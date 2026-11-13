"""Purpose: normalize selected AVC VUI/HRD and sample-framing fields.

Usage: import avcc_normalize, normalize_sps and normalize_sample in the package
    builder; use Bits/escape/unescape for supported syntax inspection. No CLI.
Design: edit parsed bit fields and rebuild escaped RBSP rather than substituting
    another encoder's SPS or rewriting its coded picture/slice parameters.
Scope: explicitly supported progressive AVC profiles and syntax. These helpers
    are not a complete H.264 implementation or independent camera admission test.
"""
import struct
from fractions import Fraction


def unescape(data):
    out = bytearray()
    zeros = 0
    for i, value in enumerate(data):
        if zeros >= 2 and value == 3:
            if i + 1 >= len(data) or data[i + 1] > 3:
                raise ValueError("Invalid emulation-prevention byte")
            zeros = 0
            continue
        out.append(value)
        zeros = zeros + 1 if value == 0 else 0
    return bytes(out)


def escape(data):
    out = bytearray()
    zeros = 0
    for value in data:
        if zeros >= 2 and value <= 3:
            out.append(3)
            zeros = 0
        out.append(value)
        zeros = zeros + 1 if value == 0 else 0
    return bytes(out)


def bitstring(data):
    return "".join(f"{x:08b}" for x in data)


