/*
 * Purpose: export raw imola2 dispatch-table words and recovered direct xrefs.
 * Usage: run TraceVcdDispatch.java in Ghidra on the matching prepared program;
 *        writes analysis/vcd-dispatch-table.json relative to this script's repo.
 * Design: check known dispatch pointers, scan fixed ranges for both core
 *         deltas, and retain referenced instructions/functions without execution.
 * Scope: static recovered references only; table boundaries and indirect
 *        consumers are not proven. Does not patch firmware or run a decoder.
 */
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.symbol.Reference;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import com.google.gson.GsonBuilder;

public class TraceVcdDispatch extends GhidraScript {
    public void run() throws Exception {
        ArrayList<Object> tables = new ArrayList<>();
        for (long delta : new long[] {0, 0x1ab000L}) {
            if (getInt(toAddr(0x807b6f74L + delta)) != (int)(0x80798344L + delta)) {
                throw new Exception("Unexpected imola2 dispatch pointer");
            }
            ArrayList<Object> rows = new ArrayList<>();
            for (long base = 0x807b6e00L; base < 0x807b6fa0L; base += 4) {
                long address = base + delta;
                ArrayList<Object> refs = new ArrayList<>();
                for (Reference ref : getReferencesTo(toAddr(address))) {
                    Function f = getFunctionContaining(ref.getFromAddress());
                    Instruction ins = getInstructionAt(ref.getFromAddress());
                    LinkedHashMap<String, Object> item = new LinkedHashMap<>();
                    item.put("from", ref.getFromAddress().toString());
                    item.put("type", ref.getReferenceType().toString());
                    item.put("function", f == null ? null : f.getEntryPoint().toString());
                    item.put("instruction", ins == null ? null : ins.toString());
                    refs.add(item);
                    println("TABLE_REFERENCE " + Long.toHexString(address) + " " + item);
                }
                LinkedHashMap<String, Object> row = new LinkedHashMap<>();
                row.put("address", Long.toHexString(address));
                row.put("word", Integer.toUnsignedString(getInt(toAddr(address)), 16));
                row.put("references", refs);
                rows.add(row);
            }
            LinkedHashMap<String, Object> table = new LinkedHashMap<>();
            table.put("core_delta", Long.toHexString(delta));
            table.put("words", rows);
            tables.add(table);
        }
        LinkedHashMap<String, Object> result = new LinkedHashMap<>();
        result.put("program", currentProgram.getName());
        result.put("scope", "Raw words and recovered direct references; table boundaries unproven");
        result.put("tables", tables);
        Path root = Path.of(getSourceFile().getAbsolutePath()).getParent().getParent();
        Files.writeString(root.resolve("analysis/vcd-dispatch-table.json"),
            new GsonBuilder().setPrettyPrinting().create().toJson(result));
    }
}
