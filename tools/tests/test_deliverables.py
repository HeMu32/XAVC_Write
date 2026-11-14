"""Check local-only inventory behavior and the separate post-repair feedback."""
import hashlib
import json
from pathlib import Path
import re
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from inventory_deliverables import file_ref, package_view, write_report

ROOT = Path(__file__).resolve().parents[2]


class InventoryTests(unittest.TestCase):
    def test_media_is_not_hashed_and_text_is_hash_bound(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            media, text = root / "clip.MP4", root / "report.json"
            media.write_bytes(b"media")
            text.write_bytes(b'{"passed": true}\r\n')
            self.assertNotIn("sha256", file_ref(root, media, set()))
            row = file_ref(root, text, {"report.json"})
            self.assertTrue(row["git_tracked"])
            self.assertEqual(row["sha256"], hashlib.sha256(text.read_bytes()).hexdigest())

    def test_old_pass_and_deployment_do_not_imply_current_approval_or_playback(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            manifest = root / "build-manifest.json"
            manifest.write_text(json.dumps({"clip": "C0010", "sha256": "declared"}))
            (root / "verification.json").write_text(json.dumps(
                {"passed": True, "verification_schema": 5}))
            (root / "deployment.json").write_text(json.dumps({"status": "deployed"}))
            row = package_view(root, manifest, set())
            self.assertTrue(row["historical_verification"]["passed"])
            self.assertEqual(row["historical_verification"]["schema"], 5)
            self.assertFalse(row["historical_verification"]["current_admission_recomputed"])
            self.assertFalse(row["physical_playback_inferred_from_local_reports"])
            self.assertFalse(row["media_hash_recomputed"])
            self.assertEqual(row["declared_media_sha256"], "declared")
            self.assertTrue(all(not asset["exists"] for asset in row["assets"]))

    def test_output_is_local_and_cannot_overwrite_evidence(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            output = root / "analysis/inventory.json"
            write_report(root, output, {"card_access": False})
            saved = output.read_bytes()
            with self.assertRaises(FileExistsError):
                write_report(root, output, {"changed": True})
            self.assertEqual(output.read_bytes(), saved)
            with self.assertRaises(ValueError):
                write_report(root, root / "outside.json", {})


class DeliveryEvidenceTests(unittest.TestCase):
    def test_post_repair_success_is_new_hash_bound_feedback_for_C0010_only(self):
        report = json.loads((ROOT / "analysis/camera-observations-0033-result.json").read_text("utf-8"))
        binding = report["binding"]
        for key in ("deployment_summary", "post_repair_disk_report"):
            self.assertEqual(hashlib.sha256((ROOT / binding[key]).read_bytes()).hexdigest(),
                             binding[key + "_sha256"])
        result, = report["results"]
        self.assertEqual(result["clip"], "C0010")
        summary = json.loads((ROOT / binding["deployment_summary"]).read_text("utf-8"))
        self.assertEqual(result["media_sha256"], summary["media_sha256"])
        for key in ("plays_normally", "post_repair_playback", "post_repair_listed",
                    "survives_reported_database_repair"):
            self.assertIs(result[key], True)
        for key in ("thumbnail_normal", "full_duration_playback", "audio", "seek"):
            self.assertIsNone(result[key])
        self.assertFalse(report["card_access_this_recording_turn"])
        previous = json.loads((ROOT / "analysis/camera-observations-0032-result.json").read_text("utf-8"))
        self.assertIsNone(previous["results"][0]["post_repair_playback"])
        self.assertIsNone(summary["camera"]["starts_playback"])

    def test_delivery_document_links_exist_in_workspace(self):
        document = ROOT / "docs/deliverables.md"
        links = re.findall(r"\[[^\]]+\]\(([^)]+)\)", document.read_text("utf-8"))
        self.assertGreater(len(links), 20)
        for target in links:
            self.assertTrue((document.parent / target).resolve().exists(), target)

    def test_inventory_records_artifacts_without_playback_or_card_claims(self):
        report = json.loads((ROOT / "analysis/deliverables-inventory-20261114.json").read_text("utf-8"))
        self.assertFalse(report["card_access"])
        self.assertFalse(report["card_writes"])
        self.assertFalse(report["media_hashes_recomputed"])
        self.assertTrue(report["saved_reports_are_not_current_deployment_approval"])
        self.assertEqual(report["counts"]["media_packages"], len(report["media_packages"]))
        self.assertEqual(report["counts"]["snapshot_summaries"], len(report["saved_snapshots"]))
        self.assertGreaterEqual(len(report["media_packages"]), 30)
        for package in report["media_packages"]:
            self.assertFalse(package["historical_verification"]["current_admission_recomputed"])
            self.assertFalse(package["physical_playback_inferred_from_local_reports"])
        self.assertTrue(any("0033-result.json" in row["path"]
                            for row in report["camera_feedback_reports"]))


if __name__ == "__main__":
    unittest.main()
