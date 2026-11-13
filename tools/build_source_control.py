"""Purpose: build a new-identity control from the historical successful C0007.

Usage: python tools/build_source_control.py --source REFERENCE.MP4
    --snapshot SNAP --clip Cnnnn --output NEW_DIRECTORY --observations REPORT
    [--thumbnail LOCAL_SOURCE.JPG].
Design: require hash-bound observations, stream-copy the source payload and
    opaque PROF, and change only allowed XML identity and container timestamps.
Scope: local historical-source control, not native-camera control, re-encoding
    or deployment. Source provenance and supported metadata layout are mandatory.
"""
import argparse
import hashlib
import json
import re
import struct
import uuid
from contextlib import closing
from datetime import datetime, timedelta, timezone
from pathlib import Path
from xml.etree import ElementTree as ET
from xml.parsers import expat

from sony_mp4 import MP4


SOURCE_CLIP = "C0007"
UMID_PREFIX = bytes.fromhex("060A2B340101010501010D2313000000")
PROF_UUID = bytes.fromhex("50524f4621d24fcebb88695cfac9c740")
OBSERVATION_SCOPE = "historical_user_report_not_fresh_retest"
COPY_BLOCK = 1024 * 1024
METADATA_LIMIT = 64 * 1024 * 1024


def digest(path):
    with Path(path).open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def range_digest(stream, start, size):
    stream.seek(start)
    result = hashlib.sha256()
    while size:
        block = stream.read(min(size, COPY_BLOCK))
        if not block:
            raise ValueError("Truncated source range")
        result.update(block)
        size -= len(block)
    return result.hexdigest()


def copy_range(source, target, start, size):
    source.seek(start)
    while size:
        block = source.read(min(size, COPY_BLOCK))
        if not block:
            raise ValueError("Truncated source while copying")
        if target.write(block) != len(block):
            raise OSError("Short output write")
        size -= len(block)


def metadata_raw(media, item):
    if item.size > METADATA_LIMIT:
        raise ValueError("Unsupported oversized metadata box")
    return media.raw(item)


def load_observation(path, source_sha256):
    raw = Path(path).read_bytes()
    report = json.loads(raw)
    if not isinstance(report, dict) or report.get("scope") != OBSERVATION_SCOPE:
        raise ValueError("Expected explicitly historical playback observation")
    entries = report.get("historical_playback_positive")
    if not isinstance(entries, list) or any(not isinstance(x, dict) for x in entries):
        raise ValueError("Expected historical playback entries")
    matches = [entry for entry in entries if entry.get("clip") == SOURCE_CLIP]
    if len(matches) != 1:
        raise ValueError("Require exactly one historical C0007 observation")
    entry = matches[0]
    expected = entry.get("source_sha256")
    provenance = entry.get("provenance")
    if (not isinstance(expected, str) or
            re.fullmatch(r"[0-9a-fA-F]{64}", expected) is None or
            expected.lower() != source_sha256 or
            entry.get("camera_playback") != "USER_REPORTED_SUCCESS" or
            not isinstance(provenance, str) or not provenance.strip()):
        raise ValueError("Historical playback must bind the source hash and real provenance")
    return hashlib.sha256(raw).hexdigest(), entry


def output_paths(source, snapshot, output):
    source, snapshot, output = (Path(p).resolve() for p in (source, snapshot, output))
    if not source.is_file():
        raise ValueError("Source must be an existing file")
    info = json.loads((snapshot / "_snapshot.json").read_bytes())
    card = info.get("card")
    if not isinstance(card, str) or not Path(card).is_absolute():
        raise ValueError("Snapshot must identify an absolute source card root")
    card = Path(card).resolve()
    if (output.exists() or output.drive.upper() == "F:" or
            output.is_relative_to(source) or output.is_relative_to(snapshot) or
            output.is_relative_to(card)):
        raise ValueError("Output must be fresh and outside the source, snapshot and card")
    return source, snapshot, output, card


def xml_semantic(node):
    text = node.text if node.text and node.text.strip() else None
    tail = node.tail if node.tail and node.tail.strip() else None
    return node.tag, node.attrib, text, tail, [xml_semantic(child) for child in node]


def xml_node(root, name):
    matches = [x for x in root.iter() if x.tag.rsplit("}", 1)[-1] == name]
    if len(matches) != 1:
        raise ValueError(f"Expected exactly one XML {name}")
    return matches[0]


