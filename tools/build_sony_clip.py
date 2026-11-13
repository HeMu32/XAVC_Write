"""Purpose: package encoded AVC/PCM into a Sony SD XAVC-S candidate.

Usage: python tools/build_sony_clip.py --base BASE.mov --camera NATIVE.MP4
    --edius EDIUS.MP4 --clip Cnnnn --output DIRECTORY --profile hd25_5994.
Design: validate explicit profiles, normalize VUI/dual-HRD/SEI and NAL lengths,
    rebuild track tables/PROF, and emit matching RTMD, embedded XML and sidecar.
Scope: explicit modeled 8-bit 4:2:0 profiles and supported templates, below the
    builder's 4-GiB limit. No card deployment or arbitrary-input certification;
    3-byte framing is a diagnostic control, not the successful production path.
"""
import argparse
import hashlib
import json
import struct
import uuid
from datetime import datetime, timezone, timedelta
from pathlib import Path
from xml.etree import ElementTree as ET

from avc_sony import avcc_normalize, normalize_sample
from avc_hrd import nals, retime_cbr_samples
from sony_mp4 import MP4, ConstantSizes, box, fullbox, u32
from sony_umid import make_umid
from sony_rtmd import timecode, make_packet
from sony_profiles import DEFAULT_PROFILE, PROFILES, get_profile

NRT = "urn:schemas-professionalDisc:nonRealTimeMeta:ver.2.00"
MPF = "http://xmlns.sony.net/pro/metadata/mediaprofile"
ET.register_namespace("", NRT)


def align_pcm(audio, frames, profile=DEFAULT_PROFILE):
    if len(audio) % 4 or frames < 1:
        raise ValueError("Expected complete stereo PCM samples and at least one frame")
    samples = get_profile(profile).audio_boundary(frames)
    return audio[:samples * 4] + bytes(max(0, samples * 4 - len(audio)))


def ediustype_umid(source_umid):
    value = bytes.fromhex(source_umid)
    if len(value) != 32 or value[:16].hex() != "060a2b340101010501010d2313000000":
        raise ValueError("Expected observed EDIUS UUID-based UMID label")
    return (value[:16] + uuid.uuid4().bytes).hex().upper()


def payload_prefix(ftyp, prof, payload_start):
    prefix = ftyp + prof
    gap = payload_start - len(prefix) - 16
    if gap < 0 or 0 < gap < 8:
        raise ValueError("Unsupported first mdat payload offset")
    return prefix + (box("free", bytes(gap - 8)) if gap else b"")


def reframe_sample(sample, before, after):
    if before not in (3, 4) or after not in (3, 4):
        raise ValueError("Only three/four-byte framing is supported")
    units = nals(sample, before)
    if any(len(nal) >= 1 << (8 * after) for nal in units):
        raise ValueError("NAL exceeds selected length field")
    return b"".join(len(nal).to_bytes(after, "big") + nal for nal in units)


def table(kind, rows):
    width = len(rows[0])
    return fullbox(kind, struct.pack(">I", len(rows)) +
                   b"".join(struct.pack(">" + "I" * width, *r) for r in rows))


