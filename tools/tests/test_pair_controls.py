"""Purpose: regress matched-pair repack/reframe controls and additive copying.

Usage: python -m unittest discover -s tools/tests -p test_pair_controls.py -v.
Design: synthetic/temporary samples test complete ordered NAL preservation,
    sample boundaries, payload placement and refusal to replace existing files.
Scope: local comparison/copy invariants, not actual card deployment or playback.
"""
import sys
import tempfile
import unittest
from pathlib import Path
from uuid import UUID

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from build_sony_clip import ediustype_umid, payload_prefix, reframe_sample
from avc_hrd import nals
from deploy_sd_clip import durable_copy_new
from sony_mp4 import box
from sony_verification import equal_ranges
from sony_mp4 import ConstantSizes
from compare_nal_reframe import sample_sizes_equal


class PairControlsTests(unittest.TestCase):
    def test_equal_concatenated_metadata_bytes_do_not_hide_changed_sample_boundaries(self):
        self.assertFalse(sample_sizes_equal(ConstantSizes(1024, 2), [1023, 1025]))
        self.assertTrue(sample_sizes_equal(ConstantSizes(1024, 2), [1024, 1024]))
        self.assertFalse(sample_sizes_equal(ConstantSizes(1024, 2), ConstantSizes(512, 4)))
        self.assertTrue(sample_sizes_equal(ConstantSizes(4, 100000000), ConstantSizes(4, 100000000)))

    def test_reframing_preserves_every_ordered_nal_and_updates_each_prefix(self):
        units = [b"\x09AUD", b"\x06SEI", b"\x65" + bytes(257)]
        before = b"".join(len(x).to_bytes(3, "big") + x for x in units)
        after = reframe_sample(before, 3, 4)
        self.assertEqual(len(after) - len(before), len(units))
        self.assertEqual(nals(after, 4), units)
        self.assertEqual(reframe_sample(after, 4, 3), before)
        for malformed in (before[:-1], b"\0\0\0", b"\0\0"):
            with self.assertRaises(ValueError):
                reframe_sample(malformed, 3, 4)
        with self.assertRaises(ValueError):
            reframe_sample(before, 3, 2)

    def test_source_label_uses_uuid4_material_not_sony_time_mac(self):
        source = "060A2B340101010501010D23130000000D429B4F43AD42B0ACE7BB28181271B5"
        values = [bytes.fromhex(ediustype_umid(source)) for _ in range(2)]
        self.assertNotEqual(*values)
        for value in values:
            self.assertEqual(value[:16], bytes.fromhex(source)[:16])
            self.assertEqual(UUID(bytes=value[16:]).version, 4)
        with self.assertRaises(ValueError):
            ediustype_umid(source.replace("0D23", "0D43"))
        with self.assertRaises(ValueError):
            ediustype_umid("00")

    def test_both_compact_and_camera_aligned_prefixes(self):
        ftyp, prof = box("ftyp", bytes(20)), box("uuid", bytes(140))
        for offset in (192, 131072):
            prefix = payload_prefix(ftyp, prof, offset)
            self.assertEqual(len(prefix) + 16, offset)
            self.assertEqual(prefix[:176], ftyp + prof)
            if offset == 192:
                self.assertEqual(prefix, ftyp + prof)
            else:
                self.assertEqual(prefix[180:184], b"free")
        for offset in (191, 193, 199):
            with self.assertRaises(ValueError):
                payload_prefix(ftyp, prof, offset)

    def test_bounded_comparison_handles_last_block_offsets_and_truncation(self):
        a, b = b"xx0123456789", b"y0123456789z"
        self.assertTrue(equal_ranges(a, 2, b, 1, 10, 3))
        self.assertFalse(equal_ranges(a, 2, b, 2, 10, 3))
        self.assertFalse(equal_ranges(a, 2, b, 1, 11, 3))
        with self.assertRaises(ValueError):
            equal_ranges(a, -1, b, 0, 1)
        with self.assertRaises(ValueError):
            equal_ranges(a, 0, b, 0, 1, 0)

    def test_streaming_deployment_never_replaces_old_file(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            source, dest = root / "source", root / "dest"
            payload = bytes(range(256)) * 8193
            source.write_bytes(payload)
            durable_copy_new(source, dest)
            self.assertEqual(dest.read_bytes(), payload)
            source.write_bytes(b"changed")
            with self.assertRaises(FileExistsError):
                durable_copy_new(source, dest)
            self.assertEqual(dest.read_bytes(), payload)


if __name__ == "__main__":
    unittest.main()
