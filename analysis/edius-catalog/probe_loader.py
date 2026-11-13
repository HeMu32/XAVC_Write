"""Bounded offline x64 loader probe; imports are stopped, never executed natively."""
import argparse
import collections
import hashlib
import json
import struct
from pathlib import Path

import pefile
from unicorn import Uc, UcError, UC_ARCH_X86, UC_MODE_64, UC_HOOK_CODE, UC_HOOK_MEM_INVALID
from unicorn.x86_const import (
    UC_X86_REG_RCX, UC_X86_REG_RDX, UC_X86_REG_R8, UC_X86_REG_RSP,
    UC_X86_REG_GS_BASE, UC_X86_REG_RIP,
    UC_X86_REG_RAX, UC_X86_REG_R9,
)

OUT = Path(__file__).resolve().parent


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("binary")
    ap.add_argument("--stub-memory-queries", action="store_true")
    ap.add_argument("--instruction-limit", type=int, default=5000000)
    args = ap.parse_args()
    if not 1 <= args.instruction_limit <= 50000000:
        ap.error("--instruction-limit must be between 1 and 50000000")
    path = Path(args.binary)
    raw = path.read_bytes()
    pe = pefile.PE(data=raw)
    base = pe.OPTIONAL_HEADER.ImageBase
    image = pe.get_memory_mapped_image()
    size = (pe.OPTIONAL_HEADER.SizeOfImage + 0xFFF) & ~0xFFF
    uc = Uc(UC_ARCH_X86, UC_MODE_64)
    uc.mem_map(base, size)
    uc.mem_write(base, image)
    uc.mem_map(0x70000000, 0x20000)
    uc.mem_map(0x71000000, 0x20000)
    stack = 0x70010000 - 8
    uc.mem_write(stack, struct.pack("<Q", 0x71000000))
    uc.reg_write(UC_X86_REG_RSP, stack)
    uc.reg_write(UC_X86_REG_RCX, base)
    uc.reg_write(UC_X86_REG_RDX, 1)
    uc.reg_write(UC_X86_REG_R8, 0)
    uc.reg_write(UC_X86_REG_GS_BASE, 0x71010000)
    imports = {}
    for desc in getattr(pe, "DIRECTORY_ENTRY_IMPORT", []):
        for imp in desc.imports:
            target = 0x71000100 + len(imports) * 16
            imports[target] = {
                "dll": desc.dll.decode(), "name": imp.name.decode() if imp.name else str(imp.ordinal),
                "iat": hex(imp.address),
            }
            uc.mem_write(imp.address, struct.pack("<Q", target))
    result = {
        "path": str(path), "sha256": hashlib.sha256(raw).hexdigest(),
        "base": hex(base), "entry": hex(base + pe.OPTIONAL_HEADER.AddressOfEntryPoint),
        "instruction_limit": args.instruction_limit, "native_execution": False, "instructions": 0,
        "import_policy": "stop before every imported call, never execute or simulate an import",
    }
    recent = collections.deque(maxlen=24)

    def on_code(u, address, size, _):
        result["instructions"] += 1
        recent.append(hex(address))
        if address in imports:
            name = imports[address]["name"]
            if args.stub_memory_queries and name in {"GetSystemInfo", "VirtualQuery", "VirtualProtect", "FlushInstructionCache"}:
                result.setdefault("stubbed_imports", []).append(imports[address])
                if name == "GetSystemInfo":
                    info = struct.pack("<HHIQQQIIIHH", 9, 0, 4096, 0x10000,
                                       0x7FFFFFFEFFFF, 15, 4, 8664, 65536, 6, 0)
                    u.mem_write(u.reg_read(UC_X86_REG_RCX), info)
                elif name == "VirtualProtect":
                    old = u.reg_read(UC_X86_REG_R9)
                    if old:
                        u.mem_write(old, struct.pack("<I", 0x20))
                elif name == "VirtualQuery":
                    requested = u.reg_read(UC_X86_REG_RCX)
                    region = requested & ~0xFFF
                    info = struct.pack("<QQIIQIIII", region, base, 0x20, 0, 4096,
                                       0x1000, 0x20, 0x1000000, 0)
                    u.mem_write(u.reg_read(UC_X86_REG_RDX), info)
                sp = u.reg_read(UC_X86_REG_RSP)
                ret = struct.unpack("<Q", u.mem_read(sp, 8))[0]
                u.reg_write(UC_X86_REG_RSP, sp + 8)
                u.reg_write(UC_X86_REG_RAX, 48 if name == "VirtualQuery" else 1)
                u.reg_write(UC_X86_REG_RIP, ret)
                return
            result["stopped_import"] = imports[address]
            u.emu_stop()
        elif address == 0x71000000:
            result["returned"] = True
            u.emu_stop()

    def on_invalid(u, access, address, size, value, _):
        result["invalid_access"] = {
            "type": access, "address": hex(address), "size": size,
            "rip": hex(u.reg_read(UC_X86_REG_RIP)),
        }
        return False

    uc.hook_add(UC_HOOK_CODE, on_code)
    uc.hook_add(UC_HOOK_MEM_INVALID, on_invalid)
    try:
        uc.emu_start(base + pe.OPTIONAL_HEADER.AddressOfEntryPoint, 0, timeout=30000000,
                     count=args.instruction_limit)
    except UcError as error:
        result["error"] = str(error)
    result["last_rip"] = hex(uc.reg_read(UC_X86_REG_RIP))
    result["recent_addresses"] = list(recent)
    changed = []
    for section in pe.sections:
        a = section.VirtualAddress
        n = section.Misc_VirtualSize
        if not section.Characteristics & 0x20000000:
            continue
        before = image[a:a+n]
        after = bytes(uc.mem_read(base + a, n))
        changed.append({
            "rva": hex(a), "size": n, "changed_bytes": sum(x != y for x, y in zip(before, after)),
            "before_sha256": hashlib.sha256(before).hexdigest(),
            "after_sha256": hashlib.sha256(after).hexdigest(),
        })
    result["executable_sections"] = changed
    suffix = ".memory-stubs" if args.stub_memory_queries else ""
    output = OUT / (path.name + suffix + ".loader-probe.json")
    if args.stub_memory_queries:
        result["import_policy"] = (
            "Simulate only GetSystemInfo, VirtualQuery, VirtualProtect and FlushInstructionCache "
            "in isolated Unicorn memory; stop at all other imports."
        )
        if any(s["changed_bytes"] for s in changed):
            reconstructed = bytearray(raw)
            for section in pe.sections:
                a = section.VirtualAddress
                n = section.SizeOfRawData
                start = section.PointerToRawData
                reconstructed[start:start+n] = uc.mem_read(base + a, n)
            decoded = OUT / (path.name + ".probe-image.dll")
            decoded.write_bytes(reconstructed)
            result["probe_image"] = str(decoded)
            result["probe_image_sha256"] = hashlib.sha256(reconstructed).hexdigest()
    output.write_text(json.dumps(result, indent=2), encoding="utf-8")
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
