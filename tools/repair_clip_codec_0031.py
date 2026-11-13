"""Targeted, hash-guarded repair of existing C6520/C6521 XML and SD records.

Stage locally, probe the corrected media, then use explicit --apply. This is
not ordinary clip deployment: it may edit only the two user-authorized clips.
Never deletes files, changes picture/audio bytes, or restores an old database.
"""
import argparse
from datetime import datetime
import hashlib
import json
import os
from pathlib import Path
import struct
import subprocess
import sys
from xml.etree import ElementTree as ET
from xml.parsers import expat

from analyze_sd_repair import verify_saved_metadata
from compare_sd_snapshots import compare, db_view, read_manifest
from deploy_sd_clip import durable_write
from emulate_mediapro import MediaProfileEmulator
from emulate_sidb_converter import EXPECTED, RecordConverter
from sony_mp4 import MP4
from sony_nrt_codec import nrt_codec_matches
from sony_profiles import get_profile
from sony_verification import digest, track_payload_hash
from stage_sd_catalog import catalog_records, validate_catalog_changes

ROOT = Path(__file__).resolve().parents[1]
OLD = b"AVC_1920_1080_HP@L40"
NEW = b"AVC_1920_1080_HP@L4"
ORIGINALS = {
    "C6520": ROOT / "output/profiles-0028-hd16-2997/package",
    "C6521": ROOT / "output/bitrate-0029-29/A",
}
DB_REL = "PRIVATE/DATABASE/DATABASE.BIN"
MP_REL = "PRIVATE/M4ROOT/MEDIAPRO.XML"


def sha(data):
    return hashlib.sha256(data).hexdigest()


def corrected_xml(raw):
    root = ET.fromstring(raw)
    video = [n for n in root.iter() if n.tag.rsplit("}", 1)[-1] == "VideoFrame"]
    literal = b'videoCodec="' + OLD + b'"'
    if len(video) != 1 or video[0].get("videoCodec") != OLD.decode() or raw.count(literal) != 1:
        raise ValueError("Expected exactly one historical codec attribute")
    fixed = raw.replace(literal, b'videoCodec="' + NEW + b'"') + b" "
    if len(fixed) != len(raw) or not nrt_codec_matches(ET.fromstring(fixed), get_profile("hd16_2997")):
        raise ValueError("Codec correction changed length or is not canonical")
    return fixed


def media_patch(path):
    media = MP4(path)
    try:
        xml = media.child(media.one(media.top, "meta"), "xml ", 4)
        offset, raw = xml.data + 4, media.payload(xml)[4:]
        return offset, raw, corrected_xml(raw)
    finally:
        media.close()


def corrected_mediapro(raw, clip):
    parser, positions = expat.ParserCreate(), []
    def start(name, attrs):
        if name.rsplit(":", 1)[-1] == "Material" and attrs.get("uri") == f"./CLIP/{clip}.MP4":
            if attrs.get("videoType") != OLD.decode() or any(">" in v for v in attrs.values()):
                raise ValueError("Unexpected existing Material attributes")
            positions.append(parser.CurrentByteIndex)
    parser.StartElementHandler = start
    parser.Parse(raw, True)
    if len(positions) != 1:
        raise ValueError("Expected one existing MEDIAPRO material")
    first = positions[0]
    end = raw.index(b">", first) + 1
    tag = raw[first:end]
    needle = b'videoType="' + OLD + b'"'
    if tag.count(needle) != 1:
        raise ValueError("Expected exact historical videoType spelling")
    fixed = raw[:first] + tag.replace(needle, b'videoType="' + NEW + b'"') + raw[end:]
    # No serialization of unrelated XML or creation-date updates.
    before, after = ET.fromstring(raw), ET.fromstring(fixed)
    target = next(n for n in before.iter() if n.get("uri") == f"./CLIP/{clip}.MP4")
    target.set("videoType", NEW.decode())
    if ET.tostring(before) != ET.tostring(after):
        raise ValueError("Unexpected MEDIAPRO semantic changes")
    return fixed


def verify_media(original, corrected):
    a, b = MP4(original), MP4(corrected)
    try:
        offset, old, fixed = media_patch(original)
        expected = bytearray(a.buf)
        expected[offset:offset + len(old)] = fixed
        checks = {
            "entire_mp4_change_is_exact_xml_correction": bytes(expected) == b.buf[:],
            "all_top_boxes_and_offsets_preserved":
                [(x.kind, x.start, x.end) for x in a.top] ==
                [(x.kind, x.start, x.end) for x in b.top],
            "complete_mdat_exact": a.raw(a.one(a.top, "mdat")) == b.raw(b.one(b.top, "mdat")),
            "complete_moov_exact": a.raw(a.moov) == b.raw(b.moov),
            "all_track_payloads_exact":
                [track_payload_hash(t) for t in a.tracks] == [track_payload_hash(t) for t in b.tracks],
        }
        if not all(checks.values()):
            raise ValueError("Media correction modified unrelated data")
        return checks
    finally:
        a.close()
        b.close()


