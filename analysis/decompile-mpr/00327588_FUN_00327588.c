// FUN_00327588
// Ghidra address: 00327588

/* WARNING: Type propagation algorithm not settling */

undefined8
FUN_00327588(undefined8 param_1,undefined8 param_2,ulong param_3,int param_4,long param_5,
            undefined4 *param_6)

{
  undefined8 uVar1;
  long lVar2;
  ulong uVar3;
  int local_14;
  long local_10 [2];
  
  local_10[0] = 0;
  if (param_3 == 0xffffffffffffffff) {
    FUN_002cfce4(param_2,*(undefined4 *)(param_5 + 4),0);
  }
  else {
    uVar3 = (ulong)(*(int *)(param_5 + 0x24) + 90000);
    lVar2 = param_3 - uVar3;
    if (param_3 < uVar3) {
      lVar2 = 0;
    }
    FUN_00326cfc(param_1,lVar2,90000,*(undefined4 *)(param_5 + 0x18),local_10);
  }
  if (local_10[0] == 0 && param_4 == 0) {
    *param_6 = 1;
    uVar1 = 0;
  }
  else {
    local_14 = 0;
    local_10[1] = 0;
    FUN_002cf380(param_2,*(undefined4 *)(param_5 + 4),local_10[0],param_4,&local_14,param_6,
                 local_10 + 1);
    uVar1 = FUN_00322428();
    if (local_14 == 0) {
      FUN_002cf204(param_2,*(undefined4 *)(param_5 + 4),*param_6,param_4,param_6,local_10 + 1);
      uVar1 = FUN_00322428();
      return uVar1;
    }
  }
  return uVar1;
}

