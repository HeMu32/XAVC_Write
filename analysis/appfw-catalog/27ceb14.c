// ELF VMA 0x27ceb14; Ghidra bias 0x100000

void appfw_27ceb14(undefined8 param_1,int param_2)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  int iStack_7a4;
  undefined1 uStack_7a0;
  undefined1 uStack_79f;
  undefined1 uStack_79e;
  undefined4 uStack_79c;
  undefined8 uStack_798;
  int *piStack_790;
  long lStack_788;
  undefined4 uStack_780;
  undefined1 uStack_77c;
  undefined1 uStack_77b;
  undefined8 uStack_778;
  
  func_0x02fe71e8(&piStack_790);
  piVar3 = (int *)func_0x029f7f14();
  iVar1 = *piVar3;
  func_0x02fe6ec4(&piStack_790);
  if (iVar1 != param_2) {
    func_0x027089d8(param_1,0);
  }
  func_0x01936e44(&uStack_7a0);
  uVar2 = uStack_798;
  piVar3 = (int *)func_0x029f7f14();
  lStack_788 = func_0x029f7f28();
  uStack_77c = 0;
  uStack_77b = 0;
  uStack_780 = 0x6c7;
  uStack_778 = uVar2;
  iStack_7a4 = param_2;
  piStack_790 = piVar3;
  if (*(long *)(lStack_788 + 8) == 0) {
    func_0x038284b4(uVar2,0x6c7,piVar3,&iStack_7a4,4);
  }
  else {
    func_0x038284b4(uVar2,0x6c7,*(long *)(lStack_788 + 8),&iStack_7a4,4);
    **(int **)(lStack_788 + 8) = param_2;
    uStack_77b = 1;
  }
  *piStack_790 = param_2;
  uStack_77c = 1;
  func_0x01db175c(&piStack_790);
  func_0x01936e68(&uStack_7a0);
  func_0x01936e44(&uStack_7a0);
  func_0x02678f2c(&piStack_790,uStack_798);
  iStack_7a4 = 1;
  func_0x0273d04c(&piStack_790,&iStack_7a4);
  func_0x026c3c70(&piStack_790);
  func_0x01936e68(&uStack_7a0);
  uStack_79f = 1;
  uStack_7a0 = 0;
  uStack_79e = 0;
  uStack_79c = 0;
  func_0x02681d34(&piStack_790,&uStack_7a0);
  appfw_3596604(&piStack_790);
  func_0x028ceb00(&piStack_790);
  return;
}

