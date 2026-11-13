// FUN_00213ee8
// Ghidra address: 00213ee8

int FUN_00213ee8(XavcsMovieReader *param_1,long param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 local_18;
  undefined8 uStack_10;
  undefined8 local_8;
  
  if (*(char *)(param_2 + 0x20) == '\0') {
    if (param_1[0x4a8] != (XavcsMovieReader)0x0) {
      FUN_00213c68(param_1,*(undefined4 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x30));
    }
    iVar1 = FUN_00213900(param_1,*(int *)(param_2 + 0x14) + -1,*(undefined8 *)(param_2 + 0x30));
  }
  else {
    iVar1 = FUN_00213900(param_1,*(int *)(param_2 + 0x14) + -1,*(undefined8 *)(param_2 + 0x30));
    if (param_1[0x4a8] != (XavcsMovieReader)0x0) {
      iVar1 = FUN_00213c68(param_1,*(undefined4 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x30));
    }
  }
  if (iVar1 == 0) {
    if (*(uint *)(param_2 + 0xc) != 0) {
      mpr::Codec::SetVideoPiWriteIndexCount(*(uint *)(param_2 + 0xc));
      for (uVar2 = 0; uVar2 < *(uint *)(param_2 + 0xc); uVar2 = uVar2 + 1) {
        FUN_001f8a24(*(undefined8 *)(param_1 + 0xf8),
                     *(long *)(param_2 + 0x28) + (ulong)uVar2 * 0x5e8);
      }
    }
    if (*(uint *)(param_2 + 0x10) != 0) {
      mpr::Codec::SetAudioPiWriteIndexCount(*(uint *)(param_2 + 0x10));
    }
    local_18 = 0;
    uStack_10 = 0;
    local_8 = 0;
    mpr::Codec::GetMetaInfoWriteList((vector *)&local_18);
    XavcsMovieReader::TransferInfoTable
              (param_1,(vector *)&local_18,*(ulong **)(param_1 + 0x1d40),0x500,
               *(uint *)(param_2 + 0x1c));
    std::_Vector_base<mpr::Codec::BufferAreaInfo,std::allocator<mpr::Codec::BufferAreaInfo>>::
    ~_Vector_base((_Vector_base<mpr::Codec::BufferAreaInfo,std::allocator<mpr::Codec::BufferAreaInfo>>
                   *)&local_18);
    local_18 = 0;
    uStack_10 = 0;
    local_8 = 0;
    mpr::Codec::GetVideoInfoWriteList((vector *)&local_18);
    XavcsMovieReader::TransferInfoTable
              (param_1,(vector *)&local_18,*(ulong **)(param_1 + 0x1d20),0x40,
               *(uint *)(param_2 + 0x14));
    mpr::Codec::SetVideoInfoWriteIndexCount(*(uint *)(param_2 + 0x14));
    std::_Vector_base<mpr::Codec::BufferAreaInfo,std::allocator<mpr::Codec::BufferAreaInfo>>::
    ~_Vector_base((_Vector_base<mpr::Codec::BufferAreaInfo,std::allocator<mpr::Codec::BufferAreaInfo>>
                   *)&local_18);
    local_18 = 0;
    uStack_10 = 0;
    local_8 = 0;
    mpr::Codec::GetAudioInfoWriteList((vector *)&local_18);
    XavcsMovieReader::TransferInfoTable
              (param_1,(vector *)&local_18,*(ulong **)(param_1 + 0x1d30),0x30,
               *(uint *)(param_2 + 0x18));
    mpr::Codec::SetAudioInfoWriteIndexCount(*(uint *)(param_2 + 0x18));
    std::_Vector_base<mpr::Codec::BufferAreaInfo,std::allocator<mpr::Codec::BufferAreaInfo>>::
    ~_Vector_base((_Vector_base<mpr::Codec::BufferAreaInfo,std::allocator<mpr::Codec::BufferAreaInfo>>
                   *)&local_18);
  }
  return iVar1;
}

