"""Purpose: execute original sidb checksum, bitmap and record-read helpers.

Usage: python tools/emulate_sidb_readers.py --snapshot SNAP --output REPORT
    --observations OBSERVATIONS [--snapshot OTHER --firmware LIBMPR].
Design: load identified AArch64 ELF code into Unicorn and exercise bounded
    original readers plus negative controls, modeling memcpy/strncpy.
Scope: offline saved databases, not filesystem/card mounting, full library
    initialization, camera UI or proof of camera admission.
"""
import argparse
import hashlib
import json
import struct
from pathlib import Path

import unicorn
from elftools.elf.elffile import ELFFile
from unicorn import Uc, UC_ARCH_ARM64, UC_MODE_ARM, UC_HOOK_CODE, UC_HOOK_MEM_WRITE
from unicorn import arm64_const as regs

from sony_db import check_regions, checksum, inventory

EXPECTED = "1a7a8007828810f948eb4fb95b9a269176355553a69977f6d8f2ae59516f5532"
DATABASE = 0x10000000
SCRATCH = 0x20000000
STACK = 0x30000000
RETURN = 0x40000000
FUNCTIONS = {"bitmap": 0x28a8a4, "checksum": 0x28b45c, "path": 0x28dcdc,
             "binary": 0x28e298, "array": 0x28e5ac}
ARGUMENTS = [getattr(regs, f"UC_ARM64_REG_X{i}") for i in range(8)]


class SidbReaders:
    def __init__(self, firmware):
        raw = Path(firmware).read_bytes()
        if hashlib.sha256(raw).hexdigest() != EXPECTED:
            raise ValueError("Only the identified M4 6.02 libmpr.so is supported")
        self.uc = Uc(UC_ARCH_ARM64, UC_MODE_ARM)
        self.plt, self.definitions, self.ranges = {}, {}, []
        with Path(firmware).open("rb") as stream:
            elf = ELFFile(stream)
            if elf["e_machine"] != "EM_AARCH64" or not elf.little_endian:
                raise ValueError("Expected little-endian AArch64")
            pages = set()
            segments = [seg for seg in elf.iter_segments() if seg["p_type"] == "PT_LOAD"]
            for seg in segments:
                pages.update(range(seg["p_vaddr"] & ~4095,
                                   (seg["p_vaddr"] + seg["p_memsz"] + 4095) & ~4095, 4096))
            for page in sorted(pages):
                self.uc.mem_map(page, 4096)
            for seg in segments:
                self.uc.mem_write(seg["p_vaddr"], seg.data())
            symbols = elf.get_section_by_name(".dynsym")
            for symbol in symbols.iter_symbols():
                if symbol["st_value"]:
                    self.definitions[symbol.name] = symbol["st_value"]
                if symbol["st_value"] in FUNCTIONS.values():
                    self.ranges.append((symbol["st_value"], symbol["st_value"] + symbol["st_size"]))
            if len({start for start, end in self.ranges}) != len(FUNCTIONS):
                raise ValueError("Reader function sizes not found")
            plt = elf.get_section_by_name(".plt")
            relocation = elf.get_section_by_name(".rela.plt")
            for index, entry in enumerate(relocation.iter_relocations()):
                self.plt[plt["sh_addr"] + 32 + 16 * index] = symbols.get_symbol(entry["r_info_sym"]).name
        self.uc.mem_map(DATABASE, 0xA00000)
        self.uc.mem_map(SCRATCH, 0x2000)
        self.uc.mem_map(STACK, 0x10000)
        self.uc.mem_map(RETURN, 4096)
        self.uc.reg_write(regs.UC_ARM64_REG_SP, STACK + 0xF000)
        self.uc.reg_write(regs.UC_ARM64_REG_X30, RETURN)
        self.initial = self.uc.context_save()
        self.uc.hook_add(UC_HOOK_CODE, self.on_code)
        self.uc.hook_add(UC_HOOK_MEM_WRITE, self.on_write)
        self.boundaries, self.tail, self.writes = [], [], []
        self.data = b""

    def on_write(self, uc, access, address, size, value, user_data):
        if not (SCRATCH <= address and address + size <= SCRATCH + 0x2000 or
                STACK <= address and address + size <= STACK + 0x10000):
            raise RuntimeError(f"Unexpected guest write: {address:x}, size {size}")
        self.writes.append((address, size))

    def on_code(self, uc, address, size, user_data):
        self.tail = (self.tail + [hex(address)])[-20:]
        name = self.plt.get(address)
        if name:
            target = self.definitions.get(name)
            if target in FUNCTIONS.values():
                self.boundaries.append({"kind": "original_internal_plt", "symbol": name,
                                        "target": hex(target)})
                uc.reg_write(regs.UC_ARM64_REG_PC, target)
                return
            if name not in {"memcpy", "strncpy"}:
                raise RuntimeError(f"Unmodeled PLT dependency {name} at {address:x}")
            destination, source, count = [uc.reg_read(r) for r in ARGUMENTS[:3]]
            if not (SCRATCH <= destination and destination + count <= SCRATCH + 0x2000 and
                    DATABASE <= source and source + count <= DATABASE + len(self.data)):
                raise RuntimeError("Libc boundary outside input/output memory")
            value = bytes(uc.mem_read(source, count))
            if name == "strncpy" and b"\0" in value:
                value = value.split(b"\0", 1)[0].ljust(count, b"\0")
            uc.mem_write(destination, value)
            self.boundaries.append({"kind": "modeled_libc", "symbol": name, "length": count})
            uc.reg_write(regs.UC_ARM64_REG_X0, destination)
            uc.reg_write(regs.UC_ARM64_REG_PC, uc.reg_read(regs.UC_ARM64_REG_X30))
            return
        if not any(first <= address < end for first, end in self.ranges):
            raise RuntimeError(f"Execution left selected original readers: {address:x}, tail {self.tail}")

    def load(self, data):
        if len(data) > 0xA00000:
            raise ValueError("Snapshot exceeds mapped database allocation")
        self.data = bytes(data)
        self.uc.mem_write(DATABASE, self.data)

    def call(self, name, values, output_size=0):
        self.uc.context_restore(self.initial)
        self.uc.mem_write(SCRATCH, bytes(0x2000))
        self.boundaries, self.tail, self.writes = [], [], []
        for reg, value in zip(ARGUMENTS, values):
            self.uc.reg_write(reg, value & 0xFFFFFFFFFFFFFFFF)
        self.uc.emu_start(FUNCTIONS[name], RETURN, count=200000)
        if self.uc.reg_read(regs.UC_ARM64_REG_PC) != RETURN:
            raise RuntimeError(f"Reader did not return: {name}, tail {self.tail}")
        return {"return_u64": self.uc.reg_read(regs.UC_ARM64_REG_X0),
                "output_hex": bytes(self.uc.mem_read(SCRATCH, output_size)).hex(),
                "boundaries": self.boundaries,
                "original_guest_writes_confined_to_stack_and_output": True}

    def array(self, index, slot):
        return self.call("array", [DATABASE, 2, index, slot, SCRATCH, 32], 32)


