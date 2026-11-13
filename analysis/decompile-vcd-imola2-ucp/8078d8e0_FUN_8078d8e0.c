// FUN_8078d8e0
// Ghidra address: 8078d8e0

void FUN_8078d8e0(uint param_1,uint *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  
  uVar7 = 0;
  uVar5 = 0;
  uVar2 = FUN_8079408c(2);
  *param_2 = *param_2 & 0xfffffffc | uVar2 & 3;
  uVar2 = FUN_8079408c(1);
  *param_2 = *param_2 & 0xfffffffb | (uVar2 & 1) << 2;
  uVar2 = FUN_8079408c(5);
  *param_2 = *param_2 & 0xffffff07 | (uVar2 & 0x1f) << 3;
  do {
    uVar3 = FUN_8079408c(1);
    uVar2 = uVar7 & 0x1f;
    uVar7 = uVar7 + 1;
    uVar5 = uVar5 | (uVar3 & 1) << uVar2;
  } while (uVar7 < 0x20);
  param_2[1] = uVar5;
  uVar2 = FUN_8079408c(1);
  param_2[2] = param_2[2] & 0xfffffffe | uVar2 & 1;
  uVar5 = 0;
  uVar2 = FUN_8079408c(1);
  param_2[2] = param_2[2] & 0xfffffffd | (uVar2 & 1) << 1;
  uVar2 = FUN_8079408c(1);
  param_2[2] = param_2[2] & 0xfffffffb | (uVar2 & 1) << 2;
  uVar2 = FUN_8079408c(1);
  param_2[2] = param_2[2] & 0xfffffff7 | (uVar2 & 1) << 3;
  FUN_8079408c(0x20);
  FUN_8079408c(0xc);
  uVar1 = FUN_8079408c(8);
  *(undefined1 *)(param_2 + 3) = uVar1;
  puVar6 = param_2;
  if (param_1 != 0) {
    do {
      uVar2 = FUN_8079408c(1);
      puVar6[4] = puVar6[4] & 0xfffffffe | uVar2 & 1;
      uVar5 = uVar5 + 1;
      uVar2 = FUN_8079408c(1);
      puVar6[4] = puVar6[4] & 0xfffffffd | (uVar2 & 1) << 1;
      puVar6 = puVar6 + 8;
    } while (uVar5 < param_1);
  }
  uVar2 = param_1;
  if (param_1 != 0) {
    for (; uVar2 < 8; uVar2 = uVar2 + 1) {
      FUN_8079408c(2);
    }
  }
  uVar2 = 0;
  if (param_1 != 0) {
    do {
      if ((param_2[4] & 1) == 0) {
        uVar5 = param_2[4];
      }
      else {
        uVar5 = FUN_8079408c(2);
        param_2[5] = param_2[5] & 0xfffffffc | uVar5 & 3;
        uVar3 = 0;
        uVar5 = FUN_8079408c(1);
        param_2[5] = param_2[5] & 0xfffffffb | (uVar5 & 1) << 2;
        uVar7 = 0;
        uVar5 = FUN_8079408c(5);
        param_2[5] = param_2[5] & 0xffffff07 | (uVar5 & 0x1f) << 3;
        do {
          uVar4 = FUN_8079408c(1);
          uVar5 = uVar7 & 0x1f;
          uVar7 = uVar7 + 1;
          uVar3 = uVar3 | (uVar4 & 1) << uVar5;
        } while (uVar7 < 0x20);
        param_2[6] = uVar3;
        uVar5 = FUN_8079408c(1);
        param_2[7] = uVar5;
        uVar5 = FUN_8079408c(1);
        param_2[8] = uVar5;
        uVar5 = FUN_8079408c(1);
        param_2[9] = uVar5;
        uVar5 = FUN_8079408c(1);
        param_2[10] = uVar5;
        FUN_8079408c(0x20);
        FUN_8079408c(0xc);
        uVar5 = param_2[4];
      }
      if ((int)(uVar5 << 0x1e) < 0) {
        uVar1 = FUN_8079408c(8);
        *(undefined1 *)(param_2 + 0xb) = uVar1;
      }
      uVar2 = uVar2 + 1;
      param_2 = param_2 + 8;
    } while (uVar2 < param_1);
  }
  return;
}

