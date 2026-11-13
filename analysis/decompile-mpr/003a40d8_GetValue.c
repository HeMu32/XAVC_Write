// sidb::recordStructureWithFunc<unsigned_long>::GetValue
// Ghidra address: 003a40d8

/* sidb::recordStructureWithFunc<unsigned long>::GetValue(sidb::COL_ID, unsigned int, unsigned
   long*) */

undefined8 __thiscall
sidb::recordStructureWithFunc<unsigned_long>::GetValue
          (recordStructureWithFunc<unsigned_long> *this,undefined4 param_2,uint param_3,
          ulong *param_4)

{
  recordStructureWithFunc<unsigned_long> rVar1;
  ushort uVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  byte bVar7;
  
  if (param_4 == (ulong *)0x0) {
switchD_003a410c_default:
    return 0x403;
  }
  switch(param_2) {
  case 0:
    uVar6 = ContentTypeInternal2ContentType((byte)this[7] & 0xf);
    uVar6 = uVar6 & 0xffffffff;
    break;
  case 1:
    *param_4 = (ulong)(param_3 | (uint)(*(ushort *)(this + 4) >> 1) << 0x11);
    return 0;
  case 2:
    uVar6 = (ulong)(*(uint *)(this + 8) >> 8);
    break;
  case 3:
  case 4:
    uVar4 = *(uint *)(this + 0x14);
    uVar6 = (ulong)(*(uint *)(this + 0x10) >> 0xc);
    goto LAB_003a415c;
  case 5:
    uVar6 = (ulong)(*(ushort *)(this + 0xc) >> 6);
    break;
  case 6:
    uVar6 = (ulong)(ushort)((ushort)(byte)this[0xe] * 0x4000 + (*(ushort *)(this + 0xe) >> 2));
    break;
  case 7:
    uVar4 = ((byte)this[0xe] & 3) * 0x4000 + (uint)(*(ushort *)(this + 0xe) >> 2) |
            (uint)(*(ushort *)(this + 0xc) >> 6) << 0x10;
    goto LAB_003a41b0;
  case 8:
    rVar1 = this[6];
    goto LAB_003a41bc;
  case 9:
    uVar6 = (ulong)((byte)this[6] >> 5);
    break;
  case 10:
    uVar6 = (ulong)(byte)this[4];
    goto LAB_003a41d4;
  case 0xb:
    uVar6 = (long)((ulong)(byte)this[7] << 0x38) >> 0x3c;
    break;
  case 0xc:
    if (((byte)this[7] & 0xf) != 1) {
LAB_003a4214:
      *param_4 = 0;
      return 0;
    }
    rVar1 = this[0x4c];
    uVar2 = *(ushort *)(this + 0x40);
    goto LAB_003a4204;
  case 0xd:
    if (((byte)this[7] & 0xf) != 1) goto LAB_003a4214;
    uVar4 = (uint)*(ushort *)(this + 0x42);
    uVar5 = (byte)this[0x4c] >> 1 & 1;
    goto LAB_003a4238;
  case 0xe:
    if (((byte)this[7] & 0xf) != 1) goto LAB_003a4214;
    uVar4 = (uint)*(ushort *)(this + 0x44);
    uVar5 = (byte)this[0x4c] >> 2 & 1;
    goto LAB_003a4238;
  case 0xf:
    if (((byte)this[7] & 0xf) != 1) goto LAB_003a4214;
    uVar4 = (uint)*(ushort *)(this + 0x46);
    uVar5 = (byte)this[0x4c] >> 3 & 1;
    goto LAB_003a4238;
  case 0x10:
    if (1 < (byte)(((byte)this[7] & 0xf) - 2)) goto LAB_003a4214;
    rVar1 = this[0x5c];
    uVar2 = *(ushort *)(this + 0x50);
LAB_003a4204:
    uVar4 = ((byte)rVar1 & 1) << 0x11 | (uint)uVar2;
    goto LAB_003a4208;
  case 0x11:
    if (1 < (byte)(((byte)this[7] & 0xf) - 2)) goto LAB_003a4214;
    uVar4 = (uint)*(ushort *)(this + 0x52);
    uVar5 = (byte)this[0x5c] >> 1 & 1;
    goto LAB_003a4238;
  case 0x12:
    if (1 < (byte)(((byte)this[7] & 0xf) - 2)) goto LAB_003a4214;
    uVar4 = (uint)*(ushort *)(this + 0x54);
    uVar5 = (byte)this[0x5c] >> 2 & 1;
    goto LAB_003a4238;
  case 0x13:
    if (1 < (byte)(((byte)this[7] & 0xf) - 2)) goto LAB_003a4214;
    uVar4 = (uint)*(ushort *)(this + 0x56);
    uVar5 = (byte)this[0x5c] >> 3 & 1;
LAB_003a4238:
    uVar4 = uVar4 | uVar5 << 0x11;
LAB_003a4208:
    uVar6 = (ulong)(uVar4 != 0);
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
    goto LAB_003a4324;
  case 0x17:
    uVar6 = (ulong)(byte)this[6];
    goto LAB_003a41d4;
  case 0x18:
    uVar6 = (ulong)(byte)this[0x10];
    goto LAB_003a41d4;
  case 0x19:
  case 0x1a:
    uVar4 = *(uint *)(this + 0x1c);
    uVar6 = (ulong)(*(uint *)(this + 0x18) >> 0xc) & 0xfff0000000000fff;
LAB_003a415c:
    uVar6 = (ulong)uVar4 | (uVar6 & 0xfff) << 0x20;
    break;
  case 0x1b:
  case 0x2b:
    uVar6 = (ulong)(byte)this[0x5c];
    goto LAB_003a43d4;
  case 0x1c:
    cVar3 = IsJpegExist(this);
    goto LAB_003a4350;
  case 0x1d:
    cVar3 = IsJpegExist(this);
    goto LAB_003a4384;
  case 0x1e:
    cVar3 = IsHeifExist(this);
LAB_003a4350:
    uVar4 = 0;
    if (cVar3 != '\0') {
      uVar4 = (byte)this[0x5b] & 3 | ((byte)this[0x6e] >> 6 & 1) << 2;
    }
    uVar6 = (ulong)(int)uVar4;
LAB_003a4374:
    *param_4 = uVar6;
    return 0;
  case 0x1f:
    cVar3 = IsHeifExist(this);
LAB_003a4384:
    bVar7 = 0;
    if (cVar3 != '\0') {
      rVar1 = this[0x5b];
LAB_003a4394:
      bVar7 = (byte)rVar1 >> 2 & 3;
    }
LAB_003a4398:
    uVar6 = (ulong)bVar7;
    goto LAB_003a4374;
  case 0x20:
    uVar5 = (uint)((byte)this[0x6e] >> 7);
    uVar4 = (byte)this[0x5b] >> 4 & 3;
    goto LAB_003a43c8;
  case 0x21:
    uVar6 = (ulong)(byte)this[0x5b];
    goto LAB_003a43d4;
  case 0x22:
    uVar6 = (ulong)(byte)this[0x5c];
    goto LAB_003a43e0;
  case 0x23:
    uVar5 = (byte)this[0x84] >> 4 & 1;
    uVar4 = (byte)this[0x6b] & 3;
    goto LAB_003a43c8;
  case 0x24:
    uVar5 = (byte)this[0x84] >> 5 & 1;
    uVar4 = (byte)this[0x6b] >> 2 & 3;
LAB_003a43c8:
    uVar4 = uVar4 | uVar5 << 2;
LAB_003a41b0:
    uVar6 = (ulong)(int)uVar4;
    break;
  case 0x25:
    uVar6 = (ulong)(byte)this[0x6b];
    goto LAB_003a4414;
  case 0x26:
    uVar6 = (ulong)(byte)this[0x6b];
    goto LAB_003a43d4;
  case 0x27:
    cVar3 = IsJpegExist(this);
    goto LAB_003a442c;
  case 0x28:
    cVar3 = IsJpegExist(this);
    goto LAB_003a4448;
  case 0x29:
    cVar3 = IsHeifExist(this);
LAB_003a442c:
    bVar7 = 0;
    if (cVar3 != '\0') {
      rVar1 = this[0x5c];
      goto LAB_003a4394;
    }
    goto LAB_003a4398;
  case 0x2a:
    cVar3 = IsHeifExist(this);
LAB_003a4448:
    bVar7 = 0;
    if (cVar3 != '\0') {
      rVar1 = this[0x5c];
LAB_003a4458:
      bVar7 = (byte)rVar1 >> 4 & 3;
    }
    goto LAB_003a4398;
  case 0x2c:
    uVar6 = (ulong)(byte)this[0x5d];
    goto LAB_003a43e0;
  case 0x2d:
    uVar6 = (ulong)(byte)this[0x5d];
    goto LAB_003a4484;
  case 0x2e:
    uVar6 = (ulong)(byte)this[0x6c];
    goto LAB_003a43e0;
  case 0x2f:
    uVar6 = (ulong)(byte)this[0x6c];
    goto LAB_003a4484;
  case 0x30:
    uVar6 = (ulong)(byte)this[0x6c];
    goto LAB_003a4414;
  case 0x31:
    uVar6 = (ulong)(byte)this[0x6c];
    goto LAB_003a43d4;
  case 0x32:
    uVar6 = (ulong)(byte)this[0x6f];
    goto LAB_003a4484;
  case 0x33:
    uVar6 = (ulong)(byte)this[0x6f];
    goto LAB_003a4414;
  case 0x34:
    cVar3 = IsJpegExist(this);
    goto LAB_003a44c4;
  case 0x35:
    cVar3 = IsJpegExist(this);
    goto LAB_003a44e0;
  case 0x36:
    cVar3 = IsHeifExist(this);
LAB_003a44c4:
    bVar7 = 0;
    if (cVar3 != '\0') {
      rVar1 = this[0x5d];
      goto LAB_003a4458;
    }
    goto LAB_003a4398;
  case 0x37:
    cVar3 = IsHeifExist(this);
LAB_003a44e0:
    bVar7 = 0;
    if (cVar3 != '\0') {
      bVar7 = (byte)this[0x5d] >> 6;
    }
    goto LAB_003a4398;
  case 0x38:
    uVar6 = (ulong)(byte)this[0x5e];
    goto LAB_003a43e0;
  case 0x39:
    uVar6 = (ulong)(byte)this[0x5e];
    goto LAB_003a4484;
  case 0x3a:
    uVar6 = (ulong)(byte)this[0x5e];
    goto LAB_003a4414;
  case 0x3b:
    uVar6 = (ulong)(byte)this[0x6d];
LAB_003a43e0:
    uVar6 = uVar6 & 3;
    break;
  case 0x3c:
    uVar6 = (ulong)(byte)this[0x6d];
LAB_003a4484:
    uVar6 = uVar6 >> 2 & 3;
    break;
  case 0x3d:
    uVar6 = (ulong)(byte)this[0x6d];
LAB_003a4414:
    uVar6 = uVar6 >> 4 & 3;
    break;
  case 0x3e:
    uVar6 = (ulong)(byte)this[0x6d];
LAB_003a43d4:
    uVar6 = uVar6 >> 6;
    break;
  case 0x3f:
    uVar6 = (ulong)(byte)this[0x6e];
    goto LAB_003a41d4;
  case 0x40:
    uVar6 = (ulong)(byte)this[0x6e];
    goto LAB_003a4324;
  case 0x41:
    uVar6 = (ulong)((byte)this[0x6e] >> 2) & 1;
    break;
  case 0x42:
    uVar6 = (ulong)((byte)this[0x6e] >> 3) & 1;
    break;
  case 0x43:
    rVar1 = this[0x6e];
LAB_003a41bc:
    uVar6 = (ulong)((byte)rVar1 >> 4) & 1;
    break;
  case 0x44:
    uVar6 = (ulong)((byte)this[0x6e] >> 5) & 1;
    break;
  case 0x45:
    uVar6 = (ulong)(byte)this[0x6e];
    goto LAB_003a452c;
  case 0x46:
    rVar1 = this[0x6e];
    goto LAB_003a4538;
  case 0x47:
    uVar6 = (ulong)(byte)this[0x6f];
LAB_003a41d4:
    uVar6 = uVar6 & 1;
    break;
  case 0x48:
    uVar6 = (ulong)(byte)this[0x6f];
LAB_003a4324:
    uVar6 = uVar6 >> 1 & 1;
    break;
  case 0x49:
    uVar6 = (ulong)(byte)this[0x6f];
    goto LAB_003a452c;
  case 0x59:
    uVar6 = (ulong)(byte)this[0x5e];
LAB_003a452c:
    uVar6 = uVar6 >> 6 & 1;
    break;
  case 0x5a:
    rVar1 = this[0x5e];
LAB_003a4538:
    uVar6 = (ulong)((byte)rVar1 >> 7);
    break;
  default:
    goto switchD_003a410c_default;
  }
  *param_4 = uVar6;
  return 0;
}

