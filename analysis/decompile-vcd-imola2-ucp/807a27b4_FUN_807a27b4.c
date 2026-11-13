// FUN_807a27b4
// Ghidra address: 807a27b4

undefined4 FUN_807a27b4(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_8077fe84();
  for (uVar2 = uVar1 & 0xffffffc0; uVar2 < uVar1 + 0x130; uVar2 = uVar2 + 0x40) {
    cacheOp(0x19,uVar2);
  }
  FUN_807a3908(uVar1);
  FUN_807a3b98(uVar1);
  return 1;
}

