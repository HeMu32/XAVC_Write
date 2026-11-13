// FUN_8078c8dc
// Ghidra address: 8078c8dc

void FUN_8078c8dc(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint *puVar11;
  uint local_110 [60];
  
  iVar7 = 0;
  do {
    uVar10 = sony_ucp_read7(0x350);
    iVar7 = iVar7 + 1;
    if ((uVar10 & 1) != 0) goto LAB_8078c924;
  } while (iVar7 != 0x30571);
  FUN_80747a30(0x350);
LAB_8078c924:
  sony_ucp_write7(0x350,1);
  iVar7 = 0;
  do {
    uVar10 = sony_ucp_read7(0x360);
    iVar7 = iVar7 + 1;
    if ((uVar10 & 1) != 0) goto LAB_8078c958;
  } while (iVar7 != 0x30571);
  FUN_80747a30(0x360);
LAB_8078c958:
  uVar10 = FUN_8079408c(4);
  uVar2 = FUN_8079408c(3);
  uVar3 = FUN_8079408c(1);
  FUN_8078d8e0(uVar2,local_110);
  uVar4 = FUN_80794188();
  uVar5 = FUN_80795b84(uVar4);
  puVar6 = (uint *)FUN_8078b7b4(uVar5);
  uVar8 = 0;
  puVar9 = puVar6;
  do {
    uVar8 = uVar8 + 1;
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  } while (uVar8 < 0x1082);
  uVar8 = FUN_80795d94(uVar2);
  *puVar6 = *puVar6 & 0xfffff000 | uVar10 & 0xf | (uVar8 & 7) << 4 | (uVar3 & 1) << 7 |
            (uVar5 & 0xf) << 8;
  puVar11 = local_110;
  puVar9 = puVar6 + 0x2a;
  do {
    uVar5 = puVar11[1];
    uVar3 = puVar11[2];
    uVar10 = puVar11[3];
    *puVar9 = *puVar11;
    puVar11 = puVar11 + 4;
    puVar9[1] = uVar5;
    puVar9[2] = uVar3;
    puVar9[3] = uVar10;
    puVar9 = puVar9 + 4;
  } while (puVar11 != (uint *)&stack0xffffffe0);
  uVar10 = FUN_80794188();
  puVar6[1] = puVar6[1] & 0xfffffffc | uVar10 & 3;
  if ((uVar10 & 3) == 3) {
    uVar10 = FUN_8079408c(1);
    puVar6[1] = puVar6[1] & 0xfffffffb | (uVar10 & 1) << 2;
  }
  uVar2 = FUN_80794188();
  uVar1 = FUN_80795ba8(uVar2);
  *(undefined2 *)(puVar6 + 2) = uVar1;
  uVar2 = FUN_80794188();
  uVar1 = FUN_80795bd8(uVar2);
  *(undefined2 *)((int)puVar6 + 10) = uVar1;
  uVar10 = FUN_8079408c(1);
  puVar6[3] = puVar6[3] & 0xfffffffe | uVar10 & 1;
  if ((uVar10 & 1) != 0) {
    uVar10 = FUN_80794188();
    puVar6[0x66] = uVar10;
    uVar10 = FUN_80794188();
    puVar6[0x67] = uVar10;
    uVar10 = FUN_80794188();
    puVar6[0x68] = uVar10;
    uVar10 = FUN_80794188();
    puVar6[0x69] = uVar10;
  }
  uVar10 = 0;
  uVar2 = FUN_80794188();
  uVar3 = FUN_80795c38(uVar2);
  puVar6[4] = puVar6[4] & 0xfffffff8 | uVar3 & 7;
  uVar2 = FUN_80794188();
  uVar3 = FUN_80795c6c(uVar2,puVar6[4] & 7);
  puVar6[4] = puVar6[4] & 0xffffffc7 | (uVar3 & 7) << 3;
  uVar2 = FUN_80794188();
  uVar3 = FUN_80795c14(uVar2);
  puVar6[4] = puVar6[4] & 0xfffffc3f | (uVar3 & 0xf) << 6;
  uVar3 = FUN_8079408c(1);
  uVar3 = puVar6[4] & 0xfffffbff | (uVar3 & 1) << 10;
  puVar6[4] = uVar3;
  if ((int)(uVar3 << 0x15) < 0) {
    iVar7 = 0;
    goto LAB_8078d1fc;
  }
  uVar3 = *puVar6;
  for (uVar10 = (uVar3 & 0x7f) >> 4; iVar7 = uVar10 << 2, uVar10 <= (uVar3 & 0x7f) >> 4;
      uVar10 = uVar10 + 1) {
LAB_8078d1fc:
    uVar2 = FUN_80794188();
    *(undefined4 *)((int)puVar6 + iVar7 + 0x14) = uVar2;
    uVar2 = FUN_80794188();
    *(undefined4 *)((int)puVar6 + iVar7 + 0x30) = uVar2;
    uVar2 = FUN_80794188();
    *(undefined4 *)((int)puVar6 + iVar7 + 0x4c) = uVar2;
    uVar3 = *puVar6;
  }
  uVar2 = FUN_80794188();
  uVar10 = FUN_80795c90(uVar2);
  puVar6[0x1a] = uVar10;
  uVar2 = FUN_80794188();
  uVar10 = FUN_80795cb8(uVar2);
  puVar6[0x1b] = uVar10;
  uVar10 = FUN_80794188();
  puVar6[0x1c] = uVar10;
  uVar10 = FUN_80794188();
  puVar6[0x1d] = uVar10;
  uVar10 = FUN_80794188();
  puVar6[0x1e] = uVar10;
  uVar10 = FUN_80794188();
  puVar6[0x1f] = uVar10;
  uVar10 = FUN_8079408c(1);
  uVar3 = puVar6[0x20];
  puVar6[0x20] = uVar3 & 0xfffffffe | uVar10 & 1;
  if ((uVar10 & 1) == 0) {
    puVar6[0x20] = uVar3 & 0xfffffffc;
  }
  else {
    uVar10 = FUN_8079408c(1);
    uVar10 = puVar6[0x20] & 0xfffffffd | (uVar10 & 1) << 1;
    puVar6[0x20] = uVar10;
    if ((int)(uVar10 << 0x1e) < 0) {
      FUN_8078e2c4(puVar6 + 0x7f);
    }
    else {
      FUN_8078def8(puVar6 + 0x9b);
      *(undefined1 *)(puVar6 + 0x98) = 0x10;
      *(undefined1 *)((int)puVar6 + 0x267) = 0x10;
      *(undefined1 *)((int)puVar6 + 0x261) = 0x10;
      *(undefined1 *)((int)puVar6 + 0x262) = 0x10;
      *(undefined1 *)((int)puVar6 + 0x263) = 0x10;
      *(undefined1 *)(puVar6 + 0x99) = 0x10;
      *(undefined1 *)((int)puVar6 + 0x265) = 0x10;
      *(undefined1 *)((int)puVar6 + 0x266) = 0x10;
    }
  }
  uVar10 = FUN_8079408c(1);
  puVar6[0x21] = puVar6[0x21] & 0xfffffffe | uVar10 & 1;
  uVar10 = FUN_8079408c(1);
  puVar6[0x21] = puVar6[0x21] & 0xfffffffd | (uVar10 & 1) << 1;
  uVar10 = FUN_8079408c(1);
  uVar3 = puVar6[0x22];
  puVar6[0x22] = uVar3 & 0xfffffffe | uVar10 & 1;
  if ((uVar10 & 1) == 0) {
    puVar6[0x22] = uVar3 & 0xffffdffe;
  }
  else {
    uVar10 = FUN_8079408c(4);
    puVar6[0x22] = puVar6[0x22] & 0xffffffe1 | (uVar10 & 0xf) << 1;
    uVar10 = FUN_8079408c(4);
    puVar6[0x22] = puVar6[0x22] & 0xfffffe1f | (uVar10 & 0xf) << 5;
    uVar10 = FUN_80794188();
    puVar6[0x22] = puVar6[0x22] & 0xfffff9ff | (uVar10 & 3) << 9;
    uVar10 = FUN_80794188();
    puVar6[0x22] = puVar6[0x22] & 0xffffe7ff | (uVar10 & 3) << 0xb;
    uVar10 = FUN_8079408c(1);
    puVar6[0x22] = puVar6[0x22] & 0xffffdfff | (uVar10 & 1) << 0xd;
  }
  uVar3 = 0;
  uVar2 = FUN_80794188();
  uVar10 = FUN_80795ce0(uVar2);
  puVar6[0x23] = puVar6[0x23] & 0xffffff80 | uVar10 & 0x7f;
  if ((uVar10 & 0x7f) != 0) {
    do {
      FUN_8078afdc(uVar3,puVar6 + 0x21b,0);
      uVar3 = uVar3 + 1;
    } while (uVar3 < (puVar6[0x23] & 0x7f));
  }
  uVar10 = FUN_8079408c(1);
  puVar6[0x24] = puVar6[0x24] & 0xfffffffe | uVar10 & 1;
  uVar3 = 0;
  if ((uVar10 & 1) != 0) {
    uVar5 = puVar6[4];
    puVar9 = puVar6 + 0x1012;
    uVar10 = 0;
    uVar2 = FUN_80794188();
    uVar3 = FUN_80795d04(uVar2);
    if (uVar3 != 0) {
      do {
        uVar8 = FUN_8079408c(((uVar5 & 0x3ff) >> 6) + 4);
        *puVar9 = *puVar9 & 0xfffe0000 | uVar8 & 0x1ffff;
        uVar10 = uVar10 + 1;
        uVar8 = FUN_8079408c(1);
        *puVar9 = *puVar9 & 0xfffdffff | (uVar8 & 1) << 0x11;
        puVar9 = puVar9 + 1;
      } while (uVar10 < uVar3);
      uVar10 = puVar6[0x24];
      goto LAB_8078cc34;
    }
  }
  uVar10 = puVar6[0x24];
LAB_8078cc34:
  puVar6[0x24] = uVar10 & 0xffffff81 | (uVar3 & 0x3f) << 1;
  uVar10 = FUN_8079408c(1);
  puVar6[0x25] = puVar6[0x25] & 0xfffffffe | uVar10 & 1;
  uVar10 = FUN_8079408c(1);
  puVar6[0x25] = puVar6[0x25] & 0xfffffffd | (uVar10 & 1) << 1;
  uVar10 = FUN_8079408c(1);
  uVar10 = puVar6[0x25] & 0xfffffffb | (uVar10 & 1) << 2;
  puVar6[0x25] = uVar10;
  if ((int)(uVar10 << 0x1d) < 0) {
    FUN_8078e49c(puVar6 + 0x1032);
  }
  else {
    if ((puVar6[0x2c] & 3) == 3) {
      uVar10 = puVar6[0x1035] | 0x20;
    }
    else {
      uVar10 = puVar6[0x1035] & 0xffffffdf;
    }
    puVar6[0x1035] = uVar10;
  }
  uVar10 = FUN_8079408c(1);
  uVar3 = puVar6[0x26];
  puVar6[0x26] = uVar3 & 0xfffffffe | uVar10 & 1;
  if ((uVar10 & 1) == 0) {
    puVar6[0x26] = uVar3 & 0xfffffe00;
  }
  else {
    uVar10 = FUN_8079408c(1);
    puVar6[0x26] = puVar6[0x26] & 0xfffffffd | (uVar10 & 1) << 1;
    uVar10 = FUN_8079408c(1);
    puVar6[0x26] = puVar6[0x26] & 0xfffffffb | (uVar10 & 1) << 2;
    uVar10 = FUN_8079408c(1);
    puVar6[0x26] = puVar6[0x26] & 0xfffffff7 | (uVar10 & 1) << 3;
    uVar10 = FUN_8079408c(5);
    puVar6[0x26] = puVar6[0x26] & 0xfffffe0f | (uVar10 & 0x1f) << 4;
  }
  if ((int)(puVar6[0x26] << 0x1e) < 0) {
    uVar10 = FUN_8079408c(1);
    puVar6[0x26] = puVar6[0x26] & 0xfffffdff | (uVar10 & 1) << 9;
    uVar10 = FUN_8079408c(1);
    puVar6[0x26] = puVar6[0x26] & 0xfffffbff | (uVar10 & 1) << 10;
    uVar10 = FUN_8079408c(1);
    puVar6[0x26] = puVar6[0x26] & 0xfffff7ff | (uVar10 & 1) << 0xb;
    uVar10 = FUN_8079408c(1);
    puVar6[0x26] = puVar6[0x26] & 0xffffefff | (uVar10 & 1) << 0xc;
    uVar10 = FUN_8079408c(1);
    puVar6[0x26] = puVar6[0x26] & 0xffffdfff | (uVar10 & 1) << 0xd;
    uVar10 = FUN_8079408c(1);
    puVar6[0x26] = puVar6[0x26] & 0xffffbfff | (uVar10 & 1) << 0xe;
    uVar10 = FUN_8079408c(1);
    puVar6[0x26] = puVar6[0x26] & 0xffff7fff | (uVar10 & 1) << 0xf;
    uVar10 = FUN_8079408c(1);
    puVar6[0x26] = puVar6[0x26] & 0xfffeffff | (uVar10 & 1) << 0x10;
    uVar10 = FUN_8079408c(1);
    puVar6[0x26] = puVar6[0x26] & 0xfffdffff | (uVar10 & 1) << 0x11;
  }
  else {
    puVar6[0x26] = puVar6[0x26] & 0xfffc01ff;
  }
  uVar10 = puVar6[0x26];
  if ((int)(uVar10 << 0x1d) < 0) {
    uVar10 = FUN_8079408c(1);
    uVar10 = puVar6[0x26] & 0xfffbffff | (uVar10 & 1) << 0x12;
    puVar6[0x26] = uVar10;
  }
  if ((int)(uVar10 << 0x1c) < 0) {
    puVar9 = puVar6 + 0x24;
    uVar10 = 0;
    do {
      uVar3 = FUN_8079408c(1);
      puVar9[3] = puVar9[3] & 0xfffffffe | uVar3 & 1;
      uVar3 = FUN_8079408c(1);
      uVar5 = puVar9[3];
      uVar3 = (uVar3 & 1) << 1;
      puVar9[3] = uVar5 & 0xfffffffd | uVar3;
      if (uVar10 == 0) {
        uVar3 = FUN_80794188();
        puVar6[0x27] = puVar6[0x27] & 0xfffffffb | (uVar3 & 1) << 2;
        uVar3 = FUN_8079408c(1);
        puVar6[0x27] = puVar6[0x27] & 0xfffffff7 | (uVar3 & 1) << 3;
        uVar3 = FUN_8079408c(1);
        puVar6[0x27] = puVar6[0x27] & 0xffffffef | (uVar3 & 1) << 4;
        uVar3 = FUN_8079408c(1);
        puVar6[0x27] = puVar6[0x27] & 0xffffffdf | (uVar3 & 1) << 5;
        uVar3 = FUN_8079408c(1);
        puVar6[0x27] = puVar6[0x27] & 0xffffc03f | (uVar3 & 1) << 6;
      }
      else {
        puVar9[3] = uVar5 & 0xffffff81 | uVar3 | (puVar6[0x1b] + puVar6[0x1a] & 1) << 2;
        uVar3 = FUN_8079408c(1);
        puVar9[3] = puVar9[3] & 0xffffff7f | (uVar3 & 1) << 7;
        uVar3 = FUN_8079408c(1);
        puVar9[3] = puVar9[3] & 0xfffffeff | (uVar3 & 1) << 8;
        uVar3 = FUN_8079408c(1);
        puVar9[3] = puVar9[3] & 0xfffffdff | (uVar3 & 1) << 9;
        uVar3 = FUN_8079408c(1);
        puVar9[3] = puVar9[3] & 0xfffffbff | (uVar3 & 1) << 10;
        uVar3 = FUN_8079408c(1);
        puVar9[3] = puVar9[3] & 0xfffff7ff | (uVar3 & 1) << 0xb;
        uVar3 = FUN_8079408c(1);
        puVar9[3] = puVar9[3] & 0xffffefff | (uVar3 & 1) << 0xc;
        uVar3 = FUN_8079408c(1);
        puVar9[3] = puVar9[3] & 0xffffdfff | (uVar3 & 1) << 0xd;
      }
      uVar10 = uVar10 + 1;
      puVar9 = puVar9 + 1;
    } while (uVar10 < 2);
    uVar10 = puVar6[0x26];
  }
  if ((uVar10 & 0x1ff) >> 4 != 0) {
    while (iVar7 = FUN_8078b8b0(), iVar7 != 0) {
      uVar10 = FUN_8079408c(1);
      puVar6[0x29] = puVar6[0x29] & 0xfffffffe | uVar10 & 1;
    }
  }
  sony_ucp_write7(0x360,0);
  for (puVar9 = (uint *)((uint)puVar6 & 0xffffffc0); puVar9 < puVar6 + 0x1082;
      puVar9 = puVar9 + 0x10) {
    cacheOp(0x1a,puVar9);
  }
  return;
}

