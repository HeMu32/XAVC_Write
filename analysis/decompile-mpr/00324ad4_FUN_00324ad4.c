// FUN_00324ad4
// Ghidra address: 00324ad4

int FUN_00324ad4(long param_1,int param_2,undefined4 param_3,undefined8 param_4,uint *param_5)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  ulong local_10;
  undefined8 local_8;
  
  if (param_2 == 0x61766331) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    local_10 = local_10 & 0xffffffff00000000;
    FUN_002ccedc(*(undefined8 *)(param_1 + 0x108),param_4);
    iVar2 = FUN_00322428();
    if (iVar2 == 0) {
      *(undefined1 *)(param_5 + 2) = 1;
      *(char *)((long)param_5 + 9) = (char)local_20;
      *(char *)((long)param_5 + 10) = (char)((ulong)local_20 >> 0x20);
      if ((int)local_18 == 1) {
        *param_5 = (uint)local_18._4_1_;
        if (local_18._6_1_ == '\x02') {
          uVar3 = 10;
        }
        else if (local_18._6_1_ == '\x04') {
          uVar3 = 0xc;
        }
        else {
          uVar3 = 0x11;
          if (local_18._6_1_ == '\0') {
            uVar3 = 8;
          }
        }
      }
      else {
        *param_5 = 1;
        uVar3 = 8;
      }
      param_5[1] = uVar3;
      *(bool *)((long)param_5 + 0xd) = local_28._2_1_ == '\x10';
    }
  }
  else {
    local_8 = 0;
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    local_10 = 0;
    FUN_002cd6d8(*(undefined8 *)(param_1 + 0x108),param_4);
    iVar2 = FUN_00322428();
    if (iVar2 == 0) {
      *param_5 = (uint)local_18._5_1_;
      if (local_18._7_1_ == '\x02') {
        uVar3 = 10;
      }
      else if (local_18._7_1_ == '\x04') {
        uVar3 = 0xc;
      }
      else {
        uVar3 = 0x11;
        if (local_18._7_1_ == '\0') {
          uVar3 = 8;
        }
      }
      param_5[1] = uVar3;
      local_30 = 0;
      for (uVar3 = 1; uVar3 <= (uint)local_8; uVar3 = uVar3 + 1) {
        FUN_002cd828(*(undefined8 *)(param_1 + 0x108),param_4,param_3,uVar3,&local_30);
        iVar4 = FUN_00322428();
        if (iVar4 != 0) {
          return iVar4;
        }
        uVar1 = (undefined1)((ulong)local_30 >> 0x20);
        if (local_30._1_1_ == '!') {
          *(undefined1 *)(param_5 + 2) = 1;
          *(undefined1 *)((long)param_5 + 9) = uVar1;
        }
        else if (local_30._1_1_ == '\"') {
          *(undefined1 *)(param_5 + 2) = 1;
          *(undefined1 *)((long)param_5 + 10) = uVar1;
        }
        else if (local_30._1_1_ == ' ') {
          *(undefined1 *)((long)param_5 + 0xb) = 1;
          *(undefined1 *)(param_5 + 3) = uVar1;
        }
      }
    }
  }
  return iVar2;
}

