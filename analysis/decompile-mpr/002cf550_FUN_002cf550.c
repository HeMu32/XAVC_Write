// FUN_002cf550
// Ghidra address: 002cf550

int FUN_002cf550(undefined8 *param_1,int param_2,undefined8 param_3,undefined4 param_4,
                undefined4 param_5,undefined8 *param_6,long param_7)

{
  int iVar1;
  int iVar2;
  undefined4 local_8c;
  undefined4 local_88;
  int local_84;
  undefined8 local_80;
  undefined1 auStack_78 [120];
  
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  iVar1 = 1;
  if ((param_1 != (undefined8 *)0x0 && param_2 != 0) &&
     (iVar1 = 1, param_6 != (undefined8 *)0x0 && param_7 != 0)) {
    FUN_002dd7a4(*param_1,auStack_78,0,0x78);
    iVar1 = FUN_002efdd8(param_1[0x38],param_2,0);
    if ((iVar1 == 0) &&
       (iVar2 = FUN_002e322c(param_1,param_2,param_3,param_4,&local_84), iVar1 = iVar2, iVar2 == 0))
    {
      if (local_84 == 0) {
        iVar1 = FUN_002e32ec(param_1);
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = FUN_002cf380(param_1,param_2,param_3,param_4,&local_8c,&local_88,&local_80);
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = FUN_002cedb8(param_1,param_2,local_88,param_5,auStack_78,0);
      }
      else {
        iVar1 = FUN_002e3350(param_1,param_2);
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = FUN_002e5778(param_1,param_2,param_3,param_4,param_5,&local_80,auStack_78);
      }
      if (iVar1 == 0) {
        FUN_002dd78c(*param_1,param_7,0x78,auStack_78);
        *param_6 = local_80;
        iVar1 = iVar2;
      }
    }
  }
  return iVar1;
}

