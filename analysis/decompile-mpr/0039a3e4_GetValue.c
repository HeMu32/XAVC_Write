// sidb::recordStructureWithFunc<bool>::GetValue
// Ghidra address: 0039a3e4

/* sidb::recordStructureWithFunc<bool>::GetValue(sidb::COL_ID, unsigned int, bool*) */

undefined8 __thiscall
sidb::recordStructureWithFunc<bool>::GetValue
          (recordStructureWithFunc<bool> *this,undefined4 param_2,int param_3,undefined1 *param_4)

{
  int iVar1;
  ushort uVar2;
  bool bVar3;
  recordStructureWithFunc<bool> rVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  
  if (param_4 == (undefined1 *)0x0) {
switchD_0039a418_default:
    return 0x403;
  }
  switch(param_2) {
  case 0:
    uVar6 = ContentTypeInternal2ContentType((byte)this[7] & 0xf);
    goto LAB_0039a428;
  case 1:
    bVar3 = param_3 == 0 && *(ushort *)(this + 4) >> 1 == 0;
    goto LAB_0039a440;
  case 2:
    bVar3 = (*(uint *)(this + 8) & 0xffffff00) == 0;
    goto LAB_0039a450;
  case 3:
  case 4:
    iVar1 = *(int *)(this + 0x14);
    uVar6 = *(uint *)(this + 0x10) >> 0xc;
    goto LAB_0039a460;
  case 5:
    bVar3 = (*(ushort *)(this + 0xc) & 0xffc0) == 0;
    goto LAB_0039a450;
  case 6:
    uVar6 = ((byte)this[0xe] & 3) * 0x4000 + (uint)(*(ushort *)(this + 0xe) >> 2);
    goto LAB_0039a428;
  case 7:
    uVar6 = ((byte)this[0xe] & 3) * 0x4000 + (uint)(*(ushort *)(this + 0xe) >> 2) |
            (uint)(*(ushort *)(this + 0xc) >> 6) << 0x10;
    goto LAB_0039a428;
  case 8:
    rVar4 = this[6];
    goto LAB_0039a4c0;
  case 9:
    bVar3 = ((byte)this[6] & 0xe0) == 0;
    goto LAB_0039a450;
  case 10:
    rVar4 = this[4];
    goto LAB_0039a4d8;
  case 0xb:
    bVar3 = ((byte)this[7] & 0xf0) == 0;
    goto LAB_0039a450;
  case 0xc:
    if (((byte)this[7] & 0xf) != 1) {
LAB_0039a510:
      *param_4 = 0;
      return 0;
    }
    rVar4 = this[0x4c];
    uVar2 = *(ushort *)(this + 0x40);
    goto LAB_0039a508;
  case 0xd:
    if (((byte)this[7] & 0xf) != 1) goto LAB_0039a510;
    uVar6 = (uint)*(ushort *)(this + 0x42);
    uVar7 = (byte)this[0x4c] >> 1 & 1;
    goto LAB_0039a540;
  case 0xe:
    if (((byte)this[7] & 0xf) != 1) goto LAB_0039a510;
    uVar6 = (uint)*(ushort *)(this + 0x44);
    uVar7 = (byte)this[0x4c] >> 2 & 1;
    goto LAB_0039a540;
  case 0xf:
    if (((byte)this[7] & 0xf) != 1) goto LAB_0039a510;
    uVar6 = (uint)*(ushort *)(this + 0x46);
    uVar7 = (byte)this[0x4c] >> 3 & 1;
    goto LAB_0039a540;
  case 0x10:
    if (1 < (byte)(((byte)this[7] & 0xf) - 2)) goto LAB_0039a510;
    rVar4 = this[0x5c];
    uVar2 = *(ushort *)(this + 0x50);
LAB_0039a508:
    uVar6 = ((byte)rVar4 & 1) << 0x11 | (uint)uVar2;
    goto LAB_0039a428;
  case 0x11:
    if (1 < (byte)(((byte)this[7] & 0xf) - 2)) goto LAB_0039a510;
    uVar6 = (uint)*(ushort *)(this + 0x52);
    uVar7 = (byte)this[0x5c] >> 1 & 1;
    goto LAB_0039a540;
  case 0x12:
    if (1 < (byte)(((byte)this[7] & 0xf) - 2)) goto LAB_0039a510;
    uVar6 = (uint)*(ushort *)(this + 0x54);
    uVar7 = (byte)this[0x5c] >> 2 & 1;
    goto LAB_0039a540;
  case 0x13:
    if (1 < (byte)(((byte)this[7] & 0xf) - 2)) goto LAB_0039a510;
    uVar6 = (uint)*(ushort *)(this + 0x56);
    uVar7 = (byte)this[0x5c] >> 3 & 1;
LAB_0039a540:
    uVar6 = uVar6 | uVar7 << 0x11;
LAB_0039a428:
    bVar3 = uVar6 == 0;
LAB_0039a440:
    bVar3 = !bVar3;
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
    goto LAB_0039a62c;
  case 0x17:
    rVar4 = this[6];
    goto LAB_0039a4d8;
  case 0x18:
    bVar3 = (bool)((byte)this[0x10] & 1);
    break;
  case 0x19:
  case 0x1a:
    iVar1 = *(int *)(this + 0x1c);
    uVar6 = *(uint *)(this + 0x18) >> 0xc & 0xfff;
LAB_0039a460:
    bVar3 = iVar1 == 0 && (uVar6 & 0xfff) == 0;
    goto LAB_0039a440;
  case 0x1b:
  case 0x2b:
    rVar4 = this[0x5c];
    goto LAB_0039a6cc;
  case 0x1c:
    cVar5 = IsJpegExist(this);
    goto LAB_0039a660;
  case 0x1d:
    cVar5 = IsJpegExist(this);
    goto LAB_0039a684;
  case 0x1e:
    cVar5 = IsHeifExist(this);
LAB_0039a660:
    bVar3 = false;
    if (cVar5 == '\0') break;
    rVar4 = this[0x5b];
    uVar7 = (uint)((byte)this[0x6e] >> 6);
LAB_0039a674:
    uVar7 = uVar7 & 1;
    uVar6 = (byte)rVar4 & 3;
    goto LAB_0039a6c0;
  case 0x1f:
    cVar5 = IsHeifExist(this);
LAB_0039a684:
    bVar3 = false;
    if (cVar5 == '\0') break;
    rVar4 = this[0x5b];
    goto LAB_0039a690;
  case 0x20:
    uVar7 = (uint)((byte)this[0x6e] >> 7);
    uVar6 = (byte)this[0x5b] >> 4 & 3;
    goto LAB_0039a6c0;
  case 0x21:
    rVar4 = this[0x5b];
    goto LAB_0039a6cc;
  case 0x22:
    rVar4 = this[0x5c];
    goto LAB_0039a6d8;
  case 0x23:
    rVar4 = this[0x6b];
    uVar7 = (byte)this[0x84] >> 4 & 1;
    goto LAB_0039a674;
  case 0x24:
    uVar7 = (byte)this[0x84] >> 5 & 1;
    uVar6 = (byte)this[0x6b] >> 2 & 3;
LAB_0039a6c0:
    uVar6 = uVar6 | uVar7 << 2;
    goto LAB_0039a428;
  case 0x25:
    rVar4 = this[0x6b];
    goto LAB_0039a708;
  case 0x26:
    rVar4 = this[0x6b];
    goto LAB_0039a6cc;
  case 0x27:
    cVar5 = IsJpegExist(this);
    goto LAB_0039a720;
  case 0x28:
    cVar5 = IsJpegExist(this);
    goto LAB_0039a738;
  case 0x29:
    cVar5 = IsHeifExist(this);
LAB_0039a720:
    bVar3 = false;
    if (cVar5 == '\0') break;
    rVar4 = this[0x5c];
    goto LAB_0039a690;
  case 0x2a:
    cVar5 = IsHeifExist(this);
LAB_0039a738:
    bVar3 = false;
    if (cVar5 == '\0') break;
    rVar4 = this[0x5c];
    goto LAB_0039a708;
  case 0x2c:
    rVar4 = this[0x5d];
    goto LAB_0039a6d8;
  case 0x2d:
    rVar4 = this[0x5d];
    goto LAB_0039a690;
  case 0x2e:
    rVar4 = this[0x6c];
    goto LAB_0039a6d8;
  case 0x2f:
    rVar4 = this[0x6c];
    goto LAB_0039a690;
  case 0x30:
    rVar4 = this[0x6c];
    goto LAB_0039a708;
  case 0x31:
    rVar4 = this[0x6c];
    goto LAB_0039a6cc;
  case 0x32:
    rVar4 = this[0x6f];
    goto LAB_0039a690;
  case 0x33:
    rVar4 = this[0x6f];
    goto LAB_0039a708;
  case 0x34:
    cVar5 = IsJpegExist(this);
    goto LAB_0039a7a8;
  case 0x35:
    cVar5 = IsJpegExist(this);
    goto LAB_0039a7c0;
  case 0x36:
    cVar5 = IsHeifExist(this);
LAB_0039a7a8:
    bVar3 = false;
    if (cVar5 == '\0') break;
    rVar4 = this[0x5d];
    goto LAB_0039a708;
  case 0x37:
    cVar5 = IsHeifExist(this);
LAB_0039a7c0:
    bVar3 = false;
    if (cVar5 == '\0') break;
    rVar4 = this[0x5d];
    goto LAB_0039a6cc;
  case 0x38:
    rVar4 = this[0x5e];
    goto LAB_0039a6d8;
  case 0x39:
    rVar4 = this[0x5e];
    goto LAB_0039a690;
  case 0x3a:
    rVar4 = this[0x5e];
    goto LAB_0039a708;
  case 0x3b:
    rVar4 = this[0x6d];
LAB_0039a6d8:
    bVar3 = ((byte)rVar4 & 3) == 0;
    goto LAB_0039a450;
  case 0x3c:
    rVar4 = this[0x6d];
LAB_0039a690:
    bVar3 = ((byte)rVar4 & 0xc) == 0;
LAB_0039a450:
    bVar3 = !bVar3;
    break;
  case 0x3d:
    rVar4 = this[0x6d];
LAB_0039a708:
    bVar3 = ((byte)rVar4 & 0x30) == 0;
    goto LAB_0039a450;
  case 0x3e:
    rVar4 = this[0x6d];
LAB_0039a6cc:
    bVar3 = ((byte)rVar4 & 0xc0) == 0;
    goto LAB_0039a450;
  case 0x3f:
    rVar4 = this[0x6e];
    goto LAB_0039a4d8;
  case 0x40:
    uVar8 = (ulong)(byte)this[0x6e];
    goto LAB_0039a62c;
  case 0x41:
    bVar3 = (bool)((byte)this[0x6e] >> 2 & 1);
    break;
  case 0x42:
    bVar3 = (bool)((byte)this[0x6e] >> 3 & 1);
    break;
  case 0x43:
    rVar4 = this[0x6e];
LAB_0039a4c0:
    bVar3 = (bool)((byte)rVar4 >> 4 & 1);
    break;
  case 0x44:
    bVar3 = (bool)((byte)this[0x6e] >> 5 & 1);
    break;
  case 0x45:
    uVar8 = (ulong)(byte)this[0x6e];
    goto LAB_0039a804;
  case 0x46:
    rVar4 = this[0x6e];
    goto LAB_0039a810;
  case 0x47:
    rVar4 = this[0x6f];
LAB_0039a4d8:
    bVar3 = (bool)((byte)rVar4 & 1);
    break;
  case 0x48:
    uVar8 = (ulong)(byte)this[0x6f];
LAB_0039a62c:
    bVar3 = (bool)((byte)(uVar8 >> 1) & 1);
    break;
  case 0x49:
    uVar8 = (ulong)(byte)this[0x6f];
    goto LAB_0039a804;
  case 0x59:
    uVar8 = (ulong)(byte)this[0x5e];
LAB_0039a804:
    bVar3 = (bool)((byte)(uVar8 >> 6) & 1);
    break;
  case 0x5a:
    rVar4 = this[0x5e];
LAB_0039a810:
    bVar3 = (bool)((byte)rVar4 >> 7);
    break;
  default:
    goto switchD_0039a418_default;
  }
  *param_4 = bVar3;
  return 0;
}

