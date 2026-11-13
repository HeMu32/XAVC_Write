"""Targeted ADRP+ADD printable data references in selected functions."""
import argparse
import json
import re
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64
from elftools.elf.elffile import ELFFile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
p = argparse.ArgumentParser()
p.add_argument("survey")
p.add_argument("--read", nargs="*", default=[])
a = p.parse_args()
with (ROOT / "firmware/m4-v602/usr/lib/appFw.so").open("rb") as stream:
    elf = ELFFile(stream)
    segs = [(s["p_vaddr"], s.data()) for s in elf.iter_segments()
            if s["p_type"] == "PT_LOAD"]
    def read(addr, n):
        return next((raw[addr - v:addr - v + n] for v, raw in segs
                     if v <= addr < v + len(raw)), b"")
    def string(addr):
        raw = read(addr, 1024).split(b"\0")[0]
        if len(raw) < 4 or not all(32 <= x < 127 or x in (9, 10, 13) for x in raw):
            return None
        return raw.decode()
    for value in a.read:
        addr, n = (int(x, 0) for x in value.split(":"))
        print(hex(addr), read(addr, n).hex(" "), repr(string(addr)))
    data = json.loads((HERE / a.survey).read_text())
    result = {}
    for f in data["functions"]:
        start, size = int(f["start"], 16), int(f["size"], 16)
        pages = {}
        refs = []
        for ins in Cs(CS_ARCH_ARM64, 0).disasm(read(start, size), start):
            if ins.mnemonic == "adrp":
                reg, value = ins.op_str.split(", ")
                pages[reg] = (int(value[1:], 0), ins.address)
            elif ins.mnemonic == "add":
                match = re.fullmatch(r"(x\d+), (x\d+), #(0x[0-9a-f]+|\d+)", ins.op_str)
                if match and match[2] in pages:
                    base, pc = pages[match[2]]
                    if ins.address - pc <= 64:
                        addr = base + int(match[3], 0)
                        s = string(addr)
                        if s:
                            refs.append({"pc": hex(ins.address), "address": hex(addr), "string": s})
        if refs:
            result[f["start"]] = refs
    (HERE / (Path(a.survey).stem + "-strings.json")).write_text(json.dumps(result, indent=2))
    print(json.dumps(result, indent=2))
