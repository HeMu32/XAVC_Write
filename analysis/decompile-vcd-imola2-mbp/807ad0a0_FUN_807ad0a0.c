// FUN_807ad0a0
// Ghidra address: 807ad0a0

void FUN_807ad0a0(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  uVar1 = FUN_8079408c(0x19);
  *(uint *)(iVar2 + 0xa8) = *(uint *)(iVar2 + 0xa8) & 0xfe000000 | uVar1 & 0x1ffffff;
  uVar1 = FUN_8079408c(1);
  *(uint *)(iVar2 + 0xa8) = *(uint *)(iVar2 + 0xa8) & 0xfdffffff | (uVar1 & 1) << 0x19;
  uVar1 = FUN_8079408c(1);
  *(uint *)(iVar2 + 0xa8) = *(uint *)(iVar2 + 0xa8) & 0xfbffffff | (uVar1 & 1) << 0x1a;
  FUN_80787c8c(iVar2 + 0xa8);
  return;
}

