// Ghidra: 0028bbec; ELF VMA = Ghidra - 0x100000

void FUN_0028bbec(long *param_1,long param_2,undefined4 param_3)

{
  undefined *puVar1;
  
  *(undefined4 *)(param_1 + 2) = param_3;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  puVar1 = PTR_DAT_00401b98;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  *param_1 = (long)(puVar1 + 0x10);
  param_1[1] = param_2;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  *(undefined4 *)(param_1 + 0xe) = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  return;
}

