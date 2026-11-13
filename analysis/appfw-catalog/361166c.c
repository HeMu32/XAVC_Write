// ELF VMA 0x361166c; Ghidra bias 0x100000

void appfw_361166c(undefined4 *param_1,long param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uStack_20;
  undefined8 uStack_18;
  undefined8 uStack_10;
  undefined4 uStack_8;
  
  switch(param_1[5]) {
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
    func_0x0374badc(&UNK_04d1dc96,0x4367,&UNK_04d1fcd8);
  case 0:
    uVar2 = 0;
  }
  uStack_20 = 0x8b9a1b8;
  func_0x0193b6d4();
  uStack_8 = 0;
  uStack_10 = 0;
  uStack_18 = *(undefined8 *)(param_1 + 1);
  func_0x01817290(*param_1,&uStack_18,uVar2,*(undefined1 *)(param_1 + 6),
                  *(undefined1 *)((long)param_1 + 0x19),0,0x8b9abd8);
  uRam0000000008b9a228 = 0x8b9abd8;
  uVar1 = func_0x03704954();
  *(undefined4 *)(param_2 + 0x30) = uVar1;
  uVar1 = func_0x03709708(uRam0000000008b9a228);
  *(undefined4 *)(param_2 + 8) = uVar1;
  *(undefined4 *)(param_2 + 0x2c) = 7;
  func_0x0193b730(&uStack_20);
  return;
}

