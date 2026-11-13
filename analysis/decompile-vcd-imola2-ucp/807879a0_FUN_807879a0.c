// FUN_807879a0
// Ghidra address: 807879a0

void FUN_807879a0(int param_1)

{
  undefined2 local_30;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  
  local_2e = 0xff;
  local_2d = 0;
  local_1c = *(int *)(param_1 + 0xc);
  local_20 = *(undefined4 *)(param_1 + 4);
  local_30 = 1;
  local_2c = *(undefined4 *)(local_1c + 8);
  local_28 = *(undefined4 *)(local_1c + 0xc);
  local_24 = *(undefined4 *)(local_1c + 0x10);
  FUN_80794ebc(&local_30);
  return;
}

