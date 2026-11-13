// XavcsMovieReader::GetMetadata
// Ghidra address: 0020dda0

/* XavcsMovieReader::GetMetadata(unsigned char*, unsigned int, bool&, DefStruct::CamMetaInfo*,
   bool&, mpr::RDD18MetaInfo*, bool&, DefStruct::LocalTime*, bool&, DefStruct::GpsInfo*) */

undefined8 __thiscall
XavcsMovieReader::GetMetadata
          (XavcsMovieReader *this,uchar *param_1,uint param_2,bool *param_3,CamMetaInfo *param_4,
          bool *param_5,RDD18MetaInfo *param_6,bool *param_7,LocalTime *param_8,bool *param_9,
          GpsInfo *param_10)

{
  byte *pbVar1;
  long lVar2;
  uchar uVar3;
  uchar uVar4;
  byte bVar5;
  char cVar6;
  ushort uVar7;
  ushort uVar8;
  uint uVar9;
  byte *__s1;
  bool bVar10;
  undefined2 uVar11;
  int iVar12;
  uint uVar13;
  undefined4 uVar14;
  uint uVar15;
  uint uVar16;
  long lVar17;
  uint uVar18;
  undefined8 uVar19;
  long extraout_x1;
  ulong uVar20;
  short sVar21;
  int iVar22;
  int iVar23;
  float fVar24;
  double dVar25;
  uint local_264;
  byte *local_260;
  ulong local_258;
  uint local_250;
  undefined8 local_248;
  undefined4 local_240;
  undefined2 local_238;
  undefined2 local_236;
  undefined1 local_234;
  undefined1 local_233;
  undefined1 local_232;
  undefined1 local_231;
  int local_230;
  undefined1 *local_228;
  undefined8 local_220;
  undefined1 local_218 [16];
  uint local_208;
  CamMetaInfo local_204;
  undefined1 local_203;
  undefined1 local_202;
  undefined1 local_201;
  undefined8 local_200;
  undefined1 *local_1e8;
  undefined8 local_1e0;
  undefined1 local_1d8 [16];
  undefined1 *local_1c8;
  undefined8 local_1c0;
  undefined1 local_1b8 [16];
  char *local_1a8;
  long local_1a0;
  char local_198 [16];
  undefined8 local_188;
  ulong local_180;
  ostream aoStack_178 [376];
  
  uVar3 = param_1[5];
  uVar7 = CONCAT11(*param_1,param_1[1]);
  uVar4 = param_1[4];
  *param_3 = false;
  *param_5 = false;
  uVar8 = CONCAT11(uVar4,uVar3);
  uVar13 = (uint)uVar8;
  local_264 = 0;
  *param_7 = false;
  *param_9 = false;
  *param_4 = (CamMetaInfo)0x0;
  param_4[0xc] = (CamMetaInfo)0x0;
  param_4[0x14] = (CamMetaInfo)0x0;
  param_4[0x1c] = (CamMetaInfo)0x0;
  param_4[0x1d] = (CamMetaInfo)0x0;
  param_4[0x1f] = (CamMetaInfo)0x0;
  param_4[0x34] = (CamMetaInfo)0x0;
  param_4[0x42] = (CamMetaInfo)0x0;
  param_4[0x4c] = (CamMetaInfo)0x0;
  param_4[0x58] = (CamMetaInfo)0x0;
  param_4[0x5c] = (CamMetaInfo)0x0;
  param_4[0x68] = (CamMetaInfo)0x0;
  param_4[0x74] = (CamMetaInfo)0x0;
  param_4[0x80] = (CamMetaInfo)0x0;
  param_4[0x84] = (CamMetaInfo)0x0;
  param_4[0x88] = (CamMetaInfo)0x0;
  param_4[0x8c] = (CamMetaInfo)0x0;
  param_4[0x90] = (CamMetaInfo)0x0;
  param_4[0x9c] = (CamMetaInfo)0x0;
  param_4[0xa8] = (CamMetaInfo)0x0;
  param_4[0xac] = (CamMetaInfo)0x0;
  param_4[0xb0] = (CamMetaInfo)0x0;
  param_4[0xb4] = (CamMetaInfo)0x0;
  param_4[0xbc] = (CamMetaInfo)0x0;
  param_4[0xfd] = (CamMetaInfo)0x0;
  param_4[0x1c0] = (CamMetaInfo)0x0;
  param_4[0x1c4] = (CamMetaInfo)0x0;
  param_4[0x1cc] = (CamMetaInfo)0x0;
  param_4[0x1d4] = (CamMetaInfo)0x0;
  param_4[0x1dc] = (CamMetaInfo)0x0;
  param_4[0x1e0] = (CamMetaInfo)0x0;
  param_4[0x1e8] = (CamMetaInfo)0x0;
  param_4[0x1f0] = (CamMetaInfo)0x0;
  param_4[0x1f8] = (CamMetaInfo)0x0;
  param_4[0x218] = (CamMetaInfo)0x0;
  param_4[0x224] = (CamMetaInfo)0x0;
  param_4[0x228] = (CamMetaInfo)0x0;
  param_4[0x22c] = (CamMetaInfo)0x0;
  param_4[0x230] = (CamMetaInfo)0x0;
  param_4[0x23c] = (CamMetaInfo)0x0;
  param_4[0x246] = (CamMetaInfo)0x0;
  param_4[0x24c] = (CamMetaInfo)0x0;
  param_4[0x250] = (CamMetaInfo)0x0;
  param_4[0x252] = (CamMetaInfo)0x0;
  param_4[0x256] = (CamMetaInfo)0x0;
  param_4[0x25c] = (CamMetaInfo)0x0;
  param_4[0x263] = (CamMetaInfo)0x0;
  param_4[0x268] = (CamMetaInfo)0x0;
  param_4[0x270] = (CamMetaInfo)0x0;
  param_4[0x278] = (CamMetaInfo)0x0;
  param_4[0x280] = (CamMetaInfo)0x0;
  param_4[0x288] = (CamMetaInfo)0x0;
  param_4[0x290] = (CamMetaInfo)0x0;
  param_4[0x298] = (CamMetaInfo)0x0;
  param_4[0x2a0] = (CamMetaInfo)0x0;
  param_4[0x2a7] = (CamMetaInfo)0x0;
  *param_10 = (GpsInfo)0x0;
  param_10[5] = (GpsInfo)0x0;
  param_10[0x18] = (GpsInfo)0x0;
  param_10[0x2c] = (GpsInfo)0x0;
  param_10[0x38] = (GpsInfo)0x0;
  param_10[0x3e] = (GpsInfo)0x0;
  param_10[0x4c] = (GpsInfo)0x0;
  param_10[0x54] = (GpsInfo)0x0;
  param_10[0x5c] = (GpsInfo)0x0;
  param_10[0x62] = (GpsInfo)0x0;
  param_10[0x6c] = (GpsInfo)0x0;
  param_10[0x78] = (GpsInfo)0x0;
  param_10[0x84] = (GpsInfo)0x0;
  *param_6 = (RDD18MetaInfo)0x0;
  param_6[8] = (RDD18MetaInfo)0x0;
  param_6[0x10] = (RDD18MetaInfo)0x0;
  if (param_2 < uVar7) {
    uVar11 = 0xd09;
  }
  else if (param_2 < uVar13) {
    uVar11 = 0xd0a;
  }
  else {
    if (uVar7 + uVar13 <= param_2) {
      pbVar1 = param_1 + uVar7;
      iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x8000,&local_260,&local_264);
      if (iVar12 == 0) {
        if ((((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0 || uVar13 < 2)) ||
            (local_260 < pbVar1)) || (pbVar1 + uVar8 < local_260 + 2)) {
          uVar19 = 0x10;
          local_188 = 0x20d0b2311;
          local_180 = 0x15c600000000;
          goto LAB_0020e058;
        }
        *param_3 = true;
        fVar24 = powf(2.0,(1.0 - DAT_003d6138 * (float)CONCAT11(*local_260,local_260[1])) * 8.0);
        local_188 = 0;
        local_180 = 0;
        snprintf((char *)&local_188,0x10,"%.*f",(double)fVar24,1);
        dVar25 = strtod((char *)&local_188,(char **)0x0);
        fVar24 = DAT_003d613c;
        param_4[0x42] = (CamMetaInfo)0x1;
        *(int *)(param_4 + 0x44) = (int)((float)dVar25 * fVar24);
        *(undefined4 *)(param_4 + 0x48) = 100;
      }
      iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x8001,&local_260,&local_264);
      if (iVar12 == 0) {
        if (((pbVar1 != (byte *)0x0) && (local_260 != (byte *)0x0 && 7 < uVar13)) &&
           ((pbVar1 <= local_260 && (local_260 + 8 <= pbVar1 + uVar8)))) {
          *param_3 = true;
          param_4[0x23c] = (CamMetaInfo)0x1;
          *(ushort *)(param_4 + 0x23e) = CONCAT11(*local_260,local_260[1]);
          *(ushort *)(param_4 + 0x240) = CONCAT11(local_260[2],local_260[3]);
          *(ushort *)(param_4 + 0x242) = CONCAT11(local_260[4],local_260[5]);
          *(ushort *)(param_4 + 0x244) = CONCAT11(local_260[6],local_260[7]);
          goto LAB_0020e1f4;
        }
        uVar13 = 0x15f0;
      }
      else {
LAB_0020e1f4:
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x8100,&local_260,&local_264);
        __s1 = local_260;
        if (iVar12 == 0) {
          if (((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0 || uVar13 < 0x10)) ||
             ((local_260 < pbVar1 || (pbVar1 + uVar8 < local_260 + 0x10)))) {
            uVar13 = 0x1601;
            goto LAB_0020e198;
          }
          *param_3 = true;
          local_203 = 1;
          local_202 = 1;
          local_228 = (undefined1 *)0xb010104342b0e06;
          local_208 = 0x342b0e06;
          local_204 = (CamMetaInfo)0x4;
          local_201 = 0xb;
          local_220 = 0x10101011005;
          local_200 = 0x20101011005;
          local_1e0 = 0x40101011005;
          local_180 = 0x50101011005;
          local_1e8 = (undefined1 *)0xb010104342b0e06;
          local_188 = 0xb010104342b0e06;
          iVar12 = memcmp(local_260,&local_228,0x10);
          if (iVar12 == 0) {
            param_4[0x58] = (CamMetaInfo)0x1;
            uVar11 = 1;
          }
          else {
            iVar12 = memcmp(__s1,&local_208,0x10);
            if (iVar12 == 0) {
              param_4[0x58] = (CamMetaInfo)0x1;
              uVar11 = 2;
            }
            else {
              iVar12 = memcmp(__s1,&local_1e8,0x10);
              if (iVar12 == 0) {
                param_4[0x58] = (CamMetaInfo)0x1;
                uVar11 = 3;
              }
              else {
                iVar12 = memcmp(__s1,&local_188,0x10);
                if (iVar12 != 0) {
                  param_4[0x58] = (CamMetaInfo)0x0;
                  goto LAB_0020e3cc;
                }
                uVar11 = 4;
                param_4[0x58] = (CamMetaInfo)0x1;
              }
            }
          }
          *(undefined2 *)(param_4 + 0x5a) = uVar11;
        }
LAB_0020e3cc:
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x8109,&local_260,&local_264);
        if (iVar12 == 0) {
          if ((((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0 || uVar13 < 8)) ||
              (local_260 < pbVar1)) || (pbVar1 + uVar8 < local_260 + 8)) {
            uVar13 = 0x162d;
            goto LAB_0020e198;
          }
          *param_3 = true;
          param_4[0x4c] = (CamMetaInfo)0x1;
          uVar14 = FUN_0020adf8(local_260);
          *(undefined4 *)(param_4 + 0x50) = uVar14;
          uVar14 = FUN_0020adf8(extraout_x1 + 4);
          *(undefined4 *)(param_4 + 0x54) = uVar14;
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x810b,&local_260,&local_264);
        if (iVar12 == 0) {
          if (((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0 || uVar13 < 2)) ||
             ((local_260 < pbVar1 || (pbVar1 + uVar8 < local_260 + 2)))) {
            uVar13 = 0x164c;
            goto LAB_0020e198;
          }
          *param_3 = true;
          param_4[0xb4] = (CamMetaInfo)0x1;
          *(uint *)(param_4 + 0xb8) = (uint)CONCAT11(*local_260,local_260[1]);
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0xe301,&local_260,&local_264);
        if (iVar12 == 0) {
          if (((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0 || uVar13 < 4)) ||
             ((local_260 < pbVar1 || (pbVar1 + uVar8 < local_260 + 4)))) {
            uVar13 = 0x1657;
            goto LAB_0020e198;
          }
          *param_3 = true;
          param_4[0xb4] = (CamMetaInfo)0x1;
          uVar14 = FUN_0020adf8();
          *(undefined4 *)(param_4 + 0xb8) = uVar14;
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0xe303,&local_260,&local_264);
        if (iVar12 == 0) {
          if ((((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0)) || (uVar13 == 0)) ||
             ((local_260 < pbVar1 || (pbVar1 + uVar8 < local_260 + 1)))) {
            uVar13 = 0x1685;
            goto LAB_0020e198;
          }
          *param_3 = true;
          param_4[0xa8] = (CamMetaInfo)0x0;
          if (*local_260 == 0xff) {
            uVar11 = 0x1f;
          }
          else {
            if (*local_260 < 7) goto LAB_0020e6bc;
            uVar11 = 6;
          }
          *(undefined2 *)(param_4 + 0xaa) = uVar11;
        }
