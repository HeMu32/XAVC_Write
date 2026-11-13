// mpr::UMID::CreateBasicUMID
// Ghidra address: 003cdb58

/* mpr::UMID::CreateBasicUMID() */

undefined8 __thiscall mpr::UMID::CreateBasicUMID(UMID *this)

{
  SetUniversalLabel(this,*(undefined4 *)(this + 0x1c0),*(undefined4 *)(this + 0x1c8),
                    *(undefined4 *)(this + 0x1cc));
  *(undefined2 *)(this + 0xd) = 0;
  this[0xf] = (UMID)0x0;
  this[0xc] = (UMID)0x13;
  CreateMaterialNumber(this,*(undefined4 *)(this + 0x1c8),this + 0x10);
  return 0;
}

