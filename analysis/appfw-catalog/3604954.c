// ELF VMA 0x3604954; Ghidra bias 0x100000

undefined8 appfw_3604954(int param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    func_0x038258d4(&UNK_04d1ded7,param_1);
    func_0x038258d4(&UNK_04d1dece,&UNK_04c989a0,&UNK_04d23068,0x1d7,param_1);
    switch(param_1) {
    case 0x401:
      uVar1 = 0xce;
      break;
    case 0x402:
      uVar1 = 0xcf;
      break;
    case 0x403:
      uVar1 = 0xd0;
      break;
    case 0x404:
      uVar1 = 0xd1;
      break;
    case 0x405:
      uVar1 = 0xd2;
      break;
    case 0x406:
      uVar1 = 0xd3;
      break;
    case 0x407:
      uVar1 = 0xd4;
      break;
    case 0x408:
      uVar1 = 0xd5;
      break;
    case 0x409:
      uVar1 = 0xd6;
      break;
    default:
      uVar1 = 2;
      break;
    case 0x40b:
      uVar1 = 0xd8;
    }
    return uVar1;
  }
  return 0;
}

