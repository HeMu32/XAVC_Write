"""Trace recovered code to previously inventoried strings, imports, and MSVC vtables."""
import argparse
import bisect
import hashlib
import json
from pathlib import Path
import struct

import capstone
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP
import pefile

ROOT = Path(__file__).resolve().parent
CLASSES = {
    "CExportXAVCS": ".?AVCExportXAVCS@@",
    "CPDMediaProfileUpdater": ".?AVCPDMediaProfileUpdater@@",
    "CPDMediaProfile": ".?AVCPDMediaProfile@@",
    "CXdcamExMp4ClipWriter": ".?AVCXdcamExMp4ClipWriter@@",
}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("capture")
    args = ap.parse_args()
    directory = Path(args.capture).resolve()
    capture = json.loads((directory / "capture.json").read_text(encoding="utf-8"))
    path = Path(capture["analysis_pe_file"])
    data = path.read_bytes()
    pe = pefile.PE(data=data)
    base = pe.OPTIONAL_HEADER.ImageBase
    original = json.loads((ROOT / "CtsMpegPlugIn.tpi.trace.json").read_text(encoding="utf-8"))
    strings = {int(s["va"], 16): s["text"] for s in original["strings"]}
    ranges = sorted((base + e.struct.BeginAddress, base + e.struct.EndAddress)
                    for e in pe.DIRECTORY_ENTRY_EXCEPTION)
    starts = [a for a, _ in ranges]

    def owner(a):
        i = bisect.bisect_right(starts, a) - 1
        return ranges[i][0] if i >= 0 and a < ranges[i][1] else None

    imports = {}
    for key in ("DIRECTORY_ENTRY_IMPORT", "DIRECTORY_ENTRY_DELAY_IMPORT"):
        for desc in getattr(pe, key, []):
            for imp in desc.imports:
                imports[imp.address] = {
                    "dll": desc.dll.decode(), "name": imp.name.decode() if imp.name else str(imp.ordinal)
                }
    rdata = next(s for s in pe.sections if s.Name.rstrip(b"\x00") == b".rdata")
    rb = rdata.get_data()
    vtables = {}
    rtti = {}
    for name, type_name in CLASSES.items():
        type_text = [a for a, value in strings.items() if value == type_name]
        if len(type_text) != 1:
            raise RuntimeError(f"Expected one descriptor for {name}: {type_text}")
        descriptor = type_text[0] - 16
        needle = struct.pack("<I", descriptor - base)
        records = []
        pos = rb.find(needle)
        while pos >= 0:
            if pos >= 12 and pos + 12 <= len(rb):
                col_rva = rdata.VirtualAddress + pos - 12
                signature, offset, cd_offset, type_rva, hierarchy, self_rva = struct.unpack_from(
                    "<6I", rb, pos - 12)
                if signature == 1 and self_rva == col_rva:
                    pointer = struct.pack("<Q", base + col_rva)
                    p = rb.find(pointer)
                    while p >= 0:
                        vt = base + rdata.VirtualAddress + p + 8
                        entries = []
                        for n in range(64):
                            if p + 16 + n * 8 > len(rb):
                                break
                            entry = struct.unpack_from("<Q", rb, p + 8 + n * 8)[0]
                            target = next((s for s in pe.sections if
                                           base+s.VirtualAddress <= entry <
                                           base+s.VirtualAddress+s.Misc_VirtualSize), None)
                            if target is None or not target.Characteristics & 0x20000000:
                                break
                            entries.append(hex(entry))
                        if entries:
                            records.append({"col": hex(base + col_rva), "object_offset": offset,
                                            "vtable": hex(vt), "entries": entries})
                            vtables[vt] = name
                        p = rb.find(pointer, p + 1)
            pos = rb.find(needle, pos + 1)
        rtti[name] = {"type_descriptor": hex(descriptor), "vtables": records}
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    md.detail = True
    md.skipdata = True
    refs = []
    calls = []
    for section in pe.sections:
        if not section.Characteristics & 0x20000000:
            continue
        for ins in md.disasm(section.get_data(), base + section.VirtualAddress):
            if ins.id == 0:
                continue
            f = owner(ins.address)
            for operand in ins.operands:
                target = None
                if operand.type == X86_OP_MEM and operand.mem.base == X86_REG_RIP:
                    target = ins.address + ins.size + operand.mem.disp
                elif operand.type == X86_OP_IMM:
                    target = operand.imm
                if target is None:
                    continue
                kind = None
                if target in strings:
                    kind, name = "known_string", strings[target]
                elif target in vtables:
                    kind, name = "vtable", vtables[target]
                elif target in imports:
                    kind, name = "import", imports[target]["name"]
                if kind:
                    refs.append({
                        "from": hex(ins.address), "function": hex(f) if f else None,
                        "target": hex(target), "kind": kind, "name": name,
                        "instruction": ins.mnemonic + " " + ins.op_str,
                    })
                if ins.mnemonic in ("call", "jmp"):
                    calls.append({
                        "from": hex(ins.address), "function": hex(f) if f else None,
                        "target": hex(target), "mnemonic": ins.mnemonic,
                        "import": imports.get(target),
                    })
    result = {
        "source_pe": str(path), "source_sha256": hashlib.sha256(data).hexdigest(),
        "image_base": hex(base), "actual_base": capture["actual_base"],
        "address_rule": "All graph VAs use normalized preferred base; live VA = actual_base + RVA",
        "function_ranges": [[hex(a), hex(b)] for a, b in ranges],
        "references": refs, "calls": calls,
        "note": "Static relationships in code read from a live process, not an executed export trace.",
    }
    (directory / "loaded-callgraph.json").write_text(json.dumps(result, indent=2), encoding="utf-8")
    (directory / "loaded-rtti.json").write_text(json.dumps(rtti, indent=2), encoding="utf-8")
    print("Saved", len(refs), "targeted references and", len(calls), "direct calls/branches")
    print(json.dumps(rtti, indent=2))
    for ref in refs:
        if ref["kind"] == "vtable" or (
            ref["kind"] == "known_string" and
            any(k in ref["name"] for k in ("M4ROOT", "MEDIAPRO", "C%04d.MP4", "exXAVCS.cpp"))
        ):
            print(ref["function"], ref["from"], ref["kind"], ref["name"])


if __name__ == "__main__":
    main()
