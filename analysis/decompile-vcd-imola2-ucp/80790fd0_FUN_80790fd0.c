// FUN_80790fd0
// Ghidra address: 80790fd0

undefined4
FUN_80790fd0(undefined4 param_1,int param_2,undefined4 param_3,int param_4,uint param_5,char param_6
            ,char param_7)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  char cVar9;
  uint local_50;
  undefined4 local_4c;
  undefined4 local_48;
  uint local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  
  FUN_80792390(*(undefined4 *)(param_2 + 0x88),0);
  local_40 = FUN_80787480(param_1);
  local_3c = local_40 << 4;
  DAT_807c0a98 = param_4;
  FUN_8078e980();
  iVar7 = *(int *)(local_3c + param_2 + 0x114) >> 0xc;
  if (iVar7 == -1) {
    uVar2 = FUN_8078fe48();
  }
  else {
    uVar2 = FUN_8078fd80();
    uVar2 = iVar7 << (uVar2 & 0x1f);
  }
  local_34 = *(undefined4 *)(param_2 + 0x90);
  local_38 = 0;
  iVar7 = local_3c + param_2;
LAB_80791088:
  do {
    FUN_80794380(&local_50);
    uVar5 = local_50;
    uVar8 = local_50 & 0xff;
    uVar3 = FUN_8078f298(uVar8);
    iVar4 = FUN_80792324(uVar3);
    if (iVar4 == 0) {
      uVar6 = FUN_8077fe78(uVar8);
      if (uVar8 != uVar6) goto LAB_80791088;
    }
    local_48 = FUN_8078f264(uVar8,uVar3);
    local_44 = uVar5 >> 8;
    local_4c = uVar3;
    iVar4 = FUN_80792324(uVar3);
    cVar9 = (char)param_1;
    if (iVar4 == 0) {
      cVar1 = FUN_8078fd80();
      uVar3 = *(undefined4 *)(param_2 + 0x8c);
      iVar7 = (int)param_7;
      uVar8 = 0xffffffff;
      uVar5 = *(uint *)(local_3c + param_2 + 0x110);
LAB_807912c4:
      FUN_80788228((int)cVar9,(int)(char)local_4c,(int)(char)local_48,(int)param_6,iVar7,(int)cVar1,
                   local_44,uVar3,param_5,uVar2,uVar8,uVar5 >> 0xc);
      FUN_8079a450(local_34,uVar2,param_6,param_1);
      return 1;
    }
    FUN_80790564(local_4c,local_48,0,1,1);
    uVar5 = FUN_8078fd80();
    uVar8 = *(uint *)(param_4 + 4) << (uVar5 & 0x1f);
    if (param_7 == '\0') {
      if (uVar2 <= uVar8) {
        cVar1 = FUN_8078fd80();
        uVar3 = *(undefined4 *)(param_2 + 0x8c);
        iVar7 = 0;
        uVar5 = *(uint *)(local_3c + param_2 + 0x110);
        goto LAB_807912c4;
      }
      if (param_5 == uVar8) goto LAB_807911f4;
      local_38 = 1;
      if (param_5 < uVar8) {
        cVar1 = FUN_8078fd80();
        local_38 = 1;
        FUN_80788228((int)cVar9,(int)(char)local_4c,(int)(char)local_48,(int)param_6,0,(int)cVar1,
                     local_44,*(undefined4 *)(param_2 + 0x8c),param_5,uVar2,uVar8,
                     *(uint *)(local_3c + param_2 + 0x110) >> 0xc);
        goto LAB_807911f4;
      }
      cVar1 = FUN_8078fd80();
      FUN_80788228((int)cVar9,(int)(char)local_4c,(int)(char)local_48,(int)param_6,0,(int)cVar1,
                   local_44,*(undefined4 *)(param_2 + 0x8c),param_5,uVar2,uVar8,
                   *(uint *)(iVar7 + 0x110) >> 0xc);
    }
    else if (*(uint *)(param_4 + 4) == *(uint *)(iVar7 + 0x110) >> 0xc) {
LAB_807911f4:
      FUN_80790634(0,1,0);
      FUN_80790998(param_3,param_2,0,0);
      FUN_8079a238();
      FUN_80790ecc();
      FUN_8078fcec(param_2,local_40);
      FUN_8079a368(*(undefined4 *)(param_2 + 0x90),param_2 + local_3c + 0x110,param_6,param_1);
      return local_38;
    }
  } while( true );
}

