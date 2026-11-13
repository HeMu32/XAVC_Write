"""Purpose: verify local media, metadata and staged SD catalogs before deployment.

Usage: python tools/verify_sony_package.py --build PACKAGE [--card F:/].
Design: cross-check profile/PROF, track tables, NAL timing, RTMD, XML, catalog
    changes and fresh decode/audio evidence, binding the report to package hashes.
Scope: the modeled candidate/control package schemas. Writes local evidence,
    not card resources; success is writer admission, not a physical playback test.
"""
import argparse
import hashlib
import json
import struct
from fractions import Fraction
from pathlib import Path
from xml.etree import ElementTree as ET

from build_sony_clip import MPF, NRT
from sony_db import check_regions, inventory
from sony_mp4 import MP4, ConstantSizes
from sony_profiles import DEFAULT_PROFILE, manifest_profile
from sony_rtmd import make_packet, timecode
from sony_umid import restore_umid
from sony_verification import SCHEMA, digest, equal_ranges, run_media_checks
from stage_sd_catalog import acquisition_bytes, catalog_profile, catalog_records, validate_catalog_changes
from datetime import datetime
from encode_xavc import probe_input


def hash_audio(m, target_samples=None):
    t = next(t for t in m.tracks if t.handler == "soun")
    h = hashlib.sha256()
    remaining = target_samples * 4 if target_samples is not None else None
    for p, count in zip(t.chunks, t.chunk_samples):
        n = count * 4
        if remaining is not None:
            n = min(n, remaining)
            remaining -= n
        h.update(m.buf[p:p + n])
        if remaining == 0:
            break
    if remaining:
        zeros = bytes(65536)
        while remaining:
            n = min(len(zeros), remaining)
            h.update(zeros[:n])
            remaining -= n
    return h.hexdigest()


def semantic(e):
    return e.tag, e.attrib, [semantic(x) for x in e]


def rec709_stream_matches(probe):
    video = next((s for s in probe.get("streams", []) if s.get("codec_type") == "video"), {})
    return all(video.get(key) == value for key, value in
               {"color_range": "tv", "color_space": "bt709", "color_transfer": "bt709",
                "color_primaries": "bt709"}.items())


def prof_profile_matches(fields, selected):
    return (
        len(fields) == 44 and fields[:8] == bytes.fromhex("0000000000000001") and
        fields[8:16] == b"avc1\x01\x64\x00" + bytes([selected.level_idc]) and
        struct.unpack_from(">4I", fields, 20) ==
        (selected.bitrate_kbps, selected.bitrate_kbps, selected.prof_fps, selected.prof_fps) and
        struct.unpack_from(">HH", fields, 36) == (selected.width, selected.height))


def probe_profile_matches(probe, selected):
    videos = [s for s in probe.get("streams", []) if s.get("codec_type") == "video"]
    if len(videos) != 1:
        return False
    video = videos[0]
    try:
        return (
            video.get("codec_name") == "h264" and video.get("profile") == "High" and
            video.get("codec_tag_string") == "avc1" and
            (video.get("width"), video.get("height"), video.get("pix_fmt"), video.get("level")) ==
            (selected.width, selected.height, "yuv420p", selected.level_idc) and
            all(Fraction(video.get(key, "0")) == selected.fps
                for key in ("r_frame_rate", "avg_frame_rate")) and
            video.get("field_order") == "progressive")
    except (ValueError, TypeError, ZeroDivisionError):
        return False


