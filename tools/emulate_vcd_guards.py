"""Purpose: test selected scalar decoder guards from original imola2 firmware.

Usage: python tools/emulate_vcd_guards.py --output REPORT.json
    [--firmware IMAGE.bin --trace PARSED_TRACE.json].
Design: execute bounded, hardware-free leaf functions and compare their mapped
    fields with supported syntax traces and synthetic boundary values.
Scope: selected identified code/fields only. Not complete camera/codec emulation;
    no Sony custom instruction or hardware decoding semantics are implemented.
"""
import argparse
import hashlib
import json
import struct
from pathlib import Path

import unicorn
from unicorn import Uc, UC_ARCH_MIPS, UC_MODE_MIPS32, UC_MODE_LITTLE_ENDIAN, UC_HOOK_MEM_WRITE
from unicorn.mips_const import UC_MIPS_REG_A0, UC_MIPS_REG_GP, UC_MIPS_REG_RA
from unicorn.mips_const import UC_MIPS_REG_SP, UC_MIPS_REG_V0, UC_MIPS_REG_PC

EXPECTED_HASH = "15e75a9732e2f9904ada1c919c631dac0da57e605ce3daa4c6fb2ebe98982b5b"
RETURN = 0x80b00000
FLAGS_OFFSET = 0x7c0368
GP = 0x807bf0e0
SECOND_CORE_DELTA = 0x1ab000

# Semantic names follow the parser call sites, not stripped symbol names.
GUARDS = {
    "profile_idc": (0x8078eff4, list(range(256))),
    "level_idc": (0x8078f04c, list(range(256))),
    "seq_parameter_set_id": (0x8078f0a0, [0, 1, 31, 32, 255, 0xffffffff]),
    "chroma_format_idc": (0x8078f0c4, [0, 1, 2, 3, 4, 0xffffffff]),
    "log2_max_frame_num_minus4": (0x8078f13c, [0, 4, 12, 13, 31, 0xffffffff]),
    "pic_order_cnt_type": (0x8078f160, [0, 1, 2, 3, 4, 0xffffffff]),
    "log2_max_pic_order_cnt_lsb_minus4": (0x8078f184, [0, 4, 12, 13, 31, 0xffffffff]),
    "pic_width_in_mbs_minus1": (0x8078f1cc, [0, 4, 5, 119, 239, 511, 512, 1023]),
    "pic_parameter_set_id": (0x8078ee7c, [0, 1, 255, 256, 1023, 0xffffffff]),
    "num_slice_groups_minus1": (0x8078eea0, [0, 1, 2, 7, 255]),
    "num_ref_idx_l0_default_active_minus1": (0x8078eebc, [0, 1, 15, 31, 32, 255]),
    "num_ref_idx_l1_default_active_minus1": (0x8078eee4, [0, 1, 15, 31, 32, 255]),
    "chroma_qp_index_offset": (0x8078ef7c, list(range(-14, 15))),
    "redundant_pic_cnt_present_flag": (0x8078efa8, [0, 1]),
    "second_chroma_qp_index_offset": (0x8078efc8, list(range(-14, 15))),
    "vui_parameters_present_flag": (0x8078f24c, [0, 1]),
    "nal_hrd_parameters_present_flag": (0x8078f254, [0, 1]),
    "vcl_hrd_parameters_present_flag": (0x8078f25c, [0, 1]),
}


