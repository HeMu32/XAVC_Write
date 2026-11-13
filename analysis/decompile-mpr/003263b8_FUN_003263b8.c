// FUN_003263b8
// Ghidra address: 003263b8

void FUN_003263b8(long param_1,undefined8 param_2,uint *param_3)

{
  undefined4 uVar1;
  ulong local_48;
  undefined8 local_40;
  undefined8 local_38;
  ulong local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  undefined8 local_8;
  
  local_8 = 0;
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_48 = (ulong)*param_3;
  local_40 = *(undefined8 *)(param_3 + 2);
  uVar1 = FUN_0032637c(param_1,*(undefined4 *)(param_1 + 0x3c));
  local_38 = CONCAT44(1,uVar1);
  local_28 = CONCAT44(local_28._4_4_,*(undefined4 *)(param_1 + 0xf4));
  local_30 = (local_30 >> 8 & 0xffffff) << 8;
  FUN_002d9c58(*(undefined8 *)(param_1 + 0xb0),*(undefined4 *)(param_1 + 0xf0),&local_48,0);
  FUN_00322428();
  if ((char)param_3[4] != '\0') {
    FUN_002d9ca0(*(undefined8 *)(param_1 + 0xb0),*(undefined4 *)(param_1 + 0xf0));
    FUN_00322428();
    return;
  }
  return;
}

