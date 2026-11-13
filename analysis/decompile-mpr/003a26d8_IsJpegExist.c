// sidb::recordStructureWithFunc<int>::IsJpegExist
// Ghidra address: 003a26d8

/* sidb::recordStructureWithFunc<int>::IsJpegExist() */

bool __thiscall sidb::recordStructureWithFunc<int>::IsJpegExist(recordStructureWithFunc<int> *this)

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

