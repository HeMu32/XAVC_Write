// FUN_1800a04b0
// VA 1800a04b0

BOOL FUN_1800a04b0(undefined8 *param_1,undefined8 *param_2,LPCVOID param_3,DWORD param_4,
                  LPDWORD param_5,LPOVERLAPPED param_6)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  BOOL BVar6;
  DWORD local_res8 [2];
  LPOVERLAPPED local_58;
  LPDWORD local_50;
  LPCVOID local_48 [2];
  undefined8 *local_38;
  undefined8 local_30;
  longlong local_28;
  longlong *local_20;
  longlong local_18;
  longlong *plStack_10;
  
  local_18 = 0;
  plStack_10 = (longlong *)0x0;
  local_38 = param_1;
  if (7 < (ulonglong)param_1[3]) {
    local_38 = (undefined8 *)*param_1;
  }
  local_30 = param_1[2];
  FUN_18009e830(&local_28,&local_38,&local_18);
  if (local_28 == 0) {
    BVar6 = WriteFile(param_2,param_3,param_4,param_5,param_6);
  }
  else {
    plVar4 = *(longlong **)(local_28 + 0x238);
    if (plVar4 == (longlong *)0x0) {
      SetLastError(0x32);
      BVar6 = 0;
    }
    else {
      local_58 = param_6;
      local_50 = param_5;
      local_res8[0] = param_4;
      local_48[0] = param_3;
      local_38 = param_2;
      BVar6 = (**(code **)(*plVar4 + 0x10))
                        (plVar4,&local_38,local_48,local_res8,&local_50,&local_58);
    }
  }
  if (local_20 != (longlong *)0x0) {
    LOCK();
    plVar4 = local_20 + 1;
    lVar5 = *plVar4;
    *(int *)plVar4 = (int)*plVar4 + -1;
    UNLOCK();
    if ((int)lVar5 == 1) {
      (**(code **)*local_20)(local_20);
      LOCK();
      piVar1 = (int *)((longlong)local_20 + 0xc);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (**(code **)(*local_20 + 8))(local_20);
      }
    }
  }
  plVar4 = plStack_10;
  if (plStack_10 != (longlong *)0x0) {
    LOCK();
    plVar2 = plStack_10 + 1;
    lVar5 = *plVar2;
    *(int *)plVar2 = (int)*plVar2 + -1;
    UNLOCK();
    if ((int)lVar5 == 1) {
      (**(code **)*plStack_10)(plStack_10);
      LOCK();
      piVar1 = (int *)((longlong)plVar4 + 0xc);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (**(code **)(*plVar4 + 8))(plVar4);
      }
    }
  }
  return BVar6;
}

