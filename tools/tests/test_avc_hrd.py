"""Purpose: regress CPB accounting and buffering-period retiming helpers.

Usage: python -m unittest discover -s tools/tests -p test_avc_hrd.py -v.
Design: synthetic NAL/SEI schedules exercise rounding, bit counts, bounds,
    independent retiming and rejection of unsupported/truncated inputs.
Scope: unit-level supported CBR model, not full AVC or camera conformance.
"""
import sys
import unittest
from fractions import Fraction
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from avc_hrd import CbrRetimer, encode_sei, nal_bits, nals, sei_messages, retime_cbr_samples
from avc_sony import Bits, packbits
from check_avc_cpb import check_schedule


def packetize(units):
    return b"".join(len(nal).to_bytes(3, "big") + nal for nal in units)


class AvcHrdTests(unittest.TestCase):
    def test_counts_vcl_and_filler_but_not_aud_or_sei(self):
        units = [b"\x61abc", b"\x0cde", b"\x09f", b"\x06g"]
        self.assertEqual(nal_bits(units, "vcl"), 56)
        self.assertEqual(nal_bits(units, "nal"), 88)

    def test_nal_span_validation(self):
        for sample in (b"\x00", b"\x00\x00\x00", b"\x00\x00\x02\x61",
                       b"\x00\x00\x01\x80"):
            with self.subTest(sample=sample), self.assertRaises(ValueError):
                nals(sample, 3)

    def test_sei_roundtrip_preserves_payloads_and_escapes(self):
        messages = [(0, b"\x00\x00\x01\x02\x00"), (300, b"x" * 260)]
        self.assertEqual(sei_messages(encode_sei(6, messages)), messages)

    def test_truncated_sei_is_refused(self):
        for nal in (b"\x06", b"\x06\x00\x10\x80", b"\x06\xff"):
            with self.subTest(nal=nal), self.assertRaises(ValueError):
                sei_messages(nal)

    def test_buffer_overflow_and_underflow_are_not_hidden(self):
        packets = [{"dts": 0, "buffering_periods": [{"initial_delay": [45000]}]},
                   {"dts": 1000, "buffering_periods": []}]
        self.assertIn("cpb_underflow", check_schedule([8, 8], packets, 8, 100, 1000, 0)["failure_counts"])
        self.assertIn("cpb_overflow", check_schedule([8, 8], packets, 100, 4, 1000, 0)["failure_counts"])

    def test_C16_rounding_is_not_replaced_by_buffer_bounds(self):
        packets = [{"dts": 0, "buffering_periods": [{"initial_delay": [90000]}]},
                   {"dts": 1000, "buffering_periods": [{"initial_delay": [90002]}]}]
        result = check_schedule([8, 8], packets, 8, 16, 1000, 0)
        self.assertEqual(result["failure_counts"], {"C16_initial_delay_rounding": 1})

    def test_retimer_recomputes_independent_groups_from_actual_escaped_bytes(self):
        hrd = {"count": 1, "initial": 24, "rates": [8000], "sizes": [80000], "cbr": [1]}
        vm = CbrRetimer({0: {"hrd": hrd}}, Fraction(1))
        bp_bits = "1" + "".join(f"{80999:024b}{819001:024b}" for _ in range(2))
        bp_bits += "1"
        original_sei = encode_sei(6, [(0, packbits(bp_bits))])
        vcl = b"\x61" + b"x" * 699
        sample = packetize([b"\x09\x10", original_sei, vcl])
        outputs = [vm.rewrite(sample, i) for i in range(3)]
        packets, sizes = [], {"nal": [], "vcl": []}
        for i, output in enumerate(outputs):
            units = nals(output, 3)
            self.assertEqual(units[-1], vcl)
            typ, payload = sei_messages(units[1])[0]
            self.assertEqual(typ, 0)
            reader = Bits(payload)
            self.assertEqual(reader.ue(), 0)
            pairs = [(reader.u(24), reader.u(24)) for _ in range(2)]
            packets.append({"dts": i * 1000,
                            "buffering_periods": [{"initial_delay": [p[0] for p in pairs]}]})
            for group in sizes:
                sizes[group].append(nal_bits(units, group))
        for position, group in enumerate(sizes):
            result = check_schedule(sizes[group], packets, 8000, 80000, 1000, position)
            self.assertTrue(result["passed_selected_cpb_checks"], result)
        self.assertNotEqual(vm.periods[1]["new"][0], vm.periods[1]["new"][1])

    def test_retimer_refuses_unsupported_and_out_of_order_input(self):
        with self.assertRaises(ValueError):
            CbrRetimer({}, Fraction(1, 60))
        vm = CbrRetimer({0: {"hrd": {"count": 1, "initial": 19, "rates": [25000000],
                                    "sizes": [25000000], "cbr": [1]}}}, Fraction(1001, 60000))
        with self.assertRaisesRegex(ValueError, "decode order"):
            vm.rewrite(packetize([b"\x61x"]), 1)
        with self.assertRaisesRegex(ValueError, "buffering period"):
            vm.rewrite(packetize([b"\x61x"]), 0)

    def test_preflight_selects_feasible_initial_delay(self):
        hrd = {"count": 1, "initial": 24, "rates": [8000], "sizes": [80000], "cbr": [1]}
        bits = "1" + "".join(f"{9000000:024b}{0:024b}" for _ in range(2)) + "1"
        sample = packetize([encode_sei(6, [(0, packbits(bits))]), b"\x61" + b"x" * 699])
        outputs, vm = retime_cbr_samples([sample] * 3, {0: {"hrd": hrd}}, Fraction(1))
        self.assertEqual(len(outputs), 3)
        for chosen in vm.initial:
            self.assertLess(chosen, 9000000)
            self.assertLessEqual(chosen, 900000)

    def test_preflight_refuses_infeasible_fixed_capacity(self):
        hrd = {"count": 1, "initial": 24, "rates": [8000], "sizes": [1], "cbr": [1]}
        bits = "1" + "".join(f"{80999:024b}{0:024b}" for _ in range(2)) + "1"
        sample = packetize([encode_sei(6, [(0, packbits(bits))]), b"\x61" + b"x" * 699])
        with self.assertRaisesRegex(ValueError, "No guarded"):
            retime_cbr_samples([sample] * 3, {0: {"hrd": hrd}}, Fraction(1))


if __name__ == "__main__":
    unittest.main()
