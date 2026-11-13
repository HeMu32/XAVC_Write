// FUN_807a4ed8
// Ghidra address: 807a4ed8

/* WARNING: Removing unreachable block (ram,0x807a5048) */
/* WARNING: Removing unreachable block (ram,0x807a5000) */
/* WARNING: Removing unreachable block (ram,0x807a4fe4) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffc0 : 0x807a4f50 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_807a4ed8(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_807882e4(param_1,0);
  uVar2 = 0x807a4f5c;
  iVar1 = FUN_8079c854(5,0x8502,0xffffffff);
  if (iVar1 != 0) {
    FUN_80745808(&DAT_807c0524,s_________________________src_ipsx_807b0914,0x135,uVar2);
  }
  uVar2 = 0x807a4f74;
  iVar1 = FUN_8079c854(5,param_1,0xffffffff);
  if (iVar1 != 0) {
    FUN_80745808(&DAT_807c0524,s_________________________src_ipsx_807b0914,0x138,uVar2);
  }
  DAT_807c0518 = 2;
  DAT_807c051c = 1;
  DAT_807c0520 = param_1;
  return;
}

