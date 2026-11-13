// mpr::MoviePlayer::SetMovieReaderStartParam
// Ghidra address: 00203244

/* mpr::MoviePlayer::SetMovieReaderStartParam(mpr::MoviePlayer::MovieReaderStartParam*, signed char)
    */

void mpr::MoviePlayer::SetMovieReaderStartParam(string *param_1,char param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  string sVar5;
  undefined4 uVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined8 uVar11;
  ulong uVar12;
  long lVar13;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  uint local_8;
  
  local_c = 3;
  local_10 = 0x2313;
  local_e = 0x430;
  local_b = 0;
  local_a = 0;
  local_9 = 0;
  local_8 = (int)param_2;
  FUN_001fe840(&local_10,0xc);
  puVar3 = PTR_s_pbStartParam_00401a40;
  puVar2 = PTR_sp_vpiSyncInfo_00401668;
  if (((int)param_2 & 0xfffffffdU) == 0) {
    std::__cxx11::string::_M_assign(param_1);
    param_1[0x20] = *(string *)(puVar3 + 0x20);
    std::__cxx11::string::_M_assign(param_1 + 0x28);
    std::__cxx11::string::_M_assign(param_1 + 0x48);
    *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(puVar3 + 0x68);
    lVar13 = *(long *)PTR_s_pbTime_00402a98;
    if ((lVar13 == 90000) &&
       (cVar7 = GetPlayDirection(*(int *)PTR_s_currentPbSpeed_004018f0), cVar7 == '\x01')) {
      lVar13 = -1;
    }
    *(long *)(param_1 + 0x70) = lVar13;
    param_1[0x85] = (string)0x1;
  }
  else {
    uVar11 = *(undefined8 *)PTR_sp_vpiSyncInfo_00401668;
    std::__cxx11::string::_M_assign(param_1);
    param_1[0x20] = *(string *)(*(long *)puVar2 + 0x5a0);
    std::__cxx11::string::_M_assign(param_1 + 0x28);
    uVar11 = *(undefined8 *)puVar2;
    std::__cxx11::string::_M_assign(param_1 + 0x48);
    lVar13 = *(long *)puVar2;
    *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(lVar13 + 0x590);
    puVar3 = PTR_s_currentPbSpeed_004018f0;
    if (*(int *)(PTR_s_pbStartParam_00401a40 + 0x74) == 1) {
      uVar8 = *(uint *)PTR_s_currentPbSpeed_004018f0;
      if (*(int *)(PTR_PlaySpeedDefaultTbl_004025e0 +
                  (-(ulong)(uVar8 >> 0x1f) & 0xfffffff000000000 | (ulong)uVar8 << 4)) == 1) {
        cVar7 = GetPlaySpeedMode(uVar8);
        if (cVar7 == '\0') {
          lVar13 = *(long *)puVar2;
          goto LAB_002034d8;
        }
        uVar11 = Codec::GetDecStatusPts64();
        goto LAB_002034e4;
      }
      uVar11 = Codec::GetDecStatusPts64();
      *(undefined8 *)(param_1 + 0x70) = uVar11;
      cVar7 = GetPlaySpeedMode(*(int *)PTR_s_beforePbSpeed_00402608);
      if ((cVar7 != '\0') && (cVar7 = GetPlaySpeedMode(*(int *)puVar3), cVar7 == '\0')) {
        param_1[0x87] = (string)0x1;
      }
    }
    else {
LAB_002034d8:
      uVar11 = *(undefined8 *)(lVar13 + 0x480);
LAB_002034e4:
      *(undefined8 *)(param_1 + 0x70) = uVar11;
    }
    param_1[0x85] = (string)0x0;
  }
  puVar4 = PTR_PlaySpeedDefaultTbl_004025e0;
  puVar3 = PTR_s_pbStartParam_00401a40;
  puVar2 = PTR_s_currentPbSpeed_004018f0;
  *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(PTR_s_pbStartParam_00401a40 + 0x6c);
  uVar8 = *(uint *)puVar2;
  *(undefined4 *)(param_1 + 0x78) =
       *(undefined4 *)(puVar4 + (-(ulong)(uVar8 >> 0x1f) & 0xfffffff000000000 | (ulong)uVar8 << 4));
  uVar8 = GetPlayDirection(uVar8);
  *(uint *)(param_1 + 0x7c) = uVar8 & 0xff;
  if (*(int *)(param_1 + 0x78) == 0) {
    *(undefined4 *)(param_1 + 0x80) = 0;
    param_1[0x84] = (string)0x1;
  }
  else {
    iVar1 = *(int *)puVar2;
    if ((iVar1 - 0xbU & 0xfffffffd) == 0) {
      if (*(int *)(puVar3 + 0x74) != 1) {
        iVar9 = 0x176;
        goto LAB_00203568;
      }
      if (*(uint *)(puVar3 + 0x78) < 8) {
                    /* WARNING: Could not recover jumptable at 0x00203560. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)((long)(char)(&switchD_00203560::switchdataD_003d5684)[*(uint *)(puVar3 + 0x78)] *
                   4 + 0x203564))();
        return;
      }
      *(undefined4 *)(param_1 + 0x80) = 0;
    }
    else {
      cVar7 = puVar3[0x8a];
      if (cVar7 == '\0') {
        iVar9 = 0xbbb;
        iVar10 = 0xf;
      }
      else {
        iVar9 = 0xe10;
        if (cVar7 != '\x01') {
          iVar9 = 0;
        }
        iVar10 = 0xd;
        if (cVar7 != '\x01') {
          iVar10 = 0;
        }
      }
      iVar9 = iVar10 * *(int *)(PTR_PlaySpeedDefaultTbl_004025e0 + (long)iVar1 * 0x10 + 0xc) * iVar9
      ;
LAB_00203568:
      *(int *)(param_1 + 0x80) = iVar9;
    }
    param_1[0x84] = (string)0x0;
  }
  uVar12 = *(ulong *)(param_1 + 0x70);
  if ((uVar12 != 0xffffffffffffffff) && (uVar8 = *(uint *)(param_1 + 0x80), uVar8 != 0)) {
    if (*(int *)(param_1 + 0x7c) == 0) {
      lVar13 = uVar12 + uVar8;
    }
    else {
      if ((uVar8 < uVar12) &&
         (uVar12 = uVar12 - uVar8, *(ulong *)(param_1 + 0x70) = uVar12, 89999 < uVar12))
      goto LAB_00203398;
      lVar13 = 90000;
    }
    *(long *)(param_1 + 0x70) = lVar13;
  }
LAB_00203398:
  puVar2 = PTR_s_pbStartParam_00401a40;
  local_b = 0;
  local_a = 0;
  local_9 = 0;
  param_1[0x86] = *(string *)(PTR_s_pbStartParam_00401a40 + 0x89);
  puVar3 = PTR_s_buffer_00402480;
  *(undefined8 *)(param_1 + 0x88) = *(undefined8 *)(PTR_s_buffer_00402480 + 0x240);
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(puVar3 + 0x250);
  *(undefined8 *)(param_1 + 0x98) = *(undefined8 *)(puVar3 + 600);
  *(undefined8 *)(param_1 + 0xa0) = *(undefined8 *)(puVar3 + 0x20);
  uVar11 = *(undefined8 *)(puVar3 + 0x38);
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(puVar3 + 0x30);
  *(undefined8 *)(param_1 + 0xb0) = uVar11;
  *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(puVar2 + 0x90);
  uVar6 = DAT_00498214;
  sVar5 = DAT_00498210;
  DAT_00498210 = (string)0x0;
  local_c = 3;
  param_1[0xc0] = sVar5;
  local_10 = 0x2313;
  *(undefined4 *)(param_1 + 0xc4) = uVar6;
  local_e = 0x43f;
  local_8 = (uint)*(undefined8 *)(param_1 + 0x70);
  FUN_001fe840(&local_10,0xc);
  return;
}

