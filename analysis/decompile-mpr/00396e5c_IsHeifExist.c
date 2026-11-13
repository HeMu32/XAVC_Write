// sidb::recordStructureWithFunc<unsigned_short>::IsHeifExist
// Ghidra address: 00396e5c

/* sidb::recordStructureWithFunc<unsigned short>::IsHeifExist() */

bool __thiscall
sidb::recordStructureWithFunc<unsigned_short>::IsHeifExist
          (recordStructureWithFunc<unsigned_short> *this)

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

