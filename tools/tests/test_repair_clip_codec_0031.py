"""Regress the narrowly authorized metadata correction without card writes."""
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch
from xml.etree import ElementTree as ET

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from repair_clip_codec_0031 import (NEW, OLD, ORIGINALS, ROOT, corrected_mediapro,
                                    corrected_xml, media_patch, stage, verify_media)
from sony_mp4 import MP4


class XmlRepairTests(unittest.TestCase):
    def xml(self, codec=OLD):
        return b'<NonRealTimeMeta lastUpdate="unchanged"><VideoFormat><VideoFrame videoCodec="' + codec + b'"/></VideoFormat></NonRealTimeMeta>\n'

    def test_embedded_correction_preserves_length_and_unrelated_attributes(self):
        old = self.xml()
        fixed = corrected_xml(old)
        self.assertEqual(len(old), len(fixed))
        self.assertTrue(fixed.endswith(b"\n "))
        self.assertEqual(fixed, old.replace(OLD, NEW) + b" ")
        self.assertEqual(ET.fromstring(fixed).get("lastUpdate"), "unchanged")

    def test_canonical_wrong_or_duplicate_input_is_refused(self):
        for raw in (self.xml(NEW), self.xml(b"wrong"),
                    self.xml().replace(b"</VideoFormat>", b'<VideoFrame videoCodec="' + OLD + b'"/></VideoFormat>')):
            with self.subTest(raw=raw), self.assertRaises(ValueError):
                corrected_xml(raw)

    def test_mediapro_patches_only_selected_existing_material_without_reserialization(self):
        original = (b'<?xml version="1.0"?>\r\n<MediaProfile createdAt="unchanged"><Contents>\r\n' +
                    b'<Material uri="./CLIP/C6520.MP4" videoType="' + OLD + b'"/>\r\n' +
                    b'<Material uri="./CLIP/C6521.MP4" videoType="' + OLD + b'"/>\r\n' +
                    b'</Contents></MediaProfile>\r\n')
        expected = original.replace(OLD, NEW, 1)
        self.assertEqual(corrected_mediapro(original, "C6520"), expected)
        self.assertEqual(corrected_mediapro(expected, "C6521"), expected.replace(OLD, NEW))
        with self.assertRaises(ValueError):
            corrected_mediapro(expected, "C6520")
        with self.assertRaises(ValueError):
            corrected_mediapro(original, "C9999")

    def test_unauthorized_target_and_nonlocal_build_rejected_before_card_reads(self):
        with patch("repair_clip_codec_0031.bind_snapshot") as bind:
            with self.assertRaises(ValueError):
                stage("C6522", Path("unused"), Path("unused"), Path("F:/"), ROOT / "output/new-unused")
            with self.assertRaises(ValueError):
                stage("C6520", Path("unused"), Path("unused"), Path("F:/"), Path("F:/not-local"))
            bind.assert_not_called()


@unittest.skipUnless((ORIGINALS["C6520"] / "C6520.MP4").is_file(), "Requires saved experiment media")
class RealMediaRepairTests(unittest.TestCase):
    def test_exact_xml_only_patch_and_vcl_mutation_negative_control(self):
        source = ORIGINALS["C6520"] / "C6520.MP4"
        offset, old, fixed = media_patch(source)
        before = source.read_bytes()
        corrected = bytearray(before)
        corrected[offset:offset + len(old)] = fixed
        with tempfile.TemporaryDirectory() as temp:
            output = Path(temp) / "C6520.MP4"
            output.write_bytes(corrected)
            self.assertTrue(all(verify_media(source, output).values()))
            media = MP4(source)
            try:
                position = media.tracks[0].offsets[0] + 8
            finally:
                media.close()
            corrected[position] ^= 1
            output.write_bytes(corrected)
            with self.assertRaises(ValueError):
                verify_media(source, output)
        self.assertEqual(source.read_bytes(), before)


if __name__ == "__main__":
    unittest.main()
