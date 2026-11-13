// FUN_00323154
// Ghidra address: 00323154

void FUN_00323154(long param_1,undefined8 param_2,undefined4 param_3)

{
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  char *local_10;
  undefined8 local_8;
  
  local_28 = 0;
  local_20 = 0;
  local_18 = 0x6e72746d;
  local_10 = "Non-Real Time Metadata";
  local_8 = 0x17;
  FUN_002d334c(*(undefined8 *)(param_1 + 0xb0),1,&local_18);
  local_20 = CONCAT44(local_20._4_4_,param_3);
  local_28 = param_2;
  FUN_002d33a0(*(undefined8 *)(param_1 + 0xb0),1,&local_28);
  FUN_00322428();
  return;
}

