// CMXF_ExportBegin
// VA 180012480

int CMXF_ExportBegin(undefined **param_1,undefined8 *param_2,undefined8 param_3,undefined **param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined **local_18;
  undefined8 *local_10;
  
                    /* 0x12480  7  CMXF_ExportBegin */
  if ((param_2 == (undefined8 *)0x0) || (*param_2 = 0, param_1 == (undefined **)0x0)) {
    iVar3 = -0x7ff8ffa9;
  }
  else {
    if (*(int *)(param_1 + 0xc) != 0) {
      *(undefined4 *)(param_1 + 0xc) = 1;
    }
    puVar4 = (undefined8 *)FUN_1800baa00(0x2e0);
    if (puVar4 == (undefined8 *)0x0) {
      puVar4 = (undefined8 *)0x0;
    }
    else {
      puVar4 = FUN_180018c80(puVar4);
    }
    local_18 = PTypedRefObject<CMxfExport>::vftable;
    local_10 = (undefined8 *)0x0;
    if (puVar4 != (undefined8 *)0x0) {
      LOCK();
      *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
      UNLOCK();
    }
    (*(code *)PTypedRefObject<CMxfExport>::vftable[1])(&local_18);
    local_10 = puVar4;
    iVar3 = FUN_1800278a0((longlong)puVar4,param_1,param_3,param_4);
    if (-1 < iVar3) {
      LOCK();
      *(int *)(local_10 + 1) = *(int *)(local_10 + 1) + 1;
      UNLOCK();
      *param_2 = local_10;
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
  }
  return iVar3;
}

