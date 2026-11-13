import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import java.nio.file.Files;
import java.nio.file.Path;

public class TargetLoaded extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Path out = Path.of(args[0]);
        Files.createDirectories(out);
        DecompInterface dec = new DecompInterface();
        dec.openProgram(currentProgram);
        println("IMAGE_BASE " + currentProgram.getImageBase() + " LANGUAGE "
                + currentProgram.getLanguageID());
        for (String value : args[1].split(",")) {
            Address address = toAddr(value);
            Function f = getFunctionAt(address);
            boolean decoded = disassemble(address);
            if (f != null && f.getBody().getNumAddresses() <= 1) {
                currentProgram.getFunctionManager().removeFunction(address);
                f = null;
            }
            if (f == null) {
                f = createFunction(address, "loaded_" + value);
            }
            if (f == null) {
                println("UNRECOVERED " + address);
                continue;
            }
            DecompileResults result = dec.decompileFunction(f, 30, monitor);
            String text = "// Normalized static image, not an observed export trace.\n";
            text += "// Preferred VA " + address + "\n";
            text += "// Disassembly returned " + decoded + "; body bytes "
                    + f.getBody().getNumAddresses() + "\n";
            text += result.decompileCompleted() ? result.getDecompiledFunction().getC()
                                               : "// FAILED " + result.getErrorMessage();
            Files.writeString(out.resolve(value + ".c"), text);
            StringBuilder assembly = new StringBuilder();
            for (Instruction ins : currentProgram.getListing().getInstructions(f.getBody(), true)) {
                assembly.append(ins.getAddress()).append(" ").append(ins).append("\n");
            }
            Files.writeString(out.resolve(value + ".asm.txt"), assembly.toString());
            println("EXPORTED " + address + " bytes " + f.getBody().getNumAddresses()
                    + " decompile " + result.decompileCompleted());
        }
        dec.dispose();
    }
}
