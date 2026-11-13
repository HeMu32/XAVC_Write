// FUN_00214ac0
// Ghidra address: 00214ac0

void FUN_00214ac0(long param_1)

{
  undefined8 *puVar1;
  signalLock *this;
  uint uVar2;
  undefined1 uVar3;
  __useconds_t _Var4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined8 *puVar12;
  void *pvVar13;
  uint *puVar14;
  undefined8 *puVar15;
  RingBuffer *this_00;
  byte bVar16;
  int iVar17;
  byte bVar18;
  byte local_ff;
  char local_fe;
  char local_fd;
  undefined4 local_fc;
  undefined2 local_f8;
  undefined2 local_f6;
  undefined1 local_f4;
  undefined1 local_f3;
  undefined1 local_f2;
  undefined1 local_f1;
  uint local_f0;
  uint local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  short local_88 [2];
  undefined1 local_84;
  undefined1 local_83;
  undefined1 local_82;
  undefined1 local_81;
  
  local_84 = 4;
  local_88[0] = 0x2311;
  local_83 = 0;
  local_82 = 0;
  local_81 = 0;
  local_88[1] = 0;
  FUN_0020aff4(local_88,8);
  local_ff = 0;
  local_fe = '\0';
  local_fd = '\0';
  local_c0 = 0;
  uStack_b8 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_a0 = 0;
  local_98 = (undefined8 *)0x0;
  local_fc = 0;
  local_90 = 0;
  puVar12 = operator_new__(0xbd8);
  *puVar12 = 2;
  puVar15 = puVar12 + 1;
  do {
    *(undefined1 *)(puVar15 + 0xb7) = 0;
    puVar15[0x8b] = puVar15 + 0x8d;
    puVar15[0xb5] = puVar15 + 0xb7;
    puVar15[0xb9] = puVar15 + 0xbb;
    *(undefined1 *)(puVar15 + 0xbb) = 0;
    puVar15[0xb6] = 0;
    puVar15[0xba] = 0;
    *(undefined1 *)(puVar15 + 4) = 0;
    *(undefined1 *)(puVar15 + 0x8d) = 0;
    *(undefined4 *)((long)puVar15 + 0x24) = 0;
    *(undefined4 *)(puVar15 + 5) = 2;
    *(undefined4 *)((long)puVar15 + 0x3c) = 0;
    *(undefined4 *)(puVar15 + 8) = 0;
    *(undefined4 *)((long)puVar15 + 0x44) = 0;
    *(undefined4 *)(puVar15 + 9) = 0;
    puVar15[0x8c] = 0;
    puVar1 = puVar15 + 0xbd;
    FUN_001b45a4(puVar15);
    puVar15 = puVar1;
  } while (puVar1 != puVar12 + 0x17b);
  bVar6 = false;
  local_98 = puVar12 + 1;
  pvVar13 = operator_new(0x68);
  FUN_0032a730();
  bVar16 = 0;
  iVar17 = 0;
  bVar5 = false;
  memset(local_88,0,0x88);
  uVar3 = 0;
  local_e0 = DAT_003d6180;
  uStack_d8 = DAT_003d6188;
  local_d0 = DAT_003d6190;
  uStack_c8 = DAT_003d6198;
  bVar18 = 0;
LAB_00214c10:
  this = (signalLock *)(param_1 + 0x78);
  if (bVar5) {
    mpr::thread::signalLock::lock(this);
    puVar14 = *(uint **)(param_1 + 0x38);
    if (puVar14 == *(uint **)(param_1 + 0x58)) {
      if (bVar18 == 0) {
        pthread_cond_wait((pthread_cond_t *)(param_1 + 0xb0),(pthread_mutex_t *)(param_1 + 0x80));
        goto LAB_00214f44;
      }
      bVar18 = 0;
      uVar9 = 0x10000006;
    }
    else {
      uVar9 = *puVar14;
      uVar2 = puVar14[1];
      FUN_00212bfc(param_1 + 0x28);
      if (uVar2 != 0) {
        local_f3 = 0;
        local_f4 = 2;
        local_f2 = 0;
        local_f8 = 0x2311;
        local_f1 = 0;
        local_f6 = 0xee02;
        local_f0 = uVar9;
        local_ec = uVar2;
        FUN_0020aff4(&local_f8,0x10);
LAB_00214f44:
        mpr::thread::signalLock::unlock(this);
        goto LAB_00214c10;
      }
    }
    mpr::thread::signalLock::unlock(this);
    if (uVar9 != 0x10000006) {
      if (uVar9 < 0x10000007) {
        if (uVar9 == 0x10000000) {
          FUN_00210c78(param_1,pvVar13,&local_e0,1);
          FUN_002111cc(param_1,pvVar13,&local_e0,param_1 + 0x1dcc);
        }
        else if (uVar9 == 0x10000001) {
LAB_00214fac:
          FUN_00210c78(param_1,pvVar13,&local_e0,1);
          goto LAB_00214ed4;
        }
        goto LAB_00214c10;
      }
      if (uVar9 == 0x1000000d) {
        FUN_00212630(param_1,param_1 + 0x498,1);
        goto LAB_00214c10;
      }
      if (uVar9 != 0x40000004) {
        if (uVar9 == 0x10000007) {
          FUN_00211a40(param_1,param_1 + 0x488,1);
        }
        goto LAB_00214c10;
      }
      mpr::BaseList::Add(*(BaseList **)(param_1 + 0x1d18),
                         (void *)(param_1 + (ulong)*(uint *)(param_1 + 0x1d10) * 0x138 + 0x4b0),
                         0x138);
      *(uint *)(param_1 + 0x1d10) = (*(int *)(param_1 + 0x1d10) + 1U) % 0x14;
      if (local_fe == '\0') {
        uVar10 = mpr::RingBuffer::GetUsedSize(*(RingBuffer **)(param_1 + 0x1d98));
        FUN_00210abc(param_1,&local_d0,uVar10);
        bVar6 = false;
      }
      else {
        bVar6 = false;
        FUN_00210abc(param_1,&local_e0,0xffffffff);
        FUN_00210abc(param_1,&local_d0,0xffffffff);
      }
    }
    uVar9 = Fsys_GetDriveInfo(uVar3,local_88);
    if ((uVar9 != 0) || (local_88[0] == 0x40)) {
      local_f3 = 0;
      local_f4 = 3;
      local_f2 = 0;
      local_f8 = 0x2311;
      local_f1 = 0;
      local_f6 = 2;
      local_f0 = uVar9;
      FUN_0020aff4(&local_f8,0xc);
      FUN_001fe0e8(*(undefined8 *)(param_1 + 0x440),0xb);
    }
    if (((local_fe == '\0') &&
        (uVar9 = mpr::RingBuffer::GetUsedSize(*(RingBuffer **)(param_1 + 0x1d98)),
        uVar9 < *(uint *)(param_1 + 0x1dc8))) &&
       (uVar9 = mpr::BaseList::GetNum(*(BaseList **)(param_1 + 0x1d18)), !bVar6 && uVar9 < 0x14)) {
      bVar6 = true;
      FUN_0020c154(param_1,*(undefined8 *)((long)pvVar13 + 0x10),&local_fe);
    }
    if (local_fe == '\0') {
      uVar10 = mpr::Codec::GetDecVideoInfoBordedNum();
      FUN_00210abc(param_1,&local_e0,uVar10);
    }
    uVar9 = FUN_00214894(param_1,iVar17,&local_c0,&local_fc,&local_fd,&local_ff);
    bVar7 = local_ff;
    if (bVar16 == 0) {
      if (local_ff == 0) {
        _Var4 = 100000;
        if (bVar6) {
          _Var4 = 0;
        }
        usleep(_Var4);
        bVar18 = 1;
        goto LAB_00214c10;
      }
      if (uVar9 != 0) {
        local_f4 = 3;
        local_f8 = 0x2311;
        local_f3 = 0;
        local_f6 = 3;
        local_f2 = 0;
        local_f1 = 0;
        local_f0 = uVar9;
        FUN_0020aff4(&local_f8,0xc);
        FUN_001fe0e8(*(undefined8 *)(param_1 + 0x440),uVar9);
        goto LAB_00214c10;
      }
      bVar8 = FUN_0021358c(param_1,&local_c0);
      local_ff = bVar8;
      if (bVar8 == 0) {
        _Var4 = 100000;
        if (bVar6) {
          _Var4 = 0;
        }
        usleep(_Var4);
        bVar18 = bVar7;
        goto LAB_00214c10;
      }
      local_90 = *(undefined8 *)(param_1 + 0x460);
      uVar10 = FUN_00213ee8(param_1,&local_c0,local_fd);
      if (local_fe == '\0') {
        uVar11 = mpr::Codec::GetDecVideoInfoBordedNum();
        FUN_00210abc(param_1,&local_e0,uVar11);
        uVar11 = mpr::RingBuffer::GetUsedSize(*(RingBuffer **)(param_1 + 0x1d98));
        FUN_00210abc(param_1,&local_d0,uVar11);
      }
      if ((iVar17 != 0) && (*(long *)(param_1 + 0x18) != 0)) {
        local_f3 = 0;
        local_f4 = 4;
        local_f2 = 0;
        local_f8 = 0x2311;
        local_f1 = 0;
        local_f6 = 4;
        FUN_0020aff4(&local_f8,8);
        (**(code **)(param_1 + 0x18))(0x20000000,uVar10,0,0,*(undefined8 *)(param_1 + 0x20));
      }
      FUN_0020c330(param_1);
      if (local_fd != '\0') {
        iVar17 = 0;
        FUN_00210dec(param_1,pvVar13,&local_e0);
        goto LAB_00214ed4;
      }
      _Var4 = 100000;
      if (bVar6) {
        _Var4 = 0;
      }
      usleep(_Var4);
      iVar17 = 0;
    }
    else {
      _Var4 = 100000;
      if (bVar6) {
        _Var4 = 0;
      }
      usleep(_Var4);
      bVar8 = bVar16;
    }
    bVar16 = 0;
    bVar18 = bVar8;
    goto LAB_00214c10;
  }
  mpr::thread::signalLock::lock(this);
  puVar14 = *(uint **)(param_1 + 0x38);
  if (puVar14 == *(uint **)(param_1 + 0x58)) {
    pthread_cond_wait((pthread_cond_t *)(param_1 + 0xb0),(pthread_mutex_t *)(param_1 + 0x80));
LAB_00214c7c:
    mpr::thread::signalLock::unlock(this);
  }
  else {
    uVar9 = *puVar14;
    uVar2 = puVar14[1];
    FUN_00212bfc(param_1 + 0x28);
    if (uVar2 != 0) {
      local_f3 = 0;
      local_f4 = 2;
      local_f2 = 0;
      local_f8 = 0x2311;
      local_f1 = 0;
      local_f6 = 0xee01;
      local_f0 = uVar9;
      local_ec = uVar2;
      FUN_0020aff4(&local_f8,0x10);
      goto LAB_00214c7c;
    }
    mpr::thread::signalLock::unlock(this);
    if (uVar9 == 0x1000000d) {
      FUN_00212630(param_1,param_1 + 0x498,0);
      goto LAB_00214ed4;
    }
    if (0x1000000d < uVar9) {
      if ((uVar9 == 0x40000005) || (uVar9 == 0x40000009)) {
        this_00 = *(RingBuffer **)(param_1 + 0x1d98);
        if (this_00 != (RingBuffer *)0x0) {
          mpr::RingBuffer::~RingBuffer(this_00);
          operator_delete(this_00,0x48);
          *(undefined8 *)(param_1 + 0x1d98) = 0;
        }
        FUN_0020643c(*(undefined8 *)(param_1 + 0x100),*(undefined8 *)(param_1 + 0x1db8),1,
                     *(undefined8 *)(param_1 + 0x468));
        FUN_00206388(*(undefined8 *)(param_1 + 0x100));
        *(undefined8 *)(param_1 + 0x1db8) = 0;
        *(undefined4 *)(param_1 + 0x1dc0) = 0;
        local_f4 = 1;
        local_f3 = 0;
        local_f6 = 0xdd58;
        local_f0 = *(uint *)(param_1 + 0x1df0);
        local_f2 = 0;
        local_ec = *(uint *)(param_1 + 0x1df4);
        local_f1 = 0;
        local_e8 = *(undefined4 *)(param_1 + 0x1e00);
        local_f8 = 0x2311;
        local_e4 = *(undefined4 *)(param_1 + 0x1e04);
        FUN_0020aff4(&local_f8,0x18);
        FUN_00210abc(param_1,&local_d0,0xffffffff);
        if ((uVar9 == 0x40000005) && (*(long *)(param_1 + 0x18) != 0)) {
          local_f3 = 0;
          local_f4 = 4;
          local_f2 = 0;
          local_f6 = 1;
          local_f1 = 0;
          local_f8 = 0x2311;
          FUN_0020aff4(&local_f8,8);
          (**(code **)(param_1 + 0x18))(0x20000001,0,0,0,*(undefined8 *)(param_1 + 0x20));
        }
        bVar6 = false;
        goto LAB_00214ed4;
      }
      if (uVar9 != 0x40000003) goto LAB_00214ed4;
      FUN_00211034(param_1,*(undefined4 *)(param_1 + 0x420),&local_e0,param_1 + 0x1dcc,
                   param_1 + 0x108);
      local_fe = '\0';
      local_fd = '\0';
      uVar3 = 0;
      if (*(uint *)(param_1 + 0x420) < 4) {
        uVar3 = PTR_g_msidconv_00401cd8[(ulong)*(uint *)(param_1 + 0x420) * 0x80];
      }
      bVar6 = true;
      bVar5 = true;
      FUN_0020c154(param_1,*(undefined8 *)((long)pvVar13 + 0x10),&local_fe);
      goto LAB_00214c10;
    }
    if (uVar9 == 0x10000001) goto LAB_00214fac;
    if (uVar9 != 0x10000007) {
      if (uVar9 != 0x10000000) goto LAB_00214ed4;
      if (*(byte *)(param_1 + 0x43f) != 0) {
        bVar16 = *(byte *)(param_1 + 0x43f);
      }
      bVar5 = false;
      iVar17 = 1;
      FUN_002111cc(param_1,pvVar13,&local_e0,param_1 + 0x1dcc);
      goto LAB_00214c10;
    }
    FUN_00211a40(param_1,param_1 + 0x488,0);
  }
LAB_00214ed4:
  bVar5 = false;
  goto LAB_00214c10;
}

