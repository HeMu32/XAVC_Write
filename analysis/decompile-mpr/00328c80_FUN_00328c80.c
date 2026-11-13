// FUN_00328c80
// Ghidra address: 00328c80

void FUN_00328c80(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 local_88;
  undefined8 local_80;
  undefined4 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
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
  undefined8 uStack_8;
  
  *param_3 = 0;
  *(undefined4 *)(param_3 + 1) = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_10 = 0;
  uStack_8 = 0;
  FUN_00323748(param_1,0,&local_70);
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  FUN_002c73ac(&local_70,&local_88);
  iVar1 = FUN_00322428();
  if (iVar1 == 0) {
    FUN_002c7468(local_88,param_2,&local_80);
    iVar1 = FUN_00322428();
    FUN_002c7440(local_88);
    if (iVar1 == 0) {
      *(undefined2 *)((long)param_3 + 2) = (undefined2)local_80;
      *(char *)((long)param_3 + 4) = (char)((ulong)local_80 >> 0x10);
      *(char *)((long)param_3 + 5) = (char)((ulong)local_80 >> 0x20);
      *(char *)((long)param_3 + 6) = (char)((ulong)local_80 >> 0x30);
      *(char *)((long)param_3 + 7) = (char)local_78;
      *(char *)(param_3 + 1) = (char)((uint)local_78 >> 0x10);
    }
  }
  return;
}

