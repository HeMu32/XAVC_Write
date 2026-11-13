"""Check that listing feedback is bound to the corrected, not original, files."""
import hashlib
import json
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from sony_profiles import PROFILES

ROOT = Path(__file__).resolve().parents[2]


class CurrentEvidenceTests(unittest.TestCase):
    def test_feedback_is_listing_only_and_bound_to_immutable_write_audit(self):
        path = ROOT / "analysis/camera-observations-0031-result.json"
        report = json.loads(path.read_text(encoding="utf-8"))
        binding = report["binding"]
        audit_path = ROOT / binding["deployment_audit"]
        self.assertEqual(hashlib.sha256(audit_path.read_bytes()).hexdigest(),
                         binding["deployment_audit_sha256"])
        audit = json.loads(audit_path.read_text(encoding="utf-8"))
        deployed = {r["clip"]: r["corrected_media_sha256"] for r in audit["deployments"]}
        self.assertEqual({r["clip"] for r in report["results"]}, {"C6520", "C6521"})
        for row in report["results"]:
            self.assertIs(row["listed"], True)
            self.assertEqual(row["corrected_media_sha256"], deployed[row["clip"]])
            self.assertEqual(row["listing_evidence"], "EXPLICIT_USER_REPORT")
            for key in ("thumbnail_normal", "starts_playback", "full_duration_playback",
                        "audio", "seek", "survives_another_database_repair"):
                self.assertIsNone(row[key], key)
        self.assertFalse(report["historical_preparation_and_deployment_reports_rewritten"])

    def test_new_listing_feedback_does_not_rewrite_old_preparation_verdict(self):
        audit = json.loads((ROOT / "analysis/0031-repair-final-audit.json").read_text(encoding="utf-8"))
        self.assertEqual(audit["phase"], "AUTHORIZED_TARGETED_REPAIR_WRITTEN_AWAITING_CAMERA")
        self.assertEqual(audit["camera_listing_C6520_C6521"], "AWAITING_USER_TEST")
        self.assertEqual(set(PROFILES), {
            "hd25_5994", "hd50_5994", "uhd60_2997", "hd50_2997", "hd16_2997"})
        self.assertFalse(any("4m" in name.lower() for name in PROFILES))


if __name__ == "__main__":
    unittest.main()
