// FUN_0021baac
// Ghidra address: 0021baac

void FUN_0021baac(long param_1)

{
  uint uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined8 *puVar4;
  normalLock *this;
  void *pvVar5;
  _Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
  *this_00;
  _Vector_base<mpr::AudioEncodeTable::AudioInfo,std::allocator<mpr::AudioEncodeTable::AudioInfo>>
  *this_01;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined8 uStack_8;
  
  if ((*(int *)(param_1 + 0x48) != 0) || (*(int *)(param_1 + 0x68) != 0)) {
    iVar3 = FUN_00219378(*(undefined8 *)(param_1 + 0x10),*(int *)(param_1 + 0x48),
                         *(undefined4 *)(param_1 + 0x68));
    if (iVar3 != 0) {
      local_30 = 0x304292310;
      local_28 = CONCAT44(local_28._4_4_,iVar3);
      FUN_0021777c((_Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
                    *)&local_30,0xc);
      FUN_001fe0e8(*(undefined8 *)(param_1 + 0x78),iVar3);
    }
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    iVar3 = FUN_00219608(*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x18),
                         *(int *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x24),
                         *(undefined8 *)(param_1 + 0x28));
    if (iVar3 != 0) {
      local_30 = 0x304282310;
      local_28 = CONCAT44(local_28._4_4_,iVar3);
      FUN_0021777c((_Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
                    *)&local_30,0xc);
      FUN_001fe0e8(*(undefined8 *)(param_1 + 0x78),iVar3);
    }
  }
  if (*(uint *)(param_1 + 0x38) != 0) {
    iVar3 = XavcsMovieWriter::SetVideoSampleInfo
                      (*(libXavcMp4 **)(param_1 + 0x10),*(vector **)(param_1 + 0x30),
                       *(uint *)(param_1 + 0x38),*(ulong *)(param_1 + 0x40));
    if (iVar3 != 0) {
      local_30 = 0x304302310;
      local_28 = CONCAT44(local_28._4_4_,iVar3);
      FUN_0021777c((_Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
                    *)&local_30,0xc);
      FUN_001fe0e8(*(undefined8 *)(param_1 + 0x78),iVar3);
    }
  }
  uVar1 = *(uint *)(param_1 + 0x58);
  if (uVar1 != 0) {
    if (*(int *)(param_1 + 0x70) - 3U < 2) {
      iVar3 = XavcsMovieWriter::SetAudioSampleInfo
                        (*(libXavcMp4 **)(param_1 + 0x10),*(vector **)(param_1 + 0x50),uVar1,
                         *(ulong *)(param_1 + 0x60));
      if (iVar3 == 0) goto LAB_0021bc98;
      uVar2 = 0x440;
    }
    else {
      iVar3 = XavcsMovieWriter::AddAudioChunk
                        (*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x50),uVar1,
                         *(undefined4 *)(param_1 + 0x6c),*(undefined8 *)(param_1 + 0x60));
      if (iVar3 == 0) goto LAB_0021bc98;
      uVar2 = 0x438;
    }
    local_30._0_4_ = CONCAT22(uVar2,0x2310);
    local_30 = (ulong)CONCAT24(3,(undefined4)local_30);
    local_28 = CONCAT44(local_28._4_4_,iVar3);
    FUN_0021777c((_Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
                  *)&local_30,0xc);
    FUN_001fe0e8(*(undefined8 *)(param_1 + 0x78),iVar3);
  }
LAB_0021bc98:
  (*(undefined8 **)(param_1 + 0x18))[1] = **(undefined8 **)(param_1 + 0x18);
  puVar4 = *(undefined8 **)(param_1 + 0x18);
  local_30 = *puVar4;
  *puVar4 = 0;
  local_28 = puVar4[1];
  puVar4[1] = 0;
  local_20 = puVar4[2];
  puVar4[2] = 0;
  FUN_0021b940((_Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
                *)&local_30);
  (*(undefined8 **)(param_1 + 0x30))[1] = **(undefined8 **)(param_1 + 0x30);
  puVar4 = *(undefined8 **)(param_1 + 0x30);
  local_30 = *puVar4;
  *puVar4 = 0;
  local_28 = puVar4[1];
  puVar4[1] = 0;
  local_20 = puVar4[2];
  puVar4[2] = 0;
  std::
  _Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>::
  ~_Vector_base((_Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
                 *)&local_30);
  (*(undefined8 **)(param_1 + 0x50))[1] = **(undefined8 **)(param_1 + 0x50);
  puVar4 = *(undefined8 **)(param_1 + 0x50);
  local_30 = *puVar4;
  *puVar4 = 0;
  local_28 = puVar4[1];
  puVar4[1] = 0;
  local_20 = puVar4[2];
  puVar4[2] = 0;
  std::
  _Vector_base<mpr::AudioEncodeTable::AudioInfo,std::allocator<mpr::AudioEncodeTable::AudioInfo>>::
  ~_Vector_base((_Vector_base<mpr::AudioEncodeTable::AudioInfo,std::allocator<mpr::AudioEncodeTable::AudioInfo>>
                 *)&local_30);
  pvVar5 = *(void **)(param_1 + 0x18);
  if (pvVar5 != (void *)0x0) {
    FUN_0021b940(pvVar5);
    operator_delete(pvVar5,0x18);
  }
  this_00 = *(_Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
              **)(param_1 + 0x30);
  *(undefined8 *)(param_1 + 0x18) = 0;
  if (this_00 !=
      (_Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
       *)0x0) {
    std::
    _Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
    ::~_Vector_base(this_00);
    operator_delete(this_00,0x18);
  }
  this_01 = *(_Vector_base<mpr::AudioEncodeTable::AudioInfo,std::allocator<mpr::AudioEncodeTable::AudioInfo>>
              **)(param_1 + 0x50);
  *(undefined8 *)(param_1 + 0x30) = 0;
  if (this_01 !=
      (_Vector_base<mpr::AudioEncodeTable::AudioInfo,std::allocator<mpr::AudioEncodeTable::AudioInfo>>
       *)0x0) {
    std::
    _Vector_base<mpr::AudioEncodeTable::AudioInfo,std::allocator<mpr::AudioEncodeTable::AudioInfo>>
    ::~_Vector_base(this_01);
    operator_delete(this_01,0x18);
  }
  *(undefined8 *)(param_1 + 0x50) = 0;
  if (*(long *)(param_1 + 0x80) != 0) {
    local_30 = 0;
    local_28 = 0;
    local_20 = 0;
    uStack_18 = 0;
    local_10 = 0;
    uStack_8 = 0;
    iVar3 = FUN_003292b0(*(undefined8 *)(param_1 + 0x10),
                         (_Vector_base<mpr::VideoEncodeTable::VideoInfo,std::allocator<mpr::VideoEncodeTable::VideoInfo>>
                          *)&local_30);
    if (iVar3 == 0) {
      mpr::thread::normalLock::lock(*(normalLock **)(param_1 + 0x80));
      this = *(normalLock **)(param_1 + 0x80);
      *(ulong *)(this + 0x48) = local_30;
      *(undefined8 *)(this + 0x50) = local_28;
      *(undefined8 *)(this + 0x58) = local_20;
      *(undefined8 *)(this + 0x60) = uStack_18;
      *(undefined8 *)(this + 0x68) = local_10;
      *(undefined8 *)(this + 0x70) = uStack_8;
      mpr::thread::normalLock::unlock(this);
    }
  }
  return;
}

