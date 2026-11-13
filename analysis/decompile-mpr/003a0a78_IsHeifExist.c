// sidb::recordStructureWithFunc<unsigned_int>::IsHeifExist
// Ghidra address: 003a0a78

/* sidb::recordStructureWithFunc<unsigned int>::IsHeifExist() */

bool __thiscall
sidb::recordStructureWithFunc<unsigned_int>::IsHeifExist
          (recordStructureWithFunc<unsigned_int> *this)

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

