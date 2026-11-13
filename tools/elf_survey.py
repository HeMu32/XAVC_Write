"""Purpose: inventory an ELF image before deeper firmware analysis.

Usage: python tools/elf_survey.py PATH_TO_ELF --output REPORT.json.
Design: use structured ELF parsing to record identity, architecture, symbols
    and task-relevant string evidence with file provenance.
Scope: static, read-only reconnaissance of local ELF files. It does not execute
    firmware, reconstruct full control flow or establish camera requirements.
"""
import argparse
import hashlib
import json
import re
import subprocess
from pathlib import Path

from elftools.elf.elffile import ELFFile


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("path")
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    path = Path(args.path)
    data = path.read_bytes()
    with path.open("rb") as f:
        elf = ELFFile(f)
        symbols = []
        tab = elf.get_section_by_name(".dynsym")
        for s in tab.iter_symbols():
            if s["st_info"]["type"] == "STT_FUNC" and s["st_value"] and s.name:
                symbols.append({"name": s.name, "address": hex(s["st_value"]), "size": s["st_size"]})
        if symbols:
            names = subprocess.run(["c++filt"], input="\n".join(s["name"] for s in symbols),
                                   text=True, capture_output=True, check=True).stdout.splitlines()
            for s, name in zip(symbols, names):
                s["demangled"] = name
        result = {"path": str(path.resolve()), "sha256": hashlib.sha256(data).hexdigest(),
                  "header": dict(elf.header),
                  "segments": [dict(x.header) for x in elf.iter_segments()],
                  "sections": [{"name": x.name, **dict(x.header)} for x in elf.iter_sections()],
                  "symbols": symbols}
        selected = []
        for match in re.finditer(rb"[\x20-\x7e]{5,}", data):
            value = match.group().decode("ascii")
            if re.search(r"VPRF|avcC|MEDIAPRO|DATABASE\.BIN|M4ROOT|deblocking|SPS|[Pp]lay.*[Cc]heck|[Cc]heck.*[Pp]lay", value):
                offset = match.start()
                va = next((s["p_vaddr"] + offset - s["p_offset"] for s in elf.iter_segments()
                           if s["p_type"] == "PT_LOAD" and s["p_offset"] <= offset < s["p_offset"] + s["p_filesz"]), None)
                selected.append({"offset": hex(offset), "address": hex(va) if va is not None else None, "text": value})
        result["strings"] = selected
    out = Path(args.output)
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(result, indent=2, default=dict), encoding="utf-8")
    for s in symbols:
        if re.search(r"XavcsMovieReader::|libXavcMp4::|sidb::.*(?:Check|Profile|Record)|M4MediaProfile.*(?:Read|Write|Check)", s["demangled"]):
            print(s["address"], s["size"], s["demangled"])


if __name__ == "__main__":
    main()
