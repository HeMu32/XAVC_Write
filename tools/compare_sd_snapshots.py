"""Purpose: compare two saved Sony SD snapshots and their catalog records.

Usage: python tools/compare_sd_snapshots.py BEFORE_SNAPSHOT AFTER_SNAPSHOT
    --output REPORT.json.
Design: compare metadata hashes, skipped-media size/mtime, MEDIAPRO semantics,
    checksums, active records, references and independently restored UMIDs.
Scope: local snapshots in the observed SD layout. Media contents were skipped,
    and differences alone do not prove a cause or camera playback behavior.
"""
import argparse
import csv
import hashlib
import json
import re
import struct
from pathlib import Path
from xml.etree import ElementTree as ET

from sony_db import check_regions, inventory
from sony_umid import restore_umid
from sd_catalog_evidence import header_time, restore_path_template, umid_evidence


def read_manifest(root, name):
    with (root / name).open(encoding="utf-8-sig", newline="") as stream:
        return {row["relative_path"]: row for row in csv.DictReader(stream)}


def manifest_diff(before, after, media=False):
    keys = ("size", "last_write_time_ns") if media else ("sha256",)
    return {"added": sorted(after.keys() - before.keys()),
            "removed": sorted(before.keys() - after.keys()),
            "changed": [name for name in sorted(before.keys() & after.keys())
                        if any(before[name][key] != after[name][key] for key in keys)]}


def byte_changes(before, after):
    return [{"offset": hex(i), "before": a, "after": b}
            for i, (a, b) in enumerate(zip(before, after)) if a != b]


def sidecar(path):
    root = ET.fromstring(path.read_bytes().rstrip(b" \x00"))
    def first(local):
        return next((node.attrib for node in root.iter()
                     if node.tag.rsplit("}", 1)[-1] == local), {})
    return {"umid": first("TargetMaterial").get("umidRef"),
            "duration": first("Duration").get("value"),
            "creation": first("CreationDate").get("value"),
            "device_model": first("Device").get("modelName"),
            "video": first("VideoFrame"), "audio": first("AudioFormat"),
            "recording_mode": first("RecordingMode")}


def db_view(root):
    path = root / "PRIVATE/DATABASE/DATABASE.BIN"
    data = path.read_bytes()
    records = {row["index"]: row for row in inventory(data)}
    movies = {}
    for index, row in records.items():
        if row.get("content_type") != 2:
            continue
        record = bytes.fromhex(row["hex"])
        number = row["clip_number"]
        array_id = struct.unpack_from("<H", record, 0x5a)[0] | ((record[0x5c] >> 5 & 1) << 16)
        video = records.get(row["video_info_ref"])
        array = records.get(array_id)
        xml = root / f"PRIVATE/M4ROOT/CLIP/C{number:04d}M01.XML"
        meta = sidecar(xml) if xml.is_file() else {}
        try:
            restored = restore_umid(record, bytes.fromhex(array["hex"])).hex().upper() if array else None
            evidence = (umid_evidence(record, bytes.fromhex(array["hex"]), meta["umid"])
                        if array and meta.get("umid") else None)
            error = None
        except (ValueError, OverflowError) as exc:
            restored, evidence, error = None, None, str(exc)
        paths, path_errors = [], []
        for field, ref in enumerate(row["path_refs"]):
            ref |= (record[0x5c] >> field & 1) << 16
            if not ref:
                paths.append(None)
                continue
            try:
                paths.append(restore_path_template(records, ref).replace("C****", f"C{number:04d}"))
            except (ValueError, UnicodeError) as exc:
                paths.append(None)
                path_errors.append(str(exc))
        movies[number] = {
            "record_index": index, "record_hex": row["hex"], "sidecar": meta,
            "path_refs": row["path_refs"], "video_info_ref": row["video_info_ref"],
            "video_info_hex": video["hex"] if video else None,
            "umid_array_ref": array_id, "umid_array_slot": record[0x5d] >> 4,
            "umid_array_hex": array["hex"] if array else None,
            "restored_umid": restored, "umid_restore_error": error,
            "umid_matches_sidecar": restored == meta.get("umid") if restored else False,
            "umid_evidence": evidence,
            "restored_paths": paths, "path_errors": path_errors,
            "video_parameter_payload": video["hex"][20:100] if video else None,
            "word04": hex(struct.unpack_from("<H", record, 4)[0]),
            "load_count_condition": bool(struct.unpack_from("<H", record, 4)[0] & 0xfffe),
            "u32_08": hex(struct.unpack_from("<I", record, 8)[0]),
            "u32_0c": hex(struct.unpack_from("<I", record, 0xc)[0]),
        }
    return data, records, movies


def mediapro(root):
    tree = ET.fromstring((root / "PRIVATE/M4ROOT/MEDIAPRO.XML").read_bytes())
    def semantic(node):
        return {"tag": node.tag.rsplit("}", 1)[-1], "attributes": node.attrib,
                "children": [semantic(child) for child in node]}
    return tree.attrib, {
        node.get("uri"): semantic(node) for node in tree.iter()
        if node.tag.rsplit("}", 1)[-1] == "Material"}


