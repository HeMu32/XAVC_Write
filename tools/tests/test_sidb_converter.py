"""Purpose: regress original sidb record conversion and dependency behavior.

Usage: python -m unittest discover -s tools/tests -p test_sidb_converter.py -v.
Design: execute identified firmware against saved databases, checking paths,
    flag offsets, actual main-UMID output and checksum-corruption propagation.
Scope: offline converter harness only, not full Select, runtime UI or playback.
"""
import importlib.util
import json
import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

ROOT = Path(__file__).resolve().parents[2]
FIRMWARE = ROOT / "firmware/m4-v602/usr/lib/libmpr.so"
SNAPSHOT = ROOT / "backup/snap_20261112T213116"
AVAILABLE = (FIRMWARE.is_file() and SNAPSHOT.is_dir() and
             all(importlib.util.find_spec(name) for name in ("unicorn", "elftools")))


@unittest.skipUnless(AVAILABLE, "Requires offline M4 firmware, snapshot, Unicorn and pyelftools")
class SidbConverterTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        from emulate_sidb_converter import RecordConverter
        from sony_db import inventory
        cls.engine = RecordConverter(FIRMWARE)
        cls.data = (SNAPSHOT / "PRIVATE/DATABASE/DATABASE.BIN").read_bytes()
        cls.movies = [row for row in inventory(cls.data) if row.get("content_type") == 2]

    def test_every_movie_converts_with_correct_filename(self):
        self.engine.load(self.data)
        observed = json.loads((ROOT / "analysis/camera_observations_20261112.json").read_text(
            encoding="utf-8"))
        seen = set()
        self.assertEqual(len(self.movies), 42)
        for movie in self.movies:
            clip = f"C{movie['clip_number']:04d}"
            with self.subTest(clip=clip):
                seen.add(clip)
                result = self.engine.convert(movie["index"])
                self.assertEqual(result["return_u32"], 0)
                self.assertEqual(result["record_info_content_type"], 4)
                self.assertEqual(result["restored_paths"]["main"],
                                 f"A:/PRIVATE/M4ROOT/CLIP/{clip}.MP4")
                self.assertEqual(result["restored_paths"]["nrt"],
                                 f"A:/PRIVATE/M4ROOT/CLIP/{clip}M01.XML")
                self.assertEqual(result["restored_paths"]["thumbnail"],
                                 f"A:/PRIVATE/M4ROOT/THMBNL/{clip}T01.JPG")
                expected_proxy = f"A:/PRIVATE/M4ROOT/SUB/{clip}S03.MP4" if movie["path_refs"][3] else ""
                self.assertEqual(result["restored_paths"]["proxy"], expected_proxy)
                self.assertTrue(result["original_guest_writes_confined_to_stack_and_output"])
                self.assertGreater(result["original_instruction_addresses_executed"], 600)
                self.assertTrue(all(row["return_u32"] == 0
                                    for row in result["original_reader_returns"]))
        self.assertTrue(set(observed["current_listing_positive_examples_not_exhaustive"]) <= seen)
        self.assertTrue(set(observed["current_listing_negative_confirmed"]) <= seen)
        self.assertEqual(bytes(self.engine.uc.mem_read(0x10000000, len(self.data))), self.data)

    def test_legacy_optional_refs_and_native_refs_follow_different_original_paths(self):
        self.engine.load(self.data)
        selected = {row["clip_number"]: row for row in self.movies}
        legacy = self.engine.convert(selected[7]["index"])
        native = self.engine.convert(selected[6503]["index"])
        legacy_symbols = {row["symbol"] for row in legacy["executed_original_entrypoints"]}
        native_symbols = {row["symbol"] for row in native["executed_original_entrypoints"]}
        array_symbol = "_ZN4sidb26RestorateArrayBinaryRecordEPKNS_13fileStructureENS_16BinaryRecordTypeEjjPhj"
        self.assertNotIn(array_symbol, legacy_symbols)
        self.assertIn(array_symbol, native_symbols)
        self.assertEqual(legacy["return_u32"], 0)
        self.assertEqual(native["return_u32"], 0)

    def test_dependency_checksum_failures_and_converter_status_propagation(self):
        native = next(row for row in self.movies if row["clip_number"] == 6503)
        raw = bytes.fromhex(native["hex"])
        array = struct.unpack_from("<H", raw, 0x5A)[0] | ((raw[0x5C] >> 5 & 1) << 16)
        self.engine.load(self.data)
        original = bytes.fromhex(self.engine.convert(native["index"])["record_info_hex"])
        self.assertNotEqual(original[0x4F8:0x518], bytes(32))
        for index in [31, 30, 29, native["video_info_ref"], array]:
            with self.subTest(reference=index):
                changed = bytearray(self.data)
                changed[0x10000 + index * 160 + 158] ^= 1
                self.engine.load(changed)
                result = self.engine.convert(native["index"])
                expected = 0x406 if index in {31, 30, 29} else 0
                self.assertEqual(result["return_u32"], expected)
                self.assertTrue(any(row["return_u32"] == 0x406
                                    for row in result["original_reader_returns"]))
                if index == native["video_info_ref"]:
                    self.assertEqual(bytes.fromhex(result["record_info_hex"])[0x26], 0)
                if index == array:
                    self.assertEqual(bytes.fromhex(result["record_info_hex"])[0x4F8:0x518],
                                     bytes(32))
        self.engine.load(self.data)
        self.assertEqual(self.engine.convert(native["index"])["return_u32"], 0)

    def test_main_umid_offset_matches_independent_record_restoration(self):
        from sony_umid import restore_umid
        from sony_db import inventory
        self.engine.load(self.data)
        records = {row["index"]: row for row in inventory(self.data)}
        for row in self.movies:
            raw = bytes.fromhex(row["hex"])
            array_id = struct.unpack_from("<H", raw, 0x5A)[0] | ((raw[0x5C] >> 5 & 1) << 16)
            output = bytes.fromhex(self.engine.convert(row["index"])["record_info_hex"])
            expected = (restore_umid(raw, bytes.fromhex(records[array_id]["hex"]))
                        if array_id else bytes(32))
            with self.subTest(clip=row["clip_number"]):
                self.assertEqual(output[0x4F8:0x518], expected)

    def test_output_offsets_follow_original_record_flag_bits(self):
        self.engine.load(self.data)
        for movie in self.movies:
            with self.subTest(clip=movie["clip_number"]):
                output = bytes.fromhex(self.engine.convert(movie["index"])["record_info_hex"])
                raw = bytes.fromhex(movie["hex"])
                self.assertEqual(output[0x619], raw[6] >> 2 & 1)
                self.assertEqual(output[0x61A], raw[6] >> 3 & 1)


if __name__ == "__main__":
    unittest.main()