def nrt_xml(umid, frames, stamp, acquisition="unspecified", profile=DEFAULT_PROFILE):
    selected = get_profile(profile)
    root = ET.Element("NonRealTimeMeta", {"xmlns": NRT, "lastUpdate": stamp})
    ET.SubElement(root, "TargetMaterial", umidRef=umid)
    ET.SubElement(root, "Duration", value=str(frames))
    ltc = ET.SubElement(root, "LtcChangeTable", tcFps="30",
                        halfStep=str(selected.half_step).lower())
    ET.SubElement(ltc, "LtcChange", frameCount="0",
                  value=timecode(0, selected.half_step).hex().upper(), status="increment")
    ET.SubElement(ltc, "LtcChange", frameCount=str(frames-1),
                  value=timecode(frames-1, selected.half_step).hex().upper(), status="end")
    ET.SubElement(root, "CreationDate", value=stamp)
    ET.SubElement(root, "TypicalUbit", value="0000000000000000")
    ET.SubElement(root, "KeyFrame", frameCount="0")
    video = ET.SubElement(root, "VideoFormat")
    ET.SubElement(video, "VideoRecPort", port="OTHERS")
    ET.SubElement(video, "VideoFrame", videoCodec=selected.video_codec,
                  captureFps=selected.xml_fps, formatFps=selected.xml_fps)
    ET.SubElement(video, "VideoLayout", pixel=str(selected.width),
                  numOfVerticalLine=str(selected.height), aspectRatio="16:9")
    audio = ET.SubElement(root, "AudioFormat", numOfChannel="2")
    for i in (1, 2):
        ET.SubElement(audio, "AudioRecPort", port="OTHERS", audioCodec="LPCM16", trackDst=f"CH{i}")
    ET.SubElement(root, "RecordingMode", type="normal", cacheRec="false")
    if acquisition == "rec709":
        record = ET.SubElement(root, "AcquisitionRecord")
        group = ET.SubElement(record, "Group", name="CameraUnitMetadataSet")
        for name in ("CaptureGammaEquation", "CaptureColorPrimaries", "CodingEquations"):
            ET.SubElement(group, "Item", name=name, value="rec709")
    elif acquisition != "unspecified":
        raise ValueError("Unsupported acquisition")
    ET.indent(root, space="  ")
    return b'<?xml version="1.0" encoding="UTF-8"?>\n' + ET.tostring(root, encoding="utf-8") + b"\n"


def patched_header(m, b, duration=None, timescale=None, track_id=None, stamp=None, dimensions=None):
    raw = bytearray(m.payload(b))
    if raw[0] != 0:
        raise ValueError("Only version-0 headers supported")
    if stamp is not None:
        struct.pack_into(">II", raw, 4, stamp, stamp)
    if b.kind in {"mvhd", "mdhd"}:
        if timescale is not None:
            struct.pack_into(">I", raw, 12, timescale)
        if duration is not None:
            struct.pack_into(">I", raw, 16, duration)
    if b.kind == "tkhd":
        if duration is not None:
            struct.pack_into(">I", raw, 20, duration)
        if track_id is not None:
            struct.pack_into(">I", raw, 12, track_id)
        if dimensions is not None:
            struct.pack_into(">II", raw, 76, *(value << 16 for value in dimensions))
    return box(b.kind, raw)


def make_track(template, entry, sizes, chunks, counts, stts, ctts, sync, movie_duration,
               media_duration, timescale, media_time, stamp, dimensions=None):
    m = template.m
    if isinstance(sizes, ConstantSizes) or all(x == sizes[0] for x in sizes):
        stsz = fullbox("stsz", struct.pack(">II", sizes[0], len(sizes)))
    else:
        stsz = fullbox("stsz", struct.pack(">II", 0, len(sizes)) +
                       struct.pack(">" + "I" * len(sizes), *sizes))
    runs = []
    for i, count in enumerate(counts, 1):
        if not runs or runs[-1][1] != count:
            runs.append((i, count, 1))
    stbl = fullbox("stsd", struct.pack(">I", 1) + entry) + table("stts", stts)
    if ctts:
        stbl += ctts
    stbl += table("stsc", runs) + stsz + table("stco", [(p,) for p in chunks])
    if sync:
        stbl += table("stss", [(x,) for x in sync])
    minf = m.child(template.mdia, "minf")
    new_minf = box("minf", b"".join(box("stbl", stbl) if b.kind == "stbl" else m.raw(b)
                                   for b in m.children(minf)))
    mdia = box("mdia", b"".join(
        patched_header(m, b, media_duration, timescale, stamp=stamp) if b.kind == "mdhd"
        else new_minf if b.kind == "minf" else m.raw(b) for b in m.children(template.mdia)))
    edts = box("edts", fullbox("elst", struct.pack(">IIiI", 1, movie_duration, media_time, 65536)))
    result = []
    seen_edts = False
    for b in m.children(template.box):
        if b.kind == "tkhd":
            result.append(patched_header(m, b, movie_duration, stamp=stamp, dimensions=dimensions))
        elif b.kind == "edts":
            result.append(edts)
            seen_edts = True
        elif b.kind == "mdia":
            if not seen_edts:
                result.append(edts)
                seen_edts = True
            result.append(mdia)
        else:
            result.append(m.raw(b))
    return box("trak", b"".join(result))


