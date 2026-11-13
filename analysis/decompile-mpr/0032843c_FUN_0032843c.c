// FUN_0032843c
// Ghidra address: 0032843c

undefined8
FUN_0032843c(long param_1,int param_2,undefined4 *param_3,uint *param_4,int *param_5,int *param_6)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int local_78 [2];
  ulong local_70;
  uint local_40;
  
  if (*(int *)(param_1 + 0x90) == 0) {
    iVar6 = 0;
    iVar1 = *(int *)(param_1 + 0x2ec);
    uVar2 = 0;
    while (uVar5 = uVar2, iVar7 = iVar1, param_2 != 0) {
      memset(local_78,0,0x78);
      FUN_002cedb8(*(undefined8 *)(param_1 + 0x108),*(undefined4 *)(param_1 + 0x2b0),iVar7,1,
                   local_78,0);
      uVar3 = FUN_00322428();
      if ((int)uVar3 == 4) break;
      if ((int)uVar3 != 0) {
        return uVar3;
      }
      if ((uVar5 != 0) &&
         ((ulong)(uint)param_6[(ulong)(uVar5 - 1) * 6] +
          *(long *)(param_6 + (ulong)(uVar5 - 1) * 6 + 2) < local_70)) {
        *param_3 = 2;
        break;
      }
      uVar4 = 0;
      while( true ) {
        iVar1 = iVar7 + uVar4;
        uVar2 = uVar5 + uVar4;
        if (local_40 <= uVar4) break;
        uVar3 = FUN_00328348(param_1,*(undefined8 *)(param_1 + 0x108),param_1 + 0x2b0,iVar7 + uVar4,
                             param_6 + (ulong)(uVar5 + uVar4) * 6);
        uVar4 = uVar4 + 1;
        if ((int)uVar3 != 0) {
          return uVar3;
        }
        iVar6 = iVar6 + local_78[0];
      }
    }
    *(int *)(param_1 + 0x2ec) = iVar7;
  }
  else {
    uVar3 = FUN_00328348(param_1,*(undefined8 *)(param_1 + 0x108),param_1 + 0x2b0,
                         *(int *)(param_1 + 0x2ec),param_6);
    if ((int)uVar3 != 0) {
      return uVar3;
    }
    uVar5 = 1;
    iVar6 = *param_6;
    *(undefined4 *)(param_1 + 0x2ec) = *(undefined4 *)(param_1 + 0x2f0);
  }
  if (param_2 == 0) {
    *param_3 = 8;
  }
  *param_4 = uVar5;
  *param_5 = iVar6;
  return 0;
}

