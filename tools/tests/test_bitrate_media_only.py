"""Media-only evidence cannot substitute for complete guarded SD verification."""
import sys
import unittest
from pathlib import Path
from types import SimpleNamespace

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from sony_verification import require_current_verification
from verify_bitrate_media import vcl_equal


def media(samples, width=4):
    packed = [b"".join(len(nal).to_bytes(width, "big") + nal for nal in units)
              for units in samples]
    track = SimpleNamespace(sizes=list(map(len, packed)), sample=packed.__getitem__,
                            avcc=lambda: bytes([1, 100, 0, 40, 252 | (width - 1)]))
    return SimpleNamespace(tracks=[track])


class MediaOnlyTests(unittest.TestCase):
    def test_no_media_only_report_can_admit_deployment(self):
        report = {"media_verification_schema": 1, "passed_media_checks": True,
                  "deployment_admitted": False, "catalog_staged": False, "checks": {}}
        for kind in ("encoded_avc", "bitrate_diagnostic"):
            with self.subTest(kind=kind), self.assertRaises(ValueError):
                require_current_verification(report, kind, "rec709", "observed_minimal",
                                             allow_diagnostic=True)

    def test_vcl_proof_permits_only_non_vcl_packaging_changes(self):
        a = media([[b"\x65picture", b"\x06before"], [b"\x41next"]])
        b = media([[b"\x65picture", b"\x06after"], [b"\x41next"]], width=3)
        self.assertTrue(vcl_equal(a, b))
        self.assertFalse(vcl_equal(a, media([[b"\x65changed"], [b"\x41next"]])))
        self.assertFalse(vcl_equal(a, media([[b"\x65picture"]])))
        self.assertFalse(vcl_equal(media([[b"\x06only"]]), media([[b"\x06only"]])))


if __name__ == "__main__":
    unittest.main()
