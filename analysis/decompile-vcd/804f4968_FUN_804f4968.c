// FUN_804f4968
// Ghidra address: 804f4968

void FUN_804f4968(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  DAT_802ec2f4 = param_1 + 0x980;
  DAT_802ec2f8 = param_1 + 0xb40;
  DAT_802ec2f0 = param_1;
  uVar1 = FUN_804e6d84(DAT_802ec2f4);
  iVar2 = FUN_804e6d24(uVar1);
  DAT_802ec2fc = param_1 + iVar2 * 0x300 + 0xcc0;
  return;
}

