import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.Reference;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.*;
import java.util.regex.Pattern;

public class InspectWriter extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Path out = Path.of(args[0]);
        Files.createDirectories(out);
        Set<Function> selected = new TreeSet<>(Comparator.comparing(f -> f.getEntryPoint()));
        for (String a : args[1].split(",")) {
            if (a.isEmpty()) continue;
            Function f = getFunctionAt(toAddr(a));
            if (f == null) f = getFunctionContaining(toAddr(a));
            if (f != null) selected.add(f);
            for (Reference ref : getReferencesTo(toAddr(a))) {
                f = getFunctionContaining(ref.getFromAddress());
                if (f != null) selected.add(f);
            }
        }
        Pattern pattern = Pattern.compile(args[2], Pattern.CASE_INSENSITIVE);
        StringBuilder evidence = new StringBuilder();
        evidence.append("PROGRAM ").append(currentProgram.getName())
            .append(" BASE ").append(currentProgram.getImageBase()).append("\n");
        DataIterator data = currentProgram.getListing().getDefinedData(true);
        while (data.hasNext()) {
            Data d = data.next();
            if (!(d.getValue() instanceof String) || !pattern.matcher((String)d.getValue()).find()) continue;
            for (Reference ref : getReferencesTo(d.getAddress())) {
                Function f = getFunctionContaining(ref.getFromAddress());
                evidence.append("STRING ").append(d.getAddress()).append(" ").append(d.getValue())
                    .append(" XREF ").append(ref.getFromAddress()).append(" FUNCTION ")
                    .append(f == null ? "none" : f.getEntryPoint()).append("\n");
                if (f != null) selected.add(f);
            }
        }
        DecompInterface dec = new DecompInterface();
        dec.openProgram(currentProgram);
        int count = 0;
        for (Function f : selected) {
            if (f.isExternal() || count >= 120) continue;
            evidence.append("FUNCTION ").append(f.getEntryPoint()).append(" ").append(f.getName(true)).append("\n");
            for (Reference ref : getReferencesTo(f.getEntryPoint())) {
                evidence.append("REF ").append(ref.getFromAddress()).append(" ")
                    .append(ref.getReferenceType()).append("\n");
            }
            for (Function called : f.getCalledFunctions(monitor)) {
                evidence.append("CALLS ").append(called.getEntryPoint()).append(" ")
                    .append(called.getName(true)).append("\n");
            }
            DecompileResults result = dec.decompileFunction(f, 30, monitor);
            String text = "// " + f.getName(true) + "\n// VA " + f.getEntryPoint() + "\n";
            text += result.decompileCompleted() ? result.getDecompiledFunction().getC()
                : "// FAILED " + result.getErrorMessage();
            Files.writeString(out.resolve(f.getEntryPoint() + ".c"), text);
            count++;
        }
        dec.dispose();
        Files.writeString(out.resolve("references.txt"), evidence);
        println("EXPORTED " + count + " functions to " + out);
    }
}
