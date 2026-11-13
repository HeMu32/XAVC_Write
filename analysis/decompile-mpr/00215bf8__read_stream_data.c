// XavcsMovieReader::_read_stream_data
// Ghidra address: 00215bf8

/* XavcsMovieReader::_read_stream_data(void*, unsigned char, XavcsMovieReader::VideoSampleInfo*,
   XavcsMovieReader::AudioSampleInfo*, XavcsMovieReader::MetadataSampleInfo*, unsigned int*,
   mpr::RingBuffer*, mpr::BaseList*, mpr::BaseList*, mpr::BaseList*) */

int XavcsMovieReader::_read_stream_data
              (void *param_1,uchar param_2,VideoSampleInfo *param_3,AudioSampleInfo *param_4,
              MetadataSampleInfo *param_5,uint *param_6,RingBuffer *param_7,BaseList *param_8,
              BaseList *param_9,BaseList *param_10)

{
  void *pvVar1;
  int iVar2;
  void *extraout_x9;
  void *pvVar3;
  long extraout_x9_00;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  void *local_38;
  void *pvStack_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  undefined4 uStack_14;
  BaseList *local_10;
  undefined1 local_8;
  
  local_18 = *(undefined4 *)(param_3 + 8);
  local_20 = *(undefined8 *)(*(long *)(param_3 + 0x10) + 8);
  uStack_14 = *(undefined4 *)(param_3 + 4);
  local_28 = 0;
  local_8 = 0;
  local_38 = (void *)0x0;
  pvStack_30 = (void *)0x0;
  local_10 = param_8;
  FUN_00215860(&local_38,&local_20);
  for (uVar4 = 0; uVar4 < param_2; uVar4 = uVar4 + 1 & 0xff) {
    local_20 = *(undefined8 *)(*(long *)(param_4 + (ulong)uVar4 * 0x18 + 0x10) + 8);
    local_18 = *(undefined4 *)(param_4 + (ulong)uVar4 * 0x18 + 8);
    uStack_14 = *(undefined4 *)(param_4 + (ulong)uVar4 * 0x18 + 4);
    local_10 = param_9;
    local_8 = 1 < param_2;
    FUN_00215860(&local_38,&local_20);
  }
  local_18 = *(undefined4 *)(param_5 + 8);
  local_20 = *(undefined8 *)(*(long *)(param_5 + 0x10) + 8);
  uStack_14 = *(undefined4 *)(param_5 + 4);
  local_8 = 0;
  local_10 = param_10;
  FUN_00215860(&local_38,&local_20);
  pvVar1 = pvStack_30;
  pvVar3 = local_38;
  if (pvStack_30 != local_38) {
    lVar7 = (long)pvStack_30 - (long)local_38;
    FUN_00215a6c(local_38,pvStack_30,(0x3f - LZCOUNT(lVar7 >> 5)) * 2);
    if (lVar7 < 0x220) {
      FUN_0020af3c(pvVar3,pvVar1);
    }
    else {
      FUN_0020af3c(pvVar3,(long)pvVar3 + 0x200);
      pvVar3 = extraout_x9;
      while (pvVar1 != pvVar3) {
        FUN_0020aed8(pvVar3);
        pvVar3 = (void *)(extraout_x9_00 + 0x20);
      }
    }
  }
  uVar6 = (long)pvStack_30 - (long)local_38;
  for (uVar5 = 0; (uint)uVar5 < (uint)(uVar6 >> 5); uVar5 = (ulong)(byte)((char)uVar5 + 1)) {
    lVar7 = uVar5 * 0x20;
    if ((*(int *)((long)local_38 + lVar7 + 0xc) != 0) &&
       (uVar4 = *(uint *)((long)local_38 + lVar7 + 8), uVar4 != 0)) {
      iVar2 = _read_stream_from_file
                        (param_1,param_7,*(ulong *)((long)local_38 + lVar7),uVar4,
                         *(bool *)((long)local_38 + lVar7 + 0x18),
                         *(BaseList **)((long)local_38 + lVar7 + 0x10),param_6);
      if (iVar2 != 0) goto LAB_00215dcc;
    }
  }
  iVar2 = 0;
LAB_00215dcc:
  if (local_38 != (void *)0x0) {
    operator_delete(local_38);
  }
  return iVar2;
}

