// FUN_0028dc7c
// Ghidra address: 0028dc7c

int FUN_0028dc7c(long *param_1,char *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  ulong uVar6;
  size_t sVar7;
  ulong uVar8;
  undefined8 uVar9;
  int iVar10;
  long lVar11;
  char local_28 [8];
  char acStack_20 [8];
  long local_18 [2];
  int local_8;
  
  cVar4 = (**(code **)(*param_1 + 0xa8))();
  if (cVar4 == '\0') {
    iVar5 = *(int *)(param_1[0xc] + 0x18);
    uVar3 = *(int *)(param_1[0xc] + 0x1c) - iVar5;
    FUN_00291210(param_1[5],1,iVar5,uVar3);
    FUN_00291228(local_18,param_1[5]);
    if (local_8 != 0) {
      FUN_0028bc28(param_1[1],2);
      uVar9 = 0x377;
      iVar5 = local_8;
LAB_0028dd28:
      FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",uVar9,iVar5);
      return iVar5;
    }
    local_28[0] = s_masterVersion___003d81f2[0];
    local_28[1] = s_masterVersion___003d81f2[1];
    local_28[2] = s_masterVersion___003d81f2[2];
    local_28[3] = s_masterVersion___003d81f2[3];
    local_28[4] = s_masterVersion___003d81f2[4];
    local_28[5] = s_masterVersion___003d81f2[5];
    local_28[6] = s_masterVersion___003d81f2[6];
    local_28[7] = s_masterVersion___003d81f2[7];
    acStack_20[0] = s_masterVersion___003d81f2[8];
    acStack_20[1] = s_masterVersion___003d81f2[9];
    acStack_20[2] = s_masterVersion___003d81f2[10];
    acStack_20[3] = s_masterVersion___003d81f2[0xb];
    acStack_20[4] = s_masterVersion___003d81f2[0xc];
    acStack_20[5] = s_masterVersion___003d81f2[0xd];
    acStack_20[6] = s_masterVersion___003d81f2[0xe];
    acStack_20[7] = s_masterVersion___003d81f2[0xf];
    uVar8 = 0;
    for (uVar6 = 0; uVar3 != uVar6; uVar6 = uVar6 + 1) {
      if (local_28[uVar8] == *(char *)(local_18[0] + uVar6)) {
        uVar1 = (int)uVar8 + 1;
        uVar8 = (ulong)uVar1;
        if (uVar1 == 0xf) {
          uVar1 = (int)uVar6 + 1;
          if (uVar1 != 0) {
            iVar10 = 0;
            for (uVar2 = uVar1; (uVar2 < uVar3 && (*(char *)(local_18[0] + (ulong)uVar2) != '\"'));
                uVar2 = uVar2 + 1) {
              iVar10 = iVar10 + 1;
            }
            if (iVar10 != 0) {
              if (param_2 == (char *)0x0) {
                FUN_0028bc28(param_1[1],2);
                uVar9 = 0x3b5;
LAB_0028de10:
                FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",uVar9);
                return 2;
              }
              sVar7 = strlen(param_2);
              if (iVar10 != (int)sVar7) {
                FUN_0028bc28(param_1[1],2);
                uVar9 = 0x3bb;
                goto LAB_0028de10;
              }
              FUN_00291d44(param_1[6],iVar5 + uVar1);
              iVar5 = FUN_00291dfc(param_1[6],param_2,iVar10);
              if (iVar5 == 0) {
                iVar5 = FUN_00291d4c(param_1[6]);
                if (iVar5 == 0) {
                  lVar11 = param_1[0xc];
                  *(undefined4 *)(lVar11 + 0xec00) = 1;
                  sVar7 = strlen(param_2);
                  if ((uint)sVar7 < 0x40) {
                    *(uint *)(lVar11 + 0xec04) = (uint)sVar7;
                    memcpy((void *)(lVar11 + 0xec08),param_2,sVar7 & 0xffffffff);
                    *(undefined1 *)(lVar11 + (sVar7 & 0xffffffff) + 0xec08) = 0;
                  }
                  else {
                    *(undefined4 *)(lVar11 + 0xec00) = 4;
                  }
                  return 0;
                }
                FUN_0028bc28(param_1[1],2);
                uVar9 = 0x3cd;
              }
              else {
                FUN_0028bc28(param_1[1],2);
                uVar9 = 0x3c6;
              }
              goto LAB_0028dd28;
            }
            FUN_0028bc28(param_1[1],2);
            uVar9 = 0x3ab;
            goto LAB_0028dcb4;
          }
          break;
        }
      }
      else {
        uVar8 = 0;
      }
    }
    FUN_0028bc28(param_1[1],2);
    uVar9 = 0x396;
  }
  else {
    uVar9 = 0x369;
  }
LAB_0028dcb4:
  FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",uVar9,0xf);
  return 0xf;
}

