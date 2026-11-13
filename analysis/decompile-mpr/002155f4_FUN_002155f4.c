// FUN_002155f4
// Ghidra address: 002155f4

undefined4 FUN_002155f4(undefined4 param_1,char *param_2,undefined4 param_3)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  undefined2 local_2a;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined4 local_18;
  
  local_1e = 0x4000;
  local_1c = 4;
  local_1b = 0;
  local_1a = 0;
  local_19 = 0;
  local_20 = 0x2160;
  FUN_0020aff4(&local_20,8);
  local_2a = 0;
  local_28 = 0;
  if ((param_2 == (char *)0x0) || (sVar2 = strnlen(param_2,0x106), sVar2 == 0)) {
    uVar3 = 2;
    local_1b = 0;
    local_1c = 4;
    local_1a = 0;
    local_20 = 0x2160;
    local_19 = 0;
    local_1e = 0x4003;
    FUN_0020aff4(&local_20,8);
  }
  else {
    FUN_0020ae44(&local_20,param_2);
    FUN_002153f4(&local_20,&local_2a);
    std::__cxx11::string::_M_dispose();
    iVar1 = FUN_0028223c(param_1,local_2a,&local_28);
    if (iVar1 == 0) {
      FUN_00212bd4(param_3,&uStack_24);
      iVar1 = FUN_00282724(param_1,local_28,uStack_24);
      uVar3 = 0;
      if (iVar1 == 0) goto LAB_00215698;
      local_1e = 0x4005;
    }
    else {
      local_1e = 0x4004;
    }
    local_19 = 0;
    local_1a = 0;
    local_1b = 0;
    local_1c = 4;
    local_20 = 0x2160;
    uVar3 = 0xb;
    FUN_0020aff4(&local_20,8);
  }
LAB_00215698:
  local_1c = 3;
  local_1b = 0;
  local_20 = 0x2160;
  local_1a = 0;
  local_1e = 0x400f;
  local_19 = 0;
  local_18 = uVar3;
  FUN_0020aff4(&local_20,0xc);
  return uVar3;
}

