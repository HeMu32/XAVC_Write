// FUN_00352900
// Ghidra address: 00352900

undefined8 FUN_00352900(int param_1,undefined8 *param_2,undefined4 *param_3,string *param_4)

{
  undefined4 *puVar1;
  char cVar2;
  undefined8 uVar3;
  long *plVar4;
  undefined4 *puVar5;
  long lVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined1 *local_80;
  undefined8 uStack_78;
  undefined1 local_70 [16];
  undefined1 auStack_60 [32];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  long local_28;
  undefined1 auStack_20 [32];
  
  if (param_3 == (undefined4 *)0x0 || param_4 == (string *)0x0) {
    return 2;
  }
  if (param_1 != 0) {
    return 4;
  }
  uVar8 = param_2[1];
  uVar7 = 0;
  *param_3 = 0xe;
  *(undefined8 *)(param_4 + 8) = 0;
  **(undefined1 **)param_4 = 0;
  local_80 = local_70;
  uStack_78 = 0;
  uVar3 = *param_2;
  local_70[0] = 0;
  while (uVar7 = uVar7 + 1, uVar7 < (uint)((int)uVar8 - (int)uVar3)) {
    std::__cxx11::string::append((ulong)&local_80,'\x01');
  }
  FUN_0035148c(auStack_60,&DAT_003de094,0x10);
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  local_28 = 0;
  cVar2 = FUN_00350d38(&local_80,&local_40,auStack_60,0);
  if (cVar2 != '\0') {
    FUN_0034deac(auStack_20,&local_40,0);
    std::__cxx11::string::assign(param_4);
    std::__cxx11::string::_M_dispose();
    std::__cxx11::string::erase((ulong)param_4,0);
    plVar4 = (long *)FUN_0034de54(&local_40,0);
    std::__cxx11::string::erase((ulong)&local_80,(*plVar4 - local_28) + 1);
  }
  puVar1 = DAT_004bd198;
  puVar5 = DAT_004bd190;
  for (lVar6 = ((long)DAT_004bd198 - (long)DAT_004bd190 >> 3) * -0x3333333333333333 >> 2; 0 < lVar6;
      lVar6 = lVar6 + -1) {
    cVar2 = FUN_001ba894(puVar5 + 2,&local_80);
    if (cVar2 != '\0') goto LAB_00352aa8;
    cVar2 = FUN_001ba894(puVar5 + 0xc,&local_80);
    if (cVar2 != '\0') {
      puVar5 = puVar5 + 10;
      goto LAB_00352aa8;
    }
    cVar2 = FUN_001ba894(puVar5 + 0x16,&local_80);
    if (cVar2 != '\0') {
      puVar5 = puVar5 + 0x14;
      goto LAB_00352aa8;
    }
    cVar2 = FUN_001ba894(puVar5 + 0x20,&local_80);
    if (cVar2 != '\0') {
      puVar5 = puVar5 + 0x1e;
      goto LAB_00352aa8;
    }
    puVar5 = puVar5 + 0x28;
  }
  lVar6 = ((long)puVar1 - (long)puVar5 >> 3) * -0x3333333333333333;
  if (lVar6 == 2) {
LAB_00352b8c:
    cVar2 = FUN_001ba894(puVar5 + 2,&local_80);
    if (cVar2 == '\0') {
      puVar5 = puVar5 + 10;
LAB_00352b2c:
      cVar2 = FUN_001ba894(puVar5 + 2,&local_80);
      if (cVar2 == '\0') goto LAB_00352b40;
    }
  }
  else {
    if (lVar6 != 3) {
      if (lVar6 != 1) goto LAB_00352b40;
      goto LAB_00352b2c;
    }
    cVar2 = FUN_001ba894(puVar5 + 2,&local_80);
    if (cVar2 == '\0') {
      puVar5 = puVar5 + 10;
      goto LAB_00352b8c;
    }
  }
LAB_00352aa8:
  if (puVar1 != puVar5) {
    *param_3 = *puVar5;
  }
LAB_00352b40:
  FUN_002beb94(&local_40);
  FUN_0034de2c(auStack_60);
  std::__cxx11::string::_M_dispose();
  return 0;
}

