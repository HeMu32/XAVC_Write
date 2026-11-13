"""Purpose: regress construction of the historical-source identity control.

Usage: python -m unittest discover -s tools/tests -p test_source_control.py -v.
Design: temporary sources and mutation cases verify streaming preservation,
    provenance, allowed XML/header edits and rejection of evidence/path changes.
Scope: local source-control packaging, not native-camera encoding or card writes.
"""
import copy
import hashlib
import io
import json
import struct
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch
from xml.etree import ElementTree as ET

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from build_source_control import (
    COPY_BLOCK, OBSERVATION_SCOPE, PROF_UUID, UMID_PREFIX, build_source_control,
    copy_range, digest, rewrite_xml,
    source_payload_checks, stamp_ranges,
)
from sony_mp4 import MP4, box, fullbox


def table(kind, rows):
    return fullbox(kind, struct.pack(">I", len(rows)) +
                   b"".join(struct.pack(">" + "I" * len(row), *row) for row in rows))


def track(handler, codec, sizes, offset, scale, delta, version=0):
    count = len(sizes)
    duration = count * delta
    if version:
        mdhd = fullbox("mdhd", struct.pack(">QQIQ", 1, 2, scale, duration) + bytes(4), 1 << 24)
        tkhd = fullbox("tkhd", struct.pack(">QQIIQ", 1, 2, 1, 0, duration), 1 << 24)
    else:
        mdhd = fullbox("mdhd", struct.pack(">IIII", 1, 2, scale, duration) + bytes(4))
        tkhd = fullbox("tkhd", struct.pack(">IIIII", 1, 2, 1, 0, duration))
    stbl = (fullbox("stsd", struct.pack(">I", 1) + box(codec, b"source-configuration")) +
            fullbox("stsz", struct.pack(">II", 0, count) + struct.pack(">" + "I" * count, *sizes)) +
            table("stts", [(count, delta)]) + table("stsc", [(1, count, 1)]) +
            table("stco", [(offset,)]))
    hdlr = fullbox("hdlr", bytes(4) + handler.encode("ascii") + bytes(12))
    return box("trak", tkhd + box("mdia", mdhd + hdlr + box("minf", box("stbl", stbl))))


def source_fixture(xml, version=0):
    prof = box("uuid", PROF_UUID + bytes(8) +
               box("VPRF", bytes.fromhex("000000000000c3500000c350003bf0a6003bf0a6") +
                   b"opaque-not-avc1"))
    ftyp = box("ftyp", b"fixture ")
    start = len(ftyp) + len(prof) + 16
    payload = b"VIDvid" + b"PCM!" * 8 + b"RTMDrtmd" + b"padding-is-preserved"
    mdat = struct.pack(">I4sQ", 1, b"mdat", 16 + len(payload)) + payload
    if version:
        mvhd = fullbox("mvhd", struct.pack(">QQIQ", 1, 2, 60000, 2002), 1 << 24)
    else:
        mvhd = fullbox("mvhd", struct.pack(">IIII", 1, 2, 60000, 2002))
    moov = box("moov", mvhd +
               track("vide", "avc1", [3, 3], start, 60000, 1001, version) +
               track("soun", "twos", [4] * 8, start + 6, 48000, 1, version) +
               track("meta", "rtmd", [4, 4], start + 38, 60000, 1001, version))
    return ftyp + prof + mdat + moov + fullbox("meta", fullbox("hdlr", b"unchanged") +
                                                           fullbox("xml ", xml))


def fixture_xml():
    return (
        b'<?xml version="1.0" encoding="UTF-8"?>\r\r\n'
        b'<NonRealTimeMeta xmlns="urn:source-test" lastUpdate="2026-06-25T23:45:44+08:00">\r\r\n'
        b'<!-- Keep this comment and the original whitespace. -->\r\r\n'
        b'<TargetMaterial umidRef="' + UMID_PREFIX.hex().upper().encode() + b'0123456789ABCDEF0123456789ABCDEF"/>\r\r\n'
        b'<Duration value="2"/><CreationDate value="2026-06-25T23:44:37+08:00"/>\r\r\n'
        b'<LtcChangeTable><LtcChange value="40000000"/><LtcChange value="40800000"/></LtcChangeTable>\r\r\n'
        b'<VideoFormat label="unchanged &amp; retained"/>\r\r\n'
        b'</NonRealTimeMeta>\r\r\n')


class SourceControlTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.source = self.root / "analysis" / "C0007-reference-0023.MP4"
        self.source.parent.mkdir()
        self.snapshot = self.root / "snapshot"
        self.sidecar = self.snapshot / "PRIVATE/M4ROOT/CLIP/C0007M01.XML"
        self.sidecar.parent.mkdir(parents=True)
        self.card = self.root / "card"
        self.thumbnail = self.card / "PRIVATE/M4ROOT/THMBNL/C0007T01.JPG"
        self.thumbnail.parent.mkdir(parents=True)
        self.thumbnail.write_bytes(b"source thumbnail bytes")
        (self.snapshot / "_snapshot.json").write_text(json.dumps({"card": str(self.card)}))
        self.xml = fixture_xml()
        self.sidecar.write_bytes(self.xml.replace(b"\r\r\n", b"\r\n"))
        self.source.write_bytes(source_fixture(self.xml))
        self.observations = self.root / "observations.json"
        self.observation = {
            "scope": OBSERVATION_SCOPE,
            "historical_playback_positive": [{
                "clip": "C0007", "source_sha256": digest(self.source),
                "camera_playback": "USER_REPORTED_SUCCESS",
                "provenance": "Synthetic test fixture, not actual playback evidence",
            }],
        }
        self.save_observation()
        self.output = self.root / "output"

    def save_observation(self):
        self.observations.write_text(json.dumps(self.observation))

    def build(self, **kwargs):
        params = dict(source=self.source, snapshot=self.snapshot, clip="C6511",
                      output=self.output, observations=self.observations)
        params.update(kwargs)
        return build_source_control(**params)

    def test_distinct_profile_bound_evidence_and_opaque_prof(self):
        before = self.source.read_bytes()
        manifest = self.build()
        self.assertEqual(manifest["package_kind"], "source_control")
        self.assertNotIn("native_source_sha256", manifest)
        self.assertEqual(manifest["umid_mode"], "edius_label_uuid4")
        self.assertEqual(bytes.fromhex(manifest["umid"])[:16], UMID_PREFIX)
        import uuid
        self.assertEqual(uuid.UUID(bytes=bytes.fromhex(manifest["umid"])[16:]).version, 4)
        self.assertNotEqual(manifest["umid"], manifest["source_umid"])
        self.assertEqual(manifest["source_sha256"], hashlib.sha256(before).hexdigest())
        self.assertEqual(manifest["source_sidecar"], str(self.sidecar))
        self.assertEqual(manifest["source_sidecar_sha256"], digest(self.sidecar))
        self.assertEqual(manifest["observations_path"], str(self.observations))
        self.assertEqual(manifest["observations_sha256"], digest(self.observations))
        self.assertEqual(manifest["source_sidecar_match"], "xml_semantic")
        self.assertEqual(manifest["nominal_video_bitrate_mbps"], 50)
        self.assertEqual(manifest["nominal_video_bitrate_basis"], "historical_user_report")
        self.assertEqual(manifest["prof_classification"], "observed_source_opaque")
        self.assertEqual(manifest["acquisition"], "unspecified")
        self.assertEqual(manifest["camera_playback"], "NOT_TESTED")
        self.assertEqual(self.source.read_bytes(), before)
        self.assertTrue(all(manifest["source_preservation_checks"].values()))
        self.assertEqual((self.output / "C6511T01.JPG").read_bytes(), self.thumbnail.read_bytes())
        self.assertEqual(manifest["sha256"], digest(self.output / "C6511.MP4"))

    def test_only_allowed_xml_values_and_container_stamps_change(self):
        manifest = self.build()
        a, b = MP4(self.source), MP4(self.output / "C6511.MP4")
        try:
            self.assertEqual([(x.start, x.size) for x in a.top[:-1]],
                             [(x.start, x.size) for x in b.top[:-1]])
            for x, y in zip(a.top, b.top):
                if x.kind not in {"moov", "meta"}:
                    self.assertEqual(a.raw(x), b.raw(y))
            original, changed = bytearray(a.raw(a.moov)), bytearray(b.raw(b.moov))
            for start, width in stamp_ranges(a):
                offset = start - a.moov.start
                self.assertNotEqual(original[offset:offset + width * 2],
                                    changed[offset:offset + width * 2])
                original[offset:offset + width * 2] = changed[offset:offset + width * 2]
            self.assertEqual(original, changed)
            expected = self.xml
            source_umid = ET.fromstring(self.xml).find("{urn:source-test}TargetMaterial").get("umidRef")
            expected = expected.replace(source_umid.encode(), manifest["umid"].encode())
            for stamp in (b"2026-06-25T23:45:44+08:00", b"2026-06-25T23:44:37+08:00"):
                expected = expected.replace(stamp, manifest["stamp"].encode())
            actual = b.payload(b.child(b.one(b.top, "meta"), "xml ", 4))[4:]
            self.assertEqual(actual, expected)
            self.assertEqual(expected.replace(b"\r\r\n", b"\r\n"),
                             (self.output / "C6511M01.XML").read_bytes())
        finally:
            a.close()
            b.close()

    def test_streams_mdat_instead_of_materializing_it(self):
        original_raw, original_payload = MP4.raw, MP4.payload
        def raw(media, item):
            self.assertNotEqual(item.kind, "mdat")
            return original_raw(media, item)
        def payload(media, item):
            self.assertNotEqual(item.kind, "mdat")
            return original_payload(media, item)
        with patch.object(MP4, "raw", raw), patch.object(MP4, "payload", payload):
            self.build()

    def test_streaming_copy_is_bounded_and_detects_truncation(self):
        class BoundedReader(io.BytesIO):
            def read(self, count=-1):
                if not 0 <= count <= COPY_BLOCK:
                    raise AssertionError("Unbounded read")
                return super().read(count)
        data = b"a" * (2 * COPY_BLOCK + 7)
        target = io.BytesIO()
        copy_range(BoundedReader(data), target, 0, len(data))
        self.assertEqual(target.getvalue(), data)
        with self.assertRaisesRegex(ValueError, "Truncated"):
            copy_range(BoundedReader(b"short"), io.BytesIO(), 0, 10)

    def test_version_one_headers_preserve_non_stamp_bytes(self):
        self.source.write_bytes(source_fixture(self.xml, version=1))
        self.observation["historical_playback_positive"][0]["source_sha256"] = digest(self.source)
        self.save_observation()
        self.assertTrue(all(self.build()["source_preservation_checks"].values()))

    def test_explicit_thumbnail_and_local_same_drive_are_allowed(self):
        explicit = self.root / "explicit.JPG"
        explicit.write_bytes(b"explicit original thumbnail")
        self.thumbnail.unlink()
        manifest = self.build(thumbnail=explicit)
        self.assertEqual(manifest["source_thumbnail"], str(explicit))
        self.assertEqual(manifest["source_thumbnail_sha256"], digest(explicit))
        self.assertEqual(self.source.drive, self.output.drive)

    def test_missing_mismatched_listing_only_or_duplicate_observations_rejected(self):
        saved = copy.deepcopy(self.observation)
        variants = [
            {},
            dict(saved, scope="fresh_retest"),
            dict(saved, historical_playback_positive=[]),
            dict(saved, historical_playback_positive=saved["historical_playback_positive"] * 2),
        ]
        for key, value in (("source_sha256", "0" * 64), ("camera_playback", True),
                           ("camera_playback", "LISTED"), ("provenance", "")):
            report = copy.deepcopy(saved)
            report["historical_playback_positive"][0][key] = value
            variants.append(report)
        for report in variants:
            with self.subTest(report=report):
                self.observation = report
                self.save_observation()
                with self.assertRaises(ValueError):
                    self.build()
                self.assertFalse(self.output.exists())

    def test_source_hash_and_sidecar_semantics_are_required(self):
        self.sidecar.write_bytes(self.sidecar.read_bytes().replace(b'value="2"', b'value="3"'))
        with self.assertRaisesRegex(ValueError, "semantically"):
            self.build()
        self.assertFalse(self.output.exists())
        self.source.write_bytes(self.source.read_bytes() + b"changed")
        with self.assertRaisesRegex(ValueError, "hash"):
            self.build()
        self.assertFalse(self.output.exists())

    def test_fresh_output_and_card_snapshot_boundaries(self):
        self.output.mkdir()
        sentinel = self.output / "keep.txt"
        sentinel.write_bytes(b"keep")
        for output in (self.output, self.source, self.source / "child",
                       self.snapshot / "new-output", self.card / "new-output"):
            with self.subTest(output=output), self.assertRaises(ValueError):
                self.build(output=output)
        self.assertEqual(sentinel.read_bytes(), b"keep")
        if sys.platform == "win32":
            with self.assertRaises(ValueError):
                self.build(output=Path("F:/source-control-must-not-be-created"))

    def test_invalid_clip_and_source_label_are_rejected(self):
        for clip in ("C0007", "../C6511", "C65110", "not-a-clip"):
            with self.subTest(clip=clip), self.assertRaises(ValueError):
                self.build(clip=clip)
        xml = self.xml.replace(UMID_PREFIX.hex().upper().encode(), b"06" * 16)
        self.source.write_bytes(source_fixture(xml))
        self.sidecar.write_bytes(xml)
        self.observation["historical_playback_positive"][0]["source_sha256"] = digest(self.source)
        self.save_observation()
        with self.assertRaisesRegex(ValueError, "EDIUS"):
            self.build()
        self.assertFalse(self.output.exists())

    def test_payload_checker_detects_mdat_prof_and_table_tampering(self):
        self.build()
        target = self.output / "C6511.MP4"
        original = target.read_bytes()
        media = MP4(target)
        mdat = media.one(media.top, "mdat")
        prof = media.one(media.top, "uuid")
        table_box = media.tracks[0].tables["stsz"]
        positions = [mdat.data, prof.data + 16, table_box.end - 1]
        media.close()
        for position, failed in zip(positions, ("source_mdat_bit_exact", "source_prof_bit_exact",
                                                "source_track_configuration_bit_exact")):
            changed = bytearray(original)
            changed[position] ^= 1
            target.write_bytes(changed)
            checks = source_payload_checks(self.source, target)
            self.assertFalse(checks[failed])
            if failed != "source_prof_bit_exact":
                self.assertFalse(checks["source_track_payloads_bit_exact"])
        target.write_bytes(original)

    def test_evidence_changed_during_copy_prevents_completed_manifest(self):
        changed = False
        def copy_and_change(src, dst, start, size):
            nonlocal changed
            copy_range(src, dst, start, size)
            if not changed:
                self.observations.write_bytes(self.observations.read_bytes() + b"\n")
                changed = True
        with patch("build_source_control.copy_range", side_effect=copy_and_change):
            with self.assertRaisesRegex(ValueError, "evidence changed"):
                self.build()
        self.assertFalse((self.output / "build-manifest.json").exists())

    def test_xml_rewrite_rejects_missing_or_duplicate_fields(self):
        for xml in (self.xml.replace(b' lastUpdate="2026-06-25T23:45:44+08:00"', b""),
                    self.xml.replace(b"</NonRealTimeMeta>", b'<CreationDate value="other"/></NonRealTimeMeta>')):
            with self.assertRaises(ValueError):
                rewrite_xml(xml, "A" * 64, "2026-11-13T01:00:00+08:00")

    def shared_identity_checks(self, manifest):
        from verify_sony_package import source_control_identity_checks
        source, target = MP4(self.source), MP4(self.output / "C6511.MP4")
        try:
            return source_control_identity_checks(manifest, source, target)
        finally:
            source.close()
            target.close()

    def test_shared_identity_verifier_accepts_semantic_sidecar_and_builder_manifest(self):
        manifest = self.build()
        self.assertNotEqual(self.xml, self.sidecar.read_bytes())
        checks = self.shared_identity_checks(manifest)
        self.assertTrue(all(checks.values()), checks)

    def test_shared_identity_verifier_binds_raw_embedded_hash_including_nul(self):
        raw_xml = self.xml + b"\x00"
        self.source.write_bytes(source_fixture(raw_xml))
        self.observation["historical_playback_positive"][0]["source_sha256"] = digest(self.source)
        self.save_observation()
        manifest = self.build()
        target = MP4(self.output / "C6511.MP4")
        try:
            self.assertTrue(target.payload(target.child(
                target.one(target.top, "meta"), "xml ", 4))[4:].endswith(b"\x00"))
            self.assertFalse((self.output / "C6511M01.XML").read_bytes().endswith(b"\x00"))
        finally:
            target.close()
        self.assertEqual(manifest["source_embedded_xml_sha256"],
                         hashlib.sha256(raw_xml).hexdigest())
        self.assertNotEqual(manifest["source_embedded_xml_sha256"],
                            hashlib.sha256(self.xml).hexdigest())
        self.assertTrue(all(self.shared_identity_checks(manifest).values()))
        manifest["source_embedded_xml_sha256"] = hashlib.sha256(self.xml).hexdigest()
        self.assertFalse(self.shared_identity_checks(manifest)["source_identity_verified"])

    def test_shared_identity_verifier_rejects_changed_sidecar_even_with_updated_hash(self):
        manifest = self.build()
        self.sidecar.write_bytes(self.sidecar.read_bytes().replace(b'value="2"', b'value="3"'))
        manifest["source_sidecar_sha256"] = digest(self.sidecar)
        self.assertFalse(self.shared_identity_checks(manifest)["source_identity_verified"])

    def test_shared_identity_verifier_rejects_metadata_fullbox_flag_changes(self):
        manifest = self.build()
        target = self.output / "C6511.MP4"
        original = target.read_bytes()
        media = MP4(target)
        meta = media.one(media.top, "meta")
        xml = media.child(meta, "xml ", 4)
        positions = [meta.data + 3, xml.data + 3]
        media.close()
        for position in positions:
            mutated = bytearray(original)
            mutated[position] ^= 1
            target.write_bytes(mutated)
            self.assertFalse(self.shared_identity_checks(manifest)[
                "source_container_changes_limited_to_identity_and_dates"])
        target.write_bytes(original)


if __name__ == "__main__":
    unittest.main()
