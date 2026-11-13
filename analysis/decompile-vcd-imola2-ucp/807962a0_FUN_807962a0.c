// FUN_807962a0
// Ghidra address: 807962a0

int FUN_807962a0(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    iVar1 = FUN_8079408c(8);
    if (iVar1 != 0xff) break;
    iVar2 = iVar2 + 0xff;
  }
  return iVar2 + iVar1;
}

