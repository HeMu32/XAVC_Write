"""Strict original-reader evidence tests; all inputs are offline or temporary."""
import copy
import hashlib
import importlib.util
import io
import json
import subprocess
import sys
import tempfile
import unittest
from contextlib import redirect_stderr, redirect_stdout
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import bitrate_reader_evidence as evidence
from bitrate_experiment import ExperimentSpec
from sony_profiles import get_profile

ROOT = Path(__file__).resolve().parents[2]


def spec(profile="hd16_2997", variant="B"):
    nominal = get_profile(profile).bitrate_kbps if variant == "A" else 4000
    return ExperimentSpec.from_dict({
        "schema": 1, "kind": "bitrate_diagnostic", "experiment_id": "reader-test",
        "pair_id": profile + "-4m", "variant": variant, "base_profile": profile,
        "coded_bitrate_kbps": 4000, "hrd_bitrate_kbps": 4000, "cpb_size_kbits": 4000,
        "prof_average_kbps": nominal, "prof_maximum_kbps": nominal,
        "creation_time": "2026-11-13T12:00:00+08:00",
    })


class RejectionEvidenceTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.media = self.root / "LOCAL.MP4"
        self.media.write_bytes(b"bounded offline test input")
        firmware, runtime = self.root / "libmpr.so", self.root / "libstdc++.so"
        firmware.write_bytes(b"test firmware")
        runtime.write_bytes(b"test runtime")
        self.firmware_hash = hashlib.sha256(firmware.read_bytes()).hexdigest()
        for name, value in (("FIRMWARE", firmware), ("RUNTIME", runtime),
                            ("FIRMWARE_SHA256", self.firmware_hash)):
            mock = patch.object(evidence, name, value)
            mock.start()
            self.addCleanup(mock.stop)
        steps = []
        for label in evidence.OPEN_STEPS:
            constructor = label.endswith("_constructor")
            steps.append({"label": label, "entry_elf_vma": hex(evidence.ENTRIES[label]),
                          "return_u32": None if constructor else
                          (3 if label == "original_movie_property_query" else 0),
                          "void_return_ignored": constructor})
        self.report = {
            "media": str(self.media), "media_sha256": hashlib.sha256(self.media.read_bytes()).hexdigest(),
            "firmware_sha256": self.firmware_hash,
            "original_stdcpp_sha256": hashlib.sha256(runtime.read_bytes()).hexdigest(),
            "card_access": False, "root_cause_established": False,
            "passed_selected_reader_checks": False,
            "original_executable_sections_unchanged_after_all_probes": True,
            "steps": steps, "active_step": {key: steps[-1][key] for key in ("label", "entry_elf_vma")},
            "result": {"last_status_u32": 3, "selected_seek_probe": None, "sample_probe": None,
                       "audio_gate": None, "original_executable_sections_unchanged": True},
        }

    def validate(self, report=None, selected=None):
        return evidence.validate_reader_report(
            self.report if report is None else report, self.media, selected or spec())

    def test_exact_property_rejection_is_expected_and_raw_report_is_not_mutated(self):
        original = copy.deepcopy(self.report)
        assessment = self.validate()
        self.assertTrue(assessment["passed"])
        self.assertTrue(assessment["expected_rejection"])
        self.assertEqual(assessment["expected_query_status"], 3)
        self.assertIsNone(assessment["probe_mode"])
        self.assertFalse(assessment["probe_mode_observed"])
        self.assertTrue(all(assessment["checks"].values()))
        self.assertEqual(self.report, original)
        self.assertFalse(self.report["passed_selected_reader_checks"])
        self.assertEqual(self.validate(selected=spec().to_dict()), assessment)

    def test_rejection_has_no_waiver_outside_exact_profile_and_variant(self):
        for profile, variant in (("hd16_2997", "A"), ("hd25_5994", "A"), ("hd25_5994", "B")):
            with self.subTest(profile=profile, variant=variant), self.assertRaises(ValueError):
                self.validate(selected=spec(profile, variant))

    def test_invalid_spec_cannot_supply_arbitrary_expected_status(self):
        raw = spec().to_dict()
        raw["expected_reader_status"] = 3
        with self.assertRaises(ValueError):
            self.validate(selected=raw)

    def test_earlier_status_failures_are_not_expected_property_rejection(self):
        for index in (2, 3, 4):
            changed = copy.deepcopy(self.report)
            changed["steps"][index]["return_u32"] = 3
            with self.subTest(index=index), self.assertRaises(ValueError):
                self.validate(changed)

    def test_each_required_step_must_be_present_and_in_order(self):
        for index in range(6):
            changed = copy.deepcopy(self.report)
            del changed["steps"][index]
            with self.subTest(missing=index), self.assertRaises(ValueError):
                self.validate(changed)
        changed = copy.deepcopy(self.report)
        changed["steps"][2:4] = reversed(changed["steps"][2:4])
        with self.assertRaises(ValueError):
            self.validate(changed)

    def test_duplicate_or_downstream_steps_are_not_accepted(self):
        changed = copy.deepcopy(self.report)
        changed["steps"].append(copy.deepcopy(changed["steps"][-1]))
        with self.assertRaises(ValueError):
            self.validate(changed)
        for key in ("rtmd_probe", "sample_index_crosscheck"):
            changed = copy.deepcopy(self.report)
            changed[key] = {}
            with self.subTest(key=key), self.assertRaises(ValueError):
                self.validate(changed)

    def test_wrong_property_address_or_status_is_rejected(self):
        for value in (0, 1, 2, 4, True, "3", None):
            changed = copy.deepcopy(self.report)
            changed["steps"][-1]["return_u32"] = value
            with self.subTest(value=value), self.assertRaises(ValueError):
                self.validate(changed)
        changed = copy.deepcopy(self.report)
        changed["steps"][-1]["entry_elf_vma"] = "0x22a380"
        with self.assertRaises(ValueError):
            self.validate(changed)
        changed = copy.deepcopy(self.report)
        changed["result"]["last_status_u32"] = 0
        with self.assertRaises(ValueError):
            self.validate(changed)

    def test_constructors_are_void_and_boolean_statuses_are_not_integers(self):
        for index, field, value in ((0, "return_u32", 0), (1, "void_return_ignored", False),
                                    (2, "return_u32", False), (2, "void_return_ignored", True)):
            changed = copy.deepcopy(self.report)
            changed["steps"][index][field] = value
            with self.subTest(index=index, field=field), self.assertRaises(ValueError):
                self.validate(changed)

    def test_errors_and_timeouts_are_never_rejection_evidence_even_if_empty(self):
        for key, value in (("emulation_error", "budget exhausted"), ("emulation_error", ""),
                           ("error_kind", "TimeoutError"), ("error_kind", "UcError"),
                           ("partial_sample_batches_not_complete", []),
                           ("guest_registers_at_failure", {})):
            changed = copy.deepcopy(self.report)
            changed[key] = value
            with self.subTest(key=key, value=value), self.assertRaises(ValueError):
                self.validate(changed)

    def test_hash_and_path_binding(self):
        for key in ("media_sha256", "firmware_sha256", "original_stdcpp_sha256"):
            changed = copy.deepcopy(self.report)
            changed[key] = "0" * 64
            with self.subTest(key=key), self.assertRaises(ValueError):
                self.validate(changed)
        changed = copy.deepcopy(self.report)
        changed["media"] = str(self.root / "OTHER.MP4")
        with self.assertRaises(ValueError):
            self.validate(changed)
        self.media.write_bytes(b"changed media")
        with self.assertRaises(ValueError):
            self.validate()

    def test_actual_firmware_must_match_pinned_image_not_just_report(self):
        evidence.FIRMWARE.write_bytes(b"modified firmware")
        self.report["firmware_sha256"] = evidence._sha256(evidence.FIRMWARE)
        with self.assertRaises(ValueError):
            self.validate()

    def test_original_failed_verdict_integrity_and_scope_must_be_preserved(self):
        for key, value in (("passed_selected_reader_checks", True), ("card_access", True),
                           ("root_cause_established", True),
                           ("original_executable_sections_unchanged_after_all_probes", False)):
            changed = copy.deepcopy(self.report)
            changed[key] = value
            with self.subTest(key=key), self.assertRaises(ValueError):
                self.validate(changed)
        changed = copy.deepcopy(self.report)
        changed["result"]["original_executable_sections_unchanged"] = False
        with self.assertRaises(ValueError):
            self.validate(changed)

    def test_missing_result_step_fields_and_final_step_fail_closed(self):
        for key in ("result", "steps", "active_step", "media_sha256", "firmware_sha256"):
            changed = copy.deepcopy(self.report)
            del changed[key]
            with self.subTest(missing=key), self.assertRaises(ValueError):
                self.validate(changed)
        changed = copy.deepcopy(self.report)
        changed["active_step"] = changed["steps"][4]
        with self.assertRaises(ValueError):
            self.validate(changed)
        for raw in (None, [], {}, {"result": None}):
            with self.subTest(raw=raw), self.assertRaises(ValueError):
                evidence.validate_reader_report(raw, self.media, spec())

    def cli_inputs(self):
        spec_path = self.root / "spec.json"
        spec_path.write_text(json.dumps(spec().to_dict()), encoding="utf-8")
        snapshot = self.root / "snapshot"
        snapshot.mkdir()
        (snapshot / "_snapshot.json").write_text("{}", encoding="utf-8")
        output = self.root / "reader.json"
        argv = ["--media", str(self.media), "--experiment-spec", str(spec_path),
                "--snapshot", str(snapshot), "--output", str(output)]
        return argv, output

    def test_cli_accepts_exact_rejection_exit_one_and_preserves_original_bytes(self):
        argv, output = self.cli_inputs()
        original = json.dumps(self.report, separators=(",", ":")).encode("utf-8")

        def run(command, **kwargs):
            output.write_bytes(original)
            self.assertEqual(command[command.index("--seek-mode") + 1], "1")
            self.assertEqual(command[command.index("--sample-batches") + 1], "1")
            self.assertEqual(command[command.index("--max-runtime-seconds") + 1], "180")
            for flag in ("--seek-probe", "--decode-table-probe", "--rtmd-probe"):
                self.assertIn(flag, command)
            self.assertEqual(kwargs["timeout"], 210)
            return subprocess.CompletedProcess(command, 1)

        with patch.object(evidence.subprocess, "run", side_effect=run), redirect_stdout(io.StringIO()):
            self.assertEqual(evidence.main(argv), 0)
        self.assertEqual(output.read_bytes(), original)
        assessment = json.loads(output.with_name("reader.assessment.json").read_text())
        self.assertTrue(assessment["expected_rejection"])
        self.assertEqual(assessment["requested_probe_mode"]["seek_mode"], 1)

    def test_cli_does_not_accept_unexpected_process_exit(self):
        argv, output = self.cli_inputs()

        def run(command, **kwargs):
            output.write_text(json.dumps(self.report), encoding="utf-8")
            return subprocess.CompletedProcess(command, 2)

        with patch.object(evidence.subprocess, "run", side_effect=run), redirect_stderr(io.StringIO()):
            self.assertEqual(evidence.main(argv), 1)
        self.assertFalse(output.with_name("reader.assessment.json").exists())

    def test_cli_timeout_never_accepts_a_partial_or_stale_report(self):
        argv, output = self.cli_inputs()
        with patch.object(evidence.subprocess, "run", side_effect=subprocess.TimeoutExpired("reader", 210)), \
                redirect_stderr(io.StringIO()):
            self.assertEqual(evidence.main(argv), 1)
        output.write_text(json.dumps(self.report), encoding="utf-8")
        with patch.object(evidence.subprocess, "run") as run, redirect_stderr(io.StringIO()):
            self.assertEqual(evidence.main(argv), 1)
            run.assert_not_called()

    def test_card_path_is_rejected_before_io(self):
        with patch.object(Path, "resolve", side_effect=AssertionError("No card access")):
            with self.assertRaisesRegex(ValueError, "Card paths"):
                evidence.validate_reader_report(self.report, "F:/PRIVATE/M4ROOT/CLIP/X.MP4", spec())


