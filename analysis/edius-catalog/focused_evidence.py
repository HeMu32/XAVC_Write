"""Preserve targeted string context and on-disk entry stubs as reproducible evidence."""
import hashlib
import json
import re
from pathlib import Path

import capstone
import pefile

OUT = Path(__file__).resolve().parent
ROOT = Path(r"C:\Program Files\Grass Valley\EDIUS 11")
TARGETS = {
    "PlugIn/CtsMpegPlugIn.tpi": [(0x6F8800, 0x2800), (0x702800, 0x500),
                               (0x70FA00, 0xE00), (0x711500, 0x90),
                               (0x711B50, 0xE50), (0x727800, 0x800)],
    "PlugIn/CtsMxfPlugIn.tpi": [(0x55E300, 0x300), (0x560000, 0x180),
                              (0x565F00, 0x300), (0x56BD00, 0x500),
                              (0x585700, 0x500)],
    "cmxfapi.dll": [],
}


def main():
    result = []
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    for name, ranges in TARGETS.items():
        path = ROOT / name
        raw = path.read_bytes()
        pe = pefile.PE(data=raw)
        base = pe.OPTIONAL_HEADER.ImageBase
        entry = pe.OPTIONAL_HEADER.AddressOfEntryPoint
        m = {
            "path": str(path), "sha256": hashlib.sha256(raw).hexdigest(),
            "base": hex(base), "entry_rva": hex(entry),
            "sections": [{"name": s.Name.decode().rstrip("\x00"),
                          "rva": hex(s.VirtualAddress), "entropy": s.get_entropy()}
                         for s in pe.sections],
            "entry_instructions": [
                {"va": hex(i.address), "instruction": i.mnemonic + " " + i.op_str}
                for i in list(md.disasm(pe.get_data(entry, 64), base + entry))[:16]
            ],
            "strings": [],
        }
        for rva, count in ranges:
            for enc, rx in [("ascii", rb"[\x20-\x7e]{4,}"),
                            ("utf-16le", rb"(?:[\x20-\x7e]\x00){3,}")]:
                for match in re.finditer(rx, pe.get_data(rva, count)):
                    a = rva + match.start()
                    m["strings"].append({
                        "rva": hex(a), "va": hex(base + a), "encoding": enc,
                        "text": match.group().decode(enc),
                    })
        if name.endswith("CtsMpegPlugIn.tpi"):
            m["protected_call_sample"] = [
                {"va": hex(i.address), "instruction": i.mnemonic + " " + i.op_str}
                for i in list(md.disasm(pe.get_data(0x215DF0, 64), base + 0x215DF0))[:16]
            ]
        result.append(m)
    (OUT / "focused-evidence.json").write_text(json.dumps(result, indent=2), encoding="utf-8")
    print("Saved focused-evidence.json")


if __name__ == "__main__":
    main()
