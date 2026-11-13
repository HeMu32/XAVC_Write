"""Purpose: regress original MediaProfile/Expat parsing under the offline harness.

Usage: python -m unittest discover -s tools/tests -p test_mediapro_emulation.py -v.
Design: identified firmware and saved metadata test clip queries, malformed XML,
    unknown tags and refusal of writes by the modeled filesystem.
Scope: local firmware/artifacts and modeled I/O, not full UI or camera playback.
"""
import hashlib
import importlib.util
import sys
import unittest
from pathlib import Path
from xml.etree import ElementTree as ET

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

ROOT = Path(__file__).resolve().parents[2]
FIRMWARE = ROOT / "firmware/m4-v602/usr/lib/libmpr.so"
EXPAT = ROOT / "firmware/m4-v602/usr/lib/libexpat.so.1.6.11"
SNAPSHOT = ROOT / "backup/snap_20261112T214535"
PROFILE = SNAPSHOT / "PRIVATE/M4ROOT/MEDIAPRO.XML"
AVAILABLE = (FIRMWARE.is_file() and EXPAT.is_file() and PROFILE.is_file() and
             all(importlib.util.find_spec(name) for name in ("unicorn", "elftools")))


@unittest.skipUnless(AVAILABLE, "Requires offline firmware, Expat, snapshot and emulator dependencies")
class MediaProfileEmulationTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        from emulate_mediapro import MediaProfileEmulator
        cls.original = PROFILE.read_bytes()
        cls.engine = MediaProfileEmulator(FIRMWARE, EXPAT, SNAPSHOT)
        cls.result = cls.engine.run()

    def test_original_parser_and_original_clip_queries_cover_all_materials(self):
        result = self.result
        self.assertEqual(result["initialized_return"], 0)
        self.assertEqual(result["load_return"], 0)
        self.assertEqual(result["material_count_at_object_afc60"], 42)
        self.assertTrue(result["original_executable_sections_unchanged"])
        expected = {Path(node.attrib["uri"]).stem: node.attrib for node in
                    ET.fromstring(self.original).iter()
                    if node.tag.rsplit("}", 1)[-1] == "Material"}
        self.assertEqual({row["clip"] for row in result["materials"]}, set(expected))
        for row in result["materials"]:
            with self.subTest(clip=row["clip"]):
                self.assertEqual(row["original_find_return"], 0)
                self.assertEqual(row["original_clip_info_return"], 0)
                self.assertEqual(row["clip_info_name"], row["clip"] + ".MP4")
                self.assertEqual(row["clip_info_uri"].replace("\\", "/"),
                                 expected[row["clip"]]["uri"])
                self.assertEqual(row["umid_at_record_0a_hex"], expected[row["clip"]]["umid"])
        xml_calls = {row["symbol"] for row in result["original_expat_entrypoints_executed_during_load"]}
        self.assertTrue({"XML_Parse", "XML_ParserCreate", "XML_ParserFree"} <= xml_calls)
        operations = {row["operation"] for row in self.engine.io}
        self.assertTrue(operations <= {"Fsys_Open", "Fsys_Read", "Fsys_Close", "Fsys_Flush"})
        self.assertEqual(hashlib.sha256(PROFILE.read_bytes()).digest(),
                         hashlib.sha256(self.original).digest())

    def test_well_formed_but_unknown_material_tag_is_not_counted(self):
        from emulate_mediapro import MediaProfileEmulator
        root = ET.fromstring(self.original)
        for node in root.iter():
            if node.tag.rsplit("}", 1)[-1] == "Material":
                node.tag = node.tag.rsplit("}", 1)[0] + "}UnknownMaterial"
        ET.register_namespace("", root.tag[1:].split("}")[0])
        changed = ET.tostring(root, encoding="utf-8")
        engine = MediaProfileEmulator(FIRMWARE, EXPAT, SNAPSHOT, profile_override=changed)
        result = engine.run()
        self.assertEqual(result["load_return"], 0)
        self.assertEqual(result["material_count_at_object_afc60"], 0)
        self.assertEqual(result["materials"], [])
        self.assertTrue(result["original_executable_sections_unchanged"])

    def test_malformed_xml_is_rejected_by_original_expat_and_profile_load(self):
        from emulate_mediapro import MediaProfileEmulator
        engine = MediaProfileEmulator(
            FIRMWARE, EXPAT, SNAPSHOT, profile_override=b"<MediaProfile><Contents>")
        result = engine.run()
        self.assertEqual(result["initialized_return"], 0)
        self.assertEqual(result["load_return"], 0x65)
        self.assertEqual(result["materials"], [])
        self.assertTrue(result["original_executable_sections_unchanged"])

    def test_virtual_filesystem_rejects_writes(self):
        address = next(address for address, name in self.engine.plt.items() if name == "Fsys_Write")
        with self.assertRaisesRegex(RuntimeError, "forbidden file operation Fsys_Write"):
            self.engine.on_code(self.engine.uc, address, 4, None)


if __name__ == "__main__":
    unittest.main()
