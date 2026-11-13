// FUN_8079a550
// Ghidra address: 8079a550

/* WARNING: Control flow encountered bad instruction data */

void FUN_8079a550(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined2 *puVar2;
  uint *puVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  
  uVar6 = 0x8079a590;
  puVar2 = (undefined2 *)FUN_8078691c(param_3);
  if (puVar2 == (undefined2 *)0x0) {
    FUN_80745808(&DAT_807c0450,s_________________________src_ipsx_807affd0,199,uVar6);
    uVar5 = *(undefined2 *)(param_1 + 8);
  }
  else {
    uVar5 = *(undefined2 *)(param_1 + 8);
  }
  *puVar2 = uVar5;
  uVar5 = *(undefined2 *)(param_1 + 4);
  *(uint *)(puVar2 + 2) =
       *(uint *)(puVar2 + 2) & 0xffffe00f | (param_3 & 1) << 0xb | (param_2 & 1) << 0xc;
  puVar2[1] = uVar5;
  FUN_8079175c();
  puVar3 = (uint *)FUN_8079175c(1);
  uVar1 = (*puVar3 & 0x1ff) >> 3;
  uVar4 = uVar1 & 1;
  uVar1 = (*(uint *)(uVar1 * 4 + param_1 + 0x74) & 0x7fff) >> 0xd;
  if (uVar1 != 0) {
    uVar4 = 0;
  }
  *(uint *)(puVar2 + 4) = DAT_807c0b4c & 7;
  *(uint *)(puVar2 + 6) = uVar1 | uVar4 << 2;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

