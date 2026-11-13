// mpr::PbPause
// Ghidra address: 001c2698

/* mpr::PbPause(mpr::pbPauseInParam const&) */

int mpr::PbPause(pbPauseInParam *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  FUN_001bf858(param_1,8);
  pbPauseInParam::DbgPrint();
  pthread_mutex_lock((pthread_mutex_t *)PTR_g_integApiMutex_00401418);
  local_c = 4;
  local_10 = 0x10202160;
  FUN_001bf858((evtPbPauseFinishedParam *)&local_10,8);
  LockPbApi(0x1014);
  thread::normalLock::lock((normalLock *)PTR_s_moviePlayLock_00402d68);
  iVar1 = *(int *)PTR_s_statePlay_00401508;
  if (iVar1 == 1) {
    iVar1 = ProcInMoviePlaying_RecvPbPauseCmd(*(uint *)(param_1 + 4),2);
    if ((iVar1 != 0) && (*(long *)PTR_s_merrCtxPlaying_00402880 != 0)) {
      FUN_001fe0e8(*(long *)PTR_s_merrCtxPlaying_00402880,iVar1);
    }
  }
  else {
    if (iVar1 == 0) {
      uVar2 = 8;
      local_c = 4;
      local_10 = 0x10212160;
    }
    else {
      if (iVar1 == 2) {
        local_c = 4;
        local_10 = 0x10222160;
        FUN_001bf858((evtPbPauseFinishedParam *)&local_10,8);
        iVar1 = 2;
        goto LAB_001c27c0;
      }
      uVar2 = 0xc;
      local_c = 3;
      local_10 = 0x10232160;
      local_8 = iVar1;
    }
    iVar1 = 2;
    FUN_001bf858((evtPbPauseFinishedParam *)&local_10,uVar2);
  }
LAB_001c27c0:
  thread::normalLock::unlock((normalLock *)PTR_s_moviePlayLock_00402d68);
  if (iVar1 != 0) {
    evtPbPauseFinishedParam::evtPbPauseFinishedParam((evtPbPauseFinishedParam *)&local_10);
    local_8 = *(int *)(param_1 + 4);
    local_c = iVar1;
    SetIssueEvent(0x1014,(evtPbPauseFinishedParam *)&local_10,0xc);
    UnlockPbApi(0x1014);
  }
  local_10 = 0x102f2160;
  local_c = 3;
  local_8 = iVar1;
  FUN_001bf858((evtPbPauseFinishedParam *)&local_10,0xc);
  pthread_mutex_unlock((pthread_mutex_t *)PTR_g_integApiMutex_00401418);
  local_10 = 0x31;
  local_c = iVar1;
  FUN_001bf858((evtPbPauseFinishedParam *)&local_10,8);
  return iVar1;
}

