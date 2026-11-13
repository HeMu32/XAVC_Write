// mpr::dbg::still
// Ghidra address: 0019b0f8

/* mpr::dbg::still(int, char**) */

undefined8 mpr::dbg::still(int param_1,char **param_2)

{
  set *this;
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  void *__ptr;
  libstill *plVar10;
  ulong uVar11;
  char *__s2;
  undefined4 local_674;
  undefined8 local_670;
  undefined8 local_668;
  undefined8 uStack_660;
  undefined4 local_658;
  undefined8 local_650;
  undefined8 local_648;
  void *local_640;
  undefined8 uStack_638;
  undefined8 local_630;
  undefined8 uStack_628;
  ulong local_620 [2];
  void *local_610;
  undefined8 uStack_608;
  undefined8 local_600;
  undefined8 uStack_5f8;
  byte local_560;
  undefined1 auStack_55f [262];
  byte local_459;
  undefined1 auStack_458 [262];
  byte local_352;
  undefined1 auStack_351 [849];
  
  puVar2 = PTR_opt_still_00401c98;
  *(undefined4 *)PTR_optind_00401fe8 = 0;
  bVar1 = false;
  uVar7 = 0;
  uVar11 = 0;
  iVar5 = 0;
  local_674 = 0;
  *(undefined4 *)PTR_opterr_00402bd8 = 1;
  puVar3 = PTR_optarg_00401fc8;
  local_668 = DAT_003d18e8;
  uStack_660 = DAT_003d18f0;
  local_658 = DAT_003d18f8;
  while (iVar4 = getopt_long(param_1,param_2,"ha:t:s:i:",puVar2,&local_674), iVar4 != -1) {
    if (iVar4 == 0x69) {
      uVar7 = atoi(*(char **)puVar3);
    }
    else if (iVar4 < 0x6a) {
      if (iVar4 != 0x61) {
        return 1;
      }
      iVar4 = Fsys_Open(*(undefined8 *)PTR_optarg_00401fc8,&local_670,1);
      if (iVar4 != 0) {
        return 1;
      }
      bVar1 = true;
    }
    else if (iVar4 == 0x73) {
      uVar6 = atoi(*(char **)PTR_optarg_00401fc8);
      uVar11 = (ulong)uVar6;
    }
    else {
      if (iVar4 != 0x74) {
        return 1;
      }
      __s2 = *(char **)PTR_optarg_00401fc8;
      iVar5 = strncasecmp("JPEG",__s2,0x10);
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = strncasecmp("ARW",__s2,0x10);
        if (iVar5 == 0) {
          iVar5 = 1;
        }
        else {
          iVar5 = strncasecmp("HEIF",__s2,0x10);
          if (iVar5 != 0) {
            return 1;
          }
          iVar5 = 2;
        }
      }
    }
  }
  if (bVar1) goto LAB_0019b368;
  uVar8 = 0xffffffff;
  if ((uint)uVar11 < 4) {
    uVar8 = *(undefined4 *)(PTR_g_msidconv_00401cd8 + uVar11 * 0x80 + 0x7c);
  }
  local_668 = CONCAT44(local_668._4_4_,uVar8);
  this = (set *)(PTR_g_rootContentSet_00402d48 + uVar11 * 0x20);
  iVar4 = sidb::GetRootSet(1,&local_668,*(undefined4 *)PTR_g_filter_00402410,0,1,0,this);
  if (iVar4 != 0) goto LAB_0019b368;
  uVar7 = sidb::set::at(this,uVar7);
  sidb::recordInfo::clear((recordInfo *)local_620);
  sidb::Select(0xffffffff,uVar7,(recordInfo *)local_620,true);
  uVar11 = local_620[0] & 0xffffffff;
  if ((int)local_620[0] == 1) {
    if ((iVar5 == 0 & local_560) == 0) {
      if ((iVar5 == 1 & local_459) == 0) {
        if ((iVar5 == 2 & local_352) == 0) {
          return 1;
        }
        goto LAB_0019b440;
      }
      puVar9 = auStack_458;
    }
    else {
      puVar9 = auStack_55f;
    }
  }
  else {
    if ((int)local_620[0] != 4) {
      return 1;
    }
    if ((iVar5 == 0 & local_352) == 0) {
      return 1;
    }
    uVar11 = 1;
LAB_0019b440:
    puVar9 = auStack_351;
  }
  iVar4 = Fsys_Open(puVar9,&local_670,uVar11);
  if (iVar4 != 0) {
    return 1;
  }
LAB_0019b368:
  __ptr = malloc(0x40000);
  local_650 = 0;
  uStack_638 = 0;
  local_648 = 0x40000;
  local_620[0] = 0;
  local_620[1] = 0x40000;
  uStack_608 = 0;
  local_600 = local_630;
  uStack_5f8 = uStack_628;
  local_640 = __ptr;
  local_610 = __ptr;
  Fsys_Read(local_670,__ptr);
  Fsys_Close(local_670);
  plVar10 = (libstill *)FUN_0019b038(iVar5);
  (**(code **)(*(long *)plVar10 + 0x10))(plVar10,1);
  libstill::ana_if(plVar10,(recordInfo *)local_620,0);
  (**(code **)(*(long *)plVar10 + 0x10))(plVar10,0);
  free(__ptr);
  (**(code **)(*(long *)plVar10 + 8))(plVar10);
  return 1;
}