LAB_0020e6bc:
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x810d,&local_260,&local_264);
        if (iVar12 == 0) {
          if (((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0)) ||
             ((uVar13 == 0 || ((local_260 < pbVar1 || (pbVar1 + uVar8 < local_260 + 1)))))) {
            uVar13 = 0x169d;
            goto LAB_0020e198;
          }
          *param_3 = true;
          param_4[0x88] = (CamMetaInfo)0x1;
          *(ushort *)(param_4 + 0x8a) = (ushort)(*local_260 != 1);
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x3210,&local_260,&local_264);
        if (iVar12 == 0) {
          if ((((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0 || uVar13 < 0x10)) ||
              (local_260 < pbVar1)) || (pbVar1 + uVar8 < local_260 + 0x10)) {
            uVar13 = 0x16b6;
            goto LAB_0020e198;
          }
          uVar19 = *(undefined8 *)local_260;
          uVar20 = *(ulong *)(local_260 + 8);
          if (((((uint)uVar19 & 0xff) == 6) && (((uint)((ulong)uVar19 >> 8) & 0xff) == 0xe)) &&
             ((((((uint)((ulong)uVar19 >> 0x10) & 0xff) == 0x2b &&
                (((uint)uVar19 >> 0x18 == 0x34 &&
                 (uVar16 = (uint)((ulong)uVar19 >> 0x20), (uVar16 & 0xff) == 4)))) &&
               ((uVar16 >> 8 & 0xff) == 1)) && (((ushort)((ulong)uVar19 >> 0x30) & 0xff) == 1)))) {
            cVar6 = (char)((ulong)uVar19 >> 0x38);
            uVar15 = (uint)uVar20;
            bVar5 = (byte)(uVar20 >> 0x38);
            uVar16 = (uint)(uVar20 >> 8);
            uVar18 = (uint)(uVar20 >> 0x10);
            uVar9 = (uint)(uVar20 >> 0x20);
            if (cVar6 != '\x06') {
              if (cVar6 == '\x01') {
                if ((((uVar15 & 0xff) == 4) && ((uVar16 & 0xff) == 1)) &&
                   ((((uVar18 & 0xff) == 1 &&
                     (((uVar15 >> 0x18 == 1 && ((uVar9 & 0xff) == 1)) &&
                      ((uVar20 & 0xff000000000000) == 0)))) && (bVar5 == 0)))) {
                  uVar16 = uVar9 >> 8 & 0xff;
                  if (uVar16 == 3) {
                    uVar16 = 0x34;
                  }
                  else {
                    if (uVar16 != 2) goto LAB_0020ebf4;
                    uVar16 = 0x35;
                  }
                  goto LAB_0020e970;
                }
              }
              else if (cVar6 == '\r') {
                if ((((((uVar15 & 0xff) == 4) && ((uVar16 & 0xff) == 1)) && ((uVar18 & 0xff) == 1))
                    && ((uVar15 >> 0x18 == 1 && ((uVar9 & 0xff) == 1)))) &&
                   (((uVar20 & 0xff000000000000) == 0 && (bVar5 == 0)))) {
                  uVar16 = uVar9 >> 8 & 0xff;
                  if (uVar16 != 8) {
                    if (uVar16 != 10) {
                      if (uVar16 == 0xb) {
                        uVar16 = 0x58;
                        goto LAB_0020e970;
                      }
                      bVar10 = uVar16 == 0xd;
LAB_0020ead0:
                      if (!bVar10) goto LAB_0020ebf4;
                    }
                    goto LAB_0020e96c;
                  }
                  uVar16 = 0x53;
                  goto LAB_0020e970;
                }
              }
              else if (((((cVar6 == '\x0e') && ((uVar15 & 0xff) == 4)) && ((uVar16 & 0xff) == 1)) &&
                       ((((uVar18 & 0xff) == 1 && (uVar15 >> 0x18 == 1)) &&
                        (((uVar9 & 0xff) == 1 &&
                         (((uVar9 >> 8 & 0xff) == 9 && ((uVar20 & 0xff000000000000) == 0)))))))) &&
                      (bVar5 == 0)) {
                uVar16 = 0x56;
                goto LAB_0020e970;
              }
              goto LAB_0020ebf4;
            }
            if ((uVar15 & 0xff) != 0xe) {
              if ((((((uVar15 & 0xff) == 4) && ((uVar16 & 0xff) == 1)) &&
                   (((uVar18 & 0xff) == 1 && ((uVar15 >> 0x18 == 1 && ((uVar9 & 0xff) == 1)))))) &&
                  ((uVar9 >> 8 & 0xff) == 6)) &&
                 (((uVar20 & 0xff000000000000) == 0 && (bVar5 == 0)))) {
                uVar16 = 0x25;
                goto LAB_0020e970;
              }
              goto LAB_0020ebf4;
            }
            if (((((uVar16 & 0xff) != 6) || ((uVar18 & 0xff) != 4)) ||
                (((uint)(uVar20 >> 0x18) & 0xff) != 1)) ||
               ((((uVar9 & 0xff) != 1 || ((uVar9 >> 8 & 0xff) != 1)) ||
                (uVar18 = (ushort)(uVar20 >> 0x30) & 0xff, 6 < uVar18 - 1)))) goto LAB_0020ebf4;
            uVar16 = (uint)bVar5;
            switch(uVar18) {
            case 1:
              if (bVar5 == 1) {
                uVar16 = 0x31;
              }
              else if (bVar5 == 2) {
                uVar16 = 0x32;
              }
              else if (bVar5 == 3) {
                uVar16 = 0x33;
              }
              else if (bVar5 == 6) {
                uVar16 = 0x36;
              }
              else {
                if ((uVar16 - 7 & 0xff) < 3) goto LAB_0020e96c;
                if (uVar16 != 0x7f) goto LAB_0020ebf4;
                uVar16 = 0x30;
              }
              break;
            case 2:
              if (bVar5 == 1) {
                uVar16 = 0x11;
              }
              else if (bVar5 == 2) {
                uVar16 = 0x12;
              }
              else if (uVar16 == 3) {
                uVar16 = 0x13;
              }
              else if (uVar16 == 4) {
                uVar16 = 0x14;
              }
              else if (uVar16 == 5) {
                uVar16 = 0x15;
              }
              else if (uVar16 == 6) {
                uVar16 = 0x16;
              }
              else if (bVar5 == 7) {
                uVar16 = 0x17;
              }
              else {
                if (bVar5 != 8) goto LAB_0020ebf4;
                uVar16 = 0x18;
              }
              break;
            case 3:
              if (((uVar16 == 1) || (bVar5 == 2)) || ((bVar5 == 3 || (bVar5 == 4)))) break;
              if (4 < (byte)(bVar5 - 5)) goto LAB_0020ebf4;
              goto LAB_0020e96c;
            case 4:
              if (uVar16 == 1) {
                uVar16 = 0x41;
              }
              else if (uVar16 == 2) {
                uVar16 = 0x42;
              }
              else if (bVar5 == 3) {
                uVar16 = 0x43;
              }
              else if (bVar5 == 4) {
                uVar16 = 0x44;
              }
              else if (bVar5 == 5) {
                uVar16 = 0x45;
              }
              else if (bVar5 == 6) {
                uVar16 = 0x46;
              }
              else if (bVar5 == 7) {
                uVar16 = 0x47;
              }
              else if (bVar5 == 8) {
                uVar16 = 0x48;
              }
              else {
                if (uVar16 != 9) goto LAB_0020ebf4;
                uVar16 = 0x49;
              }
              break;
            case 5:
              if ((uVar16 - 1 & 0xff) < 3) goto LAB_0020e96c;
              if (uVar16 == 4) {
                uVar16 = 0x24;
              }
              else {
                if ((uVar16 - 6 & 0xff) < 2) goto LAB_0020e96c;
                if (uVar16 != 8) {
                  bVar10 = uVar16 == 9;
                  goto LAB_0020ead0;
                }
                uVar16 = 0x28;
              }
              break;
            case 6:
              if (uVar16 == 1) {
                uVar16 = 0x51;
              }
              else if (uVar16 == 2) {
                uVar16 = 0x52;
              }
              else if (uVar16 == 4) {
                uVar16 = 0x54;
              }
              else {
                if (uVar16 != 5) goto LAB_0020ebf4;
                uVar16 = 0x55;
              }
              break;
            case 7:
              if (bVar5 == 1) {
                uVar16 = 0x61;
              }
              else if (bVar5 == 2) {
                uVar16 = 0x62;
              }
              else {
                if (bVar5 == 3) goto LAB_0020e96c;
                if (bVar5 == 4) {
                  uVar16 = 100;
                }
                else {
                  if (uVar16 != 5) goto LAB_0020ebf4;
                  uVar16 = 0x65;
                }
              }
            }
          }
          else {
LAB_0020ebf4:
            local_188 = 0x30d022311;
            local_180 = CONCAT44(local_180._4_4_,2);
            FUN_0020aff4(&local_188,0xc);
LAB_0020e96c:
            uVar16 = 0xffff;
          }
LAB_0020e970:
          *(uint *)(param_6 + 4) = uVar16;
          if (*(int *)(param_6 + 4) != 0xffff) {
            *param_5 = true;
            *param_6 = (RDD18MetaInfo)0x1;
          }
        }
        if (*param_5 != false) {
          if ((*param_6 == (RDD18MetaInfo)0x0) ||
             (*(int *)(param_6 + 4) != 0x58 && *(int *)(param_6 + 4) != 100)) {
            param_4[0x14] = (CamMetaInfo)0x0;
            *(undefined4 *)(param_4 + 0x18) = 4;
          }
          else {
            *param_3 = true;
            param_4[0x14] = (CamMetaInfo)0x1;
            *(undefined4 *)(param_4 + 0x18) = 2;
          }
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x3219,&local_260,&local_264);
        if (iVar12 == 0) {
          if ((((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0 || uVar13 < 0x10)) ||
              (local_260 < pbVar1)) || (pbVar1 + uVar8 < local_260 + 0x10)) {
            uVar13 = 0x170f;
            goto LAB_0020e198;
          }
          if (DAT_003d61e8 == (int)*(undefined8 *)local_260) {
            iVar22 = (int)((ulong)*(undefined8 *)local_260 >> 0x20);
            iVar12 = (int)*(undefined8 *)(local_260 + 8);
            iVar23 = (int)((ulong)*(undefined8 *)(local_260 + 8) >> 0x20);
            if (((iVar22 == DAT_003d61fc) && (DAT_003d6200 == iVar12)) && (DAT_003d6204 == iVar23))
            {
              uVar14 = 0x32;
            }
            else {
              if (iVar22 != DAT_003d61ec) goto LAB_0020ff4c;
              if ((iVar12 == DAT_003d61f0) && (DAT_003d61f4 == iVar23)) {
                uVar14 = 0x31;
              }
              else {
                if (iVar12 != DAT_003d6210) goto LAB_0020ff4c;
                if (iVar23 == DAT_003d6214) {
                  uVar14 = 0x33;
                }
                else if (iVar23 == DAT_003d6224) {
                  uVar14 = 0x34;
                }
                else if (iVar23 == DAT_003d6234) {
                  uVar14 = 0x35;
                }
                else {
                  if ((((iVar23 != DAT_003d6244) && (iVar23 != DAT_003d6254)) &&
                      (iVar23 != DAT_003d6264)) && (iVar23 != DAT_003d6274)) goto LAB_0020ff4c;
                  uVar14 = 0x3f;
                }
              }
            }
          }
          else {
LAB_0020ff4c:
            local_188 = 0x30d032311;
            local_180 = CONCAT44(local_180._4_4_,2);
            FUN_0020aff4(&local_188,0xc);
            uVar14 = 0xffff;
          }
          *(undefined4 *)(param_6 + 0xc) = uVar14;
          if (*(int *)(param_6 + 0xc) != 0xffff) {
            *param_5 = true;
            param_6[8] = (RDD18MetaInfo)0x1;
          }
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x321a,&local_260,&local_264);
        if (iVar12 == 0) {
          if (((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0 || uVar13 < 0x10)) ||
             ((local_260 < pbVar1 || (pbVar1 + uVar8 < local_260 + 0x10)))) {
            uVar13 = 0x1730;
            goto LAB_0020e198;
          }
          if (DAT_003d6278 == (int)*(undefined8 *)local_260) {
            iVar22 = (int)((ulong)*(undefined8 *)local_260 >> 0x20);
            iVar12 = (int)*(undefined8 *)(local_260 + 8);
            iVar23 = (int)((ulong)*(undefined8 *)(local_260 + 8) >> 0x20);
            if (((iVar22 == DAT_003d627c) && (DAT_003d6280 == iVar12)) && (DAT_003d6284 == iVar23))
            {
              uVar14 = 2;
            }
            else if (((iVar22 == DAT_003d628c) && (DAT_003d6290 == iVar12)) &&
                    (DAT_003d6294 == iVar23)) {
              uVar14 = 5;
            }
            else {
              if (((iVar22 != DAT_003d629c) || (DAT_003d62a0 != iVar12)) || (DAT_003d62a4 != iVar23)
                 ) goto LAB_00210054;
              uVar14 = 1;
            }
          }
          else {
LAB_00210054:
            local_188 = 0x30d042311;
            local_180 = CONCAT44(local_180._4_4_,2);
            FUN_0020aff4(&local_188,0xc);
            uVar14 = 0xffff;
          }
          *(undefined4 *)(param_6 + 0x14) = uVar14;
          if (*(int *)(param_6 + 0x14) != 0xffff) {
            *param_5 = true;
            param_6[0x10] = (RDD18MetaInfo)0x1;
          }
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0xe304,&local_260,&local_264);
        if (iVar12 == 0) {
          if (((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0 || uVar13 < 8)) ||
             ((local_260 < pbVar1 || (pbVar1 + uVar8 < local_260 + 8)))) {
            uVar13 = 0x174c;
            goto LAB_0020e198;
          }
          *param_7 = true;
          bVar5 = *local_260;
          uVar7 = bVar5 >> 1 & 0xf;
          sVar21 = 0;
          if (uVar7 != 0xf) {
            sVar21 = uVar7 * 0x3c;
            if ((bVar5 & 1) != 0) {
              sVar21 = sVar21 + 0x1e;
            }
            if ((bVar5 >> 5 & 1) != 0) {
              sVar21 = -sVar21;
            }
          }
          *(short *)param_8 = sVar21;
          *(ushort *)(param_8 + 2) =
               (local_260[1] & 0xf) * 100 + (ushort)(local_260[1] >> 4) * 1000 +
               (local_260[2] & 0xf) + (ushort)(local_260[2] >> 4) * 10;
          param_8[4] = (LocalTime)((local_260[3] & 0xf) + (local_260[3] >> 4) * '\n');
          param_8[5] = (LocalTime)((local_260[4] & 0xf) + (local_260[4] >> 4) * '\n');
          param_8[6] = (LocalTime)((local_260[5] & 0xf) + (local_260[5] >> 4) * '\n');
          param_8[7] = (LocalTime)((local_260[6] & 0xf) + (local_260[6] >> 4) * '\n');
          param_8[8] = (LocalTime)((local_260[7] & 0xf) + (local_260[7] >> 4) * '\n');
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x8500,&local_260,&local_264);
        if (iVar12 == 0) {
          if ((((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0 || uVar13 < 4)) ||
              (local_260 < pbVar1)) || (pbVar1 + uVar8 < local_260 + 4)) {
            uVar13 = 0x1774;
            goto LAB_0020e198;
          }
          *param_9 = true;
          *param_10 = (GpsInfo)0x1;
          lVar17 = 0;
          do {
            lVar2 = lVar17 + 1;
            param_10[lVar17 + 1] = *(GpsInfo *)(local_260 + lVar17);
            lVar17 = lVar2;
          } while (lVar2 != 4);
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x8501,&local_260,&local_264);
        if (iVar12 == 0) {
          if (((pbVar1 != (byte *)0x0) && (local_260 != (byte *)0x0)) &&
             ((uVar13 != 0 && ((pbVar1 <= local_260 && (local_260 + 1 <= pbVar1 + uVar8)))))) {
            local_1e8 = (undefined1 *)CONCAT62(local_1e8._2_6_,0x534e);
            local_188 = 0x100000000;
            FUN_0020db8c(this,*local_260,2,&local_1e8,&local_188,param_10 + 5,param_10 + 8);
            goto LAB_0020f060;
          }
          uVar13 = 0x1781;
LAB_0020f1c0:
          local_188 = 0x20d0b2311;
          local_180 = (ulong)uVar13 << 0x20;
          uVar19 = 0x10;
          goto LAB_0020e058;
        }
