"""Purpose: capture FFmpeg AVC syntax traces and selected named fields.

Usage: python tools/trace_avc.py INPUT.MP4 --output REPORT.json [--all-sei].
Design: invoke trace_headers, retain parser evidence and extract a compact
    summary for timing, slice and firmware-field cross-checks.
Scope: local syntax observation through FFmpeg, not an independent complete AVC
    validator, firmware trace or proof that a camera will decode the stream.
"""
import argparse
import json
import re
import subprocess
from pathlib import Path


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("input")
    ap.add_argument("--output", required=True)
    ap.add_argument("--all-sei", action="store_true")
    args = ap.parse_args()
    duration = [] if args.all_sei else ["-t", "0.04"]
    filters = "filter_units=pass_types=6-8,trace_headers" if args.all_sei else "trace_headers"
    result = subprocess.run(["ffmpeg", "-hide_banner", "-v", "info", "-i", args.input,
                             "-map", "0:v:0"] + duration + ["-c:v", "copy",
                             "-bsf:v", filters, "-f", "null", "-"],
                            capture_output=True, text=True, encoding="utf-8", errors="replace")
    out = Path(args.output)
    out.parent.mkdir(parents=True, exist_ok=True)
    out.with_suffix(".log").write_text(result.stderr, encoding="utf-8")
    fields = {}
    for line in result.stderr.splitlines():
        match = re.search(r"\]\s+\d+\s+([a-zA-Z][a-zA-Z_0-9\[\]]*)\s+[01]+\s+=\s+(-?\d+)", line)
        if match:
            key, value = match.groups()
            fields.setdefault(key, [])
            if int(value) not in fields[key]:
                fields[key].append(int(value))
    out.write_text(json.dumps(fields, indent=2), encoding="utf-8")
    print(out, "exit", result.returncode)
    raise SystemExit(result.returncode)


if __name__ == "__main__":
    main()
