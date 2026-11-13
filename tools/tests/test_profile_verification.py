"""Purpose: regress cross-layer checks for the explicit Sony experiment profiles.

Usage: python -m unittest discover -s tools/tests
    -p test_profile_verification.py -v.
Design: mutate profile, SPS, PROF, XML, RTMD, sample-table and header fixtures
    to ensure inconsistent dimensions, rates, colors and timing are rejected.
Scope: local verifier contracts, not a comprehensive Sony specification test.
"""
import copy
import struct
import sys
import tempfile
import unittest
from pathlib import Path
from types import SimpleNamespace
from xml.etree import ElementTree as ET

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from build_sony_clip import NRT, table
from sony_mp4 import MP4, box, fullbox
from sony_profiles import PROFILES, get_profile, manifest_profile
from sony_rtmd import make_packet, timecode
from stage_sd_catalog import material_attributes
from verify_sony_package import (
    material_profile_matches, probe_profile_matches, prof_profile_matches,
    rtmd_profile_matches, selected_profile_checks, sps_profile_matches, xml_profile_matches,
)


def prof_fixture(profile):
    fields = bytearray(44)
    fields[7] = 1
    fields[8:16] = b"avc1\x01\x64\x00" + bytes([profile.level_idc])
    struct.pack_into(">4IHH", fields, 20, profile.bitrate_kbps, profile.bitrate_kbps,
                     profile.prof_fps, profile.prof_fps, profile.width, profile.height)
    return fields


def probe_fixture(profile):
    return {"streams": [{
        "codec_type": "video", "codec_name": "h264", "profile": "High",
        "codec_tag_string": "avc1", "width": profile.width, "height": profile.height,
        "pix_fmt": "yuv420p", "level": profile.level_idc, "field_order": "progressive",
        "r_frame_rate": profile.fps_text, "avg_frame_rate": profile.fps_text,
    }]}


def sps_fixture(profile):
    fields = {
        "profile_idc": 100, "level_idc": profile.level_idc, "chroma_format_idc": 1,
        "bit_depth_luma_minus8": 0, "bit_depth_chroma_minus8": 0,
        "frame_mbs_only_flag": 1, "fixed_frame_rate_flag": 1,
        "num_units_in_tick": profile.vui_tick, "time_scale": 240000,
        "pic_width_in_mbs_minus1": profile.width // 16 - 1,
        "pic_height_in_map_units_minus1": (profile.height + 15) // 16 - 1,
        "frame_crop_bottom_offset": (-profile.height % 16) // 2,
    }
    hrd = {
        "cpb_cnt_minus1": 0, "cbr_flag[0]": 1, "bit_rate_scale": 0, "cpb_size_scale": 0,
        "bit_rate_value_minus1[0]": profile.bitrate_kbps * 1000 // 64 - 1,
        "cpb_size_value_minus1[0]": profile.bitrate_kbps * 1000 // 16 - 1,
    }
    return {"fields": fields, "hrd": {"nal": dict(hrd), "vcl": dict(hrd)}}


def xml_fixture(profile, frames):
    def element(parent, name, **attrs):
        return ET.SubElement(parent, f"{{{NRT}}}{name}", attrs)
    root = ET.Element(f"{{{NRT}}}NonRealTimeMeta")
    element(root, "Duration", value=str(frames))
    video = element(root, "VideoFormat")
    element(video, "VideoFrame", videoCodec=profile.video_codec,
            captureFps=profile.xml_fps, formatFps=profile.xml_fps)
    element(video, "VideoLayout", pixel=str(profile.width),
            numOfVerticalLine=str(profile.height), aspectRatio="16:9")
    ltc = element(root, "LtcChangeTable", tcFps="30", halfStep=str(profile.half_step).lower())
    for frame, status in ((0, "increment"), (frames - 1, "end")):
        element(ltc, "LtcChange", frameCount=str(frame), status=status,
                value=timecode(frame, profile.half_step).hex().upper())
    return root


def rtmd_fixture(profile):
    seed = bytearray(1024)
    seed[:2] = bytes.fromhex("001c")
    seed[18:20] = struct.pack(">H", 60 if profile.half_step else 30)
    seed[20:24] = timecode(0, profile.half_step)
    seed[32:40] = b"colorKLV"
    if not profile.half_step:
        # The measured UHD seed is nonzero; the generated clip deliberately is not.
        seed = bytearray(make_packet(seed, 2231, half_step=False))
    return bytes(seed)


