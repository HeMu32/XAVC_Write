"""Verify a locally prepared bitrate package while no current card is attached.

Usage: --build PACKAGE --experiment-spec SPEC --output NEW_REPORT.json.
This deliberately does not emit a deployable verification.json, allocate a
clip number, or assert anything about a live SD catalog or camera playback.
"""
import argparse
import json
import struct
from datetime import datetime
from pathlib import Path
from xml.etree import ElementTree as ET

from avc_hrd import nals
from bitrate_experiment import load_spec, package_profile, package_spec, require_diagnostic_evidence
from encode_xavc import probe_input
from sony_mp4 import MP4
from sony_nrt_codec import nrt_codec_matches
from sony_verification import digest, run_media_checks
from verify_sony_package import (
    NRT, edit_origin_checks, hash_audio, probe_profile_matches, prof_profile_matches,
    rec709_stream_matches, rtmd_profile_matches, sps_profile_matches,
    track_profile_checks, xml_profile_matches,
)


def vcl_equal(base, media):
    tracks = [m.tracks[0] for m in (base, media)]
    if len(tracks[0].sizes) != len(tracks[1].sizes):
        return False
    widths = [(t.avcc()[4] & 3) + 1 for t in tracks]
    for index in range(len(tracks[0].sizes)):
        payloads = [[nal for nal in nals(t.sample(index), width) if nal[0] & 31 in {1, 5}]
                    for t, width in zip(tracks, widths)]
        if not payloads[0] or payloads[0] != payloads[1]:
            return False
    return True


def verify(build, spec):
    build = Path(build).resolve()
    if build.drive.upper() == "F:":
        raise ValueError("Only local media preparation is supported")
    info = json.loads((build / "build-manifest.json").read_text(encoding="utf-8"))
    if package_spec(info) != spec:
        raise ValueError("Explicit experiment spec disagrees with package")
    selected = package_profile(info)
    clip = info["clip"]
    media_path = build / (clip + ".MP4")
    checks, proof = run_media_checks(
        build, clip, info["base"], info["frames"], info["package_kind"])
    timing = json.loads((Path(proof["directory"]) / "timing.json").read_text(encoding="utf-8"))
    slices = json.loads((Path(proof["directory"]) / "slice-order.json").read_text(encoding="utf-8"))
    media, base, rtmd = MP4(media_path), MP4(info["base"]), MP4(info["rtmd_template"])
    try:
        checks.update(track_profile_checks(media, selected, info))
        checks.update(edit_origin_checks(media, base))
        sidecar = (build / (clip + "M01.XML")).read_bytes()
        embedded = media.payload(media.child(media.one(media.top, "meta"), "xml ", 4))[4:]
        root = ET.fromstring(embedded)
        prof = media.one(media.top, "uuid")
        fields = media.payload(media.one(media.boxes(prof.data + 24, prof.end), "VPRF"))
        stream = probe_input(media_path)
        qt_stamp = int(datetime.fromisoformat(spec.creation_time).timestamp()) + 2082844800
        headers = [media.child(media.moov, "mvhd")]
        headers += [media.child(t.box, "tkhd") for t in media.tracks]
        headers += [media.child(t.mdia, "mdhd") for t in media.tracks]
        sps_fields = timing["sps"]["fields"]
        checks.update({
            "audio_pcm_bit_exact_to_aligned_encoder_output":
                hash_audio(media) == hash_audio(base, info["audio_samples"]),
            "all_coded_vcl_nals_preserved_by_packaging": vcl_equal(base, media),
            "embedded_xml_bit_exact_to_sidecar": embedded == sidecar,
            "xml_profile_and_duration": xml_profile_matches(root, selected, info["frames"]),
            "sony_xml_codec_name_supported": nrt_codec_matches(root, selected),
            "xml_umid": root.find(f"{{{NRT}}}TargetMaterial").get("umidRef") == info["umid"],
            "xml_dates": root.get("lastUpdate") == spec.creation_time and
                root.find(f"{{{NRT}}}CreationDate").get("value") == spec.creation_time,
            "container_dates": all(
                struct.unpack_from(">II", media.payload(h), 4) == (qt_stamp, qt_stamp)
                for h in headers),
            "prof_matches_explicit_declarations": prof_profile_matches(
                fields, selected, spec.prof_average_kbps, spec.prof_maximum_kbps),
            "probed_avc_matches_profile": probe_profile_matches(stream, selected),
            "rec709_limited_range": rec709_stream_matches(stream),
            "dual_hrd_rates_and_buffers": sps_profile_matches(timing["sps"], selected),
            "rtmd_every_packet": rtmd_profile_matches(
                media.tracks[2], selected, info["frames"], rtmd.tracks[2].sample(0)),
            "four_slices_every_frame": slices["slice_count_histogram"] == {"4": info["frames"]},
            "gop_sync_samples": media.tracks[0].sync ==
                list(range(1, info["frames"] + 1, selected.gop_frames)),
            "reference_and_reorder_configuration":
                (sps_fields.get("max_num_ref_frames"), sps_fields.get("max_num_reorder_frames"),
                 sps_fields.get("max_dec_frame_buffering")) == (2, 1, 2),
            "structure_template_still_bound":
                digest(info["structure_template"]) == info["structure_template_sha256"],
            "media_still_matches_build": digest(media_path) == info["sha256"],
            "encoder_base_still_bound": digest(info["base"]) == info["base_sha256"],
        })
    finally:
        media.close()
        base.close()
        rtmd.close()
    evidence = info["diagnostic_evidence"]
    bound = {"diagnostic_evidence": {
        key + "_sha256": digest(evidence[key]) for key in ("pair_report", "reader_report")}}
    assessment = require_diagnostic_evidence(bound, build, info)
    checks["pair_and_exact_original_reader_evidence_bound"] = assessment["passed"] is True
    pair = json.loads(Path(evidence["pair_report"]).read_text(encoding="utf-8"))
    return {
        "media_verification_schema": 1, "scope": "MEDIA_ONLY_NO_CURRENT_CARD_CATALOG",
        "passed_media_checks": all(value is True for value in checks.values()),
        "deployment_admitted": False, "catalog_staged": False,
        "camera_playback": "NOT_TESTED", "clip_name_is_local_placeholder": True,
        "checks": checks, "frames": info["frames"],
        "duration_seconds": info["duration_ticks"] / info["timescale"],
        "audio_samples": info["audio_samples"], "audio_alignment": info["audio_alignment"],
        "media_path": str(media_path), "media_sha256": digest(media_path),
        "media_bytes": media_path.stat().st_size, "experiment_spec": spec.to_dict(),
        "rates": pair["rates"][spec.variant.lower()],
        "original_reader_assessment": assessment, **bound,
        "fresh_media_evidence": proof,
    }


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--build", required=True)
    ap.add_argument("--experiment-spec", required=True)
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    output = Path(args.output).resolve()
    if output.exists() or output.drive.upper() == "F:":
        raise ValueError("Use a fresh local report path")
    result = verify(args.build, load_spec(args.experiment_spec))
    output.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({key: result[key] for key in (
        "passed_media_checks", "frames", "duration_seconds", "media_bytes",
        "deployment_admitted", "catalog_staged")}, indent=2))
    if result["passed_media_checks"] is not True:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
