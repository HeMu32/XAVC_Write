// FUN_002819f8
// Ghidra address: 002819f8

void FUN_002819f8(uint param_1,undefined8 param_2)

{
  undefined4 uVar1;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  uint local_8;
  
  local_c = 3;
  local_e = 0x60;
  local_b = 0;
  local_a = 0;
  local_9 = 0;
  local_10 = 0x2300;
  local_8 = param_1;
  FUN_00281260(&local_10,0xc);
  if (PTR_DAT_004028b8[(ulong)param_1 * 0x10] == '\0') {
    uVar1 = 0x6c;
    FUN_00194dd8(0x2300,0x61,"Init() has not been called yet");
  }
  else {
    uVar1 = (**(code **)(**(long **)(PTR_DAT_004028b8 + (ulong)param_1 * 0x10 + 8) + 0x78))
                      (*(long **)(PTR_DAT_004028b8 + (ulong)param_1 * 0x10 + 8),param_2);
  }
  local_b = 0;
  local_c = 4;
  local_a = 0;
  local_10 = 0x2300;
  local_9 = 0;
  local_e = 0x6f;
  FUN_00281260(&local_10,8);
  FUN_00281388(uVar1);
  return;
}

