// FUN_0020b890
// Ghidra address: 0020b890

undefined8 FUN_0020b890(long param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  char cVar3;
  BaseList *pBVar4;
  void *pvVar5;
  XavcOutBandParamDataBuffer *pXVar6;
  undefined8 uVar7;
  long *plVar8;
  long lVar9;
  RTMetadatSmplDatParser *pRVar10;
  TCUBConv *pTVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined2 local_28;
  undefined2 local_26;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined4 local_20;
  undefined *local_18;
  long lStack_10;
  
  local_24 = 4;
  local_28 = 0x2311;
  local_23 = 0;
  local_26 = 0x300;
  local_22 = 0;
  local_21 = 0;
  FUN_0020aff4((__osal_thread_info *)&local_28,8);
  if (*(long **)(param_1 + 0x1d18) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x1d18) + 8))();
  }
  pBVar4 = operator_new(0x20);
  mpr::BaseList::BaseList(pBVar4,0x14);
  *(BaseList **)(param_1 + 0x1d18) = pBVar4;
  *(undefined4 *)(param_1 + 0x1d10) = 0;
  for (puVar12 = (undefined8 *)(param_1 + 0x5d8); puVar12 != (undefined8 *)(param_1 + 0x1e38);
      puVar12 = puVar12 + 0x27) {
    if ((void *)puVar12[-0xf] != (void *)0x0) {
      operator_delete__((void *)puVar12[-0xf]);
    }
    pvVar5 = operator_new__(0x3c00);
    puVar12[-0xf] = pvVar5;
    for (puVar13 = puVar12 + -0xc; puVar12 != puVar13; puVar13 = puVar13 + 3) {
      if ((void *)*puVar13 != (void *)0x0) {
        operator_delete__((void *)*puVar13);
      }
      pvVar5 = operator_new__(0x1e00);
      *puVar13 = pvVar5;
    }
    if ((void *)*puVar12 != (void *)0x0) {
      operator_delete__((void *)*puVar12);
    }
    pvVar5 = operator_new__(0x1680);
    *puVar12 = pvVar5;
  }
  free(*(void **)(param_1 + 0x1d20));
  pvVar5 = calloc((ulong)*(uint *)(param_2 + 2) << 6,1);
  *(void **)(param_1 + 0x1d20) = pvVar5;
  free(*(void **)(param_1 + 0x1d30));
  pvVar5 = calloc((ulong)*(uint *)((long)param_2 + 0x14) * 0x30,1);
  *(void **)(param_1 + 0x1d30) = pvVar5;
  free(*(void **)(param_1 + 0x1d40));
  uVar1 = *(uint *)(param_2 + 3);
  pvVar5 = calloc((ulong)uVar1 * 0x500,1);
  *(void **)(param_1 + 0x1d40) = pvVar5;
  *(undefined4 *)(param_1 + 0x1d28) = *(undefined4 *)(param_2 + 2);
  uVar2 = *(undefined4 *)((long)param_2 + 0x14);
  *(uint *)(param_1 + 0x1d48) = uVar1;
  *(undefined4 *)(param_1 + 0x1d38) = uVar2;
  free(*(void **)(param_1 + 0x1d60));
  pvVar5 = calloc(1,(ulong)*(uint *)((long)param_2 + 0x1c) * 0x18);
  *(void **)(param_1 + 0x1d60) = pvVar5;
  free(*(void **)(param_1 + 0x1d50));
  pvVar5 = calloc(1,0x40000);
  *(void **)(param_1 + 0x1d50) = pvVar5;
  if (*(long **)(param_1 + 0x1d70) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x1d70) + 8))();
  }
  pXVar6 = operator_new(0x30);
  mpr::XavcOutBandParamDataBuffer::XavcOutBandParamDataBuffer(pXVar6,pvVar5,0x40000);
  uVar2 = *(undefined4 *)((long)param_2 + 0x1c);
  *(undefined4 *)(param_1 + 0x1d68) = 0;
  *(undefined4 *)(param_1 + 0x1d6c) = uVar2;
  *(XavcOutBandParamDataBuffer **)(param_1 + 0x1d70) = pXVar6;
  if (*(long **)(param_1 + 0x1d58) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x1d58) + 8))();
  }
  pBVar4 = operator_new(0x20);
  mpr::BaseList::BaseList(pBVar4,*(uint *)((long)param_2 + 0x1c));
  *(BaseList **)(param_1 + 0x1d58) = pBVar4;
  if (*(long **)(param_1 + 0x1da0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x1da0) + 8))();
  }
  pBVar4 = operator_new(0x20);
  mpr::BaseList::BaseList(pBVar4,100);
  *(BaseList **)(param_1 + 0x1da0) = pBVar4;
  if (*(long **)(param_1 + 0x1da8) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x1da8) + 8))();
  }
  pBVar4 = operator_new(0x20);
  mpr::BaseList::BaseList(pBVar4,400);
  *(BaseList **)(param_1 + 0x1da8) = pBVar4;
  if (*(long **)(param_1 + 0x1db0) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x1db0) + 8))();
  }
  pBVar4 = operator_new(0x20);
  mpr::BaseList::BaseList(pBVar4,0x29);
  uVar7 = param_2[4];
  *(BaseList **)(param_1 + 0x1db0) = pBVar4;
  *(undefined8 *)(param_1 + 0x1d80) = uVar7;
  *(undefined4 *)(param_1 + 0x1d88) = *(undefined4 *)(param_2 + 5);
  *(undefined8 *)(param_1 + 0x1d90) = param_2[6];
  if (*(long **)(param_1 + 0x1d78) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x1d78) + 8))();
  }
  plVar8 = (long *)mpr::DmacLib::MakeDmacLib
                             (*(long *)(param_1 + 0x1d80),*(uint *)(param_2 + 5) >> 1,
                              *(long *)(param_1 + 0x1d80) - *(long *)(param_1 + 0x1d90),0xff0,0);
  lVar9 = *plVar8;
  *(long **)(param_1 + 0x1d78) = plVar8;
  cVar3 = (**(code **)(lVar9 + 0x30))();
  if (cVar3 == '\0') {
    *(undefined8 *)(param_1 + 0x1d80) = 0;
    *(undefined4 *)(param_1 + 0x1d88) = 0;
    *(undefined8 *)(param_1 + 0x1d90) = 0;
  }
  *(undefined8 *)(param_1 + 0x18) = *param_2;
  pRVar10 = *(RTMetadatSmplDatParser **)(param_1 + 0xe8);
  *(undefined8 *)(param_1 + 0x20) = param_2[1];
  if (pRVar10 != (RTMetadatSmplDatParser *)0x0) {
    mpr::RTMetadatSmplDatParser::~RTMetadatSmplDatParser(pRVar10);
    operator_delete(pRVar10,0x30);
  }
  pRVar10 = operator_new(0x30);
  mpr::RTMetadatSmplDatParser::RTMetadatSmplDatParser(pRVar10);
  *(RTMetadatSmplDatParser **)(param_1 + 0xe8) = pRVar10;
  pTVar11 = *(TCUBConv **)(param_1 + 0xf0);
  if (pTVar11 != (TCUBConv *)0x0) {
    mpr::TCUBConv::~TCUBConv(pTVar11);
    operator_delete(pTVar11,0x20);
  }
  pTVar11 = operator_new(0x20);
  mpr::TCUBConv::TCUBConv(pTVar11);
  *(TCUBConv **)(param_1 + 0xf0) = pTVar11;
  pvVar5 = *(void **)(param_1 + 0xe0);
  if (pvVar5 != (void *)0x0) {
    thunk_FUN_00329434(pvVar5);
    operator_delete(pvVar5,800);
  }
  local_38[0] = 0x58415643;
  local_30 = 0xa00000;
  pvVar5 = operator_new(800);
  FUN_00322994(pvVar5,local_38);
  *(void **)(param_1 + 0xe0) = pvVar5;
  if (*(char *)(param_1 + 0x10) == '\0') {
    mpr::ThreadInfo::GetThreadInfo(0x7a,(__osal_thread_info *)&local_28);
    local_18 = PTR_FUN_00402a30;
    *(undefined1 *)(param_1 + 0x10) = 1;
    lStack_10 = param_1;
    osal_create_waitable_thread((__osal_thread_info *)&local_28,param_1 + 8);
  }
  *(undefined4 *)(param_1 + 0x4a4) = 0x8000;
  FUN_0020b138(param_1 + 0x1e10);
  local_23 = 0;
  local_22 = 0;
  local_24 = 3;
  local_21 = 0;
  local_28 = 0x2311;
  local_20 = 0;
  local_26 = 0x30f;
  FUN_0020aff4((__osal_thread_info *)&local_28,0xc);
  return 0;
}

