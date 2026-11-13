// sidb::recordStructureWithFunc<bool>::SetValue
// Ghidra address: 0039b4b0

/* sidb::recordStructureWithFunc<bool>::SetValue(sidb::COL_ID, bool) */

undefined8 __thiscall
sidb::recordStructureWithFunc<bool>::SetValue
          (recordStructureWithFunc<bool> *this,int param_2,byte param_3)

{
  recordStructureWithFunc<bool> rVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (0x58 < param_2 - 2U) {
    return 0x403;
  }
  uVar3 = (uint)param_3;
  uVar4 = (uint)param_3;
  uVar5 = (uint)param_3;
  switch(param_2) {
  case 2:
    *(uint *)(this + 8) = *(uint *)(this + 8) & 0xff | uVar3 << 8;
    break;
  default:
    return 0x403;
  case 8:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[6] & 0xe0 | (byte)this[6] & 0xf | (byte)((uVar5 & 1) << 4));
    goto LAB_0039b4f0;
  case 9:
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[6] & 0x1f | (byte)((uVar5 & 7) << 5));
    goto LAB_0039b4f0;
  case 10:
    this[4] = (recordStructureWithFunc<bool>)((byte)this[4] & 0xfe | param_3 & 1);
    break;
  case 0xb:
    this[7] = (recordStructureWithFunc<bool>)((byte)this[7] & 0xf | (byte)((uVar5 & 0xf) << 4));
    break;
  case 0x16:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[6] & 0xfc | (byte)this[6] & 1 | (byte)((uVar5 & 1) << 1));
    goto LAB_0039b4f0;
  case 0x17:
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[6] & 0xfe | param_3 & 1);
LAB_0039b4f0:
    this[6] = rVar1;
    break;
  case 0x18:
    this[0x10] = (recordStructureWithFunc<bool>)((byte)this[0x10] & 0xfe | param_3 & 1);
    break;
  case 0x1b:
  case 0x2b:
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[0x5c] & 0x3f | (byte)((uVar5 & 3) << 6));
    goto LAB_0039b614;
  case 0x1c:
    cVar2 = IsJpegExist(this);
    if (cVar2 == '\0') {
      return 0;
    }
    goto LAB_0039b580;
  case 0x1d:
    cVar2 = IsJpegExist(this);
    if (cVar2 == '\0') {
      return 0;
    }
    goto LAB_0039b5b0;
  case 0x1e:
    cVar2 = IsHeifExist(this);
    if (cVar2 == '\0') {
      return 0;
    }
LAB_0039b580:
    this[0x5b] = (recordStructureWithFunc<bool>)((byte)this[0x5b] & 0xfc | param_3 & 3);
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[0x6e] & 0xbf);
    goto LAB_0039b594;
  case 0x1f:
    cVar2 = IsHeifExist(this);
    if (cVar2 == '\0') {
      return 0;
    }
LAB_0039b5b0:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x5b] & 0xf0 | (byte)this[0x5b] & 3 | (byte)((uVar5 & 3) << 2));
LAB_0039b5b8:
    this[0x5b] = rVar1;
    break;
  case 0x20:
    this[0x5b] = (recordStructureWithFunc<bool>)
                 ((byte)this[0x5b] & 0xc0 | (byte)this[0x5b] & 0xf | (byte)((uVar5 & 3) << 4));
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[0x6e] & 0x7f);
    goto LAB_0039b594;
  case 0x21:
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[0x5b] & 0x3f | (byte)((uVar5 & 3) << 6));
    goto LAB_0039b5b8;
  case 0x22:
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[0x5c] & 0xfc | param_3 & 3);
    goto LAB_0039b614;
  case 0x23:
    this[0x6b] = (recordStructureWithFunc<bool>)((byte)this[0x6b] & 0xfc | param_3 & 3);
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[0x84] & 0xef);
    goto LAB_0039b630;
  case 0x24:
    this[0x6b] = (recordStructureWithFunc<bool>)
                 ((byte)this[0x6b] & 0xf0 | (byte)this[0x6b] & 3 | (byte)((uVar5 & 3) << 2));
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[0x84] & 0xdf);
LAB_0039b630:
    this[0x84] = rVar1;
    break;
  case 0x25:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x6b] & 0xc0 | (byte)this[0x6b] & 0xf | (byte)((uVar5 & 3) << 4));
    goto LAB_0039b658;
  case 0x26:
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[0x6b] & 0x3f | (byte)((uVar5 & 3) << 6));
LAB_0039b658:
    this[0x6b] = rVar1;
    break;
  case 0x27:
    cVar2 = IsJpegExist(this);
    if (cVar2 == '\0') {
      return 0;
    }
    goto LAB_0039b680;
  case 0x28:
    cVar2 = IsJpegExist(this);
    if (cVar2 == '\0') {
      return 0;
    }
    goto LAB_0039b6a0;
  case 0x29:
    cVar2 = IsHeifExist(this);
    if (cVar2 == '\0') {
      return 0;
    }
