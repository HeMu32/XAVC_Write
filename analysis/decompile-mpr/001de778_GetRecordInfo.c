// mpr::GetRecordInfo
// Ghidra address: 001de778

/* mpr::GetRecordInfo(unsigned int, sidb::recordInfo&) */

int mpr::GetRecordInfo(uint param_1,recordInfo *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 local_178;
  ClipStatus aCStack_174 [4];
  undefined2 local_170;
  undefined2 local_16e;
  undefined1 local_16c;
  undefined1 local_16b;
  undefined1 local_16a;
  undefined1 local_169;
  int local_168;
  undefined4 *local_160;
  undefined4 *puStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  MoviePropertyInfo aMStack_130 [12];
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined2 local_104;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  MoviePropertyInfo aMStack_e8 [12];
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined2 local_bc;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined2 local_a0;
  undefined2 local_9e;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a;
  undefined1 local_99;
  undefined1 local_98;
  undefined8 local_96;
  undefined8 uStack_8e;
  undefined8 local_86;
  undefined8 uStack_7e;
  undefined4 local_74;
  undefined4 local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  undefined1 local_58;
  undefined2 local_50;
  undefined2 local_4e;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  undefined4 local_48;
  undefined6 uStack_44;
  undefined8 uStack_3e;
  undefined8 local_36;
  undefined8 uStack_2e;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  local_4c = 3;
  local_50 = 0x2110;
  local_4e = 0x130;
  local_4b = 0;
  local_4a = 0;
  local_49 = 0;
  local_48 = param_1;
  FUN_001c9f24((BasicInformation *)&local_50,0xc);
  FUN_001cb454(aMStack_130);
  FUN_001cb454(aMStack_e8);
  FUN_001ca54c((BasicInformation *)&local_a0);
  FUN_001ca54c((BasicInformation *)&local_50);
  local_160 = (undefined4 *)0x0;
  puStack_158 = (undefined4 *)0x0;
  local_150 = 0;
  uStack_148 = 0;
  local_140 = 0;
  uStack_138 = 0;
  iVar2 = GetRecordInfoFromMp4(param_2 + 0xc1,aMStack_130);
  if (iVar2 == 0) {
    iVar3 = GetRecordInfoFromNrtMeta
                      (param_2 + 0xc1,(BasicInformation *)&local_a0,(vector *)&local_160,
                       (ClipStatus *)&local_178);
    iVar2 = iVar3;
    if (iVar3 == 0) {
      if (param_2[0x3d5] != '\0') {
        iVar2 = GetRecordInfoFromMp4(param_2 + 0x3d6,aMStack_e8);
        if (iVar2 != 0) goto LAB_001deba8;
        iVar2 = GetRecordInfoFromNrtMeta
                          (param_2 + 0x3d6,(BasicInformation *)&local_50,(vector *)&uStack_148,
                           aCStack_174);
        if (iVar2 != 0) goto LAB_001deba8;
      }
      param_2[0x14] = local_98;
      param_2[0x26] = 1;
      *(undefined4 *)(param_2 + 0x28) = local_124;
      *(undefined4 *)(param_2 + 0x2c) = local_120;
      *(undefined4 *)(param_2 + 0x30) = local_11c;
      *(undefined4 *)(param_2 + 0x34) = local_118;
      param_2[0x13] = local_99;
      *(undefined4 *)(param_2 + 0x38) = local_114;
      *(undefined4 *)(param_2 + 0x3c) = local_110;
      param_2[0x12] = local_9a;
      *(undefined2 *)(param_2 + 0x44) = local_104;
      *(undefined2 *)(param_2 + 0xc) = local_a0;
      *(undefined2 *)(param_2 + 0xe) = local_9e;
      param_2[0x10] = local_9c;
      param_2[0x11] = local_9b;
      *(undefined2 *)(param_2 + 0x16) = 0;
      *(undefined4 *)(param_2 + 0x40) = local_10c;
      uVar4 = pconv::ConvertFrameRateToNumer();
      uVar6 = local_68;
      if (local_68 == 0x3e9) {
        uVar6 = 1000;
      }
      uVar1 = 0;
      if (uVar6 != 0) {
        uVar1 = local_6c / uVar6;
      }
      if (uVar1 == (uVar4 & 0xffff)) {
        uVar1 = 0;
      }
      *(short *)(param_2 + 0x46) = (short)uVar1;
      *(undefined4 *)(param_2 + 0x48) = local_74;
      *(undefined4 *)(param_2 + 0x4c) = local_70;
      uVar6 = 0xffff;
      if (local_64 < 0x2b) {
        uVar6 = (uint)(byte)(&DAT_003d3cb8)[local_64];
      }
      *(uint *)(param_2 + 0x50) = uVar6;
      uVar6 = 0xffff;
      if (local_60 < 7) {
        uVar6 = (uint)(byte)(&DAT_003d3ce8)[local_60];
      }
      *(uint *)(param_2 + 0x54) = uVar6;
      uVar6 = 0xffff;
      if (local_5c < 5) {
        uVar6 = (uint)(byte)(&DAT_003d3cf0)[local_5c];
      }
      *(uint *)(param_2 + 0x58) = uVar6;
      *(undefined4 *)(param_2 + 0x98) = local_fc;
      *(undefined4 *)(param_2 + 0x9c) = local_f8;
      param_2[0x94] = 1;
      *(undefined4 *)(param_2 + 0xa0) = local_f4;
      *(undefined4 *)(param_2 + 0xa4) = local_f0;
      *(undefined8 *)(param_2 + 0x4f8) = local_96;
      *(undefined8 *)(param_2 + 0x500) = uStack_8e;
      *(undefined8 *)(param_2 + 0x508) = local_86;
      *(undefined8 *)(param_2 + 0x510) = uStack_7e;
      puVar5 = local_160;
      if (param_2[0x3d5] != '\0') {
        param_2[0x5c] = 1;
        *(undefined4 *)(param_2 + 0x60) = local_dc;
        *(undefined4 *)(param_2 + 100) = local_d8;
        *(undefined2 *)(param_2 + 0x7c) = local_bc;
        *(undefined4 *)(param_2 + 0x68) = local_d4;
        *(undefined4 *)(param_2 + 0x6c) = local_d0;
        *(undefined4 *)(param_2 + 0x70) = local_cc;
        *(undefined4 *)(param_2 + 0x74) = local_c8;
        *(undefined4 *)(param_2 + 0x78) = local_c4;
        uVar4 = pconv::ConvertFrameRateToNumer();
        uVar6 = 1000;
        if (local_18 != 0x3e9) {
          uVar6 = local_68;
        }
        uVar1 = 0;
        if (uVar6 != 0) {
          uVar1 = local_1c / uVar6;
        }
        if (uVar1 == (uVar4 & 0xffff)) {
          uVar1 = 0;
        }
        *(short *)(param_2 + 0x7e) = (short)uVar1;
        *(undefined4 *)(param_2 + 0x80) = local_24;
        *(undefined4 *)(param_2 + 0x84) = local_20;
        uVar6 = 0xffff;
        if (local_14 < 0x2b) {
          uVar6 = (uint)(byte)(&DAT_003d3cb8)[local_14];
        }
        *(uint *)(param_2 + 0x88) = uVar6;
        uVar6 = 0xffff;
        if (local_10 < 7) {
          uVar6 = (uint)(byte)(&DAT_003d3ce8)[local_10];
        }
        *(uint *)(param_2 + 0x8c) = uVar6;
        uVar6 = 0xffff;
        if (local_c < 5) {
          uVar6 = (uint)(byte)(&DAT_003d3cf0)[local_c];
        }
        *(uint *)(param_2 + 0x90) = uVar6;
        param_2[0xa8] = 1;
        *(undefined4 *)(param_2 + 0xac) = local_b4;
        *(undefined4 *)(param_2 + 0xb0) = local_b0;
        *(undefined4 *)(param_2 + 0xb4) = local_ac;
        *(undefined4 *)(param_2 + 0xb8) = local_a8;
        *(ulong *)(param_2 + 0x558) = CONCAT62(uStack_44,local_48._2_2_);
        *(undefined8 *)(param_2 + 0x560) = uStack_3e;
        *(undefined8 *)(param_2 + 0x568) = local_36;
        *(undefined8 *)(param_2 + 0x570) = uStack_2e;
        puVar5 = local_160;
      }
      for (; puStack_158 != puVar5; puVar5 = puVar5 + 1) {
        switch(*puVar5) {
        case 0:
          param_2[0x609] = 1;
          break;
        case 1:
          param_2[0x60a] = 1;
          break;
        case 2:
          param_2[0x60b] = 1;
          break;
        case 3:
          param_2[0x60c] = 1;
          break;
        case 4:
          param_2[0x60d] = 1;
          break;
        case 5:
          param_2[0x60e] = 1;
          break;
        case 6:
          param_2[0x60f] = 1;
          break;
        case 7:
          param_2[0x610] = 1;
          break;
        case 8:
          param_2[0x611] = 1;
          break;
        case 9:
          param_2[0x608] = 1;
        }
      }
      param_2[0x618] = local_58;
      ConvClipStatusTypeNrtDef2Sidb(local_178,param_2 + 0x604);
      iVar2 = iVar3;
    }
  }
LAB_001deba8:
  local_16c = 3;
  local_16b = 0;
  local_170 = 0x2110;
  local_16a = 0;
  local_16e = 0x131;
  local_169 = 0;
  local_168 = iVar2;
  FUN_001c9f24(&local_170,0xc);
  FUN_001dd638(&uStack_148);
  FUN_001dd638((vector *)&local_160);
  return iVar2;
}

