"""Purpose: join repair-time media hashes to prior whole-file hash evidence.

Usage: python tools/join_repair_media.py --output NEW_LOCAL_REPORT.json
    [--root WORKSPACE --hash-local-references --snapshot-attempt STATUS].
Design: validate inventory bindings, inspect deployed packages and explicit
    historical reports, then report exact matches, coverage and version lineage.
Scope: saved experiment 0027 artifacts; optional rehashes read local references
    only. No card access or post-repair playback claim; copied reports are not
    statistically independent observations.
"""
import argparse
import csv
import hashlib
import json
import ntpath
import re
from datetime import datetime, timezone
from pathlib import Path, PurePosixPath


PRIORITY = ("C6507", "C6509", "C6511", "C6512", "C6513", "C6514",
            "C6515", "C6517", "C6518", "C0007", "C6359")
REFERENCES = {
    "C0001": "analysis/C0001-reference-0026.MP4",
    "C0007": "analysis/C0007-reference-0023.MP4",
    "C6359": "analysis/C6359-reference-0023.MP4",
}
ROUND_FILES = (
    "analysis/C6507-C6508-card-audit.json",
    "analysis/C6509-C6510-card-audit.json",
    "analysis/sd-test-round-0025.json",
    "analysis/sd-test-round-0026.json",
    "analysis/camera-test-round-0025.json",
    "analysis/camera-test-round-0026.json",
    "analysis/camera-observations-0025-result.json",
    "analysis/camera-observations-0026-result.json",
    "analysis/historical-playback-C0007-0025.json",
)


def sha256(path):
    with path.open("rb") as stream:
        return hashlib.file_digest(stream, "sha256").hexdigest()


def pointer(*parts):
    return "/" + "/".join(str(part).replace("~", "~0").replace("/", "~1")
                          for part in parts)


def media_path(value):
    """Map only explicit card paths, clip filenames, and named full references."""
    if not isinstance(value, str):
        return None
    value = value.replace("\\", "/")
    if "/PRIVATE/" in value:
        value = "PRIVATE/" + value.split("/PRIVATE/", 1)[1]
    if value.startswith(("PRIVATE/", "DCIM/")):
        return value
    name = PurePosixPath(value).name
    match = re.fullmatch(r"(C\d{4})-reference-\d{4}\.MP4", name, re.I)
    if match:
        name = match[1].upper() + ".MP4"
    if re.fullmatch(r"C\d{4}\.MP4", name, re.I):
        return "PRIVATE/M4ROOT/CLIP/" + name.upper()
    if re.fullmatch(r"C\d{4}T\d{2}\.JPG", name, re.I):
        return "PRIVATE/M4ROOT/THMBNL/" + name.upper()
    return None


def local_path(root, value):
    path = Path(value)
    path = (path if path.is_absolute() else root / path).resolve()
    if not path.is_relative_to(root):
        raise ValueError("Evidence must be local to the workspace: " + str(path))
    return path


class Evidence:
    def __init__(self, root, post):
        self.root = root
        self.post = post
        self.sources = {}
        self.hashes = {name: [] for name in post}
        self.ignored_noninventory_hashes = 0

    def load(self, value, kind):
        path = local_path(self.root, value)
        relative = path.relative_to(self.root).as_posix()
        raw = path.read_bytes()
        data = json.loads(raw)
        self.sources.setdefault(relative, {
            "kind": kind, "sha256": hashlib.sha256(raw).hexdigest(),
            "size": len(raw), "last_write_time_ns": path.stat().st_mtime_ns,
            "independent_of_post_hash_report": kind != "post_repair_hash_report",
        })
        return relative, data

    def add(self, source, location, name, digest, basis):
        name = media_path(name)
        if name is None:
            return
        if not isinstance(digest, str) or not re.fullmatch(r"[0-9a-fA-F]{64}", digest):
            raise ValueError(f"Invalid SHA256 at {source}#{location}")
        if name not in self.hashes:
            self.ignored_noninventory_hashes += 1
            return
        row = {"source": source, "json_pointer": location, "sha256": digest.lower(),
               "basis": basis, "matches_post_repair": digest.lower() == self.post[name]["sha256"]}
        if row not in self.hashes[name]:
            self.hashes[name].append(row)