class LeafEmulator:
    def __init__(self, data):
        self.uc = Uc(UC_ARCH_MIPS, UC_MODE_MIPS32 | UC_MODE_LITTLE_ENDIAN)
        # Unicorn's MIPS CPU maps KSEG0 virtual accesses to physical addresses.
        self.uc.mem_map(0, 0xb01000)
        self.uc.mem_write(0, data)
        self.uc.mem_map(0x1000000, 0x10000)
        self.uc.reg_write(UC_MIPS_REG_SP, 0x81008000)
        self.uc.reg_write(UC_MIPS_REG_RA, RETURN)
        self.context = self.uc.context_save()
        self.expected_write = None
        self.unexpected_writes = []
        self.uc.hook_add(UC_HOOK_MEM_WRITE, self.on_write)

    def on_write(self, uc, access, address, size, value, user_data):
        if address != self.expected_write or size != 4:
            self.unexpected_writes.append({"address": hex(address), "size": size})
            uc.emu_stop()

    def call(self, address, value, delta=0):
        uc = self.uc
        uc.context_restore(self.context)
        self.expected_write = FLAGS_OFFSET + delta
        self.unexpected_writes = []
        uc.mem_write(self.expected_write, bytes(4))
        uc.reg_write(UC_MIPS_REG_A0, value & 0xffffffff)
        uc.reg_write(UC_MIPS_REG_GP, GP + delta)
        uc.emu_start(address + delta, RETURN, count=200)
        if self.unexpected_writes:
            raise RuntimeError(f"Not a pure selected guard: {self.unexpected_writes}")
        if uc.reg_read(UC_MIPS_REG_PC) != RETURN:
            raise RuntimeError(f"Guard did not return at {address + delta:x}")
        return {"input": value, "return_u32": uc.reg_read(UC_MIPS_REG_V0),
                "flags_u32": struct.unpack("<I", uc.mem_read(self.expected_write, 4))[0]}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--firmware", default="firmware/m4-v602/usr/codec/vcd_firmware_imola2.bin")
    ap.add_argument("--trace", action="append", default=[])
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    path = Path(args.firmware)
    data = path.read_bytes()
    digest = hashlib.sha256(data).hexdigest()
    if digest != EXPECTED_HASH:
        raise ValueError("Only the independently mapped M4 6.02 imola2 image is supported")
    emu = LeafEmulator(data)
    report = {"firmware": str(path.resolve()), "sha256": digest, "unicorn": unicorn.__version__,
              "camera_playback": "NOT_TESTED", "full_decoder_emulated": False,
              "custom_instructions_emulated": False, "hardware_hooks": False,
              "cores": {"a_gp": hex(GP), "b_gp": hex(GP + SECOND_CORE_DELTA)},
              "guards": {}, "traces": []}
    for field, (address, values) in GUARDS.items():
        a = [emu.call(address, value) for value in values]
        b = [emu.call(address, value, SECOND_CORE_DELTA) for value in values]
        if a != b:
            raise RuntimeError(f"Different behavior between core copies: {field}")
        report["guards"][field] = {"address_a": hex(address),
                                   "address_b": hex(address + SECOND_CORE_DELTA),
                                   "both_copies_equal": True, "cases": a}
    for trace in args.trace:
        fields = json.loads(Path(trace).read_text(encoding="utf-8"))
        checks = []
        for name, (address, _) in GUARDS.items():
            for value in fields.get(name, []):
                result = emu.call(address, value)
                checks.append({"field": name, **result, "not_corrected_or_flagged":
                               result["return_u32"] == (value & 0xffffffff) and
                               result["flags_u32"] == 0})
        report["traces"].append({"trace": str(Path(trace).resolve()), "checks": checks,
                                 "trace_sha256": hashlib.sha256(Path(trace).read_bytes()).hexdigest(),
                                 "missing_trace_fields": sorted(set(GUARDS) - set(fields)),
                                 "passed_selected_guards": bool(checks) and all(
                                     c["not_corrected_or_flagged"] for c in checks),
                                 "scope": "Selected scalar helpers only; not full syntax or decode"})
    output = Path(args.output)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2), encoding="utf-8")
    print("guards", len(GUARDS), "cases", sum(len(x["cases"]) for x in report["guards"].values()),
          "per core; traces", [(x["trace"], x["passed_selected_guards"]) for x in report["traces"]])


if __name__ == "__main__":
    main()
