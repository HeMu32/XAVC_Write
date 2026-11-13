// mpr::SetClipStatusInRec
// Ghidra address: 001dc578

/* mpr::SetClipStatusInRec(mpr::SetClipStatusInRecInParam const&) */

undefined4 mpr::SetClipStatusInRec(SetClipStatusInRecInParam *param_1)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 local_58;
  undefined4 local_54;
  uint local_50;
  undefined4 uStack_4c;
  
  FUN_001c9f24(param_1,0xc);
  SetClipStatusInRecInParam::DbgPrint();
  pthread_mutex_lock((pthread_mutex_t *)PTR_g_integApiMutex_00401418);
  local_54 = 4;
  local_58 = 0x18002110;
  FUN_001c9f24((execIssueEvent_t *)&local_58,8);
  thread::normalLock::lock((normalLock *)PTR_s_integRecordMovieLock_00402670);
  if (*(uint *)(param_1 + 8) < 4) {
    iVar5 = 0;
    pcVar3 = PTR_s_recSequenceInfo_004019c0 + 8;
    do {
      cVar2 = *pcVar3;
      if (cVar2 != '\0') {
        iVar6 = 0;
        piVar8 = (int *)(PTR_s_movieRecInfo_00401670 + 0x260);
        cVar4 = '\0';
        while (iVar6 != *(int *)(PTR_s_movieRecInfo_00401670 + 0x270)) {
          piVar7 = piVar8 + 1;
          iVar1 = *piVar8;
          iVar6 = iVar6 + 1;
          piVar8 = piVar7;
          if (*(int *)(pcVar3 + 0x280) == iVar1) {
            cVar4 = cVar2;
          }
        }
        iVar6 = 0;
        piVar8 = (int *)(PTR_s_movieRecInfo_00401670 + 0x274);
        while (iVar6 != *(int *)(PTR_s_movieRecInfo_00401670 + 0x284)) {
          piVar7 = piVar8 + 1;
          iVar1 = *piVar8;
          iVar6 = iVar6 + 1;
          piVar8 = piVar7;
          if (*(int *)(pcVar3 + 0x280) == iVar1) {
            cVar4 = cVar2;
          }
        }
        if (cVar4 == '\0') {
          iVar5 = iVar5 + 1;
        }
      }
      pcVar3 = pcVar3 + 0x1ac8;
    } while (PTR_s_recSequenceInfo_004019c0 + 0x6b28 != pcVar3);
    if (iVar5 != 0) {
      uVar9 = 0;
      uVar10 = 0;
      EnqueueExecSetClipStatus(PTR_s_movieRecInfo_00401670,PTR_s_recSequenceInfo_004019c0);
      goto LAB_001dc73c;
    }
    uVar9 = 0;
    local_54 = 3;
    uVar10 = 4;
    local_58 = 0x18022110;
    local_50 = 0x38c6;
    FUN_001c9f24((execIssueEvent_t *)&local_58,0xc);
  }
  else {
    uVar9 = 3;
    uVar10 = 3;
    local_58 = 0x18012110;
    local_54 = 3;
    local_50 = *(uint *)(param_1 + 8);
    FUN_001c9f24((execIssueEvent_t *)&local_58,0xc);
  }
  local_58 = 0x1035;
  local_54 = uVar10;
  NotifyClipStatusInRecFinished((execIssueEvent_t *)&local_58);
LAB_001dc73c:
  thread::normalLock::unlock((normalLock *)PTR_s_integRecordMovieLock_00402670);
  local_54 = 2;
  local_58 = 0x180f2110;
  local_50 = uVar10;
  uStack_4c = uVar9;
  FUN_001c9f24((execIssueEvent_t *)&local_58,0x10);
  pthread_mutex_unlock((pthread_mutex_t *)PTR_g_integApiMutex_00401418);
  local_58 = 0x7d;
  local_54 = uVar10;
  FUN_001c9f24((execIssueEvent_t *)&local_58,8);
  return uVar9;
}

