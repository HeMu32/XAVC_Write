// mpr::dbg::SetEssenceMarkInPlay
// Ghidra address: 001a08d4

/* mpr::dbg::SetEssenceMarkInPlay(int, char**) */

undefined8 mpr::dbg::SetEssenceMarkInPlay(int param_1,char **param_2)

{
  set *this;
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  undefined4 local_654;
  undefined8 local_650;
  undefined8 uStack_648;
  undefined4 local_640;
  undefined8 local_638;
  undefined8 uStack_630;
  int local_628;
  int iStack_624;
  recordInfo arStack_620 [1568];
  
  record_cmd(param_1,param_2);
  local_654 = 0;
  local_628 = 0;
  iStack_624 = 0;
  uVar7 = 0;
  uVar6 = 0;
  local_638 = 0x1234567800000062;
  uStack_630 = (ulong)*(uint *)(PTR_g_msidconv_00401cd8 + 0x7c) << 0x20;
  *(undefined4 *)PTR_optind_00401fe8 = 0;
  *(undefined4 *)PTR_opterr_00402bd8 = 1;
  sidb::recordInfo::clear(arStack_620);
  puVar3 = PTR_opt_setEssenceMarkInPlay_00402ef0;
  puVar2 = PTR_optarg_00401fc8;
  local_650 = DAT_003d18e8;
  uStack_648 = DAT_003d18f0;
  local_640 = DAT_003d18f8;
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          iVar4 = getopt_long(param_1,param_2,"hs:i:f:m:",puVar3,&local_654);
          if (iVar4 == -1) {
            this = (set *)(PTR_g_rootContentSet_00402d48 + uVar7 * 0x20);
            uVar6 = sidb::set::at(this,uVar6);
            local_650 = CONCAT44(local_650._4_4_,
                                 *(undefined4 *)(PTR_g_msidconv_00401cd8 + uVar7 * 0x80 + 0x7c));
            iVar4 = sidb::GetRootSet(1,&local_650,*(undefined4 *)PTR_g_filter_00402410,0,1,0,this);
            if (iVar4 == 0) {
              sidb::Select(0xffffffff,uVar6,arStack_620,true);
            }
            return 1;
          }
          if (iVar4 != 0x69) break;
          uVar6 = atoi(*(char **)puVar2);
        }
        if (0x69 < iVar4) break;
        if (iVar4 != 0x66) {
          return 1;
        }
        local_628 = atoi(*(char **)PTR_optarg_00401fc8);
      }
      if (iVar4 != 0x6d) break;
      bVar1 = **(byte **)PTR_optarg_00401fc8;
      if (bVar1 == 0x61) {
        iStack_624 = 0xc;
      }
      else if (bVar1 < 0x62) {
        if (bVar1 == 0x30) {
          iStack_624 = 9;
        }
        else {
          if (bVar1 < 0x30) {
            return 1;
          }
          if (0x39 < bVar1) {
            return 1;
          }
          iStack_624 = atoi((char *)*(byte **)PTR_optarg_00401fc8);
          iStack_624 = iStack_624 + -1;
        }
      }
      else if (bVar1 == 0x72) {
        iStack_624 = 10;
      }
      else if (bVar1 == 0x74) {
        iStack_624 = 0xb;
      }
      else {
        if (bVar1 != 99) {
          return 1;
        }
        iStack_624 = 0xd;
      }
    }
    if (iVar4 != 0x73) {
      return 1;
    }
    uVar5 = atoi(*(char **)PTR_optarg_00401fc8);
    uVar7 = (ulong)uVar5;
    if (3 < uVar5) break;
    uStack_630 = CONCAT44(*(undefined4 *)(PTR_g_msidconv_00401cd8 + uVar7 * 0x80 + 0x7c),
                          (undefined4)uStack_630);
  }
  return 1;
}

