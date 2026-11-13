"""Purpose: check selected one-CPB CBR buffering constraints for a local clip.

Usage: python tools/check_avc_cpb.py INPUT.MP4 --timing TIMING_REPORT.json
    --output REPORT.json.
Design: combine parsed timing with actual NAL/VCL bit counts, testing initial
    delay rounding and CPB overflow/underflow starting at each buffering period.
Scope: selected Annex-C-style checks for the supported model, not DPB/reference
    validation, complete H.264/Sony conformance or a camera playback verdict.
"""
import argparse
import hashlib
import json
import math
from collections import Counter
from fractions import Fraction
from pathlib import Path

from avc_hrd import nal_bits, nals
from check_avc_timing import evaluate, parse_trace
from sony_mp4 import MP4


def check_schedule(bits, packets, rate, size, timescale, position):
    if not bits or len(bits) != len(packets) or rate <= 0 or size <= 0:
        raise ValueError("Invalid or empty CPB input")
    if any(value <= 0 for value in bits):
        raise ValueError("Each access unit must have counted NAL data")
    starts = [i for i, packet in enumerate(packets) if packet["buffering_periods"]]
    if not starts or starts[0] != 0:
        raise ValueError("Missing initializing buffering period")
    counts, examples = Counter(), []
    peak, minimum_margin, checked = Fraction(0), None, 0
    cumulative = [0]
    for value in bits:
        cumulative.append(cumulative[-1] + value)
    for start in starts:
        delay = packets[start]["buffering_periods"][0]["initial_delay"][position]
        initial = Fraction(delay, 90000)
        total = cumulative[-1] - cumulative[start]
        for index in range(start, len(bits)):
            packet = packets[index]
            previous_bits = cumulative[index] - cumulative[start]
            removal = initial + Fraction(packet["dts"] - packets[start]["dts"], timescale)
            final_arrival = Fraction(previous_bits + bits[index], rate)
            margin = removal - final_arrival
            minimum_margin = margin if minimum_margin is None else min(minimum_margin, margin)
            occupancy = min(Fraction(total), rate * removal) - previous_bits
            peak = max(peak, occupancy)
            errors = []
            if margin < 0:
                errors.append("cpb_underflow")
            if occupancy > size:
                errors.append("cpb_overflow")
            delta = None
            if index > start and packet["buffering_periods"]:
                delta = 90000 * (removal - Fraction(previous_bits, rate))
                actual = packet["buffering_periods"][0]["initial_delay"][position]
                if not math.floor(delta) <= actual <= math.ceil(delta):
                    errors.append("C16_initial_delay_rounding")
            for error in errors:
                counts[error] += 1
            if errors and len(examples) < 12:
                examples.append({"initialization_sample": start, "sample_index": index,
                                 "errors": errors, "expected_delay_exact": str(delta),
                                 "signaled_initial_delay": packet["buffering_periods"][0][
                                     "initial_delay"][position] if packet["buffering_periods"] else None})
            checked += 1
    return {"rate_bits_per_second": rate, "capacity_bits": size,
            "initialization_points": len(starts), "access_unit_checks": checked,
            "peak_occupancy_bits_exact": str(peak),
            "minimum_arrival_margin_seconds_exact": str(minimum_margin),
            "failure_counts": dict(counts), "failure_examples": examples,
            "passed_selected_cpb_checks": not counts}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("input")
    ap.add_argument("--timing", required=True)
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    source, output = Path(args.input).resolve(), Path(args.output).resolve()
    if output in {source, Path(args.timing).resolve()}:
        raise ValueError("Report must not overwrite its input")
    timing = json.loads(Path(args.timing).read_text(encoding="utf-8"))
    with source.open("rb") as stream:
        digest = hashlib.file_digest(stream, "sha256").hexdigest()
    if digest != timing["sha256"] or not timing["passed_selected_checks"]:
        raise ValueError("Timing report is stale or not passing")
    log = Path(timing["trace_log"])
    if output == log.resolve():
        raise ValueError("Report must not overwrite its trace")
    with log.open("rb") as stream:
        if hashlib.file_digest(stream, "sha256").hexdigest() != timing["trace_sha256"]:
            raise ValueError("Timing trace changed")
    with log.open(encoding="utf-8", errors="replace") as stream:
        sps, packets, errors = parse_trace(stream)
    m = MP4(source)
    try:
        t = next(t for t in m.tracks if t.handler == "vide")
        syntax = evaluate(sps, packets, t.timescale, len(t.sizes))
        if errors or not syntax["passed_selected_checks"]:
            raise ValueError("Timing cannot be reproduced")
        if syntax["sps"]["fields"].get("low_delay_hrd_flag") != 0:
            raise ValueError("Only low_delay_hrd_flag=0 is supported")
        groups = syntax["sps"]["hrd"]
        length_size = (t.avcc()[4] & 3) + 1
        sizes = {name: [] for name in groups}
        totals = Counter()
        for index in range(len(t.sizes)):
            units = nals(t.sample(index), length_size)
            for nal in units:
                totals[nal[0] & 31] += len(nal)
            for name in groups:
                sizes[name].append(nal_bits(units, name))
        schedules = {}
        for position, (name, group) in enumerate(groups.items()):
            if group["cbr_flag[0]"] != 1:
                raise ValueError("This checker supports only CBR CPBs")
            rate = (group["bit_rate_value_minus1[0]"] + 1) << (6 + group["bit_rate_scale"])
            size = (group["cpb_size_value_minus1[0]"] + 1) << (4 + group["cpb_size_scale"])
            schedules[name] = check_schedule(sizes[name], packets, rate, size, t.timescale, position)
    finally:
        m.close()
    report = {"input": str(source), "sha256": digest, "timing_report": str(Path(args.timing).resolve()),
              "conformance_point": "NAL unit stream; MP4 length prefixes and Annex B bytes excluded",
              "scope": "Selected CBR CPB conditions only; no DPB/reference or full conformance check",
              "nal_bytes_by_type": dict(sorted(totals.items())), "schedules": schedules,
              "passed_selected_cpb_checks": all(x["passed_selected_cpb_checks"] for x in schedules.values()),
              "camera_playback": "NOT_TESTED"}
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps(report, indent=2))
    if not report["passed_selected_cpb_checks"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
