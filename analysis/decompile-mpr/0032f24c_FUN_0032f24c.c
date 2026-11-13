// FUN_0032f24c
// Ghidra address: 0032f24c

undefined8 FUN_0032f24c(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  undefined1 local_1c1;
  undefined8 local_1c0;
  uint local_1b8;
  undefined1 *local_1a0;
  undefined8 uStack_198;
  undefined1 local_190 [16];
  string asStack_180 [16];
  string asStack_170 [368];
  
  if (param_2 == 0) {
    return 2;
  }
  uVar4 = 5;
  if (*(long *)(param_1 + 0x10) != 0) {
    lVar2 = FUN_0032ca5c(param_1,*(long *)(param_1 + 0x10),6,0);
    if ((lVar2 == 0) || (lVar3 = FUN_0032c960(param_1,lVar2,6), lVar3 == 0)) {
      uVar4 = 1;
    }
    else {
      FUN_00337e2c(&local_1c0);
      uVar5 = 0;
      while (((uint)uVar5 < local_1b8 && (uVar5 != 0x10))) {
        local_1c1 = 0;
        local_190[0] = 0;
        uStack_198 = 0;
        local_1a0 = local_190;
        std::__cxx11::string::substr((ulong)&local_1c0,uVar5);
        std::__cxx11::string::assign((string *)&local_1a0);
        std::__cxx11::string::_M_dispose();
        std::__cxx11::string::string(asStack_180,(string *)&local_1a0);
        iVar1 = FUN_00349a20(asStack_180,&local_1c1);
        std::__cxx11::string::_M_dispose();
        if (iVar1 != 0) {
          std::__cxx11::string::_M_dispose();
          std::__cxx11::string::_M_dispose();
          return 5;
        }
        *(undefined1 *)(param_2 + (ulong)((uint)uVar5 >> 1)) = local_1c1;
        std::__cxx11::string::_M_dispose();
        uVar5 = uVar5 + 2;
      }
      std::__cxx11::string::_M_dispose();
      *(undefined1 *)(param_2 + 8) = 0;
      lVar3 = FUN_0032c960(param_1,lVar2,7);
      if (lVar3 != 0) {
        *(undefined1 *)(param_2 + 8) = 1;
        FUN_00337e2c(asStack_180);
        std::__cxx11::string::assign((string *)(param_2 + 0x10));
        std::__cxx11::string::_M_dispose();
      }
      *(undefined1 *)(param_2 + 8) = 0;
      lVar2 = FUN_0032c960(param_1,lVar2,8);
      uVar4 = 0;
      if (lVar2 != 0) {
        FUN_00337e2c(&local_1c0);
        std::__cxx11::istringstream::istringstream((istringstream *)asStack_180,8);
        FUN_0032c3e0(&local_1a0,local_1c0);
        std::__cxx11::stringbuf::str(asStack_170);
        std::__cxx11::string::_M_dispose();
        std::istream::operator>>((istream *)asStack_180,(long *)&local_1a0);
        *(int *)(param_2 + 0x34) = (int)local_1a0;
        *(undefined1 *)(param_2 + 0x30) = 1;
        std::__cxx11::istringstream::~istringstream((istringstream *)asStack_180);
        std::__cxx11::string::_M_dispose();
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}

