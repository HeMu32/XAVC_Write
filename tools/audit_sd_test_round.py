"""Purpose: audit an ordered deployment round against the connected SD card.

Usage: python tools/audit_sd_test_round.py --card F:/ --before SNAP
    --build PACKAGE_A [--build PACKAGE_B] --output LOCAL_REPORT.json.
Design: bind package verification and deployment records to card readback,
    checking cumulative catalog changes and preservation of existing resources.
Scope: read-only audit of this project's additive SD transactions; does not
    deploy packages or establish camera listing, decoding or playback.
"""
import argparse
import json
from datetime import datetime, timezone
from pathlib import Path

from audit_card_snapshot import audit
from deploy_sd_clip import digest
from sony_verification import require_current_verification, require_package_hashes


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--card", default="F:/")
    ap.add_argument("--before", required=True)
    ap.add_argument("--build", action="append", required=True)
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    card, output = Path(args.card).resolve(), Path(args.output).resolve()
    if output == card or card in output.parents:
        raise ValueError("Report must be outside the card")
    builds = [Path(value).resolve() for value in args.build]
    expected, packages = {}, []
    assets = set()
    native_source_checks = []
    for build in builds:
        manifest = json.loads((build / "build-manifest.json").read_text(encoding="utf-8"))
        report = json.loads((build / "verification.json").read_text(encoding="utf-8"))
        deployment = json.loads((build / "deployment.json").read_text(encoding="utf-8"))
        transaction = json.loads((build / "catalog/transaction.json").read_text(encoding="utf-8"))
        require_current_verification(report, manifest.get("package_kind", "encoded_avc"),
                                     manifest.get("acquisition", "unspecified"),
                                     transaction.get("catalog_representation", "native_reuse"))
        if deployment.get("status") != "deployed":
            raise ValueError("Expected a successful deployment")
        clip = manifest["clip"]
        require_package_hashes(report, build, clip)
        mapping = {clip + ".MP4": f"PRIVATE/M4ROOT/CLIP/{clip}.MP4",
                   clip + "M01.XML": f"PRIVATE/M4ROOT/CLIP/{clip}M01.XML",
                   clip + "T01.JPG": f"PRIVATE/M4ROOT/THMBNL/{clip}T01.JPG",
                   "catalog/DATABASE.BIN": "PRIVATE/DATABASE/DATABASE.BIN",
                   "catalog/MEDIAPRO.XML": "PRIVATE/M4ROOT/MEDIAPRO.XML"}
        local_matches = {name: digest(build / name) == report["package_hashes"][name]
                         for name in mapping}
        if not all(local_matches.values()):
            raise ValueError(f"Verified local files changed: {clip}")
        for name, path in mapping.items():
            if name.startswith("catalog/"):
                # Builds are in deployment order: the final package owns the catalogs.
                expected[path] = report["package_hashes"][name]
            else:
                if path in assets:
                    raise ValueError("Duplicate clip assets")
                assets.add(path)
                expected[path] = report["package_hashes"][name]
        if manifest.get("package_kind") == "native_control":
            native_source_checks.append(digest(Path(manifest["base"])) == manifest["native_source_sha256"])
        if manifest.get("package_kind") == "source_control":
            native_source_checks.append(
                digest(Path(manifest["base"])) == manifest["source_sha256"] and
                digest(Path(manifest["observations_path"])) == manifest["observations_sha256"])
        packages.append({"clip": clip, "package": str(build), "profile": report["verification_profile"],
                         "schema": report["verification_schema"], "frames": manifest["frames"],
                         "media_sha256": manifest["sha256"]})
    state = audit(card, Path(args.before).resolve())
    readback = {path: digest(card / path) == value for path, value in expected.items()}
    checks = {
        "all_clip_assets_and_final_catalogs_match_verified_files": all(readback.values()),
        "only_expected_files_added": set(state["added"]) == assets,
        "no_missing_old_files": not state["missing"],
        "old_metadata_changes_limited_to_two_catalogs": set(state["changed_metadata_hashes"]) == {
            "PRIVATE/DATABASE/DATABASE.BIN", "PRIVATE/M4ROOT/MEDIAPRO.XML"},
        "old_media_sizes_and_write_times_unchanged": not state["changed_media_size_or_mtime"],
        "control_sources_and_bound_observations_still_bit_exact": all(native_source_checks),
    }
    result = {"checked_at_utc": datetime.now(timezone.utc).isoformat(), "card": str(card),
              "packages": packages, "checks": checks, "passed": all(checks.values()),
              "readback": readback, "before_snapshot_audit": state,
              "camera_listing": "NOT_TESTED", "camera_playback": "NOT_TESTED",
              "scope": "Metadata hashes and selected media hashes; all other old media use size/mtime"}
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(result, indent=2), encoding="utf-8")
    print(json.dumps(result, indent=2))
    if not result["passed"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
