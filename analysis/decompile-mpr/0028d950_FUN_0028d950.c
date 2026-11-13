// FUN_0028d950
// Ghidra address: 0028d950

int FUN_0028d950(long *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  undefined8 uVar9;
  ulong uVar10;
  char local_28 [8];
  char local_20 [8];
  long local_18 [2];
  int local_8;
  
  cVar4 = (**(code **)(*param_1 + 0xa8))();
  if (cVar4 == '\0') {
    iVar6 = *(int *)(param_1[0xc] + 0x10);
    uVar3 = *(int *)(param_1[0xc] + 0x14) - iVar6;
    FUN_00291210(param_1[5],1,iVar6,uVar3);
    FUN_00291228(local_18,param_1[5]);
    if (local_8 != 0) {
      FUN_0028bc28(param_1[1],2);
      uVar9 = 0x3ef;
      iVar6 = local_8;
LAB_0028d9f8:
      FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",uVar9,iVar6);
      return iVar6;
    }
    uVar10 = 0;
    local_28[0] = s_createdAt___003d81e6[0];
    local_28[1] = s_createdAt___003d81e6[1];
    local_28[2] = s_createdAt___003d81e6[2];
    local_28[3] = s_createdAt___003d81e6[3];
    local_28[4] = s_createdAt___003d81e6[4];
    local_28[5] = s_createdAt___003d81e6[5];
    local_28[6] = s_createdAt___003d81e6[6];
    local_28[7] = s_createdAt___003d81e6[7];
    local_20[0] = s_createdAt___003d81e6[8];
    local_20[1] = s_createdAt___003d81e6[9];
    local_20[2] = s_createdAt___003d81e6[10];
    local_20[3] = s_createdAt___003d81e6[0xb];
    for (uVar7 = 0; uVar7 != uVar3; uVar7 = uVar7 + 1) {
      if (local_28[uVar10] == *(char *)(local_18[0] + uVar7)) {
        uVar1 = (int)uVar10 + 1;
        uVar10 = (ulong)uVar1;
        if (uVar1 == 0xb) {
          uVar1 = (int)uVar7 + 1;
          if (uVar1 != 0) {
            iVar5 = 0;
            for (uVar2 = uVar1; (uVar2 < uVar3 && (*(char *)(local_18[0] + (ulong)uVar2) != '\"'));
                uVar2 = uVar2 + 1) {
              iVar5 = iVar5 + 1;
            }
            if (iVar5 != 0) {
              if (*param_2 != 1) {
                FUN_0028bc28(param_1[1],2);
                uVar9 = 0x42d;
LAB_0028daf0:
                FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",uVar9);
                return 2;
              }
              if (iVar5 != param_2[1]) {
                FUN_0028bc28(param_1[1],2);
                uVar9 = 0x433;
                goto LAB_0028daf0;
              }
              FUN_00291d44(param_1[6],iVar6 + uVar1);
              (**(code **)(*param_1 + 0xc0))(param_1,param_1[6],param_2);
              iVar6 = FUN_00291d4c(param_1[6]);
              if (iVar6 == 0) {
                lVar8 = param_1[0xc];
                uVar9 = *(undefined8 *)(param_2 + 2);
                *(undefined8 *)(lVar8 + 0xeaf0) = *(undefined8 *)param_2;
                *(undefined8 *)(lVar8 + 0xeaf8) = uVar9;
                *(undefined8 *)(lVar8 + 0xeb00) = *(undefined8 *)(param_2 + 4);
                return 0;
              }
              FUN_0028bc28(param_1[1],2);
              uVar9 = 0x43f;
              goto LAB_0028d9f8;
            }
            FUN_0028bc28(param_1[1],2);
            uVar9 = 0x423;
            goto LAB_0028d988;
          }
          break;
        }
      }
      else {
        uVar10 = 0;
      }
    }
    FUN_0028bc28(param_1[1],2);
    uVar9 = 0x40e;
  }
  else {
    uVar9 = 0x3e0;
  }
LAB_0028d988:
  FUN_00290aa4(2,"xavcIfo_CommonMediaProfileParserImplState.cpp",uVar9,0x10);
  return 0x10;
}

