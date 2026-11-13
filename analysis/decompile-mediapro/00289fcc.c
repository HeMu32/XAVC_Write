// Ghidra: 00289fcc; ELF VMA = Ghidra - 0x100000

undefined4 FUN_00289fcc(long *param_1,long param_2,long param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  long *plVar8;
  long *plVar9;
  long lVar10;
  uint uVar11;
  undefined8 *puVar12;
  undefined1 auStack_120 [144];
  char acStack_90 [144];
  
  (**(code **)(*param_1 + 0x3b8))(param_1,param_3);
  memset(auStack_120,0,0x89);
  FUN_00284e8c(acStack_90,param_2 + 0x80);
  while (pcVar7 = strchr(acStack_90,0x5c), pcVar7 != (char *)0x0) {
    *pcVar7 = DAT_003d7f63._1_1_;
  }
  FUN_00284e8c(auStack_120,acStack_90);
  iVar5 = 0;
  iVar4 = FUN_00289b2c(param_3,auStack_120);
  if (iVar4 == 1) {
    iVar5 = (**(code **)(*param_1 + 0x1d8))(param_1,param_2,&DAT_003d8131);
    if (iVar5 == 0) {
      iVar4 = FUN_00288390(param_3 + 0xf4,&DAT_003d8132);
      iVar5 = 0;
    }
    else {
      iVar5 = 0x67;
    }
  }
  bVar2 = iVar4 == 1;
  if (bVar2 && iVar5 == 0) {
    iVar5 = (**(code **)(*param_1 + 0x438))(param_1,param_2,param_3 + 0x120);
  }
  if (bVar2 && iVar5 == 0) {
    iVar5 = (**(code **)(*param_1 + 0x208))(param_1,param_2,param_3 + 0x130);
  }
  if (bVar2 && iVar5 == 0) {
    iVar5 = (**(code **)(*param_1 + 0x220))(param_1,param_2,param_3 + 0x148);
  }
  if (bVar2 && iVar5 == 0) {
    iVar5 = (**(code **)(*param_1 + 0x210))(param_1,param_2,param_3 + 0x194);
  }
  if (bVar2 && iVar5 == 0) {
    iVar5 = (**(code **)(*param_1 + 0x268))
                      (param_1,*(undefined4 *)(param_2 + 0x114),param_3 + 0x1b0);
  }
  if (bVar2 && iVar5 == 0) {
    iVar5 = (**(code **)(*param_1 + 0x218))(param_1,param_2,param_3 + 0x1dc);
  }
  if (bVar2 && iVar5 == 0) {
    iVar5 = (**(code **)(*param_1 + 0x288))
                      (param_1,*(undefined4 *)(param_2 + 0x118),*(undefined1 *)(param_2 + 0x11c),
                       param_3 + 0x1f8);
  }
  bVar3 = iVar5 == 0;
  if (bVar2 && bVar3) {
    iVar4 = FUN_00288334(param_3 + 0x214,*(undefined4 *)(param_2 + 0x120));
  }
  if (bVar3 && iVar4 == 1) {
    if (*(int *)(param_3 + 0x21c) == 0) {
      *(undefined2 *)(param_3 + 0x220) = *(undefined2 *)(param_2 + 0x124);
      *(undefined4 *)(param_3 + 0x21c) = 1;
    }
    else {
      *(undefined4 *)(param_3 + 0x21c) = 3;
    }
    iVar4 = *(int *)(param_3 + 0x21c);
  }
  if (bVar3 && iVar4 == 1) {
    (**(code **)(*param_1 + 0x298))(param_1,*(undefined4 *)(param_2 + 0x128),param_3 + 0x22c);
    iVar4 = FUN_00288334(param_3 + 0x248,*(undefined4 *)(param_2 + 300));
  }
  if (bVar3 && iVar4 == 1) {
    iVar4 = FUN_00288358(param_3 + 0x250,param_2 + 0x130);
  }
  if (bVar3 && iVar4 == 1) {
    iVar4 = 1;
    (**(code **)(*param_1 + 0x2a8))(param_1,*(undefined4 *)(param_2 + 0x154),param_3 + 0x274);
    if (*(uint *)(param_2 + 0x198) < 6) {
      *(uint *)(param_3 + 0x5b8) = *(uint *)(param_2 + 0x198);
      plVar8 = param_1 + 0x1610a;
      lVar10 = param_2 + 0x19c;
      memset(plVar8,0,0x7e4);
      puVar12 = (undefined8 *)(param_3 + 0x5c0);
      for (uVar11 = 0; uVar11 < *(uint *)(param_2 + 0x198); uVar11 = uVar11 + 1) {
        FUN_00284e8c(acStack_90,lVar10);
        while (pcVar7 = strchr(acStack_90,0x5c), pcVar7 != (char *)0x0) {
          *pcVar7 = DAT_003d7f63._1_1_;
        }
        iVar4 = FUN_00289b2c(plVar8 + 0x15,acStack_90);
        if (iVar4 != 1) goto LAB_0028a38c;
        puVar1 = (undefined4 *)(lVar10 + 0x8c);
        lVar10 = lVar10 + 0x90;
        iVar5 = (**(code **)(*param_1 + 0x278))(param_1,*puVar1,(long)plVar8 + 0x13c);
        if (iVar5 != 0) goto LAB_0028a38c;
        *puVar12 = plVar8;
        plVar8 = (long *)((long)plVar8 + 0x194);
        puVar12 = puVar12 + 1;
      }
      iVar4 = 1;
      iVar5 = 0;
    }
    else {
LAB_0028a38c:
      iVar5 = 0x67;
    }
  }
  if (iVar5 == 0 && iVar4 == 1) {
    iVar4 = 1;
    if (*(uint *)(param_2 + 0x46c) < 3) {
      *(uint *)(param_3 + 0x5a0) = *(uint *)(param_2 + 0x46c);
      iVar4 = 1;
      memset(param_1 + 0x16303,0,0x4b8);
      plVar8 = (long *)(param_3 + 0x5a8);
      plVar9 = param_1;
      lVar10 = param_2;
      for (uVar11 = 0; uVar11 < *(uint *)(param_2 + 0x46c); uVar11 = uVar11 + 1) {
        FUN_00284e8c(acStack_90,lVar10 + 0x470);
        while (pcVar7 = strchr(acStack_90,0x5c), pcVar7 != (char *)0x0) {
          *pcVar7 = DAT_003d7f63._1_1_;
        }
        iVar4 = FUN_00289b2c(plVar9 + 0x16318,acStack_90);
        if ((((iVar4 != 1) ||
             (iVar5 = (**(code **)(*param_1 + 0x278))
                                (param_1,*(undefined4 *)(lVar10 + 0x4fc),(long)plVar9 + 0xb1954),
             iVar5 != 0)) ||
            (iVar5 = (**(code **)(*param_1 + 0x230))(param_1,lVar10 + 0x470,plVar9 + 0x16330),
            iVar5 != 0)) ||
           (iVar5 = (**(code **)(*param_1 + 0x268))
                              (param_1,*(undefined4 *)(lVar10 + 0x508),(long)plVar9 + 0xb19cc),
           iVar5 != 0)) goto LAB_0028a518;
        iVar4 = FUN_00288334((long)plVar9 + 0xb1a1c,*(undefined2 *)(lVar10 + 0x510));
        if (iVar4 != 1) goto LAB_0028a518;
        (**(code **)(*param_1 + 0x298))
                  (param_1,*(undefined4 *)(lVar10 + 0x514),(long)plVar9 + 0xb1a2c);
        iVar4 = FUN_00288358(plVar9 + 0x1634a,lVar10 + 0x518);
        *plVar8 = (long)(plVar9 + 0x16303);
        plVar8 = plVar8 + 1;
        plVar9 = (long *)((long)plVar9 + 0x25c);
        lVar10 = lVar10 + 0x11c;
      }
      iVar5 = 0;
    }
    else {
LAB_0028a518:
      iVar5 = 0x67;
    }
  }
  uVar6 = 0x67;
  if (iVar5 == 0 && iVar4 == 1) {
    uVar6 = 0;
  }
  return uVar6;
}

