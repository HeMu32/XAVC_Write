"""Compare explicit HD29.97 candidates with a hash-bound native 16M reference."""
import argparse
import hashlib
import json
from pathlib import Path
import struct

from sony_mp4 import MP4
from sony_profiles import manifest_profile


def inspect(path):
    media = MP4(path)
    try:
        video = next(track for track in media.tracks if track.handler == "vide")
        prof = media.one(media.top, "uuid")
        vprf = media.payload(media.one(media.boxes(prof.data + 24, prof.end), "VPRF"))
        return {
            "path": str(path), "sha256": hashlib.sha256(media.buf).hexdigest(),
            "dimensions": list(struct.unpack_from(">HH", media.payload(video.entry), 24)),
            "avcc_profile_level": list(video.avcc()[1:4]),
            "nal_length_size": (video.avcc()[4] & 3) + 1,
            "timescale": video.timescale, "duration_ticks": video.duration,
            "frames": len(video.sizes), "stts": video.stts,
            "first_sync_samples": video.sync[:8], "vprf_hex": vprf.hex(),
            "vprf_rates_and_fps": list(struct.unpack_from(">4I", vprf, 20))}
    finally:
        media.close()


def sdk_properties(path, media):
    report = json.loads(path.read_text(encoding="utf-8"))
    if report["media_sha256"] != media["sha256"] or not report["passed_selected_reader_checks"]:
        raise ValueError("Original reader report failed or is not bound to current media")
    raw = bytes.fromhex(report["result"]["movie_property_hex"])
    return {"report": str(path), "media_sha256": report["media_sha256"],
            "video_enums": list(struct.unpack_from("<7I", raw, 0xc)),
            "nominal_bitrate_mbps": struct.unpack_from("<H", raw, 0x2c)[0],
            "original_code_unchanged": report["original_executable_sections_unchanged_after_all_probes"],
            "rtmd_probe": report.get("rtmd_probe"),
            "scope": "Bounded original read side, one selected I frame; not full hardware playback"}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--reference", default="analysis/C6501-reference-0028.MP4")
    ap.add_argument("--native-report", default="analysis/xavc-reader-C6501-basic-0028.json")
    ap.add_argument("--build", action="append", required=True)
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    reference, native_report, output = [Path(value).resolve() for value in
                                       (args.reference, args.native_report, args.output)]
    builds = [Path(value).resolve() for value in args.build]
    if any(path.drive.upper() == "F:" for path in [reference, native_report, output] + builds):
        raise ValueError("Only saved local evidence permitted")
    native = inspect(reference)
    native["sdk"] = sdk_properties(native_report, native)
    expected_enums = [0, 0, 2, 1, 0, 0, 3]
    rows = []
    for build in builds:
        manifest = json.loads((build / "build-manifest.json").read_text(encoding="utf-8"))
        selected = manifest_profile(manifest)
        media = inspect(build / (manifest["clip"] + ".MP4"))
        sdk = sdk_properties(build / "firmware-reader.json", media)
        checks = {
            "manifest_media_hash": media["sha256"] == manifest["sha256"],
            "native_hardware_format_family": sdk["video_enums"] == native["sdk"]["video_enums"] == expected_enums,
            "nominal_bitrate": sdk["nominal_bitrate_mbps"] * 1000 == selected.bitrate_kbps,
            "dimensions": media["dimensions"] == [1920, 1080],
            "sps_avcc_level": media["avcc_profile_level"] == [100, 0, selected.level_idc],
            "nal_length": media["nal_length_size"] == native["nal_length_size"] == 4,
            "cadence": media["timescale"] == native["timescale"] == 30000 and
                       media["stts"] == [(manifest["frames"], 1001)],
            "prof_fps": media["vprf_rates_and_fps"][2:] == native["vprf_rates_and_fps"][2:],
            "original_code_unchanged": sdk["original_code_unchanged"],
        }
        if selected.name == "hd16_2997":
            checks["native_16m_vprf_bit_exact"] = media["vprf_hex"] == native["vprf_hex"]
        rows.append({"clip": manifest["clip"], "profile": selected.name,
                     "media": media, "sdk": sdk, "checks": checks, "passed": all(checks.values())})
    report = {
        "native": native, "candidates": rows, "passed": all(row["passed"] for row in rows),
        "card_access": False, "camera_playback": "NOT_TESTED",
        "native_sensor_rtmd_full_probe": {
            "report": "analysis/xavc-reader-C6501-native-0028.json",
            "result": "EMULATION_WALL_TIME_BUDGET_EXHAUSTED_NOT_MEDIA_REJECTION",
            "scope": "A separately preserved attempt, not counted as a successful full RTMD probe"},
        "limits": [
            "No native HD29.97 50M reference was available; its level/GOP are explicit candidate settings.",
            "Matching VPRF and reader enums do not establish matching SPS/PPS, acquisition, GOP or camera admission.",
            "Native C6501 is full-range; candidates deliberately retain the previously used Rec.709 limited-range encoding path."
        ]}
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps({"passed": report["passed"], "clips": [
        {"clip": row["clip"], "checks": row["checks"]} for row in rows]}, indent=2))
    if not report["passed"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
