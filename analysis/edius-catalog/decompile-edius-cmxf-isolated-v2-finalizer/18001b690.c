// FUN_18001b690
// VA 18001b690

void FUN_18001b690(undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  
  *param_1 = CMxfExport::vftable;
  FUN_18001e1f0((longlong)param_1,0,(int *)0x0);
  param_1[0x59] = PTypedRefObject<CMxfExport::CTextDescriptiveMetadata>::vftable;
  puVar3 = (undefined8 *)param_1[0x5a];
  if (puVar3 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puVar3 + 1);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 2) {
      (**(code **)*puVar3)(puVar3,1);
    }
    param_1[0x5a] = 0;
  }
  param_1[0x56] = PTypedRefObject<CMxfExport::CP2DescriptiveMetadata>::vftable;
  puVar3 = (undefined8 *)param_1[0x57];
  if (puVar3 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puVar3 + 1);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 2) {
      (**(code **)*puVar3)(puVar3,1);
    }
    param_1[0x57] = 0;
  }
  FUN_18001b5a0(param_1 + 0x53);
  FUN_18001b5a0(param_1 + 0x50);
  param_1[0x4d] = PTypedRefObject<CWaveCacheMaker>::vftable;
  puVar3 = (undefined8 *)param_1[0x4e];
  if (puVar3 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puVar3 + 1);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 2) {
      (**(code **)*puVar3)(puVar3,1);
    }
    param_1[0x4e] = 0;
  }
  param_1[0x49] = PTypedRefObject<CClipPropertiesXml::CProxyInfo>::vftable;
  puVar3 = (undefined8 *)param_1[0x4a];
  if (puVar3 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puVar3 + 1);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 2) {
      (**(code **)*puVar3)(puVar3,1);
    }
    param_1[0x4a] = 0;
  }
  param_1[0x47] = PTypedRefObject<CClipPropertiesXml::CK2Metadata>::vftable;
  puVar3 = (undefined8 *)param_1[0x48];
  if (puVar3 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puVar3 + 1);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 2) {
      (**(code **)*puVar3)(puVar3,1);
    }
    param_1[0x48] = 0;
  }
  FUN_180001b30(param_1 + 0x45);
  param_1[0x43] = PTypedRefObject<CClipPropertiesXml>::vftable;
  puVar3 = (undefined8 *)param_1[0x44];
  if (puVar3 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puVar3 + 1);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 2) {
      (**(code **)*puVar3)(puVar3,1);
    }
    param_1[0x44] = 0;
  }
  FUN_180009070(param_1 + 0x40);
  FUN_180009070(param_1 + 0x3d);
  FUN_18001a890(param_1 + 0x38);
  FUN_18001a910(param_1 + 0x31);
  param_1[0x2f] = PTypedRefObject<CMxfExportContextBase>::vftable;
  puVar3 = (undefined8 *)param_1[0x30];
  if (puVar3 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puVar3 + 1);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 2) {
      (**(code **)*puVar3)(puVar3,1);
    }
    param_1[0x30] = 0;
  }
  FUN_18001a690(param_1 + 0x2b);
  FUN_18001a610(param_1 + 0x27);
  FUN_18001a790(param_1 + 0x23);
  FUN_18001a790(param_1 + 0x1d);
  FUN_18001a790(param_1 + 0x19);
  FUN_180009070(param_1 + 0x14);
  FUN_180009070(param_1 + 0x11);
  FUN_180009070(param_1 + 0xe);
  FUN_18001a890(param_1 + 4);
  *param_1 = CRefObject::vftable;
  return;
}

