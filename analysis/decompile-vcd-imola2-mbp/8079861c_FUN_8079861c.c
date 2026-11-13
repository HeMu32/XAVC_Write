// FUN_8079861c
// Ghidra address: 8079861c

void FUN_8079861c(int param_1)

{
  int iVar1;
  
  iVar1 = **(int **)(param_1 + 0xc) << 0x1c;
  if (iVar1 < 0) {
    if (-1 < iVar1) {
                    /* WARNING: Subroutine does not return */
      FUN_80745808(&DAT_807c0414,s_________________________src_ipsx_807aff84,0x26b);
    }
  }
  else {
    FUN_8079895c();
  }
  return;
}

