// mpr::MakeMediaPro
// Ghidra address: 001ba3f0

/* mpr::MakeMediaPro(unsigned int, std::__cxx11::string) */

int mpr::MakeMediaPro(undefined4 param_1,undefined8 *param_2)

{
  char *__dest;
  long lVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  undefined1 *puVar6;
  long lVar7;
  undefined2 local_2b8;
  undefined2 local_2b6;
  undefined1 local_2b4;
  undefined1 local_2b3;
  undefined1 local_2b2;
  undefined1 local_2b1;
  undefined1 local_2b0;
  undefined2 local_2a8;
  undefined2 local_2a6;
  undefined1 local_2a4;
  undefined1 local_2a3;
  undefined1 local_2a2;
  undefined1 local_2a1;
  int local_2a0;
  undefined8 local_298;
  char acStack_290 [16];
  undefined8 local_280;
  undefined8 uStack_278;
  undefined8 local_270;
  undefined8 uStack_268;
  undefined1 local_260;
  undefined8 local_258;
  undefined8 uStack_250;
  undefined8 local_248;
  undefined8 uStack_240;
  undefined8 local_238;
  undefined8 uStack_230;
  undefined8 local_228;
  undefined8 uStack_220;
  char local_218 [200];
  undefined2 local_150;
  undefined2 local_14e;
  undefined1 local_14c;
  undefined1 local_14b;
  undefined1 local_14a;
  undefined1 local_149;
  undefined1 local_148;
  int local_144;
  char local_140 [8];
  undefined1 auStack_138 [72];
  undefined1 auStack_f0 [72];
  int local_a8;
  char local_a4 [16];
  int local_94;
  uint local_90;
  undefined1 auStack_8c [68];
  undefined1 auStack_48 [72];
  
  memset(&local_150,0,0x150);
  iVar3 = time::GetLTM((LocalTime *)&local_2b8);
  if (iVar3 == 0) {
    local_150 = local_2b8;
    local_14e = local_2b6;
    local_14c = local_2b4;
    local_14b = local_2b3;
    local_14a = local_2b2;
    local_149 = local_2b1;
  }
  else {
    local_150 = 0x21c;
    local_14e = 0x7e3;
    local_14c = 0xb;
    local_14b = 0x1e;
    local_14a = 9;
    local_149 = 0x23;
    local_2b0 = 0x3b;
  }
  acStack_290[8] = 0;
  local_280 = 0;
  uStack_278 = 0;
  local_298 = 0;
  acStack_290[0] = '\0';
  acStack_290[1] = '\0';
  acStack_290[2] = '\0';
  acStack_290[3] = '\0';
  acStack_290[4] = '\0';
  acStack_290[5] = '\0';
  acStack_290[6] = '\0';
  acStack_290[7] = '\0';
  local_270 = 0;
  uStack_268 = 0;
  local_260 = 0;
  local_258 = 0;
  uStack_250 = 0;
  local_218[0xc0] = 0;
  local_248 = 0;
  uStack_240 = 0;
  local_238 = 0;
  uStack_230 = 0;
  local_228 = 0;
  uStack_220 = 0;
  local_218[0] = '\0';
  local_218[1] = '\0';
  local_218[2] = '\0';
  local_218[3] = '\0';
  local_218[4] = '\0';
  local_218[5] = '\0';
  local_218[6] = '\0';
  local_218[7] = '\0';
  local_218[8] = '\0';
  local_218[9] = '\0';
  local_218[10] = '\0';
  local_218[0xb] = '\0';
  local_218[0xc] = '\0';
  local_218[0xd] = '\0';
  local_218[0xe] = '\0';
  local_218[0xf] = '\0';
  local_218[0x10] = '\0';
  local_218[0x11] = '\0';
  local_218[0x12] = '\0';
  local_218[0x13] = '\0';
  local_218[0x14] = '\0';
  local_218[0x15] = '\0';
  local_218[0x16] = '\0';
  local_218[0x17] = '\0';
  local_218[0x18] = '\0';
  local_218[0x19] = '\0';
  local_218[0x1a] = '\0';
  local_218[0x1b] = '\0';
  local_218[0x1c] = '\0';
  local_218[0x1d] = '\0';
  local_218[0x1e] = '\0';
  local_218[0x1f] = '\0';
  local_218[0x20] = '\0';
  local_218[0x21] = '\0';
  local_218[0x22] = '\0';
  local_218[0x23] = '\0';
  local_218[0x24] = '\0';
  local_218[0x25] = '\0';
  local_218[0x26] = '\0';
  local_218[0x27] = '\0';
  local_218[0x28] = '\0';
  local_218[0x29] = '\0';
  local_218[0x2a] = '\0';
  local_218[0x2b] = '\0';
  local_218[0x2c] = '\0';
  local_218[0x2d] = '\0';
  local_218[0x2e] = '\0';
  local_218[0x2f] = '\0';
  local_218[0x30] = '\0';
  local_218[0x31] = '\0';
  local_218[0x32] = '\0';
  local_218[0x33] = '\0';
  local_218[0x34] = '\0';
  local_218[0x35] = '\0';
  local_218[0x36] = '\0';
  local_218[0x37] = '\0';
  local_218[0x38] = '\0';
  local_218[0x39] = '\0';
  local_218[0x3a] = '\0';
  local_218[0x3b] = '\0';
  local_218[0x3c] = '\0';
  local_218[0x3d] = '\0';
  local_218[0x3e] = '\0';
  local_218[0x3f] = '\0';
  local_218[0x40] = '\0';
  local_218[0x41] = '\0';
  local_218[0x42] = '\0';
  local_218[0x43] = '\0';
  local_218[0x44] = '\0';
  local_218[0x45] = '\0';
  local_218[0x46] = '\0';
  local_218[0x47] = '\0';
  local_218[0x48] = '\0';
  local_218[0x49] = '\0';
  local_218[0x4a] = '\0';
  local_218[0x4b] = '\0';
  local_218[0x4c] = '\0';
  local_218[0x4d] = '\0';
  local_218[0x4e] = '\0';
  local_218[0x4f] = '\0';
  local_218[0x50] = '\0';
  local_218[0x51] = '\0';
  local_218[0x52] = '\0';
  local_218[0x53] = '\0';
  local_218[0x54] = '\0';
  local_218[0x55] = '\0';
  local_218[0x56] = '\0';
  local_218[0x57] = '\0';
  local_218[0x58] = '\0';
  local_218[0x59] = '\0';
  local_218[0x5a] = '\0';
  local_218[0x5b] = '\0';
  local_218[0x5c] = '\0';
  local_218[0x5d] = '\0';
  local_218[0x5e] = '\0';
  local_218[0x5f] = '\0';
  local_218[0x60] = '\0';
  local_218[0x61] = '\0';
  local_218[0x62] = '\0';
  local_218[99] = '\0';
  local_218[100] = '\0';
  local_218[0x65] = '\0';
  local_218[0x66] = '\0';
  local_218[0x67] = '\0';
  local_218[0x68] = '\0';
  local_218[0x69] = '\0';
  local_218[0x6a] = '\0';
  local_218[0x6b] = '\0';
  local_218[0x6c] = '\0';
  local_218[0x6d] = '\0';
  local_218[0x6e] = '\0';
  local_218[0x6f] = '\0';
  local_218[0x70] = '\0';
  local_218[0x71] = '\0';
  local_218[0x72] = '\0';
  local_218[0x73] = '\0';
  local_218[0x74] = '\0';
  local_218[0x75] = '\0';
  local_218[0x76] = '\0';
  local_218[0x77] = '\0';
  local_218[0x78] = '\0';
  local_218[0x79] = '\0';
  local_218[0x7a] = '\0';
  local_218[0x7b] = '\0';
  local_218[0x7c] = '\0';
  local_218[0x7d] = '\0';
  local_218[0x7e] = '\0';
  local_218[0x7f] = '\0';
  local_218[0x80] = '\0';
  local_218[0x81] = '\0';
  local_218[0x82] = '\0';
  local_218[0x83] = '\0';
  local_218[0x84] = '\0';
  local_218[0x85] = '\0';
  local_218[0x86] = '\0';
  local_218[0x87] = '\0';
  local_218[0x88] = '\0';
  local_218[0x89] = '\0';
  local_218[0x8a] = '\0';
  local_218[0x8b] = '\0';
  local_218[0x8c] = '\0';
  local_218[0x8d] = '\0';
  local_218[0x8e] = '\0';
  local_218[0x8f] = '\0';
  local_218[0x90] = '\0';
  local_218[0x91] = '\0';
  local_218[0x92] = '\0';
  local_218[0x93] = '\0';
  local_218[0x94] = '\0';
  local_218[0x95] = '\0';
  local_218[0x96] = '\0';
  local_218[0x97] = '\0';
  local_218[0x98] = '\0';
  local_218[0x99] = '\0';
  local_218[0x9a] = '\0';
  local_218[0x9b] = '\0';
  local_218[0x9c] = '\0';
  local_218[0x9d] = '\0';
  local_218[0x9e] = '\0';
  local_218[0x9f] = '\0';
  local_218[0xa0] = '\0';
  local_218[0xa1] = '\0';
  local_218[0xa2] = '\0';
  local_218[0xa3] = '\0';
  local_218[0xa4] = '\0';
  local_218[0xa5] = '\0';
  local_218[0xa6] = '\0';
  local_218[0xa7] = '\0';
  local_218[0xa8] = '\0';
  local_218[0xa9] = '\0';
  local_218[0xaa] = '\0';
  local_218[0xab] = '\0';
  local_218[0xac] = '\0';
  local_218[0xad] = '\0';
  local_218[0xae] = '\0';
  local_218[0xaf] = '\0';
  local_218[0xb0] = '\0';
  local_218[0xb1] = '\0';
  local_218[0xb2] = '\0';
  local_218[0xb3] = '\0';
  local_218[0xb4] = '\0';
  local_218[0xb5] = '\0';
  local_218[0xb6] = '\0';
  local_218[0xb7] = '\0';
  local_218[0xb8] = '\0';
  local_218[0xb9] = '\0';
  local_218[0xba] = '\0';
  local_218[0xbb] = '\0';
  local_218[0xbc] = '\0';
  local_218[0xbd] = '\0';
  local_218[0xbe] = '\0';
  local_218[0xbf] = '\0';
  local_148 = local_2b0;
  iVar3 = Backup_get_datasize("FilterData[1]");
  if (iVar3 - 1U < 0x3f) {
    Backup_nread("FilterData[1]",&local_258,0x3f);
  }
  else {
    local_2a3 = 0;
    local_2a4 = 3;
    local_2a2 = 0;
    local_2a8 = 0x2180;
    local_2a1 = 0;
    local_2a6 = 0xf07;
    local_2a0 = iVar3;
    FUN_001b7d90(&local_2a8,0xc);
  }
  puVar2 = PTR_gp_umid_00402810;
  __dest = local_218 + 0x40;
  iVar3 = UMID::CreateBasicUMID(*(UMID **)PTR_gp_umid_00402810,4);
  if (iVar3 == 0) {
    UMID::GetDeviceNodeIdString(*(UMID **)puVar2,(char *)&local_298,0x11);
    strncpy(local_218,"XAVC-M4@2.00.00",0x3f);
    UMID::GetMaterialNoString(*(UMID **)puVar2,(char *)&local_280,0x21);
  }
  else {
    local_2a3 = 0;
    local_2a4 = 4;
    local_2a2 = 0;
    local_2a8 = 0x2180;
    local_2a1 = 0;
    local_2a6 = 0xf08;
    FUN_001b7d90(&local_2a8,8);
    local_298 = DAT_003d3a41;
    acStack_290[0] = s_FE3EC99F_003d3a49[0];
    acStack_290[1] = s_FE3EC99F_003d3a49[1];
    acStack_290[2] = s_FE3EC99F_003d3a49[2];
    acStack_290[3] = s_FE3EC99F_003d3a49[3];
    acStack_290[4] = s_FE3EC99F_003d3a49[4];
    acStack_290[5] = s_FE3EC99F_003d3a49[5];
    acStack_290[6] = s_FE3EC99F_003d3a49[6];
    acStack_290[7] = s_FE3EC99F_003d3a49[7];
    strncpy(local_218,"XAVC-M4@2.00.00",0x3f);
    local_280 = DAT_003d3a52;
    uStack_278 = DAT_003d3a5a;
    local_270 = DAT_003d3a62;
    uStack_268 = DAT_003d3a6a;
  }
  strncpy(__dest,"AffordableMemoryCard",0x3f);
  strncpy(local_218 + 0x80,"",0x40);
  if (local_144 == 0) {
    local_144 = 1;
    sVar5 = strlen((char *)&local_298);
    if ((int)sVar5 == 0x10) {
      puVar6 = (undefined1 *)((long)&local_298 + 1);
      lVar7 = 0;
      do {
        iVar3 = FUN_001b8088(puVar6[-1]);
        iVar4 = FUN_001b8088(*puVar6);
        if (iVar3 == -1 || iVar4 == -1) {
          local_144 = 2;
          break;
        }
        lVar1 = lVar7 + 1;
        puVar6 = puVar6 + 2;
        local_140[lVar7] = (char)iVar4 + (char)iVar3 * '\x10';
        lVar7 = lVar1;
      } while (lVar1 != 8);
    }
    else {
      local_144 = 4;
    }
  }
  else {
    local_144 = 3;
  }
  FUN_001ba374(auStack_138,&local_258);
  FUN_001ba374(auStack_f0,local_218);
  if (local_a8 == 0) {
    local_a8 = 1;
    sVar5 = strlen((char *)&local_280);
    if ((int)sVar5 == 0x20) {
      puVar6 = (undefined1 *)((long)&local_280 + 1);
      lVar7 = 0;
      do {
        iVar3 = FUN_001b8088(puVar6[-1]);
        iVar4 = FUN_001b8088(*puVar6);
        if (iVar3 == -1 || iVar4 == -1) {
          local_a8 = 2;
          break;
        }
        lVar1 = lVar7 + 1;
        puVar6 = puVar6 + 2;
        local_a4[lVar7] = (char)iVar4 + (char)iVar3 * '\x10';
        lVar7 = lVar1;
      } while (lVar1 != 0x10);
    }
    else {
      local_a8 = 4;
    }
  }
  else {
    local_a8 = 3;
  }
  if (local_94 == 0) {
    local_94 = 1;
    sVar5 = strlen(__dest);
    iVar3 = 4;
    if ((uint)sVar5 < 0x41) {
      local_90 = (uint)sVar5;
      memcpy(auStack_8c,__dest,sVar5 & 0xffffffff);
      auStack_8c[sVar5 & 0xffffffff] = 0;
      iVar3 = local_94;
    }
  }
  else {
    iVar3 = 3;
  }
  local_94 = iVar3;
  FUN_001ba374(auStack_48,local_218 + 0x80);
  FUN_002813f4(param_1,*param_2);
  iVar3 = FUN_0028174c(param_1,&local_150);
  if ((iVar3 != 0) || (iVar3 = FUN_00281574(param_1,0,0), iVar3 != 0)) {
    FUN_00282618(param_1);
  }
  return iVar3;
}

