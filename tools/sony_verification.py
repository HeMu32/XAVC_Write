"""Purpose: provide fresh-media checks and the shared package admission contract.

Usage: import require_current_verification, require_package_hashes and
    run_media_checks; verification/deployment CLIs call these helpers. No CLI.
Design: bind evidence to current resource hashes, reject stale/incomplete
    reports and run fresh decoder/audio/payload checks in separate run outputs.
Scope: local preparation and guarded writer admission, not physical playback
    certification. Some helpers run FFmpeg and write local verification evidence.
"""
import hashlib
import json
import subprocess
import sys
import tempfile
from pathlib import Path

SCHEMA = 5
REQUIRED_CHECKS = {"decoded_frames_and_timestamps_bit_exact", "audio_bit_exact",
                   "sei_container_timing", "progressive_slice_order", "selected_cbr_cpb",
                   "sd_only_declared_native_catalog_changes",
                   "xml_acquisition_matches_manifest", "sd_acquisition_matches_xml",
                   "catalog_baseline_hashes_bound", "qualified_candidate_nal_framing",
                   "selected_profile_consistent"}
FRAMING_CHECKS = (REQUIRED_CHECKS - {"qualified_candidate_nal_framing"}) | {
    "explicit_diagnostic_framing_control"}
NATIVE_CHECKS = {"decoded_frames_and_timestamps_bit_exact", "audio_bit_exact",
                 "native_mdat_bit_exact", "native_track_payloads_bit_exact",
                 "native_track_configuration_bit_exact", "native_source_identity_verified",
                 "sd_only_declared_native_catalog_changes",
                 "xml_acquisition_matches_manifest", "sd_acquisition_matches_xml",
                 "catalog_baseline_hashes_bound"}
SOURCE_CHECKS = (NATIVE_CHECKS - {
    "native_mdat_bit_exact", "native_track_payloads_bit_exact",
    "native_track_configuration_bit_exact", "native_source_identity_verified"}) | {
        "source_mdat_bit_exact", "source_track_payloads_bit_exact",
        "source_track_configuration_bit_exact", "source_prof_bit_exact",
        "source_playback_observation_bound", "source_identity_verified",
        "source_container_changes_limited_to_identity_and_dates",
        "source_sidecar_changes_limited_to_identity_and_dates"}


def require_current_verification(report, expected_profile="encoded_avc", expected_acquisition="unspecified",
                                 expected_catalog="native_reuse"):
    checks = report.get("checks", {})
    required = {"encoded_avc": REQUIRED_CHECKS, "native_control": NATIVE_CHECKS,
                "source_control": SOURCE_CHECKS, "framing_control": FRAMING_CHECKS}.get(expected_profile)
    if expected_catalog == "observed_minimal" and required is not None:
        required = required - {"sd_acquisition_matches_xml"} | {
            "sd_metadata_omission_matches_positive_template",
            "sd_minimal_catalog_rebuilt_exactly", "sd_positive_template_observation_bound"}
    if (report.get("verification_schema") != SCHEMA or report.get("passed") is not True or
            required is None or
            (expected_profile == "source_control" and expected_catalog != "observed_minimal") or
            expected_catalog not in {"native_reuse", "observed_minimal"} or
            report.get("catalog_representation", "native_reuse") != expected_catalog or
            report.get("verification_profile", "encoded_avc") != expected_profile or
            report.get("acquisition", "unspecified") != expected_acquisition or
            not isinstance(checks, dict) or not required.issubset(checks) or
            (expected_acquisition == "rec709" and checks.get("rec709_stream_and_acquisition_agree") is not True) or
            any(value is not True for value in checks.values())):
        raise ValueError("Package requires current full verification before writing")


def digest(path):
    with Path(path).open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def require_package_hashes(report, build, clip):
    expected = {clip + ".MP4", clip + "M01.XML", clip + "T01.JPG",
                "catalog/DATABASE.BIN", "catalog/MEDIAPRO.XML",
                "catalog/transaction.json", "build-manifest.json"}
    hashes = report.get("package_hashes")
    if not isinstance(hashes, dict) or set(hashes) != expected:
        raise ValueError("Verification must bind the complete package and transaction")
    for name, value in hashes.items():
        if digest(Path(build) / name) != value:
            raise ValueError(f"Package changed after verification: {name}")


def frame_lines(path):
    with Path(path).open(encoding="utf-8") as stream:
        return [line.strip() for line in stream if line.strip() and not line.startswith("#")]


def equal_ranges(a, start_a, b, start_b, size, block_size=1024 * 1024):
    if min(start_a, start_b, size) < 0 or block_size < 1:
        raise ValueError("Invalid comparison range")
    if start_a + size > len(a) or start_b + size > len(b):
        return False
    return all(a[start_a + p:start_a + min(p + block_size, size)] ==
               b[start_b + p:start_b + min(p + block_size, size)]
               for p in range(0, size, block_size))


def track_payload_hash(track):
    from sony_mp4 import ConstantSizes
    result = hashlib.sha256()
    first = 0
    for offset, count in zip(track.chunks, track.chunk_samples):
        size = (track.sizes.size * count if isinstance(track.sizes, ConstantSizes)
                else sum(track.sizes[first:first + count]))
        for p in range(0, size, 1024 * 1024):
            result.update(track.m.buf[offset + p:offset + min(p + 1024 * 1024, size)])
        first += count
    return result.hexdigest()


