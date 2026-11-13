"""Check bounded standard runtime models and original Sony codec lookup."""
import struct
import sys
import unittest
from pathlib import Path

from unicorn import arm64_const as regs

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from emulate_nrt_semantics import NrtEngine

ROOT = Path(__file__).resolve().parents[2]
FIRMWARE = ROOT / "firmware/m4-v602/usr/lib"
STRING = "_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE"
CONST_STRING = "_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE"


@unittest.skipUnless((FIRMWARE / "libmpr.so").is_file(), "Requires saved Sony firmware")
class NrtRuntimeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.engine = NrtEngine(FIRMWARE / "libmpr.so", FIRMWARE / "libexpat.so.1.6.11",
                               ROOT / "backup/snap_20261113T221317", b"", max_seconds=600)
        cls.engine.step("original_nrt_enum_initialization", 0x8cff4, [], False)

    def call(self, symbol, *args):
        entry = next(address for address, name in self.engine.plt.items() if name == symbol)
        return self.engine.invoke(entry, args)

    def string(self, value):
        obj = self.engine.allocate(32)
        self.engine.write_output(obj, struct.pack("<QQ", obj + 16, 0) + bytes(16))
        self.engine.assign_string(obj, value)
        return obj

    def test_original_lookup_distinguishes_level_spelling_without_patching_sony_code(self):
        e = self.engine
        for name, expected in (
                (b"AVC_1920_1080_HP@L4", 0x4c),
                (b"AVC_1920_1080_HP@L40", 0x9a),
                (b"AVC_1920_1080_HP@L41", 0x4d),
                (b"AVC_1920_1080_HP@L42", 0x4e),
                (b"not-a-codec", 0x9a)):
            self.assertEqual(e.invoke(0x24bf44, [self.string(name)]), expected)
        self.assertTrue(all(bytes(e.uc.mem_read(address, len(code))) == code
                            for address, code in e.code_sections))

    def test_string_sso_growth_copy_append_erase_and_move(self):
        e = self.engine
        source, target = self.string(b"0123456789abcdefghijkl"), self.string(b"")
        self.call(STRING + "9_M_assignERKS4_", target, source)
        self.assertEqual(e.read_string(target), b"0123456789abcdefghijkl")
        self.call(STRING + "9push_backEc", target, ord("!"))
        self.call(STRING + "5eraseEmm", target, 2, 5)
        self.assertEqual(e.read_string(target), b"01789abcdefghijkl!")
        moved = self.string(b"old")
        self.call(STRING + "aSEOS4_", moved, target)
        self.assertEqual(e.read_string(moved), b"01789abcdefghijkl!")
        self.assertEqual(e.read_string(target), b"")
        self.call(STRING + "7reserveEm", moved, 1)
        self.assertEqual(e.read_string(moved), b"01789abcdefghijkl!")
        self.call(STRING + "6assignEmc", moved, 6, ord("0"))
        self.assertEqual(e.read_string(moved), b"000000")

    def test_string_find_boundary_and_comparison(self):
        e = self.engine
        obj = self.string(b"AbC")
        self.assertEqual(self.call(CONST_STRING + "4findEcm", obj, ord("b"), 0), 1)
        self.assertEqual(self.call(CONST_STRING + "4findEcm", obj, ord("b"), 2), 0xffffffff)
        empty = e.allocate(16)
        e.write_output(empty, b"\0")
        self.assertEqual(self.call(CONST_STRING + "4findEPKcm", obj, empty, 3), 3)
        self.assertEqual(self.call(CONST_STRING + "4findEPKcm", obj, empty, 4), 0xffffffff)
        other = self.string(b"AbD")
        self.assertEqual(self.call(CONST_STRING + "7compareERKS4_", obj, other), 0xffffffff)

    def test_classic_ctype_masks_and_identity_widen_cache(self):
        e = self.engine
        obj = e.classic_ctype()
        table = struct.unpack("<Q", e.uc.mem_read(obj + 0x30, 8))[0]
        mask = lambda char: struct.unpack("<H", e.uc.mem_read(table + 2 * ord(char), 2))[0]
        self.assertTrue(mask("5") & 0x800)
        self.assertFalse(mask("A") & 0x800)
        self.assertTrue(mask("A") & 0x100)
        self.assertTrue(mask("a") & 0x200)
        self.assertTrue(mask("\t") & 0x2000)
        self.assertFalse(mask("-") & 0x2000)
        self.assertEqual(bytes(e.uc.mem_read(obj + 0x39, 256)), bytes(range(256)))

    def test_strtol_base_sign_end_pointer_and_no_conversion(self):
        e = self.engine
        source, end = e.allocate(64), e.allocate(8)
        for text, base, expected, consumed in (
                (b"  -123tail", 10, -123, 6), (b"0x2a?", 0, 42, 4),
                (b"077stop", 0, 63, 3), (b"FFend", 16, 4094, 3),
                (b" +nothing", 10, 0, 0), (b"0x", 16, 0, 1)):
            e.write_output(source, text + b"\0")
            self.call("strtol", source, end, base)
            actual = e.uc.reg_read(regs.UC_ARM64_REG_X0)
            if actual >> 63:
                actual -= 1 << 64
            self.assertEqual(actual, expected)
            self.assertEqual(struct.unpack("<Q", e.uc.mem_read(end, 8))[0], source + consumed)

    def test_decimal_output_stream_width_fill_and_reset(self):
        e = self.engine
        obj = e.allocate(0x180)
        self.call("_ZNSt7__cxx1118basic_stringstreamIcSt11char_traitsIcESaIcEEC1ESt13_Ios_Openmode",
                  obj, 0x18)
        self.call("_ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St8_SetfillIS3_E",
                  obj + 16, ord("0"))
        e.write_output(obj + 0x90, struct.pack("<Q", 4))
        self.call("_ZNSolsEi", obj + 16, 26)
        self.call("_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c", obj + 16, ord("-"))
        self.call("_ZNSolsEi", obj + 16, 13)
        self.assertEqual(e.streams[obj]["bytes"], b"0026-13")
        self.assertEqual(bytes(e.uc.mem_read(obj + 0x90, 8)), bytes(8))

    def test_integer_input_stream_digits_and_failure_state(self):
        e = self.engine
        constructor = "_ZNSt7__cxx1119basic_istringstreamIcSt11char_traitsIcESaIcEEC1ERKNS_12basic_stringIcS2_S3_EESt13_Ios_Openmode"
        destructor = "_ZNSt7__cxx1119basic_istringstreamIcSt11char_traitsIcESaIcEED1Ev"
        for text, expected, state in ((b"27", 27, 2), (b"q", 0, 4), (b"-2", -2, 2)):
            stream, output = e.allocate(0x180), e.allocate(8)
            self.call(constructor, stream, self.string(text), 8)
            self.call("_ZNSirsERl", stream, output)
            self.assertEqual(struct.unpack("<q", e.uc.mem_read(output, 8))[0], expected)
            self.assertEqual(struct.unpack("<I", e.uc.mem_read(stream + 0x98, 4))[0], state)
            self.call(destructor, stream)


if __name__ == "__main__":
    unittest.main()
