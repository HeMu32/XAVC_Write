// FUN_00327b38
// Ghidra address: 00327b38

undefined4
FUN_00327b38(long param_1,undefined8 param_2,undefined4 *param_3,long param_4,int param_5,
            int *param_6,undefined1 *param_7)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  long local_20;
  undefined8 local_18;
  undefined8 local_10;
  undefined8 local_8;
  
  param_6[0] = 0;
  param_6[1] = 0;
  param_6[2] = 0;
  param_6[3] = 0;
  param_6[4] = 0;
  param_6[5] = 0;
  param_6[6] = 0;
  param_6[7] = 0;
  *param_7 = 0;
  local_20 = 0;
  FUN_00327690(param_1,param_2,*param_3,param_5);
  local_30 = 0;
  local_18 = 0;
  uVar1 = FUN_003279c0(param_1,param_2,param_3,param_5,param_4,&local_30,&local_18,param_7);
  local_2c = 0;
  iVar2 = local_30;
  if (*(int *)(param_4 + 0xc) != 0) {
    if (param_5 == 1) {
      *param_7 = 1;
      iVar2 = local_2c;
    }
    else {
      if ((ulong)*(uint *)(param_4 + 0x10) < local_20 - 90000U) {
        local_10 = 0;
        FUN_00326cfc(param_1,(local_20 - 90000U) - (ulong)*(uint *)(param_4 + 0x10),90000,
                     *(undefined4 *)(param_1 + 0x1cc));
        local_28 = 0;
        local_24 = 0;
        local_8 = 0;
        iVar2 = FUN_002cf380(param_2,*param_3,local_10,1,&local_24,&local_28,&local_8);
        if ((iVar2 == 0) &&
           ((iVar2 = local_28, local_24 != 0 ||
            (iVar3 = FUN_002cf204(param_2,*param_3,local_28,0,&local_2c,&local_8), iVar2 = local_2c,
            iVar3 == 0)))) goto LAB_00327be0;
      }
      iVar2 = 1;
    }
  }
LAB_00327be0:
  local_2c = iVar2;
  *(long *)(param_6 + 4) = local_20;
  *param_6 = param_5;
  *(undefined8 *)(param_6 + 6) = local_18;
  param_6[1] = local_30;
  param_6[2] = local_2c;
  return uVar1;
}

