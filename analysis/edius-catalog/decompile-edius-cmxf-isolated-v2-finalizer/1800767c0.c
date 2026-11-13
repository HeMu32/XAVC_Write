// FUN_1800767c0
// VA 1800767c0

undefined4 FUN_1800767c0(longlong param_1,void *param_2,uint param_3)

{
  LPCRITICAL_SECTION p_Var1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined **local_60;
  undefined8 *local_58;
  undefined **local_50;
  undefined8 *local_48;
  LPCRITICAL_SECTION local_40;
  undefined1 local_38;
  
  if (((((*(uint *)(param_1 + 0x2a0) & 4) != 0) &&
       (((byte)*(uint *)(param_1 + 0x2a0) & 0x14) != 0x14)) &&
      (lVar7 = *(longlong *)(param_1 + 0xb8), lVar7 != 0)) &&
     (lVar7 = SUB168(SEXT816(-0x4de9bd37a6f4de9b) * SEXT816(lVar7),8) + lVar7,
     lVar7 >> 7 != lVar7 >> 0x3f)) {
    (**(code **)(**(longlong **)(param_1 + 0xb8) + 8))
              (*(longlong **)(param_1 + 0xb8),param_2,(ulonglong)param_3);
  }
  puVar6 = (undefined8 *)FUN_1800baa00(0x30);
  if (puVar6 == (undefined8 *)0x0) {
    puVar6 = (undefined8 *)0x0;
  }
  else {
    puVar6 = FUN_1800a0850(puVar6,0);
  }
  local_60 = PTypedRefObject<cmlib::CMemory>::vftable;
  local_58 = (undefined8 *)0x0;
  if (puVar6 != (undefined8 *)0x0) {
    LOCK();
    *(int *)(puVar6 + 1) = *(int *)(puVar6 + 1) + 1;
    UNLOCK();
  }
  (*(code *)PTypedRefObject<cmlib::CMemory>::vftable[1])(&local_60);
  local_58 = puVar6;
  FUN_1800a0950((longlong)puVar6,param_2,(ulonglong)param_3);
  puVar6 = local_58;
  if (((byte)*(undefined4 *)(param_1 + 0x2a0) & 0x14) == 0x14) {
    local_50 = PTypedRefObject<cmlib::CMemory>::vftable;
    local_48 = (undefined8 *)0x0;
    if (local_58 != (undefined8 *)0x0) {
      LOCK();
      *(int *)(local_58 + 1) = *(int *)(local_58 + 1) + 1;
      UNLOCK();
    }
    (*(code *)PTypedRefObject<cmlib::CMemory>::vftable[1])(&local_50);
    local_48 = puVar6;
    p_Var1 = (LPCRITICAL_SECTION)(param_1 + 0x28);
    local_38 = 1;
    local_40 = p_Var1;
    EnterCriticalSection(p_Var1);
    FUN_180077310((longlong *)(param_1 + 0x318),(longlong)&local_50);
    LeaveCriticalSection(p_Var1);
    local_50 = PTypedRefObject<cmlib::CMemory>::vftable;
    if (local_48 != (undefined8 *)0x0) {
      LOCK();
      piVar2 = (int *)(local_48 + 1);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 < 2) {
        (**(code **)*local_48)(local_48,1);
      }
    }
  }
  p_Var1 = (LPCRITICAL_SECTION)(param_1 + 0x28);
  local_38 = 1;
  local_40 = p_Var1;
  EnterCriticalSection(p_Var1);
  if ((*(int *)(param_1 + 0x50) == 0x1000001) || (*(int *)(param_1 + 0x50) == 0x1000002)) {
    bVar5 = true;
  }
  else {
    bVar5 = false;
  }
  LeaveCriticalSection(p_Var1);
  puVar6 = local_58;
  if (bVar5) {
    lVar7 = *(longlong *)(param_1 + 0x20);
    local_50 = PTypedRefObject<cmlib::CMemory>::vftable;
    local_48 = (undefined8 *)0x0;
    if (local_58 != (undefined8 *)0x0) {
      LOCK();
      *(int *)(local_58 + 1) = *(int *)(local_58 + 1) + 1;
      UNLOCK();
    }
    (*(code *)PTypedRefObject<cmlib::CMemory>::vftable[1])(&local_50);
    local_48 = puVar6;
    FUN_1800020e0(lVar7,&local_50);
  }
  local_38 = 1;
  local_40 = p_Var1;
  EnterCriticalSection(p_Var1);
  uVar4 = *(undefined4 *)(param_1 + 0x50);
  LeaveCriticalSection(p_Var1);
  local_60 = PTypedRefObject<cmlib::CMemory>::vftable;
  if (local_58 != (undefined8 *)0x0) {
    LOCK();
    piVar2 = (int *)(local_58 + 1);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if ((iVar3 < 2) && (local_58 != (undefined8 *)0x0)) {
      (**(code **)*local_58)(local_58,1);
    }
  }
  return uVar4;
}

