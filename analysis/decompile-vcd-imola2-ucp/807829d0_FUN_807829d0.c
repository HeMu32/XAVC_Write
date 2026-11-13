// FUN_807829d0
// Ghidra address: 807829d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_807829d0(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  
  while( true ) {
    iVar1 = FUN_8079ec78(DAT_807c0b98[10]);
    if (iVar1 != 0) {
      return;
    }
    piVar2 = (int *)FUN_8079ec5c(DAT_807c0b98[10]);
    iVar1 = *piVar2;
    uVar4 = *(uint *)(iVar1 + 4);
    uVar5 = (uVar4 & 0x7ff) >> 8;
    if (((uVar5 == 1) && (_DAT_807c011c == 0)) || ((uVar5 == 2 && (_DAT_807c011c == 1)))) {
      iVar3 = FUN_80786788();
      uVar6 = 0x80782b10;
      iVar3 = FUN_8079c854(3,(*(uint *)(iVar3 + 4) & 7) << 0xc | 0x585,0xffffffff);
      if (iVar3 != 0) {
        FUN_80745808(&DAT_807c0160,s_________________________src_ipsx_807af878,0x482,uVar6);
      }
      FUN_807867a8();
      uVar4 = *(uint *)(iVar1 + 4);
    }
    if (((uVar4 & 0x7ff) >> 8) - 1 < 2) {
      _DAT_807c011c = 0;
      DAT_807c0b98 = &DAT_807c1390;
    }
    piVar2 = (int *)FUN_8079ec5c(DAT_807c0b98[10]);
    uVar5 = *(uint *)(*piVar2 + 4);
    iVar1 = FUN_8079ec40(DAT_807c0b98[10]);
    if (iVar1 == 0) break;
    FUN_807852fc((uVar5 & 0xfff) >> 0xb);
  }
  uVar6 = 0x80782ad8;
  FUN_807a0894(s__s_FALSE__807c016c,s_popSlicePrmCmdQue_807af8c8);
  FUN_80745808(&DAT_807c0160,s_________________________src_ipsx_807af878,0x67c,uVar6);
  return;
}

