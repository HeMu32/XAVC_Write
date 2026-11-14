"""Inventory local deliverables without accessing a card or admitting packages.

Usage: python tools/inventory_deliverables.py --output analysis/NEW.json.
Reports source/doc files, top-level evidence, output manifests, encoded bases,
saved snapshot summaries and local-only research directories. It does not walk
raw Ghidra projects, hash media, copy assets, execute tools or revalidate packages.
"""
import argparse
from datetime import datetime, timedelta, timezone
import hashlib
import json
from pathlib import Path
import re
import subprocess


ROOT = Path(__file__).resolve().parents[1]
HASH_LIMIT = 4 * 1024 * 1024
TEXT_SUFFIXES = {".md", ".txt", ".json", ".log", ".csv", ".py", ".ps1", ".c", ".java"}


def read_json(path):
    return json.loads(path.read_text(encoding="utf-8-sig"))


def file_ref(root, path, tracked):
    relative = path.relative_to(root).as_posix()
    row = {"path": relative, "exists": path.is_file(), "git_tracked": relative in tracked}
    if row["exists"]:
        stat = path.stat()
        row.update(bytes=stat.st_size, last_write_time_ns=stat.st_mtime_ns)
        if path.suffix.lower() in TEXT_SUFFIXES and stat.st_size <= HASH_LIMIT:
            row["sha256"] = hashlib.sha256(path.read_bytes()).hexdigest()
    return row


def package_view(root, path, tracked):
    manifest = read_json(path)
    clip = manifest["clip"]
    if not re.fullmatch(r"C\d{4}", clip):
        raise ValueError("Unexpected clip name in " + str(path))
    verification_path = path.parent / "verification.json"
    deployment_path = path.parent / "deployment.json"
    verification = read_json(verification_path) if verification_path.is_file() else {}
    deployment = read_json(deployment_path) if deployment_path.is_file() else {}
    return {
        "manifest": file_ref(root, path, tracked), "clip": clip,
        "package_kind": manifest.get("package_kind", "legacy_unspecified"),
        "profile": manifest.get("sony_profile"),
        "declared_media_sha256": manifest.get("sha256"),
        "media_hash_recomputed": False,
        "assets": [file_ref(root, path.parent / name, tracked) for name in (
            clip + ".MP4", clip + "M01.XML", clip + "T01.JPG")],
        "historical_verification": {
            "report": file_ref(root, verification_path, tracked),
            "passed": verification.get("passed"),
            "schema": verification.get("verification_schema"),
            "current_admission_recomputed": False},
        "historical_deployment": {
            "report": file_ref(root, deployment_path, tracked),
            "status": deployment.get("status")},
        "physical_playback_inferred_from_local_reports": False,
    }


