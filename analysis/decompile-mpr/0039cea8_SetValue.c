// sidb::recordStructureWithFunc<unsigned_char>::SetValue
// Ghidra address: 0039cea8

/* sidb::recordStructureWithFunc<unsigned char>::SetValue(sidb::COL_ID, unsigned char) */

undefined8 __thiscall
sidb::recordStructureWithFunc<unsigned_char>::SetValue
          (recordStructureWithFunc<unsigned_char> *this,int param_2,byte param_3)

{
  uint uVar1;
  recordStructureWithFunc<unsigned_char> rVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (0x58 < param_2 - 2U) {
    return 0x403;
  }
  uVar4 = (uint)param_3;
  uVar5 = (uint)param_3;
  uVar6 = (uint)param_3;
  uVar1 = (int)uVar6 >> 2;
  switch(param_2) {
  case 2:
    *(uint *)(this + 8) = *(uint *)(this + 8) & 0xff | (uint)param_3 << 8;
    break;
  default:
    return 0x403;
  case 8:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[6] & 0xe0 | (byte)this[6] & 0xf | (uVar6 != 0) << 4);
    goto LAB_0039cef0;
  case 9:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[6] & 0x1f | (byte)((uVar6 & 7) << 5));
    goto LAB_0039cef0;
  case 10:
    this[4] = (recordStructureWithFunc<unsigned_char>)((byte)this[4] & 0xfe | uVar6 != 0);
    break;
  case 0xb:
    this[7] = (recordStructureWithFunc<unsigned_char>)
              ((byte)this[7] & 0xf | (byte)((uVar6 & 0xf) << 4));
    break;
  case 0x16:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[6] & 0xfc | (byte)this[6] & 1 | (uVar6 != 0) << 1);
    goto LAB_0039cef0;
  case 0x17:
    rVar2 = (recordStructureWithFunc<unsigned_char>)((byte)this[6] & 0xfe | uVar6 != 0);
LAB_0039cef0:
    this[6] = rVar2;
    break;
  case 0x18:
    this[0x10] = (recordStructureWithFunc<unsigned_char>)((byte)this[0x10] & 0xfe | param_3 & 1);
    break;
  case 0x1b:
  case 0x2b:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x5c] & 0x3f | (byte)((uVar6 & 3) << 6));
    goto LAB_0039d034;
  case 0x1c:
    cVar3 = IsJpegExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
    goto LAB_0039cf98;
  case 0x1d:
    cVar3 = IsJpegExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
    goto LAB_0039cfcc;
  case 0x1e:
    cVar3 = IsHeifExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
LAB_0039cf98:
    this[0x5b] = (recordStructureWithFunc<unsigned_char>)((byte)this[0x5b] & 0xfc | param_3 & 3);
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x6e] & 0x80 |
            (byte)this[0x6e] & 0x3f | (byte)(((int)(uint)param_3 >> 2 & 1U) << 6));
    goto LAB_0039cfb0;
  case 0x1f:
    cVar3 = IsHeifExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
LAB_0039cfcc:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x5b] & 0xf0 | (byte)this[0x5b] & 3 | (byte)((uVar6 & 3) << 2));
LAB_0039cfd4:
    this[0x5b] = rVar2;
    break;
  case 0x20:
    this[0x5b] = (recordStructureWithFunc<unsigned_char>)
                 ((byte)this[0x5b] & 0xc0 | (byte)this[0x5b] & 0xf | (byte)((uVar6 & 3) << 4));
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x6e] & 0x7f | (byte)((uVar1 & 1) << 7));
    goto LAB_0039cfb0;
  case 0x21:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x5b] & 0x3f | (byte)((uVar6 & 3) << 6));
    goto LAB_0039cfd4;
  case 0x22:
    rVar2 = (recordStructureWithFunc<unsigned_char>)((byte)this[0x5c] & 0xfc | param_3 & 3);
    goto LAB_0039d034;
  case 0x23:
    this[0x6b] = (recordStructureWithFunc<unsigned_char>)((byte)this[0x6b] & 0xfc | param_3 & 3);
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x84] & 0xe0 | (byte)this[0x84] & 0xf | (byte)((uVar1 & 1) << 4));
    goto LAB_0039d054;
  case 0x24:
    this[0x6b] = (recordStructureWithFunc<unsigned_char>)
                 ((byte)this[0x6b] & 0xf0 | (byte)this[0x6b] & 3 | (byte)((uVar6 & 3) << 2));
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x84] & 0xc0 | (byte)this[0x84] & 0x1f | (byte)((uVar1 & 1) << 5));
LAB_0039d054:
    this[0x84] = rVar2;
    break;
  case 0x25:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x6b] & 0xc0 | (byte)this[0x6b] & 0xf | (byte)((uVar6 & 3) << 4));
    goto LAB_0039d080;
  case 0x26:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x6b] & 0x3f | (byte)((uVar6 & 3) << 6));
