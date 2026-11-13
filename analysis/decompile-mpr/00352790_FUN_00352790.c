// FUN_00352790
// Ghidra address: 00352790

undefined8 FUN_00352790(string *param_1,long param_2)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined1 auStack_80 [32];
  undefined1 *local_60;
  long local_58;
  char *local_40;
  undefined8 uStack_38;
  char local_30 [16];
  char *local_20 [4];
  
  uVar3 = 2;
  FUN_0035148c(auStack_80,"\\d.\\d.\\d.\\d",0x10);
  cVar1 = FUN_00350cec(param_1,auStack_80,0);
  if (cVar1 != '\0') {
    std::__cxx11::string::string((string *)&local_60,param_1);
    for (uVar4 = 0; local_58 != 0 && uVar4 < 4; uVar4 = uVar4 + 1) {
      lVar2 = std::__cxx11::string::find((char)(string *)&local_60,0x2e);
      local_30[0] = '\0';
      uStack_38 = 0;
      local_40 = local_30;
      if (lVar2 == -1) {
        std::__cxx11::string::_M_assign((string *)&local_40);
        local_58 = 0;
        *local_60 = 0;
      }
      else {
        std::__cxx11::string::substr((ulong)&local_60,0);
        std::__cxx11::string::operator=((string *)&local_40,(string *)local_20);
        std::__cxx11::string::_M_dispose();
        std::__cxx11::string::erase((ulong)&local_60,0);
      }
      local_20[0] = (char *)0x0;
      lVar2 = strtol(local_40,local_20,10);
      if (*local_20[0] != '\0') {
        uVar3 = 2;
        std::__cxx11::string::_M_dispose();
        goto LAB_00352818;
      }
      *(char *)(param_2 + (ulong)uVar4) = (char)lVar2;
      std::__cxx11::string::_M_dispose();
    }
    uVar3 = 0;
LAB_00352818:
    std::__cxx11::string::_M_dispose();
  }
  FUN_0034de2c(auStack_80);
  return uVar3;
}

