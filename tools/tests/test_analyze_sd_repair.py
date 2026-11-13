"""Purpose: regress offline repair analysis, reference graphs and report binding.

Usage: python -m unittest discover -s tools/tests -p test_analyze_sd_repair.py -v.
Design: combine small synthetic records with the saved repair-pair corpus,
    including stale-media-hash rejection and sparse-template refusal.
Scope: local fixtures/artifacts only; no live card access or physical validation.
"""
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from analyze_sd_repair import (
    analyze, array_inventory, changed_ranges, content_references, converter_views,
)

ROOT = Path(__file__).resolve().parents[2]
BEFORE = ROOT / "backup/snap_20261113T135135"
AFTER = ROOT / "backup/snap_20261113T135646"


def row(index, raw):
    return {"index": index, "type": raw[0] & 15, "hex": raw.hex(),
            "content_type": raw[7] & 15, "clip_number": index}


class RepairAnalysisTests(unittest.TestCase):
    def test_changed_ranges_do_not_merge_equal_gaps(self):
        values = changed_ranges(bytes(6), b"\1\2\0\3\0\4")
        self.assertEqual([(v["start"], v["end_exclusive"]) for v in values],
                         [(0, 2), (3, 4), (5, 6)])
        self.assertEqual(changed_ranges(b"a", b"a"), [])
        with self.assertRaises(ValueError):
            changed_ranges(b"a", b"")

    def test_movie_reference_high_bits_and_slot(self):
        raw = bytearray(160)
        raw[7] = 2
        struct.pack_into("<6H", raw, 0x50, 1, 2, 3, 4, 5, 6)
        raw[0x5c] = 0x3f
        raw[0x5d] = 0x30
        values = content_references(row(1, raw))
        self.assertEqual([value["reference"] for value in values],
                         [65537, 65538, 65539, 65540, 65541, 65542])
        self.assertEqual(values[-1]["slot"], 3)

    def test_photo_unique_id_is_not_movie_video_reference(self):
        raw = bytearray(160)
        raw[7] = 1
        struct.pack_into("<H", raw, 0x4a, 72)
        raw[0x4d] = 0x30
        struct.pack_into("<H", raw, 0x58, 101)
        raw[0x5a] = 0x78
        refs = {v["field"]: v for v in content_references(row(1, raw))}
        self.assertEqual(refs["umid"]["reference"], 72)
        self.assertEqual(refs["umid"]["slot"], 3)
        self.assertEqual(refs["image_unique_id"]["reference"], 65637)
        self.assertEqual(refs["image_unique_id"]["slot"], 7)

    def test_array_counts_include_photos_and_movies(self):
        array = bytearray(160)
        array[0], array[4], array[5], array[6] = 3, 2, 32, 1
        struct.pack_into("<I", array, 8, 2)
        photo, movie = bytearray(160), bytearray(160)
        photo[7], movie[7] = 1, 2
        struct.pack_into("<H", photo, 0x4a, 3)
        struct.pack_into("<H", movie, 0x5a, 3)
        rows = {i: row(i, raw) for i, raw in enumerate((photo, movie, array), 1)}
        value = array_inventory(rows)["arrays"][0]
        self.assertTrue(value["reference_count_matches"])
        self.assertEqual(value["all_content_owner_count"], 2)
        self.assertTrue(value["owners_point_to_occupied_slots"])
        array[6] = 0
        rows[3] = row(3, array)
        self.assertFalse(array_inventory(rows)["arrays"][0]["owners_point_to_occupied_slots"])

    def test_converter_report_requires_matching_hash(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "report.json"
            path.write_text(json.dumps({"snapshots": []}), encoding="utf-8")
            with self.assertRaisesRegex(ValueError, "hash"):
                converter_views(path, [(b"unrelated", {}, {})])

    @unittest.skipUnless((AFTER / "_snapshot.json").is_file(), "Local repair corpus unavailable")
    def test_saved_repair_pair_regression_and_stager_rejection(self):
        report = analyze(BEFORE, AFTER, ROOT / "analysis/repair-original-converter-0027.json",
                         ROOT / "output/profiles-0026-hd50/package/build-manifest.json",
                         [ROOT / "analysis/xavc-reader-C6515-ionly-0025.json"],
                         ROOT / "analysis/repair-media-hashes-0027.json",
                         [ROOT / "analysis/repair-embedded-nrt-C6515-0027.json"])
        self.assertTrue(report["passed"])
        self.assertEqual(report["active_record_counts"], [96, 115])
        self.assertEqual(report["changed_database_bytes"], 2246)
        self.assertEqual(report["modified_existing_record_counts"],
                         {"movie": 38, "photo": 23, "array": 1})
        self.assertEqual(len(report["movies"]), 51)
        self.assertTrue(all(value["ltc_start_matches_xml"] and value["ltc_end_matches_xml"]
                            for value in report["movies"]))
        self.assertEqual(len(report["umid_summary"]["unexplained_by_subsecond_loss"]), 11)
        self.assertEqual(report["empty_video_record_28"]["known_incoming_references_after"], [])
        self.assertEqual(report["minimal_template_probe"]["results"][1]["next_free_after_cursor"], 118)
        self.assertTrue(report["checks"]["selected_sdk_properties_match_repaired_catalog"])
        self.assertTrue(report["checks"]["selected_nrt_original_scans_match_saved_metadata"])
        with tempfile.TemporaryDirectory() as directory:
            source = ROOT / "analysis/repair-embedded-nrt-C6515-0027.json"
            changed = json.loads(source.read_text(encoding="utf-8"))
            changed["media_sha256"] = "0" * 64
            path = Path(directory) / "stale-nrt.json"
            path.write_text(json.dumps(changed), encoding="utf-8")
            with self.assertRaisesRegex(ValueError, "uniquely bound"):
                analyze(BEFORE, AFTER, ROOT / "analysis/repair-original-converter-0027.json",
                        ROOT / "output/profiles-0026-hd50/package/build-manifest.json",
                        media_hashes_path=ROOT / "analysis/repair-media-hashes-0027.json",
                        nrt_paths=[path])


if __name__ == "__main__":
    unittest.main()
