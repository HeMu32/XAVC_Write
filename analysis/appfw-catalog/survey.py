"""Bounded offline appFw evidence; no removable-media operations."""
import argparse
import bisect
import hashlib
import json
import re
import struct
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_LITTLE_ENDIAN
from elftools.elf.elffile import ELFFile
from elftools.dwarf.callframe import FDE

ROOT = Path(__file__).resolve().parents[2]
OUT = Path(__file__).resolve().parent
SOURCE = ROOT / "firmware/m4-v602/usr/lib/appFw.so"


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--targets", nargs="*", default=[])
    parser.add_argument("--callers", action="store_true")
    parser.add_argument("--tag", default="initial")
    parser.add_argument("--max-size", type=lambda s: int(s, 0), default=0x2000)
    parser.add_argument("--exact", nargs="*", default=[])
    args = parser.parse_args()
    with SOURCE.open("rb") as stream:
        elf = ELFFile(stream)
        entries = elf.get_dwarf_info().EH_CFI_entries()
        ranges = sorted((e["initial_location"], e["address_range"])
                        for e in entries if isinstance(e, FDE))
        fde_count = len(ranges)
        text = elf.get_section_by_name(".text")
        text_raw = text.data()
        all_calls = []
        call_targets = set()
        for i, (word,) in enumerate(struct.iter_unpack("<I", text_raw[:len(text_raw) & ~3])):
            kind = word & 0xfc000000
            if kind not in (0x94000000, 0x14000000):
                continue
            pc = text["sh_addr"] + i * 4
            imm = word & 0x3ffffff
            if imm & 0x2000000:
                imm -= 0x4000000
            dest = pc + 4 * imm
            all_calls.append((pc, dest, "bl" if kind == 0x94000000 else "b"))
            if kind == 0x94000000:
                call_targets.add(dest)
        relocated_targets = {}
        reladyn = elf.get_section_by_name(".rela.dyn")
        for offset, info, addend in struct.iter_unpack("<QQq", reladyn.data()):
            if info & 0xffffffff == 1027 and text["sh_addr"] <= addend < text["sh_addr"] + len(text_raw):
                relocated_targets.setdefault(addend, []).append(offset)
                call_targets.add(addend)
        call_targets = sorted(call_targets)
        dis = Cs(CS_ARCH_ARM64, CS_MODE_LITTLE_ENDIAN)
        # Stack-frame candidates only; selected boundaries are reviewed against branches.
        prologues = []
        for i, (word,) in enumerate(struct.iter_unpack("<I", text_raw[:len(text_raw) & ~3])):
            if word & 0xffc07fff == 0xa9807bfd:
                start = text["sh_addr"] + i * 4
                j = bisect.bisect_right(call_targets, start) - 1
                target = call_targets[j] if j >= 0 else 0
                if 0 <= start - target <= 0x40:
                    between = struct.iter_unpack("<I", text_raw[target - text["sh_addr"]:i * 4])
                    if not any(w == 0xd65f03c0 or w & 0xfc000000 == 0x14000000 for (w,) in between):
                        start = target
                else:
                    prev = list(dis.disasm(text_raw[i * 4 - 4:i * 4], start - 4))
                    if prev and prev[0].mnemonic == "sub" and prev[0].op_str.startswith("sp, sp,"):
                        start -= 4
                prologues.append(start)
        prologues = sorted(set(prologues))
        ranges += [(s, e - s) for s, e in zip(prologues, prologues[1:])
                   if not any(a <= s < a + n for a, n in ranges)]
        ranges.sort()
        starts = [p[0] for p in ranges]
        def containing(addr):
            i = bisect.bisect_right(starts, addr) - 1
            if i >= 0 and addr < sum(ranges[i]):
                return ranges[i]
            return None
        symbols = elf.get_section_by_name(".dynsym")
        names = {s["st_value"]: s.name for s in symbols.iter_symbols() if s["st_value"]}
        plt = elf.get_section_by_name(".plt")
        reloc = elf.get_section_by_name(".rela.plt")
        for i, r in enumerate(reloc.iter_relocations()):
            names[plt["sh_addr"] + 32 + i * 16] = symbols.get_symbol(r["r_info_sym"]).name + "@plt"
        source = json.loads((ROOT / "analysis/mpr-catalog-linkage-0021.json").read_text())
        calls = [c for c in source["modules"][0]["callsites"] if "GetRootSet" in c["symbol"]]
        selected = set()
        for addr in ([int(t, 0) for t in args.targets] if args.targets
                     else [int(c["vma"], 16) for c in calls]):
            r = containing(addr)
            if r:
                selected.add(r)
        target_starts = {p[0] for p in selected}
        refs = [{"pc": hex(pc), "target": hex(dest), "kind": kind,
                 "caller": [hex(x) for x in containing(pc)] if containing(pc) else None}
                for pc, dest, kind in all_calls if dest in target_starts]
        if args.callers:
            selected.update(containing(int(c["pc"], 16)) for c in refs if c["caller"])
        omitted = [r for r in selected if r[1] > args.max_size]
        selected = {r for r in selected if r[1] <= args.max_size}
        for value in args.exact:
            a, n = (int(x, 0) for x in value.split(":"))
            selected = {r for r in selected if not (r[0] <= a < sum(r))}
            selected.add((a, n))
        dis = Cs(CS_ARCH_ARM64, CS_MODE_LITTLE_ENDIAN)
        funcs = []
        for start, size in sorted(selected):
            sec = next(s for s in elf.iter_sections()
                       if s["sh_addr"] <= start < s["sh_addr"] + s["sh_size"])
            raw = sec.data()[start - sec["sh_addr"]:start - sec["sh_addr"] + size]
            lines = []
            for ins in dis.disasm(raw, start):
                suffix = ""
                if ins.mnemonic in ("b", "bl") and ins.op_str.startswith("#"):
                    dest = int(ins.op_str[1:], 0)
                    if dest in names:
                        suffix = " ; " + names[dest]
                lines.append(f"{ins.address:08x}: {ins.bytes.hex()} {ins.mnemonic} {ins.op_str}{suffix}")
            (OUT / f"{start:08x}.asm").write_text("\n".join(lines) + "\n")
            funcs.append({"start": hex(start), "size": hex(size), "name": names.get(start)})
        dyn = elf.get_section_by_name(".dynamic")
        result = {
            "source": str(SOURCE), "sha256": hashlib.sha256(SOURCE.read_bytes()).hexdigest(),
            "size": SOURCE.stat().st_size, "mtime_ns": SOURCE.stat().st_mtime_ns,
            "card_access": False, "snapshot": "No card snapshot: explicitly prohibited F: access.",
            "machine": elf["e_machine"], "type": elf["e_type"], "entry": hex(elf["e_entry"]),
            "fde_count": fde_count, "functions": funcs, "incoming_direct_branches": refs,
            "omitted_over_size_bound": [[hex(a), hex(n)] for a, n in omitted],
            "selected_pointer_relocations": {hex(a): [hex(v) for v in relocated_targets.get(a, [])]
                                               for a, n in selected if a in relocated_targets},
            "sections": [{"name": s.name, "vma": hex(s["sh_addr"]), "size": hex(s["sh_size"])}
                         for s in elf.iter_sections()],
            "segments": [{k: (hex(v) if isinstance(v, int) else v) for k, v in s.header.items()}
                         for s in elf.iter_segments()],
            "dynamic_flags": [str(t) for t in dyn.iter_tags()
                              if t.entry.d_tag in ("DT_FLAGS", "DT_FLAGS_1", "DT_BIND_NOW")],
            "instrumentation_imports": [s.name for s in symbols.iter_symbols()
                                        if re.search(r"__stack_chk|__.*_chk$", s.name)],
            "comment": elf.get_section_by_name(".comment").data().decode(errors="replace"),
            "related_imports": {hex(k): v for k, v in names.items()
                                if re.search("sidb|RootSet|EntryInfoList|mpr", v)},
        }
        (OUT / (args.tag + ".json")).write_text(json.dumps(result, indent=2))
        (OUT / "fde-ranges.json").write_text(json.dumps(ranges))
        print(json.dumps({"functions": funcs, "incoming": refs}, indent=2))


if __name__ == "__main__":
    main()
