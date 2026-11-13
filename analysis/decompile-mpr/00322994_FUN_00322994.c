// FUN_00322994
// Ghidra address: 00322994

void FUN_00322994(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  *(undefined4 *)(param_1 + 1) = 0x58415643;
  param_1[2] = 0xa00000;
  FUN_0032266c(param_1 + 3);
  *(undefined1 *)((long)param_1 + 0x9c) = 0;
  *(undefined1 *)((long)param_1 + 0x9d) = 0;
  *(undefined1 *)((long)param_1 + 0x9e) = 0;
  lVar2 = 0;
  param_1[0x11] = 0;
  *(undefined4 *)(param_1 + 0x12) = 0;
  *(undefined4 *)((long)param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x13) = 0;
  do {
    *(undefined4 *)((long)param_1 + lVar2 + 0x284) = 0;
    lVar2 = lVar2 + 4;
  } while (lVar2 != 0x14);
  puVar4 = param_1 + 0x5b;
  do {
    puVar3 = (undefined8 *)((long)puVar4 + 4);
    *(undefined4 *)puVar4 = 0;
    puVar4 = puVar3;
  } while (puVar3 != (undefined8 *)((long)param_1 + 0x2ec));
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  *(undefined4 *)(param_1 + 0x17) = 0;
  *(undefined4 *)((long)param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined8 *)((long)param_1 + 0xc4) = 0;
  *(undefined8 *)((long)param_1 + 0xcc) = 0;
  *(undefined4 *)((long)param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0x1b) = 0;
  *(undefined8 *)((long)param_1 + 0xdc) = 0;
  *(undefined8 *)((long)param_1 + 0xe4) = 0;
  *(undefined4 *)((long)param_1 + 0xec) = 0;
  *(undefined4 *)(param_1 + 0x1e) = 0;
  *(undefined4 *)(param_1 + 0x1f) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0xfc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  *(undefined4 *)(param_1 + 0x2e) = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  memset(param_1 + 0x39,0,0xb8);
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  param_1[0x58] = 0;
  param_1[0x59] = 0;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  *(undefined4 *)(param_1 + 0x5d) = 0;
  *(undefined4 *)((long)param_1 + 0x2ec) = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  param_1[99] = 0;
  if (param_2 != (undefined8 *)0x0) {
    uVar1 = param_2[1];
    param_1[1] = *param_2;
    param_1[2] = uVar1;
  }
  *param_1 = 0;
  *(undefined4 *)((long)param_1 + 0xf4) = 1;
  return;
}

