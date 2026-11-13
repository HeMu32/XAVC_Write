// FUN_00325eb0
// Ghidra address: 00325eb0

void FUN_00325eb0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                 undefined8 param_5)

{
  int iVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  undefined8 local_8;
  
  local_8 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = FUN_00325db8(param_1,param_5,&local_28);
  if (iVar1 == 0) {
    local_28 = CONCAT44(local_28._4_4_,param_4);
    FUN_002d3bb8(param_2,&local_28);
    FUN_00322428();
    return;
  }
  return;
}

