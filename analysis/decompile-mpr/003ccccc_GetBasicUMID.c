// mpr::UMID::GetBasicUMID
// Ghidra address: 003ccccc

/* mpr::UMID::GetBasicUMID(mpr::UMID::UmidGetMode) */

UMID * __thiscall mpr::UMID::GetBasicUMID(UMID *this,int param_2)

{
  UMID *pUVar1;
  
  pUVar1 = this;
  if (param_2 != 2) {
    if (param_2 == 3) {
      pUVar1 = this + 0x40;
      this[0x4e] = (UMID)0x0;
      *(undefined8 *)(this + 0x40) = *(undefined8 *)this;
      this[0x4f] = (UMID)0x0;
      *(undefined8 *)(this + 0x45) = *(undefined8 *)(this + 5);
      this[0x4d] = (UMID)0xff;
      *(undefined8 *)(this + 0x50) = *(undefined8 *)(this + 0x10);
      *(undefined8 *)(this + 0x58) = *(undefined8 *)(this + 0x18);
    }
    else {
      pUVar1 = this + 0xc0;
      if (param_2 == 4) {
        *(undefined8 *)(this + 0xc0) = *(undefined8 *)this;
        *(undefined8 *)(this + 0xc5) = *(undefined8 *)(this + 5);
        this[0xce] = (UMID)0x0;
        this[0xcd] = (UMID)0x40;
        this[0xcf] = (UMID)0x0;
        *(undefined8 *)(this + 0xd0) = *(undefined8 *)(this + 0x10);
        *(undefined8 *)(this + 0xd8) = *(undefined8 *)(this + 0x18);
      }
    }
  }
  return pUVar1;
}

