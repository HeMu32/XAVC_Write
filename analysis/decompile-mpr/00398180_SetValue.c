// sidb::recordStructureWithFunc<unsigned_short>::SetValue
// Ghidra address: 00398180

/* sidb::recordStructureWithFunc<unsigned short>::SetValue(sidb::COL_ID, unsigned short) */

undefined8 __thiscall
sidb::recordStructureWithFunc<unsigned_short>::SetValue
          (recordStructureWithFunc<unsigned_short> *this,int param_2,ushort param_3)

{
  uint uVar1;
  byte bVar2;
  recordStructureWithFunc<unsigned_short> rVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  if (0x58 < param_2 - 2U) {
    return 0x403;
  }
  uVar5 = (uint)param_3;
  uVar6 = (uint)param_3;
  uVar7 = (uint)param_3;
  uVar1 = (int)uVar7 >> 2;
  bVar2 = (byte)param_3;
  switch(param_2) {
  case 2:
    *(uint *)(this + 8) = *(uint *)(this + 8) & 0xff | (uint)param_3 << 8;
    break;
  default:
    return 0x403;
  case 8:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[6] & 0xe0 | (byte)this[6] & 0xf | (uVar7 != 0) << 4);
    goto LAB_003981c8;
  case 9:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[6] & 0x1f | (byte)((uVar7 & 7) << 5));
    goto LAB_003981c8;
  case 10:
    this[4] = (recordStructureWithFunc<unsigned_short>)((byte)this[4] & 0xfe | uVar7 != 0);
    break;
  case 0xb:
    this[7] = (recordStructureWithFunc<unsigned_short>)
              ((byte)this[7] & 0xf | (byte)((uVar7 & 0xf) << 4));
    break;
  case 0x16:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[6] & 0xfc | (byte)this[6] & 1 | (uVar7 != 0) << 1);
    goto LAB_003981c8;
  case 0x17:
    rVar3 = (recordStructureWithFunc<unsigned_short>)((byte)this[6] & 0xfe | uVar7 != 0);
LAB_003981c8:
    this[6] = rVar3;
    break;
  case 0x18:
    this[0x10] = (recordStructureWithFunc<unsigned_short>)((byte)this[0x10] & 0xfe | bVar2 & 1);
    break;
  case 0x1b:
  case 0x2b:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x5c] & 0x3f | (byte)((uVar7 & 3) << 6));
    goto LAB_0039830c;
  case 0x1c:
    cVar4 = IsJpegExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
    goto LAB_00398270;
  case 0x1d:
    cVar4 = IsJpegExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
    goto LAB_003982a4;
  case 0x1e:
    cVar4 = IsHeifExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
LAB_00398270:
    this[0x5b] = (recordStructureWithFunc<unsigned_short>)((byte)this[0x5b] & 0xfc | bVar2 & 3);
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x6e] & 0x80 |
            (byte)this[0x6e] & 0x3f | (byte)(((int)(uint)param_3 >> 2 & 1U) << 6));
    goto LAB_00398288;
  case 0x1f:
    cVar4 = IsHeifExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
LAB_003982a4:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x5b] & 0xf0 | (byte)this[0x5b] & 3 | (byte)((uVar7 & 3) << 2));
LAB_003982ac:
    this[0x5b] = rVar3;
    break;
  case 0x20:
    this[0x5b] = (recordStructureWithFunc<unsigned_short>)
                 ((byte)this[0x5b] & 0xc0 | (byte)this[0x5b] & 0xf | (byte)((uVar7 & 3) << 4));
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x6e] & 0x7f | (byte)((uVar1 & 1) << 7));
    goto LAB_00398288;
  case 0x21:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x5b] & 0x3f | (byte)((uVar7 & 3) << 6));
    goto LAB_003982ac;
  case 0x22:
    rVar3 = (recordStructureWithFunc<unsigned_short>)((byte)this[0x5c] & 0xfc | bVar2 & 3);
    goto LAB_0039830c;
  case 0x23:
    this[0x6b] = (recordStructureWithFunc<unsigned_short>)((byte)this[0x6b] & 0xfc | bVar2 & 3);
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x84] & 0xe0 | (byte)this[0x84] & 0xf | (byte)((uVar1 & 1) << 4));
    goto LAB_0039832c;
  case 0x24:
    this[0x6b] = (recordStructureWithFunc<unsigned_short>)
                 ((byte)this[0x6b] & 0xf0 | (byte)this[0x6b] & 3 | (byte)((uVar7 & 3) << 2));
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x84] & 0xc0 | (byte)this[0x84] & 0x1f | (byte)((uVar1 & 1) << 5));
LAB_0039832c:
    this[0x84] = rVar3;
    break;
  case 0x25:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x6b] & 0xc0 | (byte)this[0x6b] & 0xf | (byte)((uVar7 & 3) << 4));
    goto LAB_00398358;
  case 0x26:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x6b] & 0x3f | (byte)((uVar7 & 3) << 6));
