"""Purpose: test selected original sidb repair fields and array-hash behavior.

Usage: python tools/emulate_sd_repair_fields.py --snapshot BEFORE
    --snapshot AFTER --output REPORT.json [--assembly-dir LOCAL_DIRECTORY].
Design: export full ELF-symbol assembly and run flag fragments, photo readers
    and hash/register/search controls with explicit cache/GOT/libc models.
Scope: identified M4 firmware and saved SD snapshots only. No card access,
    complete Load/Create/repair execution, live cache capture or playback claim.
"""
import argparse
import hashlib
import io
import json
import struct
from pathlib import Path

import capstone
from elftools.elf.elffile import ELFFile
import unicorn
from unicorn import arm64_const as regs
from emulate_sidb_converter import RecordConverter
from emulate_sidb_readers import EXPECTED, SCRATCH, STACK, DATABASE
from sony_db import checksum, inventory


EVIDENCE_SYMBOLS = {
    "Load": (0x2992C8, 0xB24),
    "regist": (0x28A6A4, 0xC8),
    "SearchArrayBinaryRecord": (0x28E3C0, 0x14C),
    "CreateArrayBinaryRecord": (0x29267C, 0x2D8),
    "binary_hash": (0x28A810, 0x94),
}


def export_symbol_assembly(firmware, destination):
    """Use ELF symbol sizes, never a decompiler's possibly incomplete body."""
    raw = Path(firmware).read_bytes()
    digest = hashlib.sha256(raw).hexdigest()
    if digest != EXPECTED:
        raise ValueError("Assembly evidence requires the identified libmpr.so")
    elf = ELFFile(io.BytesIO(raw))
    symbols = elf.get_section_by_name(".dynsym")
    decoder = capstone.Cs(capstone.CS_ARCH_ARM64, capstone.CS_MODE_LITTLE_ENDIAN)
    destination.mkdir(parents=True, exist_ok=True)
    exports = []
    for label, (start, size) in EVIDENCE_SYMBOLS.items():
        matches = [symbol for symbol in symbols.iter_symbols()
                   if symbol["st_value"] == start and symbol["st_info"]["type"] == "STT_FUNC"]
        if len(matches) != 1 or matches[0]["st_size"] != size:
            raise ValueError(f"Unexpected ELF symbol range: {label}")
        symbol = matches[0]
        section = elf.get_section(symbol["st_shndx"])
        offset = start - section["sh_addr"]
        if not section["sh_flags"] & 4 or not 0 <= offset <= offset + size <= section["sh_size"]:
            raise ValueError(f"Symbol is not wholly in executable section: {label}")
        code = section.data()[offset:offset + size]
        instructions = list(decoder.disasm(code, start))
        if (len(instructions) * 4 != size or
                any(ins.address != start + index * 4 or ins.size != 4
                    for index, ins in enumerate(instructions))):
            raise ValueError(f"Incomplete Capstone decode: {label}")
        filename = f"elf-{start:08x}-{label}.capstone.asm.txt"
        lines = [
            f"// ELF SHA256: {digest}",
            f"// Symbol: {symbol.name}",
            f"// Range authority: .dynsym st_value/st_size; ELF VMAs, no Ghidra body",
            f"// Complete range: [{start:#x}, {start + size:#x}), size {size:#x}",
            f"// Section: {section.name}; symbol bytes SHA256: {hashlib.sha256(code).hexdigest()}",
            f"// Capstone: {capstone.__version__}; AArch64 little-endian; no skipdata",
        ]
        lines.extend(f"{ins.address:08x} {ins.bytes.hex()} {ins.mnemonic} {ins.op_str}".rstrip()
                     for ins in instructions)
        text = "\n".join(lines) + "\n"
        (destination / filename).write_text(text, encoding="utf-8", newline="\n")
        exports.append({
            "label": label, "symbol": symbol.name, "symbol_table": ".dynsym",
            "elf_vma": hex(start), "size": hex(size), "end_exclusive": hex(start + size),
            "section": section.name, "file_offset": hex(section["sh_offset"] + offset),
            "symbol_bytes_sha256": hashlib.sha256(code).hexdigest(),
            "instruction_count": len(instructions), "decoded_bytes": len(code),
            "complete_symbol_range": True, "assembly_file": filename,
            "assembly_sha256": hashlib.sha256(text.encode("utf-8")).hexdigest(),
        })
    manifest = {
        "firmware": str(firmware), "firmware_sha256": digest,
        "capstone_version": capstone.__version__, "exports": exports,
        "range_authority": "ELF .dynsym st_value/st_size, not Ghidra function bodies",
        "scope": "Static full-symbol evidence only; exporting Load/Create does not execute them",
    }
    manifest_path = destination / "array-hash-elf-symbols.capstone.json"
    manifest_path.write_text(json.dumps(manifest, indent=2), encoding="utf-8")
    return {"directory": str(destination), "manifest": str(manifest_path),
            "manifest_sha256": hashlib.sha256(manifest_path.read_bytes()).hexdigest(), **manifest}


