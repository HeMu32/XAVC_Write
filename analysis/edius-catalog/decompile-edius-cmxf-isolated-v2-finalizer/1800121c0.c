// CMXF_CreateFileEx
// VA 1800121c0

ulonglong CMXF_CreateFileEx(wchar_t *param_1,undefined4 param_2,undefined8 *param_3,
                           undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  undefined **local_28;
  undefined8 *local_20;
  
                    /* 0x121c0  4  CMXF_CreateFileEx */
  if (param_3 == (undefined8 *)0x0) {
    uVar3 = 0x80070057;
  }
  else {
    puVar4 = (undefined8 *)FUN_1800baa00(0x390);
    if (puVar4 == (undefined8 *)0x0) {
      puVar4 = (undefined8 *)0x0;
    }
    else {
      puVar4 = FUN_180060ff0(puVar4);
    }
    local_28 = PTypedRefObject<CMxfIndexMaker>::vftable;
    local_20 = (undefined8 *)0x0;
    if (puVar4 != (undefined8 *)0x0) {
      LOCK();
      *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
      UNLOCK();
    }
    (*(code *)PTypedRefObject<CMxfIndexMaker>::vftable[1])(&local_28);
    local_20 = puVar4;
    uVar5 = FUN_180065f20(puVar4,param_1,param_2,param_4);
    uVar3 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) {
      FUN_180065b10((longlong)local_20);
    }
    else {
      LOCK();
      *(int *)(local_20 + 1) = *(int *)(local_20 + 1) + 1;
      UNLOCK();
      *param_3 = local_20;
    }
    local_28 = PTypedRefObject<CMxfIndexMaker>::vftable;
    if (local_20 != (undefined8 *)0x0) {
      LOCK();
      piVar1 = (int *)(local_20 + 1);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if ((iVar2 < 2) && (local_20 != (undefined8 *)0x0)) {
        (**(code **)*local_20)(local_20,1);
      }
    }
  }
  return uVar3;
}

