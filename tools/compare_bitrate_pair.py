"""Read-only, fail-closed evidence for a matched PROF bitrate diagnostic pair.

Usage: python tools/compare_bitrate_pair.py --a PACKAGE --b PACKAGE --output REPORT.
Only parsed VPRF payload words 20/24 and TargetMaterial UMID attribute bytes
may differ. This proves pair isolation, not HRD conformance or camera playback.
"""
import argparse
from contextlib import ExitStack, contextmanager
import hashlib
import json
from pathlib import Path, PureWindowsPath
import re
import struct
from uuid import UUID
from xml.etree import ElementTree as ET
from xml.parsers import expat

from avc_hrd import nals
from bitrate_experiment import ExperimentSpec, package_spec
from sony_mp4 import MP4
from sony_profiles import get_profile
from sony_verification import digest, equal_ranges, track_payload_hash

PROF_UUID = bytes.fromhex("50524f4621d24fcebb88695cfac9c740")
UMID_LABEL = bytes.fromhex("060a2b340101010501010d2313000000")
NRT = "urn:schemas-professionalDisc:nonRealTimeMeta:ver.2.00"
BLOCK = 1024 * 1024
_UNDECLARED = object()


def _canonical_hash(value):
    return hashlib.sha256(json.dumps(value, sort_keys=True, separators=(",", ":"),
                                     allow_nan=False).encode("utf-8")).hexdigest()


def _local(path):
    # Check the spelling as well as the resolved target before opening anything.
    if PureWindowsPath(str(path)).drive.upper() == "F:":
        raise ValueError("Offline comparison refuses card paths")
    resolved = Path(path).resolve()
    if resolved.drive.upper() == "F:":
        raise ValueError("Offline comparison refuses card paths")
    return resolved


def _json(path):
    def unique(pairs):
        value = {}
        for key, item in pairs:
            if key in value:
                raise ValueError("Duplicate JSON key: " + key)
            value[key] = item
        return value
    return json.loads(path.read_text(encoding="utf-8"), object_pairs_hook=unique,
                      parse_constant=lambda x: (_ for _ in ()).throw(
                          ValueError("Non-finite JSON value: " + x)))


def _resource(path, expected=_UNDECLARED):
    if expected is not _UNDECLARED and (
            not isinstance(expected, str) or re.fullmatch(r"[0-9a-f]{64}", expected) is None):
        raise ValueError("Required declared hash must be a SHA-256 hex digest")
    path = _local(path)
    value = {"path": str(path), "size": path.stat().st_size, "sha256": digest(path)}
    if expected is not _UNDECLARED and value["sha256"] != expected:
        raise ValueError("Stale declared hash: " + str(path))
    return value


