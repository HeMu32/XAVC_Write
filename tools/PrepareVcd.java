/*
 * Purpose: prepare known raw VCD firmware mappings for Ghidra analysis.
 * Usage: select/import the matching flat MIPS image, then run PrepareVcd.java
 *        as a Ghidra pre-script; tools/run_ghidra.py accepts --pre-script.
 * Design: recognize version strings, set per-core GP context and recover
 *         measured startup/main entries in the provisional flat mapping.
 * Scope: the two identified builds only. Modifies the analysis program's
 *        context/functions, not the source image; does not emulate hardware.
 */
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.lang.Register;
import java.math.BigInteger;

public class PrepareVcd extends GhidraScript {
    public void run() throws Exception {
        Address version = toAddr(0x80000010L);
        byte[] bytes = getBytes(version, 32);
        String build = new String(bytes, java.nio.charset.StandardCharsets.US_ASCII).split("\0", 2)[0];
        long start, end, gpValue, main;
        if (build.equals("SW_VER_13_11_10_0")) {
            start = 0x80004300L;
            end = 0x802ed243L;
            gpValue = 0x802f32a0L;
            main = 0x800f2c58L;
        } else if (build.equals("SW_VER_46_21_02_0______________")) {
            // Corroborated by imola2's own +0x9300 startup and BSS clear loop.
            start = 0x80009300L;
            end = 0x80248e07L;
            gpValue = 0x8024eb58L;
            main = 0x8005c34cL;
        } else {
            throw new Exception("Unexpected VCD build: " + build);
        }
        Register gp = currentProgram.getRegister("gp");
        currentProgram.getProgramContext().setValue(gp, toAddr(start),
            toAddr(end), BigInteger.valueOf(gpValue));
        for (long entry : new long[] {start, main}) {
            Address address = toAddr(entry);
            disassemble(address);
            createFunction(address, null);
            addEntryPoint(address);
        }
        if (build.equals("SW_VER_46_21_02_0______________")) {
            // Each MBP startup supplies its own GP and BSS boundary.
            long[][] cores = {
                {0x80714300L, 0x807c0627L, 0x807bf0e0L, 0x8079da80L},
                {0x808bf300L, 0x8096b627L, 0x8096a0e0L, 0x80948a80L}
            };
            for (long[] core : cores) {
                currentProgram.getProgramContext().setValue(gp, toAddr(core[0]),
                    toAddr(core[1]), BigInteger.valueOf(core[2]));
                for (long entry : new long[] {core[0], core[3]}) {
                    Address address = toAddr(entry);
                    disassemble(address);
                    createFunction(address, null);
                    addEntryPoint(address);
                }
                println("MBP entry " + Long.toHexString(core[0]) +
                    "; GP " + Long.toHexString(core[2]) +
                    "; initialized range end " + Long.toHexString(core[1]));
            }
        }
        println("VCD provisional flat mapping: 0x80000000 + file offset; " + build +
            "; main GP " + Long.toHexString(gpValue));
    }
}
