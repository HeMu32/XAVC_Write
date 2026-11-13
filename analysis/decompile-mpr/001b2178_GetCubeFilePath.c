// mpr::GetCubeFilePath
// Ghidra address: 001b2178

/* mpr::GetCubeFilePath(sidb::recordInfo const&, unsigned int, std::__cxx11::string&) */

undefined4 mpr::GetCubeFilePath(recordInfo *param_1,uint param_2,string *param_3)

{
  uint uVar1;
  int iVar2;
  void *__ptr;
  undefined4 uVar3;
  uint local_94;
  undefined2 local_90;
  undefined2 local_8e;
  undefined1 local_8c;
  undefined1 local_8b;
  undefined1 local_8a;
  undefined1 local_89;
  int local_88;
  NrtMetaWrapper aNStack_80 [48];
  undefined1 auStack_50 [80];
  
  if (param_1[0xc0] == '\0') {
    return 4;
  }
  FUN_00341acc(auStack_50);
  FUN_00352de0(aNStack_80);
  local_94 = 0;
  iVar2 = FUN_00341af0(auStack_50,param_1 + 0xc1,1);
  if (iVar2 == 0) {
    iVar2 = FUN_00342354(auStack_50,&local_94);
    uVar1 = local_94;
    if (iVar2 == 0) {
      __ptr = malloc((ulong)local_94);
      iVar2 = FUN_00341dac(auStack_50,__ptr,uVar1);
      if (iVar2 == 0) {
        FUN_00341b2c(auStack_50);
        iVar2 = FUN_00353e8c(aNStack_80,__ptr,local_94);
        if (iVar2 == 0) {
          iVar2 = GetLutNrtInfo(aNStack_80,param_2,param_3);
          uVar3 = 0;
          if (iVar2 != 0) {
            uVar3 = 4;
            local_8c = 3;
            local_8b = 0;
            local_90 = 0x2100;
            local_8a = 0;
            local_8e = 6;
            local_89 = 0;
            local_88 = iVar2;
            FUN_001aa3f8(&local_90,0xc);
          }
        }
        else {
          local_8b = 0;
          uVar3 = 2;
          local_8c = 3;
          local_8a = 0;
          local_90 = 0x2100;
          local_89 = 0;
          local_8e = 5;
          local_88 = 0;
          FUN_001aa3f8(&local_90,0xc);
        }
        if (__ptr != (void *)0x0) {
          free(__ptr);
        }
        goto LAB_001b220c;
      }
      local_8e = 4;
    }
    else {
      local_8e = 3;
    }
    local_89 = 0;
    local_8a = 0;
    local_8b = 0;
    local_8c = 3;
    local_90 = 0x2100;
    local_88 = iVar2;
    FUN_001aa3f8(&local_90,0xc);
    FUN_00341b2c(auStack_50);
  }
  else {
    local_8b = 0;
    local_8c = 3;
    local_8a = 0;
    local_90 = 0x2100;
    local_89 = 0;
    local_8e = 2;
    local_88 = iVar2;
    FUN_001aa3f8(&local_90,0xc);
  }
  uVar3 = 2;
LAB_001b220c:
  FUN_00352bb4(aNStack_80);
  FUN_00341b6c(auStack_50);
  return uVar3;
}

