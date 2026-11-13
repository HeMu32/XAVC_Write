// mpr::UMID::CreateBasicUMID
// Ghidra address: 003cdea0

/* mpr::UMID::CreateBasicUMID(unsigned char*, mpr::StillType, mpr::StillImage) */

undefined8 __thiscall
mpr::UMID::CreateBasicUMID(UMID *this,undefined8 param_1,int param_3,int param_4)

{
  code *pcVar1;
  UMID *pUVar2;
  
  SetUniversalLabel(this,*(undefined4 *)(this + 0x1c4),4,*(undefined4 *)(this + 0x1cc));
  if (param_4 == 0) {
    if (param_3 == 2) {
      pUVar2 = this + 0x140;
    }
    else if (param_3 == 4) {
      pUVar2 = this + 0x100;
    }
    else {
      pUVar2 = this + 0xc0;
      if (param_3 != 1) goto LAB_003cdef4;
    }
  }
  else {
    pUVar2 = this + 0x1a0;
    if ((param_4 != 3) && (pUVar2 = this + 0x180, param_4 != 2)) {
LAB_003cdef4:
      uRam000000000000000c = 0;
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(1000,0x3cdf00);
      (*pcVar1)();
    }
  }
  pUVar2[0xc] = (UMID)0x13;
  CreateInstanceNumber
            (this,param_1,*(undefined4 *)(this + 0x1cc),param_3,param_3,param_4,pUVar2 + 0xd);
  CreateMaterialNumber(this,4,pUVar2 + 0x10);
  return 0;
}

