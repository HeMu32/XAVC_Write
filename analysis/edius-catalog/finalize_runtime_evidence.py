"""Verify and seal the existing runtime packet, without touching a process or GUI."""
import argparse
from datetime import datetime, timezone, timedelta
import hashlib
import json
import os
from pathlib import Path
import subprocess


ROOT = Path(__file__).resolve().parent


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("capture")
    args = ap.parse_args()
    directory = Path(args.capture).resolve()
    if directory.parent != ROOT:
        raise ValueError("Capture must be a direct child of the EDIUS analysis directory")
    capture = json.loads((directory / "capture.json").read_text(encoding="utf-8"))
    summary = json.loads((directory / "runtime-evidence-summary.json").read_text(encoding="utf-8"))
    assert digest(directory / "CtsMpegPlugIn.loaded-memory.bin") == capture["raw_memory_sha256"]
    assert digest(directory / "CtsMpegPlugIn.loaded-normalized-pe.bin") == (
        capture["normalized_analysis_pe_sha256"]
    )
    assert summary["hashes_verified"] and len(summary["confirmed_direct_calls"]) == 3
    assert digest(Path(capture["module_path"])) == capture["disk_sha256"]
    command = (
        "Get-CimInstance Win32_Process | Where-Object { "
        "$_.Name -in @('EDIUS.exe','EHRenderEngine.exe','EHRenderWorker.exe','java.exe','python.exe') "
        "-and ($_.Name -in @('EDIUS.exe','EHRenderEngine.exe','EHRenderWorker.exe') "
        "-or $_.CommandLine -match "
        "'edius-catalog|edius-live-mpeg-47056|edius-xavcs-isolated|edius-cmxf-isolated') "
        "} | Select-Object ProcessId,ParentProcessId,Name,CreationDate,CommandLine "
        "| ConvertTo-Json -Depth 3"
    )
    result = subprocess.run(
        ["powershell.exe", "-NoProfile", "-NonInteractive", "-Command", command],
        capture_output=True, text=True, encoding="utf-8", check=True,
    )
    processes = json.loads(result.stdout) if result.stdout.strip() else []
    if isinstance(processes, dict):
        processes = [processes]
    processes = [p for p in processes if p["ProcessId"] != os.getpid()]
    retained = [p for p in processes if p["Name"] in {
        "EDIUS.exe", "EHRenderEngine.exe", "EHRenderWorker.exe"
    }]
    temporary = [p for p in processes if p not in retained]
    notes = ROOT.parent.parent / "docs" / "edius-writer-catalog-notes.md"
    files = [
        directory / name for name in (
            "capture.json", "CtsMpegPlugIn.loaded-memory.bin",
            "CtsMpegPlugIn.loaded-normalized-pe.bin", "loaded-callgraph.json",
            "loaded-rtti.json", "runtime-evidence-summary.json", "runtime-anchor-disassembly.txt",
        )
    ] + [
        ROOT / name for name in (
            "capture_loaded_mpeg.py", "trace_loaded_writer.py",
            "runtime_evidence_packet.py", "finalize_runtime_evidence.py",
        )
    ] + [notes]
    packet = {
        "status": "closed" if not temporary else "temporary_helpers_remaining",
        "closed_at": datetime.now(timezone(timedelta(hours=8))).isoformat(),
        "hash_verification": "PASS",
        "original_installed_module_unchanged": True,
        "evidence_summary": summary,
        "files": [{"path": str(path), "bytes": path.stat().st_size, "sha256": digest(path)}
                  for path in files],
        "process_audit": {
            "temporary_analysis_processes": temporary,
            "retained_application_processes": retained,
            "policy": "No EDIUS application or render child terminated; unsaved state preserved.",
            "inspection_only": True,
        },
        "capture_session": "Exited normally; OpenProcess handle closed in finally.",
        "headless_session": "Previously terminated after Computer Use stop; no finished decompilation.",
        "limits": [
            "No complete CExportXAVCS entry-to-filesystem-write chain established.",
            "Runtime image capture, not a dynamic write-operation trace.",
            "No additional GUI or live process-memory operation during finalization.",
        ],
    }
    output = directory / "runtime-evidence-final.json"
    if output.exists():
        raise FileExistsError(output)
    output.write_text(json.dumps(packet, indent=2), encoding="utf-8")
    print("Final packet:", output)
    print("Hash verification: PASS")
    print("Temporary analysis processes:", len(temporary))
    for process in retained:
        print("Preserved:", process["Name"], process["ProcessId"],
              "parent", process["ParentProcessId"])
    if temporary:
        raise RuntimeError("Temporary analysis helpers remain; inspect the final packet")


if __name__ == "__main__":
    main()
