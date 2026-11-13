// FUN_80786714
// Ghidra address: 80786714

int FUN_80786714(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_8079c590((int)DAT_807c0218,100);
  iVar2 = 0;
  if (iVar1 == -0x32) {
    *param_1 = 1;
  }
  else {
    iVar2 = DAT_807c021c * 0x7c0 + -0x7f832f98;
    DAT_807c021c = DAT_807c021c + 1 & 3;
  }
  return iVar2;
}

