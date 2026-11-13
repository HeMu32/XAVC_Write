// ELF VMA 0x3594c44; Ghidra bias 0x100000

void appfw_3594c44(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
                  undefined8 param_5,undefined4 *param_6)

{
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 auStack_10 [2];
  undefined8 uStack_8;
  
  uStack_18 = param_2;
  uStack_14 = param_4;
  func_0x036a974c(&uStack_18,auStack_10);
  *param_6 = auStack_10[0];
  auStack_10[0] = param_2;
  uStack_8 = param_5;
  func_0x036a980c(auStack_10,&uStack_18);
  return;
}

