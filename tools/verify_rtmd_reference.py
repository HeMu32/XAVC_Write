"""Purpose: compare generated minimal RTMD with every packet in a reference.

Usage: python tools/verify_rtmd_reference.py REFERENCE.MP4
    --profile hd25_5994 --output REPORT.json.
Design: select the explicit half-step/profile model, regenerate packets from
    the observed seed/start time and compare all indexed bytes with provenance.
Scope: supported measured reference templates only. Exact packet equality does
    not recover all opaque semantics or establish camera playback.
"""
import argparse
import hashlib
import json
from pathlib import Path

from sony_mp4 import MP4
from sony_rtmd import make_packet


# Local cadence mapping keeps this verifier independent of builder profile setup.
PROFILE_HALF_STEP = {"hd25_5994": True, "hd50_5994": True, "uhd60_2997": False}
TIMECODE_OFFSETS = frozenset(range(13, 18)) | frozenset(range(20, 24))


def verify_reference(reference, profile="hd25_5994"):
    half_step = PROFILE_HALF_STEP[profile]
    path = Path(reference).resolve()
    stat = path.stat()
    file_hash = hashlib.sha256()
    with path.open("rb") as source:
        for chunk in iter(lambda: source.read(1024 * 1024), b""):
            file_hash.update(chunk)
    media = MP4(path)
    try:
        track = next(t for t in media.tracks if t.codec == "rtmd")
        count = len(track.sizes)
        if not count:
            raise ValueError("Reference has no rtmd packets")
        template = track.sample(0)
        generated_hash, reference_hash = hashlib.sha256(), hashlib.sha256()
        mismatch_count, first_mismatches = 0, []
        varying_offsets, opaque_mismatch_count = set(), 0
        examples = []
        scale = 2 if half_step else 1
        example_frames = {0, 1, 2, 29, 30, 59, 60, count - 1}
        for boundary in [1800 * scale, 17982 * scale, 2589408 * scale]:
            example_frames.update([boundary - 1, boundary])
        for i in range(count):
            generated = make_packet(template, i, half_step=half_step)
            actual = track.sample(i)
            generated_hash.update(generated)
            reference_hash.update(actual)
            changes = {j for j, (a, b) in enumerate(zip(template, actual)) if a != b}
            varying_offsets.update(changes)
            if len(actual) != len(template) or changes - TIMECODE_OFFSETS:
                opaque_mismatch_count += 1
            if generated != actual:
                mismatch_count += 1
                if len(first_mismatches) < 20:
                    first_mismatches.append(i)
            if i in example_frames:
                examples.append({"frame": i, "reference_first32_hex": actual[:32].hex(),
                                 "generated_first32_hex": generated[:32].hex(),
                                 "reference_timecode_hex": actual[20:24].hex(),
                                 "reference_header_time_fields_hex": actual[13:18].hex()})
        return {
            "reference": str(path), "profile": profile, "half_step": half_step,
            "reference_file_sha256": file_hash.hexdigest(),
            "reference_stat": {"size": stat.st_size, "mtime_ns": stat.st_mtime_ns,
                               "ctime_ns": stat.st_ctime_ns},
            "samples": count, "packet_sizes": sorted(set(track.sizes)),
            "track": {"timescale": track.timescale, "duration": track.duration,
                      "duration_seconds": track.duration / track.timescale,
                      "stts": track.stts},
            "template_sha256": hashlib.sha256(template).hexdigest(),
            "template_start_timecode_hex": template[20:24].hex(),
            "reference_end_timecode_hex": track.sample(count - 1)[20:24].hex(),
            "template_start_header_time_fields_hex": template[13:18].hex(),
            "mismatch_count": mismatch_count, "first_mismatches": first_mismatches,
            "generated_sha256": generated_hash.hexdigest(),
            "reference_sha256": reference_hash.hexdigest(),
            "observed_varying_offsets": sorted(varying_offsets),
            "rewritten_offsets": sorted(TIMECODE_OFFSETS),
            "opaque_mismatch_count": opaque_mismatch_count,
            "examples": examples,
            "limitations": [
                "All rtmd packets in this local reference were compared, not video or audio payloads.",
                "Opaque bytes are copied from sample zero; their semantics and validity are not established.",
                "Profile selects timecode cadence only, not bitrate or complete profile conformance.",
                "29.97p retains the template starting timecode; default 59.94p requires a zero start.",
                f"This comparison spans {count} packets "
                f"({track.duration / track.timescale:g} seconds); only transitions "
                "inside the measured starting/ending timecode interval are reference evidence.",
                "Unobserved boundaries are covered by synthetic unit tests, not reference evidence.",
                "Byte equality to these EDIUS references does not establish full rtmd validity "
                "or successful camera playback; no card was accessed."
            ]
        }
    finally:
        media.close()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("reference")
    ap.add_argument("--profile", choices=tuple(PROFILE_HALF_STEP), default="hd25_5994")
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    report = verify_reference(args.reference, args.profile)
    path = Path(args.output)
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps(report, indent=2))
    if report["mismatch_count"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
