"""Independent, targeted, no-autoanalysis appFw Ghidra project."""
import argparse
import json
import subprocess
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]

p = argparse.ArgumentParser()
p.add_argument("survey")
p.add_argument("--existing", action="store_true")
p.add_argument("--tag", default="initial")
a = p.parse_args()
d = json.loads((HERE / a.survey).read_text())
targets = HERE / (a.tag + "-targets.txt")
targets.write_text("\n".join(f"{f['start']} {f['size']}" for f in d["functions"]) + "\n")
cmd = ["E:/Program Files/jdk-21/bin/java.exe", "-Xmx4G", "-Djava.awt.headless=true",
       "-Djava.system.class.loader=ghidra.GhidraClassLoader", "-Dfile.encoding=UTF8",
       "-Dapplication.settingsdir=" + str(HERE / "settings"),
       "-cp", "E:/Program Files/ghidra_12.1.4_PUBLIC/Ghidra/Framework/Utility/lib/Utility.jar",
       "ghidra.Ghidra", "ghidra.app.util.headless.AnalyzeHeadless", str(HERE), "catalog"]
cmd += (["-process", "appFw.so"] if a.existing else
        ["-import", str(ROOT / "firmware/m4-v602/usr/lib/appFw.so")])
cmd += ["-noanalysis", "-scriptPath", str(HERE), "-postScript", "TargetAppFw.java",
        str(HERE), str(targets), "-max-cpu", "2",
        "-log", str(HERE / (a.tag + "-application.log")),
        "-scriptlog", str(HERE / (a.tag + "-script.log"))]
with (HERE / (a.tag + "-headless.log")).open("w") as log:
    r = subprocess.run(cmd, stdout=log, stderr=subprocess.STDOUT)
text = (HERE / (a.tag + "-headless.log")).read_text()
if "ERROR REPORT SCRIPT ERROR" in text or "FAILED:" in text:
    raise SystemExit("Ghidra script failed; inspect " + a.tag + "-headless.log")
print("exit", r.returncode)
raise SystemExit(r.returncode)
