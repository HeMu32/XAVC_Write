// FUN_001c7e10
// Ghidra address: 001c7e10

int FUN_001c7e10(recordInfo *param_1,nrt_info_t *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  void *__ptr;
  int iVar5;
  uint local_16c;
  int local_168;
  undefined1 local_164;
  undefined2 local_160;
  undefined2 local_15e;
  undefined1 local_15c;
  undefined1 local_15b;
  undefined1 local_15a;
  undefined1 local_159;
  int local_158;
  NrtMetaWrapper aNStack_150 [48];
  undefined1 auStack_120 [80];
  ExifGPSMetadataSet local_d0;
  undefined1 local_cf;
  undefined1 local_ce;
  undefined1 local_cd;
  undefined1 local_cc;
  undefined1 local_cb;
  undefined1 local_ca;
  undefined1 local_c9;
  undefined1 local_c8;
  undefined1 local_c7;
  undefined1 local_c6;
  undefined1 local_c5;
  undefined1 local_c4;
  undefined1 local_c3;
  undefined1 local_c2;
  undefined2 local_c0;
  undefined4 local_be;
  undefined4 local_b8;
  undefined4 local_9c;
  undefined4 local_80;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_4c;
  undefined4 local_40;
  undefined4 local_34;
  undefined1 *local_28;
  undefined8 uStack_20;
  undefined1 local_18 [16];
  undefined2 local_8;
  undefined1 local_6;
  undefined1 local_5;
  undefined2 local_4;
  
  FUN_00341acc(auStack_120);
  FUN_00352de0(aNStack_150);
  local_18[0] = 0;
  local_28 = local_18;
  uStack_20 = 0;
  local_8 = 0;
  local_6 = 0;
  local_be = 0;
  local_5 = 0;
  local_d0 = (ExifGPSMetadataSet)0x0;
  local_cf = 0;
  local_ce = 0;
  local_cd = 0;
  local_cc = 0;
  local_cb = 0;
  local_ca = 0;
  local_c9 = 0;
  local_c8 = 0;
  local_c7 = 0;
  local_c6 = 0;
  local_c5 = 0;
  local_c4 = 0;
  local_c3 = 0;
  local_c2 = 0;
  local_c0 = 0;
  local_16c = 0;
  local_b8 = 0;
  local_9c = 0;
  local_80 = 0;
  local_5c = 0;
  local_58 = 0;
  local_4c = 0;
  local_40 = 0;
  local_34 = 0;
  local_4 = 0;
  local_164 = 0;
  local_168 = 0;
  iVar2 = FUN_00341af0(auStack_120,param_1 + 0xc1,1);
  if (iVar2 != 0) {
    local_15b = 0;
    local_15c = 3;
    local_15a = 0;
    iVar5 = 2;
    local_160 = 0x2140;
    local_159 = 0;
    local_15e = 0x5410;
    local_158 = iVar2;
    FUN_001c495c(&local_160,0xc);
    goto LAB_001c7f28;
  }
  iVar2 = FUN_00342354(auStack_120,&local_16c);
  uVar1 = local_16c;
  if (iVar2 == 0) {
    __ptr = malloc((ulong)local_16c);
    iVar5 = 0;
    iVar2 = FUN_00341dac(auStack_120,__ptr,uVar1);
    if (iVar2 != 0) {
      local_15b = 0;
      local_15c = 3;
      local_15a = 0;
      local_160 = 0x2140;
      local_159 = 0;
      local_15e = 0x5430;
      local_158 = iVar2;
      FUN_001c495c(&local_160,0xc);
      goto LAB_001c7f94;
    }
  }
  else {
    local_15b = 0;
    __ptr = (void *)0x0;
    local_15c = 3;
    local_15a = 0;
    local_160 = 0x2140;
    local_159 = 0;
    local_15e = 0x5420;
    local_158 = iVar2;
    FUN_001c495c(&local_160,0xc);
LAB_001c7f94:
    iVar5 = 2;
  }
  FUN_00341b2c(auStack_120);
  if (iVar5 == 0) {
    iVar3 = FUN_00353e8c(aNStack_150,__ptr,local_16c);
    if (iVar3 == 0) {
      iVar2 = FUN_003540b8(aNStack_150,&local_d0);
      if (iVar2 == 0) {
        **(undefined1 **)param_2 = 1;
        mpr::stillplay::_conv_gps_from_nrt_to_defstruct(&local_d0,*(GpsInfo **)(param_2 + 8));
      }
      iVar2 = FUN_00354288(aNStack_150,&local_168);
      if (iVar2 == 0) {
        param_2[0x38] = (nrt_info_t)0x1;
        if (local_168 == 1) {
          uVar4 = 2;
LAB_001c8068:
          *(undefined4 *)(param_2 + 0x3c) = uVar4;
        }
        else if (local_168 == 0) {
          *(undefined4 *)(param_2 + 0x3c) = 0;
        }
        else {
          if (local_168 == 3) {
            uVar4 = 1;
            goto LAB_001c8068;
          }
          param_2[0x38] = (nrt_info_t)0x0;
        }
      }
      iVar2 = mpr::stillplay::GetLutNrtInfo(aNStack_150,param_2);
      if (iVar2 != 0) {
        local_15b = 0;
        local_15c = 3;
        local_15a = 0;
        local_160 = 0x2140;
        local_159 = 0;
        local_15e = 0x5501;
        local_158 = iVar2;
        FUN_001c495c(&local_160,0xc);
      }
      iVar2 = mpr::stillplay::GetMovieSignatureNrtInfo(aNStack_150,param_1,param_2);
      if (iVar2 == 0) {
        iVar5 = 0;
      }
      else {
        local_15b = 0;
        local_15c = 3;
        local_15a = 0;
        local_160 = 0x2140;
        local_159 = 0;
        local_15e = 0x5502;
        local_158 = iVar2;
        FUN_001c495c(&local_160,0xc);
      }
    }
    else {
      local_15b = 0;
      iVar5 = 2;
      local_15c = 3;
      local_15a = 0;
      local_160 = 0x2140;
      local_159 = 0;
      local_15e = 0x5440;
      local_158 = iVar2;
      FUN_001c495c(&local_160,0xc);
    }
  }
  if (__ptr != (void *)0x0) {
    free(__ptr);
  }
LAB_001c7f28:
  std::__cxx11::string::_M_dispose();
  FUN_00352bb4(aNStack_150);
  FUN_00341b6c(auStack_120);
  return iVar5;
}

