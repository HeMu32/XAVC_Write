"""Producer-prefixed outputs using the existing offline project in read-only mode."""
import argparse
import json
import subprocess
from pathlib import Path

HERE = Path(__file__).resolve().parent
p = argparse.ArgumentParser()
p.add_argument("survey", nargs="?", default="producer-survey.json")
p.add_argument("--tag", default="producer-ghidra")
args = p.parse_args()
assert args.tag.startswith("producer")
d = json.loads((HERE / args.survey).read_text())
target = HERE / (args.tag + "-targets.txt")
target.write_text("\n".join(f"{f['start']} {f['size']}" for f in d["functions"]) + "\n")
cmd = ["E:/Program Files/jdk-21/bin/java.exe", "-Xmx4G", "-Djava.awt.headless=true",
       "-Djava.system.class.loader=ghidra.GhidraClassLoader", "-Dfile.encoding=UTF8",
       "-Dapplication.settingsdir=" + str(HERE / "producer-settings"), "-cp",
       "E:/Program Files/ghidra_12.1.4_PUBLIC/Ghidra/Framework/Utility/lib/Utility.jar",
       "ghidra.Ghidra", "ghidra.app.util.headless.AnalyzeHeadless", str(HERE), "catalog",
       "-process", "appFw.so", "-noanalysis", "-readOnly", "-max-cpu", "2",
       "-scriptPath", str(HERE), "-postScript", "producerGhidra.java", str(HERE), str(target),
       "-log", str(HERE / (args.tag + "-application.log")),
       "-scriptlog", str(HERE / (args.tag + "-script.log"))]
logpath = HERE / (args.tag + "-headless.log")
with logpath.open("w") as log:
    completed = subprocess.run(cmd, stdout=log, stderr=subprocess.STDOUT)
assert "ERROR REPORT SCRIPT ERROR" not in logpath.read_text(), str(logpath)
print("exit", completed.returncode)
raise SystemExit(completed.returncode)
