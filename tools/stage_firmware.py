"""Purpose: copy and extract the existing CAppRev M4 6.02 research inputs.

Usage: python tools/stage_firmware.py; inspect SOURCE and DEST constants first.
Design: hash-check copied tools/ext2 input, extract regular files with path
    containment and case-collision handling, and save provenance manifests.
Scope: fixed local source/destination paths, not a generic firmware downloader
    or device flasher. Writes workspace firmware copies/manifests, not the card.
"""
import hashlib
import json
import shutil
import stat
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SOURCE = Path("C:/Users/HeMu/Desktop/CAppRev/artifacts/ble-firmware-static-20261103")
DEST = ROOT / "firmware/m4-v602"


def digest(path):
    with path.open("rb") as f:
        return hashlib.file_digest(f, "sha256").hexdigest()


def main():
    DEST.mkdir(parents=True, exist_ok=True)
    records = []
    pairs = [(SOURCE / "inputs/m4-v602/usr.ext2", DEST / "usr.ext2")]
    for sub in ["tools/fwtool", "tools/DecompileFunc.java", "tools/Invoke-GhidraOffline.ps1"]:
        path = SOURCE / sub
        if path.is_dir():
            pairs.extend((p, ROOT / "firmware" / p.relative_to(SOURCE)) for p in path.rglob("*")
                         if p.is_file() and "__pycache__" not in p.parts)
        else:
            pairs.append((path, ROOT / "firmware" / sub))
    for src, dst in pairs:
        h = digest(src)
        if not dst.exists():
            dst.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(src, dst)
        if digest(dst) != h:
            raise RuntimeError(f"Copy mismatch: {dst}")
        records.append({"source": str(src), "copy": str(dst.relative_to(ROOT)), "sha256": h,
                        "bytes": src.stat().st_size})
    sys.path.insert(0, str(ROOT / "firmware/tools/fwtool"))
    from fwtool.archive.ext2 import isExt2, readExt2
    inventory = []
    extracted = []
    outroot = (DEST / "usr").resolve()
    with (DEST / "usr.ext2").open("rb") as f:
        assert isExt2(f)
        f.seek(0)
        for entry in readExt2(f):
            inventory.append({"path": entry.path, "bytes": entry.size, "mode": oct(entry.mode)})
            if not stat.S_ISREG(entry.mode):
                continue
            dst = (outroot / entry.path.lstrip("/")).resolve()
            dst.relative_to(outroot)
            chunks = []
            while chunk := entry.contents.read(65536):
                chunks.append(chunk)
            data = b"".join(chunks)
            if len(data) != entry.size:
                raise RuntimeError(f"Truncated: {entry.path}")
            h = hashlib.sha256(data).hexdigest()
            if dst.exists() and digest(dst) != h:
                dst = dst.with_name(dst.name + "__case_" + h[:12])
            if not dst.exists():
                dst.parent.mkdir(parents=True, exist_ok=True)
                with dst.open("xb") as o:
                    o.write(data)
            if digest(dst) != h:
                raise RuntimeError(f"Extract mismatch: {entry.path}")
            extracted.append({"member": entry.path, "copy": str(dst.relative_to(DEST)),
                              "sha256": h, "bytes": len(data)})
    for name, value in [("copy-manifest.json", records), ("inventory.json", inventory),
                        ("extracted-manifest.json", extracted)]:
        (DEST / name).write_text(json.dumps(value, indent=2), encoding="utf-8")
    print(json.dumps({"files": len(extracted), "bytes": sum(x["bytes"] for x in extracted),
                      "destination": str(DEST)}, indent=2))


if __name__ == "__main__":
    main()
