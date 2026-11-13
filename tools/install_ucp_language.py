"""Purpose: install the separate Sony opaque-UCP analysis language in Ghidra.

Usage: python tools/install_ucp_language.py [--ghidra GHIDRA_DIRECTORY];
    add --apply only to install/compile the supplied language files.
Design: preflight existing language hashes, compile with Sleigh, then publish a
    separate language definition and record installation provenance.
Scope: the configured Windows Ghidra/MIPS installation. Writes application
    files with --apply; never replaces stock MIPS or models hardware semantics.
"""
import argparse
import hashlib
import json
import shutil
import subprocess
from pathlib import Path


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--ghidra", default="E:/Program Files/ghidra_12.1.4_PUBLIC")
    ap.add_argument("--apply", action="store_true")
    args = ap.parse_args()
    root = Path(__file__).resolve().parent.parent
    sources = root / "firmware/tools/sony_ucp"
    ghidra = Path(args.ghidra).resolve()
    languages = ghidra / "Ghidra/Processors/MIPS/data/languages"
    compiler = ghidra / "Ghidra/Features/Decompiler/os/win_x86_64/sleigh.exe"
    if not (languages / "mips32le.slaspec").is_file() or not compiler.is_file():
        raise ValueError("Expected the Windows Ghidra MIPS language and Sleigh compiler")
    source = sources / "sony_ucp32le.slaspec"
    definition = sources / "sony_ucp.ldefs"
    for path in (source, definition):
        target = languages / path.name
        if target.exists() and digest(target) != digest(path):
            raise FileExistsError(f"Will not overwrite a different installed language source: {target}")
    if not args.apply:
        print("Preflight passed; --apply installs only the separate Sony opaque language")
        return
    shutil.copy2(source, languages / source.name)
    command = [str(compiler), str(languages / source.name), str(languages / "sony_ucp32le.sla")]
    result = subprocess.run(command, capture_output=True, text=True, encoding="utf-8", errors="replace")
    log = root / "analysis/ucp-language-compile.log"
    log.write_text(result.stdout + result.stderr, encoding="utf-8")
    if result.returncode:
        raise RuntimeError(f"Sleigh compiler failed; inspect {log}")
    # Publish the language definition only once its compiled specification exists.
    shutil.copy2(definition, languages / definition.name)
    report = {"language": "MIPS:LE:32:sony-ucp-opaque", "analysis_only": True,
              "hardware_emulation": False, "compiler": str(compiler),
              "command": command, "compiler_exit": result.returncode,
              "installed": [{"path": str(languages / name), "sha256": digest(languages / name)}
                            for name in [source.name, definition.name, "sony_ucp32le.sla"]]}
    (root / "analysis/ucp-language-install.json").write_text(
        json.dumps(report, indent=2), encoding="utf-8")
    print(json.dumps(report, indent=2))


if __name__ == "__main__":
    main()
