"""Purpose: regress original sidb leaf readers and snapshot-based controls.

Usage: python -m unittest discover -s tools/tests -p test_sidb_readers.py -v.
Design: compare identified original checksum/bitmap/path/binary/array routines
    with fixture expectations and targeted corruption/bitmap/slot mutations.
Scope: local firmware and saved snapshots; untouched code is checked, but
    passing selected reads is not proof of camera listing or playback.
"""
import hashlib
import importlib.util
import json
import struct
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

ROOT = Path(__file__).resolve().parents[2]
FIRMWARE = ROOT / "firmware/m4-v602/usr/lib/libmpr.so"
OBSERVATIONS = ROOT / "analysis/camera_observations_20261112.json"
SNAPSHOTS = {
    "snap_20261112T195043": "38a90dcfb1f2de1351611204dfc56668ed7a0ef0606d1c71edad452ce446dc67",
    "snap_20261112T213116": "c47f17a05758cac62656b15db0616a24fed57ac806d7eae8aa3846083b69b6e0",
}
DATABASE_PATH = Path("PRIVATE/DATABASE/DATABASE.BIN")
AVAILABLE = (FIRMWARE.is_file() and
             all(importlib.util.find_spec(name) is not None for name in ("unicorn", "elftools")))
SNAPSHOTS_AVAILABLE = (OBSERVATIONS.is_file() and
                       all((ROOT / "backup" / name / DATABASE_PATH).is_file()
                           for name in SNAPSHOTS))
CONTROL_RETURNS = {
    "array_checksum_corruption": 0x406,
    "array_bitmap_absent": 0x406,
    "wrong_array_subtype_argument": 0x406,
    # This selected reader copies the slot even when its occupied bit is clear.
    "array_requested_slot_bit_cleared": 0,
}


@unittest.skipUnless(AVAILABLE, "Requires the local M4 libmpr.so, Unicorn and pyelftools")
class SidbLeafTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        from emulate_sidb_readers import SidbReaders
        cls.engine = SidbReaders(FIRMWARE)

    def test_checksum_original_sum_including_tail_and_u64_wrap(self):
        from emulate_sidb_readers import DATABASE
        vectors = [
            (b"", 0),
            (b"\x01", 1),
            (bytes.fromhex("01020304050607"), 0x0007060504030201),
            (bytes.fromhex("0102030405060708"), 0x0807060504030201),
            (bytes.fromhex("010203040506070809"), 0x080706050403020A),
            (b"\xff" * 16, 0xFFFFFFFFFFFFFFFE),
        ]
        for data, expected in vectors:
            with self.subTest(data=data.hex()):
                self.engine.load(data)
                result = self.engine.call("checksum", [DATABASE, len(data)])
                self.assertEqual(result["return_u64"], expected)
                self.assertEqual(result["boundaries"], [])
                self.assertTrue(result["original_guest_writes_confined_to_stack_and_output"])

    def test_bitmap_requested_bits_across_byte_boundaries(self):
        from emulate_sidb_readers import DATABASE
        data = bytearray(0x10000)
        struct.pack_into("<I", data, 0x44, 128)
        for index in (0, 7, 8, 63, 72, 127):
            with self.subTest(index=index):
                offset, mask = 0x4000 + index // 8, 1 << (index % 8)
                data[offset] |= mask
                self.engine.load(data)
                self.assertEqual(self.engine.call("bitmap", [DATABASE, index])["return_u64"], 1)
                data[offset] &= ~mask
                self.engine.load(data)
                self.assertEqual(self.engine.call("bitmap", [DATABASE, index])["return_u64"], 0)

    def test_selected_original_code_is_not_patched(self):
        from elftools.elf.elffile import ELFFile
        from emulate_sidb_readers import EXPECTED, FUNCTIONS
        self.assertEqual(hashlib.sha256(FIRMWARE.read_bytes()).hexdigest(), EXPECTED)
        self.assertEqual({start for start, end in self.engine.ranges}, set(FUNCTIONS.values()))
        with FIRMWARE.open("rb") as stream:
            elf = ELFFile(stream)
            for start, end in self.engine.ranges:
                with self.subTest(start=hex(start)):
                    offset = next(elf.address_offsets(start, end - start))
                    stream.seek(offset)
                    self.assertEqual(bytes(self.engine.uc.mem_read(start, end - start)),
                                     stream.read(end - start))


@unittest.skipUnless(AVAILABLE and SNAPSHOTS_AVAILABLE,
                     "Requires local firmware/dependencies and both offline snapshots/observations")
class SidbSnapshotTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        from emulate_sidb_readers import SidbReaders, snapshot_report

        class TracedReaders(SidbReaders):
            def call(self, name, values, output_size=0):
                if name == "array":
                    _, subtype, reference, slot, *_ = values
                    offset = 0x10000 + reference * 160
                    self.array_inputs.append({
                        "reference": reference, "slot": slot, "subtype": subtype,
                        "record": self.data[offset:offset + 160],
                        "bitmap_byte": self.data[0x4000 + reference // 8],
                    })
                return super().call(name, values, output_size)

        cls.engine = TracedReaders(FIRMWARE)
        cls.observations = json.loads(OBSERVATIONS.read_text(encoding="utf-8"))
        cls.cases = []
        for name in SNAPSHOTS:
            snapshot = ROOT / "backup" / name
            data = (snapshot / DATABASE_PATH).read_bytes()
            cls.engine.array_inputs = []
            report = snapshot_report(cls.engine, snapshot, cls.observations)
            controls = report["negative_controls"]
            traces = cls.engine.array_inputs[-len(controls):] if controls else []
            cls.cases.append((snapshot, data, report, traces))

    def test_fixture_hashes_and_original_header_checksum_booleans(self):
        for snapshot, data, report, _ in self.cases:
            with self.subTest(snapshot=snapshot.name):
                self.assertEqual(hashlib.sha256(data).hexdigest(), SNAPSHOTS[snapshot.name])
                self.assertEqual(report["database_sha256"], SNAPSHOTS[snapshot.name])
                self.assertEqual(len(report["header_regions"]), 19)
                for region in report["header_regions"]:
                    self.assertIs(region["original_function_matches_stored"], True, region)
                    self.assertIs(region["valid"], True, region)
                    self.assertEqual(region["original_function_computed_modulus"],
                                     region["computed"])
                    self.assertEqual(region["original_function_computed_modulus"], region["stored"])

    def test_bad_stored_header_checksum_reports_false(self):
        from emulate_sidb_readers import snapshot_report
        _, source, _, _ = self.cases[0]
        data = bytearray(source)
        data[0x3FFC] ^= 1
        with tempfile.TemporaryDirectory(prefix="sidb-readers-", dir=ROOT / "analysis") as tmp:
            snapshot = Path(tmp)
            database = snapshot / DATABASE_PATH
            database.parent.mkdir(parents=True)
            database.write_bytes(data)
            report = snapshot_report(self.engine, snapshot, self.observations)
        self.assertIs(report["header_regions"][0]["original_function_matches_stored"], False)
        self.assertIs(report["header_regions"][0]["valid"], False)
        self.assertTrue(all(region["original_function_matches_stored"] is True
                            for region in report["header_regions"][1:]))

    def test_all_observed_positive_and_negative_clip_helpers_return_success(self):
        expected_paths = {
            31: "A:/PRIVATE/M4ROOT/CLIP/C****.MP4",
            30: "A:/PRIVATE/M4ROOT/CLIP/C****M01.XML",
            29: "A:/PRIVATE/M4ROOT/THMBNL/C****T01.JPG",
            52: "A:/PRIVATE/M4ROOT/SUB/C****S03.MP4",
        }
        for snapshot, data, report, _ in self.cases:
            seen = {"listed": set(), "not_listed": set(), "unknown_in_this_round": set()}
            for movie in report["movies"]:
                with self.subTest(snapshot=snapshot.name, clip=movie["clip"],
                                  observed=movie["observed_listing"]):
                    seen[movie["observed_listing"]].add(movie["clip"])
                    self.assertIs(movie["record_checksum_host_check"], True)
                    readers = movie["path_readers"] + [movie["array_reader"], movie["binary_reader"]]
                    for reader in readers:
                        if not reader["reference"]:
                            self.assertEqual(reader["reader"], "not_called_optional_reference")
                            self.assertNotIn("return_u64", reader)
                            continue
                        self.assertEqual(reader["return_u64"], 0, reader)
                        self.assertIs(reader["original_guest_writes_confined_to_stack_and_output"],
                                      True)
                    for reader in movie["path_readers"]:
                        if reader["reference"]:
                            self.assertEqual(reader["path_template"],
                                             expected_paths[reader["reference"]])
                    array = movie["array_reader"]
                    if array["reference"]:
                        offset = 0x10000 + 160 * array["reference"] + 12 + 32 * array["slot"]
                        self.assertEqual(array["output_hex"], data[offset:offset + 32].hex())
                    binary = movie["binary_reader"]
                    if binary["reference"]:
                        offset = 0x10000 + 160 * binary["reference"]
                        self.assertEqual(struct.unpack_from("<H", data, offset + 8)[0] >> 1, 40)
                        self.assertEqual(binary["output_hex"], data[offset + 10:offset + 50].hex())
            clips = {movie["clip"] for movie in report["movies"]}
            self.assertEqual(seen["listed"], clips & set(
                self.observations["current_listing_positive_examples_not_exhaustive"]))
            self.assertEqual(seen["not_listed"], clips & set(
                self.observations["current_listing_negative_confirmed"]))
            self.assertTrue(seen["listed"])
            self.assertTrue(seen["not_listed"])
            self.assertEqual(report["selected_reader_failures"], [])
            self.assertIs(report["root_cause_established"], False)
        latest = {movie["clip"] for movie in self.cases[-1][2]["movies"]}
        self.assertTrue(set(self.observations["current_listing_positive_examples_not_exhaustive"])
                        <= latest)
        self.assertTrue(set(self.observations["current_listing_negative_confirmed"]) <= latest)

    def test_controls_cover_every_referenced_array_slot_including_63_and_72(self):
        for snapshot, _, report, _ in self.cases:
            with self.subTest(snapshot=snapshot.name):
                pairs = {(movie["array_reader"]["reference"], movie["array_reader"]["slot"])
                         for movie in report["movies"] if movie["array_reader"]["reference"]}
                self.assertTrue({63, 72} <= {reference for reference, slot in pairs})
                expected = {(reference, slot, case) for reference, slot in pairs
                            for case in CONTROL_RETURNS}
                controls = report["negative_controls"]
                self.assertEqual(len(controls), len(expected))
                self.assertEqual({(row["reference"], row["slot"], row["case"]) for row in controls},
                                 expected)
                for row in controls:
                    self.assertEqual(row["expected"], CONTROL_RETURNS[row["case"]])
                    self.assertEqual(row["return_u64"], CONTROL_RETURNS[row["case"]])

    def test_controls_mutate_only_requested_record_bitmap_or_slot(self):
        from emulate_sidb_readers import DATABASE
        from sony_db import checksum
        for snapshot, data, report, traces in self.cases:
            self.assertEqual(len(traces), len(report["negative_controls"]))
            for control, trace in zip(report["negative_controls"], traces):
                reference, slot, case = control["reference"], control["slot"], control["case"]
                with self.subTest(snapshot=snapshot.name, reference=reference, slot=slot, case=case):
                    self.assertEqual((trace["reference"], trace["slot"]), (reference, slot))
                    subtype = 1 if case == "wrong_array_subtype_argument" else 2
                    self.assertEqual(control["subtype_argument"], subtype)
                    self.assertEqual(trace["subtype"], subtype)
                    offset = 0x10000 + reference * 160
                    expected_record = bytearray(data[offset:offset + 160])
                    bitmap = data[0x4000 + reference // 8]
                    if case == "array_checksum_corruption":
                        expected_record[158] ^= 1
                    elif case == "array_bitmap_absent":
                        bitmap &= ~(1 << (reference % 8))
                    elif case == "array_requested_slot_bit_cleared":
                        occupied = struct.unpack_from("<H", expected_record, 6)[0]
                        self.assertTrue(occupied & (1 << slot))
                        struct.pack_into("<H", expected_record, 6, occupied & ~(1 << slot))
                        struct.pack_into("<H", expected_record, 158,
                                         checksum(bytes(expected_record[:158]), 0xFFF1))
                    self.assertEqual(trace["record"], expected_record)
                    self.assertEqual(trace["bitmap_byte"], bitmap)
                    self.engine.load(trace["record"])
                    computed = self.engine.call("checksum", [DATABASE, 158])["return_u64"] % 0xFFF1
                    stored = struct.unpack_from("<H", trace["record"], 158)[0]
                    self.assertEqual(computed == stored, case != "array_checksum_corruption")
                    self.assertIs(control["original_guest_writes_confined_to_stack_and_output"],
                                  True)
                    copies = [boundary for boundary in control["boundaries"]
                              if boundary["kind"] == "modeled_libc"]
                    if case == "array_requested_slot_bit_cleared":
                        self.assertEqual(control["output_hex"],
                                         expected_record[12 + slot * 32:44 + slot * 32].hex())
                        self.assertEqual(copies, [{"kind": "modeled_libc", "symbol": "memcpy",
                                                  "length": 32}])
                    else:
                        self.assertEqual(control["output_hex"], bytes(32).hex())
                        self.assertEqual(copies, [])

    def test_path_and_binary_reject_bad_checksum_and_inactive_bitmap(self):
        from emulate_sidb_readers import DATABASE, SCRATCH
        for snapshot, source, _, _ in self.cases:
            for name, reference, values, size in (
                    ("path", 31, [DATABASE, ord("A"), 31, SCRATCH, 0x106], 0x106),
                    ("binary", 81, [DATABASE, 81, SCRATCH, 0x1000, SCRATCH + 0x1800], 40)):
                for case in ("bad_checksum", "inactive_bitmap"):
                    with self.subTest(snapshot=snapshot.name, reader=name, case=case):
                        data = bytearray(source)
                        if case == "bad_checksum":
                            data[0x10000 + reference * 160 + 158] ^= 1
                        else:
                            data[0x4000 + reference // 8] &= ~(1 << (reference % 8))
                        self.engine.load(data)
                        if case == "inactive_bitmap":
                            self.assertEqual(self.engine.call("bitmap", [DATABASE, reference])[
                                "return_u64"], 0)
                        result = self.engine.call(name, values, size)
                        self.assertEqual(result["return_u64"], 0x406)
                        self.assertFalse(any(boundary["kind"] == "modeled_libc"
                                             for boundary in result["boundaries"]))

    def test_report_leaves_original_snapshot_loaded(self):
        from emulate_sidb_readers import snapshot_report
        for snapshot, data, _, _ in self.cases:
            snapshot_report(self.engine, snapshot, self.observations)
            self.assertEqual(self.engine.data, data)
            self.assertEqual((snapshot / DATABASE_PATH).read_bytes(), data)


if __name__ == "__main__":
    unittest.main()
