// CMXF_CloseFile
// VA 180011ff0

undefined4 CMXF_CloseFile(undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined **local_18;
  undefined8 *local_10;
  
                    /* 0x11ff0  2  CMXF_CloseFile */
  if (param_1 != (undefined8 *)0x0) {
    local_18 = PTypedRefObject<CMxfIndexMaker>::vftable;
    local_10 = (undefined8 *)0x0;
    LOCK();
    *(int *)(param_1 + 1) = *(int *)(param_1 + 1) + 1;
    UNLOCK();
    (*(code *)PTypedRefObject<CMxfIndexMaker>::vftable[1])(&local_18);
    local_10 = param_1;
    uVar3 = FUN_180065b10((longlong)param_1);
    LOCK();
    piVar1 = (int *)(local_10 + 1);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar2 < 2) && (local_10 != (undefined8 *)0x0)) {
      (**(code **)*local_10)(local_10,1);
    }
    local_18 = PTypedRefObject<CMxfIndexMaker>::vftable;
    if (local_10 != (undefined8 *)0x0) {
      LOCK();
      piVar1 = (int *)(local_10 + 1);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if ((iVar2 < 2) && (local_10 != (undefined8 *)0x0)) {
        (**(code **)*local_10)(local_10,1);
      }
    }
    return uVar3;
  }
  return 0x80070057;
}

