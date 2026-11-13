// Decompile functions whose name contains the given pattern.
// Usage: -postScript DecompileFunc.java <pattern> <outDir>
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;
import java.io.FileWriter;
import java.io.PrintWriter;

public class DecompileFunc extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String pattern = args.length > 0 ? args[0] : "cmd_start";
        String outDir = args.length > 1 ? args[1] : ".";

        DecompInterface ifc = new DecompInterface();
        ifc.toggleCCode(true);
        ifc.toggleSyntaxTree(true);
        ifc.openProgram(currentProgram);

        SymbolIterator it = currentProgram.getSymbolTable().getAllSymbols(true);
        int written = 0;

        // 支持 0xADDR 形式：直接反编译该地址所在函数
        if (pattern.startsWith("0x")) {
            ghidra.program.model.address.Address a =
                currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(
                    Long.parseLong(pattern.substring(2), 16));
            Function f = getFunctionAt(a);
            if (f == null) f = getFunctionContaining(a);
            if (f == null) { println("no function at " + pattern); return; }
            DecompileResults res = ifc.decompileFunction(f, 120, monitor);
            if (res.decompileCompleted()) {
                String c = res.getDecompiledFunction().getC();
                try (PrintWriter w = new PrintWriter(new FileWriter(
                        outDir + "/" + f.getName() + "_" + f.getEntryPoint() + ".c"))) {
                    w.println("// function: " + f.getName());
                    w.println("// entry: " + f.getEntryPoint());
                    w.println(c);
                }
                println("wrote " + f.getName() + " @ " + f.getEntryPoint());
            }
            ifc.dispose();
            return;
        }

        while (it.hasNext()) {
            Symbol s = it.next();
            String name = s.getName();
            if (name == null || !name.contains(pattern)) continue;
            if (s.isExternal()) continue;
            Function f = getFunctionAt(s.getAddress());
            if (f == null) f = getFunctionContaining(s.getAddress());
            if (f == null) continue;
            DecompileResults res = ifc.decompileFunction(f, 120, monitor);
            if (!res.decompileCompleted()) {
                println("decompile failed: " + f.getName());
                continue;
            }
            String c = res.getDecompiledFunction().getC();
            String safe = f.getName().replaceAll("[^A-Za-z0-9_.-]", "_")
                    + "_" + f.getEntryPoint().toString();
            try (PrintWriter w = new PrintWriter(new FileWriter(outDir + "/" + safe + ".c"))) {
                w.println("// function: " + f.getName());
                w.println("// entry: " + f.getEntryPoint());
                w.println("// signature: " + f.getSignature());
                w.println(c);
            }
            println("wrote " + f.getName() + " @ " + f.getEntryPoint());
            written++;
        }
        println("total functions written: " + written);
        ifc.dispose();
    }
}
