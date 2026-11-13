/*
 * Purpose: validate selected opaque-UCP instruction models in Ghidra.
 * Usage: load the identified image with MIPS:LE:32:sony-ucp-opaque, then run
 *        ValidateUcp.java; report: analysis/ucp-instruction-check.json.
 * Design: check four original words, expected mnemonics and CALLOTHER P-code
 *         selector/read-write shape against the separate analysis-only language.
 * Scope: syntax/P-code model validation, not emulation or proof of exact Sony
 *        custom-instruction hardware semantics. Does not modify source firmware.
 */
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.pcode.PcodeOp;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import com.google.gson.GsonBuilder;

public class ValidateUcp extends GhidraScript {
    public void run() throws Exception {
        if (!currentProgram.getLanguageID().toString().equals("MIPS:LE:32:sony-ucp-opaque")) {
            throw new Exception("Expected the analysis-only Sony language");
        }
        long[][] tests = {
            {0x807940b0L, 0x68e60360L, 0x360L, 1},
            {0x807940d0L, 0xb0f00360L, 0x360L, 0},
            {0x80794100L, 0x68e40362L, 0x362L, 1},
            {0x8079410cL, 0xb0e00361L, 0x361L, 0}
        };
        ArrayList<Object> rows = new ArrayList<>();
        for (long[] test : tests) {
            if (Integer.toUnsignedLong(getInt(toAddr(test[0]))) != test[1]) {
                throw new Exception("Raw bytes mismatch at " + Long.toHexString(test[0]));
            }
            Instruction ins = getInstructionAt(toAddr(test[0]));
            if (ins == null) throw new Exception("Instruction not recovered");
            String mnemonic = test[3] == 1 ? "ucp_read7" : "ucp_write7";
            if (!ins.getMnemonicString().equals(mnemonic)) {
                throw new Exception("Wrong instruction model at " + ins.getAddress());
            }
            boolean found = false;
            ArrayList<String> pcode = new ArrayList<>();
            for (PcodeOp op : ins.getPcode()) {
                pcode.add(op.toString());
                if (op.getOpcode() == PcodeOp.CALLOTHER &&
                    op.getInput(1).isConstant() && op.getInput(1).getOffset() == test[2]) {
                    found = true;
                    if ((op.getOutput() != null) != (test[3] == 1)) {
                        throw new Exception("Read/write output model mismatch");
                    }
                }
            }
            if (!found) throw new Exception("Missing opaque operation");
            LinkedHashMap<String, Object> row = new LinkedHashMap<>();
            row.put("address", ins.getAddress().toString());
            row.put("raw_word", Long.toHexString(test[1]));
            row.put("instruction", ins.toString());
            row.put("pcode", pcode);
            rows.add(row);
        }
        LinkedHashMap<String, Object> report = new LinkedHashMap<>();
        report.put("language", currentProgram.getLanguageID().toString());
        report.put("passed", true);
        report.put("exact_hardware_semantics_proven", false);
        report.put("checks", rows);
        Path root = Path.of(getSourceFile().getAbsolutePath()).getParent().getParent();
        Path output = root.resolve("analysis/ucp-instruction-check.json");
        Files.writeString(output, new GsonBuilder().setPrettyPrinting().create().toJson(report));
        println("UCP model decode/pcode checks passed: " + output);
    }
}
