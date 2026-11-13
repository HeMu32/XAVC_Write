// FUN_003279c0
// Ghidra address: 003279c0

undefined4
FUN_003279c0(long param_1,undefined8 param_2,undefined4 *param_3,undefined4 param_4,long param_5,
            undefined4 *param_6,long *param_7,undefined1 *param_8)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_24;
  long local_20;
  long local_18;
  ulong local_10;
  long local_8;
  
  local_20 = 0;
  FUN_002cf9d0(param_2,*param_3,param_4,&local_20);
  iVar3 = 0;
  uVar1 = FUN_00322428();
  local_24 = 0;
  local_18 = 0;
  local_10 = 0;
  do {
    iVar3 = iVar3 + 1;
    iVar2 = FUN_002cf204(param_2,*param_3,param_4,1,&local_24,&local_18);
    param_4 = local_24;
    if (iVar2 != 0) {
      if (iVar2 == 0x200) {
        if (iVar3 == 1) {
          FUN_002cfadc(param_2,*param_3,0,&local_18);
          local_24 = *(undefined4 *)(param_1 + 0x1d0);
          if (*(int *)(param_5 + 0xc) == 0) {
            *param_8 = 1;
          }
        }
      }
      else {
        uVar1 = 2;
      }
      break;
    }
    FUN_00326cfc(param_1,local_18 - local_20,*(undefined4 *)(param_1 + 0x1cc),90000,&local_10);
  } while (local_10 < *(uint *)(param_5 + 0x10));
  local_8 = 0;
  FUN_00326cfc(param_1,local_18,param_3[1],90000);
  *param_7 = local_8 + 90000;
  *param_6 = local_24;
  return uVar1;
}

