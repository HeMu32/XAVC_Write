// FUN_00324440
// Ghidra address: 00324440

void FUN_00324440(undefined8 param_1,undefined8 param_2,long param_3,undefined4 param_4,
                 undefined8 param_5,undefined4 *param_6)

{
  int iVar1;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined8 uStack_8;
  
  local_38 = 0;
  uStack_30 = 0;
  local_3c = 0;
  local_28 = 0;
  iVar1 = FUN_003240cc();
  if (iVar1 == 0) {
    FUN_002d5928(param_2,param_4,&local_38,&local_3c);
    local_20 = 0;
    uStack_18 = 0;
    if (*(int *)(param_3 + 0xc) == 0x61766331) {
      FUN_003241d8(param_1,param_2,param_3,param_4,local_3c,&local_20);
      FUN_002d71b0(param_2,param_4,local_3c,&local_20);
    }
    else {
      local_10 = 0;
      uStack_8 = 0;
      FUN_00324308(param_1,param_2,param_3,param_4,local_3c,&local_20);
      FUN_002d7658(param_2,param_4,local_3c,&local_20);
    }
    FUN_00322428();
    *param_6 = local_3c;
  }
  return;
}