def _load_package(root):
    root = _local(root)
    manifest_path = root / "build-manifest.json"
    manifest_binding = _resource(manifest_path)
    manifest = _json(manifest_path)
    if not isinstance(manifest, dict):
        raise ValueError("Package manifest must be an object")
    if not isinstance(manifest.get("hrd_retiming"), dict):
        raise ValueError("Missing HRD retiming controls")
    spec = package_spec(manifest)
    if spec is None:
        raise ValueError("Pair requires two bitrate_diagnostic manifests")
    clip = manifest.get("clip", "")
    if not isinstance(clip, str) or re.fullmatch(r"C[0-9]{4}", clip) is None:
        raise ValueError("Unsafe or missing clip name")
    binding = {
        "build": str(root), "manifest": manifest_binding,
        "experiment_spec": spec.to_dict(),
        "experiment_spec_sha256": _canonical_hash(spec.to_dict()),
        "coding_fields": spec.coding_fields(),
        "coding_fields_sha256": _canonical_hash(spec.coding_fields()),
        "coding_profile": spec.coding_profile().manifest_fields(),
        "files": {
            clip + ".MP4": _resource(root / (clip + ".MP4"), manifest["sha256"]),
            clip + "M01.XML": _resource(root / (clip + "M01.XML")),
            clip + "T01.JPG": _resource(root / (clip + "T01.JPG")),
        },
        "base": _resource(manifest["base"], manifest["base_sha256"]),
        "source_spec": _resource(manifest["experiment_spec_path"],
                                 manifest["experiment_spec_sha256"]),
    }
    source_spec = ExperimentSpec.from_dict(_json(Path(binding["source_spec"]["path"])))
    if source_spec != spec:
        raise ValueError("Source spec disagrees with embedded experiment_spec")
    assumptions_path = Path(binding["base"]["path"]).parent / "input-assumptions.json"
    binding["encoder_assumptions"] = _resource(
        assumptions_path, manifest["encoder_assumptions_sha256"])
    assumptions = _json(assumptions_path)
    if not isinstance(assumptions, dict):
        raise ValueError("Encoder assumptions must be an object")
    encoded_spec = ExperimentSpec.from_dict(assumptions.get("experiment_spec"))
    if (encoded_spec.coding_fields() != spec.coding_fields() or
            assumptions.get("profile_parameters") != spec.coding_profile().manifest_fields()):
        raise ValueError("Encoder assumptions disagree with coding controls")
    evidence = manifest.get("diagnostic_evidence")
    if not isinstance(evidence, dict) or set(evidence) != {
            "peer_build", "pair_report", "reader_report"}:
        raise ValueError("Missing diagnostic evidence locations")
    binding["diagnostic_evidence"] = {}
    for key, value in evidence.items():
        if not isinstance(value, str) or not Path(value).is_absolute():
            raise ValueError("Diagnostic evidence paths must be absolute")
        binding["diagnostic_evidence"][key] = str(_local(value))
    return root, manifest, spec, binding


@contextmanager
def _media(path):
    # MP4.__init__ can fail after opening/mapping a file; close partial objects too.
    media = MP4.__new__(MP4)
    try:
        MP4.__init__(media, path)
        yield media
    finally:
        if hasattr(media, "buf"):
            media.buf.close()
        if hasattr(media, "file"):
            media.file.close()


def _box_digest(media, item):
    value = hashlib.sha256()
    for p in range(item.start, item.end, BLOCK):
        value.update(media.buf[p:min(p + BLOCK, item.end)])
    return value.hexdigest()


def _xml_identity(raw, spec):
    """Use the XML parser's byte index, never a global UMID search/replace."""
    parser = expat.ParserCreate(namespace_separator="}")
    positions = []

    def start(name, attrs):
        if name == NRT + "}TargetMaterial":
            positions.append(parser.CurrentByteIndex)

    def no_doctype(*unused):
        raise ValueError("DTD is not permitted in diagnostic XML")

    parser.StartElementHandler = start
    parser.StartDoctypeDeclHandler = no_doctype
    parser.Parse(raw, True)
    root = ET.fromstring(raw)
    target_tag = "{" + NRT + "}TargetMaterial"
    targets = list(root.iter(target_tag))
    if (root.tag != "{" + NRT + "}NonRealTimeMeta" or len(targets) != 1 or
            targets[0] not in list(root) or len(positions) != 1):
        raise ValueError("Expected one direct NRT TargetMaterial")
    target = targets[0]
    umid = target.get("umidRef", "")
    if re.fullmatch(r"[0-9a-fA-F]{64}", umid) is None:
        raise ValueError("TargetMaterial must contain a 32-byte hex UMID")
    identity = bytes.fromhex(umid)
    material = UUID(bytes=identity[16:])
    if identity[:16] != UMID_LABEL or material.version != 4:
        raise ValueError("Expected EDIUS-label UUID4 UMID")
    creation = list(root.iter("{" + NRT + "}CreationDate"))
    if (root.get("lastUpdate") != spec.creation_time or len(creation) != 1 or
            creation[0].get("value") != spec.creation_time):
        raise ValueError("XML dates must equal the experiment creation_time")
    offset = positions[0]
    tag = re.match(rb"<[^\s/>]+(?:[^<>\"']|\"[^\"]*\"|'[^']*')*>", raw[offset:])
    if tag is None:
        raise ValueError("Cannot locate TargetMaterial start tag")
    attrs = list(re.finditer(rb"([^\s=<>/]+)\s*=\s*(?:\"([^\"]*)\"|'([^']*)')",
                             tag.group()))
    matches = [item for item in attrs if item[1] == b"umidRef"]
    if len(matches) != 1:
        raise ValueError("Cannot locate the precise umidRef attribute")
    item = matches[0]
    group = 2 if item[2] is not None else 3
    if item[group] != umid.encode("ascii"):
        raise ValueError("UMID must be literal ASCII hex, not entity encoded")
    span = (offset + item.start(group), 64)

    def signature(node):
        attributes = dict(node.attrib)
        if node is target:
            attributes["umidRef"] = "<pair-identity>"
        return (node.tag, sorted(attributes.items()), node.text, node.tail,
                [signature(child) for child in node])
    return umid, span, signature(root)


