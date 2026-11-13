"""Purpose: preflight or apply a revision of this task's own deployed test clip.

Usage: python tools/revise_owned_clip.py --previous PREVIOUS_PACKAGE
    --build REVISED_PACKAGE --card F:/; add --apply only with write authorization.
Design: require matching previous deployment/resource hashes and current
    verification before the narrowly scoped revision and readback.
Scope: owned experimental clips only, not arbitrary card media. Unlike additive
    deployment, --apply can replace the identified existing test resources.
"""
import argparse
import csv
import json
import subprocess
import sys
from pathlib import Path

from deploy_sd_clip import digest, durable_write
from sony_verification import require_current_verification, require_package_hashes


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--previous", required=True)
    ap.add_argument("--build", required=True)
    ap.add_argument("--card", default="F:/")
    ap.add_argument("--apply", action="store_true")
    args = ap.parse_args()
    old, new, card = Path(args.previous).resolve(), Path(args.build).resolve(), Path(args.card).resolve()
    old_deploy = json.loads((old / "deployment.json").read_text(encoding="utf-8"))
    manifest = json.loads((new / "build-manifest.json").read_text(encoding="utf-8"))
    clip = manifest["clip"]
    if old_deploy["status"] != "deployed" or old_deploy["clip"] != clip:
        raise ValueError("Not a previous successful deployment of this same test clip")
    verification = json.loads((new / "verification.json").read_text(encoding="utf-8"))
    transaction = json.loads((new / "catalog/transaction.json").read_text(encoding="utf-8"))
    require_current_verification(verification, manifest.get("package_kind", "encoded_avc"),
                                 manifest.get("acquisition", "unspecified"),
                                 transaction.get("catalog_representation", "native_reuse"))
    require_package_hashes(verification, new, clip)
    previous_hashes = {x["path"]: x["sha256"] for x in old_deploy["added"] + old_deploy["updated"]}
    mapping = {
        f"PRIVATE/M4ROOT/CLIP/{clip}.MP4": clip + ".MP4",
        f"PRIVATE/M4ROOT/CLIP/{clip}M01.XML": clip + "M01.XML",
        f"PRIVATE/M4ROOT/THMBNL/{clip}T01.JPG": clip + "T01.JPG",
        "PRIVATE/M4ROOT/MEDIAPRO.XML": "catalog/MEDIAPRO.XML",
        "PRIVATE/DATABASE/DATABASE.BIN": "catalog/DATABASE.BIN"}
    if set(previous_hashes) != set(mapping):
        raise ValueError("Unexpected previous write set")
    for rel, local in mapping.items():
        if digest(card / rel) != previous_hashes[rel] or digest(old / local) != previous_hashes[rel]:
            raise ValueError(f"Previous candidate has changed: {rel}")
        if digest(new / local) != verification["package_hashes"][local]:
            raise ValueError(f"Verified replacement changed: {local}")
    if not args.apply:
        print("Revision preflight passed; no card changes")
        return
    root = Path(__file__).resolve().parent.parent
    result = subprocess.run([sys.executable, str(root / "tools/card_snapshot.py"), "--card", str(card),
                             "--output", str(root / "backup")],
                            check=True, capture_output=True, text=True)
    snap = Path(json.loads(result.stdout)["snapshot"])
    audit = {"clip": clip, "card": str(card), "snapshot": str(snap),
             "previous_deployment": str(old / "deployment.json"),
             "status": "writing", "added": [], "updated": [], "deleted": [],
             "camera_playback": "NOT_TESTED"}
    audit_path = new / "deployment.json"
    try:
        for rel, local in mapping.items():
            durable_write(card / rel, (new / local).read_bytes())
            audit["updated"].append({"path": rel, "sha256": digest(card / rel)})
        problems = []
        for name in ["_metadata_manifest.csv", "_skipped_media_manifest.csv"]:
            with (snap / name).open(encoding="utf-8-sig", newline="") as f:
                for row in csv.DictReader(f):
                    rel = row["relative_path"]
                    if rel in mapping:
                        continue
                    p = card / rel
                    if "sha256" in row:
                        if digest(p) != row["sha256"]:
                            problems.append(rel)
                    elif p.stat().st_size != int(row["size"]) or p.stat().st_mtime_ns != int(row["last_write_time_ns"]):
                        problems.append(rel)
        if problems:
            raise ValueError(f"Unexpected unrelated changes: {problems}")
        audit["status"] = "deployed"
        audit["existing_unrelated_files_unchanged"] = True
    except Exception as e:
        audit["status"] = "failed_restored_previous_candidate"
        audit["error"] = str(e)
        for rel, local in mapping.items():
            durable_write(card / rel, (old / local).read_bytes())
        raise
    finally:
        audit_path.write_text(json.dumps(audit, indent=2), encoding="utf-8")
    print(json.dumps(audit, indent=2))


if __name__ == "__main__":
    main()
