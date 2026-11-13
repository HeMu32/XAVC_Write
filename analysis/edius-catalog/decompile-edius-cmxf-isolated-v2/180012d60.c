// CMXF_WriteFile
// VA 180012d60

undefined4 CMXF_WriteFile(undefined8 *param_1,void *param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined **local_18;
  undefined8 *local_10;
  
                    /* 0x12d60  18  CMXF_WriteFile */
  if (param_1 == (undefined8 *)0x0) {
    uVar3 = 0x80070057;
  }
  else {
    local_18 = PTypedRefObject<CMxfIndexMaker>::vftable;
    local_10 = (undefined8 *)0x0;
    LOCK();
    *(int *)(param_1 + 1) = *(int *)(param_1 + 1) + 1;
    UNLOCK();
    (*(code *)PTypedRefObject<CMxfIndexMaker>::vftable[1])(&local_18);
    local_10 = param_1;
    uVar3 = FUN_1800767c0((longlong)param_1,param_2,param_3);
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
  }
  return uVar3;
}

