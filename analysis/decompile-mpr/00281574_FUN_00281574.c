// FUN_00281574
// Ghidra address: 00281574

void FUN_00281574(uint param_1,byte param_2,uint param_3)

{
  undefined4 uVar1;
  undefined2 local_18;
  undefined2 local_16;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  uint local_10;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_14 = 1;
  local_16 = 0x10;
  local_13 = 0;
  local_12 = 0;
  local_11 = 0;
  local_18 = 0x2300;
  local_4 = 0;
  local_10 = param_1;
  uStack_c = (uint)param_2;
  local_8 = param_3 & 0xff;
  FUN_00281260(&local_18,0x18);
  if (PTR_DAT_004028b8[(ulong)param_1 * 0x10] == '\0') {
    uVar1 = 0x6c;
    FUN_00194dd8(0x2300,0x11,"Init() has not been called yet");
  }
  else {
    uVar1 = (**(code **)(**(long **)(PTR_DAT_004028b8 + (ulong)param_1 * 0x10 + 8) + 0x18))
                      (*(long **)(PTR_DAT_004028b8 + (ulong)param_1 * 0x10 + 8),(uint)param_2,
                       param_3 & 0xff);
  }
  local_13 = 0;
  local_14 = 4;
  local_12 = 0;
  local_18 = 0x2300;
  local_11 = 0;
  local_16 = 0x1f;
  FUN_00281260(&local_18,8);
  FUN_00281388(uVar1);
  return;
}

