// mpr::ProtectStill
// Ghidra address: 001b0ff0

/* mpr::ProtectStill(unsigned int, unsigned int, mpr::ProtectCtrl, sidb::recordInfo&, bool) */

undefined4
mpr::ProtectStill(undefined4 param_1,undefined4 param_2,int param_3,recordInfo *param_4,uint param_5
                 )

{
  byte bVar1;
  char cVar2;
  normalLock *this;
  undefined *puVar3;
  int iVar4;
  string *psVar5;
  long lVar6;
  char *pcVar7;
  undefined4 uVar8;
  char *pcVar9;
  undefined8 local_d18;
  undefined8 uStack_d10;
  undefined8 local_d08;
  char *local_d00;
  char *local_cf8;
  undefined8 local_cf0;
  char *local_ce8;
  long local_ce0;
  char local_cd8 [16];
  undefined1 *local_cc8;
  undefined8 local_cc0;
  undefined1 local_cb8 [16];
  char acStack_ca8 [32];
  string asStack_c88 [32];
  undefined1 auStack_c68 [32];
  undefined2 local_c48;
  undefined2 uStack_c46;
  undefined1 uStack_c44;
  undefined1 uStack_c43;
  undefined1 uStack_c42;
  undefined1 uStack_c41;
  int local_c40;
  string local_c28;
  undefined1 uStack_c27;
  undefined2 uStack_c26;
  undefined1 uStack_c24;
  undefined1 uStack_c23;
  undefined1 uStack_c22;
  undefined1 uStack_c21;
  undefined4 local_c20;
  undefined4 local_c1c;
  int local_c18;
  uint local_c14;
  byte local_c0a;
  byte local_c02;
  
  uStack_c24 = 1;
  uStack_c26 = 0x1100;
  local_c28 = (string)0xb0;
  uStack_c27 = 0x21;
  uStack_c23 = 0;
  uStack_c22 = 0;
  uStack_c21 = 0;
  local_c20 = param_1;
  local_c1c = param_2;
  local_c18 = param_3;
  local_c14 = param_5 & 0xff;
  FUN_001aa3f8(&local_c28,0x18);
  local_c28 = (string)0xb0;
  uStack_c27 = 0x21;
  uVar8 = 0xb;
  uStack_c24 = 3;
  uStack_c23 = 0;
  uStack_c26 = 0x1101;
  uStack_c22 = 0;
  uStack_c21 = 0;
  local_c20 = SUB84(param_4,0);
  FUN_001aa3f8(&local_c28,0xc);
  local_d18 = 0;
  uStack_d10 = 0;
  local_d08 = 0;
  iVar4 = LockEditTargetFiles(param_4,(vector *)&local_d18);
  if (iVar4 != 0) goto LAB_001b1450;
  uVar8 = 0;
  local_c28 = *(string *)(param_4 + 0xc0);
  local_d00 = (char *)0x0;
  local_cf8 = (char *)0x0;
  local_cf0 = 0;
  FUN_001aa364(&local_c20,param_4 + 0xc1);
  FUN_001b0fa4(&local_d00,&local_c28);
  std::__cxx11::string::_M_dispose();
  local_c28 = *(string *)(param_4 + 0x1c7);
  FUN_001aa364(&local_c20,param_4 + 0x1c8);
  FUN_001b0fa4(&local_d00,&local_c28);
  std::__cxx11::string::_M_dispose();
  local_c28 = *(string *)(param_4 + 0x2ce);
  FUN_001aa364(&local_c20,param_4 + 0x2cf);
  FUN_001b0fa4(&local_d00,&local_c28);
  std::__cxx11::string::_M_dispose();
  local_c28 = *(string *)(param_4 + 0x3d5);
  FUN_001aa364(&local_c20,param_4 + 0x3d6);
  FUN_001b0fa4(&local_d00,&local_c28);
  std::__cxx11::string::_M_dispose();
  local_cd8[0] = '\0';
  local_ce8 = local_cd8;
  local_ce0 = 0;
  local_cc8 = local_cb8;
  local_cb8[0] = 0;
  local_cc0 = 0;
  pcVar7 = local_d00;
  do {
    pcVar9 = local_d00;
    this = (normalLock *)PTR_DAT_00402c30;
    if (local_cf8 == pcVar7) goto LAB_001b12ec;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 0x28;
  } while (cVar2 == '\0');
  std::__cxx11::string::_M_assign((string *)&local_ce8);
  std::__cxx11::string::substr((ulong)&local_ce8,0);
  std::__cxx11::string::operator=((string *)&local_cc8,&local_c28);
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::substr((ulong)&local_ce8,0);
  psVar5 = (string *)std::__cxx11::string::append(acStack_ca8);
  std::__cxx11::string::string(asStack_c88,psVar5);
  std::__cxx11::string::substr((ulong)&local_ce8,local_ce0 - 8);
  FUN_001ac06c(&local_c48,asStack_c88,auStack_c68);
  psVar5 = (string *)std::__cxx11::string::append((char *)&local_c48);
  std::__cxx11::string::string(&local_c28,psVar5);
  std::__cxx11::string::operator=((string *)&local_ce8,&local_c28);
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::_M_dispose();
  pcVar9 = local_d00;
  this = (normalLock *)PTR_DAT_00402c30;
LAB_001b12ec:
  if (pcVar9 != local_cf8) {
    if (*pcVar9 == '\0') goto LAB_001b147c;
    Fsys_Stat(*(undefined8 *)(pcVar9 + 8),&local_c28);
    bVar1 = local_c0a & 0xfe;
    if (param_3 == 0) {
      bVar1 = local_c0a | 1;
    }
    thread::normalLock::lock(this);
    iVar4 = Fsys_Chmod(*(undefined8 *)(pcVar9 + 8),bVar1);
    thread::normalLock::unlock(this);
    if (iVar4 == 0 || iVar4 == -0x7fffffaf) goto LAB_001b147c;
    uStack_c44 = 3;
    local_c48 = 0x21b0;
    uStack_c46 = 0x1102;
    uStack_c43 = 0;
    uStack_c42 = 0;
    uStack_c41 = 0;
    local_c40 = iVar4;
    FUN_001aa3f8(&local_c48,0xc);
    FUN_001aaa3c(0x21b0,0x1103,0x28,*(undefined8 *)(pcVar9 + 8));
    puVar3 = PTR_s_directProtectReqCnt_00401f18;
    thread::normalLock::lock((normalLock *)(PTR_s_directProtectReqCnt_00401f18 + 0x30));
    local_c48 = (undefined2)param_2;
    uStack_c46 = (undefined2)((uint)param_2 >> 0x10);
    lVar6 = FUN_001acbd8(puVar3,&local_c48);
    pcVar7 = local_d00;
    if (lVar6 == 1) {
      for (; pcVar7 != local_cf8; pcVar7 = pcVar7 + 0x28) {
        if (*pcVar7 != '\0') {
          Fsys_Chmod(*(undefined8 *)(pcVar7 + 8),local_c0a);
        }
      }
      sidb::PartialUpdate<int>(0xffffffff,param_2,10,local_c0a & 1,0,1);
    }
    thread::normalLock::unlock((normalLock *)(PTR_s_directProtectReqCnt_00401f18 + 0x30));
    goto LAB_001b142c;
  }
  if (((byte)param_4[0x61c] >> 3 & 1) == 0) {
LAB_001b1510:
    if ((param_5 & 0xff) != 0) {
      sidb::PartialUpdate<int>(0xffffffff,param_2,0x19,0,0,0);
      sidb::NotifyChangeEvent(param_1,param_2,3,1,1);
      goto LAB_001b1430;
    }
    iVar4 = sidb::PartialUpdate<bool>(0xffffffff,param_2,10,param_3 == 0,0,1);
    uVar8 = 0;
    if (iVar4 == 0) goto LAB_001b1430;
    uVar8 = 2;
  }
  else {
    pcVar7 = local_ce8;
    while (iVar4 = FindDcfFile(pcVar7,(FSYSFINDINFO *)&local_c28), iVar4 == 0) {
      bVar1 = local_c02 & 0xfe;
      local_c02 = local_c02 | 1;
      if (param_3 != 0) {
        local_c02 = bVar1;
      }
      std::__cxx11::string::string((string *)&local_c48,(string *)&local_cc8);
      std::__cxx11::string::append((char *)&local_c48);
      iVar4 = Fsys_Chmod(CONCAT17(uStack_c41,
                                  CONCAT16(uStack_c42,
                                           CONCAT15(uStack_c43,
                                                    CONCAT14(uStack_c44,
                                                             CONCAT22(uStack_c46,local_c48))))),
                         local_c02);
      if (iVar4 != 0) {
        std::__cxx11::string::_M_dispose();
        goto LAB_001b142c;
      }
      std::__cxx11::string::_M_dispose();
      pcVar7 = (char *)0x0;
    }
    if (iVar4 != 0xb) goto LAB_001b1510;
LAB_001b142c:
    uVar8 = 0xb;
LAB_001b1430:
    UnlockEditTargetFiles((vector *)&local_d18);
  }
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::_M_dispose();
  FUN_001aca2c(&local_d00);
LAB_001b1450:
  FUN_001adca0((vector *)&local_d18);
  return uVar8;
LAB_001b147c:
  pcVar9 = pcVar9 + 0x28;
  goto LAB_001b12ec;
}

