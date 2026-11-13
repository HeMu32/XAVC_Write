// FUN_8078fd98
// Ghidra address: 8078fd98

int FUN_8078fd98(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_20 [4];
  
  local_20[0] = 0;
  DAT_807c0a8c = FUN_80786714(local_20);
  if (local_20[0] == 0) {
    FUN_8078fe54(param_1,0x510,0);
    DAT_807c0384 = DAT_807c0384 + 1;
  }
  else {
    uVar2 = 0x8078fdd4;
    iVar1 = FUN_8079c854(4);
    if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_80745808(&DAT_807c0398,s_________________________src_ipsx_807afc88,0xa2,uVar2);
    }
  }
  return local_20[0];
}

