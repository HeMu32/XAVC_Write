// FUN_80793c2c
// Ghidra address: 80793c2c

void FUN_80793c2c(uint *param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = FUN_80794188();
  param_1[3] = param_1[3] & 0xffffffe0 | uVar2 & 0x1f;
  if (param_2 == 1) {
    uVar2 = FUN_8079408c(4);
    param_1[6] = param_1[6] & 0xfffffe1f | (uVar2 & 0xf) << 5;
  }
  else {
    FUN_8079408c(4);
  }
  uVar2 = FUN_8079408c(4);
  param_1[6] = param_1[6] & 0xffffe1ff | (uVar2 & 0xf) << 9;
  uVar2 = 0;
  do {
    uVar3 = FUN_80794188();
    bVar1 = uVar2 == 0;
    uVar2 = uVar2 + 1;
    if (bVar1 && param_2 == 1) {
      param_1[7] = uVar3;
    }
    FUN_80794188();
    FUN_8079408c(1);
  } while (uVar2 <= (param_1[3] & 0x1f));
  uVar2 = FUN_8079408c(5);
  *param_1 = *param_1 & 0xfffff07f | (uVar2 & 0x1f) << 7;
  uVar2 = FUN_8079408c(5);
  *param_1 = *param_1 & 0xfffe0fff | (uVar2 & 0x1f) << 0xc;
  uVar2 = FUN_8079408c(5);
  *param_1 = *param_1 & 0xffc1ffff | (uVar2 & 0x1f) << 0x11;
  uVar2 = FUN_8079408c(5);
  *param_1 = *param_1 & 0xf83fffff | (uVar2 & 0x1f) << 0x16;
  return;
}

