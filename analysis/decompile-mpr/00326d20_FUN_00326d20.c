// FUN_00326d20
// Ghidra address: 00326d20

ulong FUN_00326d20(long param_1,uint *param_2,int *param_3,int *param_4,int *param_5,
                  undefined4 *param_6)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  int iVar9;
  ulong uVar10;
  uint uVar11;
  int iVar12;
  undefined1 uVar13;
  undefined4 local_b4;
  undefined4 local_b0;
  int local_ac;
  long local_a8;
  long local_a0;
  long local_98;
  long local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined1 local_80;
  undefined1 local_7f;
  undefined1 local_7e;
  undefined1 local_7d;
  undefined1 local_7c;
  undefined1 local_7b;
  int local_78 [2];
  undefined8 local_70;
  uint local_68;
  int local_64;
  uint local_5c;
  int local_54;
  uint local_40;
  
  memset(local_78,0,0x78);
  FUN_002cedb8(*(undefined8 *)(param_1 + 0x108),*(undefined4 *)(param_1 + 0x1c8),
               *(undefined4 *)(param_1 + 0x2c0),1,local_78,&local_b4);
  uVar3 = FUN_00322428();
  if ((int)uVar3 == 4) {
    *param_2 = 0x10;
    *param_3 = 0;
    *param_4 = 0;
    return 0;
  }
  uVar10 = uVar3 & 0xffffffff;
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = local_b4;
  }
  uVar11 = 1;
  if ((*(int *)(param_1 + 0x90) == 0) && (uVar11 = local_40, 0x78 < local_40)) {
    uVar11 = 0x78;
  }
  iVar2 = *(int *)(param_1 + 0x2c0);
  iVar12 = 0;
  while( true ) {
    iVar9 = (int)uVar10;
    uVar1 = iVar9 + iVar2;
    if ((int)uVar11 <= iVar9) break;
    FUN_002cedb8(*(undefined8 *)(param_1 + 0x108),*(undefined4 *)(param_1 + 0x1c8),uVar1,0,local_78,
                 0);
    uVar3 = FUN_00322428();
    if ((int)uVar3 != 0) {
      return uVar3;
    }
    local_b0 = 0;
    local_a8 = 0;
    FUN_002cf9d0(*(undefined8 *)(param_1 + 0x108),*(undefined4 *)(param_1 + 0x1c8),uVar1,&local_a8,
                 &local_b0);
    uVar3 = FUN_00322428();
    if ((int)uVar3 != 0) {
      return uVar3;
    }
    local_ac = 0;
    FUN_003265cc(param_1,local_b0,*(undefined4 *)(param_1 + 0x1cc),90000,&local_ac);
    local_a0 = 0;
    FUN_00326cfc(param_1,local_a8,*(undefined4 *)(param_1 + 0x1cc),90000,&local_a0);
    local_98 = 0;
    FUN_00326cfc(param_1,(ulong)local_5c + local_a8,*(undefined4 *)(param_1 + 0x1cc),90000);
    local_90 = 0;
    uVar4 = (ulong)local_68;
    uVar3 = local_5c + uVar4 + local_a8;
    uVar10 = 0;
    if (uVar4 != 0) {
      uVar10 = uVar3 / uVar4;
    }
    if (uVar3 != uVar10 * uVar4) {
      uVar10 = 0;
      if (uVar4 != 0) {
        uVar10 = ((uVar4 - 1) + uVar3) / uVar4;
      }
      uVar3 = uVar4 * uVar10;
    }
    FUN_00326cfc(param_1,uVar3,*(undefined4 *)(param_1 + 0x1cc),90000,&local_90);
    uVar3 = (ulong)(uint)((*(int *)(param_1 + 0x1dc) + 90000) - *(int *)(param_1 + 0x1e0));
    local_a0 = local_a0 + uVar3;
    local_98 = local_98 + uVar3;
    local_90 = local_90 + uVar3;
    if (*(int *)(param_1 + 0x2c4) == local_54) {
      uVar6 = 0;
      uVar7 = 0;
      uVar8 = 0;
      uVar5 = 0;
      uVar13 = 0;
    }
    else {
      local_88 = 0;
      local_84 = 8;
      local_80 = 0;
      local_7f = 0;
      local_7e = 0;
      local_7d = 0;
      local_7c = 0;
      local_7b = 0;
      uVar3 = FUN_00324ad4(param_1,*(undefined4 *)(param_1 + 0x1d8),local_54,
                           *(undefined8 *)(param_1 + 0x260),&local_88);
      if ((int)uVar3 != 0) {
        return uVar3;
      }
      *(undefined4 *)(param_1 + 0x2c8) = local_88;
      *(undefined4 *)(param_1 + 0x2cc) = local_84;
      *(int *)(param_1 + 0x2c4) = local_54;
      uVar5 = local_7d;
      uVar8 = local_80;
      uVar7 = local_7f;
      uVar6 = local_7e;
      uVar13 = local_7c;
    }
    uVar10 = (ulong)(iVar9 + 1);
    *(undefined8 *)(param_5 + 2) = local_70;
    *param_5 = local_78[0];
    iVar12 = iVar12 + local_78[0];
    param_5[4] = (int)local_98;
    param_5[0xe] = (int)local_90;
    param_5[5] = (int)local_a0;
    param_5[6] = local_ac;
    param_5[7] = uVar1;
    param_5[8] = *(int *)(param_1 + 0x2c8);
    param_5[9] = *(int *)(param_1 + 0x2cc);
    *(bool *)(param_5 + 10) = uVar1 == 1;
    *(bool *)((long)param_5 + 0x29) = *(uint *)(param_1 + 0x1d0) == uVar1;
    *(bool *)((long)param_5 + 0x2a) = local_64 == 1;
    *(undefined1 *)((long)param_5 + 0x2b) = uVar8;
    *(undefined1 *)(param_5 + 0xd) = uVar7;
    *(undefined1 *)((long)param_5 + 0x35) = uVar6;
    *(undefined1 *)(param_5 + 0xb) = uVar5;
    *(undefined1 *)((long)param_5 + 0x36) = uVar13;
    param_5[0xc] = local_54;
    param_5 = param_5 + 0x10;
  }
  if (*(int *)(param_1 + 0x90) == 0) {
    FUN_002cedb8(*(undefined8 *)(param_1 + 0x108),*(undefined4 *)(param_1 + 0x1c8),uVar1,0,local_78,
                 0);
    uVar3 = FUN_00322428();
    uVar11 = *param_2;
    *param_2 = uVar11 | 2;
    if (local_64 == 1) {
      *param_2 = uVar11 | 3;
    }
    if ((int)uVar3 == 4) goto LAB_003270d4;
    if ((int)uVar3 != 0) {
      return uVar3;
    }
  }
  else {
LAB_003270d4:
    *param_2 = *param_2 | 1;
  }
  if (*(int *)(param_1 + 0x94) == 0) {
    if (uVar1 < *(uint *)(param_1 + 0x1d0)) goto LAB_00327108;
  }
  else if (*(int *)(param_1 + 0x94) != 1 || uVar1 != 1) goto LAB_00327108;
  *param_2 = *param_2 | 0x10;
LAB_00327108:
  *param_4 = iVar12;
  *param_3 = iVar9;
  if (*(int *)(param_1 + 0x90) == 1) {
    *(undefined4 *)(param_1 + 0x2c0) = *(undefined4 *)(param_1 + 0x2f0);
  }
  else {
    *(uint *)(param_1 + 0x2c0) = uVar1;
  }
  return 0;
}

