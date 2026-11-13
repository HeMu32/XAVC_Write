// sidb::recordStructureWithFunc<signed_char>::GetValue
// Ghidra address: 0039d82c

/* sidb::recordStructureWithFunc<signed char>::GetValue(sidb::COL_ID, unsigned int, signed char*) */

undefined8 __thiscall
sidb::recordStructureWithFunc<signed_char>::GetValue
          (recordStructureWithFunc<signed_char> *this,undefined4 param_2,byte param_3,byte *param_4)

{
  ushort uVar1;
  byte bVar2;
  recordStructureWithFunc<signed_char> rVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  
  if (param_4 == (byte *)0x0) {
switchD_0039d860_default:
    return 0x403;
  }
  switch(param_2) {
  case 0:
    bVar2 = ContentTypeInternal2ContentType((byte)this[7] & 0xf);
    break;
  case 1:
    *param_4 = param_3;
    return 0;
  case 2:
    bVar2 = (byte)((uint)*(undefined4 *)(this + 8) >> 8);
    break;
  case 3:
  case 4:
    bVar2 = (byte)*(undefined4 *)(this + 0x14);
    break;
  case 5:
    bVar2 = (byte)(*(ushort *)(this + 0xc) >> 6);
    break;
  case 6:
  case 7:
    bVar2 = (byte)(*(ushort *)(this + 0xe) >> 2);
    break;
  case 8:
    rVar3 = this[6];
    goto LAB_0039d8bc;
  case 9:
    bVar2 = (byte)this[6] >> 5;
    break;
  case 10:
    rVar3 = this[4];
    goto LAB_0039d8d4;
  case 0xb:
    bVar2 = (char)this[7] >> 4;
    break;
  case 0xc:
    if (((byte)this[7] & 0xf) != 1) {
LAB_0039d914:
      *param_4 = 0;
      return 0;
    }
    rVar3 = this[0x4c];
    uVar1 = *(ushort *)(this + 0x40);
    goto LAB_0039d904;
  case 0xd:
    if (((byte)this[7] & 0xf) != 1) goto LAB_0039d914;
    uVar6 = (uint)*(ushort *)(this + 0x42);
    uVar7 = (byte)this[0x4c] >> 1 & 1;
    goto LAB_0039d938;
  case 0xe:
    if (((byte)this[7] & 0xf) != 1) goto LAB_0039d914;
    uVar6 = (uint)*(ushort *)(this + 0x44);
    uVar7 = (byte)this[0x4c] >> 2 & 1;
    goto LAB_0039d938;
  case 0xf:
    if (((byte)this[7] & 0xf) != 1) goto LAB_0039d914;
    uVar6 = (uint)*(ushort *)(this + 0x46);
    uVar7 = (byte)this[0x4c] >> 3 & 1;
    goto LAB_0039d938;
  case 0x10:
    if (1 < (byte)(((byte)this[7] & 0xf) - 2)) goto LAB_0039d914;
    rVar3 = this[0x5c];
    uVar1 = *(ushort *)(this + 0x50);
LAB_0039d904:
    uVar6 = ((byte)rVar3 & 1) << 0x11 | (uint)uVar1;
    goto LAB_0039d908;
  case 0x11:
    if (1 < (byte)(((byte)this[7] & 0xf) - 2)) goto LAB_0039d914;
    uVar6 = (uint)*(ushort *)(this + 0x52);
    uVar7 = (byte)this[0x5c] >> 1 & 1;
    goto LAB_0039d938;
  case 0x12:
    if (1 < (byte)(((byte)this[7] & 0xf) - 2)) goto LAB_0039d914;
    uVar6 = (uint)*(ushort *)(this + 0x54);
    uVar7 = (byte)this[0x5c] >> 2 & 1;
    goto LAB_0039d938;
  case 0x13:
    if (1 < (byte)(((byte)this[7] & 0xf) - 2)) goto LAB_0039d914;
    uVar6 = (uint)*(ushort *)(this + 0x56);
    uVar7 = (byte)this[0x5c] >> 3 & 1;
LAB_0039d938:
    uVar6 = uVar6 | uVar7 << 0x11;
LAB_0039d908:
    bVar2 = uVar6 != 0;
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
    uVar8 = (ulong)(byte)this[6];
    goto LAB_0039da24;
  case 0x17:
    rVar3 = this[6];
    goto LAB_0039d8d4;
  case 0x18:
    rVar3 = this[0x10];
    goto LAB_0039d8d4;
  case 0x19:
  case 0x1a:
    bVar2 = (byte)*(undefined4 *)(this + 0x1c);
    break;
  case 0x1b:
  case 0x2b:
    uVar8 = (ulong)(byte)this[0x5c];
    goto LAB_0039dacc;
  case 0x1c:
    cVar5 = IsJpegExist(this);
    goto LAB_0039da4c;
  case 0x1d:
    cVar5 = IsJpegExist(this);
    goto LAB_0039da80;
  case 0x1e:
    cVar5 = IsHeifExist(this);
LAB_0039da4c:
    bVar2 = 0;
    if (cVar5 != '\0') {
      bVar2 = (byte)this[0x5b] & 3 | ((byte)this[0x6e] >> 6 & 1) << 2;
    }
LAB_0039da70:
    *param_4 = bVar2;
    return 0;
  case 0x1f:
    cVar5 = IsHeifExist(this);
LAB_0039da80:
    bVar2 = 0;
    if (cVar5 != '\0') {
      rVar3 = this[0x5b];
LAB_0039da90:
      bVar2 = (byte)rVar3 >> 2 & 3;
    }
    goto LAB_0039da70;
  case 0x20:
    bVar4 = (byte)this[0x6e] >> 7;
    bVar2 = (byte)this[0x5b] >> 4 & 3;
    goto LAB_0039dac0;
  case 0x21:
    uVar8 = (ulong)(byte)this[0x5b];
    goto LAB_0039dacc;
  case 0x22:
    rVar3 = this[0x5c];
    goto LAB_0039dad8;
  case 0x23:
    bVar4 = (byte)this[0x84] >> 4 & 1;
    bVar2 = (byte)this[0x6b] & 3;
    goto LAB_0039dac0;
  case 0x24:
    bVar4 = (byte)this[0x84] >> 5 & 1;
    bVar2 = (byte)this[0x6b] >> 2 & 3;
LAB_0039dac0:
    bVar2 = bVar2 | bVar4 << 2;
    break;
  case 0x25:
    uVar8 = (ulong)(byte)this[0x6b];
    goto LAB_0039db0c;
  case 0x26:
    uVar8 = (ulong)(byte)this[0x6b];
    goto LAB_0039dacc;
  case 0x27:
    cVar5 = IsJpegExist(this);
    goto LAB_0039db24;
  case 0x28:
    cVar5 = IsJpegExist(this);
    goto LAB_0039db40;
  case 0x29:
    cVar5 = IsHeifExist(this);
LAB_0039db24:
    bVar2 = 0;
    if (cVar5 == '\0') goto LAB_0039da70;
    rVar3 = this[0x5c];
    goto LAB_0039da90;
  case 0x2a:
    cVar5 = IsHeifExist(this);
LAB_0039db40:
    bVar2 = 0;
    if (cVar5 != '\0') {
      rVar3 = this[0x5c];
LAB_0039db50:
      bVar2 = (byte)rVar3 >> 4 & 3;
    }
    goto LAB_0039da70;
  case 0x2c:
    rVar3 = this[0x5d];
    goto LAB_0039dad8;
  case 0x2d:
    uVar8 = (ulong)(byte)this[0x5d];
    goto LAB_0039db7c;
  case 0x2e:
    rVar3 = this[0x6c];
    goto LAB_0039dad8;
  case 0x2f:
    uVar8 = (ulong)(byte)this[0x6c];
    goto LAB_0039db7c;
  case 0x30:
    uVar8 = (ulong)(byte)this[0x6c];
    goto LAB_0039db0c;
  case 0x31:
    uVar8 = (ulong)(byte)this[0x6c];
    goto LAB_0039dacc;
  case 0x32:
    uVar8 = (ulong)(byte)this[0x6f];
    goto LAB_0039db7c;
  case 0x33:
    uVar8 = (ulong)(byte)this[0x6f];
    goto LAB_0039db0c;
  case 0x34:
    cVar5 = IsJpegExist(this);
    goto LAB_0039dbbc;
  case 0x35:
    cVar5 = IsJpegExist(this);
    goto LAB_0039dbd8;
  case 0x36:
    cVar5 = IsHeifExist(this);
LAB_0039dbbc:
    bVar2 = 0;
    if (cVar5 == '\0') goto LAB_0039da70;
    rVar3 = this[0x5d];
    goto LAB_0039db50;
  case 0x37:
    cVar5 = IsHeifExist(this);
LAB_0039dbd8:
    bVar2 = 0;
    if (cVar5 != '\0') {
      bVar2 = (byte)this[0x5d] >> 6;
    }
    goto LAB_0039da70;
  case 0x38:
    rVar3 = this[0x5e];
    goto LAB_0039dad8;
  case 0x39:
    uVar8 = (ulong)(byte)this[0x5e];
    goto LAB_0039db7c;
  case 0x3a:
    uVar8 = (ulong)(byte)this[0x5e];
    goto LAB_0039db0c;
  case 0x3b:
    rVar3 = this[0x6d];
LAB_0039dad8:
    bVar2 = (byte)rVar3 & 3;
    break;
  case 0x3c:
    uVar8 = (ulong)(byte)this[0x6d];
LAB_0039db7c:
    bVar2 = (byte)(uVar8 >> 2) & 3;
    break;
  case 0x3d:
    uVar8 = (ulong)(byte)this[0x6d];
LAB_0039db0c:
    bVar2 = (byte)(uVar8 >> 4) & 3;
    break;
  case 0x3e:
    uVar8 = (ulong)(byte)this[0x6d];
LAB_0039dacc:
    bVar2 = (byte)(uVar8 >> 6);
    break;
  case 0x3f:
    rVar3 = this[0x6e];
    goto LAB_0039d8d4;
  case 0x40:
    uVar8 = (ulong)(byte)this[0x6e];
    goto LAB_0039da24;
  case 0x41:
    bVar2 = (byte)this[0x6e] >> 2 & 1;
    break;
  case 0x42:
    bVar2 = (byte)this[0x6e] >> 3 & 1;
    break;
  case 0x43:
    rVar3 = this[0x6e];
LAB_0039d8bc:
    bVar2 = (byte)rVar3 >> 4 & 1;
    break;
  case 0x44:
    bVar2 = (byte)this[0x6e] >> 5 & 1;
    break;
  case 0x45:
    uVar8 = (ulong)(byte)this[0x6e];
    goto LAB_0039dc24;
  case 0x46:
    rVar3 = this[0x6e];
    goto LAB_0039dc30;
  case 0x47:
    rVar3 = this[0x6f];
LAB_0039d8d4:
    bVar2 = (byte)rVar3 & 1;
    break;
  case 0x48:
    uVar8 = (ulong)(byte)this[0x6f];
LAB_0039da24:
    bVar2 = (byte)(uVar8 >> 1) & 1;
    break;
  case 0x49:
    uVar8 = (ulong)(byte)this[0x6f];
    goto LAB_0039dc24;
  case 0x59:
    uVar8 = (ulong)(byte)this[0x5e];
LAB_0039dc24:
    bVar2 = (byte)(uVar8 >> 6) & 1;
    break;
  case 0x5a:
    rVar3 = this[0x5e];
LAB_0039dc30:
    bVar2 = (byte)rVar3 >> 7;
    break;
  default:
    goto switchD_0039d860_default;
  }
  *param_4 = bVar2;
  return 0;
}

