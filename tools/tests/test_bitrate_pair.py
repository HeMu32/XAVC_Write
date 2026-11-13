"""Synthetic, card-free isolation and evidence-binding tests for PROF pairs."""
import copy
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys
import tempfile
import unittest
from uuid import uuid4

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from bitrate_experiment import ExperimentSpec
from build_sony_clip import nrt_xml, table
from compare_bitrate_pair import PROF_UUID, UMID_LABEL, _diff, compare_pair
from sony_mp4 import MP4, box, fullbox


def sha(data):
    return hashlib.sha256(data).hexdigest()


def write_json(path, value):
    path.write_text(json.dumps(value, indent=2), encoding="utf-8")


def make_track(codec, handler, payloads, start, timescale, delta, level):
    count = len(payloads)
    mdhd = fullbox("mdhd", struct.pack(">IIII", 0, 0, timescale, count * delta))
    hdlr = fullbox("hdlr", bytes(4) + handler.encode() + bytes(12))
    if codec == "avc1":
        visual = bytearray(78)
        struct.pack_into(">HH", visual, 24, 1920, 1080)
        entry = box(codec, visual + box("avcC", bytes([1, 100, 0, level, 255])))
    else:
        entry = box(codec, bytes(28))
    stbl = fullbox("stsd", struct.pack(">I", 1) + entry)
    stbl += table("stts", [(count, delta)])
    stbl += table("stsc", [(1, count, 1)])
    stbl += fullbox("stsz", struct.pack(">II", 0, count) +
                    struct.pack(">" + "I" * count, *map(len, payloads)))
    stbl += table("stco", [(start,)])
    return box("trak", box("mdia", mdhd + hdlr + box("minf", box("stbl", stbl))))


def media_bytes(spec, umid, extended=False):
    profile = spec.coding_profile()
    vprf = (bytes.fromhex("000000000000000161766331016400") +
            bytes([profile.level_idc]) + b"\0\3\0\2" +
            struct.pack(">4IHH", spec.prof_average_kbps, spec.prof_maximum_kbps,
                        profile.prof_fps, profile.prof_fps, 1920, 1080) + bytes(4))
    prof = PROF_UUID + bytes(8) + box("FPRF", b"opaque") + box("VPRF", vprf)
    prof = (struct.pack(">I4sQ", 1, b"uuid", 16 + len(prof)) + prof
            if extended else box("uuid", prof))
    prefix = box("ftyp", b"isom" + bytes(12)) + prof + box("free", b"keep-this")
    # More than one second and distinct sizes expose NAL and window accounting.
    video = [b"".join(len(n).to_bytes(4, "big") + n for n in
                      [b"\x65" + bytes(4 + i % 3), b"\x0c" + bytes(i % 5), b"\x06x"])
             for i in range(65)]
    audio, metadata = [b"pcm0", b"pcm1"], [b"rtmd" + bytes(2)]
    samples = [video, audio, metadata]
    offsets, cursor = [], len(prefix) + 8
    for values in samples:
        offsets.append(cursor)
        cursor += sum(map(len, values))
    # Unindexed mdat bytes must also be protected.
    mdat = box("mdat", b"".join(b"".join(values) for values in samples) + b"unindexed")
    tracks = b"".join(make_track(codec, handler, values, offset, scale, delta, profile.level_idc)
                      for codec, handler, values, offset, scale, delta in [
                          ("avc1", "vide", video, offsets[0], profile.timescale, profile.fps_den),
                          ("twos", "soun", audio, offsets[1], 48000, 1),
                          ("rtmd", "meta", metadata, offsets[2], profile.timescale, profile.fps_den)])
    xml = nrt_xml(umid, len(video), spec.creation_time, "rec709", spec.base_profile)
    return (prefix + mdat + box("moov", tracks) +
            fullbox("meta", fullbox("hdlr", b"nrtm") + fullbox("xml ", xml)), xml)


class BitratePairTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.a, self.b = self.root / "a", self.root / "b"
        self.base = self.root / "base.mov"
        self.base.write_bytes(b"encoded shared base")
        self.build_pair()

    def build_pair(self, profile="hd16_2997", extended=False):
        nominal = 16000 if profile == "hd16_2997" else 25000
        self.manifests = []
        for variant, root, peer, clip, rate in [
                ("A", self.a, self.b, "C0100", nominal),
                ("B", self.b, self.a, "C0101", 4000)]:
            root.mkdir(exist_ok=True)
            raw = {"schema": 1, "kind": "bitrate_diagnostic", "experiment_id": "round-1",
                   "pair_id": "hd-pair", "variant": variant, "base_profile": profile,
                   "coded_bitrate_kbps": 4000, "hrd_bitrate_kbps": 4000,
                   "cpb_size_kbits": 4000, "prof_average_kbps": rate,
                   "prof_maximum_kbps": rate, "creation_time": "2026-11-13T17:00:00+08:00"}
            spec = ExperimentSpec.from_dict(raw)
            spec_path = root / "experiment.json"
            write_json(spec_path, raw)
            if variant == "A":
                write_json(self.root / "input-assumptions.json",
                           {"experiment_spec": raw,
                            "profile_parameters": spec.coding_profile().manifest_fields()})
            umid = (UMID_LABEL + uuid4().bytes).hex().upper()
            data, xml = media_bytes(spec, umid, extended)
            (root / (clip + ".MP4")).write_bytes(data)
            (root / (clip + "M01.XML")).write_bytes(xml)
            (root / (clip + "T01.JPG")).write_bytes(b"identical thumbnail")
            manifest = {
                "clip": clip, "umid": umid, "sha256": sha(data), "frames": 65,
                "package_kind": "bitrate_diagnostic", "test_role": "bitrate_diagnostic",
                "experiment_spec": raw, "sony_profile": profile,
                "profile_parameters": spec.coding_profile().manifest_fields(),
                "stamp": spec.creation_time, "nal_length_size": 4,
                "umid_mode": "edius_uuid4", "payload_layout": "structure_template",
                "acquisition": "rec709", "hrd_retiming": {"enabled": True},
                "base": str(self.base), "base_sha256": sha(self.base.read_bytes()),
                "encoder_assumptions_sha256": sha((self.root / "input-assumptions.json").read_bytes()),
                "experiment_spec_path": str(spec_path),
                "experiment_spec_sha256": sha(spec_path.read_bytes()),
                "diagnostic_evidence": {
                    "peer_build": str(peer), "pair_report": str(self.root / "pair.json"),
                    "reader_report": str(root / "reader.json")},
            }
            write_json(root / "build-manifest.json", manifest)
            self.manifests.append(manifest)

    def rewrite_manifest(self, index):
        write_json([self.a, self.b][index] / "build-manifest.json", self.manifests[index])

    def mutate_mp4(self, offset):
        path = self.b / "C0101.MP4"
        data = bytearray(path.read_bytes())
        data[offset] ^= 1
        path.write_bytes(data)
        # Defeat a merely stale-hash rejection so the isolation check is exercised.
        self.manifests[1]["sha256"] = sha(data)
        self.rewrite_manifest(1)

    def report(self):
        return compare_pair(self.a, self.b)

    def test_valid_pair_is_deterministic_json_and_has_precise_offsets(self):
        report = self.report()
        self.assertTrue(report["passed"], report)
        self.assertEqual(report, self.report())
        self.assertEqual(report, json.loads(json.dumps(report)))
        regions = report["allowed_diff_regions"]
        self.assertEqual([x["length"] for x in regions], [4, 4, 64, 64])
        with_media = MP4(self.a / "C0100.MP4")
        try:
            prof = with_media.one(with_media.top, "uuid")
            vprf = with_media.one(with_media.boxes(prof.data + 24, prof.end), "VPRF")
            self.assertEqual([r["offset"] for r in regions[:2]],
                             [vprf.data + 20, vprf.data + 24])
        finally:
            with_media.close()
        self.assertGreater(report["actual_changed_bytes"], 0)
        self.assertEqual(report["mp4_diff"]["unexpected_changed_bytes"], 0)
        self.assertTrue(all(r["allowed"] for r in report["mp4_diff"]["changed_regions"]))

    def test_extended_prof_headers_and_other_cadence(self):
        self.build_pair("hd25_5994", extended=True)
        self.assertTrue(self.report()["passed"], self.report())

    def test_rates_exclude_filler_from_vcl_and_use_sliding_decode_windows(self):
        report = self.report()
        rates = report["rates"]["a"]
        totals = rates["byte_totals"]
        self.assertEqual(totals["vcl"], sum(5 + i % 3 for i in range(65)))
        self.assertEqual(totals["filler"], sum(1 + i % 5 for i in range(65)))
        self.assertEqual(totals["nal"], totals["vcl"] + totals["filler"] + 2 * 65)
        self.assertEqual(totals["video"], totals["nal"] + 12 * 65)
        expected = max(sum((5 + i % 3) for i in range(first, min(65, first + 30)))
                       for first in range(65))
        peak = rates["one_second_decode_window_peak"]["vcl"]
        self.assertEqual(peak["bytes"], expected)
        self.assertEqual(peak["bps"], expected * 8)

    def test_unexpected_mutations_in_every_protected_region(self):
        for name in ["mdat", "unindexed", "moov", "free", "prof_neighbor", "xml_date"]:
            with self.subTest(name=name):
                self.build_pair()
                m = MP4(self.b / "C0101.MP4")
                try:
                    if name == "mdat":
                        offset = m.one(m.top, "mdat").data + 5
                    elif name == "unindexed":
                        offset = m.one(m.top, "mdat").end - 1
                    elif name == "moov":
                        offset = m.tracks[1].entry.data
                    elif name == "free":
                        offset = m.one(m.top, "free").data
                    elif name == "prof_neighbor":
                        p = m.one(m.top, "uuid")
                        v = m.one(m.boxes(p.data + 24, p.end), "VPRF")
                        offset = v.data + 19
                    else:
                        offset = m.buf.find(b'lastUpdate="') + len(b'lastUpdate="') + 9
                finally:
                    m.close()
                self.mutate_mp4(offset)
                self.assertFalse(self.report()["passed"])

    def test_moov_mapping_mutation_is_rejected_even_with_same_payload(self):
        m = MP4(self.b / "C0101.MP4")
        try:
            offset = m.tracks[0].tables["stco"].data + 11
        finally:
            m.close()
        self.mutate_mp4(offset)
        self.assertFalse(self.report()["passed"])

    def test_missing_or_bogus_specs_never_pass(self):
        original = copy.deepcopy(self.manifests[1])
        for mutation in [None, {}, {"schema": True}, {"coded_bitrate_kbps": 5000},
                         {"variant": "A"}, {"creation_time": "2026-11-13T17:00:00"}]:
            with self.subTest(mutation=mutation):
                self.manifests[1] = copy.deepcopy(original)
                if mutation is None:
                    del self.manifests[1]["experiment_spec"]
                elif not mutation:
                    self.manifests[1]["experiment_spec"] = {}
                else:
                    self.manifests[1]["experiment_spec"].update(mutation)
                self.rewrite_manifest(1)
                self.assertFalse(self.report()["passed"])

    def test_every_evidence_input_is_bound_and_rechecked(self):
        original = self.report()
        self.assertTrue(original["passed"])
        for key in ["manifest", "base", "source_spec", "encoder_assumptions"]:
            self.assertIn("sha256", original["a"][key])
            self.assertTrue(Path(original["a"][key]["path"]).is_absolute())
        for path in [self.base, self.root / "input-assumptions.json",
                     self.b / "experiment.json", self.b / "C0101T01.JPG"]:
            with self.subTest(path=path):
                data = path.read_bytes()
                path.write_bytes(data + b"x")
                self.assertFalse(self.report()["passed"])
                path.write_bytes(data)
        self.manifests[1]["harmless_extra_field"] = "still-bound"
        self.rewrite_manifest(1)
        altered = self.report()
        self.assertNotEqual(original["b"]["manifest"], altered["b"]["manifest"])
        self.assertFalse(altered["passed"])
        self.assertNotIn("catalog", original["a"])

    def test_sidecar_structure_and_exact_lexical_changes_are_not_masked(self):
        path = self.b / "C0101M01.XML"
        original = path.read_bytes()
        for after in [original.replace(b'TargetMaterial', b'OtherMaterial'),
                      original.replace(b'<Duration', b'<Duration extra="x"'),
                      original.replace(b"<VideoFormat>", b"<VideoFormat>\n")]:
            path.write_bytes(after)
            self.assertFalse(self.report()["passed"])
        path.write_bytes(original)

    def test_identity_must_be_unique_uuid4_with_correct_label(self):
        for mode in ["duplicate", "not_uuid4", "wrong_label"]:
            with self.subTest(mode=mode):
                self.build_pair()
                replacement = {
                    "duplicate": self.manifests[0]["umid"],
                    "not_uuid4": (UMID_LABEL + bytes(16)).hex().upper(),
                    "wrong_label": (bytes(16) + uuid4().bytes).hex().upper(),
                }[mode]
                old = self.manifests[1]["umid"]
                self.manifests[1]["umid"] = replacement
                for suffix in [".MP4", "M01.XML"]:
                    path = self.b / ("C0101" + suffix)
                    path.write_bytes(path.read_bytes().replace(old.encode(), replacement.encode()))
                self.manifests[1]["sha256"] = sha((self.b / "C0101.MP4").read_bytes())
                self.rewrite_manifest(1)
                self.assertFalse(self.report()["passed"])

    def test_null_or_missing_declared_hashes_cannot_disable_binding(self):
        original = copy.deepcopy(self.manifests[1])
        for name in ["sha256", "base_sha256", "experiment_spec_sha256",
                     "encoder_assumptions_sha256"]:
            for value in [None, "", "bogus", True]:
                with self.subTest(name=name, value=value):
                    self.manifests[1] = copy.deepcopy(original)
                    self.manifests[1][name] = value
                    self.rewrite_manifest(1)
                    self.assertFalse(self.report()["passed"])

    def test_report_ignores_catalog_staging_but_not_manifest(self):
        before = self.report()
        catalog = self.a / "catalog"
        catalog.mkdir()
        (catalog / "DATABASE.BIN").write_bytes(b"staged after pair proof")
        self.assertEqual(before, self.report())

    def test_diff_boundaries_offsets_and_size_changes(self):
        report = _diff(b"abc123xyz", b"abc456xyz", [{"offset": 3, "length": 3}])
        self.assertTrue(report["equal_after_precise_masks"])
        self.assertEqual(report["actual_changed_bytes"], 3)
        self.assertFalse(_diff(b"a1b", b"x2b", [{"offset": 1, "length": 1}])[
            "equal_after_precise_masks"])
        self.assertFalse(_diff(b"abc", b"abcd", [])["equal_after_precise_masks"])
        with self.assertRaises(ValueError):
            _diff(b"abc", b"abc", [{"offset": 2, "length": 2}])

    def test_cli_saves_identical_report_and_refuses_overwrite(self):
        output = self.root / "pair.json"
        command = [sys.executable, str(Path(__file__).resolve().parents[1] /
                                      "compare_bitrate_pair.py"),
                   "--a", str(self.a), "--b", str(self.b), "--output", str(output)]
        result = subprocess.run(command, capture_output=True, text=True)
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(_load_json(output), self.report())
        self.assertNotEqual(subprocess.run(command, capture_output=True).returncode, 0)

    def test_card_paths_refused_before_any_open(self):
        report = compare_pair("F:/PRIVATE/M4ROOT", self.b)
        self.assertFalse(report["passed"])
        self.assertIn("refuses card paths", report["errors"][0])


def _load_json(path):
    return json.loads(path.read_text(encoding="utf-8"))


if __name__ == "__main__":
    unittest.main()