def read_manifest(evidence, snapshot, kind):
    folder = local_path(evidence.root, snapshot)
    relative, summary = evidence.load(folder / "_snapshot.json", kind)
    manifest = folder / "_skipped_media_manifest.csv"
    raw = manifest.read_bytes()
    key = manifest.relative_to(evidence.root).as_posix()
    evidence.sources[key] = {
        "kind": kind, "sha256": hashlib.sha256(raw).hexdigest(),
        "size": len(raw), "last_write_time_ns": manifest.stat().st_mtime_ns,
        "independent_of_post_hash_report": True,
    }
    with manifest.open(encoding="utf-8-sig", newline="") as stream:
        rows = list(csv.DictReader(stream))
    result = {row["relative_path"]: row for row in rows}
    if len(rows) != len(result) or len(rows) != summary["skipped_media"] or summary["errors"]:
        raise ValueError("Invalid snapshot inventory: " + relative)
    return result, key


def collect_packages(evidence):
    lineages = []
    # Restrict package evidence to directories with a saved deployment record.
    # Other builds can reuse a clip number without ever having reached the card.
    for deployment in sorted((evidence.root / "output").rglob("deployment.json")):
        source, data = evidence.load(deployment, "deployment_readback")
        if data.get("status") != "deployed":
            continue
        if data.get("previous_deployment"):
            lineages.append({
                "source": source, "json_pointer": "/previous_deployment",
                "previous_deployment": data["previous_deployment"],
                "snapshot": data.get("snapshot"), "clip": data.get("clip"),
                "media_updates": [row for row in data.get("updated", [])
                                  if media_path(row.get("path")) in evidence.post],
                "interpretation": "Explicit historical revision linkage, not a repair-time change.",
            })
        for group in ("added", "updated"):
            for index, row in enumerate(data.get(group, [])):
                evidence.add(source, pointer(group, index, "sha256"), row.get("path"),
                             row.get("sha256"), "saved_deployment_readback")
        for filename, kind in (("build-manifest.json", "package_build"),
                               ("verification.json", "package_verification")):
            source, data = evidence.load(deployment.parent / filename, kind)
            if filename == "build-manifest.json":
                evidence.add(source, "/sha256", data["clip"] + ".MP4", data["sha256"],
                             "build_manifest_whole_file")
                for field, path_field in (("native_source_sha256", "base"),
                                          ("source_sha256", "base"),
                                          ("source_thumbnail_sha256", "source_thumbnail"),
                                          ("structure_template_sha256", "structure_template")):
                    if field in data:
                        evidence.add(source, pointer(field), data.get(path_field), data[field],
                                     "build_input_whole_file")
            else:
                for name, digest in data.get("package_hashes", {}).items():
                    evidence.add(source, pointer("package_hashes", name), name, digest,
                                 "verification_package_whole_file")
                fresh = data.get("fresh_media_evidence", {})
                if "media_sha256" in fresh:
                    clip = json.loads((deployment.parent / "build-manifest.json").read_text(
                        encoding="utf-8"))["clip"]
                    evidence.add(source, "/fresh_media_evidence/media_sha256", clip + ".MP4",
                                 fresh["media_sha256"], "fresh_verification_whole_file")
    return lineages