LAB_00398358:
    this[0x6b] = rVar3;
    break;
  case 0x27:
    cVar4 = IsJpegExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
    goto LAB_00398380;
  case 0x28:
    cVar4 = IsJpegExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
    goto LAB_003983a0;
  case 0x29:
    cVar4 = IsHeifExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
LAB_00398380:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x5c] & 0xf0 | (byte)this[0x5c] & 3 | (byte)((uVar7 & 3) << 2));
    goto LAB_0039830c;
  case 0x2a:
    cVar4 = IsHeifExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
LAB_003983a0:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x5c] & 0xc0 | (byte)this[0x5c] & 0xf | (byte)((uVar7 & 3) << 4));
LAB_0039830c:
    this[0x5c] = rVar3;
    break;
  case 0x2c:
    rVar3 = (recordStructureWithFunc<unsigned_short>)((byte)this[0x5d] & 0xfc | bVar2 & 3);
    goto LAB_003983dc;
  case 0x2d:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x5d] & 0xf0 | (byte)this[0x5d] & 3 | (byte)((uVar7 & 3) << 2));
    goto LAB_003983dc;
  case 0x2e:
    rVar3 = (recordStructureWithFunc<unsigned_short>)((byte)this[0x6c] & 0xfc | bVar2 & 3);
    goto LAB_003983f8;
  case 0x2f:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x6c] & 0xf0 | (byte)this[0x6c] & 3 | (byte)((uVar7 & 3) << 2));
    goto LAB_003983f8;
  case 0x30:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x6c] & 0xc0 | (byte)this[0x6c] & 0xf | (byte)((uVar7 & 3) << 4));
    goto LAB_003983f8;
  case 0x31:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x6c] & 0x3f | (byte)((uVar7 & 3) << 6));
LAB_003983f8:
    this[0x6c] = rVar3;
    break;
  case 0x32:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x6f] & 0xf0 | (byte)this[0x6f] & 3 | (byte)((uVar7 & 3) << 2));
    goto LAB_0039842c;
  case 0x33:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x6f] & 0xc0 | (byte)this[0x6f] & 0xf | (byte)((uVar7 & 3) << 4));
    goto LAB_0039842c;
  case 0x34:
    cVar4 = IsJpegExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
    goto LAB_00398454;
  case 0x35:
    cVar4 = IsJpegExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
    goto LAB_00398474;
  case 0x36:
    cVar4 = IsHeifExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
LAB_00398454:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x5d] & 0xc0 | (byte)this[0x5d] & 0xf | (byte)((uVar7 & 3) << 4));
    goto LAB_003983dc;
  case 0x37:
    cVar4 = IsHeifExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
