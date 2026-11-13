// FUN_80792e90
// Ghidra address: 80792e90

void FUN_80792e90(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  
  iVar8 = 0;
  do {
    uVar11 = sony_ucp_read7(0x350);
    iVar8 = iVar8 + 1;
    if ((uVar11 & 1) != 0) goto LAB_80792ee0;
  } while (iVar8 != 0x30571);
  FUN_80747a30(0x350);
LAB_80792ee0:
  sony_ucp_write7(0x350,1);
  iVar8 = 0;
  do {
    uVar11 = sony_ucp_read7(0x360);
    iVar8 = iVar8 + 1;
    if ((uVar11 & 1) != 0) goto LAB_80792f14;
  } while (iVar8 != 0x30571);
  FUN_80747a30(0x360);
LAB_80792f14:
  uVar1 = FUN_8079408c(8);
  iVar8 = FUN_8078eff4(uVar1);
  uVar11 = FUN_8079408c(1);
  uVar2 = FUN_8079408c(1);
  uVar3 = FUN_8079408c(1);
  FUN_8079408c(1);
  FUN_8079408c(1);
  FUN_8079408c(1);
  FUN_8079408c(2);
  uVar4 = FUN_8079408c(8);
  uVar1 = FUN_80794188();
  uVar5 = FUN_8078f0a0(uVar1);
  puVar6 = (undefined4 *)FUN_807921f4(uVar5);
  uVar10 = 0;
  puVar9 = puVar6;
  do {
    uVar10 = uVar10 + 1;
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  } while (uVar10 < 0x149);
  *(char *)(puVar6 + 1) = (char)iVar8;
  puVar6[1] = puVar6[1] & 0xfe0008ff | (uVar11 & 1) << 8 | (uVar2 & 1) << 9 | (uVar3 & 1) << 10 |
              (uVar4 & 0xff) << 0xc | (uVar5 & 0x1f) << 0x14;
  if ((iVar8 == 100 || iVar8 == 0x6e) || (iVar8 == 0x7a || iVar8 == 0xf4)) {
    uVar1 = FUN_80794188();
    uVar11 = FUN_8078f0c4(uVar1);
    puVar6[2] = puVar6[2] & 0xfffffffc | uVar11 & 3;
    if ((uVar11 & 3) == 3) {
      uVar11 = FUN_8079408c(1);
      puVar6[2] = puVar6[2] & 0xfffffffb | (uVar11 & 1) << 2;
    }
    uVar11 = FUN_80794188();
    puVar6[2] = puVar6[2] & 0xffffff8f | (uVar11 & 7) << 4;
    uVar11 = FUN_80794188();
    puVar6[2] = puVar6[2] & 0xfffffc7f | (uVar11 & 7) << 7;
    uVar11 = FUN_8079408c(1);
    puVar6[2] = puVar6[2] & 0xfffffbff | (uVar11 & 1) << 10;
    uVar11 = FUN_8079408c(1);
    uVar11 = puVar6[2] & 0xfffff7ff | (uVar11 & 1) << 0xb;
    puVar6[2] = uVar11;
    if ((int)(uVar11 << 0x14) < 0) {
      FUN_80793aac(puVar6 + 0x109);
      iVar8 = puVar6[2];
      goto LAB_80793080;
    }
  }
  else {
    puVar6[2] = puVar6[2] & 0xfffffc0c | 1;
  }
  iVar8 = puVar6[2];
LAB_80793080:
  if (-1 < iVar8 << 0x14) {
    FUN_80798d24(puVar6 + 0x109);
  }
  uVar1 = FUN_80794188();
  uVar11 = FUN_8078f13c(uVar1);
  puVar6[1] = puVar6[1] & 0xe1ffffff | (uVar11 & 0xf) << 0x19;
  uVar1 = FUN_80794188();
  uVar11 = FUN_8078f160(uVar1);
  uVar11 = uVar11 & 3;
  puVar6[1] = puVar6[1] & 0x9fffffff | uVar11 << 0x1d;
  if (uVar11 == 0) {
    uVar1 = FUN_80794188();
    uVar11 = FUN_8078f184(uVar1);
    puVar6[2] = puVar6[2] & 0xffff0fff | (uVar11 & 0xf) << 0xc;
  }
  else if (uVar11 == 1) {
    uVar11 = FUN_8079408c(1);
    puVar6[2] = puVar6[2] & 0xfffeffff | (uVar11 & 1) << 0x10;
    iVar8 = 0;
    uVar1 = FUN_807941d8();
    puVar6[5] = uVar1;
    uVar1 = FUN_807941d8();
    puVar6[6] = uVar1;
    uVar11 = FUN_80794188();
    puVar6[2] = puVar6[2] & 0xfe01ffff | (uVar11 & 0xff) << 0x11;
    if ((uVar11 & 0xff) != 0) {
      puVar9 = puVar6 + 7;
      do {
        iVar8 = iVar8 + 1;
        uVar1 = FUN_807941d8();
        *puVar9 = uVar1;
        puVar9 = puVar9 + 1;
      } while (iVar8 < (int)((puVar6[2] & 0x1ffffff) >> 0x11));
    }
  }
  uVar11 = FUN_80794188();
  puVar6[2] = puVar6[2] & 0xc1ffffff | (uVar11 & 0x1f) << 0x19;
  uVar11 = FUN_8079408c(1);
  puVar6[2] = puVar6[2] & 0xbfffffff | (uVar11 & 1) << 0x1e;
  uVar1 = FUN_80794188();
  uVar11 = FUN_8078f1cc(uVar1);
  puVar6[3] = puVar6[3] & 0xfffffc00 | uVar11 & 0x3ff;
  uVar11 = FUN_80794188();
  puVar6[3] = puVar6[3] & 0xfff803ff | (uVar11 & 0x1ff) << 10;
  uVar11 = FUN_8079408c(1);
  uVar11 = puVar6[3] & 0xfff7ffff | (uVar11 & 1) << 0x13;
  puVar6[3] = uVar11;
  if (-1 < (int)(uVar11 << 0xc)) {
    uVar11 = FUN_8079408c(1);
    puVar6[3] = puVar6[3] & 0xffefffff | (uVar11 & 1) << 0x14;
  }
  uVar11 = FUN_8079408c(1);
  puVar6[3] = puVar6[3] & 0xffdfffff | (uVar11 & 1) << 0x15;
  uVar11 = FUN_8079408c(1);
  uVar11 = puVar6[4] & 0xbfffffff | (uVar11 & 1) << 0x1e;
  puVar6[4] = uVar11;
  if ((int)(uVar11 << 1) < 0) {
    uVar1 = FUN_80794188();
    iVar8 = FUN_8078f22c(uVar1);
    puVar6[3] = puVar6[3] & 0x3fffff | iVar8 << 0x16;
    uVar1 = FUN_80794188();
    uVar11 = FUN_8078f234(uVar1);
    puVar6[4] = puVar6[4] & 0xfffffc00 | uVar11 & 0x3ff;
    uVar1 = FUN_80794188();
    uVar11 = FUN_8078f23c(uVar1);
    puVar6[4] = puVar6[4] & 0xfff003ff | (uVar11 & 0x3ff) << 10;
    uVar1 = FUN_80794188();
    uVar11 = FUN_8078f244(uVar1);
    puVar6[4] = puVar6[4] & 0xc00fffff | (uVar11 & 0x3ff) << 0x14;
  }
  puVar6[0x141] = puVar6[0x141] & 0xf800007f | 0x62f7b80;
  uVar11 = FUN_8078f04c(uVar4);
  uVar11 = *(uint *)((uVar11 + (uVar11 / 10) * -6) * 4 + -0x7f8502dc);
  iVar8 = FUN_8079220c(uVar5);
  iVar7 = FUN_80792230(uVar5);
  uVar11 = uVar11 / (uint)(iVar8 * iVar7);
  if (iVar8 * iVar7 == 0) {
    trap(7);
  }
  uVar2 = 0x10;
  if (uVar11 < 0x11) {
    uVar2 = uVar11;
  }
  puVar6[0x147] = puVar6[0x147] & 0xffffffe0 | uVar2 & 0x1f;
  puVar6[2] = puVar6[2] & 0xc1ffffff |
              ((uVar2 & 0x1f) + ((puVar6[2] & 0x3fffffff) >> 0x19) & 0x1f) << 0x19;
  puVar6[0x141] = puVar6[0x141] & 0x7ffffff | uVar2 << 0x1b;
  uVar1 = FUN_8079408c(1);
  iVar8 = FUN_8078f24c(uVar1);
  puVar6[4] = puVar6[4] & 0x7fffffff | iVar8 << 0x1f;
  if (iVar8 << 0x1f != 0) {
    FUN_807936c4(puVar6 + 0x141);
  }
  sony_ucp_write7(0x360,0);
  for (puVar9 = (undefined4 *)((uint)puVar6 & 0xffffffc0); puVar9 < puVar6 + 0x149;
      puVar9 = puVar9 + 0x10) {
    cacheOp(0x1a,puVar9);
  }
  return;
}

