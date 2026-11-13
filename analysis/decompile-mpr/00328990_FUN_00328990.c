// FUN_00328990
// Ghidra address: 00328990

/* WARNING: Type propagation algorithm not settling */

int FUN_00328990(long param_1,undefined8 param_2,undefined4 param_3,uint *param_4,uint *param_5,
                uint *param_6,undefined4 *param_7,int *param_8)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int local_a0 [2];
  undefined8 local_98;
  undefined8 local_90;
  long local_88 [2];
  int local_78 [2];
  long local_70;
  int local_68;
  undefined8 local_50;
  uint local_40;
  
  uVar3 = 0xb40;
  local_a0[0] = 0;
  local_98 = 0;
  FUN_00328950(param_1,*(undefined8 *)(param_1 + 0x108),local_a0);
  if (((local_a0[0] != 96000) && (uVar3 = 0x1680, local_a0[0] != 0x2ee00)) &&
     (uVar3 = 0x2d0, local_a0[0] != 24000)) {
    uVar3 = 0x5a0;
  }
  FUN_00326cfc(param_1,uVar3,local_a0[0],90000,&local_98);
  memset(local_78,0,0x78);
  local_a0[1] = 0;
  local_90 = 0;
  local_88[0] = 0;
  FUN_002cedb8(*(undefined8 *)(param_1 + 0x108),param_3,*param_4,1,local_78,0);
  iVar4 = FUN_00322428();
  if (iVar4 != 0) {
    return iVar4;
  }
  FUN_002cf9d0(*(undefined8 *)(param_1 + 0x108),param_3,*param_4,&local_90,local_a0 + 1);
  iVar4 = FUN_00322428();
  if (iVar4 != 0) {
    return iVar4;
  }
  uVar5 = 0;
  FUN_00326cfc(param_1,local_90,*(undefined4 *)(param_1 + 0x298),90000,local_88);
  local_88[0] = local_88[0] + 90000;
  uVar2 = 0;
  uVar6 = local_40;
  if (uVar3 != 0) {
    uVar2 = ((local_40 - 1) + uVar3) / uVar3;
  }
  for (; uVar5 != uVar2; uVar5 = uVar5 + 1) {
    uVar1 = uVar6;
    if (uVar3 < uVar6) {
      uVar1 = uVar3;
    }
    local_88[1] = 0;
    FUN_00326cfc(param_1,uVar1 * local_68,*(undefined4 *)(param_1 + 0x298),90000,local_88 + 1);
    *param_8 = local_78[0] * uVar1;
    *(ulong *)(param_8 + 2) = (ulong)(local_78[0] * uVar3 * uVar5) + local_70;
    param_8[5] = (int)local_88[1];
    param_8[4] = (int)local_88[0] + uVar5 * (int)local_98;
    param_8 = param_8 + 8;
    uVar6 = uVar6 - uVar1;
  }
  uVar3 = *param_5;
  iVar4 = *(int *)(param_1 + 0x94);
  *param_5 = uVar3 | 1;
  if (iVar4 == 0) {
    if (*param_4 < *(uint *)(param_1 + 0x29c)) goto LAB_00328bb0;
  }
  else if ((iVar4 != 1) || (*param_4 != 1)) goto LAB_00328bb0;
  *param_5 = uVar3 | 0x11;
LAB_00328bb0:
  *param_4 = *param_4 + local_40;
  *param_6 = uVar5;
  *param_7 = (int)local_50;
  return 0;
}

