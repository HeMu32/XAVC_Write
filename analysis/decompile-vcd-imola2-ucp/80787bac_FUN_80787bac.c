// FUN_80787bac
// Ghidra address: 80787bac

void FUN_80787bac(int param_1)

{
  int iVar1;
  undefined2 local_30;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_2e = 0xff;
  local_2d = 0;
  local_30 = 0x14;
  local_2c = *(undefined4 *)(*(int *)(param_1 + 0x8c) + 8);
  iVar1 = FUN_80747db0();
  local_28 = *(undefined4 *)(iVar1 * 0x40 + param_1);
  FUN_80794ebc(&local_30);
  return;
}