def bind_snapshot(snapshot, card):
    if not verify_saved_metadata(snapshot)["passed"]:
        raise ValueError("Invalid snapshot")
    for name, row in read_manifest(snapshot, "_metadata_manifest.csv").items():
        target = (card / name).resolve()
        if not target.is_relative_to(card) or digest(target) != row["sha256"]:
            raise ValueError("Card metadata differs from fresh baseline: " + name)
    for name, row in read_manifest(snapshot, "_skipped_media_manifest.csv").items():
        target = (card / name).resolve()
        if not target.is_relative_to(card):
            raise ValueError("Media inventory path escapes card")
        stat = target.stat()
        if (stat.st_size, stat.st_mtime_ns) != (int(row["size"]), int(row["last_write_time_ns"])):
            raise ValueError("Card media inventory differs from snapshot: " + name)


def firmware_catalog(build, snapshot, clip, details, umid):
    firmware = ROOT / "firmware/m4-v602/usr/lib/libmpr.so"
    expat_path = firmware.parent / "libexpat.so.1.6.11"
    db, xml = [(build / "catalog" / name).read_bytes() for name in ("DATABASE.BIN", "MEDIAPRO.XML")]
    converter = RecordConverter(firmware)
    converter.load(db)
    converted = converter.convert(details["movie_record"])
    parser = MediaProfileEmulator(firmware, expat_path, snapshot, profile_override=xml)
    profile = parser.run()
    selected = [r for r in profile["materials"] if r["clip"] == clip]
    before_db, _, before_movies = db_view(snapshot)
    from sony_db import inventory
    after_numbers = {r["clip_number"] for r in inventory(db) if r.get("content_type") == 2}
    expected_numbers = set(before_movies) | {int(clip[1:])}
    checks = {
        "new_record_conversion": converted["return_u32"] == 0,
        "called_original_readers": all(r["return_u32"] == 0
                                       for r in converted["original_reader_returns"]),
        "restored_main_path": converted["restored_paths"]["main"] ==
                              f"A:/PRIVATE/M4ROOT/CLIP/{clip}.MP4",
        "profile_initialized_and_loaded": profile["initialized_return"] == profile["load_return"] == 0,
        "one_target_profile_query": len(selected) == 1 and
            selected[0]["original_find_return"] == selected[0]["original_clip_info_return"] == 0,
        "target_profile_umid": len(selected) == 1 and selected[0]["umid_at_record_0a_hex"] == umid,
        "database_adds_only_target_movie": after_numbers == expected_numbers,
        "original_parser_code_unchanged": profile["original_executable_sections_unchanged"],
        "database_unchanged_in_emulator":
            bytes(converter.uc.mem_read(0x10000000, len(db))) == db,
    }
    validate_catalog_changes(before_db, db, details)
    report = {"passed": all(checks.values()), "checks": checks, "conversion": converted,
              "profile": profile, "firmware_sha256": EXPECTED,
              "database_sha256": sha(db), "mediapro_sha256": sha(xml),
              "scope": "Original target readers/profile parser; not full mount or camera playback"}
    (build / "firmware-catalog.json").write_text(json.dumps(report, indent=2), encoding="utf-8")
    if not report["passed"]:
        raise ValueError("Original catalog checks failed")


