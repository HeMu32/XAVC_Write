// FUN_002166d8
// Ghidra address: 002166d8

void FUN_002166d8(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  void *pvVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  signalLock *this;
  undefined8 uVar11;
  undefined8 local_168;
  uint local_160;
  int local_15c;
  int local_158;
  uint local_154;
  undefined8 local_150;
  undefined8 local_148;
  undefined4 local_140;
  uint3 local_13c;
  undefined1 uStack_139;
  undefined4 local_138;
  undefined4 local_134;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined4 local_120;
  int local_11c;
  uint local_118;
  int local_114;
  int local_110;
  uint local_10c;
  undefined2 local_108;
  undefined2 local_106;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  undefined1 local_101;
  
  local_104 = 4;
  local_106 = 0x1900;
  local_103 = 0;
  local_102 = 0;
  local_101 = 0;
  local_108 = 0x2311;
  FUN_0020aff4(&local_108,8);
  uVar11 = *(undefined8 *)(param_1 + 0x10);
  memcpy(&local_108,*(void **)(param_1 + 0x18),0x106);
  uVar10 = *(undefined8 *)(param_1 + 0x20);
  lVar1 = *(long *)(param_1 + 0x30);
  uVar2 = *(undefined8 *)(param_1 + 0x38);
  this = *(signalLock **)(param_1 + 0x40);
  puVar9 = *(undefined8 **)(param_1 + 0x50);
  uVar5 = FUN_0032a774(uVar11,0x20000);
  if (uVar5 == 0) {
    uVar5 = FUN_0032af44(uVar11,&local_108,1,&local_168);
    if (uVar5 != 0) {
      uVar4 = 0x1902;
      goto LAB_002167a0;
    }
    local_168 = 0;
    uVar5 = FUN_0032a380(uVar10,uVar11,1,0,&local_168);
    if (uVar5 != 0) {
      uVar4 = 0x1903;
      goto LAB_002167a0;
    }
    uVar5 = 0;
    if (*(char *)(lVar1 + 0x344) != '\0') {
      uVar6 = FUN_003292c8(uVar10,*(undefined4 *)(lVar1 + 0x340));
      uVar5 = 0;
      if (uVar6 != 0) {
        uVar4 = 0x1905;
        uVar5 = uVar6;
        goto LAB_002167a0;
      }
    }
  }
  else {
    uVar4 = 0x1901;
LAB_002167a0:
    local_150 = CONCAT44(3,CONCAT22(uVar4,0x2311));
    local_148 = CONCAT44(local_148._4_4_,uVar5);
    FUN_0020aff4(&local_150,0xc);
    FUN_001fe0e8(*(undefined8 *)(lVar1 + 0x338),uVar5);
  }
  local_150 = 0x319062311;
  local_148 = local_148 & 0xffffffff00000000;
  FUN_0020aff4(&local_150,0xc);
  if (uVar5 == 0) {
    local_140 = 0xff;
    _local_13c = 3;
    local_130 = 0x300000000;
    local_138 = 1;
    uStack_128 = 0x64014d4015;
    local_110 = 1;
    local_10c = 1;
    local_150 = 0;
    local_148 = 0;
    local_134 = 0;
    local_120 = 0;
    local_11c = 0;
    local_118 = 0;
    local_114 = 0;
    uVar5 = FUN_00328fa8(uVar10,&local_150);
    if (uVar5 != 0) {
      local_168 = 0x319082311;
      local_160 = uVar5;
      FUN_0020aff4(&local_168,0xc);
      FUN_001fe0e8(*(undefined8 *)(lVar1 + 0x338),uVar5);
    }
    if ((((1 < local_118 || local_110 != 1) || (local_11c != 0 || (local_10c & 0xff) != 1)) &&
        ((local_118 != 1 || local_110 != 2 || (local_11c != 0 || (local_10c & 0xff) != 4)))) ||
       (local_114 != 0)) {
      local_158 = local_110;
      local_154 = local_118;
      local_160 = local_114;
      local_15c = local_11c;
      local_168 = 0x119092311;
      FUN_0020aff4(&local_168,0x18);
      uVar5 = 2;
      local_160 = local_10c;
      local_168 = 0x319102311;
      FUN_0020aff4(&local_168,0xc);
      FUN_001fe0e8(*(undefined8 *)(lVar1 + 0x338),2);
    }
    local_160 = local_114;
    local_168 = 0x119112311;
    local_15c = local_11c;
    local_158 = local_110;
    local_154 = local_118;
    FUN_0020aff4(&local_168,0x18);
    local_168 = 0x319122311;
    local_160 = local_10c;
    FUN_0020aff4(&local_168,0xc);
  }
  local_150 = 0x319072311;
  local_148 = local_148 & 0xffffffff00000000;
  FUN_0020aff4(&local_150,0xc);
  if (uVar5 != 0) goto LAB_00216a50;
  local_148 = *(ulong *)(lVar1 + 0x328);
  local_140 = *(undefined4 *)(lVar1 + 0x330);
  local_150 = *(undefined8 *)(lVar1 + 800);
  local_13c = (uint3)*(ushort *)(lVar1 + 0x334);
  uVar5 = FUN_00327714(uVar10,&local_150);
  if (uVar5 != 0) {
    printf("[XavcMovieReader][ID:%x][%s] %s(%d) : err(0x%x)",0,"xavcsMovieReader.cpp","_open_file",
           0x1977,(ulong)uVar5);
    if (uVar5 != 4) {
                    /* WARNING: Subroutine does not return */
      abort();
    }
    local_168 = 0x319042311;
    local_160 = uVar5;
    FUN_0020aff4(&local_168,0xc);
    FUN_001fe0e8(*(undefined8 *)(lVar1 + 0x338),4);
    goto LAB_00216a50;
  }
  mpr::thread::normalLock::lock((normalLock *)(puVar9 + 3));
  FUN_0020b138(puVar9);
  pvVar8 = operator_new(0x30);
  FUN_00352de0();
  *(undefined4 *)((long)puVar9 + 0xc) = *(undefined4 *)(lVar1 + 0x314);
  uVar3 = *(undefined4 *)(lVar1 + 0x318);
  *puVar9 = pvVar8;
  *(undefined4 *)(puVar9 + 2) = uVar3;
  iVar7 = FUN_002113c0(lVar1 + 0x20d);
  if (iVar7 == 0) {
LAB_00216cc0:
    *(undefined1 *)(puVar9 + 1) = 1;
  }
  else {
    FUN_0020b138(puVar9);
    pvVar8 = operator_new(0x30);
    FUN_00352de0();
    *(undefined4 *)((long)puVar9 + 0xc) = *(undefined4 *)(lVar1 + 0x314);
    uVar3 = *(undefined4 *)(lVar1 + 0x318);
    *puVar9 = pvVar8;
    *(undefined4 *)(puVar9 + 2) = uVar3;
    iVar7 = FUN_0021654c(lVar1);
    if (iVar7 == 0) goto LAB_00216cc0;
    local_148 = CONCAT44(0x1994,iVar7);
    local_150 = 0x203232311;
    FUN_0020aff4(&local_150,0x10);
    FUN_0020b138(puVar9);
  }
  mpr::thread::normalLock::unlock((normalLock *)(puVar9 + 3));
LAB_00216a50:
  FUN_00210ee8(uVar10,*(undefined8 *)(param_1 + 0x48));
  mpr::thread::signalLock::lock(this);
  local_168 = CONCAT44(uVar5,0x40000003);
  FUN_00212de8(uVar2,&local_168);
  mpr::thread::signalLock::signal(this);
  mpr::thread::signalLock::unlock(this);
  local_148 = CONCAT44(local_148._4_4_,uVar5);
  local_150 = 0x3190f2311;
  FUN_0020aff4(&local_150,0xc);
  return;
}