def _prof(media, spec):
    prof = [b for b in media.top if b.kind == "uuid" and
            media.buf[b.data:b.data + 16] == PROF_UUID]
    if len(prof) != 1:
        raise ValueError("Expected exactly one top-level PROF UUID")
    prof = prof[0]
    vprf = media.one(media.boxes(prof.data + 24, prof.end), "VPRF")
    data = media.payload(vprf)
    baseline = get_profile(spec.base_profile)
    if (len(data) != 44 or data[:15] !=
            bytes.fromhex("000000000000000161766331016400") or
            data[15] != baseline.level_idc or data[16:20] != b"\0\3\0\2" or
            struct.unpack_from(">4IHH", data, 20) != (
                spec.prof_average_kbps, spec.prof_maximum_kbps,
                baseline.prof_fps, baseline.prof_fps, baseline.width, baseline.height)):
        raise ValueError("VPRF structure/declarations disagree with experiment_spec")
    return prof, [
        {"field": "VPRF.prof_average_kbps", "offset": vprf.data + 20, "length": 4},
        {"field": "VPRF.prof_maximum_kbps", "offset": vprf.data + 24, "length": 4},
    ]


def _rate_report(track):
    if (track.handler, track.codec) != ("vide", "avc1"):
        raise ValueError("Expected AVC video as first track")
    avcc = track.avcc()
    if len(avcc) < 5 or (avcc[4] & 3) != 3 or track.duration <= 0 or track.timescale <= 0:
        raise ValueError("Expected four-byte AVC lengths and positive decode duration")
    durations = (delta for count, delta in track.stts for _ in range(count))
    rows, counts, tick = [], {}, 0
    for i, delta in enumerate(durations):
        if delta <= 0:
            raise ValueError("Non-positive video sample decode duration")
        units = nals(track.sample(i), 4)
        values = {"video": track.sizes[i], "nal": 0, "vcl": 0, "filler": 0}
        for unit in units:
            kind = unit[0] & 31
            counts[str(kind)] = counts.get(str(kind), 0) + 1
            values["nal"] += len(unit)
            if kind in {1, 2, 3, 4, 5, 19, 20, 21}:
                values["vcl"] += len(unit)
            if kind == 12:
                values["filler"] += len(unit)
        rows.append((tick, values))
        tick += delta
    if not rows:
        raise ValueError("Empty video track")
    total = {name: sum(row[name] for _, row in rows) for name in rows[0][1]}
    peaks = {name: {"bytes": 0, "start_decode_tick": 0} for name in total}
    running, right = dict.fromkeys(total, 0), 0
    # Half-open [DTS, DTS + one second) windows, charging complete access units.
    for left, (start, values) in enumerate(rows):
        while right < len(rows) and rows[right][0] < start + track.timescale:
            for name in total:
                running[name] += rows[right][1][name]
            right += 1
        for name in total:
            if running[name] > peaks[name]["bytes"]:
                peaks[name] = {"bytes": running[name], "start_decode_tick": start}
        for name in total:
            running[name] -= values[name]
    return {
        "timescale": track.timescale, "duration_ticks": track.duration,
        "duration_seconds": track.duration / track.timescale, "samples": len(rows),
        "byte_totals": total, "nal_type_counts": counts,
        "average_bps": {name: size * 8 * track.timescale / track.duration
                        for name, size in total.items()},
        "one_second_decode_window_peak": {
            name: {**value, "bps": value["bytes"] * 8} for name, value in peaks.items()},
        "accounting": {
            "video": "MP4 video samples including four-byte NAL length prefixes",
            "nal": "All NAL bytes including NAL headers, excluding MP4 prefixes",
            "vcl": "NAL types 1-5,19-21; filler excluded",
            "filler": "NAL type 12 only",
            "window": "Whole samples at DTS in [start,start+1s); tail zero padded to 1s",
        },
    }