def packbits(bits):
    return int(bits + "0" * (-len(bits) % 8), 2).to_bytes((len(bits) + 7) // 8, "big")


class Bits:
    def __init__(self, data):
        self.bits = bitstring(data)
        self.p = 0

    def u(self, n):
        if self.p + n > len(self.bits):
            raise ValueError("Truncated AVC syntax")
        v = int(self.bits[self.p:self.p+n], 2) if n else 0
        self.p += n
        return v

    def ue(self):
        zeros = 0
        while self.u(1) == 0:
            zeros += 1
            if zeros > 31:
                raise ValueError("Unbounded Exp-Golomb")
        return (1 << zeros) - 1 + self.u(zeros)

    def se(self):
        v = self.ue()
        return (v + 1) // 2 if v & 1 else -(v // 2)


def hrd(b):
    count = b.ue() + 1
    if count > 32:
        raise ValueError("Invalid CPB count")
    rate_scale, size_scale = b.u(4), b.u(4)
    rates, sizes, cbr = [], [], []
    for _ in range(count):
        rates.append((b.ue() + 1) << (6 + rate_scale))
        sizes.append((b.ue() + 1) << (4 + size_scale))
        cbr.append(b.u(1))
    initial = b.u(5) + 1
    removal = b.u(5) + 1
    output = b.u(5) + 1
    offset = b.u(5)
    return {"count": count, "initial": initial, "removal": removal, "output": output, "offset": offset,
            "rates": rates, "sizes": sizes, "cbr": cbr,
            "rate_scale": rate_scale, "size_scale": size_scale}


def normalize_sps(nal, frame_rate=Fraction(60000, 1001)):
    frame_rate = Fraction(frame_rate)
    if frame_rate not in {Fraction(60000, 1001), Fraction(30000, 1001)}:
        raise ValueError("Unsupported progressive AVC frame rate")
    if nal[0] & 31 != 7:
        raise ValueError("Not SPS")
    b = Bits(unescape(nal[1:]))
    profile = b.u(8)
    b.u(8)
    level = b.u(8)
    sid = b.ue()
    if profile in {100, 110, 122, 244, 44, 83, 86, 118, 128, 138, 139, 134, 135}:
        chroma = b.ue()
        if chroma == 3:
            b.u(1)
        depth_luma, depth_chroma = b.ue() + 8, b.ue() + 8
        b.u(1)
        if b.u(1):
            for i in range(8 if chroma != 3 else 12):
                if b.u(1):
                    last, next_scale = 8, 8
                    for _ in range(16 if i < 6 else 64):
                        if next_scale:
                            next_scale = (last + b.se() + 256) % 256
                        last = next_scale or last
    if profile != 100 or chroma != 1 or depth_luma != 8 or depth_chroma != 8:
        raise ValueError("Expected High profile 8-bit 4:2:0")
    b.ue()
    poc = b.ue()
    if poc == 0:
        b.ue()
    elif poc == 1:
        b.u(1)
        b.se()
        b.se()
        for _ in range(b.ue()):
            b.se()
    b.ue()
    b.u(1)
    width_mbs, height_map_units = b.ue() + 1, b.ue() + 1
    if not b.u(1):
        raise ValueError("Only progressive frame SPS is supported")
    b.u(1)
    crop = [b.ue() for _ in range(4)] if b.u(1) else [0] * 4
    width = width_mbs * 16 - 2 * (crop[0] + crop[1])
    height = height_map_units * 16 - 2 * (crop[2] + crop[3])
    if not b.u(1):
        raise ValueError("Missing VUI")
    if b.u(1) and b.u(8) == 255:
        b.u(16)
        b.u(16)
    if b.u(1):
        b.u(1)
    if b.u(1):
        b.u(3)
        b.u(1)
        if b.u(1):
            b.u(24)
    if b.u(1):
        b.ue()
        b.ue()
    if not b.u(1):
        raise ValueError("Missing timing")
    timing = b.p
    tick, scale, fixed = b.u(32), b.u(32), b.u(1)
    if scale * frame_rate.denominator != tick * 2 * frame_rate.numerator:
        raise ValueError("SPS timing disagrees with selected frame rate")
    if not b.u(1):
        raise ValueError("Missing NAL HRD")
    start = b.p
    info = hrd(b)
    nal_hrd = b.bits[start:b.p]
    vcl = b.p
    if b.u(1):
        raise ValueError("VCL HRD already present; avoid double patching")
    bits = b.bits[:vcl] + "1" + nal_hrd + b.bits[vcl+1:b.bits.rfind("1")+1]
    normalized_tick = 240000 * frame_rate.denominator // (2 * frame_rate.numerator)
    bits = bits[:timing] + f"{normalized_tick:032b}{240000:032b}1" + bits[timing+65:]
    return nal[:1] + escape(packbits(bits)), {"sps_id": sid, "hrd": info,
                                             "old_tick": tick, "old_scale": scale,
                                             "old_fixed": fixed, "profile_idc": profile,
                                             "level_idc": level, "width": width, "height": height,
                                             "chroma_format_idc": chroma,
                                             "bit_depth_luma": depth_luma,
                                             "bit_depth_chroma": depth_chroma,
                                             "normalized_tick": normalized_tick,
                                             "normalized_scale": 240000}


def avcc_normalize(data, frame_rate=Fraction(60000, 1001)):
    length_size = (data[4] & 3) + 1
    p, sps = 6, []
    mappings, infos = {}, {}
    for _ in range(data[5] & 31):
        n = struct.unpack_from(">H", data, p)[0]
        old = data[p+2:p+2+n]
        new, info = normalize_sps(old, frame_rate)
        if info["sps_id"] in infos:
            raise ValueError("Duplicate SPS id; expected one unchanging parameter set")
        mappings[old] = new
        infos[info["sps_id"]] = info
        sps.append(struct.pack(">H", len(new)) + new)
        p += 2 + n
    # All PPS bytes and optional AVC configuration extensions stay encoder-original.
    result = data[:4] + b"\xfe" + data[5:6] + b"".join(sps) + data[p:]
    return result, length_size, mappings, infos


def sei_buffering_period(nal, infos):
    raw = unescape(nal[1:])
    p, out = 0, bytearray()
    while p < len(raw) and raw[p:] != b"\x80":
        typ, n = 0, 0
        while p < len(raw) and raw[p] == 255:
            typ += 255
            p += 1
        if p >= len(raw):
            raise ValueError("Truncated SEI type")
        typ += raw[p]
        p += 1
        while p < len(raw) and raw[p] == 255:
            n += 255
            p += 1
        if p >= len(raw):
            raise ValueError("Truncated SEI length")
        n += raw[p]
        p += 1
        payload = raw[p:p+n]
        if len(payload) != n:
            raise ValueError("Truncated SEI payload")
        p += n
        if typ == 0:
            b = Bits(payload)
            sid = b.ue()
            start = b.p
            info = infos[sid]["hrd"]
            b.u(2 * info["count"] * info["initial"])
            delays = b.bits[start:b.p]
            bits = b.bits[:b.p] + delays
            if len(bits) % 8:
                bits += "1"
            payload = packbits(bits)
        out.extend(b"\xff" * (typ // 255) + bytes([typ % 255]))
        out.extend(b"\xff" * (len(payload) // 255) + bytes([len(payload) % 255]) + payload)
    out.append(128)
    return nal[:1] + escape(bytes(out))


def normalize_sample(sample, length_size, mappings, infos):
    p, out = 0, bytearray()
    while p < len(sample):
        if p + length_size > len(sample):
            raise ValueError("Truncated NAL length")
        n = int.from_bytes(sample[p:p+length_size], "big")
        p += length_size
        nal = sample[p:p+n]
        if not nal or len(nal) != n:
            raise ValueError("Invalid NAL span")
        p += n
        typ = nal[0] & 31
        if typ == 7:
            nal = mappings[nal]
        elif typ == 6:
            nal = sei_buffering_period(nal, infos)
        if len(nal) >= 1 << 24:
            raise ValueError("NAL exceeds 24-bit length field")
        out.extend(len(nal).to_bytes(3, "big") + nal)
    return bytes(out)
