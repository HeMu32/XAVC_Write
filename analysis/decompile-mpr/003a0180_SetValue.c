// sidb::recordStructureWithFunc<short>::SetValue
// Ghidra address: 003a0180

/* sidb::recordStructureWithFunc<short>::SetValue(sidb::COL_ID, short) */

undefined8 __thiscall
sidb::recordStructureWithFunc<short>::SetValue
          (recordStructureWithFunc<short> *this,int param_2,short param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  recordStructureWithFunc<short> rVar4;
  char cVar5;
  
  if (0x58 < param_2 - 2U) {
    return 0x403;
  }
  uVar2 = (uint)param_3;
  uVar1 = (int)uVar2 >> 2;
  bVar3 = (byte)param_3;
  switch(param_2) {
  case 2:
    *(uint *)(this + 8) = *(uint *)(this + 8) & 0xff | uVar2 << 8;
    break;
  default:
    return 0x403;
  case 8:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[6] & 0xe0 | (byte)this[6] & 0xf | (uVar2 != 0) << 4);
    goto LAB_003a01c8;
  case 9:
    rVar4 = (recordStructureWithFunc<short>)((byte)this[6] & 0x1f | (byte)((uVar2 & 7) << 5));
    goto LAB_003a01c8;
  case 10:
    this[4] = (recordStructureWithFunc<short>)((byte)this[4] & 0xfe | uVar2 != 0);
    break;
  case 0xb:
    this[7] = (recordStructureWithFunc<short>)((byte)this[7] & 0xf | (byte)((uVar2 & 0xf) << 4));
    break;
  case 0x16:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[6] & 0xfc | (byte)this[6] & 1 | (uVar2 != 0) << 1);
    goto LAB_003a01c8;
  case 0x17:
    rVar4 = (recordStructureWithFunc<short>)((byte)this[6] & 0xfe | uVar2 != 0);
LAB_003a01c8:
    this[6] = rVar4;
    break;
  case 0x18:
    this[0x10] = (recordStructureWithFunc<short>)((byte)this[0x10] & 0xfe | bVar3 & 1);
    break;
  case 0x1b:
  case 0x2b:
    rVar4 = (recordStructureWithFunc<short>)((byte)this[0x5c] & 0x3f | (byte)((uVar2 & 3) << 6));
    goto LAB_003a030c;
  case 0x1c:
    cVar5 = IsJpegExist(this);
    if (cVar5 == '\0') {
      return 0;
    }
    goto LAB_003a0270;
  case 0x1d:
    cVar5 = IsJpegExist(this);
    if (cVar5 == '\0') {
      return 0;
    }
    goto LAB_003a02a4;
  case 0x1e:
    cVar5 = IsHeifExist(this);
    if (cVar5 == '\0') {
      return 0;
    }
LAB_003a0270:
    this[0x5b] = (recordStructureWithFunc<short>)((byte)this[0x5b] & 0xfc | bVar3 & 3);
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x6e] & 0x80 | (byte)this[0x6e] & 0x3f | (byte)((uVar1 & 1) << 6));
    goto LAB_003a0288;
  case 0x1f:
    cVar5 = IsHeifExist(this);
    if (cVar5 == '\0') {
      return 0;
    }
LAB_003a02a4:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x5b] & 0xf0 | (byte)this[0x5b] & 3 | (byte)((uVar2 & 3) << 2));
LAB_003a02ac:
    this[0x5b] = rVar4;
    break;
  case 0x20:
    this[0x5b] = (recordStructureWithFunc<short>)
                 ((byte)this[0x5b] & 0xc0 | (byte)this[0x5b] & 0xf | (byte)((uVar2 & 3) << 4));
    rVar4 = (recordStructureWithFunc<short>)((byte)this[0x6e] & 0x7f | (byte)((uVar1 & 1) << 7));
    goto LAB_003a0288;
  case 0x21:
    rVar4 = (recordStructureWithFunc<short>)((byte)this[0x5b] & 0x3f | (byte)((uVar2 & 3) << 6));
    goto LAB_003a02ac;
  case 0x22:
    rVar4 = (recordStructureWithFunc<short>)((byte)this[0x5c] & 0xfc | bVar3 & 3);
    goto LAB_003a030c;
  case 0x23:
    this[0x6b] = (recordStructureWithFunc<short>)((byte)this[0x6b] & 0xfc | bVar3 & 3);
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x84] & 0xe0 | (byte)this[0x84] & 0xf | (byte)((uVar1 & 1) << 4));
    goto LAB_003a032c;
  case 0x24:
    this[0x6b] = (recordStructureWithFunc<short>)
                 ((byte)this[0x6b] & 0xf0 | (byte)this[0x6b] & 3 | (byte)((uVar2 & 3) << 2));
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x84] & 0xc0 | (byte)this[0x84] & 0x1f | (byte)((uVar1 & 1) << 5));
LAB_003a032c:
    this[0x84] = rVar4;
    break;
  case 0x25:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x6b] & 0xc0 | (byte)this[0x6b] & 0xf | (byte)((uVar2 & 3) << 4));
    goto LAB_003a0358;
  case 0x26:
    rVar4 = (recordStructureWithFunc<short>)((byte)this[0x6b] & 0x3f | (byte)((uVar2 & 3) << 6));
