// XavcsMovieReader::_make_outband_param_info
// Ghidra address: 0021075c

/* XavcsMovieReader::_make_outband_param_info(libXavcMp4*, XavcsMovieReader::VideoSampleInfo*,
   mpr::XavcOutBandParamDataBuffer*, mpr::BaseList*, XavcsMovieReader::OutBandParamInfo*, unsigned
   int, unsigned int*) */

int XavcsMovieReader::_make_outband_param_info
              (libXavcMp4 *param_1,VideoSampleInfo *param_2,XavcOutBandParamDataBuffer *param_3,
              BaseList *param_4,OutBandParamInfo *param_5,uint param_6,uint *param_7)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  OutBandParamInfo *pOVar5;
  uint uVar6;
  byte bVar7;
  uint local_40;
  uint local_24;
  uint local_20;
  uint local_1c;
  void *local_18;
  void *local_10;
  void *local_8;
  
  uVar6 = *param_7;
  iVar4 = 0;
  local_40 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = (void *)0x0;
  local_10 = (void *)0x0;
  local_8 = (void *)0x0;
LAB_002107c8:
  if (*(uint *)(param_2 + 4) <= local_40) {
    return iVar4;
  }
  lVar1 = *(long *)(param_2 + 0x10) + (ulong)local_40 * 0x40;
  iVar3 = iVar4;
  if (*(char *)(lVar1 + 0x2c) != '\0') {
    if (iVar4 != 0) {
      return iVar4;
    }
    bVar7 = 1;
    while( true ) {
      iVar3 = iVar4;
      if ((*(byte *)(lVar1 + 0x36) < bVar7) ||
         (iVar3 = FUN_00325424(param_1,2,*(undefined4 *)(lVar1 + 0x30),1,&local_24), iVar3 != 0))
      goto LAB_002108a8;
      mpr::XavcOutBandParamDataBuffer::GetFreeArea(param_3,local_24,&local_18);
      iVar3 = FUN_00325554(param_1,2,*(undefined4 *)(lVar1 + 0x30),1,local_18);
      if (iVar3 != 0) goto LAB_002108a8;
      mpr::XavcOutBandParamDataBuffer::UseMemory(param_3,local_24);
      pOVar5 = param_5 + (ulong)uVar6 * 0x18;
      *(undefined4 *)(param_5 + (ulong)uVar6 * 0x18) = 4;
      *(void **)(pOVar5 + 8) = local_18;
      *(uint *)(pOVar5 + 0x10) = local_24;
      iVar3 = mpr::BaseList::Add(param_4,pOVar5,0x18);
      if (iVar3 != 0) break;
      bVar7 = bVar7 + 1;
      uVar2 = 0;
      if (param_6 != 0) {
        uVar2 = (uVar6 + 1) / param_6;
      }
      uVar6 = (uVar6 + 1) - uVar2 * param_6;
    }
    iVar3 = 2;
  }
LAB_002108a8:
  iVar4 = iVar3;
  if (*(char *)(lVar1 + 0x2b) == '\0') {
    if (iVar3 == 0) {
LAB_00210a48:
      *param_7 = uVar6;
      iVar4 = 0;
    }
  }
  else if (iVar3 == 0) {
    bVar7 = 1;
    while (bVar7 <= *(byte *)(lVar1 + 0x34)) {
      iVar4 = FUN_00325424(param_1,0,*(undefined4 *)(lVar1 + 0x30),1,&local_20);
      if (iVar4 != 0) goto LAB_00210a54;
      mpr::XavcOutBandParamDataBuffer::GetFreeArea(param_3,local_20,&local_10);
      iVar4 = FUN_00325554(param_1,0,*(undefined4 *)(lVar1 + 0x30),1,local_10);
      if (iVar4 != 0) goto LAB_00210a54;
      mpr::XavcOutBandParamDataBuffer::UseMemory(param_3,local_20);
      pOVar5 = param_5 + (ulong)uVar6 * 0x18;
      *(undefined4 *)(param_5 + (ulong)uVar6 * 0x18) = 2;
      *(void **)(pOVar5 + 8) = local_10;
      *(uint *)(pOVar5 + 0x10) = local_20;
      iVar4 = mpr::BaseList::Add(param_4,pOVar5,0x18);
      if (iVar4 != 0) goto LAB_00210a64;
      bVar7 = bVar7 + 1;
      uVar2 = 0;
      if (param_6 != 0) {
        uVar2 = (uVar6 + 1) / param_6;
      }
      uVar6 = (uVar6 + 1) - uVar2 * param_6;
    }
    bVar7 = 1;
    while (bVar7 <= *(byte *)(lVar1 + 0x35)) {
      iVar4 = FUN_00325424(param_1,1,*(undefined4 *)(lVar1 + 0x30),bVar7,&local_1c);
      if (iVar4 != 0) goto LAB_00210a54;
      mpr::XavcOutBandParamDataBuffer::GetFreeArea(param_3,local_1c,&local_8);
      iVar4 = FUN_00325554(param_1,1,*(undefined4 *)(lVar1 + 0x30),bVar7,local_8);
      if (iVar4 != 0) goto LAB_00210a54;
      mpr::XavcOutBandParamDataBuffer::UseMemory(param_3,local_1c);
      pOVar5 = param_5 + (ulong)uVar6 * 0x18;
      *(undefined4 *)(param_5 + (ulong)uVar6 * 0x18) = 3;
      *(void **)(pOVar5 + 8) = local_8;
      *(uint *)(pOVar5 + 0x10) = local_1c;
      iVar4 = mpr::BaseList::Add(param_4,pOVar5,0x18);
      if (iVar4 != 0) goto LAB_00210a64;
      bVar7 = bVar7 + 1;
      uVar2 = 0;
      if (param_6 != 0) {
        uVar2 = (uVar6 + 1) / param_6;
      }
      uVar6 = (uVar6 + 1) - uVar2 * param_6;
    }
    pOVar5 = param_5 + (ulong)uVar6 * 0x18;
    *(undefined8 *)pOVar5 = 0;
    *(undefined8 *)(pOVar5 + 8) = 0;
    *(undefined8 *)(pOVar5 + 0x10) = 0;
    iVar3 = mpr::BaseList::Add(param_4,pOVar5,0x18);
    iVar4 = 2;
    if (iVar3 == 0) {
      uVar2 = 0;
      if (param_6 != 0) {
        uVar2 = (uVar6 + 1) / param_6;
      }
      uVar6 = (uVar6 + 1) - uVar2 * param_6;
      goto LAB_00210a48;
    }
  }
  goto LAB_00210a54;
LAB_00210a64:
  iVar4 = 2;
LAB_00210a54:
  local_40 = local_40 + 1;
  goto LAB_002107c8;
}

