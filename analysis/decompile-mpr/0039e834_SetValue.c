// sidb::recordStructureWithFunc<signed_char>::SetValue
// Ghidra address: 0039e834

/* sidb::recordStructureWithFunc<signed char>::SetValue(sidb::COL_ID, signed char) */

undefined8 __thiscall
sidb::recordStructureWithFunc<signed_char>::SetValue
          (recordStructureWithFunc<signed_char> *this,int param_2,byte param_3)

{
  uint uVar1;
  uint uVar2;
  recordStructureWithFunc<signed_char> rVar3;
  char cVar4;
  
  if (0x58 < param_2 - 2U) {
    return 0x403;
  }
  uVar2 = (uint)(char)param_3;
  uVar1 = (int)uVar2 >> 2;
  switch(param_2) {
  case 2:
    *(uint *)(this + 8) = *(uint *)(this + 8) & 0xff | uVar2 << 8;
    break;
  default:
    return 0x403;
  case 8:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[6] & 0xe0 | (byte)this[6] & 0xf | (uVar2 != 0) << 4);
    goto LAB_0039e87c;
  case 9:
    rVar3 = (recordStructureWithFunc<signed_char>)((byte)this[6] & 0x1f | (byte)((uVar2 & 7) << 5));
    goto LAB_0039e87c;
  case 10:
    this[4] = (recordStructureWithFunc<signed_char>)((byte)this[4] & 0xfe | uVar2 != 0);
    break;
  case 0xb:
    this[7] = (recordStructureWithFunc<signed_char>)
              ((byte)this[7] & 0xf | (byte)((uVar2 & 0xf) << 4));
    break;
  case 0x16:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[6] & 0xfc | (byte)this[6] & 1 | (uVar2 != 0) << 1);
    goto LAB_0039e87c;
  case 0x17:
    rVar3 = (recordStructureWithFunc<signed_char>)((byte)this[6] & 0xfe | uVar2 != 0);
LAB_0039e87c:
    this[6] = rVar3;
    break;
  case 0x18:
    this[0x10] = (recordStructureWithFunc<signed_char>)((byte)this[0x10] & 0xfe | param_3 & 1);
    break;
  case 0x1b:
  case 0x2b:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x5c] & 0x3f | (byte)((uVar2 & 3) << 6));
    goto LAB_0039e9c0;
  case 0x1c:
    cVar4 = IsJpegExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
    goto LAB_0039e924;
  case 0x1d:
    cVar4 = IsJpegExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
    goto LAB_0039e958;
  case 0x1e:
    cVar4 = IsHeifExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
LAB_0039e924:
    this[0x5b] = (recordStructureWithFunc<signed_char>)((byte)this[0x5b] & 0xfc | param_3 & 3);
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x6e] & 0x80 | (byte)this[0x6e] & 0x3f | (byte)((uVar1 & 1) << 6));
    goto LAB_0039e93c;
  case 0x1f:
    cVar4 = IsHeifExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
LAB_0039e958:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x5b] & 0xf0 | (byte)this[0x5b] & 3 | (byte)((uVar2 & 3) << 2));
LAB_0039e960:
    this[0x5b] = rVar3;
    break;
  case 0x20:
    this[0x5b] = (recordStructureWithFunc<signed_char>)
                 ((byte)this[0x5b] & 0xc0 | (byte)this[0x5b] & 0xf | (byte)((uVar2 & 3) << 4));
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x6e] & 0x7f | (byte)((uVar1 & 1) << 7));
    goto LAB_0039e93c;
  case 0x21:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x5b] & 0x3f | (byte)((uVar2 & 3) << 6));
    goto LAB_0039e960;
  case 0x22:
    rVar3 = (recordStructureWithFunc<signed_char>)((byte)this[0x5c] & 0xfc | param_3 & 3);
    goto LAB_0039e9c0;
  case 0x23:
    this[0x6b] = (recordStructureWithFunc<signed_char>)((byte)this[0x6b] & 0xfc | param_3 & 3);
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x84] & 0xe0 | (byte)this[0x84] & 0xf | (byte)((uVar1 & 1) << 4));
    goto LAB_0039e9e0;
  case 0x24:
    this[0x6b] = (recordStructureWithFunc<signed_char>)
                 ((byte)this[0x6b] & 0xf0 | (byte)this[0x6b] & 3 | (byte)((uVar2 & 3) << 2));
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x84] & 0xc0 | (byte)this[0x84] & 0x1f | (byte)((uVar1 & 1) << 5));
LAB_0039e9e0:
    this[0x84] = rVar3;
    break;
  case 0x25:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x6b] & 0xc0 | (byte)this[0x6b] & 0xf | (byte)((uVar2 & 3) << 4));
    goto LAB_0039ea0c;
  case 0x26:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x6b] & 0x3f | (byte)((uVar2 & 3) << 6));
