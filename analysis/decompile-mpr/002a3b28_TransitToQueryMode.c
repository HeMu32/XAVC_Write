// mpr::RTMetadatSmplDatParser::TransitToQueryMode
// Ghidra address: 002a3b28

/* mpr::RTMetadatSmplDatParser::TransitToQueryMode(unsigned char*) */

void __thiscall
mpr::RTMetadatSmplDatParser::TransitToQueryMode(RTMetadatSmplDatParser *this,uchar *param_1)

{
  int iVar1;
  
  iVar1 = UpdateBasicInfo((uchar *)this,(BasicInfo *)param_1);
  if (iVar1 == 0) {
    *(undefined4 *)this = 1;
  }
  return;
}