def validate_base_profile(track, infos, selected):
    entry = track.m.payload(track.entry)
    if (track.codec != "avc1" or struct.unpack_from(">HH", entry, 24) !=
            (selected.width, selected.height) or
            track.avcc()[1:4] != bytes([100, 0, selected.level_idc])):
        raise ValueError("Base video description disagrees with selected profile")
    if len(infos) != 1:
        raise ValueError("Expected one unchanging SPS")
    info = next(iter(infos.values()))
    if (info["width"], info["height"], info["level_idc"]) != (
            selected.width, selected.height, selected.level_idc):
        raise ValueError("Base SPS dimensions or level disagree with selected profile")
    hrd = info["hrd"]
    target = selected.bitrate_kbps * 1000
    if (hrd["count"] != 1 or hrd["cbr"] != [1] or
            not hrd["rates"][0] <= target < hrd["rates"][0] + (64 << hrd["rate_scale"]) or
            not hrd["sizes"][0] <= target < hrd["sizes"][0] + (16 << hrd["size_scale"])):
        raise ValueError("Base HRD rate or buffer size disagrees with selected profile")


def validate_pcm_entry(track):
    entry = track.m.payload(track.entry)
    if (track.codec != "twos" or len(entry) < 28 or
            struct.unpack_from(">HH", entry, 16) != (2, 16) or
            u32(entry, 24) != 48000 << 16):
        raise ValueError("Expected stereo 16-bit big-endian PCM at 48 kHz in every audio description")


