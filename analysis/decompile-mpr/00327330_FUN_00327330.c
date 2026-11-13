// FUN_00327330
// Ghidra address: 00327330

ulong FUN_00327330(undefined8 param_1,undefined8 param_2,ulong *param_3,undefined4 *param_4,
                  uint *param_5,undefined1 *param_6)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  uint uVar6;
  undefined1 auStack_80 [8];
  ulong local_78 [2];
  int local_64;
  
  uVar5 = *param_3;
  *param_6 = 0;
  if (uVar5 == 0xffffffffffffffff) {
    uVar6 = param_4[2];
  }
  else {
    uVar6 = 1;
    if (89999 < uVar5) {
      uVar6 = param_4[0xc];
      FUN_00326cfc(param_1,uVar5 - 90000,90000,param_4[1],local_78);
      iVar4 = 0;
      if ((ulong)uVar6 != 0) {
        iVar4 = (int)(local_78[0] / uVar6);
      }
      uVar3 = FUN_00324968(param_1,iVar4 + 1,*(undefined8 *)(param_4 + 0x2c),
                           *(undefined1 *)((long)param_4 + 0xad));
      uVar6 = param_4[2];
      if (uVar3 < (uint)param_4[2]) {
        uVar6 = uVar3;
      }
    }
  }
  FUN_002cedb8(param_2,*param_4,uVar6,0,local_78,0);
  uVar3 = FUN_00322428();
  if (uVar3 == 0) {
    if (local_64 == 0) {
      *param_6 = 1;
      bVar1 = (int)param_3[1] != 0;
      bVar2 = *(int *)((long)param_3 + 0xc) != 1;
      iVar4 = FUN_002cf204(param_2,*param_4,uVar6,bVar1 && bVar2,param_5,auStack_80);
      if ((iVar4 != 1) &&
         ((iVar4 != 0x200 ||
          (iVar4 = FUN_002cf204(param_2,*param_4,uVar6,!bVar1 || !bVar2,param_5,auStack_80),
          iVar4 != 1)))) {
        uVar5 = FUN_00322428();
        return uVar5;
      }
      *param_5 = 1;
    }
    else {
      *param_5 = uVar6;
    }
  }
  return (ulong)uVar3;
}