def sps_profile_matches(sps, selected):
    """Check freshly parsed SPS, including HRD, rather than manifest normalization notes."""
    try:
        fields, groups = sps["fields"], sps["hrd"]
        if (fields["profile_idc"] != 100 or fields["level_idc"] != selected.level_idc or
                fields["chroma_format_idc"] != 1 or fields["bit_depth_luma_minus8"] != 0 or
                fields["bit_depth_chroma_minus8"] != 0 or fields["frame_mbs_only_flag"] != 1 or
                fields.get("separate_colour_plane_flag", 0) != 0 or
                fields["fixed_frame_rate_flag"] != 1 or
                (fields["num_units_in_tick"], fields["time_scale"]) !=
                (selected.vui_tick, 240000)):
            return False
        crop = [fields.get("frame_crop_" + edge + "_offset", 0)
                for edge in ("left", "right", "top", "bottom")]
        dimensions = ((fields["pic_width_in_mbs_minus1"] + 1) * 16 - 2 * sum(crop[:2]),
                      (fields["pic_height_in_map_units_minus1"] + 1) * 16 - 2 * sum(crop[2:]))
        if dimensions != (selected.width, selected.height) or set(groups) != {"nal", "vcl"}:
            return False
        for group in groups.values():
            rate = (group["bit_rate_value_minus1[0]"] + 1) << (6 + group["bit_rate_scale"])
            size = (group["cpb_size_value_minus1[0]"] + 1) << (4 + group["cpb_size_scale"])
            if (group["cpb_cnt_minus1"] != 0 or group["cbr_flag[0]"] != 1 or
                    rate != selected.bitrate_kbps * 1000 or size != selected.bitrate_kbps * 1000):
                return False
        return True
    except (KeyError, TypeError, ValueError):
        return False


def xml_profile_matches(root, selected, frames):
    def one(name):
        nodes = [x for x in root.iter() if x.tag.rsplit("}", 1)[-1] == name]
        if len(nodes) != 1:
            raise ValueError("Expected one " + name)
        return nodes[0]

    try:
        if frames < 1 or root.tag != f"{{{NRT}}}NonRealTimeMeta":
            return False
        video, layout, ltc = one("VideoFrame"), one("VideoLayout"), one("LtcChangeTable")
        changes = list(ltc)
        expected_changes = [
            {"frameCount": "0", "value": timecode(0, half_step=selected.half_step).hex().upper(),
             "status": "increment"},
            {"frameCount": str(frames - 1),
             "value": timecode(frames - 1, half_step=selected.half_step).hex().upper(),
             "status": "end"},
        ]
        return (
            video.get("videoCodec") == selected.video_codec and
            video.get("captureFps") == video.get("formatFps") == selected.xml_fps and
            layout.get("pixel") == str(selected.width) and
            layout.get("numOfVerticalLine") == str(selected.height) and
            layout.get("aspectRatio") == "16:9" and
            ltc.get("tcFps") == "30" and
            ltc.get("halfStep") == str(selected.half_step).lower() and
            [x.attrib for x in changes] == expected_changes and
            all(x.tag == f"{{{NRT}}}LtcChange" for x in changes) and
            one("Duration").get("value") == str(frames))
    except (ValueError, TypeError, AttributeError):
        return False


def material_profile_matches(material, selected):
    return (material.get("videoType") == selected.video_codec and
            material.get("fps") == selected.xml_fps)


def rtmd_profile_matches(track, selected, frames, template):
    try:
        # Validate the original nonzero 29.97p origin before deliberately resetting it.
        make_packet(template, 0, half_step=selected.half_step)
        seed = bytearray(template)
        seed[13:18] = bytes(5)
        seed[20:24] = timecode(0, half_step=selected.half_step)
        return (frames > 0 and len(track.sizes) == frames and
                all(track.sample(i) == make_packet(seed, i, half_step=selected.half_step)
                    for i in range(frames)))
    except (ValueError, TypeError, IndexError, struct.error):
        return False


def header_duration(payload, track=False):
    version = payload[0]
    if version not in (0, 1):
        raise ValueError("Unsupported header version")
    if track:
        return struct.unpack_from(">Q" if version else ">I", payload, 28 if version else 20)[0]
    return struct.unpack_from(">IQ" if version else ">II", payload, 20 if version else 12)


def edit_origin_checks(media, base):
    checks = {"profile_audio_metadata_edit_origins": False, "profile_video_edit_origin": False}
    try:
        def origin(m, track):
            edit = m.payload(m.child(m.child(track.box, "edts"), "elst"))
            if len(edit) != 20 or edit[:8] != bytes.fromhex("0000000000000001"):
                raise ValueError("Expected one version-0 edit")
            return struct.unpack_from(">i", edit, 12)[0]

        checks["profile_audio_metadata_edit_origins"] = all(
            origin(media, track) == 0 for track in media.tracks[1:])
        if base is not None:
            checks["profile_video_edit_origin"] = (
                media.tracks[0].timescale == base.tracks[0].timescale and
                origin(media, media.tracks[0]) == origin(base, base.tracks[0]))
    except (ValueError, TypeError, IndexError, struct.error):
        pass
    return checks


