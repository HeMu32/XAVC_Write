// FUN_80798344
// Ghidra address: 80798344

void FUN_80798344(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 auStack_90 [16];
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  
  uVar7 = 0;
  puVar5 = *(uint **)(param_1 + 0xc);
  iVar9 = *(int *)(param_1 + 8);
  uVar3 = *puVar5;
  uStack_48 = 0;
  uStack_4c = 0;
  uStack_44 = 0;
  uStack_38 = 0;
  uVar11 = 0x807983a4;
  puVar6 = *(uint **)(param_1 + 4);
  FUN_80792420(iVar9,*(undefined4 *)(param_1 + 0x10));
  if ((int)(uVar3 << 0x1c) < 0) {
    if ((int)(uVar3 << 0x1c) < 0) {
      uVar7 = 0;
      FUN_8078e980();
      FUN_807992fc();
      FUN_807992ec();
      uStack_40 = 0;
      puVar4 = puVar5;
      uVar3 = 0;
      do {
        uVar2 = puVar4[8];
        uVar8 = uVar3 + 1;
        if (uVar2 == 0) break;
        uVar10 = puVar4[7];
        auStack_90[uVar3] = puVar4 + 7;
        puVar1 = puVar4 + 9;
        puVar4 = puVar4 + 3;
        FUN_8079486c((*puVar5 & 0xff) >> 5,uVar2 + uVar10,*puVar1,1,0,(*puVar5 & 0xf) >> 3);
        FUN_80788074(0,puVar5[2]);
        FUN_80794380(&uStack_50);
        uStack_3c = uStack_50;
        uVar11 = FUN_8078f298(uStack_50 & 0xff);
        uVar3 = FUN_80792530(uVar11,&uStack_40,&uStack_3c);
        uVar7 = uVar7 | uVar3;
        uStack_44 = uStack_44 | uStack_40;
        uVar3 = uVar8;
      } while (uVar8 < 0xd);
      uStack_34 = 0;
      uVar3 = FUN_80798678(param_1,&uStack_44,&uStack_38,&uStack_34,&uStack_48);
      uVar7 = uVar7 | uVar3;
      FUN_807991f4();
      uStack_4c = FUN_8078e974();
      FUN_8078e980();
      *puVar6 = *puVar6 & 0xfff0000f | (uStack_34 & 0xff) << 0xc | (uStack_38 & 0xff) << 4;
    }
    else {
      FUN_80745808(&DAT_807c0414,s_________________________src_ipsx_807aff84,0x1b1,uVar11);
    }
  }
  else {
    FUN_8079486c((*puVar5 & 0xff) >> 5,puVar5[3],puVar5[4],1,0,0);
    FUN_80788074(0,puVar5[2]);
    uVar7 = FUN_807920dc(iVar9 + 0x19b30,&DAT_807c0410,&uStack_4c,&uStack_48);
    uStack_44 = uStack_44 | uStack_4c;
  }
  puVar6[1] = uStack_44;
  puVar6[2] = uVar7;
  *puVar6 = *puVar6 & 0xfffffff9 | (uStack_48 & 1) << 1;
  for (uVar7 = iVar9 + 0x19b30U & 0xffffffc0; uVar7 < iVar9 + 0x19b54U; uVar7 = uVar7 + 0x40) {
    cacheOp(0x1a,uVar7);
  }
  return;
}

