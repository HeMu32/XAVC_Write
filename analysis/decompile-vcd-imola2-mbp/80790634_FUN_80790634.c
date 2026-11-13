// FUN_80790634
// Ghidra address: 80790634

/* WARNING: Control flow encountered bad instruction data */

void FUN_80790634(undefined1 param_1,int param_2,int param_3)

{
  uint *puVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  undefined4 uVar9;
  
  if (param_2 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar4 = FUN_80794188();
  puVar7 = DAT_807c0a98;
  uVar5 = FUN_8078ea40(uVar4);
  *puVar7 = *puVar7 & 0xfff0ffff | (uVar5 & 0xf) << 0x10;
  iVar8 = 0;
  uVar9 = 0;
  uVar4 = FUN_80794188();
  puVar7 = DAT_807c0a98;
  uVar2 = FUN_8078ea68(uVar4,param_1);
  *(undefined1 *)((int)puVar7 + 3) = uVar2;
  uVar4 = FUN_80792a4c(*(undefined1 *)((int)DAT_807c0a98 + 3));
  puVar7 = DAT_807c0a98;
  uVar5 = FUN_8078f0a0(uVar4);
  *puVar7 = *puVar7 & 0xfffff07f | (uVar5 & 0x1f) << 7;
  DAT_807c03a4 = (*DAT_807c0a98 & 0xfff) >> 7;
  uVar5 = FUN_80792678(DAT_807c03a4);
  puVar7 = DAT_807c0a98;
  DAT_807c0aa0 = 1 << (uVar5 & 0x1f);
  uVar4 = FUN_80792678((*DAT_807c0a98 & 0xfff) >> 7);
  uVar3 = FUN_8079408c(uVar4);
  *(undefined2 *)(puVar7 + 2) = uVar3;
  iVar6 = FUN_807925f4((*DAT_807c0a98 & 0xfff) >> 7);
  if ((iVar6 == 0) && (iVar8 = FUN_8079408c(1), iVar8 != 0)) {
    uVar9 = FUN_8079408c(1);
  }
  puVar7 = DAT_807c0a98;
  uVar5 = FUN_8078eb00(iVar8,param_1);
  *puVar7 = *puVar7 & 0xffefffff | (uVar5 & 1) << 0x14;
  puVar7 = DAT_807c0a98;
  uVar5 = FUN_8078eb58(uVar9,param_1);
  puVar1 = DAT_807c0a98;
  *puVar7 = *puVar7 & 0xffdfffff | (uVar5 & 1) << 0x15;
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
    puVar7 = DAT_807c0a98;
    uVar3 = FUN_8078ebb0(uVar4,param_1);
    *(undefined2 *)(puVar7 + 3) = uVar3;
    uVar5 = *DAT_807c0a98;
  }
  else {
    uVar5 = *puVar1;
  }
  iVar6 = FUN_8079269c((uVar5 & 0xfff) >> 7);
  puVar7 = DAT_807c0a98;
  if (iVar6 == 0) {
    uVar4 = FUN_807926bc((*DAT_807c0a98 & 0xfff) >> 7);
    uVar4 = FUN_8079408c(uVar4);
    puVar7 = DAT_807c0a98;
    uVar3 = FUN_8078ec18(uVar4,param_1);
    *(undefined2 *)((int)puVar7 + 0xe) = uVar3;
    iVar6 = FUN_807929a8(*(undefined1 *)((int)DAT_807c0a98 + 3));
    puVar7 = DAT_807c0a98;
    if (iVar6 != 0) {
      if ((int)(*DAT_807c0a98 << 0xb) < 0) {
        uVar5 = *DAT_807c0a98;
        goto LAB_80790804;
      }
      uVar4 = FUN_807941d8();
      puVar1 = DAT_807c0a98;
      uVar5 = FUN_8078ec74(uVar4,param_1);
      puVar7 = DAT_807c0a98;
      puVar1[4] = uVar5;
    }
  }
  uVar5 = *puVar7;
LAB_80790804:
  iVar6 = FUN_8079269c((uVar5 & 0xfff) >> 7);
  if ((iVar6 == 1) && (iVar6 = FUN_807926e0((*DAT_807c0a98 & 0xfff) >> 7), iVar6 == 0)) {
    uVar4 = FUN_807941d8();
    puVar7 = DAT_807c0a98;
    uVar5 = FUN_8078eccc(uVar4,param_1);
    puVar7[5] = uVar5;
    iVar6 = FUN_807929a8(*(undefined1 *)((int)DAT_807c0a98 + 3));
    if ((iVar6 != 0) && (-1 < (int)(*DAT_807c0a98 << 0xb))) {
      uVar4 = FUN_807941d8();
      puVar7 = DAT_807c0a98;
      uVar5 = FUN_8078ed24(uVar4,param_1);
      puVar7[6] = uVar5;
    }
  }
  if (param_3 == 0) {
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

