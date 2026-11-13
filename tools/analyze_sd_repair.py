"""Purpose: analyze a saved before/after SD database-repair pair.

Usage: python tools/analyze_sd_repair.py --before SNAP --after SNAP
    --converter REPORT --manifest BUILD_MANIFEST --output REPORT
    [--sdk-report REPORT --nrt-report REPORT --media-hashes REPORT].
Design: join snapshot checksums, decoded references, original-firmware reports,
    media hashes and an in-memory staging probe into a structured JSON report.
Scope: the observed Sony SD sidb layout and saved experiment artifacts only.
    No card writes, full repair emulation, CFexpress support or playback verdict.
"""
import argparse
from collections import Counter, defaultdict
from datetime import datetime
import hashlib
import json
from pathlib import Path
import struct
from xml.etree import ElementTree as ET

from compare_sd_snapshots import compare, db_view, read_manifest
from sony_umid import creation_time
from stage_sd_catalog import observed_minimal_records


def digest(data):
    return hashlib.sha256(data).hexdigest()


def verify_saved_metadata(snapshot):
    summary = json.loads((snapshot / "_snapshot.json").read_text(encoding="utf-8"))
    rows = read_manifest(snapshot, "_metadata_manifest.csv")
    errors = []
    for name, row in rows.items():
        path = (snapshot / name).resolve()
        if not path.is_relative_to(snapshot) or path == snapshot:
            raise ValueError("Saved metadata path escapes snapshot")
        data = path.read_bytes()
        if len(data) != int(row["size"]) or digest(data) != row["sha256"]:
            errors.append(name)
    return {"snapshot": str(snapshot), "metadata_files_checked": len(rows),
            "errors": errors, "passed": not errors and not summary["errors"] and
            len(rows) == summary["metadata_files"]}


def changed_ranges(a, b):
    if len(a) != len(b):
        raise ValueError("Changed ranges require equal allocation sizes")
    ranges = []
    for offset, (old, new) in enumerate(zip(a, b)):
        if old == new:
            continue
        if ranges and ranges[-1]["end_exclusive"] == offset:
            ranges[-1]["end_exclusive"] += 1
        else:
            ranges.append({"start": offset, "end_exclusive": offset + 1})
    return [{**row, "before_hex": a[row["start"]:row["end_exclusive"]].hex(),
             "after_hex": b[row["start"]:row["end_exclusive"]].hex()} for row in ranges]


def content_references(row):
    """Both content layouts, taken from ConvRecordInfo2RecordStructure."""
    raw = bytes.fromhex(row["hex"])
    kind = row.get("content_type")
    if row["type"] != 0 or kind not in (1, 2):
        return []
    flag_offset, path_offset = (0x5c, 0x50) if kind == 2 else (0x4c, 0x40)
    refs = []
    for field in range(4):
        ref = struct.unpack_from("<H", raw, path_offset + field * 2)[0]
        ref |= (raw[flag_offset] >> field & 1) << 16
        refs.append((f"path_{field}", ref, None))
    video_offset = 0x58 if kind == 2 else 0x48
    ref = struct.unpack_from("<H", raw, video_offset)[0]
    refs.append(("video" if kind == 2 else "audio",
                 ref | (raw[flag_offset] >> 4 & 1) << 16, None))
    umid_offset = 0x5a if kind == 2 else 0x4a
    ref = struct.unpack_from("<H", raw, umid_offset)[0]
    refs.append(("umid", ref | (raw[flag_offset] >> 5 & 1) << 16,
                 raw[flag_offset + 1] >> 4))
    if kind == 1:
        ref = struct.unpack_from("<H", raw, 0x58)[0]
        refs.append(("image_unique_id", ref | (raw[0x5a] >> 3 & 1) << 16,
                     raw[0x5a] >> 4))
        ref = struct.unpack_from("<H", raw, 0x6c)[0]
        refs.append(("photo_properties", ref | (raw[0x4c] >> 6 & 1) << 16, None))
    return [{"field": field, "reference": ref, "slot": slot}
            for field, ref, slot in refs if ref]


