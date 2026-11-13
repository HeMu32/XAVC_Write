// FUN_0035148c
// Ghidra address: 0035148c

void FUN_0035148c(undefined4 *param_1,char *param_2,undefined4 param_3)

{
  size_t sVar1;
  locale alStack_8 [8];
  
  sVar1 = strlen(param_2);
  std::locale::locale(alStack_8);
  *param_1 = param_3;
  std::locale::locale((locale *)(param_1 + 2),alStack_8);
  FUN_00351090(param_1 + 4,param_2,param_2 + sVar1,(locale *)(param_1 + 2),*param_1);
  std::locale::~locale(alStack_8);
  return;
}

