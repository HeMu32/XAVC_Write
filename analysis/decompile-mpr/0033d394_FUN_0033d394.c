// FUN_0033d394
// Ghidra address: 0033d394

undefined4 FUN_0033d394(long param_1,long *param_2)

{
  bool bVar1;
  long lVar2;
  long lVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  undefined4 uVar7;
  int iVar8;
  long lVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  int local_d0;
  byte local_a1;
  string asStack_a0 [8];
  ulong local_98;
  undefined4 local_80 [8];
  int local_60;
  undefined1 local_5c;
  undefined4 local_58;
  int local_54;
  undefined1 local_50;
  undefined1 auStack_4c [8];
  char local_44 [4];
  undefined1 auStack_40 [8];
  char local_38 [4];
  int local_34;
  undefined1 local_30;
  bool local_2f;
  undefined4 local_2c;
  bool local_28;
  undefined1 *local_20;
  undefined8 local_18;
  undefined1 local_10 [16];
  
  local_20 = local_10;
  bVar12 = 0;
  local_10[0] = 0;
  local_5c = 0;
  bVar14 = 0;
  local_50 = 0;
  bVar13 = 0;
  local_44[0] = '\0';
  bVar11 = 0;
  local_44[1] = 0;
  bVar10 = 0;
  local_44[2] = 0;
  local_38[0] = '\0';
  local_30 = 0;
  local_2f = false;
  local_28 = false;
  local_60 = 0;
  local_58 = 0;
  local_34 = 0;
  local_2c = 0;
  local_18 = 0;
  local_54 = 1;
  lVar2 = *param_2;
  lVar3 = param_2[1];
  bVar5 = 0;
  bVar4 = 0;
  bVar6 = 0;
  for (lVar9 = 0; local_d0 = (int)((ulong)(lVar3 - lVar2) >> 5), (int)lVar9 * 2 < local_d0;
      lVar9 = lVar9 + 1) {
    std::__cxx11::string::string(asStack_a0,(string *)(*param_2 + lVar9 * 0x40 + 0x20));
    uVar7 = FUN_0034cd04(*param_2 + lVar9 * 0x40);
    switch(uVar7) {
    case 0xf:
      bVar15 = bVar13;
      if (bVar13 == 0) {
        std::__cxx11::string::string((string *)local_80,asStack_a0);
        iVar8 = FUN_00349ca4((string *)local_80,&local_2c);
        std::__cxx11::string::_M_dispose();
        if (iVar8 != 0) {
          bVar6 = 1;
        }
        local_2f = iVar8 == 0;
        bVar13 = 1;
        bVar15 = bVar6;
      }
      break;
    default:
      bVar15 = 1;
      break;
    case 0x1b:
      bVar15 = bVar10;
      if (bVar10 == 0) {
        bVar10 = 1;
        local_60 = FUN_0034bf44(asStack_a0);
        bVar15 = bVar6;
        if (local_60 == 0x9a) {
          bVar15 = 1;
        }
      }
      break;
    case 0x1c:
      bVar15 = bVar11;
      if (bVar11 == 0) {
        FUN_00346a60(asStack_a0,&local_58,&local_54);
        local_5c = local_54 != 4;
        bVar11 = 1;
        bVar15 = bVar6;
      }
      break;
    case 0x1d:
      bVar15 = bVar4;
      if (bVar4 == 0) {
        FUN_003472f8(asStack_a0,auStack_4c,local_80,local_44 + 1,local_44);
        if ((local_80[0]._0_1_ == (string)0x0) && (local_44[0] == '\0')) {
          local_50 = 0;
          bVar6 = 1;
        }
        else {
          local_50 = 1;
        }
        bVar4 = 1;
        bVar15 = bVar6;
      }
      break;
    case 0x1e:
      bVar15 = bVar5;
      if (bVar5 == 0) {
        FUN_003472f8(asStack_a0,auStack_40,&local_a1,local_80,local_38);
        if ((local_a1 == 0) || (local_38[0] != '\0')) {
          local_44[2] = 1;
        }
        else {
          local_44[2] = 0;
          bVar6 = local_a1;
        }
        bVar5 = 1;
        bVar15 = bVar6;
      }
      break;
    case 0x1f:
      bVar15 = bVar12;
      if (bVar12 == 0) {
        bVar12 = 1;
        FUN_0034a82c(asStack_a0,&local_34,&local_30);
        bVar15 = bVar6;
        if (local_34 == 0x14) {
          bVar15 = 1;
        }
      }
      break;
    case 0x20:
      bVar15 = bVar14;
      if (bVar14 == 0) {
        bVar1 = 0x10 < local_98;
        if (bVar1) {
          bVar6 = 1;
        }
        else {
          std::__cxx11::string::_M_assign((string *)&local_20);
        }
        local_28 = !bVar1;
        bVar14 = 1;
        bVar15 = bVar6;
      }
    }
    std::__cxx11::string::_M_dispose();
    bVar6 = bVar15;
  }
  local_80[0] = 0;
  iVar8 = FUN_00333b70(*(undefined8 *)(param_1 + 0x38),0xffffffff,&local_60);
  uVar7 = 0;
  if (iVar8 != 0) {
    uVar7 = 8;
  }
  if (bVar6 != 0) {
    uVar7 = 8;
  }
  std::__cxx11::string::_M_dispose();
  return uVar7;
}

