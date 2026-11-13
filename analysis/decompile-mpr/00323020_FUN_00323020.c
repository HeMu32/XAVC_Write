// FUN_00323020
// Ghidra address: 00323020

void FUN_00323020(long param_1,uint *param_2)

{
  undefined4 uVar1;
  int iVar2;
  ulong local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined8 uStack_30;
  ulong local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  undefined8 local_8;
  
  local_8 = 0;
  uStack_30 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_48 = (ulong)*param_2;
  local_40 = *(undefined8 *)(param_2 + 2);
  uVar1 = 1;
  if ((*(uint *)(param_1 + 0x54) & 2) == 0) {
    uVar1 = 0x400;
  }
  _local_38 = CONCAT44(1,uVar1);
  local_28 = (ulong)*(uint *)(param_1 + 0xd8);
  FUN_002d9c58(*(undefined8 *)(param_1 + 0xb0),*(undefined4 *)(param_1 + 0xc4),&local_48,0);
  iVar2 = FUN_00322428();
  if ((iVar2 == 0) &&
     (*(int *)(param_1 + 0xdc) = *(int *)(param_1 + 0xdc) + 1, (char)param_2[4] != '\0')) {
    FUN_002d9ca0(*(undefined8 *)(param_1 + 0xb0),*(undefined4 *)(param_1 + 0xc4));
    FUN_00322428();
    return;
  }
  return;
}

