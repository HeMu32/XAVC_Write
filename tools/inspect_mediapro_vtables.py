"""Purpose: resolve identified Sony MediaProfile virtual-method tables.

Usage: python tools/inspect_mediapro_vtables.py --output REPORT.json
    [--firmware LOCAL_LIBMPR.so].
Design: inspect original ELF symbols and relocation-backed pointers, preserving
    addresses/provenance for subsequent targeted function analysis.
Scope: static read-only evidence for the identified tables, not general C++
    class recovery, method execution or camera behavior verification.
"""
import argparse
import hashlib
import json
import struct
from pathlib import Path

from elftools.elf.elffile import ELFFile

from emulate_sidb_readers import EXPECTED


def inspect(path):
    if hashlib.sha256(path.read_bytes()).hexdigest() != EXPECTED:
        raise ValueError("Only the identified M4 6.02 image is supported")
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        relocations = {row["r_offset"]: row for row in
                       elf.get_section_by_name(".rela.dyn").iter_relocations()}
        symbols = elf.get_section_by_name(".dynsym")

        def resolve(address):
            relocation = relocations.get(address)
            if relocation is not None:
                if relocation["r_info_type"] == 1027:
                    return relocation["r_addend"], "R_AARCH64_RELATIVE"
                symbol = symbols.get_symbol(relocation["r_info_sym"])
                return (symbol["st_value"] + relocation["r_addend"],
                        f"symbol_relocation:{symbol.name}")
            segment = next(seg for seg in elf.iter_segments() if seg["p_type"] == "PT_LOAD" and
                           seg["p_vaddr"] <= address < seg["p_vaddr"] + seg["p_filesz"])
            offset = address - segment["p_vaddr"]
            return struct.unpack_from("<Q", segment.data(), offset)[0], "original_raw_qword"

        tables = []
        for name, got, length in [
                ("M4MediaProfile", 0x3022A0, 0x498),
                ("M4CommonMediaProfileParser", 0x302A48, 0xB0),
                ("M4CommonMediaProfileParserImpl", 0x301E40, 0xB0),
                ("M4ParserState0", 0x302300, 0xC0),
                ("M4ParserState1", 0x301710, 0xC0),
                ("M4ParserState2", 0x301C70, 0xC0)]:
            base, kind = resolve(got)
            entries = []
            for offset in range(0, length, 8):
                pointer, method = resolve(base + 0x10 + offset)
                entries.append({"virtual_offset": hex(offset), "elf_target": hex(pointer),
                                "ghidra_target": hex(pointer + 0x100000) if pointer else None,
                                "resolution": method})
            tables.append({"name_is_analyst_label": name, "got_elf_vma": hex(got),
                           "got_resolution": kind, "vtable_address_point": hex(base + 0x10),
                           "entries": entries})
    return {"firmware": str(path.resolve()), "sha256": EXPECTED, "card_access": False,
            "load_bias": 0, "tables": tables}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--firmware", default="firmware/m4-v602/usr/lib/libmpr.so")
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    path, output = Path(args.firmware).resolve(), Path(args.output).resolve()
    if path.drive.upper() == "F:" or output.drive.upper() == "F:":
        raise ValueError("Only offline files and local output are allowed")
    report = inspect(path)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2), encoding="utf-8")
    print("Resolved tables", len(report["tables"]), "output", output)


if __name__ == "__main__":
    main()
