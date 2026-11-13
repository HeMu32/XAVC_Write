"""Purpose: stage an additive Sony SD catalog transaction in a local build.

Usage: python tools/stage_sd_catalog.py --snapshot FRESH_SNAP --build PACKAGE
    --template-number NUMBER --catalog-representation MODE.
Design: validate observed record forms, allocate free bitmap slots, maintain
    references/checksums and add a MEDIAPRO material with a hash-bound transaction.
Scope: modeled native_reuse/observed_minimal SD forms, not card deployment.
    Repair-populated C0007 is not a sparse template. An explicit historical
    template may be used only with identical live support/path dependencies;
    allocation always uses the fresh database. CFexpress is unsupported.
"""
import argparse
import hashlib
import json
import struct
from datetime import datetime
from pathlib import Path
from xml.etree import ElementTree as ET

from build_sony_clip import MPF, timecode
from sony_db import check_regions, checksum, fix_checksums, inventory
from sony_profiles import DEFAULT_PROFILE, manifest_profile


def digest(data):
    return hashlib.sha256(data).hexdigest()


def record_checksum(record):
    struct.pack_into("<H", record, 158, checksum(bytes(record[:158]), 0xFFF1))


def set_date(record, offset, stamp):
    packed = ((stamp.year - 1900) & 255) << 36 | stamp.month << 32 | stamp.day << 27
    packed |= stamp.hour << 22 | stamp.minute << 16 | stamp.second << 10
    packed |= stamp.microsecond // 1000
    tz_half_hours = int(stamp.utcoffset().total_seconds() / 1800)
    old = struct.unpack_from("<I", record, offset)[0]
    high = (old & 0xFF000001) | (((packed >> 32) & 0xFFF) << 12)
    high |= (tz_half_hours & 127) << 1
    struct.pack_into("<II", record, offset, high, packed & 0xFFFFFFFF)


