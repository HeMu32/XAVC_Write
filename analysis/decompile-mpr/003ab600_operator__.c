// sidb::SortCompFunc<unsigned_int>::operator()
// Ghidra address: 003ab600

/* sidb::SortCompFunc<unsigned int>::TEMPNAMEPLACEHOLDERVALUE(unsigned int, unsigned int) */

undefined1 __thiscall
sidb::SortCompFunc<unsigned_int>::operator()
          (SortCompFunc<unsigned_int> *this,uint param_1,uint param_2)

{
  uint uVar1;
  byte bVar2;
  undefined *puVar3;
  undefined *puVar4;
  char cVar5;
  undefined1 uVar6;
  int iVar7;
  undefined4 uVar8;
  headerStructure *this_00;
  ulong uVar9;
  int iVar10;
  int iVar11;
  long lVar12;
  long lVar13;
  byte local_39;
  uint local_38 [6];
  int local_20 [4];
  undefined8 local_10;
  uint local_8;
  uint uStack_4;
  
  lVar12 = 0;
  local_39 = 0;
  local_38[0] = param_1;
  local_38[1] = param_2;
  do {
    uVar1 = *(uint *)((long)local_38 + lVar12);
    iVar7 = GetDriveLetterFromUniqueId(uVar1,(char *)&local_39);
    if (iVar7 != 0) {
      local_10._5_1_ = 0;
      local_10._4_1_ = 2;
      local_10._6_1_ = 0;
      local_10._0_2_ = 0x2470;
      local_10._7_1_ = 0;
      local_10._2_2_ = 0xdc01;
      uStack_4 = (uint)local_39;
      local_8 = uVar1;
      FUN_003896c0(&local_10,0x10);
      return 0;
    }
    uVar8 = mpr::msidconv::GetSlotIDFromDriveLetter((msidconv *)PTR_g_msidconv_00402dc8,local_39);
    puVar4 = PTR_gp_onmem_00401cf8;
    puVar3 = PTR_gp_db_004017c8;
    *(uint *)((long)local_38 + lVar12 + 0x10) = uVar1 & 0x1ffff;
    *(undefined4 *)((long)local_38 + lVar12 + 8) = uVar8;
    lVar12 = lVar12 + 4;
  } while (lVar12 != 8);
  iVar7 = *(int *)this;
  lVar12 = 0;
  if (0x61 < iVar7) {
    do {
      uVar9 = (ulong)*(uint *)((long)local_38 + lVar12 + 8);
      uVar1 = *(uint *)((long)local_38 + lVar12 + 0x10);
      lVar13 = *(long *)(puVar4 + uVar9 * 8);
      cVar5 = headerStructure::IsTrueBitmap(*(headerStructure **)(puVar3 + uVar9 * 8),uVar1);
      if (cVar5 == '\0') {
        return 0;
      }
      if (iVar7 != 99) {
        return 0;
      }
      *(undefined4 *)((long)local_20 + lVar12) = *(undefined4 *)(lVar13 + (ulong)uVar1 * 4);
      lVar12 = lVar12 + 4;
      iVar10 = local_20[0];
      iVar11 = local_20[1];
    } while (lVar12 != 8);
    goto LAB_003ab814;
  }
  do {
    uVar1 = *(uint *)((long)local_38 + lVar12 + 0x10);
    this_00 = *(headerStructure **)(puVar3 + (ulong)*(uint *)((long)local_38 + lVar12 + 8) * 8);
    iVar7 = *(int *)(this_00 + 0x30);
    *(recordStructureWithFunc<unsigned_int> **)((long)&local_10 + lVar12 * 2) =
         (recordStructureWithFunc<unsigned_int> *)(this_00 + (ulong)(uVar1 * iVar7) + 0x10000);
    cVar5 = headerStructure::IsTrueBitmap(this_00,uVar1);
    if (cVar5 == '\0') {
      return 0;
    }
    iVar7 = recordStructureWithFunc<unsigned_int>::GetValue
                      ((recordStructureWithFunc<unsigned_int> *)
                       (this_00 + (ulong)(uVar1 * iVar7) + 0x10000),*(undefined4 *)this,uVar1,
                       (long)local_20 + lVar12);
    if (iVar7 != 0) {
      return 0;
    }
    lVar12 = lVar12 + 4;
  } while (lVar12 != 8);
  if (*(int *)this == 4) {
    FUN_0038a448(local_20[0],
                 (long)((ulong)*(byte *)(CONCAT17(local_10._7_1_,
                                                  CONCAT16(local_10._6_1_,
                                                           CONCAT15(local_10._5_1_,
                                                                    CONCAT14(local_10._4_1_,
                                                                             CONCAT22(local_10._2_2_
                                                                                      ,(undefined2)
                                                                                       local_10)))))
                                        + 0x10) << 0x38) >> 0x39,local_20 + 2);
    bVar2 = *(byte *)(CONCAT44(uStack_4,local_8) + 0x10);
LAB_003ab764:
    local_20[0] = local_20[2];
    FUN_0038a448(local_20[1],(long)((ulong)bVar2 << 0x38) >> 0x39,local_20 + 2);
    local_20[1] = local_20[2];
  }
  else if (*(int *)this == 0x1a) {
    FUN_0038a448(local_20[0],
                 (long)((ulong)*(byte *)(CONCAT17(local_10._7_1_,
                                                  CONCAT16(local_10._6_1_,
                                                           CONCAT15(local_10._5_1_,
                                                                    CONCAT14(local_10._4_1_,
                                                                             CONCAT22(local_10._2_2_
                                                                                      ,(undefined2)
                                                                                       local_10)))))
                                        + 0x18) << 0x38) >> 0x39,local_20 + 2);
    bVar2 = *(byte *)(CONCAT44(uStack_4,local_8) + 0x18);
    goto LAB_003ab764;
  }
  iVar7 = *(int *)this;
  iVar10 = local_20[0];
  iVar11 = local_20[1];
  if ((1 < iVar7 - 3U && (iVar7 != 0x19 && iVar7 != 0x1a)) || (local_20[0] != local_20[1]))
  goto LAB_003ab814;
  lVar12 = CONCAT17(local_10._7_1_,
                    CONCAT16(local_10._6_1_,
                             CONCAT15(local_10._5_1_,
                                      CONCAT14(local_10._4_1_,
                                               CONCAT22(local_10._2_2_,(undefined2)local_10)))));
  lVar13 = CONCAT44(uStack_4,local_8);
  if (((*(byte *)(lVar12 + 7) ^ *(byte *)(lVar13 + 7)) & 0xf) == 0) {
    if (((*(byte *)(lVar12 + 0xe) & 3) * 0x4000 + (uint)(*(ushort *)(lVar12 + 0xe) >> 2) |
        (uint)(*(ushort *)(lVar12 + 0xc) >> 6) << 0x10) <
        ((*(byte *)(lVar13 + 0xe) & 3) * 0x4000 + (uint)(*(ushort *)(lVar13 + 0xe) >> 2) |
        (uint)(*(ushort *)(lVar13 + 0xc) >> 6) << 0x10)) {
LAB_003ab80c:
      iVar10 = 0;
      iVar11 = 1;
      goto LAB_003ab814;
    }
  }
  else if ((*(byte *)(lVar12 + 7) & 0xf) != 1) goto LAB_003ab80c;
  iVar10 = 1;
  iVar11 = 0;
LAB_003ab814:
  uVar6 = FUN_003ab5d0(this + 8,iVar10,iVar11);
  return uVar6;
}

