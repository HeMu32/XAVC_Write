"""Read only the loaded MPEG plug-in. Never inject, suspend, debug, or write a process."""
import argparse
import ctypes as c
from ctypes import wintypes as w
from datetime import datetime, timezone
import hashlib
import json
from pathlib import Path
import struct

import pefile

OUT = Path(__file__).resolve().parent
EXPECTED_PATH = Path(r"C:\Program Files\Grass Valley\EDIUS 11\PlugIn\CtsMpegPlugIn.tpi")
EXPECTED_EXE = Path(r"C:\Program Files\Grass Valley\EDIUS 11\EDIUS.exe")
PROCESS_ACCESS = 0x0400 | 0x0010
PAGE = 4096


class MODULEINFO(c.Structure):
    _fields_ = [("base", c.c_void_p), ("size", w.DWORD), ("entry", c.c_void_p)]


class MBI(c.Structure):
    _fields_ = [("base", c.c_void_p), ("allocation_base", c.c_void_p),
                ("allocation_protect", w.DWORD), ("partition_id", w.WORD),
                ("region_size", c.c_size_t), ("state", w.DWORD),
                ("protect", w.DWORD), ("type", w.DWORD)]


def digest(data):
    return hashlib.sha256(data).hexdigest()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--pid", type=int, required=True)
    args = ap.parse_args()
    kernel = c.WinDLL("kernel32", use_last_error=True)
    psapi = c.WinDLL("psapi", use_last_error=True)
    kernel.OpenProcess.argtypes = [w.DWORD, w.BOOL, w.DWORD]
    kernel.OpenProcess.restype = w.HANDLE
    kernel.CloseHandle.argtypes = [w.HANDLE]
    kernel.ReadProcessMemory.argtypes = [w.HANDLE, c.c_void_p, c.c_void_p, c.c_size_t,
                                        c.POINTER(c.c_size_t)]
    kernel.ReadProcessMemory.restype = w.BOOL
    kernel.VirtualQueryEx.argtypes = [w.HANDLE, c.c_void_p, c.POINTER(MBI), c.c_size_t]
    kernel.VirtualQueryEx.restype = c.c_size_t
    kernel.QueryFullProcessImageNameW.argtypes = [w.HANDLE, w.DWORD, w.LPWSTR, c.POINTER(w.DWORD)]
    psapi.EnumProcessModulesEx.argtypes = [w.HANDLE, c.POINTER(w.HMODULE), w.DWORD,
                                         c.POINTER(w.DWORD), w.DWORD]
    psapi.GetModuleFileNameExW.argtypes = [w.HANDLE, w.HMODULE, w.LPWSTR, w.DWORD]
    psapi.GetModuleInformation.argtypes = [w.HANDLE, w.HMODULE, c.POINTER(MODULEINFO), w.DWORD]
    handle = kernel.OpenProcess(PROCESS_ACCESS, False, args.pid)
    if not handle:
        raise c.WinError(c.get_last_error())
    try:
        exe = c.create_unicode_buffer(32768)
        exe_size = w.DWORD(len(exe))
        if not kernel.QueryFullProcessImageNameW(handle, 0, exe, c.byref(exe_size)):
            raise c.WinError(c.get_last_error())
        if Path(exe.value) != EXPECTED_EXE:
            raise RuntimeError(f"Unexpected executable: {exe.value}")
        modules = (w.HMODULE * 4096)()
        needed = w.DWORD()
        if not psapi.EnumProcessModulesEx(handle, modules, c.sizeof(modules), c.byref(needed), 3):
            raise c.WinError(c.get_last_error())
        candidates = []
        for module in modules[:needed.value // c.sizeof(w.HMODULE)]:
            name = c.create_unicode_buffer(32768)
            if psapi.GetModuleFileNameExW(handle, module, name, len(name)):
                if Path(name.value) == EXPECTED_PATH:
                    candidates.append(module)
        if len(candidates) != 1:
            raise RuntimeError(f"Expected one installed MPEG plug-in, found {len(candidates)}")
        info = MODULEINFO()
        if not psapi.GetModuleInformation(handle, candidates[0], c.byref(info), c.sizeof(info)):
            raise c.WinError(c.get_last_error())
        stamp = datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%SZ")
        directory = OUT / f"live-mpeg-{args.pid}-{stamp}"
        directory.mkdir(exist_ok=False)
        start = datetime.now(timezone.utc).isoformat()
        memory = bytearray(info.size)
        failures = []
        for rva in range(0, info.size, PAGE):
            n = min(PAGE, info.size - rva)
            buffer = c.create_string_buffer(n)
            read = c.c_size_t()
            ok = kernel.ReadProcessMemory(handle, info.base + rva, buffer, n, c.byref(read))
            memory[rva:rva+read.value] = buffer.raw[:read.value]
            if not ok or read.value != n:
                failures.append({"rva": hex(rva), "requested": n, "read": read.value,
                                 "winerror": c.get_last_error()})
        regions = []
        cursor = info.base
        while cursor < info.base + info.size:
            region = MBI()
            if not kernel.VirtualQueryEx(handle, cursor, c.byref(region), c.sizeof(region)):
                break
            regions.append({
                "base": hex(region.base), "size": region.region_size,
                "allocation_base": hex(region.allocation_base or 0),
                "state": hex(region.state), "protect": hex(region.protect), "type": hex(region.type),
            })
            cursor = region.base + region.region_size
        raw = EXPECTED_PATH.read_bytes()
        pe = pefile.PE(data=raw)
        preferred = pe.OPTIONAL_HEADER.ImageBase
        delta = info.base - preferred
        normalized = bytearray(memory)
        relocation_count = 0
        for block in getattr(pe, "DIRECTORY_ENTRY_BASERELOC", []):
            for reloc in block.entries:
                if reloc.type == 10 and reloc.rva + 8 <= len(normalized):
                    value = struct.unpack_from("<Q", normalized, reloc.rva)[0]
                    struct.pack_into("<Q", normalized, reloc.rva, (value - delta) & ((1 << 64) - 1))
                    relocation_count += 1
                elif reloc.type not in (0, 10):
                    raise RuntimeError(f"Unhandled PE relocation type {reloc.type}")
        # This derivative is for static analysis, not an executable replacement.
        for key in ("DIRECTORY_ENTRY_IMPORT", "DIRECTORY_ENTRY_DELAY_IMPORT"):
            for desc in getattr(pe, key, []):
                for imp in desc.imports:
                    rva = imp.address - preferred
                    normalized[rva:rva+8] = pe.get_data(rva, 8)
        struct.pack_into("<Q", normalized, pe.OPTIONAL_HEADER.get_field_absolute_offset("ImageBase"),
                         preferred)
        rebuilt = bytearray(raw)
        sections = []
        for section in pe.sections:
            a = section.VirtualAddress
            n = section.SizeOfRawData
            rebuilt[section.PointerToRawData:section.PointerToRawData+n] = normalized[a:a+n]
            evidence = {
                "name": section.Name.decode().rstrip("\x00"), "rva": hex(a),
                "raw_size": n, "disk_sha256": digest(section.get_data()),
                "normalized_loaded_sha256": digest(normalized[a:a+n]),
                "changed_bytes": sum(x != y for x, y in zip(section.get_data(), normalized[a:a+n])),
            }
            if section.Characteristics & 0x20000000:
                second = c.create_string_buffer(n)
                read = c.c_size_t()
                ok = kernel.ReadProcessMemory(handle, info.base + a, second, n, c.byref(read))
                evidence["second_read_complete"] = bool(ok and read.value == n)
                evidence["live_code_stable_across_reads"] = (
                    evidence["second_read_complete"] and second.raw == bytes(memory[a:a+n])
                )
            sections.append(evidence)
        mem_path = directory / "CtsMpegPlugIn.loaded-memory.bin"
        pe_path = directory / "CtsMpegPlugIn.loaded-normalized-pe.bin"
        mem_path.write_bytes(memory)
        pe_path.write_bytes(rebuilt)
        manifest = {
            "pid": args.pid, "process_executable": exe.value,
            "process_access": hex(PROCESS_ACCESS),
            "access_note": "PROCESS_QUERY_INFORMATION | PROCESS_VM_READ only",
            "module_path": str(EXPECTED_PATH), "actual_base": hex(info.base),
            "preferred_base": hex(preferred), "size_of_image": info.size,
            "capture_start_utc": start, "capture_end_utc": datetime.now(timezone.utc).isoformat(),
            "disk_sha256": digest(raw), "raw_memory_sha256": digest(memory),
            "normalized_analysis_pe_sha256": digest(rebuilt),
            "disk_unchanged_after_capture": digest(EXPECTED_PATH.read_bytes()) == digest(raw),
            "reverse_relocations": relocation_count, "regions": regions,
            "read_failures": failures, "sections": sections,
            "memory_file": str(mem_path), "analysis_pe_file": str(pe_path),
            "analysis_derivative_warning": (
                "Never load this derivative. Original PE layout with loaded sections, "
                "reverse DIR64 relocations, restored original IAT and preferred image base. "
                "May contain runtime-only globals; retained solely for static analysis."
            ),
        }
        (directory / "capture.json").write_text(json.dumps(manifest, indent=2), encoding="utf-8")
        print(json.dumps({"directory": str(directory), "actual_base": hex(info.base),
                          "read_failures": len(failures), "sections": sections}, indent=2))
    finally:
        kernel.CloseHandle(handle)


if __name__ == "__main__":
    main()