def track_profile_checks(media, selected, info):
    frames = info["frames"]
    ticks, samples = frames * selected.fps_den, selected.audio_boundary(frames)
    result = {
        "profile_manifest_cadence": (frames > 0 and info["timescale"] == selected.timescale and
                                    info["duration_ticks"] == ticks and info["audio_samples"] == samples),
        "profile_track_cadence": False, "profile_movie_duration": False,
        "profile_edit_durations": False,
        "profile_sample_entry_dimensions": False, "profile_track_dimensions": False,
        "profile_avcc": False, "profile_pcm_format_and_count": False,
    }
    if len(media.tracks) != 3:
        return result
    video, audio, metadata = media.tracks
    result["profile_track_cadence"] = (
        [(t.handler, t.codec) for t in media.tracks] ==
        [("vide", "avc1"), ("soun", "twos"), ("meta", "rtmd")] and
        all(t.timescale == selected.timescale and t.duration == ticks and
            len(t.sizes) == frames and all(delta == selected.fps_den for _, delta in t.stts)
            for t in (video, metadata)) and
        audio.timescale == 48000 and audio.duration == samples and
        all(delta == 1 for _, delta in audio.stts))
    result["profile_movie_duration"] = (
        header_duration(media.payload(media.child(media.moov, "mvhd"))) ==
        (selected.timescale, ticks) and
        all(header_duration(media.payload(media.child(t.box, "tkhd")), track=True) == ticks
            for t in media.tracks))
    edits = [media.payload(media.child(media.child(t.box, "edts"), "elst"))
             for t in media.tracks]
    result["profile_edit_durations"] = all(
        len(edit) == 20 and edit[:8] == bytes.fromhex("0000000000000001") and
        struct.unpack_from(">I", edit, 8)[0] == ticks and
        struct.unpack_from(">I", edit, 16)[0] == 65536
        for edit in edits)
    entry = media.payload(video.entry)
    result["profile_sample_entry_dimensions"] = (
        struct.unpack_from(">HH", entry, 24) == (selected.width, selected.height))
    tkhd = media.payload(media.child(video.box, "tkhd"))
    result["profile_track_dimensions"] = (
        struct.unpack_from(">II", tkhd, len(tkhd) - 8) ==
        (selected.width << 16, selected.height << 16))
    avcc = video.avcc()
    result["profile_avcc"] = (
        len(avcc) >= 7 and avcc[:4] == bytes([1, 100, 0, selected.level_idc]) and
        (avcc[4] & 3) + 1 == (3 if info.get("package_kind") == "framing_control" else 4) and
        avcc[5] & 31 == 1)
    pcm = media.payload(audio.entry)
    result["profile_pcm_format_and_count"] = (
        isinstance(audio.sizes, ConstantSizes) and audio.sizes.size == 4 and
        len(audio.sizes) == samples and struct.unpack_from(">HH", pcm, 16) == (2, 16) and
        struct.unpack_from(">I", pcm, 24)[0] == 48000 << 16)
    return result