LAB_0039d080:
    this[0x6b] = rVar2;
    break;
  case 0x27:
    cVar3 = IsJpegExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
    goto LAB_0039d0a8;
  case 0x28:
    cVar3 = IsJpegExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
    goto LAB_0039d0c8;
  case 0x29:
    cVar3 = IsHeifExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
LAB_0039d0a8:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x5c] & 0xf0 | (byte)this[0x5c] & 3 | (byte)((uVar6 & 3) << 2));
    goto LAB_0039d034;
  case 0x2a:
    cVar3 = IsHeifExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
LAB_0039d0c8:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x5c] & 0xc0 | (byte)this[0x5c] & 0xf | (byte)((uVar6 & 3) << 4));
LAB_0039d034:
    this[0x5c] = rVar2;
    break;
  case 0x2c:
    rVar2 = (recordStructureWithFunc<unsigned_char>)((byte)this[0x5d] & 0xfc | param_3 & 3);
    goto LAB_0039d104;
  case 0x2d:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x5d] & 0xf0 | (byte)this[0x5d] & 3 | (byte)((uVar6 & 3) << 2));
    goto LAB_0039d104;
  case 0x2e:
    rVar2 = (recordStructureWithFunc<unsigned_char>)((byte)this[0x6c] & 0xfc | param_3 & 3);
    goto LAB_0039d120;
  case 0x2f:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x6c] & 0xf0 | (byte)this[0x6c] & 3 | (byte)((uVar6 & 3) << 2));
    goto LAB_0039d120;
  case 0x30:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x6c] & 0xc0 | (byte)this[0x6c] & 0xf | (byte)((uVar6 & 3) << 4));
    goto LAB_0039d120;
  case 0x31:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x6c] & 0x3f | (byte)((uVar6 & 3) << 6));
LAB_0039d120:
    this[0x6c] = rVar2;
    break;
  case 0x32:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x6f] & 0xf0 | (byte)this[0x6f] & 3 | (byte)((uVar6 & 3) << 2));
    goto LAB_0039d154;
  case 0x33:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x6f] & 0xc0 | (byte)this[0x6f] & 0xf | (byte)((uVar6 & 3) << 4));
    goto LAB_0039d154;
  case 0x34:
    cVar3 = IsJpegExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
    goto LAB_0039d17c;
  case 0x35:
    cVar3 = IsJpegExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
    goto LAB_0039d19c;
  case 0x36:
    cVar3 = IsHeifExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
LAB_0039d17c:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x5d] & 0xc0 | (byte)this[0x5d] & 0xf | (byte)((uVar6 & 3) << 4));
    goto LAB_0039d104;
  case 0x37:
    cVar3 = IsHeifExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
