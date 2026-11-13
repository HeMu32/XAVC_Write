// FUN_003266cc
// Ghidra address: 003266cc

void FUN_003266cc(long param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  ulong local_48;
  undefined8 local_40;
  ulong local_38;
  ulong local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  undefined8 local_8;
  
  iVar6 = *param_2;
  iVar1 = param_2[1];
  uVar2 = *(undefined4 *)(param_1 + 0x3c);
  local_48 = CONCAT44(local_48._4_4_,iVar6 - iVar1);
  uVar4 = FUN_00325ff4(param_1,uVar2);
  FUN_003265cc(param_1,iVar6 - iVar1,90000,uVar4,&local_48);
  uVar5 = FUN_0032637c(param_1,uVar2);
  uVar3 = 0;
  if (uVar5 != 0) {
    uVar3 = (uint)local_48 / uVar5;
  }
  uVar3 = uVar3 * uVar5;
  if (uVar5 >> 1 < (uint)local_48 - uVar3) {
    uVar3 = 0;
    if (uVar5 != 0) {
      uVar3 = (((uint)local_48 - 1) + uVar5) / uVar5;
    }
    local_48 = (ulong)(uVar3 * uVar5);
  }
  else if ((uint)local_48 != uVar3) {
    local_48 = (ulong)uVar3;
  }
  uVar2 = (uint)local_48;
  local_8 = 0;
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_48 = (ulong)(uint)param_2[4];
  local_40 = *(undefined8 *)(param_2 + 6);
  uVar4 = FUN_0032637c(param_1,*(undefined4 *)(param_1 + 0x3c));
  local_38 = (ulong)CONCAT14((char)param_2[8],uVar4);
  local_28 = CONCAT44(local_28._4_4_,*(undefined4 *)(param_1 + 0xbc));
  local_30 = CONCAT44(uVar2,(int)local_30) & 0xffffffffffffff00;
  FUN_002d9c58(*(undefined8 *)(param_1 + 0xb0),*(undefined4 *)(param_1 + 0xb8),&local_48,0);
  FUN_00322428();
  if (*(char *)((long)param_2 + 0x21) != '\0') {
    FUN_002d9ca0(*(undefined8 *)(param_1 + 0xb0),*(undefined4 *)(param_1 + 0xb8));
    iVar6 = FUN_00322428();
    if (iVar6 != 0) {
      return;
    }
  }
  *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xc0) + 1;
  return;
}

