"""Regression tests for isolated, opt-in bitrate diagnostics."""
import copy
import json
import struct
import sys
import unittest
from pathlib import Path
from types import SimpleNamespace

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from bitrate_experiment import ExperimentSpec, load_spec, package_profile, package_spec
from build_sony_clip import profile_descriptor, validate_base_profile
from encode_xavc import make_command
from sony_mp4 import MP4, box
from sony_profiles import PROFILES, get_profile, manifest_profile
from sony_verification import BITRATE_CHECKS, SCHEMA, require_current_verification
from stage_sd_catalog import catalog_profile, material_attributes
from test_sony_profiles import fake_track, synthetic_sps
from avc_sony import normalize_sps
from verify_sony_package import prof_profile_matches, sps_profile_matches
from test_profile_verification import prof_fixture, sps_fixture


def spec(base="hd16_2997", variant="A"):
    return ExperimentSpec.from_dict({
        "schema": 1, "kind": "bitrate_diagnostic", "experiment_id": "test0029",
        "pair_id": "pair-" + base, "variant": variant, "base_profile": base,
        "coded_bitrate_kbps": 4000, "hrd_bitrate_kbps": 4000, "cpb_size_kbits": 4000,
        "prof_average_kbps": get_profile(base).bitrate_kbps if variant == "A" else 4000,
        "prof_maximum_kbps": get_profile(base).bitrate_kbps if variant == "A" else 4000,
        "creation_time": "2026-11-13T17:03:26+08:00"})


def manifest(s):
    return {"package_kind": "bitrate_diagnostic", "test_role": "bitrate_diagnostic",
            "experiment_spec": s.to_dict(), "stamp": s.creation_time,
            "sony_profile": s.base_profile, "profile_parameters": s.coding_profile().manifest_fields(),
            "nal_length_size": 4, "umid_mode": "edius_uuid4", "acquisition": "rec709",
            "payload_layout": "structure_template", "hrd_retiming": {"enabled": True},
            "clip": "C9999", "frames": 30, "umid": "fixture"}


