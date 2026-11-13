/*
 * Purpose: export selected Ghidra functions as decompiled C for XAVC research.
 * Usage: headless -postScript FocusXavc.java OUTPUT_DIR FUNCTION_REGEX
 *        [STRING_REGEX], or tools/run_ghidra.py with --pattern/--strings.
 * Design: select names, @address references and optional string xrefs; export
 *         bounded decompilations with original Ghidra addresses and failures.
 * Scope: the currently loaded program and recovered references only. Writes
 *        local exports, not firmware bytes; selection is not a complete call graph.
 */
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.regex.Pattern;
import java.util.HashSet;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.DataIterator;
import ghidra.program.model.symbol.Reference;

public class FocusXavc extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Path out = Path.of(args[0]);
        Files.createDirectories(out);
        Pattern pattern = Pattern.compile(args[1], Pattern.CASE_INSENSITIVE);
        HashSet<Function> selected = new HashSet<>();
        java.util.regex.Matcher addresses = Pattern.compile("@([0-9a-fA-F]+)").matcher(args[1]);
        while (addresses.find()) {
            ghidra.program.model.address.Address a = toAddr(addresses.group(1));
            Function target = getFunctionAt(a);
            if (target == null) target = getFunctionContaining(a);
            if (target != null) selected.add(target);
            for (Reference ref : getReferencesTo(a)) {
                Function f = getFunctionContaining(ref.getFromAddress());
                if (f != null) selected.add(f);
            }
        }
        if (args.length > 2) {
            Pattern strings = Pattern.compile(args[2], Pattern.CASE_INSENSITIVE);
            DataIterator data = currentProgram.getListing().getDefinedData(true);
            while (data.hasNext()) {
                Data d = data.next();
                if (!(d.getValue() instanceof String) ||
                    !strings.matcher((String)d.getValue()).find()) continue;
                for (Reference ref : getReferencesTo(d.getAddress())) {
                    Function f = getFunctionContaining(ref.getFromAddress());
                    if (f != null) {
                        selected.add(f);
                        println("STRING_XREF " + d.getAddress() + " " + d.getValue() +
                            " -> " + f.getEntryPoint());
                    }
                }
            }
        }
        DecompInterface dec = new DecompInterface();
        dec.openProgram(currentProgram);
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        int count = 0;
        while (it.hasNext() && !monitor.isCancelled()) {
            Function f = it.next();
            String name = f.getName(true);
            if (f.isExternal() || f.isThunk() ||
                (!pattern.matcher(name).find() && !selected.contains(f))) continue;
            DecompileResults r = dec.decompileFunction(f, 60, monitor);
            String filename = f.getEntryPoint().toString() + "_" +
                f.getName().replaceAll("[^A-Za-z0-9_.-]", "_");
            if (filename.length() > 170) filename = filename.substring(0, 170);
            String text = "// " + name + "\n// Ghidra address: " + f.getEntryPoint() + "\n";
            text += r.decompileCompleted() ? r.getDecompiledFunction().getC() : "// FAILED: " + r.getErrorMessage();
            Files.writeString(out.resolve(filename + ".c"), text);
            println("EXPORTED " + f.getEntryPoint() + " " + name);
            count++;
        }
        dec.dispose();
        println("EXPORTED COUNT " + count);
    }
}
