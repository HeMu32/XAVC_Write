// Ghidra: 00282c5c; ELF VMA = Ghidra - 0x100000

void FUN_00282c5c(long *param_1)

{
  if ((long *)param_1[1] != (long *)0x0) {
    (**(code **)(*(long *)param_1[1] + 8))();
    param_1[1] = 0;
  }
  if ((long *)param_1[2] != (long *)0x0) {
    (**(code **)(*(long *)param_1[2] + 8))();
    param_1[2] = 0;
  }
  (**(code **)(*param_1 + 0x3d8))(param_1);
                    /* WARNING: Could not recover jumptable at 0x00282cc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xd0))(param_1);
  return;
}

