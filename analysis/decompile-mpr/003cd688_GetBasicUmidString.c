// mpr::UMID::GetBasicUmidString
// Ghidra address: 003cd688

/* mpr::UMID::GetBasicUmidString(char*, unsigned int) */

undefined8 __thiscall mpr::UMID::GetBasicUmidString(UMID *this,char *param_1,uint param_2)

{
  undefined8 uVar1;
  
  if (0x40 < param_2) {
    uVar1 = FUN_003cd59c(param_1,param_2,this,0x20);
    return uVar1;
  }
  return 3;
}

