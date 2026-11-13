// XavcsMovieReader::MakeSpecialAudioInfo
// Ghidra address: 0020c8dc

/* XavcsMovieReader::MakeSpecialAudioInfo(mpr::BaseDecodeTable::InfoType, unsigned int&) */

long __thiscall
XavcsMovieReader::MakeSpecialAudioInfo(XavcsMovieReader *this,undefined1 param_2,uint *param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)(*(long *)(this + 0x1d30) + (ulong)*param_3 * 0x30);
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  puVar2[5] = 0;
  uVar1 = *param_3 + 1;
  *(undefined1 *)(*(long *)(this + 0x1d30) + (ulong)*param_3 * 0x30) = param_2;
  *param_3 = uVar1;
  return (ulong)(*(uint *)(this + 0x1d38) < uVar1) << 1;
}

