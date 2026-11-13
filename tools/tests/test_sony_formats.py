"""Purpose: regress the small binary-format primitives used by Sony tools.

Usage: python -m unittest discover -s tools/tests -p test_sony_formats.py -v.
Design: round-trip and corruption vectors cover EBSP/Exp-Golomb, checksum
    regions/wrap, half-step timecodes and UMID date/database reconstruction.
Scope: unit-level modeled primitives, not complete AVC/SD conformance testing.
"""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from avc_sony import Bits, escape, unescape
from build_sony_clip import timecode
from sony_db import checksum, check_regions, fix_checksums
from sony_umid import material_time, make_umid, creation_time, restore_umid
from stage_sd_catalog import set_date
from datetime import datetime, timezone, timedelta


class SonyFormatsTests(unittest.TestCase):
    def test_ebsp_roundtrip(self):
        for data in [bytes(range(256)), bytes(1024), b"\0\0\0\1\0\0\2\0\0\3\0\0\4"]:
            self.assertEqual(unescape(escape(data)), data)

    def test_reject_invalid_epb(self):
        with self.assertRaises(ValueError):
            unescape(b"\0\0\3\4")

    def test_exp_golomb(self):
        b = Bits(bytes.fromhex("a640"))
        self.assertEqual([b.ue() for _ in range(4)], [0, 1, 2, 3])
        with self.assertRaises(ValueError):
            Bits(bytes(8)).ue()

    def test_checksum_little_endian(self):
        self.assertEqual(checksum(b"\x01\x02"), 513)
        self.assertEqual(checksum((0xFFFFFFFB).to_bytes(8, "little")), 0)
        self.assertEqual(checksum((65521).to_bytes(8, "little"), 65521), 0)

    def test_checksum_wrap(self):
        self.assertEqual(checksum(bytes([255]) * 16), 23)

    def test_checksum_regions_detect_tamper(self):
        data = bytearray(0x10000)
        fix_checksums(data)
        self.assertTrue(all(x["valid"] for x in check_regions(data)))
        data[0x8000] = 1
        self.assertFalse(all(x["valid"] for x in check_regions(data)))
        fix_checksums(data)
        self.assertTrue(all(x["valid"] for x in check_regions(data)))

    def test_timecode_half_step(self):
        self.assertEqual(timecode(0), bytes.fromhex("40000000"))
        self.assertEqual(timecode(1), bytes.fromhex("40800000"))
        self.assertEqual(timecode(60), bytes.fromhex("40010000"))
        self.assertEqual(timecode(1533), bytes.fromhex("56a50000"))
        self.assertEqual(timecode(3600), bytes.fromhex("42000100"))

    def test_umid_date_bcd(self):
        stamp = datetime(2026, 6, 25, tzinfo=timezone.utc)
        self.assertEqual(material_time(stamp), bytes.fromhex("00000000161206"))

    def test_umid_db_roundtrip(self):
        for hours, micros in [(8, 0), (-3, 123000)]:
            stamp = datetime(2026, 11, 12, 15, 11, 26, micros,
                             tzinfo=timezone(timedelta(hours=hours)))
            value = make_umid(stamp, bytes.fromhex("9C50D1FFFEC4F949"), 0xC5)
            r, array = bytearray(160), bytearray(160)
            set_date(r, 0x10, stamp)
            self.assertEqual(creation_time(r), stamp)
            array[5] = 32
            array[12:44] = value[:13] + bytes(11) + value[24:]
            r[0x5E] = value[23]
            r[0x5F:0x62] = value[13:16]
            self.assertEqual(restore_umid(r, array), value)


if __name__ == "__main__":
    unittest.main()
