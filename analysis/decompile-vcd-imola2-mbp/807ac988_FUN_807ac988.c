// FUN_807ac988
// Ghidra address: 807ac988

void FUN_807ac988(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 8);
  uVar1 = FUN_8079408c(8);
  *(undefined1 *)(iVar3 + 0x8c) = uVar1;
  uVar2 = FUN_8079408c(1);
  *(uint *)(iVar3 + 0x8c) = *(uint *)(iVar3 + 0x8c) & 0xfffffeff | (uVar2 & 1) << 8;
  uVar2 = FUN_8079408c(2);
  *(uint *)(iVar3 + 0x8c) = *(uint *)(iVar3 + 0x8c) & 0xfffff9ff | (uVar2 & 3) << 9;
  uVar2 = FUN_8079408c(2);
  *(uint *)(iVar3 + 0x8c) = *(uint *)(iVar3 + 0x8c) & 0xffffe7ff | (uVar2 & 3) << 0xb;
  uVar2 = FUN_8079408c(2);
  *(uint *)(iVar3 + 0x8c) = *(uint *)(iVar3 + 0x8c) & 0xffff9fff | (uVar2 & 3) << 0xd;
  uVar2 = FUN_8079408c(0xc);
  *(uint *)(iVar3 + 0x8c) = *(uint *)(iVar3 + 0x8c) & 0xf8007fff | (uVar2 & 0xfff) << 0xf;
  FUN_8079408c(1);
  uVar1 = FUN_8079408c(8);
  *(undefined1 *)(iVar3 + 0x90) = uVar1;
  uVar2 = FUN_8079408c(1);
  *(uint *)(iVar3 + 0x90) = *(uint *)(iVar3 + 0x90) & 0xfffffeff | (uVar2 & 1) << 8;
  uVar2 = FUN_8079408c(2);
  *(uint *)(iVar3 + 0x90) = *(uint *)(iVar3 + 0x90) & 0xfffff9ff | (uVar2 & 3) << 9;
  uVar2 = FUN_8079408c(5);
  *(uint *)(iVar3 + 0x90) = *(uint *)(iVar3 + 0x90) & 0xffff07ff | (uVar2 & 0x1f) << 0xb;
  FUN_80787ea8(iVar3 + 0x8c);
  return;
}

