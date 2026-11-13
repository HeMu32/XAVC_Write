from __future__ import annotations

import argparse
import hashlib
import json
import shutil
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def inside_workspace(path: Path) -> bool:
    try:
        path.resolve().relative_to(ROOT)
        return True
    except ValueError:
        return False


def require_local(path: Path) -> Path:
    resolved = path.resolve()
    if not inside_workspace(resolved):
        raise RuntimeError(f"Refusing path outside workspace: {resolved}")
    if resolved.drive.upper() == "F:":
        raise RuntimeError(f"Refusing card path: {resolved}")
    return resolved


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--apply", action="store_true")
    parser.add_argument(
        "--batch",
        choices=("1", "2"),
        default="1",
        help="Cleanup batch to evaluate; batch 1 is already applied",
    )
    args = parser.parse_args()

    report_path = require_local(
        ROOT / "analysis" / f"workspace-cleanup-20261113-batch{args.batch}.json"
    )
    actions: list[dict[str, object]] = []

    if args.batch == "1":
        # Historical generic smoke runs. Their final result is retained in report.json.
        for name in ("generic-smoke-03", "generic-smoke-05"):
            run = require_local(ROOT / "output" / name)
            report = require_local(run / "report.json")
            if not run.is_dir() or not report.is_file():
                raise RuntimeError(f"Missing expected smoke evidence: {run}")
            report_hash = sha256(report)
            for child in sorted(run.iterdir()):
                if child.name == "report.json":
                    continue
                target = require_local(child)
                if target.is_dir():
                    size = sum(p.stat().st_size for p in target.rglob("*") if p.is_file())
                else:
                    size = target.stat().st_size
                actions.append(
                    {
                        "path": target.relative_to(ROOT).as_posix(),
                        "bytes": size,
                        "reason": "obsolete generic smoke intermediate; final report retained",
                        "evidence": report.relative_to(ROOT).as_posix(),
                        "evidence_sha256": report_hash,
                    }
                )

        # The package and deploy copies were verified byte-identical.
        for package, deploy in (
            (
                ROOT / "output" / "profiles-0026-hd50" / "package" / "C6517.MP4",
                ROOT / "output" / "profiles-0026-deploy" / "C6517" / "C6517.MP4",
            ),
            (
                ROOT / "output" / "profiles-0026-uhd60" / "package" / "C6518.MP4",
                ROOT / "output" / "profiles-0026-deploy" / "C6518" / "C6518.MP4",
            ),
        ):
            package = require_local(package)
            deploy = require_local(deploy)
            if not package.is_file() or not deploy.is_file():
                raise RuntimeError(f"Missing duplicate pair: {package}, {deploy}")
            package_hash = sha256(package)
            deploy_hash = sha256(deploy)
            if package_hash != deploy_hash:
                raise RuntimeError(f"Duplicate hash mismatch: {package}")
            actions.append(
                {
                    "path": package.relative_to(ROOT).as_posix(),
                    "bytes": package.stat().st_size,
                    "reason": "byte-identical to retained deployed package media",
                    "evidence": deploy.relative_to(ROOT).as_posix(),
                    "evidence_sha256": deploy_hash,
                }
            )

    if args.batch == "2":
        for name in ("generic-smoke-01", "generic-smoke-02"):
            run = require_local(ROOT / "output" / name)
            report = require_local(run / "report.json")
            if not run.is_dir() or not report.is_file():
                raise RuntimeError(f"Missing expected smoke evidence: {run}")
            report_hash = sha256(report)
            for child in sorted(run.iterdir()):
                if child.name == "report.json":
                    continue
                target = require_local(child)
                size = (
                    sum(p.stat().st_size for p in target.rglob("*") if p.is_file())
                    if target.is_dir()
                    else target.stat().st_size
                )
                actions.append(
                    {
                        "path": target.relative_to(ROOT).as_posix(),
                        "bytes": size,
                        "reason": "historical smoke intermediate; report retained",
                        "evidence": report.relative_to(ROOT).as_posix(),
                        "evidence_sha256": report_hash,
                    }
                )

    payload = {
        "scope": "workspace only; camera card not accessed",
        "applied": bool(args.apply),
        "total_bytes": sum(int(action["bytes"]) for action in actions),
        "actions": actions,
    }
    report_path.write_text(json.dumps(payload, indent=2), encoding="utf-8")

    if not args.apply:
        print(json.dumps(payload, indent=2))
        return

    for action in actions:
        target = require_local(ROOT / str(action["path"]))
        if target.is_dir():
            shutil.rmtree(target)
        elif target.is_file():
            target.unlink()
        else:
            raise RuntimeError(f"Missing cleanup target: {target}")

    print(
        json.dumps(
            {
                "removed_items": len(actions),
                "removed_bytes": payload["total_bytes"],
                "report": report_path.relative_to(ROOT).as_posix(),
            },
            indent=2,
        )
    )


if __name__ == "__main__":
    main()
