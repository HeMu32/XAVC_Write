// XavcsMovieReader::ConvertLibSizeAndFrameRateToMprStreamProperty
// Ghidra address: 0020ccec

/* XavcsMovieReader::ConvertLibSizeAndFrameRateToMprStreamProperty(unsigned int, unsigned int,
   libXavcMp4::VideoFrameRate, mpr::ScanMode) */

char __thiscall
XavcsMovieReader::ConvertLibSizeAndFrameRateToMprStreamProperty
          (undefined8 param_1_00,uint param_1,int param_2,uint param_4,int param_5)

{
  char cVar1;
  
  if (param_1 == 0x5a0) {
    if (param_4 == 0x1df853) {
      return '8';
    }
    if (0x1df853 < param_4) {
      if ((param_4 != 0x320000) && (param_4 != 0x3bf0a6)) {
        return '\0';
      }
      return '6';
    }
    if (param_4 == 0x17f9dc) {
      return '7';
    }
    if (param_4 != 0x190000) {
      return '\0';
    }
    return '8';
  }
  if (param_1 < 0x5a1) {
    if (param_1 == 0x2d0) {
      if ((param_4 != 0x320000) && (param_4 != 0x3bf0a6)) {
        return '\0';
      }
      cVar1 = '3';
      if (param_2 == 0x1e0) {
        cVar1 = '\x01';
      }
      return cVar1;
    }
    if (param_1 < 0x2d1) {
      if (param_1 == 0x1e0) {
        if (param_4 == 0x190000) {
          return '1';
        }
        if (0x190000 < param_4) {
          if ((param_4 != 0x320000) && (param_4 != 0x3bf0a6)) {
            if (param_4 != 0x1df853) {
              return '\0';
            }
            return '1';
          }
          return '2';
        }
        if (param_4 == 0x17f9dc) {
          return '/';
        }
        cVar1 = '0';
      }
      else {
        if (param_1 != 0x280) {
          return '\0';
        }
        if (param_2 == 0x1e0) {
          if (param_4 == 0x1df853) {
            return '\x1a';
          }
          if (param_4 < 0x1df854) {
            if (param_4 != 0x190000) {
              return '\0';
            }
            return '\x1a';
          }
          if ((param_4 != 0x320000) && (param_4 != 0x3bf0a6)) {
            return '\0';
          }
          return '\x19';
        }
        if (param_4 == 0x190000) {
          return '-';
        }
        if (0x190000 < param_4) {
          if ((param_4 != 0x320000) && (param_4 != 0x3bf0a6)) {
            if (param_4 != 0x1df853) {
              return '\0';
            }
            return '-';
          }
          return '.';
        }
        if (param_4 == 0x17f9dc) {
          return '+';
        }
        cVar1 = ',';
      }
LAB_0020cd8c:
      if (param_4 != 0x180000) {
        return '\0';
      }
      return cVar1;
    }
    if (param_1 == 800) {
      if ((param_4 != 0xc80000) && (param_4 != 0xefc29f)) {
        return '\0';
      }
      return '\x1f';
    }
    if (param_1 != 0x500) {
      return '\0';
    }
    if (param_4 == 0x320000) {
      return '\x12';
    }
    if (0x320000 < param_4) {
      if (param_4 == 0x77e14f) {
        return '\x1e';
      }
      if (0x77e14f < param_4) {
        if ((param_4 != 0xc80000) && (param_4 != 0xefc29f)) {
          return '\0';
        }
        return '\"';
      }
      if (param_4 == 0x3bf0a6) {
        return '\x12';
      }
      if (param_4 != 0x640000) {
        return '\0';
      }
      return '\x1e';
    }
    if (param_4 == 0x180000) {
      return '4';
    }
    if (0x180000 < param_4) {
      if ((param_4 != 0x190000) && (param_4 != 0x1df853)) {
        return '\0';
      }
      return '\x18';
    }
    cVar1 = '\x11';
  }
  else if (param_1 == 0xf00) {
    if (param_4 == 0x320000) {
      return '\x1d';
    }
    if (0x320000 < param_4) {
      if ((param_4 != 0x640000) && (param_4 != 0x77e14f)) {
        if (param_4 != 0x3bf0a6) {
          return '\0';
        }
        return '\x1d';
      }
      return '9';
    }
    if ((param_4 == 0x190000) || (param_4 == 0x1df853)) {
      return '\x1c';
    }
    cVar1 = '\x1b';
  }
  else if (param_1 < 0xf01) {
    if (param_1 != 0x780) {
      if (param_1 != 0x800) {
        return '\0';
      }
      if (param_4 == 0x190000) {
        return '%';
      }
      if (0x190000 < param_4) {
        if ((param_4 != 0x320000) && (param_4 != 0x3bf0a6)) {
          if (param_4 != 0x1df853) {
            return '\0';
          }
          return '%';
        }
        return '&';
      }
      if (param_4 == 0x17f9dc) {
        return '#';
      }
      cVar1 = '$';
      goto LAB_0020cd8c;
    }
    if (param_4 == 0x1df853) {
      return '\x17';
    }
    if (0x1df853 < param_4) {
      if (param_4 != 0x3bf0a6) {
        if (0x3bf0a6 < param_4) {
          if ((param_4 != 0x640000) && (param_4 != 0x77e14f)) {
            return '\0';
          }
          return ' ';
        }
        if (param_4 != 0x320000) {
          return '\0';
        }
      }
      if (param_5 != 0) {
        return (param_5 == 1) + '\x15';
      }
      return '\x13';
    }
    if (param_4 == 0x180000) {
      return '5';
    }
    cVar1 = '\x14';
    if (param_4 == 0x190000) {
      return '\x17';
    }
  }
  else {
    if (param_1 != 0x1000) {
      if (param_1 != 0x1e00) {
        return '\0';
      }
      if ((param_4 != 0x190000) && (param_4 != 0x1df853)) {
        cVar1 = '<';
        if (param_4 != 0x17f9dc) {
          cVar1 = '\0';
        }
        return cVar1;
      }
      return ';';
    }
    if (param_4 == 0x1df853) {
      return ')';
    }
    if (0x1df853 < param_4) {
      if (param_4 == 0x3bf0a6) {
        return '*';
      }
      if (param_4 < 0x3bf0a7) {
        if (param_4 != 0x320000) {
          return '\0';
        }
        return '*';
      }
      if ((param_4 != 0x640000) && (param_4 != 0x77e14f)) {
        return '\0';
      }
      return ':';
    }
    if (param_4 == 0x180000) {
      return '(';
    }
    cVar1 = '\'';
    if (param_4 == 0x190000) {
      return ')';
    }
  }
  if (param_4 != 0x17f9dc) {
    return '\0';
  }
  return cVar1;
}

