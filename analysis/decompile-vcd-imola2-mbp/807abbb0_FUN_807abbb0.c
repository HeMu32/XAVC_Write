// FUN_807abbb0
// Ghidra address: 807abbb0

void FUN_807abbb0(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  uVar1 = FUN_8079408c(1);
  *(uint *)(iVar2 + 0x1cc) = *(uint *)(iVar2 + 0x1cc) & 0xfffffffe | uVar1 & 1;
  uVar1 = FUN_8079408c(8);
  *(uint *)(iVar2 + 0x1cc) = *(uint *)(iVar2 + 0x1cc) & 0xfffffe01 | (uVar1 & 0xff) << 1;
  uVar1 = FUN_8079408c(1);
  *(uint *)(iVar2 + 0x1cc) = *(uint *)(iVar2 + 0x1cc) & 0xfffffdff | (uVar1 & 1) << 9;
  FUN_8079408c(7);
  FUN_8079408c(1);
  uVar1 = FUN_8079408c(0x14);
  *(uint *)(iVar2 + 0x1cc) = *(uint *)(iVar2 + 0x1cc) & 0xc00003ff | (uVar1 & 0xfffff) << 10;
  FUN_8079408c(1);
  uVar1 = FUN_8079408c(0x16);
  *(uint *)(iVar2 + 0x1d0) = *(uint *)(iVar2 + 0x1d0) & 0xffc00000 | uVar1 & 0x3fffff;
  FUN_8079408c(1);
  uVar1 = FUN_8079408c(0x16);
  *(uint *)(iVar2 + 0x1d4) = *(uint *)(iVar2 + 0x1d4) & 0xffc00000 | uVar1 & 0x3fffff;
  return;
}

