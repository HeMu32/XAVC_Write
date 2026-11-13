// XavcsMovieReader::GetMetaSampleData
// Ghidra address: 0020caf0

/* XavcsMovieReader::GetMetaSampleData(mpr::BaseList*, unsigned int, unsigned char*) */

undefined8 __thiscall
XavcsMovieReader::GetMetaSampleData
          (XavcsMovieReader *this,BaseList *param_1,uint param_2,uchar *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  uint local_c;
  void *local_8;
  
  uVar2 = 3;
  local_8 = (void *)0x0;
  if (param_3 != (uchar *)0x0) {
    uVar4 = 0;
    memset(param_3,0,(ulong)param_2);
    for (uVar3 = 0; uVar3 < param_2; uVar3 = uVar3 + uVar1) {
      mpr::BaseList::Get(param_1,uVar4,&local_8,&local_c);
      if ((local_8 == (void *)0x0) || (local_c == 0)) {
        return 2;
      }
      uVar4 = uVar4 + 1;
      uVar1 = local_c;
      if (param_2 - uVar3 < local_c) {
        uVar1 = param_2 - uVar3;
      }
      memcpy(param_3 + uVar3,local_8,(ulong)uVar1);
    }
    uVar2 = 0;
  }
  return uVar2;
}

