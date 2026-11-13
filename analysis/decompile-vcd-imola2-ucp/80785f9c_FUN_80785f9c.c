// FUN_80785f9c
// Ghidra address: 80785f9c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80785f9c(ushort *param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  short local_30 [8];
  
  if (*(int *)(param_1 + 2) << 0x13 < 0) {
    iVar2 = FUN_80786788();
    DAT_807c01e4 = (uint)*param_1;
    DAT_807c01e8 = (uint)param_1[1];
    DAT_807c01e0 = *(uint *)(param_1 + 2) & 0xf;
    iVar1 = 2;
    DAT_807c01d4 = DAT_807c01d4 - _DAT_807c01d8;
    if ((*(uint *)(iVar2 + 0x18) & 1) == 0) {
      iVar1 = 1;
    }
    DAT_807c01ec = 0;
    _DAT_807c01d8 = iVar1;
    iVar1 = FUN_8079ec78(DAT_807c0a44);
    if ((iVar1 == 0) && (_DAT_807c01d8 == 2)) {
      uVar6 = 0x80786270;
      iVar1 = FUN_8079ec78(DAT_807c0a44);
      if (iVar1 != 0) {
        FUN_80745808(&DAT_807c020c,s_________________________src_ipsx_807af9a8,0x1e6,uVar6);
      }
      uVar6 = 0x80786284;
      puVar3 = (uint *)FUN_8079ec5c(DAT_807c0a44);
      if ((DAT_807c01e0 == (*puVar3 & 0xffffff) >> 0x10) && (DAT_807c01e8 == (*puVar3 & 0xffff))) {
        FUN_80788928(0x9001,DAT_807c01e0 & 0xffff);
        DAT_807c01d4 = DAT_807c01d4 + 1;
        FUN_8079ec40(DAT_807c0a44);
      }
      else {
        FUN_80745808(&DAT_807c020c,s_________________________src_ipsx_807af9a8,0x20c,uVar6);
      }
    }
    iVar1 = FUN_80747da8();
    if (((iVar1 != 0) && (iVar1 = FUN_80747db0(), iVar1 == 0)) &&
       (iVar1 = FUN_8079c590(6,0xffffffff), iVar1 != 0)) {
      uVar6 = 0x80786240;
      FUN_807a0894(&DAT_807c0210,iVar1);
      FUN_80745808(&DAT_807c020c,s_________________________src_ipsx_807af9a8,0x217,uVar6);
    }
    FUN_807886dc((undefined2)DAT_807c01c8,
                 (uint)CONCAT12((undefined1)DAT_807c01e0,(undefined2)DAT_807c01e4));
    FUN_80786be8(*(undefined2 *)(iVar2 + 0xc),2);
    (*(code *)(&PTR_LAB_807c01f4)[DAT_807c01f0])();
    iVar1 = FUN_80788c90();
    if (iVar1 != 0) {
      FUN_8079c590(5,0xffffffff);
    }
    FUN_807897f8(iVar2,param_1);
    iVar1 = FUN_807873f0((*(uint *)(param_1 + 2) & 0xff) >> 4);
    (*(code *)(&PTR_LAB_807b551c)[iVar1])(iVar2,param_1);
    iVar1 = FUN_807873f0((*(uint *)(param_1 + 2) & 0xff) >> 4);
    (*(code *)(&PTR_FUN_807b54f4)[iVar1])(iVar2);
  }
  if (DAT_807c01d0 == 0) {
    DAT_807c01d0 = 1;
    uVar5 = *(uint *)(param_1 + 2);
  }
  else {
    uVar5 = *(uint *)(param_1 + 2);
  }
  iVar1 = FUN_807873f0((uVar5 & 0xff) >> 4);
  (*(code *)(&PTR_LAB_807b5508)[iVar1])(param_1);
  iVar1 = DAT_807c01cc;
  uVar6 = 0x8078601c;
  iVar2 = FUN_8079ec40((&DAT_807c0a3c)[DAT_807c01cc]);
  if (iVar2 == 0) {
    uVar4 = 0x1cd;
  }
  else {
    local_30[0] = 5;
    if (iVar1 != 0) {
      FUN_80745808(&DAT_807c020c,s_________________________src_ipsx_807af9a8,0x1be,uVar6);
    }
    uVar6 = 0x80786044;
    iVar1 = FUN_8079c854((int)local_30[iVar1],0x850c,0xffffffff);
    if (iVar1 == 0) {
      return;
    }
    uVar4 = 0x1c2;
  }
  FUN_80745808(&DAT_807c020c,s_________________________src_ipsx_807af9a8,uVar4,uVar6);
  return;
}

