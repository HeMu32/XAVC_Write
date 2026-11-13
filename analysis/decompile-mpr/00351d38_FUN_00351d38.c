// FUN_00351d38
// Ghidra address: 00351d38

ulong FUN_00351d38(string *param_1)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  string asStack_c0 [8];
  long local_b8;
  undefined1 auStack_a0 [32];
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  char *local_60;
  undefined8 uStack_58;
  char local_50 [16];
  undefined1 auStack_40 [32];
  string asStack_20 [32];
  
  std::__cxx11::string::string(asStack_c0,param_1);
  if (local_b8 == 0) {
    uVar4 = 0x100000000;
  }
  else {
    FUN_0035148c(auStack_a0,&DAT_003db056,0x10);
    local_50[0] = '\0';
    local_60 = local_50;
    uStack_58 = 0;
    local_80 = 0;
    uStack_78 = 0;
    local_70 = 0;
    uStack_68 = 0;
    FUN_0035148c(auStack_40,"\\d{1,2}.\\d{3}",0x10);
    cVar1 = FUN_00350cec(asStack_c0,auStack_40,0);
    if (cVar1 == '\0') {
      uVar4 = 0;
      lVar3 = 1;
    }
    else {
      while (cVar1 = FUN_00350d38(asStack_c0,&local_80,auStack_a0,0), cVar1 != '\0') {
        FUN_0034deac(asStack_20,&local_80,0);
        std::__cxx11::string::append((string *)&local_60);
        std::__cxx11::string::_M_dispose();
        FUN_00350698(&local_80);
        FUN_002bea8c(asStack_20);
        std::__cxx11::string::operator=(asStack_c0,asStack_20);
        std::__cxx11::string::_M_dispose();
      }
      uVar2 = atoi(local_60);
      uVar4 = (ulong)uVar2;
      lVar3 = 1000;
    }
    uVar4 = uVar4 | lVar3 << 0x20;
    FUN_0034de2c(auStack_40);
    std::__cxx11::string::_M_dispose();
    FUN_002beb94(&local_80);
    FUN_0034de2c(auStack_a0);
  }
  std::__cxx11::string::_M_dispose();
  return uVar4;
}

