// mpr::dbg::GetEssenceMarks
// Ghidra address: 001a0b50

/* mpr::dbg::GetEssenceMarks(int, char**) */

undefined8 mpr::dbg::GetEssenceMarks(int param_1,char **param_2)

{
  set *this;
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  undefined4 local_66c;
  undefined8 local_668;
  undefined4 local_660;
  int local_65c;
  undefined8 local_658;
  undefined8 uStack_650;
  undefined4 local_648;
  undefined8 local_640;
  void *local_638;
  undefined8 local_630;
  undefined8 uStack_628;
  recordInfo arStack_620 [4];
  undefined4 local_61c;
  
  record_cmd(param_1,param_2);
  local_638 = (void *)0x0;
  local_630 = 0;
  uStack_628 = 0;
  uVar7 = 0;
  local_66c = 0;
  local_668 = 100;
  uVar5 = 0;
  local_660 = *(undefined4 *)(PTR_g_msidconv_00401cd8 + 0x7c);
  local_65c = 0;
  local_640 = 0x65;
  *(undefined4 *)PTR_optind_00401fe8 = 0;
  *(undefined4 *)PTR_opterr_00402bd8 = 1;
  sidb::recordInfo::clear(arStack_620);
  puVar3 = PTR_opt_getEssenceMarks_00402118;
  puVar2 = PTR_optarg_00401fc8;
  local_658 = DAT_003d18e8;
  uStack_650 = DAT_003d18f0;
  local_648 = DAT_003d18f8;
  while (iVar4 = getopt_long(param_1,param_2,"hs:i:m:",puVar3,&local_66c), iVar4 != -1) {
    if (iVar4 == 0x6d) {
      bVar1 = **(byte **)puVar2;
      if (bVar1 == 0x61) {
        local_65c = 0xc;
      }
      else if (bVar1 < 0x62) {
        if (bVar1 == 0x30) {
          local_65c = 9;
        }
        else {
          if ((bVar1 < 0x30) || (0x39 < bVar1)) goto LAB_001a0cc0;
          local_65c = atoi((char *)*(byte **)puVar2);
          local_65c = local_65c + -1;
        }
      }
      else if (bVar1 == 0x72) {
        local_65c = 10;
      }
      else if (bVar1 == 0x74) {
        local_65c = 0xb;
      }
      else {
        if (bVar1 != 99) goto LAB_001a0cc0;
        local_65c = 0xd;
      }
    }
    else if (iVar4 == 0x73) {
      uVar6 = atoi(*(char **)PTR_optarg_00401fc8);
      uVar7 = (ulong)uVar6;
      if (3 < uVar6) goto LAB_001a0cc0;
      local_660 = *(undefined4 *)(PTR_g_msidconv_00401cd8 + uVar7 * 0x80 + 0x7c);
    }
    else {
      if (iVar4 != 0x69) goto LAB_001a0cc0;
      uVar5 = atoi(*(char **)PTR_optarg_00401fc8);
    }
  }
  this = (set *)(PTR_g_rootContentSet_00402d48 + uVar7 * 0x20);
  uVar5 = sidb::set::at(this,uVar5);
  local_658 = CONCAT44(local_658._4_4_,
                       *(undefined4 *)(PTR_g_msidconv_00401cd8 + uVar7 * 0x80 + 0x7c));
  iVar4 = sidb::GetRootSet(1,&local_658,*(undefined4 *)PTR_g_filter_00402410,0,1,0,this);
  if (iVar4 == 0) {
    sidb::Select(0xffffffff,uVar5,arStack_620,true);
    local_668 = CONCAT44(local_61c,(undefined4)local_668);
    getEssenceMarksOutParam::DbgPrint((getEssenceMarksOutParam *)&local_640);
  }
LAB_001a0cc0:
  if (local_638 != (void *)0x0) {
    operator_delete(local_638);
  }
  return 1;
}

