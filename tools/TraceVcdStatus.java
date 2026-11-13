/*
 * Purpose: export direct readers/writers of the two identified VCD status words.
 * Usage: run TraceVcdStatus.java in the prepared imola2 Ghidra program;
 *        writes analysis/vcd-status-xrefs.json and prints read-only consumers.
 * Design: collect recovered references, instructions and containing functions,
 *         then count static reads/writes per function at the fixed addresses.
 * Scope: existing direct-reference recovery only, not a dynamic execution trace
 *        or complete status dataflow; no firmware/card modification.
 */
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.symbol.Reference;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.Map;
import com.google.gson.GsonBuilder;

public class TraceVcdStatus extends GhidraScript {
    public void run() throws Exception {
        ArrayList<Object> words = new ArrayList<>();
        for (long value : new long[] {0x807c0368L, 0x8096b368L}) {
            Address address = toAddr(value);
            LinkedHashMap<String, LinkedHashMap<String, Object>> functions = new LinkedHashMap<>();
            ArrayList<Object> references = new ArrayList<>();
            for (Reference ref : getReferencesTo(address)) {
                monitor.checkCancelled();
                Function f = getFunctionContaining(ref.getFromAddress());
                Instruction ins = getInstructionAt(ref.getFromAddress());
                LinkedHashMap<String, Object> row = new LinkedHashMap<>();
                row.put("from", ref.getFromAddress().toString());
                row.put("type", ref.getReferenceType().toString());
                row.put("read", ref.getReferenceType().isRead());
                row.put("write", ref.getReferenceType().isWrite());
                row.put("function", f == null ? null : f.getEntryPoint().toString());
                row.put("instruction", ins == null ? null : ins.toString());
                references.add(row);
                if (f != null) {
                    String key = f.getEntryPoint().toString();
                    LinkedHashMap<String, Object> item = functions.get(key);
                    if (item == null) {
                        item = new LinkedHashMap<>();
                        item.put("function", key);
                        item.put("name", f.getName());
                        item.put("reads", 0);
                        item.put("writes", 0);
                        functions.put(key, item);
                    }
                    if (ref.getReferenceType().isRead()) {
                        item.put("reads", (Integer)item.get("reads") + 1);
                    }
                    if (ref.getReferenceType().isWrite()) {
                        item.put("writes", (Integer)item.get("writes") + 1);
                    }
                }
            }
            LinkedHashMap<String, Object> word = new LinkedHashMap<>();
            word.put("address", address.toString());
            word.put("references", references);
            word.put("functions", new ArrayList<>(functions.values()));
            words.add(word);
            for (Map<String, Object> f : functions.values()) {
                if ((Integer)f.get("reads") > 0 && (Integer)f.get("writes") == 0) {
                    println("READ_ONLY_CONSUMER " + address + " " + f.get("function"));
                }
            }
        }
        LinkedHashMap<String, Object> result = new LinkedHashMap<>();
        result.put("program", currentProgram.getName());
        result.put("language", currentProgram.getLanguageID().toString());
        result.put("scope", "Recovered direct references only; indirect references may be missing");
        result.put("words", words);
        Path root = Path.of(getSourceFile().getAbsolutePath()).getParent().getParent();
        Path out = root.resolve("analysis/vcd-status-xrefs.json");
        Files.writeString(out, new GsonBuilder().setPrettyPrinting().create().toJson(result));
        println("STATUS_XREF_REPORT " + out);
    }
}
