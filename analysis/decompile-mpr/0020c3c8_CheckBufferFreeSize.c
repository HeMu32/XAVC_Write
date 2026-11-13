// XavcsMovieReader::CheckBufferFreeSize
// Ghidra address: 0020c3c8

/* XavcsMovieReader::CheckBufferFreeSize(std::vector<mpr::Codec::BufferAreaInfo,
   std::allocator<mpr::Codec::BufferAreaInfo> >*, unsigned long) */

bool __thiscall
XavcsMovieReader::CheckBufferFreeSize(XavcsMovieReader *this,vector *param_1,ulong param_2)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar3 = 0;
  uVar1 = (*(long *)(param_1 + 8) - *(long *)param_1 >> 3) * -0x5555555555555555;
  for (uVar2 = 0; uVar2 <= uVar1 && uVar1 - uVar2 != 0; uVar2 = (ulong)((int)uVar2 + 1)) {
    uVar3 = uVar3 + *(long *)(*(long *)param_1 + uVar2 * 0x18 + 8);
  }
  return param_2 <= uVar3;
}

