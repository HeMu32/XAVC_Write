"""Analyze the second repair after C0010 playback, without writing to the card.

Usage: python tools/analyze_repair_0033.py --card F:/ --output REPORT.json.
Inputs are the saved 0032/0033 snapshots and original-converter evidence.
Media are hashed against preserved references; other media use size/mtime only.
This episode-specific report does not establish post-repair UI/playback results.
"""
import argparse
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import struct

from analyze_sd_repair import (
    array_inventory, converter_views, decoded_info, sdk_comparisons,
    verify_saved_metadata, xml_timecodes,
)
from audit_card_snapshot import audit
from compare_sd_snapshots import compare, db_view


ROOT = Path(__file__).resolve().parents[1]
BEFORE = "backup/snap_20261114T011354"
AFTER = "backup/snap_20261114T013129"
CONVERTER = "analysis/0033-original-converter.json"
FEEDBACK = "analysis/camera-observations-0032-result.json"
REFERENCES = {
    "C0007": "analysis/C0007-reference-0023.MP4",
    "C0010": "output/mux-0032-29/A/C0010.MP4",
    "C6501": "analysis/C6501-reference-0028.MP4",
    "C6519": "output/profiles-0028-hd50-2997/package/C6519.MP4",
    "C6520": "output/repair-0031/C6520/C6520.MP4",
    "C6521": "output/repair-0031/C6521/C6521.MP4",
    "C6522": "output/bitrate-0029-29/B/C6522.MP4",
    "C6523": "output/bitrate-0029-59/A/C6523.MP4",
    "C6524": "output/bitrate-0029-59/B/C6524.MP4",
}
SDK_REPORTS = [
    "analysis/0032-reader-C0010.json",
    "analysis/0031-reader-C6520-staged.json",
    "analysis/0031-reader-C6521-staged.json",
]


def digest(path):
    with path.open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def movie_transitions(before, after):
    """Clip membership and slot membership are distinct; shared arrays may grow."""
    rows = []
    for number in sorted(before.keys() | after.keys()):
        old, new = before.get(number), after.get(number)
        if old and new:
            if (old["record_hex"] == new["record_hex"] and
                    old["record_index"] == new["record_index"]):
                continue
            status = ("RELOCATED" if old["record_index"] != new["record_index"]
                      else "UPDATED_IN_PLACE")
        else:
            status = "ADDED" if new else "REMOVED"
        rows.append({
            "clip": f"C{number:04d}", "status": status,
            "record_before": old["record_index"] if old else None,
            "record_after": new["record_index"] if new else None,
            "flags_before_after": [
                hex(bytes.fromhex(row["record_hex"])[6]) if row else None
                for row in (old, new)],
            "video_reference_before_after": [
                row["video_info_ref"] if row else None for row in (old, new)],
            "umid_reference_before_after": [
                row["umid_array_ref"] if row else None for row in (old, new)],
            "post_repair_physical_listing": None,
            "post_repair_physical_playback": None,
        })
    return rows


