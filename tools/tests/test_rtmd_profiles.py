"""Purpose: regress supported RTMD profile cadence and timestamp boundaries.

Usage: python -m unittest discover -s tools/tests -p test_rtmd_profiles.py -v.
Design: measured seed fixtures and synthetic frame indexes cover half-step,
    nonzero origins, drop-frame/day boundaries and opaque-byte preservation.
Scope: identified template fields only, not all RTMD semantics or camera tests.
"""
import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from sony_rtmd import make_packet, timecode
from verify_rtmd_reference import PROFILE_HALF_STEP


DAY_FRAMES_2997 = 2589408


def template_at(hh=0, mm=0, ss=0, ff=0):
    packet = bytearray((i * 37 + 11) % 256 for i in range(1024))
    packet[:2] = b"\x00\x1c"
    packet[13:18] = bytes([hh, mm, ss]) + struct.pack(">H", ff)
    bcd = lambda value: (value // 10) * 16 + value % 10
    packet[20:24] = bytes([bcd(ff) | 0x40, bcd(ss), bcd(mm), bcd(hh)])
    return packet


def legacy_timecode(frame):
    f = frame // 2
    ten, rem = divmod(f, 17982)
    f += 18 * ten + (2 * ((rem - 2) // 1798) if rem >= 2 else 0)
    f %= 30 * 60 * 60 * 24
    sec, ff = divmod(f, 30)
    minute, ss = divmod(sec, 60)
    hh, mm = divmod(minute, 60)
    bcd = lambda value: value // 10 * 16 + value % 10
    return bytes([bcd(ff) | 0x40, bcd(ss) | ((frame & 1) << 7), bcd(mm), bcd(hh)])


class RTMDProfileTests(unittest.TestCase):
    def test_profile_cadences(self):
        self.assertEqual(PROFILE_HALF_STEP,
                         {"hd25_5994": True, "hd50_5994": True, "uhd60_2997": False})

    def test_2997_first_frames(self):
        for frame, expected in [(0, "40000000"), (1, "41000000"), (2, "42000000"),
                                (29, "69000000"), (30, "40010000")]:
            with self.subTest(frame=frame):
                self.assertEqual(timecode(frame, half_step=False), bytes.fromhex(expected))

    def test_legacy_5994_unchanged(self):
        template = template_at()
        for frame in list(range(14170)) + [35963, 35964, 5178815, 5178816, 5178817]:
            expected = legacy_timecode(frame)
            self.assertEqual(timecode(frame), expected)
            self.assertEqual(timecode(frame, half_step=True), expected)
            packet = bytearray(template)
            decimal = lambda value: (value >> 4) * 10 + (value & 15)
            packet[13:16] = bytes([decimal(expected[3]), decimal(expected[2]),
                                   decimal(expected[1] & 127)])
            struct.pack_into(">H", packet, 16,
                             decimal(expected[0] & 63) * 2 + (expected[1] >> 7))
            packet[20:24] = expected
            self.assertEqual(make_packet(template, frame), packet)
            self.assertEqual(make_packet(template, frame, half_step=True), packet)

    def test_drop_frame_minute_ten_minute_and_day(self):
        cases = [(1799, "69590000", "00003b001d"),
                 (1800, "42000100", "0001000002"),
                 (3597, "69590100", "00013b001d"),
                 (3598, "42000200", "0002000002"),
                 (17981, "69590900", "00093b001d"),
                 (17982, "40001000", "000a000000"),
                 (DAY_FRAMES_2997 - 1, "69595923", "173b3b001d"),
                 (DAY_FRAMES_2997, "40000000", "0000000000"),
                 (2 * DAY_FRAMES_2997, "40000000", "0000000000")]
        for half_step in [False, True]:
            for frame, expected_tc, expected_header in cases:
                for parity in range(2 if half_step else 1):
                    sample = frame * (2 if half_step else 1) + parity
                    with self.subTest(half_step=half_step, sample=sample):
                        tc = bytearray.fromhex(expected_tc)
                        header = bytearray.fromhex(expected_header)
                        if half_step:
                            tc[1] |= parity << 7
                            header[4] = header[4] * 2 + parity
                        self.assertEqual(timecode(sample, half_step=half_step), tc)
                        packet = make_packet(template_at(), sample, half_step=half_step)
                        self.assertEqual(packet[20:24], tc)
                        self.assertEqual(packet[13:18], header)

    def test_nonzero_2997_reference_start(self):
        template = template_at(0, 1, 14, 11)
        # First 32 bytes were read directly from C0001-reference-0026.MP4.
        template[:32] = bytes.fromhex(
            "001c010000500394f00100100100010e000b001e5114010000000000060e2b34")
        cases = [(0, "51140100", "00010e000b"),
                 (1, "52140100", "00010e000c"),
                 (28, "49150100", "00010f0009"),
                 (89, "50170100", "000111000a")]
        for frame, tc, header in cases:
            packet = make_packet(template, frame, half_step=False)
            self.assertEqual(packet[20:24].hex(), tc)
            self.assertEqual(packet[13:18].hex(), header)

    def test_nonzero_2997_template_across_boundaries(self):
        for template, frame, expected in [
                (template_at(0, 0, 59, 29), 1, "42000100"),
                (template_at(0, 9, 59, 29), 1, "40001000"),
                (template_at(23, 59, 59, 29), 1, "40000000"),
                (template_at(0, 1, 0, 2), 0, "42000100"),
                (template_at(0, 10, 0, 0), 0, "40001000")]:
            self.assertEqual(make_packet(template, frame, half_step=False)[20:24].hex(),
                             expected)

    def test_opaque_bytes_preserved_and_template_not_mutated(self):
        rewritten = set(range(13, 18)) | set(range(20, 24))
        for half_step in [True, False]:
            template = template_at() if half_step else template_at(0, 1, 14, 11)
            original = bytes(template)
            for frame in [0, 1, 1800, 17982, DAY_FRAMES_2997]:
                packet = make_packet(template, frame, half_step=half_step)
                self.assertEqual(len(packet), 1024)
                self.assertIsInstance(packet, bytes)
                self.assertEqual(template, original)
                self.assertTrue(all(packet[i] == original[i]
                                    for i in range(1024) if i not in rewritten))

    def test_reject_invalid_frame(self):
        for half_step in [True, False]:
            for frame in [-1, -100, 0.0, 1.5, float("inf"), float("nan"),
                          "1", None, True, False]:
                with self.subTest(half_step=half_step, frame=frame):
                    with self.assertRaises(ValueError):
                        timecode(frame, half_step=half_step)
                    with self.assertRaises(ValueError):
                        make_packet(template_at(), frame, half_step=half_step)

    def test_reject_invalid_templates(self):
        template = template_at()
        for half_step in [True, False]:
            for invalid in [bytes(1024), template[:-1], template + b"x"]:
                with self.assertRaises(ValueError):
                    make_packet(invalid, 0, half_step=half_step)
        with self.assertRaisesRegex(ValueError, "zero timecode"):
            make_packet(template_at(0, 0, 1, 0), 0)
        for tc in ["c0000000", "40800000", "4a000000", "70000000",
                   "40600000", "40006000", "40000024"]:
            invalid = template_at()
            invalid[20:24] = bytes.fromhex(tc)
            with self.subTest(tc=tc):
                with self.assertRaises(ValueError):
                    make_packet(invalid, 0, half_step=False)
        for ff in [0, 1]:
            with self.assertRaisesRegex(ValueError, "Dropped"):
                make_packet(template_at(0, 1, 0, ff), 0, half_step=False)
        invalid = template_at()
        invalid[17] = 1
        with self.assertRaisesRegex(ValueError, "disagree"):
            make_packet(invalid, 0, half_step=False)


if __name__ == "__main__":
    unittest.main()
