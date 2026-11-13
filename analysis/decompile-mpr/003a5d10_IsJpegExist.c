// sidb::recordStructureWithFunc<long>::IsJpegExist
// Ghidra address: 003a5d10

/* sidb::recordStructureWithFunc<long>::IsJpegExist() */

bool __thiscall
sidb::recordStructureWithFunc<long>::IsJpegExist(recordStructureWithFunc<long> *this)

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

