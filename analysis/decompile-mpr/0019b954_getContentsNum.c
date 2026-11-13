// mpr::dbg::getContentsNum
// Ghidra address: 0019b954

/* mpr::dbg::getContentsNum(unsigned int) */

void mpr::dbg::getContentsNum(uint param_1)

{
  set *this;
  int iVar1;
  ulong uVar2;
  size_t sVar3;
  ulong uVar4;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  
  uVar4 = (ulong)param_1;
  if (param_1 < 4) {
    local_3c = 0xffff;
    uStack_38 = 0xffff;
    local_34 = 0xffff;
    uStack_30 = 0xffff;
    local_40 = *(undefined4 *)(PTR_g_msidconv_00401cd8 + uVar4 * 0x80 + 0x7c);
    this = (set *)(PTR_g_rootContentSet_00402d48 + uVar4 * 0x20);
    iVar1 = sidb::GetRootSet(1,&local_40,*(undefined4 *)PTR_g_filter_00402410,0,1,0,this);
    if (iVar1 == 0) {
      uVar2 = sidb::set::size(this);
      uVar2 = uVar2 & 0xffffffff;
      goto LAB_0019b9e8;
    }
  }
  uVar2 = 0;
LAB_0019b9e8:
  snprintf((char *)&local_40,0x40,"CMDNUM,%d,%d",uVar4,uVar2);
  sVar3 = strlen((char *)&local_40);
  dbgcmd::send_to_ui((char *)&local_40,(uint)sVar3);
  dbgcmd::send_to_ui("\n",1);
  return;
}