LAB_0039b680:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x5c] & 0xf0 | (byte)this[0x5c] & 3 | (byte)((uVar5 & 3) << 2));
    goto LAB_0039b614;
  case 0x2a:
    cVar2 = IsHeifExist(this);
    if (cVar2 == '\0') {
      return 0;
    }
LAB_0039b6a0:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x5c] & 0xc0 | (byte)this[0x5c] & 0xf | (byte)((uVar5 & 3) << 4));
LAB_0039b614:
    this[0x5c] = rVar1;
    break;
  case 0x2c:
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[0x5d] & 0xfc | param_3 & 3);
    goto LAB_0039b6dc;
  case 0x2d:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x5d] & 0xf0 | (byte)this[0x5d] & 3 | (byte)((uVar5 & 3) << 2));
    goto LAB_0039b6dc;
  case 0x2e:
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[0x6c] & 0xfc | param_3 & 3);
    goto LAB_0039b6f8;
  case 0x2f:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x6c] & 0xf0 | (byte)this[0x6c] & 3 | (byte)((uVar5 & 3) << 2));
    goto LAB_0039b6f8;
  case 0x30:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x6c] & 0xc0 | (byte)this[0x6c] & 0xf | (byte)((uVar5 & 3) << 4));
    goto LAB_0039b6f8;
  case 0x31:
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[0x6c] & 0x3f | (byte)((uVar5 & 3) << 6));
LAB_0039b6f8:
    this[0x6c] = rVar1;
    break;
  case 0x32:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x6f] & 0xf0 | (byte)this[0x6f] & 3 | (byte)((uVar5 & 3) << 2));
    goto LAB_0039b72c;
  case 0x33:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x6f] & 0xc0 | (byte)this[0x6f] & 0xf | (byte)((uVar5 & 3) << 4));
    goto LAB_0039b72c;
  case 0x34:
    cVar2 = IsJpegExist(this);
    if (cVar2 == '\0') {
      return 0;
    }
    goto LAB_0039b754;
  case 0x35:
    cVar2 = IsJpegExist(this);
    if (cVar2 == '\0') {
      return 0;
    }
    goto LAB_0039b774;
  case 0x36:
    cVar2 = IsHeifExist(this);
    if (cVar2 == '\0') {
      return 0;
    }
LAB_0039b754:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x5d] & 0xc0 | (byte)this[0x5d] & 0xf | (byte)((uVar5 & 3) << 4));
    goto LAB_0039b6dc;
  case 0x37:
    cVar2 = IsHeifExist(this);
    if (cVar2 == '\0') {
      return 0;
    }
