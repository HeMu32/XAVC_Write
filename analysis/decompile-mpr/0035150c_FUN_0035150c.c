// FUN_0035150c
// Ghidra address: 0035150c

undefined1  [16] FUN_0035150c(string *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined2 uVar10;
  undefined1 auVar11 [16];
  string asStack_c0 [8];
  long local_b8;
  undefined1 auStack_a0 [32];
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined1 auStack_60 [32];
  char *local_40;
  undefined8 local_38;
  short local_20;
  undefined2 local_1e;
  undefined1 local_1c;
  undefined1 uStack_1b;
  undefined1 local_1a;
  undefined1 uStack_19;
  undefined1 local_18;
  undefined1 uStack_17;
  
  std::__cxx11::string::string(asStack_c0,param_1);
  if (local_b8 == 0) {
    local_20 = 0;
    local_1e = 0;
    local_1c = 0;
    uStack_1b = 0;
    local_1a = 0;
    uStack_19 = 0;
    local_18 = 0;
    goto LAB_0035155c;
  }
  FUN_0035148c(auStack_a0,&DAT_003db056,0x10);
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  FUN_0035148c(auStack_60,&DAT_003de0d1,0x10);
  cVar3 = FUN_00350cec(asStack_c0,auStack_60,0);
  if (cVar3 == '\0') {
    local_20 = 0;
    local_1e = 0;
    local_1c = 0;
    uStack_1b = 0;
    local_1a = 0;
    uStack_19 = 0;
    local_18 = 0;
  }
  else {
    uVar10 = 0;
    cVar3 = FUN_00350d38(asStack_c0,&local_80,auStack_a0,0);
    if (cVar3 != '\0') {
      FUN_0034deac(&local_40,&local_80,0);
      iVar4 = atoi(local_40);
      uVar10 = (undefined2)iVar4;
      FUN_00350698(&local_80);
      FUN_002bea8c((string *)&local_20);
      std::__cxx11::string::operator=(asStack_c0,(string *)&local_20);
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::_M_dispose();
    }
    uVar9 = 0;
    cVar3 = FUN_00350d38(asStack_c0,&local_80,auStack_a0,0);
    if (cVar3 != '\0') {
      FUN_0034deac(&local_40,&local_80,0);
      iVar4 = atoi(local_40);
      uVar9 = (undefined1)iVar4;
      FUN_00350698(&local_80);
      FUN_002bea8c((string *)&local_20);
      std::__cxx11::string::operator=(asStack_c0,(string *)&local_20);
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::_M_dispose();
    }
    uVar8 = 0;
    cVar3 = FUN_00350d38(asStack_c0,&local_80,auStack_a0,0);
    if (cVar3 != '\0') {
      FUN_0034deac(&local_40,&local_80,0);
      iVar4 = atoi(local_40);
      uVar8 = (undefined1)iVar4;
      FUN_00350698(&local_80);
      FUN_002bea8c((string *)&local_20);
      std::__cxx11::string::operator=(asStack_c0,(string *)&local_20);
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::_M_dispose();
    }
    uVar7 = 0;
    cVar3 = FUN_00350d38(asStack_c0,&local_80,auStack_a0,0);
    if (cVar3 != '\0') {
      FUN_0034deac(&local_40,&local_80,0);
      iVar4 = atoi(local_40);
      uVar7 = (undefined1)iVar4;
      FUN_00350698(&local_80);
      FUN_002bea8c((string *)&local_20);
      std::__cxx11::string::operator=(asStack_c0,(string *)&local_20);
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::_M_dispose();
    }
    cVar3 = FUN_00350d38(asStack_c0,&local_80,auStack_a0,0);
    uVar1 = 0;
    if (cVar3 != '\0') {
      FUN_0034deac(&local_40,&local_80,0);
      iVar4 = atoi(local_40);
      uVar1 = (undefined1)iVar4;
      FUN_00350698(&local_80);
      FUN_002bea8c((string *)&local_20);
      std::__cxx11::string::operator=(asStack_c0,(string *)&local_20);
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::_M_dispose();
    }
    cVar3 = FUN_00350d38(asStack_c0,&local_80,auStack_a0,0);
    uVar2 = 0;
    if (cVar3 != '\0') {
      FUN_0034deac(&local_40,&local_80,0);
      iVar4 = atoi(local_40);
      uVar2 = (undefined1)iVar4;
      FUN_00350698(&local_80);
      FUN_002bea8c((string *)&local_20);
      std::__cxx11::string::operator=(asStack_c0,(string *)&local_20);
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::_M_dispose();
    }
    lVar6 = std::__cxx11::string::find((char *)asStack_c0,0x3da453);
    local_1e = uVar10;
    local_1c = uVar9;
    uStack_1b = uVar8;
    local_1a = uVar7;
    uStack_19 = uVar1;
    local_18 = uVar2;
    if (lVar6 == -1) {
      lVar6 = std::__cxx11::string::find((char *)asStack_c0,0x3db058);
      if (lVar6 == -1) {
        lVar6 = std::__cxx11::string::find((char *)asStack_c0,0x3de08c);
        if ((lVar6 != -1) &&
           (cVar3 = FUN_00350d38(asStack_c0,&local_80,auStack_a0,0), cVar3 != '\0')) {
          FUN_0034deac((string *)&local_40,&local_80,0);
          iVar4 = atoi(local_40);
          FUN_00350698(&local_80);
          FUN_002bea8c((string *)&local_20);
          std::__cxx11::string::operator=(asStack_c0,(string *)&local_20);
          std::__cxx11::string::_M_dispose();
          FUN_00350d38(asStack_c0,&local_80,auStack_a0,0);
          local_38 = 0;
          *local_40 = '\0';
          FUN_0034deac((string *)&local_20,&local_80,0);
          std::__cxx11::string::append((string *)&local_40);
          std::__cxx11::string::_M_dispose();
          iVar5 = atoi(local_40);
          local_20 = -((short)iVar5 + (short)iVar4 * 0x3c);
          goto LAB_00351a00;
        }
      }
      else {
        cVar3 = FUN_00350d38(asStack_c0,&local_80,auStack_a0,0);
        if (cVar3 != '\0') {
          FUN_0034deac((string *)&local_40,&local_80,0);
          iVar4 = atoi(local_40);
          FUN_00350698(&local_80);
          FUN_002bea8c((string *)&local_20);
          std::__cxx11::string::operator=(asStack_c0,(string *)&local_20);
          std::__cxx11::string::_M_dispose();
          FUN_00350d38(asStack_c0,&local_80,auStack_a0,0);
          local_38 = 0;
          *local_40 = '\0';
          FUN_0034deac((string *)&local_20,&local_80,0);
          std::__cxx11::string::append((string *)&local_40);
          std::__cxx11::string::_M_dispose();
          iVar5 = atoi(local_40);
          local_20 = (short)iVar5 + (short)iVar4 * 0x3c;
LAB_00351a00:
          std::__cxx11::string::_M_dispose();
          goto LAB_00351618;
        }
      }
    }
    local_20 = 0;
  }
LAB_00351618:
  FUN_0034de2c(auStack_60);
  FUN_002beb94(&local_80);
  FUN_0034de2c(auStack_a0);
LAB_0035155c:
  std::__cxx11::string::_M_dispose();
  auVar11._2_2_ = local_1e;
  auVar11._0_2_ = local_20;
  auVar11[4] = local_1c;
  auVar11[5] = uStack_1b;
  auVar11[6] = local_1a;
  auVar11[7] = uStack_19;
  auVar11[8] = local_18;
  auVar11[9] = uStack_17;
  auVar11._10_6_ = 0;
  return auVar11;
}

