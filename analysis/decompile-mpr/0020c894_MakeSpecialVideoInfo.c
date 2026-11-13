// XavcsMovieReader::MakeSpecialVideoInfo
// Ghidra address: 0020c894

/* XavcsMovieReader::MakeSpecialVideoInfo(mpr::BaseDecodeTable::InfoType, unsigned int&) */

long __thiscall
XavcsMovieReader::MakeSpecialVideoInfo(XavcsMovieReader *this,undefined1 param_2,uint *param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)(*(long *)(this + 0x1d20) + (ulong)*param_3 * 0x40);
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  puVar2[5] = 0;
  puVar2[6] = 0;
  puVar2[7] = 0;
  uVar1 = *param_3 + 1;
  *(undefined1 *)(*(long *)(this + 0x1d20) + (ulong)*param_3 * 0x40) = param_2;
  *param_3 = uVar1;
  return (ulong)(*(uint *)(this + 0x1d28) < uVar1) << 1;
}