SAVED_REPORT = ROOT / "output/profiles-0028-hd16-2997/package/firmware-reader.json"
SAVED_MEDIA = SAVED_REPORT.parent / "C6520.MP4"
AVAILABLE = (SAVED_REPORT.is_file() and SAVED_MEDIA.is_file() and evidence.FIRMWARE.is_file() and
             all(importlib.util.find_spec(x) for x in ("unicorn", "elftools")))


@unittest.skipUnless(AVAILABLE, "Requires saved offline reader report, media and probe dependencies")
class SuccessfulEvidenceTests(unittest.TestCase):
    def setUp(self):
        self.report = json.loads(SAVED_REPORT.read_text(encoding="utf-8"))

    def validate(self, report=None):
        return evidence.validate_reader_report(
            self.report if report is None else report, SAVED_MEDIA, spec(variant="A"))

    def test_real_original_success_report_validates_directly_without_wrapper(self):
        original = copy.deepcopy(self.report)
        assessment = self.validate()
        self.assertTrue(assessment["passed"])
        self.assertFalse(assessment["expected_rejection"])
        self.assertEqual(assessment["probe_mode"], evidence.PROBE_MODE)
        self.assertEqual(assessment["video_frames_checked"], 1)
        self.assertEqual(assessment["total_video_frames"], 767)
        self.assertFalse(assessment["full_stream_decode"])
        self.assertFalse(assessment["camera_playback_proven"])
        self.assertEqual(self.report, original)

    def test_success_is_not_accepted_in_place_of_expected_rejection(self):
        with self.assertRaises(ValueError):
            evidence.validate_reader_report(self.report, SAVED_MEDIA, spec())

    def test_missing_probe_steps_or_wrong_status_never_pass(self):
        for index, row in enumerate(self.report["steps"]):
            changed = copy.deepcopy(self.report)
            del changed["steps"][index]
            with self.subTest(missing=row["label"]), self.assertRaises(ValueError):
                self.validate(changed)
            if row["return_u32"] is not None:
                changed = copy.deepcopy(self.report)
                changed["steps"][index]["return_u32"] = 3
                with self.subTest(status=row["label"]), self.assertRaises(ValueError):
                    self.validate(changed)

    def test_success_requires_all_probe_sections_and_original_true_verdict(self):
        for key in ("sample_index_crosscheck", "rtmd_probe"):
            changed = copy.deepcopy(self.report)
            del changed[key]
            with self.subTest(missing=key), self.assertRaises(ValueError):
                self.validate(changed)
        for key in ("selected_seek_probe", "sample_probe"):
            changed = copy.deepcopy(self.report)
            changed["result"][key] = None
            with self.subTest(missing=key), self.assertRaises(ValueError):
                self.validate(changed)
        changed = copy.deepcopy(self.report)
        changed["passed_selected_reader_checks"] = False
        with self.assertRaises(ValueError):
            self.validate(changed)

    def test_seek_mode_and_parameters_are_both_bound(self):
        for key, value in (("mode", 0), ("return_u32", 3), ("parameter_hex", "00" * 24)):
            changed = copy.deepcopy(self.report)
            changed["result"]["selected_seek_probe"][key] = value
            with self.subTest(key=key), self.assertRaises(ValueError):
                self.validate(changed)

    def test_independent_oracle_is_recomputed_not_trusted(self):
        changed = copy.deepcopy(self.report)
        probe = changed["result"]["sample_probe"]
        raw = bytearray.fromhex(probe["batches"][0]["video_rows"][0])
        raw[8] ^= 1
        probe["batches"][0]["video_rows"][0] = raw.hex()
        with self.assertRaisesRegex(ValueError, "Independent sample/table"):
            self.validate(changed)
        changed = copy.deepcopy(self.report)
        changed["sample_index_crosscheck"]["checks"] = {}
        with self.assertRaises(ValueError):
            self.validate(changed)

    def test_empty_or_incomplete_tables_and_batches_fail(self):
        for field, value in (("conversions", []), ("tables", []), ("parameter_sets", [])):
            changed = copy.deepcopy(self.report)
            changed["result"]["sample_probe"]["batches"][0]["decode_table_probe"][field] = value
            with self.subTest(field=field), self.assertRaises(ValueError):
                self.validate(changed)
        changed = copy.deepcopy(self.report)
        changed["result"]["sample_probe"]["batches"] = []
        with self.assertRaises(ValueError):
            self.validate(changed)

    def test_rtmd_hash_first_second_last_status_and_timecode_consistency(self):
        for key, value in (("frame_index", 2), ("sample_sha256", "0" * 64),
                           ("sample_size", 1), ("transit_return_u32", 3),
                           ("basic_query_return_u32", 3), ("table_conversion_return_u32", 3),
                           ("basic_timecode_present", False), ("table_count", 0),
                           ("basic_timecode_item_hex", "00" * 16)):
            changed = copy.deepcopy(self.report)
            changed["rtmd_probe"]["packets"][1][key] = value
            with self.subTest(field=key), self.assertRaises(ValueError):
                self.validate(changed)
        changed = copy.deepcopy(self.report)
        changed["rtmd_probe"]["packets"].pop()
        with self.assertRaises(ValueError):
            self.validate(changed)


