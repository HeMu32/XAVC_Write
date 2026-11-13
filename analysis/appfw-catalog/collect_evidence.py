"""Small original-instruction excerpts and linkage, never a broad binary export."""
import hashlib
import json
import struct
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64
from elftools.elf.elffile import ELFFile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]


def collect(relative, ranges):
    path = ROOT / relative
    with path.open("rb") as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name(".dynsym")
        names = {s["st_value"]: s.name for s in symbols.iter_symbols() if s["st_value"]}
        plt, rela = elf.get_section_by_name(".plt"), elf.get_section_by_name(".rela.plt")
        for i, r in enumerate(rela.iter_relocations()):
            names[plt["sh_addr"] + 32 + i * 16] = symbols.get_symbol(r["r_info_sym"]).name
        excerpts = []
        for address, size, purpose in ranges:
            section = next(s for s in elf.iter_sections()
                           if s["sh_addr"] <= address < s["sh_addr"] + s["sh_size"])
            raw = section.data()[address - section["sh_addr"]:address - section["sh_addr"] + size]
            instructions = []
            for ins in Cs(CS_ARCH_ARM64, 0).disasm(raw, address):
                item = {"pc": hex(ins.address), "bytes": ins.bytes.hex(),
                        "mnemonic": ins.mnemonic, "operands": ins.op_str}
                if ins.mnemonic in ("bl", "b") and ins.op_str.startswith("#"):
                    item["symbol"] = names.get(int(ins.op_str[1:], 0))
                instructions.append(item)
            excerpts.append({"address": hex(address), "purpose": purpose,
                             "instructions": instructions})
        return {"path": str(path), "sha256": hashlib.sha256(path.read_bytes()).hexdigest(),
                "size": path.stat().st_size, "mtime_ns": path.stat().st_mtime_ns,
                "excerpts": excerpts}


app = collect("firmware/m4-v602/usr/lib/appFw.so", [
    (0x3594a94, 0x24, "Persistent representative-bit gate condition"),
    (0x35952d8, 0x6c, "Main root request construction"),
    (0x35953cc, 0x78, "Alternate non-representative root construction"),
    (0x3595464, 0x94, "Conditional extra root refinement"),
    (0x359561c, 0xb0, "Mode 0x16 zero compare vs unrelated tail byte"),
    (0x35956cc, 0x54, "Complex filter enable and five actual caller arguments"),
    (0x3596604, 0x44, "Run entry, enabled flag +0x90, actual call despite decompiler warning"),
    (0x35a924c, 0x40, "Root tracing wrapper"),
    (0x35a988c, 0x40, "GeneralPlayback tracing wrapper"),
    (0x35a964c, 0x40, "Refine tracing wrapper"),
    (0x3611020, 0xc8, "Main root producer and exact argument registers"),
    (0x36110e8, 0xcc, "Non-representative root producer"),
    (0x3611774, 0x108, "GeneralPlayback root producer"),
    (0x3603908, 0x14, "Boolean equality callback"),
    (0x3604370, 0x24, "Destination handle 0x39 is per-operation scratch sentinel"),
    (0x361615c, 0x60, "Complex predicate calls uint equivalence on content ID"),
    (0x3616fb4, 0xc, "Actual std::function invoke adapter"),
    (0x3622f50, 0x40, "Refine operation 0x16 constructs bool equality on COL 0x68"),
    (0x36200f0, 0x18, "Shared Refine<bool> import call"),
])
dependency = collect("firmware/m4-v602/usr/lib/libmpr.so", [
    (0x28ab6c, 0x24, "Internal content type 1 -> public 1; 2/3 -> public 4"),
    (0x28b3f4, 0x78, "COL 0x68 runtime on-memory bit1 reader"),
    (0x2a177c, 0xb8, "EquivalenceFunc<uint> gets column from this+4, NOT this+0"),
    (0x2a8760, 0x58c, "Root-set bitmap/type/persistent/runtime predicates and sort cases"),
])
with (ROOT / "firmware/m4-v602/usr/lib/appFw.so").open("rb") as stream:
    elf = ELFFile(stream)
    text = elf.get_section_by_name(".text")
    rodata = elf.get_section_by_name(".rodata")
    def ro(addr, n):
        return rodata.data()[addr - rodata["sh_addr"]:addr - rodata["sh_addr"] + n]
    switches = []
    for table, base, width, count, purpose in [
        (0x4c1cc00, 0x36116a8, 1, 5, "General root switch"),
        (0x4c1cc08, 0x36117b0, 1, 5, "GeneralPlayback switch"),
        (0x4c1cfc8, 0x361f7a4, 2, 36, "Refine operation switch"),
    ]:
        raw = ro(table, width * count)
        values = struct.unpack("<" + ("b" if width == 1 else "h") * count, raw)
        switches.append({"purpose": purpose, "table": hex(table), "base": hex(base),
                         "bytes": raw.hex(), "targets": [hex(base + 4 * v) for v in values]})
    app["switch_tables"] = switches
    app["main_root_type_lookup"] = {"address": "0x4c1d378", "values": list(ro(0x4c1d378, 5))}
    got = {0x59f6128, 0x59f62f0}
    app["boolean_callback_relocations"] = [
        {"got": hex(o), "target": hex(addend), "reloc_type": info & 0xffffffff}
        for o, info, addend in struct.iter_unpack("<QQq", elf.get_section_by_name(".rela.dyn").data())
        if o in got
    ]

(HERE / "reviewed-evidence.json").write_text(json.dumps({
    "card_access": False, "addresses": "ELF VMA; independent Ghidra adds 0x100000",
    "appFw": app, "dependency": dependency,
}, indent=2))
print("Wrote reviewed-evidence.json")
