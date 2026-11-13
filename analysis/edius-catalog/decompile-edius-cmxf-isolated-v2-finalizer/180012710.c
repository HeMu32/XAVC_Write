// CMXF_ExportEnd
// VA 180012710

undefined8 CMXF_ExportEnd(undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined **local_18;
  undefined8 *local_10;
  
                    /* 0x12710  10  CMXF_ExportEnd */
  if (param_1 != (undefined8 *)0x0) {
    local_18 = PTypedRefObject<CMxfExport>::vftable;
    local_10 = (undefined8 *)0x0;
    LOCK();
    *(int *)(param_1 + 1) = *(int *)(param_1 + 1) + 1;
    UNLOCK();
    (*(code *)PTypedRefObject<CMxfExport>::vftable[1])(&local_18);
    local_10 = param_1;
    FUN_18001e1f0((longlong)param_1,0,(int *)0x0);
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

