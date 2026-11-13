// FUN_8078eda0
// Ghidra address: 8078eda0

int FUN_8078eda0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_80791388();
  iVar2 = FUN_80792820(uVar1);
  if (param_1 < iVar2 * -6 || 0x33 < param_1) {
    DAT_807c0368 = DAT_807c0368 | 8;
    param_1 = 0;
  }
  return param_1;
}

