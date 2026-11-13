// FUN_807914c0
// Ghidra address: 807914c0

int FUN_807914c0(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = FUN_80791388();
  iVar2 = FUN_8079220c(uVar1);
  uVar3 = FUN_80792230(uVar1);
  if ((*DAT_807c0a98 << 0xb < 0) || (iVar4 = FUN_80792614(uVar1), iVar4 != 0)) {
    uVar3 = uVar3 >> 1;
  }
  return iVar2 * uVar3;
}

