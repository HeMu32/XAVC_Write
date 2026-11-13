// CMXF_ExportCancel
// VA 180012590

undefined8 CMXF_ExportCancel(undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined **local_18;
  undefined8 *local_10;
  
                    /* 0x12590  8  CMXF_ExportCancel */
  if (param_1 != (undefined8 *)0x0) {
    local_18 = PTypedRefObject<CMxfExport>::vftable;
    local_10 = (undefined8 *)0x0;
    LOCK();
    *(int *)(param_1 + 1) = *(int *)(param_1 + 1) + 1;
    UNLOCK();
    (*(code *)PTypedRefObject<CMxfExport>::vftable[1])(&local_18);
    local_10 = param_1;
    FUN_18001e1f0((longlong)param_1,1,(int *)0x0);
    LOCK();
    piVar1 = (int *)(local_10 + 1);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar2 < 2) && (local_10 != (undefined8 *)0x0)) {
      (**(code **)*local_10)(local_10,1);
    }
    local_18 = PTypedRefObject<CMxfExport>::vftable;
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
    return 0;
  }
  return 0x80070057;
}

