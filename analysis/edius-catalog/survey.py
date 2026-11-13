"""Read-only EDIUS binary survey; all generated artifacts stay beside this file."""
import hashlib
import json
import re
from pathlib import Path

import pefile

ROOT = Path(r"C:\Program Files\Grass Valley\EDIUS 11")
OUT = Path(__file__).resolve().parent
PATTERN = re.compile(
    r"xavc|mediapro|database\.bin|m4root|nrtmetadata|nonrealtime|"
    r"non-real.?time|nrtmd|c\d{4}m\d{2}|avf_info|avf_escp|"
    r"mxf.*writ|writ.*mxf|mp4.*writ|writ.*mp4|"
    r"(?:xmp|nrt|umid|sony).*\.xml|\.xml.*(?:xmp|nrt|sony)|"
    r"write.*(?:thumbnail|catalog)|(?:thumbnail|catalog).*write",
    re.I,
)
NAME = re.compile(r"xavc|mxf|mp4|mpeg|export|sourcebrowser|cmf|core|sony", re.I)


def text(value):
    return value.decode("utf-8", "replace") if value else ""


def mapped(pe, offset):
    try:
        rva = pe.get_rva_from_offset(offset)
        return {"rva": hex(rva), "va": hex(pe.OPTIONAL_HEADER.ImageBase + rva)}
    except pefile.PEFormatError:
        return {}


def main():
    modules = []
    inventory = []
    for path in sorted(ROOT.rglob("*")):
        if not path.is_file() or path.suffix.lower() not in {".dll", ".tpi", ".exe", ".ax"}:
            continue
        data = path.read_bytes()
        if data[:2] != b"MZ":
            continue
        matches = []
        for encoding, rx in [
            ("ascii", rb"[\x20-\x7e]{5,}"),
            ("utf-16le", rb"(?:[\x20-\x7e]\x00){5,}"),
        ]:
            for match in re.finditer(rx, data):
                value = match.group().decode(encoding)
                if PATTERN.search(value):
                    matches.append({"encoding": encoding, "offset": hex(match.start()), "text": value})
        identity = {
            "path": str(path), "relative": str(path.relative_to(ROOT)),
            "size": len(data), "sha256": hashlib.sha256(data).hexdigest(),
            "matches": len(matches),
        }
        inventory.append(identity)
        if not matches and not NAME.search(path.name):
            continue
        pe = pefile.PE(data=data, fast_load=True)
        pe.parse_data_directories(directories=[
            pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_IMPORT"],
            pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_EXPORT"],
            pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT"],
        ])
        imports = []
        for key, delayed in [("DIRECTORY_ENTRY_IMPORT", False), ("DIRECTORY_ENTRY_DELAY_IMPORT", True)]:
            for desc in getattr(pe, key, []):
                for imp in desc.imports:
                    imports.append({
                        "dll": text(desc.dll), "name": text(imp.name),
                        "ordinal": imp.ordinal, "iat_va": hex(imp.address), "delayed": delayed,
                    })
        exports = []
        if hasattr(pe, "DIRECTORY_ENTRY_EXPORT"):
            for sym in pe.DIRECTORY_ENTRY_EXPORT.symbols:
                exports.append({
                    "name": text(sym.name), "ordinal": sym.ordinal,
                    "rva": hex(sym.address),
                    "va": hex(pe.OPTIONAL_HEADER.ImageBase + sym.address),
                    "forwarder": text(sym.forwarder),
                })
        for match in matches:
            match.update(mapped(pe, int(match["offset"], 16)))
        identity = {
            **identity, "image_base": hex(pe.OPTIONAL_HEADER.ImageBase),
            "timestamp": pe.FILE_HEADER.TimeDateStamp, "machine": hex(pe.FILE_HEADER.Machine),
            "sections": [{"name": text(s.Name).strip("\x00"),
                          "rva": hex(s.VirtualAddress), "size": s.Misc_VirtualSize,
                          "raw_offset": hex(s.PointerToRawData),
                          "characteristics": hex(s.Characteristics)} for s in pe.sections],
            "imports": imports, "exports": exports, "strings": matches,
        }
        modules.append(identity)
        if matches:
            print(path.relative_to(ROOT), "strings", len(matches), "imports", len(imports), "exports", len(exports))
        pe.close()
    (OUT / "inventory.json").write_text(json.dumps(inventory, indent=2), encoding="utf-8")
    (OUT / "survey.json").write_text(json.dumps(modules, indent=2), encoding="utf-8")
    print("PE files scanned", len(inventory), "selected", len(modules))


if __name__ == "__main__":
    main()
