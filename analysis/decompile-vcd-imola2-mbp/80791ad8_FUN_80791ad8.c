// FUN_80791ad8
// Ghidra address: 80791ad8

void FUN_80791ad8(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined1 uVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  uint uVar15;
  
  uVar15 = 0;
  uVar3 = FUN_80791388();
  iVar4 = FUN_80792800(uVar3);
  uVar1 = DAT_807c0aac & 0x1f;
  uVar2 = DAT_807c0ab0 & 0x1f;
  if (-1 < param_2) {
    iVar9 = param_1 * 0x20;
    puVar14 = &DAT_80833b98 + iVar9;
    puVar13 = &DAT_80833b58 + iVar9;
    puVar12 = &DAT_80833b18 + iVar9;
    puVar11 = &DAT_80833ad8 + iVar9;
    puVar10 = &DAT_80833a98 + iVar9;
    do {
      uVar5 = FUN_8079408c(1);
      (&DAT_807c0ab8)[param_1] = (&DAT_807c0ab8)[param_1] | (uVar5 & 1) << (uVar15 & 0x1f);
      if ((uVar5 & 0xff) == 0) {
        (&DAT_80833a98)[iVar9] = (char)(1 << uVar1);
        (&DAT_80833ad8)[iVar9] = 0;
      }
      else {
        iVar6 = FUN_807941d8();
        iVar7 = FUN_807941d8();
        if (0xff < iVar6 + 0x80U) {
          iVar6 = 0;
        }
        *puVar10 = (char)iVar6;
        uVar8 = (undefined1)iVar7;
        if (0xff < iVar7 + 0x80U) {
          uVar8 = 0;
        }
        *puVar11 = uVar8;
      }
      if (iVar4 != 0) {
        uVar5 = FUN_8079408c(1);
        (&DAT_807c0ac0)[param_1] = (&DAT_807c0ac0)[param_1] | (uVar5 & 1) << (uVar15 & 0x1f);
        if ((uVar5 & 0xff) == 0) {
          uVar8 = (undefined1)(1 << uVar2);
          (&DAT_80833b98)[iVar9] = uVar8;
          (&DAT_80833bd8)[iVar9] = 0;
          (&DAT_80833b18)[iVar9] = uVar8;
          (&DAT_80833b58)[iVar9] = 0;
        }
        else {
          iVar6 = FUN_807941d8();
          iVar7 = FUN_807941d8();
          if (0xff < iVar6 + 0x80U) {
            iVar6 = 0;
          }
          *puVar12 = (char)iVar6;
          if (0xff < iVar7 + 0x80U) {
            iVar7 = 0;
          }
          *puVar13 = (char)iVar7;
          iVar6 = FUN_807941d8();
          iVar7 = FUN_807941d8();
          if (0xff < iVar6 + 0x80U) {
            iVar6 = 0;
          }
          *puVar14 = (char)iVar6;
          uVar8 = (undefined1)iVar7;
          if (0xff < iVar7 + 0x80U) {
            uVar8 = 0;
          }
          (&DAT_80833bd8)[iVar9] = uVar8;
        }
      }
      uVar15 = uVar15 + 1;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
      puVar13 = puVar13 + 1;
      puVar14 = puVar14 + 1;
      iVar9 = iVar9 + 1;
    } while ((int)uVar15 <= param_2);
  }
  return;
}

