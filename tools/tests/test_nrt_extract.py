"""Purpose: regress original embedded-NRT XML extraction and handler checks.

Usage: python -m unittest discover -s tools/tests -p test_nrt_extract.py -v.
Design: synthetic temporary MP4s with conflicting sidecars exercise original
    firmware scanning, changed XML/padding and wrong-handler rejection.
Scope: requires identified local firmware; no live card or full NRT semantics.
"""
from pathlib import Path
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from emulate_nrt_extract import extract
from sony_mp4 import box, fullbox

ROOT = Path(__file__).resolve().parents[2]
FIRMWARE = ROOT / "firmware/m4-v602/usr/lib/libmpr.so"
EXPAT = FIRMWARE.parent / "libexpat.so.1.6.11"
HDLR = bytes.fromhex(
    "0000003768646c7200000000000000006e72746d000000000000000000000000"
    "4e6f6e2d5265616c2054696d65204d6574616461746100")


@unittest.skipUnless(FIRMWARE.is_file() and EXPAT.is_file(), "Identified firmware unavailable")
class NrtExtractTests(unittest.TestCase):
    def run_scanner(self, xml, handler=HDLR):
        with tempfile.TemporaryDirectory() as directory:
            media = Path(directory) / "probe.MP4"
            media.write_bytes(box("moov", b"") + fullbox("meta", handler + fullbox("xml ", xml)))
            # The deliberately conflicting sidecar must never be consulted.
            (media.parent / "probeM01.XML").write_bytes(b"<sidecar>wrong</sidecar>")
            return extract(media, FIRMWARE, EXPAT, media.parent)

    def test_original_scanner_reads_embedded_xml_not_conflicting_sidecar(self):
        xml = b'<?xml version="1.0"?><embedded>alpha</embedded>'
        report = self.run_scanner(xml)
        self.assertTrue(report["passed"])
        self.assertEqual(report["original_scanner_xml"].encode(), xml)
        self.assertTrue(report["checks"]["only_main_mp4_opened"])
        self.assertTrue(report["checks"]["executable_sections_unchanged"])

    def test_changed_embedded_bytes_are_returned_without_a_sidecar_edit(self):
        report = self.run_scanner(b"<embedded>different</embedded>\0\0\0")
        self.assertTrue(report["passed"])
        self.assertEqual(report["original_scanner_xml"], "<embedded>different</embedded>")

    def test_wrong_metadata_handler_is_rejected_by_original_scanner(self):
        with self.assertRaisesRegex(RuntimeError, "embedded_xml_size"):
            self.run_scanner(b"<embedded/>", HDLR.replace(b"nrtm", b"zzzz"))


if __name__ == "__main__":
    unittest.main()
