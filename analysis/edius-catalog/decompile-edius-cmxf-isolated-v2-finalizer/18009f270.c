// FUN_18009f270
// VA 18009f270

HANDLE FUN_18009f270(wchar_t *param_1,DWORD param_2,DWORD param_3,LPSECURITY_ATTRIBUTES param_4,
                    DWORD param_5,DWORD param_6,HANDLE param_7)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  HANDLE pvVar6;
  DWORD local_res8 [2];
  DWORD local_78 [2];
  DWORD local_70 [2];
  DWORD local_68 [4];
  wchar_t *local_58;
  size_t local_50;
  HANDLE local_48;
  LPSECURITY_ATTRIBUTES local_40;
  longlong local_38;
  longlong *local_30;
  longlong local_28;
  longlong *plStack_20;
  
  if (param_1 == (wchar_t *)0x0) {
    SetLastError(0x57);
    pvVar6 = (HANDLE)0xffffffffffffffff;
  }
  else {
    local_28 = 0;
    plStack_20 = (longlong *)0x0;
    local_50 = wcslen(param_1);
    local_58 = param_1;
    FUN_18009e830(&local_38,&local_58,&local_28);
    if (local_38 == 0) {
      pvVar6 = CreateFileW(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    else {
      plVar4 = *(longlong **)(local_38 + 0xf8);
      if (plVar4 == (longlong *)0x0) {
        SetLastError(0x32);
        pvVar6 = (HANDLE)0xffffffffffffffff;
      }
      else {
        local_48 = param_7;
        local_res8[0] = param_6;
        local_78[0] = param_5;
        local_70[0] = param_3;
        local_68[0] = param_2;
        local_58 = param_1;
        local_40 = param_4;
        pvVar6 = (HANDLE)(**(code **)(*plVar4 + 0x10))
                                   (plVar4,&local_58,local_68,local_70,&local_40,local_78,local_res8
                                    ,&local_48);
      }
    }
    if (local_30 != (longlong *)0x0) {
      LOCK();
      plVar4 = local_30 + 1;
      lVar5 = *plVar4;
      *(int *)plVar4 = (int)*plVar4 + -1;
      UNLOCK();
      if ((int)lVar5 == 1) {
        (**(code **)*local_30)(local_30);
        LOCK();
        piVar1 = (int *)((longlong)local_30 + 0xc);
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar3 == 1) {
          (**(code **)(*local_30 + 8))(local_30);
        }
      }
    }
    plVar4 = plStack_20;
    if (plStack_20 != (longlong *)0x0) {
      LOCK();
      plVar2 = plStack_20 + 1;
      lVar5 = *plVar2;
      *(int *)plVar2 = (int)*plVar2 + -1;
      UNLOCK();
      if ((int)lVar5 == 1) {
        (**(code **)*plStack_20)(plStack_20);
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
  }
  return pvVar6;
}

