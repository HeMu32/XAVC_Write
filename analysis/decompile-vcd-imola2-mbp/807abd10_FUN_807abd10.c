// FUN_807abd10
// Ghidra address: 807abd10

void FUN_807abd10(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  uVar1 = FUN_8079408c(2);
  *(uint *)(iVar2 + 0x1e0) = *(uint *)(iVar2 + 0x1e0) & 0xfffffffc | uVar1 & 3;
  uVar1 = FUN_8079408c(10);
  *(uint *)(iVar2 + 0x1e0) = *(uint *)(iVar2 + 0x1e0) & 0xfffff003 | (uVar1 & 0x3ff) << 2;
  FUN_8079408c(1);
  uVar1 = FUN_8079408c(10);
  *(uint *)(iVar2 + 0x1e0) = *(uint *)(iVar2 + 0x1e0) & 0xffc00fff | (uVar1 & 0x3ff) << 0xc;
  return;
}

