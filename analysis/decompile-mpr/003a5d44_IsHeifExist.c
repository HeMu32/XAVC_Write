// sidb::recordStructureWithFunc<long>::IsHeifExist
// Ghidra address: 003a5d44

/* sidb::recordStructureWithFunc<long>::IsHeifExist() */

bool __thiscall
sidb::recordStructureWithFunc<long>::IsHeifExist(recordStructureWithFunc<long> *this)

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

