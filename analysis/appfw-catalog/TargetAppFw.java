import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.symbol.SourceType;
import java.nio.file.Files;
import java.nio.file.Path;

public class TargetAppFw extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Path out = Path.of(args[0]);
        long bias = currentProgram.getImageBase().getOffset();
        println("IMAGE_BASE " + currentProgram.getImageBase());
        for (String spec : Files.readAllLines(Path.of(args[1]))) {
            if (spec.isBlank()) continue;
            String[] p = spec.split(" ");
            long start = Long.decode(p[0]), size = Long.decode(p[1]);
            Address a = toAddr(start + bias);
            AddressSet body = new AddressSet(a, a.add(size - 1));
            disassemble(a);
            Function f = getFunctionAt(a);
            if (f == null) {
                f = currentProgram.getFunctionManager().createFunction(
                    "appfw_" + Long.toHexString(start), a, body, SourceType.USER_DEFINED);
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
            DecompileResults r = dec.decompileFunction(f, 50, monitor);
            String text = "// ELF VMA 0x" + Long.toHexString(start)
                + "; Ghidra bias 0x" + Long.toHexString(bias) + "\n";
            text += r.decompileCompleted() ? r.getDecompiledFunction().getC()
                : "// FAILED: " + r.getErrorMessage();
            Files.writeString(out.resolve(Long.toHexString(start) + ".c"), text);
            println("EXPORTED " + f.getEntryPoint());
        }
        dec.dispose();
    }
}
