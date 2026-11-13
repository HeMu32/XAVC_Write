// FUN_00327f20
// Ghidra address: 00327f20

int FUN_00327f20(long param_1,undefined8 param_2,undefined4 param_3,int param_4,ulong param_5,
                int *param_6,ulong *param_7,ulong *param_8,undefined1 *param_9)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  undefined4 local_140;
  undefined4 local_13c;
  undefined8 local_138;
  ulong local_130;
  undefined8 local_128;
  int local_120 [2];
  undefined8 local_118;
  undefined8 uStack_110;
  ulong local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined1 auStack_f0 [120];
  undefined1 auStack_78 [120];
  
  *param_6 = 0;
  *param_7 = 0;
  *param_8 = 0;
  *param_9 = 0;
  lVar5 = 0;
  iVar6 = 0;
  local_118 = 0;
  uStack_110 = 0;
  local_f8 = 0;
  local_108 = 0;
  uStack_100 = 0;
  FUN_002c9120(param_2,param_3,&local_118);
  local_140 = 0;
  local_138 = 0;
  FUN_002cf9d0(param_2,param_3,param_4,&local_138,&local_140);
  memset(auStack_f0,0,0x78);
  bVar1 = true;
  FUN_002cedb8(param_2,param_3,param_4,0,auStack_f0,0);
  iVar3 = FUN_00322428();
  FUN_00326cfc(param_1,local_138,local_108 & 0xffffffff,90000,param_7);
  local_13c = 0;
  local_120[1] = 1;
  local_130 = *param_7 + 90000;
  *param_7 = local_130;
  local_128 = 0;
  local_120[0] = 0x5a0;
  iVar4 = param_4;
  do {
    bVar2 = bVar1;
    if (bVar1) {
      iVar4 = 0;
      if (iVar6 != 0) {
        iVar4 = iVar6 * 0x5a0 + -0x5a0;
      }
      local_130 = *param_7;
      iVar4 = iVar4 + param_4;
      while (bVar2 = bVar1, local_130 < param_5) {
        memset(auStack_78,0,0x78);
        FUN_002cedb8(param_2,param_3,iVar4,0,auStack_78,0);
        iVar3 = FUN_00322428();
        if (iVar3 != 0) break;
        FUN_002cf9d0(*(undefined8 *)(param_1 + 0x108),param_3,iVar4,&local_128,&local_13c);
        iVar3 = FUN_00322428();
        FUN_00326cfc(param_1,local_128,local_108 & 0xffffffff,90000,&local_130);
        local_130 = local_130 + 90000;
        bVar2 = param_5 != local_130;
        if (param_5 <= local_130) break;
        iVar6 = iVar6 + 1;
        iVar4 = iVar4 + *(int *)((long)local_120 + lVar5);
      }
    }
    bVar1 = bVar2;
    lVar5 = lVar5 + 4;
    if (lVar5 == 8) {
      *param_6 = iVar4;
      *param_8 = local_130;
      if (iVar3 == 4) {
        iVar3 = 0;
      }
      return iVar3;
    }
  } while( true );
}

