"""Purpose: isolate decoder status-wrapper ordering in the original firmware.

Usage: python tools/emulate_vcd_status_flow.py --output REPORT.json
    [--firmware IDENTIFIED_IMOLA2.bin].
Design: execute original wrappers/getters around explicit guest stubs for NAL
    parsing, hardware and logging, then record status copying/reset behavior.
Scope: bounded ordering experiments, not authentic parser or hardware execution.
    Stub success does not establish codec validity or camera playback.
"""
import argparse
import hashlib
import json
import struct
from pathlib import Path

import unicorn
from unicorn import Uc, UC_ARCH_MIPS, UC_MODE_MIPS32, UC_MODE_LITTLE_ENDIAN
from unicorn import UC_HOOK_CODE, UC_HOOK_MEM_WRITE, UC_HOOK_INTR
from unicorn.mips_const import UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_A2, UC_MIPS_REG_A3
from unicorn.mips_const import UC_MIPS_REG_GP, UC_MIPS_REG_RA, UC_MIPS_REG_SP, UC_MIPS_REG_PC
from unicorn.mips_const import UC_CPU_MIPS32_24KF
from unicorn.mips_const import UC_MIPS_REG_S0, UC_MIPS_REG_S5, UC_MIPS_REG_S7
from emulate_vcd_guards import EXPECTED_HASH, FLAGS_OFFSET, GP, RETURN, SECOND_CORE_DELTA

REG_ARGS = [UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_A2, UC_MIPS_REG_A3]
SINGLE = 0x80792530
BULK = 0x807920dc
BULK_TAIL = 0x80792194
SCRATCH = 0x81000000
HOOKS = {0x807992fc, 0x807992ec, 0x807991f4, 0x807985d0,
         0x80794380, 0x80792cf4, 0x80787a24}
STUB = struct.pack("<3I", 0x00001021, 0x03e00008, 0)
INPUT_STUB = struct.pack("<6I", 0x3c030001, 0x34632307, 0xac830000,
                         0x00001021, 0x03e00008, 0)