def analyze(card):
    before, after = ROOT / BEFORE, ROOT / AFTER
    integrity = [verify_saved_metadata(path) for path in (before, after)]
    views = [db_view(path) for path in (before, after)]
    comparison = compare(before, after)
    conversions = converter_views(ROOT / CONVERTER, views)
    converter = json.loads((ROOT / CONVERTER).read_text(encoding="utf-8"))
    changes = movie_transitions(views[0][2], views[1][2])
    selected = []
    for clip, name in REFERENCES.items():
        relative = f"PRIVATE/M4ROOT/CLIP/{clip}.MP4"
        reference, current = ROOT / name, card / relative
        saved_hash, current_hash = digest(reference), digest(current)
        selected.append({
            "clip": clip, "relative_path": relative,
            "reference": name, "reference_sha256": saved_hash,
            "sha256": current_hash, "matches_reference": saved_hash == current_hash,
        })
    sdk = sdk_comparisons([ROOT / path for path in SDK_REPORTS],
                          conversions[1], views[1][2], {"entries": selected})
    completion = []
    for number in (10, 6520, 6521):
        movie = views[1][2][number]
        raw = bytes.fromhex(movie["record_hex"])
        first, last = xml_timecodes(after / f"PRIVATE/M4ROOT/CLIP/C{number:04d}M01.XML")
        info = decoded_info(conversions[1][number])
        completion.append({
            "clip": f"C{number:04d}",
            "original_converter": info,
            "umid_array": movie["umid_array_ref"],
            "umid_slot": movie["umid_array_slot"],
            "catalog_umid_matches_original_converter":
                movie["restored_umid"] == info["main_umid_at_4f8"],
            "catalog_umid_equals_xml": movie["umid_matches_sidecar"],
            "non_time_identity_bytes_match_xml":
                movie["umid_evidence"]["non_time_bytes_match"],
            "identity_scope": "Firmware reconstructs time bytes; UUID-style XML material bytes need not be identical. Not evidence of rejection.",
            "xml_first_last_timecodes": [first, last],
            "catalog_first_last_timecodes": [
                raw[0x40:0x44][::-1].hex().upper(),
                raw[0x44:0x48][::-1].hex().upper()],
            "timecodes_match_xml": (
                raw[0x40:0x44][::-1].hex().upper() == first and
                raw[0x44:0x48][::-1].hex().upper() == last),
        })
    graph = array_inventory(views[1][1])
    state = audit(card, after)
    checks = {
        "saved_snapshot_metadata_intact": all(row["passed"] for row in integrity),
        "live_card_matches_new_snapshot": state["unchanged"],
        "only_database_metadata_changed": comparison["metadata"] == {
            "added": [], "removed": [], "changed": ["PRIVATE/DATABASE/DATABASE.BIN"]},
        "media_size_mtime_inventory_unchanged": comparison["media_size_mtime_inventory"] == {
            "added": [], "removed": [], "changed": []},
        "all_58_movie_numbers_preserved":
            set(views[0][2]) == set(views[1][2]) and len(views[1][2]) == 58,
        "mediapro_all_materials_unchanged":
            not any(comparison["mediapro"][key]
                    for key in ("added", "removed", "modified_existing")) and
            comparison["mediapro"]["before_material_count"] == 58 and
            comparison["mediapro"]["after_material_count"] == 58,
        "header_and_active_record_checksums_valid": all(
            comparison["database"][key] for key in (
                "before_header_checksums_pass", "after_header_checksums_pass",
                "non_root_record_checksums_pass")),
        "selected_nine_full_media_hashes_match_references":
            len(selected) == 9 and all(row["matches_reference"] for row in selected),
        "original_converter_all_116_records_return_zero": all(
            len(snapshot["movies"]) == 58 and
            all(row.get("return_u32") == 0 and "emulation_error" not in row
                for row in snapshot["movies"]) for snapshot in converter["snapshots"]),
        "all_after_conversion_labels_unknown":
            all(row["observed_listing"] == "unknown_in_this_round"
                for row in converter["snapshots"][1]["movies"]),
        "selected_sdk_properties_match_completed_catalog": all(
            row["enums_match"] and row["bitrate_match"] for row in sdk),
        "completed_timecodes_and_identities_match_original_readers": all(
            row["timecodes_match_xml"] and row["catalog_umid_matches_original_converter"]
            and row["non_time_identity_bytes_match_xml"] for row in completion),
        "array_reference_counts_and_occupied_slots_valid": all(
            row["reference_count_matches"] and row["owners_point_to_occupied_slots"]
            for row in graph["arrays"]),
    }
    db = comparison["database"]
    return {
        "episode": "0033", "checked_at_utc": datetime.now(timezone.utc).isoformat(),
        "before_snapshot": BEFORE, "after_snapshot": AFTER,
        "card_writes": False, "card_deletions": False,
        "checks": checks, "passed": all(checks.values()),
        "saved_snapshot_integrity": integrity,
        "live_card_audit": state, "selected_media": selected,
        "database": {key: db[key] for key in (
            "before_sha256", "after_sha256", "changed_byte_count",
            "active_records_before", "active_records_after",
            "activated_record_indices", "deactivated_record_indices",
            "modified_record_indices")},
        "movie_count_before_after": [len(view[2]) for view in views],
        "header_movie_counts": [
            struct.unpack_from("<I", view[0], 0x7c88)[0] for view in views],
        "movie_transitions": changes, "completed_movies": completion,
        "selected_sdk_comparisons": sdk, "array_inventory_after": graph,
        "bound_reports_sha256": {
            name: digest(ROOT / name) for name in (
                CONVERTER, FEEDBACK, "analysis/camera-test-round-0032.json",
                "analysis/0033-repair-snapshot-diff.json")},
        "conclusion": "C0010/C6520/C6521 retained and populated; C6522 relocated to a new sparse slot, not removed from clip membership. No new physical post-repair UI/playback verdict.",
        "scope": "Metadata hashes, all active records, original converter and nine selected full MP4 hashes. Other media use membership/size/mtime. No full repair emulation or hardware decoding.",
    }


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--card", default="F:/")
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    card, output = Path(args.card).resolve(), Path(args.output).resolve()
    if output == card or card in output.parents or output.is_relative_to(ROOT / "backup"):
        raise ValueError("Report must stay off the card and outside snapshots")
    report = analyze(card)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps({"passed": report["passed"], "checks": report["checks"],
                      "movie_transitions": report["movie_transitions"]}, indent=2))
    if not report["passed"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
