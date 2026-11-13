// FUN_80799e78
// Ghidra address: 80799e78

void FUN_80799e78(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  DAT_807c0430 = DAT_807c0430 + 4;
  uVar8 = 0;
  uVar5 = FUN_8079408c(4);
  puVar3 = DAT_807c0b24;
  if (8 < uVar5) {
    uVar5 = 0;
  }
  DAT_807c0b24[2] = DAT_807c0b24[2] & 0xfffffff0 | uVar5 & 0xf;
  if (*(int *)(&DAT_807b598c + (uVar5 & 0xf) * 4) != 0) {
    iVar9 = 0;
    do {
      puVar7 = puVar3 + 3;
      uVar10 = *puVar7;
      uVar5 = DAT_807c0440 & 0x3f;
      uVar1 = DAT_807c0444 & 0x3f;
      uVar2 = DAT_807c0448 & 0x1f;
      *puVar7 = uVar10 & 0xfffffff9 | 2;
      DAT_807c0430 = DAT_807c0430 + 1;
      *puVar7 = uVar10 & 0xe0700201 | 2 | uVar5 << 0x17;
      puVar3[4] = puVar3[4] & 0xfffff800 | uVar1 | uVar2 << 6;
      puVar3[5] = 0;
      uVar5 = FUN_8079408c(1);
      *puVar7 = *puVar7 & 0xfffffffe | uVar5 & 1;
      if ((uVar5 & 1) != 0) {
        DAT_807c0430 = DAT_807c0430 + 2;
        uVar5 = FUN_8079408c(2);
        *puVar7 = *puVar7 & 0xfffffff9 | (uVar5 & 3) << 1;
        DAT_807c0430 = DAT_807c0430 + 1;
        uVar5 = FUN_8079408c(1);
        *puVar7 = *puVar7 & 0xfffffff7 | (uVar5 & 1) << 3;
        DAT_807c0430 = DAT_807c0430 + 5;
        uVar5 = FUN_8079408c(5);
        *puVar7 = *puVar7 & 0xfffffe0f | (uVar5 & 0x1f) << 4;
        DAT_807c0430 = DAT_807c0430 + 1;
        uVar5 = FUN_8079408c(1);
        *puVar7 = *puVar7 & 0xfffffdff | (uVar5 & 1) << 9;
        DAT_807c0430 = DAT_807c0430 + 1;
        uVar5 = FUN_8079408c(1);
        *puVar7 = *puVar7 & 0xfffffbff | (uVar5 & 1) << 10;
        DAT_807c0430 = DAT_807c0430 + 1;
        uVar5 = FUN_8079408c(1);
        *puVar7 = *puVar7 & 0xfffff7ff | (uVar5 & 1) << 0xb;
        DAT_807c0430 = DAT_807c0430 + 8;
        uVar5 = FUN_8079408c(8);
        puVar4 = DAT_807c0b24;
        *puVar7 = *puVar7 & 0xfff00fff | (uVar5 & 0xff) << 0xc;
        if (*(int *)((int)puVar4 + iVar9 + 0xc) << 0x16 < 0) {
          DAT_807c0430 = DAT_807c0430 + 6;
          uVar5 = FUN_8079408c(6);
          *puVar7 = *puVar7 & 0xe07fffff | (uVar5 & 0x3f) << 0x17;
          DAT_807c0430 = DAT_807c0430 + 6;
          uVar5 = FUN_8079408c(6);
          puVar3[4] = puVar3[4] & 0xffffffc0 | uVar5 & 0x3f;
LAB_8079a12c:
          DAT_807c0430 = DAT_807c0430 + 5;
          uVar5 = FUN_8079408c(5);
          puVar3[4] = puVar3[4] & 0xfffff83f | (uVar5 & 0x1f) << 6;
        }
        else {
          DAT_807c0430 = DAT_807c0430 + 1;
          uVar5 = FUN_8079408c(1);
          uVar5 = *puVar7 & 0xffefffff | (uVar5 & 1) << 0x14;
          *puVar7 = uVar5;
          if ((int)(uVar5 << 0xb) < 0) {
            DAT_807c0430 = DAT_807c0430 + 6;
            uVar5 = FUN_8079408c(6);
            *puVar7 = *puVar7 & 0xe07fffff | (uVar5 & 0x3f) << 0x17;
            DAT_807c0430 = DAT_807c0430 + 1;
            uVar5 = FUN_8079408c(1);
            uVar5 = *puVar7 & 0xffdfffff | (uVar5 & 1) << 0x15;
            *puVar7 = uVar5;
            if ((int)(uVar5 << 10) < 0) {
              DAT_807c0430 = DAT_807c0430 + 6;
              uVar5 = FUN_8079408c(6);
              puVar3[4] = puVar3[4] & 0xffffffc0 | uVar5 & 0x3f;
              DAT_807c0430 = DAT_807c0430 + 1;
              uVar5 = FUN_8079408c(1);
              uVar5 = *puVar7 & 0xffbfffff | (uVar5 & 1) << 0x16;
              *puVar7 = uVar5;
              if ((int)(uVar5 << 9) < 0) goto LAB_8079a12c;
            }
          }
        }
        iVar6 = FUN_80792780(param_1);
        if (iVar6 != 0) {
          DAT_807c0430 = DAT_807c0430 + iVar6;
          uVar5 = FUN_807944d8(iVar6);
          puVar3[5] = uVar5;
        }
      }
      uVar8 = uVar8 + 1;
      DAT_807c0440 = (*puVar7 & 0x1fffffff) >> 0x17;
      DAT_807c0448 = (puVar3[4] & 0x7ff) >> 6;
      DAT_807c0444 = puVar3[4] & 0x3f;
      iVar9 = iVar9 + 0xc;
      puVar3 = puVar7;
    } while (uVar8 < *(uint *)(&DAT_807b598c + (DAT_807c0b24[2] & 0xf) * 4));
  }
  return;
}

