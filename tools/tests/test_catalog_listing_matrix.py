"""Purpose: regress hash-bound joining of catalog evidence and user observations.

Usage: python -m unittest discover -s tools/tests
    -p test_catalog_listing_matrix.py -v.
Design: mutate saved/local report fixtures to test binding, record indexes,
    original profile joins and preservation of unknown observation states.
Scope: evidence classification, not a new camera test or live card inspection.
"""
import copy
import json
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

ROOT = Path(__file__).resolve().parents[2]
SNAPSHOT = ROOT / "backup/snap_20261112T214535"
CONVERTER = ROOT / "analysis/sidb-original-converter-0021.json"
OBSERVATIONS = ROOT / "analysis/camera_observations_20261112.json"


@unittest.skipUnless(SNAPSHOT.is_dir() and CONVERTER.is_file() and OBSERVATIONS.is_file(),
                     "Requires the local offline listing-evidence fixtures")
class ListingMatrixTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.converter = json.loads(CONVERTER.read_text(encoding="utf-8"))
        cls.observations = json.loads(OBSERVATIONS.read_text(encoding="utf-8"))

    def test_partial_user_observations_do_not_classify_unknowns(self):
        from catalog_listing_matrix import build_matrix
        result = build_matrix(SNAPSHOT, self.converter, self.observations)
        self.assertEqual(result["counts_by_observed_listing"],
                         {"unknown_in_this_round": 24, "listed": 9, "not_listed": 9})
        rows = {row["clip"]: row for row in result["movies"]}
        for clip in ("C6499", "C6359"):
            self.assertEqual(rows[clip]["observed_listing"], "unknown_in_this_round")
        for clip in self.observations["listing_unknown_examples"]:
            if clip in rows:
                self.assertEqual(rows[clip]["observed_listing"], "unknown_in_this_round")
        self.assertEqual(rows["C6503"]["observed_listing"], "not_listed")
        self.assertEqual(rows["C0007"]["observed_listing"], "listed")
        self.assertFalse(result["root_cause_established"])
        self.assertTrue(all(row["camera_admission_proven_by_emulation"] is False
                            for row in rows.values()))
        self.assertTrue(all(row["material_present"] for row in rows.values()))
        self.assertTrue(all(row["persistent_root_filter_bit4"] for row in rows.values()))
        self.assertTrue(all(row["nested_reader_failures"] == [] for row in rows.values()))

    def test_mismatched_database_report_is_refused(self):
        from catalog_listing_matrix import build_matrix
        report = copy.deepcopy(self.converter)
        for case in report["snapshots"]:
            case["database_sha256"] = "0" * 64
        with self.assertRaisesRegex(ValueError, "does not match"):
            build_matrix(SNAPSHOT, report, self.observations)

    def test_record_index_mismatch_is_refused(self):
        from catalog_listing_matrix import build_matrix
        report = copy.deepcopy(self.converter)
        report["snapshots"][-1]["movies"][0]["record_index"] += 1
        with self.assertRaisesRegex(ValueError, "record index mismatch"):
            build_matrix(SNAPSHOT, report, self.observations)

    def test_original_profile_parser_is_bound_to_xml_hash(self):
        from catalog_listing_matrix import build_matrix
        report = {"profile_sha256": "0" * 64}
        with self.assertRaisesRegex(ValueError, "snapshot XML hash"):
            build_matrix(SNAPSHOT, self.converter, self.observations, report)

    def test_original_profile_parser_join(self):
        from catalog_listing_matrix import build_matrix
        path = ROOT / "analysis/mediapro-original-parser-0021.json"
        if not path.is_file():
            self.skipTest("Requires completed local original-parser report")
        parser = json.loads(path.read_text(encoding="utf-8"))
        result = build_matrix(SNAPSHOT, self.converter, self.observations, parser)
        for movie in result["movies"]:
            with self.subTest(clip=movie["clip"]):
                self.assertEqual(movie["original_mediapro_parse_query"]["original_clip_info_return"], 0)
                self.assertTrue(movie["original_mediapro_umid_matches_sidecar"])


if __name__ == "__main__":
    unittest.main()