LAB_0039d19c:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x5d] & 0x3f | (byte)((uVar6 & 3) << 6));
LAB_0039d104:
    this[0x5d] = rVar2;
    break;
  case 0x38:
    rVar2 = (recordStructureWithFunc<unsigned_char>)((byte)this[0x5e] & 0xfc | param_3 & 3);
    goto LAB_0039d1d8;
  case 0x39:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x5e] & 0xf0 | (byte)this[0x5e] & 3 | (byte)((uVar5 & 3) << 2));
    goto LAB_0039d1d8;
  case 0x3a:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x5e] & 0xc0 | (byte)this[0x5e] & 0xf | (byte)((uVar5 & 3) << 4));
    goto LAB_0039d1d8;
  case 0x3b:
    rVar2 = (recordStructureWithFunc<unsigned_char>)((byte)this[0x6d] & 0xfc | param_3 & 3);
    goto LAB_0039d200;
  case 0x3c:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x6d] & 0xf0 | (byte)this[0x6d] & 3 | (byte)((uVar5 & 3) << 2));
    goto LAB_0039d200;
  case 0x3d:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x6d] & 0xc0 | (byte)this[0x6d] & 0xf | (byte)((uVar5 & 3) << 4));
    goto LAB_0039d200;
  case 0x3e:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x6d] & 0x3f | (byte)((uVar5 & 3) << 6));
LAB_0039d200:
    this[0x6d] = rVar2;
    break;
  case 0x3f:
    rVar2 = (recordStructureWithFunc<unsigned_char>)((byte)this[0x6e] & 0xfe | uVar5 != 0);
    goto LAB_0039cfb0;
  case 0x40:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x6e] & 0xfc | (byte)this[0x6e] & 1 | (uVar5 != 0) << 1);
    goto LAB_0039cfb0;
  case 0x41:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x6e] & 0xf8 | (byte)this[0x6e] & 3 | (uVar5 != 0) << 2);
    goto LAB_0039cfb0;
  case 0x42:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x6e] & 0xf0 | (byte)this[0x6e] & 7 | (uVar5 != 0) << 3);
    goto LAB_0039cfb0;
  case 0x43:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x6e] & 0xe0 | (byte)this[0x6e] & 0xf | (uVar5 != 0) << 4);
    goto LAB_0039cfb0;
  case 0x44:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x6e] & 0xc0 | (byte)this[0x6e] & 0x1f | (uVar5 != 0) << 5);
    goto LAB_0039cfb0;
  case 0x45:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x6e] & 0x80 | (byte)this[0x6e] & 0x3f | (uVar5 != 0) << 6);
    goto LAB_0039cfb0;
  case 0x46:
    rVar2 = (recordStructureWithFunc<unsigned_char>)((byte)this[0x6e] & 0x7f | (uVar5 != 0) << 7);
LAB_0039cfb0:
    this[0x6e] = rVar2;
    break;
  case 0x47:
    rVar2 = (recordStructureWithFunc<unsigned_char>)((byte)this[0x6f] & 0xfe | uVar5 != 0);
    goto LAB_0039d154;
  case 0x48:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x6f] & 0xfc | (byte)this[0x6f] & 1 | (uVar5 != 0) << 1);
    goto LAB_0039d154;
  case 0x49:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x6f] & 0x80 | (byte)this[0x6f] & 0x3f | (uVar4 != 0) << 6);
LAB_0039d154:
    this[0x6f] = rVar2;
    break;
  case 0x4c:
    cVar3 = IsJpegExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
    goto LAB_0039d328;
  case 0x50:
    cVar3 = IsHeifExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
LAB_0039d328:
    *(uint *)(this + 0x60) = uVar4;
    break;
  case 0x54:
    *(uint *)(this + 100) = uVar4;
    break;
  case 0x56:
    *(uint *)(this + 0x70) = uVar4;
    break;
  case 0x57:
    *(undefined4 *)(this + 0x70) = 0;
    *(uint *)(this + 0x74) = uVar4;
    break;
  case 0x58:
    *(undefined4 *)(this + 0x7c) = 0;
    *(uint *)(this + 0x80) = uVar4;
    break;
  case 0x59:
    rVar2 = (recordStructureWithFunc<unsigned_char>)
            ((byte)this[0x5e] & 0x80 | (byte)this[0x5e] & 0x3f | (uVar4 != 0) << 6);
    goto LAB_0039d1d8;
  case 0x5a:
    rVar2 = (recordStructureWithFunc<unsigned_char>)((byte)this[0x5e] & 0x7f | (uVar4 != 0) << 7);
LAB_0039d1d8:
    this[0x5e] = rVar2;
  }
  return 0;
}

