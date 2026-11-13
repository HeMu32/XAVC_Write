"""Freeze the bounded EDIUS survey and entry-transfer evidence; no DLL execution."""
import hashlib
import json
import re
from pathlib import Path

import capstone
import pefile

ROOT = Path(__file__).resolve().parent


def main():
    survey = json.loads((ROOT / "survey.json").read_text(encoding="utf-8"))
    inventory = json.loads((ROOT / "inventory.json").read_text(encoding="utf-8"))
    names = {"CtsMpegPlugIn.tpi", "CtsMxfPlugIn.tpi", "cmxfapi.dll"}
    modules = []
    for row in survey:
        if Path(row["path"]).name not in names:
            continue
        data = Path(row["path"]).read_bytes()
        if hashlib.sha256(data).hexdigest() != row["sha256"]:
            raise ValueError("Installed binary changed since survey")
        pe = pefile.PE(data=data)
        base = pe.OPTIONAL_HEADER.ImageBase
        selected = [value for value in row["strings"] if re.search(
            r"M4ROOT|MEDIAPRO|NonRealTimeMeta|CPDMediaProfile|CExportXAVCS|exXAVCS\.cpp|XAVC-M4@",
            value["text"], re.I)]
        transfers = []
        decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
        for item in row["exports"]:
            if not item["name"].startswith("Startup"):
                continue
            rva = int(item["rva"], 16)
            instruction = next(decoder.disasm(pe.get_data(rva, 16), base + rva), None)
            transfers.append({"export": item["name"], "va": item["va"], "rva": item["rva"],
                              "first_instruction": f"{instruction.mnemonic} {instruction.op_str}"
                              if instruction else None})
        modules.append({"path": row["path"], "sha256": row["sha256"],
                        "image_base": row["image_base"], "selected_literals": selected,
                        "entry_transfers": transfers,
                        "executable_sections": [{"rva": hex(s.VirtualAddress),
                                                 "size": s.Misc_VirtualSize,
                                                 "entropy": s.get_entropy()}
                                                for s in pe.sections if s.Characteristics & 0x20000000],
                        "selected_io_imports": [item for item in row["imports"] if re.search(
                            r"CreateFile[AW]$|WriteFile$|FlushFileBuffers$|CloseHandle$|MoveFile[AW]$|"
                            r"CreateDirectory[AW]$|CreateXmlWriter|SHCreateStreamOnFileW",
                            item["name"])]})
        pe.close()
    report = {
        "scanned_pe_count": len(inventory), "survey_selected_module_count": len(survey),
        "modules": modules,
        "database_bin_literal_hits": [{"module": row["relative"], **value}
                                     for row in survey for value in row["strings"]
                                     if "DATABASE.BIN" in value["text"].upper()],
        "scope": "Literal presence and import/entry observations, not a proven writer call chain",
        "card_access": False, "applications_or_dlls_executed": False,
        "limitations": ["The direct xref scan does not resolve indirect dispatch or transformed code.",
                        "Missing DATABASE.BIN literals do not prove absence of database support.",
                        "The interrupted cmxfapi headless import is not a completed analysis."],
    }
    target = ROOT / "evidence-summary.json"
    target.write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(target)
    for row in modules:
        print(row["path"], len(row["selected_literals"]), row["entry_transfers"])


if __name__ == "__main__":
    main()
