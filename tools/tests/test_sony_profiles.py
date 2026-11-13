"""Purpose: regress explicit profile definitions and encoder/builder parameters.

Usage: python -m unittest discover -s tools/tests -p test_sony_profiles.py -v.
Design: test coupled bitrate/dimensions/cadence, exact PCM boundaries, SPS/HRD,
    PROF constants and refusal of conflicting SPS or audio sample descriptions.
Scope: three modeled profiles and local fixtures; not arbitrary Sony formats.
"""
import struct
import sys
import unittest
from fractions import Fraction
from pathlib import Path
from types import SimpleNamespace

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from avc_sony import avcc_normalize, escape, normalize_sps, packbits
from build_sony_clip import align_pcm, validate_base_profile, validate_pcm_entry
from encode_xavc import make_command
from sony_profiles import DEFAULT_PROFILE, PROFILES, get_profile, manifest_profile


def ue(value):
    bits = f"{value + 1:b}"
    return "0" * (len(bits) - 1) + bits


def synthetic_sps(profile):
    width, height = profile.width, profile.height
    bits = f"{100:08b}{0:08b}{profile.level_idc:08b}" + ue(0)
    bits += ue(1) + ue(0) + ue(0) + "00"
    bits += ue(0) + ue(0) + ue(0) + ue(2) + "0"
    bits += ue(width // 16 - 1) + ue((height + 15) // 16 - 1) + "11"
    crop = ((height + 15) // 16 * 16 - height) // 2
    bits += ("1" + ue(0) * 3 + ue(crop)) if crop else "0"
    bits += "1" + "00" + "1" + "10101" + f"{1:08b}" * 3 + "0"
    bits += "1" + f"{profile.fps_den:032b}{2 * profile.fps_num:032b}" + "1"
    bits += "1" + ue(0) + "00000000"
    bits += ue(profile.bitrate_kbps * 1000 // 64 - 1)
    bits += ue(profile.bitrate_kbps * 1000 // 16 - 1) + "1"
    bits += f"{23:05b}{6:05b}{4:05b}{0:05b}" + "0000" + "1"
    return b"\x67" + escape(packbits(bits))


def fake_track(profile, avcc=None):
    entry = bytearray(78)
    struct.pack_into(">HH", entry, 24, profile.width, profile.height)
    config = avcc or bytes([1, 100, 0, profile.level_idc])
    return SimpleNamespace(codec="avc1", m=SimpleNamespace(payload=lambda _: entry),
                           entry=None, avcc=lambda: config)


class ProfileTests(unittest.TestCase):
    def test_explicit_profiles_and_legacy_default(self):
        self.assertEqual(manifest_profile({}).name, DEFAULT_PROFILE)
        for name in PROFILES:
            selected = get_profile(name)
            self.assertIs(manifest_profile({"sony_profile": name,
                                           "profile_parameters": selected.manifest_fields()}), selected)
        with self.assertRaises(ValueError):
            get_profile("uhd_5994")
        with self.assertRaises(ValueError):
            manifest_profile({"sony_profile": "hd50_5994",
                              "profile_parameters": get_profile().manifest_fields()})

    def test_prof_fps_matches_observed_not_exact_rational_floor(self):
        self.assertEqual(get_profile().prof_fps, 0x3bf0a6)
        self.assertNotEqual(get_profile().prof_fps, int(get_profile().fps * 65536))
        self.assertEqual(get_profile("uhd60_2997").prof_fps, 0x1df853)

    def test_hd2997_profiles_bind_level_rate_and_cadence_independently(self):
        for name, rate, level, gop in (("hd50_2997", 50000, 41, 15),
                                       ("hd16_2997", 16000, 40, 30)):
            profile = get_profile(name)
            self.assertEqual((profile.width, profile.height, profile.fps_text),
                             (1920, 1080, "30000/1001"))
            self.assertEqual((profile.bitrate_kbps, profile.level_idc, profile.gop_frames),
                             (rate, level, gop))
            self.assertFalse(profile.half_step)
            self.assertEqual((profile.vui_tick, profile.prof_fps), (4004, 0x1df853))
            self.assertEqual(profile.audio_boundary(30), 48048)

    def test_encoder_parameters_move_together(self):
        probe = {"streams": [{"index": 0, "codec_type": "video", "duration": "2.5"}]}
        for name, profile in PROFILES.items():
            with self.subTest(profile=name):
                command = make_command("input.mov", Path("out"), probe, profile=name)
                value = lambda key: command[command.index(key) + 1]
                self.assertEqual(value("-level:v"), profile.level)
                for key in ("-b:v", "-minrate", "-maxrate", "-bufsize"):
                    self.assertEqual(value(key), f"{profile.bitrate_kbps}k")
                self.assertIn(f"fps={profile.fps_text}", value("-vf"))
                self.assertIn(f"pad={profile.width}:{profile.height}", value("-vf"))
                self.assertIn(f"keyint={profile.gop_frames}:", value("-x264-params"))
                self.assertEqual(value("-video_track_timescale"), str(profile.timescale))
                self.assertEqual(value("-movie_timescale"), str(profile.timescale))

    def test_pcm_boundaries_are_exact_including_partial_chunks(self):
        for profile in PROFILES.values():
            for count in (1, 2, 3, 15, 29, 30, 31, 1534):
                exact = Fraction(count * 48000, 1) / profile.fps
                self.assertEqual(profile.audio_boundary(count), exact.numerator // exact.denominator)
                audio = align_pcm(b"", count, profile.name)
                self.assertEqual(len(audio), profile.audio_boundary(count) * 4)
        self.assertEqual(get_profile("uhd60_2997").audio_boundary(15), 24024)
        self.assertEqual(get_profile("hd50_5994").audio_boundary(30), 24024)

    def test_sps_dimensions_timing_and_hrd_for_every_profile(self):
        for profile in PROFILES.values():
            with self.subTest(profile=profile.name):
                sps = synthetic_sps(profile)
                normalized, info = normalize_sps(sps, profile.fps)
                self.assertEqual((info["width"], info["height"], info["level_idc"]),
                                 (profile.width, profile.height, profile.level_idc))
                self.assertEqual(info["normalized_tick"], profile.vui_tick)
                self.assertEqual(info["normalized_scale"], 240000)
                validate_base_profile(fake_track(profile), {0: info}, profile)
                with self.assertRaisesRegex(ValueError, "already present"):
                    normalize_sps(normalized, profile.fps)
                other = Fraction(30000, 1001) if profile.half_step else Fraction(60000, 1001)
                with self.assertRaisesRegex(ValueError, "timing"):
                    normalize_sps(sps, other)

    def test_base_profile_rejects_mislabelled_dimensions_level_and_bitrate(self):
        profile = get_profile("hd50_5994")
        _, info = normalize_sps(synthetic_sps(profile), profile.fps)
        for key, value in (("width", 3840), ("height", 2160), ("level_idc", 51)):
            wrong = {**info, key: value}
            with self.subTest(field=key), self.assertRaises(ValueError):
                validate_base_profile(fake_track(profile), {0: wrong}, profile)
        with self.assertRaisesRegex(ValueError, "description"):
            validate_base_profile(fake_track(get_profile("uhd60_2997")), {0: info}, profile)
        wrong = {**info, "hrd": {**info["hrd"], "rates": [25000000]}}
        with self.assertRaisesRegex(ValueError, "rate"):
            validate_base_profile(fake_track(profile), {0: wrong}, profile)

    def test_avcc_normalization_preserves_pps_and_extensions(self):
        for profile in PROFILES.values():
            sps = synthetic_sps(profile)
            tail = b"\x01\x00\x02\x68\x80\xfd\xf8\xf8\x00"
            data = bytes([1, 100, 0, profile.level_idc, 255, 225])
            data += struct.pack(">H", len(sps)) + sps + tail
            result, length, _, infos = avcc_normalize(data, profile.fps)
            self.assertEqual(length, 4)
            self.assertTrue(result.endswith(tail))
            validate_base_profile(fake_track(profile), infos, profile)

    def test_duplicate_sps_ids_cannot_hide_a_conflicting_rate(self):
        selected = get_profile("hd50_5994")
        for first in (get_profile("hd25_5994"), selected):
            units = [synthetic_sps(first), synthetic_sps(selected)]
            avcc = bytes([1, 100, 0, selected.level_idc, 255, 226])
            avcc += b"".join(struct.pack(">H", len(nal)) + nal for nal in units)
            avcc += b"\x01\x00\x02\x68\x80"
            with self.subTest(first=first.name), self.assertRaisesRegex(ValueError, "Duplicate SPS"):
                avcc_normalize(avcc, selected.fps)

    def test_structure_audio_description_must_match_big_endian_payload(self):
        def track(codec="twos", channels=2, depth=16, rate=48000):
            entry = bytearray(28)
            struct.pack_into(">HH", entry, 16, channels, depth)
            struct.pack_into(">I", entry, 24, rate << 16)
            return SimpleNamespace(codec=codec, entry=None,
                                   m=SimpleNamespace(payload=lambda _: entry))
        validate_pcm_entry(track())
        for wrong in ({"codec": "sowt"}, {"channels": 1}, {"depth": 24}, {"rate": 44100}):
            with self.subTest(wrong=wrong), self.assertRaisesRegex(ValueError, "PCM"):
                validate_pcm_entry(track(**wrong))


if __name__ == "__main__":
    unittest.main()
