// FUN_00298174
// Ghidra address: 00298174

int FUN_00298174(long *param_1,long param_2,uint param_3)

{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  uint *puVar11;
  long lVar12;
  int *piVar13;
  uint uVar14;
  uint uVar15;
  undefined8 uVar16;
  int iVar17;
  uint uVar18;
  ulong uVar19;
  
  iVar9 = (**(code **)(*param_1 + 0xa0))();
  if (iVar9 == 0) {
    uVar19 = 0;
    uVar18 = 0;
    iVar17 = 0;
    uVar14 = 0;
    uVar15 = 0;
    do {
      while( true ) {
        puVar10 = (uint *)param_1[0xc];
        if (*puVar10 <= uVar14) goto LAB_002983c4;
        uVar2 = uVar14 + 1;
        uVar6 = puVar10[(ulong)uVar14 + 8];
        if (uVar14 == *(uint *)(param_2 + uVar19 * 4)) break;
        uVar1 = (ulong)uVar18;
        uVar18 = uVar18 + 1;
        puVar10[uVar1 + 8] = uVar6 - iVar17;
        uVar14 = uVar2;
      }
      uVar7 = puVar10[(ulong)uVar2 + 8];
      if ((int)uVar19 == 0) {
        FUN_00291d44(param_1[6],uVar6);
      }
      else if (uVar15 != uVar6) {
        FUN_00291210(param_1[5],1,uVar15,uVar6 - uVar15);
        iVar9 = (**(code **)(*param_1 + 0xe0))(param_1,param_1[6],param_1[5]);
        if (iVar9 != 0) {
          FUN_0028bc28(param_1[1],2);
          uVar16 = 0x193;
          goto LAB_00298258;
        }
      }
      uVar3 = (int)uVar19 + 1;
      uVar19 = (ulong)uVar3;
      iVar17 = iVar17 + (uVar7 - uVar6);
      uVar14 = uVar2;
      uVar15 = uVar7;
    } while (param_3 != uVar3);
    puVar11 = (uint *)param_1[0xc];
    iVar9 = uVar2 - uVar18;
    uVar14 = *puVar11;
    puVar10 = puVar11 + uVar2;
    for (; iVar9 + uVar18 < uVar14; uVar18 = uVar18 + 1) {
      puVar11[(ulong)uVar18 + 8] = puVar10[8] - iVar17;
      puVar10 = puVar10 + 1;
    }
    uVar15 = puVar11[0x3a9f];
    lVar12 = param_1[5];
    puVar11[(ulong)uVar18 + 8] = puVar11[(ulong)uVar14 + 8] - iVar17;
    FUN_00291210(lVar12,1,uVar7,uVar15 - uVar7);
    iVar9 = (**(code **)(*param_1 + 0xe0))(param_1,param_1[6],param_1[5]);
    if (iVar9 == 0) {
      iVar9 = FUN_00292080(param_1[6],0x20,iVar17);
      if (iVar9 == 0) {
        puVar11 = (uint *)param_1[0xc];
        uVar14 = *puVar11;
        puVar11[3] = puVar11[3] - iVar17;
        puVar11[0x3a9f] = puVar11[0x3a9f] - iVar17;
        uVar19 = (ulong)(uVar18 + 1);
        puVar10 = puVar11 + uVar19 + 8;
        for (; (uint)uVar19 < uVar14 + 1; uVar19 = (ulong)((uint)uVar19 + 1)) {
          *puVar10 = 0;
          puVar10 = puVar10 + 1;
        }
        *puVar11 = uVar18;
LAB_002983c4:
        piVar13 = (int *)param_1[0xc];
        if ((*piVar13 == 0) && ((char)piVar13[1] == '\0')) {
          iVar5 = piVar13[2];
          iVar9 = piVar13[3];
          iVar8 = piVar13[0x3a9f];
          iVar4 = iVar17 + iVar9;
          FUN_00291d44(param_1[6],iVar5);
          FUN_00291210(param_1[5],1,iVar4,iVar8 - iVar9);
          iVar9 = (**(code **)(*param_1 + 0xe0))(param_1,param_1[6],param_1[5]);
          if (iVar9 != 0) {
            FUN_0028bc28(param_1[1],2);
            uVar16 = 0x1d1;
            goto LAB_00298258;
          }
          iVar4 = iVar4 - iVar5;
          iVar9 = FUN_00292080(param_1[6],0x20,iVar4);
          if (iVar9 != 0) {
            FUN_0028bc28(param_1[1],2);
            uVar16 = 0x1d8;
            goto LAB_00298258;
          }
          lVar12 = param_1[0xc];
          *(undefined4 *)(lVar12 + 0xc) = 0;
          *(int *)(lVar12 + 0xea7c) = (iVar17 + *(int *)(lVar12 + 0xea7c)) - iVar4;
        }
        iVar9 = FUN_00291d4c(param_1[6]);
        if (iVar9 == 0) {
          FUN_002917b8(param_1[0xb],param_2,param_3);
          return 0;
        }
        FUN_0028bc28(param_1[1],2);
        uVar16 = 0x1e7;
      }
      else {
        FUN_0028bc28(param_1[1],2);
        uVar16 = 0x1b0;
      }
    }
    else {
      FUN_0028bc28(param_1[1],2);
      uVar16 = 0x1a9;
    }
  }
  else {
    uVar16 = 0x172;
  }
LAB_00298258:
  FUN_00290aa4(2,"xavcIfo_PxMediaProfileParserImplState.cpp",uVar16,iVar9);
  return iVar9;
}

