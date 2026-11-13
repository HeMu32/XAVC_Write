// ELF VMA 0x3594e18; Ghidra bias 0x100000

undefined4 appfw_3594e18(long param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uStack_13c70;
  undefined4 uStack_13c68;
  undefined4 uStack_13c60;
  undefined4 uStack_13c5c;
  undefined8 uStack_a020;
  undefined1 auStack_a018 [40000];
  undefined4 uStack_3d8;
  undefined4 uStack_3d4;
  undefined1 uStack_8;
  
  uStack_a020 = 0;
  uStack_13c70 = 0;
  uStack_13c68 = 0;
  func_0x036a9c4c(&uStack_13c60,&uStack_a020);
  uVar2 = uStack_a020._4_4_;
  if ((int)uStack_a020 != 0) {
    uVar2 = 0x39;
    func_0x0374badc(&UNK_04cf7342,0x2cf,&UNK_04cf73f0);
  }
  func_0x01815020(&uStack_13c60,0,40000);
  puVar1 = (undefined4 *)(param_1 + 0x28);
  if (*(int *)(param_1 + 0x34) != 0) {
    puVar1 = (undefined4 *)(param_1 + 0x2c);
  }
  uVar3 = *puVar1;
  func_0x01815020(&uStack_a020,0,0xa020);
  uStack_a020 = CONCAT44(0x1e,*(undefined4 *)(param_1 + 0x30));
  uStack_13c60 = uVar3;
  uStack_13c5c = uVar2;
  func_0x018151a0(auStack_a018,&uStack_13c60,40000);
  uStack_3d8 = param_2;
  uStack_3d4 = uVar2;
  uStack_8 = func_0x02fe59c8(0x1bd4);
  func_0x036a964c(&uStack_a020,&uStack_13c70);
  uVar3 = 0xffffffff;
  if (uStack_13c70._4_4_ != 0) {
    uStack_a020 = CONCAT44(uStack_13c70._4_4_ + -1,(int)uStack_13c70);
    func_0x036a978c(&uStack_a020,&uStack_13c60);
    uVar3 = uStack_13c60;
  }
  func_0x03255f2c(uVar2);
  return uVar3;
}

