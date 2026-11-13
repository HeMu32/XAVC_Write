// mpr::dbg::db
// Ghidra address: 0019996c

/* mpr::dbg::db(int, char**) */

undefined8 mpr::dbg::db(int param_1,char **param_2)

{
  long lVar1;
  set *this;
  undefined *puVar2;
  undefined *puVar3;
  undefined *this_00;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  ulong uVar9;
  long lVar10;
  undefined4 local_6c4;
  undefined8 local_6c0;
  undefined8 uStack_6b8;
  undefined4 local_6b0;
  set asStack_6a8 [32];
  char acStack_688 [104];
  int local_620 [48];
  char local_560;
  char local_459;
  char local_352;
  char local_24b;
  byte local_128 [296];
  
  local_6c4 = 0;
  *(undefined4 *)PTR_optind_00401fe8 = 0;
  uVar7 = 0xfffffff0;
  uVar5 = 0;
  uVar9 = 0;
  *(undefined4 *)PTR_opterr_00402bd8 = 1;
  sidb::set::set(asStack_6a8);
  puVar3 = PTR_opt_db_00402468;
  puVar2 = PTR_optarg_00401fc8;
  local_6c0 = DAT_003d18e8;
  uStack_6b8 = DAT_003d18f0;
  local_6b0 = DAT_003d18f8;
  while (iVar4 = getopt_long(param_1,param_2,"hs:f:b:e:",puVar3,&local_6c4),
        this_00 = PTR_sw_00402db8, iVar4 != -1) {
    if (iVar4 == 0x65) {
      uVar7 = atoi(*(char **)puVar2);
    }
    else if (iVar4 == 0x73) {
      uVar6 = atoi(*(char **)PTR_optarg_00401fc8);
      uVar9 = (ulong)uVar6;
    }
    else {
      if (iVar4 != 0x62) goto LAB_00199d98;
      uVar5 = atoi(*(char **)PTR_optarg_00401fc8);
    }
  }
  uVar8 = 0xffffffff;
  if ((uint)uVar9 < 4) {
    uVar8 = *(undefined4 *)(PTR_g_msidconv_00401cd8 + uVar9 * 0x80 + 0x7c);
  }
  local_6c0 = CONCAT44(local_6c0._4_4_,uVar8);
  mpr::sw::start((sw *)PTR_sw_00402db8,"mpr::sw");
  this = (set *)(PTR_g_rootContentSet_00402d48 + uVar9 * 0x20);
  iVar4 = sidb::GetRootSet(1,&local_6c0,*(undefined4 *)PTR_g_filter_00402410,0,1,0,this);
  if (iVar4 == 0) {
    mpr::sw::pause((sw *)this_00,"mpr::sw");
    mpr::sw::pause_release((sw *)this_00,"mpr::sw");
    iVar4 = sidb::set::size(this);
    mpr::sw::stop((sw *)this_00,"mpr::sw");
    if (iVar4 != 0) {
      uVar6 = iVar4 - 1;
      if (uVar7 != 0xfffffff0) {
        uVar6 = uVar7;
      }
      for (; uVar5 <= uVar6; uVar5 = uVar5 + 1) {
        uVar7 = sidb::set::at(this,uVar5);
        sidb::recordInfo::clear((recordInfo *)local_620);
        sidb::Select(0xffffffff,uVar7,(recordInfo *)local_620,true);
        if ((local_620[0] == 1) && (local_560 != '\0')) {
          lVar10 = 0;
          do {
            lVar1 = lVar10 + 1;
            snprintf(acStack_688 + lVar10 * 3,4,"%02x ",(ulong)local_128[lVar10 + 0xc]);
            lVar10 = lVar1;
          } while (lVar1 != 0x20);
        }
        if ((local_620[0] == 1) && (local_459 != '\0')) {
          lVar10 = 0;
          do {
            lVar1 = lVar10 + 1;
            snprintf(acStack_688 + lVar10 * 3,4,"%02x ",(ulong)local_128[lVar10 + 0x2c]);
            lVar10 = lVar1;
          } while (lVar1 != 0x20);
        }
        if ((local_620[0] == 1) && (local_352 != '\0')) {
          lVar10 = 0;
          do {
            lVar1 = lVar10 + 1;
            snprintf(acStack_688 + lVar10 * 3,4,"%02x ",(ulong)local_128[lVar10 + 0x4c]);
            lVar10 = lVar1;
          } while (lVar1 != 0x20);
        }
        if ((local_620[0] == 1) && (local_24b != '\0')) {
          lVar10 = 0;
          do {
            lVar1 = lVar10 + 1;
            snprintf(acStack_688 + lVar10 * 3,4,"%02x ",(ulong)local_128[lVar10 + 0x6c]);
            lVar10 = lVar1;
          } while (lVar1 != 0x20);
        }
        if ((local_620[0] == 4) && (local_560 != '\0')) {
          lVar10 = 0;
          do {
            lVar1 = lVar10 + 1;
            snprintf(acStack_688 + lVar10 * 3,4,"%02x ",(ulong)local_128[lVar10]);
            lVar10 = lVar1;
          } while (lVar1 != 0x20);
        }
        if ((local_620[0] == 4) && (local_459 != '\0')) {
          lVar10 = 0;
          do {
            lVar1 = lVar10 + 1;
            snprintf(acStack_688 + lVar10 * 3,4,"%02x ",(ulong)local_128[lVar10 + 0x20]);
            lVar10 = lVar1;
          } while (lVar1 != 0x20);
        }
        if ((local_620[0] == 4) && (local_352 != '\0')) {
          lVar10 = 0;
          do {
            lVar1 = lVar10 + 1;
            snprintf(acStack_688 + lVar10 * 3,4,"%02x ",(ulong)local_128[lVar10 + 0x40]);
            lVar10 = lVar1;
          } while (lVar1 != 0x20);
        }
        if ((local_620[0] == 4) && (local_24b != '\0')) {
          lVar10 = 0;
          do {
            lVar1 = lVar10 + 1;
            snprintf(acStack_688 + lVar10 * 3,4,"%02x ",(ulong)local_128[lVar10 + 0x60]);
            lVar10 = lVar1;
          } while (lVar1 != 0x20);
        }
        usleep(30000);
      }
      mpr::sw::print((sw *)PTR_sw_00402db8,"mpr::sw");
    }
  }
LAB_00199d98:
  sidb::set::~set(asStack_6a8);
  return 1;
}

