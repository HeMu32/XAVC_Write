"""Purpose: regress AVC SEI/container timing comparison.

Usage: python -m unittest discover -s tools/tests -p test_avc_timing.py -v.
Design: synthetic traces cover cadence, buffering-period resets, counter wrap
    and explicit rejection of absent or contradictory timing fields.
Scope: supported timing model only, not CPB/DPB or physical playback validation.
"""
import copy
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from check_avc_timing import evaluate, parse_trace


class AvcTimingTests(unittest.TestCase):
    def setUp(self):
        hrd = {"cpb_cnt_minus1": 0, "bit_rate_scale": 0, "cpb_size_scale": 2,
               "bit_rate_value_minus1[0]": 390624, "cpb_size_value_minus1[0]": 390624,
               "cbr_flag[0]": 1, "initial_cpb_removal_delay_length_minus1": 18,
               "cpb_removal_delay_length_minus1": 10,
               "dpb_output_delay_length_minus1": 6, "time_offset_length": 0}
        self.sps = {"fields": {"num_units_in_tick": 2002, "time_scale": 240000,
                               "seq_parameter_set_id": 0, "frame_mbs_only_flag": 1,
                               "pic_struct_present_flag": 0},
                    "hrd": {"nal": hrd, "vcl": dict(hrd)}}
        self.packets = []
        for index in range(4):
            self.packets.append({"pts": index * 1001, "dts": (index - 1) * 1001,
                                 "duration": 1001,
                                 "picture_timings": [{"cpb_removal_delay": index * 2,
                                                     "dpb_output_delay": 2}],
                                 "buffering_periods": []})
        self.bp = {"sps_id": 0, "initial_delay": [80999, 80999],
                   "initial_offset": [9001, 9001]}
        self.packets[0]["buffering_periods"] = [copy.deepcopy(self.bp)]

    def check(self):
        return evaluate([self.sps], self.packets, 60000, 4)

    def test_exact_cadence(self):
        result = self.check()
        self.assertTrue(result["passed_selected_checks"])
        self.assertEqual(result["clock_tick"], "1001/120000")

    def test_buffering_period_resets_following_delay(self):
        self.packets[2]["buffering_periods"] = [copy.deepcopy(self.bp)]
        self.packets[3]["picture_timings"][0]["cpb_removal_delay"] = 2
        self.assertTrue(self.check()["passed_selected_checks"])

    def test_cpb_delay_wrap(self):
        packets = copy.deepcopy(self.packets[:2])
        packets[1]["dts"] = packets[0]["dts"] + 1025 * 1001
        packets[1]["pts"] = packets[1]["dts"] + 1001
        packets[1]["picture_timings"][0]["cpb_removal_delay"] = 2
        self.assertTrue(evaluate([self.sps], packets, 60000, 2)["passed_selected_checks"])

    def test_rejects_wrong_cpb_or_dpb(self):
        for name in ("cpb_removal_delay", "dpb_output_delay"):
            with self.subTest(name=name):
                packets = copy.deepcopy(self.packets)
                packets[1]["picture_timings"][0][name] += 1
                self.assertFalse(evaluate([self.sps], packets, 60000, 4)["passed_selected_checks"])

    def test_rejects_empty_or_missing_timing(self):
        self.assertFalse(evaluate([self.sps], [], 60000, 0)["passed_selected_checks"])
        self.packets[2]["picture_timings"] = []
        self.assertFalse(self.check()["passed_selected_checks"])

    def test_rejects_unpaired_buffering_period(self):
        self.packets[0]["buffering_periods"][0]["initial_delay"] = [80999]
        self.assertFalse(self.check()["passed_selected_checks"])

    def test_refuses_unsupported_syntax_or_widths(self):
        self.sps["hrd"]["vcl"]["cpb_removal_delay_length_minus1"] = 9
        self.assertFalse(self.check()["applicable"])
        self.sps["hrd"]["vcl"]["cpb_removal_delay_length_minus1"] = 10
        self.sps["fields"]["frame_mbs_only_flag"] = 0
        self.assertFalse(self.check()["applicable"])

    def test_parser_keeps_both_hrd_delay_pairs(self):
        lines = ["[trace_headers @ 1] Sequence Parameter Set",
                 "[trace_headers @ 1] 10 seq_parameter_set_id 1 = 0",
                 "[trace_headers @ 1] 20 nal_hrd_parameters_present_flag 1 = 1",
                 "[trace_headers @ 1] 21 cpb_cnt_minus1 1 = 0",
                 "[trace_headers @ 1] 30 vcl_hrd_parameters_present_flag 1 = 1",
                 "[trace_headers @ 1] 31 cpb_cnt_minus1 1 = 0",
                 "[trace_headers @ 1] Packet: 100 bytes, key frame, pts 0, dts -1001, duration 1001.",
                 "[trace_headers @ 1] Buffering Period",
                 "[trace_headers @ 1] 10 seq_parameter_set_id 1 = 0",
                 "[trace_headers @ 1] 20 initial_cpb_removal_delay[0] 1 = 80999",
                 "[trace_headers @ 1] 30 initial_cpb_removal_delay_offset[0] 1 = 9001",
                 "[trace_headers @ 1] 40 initial_cpb_removal_delay[0] 1 = 80999",
                 "[trace_headers @ 1] 50 initial_cpb_removal_delay_offset[0] 1 = 9001",
                 "[trace_headers @ 1] Picture Timing",
                 "[trace_headers @ 1] 10 cpb_removal_delay 1 = 0",
                 "[trace_headers @ 1] 20 dpb_output_delay 1 = 2"]
        sps, packets, errors = parse_trace(lines)
        self.assertFalse(errors)
        self.assertEqual(set(sps[0]["hrd"]), {"nal", "vcl"})
        self.assertEqual(packets[0]["buffering_periods"][0], self.bp)
        self.assertEqual(packets[0]["picture_timings"][0]["dpb_output_delay"], 2)


if __name__ == "__main__":
    unittest.main()
