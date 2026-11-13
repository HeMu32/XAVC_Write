// mpr::dbg::SetClipStatusInPlay
// Ghidra address: 001a1180

/* mpr::dbg::SetClipStatusInPlay(int, char**) */

undefined8 mpr::dbg::SetClipStatusInPlay(int param_1,char **param_2)

{
  set *this;
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined4 local_63c;
  undefined8 local_638;
  undefined4 uStack_630;
  uint local_62c;
  undefined4 local_628;
  recordInfo arStack_620 [1568];
  
  record_cmd(param_1,param_2);
  uVar7 = 0;
  local_628 = 0;
  uVar5 = 0;
  local_63c = 0;
  local_638 = 0x123456780000007e;
  local_62c = *(uint *)(PTR_g_msidconv_00401cd8 + 0x7c);
  uStack_630 = 0;
  *(undefined4 *)PTR_optind_00401fe8 = 0;
  *(undefined4 *)PTR_opterr_00402bd8 = 1;
  sidb::recordInfo::clear(arStack_620);
  puVar2 = PTR_optarg_00401fc8;
  puVar1 = PTR_opt_setClipStatusInPlay_004017e0;
  while( true ) {
    while( true ) {
      iVar3 = getopt_long(param_1,param_2,"hs:i:c:",puVar1,&local_63c);
      if (iVar3 == -1) {
        this = (set *)(PTR_g_rootContentSet_00402d48 + uVar7 * 0x20);
        iVar3 = sidb::GetRootSet(*(undefined4 *)(PTR_g_msidconv_00401cd8 + uVar7 * 0x80 + 0x7c),
                                 *(undefined4 *)PTR_g_filter_00402410,0,1,this);
        if (iVar3 == 0) {
          uVar5 = sidb::set::at(this,uVar5);
          sidb::Select(local_62c,uVar5,arStack_620,true);
        }
        return 1;
      }
      if (iVar3 != 0x69) break;
      uVar5 = atoi(*(char **)puVar2);
    }
    if (iVar3 != 0x73) break;
    uVar4 = atoi(*(char **)PTR_optarg_00401fc8);
    uVar7 = (ulong)uVar4;
    if (3 < uVar4) {
      return 1;
    }
    local_62c = *(uint *)(PTR_g_msidconv_00401cd8 + uVar7 * 0x80 + 0x7c);
  }
  if (iVar3 != 99) {
    return 1;
  }
  if (0xb < **(byte **)PTR_optarg_00401fc8 - 100) {
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x001a128c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar6 = (*(code *)((long)(char)(&switchD_001a128c::switchdataD_003d18a0)
                                 [**(byte **)PTR_optarg_00401fc8 - 100] * 4 + 0x1a1290))();
  return uVar6;
}

