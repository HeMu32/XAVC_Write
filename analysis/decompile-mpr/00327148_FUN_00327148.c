// FUN_00327148
// Ghidra address: 00327148

int FUN_00327148(long param_1,undefined8 param_2,undefined4 param_3,uint *param_4,uint *param_5,
                uint *param_6,undefined4 *param_7,undefined4 *param_8)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_94;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined4 local_78 [2];
  undefined8 local_70;
  undefined8 local_50;
  uint local_40;
  
  memset(local_78,0,0x78);
  FUN_002cedb8(*(undefined8 *)(param_1 + 0x108),param_3,*param_4,1,local_78,0);
  iVar4 = FUN_00322428();
  uVar3 = local_40;
  if (iVar4 != 0) {
    return iVar4;
  }
  local_94 = 0;
  local_80 = 0;
  puVar1 = param_8 + (ulong)local_40 * 8;
  local_90 = 0;
  local_88 = 90000;
  for (; param_8 != puVar1; param_8 = param_8 + 8) {
    FUN_002cedb8(*(undefined8 *)(param_1 + 0x108),param_3,*param_4,0,local_78,0);
    iVar4 = FUN_00322428();
    if (iVar4 != 0) {
      return iVar4;
    }
    FUN_002cf9d0(*(undefined8 *)(param_1 + 0x108),param_3,*param_4,&local_90,&local_94);
    iVar4 = FUN_00322428();
    if (iVar4 != 0) {
      return iVar4;
    }
    FUN_00326cfc(param_1,local_90,*(undefined4 *)(param_1 + 0x298),90000,&local_88);
    FUN_00326cfc(param_1,local_94,*(undefined4 *)(param_1 + 0x298),90000,&local_80);
    *param_8 = local_78[0];
    *(undefined8 *)(param_8 + 2) = local_70;
    param_8[5] = (int)local_80;
    param_8[4] = (int)local_88;
  }
  uVar2 = *param_5;
  iVar4 = *(int *)(param_1 + 0x94);
  *param_5 = uVar2 | 1;
  if (iVar4 == 0) {
    if (*param_4 < *(uint *)(param_1 + 0x29c)) goto LAB_003272e8;
  }
  else if ((iVar4 != 1) || (*param_4 != 1)) goto LAB_003272e8;
  *param_5 = uVar2 | 0x11;
LAB_003272e8:
  *param_4 = *param_4 + local_40;
  *param_6 = uVar3;
  *param_7 = (int)local_50;
  return 0;
}

