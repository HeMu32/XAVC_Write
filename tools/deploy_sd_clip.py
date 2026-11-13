"""Purpose: preflight or apply a verified additive SD clip transaction.

Usage: python tools/deploy_sd_clip.py --card F:/ --build PACKAGE; add --apply
    only when explicitly authorized to write the card.
Design: validate current package/source hashes, snapshot before application,
    create new MP4/XML/JPG resources, update both catalogs and verify readback.
Scope: this project's guarded SD transaction format, not CFexpress or recovery.
    --apply writes catalogs; no card file is deleted or existing clip replaced.
"""
import argparse
import csv
import hashlib
import json
import os
import subprocess
import sys
from pathlib import Path
from sony_verification import require_current_verification, require_package_hashes


def digest(path):
    with path.open("rb") as f:
        return hashlib.file_digest(f, "sha256").hexdigest()


def durable_write(path, data, new=False):
    with path.open("xb" if new else "r+b") as f:
        f.write(data)
        f.truncate()
        f.flush()
        os.fsync(f.fileno())
    if digest(path) != hashlib.sha256(data).hexdigest():
        raise RuntimeError(f"Readback mismatch: {path}")


def durable_copy_new(source, destination):
    expected = digest(source)
    with source.open("rb") as src, destination.open("xb") as dst:
        for block in iter(lambda: src.read(1024 * 1024), b""):
            dst.write(block)
        dst.flush()
        os.fsync(dst.fileno())
    if digest(destination) != expected or digest(source) != expected:
        raise RuntimeError(f"Readback or source mismatch: {destination}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--card", default="F:/")
    ap.add_argument("--build", default="output/cat-25m")
    ap.add_argument("--apply", action="store_true")
    args = ap.parse_args()
    root = Path(__file__).resolve().parent.parent
    card, build = Path(args.card).resolve(), Path(args.build).resolve()
    manifest = json.loads((build / "build-manifest.json").read_text(encoding="utf-8"))
    transaction = json.loads((build / "catalog/transaction.json").read_text(encoding="utf-8"))
    verification = json.loads((build / "verification.json").read_text(encoding="utf-8"))
    require_current_verification(verification, manifest.get("package_kind", "encoded_avc"),
                                 manifest.get("acquisition", "unspecified"),
                                 transaction.get("catalog_representation", "native_reuse"))
    if manifest.get("package_kind") == "native_control" and digest(Path(manifest["base"])) != manifest["native_source_sha256"]:
        raise RuntimeError("Native source changed after control preparation")
    if manifest.get("package_kind") == "source_control":
        if digest(Path(manifest["base"])) != manifest["source_sha256"]:
            raise RuntimeError("Historical source changed after control preparation")
        if digest(Path(manifest["observations_path"])) != manifest["observations_sha256"]:
            raise RuntimeError("Historical source observation changed")
    clip = manifest["clip"]
    require_package_hashes(verification, build, clip)
    files = {
        f"PRIVATE/M4ROOT/CLIP/{clip}.MP4": build / (clip + ".MP4"),
        f"PRIVATE/M4ROOT/CLIP/{clip}M01.XML": build / (clip + "M01.XML"),
        f"PRIVATE/M4ROOT/THMBNL/{clip}T01.JPG": build / (clip + "T01.JPG"),
    }
    catalogs = {
        "PRIVATE/M4ROOT/MEDIAPRO.XML": ("MEDIAPRO.XML", "mediapro"),
        "PRIVATE/DATABASE/DATABASE.BIN": ("DATABASE.BIN", "database"),
    }
    if not (card / "PRIVATE/M4ROOT/CLIP").is_dir():
        raise ValueError("Not the expected Sony card")
    for rel in files:
        if (card / rel).exists():
            raise FileExistsError(f"Will not replace a clip asset: {rel}")
    for rel, (local, key) in catalogs.items():
        if digest(card / rel) != transaction[key + "_before_sha256"]:
            raise RuntimeError(f"Card changed since staging: {rel}")
        if digest(build / "catalog" / local) != transaction[key + "_after_sha256"]:
            raise RuntimeError(f"Staged catalog changed: {local}")
    if digest(files[f"PRIVATE/M4ROOT/CLIP/{clip}.MP4"]) != manifest["sha256"]:
        raise RuntimeError("Verified clip changed")
    if not args.apply:
        print("Preflight passed. No card changes. Use --apply to deploy.")
        return
    run = subprocess.run([sys.executable, str(root / "tools/card_snapshot.py"),
                          "--card", str(card), "--output", str(root / "backup")],
                         check=True, capture_output=True, text=True)
    fresh = json.loads(run.stdout)
    snapshot = Path(fresh["snapshot"])
    audit = {"clip": clip, "card": str(card), "snapshot": str(snapshot),
             "added": [], "updated": [], "deleted": [], "status": "writing",
             "camera_playback": "NOT_TESTED"}
    audit_path = build / "deployment.json"
    def save():
        audit_path.write_text(json.dumps(audit, indent=2), encoding="utf-8")
    save()
    inflight = None
    try:
        for rel, src in files.items():
            durable_copy_new(src, card / rel)
            audit["added"].append({"path": rel, "sha256": digest(card / rel)})
            save()
        for rel, (local, key) in catalogs.items():
            if digest(card / rel) != transaction[key + "_before_sha256"]:
                raise RuntimeError(f"Concurrent card modification: {rel}")
            inflight = rel
            durable_write(card / rel, (build / "catalog" / local).read_bytes())
            inflight = None
            audit["updated"].append({"path": rel, "sha256": digest(card / rel)})
            save()
        problems = []
        with (snapshot / "_metadata_manifest.csv").open(encoding="utf-8-sig", newline="") as f:
            for row in csv.DictReader(f):
                rel = row["relative_path"]
                if rel not in catalogs and digest(card / rel) != row["sha256"]:
                    problems.append(rel)
        with (snapshot / "_skipped_media_manifest.csv").open(encoding="utf-8-sig", newline="") as f:
            for row in csv.DictReader(f):
                s = (card / row["relative_path"]).stat()
                if s.st_size != int(row["size"]) or s.st_mtime_ns != int(row["last_write_time_ns"]):
                    problems.append(row["relative_path"])
        audit["existing_files_unchanged"] = not problems
        audit["unexpected_changes"] = problems
        audit["status"] = "deployed" if not problems else "deployed_with_unexpected_changes"
        save()
        print(json.dumps(audit, indent=2))
        if problems:
            raise RuntimeError("Unexpected existing-file changes detected")
    except Exception as e:
        audit["status"] = "failed"
        audit["error"] = str(e)
        # Restore only catalogs this transaction changed; leave all clip files present.
        if inflight is not None:
            durable_write(card / inflight, (snapshot / inflight).read_bytes())
        for item in audit["updated"]:
            rel = item["path"]
            if digest(card / rel) == item["sha256"]:
                durable_write(card / rel, (snapshot / rel).read_bytes())
        save()
        raise


if __name__ == "__main__":
    main()
