// ELF VMA 0x3594ae4; Ghidra bias 0x100000

void appfw_3594ae4(long param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
                  undefined4 *param_5)

{
  undefined4 uVar1;
  undefined4 uStack_b240;
  undefined4 uStack_b23c;
  undefined8 uStack_b238;
  int iStack_b230;
  undefined1 auStack_b228 [2672];
  int iStack_a7b8;
  int iStack_a048;
  undefined4 uStack_a020;
  undefined4 uStack_a01c;
  int iStack_a018;
  undefined4 uStack_3d8;
  undefined4 uStack_3d4;
  undefined1 uStack_8;
  
  func_0x01815020(auStack_b228,0,0x1208);
  uStack_a020 = *(undefined4 *)(param_1 + 0x30);
  uStack_a01c = param_2;
  func_0x036a958c(&uStack_a020,auStack_b228);
  if (iStack_a048 == 0) {
    if (iStack_a7b8 != -1) {
      uStack_b238 = 0;
      iStack_b230 = 0;
      func_0x01815020(&uStack_a020,0,0xa020);
      iStack_a018 = iStack_a7b8;
      uStack_a020 = *(undefined4 *)(param_1 + 0x30);
      uStack_a01c = 5;
      uStack_3d8 = *param_3;
      uStack_3d4 = 0x39;
      uStack_8 = func_0x02fe59c8(0x1bd4);
      func_0x036a964c(&uStack_a020,&uStack_b238);
      if ((iStack_b230 == 0) && (uStack_b238._4_4_ == 1)) {
        uStack_a01c = 0;
        uStack_a020 = (undefined4)uStack_b238;
        func_0x036a978c(&uStack_a020,&uStack_b240);
        uVar1 = *param_3;
        uStack_b23c = uStack_b240;
        *param_5 = uStack_b240;
        uStack_b240 = uVar1;
        func_0x036a974c(&uStack_b240,&uStack_a020);
        *param_4 = uStack_a020;
      }
    }
  }
  else {
    *param_5 = 0xffffffff;
  }
  return;
}

