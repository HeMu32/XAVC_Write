"""Bounded appFw whole-flag producer survey, offline and producer-prefixed outputs."""
import argparse
import bisect
import hashlib
import json
import re
import struct
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64
from elftools.elf.elffile import ELFFile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
SOURCE = ROOT / "firmware/m4-v602/usr/lib/appFw.so"


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--targets", nargs="*", default=[])
    p.add_argument("--exact", nargs="*", default=[])
    p.add_argument("--tag", default="producer-survey")
    args = p.parse_args()
    assert args.tag.startswith("producer")
    ranges = json.loads((HERE / "fde-ranges.json").read_text())
    starts = [r[0] for r in ranges]
    def owner(pc):
        i = bisect.bisect_right(starts, pc) - 1
        return ranges[i] if i >= 0 and pc < sum(ranges[i]) else None
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        text = elf.get_section_by_name(".text")
        raw = text.data()
        symbols = elf.get_section_by_name(".dynsym")
        sidb_symbols = [{"name": s.name, "value": hex(s["st_value"]),
                         "size": s["st_size"], "section": s["st_shndx"]}
                        for s in symbols.iter_symbols() if "sidb" in s.name]
        plt = elf.get_section_by_name(".plt")
        names = {}
        for i, r in enumerate(elf.get_section_by_name(".rela.plt").iter_relocations()):
            names[plt["sh_addr"] + 32 + 16 * i] = symbols.get_symbol(r["r_info_sym"]).name
        dis = Cs(CS_ARCH_ARM64, 0)
        calls, accesses, branches = [], [], []
        instruction_count = len(raw) // 4
        for i, (word,) in enumerate(struct.iter_unpack("<I", raw[:instruction_count * 4])):
            pc = text["sh_addr"] + i * 4
            kind = word & 0xfc000000
            if kind in (0x94000000, 0x14000000):
                imm = word & 0x3ffffff
                if imm & 0x2000000:
                    imm -= 0x4000000
                target = pc + 4 * imm
                branches.append((pc, target, "bl" if kind == 0x94000000 else "b"))
                name = names.get(target, "")
                if re.search(r"sidb.*(?:Update|GetValue)", name):
                    context = list(dis.disasm(raw[max(0, i * 4 - 64):i * 4 + 12],
                                              max(text["sh_addr"], pc - 64)))
                    calls.append({"pc": hex(pc), "target": hex(target), "kind": branches[-1][2],
                                  "symbol": name, "owner_candidate": owner(pc),
                                  "context": [{"pc": hex(x.address), "mnemonic": x.mnemonic,
                                               "operands": x.op_str, "bytes": x.bytes.hex()}
                                              for x in context]})
            # Integer unsigned-immediate load/store; excludes SIMD and register offsets.
            if word & 0x3f000000 == 0x39000000:
                scale = (word >> 30) & 3
                offset = ((word >> 10) & 0xfff) << scale
                if offset <= 0x61c < offset + (1 << scale):
                    instruction = next(dis.disasm(struct.pack("<I", word), pc))
                    accesses.append({"pc": hex(pc), "mnemonic": instruction.mnemonic,
                                     "operands": instruction.op_str, "bytes": instruction.bytes.hex(),
                                     "offset": hex(offset), "width": 1 << scale,
                                     "owner_candidate": owner(pc)})
        related_text = []
        image = SOURCE.read_bytes()
        for pattern in (b"_ZN4sidb6Update", b"_ZN4sidb8GetValue", b"whole_flag",
                        b"wholeFlag", b"wholeflag", b"onMemoryColumn"):
            positions = []
            begin = 0
            while True:
                offset = image.find(pattern, begin)
                if offset < 0:
                    break
                positions.append(hex(offset))
                begin = offset + 1
            related_text.append({"pattern": pattern.decode(), "file_offsets": positions})
        selected = set()
        if args.targets:
            for a in args.targets:
                found = owner(int(a, 0))
                if found:
                    selected.add(tuple(found))
        else:
            for c in calls:
                if c["owner_candidate"]:
                    selected.add(tuple(c["owner_candidate"]))
            for c in accesses:
                if (c["mnemonic"] == "strb" and c["offset"] == "0x61c"
                        and c["owner_candidate"] and c["owner_candidate"][1] <= 0x400):
                    selected.add(tuple(c["owner_candidate"]))
            selected.add((0x3609328, 0x1c0))
        for v in args.exact:
            a, size = (int(x, 0) for x in v.split(":"))
            selected = {r for r in selected if not r[0] <= a < sum(r)}
            selected.add((a, size))
        functions = []
        string_refs = {}
        sections = [(s["sh_addr"], s.data()) for s in elf.iter_sections()
                    if s.name in (".text", ".rodata")]
        def read(addr, count):
            return next((data[addr - base:addr - base + count]
                         for base, data in sections if base <= addr < base + len(data)), b"")
        for a, size in sorted(selected):
            if size > 0x5000:
                continue
            instructions = list(dis.disasm(read(a, size), a))
            pages, refs, lines = {}, [], []
            for ins in instructions:
                suffix = ""
                if ins.mnemonic in ("bl", "b") and ins.op_str.startswith("#"):
                    suffix = " ; " + names.get(int(ins.op_str[1:], 0), "")
                lines.append(f"{ins.address:08x}: {ins.bytes.hex()} {ins.mnemonic} {ins.op_str}{suffix}")
                if ins.mnemonic == "adrp":
                    reg, value = ins.op_str.split(", ")
                    pages[reg] = (int(value[1:], 0), ins.address)
                elif ins.mnemonic == "add":
                    m = re.fullmatch(r"(x\d+), (x\d+), #(0x[0-9a-f]+|\d+)", ins.op_str)
                    if m and m[2] in pages:
                        base, pc = pages[m[2]]
                        if ins.address - pc <= 64:
                            addr = base + int(m[3], 0)
                            value = read(addr, 1024).split(b"\0")[0]
                            if len(value) >= 4 and all(32 <= x < 127 or x in (9, 10, 13) for x in value):
                                refs.append({"pc": hex(ins.address), "address": hex(addr),
                                             "string": value.decode()})
            (HERE / f"producer-{a:08x}.asm").write_text("\n".join(lines) + "\n")
            functions.append({"start": hex(a), "size": hex(size)})
            if refs:
                string_refs[hex(a)] = refs
        selected_starts = {a for a, n in selected}
        incoming = [{"pc": hex(pc), "target": hex(target), "kind": kind, "owner_candidate": owner(pc)}
                    for pc, target, kind in branches if target in selected_starts]
        data = {
            "source": str(SOURCE), "sha256": hashlib.sha256(image).hexdigest(),
            "size": len(image), "mtime_ns": SOURCE.stat().st_mtime_ns, "card_access": False,
            "machine": elf["e_machine"], "text_vma": hex(text["sh_addr"]), "text_size": len(raw),
            "aligned_words_scanned": instruction_count,
            "sidb_symbols": sidb_symbols, "direct_plt_calls": calls,
            "record61c_candidate_accesses": accesses, "string_patterns": related_text,
            "functions": functions, "string_refs": string_refs, "incoming": incoming,
        }
        (HERE / (args.tag + ".json")).write_text(json.dumps(data, indent=2))
        print(json.dumps({"call_count": len(calls), "offset_candidate_count": len(accesses),
                          "functions": functions, "strings": string_refs}, indent=2))


if __name__ == "__main__":
    main()