LAB_0020f060:
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x8502,&local_260,&local_264);
        if ((iVar12 == 0) && (param_10[5] != (GpsInfo)0x0)) {
          if ((((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0 || uVar13 < 0x18)) ||
              (local_260 < pbVar1)) || (pbVar1 + uVar8 < local_260 + 0x18)) {
            uVar13 = 0x178c;
            goto LAB_0020e198;
          }
          *param_9 = true;
          FUN_0020dbd0(this,local_260,param_10 + 5,param_10 + 0xc,param_10 + 0x10,param_10 + 0x14);
        }
        else {
          param_10[5] = (GpsInfo)0x0;
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x8503,&local_260,&local_264);
        if (iVar12 == 0) {
          if (((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0)) ||
             ((uVar13 == 0 || ((local_260 < pbVar1 || (pbVar1 + uVar8 < local_260 + 1)))))) {
            uVar13 = 0x1799;
            goto LAB_0020f1c0;
          }
          local_1e8 = (undefined1 *)CONCAT62(local_1e8._2_6_,0x5745);
          local_188 = 0x100000000;
          FUN_0020db8c(this,*local_260,2,&local_1e8,&local_188,param_10 + 0x18,param_10 + 0x1c);
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x8504,&local_260,&local_264);
        if ((iVar12 == 0) && (param_10[0x18] != (GpsInfo)0x0)) {
          if ((((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0 || uVar13 < 0x18)) ||
              (local_260 < pbVar1)) || (pbVar1 + uVar8 < local_260 + 0x18)) {
            uVar13 = 0x17a3;
            goto LAB_0020e198;
          }
          *param_9 = true;
          FUN_0020dbd0(this,local_260,param_10 + 0x18,param_10 + 0x20,param_10 + 0x24,
                       param_10 + 0x28);
        }
        else {
          param_10[0x18] = (GpsInfo)0x0;
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x8505,&local_260,&local_264);
        if (iVar12 == 0) {
          if (((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0)) ||
             ((uVar13 == 0 || ((local_260 < pbVar1 || (pbVar1 + uVar8 < local_260 + 1)))))) {
            uVar13 = 0x17b0;
            goto LAB_0020f1c0;
          }
          local_1e8 = (undefined1 *)CONCAT62((int6)((ulong)local_1e8 >> 0x10),0x100);
          local_188 = 0x100000000;
          FUN_0020db8c(this,*local_260,2,&local_1e8,&local_188,param_10 + 0x2c,param_10 + 0x30);
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x8506,&local_260,&local_264);
        if ((iVar12 == 0) && (param_10[0x2c] != (GpsInfo)0x0)) {
          if ((((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0 || uVar13 < 8)) ||
              (local_260 < pbVar1)) || (pbVar1 + uVar8 < local_260 + 8)) {
            uVar13 = 0x17ba;
            goto LAB_0020e198;
          }
          *param_9 = true;
          FUN_0020dbd0(this,local_260,param_10 + 0x2c,param_10 + 0x34,0,0);
        }
        else {
          param_10[0x2c] = (GpsInfo)0x0;
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x851d,&local_260,&local_264);
        if (iVar12 == 0) {
          if (((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0 || uVar13 < 10)) ||
             ((local_260 < pbVar1 || (pbVar1 + uVar8 < local_260 + 10)))) {
            uVar13 = 0x17c7;
            goto LAB_0020e198;
          }
          *param_9 = true;
          FUN_0020dcb0(this,local_260,param_10 + 0x38,param_10 + 0x3a);
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x8507,&local_260,&local_264);
        if (iVar12 == 0) {
          if (((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0 || uVar13 < 0x18)) ||
             ((local_260 < pbVar1 || (pbVar1 + uVar8 < local_260 + 0x18)))) {
            uVar13 = 0x17d1;
            goto LAB_0020e198;
          }
          *param_9 = true;
          FUN_0020dbd0(this,local_260,param_10 + 0x3e,param_10 + 0x40,param_10 + 0x44,
                       param_10 + 0x48);
        }
        else {
          param_10[0x3e] = (GpsInfo)0x0;
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x8509,&local_260,&local_264);
        if (iVar12 == 0) {
          if ((((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0)) || (uVar13 == 0)) ||
             ((local_260 < pbVar1 || (pbVar1 + uVar8 < local_260 + 1)))) {
            uVar13 = 0x17df;
            goto LAB_0020f1c0;
          }
          *param_9 = true;
          local_1e8 = (undefined1 *)CONCAT62(local_1e8._2_6_,0x5641);
          local_188 = 0x100000000;
          FUN_0020db8c(this,*local_260,2,&local_1e8,&local_188,param_10 + 0x4c,param_10 + 0x50);
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x850a,&local_260,&local_264);
        if (iVar12 == 0) {
          if (((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0)) ||
             ((uVar13 == 0 || ((local_260 < pbVar1 || (pbVar1 + uVar8 < local_260 + 1)))))) {
            uVar13 = 0x17eb;
            goto LAB_0020f1c0;
          }
          *param_9 = true;
          local_1e8 = (undefined1 *)CONCAT62(local_1e8._2_6_,0x3332);
          local_188 = 0x100000000;
          FUN_0020db8c(this,*local_260,2,&local_1e8,&local_188,param_10 + 0x54,param_10 + 0x58);
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x850b,&local_260,&local_264);
        if (iVar12 == 0) {
          if ((((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0 || uVar13 < 8)) ||
              (local_260 < pbVar1)) || (pbVar1 + uVar8 < local_260 + 8)) {
            uVar13 = 0x17f7;
            goto LAB_0020e198;
          }
          *param_9 = true;
          FUN_0020dbd0(this,local_260,param_10 + 0x5c,param_10 + 0x5e,0,0);
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x850c,&local_260,&local_264);
        if (iVar12 == 0) {
          if (((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0)) ||
             ((uVar13 == 0 || ((local_260 < pbVar1 || (pbVar1 + uVar8 < local_260 + 1)))))) {
            uVar13 = 0x1801;
            goto LAB_0020f1c0;
          }
          local_1e8 = (undefined1 *)CONCAT53(local_1e8._3_5_,0x4e4d4b);
          local_188 = 0x100000000;
          local_180 = CONCAT44(local_180._4_4_,2);
          FUN_0020db8c(this,*local_260,3,&local_1e8,&local_188,param_10 + 0x62,param_10 + 100);
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x850d,&local_260,&local_264);
        if ((iVar12 == 0) && (param_10[0x62] != (GpsInfo)0x0)) {
          if ((((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0 || uVar13 < 8)) ||
              (local_260 < pbVar1)) || (pbVar1 + uVar8 < local_260 + 8)) {
            uVar13 = 0x180c;
            goto LAB_0020e198;
          }
          *param_9 = true;
          FUN_0020dbd0(this,local_260,param_10 + 0x62,param_10 + 0x68,0,0);
        }
        else {
          param_10[0x62] = (GpsInfo)0x0;
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x850e,&local_260,&local_264);
        if (iVar12 == 0) {
          if (((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0)) ||
             ((uVar13 == 0 || ((local_260 < pbVar1 || (pbVar1 + uVar8 < local_260 + 1)))))) {
            uVar13 = 0x1818;
            goto LAB_0020f1c0;
          }
          local_1e8 = (undefined1 *)CONCAT62(local_1e8._2_6_,0x4d54);
          local_188 = 0x100000000;
          FUN_0020db8c(this,*local_260,2,&local_1e8,&local_188,param_10 + 0x6c,param_10 + 0x70);
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x850f,&local_260,&local_264);
        if ((iVar12 == 0) && (param_10[0x6c] != (GpsInfo)0x0)) {
          if ((((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0 || uVar13 < 8)) ||
              (local_260 < pbVar1)) || (pbVar1 + uVar8 < local_260 + 8)) {
            uVar13 = 0x1823;
            goto LAB_0020e198;
          }
          *param_9 = true;
          FUN_0020dbd0(this,local_260,param_10 + 0x6c,param_10 + 0x74,0,0);
        }
        else {
          param_10[0x6c] = (GpsInfo)0x0;
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x8510,&local_260,&local_264);
        if (iVar12 == 0) {
          if (((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0)) ||
             ((uVar13 == 0 || ((local_260 < pbVar1 || (pbVar1 + uVar8 < local_260 + 1)))))) {
            uVar13 = 0x182f;
            goto LAB_0020f1c0;
          }
          local_1e8 = (undefined1 *)CONCAT62(local_1e8._2_6_,0x4d54);
          local_188 = 0x100000000;
          FUN_0020db8c(this,*local_260,2,&local_1e8,&local_188,param_10 + 0x78,param_10 + 0x7c);
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x8511,&local_260,&local_264);
        if ((iVar12 == 0) && (param_10[0x78] != (GpsInfo)0x0)) {
          if ((((pbVar1 == (byte *)0x0) || (local_260 == (byte *)0x0 || uVar13 < 8)) ||
              (local_260 < pbVar1)) || (pbVar1 + uVar8 < local_260 + 8)) {
            uVar13 = 0x183a;
            goto LAB_0020e198;
          }
          *param_9 = true;
          FUN_0020dbd0(this,local_260,param_10 + 0x78,param_10 + 0x80,0,0);
        }
        else {
          param_10[0x78] = (GpsInfo)0x0;
        }
        iVar12 = mpr::KlvConverter::KlvParser(pbVar1,uVar13,0x8512,&local_260,&local_264);
        if (iVar12 != 0) {
LAB_0020fd0c:
          param_4[0x13e] = (CamMetaInfo)0x0;
          mpr::thread::normalLock::lock((normalLock *)(this + 0x1e28));
          if (this[0x1e18] != (XavcsMovieReader)0x0) {
            local_1e8 = local_1d8;
            local_1e0 = 0;
            local_1c8 = local_1b8;
            local_1a8 = local_198;
            local_1d8[0] = 0;
            local_1b8[0] = 0;
            local_198[0] = '\0';
            local_1c0 = 0;
            local_1a0 = 0;
            std::__cxx11::stringstream::stringstream((stringstream *)&local_188,0x18);
            std::ostream::operator<<(aoStack_178,0xffffffff);
            local_218[0] = 0;
            local_228 = local_218;
            local_220 = 0;
            std::__cxx11::stringbuf::str();
            std::__cxx11::string::assign((string *)&local_228);
            std::__cxx11::string::_M_dispose();
            uVar19 = *(undefined8 *)(this + 0x1e10);
            iVar12 = FUN_00354780(uVar19,&local_1e8);
            if (((iVar12 == 0) && (local_1a0 != 0)) &&
               (iVar12 = std::__cxx11::string::compare((string *)&local_228), iVar12 != 0)) {
              param_4[0x13e] = (CamMetaInfo)0x1;
              strncpy((char *)(param_4 + 0x13f),local_1a8,0x3f);
            }
            param_4[0x27] = (CamMetaInfo)0x0;
            local_204 = (CamMetaInfo)0x0;
            local_208 = 0;
            local_200 = 0;
            iVar12 = FUN_00354980(uVar19,&local_208);
            if ((((iVar12 == 0) && ((local_208 & 0x101) != 0)) && (local_204 != (CamMetaInfo)0x0))
               && (*param_7 != false)) {
              local_248 = 0;
              local_240 = 0;
              local_258 = (ulong)*(uint7 *)(param_8 + 2);
              local_250 = (uint)*(ushort *)(param_8 + 10);
              iVar12 = date_time_add_seconds(&local_248,&local_258,local_200);
              if (iVar12 == 0) {
                param_4[0x27] = local_204;
                *(undefined2 *)(param_4 + 0x28) = *(undefined2 *)param_8;
                *(undefined2 *)(param_4 + 0x2a) = (undefined2)local_248;
                param_4[0x2c] = local_248._2_1_;
                param_4[0x2d] = local_248._3_1_;
                param_4[0x2e] = local_248._4_1_;
                param_4[0x2f] = local_248._5_1_;
                param_4[0x30] = local_248._6_1_;
                *(undefined2 *)(param_4 + 0x32) = (undefined2)local_240;
              }
              else {
                local_233 = 0;
                local_234 = 3;
                local_232 = 0;
                local_238 = 0x2140;
                local_231 = 0;
                local_236 = 0xd08;
                local_230 = iVar12;
                FUN_0020aff4(&local_238,0xc);
              }
            }
            std::__cxx11::string::_M_dispose();
            std::__cxx11::stringstream::~stringstream((stringstream *)&local_188);
            std::__cxx11::string::_M_dispose();
            std::__cxx11::string::_M_dispose();
            std::__cxx11::string::_M_dispose();
          }
          mpr::thread::normalLock::unlock((normalLock *)(this + 0x1e28));
          return 0;
        }
        *param_9 = true;
        param_10[0x8d] = (GpsInfo)0x0;
        uVar16 = local_264;
        if (9 < local_264) {
          uVar16 = 9;
        }
        *(undefined8 *)(param_10 + 0x85) = 0;
        if (((pbVar1 != (byte *)0x0) && (local_260 != (byte *)0x0 && uVar16 <= uVar13)) &&
           ((pbVar1 <= local_260 && (local_260 + uVar16 <= pbVar1 + uVar8)))) {
          param_10[0x84] = (GpsInfo)0x1;
          for (uVar20 = 0; uVar20 != uVar16; uVar20 = uVar20 + 1) {
            param_10[uVar20 + 0x85] = *(GpsInfo *)(local_260 + uVar20);
          }
          goto LAB_0020fd0c;
        }
        uVar13 = 0x1849;
      }
LAB_0020e198:
      local_188 = 0x20d0b2311;
      uVar19 = 0x10;
      local_180 = (ulong)uVar13 << 0x20;
      goto LAB_0020e058;
    }
    uVar11 = 0xd0c;
  }
  local_188 = CONCAT44(3,CONCAT22(uVar11,0x2311));
  uVar19 = 0xc;
  local_180 = local_180 & 0xffffffff00000000;
LAB_0020e058:
  FUN_0020aff4(&local_188,uVar19);
  return 0;
}

