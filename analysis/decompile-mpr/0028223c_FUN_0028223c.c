// FUN_0028223c
// Ghidra address: 0028223c

void FUN_0028223c(uint param_1,ushort param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  uint local_8;
  uint local_4;
  
  local_c = 2;
  local_e = 0xf0;
  local_b = 0;
  local_a = 0;
  local_9 = 0;
  local_10 = 0x2300;
  local_8 = param_1;
  local_4 = (uint)param_2;
  FUN_00281260(&local_10,0x10);
  if (PTR_DAT_004028b8[(ulong)param_1 * 0x10] == '\0') {
    uVar1 = 0x6c;
    FUN_00194dd8(0x2300,0xf1,"Init() has not been called yet");
  }
  else {
    uVar1 = (**(code **)(**(long **)(PTR_DAT_004028b8 + (ulong)param_1 * 0x10 + 8) + 0x68))
                      (*(long **)(PTR_DAT_004028b8 + (ulong)param_1 * 0x10 + 8),(uint)param_2,
                       param_3);
  }
  local_b = 0;
  local_c = 3;
  local_a = 0;
  local_10 = 0x2300;
  local_9 = 0;
  local_e = 0xff;
  local_8 = *param_3;
  FUN_00281260(&local_10,0xc);
  FUN_00281388(uVar1);
  return;
}

