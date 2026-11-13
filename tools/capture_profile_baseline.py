"""Read-only selected media hashes before/after an additive profile round."""
import argparse
import hashlib
import json
from pathlib import Path

from audit_card_snapshot import audit
from hash_snapshot_media import fingerprint


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--card", required=True)
    ap.add_argument("--snapshot", required=True)
    ap.add_argument("--known-hashes", default="analysis/repair-media-hashes-0027.json")
    ap.add_argument("--output", required=True)
    args = ap.parse_args()
    card, snapshot, known, output = [Path(value).resolve() for value in
                                     (args.card, args.snapshot, args.known_hashes, args.output)]
    if output == card or card in output.parents or output == snapshot or snapshot in output.parents:
        raise ValueError("Report must not modify card or snapshot")
    if output.exists():
        raise FileExistsError(output)
    state = audit(card, snapshot)
    if not state["unchanged"]:
        raise ValueError("Card no longer matches the supplied snapshot")
    originals = json.loads(known.read_text(encoding="utf-8"))
    if not originals["passed"]:
        raise ValueError("Incomplete known media hash report")
    hashes = {row["relative_path"]: row["sha256"] for row in originals["entries"]}
    controls = []
    for clip in ("C6501", "C6515", "C6517", "C6518"):
        relative = f"PRIVATE/M4ROOT/CLIP/{clip}.MP4"
        path = card / relative
        before = fingerprint(path)
        with path.open("rb") as stream:
            value = hashlib.file_digest(stream, "sha256").hexdigest()
        controls.append({"clip": clip, "relative_path": relative, "sha256": value,
                         "size": before[0], "mtime_ns": before[1],
                         "stable_during_hash": fingerprint(path) == before,
                         "matches_known_repair_hash": hashes[relative] == value})
    report = {
        "snapshot": str(snapshot), "card": str(card), "card_writes": False,
        "known_hashes": str(known), "snapshot_audit": state, "controls": controls,
        "passed": all(row["stable_during_hash"] and row["matches_known_repair_hash"]
                      for row in controls),
        "scope": "Metadata and size/mtime audit plus four complete media hashes; not a whole-card content hash"}
    output.parent.mkdir(parents=True, exist_ok=True)
    with output.open("x", encoding="utf-8") as stream:
        json.dump(report, stream, indent=2)
    print(json.dumps({"passed": report["passed"], "controls": controls}, indent=2))
    if not report["passed"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