class StatusFlow:
    def __init__(self, data):
        if hashlib.sha256(data).hexdigest() != EXPECTED_HASH:
            raise ValueError("Unexpected imola2 firmware")
        self.uc = Uc(UC_ARCH_MIPS, UC_MODE_MIPS32 | UC_MODE_LITTLE_ENDIAN)
        self.uc.ctl_set_cpu_model(UC_CPU_MIPS32_24KF)
        self.uc.mem_map(0, 0xb01000)
        self.uc.mem_write(0, data)
        self.stubs = []
        self.stub_ranges = []
        for delta in (0, SECOND_CORE_DELTA):
            for address in sorted(HOOKS):
                offset = address + delta - 0x80000000
                flag_address = 0x80000000 + FLAGS_OFFSET + delta
                parser_stub = struct.pack("<10I",
                    0x3c080000 | (flag_address >> 16), 0x35080000 | (flag_address & 0xffff),
                    0x3c098100, 0x8d295000, 0x240a0001, 0xad090000, 0xa08a0000,
                    0x00001021, 0x03e00008, 0)
                stub = (parser_stub if address == 0x80792cf4 else
                        INPUT_STUB if address == 0x80794380 else STUB)
                self.stubs.append({"address": hex(address + delta),
                                   "original_hex": data[offset:offset + len(stub)].hex(),
                                   "guest_stub_hex": stub.hex()})
                self.stub_ranges.append((address, address + len(stub)))
                self.uc.mem_write(offset, stub)
        self.uc.mem_map(0x1000000, 0x10000)
        self.uc.reg_write(UC_MIPS_REG_SP, SCRATCH + 0x8000)
        self.uc.reg_write(UC_MIPS_REG_RA, RETURN)
        self.context = self.uc.context_save()
        self.uc.hook_add(UC_HOOK_CODE, self.on_code)
        self.uc.hook_add(UC_HOOK_MEM_WRITE, self.on_write)
        self.uc.hook_add(UC_HOOK_INTR, self.on_interrupt)

    def physical(self, address):
        return address & 0x1fffffff

    def word(self, address):
        return struct.unpack("<I", self.uc.mem_read(self.physical(address), 4))[0]

    def put(self, address, value):
        self.uc.mem_write(self.physical(address), struct.pack("<I", value & 0xffffffff))

    def on_write(self, uc, access, address, size, value, user_data):
        self.native_writes.append((hex(address), size, hex(value)))
        flag = FLAGS_OFFSET + self.delta
        if address == flag and size == 4:
            self.native_flag_writes.append(value)
        elif not 0x1000000 <= address < 0x1010000 - size + 1:
            raise RuntimeError(f"Unexpected native write: {address:x}")

    def on_interrupt(self, uc, number, user_data):
        raise RuntimeError(f"Guest interrupt {number}; PC {uc.reg_read(UC_MIPS_REG_PC):x}; "
                           f"trace {self.tail}; events {self.events}")

    def handle_boundary(self, pc, args):
        if pc in {0x807992fc, 0x807992ec, 0x807991f4, 0x807985d0}:
            self.events.append({"hook": hex(pc), "role": "opaque setup/drain boundary"})
            return
        if pc == 0x80794380:
            self.events.append({"hook": hex(pc), "role": "modeled NAL input", "type": 7})
            return
        if pc == 0x80792cf4:
            self.events.append({"hook": hex(pc), "role": "modeled NAL parser completion",
                                "flags_set": self.injected_flags, "stop_pointer": hex(args[0])})
            return
        if pc == 0x80787a24:
            self.logged_flags = args[2]
            self.events.append({"hook": hex(pc), "role": "modeled diagnostic sink",
                                "flags_argument": args[2]})
            return
        raise RuntimeError(f"Unknown boundary: {pc:x}")

    def on_code(self, uc, address, size, user_data):
        pc = address - self.delta
        self.tail = (self.tail + [hex(address)])[-16:]
        if pc in HOOKS:
            self.handle_boundary(pc, [uc.reg_read(r) for r in REG_ARGS])
            return
        if any(first < pc < end for first, end in self.stub_ranges):
            return
        allowed = [(SINGLE, 0x807925f4), (BULK, 0x807921f4),
                   (0x8078e974, 0x8078e98c), (0x8078f298, 0x8078f2d8)]
        if not any(first <= pc < end for first, end in allowed):
            raise RuntimeError(f"Unexpected native execution: {address:x}; trace {self.tail}; "
                               f"RA {uc.reg_read(UC_MIPS_REG_RA):x}; writes {self.native_writes}; "
                               f"stack RA {self.word(SCRATCH + 0x7ff0):x}; events {self.events}")

    def run(self, variant, injected_flags, delta=0):
        self.uc.context_restore(self.context)
        self.uc.reg_write(UC_MIPS_REG_SP, SCRATCH + 0x8000)
        self.uc.reg_write(UC_MIPS_REG_RA, RETURN)
        self.uc.mem_write(0x1000000, bytes(0x10000))
        self.delta, self.injected_flags = delta, injected_flags
        self.events, self.native_flag_writes = [], []
        self.native_writes = []
        self.tail = []
        self.logged_flags = None
        self.put(0x80000000 + FLAGS_OFFSET + delta, 0xa5a5a5a5)
        self.put(SCRATCH + 0x5000, injected_flags)
        self.uc.reg_write(UC_MIPS_REG_GP, GP + delta)
        output = SCRATCH + 0x1000
        self.put(output, 0xdeadbeef)
        if variant == "single":
            values = [7, output, SCRATCH + 0x2000, 0]
            entry = SINGLE
        elif variant == "bulk":
            context = SCRATCH + 0x3000
            self.put(context + 4, SCRATCH + 0x4000)
            values = [context, SCRATCH + 0x2000, output, SCRATCH + 0x2100]
            entry = BULK
        elif variant == "bulk_tail":
            values = [0, 0, 0, 0]
            entry = BULK_TAIL
            self.put(0x80000000 + FLAGS_OFFSET + delta, injected_flags)
            self.put(SCRATCH + 0x2000, 0x123)
            self.put(SCRATCH + 0x8040, RETURN)
            self.uc.reg_write(UC_MIPS_REG_S0, 1 << 7)
            self.uc.reg_write(UC_MIPS_REG_S5, SCRATCH + 0x2000)
            self.uc.reg_write(UC_MIPS_REG_S7, output)
        else:
            raise ValueError(variant)
        for reg, value in zip(REG_ARGS, values):
            self.uc.reg_write(reg, value)
        try:
            self.uc.emu_start(entry + delta, RETURN, count=2000)
        except unicorn.UcError as error:
            raise RuntimeError(f"{variant} core delta {delta:x}: {error}; trace {self.tail}; "
                               f"PC {self.uc.reg_read(UC_MIPS_REG_PC):x}") from error
        if self.uc.reg_read(UC_MIPS_REG_PC) != RETURN:
            raise RuntimeError("Wrapper did not return within the instruction bound")
        result = {"variant": variant, "core": "a" if delta == 0 else "b",
                  "entry": hex(entry + delta), "injected_parser_flags": injected_flags,
                  "output_flags": self.word(output),
                  "global_flags_after": self.word(0x80000000 + FLAGS_OFFSET + delta),
                  "diagnostic_flags": self.logged_flags,
                  "guest_flag_write_callbacks": self.native_flag_writes, "events": self.events}
        expected = ((0, injected_flags & 0xffffffff, 0) if variant == "single" else
                    (injected_flags & 0xffffffff, 0, injected_flags & 0xffffffff))
        actual = (result["output_flags"], result["global_flags_after"], result["diagnostic_flags"])
        if actual != expected:
            raise RuntimeError(f"Observed ordering differs from static hypothesis: {result}")
        return result


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--firmware", default="firmware/m4-v602/usr/codec/vcd_firmware_imola2.bin")
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    path = Path(args.firmware)
    data = path.read_bytes()
    if hashlib.sha256(data).hexdigest() != EXPECTED_HASH:
        raise ValueError("Unexpected imola2 firmware")
    vm = StatusFlow(data)
    cases = [vm.run(mode, flags, delta)
             for delta in (0, SECOND_CORE_DELTA)
             for mode in ("single", "bulk_tail")
             for flags in (0, 4, 0x20, 0x8000, 0x100000, 0xffffffff)]
    report = {"firmware": str(path.resolve()), "sha256": EXPECTED_HASH,
              "unicorn": unicorn.__version__, "passed_ordering_hypothesis": True,
              "unicorn_cpu_model": "MIPS32 24KF",
              "nal_parser_hooked": True, "hardware_boundaries_hooked": True,
              "guest_boundary_instructions_patched": True, "guest_boundary_stubs": vm.stubs,
              "wrapper_instructions_patched": False, "on_disk_firmware_modified": False,
              "full_decoder_emulated": False,
              "full_bulk_wrapper_emulated": False,
              "bulk_tail_preconditions_seeded": True,
              "full_bulk_limit": "Unicorn guest interrupt 20 after 0x80792194; not a camera result",
              "camera_playback": "NOT_TESTED", "cases": cases,
              "event_log_semantics": "Hook callbacks can repeat; not an instruction-execution count",
              "scope": "Original wrapper/getter/reset instructions, modeled boundary behavior only"}
    output = Path(args.output)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2), encoding="utf-8")
    print("status-ordering cases", len(cases), "passed; NAL and hardware boundaries are STUBS")


if __name__ == "__main__":
    main()
