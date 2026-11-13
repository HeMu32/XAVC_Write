"""Purpose: encode finite local input to a supported AVC/PCM experiment profile.

Usage: python tools/encode_xavc.py INPUT --output DIRECTORY
    --profile hd25_5994 [--threads 6 --preset slow --dry-run].
Design: probe timing/color, derive explicit scale/fps/audio alignment and x264
    parameters, and save encoder commands, logs and provenance.
Scope: explicit 8-bit 4:2:0 SDR inputs/profiles. Unsupported color
    or timing is refused; encoding alone is not Sony packaging or camera approval.
"""
import argparse
import json
import subprocess
from fractions import Fraction
from pathlib import Path
from sony_profiles import DEFAULT_PROFILE, PROFILES, get_profile

X264_PARAMS = (
    "nal-hrd=cbr:filler=1:force-cfr=1:keyint={gop}:min-keyint={gop}:scenecut=0:"
    "bframes=2:b-adapt=0:b-pyramid=none:ref=2:weightp=0:weightb=0:open-gop=0:"
    "slices=4:aud=1:repeat-headers=0:deblock=0,0"
)


def finite_fraction(value):
    try:
        result = Fraction(str(value))
    except (ValueError, TypeError, ZeroDivisionError):
        return None
    return result


def probe_input(path):
    r = subprocess.run(["ffprobe", "-v", "error", "-show_streams", "-show_format", "-of", "json",
                        str(path)], capture_output=True, text=True, encoding="utf-8", check=True)
    return json.loads(r.stdout)


def source_timing(probe):
    video = next((s for s in probe["streams"] if s.get("codec_type") == "video"
                  and not s.get("disposition", {}).get("attached_pic")), None)
    if video is None:
        raise ValueError("Input has no video stream")
    ts = finite_fraction(video.get("time_base"))
    duration = None
    if ts is not None and video.get("duration_ts") is not None:
        duration = int(video["duration_ts"]) * ts
    duration = duration or finite_fraction(video.get("duration"))
    duration = duration or finite_fraction(probe.get("format", {}).get("duration"))
    if duration is None or duration <= 0:
        raise ValueError("Input needs a finite video duration")
    start = finite_fraction(video.get("start_time")) or Fraction(0)
    if video.get("start_pts") is not None and ts is not None:
        start = int(video["start_pts"]) * ts
    return video, start, duration


def color_policy(video):
    if video.get("color_transfer") in {"smpte2084", "arib-std-b67"}:
        raise ValueError("HDR input needs an explicit validated SDR color transform")
    pixel = video.get("pix_fmt", "")
    rgb = pixel.startswith(("rgb", "bgr", "gbr"))
    assumptions = []

    def field(name, fallback, supported):
        value = video.get(name)
        if name == "color_transfer":
            value = {"bt470m": "gamma22", "bt470bg": "gamma28"}.get(value, value)
        if value in {None, "unknown", "unspecified", "reserved"}:
            value = fallback
            assumptions.append(f"{name} missing: assumed {value}")
        if value not in supported:
            raise ValueError(f"Unsupported {name}: {value}; supply an explicit color transform")
        return value

    matrix = field("color_space", "gbr" if rgb else "bt709",
                   {"bt709", "fcc", "bt470bg", "smpte170m", "smpte240m", "ycgco", "gbr",
                    "bt2020nc"})
    primaries = field("color_primaries", "bt709",
                      {"bt709", "bt470m", "bt470bg", "smpte170m", "smpte240m", "film",
                       "bt2020", "smpte428", "smpte431", "smpte432", "jedec-p22"})
    transfer = field("color_transfer", "iec61966-2-1" if rgb else "bt709",
                     {"bt709", "gamma22", "gamma28", "smpte170m", "smpte240m", "linear",
                      "iec61966-2-1", "iec61966-2-4", "bt2020-10", "bt2020-12"})
    range_ = field("color_range", "pc" if rgb or pixel.startswith("yuvj") else "tv",
                   {"pc", "tv"})
    # swscale first converts RGB to a known YUV matrix; colorspace then handles
    # transfer/primaries as well as matrix/range conversion for YUV sources.
    prefilter = ("scale=in_range=pc:out_range=tv:out_color_matrix=bt709,format=yuv444p,"
                 if rgb else "")
    if rgb:
        matrix, range_ = "bt709", "tv"
    transform = (f"colorspace=ispace={matrix}:iprimaries={primaries}:itrc={transfer}:"
                 f"irange={range_}:all=bt709:range=tv:format=yuv420p:dither=fsb")
    return prefilter + transform, assumptions


