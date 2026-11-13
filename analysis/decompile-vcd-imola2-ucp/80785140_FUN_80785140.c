// FUN_80785140
// Ghidra address: 80785140

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80785140(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  short local_20 [8];
  
  iVar1 = FUN_8079ec78(DAT_807c0a40);
  if (iVar1 != 0) {
    return 0;
  }
  uVar7 = 0x80785184;
  piVar2 = (int *)FUN_8079ec5c(DAT_807c0a40);
  iVar1 = DAT_807c01cc;
  iVar6 = *piVar2;
  uVar5 = (*(uint *)(iVar6 + 4) & 0x7ff) >> 8;
  if (uVar5 == 0) {
    piVar2 = (int *)FUN_8079ec5c(DAT_807c0a40);
    if ((*(int *)(*piVar2 + 4) << 0x13 < 0) && (DAT_807c01d4 < _DAT_807c01d8)) {
      return 2;
    }
    FUN_80785f9c(iVar6);
    return 1;
  }
  if (1 < uVar5 - 1) {
    FUN_80745808(&DAT_807c020c,s_________________________src_ipsx_807af9a8,0x28c,uVar7);
    return DAT_807c01c8;
  }
  uVar7 = 0x807851bc;
  iVar3 = FUN_8079ec40((&DAT_807c0a3c)[DAT_807c01cc]);
  if (iVar3 == 0) {
    uVar4 = 0x1cd;
  }
  else {
    local_20[0] = 5;
    if (iVar1 != 0) {
      FUN_80745808(&DAT_807c020c,s_________________________src_ipsx_807af9a8,0x1be,uVar7);
    }
    uVar7 = 0x807851e4;
    iVar1 = FUN_8079c854((int)local_20[iVar1],0x850c,0xffffffff);
    if (iVar1 == 0) {
      uVar5 = *(uint *)(iVar6 + 4);
      goto LAB_807851f0;
    }
    uVar4 = 0x1c2;
  }
  FUN_80745808(&DAT_807c020c,s_________________________src_ipsx_807af9a8,uVar4,uVar7);
  uVar5 = *(uint *)(iVar6 + 4);
LAB_807851f0:
  if ((uVar5 & 0x7ff) >> 8 == 1) {
    DAT_807c01dc = 1;
  }
  DAT_807c0a40 = DAT_807c0a3c;
  DAT_807c01cc = 0;
  DAT_807c01d0 = 0;
  uVar7 = FUN_80785140();
  return uVar7;
}

