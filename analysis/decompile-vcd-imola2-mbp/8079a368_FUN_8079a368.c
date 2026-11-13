// FUN_8079a368
// Ghidra address: 8079a368

/* WARNING: Control flow encountered bad instruction data */

void FUN_8079a368(int param_1,uint *param_2,undefined1 param_3,undefined4 param_4)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = FUN_807868c0(param_4);
  if (5 < uVar1) {
    bVar2 = false;
    if ((*param_2 & 0xf) == 1 || (*param_2 & 0xf) == 3) {
      uVar1 = FUN_8079168c(0);
      bVar2 = uVar1 == *param_2 >> 0xc;
    }
    FUN_8079acc8(bVar2,param_4,*(undefined4 *)(param_1 + 8));
    FUN_8079a550(param_1,param_3,param_4);
    return;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