def rewrite_xml(raw, umid, stamp):
    """Use parser byte offsets to retain the original XML outside three values."""
    parser = expat.ParserCreate(namespace_separator="}")
    replacements = []
    counts = {"NonRealTimeMeta": 0, "TargetMaterial": 0, "CreationDate": 0}

    def element(name, attributes):
        local = name.rsplit("}", 1)[-1]
        if local not in counts:
            return
        counts[local] += 1
        attribute, value = {
            "NonRealTimeMeta": ("lastUpdate", stamp),
            "TargetMaterial": ("umidRef", umid),
            "CreationDate": ("value", stamp),
        }[local]
        if attribute not in attributes:
            raise ValueError(f"Missing {local}.{attribute}")
        start = parser.CurrentByteIndex
        quote, end = None, start
        while end < len(raw):
            char = raw[end]
            if quote is not None:
                if char == quote:
                    quote = None
            elif char in (34, 39):
                quote = char
            elif char == 62:
                break
            end += 1
        if end == len(raw):
            raise ValueError("Unterminated XML start tag")
        pattern = rb"([^\s=<>/]+)\s*=\s*(['\"])(.*?)\2"
        matches = [m for m in re.finditer(pattern, raw[start:end], re.DOTALL)
                   if m.group(1) == attribute.encode("ascii")]
        if len(matches) != 1:
            raise ValueError("Ambiguous XML attribute")
        match = matches[0]
        replacements.append((start + match.start(3), start + match.end(3),
                             value.encode("ascii")))

    parser.StartElementHandler = element
    parser.Parse(raw, True)
    if any(count != 1 for count in counts.values()):
        raise ValueError("Expected one root, material identity and creation date")
    result = raw
    for start, end, value in sorted(replacements, reverse=True):
        result = result[:start] + value + result[end:]
    return result


def stamp_ranges(media):
    ranges = []

    def visit(parent):
        for item in media.children(parent):
            if item.kind in {"mvhd", "tkhd", "mdhd"}:
                version = media.buf[item.data]
                if version not in (0, 1):
                    raise ValueError("Unsupported container header version")
                width = 8 if version else 4
                start = item.data + 4
                if start + 2 * width > item.end:
                    raise ValueError("Truncated container stamp")
                ranges.append((start, width))
            elif item.kind in {"trak", "mdia"}:
                visit(item)
    media.child(media.moov, "mvhd")
    for track in media.tracks:
        media.child(track.box, "tkhd")
    visit(media.moov)
    return ranges


def stamped_moov(media, stamp):
    result = bytearray(metadata_raw(media, media.moov))
    for start, width in stamp_ranges(media):
        struct.pack_into(">QQ" if width == 8 else ">II", result,
                         start - media.moov.start, stamp, stamp)
    return bytes(result)


def resized_box(media, item, payload):
    header = bytearray(media.buf[item.start:item.data])
    size = len(header) + len(payload)
    original_size = struct.unpack_from(">I", header)[0]
    if original_size == 1:
        struct.pack_into(">Q", header, 8, size)
    elif original_size:
        struct.pack_into(">I", header, 0, size)
    return bytes(header) + payload


def source_payload_checks(source, target):
    """Prove sample identity from unchanged mappings and streamed whole mdats."""
    with closing(MP4(source)) as a, closing(MP4(target)) as b:
        def mdats(media):
            return [(x.start, x.size, range_digest(media.file, x.start, x.size))
                    for x in media.top if x.kind == "mdat"]

        def other_boxes(media):
            return [(x.kind, x.start, x.size, range_digest(media.file, x.start, x.size))
                    for x in media.top if x.kind not in {"mdat", "moov", "meta"}]

        def profiles(media):
            return [metadata_raw(media, x) for x in media.top if x.kind == "uuid" and
                    media.buf[x.data:x.data + 16] == PROF_UUID]

        mdat_match = mdats(a) == mdats(b)
        config_match = stamped_moov(a, 0) == stamped_moov(b, 0)
        source_prof, target_prof = profiles(a), profiles(b)
        return {
            "source_mdat_bit_exact": mdat_match,
            "source_track_configuration_bit_exact": config_match,
            "source_track_payloads_bit_exact": mdat_match and config_match,
            "source_prof_bit_exact": len(source_prof) == 1 and source_prof == target_prof,
            "source_other_top_boxes_bit_exact": other_boxes(a) == other_boxes(b),
        }


