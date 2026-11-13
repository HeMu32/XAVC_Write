"""Purpose: smoke-test supported generic-input encoding and Sony packaging.

Usage: python tools/smoke_generic_encoding.py --output NEW_DIRECTORY
    --camera LOCAL_NATIVE.MP4 --edius LOCAL_EDIUS.MP4.
Design: generate local integration cases and run the encoding/normalization
    pipeline with recorded commands and decoded-frame/timing checks.
Scope: writes local experiment outputs and may read supplied references, but
    never writes card catalogs. Passing synthetic cases is not camera validation.
"""
import argparse
import hashlib
import json
import subprocess
import sys
from pathlib import Path

from encode_xavc import probe_input, source_timing
from sony_mp4 import MP4
from sony_rtmd import make_packet
from verify_sony_package import hash_audio

TOOLS = Path(__file__).resolve().parent


def run(command, log):
    with log.open("w", encoding="utf-8") as stream:
        result = subprocess.run([str(x) for x in command], stdout=stream, stderr=subprocess.STDOUT)
    if result.returncode:
        raise RuntimeError(f"exit {result.returncode}: {log}")


def frame_lines(path):
    return [x for x in path.read_text().splitlines() if not x.startswith("#")]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--output", required=True)
    ap.add_argument("--camera", default="F:/PRIVATE/M4ROOT/CLIP/C6359.MP4")
    ap.add_argument("--edius", default="F:/PRIVATE/M4ROOT/CLIP/C0007.MP4")
    args = ap.parse_args()
    root = Path(args.output).resolve()
    root.mkdir(parents=True, exist_ok=False)
    common = ["ffmpeg", "-hide_banner", "-nostdin", "-n"]
    fixtures = {
        "portrait_silent": (
            ["-f", "lavfi", "-i", "testsrc2=size=180x320:rate=25:duration=1.2",
             "-c:v", "libx264", "-preset", "ultrafast", "-bf", "0"], {}),
        "delayed_mono_nonzero_start": (
            ["-f", "lavfi", "-i", "testsrc2=size=320x180:rate=24:duration=2",
             "-f", "lavfi", "-i", "sine=frequency=1000:sample_rate=44100:duration=1",
             "-af", "asetpts=PTS+0.25/TB", "-c:v", "libx264", "-preset", "ultrafast",
             "-bf", "0", "-c:a", "pcm_s16le", "-output_ts_offset", "5"],
            {"audio_onset_seconds": 0.25, "audio_end_seconds": 1.25}),
        "short_mono": (
            ["-f", "lavfi", "-i", "testsrc2=size=320x180:rate=30:duration=1.5",
             "-f", "lavfi", "-i", "sine=frequency=1000:sample_rate=48000:duration=0.4",
             "-c:v", "libx264", "-preset", "ultrafast", "-bf", "0", "-c:a", "pcm_s16le"],
            {"audio_onset_seconds": 0, "audio_end_seconds": 0.4}),
        "vfr": (
            ["-f", "lavfi", "-i", "testsrc2=size=320x180:rate=30:duration=1.5",
             "-vf", "select=not(eq(mod(n\\,3)\\,1))",
             "-fps_mode", "vfr", "-c:v", "libx264", "-preset", "ultrafast", "-bf", "0"], {}),
        "interlaced_sd": (
            ["-f", "lavfi", "-i", "testsrc2=size=720x480:rate=60000/1001:duration=1.5",
             "-vf", "tinterlace=mode=interleave_top,setsar=8/9", "-flags", "+ilme+ildct",
             "-c:v", "mpeg2video", "-b:v", "8M", "-color_range", "tv",
             "-colorspace", "smpte170m", "-color_primaries", "smpte170m",
             "-color_trc", "smpte170m"], {}),
        "rgb_silent": (
            ["-f", "lavfi", "-i", "testsrc=size=320x180:rate=25:duration=1",
             "-c:v", "qtrle", "-pix_fmt", "rgb24"], {}),
    }
    report = {"card_writes": False, "camera_playback": "NOT_TESTED", "cases": {}}
    for name, (options, expected) in fixtures.items():
        case = root / name
        case.mkdir()
        source = case / "source.mov"
        command = common + options + [source]
        (case / "fixture-command.json").write_text(json.dumps(list(map(str, command)), indent=2))
        run(command, case / "fixture.log")
        output = case / "package"
        run([sys.executable, TOOLS / "encode_xavc.py", source, "--output", output],
            case / "encode-driver.log")
        run([sys.executable, TOOLS / "build_sony_clip.py", "--base", output / "base.mov",
             "--output", output, "--camera", args.camera, "--edius", args.edius, "--clip", "C9999"],
            case / "package.log")
        for stem, media in [("base", output / "base.mov"), ("C9999", output / "C9999.MP4")]:
            run(common + ["-v", "error", "-i", media, "-map", "0:v:0", "-f", "framemd5",
                          output / (stem + ".framemd5")], case / (stem + "-decode.log"))
        run(common + ["-v", "error", "-i", output / "C9999.MP4", "-map", "0:v:0",
                      "-c:v", "copy", "-bsf:v", "trace_headers", "-f", "null", "-"],
            case / "syntax-errors.log")
        for tool, stem in [("check_avc_timing.py", "timing"),
                           ("check_avc_slice_order.py", "slice-order")]:
            run([sys.executable, TOOLS / tool, output / "C9999.MP4",
                 "--output", case / (stem + ".json")], case / (stem + "-check.log"))
        run([sys.executable, TOOLS / "check_avc_cpb.py", output / "C9999.MP4",
             "--timing", case / "timing.json", "--output", case / "cpb.json"],
            case / "cpb-check.log")
        media, base = MP4(output / "C9999.MP4"), MP4(output / "base.mov")
        info = json.loads((output / "build-manifest.json").read_text())
        encoded = probe_input(output / "C9999.MP4")
        v = encoded["streams"][0]
        a, rt = media.tracks[1:]
        checks = {
            "decode_hashes_and_timestamps": frame_lines(output / "base.framemd5") ==
                                          frame_lines(output / "C9999.framemd5"),
            "decoded_frame_count": len(frame_lines(output / "C9999.framemd5")) == info["frames"],
            "dimensions_and_cadence": (v["width"], v["height"], v["r_frame_rate"], v["pix_fmt"]) ==
                                      (1920, 1080, "60000/1001", "yuv420p"),
            "profile_level": (v["profile"], v["level"]) == ("High", 42),
            "bt709_limited": (v.get("color_space"), v.get("color_primaries"),
                             v.get("color_transfer"), v.get("color_range")) ==
                            ("bt709", "bt709", "bt709", "tv"),
            "progressive": v.get("field_order") == "progressive",
            "pcm_alignment": len(a.sizes) == info["frames"] * 1001 * 4 // 5,
            "pcm_hash": hash_audio(media) == hash_audio(base, info["audio_samples"]),
            "generated_rtmd": all(rt.sample(i) == make_packet(rt.sample(0), i)
                                  for i in range(info["frames"])),
            "syntax_no_errors": not (case / "syntax-errors.log").read_text().strip(),
            "sei_container_timing": json.loads((case / "timing.json").read_text())[
                "passed_selected_checks"],
            "progressive_slice_order": json.loads((case / "slice-order.json").read_text())[
                "passed_selected_checks"],
            "selected_cbr_cpb": json.loads((case / "cpb.json").read_text())[
                "passed_selected_cpb_checks"],
        }
        # The fixture sine starts at zero; allow a short resampler edge transient.
        audio = b"".join(media.buf[p:p + n * 4] for p, n in zip(a.chunks, a.chunk_samples))
        import struct
        active = [i for i, (left, right) in enumerate(struct.iter_unpack(">hh", audio))
                  if abs(left) > 100 or abs(right) > 100]
        onset, end = (active[0] / 48000, (active[-1] + 1) / 48000) if active else (None, None)
        if "audio_onset_seconds" in expected:
            checks["audio_offset_preserved"] = onset is not None and abs(
                onset - expected["audio_onset_seconds"]) < 0.003
            checks["audio_end_preserved"] = end is not None and abs(
                end - expected["audio_end_seconds"]) < 0.003
        else:
            checks["silent_audio"] = not active
        source_probe = probe_input(source)
        _, start, duration = source_timing(source_probe)
        report["cases"][name] = {
            "checks": checks, "passed": all(checks.values()), "frames": info["frames"],
            "source_start": str(start), "source_duration": str(duration),
            "audio_onset_seconds": onset, "audio_end_seconds": end,
            "audio_alignment": info["audio_alignment"],
            "video_bitrate": info["video_bitrate"],
            "sha256": hashlib.sha256((output / "C9999.MP4").read_bytes()).hexdigest(),
        }
        media.close()
        base.close()
        (root / "report.json").write_text(json.dumps(report, indent=2), encoding="utf-8")
        print(name, report["cases"][name]["passed"], flush=True)
    report["passed"] = all(c["passed"] for c in report["cases"].values())
    (root / "report.json").write_text(json.dumps(report, indent=2), encoding="utf-8")
    if not report["passed"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
