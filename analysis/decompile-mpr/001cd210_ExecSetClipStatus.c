// mpr::ExecSetClipStatus
// Ghidra address: 001cd210

/* mpr::ExecSetClipStatus(void*) */

void mpr::ExecSetClipStatus(void *param_1)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  undefined8 uVar4;
  ulong uVar5;
  undefined4 uVar6;
  char *pcVar7;
  char cVar8;
  undefined2 local_68;
  undefined2 local_66;
  undefined1 local_64;
  undefined1 local_63;
  undefined1 local_62;
  undefined1 local_61;
  undefined4 local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  
  pcVar7 = (char *)((long)param_1 + 0x10);
  uVar5 = 0;
  local_58 = 0x1b002110;
  cVar8 = '\0';
  local_54 = 4;
  FUN_001c9f24((execIssueEvent_t *)&local_58,8);
  do {
    cVar2 = *pcVar7;
    if (cVar2 != '\0') {
      if (*(XavcsMovieWriter **)(pcVar7 + 0x10) == (XavcsMovieWriter *)0x0) {
        local_58 = 0x1b012110;
        local_50 = *(undefined4 *)((long)param_1 + uVar5 * 0x1ac8 + 0x18);
LAB_001cd2b4:
        local_54 = 3;
        uVar4 = 0xc;
        goto LAB_001cd2bc;
      }
      XavcsMovieWriter::SetClipStatus
                (*(XavcsMovieWriter **)(pcVar7 + 0x10),*(undefined4 *)((long)param_1 + 0x85a0));
      cVar3 = pcVar7[0x140];
      cVar8 = cVar2;
      if (cVar3 != '\0') {
        if (*(XavcsMovieWriter **)(pcVar7 + 0x150) == (XavcsMovieWriter *)0x0) {
          local_58 = 0x1b022110;
          local_50 = *(undefined4 *)((long)param_1 + uVar5 * 0x1ac8 + 0x158);
          goto LAB_001cd2b4;
        }
        XavcsMovieWriter::SetClipStatus
                  (*(XavcsMovieWriter **)(pcVar7 + 0x150),*(undefined4 *)((long)param_1 + 0x85a0));
        cVar8 = cVar3;
      }
    }
    uVar1 = (int)uVar5 + 1;
    uVar5 = (ulong)uVar1;
    pcVar7 = pcVar7 + 0x1ac8;
  } while (uVar1 != 4);
  uVar6 = 0;
  if (cVar8 == '\0') {
    uVar4 = 8;
    local_54 = 4;
    local_58 = 0x1b032110;
LAB_001cd2bc:
    uVar6 = 2;
    FUN_001c9f24((execIssueEvent_t *)&local_58,uVar4);
  }
  local_58 = 0x1035;
  local_54 = uVar6;
  NotifyClipStatusInRecFinished((execIssueEvent_t *)&local_58);
  local_63 = 0;
  local_64 = 3;
  local_62 = 0;
  local_68 = 0x2110;
  local_61 = 0;
  local_66 = 0x1b0f;
  local_60 = uVar6;
  FUN_001c9f24(&local_68,0xc);
  return;
}

