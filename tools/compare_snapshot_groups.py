from __future__ import annotations

import hashlib
import json
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
BACKUP = ROOT / "backup"


def digest(path: Path) -> str:
    value = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            value.update(block)
    return value.hexdigest()


def file_set(root: Path) -> list[tuple[str, int, str]]:
    result = []
    for path in sorted(p for p in root.rglob("*") if p.is_file()):
        result.append(
            (path.relative_to(root).as_posix(), path.stat().st_size, digest(path))
        )
    return result


def main() -> None:
    groups: dict[tuple[str, str], list[Path]] = {}
    for snapshot in sorted(p for p in BACKUP.iterdir() if p.is_dir()):
        database = snapshot / "PRIVATE" / "DATABASE" / "DATABASE.BIN"
        mediapro = snapshot / "PRIVATE" / "M4ROOT" / "MEDIAPRO.XML"
        if not database.is_file() or not mediapro.is_file():
            continue
        groups.setdefault((digest(database), digest(mediapro)), []).append(snapshot)

    rows = []
    for (database, mediapro), snapshots in groups.items():
        sets = {snapshot.name: file_set(snapshot) for snapshot in snapshots}
        reference_name = snapshots[0].name
        reference = sets[reference_name]
        matching = [name for name, value in sets.items() if value == reference]
        rows.append(
            {
                "database_sha256": database,
                "mediapro_sha256": mediapro,
                "snapshots": [p.name for p in snapshots],
                "exact_file_set_matches": matching,
                "all_exact_file_set_match": len(matching) == len(snapshots),
                "bytes": sum(
                    p.stat().st_size for p in (BACKUP / reference_name).rglob("*")
                    if p.is_file()
                ),
            }
        )

    output = ROOT / "analysis" / "snapshot-cleanup-groups-20261113.json"
    output.write_text(json.dumps(rows, indent=2), encoding="utf-8")
    for row in rows:
        print(
            f"{len(row['snapshots']):2d} "
            f"{'MATCH' if row['all_exact_file_set_match'] else 'DIFF ':5s} "
            f"{row['snapshots'][0]} .. {row['snapshots'][-1]}"
        )


if __name__ == "__main__":
    main()
