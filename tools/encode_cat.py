"""Purpose: reproduce the original fixed Cat-input 25M encoding experiment.

Usage: python tools/encode_cat.py, from the workspace environment with FFmpeg.
Design: encode Cat_25-12-25.mp4 to output/cat-25m/base.mov using fixed x264/PCM
    parameters, saving the command and encoder log; FFmpeg refuses overwriting.
Scope: historical hard-coded input, duration/audio sample count and HD25 setup.
    Prefer encode_xavc.py for other inputs; this does not package or deploy a clip.
"""
import json
import subprocess
from pathlib import Path


def main():
    root = Path(__file__).resolve().parent.parent
    out = root / "output/cat-25m"
    out.mkdir(parents=True, exist_ok=True)
    command = [
        "ffmpeg", "-hide_banner", "-nostdin", "-n", "-i", str(root / "Cat_25-12-25.mp4"),
        "-map", "0:v:0", "-map", "0:a:0", "-map_metadata", "-1",
        "-vf", "scale=1920:1080:flags=lanczos,setsar=1,fps=60000/1001",
        "-c:v", "libx264", "-preset", "slow", "-profile:v", "high", "-level:v", "4.2",
        "-pix_fmt", "yuv420p", "-b:v", "25000k", "-minrate", "25000k", "-maxrate", "25000k",
        "-bufsize", "25000k", "-threads", "6",
        "-x264-params", "nal-hrd=cbr:filler=1:force-cfr=1:keyint=30:min-keyint=30:scenecut=0:"
        "bframes=2:b-adapt=0:b-pyramid=none:ref=2:weightp=0:weightb=0:open-gop=0:slices=4:"
        "aud=1:repeat-headers=0:deblock=0,0",
        "-color_range", "tv", "-colorspace", "bt709", "-color_primaries", "bt709",
        "-color_trc", "bt709", "-c:a", "pcm_s16be", "-ar", "48000", "-ac", "2",
        "-af", "atrim=end_sample=1228427,asetpts=PTS-STARTPTS",
        "-video_track_timescale", "60000", "-movie_timescale", "60000",
        "-write_tmcd", "0", "-f", "mov", str(out / "base.mov"),
    ]
    (out / "encode-command.json").write_text(json.dumps(command, indent=2), encoding="utf-8")
    with (out / "encode.log").open("w", encoding="utf-8") as f:
        r = subprocess.run(command, stdout=f, stderr=subprocess.STDOUT)
    print("exit", r.returncode, "output", out / "base.mov")
    raise SystemExit(r.returncode)


if __name__ == "__main__":
    main()
