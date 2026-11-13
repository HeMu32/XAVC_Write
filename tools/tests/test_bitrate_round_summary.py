"""A passed audit must belong to the card, baseline and complete ordered round."""
import copy
import json
from pathlib import Path
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from summarize_bitrate_round import validate_audit_binding


class AuditBindingTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        root = Path(self.temp.name)
        self.card, self.before = root / "card", root / "before"
        self.builds = [root / "A", root / "B"]
        packages, readback = [], {
            "PRIVATE/DATABASE/DATABASE.BIN": True, "PRIVATE/M4ROOT/MEDIAPRO.XML": True}
        for i, build in enumerate(self.builds):
            build.mkdir()
            clip, sha = f"C{9000+i}", str(i) * 64
            (build / "build-manifest.json").write_text(
                json.dumps({"clip": clip, "sha256": sha}), encoding="utf-8")
            packages.append({"package": str(build), "clip": clip, "media_sha256": sha})
            readback.update({
                f"PRIVATE/M4ROOT/CLIP/{clip}.MP4": True,
                f"PRIVATE/M4ROOT/CLIP/{clip}M01.XML": True,
                f"PRIVATE/M4ROOT/THMBNL/{clip}T01.JPG": True})
        self.audit = {
            "passed": True, "card": str(self.card), "checks": {"preserved": True},
            "before_snapshot_audit": {"card": str(self.card), "snapshot": str(self.before)},
            "packages": packages, "readback": readback}

    def verify(self, audit):
        return validate_audit_binding(audit, self.card, self.before, self.builds)

    def test_matching_audit(self):
        self.verify(self.audit)

    def test_other_baseline_or_card_rejected(self):
        for key in ("card", "baseline", "inner_card"):
            audit = copy.deepcopy(self.audit)
            if key == "card":
                audit["card"] += "-different"
            elif key == "baseline":
                audit["before_snapshot_audit"]["snapshot"] += "-different"
            else:
                audit["before_snapshot_audit"]["card"] += "-different"
            with self.subTest(key=key), self.assertRaises(ValueError):
                self.verify(audit)

    def test_other_package_hash_identity_or_order_rejected(self):
        for key in ("package", "clip", "media_sha256", "order"):
            audit = copy.deepcopy(self.audit)
            if key == "order":
                audit["packages"].reverse()
            else:
                audit["packages"][0][key] += "-different"
            with self.subTest(key=key), self.assertRaises(ValueError):
                self.verify(audit)

    def test_partial_readback_or_failed_checks_rejected(self):
        for mode in ("missing_asset", "false_asset", "nonboolean_asset", "empty_checks",
                     "failed_check", "false_verdict", "incomplete"):
            audit = copy.deepcopy(self.audit)
            if mode == "missing_asset":
                audit["readback"].pop(next(iter(audit["readback"])))
            elif mode in ("false_asset", "nonboolean_asset"):
                audit["readback"][next(iter(audit["readback"]))] = (
                    False if mode == "false_asset" else 1)
            elif mode == "empty_checks":
                audit["checks"] = {}
            elif mode == "failed_check":
                audit["checks"]["preserved"] = False
            elif mode == "false_verdict":
                audit["passed"] = False
            else:
                del audit["before_snapshot_audit"]
            with self.subTest(mode=mode), self.assertRaises(ValueError):
                self.verify(audit)


if __name__ == "__main__":
    unittest.main()
