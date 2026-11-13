// FUN_00351ea8
// Ghidra address: 00351ea8

int * FUN_00351ea8(int *param_1,string *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  string asStack_c0 [8];
  long local_b8;
  undefined1 auStack_a0 [32];
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined1 auStack_60 [32];
  char *local_40;
  undefined8 uStack_38;
  char local_30 [16];
  string asStack_20 [32];
  
  uVar2 = DAT_003dc1a0;
  uVar1 = DAT_003dc198;
  *(undefined8 *)(param_1 + 4) = DAT_003dc1a8;
  *(undefined8 *)param_1 = uVar1;
  *(undefined8 *)(param_1 + 2) = uVar2;
  std::__cxx11::string::string(asStack_c0,param_2);
  if (local_b8 != 0) {
    FUN_0035148c(auStack_a0,&DAT_003db056,0x10);
    local_80 = 0;
    uStack_78 = 0;
    local_70 = 0;
    uStack_68 = 0;
    FUN_0035148c(auStack_60,"([0-2][0-9]|[0-9]):([0-6][0-9]|[0-9]):([0-6][0-9]|[0-9]).\\d{3}",0x10);
    cVar3 = FUN_00350cec(asStack_c0,auStack_60,0);
    if (cVar3 != '\0') {
      cVar3 = FUN_00350d38(asStack_c0,&local_80,auStack_a0,0);
      if (cVar3 != '\0') {
        FUN_0034deac((string *)&local_40,&local_80,0);
        iVar4 = atoi(local_40);
        *param_1 = iVar4;
        FUN_00350698(&local_80);
        FUN_002bea8c(asStack_20);
        std::__cxx11::string::operator=(asStack_c0,asStack_20);
        std::__cxx11::string::_M_dispose();
        std::__cxx11::string::_M_dispose();
      }
      cVar3 = FUN_00350d38(asStack_c0,&local_80,auStack_a0,0);
      if (cVar3 != '\0') {
        FUN_0034deac((string *)&local_40,&local_80,0);
        iVar4 = atoi(local_40);
        param_1[2] = iVar4;
        FUN_00350698(&local_80);
        FUN_002bea8c(asStack_20);
        std::__cxx11::string::operator=(asStack_c0,asStack_20);
        std::__cxx11::string::_M_dispose();
        std::__cxx11::string::_M_dispose();
      }
      local_40 = local_30;
      local_30[0] = '\0';
      uStack_38 = 0;
      while (cVar3 = FUN_00350d38(asStack_c0,&local_80,auStack_a0,0), cVar3 != '\0') {
        FUN_0034deac(asStack_20,&local_80,0);
        std::__cxx11::string::append((string *)&local_40);
        std::__cxx11::string::_M_dispose();
        FUN_00350698(&local_80);
        FUN_002bea8c(asStack_20);
        std::__cxx11::string::operator=(asStack_c0,asStack_20);
        std::__cxx11::string::_M_dispose();
      }
      iVar4 = atoi(local_40);
      param_1[4] = iVar4;
      param_1[5] = 1000;
      std::__cxx11::string::_M_dispose();
    }
    FUN_0034de2c(auStack_60);
    FUN_002beb94(&local_80);
    FUN_0034de2c(auStack_a0);
  }
  std::__cxx11::string::_M_dispose();
  return param_1;
}

