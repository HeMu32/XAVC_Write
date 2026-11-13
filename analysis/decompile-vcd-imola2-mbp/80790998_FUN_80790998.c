// FUN_80790998
// Ghidra address: 80790998

/* WARNING: Control flow encountered bad instruction data */

void FUN_80790998(uint *param_1,int param_2,int param_3,int param_4)

{
  uint *puVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  
  if (param_3 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  iVar3 = FUN_807929c8(*(undefined1 *)((int)DAT_807c0a98 + 3));
  puVar8 = DAT_807c0a98;
  if (iVar3 != 0) {
    uVar2 = FUN_80794188();
    *(undefined1 *)(puVar8 + 7) = uVar2;
  }
  iVar3 = FUN_807913dc();
  puVar8 = DAT_807c0a98;
  if (iVar3 != 0) {
    uVar4 = FUN_8079408c(1);
    puVar8[7] = puVar8[7] & 0xfffffeff | (uVar4 & 1) << 8;
  }
  iVar3 = FUN_807913bc();
  if (((iVar3 == 0) && (iVar3 = FUN_80791424(), iVar3 == 0)) && (iVar3 = FUN_807913dc(), iVar3 == 0)
     ) {
    uVar5 = *(undefined4 *)(param_2 + 0x90);
  }
  else {
    puVar8 = DAT_807c0a98;
    uVar4 = FUN_8079408c(1);
    puVar8[7] = puVar8[7] & 0xfffffdff | (uVar4 & 1) << 9;
    puVar8 = DAT_807c0a98;
    if ((int)(DAT_807c0a98[7] << 0x16) < 0) {
      uVar5 = FUN_80794188();
      puVar8 = DAT_807c0a98;
      uVar2 = FUN_8078eebc(uVar5);
      *(undefined1 *)((int)puVar8 + 0x1e) = uVar2;
      iVar3 = FUN_807913dc();
      if (iVar3 != 0) {
        uVar5 = FUN_80794188();
        puVar8 = DAT_807c0a98;
        uVar2 = FUN_8078eee4(uVar5);
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
    uVar5 = *(undefined4 *)(param_2 + 0x90);
  }
  FUN_8079177c(uVar5);
  DAT_807c0ab0 = 0;
  DAT_807c0aac = 0;
  iVar3 = 0;
  do {
    iVar6 = iVar3 + 1;
    (&DAT_80833ab8)[iVar3] = 1;
    (&DAT_80833b38)[iVar3] = 1;
    (&DAT_80833bb8)[iVar3] = 1;
    (&DAT_80833af8)[iVar3] = 0;
    (&DAT_80833b78)[iVar3] = 0;
    (&DAT_80833bf8)[iVar3] = 0;
    (&DAT_80833a98)[iVar3] = 1;
    (&DAT_80833b18)[iVar3] = 1;
    (&DAT_80833b98)[iVar3] = 1;
    (&DAT_80833ad8)[iVar3] = 0;
    (&DAT_80833b58)[iVar3] = 0;
    (&DAT_80833bd8)[iVar3] = 0;
    iVar3 = iVar6;
  } while (iVar6 < 0x20);
  DAT_807c0ab8 = 0;
  DAT_807c0abc = 0;
  DAT_807c0ac0 = 0;
  DAT_807c0ac4 = 0;
  iVar3 = FUN_807928fc(*(undefined1 *)((int)DAT_807c0a98 + 3));
  if (((iVar3 != 0) &&
      ((iVar3 = FUN_807913bc(), iVar3 != 0 || (iVar3 = FUN_80791424(), iVar3 != 0)))) ||
     ((iVar3 = FUN_807928dc(*(undefined1 *)((int)DAT_807c0a98 + 3)), iVar3 == 1 &&
      (iVar3 = FUN_807913dc(), iVar3 != 0)))) {
    puVar8 = DAT_807c0a98;
    uVar5 = FUN_80791388();
    iVar3 = FUN_80792800(uVar5);
    DAT_807c0aac = FUN_80794188();
    if (7 < DAT_807c0aac) {
      DAT_807c0aac = 0;
    }
    if (iVar3 == 0) {
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
    iVar3 = FUN_807913dc();
    if (iVar3 != 0) {
      FUN_80791ad8(1,*(undefined1 *)((int)puVar8 + 0x1f));
    }
  }
  puVar8 = DAT_807c0a98;
  if ((*DAT_807c0a98 & 3) != 0) {
    if ((*DAT_807c0a98 & 0x7f) >> 2 == 5) {
      uVar4 = FUN_8079408c(1);
      puVar8[8] = puVar8[8] & 0xfffffffb | (uVar4 & 1) << 2;
      puVar1 = DAT_807c0a98;
      uVar4 = FUN_8079408c(1);
      puVar8 = DAT_807c0a98;
      puVar1[8] = puVar1[8] & 0xfffffff7 | (uVar4 & 1) << 3;
      iVar3 = DAT_807c0a9c;
      uVar4 = puVar8[8];
      uVar7 = *(uint *)(DAT_807c0a9c + 0x20);
      *(uint *)(DAT_807c0a9c + 0x20) = uVar7 & 0xfffffffb | uVar4 & 4;
      *(uint *)(iVar3 + 0x20) = uVar7 & 0xfffffff3 | uVar4 & 4 | puVar8[8] & 8;
    }
    else {
      uVar4 = FUN_8079408c(1);
      puVar8[8] = puVar8[8] & 0xffffffef | (uVar4 & 1) << 4;
      puVar8 = DAT_807c0a98;
      *(uint *)(DAT_807c0a9c + 0x20) =
           *(uint *)(DAT_807c0a9c + 0x20) & 0xffffffef | DAT_807c0a98[8] & 0x10;
      if ((int)(puVar8[8] << 0x1b) < 0) {
        do {
          uVar4 = FUN_80794188();
          if (6 < uVar4) {
            uVar4 = 0;
          }
          uVar4 = uVar4 & 7;
          *param_1 = *param_1 & 0xfffffff8 | uVar4;
          if (uVar4 == 3) {
            iVar3 = FUN_80794188();
            *param_1 = *param_1 & 0xff | iVar3 << 8;
            uVar4 = FUN_80794188();
            uVar4 = *param_1 & 0xffffff07 | (uVar4 & 0x1f) << 3;
LAB_80790d4c:
            *param_1 = uVar4;
          }
          else if ((uVar4 - 1 < 2 || uVar4 == 4) || (uVar4 == 6)) {
            iVar3 = FUN_80794188();
            uVar4 = *param_1 & 0xff | iVar3 << 8;
            goto LAB_80790d4c;
          }
          uVar4 = *param_1;
          param_1 = param_1 + 1;
        } while (((uVar4 & 7) != 0) && (iVar3 = FUN_8078e998(0x20), iVar3 == 0));
        FUN_8078e98c();
        puVar8 = DAT_807c0a98;
      }
    }
  }
  iVar3 = FUN_80792a2c(*(undefined1 *)((int)puVar8 + 3));
  if (((iVar3 != 0) && (iVar3 = FUN_80791398(), iVar3 == 0)) && (iVar3 = FUN_80791400(), iVar3 == 0)
     ) {
    uVar5 = FUN_80794188();
    puVar8 = DAT_807c0a98;
    uVar4 = FUN_8078ed7c(uVar5);
    puVar8[7] = puVar8[7] & 0xffffe7ff | (uVar4 & 3) << 0xb;
  }
  puVar8 = DAT_807c0a98;
  uVar2 = FUN_807941d8();
  *(undefined1 *)((int)puVar8 + 0x21) = uVar2;
  if (param_4 == 0) {
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

