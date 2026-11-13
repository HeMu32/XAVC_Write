// FUN_807a6b90
// Ghidra address: 807a6b90

void FUN_807a6b90(uint *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  
  uVar8 = param_1[5];
  uVar6 = *param_1;
  puVar7 = *(uint **)(uVar8 + 0x8c);
  iVar2 = *(int *)(uVar8 + 0x90);
  param_1[6] = (*puVar7 & 0xff) >> 5;
  iVar1 = FUN_807873f0();
  (*(code *)(&PTR_LAB_807b6f38)[iVar1])(uVar6);
  FUN_80794b84(puVar7[5],puVar7[6]);
  FUN_807aceb0(uVar6);
  FUN_80786be8(*(undefined2 *)(iVar2 + 0xc),param_1[7]);
  FUN_807883c8(param_1,0xff);
  iVar1 = FUN_807873f0(param_1[6]);
  uVar8 = (*(code *)(&PTR_LAB_807b6f4c)[iVar1])(uVar6,uVar8);
  if ((uVar8 & 5) == 0) {
    uVar5 = param_1[5];
  }
  else {
    if (*param_1 == 0) {
      uVar3 = param_1[5];
      iVar1 = FUN_80747db0();
      uVar5 = param_1[5];
      puVar4 = (uint *)(iVar1 * 0x40 + uVar3);
      uVar3 = *(uint *)(iVar1 * 0x40 + uVar5) | 1;
    }
    else {
      uVar3 = param_1[5];
      iVar1 = FUN_80747db0();
      uVar5 = param_1[5];
      puVar4 = (uint *)(iVar1 * 0x40 + uVar3);
      uVar3 = *(uint *)(iVar1 * 0x40 + uVar5) | 2;
    }
    *puVar4 = uVar3;
  }
  iVar1 = FUN_80747db0();
  FUN_80788694(5,0xff,uVar6 & 0xff,0xffffffff,uVar8,*(undefined4 *)(iVar1 * 0x40 + uVar5),puVar7[2])
  ;
  return;
}

