"""Purpose: account for AVC NAL/VCL CPB bits and retime buffering-period SEI.

Usage: import CbrRetimer or retime_cbr_samples from avc_hrd; the encoder/package
    tools supply ordered samples and the selected profile. There is no CLI.
Design: parse and rebuild length-delimited NAL/SEI data, retaining coded payloads
    while deriving separate NAL and VCL initial delays from actual byte counts.
Scope: the supported single-CPB CBR experiment configuration. Not a general AVC
    validator, DPB simulator or proof of camera/hardware conformance.
"""
from fractions import Fraction
import math

from avc_sony import Bits, escape, packbits, unescape

VCL_AND_FILLER = {1, 2, 3, 4, 5, 12}


def nals(sample, length_size):
    result = []
    p = 0
    while p < len(sample):
        if p + length_size > len(sample):
            raise ValueError("Truncated NAL length")
        size = int.from_bytes(sample[p:p + length_size], "big")
        p += length_size
        if size <= 0 or p + size > len(sample):
            raise ValueError("Invalid NAL span")
        nal = sample[p:p + size]
        if nal[0] & 0x80:
            raise ValueError("NAL forbidden_zero_bit is set")
        result.append(nal)
        p += size
    return result


def sei_messages(nal):
    if nal[0] & 31 != 6:
        raise ValueError("Not SEI")
    data = unescape(nal[1:])
    result, p = [], 0
    while data[p:] != b"\x80":
        typ, size = 0, 0
        while p < len(data) and data[p] == 255:
            typ += 255
            p += 1
        if p >= len(data):
            raise ValueError("Missing SEI type or trailing bits")
        typ += data[p]
        p += 1
        while p < len(data) and data[p] == 255:
            size += 255
            p += 1
        if p >= len(data):
            raise ValueError("Missing SEI size")
        size += data[p]
        p += 1
        if p + size > len(data):
            raise ValueError("Truncated SEI payload")
        result.append((typ, data[p:p + size]))
        p += size
    return result


