"""Purpose: regress read-only snapshot-bound media hashing and path safeguards.

Usage: python -m unittest discover -s tools/tests
    -p test_hash_snapshot_media.py -v.
Design: temporary synthetic card trees and mocked digests exercise hashes,
    inventory binding, duplicate aliases, path escape and concurrent stat drift.
Scope: temporary fixtures only; never accesses the physical memory card.
"""
import csv
import hashlib
import json
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import hash_snapshot_media as target


class HashSnapshotMediaTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.card = self.root / "card"
        self.snapshot = self.root / "snapshot"
        self.output = self.root / "reports" / "hashes.json"
        self.card.mkdir()
        self.snapshot.mkdir()
        self.payloads = {"PRIVATE/M4ROOT/CLIP/C6512.MP4": b"three-byte-control\x00\xff",
                         "PRIVATE/M4ROOT/THMBNL/C6512T01.JPG": b"\xff\xd8tiny\xff\xd9"}
        for name, payload in self.payloads.items():
            path = self.card / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(payload)
        self.inventory = [
            {"relative_path": name, "size": len(payload),
             "last_write_time_ns": (self.card / name).stat().st_mtime_ns}
            for name, payload in self.payloads.items()
        ]
        self.save_inventory()

    def save_inventory(self, summary_errors=None, summary_count=None):
        with (self.snapshot / "_skipped_media_manifest.csv").open(
                "w", encoding="utf-8-sig", newline="") as stream:
            writer = csv.DictWriter(stream, fieldnames=[
                "relative_path", "size", "last_write_time_ns"])
            writer.writeheader()
            writer.writerows(self.inventory)
        (self.snapshot / "_snapshot.json").write_text(json.dumps({
            "card": str(self.card), "snapshot": str(self.snapshot),
            "skipped_media": len(self.inventory) if summary_count is None else summary_count,
            "errors": summary_errors or [],
        }), encoding="utf-8")

    def run_hash(self, output=None):
        return target.hash_media(self.card, self.snapshot, self.output if output is None else output)

    def test_success_hashes_exact_bytes_binds_manifest_and_preserves_inputs(self):
        before = {p: p.read_bytes() for folder in (self.card, self.snapshot)
                  for p in folder.rglob("*") if p.is_file()}
        stats = {p: (p.stat().st_size, p.stat().st_mtime_ns) for p in before}
        report = self.run_hash()
        self.assertTrue(report["passed"])
        self.assertEqual(report["errors"], [])
        self.assertEqual(report["algorithm"], "sha256")
        self.assertFalse(report["card_writes"])
        self.assertEqual(report["media_count"], 2)
        self.assertEqual(report["expected_media_count"], 2)
        self.assertEqual(report["bytes_hashed"], sum(map(len, self.payloads.values())))
        self.assertEqual(report["snapshot_media_manifest_sha256"], hashlib.sha256(
            (self.snapshot / "_skipped_media_manifest.csv").read_bytes()).hexdigest())
        self.assertEqual(json.loads(self.output.read_text()), report)
        for row in report["entries"]:
            self.assertEqual(row["sha256"], hashlib.sha256(
                self.payloads[row["relative_path"]]).hexdigest())
        after = {p: p.read_bytes() for folder in (self.card, self.snapshot)
                 for p in folder.rglob("*") if p.is_file()}
        self.assertEqual(before, after)
        self.assertEqual(stats, {p: (p.stat().st_size, p.stat().st_mtime_ns) for p in after})

    def test_empty_complete_inventory(self):
        self.inventory = []
        self.save_inventory()
        report = self.run_hash()
        self.assertTrue(report["passed"])
        self.assertEqual(report["media_count"], 0)
        self.assertEqual(report["bytes_hashed"], 0)

    def test_existing_output_is_never_replaced(self):
        self.output.parent.mkdir()
        self.output.write_bytes(b"keep existing report")
        with self.assertRaises(FileExistsError):
            self.run_hash()
        self.assertEqual(self.output.read_bytes(), b"keep existing report")

    def test_card_and_snapshot_output_paths_rejected_before_writes(self):
        for output in (self.card, self.card / "new.json",
                       self.snapshot, self.snapshot / "new.json"):
            with self.subTest(output=output), self.assertRaisesRegex(ValueError, "Report must not"):
                self.run_hash(output)
        self.assertFalse((self.card / "new.json").exists())
        self.assertFalse((self.snapshot / "new.json").exists())

    def test_sibling_with_similar_prefix_is_allowed(self):
        report = self.run_hash(self.root / "card-reports" / "report.json")
        self.assertTrue(report["passed"])

    def test_incomplete_inventory_or_snapshot_errors_reject_without_report(self):
        for count, errors in ((3, []), (2, [{"path": "missing", "error": "read failed"}])):
            with self.subTest(count=count, errors=errors):
                self.save_inventory(summary_count=count, summary_errors=errors)
                with self.assertRaisesRegex(ValueError, "Incomplete snapshot"):
                    self.run_hash()
                self.assertFalse(self.output.exists())

    def test_size_or_mtime_drift_is_not_hashed(self):
        for field in ("size", "last_write_time_ns"):
            with self.subTest(field=field):
                self.inventory[0][field] += 1
                self.save_inventory()
                with patch.object(target.hashlib, "file_digest", wraps=hashlib.file_digest) as digest:
                    report = self.run_hash(self.root / (field + ".json"))
                self.assertFalse(report["passed"])
                self.assertEqual(digest.call_count, 1)
                self.assertEqual(report["media_count"], 1)
                self.assertIn("differs from saved inventory", report["errors"][0]["error"])
                self.inventory[0][field] -= 1

    def test_missing_media_is_recorded_and_other_media_continue(self):
        (self.card / self.inventory[0]["relative_path"]).unlink()
        report = self.run_hash()
        self.assertFalse(report["passed"])
        self.assertEqual(report["media_count"], 1)
        self.assertEqual(report["errors"][0]["relative_path"], self.inventory[0]["relative_path"])

    def test_invalid_numeric_manifest_value_becomes_entry_error(self):
        self.inventory[0]["size"] = "not-a-size"
        self.save_inventory()
        report = self.run_hash()
        self.assertFalse(report["passed"])
        self.assertEqual(report["media_count"], 1)
        self.assertEqual(len(report["errors"]), 1)

    def test_duplicate_path_is_rejected(self):
        self.inventory.append(dict(self.inventory[0]))
        self.save_inventory()
        report = self.run_hash()
        self.assertFalse(report["passed"])
        self.assertEqual(report["media_count"], 2)
        self.assertIn("duplicate", report["errors"][0]["error"])

    def test_escape_absolute_outside_and_card_root_are_not_opened(self):
        outside = self.root / "outside.mp4"
        outside.write_bytes(b"not card media")
        for index, relative in enumerate(("../outside.mp4", str(outside), ".")):
            with self.subTest(relative=relative):
                self.inventory = [{"relative_path": relative, "size": outside.stat().st_size,
                                   "last_write_time_ns": outside.stat().st_mtime_ns}]
                self.save_inventory()
                with patch.object(target.hashlib, "file_digest") as digest:
                    report = self.run_hash(self.root / f"invalid-{index}.json")
                digest.assert_not_called()
                self.assertFalse(report["passed"])
                self.assertIn("Invalid", report["errors"][0]["error"])

    def test_mutation_during_digest_is_detected_before_entry_is_accepted(self):
        original = hashlib.file_digest
        first = self.card / self.inventory[0]["relative_path"]

        def mutate(stream, algorithm):
            result = original(stream, algorithm)
            if Path(stream.name) == first:
                first.write_bytes(b"changed size during hashing")
            return result

        with patch.object(target.hashlib, "file_digest", side_effect=mutate):
            report = self.run_hash()
        self.assertFalse(report["passed"])
        self.assertEqual(report["media_count"], 1)
        self.assertIn("changed during hashing", report["errors"][0]["error"])

    def test_final_recheck_catches_earlier_item_changing_during_later_hash(self):
        original = hashlib.file_digest
        first = self.card / self.inventory[0]["relative_path"]
        second = self.card / self.inventory[1]["relative_path"]

        def mutate_earlier(stream, algorithm):
            result = original(stream, algorithm)
            if Path(stream.name) == second:
                first.write_bytes(b"earlier file changed")
            return result

        with patch.object(target.hashlib, "file_digest", side_effect=mutate_earlier):
            report = self.run_hash()
        self.assertFalse(report["passed"])
        self.assertEqual(report["media_count"], 2)
        self.assertIn("final inventory recheck", report["errors"][0]["error"])

    def test_known_bug_normalized_alias_duplicate_should_be_rejected(self):
        alias = dict(self.inventory[0])
        alias["relative_path"] = "./" + alias["relative_path"]
        self.inventory.append(alias)
        self.save_inventory()
        report = self.run_hash()
        self.assertFalse(report["passed"], "Raw path strings hide a duplicate resolved file")

    def test_known_bug_case_alias_duplicate_should_be_rejected_on_windows(self):
        if sys.platform != "win32":
            self.skipTest("Case-insensitive Windows inventory alias")
        alias = dict(self.inventory[0])
        alias["relative_path"] = alias["relative_path"].lower()
        self.inventory.append(alias)
        self.save_inventory()
        report = self.run_hash()
        self.assertFalse(report["passed"], "Case variants hide a duplicate resolved file")


if __name__ == "__main__":
    unittest.main()