def compare(before, after):
    bm, am = [read_manifest(root, "_metadata_manifest.csv") for root in (before, after)]
    bv, av = [read_manifest(root, "_skipped_media_manifest.csv") for root in (before, after)]
    metadata = manifest_diff(bm, am)
    media = manifest_diff(bv, av, media=True)
    a, ar, ac = db_view(before)
    b, br, bc = db_view(after)
    added = sorted(br.keys() - ar.keys())
    removed = sorted(ar.keys() - br.keys())
    changed = [index for index in sorted(ar.keys() & br.keys())
               if ar[index]["hex"] != br[index]["hex"]]
    header = [{"offset": hex(offset), "before": struct.unpack_from("<I", a, offset)[0],
               "after": struct.unpack_from("<I", b, offset)[0]}
              for offset in range(0, 0x10000, 4) if a[offset:offset + 4] != b[offset:offset + 4]]
    bmp, bmats = mediapro(before)
    amp, amats = mediapro(after)
    arrays = []
    for index, row in br.items():
        if row["type"] != 3:
            continue
        raw = bytes.fromhex(row["hex"])
        if raw[4:6] != b"\x02\x20":
            continue
        bitmap = struct.unpack_from("<H", raw, 6)[0]
        references = [{"clip_number": number, "slot": movie["umid_array_slot"]}
                      for number, movie in bc.items() if movie["umid_array_ref"] == index]
        arrays.append({"index": index, "slot_bitmap": bitmap,
                       "stored_reference_count": struct.unpack_from("<I", raw, 8)[0],
                       "movie_references": references,
                       "occupied_slots": {slot: raw[12 + slot * 32:44 + slot * 32].hex()
                                          for slot in range(4) if bitmap >> slot & 1}})
    templates = {}
    for number in (8, 9):
        if number not in bc or 6502 not in bc:
            continue
        own, native = [bytes.fromhex(bc[n]["video_info_hex"]) for n in (number, 6502)]
        templates[number] = byte_changes(own[10:50], native[10:50])
    return {
        "before": str(before), "after": str(after), "card_writes": False,
        "metadata": metadata, "media_size_mtime_inventory": media,
        "new_sidecars": {Path(path).name: sidecar(after / path) for path in metadata["added"]
                         if re.fullmatch(r"C\d{4}M01\.XML", Path(path).name)},
        "mediapro": {
            "before_root_attributes": bmp, "after_root_attributes": amp,
            "before_material_count": len(bmats), "after_material_count": len(amats),
            "added": sorted(amats.keys() - bmats.keys()),
            "removed": sorted(bmats.keys() - amats.keys()),
            "modified_existing": [uri for uri in sorted(bmats.keys() & amats.keys())
                                  if bmats[uri] != amats[uri]],
        },
        "database": {
            "before_sha256": hashlib.sha256(a).hexdigest(),
            "after_sha256": hashlib.sha256(b).hexdigest(),
            "before_bytes": len(a), "after_bytes": len(b),
            "changed_byte_count": sum(x != y for x, y in zip(a, b)),
            "before_header_checksums_pass": all(x["valid"] for x in check_regions(a)),
            "after_header_checksums_pass": all(x["valid"] for x in check_regions(b)),
            "active_records_before": len(ar), "active_records_after": len(br),
            "activated_record_indices": added, "deactivated_record_indices": removed,
            "modified_record_indices": changed,
            "header_changed_u32": header,
            "header_times_before": {hex(p): header_time(a, p) for p in (0x8010, 0x8018)},
            "header_times_after": {hex(p): header_time(b, p) for p in (0x8010, 0x8018)},
            "non_root_record_checksums_pass": all(row["checksum_valid"]
                                                  for index, row in br.items() if index),
            "umid_arrays_after": arrays,
            "candidate_video_payload_diffs_vs_C6502": {
                "offset_basis": "40-byte video parameter payload (record+10)",
                "clips": templates},
            "new_records": [br[index] for index in added],
            "modified_records": [{"index": index, "before": ar[index], "after": br[index],
                                  "byte_changes": byte_changes(bytes.fromhex(ar[index]["hex"]),
                                                               bytes.fromhex(br[index]["hex"]))}
                                 for index in changed],
            "movies_before": ac, "movies_after": bc,
        },
    }


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("before")
    ap.add_argument("after")
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    before, after, out = [Path(value).resolve() for value in
                          (args.before, args.after, args.output)]
    if any(root == out or root in out.parents for root in (before, after)):
        raise ValueError("Report must not modify a source snapshot")
    report = compare(before, after)
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(report, indent=2), encoding="utf-8")
    db = report["database"]
    print(json.dumps({key: report[key] for key in
                      ("metadata", "media_size_mtime_inventory", "new_sidecars")}, indent=2))
    print("DB active", db["active_records_before"], "->", db["active_records_after"],
          "activated", db["activated_record_indices"], "modified", db["modified_record_indices"],
          "deactivated", db["deactivated_record_indices"])
    print("header changed words", db["header_changed_u32"])


if __name__ == "__main__":
    main()
