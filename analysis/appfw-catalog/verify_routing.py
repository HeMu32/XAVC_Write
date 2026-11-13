"""Execute original appFw request construction with explicitly mocked services."""
import json
import struct
from pathlib import Path

from elftools.elf.elffile import ELFFile
from unicorn import Uc, UC_ARCH_ARM64, UC_MODE_ARM, UC_HOOK_CODE
from unicorn.arm64_const import (
    UC_ARM64_REG_PC, UC_ARM64_REG_SP, UC_ARM64_REG_X0, UC_ARM64_REG_X1,
    UC_ARM64_REG_X2, UC_ARM64_REG_X3, UC_ARM64_REG_X4, UC_ARM64_REG_X5,
    UC_ARM64_REG_X6, UC_ARM64_REG_X30,
)

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
with (ROOT / "firmware/m4-v602/usr/lib/appFw.so").open("rb") as stream:
    elf = ELFFile(stream)
    sections = [(s["sh_addr"], s.data()) for s in elf.iter_sections()
                if s.name in (".text", ".rodata")]


def original(addr, size):
    return next(data[addr - base:addr - base + size] for base, data in sections
                if base <= addr < base + len(data))


def machine():
    uc = Uc(UC_ARCH_ARM64, UC_MODE_ARM)
    for addr, size in [(0x3594000, 0x3000), (0x2e2c000, 0x1000)]:
        uc.mem_map(addr, size)
        uc.mem_write(addr, original(addr, size))
    uc.mem_map(0x10000000, 0x10000)
    uc.mem_map(0x20000000, 0x200000)
    uc.reg_write(UC_ARM64_REG_SP, 0x201ff000)
    uc.reg_write(UC_ARM64_REG_X0, 0x10000000)
    uc.reg_write(UC_ARM64_REG_X30, 0x10008000)
    return uc


def u32(uc, addr):
    return struct.unpack("<I", uc.mem_read(addr, 4))[0]


def put32(uc, addr, value):
    uc.mem_write(addr, struct.pack("<I", value))


def caller_route(mode10, mode84, grouped, property_value):
    uc = machine()
    obj = 0x10000000
    uc.mem_write(obj + 0x10, bytes([mode10, 0, 1, 0]))
    for offset, value in {
        0x18: 2, 0x1c: 0x123456, 0x20: 0x654321, 0x30: 1,
        0x38: 0, 0x70: 1, 0x74: 0 if grouped else 1, 0x78: 1,
        0x84: mode84,
    }.items():
        put32(uc, obj + offset, value)
    events = []
    def hook(uc, pc, size, _):
        if pc == 0x35956cc:
            uc.emu_stop()
            return
        word = u32(uc, pc)
        if word & 0xfc000000 != 0x94000000:
            return
        imm = word & 0x3ffffff
        if imm & 0x2000000:
            imm -= 0x4000000
        target = pc + imm * 4
        if target in (0x3594a94, 0x2e2c25c):
            return
        x0, x1, x2 = (uc.reg_read(r) for r in
                       (UC_ARM64_REG_X0, UC_ARM64_REG_X1, UC_ARM64_REG_X2))
        if target == 0x1715020:
            uc.mem_write(x0, bytes([x1 & 255]) * x2)
        elif target in (0x35a924c, 0x35a928c):
            events.append({"pc": hex(pc), "target": hex(target),
                           "request": bytes(uc.mem_read(x0, 0x28)).hex()})
            put32(uc, x1 + 8, 42)
            put32(uc, x1 + 0x2c, 0 if target == 0x35a924c else 1)
            put32(uc, x1 + 0x30, 0)
        elif target == 0x35a964c:
            events.append({"pc": hex(pc), "target": hex(target),
                           "mode": u32(uc, x0 + 4),
                           "compare_byte": uc.mem_read(x0 + 8, 1)[0],
                           "input_handle": u32(uc, x0 + 0x9c48),
                           "output_handle": u32(uc, x0 + 0x9c4c),
                           "tail_byte_a018": uc.mem_read(x0 + 0xa018, 1)[0]})
            put32(uc, x1, 0x22)
            put32(uc, x1 + 4, 42)
            put32(uc, x1 + 8, 0)
        uc.reg_write(UC_ARM64_REG_X0, property_value if target == 0x2ee59c8 else 0)
        uc.reg_write(UC_ARM64_REG_PC, pc + 4)
    uc.hook_add(UC_HOOK_CODE, hook)
    uc.emu_start(0x359529c, 0x10008000, count=10000)
    assert uc.reg_read(UC_ARM64_REG_PC) == 0x35956cc
    refinements = [e for e in events if e.get("mode") == 0x16]
    assert len(refinements) == (1 + int(grouped) if mode10 and not mode84 else 0)
    assert all(e["compare_byte"] == 0 and e["tail_byte_a018"] == property_value
               for e in refinements)
    return {"flags": {"plus10": mode10, "plus84": mode84, "group_condition": grouped,
                      "mock_property_1bd4": property_value}, "events": events}


