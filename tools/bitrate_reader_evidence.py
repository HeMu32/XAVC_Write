"""Validate original, unmodified reader evidence for the bounded 4M diagnostic.

Usage: python tools/bitrate_reader_evidence.py --media LOCAL.MP4
    --experiment-spec SPEC.json --snapshot SNAP --output ORIGINAL.json
Design: preserve the emulator JSON verbatim; write ORIGINAL.assessment.json
    separately. Only hd16_2997/B expects property-query status 3.
Scope: offline selected parser probes, never camera playback or admission.
"""
import argparse
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path, PureWindowsPath

from bitrate_experiment import ExperimentSpec, load_spec

ROOT = Path(__file__).resolve().parents[1]
FIRMWARE = ROOT / "firmware/m4-v602/usr/lib/libmpr.so"
RUNTIME = FIRMWARE.parent / "libstdc++.so.6.0.22"
# The original emulator admits this exact libmpr image.
FIRMWARE_SHA256 = "1a7a8007828810f948eb4fb95b9a269176355553a69977f6d8f2ae59516f5532"
ENTRIES = {
    "file_object_constructor": 0x22a730, "reader_constructor": 0x222994,
    "file_buffer_setup": 0x22a774, "readonly_file_open": 0x22af44,
    "original_mp4_open": 0x22a380, "original_movie_property_query": 0x228fa8,
    "selected_start_position_probe": 0x227714, "presentation_query": 0x228170,
    "video_sample_query": 0x226d20, "audio_sample_query": 0x228bf0,
    "metadata_sample_query": 0x22843c, "outband_buffer_constructor": 0x107904,
    "outband_list_constructor": 0xfb22c, "original_parameter_set_preparation": 0x11075c,
    "parameter_list_item": 0xfb388, "original_video_config_table": 0x10c998,
    "original_video_frame_table": 0x10c4a4, "rtmd_parser_constructor": 0x1a39d8,
    "timecode_converter_constructor": 0x1a5684, "rtmd_transit_to_query": 0x1a3b28,
    "rtmd_basic_timecode_query": 0x1a3a24, "original_metadata_decode_table": 0x10c550,
}
OPEN_STEPS = list(ENTRIES)[:6]
PROBE_MODE = {"seek_probe": True, "seek_mode": 1, "sample_batches": 1,
              "decode_table_probe": True, "rtmd_probe": True}


def _require(condition, message):
    if not condition:
        raise ValueError(message)


def _offline(path):
    _require(PureWindowsPath(str(path)).drive.upper() != "F:", "Card paths are forbidden")
    resolved = Path(path).resolve()
    _require(resolved.drive.upper() != "F:", "Card paths are forbidden")
    return resolved


def _sha256(path):
    with _offline(path).open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def _zero(value, label):
    _require(type(value) is int and value == 0, label + " must return status 0")


def _hex(text, size, label):
    _require(isinstance(text, str), label + " must be hex")
    raw = bytes.fromhex(text)
    _require(len(raw) == size, label + " has wrong size")
    return raw


