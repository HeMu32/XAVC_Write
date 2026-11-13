// FUN_00326818
// Ghidra address: 00326818

/* WARNING: Type propagation algorithm not settling */

int FUN_00326818(undefined8 param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  uint uVar8;
  uchar local_70 [4];
  uint local_6c;
  long local_68;
  long local_60 [2];
  undefined4 local_50;
  undefined8 local_48;
  undefined4 local_40;
  ulong local_38;
  ulong local_30;
  undefined8 local_28;
  undefined8 local_20;
  ulong local_18;
  uchar *local_10;
  undefined8 local_8;
  
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  uVar2 = FUN_00325f20(param_1,*(undefined4 *)((long)param_2 + 0x54));
  uVar3 = FUN_00325ff4(param_1,*(undefined4 *)((long)param_2 + 0x54));
  iVar4 = FUN_0032637c(param_1,*(undefined4 *)((long)param_2 + 0x54));
  local_6c = 0;
  iVar5 = FUN_003265cc(param_1,iVar4 * *(int *)(param_2 + 0x15),uVar3,uVar2);
  if (iVar5 != 0) {
    return iVar5;
  }
  if (*(int *)(param_2 + 0x10) != 0) {
    local_20 = local_20 & 0xffffffff00000000;
    iVar5 = FUN_003265cc(param_1,*(int *)(param_2 + 0x10),90000,uVar2);
    if (iVar5 != 0) {
      return iVar5;
    }
    local_38 = local_20 & 0xffffffff;
    local_28._2_6_ = (uint6)((ulong)local_28 >> 0x10) & 0xffffffff0000;
    local_30 = 0xffffffffffffffff;
    local_28 = CONCAT62(local_28._2_6_,1);
    FUN_002d55d0(*param_2,*(undefined4 *)((long)param_2 + 0x14),&local_38);
    iVar5 = FUN_00322428();
    if (iVar5 != 0) {
      return iVar5;
    }
  }
  local_38 = (ulong)local_6c;
  local_28._2_6_ = (uint6)((ulong)local_28 >> 0x10) & 0xffffffff0000;
  local_30 = (ulong)(uint)(iVar4 * *(int *)(param_2 + 0xd));
  local_28 = CONCAT62(local_28._2_6_,1);
  FUN_002d55d0(*param_2,*(undefined4 *)((long)param_2 + 0x14),&local_38);
  iVar4 = FUN_00322428();
  if (iVar4 != 0) {
    return iVar4;
  }
  uVar8 = 4;
  if (*(int *)(param_2 + 0xf) != 4) {
    uVar8 = 1;
  }
  if (*(int *)((long)param_2 + 0x84) != 0) {
    local_20 = local_20 & 0xffffffff00000000;
    iVar4 = FUN_003265cc(param_1,*(int *)((long)param_2 + 0x84),90000,uVar2,&local_20);
    if (iVar4 != 0) {
      return iVar4;
    }
    local_38 = local_20 & 0xffffffff;
    local_28 = CONCAT44(local_28._4_4_,1);
    local_30 = 0xffffffffffffffff;
    for (uVar6 = 0; (uint)uVar6 < uVar8; uVar6 = (ulong)(byte)((char)uVar6 + 1)) {
      lVar7 = (long)param_2 + uVar6 * 4 + 0x10;
      FUN_002d55d0(*param_2,*(undefined4 *)(lVar7 + 8),&local_38);
      iVar4 = FUN_00322428();
      if (iVar4 != 0) goto LAB_003269cc;
    }
  }
  uVar1 = *(uint *)((long)param_2 + 0x6c);
  iVar4 = 0x400;
  if ((uVar1 & 2) != 0) {
    iVar4 = 1;
  }
  uVar3 = 24000;
  if (((uVar1 >> 0x10 & 1) == 0) && (uVar3 = 48000, (uVar1 >> 0x11 & 1) == 0)) {
    uVar3 = 96000;
    if ((uVar1 & 0x40000) == 0) {
      uVar3 = 0x2ee00;
    }
  }
  local_20 = local_20 & 0xffffffff00000000;
  iVar4 = FUN_003265cc(param_1,iVar4 * *(int *)((long)param_2 + 0xac),uVar3,uVar2,&local_20);
  if (iVar4 != 0) {
    return iVar4;
  }
  local_38 = local_20 & 0xffffffff;
  uVar6 = 0;
  local_28._2_6_ = (uint6)((ulong)local_28 >> 0x10) & 0xffffffff0000;
  local_30 = 0;
  local_28 = CONCAT62(local_28._2_6_,1);
  while( true ) {
    if (uVar8 <= (uint)uVar6) {
      if (*(int *)(param_2 + 0x10) != 0) {
        local_20 = local_20 & 0xffffffff00000000;
        iVar4 = FUN_003265cc(param_1,*(int *)(param_2 + 0x10),90000,uVar2,&local_20);
        if (iVar4 != 0) {
          return iVar4;
        }
        local_38 = local_20 & 0xffffffff;
        local_28._2_6_ = (uint6)((ulong)local_28 >> 0x10) & 0xffffffff0000;
        local_30 = 0xffffffffffffffff;
        local_28 = CONCAT62(local_28._2_6_,1);
        FUN_002d55d0(*param_2,*(undefined4 *)((long)param_2 + 0x2c),&local_38);
        iVar4 = FUN_00322428();
        if (iVar4 != 0) {
          return iVar4;
        }
      }
      local_38 = (ulong)local_6c;
      local_30 = 0;
      local_28 = CONCAT44(local_28._4_4_,1);
      FUN_002d55d0(*param_2,*(undefined4 *)((long)param_2 + 0x2c),&local_38);
      iVar4 = FUN_00322428();
      if (iVar4 != 0) {
        return iVar4;
      }
      local_68 = 0;
      local_60[1] = 0;
      local_50 = 0;
      FUN_0032658c(param_1,param_2 + 6,local_60 + 1);
      FUN_002c7668(param_2[0x14],local_60 + 1,&local_68);
      local_48 = 0;
      local_40 = 0;
      local_68 = local_68 + (long)(int)*(short *)(param_2 + 6) * -0x3c;
      local_60[0] = 0;
      FUN_0032658c(param_1,param_2 + 1,&local_48);
      FUN_002c7668(param_2[0x14],&local_48,local_60);
      local_60[0] = local_60[0] + (long)(int)*(short *)(param_2 + 6) * -0x3c;
      FUN_002d94f8(*param_2,0,0xffffffff,local_68);
      local_70[0] = '\0';
      local_70[1] = '\0';
      local_20 = 0;
      local_18 = 0;
      local_10 = (uchar *)0x0;
      local_8 = 0;
      mpr::pconv::SetUInt16be(local_70,*(ushort *)(param_2 + 6));
      local_20 = CONCAT35(local_20._5_3_,0x100000000);
      local_20 = CONCAT44(local_20._4_4_,0xb);
      local_18 = local_18 & 0xffffffffffff0000;
      local_20 = CONCAT26(0x55c4,(undefined6)local_20);
      local_8 = CONCAT44(local_8._4_4_,2);
      local_10 = local_70;
      FUN_002d83b8(*param_2,0,&local_20);
      iVar4 = FUN_00322428();
      return iVar4;
    }
    lVar7 = (long)param_2 + uVar6 * 4 + 0x10;
    FUN_002d55d0(*param_2,*(undefined4 *)(lVar7 + 8),&local_38);
    iVar4 = FUN_00322428();
    if (iVar4 != 0) break;
    uVar6 = (ulong)(byte)((char)uVar6 + 1);
  }
LAB_003269cc:
  printf("[%s] ERROR! TackIndex:%d\n","MakeMovieInternal",(ulong)*(uint *)(lVar7 + 8));
  return iVar4;
}

