// FUN_80787ac4
// Ghidra address: 80787ac4

void FUN_80787ac4(int param_1,int param_2)

{
  bool bVar1;
  uint *puVar2;
  undefined2 local_30;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  ushort local_2a;
  undefined4 local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  
  local_2e = 0xff;
  puVar2 = *(uint **)(param_1 + 4);
  bVar1 = param_2 == ((*puVar2 & 0xfff) >> 4) - 1;
  local_2b = bVar1 || param_2 == 0x23;
  local_2d = !bVar1 && param_2 != 0x23;
  local_28 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 8);
  local_2c = (undefined1)param_2;
  local_2a = (ushort)puVar2[param_2 * 2 + 4] & 0xfff;
  local_30 = 0x12;
  local_24 = puVar2[param_2 * 2 + 4] >> 0xc;
  local_20 = puVar2[param_2 * 2 + 5];
  local_1c = *(int *)(*(int *)(param_1 + 0xc) + 0xc) + puVar2[param_2 * 2 + 5];
  FUN_80794ebc(&local_30);
  return;
}