def collect_rounds(evidence):
    for filename in ROUND_FILES:
        source, data = evidence.load(filename, "historical_round")
        for group in ("clips", "packages", "results", "historical_playback_positive"):
            for index, row in enumerate(data.get(group, [])):
                for field in ("media_sha256", "source_sha256"):
                    if field in row:
                        evidence.add(source, pointer(group, index, field), row["clip"] + ".MP4",
                                     row[field], "historical_round_whole_file")
        for clip, digest in data.get("existing_control_hashes_checked_before_deployment", {}).items():
            evidence.add(source, pointer("existing_control_hashes_checked_before_deployment", clip),
                         clip + ".MP4", digest, "historical_card_control_rehash")
        digest = data.get("preservation", {}).get("card_C0007_final_sha256")
        if digest:
            evidence.add(source, "/preservation/card_C0007_final_sha256", "C0007.MP4",
                         digest, "historical_card_control_rehash")
    for clip in REFERENCES:
        filename = f"analysis/xavc-reader-{clip}-0023.json"
        if (evidence.root / filename).exists():
            source, data = evidence.load(filename, "historical_reference")
            evidence.add(source, "/media_sha256", data["media"], data["media_sha256"],
                         "historical_full_reference_hash_not_firmware_or_track_hash")
    for profile in ("hd25_5994", "hd50_5994", "uhd60_2997"):
        source, data = evidence.load(f"analysis/rtmd-reference-0026-{profile}.json",
                                     "historical_reference")
        # reference_sha256 in these files is ONLY the RTMD payload, not the MP4.
        evidence.add(source, "/reference_file_sha256", data["reference"],
                     data["reference_file_sha256"], "historical_full_reference_hash")


def coverage(entries):
    covered = [row for row in entries if row["historical_sha256_match"]]
    total_bytes = sum(row["size"] for row in entries)
    matched_bytes = sum(row["size"] for row in covered)
    return {
        "total": len(entries), "matched": len(covered), "uncovered": len(entries) - len(covered),
        "percent_files": round(100 * len(covered) / len(entries), 4) if entries else 0,
        "total_bytes": total_bytes, "matched_bytes": matched_bytes,
        "percent_bytes": round(100 * matched_bytes / total_bytes, 4) if total_bytes else 0,
    }


