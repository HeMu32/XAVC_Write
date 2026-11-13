/*
 * Purpose: recover and export the identified MediaProfile catalog functions.
 * Usage: on the matching imported libmpr program, run Ghidra post-script
 *        RecoverCatalog.java [OUTPUT_DIR]; default: analysis/decompile-mediapro.
 * Design: visit a fixed address list, disassemble/create missing functions,
 *         and export both recovered-body assembly and decompiled C.
 * Scope: the identified program/base only; Ghidra addresses include its import
 *        bias. Can modify project functions; exports are not full runtime proof.
 */
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import java.nio.file.Files;
import java.nio.file.Path;

public class RecoverCatalog extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        Path out = Path.of(args.length > 0 ? args[0] : "analysis/decompile-mediapro");
        Files.createDirectories(out);
        String[] targets = {
            "00286954", "00282d68", "002866f4", "002875c0", "0028e5e8",
            "00282c5c", "00283924", "0028348c", "002834b4", "00289fcc",
            "0028e8e0", "00283520", "0028a550", "0028e9ec", "00286874",
            "0028efa0", "0028323c", "00286970", "002811ec", "0028ff90",
            "00286448", "0028abc0", "0028ab08", "0028ade0", "0028aec0",
            "00282bd0", "002835f8", "00290b40", "0028ff44", "002900b8",
            "0028bc30", "0028b560", "0028bbec", "0028b704", "0028b7ac",
            "00290000", "0028bec4", "0028ba24", "0028bac4", "0029019c",
            "002901cc", "002901fc", "0028e0d0", "00280c20", "00280cc4",
            "00291d4c", "00280e18"
        };
        DecompInterface dec = new DecompInterface();
        dec.openProgram(currentProgram);
        for (String value : targets) {
            Address address = toAddr(value);
            Function function = getFunctionAt(address);
            if (function == null) {
                disassemble(address);
                function = createFunction(address, "catalog_" + value);
            }
            if (function == null) {
                println("UNRECOVERED " + address);
                continue;
            }
            DecompileResults result = dec.decompileFunction(function, 45, monitor);
            String text = "// Ghidra: " + address + "; ELF VMA = Ghidra - 0x100000\n";
            text += result.decompileCompleted() ? result.getDecompiledFunction().getC()
                                               : "// FAILED " + result.getErrorMessage();
            Files.writeString(out.resolve(value + ".c"), text);
            StringBuilder assembly = new StringBuilder();
            for (Instruction ins : currentProgram.getListing().getInstructions(function.getBody(), true)) {
                assembly.append(ins.getAddress()).append(" ").append(ins.toString()).append("\n");
            }
            Files.writeString(out.resolve(value + ".asm.txt"), assembly.toString());
            println("RECOVERED " + address + " bytes " + function.getBody().getNumAddresses());
        }
        dec.dispose();
    }
}
