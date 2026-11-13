"""Probe original embedded-XML parsing and basic-property extraction offline.

Runs identified original constructors, XML loading and property methods with
the existing bounded read-only firmware model. Never edits media or card data.
Failures in the emulation model are reported as errors, not camera rejection.
"""
import argparse
import hashlib
import json
import struct
from pathlib import Path
import string

from unicorn import arm64_const as regs

from emulate_xavc_reader import XavcReaderEmulator
from sony_mp4 import MP4


class NrtEngine(XavcReaderEmulator):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        merged = []
        for start, end in sorted(self.ranges):
            if merged and start <= merged[-1][1]:
                merged[-1] = (merged[-1][0], max(merged[-1][1], end))
            else:
                merged.append((start, end))
        self.ranges = merged

    def stream_at(self, pointer):
        matches = [(base, state) for base, state in getattr(self, "streams", {}).items()
                   if base <= pointer < base + 0x180]
        if len(matches) != 1:
            raise ValueError("Unmodeled standard output stream address")
        return matches[0]

    def stream_insert(self, pointer, value):
        base, state = self.stream_at(pointer)
        width = struct.unpack("<Q", self.uc.mem_read(base + 0x90, 8))[0]
        if width > 1024:
            raise ValueError("Unbounded output stream width")
        state["bytes"] += value.rjust(width, state["fill"])
        self.write_output(base + 0x90, bytes(8))
        if len(state["bytes"]) > 0x100000:
            raise ValueError("Unbounded output stream")

    def classic_ctype(self):
        if hasattr(self, "_classic_ctype"):
            return self._classic_ctype
        obj, table = self.allocate(0x300), self.allocate(512)
        vtable = self.allocate(80)
        for index, operation in enumerate(
                ("release", "release", "upper", "upper_range", "lower",
                 "lower_range", "widen", "widen_range", "narrow", "narrow_range")):
            stub = 0x70000000 + len(self.stubs) * 16
            self.stubs[stub] = "classic_ctype_" + operation
            self.write_output(vtable + index * 8, struct.pack("<Q", stub))
        self.write_output(obj, struct.pack("<Q", vtable))
        masks = []
        for value in range(256):
            char = chr(value)
            mask = 0
            for enabled, bit in (
                (char in string.ascii_uppercase, 0x100),
                (char in string.ascii_lowercase, 0x200),
                (char in string.ascii_letters, 0x400),
                (char in string.digits, 0x800),
                (char in string.hexdigits, 0x1000),
                (char in " \t\n\r\v\f", 0x2000),
                (32 <= value < 127, 0x4000),
                (33 <= value < 127, 0x8000),
                (char in " \t", 1), (value < 32 or value == 127, 2),
                (char in string.punctuation, 4),
                (char in string.ascii_letters + string.digits, 8),
            ):
                if enabled:
                    mask |= bit
            masks.append(mask)
        self.write_output(table, struct.pack("<256H", *masks))
        # GCC 6 ctype<char>: table at +0x30; identity widen cache at +0x39.
        self.write_output(obj + 0x30, struct.pack("<Q", table))
        self.write_output(obj + 0x38, b"\x01" + bytes(range(256)))
        self._classic_ctype = obj
        return obj

    def read_string(self, address):
        pointer, length = struct.unpack("<QQ", self.uc.mem_read(address, 16))
        if length > 0x100000:
            raise ValueError("Unbounded standard string")
        return bytes(self.uc.mem_read(pointer, length))

    def assign_string(self, address, value):
        pointer = struct.unpack("<Q", self.uc.mem_read(address, 8))[0]
        capacity = (15 if pointer == address + 16 else
                    struct.unpack("<Q", self.uc.mem_read(address + 16, 8))[0])
        if len(value) > 0x100000 or capacity > 0x100000:
            raise ValueError("Unbounded standard string assignment")
        if len(value) > capacity:
            capacity = max(len(value), capacity * 2)
            pointer = self.allocate(capacity + 1)
            self.write_output(address, struct.pack("<Q", pointer))
            self.write_output(address + 16, struct.pack("<Q", capacity))
        self.write_output(pointer, value + b"\0")
        self.write_output(address + 8, struct.pack("<Q", len(value)))

    def on_code(self, uc, address, size, user_data):
        if not hasattr(self, "semantic_trace"):
            self.semantic_trace, self.semantic_pending = [], []
        if self.semantic_pending and address == self.semantic_pending[-1][0]:
            _, item = self.semantic_pending.pop()
            item["return_u32"] = uc.reg_read(regs.UC_ARM64_REG_X0) & 0xffffffff
        if address in {0x24bf44, 0x23d394, 0x23a018}:
            item = {"entry_elf_vma": hex(address)}
            if address == 0x24bf44:
                item["codec_literal"] = self.read_string(
                    uc.reg_read(regs.UC_ARM64_REG_X0)).decode("ascii")
            if address == 0x23a018:
                item["nrt_status_input"] = uc.reg_read(regs.UC_ARM64_REG_X0) & 0xffffffff
            self.semantic_trace.append(item)
            self.semantic_pending.append((uc.reg_read(regs.UC_ARM64_REG_X30), item))
        name = self.plt.get(address) or self.stubs.get(address)
        if name is None:
            super().on_code(uc, address, size, user_data)
            return
        if name == "_ZNSt7__cxx1119basic_istringstreamIcSt11char_traitsIcESaIcEEC1ERKNS_12basic_stringIcS2_S3_EESt13_Ios_Openmode":
            base, source, mode = [uc.reg_read(reg) for reg in
                                  (regs.UC_ARM64_REG_X0, regs.UC_ARM64_REG_X1,
                                   regs.UC_ARM64_REG_X2)]
            if mode != 8:
                raise ValueError("Only input stringstream mode is modeled")
            if not hasattr(self, "streams"):
                self.streams = {}
            self.streams[base] = {"bytes": self.read_string(source), "base": 10, "position": 0}
            self.write_output(base + 0x98, bytes(4))
            self.finish_stub(0, "standard_integer_istringstream_constructor")
            return
        if name == "_ZNSt7__cxx1119basic_istringstreamIcSt11char_traitsIcESaIcEED1Ev":
            base, _ = self.stream_at(uc.reg_read(regs.UC_ARM64_REG_X0))
            del self.streams[base]
            self.finish_stub(0, "standard_integer_istringstream_destructor")
            return
        if name == "_ZNSirsEPFRSt8ios_baseS0_E":
            pointer, manipulator = [uc.reg_read(reg) for reg in
                                    (regs.UC_ARM64_REG_X0, regs.UC_ARM64_REG_X1)]
            _, state = self.stream_at(pointer)
            known = {struct.unpack("<Q", uc.mem_read(0x301d00, 8))[0]: 8,
                     struct.unpack("<Q", uc.mem_read(0x302ee0, 8))[0]: 16}
            if manipulator not in known:
                raise ValueError("Unmodeled input stream manipulator")
            state["base"] = known[manipulator]
            self.finish_stub(pointer, "standard_integer_input_stream_base")
            return
        if name in {"_ZNSirsERl", "_ZNSirsERj", "_ZNSirsERt"}:
            pointer, destination = [uc.reg_read(reg) for reg in
                                    (regs.UC_ARM64_REG_X0, regs.UC_ARM64_REG_X1)]
            obj, state = self.stream_at(pointer)
            raw, pos, radix = state["bytes"], state["position"], state["base"]
            while pos < len(raw) and raw[pos] in b" \t\r\n\v\f":
                pos += 1
            sign = 1
            if raw[pos:pos + 1] in (b"+", b"-"):
                sign = -1 if raw[pos] == ord("-") else 1
                pos += 1
            if radix == 16 and raw[pos:pos + 2].lower() == b"0x":
                pos += 2
            first, value = pos, 0
            while pos < len(raw):
                digit = b"0123456789abcdef".find(raw[pos:pos + 1].lower())
                if not 0 <= digit < radix:
                    break
                value, pos = value * radix + digit, pos + 1
            width = {"_ZNSirsERl": 64, "_ZNSirsERj": 32, "_ZNSirsERt": 16}[name]
            low, high = (-(1 << 63), (1 << 63) - 1) if width == 64 else (0, (1 << width) - 1)
            value *= sign
            flags = (4 if pos == first or not low <= value <= high else 0) | (
                2 if pos == len(raw) else 0)
            value = min(high, max(low, value)) & ((1 << width) - 1)
            state["position"] = pos
            self.write_output(destination, value.to_bytes(width // 8, "little"))
            self.write_output(obj + 0x98, struct.pack("<I", flags))
            self.finish_stub(pointer, "standard_integer_input_stream_extract")
            return
        if name == "_ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEEC1ESt13_Ios_Openmode":
            base, mode = [uc.reg_read(reg) for reg in
                          (regs.UC_ARM64_REG_X0, regs.UC_ARM64_REG_X1)]
            if mode != 0x18:
                raise ValueError("Only decimal in/out stringstream is modeled")
            if not hasattr(self, "streams"):
                self.streams = {}
            self.streams[base] = {"bytes": b"", "fill": b" "}
            vtable = self.allocate(64)
            self.write_output(vtable, struct.pack("<Q", 0x70))
            self.write_output(base + 16, struct.pack("<Q", vtable + 24))
            self.write_output(base + 0x90, bytes(8))
            self.finish_stub(0, "standard_decimal_stringstream_constructor")
            return
        if name == "_ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEED1Ev":
            base, _ = self.stream_at(uc.reg_read(regs.UC_ARM64_REG_X0))
            del self.streams[base]
            self.finish_stub(0, "standard_decimal_stringstream_destructor")
            return
        if name == "_ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St8_SetfillIS3_E":
            pointer, char = [uc.reg_read(reg) for reg in
                             (regs.UC_ARM64_REG_X0, regs.UC_ARM64_REG_X1)]
            _, state = self.stream_at(pointer)
            state["fill"] = bytes([char & 255])
            self.finish_stub(pointer, "standard_output_stream_setfill")
            return
        if name in {
                "_ZNSolsEi", "_ZNSolsEs", "_ZNSolsEt", "_ZNSolsEj",
                "_ZNSolsEl", "_ZNSolsEm", "_ZNSo9_M_insertImEERSoT_",
                "_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c",
                "_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc"}:
            pointer, value = [uc.reg_read(reg) for reg in
                              (regs.UC_ARM64_REG_X0, regs.UC_ARM64_REG_X1)]
            if name == "_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c":
                raw = bytes([value & 255])
            elif name == "_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc":
                raw = self.cstring(value)
            else:
                bits = (16 if name in {"_ZNSolsEs", "_ZNSolsEt"} else
                        32 if name in {"_ZNSolsEi", "_ZNSolsEj"} else 64)
                value &= (1 << bits) - 1
                if name in {"_ZNSolsEi", "_ZNSolsEs", "_ZNSolsEl"} and value >> (bits - 1):
                    value -= 1 << bits
                raw = str(value).encode("ascii")
            self.stream_insert(pointer, raw)
            self.finish_stub(pointer, "standard_decimal_output_stream_insert")
            return
        if name == "_ZNKSt7__cxx1115basic_stringbufIcSt11char_traitsIcESaIcEE3strEv":
            _, state = self.stream_at(uc.reg_read(regs.UC_ARM64_REG_X0))
            destination = uc.reg_read(regs.UC_ARM64_REG_X8)
            self.write_output(destination, struct.pack("<QQ", destination + 16, 0) + bytes(16))
            self.assign_string(destination, state["bytes"])
            self.finish_stub(0, "standard_stringbuf_copy_contents")
            return
        if name == "snprintf":
            values = [uc.reg_read(getattr(regs, f"UC_ARM64_REG_X{i}")) for i in range(7)]
            destination, capacity, fmt = values[:3]
            if self.cstring(fmt) == b"%s%02d%s%02d":
                raw = (self.cstring(values[3]) + f"{values[4]:02d}".encode("ascii") +
                       self.cstring(values[5]) + f"{values[6]:02d}".encode("ascii"))
                if capacity:
                    self.write_output(destination, raw[:capacity - 1] + b"\0")
                self.finish_stub(len(raw), "standard_snprintf_timezone")
                return
        if name and name.startswith("classic_ctype_"):
            a, b, c, d = [uc.reg_read(reg) for reg in
                          (regs.UC_ARM64_REG_X0, regs.UC_ARM64_REG_X1,
                           regs.UC_ARM64_REG_X2, regs.UC_ARM64_REG_X3)]
            operation = name.removeprefix("classic_ctype_")
            if operation == "release":
                value = 0
            elif operation.endswith("_range"):
                if not 0 <= c - b <= 0x100000:
                    raise ValueError("Unbounded ctype range")
                raw = bytes(uc.mem_read(b, c - b))
                if operation.startswith("upper"):
                    raw = raw.upper()
                elif operation.startswith("lower"):
                    raw = raw.lower()
                destination = b if operation.startswith(("upper", "lower")) else d
                self.write_output(destination, raw)
                value = c
            else:
                raw = bytes([b & 255])
                value = (raw.upper() if operation == "upper" else
                         raw.lower() if operation == "lower" else raw)[0]
            self.finish_stub(value, name)
            return
        if name and ("locale" in name or "use_facet" in name):
            a, b = [uc.reg_read(reg) for reg in
                    (regs.UC_ARM64_REG_X0, regs.UC_ARM64_REG_X1)]
            if name == "_ZNSt6localeC1Ev":
                if not hasattr(self, "_classic_locale"):
                    self._classic_locale = self.allocate(0x40)
                    facets = self.allocate(8)
                    self.write_output(facets, struct.pack("<Q", self.classic_ctype()))
                    self.write_output(self._classic_locale,
                                      struct.pack("<QQQ", 1, facets, 1))
                self.write_output(a, struct.pack("<Q", self._classic_locale))
                self.finish_stub(0, "standard_classic_locale_constructor")
                return
            if name in {"_ZNSt6localeC1ERKS_", "_ZNSt6localeaSERKS_"}:
                self.write_output(a, bytes(uc.mem_read(b, 8)))
                self.finish_stub(a, "standard_classic_locale_copy")
                return
            if name == "_ZNSt6localeD1Ev":
                self.finish_stub(0, "standard_classic_locale_release")
                return
            if name == "_ZSt9use_facetISt5ctypeIcEERKT_RKSt6locale":
                self.finish_stub(self.classic_ctype(), "standard_classic_ascii_ctype_facet")
                return
            if name == "_ZSt9use_facetINSt7__cxx117collateIcEEERKT_RKSt6locale":
                if not hasattr(self, "_classic_collate"):
                    self._classic_collate = self.allocate(16)
                self.finish_stub(self._classic_collate, "standard_classic_collate_facet")
                return
            if name == "_ZNKSt6locale2id5_M_idEv":
                self.finish_stub(0, "standard_classic_ctype_facet_id")
                return
        if name == "_ZSt19__throw_regex_errorNSt15regex_constants10error_typeE":
            raise RuntimeError(f"Original regex error {uc.reg_read(regs.UC_ARM64_REG_X0)}")
        if name == "_ZNKSt7__cxx117collateIcE9transformEPKcS3_":
            first, last, destination = [
                uc.reg_read(reg) for reg in
                (regs.UC_ARM64_REG_X1, regs.UC_ARM64_REG_X2, regs.UC_ARM64_REG_X8)]
            if not 0 <= last - first <= 0x100000:
                raise ValueError("Unbounded classic collation range")
            self.write_output(destination, struct.pack("<QQ", destination + 16, 0) + bytes(16))
            self.assign_string(destination, bytes(uc.mem_read(first, last - first)))
            self.finish_stub(0, "standard_classic_collation_identity_transform")
            return
        prefix = "_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE"
        const_prefix = "_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE"
        if name and name.startswith(const_prefix):
            suffix = name[len(const_prefix):]
            a, b, c = [uc.reg_read(reg) for reg in
                       (regs.UC_ARM64_REG_X0, regs.UC_ARM64_REG_X1, regs.UC_ARM64_REG_X2)]
            if suffix in {"7compareEPKc", "7compareERKS4_"}:
                left = self.read_string(a)
                right = self.cstring(b) if suffix.endswith("EPKc") else self.read_string(b)
                self.finish_stub((left > right) - (left < right),
                                 "standard_string_compare_exact_bytes")
                return
            if suffix in {"4findEcm", "4findEPKcm", "4findERKS4_m"}:
                needle = (bytes([b & 255]) if suffix == "4findEcm" else
                          self.cstring(b) if suffix == "4findEPKcm" else self.read_string(b))
                value = self.read_string(a)
                self.finish_stub(value.find(needle, min(c, len(value) + 1)),
                                 "standard_string_find_exact_bytes")
                return
            if suffix == "6substrEmm":
                value = self.read_string(a)
                if b > len(value):
                    raise ValueError("String substring position out of bounds")
                destination = uc.reg_read(regs.UC_ARM64_REG_X8)
                self.write_output(destination,
                                  struct.pack("<QQ", destination + 16, 0) + bytes(16))
                self.assign_string(destination, value[b:b + min(c, len(value) - b)])
                self.finish_stub(0, "standard_string_substring_copy")
                return
            if suffix in {"5rfindEPKcm", "5rfindEcm"}:
                value = self.read_string(a)
                needle = bytes([b & 255]) if suffix == "5rfindEcm" else self.cstring(b)
                position = min(c, len(value))
                found = (position if not needle else
                         value.rfind(needle, 0, min(len(value), position + len(needle))))
                self.finish_stub(found, "standard_string_reverse_find_exact_bytes")
                return
            if suffix == "2atEm":
                if b >= len(self.read_string(a)):
                    raise ValueError("String at() out of bounds")
                pointer = struct.unpack("<Q", uc.mem_read(a, 8))[0]
                self.finish_stub(pointer + b, "standard_string_at_bounded")
                return
        if name and name.startswith(prefix):
            suffix = name[len(prefix):]
            a, b, c, d = [uc.reg_read(reg) for reg in
                          (regs.UC_ARM64_REG_X0, regs.UC_ARM64_REG_X1,
                           regs.UC_ARM64_REG_X2, regs.UC_ARM64_REG_X3)]
            if suffix == "9push_backEc":
                self.assign_string(a, self.read_string(a) + bytes([b & 255]))
                self.finish_stub(0, "standard_string_push_back_void")
                return
            if suffix == "D1Ev":
                self.finish_stub(0, "standard_string_destructor_heap_not_reused")
                return
            if suffix == "pLERKS4_":
                self.assign_string(a, self.read_string(a) + self.read_string(b))
                self.finish_stub(a, "standard_string_append_string")
                return
            if suffix in {"6insertEmPKc", "6insertEmRKS4_", "7replaceEmmPKc", "7replaceEmmRKS4_"}:
                value = self.read_string(a)
                if b > len(value):
                    raise ValueError("String edit position out of bounds")
                source = c if suffix.startswith("6insert") else d
                replacement = self.cstring(source) if suffix.endswith("PKc") else self.read_string(source)
                count = 0 if suffix.startswith("6insert") else min(c, len(value) - b)
                self.assign_string(a, value[:b] + replacement + value[b + count:])
                self.finish_stub(a, "standard_string_insert_or_replace_exact_bytes")
                return
            if suffix == "5eraseEN9__gnu_cxx17__normal_iteratorIPKcS4_EES9_":
                value = self.read_string(a)
                pointer = struct.unpack("<Q", uc.mem_read(a, 8))[0]
                if not pointer <= b <= c <= pointer + len(value):
                    raise ValueError("String erase iterator range out of bounds")
                self.assign_string(a, value[:b - pointer] + value[c - pointer:])
                self.finish_stub(b, "standard_string_erase_iterator_range")
                return
            if suffix == "2atEm":
                if b >= len(self.read_string(a)):
                    raise ValueError("String at() out of bounds")
                pointer = struct.unpack("<Q", uc.mem_read(a, 8))[0]
                self.finish_stub(pointer + b, "standard_string_at_bounded")
                return
            if suffix in {"12_M_constructEmc", "6appendEmc", "aSEc"}:
                count, char = (1, b) if suffix == "aSEc" else (b, c)
                if count > 0x100000:
                    raise ValueError("Unbounded string count/char operation")
                value = bytes([char & 255]) * count
                if suffix == "12_M_constructEmc":
                    self.write_output(a, struct.pack("<QQ", a + 16, 0) + bytes(16))
                elif suffix == "6appendEmc":
                    value = self.read_string(a) + value
                self.assign_string(a, value)
                self.finish_stub(0 if suffix == "12_M_constructEmc" else a,
                                 "standard_string_count_char_" + suffix)
                return
            if suffix in {"6appendEPKcm", "6appendEPKc", "pLEPKc"}:
                if suffix == "6appendEPKcm":
                    if c > 0x100000:
                        raise ValueError("Unbounded string append")
                    value = bytes(uc.mem_read(b, c))
                else:
                    value = self.cstring(b)
                self.assign_string(a, self.read_string(a) + value)
                self.finish_stub(a, "standard_string_append_range")
                return
            if suffix in {"6assignEPKc", "aSEPKc"}:
                self.assign_string(a, self.cstring(b))
                self.finish_stub(a, "standard_string_assign_c_string")
                return
            if suffix in {"aSEOS4_", "6assignEOS4_"}:
                if a != b:
                    pointer = struct.unpack("<Q", uc.mem_read(b, 8))[0]
                    if pointer == b + 16:
                        self.assign_string(a, self.read_string(b))
                    else:
                        self.write_output(a, bytes(uc.mem_read(b, 32)))
                    self.write_output(b, struct.pack("<QQ", b + 16, 0) + bytes(16))
                self.finish_stub(a, "standard_string_move_assignment_heap_not_reused")
                return
            if suffix == "5eraseEmm":
                value = self.read_string(a)
                if b > len(value):
                    raise ValueError("String erase position out of bounds")
                self.assign_string(a, value[:b] + value[b + min(c, len(value) - b):])
                self.finish_stub(a, "standard_string_erase_position_count")
                return
            if suffix == "7reserveEm":
                value = self.read_string(a)
                if b > 0x100000:
                    raise ValueError("Unbounded string reserve")
                pointer = struct.unpack("<Q", uc.mem_read(a, 8))[0]
                capacity = (15 if pointer == a + 16 else
                            struct.unpack("<Q", uc.mem_read(a + 16, 8))[0])
                if b > capacity:
                    pointer = self.allocate(b + 1)
                    self.write_output(a, struct.pack("<QQQ", pointer, len(value), b))
                    self.write_output(pointer, value + b"\0")
                self.finish_stub(0, "standard_string_reserve_void")
                return
        if name == "_ZNSt8ios_base4InitC1Ev" and name not in self.definitions:
            self.finish_stub(0, "iostream_initialization_unused_by_xml_probe")
            return
        if name == "__cxa_atexit" and name not in self.definitions:
            self.finish_stub(0, "deferred_destructor_registration_no_process_exit")
            return
        if name in {
                "_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsEPcPKcS7_",
                "_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_S_copy_charsEPcS5_S5_"}:
            destination, first, last = [
                uc.reg_read(reg) for reg in
                (regs.UC_ARM64_REG_X0, regs.UC_ARM64_REG_X1, regs.UC_ARM64_REG_X2)]
            if not 0 <= last - first <= 0x100000:
                raise ValueError("Unbounded standard string copy")
            self.write_output(destination, bytes(uc.mem_read(first, last - first)))
            self.finish_stub(0, "standard_string_copy_exact_range_void")
            return
        if name == "_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm":
            capacity_cell, old_capacity = [
                uc.reg_read(reg) for reg in (regs.UC_ARM64_REG_X1, regs.UC_ARM64_REG_X2)]
            capacity = struct.unpack("<Q", uc.mem_read(capacity_cell, 8))[0]
            if not capacity <= 0x100000 or not old_capacity <= 0x100000:
                raise ValueError("Unbounded standard string capacity")
            if old_capacity < capacity < 2 * old_capacity:
                capacity = 2 * old_capacity
            self.write_output(capacity_cell, struct.pack("<Q", capacity))
            self.finish_stub(self.allocate(capacity + 1), "standard_string_capacity_allocation")
            return
        if name == "_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_":
            destination, source = [
                uc.reg_read(reg) for reg in (regs.UC_ARM64_REG_X0, regs.UC_ARM64_REG_X1)]
            pointer, length = struct.unpack("<QQ", uc.mem_read(source, 16))
            if length > 0x100000:
                raise ValueError("Unbounded standard string copy constructor")
            value = bytes(uc.mem_read(pointer, length)) + b"\0"
            storage = destination + 16 if length <= 15 else self.allocate(length + 1)
            self.write_output(destination, struct.pack("<QQ", storage, length) + bytes(16))
            if length > 15:
                self.write_output(destination + 16, struct.pack("<Q", length))
            self.write_output(storage, value)
            self.finish_stub(0, "standard_string_deep_copy_constructor_void")
            return
        if name == "_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_":
            destination, source = [
                uc.reg_read(reg) for reg in (regs.UC_ARM64_REG_X0, regs.UC_ARM64_REG_X1)]
            pointer, length = struct.unpack("<QQ", uc.mem_read(source, 16))
            if length > 0x100000:
                raise ValueError("Unbounded standard string move")
            if pointer == source + 16:
                value = bytes(uc.mem_read(pointer, length)) + b"\0"
                self.write_output(destination, struct.pack("<QQ", destination + 16, length) +
                                  value.ljust(16, b"\0"))
            else:
                self.write_output(destination, bytes(uc.mem_read(source, 32)))
            self.write_output(source, struct.pack("<QQ", source + 16, 0))
            self.write_output(source + 16, b"\0")
            self.finish_stub(0, "standard_string_move_constructor_void")
            return
        if name == "_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE10_M_disposeEv":
            self.finish_stub(0, "standard_string_release_heap_not_reused")
            return
        if name == "_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendERKS4_":
            destination, source = [
                uc.reg_read(reg) for reg in (regs.UC_ARM64_REG_X0, regs.UC_ARM64_REG_X1)]
            value = self.read_string(destination) + self.read_string(source)
            self.assign_string(destination, value)
            self.finish_stub(destination, "standard_string_append_exact_bytes")
            return
        if name == "_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_assignERKS4_":
            destination, source = [
                uc.reg_read(reg) for reg in (regs.UC_ARM64_REG_X0, regs.UC_ARM64_REG_X1)]
            self.assign_string(destination, self.read_string(source))
            self.finish_stub(0, "standard_string_assign_exact_bytes_void")
            return
        if name == "_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6assignEmc":
            destination, count, char = [
                uc.reg_read(reg) for reg in
                (regs.UC_ARM64_REG_X0, regs.UC_ARM64_REG_X1, regs.UC_ARM64_REG_X2)]
            if count > 0x100000:
                raise ValueError("Unbounded standard string fill")
            self.assign_string(destination, bytes([char & 255]) * count)
            self.finish_stub(destination, "standard_string_assign_count_char")
            return
        if name == "_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSERKS4_":
            destination, source = [
                uc.reg_read(reg) for reg in (regs.UC_ARM64_REG_X0, regs.UC_ARM64_REG_X1)]
            self.assign_string(destination, self.read_string(source))
            self.finish_stub(destination, "standard_string_copy_assignment")
            return
        if name == "_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4findEPKcm":
            source, needle, position = [
                uc.reg_read(reg) for reg in
                (regs.UC_ARM64_REG_X0, regs.UC_ARM64_REG_X1, regs.UC_ARM64_REG_X2)]
            self.finish_stub(self.read_string(source).find(self.cstring(needle), position),
                             "standard_string_find_exact_bytes")
            return
        if name == "atoi":
            source = uc.reg_read(regs.UC_ARM64_REG_X0)
            import re
            matched = re.match(rb"\s*([+-]?[0-9]+)", self.cstring(source))
            self.finish_stub(int(matched[1]) if matched else 0, "standard_atoi_decimal")
            return
        if name == "strtol":
            source, endptr, base = [
                uc.reg_read(reg) for reg in
                (regs.UC_ARM64_REG_X0, regs.UC_ARM64_REG_X1, regs.UC_ARM64_REG_X2)]
            if base != 0 and not 2 <= base <= 36:
                raise ValueError("Invalid strtol base")
            raw, pos, sign = self.cstring(source), 0, 1
            while pos < len(raw) and raw[pos] in b" \t\r\n\v\f":
                pos += 1
            if pos < len(raw) and raw[pos] in b"+-":
                sign = -1 if raw[pos] == ord("-") else 1
                pos += 1
            if (base in (0, 16) and raw[pos:pos + 2].lower() == b"0x" and
                    pos + 2 < len(raw) and chr(raw[pos + 2]) in string.hexdigits):
                base, pos = 16, pos + 2
            elif base == 0:
                base = 8 if raw[pos:pos + 1] == b"0" else 10
            begin, value = pos, 0
            while pos < len(raw):
                digit = b"0123456789abcdefghijklmnopqrstuvwxyz".find(raw[pos:pos + 1].lower())
                if not 0 <= digit < base:
                    break
                value, pos = value * base + digit, pos + 1
            value *= sign
            if not -(1 << 63) <= value < 1 << 63:
                raise ValueError("strtol overflow requires errno modeling")
            if endptr:
                self.write_output(endptr, struct.pack("<Q", source + (pos if pos > begin else 0)))
            self.finish_stub(value, "standard_strtol_classic_locale_bounded")
            return
        super().on_code(uc, address, size, user_data)


def probe(media, firmware, expat, snapshot, replacement=None):
    m = MP4(media)
    try:
        raw = m.payload(m.child(m.one(m.top, "meta"), "xml ", 4))[4:].rstrip(b"\0 ")
    finally:
        m.close()
    original = raw
    if replacement:
        old, new = (v.encode("ascii") for v in replacement.split("=", 1))
        if not old or raw.count(old) != 1:
            raise ValueError("Control must replace exactly one literal")
        raw = raw.replace(old, new)
    e = NrtEngine(firmware, expat, snapshot, media.read_bytes(), max_seconds=600)
    result = {
        "media": str(media), "media_sha256": hashlib.sha256(media.read_bytes()).hexdigest(),
        "original_xml_sha256": hashlib.sha256(original).hexdigest(),
        "probe_xml_sha256": hashlib.sha256(raw).hexdigest(),
        "in_memory_replacement": replacement, "card_access": False,
        "firmware_sha256": hashlib.sha256(firmware.read_bytes()).hexdigest(),
        "expat_sha256": hashlib.sha256(expat.read_bytes()).hexdigest(),
        "original_stdcpp_sha256": e.runtime_sha256,
        "probe_implementation_sha256": hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        "scope": "Original NRT semantic parsing/basic-information extraction; not full camera repair",
        "runtime_model": (
            "Bounded GNU ABI strings, classic C-locale ctype/collation, decimal output "
            "stringstreams, libc/allocator; Sony validation functions are not stubbed"),
    }
    try:
        e.step("original_xml_schema_static_initialization", 0x8c3e0, [], False)
        e.step("original_nrt_static_initialization", 0x8cff4, [], False)
        obj, text, basic, count, status = [e.allocate(n) for n in (0x80, len(raw) + 1, 0x100, 8, 8)]
        e.uc.mem_write(text, raw + b"\0")
        e.step("nrt_wrapper_constructor", 0x252de0, [obj], False)
        loaded = e.step("load_embedded_xml", 0x253e8c, [obj, text, len(raw)])
        result["load_return_u32"] = loaded
        if loaded == 0:
            extracted = e.step("get_basic_information", 0x2543fc, [obj, basic])
            result["basic_information_return_u32"] = extracted
            result["basic_information_hex"] = bytes(e.uc.mem_read(basic, 0x80)).hex()
            if extracted == 0:
                result["mark_count_return_u32"] = e.step("get_mark_count", 0x254f88, [obj, count])
                result["mark_count"] = struct.unpack("<I", e.uc.mem_read(count, 4))[0]
                result["clip_status_return_u32"] = e.step("get_clip_status", 0x254304, [obj, status])
        e.step("nrt_wrapper_destructor", 0x252bb4, [obj], False)
    except Exception as error:
        result["emulation_error"] = type(error).__name__ + ": " + str(error)
        result["tail"] = e.tail
        result["guest_registers_at_failure"] = {
            f"x{i}": hex(e.uc.reg_read(getattr(regs, f"UC_ARM64_REG_X{i}")))
            for i in range(31)}
    result["steps"] = e.steps
    result["active_step"] = e.active_step
    result["calls"] = e.calls
    result["semantic_trace"] = getattr(e, "semantic_trace", [])
    result["instruction_count"] = e.instruction_count
    result["original_executable_sections_unchanged"] = all(
        bytes(e.uc.mem_read(address, len(code))) == code for address, code in e.code_sections)
    result["local_media_unchanged"] = (
        hashlib.sha256(media.read_bytes()).hexdigest() == result["media_sha256"])
    if not result["local_media_unchanged"]:
        raise RuntimeError("Local media changed during probe")
    return result


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("media")
    ap.add_argument("--snapshot", required=True)
    ap.add_argument("--output", required=True)
    ap.add_argument("--replace")
    ap.add_argument("--firmware", default="firmware/m4-v602/usr/lib/libmpr.so")
    ap.add_argument("--expat", default="firmware/m4-v602/usr/lib/libexpat.so.1.6.11")
    args = ap.parse_args()
    paths = [Path(v).resolve() for v in
             (args.media, args.firmware, args.expat, args.snapshot, args.output)]
    if (any(p.drive.upper() == "F:" for p in paths) or paths[-1].exists() or
            paths[3] in paths[-1].parents or
            not (paths[3] / "_snapshot.json").is_file()):
        raise ValueError("Use local inputs and a fresh local report")
    result = probe(*paths[:4], replacement=args.replace)
    paths[-1].write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps({k: v for k, v in result.items() if k in {
        "emulation_error", "load_return_u32", "basic_information_return_u32",
        "mark_count_return_u32", "clip_status_return_u32",
        "original_executable_sections_unchanged", "active_step"}}, indent=2))
    if "emulation_error" in result:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
