// mpr::UMID::GetBasicUMID
// Ghidra address: 003ccca4

/* mpr::UMID::GetBasicUMID(unsigned char*, unsigned int) */

undefined8 __thiscall mpr::UMID::GetBasicUMID(UMID *this,uchar *param_1,uint param_2)

{
  undefined8 uVar1;
  
  if (0x1f < param_2) {
    uVar1 = *(undefined8 *)(this + 8);
    *(undefined8 *)param_1 = *(undefined8 *)this;
    *(undefined8 *)(param_1 + 8) = uVar1;
    uVar1 = *(undefined8 *)(this + 0x18);
    *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(this + 0x10);
    *(undefined8 *)(param_1 + 0x18) = uVar1;
    return 0;
  }
  return 3;
}

