// ELF VMA 0x27d37bc; Ghidra bias 0x100000

void appfw_27d37bc(undefined8 param_1,uint param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 uStack_422c;
  undefined8 uStack_4228;
  uint auStack_4220 [2];
  undefined8 uStack_4218;
  ulong uStack_4210;
  undefined1 uStack_4208;
  undefined1 uStack_4207;
  undefined1 uStack_4206;
  undefined1 uStack_4205;
  undefined4 uStack_4204;
  undefined1 auStack_41f0 [16880];
  
  bVar1 = true;
  func_0x02fe71e8(&uStack_4210);
  piVar3 = (int *)func_0x02a07680();
  if (*piVar3 != 1) {
    func_0x02fe71e8(auStack_41f0);
    piVar3 = (int *)func_0x02a07680();
    bVar1 = *piVar3 == 2;
    func_0x02fe6ec4(auStack_41f0);
  }
  func_0x02fe6ec4(&uStack_4210);
  if ((bool)(bVar1 & param_2 != 0)) {
    bVar1 = false;
    func_0x02fe71e8(&uStack_4210);
    piVar3 = (int *)func_0x029f857c();
    if (*piVar3 == 0) {
      func_0x02fe71e8(auStack_41f0);
      piVar3 = (int *)func_0x029efe64();
      bVar1 = *piVar3 == 1;
      func_0x02fe6ec4(auStack_41f0);
    }
    func_0x02fe6ec4(&uStack_4210);
    func_0x01936e44(&uStack_4210);
    func_0x0267e57c(auStack_41f0,
                    CONCAT44(uStack_4204,
                             CONCAT13(uStack_4205,
                                      CONCAT12(uStack_4206,CONCAT11(uStack_4207,uStack_4208)))));
    func_0x0273d418(auStack_41f0,param_3);
    func_0x0270fd50(auStack_41f0);
    func_0x01936e68(&uStack_4210);
    if (param_3 == 0) {
      func_0x01936e44(&uStack_4210);
      func_0x02676644(auStack_41f0,
                      CONCAT44(uStack_4204,
                               CONCAT13(uStack_4205,
                                        CONCAT12(uStack_4206,CONCAT11(uStack_4207,uStack_4208)))));
    }
    else {
      func_0x01936e44(&uStack_4210);
      func_0x02676644(auStack_41f0,
                      CONCAT44(uStack_4204,
                               CONCAT13(uStack_4205,
                                        CONCAT12(uStack_4206,CONCAT11(uStack_4207,uStack_4208)))));
    }
    auStack_4220[0] = (uint)(param_3 == 0);
    func_0x0273d490(auStack_41f0,auStack_4220);
    func_0x026b8ec8(auStack_41f0);
    func_0x01936e68(&uStack_4210);
    uStack_4207 = 0;
    uStack_4205 = 0;
    uStack_4206 = 1;
    uStack_4210 = (ulong)param_2;
    uStack_4208 = bVar1;
    func_0x0363c684(auStack_41f0,&uStack_4210);
    func_0x0363f578(auStack_41f0);
    func_0x028d0c34(auStack_41f0);
  }
  else if (!bVar1) {
    return;
  }
  iVar2 = func_0x02686054(param_1);
  func_0x02fe71e8(auStack_41f0);
  if (iVar2 == 0) {
    piVar3 = (int *)func_0x02a082d8();
  }
  else {
    bVar1 = false;
    if (iVar2 != 1) goto LAB_028d3954;
    piVar3 = (int *)func_0x02a08378();
  }
  bVar1 = *piVar3 == 1;
LAB_028d3954:
  func_0x02fe6ec4(auStack_41f0);
  func_0x02fe71e8(auStack_41f0);
  piVar3 = (int *)func_0x02a07680();
  iVar2 = *piVar3;
  func_0x02fe6ec4(auStack_41f0);
  uStack_4228 = (ulong)param_2 << 0x20;
  uStack_4228._0_3_ = CONCAT12(iVar2 == 2,0x100);
  uStack_4228 = CONCAT71(uStack_4228._1_7_,bVar1);
  func_0x02681d34(auStack_41f0,&uStack_4228);
  appfw_3596604(auStack_41f0);
  func_0x01936e44(auStack_4220);
  func_0x0267bbac(&uStack_4210,uStack_4218);
  uStack_422c = 0;
  func_0x0273d514(&uStack_4210,&uStack_422c);
  func_0x026fe254(&uStack_4210);
  func_0x01936e68(auStack_4220);
  func_0x028ceb00(auStack_41f0);
  return;
}

