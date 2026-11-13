"""Find direct RIP-relative string/import xrefs and calls, using PE unwind ranges."""
import argparse
import bisect
import json
import re
from pathlib import Path

import capstone
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP
import pefile

OUT = Path(__file__).resolve().parent
EXTRA = re.compile(
    r"\.xml|\.jpg|\.bim|\.mp4|\.mxf|thmbnl|thumbnail|mediapro|m4root|"
    r"umid|database|finaliz|flush|commit|xavc|nrt|CExportXAVCS|"
    r"CPDMediaProfile|CXdcamExMp4ClipWriter|generate|sequence|clipname|"
    r"destination|filesystem",
    re.I,
)
SINK = re.compile(
    r"CreateFile|WriteFile|Flush|CloseHandle|MoveFile|ReplaceFile|"
    r"DeleteFile|CreateDirectory|SetEndOfFile|CMXF_|MP4|MPEG|"
    r"fwrite|fclose|fflush|rename|fopen|LoadLibrary|GetProcAddress",
    re.I,
)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("name")
    args = ap.parse_args()
    modules = json.loads((OUT / "survey.json").read_text(encoding="utf-8"))
    m = next(m for m in modules if Path(m["path"]).name.lower() == args.name.lower())
    path = Path(m["path"])
    data = path.read_bytes()
    pe = pefile.PE(data=data)
    base = pe.OPTIONAL_HEADER.ImageBase
    ranges = sorted((base + e.struct.BeginAddress, base + e.struct.EndAddress)
                    for e in pe.DIRECTORY_ENTRY_EXCEPTION)
    starts = [r[0] for r in ranges]

    def owner(address):
        i = bisect.bisect_right(starts, address) - 1
        return ranges[i][0] if i >= 0 and address < ranges[i][1] else None

    strings = {}
    for encoding, rx in [("ascii", rb"[\x20-\x7e]{4,}"), ("utf-16le", rb"(?:[\x20-\x7e]\x00){4,}")]:
        for match in re.finditer(rx, data):
            value = match.group().decode(encoding)
            if not EXTRA.search(value):
                continue
            try:
                va = base + pe.get_rva_from_offset(match.start())
            except pefile.PEFormatError:
                continue
            strings[va] = {"va": hex(va), "rva": hex(va - base),
                           "offset": hex(match.start()), "encoding": encoding, "text": value}
    imports = {int(i["iat_va"], 16): i for i in m["imports"]}
    interesting_imports = {a: i for a, i in imports.items() if SINK.search(i["name"])}
    xrefs = []
    calls = []
    selected = set()
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    md.detail = True
    md.skipdata = True
    for section in pe.sections:
        if not section.Characteristics & 0x20000000:
            continue
        for ins in md.disasm(section.get_data(), base + section.VirtualAddress):
            if ins.id == 0:
                continue
            f = owner(ins.address)
            for op in ins.operands:
                target = None
                if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP:
                    target = ins.address + ins.size + op.mem.disp
                elif op.type == X86_OP_IMM:
                    target = op.imm
                if target in strings or target in interesting_imports:
                    xrefs.append({
                        "from": hex(ins.address), "function": hex(f) if f else None,
                        "target": hex(target), "kind": "string" if target in strings else "import",
                        "text": strings[target]["text"] if target in strings else imports[target]["name"],
                        "instruction": ins.mnemonic + " " + ins.op_str,
                    })
                    if target in strings and f:
                        selected.add(f)
                if ins.mnemonic in {"call", "jmp"} and target is not None:
                    calls.append({
                        "from": hex(ins.address), "function": hex(f) if f else None,
                        "target": hex(target),
                        "import": imports[target]["name"] if target in imports else None,
                        "mnemonic": ins.mnemonic,
                    })
    result = {
        "module": m["relative"], "sha256": m["sha256"], "image_base": hex(base),
        "strings": list(strings.values()), "xrefs": xrefs, "calls": calls,
        "function_ranges": [[hex(a), hex(b)] for a, b in ranges],
        "limitations": "Only decoded direct immediate and RIP-relative references; indirect dispatch is not resolved.",
    }
    out = OUT / (path.name + ".trace.json")
    out.write_text(json.dumps(result, indent=2), encoding="utf-8")
    print("Saved", out.name, "strings", len(strings), "xrefs", len(xrefs), "calls", len(calls))
    for x in xrefs:
        if x["kind"] == "string" and re.search(
            r"exXAVCS|M4ROOT|MEDIAPRO|THMBNL|\.JPG|M01.XML|\.MP4|database\.bin", x["text"], re.I
        ):
            print(x["function"], x["from"], x["target"], x["text"][:180])


if __name__ == "__main__":
    main()
