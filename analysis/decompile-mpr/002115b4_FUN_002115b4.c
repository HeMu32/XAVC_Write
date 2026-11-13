// FUN_002115b4
// Ghidra address: 002115b4

ulong FUN_002115b4(uint param_1,uint param_2,undefined8 param_3,char *param_4)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 uVar4;
  uint uVar5;
  uint local_658;
  uint local_654;
  undefined2 local_650;
  undefined2 local_64e;
  undefined1 local_64c;
  undefined1 local_64b;
  undefined1 local_64a;
  undefined1 local_649;
  uint local_648;
  uint uStack_644;
  undefined8 local_640 [4];
  uint local_620 [4];
  undefined1 *local_610;
  undefined8 uStack_608;
  undefined1 local_600 [161];
  undefined1 auStack_55f [788];
  char local_24b;
  undefined1 auStack_24a [266];
  undefined8 local_140;
  undefined8 local_138;
  uint local_1c;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  
  local_620[0] = 0xe502311;
  local_620[1] = 4;
  FUN_0020aff4((recordInfo *)local_620,8);
  local_658 = 0;
  uVar2 = 0;
  FUN_00354f88(param_3,&local_658);
  while( true ) {
    if (local_658 <= uVar2) {
      uVar2 = 0;
      local_654 = 3;
      FUN_00354304(param_3,&local_654);
      if (local_654 < 4) {
        uVar2 = (uint)(byte)(&UNK_003d61e0)[local_654];
      }
      uVar5 = 0xffffffff;
      sidb::recordInfo::clear((recordInfo *)local_620);
      if (param_1 < 4) {
        uVar5 = *(uint *)(PTR_g_msidconv_00401cd8 + (ulong)param_1 * 0x80 + 0x7c);
      }
      sidb::Select(0xffffffff,param_2,(recordInfo *)local_620,true);
      local_18 = 0;
      local_17 = 0;
      local_14 = 0;
      local_16 = 0;
      local_13 = 0;
      local_15 = 0;
      local_12 = 0;
      local_11 = 0;
      local_10 = 0;
      local_f = 0;
      local_1c = uVar2;
      iVar1 = Fsys_Stat(auStack_55f,local_640);
      if (iVar1 == 0) {
        local_140 = local_640[0];
      }
      if ((local_24b != '\0') && (iVar1 = Fsys_Stat(auStack_24a,local_640), iVar1 == 0)) {
        local_138 = local_640[0];
      }
      sidb::Update(0xffffffff,(recordInfo *)local_620,true,false);
      if (*param_4 != '\0') {
        sidb::NotifyChangeEvent(uVar5,param_2,3,8,1);
      }
      if (param_4[1] != '\0') {
        sidb::NotifyChangeEvent(uVar5,param_2,3,0x10,1);
      }
      uVar2 = sidb::Flush(uVar5);
      if (uVar2 == 0) {
        local_64c = 4;
        local_64e = 0xe5f;
        uVar4 = 8;
      }
      else {
        local_64c = 2;
        local_64e = 0xe51;
        uVar4 = 0x10;
        local_648 = uVar5;
        uStack_644 = uVar2;
      }
      local_649 = 0;
      local_64a = 0;
      local_64b = 0;
      local_650 = 0x2311;
      FUN_0020aff4(&local_650,uVar4);
      return (ulong)uVar2;
    }
    uStack_608 = 0;
    local_600[0] = 0;
    local_620[0] = 0;
    local_620[1] = 0;
    local_620[2] = 0;
    local_610 = local_600;
    FUN_00355384(param_3,uVar2,1,(recordInfo *)local_620,local_640);
    if (local_620[0] < 10) break;
    uVar2 = uVar2 + 1;
    std::__cxx11::string::_M_dispose();
  }
                    /* WARNING: Could not recover jumptable at 0x002116b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*(code *)((long)(char)(&DAT_003d6140)[local_620[0]] * 4 + 0x2116b8))();
  return uVar3;
}