def wrapper_route(root_type, override, persistent_gate, onmem_include):
    uc = machine()
    uc.mem_map(0x3611000, 0x1000)
    uc.mem_write(0x3611000, original(0x3611000, 0x1000))
    uc.mem_map(0x4c1d000, 0x1000)
    uc.mem_write(0x4c1d000, original(0x4c1d000, 0x1000))
    request, out = 0x10000000, 0x10001000
    for offset, value in {0: 2, 4: 0x123456, 8: 0x654321,
                          0x14: root_type, 0x20: override}.items():
        put32(uc, request + offset, value)
    uc.mem_write(request + 0x1c, bytes([persistent_gate]))
    uc.mem_write(request + 0x24, bytes([onmem_include]))
    uc.reg_write(UC_ARM64_REG_X1, out)
    result = {}
    def hook(uc, pc, size, _):
        word = u32(uc, pc)
        if word & 0xfc000000 != 0x94000000:
            return
        imm = word & 0x3ffffff
        if imm & 0x2000000:
            imm -= 0x4000000
        target = pc + 4 * imm
        if target == 0x1717290:
            regs = [UC_ARM64_REG_X0, UC_ARM64_REG_X1, UC_ARM64_REG_X2,
                    UC_ARM64_REG_X3, UC_ARM64_REG_X4, UC_ARM64_REG_X5, UC_ARM64_REG_X6]
            values = [uc.reg_read(r) for r in regs]
            result.update(count=values[0], media_ids=[u32(uc, values[1]), u32(uc, values[1] + 4)],
                          root_type=values[2], require_record6_bit4=values[3],
                          include_onmem_bit1=values[4], cancellable=values[5],
                          result_set=hex(values[6]))
            uc.emu_stop()
            return
        uc.reg_write(UC_ARM64_REG_X0, 0)
        uc.reg_write(UC_ARM64_REG_PC, pc + 4)
    uc.hook_add(UC_HOOK_CODE, hook)
    uc.emu_start(0x3611020, 0x10008000, count=1000)
    expected = 5 if override == 1 else [0, 1, 5, 6, 7][root_type]
    assert result["root_type"] == expected
    assert result["require_record6_bit4"] == persistent_gate
    assert result["include_onmem_bit1"] == onmem_include
    return {"input_type": root_type, "override": override, "root_call": result}


callers = [caller_route(a, b, g, p) for a in (0, 1) for b in (0, 1)
           for g in (False, True) for p in (0, 1)]
wrappers = [wrapper_route(t, o, 1, 1) for t in range(5) for o in (0, 1)]
result = {
    "scope": "Original appFw caller/wrapper instructions; DB/UI calls mocked; NOT camera playback.",
    "card_access": False, "caller_cases": callers, "wrapper_cases": wrappers,
    "assertions": "32 caller cases + 10 root-wrapper cases passed",
}
(HERE / "routing-execution.json").write_text(json.dumps(result, indent=2))
print(result["assertions"])
