// XavcsMovieReader::ConvEmTypeNrtDef2Mpr
// Ghidra address: 00211908

/* XavcsMovieReader::ConvEmTypeNrtDef2Mpr(NRTDEF::MarkType, bool, mpr::EssenceMarkType*) */

void XavcsMovieReader::ConvEmTypeNrtDef2Mpr(undefined4 param_1,char param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_2 == '\0') {
    switch(param_1) {
    case 0:
      *param_3 = 0;
      return;
    case 1:
      uVar1 = 1;
      break;
    case 2:
      uVar1 = 2;
      break;
    case 3:
      uVar1 = 3;
      break;
    case 4:
      uVar1 = 4;
      break;
    case 5:
      uVar1 = 5;
      break;
    case 6:
      uVar1 = 6;
      break;
    case 7:
      uVar1 = 7;
      break;
    case 8:
      uVar1 = 8;
      break;
    case 9:
      uVar1 = 9;
      break;
    case 10:
      uVar1 = 10;
      break;
    case 0xb:
      uVar1 = 0xb;
      break;
    default:
      uVar1 = 0xc;
    }
  }
  else {
    uVar1 = 0xd;
  }
  *param_3 = uVar1;
  return;
}

