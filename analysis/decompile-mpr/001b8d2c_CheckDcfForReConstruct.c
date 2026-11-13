// mpr::CheckDcfForReConstruct
// Ghidra address: 001b8d2c

/* mpr::CheckDcfForReConstruct(unsigned int, bool*, bool&, unsigned int&) */

undefined4 mpr::CheckDcfForReConstruct(uint param_1,bool *param_2,bool *param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 local_658;
  undefined4 uStack_654;
  undefined4 local_650;
  undefined4 uStack_64c;
  undefined4 local_648;
  set asStack_640 [32];
  recordInfo arStack_620 [1562];
  char local_6;
  
  uVar3 = 0xffffffff;
  if (param_1 < 4) {
    uVar3 = *(undefined4 *)(PTR_g_msidconv_00401cd8 + (ulong)param_1 * 0x80 + 0x7c);
  }
  *param_3 = false;
  *param_4 = 0;
  sidb::set::set(asStack_640);
  uStack_654 = 0xffff;
  local_650 = 0xffff;
  uStack_64c = 0xffff;
  local_648 = 0xffff;
  local_658 = uVar3;
  iVar1 = sidb::GetRootSet(1,&local_658,6,0,1,0,asStack_640);
  if (iVar1 == 0) {
    iVar1 = sidb::set::size(asStack_640);
    uVar3 = 0;
    if (iVar1 != 0) {
      uVar4 = 0;
      for (uVar5 = 0; uVar2 = sidb::set::size(asStack_640), uVar5 < uVar2; uVar5 = uVar5 + 1) {
        if ((param_2 != (bool *)0x0) && (*param_2 != false)) {
          uVar3 = 1;
          break;
        }
        sidb::recordInfo::clear(arStack_620);
        uVar2 = sidb::set::at(asStack_640,uVar5);
        iVar1 = sidb::Select(0xffffffff,uVar2,arStack_620,false);
        if (iVar1 != 0) {
          uVar3 = 2;
          break;
        }
        if (local_6 != '\0') {
          uVar4 = uVar4 + 1;
          *param_3 = true;
        }
      }
      *param_4 = (int)((double)uVar4 * DAT_003d39f0);
    }
  }
  else {
    uVar3 = 2;
  }
  sidb::set::~set(asStack_640);
  return uVar3;
}

