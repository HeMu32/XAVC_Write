// CMXF_CreateFile
// VA 1800120c0

ulonglong CMXF_CreateFile(wchar_t *param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4
                         )

{
  int *piVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  undefined **local_18;
  undefined8 *local_10;
  
                    /* 0x120c0  3  CMXF_CreateFile */
  if (param_2 == (undefined8 *)0x0) {
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
    local_18 = PTypedRefObject<CMxfIndexMaker>::vftable;
    local_10 = (undefined8 *)0x0;
    if (puVar4 != (undefined8 *)0x0) {
      LOCK();
      *(int *)(puVar4 + 1) = *(int *)(puVar4 + 1) + 1;
      UNLOCK();
    }
    (*(code *)PTypedRefObject<CMxfIndexMaker>::vftable[1])(&local_18);
    local_10 = puVar4;
    uVar5 = FUN_180065f20(puVar4,param_1,0,param_4);
    uVar3 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) {
      FUN_180065b10((longlong)local_10);
    }
    else {
      LOCK();
      *(int *)(local_10 + 1) = *(int *)(local_10 + 1) + 1;
      UNLOCK();
      *param_2 = local_10;
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
  }
  return uVar3;
}

