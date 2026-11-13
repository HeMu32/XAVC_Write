"""Purpose: check selected progressive AVC slice-order invariants.

Usage: python tools/check_avc_slice_order.py INPUT.MP4 --output REPORT.json.
Design: obtain FFmpeg trace_headers syntax, group parsed slices into pictures
    and test the explicitly supported ordering/coverage constraints.
Scope: local FFmpeg-based checks for modeled progressive syntax; unsupported
    cases are refused. Not firmware execution, full AVC validation or admission.
"""
import argparse
import hashlib
import json
import re
import subprocess
from collections import Counter
from pathlib import Path

from sony_mp4 import MP4

FIELD = re.compile(r"\]\s+\d+\s+([A-Za-z][A-Za-z_0-9]*)\s+[01]+\s+=\s+(-?\d+)")
REQUIRED = ("pic_width_in_mbs_minus1", "pic_height_in_map_units_minus1",
            "frame_mbs_only_flag", "num_slice_groups_minus1")


def parse_trace(lines):
    fields = {name: set() for name in REQUIRED}
    packets = []
    current = None
    for line in lines:
        if "] Packet:" in line:
            current = []
            packets.append(current)
        match = FIELD.search(line)
        if not match:
            continue
        name, raw = match.groups()
        value = int(raw)
        if name in fields:
            fields[name].add(value)
        if name == "first_mb_in_slice" and current is not None:
            current.append(value)
    return fields, packets


def evaluate(fields, packets, expected_samples):
    reasons = []
    if any(len(fields.get(name, ())) != 1 for name in REQUIRED):
        reasons.append("Requires one unambiguous value for each supported SPS/PPS field")
    if fields.get("frame_mbs_only_flag") != {1}:
        reasons.append("Only frame_mbs_only_flag=1 is supported by this check")
    if fields.get("num_slice_groups_minus1") != {0}:
        reasons.append("Only one slice group is supported by this check")
    applicable = not reasons
    limit = None
    if applicable:
        width = next(iter(fields["pic_width_in_mbs_minus1"])) + 1
        height = next(iter(fields["pic_height_in_map_units_minus1"])) + 1
        limit = width * height
    failures = []
    if applicable:
        for index, starts in enumerate(packets):
            errors = []
            if not starts:
                errors.append("No parsed VCL slice in this MP4 sample")
            elif starts[0] != 0:
                errors.append("First slice does not start at macroblock zero")
            if any(b <= a for a, b in zip(starts, starts[1:])):
                errors.append("Slice starts are not strictly increasing")
            if any(value < 0 or value >= limit for value in starts):
                errors.append("Slice start is outside the coded picture")
            if errors:
                failures.append({"sample_index": index, "starts": starts, "errors": errors})
    count_match = expected_samples > 0 and len(packets) == expected_samples
    return {"scope": "Selected inferred progressive slice-index conditions only; not full AVC conformance",
            "applicable": applicable, "unsupported_reasons": reasons,
            "coded_macroblocks": limit, "expected_samples": expected_samples,
            "parsed_packets": len(packets), "packet_count_matches": count_match,
            "slice_count_histogram": dict(sorted(Counter(map(len, packets)).items())),
            "start_patterns": [{"starts": list(pattern), "samples": count}
                               for pattern, count in Counter(map(tuple, packets)).most_common()],
            "failures": failures,
            "passed_selected_checks": applicable and count_match and not failures,
            "firmware_executed": False, "camera_playback": "NOT_TESTED"}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("input")
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    source, output = Path(args.input).resolve(), Path(args.output).resolve()
    log = output.with_suffix(".log")
    if source in (output, log) or output == log:
        raise ValueError("Input, JSON report, and trace log must be distinct")
    media = MP4(source)
    try:
        tracks = [track for track in media.tracks if track.handler == "vide"]
        if len(tracks) != 1 or tracks[0].codec != "avc1":
            raise ValueError("Requires a single avc1 video track")
        expected_samples = len(tracks[0].sizes)
    finally:
        media.close()
    command = ["ffmpeg", "-hide_banner", "-nostats", "-v", "info", "-i", str(source),
               "-map", "0:v:0", "-c:v", "copy", "-bsf:v", "trace_headers", "-f", "null", "-"]
    output.parent.mkdir(parents=True, exist_ok=True)
    with log.open("w", encoding="utf-8") as stream:
        result = subprocess.run(command, stdout=subprocess.DEVNULL, stderr=stream)
    with log.open(encoding="utf-8", errors="replace") as stream:
        fields, packets = parse_trace(stream)
    report = evaluate(fields, packets, expected_samples)
    with source.open("rb") as stream:
        digest = hashlib.file_digest(stream, "sha256").hexdigest()
    report.update(input=str(source), sha256=digest, command=command,
                  trace_log=str(log), ffmpeg_exit_code=result.returncode,
                  syntax_fields={name: sorted(values) for name, values in fields.items()})
    report["passed_selected_checks"] &= result.returncode == 0
    output.write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps({key: report[key] for key in
                      ("input", "parsed_packets", "start_patterns", "passed_selected_checks",
                       "firmware_executed", "camera_playback")}, indent=2))
    if not report["passed_selected_checks"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
