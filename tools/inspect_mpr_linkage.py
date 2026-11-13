"""Purpose: inspect catalog-library linkage and selected direct call evidence.

Usage: python tools/inspect_mpr_linkage.py --output REPORT.json
    [--root FIRMWARE_ROOT --symbols REGEX --address HEX --callers REGEX].
Design: join ELF symbols/relocations with bounded decoding of original branch
    instructions to locate selected imports, callers and shared state.
Scope: offline static evidence. Indirect/unrecovered calls may be absent; this
    is not a complete call graph, dynamic trace or execution of firmware.
"""
import argparse
import bisect
import hashlib
import json
import re
import struct
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_LITTLE_ENDIAN
from elftools.elf.elffile import ELFFile


def survey(path, symbol_pattern, addresses, caller_pattern=None):
    with path.open("rb") as stream:
        if stream.read(4) != b"\x7fELF":
            return None
        stream.seek(0)
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".dynsym")
        if symbols is None:
            return None
        matches = [{"name": s.name, "value": hex(s["st_value"]),
                    "size": s["st_size"], "section": s["st_shndx"]}
                   for s in symbols.iter_symbols() if symbol_pattern.search(s.name)]
        functions = []
        callsites = []
        if caller_pattern is not None and elf["e_machine"] == "EM_AARCH64":
            plt = elf.get_section_by_name(".plt")
            relocation = elf.get_section_by_name(".rela.plt")
            targets = {}
            if plt and relocation:
                for index, entry in enumerate(relocation.iter_relocations()):
                    name = symbols.get_symbol(entry["r_info_sym"]).name
                    if caller_pattern.search(name):
                        targets[plt["sh_addr"] + 32 + 16 * index] = name
            if targets:
                defined = sorted((s["st_value"], s["st_size"], s.name)
                                 for s in symbols.iter_symbols()
                                 if s["st_value"] and s["st_info"]["type"] == "STT_FUNC")
                starts = [s[0] for s in defined]
                disassembler = Cs(CS_ARCH_ARM64, CS_MODE_LITTLE_ENDIAN)
                for section in elf.iter_sections():
                    if not section["sh_flags"] & 4 or section["sh_type"] == "SHT_NOBITS":
                        continue
                    raw = section.data()
                    for offset, (word,) in enumerate(struct.iter_unpack("<I", raw[:len(raw) & ~3])):
                        if word & 0x7C000000 != 0x14000000:
                            continue
                        address = section["sh_addr"] + 4 * offset
                        displacement = word & 0x3FFFFFF
                        if displacement & 0x2000000:
                            displacement -= 0x4000000
                        target = address + 4 * displacement
                        if target not in targets:
                            continue
                        index = bisect.bisect_right(starts, address) - 1
                        function = defined[index] if index >= 0 else None
                        if function and not function[0] <= address < function[0] + function[1]:
                            function = None
                        begin, end = max(0, 4 * offset - 48), min(len(raw), 4 * offset + 20)
                        context = [{"vma": hex(ins.address), "mnemonic": ins.mnemonic,
                                    "operands": ins.op_str}
                                   for ins in disassembler.disasm(raw[begin:end],
                                                                section["sh_addr"] + begin)]
                        callsites.append({"vma": hex(address), "target": hex(target),
                                          "symbol": targets[target],
                                          "branch_kind": "bl" if word & 0x80000000 else "b",
                                          "containing_symbol": function,
                                          "context": context})
        if addresses and path.name == "libmpr.so":
            names = {s["st_value"]: s.name for s in symbols.iter_symbols() if s["st_value"]}
            plt = elf.get_section_by_name(".plt")
            relocation = elf.get_section_by_name(".rela.plt")
            for index, entry in enumerate(relocation.iter_relocations()):
                names[plt["sh_addr"] + 32 + 16 * index] = (
                    symbols.get_symbol(entry["r_info_sym"]).name + "@plt")
            disassembler = Cs(CS_ARCH_ARM64, CS_MODE_LITTLE_ENDIAN)
            for address in addresses:
                symbol = next((s for s in symbols.iter_symbols() if s["st_value"] == address), None)
                if symbol is None:
                    raise ValueError(f"No sized dynamic symbol at {address:#x}")
                segment = next(s for s in elf.iter_segments()
                               if s["p_type"] == "PT_LOAD" and
                               s["p_vaddr"] <= address < s["p_vaddr"] + s["p_filesz"])
                offset = address - segment["p_vaddr"]
                raw = segment.data()[offset:offset + symbol["st_size"]]
                instructions, calls = [], []
                for ins in disassembler.disasm(raw, address):
                    row = {"vma": hex(ins.address), "mnemonic": ins.mnemonic,
                           "operands": ins.op_str, "bytes": ins.bytes.hex()}
                    instructions.append(row)
                    if ins.mnemonic in {"bl", "b"} and ins.op_str.startswith("#"):
                        target = int(ins.op_str[1:], 0)
                        if ins.mnemonic == "bl" or not address <= target < address + len(raw):
                            calls.append({**row, "target": hex(target), "symbol": names.get(target)})
                functions.append({"name": symbol.name, "vma": hex(address),
                                  "size": len(raw), "calls": calls, "instructions": instructions})
        if not matches and not functions and not callsites:
            return None
        dependencies = []
        dynamic = elf.get_section_by_name(".dynamic")
        if dynamic:
            dependencies = [tag.needed for tag in dynamic.iter_tags("DT_NEEDED")]
        return {"path": str(path.resolve()), "sha256": hashlib.sha256(path.read_bytes()).hexdigest(),
                "machine": elf["e_machine"], "dependencies": dependencies,
                "symbols": matches, "functions": functions, "callsites": callsites}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--root", default="firmware/m4-v602")
    ap.add_argument("--symbols", default="GetEntryInfoList|GetRootSet|PartialUpdate|gp_onmem")
    ap.add_argument("--address", action="append", default=[])
    ap.add_argument("--callers", help="Regex for imported PLT symbols; scan original BL and B instructions")
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    addresses = [int(value, 0) for value in args.address]
    pattern = re.compile(args.symbols)
    results, errors = [], []
    for path in Path(args.root).rglob("*"):
        if not path.is_file():
            continue
        try:
            result = survey(path, pattern, addresses,
                            re.compile(args.callers) if args.callers else None)
            if result:
                results.append(result)
        except (OSError, ValueError) as error:
            errors.append({"path": str(path), "error": str(error)})
    output = Path(args.output).resolve()
    if output.drive.upper() == "F:":
        raise ValueError("Output must remain off the card")
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps({"root": str(Path(args.root).resolve()),
                                 "symbol_pattern": args.symbols, "modules": results,
                                 "errors": errors, "card_access": False}, indent=2), encoding="utf-8")
    print("matched modules", len(results), "errors", len(errors), "output", output)
    for result in results:
        print(result["path"], "matches", len(result["symbols"]))


if __name__ == "__main__":
    main()
