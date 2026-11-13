"""Package verified anchors from the existing live capture; no live process or card access."""
import argparse
import hashlib
import json
from pathlib import Path

import capstone
import pefile


def sha(data):
    return hashlib.sha256(data).hexdigest()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("capture")
    args = ap.parse_args()
    directory = Path(args.capture).resolve()
    capture = json.loads((directory / "capture.json").read_text(encoding="utf-8"))
    memory = (directory / "CtsMpegPlugIn.loaded-memory.bin").read_bytes()
    raw = (directory / "CtsMpegPlugIn.loaded-normalized-pe.bin").read_bytes()
    assert sha(memory) == capture["raw_memory_sha256"]
    assert sha(raw) == capture["normalized_analysis_pe_sha256"]
    graph = json.loads((directory / "loaded-callgraph.json").read_text(encoding="utf-8"))
    assert graph["source_sha256"] == sha(raw)
    rtti = json.loads((directory / "loaded-rtti.json").read_text(encoding="utf-8"))
    pe = pefile.PE(data=raw)
    base = pe.OPTIONAL_HEADER.ImageBase
    actual = int(capture["actual_base"], 16)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    snippets = [
        ("Restored code sample, previously transformed on disk", 0x215DF0, 0x20),
        ("CExportXAVCS vtable installation references", 0x234559, 0x90),
        ("Caller to updater-containing implementation", 0x23BF00, 0x54),
        ("CPDMediaProfileUpdater object setup and conditional helper", 0x238510, 0x130),
        ("Updater vtable slot 3 helper delegation", 0x1C4360, 0x63),
    ]
    lines = [
        "STATIC DISASSEMBLY OF CODE CAPTURED FROM EDIUS PID 47056",
        "Not a dynamic export/write trace. No inferred file-commit semantics.",
        f"Normalized PE SHA256 {sha(raw)}",
        f"Preferred base {base:#x}; live capture base {actual:#x}",
        "All addresses below use preferred VA. Live VA = actual base + RVA.",
        "",
    ]
    for label, rva, size in snippets:
        lines += [f"=== {label} ===", f"RVA {rva:#x}; captured live VA {actual+rva:#x}"]
        for ins in md.disasm(pe.get_data(rva, size), base + rva):
            lines.append(f"{ins.address:#x}  {ins.bytes.hex(' '):<34} {ins.mnemonic} {ins.op_str}")
        lines.append("")
    (directory / "runtime-anchor-disassembly.txt").write_text("\n".join(lines), encoding="utf-8")
    wanted_calls = {0x18023BF43, 0x180238610, 0x1801C43A1}
    wanted_refs = {0x180234559, 0x18023853A, 0x180238556}
    packet = {
        "capture_manifest": str(directory / "capture.json"),
        "hashes_verified": True,
        "pid_at_capture": capture["pid"],
        "capture_start_utc": capture["capture_start_utc"],
        "actual_base": capture["actual_base"],
        "preferred_base": capture["preferred_base"],
        "memory_sha256": sha(memory), "analysis_pe_sha256": sha(raw),
        "read_failures": len(capture["read_failures"]),
        "access": capture["access_note"],
        "scope": "Existing module capture only; no new process read, GUI, export, or card access.",
        "evidence_grade": "Runtime-captured bytes, statically decoded; not observed export execution.",
        "rtti": rtti,
        "confirmed_direct_calls": [
            c for c in graph["calls"] if int(c["from"], 16) in wanted_calls
        ],
        "confirmed_vtable_references": [
            r for r in graph["references"] if int(r["from"], 16) in wanted_refs
        ],
        "explicit_non_claims": [
            "No verified complete CExportXAVCS entry-to-filesystem-write chain.",
            "No verified meaning assigned to the unnamed updater methods.",
            "No observed file creation, XML save, rename, flush, or DATABASE.BIN write.",
            "No claim that all transformed code in the module has been recovered.",
        ],
    }
    assert len(packet["confirmed_direct_calls"]) == 3
    assert len(packet["confirmed_vtable_references"]) == 3
    path = directory / "runtime-evidence-summary.json"
    path.write_text(json.dumps(packet, indent=2), encoding="utf-8")
    print("Verified raw memory and normalized PE hashes.")
    print("Saved", path)
    print("Saved", directory / "runtime-anchor-disassembly.txt")


if __name__ == "__main__":
    main()
