// FUN_00325020
// Ghidra address: 00325020

undefined4
FUN_00325020(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined4 local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  long local_c0;
  undefined4 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined4 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  long lStack_70;
  undefined4 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  ulong local_8;
  
  local_60 = 0;
  uStack_58 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_10 = 0;
  local_8 = 0;
  FUN_002c8ffc(param_2,param_3,&local_60);
  uVar1 = FUN_00322428();
  uStack_a8 = 0;
  local_b0 = 0xffff0000;
  local_a0 = 0xffff0000;
  local_100 = DAT_003db5f0;
  uStack_f8 = DAT_003db5f8;
  local_f0 = DAT_003db600;
  uStack_e8 = DAT_003db608;
  local_e0 = DAT_003db610;
  local_b8 = 0x40000000;
  uStack_d0 = 0xffff000000000000;
  local_68 = 0x40000000;
  local_c8 = 0;
  uStack_90 = 0x40000000;
  local_c0 = (local_8 & 0xffff) << 0x10;
  local_d8 = 0x1000000000000;
  local_88 = 0xffff000000000000;
  uStack_80 = 0x1000000000000;
  local_78 = 0;
  local_98._4_4_ = (undefined4)((local_8 & 0xffff) << 0x10);
  local_98 = (ulong)CONCAT42(local_98._4_4_,local_10._4_2_) << 0x10;
  lStack_70 = (ulong)local_10._4_2_ << 0x30;
  iVar2 = memcmp(&local_30,&local_100,0x24);
  uVar3 = 0;
  if (iVar2 != 0) {
    iVar2 = memcmp(&local_30,&local_d8,0x24);
    uVar3 = 0x5a;
    if (iVar2 != 0) {
      iVar2 = memcmp(&local_30,&local_b0,0x24);
      uVar3 = 0xb4;
      if (iVar2 != 0) {
        iVar2 = memcmp(&local_30,&local_88,0x24);
        uVar3 = 0x10e;
        if (iVar2 != 0) {
          uVar3 = 0xffffffff;
        }
      }
    }
  }
  *param_4 = uVar3;
  return uVar1;
}

