// FUN_80797c8c
// Ghidra address: 80797c8c

void FUN_80797c8c(uint *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  undefined1 *puVar5;
  
  puVar4 = param_1 + 0x49;
  uVar2 = FUN_8079452c(param_2);
  uVar3 = FUN_8079408c(1);
  uVar3 = param_1[0x49] & 0xffffffef | (uVar3 & 1) << 4;
  param_1[0x49] = uVar3;
  if ((int)(uVar3 << 0x1b) < 0) {
    uVar3 = 0;
    do {
      uVar1 = FUN_8079408c(uVar2);
      *(undefined1 *)((int)puVar4 + uVar3 + 4) = uVar1;
      uVar3 = uVar3 + 1;
    } while (uVar3 <= (param_1[8] & 0xf));
  }
  if ((*param_1 & 0x1fffffff) >> 0x1b == 0) {
    uVar3 = FUN_8079408c(1);
    uVar3 = *puVar4 & 0xffffffdf | (uVar3 & 1) << 5;
    *puVar4 = uVar3;
    if ((int)(uVar3 << 0x1a) < 0) {
      puVar5 = (undefined1 *)((int)param_1 + 0x137);
      uVar3 = 0;
      do {
        uVar1 = FUN_8079408c(uVar2);
        *puVar5 = uVar1;
        uVar3 = uVar3 + 1;
        puVar5 = puVar5 + 1;
      } while (uVar3 <= (param_1[8] & 0xff) >> 4);
    }
  }
  return;
}