def _success_evidence(report, media):
    """Recompute the existing independent oracle rather than trust its verdict."""
    from emulate_xavc_reader import audio_gate, validate_sample_probe
    from sony_mp4 import MP4

    result = report["result"]
    seek = result["selected_seek_probe"]
    _zero(seek["return_u32"], "seek")
    for key, value in (("time_90khz", 90000), ("mode", 1), ("direction", 0), ("flags", 0)):
        _require(type(seek[key]) is int and seek[key] == value, "Wrong seek " + key)
    _require(seek["physical_camera_parameters_observed"] is False, "Incorrect seek scope")
    _require(_hex(seek["parameter_hex"], 24, "seek parameters") ==
             struct.pack("<QIIII", 90000, 1, 0, 0, 0), "Seek parameters disagree")
    properties = _hex(result["movie_property_hex"], 0x60, "movie properties")
    _require(result["audio_gate"] == audio_gate(properties) and
             result["audio_gate"]["accepted_by_literal_property_predicate"] is True,
             "Audio predicate failed or disagrees with properties")
    probe = result["sample_probe"]
    _zero(probe["return_u32"], "sample probe")
    batches = probe["batches"]
    _require(isinstance(batches, list) and len(batches) == 1, "Require one completed sample batch")
    batch = batches[0]
    _require(batch["batch"] == 0 and type(batch["batch"]) is int, "Wrong sample batch index")
    for count_key, rows_key, row_size in (("video_count", "video_rows", 64),
                                         ("metadata_count", "metadata_rows", 24)):
        rows, count = batch[rows_key], batch[count_key]
        _require(type(count) is int and 0 < count <= 240 and len(rows) == count,
                 "Empty or inconsistent " + rows_key)
        for row in rows:
            _hex(row, row_size, rows_key)
    audio = batch["audio"]
    _require(isinstance(audio, list) and 1 <= len(audio) <= 8, "Missing audio queries")
    for item in audio:
        _zero(item["return_u32"], "audio query")
        _require(type(item["count"]) is int and 0 <= item["count"] <= 240 and
                 item["count"] == len(item["rows"]), "Inconsistent audio rows")
        for row in item["rows"]:
            _hex(row, 32, "audio row")
    tables = batch["decode_table_probe"]
    _zero(tables["parameter_preparation_return_u32"], "parameter preparation")
    _require(0 < len(tables["parameter_sets"]) <= 256, "Missing parameter sets")
    for parameter in tables["parameter_sets"]:
        _require(type(parameter["size"]) is int and parameter["size"] >= 0,
                 "Invalid parameter size")
        _hex(parameter["hex"], parameter["size"], "parameter set")
    _require(len(tables["conversions"]) == batch["video_count"], "Incomplete table conversions")
    for row in tables["conversions"]:
        _zero(row["config_return_u32"], "config conversion")
        _zero(row["frame_return_u32"], "frame conversion")
    _require(type(tables["table_count"]) is int and
             0 < tables["table_count"] <= 240 and
             tables["table_count"] == len(tables["tables"]), "Inconsistent decode tables")
    for row in tables["tables"]:
        _hex(row, 64, "decode table")
    crosscheck = validate_sample_probe(media, probe)
    _require(crosscheck["passed"] is True and
             all(value is True for value in crosscheck["checks"].values()),
             "Independent sample/table comparison failed")
    _require(report["sample_index_crosscheck"] == crosscheck,
             "Saved independent sample comparison is missing, stale or inconsistent")

    packets = report["rtmd_probe"]["packets"]
    source = MP4(media)
    try:
        track = next(t for t in source.tracks if t.handler == "meta")
        count = len(track.sizes)
        _require(count > 0, "No metadata samples")
        selected = sorted({0, min(1, count - 1), count - 1})
        _require([row["frame_index"] for row in packets] == selected,
                 "RTMD must cover first, second and last packets")
        for row, number in zip(packets, selected):
            _require(type(row["frame_index"]) is int, "Invalid RTMD frame index")
            sample = track.sample(number)
            _require(row["sample_sha256"] == hashlib.sha256(sample).hexdigest() and
                     type(row["sample_size"]) is int and row["sample_size"] == len(sample),
                     "RTMD sample hash/size does not match media")
            for key in ("transit_return_u32", "basic_query_return_u32",
                        "table_conversion_return_u32"):
                _zero(row[key], "RTMD " + key)
            _require(row["basic_timecode_present"] is True and
                     type(row["table_count"]) is int and row["table_count"] == 1,
                     "RTMD timecode/table missing")
            item = _hex(row["basic_timecode_item_hex"], 16, "RTMD timecode")
            table = _hex(row["table_hex"], 0x500, "RTMD table")
            _require(item[8:12] == table[0x40:0x44], "RTMD table/timecode disagree")
    finally:
        source.close()

    labels = OPEN_STEPS + ["selected_start_position_probe", "presentation_query",
                           "video_sample_query"] + ["audio_sample_query"] * len(audio)
    labels += ["metadata_sample_query", "outband_buffer_constructor",
               "outband_list_constructor", "original_parameter_set_preparation"]
    labels += ["parameter_list_item"] * len(tables["parameter_sets"])
    labels += ["original_video_config_table", "original_video_frame_table"] * batch["video_count"]
    labels += ["rtmd_parser_constructor", "timecode_converter_constructor"]
    labels += ["rtmd_transit_to_query", "rtmd_basic_timecode_query",
               "original_metadata_decode_table"] * len(packets)
    return labels


