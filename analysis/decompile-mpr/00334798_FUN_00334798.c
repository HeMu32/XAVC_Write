// FUN_00334798
// Ghidra address: 00334798

int FUN_00334798(long param_1,undefined4 param_2,undefined4 *param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  char cVar6;
  undefined1 uStack_61;
  undefined1 auStack_60 [32];
  undefined1 *local_40;
  undefined8 uStack_38;
  undefined1 local_30 [16];
  string asStack_20 [32];
  
  if (param_3 == (undefined4 *)0x0) {
    return 2;
  }
  if (*(long *)(param_1 + 0x10) == 0) {
    return 3;
  }
  lVar4 = FUN_0032ca5c(param_1,*(long *)(param_1 + 0x10),0xd,0);
  if (lVar4 == 0) {
    return 1;
  }
  lVar4 = FUN_0032ca5c(param_1,lVar4,0x25,param_2);
  FUN_00347bc0(auStack_60,0x25);
  if (lVar4 != 0) {
    FUN_00337f5c(asStack_20,lVar4);
    cVar1 = FUN_001ba894(auStack_60,asStack_20);
    std::__cxx11::string::_M_dispose();
    if (cVar1 != '\0') {
      lVar5 = FUN_0032c960(param_1,lVar4,0x1b);
      cVar6 = cVar1;
      if (lVar5 != 0) {
        local_40 = local_30;
        uStack_38 = 0;
        local_30[0] = 0;
        FUN_00337e2c(asStack_20);
        std::__cxx11::string::operator=((string *)&local_40,asStack_20);
        std::__cxx11::string::_M_dispose();
        uVar2 = FUN_0034bf44((string *)&local_40);
        *param_3 = uVar2;
        cVar6 = '\0';
        std::__cxx11::string::_M_dispose();
      }
      lVar5 = FUN_0032c960(param_1,lVar4,0x1c);
      if (lVar5 == 0) {
        *(undefined1 *)(param_3 + 1) = 0;
      }
      else {
        FUN_00337e2c(asStack_20);
        FUN_00346a60(asStack_20,param_3 + 2,param_3 + 3);
        *(undefined1 *)(param_3 + 1) = 1;
        std::__cxx11::string::_M_dispose();
      }
      lVar5 = FUN_0032c960(param_1,lVar4,0x1d);
      if (lVar5 == 0) {
        *(undefined1 *)(param_3 + 4) = 0;
      }
      else {
        FUN_00337e2c(asStack_20);
        FUN_003472f8(asStack_20,param_3 + 5,&local_40,(long)param_3 + 0x1d,param_3 + 7);
        *(undefined1 *)(param_3 + 4) = 1;
        std::__cxx11::string::_M_dispose();
      }
      lVar5 = FUN_0032c960(param_1,lVar4,0x1e);
      if (lVar5 == 0) {
        *(undefined1 *)((long)param_3 + 0x1e) = 0;
      }
      else {
        FUN_00337e2c(asStack_20);
        FUN_003472f8(asStack_20,param_3 + 8,&uStack_61,&local_40,param_3 + 10);
        *(undefined1 *)((long)param_3 + 0x1e) = 1;
        std::__cxx11::string::_M_dispose();
      }
      lVar5 = FUN_0032c960(param_1,lVar4,0x1f);
      if (lVar5 != 0) {
        FUN_00337e2c(asStack_20);
        FUN_0034a82c(asStack_20,param_3 + 0xb,param_3 + 0xc);
        std::__cxx11::string::_M_dispose();
        cVar1 = cVar6;
      }
      lVar5 = FUN_0032c960(param_1,lVar4,0xf);
      if (lVar5 == 0) {
        *(undefined1 *)((long)param_3 + 0x31) = 0;
        iVar3 = 0;
      }
      else {
        FUN_00337e2c((string *)&local_40);
        std::__cxx11::string::string(asStack_20,(string *)&local_40);
        iVar3 = FUN_00349ca4(asStack_20,param_3 + 0xd);
        std::__cxx11::string::_M_dispose();
        if (iVar3 == 0) {
          *(undefined1 *)((long)param_3 + 0x31) = 1;
        }
        else {
          *(undefined1 *)((long)param_3 + 0x31) = 0;
          param_3[0xd] = 0;
        }
        std::__cxx11::string::_M_dispose();
      }
      lVar4 = FUN_0032c960(param_1,lVar4,0x20);
      if (lVar4 == 0) {
        *(undefined1 *)(param_3 + 0xe) = 0;
      }
      else {
        FUN_00337e2c(asStack_20);
        std::__cxx11::string::_M_assign((string *)(param_3 + 0x10));
        *(undefined1 *)(param_3 + 0xe) = 1;
        std::__cxx11::string::_M_dispose();
      }
      if (cVar1 == '\0') goto LAB_00334954;
    }
  }
  iVar3 = 1;
LAB_00334954:
  std::__cxx11::string::_M_dispose();
  return iVar3;
}