def encode_sei(header, messages):
    data = bytearray()
    for typ, payload in messages:
        data.extend(b"\xff" * (typ // 255) + bytes([typ % 255]))
        data.extend(b"\xff" * (len(payload) // 255) + bytes([len(payload) % 255]))
        data.extend(payload)
    return bytes([header]) + escape(bytes(data) + b"\x80")


def nal_bits(units, group):
    return sum(len(nal) * 8 for nal in units
               if group == "nal" or (nal[0] & 31) in VCL_AND_FILLER)


class CbrRetimer:
    """Keep coding data and picture timing; retime only dual-HRD BP pairs.

    The conformance point is a NAL unit stream, not MP4 length prefixes or
    an unspecified Annex B reconstruction. Only one constant-rate CPB is supported.
    """
    def __init__(self, infos, frame_duration, initial_override=None):
        if len(infos) != 1:
            raise ValueError("Retiming requires exactly one unchanging SPS")
        self.infos = infos
        self.frame_duration = Fraction(frame_duration)
        if self.frame_duration <= 0:
            raise ValueError("Frame duration must be positive")
        self.initial = None
        self.initial_override = initial_override
        self.bits = {"nal": 0, "vcl": 0}
        self.next_index = 0
        self.periods = []
        for info in infos.values():
            hrd = info["hrd"]
            if hrd["count"] != 1 or hrd.get("cbr") != [1]:
                raise ValueError("Retiming requires one CBR CPB")
            if hrd["rates"][0] <= 0 or hrd["sizes"][0] <= 0:
                raise ValueError("Invalid CPB rate or size")

    def rewrite_period(self, payload, index):
        b = Bits(payload)
        sid = b.ue()
        prefix = b.bits[:b.p]
        hrd = self.infos[sid]["hrd"]
        width = hrd["initial"]
        old = [(b.u(width), b.u(width)) for _ in range(2)]
        if self.initial is None:
            if index != 0:
                raise ValueError("First access unit must carry the initializing buffering period")
            self.initial = (list(self.initial_override) if self.initial_override is not None else
                            [pair[0] for pair in old])
        rate, size = hrd["rates"][0], hrd["sizes"][0]
        duration = Fraction(size * 90000, rate)
        new = []
        for position, group in enumerate(("nal", "vcl")):
            desired = (self.initial[position] + index * self.frame_duration * 90000 -
                       Fraction(self.bits[group] * 90000, rate))
            delay = desired.numerator // desired.denominator
            offset = duration.numerator // duration.denominator - delay
            if not 0 < delay < (1 << width) or not 0 <= offset < (1 << width):
                raise ValueError("Computed buffering-period delay/offset is outside field range")
            new.append((delay, offset))
        bits = prefix + "".join(f"{delay:0{width}b}{offset:0{width}b}" for delay, offset in new)
        if len(bits) % 8:
            bits += "1"
        self.periods.append({"sample_index": index, "old": old, "new": new})
        return packbits(bits)

    def rewrite(self, sample, index, length_size=3):
        if index != self.next_index:
            raise ValueError("Samples must be retimed exactly once in decode order")
        units, periods = [], 0
        for nal in nals(sample, length_size):
            if nal[0] & 31 == 6:
                messages = []
                for typ, payload in sei_messages(nal):
                    if typ == 0:
                        periods += 1
                        if periods > 1:
                            raise ValueError("Multiple buffering periods in one access unit")
                        payload = self.rewrite_period(payload, index)
                    messages.append((typ, payload))
                nal = encode_sei(nal[0], messages)
            units.append(nal)
        if self.initial is None:
            raise ValueError("Missing initializing buffering period")
        for group in self.bits:
            self.bits[group] += nal_bits(units, group)
        self.next_index += 1
        return b"".join(len(nal).to_bytes(length_size, "big") + nal for nal in units)


def retime_cbr_samples(samples, infos, frame_duration):
    """Select feasible initial delays before the sequential escaped-byte pass."""
    vm = CbrRetimer(infos, frame_duration)
    hrd = next(iter(infos.values()))["hrd"]
    rate, size = hrd["rates"][0], hrd["sizes"][0]
    counted = {group: [] for group in ("nal", "vcl")}
    periods, old_initial = [], None
    for index, sample in enumerate(samples):
        units = nals(sample, 3)
        for group in counted:
            counted[group].append(nal_bits(units, group))
        for nal in units:
            if nal[0] & 31 != 6:
                continue
            for typ, payload in sei_messages(nal):
                if typ != 0:
                    continue
                periods.append(index)
                if index == 0:
                    reader = Bits(payload)
                    reader.ue()
                    old_initial = []
                    for _ in range(2):
                        old_initial.append(reader.u(hrd["initial"]))
                        reader.u(hrd["initial"])
    if old_initial is None or not samples:
        raise ValueError("Missing initializing buffering period")
    # One-CPB BP payloads have at most four 32-bit delay fields. Reserve more
    # than their possible emulation-prevention-byte growth across the clip.
    guard = math.ceil(Fraction(len(periods) * 32 * 8 * 90000, rate)) + 2
    duration = Fraction(size * 90000, rate)
    initial, selection = [], []
    for position, (group, values) in enumerate(counted.items()):
        prefix, lower = 0, Fraction(1)
        total = sum(values)
        period_set = set(periods)
        upper = min(duration, Fraction((1 << hrd["initial"]) - 1))
        for index, value in enumerate(values):
            elapsed = index * vm.frame_duration * 90000
            lower = max(lower, Fraction((prefix + value) * 90000, rate) - elapsed)
            if total - prefix > size or index in period_set:
                upper = min(upper, Fraction((prefix + size) * 90000, rate) - elapsed)
            prefix += value
        lo, hi = math.ceil(lower) + guard, math.floor(upper) - guard
        lo = max(lo, math.ceil(duration) - (1 << hrd["initial"]) + 1)
        if lo > hi:
            raise ValueError("No guarded initial-delay interval for the fixed CBR CPB")
        chosen = max(lo, min(hi, old_initial[position]))
        initial.append(chosen)
        selection.append({"group": group, "encoder_initial_delay": old_initial[position],
                          "chosen_initial_delay": chosen, "guard_ticks_90khz": guard,
                          "feasible_integer_interval_with_guard": [lo, hi]})
    vm = CbrRetimer(infos, frame_duration, initial_override=initial)
    rewritten = [vm.rewrite(sample, index) for index, sample in enumerate(samples)]
    vm.initial_selection = selection
    return rewritten, vm
