// FUN_00352608
// Ghidra address: 00352608

void FUN_00352608(string *param_1,long param_2)

{
  int *piVar1;
  char cVar2;
  string asStack_c0 [8];
  long local_b8;
  undefined1 auStack_a0 [32];
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  char *local_60;
  undefined8 local_58;
  char local_50 [16];
  undefined1 auStack_40 [32];
  int local_20 [8];
  
  std::__cxx11::string::string(asStack_c0,param_1);
  if (local_b8 != 0) {
    FUN_0035148c(auStack_a0,&DAT_003db056,0x10);
    local_50[0] = '\0';
    local_60 = local_50;
    local_58 = 0;
    local_80 = 0;
    uStack_78 = 0;
    local_70 = 0;
    uStack_68 = 0;
    FUN_0035148c(auStack_40,&DAT_003de0ab,0x10);
    cVar2 = FUN_00350cec(asStack_c0,auStack_40,0);
    if (cVar2 != '\0') {
      while (cVar2 = FUN_00350d38(asStack_c0,&local_80,auStack_a0,0), cVar2 != '\0') {
        FUN_0034deac((string *)local_20,&local_80,0);
        std::__cxx11::string::append((string *)&local_60);
        std::__cxx11::string::_M_dispose();
        local_20[0] = atoi(local_60);
        piVar1 = *(int **)(param_2 + 8);
        if (piVar1 == *(int **)(param_2 + 0x10)) {
          FUN_00224d5c(param_2,(string *)local_20);
        }
        else {
          if (piVar1 != (int *)0x0) {
            *piVar1 = local_20[0];
          }
          *(int **)(param_2 + 8) = piVar1 + 1;
        }
        FUN_00350698(&local_80);
        FUN_002bea8c((string *)local_20);
        std::__cxx11::string::operator=(asStack_c0,(string *)local_20);
        std::__cxx11::string::_M_dispose();
        local_58 = 0;
        *local_60 = '\0';
      }
    }
    FUN_0034de2c(auStack_40);
    std::__cxx11::string::_M_dispose();
    FUN_002beb94(&local_80);
    FUN_0034de2c(auStack_a0);
  }
  std::__cxx11::string::_M_dispose();
  return;
}

