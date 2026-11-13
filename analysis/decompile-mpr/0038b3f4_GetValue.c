// sidb::onMemoryColumnWithFunc<bool>::GetValue
// Ghidra address: 0038b3f4

/* sidb::onMemoryColumnWithFunc<bool>::GetValue(sidb::COL_ID, bool*) */

undefined8 __thiscall
sidb::onMemoryColumnWithFunc<bool>::GetValue
          (onMemoryColumnWithFunc<bool> *this,undefined4 param_2,byte *param_3)

{
  byte bVar1;
  
  if (param_3 == (byte *)0x0) {
switchD_0038b418_caseD_6a:
    return 0x403;
  }
  switch(param_2) {
  case 0x68:
    bVar1 = (byte)*this >> 1 & 1;
    break;
  case 0x69:
    bVar1 = (byte)*this >> 3 & 1;
    break;
  default:
    goto switchD_0038b418_caseD_6a;
  case 0x6b:
    bVar1 = (byte)*this >> 2 & 1;
    break;
  case 0x6c:
    bVar1 = (byte)*this >> 4 & 1;
  }
  *param_3 = bVar1;
  return 0;
}

