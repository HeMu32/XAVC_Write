// FUN_00323cc0
// Ghidra address: 00323cc0

undefined8 FUN_00323cc0(undefined8 param_1,undefined8 param_2,undefined4 param_3,long param_4)

{
  undefined8 uVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 uStack_c;
  int local_8;
  
  local_8 = *(int *)(param_4 + 0xc);
  local_14 = 0;
  uStack_c = param_3;
  if (local_8 == 0x68766331) {
    local_10 = 0x56505246;
    FUN_002d3f48(param_2,&local_10,&local_14);
    uVar1 = FUN_00322428();
    if ((int)uVar1 == 0) {
      uVar1 = FUN_00323a0c(param_1,param_2,local_14,param_4);
    }
  }
  else {
    uVar1 = 0;
    if ((local_8 == 0x61766331) && (*(int *)(param_4 + 0x34) == 1)) {
      local_10 = 0x56505246;
      FUN_002d3f48(param_2,&local_10,&local_14);
      uVar1 = FUN_00322428();
      if ((int)uVar1 == 0) {
        uVar1 = FUN_00323af0(param_1,param_2,local_14,param_4);
      }
    }
  }
  return uVar1;
}

