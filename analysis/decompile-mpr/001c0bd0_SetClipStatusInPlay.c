// mpr::SetClipStatusInPlay
// Ghidra address: 001c0bd0

/* mpr::SetClipStatusInPlay(mpr::SetClipStatusInPlayInParam const&) */

int mpr::SetClipStatusInPlay(SetClipStatusInPlayInParam *param_1)

{
  undefined *this;
  int iVar1;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 local_10;
  int iStack_c;
  undefined4 local_8;
  
  FUN_001bf858(param_1,0x14);
  SetClipStatusInPlayInParam::DbgPrint();
  pthread_mutex_lock((pthread_mutex_t *)PTR_g_integApiMutex_00401418);
  LockPbApi(0x1036);
  this = PTR_s_moviePlayLock_00402d68;
  thread::normalLock::lock((normalLock *)PTR_s_moviePlayLock_00402d68);
  uStack_1c = msidconv::GetSlotID((msidconv *)PTR_g_msidconv_00401cd8,*(uint *)(param_1 + 0xc));
  local_20 = *(undefined4 *)(param_1 + 8);
  local_18 = *(undefined4 *)(param_1 + 0x10);
  iVar1 = MoviePlayer::SetClipStatus((SetClipStatusInParam *)&local_20);
  thread::normalLock::unlock((normalLock *)this);
  if (iVar1 != 0) {
    local_8 = *(undefined4 *)(param_1 + 0xc);
    local_10 = 0x1036;
    iStack_c = iVar1;
    SetIssueEvent(0x1036,&local_10,0xc);
    UnlockPbApi(0x1036);
  }
  pthread_mutex_unlock((pthread_mutex_t *)PTR_g_integApiMutex_00401418);
  local_10 = 0x7f;
  iStack_c = iVar1;
  FUN_001bf858(&local_10,8);
  return iVar1;
}