LAB_0039ea0c:
    this[0x6b] = rVar3;
    break;
  case 0x27:
    cVar4 = IsJpegExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
    goto LAB_0039ea34;
  case 0x28:
    cVar4 = IsJpegExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
    goto LAB_0039ea54;
  case 0x29:
    cVar4 = IsHeifExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
LAB_0039ea34:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x5c] & 0xf0 | (byte)this[0x5c] & 3 | (byte)((uVar2 & 3) << 2));
    goto LAB_0039e9c0;
  case 0x2a:
    cVar4 = IsHeifExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
LAB_0039ea54:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x5c] & 0xc0 | (byte)this[0x5c] & 0xf | (byte)((uVar2 & 3) << 4));
LAB_0039e9c0:
    this[0x5c] = rVar3;
    break;
  case 0x2c:
    rVar3 = (recordStructureWithFunc<signed_char>)((byte)this[0x5d] & 0xfc | param_3 & 3);
    goto LAB_0039ea90;
  case 0x2d:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x5d] & 0xf0 | (byte)this[0x5d] & 3 | (byte)((uVar2 & 3) << 2));
    goto LAB_0039ea90;
  case 0x2e:
    rVar3 = (recordStructureWithFunc<signed_char>)((byte)this[0x6c] & 0xfc | param_3 & 3);
    goto LAB_0039eaac;
  case 0x2f:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x6c] & 0xf0 | (byte)this[0x6c] & 3 | (byte)((uVar2 & 3) << 2));
    goto LAB_0039eaac;
  case 0x30:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x6c] & 0xc0 | (byte)this[0x6c] & 0xf | (byte)((uVar2 & 3) << 4));
    goto LAB_0039eaac;
  case 0x31:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x6c] & 0x3f | (byte)((uVar2 & 3) << 6));
LAB_0039eaac:
    this[0x6c] = rVar3;
    break;
  case 0x32:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x6f] & 0xf0 | (byte)this[0x6f] & 3 | (byte)((uVar2 & 3) << 2));
    goto LAB_0039eae0;
  case 0x33:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x6f] & 0xc0 | (byte)this[0x6f] & 0xf | (byte)((uVar2 & 3) << 4));
    goto LAB_0039eae0;
  case 0x34:
    cVar4 = IsJpegExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
    goto LAB_0039eb08;
  case 0x35:
    cVar4 = IsJpegExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
    goto LAB_0039eb28;
  case 0x36:
    cVar4 = IsHeifExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
LAB_0039eb08:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x5d] & 0xc0 | (byte)this[0x5d] & 0xf | (byte)((uVar2 & 3) << 4));
    goto LAB_0039ea90;
  case 0x37:
    cVar4 = IsHeifExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
