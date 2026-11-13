// sidb::headerStructure::IsTrueBitmap
// Ghidra address: 0038a8a4

/* sidb::headerStructure::IsTrueBitmap(unsigned int) const */

uint __thiscall sidb::headerStructure::IsTrueBitmap(headerStructure *this,uint param_1)

{
  return (uint)(*(ulong *)(this + ((ulong)(param_1 >> 6) + 0x800) * 8) >> (param_1 & 0x3f)) & 1;
}

