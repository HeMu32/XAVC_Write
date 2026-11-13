// ELF VMA 0x27d1424; Ghidra bias 0x100000

void appfw_27d1424(undefined8 param_1,uint param_2,uint param_3,byte param_4,char param_5,
                  char param_6)

{
  char cVar1;
  ulong uVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  undefined8 uVar6;
  int *piVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined8 uVar10;
  undefined4 uStack_422c;
  undefined8 uStack_4228;
  undefined1 auStack_4220 [8];
  undefined8 uStack_4218;
  undefined8 uStack_4210;
  undefined8 uStack_4208;
  undefined4 uStack_4200;
  undefined1 uStack_41fc;
  undefined1 uStack_41fb;
  undefined8 uStack_41f8;
  long lStack_41f0;
  uint uStack_41e8;
  
  func_0x01936e44(auStack_4220);
  uVar10 = uStack_4218;
  uVar6 = func_0x029e9d3c();
  uStack_4208 = func_0x029e9d50();
  uStack_41f8 = uVar10;
  uStack_4200 = 0x23;
  uStack_41fc = 0;
  uStack_41fb = 0;
  uStack_4210 = uVar6;
  func_0x01815020(&lStack_41f0,0,0x400);
  bVar3 = true;
  func_0x0273fe24(&uStack_4210,&lStack_41f0);
  func_0x026b7f28(&uStack_4210);
  func_0x01936e68(auStack_4220);
  func_0x02fe71e8(&uStack_4210);
  piVar7 = (int *)func_0x02a07680();
  if (*piVar7 != 1) {
    func_0x02fe71e8(&lStack_41f0);
    piVar7 = (int *)func_0x02a07680();
    bVar3 = *piVar7 == 2;
    func_0x02fe6ec4(&lStack_41f0);
  }
  func_0x02fe6ec4(&uStack_4210);
  func_0x02fe71e8(&lStack_41f0);
  puVar8 = (undefined4 *)func_0x02a2333c();
  iVar5 = func_0x02696258(param_1,*puVar8);
  func_0x02fe6ec4(&lStack_41f0);
  if (iVar5 != 0) {
    bVar3 = false;
    param_5 = '\0';
  }
  if (param_5 == '\0' && !bVar3) goto LAB_028d1684;
  if (param_2 != 0) {
    uVar2 = (ulong)uStack_4208 >> 0x18;
    uStack_4210 = CONCAT44(param_3,param_2);
    uStack_4208 = CONCAT53((uint5)uVar2 & 0xffffffff00,0x10000);
    uStack_4208 = CONCAT71(uStack_4208._1_7_,param_4);
    func_0x0363c684(&lStack_41f0,&uStack_4210);
    func_0x0363f578(&lStack_41f0);
    func_0x028d0c34(&lStack_41f0);
  }
  if (bVar3) {
    func_0x02fe71e8(&lStack_41f0);
    pcVar9 = (char *)func_0x02a16df0();
    cVar1 = *pcVar9;
    func_0x02fe6ec4(&lStack_41f0);
    if (cVar1 != '\0') {
      func_0x027089d8(param_1,0);
    }
  }
  uVar10 = func_0x03341cf0();
  func_0x03404f00(uVar10,0x4f3);
  uVar10 = func_0x03341cf0();
  func_0x0349dc7c(uVar10,0x4f7,&lStack_41f0);
  iVar5 = func_0x02686054(param_1);
  func_0x02fe71e8(&lStack_41f0);
  if (iVar5 == 0) {
    piVar7 = (int *)func_0x02a082d8();
LAB_028d15e8:
    bVar3 = *piVar7 == 1;
  }
  else {
    bVar3 = false;
    if (iVar5 == 1) {
      piVar7 = (int *)func_0x02a08378();
      goto LAB_028d15e8;
    }
  }
  func_0x02fe6ec4(&lStack_41f0);
  func_0x02fe71e8(&lStack_41f0);
  piVar7 = (int *)func_0x02a07680();
  iVar5 = *piVar7;
  func_0x02fe6ec4(&lStack_41f0);
  uStack_4228 = (ulong)param_2 << 0x20;
  uStack_4228._0_3_ = CONCAT12(iVar5 == 2,0x100);
  uStack_4228 = CONCAT71(uStack_4228._1_7_,bVar3);
  func_0x02681d34(&lStack_41f0,&uStack_4228);
  appfw_3596604(&lStack_41f0);
  func_0x01936e44(auStack_4220);
  func_0x0267bbac(&uStack_4210,uStack_4218);
  uStack_422c = 0;
  func_0x0273d514(&uStack_4210,&uStack_422c);
  func_0x026fe254(&uStack_4210);
  func_0x01936e68(auStack_4220);
  func_0x028ceb00(&lStack_41f0);
LAB_028d1684:
  uStack_4210 = CONCAT44(param_3,param_2);
  uStack_4208._1_7_ = (undefined7)(CONCAT44((int)((ulong)uStack_4208 >> 0x20),0x1000000) >> 8);
  uStack_4208 = CONCAT71(uStack_4208._1_7_,param_4);
  func_0x0363c684(&lStack_41f0,&uStack_4210);
  func_0x0363f578(&lStack_41f0);
  func_0x028d0c34(&lStack_41f0);
  if (param_6 == '\0') {
    lStack_41f0 = (ulong)param_3 << 0x20;
    uStack_41e8 = (uint)param_4;
    func_0x02634630(&lStack_41f0,1,0);
  }
  else {
    uVar10 = func_0x03341cf0();
    uStack_41e8._0_3_ = (uint3)param_4;
    lStack_41f0 = (ulong)param_3 << 0x20;
    func_0x0340b74c(uVar10,0x33,&lStack_41f0);
  }
  bVar3 = false;
  func_0x02fe71e8(&lStack_41f0);
  piVar7 = (int *)func_0x029f15a8();
  iVar5 = *piVar7;
  func_0x02fe6ec4(&lStack_41f0);
  if (iVar5 == 1) {
    func_0x02fe71e8(auStack_4220);
    piVar7 = (int *)func_0x029f033c();
    bVar3 = true;
    if (*piVar7 != 8) {
      func_0x02fe71e8(&uStack_4210);
      piVar7 = (int *)func_0x029f033c();
      if (*piVar7 != 7) {
        func_0x02fe71e8(&lStack_41f0);
        piVar7 = (int *)func_0x029f033c();
        bVar3 = *piVar7 == 6;
        func_0x02fe6ec4(&lStack_41f0);
      }
      func_0x02fe6ec4(&uStack_4210);
    }
    func_0x02fe6ec4(auStack_4220);
  }
  bVar4 = true;
  func_0x02fe71e8(auStack_4220);
  piVar7 = (int *)func_0x029f02ec();
  if (*piVar7 == 0) {
    bVar4 = false;
    func_0x02fe71e8(&uStack_4210);
    piVar7 = (int *)func_0x02a090ac();
    if (*piVar7 == 2) {
      func_0x02fe71e8(&lStack_41f0);
      piVar7 = (int *)func_0x029ecab0();
      bVar4 = *piVar7 == 1;
      func_0x02fe6ec4(&lStack_41f0);
    }
    func_0x02fe6ec4(&uStack_4210);
  }
  func_0x02fe6ec4(auStack_4220);
  if ((bool)(bVar3 & (bVar4 ^ 1U))) {
    if (param_6 != '\0') {
      uVar10 = func_0x03341cf0();
      func_0x03404f00(uVar10,0x34);
    }
    lStack_41f0 = 0;
    uStack_41e8 = CONCAT31(0x101,param_4);
    func_0x026346e0(&lStack_41f0,1,0);
  }
  else {
    uVar10 = func_0x03341cf0();
    func_0x03404f00(uVar10,0x34);
  }
  func_0x02fe71e8(&lStack_41f0);
  piVar7 = (int *)func_0x029ecdf8();
  iVar5 = *piVar7;
  func_0x02fe6ec4(&lStack_41f0);
  if (iVar5 != 0) {
    func_0x0269ee20(param_1);
  }
  return;
}

