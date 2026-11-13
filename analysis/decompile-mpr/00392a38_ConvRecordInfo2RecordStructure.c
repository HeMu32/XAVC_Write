// sidb::ConvRecordInfo2RecordStructure
// Ghidra address: 00392a38

/* WARNING: Type propagation algorithm not settling */
/* sidb::ConvRecordInfo2RecordStructure(unsigned int, sidb::recordInfo const&, DefStruct::LocalTime
   const&, sidb::recordStructure*) */

undefined8
sidb::ConvRecordInfo2RecordStructure
          (uint param_1,recordInfo *param_2,LocalTime *param_3,recordStructure *param_4)

{
  LocalTime *pLVar1;
  recordInfo *__s1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  byte bVar7;
  undefined *puVar8;
  byte bVar9;
  recordStructure rVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  undefined2 uVar13;
  short sVar14;
  ushort uVar15;
  uint uVar16;
  int iVar17;
  undefined8 uVar18;
  size_t sVar19;
  recordStructure rVar20;
  uint uVar21;
  char *pcVar22;
  ulong uVar23;
  uint uVar24;
  ulong uVar25;
  char *pcVar26;
  fileStructure *pfVar27;
  signed local_103;
  signed local_102;
  undefined1 local_101;
  undefined2 local_100;
  recordStructure local_fe;
  undefined2 local_f8;
  recordStructure local_f6;
  undefined2 local_f0;
  recordStructure local_ee;
  undefined4 local_e8;
  undefined4 local_e0;
  undefined4 local_d8;
  uint local_d0;
  uint local_cc;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  uint local_bc [9];
  ulong local_98;
  ulong local_90;
  undefined1 *local_88 [2];
  undefined1 auStack_78 [16];
  undefined8 local_68;
  ulong local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined8 uStack_8;
  
  uVar23 = (ulong)param_1;
  pLVar1 = (LocalTime *)(param_2 + 0xc);
  *param_4 = (recordStructure)((byte)*param_4 & 0xf0);
  ConvDefStructLocalTime2SiDBUInt64(param_3,&local_98,&local_103);
  param_4[0x18] = (recordStructure)((byte)param_4[0x18] & 1 | (char)local_103 << 1);
  *(uint *)(param_4 + 0x18) =
       *(uint *)(param_4 + 0x18) & 0xff000000 |
       *(uint *)(param_4 + 0x18) & 0xfff | ((uint)(local_98 >> 0x20) & 0xfff) << 0xc;
  *(int *)(param_4 + 0x1c) = (int)local_98;
  *(ushort *)(param_4 + 4) =
       *(ushort *)(param_4 + 4) & 1 | (ushort)((*(uint *)(param_2 + 4) >> 0x11 & 0x7f) << 1);
  *(uint *)(param_4 + 8) = *(uint *)(param_4 + 8) & 0xff | *(int *)(param_2 + 8) << 8;
  bVar9 = ContentType2ContentTypeInternal(*(undefined4 *)param_2,*(undefined4 *)(param_2 + 0x614));
  param_4[7] = (recordStructure)((byte)param_4[7] & 0xf0 | bVar9 & 0xf);
  param_4[6] = (recordStructure)
               ((byte)param_4[6] & 0x1f | (byte)((*(uint *)(param_2 + 0x20) & 7) << 5));
  ConvDefStructLocalTime2SiDBUInt64(pLVar1,&local_90,&local_102);
  param_4[0x10] = (recordStructure)((byte)param_4[0x10] & 1 | (char)local_102 << 1);
  *(uint *)(param_4 + 0x10) =
       *(uint *)(param_4 + 0x10) & 0xff000000 |
       *(uint *)(param_4 + 0x10) & 0xfff | ((uint)(local_90 >> 0x20) & 0xfff) << 0xc;
  *(int *)(param_4 + 0x14) = (int)local_90;
  rVar20 = param_4[6];
  bVar9 = (param_2[0x1c] & 1) << 4;
  bVar2 = (byte)rVar20 & 0xe0;
  param_4[6] = (recordStructure)(bVar2 | (byte)rVar20 & 0xf | bVar9);
  param_4[4] = (recordStructure)((byte)param_4[4] & 0xfe | param_2[0x24] & 1);
  param_4[7] = (recordStructure)((byte)param_4[7] & 0xf | param_2[0x25] << 4);
  bVar7 = (param_2[0x5f0] & 1) << 1;
  bVar3 = bVar2 | (byte)rVar20 & 0xc | bVar9;
  param_4[6] = (recordStructure)(bVar3 | (byte)rVar20 & 1 | bVar7);
  bVar4 = param_2[0x5f1];
  param_4[6] = (recordStructure)(bVar3 | bVar7 | bVar4 & 1);
  param_4[0x10] = (recordStructure)((byte)param_4[0x10] & 0xfe | param_2[0x5f2] & 1);
  bVar7 = bVar7 | bVar4 & 1 | (param_2[0x619] & 1) << 2;
  param_4[6] = (recordStructure)(bVar2 | (byte)rVar20 & 8 | bVar9 | bVar7);
  param_4[6] = (recordStructure)(bVar2 | bVar9 | bVar7 | (param_2[0x61a] & 1) << 3);
  if (*(int *)param_2 != 1) {
    if (*(int *)param_2 != 4) {
      return 0x407;
    }
    local_d0 = 0;
    local_20 = 0;
    local_40 = 0;
    local_38 = 0;
    local_30 = 0;
    local_28 = 0;
    if (param_2[0x26] != '\0') {
      local_40 = 1;
      uVar11 = defStruct2sidb_VideoCodec(*(undefined4 *)(param_2 + 0x28));
      local_38._0_3_ = CONCAT12(uVar11,(undefined2)local_38);
      uVar11 = defStruct2sidb_GopStructure(*(undefined4 *)(param_2 + 0x2c));
      local_38._0_4_ = CONCAT13(uVar11,(undefined3)local_38);
      uVar11 = defStruct2sidb_VideoResolution(*(undefined4 *)(param_2 + 0x30));
      local_38._0_5_ = CONCAT14(uVar11,(undefined4)local_38);
      uVar11 = defStruct2sidb_VideoAspect(*(undefined4 *)(param_2 + 0x34));
      local_38._0_6_ = CONCAT15(uVar11,(undefined5)local_38);
      uVar11 = defStruct2sidb_ColorFormat(*(undefined4 *)(param_2 + 0x38));
      local_38._0_7_ = CONCAT16(uVar11,(undefined6)local_38);
      uVar11 = defStruct2sidb_VideoBitDepth(*(undefined4 *)(param_2 + 0x3c));
      uVar18 = local_40;
      local_38 = CONCAT17(uVar11,(undefined7)local_38);
      uVar11 = 0;
      if (*(uint *)(param_2 + 0x40) < 0xd) {
        uVar11 = (&DAT_003e61c0)[*(uint *)(param_2 + 0x40)];
      }
      local_30 = CONCAT71(local_30._1_7_,uVar11);
      local_40._0_4_ = CONCAT22(*(undefined2 *)(param_2 + 0x44),(undefined2)local_40);
      local_40._6_2_ = SUB82(uVar18,6);
      local_40._0_6_ = CONCAT24(*(undefined2 *)(param_2 + 0x46),(uint)local_40);
      uVar11 = defStruct2sidb_CaptureGammaEquation(*(undefined4 *)(param_2 + 0x50));
      local_30._0_2_ = CONCAT11(uVar11,(undefined1)local_30);
      uVar11 = defStruct2sidb_ColorPrimaries(*(undefined4 *)(param_2 + 0x54));
      local_30._0_3_ = CONCAT12(uVar11,(undefined2)local_30);
      uVar11 = defStruct2sidb_CodingEquations(*(undefined4 *)(param_2 + 0x58));
      local_30._0_4_ = CONCAT13(uVar11,(undefined3)local_30);
      *(undefined4 *)(param_4 + 0x40) = *(undefined4 *)(param_2 + 0x48);
      *(undefined4 *)(param_4 + 0x44) = *(undefined4 *)(param_2 + 0x4c);
    }
    if (param_2[0x94] != '\0') {
      local_40 = local_40 | 4;
      uVar11 = defStruct2sidb_AudioCodec(*(undefined4 *)(param_2 + 0x98));
      local_28._0_7_ = CONCAT16(uVar11,(undefined6)local_28);
      uVar11 = defStruct2sidb_AudioBitLength(*(undefined4 *)(param_2 + 0x9c));
      local_28 = CONCAT17(uVar11,(undefined7)local_28);
      uVar11 = defStruct2sidb_AudioSamplingRate(*(undefined4 *)(param_2 + 0xa0));
      local_20 = CONCAT71(local_20._1_7_,uVar11);
      uVar11 = defStruct2sidb_AudioChannel(*(undefined4 *)(param_2 + 0xa4));
      local_20._0_2_ = CONCAT11(uVar11,(undefined1)local_20);
    }
    if (param_2[0x5c] != '\0') {
      local_40 = local_40 | 2;
      uVar11 = defStruct2sidb_VideoCodec(*(undefined4 *)(param_2 + 0x60));
      local_30._0_5_ = CONCAT14(uVar11,(undefined4)local_30);
      uVar11 = defStruct2sidb_GopStructure(*(undefined4 *)(param_2 + 100));
      local_30._0_6_ = CONCAT15(uVar11,(undefined5)local_30);
      uVar11 = defStruct2sidb_VideoResolution(*(undefined4 *)(param_2 + 0x68));
      local_30._0_7_ = CONCAT16(uVar11,(undefined6)local_30);
      uVar11 = defStruct2sidb_VideoAspect(*(undefined4 *)(param_2 + 0x6c));
      local_30 = CONCAT17(uVar11,(undefined7)local_30);
      uVar11 = defStruct2sidb_ColorFormat(*(undefined4 *)(param_2 + 0x70));
      local_28 = CONCAT71(local_28._1_7_,uVar11);
      uVar12 = defStruct2sidb_VideoBitDepth(*(undefined4 *)(param_2 + 0x74));
      uVar18 = local_28;
      uVar11 = 0;
      if (*(uint *)(param_2 + 0x78) < 0xd) {
        uVar11 = (&DAT_003e61c0)[*(uint *)(param_2 + 0x78)];
      }
      local_28._3_5_ = SUB85(uVar18,3);
      local_28._0_3_ = CONCAT12(uVar11,CONCAT11(uVar12,(undefined1)local_28));
      local_40 = CONCAT26(*(undefined2 *)(param_2 + 0x7c),(undefined6)local_40);
      local_38 = CONCAT62(local_38._2_6_,*(undefined2 *)(param_2 + 0x7e));
      uVar11 = defStruct2sidb_CaptureGammaEquation(*(undefined4 *)(param_2 + 0x88));
      local_28._0_4_ = CONCAT13(uVar11,(undefined3)local_28);
      uVar11 = defStruct2sidb_ColorPrimaries(*(undefined4 *)(param_2 + 0x8c));
      local_28._0_5_ = CONCAT14(uVar11,(undefined4)local_28);
      uVar11 = defStruct2sidb_CodingEquations(*(undefined4 *)(param_2 + 0x90));
      local_28._0_6_ = CONCAT15(uVar11,(undefined5)local_28);
      *(undefined4 *)(param_4 + 0x48) = *(undefined4 *)(param_2 + 0x80);
      *(undefined4 *)(param_4 + 0x4c) = *(undefined4 *)(param_2 + 0x84);
    }
    if (param_2[0xa8] != '\0') {
      local_40 = local_40 | 8;
      uVar11 = defStruct2sidb_AudioCodec(*(undefined4 *)(param_2 + 0xac));
      local_20._0_3_ = CONCAT12(uVar11,(undefined2)local_20);
      uVar11 = defStruct2sidb_AudioBitLength(*(undefined4 *)(param_2 + 0xb0));
      local_20._0_4_ = CONCAT13(uVar11,(undefined3)local_20);
      uVar11 = defStruct2sidb_AudioSamplingRate(*(undefined4 *)(param_2 + 0xb4));
      local_20._0_5_ = CONCAT14(uVar11,(undefined4)local_20);
      uVar11 = defStruct2sidb_AudioChannel(*(undefined4 *)(param_2 + 0xb8));
      local_20._0_6_ = CONCAT15(uVar11,(undefined5)local_20);
    }
    iVar17 = SearchBinaryRecord(param_1,(uchar *)&local_40,0x28,&local_d0);
    if ((iVar17 != 0) &&
       (uVar18 = CreateBinaryRecord(param_1,(uchar *)&local_40,0x28,&local_d0), (int)uVar18 != 0)) {
      return uVar18;
    }
    *(short *)(param_4 + 0x58) = (short)local_d0;
    param_4[0x5c] =
         (recordStructure)
         ((byte)param_4[0x5c] & 0xe0 |
         (byte)param_4[0x5c] & 0xf | (byte)((local_d0 >> 0x10 & 1) << 4));
    local_d8 = 0;
    local_cc = 0;
    local_c8 = 0;
    local_c4 = 0;
    local_c0 = 0;
    if (param_2[0xc0] != '\0') {
      FUN_00392954(uVar23,*(long *)(PTR_gp_db_004017c8 + uVar23 * 8) + 0x7c4c,param_2 + 0x4f8,
                   &local_e8,&local_cc,&local_c4,&local_d8);
      *(undefined2 *)(param_4 + 0x5f) = (undefined2)local_e8;
      param_4[0x61] = local_e8._2_1_;
    }
    if (param_2[0x3d5] != '\0') {
      FUN_00392954(uVar23,*(long *)(PTR_gp_db_004017c8 + uVar23 * 8) + 0x7c4c,param_2 + 0x558,
                   &local_e0,&local_c8,&local_c0,(long)&local_d8 + 3);
      *(undefined2 *)(param_4 + 0x62) = (undefined2)local_e0;
      param_4[100] = local_e0._2_1_;
    }
    puVar8 = PTR_gp_db_004017c8;
    uVar25 = (ulong)local_cc;
    if (local_cc == 0) {
      uVar25 = (ulong)local_c8;
      if (local_c8 == 0) {
        rVar20 = (recordStructure)0x0;
        uVar16 = 0;
      }
      else {
        rVar20 = *(recordStructure *)(param_2 + 0x56f);
        uVar16 = local_c0;
      }
    }
    else {
      rVar20 = *(recordStructure *)(param_2 + 0x50f);
      uVar16 = local_c4;
    }
    rVar10 = param_4[0x5c];
    uVar15 = *(ushort *)(param_4 + 0x5a);
    uVar24 = (uint)uVar25;
    *(short *)(param_4 + 0x5a) = (short)uVar25;
    uVar21 = (uint)uVar15 | ((byte)rVar10 >> 5 & 1) << 0x10;
    param_4[0x5e] = rVar20;
    param_4[0x5c] =
         (recordStructure)
         ((byte)rVar10 & 0xc0 | (byte)rVar10 & 0x1f | (byte)(((uint)(uVar25 >> 0x10) & 1) << 5));
    param_4[0x5d] = (recordStructure)((byte)param_4[0x5d] & 0xf | (byte)((uVar16 & 0xf) << 4));
    pfVar27 = *(fileStructure **)(puVar8 + uVar23 * 8);
    if (uVar21 == 0) {
      if (uVar24 == 0) goto LAB_0039365c;
    }
    else {
      if (uVar24 == 0) {
        DecrementArrayBinaryRecordRefCount(param_1,pfVar27,uVar21);
        goto LAB_0039365c;
      }
      if (uVar24 == uVar21) goto LAB_0039365c;
      DecrementArrayBinaryRecordRefCount(param_1,pfVar27,uVar21);
    }
    IncrementArrayBinaryRecordRefCount(param_1,pfVar27,uVar24);
LAB_0039365c:
    local_bc[0] = 0;
    local_bc[1] = 0;
    local_bc[2] = 0;
    local_bc[3] = 0;
    local_bc[4] = 0;
    local_bc[5] = 0;
    local_bc[6] = 0;
    local_bc[7] = 0;
    if (*(int *)(param_2 + 0x614) == 1) {
      if (param_2[0x3d5] == '\0') {
        iVar17 = 0;
        pcVar26 = (char *)0x0;
      }
      else {
        pcVar26 = param_2 + 0x3d6;
        uVar18 = FUN_00392014(uVar23,pcVar26,0xfffffff5,0xfffffff8,pLVar1,local_bc + 3,local_bc + 7)
        ;
        if ((int)uVar18 != 0) {
          return uVar18;
        }
        iVar17 = 3;
      }
      uVar16 = local_bc[7];
      if (param_2[0x2ce] != '\0') {
        pcVar26 = param_2 + 0x2cf;
        uVar18 = FUN_00392014(uVar23,pcVar26,0xfffffff5,0xfffffff8,pLVar1,local_bc + 2,local_bc + 6)
        ;
        if ((int)uVar18 != 0) {
          return uVar18;
        }
        iVar17 = 3;
        uVar16 = local_bc[6];
      }
      if (param_2[0x1c7] != '\0') {
        pcVar26 = param_2 + 0x1c8;
        uVar18 = FUN_00392014(uVar23,pcVar26,0xfffffff5,0xfffffff8,pLVar1,local_bc + 1,local_bc + 5)
        ;
        if ((int)uVar18 != 0) {
          return uVar18;
        }
        iVar17 = 3;
        uVar16 = local_bc[5];
      }
      if (param_2[0xc0] != '\0') {
        pcVar26 = param_2 + 0xc1;
        uVar18 = FUN_00392014(uVar23,pcVar26,0xfffffff8,0xfffffffb,pLVar1,local_bc,local_bc + 4);
        if ((int)uVar18 != 0) {
          return uVar18;
        }
        iVar17 = 0;
        uVar16 = local_bc[4];
      }
    }
    else {
      if (*(int *)(param_2 + 0x614) != 2) {
        return 0x403;
      }
      if (param_2[0x3d5] == '\0') {
        iVar17 = 0;
        pcVar26 = (char *)0x0;
      }
      else {
        pcVar26 = param_2 + 0x3d6;
        uVar18 = FUN_00392244(uVar23,pcVar26,0xffffffe9,pLVar1,local_bc + 3,local_bc + 7);
        if ((int)uVar18 != 0) {
          return uVar18;
        }
        iVar17 = 3;
      }
      uVar16 = local_bc[7];
      if (param_2[0x2ce] != '\0') {
        pcVar26 = param_2 + 0x2cf;
        uVar18 = FUN_00392244(uVar23,pcVar26,0xffffffe9,pLVar1,local_bc + 2,local_bc + 6);
        if ((int)uVar18 != 0) {
          return uVar18;
        }
        iVar17 = 3;
        uVar16 = local_bc[6];
      }
      if (param_2[0x1c7] != '\0') {
        pcVar26 = param_2 + 0x1c8;
        uVar18 = FUN_00392244(uVar23,pcVar26,0xffffffe9,pLVar1,local_bc + 1,local_bc + 5);
        if ((int)uVar18 != 0) {
          return uVar18;
        }
        iVar17 = 3;
        uVar16 = local_bc[5];
      }
      if (param_2[0xc0] != '\0') {
        pcVar26 = param_2 + 0xc1;
        uVar18 = FUN_00392244(uVar23,pcVar26,0xffffffec,pLVar1,local_bc,local_bc + 4);
        if ((int)uVar18 != 0) {
          return uVar18;
        }
        iVar17 = 0;
        uVar16 = local_bc[4];
      }
      iVar6 = uVar16 - iVar17;
      uVar23 = str2uint16(pcVar26,iVar6 - 0x14,iVar6 - 0x12);
      param_4[0x85] = SUB81(uVar23 >> 2,0);
      param_4[0x84] =
           (recordStructure)((byte)param_4[0x84] & 0x3f | (byte)(((uint)uVar23 & 3) << 6));
      param_4[0x86] = *(recordStructure *)(pcVar26 + (iVar6 - 0x11));
      *(undefined2 *)(param_4 + 0x87) = *(undefined2 *)(pcVar26 + (iVar6 - 6));
    }
    *(short *)(param_4 + 0x50) = (short)local_bc[0];
    *(short *)(param_4 + 0x52) = (short)local_bc[1];
    *(short *)(param_4 + 0x54) = (short)local_bc[2];
    *(short *)(param_4 + 0x56) = (short)local_bc[3];
    param_4[0x5c] =
         (recordStructure)((byte)param_4[0x5c] & 0xf0 | (byte)((local_bc[3] >> 0x10 & 1) << 3));
    *(ushort *)(param_4 + 0xc) = *(ushort *)(param_4 + 0xc) & 0x3f;
    if (*(int *)(param_2 + 0x614) == 1) {
      uVar15 = str2uint16(pcVar26,(uVar16 - iVar17) - 8,(uVar16 - iVar17) - 5);
      uVar23 = (ulong)uVar15;
    }
    else {
      uVar23 = 0;
      if (*(int *)(param_2 + 0x614) == 2) {
        pcVar22 = (char *)0xffffffffffffffff;
        local_88[0] = auStack_78;
        if (pcVar26 != (char *)0x0) {
          sVar19 = strlen(pcVar26);
          pcVar22 = pcVar26 + sVar19;
        }
        uVar23 = 0;
        FUN_00389624(local_88,pcVar26,pcVar22);
        std::__cxx11::string::substr((ulong)local_88,(ulong)((uVar16 + -0x11) - iVar17));
        if (local_68 != (byte *)0x0) {
          uVar15 = *local_68 - 0x41;
          if ((0x19 < (uVar15 & 0xff)) && (uVar15 = *local_68 - 0x61, 0x19 < (uVar15 & 0xff))) {
            uVar15 = 0;
          }
          local_bc[8] = 0;
          sscanf((char *)(local_68 + 1),"%d");
          uVar23 = (ulong)(ushort)((short)local_bc[8] + 10000 + uVar15 * 1000);
        }
        std::__cxx11::string::_M_dispose();
        std::__cxx11::string::_M_dispose();
      }
    }
    param_4[0xe] = (recordStructure)((byte)param_4[0xe] & 0xfc | (byte)(uVar23 >> 0xe));
    *(ushort *)(param_4 + 0xe) =
         *(ushort *)(param_4 + 0xe) & 3 | (ushort)(((uint)uVar23 & 0x3fff) << 2);
    rVar20 = param_4[0x6b];
    iVar17 = *(int *)(param_2 + 0x578);
    bVar9 = (byte)iVar17 & 3;
    param_4[0x6b] = (recordStructure)((byte)rVar20 & 0xfc | bVar9);
    rVar10 = param_4[0x84];
    bVar7 = (byte)rVar10 & 0xf | (byte)((iVar17 >> 2 & 1U) << 4);
    param_4[0x84] = (recordStructure)((byte)rVar10 & 0xe0 | bVar7);
    uVar16 = *(uint *)(param_2 + 0x57c);
    bVar9 = bVar9 | (byte)((uVar16 & 3) << 2);
    param_4[0x6b] = (recordStructure)((byte)rVar20 & 0xf0 | bVar9);
    param_4[0x84] =
         (recordStructure)((byte)rVar10 & 0xc0 | bVar7 | (byte)(((int)uVar16 >> 2 & 1U) << 5));
    bVar9 = bVar9 | (byte)((*(uint *)(param_2 + 0x580) & 3) << 4);
    param_4[0x6b] = (recordStructure)((byte)rVar20 & 0xc0 | bVar9);
    param_4[0x6b] = (recordStructure)(bVar9 | (byte)((*(uint *)(param_2 + 0x584) & 3) << 6));
    rVar20 = param_4[0x6c];
    bVar9 = (byte)*(undefined4 *)(param_2 + 0x588) & 3;
    param_4[0x6c] = (recordStructure)((byte)rVar20 & 0xfc | bVar9);
    bVar9 = bVar9 | (byte)((*(uint *)(param_2 + 0x58c) & 3) << 2);
    param_4[0x6c] = (recordStructure)((byte)rVar20 & 0xf0 | bVar9);
    bVar9 = bVar9 | (byte)((*(uint *)(param_2 + 0x590) & 3) << 4);
    param_4[0x6c] = (recordStructure)((byte)rVar20 & 0xc0 | bVar9);
    param_4[0x6c] = (recordStructure)(bVar9 | (byte)((*(uint *)(param_2 + 0x594) & 3) << 6));
    rVar20 = param_4[0x6f];
    bVar3 = (byte)((*(uint *)(param_2 + 0x598) & 3) << 2);
    bVar9 = (byte)rVar20 & 3 | bVar3;
    param_4[0x6f] = (recordStructure)((byte)rVar20 & 0xf0 | bVar9);
    rVar10 = param_4[0x6d];
    bVar7 = (byte)rVar20 & 0xc0;
    bVar2 = (byte)((*(uint *)(param_2 + 0x59c) & 3) << 4);
    param_4[0x6f] = (recordStructure)(bVar7 | bVar9 | bVar2);
    bVar9 = (byte)*(undefined4 *)(param_2 + 0x5a0) & 3;
    param_4[0x6d] = (recordStructure)((byte)rVar10 & 0xfc | bVar9);
    bVar9 = bVar9 | (byte)((*(uint *)(param_2 + 0x5a4) & 3) << 2);
    param_4[0x6d] = (recordStructure)((byte)rVar10 & 0xf0 | bVar9);
    bVar9 = bVar9 | (byte)((*(uint *)(param_2 + 0x5a8) & 3) << 4);
    param_4[0x6d] = (recordStructure)((byte)rVar10 & 0xc0 | bVar9);
    param_4[0x6d] = (recordStructure)(bVar9 | (byte)((*(uint *)(param_2 + 0x5ac) & 3) << 6));
    param_4[0x5c] =
         (recordStructure)
         ((byte)param_4[0x5c] & 0x3f | (byte)((*(uint *)(param_2 + 0x604) & 3) << 6));
    rVar10 = param_4[0x6e];
    bVar9 = param_2[0x608];
    param_4[0x6e] = (recordStructure)((byte)rVar10 & 0xfe | bVar9 & 1);
    bVar9 = bVar9 & 1 | (param_2[0x609] & 1) << 1;
    param_4[0x6e] = (recordStructure)((byte)rVar10 & 0xfc | bVar9);
    bVar9 = bVar9 | (param_2[0x60a] & 1) << 2;
    param_4[0x6e] = (recordStructure)((byte)rVar10 & 0xf8 | bVar9);
    bVar9 = bVar9 | (param_2[0x60b] & 1) << 3;
    param_4[0x6e] = (recordStructure)((byte)rVar10 & 0xf0 | bVar9);
    bVar9 = bVar9 | (param_2[0x60c] & 1) << 4;
    param_4[0x6e] = (recordStructure)((byte)rVar10 & 0xe0 | bVar9);
    bVar9 = bVar9 | (param_2[0x60d] & 1) << 5;
    param_4[0x6e] = (recordStructure)((byte)rVar10 & 0xc0 | bVar9);
    bVar9 = bVar9 | (param_2[0x60e] & 1) << 6;
    param_4[0x6e] = (recordStructure)((byte)rVar10 & 0x80 | bVar9);
    param_4[0x6e] = (recordStructure)(bVar9 | param_2[0x60f] << 7);
    bVar9 = param_2[0x610];
    param_4[0x6f] = (recordStructure)(bVar7 | (byte)rVar20 & 2 | bVar3 | bVar2 | bVar9 & 1);
    bVar9 = bVar9 & 1 | (param_2[0x611] & 1) << 1;
    param_4[0x6f] = (recordStructure)(bVar7 | bVar3 | bVar2 | bVar9);
    uVar18 = *(undefined8 *)(param_2 + 0x4e0);
    *(int *)(param_4 + 0x70) = (int)((ulong)uVar18 >> 0x20);
    *(int *)(param_4 + 0x74) = (int)uVar18;
    *(int *)(param_4 + 0x78) = (int)*(undefined8 *)(param_2 + 0x4f0);
    uVar18 = *(undefined8 *)(param_2 + 0x4e8);
    *(int *)(param_4 + 0x7c) = (int)((ulong)uVar18 >> 0x20);
    *(int *)(param_4 + 0x80) = (int)uVar18;
    param_4[0x6f] =
         (recordStructure)((byte)rVar20 & 0x80 | bVar3 | bVar2 | bVar9 | (param_2[0x618] & 1) << 6);
    return 0;
  }
  if (param_2[0x94] != '\0') {
    local_40 = local_40 & 0xffffffff00000000;
    uVar11 = defStruct2sidb_AudioCodec(*(undefined4 *)(param_2 + 0x98));
    local_68 = (byte *)CONCAT71(local_68._1_7_,uVar11);
    uVar11 = defStruct2sidb_AudioBitLength(*(undefined4 *)(param_2 + 0x9c));
    local_68._0_2_ = CONCAT11(uVar11,(uchar)local_68);
    uVar11 = defStruct2sidb_AudioSamplingRate(*(undefined4 *)(param_2 + 0xa0));
    local_68._0_3_ = CONCAT12(uVar11,(undefined2)local_68);
    uVar11 = defStruct2sidb_AudioChannel(*(undefined4 *)(param_2 + 0xa4));
    local_68._0_4_ = CONCAT13(uVar11,(undefined3)local_68);
    iVar17 = SearchBinaryRecord(param_1,(uchar *)&local_68,4,(uint *)&local_40);
    if ((iVar17 != 0) &&
       (uVar18 = CreateBinaryRecord(param_1,(uchar *)&local_68,4,(uint *)&local_40),
       (int)uVar18 != 0)) {
      return uVar18;
    }
    *(short *)(param_4 + 0x48) = (short)local_40;
    param_4[0x4c] =
         (recordStructure)
         ((byte)param_4[0x4c] & 0xe0 |
         (byte)param_4[0x4c] & 0xf | (byte)(((uint)local_40 >> 0x10 & 1) << 4));
  }
  local_e8 = 0;
  local_e0 = 0;
  local_d8 = 0;
  local_d0 = 0;
  local_cc = 0;
  local_c8 = 0;
  local_c4 = 0;
  if (param_2[0xc0] == '\0') {
    if (param_2[0x2ce] != '\0') {
      FUN_00392954(uVar23,*(long *)(PTR_gp_db_004017c8 + uVar23 * 8) + 0x7c4c,param_2 + 0x544,
                   &local_f0,&local_d0,&local_c4,(long)&local_e8 + 1);
      *(undefined2 *)(param_4 + 0x4f) = local_f0;
      local_fe = local_ee;
      goto LAB_00392c90;
    }
  }
  else {
    FUN_00392954(uVar23,*(long *)(PTR_gp_db_004017c8 + uVar23 * 8) + 0x7c4c,param_2 + 0x504,
                 &local_100,&local_e0,&local_cc,&local_e8);
    *(undefined2 *)(param_4 + 0x4f) = local_100;
LAB_00392c90:
    param_4[0x51] = local_fe;
  }
  if (param_2[0x1c7] != '\0') {
    FUN_00392954(uVar23,*(long *)(PTR_gp_db_004017c8 + uVar23 * 8) + 0x7c4c,param_2 + 0x524,
                 &local_f8,&local_d8,&local_c8,(long)&local_e8 + 2);
    *(undefined2 *)(param_4 + 0x52) = local_f8;
    param_4[0x54] = local_f6;
  }
  uVar25 = (ulong)local_e0;
  if (local_e0 == 0) {
    uVar25 = (ulong)local_d8;
    if (local_d8 == 0) {
      uVar25 = (ulong)local_d0;
      if (local_d0 == 0) {
        rVar20 = (recordStructure)0x0;
        uVar16 = 0;
      }
      else {
        rVar20 = *(recordStructure *)(param_2 + 0x55b);
        uVar16 = local_c4;
      }
    }
    else {
      rVar20 = *(recordStructure *)(param_2 + 0x53b);
      uVar16 = local_c8;
    }
  }
  else {
    rVar20 = *(recordStructure *)(param_2 + 0x51b);
    uVar16 = local_cc;
  }
  rVar10 = param_4[0x4c];
  uVar15 = *(ushort *)(param_4 + 0x4a);
  uVar24 = (uint)uVar25;
  *(short *)(param_4 + 0x4a) = (short)uVar25;
  param_4[0x4e] = rVar20;
  uVar21 = (uint)uVar15 | ((byte)rVar10 >> 5 & 1) << 0x10;
  param_4[0x4c] =
       (recordStructure)
       ((byte)rVar10 & 0xc0 | (byte)rVar10 & 0x1f | (byte)(((uint)(uVar25 >> 0x10) & 1) << 5));
  param_4[0x4d] = (recordStructure)((byte)param_4[0x4d] & 0xf | (byte)((uVar16 & 0xf) << 4));
  pfVar27 = *(fileStructure **)(PTR_gp_db_004017c8 + uVar23 * 8);
  if (uVar21 == 0) {
    if (uVar24 != 0) {
LAB_00392d28:
      IncrementArrayBinaryRecordRefCount(param_1,pfVar27,uVar24);
    }
  }
  else if (uVar24 == 0) {
    DecrementArrayBinaryRecordRefCount(param_1,pfVar27,uVar21);
  }
  else if (uVar24 != uVar21) {
    DecrementArrayBinaryRecordRefCount(param_1,pfVar27,uVar21);
    goto LAB_00392d28;
  }
  __s1 = param_2 + 0x5f3;
  local_101 = 0;
  local_40 = 0;
  local_38 = 0;
  local_c0 = 0;
  local_bc[0] = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_10 = 0;
  uStack_8 = 0;
  iVar17 = memcmp(__s1,&local_40,0x10);
  if (iVar17 != 0) {
    iVar17 = SearchArrayBinaryRecord(uVar23,3,__s1,0x10,&local_c0,local_bc);
    if ((iVar17 != 0) &&
       (uVar18 = CreateArrayBinaryRecord
                           (uVar23,3,*(long *)(PTR_gp_db_004017c8 + uVar23 * 8) + 0x7c50,__s1,0x10,
                            &local_c0,local_bc,&local_101), (int)uVar18 != 0)) {
      return uVar18;
    }
  }
  uVar16 = (uint)*(ushort *)(param_4 + 0x58) | ((byte)param_4[0x5a] >> 3 & 1) << 0x10;
  *(short *)(param_4 + 0x58) = (short)local_c0;
  param_4[0x5a] =
       (recordStructure)
       ((byte)param_4[0x5a] & 7 | (byte)((local_c0 >> 0x10 & 1) << 3) |
       (byte)((local_bc[0] & 0xf) << 4));
  if (uVar16 == 0) {
    if (local_c0 != 0) {
LAB_00393184:
      IncrementArrayBinaryRecordRefCount(param_1,pfVar27,local_c0);
    }
  }
  else if (local_c0 == 0) {
    DecrementArrayBinaryRecordRefCount(param_1,pfVar27,uVar16);
  }
  else if (uVar16 != local_c0) {
    DecrementArrayBinaryRecordRefCount(param_1,pfVar27,uVar16);
    goto LAB_00393184;
  }
  local_bc[1] = 0;
  local_bc[2] = 0;
  local_bc[3] = 0;
  local_bc[4] = 0;
  local_bc[5] = 0;
  local_bc[6] = 0;
  local_bc[7] = 0;
  local_bc[8] = 0;
  if (param_2[0x3d5] == '\0') {
    pcVar26 = (char *)0x0;
  }
  else {
    pcVar26 = param_2 + 0x3d6;
    uVar18 = FUN_00391f1c(uVar23,pcVar26,local_bc + 4,local_bc + 8);
    if ((int)uVar18 != 0) {
      return uVar18;
    }
  }
  uVar16 = local_bc[8];
  if (param_2[0x2ce] != '\0') {
    pcVar26 = param_2 + 0x2cf;
    uVar18 = FUN_00391f1c(uVar23,pcVar26,local_bc + 3,local_bc + 7);
    uVar16 = local_bc[7];
    if ((int)uVar18 != 0) {
      return uVar18;
    }
  }
  if (param_2[0x1c7] != '\0') {
    pcVar26 = param_2 + 0x1c8;
    uVar18 = FUN_00391f1c(uVar23,pcVar26,local_bc + 2,local_bc + 6);
    uVar16 = local_bc[6];
    if ((int)uVar18 != 0) {
      return uVar18;
    }
  }
  if (param_2[0xc0] != '\0') {
    pcVar26 = param_2 + 0xc1;
    uVar18 = FUN_00391f1c(uVar23,pcVar26,local_bc + 1,local_bc + 5);
    uVar16 = local_bc[5];
    if ((int)uVar18 != 0) {
      return uVar18;
    }
  }
  *(short *)(param_4 + 0x40) = (short)local_bc[1];
  *(short *)(param_4 + 0x42) = (short)local_bc[2];
  *(short *)(param_4 + 0x44) = (short)local_bc[3];
  *(short *)(param_4 + 0x46) = (short)local_bc[4];
  rVar20 = param_4[0x6e];
  param_4[0x4c] =
       (recordStructure)((byte)param_4[0x4c] & 0xf0 | (byte)((local_bc[4] >> 0x10 & 1) << 3));
  cVar5 = param_2[0xc0];
  if (cVar5 == '\0') {
    if (param_2[0x2ce] != '\0') {
      iVar17 = *(int *)(param_2 + 0x58c);
      rVar10 = (recordStructure)((byte)param_4[0x5b] & 0xfc | (byte)iVar17 & 3);
      param_4[0x5b] = rVar10;
      param_4[0x6e] =
           (recordStructure)
           ((byte)rVar20 & 0x80 | (byte)rVar20 & 0x3f | (byte)((iVar17 >> 2 & 1U) << 6));
      uVar21 = *(uint *)(param_2 + 0x590);
      goto LAB_00393000;
    }
  }
  else {
    iVar17 = *(int *)(param_2 + 0x584);
    rVar10 = (recordStructure)((byte)param_4[0x5b] & 0xfc | (byte)iVar17 & 3);
    param_4[0x5b] = rVar10;
    param_4[0x6e] =
         (recordStructure)
         ((byte)rVar20 & 0x80 | (byte)rVar20 & 0x3f | (byte)((iVar17 >> 2 & 1U) << 6));
    uVar21 = *(uint *)(param_2 + 0x588);
LAB_00393000:
    param_4[0x5b] =
         (recordStructure)((byte)rVar10 & 0xf0 | (byte)rVar10 & 3 | (byte)((uVar21 & 3) << 2));
  }
  uVar21 = *(uint *)(param_2 + 0x594);
  bVar9 = (byte)param_4[0x5b] & 0xf | (byte)((uVar21 & 3) << 4);
  param_4[0x5b] = (recordStructure)((byte)param_4[0x5b] & 0xc0 | bVar9);
  param_4[0x6e] =
       (recordStructure)((byte)param_4[0x6e] & 0x7f | (byte)(((int)uVar21 >> 2 & 1U) << 7));
  param_4[0x5b] = (recordStructure)(bVar9 | (byte)((*(uint *)(param_2 + 0x598) & 3) << 6));
  rVar20 = param_4[0x5c];
  bVar9 = (byte)*(undefined4 *)(param_2 + 0x59c) & 3;
  param_4[0x5c] = (recordStructure)((byte)rVar20 & 0xfc | bVar9);
  if (cVar5 == '\0') {
    if (param_2[0x2ce] != '\0') {
      rVar20 = (recordStructure)
               ((byte)rVar20 & 0xf0 | bVar9 | (byte)((*(uint *)(param_2 + 0x5a8) & 3) << 2));
      param_4[0x5c] = rVar20;
      uVar21 = *(uint *)(param_2 + 0x5ac);
      goto LAB_00393058;
    }
  }
  else {
    rVar20 = (recordStructure)
             ((byte)rVar20 & 0xf0 | bVar9 | (byte)((*(uint *)(param_2 + 0x5a0) & 3) << 2));
    param_4[0x5c] = rVar20;
    uVar21 = *(uint *)(param_2 + 0x5a4);
LAB_00393058:
    param_4[0x5c] =
         (recordStructure)((byte)rVar20 & 0xc0 | (byte)rVar20 & 0xf | (byte)((uVar21 & 3) << 4));
  }
  param_4[0x5c] =
       (recordStructure)((byte)param_4[0x5c] & 0x3f | (byte)((*(uint *)(param_2 + 0x5b0) & 3) << 6))
  ;
  rVar20 = param_4[0x5d];
  bVar9 = (byte)*(undefined4 *)(param_2 + 0x5b4) & 3;
  param_4[0x5d] = (recordStructure)((byte)rVar20 & 0xfc | bVar9);
  bVar9 = bVar9 | (byte)((*(uint *)(param_2 + 0x5b8) & 3) << 2);
  param_4[0x5d] = (recordStructure)((byte)rVar20 & 0xf0 | bVar9);
  if (cVar5 == '\0') {
    if (param_2[0x2ce] != '\0') {
      rVar20 = (recordStructure)
               ((byte)rVar20 & 0xc0 | bVar9 | (byte)((*(uint *)(param_2 + 0x5c0) & 3) << 4));
      param_4[0x5d] = rVar20;
      uVar21 = *(uint *)(param_2 + 0x5c8);
      goto LAB_003930a0;
    }
  }
  else {
    rVar20 = (recordStructure)
             ((byte)rVar20 & 0xc0 | bVar9 | (byte)((*(uint *)(param_2 + 0x5bc) & 3) << 4));
    param_4[0x5d] = rVar20;
    uVar21 = *(uint *)(param_2 + 0x5c4);
LAB_003930a0:
    param_4[0x5d] = (recordStructure)((byte)rVar20 & 0x3f | (byte)((uVar21 & 3) << 6));
  }
  rVar20 = param_4[0x5e];
  bVar9 = (byte)*(undefined4 *)(param_2 + 0x5cc) & 3;
  param_4[0x5e] = (recordStructure)((byte)rVar20 & 0xfc | bVar9);
  bVar9 = bVar9 | (byte)((*(uint *)(param_2 + 0x5d0) & 3) << 2);
  param_4[0x5e] = (recordStructure)((byte)rVar20 & 0xf0 | bVar9);
  param_4[0x5e] =
       (recordStructure)
       ((byte)rVar20 & 0xc0 | bVar9 | (byte)((*(uint *)(param_2 + 0x5d4) & 3) << 4));
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = *(byte **)(param_2 + 0x4dc);
  local_60 = (ulong)*(uint *)(param_2 + 0x4e4);
  iVar17 = SearchBinaryRecord(param_1,(uchar *)&local_68,0x24,(uint *)local_88);
  if ((iVar17 != 0) &&
     (uVar18 = CreateBinaryRecord(param_1,(uchar *)&local_68,0x24,(uint *)local_88),
     (int)uVar18 != 0)) {
    return uVar18;
  }
  *(short *)(param_4 + 0x6c) = (short)(uint)local_88[0];
  param_4[0x4c] =
       (recordStructure)
       ((byte)param_4[0x4c] & 0x80 |
       (byte)param_4[0x4c] & 0x3f | (byte)(((uint)local_88[0] >> 0x10 & 1) << 6));
  if (param_2[0xc0] == '\0') {
    if (param_2[0x2ce] == '\0') goto LAB_0039322c;
    *(undefined4 *)(param_4 + 0x60) = *(undefined4 *)(param_2 + 0x4f8);
    uVar13 = *(undefined2 *)(param_2 + 0x4fc);
  }
  else {
    *(undefined4 *)(param_4 + 0x60) = *(undefined4 *)(param_2 + 0x4e8);
    uVar13 = *(undefined2 *)(param_2 + 0x4ec);
  }
  *(undefined2 *)(param_4 + 0x68) = uVar13;
LAB_0039322c:
  *(undefined4 *)(param_4 + 100) = *(undefined4 *)(param_2 + 0x4f0);
  *(undefined2 *)(param_4 + 0x6a) = *(undefined2 *)(param_2 + 0x4f4);
  *(undefined4 *)(param_4 + 0x70) = *(undefined4 *)(param_2 + 0x500);
  bVar9 = (byte)param_4[0x5e] & 0x3f | (param_2[0x612] & 1) << 6;
  param_4[0x5e] = (recordStructure)((byte)param_4[0x5e] & 0x80 | bVar9);
  param_4[0x5e] = (recordStructure)(bVar9 | param_2[0x613] << 7);
  sVar14 = str2uint16(pcVar26,uVar16 - 0x15,uVar16 - 0x13);
  *(ushort *)(param_4 + 0xc) = *(ushort *)(param_4 + 0xc) & 0x3f | sVar14 << 6;
  uVar16 = str2uint16(pcVar26,uVar16 - 8,uVar16 - 5);
  param_4[0xe] = (recordStructure)((byte)param_4[0xe] & 0xfc | (byte)(uVar16 >> 0xe) & 3);
  *(ushort *)(param_4 + 0xe) = *(ushort *)(param_4 + 0xe) & 3 | (ushort)((uVar16 & 0x3fff) << 2);
  return 0;
}

