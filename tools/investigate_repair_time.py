"""Purpose: trace experiment 0027's changed database-header time to content.

Usage: python tools/investigate_repair_time.py
    --output analysis/repair-header-time-0027.json.
Design: compare every saved content timestamp and XML date, test masked/full
    maxima and execute identified original date-packing helpers.
Scope: fixed local repair-pair corpus and designated report path; no live card,
    EXIF reread, complete repair trace or inference about actual camera-clock use.
"""
import argparse
import csv
import hashlib
import json
import struct
from collections import Counter
from datetime import datetime, timedelta, timezone
from pathlib import Path
from xml.etree import ElementTree as ET

from sd_catalog_evidence import header_time
from sony_db import check_regions, inventory

ROOT = Path(__file__).resolve().parents[1]
BEFORE = ROOT / "backup/snap_20261113T135135"
AFTER = ROOT / "backup/snap_20261113T135646"
OUTPUT = ROOT / "analysis/repair-header-time-0027.json"
FIRMWARE = ROOT / "firmware/m4-v602/usr/lib/libmpr.so"
FIRMWARE_HASH = "1a7a8007828810f948eb4fb95b9a269176355553a69977f6d8f2ae59516f5532"
MASK = 0x7FFFFFFFFFF
SOURCE_FILES = [
    "analysis/decompile-mpr/001aa87c_ConvDefStructLocalTime2SiDBUInt64.c",
    "analysis/decompile-mpr/001b7ecc_ConvDefStructLocalTime2SiDBUInt64.c",
    "analysis/decompile-mpr/001bded4_ProvisionalRepairM4.c",
    "analysis/decompile-mpr/001bc1d8_ProvisionalRepairDcf.c",
    "analysis/decompile-mpr/001be8f4__Load.c",
    "analysis/decompile-mpr/001bf1b0_ReCreate.c",
    "analysis/decompile-mpr/00390bc4_SetHeaderParam_unsigned_long_.c",
    "analysis/decompile-mpr/00392a38_ConvRecordInfo2RecordStructure.c",
]


def digest(data):
    return hashlib.sha256(data).hexdigest()


