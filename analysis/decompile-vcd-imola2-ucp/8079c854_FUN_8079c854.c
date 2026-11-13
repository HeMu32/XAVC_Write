// FUN_8079c854
// Ghidra address: 8079c854

undefined4 FUN_8079c854(short param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  
  uVar9 = 0;
  iVar8 = (int)param_1;
  uVar2 = FUN_80714f40(1,0);
  FUN_80714fec();
  iVar6 = DAT_807c95dc;
  if (DAT_807c0bb1 == '\0') {
    if (((DAT_807c0ba8 == 0) && (DAT_807c0ba4 == '\0')) || (param_3 == 0)) {
      if (iVar8 - 1U < 8) {
        if (param_3 < -1) {
          uVar9 = 0xffffffef;
        }
        else {
          iVar7 = iVar8 * 0x10;
          if (*(short *)(&DAT_807b63dc + iVar7) == 0) {
            uVar9 = 0xffffffd6;
          }
          else {
            iVar8 = iVar8 * 0x18;
            iVar4 = *(int *)(&DAT_807c9340 + iVar8);
            if (iVar4 == 0) {
              if (*(uint *)(&DAT_807c9350 + iVar8) < *(uint *)(&DAT_807b63d4 + iVar7)) {
                *(uint *)(&DAT_807c9350 + iVar8) = *(uint *)(&DAT_807c9350 + iVar8) + 1;
                puVar5 = *(undefined4 **)(&DAT_807c9348 + iVar8) + 1;
                **(undefined4 **)(&DAT_807c9348 + iVar8) = param_2;
                iVar6 = *(int *)(&DAT_807b63d8 + iVar7);
                *(undefined4 **)(&DAT_807c9348 + iVar8) = puVar5;
                if ((undefined4 *)(iVar6 + *(int *)(&DAT_807c934c + iVar8)) <= puVar5) {
                  *(int *)(&DAT_807c9348 + iVar8) = iVar6;
                }
                goto LAB_8079c8d8;
              }
              if (param_3 == 0) {
                uVar9 = 0xffffffce;
                goto LAB_8079c8d8;
              }
              *(short *)(DAT_807c95dc + 0x28) = param_1;
              *(undefined1 *)(iVar6 + 0xe) = 4;
              *(undefined2 *)(iVar6 + 0x12) = 0x10;
              *(undefined4 *)(iVar6 + 0x14) = param_2;
              FUN_80714954(iVar6);
              pcVar3 = FUN_8079b358;
              if ((*(uint *)(&DAT_807b63d0 + iVar7) & 1) == 0) {
                pcVar3 = FUN_8079b5b4;
              }
              (*pcVar3)(&DAT_807c933c + iVar8,&DAT_807c95dc + *(byte *)(iVar6 + 0xd),iVar6);
              if (param_3 < 1) {
                if (param_3 == -1) {
                  *(undefined4 *)(iVar6 + 0x2c) = 0xffffffff;
                }
              }
              else {
                *(int *)(iVar6 + 0x2c) = param_3;
                FUN_8079b460(iVar6);
              }
            }
            else {
              iVar6 = *(int *)(iVar4 + 0x20);
              **(undefined4 **)(iVar4 + 0x14) = param_2;
              if (iVar6 != 0) {
                FUN_8079b630();
                iVar4 = *(int *)(&DAT_807c9340 + iVar8);
              }
              *(undefined2 *)(iVar4 + 0x28) = 0;
              *(byte *)(iVar4 + 0xe) = *(byte *)(iVar4 + 0xe) & 8;
              iVar6 = *(int *)(&DAT_807c9340 + iVar8);
              *(undefined2 *)(iVar4 + 0x12) = 0;
              cVar1 = *(char *)(iVar6 + 0xe);
              *(undefined4 *)(iVar4 + 0x14) = 0;
              puVar5 = &DAT_807c95c4;
              if (cVar1 == '\0') {
                *(undefined1 *)(iVar6 + 0xe) = 2;
                FUN_807148dc(*(undefined1 *)(*(int *)(&DAT_807c9340 + iVar8) + 0xd));
                puVar5 = &DAT_807c95dc + *(byte *)(*(int *)(&DAT_807c9340 + iVar8) + 0xd);
              }
              FUN_8079b5b4(puVar5,&DAT_807c9340 + iVar8);
            }
            if ((DAT_807c0ba8 == 0) && (DAT_807c0ba4 == '\0')) {
              uVar2 = FUN_807146a4(uVar2);
              return uVar2;
            }
            DAT_807c0bb0 = 1;
          }
        }
      }
      else {
        uVar9 = 0xffffffee;
      }
    }
    else {
      uVar9 = 0xffffffe7;
    }
  }
  else {
    uVar9 = 0xffffffe7;
  }
LAB_8079c8d8:
  FUN_80714f40(0xff,uVar2);
  return uVar9;
}

