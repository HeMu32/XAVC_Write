// sidb::ConvVideoParamToQualityLevel
// Ghidra address: 0038d924

/* sidb::ConvVideoParamToQualityLevel(sidb::VideoParam&) */

char sidb::ConvVideoParamToQualityLevel(VideoParam *param_1)

{
  ushort uVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  iVar2 = ConvVideoParamToVPC(param_1);
  if (iVar2 != 0xe) {
    uVar1 = *(ushort *)(param_1 + 0x1c);
    if (0xffe < (ushort)(uVar1 - 1)) {
      return -1;
    }
    switch(iVar2) {
    case 0:
    case 2:
    case 9:
    case 0xc:
      switch(*(undefined4 *)(param_1 + 0x18)) {
      case 0:
      case 1:
      case 2:
switchD_0038d978_default:
        return '3';
      case 3:
        return (iVar2 == 0xc) + '3';
      default:
        uVar4 = 0xbec;
        break;
      case 5:
      case 7:
switchD_0038d978_default:
        return '4';
      case 8:
      case 9:
        return '<';
      }
      break;
    case 1:
    case 3:
      switch(*(undefined4 *)(param_1 + 0x18)) {
      case 5:
      case 7:
switchD_0038d978_default:
        return '*';
      default:
        if (uVar1 < 0x33) {
          uVar3 = 1L << ((ulong)uVar1 & 0x3f);
          if ((uVar3 & 0x4010002200000) != 0) {
            return ')';
          }
          if ((uVar3 & 0x11000) != 0) {
            return '(';
          }
        }
        uVar4 = 0xc04;
        break;
      case 8:
      case 9:
        goto switchD_0038d978_default;
      }
      break;
    case 4:
      if (uVar1 == 200) {
        return '<';
      }
      uVar4 = 0xc21;
      if (uVar1 == 400) {
        return '=';
      }
      break;
    case 5:
    case 7:
      switch(*(undefined4 *)(param_1 + 0x18)) {
      case 0:
      case 2:
      case 3:
switchD_0038d978_default:
        return '2';
      default:
        uVar4 = 0xc30;
        break;
      case 5:
      case 7:
        goto switchD_0038d978_default;
      case 8:
      case 9:
        goto switchD_0038d978_default;
      }
      break;
    case 6:
    case 8:
      if (uVar1 == 9) {
        return (3 < *(uint *)(param_1 + 0x18)) + '(';
      }
      if (uVar1 == 0x10) {
        return ')';
      }
      uVar4 = 0xc45;
      break;
    case 10:
      switch(*(undefined4 *)(param_1 + 0x18)) {
      case 0:
      case 2:
      case 3:
        return ')';
      default:
        uVar4 = 0xc13;
        break;
      case 5:
        goto switchD_0038d978_default;
      case 7:
        goto switchD_0038d978_default;
      }
      break;
    case 0xb:
      return '(';
    case 0xd:
      if (uVar1 == 0x104) {
        return '<';
      }
      uVar4 = 0xc4e;
      if (uVar1 == 0x208) {
        return '=';
      }
      break;
    default:
      goto switchD_0038d978_default;
    }
    printf("[%s][%d] Conv ERROR!\n","ConvVideoParamToQualityLevel",uVar4);
  }
switchD_0038d978_default:
  return -1;
}