def pack_header(stamp):
    minutes = int(stamp.utcoffset().total_seconds() // 60)
    # Match C++ truncation toward zero for the signed timezone division.
    half_hours = (abs(minutes) // 30) * (-1 if minutes < 0 else 1)
    return (((half_hours + 0x60) & 255) << 44 |
            (max(stamp.year - 1900, 0) & 255) << 36 |
            stamp.month << 32 | stamp.day << 27 | stamp.hour << 22 |
            stamp.minute << 16 | stamp.second << 10 | stamp.microsecond // 1000)


def record_time(record, offset):
    high, low = struct.unpack_from("<II", record, offset)
    half_hours = high >> 1 & 127
    if half_hours >= 64:
        half_hours -= 128
    stamp = datetime(1900 + (high >> 16 & 255), high >> 12 & 15,
                     low >> 27 & 31, low >> 22 & 31, low >> 16 & 63,
                     low >> 10 & 63, (low & 1023) * 1000,
                     tzinfo=timezone(timedelta(minutes=half_hours * 30)))
    packed = pack_header(stamp)
    return {"record_bytes_le": record[offset:offset + 8].hex(),
            "iso": stamp.isoformat(), "header_packed": hex(packed),
            "masked_comparison_key": hex(packed & MASK)}


def maximum(rows, field, kind):
    def key(row):
        value = row[field]
        if kind == "utc":
            return datetime.fromisoformat(value["iso"]).astimezone(timezone.utc)
        packed = int(value["header_packed"], 16)
        return packed & MASK if kind == "masked" else packed
    best = max(key(row) for row in rows)
    return [{"index": row["index"], "paths": row["paths"], **row[field]}
            for row in rows if key(row) == best]


def read_manifest(root, filename):
    with (root / filename).open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream))


def xml_dates(path):
    tree = ET.fromstring(path.read_bytes().rstrip(b" \x00"))
    dates = [{"element": node.tag.rsplit("}", 1)[-1], "attributes": dict(node.attrib)}
             for node in tree.iter()
             if "date" in node.tag.rsplit("}", 1)[-1].lower()]
    return {"sha256": digest(path.read_bytes()), "root_attributes": dict(tree.attrib),
            "dates": dates}


def snapshot_view(root, engine):
    raw = (root / "PRIVATE/DATABASE/DATABASE.BIN").read_bytes()
    records = inventory(raw)
    engine.load(raw)
    media = read_manifest(root, "_skipped_media_manifest.csv")
    metadata = read_manifest(root, "_metadata_manifest.csv")
    rows = []
    for item in records:
        if item["type"] != 0:
            continue
        record = bytes.fromhex(item["hex"])
        value = engine.convert(item["index"])
        info = bytes.fromhex(value["record_info_hex"])
        paths = [info[offset:offset + 0x106].split(b"\0", 1)[0].decode("ascii")
                 for offset in (0xC1, 0x1C8, 0x2CF, 0x3D6)]
        paths = [path.split(":", 1)[-1].lstrip("/") for path in paths if path]
        row = {"index": item["index"], "offset": item["offset"],
               "content_type": item["content_type"], "paths": paths,
               "checksum_valid": item["checksum_valid"],
               "creation": record_time(record, 0x10),
               "update_argument_time": record_time(record, 0x18),
               "native_converter_return": value["return_u32"],
               "native_converter_local_time_0c_hex": info[0xC:0x18].hex()}
        decoded = datetime.fromisoformat(row["creation"]["iso"])
        native_local = struct.pack("<hh6BH", int(decoded.utcoffset().total_seconds() // 60),
                                   decoded.year, decoded.month, decoded.day, decoded.hour,
                                   decoded.minute, decoded.second, 0,
                                   decoded.microsecond // 1000)
        row["native_converter_time_matches_decoder"] = native_local == info[0xC:0x18]
        row["media_manifest"] = [entry for entry in media
                                 if entry["relative_path"] in paths]
        rows.append(row)
    groups = {"all": rows,
              "photos": [row for row in rows if row["content_type"] == 1],
              "videos": [row for row in rows if row["content_type"] == 2]}
    maxima = {name: {field: {kind: maximum(values, field, kind)
                            for kind in ("masked", "unsigned_full", "utc")}
                    for field in ("creation", "update_argument_time")}
              for name, values in groups.items()}
    header = {hex(offset): header_time(raw, offset) for offset in (0x8010, 0x8018)}
    target = int(header["0x8010"]["raw"], 16)
    exact = [{"index": row["index"], "field": field, "paths": row["paths"],
              "value": row[field]} for row in rows
             for field in ("creation", "update_argument_time")
             if int(row[field]["header_packed"], 16) == target]
    represented = {path for row in rows for path in row["paths"]}
    xml = []
    comparisons = []
    for path in sorted((root / "PRIVATE/M4ROOT/CLIP").glob("*.XML")):
        details = xml_dates(path)
        details["relative_path"] = path.relative_to(root).as_posix()
        xml.append(details)
        creation = next((x["attributes"].get("value") for x in details["dates"]
                         if x["element"] == "CreationDate"), None)
        row = next((x for x in rows if details["relative_path"] in x["paths"]), None)
        comparisons.append({"xml": details["relative_path"],
                            "record_index": row["index"] if row else None,
                            "creation": creation,
                            "record_matches_xml": bool(row and creation and
                                pack_header(datetime.fromisoformat(creation)) ==
                                int(row["creation"]["header_packed"], 16)),
                            "header_8010_exact_match": bool(creation and
                                pack_header(datetime.fromisoformat(creation)) == target)})
    return {"snapshot": str(root.relative_to(ROOT)), "database_sha256": digest(raw),
            "database_bytes": len(raw), "header": header,
            "header_checksums_pass": all(x["valid"] for x in check_regions(raw)),
            "active_content_record_count": len(rows),
            "content_type_counts": dict(Counter(row["content_type"] for row in rows)),
            "all_content_checksums_pass": all(row["checksum_valid"] for row in rows),
            "native_time_decoding_all_match":
                all(row["native_converter_time_matches_decoder"] and
                    row["native_converter_return"] == 0 for row in rows),
            "records": rows, "maxima": maxima, "header_exact_record_matches": exact,
            "video_xml_dates": xml, "video_xml_record_comparisons": comparisons,
            "media_manifest_count": len(media),
            "media_manifest_extension_counts":
                dict(Counter(Path(row["relative_path"]).suffix.upper() for row in media)),
            "unreferenced_media_manifest_entries":
                [row for row in media if row["relative_path"] not in represented],
            "metadata_manifest_count": len(metadata)}


def original_pack_proof(firmware):
    from elftools.elf.elffile import ELFFile
    from unicorn import Uc, UC_ARCH_ARM64, UC_MODE_ARM
    from unicorn import arm64_const as regs

    if digest(firmware.read_bytes()) != FIRMWARE_HASH:
        raise ValueError("Unexpected libmpr.so hash")
    with firmware.open("rb") as stream:
        elf = ELFFile(stream)
        text = elf.get_section_by_name(".text")
        start = text["sh_addr"]
        code = text.data()
    uc = Uc(UC_ARCH_ARM64, UC_MODE_ARM)
    for base in (0xAA000, 0xB7000, 0x10000000, 0x20000000, 0x30000000):
        uc.mem_map(base, 0x2000)
    for address, size in ((0xAA87C, 128), (0xB7ECC, 144)):
        uc.mem_write(address, code[address - start:address - start + size])
    result = []
    for iso in ("2026-12-14T11:59:55+03:00", "2026-12-14T11:59:59+00:00",
                "2026-11-13T13:14:53+08:00", "2024-02-12T11:49:32+08:00"):
        stamp = datetime.fromisoformat(iso)
        local = struct.pack("<hh6BH", int(stamp.utcoffset().total_seconds() // 60),
                            stamp.year, stamp.month, stamp.day, stamp.hour, stamp.minute,
                            stamp.second, 0, stamp.microsecond // 1000)
        values = []
        for address in (0xAA87C, 0xB7ECC):
            uc.mem_write(0x10000000, local + bytes(52))
            uc.reg_write(regs.UC_ARM64_REG_SP, 0x20001000)
            uc.reg_write(regs.UC_ARM64_REG_X0, 0x10000000)
            uc.reg_write(regs.UC_ARM64_REG_X1, 0x10000020)
            uc.reg_write(regs.UC_ARM64_REG_X2, 0x10000028)
            uc.reg_write(regs.UC_ARM64_REG_X30, 0x30000000)
            uc.emu_start(address, 0x30000000, count=1000)
            if uc.reg_read(regs.UC_ARM64_REG_PC) != 0x30000000:
                raise RuntimeError("Original time helper did not return")
            returned = uc.reg_read(regs.UC_ARM64_REG_X0)
            values.append({"elf_vma": hex(address), "return": hex(returned),
                           "out_u64": hex(struct.unpack("<Q", uc.mem_read(0x10000020, 8))[0]),
                           "out_signed_timezone": struct.unpack("b", uc.mem_read(0x10000028, 1))[0]})
        result.append({"iso": iso, "local_time_bytes": local.hex(),
                       "python_header_packed": hex(pack_header(stamp)), "original_runs": values,
                       "original_header_helper_matches": values[0]["return"] == hex(pack_header(stamp))})
    return {"firmware": str(firmware.relative_to(ROOT)), "sha256": FIRMWARE_HASH,
            "execution_scope": "Only two pure original time helpers; no filesystem or repair emulation",
            "vectors": result}


def firmware_comparison_windows(firmware):
    from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
    from elftools.elf.elffile import ELFFile

    with firmware.open("rb") as stream:
        elf = ELFFile(stream)
        text = elf.get_section_by_name(".text")
        raw, base = text.data(), text["sh_addr"]
        symbols = elf.get_section_by_name(".dynsym")
        plt = elf.get_section_by_name(".plt")["sh_addr"]
        call_symbols = {plt + 32 + index * 16:
                        symbols.get_symbol(rel["r_info_sym"]).name
                        for index, rel in enumerate(
                            elf.get_section_by_name(".rela.plt").iter_relocations())}
        targets = [symbol for symbol in symbols.iter_symbols() if symbol["st_value"] in
                   {0xBDED4, 0xBC1D8, 0xBE8F4, 0xBF1B0, 0x290BC4}]
    md = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
    result = []
    for symbol in targets:
        address, size = symbol["st_value"], symbol["st_size"]
        ins = list(md.disasm(raw[address - base:address - base + size], address))
        selected = set(range(len(ins))) if address == 0x290BC4 else set()
        for index, item in enumerate(ins):
            target = int(item.op_str[1:], 16) if item.mnemonic == "bl" and item.op_str.startswith("#0x") else None
            name = call_symbols.get(target, "")
            if ("0x7ffffffffff" in item.op_str or
                "ConvDefStructLocalTime2SiDBUInt64" in name or "SetHeaderParam" in name):
                selected.update(range(max(0, index - 8), min(len(ins), index + 14)))
        lines = []
        for index in sorted(selected):
            item = ins[index]
            target = int(item.op_str[1:], 16) if item.mnemonic == "bl" and item.op_str.startswith("#0x") else None
            lines.append({"elf_vma": hex(item.address),
                          "ghidra_address": hex(item.address + 0x100000),
                          "bytes": bytes(item.bytes).hex(),
                          "asm": f"{item.mnemonic} {item.op_str}",
                          "plt_symbol": call_symbols.get(target)})
        result.append({"symbol": symbol.name, "elf_vma": hex(address),
                       "function_bytes_sha256": digest(raw[address-base:address-base+size]),
                       "selected_instruction_windows": lines})
    return result


def investigate():
    from emulate_sidb_converter import RecordConverter

    proof = original_pack_proof(FIRMWARE)
    engine = RecordConverter(FIRMWARE)
    before, after = [snapshot_view(root, engine) for root in (BEFORE, AFTER)]
    manifests = [read_manifest(root, "_skipped_media_manifest.csv") for root in (BEFORE, AFTER)]
    before_media, after_media = [{x["relative_path"]: x for x in rows} for rows in manifests]
    return {"scope": {"card_reads": False, "card_writes": False, "new_snapshots": False,
                      "reason_no_card_exif": "User reports F: unavailable; do not wait for or mount card",
                      "excluded": ["NRT embedded-path investigation", "overall record repair analysis"]},
            "before": before, "after": after,
            "media_manifest_size_mtime_differences":
                [path for path in sorted(set(before_media) | set(after_media))
                 if path not in before_media or path not in after_media or
                 any(before_media[path][key] != after_media[path][key]
                     for key in ("size", "last_write_time_ns"))],
            "original_time_helper_proof": proof,
            "original_firmware_comparison_windows": firmware_comparison_windows(FIRMWARE),
            "local_source_hashes": {path: digest((ROOT / path).read_bytes()) for path in SOURCE_FILES},
            "findings": [
                "After header 0x8010 is exactly the original header packing of C6353 record 53 creation time, including +03:00 and zero milliseconds.",
                "C6353M01.XML CreationDate already contains that exact time in both snapshots; compare source hashes and XML date entries.",
                "All 23 photo and 51 video content records in both snapshots are included; original offline converter confirms all decoded creation LocalTime bytes.",
                "After C6353 is the unique maximum creation time under the existing-record repair mask 0x7ffffffffff; this is not a UTC comparison.",
                "Existing-record provisional M4 and Dcf loops compare masked dates and retain the full packed winning value. Remaining-new-object loops use a different overload (timezone separate) and unmasked comparison.",
                "_Load compares masked Dcf/M4 accumulators; ReCreate compares full unsigned accumulators. Both conditionally call header parameter 3 when a repair flag is set.",
                "SetHeaderParam<unsigned long> parameter 3 writes database+0x8010 and updates header checksum/flush state.",
            ],
            "limitations": [
                "No camera execution trace proves which repair caller or per-object branch ran; static code plus exact record/XML match supports provenance, not a unique causal history.",
                "A content record is not itself demonstrated as the runtime accumulator source; provisional loops use ExistedFileInfo LocalTime. Derivation of that intermediate object is outside this subtask.",
                "No photo EXIF bytes exist in these non-media snapshots. No saved standalone EXIF export was identified in the targeted local artifact inventory; live F: was not read.",
                "Media manifest size/mtime agreement does not prove media byte identity. No media hashes were recomputed and no video/EXIF metadata was reread from the card.",
                "The mask drops bits 43 and above, including timezone and the top year-offset bit. All observed content years are below 2028, so that year truncation does not alter this comparison.",
                "The presence of future-dated source metadata does not establish why the camera clock was set that way, actual capture date, or a physical repair-time clock jump.",
            ]}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    if args.output is not None and args.output.resolve() != OUTPUT:
        raise ValueError("Only analysis/repair-header-time-0027.json may be written")
    report = investigate()
    if args.output is not None:
        OUTPUT.write_text(json.dumps(report, indent=2, ensure_ascii=True) + "\n", encoding="utf-8")
    else:
        print(json.dumps(report, indent=2, ensure_ascii=True))
    print(json.dumps({"before_header": report["before"]["header"],
                      "after_header": report["after"]["header"],
                      "exact_matches_after": report["after"]["header_exact_record_matches"],
                      "all_native_time_decodes_match":
                          all(report[key]["native_time_decoding_all_match"] for key in ("before", "after")),
                      "media_size_mtime_differences": report["media_manifest_size_mtime_differences"]},
                     indent=2))


if __name__ == "__main__":
    main()
