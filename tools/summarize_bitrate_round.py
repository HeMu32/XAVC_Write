"""Record a completed diagnostic deployment without inventing camera observations.

Usage: --before SNAP --after SNAP --audit REPORT --regression-log LOG
    --build A --build B --build A --build B --output ROUND.json.
Read local evidence and selected card controls; never write the card.
"""
import argparse
import json
import re
from datetime import datetime, timezone
from pathlib import Path

from bitrate_experiment import package_spec, require_diagnostic_evidence
from bitrate_reader_evidence import validate_reader_report
from sony_db import inventory
from sony_verification import digest, require_current_verification, require_package_hashes

CONTROLS = {
    "C6520": "bd191099d30e7bc3921a0f4f3e18aba71d095f924d20458180fbf2a67e9f377b",
    "C6515": "f6815df190cda04a3dcd500aba0df6c4ac1859f22838297b337c3b2f1b0f63e5",
}


def read(path):
    return json.loads(Path(path).read_text(encoding="utf-8"))


def validate_audit_binding(audit, card, before, builds):
    """A passing audit from some other round is not preservation evidence."""
    expected = []
    assets = {"PRIVATE/DATABASE/DATABASE.BIN", "PRIVATE/M4ROOT/MEDIAPRO.XML"}
    for build in builds:
        m = read(build / "build-manifest.json")
        expected.append((str(build.resolve()), m["clip"], m["sha256"]))
        assets.update({
            f"PRIVATE/M4ROOT/CLIP/{m['clip']}.MP4",
            f"PRIVATE/M4ROOT/CLIP/{m['clip']}M01.XML",
            f"PRIVATE/M4ROOT/THMBNL/{m['clip']}T01.JPG"})
    try:
        actual = [(str(Path(row["package"]).resolve()), row["clip"], row["media_sha256"])
                  for row in audit["packages"]]
        state = audit["before_snapshot_audit"]
        checks = audit["checks"]
        if (audit["passed"] is not True or not checks or
                any(value is not True for value in checks.values()) or
                Path(audit["card"]).resolve() != card.resolve() or
                Path(state["card"]).resolve() != card.resolve() or
                Path(state["snapshot"]).resolve() != before.resolve() or
                actual != expected or set(audit["readback"]) != assets or
                any(value is not True for value in audit["readback"].values())):
            raise ValueError("Final audit does not bind this card, baseline and ordered packages")
    except (KeyError, TypeError, AttributeError) as error:
        raise ValueError("Incomplete final audit binding") from error


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--card", default="F:/")
    for name in ("before", "after", "audit", "regression-log", "output"):
        ap.add_argument("--" + name, required=True)
    ap.add_argument("--build", action="append", required=True)
    args = ap.parse_args()
    output, card = Path(args.output).resolve(), Path(args.card).resolve()
    if output == card or output.is_relative_to(card) or output.exists():
        raise ValueError("Use a fresh local report path")
    audit = read(args.audit)
    before, after = Path(args.before).resolve(), Path(args.after).resolve()
    builds = [Path(value).resolve() for value in args.build]
    validate_audit_binding(audit, card, before, builds)
    regression_text = Path(args.regression_log).read_text(encoding="utf-8-sig", errors="replace")
    regression = re.search(r"\nRan (\d+) tests in ([\d.]+)s\s+OK\s*$", regression_text)
    if not regression:
        raise ValueError("Full regression log must finish successfully")
    dbs = [(snap / "PRIVATE/DATABASE/DATABASE.BIN").read_bytes() for snap in (before, after)]
    rows = [{row["index"]: row for row in inventory(db)} for db in dbs]
    added = sorted(rows[1].keys() - rows[0].keys())
    if (len(added) != 4 or rows[0].keys() - rows[1].keys() or
            any(row["hex"] != rows[1][index]["hex"] for index, row in rows[0].items())):
        raise ValueError("Must preserve every old record and add exactly four records")
    clips = []
    seen = set()
    for build in builds:
        m = read(build / "build-manifest.json")
        spec = package_spec(m)
        verification = read(build / "verification.json")
        transaction = read(build / "catalog/transaction.json")
        require_current_verification(verification, "bitrate_diagnostic", "rec709",
                                     "observed_minimal", allow_diagnostic=True)
        require_package_hashes(verification, build, m["clip"])
        require_diagnostic_evidence(verification, build, m)
        reader_path = Path(m["diagnostic_evidence"]["reader_report"])
        reader = read(reader_path)
        assessment = validate_reader_report(reader, build / (m["clip"] + ".MP4"), spec)
        pair_path = Path(m["diagnostic_evidence"]["pair_report"])
        pair = read(pair_path)
        role = ("59" if spec.coding_profile().half_step else "29") + "-" + spec.variant
        if role in seen:
            raise ValueError("Duplicate diagnostic role")
        seen.add(role)
        record = transaction["movie_record"]
        if record not in added or rows[1][record].get("clip_number") != int(m["clip"][1:]):
            raise ValueError("Final database lacks expected diagnostic record")
        firmware_catalog = read(build / "firmware-catalog-verification.json")
        if (firmware_catalog.get("passed") is not True or
                firmware_catalog.get("hashes") != {
                    "database": transaction["database_after_sha256"],
                    "mediapro": transaction["mediapro_after_sha256"]}):
            raise ValueError("Original catalog-reader evidence is failed or stale")
        media_size = (build / (m["clip"] + ".MP4")).stat().st_size
        clips.append({
            "label": role, "clip": m["clip"], "package": str(build),
            "media_sha256": m["sha256"], "media_size": media_size,
            "total_file_bitrate_bps": media_size * 8 * m["timescale"] / m["duration_ticks"],
            "experiment_spec": spec.to_dict(), "frames": m["frames"],
            "duration_seconds": m["duration_ticks"] / m["timescale"],
            "audio_samples": m["audio_samples"], "catalog_record": record,
            "staging_snapshot": transaction["snapshot"],
            "pair_report": str(pair_path), "pair_report_sha256": digest(pair_path),
            "rates": pair["rates"][spec.variant.lower()],
            "reader_report": str(reader_path), "reader_report_sha256": digest(reader_path),
            "reader_original_passed": reader["passed_selected_reader_checks"],
            "reader_property_query_status": reader["result"]["last_status_u32"],
            "reader_assessment": assessment,
            "verification_sha256": digest(build / "verification.json"),
            "firmware_catalog_verification_sha256": digest(build / "firmware-catalog-verification.json"),
            "camera": dict.fromkeys(("listed", "thumbnail", "starts_playback", "full_duration",
                                     "audio", "seek", "message")),
        })
    if seen != {"29-A", "29-B", "59-A", "59-B"} or len(clips) != 4:
        raise ValueError("Require exactly the approved four roles")
    controls = {}
    for clip, expected in CONTROLS.items():
        path = card / "PRIVATE/M4ROOT/CLIP" / (clip + ".MP4")
        actual = digest(path)
        if actual != expected:
            raise ValueError("Existing playback control changed: " + clip)
        controls[clip] = {"sha256": actual, "unchanged": True,
                          "historical_playback": "USER_REPORTED_SUCCESS",
                          "current_round_playback": "NOT_TESTED"}
    result = {
        "experiment": "0029", "kind": "bitrate_diagnostic",
        "state": "PREPARED_FOR_PHYSICAL_TEST_NOT_YET_CAMERA_VERIFIED",
        "recorded_at_utc": datetime.now(timezone.utc).isoformat(), "card": str(card),
        "source": str(Path("Cat_25-12-25.mp4").resolve()),
        "source_sha256": digest("Cat_25-12-25.mp4"),
        "before_snapshot": str(before), "final_snapshot": str(after),
        "before_database_sha256": digest(before / "PRIVATE/DATABASE/DATABASE.BIN"),
        "final_database_sha256": digest(after / "PRIVATE/DATABASE/DATABASE.BIN"),
        "audit": str(Path(args.audit).resolve()), "audit_sha256": digest(args.audit),
        "regression": {"tests": int(regression[1]), "seconds": float(regression[2]),
                       "log": str(Path(args.regression_log).resolve()),
                       "log_sha256": digest(args.regression_log), "passed": True},
        "old_record_count": len(rows[0]), "final_record_count": len(rows[1]),
        "added_records": added, "all_old_records_bit_exact": True,
        "existing_controls": controls, "clips": clips,
        "test_order": ["C6520", "C6515"] + [row["clip"] for row in clips],
        "files_deleted": [], "existing_clip_assets_replaced": False,
        "scope": "PROF declaration isolation on identical 4M payload pairs; not proof of a universal minimum rate",
    }
    output.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({"output": str(output), "clips": [row["clip"] for row in clips],
                      "state": result["state"]}, indent=2))


if __name__ == "__main__":
    main()
