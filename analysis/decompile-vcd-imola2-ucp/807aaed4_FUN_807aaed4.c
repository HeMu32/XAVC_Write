// FUN_807aaed4
// Ghidra address: 807aaed4

undefined4 FUN_807aaed4(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 uVar7;
  
  puVar6 = *(uint **)(param_2 + 0x8c);
  FUN_8079486c((*puVar6 & 0xff) >> 5,puVar6[3],puVar6[4],1,param_1,(*puVar6 & 0xf) >> 3);
  FUN_80788074(param_1,puVar6[2]);
  FUN_807acc78();
  FUN_807aceb0(param_1);
  FUN_807ab3dc();
  piVar3 = *(int **)(param_2 + 0x88);
  uVar5 = piVar3[0x23];
  uVar2 = ((uVar5 & 0x7fff) >> 0xd) << 0xc | (piVar3[1] & 0xffffffU) >> 0xc;
  uVar4 = uVar2 + 0xf >> 4;
  if ((-1 < (int)(uVar5 << 0x17)) && (-1 < *piVar3 << 3)) {
    uVar4 = (uVar2 + 0x1f >> 5) << 1;
    if ((piVar3[0x2d] & 0xfffffU) >> 0x12 != 3) {
      uVar4 = uVar2 + 0x1f >> 5;
    }
  }
  FUN_807accb0(param_2,(((uVar5 & 0x1fff) >> 0xb) << 0xc | piVar3[1] & 0xfffU) + 0xf >> 4,uVar4);
  FUN_807acb48();
  iVar1 = FUN_8078691c(param_1);
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & 0xfffff00f | 0x10 | (param_1 & 1) << 0xb | 0x1000;
  uVar7 = 0x807ab004;
  iVar1 = FUN_8079c854(7,iVar1,0xffffffff);
  if (iVar1 != 0) {
    FUN_80745808(&DAT_807c05d4,s_________________________src_ipsx_807b0afc,0x59,uVar7);
  }
  return 0;
}

