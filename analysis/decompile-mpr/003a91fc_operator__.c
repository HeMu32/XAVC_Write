// sidb::SortCompFunc<bool>::operator()
// Ghidra address: 003a91fc

/* sidb::SortCompFunc<bool>::TEMPNAMEPLACEHOLDERVALUE(unsigned int, unsigned int) */

undefined1 __thiscall
sidb::SortCompFunc<bool>::operator()(SortCompFunc<bool> *this,uint param_1,uint param_2)

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
  char cVar9;
  long lVar10;
  long lVar11;
  byte local_39;
  bool local_38;
  char local_37;
  uint local_30 [6];
  long local_18;
  undefined8 local_10;
  uint local_8;
  uint uStack_4;
  
  local_39 = 0;
  lVar10 = 0;
  local_30[0] = param_1;
  local_30[1] = param_2;
  do {
    uVar1 = *(uint *)((long)local_30 + lVar10);
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
    *(uint *)((long)local_30 + lVar10 + 0x10) = uVar1 & 0x1ffff;
    *(undefined4 *)((long)local_30 + lVar10 + 8) = uVar8;
    lVar10 = lVar10 + 4;
  } while (lVar10 != 8);
  lVar10 = 0;
  if (0x61 < *(int *)this) {
    do {
      uVar1 = local_30[lVar10 + 4];
      lVar11 = *(long *)(puVar4 + (ulong)local_30[lVar10 + 2] * 8);
      cVar5 = headerStructure::IsTrueBitmap
                        (*(headerStructure **)(puVar3 + (ulong)local_30[lVar10 + 2] * 8),uVar1);
      if (cVar5 == '\0') {
        return 0;
      }
      iVar7 = onMemoryColumnWithFunc<bool>::GetValue
                        ((onMemoryColumnWithFunc<bool> *)(lVar11 + (ulong)uVar1 * 4),
                         *(undefined4 *)this,&local_38 + lVar10);
      if (iVar7 != 0) {
        return 0;
      }
      lVar10 = lVar10 + 1;
      cVar5 = local_37;
      cVar9 = local_38;
    } while (lVar10 != 2);
    goto LAB_003a9438;
  }
  do {
    uVar1 = local_30[lVar10 + 4];
    this_00 = *(headerStructure **)(puVar3 + (ulong)local_30[lVar10 + 2] * 8);
    iVar7 = *(int *)(this_00 + 0x30);
    (&local_10)[lVar10] =
         (recordStructureWithFunc<bool> *)(this_00 + (ulong)(uVar1 * iVar7) + 0x10000);
    cVar5 = headerStructure::IsTrueBitmap(this_00,uVar1);
    if ((cVar5 == '\0') ||
       (iVar7 = recordStructureWithFunc<bool>::GetValue
                          ((recordStructureWithFunc<bool> *)
                           (this_00 + (ulong)(uVar1 * iVar7) + 0x10000),*(undefined4 *)this,uVar1,
                           &local_38 + lVar10), iVar7 != 0)) {
      return 0;
    }
    lVar10 = lVar10 + 1;
  } while (lVar10 != 2);
  if (*(int *)this == 4) {
    FUN_0038a448(local_38,(long)((ulong)*(byte *)(CONCAT17(local_10._7_1_,
                                                           CONCAT16(local_10._6_1_,
                                                                    CONCAT15(local_10._5_1_,
                                                                             CONCAT14(local_10._4_1_
                                                                                      ,CONCAT22(
                                                  local_10._2_2_,(undefined2)local_10))))) + 0x10)
                                << 0x38) >> 0x39,&local_18);
    bVar2 = *(byte *)(CONCAT44(uStack_4,local_8) + 0x10);
LAB_003a937c:
    local_38 = local_18 != 0;
    FUN_0038a448(local_37,(long)((ulong)bVar2 << 0x38) >> 0x39,&local_18);
    local_37 = local_18 != 0;
  }
  else if (*(int *)this == 0x1a) {
    FUN_0038a448(local_38,(long)((ulong)*(byte *)(CONCAT17(local_10._7_1_,
                                                           CONCAT16(local_10._6_1_,
                                                                    CONCAT15(local_10._5_1_,
                                                                             CONCAT14(local_10._4_1_
                                                                                      ,CONCAT22(
                                                  local_10._2_2_,(undefined2)local_10))))) + 0x18)
                                << 0x38) >> 0x39,&local_18);
    bVar2 = *(byte *)(CONCAT44(uStack_4,local_8) + 0x18);
    goto LAB_003a937c;
  }
  iVar7 = *(int *)this;
  cVar5 = local_37;
  cVar9 = local_38;
  if ((1 < iVar7 - 3U && (iVar7 != 0x19 && iVar7 != 0x1a)) || (local_38 != (bool)local_37))
  goto LAB_003a9438;
  lVar10 = CONCAT17(local_10._7_1_,
                    CONCAT16(local_10._6_1_,
                             CONCAT15(local_10._5_1_,
                                      CONCAT14(local_10._4_1_,
                                               CONCAT22(local_10._2_2_,(undefined2)local_10)))));
  lVar11 = CONCAT44(uStack_4,local_8);
  if (((*(byte *)(lVar10 + 7) ^ *(byte *)(lVar11 + 7)) & 0xf) == 0) {
    if (((*(byte *)(lVar10 + 0xe) & 3) * 0x4000 + (uint)(*(ushort *)(lVar10 + 0xe) >> 2) |
        (uint)(*(ushort *)(lVar10 + 0xc) >> 6) << 0x10) <
        ((*(byte *)(lVar11 + 0xe) & 3) * 0x4000 + (uint)(*(ushort *)(lVar11 + 0xe) >> 2) |
        (uint)(*(ushort *)(lVar11 + 0xc) >> 6) << 0x10)) {
LAB_003a9430:
      cVar5 = '\x01';
      cVar9 = '\0';
      goto LAB_003a9438;
    }
  }
  else if ((*(byte *)(lVar10 + 7) & 0xf) != 1) goto LAB_003a9430;
  cVar5 = '\0';
  cVar9 = '\x01';
LAB_003a9438:
  uVar6 = FUN_003a91c8(this + 8,cVar9,cVar5);
  return uVar6;
}

