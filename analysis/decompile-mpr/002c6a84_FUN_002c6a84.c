// FUN_002c6a84
// Ghidra address: 002c6a84

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_002c6a84(uint *param_1,undefined8 param_2,undefined8 param_3,locale *param_4,uint param_5)

{
  uint uVar1;
  uint *puVar2;
  char cVar3;
  char *pcVar4;
  ulong uVar5;
  long lVar6;
  undefined *puVar7;
  undefined8 uVar8;
  ctype *pcVar9;
  long local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  long local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  undefined8 uStack_8;
  
  uVar1 = param_5 | 0x10;
  if ((param_5 & 0x3f0) != 0) {
    uVar1 = param_5;
  }
  *param_1 = uVar1;
  std::locale::locale((locale *)&local_50,param_4);
  memcpy(param_1 + 2,&DAT_003daef0,0x48);
  *(undefined1 *)((long)param_1 + 0x51) = 0;
  *(undefined1 *)((long)param_1 + 0x5e) = 0;
  *(undefined1 *)((long)param_1 + 0x5f) = 0;
  *(undefined1 *)(param_1 + 0x14) = 0x30;
  *(undefined1 *)((long)param_1 + 0x52) = 0x62;
  *(undefined1 *)((long)param_1 + 0x53) = 8;
  puVar2 = param_1 + 0x18;
  if ((uVar1 & 0x10) != 0) {
    puVar2 = param_1 + 0x14;
  }
  *(undefined1 *)(param_1 + 0x15) = 0x66;
  *(undefined1 *)((long)param_1 + 0x55) = 0xc;
  *(undefined1 *)((long)param_1 + 0x56) = 0x6e;
  *(undefined1 *)((long)param_1 + 0x57) = 10;
  *(undefined1 *)(param_1 + 0x16) = 0x72;
  *(undefined1 *)((long)param_1 + 0x59) = 0xd;
  *(undefined1 *)((long)param_1 + 0x5a) = 0x74;
  *(undefined1 *)((long)param_1 + 0x5b) = 9;
  *(undefined1 *)(param_1 + 0x17) = 0x76;
  *(undefined1 *)((long)param_1 + 0x5d) = 0xb;
  uVar8 = CONCAT26(DAT_003daf40._6_2_,(undefined6)DAT_003daf40);
  *(undefined8 *)(param_1 + 0x18) = DAT_003daf38;
  *(undefined8 *)(param_1 + 0x1a) = uVar8;
  *(ulong *)((long)param_1 + 0x6e) = CONCAT62(_UNK_003daf48,DAT_003daf40._6_2_);
  *(char **)(param_1 + 0x22) = ".[\\()*+?{|^$";
  *(char **)(param_1 + 0x1e) = "^$\\.*+?()[]{}|";
  *(char **)(param_1 + 0x20) = ".[\\*^$";
  param_1[0x24] = 0;
  param_1[0x25] = uVar1;
  *(uint **)(param_1 + 0x28) = puVar2;
  pcVar4 = "^$\\.*+?()[]{}|";
  if ((((uVar1 & 0x10) == 0) && (pcVar4 = ".[\\*^$", (uVar1 >> 5 & 1) == 0)) &&
     (pcVar4 = ".[\\()*+?{|^$", (uVar1 >> 6 & 1) == 0)) {
    if ((uVar1 >> 8 & 1) != 0) goto LAB_002c6c00;
    if ((uVar1 >> 9 & 1) == 0) {
      pcVar4 = ".[\\()*+?{|^$";
      if ((uVar1 & 0x80) == 0) {
        pcVar4 = (char *)0x0;
      }
    }
    else {
      pcVar4 = ".[\\()*+?{|^$\n";
    }
  }
  while( true ) {
    *(char **)(param_1 + 0x2a) = pcVar4;
    *(undefined1 *)(param_1 + 0x2c) = 0;
    *(undefined8 *)(param_1 + 0x2e) = param_2;
    *(undefined8 *)(param_1 + 0x30) = param_3;
    uVar5 = std::locale::id::_M_id();
    if ((uVar5 < *(ulong *)(local_50 + 0x10)) &&
       (lVar6 = *(long *)(*(long *)(local_50 + 8) + uVar5 * 8), lVar6 != 0)) break;
    std::__throw_bad_cast();
LAB_002c6c00:
    pcVar4 = ".[\\*^$\n";
  }
  *(long *)(param_1 + 0x32) = lVar6;
  *(uint **)(param_1 + 0x34) = param_1 + 0x38;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  *(undefined1 *)(param_1 + 0x38) = 0;
  puVar7 = PTR_FUN_00402748;
  if ((param_1[0x25] >> 4 & 1) != 0) {
    puVar7 = PTR_FUN_00402478;
  }
  *(undefined **)(param_1 + 0x3c) = puVar7;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  FUN_002bfc7c(param_1 + 2);
  std::locale::~locale((locale *)&local_50);
  FUN_002bf9d4(param_1 + 0x40,0,(locale *)&local_50,param_4,param_1);
  *(undefined1 *)(param_1 + 0x48) = 0;
  *(uint **)(param_1 + 0x44) = param_1 + 0x48;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_10 = 0;
  uStack_8 = 0;
  FUN_002bf7bc((locale *)&local_50,0);
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  param_1[0x58] = 0;
  param_1[0x59] = 0;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  FUN_002bf7bc(param_1 + 0x4c,0);
  if (local_50 != 0) {
    FUN_002c0300(param_1 + 0x50,&local_40);
    FUN_002c0300(param_1 + 0x58,&local_20);
    lVar6 = *(long *)(param_1 + 0x4c);
    *(long *)(param_1 + 0x4c) = local_50;
    uVar8 = *(undefined8 *)(param_1 + 0x4e);
    *(undefined8 *)(param_1 + 0x4e) = local_48;
    local_50 = lVar6;
    local_48 = uVar8;
  }
  FUN_002bec70((locale *)&local_50);
  *(long *)(param_1 + 0x60) = *(long *)(param_1 + 0x40) + 0x50;
  pcVar9 = std::use_facet<std::ctype<char>>(param_4);
  *(ctype **)(param_1 + 0x62) = pcVar9;
  local_68 = *(long *)(param_1 + 0x40);
  uStack_60 = *(undefined8 *)(local_68 + 0x20);
  local_58 = uStack_60;
  uVar8 = FUN_002c0794();
  FUN_002beeac(&local_68,uVar8);
  FUN_002c6984(param_1);
  cVar3 = FUN_002bfcc0(param_1,0x1b);
  if (cVar3 == '\0') {
    std::__throw_regex_error(5);
  }
  FUN_002beecc((locale *)&local_50,param_1);
  FUN_002bef6c(&local_68,(locale *)&local_50);
  uVar8 = FUN_002c06d4(*(undefined8 *)(param_1 + 0x40));
  FUN_002beeac(&local_68,uVar8);
  uVar8 = FUN_002c0750(*(undefined8 *)(param_1 + 0x40));
  FUN_002beeac(&local_68,uVar8);
  FUN_002bef90(*(undefined8 *)(param_1 + 0x40));
  return;
}

