// FUN_0021358c
// Ghidra address: 0021358c

char FUN_0021358c(XavcsMovieReader *param_1,int *param_2)

{
  char cVar1;
  long local_18;
  long local_10;
  undefined8 local_8;
  
  local_18 = 0;
  local_10 = 0;
  local_8 = 0;
  mpr::Codec::GetVideoEsWriteList((vector *)&local_18);
  cVar1 = XavcsMovieReader::CheckBufferFreeSize
                    (param_1,(vector *)&local_18,(ulong)(uint)(*param_2 + param_2[1]));
  if (cVar1 != '\0') {
    local_10 = local_18;
    mpr::Codec::GetAudioEsWriteList((vector *)&local_18);
    cVar1 = XavcsMovieReader::CheckBufferFreeSize
                      (param_1,(vector *)&local_18,(ulong)(uint)param_2[2]);
    if (cVar1 != '\0') {
      local_10 = local_18;
      std::_Vector_base<mpr::Codec::BufferAreaInfo,std::allocator<mpr::Codec::BufferAreaInfo>>::
      ~_Vector_base((_Vector_base<mpr::Codec::BufferAreaInfo,std::allocator<mpr::Codec::BufferAreaInfo>>
                     *)&local_18);
      local_18 = 0;
      local_10 = 0;
      local_8 = 0;
      mpr::Codec::GetVideoInfoWriteList((vector *)&local_18);
      if ((ulong)(uint)param_2[5] <= (ulong)((local_10 - local_18 >> 3) * -0x5555555555555555)) {
        local_10 = local_18;
        mpr::Codec::GetAudioInfoWriteList((vector *)&local_18);
        if ((ulong)(uint)param_2[6] <= (ulong)((local_10 - local_18 >> 3) * -0x5555555555555555)) {
          local_10 = local_18;
          mpr::Codec::GetMetaInfoWriteList((vector *)&local_18);
          if ((ulong)(uint)param_2[7] <= (ulong)((local_10 - local_18 >> 3) * -0x5555555555555555))
          {
            local_10 = local_18;
            std::_Vector_base<mpr::Codec::BufferAreaInfo,std::allocator<mpr::Codec::BufferAreaInfo>>
            ::~_Vector_base((_Vector_base<mpr::Codec::BufferAreaInfo,std::allocator<mpr::Codec::BufferAreaInfo>>
                             *)&local_18);
            return cVar1;
          }
        }
      }
    }
  }
  std::_Vector_base<mpr::Codec::BufferAreaInfo,std::allocator<mpr::Codec::BufferAreaInfo>>::
  ~_Vector_base((_Vector_base<mpr::Codec::BufferAreaInfo,std::allocator<mpr::Codec::BufferAreaInfo>>
                 *)&local_18);
  return '\0';
}

