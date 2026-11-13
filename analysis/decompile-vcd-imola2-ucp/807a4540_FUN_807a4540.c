// FUN_807a4540
// Ghidra address: 807a4540

void FUN_807a4540(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)FUN_80746e40(0);
  FUN_807aceb0(0);
  FUN_80783758(0,*puVar1,puVar1);
  uVar2 = FUN_80783744(0);
  sony_ucp_write7(0x353,uVar2);
  FUN_80783688();
  FUN_807881ec(1);
  uVar2 = 0x807a459c;
  iVar3 = FUN_8079c854(7,0x8500,0xffffffff);
  if (iVar3 != 0) {
    FUN_80745808(&DAT_807c04fc,s_________________________src_ipsx_807b087c,0x2d9,uVar2);
  }
  return;
}

