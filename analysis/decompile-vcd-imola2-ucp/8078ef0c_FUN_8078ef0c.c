// FUN_8078ef0c
// Ghidra address: 8078ef0c

int FUN_8078ef0c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_80791388();
  iVar2 = FUN_80792820(uVar1);
  if (param_1 < -(iVar2 * 6 + 0x1a) || 0x19 < param_1) {
    DAT_807c0368 = DAT_807c0368 | 0x40000;
    param_1 = 0;
  }
  return param_1;
}

