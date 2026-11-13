"""Purpose: regress original decoder status-wrapper ordering and guest stubs.

Usage: python -m unittest discover -s tools/tests -p test_vcd_status_flow.py -v.
Design: identified firmware vectors check status copy/reset ordering, original
    wrapper bytes and explicitly modeled parser/log/hardware boundaries.
Scope: bounded harness behavior; stubbed parsing does not validate a bitstream
    or reproduce actual Sony hardware/camera playback.
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
class VcdStatusFlowTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        from emulate_vcd_status_flow import StatusFlow
        cls.data = FIRMWARE.read_bytes()
        cls.vm = StatusFlow(cls.data)

    def test_single_copies_status_before_modeled_parser(self):
        from emulate_vcd_guards import SECOND_CORE_DELTA
        for delta in (0, SECOND_CORE_DELTA):
            for flags in (0, 4, 0x20, 0x8000, 0x100000, 0xffffffff):
                with self.subTest(delta=delta, flags=flags):
                    result = self.vm.run("single", flags, delta)
                    self.assertEqual(result["output_flags"], 0)
                    self.assertEqual(result["global_flags_after"], flags)
                    self.assertEqual(result["diagnostic_flags"], 0)
                    writes = result["guest_flag_write_callbacks"]
                    self.assertEqual(writes[-1], flags)
                    self.assertTrue(writes[:-1])
                    self.assertTrue(all(value == 0 for value in writes[:-1]))

    def test_seeded_bulk_tail_copies_then_clears_status(self):
        from emulate_vcd_guards import SECOND_CORE_DELTA
        for delta in (0, SECOND_CORE_DELTA):
            for flags in (0, 4, 0x20, 0x8000, 0x100000, 0xffffffff):
                with self.subTest(delta=delta, flags=flags):
                    result = self.vm.run("bulk_tail", flags, delta)
                    self.assertEqual(result["output_flags"], flags)
                    self.assertEqual(result["global_flags_after"], 0)
                    self.assertEqual(result["diagnostic_flags"], flags)
                    writes = result["guest_flag_write_callbacks"]
                    self.assertTrue(writes)
                    self.assertTrue(all(value == 0 for value in writes))

    def test_wrapper_getter_and_reset_bytes_are_original(self):
        from emulate_vcd_guards import SECOND_CORE_DELTA, EXPECTED_HASH
        from emulate_vcd_status_flow import SINGLE, BULK
        for delta in (0, SECOND_CORE_DELTA):
            for start, end in ((SINGLE, 0x807925f4), (BULK, 0x807921f4),
                               (0x8078e974, 0x8078e98c)):
                offset = start + delta - 0x80000000
                self.assertEqual(bytes(self.vm.uc.mem_read(offset, end - start)),
                                 self.data[offset:offset + end - start])
        self.assertEqual(hashlib.sha256(FIRMWARE.read_bytes()).hexdigest(), EXPECTED_HASH)

    def test_stub_report_matches_guest_and_original_bytes(self):
        self.assertEqual(len(self.vm.stubs), 14)
        for stub in self.vm.stubs:
            offset = int(stub["address"], 16) - 0x80000000
            replacement = bytes.fromhex(stub["guest_stub_hex"])
            self.assertEqual(bytes(self.vm.uc.mem_read(offset, len(replacement))), replacement)
            self.assertEqual(self.data[offset:offset + len(replacement)].hex(),
                             stub["original_hex"])

    def test_refuses_unknown_image(self):
        from emulate_vcd_status_flow import StatusFlow
        with self.assertRaisesRegex(ValueError, "Unexpected imola2"):
            StatusFlow(b"not firmware")


if __name__ == "__main__":
    unittest.main()
