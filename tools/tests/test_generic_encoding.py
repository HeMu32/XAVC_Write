"""Purpose: regress generic-input timing, color and audio preparation helpers.

Usage: python -m unittest discover -s tools/tests -p test_generic_encoding.py -v.
Design: synthetic probe data and temporary media exercise exact cadence,
    alignment, silent inputs, SDR handling, unsupported HDR and sample sequences.
Scope: local preparation logic, not all-input coverage or Sony camera admission.
"""
import sys
import unittest
from fractions import Fraction
from pathlib import Path
from types import SimpleNamespace

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from build_sony_clip import align_pcm
from encode_xavc import color_policy, make_command, source_timing
from sony_mp4 import ConstantSizes, UniformOffsets
from sony_rtmd import make_packet, timecode
from verify_sony_package import hash_audio


def probe(audio=True):
    streams = [{"index": 2, "codec_type": "video", "time_base": "1/1000",
                "start_pts": 5000, "duration_ts": 1234}]
    if audio:
        streams.append({"index": 3, "codec_type": "audio"})
    return {"streams": streams}


class GenericEncodingTests(unittest.TestCase):
    def test_exact_timing(self):
        _, start, duration = source_timing(probe())
        self.assertEqual((start, duration), (Fraction(5), Fraction(617, 500)))

    def test_timing_ignores_cover_art(self):
        data = probe()
        data["streams"].insert(0, {"codec_type": "video", "disposition": {"attached_pic": 1}})
        self.assertEqual(source_timing(data)[0]["index"], 2)

    def test_timing_rejects_missing_video_or_duration(self):
        for data in [{"streams": []}, {"streams": [{"codec_type": "video"}]}]:
            with self.assertRaises(ValueError):
                source_timing(data)

    def test_preserves_audio_offset(self):
        cmd = make_command("input.mov", Path("out"), probe())
        self.assertIn("0:2", cmd)
        self.assertIn("0:3", cmd)
        self.assertIn("-copyts", cmd)
        self.assertIn("asetpts=PTS-(5/1)/TB", cmd[cmd.index("-af") + 1])
        self.assertEqual(cmd[cmd.index("-t") + 1], "1.234000000")

    def test_silent_input(self):
        cmd = make_command("input.mov", Path("out"), probe(False))
        self.assertIn("1:a:0", cmd)
        self.assertIn("anullsrc=channel_layout=stereo:sample_rate=48000", cmd)

    def test_rejects_hdr(self):
        data = probe()
        data["streams"][0]["color_transfer"] = "smpte2084"
        with self.assertRaisesRegex(ValueError, "HDR"):
            make_command("input.mov", Path("out"), data)

    def test_sd_color_is_converted_not_relabelled(self):
        transform, assumptions = color_policy({
            "pix_fmt": "yuv420p", "color_space": "smpte170m", "color_primaries": "smpte170m",
            "color_transfer": "smpte170m", "color_range": "tv"})
        self.assertIn("ispace=smpte170m", transform)
        self.assertIn("iprimaries=smpte170m", transform)
        self.assertIn("all=bt709:range=tv", transform)
        self.assertEqual(assumptions, [])

    def test_missing_color_is_recorded(self):
        _, assumptions = color_policy({})
        self.assertEqual(len(assumptions), 4)

    def test_rgb_color_path(self):
        transform, _ = color_policy({"pix_fmt": "gbrp"})
        self.assertIn("out_color_matrix=bt709,format=yuv444p", transform)
        self.assertIn("ispace=bt709", transform)
        self.assertIn("itrc=iec61966-2-1", transform)

    def test_rejects_unhandled_transfer(self):
        with self.assertRaisesRegex(ValueError, "Unsupported color_transfer"):
            color_policy({"color_transfer": "log100"})

    def test_ffprobe_gamma_aliases(self):
        for source, target in [("bt470m", "gamma22"), ("bt470bg", "gamma28")]:
            transform, _ = color_policy({"color_transfer": source})
            self.assertIn(f"itrc={target}", transform)

    def test_pcm_fit(self):
        samples = 30 * 1001 * 4 // 5
        small = b"\x01\x02\x03\x04" * (samples - 3)
        self.assertEqual(align_pcm(small, 30), small + bytes(12))
        long = b"\x01\x02\x03\x04" * (samples + 7)
        self.assertEqual(align_pcm(long, 30), long[:samples * 4])
        with self.assertRaises(ValueError):
            align_pcm(b"x", 30)

    def test_audio_hash_trim_and_pad(self):
        track = SimpleNamespace(handler="soun", chunks=[2, 10], chunk_samples=[1, 1])
        media = SimpleNamespace(tracks=[track], buf=b"xxABCDxxxxEFGH")
        import hashlib
        for samples, expected in [(1, b"ABCD"), (2, b"ABCDEFGH"), (3, b"ABCDEFGH\0\0\0\0")]:
            self.assertEqual(hash_audio(media, samples), hashlib.sha256(expected).hexdigest())

    def test_constant_sizes(self):
        sizes = ConstantSizes(4, 100000000)
        self.assertEqual(len(sizes), 100000000)
        self.assertEqual(sizes[-1], 4)
        self.assertEqual(list(sizes[2:9:2]), [4] * 4)
        self.assertEqual(list(sizes[10:4]), [])
        for i in [100000000, -100000001]:
            with self.assertRaises(IndexError):
                sizes[i]

    def test_uniform_offsets_across_chunks(self):
        offsets = UniformOffsets([100, 500, 1000], [2, 3, 1], 4)
        self.assertEqual(list(offsets), [100, 104, 500, 504, 508, 1000])
        self.assertEqual(offsets[::-2], [1000, 504, 104])
        self.assertEqual(offsets[-1], 1000)
        with self.assertRaises(IndexError):
            offsets[6]

    def test_rtmd_drop_frame_boundary(self):
        packet = bytearray(1024)
        packet[:2] = b"\x00\x1c"
        packet[20:24] = timecode(0)
        packet[24:] = bytes([37]) * 1000
        out = make_packet(packet, 3600)
        self.assertEqual(out[13:18], bytes.fromhex("0001000004"))
        self.assertEqual(out[20:24], bytes.fromhex("42000100"))
        self.assertEqual(out[24:], packet[24:])
        self.assertEqual(packet[13:18], bytes(5))
        with self.assertRaises(ValueError):
            make_packet(out, 1)


if __name__ == "__main__":
    unittest.main()
