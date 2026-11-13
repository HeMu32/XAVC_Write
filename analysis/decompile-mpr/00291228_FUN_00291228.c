// FUN_00291228
// Ghidra address: 00291228

undefined8 * FUN_00291228(undefined8 *param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  uint local_c;
  undefined1 auStack_8 [8];
  
  if (*(char *)((long)param_2 + 0x24) != '\0') {
    *param_1 = 0;
    *(undefined4 *)(param_1 + 1) = 0;
    *(undefined1 *)((long)param_1 + 0xc) = 1;
    *(undefined4 *)(param_1 + 2) = 0;
    return param_1;
  }
  iVar3 = FUN_00280f68(*param_2,0,*(undefined4 *)((long)param_2 + 0x1c),auStack_8);
  if (iVar3 != 0) {
    uVar7 = 0;
    FUN_00290aa4(7,"xavcIfo_MediaProfileParserImplInputFile.cpp",0x37,iVar3);
    uVar4 = 5;
    local_c = 0;
    goto LAB_002912b4;
  }
  if (*(int *)(param_2 + 3) == 0) {
    local_c = 0;
    iVar5 = FUN_00280d8c(*param_2,param_2[2],*(undefined4 *)(param_2 + 1),&local_c);
    uVar7 = param_2[2];
    *(uint *)((long)param_2 + 0x1c) = *(int *)((long)param_2 + 0x1c) + local_c;
    if (iVar5 == 0) {
      *(undefined1 *)((long)param_2 + 0x24) = 0;
      uVar4 = 0;
      goto LAB_002912b4;
    }
    if (iVar5 == 0x6f) {
LAB_00291314:
      *(undefined1 *)((long)param_2 + 0x24) = 1;
LAB_0029131c:
      uVar4 = 0;
      goto LAB_002912b4;
    }
    uVar6 = 0x4f;
  }
  else {
    local_c = 0;
    uVar1 = *(uint *)(param_2 + 4);
    if (*(uint *)(param_2 + 1) < *(uint *)(param_2 + 4)) {
      uVar1 = *(uint *)(param_2 + 1);
    }
    iVar5 = FUN_00280d8c(*param_2,param_2[2],uVar1,&local_c);
    uVar4 = 7;
    uVar7 = param_2[2];
    *(uint *)((long)param_2 + 0x1c) = *(int *)((long)param_2 + 0x1c) + uVar1;
    iVar3 = *(int *)(param_2 + 4);
    *(uint *)(param_2 + 4) = iVar3 - uVar1;
    if (local_c != uVar1) goto LAB_002912b4;
    if (iVar5 == 0) {
      if (iVar3 - uVar1 == 0) goto LAB_00291314;
      *(undefined1 *)((long)param_2 + 0x24) = 0;
      goto LAB_0029131c;
    }
    uVar6 = 0x78;
  }
  uVar1 = local_c;
  FUN_00290aa4(7,"xavcIfo_MediaProfileParserImplInputFile.cpp",uVar6,iVar5);
  uVar4 = 6;
  local_c = uVar1;
LAB_002912b4:
  uVar2 = *(undefined1 *)((long)param_2 + 0x24);
  *param_1 = uVar7;
  *(undefined1 *)((long)param_1 + 0xc) = uVar2;
  *(uint *)(param_1 + 1) = local_c;
  *(undefined4 *)(param_1 + 2) = uVar4;
  return param_1;
}

