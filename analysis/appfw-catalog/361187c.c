// ELF VMA 0x361187c; Ghidra bias 0x100000

void appfw_361187c(undefined4 *param_1,long param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uStack_8;
  
  switch(param_1[1]) {
  case 1:
    uVar2 = 1;
    break;
  case 2:
    uVar2 = 5;
    break;
  case 3:
    uVar2 = 6;
    break;
  case 4:
    uVar2 = 7;
    break;
  default:
    func_0x0374badc(&UNK_04d1dc96,0x43c8,&UNK_04d20320);
  case 0:
    uVar2 = 0;
  }
  uStack_8 = 0x8b9a1b8;
  func_0x0193b6d4();
  func_0x018169f0(*param_1,uVar2,*(undefined1 *)(param_1 + 2),*(undefined1 *)((long)param_1 + 9),
                  0x8b9af68);
  uRam0000000008b9ae70 = 0x8b9af68;
  uVar1 = func_0x03704954();
  *(undefined4 *)(param_2 + 0x30) = uVar1;
  uVar1 = func_0x03709708(uRam0000000008b9ae70);
  *(undefined4 *)(param_2 + 8) = uVar1;
  *(undefined4 *)(param_2 + 0x2c) = 0x1a;
  func_0x0193b730(&uStack_8);
  return;
}

