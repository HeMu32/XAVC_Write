// FUN_807a6764
// Ghidra address: 807a6764

undefined4 FUN_807a6764(undefined4 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 *puStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  puVar4 = *(uint **)(param_2 + 0xc);
  FUN_8079f1d0(*(undefined4 *)(param_2 + 4),0,0x130);
  puVar3 = *(uint **)(param_2 + 0xc);
  FUN_80794b84(puVar3[5],puVar3[6]);
  FUN_807aceb0(*param_1);
  iVar1 = FUN_807873f0((*puVar3 & 0xff) >> 5);
  (*(code *)(&PTR_FUN_807b6f74)[iVar1])(param_2);
  iVar1 = FUN_807873f0((*puVar4 & 0xff) >> 5);
  (*(code *)(&PTR_FUN_807b6f88)[iVar1])(param_2);
  puVar4 = *(uint **)(param_2 + 4);
  uVar2 = *puVar4;
  puVar3 = puVar4 + 4;
  uVar5 = 0;
  if ((uVar2 & 0xfff) >> 4 != 0) {
    do {
      if ((uVar5 != 0) && (*puVar3 >> 0xc == 0)) {
        *puVar4 = uVar2 & 0xfffff00f | (uVar5 & 0xff) << 4;
        break;
      }
      uVar6 = uVar5 + 1;
      FUN_80787ac4(param_2,uVar5);
      uVar2 = *puVar4;
      puVar3 = puVar3 + 2;
      uVar5 = uVar6;
    } while (uVar6 < (uVar2 & 0xfff) >> 4 && uVar6 < 0x24);
  }
  FUN_8079497c(*param_1);
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  puStack_40 = param_1;
  FUN_80788604(0x65,0,0,0,&puStack_40,7);
  uVar7 = 0x807a68b8;
  iVar1 = FUN_8079c854(4,param_1[2],0xffffffff);
  if (iVar1 != 0) {
    FUN_80745808(&DAT_807c0534,s_________________________src_ipsx_807b0960,0x209,uVar7);
  }
  return 0;
}

