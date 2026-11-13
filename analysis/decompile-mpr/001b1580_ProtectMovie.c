// mpr::ProtectMovie
// Ghidra address: 001b1580

/* mpr::ProtectMovie(unsigned int, unsigned int, mpr::ProtectCtrl, sidb::recordInfo&, bool) */

undefined4
mpr::ProtectMovie(undefined4 param_1,undefined4 param_2,int param_3,recordInfo *param_4,char param_5
                 )

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  long lVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 local_68;
  undefined1 local_64;
  undefined1 local_63;
  undefined1 local_62;
  undefined1 local_61;
  int local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  char *local_40;
  char *local_38;
  undefined8 local_30;
  undefined1 local_28 [8];
  undefined1 auStack_20 [22];
  byte local_a;
  
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uVar6 = 0xb;
  iVar3 = LockEditTargetFiles(param_4,(vector *)&local_58);
  if (iVar3 != 0) goto LAB_001b17ec;
  uVar6 = 0;
  local_28[0] = param_4[0xc0];
  local_40 = (char *)0x0;
  local_38 = (char *)0x0;
  local_30 = 0;
  FUN_001aa364(auStack_20,param_4 + 0xc1);
  FUN_001b0fa4(&local_40,local_28);
  std::__cxx11::string::_M_dispose();
  local_28[0] = param_4[0x1c7];
  FUN_001aa364(auStack_20,param_4 + 0x1c8);
  FUN_001b0fa4(&local_40,local_28);
  std::__cxx11::string::_M_dispose();
  local_28[0] = param_4[0x3d5];
  FUN_001aa364(auStack_20,param_4 + 0x3d6);
  FUN_001b0fa4(&local_40,local_28);
  std::__cxx11::string::_M_dispose();
  local_28[0] = param_4[0x2ce];
  FUN_001aa364(auStack_20,param_4 + 0x2cf);
  FUN_001b0fa4(&local_40,local_28);
  std::__cxx11::string::_M_dispose();
  puVar2 = PTR_DAT_00402c30;
  pcVar5 = local_40;
LAB_001b169c:
  if (local_38 != pcVar5) {
    if (*pcVar5 == '\0') goto LAB_001b1814;
    Fsys_Stat(*(undefined8 *)(pcVar5 + 8),local_28);
    bVar1 = local_a & 0xfe;
    if (param_3 == 0) {
      bVar1 = local_a | 1;
    }
    thread::normalLock::lock((normalLock *)puVar2);
    iVar3 = Fsys_Chmod(*(undefined8 *)(pcVar5 + 8),bVar1);
    thread::normalLock::unlock((normalLock *)puVar2);
    if (iVar3 == 0 || iVar3 == -0x7fffffaf) goto LAB_001b1814;
    local_64 = 3;
    local_68 = 0x150021b0;
    local_63 = 0;
    local_62 = 0;
    local_61 = 0;
    local_60 = iVar3;
    FUN_001aa3f8(&local_68,0xc);
    FUN_001aaa3c(0x21b0,0x1501,0x28,*(undefined8 *)(pcVar5 + 8));
    puVar2 = PTR_s_directProtectReqCnt_00401f18;
    thread::normalLock::lock((normalLock *)(PTR_s_directProtectReqCnt_00401f18 + 0x30));
    local_68 = param_2;
    lVar4 = FUN_001acbd8(puVar2,&local_68);
    pcVar5 = local_40;
    if (lVar4 == 1) {
      for (; pcVar5 != local_38; pcVar5 = pcVar5 + 0x28) {
        if (*pcVar5 != '\0') {
          Fsys_Chmod(*(undefined8 *)(pcVar5 + 8),local_a);
        }
      }
      sidb::PartialUpdate<int>(0xffffffff,param_2,10,local_a & 1,0,1);
    }
    uVar6 = 0xb;
    thread::normalLock::unlock((normalLock *)(PTR_s_directProtectReqCnt_00401f18 + 0x30));
    goto LAB_001b17dc;
  }
  if (param_5 == '\0') {
    iVar3 = sidb::PartialUpdate<bool>(0xffffffff,param_2,10,param_3 == 0,0,1);
    uVar6 = 0;
    if (iVar3 == 0) goto LAB_001b17dc;
    uVar6 = 2;
  }
  else {
    sidb::PartialUpdate<int>(0xffffffff,param_2,0x19,0,0,0);
    sidb::NotifyChangeEvent(param_1,param_2,3,1,1);
LAB_001b17dc:
    UnlockEditTargetFiles((vector *)&local_58);
  }
  FUN_001aca2c(&local_40);
LAB_001b17ec:
  FUN_001adca0((vector *)&local_58);
  return uVar6;
LAB_001b1814:
  pcVar5 = pcVar5 + 0x28;
  goto LAB_001b169c;
}