def join(root, hash_local_references=False, snapshot_attempt="not_attempted"):
    root = Path(root).resolve()
    post_file = root / "analysis/repair-media-hashes-0027.json"
    post = json.loads(post_file.read_text(encoding="utf-8"))
    rows = post["entries"]
    indexed = {row["relative_path"]: row for row in rows}
    normalized_paths = {ntpath.normcase(ntpath.normpath(row["relative_path"])) for row in rows}
    if (post.get("algorithm") != "sha256" or post.get("passed") is not True or post["errors"]
            or len(indexed) != len(rows) or len(rows) != post["media_count"]
            or len(normalized_paths) != len(rows)
            or len(rows) != post["expected_media_count"]
            or sum(row["size"] for row in rows) != post["bytes_hashed"]):
        raise ValueError("Invalid or incomplete post-repair hash report")
    for row in rows:
        if not re.fullmatch(r"[0-9a-f]{64}", row["sha256"]):
            raise ValueError("Invalid post-repair digest")
    evidence = Evidence(root, indexed)
    tool_source = root / "tools/hash_snapshot_media.py"
    hash_tool_sha256 = sha256(tool_source)
    post_source, _ = evidence.load(post_file, "post_repair_hash_report")
    ledger_source, ledger = evidence.load("analysis/camera-database-repair-0027.json",
                                          "pre_repair_ledger")
    before, before_manifest = read_manifest(evidence, ledger["before_snapshot"], "pre_repair_inventory")
    after, after_manifest = read_manifest(evidence, post["snapshot"], "post_repair_inventory")
    if evidence.sources[after_manifest]["sha256"] != post["snapshot_media_manifest_sha256"]:
        raise ValueError("Post-repair snapshot manifest digest differs from hash report")
    if set(after) != set(indexed):
        raise ValueError("Post-repair hash paths differ from saved snapshot")
    for name, row in indexed.items():
        if (row["size"], row["last_write_time_ns"]) != (
                int(after[name]["size"]), int(after[name]["last_write_time_ns"])):
            raise ValueError("Post-repair hash stat binding differs: " + name)
    for name, digest in ledger["before_live_card_sha256"].items():
        evidence.add(ledger_source, pointer("before_live_card_sha256", name), name, digest,
                     "direct_pre_repair_live_card_hash")
    lineages = collect_packages(evidence)
    collect_rounds(evidence)
    pair_reports = []
    for a, b in (("C6512", "C6515"), ("C6513", "C6514")):
        source, data = evidence.load(f"analysis/reframe-{a}-{b}-0025.json", "historical_pair_comparison")
        for prefix in ("before", "after"):
            evidence.add(source, pointer(prefix + "_sha256"), data[prefix], data[prefix + "_sha256"],
                         "historical_full_file_pair_comparison")
        pair_reports.append((a, b, source, data))
    local_checks = []
    if hash_local_references:
        for clip, filename in REFERENCES.items():
            path = local_path(root, filename)
            stat = path.stat()
            digest = sha256(path)
            stat_after = path.stat()
            matches = [r for r in evidence.hashes[media_path(clip + ".MP4")]
                       if r["sha256"] == digest]
            local_checks.append({
                "clip": clip, "path": filename, "sha256": digest, "size": stat.st_size,
                "last_write_time_ns": stat.st_mtime_ns,
                "stable_during_hash": (stat.st_size, stat.st_mtime_ns) == (
                    stat_after.st_size, stat_after.st_mtime_ns),
                "matches_post_repair": digest == indexed[media_path(clip + ".MP4")]["sha256"],
                "matches_prior_independent_record": bool(matches),
                "scope": "Current LOCAL reference rehash; not a new pre-repair card observation",
            })
    entries = []
    for index, row in enumerate(rows):
        name = row["relative_path"]
        prior = before.get(name)
        same_stat = prior is not None and (
            int(prior["size"]), int(prior["last_write_time_ns"])) == (
                row["size"], row["last_write_time_ns"])
        hashes = evidence.hashes[name]
        matches = [r for r in hashes if r["matches_post_repair"]]
        direct = [r for r in hashes if r["basis"] == "direct_pre_repair_live_card_hash"]
        entries.append({
            **row, "post_hash_source": {"source": post_source,
                                       "json_pointer": pointer("entries", index, "sha256")},
            "pre_repair_size_mtime_match": same_stat,
            "pre_repair_inventory_source": before_manifest if prior is not None else None,
            "historical_sha256_match": bool(matches),
            "direct_pre_repair_hash_match": all(r["matches_post_repair"] for r in direct) if direct else None,
            "status": ("DIRECT_PRE_REPAIR_SHA256_DIFFERENT" if direct and any(
                not r["matches_post_repair"] for r in direct) else
                "DIRECT_PRE_REPAIR_SHA256_EQUAL" if direct and all(
                r["matches_post_repair"] for r in direct) else
                "HISTORICAL_CONTENT_SHA256_EQUAL" if matches else "NO_PRIOR_CONTENT_HASH_MATCH"),
            "matched_source_artifact_count": len({r["source"] for r in matches}),
            "historical_hash_evidence": hashes,
            "differing_historical_hashes_are_not_alone_repair_changes": True,
        })
    by_name = {row["relative_path"]: row for row in entries}
    pairs = []
    _, round25 = evidence.load("analysis/camera-test-round-0025.json", "historical_round")
    round_clips = {row["clip"]: row for row in round25["clips"]}
    for a, b, source, data in pair_reports:
        pair_bound = all(data[prefix + "_sha256"] == indexed[media_path(clip + ".MP4")]["sha256"]
                         for prefix, clip in (("before", a), ("after", b)))
        pairs.append({
            "clips": [a, b], "historical_nal_length_bytes": [round_clips[c]["nal_length_bytes"] for c in (a, b)],
            "historical_pre_repair_playback": [round_clips[c]["playback"] for c in (a, b)],
            "historical_playback_source": "analysis/camera-observations-0025-result.json",
            "historical_pair_comparison_source": source,
            "comparison_passed": data["passed"],
            "comparison_checks": data["checks"],
            "both_post_hashes_equal_pair_inputs": pair_bound,
            "whole_media_bytes_preserved_relative_to_historical_pair": pair_bound and data["passed"],
            "post_repair_playback": "NOT_ESTABLISHED_BY_THIS_HASH_JOIN",
        })
    native_source, native_observations = evidence.load(
        "analysis/camera_observations_20261112_233331.json", "historical_camera_observation")
    observation26_source, observation26 = evidence.load(
        "analysis/camera-observations-0026-result.json", "historical_round")
    observations26 = {row["clip"]: row for row in observation26["results"]}
    priority = []
    for clip in PRIORITY:
        item = by_name[media_path(clip + ".MP4")]
        playback = round_clips.get(clip, {}).get("playback")
        playback_source = "analysis/camera-observations-0025-result.json"
        if clip in ("C6507", "C6509"):
            playback = ("REJECTED_USER_REPORTED" if clip in native_observations[
                "current_playback_rejections"] else "UNKNOWN")
            playback_source = native_source
        elif clip in ("C6517", "C6518"):
            playback = observations26[clip]["playback"]
            playback_source = observation26_source
        elif clip == "C0007":
            playback = "USER_RECONFIRMED_CONTINUOUSLY_NORMAL_NOT_A_SEPARATE_FRESH_RETEST"
        elif clip == "C6359":
            playback = "NOT_ESTABLISHED"
            playback_source = None
        priority.append({
            "clip": clip, "sha256": item["sha256"], "status": item["status"],
            "matched_source_artifact_count": item["matched_source_artifact_count"],
            "pre_repair_size_mtime_match": item["pre_repair_size_mtime_match"],
            "historical_pre_repair_playback": playback,
            "historical_playback_source": playback_source,
            "post_repair_playback": "NOT_ESTABLISHED_BY_THIS_HASH_JOIN",
        })
    baseline_mismatches = [row["relative_path"] for row in entries
                           if row["direct_pre_repair_hash_match"] is False]
    report = {
        "schema": 1, "generated_utc": datetime.now(timezone.utc).isoformat(),
        "scope": "Whole-file media preservation cross-check, not post-repair camera acceptance",
        "card_access_by_join_tool": False, "card_writes": False, "card_media_rehashed": False,
        "snapshot_attempt_before_analysis": snapshot_attempt,
        "snapshot_fallback": post["snapshot"],
        "post_hash_completed_utc": post["completed_utc"],
        "post_report_valid_and_snapshot_manifest_bound": True,
        "post_report_normalized_paths_unique": len(normalized_paths) == len(rows),
        "pre_repair_ledger_state_preserved_as_recorded": ledger["state"],
        "coverage": coverage(entries),
        "priority_coverage": coverage([by_name[media_path(clip + ".MP4")] for clip in PRIORITY]),
        "coverage_by_extension": {suffix: coverage([r for r in entries
                                  if PurePosixPath(r["relative_path"]).suffix == suffix])
                                  for suffix in sorted({PurePosixPath(r["relative_path"]).suffix for r in entries})},
        "coverage_by_evidence_kind": {
            kind: coverage([dict(r, historical_sha256_match=any(
                h["matches_post_repair"] and evidence.sources[h["source"]]["kind"] == kind
                for h in r["historical_hash_evidence"])) for r in entries])
            for kind in sorted({s["kind"] for s in evidence.sources.values()
                                if s["kind"] in ("pre_repair_ledger", "deployment_readback",
                                                 "package_build", "package_verification",
                                                 "historical_round", "historical_reference",
                                                 "historical_pair_comparison")})},
        "direct_pre_repair_media_hashes": sum(r["direct_pre_repair_hash_match"] is not None for r in entries),
        "direct_pre_repair_hash_mismatches": baseline_mismatches,
        "inventory": {
            "before_count": len(before), "after_count": len(after),
            "added_paths": sorted(set(after) - set(before)),
            "removed_paths": sorted(set(before) - set(after)),
            "size_mtime_matches": sum(r["pre_repair_size_mtime_match"] for r in entries),
            "warning": "Size/mtime equality is not proof of byte equality.",
        },
        "priority": priority, "three_vs_four_byte_pairs": pairs,
        "local_reference_rehashes": local_checks,
        "source_artifacts": evidence.sources,
        "source_independence": [
            "All historical digest assertions above come from files other than the post-repair report.",
            "Repeated fields in one artifact and copied build/verification/round records are NOT independent experiments.",
            "matched_source_artifact_count counts distinct files, not statistically independent observations.",
            "Only the ledger's direct hashes give immediate pre/post card content equality; other matches bind older known bytes.",
            "Only exact path/clip identities and whole-file SHA256 fields are joined; firmware, payload, RTMD and decoded-frame hashes are excluded.",
        ],
        "historical_version_differences": [
            {"relative_path": r["relative_path"],
             "post_sha256": r["sha256"],
             "different_evidence": [h for h in r["historical_hash_evidence"] if not h["matches_post_repair"]],
             "interpretation": "Older or alternate package bytes, not alone evidence of repair mutation; inspect each deployment lineage."}
            for r in entries if any(not h["matches_post_repair"] for h in r["historical_hash_evidence"])],
        "explicit_historical_deployment_revision_lineages": lineages,
        "ignored_explicit_media_hashes_not_in_post_inventory": evidence.ignored_noninventory_hashes,
        "hash_tool_findings": [{
            "id": "normalized_inventory_aliases_are_not_deduplicated",
            "severity": "P2",
            "tool": "tools/hash_snapshot_media.py",
            "tool_sha256_at_test": hash_tool_sha256,
            "affected_check": "relative in seen; seen.add(relative)",
            "reproductions": [
                "test_known_bug_normalized_alias_duplicate_should_be_rejected",
                "test_known_bug_case_alias_duplicate_should_be_rejected_on_windows",
            ],
            "observed": "Both tests reproduce passed=true and duplicated file/byte counts for one physical file using distinct path strings.",
            "tests_marked_expected_failure": True,
            "hash_tool_modified": False,
            "impact_on_this_report": "None detected: all 141 saved report paths are unique after Windows normcase/normpath normalization.",
            "suggested_fix_for_main_agent": "Deduplicate resolved, case-normalized file paths, not raw manifest strings; keep card containment validation.",
        }],
        "uncovered_paths": [r["relative_path"] for r in entries if not r["historical_sha256_match"]],
        "limitations": [
            "No whole-card pre-repair content hash exists; unmatched photos, raw files, thumbnails, native clips and proxy files cannot be declared byte-preserved.",
            "The existing post-report establishes hashes only at its recorded completion time, not the current card state.",
            "Snapshot attempt status is recorded separately; this join reads saved local artifacts, not live card state.",
            "Historical failure/success observations remain pre-repair observations; matching media does not establish post-repair listing, thumbnails, decoder admission or playback.",
            "No local package media are rehashed. Optional current local reference rehashes supplement, but never replace, independent historical digest records.",
            "Only deployed-package build/verification files, enumerated historical rounds/reference checks and matched-pair records are searched. Unparsed logs or other reports may contain additional evidence.",
            "Same size and mtime do not exclude same-length edits with restored timestamps; filesystem timestamps are not trusted chronology.",
            "C6507/C6509 historical failures do not disappear because their unchanged bytes still match; their cause and post-repair behavior remain unresolved.",
        ],
        "entries": entries,
    }
    report["crosscheck_passed_for_priority"] = (
        not baseline_mismatches and all(r["status"] != "NO_PRIOR_CONTENT_HASH_MATCH" for r in priority)
        and all(pair["whole_media_bytes_preserved_relative_to_historical_pair"] for pair in pairs)
        and all(r["stable_during_hash"] and r["matches_post_repair"]
                and r["matches_prior_independent_record"] for r in local_checks))
    return report


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--root", type=Path, default=Path(__file__).resolve().parents[1])
    ap.add_argument("--output", default="analysis/repair-media-preservation-0027.json")
    ap.add_argument("--hash-local-references", action="store_true")
    ap.add_argument("--snapshot-attempt", default="not_attempted")
    args = ap.parse_args()
    root = args.root.resolve()
    output = local_path(root, args.output)
    if output.exists():
        raise FileExistsError(output)
    report = join(root, args.hash_local_references, args.snapshot_attempt)
    with output.open("x", encoding="utf-8") as stream:
        json.dump(report, stream, indent=2)
        stream.write("\n")
    print(json.dumps({key: report[key] for key in (
        "coverage", "direct_pre_repair_media_hashes", "direct_pre_repair_hash_mismatches",
        "crosscheck_passed_for_priority")}, indent=2))
    if not report["crosscheck_passed_for_priority"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