class BitrateExperimentTests(unittest.TestCase):
    def test_five_production_profiles_remain_unchanged(self):
        self.assertEqual(len(PROFILES), 5)
        for base in ("hd16_2997", "hd25_5994"):
            old = get_profile(base).manifest_fields()
            s = spec(base)
            self.assertEqual(s.coding_profile().bitrate_kbps, 4000)
            self.assertNotIn(s.coding_profile().name, PROFILES)
            self.assertEqual(get_profile(base).manifest_fields(), old)

    def test_prof_does_not_change_encoder_command_or_inherited_controls(self):
        probe = {"streams": [{"index": 0, "codec_type": "video", "duration": "25.6"}]}
        for base, level in (("hd16_2997", "4.0"), ("hd25_5994", "4.2")):
            a, b = spec(base), spec(base, "B")
            self.assertEqual(a.coding_fields(), b.coding_fields())
            ca, cb = [make_command("in", Path("out"), probe, experiment_spec=s) for s in (a, b)]
            self.assertEqual(ca, cb)
            value = lambda key: ca[ca.index(key) + 1]
            for key in ("-b:v", "-minrate", "-maxrate", "-bufsize"):
                self.assertEqual(value(key), "4000k")
            self.assertEqual(value("-level:v"), level)
            for text in ("keyint=30", "bframes=2", "ref=2", "slices=4", "b-pyramid=none",
                         "nal-hrd=cbr", "filler=1"):
                self.assertIn(text, value("-x264-params"))

    def test_strict_schema_rejects_unknown_missing_or_noninteger_parameters(self):
        original = spec().to_dict()
        variants = [{**original, "waive_any_reader_error": True},
                    {k: v for k, v in original.items() if k != "hrd_bitrate_kbps"}]
        for key, value in (("coded_bitrate_kbps", True), ("schema", True),
                           ("hrd_bitrate_kbps", "4000"), ("cpb_size_kbits", 3999),
                           ("coded_bitrate_kbps", 8000), ("hrd_bitrate_kbps", 0),
                           ("variant", "C"), ("base_profile", "hd50_2997"),
                           ("creation_time", "2026-11-13T17:03:26"),
                           ("creation_time", "2026-11-13T17:03:26.123+08:00"),
                           ("prof_average_kbps", 4000), ("prof_maximum_kbps", 4000)):
            variants.append({**original, key: value})
        for raw in variants:
            with self.subTest(raw=raw), self.assertRaises(ValueError):
                ExperimentSpec.from_dict(raw)

    def test_diagnostic_resolver_requires_all_fixed_manifest_controls(self):
        m = manifest(spec())
        self.assertEqual(package_profile(m).bitrate_kbps, 4000)
        self.assertEqual(material_attributes(m)["videoType"], "AVC_1920_1080_HP@L4")
        self.assertEqual(material_attributes(m)["fps"], "29.97p")
        for key, value in (("sony_profile", "hd25_5994"), ("nal_length_size", 3),
                           ("umid_mode", "sony"), ("payload_layout", "camera_aligned"),
                           ("acquisition", "unspecified"), ("test_role", "camera_candidate"),
                           ("hrd_retiming", {"enabled": False}), ("stamp", "wrong"),
                           ("profile_parameters", get_profile("hd16_2997").manifest_fields())):
            with self.subTest(key=key), self.assertRaises(ValueError):
                package_profile({**m, key: value})
        with self.assertRaises(ValueError):
            catalog_profile(m, "native_reuse")

    def test_ordinary_resolver_cannot_relabel_diagnostics(self):
        m = manifest(spec())
        with self.assertRaises(ValueError):
            manifest_profile(m)
        for kind in ("encoded_avc", "source_control", "native_control", "framing_control"):
            m["package_kind"] = kind
            m["profile_parameters"] = get_profile("hd16_2997").manifest_fields()
            with self.subTest(kind=kind), self.assertRaises(ValueError):
                package_profile(m)
            with self.assertRaises(ValueError):
                manifest_profile(m)

    def test_dual_hrd_targets_coded_rate_not_prof(self):
        for base in ("hd16_2997", "hd25_5994"):
            s = spec(base)
            p = s.coding_profile()
            _, info = normalize_sps(synthetic_sps(p), p.fps)
            validate_base_profile(fake_track(p), {0: info}, p)
            self.assertTrue(sps_profile_matches(sps_fixture(p), p))
            self.assertFalse(sps_profile_matches(sps_fixture(get_profile(base)), p))

    def test_prof_only_two_fields_change_at_exact_offsets(self):
        import tempfile
        with tempfile.TemporaryDirectory() as temp:
            path = Path(temp) / "template.MP4"
            for base in ("hd16_2997", "hd25_5994"):
                baseline = get_profile(base)
                fields = prof_fixture(baseline)
                fields[16:20] = bytes.fromhex("00030002")
                raw = box("uuid", bytes.fromhex("50524f4621d24fcebb88695cfac9c740") +
                          bytes(8) + box("VPRF", fields))
                path.write_bytes(raw + box("moov", b""))
                camera = MP4(path)
                try:
                    a, b = spec(base), spec(base, "B")
                    first = profile_descriptor(camera, a.coding_profile(), a.prof_average_kbps,
                                               a.prof_maximum_kbps)
                    second = profile_descriptor(camera, b.coding_profile(), b.prof_average_kbps,
                                                b.prof_maximum_kbps)
                finally:
                    camera.close()
                start = 8 + 24 + 8
                self.assertEqual(first[:start+20], second[:start+20])
                self.assertEqual(first[start+28:], second[start+28:])
                self.assertEqual(struct.unpack_from(">II", second, start+20), (4000, 4000))
                self.assertTrue(prof_profile_matches(first[start:], a.coding_profile(),
                                                    a.prof_average_kbps, a.prof_maximum_kbps))
                self.assertFalse(prof_profile_matches(first[start:], a.coding_profile()))

    def test_diagnostic_deployment_requires_explicit_opt_in_and_all_checks(self):
        required = BITRATE_CHECKS - {"sd_acquisition_matches_xml"} | {
            "sd_metadata_omission_matches_positive_template", "sd_minimal_catalog_rebuilt_exactly",
            "sd_positive_template_observation_bound", "rec709_stream_and_acquisition_agree"}
        report = {"verification_schema": SCHEMA, "verification_profile": "bitrate_diagnostic",
                  "acquisition": "rec709", "catalog_representation": "observed_minimal",
                  "passed": True, "checks": dict.fromkeys(required, True)}
        call = lambda allow=False: require_current_verification(
            report, "bitrate_diagnostic", "rec709", "observed_minimal", allow_diagnostic=allow)
        with self.assertRaises(ValueError):
            call()
        call(True)
        for name in required:
            report["checks"][name] = False
            with self.subTest(name=name), self.assertRaises(ValueError):
                call(True)
            report["checks"][name] = True
        with self.assertRaises(ValueError):
            require_current_verification(report, allow_diagnostic=True)

    def test_expected_rejection_is_not_a_configurable_waiver(self):
        for base in ("hd16_2997", "hd25_5994"):
            for variant in ("A", "B"):
                self.assertEqual(spec(base, variant).expected_reader_status,
                                 3 if (base, variant) == ("hd16_2997", "B") else 0)

    def test_spec_loader_rejects_duplicate_parameters(self):
        import tempfile
        with tempfile.TemporaryDirectory() as temp:
            path = Path(temp) / "spec.json"
            raw = json.dumps(spec().to_dict())
            path.write_text(raw, encoding="utf-8")
            self.assertEqual(load_spec(path), spec())
            path.write_text('{"schema": 7, ' + raw[1:], encoding="utf-8")
            with self.assertRaisesRegex(ValueError, "Duplicate"):
                load_spec(path)


if __name__ == "__main__":
    unittest.main()
