"""Purpose: regress bounded original repair-field and array-hash experiments.

Usage: python -m unittest discover -s tools/tests -p test_sd_repair_fields.py -v.
Design: validate ELF-symbol export completeness, untouched code sections,
    original flag/photo cases, occupied slots, negative controls and restoration.
Scope: identified local firmware/snapshots with Unicorn/ELF/Capstone dependencies;
    not complete Load/repair, live cache capture or camera execution.
"""
import hashlib
import importlib.util
import json
import struct
import sys
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

ROOT = Path(__file__).resolve().parents[2]
FIRMWARE = ROOT / "firmware/m4-v602/usr/lib/libmpr.so"
SNAPSHOTS = [ROOT / "backup" / name for name in
             ("snap_20261113T135135", "snap_20261113T135646")]
AVAILABLE = (FIRMWARE.is_file() and all(
    (snapshot / "PRIVATE/DATABASE/DATABASE.BIN").is_file() for snapshot in SNAPSHOTS) and
    all(importlib.util.find_spec(name) for name in ("unicorn", "elftools", "capstone")))


@unittest.skipUnless(AVAILABLE, "Requires saved M4 firmware/snapshots, Unicorn, pyelftools, Capstone")
class RepairFieldTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        import emulate_sd_repair_fields as probes
        cls.probes = probes

    def test_full_elf_symbol_exports_include_load_tail_and_hashes(self):
        from elftools.elf.elffile import ELFFile
        with tempfile.TemporaryDirectory() as directory:
            result = self.probes.export_symbol_assembly(FIRMWARE, Path(directory))
            self.assertEqual(result["firmware_sha256"], self.probes.EXPECTED)
            self.assertEqual(len(result["exports"]), 5)
            with FIRMWARE.open("rb") as stream:
                elf = ELFFile(stream)
                for row in result["exports"]:
                    with self.subTest(symbol=row["label"]):
                        path = Path(directory) / row["assembly_file"]
                        raw = path.read_bytes()
                        self.assertEqual(hashlib.sha256(raw).hexdigest(), row["assembly_sha256"])
                        lines = [line.split() for line in raw.decode().splitlines()
                                 if not line.startswith("//")]
                        start, size = int(row["elf_vma"], 16), int(row["size"], 16)
                        self.assertEqual(len(lines) * 4, size)
                        self.assertEqual([int(line[0], 16) for line in lines],
                                         list(range(start, start + size, 4)))
                        section = elf.get_section_by_name(row["section"])
                        offset = start - section["sh_addr"]
                        code = section.data()[offset:offset + size]
                        self.assertEqual(b"".join(bytes.fromhex(line[1]) for line in lines), code)
                        self.assertEqual(hashlib.sha256(code).hexdigest(), row["symbol_bytes_sha256"])
                        if row["label"] == "Load":
                            self.assertEqual((start, size), (0x2992C8, 0xB24))
                            self.assertEqual(int(lines[-1][0], 16), 0x299DE8)
                            self.assertIn(0x299D2C, [int(line[0], 16) for line in lines])
            manifest = Path(result["manifest"])
            self.assertEqual(hashlib.sha256(manifest.read_bytes()).hexdigest(),
                             result["manifest_sha256"])
            self.assertEqual(json.loads(manifest.read_text())["exports"], result["exports"])

    def test_export_rejects_unidentified_elf_without_outputs(self):
        with tempfile.TemporaryDirectory() as directory:
            firmware = Path(directory) / "not-libmpr.so"
            firmware.write_bytes(b"not an identified firmware")
            output = Path(directory) / "assembly"
            with self.assertRaisesRegex(ValueError, "identified"):
                self.probes.export_symbol_assembly(firmware, output)
            self.assertFalse(output.exists())

    def test_executable_integrity_detects_host_patches_but_allows_got_model(self):
        engine = self.probes.RepairProbeEngine(FIRMWARE)
        engine.uc.mem_write(0x301CB0, struct.pack("<Q", self.probes.STACK + 0x1000))
        engine.check_executable_sections("allowed_got")
        for name, address, raw in engine.code_sections:
            with self.subTest(section=name):
                engine.uc.mem_write(address, bytes([raw[0] ^ 1]))
                with self.assertRaisesRegex(RuntimeError, "Executable ELF section changed"):
                    engine.check_executable_sections("deliberate_host_patch")
                engine.uc.mem_write(address, raw[:1])
        engine.check_executable_sections("restored")
        self.assertEqual({row["name"] for row in engine.integrity_checks[-1]["sections"]},
                         {".init", ".plt", ".text", ".fini"})

    def test_original_flags_assignments_and_all_photo_conversions(self):
        engine = self.probes.RepairProbeEngine(FIRMWARE)
        flags = self.probes.original_flag_cases(engine)
        self.assertTrue(flags["passed"])
        self.assertEqual(flags["case_count"], 1024)
        self.assertEqual(len(flags["repair_assignments"]), 4)
        engine.check_executable_sections("after_flags")
        for snapshot in SNAPSHOTS:
            with self.subTest(snapshot=snapshot.name):
                result = self.probes.photo_conversions(engine, snapshot)
                self.assertTrue(result["passed"])
                self.assertTrue(result["database_unchanged_in_emulator"])
                self.assertEqual(len(result["photos"]), 23)
                engine.check_executable_sections(f"after_photos:{snapshot.name}")

    def test_all_33_occupied_slots_and_packed_search_controls(self):
        engine = self.probes.RepairProbeEngine(FIRMWARE)
        total = 0
        for snapshot, count in zip(SNAPSHOTS, (5, 28)):
            data = (snapshot / "PRIVATE/DATABASE/DATABASE.BIN").read_bytes()
            engine.load(data)
            got = [bytes(engine.uc.mem_read(address, 8)) for address in (0x301CB0, 0x3017C8)]
            result = self.probes.array_hash_handle_cases(engine, data)
            expected = set()
            for row in self.probes.inventory(data):
                if row["type"] == 3:
                    bitmap = struct.unpack_from("<H", bytes.fromhex(row["hex"]), 6)[0]
                    expected.update((row["index"], slot) for slot in range(16) if bitmap >> slot & 1)
            actual = {(row["record"], row["slot"]) for row in result["cases"]}
            self.assertEqual(expected, actual)
            self.assertEqual(result["tested_slot_count"], count)
            self.assertTrue(result["passed_selected_checks"])
            self.assertTrue(result["all_occupied_slots_tested"])
            self.assertEqual(result["packed_search_control_count"], count * 4)
            self.assertEqual(got, [bytes(engine.uc.mem_read(address, 8))
                                   for address in (0x301CB0, 0x3017C8)])
            self.assertEqual(bytes(engine.uc.mem_read(self.probes.DATABASE, len(data))), data)
            for row in result["cases"]:
                with self.subTest(snapshot=snapshot.name, record=row["record"], slot=row["slot"]):
                    controls = {control["case"]: control for control in row["packed_search_controls"]}
                    self.assertEqual(set(controls), {"wrong_subtype", "wrong_payload",
                                                    "record_bitmap_unoccupied",
                                                    "slot_bitmap_unoccupied"})
                    for kind, control in controls.items():
                        self.assertTrue(control["passed"], (kind, control))
                        self.assertEqual(control["search_return_u32"],
                                         0 if kind == "slot_bitmap_unoccupied" else 0x401)
                    self.assertEqual(controls["wrong_payload"]["memcmp_calls"], 1)
                    self.assertEqual(controls["record_bitmap_unoccupied"]["memcmp_calls"], 0)
            engine.check_executable_sections(f"after_hash:{snapshot.name}")
            total += len(result["cases"])
        self.assertEqual(total, 33)

    def test_failed_search_probe_restores_input_database_and_got(self):
        engine = self.probes.RepairProbeEngine(FIRMWARE)
        data = (SNAPSHOTS[0] / "PRIVATE/DATABASE/DATABASE.BIN").read_bytes()
        engine.load(data)
        got = [bytes(engine.uc.mem_read(address, 8)) for address in (0x301CB0, 0x3017C8)]
        original_invoke = self.probes.invoke
        calls = 0

        def fail_record_bitmap_control(current_engine, address, values):
            nonlocal calls
            if address == 0x28E3C0:
                calls += 1
                if calls == 5:
                    raise RuntimeError("injected search failure")
            return original_invoke(current_engine, address, values)

        with patch.object(self.probes, "invoke", side_effect=fail_record_bitmap_control):
            with self.assertRaisesRegex(RuntimeError, "injected"):
                self.probes.array_hash_handle_cases(engine, data)
        self.assertEqual(bytes(engine.uc.mem_read(self.probes.DATABASE, len(data))), data)
        self.assertEqual(got, [bytes(engine.uc.mem_read(address, 8))
                               for address in (0x301CB0, 0x3017C8)])
        engine.check_executable_sections("after_injected_failure")


if __name__ == "__main__":
    unittest.main()
