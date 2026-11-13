"""Purpose: model the identified M4 6.02 sidb UMID/time reconstruction.

Usage: import make_umid, material_time, creation_time or restore_umid from
    sony_umid, passing explicit timestamps and record/array bytes. No CLI.
Design: preserve the original arithmetic and packed-date behavior, including
    unusual multipliers, instead of replacing them with assumed standard logic.
Scope: this firmware-derived SD representation, not a universal UMID generator.
    Restored catalog identity can differ from UUID-style XML material bytes.
"""
import os
import struct
from datetime import datetime, timezone

LABEL = bytes.fromhex("060A2B340101010501010D4313000000")


def material_time(stamp):
    utc = stamp.astimezone(timezone.utc)
    # Preserve the actual instructions, including the unusual hour multiplier and
    # divide-by-86400 after conversion to milliseconds. This is not a typo fix.
    seconds = utc.second + (utc.minute + utc.hour * 3600) * 60
    milliseconds = seconds * 1000 + utc.microsecond // 1000
    numerator = milliseconds * 0xFFFFFFFF & 0xFFFFFFFFFFFFFFFF
    counter = numerator // 86400 & 0xFFFFFFFF
    mjd = (utc.date() - datetime(1858, 11, 17).date()).days
    if not 0 <= mjd < 1000000:
        raise ValueError("UMID MJD outside six BCD digits")
    bcd = lambda v: (v // 10) * 16 + v % 10
    date = bytes(bcd(mjd // (100 ** i) % 100) for i in range(3))
    return struct.pack("<I", counter) + date


def make_umid(stamp, node, discriminator=None):
    if len(node) != 8:
        raise ValueError("UMID node must be 8 bytes")
    if discriminator is None:
        discriminator = 0xC0 | (os.urandom(1)[0] & 31)
    return LABEL + material_time(stamp) + bytes([discriminator]) + node


def creation_time(record):
    from datetime import timedelta
    high, low = struct.unpack_from("<II", record, 0x10)
    tz = high >> 1 & 127
    if tz >= 64:
        tz -= 128
    return datetime(1900 + (high >> 16 & 255), high >> 12 & 15, low >> 27 & 31,
                    low >> 22 & 31, low >> 16 & 63, low >> 10 & 63,
                    (low & 1023) * 1000, tzinfo=timezone(timedelta(minutes=tz * 30)))


def restore_umid(record, array_record):
    slot = record[0x5D] >> 4
    p = 12 + slot * array_record[5]
    value = bytearray(array_record[p:p+32])
    if len(value) != 32:
        raise ValueError("Missing UMID array entry")
    value[13:16] = record[0x5F:0x62]
    value[16:23] = material_time(creation_time(record))
    value[23] = record[0x5E]
    return bytes(value)
