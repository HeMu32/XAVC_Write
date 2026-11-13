// XavcsMovieReader::GetEssenceMarks
// Ghidra address: 00213278

/* XavcsMovieReader::GetEssenceMarks(XavcsMovieReader::GetEssenceMarksInParam const&,
   std::vector<mpr::essenceMarkInfo, std::allocator<mpr::essenceMarkInfo> >&) */

undefined8 __thiscall
XavcsMovieReader::GetEssenceMarks
          (XavcsMovieReader *this,GetEssenceMarksInParam *param_1,vector *param_2)

{
  normalLock *this_00;
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined8 *puVar5;
  ulong uVar6;
  ulong uVar7;
  long *plVar8;
  undefined1 *puVar9;
  XavcsMovieReader XVar10;
  uint uVar11;
  undefined1 local_64d;
  int local_64c;
  uint local_648;
  uint local_644;
  undefined4 local_640;
  undefined4 uStack_63c;
  undefined2 local_620;
  undefined2 uStack_61e;
  undefined1 uStack_61c;
  undefined1 uStack_61b;
  undefined1 uStack_61a;
  undefined1 uStack_619;
  undefined4 local_618;
  undefined4 uStack_614;
  char local_459;
  char acStack_458 [1112];
  
  uStack_61c = 4;
  local_620 = 0x2311;
  uStack_61e = 0xe20;
  uStack_61b = 0;
  uStack_61a = 0;
  uStack_619 = 0;
  FUN_0020aff4((recordInfo *)&local_620,8);
  this_00 = (normalLock *)(this + 0x1e28);
  local_64d = 0;
  local_64c = 0;
  FUN_002119a4(*(undefined4 *)(param_1 + 8),&local_64c,&local_64d);
  mpr::thread::normalLock::lock(this_00);
  XVar10 = this[0x1e18];
  if (((XVar10 == (XavcsMovieReader)0x0) || (*(int *)(this + 0x1e1c) != *(int *)param_1)) ||
     (*(int *)(this + 0x1e20) != *(int *)(param_1 + 4))) {
    sidb::recordInfo::clear((recordInfo *)&local_620);
    FUN_0020ae44((string *)&local_640,&DAT_003d7eaf);
    iVar3 = sidb::Select(0xffffffff,*(uint *)param_1,(recordInfo *)&local_620,true);
    if (iVar3 != 0) {
      mpr::thread::normalLock::unlock(this_00);
      std::__cxx11::string::_M_dispose();
      return 4;
    }
    if (local_459 != '\0') {
      std::__cxx11::string::operator=((string *)&local_640,acStack_458);
    }
    XVar10 = (XavcsMovieReader)0x0;
    plVar8 = operator_new(0x30);
    FUN_00352de0();
    FUN_002113c0(CONCAT44(uStack_63c,local_640),plVar8);
    std::__cxx11::string::_M_dispose();
  }
  else {
    plVar8 = *(long **)(this + 0x1e10);
  }
  local_648 = 0;
  FUN_00354f88(plVar8,&local_648);
  uVar7 = (ulong)local_648;
  lVar2 = -(uVar7 * 0x30 + 0x16 & 0x7ffffffff0);
  puVar4 = (undefined4 *)(&stack0xfffffffffffff940 + lVar2);
  for (uVar6 = 0; uVar6 != uVar7; uVar6 = uVar6 + 1) {
    *(undefined1 *)(puVar4 + 8) = 0;
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    *(undefined4 **)(puVar4 + 4) = puVar4 + 8;
    *(undefined8 *)(puVar4 + 6) = 0;
    puVar4 = puVar4 + 0xc;
  }
  FUN_00355004(plVar8,0,uVar7,&stack0xfffffffffffff940 + lVar2,&local_644);
  for (uVar11 = 0; uVar11 < local_644; uVar11 = uVar11 + 1) {
    if (local_64c == 0xe ||
        *(int *)(&stack0xfffffffffffff940 + (ulong)uVar11 * 0x30 + lVar2) == local_64c) {
      ConvEmTypeNrtDef2Mpr
                (*(int *)(&stack0xfffffffffffff940 + (ulong)uVar11 * 0x30 + lVar2),0,&local_640);
      local_620 = (undefined2)local_640;
      uStack_61e = (undefined2)((uint)local_640 >> 0x10);
      uVar1 = *(undefined4 *)(&stack0xfffffffffffff944 + (ulong)uVar11 * 0x30 + lVar2);
      uStack_61c = (undefined1)uVar1;
      uStack_61b = (undefined1)((uint)uVar1 >> 8);
      uStack_61a = (undefined1)((uint)uVar1 >> 0x10);
      uStack_619 = (undefined1)((uint)uVar1 >> 0x18);
      puVar5 = *(undefined8 **)(param_2 + 8);
      if (puVar5 == *(undefined8 **)(param_2 + 0x10)) {
        std::vector<mpr::essenceMarkInfo,std::allocator<mpr::essenceMarkInfo>>::
        _M_emplace_back_aux<mpr::essenceMarkInfo_const&>
                  ((vector<mpr::essenceMarkInfo,std::allocator<mpr::essenceMarkInfo>> *)param_2,
                   (essenceMarkInfo *)&local_620);
      }
      else {
        if (puVar5 != (undefined8 *)0x0) {
          *puVar5 = CONCAT17(uStack_619,
                             CONCAT16(uStack_61a,CONCAT15(uStack_61b,CONCAT14(uStack_61c,local_640))
                                     ));
        }
        *(undefined8 **)(param_2 + 8) = puVar5 + 1;
      }
    }
  }
  if ((plVar8 != (long *)0x0 & ((byte)XVar10 ^ 1)) != 0) {
    (**(code **)(*plVar8 + 8))(plVar8);
  }
  mpr::thread::normalLock::unlock(this_00);
  uStack_61b = 0;
  uStack_61a = 0;
  uStack_619 = 0;
  uStack_61c = 2;
  local_620 = 0x2311;
  uStack_61e = 0xe2f;
  uStack_614 = (undefined4)(*(long *)(param_2 + 8) - *(long *)param_2 >> 3);
  local_618 = 0;
  FUN_0020aff4((recordInfo *)&local_620,0x10);
  for (puVar9 = &stack0xfffffffffffff940 + uVar7 * 0x30 + lVar2;
      puVar9 != &stack0xfffffffffffff940 + lVar2; puVar9 = puVar9 + -0x30) {
    std::__cxx11::string::_M_dispose();
  }
  return 0;
}

