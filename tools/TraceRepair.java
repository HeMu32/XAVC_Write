/*
 * Purpose: export selected sidb/repair/NRT functions from the M4 libmpr project.
 * Usage: run Ghidra post-script TraceRepair.java [OUTPUT_DIR], normally via
 *        tools/run_ghidra.py --existing --post-script TraceRepair.java.
 * Design: visit fixed Ghidra entries, export recovered-body instruction bytes
 *         and decompiled C, and retain explicit missing/decompilation failures.
 * Scope: identified import/base; no function recovery or firmware execution.
 *        Ghidra bodies may be incomplete: use ELF-symbol exports for full ranges.
 */
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import java.nio.file.Files;
import java.nio.file.Path;

public class TraceRepair extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Path out = Path.of(args.length > 0 ? args[0] : "analysis/repair-firmware-0027");
        Files.createDirectories(out);
        String[] targets = {
            "001b9340", "001baba4", "001b9848", "001de778", "001de3d8", "001de530",
            "0038e754", "00392a38", "00392954", "0038e698", "0038e3c0",
            "0039267c", "00391c28", "003cd954", "00393bb8", "003992c8",
            "0038e50c", "003cd6b0", "00341af0", "00342354", "00341dac", "0038a6a4",
            "00341e8c", "00341c44"
        };
        DecompInterface dec = new DecompInterface();
        dec.openProgram(currentProgram);
        for (String value : targets) {
            Address address = toAddr(value);
            Function function = getFunctionAt(address);
            if (function == null) {
                println("MISSING " + value);
                continue;
            }
            StringBuilder assembly = new StringBuilder();
            assembly.append("// ").append(function.getName(true)).append("\n");
            assembly.append("// ELF VMA = Ghidra address - 0x100000\n");
            for (Instruction ins : currentProgram.getListing().getInstructions(function.getBody(), true)) {
                assembly.append(ins.getAddress()).append(" ");
                for (byte b : ins.getBytes()) assembly.append(String.format("%02x", b & 255));
                assembly.append(" ").append(ins.toString()).append("\n");
            }
            Files.writeString(out.resolve(value + ".asm.txt"), assembly.toString());
            DecompileResults result = dec.decompileFunction(function, 30, monitor);
            String text = "// " + function.getName(true) + "\n// Ghidra address " + value
                + "; ELF VMA = Ghidra - 0x100000\n";
            text += result.decompileCompleted() ? result.getDecompiledFunction().getC()
                : "// DECOMPILATION FAILED: " + result.getErrorMessage();
            Files.writeString(out.resolve(value + ".c"), text);
            println("EXPORTED " + value + " bytes " + function.getBody().getNumAddresses()
                + " C=" + result.decompileCompleted());
        }
        dec.dispose();
    }
}
