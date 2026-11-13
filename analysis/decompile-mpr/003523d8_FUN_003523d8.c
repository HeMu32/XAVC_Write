// FUN_003523d8
// Ghidra address: 003523d8

uint FUN_003523d8(string *param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  string asStack_c0 [8];
  long local_b8;
  undefined1 auStack_a0 [32];
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined1 auStack_60 [32];
  char *local_40 [4];
  string asStack_20 [32];
  
  uVar2 = 0;
  std::__cxx11::string::string(asStack_c0,param_1);
  if (local_b8 != 0) {
    uVar2 = 0;
    FUN_0035148c(auStack_a0,&DAT_003db056,0x10);
    local_80 = 0;
    uStack_78 = 0;
    local_70 = 0;
    uStack_68 = 0;
    FUN_0035148c(auStack_60,"\\d{4}:[0-1][0-9]:[0-3][0-9]",0x10);
    cVar1 = FUN_00350cec(asStack_c0,auStack_60,0);
    if (cVar1 != '\0') {
      uVar2 = 0;
      cVar1 = FUN_00350d38(asStack_c0,&local_80,auStack_a0,0);
      if (cVar1 != '\0') {
        FUN_0034deac(local_40,&local_80,0);
        uVar2 = atoi(local_40[0]);
        uVar2 = uVar2 & 0xffff;
        FUN_00350698(&local_80);
        FUN_002bea8c(asStack_20);
        std::__cxx11::string::operator=(asStack_c0,asStack_20);
        std::__cxx11::string::_M_dispose();
        std::__cxx11::string::_M_dispose();
      }
      uVar3 = 0;
      cVar1 = FUN_00350d38(asStack_c0,&local_80,auStack_a0,0);
      if (cVar1 != '\0') {
        FUN_0034deac(local_40,&local_80,0);
        uVar3 = atoi(local_40[0]);
        uVar3 = uVar3 & 0xff;
        FUN_00350698(&local_80);
        FUN_002bea8c(asStack_20);
        std::__cxx11::string::operator=(asStack_c0,asStack_20);
        std::__cxx11::string::_M_dispose();
        std::__cxx11::string::_M_dispose();
      }
      uVar4 = 0;
      cVar1 = FUN_00350d38(asStack_c0,&local_80,auStack_a0,0);
      if (cVar1 != '\0') {
        FUN_0034deac(local_40,&local_80,0);
        uVar4 = atoi(local_40[0]);
        uVar4 = uVar4 & 0xff;
        FUN_00350698(&local_80);
        FUN_002bea8c(asStack_20);
        std::__cxx11::string::operator=(asStack_c0,asStack_20);
        std::__cxx11::string::_M_dispose();
        std::__cxx11::string::_M_dispose();
      }
      uVar2 = uVar2 | uVar3 << 0x10 | uVar4 << 0x18;
    }
    FUN_0034de2c(auStack_60);
    FUN_002beb94(&local_80);
    FUN_0034de2c(auStack_a0);
  }
  std::__cxx11::string::_M_dispose();
  return uVar2;
}

