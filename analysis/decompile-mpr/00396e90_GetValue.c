// sidb::recordStructureWithFunc<unsigned_short>::GetValue
// Ghidra address: 00396e90

/* sidb::recordStructureWithFunc<unsigned short>::GetValue(sidb::COL_ID, unsigned int, unsigned
   short*) */

undefined8 __thiscall
sidb::recordStructureWithFunc<unsigned_short>::GetValue
          (recordStructureWithFunc<unsigned_short> *this,undefined4 param_2,ushort param_3,
          ushort *param_4)

{
  recordStructureWithFunc<unsigned_short> rVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  
  if (param_4 == (ushort *)0x0) {
switchD_00396ec4_default:
    return 0x403;
  }
  switch(param_2) {
  case 0:
    uVar3 = ContentTypeInternal2ContentType((byte)this[7] & 0xf);
    break;
  case 1:
    *param_4 = param_3;
    return 0;
  case 2:
    uVar3 = (ushort)((uint)*(undefined4 *)(this + 8) >> 8);
    break;
  case 3:
  case 4:
    uVar3 = (ushort)*(undefined4 *)(this + 0x14);
    break;
  case 5:
    uVar3 = *(ushort *)(this + 0xc) >> 6;
    break;
  case 6:
  case 7:
    uVar3 = (ushort)(byte)this[0xe] * 0x4000 + (*(ushort *)(this + 0xe) >> 2);
    break;
  case 8:
    rVar1 = this[6];
    goto LAB_00396f2c;
  case 9:
    uVar3 = (ushort)((byte)this[6] >> 5);
    break;
  case 10:
    uVar3 = (ushort)(byte)this[4];
    goto LAB_00396f48;
  case 0xb:
    uVar3 = (ushort)((long)((ulong)(byte)this[7] << 0x38) >> 0x3c);
    break;
  case 0xc:
    if (((byte)this[7] & 0xf) != 1) {
LAB_00396f88:
      *param_4 = 0;
      return 0;
    }
    rVar1 = this[0x4c];
    uVar3 = *(ushort *)(this + 0x40);
    goto LAB_00396f78;
  case 0xd:
    if (((byte)this[7] & 0xf) != 1) goto LAB_00396f88;
    uVar5 = (uint)*(ushort *)(this + 0x42);
    uVar6 = (byte)this[0x4c] >> 1 & 1;
    goto LAB_00396fac;
  case 0xe:
    if (((byte)this[7] & 0xf) != 1) goto LAB_00396f88;
    uVar5 = (uint)*(ushort *)(this + 0x44);
    uVar6 = (byte)this[0x4c] >> 2 & 1;
    goto LAB_00396fac;
  case 0xf:
    if (((byte)this[7] & 0xf) != 1) goto LAB_00396f88;
    uVar5 = (uint)*(ushort *)(this + 0x46);
    uVar6 = (byte)this[0x4c] >> 3 & 1;
    goto LAB_00396fac;
  case 0x10:
    if (1 < (byte)(((byte)this[7] & 0xf) - 2)) goto LAB_00396f88;
    rVar1 = this[0x5c];
    uVar3 = *(ushort *)(this + 0x50);
LAB_00396f78:
    uVar5 = ((byte)rVar1 & 1) << 0x11 | (uint)uVar3;
    goto LAB_00396f7c;
  case 0x11:
    if (1 < (byte)(((byte)this[7] & 0xf) - 2)) goto LAB_00396f88;
    uVar5 = (uint)*(ushort *)(this + 0x52);
    uVar6 = (byte)this[0x5c] >> 1 & 1;
    goto LAB_00396fac;
  case 0x12:
    if (1 < (byte)(((byte)this[7] & 0xf) - 2)) goto LAB_00396f88;
    uVar5 = (uint)*(ushort *)(this + 0x54);
    uVar6 = (byte)this[0x5c] >> 2 & 1;
    goto LAB_00396fac;
  case 0x13:
    if (1 < (byte)(((byte)this[7] & 0xf) - 2)) goto LAB_00396f88;
    uVar5 = (uint)*(ushort *)(this + 0x56);
    uVar6 = (byte)this[0x5c] >> 3 & 1;
LAB_00396fac:
    uVar5 = uVar5 | uVar6 << 0x11;
LAB_00396f7c:
    uVar3 = (ushort)(uVar5 != 0);
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
    uVar7 = (ulong)(byte)this[6];
    goto LAB_00397098;
  case 0x17:
    uVar3 = (ushort)(byte)this[6];
    goto LAB_00396f48;
  case 0x18:
    uVar3 = (ushort)(byte)this[0x10];
    goto LAB_00396f48;
  case 0x19:
  case 0x1a:
    uVar3 = (ushort)*(undefined4 *)(this + 0x1c);
    break;
  case 0x1b:
  case 0x2b:
    uVar7 = (ulong)(byte)this[0x5c];
    goto LAB_00397148;
  case 0x1c:
    cVar2 = IsJpegExist(this);
    goto LAB_003970c0;
  case 0x1d:
    cVar2 = IsJpegExist(this);
    goto LAB_003970f8;
  case 0x1e:
    cVar2 = IsHeifExist(this);
LAB_003970c0:
    uVar3 = 0;
    if (cVar2 != '\0') {
      uVar3 = (byte)this[0x5b] & 3 | ((byte)this[0x6e] >> 6 & 1) << 2;
    }
LAB_003970e8:
    *param_4 = uVar3;
    return 0;
  case 0x1f:
    cVar2 = IsHeifExist(this);
LAB_003970f8:
    uVar3 = 0;
    if (cVar2 != '\0') {
      rVar1 = this[0x5b];
LAB_00397108:
      uVar3 = (byte)rVar1 >> 2 & 3;
    }
    goto LAB_003970e8;
  case 0x20:
    uVar4 = (ushort)((byte)this[0x6e] >> 7);
    uVar3 = (byte)this[0x5b] >> 4 & 3;
    goto LAB_00397138;
  case 0x21:
    uVar7 = (ulong)(byte)this[0x5b];
    goto LAB_00397148;
  case 0x22:
    uVar3 = (ushort)(byte)this[0x5c];
    goto LAB_00397154;
  case 0x23:
    uVar4 = (byte)this[0x84] >> 4 & 1;
    uVar3 = (byte)this[0x6b] & 3;
    goto LAB_00397138;
  case 0x24:
    uVar4 = (byte)this[0x84] >> 5 & 1;
    uVar3 = (byte)this[0x6b] >> 2 & 3;
LAB_00397138:
    uVar3 = uVar3 | uVar4 << 2;
    break;
  case 0x25:
    uVar7 = (ulong)(byte)this[0x6b];
    goto LAB_00397188;
  case 0x26:
    uVar7 = (ulong)(byte)this[0x6b];
    goto LAB_00397148;
  case 0x27:
    cVar2 = IsJpegExist(this);
    goto LAB_003971a0;
  case 0x28:
    cVar2 = IsJpegExist(this);
    goto LAB_003971bc;
  case 0x29:
    cVar2 = IsHeifExist(this);
LAB_003971a0:
    uVar3 = 0;
    if (cVar2 == '\0') goto LAB_003970e8;
    rVar1 = this[0x5c];
    goto LAB_00397108;
  case 0x2a:
    cVar2 = IsHeifExist(this);
LAB_003971bc:
    uVar3 = 0;
    if (cVar2 != '\0') {
      rVar1 = this[0x5c];
LAB_003971cc:
      uVar3 = (byte)rVar1 >> 4 & 3;
    }
    goto LAB_003970e8;
  case 0x2c:
    uVar3 = (ushort)(byte)this[0x5d];
    goto LAB_00397154;
  case 0x2d:
    uVar7 = (ulong)(byte)this[0x5d];
    goto LAB_003971f8;
  case 0x2e:
    uVar3 = (ushort)(byte)this[0x6c];
    goto LAB_00397154;
  case 0x2f:
    uVar7 = (ulong)(byte)this[0x6c];
    goto LAB_003971f8;
  case 0x30:
    uVar7 = (ulong)(byte)this[0x6c];
    goto LAB_00397188;
  case 0x31:
    uVar7 = (ulong)(byte)this[0x6c];
    goto LAB_00397148;
  case 0x32:
    uVar7 = (ulong)(byte)this[0x6f];
    goto LAB_003971f8;
  case 0x33:
    uVar7 = (ulong)(byte)this[0x6f];
    goto LAB_00397188;
  case 0x34:
    cVar2 = IsJpegExist(this);
    goto LAB_00397238;
  case 0x35:
    cVar2 = IsJpegExist(this);
    goto LAB_00397254;
  case 0x36:
    cVar2 = IsHeifExist(this);
LAB_00397238:
    uVar3 = 0;
    if (cVar2 == '\0') goto LAB_003970e8;
    rVar1 = this[0x5d];
    goto LAB_003971cc;
  case 0x37:
    cVar2 = IsHeifExist(this);
LAB_00397254:
    uVar3 = 0;
    if (cVar2 != '\0') {
      uVar3 = (ushort)((byte)this[0x5d] >> 6);
    }
    goto LAB_003970e8;
  case 0x38:
    uVar3 = (ushort)(byte)this[0x5e];
    goto LAB_00397154;
  case 0x39:
    uVar7 = (ulong)(byte)this[0x5e];
    goto LAB_003971f8;
  case 0x3a:
    uVar7 = (ulong)(byte)this[0x5e];
    goto LAB_00397188;
  case 0x3b:
    uVar3 = (ushort)(byte)this[0x6d];
LAB_00397154:
    uVar3 = uVar3 & 3;
    break;
  case 0x3c:
    uVar7 = (ulong)(byte)this[0x6d];
LAB_003971f8:
    uVar3 = (ushort)(uVar7 >> 2) & 3;
    break;
  case 0x3d:
    uVar7 = (ulong)(byte)this[0x6d];
LAB_00397188:
    uVar3 = (ushort)(uVar7 >> 4) & 3;
    break;
  case 0x3e:
    uVar7 = (ulong)(byte)this[0x6d];
LAB_00397148:
    uVar3 = (ushort)(uVar7 >> 6);
    break;
  case 0x3f:
    uVar3 = (ushort)(byte)this[0x6e];
    goto LAB_00396f48;
  case 0x40:
    uVar7 = (ulong)(byte)this[0x6e];
    goto LAB_00397098;
  case 0x41:
    uVar3 = (byte)this[0x6e] >> 2 & 1;
    break;
  case 0x42:
    uVar3 = (byte)this[0x6e] >> 3 & 1;
    break;
  case 0x43:
    rVar1 = this[0x6e];
LAB_00396f2c:
    uVar3 = (byte)rVar1 >> 4 & 1;
    break;
  case 0x44:
    uVar3 = (byte)this[0x6e] >> 5 & 1;
    break;
  case 0x45:
    uVar7 = (ulong)(byte)this[0x6e];
    goto LAB_003972a0;
  case 0x46:
    rVar1 = this[0x6e];
    goto LAB_003972ac;
  case 0x47:
    uVar3 = (ushort)(byte)this[0x6f];
LAB_00396f48:
    uVar3 = uVar3 & 1;
    break;
  case 0x48:
    uVar7 = (ulong)(byte)this[0x6f];
LAB_00397098:
    uVar3 = (ushort)(uVar7 >> 1) & 1;
    break;
  case 0x49:
    uVar7 = (ulong)(byte)this[0x6f];
    goto LAB_003972a0;
  case 0x59:
    uVar7 = (ulong)(byte)this[0x5e];
LAB_003972a0:
    uVar3 = (ushort)(uVar7 >> 6) & 1;
    break;
  case 0x5a:
    rVar1 = this[0x5e];
LAB_003972ac:
    uVar3 = (ushort)((byte)rVar1 >> 7);
    break;
  default:
    goto switchD_00396ec4_default;
  }
  *param_4 = uVar3;
  return 0;
}

