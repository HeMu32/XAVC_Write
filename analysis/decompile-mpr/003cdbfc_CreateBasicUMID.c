// mpr::UMID::CreateBasicUMID
// Ghidra address: 003cdbfc

/* mpr::UMID::CreateBasicUMID(mpr::UMID::_MATERIAL_NO_GEN_METHOD, mpr::StillType, mpr::StillType,
   mpr::UMID::UmidCreateMode) */

undefined8 __thiscall
mpr::UMID::CreateBasicUMID(UMID *this,undefined4 param_2,int param_3,int param_4,int param_5)

{
  code *pcVar1;
  UMID UVar2;
  UMID *pUVar3;
  UMID *pUVar4;
  
  SetUniversalLabel(this,*(undefined4 *)(this + 0x1c4),param_2,*(undefined4 *)(this + 0x1cc));
  if (param_4 == 0) {
    switch(param_3) {
    case 1:
      pUVar4 = this + 0xc0;
      break;
    case 2:
      pUVar4 = this + 0x140;
      break;
    default:
switchD_003cdc58_caseD_3:
      uRam000000000000000c = 0;
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(1000,0x3cdea0);
      (*pcVar1)();
    case 4:
      pUVar4 = this + 0x100;
      break;
    case 8:
      pUVar4 = this + 0x160;
    }
    pUVar4[0xc] = (UMID)0x13;
    CreateInstanceNumber(this,*(undefined4 *)(this + 0x1cc),param_3,0,0,pUVar4 + 0xd);
    CreateMaterialNumber(this,param_2,pUVar4 + 0x10);
    return 0;
  }
  if (param_3 == 0) {
    return 0;
  }
  if (param_3 == 2) {
    switch(param_4) {
    case 1:
      pUVar4 = this + 0xc0;
      break;
    case 2:
      pUVar4 = this + 0x140;
      break;
    default:
      this[0x14c] = (UMID)0x13;
      goto switchD_003cdc58_caseD_3;
    case 4:
      pUVar4 = this + 0x100;
      break;
    case 8:
      pUVar4 = this + 0x160;
    }
    this[0x14c] = (UMID)0x13;
    pUVar4[0xc] = (UMID)0x13;
    CreateInstanceNumber(this,*(undefined4 *)(this + 0x1cc),2,0,0,this + 0x14d);
    if (param_4 != 2) {
      CreateInstanceNumber(this,*(undefined4 *)(this + 0x1cc),0,2,0,pUVar4 + 0xd);
    }
    CreateMaterialNumber(this,param_2,this + 0x150);
    CreateMaterialNumber(this,param_2,pUVar4 + 0x10);
    pUVar4[0x17] = this[0x157];
    return 0;
  }
  if (param_3 == 4) {
    pUVar4 = this + 0x100;
    if (param_5 != 1 || param_4 != 4) goto LAB_003cdde4;
    this[300] = (UMID)0x13;
    CreateInstanceNumber(this,*(undefined4 *)(this + 0x1cc),0,4,0,this + 0x12d);
    pUVar3 = this + 0x130;
  }
  else {
    if (param_3 == 8) {
      pUVar4 = this + 0x160;
      goto LAB_003cdde4;
    }
    if (param_3 != 1) goto switchD_003cdc58_caseD_3;
    pUVar4 = this + 0xc0;
    if (param_5 != 1 || param_4 != 1) goto LAB_003cdde4;
    this[0xec] = (UMID)0x13;
    CreateInstanceNumber(this,*(undefined4 *)(this + 0x1cc),0,1,0,this + 0xed);
    pUVar3 = this + 0xf0;
  }
  CreateMaterialNumber(this,param_2,pUVar3);
LAB_003cdde4:
  pUVar4[0xc] = (UMID)0x13;
  CreateInstanceNumber(this,*(undefined4 *)(this + 0x1cc),param_3,0,0,pUVar4 + 0xd);
  CreateMaterialNumber(this,param_2,pUVar4 + 0x10);
  if (param_5 == 1 && param_4 == param_3) {
    if (param_3 == 1) {
      UVar2 = this[0xf7];
    }
    else {
      if (param_3 != 4) {
        return 0;
      }
      UVar2 = this[0x137];
    }
    pUVar4[0x17] = UVar2;
  }
  return 0;
}

