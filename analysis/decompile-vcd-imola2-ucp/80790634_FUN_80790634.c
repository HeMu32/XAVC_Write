// FUN_80790634
// Ghidra address: 80790634

void FUN_80790634(undefined1 param_1,int param_2,int param_3)

{
  uint *puVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  
  if (param_2 != 0) {
    iVar5 = 0;
    do {
      uVar7 = sony_ucp_read7(0x350);
      iVar5 = iVar5 + 1;
      if ((uVar7 & 1) != 0) goto LAB_80790688;
    } while (iVar5 != 0x30571);
    FUN_80747a30(0x350);
LAB_80790688:
    sony_ucp_write7(0x350,1);
    iVar5 = 0;
    do {
      uVar7 = sony_ucp_read7(0x360);
      iVar5 = iVar5 + 1;
      if ((uVar7 & 1) != 0) goto LAB_807906bc;
    } while (iVar5 != 0x30571);
    FUN_80747a30(0x360);
  }
LAB_807906bc:
  uVar4 = FUN_80794188();
  puVar6 = DAT_807c0a98;
  uVar7 = FUN_8078ea40(uVar4);
  *puVar6 = *puVar6 & 0xfff0ffff | (uVar7 & 0xf) << 0x10;
  iVar8 = 0;
  uVar9 = 0;
  uVar4 = FUN_80794188();
  puVar6 = DAT_807c0a98;
  uVar2 = FUN_8078ea68(uVar4,param_1);
  *(undefined1 *)((int)puVar6 + 3) = uVar2;
  uVar4 = FUN_80792a4c(*(undefined1 *)((int)DAT_807c0a98 + 3));
  puVar6 = DAT_807c0a98;
  uVar7 = FUN_8078f0a0(uVar4);
  *puVar6 = *puVar6 & 0xfffff07f | (uVar7 & 0x1f) << 7;
  DAT_807c03a4 = (*DAT_807c0a98 & 0xfff) >> 7;
  uVar7 = FUN_80792678(DAT_807c03a4);
  puVar6 = DAT_807c0a98;
  DAT_807c0aa0 = 1 << (uVar7 & 0x1f);
  uVar4 = FUN_80792678((*DAT_807c0a98 & 0xfff) >> 7);
  uVar3 = FUN_8079408c(uVar4);
  *(undefined2 *)(puVar6 + 2) = uVar3;
  iVar5 = FUN_807925f4((*DAT_807c0a98 & 0xfff) >> 7);
  if ((iVar5 == 0) && (iVar8 = FUN_8079408c(1), iVar8 != 0)) {
    uVar9 = FUN_8079408c(1);
  }
  puVar6 = DAT_807c0a98;
  uVar7 = FUN_8078eb00(iVar8,param_1);
  *puVar6 = *puVar6 & 0xffefffff | (uVar7 & 1) << 0x14;
  puVar6 = DAT_807c0a98;
  uVar7 = FUN_8078eb58(uVar9,param_1);
  puVar1 = DAT_807c0a98;
  *puVar6 = *puVar6 & 0xffdfffff | (uVar7 & 1) << 0x15;
  if ((int)(*puVar1 << 0xb) < 0) {
    DAT_807c0aa8 = (uint)(ushort)puVar1[2] * 2 + 1;
    DAT_807c0aa4 = DAT_807c0aa0 << 1;
  }
  else {
    DAT_807c0aa8 = (uint)(ushort)puVar1[2];
    DAT_807c0aa4 = DAT_807c0aa0;
  }
  if ((*puVar1 & 0x7f) >> 2 == 5) {
    uVar4 = FUN_80794188();
    puVar6 = DAT_807c0a98;
    uVar3 = FUN_8078ebb0(uVar4,param_1);
    *(undefined2 *)(puVar6 + 3) = uVar3;
    uVar7 = *DAT_807c0a98;
  }
  else {
    uVar7 = *puVar1;
  }
  iVar5 = FUN_8079269c((uVar7 & 0xfff) >> 7);
  puVar6 = DAT_807c0a98;
  if (iVar5 == 0) {
    uVar4 = FUN_807926bc((*DAT_807c0a98 & 0xfff) >> 7);
    uVar4 = FUN_8079408c(uVar4);
    puVar6 = DAT_807c0a98;
    uVar3 = FUN_8078ec18(uVar4,param_1);
    *(undefined2 *)((int)puVar6 + 0xe) = uVar3;
    iVar5 = FUN_807929a8(*(undefined1 *)((int)DAT_807c0a98 + 3));
    puVar6 = DAT_807c0a98;
    if (iVar5 != 0) {
      if ((int)(*DAT_807c0a98 << 0xb) < 0) {
        uVar7 = *DAT_807c0a98;
        goto LAB_80790804;
      }
      uVar4 = FUN_807941d8();
      puVar1 = DAT_807c0a98;
      uVar7 = FUN_8078ec74(uVar4,param_1);
      puVar6 = DAT_807c0a98;
      puVar1[4] = uVar7;
    }
  }
  uVar7 = *puVar6;
LAB_80790804:
  iVar5 = FUN_8079269c((uVar7 & 0xfff) >> 7);
  if ((iVar5 == 1) && (iVar5 = FUN_807926e0((*DAT_807c0a98 & 0xfff) >> 7), iVar5 == 0)) {
    uVar4 = FUN_807941d8();
    puVar6 = DAT_807c0a98;
    uVar7 = FUN_8078eccc(uVar4,param_1);
    puVar6[5] = uVar7;
    iVar5 = FUN_807929a8(*(undefined1 *)((int)DAT_807c0a98 + 3));
    if ((iVar5 != 0) && (-1 < (int)(*DAT_807c0a98 << 0xb))) {
      uVar4 = FUN_807941d8();
      puVar6 = DAT_807c0a98;
      uVar7 = FUN_8078ed24(uVar4,param_1);
      puVar6[6] = uVar7;
    }
  }
  if (param_3 != 0) {
    sony_ucp_write7(0x360,0);
  }
  return;
}