def generated_packets(profile, frames, template):
    seed = bytearray(template)
    seed[13:18] = bytes(5)
    seed[20:24] = timecode(0, profile.half_step)
    return [make_packet(seed, i, profile.half_step) for i in range(frames)]


def media_fixture(profile, info, packets):
    frames, ticks, samples = info["frames"], info["duration_ticks"], info["audio_samples"]
    prof = box("uuid", bytes(24) + box("VPRF", prof_fixture(profile)))
    start = len(prof) + 8
    video_data, audio_data, metadata = b"AVC" * frames, bytes(4 * samples), b"".join(packets)
    avcc = bytes([1, 100, 0, profile.level_idc, 255, 225, 0, 1, 103, 0])
    visual = bytearray(78)
    struct.pack_into(">HH", visual, 24, profile.width, profile.height)
    pcm = bytearray(28)
    struct.pack_into(">HH", pcm, 16, 2, 16)
    struct.pack_into(">I", pcm, 24, 48000 << 16)

    def track(handler, codec, entry, count, size, offset, scale, delta, dimensions=(0, 0)):
        tkhd = bytearray(84)
        struct.pack_into(">I", tkhd, 20, ticks)
        struct.pack_into(">II", tkhd, 76, dimensions[0] << 16, dimensions[1] << 16)
        mdhd = fullbox("mdhd", struct.pack(">IIII", 0, 0, scale, count * delta) + bytes(4))
        hdlr = fullbox("hdlr", bytes(4) + handler.encode() + bytes(12))
        stbl = (fullbox("stsd", struct.pack(">I", 1) + box(codec, entry)) +
                fullbox("stsz", struct.pack(">II", size, count)) +
                table("stts", [(count, delta)]) + table("stsc", [(1, count, 1)]) +
                table("stco", [(offset,)]))
        edts = box("edts", fullbox("elst", struct.pack(">IIiI", 1, ticks, 0, 65536)))
        return box("trak", box("tkhd", tkhd) + edts +
                   box("mdia", mdhd + hdlr + box("minf", box("stbl", stbl))))

    tracks = (
        track("vide", "avc1", visual + box("avcC", avcc), frames, 3, start,
              profile.timescale, profile.fps_den, (profile.width, profile.height)) +
        track("soun", "twos", pcm, samples, 4, start + len(video_data), 48000, 1) +
        track("meta", "rtmd", bytes(8), frames, 1024, start + len(video_data) + len(audio_data),
              profile.timescale, profile.fps_den))
    mvhd = fullbox("mvhd", struct.pack(">IIII", 0, 0, profile.timescale, ticks))
    return prof + box("mdat", video_data + audio_data + metadata) + box("moov", mvhd + tracks)


