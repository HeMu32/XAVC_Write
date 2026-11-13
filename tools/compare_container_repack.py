"""Purpose: compare payloads and timing before and after a container repack.

Usage: python tools/compare_container_repack.py BEFORE.MP4 AFTER.MP4
    --output REPORT.json.
Design: independently walk track sample indexes and compare descriptions,
    indexed bytes and timing tables despite changed physical placement.
Scope: read-only analysis of the supported MP4 layouts. Preserved samples are
    not equivalent to identical files or proven camera compatibility.
"""
import argparse
import json
from pathlib import Path

from sony_mp4 import MP4
from sony_verification import digest, native_payload_checks


def compare(before, after):
    a, b = MP4(before), MP4(after)
    try:
        payload = native_payload_checks(before, after, "repack")
        checks = {
            "all_indexed_track_payloads_identical": payload["repack_track_payloads_bit_exact"],
            "mdat_box_bytes_identical_at_new_position": payload["repack_mdat_bit_exact"],
            "track_types_codecs_durations_and_timing_identical": (
                [(t.handler, t.codec, t.timescale, t.duration, len(t.sizes),
                  t.stts, t.ctts, t.sync) for t in a.tracks] ==
                [(t.handler, t.codec, t.timescale, t.duration, len(t.sizes),
                  t.stts, t.ctts, t.sync) for t in b.tracks]),
            "sample_descriptions_identical": [a.raw(t.entry) for t in a.tracks] ==
                                             [b.raw(t.entry) for t in b.tracks],
        }
        return {
            "before": str(Path(before).resolve()), "after": str(Path(after).resolve()),
            "before_sha256": digest(before), "after_sha256": digest(after),
            "checks": checks, "passed": all(checks.values()),
            "absolute_sample_table_bytes_identical": payload["repack_track_configuration_bit_exact"],
            "first_payload_offsets": [m.one(m.top, "mdat").data for m in (a, b)],
            "top_level_boxes": [[{"type": x.kind, "offset": x.start, "size": x.size}
                                 for x in m.top] for m in (a, b)],
            "scope": "Offline ISO BMFF content/timing comparison, not camera acceptance",
            "camera_playback": "NOT_TESTED", "root_cause_established": False,
        }
    finally:
        a.close()
        b.close()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("before")
    parser.add_argument("after")
    parser.add_argument("--output", required=True)
    args = parser.parse_args()
    before, after, output = [Path(x).resolve() for x in (args.before, args.after, args.output)]
    if any(x.drive.upper() == "F:" for x in (before, after, output)) or output in {before, after}:
        raise ValueError("Offline inputs and separate local report required")
    report = compare(before, after)
    output.write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps(report, indent=2))
    if not report["passed"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
