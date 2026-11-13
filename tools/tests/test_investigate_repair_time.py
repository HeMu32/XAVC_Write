"""Purpose: independently regress experiment 0027 date-packing interpretation.

Usage: python -m unittest discover -s tools/tests
    -p test_investigate_repair_time.py -v.
Design: fixed vectors distinguish before/after values, timezone/subsecond
    packing and masked versus full unsigned maximum selection.
Scope: modeled time evidence, not actual capture dates or a live repair trace.
"""
import struct
import sys
import unittest
from datetime import datetime
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from investigate_repair_time import MASK, maximum, pack_header, record_time
from sd_catalog_evidence import header_time


class RepairHeaderTimeTests(unittest.TestCase):
    def test_exact_after_header_and_record_bytes(self):
        record = bytes.fromhex("0cc07e0000dcfb72")
        value = record_time(record, 0)
        self.assertEqual(value["iso"], "2026-12-14T11:59:55+03:00")
        self.assertEqual(value["header_packed"], "0x667ec72fbdc00")
        self.assertEqual(pack_header(datetime.fromisoformat(value["iso"])), 0x667EC72FBDC00)

    def test_before_is_four_seconds_later_but_not_exact(self):
        value = record_time(bytes.fromhex("00c07e0000ecfb72"), 0)
        self.assertEqual(value["iso"], "2026-12-14T11:59:59+00:00")
        self.assertEqual(value["header_packed"], "0x607ec72fbec00")
        self.assertNotEqual(value["header_packed"], "0x667ec72fbdc00")

    def test_header_roundtrip_timezone_and_subseconds(self):
        packed = pack_header(datetime.fromisoformat("2026-11-13T13:54:48.768+08:00"))
        value = header_time(struct.pack("<Q", packed), 0)
        self.assertEqual(value["raw"], "0x707eb6b76c300")
        self.assertEqual(value["timezone_minutes"], 480)
        self.assertEqual(value["millisecond"], 768)

    def test_masked_and_unsigned_maxima_differ(self):
        rows = [{"index": i, "paths": [],
                 "creation": {"iso": iso, "header_packed": hex(pack_header(datetime.fromisoformat(iso)))}}
                for i, iso in [(53, "2026-12-14T11:59:55+03:00"),
                               (98, "2026-11-13T13:14:53+08:00")]]
        self.assertEqual(maximum(rows, "creation", "masked")[0]["index"], 53)
        self.assertEqual(maximum(rows, "creation", "unsigned_full")[0]["index"], 98)
        self.assertEqual(maximum(rows, "creation", "utc")[0]["index"], 53)

    def test_negative_timezone_roundtrip(self):
        packed = pack_header(datetime.fromisoformat("2026-11-13T01:02:03.004-03:30"))
        self.assertEqual(header_time(struct.pack("<Q", packed), 0)["timezone_minutes"], -210)
        self.assertEqual(packed & MASK, pack_header(datetime.fromisoformat("2026-11-13T01:02:03.004+00:00")) & MASK)


if __name__ == "__main__":
    unittest.main()
