// sidb::recordStructureWithFunc<unsigned_char>::IsJpegExist
// Ghidra address: 0039bd44

/* sidb::recordStructureWithFunc<unsigned char>::IsJpegExist() */

bool __thiscall
sidb::recordStructureWithFunc<unsigned_char>::IsJpegExist
          (recordStructureWithFunc<unsigned_char> *this)

{
  bool bVar1;
  
  if (((byte)this[7] & 0xf) == 1) {
    bVar1 = true;
    if (((byte)this[0x4c] & 1) == 0) {
      bVar1 = *(short *)(this + 0x40) != 0;
    }
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