LAB_003a0358:
    this[0x6b] = rVar4;
    break;
  case 0x27:
    cVar5 = IsJpegExist(this);
    if (cVar5 == '\0') {
      return 0;
    }
    goto LAB_003a0380;
  case 0x28:
    cVar5 = IsJpegExist(this);
    if (cVar5 == '\0') {
      return 0;
    }
    goto LAB_003a03a0;
  case 0x29:
    cVar5 = IsHeifExist(this);
    if (cVar5 == '\0') {
      return 0;
    }
LAB_003a0380:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x5c] & 0xf0 | (byte)this[0x5c] & 3 | (byte)((uVar2 & 3) << 2));
    goto LAB_003a030c;
  case 0x2a:
    cVar5 = IsHeifExist(this);
    if (cVar5 == '\0') {
      return 0;
    }
LAB_003a03a0:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x5c] & 0xc0 | (byte)this[0x5c] & 0xf | (byte)((uVar2 & 3) << 4));
LAB_003a030c:
    this[0x5c] = rVar4;
    break;
  case 0x2c:
    rVar4 = (recordStructureWithFunc<short>)((byte)this[0x5d] & 0xfc | bVar3 & 3);
    goto LAB_003a03dc;
  case 0x2d:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x5d] & 0xf0 | (byte)this[0x5d] & 3 | (byte)((uVar2 & 3) << 2));
    goto LAB_003a03dc;
  case 0x2e:
    rVar4 = (recordStructureWithFunc<short>)((byte)this[0x6c] & 0xfc | bVar3 & 3);
    goto LAB_003a03f8;
  case 0x2f:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x6c] & 0xf0 | (byte)this[0x6c] & 3 | (byte)((uVar2 & 3) << 2));
    goto LAB_003a03f8;
  case 0x30:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x6c] & 0xc0 | (byte)this[0x6c] & 0xf | (byte)((uVar2 & 3) << 4));
    goto LAB_003a03f8;
  case 0x31:
    rVar4 = (recordStructureWithFunc<short>)((byte)this[0x6c] & 0x3f | (byte)((uVar2 & 3) << 6));
LAB_003a03f8:
    this[0x6c] = rVar4;
    break;
  case 0x32:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x6f] & 0xf0 | (byte)this[0x6f] & 3 | (byte)((uVar2 & 3) << 2));
    goto LAB_003a042c;
  case 0x33:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x6f] & 0xc0 | (byte)this[0x6f] & 0xf | (byte)((uVar2 & 3) << 4));
    goto LAB_003a042c;
  case 0x34:
    cVar5 = IsJpegExist(this);
    if (cVar5 == '\0') {
      return 0;
    }
    goto LAB_003a0454;
  case 0x35:
    cVar5 = IsJpegExist(this);
    if (cVar5 == '\0') {
      return 0;
    }
    goto LAB_003a0474;
  case 0x36:
    cVar5 = IsHeifExist(this);
    if (cVar5 == '\0') {
      return 0;
    }
LAB_003a0454:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x5d] & 0xc0 | (byte)this[0x5d] & 0xf | (byte)((uVar2 & 3) << 4));
    goto LAB_003a03dc;
  case 0x37:
    cVar5 = IsHeifExist(this);
    if (cVar5 == '\0') {
      return 0;
    }
LAB_003a0474:
    rVar4 = (recordStructureWithFunc<short>)((byte)this[0x5d] & 0x3f | (byte)((uVar2 & 3) << 6));