def stage(clip, snapshot, template, card, build):
    if clip not in ORIGINALS or build.exists() or not build.is_relative_to(ROOT / "output"):
        raise ValueError("Use an authorized clip and fresh local output")
    bind_snapshot(snapshot, card)
    original = ORIGINALS[clip]
    source = original / (clip + ".MP4")
    media_rel, sidecar_rel = [f"PRIVATE/M4ROOT/CLIP/{clip}{suffix}" for suffix in (".MP4", "M01.XML")]
    if digest(card / media_rel) != digest(source):
        raise ValueError("Card clip differs from preserved historical source")
    info = json.loads((original / "build-manifest.json").read_text(encoding="utf-8"))
    offset, old, fixed = media_patch(source)
    if (snapshot / sidecar_rel).read_bytes() != old:
        raise ValueError("Sidecar differs from embedded historical XML")
    data = bytearray(source.read_bytes())
    data[offset:offset + len(old)] = fixed
    before = (snapshot / DB_REL).read_bytes()
    thumb = card / f"PRIVATE/M4ROOT/THMBNL/{clip}T01.JPG"
    after, details = catalog_records(
        before, info, 7, len(data), thumb.stat().st_size,
        datetime.now().astimezone(), "observed_minimal", template)
    mp_before = (snapshot / MP_REL).read_bytes()
    mp_after = corrected_mediapro(mp_before, clip)
    build.mkdir(parents=True)
    (build / "catalog").mkdir()
    (build / (clip + ".MP4")).write_bytes(data)
    (build / (clip + "M01.XML")).write_bytes(fixed)
    (build / "catalog/DATABASE.BIN").write_bytes(after)
    (build / "catalog/MEDIAPRO.XML").write_bytes(mp_after)
    checks = verify_media(source, build / (clip + ".MP4"))
    report = {
        "repair_schema": 1, "purpose": "0031_CANONICAL_CODEC_AND_RECATALOG_AUTHORIZED_EXISTING_CLIP",
        "clip": clip, "snapshot": str(snapshot), "template_snapshot": str(template),
        "card": str(card), "original_media": str(source),
        "original_manifest_sha256": digest(original / "build-manifest.json"),
        "original_media_sha256": sha(source.read_bytes()),
        "corrected_media_sha256": sha(data), "xml_offset": offset, "xml_size": len(old),
        "old_xml_sha256": sha(old), "new_xml_sha256": sha(fixed),
        "database_before_sha256": sha(before), "database_after_sha256": sha(after),
        "mediapro_before_sha256": sha(mp_before), "mediapro_after_sha256": sha(mp_after),
        "details": details, "media_checks": checks,
        "no_card_writes_during_staging": True, "camera_listing": "NOT_TESTED",
        "target_changes": [media_rel, sidecar_rel, MP_REL, DB_REL],
    }
    firmware_catalog(build, snapshot, clip, details, info["umid"])
    (build / "repair-manifest.json").write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps({"staged": str(build), "clip": clip, "new_record": details["movie_record"],
                      "media_checks": checks}, indent=2))


