// FUN_00281f48
// Ghidra address: 00281f48

void FUN_00281f48(uint param_1,undefined4 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  uint local_8;
  undefined4 uStack_4;
  
  local_c = 2;
  local_e = 0xc0;
  local_b = 0;
  local_a = 0;
  local_9 = 0;
  local_10 = 0x2300;
  local_8 = param_1;
  uStack_4 = param_2;
  FUN_00281260(&local_10,0x10);
  if (PTR_DAT_004028b8[(ulong)param_1 * 0x10] == '\0') {
    uVar1 = 0x6c;
    FUN_00194dd8(0x2300,0xc1,"Init() has not been called yet");
  }
  else {
    uVar1 = (**(code **)(**(long **)(PTR_DAT_004028b8 + (ulong)param_1 * 0x10 + 8) + 0x88))
                      (*(long **)(PTR_DAT_004028b8 + (ulong)param_1 * 0x10 + 8),param_2,param_3);
  }
  local_b = 0;
  local_c = 4;
  local_a = 0;
  local_10 = 0x2300;
  local_9 = 0;
  local_e = 0xcf;
  FUN_00281260(&local_10,8);
  FUN_00281388(uVar1);
  return;
}

