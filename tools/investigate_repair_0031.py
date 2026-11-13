"""Collect read-only evidence for the 0031 image-database repair investigation.

Reads saved snapshots and current card files; writes a fresh local JSON report.
Does not repair, stage, deploy, remove resources, or assign camera verdicts.
"""
import argparse
from datetime import datetime
import hashlib
import json
from pathlib import Path
import struct
from xml.etree import ElementTree as ET

from analyze_sd_repair import verify_saved_metadata
from compare_sd_snapshots import compare, read_manifest
from sony_mp4 import MP4
from sony_nrt_codec import codec_name_matches
from sony_profiles import get_profile
from sony_verification import digest


LOCAL_MEDIA = {
    6501: ("analysis/C6501-reference-0028.MP4", "hd16_2997"),
    6519: ("output/profiles-0028-hd50-2997/package/C6519.MP4", "hd50_2997"),
    6520: ("output/profiles-0028-hd16-2997/package/C6520.MP4", "hd16_2997"),
    6521: ("output/bitrate-0029-29/A/C6521.MP4", "hd16_2997"),
    6522: ("output/bitrate-0029-29/B/C6522.MP4", "hd16_2997"),
    6523: ("output/bitrate-0029-59/A/C6523.MP4", "hd25_5994"),
    6524: ("output/bitrate-0029-59/B/C6524.MP4", "hd25_5994"),
}


def inspect_mp4(path, profile):
    media = MP4(path)
    try:
        raw = media.payload(media.child(media.one(media.top, "meta"), "xml ", 4))[4:]
        root = ET.fromstring(raw.rstrip(b"\0 "))
        video = next(x for x in root.iter() if x.tag.rsplit("}", 1)[-1] == "VideoFrame")
        uuid = media.one(media.top, "uuid")
        fields = media.payload(media.one(media.boxes(uuid.data + 24, uuid.end), "VPRF"))
        average, maximum = struct.unpack_from(">II", fields, 20)
        return {
            "xml_video_codec": video.get("videoCodec"),
            "xml_codec_canonical": codec_name_matches(video.get("videoCodec"), get_profile(profile)),
            "xml_sha256": hashlib.sha256(raw).hexdigest(),
            "embedded_xml_hex": raw.hex(),
            "level_idc": media.tracks[0].avcc()[3],
            "prof_average_kbps": average, "prof_maximum_kbps": maximum,
            "video_frames": len(media.tracks[0].sizes),
        }
    finally:
        media.close()


def collect(before, after, card, root):
    integrity = [verify_saved_metadata(snap) for snap in (before, after)]
    if not all(row["passed"] for row in integrity):
        raise ValueError("Saved snapshot metadata integrity failed")
    metadata = read_manifest(after, "_metadata_manifest.csv")
    for name, row in metadata.items():
        target = (card / name).resolve()
        if not target.is_relative_to(card):
            raise ValueError("Metadata path escapes card")
        if digest(target) != row["sha256"]:
            raise ValueError("Current card no longer matches snapshot: " + name)
    diff = compare(before, after)
    movies = diff["database"]
    clips = []
    for number, (local_name, profile) in LOCAL_MEDIA.items():
        name = f"C{number:04d}"
        local = (root / local_name).resolve()
        current = card / "PRIVATE/M4ROOT/CLIP" / (name + ".MP4")
        first_stat = current.stat()
        card_hash = digest(current)
        second_stat = current.stat()
        local_hash = digest(local)
        if ((first_stat.st_size, first_stat.st_mtime_ns) !=
                (second_stat.st_size, second_stat.st_mtime_ns)):
            raise ValueError("Media changed while hashing")
        if card_hash != local_hash:
            raise ValueError("Card media differs from local original: " + name)
        details = inspect_mp4(local, profile)
        raw = bytes.fromhex(details.pop("embedded_xml_hex"))
        sidecar = after / "PRIVATE/M4ROOT/CLIP" / (name + "M01.XML")
        details["sidecar_exactly_matches_embedded"] = sidecar.read_bytes() == raw
        previous, current_record = [view.get(number) for view in
                                   (movies["movies_before"], movies["movies_after"])]
        clips.append({
            "clip": name, "local_original": str(local), "card_media": str(current),
            "card_sha256": card_hash, "local_sha256": local_hash,
            "card_matches_local": True, "size": second_stat.st_size,
            "mtime_ns": second_stat.st_mtime_ns,
            "before_record": previous["record_index"] if previous else None,
            "after_record": current_record["record_index"] if current_record else None,
            "database_record_removed": previous is not None and current_record is None,
            **details,
        })
    # Detect a concurrent catalog change after the media read.
    for name, row in metadata.items():
        if digest(card / name) != row["sha256"]:
            raise ValueError("Current metadata changed during evidence collection")
    return {
        "investigation": "0031", "collected_local": datetime.now().astimezone().isoformat(),
        "card_writes": [], "snapshot_integrity": integrity,
        "current_metadata_matches_post_repair_snapshot": True,
        "user_report": {
            "raw": "执行修复影像数据库后C6520 6521不再被相机列出; 其余之前能播放的片段均正常播放.",
            "not_listed_explicit": ["C6520", "C6521"],
            "C6522_post_repair_listing": "NOT_SEPARATELY_REPORTED",
            "full_duration_audio_seek_individual_results": "NOT_SEPARATELY_REPORTED",
        },
        "clips": clips, "snapshot_diff": diff,
        "limits": [
            "Skipped media inventory is size/mtime evidence, not a hash of all card media.",
            "Only the seven selected MP4s are freshly hashed against local originals here.",
            "Database removal is not evidence of hardware decoder failure.",
            "No full camera repair or hardware decoder is emulated by this collector.",
        ],
    }


