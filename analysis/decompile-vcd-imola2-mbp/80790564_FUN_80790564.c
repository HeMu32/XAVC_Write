// FUN_80790564
// Ghidra address: 80790564

/* WARNING: Control flow encountered bad instruction data */

void FUN_80790564(uint param_1,uint param_2,undefined4 param_3,int param_4,int param_5)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_4 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_807924b8(DAT_807c0a98,0x24);
  *DAT_807c0a98 = *DAT_807c0a98 & 0xffffff80 | (param_1 & 0x1f) << 2 | param_2 & 3;
  uVar2 = FUN_80794188();
  puVar1 = DAT_807c0a98;
  uVar3 = FUN_8078ea38(uVar2);
  puVar1[1] = uVar3;
  if (param_5 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}