def collect(root=ROOT):
    root = root.resolve()
    tracked = set(subprocess.check_output(
        ["git", "ls-files", "-z"], cwd=root).decode("utf-8").split("\0"))
    head = subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=root).decode().strip()
    files = {}
    for directory in ("docs", "tools"):
        files[directory] = [
            file_ref(root, path, tracked)
            for path in sorted((root / directory).rglob("*"))
            if path.is_file() and "__pycache__" not in path.parts]
    files["analysis_top_level"] = [
        file_ref(root, path, tracked) for path in sorted((root / "analysis").iterdir())
        if path.is_file() and not path.name.startswith(("dsh-", "deliverables-inventory-"))]
    files["decompiled_exports"] = [
        file_ref(root, path, tracked) for folder in sorted((root / "analysis").glob("decompile-*"))
        if folder.is_dir() for path in sorted(folder.rglob("*")) if path.is_file()]
    packages = [package_view(root, path, tracked) for path in
                sorted((root / "output").rglob("build-manifest.json"))]
    repairs = []
    for path in sorted((root / "output").rglob("repair-manifest.json")):
        manifest = read_json(path)
        repairs.append({
            "manifest": file_ref(root, path, tracked), "clip": manifest.get("clip"),
            "purpose": manifest.get("purpose"),
            "declared_corrected_media_sha256": manifest.get("corrected_media_sha256"),
            "media_hash_recomputed": False,
            "deployment": file_ref(root, path.parent / "repair-deployment.json", tracked),
            "general_new_clip_deployment_package": False})
    snapshots = []
    for path in sorted((root / "backup").glob("snap_*/_snapshot.json")):
        summary = read_json(path)
        snapshots.append({
            "summary": file_ref(root, path, tracked),
            "metadata_files": summary["metadata_files"],
            "skipped_media": summary["skipped_media"], "errors": summary["errors"],
            "saved_metadata_revalidated_this_inventory": False,
            "scope": "Saved capture summary, not a full media backup or live card state"})
    encoded = [{
        "media": file_ref(root, path, tracked),
        "assumptions": file_ref(root, path.parent / "input-assumptions.json", tracked),
        "command": file_ref(root, path.parent / "encode-command.json", tracked),
        "media_hash_recomputed": False,
    } for path in sorted((root / "output").rglob("base.mov"))]
    research_dirs = [path.relative_to(root).as_posix() for path in
                     sorted((root / "analysis").iterdir())
                     if path.is_dir() and not path.name.startswith("decompile-")]
    return {
        "inventory_schema": 1,
        "created_at_local": datetime.now(timezone(timedelta(hours=8))).isoformat(),
        "workspace": str(root), "source_commit": head,
        "source_commit_scope": "HEAD only; listed working-tree files may contain uncommitted changes",
        "card_access": False, "card_writes": False, "media_hashes_recomputed": False,
        "saved_reports_are_not_current_deployment_approval": True,
        "file_hash_scope": "Text files no larger than 4 MiB only; binaries/media use existence, size and mtime",
        "files": files, "media_packages": packages, "targeted_repair_packages": repairs,
        "encoded_bases": encoded, "saved_snapshots": snapshots,
        "camera_feedback_reports": [
            file_ref(root, path, tracked) for path in sorted(
                (root / "analysis").glob("camera-observations-*.json"))],
        "local_research_directories_not_recursively_inventoried": research_dirs,
        "firmware_and_input_references": [
            file_ref(root, root / name, tracked) for name in (
                "Cat_25-12-25.mp4", "mux_playfull_ytb_1080.mp4",
                "firmware/m4-v602/copy-manifest.json",
                "firmware/m4-v602/extracted-manifest.json", "firmware/m4-v602/inventory.json",
                "firmware/m4-v602/usr/lib/libmpr.so",
                "firmware/m4-v602/usr/lib/appFw.so",
                "firmware/m4-v602/usr/lib/libexpat.so.1.6.11",
                "firmware/m4-v602/usr/lib/libstdc++.so.6.0.22")],
        "counts": {
            **{key: len(rows) for key, rows in files.items()},
            "media_packages": len(packages), "targeted_repairs": len(repairs),
            "encoded_bases": len(encoded), "snapshot_summaries": len(snapshots)},
        "exclusions": [
            ".git internals, __pycache__, DSH private exports, earlier inventory outputs",
            "Raw research-directory contents and the extracted firmware filesystem",
            "Media content hashing, live card state, execution of any listed tool"],
    }


def write_report(root, output, report):
    root, output = root.resolve(), output.resolve()
    if not output.is_relative_to(root / "analysis"):
        raise ValueError("Inventory output must stay in the workspace analysis directory")
    output.parent.mkdir(parents=True, exist_ok=True)
    with output.open("x", encoding="utf-8", newline="\n") as stream:
        json.dump(report, stream, indent=2, ensure_ascii=True)
        stream.write("\n")


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--output", required=True, help="Fresh JSON path under analysis/")
    args = ap.parse_args()
    report = collect()
    write_report(ROOT, Path(args.output), report)
    print(json.dumps(report["counts"], indent=2))


if __name__ == "__main__":
    main()
