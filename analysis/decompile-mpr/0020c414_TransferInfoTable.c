// XavcsMovieReader::TransferInfoTable
// Ghidra address: 0020c414

/* XavcsMovieReader::TransferInfoTable(std::vector<mpr::Codec::BufferAreaInfo,
   std::allocator<mpr::Codec::BufferAreaInfo> >*, unsigned long*, unsigned int, unsigned int) */

undefined8 __thiscall
XavcsMovieReader::TransferInfoTable
          (XavcsMovieReader *this,vector *param_1,ulong *param_2,uint param_3,uint param_4)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar4 = 0;
  uVar3 = 0;
  while( true ) {
    if (uVar3 == param_4) {
      return 0;
    }
    lVar1 = uVar3 * 0x18;
    uVar2 = uVar4 & 0xfffffff8;
    uVar3 = uVar3 + 1;
    uVar4 = (ulong)((int)uVar4 + param_3);
    if (*(ulong *)(*(long *)param_1 + lVar1 + 8) < (ulong)param_3) break;
    memcpy(*(void **)(*(long *)param_1 + lVar1),(void *)((long)param_2 + uVar2),(ulong)param_3);
  }
  return 0;
}

