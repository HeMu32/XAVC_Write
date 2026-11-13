// sidb::recordStructureWithFunc<int>::IsHeifExist
// Ghidra address: 003a270c

/* sidb::recordStructureWithFunc<int>::IsHeifExist() */

bool __thiscall sidb::recordStructureWithFunc<int>::IsHeifExist(recordStructureWithFunc<int> *this)

{
  bool bVar1;
  
  if (((byte)this[7] & 0xf) == 1) {
    bVar1 = true;
    if (((byte)this[0x4c] >> 2 & 1) == 0) {
      bVar1 = *(short *)(this + 0x44) != 0;
    }
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

