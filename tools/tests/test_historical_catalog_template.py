"""Historical sparse descriptors never replace the fresh allocation baseline."""
from datetime import datetime
from pathlib import Path
import struct
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from sony_db import fix_checksums, inventory
from stage_sd_catalog import catalog_records, record_checksum, validate_catalog_changes

ROOT = Path(__file__).resolve().parents[2]
SOURCE = ROOT / "backup/snap_20261113T135135"
FRESH = ROOT / "backup/snap_20261113T151407"


@unittest.skipUnless((FRESH / "_snapshot.json").is_file(), "Saved repair corpus unavailable")
class HistoricalTemplateTests(unittest.TestCase):
    def setUp(self):
        self.data = (FRESH / "PRIVATE/DATABASE/DATABASE.BIN").read_bytes()
        self.manifest = {"clip": "C9998", "frames": 60, "stamp": "2026-11-13T15:00:00+08:00",
                         "sony_profile": "hd16_2997"}
        self.updated = datetime.fromisoformat("2026-11-13T15:01:00+08:00")

    def build(self, data=None):
        return catalog_records(self.data if data is None else data, self.manifest, 7,
                               1000000, 5000, self.updated, "observed_minimal", SOURCE)

    def test_fresh_bitmap_counters_and_every_existing_record_are_preserved(self):
        output, details = self.build()
        old = {row["index"]: row for row in inventory(self.data)}
        new = {row["index"]: row for row in inventory(output)}
        self.assertEqual(details["new_records"], [118])
        self.assertEqual(details["modified_existing_records"], [])
        self.assertEqual(set(new) - set(old), {118})
        for index in old:
            self.assertEqual(old[index]["hex"], new[index]["hex"])
        for offset in (0x7c80, 0x7c88):
            self.assertEqual(struct.unpack_from("<I", output, offset)[0],
                             struct.unpack_from("<I", self.data, offset)[0] + 1)
        self.assertEqual(details["video_record"], 28)
        self.assertEqual(Path(details["template_source_snapshot"]), SOURCE)
        self.assertEqual(bytes.fromhex(new[118]["hex"])[6], 0x18)

    def test_current_repaired_template_still_requires_explicit_historical_source(self):
        with self.assertRaisesRegex(ValueError, "observed-minimal"):
            catalog_records(self.data, self.manifest, 7, 1, 1, self.updated, "observed_minimal")

    def test_historical_hash_tampering_is_refused(self):
        output, details = self.build()
        details["template_source_database_sha256"] = "0" * 64
        with self.assertRaisesRegex(ValueError, "hash changed"):
            validate_catalog_changes(self.data, output, details)

    def test_source_path_and_hash_must_be_paired(self):
        output, details = self.build()
        del details["template_source_database_sha256"]
        with self.assertRaisesRegex(ValueError, "source/hash"):
            validate_catalog_changes(self.data, output, details)

    def test_current_support_dependency_mismatch_is_refused(self):
        changed = bytearray(self.data)
        offset = 0x10000 + 28 * 160
        record = bytearray(changed[offset:offset + 160])
        record[10] = 1
        record_checksum(record)
        changed[offset:offset + 160] = record
        with self.assertRaisesRegex(ValueError, "dependency differs"):
            self.build(changed)

    def test_current_dependency_inactive_bitmap_is_refused(self):
        changed = bytearray(self.data)
        changed[0x4000 + 28 // 8] &= ~(1 << (28 % 8))
        fix_checksums(changed)
        with self.assertRaisesRegex(ValueError, "dependency missing"):
            self.build(changed)

    def test_historical_source_cannot_be_used_for_native_reuse(self):
        with self.assertRaisesRegex(ValueError, "only supported"):
            catalog_records(self.data, dict(self.manifest, sony_profile="hd25_5994"),
                            7, 1, 1, self.updated, "native_reuse", SOURCE)


if __name__ == "__main__":
    unittest.main()
