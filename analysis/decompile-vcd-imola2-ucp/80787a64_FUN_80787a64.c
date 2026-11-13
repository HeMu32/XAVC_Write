// FUN_80787a64
// Ghidra address: 80787a64

void FUN_80787a64(int param_1)

{
  uint *puVar1;
  undefined2 local_30;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined4 local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  
  local_2e = 0xff;
  local_2d = 0;
  puVar1 = *(uint **)(param_1 + 4);
  local_30 = 0x11;
  local_2c = *(undefined4 *)(*(int *)(param_1 + 0xc) + 8);
  local_28 = puVar1[2];
  local_24 = (*puVar1 & 0xfffff) >> 0xc;
  local_20 = puVar1[1];
  FUN_80794ebc(&local_30);
  return;
}

