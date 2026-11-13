// sidb::recordStructureWithFunc<unsigned_long>::SetValue
// Ghidra address: 003a5448

/* sidb::recordStructureWithFunc<unsigned long>::SetValue(sidb::COL_ID, unsigned long) */

undefined8 __thiscall
sidb::recordStructureWithFunc<unsigned_long>::SetValue
          (recordStructureWithFunc<unsigned_long> *this,undefined4 param_2,ulong param_3)

{
  byte bVar1;
  recordStructureWithFunc<unsigned_long> rVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = (undefined4)(param_3 >> 0x20);
  uVar4 = (uint)param_3;
  bVar1 = (byte)param_3;
  switch(param_2) {
  case 2:
    *(uint *)(this + 8) = *(uint *)(this + 8) & 0xff | uVar4 << 8;
    break;
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x19:
  case 0x1a:
  case 0x4a:
  case 0x4b:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x55:
    return 0x403;
  case 8:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[6] & 0xe0 | (byte)this[6] & 0xf | (param_3 != 0) << 4);
    goto LAB_003a5490;
  case 9:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[6] & 0x1f | (byte)((uVar4 & 7) << 5));
    goto LAB_003a5490;
  case 10:
    this[4] = (recordStructureWithFunc<unsigned_long>)((byte)this[4] & 0xfe | param_3 != 0);
    break;
  case 0xb:
    this[7] = (recordStructureWithFunc<unsigned_long>)
              ((byte)this[7] & 0xf | (byte)((uVar4 & 0xf) << 4));
    break;
  case 0x16:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[6] & 0xfc | (byte)this[6] & 1 | (param_3 != 0) << 1);
    goto LAB_003a5490;
  case 0x17:
    rVar2 = (recordStructureWithFunc<unsigned_long>)((byte)this[6] & 0xfe | param_3 != 0);
LAB_003a5490:
    this[6] = rVar2;
    break;
  case 0x18:
    this[0x10] = (recordStructureWithFunc<unsigned_long>)((byte)this[0x10] & 0xfe | bVar1 & 1);
    break;
  case 0x1b:
  case 0x2b:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x5c] & 0x3f | (byte)((uVar4 & 3) << 6));
    goto LAB_003a55d4;
  case 0x1c:
    cVar3 = IsJpegExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
    goto LAB_003a5538;
  case 0x1d:
    cVar3 = IsJpegExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
    goto LAB_003a556c;
  case 0x1e:
    cVar3 = IsHeifExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
LAB_003a5538:
    this[0x5b] = (recordStructureWithFunc<unsigned_long>)((byte)this[0x5b] & 0xfc | bVar1 & 3);
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x6e] & 0x80 |
            (byte)this[0x6e] & 0x3f | (byte)(((uint)(param_3 >> 2) & 1) << 6));
    goto LAB_003a5550;
  case 0x1f:
    cVar3 = IsHeifExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
LAB_003a556c:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x5b] & 0xf0 | (byte)this[0x5b] & 3 | (byte)((uVar4 & 3) << 2));
LAB_003a5574:
    this[0x5b] = rVar2;
    break;
  case 0x20:
    this[0x5b] = (recordStructureWithFunc<unsigned_long>)
                 ((byte)this[0x5b] & 0xc0 | (byte)this[0x5b] & 0xf | (byte)((uVar4 & 3) << 4));
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x6e] & 0x7f | (byte)(((uint)(param_3 >> 2) & 1) << 7));
    goto LAB_003a5550;
  case 0x21:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x5b] & 0x3f | (byte)((uVar4 & 3) << 6));
    goto LAB_003a5574;
  case 0x22:
    rVar2 = (recordStructureWithFunc<unsigned_long>)((byte)this[0x5c] & 0xfc | bVar1 & 3);
    goto LAB_003a55d4;
  case 0x23:
    this[0x6b] = (recordStructureWithFunc<unsigned_long>)((byte)this[0x6b] & 0xfc | bVar1 & 3);
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x84] & 0xe0 |
            (byte)this[0x84] & 0xf | (byte)(((uint)(param_3 >> 2) & 1) << 4));
    goto LAB_003a55f4;
  case 0x24:
    this[0x6b] = (recordStructureWithFunc<unsigned_long>)
                 ((byte)this[0x6b] & 0xf0 | (byte)this[0x6b] & 3 | (byte)((uVar4 & 3) << 2));
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x84] & 0xc0 |
            (byte)this[0x84] & 0x1f | (byte)(((uint)(param_3 >> 2) & 1) << 5));