LAB_0039b774:
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[0x5d] & 0x3f | (byte)((uVar5 & 3) << 6));
LAB_0039b6dc:
    this[0x5d] = rVar1;
    break;
  case 0x38:
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[0x5e] & 0xfc | param_3 & 3);
    goto LAB_0039b7b0;
  case 0x39:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x5e] & 0xf0 | (byte)this[0x5e] & 3 | (byte)((uVar4 & 3) << 2));
    goto LAB_0039b7b0;
  case 0x3a:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x5e] & 0xc0 | (byte)this[0x5e] & 0xf | (byte)((uVar4 & 3) << 4));
    goto LAB_0039b7b0;
  case 0x3b:
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[0x6d] & 0xfc | param_3 & 3);
    goto LAB_0039b7d8;
  case 0x3c:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x6d] & 0xf0 | (byte)this[0x6d] & 3 | (byte)((uVar4 & 3) << 2));
    goto LAB_0039b7d8;
  case 0x3d:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x6d] & 0xc0 | (byte)this[0x6d] & 0xf | (byte)((uVar4 & 3) << 4));
    goto LAB_0039b7d8;
  case 0x3e:
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[0x6d] & 0x3f | (byte)((uVar4 & 3) << 6));
LAB_0039b7d8:
    this[0x6d] = rVar1;
    break;
  case 0x3f:
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[0x6e] & 0xfe | param_3 & 1);
    goto LAB_0039b594;
  case 0x40:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x6e] & 0xfc | (byte)this[0x6e] & 1 | (byte)((uVar4 & 1) << 1));
    goto LAB_0039b594;
  case 0x41:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x6e] & 0xf8 | (byte)this[0x6e] & 3 | (byte)((uVar4 & 1) << 2));
    goto LAB_0039b594;
  case 0x42:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x6e] & 0xf0 | (byte)this[0x6e] & 7 | (byte)((uVar4 & 1) << 3));
    goto LAB_0039b594;
  case 0x43:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x6e] & 0xe0 | (byte)this[0x6e] & 0xf | (byte)((uVar4 & 1) << 4));
    goto LAB_0039b594;
  case 0x44:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x6e] & 0xc0 | (byte)this[0x6e] & 0x1f | (byte)((uVar4 & 1) << 5));
    goto LAB_0039b594;
  case 0x45:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x6e] & 0x80 | (byte)this[0x6e] & 0x3f | (byte)((uVar4 & 1) << 6));
    goto LAB_0039b594;
  case 0x46:
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[0x6e] & 0x7f | (byte)((uVar4 & 1) << 7));
LAB_0039b594:
    this[0x6e] = rVar1;
    break;
  case 0x47:
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[0x6f] & 0xfe | param_3 & 1);
    goto LAB_0039b72c;
  case 0x48:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x6f] & 0xfc | (byte)this[0x6f] & 1 | (byte)((uVar4 & 1) << 1));
    goto LAB_0039b72c;
  case 0x49:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x6f] & 0x80 | (byte)this[0x6f] & 0x3f | (byte)((uVar3 & 1) << 6));
LAB_0039b72c:
    this[0x6f] = rVar1;
    break;
  case 0x4c:
    cVar2 = IsJpegExist(this);
    if (cVar2 == '\0') {
      return 0;
    }
    goto LAB_0039b8a8;
  case 0x50:
    cVar2 = IsHeifExist(this);
    if (cVar2 == '\0') {
      return 0;
    }
LAB_0039b8a8:
    *(uint *)(this + 0x60) = uVar3;
    break;
  case 0x54:
    *(uint *)(this + 100) = uVar3;
    break;
  case 0x56:
    *(uint *)(this + 0x70) = uVar3;
    break;
  case 0x57:
    *(undefined4 *)(this + 0x70) = 0;
    *(uint *)(this + 0x74) = uVar3;
    break;
  case 0x58:
    *(undefined4 *)(this + 0x7c) = 0;
    *(uint *)(this + 0x80) = uVar3;
    break;
  case 0x59:
    rVar1 = (recordStructureWithFunc<bool>)
            ((byte)this[0x5e] & 0x80 | (byte)this[0x5e] & 0x3f | (byte)((uVar3 & 1) << 6));
    goto LAB_0039b7b0;
  case 0x5a:
    rVar1 = (recordStructureWithFunc<bool>)((byte)this[0x5e] & 0x7f | (byte)((uVar3 & 1) << 7));
LAB_0039b7b0:
    this[0x5e] = rVar1;
  }
  return 0;
}

