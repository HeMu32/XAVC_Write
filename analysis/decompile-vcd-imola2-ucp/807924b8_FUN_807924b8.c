// FUN_807924b8
// Ghidra address: 807924b8

void FUN_807924b8(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  
  if ((param_2 & 3) != 0) {
    FUN_80745808(&DAT_807c03b0,s_________________________src_ipsx_807afd94,0xcd);
  }
  uVar1 = 0;
  if (param_2 >> 2 != 0) {
    do {
      uVar1 = uVar1 + 1;
      *param_1 = 0;
      param_1 = param_1 + 1;
    } while (uVar1 < param_2 >> 2);
  }
  return;
}