def _diff(a, b, allowed):
    """Bounded-memory byte comparison; report exact counts and bounded previews."""
    allowed = sorted(allowed, key=lambda item: item["offset"])
    previous = 0
    for item in allowed:
        start, length = item["offset"], item["length"]
        if start < previous or length <= 0 or start + length > min(len(a), len(b)):
            raise ValueError("Invalid or overlapping allowed byte ranges")
        previous = start + length
    changed, unexpected, regions, active = 0, 0, [], None
    for offset in range(0, max(len(a), len(b)), BLOCK):
        aa, bb = a[offset:offset + BLOCK], b[offset:offset + BLOCK]
        if aa == bb:
            active = None
            continue
        for i in range(max(len(aa), len(bb))):
            x, y = aa[i:i + 1], bb[i:i + 1]
            if x == y:
                active = None
                continue
            position = offset + i
            permitted = any(r["offset"] <= position < r["offset"] + r["length"]
                            for r in allowed)
            changed += 1
            unexpected += not permitted
            if active is None or active["offset"] + active["length"] != position or (
                    active["allowed"] != permitted):
                active = {"offset": position, "length": 0, "allowed": permitted,
                          "a_hex": "", "b_hex": ""}
                regions.append(active)
            active["length"] += 1
            if active["length"] <= 64:
                active["a_hex"] += x.hex()
                active["b_hex"] += y.hex()
    for region in regions:
        region["hex_truncated"] = region["length"] > 64
    return {"size_a": len(a), "size_b": len(b), "actual_changed_bytes": changed,
            "unexpected_changed_bytes": unexpected, "changed_regions": regions,
            "equal_after_precise_masks": len(a) == len(b) and unexpected == 0}


def _allowed(file, regions, a, b):
    return [{"file": file, **item,
             "a_hex": a[item["offset"]:item["offset"] + item["length"]].hex(),
             "b_hex": b[item["offset"]:item["offset"] + item["length"]].hex()}
            for item in regions]


