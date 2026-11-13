"""Import the pinned loaded image without global auto-analysis; decompile explicit targets."""
import hashlib
import subprocess
from pathlib import Path

HERE = Path(__file__).resolve().parent
SOURCE = HERE.parent / "live-mpeg-47056-20261112T134903Z/CtsMpegPlugIn.loaded-normalized-pe.bin"
EXPECTED = "b610fd1440b389324c0513219b1930743947d977fe1d4342f489ec95ccbb83f4"
TARGETS = ["18023bf00", "180237b80", "1801b86f0", "1801bf1a0",
           "1801c4360", "1801c3070", "1801c1ab0", "1802356a0",
           "1801b89a0", "18043c630", "180440310", "18043f520",
           "1802352b0", "1801b8ca0", "1801b8f50", "180440750", "1804a9f30"]


def main():
    if hashlib.sha256(SOURCE.read_bytes()).hexdigest() != EXPECTED:
        raise ValueError("The hash-pinned loaded analysis image is required")
    project = HERE / "project"
    project.mkdir(exist_ok=True)
    existing = (project / "loaded-focused.gpr").is_file()
    command = [
        "E:/Program Files/jdk-21/bin/java.exe", "-Xmx2G", "-Djava.awt.headless=true",
        "-Djava.system.class.loader=ghidra.GhidraClassLoader", "-Dfile.encoding=UTF8", "-cp",
        "E:/Program Files/ghidra_12.1.4_PUBLIC/Ghidra/Framework/Utility/lib/Utility.jar",
        "ghidra.Ghidra", "ghidra.app.util.headless.AnalyzeHeadless", str(project), "loaded-focused"]
    command += (["-process", SOURCE.name, "-readOnly"] if existing else ["-import", str(SOURCE)])
    command += ["-noanalysis", "-scriptPath", str(HERE), "-postScript", "TargetLoaded.java",
                str(HERE / "decompile"), ",".join(TARGETS), "-max-cpu", "2"]
    with (HERE / "headless.log").open("w", encoding="utf-8") as stream:
        completed = subprocess.run(command, stdout=stream, stderr=subprocess.STDOUT, timeout=300)
    print("exit", completed.returncode, "log", HERE / "headless.log")
    raise SystemExit(completed.returncode)


if __name__ == "__main__":
    main()
