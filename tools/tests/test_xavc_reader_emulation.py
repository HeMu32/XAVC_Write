"""Purpose: regress selected original Sony MP4 read-side probes.

Usage: python -m unittest discover -s tools/tests
    -p test_xavc_reader_emulation.py -v.
Design: saved local clips and malformed controls compare properties, sample
    indexes, parameter arrays, RTMD, decode-table preparation and timeout handling.
Scope: identified firmware with modeled dependencies; no hardware decode,
    live card or full-duration camera playback is exercised.
"""
import importlib.util
import copy
import mmap
import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
ROOT = Path(__file__).resolve().parents[2]
FIRMWARE = ROOT / "firmware/m4-v602/usr/lib/libmpr.so"
EXPAT = FIRMWARE.parent / "libexpat.so.1.6.11"
SNAPSHOT = ROOT / "backup/snap_20261112T233331"
MEDIA = ROOT / "output/native-minimal-C6509/C6509.MP4"
AVAILABLE = (FIRMWARE.is_file() and EXPAT.is_file() and MEDIA.is_file() and
             all(importlib.util.find_spec(x) for x in ("unicorn", "elftools")))


@unittest.skipUnless(AVAILABLE, "Requires offline firmware and local native-control media")
class XavcReaderTests(unittest.TestCase):
    def test_original_samples_parameters_and_decode_tables_match_independent_index(self):
        from emulate_xavc_reader import XavcReaderEmulator, validate_sample_probe
        with MEDIA.open("rb") as stream, mmap.mmap(stream.fileno(), 0, access=mmap.ACCESS_READ) as data:
            engine = XavcReaderEmulator(FIRMWARE, EXPAT, SNAPSHOT, data)
            result = engine.run_reader(seek_probe=True, sample_batches=8, decode_tables=True)
        probe = result["sample_probe"]
        validation = validate_sample_probe(MEDIA, probe)
        self.assertTrue(validation["passed"], validation)
        self.assertTrue(probe["reached_video_end"])
        self.assertEqual(validation["video_frames_checked"], 90)
        self.assertTrue(result["original_executable_sections_unchanged"])
        changed = copy.deepcopy(probe)
        row = bytearray.fromhex(changed["batches"][0]["video_rows"][0])
        row[8] ^= 1
        changed["batches"][0]["video_rows"][0] = row.hex()
        self.assertFalse(validate_sample_probe(MEDIA, changed)["checks"]["video_rows_match_source"])
        changed = copy.deepcopy(probe)
        changed["batches"][0]["video_bytes"] += 1
        self.assertFalse(validate_sample_probe(MEDIA, changed)["checks"]["batch_byte_totals_match_rows"])

    def test_original_rtmd_conversion_requires_present_timecode_not_only_outer_success(self):
        from emulate_xavc_reader import XavcReaderEmulator
        from sony_mp4 import MP4
        source = MP4(ROOT / "output/cat-minimal-C6510/C6510.MP4")
        try:
            track = next(t for t in source.tracks if t.handler == "meta")
            good = track.sample(0)
        finally:
            source.close()
        engine = XavcReaderEmulator(FIRMWARE, EXPAT, SNAPSHOT, b"")
        results = engine.rtmd_probe([(0, good), (-1, bytes(1024))])["packets"]
        self.assertEqual(results[0]["transit_return_u32"], 0)
        self.assertTrue(results[0]["basic_timecode_present"])
        self.assertEqual(results[0]["table_conversion_return_u32"], 0)
        self.assertEqual(results[0]["table_count"], 1)
        self.assertEqual(bytes.fromhex(results[0]["table_hex"])[0x40:0x44],
                         bytes.fromhex(results[0]["basic_timecode_item_hex"])[8:12])
        self.assertFalse(results[1]["basic_timecode_present"])
        self.assertEqual(results[1]["table_conversion_return_u32"], 0)

    def test_wall_time_budget_is_an_emulator_error_not_media_rejection(self):
        from emulate_xavc_reader import XavcReaderEmulator
        engine = XavcReaderEmulator(FIRMWARE, EXPAT, SNAPSHOT, b"")
        engine.deadline = 0
        with self.assertRaises(TimeoutError):
            engine.step("budget_test", 0x22a730, [engine.file_object], False)
        self.assertEqual(engine.steps, [])

    def test_original_parser_accepts_native_samples_and_returns_expected_properties(self):
        from emulate_xavc_reader import XavcReaderEmulator
        with MEDIA.open("rb") as stream, mmap.mmap(stream.fileno(), 0, access=mmap.ACCESS_READ) as data:
            engine = XavcReaderEmulator(FIRMWARE, EXPAT, SNAPSHOT, data)
            result = engine.run_reader(seek_probe=True)
        self.assertEqual(result["last_status_u32"], 0)
        self.assertTrue(result["original_executable_sections_unchanged"])
        properties = bytes.fromhex(result["movie_property_hex"])
        self.assertEqual(struct.unpack_from("<H", properties, 0x2c)[0], 25)
        self.assertEqual(struct.unpack_from("<I", properties, 0x30)[0], 90)
        self.assertTrue(result["audio_gate"]["accepted_by_literal_property_predicate"])
        self.assertEqual([x["return_u32"] for x in engine.steps[2:]], [0, 0, 0, 0, 0])
        self.assertEqual(result["selected_seek_probe"]["return_u32"], 0)
        self.assertFalse(result["selected_seek_probe"]["physical_camera_parameters_observed"])

    def test_truncated_movie_and_missing_movie_box_are_rejected(self):
        from emulate_xavc_reader import XavcReaderEmulator
        from sony_mp4 import MP4
        media = MP4(MEDIA)
        moov = media.one(media.top, "moov")
        missing_moov = bytearray(media.buf)
        missing_moov[moov.start + 4:moov.start + 8] = b"free"
        media.close()
        for name, data in (("truncated", bytes(256)), ("missing_moov", bytes(missing_moov))):
            with self.subTest(case=name):
                engine = XavcReaderEmulator(FIRMWARE, EXPAT, SNAPSHOT, data)
                result = engine.run_reader()
                self.assertNotEqual(result["last_status_u32"], 0)
                self.assertIsNone(result["audio_gate"])
                self.assertTrue(result["original_executable_sections_unchanged"])
                self.assertNotIn("original_movie_property_query",
                                 {x["label"] for x in engine.steps})

    def test_audio_predicate_rejects_unsupported_rate_codec_and_track_layout(self):
        from emulate_xavc_reader import audio_gate
        properties = bytearray(0x60)
        struct.pack_into("<I", properties, 0x40, 1)
        struct.pack_into("<I", properties, 0x44, 1)
        self.assertTrue(audio_gate(properties)["accepted_by_literal_property_predicate"])
        for offset, value in ((0x34, 1), (0x38, 2), (0x3c, 1), (0x40, 0), (0x44, 2)):
            with self.subTest(offset=offset):
                changed = bytearray(properties)
                struct.pack_into("<I", changed, offset, value)
                self.assertFalse(audio_gate(changed)["accepted_by_literal_property_predicate"])


@unittest.skipUnless(AVAILABLE, "Requires optional emulator dependencies")
class AvccIndexTests(unittest.TestCase):
    def test_parameter_arrays_are_length_delimited_not_substring_matches(self):
        from emulate_xavc_reader import parameter_sets_from_avcc
        source = bytes.fromhex("0164002affe1000267640100026880")
        self.assertEqual(parameter_sets_from_avcc(source), {2: ["6764"], 3: ["6880"]})
        for data in (source[:5], source[:-1], bytes.fromhex("0164002affe1ffff")):
            with self.subTest(data=data), self.assertRaises(ValueError):
                parameter_sets_from_avcc(data)


if __name__ == "__main__":
    unittest.main()
