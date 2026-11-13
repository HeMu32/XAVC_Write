"""Purpose: regress fresh verification evidence and guarded writer admission.

Usage: python -m unittest discover -s tools/tests -p test_sony_verification.py -v.
Design: synthetic reports and temporary media test schema/hash requirements,
    stale/empty decode rejection and separation of candidate/control contracts.
Scope: local contract enforcement, not live deployment or physical playback.
"""
import json
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from sony_verification import FRAMING_CHECKS, NATIVE_CHECKS, SOURCE_CHECKS, REQUIRED_CHECKS, SCHEMA, digest, require_current_verification, require_package_hashes, run_media_checks


class VerificationContractTests(unittest.TestCase):
    def valid_report(self):
        return {"verification_schema": SCHEMA, "passed": True,
                "checks": dict.fromkeys(REQUIRED_CHECKS, True)}

    def test_accepts_complete_current_report(self):
        require_current_verification(self.valid_report())

    def test_rejects_legacy_or_incomplete_report(self):
        for report in ({"passed": True}, {"verification_schema": SCHEMA, "passed": True, "checks": {}}):
            with self.subTest(report=report), self.assertRaises(ValueError):
                require_current_verification(report)
        report = self.valid_report()
        del report["checks"]["selected_cbr_cpb"]
        with self.assertRaises(ValueError):
            require_current_verification(report)

    def test_rejects_false_or_nonboolean_checks(self):
        for value in (False, 1, "true", None):
            report = self.valid_report()
            report["checks"]["sei_container_timing"] = value
            with self.subTest(value=value), self.assertRaises(ValueError):
                require_current_verification(report)

    def test_rejects_malformed_check_container(self):
        for value in (None, list(REQUIRED_CHECKS)):
            report = self.valid_report()
            report["checks"] = value
            with self.subTest(value=value), self.assertRaises(ValueError):
                require_current_verification(report)

    def test_native_control_cannot_substitute_for_encoded_verification(self):
        report = {"verification_schema": SCHEMA, "verification_profile": "native_control",
                  "passed": True, "checks": dict.fromkeys(NATIVE_CHECKS, True)}
        require_current_verification(report, "native_control")
        with self.assertRaises(ValueError):
            require_current_verification(report)
        with self.assertRaises(ValueError):
            require_current_verification(self.valid_report(), "native_control")

    def test_native_control_needs_source_identity_and_exact_payload(self):
        for missing in NATIVE_CHECKS:
            report = {"verification_schema": SCHEMA, "verification_profile": "native_control",
                      "passed": True, "checks": dict.fromkeys(NATIVE_CHECKS - {missing}, True)}
            with self.subTest(missing=missing), self.assertRaises(ValueError):
                require_current_verification(report, "native_control")

    def test_unknown_profile_is_not_admitted(self):
        with self.assertRaises(ValueError):
            require_current_verification(self.valid_report(), "unknown")

    def test_diagnostic_framing_control_cannot_substitute_for_candidate(self):
        report = {"verification_schema": SCHEMA, "verification_profile": "framing_control",
                  "passed": True, "checks": dict.fromkeys(FRAMING_CHECKS, True)}
        require_current_verification(report, "framing_control")
        with self.assertRaises(ValueError):
            require_current_verification(report)
        with self.assertRaises(ValueError):
            require_current_verification(self.valid_report(), "framing_control")
        del report["checks"]["explicit_diagnostic_framing_control"]
        with self.assertRaises(ValueError):
            require_current_verification(report, "framing_control")

    def test_legacy_candidate_report_without_qualified_framing_is_refused(self):
        report = self.valid_report()
        del report["checks"]["qualified_candidate_nal_framing"]
        with self.assertRaises(ValueError):
            require_current_verification(report)

    def test_candidate_report_without_profile_consistency_is_refused(self):
        report = self.valid_report()
        del report["checks"]["selected_profile_consistent"]
        with self.assertRaises(ValueError):
            require_current_verification(report)

    def test_source_control_needs_explicit_profile_minimal_catalog_and_bound_source(self):
        required = SOURCE_CHECKS - {"sd_acquisition_matches_xml"} | {
            "sd_metadata_omission_matches_positive_template",
            "sd_minimal_catalog_rebuilt_exactly", "sd_positive_template_observation_bound"}
        report = {"verification_schema": SCHEMA, "verification_profile": "source_control",
                  "catalog_representation": "observed_minimal", "passed": True,
                  "checks": dict.fromkeys(required, True)}
        require_current_verification(report, "source_control", expected_catalog="observed_minimal")
        with self.assertRaises(ValueError):
            require_current_verification(report, expected_catalog="observed_minimal")
        with self.assertRaises(ValueError):
            require_current_verification(report, "source_control")
        for missing in required:
            value = report["checks"].pop(missing)
            with self.subTest(missing=missing), self.assertRaises(ValueError):
                require_current_verification(report, "source_control", expected_catalog="observed_minimal")
            report["checks"][missing] = value

    def test_rec709_requires_matching_declaration_and_stream_evidence(self):
        report = self.valid_report()
        with self.assertRaises(ValueError):
            require_current_verification(report, "encoded_avc", "rec709")
        report["acquisition"] = "rec709"
        with self.assertRaises(ValueError):
            require_current_verification(report, "encoded_avc", "rec709")
        report["checks"]["rec709_stream_and_acquisition_agree"] = True
        require_current_verification(report, "encoded_avc", "rec709")

    def test_minimal_mode_cannot_implicitly_waive_native_checks(self):
        report = self.valid_report()
        report["catalog_representation"] = "observed_minimal"
        del report["checks"]["sd_acquisition_matches_xml"]
        with self.assertRaises(ValueError):
            require_current_verification(report)
        with self.assertRaises(ValueError):
            require_current_verification(report, expected_catalog="observed_minimal")
        for name in ("sd_metadata_omission_matches_positive_template",
                     "sd_minimal_catalog_rebuilt_exactly", "sd_positive_template_observation_bound"):
            report["checks"][name] = True
        require_current_verification(report, expected_catalog="observed_minimal")
        with self.assertRaises(ValueError):
            require_current_verification(report, expected_catalog="native_reuse")
        for name in ("selected_cbr_cpb", "sd_minimal_catalog_rebuilt_exactly"):
            value = report["checks"].pop(name)
            with self.assertRaises(ValueError):
                require_current_verification(report, expected_catalog="observed_minimal")
            report["checks"][name] = value


class FreshMediaEvidenceTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.build = Path(self.temp.name)
        self.base = self.build / "base.mov"
        self.media = self.build / "C9999.MP4"
        self.base.write_bytes(b"base fixture")
        self.media.write_bytes(b"media fixture")
        self.fail_decode = False
        self.empty_frames = False
        self.stale_hash = False
        self.frame_line = "0, 0, 0, 1, 16, test-frame-hash\n"
        # Deliberately plausible old cached results must never become new evidence.
        for name in ("base.framemd5", "C9999.framemd5"):
            (self.build / name).write_text(self.frame_line)

    def fake_run(self, command, **kwargs):
        if command[0] == "ffmpeg":
            if self.fail_decode:
                return subprocess.CompletedProcess(command, 1)
            Path(command[-1]).write_text("" if self.empty_frames else self.frame_line)
        else:
            report_path = Path(command[command.index("--output") + 1])
            self.assertNotEqual(Path(kwargs["stdout"].name), report_path.with_suffix(".log"))
            report_path.write_text(json.dumps({
                "sha256": "stale" if self.stale_hash else digest(self.media),
                "passed_selected_checks": True, "passed_selected_cpb_checks": True}))
        return subprocess.CompletedProcess(command, 0)

    def run_checks(self):
        with patch("sony_verification.subprocess.run", side_effect=self.fake_run):
            return run_media_checks(self.build, "C9999", self.base, 1)

    def test_fresh_paths_and_hash_bound_reports(self):
        checks, proof = self.run_checks()
        self.assertTrue(all(checks.values()), checks)
        self.assertEqual(len(proof["runs"]), 5)
        self.assertNotEqual(Path(proof["directory"]), self.build)
        for run in proof["runs"][:2]:
            self.assertEqual(Path(run["command"][-1]).parent, Path(proof["directory"]))

    def test_decoder_failure_does_not_reuse_cached_frames(self):
        self.fail_decode = True
        checks, _ = self.run_checks()
        self.assertFalse(checks["decoded_frames_and_timestamps_bit_exact"])

    def test_empty_successful_decoder_output_is_not_a_pass(self):
        self.empty_frames = True
        checks, _ = self.run_checks()
        self.assertFalse(checks["decoded_frames_and_timestamps_bit_exact"])

    def test_stale_bitstream_report_is_refused(self):
        self.stale_hash = True
        checks, _ = self.run_checks()
        for name in ("sei_container_timing", "progressive_slice_order", "selected_cbr_cpb"):
            self.assertFalse(checks[name])

    def test_complete_package_manifest_and_transaction_hashes_are_required(self):
        names = {"C9999.MP4", "C9999M01.XML", "C9999T01.JPG",
                 "catalog/DATABASE.BIN", "catalog/MEDIAPRO.XML",
                 "catalog/transaction.json", "build-manifest.json"}
        for name in names:
            path = self.build / name
            path.parent.mkdir(exist_ok=True)
            path.write_bytes(name.encode("ascii"))
        report = {"package_hashes": {name: digest(self.build / name) for name in names}}
        require_package_hashes(report, self.build, "C9999")
        for name in names:
            value = report["package_hashes"].pop(name)
            with self.subTest(missing=name), self.assertRaises(ValueError):
                require_package_hashes(report, self.build, "C9999")
            report["package_hashes"][name] = value
        (self.build / "catalog/transaction.json").write_bytes(b"changed baseline")
        with self.assertRaisesRegex(ValueError, "transaction"):
            require_package_hashes(report, self.build, "C9999")


if __name__ == "__main__":
    unittest.main()
