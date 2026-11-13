"""Purpose: execute original Sony MediaProfile parsing and clip queries offline.

Usage: python tools/emulate_mediapro.py --snapshot SNAP --output REPORT.json
    [--firmware LIBMPR --expat LIBEXPAT].
Design: run identified AArch64 library and Expat bytes in Unicorn, with explicit
    libc/heap/read-only filesystem models and recorded execution boundaries.
Scope: saved MEDIAPRO files and selected read-side methods, not a full library
    process, card mount, camera UI or physical playback test.
"""
import argparse
import hashlib
import json
import struct
from pathlib import Path

from elftools.elf.elffile import ELFFile
from unicorn import arm64_const as regs

from emulate_sidb_converter import RecordConverter
from emulate_sidb_readers import ARGUMENTS, EXPECTED, RETURN, SCRATCH, STACK

EXPAT_SHA256 = "3d1e4818ad4c83228f2cad6496f6e46324c063c91713feb421544394c54be654"
EXPAT_BASE = 0x60000000
HEAP, HEAP_SIZE = 0x50000000, 0x4000000
STUBS = 0x70000000


class MediaProfileEmulator(RecordConverter):
    def __init__(self, firmware, expat, snapshot, profile_override=None):
        self.heap_cursor, self.allocations = HEAP, {}
        self.io, self.handles, self.calls = [], {}, []
        self.code_sections = []
        self.global_writes, self.instruction_count = 0, 0
        self.snapshot = snapshot
        self.profile_override = profile_override
        self.extra_write_ranges, self.stubs = [], {}
        super().__init__(firmware)
        self.uc.mem_map(HEAP, HEAP_SIZE)
        self.uc.mem_map(STUBS, 0x10000)
        self.ranges.append((0x180000, 0x1A0000))
        self.ranges.append((0xB8088, 0xB80D0))  # Original shared hexadecimal-digit decoder.
        if hashlib.sha256(expat.read_bytes()).hexdigest() != EXPAT_SHA256:
            raise ValueError("Unexpected firmware Expat image")
        images = []
        for path, base in [(Path(firmware), 0), (expat, EXPAT_BASE)]:
            with path.open("rb") as stream:
                elf = ELFFile(stream)
                self.code_sections.extend((base + section["sh_addr"], section.data())
                                          for section in elf.iter_sections()
                                          if section["sh_flags"] & 4 and
                                          section["sh_type"] != "SHT_NOBITS")
                symbols = elf.get_section_by_name(".dynsym")
                for symbol in symbols.iter_symbols():
                    if symbol["st_value"]:
                        self.definitions[symbol.name] = base + symbol["st_value"]
                segments = [seg for seg in elf.iter_segments() if seg["p_type"] == "PT_LOAD"]
                if base:
                    pages = set()
                    for seg in segments:
                        pages.update(range((base + seg["p_vaddr"]) & ~4095,
                                           (base + seg["p_vaddr"] + seg["p_memsz"] + 4095) & ~4095,
                                           4096))
                    for page in sorted(pages):
                        self.uc.mem_map(page, 4096)
                    for seg in segments:
                        self.uc.mem_write(base + seg["p_vaddr"], seg.data())
                        if seg["p_flags"] & 1:
                            self.ranges.append((base + seg["p_vaddr"],
                                                base + seg["p_vaddr"] + seg["p_filesz"]))
                for seg in segments:
                    if seg["p_flags"] & 2:
                        self.extra_write_ranges.append((base + seg["p_vaddr"],
                                                        base + seg["p_vaddr"] + seg["p_memsz"]))
                plt = elf.get_section_by_name(".plt")
                relocation = elf.get_section_by_name(".rela.plt")
                if plt and relocation:
                    for index, row in enumerate(relocation.iter_relocations()):
                        self.plt[base + plt["sh_addr"] + 32 + index * 16] = (
                            symbols.get_symbol(row["r_info_sym"]).name)
                entries = []
                for section in elf.iter_sections():
                    if section["sh_type"] == "SHT_RELA":
                        for row in section.iter_relocations():
                            symbol = symbols.get_symbol(row["r_info_sym"])
                            entries.append((base + row["r_offset"], row["r_info_type"],
                                            row["r_addend"], symbol.name, base))
                images.extend(entries)
        for address, kind, addend, name, base in images:
            if kind == 1027:
                pointer = base + addend
            elif kind in {257, 1025, 1026}:  # ABS64, GLOB_DAT, JUMP_SLOT
                if name in self.definitions:
                    pointer = self.definitions[name] + addend
                else:
                    pointer = STUBS + len(self.stubs) * 16
                    self.stubs[pointer] = name
            else:
                raise ValueError(f"Unsupported relocation type {kind}")
            self.uc.mem_write(address, struct.pack("<Q", pointer))
        self.io_adapter = self.allocate(0x20)
        self.uc.mem_write(self.io_adapter, struct.pack("<Q", 0x2FC760))
        self.object = self.allocate(0xC0690)
        self.profile_path = self.allocate(0x100)
        self.uc.mem_write(self.profile_path, b"A:/PRIVATE/M4ROOT/MEDIAPRO.XML\0")

    @staticmethod
    def writable(address, size):
        return (RecordConverter.writable(address, size) or
                0 <= size <= HEAP_SIZE and HEAP <= address <= address + size <= HEAP + HEAP_SIZE)

    def on_write(self, uc, access, address, size, value, user_data):
        if self.writable(address, size):
            return
        if any(first <= address <= address + size <= end for first, end in self.extra_write_ranges):
            self.global_writes += 1
            return
        raise RuntimeError(f"Guest write outside modeled writable memory: {address:#x}, {size}")

    def allocate(self, size):
        size = max(16, (size + 15) & ~15)
        if self.heap_cursor + size > HEAP + HEAP_SIZE:
            raise RuntimeError("Emulated heap limit reached")
        address = self.heap_cursor
        self.heap_cursor += size
        self.allocations[address] = size
        return address

    def finish_stub(self, result, name):
        self.boundaries.append({"kind": "modeled_external", "symbol": name})
        self.uc.reg_write(regs.UC_ARM64_REG_X0, result & 0xFFFFFFFFFFFFFFFF)
        self.uc.reg_write(regs.UC_ARM64_REG_PC, self.uc.reg_read(regs.UC_ARM64_REG_X30))

    def on_code(self, uc, address, size, user_data):
        self.instruction_count += 1
        name = self.plt.get(address) or self.stubs.get(address)
        if name and name not in self.definitions:
            values = [uc.reg_read(reg) for reg in ARGUMENTS]
            a, b, c, d = values[:4]
            result = None
            if name in {"malloc", "_Znwm", "_Znam"}:
                result = self.allocate(a)
            elif name == "calloc":
                result = self.allocate(a * b)
            elif name == "realloc":
                result = self.allocate(b)
                if a:
                    count = min(self.allocations[a], b)
                    self.write_output(result, bytes(uc.mem_read(a, count)))
            elif name in {"free", "_ZdlPv", "_ZdaPv", "_ZdlPvm", "_ZdaPvm", "usleep"}:
                result = 0
            elif name in {"getpid", "osal_thread_id"}:
                result = 1
            elif name == "getenv":
                result = 0
            elif name == "getrandom":
                self.write_output(a, b"\x5a" * b)
                result = b
            elif name in {"memcmp", "strcmp", "strncmp"}:
                left = bytes(uc.mem_read(a, c)) if name == "memcmp" else self.cstring(
                    a, c if name == "strncmp" else 0x1000)
                right = bytes(uc.mem_read(b, c)) if name == "memcmp" else self.cstring(
                    b, c if name == "strncmp" else 0x1000)
                result = (left > right) - (left < right)
            elif name == "strchr":
                value = self.cstring(a)
                index = len(value) if b == 0 else value.find(bytes([b & 255]))
                result = 0 if index < 0 else a + index
            elif name == "strrchr":
                value = self.cstring(a)
                index = len(value) if b == 0 else value.rfind(bytes([b & 255]))
                result = 0 if index < 0 else a + index
            elif name == "Fsys_Open":
                label = self.cstring(a).decode("ascii")
                self.io.append({"operation": name, "path": label, "mode": c})
                permitted = {"A:/PRIVATE/M4ROOT/MEDIAPRO.XML", "A:/PRIVATE/M4ROOT/MEDIAPRO.BUP"}
                path = self.snapshot / label[3:] if label in permitted else None
                if path is None or not path.is_file():
                    result = 2
                else:
                    handle = 0x12340000 + len(self.handles)
                    data = (self.profile_override if self.profile_override is not None and
                            label.endswith("MEDIAPRO.XML") else path.read_bytes())
                    self.handles[handle] = {"data": data, "position": 0}
                    self.write_output(b, struct.pack("<Q", handle))
                    result = 0
            elif name == "Fsys_Read":
                handle = self.handles[a]
                value = handle["data"][handle["position"]:handle["position"] + c]
                self.write_output(b, value)
                handle["position"] += len(value)
                self.io.append({"operation": name, "count": len(value)})
                result = len(value)
            elif name == "Fsys_Seek":
                handle = self.handles[a]
                displacement = b - (1 << 64) if b >> 63 else b
                start = {0: 0, 1: handle["position"], 2: len(handle["data"])}[c]
                handle["position"] = start + displacement
                if not 0 <= handle["position"] <= len(handle["data"]):
                    raise RuntimeError("Modeled seek outside offline profile")
                if d:
                    self.write_output(d, struct.pack("<Q", handle["position"]))
                result = 0
            elif name in {"Fsys_Close", "Fsys_Flush"}:
                self.io.append({"operation": name, "readonly_model": True})
                result = 0
            elif name.startswith("Fsys_"):
                raise RuntimeError(f"Unmodeled or forbidden file operation {name}")
            if result is not None:
                self.finish_stub(result, name)
                return
        if address in self.stubs:
            raise RuntimeError(f"Unmodeled indirect external {name}")
        super().on_code(uc, address, size, user_data)

    def invoke(self, entry, values, limit=20000000):
        self.uc.context_restore(self.initial)
        self.boundaries, self.tail, self.visited = [], [], set()
        self.reader_pending, self.reader_returns = [], []
        for reg, value in zip(ARGUMENTS, values):
            self.uc.reg_write(reg, value)
        self.uc.emu_start(entry, RETURN, count=limit)
        if self.uc.reg_read(regs.UC_ARM64_REG_PC) != RETURN:
            raise RuntimeError(f"Instruction budget exhausted at {self.tail}")
        result = self.uc.reg_read(regs.UC_ARM64_REG_X0) & 0xFFFFFFFF
        self.calls.append({"entry_elf_vma": hex(entry), "return_u32": result,
                           "modeled_externals": sorted({row["symbol"] for row in self.boundaries
                                                        if row["kind"] != "original_internal_plt"})})
        return result

    def run(self):
        self.invoke(0x18EB3C, [self.object])
        initialized = self.invoke(0x184AA8, [self.object, self.io_adapter, 0, self.profile_path])
        loaded = self.invoke(0x186954, [self.object, 0, 0]) if initialized == 0 else None
        expat_entries = [{"symbol": name, "runtime_vma": hex(value)}
                         for name, value in self.definitions.items()
                         if name.startswith("XML_") and value in self.visited]
        count = struct.unpack("<I", self.uc.mem_read(self.object + 0xAFC60, 4))[0]
        if count > 9999:
            raise RuntimeError("Original parser count exceeds object allocation")
        materials = []
        vtable = struct.unpack("<Q", self.uc.mem_read(self.object, 8))[0]
        find_entry = struct.unpack("<Q", self.uc.mem_read(vtable + 0x68, 8))[0]
        get_clip_info = struct.unpack("<Q", self.uc.mem_read(vtable + 0x88, 8))[0]
        for index in range(count) if loaded == 0 else []:
            raw = bytes(self.uc.mem_read(self.object + 0x2C + 0x44 * index, 0x44))
            clip = struct.unpack_from("<H", raw, 8)[0]
            self.uc.mem_write(SCRATCH, b"\xff" * 4)
            status = self.invoke(find_entry, [self.object, clip, SCRATCH])
            found = struct.unpack("<I", self.uc.mem_read(SCRATCH, 4))[0]
            self.uc.mem_write(SCRATCH, bytes(0x1000))
            query = self.invoke(get_clip_info, [self.object, found, SCRATCH]) if status == 0 else None
            output = bytes(self.uc.mem_read(SCRATCH, 0x6F0))
            materials.append({"table_index": index, "clip": f"C{clip:04d}",
                              "raw_table_record_hex": raw.hex(),
                              "type_u32_at_record_start": struct.unpack_from("<I", raw)[0],
                              "umid_at_record_0a_hex": raw[10:42].hex().upper(),
                              "original_find_return": status, "original_found_index": found,
                              "original_clip_info_return": query,
                              "clip_info_name": output[:0x80].split(b"\0", 1)[0].decode("ascii"),
                              "clip_info_uri": output[0x80:0x109].split(b"\0", 1)[0].decode("ascii")})
        return {"initialized_return": initialized, "load_return": loaded,
                "material_count_at_object_afc60": count, "materials": materials,
                "original_executable_sections_unchanged": all(
                    bytes(self.uc.mem_read(address, len(raw))) == raw
                    for address, raw in self.code_sections),
                "original_expat_entrypoints_executed_during_load": expat_entries}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--firmware", default="firmware/m4-v602/usr/lib/libmpr.so")
    ap.add_argument("--expat", default="firmware/m4-v602/usr/lib/libexpat.so.1.6.11")
    ap.add_argument("--snapshot", required=True)
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    firmware, expat, snapshot, output = [Path(value).resolve() for value in
                                        (args.firmware, args.expat, args.snapshot, args.output)]
    if any(path.drive.upper() == "F:" for path in (firmware, expat, snapshot, output)):
        raise ValueError("Only offline inputs and local output are allowed")
    if not (snapshot / "_snapshot.json").is_file() or snapshot in output.parents:
        raise ValueError("Use a saved snapshot and do not modify it")
    report = {"firmware_sha256": EXPECTED, "expat_sha256": EXPAT_SHA256,
              "snapshot": str(snapshot), "card_access": False,
              "profile_sha256": hashlib.sha256(
                  (snapshot / "PRIVATE/M4ROOT/MEDIAPRO.XML").read_bytes()).hexdigest(),
              "full_camera_or_ui_emulated": False,
              "scope": "Original profile class plus original Expat, modeled libc and read-only Fsys",
              "root_cause_established": False}
    engine = None
    try:
        engine = MediaProfileEmulator(firmware, expat, snapshot)
        report["result"] = engine.run()
    except Exception as error:
        report["emulation_error"] = str(error)
    if engine is not None:
        report.update({"calls": engine.calls, "io": engine.io,
                       "heap_bytes_used": engine.heap_cursor - HEAP,
                       "instruction_count": engine.instruction_count, "last_instructions": engine.tail})
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2), encoding="utf-8")
    summary = {key: report[key] for key in ("emulation_error", "instruction_count") if key in report}
    if "result" in report:
        result = report["result"]
        summary["result"] = {key: result[key] for key in
                             ("initialized_return", "load_return", "material_count_at_object_afc60")}
        summary["successful_clip_queries"] = sum(
            row["original_find_return"] == 0 and row["original_clip_info_return"] == 0
            for row in result["materials"])
    print(json.dumps(summary, indent=2))
    if "emulation_error" in report:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
