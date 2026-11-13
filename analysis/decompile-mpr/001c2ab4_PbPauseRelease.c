// mpr::PbPauseRelease
// Ghidra address: 001c2ab4

/* mpr::PbPauseRelease(mpr::pbPauseReleaseInParam const&) */

int mpr::PbPauseRelease(pbPauseReleaseInParam *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  FUN_001bf858(param_1,8);
  pbPauseReleaseInParam::DbgPrint();
  pthread_mutex_lock((pthread_mutex_t *)PTR_g_integApiMutex_00401418);
  local_c = 4;
  local_10 = 0x10302160;
  FUN_001bf858((evtPbPauseReleaseFinishedParam *)&local_10,8);
  LockPbApi(0x1015);
  thread::normalLock::lock((normalLock *)PTR_s_moviePlayLock_00402d68);
  iVar1 = *(int *)PTR_s_statePlay_00401508;
  if (iVar1 == 1) {
    iVar1 = ProcInMoviePlaying_RecvPbPauseReleaseCmd(*(uint *)(param_1 + 4));
    if ((iVar1 != 0) && (*(long *)PTR_s_merrCtxPlaying_00402880 != 0)) {
      FUN_001fe0e8(*(long *)PTR_s_merrCtxPlaying_00402880,iVar1);
    }
  }
  else {
    if (iVar1 == 0) {
      uVar2 = 8;
      local_c = 4;
      local_10 = 0x10312160;
    }
    else {
      if (iVar1 == 2) {
        local_c = 4;
        local_10 = 0x10322160;
        FUN_001bf858((evtPbPauseReleaseFinishedParam *)&local_10,8);
        iVar1 = 2;
        goto LAB_001c2bd8;
      }
      uVar2 = 0xc;
      local_c = 3;
      local_10 = 0x10332160;
      local_8 = iVar1;
    }
    iVar1 = 2;
    FUN_001bf858((evtPbPauseReleaseFinishedParam *)&local_10,uVar2);
  }
LAB_001c2bd8:
  thread::normalLock::unlock((normalLock *)PTR_s_moviePlayLock_00402d68);
  if (iVar1 != 0) {
    evtPbPauseReleaseFinishedParam::evtPbPauseReleaseFinishedParam
              ((evtPbPauseReleaseFinishedParam *)&local_10);
    local_8 = *(int *)(param_1 + 4);
    local_c = iVar1;
    SetIssueEvent(0x1015,(evtPbPauseReleaseFinishedParam *)&local_10,0xc);
    UnlockPbApi(0x1015);
  }
  local_10 = 0x103f2160;
  local_c = 3;
  local_8 = iVar1;
  FUN_001bf858((evtPbPauseReleaseFinishedParam *)&local_10,0xc);
  pthread_mutex_unlock((pthread_mutex_t *)PTR_g_integApiMutex_00401418);
  local_10 = 0x33;
  local_c = iVar1;
  FUN_001bf858((evtPbPauseReleaseFinishedParam *)&local_10,8);
  return iVar1;
}

