// XavcsMovieReader::OpenAndLockNrtFiles
// Ghidra address: 0020c018

/* XavcsMovieReader::OpenAndLockNrtFiles(sidb::recordInfo const&, void*&, void*&, void*&) */

void __thiscall
XavcsMovieReader::OpenAndLockNrtFiles
          (XavcsMovieReader *this,recordInfo *param_1,void **param_2,void **param_3,void **param_4)

{
  recordInfo *prVar1;
  recordInfo *prVar2;
  
  prVar1 = param_1 + 0x1c8;
  prVar2 = param_1 + 0x3d6;
  if (param_1[0x1c7] == '\0') {
    prVar1 = (recordInfo *)0x0;
  }
  if (param_1[0x3d5] == '\0') {
    prVar2 = (recordInfo *)0x0;
  }
  FUN_0020bde8(this,param_1 + 0xc1,prVar1,prVar2,param_2,param_3,param_4);
  return;
}