def collect_deployment(before, after, card, root):
    from repair_clip_codec_0031 import bind_snapshot, verify_media
    bind_snapshot(after, card)
    diff = compare(before, after)
    changed_metadata = {
        "PRIVATE/M4ROOT/CLIP/C6520M01.XML", "PRIVATE/M4ROOT/CLIP/C6521M01.XML",
        "PRIVATE/M4ROOT/MEDIAPRO.XML", "PRIVATE/DATABASE/DATABASE.BIN",
    }
    changed_media = {f"PRIVATE/M4ROOT/CLIP/C{n}.MP4" for n in (6520, 6521)}
    if (set(diff["metadata"]["changed"]) != changed_metadata or
            set(diff["media_size_mtime_inventory"]["changed"]) != changed_media or
            diff["database"]["modified_record_indices"] or
            diff["database"]["deactivated_record_indices"] or
            any(diff[group][key] for group in ("metadata", "media_size_mtime_inventory")
                for key in ("added", "removed"))):
        raise ValueError("Unexpected total card changes")
    media = []
    for number, (local, _) in LOCAL_MEDIA.items():
        clip = f"C{number}"
        expected = (root / f"output/repair-0031/{clip}/{clip}.MP4" if number in (6520, 6521)
                    else root / local)
        current = card / "PRIVATE/M4ROOT/CLIP" / (clip + ".MP4")
        if digest(current) != digest(expected):
            raise ValueError("Final card media hash mismatch: " + clip)
        entry = {"clip": clip, "card_sha256": digest(current), "expected": str(expected)}
        if number in (6520, 6521):
            entry["original_picture_audio_and_metadata_payloads_exact"] = all(
                verify_media(root / local, current).values())
        media.append(entry)
    matrix = []
    for name, expected in (
            ("C6519-final", 0), ("C6519-negative-L40", 3),
            ("C6520-original", 3), ("C6520-L4", 0),
            ("C6521-original", 3), ("C6521-L4", 0)):
        path = root / f"analysis/0031-nrt-{name}.json"
        evidence = json.loads(path.read_text(encoding="utf-8"))
        if (evidence.get("emulation_error") or evidence.get("load_return_u32") != 0 or
                evidence.get("basic_information_return_u32") != expected or
                evidence.get("original_executable_sections_unchanged") is not True or
                evidence.get("local_media_unchanged") is not True):
            raise ValueError("Original semantic matrix failed: " + name)
        matrix.append({"case": name, "report": str(path), "report_sha256": digest(path),
                       "load_status": 0, "basic_information_status": expected,
                       "in_memory_replacement": evidence["in_memory_replacement"],
                       "semantic_trace": evidence["semantic_trace"]})
    deployments = []
    for clip in ("C6520", "C6521"):
        directory = root / "output/repair-0031" / clip
        audit = json.loads((directory / "repair-deployment.json").read_text(encoding="utf-8"))
        manifest = json.loads((directory / "repair-manifest.json").read_text(encoding="utf-8"))
        if audit["status"] != "written_and_readback_verified" or audit["deleted"]:
            raise ValueError("Incomplete repair deployment")
        deployments.append({"clip": clip, "new_record": manifest["details"]["movie_record"],
                            "source_snapshot": manifest["snapshot"],
                            "after_snapshot": audit["after_snapshot"],
                            "corrected_media_sha256": manifest["corrected_media_sha256"]})
    regression = root / "analysis/0031-regression-final.log"
    log = regression.read_text(encoding="utf-8")
    if "Ran 300 tests" not in log or not log.rstrip().endswith("OK"):
        raise ValueError("Final regression evidence missing")
    return {
        "investigation": "0031", "phase": "AUTHORIZED_TARGETED_REPAIR_WRITTEN_AWAITING_CAMERA",
        "before": str(before), "after": str(after), "final_live_card_matches_snapshot": True,
        "snapshot_diff": diff, "selected_media_hashes": media,
        "original_semantic_crossovers": matrix, "deployments": deployments,
        "regression": {"tests": 300, "passed": True, "log_sha256": digest(regression)},
        "deleted_files": [], "new_files": [],
        "preexisting_active_records_changed": [],
        "camera_listing_C6520_C6521": "AWAITING_USER_TEST",
        "camera_playback_C6520_C6521": "AWAITING_USER_TEST",
        "C6522": "Left unchanged; preexisting independent PROF property-query rejection remains",
        "limits": "Original readers and payload equality are not physical camera playback proof",
    }


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--before", required=True)
    ap.add_argument("--after", required=True)
    ap.add_argument("--card", required=True)
    ap.add_argument("--output", required=True)
    ap.add_argument("--post-deployment", action="store_true")
    args = ap.parse_args()
    before, after, card, output = [Path(x).resolve() for x in
                                    (args.before, args.after, args.card, args.output)]
    root = Path(__file__).resolve().parents[1]
    if (not output.is_relative_to(root) or output.is_relative_to(card) or
            output.is_relative_to(before) or output.is_relative_to(after) or output.exists()):
        raise ValueError("Use a fresh local output outside card and snapshots")
    report = (collect_deployment(before, after, card, root) if args.post_deployment else
              collect(before, after, card, root))
    output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    if args.post_deployment:
        print(json.dumps({"phase": report["phase"], "deployments": report["deployments"],
                          "regression": report["regression"]}, indent=2))
        return
    print(json.dumps({"clips": [
        {k: row[k] for k in ("clip", "card_matches_local", "database_record_removed",
                             "xml_video_codec", "xml_codec_canonical")}
        for row in report["clips"]]}, indent=2))


if __name__ == "__main__":
    main()