class ProfileVerificationTests(unittest.TestCase):
    def test_legacy_profile_and_explicit_parameter_contradictions(self):
        self.assertEqual(manifest_profile({}).name, "hd25_5994")
        for profile in PROFILES.values():
            info = {"sony_profile": profile.name, "profile_parameters": profile.manifest_fields()}
            self.assertEqual(manifest_profile(info), profile)
            info["profile_parameters"]["width"] += 1
            with self.assertRaisesRegex(ValueError, "disagree"):
                manifest_profile(info)
        with self.assertRaises(ValueError):
            manifest_profile({"sony_profile": "invented"})

    def test_prof_observed_fps_constants_and_all_profile_fields(self):
        for profile in PROFILES.values():
            fields = prof_fixture(profile)
            self.assertTrue(prof_profile_matches(fields, profile))
            self.assertEqual(profile.prof_fps, 0x003bf0a6 if profile.half_step else 0x001df853)
            for offset in (7, 8, 13, 15, 20, 24, 28, 32, 36, 38):
                with self.subTest(profile=profile.name, offset=offset):
                    changed = bytearray(fields)
                    changed[offset] ^= 1
                    self.assertFalse(prof_profile_matches(changed, profile))
            self.assertFalse(prof_profile_matches(fields[:-1], profile))

    def test_probe_rejects_wrong_dimensions_fps_level_and_pixel_format(self):
        profile = get_profile("uhd60_2997")
        for key, wrong in (
            ("width", 1920), ("height", 1080), ("r_frame_rate", "60000/1001"),
            ("avg_frame_rate", "30/1"), ("level", 42), ("pix_fmt", "yuv422p"),
            ("codec_name", "hevc"), ("profile", "Main"), ("codec_tag_string", "avc3"),
            ("field_order", "tt"), ("avg_frame_rate", "0/0"),
        ):
            probe = probe_fixture(profile)
            self.assertTrue(probe_profile_matches(probe, profile))
            probe["streams"][0][key] = wrong
            with self.subTest(key=key, wrong=wrong):
                self.assertFalse(probe_profile_matches(probe, profile))
        self.assertFalse(probe_profile_matches({"streams": []}, profile))

    def test_sps_all_profiles_and_contradictory_fields(self):
        for profile in PROFILES.values():
            sps = sps_fixture(profile)
            self.assertTrue(sps_profile_matches(sps, profile))
            for key, value in (
                ("profile_idc", 77), ("level_idc", profile.level_idc ^ 1), ("chroma_format_idc", 2),
                ("bit_depth_luma_minus8", 2), ("bit_depth_chroma_minus8", 2),
                ("frame_mbs_only_flag", 0), ("fixed_frame_rate_flag", 0),
                ("num_units_in_tick", 1001), ("time_scale", 120000),
                ("pic_width_in_mbs_minus1", 79), ("frame_crop_bottom_offset", 1),
            ):
                changed = copy.deepcopy(sps)
                changed["fields"][key] = value
                with self.subTest(profile=profile.name, key=key):
                    self.assertFalse(sps_profile_matches(changed, profile))
            for group in ("nal", "vcl"):
                for key in ("bit_rate_value_minus1[0]", "cpb_size_value_minus1[0]", "cbr_flag[0]"):
                    changed = copy.deepcopy(sps)
                    changed["hrd"][group][key] += 1
                    self.assertFalse(sps_profile_matches(changed, profile))
            self.assertFalse(sps_profile_matches({}, profile))

    def test_xml_dimensions_fps_codec_half_step_and_zero_origin(self):
        for profile in PROFILES.values():
            root = xml_fixture(profile, 1801)
            self.assertTrue(xml_profile_matches(root, profile, 1801))
            mutations = (
                ("VideoFrame", "videoCodec", profile.video_codec + "_invalid"),
                ("VideoFrame", "captureFps", "24p"),
                ("VideoFrame", "formatFps", "30p"),
                ("VideoLayout", "pixel", "1280"), ("VideoLayout", "numOfVerticalLine", "720"),
                ("LtcChangeTable", "halfStep", str(not profile.half_step).lower()),
                ("LtcChangeTable", "tcFps", "60"), ("LtcChange", "value", "41000000"),
                ("Duration", "value", "1800"),
            )
            for tag, attr, value in mutations:
                changed = copy.deepcopy(root)
                changed.find(f".//{{{NRT}}}{tag}").set(attr, value)
                with self.subTest(profile=profile.name, tag=tag, attr=attr):
                    self.assertFalse(xml_profile_matches(changed, profile, 1801))
            changed = copy.deepcopy(root)
            changed.append(copy.deepcopy(changed.find(f".//{{{NRT}}}VideoFrame")))
            self.assertFalse(xml_profile_matches(changed, profile, 1801))

    def test_mediapro_requires_both_profile_attributes(self):
        profile = get_profile("uhd60_2997")
        material = ET.Element("Material", videoType=profile.video_codec, fps=profile.xml_fps)
        self.assertTrue(material_profile_matches(material, profile))
        material.set("fps", "59.94p")
        self.assertFalse(material_profile_matches(material, profile))
        material.set("fps", profile.xml_fps)
        material.set("videoType", get_profile().video_codec)
        self.assertFalse(material_profile_matches(material, profile))

    def test_every_rtmd_packet_including_nonzero_source_origin_and_opaque_bytes(self):
        for profile in PROFILES.values():
            seed = rtmd_fixture(profile)
            packets = generated_packets(profile, 7, seed)
            track = SimpleNamespace(sizes=[1024] * 7, sample=packets.__getitem__)
            self.assertTrue(rtmd_profile_matches(track, profile, 7, seed))
            self.assertEqual(packets[0][20:24], timecode(0, profile.half_step))
            if not profile.half_step:
                self.assertNotEqual(seed[20:24], packets[0][20:24])
            for offset in (13, 16, 19, 20, 32, 511, 1023):
                changed = bytearray(packets[5])
                changed[offset] ^= 1
                packets[5], saved = bytes(changed), packets[5]
                with self.subTest(profile=profile.name, offset=offset):
                    self.assertFalse(rtmd_profile_matches(track, profile, 7, seed))
                packets[5] = saved
            self.assertFalse(rtmd_profile_matches(track, profile, 8, seed))
            self.assertFalse(rtmd_profile_matches(track, profile, 7, bytes(1024)))

    def test_aggregate_checks_real_sample_tables_and_header_contradictions(self):
        with tempfile.TemporaryDirectory() as temp:
            path = Path(temp) / "fixture.MP4"
            base_path = Path(temp) / "base.MP4"
            for profile in PROFILES.values():
                frames = 5
                seed = rtmd_fixture(profile)
                info = {
                    "sony_profile": profile.name, "profile_parameters": profile.manifest_fields(),
                    "clip": "C6516", "umid": "00" * 32, "frames": frames,
                    "timescale": profile.timescale, "duration_ticks": frames * profile.fps_den,
                    "audio_samples": profile.audio_boundary(frames), "package_kind": "encoded_avc",
                    "rtmd_timecode_origin": "zero; template start deliberately reset",
                    "rtmd_template_start_timecode": seed[20:24].hex().upper(),
                }
                packets = generated_packets(profile, frames, seed)
                original = media_fixture(profile, info, packets)
                path.write_bytes(original)
                base_path.write_bytes(original)
                probe, root = probe_fixture(profile), xml_fixture(profile, frames)
                material = ET.Element("Material", material_attributes(info))
                timing = {"sps": sps_fixture(profile)}

                def verify(manifest=info):
                    media, base = MP4(path), MP4(base_path)
                    try:
                        return selected_profile_checks(manifest, media, probe, root, material, timing, seed, base)
                    finally:
                        media.close()
                        base.close()

                checks = verify()
                self.assertTrue(all(checks.values()), checks)
                media = MP4(path)
                mutations = [
                    (media.tracks[0].entry.data + 24, "profile_sample_entry_dimensions"),
                    (media.child(media.tracks[0].box, "tkhd").end - 8, "profile_track_dimensions"),
                    (media.child(media.tracks[1].box, "tkhd").data + 20, "profile_movie_duration"),
                    (media.child(media.moov, "mvhd").data + 12, "profile_movie_duration"),
                    (media.child(media.tracks[0].entry, "avcC", 78).data + 3, "profile_avcc"),
                    (media.tracks[1].entry.data + 18, "profile_pcm_format_and_count"),
                    (media.child(media.child(media.tracks[2].box, "edts"), "elst").data + 8,
                     "profile_edit_durations"),
                    (media.child(media.child(media.tracks[0].box, "edts"), "elst").data + 15,
                     "profile_video_edit_origin"),
                    (media.child(media.child(media.tracks[1].box, "edts"), "elst").data + 15,
                     "profile_audio_metadata_edit_origins"),
                    (media.child(media.child(media.tracks[2].box, "edts"), "elst").data + 15,
                     "profile_audio_metadata_edit_origins"),
                ]
                media.close()
                for position, failed in mutations:
                    changed = bytearray(original)
                    changed[position] ^= 1
                    path.write_bytes(changed)
                    with self.subTest(profile=profile.name, failed=failed):
                        checks = verify()
                        self.assertFalse(checks[failed])
                        self.assertFalse(checks["selected_profile_consistent"])
                path.write_bytes(original)
                for key in ("frames", "timescale", "duration_ticks", "audio_samples"):
                    changed_info = dict(info)
                    changed_info[key] += 1
                    self.assertFalse(verify(changed_info)["selected_profile_consistent"])
                checks = verify(dict(info, rtmd_timecode_origin="retained"))
                self.assertFalse(checks["profile_rtmd_timecode_origin"])


if __name__ == "__main__":
    unittest.main()
