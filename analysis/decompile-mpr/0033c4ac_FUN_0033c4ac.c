// FUN_0033c4ac
// Ghidra address: 0033c4ac

undefined8 FUN_0033c4ac(long param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  undefined1 extraout_w1;
  long lVar8;
  undefined8 local_40;
  undefined1 local_38;
  undefined2 local_30;
  undefined2 uStack_2e;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  string asStack_20 [32];
  
  bVar3 = false;
  lVar1 = *param_2;
  lVar2 = param_2[1];
  lVar8 = 0;
  bVar4 = false;
  local_40 = 0;
  local_38 = 0;
  for (iVar6 = 0; iVar6 < (int)((ulong)(lVar2 - lVar1) >> 5); iVar6 = iVar6 + 2) {
    iVar5 = FUN_0034cd04(*param_2 + lVar8);
    if (iVar5 == 6) {
      if (bVar3) {
        bVar4 = true;
      }
      else {
        bVar3 = true;
        std::__cxx11::string::string
                  (asStack_20,
                   (string *)
                   (*param_2 +
                   (-(ulong)(iVar6 + 1U >> 0x1f) & 0xffffffe000000000 | (ulong)(iVar6 + 1U) << 5)));
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
      bVar4 = true;
    }
    lVar8 = lVar8 + 0x40;
  }
  if (((bVar3) && (iVar6 = FUN_0032d6e4(*(undefined8 *)(param_1 + 0x38),&local_40,0), iVar6 != 0))
     || (uVar7 = 0, bVar4)) {
    uVar7 = 8;
  }
  return uVar7;
}

