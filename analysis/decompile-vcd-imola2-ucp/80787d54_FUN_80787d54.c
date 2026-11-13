// FUN_80787d54
// Ghidra address: 80787d54

void FUN_80787d54(int *param_1)

{
  int iVar1;
  undefined2 local_40;
  undefined1 local_3e;
  undefined1 local_3d;
  byte local_3c;
  byte local_3b;
  byte local_3a;
  byte local_39;
  byte local_38;
  byte local_37;
  byte local_36;
  byte local_35;
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  byte local_30;
  byte local_2f;
  byte local_2e;
  byte local_2d;
  
  iVar1 = *param_1;
  local_40 = 0x52;
  local_3c = (byte)iVar1 & 0xf;
  local_33 = (byte)((uint)iVar1 >> 0x10) >> 7;
  local_32 = (byte)((uint)(iVar1 << 7) >> 0x1f);
  local_31 = (byte)((uint)(iVar1 << 6) >> 0x1f);
  local_30 = (byte)((uint)(iVar1 << 5) >> 0x1f);
  local_2e = (byte)((uint)(iVar1 << 3) >> 0x1f);
  local_3e = 0xff;
  local_3b = (byte)iVar1 >> 4;
  local_3a = (byte)((uint)(iVar1 << 0x14) >> 0x1c);
  local_39 = (byte)((uint)iVar1 >> 8) >> 4;
  local_38 = (byte)((uint)(iVar1 << 0xe) >> 0x1e);
  local_37 = (byte)((uint)(iVar1 << 0xc) >> 0x1e);
  local_36 = (byte)((uint)(iVar1 << 0xb) >> 0x1f);
  local_35 = (byte)((uint)(iVar1 << 10) >> 0x1f);
  local_34 = (byte)((uint)(iVar1 << 9) >> 0x1f);
  local_2f = (byte)((uint)(iVar1 << 4) >> 0x1f);
  local_2d = (byte)((uint)(iVar1 << 2) >> 0x1f);
  local_3d = 0;
  FUN_80794ebc(&local_40);
  return;
}

