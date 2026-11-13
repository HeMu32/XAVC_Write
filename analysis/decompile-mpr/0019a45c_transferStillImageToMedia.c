// mpr::dbg::transferStillImageToMedia
// Ghidra address: 0019a45c

/* mpr::dbg::transferStillImageToMedia(int, char**) */

undefined8 mpr::dbg::transferStillImageToMedia(int param_1,char **param_2)

{
  undefined4 uVar1;
  undefined1 uVar2;
  transferStillFileOutParam *ptVar3;
  undefined *puVar4;
  undefined *this;
  undefined *puVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  transferStillFileOutParam *ptVar9;
  char *pcVar10;
  undefined4 local_7c4;
  char local_7c0 [8];
  undefined8 local_7b8;
  transferStillFileInParam atStack_7b0 [4];
  undefined4 local_7ac;
  undefined1 *local_7a8;
  int local_7a0;
  undefined1 *local_798 [2];
  undefined1 auStack_788 [16];
  undefined1 auStack_778 [32];
  transferStillFileOutParam atStack_758 [12];
  uint local_74c;
  undefined4 local_748 [32];
  undefined4 local_6c8;
  undefined4 uStack_6c4;
  undefined4 local_6c0;
  undefined4 uStack_6bc;
  undefined4 local_6b8;
  long local_630;
  int local_620 [6];
  ushort local_606;
  char local_560;
  undefined1 auStack_55f [262];
  char local_459;
  undefined1 auStack_458 [262];
  char local_352;
  undefined1 auStack_351 [849];
  
  local_7c4 = 0;
  *(undefined4 *)PTR_optind_00401fe8 = 0;
  *(undefined4 *)PTR_opterr_00402bd8 = 1;
  file::transferStillFileInParam::transferStillFileInParam(atStack_7b0);
  file::transferStillFileOutParam::transferStillFileOutParam(atStack_758);
  sidb::recordInfo::clear((recordInfo *)local_620);
  puVar5 = PTR_opt_transferStillImageToMedia_00402d60;
  puVar4 = PTR_optarg_00401fc8;
  while (iVar6 = getopt_long(param_1,param_2,&DAT_003d1edd,puVar5,&local_7c4),
        this = PTR_s_test_root_set0_00402640, iVar6 != -1) {
    if (iVar6 != 0x6d) {
      return 1;
    }
    pcVar10 = *(char **)puVar4;
    iVar6 = strncasecmp(pcVar10,"SCN",0x10);
    if (iVar6 == 0) {
      local_7a0 = 3;
    }
    else {
      iVar6 = strncasecmp(pcVar10,"THM",0x10);
      if (iVar6 == 0) {
        local_7a0 = 2;
      }
    }
  }
  uVar1 = *(undefined4 *)(PTR_g_msidconv_00401cd8 + 0x7c);
  uStack_6c4 = 0xffff;
  local_6c0 = 0xffff;
  uStack_6bc = 0xffff;
  local_6b8 = 0xffff;
  local_6c8 = uVar1;
  iVar6 = sidb::GetRootSet(1,&local_6c8,1,0,1,0,PTR_s_test_root_set0_00402640);
  if (iVar6 != 0) {
    return 1;
  }
  iVar6 = sidb::set::size((set *)this);
  uVar7 = sidb::set::at((set *)this,iVar6 - 1);
  iVar6 = sidb::Select(0xffffffff,uVar7,(recordInfo *)local_620,true);
  if (iVar6 != 0) {
    return 1;
  }
  local_7a8 = (undefined1 *)0x0;
  if ((((local_620[0] == 1) && (local_7a8 = auStack_458, local_459 == '\0')) &&
      (local_7a8 = auStack_55f, local_560 == '\0')) && (local_7a8 = auStack_351, local_352 == '\0'))
  {
    local_7a8 = (undefined1 *)0x0;
  }
  local_7ac = uVar1;
  if (local_7a8 != (undefined1 *)0x0) {
    file::TransferStillFile(atStack_7b0,atStack_758);
  }
  uVar2 = *PTR_g_msidconv_00401cd8;
  local_798[0] = auStack_788;
  std::__cxx11::string::_M_construct((ulong)local_798,'\x01');
  std::__cxx11::string::operator+=((string *)local_798,":");
  std::__cxx11::string::operator+=((string *)local_798,"/DCIM/000TRANS");
  Fsys_Mkdir(local_798[0]);
  if (local_7a0 == 3) {
    pcVar10 = "/SCN_";
  }
  else {
    pcVar10 = "/THM_";
  }
  std::__cxx11::string::operator+=((string *)local_798,pcVar10);
  local_7c0[4] = 0;
  local_7c0[0] = '\0';
  local_7c0[1] = '\0';
  local_7c0[2] = '\0';
  local_7c0[3] = '\0';
  snprintf(local_7c0,5,"%04d",(ulong)local_606);
  FUN_00198a58(auStack_778,local_7c0);
  std::__cxx11::string::operator+=((string *)local_798,local_7c0);
  if ((local_459 == '\0') && (local_560 == '\0')) {
    if (local_352 == '\0') goto LAB_0019a6e0;
    pcVar10 = ".HIF";
  }
  else {
    pcVar10 = ".JPG";
  }
  std::__cxx11::string::operator+=((string *)local_798,pcVar10);
LAB_0019a6e0:
  iVar6 = Fsys_Open(local_798[0],&local_7b8,6);
  if (iVar6 == 0) {
    ptVar3 = atStack_758;
    for (uVar7 = 0; ptVar9 = ptVar3 + 0x10, uVar7 < local_74c; uVar7 = uVar7 + 1) {
      FUN_0035ca30(ptVar9);
      puVar8 = operator_new(4);
      uVar1 = *(undefined4 *)ptVar9;
      *puVar8 = 0;
      FUN_003b7640(uVar1,&local_6c8,1,puVar8);
      Fsys_Write(local_7b8,local_630 + (ulong)*(uint *)(ptVar3 + 0x14),
                 *(undefined4 *)(ptVar3 + 0x18));
      FUN_003b7968(*(undefined4 *)ptVar9);
      operator_delete(puVar8,4);
      ptVar3 = ptVar9;
    }
    Fsys_Close(local_7b8);
  }
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::_M_dispose();
  return 1;
}

