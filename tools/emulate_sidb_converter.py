"""Purpose: execute the original sidb content-record conversion offline.

Usage: python tools/emulate_sidb_converter.py --snapshot SNAP --output REPORT
    --observations OBSERVATIONS [--snapshot OTHER --firmware LIBMPR].
Design: run original AArch64 conversion and nested readers against saved
    databases, with bounded libc models and dependency-corruption controls.
Scope: selected record conversion only. Does not run full Select, initialize all
    runtime flags, mount a card or establish listing/decoding/playback behavior.
"""
import argparse
import hashlib
import json
import struct
from pathlib import Path

from elftools.elf.elffile import ELFFile
import unicorn
from unicorn import arm64_const as regs

from emulate_sidb_readers import ARGUMENTS, DATABASE, EXPECTED, RETURN, SCRATCH, STACK, SidbReaders
from sony_db import inventory

CONVERTER = 0x28E754
OUTPUT_SIZE = 0x620


class RecordConverter(SidbReaders):
    def __init__(self, firmware):
        super().__init__(firmware)
        self.original_symbols = {}
        with Path(firmware).open("rb") as stream:
            elf = ELFFile(stream)
            for symbol in elf.get_section_by_name(".dynsym").iter_symbols():
                if symbol["st_size"] and (
                    symbol.name.startswith("_ZN4sidb") or symbol.name.startswith("_ZNK4sidb")
                ):
                    self.ranges.append((symbol["st_value"], symbol["st_value"] + symbol["st_size"]))
                    self.original_symbols[symbol["st_value"]] = symbol.name
            # Private path formatting and UMID/date helpers have no dynamic symbols.
            self.ranges.extend([(0x28DC00, 0x28F550), (0x2CC000, 0x2CE000)])
            for relocation in elf.get_section_by_name(".rela.dyn").iter_relocations():
                if relocation["r_info_type"] == 1027:  # R_AARCH64_RELATIVE, zero load bias
                    self.uc.mem_write(relocation["r_offset"],
                                      struct.pack("<Q", relocation["r_addend"]))
        self.visited = set()
        self.reader_pending, self.reader_returns = [], []

    @staticmethod
    def writable(address, size):
        return (0 <= size <= 0x10000 and
                (SCRATCH <= address <= address + size <= SCRATCH + 0x2000 or
                 STACK <= address <= address + size <= STACK + 0x10000))

    def write_output(self, address, data):
        if not self.writable(address, len(data)):
            raise RuntimeError(f"Modeled libc write outside stack/output: {address:#x}")
        self.uc.mem_write(address, data)

    def cstring(self, address, maximum=0x1000):
        if not address:
            raise RuntimeError("Unexpected NULL C string")
        value = bytearray()
        for index in range(maximum):
            byte = bytes(self.uc.mem_read(address + index, 1))
            if byte == b"\0":
                return bytes(value)
            value.extend(byte)
        return bytes(value)

    def on_code(self, uc, address, size, user_data):
        self.tail = (self.tail + [hex(address)])[-20:]
        self.visited.add(address)
        if self.reader_pending and self.reader_pending[-1]["return_vma"] == address:
            frame = self.reader_pending.pop()
            self.reader_returns.append({**frame, "return_vma": hex(address),
                                        "return_u32": uc.reg_read(regs.UC_ARM64_REG_X0) & 0xFFFFFFFF})
        name = self.plt.get(address)
        if name:
            target = self.definitions.get(name)
            if target and any(first <= target < end for first, end in self.ranges):
                self.boundaries.append({"kind": "original_internal_plt", "symbol": name,
                                        "target": hex(target)})
                if target in {0x28DCDC, 0x28E298, 0x28E5AC}:
                    self.reader_pending.append({
                        "symbol": name, "entry_vma": hex(target),
                        "return_vma": uc.reg_read(regs.UC_ARM64_REG_X30),
                        "arguments": [hex(uc.reg_read(reg)) for reg in ARGUMENTS[:6]]})
                uc.reg_write(regs.UC_ARM64_REG_PC, target)
                return
            values = [uc.reg_read(reg) for reg in ARGUMENTS]
            destination, source, count = values[:3]
            if name == "memset":
                self.write_output(destination, bytes([source & 255]) * count)
                result = destination
            elif name in {"memcpy", "memmove"}:
                self.write_output(destination, bytes(uc.mem_read(source, count)))
                result = destination
            elif name in {"strncpy", "stpncpy"}:
                value = self.cstring(source, count)
                self.write_output(destination, value.ljust(count, b"\0"))
                result = destination if name == "strncpy" else destination + len(value)
            elif name in {"strlen", "strnlen"}:
                result = len(self.cstring(destination, source if name == "strnlen" else 0x1000))
            elif name == "strstr":
                haystack, needle = self.cstring(destination), self.cstring(source)
                index = haystack.find(needle)
                result = 0 if index < 0 else destination + index
            elif name == "snprintf":
                fmt = self.cstring(count).decode("ascii")
                if fmt not in {"%04d", "%03d", "%04u", "%04u%02u", "%04u%02u%02u",
                               "%02u%02u%02u", "%c%03d"}:
                    raise RuntimeError(f"Unmodeled snprintf format: {fmt!r}")
                fields = fmt.count("%")
                args = tuple(values[3:3 + fields])
                text = (fmt.replace("u", "d") % args).encode("ascii")
                if source:
                    self.write_output(destination, text[:source - 1] + b"\0")
                result = len(text)
            else:
                raise RuntimeError(f"Unmodeled dependency {name}, tail {self.tail}")
            self.boundaries.append({"kind": "modeled_libc", "symbol": name})
            uc.reg_write(regs.UC_ARM64_REG_X0, result)
            uc.reg_write(regs.UC_ARM64_REG_PC, uc.reg_read(regs.UC_ARM64_REG_X30))
            return
        if not any(first <= address < end for first, end in self.ranges):
            raise RuntimeError(f"Execution outside allowed original functions: {address:#x}, {self.tail}")

    def convert(self, index):
        self.uc.context_restore(self.initial)
        self.uc.mem_write(SCRATCH, bytes(0x2000))
        self.uc.mem_write(STACK, bytes(0x10000))
        self.boundaries, self.tail, self.writes, self.visited = [], [], [], set()
        self.reader_pending, self.reader_returns = [], []
        for reg, value in zip(ARGUMENTS, [DATABASE, ord("A"), index,
                                         DATABASE + 0x10000 + 160 * index, SCRATCH]):
            self.uc.reg_write(reg, value)
        self.uc.emu_start(CONVERTER, RETURN, count=1000000)
        if self.uc.reg_read(regs.UC_ARM64_REG_PC) != RETURN:
            raise RuntimeError(f"Converter did not return, tail {self.tail}")
        output = bytes(self.uc.mem_read(SCRATCH, OUTPUT_SIZE))
        paths = {}
        for name, offset in [("main", 0xC1), ("nrt", 0x1C8), ("thumbnail", 0x2CF),
                             ("proxy", 0x3D6)]:
            paths[name] = output[offset:offset + 0x106].split(b"\0", 1)[0].decode("ascii")
        return {"return_u32": self.uc.reg_read(regs.UC_ARM64_REG_X0) & 0xFFFFFFFF,
                "record_info_hex": output.hex(),
                "record_info_content_type": struct.unpack_from("<I", output)[0],
                "record_info_unique_id_without_drive": hex(struct.unpack_from("<I", output, 4)[0]),
                "restored_paths": paths,
                "original_reader_returns": self.reader_returns,
                "original_instruction_addresses_executed": len(self.visited),
                "executed_original_entrypoints": [
                    {"vma": hex(value), "symbol": name}
                    for value, name in sorted(self.original_symbols.items()) if value in self.visited],
                "boundaries": self.boundaries,
                "original_guest_writes_confined_to_stack_and_output": True}


