// FUN_00352bb4
// Ghidra address: 00352bb4

void FUN_00352bb4(long *param_1)

{
  *param_1 = (long)(PTR_DAT_00401aa8 + 0x10);
  if ((long *)param_1[1] != (long *)0x0) {
    (**(code **)(*(long *)param_1[1] + 8))();
  }
  if ((void *)param_1[3] != (void *)0x0) {
    operator_delete((void *)param_1[3]);
    return;
  }
  return;
}

