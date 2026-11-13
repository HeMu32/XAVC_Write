// FUN_807a6d08
// Ghidra address: 807a6d08

void FUN_807a6d08(uint *param_1)

{
  undefined2 *puVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  
  uVar5 = *param_1;
  puVar4 = *(uint **)(param_1[5] + 0x90);
  iVar6 = *(int *)(param_1[5] + 0x8c);
  uVar2 = *puVar4;
  uVar7 = 0x807a6d4c;
  puVar1 = (undefined2 *)FUN_8078691c(uVar5);
  if (puVar1 == (undefined2 *)0x0) {
    FUN_80745808(&DAT_807c0534,s_________________________src_ipsx_807b0960,0x1b8,uVar7);
  }
  iVar3 = 1;
  if ((uVar2 & 3) != 1) {
    iVar3 = 2;
  }
  uVar2 = *(uint *)(puVar1 + 2);
  *(uint *)(puVar1 + 2) = uVar2 & 0xfffff8ff | iVar3 << 8;
  *puVar1 = *(undefined2 *)(iVar6 + 8);
  puVar1[1] = (short)puVar4[1];
  uVar7 = 0x807a6dbc;
  *(uint *)(puVar1 + 2) =
       uVar2 & 0xfffff00f | iVar3 << 8 | (param_1[6] & 0xf) << 4 | (uVar5 & 1) << 0xb;
  iVar6 = FUN_8079c854(7,puVar1,0xffffffff);
  if (iVar6 != 0) {
    FUN_80745808(&DAT_807c0534,s_________________________src_ipsx_807b0960,0x1c6,uVar7);
  }
  return;
}

