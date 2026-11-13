// FUN_0028eb3c
// Ghidra address: 0028eb3c

void FUN_0028eb3c(long *param_1)

{
  FUN_00286970();
  *param_1 = (long)(PTR_DAT_004022a0 + 0x10);
  *(undefined2 *)((long)param_1 + 0xc067c) = 0xffff;
  *(undefined8 *)((long)param_1 + 0xc067e) = 0;
  *(undefined4 *)((long)param_1 + 0xc0686) = 0;
  *(undefined4 *)((long)param_1 + 0xb084c) = 0;
  param_1[3] = 0;
  *(undefined4 *)(param_1 + 0x180cf) = 0x100000;
  return;
}

