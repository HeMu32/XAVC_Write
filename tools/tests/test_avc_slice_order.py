"""Purpose: regress selected progressive AVC slice-order checks.

Usage: python -m unittest discover -s tools/tests -p test_avc_slice_order.py -v.
Design: synthetic parser traces test picture boundaries, coverage/order and
    refusal of missing, malformed or unsupported syntax.
Scope: checker logic only; no firmware, real card or hardware decoder execution.
"""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from check_avc_slice_order import evaluate, parse_trace


class SliceOrderTests(unittest.TestCase):
    def setUp(self):
        self.fields = {"pic_width_in_mbs_minus1": {119},
                       "pic_height_in_map_units_minus1": {67},
                       "frame_mbs_only_flag": {1}, "num_slice_groups_minus1": {0}}

    def test_progressive_candidate_pattern(self):
        result = evaluate(self.fields, [[0, 2040, 4080, 6120]], 1)
        self.assertTrue(result["passed_selected_checks"])
        self.assertEqual(result["coded_macroblocks"], 8160)

    def test_rejects_bad_start_sequence(self):
        for starts in ([], [1], [0, 0], [0, 4080, 2040], [0, 8160]):
            with self.subTest(starts=starts):
                self.assertFalse(evaluate(self.fields, [starts], 1)["passed_selected_checks"])

    def test_refuses_unsupported_syntax(self):
        for name, values in (("frame_mbs_only_flag", {0}), ("num_slice_groups_minus1", {1}),
                             ("pic_width_in_mbs_minus1", set()),
                             ("pic_height_in_map_units_minus1", {67, 33})):
            fields = {**self.fields, name: values}
            result = evaluate(fields, [[0]], 1)
            self.assertFalse(result["applicable"])
            self.assertFalse(result["passed_selected_checks"])

    def test_no_empty_or_partial_success(self):
        self.assertFalse(evaluate(self.fields, [], 0)["passed_selected_checks"])
        self.assertFalse(evaluate(self.fields, [[0]], 2)["passed_selected_checks"])

    def test_parser_preserves_packet_boundaries(self):
        fields, packets = parse_trace([
            "[trace_headers @ 1] 49 pic_width_in_mbs_minus1 0000001111000 = 119",
            "[trace_headers @ 1] 8 first_mb_in_slice 1 = 99",
            "[trace_headers @ 1] Packet: 100 bytes, pts 0.",
            "[trace_headers @ 1] 8 first_mb_in_slice 1 = 0",
            "[trace_headers @ 1] 8 first_mb_in_slice 0001 = 2040",
            "[trace_headers @ 1] Packet: 100 bytes, pts 1001.",
            "[trace_headers @ 1] 8 first_mb_in_slice 1 = 0"])
        self.assertEqual(fields["pic_width_in_mbs_minus1"], {119})
        self.assertEqual(packets, [[0, 2040], [0]])


if __name__ == "__main__":
    unittest.main()