def _compare(a, b, report):
    packages = [_load_package(root) for root in (a, b)]
    (aroot, am, asp, ab), (broot, bm, bsp, bb) = packages
    report.update(a=ab, b=bb)
    checks = report["checks"]
    checks["ordered_variants_A_B"] = (asp.variant, bsp.variant) == ("A", "B")
    checks["coding_fields_identical"] = asp.coding_fields() == bsp.coding_fields()
    checks["different_clip_names"] = am["clip"] != bm["clip"]
    checks["same_base_and_encoder_assumptions"] = (
        ab["base"] == bb["base"] and ab["encoder_assumptions"] == bb["encoder_assumptions"])
    checks["reciprocal_peer_and_shared_pair_report"] = (
        ab["diagnostic_evidence"]["peer_build"] == str(broot) and
        bb["diagnostic_evidence"]["peer_build"] == str(aroot) and
        ab["diagnostic_evidence"]["pair_report"] == bb["diagnostic_evidence"]["pair_report"])
    excluded = {"clip", "umid", "sha256", "experiment_spec", "experiment_spec_path",
                "experiment_spec_sha256", "diagnostic_evidence"}
    checks["other_manifest_fields_identical"] = (
        {k: v for k, v in am.items() if k not in excluded} ==
        {k: v for k, v in bm.items() if k not in excluded})
    with ExitStack() as stack:
        media = []
        for root, manifest, spec, binding in packages:
            m = stack.enter_context(_media(root / (manifest["clip"] + ".MP4")))
            media.append(m)
        ma, mb = media
        checks["top_level_layout_identical"] = (
            [(x.kind, x.start, x.size, x.header) for x in ma.top] ==
            [(x.kind, x.start, x.size, x.header) for x in mb.top])
        checks["moov_exact"] = ma.raw(ma.moov) == mb.raw(mb.moov)
        mdats = [[x for x in m.top if x.kind == "mdat"] for m in media]
        report["complete_mdat_boxes"] = {
            label: [{"offset": item.start, "size": item.size,
                     "sha256": _box_digest(m, item)} for item in boxes]
            for label, m, boxes in zip(("a", "b"), media, mdats)}
        checks["complete_mdat_boxes_exact"] = bool(mdats[0]) and (
            len(mdats[0]) == len(mdats[1]) and all(
                x.size == y.size and equal_ranges(ma.buf, x.start, mb.buf, y.start, x.size)
                for x, y in zip(*mdats)))
        checks["three_track_layout"] = all(
            [(t.handler, t.codec) for t in m.tracks] ==
            [("vide", "avc1"), ("soun", "twos"), ("meta", "rtmd")] for m in media)
        track_rows = []
        for m in media:
            track_rows.append([
                {"handler": t.handler, "codec": t.codec, "samples": len(t.sizes),
                 "payload_sha256": track_payload_hash(t),
                 "sample_description_sha256": hashlib.sha256(m.raw(t.entry)).hexdigest(),
                 "sample_tables_sha256": hashlib.sha256(m.raw(t.stbl)).hexdigest()}
                for t in m.tracks])
        report["tracks"] = {"a": track_rows[0], "b": track_rows[1]}
        checks["every_track_payload_sha_equal"] = (
            bool(track_rows[0]) and track_rows[0] == track_rows[1])
        checks["sample_descriptions_tables_and_mappings_exact"] = (
            len(ma.tracks) == len(mb.tracks) and all(
                ma.raw(x.stbl) == mb.raw(y.stbl) for x, y in zip(ma.tracks, mb.tracks)))
        profs, prof_regions = [], []
        embedded, sidecars, identities = [], [], []
        for m, (root, manifest, spec, binding) in zip(media, packages):
            prof, regions = _prof(m, spec)
            profs.append(prof)
            prof_regions.append(regions)
            meta = m.one(m.top, "meta")
            xml_box = m.child(meta, "xml ", 4)
            xml_start = xml_box.data + 4
            xml = m.buf[xml_start:xml_box.end].rstrip(b" \0")
            sidecar = _local(root / (manifest["clip"] + "M01.XML")).read_bytes()
            eu, es, et = _xml_identity(xml, spec)
            su, ss, st = _xml_identity(sidecar, spec)
            if eu != manifest["umid"] or su != eu or et != st or xml != sidecar.rstrip(b" \0"):
                raise ValueError("Embedded XML, sidecar and manifest identity/content disagree")
            identities.append(eu)
            embedded.append({"tree": et, "region": {
                "field": "meta.xml.TargetMaterial.umidRef",
                "offset": xml_start + es[0], "length": es[1]}})
            sidecars.append((sidecar, {"field": "TargetMaterial.umidRef",
                                      "offset": ss[0], "length": ss[1]}))
            video = m.tracks[0]
            baseline = get_profile(spec.base_profile)
            if (len(video.sizes) != manifest["frames"] or
                    (video.timescale, video.stts) !=
                    (baseline.timescale, [(len(video.sizes), baseline.fps_den)])):
                raise ValueError("Video count/cadence disagrees with experiment")
        checks["unique_uuid4_umids"] = bytes.fromhex(identities[0]) != bytes.fromhex(identities[1])
        checks["xml_structures_equal_except_target_umid"] = (
            embedded[0]["tree"] == embedded[1]["tree"])
        checks["allowed_field_offsets_identical"] = (
            prof_regions[0] == prof_regions[1] and
            embedded[0]["region"] == embedded[1]["region"] and
            sidecars[0][1] == sidecars[1][1])
        allowed = prof_regions[0] + [embedded[0]["region"]]
        report["allowed_diff_regions"] = _allowed("MP4", allowed, ma.buf, mb.buf)
        report["mp4_diff"] = _diff(ma.buf, mb.buf, allowed)
        checks["entire_mp4_equal_after_precise_masks"] = report["mp4_diff"]["equal_after_precise_masks"]
        checks["other_top_boxes_exact"] = (
            len(ma.top) == len(mb.top) and all(
                x.kind == y.kind and ma.raw(x) == mb.raw(y)
                for x, y in zip(ma.top, mb.top)
                if x is not profs[0] and x.kind != "meta"))
        sa, sr = sidecars[0]
        sb, unused = sidecars[1]
        report["allowed_diff_regions"] += _allowed("XML", [sr], sa, sb)
        report["xml_diff"] = _diff(sa, sb, [sr])
        checks["sidecar_equal_after_precise_umid_mask"] = report["xml_diff"]["equal_after_precise_masks"]
        jpgs = [binding["files"][manifest["clip"] + "T01.JPG"]
                for _, manifest, _, binding in packages]
        checks["thumbnails_exact"] = jpgs[0]["sha256"] == jpgs[1]["sha256"]
        report["rates"] = {"a": _rate_report(ma.tracks[0]), "b": _rate_report(mb.tracks[0])}
        checks["actual_rates_identical"] = report["rates"]["a"] == report["rates"]["b"]
        report["actual_changed_bytes"] = (
            report["mp4_diff"]["actual_changed_bytes"] + report["xml_diff"]["actual_changed_bytes"])
        # A fresh hash pass also detects inputs changed while the proof was built.
        resources = [item for _, _, _, binding in packages
                     for item in [binding["manifest"], binding["base"], binding["source_spec"],
                                  binding["encoder_assumptions"], *binding["files"].values()]]
        checks["bound_inputs_stable_during_comparison"] = all(
            _resource(item["path"]) == item for item in resources)


