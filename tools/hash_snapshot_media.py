"""Purpose: hash card media while binding reads to a saved snapshot inventory.

Usage: python tools/hash_snapshot_media.py --card F:/ --snapshot SNAP
    --output NEW_LOCAL_REPORT.json.
Design: validate normalized paths, check size/mtime before and after each hash,
    and recheck the inventory before writing an exclusive-create JSON report.
Scope: read-only media hashes at this observation time. No full media backup or
    pre/post equality proof without independent earlier content hashes.
"""
import argparse
import csv
import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path


def fingerprint(path):
    stat = path.stat()
    return stat.st_size, stat.st_mtime_ns


def hash_media(card, snapshot, output):
    card, snapshot, output = [Path(value).resolve() for value in (card, snapshot, output)]
    if output == card or card in output.parents or output == snapshot or snapshot in output.parents:
        raise ValueError("Report must not modify the card or the source snapshot")
    if output.exists():
        raise FileExistsError(output)
    summary = json.loads((snapshot / "_snapshot.json").read_text(encoding="utf-8"))
    manifest = snapshot / "_skipped_media_manifest.csv"
    with manifest.open(encoding="utf-8-sig", newline="") as stream:
        inventory = list(csv.DictReader(stream))
    if len(inventory) != summary["skipped_media"] or summary["errors"]:
        raise ValueError("Incomplete snapshot media inventory")
    entries, errors, seen = [], [], set()
    for row in inventory:
        relative = row["relative_path"]
        path = (card / relative).resolve()
        try:
            if not path.is_relative_to(card) or path == card or path in seen:
                raise ValueError("Invalid or duplicate media inventory path")
            seen.add(path)
            expected = int(row["size"]), int(row["last_write_time_ns"])
            if fingerprint(path) != expected:
                raise ValueError("Live media size/mtime differs from saved inventory")
            with path.open("rb") as stream:
                digest = hashlib.file_digest(stream, "sha256").hexdigest()
            if fingerprint(path) != expected:
                raise ValueError("Live media changed during hashing")
            entries.append({"relative_path": relative, "size": expected[0],
                            "last_write_time_ns": expected[1], "sha256": digest})
        except (OSError, ValueError) as error:
            errors.append({"relative_path": relative, "error": str(error)})
    # Detect an earlier item changing while a later large file was being read.
    for row in entries:
        try:
            if fingerprint(card / row["relative_path"]) != (row["size"], row["last_write_time_ns"]):
                raise ValueError("Live media changed before final inventory recheck")
        except (OSError, ValueError) as error:
            errors.append({"relative_path": row["relative_path"], "error": str(error)})
    report = {
        "card": str(card), "snapshot": str(snapshot), "snapshot_media_manifest_sha256":
        hashlib.sha256(manifest.read_bytes()).hexdigest(),
        "completed_utc": datetime.now(timezone.utc).isoformat(), "algorithm": "sha256",
        "media_count": len(entries), "expected_media_count": len(inventory),
        "bytes_hashed": sum(row["size"] for row in entries), "entries": entries, "errors": errors,
        "passed": not errors and len(entries) == len(inventory), "card_writes": False,
        "scope": "Post-snapshot live media hashes; no pre-repair equality without an independent prior hash",
    }
    output.parent.mkdir(parents=True, exist_ok=True)
    with output.open("x", encoding="utf-8") as stream:
        json.dump(report, stream, indent=2)
    return report


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--card", required=True)
    ap.add_argument("--snapshot", required=True)
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    report = hash_media(args.card, args.snapshot, args.output)
    print(json.dumps({key: report[key] for key in
                      ("media_count", "expected_media_count", "bytes_hashed", "errors", "passed")}, indent=2))
    if not report["passed"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
