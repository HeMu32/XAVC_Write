// sidb::recordStructureWithFunc<unsigned_int>::GetValue
// Ghidra address: 003a0aac

/* sidb::recordStructureWithFunc<unsigned int>::GetValue(sidb::COL_ID, unsigned int, unsigned int*)
    */

undefined8 __thiscall
sidb::recordStructureWithFunc<unsigned_int>::GetValue
          (recordStructureWithFunc<unsigned_int> *this,undefined4 param_2,uint param_3,uint *param_4
          )

{
  recordStructureWithFunc<unsigned_int> rVar1;
  ushort uVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  
  if (param_4 == (uint *)0x0) {
switchD_003a0ae0_default:
    return 0x403;
  }
  switch(param_2) {
  case 0:
    uVar4 = ContentTypeInternal2ContentType((byte)this[7] & 0xf);
    break;
  case 1:
    *param_4 = param_3 | (uint)(*(ushort *)(this + 4) >> 1) << 0x11;
    return 0;
  case 2:
    uVar4 = *(uint *)(this + 8) >> 8;
    break;
  case 3:
  case 4:
    uVar4 = *(uint *)(this + 0x14);
    break;
  case 5:
    uVar4 = (uint)(*(ushort *)(this + 0xc) >> 6);
    break;
  case 6:
    uVar4 = ((byte)this[0xe] & 3) * 0x4000 + (uint)(*(ushort *)(this + 0xe) >> 2);
    break;
  case 7:
    uVar4 = ((byte)this[0xe] & 3) * 0x4000 + (uint)(*(ushort *)(this + 0xe) >> 2) |
            (uint)(*(ushort *)(this + 0xc) >> 6) << 0x10;
    break;
  case 8:
    rVar1 = this[6];
    goto LAB_003a0b80;
  case 9:
    uVar4 = (uint)((byte)this[6] >> 5);
    break;
  case 10:
    uVar4 = (uint)(byte)this[4];
    goto LAB_003a0b98;
  case 0xb:
    uVar4 = (uint)((long)((ulong)(byte)this[7] << 0x38) >> 0x3c);
    break;
  case 0xc:
    if (((byte)this[7] & 0xf) != 1) {
LAB_003a0bd8:
      *param_4 = 0;
      return 0;
    }
    rVar1 = this[0x4c];
    uVar2 = *(ushort *)(this + 0x40);
    goto LAB_003a0bc8;
  case 0xd:
    if (((byte)this[7] & 0xf) != 1) goto LAB_003a0bd8;
    uVar4 = (uint)*(ushort *)(this + 0x42);
    uVar5 = (byte)this[0x4c] >> 1 & 1;
    goto LAB_003a0bfc;
  case 0xe:
    if (((byte)this[7] & 0xf) != 1) goto LAB_003a0bd8;
    uVar4 = (uint)*(ushort *)(this + 0x44);
    uVar5 = (byte)this[0x4c] >> 2 & 1;
    goto LAB_003a0bfc;
  case 0xf:
    if (((byte)this[7] & 0xf) != 1) goto LAB_003a0bd8;
    uVar4 = (uint)*(ushort *)(this + 0x46);
    uVar5 = (byte)this[0x4c] >> 3 & 1;
    goto LAB_003a0bfc;
  case 0x10:
    if (1 < (byte)(((byte)this[7] & 0xf) - 2)) goto LAB_003a0bd8;
    rVar1 = this[0x5c];
    uVar2 = *(ushort *)(this + 0x50);
LAB_003a0bc8:
    uVar4 = ((byte)rVar1 & 1) << 0x11 | (uint)uVar2;
    goto LAB_003a0bcc;
  case 0x11:
    if (1 < (byte)(((byte)this[7] & 0xf) - 2)) goto LAB_003a0bd8;
    uVar4 = (uint)*(ushort *)(this + 0x52);
    uVar5 = (byte)this[0x5c] >> 1 & 1;
    goto LAB_003a0bfc;
  case 0x12:
    if (1 < (byte)(((byte)this[7] & 0xf) - 2)) goto LAB_003a0bd8;
    uVar4 = (uint)*(ushort *)(this + 0x54);
    uVar5 = (byte)this[0x5c] >> 2 & 1;
    goto LAB_003a0bfc;
  case 0x13:
    if (1 < (byte)(((byte)this[7] & 0xf) - 2)) goto LAB_003a0bd8;
    uVar4 = (uint)*(ushort *)(this + 0x56);
    uVar5 = (byte)this[0x5c] >> 3 & 1;
LAB_003a0bfc:
    uVar4 = uVar4 | uVar5 << 0x11;
LAB_003a0bcc:
    uVar4 = (uint)(uVar4 != 0);
    break;
  case 0x14:
  case 0x15:
  case 0x4a:
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x4f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
    return 0x403;
  case 0x16:
    uVar6 = (ulong)(byte)this[6];
    goto LAB_003a0ce8;
  case 0x17:
    uVar4 = (uint)(byte)this[6];
    goto LAB_003a0b98;
  case 0x18:
    uVar4 = (uint)(byte)this[0x10];
    goto LAB_003a0b98;
  case 0x19:
  case 0x1a:
    uVar4 = *(uint *)(this + 0x1c);
    break;
  case 0x1b:
  case 0x2b:
    uVar6 = (ulong)(byte)this[0x5c];
    goto LAB_003a0d8c;
  case 0x1c:
    cVar3 = IsJpegExist(this);
    goto LAB_003a0d10;
  case 0x1d:
    cVar3 = IsJpegExist(this);
    goto LAB_003a0d40;
  case 0x1e:
    cVar3 = IsHeifExist(this);
LAB_003a0d10:
    uVar4 = 0;
    if (cVar3 != '\0') {
      uVar4 = (byte)this[0x5b] & 3 | ((byte)this[0x6e] >> 6 & 1) << 2;
    }
LAB_003a0d30:
    *param_4 = uVar4;
    return 0;
  case 0x1f:
    cVar3 = IsHeifExist(this);
LAB_003a0d40:
    uVar4 = 0;
    if (cVar3 != '\0') {
      rVar1 = this[0x5b];
LAB_003a0d50:
      uVar4 = (byte)rVar1 >> 2 & 3;
    }
    goto LAB_003a0d30;
  case 0x20:
    uVar5 = (uint)((byte)this[0x6e] >> 7);
    uVar4 = (byte)this[0x5b] >> 4 & 3;
    goto LAB_003a0d80;
  case 0x21:
    uVar6 = (ulong)(byte)this[0x5b];
    goto LAB_003a0d8c;
  case 0x22:
    uVar4 = (uint)(byte)this[0x5c];
    goto LAB_003a0d98;
  case 0x23:
    uVar5 = (byte)this[0x84] >> 4 & 1;
    uVar4 = (byte)this[0x6b] & 3;
    goto LAB_003a0d80;
  case 0x24:
    uVar5 = (byte)this[0x84] >> 5 & 1;
    uVar4 = (byte)this[0x6b] >> 2 & 3;
LAB_003a0d80:
    uVar4 = uVar4 | uVar5 << 2;
    break;
  case 0x25:
    uVar6 = (ulong)(byte)this[0x6b];
    goto LAB_003a0dcc;
  case 0x26:
    uVar6 = (ulong)(byte)this[0x6b];
    goto LAB_003a0d8c;
  case 0x27:
    cVar3 = IsJpegExist(this);
    goto LAB_003a0de4;
  case 0x28:
    cVar3 = IsJpegExist(this);
    goto LAB_003a0e00;
  case 0x29:
    cVar3 = IsHeifExist(this);
LAB_003a0de4:
    uVar4 = 0;
    if (cVar3 == '\0') goto LAB_003a0d30;
    rVar1 = this[0x5c];
    goto LAB_003a0d50;
  case 0x2a:
    cVar3 = IsHeifExist(this);
LAB_003a0e00:
    uVar4 = 0;
    if (cVar3 != '\0') {
      rVar1 = this[0x5c];
LAB_003a0e10:
      uVar4 = (byte)rVar1 >> 4 & 3;
    }
    goto LAB_003a0d30;
  case 0x2c:
    uVar4 = (uint)(byte)this[0x5d];
    goto LAB_003a0d98;
  case 0x2d:
    uVar6 = (ulong)(byte)this[0x5d];
    goto LAB_003a0e3c;
  case 0x2e:
    uVar4 = (uint)(byte)this[0x6c];
    goto LAB_003a0d98;
  case 0x2f:
    uVar6 = (ulong)(byte)this[0x6c];
    goto LAB_003a0e3c;
  case 0x30:
    uVar6 = (ulong)(byte)this[0x6c];
    goto LAB_003a0dcc;
  case 0x31:
    uVar6 = (ulong)(byte)this[0x6c];
    goto LAB_003a0d8c;
  case 0x32:
    uVar6 = (ulong)(byte)this[0x6f];
    goto LAB_003a0e3c;
  case 0x33:
    uVar6 = (ulong)(byte)this[0x6f];
    goto LAB_003a0dcc;
  case 0x34:
    cVar3 = IsJpegExist(this);
    goto LAB_003a0e7c;
  case 0x35:
    cVar3 = IsJpegExist(this);
    goto LAB_003a0e98;
  case 0x36:
    cVar3 = IsHeifExist(this);
LAB_003a0e7c:
    uVar4 = 0;
    if (cVar3 == '\0') goto LAB_003a0d30;
    rVar1 = this[0x5d];
    goto LAB_003a0e10;
  case 0x37:
    cVar3 = IsHeifExist(this);
LAB_003a0e98:
    uVar4 = 0;
    if (cVar3 != '\0') {
      uVar4 = (uint)((byte)this[0x5d] >> 6);
    }
    goto LAB_003a0d30;
  case 0x38:
    uVar4 = (uint)(byte)this[0x5e];
    goto LAB_003a0d98;
  case 0x39:
    uVar6 = (ulong)(byte)this[0x5e];
    goto LAB_003a0e3c;
  case 0x3a:
    uVar6 = (ulong)(byte)this[0x5e];
    goto LAB_003a0dcc;
  case 0x3b:
    uVar4 = (uint)(byte)this[0x6d];
LAB_003a0d98:
    uVar4 = uVar4 & 3;
    break;
  case 0x3c:
    uVar6 = (ulong)(byte)this[0x6d];
LAB_003a0e3c:
    uVar4 = (uint)(uVar6 >> 2) & 3;
    break;
  case 0x3d:
    uVar6 = (ulong)(byte)this[0x6d];
LAB_003a0dcc:
    uVar4 = (uint)(uVar6 >> 4) & 3;
    break;
  case 0x3e:
    uVar6 = (ulong)(byte)this[0x6d];
LAB_003a0d8c:
    uVar4 = (uint)(uVar6 >> 6);
    break;
  case 0x3f:
    uVar4 = (uint)(byte)this[0x6e];
    goto LAB_003a0b98;
  case 0x40:
    uVar6 = (ulong)(byte)this[0x6e];
    goto LAB_003a0ce8;
  case 0x41:
    uVar4 = (byte)this[0x6e] >> 2 & 1;
    break;
  case 0x42:
    uVar4 = (byte)this[0x6e] >> 3 & 1;
    break;
  case 0x43:
    rVar1 = this[0x6e];
LAB_003a0b80:
    uVar4 = (byte)rVar1 >> 4 & 1;
    break;
  case 0x44:
    uVar4 = (byte)this[0x6e] >> 5 & 1;
    break;
  case 0x45:
    uVar6 = (ulong)(byte)this[0x6e];
    goto LAB_003a0ee4;
  case 0x46:
    rVar1 = this[0x6e];
    goto LAB_003a0ef0;
  case 0x47:
    uVar4 = (uint)(byte)this[0x6f];
LAB_003a0b98:
    uVar4 = uVar4 & 1;
    break;
  case 0x48:
    uVar6 = (ulong)(byte)this[0x6f];
LAB_003a0ce8:
    uVar4 = (uint)(uVar6 >> 1) & 1;
    break;
  case 0x49:
    uVar6 = (ulong)(byte)this[0x6f];
    goto LAB_003a0ee4;
  case 0x59:
    uVar6 = (ulong)(byte)this[0x5e];
LAB_003a0ee4:
    uVar4 = (uint)(uVar6 >> 6) & 1;
    break;
  case 0x5a:
    rVar1 = this[0x5e];
LAB_003a0ef0:
    uVar4 = (uint)((byte)rVar1 >> 7);
    break;
  default:
    goto switchD_003a0ae0_default;
  }
  *param_4 = uVar4;
  return 0;
}

