// FUN_0033ebc8
// Ghidra address: 0033ebc8

undefined8 FUN_0033ebc8(long param_1,long *param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  undefined1 extraout_w1;
  long lVar9;
  ulong uVar10;
  long lVar11;
  int local_50;
  undefined8 local_40;
  undefined1 local_38;
  undefined2 local_30;
  undefined2 uStack_2e;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  string asStack_20 [32];
  
  lVar9 = *param_2;
  lVar7 = param_2[1];
  bVar4 = false;
  uVar10 = 1;
  lVar11 = 0;
  bVar3 = false;
  bVar1 = false;
  bVar5 = false;
  bVar2 = false;
  local_40 = 0;
  local_38 = 0;
  do {
    local_50 = (int)((ulong)(lVar7 - lVar9) >> 5);
    if (local_50 <= (int)uVar10 + -1) {
      if (((bVar5) && (iVar6 = FUN_0032c6e0(*(undefined8 *)(param_1 + 0x38),&local_40), iVar6 != 0))
         || (uVar8 = 0, bVar2)) {
        uVar8 = 8;
      }
      return uVar8;
    }
    iVar6 = FUN_0034cd04(*param_2 + lVar11);
    if (iVar6 == 1) {
      if (bVar3) {
        bVar2 = true;
      }
      else {
        iVar6 = FUN_0034b168(*param_2 + uVar10 * 0x20);
        if (iVar6 == 2) {
          return 4;
        }
        bVar3 = true;
      }
    }
    else if (iVar6 == 0) {
      if (bVar1) {
        bVar2 = true;
      }
      else {
        iVar6 = FUN_0034bc84(*param_2 + uVar10 * 0x20);
        if (iVar6 == 3) {
          return 4;
        }
        bVar1 = true;
      }
    }
    else if (iVar6 == 2) {
      if (bVar4) {
        bVar2 = true;
      }
      else {
        iVar6 = std::__cxx11::string::compare((char *)(*param_2 + uVar10 * 0x20));
        if (iVar6 != 0) {
          return 4;
        }
        bVar4 = true;
      }
    }
    else if (iVar6 == 0x12) {
      if (bVar5) {
        bVar2 = true;
      }
      else {
        bVar5 = true;
        std::__cxx11::string::string(asStack_20,(string *)(*param_2 + uVar10 * 0x20));
        local_40 = FUN_0035150c(asStack_20);
        uStack_2e = (undefined2)((ulong)local_40 >> 0x10);
        local_30 = (undefined2)local_40;
        uStack_2c = (undefined2)((ulong)local_40 >> 0x20);
        uStack_2a = (undefined2)((ulong)local_40 >> 0x30);
        local_38 = extraout_w1;
        std::__cxx11::string::_M_dispose();
      }
    }
    else {
      bVar2 = true;
    }
    lVar11 = lVar11 + 0x40;
    uVar10 = (ulong)((int)uVar10 + 2);
  } while( true );
}

