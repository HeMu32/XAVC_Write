// ELF VMA 0x3611020; Ghidra bias 0x100000

void appfw_3611020(undefined4 *param_1,long param_2)

{
  undefined4 uVar1;
  undefined1 uVar2;
  undefined8 uStack_20;
  undefined8 uStack_18;
  undefined8 uStack_10;
  undefined4 uStack_8;
  
  uVar2 = 1;
  if ((uint)param_1[5] < 5) {
    uVar2 = (&UNK_04d1d378)[(uint)param_1[5]];
  }
  if (param_1[8] == 1) {
    uVar2 = 5;
  }
  uStack_20 = 0x8b9a1b8;
  func_0x0193b6d4();
  uStack_8 = 0;
  uStack_10 = 0;
  uStack_18 = *(undefined8 *)(param_1 + 1);
  func_0x01817290(*param_1,&uStack_18,uVar2,*(undefined1 *)(param_1 + 7),
                  *(undefined1 *)(param_1 + 9),0,0x8b9a180);
  uVar1 = func_0x03704954();
  *(undefined4 *)(param_2 + 0x30) = uVar1;
  uVar1 = func_0x03709708(0x8b9a180);
  *(undefined4 *)(param_2 + 8) = uVar1;
  *(undefined4 *)(param_2 + 0x2c) = 0;
  func_0x0193b730(&uStack_20);
  return;
}

