// sidb::recordStructureWithFunc<unsigned_char>::IsHeifExist
// Ghidra address: 0039bd78

/* sidb::recordStructureWithFunc<unsigned char>::IsHeifExist() */

bool __thiscall
sidb::recordStructureWithFunc<unsigned_char>::IsHeifExist
          (recordStructureWithFunc<unsigned_char> *this)

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

