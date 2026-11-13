"""Independent, bounded PE analysis. Never opens an existing shared Ghidra project."""
import argparse
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parent


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("binary")
    ap.add_argument("--label", required=True)
    ap.add_argument("--addresses", default="")
    ap.add_argument("--strings", default="a^")
    ap.add_argument("--existing", action="store_true")
    ap.add_argument("--tag", default="")
    args = ap.parse_args()
    binary = Path(args.binary).resolve()
    project = ROOT / "ghidra"
    project.mkdir(exist_ok=True)
    suffix = ("-" + args.tag) if args.tag else ""
    output = ROOT / ("decompile-" + args.label + suffix)
    command = [
        r"E:\Program Files\jdk-21\bin\java.exe", "-Xmx2G", "-Djava.awt.headless=true",
        "-Djava.system.class.loader=ghidra.GhidraClassLoader", "-Dfile.encoding=UTF8",
        "-cp", r"E:\Program Files\ghidra_12.1.4_PUBLIC\Ghidra\Framework\Utility\lib\Utility.jar",
        "ghidra.Ghidra", "ghidra.app.util.headless.AnalyzeHeadless",
        str(project), args.label,
    ]
    command += (["-process", binary.name, "-noanalysis", "-readOnly"] if args.existing else
                ["-import", str(binary), "-analysisTimeoutPerFile", "180"])
    command += [
        "-scriptPath", str(ROOT),
        "-postScript", "InspectWriter.java", str(output), args.addresses, args.strings,
        "-max-cpu", "2",
    ]
    log = ROOT / (args.label + ("-followup" if args.existing else "") + suffix + ".log")
    with log.open("w", encoding="utf-8") as stream:
        result = subprocess.run(command, stdout=stream, stderr=subprocess.STDOUT)
    print("exit", result.returncode, "log", log)
    raise SystemExit(result.returncode)


if __name__ == "__main__":
    main()
