// FUN_00351af4
// Ghidra address: 00351af4

int * FUN_00351af4(int *param_1,string *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  string asStack_c0 [8];
  long local_b8;
  undefined1 auStack_a0 [32];
  undefined1 auStack_80 [32];
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  char *local_40;
  undefined8 uStack_38;
  char local_30 [16];
  string asStack_20 [32];
  
  uVar2 = DAT_003dc188;
  uVar1 = DAT_003dc180;
  *(undefined8 *)(param_1 + 4) = DAT_003dc190;
  *(undefined8 *)param_1 = uVar1;
  *(undefined8 *)(param_1 + 2) = uVar2;
  std::__cxx11::string::string(asStack_c0,param_2);
  if (local_b8 != 0) {
    FUN_0035148c(auStack_a0,&DAT_003db056,0x10);
    FUN_0035148c(auStack_80,&DAT_003de243,0x10);
    local_60 = 0;
    uStack_58 = 0;
    local_50 = 0;
    uStack_48 = 0;
    cVar3 = FUN_00350cec(asStack_c0,auStack_80,0);
    if (cVar3 != '\0') {
      cVar3 = FUN_00350d38(asStack_c0,&local_60,auStack_a0,0);
      if (cVar3 != '\0') {
        FUN_0034deac((string *)&local_40,&local_60,0);
        iVar4 = atoi(local_40);
        *param_1 = iVar4;
        FUN_00350698(&local_60);
        FUN_002bea8c(asStack_20);
        std::__cxx11::string::operator=(asStack_c0,asStack_20);
        std::__cxx11::string::_M_dispose();
        std::__cxx11::string::_M_dispose();
      }
      cVar3 = FUN_00350d38(asStack_c0,&local_60,auStack_a0,0);
      if (cVar3 != '\0') {
        FUN_0034deac((string *)&local_40,&local_60,0);
        iVar4 = atoi(local_40);
        param_1[2] = iVar4;
        FUN_00350698(&local_60);
        FUN_002bea8c(asStack_20);
        std::__cxx11::string::operator=(asStack_c0,asStack_20);
        std::__cxx11::string::_M_dispose();
        std::__cxx11::string::_M_dispose();
      }
      local_40 = local_30;
      local_30[0] = '\0';
      uStack_38 = 0;
      while (cVar3 = FUN_00350d38(asStack_c0,&local_60,auStack_a0,0), cVar3 != '\0') {
        FUN_0034deac(asStack_20,&local_60,0);
        std::__cxx11::string::append((string *)&local_40);
        std::__cxx11::string::_M_dispose();
        FUN_00350698(&local_60);
        FUN_002bea8c(asStack_20);
        std::__cxx11::string::operator=(asStack_c0,asStack_20);
        std::__cxx11::string::_M_dispose();
      }
      iVar4 = atoi(local_40);
      param_1[4] = iVar4;
      param_1[5] = 1000;
      std::__cxx11::string::_M_dispose();
    }
    FUN_002beb94(&local_60);
    FUN_0034de2c(auStack_80);
    FUN_0034de2c(auStack_a0);
  }
  std::__cxx11::string::_M_dispose();
  return param_1;
}

