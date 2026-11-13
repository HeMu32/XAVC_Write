"""Purpose: run bounded Ghidra headless work in the workspace analysis project.

Usage: python tools/run_ghidra.py BINARY --pattern REGEX --label LABEL
    [--existing --post-script SCRIPT.java --log LOGFILE].
Design: invoke configured JDK/Ghidra paths, FocusXavc exports and optional scripts;
    --existing selects noanalysis/readOnly, while new imports create project data.
Scope: the configured local Windows installation and independent projects.
    Import/pre/post scripts may modify project state; no camera execution.
"""
import argparse
import subprocess
from pathlib import Path


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("binary")
    ap.add_argument("--pattern", required=True)
    ap.add_argument("--existing", action="store_true")
    ap.add_argument("--label", default="mpr")
    ap.add_argument("--strings")
    ap.add_argument("--raw-base")
    ap.add_argument("--processor")
    ap.add_argument("--pre-script")
    ap.add_argument("--log")
    ap.add_argument("--post-script", action="append", default=[])
    args = ap.parse_args()
    root = Path(__file__).resolve().parent.parent
    project = root / "analysis/ghidra"
    project.mkdir(parents=True, exist_ok=True)
    out = root / "analysis" / ("decompile-" + args.label)
    command = ["E:/Program Files/jdk-21/bin/java.exe", "-Xmx2G", "-Djava.awt.headless=true",
               "-Djava.system.class.loader=ghidra.GhidraClassLoader", "-Dfile.encoding=UTF8", "-cp",
               "E:/Program Files/ghidra_12.1.4_PUBLIC/Ghidra/Framework/Utility/lib/Utility.jar",
               "ghidra.Ghidra", "ghidra.app.util.headless.AnalyzeHeadless",
               str(project), args.label]
    command += (["-process", Path(args.binary).name, "-noanalysis", "-readOnly"] if args.existing
                else ["-import", str(Path(args.binary).resolve()), "-analysisTimeoutPerFile", "180"])
    if args.raw_base:
        if args.existing or not args.processor:
            raise ValueError("Raw import requires --processor and a new project")
        command += ["-loader", "BinaryLoader", "-loader-baseAddr", args.raw_base,
                    "-processor", args.processor]
    command += ["-scriptPath", str(root / "tools")]
    if args.pre_script:
        command += ["-preScript", args.pre_script]
    command += ["-postScript", "FocusXavc.java", str(out), args.pattern]
    if args.strings:
        command += [args.strings]
    for script in args.post_script:
        command += ["-postScript", script]
    command += ["-max-cpu", "2"]
    log = Path(args.log) if args.log else root / "analysis" / ("ghidra-" + args.label + ".log")
    log.parent.mkdir(parents=True, exist_ok=True)
    with log.open("w", encoding="utf-8") as f:
        completed = subprocess.run(command, stdout=f, stderr=subprocess.STDOUT)
    print("exit", completed.returncode, "log", log, "output", out)
    raise SystemExit(completed.returncode)


if __name__ == "__main__":
    main()
