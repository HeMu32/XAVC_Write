// mpr::ConvClipFilePathToTakeFilePath
// Ghidra address: 001ae3e8

/* mpr::ConvClipFilePathToTakeFilePath(unsigned int, std::__cxx11::string, std::__cxx11::string&,
   std::__cxx11::string&) */

void mpr::ConvClipFilePathToTakeFilePath
               (undefined4 param_1,string *param_2,string *param_3,string *param_4)

{
  int iVar1;
  long lVar2;
  long lVar3;
  char local_197;
  undefined2 local_196;
  undefined4 local_194;
  undefined1 auStack_190 [32];
  char acStack_170 [32];
  string asStack_150 [64];
  string asStack_110 [32];
  undefined1 auStack_f0 [32];
  string asStack_d0 [32];
  string asStack_b0 [137];
  undefined8 local_27;
  undefined8 uStack_1f;
  undefined8 local_17;
  undefined8 uStack_f;
  undefined1 local_7;
  
  local_196 = 0;
  std::__cxx11::string::string(asStack_b0,param_2);
  FUN_001ae1ac(asStack_b0,&local_196);
  std::__cxx11::string::_M_dispose();
  local_194 = 0xffffffff;
  iVar1 = FUN_0028223c(param_1,local_196,&local_194);
  local_197 = '\0';
  memset(asStack_b0,0,0x89);
  local_27 = 0;
  uStack_1f = 0;
  local_17 = 0;
  uStack_f = 0;
  local_7 = 0;
  if ((iVar1 == 0) && (iVar1 = FUN_00282514(param_1,local_194,&local_197,asStack_b0), iVar1 != 0)) {
    local_197 = '\0';
  }
  *(undefined8 *)(param_3 + 8) = 0;
  **(undefined1 **)param_3 = 0;
  *(undefined8 *)(param_4 + 8) = 0;
  **(undefined1 **)param_4 = 0;
  if (local_197 != '\0') {
    FUN_001aa364(auStack_190,asStack_b0);
    lVar2 = std::__cxx11::string::rfind((char)auStack_190,0x5c);
    lVar3 = std::__cxx11::string::rfind((char *)param_2,0x3d3490);
    if (lVar2 != -1 && lVar3 != -1) {
      std::__cxx11::string::substr((ulong)auStack_190,lVar2 + 1);
      std::__cxx11::string::substr((ulong)param_2,0);
      FUN_001aa364(asStack_d0,"/TAKE/");
      FUN_001ac06c(asStack_150,auStack_f0,asStack_d0);
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::string(asStack_d0,asStack_150);
      std::__cxx11::string::append(asStack_d0);
      std::__cxx11::string::append(param_3);
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::rfind(acStack_170,0x3d351e);
      std::__cxx11::string::substr((ulong)acStack_170,0);
      std::__cxx11::string::string(asStack_110,asStack_150);
      std::__cxx11::string::append(asStack_110);
      FUN_001aa364(auStack_f0,&DAT_003d3523);
      FUN_001ac06c(asStack_d0,asStack_110,auStack_f0);
      std::__cxx11::string::append(param_4);
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::_M_dispose();
      std::__cxx11::string::_M_dispose();
    }
    std::__cxx11::string::_M_dispose();
  }
  return;
}

