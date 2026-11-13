// FUN_807a3b98
// Ghidra address: 807a3b98

void FUN_807a3b98(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  undefined4 uVar8;
  undefined4 local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  
  uVar8 = 0x807a3bc8;
  local_30 = param_1;
  iVar2 = FUN_8079ec24(&local_30,DAT_807c0b5c);
  if (iVar2 == 0) {
    FUN_80745808(&DAT_807c04fc,s_________________________src_ipsx_807b087c,0xb7,uVar8);
  }
  iVar2 = FUN_807a3a18(param_1);
  puVar7 = *(uint **)(iVar2 + 0x8c);
  uVar8 = 0x807a3be8;
  iVar3 = FUN_80746d90();
  if (iVar3 == 1) {
    FUN_807acfbc();
    FUN_80747c4c();
    FUN_807aced8();
    uVar8 = 0x807a3e40;
    FUN_807a4540();
    sony_ucp_write7(0x400,1);
    piVar4 = *(int **)(iVar2 + 0x90);
  }
  else {
    piVar4 = *(int **)(iVar2 + 0x90);
  }
  puVar6 = *(uint **)(iVar2 + 0x8c);
  DAT_807c04f4 = -((*piVar4 << 0x19) >> 0x1f);
  if (DAT_807c04f4 == 0) {
    uVar5 = *puVar7;
  }
  else {
    FUN_8077feac(piVar4[1],*(undefined4 *)(iVar2 + 0x98));
    uVar8 = 0x807a3e18;
    FUN_8077fedc(*puVar6 & 7,piVar4[1],*(undefined4 *)(iVar2 + 0xa0));
    uVar5 = *puVar7;
  }
  uVar1 = (uVar5 & 0xff) >> 5;
  if ((uVar1 != 0 && uVar1 != 4) && (uVar1 != 1)) {
    FUN_80745808(&DAT_807c04fc,s_________________________src_ipsx_807b087c,0x37e,uVar8);
    uVar5 = *puVar7;
  }
  uVar5 = (uVar5 & 0xff) >> 5;
  uVar8 = *(undefined4 *)(iVar2 + 0x88);
  iVar3 = FUN_807873f0(uVar5);
  (*(code *)(&PTR_FUN_807b6e30)[iVar3])(uVar8,DAT_807c04dc);
  iVar3 = FUN_807873f0(uVar5);
  (*(code *)(&PTR_FUN_807b6e44)[iVar3])(iVar2);
  uVar8 = 0x807a3cb4;
  local_2c = iVar2;
  iVar3 = FUN_8079ec24(&local_2c,DAT_807c0b58);
  if (iVar3 == 0) {
    FUN_80745808(&DAT_807c04fc,s_________________________src_ipsx_807b087c,0x8f,uVar8);
  }
  DAT_807c04ec = DAT_807c04ec + 1;
  DAT_807c04e8 = DAT_807c04e8 + 1;
  uVar8 = 0x807a3ce4;
  iVar3 = FUN_8079c854(4,0x8502,0xffffffff);
  if (iVar3 != 0) {
    FUN_80745808(&DAT_807c04fc,s_________________________src_ipsx_807b087c,0x449,uVar8);
  }
  uVar8 = 0x807a3cfc;
  iVar2 = FUN_8079c854(4,iVar2,0xffffffff);
  if (iVar2 == 0) {
    local_28 = puVar7[2];
  }
  else {
    FUN_80745808(&DAT_807c04fc,s_________________________src_ipsx_807b087c,0x44c,uVar8);
    local_28 = puVar7[2];
  }
  uVar8 = 0x807a3d18;
  iVar2 = FUN_8079ec24(&local_28,DAT_807c0b6c);
  if (iVar2 == 0) {
    FUN_80745808(&DAT_807c04fc,s_________________________src_ipsx_807b087c,0xff,uVar8);
    local_24 = puVar7[2];
  }
  else {
    local_24 = puVar7[2];
  }
  uVar8 = 0x807a3d34;
  iVar2 = FUN_8079ec24(&local_24,DAT_807c0b70);
  if (iVar2 == 0) {
    FUN_80745808(&DAT_807c04fc,s_________________________src_ipsx_807b087c,0x120,uVar8);
  }
  return;
}

