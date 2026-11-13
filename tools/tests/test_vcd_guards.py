"""Purpose: regress selected original imola2 scalar decoder guard behavior.

Usage: python -m unittest discover -s tools/tests -p test_vcd_guards.py -v.
Design: run identified hardware-free leaf routines across profile/chroma/width,
    slice-group and QP-offset boundary cases, checking original code provenance.
Scope: local firmware subset only, not full decoding or custom hardware semantics.
"""
import hashlib
import importlib.util
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

FIRMWARE = Path(__file__).resolve().parents[2] / "firmware/m4-v602/usr/codec/vcd_firmware_imola2.bin"
AVAILABLE = FIRMWARE.is_file() and importlib.util.find_spec("unicorn") is not None


@unittest.skipUnless(AVAILABLE, "Requires the local imola2 image and Unicorn")
class VcdGuardTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        from emulate_vcd_guards import LeafEmulator, EXPECTED_HASH
        data = FIRMWARE.read_bytes()
        if hashlib.sha256(data).hexdigest() != EXPECTED_HASH:
            raise ValueError("Unexpected local firmware")
        cls.emulator = LeafEmulator(data)

    def check_guard(self, name, value, expected, flags=0):
        from emulate_vcd_guards import GUARDS, SECOND_CORE_DELTA
        for delta in (0, SECOND_CORE_DELTA):
            result = self.emulator.call(GUARDS[name][0], value, delta)
            self.assertEqual(result["return_u32"], expected & 0xffffffff, (name, value, delta))
            self.assertEqual(result["flags_u32"], flags, (name, value, delta))

    def test_profiles_from_original_instructions(self):
        for value in (66, 77, 100, 110, 122):
            self.check_guard("profile_idc", value, value)
        for value in (0, 244):
            self.check_guard("profile_idc", value, 100, 4)

    def test_chroma(self):
        for value in (1, 2):
            self.check_guard("chroma_format_idc", value, value)
        for value in (0, 3):
            self.check_guard("chroma_format_idc", value, 1, 0x20)

    def test_single_slice_group(self):
        self.check_guard("num_slice_groups_minus1", 0, 0)
        self.check_guard("num_slice_groups_minus1", 1, 0, 0x8000)

    def test_redundant_picture(self):
        self.check_guard("redundant_pic_cnt_present_flag", 0, 0)
        self.check_guard("redundant_pic_cnt_present_flag", 1, 0, 0x100000)

    def test_hrd_flags_are_not_forced_here(self):
        for name in ("nal_hrd_parameters_present_flag", "vcl_hrd_parameters_present_flag"):
            for value in (0, 1):
                self.check_guard(name, value, value)

    def test_width_guard(self):
        self.check_guard("pic_width_in_mbs_minus1", 119, 119)
        self.check_guard("pic_width_in_mbs_minus1", 0, 5, 0x1000)
        self.check_guard("pic_width_in_mbs_minus1", 512, 511, 0x1000)

    def test_chroma_qp_offset(self):
        for value in (-12, 0, 12):
            self.check_guard("chroma_qp_index_offset", value, value)
        for value in (-13, 13):
            self.check_guard("chroma_qp_index_offset", value, 0, 0x80000)


if __name__ == "__main__":
    unittest.main()
