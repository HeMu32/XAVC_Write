// mpr::MoviePlayer::ProcInIdlePbStart
// Ghidra address: 002019f0

/* mpr::MoviePlayer::ProcInIdlePbStart(mpr::MoviePlayer::PbStartInParam const&) */

int mpr::MoviePlayer::ProcInIdlePbStart(PbStartInParam *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  char cVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  uint local_1c;
  undefined2 local_18;
  undefined2 local_16;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  int local_10;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_14 = 1;
  local_18 = 0x2313;
  local_13 = 0;
  local_16 = 0x170;
  local_12 = 0;
  local_11 = 0;
  local_10 = *(int *)PTR_s_currentPbSpeed_004018f0;
  local_c = *(int *)(param_1 + 0x7c);
  local_8 = *(undefined4 *)(param_1 + 0x80);
  local_4 = *(undefined4 *)(param_1 + 0x68);
  FUN_001fe840(&local_18,0x18);
  GetPbStartParam(param_1);
  puVar2 = PTR_s_beforePbSpeed_00402608;
  puVar1 = PTR_s_currentPbSpeed_004018f0;
  local_10 = *(int *)(param_1 + 0x78);
  uVar6 = 0;
  do {
    if (local_10 == *(int *)(PTR_frameDuration90KHzTablex1000_00402958 + uVar6 * 0x10)) {
      lVar7 = (long)*(double *)
                     (PTR_frameDuration90KHzTablex1000_00402958 + (uVar6 & 0xffffffff) * 0x10 + 8);
      *(undefined4 *)PTR_s_beforePbSpeed_00402608 = *(undefined4 *)PTR_s_currentPbSpeed_004018f0;
      iVar5 = *(int *)(PTR_s_pbStartParam_00401a40 + 0x7c);
      *(int *)puVar1 = iVar5;
      if (iVar5 == 1) {
        *(undefined4 *)puVar2 = 0;
      }
      puVar2 = PTR_s_vpiSyncInfoList_00402310;
      puVar1 = PTR_s_pbStartParam_00401a40;
      uVar6 = (ulong)*(uint *)(PTR_s_pbStartParam_00401a40 + 0x6c);
      *(undefined **)PTR_sp_vpiSyncInfo_00401668 = PTR_s_vpiSyncInfoList_00402310 + uVar6 * 0x5e8;
      puVar3 = PTR_s_pbTime_00402a98;
      *(undefined8 *)PTR_s_pbTime_00402a98 = 90000;
      local_c = *(int *)(puVar1 + 0x80);
      if (local_c == 1) {
        if (*(int *)(puVar1 + 0x68) == *(int *)(puVar2 + uVar6 * 0x5e8 + 0x590)) {
          *(undefined8 *)puVar3 = *(undefined8 *)(puVar2 + uVar6 * 0x5e8 + 0x480);
        }
      }
      else if (local_c == 2) {
        DAT_00498214 = *(int *)(puVar1 + 0x84);
        *(long *)puVar3 = (long)((double)((ulong)(DAT_00498214 * lVar7) / 1000) + DAT_003d5668);
        DAT_00498210 = 1;
      }
      if (PTR_s_pbStartParam_00401a40[0x88] == '\0') {
        *(undefined **)PTR_sp_vpiSyncInfo_00401668 = PTR_s_vpiSyncInfoTemp_00401740;
      }
      local_16 = 0x172;
      local_8 = *(undefined4 *)(PTR_s_pbStartParam_00401a40 + 0x84);
      local_14 = 1;
      local_4 = 0;
      local_13 = 0;
      local_12 = 0;
      local_11 = 0;
      local_18 = 0x2313;
      FUN_001fe840(&local_18,0x18);
      local_14 = 1;
      local_13 = 0;
      local_16 = 0x173;
      local_12 = 0;
      local_10 = (int)((ulong)lVar7 >> 0x20);
      local_c = (int)lVar7;
      local_11 = 0;
      local_18 = 0x2313;
      local_8 = (undefined4)((ulong)*(undefined8 *)PTR_s_pbTime_00402a98 >> 0x20);
      local_4 = (undefined4)*(undefined8 *)PTR_s_pbTime_00402a98;
      FUN_001fe840(&local_18,0x18);
      local_1c = 0;
      cVar4 = DmmMemInfo::AllocDmmMemory(0x11,&local_1c,(BufferTable *)PTR_s_buffer_00402480);
      if (cVar4 != '\0') {
        *PTR_sb_pbStreaming_00402638 = param_1[0x8c];
        iVar5 = SendCodecDecOpen();
        if (iVar5 == 0) {
          UpdateMoviePlayerState(1);
        }
        else if (local_1c != 0) {
          DmmMemInfo::FreeDmmMemory(0x11);
        }
        local_13 = 0;
        local_14 = 3;
        local_12 = 0;
        local_18 = 0x2313;
        local_11 = 0;
        local_16 = 0x17f;
        local_10 = iVar5;
        FUN_001fe840(&local_18,0xc);
        return iVar5;
      }
      local_16 = 0x174;
      local_10 = 0x814;
      goto LAB_00201c08;
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 != 0xc);
  local_16 = 0x171;
LAB_00201c08:
  local_11 = 0;
  local_12 = 0;
  local_13 = 0;
  local_14 = 3;
  local_18 = 0x2313;
  FUN_001fe840(&local_18,0xc);
  return 2;
}

