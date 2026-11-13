"""Purpose: compare offline catalog evidence with explicit user observations.

Usage: python tools/catalog_listing_matrix.py --snapshot SNAP --converter REPORT
    --observations REPORT --output REPORT [--profile-parser REPORT].
Design: validate database/profile hash bindings before joining original-reader
    results, decoded catalog fields and non-exhaustive positive/negative examples.
Scope: local evidence classification only. Missing observations remain unknown;
    reader success is not proof of listing, thumbnails or camera playback.
"""
import argparse
import hashlib
import json
from collections import Counter
from pathlib import Path

from compare_sd_snapshots import db_view, mediapro, read_manifest


def build_matrix(snapshot, converter_report, observations, profile_report=None):
    data, records, movies = db_view(snapshot)
    digest = hashlib.sha256(data).hexdigest()
    cases = [case for case in converter_report["snapshots"] if case["database_sha256"] == digest]
    if not cases:
        raise ValueError("Original-converter report does not match this snapshot database hash")
    converted = {row["clip"]: row for row in cases[-1]["movies"]}
    parsed_materials = {}
    if profile_report is not None:
        profile_digest = hashlib.sha256((snapshot / "PRIVATE/M4ROOT/MEDIAPRO.XML").read_bytes()).hexdigest()
        if profile_report.get("profile_sha256") != profile_digest:
            raise ValueError("Original profile-parser report does not match snapshot XML hash")
        if profile_report.get("firmware_sha256") != converter_report.get("firmware_sha256"):
            raise ValueError("Parser/converter firmware identities differ")
        result = profile_report.get("result", {})
        if ("emulation_error" in profile_report or result.get("load_return") != 0 or
                result.get("original_executable_sections_unchanged") is not True):
            raise ValueError("Incomplete or modified-code profile-parser evidence")
        parsed_materials = {row["clip"]: row for row in result["materials"]}
    media = read_manifest(snapshot, "_skipped_media_manifest.csv")
    _, materials = mediapro(snapshot)
    positives = set(observations["current_listing_positive_examples_not_exhaustive"])
    negatives = set(observations["current_listing_negative_confirmed"])
    rows = []
    for number, movie in sorted(movies.items()):
        clip = f"C{number:04d}"
        record = bytes.fromhex(movie["record_hex"])
        result = converted[clip]
        if result["record_index"] != movie["record_index"]:
            raise ValueError("Converter record index mismatch")
        expected_paths = {"main": f"PRIVATE/M4ROOT/CLIP/{clip}.MP4",
                          "thumbnail": f"PRIVATE/M4ROOT/THMBNL/{clip}T01.JPG"}
        uri = f"./CLIP/{clip}.MP4"
        material = materials.get(uri)
        readers = result.get("original_reader_returns")
        rows.append({
            "clip": clip,
            "observed_listing": "listed" if clip in positives else
            "not_listed" if clip in negatives else "unknown_in_this_round",
            "record_index": movie["record_index"],
            "record_checksum_valid": records[movie["record_index"]]["checksum_valid"],
            "record_flags_byte06": hex(record[6]),
            "persistent_root_filter_bit4": bool(record[6] & 0x10),
            "persistent_bit3_semantics_not_established": bool(record[6] & 8),
            "runtime_onmem_flags": "UNKNOWN; not persisted in snapshot",
            "video_info_ref": movie["video_info_ref"],
            "umid_array_ref": movie["umid_array_ref"], "umid_array_slot": movie["umid_array_slot"],
            "sidecar": movie["sidecar"], "umid_evidence": movie["umid_evidence"],
            "material_present": material is not None,
            "material_attributes": material["attributes"] if material else None,
            "media_inventory": {name: media.get(path) for name, path in expected_paths.items()},
            "converter_return_u32": result.get("return_u32"),
            "converter_emulation_error": result.get("emulation_error"),
            "nested_reader_results_recorded": readers is not None,
            "nested_reader_failures": None if readers is None else
            [reader for reader in readers if reader["return_u32"]],
            "original_restored_paths": result.get("restored_paths"),
            "original_mediapro_parse_query": parsed_materials.get(clip),
            "original_mediapro_umid_matches_sidecar": (
                parsed_materials[clip]["umid_at_record_0a_hex"] == movie["sidecar"].get("umid")
                if clip in parsed_materials else None),
            "camera_admission_proven_by_emulation": False,
        })
    return {"snapshot": str(snapshot.resolve()), "database_sha256": digest, "card_access": False,
            "observations_source": "Direct user reports, non-exhaustive",
            "camera_body_used_for_playback": observations["camera_body_used_for_playback"],
            "installed_camera_firmware": observations["installed_camera_firmware"],
            "counts_by_observed_listing": dict(Counter(row["observed_listing"] for row in rows)),
            "scope": "Offline joins and original record conversion; not full playback UI",
            "root_cause_established": False, "movies": rows}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--snapshot", required=True)
    ap.add_argument("--converter", required=True)
    ap.add_argument("--observations", default="analysis/camera_observations_20261112_233331.json")
    ap.add_argument("--profile-parser", help="Optional completed original-parser report")
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    snapshot, converter, observations, output = [
        Path(value).resolve() for value in
        (args.snapshot, args.converter, args.observations, args.output)]
    if any(path.drive.upper() == "F:" for path in (snapshot, converter, observations, output)):
        raise ValueError("Only offline inputs and local output are allowed")
    if snapshot == output or snapshot in output.parents:
        raise ValueError("Do not modify a source snapshot")
    profile_report = None
    if args.profile_parser:
        parser = Path(args.profile_parser).resolve()
        if parser.drive.upper() == "F:":
            raise ValueError("Only offline reports are allowed")
        profile_report = json.loads(parser.read_text(encoding="utf-8"))
    report = build_matrix(snapshot, json.loads(converter.read_text(encoding="utf-8")),
                          json.loads(observations.read_text(encoding="utf-8")), profile_report)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(report["counts_by_observed_listing"], "root cause established", False)


if __name__ == "__main__":
    main()