def packed_header_time(stamp):
    tz = int(stamp.utcoffset().total_seconds() / 1800)
    return (((tz + 0x60) & 255) << 44 | (stamp.year - 1900) << 36 |
            stamp.month << 32 | stamp.day << 27 | stamp.hour << 22 |
            stamp.minute << 16 | stamp.second << 10 | stamp.microsecond // 1000)


def acquisition_bytes(manifest):
    value = manifest.get("acquisition", "unspecified")
    if value == "rec709":
        return bytes.fromhex("353103")
    if value == "unspecified":
        return bytes(3)
    raise ValueError("Unsupported acquisition mapping")


def catalog_profile(manifest, representation):
    profile = manifest_profile(manifest)
    if representation == "native_reuse" and profile.name != DEFAULT_PROFILE:
        raise ValueError("native_reuse only supports hd25_5994; use observed_minimal for other profiles")
    return profile


def material_attributes(manifest):
    profile = manifest_profile(manifest)
    clip = manifest["clip"]
    return {
        "uri": f"./CLIP/{clip}.MP4", "type": "MP4", "videoType": profile.video_codec,
        "audioType": "LPCM16", "fps": profile.xml_fps, "dur": str(manifest["frames"]),
        "ch": "2", "aspectRatio": "16:9", "offset": "0",
        "umid": manifest["umid"], "status": "none",
    }


def minimal_template_data(old, template_snapshot=None, expected_hash=None):
    if template_snapshot is None:
        if expected_hash is not None:
            raise ValueError("Historical template hash has no source snapshot")
        return old
    snapshot = Path(template_snapshot).resolve()
    if snapshot.drive.upper() == "F:" or not (snapshot / "_snapshot.json").is_file():
        raise ValueError("Historical template requires a saved local snapshot")
    summary = json.loads((snapshot / "_snapshot.json").read_text(encoding="utf-8"))
    if summary["errors"]:
        raise ValueError("Historical template snapshot has errors")
    path = (snapshot / "PRIVATE/DATABASE/DATABASE.BIN").resolve()
    if not path.is_relative_to(snapshot):
        raise ValueError("Historical template leaves its snapshot")
    data = path.read_bytes()
    if expected_hash is not None and digest(data) != expected_hash:
        raise ValueError("Historical template database hash changed")
    if not all(row["valid"] for row in check_regions(data)) or any(
            not row["checksum_valid"] for row in inventory(data) if row["index"]):
        raise ValueError("Historical template database checksum failure")
    return data


def minimal_template_records(old, source, template_number):
    rows, source_rows = [inventory(data) for data in (old, source)]
    template = next(r for r in source_rows if r.get("content_type") == 2 and
                    r["clip_number"] == template_number)
    movie = bytes.fromhex(template["hex"])
    current = {row["index"]: row for row in rows}
    originals = {row["index"]: row for row in source_rows}
    support = originals[template["video_info_ref"]]
    if source is old:
        return template, support
    dependencies = [ref | ((movie[0x5c] >> field & 1) << 16)
                    for field, ref in enumerate(template["path_refs"])]
    dependencies.append(template["video_info_ref"])
    for reference in filter(None, dependencies):
        seen = set()
        while reference != 0xffffffff:
            if reference in seen or reference not in originals or reference not in current:
                raise ValueError("Historical template dependency missing or cyclic")
            seen.add(reference)
            support = originals[reference]
            if support["hex"] != current[reference]["hex"]:
                raise ValueError("Historical template dependency differs from fresh database")
            if support["type"] not in (1, 2):
                raise ValueError("Unexpected historical template dependency type")
            reference = struct.unpack_from("<I", bytes.fromhex(support["hex"]), 4)[0]
    return template, support


def observed_minimal_records(old, manifest, template_number, clip_size, thumb_size, updated,
                             template_snapshot=None):
    """Copy an observed descriptor form; this is an experiment, not a native writer."""
    catalog_profile(manifest, "observed_minimal")
    if not all(r["valid"] for r in check_regions(old)):
        raise ValueError("Source database checksum failure")
    rows = inventory(old)
    if any(not r["checksum_valid"] for r in rows if r["index"]):
        raise ValueError("Source record checksum failure")
    number = int(manifest["clip"][1:])
    if not 0 <= number <= 9999 or any(
            r.get("content_type") == 2 and r.get("clip_number") == number for r in rows):
        raise ValueError("Invalid or already cataloged clip")
    source = minimal_template_data(old, template_snapshot)
    template, support = minimal_template_records(old, source, template_number)
    movie = bytearray.fromhex(template["hex"])
    video = bytes.fromhex(support["hex"])
    if (movie[6] != 0x18 or movie[0x5a:0x5f] != bytes(5) or
            movie[0x20:0x50] != bytes(0x30) or movie[0x62:0x70] != bytes(14) or
            movie[0x7c:0x9e] != bytes(34) or
            video[:10] != bytes.fromhex("02000000ffffffff5100") or
            video[10:158] != bytes(148)):
        raise ValueError("Template is not the supported observed-minimal representation")
    cursor = struct.unpack_from("<I", old, 0x7c44)[0]
    capacity = struct.unpack_from("<I", old, 0x44)[0]
    index = next((i for i in range(cursor + 1, min(capacity, 65536))
                  if not old[0x4000 + i // 8] >> (i % 8) & 1), None)
    if index is None:
        raise ValueError("No supported free content record")
    p = 0x10000 + index * 160
    if any(old[p:p + 160]):
        raise ValueError("Inactive slot contains old bytes; refusing reuse")
    generation = struct.unpack_from("<I", old, 0x7c40)[0]
    if not 0 < generation < 0x8000:
        raise ValueError("Unsupported content generation")
    struct.pack_into("<H", movie, 4, generation << 1 | (movie[4] & 1))
    struct.pack_into("<H", movie, 14, number << 2 | (movie[14] & 3))
    stamp = datetime.fromisoformat(manifest["stamp"])
    set_date(movie, 0x10, stamp)
    set_date(movie, 0x18, updated)
    struct.pack_into("<III", movie, 0x70, clip_size >> 32, clip_size & 0xffffffff, thumb_size)
    record_checksum(movie)
    data = bytearray(old)
    data[p:p + 160] = movie
    data[0x4000 + index // 8] |= 1 << (index % 8)
    struct.pack_into("<I", data, 0x7c44, index)
    for field in (0x7c80, 0x7c88):
        struct.pack_into("<I", data, field, struct.unpack_from("<I", old, field)[0] + 1)
    struct.pack_into("<Q", data, 0x8010, packed_header_time(stamp))
    struct.pack_into("<Q", data, 0x8018, packed_header_time(updated))
    fix_checksums(data)
    details = {
        "new_records": [index], "modified_existing_records": [], "movie_record": index,
        "video_record": support["index"], "video_reused": True,
        "umid_array_record": 0, "umid_slot": None, "umid_slot_reused": False,
        "template_number": template_number, "updated_stamp": updated.isoformat(),
        "catalog_schema": 3, "catalog_representation": "observed_minimal",
        "template_record_sha256": digest(bytes.fromhex(template["hex"])),
        "omitted_catalog_fields": ["video parameters", "UMID", "timecodes"],
        "camera_acceptance": "NOT_TESTED", "root_cause_established": False,
    }
    if template_snapshot is not None:
        details.update(template_source_snapshot=str(Path(template_snapshot).resolve()),
                       template_source_database_sha256=digest(source))
    validate_catalog_changes(old, data, details)
    return data, details


def catalog_records(old, manifest, template_number, clip_size, thumb_size, updated,
                    representation="native_reuse", template_snapshot=None):
    """Follow the native content-allocation/support-reuse order for this SD layout."""
    catalog_profile(manifest, representation)
    if representation == "observed_minimal":
        return observed_minimal_records(old, manifest, template_number, clip_size, thumb_size,
                                        updated, template_snapshot)
    if template_snapshot is not None:
        raise ValueError("Historical template is only supported for observed_minimal")
    if representation != "native_reuse":
        raise ValueError("Unknown catalog representation")
    if not all(r["valid"] for r in check_regions(old)):
        raise ValueError("Source database checksum failure")
    records = inventory(old)
    by_index = {r["index"]: r for r in records}
    if any(not r["checksum_valid"] for r in records if r["index"]):
        raise ValueError("Source record checksum failure")
    number = int(manifest["clip"][1:])
    if not 0 <= number <= 9999:
        raise ValueError("Expected four-digit SD clip number")
    if any(r.get("content_type") == 2 and r.get("clip_number") == number for r in records):
        raise ValueError("Clip already cataloged")
    template = next(r for r in records if r.get("content_type") == 2 and
                    r.get("clip_number") == template_number)
    movie = bytearray.fromhex(template["hex"])
    video = bytearray.fromhex(by_index[template["video_info_ref"]]["hex"])
    if video[0] & 15 != 2 or struct.unpack_from("<H", video, 8)[0] >> 1 != 40:
        raise ValueError("Expected single-record 40-byte video parameters")
    struct.pack_into("<H", video, 12, 25)
    video[27:30] = acquisition_bytes(manifest)
    umid = bytes.fromhex(manifest["umid"])
    if len(umid) != 32:
        raise ValueError("Expected 32-byte UMID")
    masked = umid[:13] + bytes(11) + umid[24:]
    data = bytearray(old)
    capacity = struct.unpack_from("<I", old, 0x44)[0]
    cursor = struct.unpack_from("<I", old, 0x7c44)[0]
    generation = struct.unpack_from("<I", old, 0x7c40)[0]
    allocated, modified = [], []

    def allocate(start):
        for index in range(start, min(capacity, 65536)):
            if data[0x4000 + index // 8] >> (index % 8) & 1:
                continue
            p = 0x10000 + index * 160
            if any(data[p:p + 160]):
                raise ValueError("Inactive slot contains old bytes; refusing reuse")
            data[0x4000 + index // 8] |= 1 << (index % 8)
            allocated.append(index)
            return index
        raise ValueError("No supported free record; wraparound not implemented")

    def store(index, record):
        record_checksum(record)
        p = 0x10000 + index * 160
        data[p:p + 160] = record

    movie_id = allocate(cursor + 1)
    if not 0 < generation < 0x8000:
        raise ValueError("Unsupported content generation")
    struct.pack_into("<I", data, 0x7c44, movie_id)
    video_id = next((r["index"] for r in records if r["type"] == 2 and
                     bytes.fromhex(r["hex"])[4:50] == bytes(video[4:50])), None)
    video_reused = video_id is not None
    if video_id is None:
        video_id = allocate(movie_id)
        store(video_id, video)
    preferred = struct.unpack_from("<I", old, 0x7c4c)[0]
    template_array = struct.unpack_from("<H", movie, 0x5a)[0] | ((movie[0x5c] >> 5 & 1) << 16)
    preferred_slot = movie[0x5d] >> 4
    array_id, slot, array = None, None, None
    arrays = [r for r in records if r["type"] == 3 and bytes.fromhex(r["hex"])[4:6] == b"\x02\x20"]
    arrays.sort(key=lambda r: (r["index"] != preferred, r["index"]))
    for row in arrays:
        candidate = bytearray.fromhex(row["hex"])
        order = list(range(4))
        if row["index"] == template_array and preferred_slot < 4:
            order.remove(preferred_slot)
            order.insert(0, preferred_slot)
        for position in order:
            if (struct.unpack_from("<H", candidate, 6)[0] >> position & 1 and
                    candidate[12 + position * 32:44 + position * 32] == masked):
                array_id, slot, array = row["index"], position, candidate
                break
        if array_id is not None:
            break
    slot_reused = array_id is not None
    if array_id is None:
        row = next((r for r in arrays if r["index"] == preferred), None)
        if row:
            candidate = bytearray.fromhex(row["hex"])
            free = next((s for s in range(4) if not (struct.unpack_from("<H", candidate, 6)[0] >> s & 1)), None)
            if free is not None:
                array_id, slot, array = preferred, free, candidate
        if array_id is None:
            array_id, slot, array = allocate(movie_id), 0, bytearray(160)
            array[0], array[4], array[5] = 3, 2, 32
            struct.pack_into("<I", data, 0x7c4c, array_id)
        struct.pack_into("<H", array, 6, struct.unpack_from("<H", array, 6)[0] | 1 << slot)
        array[12 + slot * 32:44 + slot * 32] = masked
    if array_id in by_index:
        modified.append(array_id)
    struct.pack_into("<I", array, 8, struct.unpack_from("<I", array, 8)[0] + 1)
    store(array_id, array)
    struct.pack_into("<H", movie, 4, generation << 1 | (movie[4] & 1))
    raw_number = struct.unpack_from("<H", movie, 14)[0]
    struct.pack_into("<H", movie, 14, (raw_number & 3) | number << 2)
    stamp = datetime.fromisoformat(manifest["stamp"])
    set_date(movie, 0x10, stamp)
    set_date(movie, 0x18, updated)
    for offset, name, fallback in ((0x40, "start_timecode", timecode(0)),
                                   (0x44, "end_timecode", timecode(manifest["frames"] - 1))):
        tc = bytes.fromhex(manifest[name]) if name in manifest else fallback
        if len(tc) != 4:
            raise ValueError("Expected four-byte timecode")
        movie[offset:offset + 4] = tc[::-1]
    struct.pack_into("<HH", movie, 0x58, video_id, array_id)
    movie[0x5c] &= 0xcf
    movie[0x5d] = (movie[0x5d] & 15) | slot << 4
    movie[0x5e] = umid[23]
    movie[0x5f:0x62] = umid[13:16]
    movie[0x62:0x65] = bytes(3)
    struct.pack_into("<III", movie, 0x70, clip_size >> 32, clip_size & 0xffffffff, thumb_size)
    movie[0x7c:0x84] = bytes(8)
    store(movie_id, movie)
    for field in (0x7c80, 0x7c88):
        struct.pack_into("<I", data, field, struct.unpack_from("<I", old, field)[0] + 1)
    struct.pack_into("<Q", data, 0x8010, packed_header_time(stamp))
    struct.pack_into("<Q", data, 0x8018, packed_header_time(updated))
    fix_checksums(data)
    details = {"new_records": allocated, "modified_existing_records": modified,
               "movie_record": movie_id, "video_record": video_id, "video_reused": video_reused,
               "umid_array_record": array_id, "umid_slot": slot, "umid_slot_reused": slot_reused,
               "template_number": template_number, "updated_stamp": updated.isoformat(),
               "catalog_schema": 2}
    validate_catalog_changes(old, data, details)
    return data, details


def validate_catalog_changes(before, after, details):
    if len(before) != len(after):
        raise ValueError("Database allocation size changed")
    old, new = [{r["index"]: r for r in inventory(data)} for data in (before, after)]
    added = set(new) - set(old)
    changed = {i for i in old if i in new and old[i]["hex"] != new[i]["hex"]}
    if (set(old) - set(new) or added != set(details["new_records"]) or
            changed != set(details["modified_existing_records"])):
        raise ValueError("Unexpected catalog record changes")
    if not all(r["valid"] for r in check_regions(after)) or any(
            not r["checksum_valid"] for i, r in new.items() if i):
        raise ValueError("Catalog checksum failure")
    expected = bytearray(before)
    for start, end in ((0x4000, 0x7c3c), (0x7c44, 0x7c48), (0x7c4c, 0x7c50),
                       (0x7c80, 0x7c84), (0x7c88, 0x7c8c), (0x7ffc, 0x8000),
                       (0x8010, 0x8020), (0xbffc, 0xc000)):
        expected[start:end] = after[start:end]
    for index in added | changed:
        p = 0x10000 + index * 160
        expected[p:p + 160] = after[p:p + 160]
    if expected != after:
        raise ValueError("Unexpected header or inactive-record changes")
    bitmap = bytearray(before[0x4000:0x7c00])
    for index in added:
        bitmap[index // 8] |= 1 << (index % 8)
    if bitmap != after[0x4000:0x7c00]:
        raise ValueError("Unexpected allocation bitmap changes")
    for field in (0x7c80, 0x7c88):
        if struct.unpack_from("<I", after, field)[0] != struct.unpack_from("<I", before, field)[0] + 1:
            raise ValueError("Unexpected content count")
    movie_id = details["movie_record"]
    if (struct.unpack_from("<I", after, 0x7c44)[0] != movie_id or movie_id not in added or
            new[movie_id].get("content_type") != 2 or
            sum(new[i].get("content_type") == 2 for i in added) != 1):
        raise ValueError("Unexpected content allocation cursor")
    for index in changed:
        if index != details["umid_array_record"] or old[index]["type"] != 3:
            raise ValueError("Existing content/path/attribute record modified")
        a, b = [bytes.fromhex(rows[index]["hex"]) for rows in (old, new)]
        slot = details["umid_slot"]
        occupied = struct.unpack_from("<H", a, 6)[0]
        expected_bitmap = occupied if details["umid_slot_reused"] else occupied | 1 << slot
        if struct.unpack_from("<H", b, 6)[0] != expected_bitmap:
            raise ValueError("Unexpected UMID slot changes")
        if not details["umid_slot_reused"] and occupied >> slot & 1:
            raise ValueError("Will not replace an occupied UMID slot")
        if struct.unpack_from("<I", b, 8)[0] != struct.unpack_from("<I", a, 8)[0] + 1:
            raise ValueError("Unexpected UMID reference count")
        expected = bytearray(a)
        expected[6:12] = b[6:12]
        if not details["umid_slot_reused"]:
            expected[12 + slot * 32:44 + slot * 32] = b[12 + slot * 32:44 + slot * 32]
        record_checksum(expected)
        if bytes(expected) != b:
            raise ValueError("Existing UMID contents changed")
    if details.get("catalog_schema") == 3:
        if (details.get("catalog_representation") != "observed_minimal" or changed or
                added != {movie_id} or details["umid_array_record"] != 0):
            raise ValueError("Unexpected observed-minimal changes")
        if bool(details.get("template_source_snapshot")) != bool(
                details.get("template_source_database_sha256")):
            raise ValueError("Historical template source/hash pair required")
        source = minimal_template_data(before, details.get("template_source_snapshot"),
                                       details.get("template_source_database_sha256"))
        template, _ = minimal_template_records(before, source, details["template_number"])
        a, b = [bytes.fromhex(r["hex"]) for r in (template, new[movie_id])]
        expected = bytearray(a)
        for start, end in ((4, 6), (14, 32), (0x70, 0x7c), (158, 160)):
            expected[start:end] = b[start:end]
        if bytes(expected) != b or digest(a) != details["template_record_sha256"]:
            raise ValueError("New descriptor does not preserve its observed template")
    elif details.get("catalog_schema") != 2:
        raise ValueError("Expected native-reuse catalog schema")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--snapshot", required=True)
    ap.add_argument("--build", default="output/cat-25m")
    ap.add_argument("--template-number", type=int, default=6359)
    ap.add_argument("--catalog-representation",
                    choices=("native_reuse", "observed_minimal"), default="native_reuse")
    ap.add_argument("--observations", default="analysis/camera_observations_20261112_233331.json")
    ap.add_argument("--template-snapshot",
                    help="Explicit saved sparse-template source; never replaces the fresh allocation baseline")
    ap.add_argument("--archive-local-stage", action="store_true")
    args = ap.parse_args()
    build, snap = Path(args.build), Path(args.snapshot)
    manifest = json.loads((build / "build-manifest.json").read_text(encoding="utf-8"))
    catalog_profile(manifest, args.catalog_representation)
    clip, frames = manifest["clip"], manifest["frames"]
    source = snap / "PRIVATE/DATABASE/DATABASE.BIN"
    old = source.read_bytes()
    records = inventory(old)
    if args.catalog_representation == "observed_minimal":
        observations = json.loads(Path(args.observations).read_text(encoding="utf-8"))
        if f"C{args.template_number:04d}" not in observations[
                "current_listing_positive_examples_not_exhaustive"]:
            raise ValueError("Experimental template must have a user-confirmed listing observation")
    stamp = datetime.fromisoformat(manifest["stamp"])
    updated = datetime.now(stamp.tzinfo)
    data, details = catalog_records(
        old, manifest, args.template_number, (build / (clip + ".MP4")).stat().st_size,
        (build / (clip + "T01.JPG")).stat().st_size, updated, args.catalog_representation,
        args.template_snapshot)
    mp_path = snap / "PRIVATE/M4ROOT/MEDIAPRO.XML"
    old_mp = mp_path.read_bytes()
    root = ET.fromstring(old_mp)
    contents = root.find(f"{{{MPF}}}Contents")
    materials = list(contents)
    if any(x.get("uri") == f"./CLIP/{clip}.MP4" for x in materials):
        raise ValueError("MEDIAPRO entry exists")
    root.set("createdAt", updated.isoformat(timespec="seconds"))
    material = ET.SubElement(contents, f"{{{MPF}}}Material", material_attributes(manifest))
    ET.SubElement(material, f"{{{MPF}}}RelevantInfo", uri=f"./CLIP/{clip}M01.XML", type="XML")
    ET.SubElement(material, f"{{{MPF}}}RelevantInfo", uri=f"./THMBNL/{clip}T01.JPG", type="JPG")
    ET.register_namespace("", MPF)
    ET.indent(root, space="\t")
    xml = b'<?xml version="1.0" encoding="UTF-8"?>\r\n' + ET.tostring(root, encoding="utf-8") + b"\r\n"
    padded_size = max(len(old_mp), ((len(xml) + 1023) // 1024) * 1024)
    xml += b" " * (padded_size - len(xml))
    stage = build / "catalog"
    if stage.exists() and args.archive_local_stage:
        archive = build / ("catalog-archive-" + datetime.now().strftime("%Y%m%dT%H%M%S"))
        resolved_build = build.resolve()
        if not stage.resolve().is_relative_to(resolved_build) or not archive.resolve().is_relative_to(resolved_build):
            raise ValueError("Local stage archive would leave the build directory")
        if archive.exists():
            raise FileExistsError(archive)
        stage.rename(archive)
    stage.mkdir(exist_ok=False)
    (stage / "DATABASE.BIN").write_bytes(data)
    (stage / "MEDIAPRO.XML").write_bytes(xml)
    unchanged_existing = len(records) - len(details["modified_existing_records"])
    transaction = {
        **details, "snapshot": str(snap.resolve()), "clip": clip,
        "existing_records_unchanged": unchanged_existing,
        "database_before_sha256": digest(old), "database_after_sha256": digest(data),
        "mediapro_before_sha256": digest(old_mp), "mediapro_after_sha256": digest(xml),
        "database_changed_bytes": sum(a != b for a, b in zip(old, data)),
        "new_materials": 1, "old_material_count": len(materials),
        "record_checksums_valid": True, "header_checksums_valid": True,
        "umid_layout": ("omitted, as in observed positive template"
                        if args.catalog_representation == "observed_minimal" else
                        "sidb::RestorateUMID with creation-time-derived bytes16..22")}
    if args.catalog_representation == "observed_minimal":
        transaction["observations_path"] = str(Path(args.observations).resolve())
        transaction["observations_sha256"] = digest(Path(args.observations).read_bytes())
    (stage / "transaction.json").write_text(json.dumps(transaction, indent=2), encoding="utf-8")
    print(json.dumps(transaction, indent=2))


if __name__ == "__main__":
    main()
