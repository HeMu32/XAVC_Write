// mpr::UMID::SetTimeInfo
// Ghidra address: 003ccc88

/* mpr::UMID::SetTimeInfo(DefStruct::LocalTime const*) */

undefined8 __thiscall mpr::UMID::SetTimeInfo(UMID *this,LocalTime *param_1)

{
  *(undefined8 *)(this + 0x1dc) = *(undefined8 *)param_1;
  *(undefined4 *)(this + 0x1e4) = *(undefined4 *)(param_1 + 8);
  return 0;
}