def selected_profile_checks(info, media, probe, root, material, timing_report, rtmd_template, base=None):
    selected = manifest_profile(info)
    checks = track_profile_checks(media, selected, info)
    checks.update(edit_origin_checks(media, base))
    prof = media.one(media.top, "uuid")
    fields = media.payload(media.one(media.boxes(prof.data + 24, prof.end), "VPRF"))
    checks.update({
        "profile_prof_descriptor": prof_profile_matches(fields, selected),
        "profile_probed_avc": probe_profile_matches(probe, selected),
        "profile_sps_and_hrd": sps_profile_matches(timing_report.get("sps", {}), selected),
        "profile_xml": xml_profile_matches(root, selected, info["frames"]),
        "profile_mediapro": material_profile_matches(material, selected),
        "profile_generated_rtmd": rtmd_profile_matches(
            media.tracks[2], selected, info["frames"], rtmd_template),
    })
    if "rtmd_timecode_origin" in info:
        checks["profile_rtmd_timecode_origin"] = (
            info["rtmd_timecode_origin"] == "zero; template start deliberately reset")
    if "rtmd_template_start_timecode" in info:
        checks["profile_rtmd_template_start_timecode"] = (
            info["rtmd_template_start_timecode"] == rtmd_template[20:24].hex().upper())
    for name, frame in (("start_timecode", 0), ("end_timecode", info["frames"] - 1)):
        if name in info:
            checks["profile_" + name] = (
                info[name] == timecode(frame, half_step=selected.half_step).hex().upper())
    checks["selected_profile_consistent"] = all(checks.values())
    return checks


