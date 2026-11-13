// mpr::GetClipInfo
// Ghidra address: 001dec08

/* mpr::GetClipInfo(unsigned int, mpr::ExistedFileInfo,
   LibMediaProfileIf::LibMediaProfile::T_MPF_CLIP_INFO&) */

int mpr::GetClipInfo(uint param_1,ushort *param_2,char *param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  char local_93a;
  undefined1 uStack_939;
  undefined4 local_938;
  ClipStatus aCStack_934 [4];
  undefined2 local_930;
  undefined2 local_92e;
  undefined1 local_92c;
  undefined1 local_92b;
  undefined1 local_92a;
  undefined1 local_929;
  int local_928;
  undefined8 local_920;
  undefined8 uStack_918;
  undefined8 local_910;
  undefined8 uStack_908;
  undefined8 local_900;
  undefined8 uStack_8f8;
  undefined1 *local_8f0 [2];
  undefined1 auStack_8e0 [16];
  MoviePropertyInfo aMStack_8d0 [12];
  undefined4 local_8c4;
  undefined4 local_8c0;
  int local_8bc;
  undefined4 local_8b8;
  undefined4 local_8b4;
  undefined4 uStack_8b0;
  undefined4 local_8ac;
  undefined4 local_8a8;
  ushort local_8a4;
  undefined4 local_8a0;
  undefined4 local_89c;
  undefined4 local_898;
  uchar local_890;
  MoviePropertyInfo aMStack_888 [12];
  undefined4 local_87c;
  undefined4 local_878;
  int local_874;
  undefined4 local_870;
  undefined4 local_86c;
  undefined4 local_868;
  undefined4 local_864;
  undefined4 local_860;
  ushort local_85c;
  undefined4 local_854;
  undefined4 local_850;
  uchar local_848;
  undefined2 local_840;
  undefined2 local_83e;
  char local_83c;
  char local_83b;
  char local_83a;
  char local_839;
  char local_838;
  undefined8 local_836;
  undefined8 uStack_82e;
  undefined8 local_826;
  undefined8 uStack_81e;
  BasicInformation aBStack_7f0 [10];
  undefined8 local_7e6;
  undefined8 uStack_7de;
  undefined8 local_7d6;
  undefined8 uStack_7ce;
  char local_7a0 [104];
  char acStack_738 [264];
  char acStack_630 [264];
  char acStack_528 [264];
  char acStack_420 [264];
  char acStack_318 [264];
  char acStack_210 [264];
  char local_108 [8];
  uint local_100;
  
  builtin_strncpy(local_108,"\x10!2\x01\x03",6);
  local_108[6] = 0;
  local_108[7] = 0;
  local_100 = param_1;
  FUN_001c9f24(local_108,0xc);
  if (param_1 < 4) {
    memcpy(local_7a0,PTR_g_msidconv_00401cd8 + (ulong)param_1 * 0x80 + 1,100);
  }
  else {
    local_7a0[0] = '\0';
  }
  local_8f0[0] = auStack_8e0;
  std::__cxx11::string::_M_construct((ulong)local_8f0,'\x01');
  std::__cxx11::string::operator+=((string *)local_8f0,":");
  std::__cxx11::string::operator+=((string *)local_8f0,local_7a0);
  if (*(int *)(*(long *)PTR_gp_paramBoard_00402470 + (ulong)param_1 * 0x2c + 0x50) == 3) {
    std::__cxx11::string::operator+=((string *)local_8f0,"/PRIVATE");
  }
  std::__cxx11::string::operator+=((string *)local_8f0,"/M4ROOT");
  if (*(int *)(param_2 + 0x3c) == 2) {
    snprintf(acStack_738,0x106,"%s%03d%s",*(undefined8 *)(param_2 + 4),(ulong)(*param_2 % 1000),
             param_2 + 0x3e);
  }
  else {
    snprintf(acStack_738,0x106,"%s%04d",*(undefined8 *)(param_2 + 4),(ulong)*param_2);
  }
  snprintf(acStack_630,0x106,"%s.%s",acStack_738,(long)param_2 + 0x39);
  snprintf(acStack_210,0x106,"%s/CLIP/%s",local_8f0[0],acStack_630);
  if ((char)param_2[0x24] != '\0') {
    snprintf(acStack_420,0x106,"%sM01.%s",acStack_738,(long)param_2 + 0x49);
  }
  if ((char)param_2[0x2c] != '\0') {
    snprintf(acStack_318,0x106,"%sT01.%s",acStack_738,(long)param_2 + 0x59);
  }
  if ((char)param_2[0x34] != '\0') {
    snprintf(acStack_528,0x106,"%sS03.%s",acStack_738,(long)param_2 + 0x69);
    snprintf(local_108,0x106,"%s/SUB/%s",local_8f0[0],acStack_528);
  }
  FUN_001cb454(aMStack_8d0);
  FUN_001cb454(aMStack_888);
  FUN_001ca54c((BasicInformation *)&local_840);
  FUN_001ca54c(aBStack_7f0);
  local_920 = 0;
  uStack_918 = 0;
  local_910 = 0;
  uStack_908 = 0;
  local_900 = 0;
  uStack_8f8 = 0;
  iVar4 = GetRecordInfoFromMp4(acStack_210,aMStack_8d0);
  if (((iVar4 == 0) &&
      (iVar5 = GetRecordInfoFromNrtMeta
                         (acStack_210,(BasicInformation *)&local_840,(vector *)&local_920,
                          (ClipStatus *)&local_938), iVar4 = iVar5, iVar5 == 0)) &&
     (((char)param_2[0x34] == '\0' ||
      ((iVar4 = GetRecordInfoFromMp4(local_108,aMStack_888), iVar4 == 0 &&
       (iVar4 = GetRecordInfoFromNrtMeta(local_108,aBStack_7f0,(vector *)&uStack_908,aCStack_934),
       iVar4 == 0)))))) {
    strncpy(param_3,acStack_630,0x80);
    snprintf(param_3 + 0x80,0x87,"./CLIP/%s",param_3);
    uVar6 = GetProfileLevel(local_8a8);
    *(undefined4 *)(param_3 + 0x10c) = uVar6;
    uVar7 = local_8bc - 1;
    if (uVar7 < 7) {
      uVar3 = *(undefined2 *)(&DAT_003d3c98 + (ulong)uVar7 * 2);
      uVar2 = *(undefined2 *)(&DAT_003d3ca8 + (ulong)uVar7 * 2);
    }
    else {
      uVar2 = 0;
      uVar3 = 0;
    }
    *(undefined2 *)(param_3 + 0x112) = uVar2;
    *(undefined2 *)(param_3 + 0x110) = uVar3;
    uVar6 = GetAudioCodec(local_89c,local_898);
    *(undefined4 *)(param_3 + 0x114) = uVar6;
    pconv::ConvertFrameRateForCodec(local_8ac,param_3 + 0x118,&local_93a,&uStack_939);
    param_3[0x11c] = local_93a == '\0';
    *(undefined4 *)(param_3 + 0x120) = local_8a0;
    uVar3 = GetAudioOutputChannel(local_890);
    *(undefined2 *)(param_3 + 0x124) = uVar3;
    uVar6 = ConvertVideoAspectForAspectRatio(local_8b8);
    *(undefined4 *)(param_3 + 0x128) = uVar6;
    param_3[300] = '\0';
    param_3[0x12d] = '\0';
    param_3[0x12e] = '\0';
    param_3[0x12f] = '\0';
    *(undefined8 *)(param_3 + 0x130) = local_836;
    *(undefined8 *)(param_3 + 0x138) = uStack_82e;
    *(undefined8 *)(param_3 + 0x140) = local_826;
    *(undefined8 *)(param_3 + 0x148) = uStack_81e;
    uVar1 = param_2[0x24];
    param_3[0x150] = '\0';
    if ((char)uVar1 != '\0') {
      *(int *)(param_3 + 0x198) = *(int *)(param_3 + 0x198) + 1;
      param_3[0x228] = '\x01';
      param_3[0x229] = '\0';
      param_3[0x22a] = '\0';
      param_3[0x22b] = '\0';
      snprintf(param_3 + 0x19c,0x89,"./CLIP/%s",acStack_420);
    }
    param_3[0x168] = local_838;
    *(undefined2 *)(param_3 + 0x160) = local_840;
    *(undefined2 *)(param_3 + 0x162) = local_83e;
    param_3[0x164] = local_83c;
    param_3[0x165] = local_83b;
    param_3[0x166] = local_83a;
    param_3[0x167] = local_839;
    param_3[0x16a] = '\0';
    param_3[0x16b] = '\0';
    uVar7 = GetVQuality(local_8a4);
    uVar6 = ConvertPictureQualityDefStructToMpr(uVar7);
    *(undefined4 *)(param_3 + 0x16c) = uVar6;
    uVar6 = GetVideoParamComb(local_8c4,local_8bc,local_8b4,uStack_8b0,local_8c0);
    *(undefined4 *)(param_3 + 0x170) = uVar6;
    if ((char)param_2[0x2c] != '\0') {
      *(int *)(param_3 + 0x198) = *(int *)(param_3 + 0x198) + 1;
      param_3[0x2b8] = '\x05';
      param_3[0x2b9] = '\0';
      param_3[0x2ba] = '\0';
      param_3[699] = '\0';
      snprintf(param_3 + 0x22c,0x89,"./THMBNL/%s",acStack_318);
    }
    if ((char)param_2[0x34] != '\0') {
      param_3[0x46c] = '\x01';
      param_3[0x46d] = '\0';
      param_3[0x46e] = '\0';
      param_3[0x46f] = '\0';
      snprintf(param_3 + 0x470,0x89,"./SUB/%s",acStack_528);
      param_3[0x4fc] = '\x04';
      param_3[0x4fd] = '\0';
      param_3[0x4fe] = '\0';
      param_3[0x4ff] = '\0';
      uVar6 = GetProfileLevel(local_860);
      *(undefined4 *)(param_3 + 0x500) = uVar6;
      uVar7 = local_874 - 1;
      if (uVar7 < 7) {
        uVar3 = *(undefined2 *)(&DAT_003d3c98 + (ulong)uVar7 * 2);
        uVar2 = *(undefined2 *)(&DAT_003d3ca8 + (ulong)uVar7 * 2);
      }
      else {
        uVar2 = 0;
        uVar3 = 0;
      }
      *(undefined2 *)(param_3 + 0x506) = uVar2;
      *(undefined2 *)(param_3 + 0x504) = uVar3;
      uVar6 = GetAudioCodec(local_854,local_850);
      *(undefined4 *)(param_3 + 0x508) = uVar6;
      pconv::ConvertFrameRateForCodec(local_864,param_3 + 0x50c,&local_93a,&uStack_939);
      uVar3 = GetAudioOutputChannel(local_848);
      *(undefined2 *)(param_3 + 0x510) = uVar3;
      uVar6 = ConvertVideoAspectForAspectRatio(local_870);
      *(undefined4 *)(param_3 + 0x514) = uVar6;
      uVar6 = ConvertVideoCodecToCodec(local_87c,local_878);
      *(undefined4 *)(param_3 + 0x53c) = uVar6;
      *(undefined8 *)(param_3 + 0x518) = local_7e6;
      *(undefined8 *)(param_3 + 0x520) = uStack_7de;
      *(undefined8 *)(param_3 + 0x528) = local_7d6;
      *(undefined8 *)(param_3 + 0x530) = uStack_7ce;
      param_3[0x538] = '\0';
      uVar7 = GetVQuality(local_85c);
      uVar6 = ConvertPictureQualityDefStructToMpr(uVar7);
      *(undefined4 *)(param_3 + 0x540) = uVar6;
      uVar6 = GetVideoParamComb(local_87c,local_874,local_86c,local_868,local_878);
      *(undefined4 *)(param_3 + 0x544) = uVar6;
    }
    uVar6 = ConvertVideoCodecToCodec(local_8c4,local_8c0);
    *(undefined4 *)(param_3 + 0x6a8) = uVar6;
    ConvClipStatusTypeNrtDef2Mpf(local_938,param_3 + 0x154);
    iVar4 = iVar5;
  }
  local_92c = 3;
  local_92b = 0;
  local_930 = 0x2110;
  local_92a = 0;
  local_92e = 0x13f;
  local_929 = 0;
  local_928 = iVar4;
  FUN_001c9f24(&local_930,0xc);
  FUN_001dd638((vector *)&uStack_908);
  FUN_001dd638((vector *)&local_920);
  std::__cxx11::string::_M_dispose();
  return iVar4;
}

