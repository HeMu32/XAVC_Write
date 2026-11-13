/*
 * Purpose: recover the bounded imola2 dispatch function and known consumers.
 * Usage: run RecoverVcdDispatch.java as a Ghidra script/post-script on the
 *        matching prepared flat imola2 program; no script arguments.
 * Design: verify measured instruction words before disassembling/creating the
 *         dispatch entry and two relocated consumer functions.
 * Scope: fixed original bytes/addresses only. Changes analysis functions, not
 *        firmware bytes; does not establish complete dispatch or hardware semantics.
 */
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class RecoverVcdDispatch extends GhidraScript {
    public void run() throws Exception {
        long entry = 0x80798344L;
        if (Integer.toUnsignedLong(getInt(toAddr(entry))) != 0x27bdff50L ||
            Integer.toUnsignedLong(getInt(toAddr(0x80798534L))) != 0x0c1e619eL ||
            Integer.toUnsignedLong(getInt(toAddr(0x807985b0L))) != 0x0c1e4837L) {
            throw new Exception("Unexpected imola2 dispatch bytes");
        }
        Address address = toAddr(entry);
        disassemble(address);
        Function f = getFunctionAt(address);
        if (f == null) f = createFunction(address, null);
        if (f == null) throw new Exception("Could not recover bounded dispatch function");
        println("RECOVERED_DISPATCH " + f.getEntryPoint() + " " + f.getBody());
        for (long delta : new long[] {0, 0x1ab000L}) {
            Address caller = toAddr(0x807a6764L + delta);
            if (Integer.toUnsignedLong(getInt(caller)) != 0x27bdffa0L) {
                throw new Exception("Unexpected dispatch consumer prologue");
            }
            disassemble(caller);
            Function consumer = getFunctionAt(caller);
            if (consumer == null) consumer = createFunction(caller, null);
            if (consumer == null) throw new Exception("Could not recover dispatch consumer");
            println("RECOVERED_DISPATCH_CONSUMER " + consumer.getEntryPoint() +
                " " + consumer.getBody());
        }
    }
}