ROUND_CASES = (("C6521", "29-A", 0, 767), ("C6522", "29-B", 3, None),
               ("C6523", "59-A", 0, 1534), ("C6524", "59-B", 0, 1534))
ROUND_AVAILABLE = AVAILABLE and all(
    (ROOT / "analysis" / ("0029-reader-" + clip + ".json")).is_file() and
    (ROOT / "analysis" / ("0029-" + suffix + ".json")).is_file() and
    (ROOT / "output" / ("bitrate-0029-" + suffix[:2]) / suffix[-1] / (clip + ".MP4")).is_file()
    for clip, suffix, _, _ in ROUND_CASES)


@unittest.skipUnless(ROUND_AVAILABLE, "Requires four saved round-0029 raw reports and local media")
class ActualRoundEvidenceTests(unittest.TestCase):
    def test_four_original_reports_validate_unmodified_with_bounded_video_scope(self):
        for clip, suffix, status, total_frames in ROUND_CASES:
            with self.subTest(clip=clip):
                path = ROOT / "analysis" / ("0029-reader-" + clip + ".json")
                original_bytes = path.read_bytes()
                report = json.loads(original_bytes)
                original = copy.deepcopy(report)
                selected = evidence.load_spec(ROOT / "analysis" / ("0029-" + suffix + ".json"))
                assessment = evidence.validate_reader_report(report, report["media"], selected)
                self.assertTrue(assessment["passed"])
                self.assertEqual(assessment["expected_query_status"], status)
                self.assertEqual(assessment["expected_rejection"], status == 3)
                self.assertIs(report["passed_selected_reader_checks"], status == 0)
                if status == 0:
                    self.assertEqual(assessment["video_frames_checked"], 1)
                    self.assertEqual(assessment["total_video_frames"], total_frames)
                    self.assertFalse(assessment["full_stream_decode"])
                    self.assertFalse(assessment["camera_playback_proven"])
                    self.assertEqual(assessment["rtmd_frame_indices"], [0, 1, total_frames - 1])
                else:
                    self.assertEqual(len(report["steps"]), 6)
                    self.assertIsNone(assessment["probe_mode"])
                    self.assertNotIn("video_frames_checked", assessment)
                self.assertEqual(report, original)
                self.assertEqual(path.read_bytes(), original_bytes)


if __name__ == "__main__":
    unittest.main()
