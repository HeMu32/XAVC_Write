"""Purpose: check a connected card against a previously saved snapshot.

Usage: python tools/audit_card_snapshot.py --card F:/ --snapshot SNAP
    --output LOCAL_REPORT.json.
Design: compare file membership, metadata SHA-256 and media size/write time;
    write a local JSON report and fail when differences are found.
Scope: read-only card audit using this project's snapshot manifests. Media
    contents are not hashed, so unchanged timestamps do not prove byte equality.
"""
import argparse
import csv
import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path


def rows(path):
    with path.open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream))


def audit(card, snapshot):
    metadata = rows(snapshot / "_metadata_manifest.csv")
    media = rows(snapshot / "_skipped_media_manifest.csv")
    expected = {row["relative_path"] for row in metadata + media}
    actual = {p.relative_to(card).as_posix() for p in card.rglob("*") if p.is_file()}
    changed_metadata, changed_media = [], []
    for group, changed, with_hash in [(metadata, changed_metadata, True), (media, changed_media, False)]:
        for row in group:
            path = card / row["relative_path"]
            if not path.is_file():
                continue
            stat = path.stat()
            if with_hash:
                with path.open("rb") as stream:
                    differs = hashlib.file_digest(stream, "sha256").hexdigest() != row["sha256"]
            else:
                differs = (stat.st_size != int(row["size"]) or
                           stat.st_mtime_ns != int(row["last_write_time_ns"]))
            if differs:
                changed.append(row["relative_path"])
    result = {"card": str(card), "snapshot": str(snapshot),
              "checked_at_utc": datetime.now(timezone.utc).isoformat(),
              "missing": sorted(expected - actual), "added": sorted(actual - expected),
              "changed_metadata_hashes": changed_metadata, "changed_media_size_or_mtime": changed_media,
              "metadata_files": len(metadata), "media_files": len(media),
              "media_content_hashes_checked": False}
    result["unchanged"] = not any(result[key] for key in
                                   ["missing", "added", "changed_metadata_hashes",
                                    "changed_media_size_or_mtime"])
    return result


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--card", required=True)
    ap.add_argument("--snapshot", required=True)
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    card, snapshot, output = Path(args.card).resolve(), Path(args.snapshot).resolve(), Path(args.output).resolve()
    # The report must not itself become an untracked write to the source card.
    if output == card or card in output.parents:
        raise ValueError("Audit report must be outside the card")
    if not (card / "PRIVATE/M4ROOT/CLIP").is_dir():
        raise ValueError("Not the expected Sony card")
    report = audit(card, snapshot)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps(report, indent=2))
    if not report["unchanged"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
