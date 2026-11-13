"""Purpose: inventory raw codec images and collect startup/identity evidence.

Usage: python tools/survey_vcd.py --root LOCAL_CODEC_DIRECTORY
    --output REPORT.json [--avcam FILE --warm-image FILE].
Design: bind hashes, version strings and bounded MIPS startup observations to
    the supplied local image corpus for subsequent targeted analysis.
Scope: read-only static survey; provisional mappings are not proven full memory
    maps, custom-instruction semantics or decoder/camera execution.
"""
import argparse
import hashlib
import json
import re
import struct
from pathlib import Path

import capstone
from capstone import Cs, CS_ARCH_MIPS, CS_MODE_MIPS32, CS_MODE_LITTLE_ENDIAN


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--root", default="firmware/m4-v602/usr/codec")
    ap.add_argument("--output", required=True)
    ap.add_argument("--avcam")
    ap.add_argument("--warm-image")
    args = ap.parse_args()
    result = {"capstone_version": capstone.__version__,
              "unblob": "Not installed; manual read-only survey, no extraction performed",
              "active_image_on_camera": "NOT_ESTABLISHED", "images": []}
    md = Cs(CS_ARCH_MIPS, CS_MODE_MIPS32 | CS_MODE_LITTLE_ENDIAN)
    for path in sorted(Path(args.root).glob("vcd_firmware*.bin")):
        data = path.read_bytes()
        strings = [{"offset": hex(m.start()), "text": m.group().decode("ascii")}
                   for m in re.finditer(rb"[ -~]{6,}", data)]
        selected = [s for s in strings if re.search(
            r"avcdec|dec_avc|decode/common|[Pp]rofile|[Cc]hroma|SPS|PPS|unsupported", s["text"])]
        ranges = [("startup", 0x40, 0x60, 0xbfc00000), ("boot", 0x400, 0x460, 0xbfc00000),
                  ("boot_transfer", 0x578, 0x5b4, 0xbfc00000)]
        if path.name == "vcd_firmware.bin":
            ranges.append(("main_startup", 0x4300, 0x4380, 0x80000000))
        elif path.name == "vcd_firmware_imola2.bin":
            ranges.append(("main_startup", 0x9300, 0x93c4, 0x80000000))
            ranges.append(("mbp_a_startup", 0x714300, 0x714398, 0x80000000))
            ranges.append(("mbp_b_startup", 0x8bf300, 0x8bf398, 0x80000000))
        gp_loads = []
        for offset in range(0, len(data) - 7, 4):
            first, second = struct.unpack_from("<II", data, offset)
            if first >> 16 == 0x3c1c and second >> 16 in {0x279c, 0x379c}:
                low = second & 0xffff
                gp = ((first & 0xffff) << 16)
                gp = gp | low if second >> 16 == 0x379c else gp + (low if low < 0x8000 else low - 0x10000)
                gp_loads.append({"file_offset": hex(offset), "gp": hex(gp & 0xffffffff),
                                 "raw_hex": data[offset:offset + 8].hex()})
        disassembly = {}
        for name, start, end, base in ranges:
            disassembly[name] = [{"address": hex(i.address), "file_offset": hex(i.address - base),
                                  "bytes": i.bytes.hex(), "mnemonic": i.mnemonic, "operands": i.op_str}
                                 for i in md.disasm(data[start:end], base + start)]
        result["images"].append({
            "path": str(path.resolve()), "bytes": len(data),
            "sha256": hashlib.sha256(data).hexdigest(), "header_hex": data[:96].hex(),
            "version": data[16:64].split(b"\0", 1)[0].decode("ascii"),
            "architecture": "MIPS32 little endian, corroborated by CP0 startup and delay slots",
            "mapping": "boot bfc00000, main 80000000 + file offset (main corroborated for original and imola2, NOT fpga)",
            "disassembly": disassembly, "strings_count": len(strings), "selected_strings": selected,
            "gp_load_candidates": gp_loads,
        })
    if args.avcam or args.warm_image:
        result["reference_evidence"] = []
        for source in [args.avcam, args.warm_image]:
            if not source:
                continue
            path = Path(source)
            data = path.read_bytes()
            tokens = ["SW_VER_46_21_02_0", "SW_VER_13_11_10_0", "SW_VER_40_11_02_0",
                      "/usr/codec/vcd_firmware_imola2.bin", "/usr/codec/vcd_firmware.bin",
                      "/usr/codec/vcd_firmware_imola2_fpga.bin"]
            result["reference_evidence"].append({
                "path": str(path.resolve()), "bytes": len(data),
                "sha256": hashlib.sha256(data).hexdigest(),
                "tokens": [{"text": token, "count": data.count(token.encode()),
                            "first_offset": hex(data.find(token.encode())) if token.encode() in data else None}
                           for token in tokens]})
        result["active_image_on_camera"] = (
            "Static av-cam path and update warm-image strings support imola2; "
            "not a runtime observation of the physical camera")
    path = Path(args.output)
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(result, indent=2), encoding="utf-8")
    print(path, "images", len(result["images"]))


if __name__ == "__main__":
    main()