LAB_00398474:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x5d] & 0x3f | (byte)((uVar7 & 3) << 6));
LAB_003983dc:
    this[0x5d] = rVar3;
    break;
  case 0x38:
    rVar3 = (recordStructureWithFunc<unsigned_short>)((byte)this[0x5e] & 0xfc | bVar2 & 3);
    goto LAB_003984b0;
  case 0x39:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x5e] & 0xf0 | (byte)this[0x5e] & 3 | (byte)((uVar6 & 3) << 2));
    goto LAB_003984b0;
  case 0x3a:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x5e] & 0xc0 | (byte)this[0x5e] & 0xf | (byte)((uVar6 & 3) << 4));
    goto LAB_003984b0;
  case 0x3b:
    rVar3 = (recordStructureWithFunc<unsigned_short>)((byte)this[0x6d] & 0xfc | bVar2 & 3);
    goto LAB_003984d8;
  case 0x3c:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x6d] & 0xf0 | (byte)this[0x6d] & 3 | (byte)((uVar6 & 3) << 2));
    goto LAB_003984d8;
  case 0x3d:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x6d] & 0xc0 | (byte)this[0x6d] & 0xf | (byte)((uVar6 & 3) << 4));
    goto LAB_003984d8;
  case 0x3e:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x6d] & 0x3f | (byte)((uVar6 & 3) << 6));
LAB_003984d8:
    this[0x6d] = rVar3;
    break;
  case 0x3f:
    rVar3 = (recordStructureWithFunc<unsigned_short>)((byte)this[0x6e] & 0xfe | uVar6 != 0);
    goto LAB_00398288;
  case 0x40:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x6e] & 0xfc | (byte)this[0x6e] & 1 | (uVar6 != 0) << 1);
    goto LAB_00398288;
  case 0x41:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x6e] & 0xf8 | (byte)this[0x6e] & 3 | (uVar6 != 0) << 2);
    goto LAB_00398288;
  case 0x42:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x6e] & 0xf0 | (byte)this[0x6e] & 7 | (uVar6 != 0) << 3);
    goto LAB_00398288;
  case 0x43:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x6e] & 0xe0 | (byte)this[0x6e] & 0xf | (uVar6 != 0) << 4);
    goto LAB_00398288;
  case 0x44:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x6e] & 0xc0 | (byte)this[0x6e] & 0x1f | (uVar6 != 0) << 5);
    goto LAB_00398288;
  case 0x45:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x6e] & 0x80 | (byte)this[0x6e] & 0x3f | (uVar6 != 0) << 6);
    goto LAB_00398288;
  case 0x46:
    rVar3 = (recordStructureWithFunc<unsigned_short>)((byte)this[0x6e] & 0x7f | (uVar6 != 0) << 7);
LAB_00398288:
    this[0x6e] = rVar3;
    break;
  case 0x47:
    rVar3 = (recordStructureWithFunc<unsigned_short>)((byte)this[0x6f] & 0xfe | uVar6 != 0);
    goto LAB_0039842c;
  case 0x48:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x6f] & 0xfc | (byte)this[0x6f] & 1 | (uVar6 != 0) << 1);
    goto LAB_0039842c;
  case 0x49:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x6f] & 0x80 | (byte)this[0x6f] & 0x3f | (uVar5 != 0) << 6);
LAB_0039842c:
    this[0x6f] = rVar3;
    break;
  case 0x4c:
    cVar4 = IsJpegExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
    goto LAB_00398600;
  case 0x50:
    cVar4 = IsHeifExist(this);
    if (cVar4 == '\0') {
      return 0;
    }
LAB_00398600:
    *(uint *)(this + 0x60) = uVar5;
    break;
  case 0x54:
    *(uint *)(this + 100) = uVar5;
    break;
  case 0x56:
    *(uint *)(this + 0x70) = uVar5;
    break;
  case 0x57:
    *(undefined4 *)(this + 0x70) = 0;
    *(uint *)(this + 0x74) = uVar5;
    break;
  case 0x58:
    *(undefined4 *)(this + 0x7c) = 0;
    *(uint *)(this + 0x80) = uVar5;
    break;
  case 0x59:
    rVar3 = (recordStructureWithFunc<unsigned_short>)
            ((byte)this[0x5e] & 0x80 | (byte)this[0x5e] & 0x3f | (uVar5 != 0) << 6);
    goto LAB_003984b0;
  case 0x5a:
    rVar3 = (recordStructureWithFunc<unsigned_short>)((byte)this[0x5e] & 0x7f | (uVar5 != 0) << 7);
LAB_003984b0:
    this[0x5e] = rVar3;
  }
  return 0;
}