def build_source_control(source, snapshot, clip, output, observations, thumbnail=None):
    source, snapshot, output, card = output_paths(source, snapshot, output)
    if re.fullmatch(r"C[0-9]{4}", clip) is None or clip == SOURCE_CLIP:
        raise ValueError("Expected a new four-digit clip identity")
    observations = Path(observations).resolve()
    source_sha256 = digest(source)
    observations_sha256, observation = load_observation(observations, source_sha256)
    sidecar = snapshot / f"PRIVATE/M4ROOT/CLIP/{SOURCE_CLIP}M01.XML"
    sidecar_raw = sidecar.read_bytes()
    thumbnail = (Path(thumbnail).resolve() if thumbnail is not None else
                 card / f"PRIVATE/M4ROOT/THMBNL/{SOURCE_CLIP}T01.JPG")
    thumbnail_sha256 = digest(thumbnail)
    stamp_dt = datetime.now(timezone(timedelta(hours=8))).replace(microsecond=0)
    stamp = stamp_dt.isoformat()
    umid = (UMID_PREFIX + uuid.uuid4().bytes).hex().upper()

    with closing(MP4(source)) as media:
        meta = media.one(media.top, "meta")
        if media.top[-1] != meta:
            raise ValueError("Source XML must be in the final top-level meta box")
        metadata_raw(media, meta)
        xml_box = media.child(meta, "xml ", 4)
        xml_raw = media.payload(xml_box)[4:]
        root = ET.fromstring(xml_raw.rstrip(b" \x00"))
        if root.tag.rsplit("}", 1)[-1] != "NonRealTimeMeta":
            raise ValueError("Expected source NRT XML")
        if xml_semantic(root) != xml_semantic(ET.fromstring(sidecar_raw.rstrip(b" \x00"))):
            raise ValueError("Source embedded XML differs semantically from snapshot sidecar")
        source_umid = xml_node(root, "TargetMaterial").get("umidRef")
        if (not isinstance(source_umid, str) or
                re.fullmatch(r"[0-9a-fA-F]{64}", source_umid) is None or
                bytes.fromhex(source_umid)[:16] != UMID_PREFIX):
            raise ValueError("Expected observed EDIUS-label source UMID")
        if umid == source_umid.upper():
            raise ValueError("Source control requires a new UMID")
        if [(t.handler, t.codec) for t in media.tracks] != [
                ("vide", "avc1"), ("soun", "twos"), ("meta", "rtmd")]:
            raise ValueError("Unsupported source track layout")
        video, audio, rtmd = media.tracks
        frames = len(video.sizes)
        if (not frames or video.timescale != 60000 or video.stts != [(frames, 1001)] or
                rtmd.timescale != video.timescale or rtmd.duration != video.duration or
                len(rtmd.sizes) != frames or audio.timescale != 48000 or
                int(xml_node(root, "Duration").get("value")) != frames):
            raise ValueError("Unsupported source cadence or XML duration")
        items = {x.get("name"): x.get("value") for x in root.iter()
                 if x.tag.rsplit("}", 1)[-1] == "Item"}
        colors = [items.get(name) for name in
                  ("CaptureGammaEquation", "CaptureColorPrimaries", "CodingEquations")]
        if all(value is None for value in colors):
            acquisition = "unspecified"
        elif colors == ["rec709"] * 3:
            acquisition = "rec709"
        else:
            raise ValueError("Unsupported source acquisition declaration")
        profiles = [x for x in media.top if x.kind == "uuid" and
                    media.buf[x.data:x.data + 16] == PROF_UUID]
        if len(profiles) != 1:
            raise ValueError("Expected exactly one preserved source PROF")
        source_prof_sha256 = hashlib.sha256(metadata_raw(media, profiles[0])).hexdigest()
        times = [x for x in root.iter() if x.tag.rsplit("}", 1)[-1] == "LtcChange"]
        if len(times) < 2 or any(re.fullmatch(r"[0-9A-Fa-f]{8}", x.get("value", "")) is None
                                 for x in (times[0], times[-1])):
            raise ValueError("Expected source start/end timecodes")
        trimmed_xml = xml_raw.rstrip(b" \x00")
        new_xml = rewrite_xml(trimmed_xml, umid, stamp) + xml_raw[len(trimmed_xml):]
        trimmed_sidecar = sidecar_raw.rstrip(b" \x00")
        new_sidecar = (rewrite_xml(trimmed_sidecar, umid, stamp) +
                       sidecar_raw[len(trimmed_sidecar):])
        xml_payload = media.buf[xml_box.data:xml_box.data + 4] + new_xml
        meta_payload = media.buf[meta.data:meta.data + 4] + b"".join(
            resized_box(media, item, xml_payload) if item == xml_box else metadata_raw(media, item)
            for item in media.children(meta, 4))
        new_meta = resized_box(media, meta, meta_payload)
        new_moov = stamped_moov(media, int(stamp_dt.timestamp()) + 2082844800)
        manifest = {
            "clip": clip, "umid": umid, "stamp": stamp,
            "package_kind": "source_control", "base": str(source),
            "source_clip": SOURCE_CLIP, "source_sha256": source_sha256,
            "source_umid": source_umid, "umid_mode": "edius_label_uuid4",
            "source_sidecar": str(sidecar), "source_sidecar_sha256": hashlib.sha256(sidecar_raw).hexdigest(),
            "source_sidecar_match": "xml_semantic",
            "source_embedded_xml_sha256": hashlib.sha256(xml_raw).hexdigest(),
            "source_thumbnail": str(thumbnail), "source_thumbnail_sha256": thumbnail_sha256,
            "observations_path": str(observations), "observations_sha256": observations_sha256,
            "source_playback_observation": observation, "observation_scope": OBSERVATION_SCOPE,
            "frames": frames, "duration_ticks": video.duration, "timescale": video.timescale,
            "audio_samples": len(audio.sizes), "acquisition": acquisition,
            "start_timecode": times[0].get("value"), "end_timecode": times[-1].get("value"),
            "video_bitrate": sum(video.sizes) * 8 * video.timescale / video.duration,
            "nominal_video_bitrate_mbps": 50,
            "nominal_video_bitrate_basis": "historical_user_report",
            "prof_classification": "observed_source_opaque",
            "source_prof_sha256": source_prof_sha256,
            "camera_listing": "NOT_TESTED", "camera_playback": "NOT_TESTED",
            "changes": ["top XML identity and dates", "container creation/modification times"],
            "preserved": ["whole mdat including padding", "all coded track samples",
                          "all track configuration except header stamps", "opaque source PROF",
                          "source timecodes", "source thumbnail"],
        }
        output.mkdir(parents=True, exist_ok=False)
        target = output / (clip + ".MP4")
        with target.open("xb") as stream:
            for item in media.top:
                if item == meta:
                    stream.write(new_meta)
                elif item == media.moov:
                    stream.write(new_moov)
                else:
                    copy_range(media.file, stream, item.start, item.size)

    with (output / (clip + "M01.XML")).open("xb") as stream:
        stream.write(new_sidecar)
    with thumbnail.open("rb") as src, (output / (clip + "T01.JPG")).open("xb") as dst:
        copy_range(src, dst, 0, thumbnail.stat().st_size)
    checks = source_payload_checks(source, target)
    if (not all(checks.values()) or digest(source) != source_sha256 or
            digest(sidecar) != manifest["source_sidecar_sha256"] or
            digest(observations) != observations_sha256 or
            digest(thumbnail) != thumbnail_sha256 or
            digest(output / (clip + "T01.JPG")) != thumbnail_sha256):
        raise ValueError("Source evidence changed or payload preservation failed")
    manifest["source_preservation_checks"] = checks
    manifest["sha256"] = digest(target)
    with (output / "build-manifest.json").open("x", encoding="utf-8") as stream:
        stream.write(json.dumps(manifest, indent=2))
    return manifest


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ("source", "snapshot", "clip", "output", "observations"):
        parser.add_argument("--" + name, required=True)
    parser.add_argument("--thumbnail", help="Explicit source C0007 thumbnail instead of snapshot card path")
    args = parser.parse_args()
    manifest = build_source_control(**vars(args))
    print(json.dumps(manifest, indent=2))


if __name__ == "__main__":
    main()
