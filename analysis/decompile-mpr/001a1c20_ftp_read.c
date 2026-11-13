// mpr::dbg::ftp_read
// Ghidra address: 001a1c20

/* mpr::dbg::ftp_read(int, char**) */

undefined8 mpr::dbg::ftp_read(int param_1,char **param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined *puVar6;
  execqueue<mpr::dbg::debug_input_t> *this;
  undefined4 uVar7;
  ulong uVar8;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  uint local_50;
  int iStack_4c;
  int local_48;
  undefined4 uStack_44;
  undefined1 local_40;
  undefined *local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined8 uStack_8;
  
  iVar4 = 1;
  record_cmd(param_1,param_2);
  local_40 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_10 = 0;
  uStack_8 = 0;
  uVar7 = 0;
  local_6c = 0;
  iVar3 = 0;
  *(undefined4 *)PTR_optind_00401fe8 = 0;
  uVar8 = 0;
  *(undefined4 *)PTR_opterr_00402bd8 = 1;
  local_68 = DAT_003d18e8;
  uStack_60 = DAT_003d18f0;
  local_58 = DAT_003d18f8;
  ThreadInfo::GetThreadInfo(0x72,(__osal_thread_info *)&local_30);
  puVar6 = PTR_opt_ftp_read_00402328;
LAB_001a1cd0:
  iVar1 = getopt_long(param_1,param_2,"hs:i:tecfl:rwxyz",puVar6,&local_6c);
  if (iVar1 == -1) {
    uVar2 = (uint)uVar8;
    uVar5 = 0xffffffff;
    if (uVar2 < 4) {
      uVar5 = *(undefined4 *)(PTR_g_msidconv_00401cd8 + uVar8 * 0x80 + 0x7c);
    }
    local_68 = CONCAT44(local_68._4_4_,uVar5);
    iVar1 = sidb::GetRootSet(1,&local_68,*(undefined4 *)PTR_g_filter_00402410,0,1,0,
                             PTR_g_rootContentSet_00402d48 + uVar8 * 0x20);
    puVar6 = PTR_debug_thread_00401a18;
    if (iVar1 == 0) {
      local_38 = PTR_ftp_read_loop_00402218;
      local_50 = uVar2;
      iStack_4c = iVar3;
      local_48 = iVar4;
      uStack_44 = uVar7;
      if (*(long *)PTR_debug_thread_00401a18 == 0) {
        this = operator_new(0xd8);
        execqueue<mpr::dbg::debug_input_t>::execqueue(this,(__osal_thread_info *)&local_30);
        *(execqueue<mpr::dbg::debug_input_t> **)puVar6 = this;
      }
      execqueue<mpr::dbg::debug_input_t>::exec
                (*(execqueue<mpr::dbg::debug_input_t> **)PTR_debug_thread_00401a18,
                 (exec_t *)&local_50);
    }
switchD_001a1d08_caseD_64:
    return 1;
  }
  switch(iVar1) {
  case 99:
    uVar7 = 3;
    goto LAB_001a1cd0;
  default:
    goto switchD_001a1d08_caseD_64;
  case 0x65:
    uVar7 = 4;
    goto LAB_001a1cd0;
  case 0x66:
    uVar7 = 0;
    goto LAB_001a1cd0;
  case 0x69:
    iVar3 = atoi(*(char **)PTR_optarg_00401fc8);
    goto LAB_001a1cd0;
  case 0x6c:
    iVar4 = atoi(*(char **)PTR_optarg_00401fc8);
    goto LAB_001a1cd0;
  case 0x72:
    local_40 = 1;
    goto LAB_001a1cd0;
  case 0x73:
    uVar2 = atoi(*(char **)PTR_optarg_00401fc8);
    uVar8 = (ulong)uVar2;
    goto LAB_001a1cd0;
  case 0x74:
    goto switchD_001a1d08_caseD_74;
  case 0x77:
    puVar6 = PTR_DAT_00402428;
    break;
  case 0x78:
    puVar6 = PTR_DAT_00402428;
    goto LAB_001a1dbc;
  case 0x79:
    puVar6 = PTR_DAT_00401d78;
    break;
  case 0x7a:
    puVar6 = PTR_DAT_00401d78;
LAB_001a1dbc:
    pthread_mutex_unlock((pthread_mutex_t *)(puVar6 + uVar8 * 0x30));
    return 1;
  }
  pthread_mutex_lock((pthread_mutex_t *)(puVar6 + uVar8 * 0x30));
  return 1;
switchD_001a1d08_caseD_74:
  uVar7 = 2;
  goto LAB_001a1cd0;
}

