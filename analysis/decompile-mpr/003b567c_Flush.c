// sidb::Flush
// Ghidra address: 003b567c

/* sidb::Flush(unsigned int) */

undefined4 sidb::Flush(uint param_1)

{
  normalLock *pnVar1;
  deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>> *this;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  bool bVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined1 uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  void *pvVar12;
  undefined8 *puVar13;
  void *pvVar14;
  long lVar15;
  ulong uVar16;
  long lVar17;
  undefined4 uVar18;
  ulong uVar19;
  undefined *puVar20;
  _Rb_tree_node_base *p_Var21;
  long lVar22;
  long local_c8;
  undefined1 auStack_90 [32];
  undefined2 local_70;
  undefined2 uStack_6e;
  undefined1 uStack_6c;
  undefined1 uStack_6b;
  undefined1 uStack_6a;
  undefined1 uStack_69;
  uint local_68;
  int iStack_64;
  undefined2 local_50;
  undefined2 local_4e;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  uint local_48;
  void *local_40;
  void *local_38;
  long local_30;
  long local_28;
  void *local_20 [4];
  
  local_4c = 3;
  local_50 = 0x2470;
  local_4e = 0x170;
  local_4b = 0;
  local_4a = 0;
  local_49 = 0;
  local_48 = param_1;
  FUN_003896c0((_Deque_base<sidb::FlushInfo,std::allocator<sidb::FlushInfo>> *)&local_50,0xc);
  puVar6 = PTR_g_msidconv_00402dc8;
  uVar9 = mpr::msidconv::GetSlotID((msidconv *)PTR_g_msidconv_00402dc8,param_1);
  uVar16 = (ulong)uVar9;
  uVar8 = 0;
  if (uVar9 < 4) {
    uVar8 = puVar6[uVar16 * 0x80];
  }
  local_50 = CONCAT11(local_50._1_1_,uVar8);
  FUN_003896b0(auStack_90,(_Deque_base<sidb::FlushInfo,std::allocator<sidb::FlushInfo>> *)&local_50,
               1);
  osal_thread_id();
  lVar22 = *(long *)(PTR_gp_db_004017c8 + uVar16 * 8);
  std::_Deque_base<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::_Deque_base
            ((_Deque_base<sidb::FlushInfo,std::allocator<sidb::FlushInfo>> *)&local_50);
  if (uVar9 == 0xffffffff) {
    uVar18 = 0x403;
  }
  else if (param_1 == *(uint *)PTR_g_pseudoMediaId_00401ef0) {
    uVar18 = 0;
  }
  else {
    uVar18 = 0x409;
    mpr::thread::rwLock::rdlock((rwLock *)PTR_g_rwlock_004023e0);
    if (*(int *)(PTR_g_dbStatus_004029e8 + uVar16 * 4) == 3) {
      uVar18 = 0x408;
      if (PTR_gb_protected_00401e10[uVar16] == '\0') {
        local_c8 = uVar16 << 6;
        pnVar1 = (normalLock *)(PTR_g_flushInfo_deq_lock_00402488 + uVar16 * 0x40);
        mpr::thread::normalLock::lock(pnVar1);
        puVar6 = PTR_g_flushInfo_deq_00402a68;
        puVar20 = PTR_g_flushArea_set_00401ae0 + (ulong)uVar9 * 0x30;
        this = (deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>> *)
               (PTR_g_flushInfo_deq_00402a68 + (ulong)uVar9 * 0x50);
        uVar19 = *(long *)(puVar20 + 0x28) * 0x4000;
        lVar17 = uVar16 * 0x50;
        for (p_Var21 = *(_Rb_tree_node_base **)(puVar20 + 0x18);
            (_Rb_tree_node_base *)(puVar20 + 8) != p_Var21;
            p_Var21 = (_Rb_tree_node_base *)std::_Rb_tree_increment(p_Var21)) {
          if (uVar19 < 0x100001) {
            pvVar12 = malloc(0x4000);
          }
          else {
            pvVar12 = (void *)(lVar22 + ((ulong)*(uint *)(p_Var21 + 0x20) & 0x3ffff) * 0x4000);
          }
          uVar2 = *(uint *)(lVar22 + 0x2c) & 0x3fff;
          uVar4 = *(uint *)(p_Var21 + 0x20) << 0xe;
          if (*(uint *)(p_Var21 + 0x20) != *(uint *)(lVar22 + 0x2c) >> 0xe) {
            uVar2 = 0x4000;
          }
          if (uVar19 < 0x100001) {
            pvVar12 = memcpy(pvVar12,(void *)(lVar22 + (ulong)uVar4),(ulong)uVar2);
          }
          puVar13 = *(undefined8 **)(puVar6 + lVar17 + 0x30);
          if (puVar13 == (undefined8 *)(*(long *)(puVar6 + lVar17 + 0x40) + -0x10)) {
            std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::_M_reserve_map_at_back
                      (this,1);
            lVar15 = *(long *)(puVar6 + lVar17 + 0x48);
            pvVar14 = operator_new(0x200);
            *(void **)(lVar15 + 8) = pvVar14;
            puVar13 = *(undefined8 **)(puVar6 + lVar17 + 0x30);
            if (puVar13 != (undefined8 *)0x0) {
              *(uint *)(puVar13 + 1) = uVar4;
              *(uint *)((long)puVar13 + 0xc) = uVar2;
              *puVar13 = pvVar12;
            }
            puVar7 = PTR_g_flushInfo_deq_00402a68;
            lVar15 = *(long *)(*(long *)(PTR_g_flushInfo_deq_00402a68 + lVar17 + 0x48) + 8);
            *(long *)(this + 0x48) = *(long *)(PTR_g_flushInfo_deq_00402a68 + lVar17 + 0x48) + 8;
            *(long *)(this + 0x38) = lVar15;
            *(long *)(this + 0x40) = lVar15 + 0x200;
            *(long *)(puVar7 + lVar17 + 0x30) = lVar15;
          }
          else {
            if (puVar13 != (undefined8 *)0x0) {
              *puVar13 = pvVar12;
              *(uint *)(puVar13 + 1) = uVar4;
              *(uint *)((long)puVar13 + 0xc) = uVar2;
            }
            *(undefined8 **)(PTR_g_flushInfo_deq_00402a68 + lVar17 + 0x30) = puVar13 + 2;
          }
        }
        FUN_00398a78(puVar20);
        std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::operator=
                  ((deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>> *)&local_50,(deque *)this
                  );
        std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::_Deque_iterator
                  ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)&local_70,
                   (_Deque_iterator *)(PTR_g_flushInfo_deq_00402a68 + (ulong)uVar9 * 0x50 + 0x10));
        std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::_M_erase_at_end
                  (this,(_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)
                        &local_70);
        mpr::thread::normalLock::unlock(pnVar1);
        if (0x100000 < uVar19) goto LAB_003b59f8;
        mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
        bVar5 = false;
        do {
          uVar18 = 0;
          pnVar1 = (normalLock *)(PTR_g_flush_fsys_lock_004015c0 + local_c8);
          mpr::thread::normalLock::lock(pnVar1);
          puVar6 = PTR_g_fsysHandle_00401688;
          while( true ) {
            if (local_20[0] == local_40) {
              iVar11 = Fsys_Flush(*(undefined8 *)(PTR_g_fsysHandle_00401688 + (ulong)uVar9 * 8));
              if (iVar11 != 0) {
                uStack_6b = 0;
                uStack_6c = 2;
                uStack_6a = 0;
                uVar18 = 0x401;
                local_70 = 0x2470;
                uStack_69 = 0;
                uStack_6e = 0x17d;
                local_68 = param_1;
                iStack_64 = iVar11;
                FUN_003896c0((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)
                             &local_70,0x10);
              }
              mpr::thread::normalLock::unlock(pnVar1);
              if (bVar5) goto LAB_003b5b80;
              goto LAB_003b5b8c;
            }
            lVar22 = std::operator-((_Deque_iterator *)local_20,(_Deque_iterator *)&local_40);
            if (lVar22 == 0) break;
            std::_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*>::operator+
                      ((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)
                       &local_40,0);
            puVar13 = (undefined8 *)
                      CONCAT17(uStack_69,
                               CONCAT16(uStack_6a,
                                        CONCAT15(uStack_6b,
                                                 CONCAT14(uStack_6c,CONCAT22(uStack_6e,local_70)))))
            ;
            uVar3 = *(undefined4 *)(puVar13 + 1);
            iVar11 = *(int *)((long)puVar13 + 0xc);
            pvVar12 = (void *)*puVar13;
            if (local_40 == (void *)(local_30 + -0x10)) {
              local_c8 = CONCAT44(local_c8._4_4_,uVar3);
              operator_delete(local_38);
              local_40 = *(void **)(local_28 + 8);
              local_30 = (long)local_40 + 0x200;
              local_38 = local_40;
              local_28 = local_28 + 8;
            }
            else {
              local_40 = (void *)((long)local_40 + 0x10);
            }
            iVar10 = Fsys_Seek(*(undefined8 *)(puVar6 + (ulong)uVar9 * 8),uVar3,0,0);
            if (iVar10 != 0) {
              uStack_6b = 0;
              uStack_6c = 2;
              uStack_6a = 0;
              uVar18 = 0x401;
              local_70 = 0x2470;
              uStack_69 = 0;
              uStack_6e = 0x17b;
              local_68 = param_1;
              iStack_64 = iVar10;
              FUN_003896c0((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)
                           &local_70,0x10);
            }
            iVar10 = Fsys_Write(*(undefined8 *)(PTR_g_fsysHandle_00401688 + (ulong)uVar9 * 8),
                                pvVar12,iVar11);
            if (iVar10 != iVar11) {
              uStack_6b = 0;
              uStack_6c = 2;
              uStack_6a = 0;
              uVar18 = 0x401;
              local_70 = 0x2470;
              uStack_69 = 0;
              uStack_6e = 0x17c;
              local_68 = param_1;
              iStack_64 = iVar10;
              FUN_003896c0((_Deque_iterator<sidb::FlushInfo,sidb::FlushInfo&,sidb::FlushInfo*> *)
                           &local_70,0x10);
            }
            if (uVar19 < 0x100001) {
              free(pvVar12);
            }
          }
          std::__throw_out_of_range_fmt
                    ("deque::_M_range_check: __n (which is %zu)>= this->size() (which is %zu)",0,0);
LAB_003b59f8:
          bVar5 = true;
        } while( true );
      }
    }
LAB_003b5b80:
    mpr::thread::rwLock::unlock((rwLock *)PTR_g_rwlock_004023e0);
  }
LAB_003b5b8c:
  uStack_6c = 3;
  uStack_6b = 0;
  local_70 = 0x2470;
  uStack_6a = 0;
  uStack_6e = 399;
  uStack_69 = 0;
  local_68 = uVar18;
  FUN_003896c0(&local_70,0xc);
  std::deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>>::~deque
            ((deque<sidb::FlushInfo,std::allocator<sidb::FlushInfo>> *)&local_50);
  std::__cxx11::string::_M_dispose();
  return uVar18;
}

