// FUN_80793420
// Ghidra address: 80793420

void FUN_80793420(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  iVar3 = 0;
  do {
    uVar5 = sony_ucp_read7(0x350);
    iVar3 = iVar3 + 1;
    if ((uVar5 & 1) != 0) goto LAB_8079345c;
  } while (iVar3 != 0x30571);
  FUN_80747a30(0x350);
LAB_8079345c:
  sony_ucp_write7(0x350,1);
  iVar3 = 0;
  do {
    uVar5 = sony_ucp_read7(0x360);
    iVar3 = iVar3 + 1;
    if ((uVar5 & 1) != 0) goto LAB_80793490;
  } while (iVar3 != 0x30571);
  FUN_80747a30(0x360);
LAB_80793490:
  uVar1 = FUN_80794188();
  uVar1 = FUN_8078ee7c(uVar1);
  puVar2 = (undefined4 *)FUN_80792268(uVar1);
  uVar5 = 0;
  puVar4 = puVar2;
  do {
    uVar5 = uVar5 + 1;
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  } while (uVar5 < 0x3d);
  *(char *)(puVar2 + 1) = (char)uVar1;
  uVar1 = FUN_80794188();
  uVar5 = FUN_8078f0a0(uVar1);
  puVar2[1] = puVar2[1] & 0xffffe0ff | (uVar5 & 0x1f) << 8;
  uVar5 = FUN_8079408c(1);
  puVar2[1] = puVar2[1] & 0xffffdfff | (uVar5 & 1) << 0xd;
  uVar5 = FUN_8079408c(1);
  puVar2[1] = puVar2[1] & 0xffffbfff | (uVar5 & 1) << 0xe;
  uVar1 = FUN_80794188();
  uVar5 = FUN_8078eea0(uVar1);
  puVar2[1] = puVar2[1] & 0xfffc7fff | (uVar5 & 7) << 0xf;
  uVar1 = FUN_80794188();
  uVar5 = FUN_8078eebc(uVar1);
  puVar2[1] = puVar2[1] & 0xff83ffff | (uVar5 & 0x1f) << 0x12;
  uVar1 = FUN_80794188();
  uVar5 = FUN_8078eee4(uVar1);
  puVar2[1] = puVar2[1] & 0xf07fffff | (uVar5 & 0x1f) << 0x17;
  uVar5 = FUN_8079408c(1);
  puVar2[1] = puVar2[1] & 0xefffffff | (uVar5 & 1) << 0x1c;
  uVar5 = FUN_8079408c(2);
  puVar2[1] = puVar2[1] & 0x9fffffff | (uVar5 & 3) << 0x1d;
  uVar1 = FUN_807941d8();
  uVar5 = FUN_8078ef0c(uVar1);
  puVar2[2] = puVar2[2] & 0xfffff807 | (uVar5 & 0xff) << 3;
  uVar5 = FUN_807941d8();
  puVar2[2] = puVar2[2] & 0xfff807ff | (uVar5 & 0xff) << 0xb;
  uVar1 = FUN_807941d8();
  uVar5 = FUN_8078ef7c(uVar1);
  puVar2[2] = puVar2[2] & 0xff07ffff | (uVar5 & 0x1f) << 0x13;
  uVar5 = FUN_8079408c(1);
  puVar2[2] = puVar2[2] & 0xfffffffe | uVar5 & 1;
  uVar5 = FUN_8079408c(1);
  puVar2[2] = puVar2[2] & 0xfffffffd | (uVar5 & 1) << 1;
  uVar1 = FUN_8079408c(1);
  uVar5 = FUN_8078efa8(uVar1);
  uVar5 = (uVar5 & 1) << 2;
  puVar2[2] = puVar2[2] & 0x83fffffb | uVar5 |
              ((int)((puVar2[2] & 0xfffffffb | uVar5) << 8) >> 0x1b & 0x1fU) << 0x1a;
  iVar3 = FUN_80792300();
  if (iVar3 == 0) {
    iVar3 = puVar2[2];
  }
  else {
    uVar5 = FUN_8079408c(1);
    puVar2[2] = puVar2[2] & 0xfeffffff | (uVar5 & 1) << 0x18;
    uVar5 = FUN_8079408c(1);
    puVar2[2] = puVar2[2] & 0xfdffffff | (uVar5 & 1) << 0x19;
    FUN_80792280(puVar2);
    iVar3 = puVar2[2];
  }
  if (-1 < iVar3 << 6) {
    iVar3 = FUN_807921f4((puVar2[1] & 0x1fff) >> 8);
    FUN_80798d44(puVar2 + 5,iVar3 + 0x424);
  }
  sony_ucp_write7(0x360,0);
  for (puVar4 = (undefined4 *)((uint)puVar2 & 0xffffffc0); puVar4 < puVar2 + 0x3d;
      puVar4 = puVar4 + 0x10) {
    cacheOp(0x1a,puVar4);
  }
  return;
}