class RepairProbeEngine(RecordConverter):
    def __init__(self, firmware):
        super().__init__(firmware)
        with Path(firmware).open("rb") as stream:
            elf = ELFFile(stream)
            self.code_sections = [
                (section.name, section["sh_addr"], section.data())
                for section in elf.iter_sections()
                if section["sh_flags"] & 4 and section["sh_type"] != "SHT_NOBITS"
            ]
        if not self.code_sections:
            raise ValueError("No executable ELF sections found")
        self.integrity_checks = []
        self.check_executable_sections("before_probes_after_loader_relocations")

    def check_executable_sections(self, checkpoint):
        sections = []
        for name, address, original in self.code_sections:
            current = bytes(self.uc.mem_read(address, len(original)))
            sections.append({
                "name": name, "elf_vma": hex(address), "size": len(original),
                "elf_sha256": hashlib.sha256(original).hexdigest(),
                "emulated_sha256": hashlib.sha256(current).hexdigest(),
                "unchanged": current == original,
            })
        result = {"checkpoint": checkpoint, "sections": sections,
                  "passed": all(row["unchanged"] for row in sections)}
        self.integrity_checks.append(result)
        if not result["passed"]:
            raise RuntimeError(f"Executable ELF section changed: {checkpoint}")
        return result

    def on_code(self, uc, address, size, user_data):
        if self.plt.get(address) == "memcmp":
            first, second, count = [uc.reg_read(getattr(regs, f"UC_ARM64_REG_X{i}")) for i in range(3)]
            if count > 4096:
                raise ValueError("Bounded memcmp model exceeded")
            a, b = bytes(uc.mem_read(first, count)), bytes(uc.mem_read(second, count))
            self.boundaries.append({"kind": "modeled_libc", "symbol": "memcmp", "length": count})
            uc.reg_write(regs.UC_ARM64_REG_X0, ((a > b) - (a < b)) & 0xFFFFFFFF)
            uc.reg_write(regs.UC_ARM64_REG_PC, uc.reg_read(regs.UC_ARM64_REG_X30))
            return
        super().on_code(uc, address, size, user_data)


def invoke(engine, address, values):
    engine.uc.context_restore(engine.initial)
    for number, value in enumerate(values):
        engine.uc.reg_write(getattr(regs, f"UC_ARM64_REG_X{number}"), value)
    engine.uc.emu_start(address, 0x40000000, count=200000)
    if engine.uc.reg_read(regs.UC_ARM64_REG_PC) != 0x40000000:
        raise RuntimeError("Original hash helper did not return")
    return engine.uc.reg_read(regs.UC_ARM64_REG_X0) & 0xFFFFFFFF


