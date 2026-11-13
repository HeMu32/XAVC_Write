"""Verify loaded-code filesystem anchors and the local SDK XML save slot."""
import hashlib
import json
import re
import uuid
from pathlib import Path

import capstone
from capstone import x86_const as x86
import pefile

HERE = Path(__file__).resolve().parent
SOURCE = HERE.parent / "live-mpeg-47056-20261112T134903Z/CtsMpegPlugIn.loaded-normalized-pe.bin"
EXPECTED = "b610fd1440b389324c0513219b1930743947d977fe1d4342f489ec95ccbb83f4"
SDK = Path("C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um/msxml.h")


def main():
    raw = SOURCE.read_bytes()
    if hashlib.sha256(raw).hexdigest() != EXPECTED:
        raise ValueError("Wrong analysis image")
    pe = pefile.PE(data=raw)
    base = pe.OPTIONAL_HEADER.ImageBase
    imports = {symbol.address: symbol.name.decode("ascii") for item in pe.DIRECTORY_ENTRY_IMPORT
               for symbol in item.imports if symbol.name}
    disassembler = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    disassembler.detail = True
    sinks = []
    for rva, size in [(0x440750, 279), (0x4A9F30, 373), (0x440310, 294)]:
        for ins in disassembler.disasm(pe.get_data(rva, size), base + rva):
            if ins.mnemonic != "call" or not ins.operands:
                continue
            operand = ins.operands[0]
            if operand.type == x86.X86_OP_MEM and operand.mem.base == x86.X86_REG_RIP:
                target = ins.address + ins.size + operand.mem.disp
                name = imports.get(target)
                if name in {"SHCreateStreamOnFileW", "DeleteFileW", "MoveFileW"}:
                    sinks.append({"function_rva": hex(rva), "call_rva": hex(ins.address - base),
                                  "import": name, "bytes": ins.bytes.hex()})
    if {row["import"] for row in sinks} != {"SHCreateStreamOnFileW", "DeleteFileW", "MoveFileW"}:
        raise ValueError("Expected original filesystem call anchors were not recovered")
    header = SDK.read_text()
    body = header.split("typedef struct IXMLDOMDocumentVtbl", 1)[1].split(
        "} IXMLDOMDocumentVtbl;", 1)[0]
    methods = re.findall(r"STDMETHODCALLTYPE\s+\*(\w+)", body)
    if methods.index("save") != 66:
        raise ValueError("Unexpected SDK XML document vtable")
    iid = str(uuid.UUID(bytes_le=pe.get_data(0x6F7268, 16)))
    if iid.lower() != "2933bf81-7b36-11d2-b20e-00c04f983e60":
        raise ValueError("Unexpected XML document IID")
    suffix = pe.get_data(0x7127A8, 10).decode("utf-16le").split("\0", 1)[0]
    if suffix != ".$$$":
        raise ValueError("Unexpected temporary filename suffix")
    save = next(disassembler.disasm(pe.get_data(0x1B9178, 15), base + 0x1B9178))
    if (save.mnemonic != "call" or save.operands[0].type != x86.X86_OP_MEM or
            save.operands[0].mem.disp != 0x210):
        raise ValueError("Original XML save call displacement changed")
    report = {
        "normalized_pe_sha256": EXPECTED, "card_access": False, "live_process_access": False,
        "scope": "Static loaded-code and SDK verification, not observed export execution",
        "decompile_functions": len(list((HERE / "decompile").glob("*.c"))),
        "original_import_call_sites": sinks, "temporary_suffix": suffix,
        "xml_document_iid_at_rva_6f7268": iid,
        "sdk_header": str(SDK), "sdk_header_sha256": hashlib.sha256(SDK.read_bytes()).hexdigest(),
        "xml_document_save_slot": 66, "xml_document_save_offset_x64": "0x210",
        "original_xml_save_call_rva": "0x1b9178", "original_xml_save_call_bytes": save.bytes.hex(),
        "reviewed_branch": [
            "RVA23896c concatenates the destination path with the .$$$ suffix",
            "RVA23897c calls RVA1b89a0 on the temporary path",
            "RVA1b89a0 calls RVA440750 with stream flags 0x1021, then RVA1b8f50",
            "RVA1b8f50 invokes XML document vtable slot 66 (save)",
            "RVA2389c7 calls RVA43c630 on the original path; local backend reaches DeleteFileW",
            "RVA238a07 calls RVA440310; local path reaches MoveFileW(temp, original)",
        ],
        "limitations": [
            "Preliminary inferred C prototypes/return types can be wrong; original assembly is authoritative.",
            "Alternate backend branches exist; local OS calls are not proven for every destination.",
            "Complete CExportXAVCS virtual-entry linkage and actual runtime options remain unverified.",
            "No verified Sony DATABASE.BIN write, full MP4/NRT/thumbnail sequence or durable flush ordering.",
            "Delete followed by MoveFileW must not be described as an atomic transaction.",
            "No card write or deletion is authorized or performed by this evidence collection.",
        ],
    }
    (HERE / "evidence.json").write_text(json.dumps(report, indent=2), encoding="utf-8")
    print("Verified", len(sinks), "filesystem sinks, XML save slot", methods.index("save"),
          "suffix", suffix)


if __name__ == "__main__":
    main()
