// FUN_8078d264
// Ghidra address: 8078d264

void FUN_8078d264(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  
  iVar4 = 0;
  do {
    uVar8 = sony_ucp_read7(0x350);
    iVar4 = iVar4 + 1;
    if ((uVar8 & 1) != 0) goto LAB_8078d2a4;
  } while (iVar4 != 0x30571);
  FUN_80747a30(0x350);
LAB_8078d2a4:
  sony_ucp_write7(0x350,1);
  iVar4 = 0;
  do {
    uVar8 = sony_ucp_read7(0x360);
    iVar4 = iVar4 + 1;
    if ((uVar8 & 1) != 0) goto LAB_8078d2d8;
  } while (iVar4 != 0x30571);
  FUN_80747a30(0x360);
LAB_8078d2d8:
  uVar2 = FUN_80794188();
  uVar8 = FUN_80795ddc(uVar2);
  puVar3 = (uint *)FUN_8078b898(uVar8);
  uVar7 = 0;
  puVar6 = puVar3;
  do {
    uVar7 = uVar7 + 1;
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  } while (uVar7 < 0x27e);
  *puVar3 = *puVar3 & 0xffffff80 | uVar8 & 0x7f;
  uVar2 = FUN_80794188();
  uVar8 = FUN_80795b84(uVar2);
  *puVar3 = *puVar3 & 0xfffff87f | (uVar8 & 0xf) << 7;
  uVar8 = FUN_8079408c(1);
  *puVar3 = *puVar3 & 0xfffff7ff | (uVar8 & 1) << 0xb;
  uVar8 = FUN_8079408c(1);
  *puVar3 = *puVar3 & 0xffffefff | (uVar8 & 1) << 0xc;
  uVar8 = FUN_8079408c(3);
  *puVar3 = *puVar3 & 0xffff1fff | (uVar8 & 7) << 0xd;
  uVar8 = FUN_8079408c(1);
  *puVar3 = *puVar3 & 0xfffeffff | (uVar8 & 1) << 0x10;
  uVar8 = FUN_8079408c(1);
  *puVar3 = *puVar3 & 0xfffdffff | (uVar8 & 1) << 0x11;
  uVar2 = FUN_80794188();
  uVar8 = FUN_80795e00(uVar2);
  *puVar3 = *puVar3 & 0xffc3ffff | (uVar8 & 0xf) << 0x12;
  uVar2 = FUN_80794188();
  uVar8 = FUN_80795e24(uVar2);
  *puVar3 = *puVar3 & 0xfc3fffff | (uVar8 & 0xf) << 0x16;
  uVar1 = FUN_807941d8();
  *(undefined1 *)(puVar3 + 1) = uVar1;
  uVar8 = FUN_8079408c(1);
  puVar3[1] = puVar3[1] & 0xfffffeff | (uVar8 & 1) << 8;
  uVar8 = FUN_8079408c(1);
  puVar3[1] = puVar3[1] & 0xfffffdff | (uVar8 & 1) << 9;
  uVar8 = FUN_8079408c(1);
  uVar8 = puVar3[1] & 0xfffffbff | (uVar8 & 1) << 10;
  puVar3[1] = uVar8;
  if ((int)(uVar8 << 0x15) < 0) {
    uVar8 = FUN_80794188();
    puVar3[2] = uVar8;
  }
  else {
    puVar3[2] = 0;
  }
  uVar8 = FUN_807941d8();
  puVar3[3] = puVar3[3] & 0xffffffe0 | uVar8 & 0x1f;
  uVar8 = FUN_807941d8();
  puVar3[3] = puVar3[3] & 0xfffffc1f | (uVar8 & 0x1f) << 5;
  uVar8 = FUN_8079408c(1);
  puVar3[3] = puVar3[3] & 0xfffffbff | (uVar8 & 1) << 10;
  uVar8 = FUN_8079408c(1);
  puVar3[4] = puVar3[4] & 0xfffffffe | uVar8 & 1;
  uVar8 = FUN_8079408c(1);
  puVar3[4] = puVar3[4] & 0xfffffffd | (uVar8 & 1) << 1;
  uVar8 = FUN_8079408c(1);
  puVar3[4] = puVar3[4] & 0xfffffffb | (uVar8 & 1) << 2;
  uVar8 = FUN_8079408c(1);
  puVar3[5] = puVar3[5] & 0xfffffffe | uVar8 & 1;
  uVar8 = FUN_8079408c(1);
  uVar7 = puVar3[5];
  uVar8 = (uVar8 & 1) << 1;
  puVar3[5] = uVar7 & 0xfffffffd | uVar8;
  if ((uVar7 & 1) == 0) {
    puVar3[5] = uVar7 & 0xfffff001 | uVar8 | (uVar7 & 1) << 2 | (uVar7 & 1) << 7 | 0x1000;
    uVar8 = puVar3[0x30] | 1;
  }
  else {
    uVar2 = FUN_80794188();
    uVar8 = FUN_80795e48(uVar2);
    puVar3[5] = puVar3[5] & 0xffffff83 | (uVar8 & 0x1f) << 2;
    uVar2 = FUN_80794188();
    uVar8 = FUN_80795e6c(uVar2);
    puVar3[5] = puVar3[5] & 0xfffff07f | (uVar8 & 0x1f) << 7;
    uVar8 = FUN_8079408c(1);
    uVar7 = puVar3[5];
    uVar8 = uVar7 & 0xffffefff | (uVar8 & 1) << 0xc;
    puVar3[5] = uVar8;
    if (-1 < (int)(uVar8 << 0x13)) {
      uVar8 = 0;
      if ((uVar7 & 0x7f) >> 2 == 0) {
        uVar7 = puVar3[5];
      }
      else {
        puVar6 = puVar3 + 6;
        do {
          uVar8 = uVar8 + 1;
          uVar7 = FUN_80794188();
          *puVar6 = uVar7;
          uVar7 = puVar3[5];
          puVar6 = puVar6 + 1;
        } while (uVar8 < (uVar7 & 0x7f) >> 2);
      }
      uVar8 = 0;
      if ((uVar7 & 0xfff) >> 7 != 0) {
        puVar6 = puVar3 + 0x1a;
        do {
          uVar8 = uVar8 + 1;
          uVar7 = FUN_80794188();
          *puVar6 = uVar7;
          puVar6 = puVar6 + 1;
        } while (uVar8 < (puVar3[5] & 0xfff) >> 7);
      }
    }
    uVar8 = FUN_8079408c(1);
    uVar8 = puVar3[0x30] & 0xfffffffe | uVar8 & 1;
  }
  puVar3[0x30] = uVar8;
  uVar8 = FUN_8079408c(1);
  puVar3[0x30] = puVar3[0x30] & 0xfffffffd | (uVar8 & 1) << 1;
  uVar8 = FUN_8079408c(1);
  uVar7 = puVar3[0x30];
  uVar8 = (uVar8 & 1) << 2;
  puVar3[0x30] = uVar7 & 0xffffe01b | uVar8;
  if ((int)((uVar7 & 0xfffffffb | uVar8) << 0x1d) < 0) {
    uVar8 = FUN_8079408c(1);
    puVar3[0x30] = puVar3[0x30] & 0xfffffff7 | (uVar8 & 1) << 3;
    uVar8 = FUN_8079408c(1);
    uVar8 = puVar3[0x30] & 0xffffffef | (uVar8 & 1) << 4;
    puVar3[0x30] = uVar8;
    if (-1 < (int)(uVar8 << 0x1b)) {
      uVar8 = FUN_807941d8();
      puVar3[0x30] = puVar3[0x30] & 0xfffffe1f | (uVar8 & 0xf) << 5;
      uVar8 = FUN_807941d8();
      puVar3[0x30] = puVar3[0x30] & 0xffffe1ff | (uVar8 & 0xf) << 9;
    }
  }
  else {
    puVar3[0x30] = uVar7 & 0xffffe003 | uVar8;
  }
  uVar8 = FUN_8079408c(1);
  uVar8 = puVar3[0x30] & 0xffffdfff | (uVar8 & 1) << 0xd;
  puVar3[0x30] = uVar8;
  if ((int)(uVar8 << 0x12) < 0) {
    FUN_8078e2c4(puVar3 + 0x36);
  }
  uVar8 = FUN_8079408c(1);
  puVar3[0x30] = puVar3[0x30] & 0xffffbfff | (uVar8 & 1) << 0xe;
  uVar8 = FUN_80794188();
  puVar3[0x30] = puVar3[0x30] & 0x80007fff | (uVar8 & 0xffff) << 0xf;
  uVar8 = FUN_8079408c(1);
  puVar3[0x31] = puVar3[0x31] & 0xfffffffe | uVar8 & 1;
  uVar8 = FUN_8079408c(1);
  uVar7 = puVar3[0x31];
  uVar8 = (uVar8 & 1) << 1;
  uVar5 = uVar7 & 0xfffffffd | uVar8;
  puVar3[0x31] = uVar5;
  if ((int)(uVar5 << 0x1e) < 0) {
    uVar8 = FUN_8079408c(1);
    puVar3[0x31] = puVar3[0x31] & 0xfffffffb | (uVar8 & 1) << 2;
    uVar8 = FUN_8079408c(7);
    puVar3[0x31] = puVar3[0x31] & 0xfffffc07 | (uVar8 & 0x7f) << 3;
  }
  else {
    puVar3[0x31] = uVar7 & 0xfffffc01 | uVar8;
  }
  puVar3[0x31] = puVar3[0x31] & 0xffc063ff;
  uVar8 = 0;
  puVar6 = puVar3;
  do {
    uVar8 = uVar8 + 1;
    *(undefined1 *)((int)puVar6 + 199) = 0xf;
    *(undefined1 *)(puVar6 + 0x32) = 0xf;
    puVar6 = (uint *)((int)puVar6 + 2);
  } while (uVar8 < 6);
  iVar4 = puVar3[0x31] << 0x1d;
  if (iVar4 < 0) {
    if ((int)(puVar3[1] << 0x16) < 0) {
      uVar8 = FUN_80794188();
      puVar3[0x31] = puVar3[0x31] & 0xffffe3ff | (uVar8 & 7) << 10;
    }
    uVar8 = FUN_8079408c(1);
    puVar3[0x31] = puVar3[0x31] & 0xffffdfff | (uVar8 & 1) << 0xd;
    uVar8 = FUN_8079408c(1);
    uVar8 = puVar3[0x31] & 0xffffbfff | (uVar8 & 1) << 0xe;
    puVar3[0x31] = uVar8;
    if ((int)(uVar8 << 0x11) < 0) {
      uVar7 = 0;
      uVar8 = FUN_80794188();
      puVar3[0x31] = puVar3[0x31] & 0xfffc7fff | (uVar8 & 7) << 0xf;
      uVar8 = FUN_80794188();
      puVar3[0x31] = puVar3[0x31] & 0xffc3ffff | (uVar8 & 0xf) << 0x12;
      puVar6 = puVar3;
      do {
        uVar7 = uVar7 + 1;
        uVar1 = FUN_807941d8();
        *(undefined1 *)((int)puVar6 + 199) = uVar1;
        uVar1 = FUN_807941d8();
        *(undefined1 *)(puVar6 + 0x32) = uVar1;
        puVar6 = (uint *)((int)puVar6 + 2);
      } while (uVar7 <= (puVar3[0x31] & 0x3fffff) >> 0x12);
    }
    uVar8 = FUN_80794188();
    puVar3[0x34] = puVar3[0x34] & 0xf0ffffff | (uVar8 & 0xf) << 0x18;
    iVar4 = FUN_80794188();
    puVar3[0x34] = puVar3[0x34] & 0xfffffff | iVar4 << 0x1c;
  }
  else {
    puVar3[0x34] = puVar3[0x34] & 0xffffff | (iVar4 >> 0x1f) * -0x10000000;
    puVar3[0x31] = puVar3[0x31] & 0xffff9fff;
  }
  if ((puVar3[0x31] & 0x3ff) >> 3 != 0) {
    while (iVar4 = FUN_8078b8b0(), iVar4 != 0) {
      uVar8 = FUN_8079408c(1);
      puVar3[0x35] = puVar3[0x35] & 0xfffffffe | uVar8 & 1;
    }
  }
  sony_ucp_write7(0x360,0);
  for (puVar6 = (uint *)((uint)puVar3 & 0xffffffc0); puVar6 < puVar3 + 0x27e; puVar6 = puVar6 + 0x10
      ) {
    cacheOp(0x1a,puVar6);
  }
  return;
}

