// FUN_180065b10
// VA 180065b10

undefined4 FUN_180065b10(longlong param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  byte *pbVar2;
  undefined4 uVar3;
  longlong *plVar4;
  int iVar5;
  ulonglong uVar6;
  longlong lVar7;
  int iVar8;
  LPCRITICAL_SECTION local_50;
  undefined8 local_48;
  
  lVar7 = *(longlong *)(param_1 + 0x20);
  if ((lVar7 != 0) && (lVar7 / 0xd8 + (lVar7 >> 0x3f) != lVar7 >> 0x3f)) {
    local_50 = (LPCRITICAL_SECTION)PTypedRefObject<cmlib::CMemory>::vftable;
    local_48 = 0;
    FUN_180002920(lVar7 + 0x20,&local_50);
    if (*(HANDLE *)(param_1 + 0x58) != (HANDLE)0x0) {
      WaitForSingleObject(*(HANDLE *)(param_1 + 0x58),0xffffffff);
      CloseHandle(*(HANDLE *)(param_1 + 0x58));
      *(undefined8 *)(param_1 + 0x58) = 0;
    }
    (**(code **)(*(longlong *)(param_1 + 0x18) + 0x18))();
  }
  iVar8 = 0;
  pbVar2 = (byte *)(param_1 + 0x2a0);
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x28);
  if ((*pbVar2 & 0xc) != 0) {
    local_48 = CONCAT71(local_48._1_7_,1);
    local_50 = lpCriticalSection;
    EnterCriticalSection(lpCriticalSection);
    piVar1 = (int *)(param_1 + 0x50);
    iVar5 = *piVar1;
    LeaveCriticalSection(lpCriticalSection);
    if (((((iVar5 == 0) && ((*pbVar2 & 4) != 0)) && (*(char *)(param_1 + 0x34c) == '\0')) &&
        ((*(int *)(param_1 + 0x128) == 2 && (*(longlong *)(param_1 + 0x240) < 0)))) &&
       ((*(int *)(param_1 + 0x348) != -0x80000000 &&
        ((lVar7 = *(longlong *)(param_1 + 0xb8), lVar7 != 0 &&
         (lVar7 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar7),8) + lVar7,
         lVar7 >> 7 != lVar7 >> 0x3f)))))) {
      FUN_180075ce0(param_1);
    }
    (**(code **)(*(longlong *)(param_1 + 0xb0) + 0x18))();
    local_48 = CONCAT71(local_48._1_7_,1);
    local_50 = lpCriticalSection;
    EnterCriticalSection(lpCriticalSection);
    LeaveCriticalSection(lpCriticalSection);
    plVar4 = *(longlong **)(param_1 + 0x2b0);
    if ((plVar4 != (longlong *)0x0) &&
       ((longlong)plVar4 / 0xa0 + ((longlong)plVar4 >> 0x3f) != (longlong)plVar4 >> 0x3f)) {
      (**(code **)(*plVar4 + 0x18))();
      (**(code **)(*(longlong *)(param_1 + 0x2a8) + 0x18))();
    }
    lVar7 = *(longlong *)(param_1 + 200);
    if ((lVar7 != 0) && (lVar7 / 0xd0 + (lVar7 >> 0x3f) != lVar7 >> 0x3f)) {
      local_48 = CONCAT71(local_48._1_7_,1);
      local_50 = lpCriticalSection;
      EnterCriticalSection(lpCriticalSection);
      iVar5 = *piVar1;
      LeaveCriticalSection(lpCriticalSection);
      if (iVar5 < 0) {
        FUN_18005e500(*(longlong *)(param_1 + 200));
      }
      else {
        iVar5 = FUN_180069bb0(param_1);
        if (((iVar5 == 0) && (*(char *)(param_1 + 0x34c) == '\0')) &&
           (*(longlong *)(param_1 + 0x240) < 0)) {
          iVar5 = *(int *)(param_1 + 0x348);
          if (((iVar5 != -0x80000000) && (*(int *)(param_1 + 0x128) == 2)) &&
             ((1 < *(uint *)(param_1 + 0x250) &&
              ((0 < iVar5 && (uVar6 = FUN_18005ed50(*(longlong *)(param_1 + 200)), uVar6 != 0))))))
          {
            lVar7 = FUN_18005ed30(*(longlong *)(param_1 + 200),uVar6 - 1);
            iVar5 = (int)((longlong)iVar5 % (longlong)(ulonglong)*(uint *)(param_1 + 0x250));
            if (iVar5 != 0) {
              *(int *)(lVar7 + 4) = iVar5;
            }
          }
        }
      }
      FUN_18005e4b0(*(longlong *)(param_1 + 200));
      lVar7 = *(longlong *)(param_1 + 200);
      if ((lVar7 != 0) && (lVar7 / 0xd0 + (lVar7 >> 0x3f) != lVar7 >> 0x3f)) {
        if (*(char *)(param_1 + 0x11a) == '\0') {
          if (*(char *)(param_1 + 0x11c) != '\0') {
            iVar8 = 3;
          }
        }
        else {
          iVar8 = 1;
        }
        FUN_18005eaa0(lVar7,1,0,iVar8);
      }
      (**(code **)(*(longlong *)(param_1 + 0xc0) + 0x18))();
    }
    if ((*pbVar2 & 4) != 0) {
      local_48 = CONCAT71(local_48._1_7_,1);
      local_50 = lpCriticalSection;
      EnterCriticalSection(lpCriticalSection);
      iVar8 = *piVar1;
      LeaveCriticalSection(lpCriticalSection);
      if (iVar8 < 0) {
        local_50 = (LPCRITICAL_SECTION)(param_1 + 0x60);
        local_48 = *(undefined8 *)(param_1 + 0x70);
        if (7 < *(ulonglong *)(param_1 + 0x78)) {
          local_50 = (LPCRITICAL_SECTION)local_50->DebugInfo;
        }
        FUN_180093a80(&local_50,'\0');
      }
    }
    local_50 = (LPCRITICAL_SECTION)(param_1 + 0x80);
    local_48 = *(undefined8 *)(param_1 + 0x90);
    if (7 < *(ulonglong *)(param_1 + 0x98)) {
      local_50 = (LPCRITICAL_SECTION)local_50->DebugInfo;
    }
    FUN_180093a80(&local_50,'\0');
  }
  local_48 = CONCAT71(local_48._1_7_,1);
  local_50 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  uVar3 = *(undefined4 *)(param_1 + 0x50);
  LeaveCriticalSection(lpCriticalSection);
  return uVar3;
}

