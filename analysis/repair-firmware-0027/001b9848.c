// mpr::RegisterM4RecordInfoOnSidb
// Ghidra address 001b9848; ELF VMA = Ghidra - 0x100000

/* mpr::RegisterM4RecordInfoOnSidb(unsigned int, mpr::ExistedFileInfo) */

undefined4 mpr::RegisterM4RecordInfoOnSidb(uint param_1,ushort *param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  ulong uVar5;
  uint uVar6;
  uint local_7b4;
  undefined8 local_7b0 [4];
  char acStack_790 [104];
  char acStack_728 [264];
  undefined4 local_620;
  uint local_61c;
  undefined4 local_618;
  undefined8 local_614;
  undefined4 local_60c;
  undefined1 local_604;
  undefined4 local_600;
  undefined1 local_5fc;
  char local_560;
  char acStack_55f [262];
  char local_459;
  char acStack_458 [262];
  char local_352;
  char acStack_351 [262];
  char local_24b;
  char acStack_24a [266];
  undefined8 local_140;
  undefined8 local_138;
  undefined8 local_130;
  int local_c;
  undefined1 local_7;
  undefined1 local_6;
  
  puVar1 = PTR_g_msidconv_00401cd8;
  uVar5 = (ulong)param_1;
  if (param_1 < 4) {
    uVar6 = *(uint *)(PTR_g_msidconv_00401cd8 + uVar5 * 0x80 + 0x7c);
  }
  else {
    uVar6 = 0xffffffff;
  }
  msidconv::GetLoadPathFromSlotID((msidconv *)PTR_g_msidconv_00401cd8,param_1,acStack_790);
  uVar3 = 0;
  if (param_1 < 4) {
    uVar3 = puVar1[uVar5 * 0x80];
  }
  FUN_001b7eb8((string *)local_7b0,uVar3);
  std::__cxx11::string::operator+=((string *)local_7b0,":");
  std::__cxx11::string::operator+=((string *)local_7b0,acStack_790);
  if (*(int *)(*(long *)PTR_gp_paramBoard_00402470 + uVar5 * 0x2c + 0x50) == 3) {
    std::__cxx11::string::operator+=((string *)local_7b0,"/PRIVATE");
  }
  std::__cxx11::string::operator+=((string *)local_7b0,"/M4ROOT");
  if (*(int *)(param_2 + 0x3c) == 2) {
    snprintf(acStack_728,0x106,"%s%03d%s",*(undefined8 *)(param_2 + 4),(ulong)(*param_2 % 1000),
             param_2 + 0x3e);
  }
  else {
    snprintf(acStack_728,0x106,"%s%04d",*(undefined8 *)(param_2 + 4),(ulong)*param_2);
  }
  sidb::recordInfo::clear((recordInfo *)&local_620);
  sidb::recordInfo::clear((recordInfo *)&local_620);
  local_7b4 = 0;
  iVar2 = sidb::IssueUniqueId(uVar6,&local_7b4,false);
  if (iVar2 == 0) {
    local_618 = 0;
    local_620 = 4;
    local_600 = 0;
    local_61c = local_7b4;
    local_614 = *(undefined8 *)(param_2 + 0x14);
    local_60c = *(undefined4 *)(param_2 + 0x18);
    local_604 = 1;
    local_5fc = (undefined1)param_2[0x1a];
    local_560 = (char)param_2[0x1c];
    if (local_560 != '\0') {
      snprintf(acStack_55f,0x106,"%s/CLIP/%s.%s",local_7b0[0],acStack_728,(long)param_2 + 0x39);
      local_140 = *(undefined8 *)(param_2 + 0x20);
    }
    local_459 = (char)param_2[0x24];
    if (local_459 != '\0') {
      snprintf(acStack_458,0x106,"%s/CLIP/%sM01.%s",local_7b0[0],acStack_728,(long)param_2 + 0x49);
    }
    local_352 = (char)param_2[0x2c];
    if (local_352 != '\0') {
      snprintf(acStack_351,0x106,"%s/THMBNL/%sT01.%s",local_7b0[0],acStack_728,(long)param_2 + 0x59)
      ;
      local_130 = *(undefined8 *)(param_2 + 0x30);
    }
    local_24b = (char)param_2[0x34];
    if (local_24b != '\0') {
      snprintf(acStack_24a,0x106,"%s/SUB/%sS03.%s",local_7b0[0],acStack_728,(long)param_2 + 0x69);
      local_138 = *(undefined8 *)(param_2 + 0x38);
    }
    local_7 = 0;
    local_6 = 1;
    local_c = 1;
    if (1 < *(uint *)(param_2 + 0x3c)) {
      local_c = (uint)(*(uint *)(param_2 + 0x3c) == 2) << 1;
    }
    iVar2 = sidb::Update(0xffffffff,(recordInfo *)&local_620,false,false);
    uVar4 = 0;
    if (iVar2 == 0) goto LAB_001b9988;
  }
  uVar4 = 2;
LAB_001b9988:
  std::__cxx11::string::_M_dispose();
  return uVar4;
}

