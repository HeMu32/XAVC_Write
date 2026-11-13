// Ghidra: 00286970; ELF VMA = Ghidra - 0x100000

void FUN_00286970(long *param_1)

{
  undefined8 *puVar1;
  
  FUN_00282b84();
  *param_1 = (long)(PTR_DAT_00402870 + 0x10);
  param_1[0x180ce] = 0;
  *(undefined4 *)(param_1 + 0x180cf) = 0x200000;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  *(undefined4 *)(param_1 + 0x180cd) = 0;
  puVar1 = operator_new(0x10);
  *puVar1 = param_1;
  param_1[0x180ce] = (long)puVar1;
  *(undefined1 *)(puVar1 + 1) = 0;
  *(undefined1 *)((long)puVar1 + 9) = 0;
  FUN_00286448(param_1);
  return;
}

