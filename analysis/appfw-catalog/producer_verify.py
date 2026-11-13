"""Original appFw PartialUpdate argument routing, with explicitly mocked DB services."""
import json
import struct
from pathlib import Path

from elftools.elf.elffile import ELFFile
from unicorn import Uc, UC_ARCH_ARM64, UC_MODE_ARM, UC_HOOK_CODE
from unicorn.arm64_const import (
    UC_ARM64_REG_PC, UC_ARM64_REG_SP, UC_ARM64_REG_X0, UC_ARM64_REG_X1,
    UC_ARM64_REG_X2, UC_ARM64_REG_X3, UC_ARM64_REG_X4, UC_ARM64_REG_X5,
    UC_ARM64_REG_X30,
)

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
with (ROOT / "firmware/m4-v602/usr/lib/appFw.so").open("rb") as stream:
    elf = ELFFile(stream)
    sections = [(s["sh_addr"], s.data()) for s in elf.iter_sections()
                if s.name in (".text", ".rodata")]


def raw(addr, n):
    return next(data[addr - base:addr - base + n]
                for base, data in sections if base <= addr < base + len(data))


def u32(uc, addr):
    return struct.unpack("<I", uc.mem_read(addr, 4))[0]


def machine():
    uc = Uc(UC_ARCH_ARM64, UC_MODE_ARM)
    for base, size in [(0x3604000, 0xa000), (0x4c1d000, 0x1000)]:
        uc.mem_map(base, size)
        uc.mem_write(base, raw(base, size))
    uc.mem_map(0x10000000, 0x4000)
    uc.mem_map(0x20000000, 0x10000)
    uc.reg_write(UC_ARM64_REG_SP, 0x2000f000)
    uc.reg_write(UC_ARM64_REG_X30, 0x10003000)
    uc.reg_write(UC_ARM64_REG_X0, 0x10000000)
    uc.reg_write(UC_ARM64_REG_X1, 0x10001000)
    return uc


def run(start, mask, quality, record_type, property_value):
    uc = machine()
    uc.mem_write(0x10000000, struct.pack("<IIIH", 1, 0x41000001, mask, quality))
    calls = []
    def hook(uc, pc, size, _):
        word = u32(uc, pc)
        kind = word & 0xfc000000
        if kind not in (0x94000000, 0x14000000):
            return
        imm = word & 0x3ffffff
        if imm & 0x2000000:
            imm -= 0x4000000
        target = pc + imm * 4
        if target == 0x1717b90:
            regs = (UC_ARM64_REG_X0, UC_ARM64_REG_X1, UC_ARM64_REG_X2,
                    UC_ARM64_REG_X3, UC_ARM64_REG_X4, UC_ARM64_REG_X5)
            values = [uc.reg_read(r) & 0xffffffff for r in regs]
            calls.append({"pc": hex(pc), "column": values[2], "args": values})
            assert values[2] not in (99, 100, 0x68), values
        elif kind == 0x14000000 or 0x3604000 <= target < 0x360e000:
            return
        elif target == 0x1716bf0:
            ptr = uc.reg_read(UC_ARM64_REG_X2)
            uc.mem_write(ptr, struct.pack("<I", record_type))
        uc.reg_write(UC_ARM64_REG_X0, property_value if target == 0x2ee59b8 else 0)
        uc.reg_write(UC_ARM64_REG_PC,
                     pc + 4 if kind == 0x94000000 else uc.reg_read(UC_ARM64_REG_X30))
    uc.hook_add(UC_HOOK_CODE, hook)
    uc.emu_start(start, 0x10003000, count=5000)
    assert uc.reg_read(UC_ARM64_REG_PC) == 0x10003000
    return calls


result = {}
masks = [0, 1, 2, 4, 8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x800, 0x1000, 0xffffffff]
cases = 0
for entry in (0x360cfcc, 0x360d08c, 0x360d228, 0x360d2f8):
    calls = [call for mask in masks for q in (0, 1, 2, 3, 4, 5, 6, 7, 8, 0xffff)
             for call in run(entry, mask, q, 1, 0)]
    cases += len(masks) * 10
    result[hex(entry)] = {"columns": sorted({c["column"] for c in calls}),
                          "sites": sorted({c["pc"] for c in calls})}
for entry in (0x360d104, 0x360d3c0, 0x360d598):
    calls = [call for content in (1, 4) for prop in (0, 1)
             for call in run(entry, 1, 0, content, prop)]
    cases += 4
    result[hex(entry)] = {"columns": sorted({c["column"] for c in calls}),
                          "sites": sorted({c["pc"] for c in calls})}
observed = {pc for r in result.values() for pc in r["sites"]}
survey = json.loads((HERE / "producer-survey.json").read_text())
expected = {c["pc"] for c in survey["direct_plt_calls"]}
assert observed == expected, {"missing": list(expected - observed), "extra": list(observed - expected)}
uc = machine()
uc.mem_write(0x10000000, b"\xff" * 0x700)
uc.emu_start(0x3609328, 0x10003000, count=1000)
assert u32(uc, 0x1000061c) == 0
output = {
    "scope": "Original appFw code; Select, property getters, and PartialUpdate side effects mocked.",
    "card_access": False, "case_count": cases, "all_direct_sites": len(observed),
    "entry_results": result, "clear_recordInfo_61c": u32(uc, 0x1000061c),
    "does_not_prove": "No real database writes or camera visibility were tested.",
}
(HERE / "producer-verification.json").write_text(json.dumps(output, indent=2))
print("passed", cases, "routing cases;", len(observed), "of", len(expected),
      "direct sites covered; recordInfo+0x61c clears to zero")
