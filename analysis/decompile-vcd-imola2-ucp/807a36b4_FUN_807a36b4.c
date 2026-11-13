// FUN_807a36b4
// Ghidra address: 807a36b4

void FUN_807a36b4(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  undefined *local_20 [4];
  
  iVar3 = DAT_807c0500 * 0x18;
  puVar4 = &DAT_807b6848 + iVar3;
  DAT_807c0500 = (DAT_807c0500 + 1) % 5;
  uVar2 = FUN_8077fe84(*(undefined4 *)(param_1 + 4));
  *(undefined4 *)(&DAT_807b684c + iVar3) = uVar2;
  uVar2 = FUN_8077fe84(*(undefined4 *)(param_1 + 8));
  *(undefined4 *)(&DAT_807b6850 + iVar3) = uVar2;
  uVar2 = FUN_8077fe84(*(undefined4 *)(param_1 + 0xc));
  *(undefined4 *)(&DAT_807b6854 + iVar3) = uVar2;
  DAT_807c04dc = FUN_8077fe84(*(undefined4 *)(param_1 + 0x10));
  uVar2 = 0x807a3748;
  *(undefined4 *)(iVar3 + -0x7f8497a8) = DAT_807c04dc;
  FUN_807879a0(puVar4);
  uVar1 = (**(uint **)(&DAT_807b6854 + iVar3) & 0xff) >> 5;
  if ((uVar1 != 0 && uVar1 != 4) && (uVar1 != 1)) {
    FUN_80745808(&DAT_807c04fc,s_________________________src_ipsx_807b087c,0x37e,uVar2);
  }
  uVar2 = 0x807a379c;
  local_20[0] = puVar4;
  iVar3 = FUN_8079ec24(local_20,DAT_807c0b54);
  if (iVar3 == 0) {
    FUN_80745808(&DAT_807c04fc,s_________________________src_ipsx_807b087c,0x67,uVar2);
  }
  DAT_807c04e4 = DAT_807c04e4 + 1;
  uVar2 = 0x807a37d4;
  iVar3 = FUN_8079c854(4,0x8501,0xffffffff);
  if (iVar3 != 0) {
    FUN_80745808(&DAT_807c04fc,s_________________________src_ipsx_807b087c,0x399,uVar2);
  }
  uVar2 = 0x807a3800;
  iVar3 = FUN_8079c854(4,puVar4,0xffffffff);
  if (iVar3 != 0) {
    FUN_80745808(&DAT_807c04fc,s_________________________src_ipsx_807b087c,0x39c,uVar2);
  }
  return;
}