def native_payload_checks(source, target, prefix="native"):
    from sony_mp4 import MP4, ConstantSizes
    a, b = MP4(source), MP4(target)
    try:
        def signature(media, track):
            return (track.handler, track.codec, track.timescale, track.duration,
                    media.raw(track.entry),
                    {name: media.raw(item) for name, item in track.tables.items()})
        mdats_a, mdats_b = [[x for x in media.top if x.kind == "mdat"] for media in (a, b)]
        mdat_equal = len(mdats_a) == len(mdats_b) and all(
            x.size == y.size and equal_ranges(a.buf, x.start, b.buf, y.start, x.size)
            for x, y in zip(mdats_a, mdats_b))
        configuration_equal = ([signature(a, t) for t in a.tracks] ==
                               [signature(b, t) for t in b.tracks])
        same_mdat_ranges = [(x.start, x.size) for x in mdats_a] == [
            (x.start, x.size) for x in mdats_b]

        def sizes_equal(x, y):
            if len(x) != len(y):
                return False
            if isinstance(x, ConstantSizes) and isinstance(y, ConstantSizes):
                return x.size == y.size
            return all(u == v for u, v in zip(x, y))

        # Equal absolute mappings and equal mdat bytes prove every indexed payload.
        # Otherwise compare ordered chunk payloads without expanding millions of PCM samples.
        payload_equal = (mdat_equal and configuration_equal and same_mdat_ranges) or (
            len(a.tracks) == len(b.tracks) and all(
                sizes_equal(x.sizes, y.sizes) and track_payload_hash(x) == track_payload_hash(y)
                for x, y in zip(a.tracks, b.tracks)))
        return {prefix + "_mdat_bit_exact": mdat_equal,
                prefix + "_track_configuration_bit_exact": configuration_equal,
                prefix + "_track_payloads_bit_exact": payload_equal}
    finally:
        a.close()
        b.close()


def run_media_checks(build, clip, base, expected_frames, profile="encoded_avc"):
    if profile not in {"encoded_avc", "native_control", "source_control", "framing_control"}:
        raise ValueError("Unknown media verification profile")
    build, base = Path(build).resolve(), Path(base).resolve()
    media = build / (clip + ".MP4")
    root = build / "verification_runs"
    root.mkdir(exist_ok=True)
    out = Path(tempfile.mkdtemp(prefix="run-", dir=root))
    tools = Path(__file__).resolve().parent
    media_hash = digest(media)
    proof = {"directory": str(out), "media_sha256": media_hash,
             "base_sha256": digest(base), "runs": []}

    def run(command, name):
        command = [str(value) for value in command]
        log = out / (name + "-process.log")
        entry = {"command": command, "log": str(log)}
        proof["runs"].append(entry)
        try:
            with log.open("w", encoding="utf-8") as stream:
                result = subprocess.run(command, stdout=stream, stderr=subprocess.STDOUT)
            entry["exit_code"] = result.returncode
            return result.returncode == 0
        except OSError as error:
            entry["error"] = str(error)
            return False

    decoded = []
    for name, source in (("base", base), (clip, media)):
        decoded.append(run(["ffmpeg", "-hide_banner", "-v", "error", "-nostdin", "-n",
                            "-i", source, "-map", "0:v:0", "-f", "framemd5",
                            out / (name + ".framemd5")], name + "-decode"))
    frames_equal = False
    if all(decoded):
        try:
            a, b = frame_lines(out / "base.framemd5"), frame_lines(out / (clip + ".framemd5"))
            frames_equal = expected_frames > 0 and len(a) == expected_frames and a == b
        except OSError as error:
            proof["frame_error"] = str(error)
    checks = {"decoded_frames_and_timestamps_bit_exact": frames_equal}
    if profile in {"native_control", "source_control"}:
        checks.update(native_payload_checks(base, media,
                                           "source" if profile == "source_control" else "native"))
        checks["media_unchanged_during_verification"] = (
            digest(media) == media_hash and digest(base) == proof["base_sha256"])
        proof["profile"] = profile
        proof["scope"] = "Byte-preserving source control; no new AVC syntax or timing was generated"
        return checks, proof
    for tool, name, check, result_key in (
            ("check_avc_timing.py", "timing", "sei_container_timing", "passed_selected_checks"),
            ("check_avc_slice_order.py", "slice-order", "progressive_slice_order", "passed_selected_checks"),
            ("check_avc_cpb.py", "cpb", "selected_cbr_cpb", "passed_selected_cpb_checks")):
        report_path = out / (name + ".json")
        command = [sys.executable, tools / tool, media, "--output", report_path]
        if name == "cpb":
            command += ["--timing", out / "timing.json"]
        succeeded = run(command, name)
        checks[check] = False
        if succeeded:
            try:
                report = json.loads(report_path.read_text(encoding="utf-8"))
                checks[check] = report.get(result_key) is True and report.get("sha256") == media_hash
            except (OSError, ValueError) as error:
                proof[name + "_report_error"] = str(error)
    checks["media_unchanged_during_verification"] = (
        digest(media) == media_hash and digest(base) == proof["base_sha256"])
    return checks, proof
