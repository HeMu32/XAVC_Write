"""Purpose: execute Sony's embedded-NRT XML scanner against a local MP4.

Usage: python tools/emulate_nrt_extract.py LOCAL.MP4 --output REPORT.json
    [--snapshot SNAP --firmware LIBMPR --expat LIBEXPAT].
Design: run original open/size/read helpers, compare returned XML with an
    independent BMFF parser, and verify executable sections remain unchanged.
Scope: bounded embedded-XML extraction using modeled read-only I/O. Not full
    NRT semantic parsing, complete repair execution or a camera playback verdict.
"""
import argparse
import hashlib
import json
import mmap
from pathlib import Path
import struct

from emulate_xavc_reader import XavcReaderEmulator
from sony_mp4 import MP4


def digest(data):
    return hashlib.sha256(data).hexdigest()


def extract(media, firmware, expat, snapshot):
    parser = MP4(media)
    try:
        xml = parser.child(parser.one(parser.top, "meta"), "xml ", 4)
        host_xml = parser.payload(xml)[4:].rstrip(b"\0")
    finally:
        parser.close()
    with media.open("rb") as stream:
        data = mmap.mmap(stream.fileno(), 0, access=mmap.ACCESS_READ)
        try:
            engine = XavcReaderEmulator(firmware, expat, snapshot, data)
            obj, size_cell = engine.allocate(0x80), engine.allocate(8)
            statuses = []
            for name, entry, args, is_status in (
                    ("nrt_file_constructor", 0x241acc, [obj], False),
                    ("open_main_mp4", 0x241af0, [obj, engine.path, 1], True),
                    ("embedded_xml_size", 0x242354, [obj, size_cell], True)):
                value = engine.step(name, entry, args, is_status)
                statuses.append({"label": name, "return_u32": value if is_status else None})
                if is_status and value:
                    raise RuntimeError(f"NRT step failed: {name}: {value:#x}")
            size = struct.unpack("<I", engine.uc.mem_read(size_cell, 4))[0]
            if not 0 < size <= 0x100000:
                raise ValueError("Unbounded embedded XML size")
            output = engine.allocate(size + 16)
            value = engine.step("embedded_xml_read", 0x241dac, [obj, output, size])
            statuses.append({"label": "embedded_xml_read", "return_u32": value})
            guest_xml = bytes(engine.uc.mem_read(output, size))
            value = engine.step("nrt_file_close", 0x241b2c, [obj])
            statuses.append({"label": "nrt_file_close", "return_u32": value})
            sections = [
                {"vma": hex(address), "bytes": len(raw), "sha256": digest(raw),
                 "unchanged": bytes(engine.uc.mem_read(address, len(raw))) == raw}
                for address, raw in engine.code_sections]
            checks = {
                "all_selected_returns_zero": all(not row["return_u32"] for row in statuses),
                "original_scanner_matches_host_embedded_xml": guest_xml == host_xml,
                "only_main_mp4_opened": [row["path"] for row in engine.io
                                        if row["operation"] == "Fsys_Open"] ==
                                       ["A:/PRIVATE/M4ROOT/CLIP/TEST.MP4"],
                "executable_sections_unchanged": all(row["unchanged"] for row in sections),
            }
            return {
                "media": str(media), "media_sha256": digest(data),
                "firmware_sha256": digest(firmware.read_bytes()),
                "expat_sha256": digest(expat.read_bytes()), "card_access": False,
                "checks": checks, "passed": all(checks.values()), "statuses": statuses,
                "xml_size": size, "xml_sha256": digest(guest_xml),
                "original_scanner_xml": guest_xml.decode("utf-8"),
                "original_instruction_count": engine.instruction_count,
                "file_operations": engine.io, "code_sections": sections,
                "scope": "Original embedded-XML scanner called by GetRecordInfoFromNrtMeta; not full repair or XML semantic parsing"}
        finally:
            data.close()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("media")
    ap.add_argument("--firmware", default="firmware/m4-v602/usr/lib/libmpr.so")
    ap.add_argument("--expat", default="firmware/m4-v602/usr/lib/libexpat.so.1.6.11")
    ap.add_argument("--snapshot", default="backup/snap_20261113T135646")
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    paths = [Path(value).resolve() for value in
             (args.media, args.firmware, args.expat, args.snapshot, args.output)]
    if any(path.drive.upper() == "F:" for path in paths):
        raise ValueError("Only local media and saved snapshots allowed")
    if paths[4] == paths[3] or paths[3] in paths[4].parents or paths[4] in paths[:3]:
        raise ValueError("Output would overwrite an input")
    report = extract(*paths[:4])
    paths[4].parent.mkdir(parents=True, exist_ok=True)
    paths[4].write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps({key: report[key] for key in ("passed", "checks", "xml_size")}, indent=2))
    if not report["passed"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
