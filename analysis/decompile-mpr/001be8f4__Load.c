// mpr::_Load
// Ghidra address: 001be8f4

/* mpr::_Load(void*) */

void mpr::_Load(void *param_1)

{
  char *pcVar1;
  uint uVar2;
  undefined *puVar3;
  undefined *puVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  char cVar8;
  int iVar9;
  long lVar10;
  undefined4 uVar11;
  long lVar12;
  uint uVar13;
  ulong uVar14;
  uint uVar15;
  bool bVar16;
  bool local_d7a;
  bool local_d79;
  undefined4 local_d78;
  undefined4 uStack_d74;
  undefined2 local_d70;
  undefined2 local_d6e;
  undefined1 local_d6c;
  undefined1 local_d6b;
  undefined1 local_d6a;
  undefined1 local_d69;
  uint local_d68;
  undefined4 uStack_d64;
  uint local_d60;
  undefined4 local_d5c;
  undefined4 local_d58;
  uint uStack_d54;
  uint local_d50;
  undefined1 *local_d48;
  undefined8 uStack_d40;
  undefined1 local_d38 [16];
  undefined8 local_d28;
  undefined4 local_d20;
  uint local_d1c;
  uint local_d18;
  undefined8 local_d08;
  undefined4 local_d00;
  uint local_cfc;
  uint local_cf8;
  undefined1 auStack_ce8 [24];
  undefined4 local_cd0;
  undefined4 local_ccc;
  ushort local_cb0;
  ushort local_cae;
  undefined4 local_cac;
  undefined4 local_ca8;
  undefined4 local_ca4;
  undefined4 local_ca0;
  undefined4 local_c4c;
  short local_c48;
  undefined2 local_c28;
  undefined2 local_c26;
  undefined1 local_c24;
  undefined1 local_c23;
  undefined1 local_c22;
  undefined1 local_c21;
  byte local_c02;
  
  local_c24 = 4;
  local_c28 = 0x2300;
  local_c26 = 0x400;
  local_c23 = 0;
  local_c22 = 0;
  local_c21 = 0;
  FUN_001b7d90(&local_c28,8);
  uVar2 = *(uint *)param_1;
  uVar14 = (ulong)uVar2;
  if (uVar2 < 4) {
    cVar8 = PTR_g_msidconv_00401cd8[uVar14 * 0x80];
    uVar15 = *(uint *)(PTR_g_msidconv_00401cd8 + uVar14 * 0x80 + 0x7c);
  }
  else {
    uVar15 = 0xffffffff;
    cVar8 = '\0';
  }
  local_d48 = local_d38;
  local_d38[0] = 0;
  uStack_d40 = 0;
  local_d78 = 0;
  uStack_d74 = 0;
  iVar9 = Fsys_GetDriveInfo(cVar8,&local_cb0);
  if (iVar9 == 0) {
    lVar12 = *(long *)PTR_gp_paramBoard_00402470;
    *(undefined1 *)(lVar12 + (ulong)uVar2 * 0x2c + 0x4c) = 1;
    if (local_cae < 0x8403) {
      if (local_cae < 0x8400) {
        iVar9 = 9;
        if ((local_cae != 0x8101) && (iVar9 = 7, local_cae != 0x8300)) goto LAB_001be9f4;
      }
      else {
LAB_001beb78:
        iVar9 = 3;
      }
    }
    else {
      if (local_cae == 0x84ff) goto LAB_001beb78;
LAB_001be9f4:
      iVar9 = 0;
    }
    uVar13 = 0;
    lVar10 = lVar12 + (ulong)uVar2 * 0x2c;
    *(int *)(lVar10 + 0x50) = iVar9;
    *(uint *)(lVar10 + 0x54) = (local_cb0 - 1 < 2) + 1;
    if ((ushort)(local_c48 - 1U) < 0x10) {
      uVar13 = (uint)(byte)(&DAT_003d3a08)[(ushort)(local_c48 - 1)];
    }
    lVar12 = lVar12 + (ulong)uVar2 * 0x2c;
    *(uint *)(lVar12 + 0x58) = uVar13;
    *(undefined4 *)(lVar12 + 0x5c) = local_cac;
    *(undefined4 *)(lVar12 + 0x60) = local_ca8;
    *(undefined4 *)(lVar12 + 100) = local_ca4;
    *(undefined4 *)(lVar12 + 0x68) = local_ca0;
    *(undefined4 *)(lVar12 + 0x6c) = local_c4c;
    bVar5 = (local_cb0 & 0x87) != 0;
    bVar6 = iVar9 == 3;
  }
  else {
    local_c23 = 0;
    local_c24 = 4;
    local_c22 = 0;
    local_c28 = 0x2180;
    local_c21 = 0;
    local_c26 = 0x401;
    FUN_001b7d90(&local_c28,8);
    *(undefined1 *)(*(long *)PTR_gp_paramBoard_00402470 + (ulong)uVar2 * 0x2c + 0x4c) = 0;
    EventError::Update((EventError *)&local_d78,0xb);
    bVar6 = false;
    bVar5 = false;
  }
  iVar9 = Fsys_GetFreeSpace(cVar8,auStack_ce8);
  if (iVar9 == 0) {
    lVar12 = *(long *)PTR_gp_paramBoard_00402470 + (ulong)uVar2 * 0x2c;
    *(undefined4 *)(lVar12 + 0x70) = local_ccc;
    *(undefined4 *)(lVar12 + 0x74) = local_cd0;
  }
  else {
    local_c23 = 0;
    local_c24 = 4;
    local_c22 = 0;
    local_c28 = 0x2180;
    local_c21 = 0;
    local_c26 = 0x402;
    FUN_001b7d90(&local_c28,8);
    *(undefined1 *)(*(long *)PTR_gp_paramBoard_00402470 + (ulong)uVar2 * 0x2c + 0x4c) = 0;
    EventError::Update((EventError *)&local_d78,0xb);
  }
  pcVar1 = (char *)((long)param_1 + 0x10);
  std::__cxx11::string::operator=((string *)&local_d48,cVar8);
  std::__cxx11::string::operator+=((string *)&local_d48,":");
  std::__cxx11::string::operator+=((string *)&local_d48,pcVar1);
  std::__cxx11::string::operator+=((string *)&local_d48,"/PRIVATE/DATABASE/DATABASE.BIN");
  iVar9 = Fsys_FindFirst(local_d48,0xffffff80,&local_c28);
  if (iVar9 == 0) {
    if ((local_c02 >> 4 & 1) == 0) {
      if (((local_c02 & 1) == 0) || (iVar9 = Fsys_Chmod(local_d48,0), iVar9 == 0))
      goto LAB_001bec58;
      goto LAB_001bec4c;
    }
    local_d08 = 0x404032180;
    FUN_001b7d90(&local_d08,8);
LAB_001beb58:
    iVar9 = 4;
  }
  else {
    if (iVar9 == 2) goto LAB_001beb58;
LAB_001bec4c:
    iVar9 = 0xb;
  }
  EventError::Update((EventError *)&local_d78,iVar9);
LAB_001bec58:
  FUN_001b7cd4(&local_d28,pcVar1);
  FUN_001b7cd4(&local_d08,"/PRIVATE/DATABASE/DATABASE.BIN");
  iVar9 = sidb::Load(uVar15,cVar8,&local_d28,&local_d08,0,bVar5);
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::_M_dispose();
  if (iVar9 == 0) {
    PTR_sb_sidbLoaded_00401990[uVar2] = 1;
  }
  else {
    EventError::Update((EventError *)&local_d78,2);
  }
  FUN_001b7cd4(&local_d08,pcVar1);
  iVar9 = FUN_0023b10c(uVar15,cVar8,&local_d08);
  EventError::Update((EventError *)&local_d78,iVar9);
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::operator=((string *)&local_d48,cVar8);
  std::__cxx11::string::operator+=((string *)&local_d48,":");
  std::__cxx11::string::operator+=((string *)&local_d48,pcVar1);
  if (bVar6) {
    std::__cxx11::string::operator+=((string *)&local_d48,"/PRIVATE");
  }
  std::__cxx11::string::operator+=((string *)&local_d48,"/M4ROOT/MEDIAPRO.XML");
  iVar9 = Fsys_FindFirst(local_d48,0xffffff80,&local_c28);
  if (iVar9 == 0) {
    bVar7 = (local_c02 & 0x11) == 1;
    FUN_002813f4(uVar2,local_d48);
    iVar9 = FUN_00281574(uVar2,bVar5,bVar7);
    if (iVar9 == 0) {
      PTR_sb_mediaProLoaded_00401400[uVar2] = 1;
    }
    else {
      EventError::Update((EventError *)&local_d78,iVar9);
      FUN_00282618(uVar2);
    }
  }
  else {
    if (iVar9 != 2) {
      iVar9 = 0xb;
    }
    EventError::Update((EventError *)&local_d78,iVar9);
    bVar7 = false;
  }
  std::__cxx11::string::operator=((string *)&local_d48,cVar8);
  std::__cxx11::string::operator+=((string *)&local_d48,":");
  std::__cxx11::string::operator+=((string *)&local_d48,pcVar1);
  std::__cxx11::string::operator+=((string *)&local_d48,"/DCIM");
  iVar9 = Fsys_FindFirst(local_d48,0x10,&local_c28);
  if (iVar9 == 0) {
    uVar11 = 1;
    bVar16 = (bool)(local_c02 & 1);
  }
  else {
    if (iVar9 != 2) {
      EventError::Update((EventError *)&local_d78,2);
    }
    bVar16 = false;
    uVar11 = 0;
  }
  FUN_001b7cd4(&local_d08,pcVar1);
  iVar9 = FUN_00224844(uVar2,cVar8,&local_d08,uVar11,bVar16);
  EventError::Update((EventError *)&local_d78,iVar9);
  std::__cxx11::string::_M_dispose();
  puVar3 = PTR_sb_sidbLoaded_00401990;
  local_d7a = false;
  local_d79 = false;
  if ((PTR_sb_sidbLoaded_00401990[uVar14] != '\0') &&
     (PTR_sb_mediaProLoaded_00401400[uVar14] != '\0')) {
    local_d60 = 0;
    local_d28 = 0;
    local_d08 = 0;
    iVar9 = ProvisionalRepairDcf(uVar2,false,&local_d60,&local_d7a,(InhBit *)&uStack_d74,&local_d28)
    ;
    if (iVar9 != 0) {
      puVar3[uVar14] = 0;
    }
    EventError::Update((EventError *)&local_d78,iVar9);
    iVar9 = ProvisionalRepairM4(uVar2,false,false,&local_d60,&local_d79,&local_d08);
    if (iVar9 != 0) {
      PTR_sb_sidbLoaded_00401990[uVar2] = 0;
    }
    EventError::Update((EventError *)&local_d78,iVar9);
    if ((local_d7a != false) || (local_d79 != false)) {
      uVar14 = local_d28;
      if ((local_d28 & 0x7ffffffffff) <= (local_d08 & 0x7ffffffffff)) {
        uVar14 = local_d08;
      }
      sidb::SetHeaderParam<unsigned_long>(uVar15,3,uVar14);
    }
    if (PTR_sb_sidbLoaded_00401990[uVar2] == '\0') {
      sidb::Unload(uVar15);
    }
    if (PTR_sb_mediaProLoaded_00401400[uVar2] == '\0') {
      FUN_00281670(uVar2);
      FUN_00282618(uVar2);
    }
  }
  puVar4 = PTR_sb_sidbLoaded_00401990;
  puVar3 = PTR_sb_mediaProLoaded_00401400;
  local_d58 = local_d78;
  local_d5c = *(undefined4 *)((long)param_1 + 0x15d0);
  local_d60 = 0x1000;
  local_d50 = (uint)(ushort)(CONCAT11(local_d7a,
                                      PTR_sb_sidbLoaded_00401990[uVar2] &
                                      PTR_sb_mediaProLoaded_00401400[uVar2]) ^ 1);
  uStack_d54 = uVar15;
  SetIssueEvent(0x1000,&local_d60,0x14);
  FUN_001b7cd4(&local_d08,pcVar1);
  iVar9 = FUN_00228f94(uVar2,cVar8,bVar6,&local_d08);
  EventError::Update((EventError *)&local_d78,iVar9);
  std::__cxx11::string::_M_dispose();
  local_d20 = local_d78;
  local_d28 = CONCAT44(*(undefined4 *)((long)param_1 + 0x15d0),0x1001);
  local_d18 = (uint)(ushort)(CONCAT11(local_d79,puVar4[uVar2] & puVar3[uVar2]) ^ 1);
  local_d1c = uVar15;
  SetIssueEvent(0x1001,&local_d28,0x14);
  FUN_0022bc00(uVar2,1);
  SetStillRecStatusInLoad(uVar2,(InhBit *)&uStack_d74,bVar5,bVar16);
  SetMovieRecStatusInLoad(uVar2,bVar5,bVar7);
  cVar8 = CheckRecordTarget(uVar15);
  if (cVar8 != '\0') {
    iVar9 = capidtbl::RemakeCapIdTbl((LocalTime *)0x0);
    EventError::Update((EventError *)&local_d78,iVar9);
  }
  local_d00 = local_d78;
  local_d08 = CONCAT44(*(undefined4 *)((long)param_1 + 0x15d0),0x1002);
  local_cf8 = (uint)(ushort)(CONCAT11(local_d7a | local_d79,
                                      PTR_sb_sidbLoaded_00401990[uVar2] &
                                      PTR_sb_mediaProLoaded_00401400[uVar2]) ^ 1);
  local_cfc = uVar15;
  SetIssueEvent(0x1002,&local_d08,0x14);
  local_d6b = 0;
  local_d6a = 0;
  local_d6c = 2;
  local_d69 = 0;
  local_d70 = 0x2300;
  local_d6e = 0x40f;
  uStack_d64 = local_d78;
  local_d68 = uVar15;
  FUN_001b7d90(&local_d70,0x10);
  std::__cxx11::string::_M_dispose();
  return;
}

