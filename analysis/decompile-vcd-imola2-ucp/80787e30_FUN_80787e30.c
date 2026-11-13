// FUN_80787e30
// Ghidra address: 80787e30

void FUN_80787e30(int *param_1)

{
  int iVar1;
  uint uVar2;
  undefined2 local_30;
  undefined1 local_2e;
  undefined1 local_2d;
  ushort local_2c;
  ushort local_2a;
  uint local_28;
  uint local_24;
  byte local_20;
  byte local_1f;
  byte local_1e;
  byte local_1d;
  
  uVar2 = param_1[1];
  iVar1 = *param_1;
  local_2c = (ushort)iVar1 & 0xfff;
  local_28 = uVar2 & 0x3ffff;
  local_24 = (uVar2 & 0xfffffff) >> 0x12;
  local_30 = 0x53;
  local_2e = 0xff;
  local_2a = (ushort)((uint)iVar1 >> 8) >> 4;
  local_20 = (byte)((uint)(iVar1 << 4) >> 0x1c);
  local_1f = (byte)((uint)iVar1 >> 0x1c);
  local_1e = (byte)((uVar2 << 3) >> 0x1f);
  local_1d = (byte)((uVar2 << 2) >> 0x1f);
  local_2d = 0;
  FUN_80794ebc(&local_30);
  return;
}

