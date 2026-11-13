// mpr::PbStart
// Ghidra address: 001c3aec

/* mpr::PbStart(mpr::pbStartInParam const&) */

int mpr::PbStart(pbStartInParam *param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  uint local_1c;
  undefined4 local_18;
  int local_14;
  long local_10;
  ulong local_8;
  
  FUN_001bf858(param_1,0x30);
  pbStartInParam::DbgPrint();
  pthread_mutex_lock((pthread_mutex_t *)PTR_g_integApiMutex_00401418);
  local_14 = 4;
  local_18 = 0x10002160;
  FUN_001bf858((evtPbStartFinishedParam *)&local_18,8);
  if (*(set **)(param_1 + 0x10) == (set *)0x0) {
    uVar2 = *(uint *)(param_1 + 0x1c);
  }
  else {
    uVar2 = sidb::set::at(*(set **)(param_1 + 0x10),*(uint *)(param_1 + 0x18));
  }
  local_1c = 0xffffffff;
  LockPbApi(0x1010);
  iVar3 = stillrecord::clear_pseudo_still(false);
  if (iVar3 == 0) {
    iVar3 = sidb::GetMediaIdFromUniqueId(uVar2,&local_1c);
    if (iVar3 != 0) {
      local_10 = CONCAT44(local_10._4_4_,uVar2);
      local_18 = 0x10022160;
      goto LAB_001c3bb0;
    }
    iVar3 = msidconv::GetSlotID((msidconv *)PTR_g_msidconv_00401cd8,local_1c);
    if (iVar3 == -1) {
      iVar3 = 2;
      bVar1 = true;
      pthread_mutex_unlock((pthread_mutex_t *)PTR_g_integApiMutex_00401418);
      local_18 = 0x2d;
      local_14 = 2;
      FUN_001bf858((evtPbStartFinishedParam *)&local_18,8);
      local_14 = 3;
      local_18 = 0x10032160;
      local_10 = CONCAT44(local_10._4_4_,local_1c);
      FUN_001bf858((evtPbStartFinishedParam *)&local_18,0xc);
    }
    else {
      thread::normalLock::lock((normalLock *)PTR_s_moviePlayLock_00402d68);
      GetPlaybackParam((playbackParam *)PTR_s_playbackParam_00401430);
      iVar3 = *(int *)PTR_s_statePlay_00401508;
      if (iVar3 == 1) {
        iVar3 = ProcInMoviePlaying_RecvPbStartCmd(param_1);
        bVar1 = true;
        if ((iVar3 != 0) && (*(long *)PTR_s_merrCtxPlaying_00402880 != 0)) {
          bVar1 = false;
          FUN_001fe0e8(*(long *)PTR_s_merrCtxPlaying_00402880,iVar3);
        }
      }
      else if (iVar3 == 0) {
        bVar1 = true;
        iVar3 = ProcInIdle_RecvPbStartCmd(param_1,0);
      }
      else {
        if (iVar3 == 2) {
          uVar4 = 8;
          local_14 = 4;
          local_18 = 0x10042160;
        }
        else {
          uVar4 = 0xc;
          local_14 = 3;
          local_10 = CONCAT44(local_10._4_4_,iVar3);
          local_18 = 0x10052160;
        }
        bVar1 = true;
        iVar3 = 2;
        FUN_001bf858((evtPbStartFinishedParam *)&local_18,uVar4);
      }
      thread::normalLock::unlock((normalLock *)PTR_s_moviePlayLock_00402d68);
      if (iVar3 == 0) {
        *(undefined4 *)PTR_s_pbSpeed_00401dd0 = *(undefined4 *)(param_1 + 0x20);
        goto LAB_001c3c20;
      }
    }
  }
  else {
    local_10 = CONCAT44(local_10._4_4_,iVar3);
    local_18 = 0x10012160;
LAB_001c3bb0:
    local_14 = 3;
    bVar1 = true;
    iVar3 = 2;
    FUN_001bf858((evtPbStartFinishedParam *)&local_18,0xc);
  }
  evtPbStartFinishedParam::evtPbStartFinishedParam((evtPbStartFinishedParam *)&local_18);
  local_10 = CONCAT44(local_10._4_4_,*(undefined4 *)(param_1 + 4));
  local_14 = iVar3;
  SetIssueEvent(0x1010,(evtPbStartFinishedParam *)&local_18,0xc);
  if (bVar1) {
    local_10 = *(long *)(param_1 + 0x10);
    local_18 = 0x1018;
    uVar2 = 0xffffffff;
    if (local_10 != 0) {
      uVar2 = *(uint *)(param_1 + 0x18);
    }
    local_8 = (ulong)uVar2;
    local_14 = iVar3;
    SetIssueEvent(0x1018,(evtPbStartFinishedParam *)&local_18,0x18);
  }
  UnlockPbApi(0x1010);
LAB_001c3c20:
  local_10 = CONCAT44(local_10._4_4_,iVar3);
  local_18 = 0x100f2160;
  local_14 = 3;
  FUN_001bf858((evtPbStartFinishedParam *)&local_18,0xc);
  pthread_mutex_unlock((pthread_mutex_t *)PTR_g_integApiMutex_00401418);
  local_18 = 0x2d;
  local_14 = iVar3;
  FUN_001bf858((evtPbStartFinishedParam *)&local_18,8);
  return iVar3;
}

