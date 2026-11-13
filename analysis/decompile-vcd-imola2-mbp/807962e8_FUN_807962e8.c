// FUN_807962e8
// Ghidra address: 807962e8

int FUN_807962e8(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    uVar1 = FUN_8079408c(8);
    if ((uVar1 & 0xff) != 0xff) break;
    iVar2 = iVar2 + 0xff;
  }
  return iVar2 + (uVar1 & 0xff);
}

