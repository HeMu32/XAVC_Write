// FUN_00326260
// Ghidra address: 00326260

void FUN_00326260(undefined8 param_1,undefined8 param_2,long param_3,undefined4 param_4,
                 undefined8 param_5,undefined4 *param_6,undefined8 param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_68 [2];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined4 local_8;
  
  local_60 = 0;
  FUN_002d4900(param_2);
  iVar1 = FUN_00322428();
  if (iVar1 == 0) {
    local_50 = 0;
    uStack_48 = 0;
    local_40 = 0;
    uStack_38 = 0;
    local_30 = 0;
    uStack_28 = 0;
    local_20 = 0;
    uStack_18 = 0;
    local_10 = 0;
    local_8 = 0;
    uVar2 = FUN_00325ff4(param_1,*(undefined4 *)(param_3 + 0x24));
    local_8 = CONCAT22(local_8._2_2_,0x55c4);
    local_10 = CONCAT44(uVar2,local_60);
    FUN_002d4fa0(param_2,&local_50,param_6);
    iVar1 = FUN_00322428();
    if (iVar1 == 0) {
      local_5c = 0;
      uStack_58 = 0x63647363;
      local_54 = param_4;
      FUN_002d54c4(param_2,*param_6,&uStack_58,&local_5c);
      iVar1 = FUN_00322428();
      if (iVar1 == 0) {
        local_68[0] = 0;
        iVar1 = FUN_003239e8(param_1,param_2,*param_6,local_68);
        if (iVar1 == 0) {
          FUN_002d61d4(param_2,*param_6,local_68,param_7);
          FUN_00322428();
          return;
        }
      }
    }
  }
  return;
}

