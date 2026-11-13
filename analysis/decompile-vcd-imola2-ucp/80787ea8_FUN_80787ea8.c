// FUN_80787ea8
// Ghidra address: 80787ea8

void FUN_80787ea8(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 local_30;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  byte local_2b;
  byte local_2a;
  byte local_29;
  uint local_28;
  byte local_24;
  undefined1 local_23;
  byte local_22;
  byte local_21;
  byte local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  local_2c = (undefined1)*param_1;
  local_23 = (undefined1)param_1[1];
  local_28 = (uVar1 & 0x7ffffff) >> 0xf;
  local_30 = 0x54;
  local_2e = 0xff;
  local_2b = (byte)((uVar1 << 0x17) >> 0x1f);
  local_2a = (byte)((uVar1 << 0x15) >> 0x1e);
  local_29 = (byte)((uVar1 << 0x13) >> 0x1e);
  local_24 = (byte)((uVar1 << 0x11) >> 0x1e);
  local_22 = (byte)((uVar2 << 0x17) >> 0x1f);
  local_21 = (byte)((uVar2 << 0x15) >> 0x1e);
  local_20 = (byte)(uVar2 >> 8) >> 3;
  local_2d = 0;
  local_1f = 0;
  local_1e = 0;
  local_1d = 0;
  FUN_80794ebc(&local_30);
  return;
}

