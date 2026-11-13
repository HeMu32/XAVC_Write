// FUN_00345f70
// Ghidra address: 00345f70

/* WARNING: Heritage AFTER dead removal. Example location: x0 : 0x00346088 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

string * FUN_00345f70(string *param_1,short *param_2)

{
  undefined *puVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  ostream *poVar7;
  char local_1b0 [8];
  string asStack_1a8 [32];
  stringstream asStack_188 [16];
  long local_178;
  undefined8 auStack_168 [45];
  
  *(string **)param_1 = param_1 + 0x10;
  *(undefined8 *)(param_1 + 8) = 0;
  param_1[0x10] = (string)0x0;
  std::__cxx11::stringstream::stringstream(asStack_188,0x18);
  local_1b0[4] = '\0';
  local_1b0[5] = '\0';
  local_1b0[6] = 0;
  local_1b0[0] = '\0';
  local_1b0[1] = '\0';
  local_1b0[2] = '\0';
  local_1b0[3] = '\0';
  if ((((param_2[1] < 10000) && ((byte)((char)param_2[2] - 1U) < 0xc)) &&
      ((byte)(*(char *)((long)param_2 + 5) - 1U) < 0x1f)) &&
     (((*(byte *)(param_2 + 3) < 0x18 && (*(byte *)((long)param_2 + 7) < 0x3c)) &&
      (*(byte *)(param_2 + 4) < 0x3d)))) {
    sVar2 = *param_2;
    iVar5 = (int)sVar2;
    if (iVar5 == 0) {
      strncpy(local_1b0,"Z",7);
    }
    else {
      if (iVar5 < 1) {
        uVar3 = (uint)(sVar2 / -0x3c);
        uVar4 = -iVar5 % 0x3c;
        puVar1 = &DAT_003de08c;
      }
      else {
        uVar3 = (int)sVar2 / 0x3c;
        puVar1 = &DAT_003db058;
        uVar4 = (uint)(short)(sVar2 + (short)uVar3 * -0x3c);
      }
      snprintf(local_1b0,7,"%s%02d%s%02d",puVar1,(ulong)uVar3,&DAT_003d1e67,(ulong)uVar4);
    }
    lVar6 = *(long *)(local_178 + -0x18);
    *(undefined8 *)((long)auStack_168 + lVar6) = 4;
    poVar7 = std::operator<<(lVar6,0x30);
    poVar7 = (ostream *)std::ostream::operator<<(poVar7,param_2[1]);
    std::operator<<(poVar7,'-');
    lVar6 = *(long *)(local_178 + -0x18);
    *(undefined8 *)((long)auStack_168 + lVar6) = 2;
    poVar7 = std::operator<<(lVar6,0x30);
    poVar7 = (ostream *)std::ostream::operator<<(poVar7,(int)(char)param_2[2]);
    std::operator<<(poVar7,'-');
    lVar6 = *(long *)(local_178 + -0x18);
    *(undefined8 *)((long)auStack_168 + lVar6) = 2;
    poVar7 = std::operator<<(lVar6,0x30);
    poVar7 = (ostream *)std::ostream::operator<<(poVar7,(int)*(char *)((long)param_2 + 5));
    std::operator<<(poVar7,'T');
    lVar6 = *(long *)(local_178 + -0x18);
    *(undefined8 *)((long)auStack_168 + lVar6) = 2;
    poVar7 = std::operator<<(lVar6,0x30);
    poVar7 = (ostream *)std::ostream::operator<<(poVar7,(int)(char)param_2[3]);
    std::operator<<(poVar7,':');
    lVar6 = *(long *)(local_178 + -0x18);
    *(undefined8 *)((long)auStack_168 + lVar6) = 2;
    poVar7 = std::operator<<(lVar6,0x30);
    poVar7 = (ostream *)std::ostream::operator<<(poVar7,(int)*(char *)((long)param_2 + 7));
    std::operator<<(poVar7,':');
    lVar6 = *(long *)(local_178 + -0x18);
    *(undefined8 *)((long)auStack_168 + lVar6) = 2;
    poVar7 = std::operator<<(lVar6,0x30);
    poVar7 = (ostream *)std::ostream::operator<<(poVar7,(int)(char)param_2[4]);
    std::operator<<(poVar7,local_1b0);
    std::__cxx11::stringbuf::str();
    std::__cxx11::string::operator=(param_1,asStack_1a8);
    std::__cxx11::string::_M_dispose();
  }
  std::__cxx11::stringstream::~stringstream(asStack_188);
  return param_1;
}

