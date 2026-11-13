// FUN_8078fe54
// Ghidra address: 8078fe54

void FUN_8078fe54(int param_1)

{
  byte bVar1;
  bool bVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  short sVar13;
  uint uVar14;
  uint *puVar15;
  uint *puVar16;
  undefined1 *puVar17;
  undefined4 *puVar18;
  uint *puVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint local_38;
  
  puVar3 = DAT_807c0a8c;
  puVar16 = *(uint **)(param_1 + 0x8c);
  puVar19 = *(uint **)(param_1 + 0x90);
  uVar14 = *(uint *)(DAT_807c0a8c + 0xc);
  *DAT_807c0a8c = (short)puVar16[2];
  puVar3[1] = (short)puVar19[1];
  *(uint *)(puVar3 + 2) = *puVar16 & 7;
  uVar22 = *puVar16;
  puVar3[5] = (ushort)((uVar22 << 0x13) >> 0x1f);
  uVar9 = puVar19[3];
  *(uint *)(puVar3 + 8) = (uVar22 & 0xfff) >> 8;
  puVar3[6] = (short)uVar9;
  *(uint *)(puVar3 + 0xc) = uVar14 & 0xfffffffe | (*puVar19 & 0xff) >> 7;
  uVar5 = FUN_80791388();
  uVar6 = FUN_80791698();
  DAT_807c0a74 = FUN_8079220c(uVar5);
  iVar7 = FUN_807925f4(uVar5);
  iVar8 = FUN_80792634(uVar5);
  uVar9 = FUN_807915dc();
  uVar14 = DAT_807c0a74;
  DAT_807c0a78 = (uint)((2 - iVar7) * iVar8) >> (uVar9 & 0x1f);
  uVar9 = DAT_807c0a74 * DAT_807c0a78;
  uVar20 = DAT_807c0a74 & 0x3ff;
  DAT_807c0388 = DAT_807c0a74 < 0x2e;
  DAT_807c0a88 = uVar9 & 0x7ffff;
  DAT_807c0a7c = uVar9;
  *(uint *)(DAT_807c0a8c + 0xe) = uVar20 | (DAT_807c0a78 & 0x3ff) << 0x10;
  uVar22 = FUN_80792614(uVar5);
  uVar10 = FUN_807915dc();
  DAT_807c0a70 = uVar22 & ~uVar10 & 1;
  iVar7 = *(int *)(param_1 + 0x114) >> 0xc;
  uVar22 = *(uint *)(param_1 + 0x110) >> 0xc;
  if (iVar7 == -1) {
    if (uVar14 == 0) {
      trap(7);
    }
    local_38 = DAT_807c0a88 - (uVar22 << DAT_807c0a70);
  }
  else {
    local_38 = iVar7 - uVar22 << DAT_807c0a70;
    if (uVar14 == 0) {
      trap(7);
    }
  }
  local_38 = local_38 / uVar14;
  iVar8 = *(int *)(param_1 + 0x124) >> 0xc;
  uVar22 = *(uint *)(param_1 + 0x120) >> 0xc;
  if (iVar8 == -1) {
    if (uVar14 == 0) {
      trap(7);
    }
    uVar22 = DAT_807c0a88 - (uVar22 << DAT_807c0a70);
  }
  else {
    if (uVar14 == 0) {
      trap(7);
    }
    uVar22 = iVar8 - uVar22 << DAT_807c0a70;
  }
  uVar22 = uVar22 / uVar14;
  if (iVar7 == -1) {
    uVar22 = 0;
  }
  bVar2 = false;
  if (((*(uint *)(DAT_807c0a8c + 0xc) & 1) == 0) || (iVar7 = FUN_80747db0(), iVar7 != 1)) {
    bVar2 = true;
  }
  uVar10 = local_38;
  if (!bVar2) {
    uVar10 = uVar22;
  }
  DAT_807c0a84 = uVar20 | (uVar10 & 0x3ff) << 0x10;
  uVar20 = 0;
  *(uint *)(DAT_807c0a8c + 0x10) = uVar9 & 0x7ffff;
  iVar7 = FUN_80747db0();
  puVar3 = DAT_807c0a8c;
  if (uVar14 == 0) {
    trap(7);
  }
  uVar9 = ((*(uint *)(iVar7 * 0x10 + param_1 + 0x110) >> 0xc) << (DAT_807c0a70 & 0x1f)) / uVar14;
  *(uint *)(DAT_807c0a8c + 0x58) = uVar9 & 0x7ffff;
  *(uint *)(puVar3 + 0x5a) = uVar14 * uVar9;
  if ((int)(*puVar19 << 0x1d) < 0) {
    uVar12 = FUN_80791388();
    iVar7 = FUN_807925f4(uVar12);
    if (iVar7 != 1) {
      FUN_807915dc();
    }
  }
  else {
    uVar9 = FUN_807915dc();
    uVar20 = ~uVar9 & 1;
  }
  puVar3 = DAT_807c0a8c;
  uVar9 = DAT_807c0a70;
  uVar21 = (uint)DAT_807c0388;
  bVar1 = *(byte *)((int)puVar19 + 0x21);
  uVar11 = FUN_807915dc();
  iVar7 = FUN_807915ec();
  iVar8 = FUN_80792658(uVar5);
  *(char *)(DAT_807c0a8c + 0xa6) = (char)uVar20;
  puVar4 = DAT_807c0a8c;
  *(uint *)(puVar3 + 0x12) =
       uVar11 | iVar7 << 1 | uVar9 << 2 | iVar8 << 4 | uVar21 << 5 | (bVar1 & 1) << 0xf |
       uVar20 << 0x15 | uVar20 << 0x1b;
  uVar9 = 0;
  puVar18 = (undefined4 *)(puVar4 + 0x1a);
  *(undefined4 *)(puVar4 + 0xa4) = 0;
  puVar15 = puVar19 + 0x1d;
  *(uint *)(puVar4 + 0xaa) = puVar19[9] | puVar19[10] << 0x10;
  puVar16 = puVar15;
  do {
    uVar11 = puVar16[1];
    uVar20 = uVar9 & 0x1f;
    uVar9 = uVar9 + 1;
    *puVar18 = CONCAT22(*(undefined2 *)((int)puVar16 + 6),*(undefined2 *)((int)puVar16 + 2));
    puVar16 = puVar16 + 2;
    DAT_807c038c = DAT_807c038c | ((uVar11 & 0x1fff) >> 0xc) << uVar20;
    puVar18 = puVar18 + 1;
  } while (uVar9 < 0x1f);
  iVar7 = FUN_807915dc();
  if (iVar7 == 0) {
    *(uint *)(DAT_807c0a8c + 100) = DAT_807c038c;
  }
  else {
    *(undefined4 *)(DAT_807c0a8c + 100) = 0;
  }
  uVar20 = 0;
  uVar9 = 0;
  puVar16 = puVar15;
  do {
    uVar21 = *puVar16;
    puVar16 = puVar16 + 1;
    uVar11 = uVar9 & 0x1f;
    uVar9 = uVar9 + 1;
    uVar20 = uVar20 | ((uVar21 & 0xffff) >> 0xf) << uVar11;
  } while (uVar9 < 0x20);
  uVar11 = 0;
  uVar9 = 0;
  *(uint *)(DAT_807c0a8c + 0x60) = uVar20;
  do {
    uVar21 = *puVar15;
    puVar15 = puVar15 + 1;
    uVar20 = uVar9 & 0x1f;
    uVar9 = uVar9 + 1;
    uVar11 = uVar11 | ((uVar21 & 0xffff) >> 0xf) << uVar20;
  } while (uVar9 < 0x1e);
  *(uint *)(DAT_807c0a8c + 0x62) = uVar11;
  iVar7 = FUN_80747db0();
  if (*(int *)(iVar7 * 0x10 + param_1 + 0x114) >> 0xc == -1) {
    uVar9 = DAT_807c0a88;
    if (uVar14 == 0) {
      trap(7);
    }
  }
  else {
    iVar7 = FUN_80747db0();
    if (uVar14 == 0) {
      trap(7);
    }
    uVar9 = (*(int *)(iVar7 * 0x10 + param_1 + 0x114) >> 0xc) << (DAT_807c0a70 & 0x1f);
  }
  puVar3 = DAT_807c0a8c;
  *(uint *)(DAT_807c0a8c + 0xa8) = uVar22 & 0xffff | local_38 << 0x10;
  *(uint *)(puVar3 + 0xac) = uVar14 * uVar10 & 0x3ffff;
  *(uint *)(puVar3 + 0x5e) = uVar14 * (uVar9 / uVar14);
  *(uint *)(puVar3 + 0x5c) = uVar9 / uVar14;
  iVar7 = FUN_80792800(uVar5);
  bVar1 = *(byte *)(iVar7 + -0x7f83fc70);
  iVar7 = FUN_80792820(uVar5);
  puVar3 = DAT_807c0a8c;
  sVar13 = 1;
  if ((iVar7 != 2) && (sVar13 = 2, iVar7 != 4)) {
    sVar13 = 0;
  }
  *(byte *)((int)DAT_807c0a8c + 0x14d) = bVar1;
  iVar8 = 0;
  puVar3[4] = (ushort)bVar1 << 4 | sVar13 << 6 | 1;
  iVar7 = FUN_80792840(uVar5);
  if (iVar7 == 0) {
    iVar7 = FUN_80792ab0(uVar6);
    if (iVar7 != 0) {
      iVar8 = 1;
    }
  }
  else {
    iVar8 = 1;
  }
  uVar9 = FUN_80792a2c(uVar6);
  *(uint *)(DAT_807c0a8c + 0x66) =
       uVar9 & 1 | iVar8 << 2 | (DAT_807c0394 & 0x3f) << 3 |
       (*(byte *)((int)puVar19 + 0x22) & 3) << 10;
  if (iVar8 != 0) {
    iVar7 = FUN_80792ad0(uVar6);
    uVar9 = 0;
    do {
      uVar22 = 0;
      *(char *)((int)DAT_807c0a8c + uVar9 + 0x15c) = (char)(uVar9 << 2);
      do {
        iVar8 = uVar9 * 0x10 + uVar22;
        uVar22 = uVar22 + 1;
        *(undefined1 *)((int)DAT_807c0a8c + iVar8 + 0x164) = *(undefined1 *)(iVar8 + iVar7);
      } while (uVar22 < 0x10);
      uVar9 = uVar9 + 1;
    } while (uVar9 < 6);
    for (; uVar9 < 8; uVar9 = uVar9 + 1) {
      *(char *)((int)DAT_807c0a8c + uVar9 + 0x15c) = (char)(uVar9 << 2);
      puVar17 = (undefined1 *)(uVar9 * 0x40 + iVar7 + -0x120);
      uVar22 = 0;
      do {
        iVar8 = uVar9 * 0x40 + uVar22;
        uVar22 = uVar22 + 1;
        *(undefined1 *)((int)DAT_807c0a8c + iVar8 + 0x44) = *puVar17;
        puVar17 = puVar17 + 1;
      } while (uVar22 < 0x40);
    }
  }
  puVar3 = DAT_807c0a8c;
  DAT_807c0394 = *(undefined1 *)((int)puVar19 + 0x23);
  puVar16 = (uint *)(DAT_807c0a8c + 0x3de);
  *(undefined4 *)(DAT_807c0a8c + 0xa2) = 0x800080;
  *(uint *)(puVar3 + 0x3de) = *puVar16 & 0xfffffffe;
  *(uint *)(puVar3 + 0x3d8) = uVar14;
  *(undefined4 *)(puVar3 + 0x3dc) = 0;
  *(uint *)(puVar3 + 0x3da) = uVar10;
  *(undefined4 *)(puVar3 + 0xa0) = 0;
  FUN_8078fbb8(param_1);
  return;
}

