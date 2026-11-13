// FUN_8079895c
// Ghidra address: 8079895c

void FUN_8079895c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  if ((*(uint *)(iVar3 + 8) & 0x22) != 0) {
    iVar2 = *(int *)(param_1 + 8);
    *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) & 0xfffff000;
    uVar1 = DAT_807c0410;
    *(int *)(iVar3 + 0x10) = *(int *)(iVar2 + 0x19b34) << 0xc;
    *(undefined4 *)(iVar3 + 0x14) = uVar1;
    if (*(int *)(iVar2 + 0x19b34) == 0) {
      FUN_807914c0();
                    /* WARNING: Subroutine does not return */
      FUN_8077fe78();
    }
    *(undefined4 *)(iVar3 + 4) = 0x80000000;
  }
  return;
}

