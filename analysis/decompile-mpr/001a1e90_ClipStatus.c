// mpr::dbg::ClipStatus
// Ghidra address: 001a1e90

/* mpr::dbg::ClipStatus(int, char**) */

undefined8 mpr::dbg::ClipStatus(int param_1,char **param_2)

{
  char *pcVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  ContentsList *pCVar9;
  undefined8 *puVar10;
  set *psVar11;
  long lVar12;
  undefined4 local_24;
  char acStack_20 [32];
  
  record_cmd(param_1,param_2);
  local_24 = 0;
  *(undefined4 *)PTR_optind_00401fe8 = 0;
  *(undefined4 *)PTR_opterr_00402bd8 = 1;
  puVar10 = *(undefined8 **)PTR_gp_contentsList_00402698;
  if (puVar10 != (undefined8 *)0x0) {
    if ((void *)*puVar10 != (void *)0x0) {
      operator_delete((void *)*puVar10);
    }
    operator_delete(puVar10,0x18);
  }
  puVar10 = operator_new(0x18);
  psVar11 = (set *)PTR_g_rootContentSet_00402d48;
  puVar5 = PTR_opt_clipStatus_00402930;
  puVar3 = PTR_gp_contentsList_00402698;
  puVar2 = PTR_optarg_00401fc8;
  *puVar10 = 0;
  puVar10[1] = 0;
  puVar10[2] = 0;
  *(undefined8 **)puVar3 = puVar10;
  while( true ) {
    while( true ) {
      while( true ) {
        iVar6 = getopt_long(param_1,param_2,"hs:i:c:",puVar5,&local_24);
        puVar4 = PTR_gp_contentsList_00402698;
        puVar3 = PTR_optarg_00401fc8;
        if (iVar6 == -1) {
          return 1;
        }
        if (iVar6 != 0x69) break;
        lVar12 = 0;
        iVar6 = 0;
        do {
          iVar8 = (int)lVar12;
          if (*(char *)(*(long *)puVar2 + lVar12) == '+') {
            strncpy(acStack_20,(char *)(*(long *)puVar2 + (long)iVar6),(long)(iVar8 - iVar6));
            pCVar9 = *(ContentsList **)puVar4;
            iVar6 = iVar8 + 1;
            uVar7 = atoi(acStack_20);
            ContentsList::Add(pCVar9,psVar11,uVar7);
          }
          pcVar1 = (char *)(*(long *)puVar3 + lVar12);
          lVar12 = lVar12 + 1;
        } while (*pcVar1 != '\0');
        if (iVar6 <= iVar8) {
          strncpy(acStack_20,(char *)(*(long *)puVar3 + (long)iVar6),(long)(iVar8 - iVar6));
          pCVar9 = *(ContentsList **)PTR_gp_contentsList_00402698;
          uVar7 = atoi(acStack_20);
          ContentsList::Add(pCVar9,psVar11,uVar7);
        }
      }
      if (iVar6 != 0x73) break;
      uVar7 = atoi(*(char **)PTR_optarg_00401fc8);
      if (3 < uVar7) {
        return 1;
      }
      psVar11 = (set *)(PTR_g_rootContentSet_00402d48 + (ulong)uVar7 * 0x20);
      iVar6 = sidb::GetRootSet(*(undefined4 *)(PTR_g_msidconv_00401cd8 + (ulong)uVar7 * 0x80 + 0x7c)
                               ,*(undefined4 *)PTR_g_filter_00402410,0,1,psVar11);
      if (iVar6 != 0) {
        return 1;
      }
    }
    if (iVar6 != 99) {
      return 1;
    }
    if (0xb < (byte)(**(char **)PTR_optarg_00401fc8 + 0x9cU)) break;
    if ((1L << ((ulong)(byte)(**(char **)PTR_optarg_00401fc8 + 0x9cU) & 0x3f) & 0xc81U) == 0) {
      return 1;
    }
  }
  return 1;
}