def snapshot_report(engine, snapshot, observations):
    data = (snapshot / "PRIVATE/DATABASE/DATABASE.BIN").read_bytes()
    engine.load(data)
    records = inventory(data)
    positives = set(observations["current_listing_positive_examples_not_exhaustive"])
    negatives = set(observations["current_listing_negative_confirmed"])
    movies = []
    for row in records:
        if row.get("content_type") != 2:
            continue
        record = bytes.fromhex(row["hex"])
        clip = f"C{row['clip_number']:04d}"
        paths = []
        for column, short_id in enumerate(row["path_refs"]):
            index = short_id | ((record[0x5c] >> column & 1) << 16)
            if not index:
                paths.append({"reference": 0, "reader": "not_called_optional_reference"})
                continue
            value = engine.call("path", [DATABASE, ord("A"), index, SCRATCH, 0x106], 0x106)
            value["path_template"] = bytes.fromhex(value["output_hex"]).split(b"\0", 1)[0].decode("ascii")
            value.pop("output_hex")
            paths.append({"reference": index, **value})
        array_id = struct.unpack_from("<H", record, 0x5a)[0] | ((record[0x5c] >> 5 & 1) << 16)
        slot = record[0x5d] >> 4
        array = ({"reference": array_id, "slot": slot, **engine.array(array_id, slot)}
                 if array_id else {"reference": 0, "reader": "not_called_optional_reference"})
        video_id = row["video_info_ref"]
        binary = ({"reference": video_id,
                   **engine.call("binary", [DATABASE, video_id, SCRATCH, 0x1000, SCRATCH + 0x1800], 40)}
                  if video_id else {"reference": 0, "reader": "not_called_optional_reference"})
        movies.append({"clip": clip, "record_index": row["index"],
                       "observed_listing": ("listed" if clip in positives else
                                            "not_listed" if clip in negatives else "unknown_in_this_round"),
                       "record_checksum_host_check": row["checksum_valid"],
                       "path_readers": paths, "array_reader": array, "binary_reader": binary})
    regions = []
    for region in check_regions(data):
        value = engine.call("checksum", [DATABASE + int(region["start"], 16),
                                         int(region["length"], 16)])
        computed = value["return_u64"] % 0xFFFFFFFB
        regions.append({**region, "original_function_computed_modulus": computed,
                        "original_function_matches_stored": computed == region["stored"]})
    candidates = sorted({(row["array_reader"]["reference"], row["array_reader"]["slot"])
                         for row in movies if row["array_reader"]["reference"]})
    controls = []
    try:
        for array_id, slot in candidates:
            offset = 0x10000 + 160 * array_id
            for case, expected in (("array_checksum_corruption", 0x406),
                                   ("array_bitmap_absent", 0x406),
                                   ("wrong_array_subtype_argument", 0x406),
                                   ("array_requested_slot_bit_cleared", 0)):
                changed = bytearray(data)
                subtype = 2
                if case == "array_checksum_corruption":
                    changed[offset + 158] ^= 1
                elif case == "array_bitmap_absent":
                    changed[0x4000 + array_id // 8] &= ~(1 << (array_id % 8))
                elif case == "wrong_array_subtype_argument":
                    subtype = 1
                else:
                    occupied = struct.unpack_from("<H", changed, offset + 6)[0]
                    struct.pack_into("<H", changed, offset + 6, occupied & ~(1 << slot))
                    # Isolate the slot bit: this reader still copies it with a valid checksum.
                    struct.pack_into("<H", changed, offset + 158,
                                     checksum(bytes(changed[offset:offset + 158]), 0xFFF1))
                engine.load(changed)
                result = engine.call("array", [DATABASE, subtype, array_id, slot, SCRATCH, 32], 32)
                controls.append({"case": case, "reference": array_id, "slot": slot,
                                 "subtype_argument": subtype, "expected": expected, **result})
        if any(row["return_u64"] != row["expected"] for row in controls):
            raise RuntimeError("Original-reader negative control returned an unexpected status")
    finally:
        engine.load(data)
    failures = []
    for movie in movies:
        readers = movie["path_readers"] + [movie["array_reader"], movie["binary_reader"]]
        for reader in readers:
            if reader.get("return_u64", 0):
                failures.append({"clip": movie["clip"], "reader": reader})
    return {"snapshot": str(snapshot.resolve()), "database_sha256": hashlib.sha256(data).hexdigest(),
            "active_records": len(records), "movies": movies, "header_regions": regions,
            "selected_reader_failures": failures, "negative_controls": controls,
            "root_cause_established": False}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--firmware", default="firmware/m4-v602/usr/lib/libmpr.so")
    ap.add_argument("--snapshot", action="append", required=True)
    ap.add_argument("--observations", default="analysis/camera_observations_20261112.json")
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    engine = SidbReaders(args.firmware)
    observations = json.loads(Path(args.observations).read_text(encoding="utf-8"))
    report = {"firmware": str(Path(args.firmware).resolve()), "sha256": EXPECTED,
              "unicorn_version": unicorn.__version__, "function_elf_vmas": {
                  name: hex(value) for name, value in FUNCTIONS.items()},
              "ghidra_address_delta": "0x100000",
              "modeled_dependencies": ["memcpy", "strncpy"], "card_access": False,
              "full_library_or_camera_ui_emulated": False,
              "scope": "Original selected reader/checksum instructions only, not full mount/listing",
              "snapshots": [snapshot_report(engine, Path(value), observations) for value in args.snapshot]}
    output = Path(args.output).resolve()
    if output.drive.upper() == "F:":
        raise ValueError("Report must remain off the camera card")
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2), encoding="utf-8")
    for row in report["snapshots"]:
        print(row["snapshot"], "movies", len(row["movies"]), "reader failures",
              len(row["selected_reader_failures"]), "negative controls", len(row["negative_controls"]))


if __name__ == "__main__":
    main()
