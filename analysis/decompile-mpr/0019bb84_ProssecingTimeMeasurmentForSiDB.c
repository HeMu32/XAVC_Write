// mpr::dbg::ProssecingTimeMeasurmentForSiDB
// Ghidra address: 0019bb84

/* WARNING: Type propagation algorithm not settling */
/* mpr::dbg::ProssecingTimeMeasurmentForSiDB(unsigned int, unsigned int) */

undefined8 mpr::dbg::ProssecingTimeMeasurmentForSiDB(uint param_1,uint param_2)

{
  uint uVar1;
  pthread_mutex_t *__mutex;
  long lVar2;
  long lVar3;
  undefined4 uVar4;
  set sVar5;
  long lVar6;
  undefined *puVar7;
  long lVar8;
  char cVar9;
  long lVar10;
  int iVar11;
  int iVar12;
  char cVar13;
  ulong uVar14;
  short sVar15;
  int iVar16;
  char cVar17;
  ulong uVar18;
  ulong uVar19;
  uint uVar20;
  ulong uVar21;
  uint local_6a8 [2];
  timespec tStack_6a0;
  timespec tStack_690;
  timespec local_680;
  timespec local_670;
  undefined4 local_660;
  undefined4 local_65c;
  undefined4 uStack_658;
  undefined4 local_654;
  undefined4 uStack_650;
  set local_640 [12];
  undefined4 uStack_634;
  char local_630;
  undefined4 local_620;
  uint local_61c;
  undefined4 local_618;
  undefined2 local_614;
  short local_612;
  undefined1 local_610;
  char local_60f;
  char local_60e;
  char local_60d;
  char local_60c;
  undefined2 local_60a;
  undefined2 local_608;
  undefined2 local_606;
  undefined1 local_604;
  undefined4 local_600;
  undefined1 local_5fc;
  undefined1 local_5fb;
  undefined1 local_5fa;
  undefined1 local_5c4;
  undefined1 local_58c;
  undefined1 local_578;
  undefined1 local_560;
  char acStack_55f [262];
  undefined1 local_459;
  undefined1 local_352;
  undefined1 local_24b;
  undefined8 local_3c;
  undefined4 local_34;
  
  uVar21 = 100;
  local_6a8[0] = 0;
  sidb::recordInfo::clear((recordInfo *)&local_620);
  puVar7 = PTR_g_msidconv_00401cd8;
  uVar4 = *(undefined4 *)(PTR_g_msidconv_00401cd8 + 0x7c);
  FUN_00198a58(&local_660,&DAT_003d7eaf);
  FUN_00198a58(local_640,"/PRIVATE/DATABASE/DATABASE.BIN");
  cVar17 = '\x01';
  sidb::CreateDBFile(uVar4,0x41,&local_660,local_640);
  std::__cxx11::string::_M_dispose();
  std::__cxx11::string::_M_dispose();
  sidb::recordInfo::clear((recordInfo *)&local_620);
  local_614 = 0;
  local_61c = local_6a8[0];
  local_60f = '\x01';
  local_612 = 0x7e4;
  local_606 = 1;
  local_610 = 0xb;
  local_604 = 1;
  local_60e = '\f';
  local_5fc = 0;
  local_60d = '\x1a';
  local_5fb = 0;
  local_60c = '&';
  local_5fa = 0;
  local_60a = 0x226;
  local_5c4 = 0;
  local_608 = 100;
  local_58c = 0;
  local_578 = 0;
  local_560 = 1;
  local_620 = 1;
  local_618 = 0;
  local_600 = 0;
  strncpy(acStack_55f,"A:/DCIM/100MSDCF/DCF00001.JPG",0x106);
  local_459 = 0;
  local_352 = 0;
  local_24b = 0;
  local_6a8[1] = 0;
  clock_gettime(0,&tStack_6a0);
  uVar14 = 0;
  cVar13 = '&';
  iVar12 = 0x1a;
  iVar11 = 0xc;
  iVar16 = 0xb;
  sVar15 = 0x7e4;
  uVar20 = 0;
  uVar18 = 1;
LAB_0019bd08:
  if (uVar14 == param_1) {
    clock_gettime(0,&tStack_690);
    sidb::set::set(local_640);
    local_65c = 0xffff;
    uStack_658 = 0xffff;
    local_654 = 0xffff;
    uStack_650 = 0xffff;
    local_660 = *(undefined4 *)(PTR_g_msidconv_00401cd8 + 0x7c);
    sidb::GetRootSet(1,&local_660,1,0,1,0,local_640);
    lVar6 = -((ulong)param_2 * 8 + 0x16 & 0xffffffff0);
    for (uVar14 = 0; uVar14 != param_2; uVar14 = uVar14 + 1) {
      clock_gettime(0,&local_680);
      clock_gettime(0,&local_670);
      *(long *)(&stack0xfffffffffffff8a0 + uVar14 * 8 + lVar6) =
           (local_670.tv_nsec - local_680.tv_nsec) +
           (local_670.tv_sec - local_680.tv_sec) * 1000000000;
    }
    uVar18 = 0;
    do {
      if (uVar18 == uVar14) {
        sidb::set::~set(local_640);
        return 0;
      }
      clock_gettime(0,&local_680);
      if (local_630 == '\0') {
        lVar8 = CONCAT44(uStack_634,
                         CONCAT13(local_640[0xb],
                                  CONCAT12(local_640[10],CONCAT11(local_640[9],local_640[8]))));
        __mutex = (pthread_mutex_t *)(lVar8 + 0x218);
        pthread_mutex_lock(__mutex);
        lVar2 = lVar8 + (ulong)*(uint *)(lVar8 + 0x10) * 8;
        for (; lVar8 != lVar2; lVar8 = lVar8 + 8) {
          lVar10 = *(long *)(lVar8 + 0x18);
          lVar3 = lVar10 + (ulong)*(uint *)(lVar10 + 0x14) * 8;
          for (; lVar10 != lVar3; lVar10 = lVar10 + 8) {
            uVar21 = 0;
            while (*(uint *)(*(long *)(lVar10 + 0x18) + 0xc) != uVar21) {
              uVar21 = uVar21 + 1;
              if (uVar20 == *(uint *)(*(long *)(lVar10 + 0x18) + uVar21 * 4 + 0xc))
              goto LAB_0019c030;
            }
          }
        }
LAB_0019c030:
        pthread_mutex_unlock(__mutex);
      }
      clock_gettime(0,&local_670);
      *(long *)(&stack0xfffffffffffff8a0 + uVar18 * 8 + lVar6) =
           (local_670.tv_nsec - local_680.tv_nsec) +
           (local_670.tv_sec - local_680.tv_sec) * 1000000000;
      uVar18 = uVar18 + 1;
    } while( true );
  }
  sidb::IssueUniqueId(*(uint *)(puVar7 + 0x7c),local_6a8,true);
  uVar20 = local_6a8[0];
  local_606 = (undefined2)uVar18;
  local_3c = 0;
  local_34 = 0;
  uVar1 = (int)uVar18 + 1;
  uVar19 = (ulong)uVar1;
  local_608 = (undefined2)uVar21;
  local_560 = 1;
  local_61c = local_6a8[0];
  snprintf(acStack_55f,0x106,"A:/DCIM/%03dMSDCF/DCF0%04d.JPG",uVar21,uVar18);
  local_60a = 0x226;
  local_610 = (undefined1)iVar16;
  local_614 = 0;
  local_612 = sVar15;
  local_60f = cVar17;
  local_60e = (char)iVar11;
  local_60d = (char)iVar12;
  local_60c = cVar13;
  sidb::Update(0xffffffff,(recordInfo *)&local_620,true,true);
  sidb::GetRemain(*(undefined4 *)(puVar7 + 0x7c),0xffffffff,local_6a8 + 1,1);
  if ((uVar1 == 4000) || (uVar1 == 8000)) {
    uVar21 = (ulong)((int)uVar21 + 1);
  }
  else if (uVar1 == 9999) {
    uVar21 = (ulong)((int)uVar21 + 1);
    uVar19 = 1;
  }
  cVar13 = cVar13 + '\x01';
  local_640[0] = (set)0x0;
  local_640[2] = (set)0x1c;
  local_640[1] = (set)0x1f;
  local_640[3] = (set)0x1f;
  local_640[4] = (set)0x1e;
  local_640[5] = (set)0x1f;
  local_640[6] = (set)0x1e;
  local_640[7] = (set)0x1f;
  local_640[8] = (set)0x1f;
  local_640[9] = (set)0x1e;
  local_640[10] = (set)0x1f;
  local_640[0xb] = (set)0x1e;
  uStack_634 = CONCAT31(uStack_634._1_3_,0x1f);
  if (';' < cVar13) {
    cVar9 = cVar13 / '<';
    cVar13 = cVar13 % '<';
    iVar12 = (int)(char)(cVar9 + (char)iVar12);
  }
  if (0x3b < iVar12) {
    cVar9 = (char)(iVar12 / 0x3c);
    iVar11 = (int)(char)(cVar9 + (char)iVar11);
    iVar12 = (int)(char)((char)iVar12 + cVar9 * -0x3c);
  }
  if (0x17 < iVar11) {
    cVar9 = (char)(iVar11 / 0x18);
    cVar17 = cVar9 + cVar17;
    iVar11 = (int)(char)((char)iVar11 + cVar9 * -0x18);
  }
  do {
    cVar9 = (char)iVar16;
    do {
      iVar16 = (int)cVar9;
      sVar5 = local_640[iVar16];
      if (cVar17 <= (char)sVar5) {
        uVar14 = uVar14 + 1;
        uVar18 = uVar19;
        goto LAB_0019bd08;
      }
      cVar9 = cVar9 + '\x01';
      cVar17 = cVar17 - (char)sVar5;
    } while (cVar9 < '\r');
    sVar15 = sVar15 + 1;
    iVar16 = 1;
  } while( true );
}

