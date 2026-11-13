// FUN_80794ebc
// Ghidra address: 80794ebc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80794ebc(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  puVar1 = _DAT_80ab0b60;
  if (DAT_80ab0b64 == '\0') {
    puVar5 = _DAT_80ab0b60 + 7;
    puVar2 = puVar5;
    if ((undefined4 *)0x80ab1ce7 < puVar5) {
      DAT_80ab0b65 = 1;
      puVar2 = (undefined4 *)0x80ab0b68;
    }
    puVar4 = (undefined4 *)((uint)_DAT_80ab0b60 & 0xffffffc0);
    *_DAT_80ab0b60 = _DAT_be0000ac;
    _DAT_80ab0b60 = puVar2;
    uVar6 = param_1[1];
    uVar7 = param_1[2];
    uVar8 = param_1[3];
    puVar1[1] = *param_1;
    puVar1[2] = uVar6;
    puVar1[3] = uVar7;
    puVar1[4] = uVar8;
    uVar6 = param_1[5];
    puVar1[5] = param_1[4];
    puVar1[6] = uVar6;
    for (; puVar4 < puVar5; puVar4 = puVar4 + 0x10) {
      cacheOp(0x1a,puVar4);
    }
    uVar3 = 0x80ab0b40;
    do {
      cacheOp(0x1a,uVar3);
      uVar3 = uVar3 + 0x40;
    } while (uVar3 < 0x80ab0b68);
  }
  return;
}

