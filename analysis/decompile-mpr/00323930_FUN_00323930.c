// FUN_00323930
// Ghidra address: 00323930

void FUN_00323930(undefined8 param_1,undefined8 param_2,uint param_3,uint param_4,uint param_5,
                 undefined4 param_6)

{
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  undefined8 uStack_8;
  
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  local_18 = 0;
  local_10 = 0;
  uStack_8 = 0;
  if (param_5 == 0x5a) {
    local_18 = (ulong)param_4;
    local_30 = 0x1000000000000;
    uStack_28 = 0xffff000000000000;
  }
  else if (param_5 < 0x5b) {
    if (param_5 != 0) goto LAB_00323968;
    local_30 = 0x10000;
    local_20 = 0x10000;
  }
  else if (param_5 == 0xb4) {
    local_18 = CONCAT44(param_4,param_3);
    local_30 = 0xffff0000;
    local_20 = 0xffff0000;
  }
  else {
    if (param_5 != 0x10e) goto LAB_00323968;
    local_18 = (ulong)param_3 << 0x20;
    local_30 = 0xffff000000000000;
    uStack_28 = 0x1000000000000;
  }
  local_10 = 0x40000000;
LAB_00323968:
  FUN_002d51a8(param_2,param_6,0x200,&local_60);
  FUN_00322428();
  return;
}

