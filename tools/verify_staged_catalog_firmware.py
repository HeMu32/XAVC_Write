"""Purpose: verify staged catalogs using selected original firmware readers.

Usage: python tools/verify_staged_catalog_firmware.py --build PACKAGE
    [--firmware LIBMPR --expat LIBEXPAT].
Design: execute offline sidb conversion/readers and MediaProfile/Expat queries,
    then bind results to staged catalog and firmware hashes.
Scope: original read-side methods with explicit models, not a full card mount,
    Select/UI flow, hardware decoder or proof of camera listing/playback.
"""
import argparse
import hashlib
import json
from pathlib import Path
from xml.etree import ElementTree as ET

from emulate_mediapro import EXPAT_SHA256, MediaProfileEmulator
from emulate_sidb_converter import EXPECTED, RecordConverter
from sony_db import check_regions, inventory


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--build", required=True)
    ap.add_argument("--firmware", default="firmware/m4-v602/usr/lib/libmpr.so")
    ap.add_argument("--expat", default="firmware/m4-v602/usr/lib/libexpat.so.1.6.11")
    args = ap.parse_args()
    build, firmware, expat = [Path(x).resolve() for x in (args.build, args.firmware, args.expat)]
    transaction = json.loads((build / "catalog/transaction.json").read_text(encoding="utf-8"))
    snapshot = Path(transaction["snapshot"]).resolve()
    if any(p.drive.upper() == "F:" for p in (build, firmware, expat, snapshot)):
        raise ValueError("Only local staging and saved snapshots are allowed")
    db = (build / "catalog/DATABASE.BIN").read_bytes()
    xml = (build / "catalog/MEDIAPRO.XML").read_bytes()
    hashes = {"database": hashlib.sha256(db).hexdigest(), "mediapro": hashlib.sha256(xml).hexdigest()}
    if any(hashes[key] != transaction[key + "_after_sha256"] for key in hashes):
        raise ValueError("Staging no longer matches transaction")
    records = inventory(db)
    converter = RecordConverter(firmware)
    converter.load(db)
    converted = []
    for row in records:
        if row.get("content_type") == 2:
            result = converter.convert(row["index"])
            converted.append({"clip": f"C{row['clip_number']:04d}", **result})
    parser = MediaProfileEmulator(firmware, expat, snapshot, profile_override=xml)
    profile = parser.run()
    expected = {node.get("uri").rsplit("/", 1)[-1][:-4]: node.get("umid")
                for node in ET.fromstring(xml).iter() if node.tag.rsplit("}", 1)[-1] == "Material"}
    parsed = {row["clip"]: row for row in profile["materials"]}
    checks = {
        "all_header_checksums": all(row["valid"] for row in check_regions(db)),
        "all_nonroot_record_checksums": all(row["checksum_valid"] for row in records if row["index"]),
        "every_converter_and_called_nested_reader_succeeded": all(
            row["return_u32"] == 0 and all(x["return_u32"] == 0
                                          for x in row["original_reader_returns"]) for row in converted),
        "all_restored_main_paths_match_clip": all(
            row["restored_paths"]["main"] == f"A:/PRIVATE/M4ROOT/CLIP/{row['clip']}.MP4"
            for row in converted),
        "profile_initialized_and_loaded": profile["initialized_return"] == profile["load_return"] == 0,
        "exact_movie_sets_and_counts": (set(parsed) == set(expected) == {x["clip"] for x in converted}
                                       and len(profile["materials"]) == len(expected) == len(converted)),
        "all_original_profile_queries_and_umids_match": all(
            row["original_find_return"] == row["original_clip_info_return"] == 0 and
            row["umid_at_record_0a_hex"] == expected[clip] and
            row["clip_info_name"] == clip + ".MP4" for clip, row in parsed.items()),
        "original_executable_sections_unchanged": profile["original_executable_sections_unchanged"],
        "source_database_bytes_unchanged_in_emulator": bytes(
            converter.uc.mem_read(0x10000000, len(db))) == db,
    }
    report = {
        "build": str(build), "source_snapshot": str(snapshot), "staged_catalogs": True,
        "firmware_sha256": EXPECTED, "expat_sha256": EXPAT_SHA256, "hashes": hashes,
        "checks": checks, "passed": all(checks.values()), "conversions": converted, "profile": profile,
        "card_access": False, "camera_listing": "NOT_TESTED", "camera_playback": "NOT_TESTED",
        "scope": "Original record conversion and profile parsing, not mount/UI/decoder",
    }
    (build / "firmware-catalog-verification.json").write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps({"passed": report["passed"], "movies": len(converted), "checks": checks}, indent=2))
    if not report["passed"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
