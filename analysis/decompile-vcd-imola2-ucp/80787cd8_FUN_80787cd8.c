// FUN_80787cd8
// Ghidra address: 80787cd8

void FUN_80787cd8(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 local_30;
  undefined1 local_2e;
  undefined1 local_2d;
  uint local_2c;
  uint local_28;
  byte local_24;
  byte local_23;
  byte local_22;
  byte local_21;
  byte local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  local_2c = uVar1 & 0x3ff;
  local_28 = (uVar1 & 0x1fffffff) >> 0xd;
  local_22 = (byte)uVar2 & 7;
  local_30 = 0x51;
  local_2e = 0xff;
  local_24 = (byte)((uVar1 << 0x13) >> 0x1d);
  local_23 = (byte)((uVar1 << 2) >> 0x1f);
  local_21 = (byte)((uVar2 << 0x1c) >> 0x1f);
  local_20 = (byte)((uVar2 << 0x19) >> 0x1d);
  local_2d = 0;
  local_1f = 0;
  local_1e = 0;
  local_1d = 0;
  FUN_80794ebc(&local_30);
  return;
}

