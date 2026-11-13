// FUN_00216cd4
// Ghidra address: 00216cd4

int FUN_00216cd4(undefined4 param_1,undefined8 param_2,char param_3,undefined8 param_4,
                undefined8 param_5,undefined8 param_6)

{
  long lVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  void *pvVar5;
  undefined4 *puVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  undefined1 *puVar10;
  char local_11b;
  char local_11a;
  char local_119;
  int local_118;
  undefined4 local_114;
  int local_110;
  uint local_10c;
  long local_108;
  long local_100;
  long local_f8;
  uint local_f0;
  undefined4 uStack_ec;
  void *local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  int local_c8;
  int iStack_c4;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined2 local_50;
  undefined2 local_4e;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  
  local_4c = 4;
  local_4b = 0;
  local_50 = 0x2311;
  local_4a = 0;
  local_4e = 0xe40;
  local_49 = 0;
  FUN_0020aff4(&local_50,8);
  local_11b = '\0';
  local_11a = '\0';
  local_119 = '\0';
  local_108 = 0;
  local_100 = 0;
  local_f8 = 0;
  local_e8 = (void *)0x0;
  uStack_e0 = 0;
  local_d8 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = 0;
  FUN_0020ae44(&local_50,param_2);
  FUN_001aefcc((vector *)&local_a0,&local_50);
  std::__cxx11::string::_M_dispose();
  if (param_3 != '\0') {
    FUN_0020ae44(&local_50,param_4);
    FUN_001aefcc((vector *)&local_a0,&local_50);
    std::__cxx11::string::_M_dispose();
  }
  FUN_0020ae44(&local_50,param_5);
  FUN_001aefcc((vector *)&local_a0,&local_50);
  std::__cxx11::string::_M_dispose();
  iVar2 = mpr::LockEditTargetFiles((vector *)&local_a0,(vector *)&local_e8);
  FUN_0019dce4((vector *)&local_a0);
  if (iVar2 != 0) goto LAB_00216e18;
  iVar2 = FUN_002122c4(param_2,&local_11b);
  if (iVar2 != 0) goto LAB_00216e18;
  iVar2 = Fsys_Open(param_2,&local_108,1);
  if ((iVar2 != 0) || (iVar2 = Fsys_Lock(local_108,6), iVar2 != 0)) {
LAB_00216e14:
    iVar2 = 0xb;
    goto LAB_00216e18;
  }
  iVar2 = FUN_002122c4(param_5,&local_11a);
  if (iVar2 != 0) goto LAB_00216e18;
  iVar2 = Fsys_Open(param_5,&local_100,1);
  if ((iVar2 != 0) || (iVar2 = Fsys_Lock(local_100,6), iVar2 != 0)) goto LAB_00216e14;
  if (param_3 != '\0') {
    iVar2 = FUN_002122c4(param_4,&local_119);
    if (iVar2 != 0) goto LAB_00216e18;
    iVar2 = Fsys_Open(param_4,&local_f8,1);
    if ((iVar2 != 0) || (iVar2 = Fsys_Lock(local_f8,6), iVar2 != 0)) goto LAB_00216e14;
  }
  pvVar4 = operator_new__(0x200000);
  local_118 = 0;
  pvVar5 = operator_new__(0x200000);
  local_114 = 0;
  FUN_00341acc((vector *)&local_a0);
  FUN_00341acc(&local_50);
  local_110 = 3;
  FUN_00354304(param_6,&local_110);
  iVar2 = FUN_0035353c(param_6,pvVar4,0x200000,&local_118);
  if (iVar2 == 0) {
    iVar2 = 0;
    if (local_118 == 0) goto LAB_00216f20;
    local_d0 = 0;
    Fsys_Open(param_5,&local_f0,2);
    Fsys_FTruncate(CONCAT44(uStack_ec,local_f0),0);
    Fsys_Seek(CONCAT44(uStack_ec,local_f0),0,0,&local_d0);
    Fsys_Write(CONCAT44(uStack_ec,local_f0),pvVar4,local_118);
    Fsys_Flush(CONCAT44(uStack_ec,local_f0));
    Fsys_Close(CONCAT44(uStack_ec,local_f0));
    FUN_003423e8((vector *)&local_a0,param_2,pvVar4,local_118,0);
  }
  else {
    iVar2 = 2;
LAB_00216f20:
    iStack_c4 = local_118;
    local_d0 = 0x20e412311;
    local_c8 = iVar2;
    FUN_0020aff4(&local_d0,0x10);
  }
  if (param_3 != '\0') {
    FUN_00352de0(&local_d0);
    FUN_0021654c(param_4,&local_d0);
    do {
      iVar3 = FUN_003552ec(&local_d0,0);
    } while (iVar3 == 0);
    local_10c = 0;
    FUN_00354f88(param_6,&local_10c);
    uVar8 = (ulong)local_10c;
    lVar1 = -(uVar8 * 0x30 + 0x16 & 0x7ffffffff0);
    puVar6 = (undefined4 *)(&stack0xfffffffffffffe50 + lVar1);
    for (uVar7 = 0; uVar7 != uVar8; uVar7 = uVar7 + 1) {
      *(undefined1 *)(puVar6 + 8) = 0;
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar6[2] = 0;
      *(undefined4 **)(puVar6 + 4) = puVar6 + 8;
      *(undefined8 *)(puVar6 + 6) = 0;
      puVar6 = puVar6 + 0xc;
    }
    local_f0 = 0;
    FUN_00355384(param_6,0,uVar8,&stack0xfffffffffffffe50 + lVar1);
    for (uVar9 = 0; uVar9 < local_f0; uVar9 = uVar9 + 1) {
      FUN_00355c8c(&local_d0,&stack0xfffffffffffffe50 + (ulong)uVar9 * 0x30 + lVar1);
    }
    if (local_110 == 3) {
      FUN_00354388();
    }
    else {
      FUN_003539f0(&local_d0);
    }
    FUN_0035353c(&local_d0,pvVar5,0x200000,&local_114);
    FUN_003423e8(&local_50,param_4,pvVar5,local_114,1);
    for (puVar10 = &stack0xfffffffffffffe50 + uVar8 * 0x30 + lVar1;
        puVar10 != &stack0xfffffffffffffe50 + lVar1; puVar10 = puVar10 + -0x30) {
      std::__cxx11::string::_M_dispose();
    }
    FUN_00352bb4(&local_d0);
  }
  FUN_00342580((vector *)&local_a0);
  operator_delete__(pvVar4);
  operator_delete__(pvVar5);
  FUN_002155f4(param_1,param_2,local_110);
  FUN_00341b6c(&local_50);
  FUN_00341b6c((vector *)&local_a0);
LAB_00216e18:
  if (local_108 != 0) {
    Fsys_Close();
    local_108 = 0;
  }
  if (local_100 != 0) {
    Fsys_Close();
    local_100 = 0;
  }
  if (local_f8 != 0) {
    Fsys_Close();
    local_f8 = 0;
  }
  if (local_11a != '\0') {
    FUN_00212470(param_5);
  }
  if (local_11b != '\0') {
    FUN_00212470(param_2);
  }
  if (local_119 != '\0') {
    FUN_00212470(param_4);
  }
  mpr::UnlockEditTargetFiles((vector *)&local_e8);
  local_4b = 0;
  local_4a = 0;
  local_4c = 4;
  local_49 = 0;
  local_50 = 0x2311;
  local_4e = 0xe4f;
  FUN_0020aff4(&local_50,8);
  if (local_e8 != (void *)0x0) {
    operator_delete(local_e8);
  }
  return iVar2;
}