LAB_003a03dc:
    this[0x5d] = rVar4;
    break;
  case 0x38:
    rVar4 = (recordStructureWithFunc<short>)((byte)this[0x5e] & 0xfc | bVar3 & 3);
    goto LAB_003a04b0;
  case 0x39:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x5e] & 0xf0 | (byte)this[0x5e] & 3 | (byte)((uVar2 & 3) << 2));
    goto LAB_003a04b0;
  case 0x3a:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x5e] & 0xc0 | (byte)this[0x5e] & 0xf | (byte)((uVar2 & 3) << 4));
    goto LAB_003a04b0;
  case 0x3b:
    rVar4 = (recordStructureWithFunc<short>)((byte)this[0x6d] & 0xfc | bVar3 & 3);
    goto LAB_003a04d8;
  case 0x3c:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x6d] & 0xf0 | (byte)this[0x6d] & 3 | (byte)((uVar2 & 3) << 2));
    goto LAB_003a04d8;
  case 0x3d:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x6d] & 0xc0 | (byte)this[0x6d] & 0xf | (byte)((uVar2 & 3) << 4));
    goto LAB_003a04d8;
  case 0x3e:
    rVar4 = (recordStructureWithFunc<short>)((byte)this[0x6d] & 0x3f | (byte)((uVar2 & 3) << 6));
LAB_003a04d8:
    this[0x6d] = rVar4;
    break;
  case 0x3f:
    rVar4 = (recordStructureWithFunc<short>)((byte)this[0x6e] & 0xfe | uVar2 != 0);
    goto LAB_003a0288;
  case 0x40:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x6e] & 0xfc | (byte)this[0x6e] & 1 | (uVar2 != 0) << 1);
    goto LAB_003a0288;
  case 0x41:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x6e] & 0xf8 | (byte)this[0x6e] & 3 | (uVar2 != 0) << 2);
    goto LAB_003a0288;
  case 0x42:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x6e] & 0xf0 | (byte)this[0x6e] & 7 | (uVar2 != 0) << 3);
    goto LAB_003a0288;
  case 0x43:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x6e] & 0xe0 | (byte)this[0x6e] & 0xf | (uVar2 != 0) << 4);
    goto LAB_003a0288;
  case 0x44:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x6e] & 0xc0 | (byte)this[0x6e] & 0x1f | (uVar2 != 0) << 5);
    goto LAB_003a0288;
  case 0x45:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x6e] & 0x80 | (byte)this[0x6e] & 0x3f | (uVar2 != 0) << 6);
    goto LAB_003a0288;
  case 0x46:
    rVar4 = (recordStructureWithFunc<short>)((byte)this[0x6e] & 0x7f | (uVar2 != 0) << 7);
LAB_003a0288:
    this[0x6e] = rVar4;
    break;
  case 0x47:
    rVar4 = (recordStructureWithFunc<short>)((byte)this[0x6f] & 0xfe | uVar2 != 0);
    goto LAB_003a042c;
  case 0x48:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x6f] & 0xfc | (byte)this[0x6f] & 1 | (uVar2 != 0) << 1);
    goto LAB_003a042c;
  case 0x49:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x6f] & 0x80 | (byte)this[0x6f] & 0x3f | (uVar2 != 0) << 6);
LAB_003a042c:
    this[0x6f] = rVar4;
    break;
  case 0x4c:
    cVar5 = IsJpegExist(this);
    if (cVar5 == '\0') {
      return 0;
    }
    goto LAB_003a0600;
  case 0x50:
    cVar5 = IsHeifExist(this);
    if (cVar5 == '\0') {
      return 0;
    }
LAB_003a0600:
    *(uint *)(this + 0x60) = uVar2;
    break;
  case 0x54:
    *(uint *)(this + 100) = uVar2;
    break;
  case 0x56:
    *(uint *)(this + 0x70) = uVar2;
    break;
  case 0x57:
    *(uint *)(this + 0x70) = -(uVar2 >> 0xf & 1);
    *(uint *)(this + 0x74) = uVar2;
    break;
  case 0x58:
    *(uint *)(this + 0x7c) = -(uVar2 >> 0xf & 1);
    *(uint *)(this + 0x80) = uVar2;
    break;
  case 0x59:
    rVar4 = (recordStructureWithFunc<short>)
            ((byte)this[0x5e] & 0x80 | (byte)this[0x5e] & 0x3f | (uVar2 != 0) << 6);
    goto LAB_003a04b0;
  case 0x5a:
    rVar4 = (recordStructureWithFunc<short>)((byte)this[0x5e] & 0x7f | (uVar2 != 0) << 7);
LAB_003a04b0:
    this[0x5e] = rVar4;
  }
  return 0;
}