def reference_graph(records):
    owners = defaultdict(list)
    for index, row in records.items():
        for ref in content_references(row):
            owners[ref["reference"]].append({
                "record": index, "content_type": row["content_type"],
                "number": row["clip_number"], **ref})
        if row["type"] in (1, 2):
            next_record = struct.unpack_from("<I", bytes.fromhex(row["hex"]), 4)[0]
            if next_record not in (0, 0xffffffff):
                owners[next_record].append({"record": index, "field": "chain_next"})
    return owners


def array_inventory(records):
    owners = reference_graph(records)
    arrays, duplicate_groups = [], defaultdict(list)
    for index, row in records.items():
        if row["type"] != 3:
            continue
        raw = bytes.fromhex(row["hex"])
        subtype, length = raw[4:6]
        if length not in (16, 32):
            raise ValueError("Unmodeled array entry length")
        bitmap = struct.unpack_from("<H", raw, 6)[0]
        slots = []
        for slot in range(16):
            if not bitmap >> slot & 1:
                continue
            start = 12 + slot * length
            if start + length > 158:
                raise ValueError("Occupied array entry outside payload")
            payload = raw[start:start + length].hex()
            slot_owners = [owner for owner in owners[index] if owner.get("slot") == slot]
            slots.append({"slot": slot, "payload_hex": payload, "owners": slot_owners})
            duplicate_groups[(subtype, length, payload)].append({"record": index, "slot": slot})
        all_owners = [owner for owner in owners[index] if owner.get("slot") is not None]
        stored = struct.unpack_from("<I", raw, 8)[0]
        arrays.append({
            "record": index, "subtype": subtype, "entry_length": length,
            "slot_bitmap": hex(bitmap), "stored_reference_count": stored,
            "all_content_owner_count": len(all_owners),
            "reference_count_matches": stored == len(all_owners),
            "owners_point_to_occupied_slots": all(bitmap >> owner["slot"] & 1
                                                 for owner in all_owners),
            "slots": slots})
    return {"arrays": arrays, "duplicate_payload_groups": [
        {"subtype": key[0], "entry_length": key[1], "payload_hex": key[2], "locations": rows}
        for key, rows in duplicate_groups.items() if len(rows) > 1]}


def converter_views(path, views):
    report = json.loads(path.read_text(encoding="utf-8"))
    result = []
    for data, records, movies in views:
        matches = [row for row in report["snapshots"] if row["database_sha256"] == digest(data)]
        if len(matches) != 1:
            raise ValueError("Converter report is not uniquely bound to database hash")
        by_number = {int(row["clip"][1:]): row for row in matches[0]["movies"]}
        if set(by_number) != set(movies):
            raise ValueError("Converter movie set differs from snapshot")
        for number, row in by_number.items():
            if row["record_index"] != movies[number]["record_index"] or row.get("return_u32") != 0:
                raise ValueError("Converter result failed or record index differs")
        result.append(by_number)
    return result


def decoded_info(row):
    raw = bytes.fromhex(row["record_info_hex"])
    return {
        "video_present": raw[0x26], "audio_present": raw[0x94],
        "video_enums_28_to_40": list(struct.unpack_from("<7I", raw, 0x28)),
        "nominal_bitrate_u16_at_44": struct.unpack_from("<H", raw, 0x44)[0],
        "acquisition_enums_50_to_58": list(struct.unpack_from("<3I", raw, 0x50)),
        "audio_enums_98_to_a4": list(struct.unpack_from("<4I", raw, 0x98)),
        "ltc_little_endian_at_48": raw[0x48:0x50].hex(),
        "main_umid_at_4f8": raw[0x4f8:0x518].hex().upper(),
        "repair_fields_619_61a": list(raw[0x619:0x61b]),
    }


def xml_timecodes(path):
    root = ET.fromstring(path.read_bytes().rstrip(b" \x00"))
    values = [node.attrib for node in root.iter()
              if node.tag.rsplit("}", 1)[-1] == "LtcChange"]
    first = next((row["value"] for row in values if row.get("frameCount") == "0"), None)
    last = next((row["value"] for row in values if row.get("status") == "end"), None)
    return first, last


