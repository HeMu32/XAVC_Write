// mpr::UMID::CreateBasicUMID
// Ghidra address: 003cdba8

/* mpr::UMID::CreateBasicUMID(mpr::UMID::_MATERIAL_NO_GEN_METHOD) */

undefined8 __thiscall mpr::UMID::CreateBasicUMID(UMID *this,undefined4 param_2)

{
  SetUniversalLabel(this,*(undefined4 *)(this + 0x1c0),param_2,*(undefined4 *)(this + 0x1cc));
  *(undefined2 *)(this + 0xd) = 0;
  this[0xf] = (UMID)0x0;
  this[0xc] = (UMID)0x13;
  CreateMaterialNumber(this,param_2,this + 0x10);
  return 0;
}

