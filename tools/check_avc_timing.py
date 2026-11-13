"""Purpose: compare AVC timing SEI with the MP4 sample timeline.

Usage: python tools/check_avc_timing.py INPUT.MP4 --output REPORT.json.
Design: parse FFmpeg syntax traces, follow buffering-period resets and delay
    counters, and compare their cadence with container decode/presentation times.
Scope: the supported HRD/timing syntax only. Does not implement CPB occupancy,
    complete AVC conformance, hardware decoding or camera admission.
"""
import argparse
import hashlib
import json
import re
import subprocess
from fractions import Fraction
from pathlib import Path

from sony_mp4 import MP4

FIELD = re.compile(r"\]\s+\d+\s+([A-Za-z][A-Za-z_0-9\[\]]*)\s+[01]+\s+=\s+(-?\d+)")
PACKET = re.compile(r"\] Packet:.*?\bpts (-?\d+), dts (-?\d+), duration (\d+)\.")
HRD_FIELDS = {"cpb_cnt_minus1", "bit_rate_scale", "cpb_size_scale",
              "initial_cpb_removal_delay_length_minus1", "cpb_removal_delay_length_minus1",
              "dpb_output_delay_length_minus1", "time_offset_length"}


def parse_trace(lines):
    sps_list, packets, errors = [], [], []
    sps, packet, section, group, item = None, None, None, None, None
    for line in lines:
        if "] Packet:" in line:
            match = PACKET.search(line)
            if not match:
                errors.append("Packet timestamp line could not be parsed")
                packet = None
            else:
                pts, dts, duration = map(int, match.groups())
                packet = {"pts": pts, "dts": dts, "duration": duration,
                          "buffering_periods": [], "picture_timings": []}
                packets.append(packet)
            section, group, item = None, None, None
            continue
        if line.rstrip().endswith("] Sequence Parameter Set"):
            sps = {"fields": {}, "hrd": {}}
            sps_list.append(sps)
            section, group, item = "sps", None, None
            continue
        if line.rstrip().endswith("] Buffering Period"):
            section, group = "bp", None
            item = {"initial_delay": [], "initial_offset": []}
            if packet is None:
                errors.append("Buffering period outside a packet")
            else:
                packet["buffering_periods"].append(item)
            continue
        if line.rstrip().endswith("] Picture Timing"):
            section, group, item = "pt", None, {}
            if packet is None:
                errors.append("Picture timing outside a packet")
            else:
                packet["picture_timings"].append(item)
            continue
        match = FIELD.search(line)
        if not match:
            if "[trace_headers " in line and "] " in line:
                section, group, item = None, None, None
            continue
        name, raw = match.groups()
        value = int(raw)
        if section == "sps":
            if name in {"nal_hrd_parameters_present_flag", "vcl_hrd_parameters_present_flag"}:
                group = name[:3] if value else None
                if group is not None:
                    sps["hrd"][group] = {}
                sps["fields"][name] = value
            elif group is not None and (
                    name in HRD_FIELDS or name.startswith(("bit_rate_value_minus1[",
                                                           "cpb_size_value_minus1[", "cbr_flag["))):
                sps["hrd"][group][name] = value
            else:
                group = None
                sps["fields"][name] = value
        elif section == "bp" and item is not None:
            if name == "seq_parameter_set_id":
                item["sps_id"] = value
            elif name.startswith("initial_cpb_removal_delay_offset["):
                item["initial_offset"].append(value)
            elif name.startswith("initial_cpb_removal_delay["):
                item["initial_delay"].append(value)
        elif section == "pt" and item is not None:
            if name in {"cpb_removal_delay", "dpb_output_delay"}:
                item[name] = value
    return sps_list, packets, errors


