// FUN_00352de0
// Ghidra address: 00352de0

void FUN_00352de0(long *param_1)

{
  undefined *puVar1;
  void *pvVar2;
  
  param_1[3] = 0;
  param_1[4] = 0;
  puVar1 = PTR_DAT_00401aa8;
  param_1[5] = 0;
  *param_1 = (long)(puVar1 + 0x10);
  *(undefined1 *)(param_1 + 2) = 1;
  pvVar2 = operator_new(0x10);
  FUN_0033abac();
  param_1[1] = (long)pvVar2;
  return;
}

