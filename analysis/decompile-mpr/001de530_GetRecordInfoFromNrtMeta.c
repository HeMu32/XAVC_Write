// mpr::GetRecordInfoFromNrtMeta
// Ghidra address: 001de530

/* mpr::GetRecordInfoFromNrtMeta(char const*, NRTDEF::BasicInformation&,
   std::vector<NRTDEF::MarkType, std::allocator<NRTDEF::MarkType> >&, NRTDEF::ClipStatus&) */

int mpr::GetRecordInfoFromNrtMeta
              (char *param_1,BasicInformation *param_2,vector *param_3,ClipStatus *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  void *__ptr;
  uint uVar4;
  uint local_bc;
  uint local_b8;
  undefined1 auStack_b4 [4];
  undefined1 auStack_b0 [48];
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  undefined1 *local_70;
  undefined8 uStack_68;
  undefined1 local_60 [16];
  undefined2 local_50;
  undefined2 local_4e;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  
  local_4c = 4;
  local_50 = 0x2110;
  local_4e = 0x150;
  local_4b = 0;
  local_4a = 0;
  local_49 = 0;
  FUN_001c9f24(&local_50,8);
  FUN_00352de0(auStack_b0);
  FUN_00341acc(&local_50);
  local_b8 = 0;
  *(undefined8 *)(param_3 + 8) = *(undefined8 *)param_3;
  iVar2 = FUN_00341af0(&local_50,param_1,1);
  if (iVar2 == 0) {
    iVar2 = FUN_00342354(&local_50,&local_b8);
    uVar4 = local_b8;
    if (iVar2 == 0) {
      __ptr = malloc((ulong)local_b8);
      iVar2 = FUN_00341dac(&local_50,__ptr,uVar4);
      iVar3 = FUN_00341b2c(&local_50);
      if ((((iVar2 == 0) && (iVar2 = iVar3, iVar3 == 0)) &&
          (iVar2 = FUN_00353e8c(auStack_b0,__ptr,local_b8), iVar2 == 0)) &&
         ((iVar2 = FUN_003543fc(auStack_b0,param_2), iVar2 == 0 &&
          (iVar2 = FUN_00354f88(auStack_b0,&local_bc), iVar2 == 0)))) {
        for (uVar4 = 0; uVar4 < local_bc; uVar4 = uVar4 + 1) {
          local_60[0] = 0;
          local_80 = 0;
          local_7c = 0;
          local_78 = 0;
          uStack_68 = 0;
          local_70 = local_60;
          iVar2 = FUN_00355384(auStack_b0,uVar4,1,&local_80,auStack_b4);
          if (iVar2 == 0) {
            puVar1 = *(undefined4 **)(param_3 + 8);
            if (puVar1 == *(undefined4 **)(param_3 + 0x10)) {
              FUN_001dd648(param_3,&local_80);
            }
            else {
              if (puVar1 != (undefined4 *)0x0) {
                *puVar1 = local_80;
              }
              *(undefined4 **)(param_3 + 8) = puVar1 + 1;
            }
          }
          std::__cxx11::string::_M_dispose();
        }
        if (iVar2 == 0) {
          iVar2 = FUN_00354304(auStack_b0,param_4);
        }
      }
      if (__ptr != (void *)0x0) {
        free(__ptr);
      }
    }
    else {
      FUN_00341b2c(&local_50);
    }
  }
  local_80 = 0x15f2110;
  local_7c = 3;
  local_78 = iVar2;
  FUN_001c9f24(&local_80,0xc);
  FUN_00341b6c(&local_50);
  FUN_00352bb4(auStack_b0);
  return iVar2;
}