def evaluate(sps_list, packets, timescale, expected_samples):
    unsupported, failures = [], []
    unique = {json.dumps(sps, sort_keys=True) for sps in sps_list}
    if len(unique) != 1:
        unsupported.append("Requires one unchanging parsed SPS")
    sps = sps_list[0] if sps_list else {"fields": {}, "hrd": {}}
    fields, groups = sps["fields"], sps["hrd"]
    tick = None
    required_timing = ("num_units_in_tick", "time_scale", "seq_parameter_set_id")
    if not all(name in fields for name in required_timing):
        unsupported.append("Missing SPS timing or identity")
    elif fields["time_scale"] <= 0 or fields["num_units_in_tick"] <= 0 or timescale <= 0:
        unsupported.append("Invalid timing scale")
    else:
        tick = Fraction(fields["num_units_in_tick"], fields["time_scale"])
    if fields.get("frame_mbs_only_flag") != 1 or fields.get("pic_struct_present_flag") != 0:
        unsupported.append("Requires progressive frame syntax without pic_struct")
    if not groups:
        unsupported.append("No parsed HRD")
    for name, group in groups.items():
        required = HRD_FIELDS | {"bit_rate_value_minus1[0]", "cpb_size_value_minus1[0]", "cbr_flag[0]"}
        if not required.issubset(group):
            unsupported.append(f"Incomplete {name} HRD")
        elif group["cpb_cnt_minus1"] != 0:
            unsupported.append(f"Only one CPB per HRD is supported: {name}")
    width_keys = ("cpb_removal_delay_length_minus1", "dpb_output_delay_length_minus1")
    if len(groups) == 2 and any(groups["nal"].get(key) != groups["vcl"].get(key) for key in width_keys):
        unsupported.append("NAL/VCL timing widths differ")
    count_match = expected_samples > 0 and len(packets) == expected_samples
    if not count_match:
        failures.append({"error": "Parsed packet count does not match nonempty sample table"})
    bp_count = 0
    if not unsupported and packets:
        width = next(iter(groups.values()))["cpb_removal_delay_length_minus1"] + 1
        anchor_dts = packets[0]["dts"]
        previous_dts = None
        for index, packet in enumerate(packets):
            errors = []
            pts, dts = packet["pts"], packet["dts"]
            bps, timings = packet["buffering_periods"], packet["picture_timings"]
            if previous_dts is not None and dts <= previous_dts:
                errors.append("Non-increasing container DTS")
            previous_dts = dts
            if len(timings) != 1:
                errors.append("Requires exactly one picture-timing SEI per packet")
            else:
                timing = timings[0]
                expected_cpb = Fraction(dts - anchor_dts, timescale) / tick
                expected_dpb = Fraction(pts - dts, timescale) / tick
                if expected_cpb.denominator != 1:
                    errors.append("DTS interval is not an integer AVC clock-tick count")
                elif timing.get("cpb_removal_delay") != int(expected_cpb) % (1 << width):
                    errors.append("CPB removal delay disagrees with DTS / previous buffering period")
                if expected_dpb.denominator != 1 or timing.get("dpb_output_delay") != expected_dpb:
                    errors.append("DPB output delay disagrees with PTS minus DTS")
            if len(bps) > 1 or (index == 0 and len(bps) != 1):
                errors.append("Requires first-packet buffering period and no duplicate periods")
            for bp in bps:
                bp_count += 1
                if bp.get("sps_id") != fields["seq_parameter_set_id"]:
                    errors.append("Buffering period refers to a different SPS")
                if len(bp["initial_delay"]) != len(groups) or len(bp["initial_offset"]) != len(groups):
                    errors.append("Buffering-period HRD delay-pair count mismatch")
                for position, (_, group) in enumerate(groups.items()):
                    if position >= len(bp["initial_delay"]) or position >= len(bp["initial_offset"]):
                        continue
                    maximum = 1 << (group["initial_cpb_removal_delay_length_minus1"] + 1)
                    delay, offset = bp["initial_delay"][position], bp["initial_offset"][position]
                    if not 0 < delay < maximum or not 0 <= offset < maximum:
                        errors.append("Initial delay/offset is outside its supported range")
                anchor_dts = dts
            if errors:
                failures.append({"sample_index": index, "pts": pts, "dts": dts, "errors": errors})
    return {"scope": "Selected SEI-versus-container timing checks only; not Annex C occupancy",
            "applicable": not unsupported, "unsupported_reasons": unsupported,
            "parsed_packets": len(packets), "expected_samples": expected_samples,
            "packet_count_matches": count_match, "buffering_period_count": bp_count,
            "clock_tick": str(tick) if tick else None, "sps": sps,
            "failures": failures, "passed_selected_checks": not unsupported and not failures,
            "annex_c_buffer_occupancy_checked": False, "camera_playback": "NOT_TESTED"}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("input")
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    source, output = Path(args.input).resolve(), Path(args.output).resolve()
    log = output.with_suffix(".log")
    if source in (output, log) or output == log:
        raise ValueError("Input and reports must be distinct")
    media = MP4(source)
    try:
        tracks = [track for track in media.tracks if track.handler == "vide"]
        if len(tracks) != 1 or tracks[0].codec != "avc1":
            raise ValueError("Requires a single avc1 video track")
        timescale, count = tracks[0].timescale, len(tracks[0].sizes)
    finally:
        media.close()
    command = ["ffmpeg", "-hide_banner", "-nostats", "-v", "info", "-i", str(source),
               "-map", "0:v:0", "-c:v", "copy", "-bsf:v", "trace_headers", "-f", "null", "-"]
    output.parent.mkdir(parents=True, exist_ok=True)
    with log.open("w", encoding="utf-8") as stream:
        result = subprocess.run(command, stdout=subprocess.DEVNULL, stderr=stream)
    with log.open(encoding="utf-8", errors="replace") as stream:
        sps_list, packets, errors = parse_trace(stream)
    report = evaluate(sps_list, packets, timescale, count)
    with source.open("rb") as stream:
        digest = hashlib.file_digest(stream, "sha256").hexdigest()
    report.update(input=str(source), sha256=digest, command=command,
                  trace_log=str(log), ffmpeg_exit_code=result.returncode,
                  trace_parse_errors=errors)
    with log.open("rb") as stream:
        report["trace_sha256"] = hashlib.file_digest(stream, "sha256").hexdigest()
    report["passed_selected_checks"] &= result.returncode == 0 and not errors
    output.write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps({key: report[key] for key in
                      ("input", "parsed_packets", "buffering_period_count", "clock_tick",
                       "unsupported_reasons", "failures", "passed_selected_checks")}, indent=2))
    if not report["passed_selected_checks"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
