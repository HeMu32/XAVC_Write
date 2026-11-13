// mpr::UMID::GetBasicUMID
// Ghidra address: 003ccb60

/* mpr::UMID::GetBasicUMID(mpr::StillImage, mpr::StillType, mpr::UMID::UmidGetMode, unsigned char*)
    */

undefined8 __thiscall
mpr::UMID::GetBasicUMID(UMID *this,int param_2,int param_3,int param_4,undefined8 *param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (param_2 == 0) {
    if (param_3 == 2) {
      this = this + 0x140;
    }
    else {
      if (param_3 != 4) {
        if (param_3 != 1) {
          return 0;
        }
        if (param_4 == 0) {
          uVar1 = *(undefined8 *)(this + 200);
          *param_5 = *(undefined8 *)(this + 0xc0);
          param_5[1] = uVar1;
          uVar1 = *(undefined8 *)(this + 0xd0);
          uVar2 = *(undefined8 *)(this + 0xd8);
        }
        else {
          if (param_4 != 1) {
            return 0;
          }
          uVar1 = *(undefined8 *)(this + 0xe8);
          *param_5 = *(undefined8 *)(this + 0xe0);
          param_5[1] = uVar1;
          uVar1 = *(undefined8 *)(this + 0xf0);
          uVar2 = *(undefined8 *)(this + 0xf8);
        }
        goto LAB_003ccb8c;
      }
      if (param_4 == 0) {
        this = this + 0x100;
      }
      else {
        this = this + 0x120;
        if (param_4 != 1) {
          return 0;
        }
      }
    }
  }
  else if (param_2 == 3) {
    this = this + 0x1a0;
  }
  else {
    if (param_2 != 2) {
      return 0;
    }
    this = this + 0x180;
  }
  uVar1 = *(undefined8 *)(this + 8);
  *param_5 = *(undefined8 *)this;
  param_5[1] = uVar1;
  uVar1 = *(undefined8 *)(this + 0x10);
  uVar2 = *(undefined8 *)(this + 0x18);
LAB_003ccb8c:
  param_5[2] = uVar1;
  param_5[3] = uVar2;
  return 0;
}