LAB_003a55f4:
    this[0x84] = rVar2;
    break;
  case 0x25:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x6b] & 0xc0 | (byte)this[0x6b] & 0xf | (byte)((uVar4 & 3) << 4));
    goto LAB_003a5620;
  case 0x26:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x6b] & 0x3f | (byte)((uVar4 & 3) << 6));
LAB_003a5620:
    this[0x6b] = rVar2;
    break;
  case 0x27:
    cVar3 = IsJpegExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
    goto LAB_003a5648;
  case 0x28:
    cVar3 = IsJpegExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
    goto LAB_003a5668;
  case 0x29:
    cVar3 = IsHeifExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
LAB_003a5648:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x5c] & 0xf0 | (byte)this[0x5c] & 3 | (byte)((uVar4 & 3) << 2));
    goto LAB_003a55d4;
  case 0x2a:
    cVar3 = IsHeifExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
LAB_003a5668:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x5c] & 0xc0 | (byte)this[0x5c] & 0xf | (byte)((uVar4 & 3) << 4));
LAB_003a55d4:
    this[0x5c] = rVar2;
    break;
  case 0x2c:
    rVar2 = (recordStructureWithFunc<unsigned_long>)((byte)this[0x5d] & 0xfc | bVar1 & 3);
    goto LAB_003a56a4;
  case 0x2d:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x5d] & 0xf0 | (byte)this[0x5d] & 3 | (byte)((uVar4 & 3) << 2));
    goto LAB_003a56a4;
  case 0x2e:
    rVar2 = (recordStructureWithFunc<unsigned_long>)((byte)this[0x6c] & 0xfc | bVar1 & 3);
    goto LAB_003a56c0;
  case 0x2f:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x6c] & 0xf0 | (byte)this[0x6c] & 3 | (byte)((uVar4 & 3) << 2));
    goto LAB_003a56c0;
  case 0x30:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x6c] & 0xc0 | (byte)this[0x6c] & 0xf | (byte)((uVar4 & 3) << 4));
    goto LAB_003a56c0;
  case 0x31:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x6c] & 0x3f | (byte)((uVar4 & 3) << 6));
LAB_003a56c0:
    this[0x6c] = rVar2;
    break;
  case 0x32:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x6f] & 0xf0 | (byte)this[0x6f] & 3 | (byte)((uVar4 & 3) << 2));
    goto LAB_003a56f4;
  case 0x33:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x6f] & 0xc0 | (byte)this[0x6f] & 0xf | (byte)((uVar4 & 3) << 4));
    goto LAB_003a56f4;
  case 0x34:
    cVar3 = IsJpegExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
    goto LAB_003a571c;
  case 0x35:
    cVar3 = IsJpegExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
    goto LAB_003a573c;
  case 0x36:
    cVar3 = IsHeifExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
LAB_003a571c:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x5d] & 0xc0 | (byte)this[0x5d] & 0xf | (byte)((uVar4 & 3) << 4));
    goto LAB_003a56a4;
  case 0x37:
    cVar3 = IsHeifExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
