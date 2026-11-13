"""Purpose: regress local additive SD catalog staging and its mutation limits.

Usage: python -m unittest discover -s tools/tests -p test_stage_sd_catalog.py -v.
Design: synthetic database fixtures exercise allocation, shared-support reuse,
    reference counts, checksums and native/minimal profile/template refusals.
Scope: host-memory transactions only, not live card deployment or a general
    writer for repaired/unknown layouts; no physical playback is tested.
"""
import struct
import sys
import unittest
from datetime import datetime
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from build_sony_clip import nrt_xml
from sd_catalog_evidence import header_time
from sony_db import fix_checksums, inventory
from sony_umid import make_umid, restore_umid
from sony_profiles import PROFILES, get_profile
from stage_sd_catalog import (
    catalog_records, material_attributes, record_checksum, validate_catalog_changes,
)
from test_sd_catalog_evidence import ARRAY, MOVIES
from xml.etree import ElementTree as ET
from verify_sony_package import rec709_stream_matches


def fixture():
    data = bytearray(0x10000 + 128 * 160)
    struct.pack_into("<I", data, 0x30, 160)
    struct.pack_into("<I", data, 0x44, 128)
    for offset, value in ((0x7c40, 1), (0x7c44, 86), (0x7c4c, 72),
                          (0x7c80, 2), (0x7c84, 0), (0x7c88, 2)):
        struct.pack_into("<I", data, offset, value)
    video = bytearray(160)
    video[0] = 2
    video[4:8] = bytes.fromhex("ffffffff")
    struct.pack_into("<H", video, 8, 40 << 1 | 1)
    struct.pack_into("<H", video, 12, 25)
    video[27:30] = bytes.fromhex("553503")
    rec709 = bytearray(video)
    rec709[27:30] = bytes.fromhex("353103")
    later = bytearray(MOVIES[6505])
    struct.pack_into("<H", later, 14, 6506 << 2)
    for index, record in ((72, bytearray(ARRAY)), (78, bytearray(MOVIES[6502])),
                           (79, video), (81, rec709), (86, later), (87, bytearray(video))):
        record_checksum(record)
        data[0x10000 + index * 160:0x10000 + (index + 1) * 160] = record
        data[0x4000 + index // 8] |= 1 << (index % 8)
    fix_checksums(data)
    return data


class StageCatalogTests(unittest.TestCase):
    def setUp(self):
        self.before = fixture()
        self.stamp = datetime.fromisoformat("2026-11-12T20:50:00+08:00")
        self.updated = datetime.fromisoformat("2026-11-12T20:50:30.123+08:00")
        self.manifest = {"clip": "C6507", "frames": 90, "stamp": self.stamp.isoformat(),
                         "umid": make_umid(self.stamp, bytes.fromhex("9C50D1FFFEC4F949"), 0xc3).hex(),
                         "acquisition": "rec709"}

    def build(self):
        return catalog_records(self.before, self.manifest, 6502, 12345678, 45678, self.updated)

    def test_reuses_native_support_and_only_allocates_content(self):
        after, change = self.build()
        self.assertEqual(change["new_records"], [88])
        self.assertEqual(change["modified_existing_records"], [72])
        self.assertEqual((change["video_record"], change["umid_array_record"], change["umid_slot"]),
                         (81, 72, 1))
        self.assertTrue(change["video_reused"])
        self.assertTrue(change["umid_slot_reused"])
        self.assertEqual(struct.unpack_from("<I", after, 0x7c44)[0], 88)
        self.assertEqual(struct.unpack_from("<I", after, 0x7c4c)[0], 72)
        rows = {r["index"]: r for r in inventory(after)}
        movie, array = [bytes.fromhex(rows[i]["hex"]) for i in (88, 72)]
        self.assertEqual(restore_umid(movie, array).hex(), self.manifest["umid"])
        self.assertEqual(array[12:158], ARRAY[12:158])
        self.assertEqual(struct.unpack_from("<I", array, 8)[0], 10)
        self.assertEqual(header_time(after, 0x8018)["millisecond"], 123)

    def test_new_attribute_does_not_advance_content_cursor(self):
        self.manifest["acquisition"] = "unspecified"
        after, change = self.build()
        self.assertEqual(change["new_records"], [88, 89])
        self.assertFalse(change["video_reused"])
        self.assertEqual(struct.unpack_from("<I", after, 0x7c44)[0], 88)

    def test_new_node_uses_free_slot_without_replacing_old_slots(self):
        self.manifest["umid"] = make_umid(self.stamp, bytes.fromhex("0102030405060708"), 0xc3).hex()
        after, change = self.build()
        self.assertEqual(change["new_records"], [88])
        self.assertEqual(change["umid_slot"], 3)
        self.assertFalse(change["umid_slot_reused"])
        p = 0x10000 + 72 * 160
        self.assertEqual(after[p + 12:p + 108], self.before[p + 12:p + 108])

    def test_full_array_allocates_support_and_retains_old_array(self):
        p = 0x10000 + 72 * 160
        array = bytearray(self.before[p:p + 160])
        array[6] = 15
        record_checksum(array)
        self.before[p:p + 160] = array
        fix_checksums(self.before)
        self.manifest["umid"] = make_umid(self.stamp, bytes.fromhex("0102030405060708"), 0xc3).hex()
        after, change = self.build()
        self.assertEqual(change["new_records"], [88, 89])
        self.assertEqual(change["modified_existing_records"], [])
        self.assertEqual(struct.unpack_from("<I", after, 0x7c4c)[0], 89)
        self.assertEqual(after[p:p + 160], self.before[p:p + 160])

    def test_detects_existing_content_mutation_even_with_valid_checksum(self):
        after, change = self.build()
        p = 0x10000 + 78 * 160
        record = bytearray(after[p:p + 160])
        record[0x40] ^= 1
        record_checksum(record)
        after[p:p + 160] = record
        with self.assertRaises(ValueError):
            validate_catalog_changes(self.before, after, change)

    def test_detects_occupied_umid_payload_mutation(self):
        after, change = self.build()
        p = 0x10000 + 72 * 160
        record = bytearray(after[p:p + 160])
        record[12] ^= 1
        record_checksum(record)
        after[p:p + 160] = record
        with self.assertRaisesRegex(ValueError, "UMID contents"):
            validate_catalog_changes(self.before, after, change)

    def test_rejects_source_checksum_failure(self):
        self.before[0x8000] ^= 1
        with self.assertRaisesRegex(ValueError, "checksum"):
            self.build()

    def test_native_reuse_rejects_unmodeled_profiles_before_reading_database(self):
        for name in ("hd50_5994", "uhd60_2997"):
            manifest = dict(self.manifest, sony_profile=name)
            with self.subTest(profile=name), self.assertRaisesRegex(ValueError, "native_reuse"):
                catalog_records(b"", manifest, 6502, 1, 1, self.updated)

    def test_native_reuse_explicit_default_matches_legacy(self):
        expected, _ = self.build()
        profile = get_profile()
        self.manifest.update(sony_profile=profile.name, profile_parameters=profile.manifest_fields())
        actual, _ = self.build()
        self.assertEqual(actual, expected)

    def test_mediapro_attrs_select_codec_and_fps_without_changing_identity(self):
        legacy = material_attributes(self.manifest)
        for profile in PROFILES.values():
            manifest = dict(self.manifest, sony_profile=profile.name,
                            profile_parameters=profile.manifest_fields())
            attrs = material_attributes(manifest)
            self.assertEqual(attrs["videoType"], profile.video_codec)
            self.assertEqual(attrs["fps"], profile.xml_fps)
            for key in set(legacy) - {"videoType", "fps"}:
                self.assertEqual(attrs[key], legacy[key])
        with self.assertRaises(ValueError):
            material_attributes(dict(self.manifest, sony_profile="unknown"))

    def test_detects_unrelated_header_change_even_with_valid_checksum(self):
        after, change = self.build()
        after[0x8000] ^= 1
        fix_checksums(after)
        with self.assertRaisesRegex(ValueError, "header"):
            validate_catalog_changes(self.before, after, change)

    def test_detects_inactive_record_change(self):
        after, change = self.build()
        after[0x10000 + 100 * 160] = 1
        with self.assertRaisesRegex(ValueError, "inactive"):
            validate_catalog_changes(self.before, after, change)

    def test_rec709_xml_is_explicit_without_fake_device_or_lens(self):
        root = ET.fromstring(nrt_xml(self.manifest["umid"], 90, self.stamp.isoformat(), "rec709"))
        items = {x.get("name"): x.get("value") for x in root.iter() if x.tag.endswith("Item")}
        self.assertEqual(len(items), 3)
        self.assertEqual(set(items.values()), {"rec709"})
        self.assertFalse(any(x.tag.endswith(("Device", "Lens")) for x in root.iter()))

    def test_gamma22_cannot_be_verified_as_rec709_acquisition(self):
        video = {"codec_type": "video", "color_range": "tv", "color_space": "bt709",
                 "color_primaries": "bt709", "color_transfer": "bt470m"}
        self.assertFalse(rec709_stream_matches({"streams": [video]}))
        video["color_transfer"] = "bt709"
        self.assertTrue(rec709_stream_matches({"streams": [video]}))


class ObservedMinimalCatalogTests(unittest.TestCase):
    def setUp(self):
        StageCatalogTests.setUp(self)
        movie = bytearray(MOVIES[6502])
        movie[6] = 0x18
        movie[0x20:0x50] = bytes(48)
        movie[0x5a:0x70] = bytes(22)
        movie[0x7c:0x9e] = bytes(34)
        record_checksum(movie)
        self.before[0x10000 + 78 * 160:0x10000 + 79 * 160] = movie
        video = bytearray(self.before[0x10000 + 79 * 160:0x10000 + 80 * 160])
        video[10:158] = bytes(148)
        record_checksum(video)
        self.before[0x10000 + 79 * 160:0x10000 + 80 * 160] = video
        fix_checksums(self.before)

    def minimal(self):
        return catalog_records(self.before, self.manifest, 6502, 12345678, 45678,
                               self.updated, "observed_minimal")

    def test_minimal_preserves_every_existing_record_including_support(self):
        after, change = self.minimal()
        self.assertEqual(change["catalog_schema"], 3)
        self.assertEqual(change["new_records"], [88])
        self.assertEqual(change["modified_existing_records"], [])
        for row in inventory(self.before):
            p = int(row["offset"], 16)
            self.assertEqual(self.before[p:p + 160], after[p:p + 160])
        movie = bytes.fromhex(next(r["hex"] for r in inventory(after) if r["index"] == 88))
        self.assertEqual(movie[6], 0x18)
        self.assertEqual(movie[0x20:0x50], bytes(48))
        self.assertEqual(movie[0x5a:0x5f], bytes(5))
        self.assertEqual(struct.unpack_from("<III", movie, 0x70), (0, 12345678, 45678))
        self.assertEqual(struct.unpack_from("<H", movie, 14)[0] >> 2, 6507)

    def test_minimal_database_is_profile_independent_without_invented_parameters(self):
        expected, expected_change = self.minimal()
        for profile in PROFILES.values():
            self.manifest.update(sony_profile=profile.name, profile_parameters=profile.manifest_fields())
            actual, change = self.minimal()
            self.assertEqual(actual, expected)
            self.assertEqual(change, expected_change)

    def test_minimal_rejects_inconsistent_declared_profile(self):
        profile = get_profile("uhd60_2997")
        parameters = profile.manifest_fields()
        parameters["level_idc"] = 42
        self.manifest.update(sony_profile=profile.name, profile_parameters=parameters)
        with self.assertRaisesRegex(ValueError, "disagree"):
            self.minimal()

    def test_minimal_refuses_populated_or_wrong_flag_template(self):
        for offset in (6, 0x40, 0x5a, 0x62):
            with self.subTest(offset=offset):
                saved = bytes(self.before)
                p = 0x10000 + 78 * 160
                record = bytearray(self.before[p:p + 160])
                record[offset] ^= 1
                record_checksum(record)
                self.before[p:p + 160] = record
                with self.assertRaisesRegex(ValueError, "observed-minimal"):
                    self.minimal()
                self.before[:] = saved

    def test_minimal_validator_rejects_unknown_new_descriptor_changes(self):
        after, change = self.minimal()
        p = 0x10000 + 88 * 160
        movie = bytearray(after[p:p + 160])
        movie[6] ^= 8
        record_checksum(movie)
        after[p:p + 160] = movie
        with self.assertRaisesRegex(ValueError, "preserve"):
            validate_catalog_changes(self.before, after, change)

    def test_minimal_rejects_existing_number_and_unrecognized_mode(self):
        self.manifest["clip"] = "C6502"
        with self.assertRaisesRegex(ValueError, "already"):
            self.minimal()
        with self.assertRaisesRegex(ValueError, "Unknown catalog"):
            catalog_records(self.before, self.manifest, 6502, 1, 1, self.updated, "guess")


if __name__ == "__main__":
    unittest.main()