def validate_reader_report(report, media_path, spec):
    """Return a separate assessment or raise ValueError; never mutate raw evidence.

    Accepts the original emulate_xavc_reader JSON, not a wrapper/waiver.
    Probe settings on expected early rejection are unobservable, not assumed.
    """
    try:
        spec = ExperimentSpec.from_dict(spec if isinstance(spec, dict) else spec.to_dict())
        expected = spec.expected_reader_status
        media = _offline(media_path)
        _require(isinstance(report, dict), "Reader report must be an object")
        _require(not any(key in report for key in
                        ("emulation_error", "error_kind", "partial_sample_batches_not_complete",
                         "guest_registers_at_failure")), "Emulator errors/timeouts are not rejection evidence")
        _require(report["card_access"] is False and report["root_cause_established"] is False,
                 "Invalid offline probe scope")
        _require(_offline(report["media"]) == media, "Report media path mismatch")
        _require(report["media_sha256"] == _sha256(media), "Report media SHA256 mismatch")
        firmware_hash = _sha256(FIRMWARE)
        _require(firmware_hash == FIRMWARE_SHA256 == report["firmware_sha256"],
                 "Report/actual firmware SHA256 mismatch")
        _require(report["original_stdcpp_sha256"] == _sha256(RUNTIME), "Runtime SHA256 mismatch")
        result = report["result"]
        _require(type(result["last_status_u32"]) is int and result["last_status_u32"] == expected,
                 "Unexpected original movie property query status")
        _require(result["original_executable_sections_unchanged"] is True and
                 report["original_executable_sections_unchanged_after_all_probes"] is True,
                 "Executable code changed or integrity evidence missing")
        _require(report["passed_selected_reader_checks"] is (expected == 0),
                 "Original selected-reader verdict must remain unchanged")
        if expected == 3:
            _require(all(result[key] is None for key in
                         ("selected_seek_probe", "sample_probe", "audio_gate")),
                     "Rejected property query must not have downstream probes")
            _require("rtmd_probe" not in report and "sample_index_crosscheck" not in report,
                     "Unexpected downstream evidence after property rejection")
            labels = OPEN_STEPS
        else:
            labels = _success_evidence(report, media)
        steps = report["steps"]
        _require(isinstance(steps, list) and [row["label"] for row in steps] == labels,
                 "Missing, duplicated, out-of-order or unexpected reader steps")
        for row, label in zip(steps, labels):
            _require(row["entry_elf_vma"] == hex(ENTRIES[label]), "Wrong ELF entry for " + label)
            constructor = label.endswith("_constructor")
            _require(row["void_return_ignored"] is constructor, "Wrong void/status type for " + label)
            if constructor:
                _require(row["return_u32"] is None, "Constructor must have an ignored void return")
            else:
                wanted = expected if label == "original_movie_property_query" else 0
                _require(type(row["return_u32"]) is int and row["return_u32"] == wanted,
                         "Wrong status at " + label)
        _require(report["active_step"] == {key: steps[-1][key] for key in
                                          ("label", "entry_elf_vma")}, "Incomplete final reader step")
        assessment = {
            "passed": True, "expected_rejection": expected == 3,
            "expected_query_status": expected, "media_sha256": report["media_sha256"],
            "firmware_sha256": firmware_hash, "experiment_spec": spec.to_dict(),
            "probe_mode": dict(PROBE_MODE) if expected == 0 else None,
            "probe_mode_observed": expected == 0,
            "scope": ("Original property-query rejection only; downstream probes not reached"
                      if expected else "Selected original reader probes; not camera playback"),
            "checks": {"media_hash_bound": True, "firmware_hash_bound": True,
                       "runtime_hash_bound": True, "original_code_unchanged": True,
                       "exact_call_sequence_and_statuses": True, "no_emulator_errors": True,
                       "original_reader_verdict_preserved": True},
        }
        if expected == 0:
            assessment["checks"].update({
                "independent_sample_table_crosscheck": True,
                "rtmd_first_second_last_consistent": True, "probe_mode_bound": True})
            assessment["rtmd_frame_indices"] = [
                row["frame_index"] for row in report["rtmd_probe"]["packets"]]
            assessment["video_frames_checked"] = report["sample_index_crosscheck"]["video_frames_checked"]
            assessment["total_video_frames"] = report["sample_index_crosscheck"]["total_video_frames"]
            assessment["full_stream_decode"] = False
            assessment["camera_playback_proven"] = False
            assessment["scope"] = (
                f"Selected original reader probes: {assessment['video_frames_checked']} of "
                f"{assessment['total_video_frames']} video samples checked; "
                "no full-stream decode or camera playback")
        else:
            assessment["checks"]["exact_expected_property_rejection"] = True
        return assessment
    except ValueError:
        raise
    except (KeyError, TypeError, AttributeError, IndexError, OSError, StopIteration, struct.error,
            OverflowError) as error:
        raise ValueError("Invalid or incomplete original reader report: " + str(error)) from error


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--media", required=True)
    parser.add_argument("--experiment-spec", required=True)
    parser.add_argument("--snapshot", required=True)
    parser.add_argument("--output", help="Original reader JSON; defaults to MEDIA-reader.json")
    args = parser.parse_args(argv)
    try:
        media, spec_path, snapshot = map(_offline, (args.media, args.experiment_spec, args.snapshot))
        output = _offline(args.output or media.with_name(media.stem + "-reader.json"))
        assessment_path = output.with_name(output.stem + ".assessment.json")
        _require((snapshot / "_snapshot.json").is_file(), "Require a saved offline snapshot")
        _require(snapshot not in output.parents and output != snapshot,
                 "Output must be outside the saved snapshot")
        _require(output not in (media, spec_path) and assessment_path not in (media, spec_path),
                 "Output would overwrite an input")
        _require(not output.exists() and not assessment_path.exists(), "Evidence output already exists")
        spec = load_spec(spec_path)
        command = [sys.executable, str(ROOT / "tools/emulate_xavc_reader.py"), str(media),
                   "--snapshot", str(snapshot), "--output", str(output),
                   "--seek-probe", "--seek-mode", "1", "--sample-batches", "1",
                   "--decode-table-probe", "--rtmd-probe", "--max-runtime-seconds", "180"]
        completed = subprocess.run(command, cwd=ROOT, timeout=210, check=False)
        _require(output.is_file(), "Emulator did not write an original report")
        report = json.loads(output.read_text(encoding="utf-8"))
        assessment = validate_reader_report(report, media, spec)
        _require(completed.returncode == (1 if assessment["expected_rejection"] else 0),
                 "Unexpected emulator process exit status")
        assessment["requested_probe_mode"] = dict(PROBE_MODE, max_runtime_seconds=180)
        assessment["original_report"] = str(output)
        assessment["original_report_sha256"] = _sha256(output)
        assessment_path.write_text(json.dumps(assessment, indent=2) + "\n", encoding="utf-8")
        print(json.dumps(assessment, indent=2))
        return 0
    except (ValueError, OSError, subprocess.TimeoutExpired) as error:
        print("Reader evidence failed: " + str(error), file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