def minimal_template_probe(views, manifest_path):
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    # A free diagnostic number, never deployed; stage entirely in host memory.
    number = next(n for n in range(9999, -1, -1) if all(n not in view[2] for view in views))
    manifest["clip"] = f"C{number:04d}"
    updated = datetime.fromisoformat(manifest["stamp"])
    results = []
    for data, records, movies in views:
        try:
            staged, details = observed_minimal_records(data, manifest, 7, 1, 1, updated)
            result = {"accepted": True, "allocated_records": details["new_records"],
                      "output_sha256": digest(staged)}
        except ValueError as exc:
            result = {"accepted": False, "error": str(exc)}
        cursor = struct.unpack_from("<I", data, 0x7c44)[0]
        capacity = struct.unpack_from("<I", data, 0x44)[0]
        next_free = next(i for i in range(cursor + 1, capacity)
                         if not data[0x4000 + i // 8] >> (i % 8) & 1)
        result.update(database_sha256=digest(data), content_cursor=cursor,
                      maximum_active_record=max(records), next_free_after_cursor=next_free,
                      flags_18_movie_count=sum(bytes.fromhex(row["record_hex"])[6] == 0x18
                                              for row in movies.values()))
        results.append(result)
    return {"diagnostic_clip": manifest["clip"], "card_writes": False, "local_files_staged": False,
            "results": results,
            "expected_before_accept_after_refuse": (
                results[0]["accepted"] and not results[1]["accepted"] and
                "observed-minimal" in results[1].get("error", ""))}


def sdk_comparisons(paths, converters, movies, media_hashes):
    hashes = {row["relative_path"]: row["sha256"] for row in media_hashes["entries"]}
    comparisons = []
    for path in paths:
        report = json.loads(path.read_text(encoding="utf-8"))
        clip = Path(report["media"]).stem
        number = int(clip[1:])
        media_hash = hashes[f"PRIVATE/M4ROOT/CLIP/{clip}.MP4"]
        if report["media_sha256"] != media_hash:
            raise ValueError("SDK report is not bound to repaired-card media hash")
        raw = bytes.fromhex(report["result"]["movie_property_hex"])
        expected = list(struct.unpack_from("<7I", raw, 0xc))
        expected_rate = struct.unpack_from("<H", raw, 0x2c)[0]
        info = decoded_info(converters[number])
        comparisons.append({
            "clip": clip, "source_report": str(path), "source_report_sha256": digest(path.read_bytes()),
            "media_sha256": media_hash, "catalog_video_record": movies[number]["video_info_ref"],
            "property_video_enums": expected, "property_nominal_bitrate": expected_rate,
            "enums_match": expected == info["video_enums_28_to_40"],
            "bitrate_match": expected_rate == info["nominal_bitrate_u16_at_44"],
            "scope": "Original read-side property output versus repaired catalog conversion; not playback"})
    return comparisons


def analyze(before, after, converter, manifest, sdk_paths=(), media_hashes_path=None,
            nrt_paths=()):
    snapshot_checks = [verify_saved_metadata(root) for root in (before, after)]
    if not all(row["passed"] for row in snapshot_checks):
        raise ValueError("Saved snapshot metadata no longer matches capture manifests")
    views = [db_view(root) for root in (before, after)]
    cmp = compare(before, after)
    conversions = converter_views(converter, views)
    a, ar, am = views[0]
    b, br, bm = views[1]
    if set(am) != set(bm):
        raise ValueError("This analyzer expects preserved movie membership")
    modified = [i for i in ar.keys() & br.keys() if ar[i]["hex"] != br[i]["hex"]]
    transitions = Counter()
    movies = []
    for number in sorted(am):
        old, new = am[number], bm[number]
        oldraw, newraw = [bytes.fromhex(row["record_hex"]) for row in (old, new)]
        info = decoded_info(conversions[1][number])
        first, last = xml_timecodes(after / f"PRIVATE/M4ROOT/CLIP/C{number:04d}M01.XML")
        evidence = new["umid_evidence"]
        transitions[(oldraw[6], newraw[6])] += 1
        movies.append({
            "clip": f"C{number:04d}", "record": new["record_index"],
            "record_changed": oldraw != newraw, "changed_record_ranges": changed_ranges(oldraw, newraw),
            "flags_before_after": [hex(oldraw[6]), hex(newraw[6])],
            "video_record_before_after": [old["video_info_ref"], new["video_info_ref"]],
            "creation_before_after": [creation_time(raw).isoformat() for raw in (oldraw, newraw)],
            "sidecar_creation": new["sidecar"].get("creation"),
            "main_umid_converter_matches_independent_restore":
                info["main_umid_at_4f8"] == new["restored_umid"],
            "umid_evidence": evidence,
            "ltc_start_xml": first, "ltc_end_xml": last,
            "ltc_start_matches_xml": newraw[0x40:0x44][::-1].hex().upper() == first if first else None,
            "ltc_end_matches_xml": newraw[0x44:0x48][::-1].hex().upper() == last if last else None,
            "before_info": decoded_info(conversions[0][number]), "after_info": info,
            "post_repair_camera_observation": None})
    photo_transitions = Counter()
    for index in modified:
        if ar[index].get("content_type") == 1:
            old, new = [bytes.fromhex(rows[index]["hex"]) for rows in (ar, br)]
            photo_transitions[(old[6], new[6])] += 1
    owners = reference_graph(br)
    supports = []
    reference_payload = bytes.fromhex(br[bm[6515]["video_info_ref"]]["hex"])[10:50]
    for index in sorted({row["video_info_ref"] for row in bm.values()}):
        payload = bytes.fromhex(br[index]["hex"])[10:50]
        supports.append({
            "record": index, "payload_hex": payload.hex(),
            "movie_owners": [f"C{n:04d}" for n, row in bm.items() if row["video_info_ref"] == index],
            "payload_diff_vs_C6515_support": changed_ranges(reference_payload, payload)})
    checks = {
        "only_database_metadata_changed": cmp["metadata"] == {
            "added": [], "removed": [], "changed": ["PRIVATE/DATABASE/DATABASE.BIN"]},
        "media_size_mtime_unchanged": cmp["media_size_mtime_inventory"] == {
            "added": [], "removed": [], "changed": []},
        "movie_membership_preserved": set(am) == set(bm),
        "all_movie_umids_match_original_converter": all(
            row["main_umid_converter_matches_independent_restore"] for row in movies),
        "array_reference_counts_match_all_content_owners": all(
            row["reference_count_matches"] and row["owners_point_to_occupied_slots"]
            for row in array_inventory(br)["arrays"]),
    }
    sdk = []
    if sdk_paths:
        if media_hashes_path is None:
            raise ValueError("Hash-bound SDK comparisons require media hash inventory")
        sdk = sdk_comparisons(sdk_paths, conversions[1], bm,
                              json.loads(media_hashes_path.read_text(encoding="utf-8")))
        checks["selected_sdk_properties_match_repaired_catalog"] = all(
            row["enums_match"] and row["bitrate_match"] for row in sdk)
    nrt = []
    if nrt_paths:
        if media_hashes_path is None:
            raise ValueError("Hash-bound NRT comparisons require media hash inventory")
        media_hashes = json.loads(media_hashes_path.read_text(encoding="utf-8"))
        media_hashes = {row["relative_path"]: row["sha256"] for row in media_hashes["entries"]}
        for path in nrt_paths:
            row = json.loads(path.read_text(encoding="utf-8"))
            matching = [name for name, value in media_hashes.items()
                        if value == row["media_sha256"] and name.endswith(".MP4")]
            if len(matching) != 1 or not row["passed"]:
                raise ValueError("NRT report failed or is not uniquely bound to repaired media")
            name = Path(matching[0]).stem
            sidecar = (after / f"PRIVATE/M4ROOT/CLIP/{name}M01.XML").read_bytes()
            xml = row["original_scanner_xml"].encode("utf-8")
            nrt.append({
                "clip": name, "report": str(path), "report_sha256": digest(path.read_bytes()),
                "media_sha256": row["media_sha256"], "xml_sha256": row["xml_sha256"],
                "scanner_output_hash_valid": digest(xml) == row["xml_sha256"],
                "scanner_xml_matches_saved_sidecar_ignoring_padding":
                    xml.rstrip(b" \0") == sidecar.rstrip(b" \0")})
        checks["selected_nrt_original_scans_match_saved_metadata"] = all(
            row["scanner_output_hash_valid"] and
            row["scanner_xml_matches_saved_sidecar_ignoring_padding"] for row in nrt)
    probe = minimal_template_probe(views, manifest)
    checks["current_minimal_stager_refuses_repaired_template"] = probe[
        "expected_before_accept_after_refuse"]
    return {
        "before": str(before), "after": str(after), "card_access": False,
        "saved_snapshot_integrity": snapshot_checks,
        "before_database_sha256": digest(a), "after_database_sha256": digest(b),
        "checks": checks, "passed": all(checks.values()),
        "metadata_diff": cmp["metadata"], "media_inventory_diff": cmp["media_size_mtime_inventory"],
        "changed_database_bytes": sum(x != y for x, y in zip(a, b)),
        "database_header_changed_ranges": changed_ranges(a[:0x10000], b[:0x10000]),
        "active_record_counts": [len(ar), len(br)],
        "record_type_counts": [dict(Counter(row["type"] for row in rows.values())) for rows in (ar, br)],
        "added_records": [{k: v for k, v in br[i].items() if k != "hex"}
                          for i in sorted(br.keys() - ar.keys())],
        "modified_existing_record_counts": {
            "movie": sum(ar[i].get("content_type") == 2 for i in modified),
            "photo": sum(ar[i].get("content_type") == 1 for i in modified),
            "array": sum(ar[i]["type"] == 3 for i in modified)},
        "flag_transitions_movies": [{"before": hex(a), "after": hex(b), "count": n}
                                   for (a, b), n in transitions.items()],
        "flag_transitions_modified_photos": [{"before": hex(a), "after": hex(b), "count": n}
                                            for (a, b), n in photo_transitions.items()],
        "movies": movies,
        "umid_summary": {
            "exact": [row["clip"] for row in movies if row["umid_evidence"]["exact_match"]],
            "explained_by_omitted_subseconds_including_exact": [
                row["clip"] for row in movies if row["umid_evidence"]["explained_by_omitted_subseconds"]],
            "unexplained_by_subsecond_loss": [
                row["clip"] for row in movies if not row["umid_evidence"]["exact_match"] and
                not row["umid_evidence"]["explained_by_omitted_subseconds"]],
            "non_time_bytes_match_all": all(row["umid_evidence"]["non_time_bytes_match"]
                                            for row in movies)},
        "array_graph_before": array_inventory(ar), "array_graph_after": array_inventory(br),
        "video_supports_after": supports,
        "empty_video_record_28": {
            "still_active": 28 in br, "unchanged": ar[28]["hex"] == br[28]["hex"],
            "known_incoming_references_after": owners[28],
            "scope": "No incoming reference in decoded content/path/binary layouts; not proof of garbage collection"},
        "minimal_template_probe": probe, "sdk_property_comparisons": sdk,
        "embedded_nrt_comparisons": nrt,
        "scope": "Saved metadata, original converter reports and hash-bound prior SDK outputs. No new camera playback verdict.",
    }


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--before", required=True)
    ap.add_argument("--after", required=True)
    ap.add_argument("--converter", required=True)
    ap.add_argument("--manifest", required=True)
    ap.add_argument("--sdk-report", action="append", default=[])
    ap.add_argument("--nrt-report", action="append", default=[])
    ap.add_argument("--media-hashes")
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    paths = [Path(value).resolve() for value in
             (args.before, args.after, args.converter, args.manifest, args.output)]
    if any(path.drive.upper() == "F:" for path in paths):
        raise ValueError("Use saved snapshots and local output only")
    if any(root == paths[4] or root in paths[4].parents for root in paths[:2]):
        raise ValueError("Cannot write into source snapshots")
    sdk = [Path(path).resolve() for path in args.sdk_report]
    nrt = [Path(path).resolve() for path in args.nrt_report]
    hashes = Path(args.media_hashes).resolve() if args.media_hashes else None
    if any(path.drive.upper() == "F:" for path in sdk + nrt + ([hashes] if hashes else [])):
        raise ValueError("Use local saved reports only")
    report = analyze(*paths[:4], sdk, hashes, nrt)
    paths[4].parent.mkdir(parents=True, exist_ok=True)
    paths[4].write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps({key: report[key] for key in
                      ("passed", "checks", "modified_existing_record_counts", "umid_summary")}, indent=2))
    if not report["passed"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