def profile_descriptor(camera, selected):
    prof = camera.one(camera.top, "uuid")
    payload = bytearray(camera.payload(prof))
    if payload[:16] != bytes.fromhex("50524f46 21d24fce bb88695c fac9c740"):
        raise ValueError("Expected PROF UUID")
    children = camera.boxes(prof.data + 24, prof.end)
    vprf = camera.one(children, "VPRF")
    data = bytearray(camera.payload(vprf))
    if (len(data) != 44 or data[:15] !=
            bytes.fromhex("000000000000000161766331016400") or
            data[16:20] != bytes.fromhex("00030002")):
        raise ValueError("Expected valid single High 4:2:0 VPRF; opaque patched PROF is not a template")
    data[15] = selected.level_idc
    struct.pack_into(">4IHH", data, 20, selected.bitrate_kbps, selected.bitrate_kbps,
                     selected.prof_fps, selected.prof_fps, selected.width, selected.height)
    start = vprf.data - prof.data
    payload[start:start + len(data)] = data
    return box("uuid", payload)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--base", default="output/cat-25m/base.mov")
    ap.add_argument("--camera", default="F:/PRIVATE/M4ROOT/CLIP/C6359.MP4")
    ap.add_argument("--edius", default="F:/PRIVATE/M4ROOT/CLIP/C0007.MP4")
    ap.add_argument("--output", default="output/cat-25m")
    ap.add_argument("--clip", default="C0008")
    ap.add_argument("--retime-hrd", action=argparse.BooleanOptionalAction, default=True)
    ap.add_argument("--acquisition", choices=("unspecified", "rec709"), default="unspecified")
    ap.add_argument("--structure-template", help="Track/ftyp/mvhd template; PROF remains --camera")
    ap.add_argument("--umid-mode", choices=("sony", "edius_uuid4"), default="sony")
    ap.add_argument("--payload-layout", choices=("camera_aligned", "structure_template"),
                    default="camera_aligned")
    ap.add_argument("--nal-length-size", type=int, choices=(3, 4), default=4)
    ap.add_argument("--diagnostic-framing-control", action="store_true")
    ap.add_argument("--profile", choices=PROFILES, default=DEFAULT_PROFILE)
    args = ap.parse_args()
    selected = get_profile(args.profile)
    if (args.nal_length_size == 3) != args.diagnostic_framing_control:
        ap.error("Three-byte framing requires --diagnostic-framing-control; candidates use four bytes")
    out = Path(args.output)
    out.mkdir(parents=True, exist_ok=True)
    destination = out / (args.clip + ".MP4")
    if destination.exists():
        raise SystemExit("Output exists; use a fresh output directory")
    base, cam, edius = MP4(args.base), MP4(args.camera), MP4(args.edius)
    structure = MP4(args.structure_template) if args.structure_template else cam
    bv, ba = base.tracks[:2]
    cv, ca, cm = structure.tracks
    rt = edius.tracks[2]
    frames = len(bv.sizes)
    validate_pcm_entry(ba)
    validate_pcm_entry(ca)
    if (not frames or not isinstance(ba.sizes, ConstantSizes) or
            ba.sizes.size != 4):
        raise ValueError("Expected video and stereo 16-bit big-endian PCM")
    duration = sum(n * t for n, t in bv.stts)
    if (bv.timescale, bv.stts, ba.timescale) != (
            selected.timescale, [(frames, selected.fps_den)], 48000):
        raise ValueError("Unexpected base timescale or cadence")
    if (rt.timescale, rt.stts) != (selected.timescale, [(len(rt.sizes), selected.fps_den)]):
        raise ValueError("RTMD template cadence disagrees with selected profile")
    new_avcc, length_size, mappings, infos = avcc_normalize(bv.avcc(), selected.fps)
    validate_base_profile(bv, infos, selected)
    video = [normalize_sample(bv.sample(i), length_size, mappings, infos) for i in range(frames)]
    retimer = None
    if args.retime_hrd:
        video, retimer = retime_cbr_samples(video, infos, 1 / selected.fps)
    if args.nal_length_size != 3:
        video = [reframe_sample(sample, 3, args.nal_length_size) for sample in video]
        new_avcc = new_avcc[:4] + bytes([(new_avcc[4] & 0xfc) | (args.nal_length_size - 1)]) + new_avcc[5:]
    # EDIUS has no camera sensor measurements in these packets, only cadence/TC/color labels.
    seed = bytearray(rt.sample(0))
    # Validate the measured template before deliberately choosing zero-start TC.
    make_packet(seed, 0, selected.half_step)
    seed[13:18] = bytes(5)
    seed[20:24] = timecode(0, selected.half_step)
    metadata = [make_packet(seed, i, selected.half_step) for i in range(frames)]
    audio = b"".join(base.buf[p:p + n * ba.sizes[0]] for p, n in zip(ba.chunks, ba.chunk_samples))
    source_audio_samples = len(audio) // 4
    samples_audio = selected.audio_boundary(frames)
    audio = align_pcm(audio, frames, args.profile)
    stamp_dt = datetime.now(timezone(timedelta(hours=8)))
    stamp = stamp_dt.isoformat(timespec="seconds")
    qt_stamp = int(stamp_dt.timestamp()) + 2082844800
    identity_source = edius if args.umid_mode == "edius_uuid4" else cam
    camera_meta = identity_source.one(identity_source.top, "meta")
    camera_xml = identity_source.payload(identity_source.child(camera_meta, "xml ", 4))[4:].rstrip(b" \0")
    camera_nrt = ET.fromstring(camera_xml)
    source_umid = next(x.get("umidRef") for x in camera_nrt if x.tag.endswith("TargetMaterial"))
    node = bytes.fromhex(source_umid)[24:]
    umid = (ediustype_umid(source_umid) if args.umid_mode == "edius_uuid4" else
            make_umid(datetime.fromisoformat(stamp), node).hex().upper())
    xml = nrt_xml(umid, frames, stamp, args.acquisition, args.profile)
    (out / (args.clip + "M01.XML")).write_bytes(xml)
    ftyp = structure.raw(structure.one(structure.top, "ftyp"))
    payload_start = (structure.one(structure.top, "mdat").data
                     if args.payload_layout == "structure_template" else 131072)
    prefix = payload_prefix(ftyp, profile_descriptor(cam, selected), payload_start)
    payload = bytearray()
    offsets = [[], [], []]
    counts = [[], [], []]
    for first in range(0, frames, selected.gop_frames):
        last = min(first + selected.gop_frames, frames)
        for track, packets in [(2, metadata[first:last]), (0, video[first:last])]:
            offsets[track].append(payload_start + len(payload))
            counts[track].append(len(packets))
            payload.extend(b"".join(packets))
        a0 = selected.audio_boundary(first)
        a1 = min(selected.audio_boundary(last), samples_audio)
        offsets[1].append(payload_start + len(payload))
        counts[1].append(a1 - a0)
        payload.extend(audio[a0*4:a1*4])
    visual = bytearray(structure.payload(cv.entry)[:78])
    struct.pack_into(">HH", visual, 24, selected.width, selected.height)
    avc_entry = box("avc1", visual + box("avcC", new_avcc))
    video_edts = base.child(bv.box, "edts")
    elst = base.payload(base.child(video_edts, "elst"))
    if u32(elst, 4) != 1 or elst[0] != 0:
        raise ValueError("Unsupported base edit list")
    media_time = struct.unpack_from(">i", elst, 12)[0]
    mvhd = structure.child(structure.moov, "mvhd")
    moov = patched_header(structure, mvhd, duration, selected.timescale, stamp=qt_stamp)
    moov += make_track(cv, avc_entry, [len(x) for x in video], offsets[0], counts[0], bv.stts,
                       base.raw(bv.tables["ctts"]) if "ctts" in bv.tables else b"",
                       bv.sync, duration, duration, selected.timescale, media_time, qt_stamp,
                       (selected.width, selected.height))
    moov += make_track(ca, structure.raw(ca.entry), ConstantSizes(4, samples_audio), offsets[1], counts[1],
                       [(samples_audio, 1)], b"", [], duration, samples_audio, 48000, 0, qt_stamp)
    moov += make_track(cm, structure.raw(cm.entry), [len(x) for x in metadata], offsets[2], counts[2],
                       [(frames, selected.fps_den)], b"", [], duration, duration,
                       selected.timescale, 0, qt_stamp)
    nrt_template = edius.one(edius.top, "meta")
    handler = edius.raw(edius.child(nrt_template, "hdlr", 4))
    nrt = fullbox("meta", handler + fullbox("xml ", xml))
    if len(prefix) + 16 + len(payload) + 8 + len(moov) + len(nrt) >= 1 << 32:
        raise ValueError("This SD single-clip builder requires splitting inputs before 4 GiB")
    with destination.open("xb") as f:
        f.write(prefix)
        f.write(struct.pack(">I4sQ", 1, b"mdat", 16 + len(payload)))
        f.write(payload)
        f.write(box("moov", moov))
        f.write(nrt)
    manifest = {"clip": args.clip, "umid": umid, "frames": frames, "duration_ticks": duration,
                "package_kind": "framing_control" if args.diagnostic_framing_control else "encoded_avc",
                "test_role": "diagnostic_framing_control" if args.diagnostic_framing_control else "camera_candidate",
                "acquisition": args.acquisition,
                "sony_profile": selected.name, "profile_parameters": selected.manifest_fields(),
                "timescale": selected.timescale, "audio_samples": samples_audio, "stamp": stamp,
                "source_audio_samples": source_audio_samples,
                "audio_alignment": {"trimmed_samples": max(0, source_audio_samples - samples_audio),
                                    "silent_samples_added": max(0, samples_audio - source_audio_samples)},
                "rtmd_mode": "generated from minimal EDIUS packet structure",
                "rtmd_timecode_origin": "zero; template start deliberately reset",
                "rtmd_template_start_timecode": rt.sample(0)[20:24].hex().upper(),
                "avc_normalization": infos, "base": str(Path(args.base).resolve()),
                "hrd_retiming": {"enabled": retimer is not None,
                                 "conformance_point": "NAL unit stream, length prefixes excluded",
                                 "initial_selection": retimer.initial_selection if retimer else [],
                                 "buffering_periods": retimer.periods if retimer else []},
                "camera_template": args.camera, "rtmd_template": args.edius,
                "structure_template": str(structure.path.resolve()),
                "structure_template_sha256": hashlib.sha256(structure.buf).hexdigest(),
                "umid_mode": args.umid_mode, "payload_layout": args.payload_layout,
                "umid_label_source": str(identity_source.path.resolve()),
                "nal_length_size": args.nal_length_size,
                "first_mdat_payload_offset": payload_start,
                "profile_descriptor_source": str(cam.path.resolve()),
                "video_bitrate": sum(map(len, video)) * 8 * selected.timescale / duration,
                "sha256": hashlib.sha256(destination.read_bytes()).hexdigest()}
    (out / "build-manifest.json").write_text(json.dumps(manifest, indent=2), encoding="utf-8")
    if structure is not cam:
        structure.close()
    for m in (base, cam, edius):
        m.close()
    verify = MP4(destination)
    print(json.dumps(manifest, indent=2))
    verify.close()


if __name__ == "__main__":
    main()
