"""Purpose: independently decode selected SD catalog evidence for comparisons.

Usage: import umid_evidence, restore_path_template and header_time from
    sd_catalog_evidence; callers provide saved record/database bytes. No CLI.
Design: restore chained paths and packed times, then diagnose whether UMID
    differences can be explained by lost subsecond precision.
Scope: observed Sony SD layouts only. These helpers do not modify inputs or
    decide listing/playback compatibility from metadata agreement.
"""
import struct
from datetime import timedelta

from sony_umid import creation_time, material_time, restore_umid


def umid_evidence(record, array_record, expected):
    expected = bytes.fromhex(expected)
    if len(expected) != 32:
        raise ValueError("Expected a 32-byte UMID")
    restored = restore_umid(record, array_record)
    stamp = creation_time(record)
    candidates = []
    # Native record dates can omit the UMID generator's subsecond component.
    # This search diagnoses that loss; it does not change the restored value.
    if stamp.microsecond == 0:
        candidates = [ms for ms in range(1000)
                      if material_time(stamp + timedelta(milliseconds=ms)) == expected[16:23]]
    identity_matches = restored[:16] == expected[:16] and restored[23:] == expected[23:]
    return {
        "catalog_creation_time": stamp.isoformat(),
        "exact_match": restored == expected,
        "non_time_bytes_match": identity_matches,
        "mjd_bytes_match": restored[20:23] == expected[20:23],
        "same_second_material_time_candidates_ms": candidates,
        "explained_by_omitted_subseconds": identity_matches and bool(candidates),
        "camera_acceptance_proven": False,
    }


def restore_path_template(records, index):
    parts, seen = [], set()
    while index != 0xFFFFFFFF:
        if index in seen:
            raise ValueError("Path chain cycle")
        seen.add(index)
        row = records.get(index)
        if not row or row["type"] != 1 or not row["checksum_valid"]:
            raise ValueError("Invalid path record")
        raw = bytes.fromhex(row["hex"])
        length = struct.unpack_from("<H", raw, 8)[0] >> 1
        if length > 148:
            raise ValueError("Path fragment exceeds record payload")
        parts.append(raw[10:10 + length].decode("ascii"))
        index = struct.unpack_from("<I", raw, 4)[0]
    return "".join(parts)


def header_time(data, offset):
    packed = struct.unpack_from("<Q", data, offset)[0]
    return {
        "raw": hex(packed), "year": 1900 + (packed >> 36 & 255),
        "month": packed >> 32 & 15, "day": packed >> 27 & 31,
        "hour": packed >> 22 & 31, "minute": packed >> 16 & 63,
        "second": packed >> 10 & 63, "millisecond": packed & 1023,
        "timezone_minutes": ((packed >> 44 & 255) - 0x60) * 30,
    }
