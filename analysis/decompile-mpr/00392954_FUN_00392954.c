// FUN_00392954
// Ghidra address: 00392954

void FUN_00392954(undefined4 param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4,
                 undefined4 *param_5,undefined4 *param_6,undefined8 param_7)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 local_20;
  undefined5 uStack_18;
  undefined3 uStack_13;
  undefined5 local_10;
  undefined2 uStack_b;
  undefined1 uStack_9;
  undefined8 uStack_8;
  
  local_20 = 0;
  uStack_18 = 0;
  uStack_13 = 0;
  local_10 = 0;
  uStack_b = 0;
  uStack_9 = 0;
  uStack_8 = 0;
  iVar2 = memcmp(&local_20,param_3,0x20);
  if (iVar2 == 0) {
    *param_5 = 0;
    *param_6 = 0;
  }
  else {
    local_20 = *param_3;
    uStack_18 = (undefined5)param_3[1];
    uStack_13 = (undefined3)((ulong)param_3[1] >> 0x28);
    uVar1 = param_3[2];
    uStack_8 = param_3[3];
    local_10 = (undefined5)uVar1;
    uStack_b = (undefined2)((ulong)uVar1 >> 0x28);
    uStack_9 = (undefined1)((ulong)uVar1 >> 0x38);
    FUN_003cd6b0(&local_20,param_4);
    uStack_13 = 0;
    local_10 = 0;
    uStack_b = 0;
    uStack_9 = 0;
    iVar2 = sidb::SearchArrayBinaryRecord(param_1,2,&local_20,0x20,param_5,param_6);
    if (iVar2 != 0) {
      sidb::CreateArrayBinaryRecord(param_1,2,param_2,&local_20,0x20,param_5,param_6,param_7);
    }
  }
  return;
}

