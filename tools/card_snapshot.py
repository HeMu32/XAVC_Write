"""Purpose: capture card metadata and inventory media before analysis or writes.

Usage: python tools/card_snapshot.py --card F:/ --output backup.
Design: create a fresh timestamped directory, copy/hash non-media files, and
    record directory state plus size and timestamps for deliberately skipped media.
Scope: reads a Sony M4ROOT card without writing/deleting card files. This is not
    a full media backup or filesystem image; inspect the saved errors before use.
"""
import argparse
import csv
import hashlib
import json
import shutil
from datetime import datetime, timezone
from pathlib import Path

MEDIA = {".jpg", ".jpeg", ".arw", ".heif", ".heic", ".png", ".mp4", ".mov", ".mts", ".m2ts"}


def sha256(path):
    h = hashlib.sha256()
    with path.open("rb") as f:
        for block in iter(lambda: f.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def state(path, root):
    s = path.stat()
    return {
        "relative_path": path.relative_to(root).as_posix(),
        "size": s.st_size,
        "creation_time_ns": s.st_ctime_ns,
        "last_write_time_ns": s.st_mtime_ns,
        "last_access_time_ns": s.st_atime_ns,
        "last_write_utc": datetime.fromtimestamp(s.st_mtime, timezone.utc).isoformat(),
    }


def write_csv(path, rows):
    with path.open("w", newline="", encoding="utf-8-sig") as f:
        w = csv.DictWriter(f, fieldnames=list(rows[0]) if rows else ["relative_path"])
        w.writeheader()
        w.writerows(rows)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--card", default="F:/")
    ap.add_argument("--output", default="backup")
    args = ap.parse_args()
    root = Path(args.card).resolve()
    if not (root / "PRIVATE/M4ROOT/CLIP").is_dir():
        raise SystemExit("Not a Sony M4ROOT card")
    out = Path(args.output).resolve() / ("snap_" + datetime.now().strftime("%Y%m%dT%H%M%S"))
    out.mkdir(parents=True, exist_ok=False)
    skipped, copied, dirs, errors = [], [], [], []
    for path in sorted(root.rglob("*")):
        try:
            row = state(path, root)
            if path.is_dir():
                dirs.append(row)
            elif path.suffix.lower() in MEDIA:
                skipped.append(row)
            else:
                dest = out / path.relative_to(root)
                dest.parent.mkdir(parents=True, exist_ok=True)
                shutil.copy2(path, dest)
                row["sha256"] = sha256(dest)
                if row["sha256"] != sha256(path):
                    raise RuntimeError("Copy hash mismatch")
                copied.append(row)
        except (OSError, RuntimeError) as e:
            errors.append({"path": str(path), "error": str(e)})
    write_csv(out / "_skipped_media_manifest.csv", skipped)
    write_csv(out / "_dir_state.csv", dirs)
    write_csv(out / "_metadata_manifest.csv", copied)
    summary = {"card": str(root), "snapshot": str(out), "metadata_files": len(copied),
               "skipped_media": len(skipped), "errors": errors}
    (out / "_snapshot.json").write_text(json.dumps(summary, indent=2), encoding="utf-8")
    print(json.dumps(summary, indent=2))
    if errors:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