def apply(build, card, nrt_path, reader_path):
    info = json.loads((build / "repair-manifest.json").read_text(encoding="utf-8"))
    clip, snapshot = info["clip"], Path(info["snapshot"]).resolve()
    if (clip not in ORIGINALS or info["card"] != str(card) or
            info["purpose"] != "0031_CANONICAL_CODEC_AND_RECATALOG_AUTHORIZED_EXISTING_CLIP"):
        raise ValueError("Not an authorized repair transaction")
    bind_snapshot(snapshot, card)
    source, corrected = Path(info["original_media"]), build / (clip + ".MP4")
    if source.resolve() != (ORIGINALS[clip] / (clip + ".MP4")).resolve():
        raise ValueError("Unexpected historical source")
    if digest(source) != info["original_media_sha256"] or digest(corrected) != info["corrected_media_sha256"]:
        raise ValueError("Repair media changed")
    verify_media(source, corrected)
    offset, old, fixed = media_patch(source)
    if (build / (clip + "M01.XML")).read_bytes() != fixed:
        raise ValueError("Repair sidecar changed")
    before = (snapshot / DB_REL).read_bytes()
    after = (build / "catalog/DATABASE.BIN").read_bytes()
    validate_catalog_changes(before, after, info["details"])
    if (sha(after) != info["database_after_sha256"] or
            (build / "catalog/MEDIAPRO.XML").read_bytes() !=
            corrected_mediapro((snapshot / MP_REL).read_bytes(), clip)):
        raise ValueError("Staged catalogs changed")
    for path, kind in ((nrt_path, "nrt"), (reader_path, "reader")):
        evidence = json.loads(path.read_text(encoding="utf-8"))
        if (evidence.get("emulation_error") or evidence.get("media_sha256") != digest(corrected) or
                Path(evidence["media"]).resolve() != corrected or
                evidence.get("firmware_sha256") != EXPECTED):
            raise ValueError("Missing current original-firmware evidence")
        if kind == "nrt":
            if (evidence.get("in_memory_replacement") is not None or
                    evidence.get("original_executable_sections_unchanged") is not True or
                    evidence.get("local_media_unchanged") is not True or
                    any(evidence.get(key) != 0 for key in
                        ("load_return_u32", "basic_information_return_u32",
                         "mark_count_return_u32", "clip_status_return_u32"))):
                raise ValueError("Corrected XML original checks failed")
        elif (evidence.get("passed_selected_reader_checks") is not True or
              evidence.get("original_executable_sections_unchanged_after_all_probes") is not True or
              evidence.get("result", {}).get("last_status_u32") != 0):
            raise ValueError("Corrected MP4 original checks failed")
    firmware_catalog(build, snapshot, clip, info["details"],
                     json.loads((ORIGINALS[clip] / "build-manifest.json").read_text())["umid"])
    media_rel, sidecar_rel, mp_rel, db_rel = info["target_changes"]
    if (media_rel != f"PRIVATE/M4ROOT/CLIP/{clip}.MP4" or
            sidecar_rel != f"PRIVATE/M4ROOT/CLIP/{clip}M01.XML" or
            mp_rel != MP_REL or db_rel != DB_REL):
        raise ValueError("Unexpected repair targets")
    bind_snapshot(snapshot, card)
    if digest(card / media_rel) != info["original_media_sha256"]:
        raise ValueError("Target media changed before write")
    audit = {"clip": clip, "snapshot": str(snapshot), "updated": [], "deleted": [],
             "status": "writing", "nrt_evidence_sha256": digest(nrt_path),
             "reader_evidence_sha256": digest(reader_path), "camera_listing": "NOT_TESTED"}
    audit_path = build / "repair-deployment.json"
    def save():
        audit_path.write_text(json.dumps(audit, indent=2), encoding="utf-8")
    save()
    try:
        with (card / media_rel).open("r+b") as stream:
            stream.seek(offset)
            if stream.read(len(old)) != old:
                raise ValueError("Embedded XML changed before patch")
            stream.seek(offset)
            stream.write(fixed)
            stream.flush()
            os.fsync(stream.fileno())
        if digest(card / media_rel) != info["corrected_media_sha256"]:
            raise RuntimeError("Corrected MP4 readback mismatch")
        audit["updated"].append(media_rel)
        save()
        for rel, data in ((sidecar_rel, fixed),
                          (MP_REL, (build / "catalog/MEDIAPRO.XML").read_bytes()),
                          (DB_REL, after)):
            expected = read_manifest(snapshot, "_metadata_manifest.csv")[rel]["sha256"]
            if digest(card / rel) != expected:
                raise RuntimeError("Concurrent card change: " + rel)
            durable_write(card / rel, data)
            audit["updated"].append(rel)
            save()
        result = subprocess.run(
            [sys.executable, str(ROOT / "tools/card_snapshot.py"), "--card", str(card),
             "--output", str(ROOT / "backup")], check=True, capture_output=True, text=True)
        fresh = json.loads(result.stdout)
        if fresh["errors"]:
            raise RuntimeError("Readback snapshot failed")
        audit["after_snapshot"] = fresh["snapshot"]
        diff = compare(snapshot, Path(fresh["snapshot"]))
        audit["snapshot_diff"] = diff
        expected_metadata = {sidecar_rel, MP_REL, DB_REL}
        if (set(diff["metadata"]["changed"]) != expected_metadata or
                diff["media_size_mtime_inventory"]["changed"] != [media_rel] or
                any(diff[group][kind] for group in ("metadata", "media_size_mtime_inventory")
                    for kind in ("added", "removed"))):
            raise RuntimeError("Unexpected post-write changes")
        audit["status"] = "written_and_readback_verified"
        save()
        print(json.dumps({"clip": clip, "status": audit["status"],
                          "after_snapshot": fresh["snapshot"]}, indent=2))
    except Exception as error:
        audit["status"], audit["error"] = "failed_stop_without_database_rollback", str(error)
        save()
        raise


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--clip", choices=ORIGINALS)
    ap.add_argument("--snapshot")
    ap.add_argument("--template-snapshot")
    ap.add_argument("--card", required=True)
    ap.add_argument("--build", required=True)
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--nrt-report")
    ap.add_argument("--reader-report")
    args = ap.parse_args()
    card, build = Path(args.card).resolve(), Path(args.build).resolve()
    if card.drive.upper() != "F:" or not build.is_relative_to(ROOT / "output"):
        raise ValueError("This authorization is restricted to F: and local output/")
    if args.apply:
        if not args.nrt_report or not args.reader_report:
            ap.error("--apply requires corrected-file original NRT and MP4 reports")
        apply(build, card, Path(args.nrt_report).resolve(), Path(args.reader_report).resolve())
    else:
        if not args.clip or not args.snapshot or not args.template_snapshot:
            ap.error("Staging requires --clip, --snapshot, --template-snapshot")
        stage(args.clip, Path(args.snapshot).resolve(), Path(args.template_snapshot).resolve(), card, build)


if __name__ == "__main__":
    main()
