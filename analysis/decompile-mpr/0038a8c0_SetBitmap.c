// sidb::headerStructure::SetBitmap
// Ghidra address: 0038a8c0

/* sidb::headerStructure::SetBitmap(unsigned int) */

void __thiscall sidb::headerStructure::SetBitmap(headerStructure *this,uint param_1)

{
  *(ulong *)(this + (ulong)(param_1 >> 6) * 8 + 0x4000) =
       *(ulong *)(this + (ulong)(param_1 >> 6) * 8 + 0x4000) | 1L << (param_1 & 0x3f);
  return;
}