def array_hash_handle_cases(engine, data):
    """Model only cache storage; run original hash, registration and search code."""
    table, bucket_list, db_slots = STACK + 0x1000, STACK + 0x4000, STACK + 0x5000
    data_ptr, out_ref, out_slot = SCRATCH + 0x1000, SCRATCH + 0x1800, SCRATCH + 0x1804
    binary_hash = next(value for name, value in engine.definitions.items()
                       if "sidbhash11binary_hash" in name)
    hash_got, db_got = 0x301CB0, 0x3017C8
    original_pointers = [bytes(engine.uc.mem_read(address, 8)) for address in (hash_got, db_got)]
    cases = []
    expected_slots = set()

    def register_and_search(handle, query, query_subtype, bucket_hash):
        engine.uc.mem_write(data_ptr, query)
        engine.uc.mem_write(table, bytes(0x1FE8))
        engine.uc.mem_write(table + bucket_hash * 8, struct.pack("<Q", bucket_list))
        engine.uc.mem_write(bucket_list, b"\xff" * 256)
        registered = invoke(engine, 0x28A6A4, [table, bucket_hash, handle])
        stored = struct.unpack("<I", engine.uc.mem_read(bucket_list, 4))[0]
        engine.uc.mem_write(out_ref, b"\xff" * 8)
        before = len(engine.boundaries)
        found = invoke(engine, 0x28E3C0,
                       [0, query_subtype, data_ptr, len(query), out_ref, out_slot])
        reference, selected_slot = struct.unpack("<II", engine.uc.mem_read(out_ref, 8))
        return {"supplied_handle": handle, "registered_return_u32": registered,
                "stored_handle": stored, "search_return_u32": found,
                "found_record": reference, "found_slot": selected_slot,
                "memcmp_calls": sum(row.get("symbol") == "memcmp"
                                    for row in engine.boundaries[before:])}

    try:
        engine.uc.mem_write(hash_got, struct.pack("<Q", table))
        engine.uc.mem_write(db_got, struct.pack("<Q", db_slots))
        engine.uc.mem_write(db_slots, struct.pack("<Q", DATABASE))
        for row in inventory(data):
            raw = bytes.fromhex(row["hex"])
            if row["type"] != 3:
                continue
            subtype, length = raw[4], raw[5]
            if not length:
                raise ValueError("Zero-length array entry")
            bitmap = struct.unpack_from("<H", raw, 6)[0]
            for slot in range(16):
                if not (bitmap >> slot & 1):
                    continue
                expected_slots.add((row["index"], slot))
                payload = raw[12 + slot * length:12 + (slot + 1) * length]
                if len(payload) != length or 12 + (slot + 1) * length > 158:
                    raise ValueError("Array slot exceeds record")
                engine.uc.mem_write(data_ptr, payload)
                hash_value = invoke(engine, binary_hash, [data_ptr, length])
                if not 0 <= hash_value < 0x3FD:
                    raise RuntimeError("Original binary hash exceeds table")
                # Execute the actual Load argument construction, stopping before regist's BL.
                engine.uc.context_restore(engine.initial)
                frame = STACK + 0x8000
                engine.uc.mem_write(frame + 0x80, struct.pack("<Q", table))
                engine.uc.reg_write(regs.UC_ARM64_REG_X29, frame)
                engine.uc.reg_write(regs.UC_ARM64_REG_X0, hash_value)
                engine.uc.reg_write(regs.UC_ARM64_REG_X23, row["index"])
                engine.uc.reg_write(regs.UC_ARM64_REG_X5, slot)
                engine.uc.emu_start(0x299D2C, 0x299D38, count=4)
                if engine.uc.reg_read(regs.UC_ARM64_REG_PC) != 0x299D38:
                    raise RuntimeError("Load argument fragment did not reach its bounded end")
                loaded_handle = engine.uc.reg_read(regs.UC_ARM64_REG_X2) & 0xFFFFFFFF
                if engine.uc.reg_read(regs.UC_ARM64_REG_X0) != table:
                    raise RuntimeError("Load fragment selected the wrong hash table")
                values = []
                for mode, handle in (("load_argument", loaded_handle),
                                     ("create_packed_form", row["index"] << 15 | slot)):
                    values.append({"mode": mode, **register_and_search(
                        handle, payload, subtype, hash_value)})
                plain, packed = values
                controls = []
                for kind in ("wrong_subtype", "wrong_payload", "record_bitmap_unoccupied",
                             "slot_bitmap_unoccupied"):
                    query, query_subtype, query_hash = payload, subtype, hash_value
                    changed = bytearray(data)
                    if kind == "wrong_subtype":
                        query_subtype ^= 1
                    elif kind == "wrong_payload":
                        query = bytes([payload[0] ^ 1]) + payload[1:]
                        engine.uc.mem_write(data_ptr, query)
                        query_hash = invoke(engine, binary_hash, [data_ptr, length])
                        if not 0 <= query_hash < 0x3FD:
                            raise RuntimeError("Control hash exceeds table")
                    elif kind == "record_bitmap_unoccupied":
                        changed[0x4000 + row["index"] // 8] &= ~(1 << (row["index"] % 8))
                    else:
                        offset = 0x10000 + 160 * row["index"]
                        struct.pack_into("<H", changed, offset + 6, bitmap & ~(1 << slot))
                        struct.pack_into("<H", changed, offset + 158,
                                         checksum(bytes(changed[offset:offset + 158]), 0xFFF1))
                    engine.load(changed)
                    result = register_and_search(
                        row["index"] << 15 | slot, query, query_subtype, query_hash)
                    # Search checks the record bitmap, but not the per-record slot bitmap.
                    expected = 0 if kind == "slot_bitmap_unoccupied" else 0x401
                    outputs = ((row["index"], slot) if expected == 0 else
                               (0xFFFFFFFF, 0xFFFFFFFF))
                    passed = (
                        result["registered_return_u32"] == 0 and
                        result["stored_handle"] == result["supplied_handle"] and
                        result["search_return_u32"] == expected and
                        (result["found_record"], result["found_slot"]) == outputs and
                        result["memcmp_calls"] == int(kind in {
                            "wrong_payload", "slot_bitmap_unoccupied"}))
                    controls.append({
                        "case": kind, "query_subtype": query_subtype,
                        "query_payload_hex": query.hex(), "query_hash": query_hash,
                        "expected_search_return_u32": expected, "passed": passed, **result,
                        "cache_model": "Single candidate registered at the query's original binary_hash; "
                                       "wrong_payload forces a candidate collision to reach memcmp",
                    })
                    engine.load(data)
                cases.append({
                    "record": row["index"], "slot": slot, "subtype": subtype, "entry_length": length,
                    "hash_value": hash_value, "runs": values, "packed_search_controls": controls,
                    "passed_selected_checks": (
                        loaded_handle == row["index"] and
                        all(value["registered_return_u32"] == 0 and
                            value["supplied_handle"] == value["stored_handle"] for value in values) and
                        plain["search_return_u32"] != 0 and packed["search_return_u32"] == 0 and
                        (packed["found_record"], packed["found_slot"]) == (row["index"], slot) and
                        all(control["passed"] for control in controls)),
                })
    finally:
        engine.load(data)
        for address, value in zip((hash_got, db_got), original_pointers):
            engine.uc.mem_write(address, value)
    covered = {(row["record"], row["slot"]) for row in cases}
    unchanged = bytes(engine.uc.mem_read(DATABASE, len(data))) == data
    got_restored = all(bytes(engine.uc.mem_read(address, 8)) == value
                       for address, value in zip((hash_got, db_got), original_pointers))
    return {
        "cases": cases, "occupied_slot_count": len(expected_slots),
        "tested_slot_count": len(cases), "all_occupied_slots_tested": covered == expected_slots,
        "packed_search_control_count": sum(len(row["packed_search_controls"]) for row in cases),
        "database_unchanged_in_emulator": unchanged, "modeled_got_pointers_restored": got_restored,
        "passed_selected_checks": (bool(cases) and covered == expected_slots and
                                   len(cases) == len(covered) and unchanged and got_restored and
                                   all(row["passed_selected_checks"] for row in cases)),
        "original_entrypoints_elf_vmas": {"load_argument_fragment": "0x299d2c..0x299d38",
                                         "registration": "0x28a6a4", "search": "0x28e3c0",
                                         "binary_hash": hex(binary_hash)},
        "scope": "Modeled preallocated cache/global pointers; original argument/hash/regist/search code. Not full Load, a live cache capture or camera behavior.",
    }


def original_flag_cases(engine):
    cases = []
    for initial in range(256):
        for done, pending in ((0, 0), (0, 1), (1, 0), (1, 1)):
            engine.uc.context_restore(engine.initial)
            engine.uc.mem_write(SCRATCH, bytes(0x2000))
            engine.uc.mem_write(SCRATCH + 0x619, bytes([done, pending]))
            engine.uc.reg_write(regs.UC_ARM64_REG_X19, SCRATCH + 0x1000)
            engine.uc.reg_write(regs.UC_ARM64_REG_X20, SCRATCH)
            engine.uc.reg_write(regs.UC_ARM64_REG_X0, initial)
            engine.uc.emu_start(0x292B78, 0x292B90, count=10)
            if engine.uc.reg_read(regs.UC_ARM64_REG_PC) != 0x292B90:
                raise RuntimeError("Flag fragment did not reach its bounded end")
            actual = bytes(engine.uc.mem_read(SCRATCH + 0x1006, 1))[0]
            expected = (initial & ~12) | done << 2 | pending << 3
            cases.append({"initial_raw_byte06": initial, "record_info_619": done,
                          "record_info_61a": pending, "actual": actual,
                          "passed": actual == expected})
    engine.ranges.append((0xB9340, 0xB95B0))
    assignments = []
    for done, pending in ((0, 0), (0, 1), (1, 0), (1, 1)):
        engine.uc.context_restore(engine.initial)
        frame = STACK + 0x8000
        engine.uc.mem_write(frame + 0x6E9, bytes([done, pending]))
        engine.uc.reg_write(regs.UC_ARM64_REG_X29, frame)
        engine.uc.emu_start(0xB9460, 0xB946C, count=4)
        actual = bytes(engine.uc.mem_read(frame + 0x6E9, 2))
        assignments.append({"before_619_61a": [done, pending],
                            "after_619_61a": list(actual), "passed": actual == b"\x01\x00"})
    return {
        "writer_fragment_elf_vmas": ["0x292b78", "0x292b90"],
        "repair_assignment_fragment_elf_vmas": ["0xb9460", "0xb946c"],
        "case_count": len(cases), "passed": all(row["passed"] for row in cases + assignments),
        "cases": cases, "repair_assignments": assignments,
        "scope": "Original flag fragments only, not full writer/repair, metadata parsing or hardware",
    }


def photo_conversions(engine, snapshot):
    data = (snapshot / "PRIVATE/DATABASE/DATABASE.BIN").read_bytes()
    engine.load(data)
    photos = []
    for row in inventory(data):
        if row.get("content_type") != 1:
            continue
        result = engine.convert(row["index"])
        output = bytes.fromhex(result["record_info_hex"])
        optional, unexpected = [], []
        for nested in result["original_reader_returns"]:
            if nested["return_u32"] == 0:
                continue
            is_optional = (
                "RestorateArrayBinaryRecord" in nested["symbol"] and
                int(nested["arguments"][2], 16) == 0 and nested["return_u32"] == 0x406)
            (optional if is_optional else unexpected).append(nested)
        photos.append({
            "record_index": row["index"], "result": result,
            "image_unique_id_hex_at_5f3": output[0x5F3:0x603].hex(),
            "flags_619_61a": list(output[0x619:0x61B]),
            "optional_zero_reference_errors": optional, "unexpected_reader_errors": unexpected,
        })
    unchanged = bytes(engine.uc.mem_read(DATABASE, len(data))) == data
    return {
        "snapshot": str(snapshot), "database_sha256": hashlib.sha256(data).hexdigest(),
        "photos": photos, "database_unchanged_in_emulator": unchanged,
        "passed": unchanged and bool(photos) and all(
            row["result"]["return_u32"] == 0 and not row["unexpected_reader_errors"] for row in photos),
    }


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--snapshot", action="append", required=True)
    ap.add_argument("--firmware", default="firmware/m4-v602/usr/lib/libmpr.so")
    ap.add_argument("--assembly-dir", default="analysis/repair-firmware-0027")
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    snapshots = [Path(value).resolve() for value in args.snapshot]
    firmware, output = Path(args.firmware).resolve(), Path(args.output).resolve()
    assembly_dir = Path(args.assembly_dir).resolve()
    if any(path.drive.upper() == "F:" for path in snapshots + [firmware, output, assembly_dir]):
        raise ValueError("Only saved snapshots and local output are permitted")
    if any(snapshot == target or snapshot in target.parents
           for snapshot in snapshots for target in (output, assembly_dir)):
        raise ValueError("Do not modify a source snapshot")
    for snapshot in snapshots:
        for relative in ("_snapshot.json", "PRIVATE/DATABASE/DATABASE.BIN"):
            path = (snapshot / relative).resolve()
            if path.drive.upper() == "F:" or snapshot not in path.parents or not path.is_file():
                raise ValueError("Only regular files inside saved local snapshots are permitted")
    assembly = export_symbol_assembly(firmware, assembly_dir)
    engine = RepairProbeEngine(firmware)
    flags = original_flag_cases(engine)
    engine.check_executable_sections("after_flag_and_assignment_fragments")
    cases = []
    for snapshot in snapshots:
        cases.append(photo_conversions(engine, snapshot))
        engine.check_executable_sections(f"after_photo_conversions:{snapshot.name}")
    hash_cases = []
    for snapshot in snapshots:
        data = (snapshot / "PRIVATE/DATABASE/DATABASE.BIN").read_bytes()
        engine.load(data)
        hash_cases.append({"snapshot": str(snapshot), "database_sha256": hashlib.sha256(data).hexdigest(),
                           **array_hash_handle_cases(engine, data)})
        engine.check_executable_sections(f"after_array_hash_probes:{snapshot.name}")
    engine.check_executable_sections("after_all_probes")
    report = {
        "firmware_sha256": EXPECTED, "flags": flags, "snapshots": cases,
        "array_hash_cases": hash_cases, "card_access": False,
        "assembly_evidence": assembly, "unicorn_version": unicorn.__version__,
        "original_executable_sections_unchanged": all(row["passed"] for row in engine.integrity_checks),
        "executable_section_integrity": {
            "checks": engine.integrity_checks,
            "policy": "All SHF_EXECINSTR sections must match ELF bytes before/after probes; "
                      "existing non-executable GOT/cache/stack/output models are allowed",
        },
        "passed": flags["passed"] and all(row["passed"] for row in cases) and
                  all(row["passed_selected_checks"] for row in hash_cases) and
                  all(row["passed"] for row in engine.integrity_checks),
        "scope": "Selected original flag/Load argument fragments, photo conversions and original "
                 "binary_hash/regist/search with modeled cache/GOT/libc only. Full Load/Create/"
                 "repair, live cache state, camera admission/listing/playback are not established.",
    }
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps({"passed": report["passed"], "flag_cases": flags["case_count"],
                      "photo_counts": [len(row["photos"]) for row in cases],
                      "array_slot_counts": [row["tested_slot_count"] for row in hash_cases],
                      "packed_search_controls": sum(row["packed_search_control_count"]
                                                    for row in hash_cases),
                      "executable_sections_unchanged":
                      report["original_executable_sections_unchanged"]}, indent=2))
    if not report["passed"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
