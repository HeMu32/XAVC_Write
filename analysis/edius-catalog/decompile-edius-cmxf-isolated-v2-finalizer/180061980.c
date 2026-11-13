// FUN_180061980
// VA 180061980

void FUN_180061980(undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  
  *param_1 = CMxfIndexMaker::vftable;
  param_1[2] = CMxfIndexMaker::vftable;
  FUN_180065b10((longlong)param_1);
  FUN_18001b410(param_1 + 0x6e);
  param_1[0x6b] = PTypedRefObject<CH264Parser>::vftable;
  puVar4 = (undefined8 *)param_1[0x6c];
  if (puVar4 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puVar4 + 1);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 2) {
      (**(code **)*puVar4)(puVar4,1);
    }
    param_1[0x6c] = 0;
  }
  param_1[0x67] = PTypedRefObject<mxfcore::CRandomIndexPack>::vftable;
  puVar4 = (undefined8 *)param_1[0x68];
  if (puVar4 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puVar4 + 1);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 2) {
      (**(code **)*puVar4)(puVar4,1);
    }
    param_1[0x68] = 0;
  }
  FUN_180001b30(param_1 + 99);
  param_1[0x60] = PTypedRefObject<CMxfIndexMaker::CEssenceBuffer>::vftable;
  puVar4 = (undefined8 *)param_1[0x61];
  if (puVar4 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puVar4 + 1);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 2) {
      (**(code **)*puVar4)(puVar4,1);
    }
    param_1[0x61] = 0;
  }
  FUN_180008f30(param_1 + 0x5d);
  FUN_180008f30(param_1 + 0x5a);
  FUN_180032240(param_1 + 0x57);
  param_1[0x55] = PTypedRefObject<CWaveCacheMakerEx>::vftable;
  puVar4 = (undefined8 *)param_1[0x56];
  if (puVar4 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puVar4 + 1);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 2) {
      (**(code **)*puVar4)(puVar4,1);
    }
    param_1[0x56] = 0;
  }
  FUN_180001b30(param_1 + 0x52);
  param_1[0x4f] = PTypedRefObject<mxfcore::CMetadataSet>::vftable;
  puVar4 = (undefined8 *)param_1[0x50];
  if (puVar4 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puVar4 + 1);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 2) {
      (**(code **)*puVar4)(puVar4,1);
    }
    param_1[0x50] = 0;
  }
  FUN_18001a590(param_1 + 0x41);
  FUN_18001a890(param_1 + 0x3d);
  FUN_18001a890(param_1 + 0x39);
  FUN_18001a590(param_1 + 0x35);
  FUN_18001a590(param_1 + 0x31);
  FUN_18001a590(param_1 + 0x2d);
  FUN_180009070(param_1 + 0x29);
  FUN_180009070(param_1 + 0x26);
  param_1[0x20] = PTypedRefObject<mxfcore::CIndexTable>::vftable;
  puVar4 = (undefined8 *)param_1[0x21];
  if (puVar4 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puVar4 + 1);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 2) {
      (**(code **)*puVar4)(puVar4,1);
    }
    param_1[0x21] = 0;
  }
  param_1[0x1e] = PTypedRefObject<mxfcore::CIndexTable>::vftable;
  puVar4 = (undefined8 *)param_1[0x1f];
  if (puVar4 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puVar4 + 1);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 2) {
      (**(code **)*puVar4)(puVar4,1);
    }
    param_1[0x1f] = 0;
  }
  param_1[0x1c] = PTypedRefObject<mxfcore::CPartition>::vftable;
  puVar4 = (undefined8 *)param_1[0x1d];
  if (puVar4 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puVar4 + 1);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 2) {
      (**(code **)*puVar4)(puVar4,1);
    }
    param_1[0x1d] = 0;
  }
  param_1[0x1a] = PTypedRefObject<mxfcore::CPartition>::vftable;
  puVar4 = (undefined8 *)param_1[0x1b];
  if (puVar4 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puVar4 + 1);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 2) {
      (**(code **)*puVar4)(puVar4,1);
    }
    param_1[0x1b] = 0;
  }
  param_1[0x18] = PTypedRefObject<CMxfIndexFileWriter>::vftable;
  puVar4 = (undefined8 *)param_1[0x19];
  if (puVar4 != (undefined8 *)0x0) {
    LOCK();
    piVar1 = (int *)(puVar4 + 1);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 2) {
      (**(code **)*puVar4)(puVar4,1);
    }
    param_1[0x19] = 0;
  }
  param_1[0x16] = PTypedRefObject<mxfcore::CFileWriter>::vftable;
  lVar3 = param_1[0x17];
  if (lVar3 != 0) {
    puVar4 = (undefined8 *)(lVar3 + 0x10);
    LOCK();
    piVar1 = (int *)(lVar3 + 0x18);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar2 < 2) && (puVar4 != (undefined8 *)0x0)) {
      (**(code **)*puVar4)(puVar4,1);
    }
    param_1[0x17] = 0;
  }
  param_1[0x14] = PTypedRefObject<mxfcore::CMxfWriter>::vftable;
  lVar3 = param_1[0x15];
  if (lVar3 != 0) {
    puVar4 = (undefined8 *)(lVar3 + 0x10);
    LOCK();
    piVar1 = (int *)(lVar3 + 0x18);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar2 < 2) && (puVar4 != (undefined8 *)0x0)) {
      (**(code **)*puVar4)(puVar4,1);
    }
    param_1[0x15] = 0;
  }
  thunk_FUN_18000aed0(param_1 + 0x10);
  thunk_FUN_18000aed0(param_1 + 0xc);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 5));
  param_1[3] = PTypedRefObject<CBufferQueueReader>::vftable;
  lVar3 = param_1[4];
  if (lVar3 != 0) {
    puVar4 = (undefined8 *)(lVar3 + 0x10);
    LOCK();
    piVar1 = (int *)(lVar3 + 0x18);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar2 < 2) && (puVar4 != (undefined8 *)0x0)) {
      (**(code **)*puVar4)(puVar4,1);
    }
    param_1[4] = 0;
  }
  *param_1 = CRefObject::vftable;
  return;
}

