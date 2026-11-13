import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;
import java.nio.file.Files;
import java.nio.file.Path;

public class producerGhidra extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Path out = Path.of(args[0]);
        long bias = currentProgram.getImageBase().getOffset();
        for (String spec : Files.readAllLines(Path.of(args[1]))) {
            if (spec.isBlank()) continue;
            String[] parts = spec.split(" ");
            long start = Long.decode(parts[0]), size = Long.decode(parts[1]);
            Address a = toAddr(start + bias);
            Function f = getFunctionAt(a);
            AddressSet body = new AddressSet(a, a.add(size - 1));
            if (f == null) {
                Function enclosing = getFunctionContaining(a);
                if (enclosing != null && enclosing.getEntryPoint().compareTo(a) < 0) {
                    AddressSet reduced = new AddressSet(enclosing.getBody());
                    reduced.delete(a, a.add(size - 1));
                    enclosing.setBody(reduced);
                }
                disassemble(a);
                f = currentProgram.getFunctionManager().createFunction(
                    "producer_" + Long.toHexString(start), a, body, SourceType.USER_DEFINED);
            } else {
                f.setBody(body);
            }
            println("TARGET " + a + " size " + size);
        }
        DecompInterface dec = new DecompInterface();
        dec.openProgram(currentProgram);
        for (String spec : Files.readAllLines(Path.of(args[1]))) {
            if (spec.isBlank()) continue;
            long start = Long.decode(spec.split(" ")[0]);
            Function f = getFunctionAt(toAddr(start + bias));
            DecompileResults r = dec.decompileFunction(f, 45, monitor);
            if (!r.decompileCompleted()) throw new Exception(r.getErrorMessage());
            Files.writeString(out.resolve("producer-" + Long.toHexString(start) + ".c"),
                "// Original ELF VMA 0x" + Long.toHexString(start)
                + "; Ghidra bias 0x" + Long.toHexString(bias)
                + "; readOnly project session\n" + r.getDecompiledFunction().getC());
            println("EXPORTED " + f.getEntryPoint());
        }
        dec.dispose();
    }
}