def dependency_controls(engine, data, movies):
    candidates = [row for row in movies if row.get("video_info_ref") and
                  struct.unpack_from("<H", bytes.fromhex(row["hex"]), 0x5A)[0]]
    if not candidates:
        return []
    movie = next((row for row in candidates if row["clip_number"] == 6503), candidates[0])
    raw = bytes.fromhex(movie["hex"])
    array = struct.unpack_from("<H", raw, 0x5A)[0] | ((raw[0x5C] >> 5 & 1) << 16)
    paths = [ref | ((raw[0x5C] >> column & 1) << 16)
             for column, ref in enumerate(movie["path_refs"]) if ref]
    results = []
    try:
        for kind, reference in [("path", ref) for ref in paths] + [
                ("video_info", movie["video_info_ref"]), ("umid_array", array)]:
            changed = bytearray(data)
            changed[0x10000 + reference * 160 + 158] ^= 1
            engine.load(changed)
            value = engine.convert(movie["index"])
            failures = [row for row in value["original_reader_returns"] if row["return_u32"]]
            expected = 0x406 if kind == "path" else 0
            if value["return_u32"] != expected or not failures:
                raise RuntimeError("Original converter status-propagation control changed")
            results.append({"case": "dependency_checksum_bit_flipped", "kind": kind,
                            "source_clip": f"C{movie['clip_number']:04d}",
                            "reference": reference, "converter_return_u32": value["return_u32"],
                            "nested_reader_failures": failures,
                            "main_path_after_control": value["restored_paths"]["main"],
                            "video_metadata_populated_after_control":
                            bool(bytes.fromhex(value["record_info_hex"])[0x26]),
                            "main_umid_hex_after_control":
                            value["record_info_hex"][0x4F8 * 2:0x518 * 2]})
    finally:
        engine.load(data)
    return results


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--firmware", default="firmware/m4-v602/usr/lib/libmpr.so")
    ap.add_argument("--snapshot", action="append", required=True)
    ap.add_argument("--observations", default="analysis/camera_observations_20261112_233331.json")
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    paths = [Path(value).resolve() for value in
             [args.firmware, args.observations, args.output] + args.snapshot]
    if any(path.drive.upper() == "F:" for path in paths):
        raise ValueError("Only offline inputs and local output are allowed")
    for name in args.snapshot:
        snapshot = Path(name).resolve()
        if not (snapshot / "_snapshot.json").is_file():
            raise ValueError("A saved card snapshot is required")
        if snapshot == paths[2] or snapshot in paths[2].parents:
            raise ValueError("Do not modify source snapshots")
    engine = RecordConverter(args.firmware)
    observations = json.loads(Path(args.observations).read_text(encoding="utf-8"))
    positives = set(observations["current_listing_positive_examples_not_exhaustive"])
    negatives = set(observations["current_listing_negative_confirmed"])
    snapshots = []
    for name in args.snapshot:
        snapshot = Path(name)
        data = (snapshot / "PRIVATE/DATABASE/DATABASE.BIN").read_bytes()
        engine.load(data)
        records = inventory(data)
        movies = []
        for row in records:
            if row.get("content_type") != 2:
                continue
            clip = f"C{row['clip_number']:04d}"
            try:
                result = engine.convert(row["index"])
            except Exception as error:
                result = {"emulation_error": str(error)}
            movies.append({"clip": clip, "record_index": row["index"],
                           "observed_listing": "listed" if clip in positives else
                           "not_listed" if clip in negatives else "unknown_in_this_round", **result})
        snapshots.append({"snapshot": str(snapshot.resolve()),
                          "database_sha256": hashlib.sha256(data).hexdigest(), "movies": movies,
                          "negative_dependency_controls": dependency_controls(
                              engine, data, [row for row in records if row.get("content_type") == 2])})
        print(name, "movies", len(movies), "errors",
              sum("emulation_error" in row for row in movies), "nonzero",
              sum(bool(row.get("return_u32")) for row in movies))
    output = Path(args.output).resolve()
    if output.drive.upper() == "F:":
        raise ValueError("Output must remain off the card")
    output.parent.mkdir(parents=True, exist_ok=True)
    report = {"firmware_sha256": EXPECTED, "entry_elf_vma": hex(CONVERTER),
              "unicorn_version": unicorn.__version__,
              "scope": "Original ConvRecordStructure2RecordInfo, not Select/mount/UI/decoder",
              "card_access": False, "runtime_flags_initialized_by_select": False,
              "libc_implementations_are_modeled": True,
              "root_cause_established": False, "snapshots": snapshots}
    output.write_text(json.dumps(report, indent=2), encoding="utf-8")
    if any("emulation_error" in row for snapshot in snapshots for row in snapshot["movies"]):
        raise SystemExit(1)


if __name__ == "__main__":
    main()
