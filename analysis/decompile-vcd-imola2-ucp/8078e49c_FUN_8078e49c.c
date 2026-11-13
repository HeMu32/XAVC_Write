// FUN_8078e49c
// Ghidra address: 8078e49c

/* WARNING: Control flow encountered bad instruction data */

void FUN_8078e49c(uint *param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  *param_1 = *param_1 & 0xfffffe01;
  uVar3 = FUN_8079408c(1);
  *param_1 = *param_1 & 0xfffffffe | uVar3 & 1;
  if ((uVar3 & 1) != 0) {
    uVar3 = FUN_8079408c(8);
    *param_1 = *param_1 & 0xfffffe01 | (uVar3 & 0xff) << 1;
    if ((uVar3 & 0xff) == 0xff) {
      uVar2 = FUN_8079408c(0x10);
      *(undefined2 *)(param_1 + 1) = uVar2;
      uVar2 = FUN_8079408c(0x10);
      *(undefined2 *)((int)param_1 + 6) = uVar2;
    }
  }
  uVar3 = FUN_8079408c(1);
  param_1[2] = param_1[2] & 0xfffffffe | uVar3 & 1;
  if ((uVar3 & 1) != 0) {
    uVar3 = FUN_8079408c(1);
    param_1[2] = param_1[2] & 0xfffffffd | (uVar3 & 1) << 1;
  }
  param_1[2] = param_1[2] & 0xffffff87 | 0x28;
  *(undefined1 *)((int)param_1 + 0xb) = 2;
  *(undefined1 *)((int)param_1 + 9) = 2;
  *(undefined1 *)((int)param_1 + 10) = 2;
  uVar3 = FUN_8079408c(1);
  uVar3 = param_1[2] & 0xfffffffb | (uVar3 & 1) << 2;
  param_1[2] = uVar3;
  if ((int)(uVar3 << 0x1d) < 0) {
    uVar3 = FUN_8079408c(3);
    param_1[2] = param_1[2] & 0xffffffc7 | (uVar3 & 7) << 3;
    uVar3 = FUN_8079408c(1);
    param_1[2] = param_1[2] & 0xffffffbf | (uVar3 & 1) << 6;
    uVar3 = FUN_8079408c(1);
    uVar3 = param_1[2] & 0xffffff7f | (uVar3 & 1) << 7;
    param_1[2] = uVar3;
    if ((int)(uVar3 << 0x18) < 0) {
      uVar1 = FUN_8079408c(8);
      *(undefined1 *)((int)param_1 + 9) = uVar1;
      uVar1 = FUN_8079408c(8);
      *(undefined1 *)((int)param_1 + 10) = uVar1;
      uVar1 = FUN_8079408c(8);
      *(undefined1 *)((int)param_1 + 0xb) = uVar1;
    }
  }
  param_1[3] = param_1[3] & 0xfffffff9;
  uVar3 = FUN_8079408c(1);
  param_1[3] = param_1[3] & 0xfffffffe | uVar3 & 1;
  if ((uVar3 & 1) != 0) {
    uVar3 = FUN_80794188();
    param_1[3] = param_1[3] & 0xfffffffd | (uVar3 & 1) << 1;
    uVar3 = FUN_80794188();
    param_1[3] = param_1[3] & 0xfffffffb | (uVar3 & 1) << 2;
  }
  uVar3 = FUN_8079408c(1);
  param_1[3] = param_1[3] & 0xfffffff7 | (uVar3 & 1) << 3;
  uVar3 = FUN_8079408c(1);
  param_1[3] = param_1[3] & 0xffffffef | (uVar3 & 1) << 4;
  uVar3 = FUN_8079408c(1);
  param_1[3] = param_1[3] & 0xffffffdf | (uVar3 & 1) << 5;
  uVar3 = FUN_8079408c(1);
  uVar3 = param_1[3] & 0xffffffbf | (uVar3 & 1) << 6;
  param_1[3] = uVar3;
  if ((int)(uVar3 << 0x19) < 0) {
    uVar3 = FUN_80794188();
    param_1[3] = param_1[3] & 0xffffff7f | (uVar3 & 1) << 7;
    uVar3 = FUN_80794188();
    param_1[3] = param_1[3] & 0xfffffeff | (uVar3 & 1) << 8;
    uVar3 = FUN_80794188();
    param_1[3] = param_1[3] & 0xfffffdff | (uVar3 & 1) << 9;
    uVar3 = FUN_80794188();
    param_1[3] = param_1[3] & 0xfffffbff | (uVar3 & 1) << 10;
  }
  uVar3 = FUN_8079408c(1);
  uVar3 = param_1[3] & 0xfffff7ff | (uVar3 & 1) << 0xb;
  param_1[3] = uVar3;
  if ((int)(uVar3 << 0x14) < 0) {
    uVar3 = FUN_8079408c(0x20);
    param_1[4] = uVar3;
    uVar3 = FUN_8079408c(0x20);
    param_1[5] = uVar3;
    uVar3 = FUN_8079408c(1);
    param_1[6] = param_1[6] & 0xfffffffe | uVar3 & 1;
    if ((uVar3 & 1) != 0) {
      uVar3 = FUN_80794188();
      param_1[6] = param_1[6] & 0xfffffffd | (uVar3 & 1) << 1;
    }
    uVar3 = FUN_8079408c(1);
    uVar3 = param_1[6] & 0xfffffffb | (uVar3 & 1) << 2;
    param_1[6] = uVar3;
    if ((int)(uVar3 << 0x1d) < 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  uVar3 = FUN_8079408c(1);
  uVar4 = param_1[6];
  uVar3 = (uVar3 & 1) << 3;
  uVar5 = uVar4 & 0xfffffff7 | uVar3;
  param_1[6] = uVar5;
  if ((int)(uVar5 << 0x1c) < 0) {
    uVar3 = FUN_8079408c(1);
    param_1[6] = param_1[6] & 0xffffffef | (uVar3 & 1) << 4;
    uVar3 = FUN_8079408c(1);
    param_1[6] = param_1[6] & 0xffffffdf | (uVar3 & 1) << 5;
    uVar3 = FUN_8079408c(1);
    param_1[6] = param_1[6] & 0xffffffbf | (uVar3 & 1) << 6;
    uVar3 = FUN_80794188();
    param_1[6] = param_1[6] & 0xffffff7f | (uVar3 & 1) << 7;
    uVar3 = FUN_80794188();
    param_1[6] = param_1[6] & 0xfffffeff | (uVar3 & 1) << 8;
    uVar3 = FUN_80794188();
    param_1[6] = param_1[6] & 0xfffffdff | (uVar3 & 1) << 9;
    uVar3 = FUN_80794188();
    param_1[6] = param_1[6] & 0xfffffbff | (uVar3 & 1) << 10;
    uVar3 = FUN_80794188();
    param_1[6] = param_1[6] & 0xfffff7ff | (uVar3 & 1) << 0xb;
  }
  else {
    param_1[6] = uVar4 & 0xfffffe07 | uVar3 | 0xe00;
  }
  return;
}

