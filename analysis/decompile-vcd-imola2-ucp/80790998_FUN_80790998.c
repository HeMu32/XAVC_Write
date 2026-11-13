// FUN_80790998
// Ghidra address: 80790998

void FUN_80790998(uint *param_1,int param_2,int param_3,int param_4)

{
  uint *puVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  
  if (param_3 != 0) {
    iVar4 = 0;
    do {
      uVar5 = sony_ucp_read7(0x350);
      iVar4 = iVar4 + 1;
      if ((uVar5 & 1) != 0) goto LAB_807909ec;
    } while (iVar4 != 0x30571);
    FUN_80747a30(0x350);
LAB_807909ec:
    sony_ucp_write7(0x350,1);
    iVar4 = 0;
    do {
      uVar5 = sony_ucp_read7(0x360);
      iVar4 = iVar4 + 1;
      if ((uVar5 & 1) != 0) goto LAB_80790a20;
    } while (iVar4 != 0x30571);
    FUN_80747a30(0x360);
  }
LAB_80790a20:
  iVar4 = FUN_807929c8(*(undefined1 *)((int)DAT_807c0a98 + 3));
  puVar8 = DAT_807c0a98;
  if (iVar4 != 0) {
    uVar2 = FUN_80794188();
    *(undefined1 *)(puVar8 + 7) = uVar2;
  }
  iVar4 = FUN_807913dc();
  puVar8 = DAT_807c0a98;
  if (iVar4 != 0) {
    uVar5 = FUN_8079408c(1);
    puVar8[7] = puVar8[7] & 0xfffffeff | (uVar5 & 1) << 8;
  }
  iVar4 = FUN_807913bc();
  if (((iVar4 == 0) && (iVar4 = FUN_80791424(), iVar4 == 0)) && (iVar4 = FUN_807913dc(), iVar4 == 0)
     ) {
    uVar3 = *(undefined4 *)(param_2 + 0x90);
  }
  else {
    puVar8 = DAT_807c0a98;
    uVar5 = FUN_8079408c(1);
    puVar8[7] = puVar8[7] & 0xfffffdff | (uVar5 & 1) << 9;
    puVar8 = DAT_807c0a98;
    if ((int)(DAT_807c0a98[7] << 0x16) < 0) {
      uVar3 = FUN_80794188();
      puVar8 = DAT_807c0a98;
      uVar2 = FUN_8078eebc(uVar3);
      *(undefined1 *)((int)puVar8 + 0x1e) = uVar2;
      iVar4 = FUN_807913dc();
      if (iVar4 != 0) {
        uVar3 = FUN_80794188();
        puVar8 = DAT_807c0a98;
        uVar2 = FUN_8078eee4(uVar3);
        *(undefined1 *)((int)puVar8 + 0x1f) = uVar2;
      }
    }
    else {
      uVar2 = FUN_80792968(*(undefined1 *)((int)DAT_807c0a98 + 3));
      *(undefined1 *)((int)puVar8 + 0x1e) = uVar2;
      puVar8 = DAT_807c0a98;
      uVar2 = FUN_80792988(*(undefined1 *)((int)DAT_807c0a98 + 3));
      *(undefined1 *)((int)puVar8 + 0x1f) = uVar2;
    }
    uVar3 = *(undefined4 *)(param_2 + 0x90);
  }
  FUN_8079177c(uVar3);
  DAT_807c0ab0 = 0;
  DAT_807c0aac = 0;
  iVar4 = 0;
  do {
    iVar6 = iVar4 + 1;
    (&DAT_80833ab8)[iVar4] = 1;
    (&DAT_80833b38)[iVar4] = 1;
    (&DAT_80833bb8)[iVar4] = 1;
    (&DAT_80833af8)[iVar4] = 0;
    (&DAT_80833b78)[iVar4] = 0;
    (&DAT_80833bf8)[iVar4] = 0;
    (&DAT_80833a98)[iVar4] = 1;
    (&DAT_80833b18)[iVar4] = 1;
    (&DAT_80833b98)[iVar4] = 1;
    (&DAT_80833ad8)[iVar4] = 0;
    (&DAT_80833b58)[iVar4] = 0;
    (&DAT_80833bd8)[iVar4] = 0;
    iVar4 = iVar6;
  } while (iVar6 < 0x20);
  DAT_807c0ab8 = 0;
  DAT_807c0abc = 0;
  DAT_807c0ac0 = 0;
  DAT_807c0ac4 = 0;
  iVar4 = FUN_807928fc(*(undefined1 *)((int)DAT_807c0a98 + 3));
  if (((iVar4 != 0) &&
      ((iVar4 = FUN_807913bc(), iVar4 != 0 || (iVar4 = FUN_80791424(), iVar4 != 0)))) ||
     ((iVar4 = FUN_807928dc(*(undefined1 *)((int)DAT_807c0a98 + 3)), iVar4 == 1 &&
      (iVar4 = FUN_807913dc(), iVar4 != 0)))) {
    puVar8 = DAT_807c0a98;
    uVar3 = FUN_80791388();
    iVar4 = FUN_80792800(uVar3);
    DAT_807c0aac = FUN_80794188();
    if (7 < DAT_807c0aac) {
      DAT_807c0aac = 0;
    }
    if (iVar4 == 0) {
      uVar2 = *(undefined1 *)((int)puVar8 + 0x1e);
    }
    else {
      DAT_807c0ab0 = FUN_80794188();
      if (7 < DAT_807c0ab0) {
        DAT_807c0ab0 = 0;
      }
      uVar2 = *(undefined1 *)((int)puVar8 + 0x1e);
    }
    FUN_80791ad8(0,uVar2);
    iVar4 = FUN_807913dc();
    if (iVar4 != 0) {
      FUN_80791ad8(1,*(undefined1 *)((int)puVar8 + 0x1f));
    }
  }
  puVar8 = DAT_807c0a98;
  if ((*DAT_807c0a98 & 3) != 0) {
    if ((*DAT_807c0a98 & 0x7f) >> 2 == 5) {
      uVar5 = FUN_8079408c(1);
      puVar8[8] = puVar8[8] & 0xfffffffb | (uVar5 & 1) << 2;
      puVar1 = DAT_807c0a98;
      uVar5 = FUN_8079408c(1);
      puVar8 = DAT_807c0a98;
      puVar1[8] = puVar1[8] & 0xfffffff7 | (uVar5 & 1) << 3;
      iVar4 = DAT_807c0a9c;
      uVar5 = puVar8[8];
      uVar7 = *(uint *)(DAT_807c0a9c + 0x20);
      *(uint *)(DAT_807c0a9c + 0x20) = uVar7 & 0xfffffffb | uVar5 & 4;
      *(uint *)(iVar4 + 0x20) = uVar7 & 0xfffffff3 | uVar5 & 4 | puVar8[8] & 8;
    }
    else {
      uVar5 = FUN_8079408c(1);
      puVar8[8] = puVar8[8] & 0xffffffef | (uVar5 & 1) << 4;
      puVar8 = DAT_807c0a98;
      *(uint *)(DAT_807c0a9c + 0x20) =
           *(uint *)(DAT_807c0a9c + 0x20) & 0xffffffef | DAT_807c0a98[8] & 0x10;
      if ((int)(puVar8[8] << 0x1b) < 0) {
        do {
          uVar5 = FUN_80794188();
          if (6 < uVar5) {
            uVar5 = 0;
          }
          uVar5 = uVar5 & 7;
          *param_1 = *param_1 & 0xfffffff8 | uVar5;
          if (uVar5 == 3) {
            iVar4 = FUN_80794188();
            *param_1 = *param_1 & 0xff | iVar4 << 8;
            uVar5 = FUN_80794188();
            uVar5 = *param_1 & 0xffffff07 | (uVar5 & 0x1f) << 3;
LAB_80790d4c:
            *param_1 = uVar5;
          }
          else if ((uVar5 - 1 < 2 || uVar5 == 4) || (uVar5 == 6)) {
            iVar4 = FUN_80794188();
            uVar5 = *param_1 & 0xff | iVar4 << 8;
            goto LAB_80790d4c;
          }
          uVar5 = *param_1;
          param_1 = param_1 + 1;
        } while (((uVar5 & 7) != 0) && (iVar4 = FUN_8078e998(0x20), iVar4 == 0));
        FUN_8078e98c();
        puVar8 = DAT_807c0a98;
      }
    }
  }
  iVar4 = FUN_80792a2c(*(undefined1 *)((int)puVar8 + 3));
  if (((iVar4 != 0) && (iVar4 = FUN_80791398(), iVar4 == 0)) && (iVar4 = FUN_80791400(), iVar4 == 0)
     ) {
    uVar3 = FUN_80794188();
    puVar8 = DAT_807c0a98;
    uVar5 = FUN_8078ed7c(uVar3);
    puVar8[7] = puVar8[7] & 0xffffe7ff | (uVar5 & 3) << 0xb;
  }
  puVar8 = DAT_807c0a98;
  uVar2 = FUN_807941d8();
  *(undefined1 *)((int)puVar8 + 0x21) = uVar2;
  if (param_4 != 0) {
    sony_ucp_write7(0x360,0);
  }
  return;
}

