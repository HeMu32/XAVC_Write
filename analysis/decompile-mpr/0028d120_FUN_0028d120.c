// FUN_0028d120
// Ghidra address: 0028d120

int FUN_0028d120(long *param_1,long param_2,uint param_3,char param_4)

{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  long lVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  undefined8 uVar14;
  uint uVar15;
  int iVar16;
  ulong uVar17;
  
  iVar7 = (**(code **)(*param_1 + 0xa0))();
  if (iVar7 != 0) {
    uVar14 = 0x2c6;
    goto LAB_0028d20c;
  }
  uVar17 = 0;
  uVar15 = 0;
  iVar16 = 0;
  uVar12 = 0;
  uVar13 = 0;
  do {
    while( true ) {
      puVar8 = (uint *)param_1[0xc];
      if (*puVar8 <= uVar12) goto LAB_0028d3c4;
      uVar2 = uVar12 + 1;
      uVar4 = puVar8[(ulong)uVar12 + 8];
      if (uVar12 == *(uint *)(param_2 + uVar17 * 4)) break;
      uVar1 = (ulong)uVar15;
      uVar15 = uVar15 + 1;
      puVar8[uVar1 + 8] = uVar4 - iVar16;
      uVar12 = uVar2;
    }
    uVar5 = puVar8[(ulong)uVar2 + 8];
    if ((int)uVar17 == 0) {
      FUN_00291d44(param_1[6],uVar4);
    }
    else if (uVar13 != uVar4) {
      FUN_00291210(param_1[5],1,uVar13,uVar4 - uVar13);
      iVar7 = (**(code **)(*param_1 + 0xb0))(param_1,param_1[6],param_1[5],param_4);
      if (iVar7 != 0) {
        FUN_0028bc28(param_1[1],2);
        uVar14 = 0x2e7;
        goto LAB_0028d20c;
      }
    }
    uVar3 = (int)uVar17 + 1;
    uVar17 = (ulong)uVar3;
    iVar16 = iVar16 + (uVar5 - uVar4);
    uVar12 = uVar2;
    uVar13 = uVar5;
  } while (param_3 != uVar3);
  puVar9 = (uint *)param_1[0xc];
  iVar7 = uVar2 - uVar15;
  uVar12 = *puVar9;
  puVar8 = puVar9 + uVar2;
  for (; iVar7 + uVar15 < uVar12; uVar15 = uVar15 + 1) {
    puVar9[(ulong)uVar15 + 8] = puVar8[8] - iVar16;
    puVar8 = puVar8 + 1;
  }
  uVar13 = puVar9[0x3a9f];
  lVar10 = param_1[5];
  puVar9[(ulong)uVar15 + 8] = puVar9[(ulong)uVar12 + 8] - iVar16;
  FUN_00291210(lVar10,1,uVar5,uVar13 - uVar5);
  iVar7 = (**(code **)(*param_1 + 0xb0))(param_1,param_1[6],param_1[5],param_4);
  if (iVar7 != 0) {
    FUN_0028bc28(param_1[1],2);
    uVar14 = 0x2fd;
    goto LAB_0028d20c;
  }
  if (param_4 == '\0') {
    iVar7 = FUN_00292080(param_1[6],0x20,iVar16);
    if (iVar7 != 0) goto LAB_0028d31c;
    iVar7 = thunk_FUN_00291ea8(param_1[6]);
  }
  else {
    iVar7 = FUN_00292008();
    if (iVar7 != 0) {
LAB_0028d31c:
      FUN_0028bc28(param_1[1],2);
      uVar14 = 0x30a;
      goto LAB_0028d20c;
    }
    iVar7 = FUN_00291d4c(param_1[6]);
  }
  if (iVar7 != 0) {
    FUN_0028bc28(param_1[1],2);
    uVar14 = 0x317;
    goto LAB_0028d20c;
  }
  puVar9 = (uint *)param_1[0xc];
  uVar12 = *puVar9;
  puVar9[3] = puVar9[3] - iVar16;
  puVar9[0x3a9f] = puVar9[0x3a9f] - iVar16;
  uVar17 = (ulong)(uVar15 + 1);
  puVar8 = puVar9 + uVar17 + 8;
  for (; (uint)uVar17 < uVar12 + 1; uVar17 = (ulong)((uint)uVar17 + 1)) {
    *puVar8 = 0;
    puVar8 = puVar8 + 1;
  }
  *puVar9 = uVar15;
LAB_0028d3c4:
  piVar11 = (int *)param_1[0xc];
  if ((*piVar11 != 0) || ((char)piVar11[1] != '\0')) goto LAB_0028d4e8;
  iVar7 = piVar11[3];
  iVar16 = piVar11[0x3a9f];
  iVar6 = iVar7 - piVar11[2];
  FUN_00291d44(param_1[6]);
  FUN_00291210(param_1[5],1,iVar7,iVar16 - iVar7);
  iVar7 = (**(code **)(*param_1 + 0xb0))(param_1,param_1[6],param_1[5],param_4);
  if (iVar7 != 0) {
    FUN_0028bc28(param_1[1],2);
    uVar14 = 0x338;
    goto LAB_0028d20c;
  }
  if (param_4 == '\0') {
    iVar7 = FUN_00292080(param_1[6],0x20,iVar6);
    if (iVar7 == 0) {
      iVar7 = thunk_FUN_00291ea8(param_1[6]);
      goto LAB_0028d4a8;
    }
  }
  else {
    iVar7 = FUN_00292008();
    if (iVar7 == 0) {
      iVar7 = FUN_00291d4c(param_1[6]);
LAB_0028d4a8:
      if (iVar7 == 0) {
        lVar10 = param_1[0xc];
        *(int *)(lVar10 + 0xc) = *(int *)(lVar10 + 0xc) - iVar6;
        *(int *)(lVar10 + 0xea7c) = *(int *)(lVar10 + 0xea7c) - iVar6;
LAB_0028d4e8:
        FUN_002917b8(param_1[0xb],param_2,param_3);
        return 0;
      }
      FUN_0028bc28(param_1[1],2);
      uVar14 = 0x352;
      goto LAB_0028d20c;
    }
  }
  FUN_0028bc28(param_1[1],2);
  uVar14 = 0x345;
LAB_0028d20c:
  FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",uVar14,iVar7);
  return iVar7;
}

