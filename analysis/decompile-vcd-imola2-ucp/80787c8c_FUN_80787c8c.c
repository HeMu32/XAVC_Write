// FUN_80787c8c
// Ghidra address: 80787c8c

void FUN_80787c8c(uint *param_1)

{
  uint uVar1;
  undefined2 local_30;
  undefined1 local_2e;
  undefined1 local_2d;
  uint local_2c;
  uint local_28;
  uint local_24;
  
  uVar1 = *param_1;
  local_30 = 0x50;
  local_24 = (uVar1 & 0x7ffffff) >> 0x1a;
  local_2c = uVar1 & 0x1ffffff;
  local_28 = (uVar1 & 0x3ffffff) >> 0x19;
  local_2e = 0xff;
  local_2d = 0;
  FUN_80794ebc(&local_30);
  return;
}