LAB_0039eb28:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x5d] & 0x3f | (byte)((uVar2 & 3) << 6));
LAB_0039ea90:
    this[0x5d] = rVar3;
    break;
  case 0x38:
    rVar3 = (recordStructureWithFunc<signed_char>)((byte)this[0x5e] & 0xfc | param_3 & 3);
    goto LAB_0039eb64;
  case 0x39:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x5e] & 0xf0 | (byte)this[0x5e] & 3 | (byte)((uVar2 & 3) << 2));
    goto LAB_0039eb64;
  case 0x3a:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x5e] & 0xc0 | (byte)this[0x5e] & 0xf | (byte)((uVar2 & 3) << 4));
    goto LAB_0039eb64;
  case 0x3b:
    rVar3 = (recordStructureWithFunc<signed_char>)((byte)this[0x6d] & 0xfc | param_3 & 3);
    goto LAB_0039eb8c;
  case 0x3c:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x6d] & 0xf0 | (byte)this[0x6d] & 3 | (byte)((uVar2 & 3) << 2));
    goto LAB_0039eb8c;
  case 0x3d:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x6d] & 0xc0 | (byte)this[0x6d] & 0xf | (byte)((uVar2 & 3) << 4));
    goto LAB_0039eb8c;
  case 0x3e:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x6d] & 0x3f | (byte)((uVar2 & 3) << 6));
LAB_0039eb8c:
    this[0x6d] = rVar3;
    break;
  case 0x3f:
    rVar3 = (recordStructureWithFunc<signed_char>)((byte)this[0x6e] & 0xfe | uVar2 != 0);
    goto LAB_0039e93c;
  case 0x40:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x6e] & 0xfc | (byte)this[0x6e] & 1 | (uVar2 != 0) << 1);
    goto LAB_0039e93c;
  case 0x41:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x6e] & 0xf8 | (byte)this[0x6e] & 3 | (uVar2 != 0) << 2);
    goto LAB_0039e93c;
  case 0x42:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x6e] & 0xf0 | (byte)this[0x6e] & 7 | (uVar2 != 0) << 3);
    goto LAB_0039e93c;
  case 0x43:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x6e] & 0xe0 | (byte)this[0x6e] & 0xf | (uVar2 != 0) << 4);
    goto LAB_0039e93c;
  case 0x44:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x6e] & 0xc0 | (byte)this[0x6e] & 0x1f | (uVar2 != 0) << 5);
    goto LAB_0039e93c;
  case 0x45:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x6e] & 0x80 | (byte)this[0x6e] & 0x3f | (uVar2 != 0) << 6);
    goto LAB_0039e93c;
  case 0x46:
    rVar3 = (recordStructureWithFunc<signed_char>)((byte)this[0x6e] & 0x7f | (uVar2 != 0) << 7);
LAB_0039e93c:
    this[0x6e] = rVar3;
    break;
  case 0x47:
    rVar3 = (recordStructureWithFunc<signed_char>)((byte)this[0x6f] & 0xfe | uVar2 != 0);
    goto LAB_0039eae0;
  case 0x48:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x6f] & 0xfc | (byte)this[0x6f] & 1 | (uVar2 != 0) << 1);
    goto LAB_0039eae0;
  case 0x49:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x6f] & 0x80 | (byte)this[0x6f] & 0x3f | (uVar2 != 0) << 6);
LAB_0039eae0:
    this[0x6f] = rVar3;
    break;
  case 0x4c:
    cVar4 = IsJpegExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
    goto LAB_0039ecb4;
  case 0x50:
    cVar4 = IsHeifExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
LAB_0039ecb4:
    *(uint *)(this + 0x60) = uVar2;
    break;
  case 0x54:
    *(uint *)(this + 100) = uVar2;
    break;
  case 0x56:
    *(uint *)(this + 0x70) = uVar2;
    break;
  case 0x57:
    *(uint *)(this + 0x70) = -(uVar2 >> 7 & 1);
    *(uint *)(this + 0x74) = uVar2;
    break;
  case 0x58:
    *(uint *)(this + 0x7c) = -(uVar2 >> 7 & 1);
    *(uint *)(this + 0x80) = uVar2;
    break;
  case 0x59:
    rVar3 = (recordStructureWithFunc<signed_char>)
            ((byte)this[0x5e] & 0x80 | (byte)this[0x5e] & 0x3f | (uVar2 != 0) << 6);
    goto LAB_0039eb64;
  case 0x5a:
    rVar3 = (recordStructureWithFunc<signed_char>)((byte)this[0x5e] & 0x7f | (uVar2 != 0) << 7);
LAB_0039eb64:
    this[0x5e] = rVar3;
  }
  return 0;
}

