// FUN_80796e84
// Ghidra address: 80796e84

/* WARNING: Control flow encountered bad instruction data */

void FUN_80796e84(uint param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar3 = 0;
  do {
    uVar4 = sony_ucp_read7(0x350);
    iVar3 = iVar3 + 1;
    if ((uVar4 & 1) != 0) goto LAB_80796ee8;
  } while (iVar3 != 0x30571);
  FUN_80747a30(0x350);
LAB_80796ee8:
  sony_ucp_write7(0x350,1);
  iVar3 = 0;
  do {
    uVar4 = sony_ucp_read7(0x360);
    iVar3 = iVar3 + 1;
    if ((uVar4 & 1) != 0) goto LAB_80796f1c;
  } while (iVar3 != 0x30571);
  FUN_80747a30(0x360);
LAB_80796f1c:
  puVar1 = DAT_807c0b10;
  uVar6 = param_1 >> 0x18 & 0x3f;
  uVar5 = *DAT_807c0b10;
  *DAT_807c0b10 = uVar5 & 0xffffffc0 | uVar6;
  uVar4 = ((param_1 & 0xffff) >> 10) << 6;
  *puVar1 = uVar5 & 0xfffff000 | uVar6 | uVar4;
  *puVar1 = uVar5 & 0xffff8000 | uVar6 | uVar4 | ((param_1 & 0xffffff) >> 0x15) << 0xc;
  uVar4 = FUN_8079408c(1);
  puVar1[2] = puVar1[2] & 0xfffffffe | uVar4 & 1;
  if ((*puVar1 & 0x3f) - 0x10 < 8) {
    uVar4 = FUN_8079408c(1);
    puVar1[2] = puVar1[2] & 0xfffffffd | (uVar4 & 1) << 1;
  }
  uVar2 = FUN_80794188();
  uVar4 = FUN_80795ddc(uVar2);
  puVar1[2] = puVar1[2] & 0xfffffe03 | (uVar4 & 0x7f) << 2;
  FUN_8078c2c8();
  FUN_8078bd0c();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

