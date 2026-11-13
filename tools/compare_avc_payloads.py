"""Purpose: audit payload preservation across a timing-only AVC revision.

Usage: python tools/compare_avc_payloads.py BEFORE.MP4 AFTER.MP4
    --output REPORT.json.
Design: compare ordered coded NALs and non-buffering-period SEI while isolating
    the buffering-period fields intentionally changed by the retimer.
Scope: read-only local comparison for the supported rewrite path; not a proof
    of whole-file equality, decoder correctness or camera playback.
"""
import argparse
import hashlib
import json
from pathlib import Path

from avc_hrd import nals, sei_messages
from sony_mp4 import MP4


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("before")
    ap.add_argument("after")
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    if Path(args.output).resolve() in {Path(args.before).resolve(), Path(args.after).resolve()}:
        raise ValueError("Report must not overwrite media")
    before, after = MP4(args.before), MP4(args.after)
    changed_bp, vcl = 0, 0
    try:
        a = next(t for t in before.tracks if t.handler == "vide")
        b = next(t for t in after.tracks if t.handler == "vide")
        if (a.avcc(), len(a.sizes), a.stts, a.ctts, a.sync, a.timescale) != (
                b.avcc(), len(b.sizes), b.stts, b.ctts, b.sync, b.timescale):
            raise ValueError("Video configuration or sample timing changed")
        length = (a.avcc()[4] & 3) + 1
        for index in range(len(a.sizes)):
            aa, bb = nals(a.sample(index), length), nals(b.sample(index), length)
            if len(aa) != len(bb):
                raise ValueError(f"NAL count changed at sample {index}")
            for old, new in zip(aa, bb):
                typ = old[0] & 31
                if old[0] != new[0]:
                    raise ValueError("NAL header changed")
                if typ != 6:
                    if old != new:
                        raise ValueError(f"Non-SEI NAL changed at sample {index}")
                    vcl += typ in {1, 2, 3, 4, 5}
                    continue
                old_messages, new_messages = sei_messages(old), sei_messages(new)
                if len(old_messages) != len(new_messages):
                    raise ValueError("SEI message count changed")
                for (old_type, old_payload), (new_type, new_payload) in zip(old_messages, new_messages):
                    if old_type != new_type:
                        raise ValueError("SEI message type changed")
                    if old_type != 0 and old_payload != new_payload:
                        raise ValueError("Non-buffering-period SEI changed")
                    changed_bp += old_type == 0 and old_payload != new_payload
        report = {"before": str(before.path.resolve()), "after": str(after.path.resolve()),
                  "samples": len(a.sizes), "identical_vcl_nals": vcl,
                  "changed_buffering_period_payloads": changed_bp,
                  "video_configuration_and_sample_timing_identical": True,
                  "all_non_sei_nals_identical": True, "non_bp_sei_payloads_identical": True,
                  "passed": True, "camera_playback": "NOT_TESTED"}
        for name, path in (("before_sha256", before.path), ("after_sha256", after.path)):
            with path.open("rb") as stream:
                report[name] = hashlib.file_digest(stream, "sha256").hexdigest()
    finally:
        before.close()
        after.close()
    output = Path(args.output)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps(report, indent=2))


if __name__ == "__main__":
    main()
