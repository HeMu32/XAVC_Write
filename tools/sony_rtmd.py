"""Purpose: retimestamp the measured minimal EDIUS RTMD packet templates.

Usage: import make_packet and timecode from sony_rtmd; supply a supported seed,
    frame index and half-step mode through the package builder. No CLI.
Design: update only identified time fields while preserving opaque bytes.
    59.94p uses paired labels/half-step; 29.97p uses one label per sample.
Scope: the measured templates and modeled drop-frame boundaries, not arbitrary
    sensor metadata, complete RTMD semantics or proof of camera playback.
"""
import operator
import struct


def _frame_index(frame):
    if isinstance(frame, bool):
        raise ValueError("Expected a nonnegative integer frame count")
    try:
        frame = operator.index(frame)
    except TypeError as exc:
        raise ValueError("Expected a nonnegative integer frame count") from exc
    if frame < 0:
        raise ValueError("Negative frame count")
    return frame


def timecode(frame, half_step=True):
    """Encode an absolute sample count as a 24-hour drop-frame timecode."""
    frame = _frame_index(frame)
    f = frame // 2 if half_step else frame
    ten, rem = divmod(f, 17982)
    f += 18 * ten + (2 * ((rem - 2) // 1798) if rem >= 2 else 0)
    f %= 30 * 60 * 60 * 24
    sec, ff = divmod(f, 30)
    minute, ss = divmod(sec, 60)
    hh, mm = divmod(minute, 60)
    bcd = lambda v: v // 10 * 16 + v % 10
    parity = (frame & 1) << 7 if half_step else 0
    return bytes([bcd(ff) | 0x40, bcd(ss) | parity, bcd(mm), bcd(hh)])


def _start_frame_2997(template):
    tc = template[20:24]
    if (tc[0] & 0xC0) != 0x40 or tc[1] & 0x80:
        raise ValueError("Expected 29.97p drop-frame timecode without a half-step bit")
    fields = [tc[3], tc[2], tc[1], tc[0] & 0x3F]
    if any((v >> 4) > 9 or (v & 15) > 9 for v in fields):
        raise ValueError("Invalid BCD in rtmd template timecode")
    hh, mm, ss, ff = [(v >> 4) * 10 + (v & 15) for v in fields]
    if hh >= 24 or mm >= 60 or ss >= 60 or ff >= 30:
        raise ValueError("Out-of-range rtmd template timecode")
    if mm % 10 and ss == 0 and ff < 2:
        raise ValueError("Dropped timecode label in rtmd template")
    if template[13:18] != bytes([hh, mm, ss]) + struct.pack(">H", ff):
        raise ValueError("rtmd template timecode fields disagree")
    minutes = hh * 60 + mm
    return ((minutes * 60 + ss) * 30 + ff) - 2 * (minutes - minutes // 10)


def make_packet(template, frame, half_step=True):
    """Advance by frame samples, retaining the observed 29.97p template start.

The default 59.94p mode retains its original zero-start template requirement.
Only offsets 13:18 and 20:24 are rewritten; other bytes remain opaque.
"""
    frame = _frame_index(frame)
    if len(template) != 1024 or template[:2] != b"\x00\x1c":
        raise ValueError("Expected the minimal 1024-byte EDIUS rtmd packet")
    start = 0
    if half_step:
        if template[13:18] != bytes(5) or template[20:24] != timecode(0):
            raise ValueError("rtmd template must start at zero timecode")
    else:
        start = _start_frame_2997(template)
    packet = bytearray(template)
    tc = timecode(start + frame, half_step=half_step)
    decimal = lambda v: (v >> 4) * 10 + (v & 15)
    hh, mm, ss = decimal(tc[3]), decimal(tc[2]), decimal(tc[1] & 127)
    ff = decimal(tc[0] & 63)
    if half_step:
        ff = ff * 2 + (tc[1] >> 7)
    packet[13:16] = bytes([hh, mm, ss])
    struct.pack_into(">H", packet, 16, ff)
    packet[20:24] = tc
    return bytes(packet)
