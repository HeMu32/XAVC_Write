// FUN_00297ba8
// Ghidra address: 00297ba8

int FUN_00297ba8(long *param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  uint *puVar5;
  uint uVar6;
  ulong uVar7;
  undefined8 uVar8;
  uint *puVar9;
  
  iVar2 = (**(code **)(*param_1 + 0x98))(param_1,param_3);
  if (iVar2 != 0) {
    uVar8 = 0x96;
    goto LAB_00297be8;
  }
  if (*(int *)param_1[0xc] == 0) {
    FUN_0029213c(param_1[9]);
    iVar2 = FUN_00294ba4(param_1[8],param_1[9]);
    if (iVar2 != 0) {
      FUN_0028bc28(param_1[1],2);
      uVar8 = 0xa9;
      goto LAB_00297be8;
    }
    iVar3 = FUN_002921b8(param_1[9]);
    iVar2 = (**(code **)(*param_1 + 0xd8))(param_1,param_1[9],*(undefined4 *)(param_1[0xc] + 8));
    if (iVar2 != 0) {
      FUN_0028bc28(param_1[1],2);
      uVar8 = 0xb3;
      goto LAB_00297be8;
    }
    lVar4 = param_1[0xc];
    *(int *)(lVar4 + 0xc) = iVar3 + *(int *)(lVar4 + 8);
    *(int *)(lVar4 + 0x20) = *(int *)(lVar4 + 8);
    iVar3 = iVar3 + *(int *)(lVar4 + 0xea7c);
    *(int *)(lVar4 + 0xea7c) = iVar3;
    if (*(uint *)(lVar4 + 0xea80) < 0x200000) {
      iVar2 = FUN_00292080(param_1[6],0x20,0x200000 - iVar3);
      if (iVar2 != 0) {
        FUN_0028bc28(param_1[1],2);
        uVar8 = 0xc4;
        goto LAB_00297be8;
      }
      *(undefined4 *)(param_1[0xc] + 0xea80) = 0x200000;
    }
    iVar2 = FUN_00291d4c(param_1[6]);
    if (iVar2 != 0) {
      FUN_0028bc28(param_1[1],2);
      uVar8 = 0xce;
      goto LAB_00297be8;
    }
  }
  FUN_0029213c(param_1[9]);
  iVar2 = FUN_0029552c(param_1[8],param_1[9],param_2);
  if (iVar2 == 0) {
    iVar3 = FUN_002921b8(param_1[9]);
    iVar2 = (**(code **)(*param_1 + 0xd8))
                      (param_1,param_1[9],*(undefined4 *)(param_1[0xc] + (ulong)param_3 * 4 + 0x20))
    ;
    if (iVar2 == 0) {
      puVar5 = (uint *)param_1[0xc];
      if (*puVar5 < 0x3a96) {
        uVar6 = *puVar5 + 1;
        uVar1 = uVar6;
        while (uVar7 = (ulong)uVar1, uVar1 != param_3) {
          uVar1 = uVar1 - 1;
          puVar5[uVar7 + 8] = puVar5[(ulong)uVar1 + 8] + iVar3;
        }
        *puVar5 = uVar6;
      }
      else {
        uVar6 = 0x3a96;
        puVar9 = puVar5 + 0x3a9e;
        while (uVar6 != param_3) {
          uVar6 = uVar6 - 1;
          *puVar9 = puVar5[(ulong)uVar6 + 8] + iVar3;
          puVar9 = puVar9 + -1;
        }
        *(undefined1 *)(puVar5 + 1) = 1;
      }
      puVar5[3] = puVar5[3] + iVar3;
      uVar6 = iVar3 + puVar5[0x3a9f];
      puVar5[0x3a9f] = uVar6;
      if (puVar5[0x3aa0] <= uVar6) {
        puVar5[0x3aa0] = uVar6 + 1;
        iVar2 = FUN_00292080(param_1[6],10,1);
        if (iVar2 != 0) {
          FUN_0028bc28(param_1[1],2);
          uVar8 = 0x105;
          goto LAB_00297be8;
        }
      }
      if (*(uint *)(param_1[0xc] + 0xea80) < 0x200000) {
        iVar2 = FUN_00292080(param_1[6],0x20,0x200000 - *(uint *)(param_1[0xc] + 0xea80));
        if (iVar2 != 0) {
          FUN_0028bc28(param_1[1],2);
          uVar8 = 0x110;
          goto LAB_00297be8;
        }
        *(undefined4 *)(param_1[0xc] + 0xea80) = 0x200000;
      }
      iVar2 = FUN_00291d4c(param_1[6]);
      if (iVar2 == 0) {
        FUN_00291c50(param_1[0xb],param_3,param_2);
        return 0;
      }
      FUN_0028bc28(param_1[1],2);
      uVar8 = 0x11c;
    }
    else {
      FUN_0028bc28(param_1[1],2);
      uVar8 = 0xe5;
    }
  }
  else {
    FUN_0028bc28(param_1[1],2);
    uVar8 = 0xdb;
  }
LAB_00297be8:
  FUN_00290aa4(2,"xavcIfo_PxMediaProfileParserImplState.cpp",uVar8,iVar2);
  return iVar2;
}