def make_command(source, output, probe, threads=6, preset="slow", profile=DEFAULT_PROFILE):
    selected = get_profile(profile)
    video, start, duration = source_timing(probe)
    transform, _ = color_policy(video)
    audio = next((s for s in probe["streams"] if s.get("codec_type") == "audio"), None)
    start_expr = f"{start.numerator}/{start.denominator}"
    duration_text = f"{float(duration):.9f}"
    command = ["ffmpeg", "-hide_banner", "-nostdin", "-n", "-copyts", "-i", str(source)]
    if audio is None:
        command += ["-f", "lavfi", "-i", "anullsrc=channel_layout=stereo:sample_rate=48000"]
        audio_map = "1:a:0"
        audio_pts = "asetpts=PTS-STARTPTS"
    else:
        audio_map = f"0:{audio['index']}"
        audio_pts = f"asetpts=PTS-({start_expr})/TB"
    rgb = video.get("pix_fmt", "").startswith(("rgb", "bgr", "gbr"))
    filters = ["setpts=PTS-STARTPTS"]
    if rgb:
        filters.append(transform)
    filters += ["bwdif=mode=send_field:deint=interlaced",
                "scale=trunc(iw*sar/2)*2:trunc(ih/2)*2", "setsar=1"]
    if not rgb:
        filters.append(transform)
    filters += [f"scale={selected.width}:{selected.height}:flags=lanczos:"
                "force_original_aspect_ratio=decrease:force_divisible_by=2",
                f"pad={selected.width}:{selected.height}:(ow-iw)/2:(oh-ih)/2",
                f"fps={selected.fps_text}"]
    rate = f"{selected.bitrate_kbps}k"
    command += ["-map", f"0:{video['index']}", "-map", audio_map, "-map_metadata", "-1",
                "-vf", ",".join(filters),
                "-c:v", "libx264", "-preset", preset, "-profile:v", "high", "-level:v", selected.level,
                "-pix_fmt", "yuv420p", "-b:v", rate, "-minrate", rate,
                "-maxrate", rate, "-bufsize", rate, "-threads", str(threads),
                "-x264-params", X264_PARAMS.format(gop=selected.gop_frames),
                "-color_range", "tv", "-colorspace", "bt709", "-color_primaries", "bt709",
                "-color_trc", "bt709", "-c:a", "pcm_s16be", "-ar", "48000", "-ac", "2",
                "-af", f"{audio_pts},aresample=48000:async=1:first_pts=0,atrim=end={duration_text}",
                "-t", duration_text, "-video_track_timescale", str(selected.timescale),
                "-movie_timescale", str(selected.timescale),
                "-write_tmcd", "0", "-f", "mov", str(output / "base.mov")]
    return command


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("input")
    ap.add_argument("--output", required=True)
    ap.add_argument("--threads", type=int, default=6)
    ap.add_argument("--preset", default="slow")
    ap.add_argument("--profile", choices=PROFILES, default=DEFAULT_PROFILE)
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args()
    if not 1 <= args.threads <= 32:
        raise ValueError("threads must be 1..32")
    source, output = Path(args.input).resolve(), Path(args.output).resolve()
    if not source.is_file():
        raise FileNotFoundError(source)
    if output.exists():
        raise FileExistsError("Use a fresh output directory")
    probe = probe_input(source)
    selected = get_profile(args.profile)
    command = make_command(source, output, probe, args.threads, args.preset, args.profile)
    if args.dry_run:
        print(json.dumps(command, indent=2))
        return
    output.mkdir(parents=True, exist_ok=False)
    (output / "input-probe.json").write_text(json.dumps(probe, indent=2), encoding="utf-8")
    _, assumptions = color_policy(source_timing(probe)[0])
    (output / "input-assumptions.json").write_text(
        json.dumps({"color": assumptions, "sony_profile": selected.name,
                    "profile_parameters": selected.manifest_fields()}, indent=2), encoding="utf-8")
    (output / "encode-command.json").write_text(json.dumps(command, indent=2), encoding="utf-8")
    with (output / "encode.log").open("w", encoding="utf-8") as f:
        result = subprocess.run(command, stdout=f, stderr=subprocess.STDOUT)
    print("exit", result.returncode, "output", output / "base.mov")
    raise SystemExit(result.returncode)


if __name__ == "__main__":
    main()
