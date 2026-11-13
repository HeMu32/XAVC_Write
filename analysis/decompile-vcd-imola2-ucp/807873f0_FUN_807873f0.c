// FUN_807873f0
// Ghidra address: 807873f0

undefined4 FUN_807873f0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = 0xf;
  switch(param_1) {
  case 0:
    uVar1 = 0;
    break;
  case 1:
  case 6:
    uVar1 = 1;
    break;
  default:
    uVar2 = 0x8078745c;
    FUN_807a0894(&DAT_807c0254,param_1);
    FUN_80745808(&DAT_807c0250,s_________________________src_ipsx_807afa88,0x6e,uVar2);
    break;
  case 4:
    uVar1 = 4;
  }
  return uVar1;
}

