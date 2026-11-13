// FUN_003230e0
// Ghidra address: 003230e0

void FUN_003230e0(long param_1,undefined8 param_2,undefined4 param_3,int param_4,uint param_5)

{
  long lVar1;
  uint uVar2;
  int local_28;
  undefined4 uStack_24;
  undefined8 local_20;
  ulong local_18;
  undefined8 uStack_10;
  ulong local_8;
  
  lVar1 = param_1 + (ulong)param_5 * 4;
  uStack_10 = 0;
  uVar2 = 0x400;
  if ((*(uint *)(param_1 + 0x54) & 2) != 0) {
    uVar2 = 1;
  }
  local_18 = (ulong)uVar2;
  local_8 = (ulong)*(uint *)(param_1 + 0xd8);
  local_28 = param_4;
  uStack_24 = param_3;
  local_20 = param_2;
  FUN_002d9c7c(*(undefined8 *)(param_1 + 0xb0),*(undefined4 *)(lVar1 + 0xc4),&local_28,0);
  FUN_00322428();
  *(int *)(lVar1 + 0xdc) = *(int *)(lVar1 + 0xdc) + param_4;
  return;
}

