"""Purpose: audit a 3-byte/4-byte AVC NAL-length reframing experiment.

Usage: python tools/compare_nal_reframe.py BEFORE.MP4 AFTER.MP4
    --output REPORT.json.
Design: parse each file's declared framing and compare complete ordered NALs,
    sample boundaries and associated container invariants.
Scope: read-only comparison, not a rewriter or proof that either framing plays
    on the camera. Only the supported local MP4 track layouts are modeled.
"""
import argparse
import hashlib
import json
from pathlib import Path

from avc_hrd import nals
from sony_mp4 import ConstantSizes, MP4
from sony_verification import digest, track_payload_hash


def sample_sizes_equal(left, right):
    if len(left) != len(right):
        return False
    if isinstance(left, ConstantSizes) and isinstance(right, ConstantSizes):
        return left.size == right.size
    return all(a == b for a, b in zip(left, right))


def compare(before, after):
    a, b = MP4(before), MP4(after)
    try:
        av, bv = a.tracks[0], b.tracks[0]
        old, new = av.avcc(), bv.avcc()
        widths = [(x[4] & 3) + 1 for x in (old, new)]
        checks = {
            "three_track_layouts_match": (
                [(t.handler, t.codec) for t in a.tracks] ==
                [(t.handler, t.codec) for t in b.tracks] ==
                [("vide", "avc1"), ("soun", "twos"), ("meta", "rtmd")]),
            "avcc_identical_except_declared_length_width": (
                old[:4] + bytes([old[4] & 0xfc]) + old[5:] ==
                new[:4] + bytes([new[4] & 0xfc]) + new[5:]),
            "all_track_counts_cadence_composition_sync_and_duration_match": (
                [(t.timescale, t.duration, len(t.sizes), t.stts, t.ctts, t.sync)
                 for t in a.tracks] ==
                [(t.timescale, t.duration, len(t.sizes), t.stts, t.ctts, t.sync)
                 for t in b.tracks]),
            "audio_and_metadata_payloads_exact": len(a.tracks) == len(b.tracks) == 3 and all(
                track_payload_hash(x) == track_payload_hash(y) and a.raw(x.entry) == b.raw(y.entry)
                for x, y in zip(a.tracks[1:], b.tracks[1:])),
            "audio_and_metadata_sample_boundaries_exact": len(a.tracks) == len(b.tracks) == 3 and all(
                sample_sizes_equal(x.sizes, y.sizes)
                for x, y in zip(a.tracks[1:], b.tracks[1:])),
        }
        counts, sample_delta = 0, 0
        canonical = hashlib.sha256()
        nal_equal = len(av.sizes) == len(bv.sizes) > 0
        if nal_equal:
            for i in range(len(av.sizes)):
                left, right = nals(av.sample(i), widths[0]), nals(bv.sample(i), widths[1])
                nal_equal &= left == right
                sample_delta += bv.sizes[i] - av.sizes[i]
                counts += len(left)
                if bv.sizes[i] - av.sizes[i] != (widths[1] - widths[0]) * len(left):
                    nal_equal = False
                for unit in left:
                    canonical.update(len(unit).to_bytes(4, "big") + unit)
        checks["every_sample_ordered_nals_exact_including_all_sei"] = nal_equal
        checks["sample_size_delta_exactly_matches_nal_prefix_change"] = (
            sample_delta == (widths[1] - widths[0]) * counts)
        return {
            "before": str(Path(before).resolve()), "after": str(Path(after).resolve()),
            "before_sha256": digest(before), "after_sha256": digest(after),
            "checks": checks, "passed": all(checks.values()), "nal_count": counts,
            "samples": len(av.sizes), "nal_length_widths": widths,
            "video_sample_bytes_delta": sample_delta,
            "canonical_four_byte_video_stream_sha256": canonical.hexdigest(),
            "scope": "Complete local payload/index comparison, not hardware acceptance",
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