LAB_003a573c:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x5d] & 0x3f | (byte)((uVar4 & 3) << 6));
LAB_003a56a4:
    this[0x5d] = rVar2;
    break;
  case 0x38:
    rVar2 = (recordStructureWithFunc<unsigned_long>)((byte)this[0x5e] & 0xfc | bVar1 & 3);
    goto LAB_003a5778;
  case 0x39:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x5e] & 0xf0 | (byte)this[0x5e] & 3 | (byte)((uVar4 & 3) << 2));
    goto LAB_003a5778;
  case 0x3a:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x5e] & 0xc0 | (byte)this[0x5e] & 0xf | (byte)((uVar4 & 3) << 4));
    goto LAB_003a5778;
  case 0x3b:
    rVar2 = (recordStructureWithFunc<unsigned_long>)((byte)this[0x6d] & 0xfc | bVar1 & 3);
    goto LAB_003a57a0;
  case 0x3c:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x6d] & 0xf0 | (byte)this[0x6d] & 3 | (byte)((uVar4 & 3) << 2));
    goto LAB_003a57a0;
  case 0x3d:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x6d] & 0xc0 | (byte)this[0x6d] & 0xf | (byte)((uVar4 & 3) << 4));
    goto LAB_003a57a0;
  case 0x3e:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x6d] & 0x3f | (byte)((uVar4 & 3) << 6));
LAB_003a57a0:
    this[0x6d] = rVar2;
    break;
  case 0x3f:
    rVar2 = (recordStructureWithFunc<unsigned_long>)((byte)this[0x6e] & 0xfe | param_3 != 0);
    goto LAB_003a5550;
  case 0x40:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x6e] & 0xfc | (byte)this[0x6e] & 1 | (param_3 != 0) << 1);
    goto LAB_003a5550;
  case 0x41:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x6e] & 0xf8 | (byte)this[0x6e] & 3 | (param_3 != 0) << 2);
    goto LAB_003a5550;
  case 0x42:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x6e] & 0xf0 | (byte)this[0x6e] & 7 | (param_3 != 0) << 3);
    goto LAB_003a5550;
  case 0x43:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x6e] & 0xe0 | (byte)this[0x6e] & 0xf | (param_3 != 0) << 4);
    goto LAB_003a5550;
  case 0x44:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x6e] & 0xc0 | (byte)this[0x6e] & 0x1f | (param_3 != 0) << 5);
    goto LAB_003a5550;
  case 0x45:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x6e] & 0x80 | (byte)this[0x6e] & 0x3f | (param_3 != 0) << 6);
    goto LAB_003a5550;
  case 0x46:
    rVar2 = (recordStructureWithFunc<unsigned_long>)((byte)this[0x6e] & 0x7f | (param_3 != 0) << 7);
LAB_003a5550:
    this[0x6e] = rVar2;
    break;
  case 0x47:
    rVar2 = (recordStructureWithFunc<unsigned_long>)((byte)this[0x6f] & 0xfe | param_3 != 0);
    goto LAB_003a56f4;
  case 0x48:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x6f] & 0xfc | (byte)this[0x6f] & 1 | (param_3 != 0) << 1);
    goto LAB_003a56f4;
  case 0x49:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x6f] & 0x80 | (byte)this[0x6f] & 0x3f | (param_3 != 0) << 6);
LAB_003a56f4:
    this[0x6f] = rVar2;
    break;
  case 0x4c:
    cVar3 = IsJpegExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
    goto LAB_003a58c8;
  case 0x50:
    cVar3 = IsHeifExist(this);
    if (cVar3 == '\0') {
      return 0;
    }
LAB_003a58c8:
    *(uint *)(this + 0x60) = uVar4;
    break;
  case 0x54:
    *(uint *)(this + 100) = uVar4;
    break;
  case 0x56:
    *(uint *)(this + 0x70) = uVar4;
    break;
  case 0x57:
    *(undefined4 *)(this + 0x70) = uVar5;
    *(uint *)(this + 0x74) = uVar4;
    break;
  case 0x58:
    *(undefined4 *)(this + 0x7c) = uVar5;
    *(uint *)(this + 0x80) = uVar4;
    break;
  case 0x59:
    rVar2 = (recordStructureWithFunc<unsigned_long>)
            ((byte)this[0x5e] & 0x80 | (byte)this[0x5e] & 0x3f | (param_3 != 0) << 6);
    goto LAB_003a5778;
  case 0x5a:
    rVar2 = (recordStructureWithFunc<unsigned_long>)((byte)this[0x5e] & 0x7f | (param_3 != 0) << 7);
LAB_003a5778:
    this[0x5e] = rVar2;
    break;
  default:
    return 0x403;
  }
  return 0;
}

