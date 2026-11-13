"""Purpose: build a new-identity control from a camera-native source clip.

Usage: python tools/build_native_control.py --source LOCAL_NATIVE.MP4
    --snapshot SNAP --clip Cnnnn --output NEW_DIRECTORY.
Design: retain native coded samples and structural evidence, changing only the
    explicitly modeled identity/header metadata and producing a build manifest.
Scope: local experimental control construction, not re-encoding or deployment.
    Requires the supported source layout; no generic-input compatibility claim.
"""
import argparse
import hashlib
import json
import shutil
from datetime import datetime, timezone, timedelta
from pathlib import Path
from xml.etree import ElementTree as ET

from build_sony_clip import patched_header
from sony_mp4 import MP4, box, fullbox
from sony_umid import make_umid


def update_headers(media, item, stamp):
    if item.kind in {"mvhd", "mdhd", "tkhd"}:
        return patched_header(media, item, stamp=stamp)
    if item.kind in {"moov", "trak", "mdia"}:
        return box(item.kind, b"".join(update_headers(media, child, stamp)
                                      for child in media.children(item)))
    return media.raw(item)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--source", required=True)
    ap.add_argument("--snapshot", required=True)
    ap.add_argument("--clip", required=True)
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    source, output = Path(args.source).resolve(), Path(args.output).resolve()
    if output.exists() or output == source.parent or source.drive == output.drive:
        raise ValueError("Use a fresh workspace directory outside the source card")
    original = MP4(source)
    try:
        if original.top[-1].kind != "meta":
            raise ValueError("Native control requires trailing top-level NRT metadata")
        meta = original.top[-1]
        xml_box = original.child(meta, "xml ", 4)
        xml = original.payload(xml_box)[4:].rstrip(b" \x00")
        root = ET.fromstring(xml)
        def node(name):
            return next(x for x in root.iter() if x.tag.rsplit("}", 1)[-1] == name)
        device = node("Device").attrib
        if device.get("manufacturer") != "Sony" or not device.get("modelName", "").startswith("ILCE-"):
            raise ValueError("Not the expected Sony native source")
        source_sidecar = Path(args.snapshot) / f"PRIVATE/M4ROOT/CLIP/{source.stem}M01.XML"
        if source_sidecar.read_bytes().rstrip(b" \x00") != xml:
            raise ValueError("Native embedded XML differs from snapshot sidecar")
        acquisition = {x.get("name"): x.get("value") for x in root.iter()
                       if x.tag.rsplit("}", 1)[-1] == "Item"}
        if any(acquisition.get(name) != "rec709" for name in
               ("CaptureGammaEquation", "CaptureColorPrimaries", "CodingEquations")):
            raise ValueError("Control source must have native Rec.709 acquisition")
        stamp_dt = datetime.now(timezone(timedelta(hours=8))).replace(microsecond=0)
        stamp = stamp_dt.isoformat()
        old_umid = node("TargetMaterial").get("umidRef")
        umid = make_umid(stamp_dt, bytes.fromhex(old_umid)[24:]).hex().upper()
        node("TargetMaterial").set("umidRef", umid)
        node("CreationDate").set("value", stamp)
        root.set("lastUpdate", stamp)
        ns = root.tag.split("}")[0][1:]
        ET.register_namespace("", ns)
        ET.indent(root, space="\t")
        new_xml = b'<?xml version="1.0" encoding="UTF-8"?>\r\n' + ET.tostring(root, encoding="utf-8") + b"\r\n"
        new_meta = fullbox("meta", b"".join(
            fullbox("xml ", new_xml) if child.kind == "xml " else original.raw(child)
            for child in original.children(meta, 4)))
        output.mkdir(parents=True, exist_ok=False)
        target = output / (args.clip + ".MP4")
        qt_stamp = int(stamp_dt.timestamp()) + 2082844800
        with target.open("xb") as stream:
            for item in original.top:
                stream.write(new_meta if item == meta else update_headers(original, item, qt_stamp))
        (output / (args.clip + "M01.XML")).write_bytes(new_xml)
        thumbnail = source.parent.parent / "THMBNL" / (source.stem + "T01.JPG")
        shutil.copyfile(thumbnail, output / (args.clip + "T01.JPG"))
        video = original.tracks[0]
        frames = len(video.sizes)
        times = [x.attrib for x in root.iter() if x.tag.rsplit("}", 1)[-1] == "LtcChange"]
        source_hash = hashlib.sha256(original.buf).hexdigest()
        manifest = {
            "clip": args.clip, "umid": umid, "stamp": stamp, "frames": frames,
            "duration_ticks": video.duration, "timescale": video.timescale,
            "audio_samples": len(original.tracks[1].sizes), "acquisition": "rec709",
            "start_timecode": times[0]["value"], "end_timecode": times[-1]["value"],
            "package_kind": "native_control", "base": str(source),
            "native_source_sha256": source_hash, "native_source_device": device,
            "native_source_sidecar": str(source_sidecar.resolve()),
            "native_source_sidecar_sha256": hashlib.sha256(source_sidecar.read_bytes()).hexdigest(),
            "source_umid": old_umid,
            "video_bitrate": sum(video.sizes) * 8 * video.timescale / video.duration,
            "sha256": hashlib.sha256(target.read_bytes()).hexdigest(),
            "changes": ["new UMID and NRT dates", "container creation/modification times"],
            "preserved": ["entire mdat including padding", "all native tracks/sample tables",
                          "native rtmd/sensor samples and timecodes", "native thumbnail"],
        }
        (output / "build-manifest.json").write_text(json.dumps(manifest, indent=2), encoding="utf-8")
        print(json.dumps(manifest, indent=2))
    finally:
        original.close()


if __name__ == "__main__":
    main()
