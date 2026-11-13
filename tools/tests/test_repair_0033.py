"""Keep slot relocation, catalog retention and physical playback separate."""
import hashlib
import json
from pathlib import Path
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from analyze_repair_0033 import movie_transitions

ROOT = Path(__file__).resolve().parents[2]


def movie(index, flags=0x18):
    raw = bytearray(160)
    raw[6] = flags
    return {"record_index": index, "record_hex": raw.hex(),
            "video_info_ref": 28, "umid_array_ref": 0}


class RepairTransitionTests(unittest.TestCase):
    def test_relocation_is_not_clip_removal(self):
        rows = movie_transitions({6522: movie(129)}, {6522: movie(132)})
        self.assertEqual(rows[0]["status"], "RELOCATED")
        self.assertEqual(rows[0]["record_before"], 129)
        self.assertEqual(rows[0]["record_after"], 132)
        self.assertIsNone(rows[0]["post_repair_physical_listing"])

    def test_completion_and_real_removal_are_distinct(self):
        rows = movie_transitions({10: movie(130), 20: movie(127)},
                                 {10: movie(130, 0x14)})
        self.assertEqual([row["status"] for row in rows], ["UPDATED_IN_PLACE", "REMOVED"])

    def test_shared_array_growth_does_not_modify_its_existing_movie(self):
        old, new = movie(123, 0x14), movie(123, 0x14)
        old["umid_array_hex"], new["umid_array_hex"] = "old", "grown"
        self.assertEqual(movie_transitions({6524: old}, {6524: new}), [])

    def test_actual_added_clip(self):
        self.assertEqual(movie_transitions({}, {10: movie(130)})[0]["status"], "ADDED")


class RepairEvidenceTests(unittest.TestCase):
    def test_feedback_is_bound_to_original_deployment_and_not_post_repair(self):
        report = json.loads((ROOT / "analysis/camera-observations-0032-result.json").read_text("utf-8"))
        binding = report["binding"]
        path = ROOT / binding["deployment_summary"]
        self.assertEqual(hashlib.sha256(path.read_bytes()).hexdigest(),
                         binding["deployment_summary_sha256"])
        deployed = json.loads(path.read_text("utf-8"))
        result, = report["results"]
        self.assertEqual(result["clip"], deployed["clip"])
        self.assertEqual(result["media_sha256"], deployed["media_sha256"])
        self.assertTrue(result["plays_normally"])
        self.assertEqual(result["phase"], "BEFORE_SUBSEQUENT_DATABASE_REPAIR")
        for key in ("thumbnail_normal", "full_duration_playback", "audio", "seek",
                    "post_repair_listed", "post_repair_playback"):
            self.assertIsNone(result[key], key)
        self.assertIsNone(deployed["camera"]["starts_playback"])

    def test_report_retains_all_clips_and_explicit_evidence_limits(self):
        report = json.loads((ROOT / "analysis/0033-repair-observations.json").read_text("utf-8"))
        self.assertTrue(report["passed"])
        self.assertTrue(all(report["checks"].values()))
        self.assertFalse(report["card_writes"])
        self.assertFalse(report["card_deletions"])
        self.assertEqual(report["movie_count_before_after"], [58, 58])
        self.assertEqual(report["header_movie_counts"], [58, 58])
        transitions = {row["clip"]: row for row in report["movie_transitions"]}
        self.assertEqual(transitions["C6522"]["status"], "RELOCATED")
        self.assertEqual(transitions["C6522"]["flags_before_after"], ["0x18", "0x18"])
        for clip in ("C0010", "C6520", "C6521"):
            self.assertEqual(transitions[clip]["status"], "UPDATED_IN_PLACE")
            self.assertEqual(transitions[clip]["flags_before_after"], ["0x18", "0x14"])
        for row in transitions.values():
            self.assertIsNone(row["post_repair_physical_listing"])
            self.assertIsNone(row["post_repair_physical_playback"])
        self.assertEqual(len(report["selected_media"]), 9)
        for name, expected in report["bound_reports_sha256"].items():
            self.assertEqual(hashlib.sha256((ROOT / name).read_bytes()).hexdigest(), expected)


if __name__ == "__main__":
    unittest.main()
