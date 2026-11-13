// FUN_0028e4e8
// Ghidra address: 0028e4e8

void * FUN_0028e4e8(int param_1,int param_2)

{
  void *pvVar1;
  
  if (param_1 == 1) {
    pvVar1 = operator_new(0xc0698);
    FUN_00296634();
  }
  else {
    pvVar1 = (void *)0x0;
    if (param_1 == 0) {
      if (param_2 == 1) {
        pvVar1 = operator_new(8);
        FUN_0028e4b8();
      }
      else {
        pvVar1 = operator_new(0xc0690);
        FUN_0028eb3c();
      }
    }
  }
  return pvVar1;
}

