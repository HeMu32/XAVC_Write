// XavcsMovieReader::MakeSpecialMetaInfo
// Ghidra address: 0020c924

/* XavcsMovieReader::MakeSpecialMetaInfo(mpr::BaseDecodeTable::InfoType, unsigned int&) */

long __thiscall
XavcsMovieReader::MakeSpecialMetaInfo(XavcsMovieReader *this,undefined1 param_2,uint *param_3)

{
  uint uVar1;
  
  memset((void *)(*(long *)(this + 0x1d40) + (ulong)*param_3 * 0x500),0,0x500);
  *(undefined1 *)(*(long *)(this + 0x1d40) + (ulong)*param_3 * 0x500) = param_2;
  uVar1 = *param_3;
  *param_3 = uVar1 + 1;
  return (ulong)(*(uint *)(this + 0x1d48) < uVar1 + 1) << 1;
}

