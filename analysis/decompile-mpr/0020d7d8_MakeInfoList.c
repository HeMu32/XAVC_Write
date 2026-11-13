// XavcsMovieReader::MakeInfoList
// Ghidra address: 0020d7d8

/* XavcsMovieReader::MakeInfoList(libXavcMp4::MoviePresentationInfo*,
   XavcsMovieReader::VideoSampleInfo*, XavcsMovieReader::AudioSampleInfo*,
   XavcsMovieReader::MetadataSampleInfo*, mpr::BaseList*, XavcsMovieReader::TransferParams*) */

int __thiscall
XavcsMovieReader::MakeInfoList
          (XavcsMovieReader *this,MoviePresentationInfo *param_1,VideoSampleInfo *param_2,
          AudioSampleInfo *param_3,MetadataSampleInfo *param_4,BaseList *param_5,
          TransferParams *param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uchar *__ptr;
  int iVar5;
  ulong uVar6;
  int iVar7;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  iVar7 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  memset(*(void **)(this + 0x1d20),0,(ulong)*(uint *)(this + 0x1d28) << 6);
  memset(*(void **)(this + 0x1d30),0,(ulong)*(uint *)(this + 0x1d38) * 0x30);
  memset(*(void **)(this + 0x1d40),0,(ulong)*(uint *)(this + 0x1d48) * 0x500);
  uVar1 = **(uint **)(param_4 + 0x10);
  __ptr = malloc((ulong)uVar1);
  for (uVar6 = 0; (uint)uVar6 < *(uint *)(param_2 + 4); uVar6 = (ulong)((uint)uVar6 + 1)) {
    local_4 = 0;
    iVar3 = FUN_0020c998(this,*(long *)(param_2 + 0x10) + uVar6 * 0x40,&local_10,&local_4);
    if (iVar3 != 0) goto LAB_0020d960;
    iVar7 = iVar7 + local_4;
    iVar3 = FUN_0020c4a4(this,*(long *)(param_2 + 0x10) + uVar6 * 0x40,&local_10);
    if (iVar3 != 0) goto LAB_0020d960;
    uVar2 = *(uint *)(*(long *)(param_4 + 0x10) + uVar6 * 0x18);
    if (((uVar1 < uVar2) || (iVar3 = GetMetaSampleData(this,param_5,uVar2,__ptr), iVar3 != 0)) ||
       (iVar3 = FUN_0020c550(this,__ptr,&local_8), iVar3 != 0)) goto LAB_0020d960;
    mpr::BaseList::DelByLen(param_5,*(uint *)(*(long *)(param_4 + 0x10) + uVar6 * 0x18));
  }
  iVar3 = 0;
LAB_0020d960:
  free(__ptr);
  if (this[0x4a8] == (XavcsMovieReader)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = 0;
    local_4 = 0;
    for (uVar6 = 0; (uint)uVar6 < *(uint *)(param_3 + 4); uVar6 = (ulong)((uint)uVar6 + 1)) {
      iVar3 = FUN_0020d6d0(this,param_1,*(long *)(param_3 + 0x10) + uVar6 * 0x20,&local_c,&local_4);
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar5 = iVar5 + local_4;
      iVar3 = 0;
    }
  }
  iVar4 = iVar3;
  if ((iVar3 == 0) &&
     (((*(uint *)param_2 & 0x11) == 0 ||
      (((iVar4 = MakeSpecialVideoInfo(this,3,&local_10), iVar4 == 0 &&
        (iVar4 = MakeSpecialMetaInfo(this,3,&local_8), iVar4 == 0)) &&
       ((this[0x4a8] == (XavcsMovieReader)0x0 ||
        (iVar4 = MakeSpecialAudioInfo(this,3,&local_c), iVar4 == 0)))))))) {
    *(int *)(param_6 + 4) = iVar7;
    *(int *)(param_6 + 8) = iVar5;
    *(undefined4 *)(param_6 + 0x14) = local_10;
    *(undefined4 *)(param_6 + 0x18) = local_c;
    *(undefined4 *)(param_6 + 0x1c) = local_8;
    iVar4 = iVar3;
  }
  return iVar4;
}