def source_control_identity_checks(info, source, target):
    from build_native_control import update_headers
    from build_source_control import rewrite_xml, xml_semantic
    from uuid import UUID
    old_meta, new_meta = [media.one(media.top, "meta") for media in (source, target)]
    old_xml_box, new_xml_box = [media.child(meta, "xml ", 4)
                              for media, meta in ((source, old_meta), (target, new_meta))]
    old_xml, new_xml = [media.payload(item)[4:].rstrip(b" \x00")
                        for media, item in ((source, old_xml_box), (target, new_xml_box))]
    old_root, new_root = [ET.fromstring(data) for data in (old_xml, new_xml)]
    material = next(x for x in old_root.iter() if x.tag.rsplit("}", 1)[-1] == "TargetMaterial")
    old_umid = material.get("umidRef")
    material.set("umidRef", info["umid"])
    old_root.set("lastUpdate", info["stamp"])
    next(x for x in old_root.iter() if x.tag.rsplit("}", 1)[-1] == "CreationDate").set(
        "value", info["stamp"])
    sidecar = Path(info["source_sidecar"])
    source_xml_payload = source.payload(old_xml_box)[4:]
    source_sidecar_payload = sidecar.read_bytes()
    target_sidecar = target.path.with_name(target.path.stem + "M01.XML").read_bytes()
    trimmed_sidecar = source_sidecar_payload.rstrip(b" \x00")
    expected_embedded = (rewrite_xml(old_xml, info["umid"], info["stamp"]) +
                         source_xml_payload[len(old_xml):])
    expected_sidecar = (rewrite_xml(trimmed_sidecar, info["umid"], info["stamp"]) +
                        source_sidecar_payload[len(trimmed_sidecar):])
    old_bytes, new_bytes = bytes.fromhex(old_umid), bytes.fromhex(info["umid"])
    identity = (len(new_bytes) == 32 and old_bytes[:16] == new_bytes[:16] and
                new_bytes[:16].hex() == "060a2b340101010501010d2313000000" and
                UUID(bytes=new_bytes[16:]).version == 4 and new_bytes != old_bytes)
    observations_path = Path(info["observations_path"])
    raw_observations = observations_path.read_bytes()
    observations = json.loads(raw_observations)
    bound = (
        hashlib.sha256(raw_observations).hexdigest() == info["observations_sha256"] and
        observations.get("scope") == "historical_user_report_not_fresh_retest" and
        any(row.get("clip") == info["source_clip"] and
            row.get("source_sha256") == info["source_sha256"] and
            row.get("camera_playback") == "USER_REPORTED_SUCCESS"
            for row in observations.get("historical_playback_positive", [])))
    qt_stamp = int(datetime.fromisoformat(info["stamp"]).timestamp()) + 2082844800
    same_top = [x.kind for x in source.top] == [x.kind for x in target.top]
    other_boxes = same_top and all(
        a.size == b.size and equal_ranges(source.buf, a.start, target.buf, b.start, a.size)
        for a, b in zip(source.top, target.top) if a.kind not in {"moov", "meta"})
    metadata_headers_exact = (
        old_meta.header == new_meta.header and old_xml_box.header == new_xml_box.header and
        source.buf[old_meta.data:old_meta.data + 4] ==
        target.buf[new_meta.data:new_meta.data + 4] and
        source.buf[old_xml_box.data:old_xml_box.data + 4] ==
        target.buf[new_xml_box.data:new_xml_box.data + 4] and
        [x.kind for x in source.children(old_meta, 4)] ==
        [x.kind for x in target.children(new_meta, 4)])
    checks = {
        "source_identity_verified": (
            digest(source.path) == info["source_sha256"] and
            digest(sidecar) == info["source_sidecar_sha256"] and
            xml_semantic(ET.fromstring(sidecar.read_bytes().rstrip(b" \x00"))) ==
            xml_semantic(ET.fromstring(old_xml)) and
            hashlib.sha256(source.payload(source.child(old_meta, "xml ", 4))[4:]).hexdigest() ==
            info["source_embedded_xml_sha256"] and
            old_umid == info["source_umid"] and identity),
        "source_playback_observation_bound": bound,
        "source_prof_bit_exact": source.raw(source.one(source.top, "uuid")) ==
                                 target.raw(target.one(target.top, "uuid")),
        "source_container_changes_limited_to_identity_and_dates": (
            other_boxes and metadata_headers_exact and
            target.raw(target.moov) == update_headers(source, source.moov, qt_stamp)
            and semantic(old_root) == semantic(new_root) and
            target.payload(new_xml_box)[4:] == expected_embedded and
            [source.raw(x) for x in source.children(old_meta, 4) if x.kind != "xml "] ==
            [target.raw(x) for x in target.children(new_meta, 4) if x.kind != "xml "]),
        "source_sidecar_changes_limited_to_identity_and_dates": target_sidecar == expected_sidecar,
    }
    return checks


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--build", default="output/cat-25m")
    ap.add_argument("--card")
    args = ap.parse_args()
    build = Path(args.build)
    info = json.loads((build / "build-manifest.json").read_text(encoding="utf-8"))
    transaction = json.loads((build / "catalog/transaction.json").read_text(encoding="utf-8"))
    selected = catalog_profile(info, transaction.get("catalog_representation", "native_reuse"))
    clip = info["clip"]
    m, base = MP4(build / (clip + ".MP4")), MP4(info["base"])
    checks = {}
    checks["sample_tables"] = len(m.tracks) == 3
    checks["video_frame_count"] = len(m.tracks[0].sizes) == info["frames"]
    checks["rtmd_frame_count"] = len(m.tracks[2].sizes) == info["frames"]
    checks["audio_bit_exact"] = hash_audio(m) == hash_audio(base, info["audio_samples"])
    profile = info.get("package_kind", "encoded_avc")
    framing_width = (m.tracks[0].avcc()[4] & 3) + 1
    if profile == "encoded_avc":
        checks["qualified_candidate_nal_framing"] = framing_width == 4
    elif profile == "framing_control":
        checks["explicit_diagnostic_framing_control"] = (
            framing_width == info.get("nal_length_size") == 3 and
            info.get("test_role") == "diagnostic_framing_control")
    media_checks, proof = run_media_checks(build, clip, info["base"], info["frames"], profile)
    checks.update(media_checks)
    if profile == "native_control":
        source_sidecar = Path(info["native_source_sidecar"])
        source_xml = base.payload(base.child(base.one(base.top, "meta"), "xml ", 4))[4:].rstrip(b" \x00")
        source_nrt = ET.fromstring(source_xml)
        device = next(x.attrib for x in source_nrt.iter() if x.tag.rsplit("}", 1)[-1] == "Device")
        source_umid = next(x.get("umidRef") for x in source_nrt.iter()
                           if x.tag.rsplit("}", 1)[-1] == "TargetMaterial")
        checks["native_source_identity_verified"] = (
            hashlib.sha256(base.buf).hexdigest() == info["native_source_sha256"] and
            hashlib.sha256(source_sidecar.read_bytes()).hexdigest() == info["native_source_sidecar_sha256"] and
            source_sidecar.read_bytes().rstrip(b" \x00") == source_xml and
            device == info["native_source_device"] and device.get("manufacturer") == "Sony" and
            device.get("modelName", "").startswith("ILCE-") and source_umid == info["source_umid"])
    elif profile == "source_control":
        checks.update(source_control_identity_checks(info, base, m))
    meta = m.one(m.top, "meta")
    nrt = m.child(meta, "xml ", 4)
    xml = m.payload(nrt)[4:]
    sidecar = (build / (clip + "M01.XML")).read_bytes()
    if profile == "source_control":
        from build_source_control import xml_semantic
        checks["embedded_xml_matches_sidecar"] = (
            xml_semantic(ET.fromstring(xml.rstrip(b" \x00"))) ==
            xml_semantic(ET.fromstring(sidecar.rstrip(b" \x00"))))
    else:
        checks["embedded_xml_matches_sidecar"] = xml == sidecar
    nr = ET.fromstring(xml.rstrip(b" \x00"))
    ns = nr.tag.split("}")[0][1:]
    checks["sidecar_umid"] = nr.find(f"{{{ns}}}TargetMaterial").get("umidRef") == info["umid"]
    checks["sidecar_duration"] = int(nr.find(f"{{{ns}}}Duration").get("value")) == info["frames"]
    items = {x.get("name"): x.get("value") for x in nr.iter()
             if x.tag.rsplit("}", 1)[-1] == "Item"}
    expected_acquisition = info.get("acquisition", "unspecified")
    checks["xml_acquisition_matches_manifest"] = (
        all(items.get(name) == "rec709" for name in
            ("CaptureGammaEquation", "CaptureColorPrimaries", "CodingEquations"))
        if expected_acquisition == "rec709" else
        not any(name in items for name in
                ("CaptureGammaEquation", "CaptureColorPrimaries", "CodingEquations")))
    stream_probe = probe_input(build / (clip + ".MP4"))
    if expected_acquisition == "rec709":
        checks["rec709_stream_and_acquisition_agree"] = rec709_stream_matches(stream_probe)
    prof = m.one(m.top, "uuid")
    vprf = m.one(m.boxes(prof.data + 24, prof.end), "VPRF")
    fields = m.payload(vprf)
    if profile == "native_control" or (
            profile in {"encoded_avc", "framing_control"} and selected.name == DEFAULT_PROFILE):
        checks["prof_avc_high_42"] = fields[8:16] == b"avc1\x01\x64\x00\x2a"
        checks["prof_25m_5994"] = struct.unpack_from(">4I", fields, 20) == (25000, 25000, 3928230, 3928230)
    if info.get("structure_template"):
        checks["structure_template_hash_bound"] = (
            digest(info["structure_template"]) == info["structure_template_sha256"])
        checks["payload_offset_matches_declared_layout"] = (
            m.one(m.top, "mdat").data == info["first_mdat_payload_offset"])
        if info.get("umid_mode") == "edius_uuid4":
            from uuid import UUID
            value = bytes.fromhex(info["umid"])
            checks["edius_uuid4_identity_encoding"] = (
                value[:16].hex() == "060a2b340101010501010d2313000000" and
                len(value) == 32 and UUID(bytes=value[16:]).version == 4)
    if "nal_length_size" in info:
        checks["nal_framing_matches_manifest"] = (
            (m.tracks[0].avcc()[4] & 3) + 1 == info["nal_length_size"])
    db = (build / "catalog/DATABASE.BIN").read_bytes()
    before = (Path(transaction["snapshot"]) / "PRIVATE/DATABASE/DATABASE.BIN").read_bytes()
    before_mp = (Path(transaction["snapshot"]) / "PRIVATE/M4ROOT/MEDIAPRO.XML").read_bytes()
    checks["catalog_baseline_hashes_bound"] = (
        hashlib.sha256(before).hexdigest() == transaction["database_before_sha256"] and
        hashlib.sha256(before_mp).hexdigest() == transaction["mediapro_before_sha256"] and
        hashlib.sha256(db).hexdigest() == transaction["database_after_sha256"] and
        hashlib.sha256((build / "catalog/MEDIAPRO.XML").read_bytes()).hexdigest() ==
        transaction["mediapro_after_sha256"] and transaction["clip"] == clip)
    records = inventory(db)
    old_records = inventory(before)
    checks["sd_header_checksums"] = all(x["valid"] for x in check_regions(db))
    checks["sd_record_checksums"] = all(x["checksum_valid"] for x in records if x["index"])
    representation = transaction.get("catalog_representation", "native_reuse")
    if transaction.get("catalog_schema") in {2, 3}:
        try:
            validate_catalog_changes(before, db, transaction)
            checks["sd_only_declared_native_catalog_changes"] = True
        except ValueError:
            checks["sd_only_declared_native_catalog_changes"] = False
    else:
        checks["sd_existing_records_unchanged"] = all(
            db[int(r["offset"], 16):int(r["offset"], 16)+160] ==
            before[int(r["offset"], 16):int(r["offset"], 16)+160] for r in old_records)
    movies = [r for r in records if r.get("content_type") == 2]
    ours = [r for r in movies if r["clip_number"] == int(clip[1:])]
    checks["sd_one_new_movie"] = (len(ours) == 1 and
                                 len(records) == len(old_records) + len(transaction["new_records"]) and
                                 len(movies) == sum(r.get("content_type") == 2 for r in old_records) + 1)
    support = next(r for r in records if r["index"] == ours[0]["video_info_ref"])
    record = bytes.fromhex(ours[0]["hex"])
    array_id = struct.unpack_from("<H", record, 0x5A)[0] | ((record[0x5C] >> 5 & 1) << 16)
    if representation == "observed_minimal":
        rebuilt, _ = catalog_records(
            before, info, transaction["template_number"],
            (build / (clip + ".MP4")).stat().st_size,
            (build / (clip + "T01.JPG")).stat().st_size,
            datetime.fromisoformat(transaction["updated_stamp"]), representation,
            transaction.get("template_source_snapshot"))
        checks["sd_minimal_catalog_rebuilt_exactly"] = bytes(rebuilt) == db
        if transaction.get("template_source_snapshot"):
            from stage_sd_catalog import minimal_template_data
            minimal_template_data(before, transaction["template_source_snapshot"],
                                  transaction["template_source_database_sha256"])
            checks["sd_historical_template_bound_to_fresh_dependencies"] = True
        video = bytes.fromhex(support["hex"])
        checks["sd_metadata_omission_matches_positive_template"] = (
            array_id == 0 and record[0x20:0x50] == bytes(48) and
            video[10:158] == bytes(148))
        observations_path = Path(transaction["observations_path"])
        observations_raw = observations_path.read_bytes()
        observations = json.loads(observations_raw)
        checks["sd_positive_template_observation_bound"] = (
            hashlib.sha256(observations_raw).hexdigest() == transaction["observations_sha256"] and
            f"C{transaction['template_number']:04d}" in
            observations["current_listing_positive_examples_not_exhaustive"])
    else:
        if profile == "source_control":
            raise ValueError("UUID source controls require observed-minimal catalog; native UMID reconstruction is inapplicable")
        checks["sd_25m_parameter_record"] = struct.unpack_from("<H", bytes.fromhex(support["hex"]), 12)[0] == 25
        checks["sd_acquisition_matches_xml"] = bytes.fromhex(support["hex"])[27:30] == acquisition_bytes(info)
        array_record = bytes.fromhex(next(r for r in records if r["index"] == array_id)["hex"])
        checks["firmware_restored_umid_matches_xml"] = restore_umid(record, array_record).hex().upper() == info["umid"]
    root = ET.fromstring((build / "catalog/MEDIAPRO.XML").read_bytes())
    old_root = ET.fromstring((Path(transaction["snapshot"]) / "PRIVATE/M4ROOT/MEDIAPRO.XML").read_bytes())
    old_materials = list(old_root.find(f"{{{MPF}}}Contents"))
    materials = list(root.find(f"{{{MPF}}}Contents"))
    checks["mediapro_existing_materials_unchanged"] = all(
        semantic(a) == semantic(b) for a, b in zip(old_materials, materials))
    checks["mediapro_one_addition"] = len(materials) == len(old_materials) + 1
    added = materials[-1]
    checks["mediapro_identity"] = (
        added.get("uri") == f"./CLIP/{clip}.MP4" and added.get("umid") == info["umid"] and
        added.get("dur") == str(info["frames"]))
    if profile in {"encoded_avc", "framing_control"}:
        try:
            timing_report = json.loads((Path(proof["directory"]) / "timing.json").read_text(encoding="utf-8"))
        except (OSError, ValueError):
            timing_report = {}
        rtmd_source = MP4(info["rtmd_template"])
        try:
            rtmd_tracks = [t for t in rtmd_source.tracks if t.codec == "rtmd"]
            if len(rtmd_tracks) != 1:
                raise ValueError("Expected one RTMD template track")
            rtmd_template = rtmd_tracks[0].sample(0)
            proof["rtmd_template"] = {
                "path": str(rtmd_source.path.resolve()),
                "sha256": digest(rtmd_source.path),
                "seed_sha256": hashlib.sha256(rtmd_template).hexdigest(),
                "observed_start_timecode": rtmd_template[20:24].hex().upper(),
            }
        finally:
            rtmd_source.close()
        checks.update(selected_profile_checks(
            info, m, stream_probe, nr, added, timing_report, rtmd_template, base))
    checks["db_xml_video_count"] = len(movies) == len(materials) == struct.unpack_from("<I", db, 0x7C88)[0]
    report = {"checks": checks, "passed": all(checks.values()), "camera_playback": "NOT_TESTED",
              "verification_profile": profile, "camera_listing": "NOT_TESTED",
              "catalog_representation": representation,
              "catalog_omissions": (["video parameters", "UMID", "timecodes"]
                                    if representation == "observed_minimal" else []),
              "acquisition": expected_acquisition,
              "frames": info["frames"], "video_bitrate": info["video_bitrate"],
              "verification_schema": SCHEMA, "fresh_media_evidence": proof}
    if profile in {"encoded_avc", "framing_control"}:
        report.update(sony_profile=selected.name, profile_parameters=selected.manifest_fields())
    if profile == "source_control":
        report["prof_interpretation"] = {
            "classification": "observed_source_opaque",
            "validated_standard_profile_descriptor": False,
            "criterion": "Exact bytes of the hash-bound historical source",
            "nominal_video_bitrate_mbps_historical_report": info["nominal_video_bitrate_mbps"]}
        report["xml_match_mode"] = "Semantic; each source serialization preserved except identity/dates"
    elif profile == "framing_control":
        report["camera_format_claim"] = "DIAGNOSTIC_FRAMING_CONTROL_ONLY"
        report["standards_conformance_claim"] = False
    report["stream_color_evidence"] = [
        {key: stream.get(key) for key in
         ("codec_type", "color_range", "color_space", "color_transfer", "color_primaries")}
        for stream in stream_probe.get("streams", []) if stream.get("codec_type") == "video"]
    report["package_hashes"] = {
        name: digest(build / name)
        for name in [clip + ".MP4", clip + "M01.XML", clip + "T01.JPG",
                     "catalog/DATABASE.BIN", "catalog/MEDIAPRO.XML",
                     "catalog/transaction.json", "build-manifest.json"]}
    if args.card:
        card = Path(args.card)
        mapping = {clip + ".MP4": f"PRIVATE/M4ROOT/CLIP/{clip}.MP4",
                   clip + "M01.XML": f"PRIVATE/M4ROOT/CLIP/{clip}M01.XML",
                   clip + "T01.JPG": f"PRIVATE/M4ROOT/THMBNL/{clip}T01.JPG",
                   "catalog/DATABASE.BIN": "PRIVATE/DATABASE/DATABASE.BIN",
                   "catalog/MEDIAPRO.XML": "PRIVATE/M4ROOT/MEDIAPRO.XML"}
        checks["card_readback_all_five_files"] = all(
            digest(card / rel) == report["package_hashes"][local]
            for local, rel in mapping.items())
        report["passed"] = all(checks.values())
    (build / "verification.json").write_text(json.dumps(report, indent=2), encoding="utf-8")
    m.close()
    base.close()
    print(json.dumps(report, indent=2))
    if not report["passed"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
