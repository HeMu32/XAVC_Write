"""Purpose: construct the Sony-style thumbnail associated with a candidate MP4.

Usage: python tools/build_sony_thumbnail.py --clip LOCAL_DIRECTORY/Cnnnn.MP4.
Design: decode/scale a frame, build the measured 4:2:2 JPEG components and reorder
    them according to the previously tested thumbnail recipe.
Scope: writes thumbnail/intermediate files beside the selected clip; use a local
    build directory, not the card. A valid thumbnail does not prove video playback.
"""
import argparse
import struct
import subprocess
from pathlib import Path


def reorder(data):
    if data[:2] != b"\xff\xd8" or data[-2:] != b"\xff\xd9":
        raise ValueError("Invalid JPEG")
    groups = [[], [], []]
    p = 2
    while data[p:p+2] != b"\xff\xda":
        if data[p] != 255:
            raise ValueError("Invalid JPEG segment")
        marker = data[p+1]
        n = struct.unpack_from(">H", data, p+2)[0]
        segment = data[p:p+n+2]
        if len(segment) != n+2:
            raise ValueError("Truncated JPEG segment")
        groups[0 if marker == 0xDB else 1 if marker == 0xC4 else 2].append(segment)
        p += n+2
    return b"\xff\xd8" + b"".join(b"".join(g) for g in groups) + data[p:]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--clip", default="output/cat-25m/C0008.MP4")
    args = ap.parse_args()
    root = Path(__file__).resolve().parent.parent
    clip = Path(args.clip)
    parts = []
    for w, h in [(160, 120), (1280, 720)]:
        raw = clip.with_name(f"{clip.stem}-{w}.yuv")
        jpg = clip.with_name(f"{clip.stem}-{w}.jpg")
        subprocess.run(["ffmpeg", "-hide_banner", "-v", "error", "-nostdin", "-n", "-i", str(clip),
                        "-map", "0:v:0", "-frames:v", "1", "-vf", f"scale={w}:{h}",
                        "-pix_fmt", "yuvj422p", "-f", "rawvideo", str(raw)], check=True)
        subprocess.run([str(root / "tools/jpeg422.exe"), str(raw), str(w), str(h), str(jpg)], check=True)
        parts.append(reorder(jpg.read_bytes()))
    header = bytearray((root / "tools/thumb_header.bin").read_bytes())
    if len(header) != 764:
        raise ValueError("Unexpected EXIF template size")
    struct.pack_into("<I", header, 692, len(parts[0]))
    app1len = len(header) + len(parts[0]) - 4
    if app1len > 65535:
        raise ValueError("APP1 overflow")
    struct.pack_into(">H", header, 4, app1len)
    result = header + parts[0] + parts[1][2:-2] + b"\xff\xd9"
    dest = clip.with_name(clip.stem + "T01.JPG")
    with dest.open("xb") as f:
        f.write(result)
    print(dest, len(result), "embedded", len(parts[0]), "main start", 4 + app1len)


if __name__ == "__main__":
    main()
