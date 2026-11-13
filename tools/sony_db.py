"""Purpose: decode observed Sony SD sidb allocation, records and checksums.

Usage: python tools/sony_db.py LOCAL_DATABASE.BIN --output REPORT.json;
    import inventory/check_regions/fix_checksums for other offline tools.
Design: use the M4 6.02 Load-derived header regions, bitmap and 160-byte stride;
    the CLI only reads input, while fix_checksums edits its caller-owned buffer.
Scope: this observed SD layout, not arbitrary Sony databases or CFexpress.
    Checksum validity alone does not establish catalog or playback acceptance.
"""
import argparse
import json
import struct
from pathlib import Path

MODULUS = 0xFFFFFFFB


def checksum(data, modulus=MODULUS):
    padded = data + bytes((-len(data)) % 8)
    total = sum(struct.unpack("<" + str(len(padded) // 8) + "Q", padded))
    return (total & 0xFFFFFFFFFFFFFFFF) % modulus


def check_regions(data):
    ranges = [(0, 0x3FFC, 0x3FFC), (0x7C40, 0x3BC, 0x7FFC),
              (0x8000, 0x3FFC, 0xBFFC), (0xC000, 0x3FFC, 0xFFFC)]
    ranges += [(p, 0x400, 0x7C00 + (p - 0x4000) // 0x100)
               for p in range(0x4000, 0x7C00, 0x400)]
    return [{"start": hex(p), "length": hex(n), "field": hex(dest),
             "computed": checksum(data[p:p+n]), "stored": struct.unpack_from("<I", data, dest)[0],
             "valid": checksum(data[p:p+n]) == struct.unpack_from("<I", data, dest)[0]}
            for p, n, dest in ranges]


def fix_checksums(data):
    for p in range(0x4000, 0x7C00, 0x400):
        struct.pack_into("<I", data, 0x7C00 + (p - 0x4000) // 0x100,
                         checksum(bytes(data[p:p+0x400])))
    for p, n, dest in [(0, 0x3FFC, 0x3FFC), (0x7C40, 0x3BC, 0x7FFC),
                       (0x8000, 0x3FFC, 0xBFFC), (0xC000, 0x3FFC, 0xFFFC)]:
        struct.pack_into("<I", data, dest, checksum(bytes(data[p:p+n])))


def inventory(data):
    stride, capacity = struct.unpack_from("<I", data, 0x30)[0], struct.unpack_from("<I", data, 0x44)[0]
    if stride != 160 or len(data) < 0x10000 + stride * capacity:
        raise ValueError("Unexpected database allocation")
    records = []
    for index in range(capacity):
        if not (data[0x4000 + index // 8] >> (index % 8) & 1):
            continue
        p = 0x10000 + index * stride
        record = data[p:p+stride]
        typ = record[0] & 15
        row = {"index": index, "offset": hex(p), "type": typ, "hex": record.hex()}
        row["checksum_valid"] = checksum(record[:158], 0xFFF1) == struct.unpack_from("<H", record, 158)[0]
        if typ == 0:
            row["content_type"] = record[7] & 15
            row["clip_number"] = struct.unpack_from("<H", record, 14)[0] >> 2
            row["path_refs"] = list(struct.unpack_from("<4H", record, 0x50))
            row["video_info_ref"] = struct.unpack_from("<H", record, 0x58)[0] | ((record[0x5C] >> 4 & 1) << 16)
        records.append(row)
    return records


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("input")
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    data = Path(args.input).read_bytes()
    records = inventory(data)
    out = {"input": args.input, "checksums": check_regions(data),
           "header": data[:0x80].hex(), "counter_block": data[0x7C40:0x7CA0].hex(),
           "records": records}
    Path(args.output).write_text(json.dumps(out, indent=2), encoding="utf-8")
    print("checksums", sum(x["valid"] for x in out["checksums"]), "/", len(out["checksums"]),
          "active records", len(records))
    for r in records:
        if r["type"] == 0:
            print({k: v for k, v in r.items() if k != "hex"})


if __name__ == "__main__":
    main()