def compare_pair(a, b):
    """Return deterministic JSON-compatible evidence; malformed inputs fail closed."""
    report = {"bitrate_pair_schema": 1, "kind": "bitrate_pair_comparison",
              "checks": {}, "passed": False, "errors": [],
              "camera_playback": "NOT_TESTED",
              "scope": "Offline pair isolation only; no decoder/HRD or hardware acceptance proof"}
    try:
        _compare(a, b, report)
        report["passed"] = bool(report["checks"]) and all(report["checks"].values())
    except (OSError, ValueError, KeyError, TypeError, IndexError, struct.error,
            expat.ExpatError, ET.ParseError) as error:
        report["errors"].append(type(error).__name__ + ": " + str(error))
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--a", required=True)
    parser.add_argument("--b", required=True)
    parser.add_argument("--output", required=True)
    args = parser.parse_args()
    output = _local(args.output)
    # Reports must not overwrite any input, including source specs/assumptions.
    if output.exists():
        raise FileExistsError("Use a fresh report path")
    report = compare_pair(args.a, args.b)
    with output.open("x", encoding="utf-8") as stream:
        json.dump(report, stream, indent=2, allow_nan=False)
        stream.write("\n")
    print(json.dumps({"output": str(output), "passed": report["passed"]}))
    return 0 if report["passed"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
