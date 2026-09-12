#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8265BF20"))) PPC_WEAK_FUNC(sub_8265BF20);
PPC_FUNC_IMPL(__imp__sub_8265BF20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r21{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x8265BF28;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r22,-32121
	r22.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,2
	ctx.r9.s64 = 131072;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// ori r21,r9,54176
	r21.u64 = ctx.r9.u64 | 54176;
	// lwz r11,-10236(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -10236);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,672(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r8,648(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 648);
	// add r23,r7,r21
	r23.u64 = ctx.r7.u64 + r21.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265BF60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,528
	ctx.r4.s64 = ctx.r6.s64 + 528;
	// lwz r11,788(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 788);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8265BF7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x8265BF84;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265BF94:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265bf94
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265BF94;
	// addi r24,r31,2100
	r24.s64 = r31.s64 + 2100;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265BFBC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265bfbc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265BFBC;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x8265BFD8;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265BFE8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265bfe8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265BFE8;
	// addi r25,r31,3300
	r25.s64 = r31.s64 + 3300;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C010:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c010
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C010;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x8265C02C;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C03C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c03c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C03C;
	// addi r26,r31,1364
	r26.s64 = r31.s64 + 1364;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C064:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c064
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C064;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x8265C080;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C090:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c090
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C090;
	// addi r28,r31,1620
	r28.s64 = r31.s64 + 1620;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C0B8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c0b8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C0B8;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x8265C0D4;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C0E4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c0e4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C0E4;
	// addi r27,r31,5108
	r27.s64 = r31.s64 + 5108;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C10C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c10c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C10C;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x8265C128;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C138:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c138
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C138;
	// addi r10,r31,5348
	ctx.r10.s64 = r31.s64 + 5348;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C15C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c15c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C15C;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x8265C178;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C188:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c188
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C188;
	// addi r10,r31,5588
	ctx.r10.s64 = r31.s64 + 5588;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C1AC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c1ac
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C1AC;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x8265C1C8;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C1D8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c1d8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C1D8;
	// addi r10,r31,5828
	ctx.r10.s64 = r31.s64 + 5828;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C1FC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c1fc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C1FC;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x8265C218;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C228:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c228
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C228;
	// addi r30,r31,3060
	r30.s64 = r31.s64 + 3060;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C250:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c250
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C250;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x8265C26C;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C27C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c27c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C27C;
	// addi r29,r31,4852
	r29.s64 = r31.s64 + 4852;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C2A4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c2a4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C2A4;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x8265C2C0;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C2D0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c2d0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C2D0;
	// addi r10,r31,4020
	ctx.r10.s64 = r31.s64 + 4020;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C2F4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c2f4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C2F4;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f70
	ctx.lr = 0x8265C310;
	sub_821C2F70(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C320:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c320
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C320;
	// addi r10,r31,3540
	ctx.r10.s64 = r31.s64 + 3540;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C344:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c344
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C344;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826550b8
	ctx.lr = 0x8265C360;
	sub_826550B8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826583c0
	ctx.lr = 0x8265C368;
	sub_826583C0(ctx, base);
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,27272
	ctx.r4.s64 = r11.s64 + 27272;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8265C37C;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C38C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c38c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C38C;
	// addi r10,r31,3780
	ctx.r10.s64 = r31.s64 + 3780;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C3B0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c3b0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C3B0;
	// lis r11,-32237
	r11.s64 = -2112684032;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,0
	ctx.r4.s64 = r11.s64 + 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8265C3D8;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C3E8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c3e8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C3E8;
	// addi r10,r31,4260
	ctx.r10.s64 = r31.s64 + 4260;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C40C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c40c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C40C;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,21960
	ctx.r4.s64 = r11.s64 + 21960;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8265C434;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C444:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c444
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C444;
	// addi r10,r31,4500
	ctx.r10.s64 = r31.s64 + 4500;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C468:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c468
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C468;
	// lis r11,-32237
	r11.s64 = -2112684032;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,0
	ctx.r4.s64 = r11.s64 + 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8265C490;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C4A0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c4a0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C4A0;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,-29656
	ctx.r4.s64 = r11.s64 + -29656;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8265C4C8;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C4D8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c4d8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C4D8;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,21840
	ctx.r4.s64 = r11.s64 + 21840;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8265C500;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C510:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c510
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C510;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,21944
	ctx.r4.s64 = r11.s64 + 21944;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8265C538;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C548:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c548
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C548;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,-20792
	ctx.r4.s64 = r11.s64 + -20792;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8265C570;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C580:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c580
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C580;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,21944
	ctx.r4.s64 = r11.s64 + 21944;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8265C5A8;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C5B8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c5b8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C5B8;
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,21944
	ctx.r4.s64 = r11.s64 + 21944;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8265C5E0;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8265C5F0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8265c5f0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8265C5F0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826564b8
	ctx.lr = 0x8265C60C;
	sub_826564B8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8265a4a0
	ctx.lr = 0x8265C614;
	sub_8265A4A0(ctx, base);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82654ac8
	ctx.lr = 0x8265C61C;
	sub_82654AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8265c64c
	if (!cr6.eq) goto loc_8265C64C;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82654b60
	ctx.lr = 0x8265C630;
	sub_82654B60(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8265c64c
	if (!cr6.eq) goto loc_8265C64C;
	// lbz r11,960(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 960);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8265c650
	if (cr6.eq) goto loc_8265C650;
loc_8265C64C:
	// li r11,0
	r11.s64 = 0;
loc_8265C650:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265c6c8
	if (cr6.eq) goto loc_8265C6C8;
	// addi r3,r23,672
	ctx.r3.s64 = r23.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x8265C664;
	sub_82631F88(ctx, base);
	// lwz r11,856(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8265c674
	if (cr6.lt) goto loc_8265C674;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8265C674:
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bgt cr6,0x8265c6c8
	if (cr6.gt) goto loc_8265C6C8;
	// lwz r11,-10236(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -10236);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r21
	ctx.r3.u64 = r11.u64 + r21.u64;
	// bl 0x82654bf8
	ctx.lr = 0x8265C68C;
	sub_82654BF8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bne cr6,0x8265c6b4
	if (!cr6.eq) goto loc_8265C6B4;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r11,29396
	ctx.r4.s64 = r11.s64 + 29396;
	// bl 0x8262ffe0
	ctx.lr = 0x8265C6B0;
	sub_8262FFE0(ctx, base);
	// b 0x8265c6e8
	goto loc_8265C6E8;
loc_8265C6B4:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r11,28124
	ctx.r4.s64 = r11.s64 + 28124;
	// bl 0x8262ffe0
	ctx.lr = 0x8265C6C4;
	sub_8262FFE0(ctx, base);
	// b 0x8265c6e8
	goto loc_8265C6E8;
loc_8265C6C8:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// addi r29,r11,29396
	r29.s64 = r11.s64 + 29396;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// bl 0x8262ffe0
	ctx.lr = 0x8265C6E4;
	sub_8262FFE0(ctx, base);
	// stw r29,464(r31)
	PPC_STORE_U32(r31.u32 + 464, r29.u32);
loc_8265C6E8:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,-10236(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -10236);
	// addi r4,r10,-10256
	ctx.r4.s64 = ctx.r10.s64 + -10256;
	// bl 0x821f9fb8
	ctx.lr = 0x8265C6F8;
	sub_821F9FB8(ctx, base);
	// lwz r9,256(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,196(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// lwz r4,56(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8265C714;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82658c28
	ctx.lr = 0x8265C71C;
	sub_82658C28(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265C730;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r9,8540(r31)
	PPC_STORE_U8(r31.u32 + 8540, ctx.r9.u8);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8265C740"))) PPC_WEAK_FUNC(sub_8265C740);
PPC_FUNC_IMPL(__imp__sub_8265C740) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r30,1016
	r31.s64 = r30.s64 + 1016;
	// lwz r11,1056(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1056);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bne cr6,0x8265c7f4
	if (!cr6.eq) goto loc_8265C7F4;
	// addi r4,r30,952
	ctx.r4.s64 = r30.s64 + 952;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8265b3c0
	ctx.lr = 0x8265C774;
	sub_8265B3C0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265C790;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265C7A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8265c7ec
	if (!cr6.gt) goto loc_8265C7EC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265C7C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,1060(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 1060);
	// twllei r3,0
	// rotlwi r11,r9,1
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// divw r8,r9,r3
	ctx.r8.s32 = ctx.r9.s32 / ctx.r3.s32;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// mullw r6,r8,r3
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r3.s32);
	// andc r5,r3,r7
	ctx.r5.u64 = ctx.r3.u64 & ~ctx.r7.u64;
	// subf r4,r6,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r6.s64;
	// twlgei r5,-1
	// stw r4,1060(r30)
	PPC_STORE_U32(r30.u32 + 1060, ctx.r4.u32);
	// b 0x8265c7f4
	goto loc_8265C7F4;
loc_8265C7EC:
	// li r11,-1
	r11.s64 = -1;
	// stw r11,1060(r30)
	PPC_STORE_U32(r30.u32 + 1060, r11.u32);
loc_8265C7F4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265C80C"))) PPC_WEAK_FUNC(sub_8265C80C);
PPC_FUNC_IMPL(__imp__sub_8265C80C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265C810"))) PPC_WEAK_FUNC(sub_8265C810);
PPC_FUNC_IMPL(__imp__sub_8265C810) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r9,1428
	ctx.r4.s64 = ctx.r9.s64 + 1428;
	// addi r8,r11,28548
	ctx.r8.s64 = r11.s64 + 28548;
	// addi r5,r10,1404
	ctx.r5.s64 = ctx.r10.s64 + 1404;
	// li r9,3
	ctx.r9.s64 = 3;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8265C84C;
	sub_8228F920(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r31,944
	ctx.r3.s64 = r31.s64 + 944;
	// addi r7,r8,604
	ctx.r7.s64 = ctx.r8.s64 + 604;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// bl 0x82659850
	ctx.lr = 0x8265C860;
	sub_82659850(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r3,r31,976
	ctx.r3.s64 = r31.s64 + 976;
	// addi r4,r6,568
	ctx.r4.s64 = ctx.r6.s64 + 568;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82633d40
	ctx.lr = 0x8265C874;
	sub_82633D40(ctx, base);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,1200
	ctx.r3.s64 = r31.s64 + 1200;
	// stw r4,1188(r31)
	PPC_STORE_U32(r31.u32 + 1188, ctx.r4.u32);
	// lfs f0,14192(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,1184(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1184, temp.u32);
	// bl 0x82634b60
	ctx.lr = 0x8265C890;
	sub_82634B60(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265C8A8"))) PPC_WEAK_FUNC(sub_8265C8A8);
PPC_FUNC_IMPL(__imp__sub_8265C8A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82646b48
	ctx.lr = 0x8265C8C8;
	sub_82646B48(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265c8e0
	if (cr6.eq) goto loc_8265C8E0;
	// bl 0x82130588
	ctx.lr = 0x8265C8DC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8265C8E0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265C8F8"))) PPC_WEAK_FUNC(sub_8265C8F8);
PPC_FUNC_IMPL(__imp__sub_8265C8F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8265C900;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r9,2308
	ctx.r4.s64 = ctx.r9.s64 + 2308;
	// addi r8,r11,27988
	ctx.r8.s64 = r11.s64 + 27988;
	// addi r5,r10,2284
	ctx.r5.s64 = ctx.r10.s64 + 2284;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,2
	ctx.r6.s64 = 2;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8265C930;
	sub_8228F920(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r7,r8,1484
	ctx.r7.s64 = ctx.r8.s64 + 1484;
	// addi r30,r31,944
	r30.s64 = r31.s64 + 944;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,1464
	ctx.r4.s64 = ctx.r6.s64 + 1464;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x8265C954;
	sub_82633D40(ctx, base);
	// addi r29,r31,1152
	r29.s64 = r31.s64 + 1152;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,1448
	ctx.r4.s64 = ctx.r4.s64 + 1448;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633d40
	ctx.lr = 0x8265C96C;
	sub_82633D40(ctx, base);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r3.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8265C9AC"))) PPC_WEAK_FUNC(sub_8265C9AC);
PPC_FUNC_IMPL(__imp__sub_8265C9AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265C9B0"))) PPC_WEAK_FUNC(sub_8265C9B0);
PPC_FUNC_IMPL(__imp__sub_8265C9B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82646f40
	ctx.lr = 0x8265C9D0;
	sub_82646F40(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265c9e8
	if (cr6.eq) goto loc_8265C9E8;
	// bl 0x82130588
	ctx.lr = 0x8265C9E4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8265C9E8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265CA00"))) PPC_WEAK_FUNC(sub_8265CA00);
PPC_FUNC_IMPL(__imp__sub_8265CA00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8265CA08;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,17
	ctx.r4.s64 = 17;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8265CA2C;
	sub_82641CB0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x826304b0
	ctx.lr = 0x8265CA34;
	sub_826304B0(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,-4116
	ctx.r4.s64 = ctx.r10.s64 + -4116;
	// lwz r8,340(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 340);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265CA50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,944(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 944);
	// addi r30,r31,944
	r30.s64 = r31.s64 + 944;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,24(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8265CA70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// lwz r3,-7572(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -7572);
	// bl 0x822f10d0
	ctx.lr = 0x8265CA7C;
	sub_822F10D0(ctx, base);
	// lis r4,-32120
	ctx.r4.s64 = -2105016320;
	// stfs f1,1184(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 1184, temp.u32);
	// lwz r11,-7884(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + -7884);
	// stw r11,1188(r31)
	PPC_STORE_U32(r31.u32 + 1188, r11.u32);
	// bl 0x822166e8
	ctx.lr = 0x8265CA90;
	sub_822166E8(ctx, base);
	// bl 0x82215a60
	ctx.lr = 0x8265CA94;
	sub_82215A60(ctx, base);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// addi r3,r3,2352
	ctx.r3.s64 = ctx.r3.s64 + 2352;
	// bl 0x821fa230
	ctx.lr = 0x8265CAA0;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265CAB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8265cafc
	if (cr6.eq) goto loc_8265CAFC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226b298
	ctx.lr = 0x8265CAC8;
	sub_8226B298(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8265cafc
	if (cr6.eq) goto loc_8265CAFC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8265CADC;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8265CAF0;
	sub_82270170(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x8265CAFC;
	sub_82274128(ctx, base);
loc_8265CAFC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265CB10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8265cb38
	if (!cr6.gt) goto loc_8265CB38;
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stw r30,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265CB34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8265cba8
	goto loc_8265CBA8;
loc_8265CB38:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// stw r10,864(r31)
	PPC_STORE_U32(r31.u32 + 864, ctx.r10.u32);
	// lwz r8,848(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r10,r9,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r10
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r10.u32, xer);
	// beq cr6,0x8265cb78
	if (cr6.eq) goto loc_8265CB78;
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
loc_8265CB64:
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r6.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x8265cb64
	if (!cr6.eq) goto loc_8265CB64;
loc_8265CB78:
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// addi r7,r31,976
	ctx.r7.s64 = r31.s64 + 976;
	// srawi r6,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 2;
	// subf r5,r6,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r6.s64;
	// clrlwi r3,r5,16
	ctx.r3.u64 = ctx.r5.u32 & 0xFFFF;
	// sth r5,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r5.u16);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rotlwi r8,r3,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r3.u32, 2);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// sth r10,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r10.u16);
	// stwx r7,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r7.u32);
loc_8265CBA8:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,2328
	ctx.r4.s64 = ctx.r10.s64 + 2328;
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x821fd980
	ctx.lr = 0x8265CBC0;
	sub_821FD980(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,32684
	ctx.r4.s64 = ctx.r8.s64 + 32684;
	// stw r9,88(r30)
	PPC_STORE_U32(r30.u32 + 88, ctx.r9.u32);
	// addi r3,r30,92
	ctx.r3.s64 = r30.s64 + 92;
	// bl 0x823dc018
	ctx.lr = 0x8265CBE0;
	sub_823DC018(ctx, base);
	// li r7,3
	ctx.r7.s64 = 3;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// stw r7,156(r30)
	PPC_STORE_U32(r30.u32 + 156, ctx.r7.u32);
	// addi r4,r6,-10256
	ctx.r4.s64 = ctx.r6.s64 + -10256;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8265CBF8;
	sub_821F9FB8(ctx, base);
	// lwz r5,256(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,196(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 196);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// lwz r4,56(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 56);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8265CC14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8265CC1C"))) PPC_WEAK_FUNC(sub_8265CC1C);
PPC_FUNC_IMPL(__imp__sub_8265CC1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265CC20"))) PPC_WEAK_FUNC(sub_8265CC20);
PPC_FUNC_IMPL(__imp__sub_8265CC20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r10,2372
	ctx.r4.s64 = ctx.r10.s64 + 2372;
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x821fd980
	ctx.lr = 0x8265CC50;
	sub_821FD980(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// addi r4,r9,32684
	ctx.r4.s64 = ctx.r9.s64 + 32684;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// bl 0x823dc018
	ctx.lr = 0x8265CC6C;
	sub_823DC018(ctx, base);
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r8,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r8.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265CC8C"))) PPC_WEAK_FUNC(sub_8265CC8C);
PPC_FUNC_IMPL(__imp__sub_8265CC8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265CC90"))) PPC_WEAK_FUNC(sub_8265CC90);
PPC_FUNC_IMPL(__imp__sub_8265CC90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x8265CC98;
	// stwu r1,-3376(r1)
	ea = -3376 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// lwz r3,-27856(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27856);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r31,r9,1
	r31.s64 = ctx.r9.s64 + 65536;
	// addi r31,r31,16256
	r31.s64 = r31.s64 + 16256;
	// bl 0x8238ec00
	ctx.lr = 0x8265CCC4;
	sub_8238EC00(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// bl 0x82250310
	ctx.lr = 0x8265CCE4;
	sub_82250310(ctx, base);
	// addis r30,r31,1
	r30.s64 = r31.s64 + 65536;
	// stw r29,3276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3276, r29.u32);
	// stw r29,3280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3280, r29.u32);
	// addi r30,r30,19760
	r30.s64 = r30.s64 + 19760;
	// stw r29,3284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3284, r29.u32);
	// stw r29,3216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3216, r29.u32);
	// addi r3,r30,1136
	ctx.r3.s64 = r30.s64 + 1136;
	// lwz r8,1136(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 1136);
	// lwz r7,336(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 336);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8265CD10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,1
	ctx.r6.s64 = 65536;
	// stw r3,3180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3180, ctx.r3.u32);
	// li r23,1
	r23.s64 = 1;
	// ori r5,r6,21616
	ctx.r5.u64 = ctx.r6.u64 | 21616;
	// lwzx r11,r31,r5
	r11.u64 = PPC_LOAD_U32(r31.u32 + ctx.r5.u32);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// stw r11,3196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3196, r11.u32);
	// stw r29,3208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3208, r29.u32);
	// blt cr6,0x8265cd38
	if (cr6.lt) goto loc_8265CD38;
	// stw r23,3208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3208, r23.u32);
loc_8265CD38:
	// lwz r11,1392(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1392);
	// addi r3,r30,1392
	ctx.r3.s64 = r30.s64 + 1392;
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265CD4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,3212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3212, ctx.r3.u32);
	// lwz r9,1392(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 1392);
	// addi r3,r30,1392
	ctx.r3.s64 = r30.s64 + 1392;
	// lwz r8,336(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 336);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265CD64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32111
	ctx.r7.s64 = -2104426496;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// addi r4,r6,2452
	ctx.r4.s64 = ctx.r6.s64 + 2452;
	// lwz r3,-24180(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -24180);
	// bl 0x821fd980
	ctx.lr = 0x8265CD80;
	sub_821FD980(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r3,r28,92
	ctx.r3.s64 = r28.s64 + 92;
	// addi r4,r5,32684
	ctx.r4.s64 = ctx.r5.s64 + 32684;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// stw r22,88(r28)
	PPC_STORE_U32(r28.u32 + 88, r22.u32);
	// bl 0x823dc018
	ctx.lr = 0x8265CD9C;
	sub_823DC018(ctx, base);
	// li r3,3
	ctx.r3.s64 = 3;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,156(r28)
	PPC_STORE_U32(r28.u32 + 156, ctx.r3.u32);
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265CDC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,92(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lwz r5,3212(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3212);
	// addi r4,r8,-5024
	ctx.r4.s64 = ctx.r8.s64 + -5024;
	// lwz r3,4(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x825ee0e0
	ctx.lr = 0x8265CDD8;
	sub_825EE0E0(ctx, base);
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82388c48
	ctx.lr = 0x8265CDE8;
	sub_82388C48(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// li r3,28
	ctx.r3.s64 = 28;
	// lwz r5,0(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r11,-3624(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -3624);
	// stw r5,3184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3184, ctx.r5.u32);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stw r4,3188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3188, ctx.r4.u32);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lbz r8,796(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 796);
	// stw r8,3248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3248, ctx.r8.u32);
	// lwz r7,700(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lbz r5,797(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + 797);
	// stw r5,3252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3252, ctx.r5.u32);
	// bl 0x82130528
	ctx.lr = 0x8265CE2C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8265ce84
	if (cr6.eq) goto loc_8265CE84;
	// li r9,255
	ctx.r9.s64 = 255;
	// lbz r10,1(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// stb r9,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r9.u8);
	// ori r8,r10,224
	ctx.r8.u64 = ctx.r10.u64 | 224;
	// stb r8,1(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1, ctx.r8.u8);
	// lbz r6,6(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// ori r5,r6,192
	ctx.r5.u64 = ctx.r6.u64 | 192;
	// lbz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// clrlwi r4,r7,25
	ctx.r4.u64 = ctx.r7.u32 & 0x7F;
	// stb r29,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, r29.u8);
	// stb r5,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, ctx.r5.u8);
	// stb r4,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r4.u8);
	// stw r29,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r29.u32);
	// stw r29,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r29.u32);
	// stw r29,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r29.u32);
	// stb r29,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, r29.u8);
	// stb r29,21(r3)
	PPC_STORE_U8(ctx.r3.u32 + 21, r29.u8);
	// stw r29,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r29.u32);
	// b 0x8265ce88
	goto loc_8265CE88;
loc_8265CE84:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8265CE88:
	// stw r3,3256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3256, ctx.r3.u32);
	// lis r11,1
	r11.s64 = 65536;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r9,r11,23056
	ctx.r9.u64 = r11.u64 | 23056;
	// ori r8,r10,22096
	ctx.r8.u64 = ctx.r10.u64 | 22096;
	// lis r7,2
	ctx.r7.s64 = 131072;
	// ori r6,r7,55136
	ctx.r6.u64 = ctx.r7.u64 | 55136;
	// lwzx r5,r31,r9
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// cntlzw r4,r5
	ctx.r4.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r11,r4,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// xori r10,r11,1
	ctx.r10.u64 = r11.u64 ^ 1;
	// stb r10,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, ctx.r10.u8);
	// lwzx r9,r31,r8
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + ctx.r8.u32);
	// lwz r8,3256(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3256);
	// stw r9,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r9.u32);
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r11,2816(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2816);
	// lbzx r6,r7,r6
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r6.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8265cee0
	if (cr6.eq) goto loc_8265CEE0;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_8265CEE0:
	// lwz r10,3256(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3256);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r4,r8,25344
	ctx.r4.u64 = ctx.r8.u64 | 25344;
	// ori r7,r9,22816
	ctx.r7.u64 = ctx.r9.u64 | 22816;
	// lis r6,1
	ctx.r6.s64 = 65536;
	// stw r11,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, r11.u32);
	// lis r5,1
	ctx.r5.s64 = 65536;
	// lwz r8,3256(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3256);
	// ori r11,r6,25584
	r11.u64 = ctx.r6.u64 | 25584;
	// ori r10,r5,25104
	ctx.r10.u64 = ctx.r5.u64 | 25104;
	// lwzx r9,r31,r7
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// addi r3,r30,4880
	ctx.r3.s64 = r30.s64 + 4880;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// stb r5,21(r8)
	PPC_STORE_U8(ctx.r8.u32 + 21, ctx.r5.u8);
	// lwzx r29,r31,r4
	r29.u64 = PPC_LOAD_U32(r31.u32 + ctx.r4.u32);
	// lwz r4,4880(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4880);
	// lwzx r27,r31,r11
	r27.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwzx r28,r31,r10
	r28.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// lwz r11,336(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 336);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8265CF40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,4624(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4624);
	// addi r11,r30,4624
	r11.s64 = r30.s64 + 4624;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,336(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 336);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265CF5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,3256(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3256);
	// cntlzw r8,r27
	ctx.r8.u64 = r27.u32 == 0 ? 32 : __builtin_clz(r27.u32);
	// cntlzw r7,r29
	ctx.r7.u64 = r29.u32 == 0 ? 32 : __builtin_clz(r29.u32);
	// rlwinm r6,r8,2,24,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x80;
	// rlwinm r9,r7,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// lbz r4,6(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// cntlzw r5,r28
	ctx.r5.u64 = r28.u32 == 0 ? 32 : __builtin_clz(r28.u32);
	// xori r10,r6,128
	ctx.r10.u64 = ctx.r6.u64 ^ 128;
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi r7,r4,26
	ctx.r7.u64 = ctx.r4.u32 & 0x3F;
	// stb r3,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r3.u8);
	// rlwinm r5,r5,2,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x80;
	// lis r6,0
	ctx.r6.s64 = 0;
	// or r4,r10,r7
	ctx.r4.u64 = ctx.r10.u64 | ctx.r7.u64;
	// xori r10,r9,1
	ctx.r10.u64 = ctx.r9.u64 ^ 1;
	// xori r7,r5,128
	ctx.r7.u64 = ctx.r5.u64 ^ 128;
	// ori r9,r6,60000
	ctx.r9.u64 = ctx.r6.u64 | 60000;
	// clrlwi r8,r8,25
	ctx.r8.u64 = ctx.r8.u32 & 0x7F;
	// mullw r5,r30,r9
	ctx.r5.s64 = int64_t(r30.s32) * int64_t(ctx.r9.s32);
	// stw r5,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r5.u32);
	// or r3,r8,r7
	ctx.r3.u64 = ctx.r8.u64 | ctx.r7.u64;
	// rlwimi r4,r10,6,25,25
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r10.u32, 6) & 0x40) | (ctx.r4.u64 & 0xFFFFFFFFFFFFFFBF);
	// stb r3,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r3.u8);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// stb r4,6(r11)
	PPC_STORE_U8(r11.u32 + 6, ctx.r4.u8);
	// lis r11,1
	r11.s64 = 65536;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// lis r30,1
	r30.s64 = 65536;
	// ori r29,r11,27024
	r29.u64 = r11.u64 | 27024;
	// ori r8,r9,25824
	ctx.r8.u64 = ctx.r9.u64 | 25824;
	// ori r30,r30,26544
	r30.u64 = r30.u64 | 26544;
	// lis r7,1
	ctx.r7.s64 = 65536;
	// lis r6,1
	ctx.r6.s64 = 65536;
	// lis r5,1
	ctx.r5.s64 = 65536;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// lis r3,1
	ctx.r3.s64 = 65536;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// lis r28,1
	r28.s64 = 65536;
	// ori r7,r7,28224
	ctx.r7.u64 = ctx.r7.u64 | 28224;
	// ori r6,r6,27984
	ctx.r6.u64 = ctx.r6.u64 | 27984;
	// ori r5,r5,27744
	ctx.r5.u64 = ctx.r5.u64 | 27744;
	// ori r4,r4,27504
	ctx.r4.u64 = ctx.r4.u64 | 27504;
	// ori r3,r3,27264
	ctx.r3.u64 = ctx.r3.u64 | 27264;
	// ori r9,r9,26784
	ctx.r9.u64 = ctx.r9.u64 | 26784;
	// lis r26,1
	r26.s64 = 65536;
	// lwz r11,3256(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3256);
	// ori r28,r28,26304
	r28.u64 = r28.u64 | 26304;
	// lwzx r8,r31,r8
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + ctx.r8.u32);
	// lwzx r30,r31,r30
	r30.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// lbz r27,0(r11)
	r27.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// ori r26,r26,26064
	r26.u64 = r26.u64 | 26064;
	// lwzx r28,r31,r28
	r28.u64 = PPC_LOAD_U32(r31.u32 + r28.u32);
	// cntlzw r8,r8
	ctx.r8.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwzx r9,r31,r9
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// cntlzw r28,r28
	r28.u64 = r28.u32 == 0 ? 32 : __builtin_clz(r28.u32);
	// lwzx r6,r31,r6
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + ctx.r6.u32);
	// lwzx r3,r31,r3
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r3.u32);
	// rlwinm r8,r8,2,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x80;
	// lwzx r5,r31,r5
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + ctx.r5.u32);
	// clrlwi r27,r27,25
	r27.u64 = r27.u32 & 0x7F;
	// lwzx r26,r31,r26
	r26.u64 = PPC_LOAD_U32(r31.u32 + r26.u32);
	// xori r8,r8,128
	ctx.r8.u64 = ctx.r8.u64 ^ 128;
	// lwzx r7,r31,r7
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// cntlzw r30,r30
	r30.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// lwzx r4,r31,r4
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r4.u32);
	// cntlzw r26,r26
	r26.u64 = r26.u32 == 0 ? 32 : __builtin_clz(r26.u32);
	// lwzx r31,r31,r29
	r31.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// rlwinm r29,r28,27,31,31
	r29.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 27) & 0x1;
	// rlwinm r28,r26,28,30,30
	r28.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 28) & 0x2;
	// xori r29,r29,1
	r29.u64 = r29.u64 ^ 1;
	// xori r28,r28,2
	r28.u64 = r28.u64 ^ 2;
	// or r8,r8,r27
	ctx.r8.u64 = ctx.r8.u64 | r27.u64;
	// or r29,r28,r29
	r29.u64 = r28.u64 | r29.u64;
	// rlwinm r30,r30,27,31,31
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 27) & 0x1;
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// cntlzw r9,r9
	ctx.r9.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r8,r29,1,24,30
	ctx.r8.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFE;
	// xori r30,r30,1
	r30.u64 = r30.u64 ^ 1;
	// rlwinm r9,r9,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// or r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 | r30.u64;
	// xori r9,r9,1
	ctx.r9.u64 = ctx.r9.u64 ^ 1;
	// rlwinm r8,r8,1,24,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFE;
	// cntlzw r31,r31
	r31.u64 = r31.u32 == 0 ? 32 : __builtin_clz(r31.u32);
	// or r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 | ctx.r9.u64;
	// rlwinm r9,r31,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 27) & 0x1;
	// rlwinm r8,r8,1,24,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFE;
	// xori r9,r9,1
	ctx.r9.u64 = ctx.r9.u64 ^ 1;
	// cntlzw r3,r3
	ctx.r3.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
	// rlwinm r8,r3,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// lbz r3,1(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// cntlzw r7,r7
	ctx.r7.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// xori r8,r8,1
	ctx.r8.u64 = ctx.r8.u64 ^ 1;
	// cntlzw r5,r5
	ctx.r5.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r9,r9,1,24,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFE;
	// cntlzw r6,r6
	ctx.r6.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// lbz r31,0(r11)
	r31.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// rlwinm r7,r7,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// or r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 | ctx.r8.u64;
	// rlwinm r5,r5,2,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0x80;
	// cntlzw r8,r4
	ctx.r8.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// xori r4,r7,1
	ctx.r4.u64 = ctx.r7.u64 ^ 1;
	// rlwinm r6,r6,28,30,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0x2;
	// xori r7,r5,128
	ctx.r7.u64 = ctx.r5.u64 ^ 128;
	// clrlwi r5,r3,27
	ctx.r5.u64 = ctx.r3.u32 & 0x1F;
	// rlwinm r3,r9,1,24,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFE;
	// xori r6,r6,2
	ctx.r6.u64 = ctx.r6.u64 ^ 2;
	// rlwinm r9,r31,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0xFFFFFF80;
	// rlwinm r8,r8,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// or r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 | ctx.r4.u64;
	// or r5,r7,r5
	ctx.r5.u64 = ctx.r7.u64 | ctx.r5.u64;
	// or r4,r3,r9
	ctx.r4.u64 = ctx.r3.u64 | ctx.r9.u64;
	// xori r3,r8,1
	ctx.r3.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r8,r5,24
	ctx.r8.u64 = ctx.r5.u32 & 0xFF;
	// rlwinm r9,r6,5,24,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xE0;
	// rlwinm r8,r8,0,27,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFF9F;
	// or r7,r4,r3
	ctx.r7.u64 = ctx.r4.u64 | ctx.r3.u64;
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stb r7,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r7.u8);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// stb r6,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r6.u8);
	// stw r23,3228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3228, r23.u32);
	// bl 0x826589d8
	ctx.lr = 0x8265D148;
	sub_826589D8(ctx, base);
	// lwz r5,3188(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 3188);
	// addi r11,r5,-1
	r11.s64 = ctx.r5.s64 + -1;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x8265d1d0
	if (cr6.gt) goto loc_8265D1D0;
	// lis r12,-32154
	r12.s64 = -2107244544;
	// addi r12,r12,-11920
	r12.s64 = r12.s64 + -11920;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8265D184;
	case 1:
		goto loc_8265D190;
	case 2:
		goto loc_8265D19C;
	case 3:
		goto loc_8265D1D0;
	case 4:
		goto loc_8265D1A8;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-11900(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -11900);
	// lwz r19,-11888(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -11888);
	// lwz r19,-11876(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -11876);
	// lwz r19,-11824(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -11824);
	// lwz r19,-11864(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -11864);
loc_8265D184:
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,2444
	ctx.r4.s64 = ctx.r10.s64 + 2444;
	// b 0x8265d1b0
	goto loc_8265D1B0;
loc_8265D190:
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,2436
	ctx.r4.s64 = ctx.r10.s64 + 2436;
	// b 0x8265d1b0
	goto loc_8265D1B0;
loc_8265D19C:
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,2428
	ctx.r4.s64 = ctx.r10.s64 + 2428;
	// b 0x8265d1b0
	goto loc_8265D1B0;
loc_8265D1A8:
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,2420
	ctx.r4.s64 = ctx.r10.s64 + 2420;
loc_8265D1B0:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265D1D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8265D1D0:
	// bl 0x822150d8
	ctx.lr = 0x8265D1D4;
	sub_822150D8(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r8,3800
	ctx.r8.s64 = 3800;
	// addi r3,r11,2396
	ctx.r3.s64 = r11.s64 + 2396;
	// li r7,3208
	ctx.r7.s64 = 3208;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82727908
	ctx.lr = 0x8265D1F4;
	sub_82727908(ctx, base);
	// addi r1,r1,3376
	ctx.r1.s64 = ctx.r1.s64 + 3376;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8265D1FC"))) PPC_WEAK_FUNC(sub_8265D1FC);
PPC_FUNC_IMPL(__imp__sub_8265D1FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265D200"))) PPC_WEAK_FUNC(sub_8265D200);
PPC_FUNC_IMPL(__imp__sub_8265D200) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,17
	ctx.r4.s64 = 17;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8265D22C;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r9,8532(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 8532);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8265d298
	if (cr6.eq) goto loc_8265D298;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265D24C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x8265d288
	if (cr6.eq) goto loc_8265D288;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265D268;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8265d288
	if (cr6.eq) goto loc_8265D288;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265D284;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8265d28c
	goto loc_8265D28C;
loc_8265D288:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8265D28C:
	// bl 0x8265cc20
	ctx.lr = 0x8265D290;
	sub_8265CC20(ctx, base);
	// bl 0x82216648
	ctx.lr = 0x8265D294;
	sub_82216648(ctx, base);
	// bl 0x822150d8
	ctx.lr = 0x8265D298;
	sub_822150D8(ctx, base);
loc_8265D298:
	// li r11,0
	r11.s64 = 0;
	// stb r11,8532(r31)
	PPC_STORE_U8(r31.u32 + 8532, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265D2B4"))) PPC_WEAK_FUNC(sub_8265D2B4);
PPC_FUNC_IMPL(__imp__sub_8265D2B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265D2B8"))) PPC_WEAK_FUNC(sub_8265D2B8);
PPC_FUNC_IMPL(__imp__sub_8265D2B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r21{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x8265D2C0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// bl 0x821f88b8
	ctx.lr = 0x8265D2CC;
	sub_821F88B8(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,-10016(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// lwz r11,76(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// lbz r22,8532(r25)
	r22.u64 = PPC_LOAD_U8(r25.u32 + 8532);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8265d394
	if (!cr6.gt) goto loc_8265D394;
	// bl 0x8265e5e8
	ctx.lr = 0x8265D2E8;
	sub_8265E5E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265d394
	if (cr6.eq) goto loc_8265D394;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r29,17268(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8265d394
	if (cr6.eq) goto loc_8265D394;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,18508(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 18508);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265d394
	if (cr6.eq) goto loc_8265D394;
	// lwz r11,-10016(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265d394
	if (cr6.eq) goto loc_8265D394;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8265D32C;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265d394
	if (cr6.eq) goto loc_8265D394;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a3998
	ctx.lr = 0x8265D344;
	sub_822A3998(ctx, base);
	// lwz r11,-10016(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82706998
	ctx.lr = 0x8265D358;
	sub_82706998(ctx, base);
	// lwz r11,-10016(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// lwz r3,18508(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 18508);
	// lwz r4,76(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// bl 0x826b94a8
	ctx.lr = 0x8265D368;
	sub_826B94A8(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8265d394
	if (cr6.eq) goto loc_8265D394;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-14960
	ctx.r4.s64 = ctx.r10.s64 + -14960;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265D394;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8265D394:
	// lis r24,-32121
	r24.s64 = -2105081856;
	// lis r11,1
	r11.s64 = 65536;
	// lis r23,-32121
	r23.s64 = -2105081856;
	// ori r9,r11,22096
	ctx.r9.u64 = r11.u64 | 22096;
	// lwz r11,-3624(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -3624);
	// lwz r10,-10236(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + -10236);
	// lwz r8,700(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r7,48(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// addis r29,r7,1
	r29.s64 = ctx.r7.s64 + 65536;
	// lwz r11,8(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// addi r29,r29,16256
	r29.s64 = r29.s64 + 16256;
	// addis r21,r29,2
	r21.s64 = r29.s64 + 131072;
	// lbz r6,796(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 796);
	// addi r21,r21,-27616
	r21.s64 = r21.s64 + -27616;
	// lwzx r10,r29,r9
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + ctx.r9.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8265d3e4
	if (!cr6.eq) goto loc_8265D3E4;
	// lbz r11,797(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 797);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265d3e8
	if (cr6.eq) goto loc_8265D3E8;
loc_8265D3E4:
	// li r10,1
	ctx.r10.s64 = 1;
loc_8265D3E8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265d430
	if (cr6.eq) goto loc_8265D430;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// lis r10,6
	ctx.r10.s64 = 393216;
	// ori r8,r10,16960
	ctx.r8.u64 = ctx.r10.u64 | 16960;
	// blt cr6,0x8265d424
	if (cr6.lt) goto loc_8265D424;
	// beq cr6,0x8265d418
	if (cr6.eq) goto loc_8265D418;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// b 0x8265d42c
	goto loc_8265D42C;
loc_8265D418:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,14884(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f0.f64 = double(temp.f32);
	// b 0x8265d42c
	goto loc_8265D42C;
loc_8265D424:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8265D42C:
	// stfsx f0,r11,r8
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, temp.u32);
loc_8265D430:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8265D43C;
	sub_8238EC00(ctx, base);
	// addis r30,r29,2
	r30.s64 = r29.s64 + 131072;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r30,r30,-32640
	r30.s64 = r30.s64 + -32640;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,784(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 784);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265D45C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8265b430
	ctx.lr = 0x8265D468;
	sub_8265B430(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r31,-32111
	r31.s64 = -2104426496;
	// addi r28,r11,2488
	r28.s64 = r11.s64 + 2488;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,-24180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -24180);
	// bl 0x822c7030
	ctx.lr = 0x8265D484;
	sub_822C7030(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// stw r7,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r7.u32);
	// addi r5,r30,976
	ctx.r5.s64 = r30.s64 + 976;
	// lhz r11,3992(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 3992);
	// sth r11,92(r3)
	PPC_STORE_U16(ctx.r3.u32 + 92, r11.u16);
	// stw r6,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r6.u32);
	// lwz r4,864(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 864);
	// cmplw cr6,r4,r5
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r5.u32, xer);
	// bne cr6,0x8265d4c0
	if (!cr6.eq) goto loc_8265D4C0;
	// addis r3,r29,2
	ctx.r3.s64 = r29.s64 + 131072;
	// addi r3,r3,-31968
	ctx.r3.s64 = ctx.r3.s64 + -31968;
	// bl 0x82631f88
	ctx.lr = 0x8265D4BC;
	sub_82631F88(ctx, base);
	// b 0x8265d5d0
	goto loc_8265D5D0;
loc_8265D4C0:
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265d560
	if (cr6.eq) goto loc_8265D560;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8238ebf8
	ctx.lr = 0x8265D4DC;
	sub_8238EBF8(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lwz r3,-24180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -24180);
	// addi r4,r11,2476
	ctx.r4.s64 = r11.s64 + 2476;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x821fde78
	ctx.lr = 0x8265D4F0;
	sub_821FDE78(ctx, base);
	// addis r11,r29,1
	r11.s64 = r29.s64 + 65536;
	// addi r11,r11,19760
	r11.s64 = r11.s64 + 19760;
	// addi r3,r11,1392
	ctx.r3.s64 = r11.s64 + 1392;
	// lwz r10,1392(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 1392);
	// lwz r9,336(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 336);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265D50C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-24180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -24180);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// addi r4,r8,2452
	ctx.r4.s64 = ctx.r8.s64 + 2452;
	// bl 0x821fde78
	ctx.lr = 0x8265D524;
	sub_821FDE78(ctx, base);
	// lis r7,1
	ctx.r7.s64 = 65536;
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// lwz r3,-24180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -24180);
	// ori r5,r7,21616
	ctx.r5.u64 = ctx.r7.u64 | 21616;
	// addi r4,r6,2464
	ctx.r4.s64 = ctx.r6.s64 + 2464;
	// lwzx r5,r29,r5
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + ctx.r5.u32);
	// bl 0x821fde78
	ctx.lr = 0x8265D540;
	sub_821FDE78(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x826304b0
	ctx.lr = 0x8265D54C;
	sub_826304B0(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,-24180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -24180);
	// bl 0x822c7138
	ctx.lr = 0x8265D55C;
	sub_822C7138(ctx, base);
	// b 0x8265d5d0
	goto loc_8265D5D0;
loc_8265D560:
	// lwz r11,-3624(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -3624);
	// lwz r11,700(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lbz r10,796(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 796);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8265d58c
	if (!cr6.eq) goto loc_8265D58C;
	// lbz r11,797(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 797);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8265d58c
	if (!cr6.eq) goto loc_8265D58C;
	// addi r31,r25,8536
	r31.s64 = r25.s64 + 8536;
	// b 0x8265d5a8
	goto loc_8265D5A8;
loc_8265D58C:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x827057e0
	ctx.lr = 0x8265D598;
	sub_827057E0(ctx, base);
	// lwz r4,8536(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 8536);
	// addi r31,r25,8536
	r31.s64 = r25.s64 + 8536;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// bne cr6,0x8265d5c8
	if (!cr6.eq) goto loc_8265D5C8;
loc_8265D5A8:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823895f8
	ctx.lr = 0x8265D5B8;
	sub_823895F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265d5d0
	if (cr6.eq) goto loc_8265D5D0;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_8265D5C8:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8265cc90
	ctx.lr = 0x8265D5D0;
	sub_8265CC90(ctx, base);
loc_8265D5D0:
	// lwz r11,-10236(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -10236);
	// lis r10,2
	ctx.r10.s64 = 131072;
	// lfs f1,1184(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r21.u32 + 1184);
	ctx.f1.f64 = double(temp.f32);
	// ori r9,r10,55136
	ctx.r9.u64 = ctx.r10.u64 | 55136;
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8265d5fc
	if (cr6.eq) goto loc_8265D5FC;
	// lwz r11,2816(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 2816);
	// addi r3,r11,-1
	ctx.r3.s64 = r11.s64 + -1;
	// b 0x8265d600
	goto loc_8265D600;
loc_8265D5FC:
	// lwz r3,2816(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 2816);
loc_8265D600:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r31,-7572(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x8238eb90
	ctx.lr = 0x8265D60C;
	sub_8238EB90(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f2,30712(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x822f1518
	ctx.lr = 0x8265D61C;
	sub_822F1518(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82656998
	ctx.lr = 0x8265D624;
	sub_82656998(ctx, base);
	// lwz r9,0(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r8,736(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 736);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265D638;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,74
	ctx.r4.s64 = 74;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8265D644;
	sub_82641CB0(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,736(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 736);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8265D654;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8265D660;
	sub_82641CB0(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,736(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 736);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8265D670;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,19
	ctx.r4.s64 = 19;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8265D67C;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265D68C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,71
	ctx.r4.s64 = 71;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8265D698;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,736(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 736);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265D6A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r3,r7,-1304
	ctx.r3.s64 = ctx.r7.s64 + -1304;
	// bl 0x821fa230
	ctx.lr = 0x8265D6B4;
	sub_821FA230(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,108(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 108);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8265D6C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265D6E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265D6F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// addi r6,r7,-12580
	ctx.r6.s64 = ctx.r7.s64 + -12580;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8265d740
	if (!cr6.eq) goto loc_8265D740;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// ori r31,r11,4672
	r31.u64 = r11.u64 | 4672;
	// addi r29,r10,-2524
	r29.s64 = ctx.r10.s64 + -2524;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82219fe8
	ctx.lr = 0x8265D72C;
	sub_82219FE8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82218d38
	ctx.lr = 0x8265D734;
	sub_82218D38(ctx, base);
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x8221a440
	ctx.lr = 0x8265D740;
	sub_8221A440(ctx, base);
loc_8265D740:
	// li r3,25
	ctx.r3.s64 = 25;
	// bl 0x82216138
	ctx.lr = 0x8265D748;
	sub_82216138(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// stb r11,-12456(r10)
	PPC_STORE_U8(ctx.r10.u32 + -12456, r11.u8);
	// lwz r3,-12012(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12012);
	// bl 0x821f15c8
	ctx.lr = 0x8265D760;
	sub_821F15C8(ctx, base);
	// bl 0x821e60c0
	ctx.lr = 0x8265D764;
	sub_821E60C0(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8265D76C"))) PPC_WEAK_FUNC(sub_8265D76C);
PPC_FUNC_IMPL(__imp__sub_8265D76C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265D770"))) PPC_WEAK_FUNC(sub_8265D770);
PPC_FUNC_IMPL(__imp__sub_8265D770) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8265D778;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r11,-12776
	ctx.r4.s64 = r11.s64 + -12776;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r29,r10,-7660
	r29.s64 = ctx.r10.s64 + -7660;
	// addi r28,r9,-22108
	r28.s64 = ctx.r9.s64 + -22108;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8265D7AC;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8265D7C0;
	sub_823DEDD8(ctx, base);
	// lwz r29,864(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 864);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x8265d824
	if (cr6.eq) goto loc_8265D824;
	// addi r3,r30,672
	ctx.r3.s64 = r30.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x8265D7D8;
	sub_82631F88(ctx, base);
	// lwz r11,856(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8265d7e8
	if (cr6.lt) goto loc_8265D7E8;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8265D7E8:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265D804;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8265d824
	if (!cr6.eq) goto loc_8265D824;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x8265D818;
	sub_821E6800(ctx, base);
loc_8265D818:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8265D824:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8265d83c
	if (cr6.eq) goto loc_8265D83C;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lbz r10,27964(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 27964);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8265d818
	if (!cr6.eq) goto loc_8265D818;
loc_8265D83C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// bl 0x821f9fb8
	ctx.lr = 0x8265D84C;
	sub_821F9FB8(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r27,56(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r31,r10,1
	r31.s64 = ctx.r10.s64 + 65536;
	// addi r31,r31,16256
	r31.s64 = r31.s64 + 16256;
	// bl 0x82387a18
	ctx.lr = 0x8265D864;
	sub_82387A18(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8265d89c
	if (!cr6.eq) goto loc_8265D89C;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-2500
	ctx.r3.s64 = r11.s64 + -2500;
	// bl 0x821fa230
	ctx.lr = 0x8265D880;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,104(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265D890;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8265d9f8
	if (cr6.eq) goto loc_8265D9F8;
loc_8265D89C:
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// lwz r11,700(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r11,r9,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// mr r26,r11
	r26.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265d928
	if (cr6.eq) goto loc_8265D928;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8265D8C8;
	sub_822A39C8(ctx, base);
	// lwz r28,1220(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82203310
	ctx.lr = 0x8265D8D4;
	sub_82203310(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8265d928
	if (cr6.eq) goto loc_8265D928;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822577d0
	ctx.lr = 0x8265D8EC;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8265d928
	if (cr6.eq) goto loc_8265D928;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8265D900;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r10,196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265D914;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8265D920;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x8265db3c
	goto loc_8265DB3C;
loc_8265D928:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8265d9f8
	if (cr6.eq) goto loc_8265D9F8;
	// lwz r11,864(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 864);
	// addi r28,r30,976
	r28.s64 = r30.s64 + 976;
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// bne cr6,0x8265d950
	if (!cr6.eq) goto loc_8265D950;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82655ff8
	ctx.lr = 0x8265D948;
	sub_82655FF8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8265d954
	goto loc_8265D954;
loc_8265D950:
	// li r31,0
	r31.s64 = 0;
loc_8265D954:
	// lwz r11,864(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 864);
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// bne cr6,0x8265d96c
	if (!cr6.eq) goto loc_8265D96C;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r11,-8672
	ctx.r3.s64 = r11.s64 + -8672;
	// b 0x8265d980
	goto loc_8265D980;
loc_8265D96C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265D980;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8265D980:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x8265D988;
	sub_821C9790(ctx, base);
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x82282580
	ctx.lr = 0x8265D99C;
	sub_82282580(ctx, base);
	// li r3,25
	ctx.r3.s64 = 25;
	// bl 0x82216138
	ctx.lr = 0x8265D9A4;
	sub_82216138(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-12580
	ctx.r10.s64 = r11.s64 + -12580;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8265db4c
	if (!cr6.eq) goto loc_8265DB4C;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,5
	r11.s64 = 327680;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// ori r31,r11,4672
	r31.u64 = r11.u64 | 4672;
	// addi r29,r10,-2636
	r29.s64 = ctx.r10.s64 + -2636;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82219fe8
	ctx.lr = 0x8265D9D8;
	sub_82219FE8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82218d38
	ctx.lr = 0x8265D9E0;
	sub_82218D38(ctx, base);
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x8221a440
	ctx.lr = 0x8265D9EC;
	sub_8221A440(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8265D9F8:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-5016
	ctx.r3.s64 = r11.s64 + -5016;
	// bl 0x821fa230
	ctx.lr = 0x8265DA04;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,104(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265DA14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8265db14
	if (cr6.eq) goto loc_8265DB14;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r27,-32111
	r27.s64 = -2104426496;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r28,r11,2532
	r28.s64 = r11.s64 + 2532;
	// addi r4,r10,2516
	ctx.r4.s64 = ctx.r10.s64 + 2516;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r3,-24180(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -24180);
	// bl 0x8220ef00
	ctx.lr = 0x8265DA40;
	sub_8220EF00(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r30,92
	ctx.r3.s64 = r30.s64 + 92;
	// bl 0x823db670
	ctx.lr = 0x8265DA54;
	sub_823DB670(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stw r28,156(r30)
	PPC_STORE_U32(r30.u32 + 156, r28.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-9136
	ctx.r4.s64 = ctx.r9.s64 + -9136;
	// lwz r3,-24180(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -24180);
	// bl 0x821fde78
	ctx.lr = 0x8265DA70;
	sub_821FDE78(ctx, base);
	// bl 0x82387b38
	ctx.lr = 0x8265DA74;
	sub_82387B38(ctx, base);
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// li r8,1
	ctx.r8.s64 = 1;
	// addis r30,r31,1
	r30.s64 = r31.s64 + 65536;
	// addi r30,r30,19760
	r30.s64 = r30.s64 + 19760;
	// lwz r7,700(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// stb r8,796(r6)
	PPC_STORE_U8(ctx.r6.u32 + 796, ctx.r8.u8);
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// lwz r5,700(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r4,8(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// stb r28,797(r4)
	PPC_STORE_U8(ctx.r4.u32 + 797, r28.u8);
	// bl 0x826583c0
	ctx.lr = 0x8265DAA8;
	sub_826583C0(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r3,22368
	ctx.r3.s64 = ctx.r3.s64 + 22368;
	// bl 0x8262fff0
	ctx.lr = 0x8265DAB8;
	sub_8262FFF0(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r3,22608
	ctx.r3.s64 = ctx.r3.s64 + 22608;
	// bl 0x8262fff0
	ctx.lr = 0x8265DAC8;
	sub_8262FFF0(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r3,21648
	ctx.r3.s64 = ctx.r3.s64 + 21648;
	// bl 0x8262fff0
	ctx.lr = 0x8265DAD8;
	sub_8262FFF0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8265d2b8
	ctx.lr = 0x8265DAE0;
	sub_8265D2B8(ctx, base);
	// lis r3,-32115
	ctx.r3.s64 = -2104688640;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r11,2508
	ctx.r4.s64 = r11.s64 + 2508;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-12440(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -12440);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265DB08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8265DB14:
	// addis r31,r31,1
	r31.s64 = r31.s64 + 65536;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r31,r31,19760
	r31.s64 = r31.s64 + 19760;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265DB34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8265DB3C:
	// lwz r8,704(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 704);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265DB4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8265DB4C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8265DB58"))) PPC_WEAK_FUNC(sub_8265DB58);
PPC_FUNC_IMPL(__imp__sub_8265DB58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8265DB60;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265DB7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8265dbf0
	if (!cr6.eq) goto loc_8265DBF0;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r10,432(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 432);
	// addi r9,r11,28124
	ctx.r9.s64 = r11.s64 + 28124;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x8265dbf0
	if (!cr6.eq) goto loc_8265DBF0;
	// lis r31,-32111
	r31.s64 = -2104426496;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-9136
	ctx.r4.s64 = r11.s64 + -9136;
	// lwz r3,-24180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -24180);
	// bl 0x821fde78
	ctx.lr = 0x8265DBB0;
	sub_821FDE78(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,-24180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -24180);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r29,r10,3998
	r29.s64 = ctx.r10.s64 + 3998;
	// addi r4,r9,2516
	ctx.r4.s64 = ctx.r9.s64 + 2516;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x8220ef00
	ctx.lr = 0x8265DBCC;
	sub_8220EF00(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x823db670
	ctx.lr = 0x8265DBE0;
	sub_823DB670(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r8,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r8.u32);
	// bl 0x8265d2b8
	ctx.lr = 0x8265DBF0;
	sub_8265D2B8(ctx, base);
loc_8265DBF0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8265DBF8"))) PPC_WEAK_FUNC(sub_8265DBF8);
PPC_FUNC_IMPL(__imp__sub_8265DBF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r20{};
	PPCRegister r21{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x8265DC00;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x8265DC24;
	sub_821F9FB8(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r28,56(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r25,r10,16256
	r25.u64 = ctx.r10.u64 | 16256;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// ori r26,r9,37920
	r26.u64 = ctx.r9.u64 | 37920;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// add r20,r7,r25
	r20.u64 = ctx.r7.u64 + r25.u64;
	// addi r4,r8,-12776
	ctx.r4.s64 = ctx.r8.s64 + -12776;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// add r22,r20,r26
	r22.u64 = r20.u64 + r26.u64;
	// addi r24,r6,-7660
	r24.s64 = ctx.r6.s64 + -7660;
	// addi r23,r5,-22108
	r23.s64 = ctx.r5.s64 + -22108;
	// bl 0x82691650
	ctx.lr = 0x8265DC6C;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8265DC80;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8265dca4
	if (cr6.eq) goto loc_8265DCA4;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lbz r10,27964(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 27964);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8265dca4
	if (cr6.eq) goto loc_8265DCA4;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9228
	return;
loc_8265DCA4:
	// cmpwi cr6,r29,55
	cr6.compare<int32_t>(r29.s32, 55, xer);
	// beq cr6,0x8265dda0
	if (cr6.eq) goto loc_8265DDA0;
	// cmpwi cr6,r29,56
	cr6.compare<int32_t>(r29.s32, 56, xer);
	// beq cr6,0x8265dd60
	if (cr6.eq) goto loc_8265DD60;
	// cmpwi cr6,r29,62
	cr6.compare<int32_t>(r29.s32, 62, xer);
	// beq cr6,0x8265dcd4
	if (cr6.eq) goto loc_8265DCD4;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826537d0
	ctx.lr = 0x8265DCCC;
	sub_826537D0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9228
	return;
loc_8265DCD4:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8265DCE0;
	sub_821E6800(ctx, base);
	// addis r31,r20,1
	r31.s64 = r20.s64 + 65536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r31,r31,30112
	r31.s64 = r31.s64 + 30112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,196(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265DD00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32154
	ctx.r8.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r8,-20600
	ctx.r4.s64 = ctx.r8.s64 + -20600;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2fb0
	ctx.lr = 0x8265DD1C;
	sub_821C2FB0(ctx, base);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// ld r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// ld r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// addi r6,r7,30784
	ctx.r6.s64 = ctx.r7.s64 + 30784;
	// addi r5,r5,30764
	ctx.r5.s64 = ctx.r5.s64 + 30764;
	// stb r11,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r11.u8);
	// li r7,3
	ctx.r7.s64 = 3;
	// rldicr r10,r10,32,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82634ec8
	ctx.lr = 0x8265DD54;
	sub_82634EC8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9228
	return;
loc_8265DD60:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8265DD6C;
	sub_821E6800(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826304b0
	ctx.lr = 0x8265DD78;
	sub_826304B0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826583c0
	ctx.lr = 0x8265DD80;
	sub_826583C0(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265DD94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9228
	return;
loc_8265DDA0:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8265DDAC;
	sub_821E6800(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-4944(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4944);
	// lwz r9,32(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8265de48
	if (cr6.eq) goto loc_8265DE48;
	// rotlwi r11,r9,0
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lhz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8265de48
	if (!cr6.gt) goto loc_8265DE48;
	// addis r31,r20,1
	r31.s64 = r20.s64 + 65536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r31,r31,30112
	r31.s64 = r31.s64 + 30112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265DDF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32154
	ctx.r9.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r9,-9384
	ctx.r4.s64 = ctx.r9.s64 + -9384;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821c2fb0
	ctx.lr = 0x8265DE0C;
	sub_821C2FB0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r6,r8,2636
	ctx.r6.s64 = ctx.r8.s64 + 2636;
	// ld r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// addi r5,r7,2608
	ctx.r5.s64 = ctx.r7.s64 + 2608;
	// ld r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// rldicr r9,r11,32,63
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826350b8
	ctx.lr = 0x8265DE3C;
	sub_826350B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9228
	return;
loc_8265DE48:
	// lbz r11,961(r22)
	r11.u64 = PPC_LOAD_U8(r22.u32 + 961);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// ori r21,r10,32896
	r21.u64 = ctx.r10.u64 | 32896;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265e1b8
	if (cr6.eq) goto loc_8265E1B8;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r3,r30,2608
	ctx.r3.s64 = r30.s64 + 2608;
	// lwz r11,-10240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r31,4304(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x826568d8
	ctx.lr = 0x8265DE74;
	sub_826568D8(ctx, base);
	// stw r3,224(r28)
	PPC_STORE_U32(r28.u32 + 224, ctx.r3.u32);
	// addi r3,r30,1888
	ctx.r3.s64 = r30.s64 + 1888;
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x826568d8
	ctx.lr = 0x8265DE84;
	sub_826568D8(ctx, base);
	// stw r3,300(r28)
	PPC_STORE_U32(r28.u32 + 300, ctx.r3.u32);
	// addi r3,r30,2368
	ctx.r3.s64 = r30.s64 + 2368;
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x826568d8
	ctx.lr = 0x8265DE94;
	sub_826568D8(ctx, base);
	// stw r3,376(r28)
	PPC_STORE_U32(r28.u32 + 376, ctx.r3.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,3776(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 3776);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r8,680(r10)
	PPC_STORE_U32(ctx.r10.u32 + 680, ctx.r8.u32);
	// lbz r7,961(r22)
	ctx.r7.u64 = PPC_LOAD_U8(r22.u32 + 961);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8265dec8
	if (cr6.eq) goto loc_8265DEC8;
	// lbz r11,960(r22)
	r11.u64 = PPC_LOAD_U8(r22.u32 + 960);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8265decc
	if (cr6.eq) goto loc_8265DECC;
loc_8265DEC8:
	// li r11,0
	r11.s64 = 0;
loc_8265DECC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265e0ac
	if (cr6.eq) goto loc_8265E0AC;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82654ac8
	ctx.lr = 0x8265DEE0;
	sub_82654AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265def8
	if (cr6.eq) goto loc_8265DEF8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,528(r11)
	PPC_STORE_U32(r11.u32 + 528, ctx.r10.u32);
loc_8265DEF8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r30,4624
	ctx.r3.s64 = r30.s64 + 4624;
	// lwz r10,3056(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 3056);
	// stw r10,452(r11)
	PPC_STORE_U32(r11.u32 + 452, ctx.r10.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,5344(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 5344);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// stw r5,1896(r9)
	PPC_STORE_U32(ctx.r9.u32 + 1896, ctx.r5.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,5824(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 5824);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// stw r8,1972(r4)
	PPC_STORE_U32(ctx.r4.u32 + 1972, ctx.r8.u32);
	// lwz r7,4624(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4624);
	// lwz r6,336(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 336);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8265DF48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r30,4880
	ctx.r3.s64 = r30.s64 + 4880;
	// extsb r11,r4
	r11.s64 = ctx.r4.s8;
	// stw r11,2048(r5)
	PPC_STORE_U32(ctx.r5.u32 + 2048, r11.u32);
	// lwz r10,4880(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4880);
	// lwz r9,336(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 336);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265DF6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r30,1392
	r11.s64 = r30.s64 + 1392;
	// stw r3,2124(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2124, ctx.r3.u32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,4016(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 4016);
	// stw r6,148(r7)
	PPC_STORE_U32(ctx.r7.u32 + 148, ctx.r6.u32);
	// lwz r5,1392(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 1392);
	// lwz r4,336(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 336);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8265DF98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// stw r3,2200(r11)
	PPC_STORE_U32(r11.u32 + 2200, ctx.r3.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,3536(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 3536);
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r7,756(r9)
	PPC_STORE_U32(ctx.r9.u32 + 756, ctx.r7.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,4496(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 4496);
	// stw r5,2276(r6)
	PPC_STORE_U32(ctx.r6.u32 + 2276, ctx.r5.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,-28304(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28304);
	// clrlwi r3,r11,31
	ctx.r3.u64 = r11.u32 & 0x1;
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r9,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// stw r8,1212(r4)
	PPC_STORE_U32(ctx.r4.u32 + 1212, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,-28304(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28304);
	// rlwinm r6,r11,0,30,30
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// subfic r5,r6,0
	xer.ca = ctx.r6.u32 <= 0;
	ctx.r5.s64 = 0 - ctx.r6.s64;
	// subfe r4,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + xer.ca < xer.ca);
	ctx.r4.u64 = ~ctx.r5.u64 + ctx.r5.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r4,31
	ctx.r3.u64 = ctx.r4.u32 & 0x1;
	// stw r3,1288(r7)
	PPC_STORE_U32(ctx.r7.u32 + 1288, ctx.r3.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,-28304(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28304);
	// rlwinm r8,r11,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// subfic r7,r8,0
	xer.ca = ctx.r8.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// stw r5,1364(r9)
	PPC_STORE_U32(ctx.r9.u32 + 1364, ctx.r5.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,-28304(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28304);
	// rlwinm r3,r11,0,28,28
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r9,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// stw r8,1440(r4)
	PPC_STORE_U32(ctx.r4.u32 + 1440, ctx.r8.u32);
	// lwz r11,-28304(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28304);
	// rlwinm r7,r11,0,27,27
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// subfic r5,r7,0
	xer.ca = ctx.r7.u32 <= 0;
	ctx.r5.s64 = 0 - ctx.r7.s64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// subfe r4,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + xer.ca < xer.ca);
	ctx.r4.u64 = ~ctx.r5.u64 + ctx.r5.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r4,31
	r11.u64 = ctx.r4.u32 & 0x1;
	// stw r11,1516(r6)
	PPC_STORE_U32(ctx.r6.u32 + 1516, r11.u32);
	// lwz r11,-28304(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28304);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r8,r11,0,26,26
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// subfic r7,r8,0
	xer.ca = ctx.r8.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// stw r5,1592(r9)
	PPC_STORE_U32(ctx.r9.u32 + 1592, ctx.r5.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,-28304(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28304);
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// subfic r9,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r9.s64 = 0 - r11.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// stw r7,1668(r4)
	PPC_STORE_U32(ctx.r4.u32 + 1668, ctx.r7.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,-28304(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28304);
	// rlwinm r5,r11,0,24,24
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// subfic r4,r5,0
	xer.ca = ctx.r5.u32 <= 0;
	ctx.r4.s64 = 0 - ctx.r5.s64;
	// subfe r11,r4,r4
	temp.u8 = (~ctx.r4.u32 + ctx.r4.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r4.u32 + xer.ca < xer.ca);
	r11.u64 = ~ctx.r4.u64 + ctx.r4.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// stw r10,1744(r6)
	PPC_STORE_U32(ctx.r6.u32 + 1744, ctx.r10.u32);
	// bl 0x826589d8
	ctx.lr = 0x8265E0A8;
	sub_826589D8(ctx, base);
	// b 0x8265e170
	goto loc_8265E170;
loc_8265E0AC:
	// lbz r11,960(r22)
	r11.u64 = PPC_LOAD_U8(r22.u32 + 960);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265e170
	if (cr6.eq) goto loc_8265E170;
	// lwz r11,-10240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// lwz r11,4304(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r29,r11,2356
	r29.s64 = r11.s64 + 2356;
	// bl 0x82654ac8
	ctx.lr = 0x8265E0D0;
	sub_82654AC8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r28,-1
	r28.s64 = -1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8265e0f4
	if (!cr6.eq) goto loc_8265E0F4;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82654b60
	ctx.lr = 0x8265E0E8;
	sub_82654B60(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265e10c
	if (cr6.eq) goto loc_8265E10C;
loc_8265E0F4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r28,528(r11)
	PPC_STORE_U32(r11.u32 + 528, r28.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r28,1136(r10)
	PPC_STORE_U32(ctx.r10.u32 + 1136, r28.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r28,984(r9)
	PPC_STORE_U32(ctx.r9.u32 + 984, r28.u32);
loc_8265E10C:
	// lwz r11,4256(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4256);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// addi r4,r10,-2524
	ctx.r4.s64 = ctx.r10.s64 + -2524;
	// stw r8,2276(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2276, ctx.r8.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4016(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4016);
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// stw r6,148(r7)
	PPC_STORE_U32(ctx.r7.u32 + 148, ctx.r6.u32);
	// lwz r29,72(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// bl 0x82294ef8
	ctx.lr = 0x8265E140;
	sub_82294EF8(ctx, base);
	// cmpw cr6,r29,r3
	cr6.compare<int32_t>(r29.s32, ctx.r3.s32, xer);
	// beq cr6,0x8265e170
	if (cr6.eq) goto loc_8265E170;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lwz r11,-28304(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -28304);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8265e170
	if (!cr6.eq) goto loc_8265E170;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,2548
	ctx.r3.s64 = r11.s64 + 2548;
	// bl 0x82130000
	ctx.lr = 0x8265E168;
	sub_82130000(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r28,908(r10)
	PPC_STORE_U32(ctx.r10.u32 + 908, r28.u32);
loc_8265E170:
	// lwz r9,4016(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4016);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r8,3996(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 3996);
	// addi r11,r30,4592
	r11.s64 = r30.s64 + 4592;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r7,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
loc_8265E188:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// beq cr6,0x8265e1a8
	if (cr6.eq) goto loc_8265E1A8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// bne cr6,0x8265e188
	if (!cr6.eq) goto loc_8265E188;
	// b 0x8265e414
	goto loc_8265E414;
loc_8265E1A8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,148(r11)
	PPC_STORE_U32(r11.u32 + 148, ctx.r10.u32);
	// b 0x8265e414
	goto loc_8265E414;
loc_8265E1B8:
	// bl 0x82387a18
	ctx.lr = 0x8265E1BC;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265e4ac
	if (cr6.eq) goto loc_8265E4AC;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r23,-32121
	r23.s64 = -2105081856;
	// addi r24,r11,-2628
	r24.s64 = r11.s64 + -2628;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r3,-10240(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8265E1E0;
	sub_822701C8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8265e414
	if (cr6.eq) goto loc_8265E414;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lis r10,2
	ctx.r10.s64 = 131072;
	// ori r28,r10,55136
	r28.u64 = ctx.r10.u64 | 55136;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lbzx r8,r9,r28
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r28.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8265e214
	if (cr6.eq) goto loc_8265E214;
	// lwz r11,2816(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2816);
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// b 0x8265e218
	goto loc_8265E218;
loc_8265E214:
	// lwz r5,2816(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 2816);
loc_8265E218:
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295f70
	ctx.lr = 0x8265E224;
	sub_82295F70(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lbzx r10,r11,r28
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + r28.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8265e244
	if (cr6.eq) goto loc_8265E244;
	// lwz r11,2816(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2816);
	// addi r28,r11,-1
	r28.s64 = r11.s64 + -1;
	// b 0x8265e248
	goto loc_8265E248;
loc_8265E244:
	// lwz r28,2816(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 2816);
loc_8265E248:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x822f10d0
	ctx.lr = 0x8265E254;
	sub_822F10D0(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8238eb90
	ctx.lr = 0x8265E25C;
	sub_8238EB90(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82296088
	ctx.lr = 0x8265E268;
	sub_82296088(ctx, base);
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r5,2096(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 2096);
	// bl 0x82295f70
	ctx.lr = 0x8265E278;
	sub_82295F70(ctx, base);
	// lwz r10,1392(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 1392);
	// addi r28,r30,1392
	r28.s64 = r30.s64 + 1392;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r9,336(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 336);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265E290;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8265e2bc
	if (cr6.eq) goto loc_8265E2BC;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265E2AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295d70
	ctx.lr = 0x8265E2BC;
	sub_82295D70(ctx, base);
loc_8265E2BC:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8265E2C8;
	sub_8238EC00(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r31,r10,r25
	r31.u64 = ctx.r10.u64 + r25.u64;
	// add r3,r31,r26
	ctx.r3.u64 = r31.u64 + r26.u64;
	// bl 0x82654bf8
	ctx.lr = 0x8265E2E0;
	sub_82654BF8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8265e308
	if (cr6.eq) goto loc_8265E308;
	// lwzx r11,r31,r21
	r11.u64 = PPC_LOAD_U32(r31.u32 + r21.u32);
	// add r3,r31,r21
	ctx.r3.u64 = r31.u64 + r21.u64;
	// lwz r10,784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265E300;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8265e30c
	goto loc_8265E30C;
loc_8265E308:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8265E30C:
	// add r11,r31,r21
	r11.u64 = r31.u64 + r21.u64;
	// li r29,0
	r29.s64 = 0;
	// addi r10,r11,976
	ctx.r10.s64 = r11.s64 + 976;
	// lwz r9,864(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 864);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x8265e32c
	if (!cr6.eq) goto loc_8265E32C;
	// li r29,2
	r29.s64 = 2;
	// b 0x8265e35c
	goto loc_8265E35C;
loc_8265E32C:
	// li r11,-1
	r11.s64 = -1;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823895f8
	ctx.lr = 0x8265E340;
	sub_823895F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8265e35c
	if (cr6.eq) goto loc_8265E35C;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x82388c48
	ctx.lr = 0x8265E358;
	sub_82388C48(ctx, base);
	// lwz r29,4(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
loc_8265E35C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826589d8
	ctx.lr = 0x8265E364;
	sub_826589D8(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r3,-10240(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8265E370;
	sub_822701C8(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265E388;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295d70
	ctx.lr = 0x8265E398;
	sub_82295D70(ctx, base);
	// cmpwi cr6,r29,8
	cr6.compare<int32_t>(r29.s32, 8, xer);
	// blt cr6,0x8265e3f4
	if (cr6.lt) goto loc_8265E3F4;
	// cmpwi cr6,r29,13
	cr6.compare<int32_t>(r29.s32, 13, xer);
	// bgt cr6,0x8265e3f4
	if (cr6.gt) goto loc_8265E3F4;
	// lwz r11,4624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4624);
	// addi r3,r30,4624
	ctx.r3.s64 = r30.s64 + 4624;
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265E3BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295d70
	ctx.lr = 0x8265E3CC;
	sub_82295D70(ctx, base);
	// lbz r9,8502(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 8502);
	// li r4,15
	ctx.r4.s64 = 15;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r5,r9,25,7,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0x1FFFFFF;
	// bl 0x82295f70
	ctx.lr = 0x8265E3E0;
	sub_82295F70(ctx, base);
	// lbz r8,8500(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 8500);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r5,r8,25,7,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 25) & 0x1FFFFFF;
	// bl 0x82295f70
	ctx.lr = 0x8265E3F4;
	sub_82295F70(ctx, base);
loc_8265E3F4:
	// li r4,17
	ctx.r4.s64 = 17;
	// lwz r5,2576(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 2576);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295f70
	ctx.lr = 0x8265E404;
	sub_82295F70(ctx, base);
	// addi r5,r30,8496
	ctx.r5.s64 = r30.s64 + 8496;
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295bc8
	ctx.lr = 0x8265E414;
	sub_82295BC8(ctx, base);
loc_8265E414:
	// lbz r11,962(r22)
	r11.u64 = PPC_LOAD_U8(r22.u32 + 962);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265e504
	if (cr6.eq) goto loc_8265E504;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82654bf8
	ctx.lr = 0x8265E428;
	sub_82654BF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265e498
	if (cr6.eq) goto loc_8265E498;
	// lwzx r11,r20,r21
	r11.u64 = PPC_LOAD_U32(r20.u32 + r21.u32);
	// add r31,r20,r21
	r31.u64 = r20.u64 + r21.u64;
	// li r30,0
	r30.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265E450;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,864(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// addi r8,r31,976
	ctx.r8.s64 = r31.s64 + 976;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bne cr6,0x8265e474
	if (!cr6.eq) goto loc_8265E474;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82655ff8
	ctx.lr = 0x8265E468;
	sub_82655FF8(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r11,-8672
	ctx.r3.s64 = r11.s64 + -8672;
loc_8265E474:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r31,700(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x821c9790
	ctx.lr = 0x8265E488;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82282580
	ctx.lr = 0x8265E498;
	sub_82282580(ctx, base);
loc_8265E498:
	// li r3,25
	ctx.r3.s64 = 25;
	// bl 0x82216138
	ctx.lr = 0x8265E4A0;
	sub_82216138(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9228
	return;
loc_8265E4AC:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r29,-32111
	r29.s64 = -2104426496;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r28,r11,2532
	r28.s64 = r11.s64 + 2532;
	// addi r4,r10,2516
	ctx.r4.s64 = ctx.r10.s64 + 2516;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r3,-24180(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -24180);
	// bl 0x8220ef00
	ctx.lr = 0x8265E4CC;
	sub_8220EF00(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x823db670
	ctx.lr = 0x8265E4E0;
	sub_823DB670(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// stw r9,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r9.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-9136
	ctx.r4.s64 = ctx.r8.s64 + -9136;
	// lwz r3,-24180(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -24180);
	// bl 0x821fde78
	ctx.lr = 0x8265E4FC;
	sub_821FDE78(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8265d2b8
	ctx.lr = 0x8265E504;
	sub_8265D2B8(ctx, base);
loc_8265E504:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8265E510"))) PPC_WEAK_FUNC(sub_8265E510);
PPC_FUNC_IMPL(__imp__sub_8265E510) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,4972
	ctx.r3.s64 = r11.s64 + 4972;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265E51C"))) PPC_WEAK_FUNC(sub_8265E51C);
PPC_FUNC_IMPL(__imp__sub_8265E51C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265E520"))) PPC_WEAK_FUNC(sub_8265E520);
PPC_FUNC_IMPL(__imp__sub_8265E520) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5008
	ctx.r3.s64 = r11.s64 + 5008;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265E52C"))) PPC_WEAK_FUNC(sub_8265E52C);
PPC_FUNC_IMPL(__imp__sub_8265E52C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265E530"))) PPC_WEAK_FUNC(sub_8265E530);
PPC_FUNC_IMPL(__imp__sub_8265E530) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5036
	ctx.r3.s64 = r11.s64 + 5036;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265E53C"))) PPC_WEAK_FUNC(sub_8265E53C);
PPC_FUNC_IMPL(__imp__sub_8265E53C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265E540"))) PPC_WEAK_FUNC(sub_8265E540);
PPC_FUNC_IMPL(__imp__sub_8265E540) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5072
	ctx.r3.s64 = r11.s64 + 5072;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265E54C"))) PPC_WEAK_FUNC(sub_8265E54C);
PPC_FUNC_IMPL(__imp__sub_8265E54C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265E550"))) PPC_WEAK_FUNC(sub_8265E550);
PPC_FUNC_IMPL(__imp__sub_8265E550) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8265e5d0
	if (cr6.eq) goto loc_8265E5D0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265E57C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8265e5d0
	if (cr6.eq) goto loc_8265E5D0;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x8265e5a0
	if (cr6.gt) goto loc_8265E5A0;
	// li r11,0
	r11.s64 = 0;
loc_8265E5A0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8265e5d0
	if (!cr6.eq) goto loc_8265E5D0;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8265E5B8;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8265E5D0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265E5E8"))) PPC_WEAK_FUNC(sub_8265E5E8);
PPC_FUNC_IMPL(__imp__sub_8265E5E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r31,17268(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8265e674
	if (cr6.eq) goto loc_8265E674;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8265E614;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265e674
	if (cr6.eq) goto loc_8265E674;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x8265E62C;
	sub_822A3998(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82703c70
	ctx.lr = 0x8265E634;
	sub_82703C70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8265e658
	if (!cr6.eq) goto loc_8265E658;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82703d08
	ctx.lr = 0x8265E648;
	sub_82703D08(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8265e65c
	if (cr6.eq) goto loc_8265E65C;
loc_8265E658:
	// li r11,1
	r11.s64 = 1;
loc_8265E65C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8265E674:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265E68C"))) PPC_WEAK_FUNC(sub_8265E68C);
PPC_FUNC_IMPL(__imp__sub_8265E68C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265E690"))) PPC_WEAK_FUNC(sub_8265E690);
PPC_FUNC_IMPL(__imp__sub_8265E690) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-13196
	ctx.r3.s64 = r11.s64 + -13196;
	// bl 0x821e6800
	ctx.lr = 0x8265E6B0;
	sub_821E6800(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82215810
	ctx.lr = 0x8265E6B8;
	sub_82215810(ctx, base);
	// clrlwi r10,r31,24
	ctx.r10.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8265e6c8
	if (cr6.eq) goto loc_8265E6C8;
	// bl 0x82130000
	ctx.lr = 0x8265E6C8;
	sub_82130000(ctx, base);
loc_8265E6C8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265E6DC"))) PPC_WEAK_FUNC(sub_8265E6DC);
PPC_FUNC_IMPL(__imp__sub_8265E6DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265E6E0"))) PPC_WEAK_FUNC(sub_8265E6E0);
PPC_FUNC_IMPL(__imp__sub_8265E6E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82632f78
	ctx.lr = 0x8265E6F8;
	sub_82632F78(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,680(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 680);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265E70C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8265e740
	if (cr6.eq) goto loc_8265E740;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r31,r10,-12592
	r31.s64 = ctx.r10.s64 + -12592;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265E734;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x825ee0e0
	ctx.lr = 0x8265E740;
	sub_825EE0E0(ctx, base);
loc_8265E740:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265E754"))) PPC_WEAK_FUNC(sub_8265E754);
PPC_FUNC_IMPL(__imp__sub_8265E754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265E758"))) PPC_WEAK_FUNC(sub_8265E758);
PPC_FUNC_IMPL(__imp__sub_8265E758) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8265E760;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r27,r10,5116
	r27.s64 = ctx.r10.s64 + 5116;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265E78C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x825ee120
	ctx.lr = 0x8265E798;
	sub_825EE120(ctx, base);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r8,-1
	cr6.compare<int32_t>(ctx.r8.s32, -1, xer);
	// beq cr6,0x8265e7b0
	if (cr6.eq) goto loc_8265E7B0;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8265E7B0:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263afa8
	ctx.lr = 0x8265E7C0;
	sub_8263AFA8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8265E7D8"))) PPC_WEAK_FUNC(sub_8265E7D8);
PPC_FUNC_IMPL(__imp__sub_8265E7D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r31,0
	r31.s64 = 0;
	// bl 0x82256058
	ctx.lr = 0x8265E7F0;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8265e80c
	if (cr6.eq) goto loc_8265E80C;
	// bl 0x82256058
	ctx.lr = 0x8265E7FC;
	sub_82256058(ctx, base);
	// lwz r11,3104(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3104);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmpwi cr6,r11,15
	cr6.compare<int32_t>(r11.s32, 15, xer);
	// beq cr6,0x8265e810
	if (cr6.eq) goto loc_8265E810;
loc_8265E80C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8265E810:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265E824"))) PPC_WEAK_FUNC(sub_8265E824);
PPC_FUNC_IMPL(__imp__sub_8265E824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265E828"))) PPC_WEAK_FUNC(sub_8265E828);
PPC_FUNC_IMPL(__imp__sub_8265E828) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82256058
	ctx.lr = 0x8265E838;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8265e854
	if (cr6.eq) goto loc_8265E854;
	// lwz r11,3152(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3152);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// b 0x8265e858
	goto loc_8265E858;
loc_8265E854:
	// li r11,0
	r11.s64 = 0;
loc_8265E858:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8265e870
	if (!cr6.eq) goto loc_8265E870;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x8265E870;
	sub_82207138(ctx, base);
loc_8265E870:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265E884"))) PPC_WEAK_FUNC(sub_8265E884);
PPC_FUNC_IMPL(__imp__sub_8265E884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265E888"))) PPC_WEAK_FUNC(sub_8265E888);
PPC_FUNC_IMPL(__imp__sub_8265E888) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265E8A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5104
	ctx.r3.s64 = ctx.r9.s64 + 5104;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265E8BC"))) PPC_WEAK_FUNC(sub_8265E8BC);
PPC_FUNC_IMPL(__imp__sub_8265E8BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265E8C0"))) PPC_WEAK_FUNC(sub_8265E8C0);
PPC_FUNC_IMPL(__imp__sub_8265E8C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265E8DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8265e918
	if (!cr6.eq) goto loc_8265E918;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x8265E8F4;
	sub_82207138(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8265e918
	if (!cr6.eq) goto loc_8265E918;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5140
	ctx.r3.s64 = r11.s64 + 5140;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8265E918:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5072
	ctx.r3.s64 = r11.s64 + 5072;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265E930"))) PPC_WEAK_FUNC(sub_8265E930);
PPC_FUNC_IMPL(__imp__sub_8265E930) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265E94C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8265e970
	if (cr6.eq) goto loc_8265E970;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5200
	ctx.r3.s64 = r11.s64 + 5200;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8265E970:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5168
	ctx.r3.s64 = r11.s64 + 5168;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265E988"))) PPC_WEAK_FUNC(sub_8265E988);
PPC_FUNC_IMPL(__imp__sub_8265E988) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265E9A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8265e9e0
	if (!cr6.eq) goto loc_8265E9E0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x8265E9BC;
	sub_82207138(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8265e9e0
	if (!cr6.eq) goto loc_8265E9E0;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5224
	ctx.r3.s64 = r11.s64 + 5224;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8265E9E0:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5036
	ctx.r3.s64 = r11.s64 + 5036;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265E9F8"))) PPC_WEAK_FUNC(sub_8265E9F8);
PPC_FUNC_IMPL(__imp__sub_8265E9F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265EA14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8265ea50
	if (!cr6.eq) goto loc_8265EA50;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x8265EA2C;
	sub_82207138(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8265ea50
	if (!cr6.eq) goto loc_8265EA50;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5256
	ctx.r3.s64 = r11.s64 + 5256;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8265EA50:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5072
	ctx.r3.s64 = r11.s64 + 5072;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265EA68"))) PPC_WEAK_FUNC(sub_8265EA68);
PPC_FUNC_IMPL(__imp__sub_8265EA68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265EA84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8265eaa8
	if (cr6.eq) goto loc_8265EAA8;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5308
	ctx.r3.s64 = r11.s64 + 5308;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8265EAA8:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5288
	ctx.r3.s64 = r11.s64 + 5288;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265EAC0"))) PPC_WEAK_FUNC(sub_8265EAC0);
PPC_FUNC_IMPL(__imp__sub_8265EAC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265EADC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8265eb00
	if (cr6.eq) goto loc_8265EB00;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5348
	ctx.r3.s64 = r11.s64 + 5348;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8265EB00:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5328
	ctx.r3.s64 = r11.s64 + 5328;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265EB18"))) PPC_WEAK_FUNC(sub_8265EB18);
PPC_FUNC_IMPL(__imp__sub_8265EB18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82387a18
	ctx.lr = 0x8265EB28;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265EB48"))) PPC_WEAK_FUNC(sub_8265EB48);
PPC_FUNC_IMPL(__imp__sub_8265EB48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r31,-5008(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -5008);
	// bl 0x82256058
	ctx.lr = 0x8265EB64;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8265eb80
	if (cr6.eq) goto loc_8265EB80;
	// lwz r11,3152(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3152);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// b 0x8265eb84
	goto loc_8265EB84;
loc_8265EB80:
	// li r11,0
	r11.s64 = 0;
loc_8265EB84:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265ebb8
	if (cr6.eq) goto loc_8265EBB8;
	// lbz r11,2620(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2620);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8265ebb8
	if (!cr6.eq) goto loc_8265EBB8;
	// lwz r11,1888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1888);
	// lwz r10,1892(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1892);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x8265ebbc
	if (cr6.lt) goto loc_8265EBBC;
loc_8265EBB8:
	// li r11,0
	r11.s64 = 0;
loc_8265EBBC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265EBD4"))) PPC_WEAK_FUNC(sub_8265EBD4);
PPC_FUNC_IMPL(__imp__sub_8265EBD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265EBD8"))) PPC_WEAK_FUNC(sub_8265EBD8);
PPC_FUNC_IMPL(__imp__sub_8265EBD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x8265eb48
	ctx.lr = 0x8265EBE8;
	sub_8265EB48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265EC04"))) PPC_WEAK_FUNC(sub_8265EC04);
PPC_FUNC_IMPL(__imp__sub_8265EC04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265EC08"))) PPC_WEAK_FUNC(sub_8265EC08);
PPC_FUNC_IMPL(__imp__sub_8265EC08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,-29932(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29932);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,4992(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4992, temp.u32);
	// stfs f13,4996(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4996, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265EC24"))) PPC_WEAK_FUNC(sub_8265EC24);
PPC_FUNC_IMPL(__imp__sub_8265EC24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265EC28"))) PPC_WEAK_FUNC(sub_8265EC28);
PPC_FUNC_IMPL(__imp__sub_8265EC28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265EC44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265EC60"))) PPC_WEAK_FUNC(sub_8265EC60);
PPC_FUNC_IMPL(__imp__sub_8265EC60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265EC80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8265ecc0
	if (cr6.eq) goto loc_8265ECC0;
	// li r31,0
	r31.s64 = 0;
	// bl 0x82256058
	ctx.lr = 0x8265EC94;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8265ecb0
	if (cr6.eq) goto loc_8265ECB0;
	// bl 0x82256058
	ctx.lr = 0x8265ECA0;
	sub_82256058(ctx, base);
	// lwz r11,3104(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3104);
	// cmpwi cr6,r11,15
	cr6.compare<int32_t>(r11.s32, 15, xer);
	// bne cr6,0x8265ecb0
	if (!cr6.eq) goto loc_8265ECB0;
	// li r31,1
	r31.s64 = 1;
loc_8265ECB0:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8265ecc4
	if (!cr6.eq) goto loc_8265ECC4;
loc_8265ECC0:
	// li r11,0
	r11.s64 = 0;
loc_8265ECC4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265ECDC"))) PPC_WEAK_FUNC(sub_8265ECDC);
PPC_FUNC_IMPL(__imp__sub_8265ECDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265ECE0"))) PPC_WEAK_FUNC(sub_8265ECE0);
PPC_FUNC_IMPL(__imp__sub_8265ECE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265ED0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,-10028(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8265ED24;
	sub_82641CB0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8265ED3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,184(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 184);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8265ED50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268e5f8
	ctx.lr = 0x8265ED58;
	sub_8268E5F8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265ED70"))) PPC_WEAK_FUNC(sub_8265ED70);
PPC_FUNC_IMPL(__imp__sub_8265ED70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8265ED80"))) PPC_WEAK_FUNC(sub_8265ED80);
PPC_FUNC_IMPL(__imp__sub_8265ED80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8265EDB0;
	sub_82641CB0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,468(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 468);
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265EDCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265EDE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,184(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 184);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8265EDF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265EE0C"))) PPC_WEAK_FUNC(sub_8265EE0C);
PPC_FUNC_IMPL(__imp__sub_8265EE0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265EE10"))) PPC_WEAK_FUNC(sub_8265EE10);
PPC_FUNC_IMPL(__imp__sub_8265EE10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8265EE34;
	sub_82641CB0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,472(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 472);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265EE44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265EE54"))) PPC_WEAK_FUNC(sub_8265EE54);
PPC_FUNC_IMPL(__imp__sub_8265EE54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265EE58"))) PPC_WEAK_FUNC(sub_8265EE58);
PPC_FUNC_IMPL(__imp__sub_8265EE58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82130000
	ctx.lr = 0x8265EE68;
	sub_82130000(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8265EE80;
	sub_82641CB0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,704(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 704);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265EE94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265EEA4"))) PPC_WEAK_FUNC(sub_8265EEA4);
PPC_FUNC_IMPL(__imp__sub_8265EEA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265EEA8"))) PPC_WEAK_FUNC(sub_8265EEA8);
PPC_FUNC_IMPL(__imp__sub_8265EEA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82130000
	ctx.lr = 0x8265EEBC;
	sub_82130000(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,17268(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8265EED0;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8265ef30
	if (cr6.eq) goto loc_8265EF30;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x8265EEE8;
	sub_822A3998(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822a93a8
	ctx.lr = 0x8265EEF4;
	sub_822A93A8(ctx, base);
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// lwz r10,784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// cmpwi cr6,r10,13
	cr6.compare<int32_t>(ctx.r10.s32, 13, xer);
	// beq cr6,0x8265ef30
	if (cr6.eq) goto loc_8265EF30;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f1,-17424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17424);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822afcd0
	ctx.lr = 0x8265EF1C;
	sub_822AFCD0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5578
	ctx.lr = 0x8265EF24;
	sub_822A5578(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,112(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
loc_8265EF30:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8265EF48;
	sub_82641CB0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265EF58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265EF6C"))) PPC_WEAK_FUNC(sub_8265EF6C);
PPC_FUNC_IMPL(__imp__sub_8265EF6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265EF70"))) PPC_WEAK_FUNC(sub_8265EF70);
PPC_FUNC_IMPL(__imp__sub_8265EF70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8265EF78;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,-1
	r29.s64 = -1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8265efec
	if (cr6.eq) goto loc_8265EFEC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r30,0
	r30.s64 = 0;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265EFA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8265efec
	if (!cr6.gt) goto loc_8265EFEC;
loc_8265EFA8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265EFC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8265eff8
	if (!cr6.eq) goto loc_8265EFF8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265EFE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x8265efa8
	if (cr6.lt) goto loc_8265EFA8;
loc_8265EFEC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8265EFF8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8265F004"))) PPC_WEAK_FUNC(sub_8265F004);
PPC_FUNC_IMPL(__imp__sub_8265F004) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265F008"))) PPC_WEAK_FUNC(sub_8265F008);
PPC_FUNC_IMPL(__imp__sub_8265F008) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8265F010;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r31,176
	r11.s64 = r31.s64 + 176;
	// lwz r10,352(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 352);
	// stw r9,352(r31)
	PPC_STORE_U32(r31.u32 + 352, ctx.r9.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8265f03c
	if (cr6.eq) goto loc_8265F03C;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,188
	ctx.r3.s64 = r11.s64 + 188;
	// bl 0x821c3048
	ctx.lr = 0x8265F03C;
	sub_821C3048(ctx, base);
loc_8265F03C:
	// addi r28,r31,1152
	r28.s64 = r31.s64 + 1152;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82631f88
	ctx.lr = 0x8265F048;
	sub_82631F88(ctx, base);
	// lwz r4,1336(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1336);
	// cmpw cr6,r4,r3
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r3.s32, xer);
	// blt cr6,0x8265f058
	if (cr6.lt) goto loc_8265F058;
	// addi r4,r3,-1
	ctx.r4.s64 = ctx.r3.s64 + -1;
loc_8265F058:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265F06C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r29,r31,1408
	r29.s64 = r31.s64 + 1408;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82631f88
	ctx.lr = 0x8265F078;
	sub_82631F88(ctx, base);
	// lwz r11,1592(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1592);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8265f088
	if (cr6.lt) goto loc_8265F088;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8265F088:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,648(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 648);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265F0A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r31,1664
	r30.s64 = r31.s64 + 1664;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82631f88
	ctx.lr = 0x8265F0AC;
	sub_82631F88(ctx, base);
	// lwz r11,1848(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1848);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8265f0bc
	if (cr6.lt) goto loc_8265F0BC;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8265F0BC:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,648(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 648);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265F0D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r31,1920
	r31.s64 = r31.s64 + 1920;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x8265F0E0;
	sub_82631F88(ctx, base);
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8265f0f0
	if (cr6.lt) goto loc_8265F0F0;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8265F0F0:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,648(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 648);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265F108;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,192(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 192);
	// lwz r27,0(r28)
	r27.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x8265ef70
	ctx.lr = 0x8265F114;
	sub_8265EF70(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,648(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 648);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265F128;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,192(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 192);
	// lwz r28,0(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8265ef70
	ctx.lr = 0x8265F134;
	sub_8265EF70(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r7,648(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 648);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8265F148;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,192(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 192);
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8265ef70
	ctx.lr = 0x8265F154;
	sub_8265EF70(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r6,648(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 648);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8265F168;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,192(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8265ef70
	ctx.lr = 0x8265F174;
	sub_8265EF70(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r5,648(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 648);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8265F188;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8265F190"))) PPC_WEAK_FUNC(sub_8265F190);
PPC_FUNC_IMPL(__imp__sub_8265F190) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// bne cr6,0x8265f1cc
	if (!cr6.eq) goto loc_8265F1CC;
	// lwz r11,220(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8265f1cc
	if (!cr6.eq) goto loc_8265F1CC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8265F1CC:
	// lis r11,1
	r11.s64 = 65536;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// ori r9,r11,10448
	ctx.r9.u64 = r11.u64 | 10448;
	// lwz r8,468(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 468);
	// lwzx r31,r3,r9
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r9.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265F1E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82653450
	ctx.lr = 0x8265F1F4;
	sub_82653450(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265F208"))) PPC_WEAK_FUNC(sub_8265F208);
PPC_FUNC_IMPL(__imp__sub_8265F208) {
	PPC_FUNC_PROLOGUE();
	// addis r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 65536;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r3,r3,10448
	ctx.r3.s64 = ctx.r3.s64 + 10448;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x82654960
	sub_82654960(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8265F21C"))) PPC_WEAK_FUNC(sub_8265F21C);
PPC_FUNC_IMPL(__imp__sub_8265F21C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265F220"))) PPC_WEAK_FUNC(sub_8265F220);
PPC_FUNC_IMPL(__imp__sub_8265F220) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8265F228;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82632f78
	ctx.lr = 0x8265F234;
	sub_82632F78(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265F248;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8265f2b4
	if (cr6.eq) goto loc_8265F2B4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r30,208(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r10,-12592
	r29.s64 = ctx.r10.s64 + -12592;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265F274;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8265F280;
	sub_825EE0E0(ctx, base);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// ori r6,r8,10448
	ctx.r6.u64 = ctx.r8.u64 | 10448;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r7,21416
	r30.s64 = ctx.r7.s64 + 21416;
	// lwz r4,468(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 468);
	// lwzx r31,r31,r6
	r31.u64 = PPC_LOAD_U32(r31.u32 + ctx.r6.u32);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8265F2A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8265F2B4;
	sub_825EE0E0(ctx, base);
loc_8265F2B4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8265F2BC"))) PPC_WEAK_FUNC(sub_8265F2BC);
PPC_FUNC_IMPL(__imp__sub_8265F2BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265F2C0"))) PPC_WEAK_FUNC(sub_8265F2C0);
PPC_FUNC_IMPL(__imp__sub_8265F2C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82256058
	ctx.lr = 0x8265F2D4;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8265f3b0
	if (cr6.eq) goto loc_8265F3B0;
	// bl 0x82256058
	ctx.lr = 0x8265F2E0;
	sub_82256058(ctx, base);
	// bl 0x82256138
	ctx.lr = 0x8265F2E4;
	sub_82256138(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265f3b0
	if (cr6.eq) goto loc_8265F3B0;
	// bl 0x82387a18
	ctx.lr = 0x8265F2F4;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265f398
	if (cr6.eq) goto loc_8265F398;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8265F308;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8265F318;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x8265F320;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8265f37c
	if (cr6.eq) goto loc_8265F37C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8265F330;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8265F340;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x8265F348;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// beq cr6,0x8265f37c
	if (cr6.eq) goto loc_8265F37C;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5368
	ctx.r3.s64 = r11.s64 + 5368;
	// bl 0x821fa230
	ctx.lr = 0x8265F35C;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265F36C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8265f380
	if (!cr6.eq) goto loc_8265F380;
loc_8265F37C:
	// li r11,0
	r11.s64 = 0;
loc_8265F380:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8265F398:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8265F3B0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265F3C8"))) PPC_WEAK_FUNC(sub_8265F3C8);
PPC_FUNC_IMPL(__imp__sub_8265F3C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82691650
	ctx.lr = 0x8265F3FC;
	sub_82691650(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265F410;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265F428"))) PPC_WEAK_FUNC(sub_8265F428);
PPC_FUNC_IMPL(__imp__sub_8265F428) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8265F454;
	sub_82641CB0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265F464;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r4,r7,-20148
	ctx.r4.s64 = ctx.r7.s64 + -20148;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82691650
	ctx.lr = 0x8265F488;
	sub_82691650(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r6,32(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8265F49C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stb r11,-12456(r5)
	PPC_STORE_U8(ctx.r5.u32 + -12456, r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265F4C0"))) PPC_WEAK_FUNC(sub_8265F4C0);
PPC_FUNC_IMPL(__imp__sub_8265F4C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-20132
	ctx.r4.s64 = ctx.r10.s64 + -20132;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82691650
	ctx.lr = 0x8265F4F8;
	sub_82691650(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,32(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265F50C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,-10028(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8265F524;
	sub_82641CB0(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,736(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 736);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8265F534;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// lis r4,-32121
	ctx.r4.s64 = -2105081856;
	// stb r11,-12456(r5)
	PPC_STORE_U8(ctx.r5.u32 + -12456, r11.u8);
	// lwz r3,-12012(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + -12012);
	// bl 0x821f15c8
	ctx.lr = 0x8265F54C;
	sub_821F15C8(ctx, base);
	// bl 0x821e60c0
	ctx.lr = 0x8265F550;
	sub_821E60C0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265F568"))) PPC_WEAK_FUNC(sub_8265F568);
PPC_FUNC_IMPL(__imp__sub_8265F568) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,18
	ctx.r4.s64 = 18;
	// lwz r11,-10028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8265F590;
	sub_82641CB0(ctx, base);
	// bl 0x8265c740
	ctx.lr = 0x8265F594;
	sub_8265C740(ctx, base);
	// bl 0x82256058
	ctx.lr = 0x8265F598;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8265f5ac
	if (cr6.eq) goto loc_8265F5AC;
	// bl 0x82256058
	ctx.lr = 0x8265F5A4;
	sub_82256058(ctx, base);
	// addi r8,r3,8
	ctx.r8.s64 = ctx.r3.s64 + 8;
	// b 0x8265f5b0
	goto loc_8265F5B0;
loc_8265F5AC:
	// li r8,0
	ctx.r8.s64 = 0;
loc_8265F5B0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// beq cr6,0x8265f740
	if (cr6.eq) goto loc_8265F740;
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8265f614
	if (cr6.lt) goto loc_8265F614;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8265f614
	if (cr6.eq) goto loc_8265F614;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,44(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// lis r7,-32129
	ctx.r7.s64 = -2105606144;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// addi r5,r7,-28304
	ctx.r5.s64 = ctx.r7.s64 + -28304;
	// rlwinm r11,r6,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// add r4,r11,r9
	ctx.r4.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// lwz r3,144(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 144);
	// and r11,r3,r11
	r11.u64 = ctx.r3.u64 & r11.u64;
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r10,r9,31
	ctx.r10.u64 = ctx.r9.u32 & 0x1;
loc_8265F614:
	// lwz r11,3140(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 3140);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8265f740
	if (!cr6.eq) goto loc_8265F740;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265f740
	if (cr6.eq) goto loc_8265F740;
	// lwz r11,3096(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 3096);
	// addi r11,r11,-5
	r11.s64 = r11.s64 + -5;
	// cmplwi cr6,r11,9
	cr6.compare<uint32_t>(r11.u32, 9, xer);
	// bgt cr6,0x8265f67c
	if (cr6.gt) goto loc_8265F67C;
	// lis r12,-32154
	r12.s64 = -2107244544;
	// addi r12,r12,-2476
	r12.s64 = r12.s64 + -2476;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8265F740;
	case 1:
		goto loc_8265F740;
	case 2:
		goto loc_8265F740;
	case 3:
		goto loc_8265F67C;
	case 4:
		goto loc_8265F67C;
	case 5:
		goto loc_8265F67C;
	case 6:
		goto loc_8265F740;
	case 7:
		goto loc_8265F67C;
	case 8:
		goto loc_8265F740;
	case 9:
		goto loc_8265F740;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-2240(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -2240);
	// lwz r19,-2240(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -2240);
	// lwz r19,-2240(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -2240);
	// lwz r19,-2436(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -2436);
	// lwz r19,-2436(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -2436);
	// lwz r19,-2436(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -2436);
	// lwz r19,-2240(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -2240);
	// lwz r19,-2436(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -2436);
	// lwz r19,-2240(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -2240);
	// lwz r19,-2240(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + -2240);
loc_8265F67C:
	// lwz r3,-10028(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// bl 0x82211210
	ctx.lr = 0x8265F684;
	sub_82211210(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// addi r3,r11,5424
	ctx.r3.s64 = r11.s64 + 5424;
	// beq cr6,0x8265f6f8
	if (cr6.eq) goto loc_8265F6F8;
	// bl 0x821fa230
	ctx.lr = 0x8265F698;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,80(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265F6A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5408
	ctx.r3.s64 = ctx.r8.s64 + 5408;
	// bl 0x821fa230
	ctx.lr = 0x8265F6B4;
	sub_821FA230(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,84(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 84);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8265F6C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r3,r5,5396
	ctx.r3.s64 = ctx.r5.s64 + 5396;
	// bl 0x821fa230
	ctx.lr = 0x8265F6D0;
	sub_821FA230(ctx, base);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 80);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8265F6E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r3,r10,5380
	ctx.r3.s64 = ctx.r10.s64 + 5380;
	// bl 0x821fa230
	ctx.lr = 0x8265F6EC;
	sub_821FA230(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,84(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// b 0x8265f7a8
	goto loc_8265F7A8;
loc_8265F6F8:
	// bl 0x821fa230
	ctx.lr = 0x8265F6FC;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265F70C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5408
	ctx.r3.s64 = ctx.r8.s64 + 5408;
	// bl 0x821fa230
	ctx.lr = 0x8265F718;
	sub_821FA230(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,80(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8265F728;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r3,r5,5396
	ctx.r3.s64 = ctx.r5.s64 + 5396;
	// bl 0x821fa230
	ctx.lr = 0x8265F734;
	sub_821FA230(ctx, base);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,84(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 84);
	// b 0x8265f78c
	goto loc_8265F78C;
loc_8265F740:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5424
	ctx.r3.s64 = r11.s64 + 5424;
	// bl 0x821fa230
	ctx.lr = 0x8265F74C;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,80(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265F75C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5408
	ctx.r3.s64 = ctx.r8.s64 + 5408;
	// bl 0x821fa230
	ctx.lr = 0x8265F768;
	sub_821FA230(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,80(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8265F778;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r3,r5,5396
	ctx.r3.s64 = ctx.r5.s64 + 5396;
	// bl 0x821fa230
	ctx.lr = 0x8265F784;
	sub_821FA230(ctx, base);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 80);
loc_8265F78C:
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8265F794;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r3,r10,5380
	ctx.r3.s64 = ctx.r10.s64 + 5380;
	// bl 0x821fa230
	ctx.lr = 0x8265F7A0;
	sub_821FA230(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
loc_8265F7A8:
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265F7B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265F7C4"))) PPC_WEAK_FUNC(sub_8265F7C4);
PPC_FUNC_IMPL(__imp__sub_8265F7C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265F7C8"))) PPC_WEAK_FUNC(sub_8265F7C8);
PPC_FUNC_IMPL(__imp__sub_8265F7C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8265f828
	if (cr6.eq) goto loc_8265F828;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// beq cr6,0x8265f7f8
	if (cr6.eq) goto loc_8265F7F8;
	// bl 0x826537d0
	ctx.lr = 0x8265F7F4;
	sub_826537D0(ctx, base);
	// b 0x8265f8d4
	goto loc_8265F8D4;
loc_8265F7F8:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8265F804;
	sub_821E6800(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8265F810;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265F824;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8265f8d4
	goto loc_8265F8D4;
loc_8265F828:
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x8265F830;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8265f840
	if (cr6.lt) goto loc_8265F840;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8265F840:
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r9,r10
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r7,72(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 72);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8265F860;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8265f8c8
	if (cr6.eq) goto loc_8265F8C8;
	// addi r11,r31,1152
	r11.s64 = r31.s64 + 1152;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x8265f884
	if (!cr6.eq) goto loc_8265F884;
	// lbz r3,1380(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 1380);
	// bl 0x8265e690
	ctx.lr = 0x8265F880;
	sub_8265E690(ctx, base);
	// b 0x8265f898
	goto loc_8265F898;
loc_8265F884:
	// addi r11,r31,944
	r11.s64 = r31.s64 + 944;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x8265f898
	if (!cr6.eq) goto loc_8265F898;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82215770
	ctx.lr = 0x8265F898;
	sub_82215770(ctx, base);
loc_8265F898:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8265F8A4;
	sub_821E6800(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826304b0
	ctx.lr = 0x8265F8B0;
	sub_826304B0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265F8C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8265f8d4
	goto loc_8265F8D4;
loc_8265F8C8:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x8265F8D4;
	sub_821E6800(ctx, base);
loc_8265F8D4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265F8F0"))) PPC_WEAK_FUNC(sub_8265F8F0);
PPC_FUNC_IMPL(__imp__sub_8265F8F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8263bf18
	ctx.lr = 0x8265F90C;
	sub_8263BF18(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-12248
	ctx.r4.s64 = ctx.r10.s64 + -12248;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8265F920;
	sub_821F9FB8(ctx, base);
	// lwz r9,3248(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3248);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// addi r30,r31,3248
	r30.s64 = r31.s64 + 3248;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,196(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// lwz r4,56(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8265F940;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,3248(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3248);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,176(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 176);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8265F954;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82635840
	ctx.lr = 0x8265F960;
	sub_82635840(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265F978"))) PPC_WEAK_FUNC(sub_8265F978);
PPC_FUNC_IMPL(__imp__sub_8265F978) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-13196
	ctx.r3.s64 = r11.s64 + -13196;
	// bl 0x821e6800
	ctx.lr = 0x8265F994;
	sub_821E6800(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82215810
	ctx.lr = 0x8265F99C;
	sub_82215810(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x8265F9A0;
	sub_82130000(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// bne cr6,0x8265f9bc
	if (!cr6.eq) goto loc_8265F9BC;
	// li r31,0
	r31.s64 = 0;
loc_8265F9BC:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r4,r10,-15108
	ctx.r4.s64 = ctx.r10.s64 + -15108;
	// bl 0x82691650
	ctx.lr = 0x8265F9CC;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r8,348(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 348);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265F9E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x8265f428
	ctx.lr = 0x8265F9E4;
	sub_8265F428(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265F9F8"))) PPC_WEAK_FUNC(sub_8265F9F8);
PPC_FUNC_IMPL(__imp__sub_8265F9F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,-10016(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265fa44
	if (cr6.eq) goto loc_8265FA44;
	// bl 0x8265e5e8
	ctx.lr = 0x8265FA1C;
	sub_8265E5E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265fa44
	if (cr6.eq) goto loc_8265FA44;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-10016(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// bl 0x827004b8
	ctx.lr = 0x8265FA34;
	sub_827004B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8265fa48
	if (cr6.eq) goto loc_8265FA48;
loc_8265FA44:
	// li r11,1
	r11.s64 = 1;
loc_8265FA48:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265FA60"))) PPC_WEAK_FUNC(sub_8265FA60);
PPC_FUNC_IMPL(__imp__sub_8265FA60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-12248
	ctx.r4.s64 = ctx.r10.s64 + -12248;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8265FA80;
	sub_821F9FB8(ctx, base);
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265FA94"))) PPC_WEAK_FUNC(sub_8265FA94);
PPC_FUNC_IMPL(__imp__sub_8265FA94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265FA98"))) PPC_WEAK_FUNC(sub_8265FA98);
PPC_FUNC_IMPL(__imp__sub_8265FA98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-10720
	ctx.r3.s64 = r11.s64 + -10720;
	// bl 0x821fa230
	ctx.lr = 0x8265FAB4;
	sub_821FA230(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r10,5480
	ctx.r3.s64 = ctx.r10.s64 + 5480;
	// bl 0x821fa230
	ctx.lr = 0x8265FAC4;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FAD0;
	sub_8268CC80(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5464
	ctx.r3.s64 = ctx.r9.s64 + 5464;
	// bl 0x821fa230
	ctx.lr = 0x8265FADC;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FAE8;
	sub_8268CC80(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5452
	ctx.r3.s64 = ctx.r8.s64 + 5452;
	// bl 0x821fa230
	ctx.lr = 0x8265FAF4;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FB00;
	sub_8268CC80(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r3,r7,5436
	ctx.r3.s64 = ctx.r7.s64 + 5436;
	// bl 0x821fa230
	ctx.lr = 0x8265FB0C;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FB18;
	sub_8268CC80(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265FB2C"))) PPC_WEAK_FUNC(sub_8265FB2C);
PPC_FUNC_IMPL(__imp__sub_8265FB2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265FB30"))) PPC_WEAK_FUNC(sub_8265FB30);
PPC_FUNC_IMPL(__imp__sub_8265FB30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5368
	ctx.r3.s64 = r11.s64 + 5368;
	// bl 0x821fa230
	ctx.lr = 0x8265FB4C;
	sub_821FA230(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r10,5520
	ctx.r3.s64 = ctx.r10.s64 + 5520;
	// bl 0x821fa230
	ctx.lr = 0x8265FB5C;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FB68;
	sub_8268CC80(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5504
	ctx.r3.s64 = ctx.r9.s64 + 5504;
	// bl 0x821fa230
	ctx.lr = 0x8265FB74;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FB80;
	sub_8268CC80(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5492
	ctx.r3.s64 = ctx.r8.s64 + 5492;
	// bl 0x821fa230
	ctx.lr = 0x8265FB8C;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FB98;
	sub_8268CC80(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265FBAC"))) PPC_WEAK_FUNC(sub_8265FBAC);
PPC_FUNC_IMPL(__imp__sub_8265FBAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265FBB0"))) PPC_WEAK_FUNC(sub_8265FBB0);
PPC_FUNC_IMPL(__imp__sub_8265FBB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x821fa230
	ctx.lr = 0x8265FBD0;
	sub_821FA230(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FBE0;
	sub_8268CC80(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265FBF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265FC10"))) PPC_WEAK_FUNC(sub_8265FC10);
PPC_FUNC_IMPL(__imp__sub_8265FC10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-10720
	ctx.r3.s64 = r11.s64 + -10720;
	// bl 0x821fa230
	ctx.lr = 0x8265FC2C;
	sub_821FA230(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r10,5480
	ctx.r3.s64 = ctx.r10.s64 + 5480;
	// bl 0x821fa230
	ctx.lr = 0x8265FC3C;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FC48;
	sub_8268CC80(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5452
	ctx.r3.s64 = ctx.r9.s64 + 5452;
	// bl 0x821fa230
	ctx.lr = 0x8265FC54;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FC60;
	sub_8268CC80(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5464
	ctx.r3.s64 = ctx.r8.s64 + 5464;
	// bl 0x821fa230
	ctx.lr = 0x8265FC6C;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FC78;
	sub_8268CC80(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265FC8C"))) PPC_WEAK_FUNC(sub_8265FC8C);
PPC_FUNC_IMPL(__imp__sub_8265FC8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265FC90"))) PPC_WEAK_FUNC(sub_8265FC90);
PPC_FUNC_IMPL(__imp__sub_8265FC90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,72
	ctx.r4.s64 = 72;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8265FCC4;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r9,256(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// beq cr6,0x8265fcd8
	if (cr6.eq) goto loc_8265FCD8;
	// bl 0x822150d8
	ctx.lr = 0x8265FCD8;
	sub_822150D8(ctx, base);
loc_8265FCD8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265FCF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265FD04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lfs f0,20160(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 20160);
	f0.f64 = double(temp.f32);
	// stfs f0,4992(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 4992, temp.u32);
	// bl 0x8265f4c0
	ctx.lr = 0x8265FD14;
	sub_8265F4C0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265FD2C"))) PPC_WEAK_FUNC(sub_8265FD2C);
PPC_FUNC_IMPL(__imp__sub_8265FD2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265FD30"))) PPC_WEAK_FUNC(sub_8265FD30);
PPC_FUNC_IMPL(__imp__sub_8265FD30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-10720
	ctx.r3.s64 = r11.s64 + -10720;
	// bl 0x821fa230
	ctx.lr = 0x8265FD4C;
	sub_821FA230(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r10,5480
	ctx.r3.s64 = ctx.r10.s64 + 5480;
	// bl 0x821fa230
	ctx.lr = 0x8265FD5C;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FD68;
	sub_8268CC80(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5628
	ctx.r3.s64 = ctx.r9.s64 + 5628;
	// bl 0x821fa230
	ctx.lr = 0x8265FD74;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FD80;
	sub_8268CC80(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5464
	ctx.r3.s64 = ctx.r8.s64 + 5464;
	// bl 0x821fa230
	ctx.lr = 0x8265FD8C;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FD98;
	sub_8268CC80(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r3,r7,5452
	ctx.r3.s64 = ctx.r7.s64 + 5452;
	// bl 0x821fa230
	ctx.lr = 0x8265FDA4;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FDB0;
	sub_8268CC80(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r3,r6,5608
	ctx.r3.s64 = ctx.r6.s64 + 5608;
	// bl 0x821fa230
	ctx.lr = 0x8265FDBC;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FDC8;
	sub_8268CC80(ctx, base);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r3,r5,5396
	ctx.r3.s64 = ctx.r5.s64 + 5396;
	// bl 0x821fa230
	ctx.lr = 0x8265FDD4;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FDE0;
	sub_8268CC80(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r3,r4,5380
	ctx.r3.s64 = ctx.r4.s64 + 5380;
	// bl 0x821fa230
	ctx.lr = 0x8265FDEC;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FDF8;
	sub_8268CC80(ctx, base);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// addi r3,r3,5436
	ctx.r3.s64 = ctx.r3.s64 + 5436;
	// bl 0x821fa230
	ctx.lr = 0x8265FE04;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FE10;
	sub_8268CC80(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5592
	ctx.r3.s64 = r11.s64 + 5592;
	// bl 0x821fa230
	ctx.lr = 0x8265FE1C;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FE28;
	sub_8268CC80(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r3,r10,5576
	ctx.r3.s64 = ctx.r10.s64 + 5576;
	// bl 0x821fa230
	ctx.lr = 0x8265FE34;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FE40;
	sub_8268CC80(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5564
	ctx.r3.s64 = ctx.r9.s64 + 5564;
	// bl 0x821fa230
	ctx.lr = 0x8265FE4C;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FE58;
	sub_8268CC80(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5548
	ctx.r3.s64 = ctx.r8.s64 + 5548;
	// bl 0x821fa230
	ctx.lr = 0x8265FE64;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FE70;
	sub_8268CC80(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r3,r7,5532
	ctx.r3.s64 = ctx.r7.s64 + 5532;
	// bl 0x821fa230
	ctx.lr = 0x8265FE7C;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FE88;
	sub_8268CC80(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8265FE9C"))) PPC_WEAK_FUNC(sub_8265FE9C);
PPC_FUNC_IMPL(__imp__sub_8265FE9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8265FEA0"))) PPC_WEAK_FUNC(sub_8265FEA0);
PPC_FUNC_IMPL(__imp__sub_8265FEA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r11,5368
	ctx.r3.s64 = r11.s64 + 5368;
	// bl 0x821fa230
	ctx.lr = 0x8265FEC4;
	sub_821FA230(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r10,5776
	ctx.r3.s64 = ctx.r10.s64 + 5776;
	// bl 0x821fa230
	ctx.lr = 0x8265FED4;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FEE0;
	sub_8268CC80(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5520
	ctx.r3.s64 = ctx.r9.s64 + 5520;
	// bl 0x821fa230
	ctx.lr = 0x8265FEEC;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FEF8;
	sub_8268CC80(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5756
	ctx.r3.s64 = ctx.r8.s64 + 5756;
	// bl 0x821fa230
	ctx.lr = 0x8265FF04;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FF10;
	sub_8268CC80(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r3,r7,5732
	ctx.r3.s64 = ctx.r7.s64 + 5732;
	// bl 0x821fa230
	ctx.lr = 0x8265FF1C;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FF28;
	sub_8268CC80(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r3,r6,5504
	ctx.r3.s64 = ctx.r6.s64 + 5504;
	// bl 0x821fa230
	ctx.lr = 0x8265FF34;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FF40;
	sub_8268CC80(ctx, base);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r3,r5,5712
	ctx.r3.s64 = ctx.r5.s64 + 5712;
	// bl 0x821fa230
	ctx.lr = 0x8265FF4C;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FF58;
	sub_8268CC80(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r3,r4,5700
	ctx.r3.s64 = ctx.r4.s64 + 5700;
	// bl 0x821fa230
	ctx.lr = 0x8265FF64;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FF70;
	sub_8268CC80(ctx, base);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// addi r3,r3,5676
	ctx.r3.s64 = ctx.r3.s64 + 5676;
	// bl 0x821fa230
	ctx.lr = 0x8265FF7C;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FF88;
	sub_8268CC80(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5492
	ctx.r3.s64 = r11.s64 + 5492;
	// bl 0x821fa230
	ctx.lr = 0x8265FF94;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FFA0;
	sub_8268CC80(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265FFB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8265ffd8
	if (cr6.eq) goto loc_8265FFD8;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5664
	ctx.r3.s64 = r11.s64 + 5664;
	// bl 0x821fa230
	ctx.lr = 0x8265FFCC;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FFD8;
	sub_8268CC80(ctx, base);
loc_8265FFD8:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5424
	ctx.r3.s64 = r11.s64 + 5424;
	// bl 0x821fa230
	ctx.lr = 0x8265FFE4;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8265FFF0;
	sub_8268CC80(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r3,r10,5408
	ctx.r3.s64 = ctx.r10.s64 + 5408;
	// bl 0x821fa230
	ctx.lr = 0x8265FFFC;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82660008;
	sub_8268CC80(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5652
	ctx.r3.s64 = ctx.r9.s64 + 5652;
	// bl 0x821fa230
	ctx.lr = 0x82660014;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82660020;
	sub_8268CC80(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5640
	ctx.r3.s64 = ctx.r8.s64 + 5640;
	// bl 0x821fa230
	ctx.lr = 0x8266002C;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82660038;
	sub_8268CC80(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82660050"))) PPC_WEAK_FUNC(sub_82660050);
PPC_FUNC_IMPL(__imp__sub_82660050) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82660058;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,5480
	ctx.r4.s64 = ctx.r10.s64 + 5480;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82691650
	ctx.lr = 0x8266007C;
	sub_82691650(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r4,r9,5928
	ctx.r4.s64 = ctx.r9.s64 + 5928;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82660094;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,5628
	ctx.r4.s64 = ctx.r6.s64 + 5628;
	// bl 0x82691650
	ctx.lr = 0x826600A4;
	sub_82691650(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r30,r5,5912
	r30.s64 = ctx.r5.s64 + 5912;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826600C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,5452
	ctx.r4.s64 = ctx.r9.s64 + 5452;
	// bl 0x82691650
	ctx.lr = 0x826600D0;
	sub_82691650(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r29,r8,5892
	r29.s64 = ctx.r8.s64 + 5892;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826600EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,5464
	ctx.r4.s64 = ctx.r5.s64 + 5464;
	// bl 0x82691650
	ctx.lr = 0x826600FC;
	sub_82691650(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r28,r4,5876
	r28.s64 = ctx.r4.s64 + 5876;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82660118;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,5520
	ctx.r4.s64 = ctx.r9.s64 + 5520;
	// bl 0x82691650
	ctx.lr = 0x82660128;
	sub_82691650(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266013C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,5492
	ctx.r4.s64 = ctx.r6.s64 + 5492;
	// bl 0x82691650
	ctx.lr = 0x8266014C;
	sub_82691650(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,340(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 340);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82660160;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,5504
	ctx.r4.s64 = ctx.r10.s64 + 5504;
	// bl 0x82691650
	ctx.lr = 0x82660170;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r8,340(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 340);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82660184;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,5640
	ctx.r4.s64 = ctx.r7.s64 + 5640;
	// bl 0x82691650
	ctx.lr = 0x82660194;
	sub_82691650(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r6,5856
	ctx.r4.s64 = ctx.r6.s64 + 5856;
	// lwz r11,340(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 340);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x826601AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,5664
	ctx.r4.s64 = ctx.r10.s64 + 5664;
	// bl 0x82691650
	ctx.lr = 0x826601BC;
	sub_82691650(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r4,r9,5836
	ctx.r4.s64 = ctx.r9.s64 + 5836;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826601D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lwz r3,-10028(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x826601E0;
	sub_82207138(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,5756
	ctx.r4.s64 = r11.s64 + 5756;
	// beq cr6,0x82660208
	if (cr6.eq) goto loc_82660208;
	// bl 0x82691650
	ctx.lr = 0x826601FC;
	sub_82691650(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,5816
	ctx.r4.s64 = ctx.r10.s64 + 5816;
	// b 0x82660214
	goto loc_82660214;
loc_82660208:
	// bl 0x82691650
	ctx.lr = 0x8266020C;
	sub_82691650(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,5788
	ctx.r4.s64 = ctx.r10.s64 + 5788;
loc_82660214:
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,340(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 340);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82660224;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266022C"))) PPC_WEAK_FUNC(sub_8266022C);
PPC_FUNC_IMPL(__imp__sub_8266022C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82660230"))) PPC_WEAK_FUNC(sub_82660230);
PPC_FUNC_IMPL(__imp__sub_82660230) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82387a18
	ctx.lr = 0x82660240;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82660288
	if (cr6.eq) goto loc_82660288;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5944
	ctx.r3.s64 = r11.s64 + 5944;
	// bl 0x821fa230
	ctx.lr = 0x82660258;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82660268;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82660288
	if (cr6.eq) goto loc_82660288;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82660288:
	// bl 0x82256058
	ctx.lr = 0x8266028C;
	sub_82256058(ctx, base);
	// addi r10,r3,0
	ctx.r10.s64 = ctx.r3.s64 + 0;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r3,r8,1
	ctx.r3.u64 = ctx.r8.u64 ^ 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826602AC"))) PPC_WEAK_FUNC(sub_826602AC);
PPC_FUNC_IMPL(__imp__sub_826602AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826602B0"))) PPC_WEAK_FUNC(sub_826602B0);
PPC_FUNC_IMPL(__imp__sub_826602B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826602CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826602ec
	if (cr6.eq) goto loc_826602EC;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826602EC:
	// bl 0x82660230
	ctx.lr = 0x826602F0;
	sub_82660230(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82660310"))) PPC_WEAK_FUNC(sub_82660310);
PPC_FUNC_IMPL(__imp__sub_82660310) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r20{};
	PPCRegister r21{};
	PPCRegister r22{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x82660318;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// addi r3,r11,5368
	ctx.r3.s64 = r11.s64 + 5368;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x821fa230
	ctx.lr = 0x82660330;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,352(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 352);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82660340;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r19)
	ctx.r8.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82660354;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r31,24
	ctx.r6.u64 = r31.u32 & 0xFF;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// addi r3,r11,6172
	ctx.r3.s64 = r11.s64 + 6172;
	// beq cr6,0x82660378
	if (cr6.eq) goto loc_82660378;
	// bl 0x821fa230
	ctx.lr = 0x8266036C;
	sub_821FA230(ctx, base);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// b 0x82660384
	goto loc_82660384;
loc_82660378:
	// bl 0x821fa230
	ctx.lr = 0x8266037C;
	sub_821FA230(ctx, base);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r9,r10,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
loc_82660384:
	// stw r9,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r9.u32);
	// lis r23,-32121
	r23.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82207190
	ctx.lr = 0x8266039C;
	sub_82207190(ctx, base);
	// bl 0x8265e5e8
	ctx.lr = 0x826603A0;
	sub_8265E5E8(ctx, base);
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826603B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82660404
	if (cr6.eq) goto loc_82660404;
	// bl 0x82387a18
	ctx.lr = 0x826603C8;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82660404
	if (!cr6.eq) goto loc_82660404;
	// bl 0x8265e7d8
	ctx.lr = 0x826603D8;
	sub_8265E7D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82660404
	if (!cr6.eq) goto loc_82660404;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// li r10,1
	ctx.r10.s64 = 1;
	// lbz r8,797(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 797);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82660408
	if (cr6.eq) goto loc_82660408;
loc_82660404:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82660408:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// clrlwi r28,r10,24
	r28.u64 = ctx.r10.u32 & 0xFF;
	// addi r31,r11,5520
	r31.s64 = r11.s64 + 5520;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821fa230
	ctx.lr = 0x8266041C;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82660430;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r30,r11,5628
	r30.s64 = r11.s64 + 5628;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821fa230
	ctx.lr = 0x82660440;
	sub_821FA230(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82660454;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r20,r29,24
	r20.u64 = r29.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x8266048c
	if (cr6.eq) goto loc_8266048C;
	// bl 0x821fa230
	ctx.lr = 0x82660468;
	sub_821FA230(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// bl 0x821fa230
	ctx.lr = 0x82660480;
	sub_821FA230(ctx, base);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r7,r8,16
	ctx.r7.u64 = ctx.r8.u64 | 16;
	// b 0x826604b0
	goto loc_826604B0;
loc_8266048C:
	// bl 0x821fa230
	ctx.lr = 0x82660490;
	sub_821FA230(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rlwinm r9,r10,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// bl 0x821fa230
	ctx.lr = 0x826604A8;
	sub_821FA230(ctx, base);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r7,r8,0,28,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
loc_826604B0:
	// stw r7,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r31,r11,6160
	r31.s64 = r11.s64 + 6160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821fa230
	ctx.lr = 0x826604C4;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826604D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r30,r11,5664
	r30.s64 = r11.s64 + 5664;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821fa230
	ctx.lr = 0x826604E8;
	sub_821FA230(ctx, base);
	// lwz r9,0(r19)
	ctx.r9.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// lwz r29,0(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82660504;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r7,76(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82660518;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x8266054c
	if (cr6.eq) goto loc_8266054C;
	// bl 0x821fa230
	ctx.lr = 0x82660528;
	sub_821FA230(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// bl 0x821fa230
	ctx.lr = 0x82660540;
	sub_821FA230(ctx, base);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r7,r8,16
	ctx.r7.u64 = ctx.r8.u64 | 16;
	// b 0x82660570
	goto loc_82660570;
loc_8266054C:
	// bl 0x821fa230
	ctx.lr = 0x82660550;
	sub_821FA230(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rlwinm r9,r10,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// bl 0x821fa230
	ctx.lr = 0x82660568;
	sub_821FA230(ctx, base);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r7,r8,0,28,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
loc_82660570:
	// stw r7,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5732
	ctx.r3.s64 = r11.s64 + 5732;
	// bl 0x821fa230
	ctx.lr = 0x82660580;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82660594;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r29,r11,5776
	r29.s64 = r11.s64 + 5776;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821fa230
	ctx.lr = 0x826605A4;
	sub_821FA230(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826605B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r3,r6,5492
	ctx.r3.s64 = ctx.r6.s64 + 5492;
	// bl 0x821fa230
	ctx.lr = 0x826605C4;
	sub_821FA230(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x826605D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r3,r10,5756
	ctx.r3.s64 = ctx.r10.s64 + 5756;
	// bl 0x821fa230
	ctx.lr = 0x826605E4;
	sub_821FA230(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826605F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r3,r7,5504
	ctx.r3.s64 = ctx.r7.s64 + 5504;
	// bl 0x821fa230
	ctx.lr = 0x82660604;
	sub_821FA230(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,76(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82660618;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r3,r4,5700
	ctx.r3.s64 = ctx.r4.s64 + 5700;
	// bl 0x821fa230
	ctx.lr = 0x82660624;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82660638;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5480
	ctx.r3.s64 = ctx.r9.s64 + 5480;
	// bl 0x821fa230
	ctx.lr = 0x82660644;
	sub_821FA230(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82660658;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r22,r11,6148
	r22.s64 = r11.s64 + 6148;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821fa230
	ctx.lr = 0x82660668;
	sub_821FA230(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r25,r11,6132
	r25.s64 = r11.s64 + 6132;
	// lwz r5,16(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// rlwinm r4,r5,0,28,26
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r4,16(r6)
	PPC_STORE_U32(ctx.r6.u32 + 16, ctx.r4.u32);
	// bl 0x821fa230
	ctx.lr = 0x82660688;
	sub_821FA230(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r21,r11,-15096
	r21.s64 = r11.s64 + -15096;
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// rlwinm r8,r9,0,28,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r8,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
	// bl 0x821fa230
	ctx.lr = 0x826606A8;
	sub_821FA230(ctx, base);
	// lwz r6,16(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// ori r5,r6,512
	ctx.r5.u64 = ctx.r6.u64 | 512;
	// stw r5,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r5.u32);
	// lwz r3,-10028(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x826606C0;
	sub_82207138(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// addi r31,r11,5436
	r31.s64 = r11.s64 + 5436;
	// addi r30,r10,5652
	r30.s64 = ctx.r10.s64 + 5652;
	// beq cr6,0x82660798
	if (cr6.eq) goto loc_82660798;
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826606F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82660798
	if (cr6.eq) goto loc_82660798;
	// bl 0x82660230
	ctx.lr = 0x82660700;
	sub_82660230(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82660760
	if (!cr6.eq) goto loc_82660760;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821fa230
	ctx.lr = 0x82660714;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82660728;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821fa230
	ctx.lr = 0x82660730;
	sub_821FA230(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82660744;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821fa230
	ctx.lr = 0x8266074C;
	sub_821FA230(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// b 0x82660794
	goto loc_82660794;
loc_82660760:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821fa230
	ctx.lr = 0x82660768;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266077C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821fa230
	ctx.lr = 0x82660784;
	sub_821FA230(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_82660794:
	// bctrl 
	ctx.lr = 0x82660798;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82660798:
	// bl 0x82387a18
	ctx.lr = 0x8266079C;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82660880
	if (cr6.eq) goto loc_82660880;
	// bl 0x821fa230
	ctx.lr = 0x826607B0;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826607C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821fa230
	ctx.lr = 0x826607CC;
	sub_821FA230(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826607E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r28,r11,6120
	r28.s64 = r11.s64 + 6120;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821fa230
	ctx.lr = 0x826607F0;
	sub_821FA230(ctx, base);
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// ori r6,r7,16
	ctx.r6.u64 = ctx.r7.u64 | 16;
	// addi r31,r11,6112
	r31.s64 = r11.s64 + 6112;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// lwz r11,-10236(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -10236);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82660818;
	sub_82691650(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82660840
	if (cr6.eq) goto loc_82660840;
	// lwz r11,-10236(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -10236);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82660834;
	sub_82691650(ctx, base);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
loc_82660840:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r26,r11,6096
	r26.s64 = r11.s64 + 6096;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821fa230
	ctx.lr = 0x82660850;
	sub_821FA230(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r24,r11,6080
	r24.s64 = r11.s64 + 6080;
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// ori r8,r9,16
	ctx.r8.u64 = ctx.r9.u64 | 16;
	// stw r8,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
	// bl 0x821fa230
	ctx.lr = 0x82660870;
	sub_821FA230(ctx, base);
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r6,r7,16
	ctx.r6.u64 = ctx.r7.u64 | 16;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// b 0x82660980
	goto loc_82660980;
loc_82660880:
	// bl 0x821fa230
	ctx.lr = 0x82660884;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82660898;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821fa230
	ctx.lr = 0x826608A0;
	sub_821FA230(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826608B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821fa230
	ctx.lr = 0x826608BC;
	sub_821FA230(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// rlwinm r5,r6,0,28,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r5,16(r7)
	PPC_STORE_U32(ctx.r7.u32 + 16, ctx.r5.u32);
	// bl 0x821fa230
	ctx.lr = 0x826608D4;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r26,r11,6096
	r26.s64 = r11.s64 + 6096;
	// lwz r11,16(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// rlwinm r10,r11,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r10,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r10.u32);
	// bl 0x821fa230
	ctx.lr = 0x826608F4;
	sub_821FA230(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r28,r11,6120
	r28.s64 = r11.s64 + 6120;
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// rlwinm r7,r8,0,28,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r7,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r7.u32);
	// bl 0x821fa230
	ctx.lr = 0x82660914;
	sub_821FA230(ctx, base);
	// lwz r6,16(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// rlwinm r5,r6,0,28,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// addi r31,r11,6112
	r31.s64 = r11.s64 + 6112;
	// stw r5,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r5.u32);
	// lwz r11,-10236(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -10236);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8266093C;
	sub_82691650(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82660964
	if (cr6.eq) goto loc_82660964;
	// lwz r11,-10236(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -10236);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82660958;
	sub_82691650(ctx, base);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r11,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
loc_82660964:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r24,r11,6080
	r24.s64 = r11.s64 + 6080;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821fa230
	ctx.lr = 0x82660974;
	sub_821FA230(ctx, base);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r11,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
loc_82660980:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5712
	ctx.r3.s64 = r11.s64 + 5712;
	// bl 0x821fa230
	ctx.lr = 0x8266098C;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826609A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5608
	ctx.r3.s64 = ctx.r8.s64 + 5608;
	// bl 0x821fa230
	ctx.lr = 0x826609AC;
	sub_821FA230(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826609C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82387a18
	ctx.lr = 0x826609C4;
	sub_82387A18(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x826609e8
	if (!cr6.eq) goto loc_826609E8;
	// li r27,1
	r27.s64 = 1;
	// bl 0x821fa230
	ctx.lr = 0x826609DC;
	sub_821FA230(ctx, base);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r11,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// b 0x826609f8
	goto loc_826609F8;
loc_826609E8:
	// li r27,0
	r27.s64 = 0;
	// bl 0x821fa230
	ctx.lr = 0x826609F0;
	sub_821FA230(ctx, base);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
loc_826609F8:
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82660A10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82660a68
	if (cr6.eq) goto loc_82660A68;
	// bl 0x82387a18
	ctx.lr = 0x82660A20;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82660a68
	if (!cr6.eq) goto loc_82660A68;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r30,r11,5640
	r30.s64 = r11.s64 + 5640;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821fa230
	ctx.lr = 0x82660A3C;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82660A50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r29,r11,5548
	r29.s64 = r11.s64 + 5548;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821fa230
	ctx.lr = 0x82660A60;
	sub_821FA230(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x82660aa0
	goto loc_82660AA0;
loc_82660A68:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r30,r11,5640
	r30.s64 = r11.s64 + 5640;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821fa230
	ctx.lr = 0x82660A78;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82660A8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r29,r11,5548
	r29.s64 = r11.s64 + 5548;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821fa230
	ctx.lr = 0x82660A9C;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
loc_82660AA0:
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82660AB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x82660ae4
	if (cr6.eq) goto loc_82660AE4;
	// bl 0x821fa230
	ctx.lr = 0x82660AC0;
	sub_821FA230(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// bl 0x821fa230
	ctx.lr = 0x82660AD8;
	sub_821FA230(ctx, base);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r7,r8,16
	ctx.r7.u64 = ctx.r8.u64 | 16;
	// b 0x82660b08
	goto loc_82660B08;
loc_82660AE4:
	// bl 0x821fa230
	ctx.lr = 0x82660AE8;
	sub_821FA230(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rlwinm r9,r10,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// bl 0x821fa230
	ctx.lr = 0x82660B00;
	sub_821FA230(ctx, base);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r7,r8,0,28,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
loc_82660B08:
	// stw r7,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-10684
	ctx.r3.s64 = r11.s64 + -10684;
	// bl 0x821fa230
	ctx.lr = 0x82660B18;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82660B28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82660b38
	if (cr6.eq) goto loc_82660B38;
	// li r27,0
	r27.s64 = 0;
loc_82660B38:
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x821fa230
	ctx.lr = 0x82660B40;
	sub_821FA230(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82660B58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// bne cr6,0x82660ba0
	if (!cr6.eq) goto loc_82660BA0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r11,2832(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lbz r10,10850(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10850);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82660ba0
	if (!cr6.eq) goto loc_82660BA0;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-15108
	ctx.r3.s64 = r11.s64 + -15108;
	// bl 0x821fa230
	ctx.lr = 0x82660B80;
	sub_821FA230(ctx, base);
	// bl 0x821f87e8
	ctx.lr = 0x82660B84;
	sub_821F87E8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82660ba0
	if (cr6.eq) goto loc_82660BA0;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// rlwinm r10,r11,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// rlwinm r10,r10,0,23,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFDFF;
	// b 0x82660ba8
	goto loc_82660BA8;
loc_82660BA0:
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// ori r10,r11,528
	ctx.r10.u64 = r11.u64 | 528;
loc_82660BA8:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// stw r10,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r10.u32);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82660bcc
	if (cr6.eq) goto loc_82660BCC;
	// bl 0x821fa230
	ctx.lr = 0x82660BC0;
	sub_821FA230(ctx, base);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r11,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// b 0x82660bd8
	goto loc_82660BD8;
loc_82660BCC:
	// bl 0x821fa230
	ctx.lr = 0x82660BD0;
	sub_821FA230(ctx, base);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
loc_82660BD8:
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,6064
	ctx.r3.s64 = r11.s64 + 6064;
	// bl 0x821fa230
	ctx.lr = 0x82660BE8;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82660BFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,6048
	ctx.r3.s64 = ctx.r8.s64 + 6048;
	// bl 0x821fa230
	ctx.lr = 0x82660C08;
	sub_821FA230(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82660C1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r3,r5,6040
	ctx.r3.s64 = ctx.r5.s64 + 6040;
	// bl 0x821fa230
	ctx.lr = 0x82660C28;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82660C3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,6020
	ctx.r3.s64 = ctx.r9.s64 + 6020;
	// bl 0x821fa230
	ctx.lr = 0x82660C48;
	sub_821FA230(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82660C5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r3,r6,6004
	ctx.r3.s64 = ctx.r6.s64 + 6004;
	// bl 0x821fa230
	ctx.lr = 0x82660C68;
	sub_821FA230(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82660C7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r3,r10,5984
	ctx.r3.s64 = ctx.r10.s64 + 5984;
	// bl 0x821fa230
	ctx.lr = 0x82660C88;
	sub_821FA230(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82660C9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r3,r7,5968
	ctx.r3.s64 = ctx.r7.s64 + 5968;
	// bl 0x821fa230
	ctx.lr = 0x82660CA8;
	sub_821FA230(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,76(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82660CBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r3,r4,5960
	ctx.r3.s64 = ctx.r4.s64 + 5960;
	// bl 0x821fa230
	ctx.lr = 0x82660CC8;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82660CDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5464
	ctx.r3.s64 = ctx.r9.s64 + 5464;
	// bl 0x821fa230
	ctx.lr = 0x82660CE8;
	sub_821FA230(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82660CFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r3,r6,5576
	ctx.r3.s64 = ctx.r6.s64 + 5576;
	// bl 0x821fa230
	ctx.lr = 0x82660D08;
	sub_821FA230(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82660D1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x8265f568
	ctx.lr = 0x82660D20;
	sub_8265F568(ctx, base);
	// lwz r10,0(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82660D34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r19)
	ctx.r8.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwz r7,48(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82660D48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82660e00
	if (cr6.eq) goto loc_82660E00;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821fa230
	ctx.lr = 0x82660D5C;
	sub_821FA230(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// bl 0x821fa230
	ctx.lr = 0x82660D74;
	sub_821FA230(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// ori r6,r7,16
	ctx.r6.u64 = ctx.r7.u64 | 16;
	// stw r6,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, ctx.r6.u32);
	// bl 0x821fa230
	ctx.lr = 0x82660D8C;
	sub_821FA230(ctx, base);
	// lwz r5,16(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// ori r11,r5,16
	r11.u64 = ctx.r5.u64 | 16;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// lwz r11,-10236(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82660DAC;
	sub_82691650(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82660dd4
	if (cr6.eq) goto loc_82660DD4;
	// lwz r11,-10236(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -10236);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82660DC8;
	sub_82691650(ctx, base);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
loc_82660DD4:
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x821fa230
	ctx.lr = 0x82660DDC;
	sub_821FA230(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// bl 0x821fa230
	ctx.lr = 0x82660DF4;
	sub_821FA230(ctx, base);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r7,r8,16
	ctx.r7.u64 = ctx.r8.u64 | 16;
	// stw r7,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
loc_82660E00:
	// bl 0x82660230
	ctx.lr = 0x82660E04;
	sub_82660230(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82660e3c
	if (!cr6.eq) goto loc_82660E3C;
	// bl 0x82387a18
	ctx.lr = 0x82660E14;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82660e3c
	if (!cr6.eq) goto loc_82660E3C;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821fa230
	ctx.lr = 0x82660E28;
	sub_821FA230(ctx, base);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r11,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9224
	return;
loc_82660E3C:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821fa230
	ctx.lr = 0x82660E44;
	sub_821FA230(ctx, base);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_82660E58"))) PPC_WEAK_FUNC(sub_82660E58);
PPC_FUNC_IMPL(__imp__sub_82660E58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82660E60;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// bl 0x82207e88
	ctx.lr = 0x82660E80;
	sub_82207E88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82660ebc
	if (cr6.eq) goto loc_82660EBC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,92(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82660EA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82660ebc
	if (!cr6.eq) goto loc_82660EBC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82660EBC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 262144;
	// addi r9,r9,976
	ctx.r9.s64 = ctx.r9.s64 + 976;
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// bne cr6,0x82660f58
	if (!cr6.eq) goto loc_82660F58;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,19
	cr6.compare<uint32_t>(r11.u32, 19, xer);
	// bgt cr6,0x82660f58
	if (cr6.gt) goto loc_82660F58;
	// lis r12,-32154
	r12.s64 = -2107244544;
	// addi r12,r12,3836
	r12.s64 = r12.s64 + 3836;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82660F4C;
	case 1:
		goto loc_82660F4C;
	case 2:
		goto loc_82660F4C;
	case 3:
		goto loc_82660F4C;
	case 4:
		goto loc_82660F58;
	case 5:
		goto loc_82660F58;
	case 6:
		goto loc_82660F58;
	case 7:
		goto loc_82660F58;
	case 8:
		goto loc_82660F58;
	case 9:
		goto loc_82660F58;
	case 10:
		goto loc_82660F58;
	case 11:
		goto loc_82660F58;
	case 12:
		goto loc_82660F58;
	case 13:
		goto loc_82660F58;
	case 14:
		goto loc_82660F58;
	case 15:
		goto loc_82660F58;
	case 16:
		goto loc_82660F4C;
	case 17:
		goto loc_82660F4C;
	case 18:
		goto loc_82660F4C;
	case 19:
		goto loc_82660F4C;
	default:
		__builtin_unreachable();
	}
	// lwz r19,3916(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 3916);
	// lwz r19,3916(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 3916);
	// lwz r19,3916(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 3916);
	// lwz r19,3916(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 3916);
	// lwz r19,3928(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 3928);
	// lwz r19,3928(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 3928);
	// lwz r19,3928(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 3928);
	// lwz r19,3928(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 3928);
	// lwz r19,3928(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 3928);
	// lwz r19,3928(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 3928);
	// lwz r19,3928(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 3928);
	// lwz r19,3928(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 3928);
	// lwz r19,3928(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 3928);
	// lwz r19,3928(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 3928);
	// lwz r19,3928(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 3928);
	// lwz r19,3928(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 3928);
	// lwz r19,3916(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 3916);
	// lwz r19,3916(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 3916);
	// lwz r19,3916(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 3916);
	// lwz r19,3916(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 3916);
loc_82660F4C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82660F58:
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8263b9a0
	ctx.lr = 0x82660F74;
	sub_8263B9A0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82660F7C"))) PPC_WEAK_FUNC(sub_82660F7C);
PPC_FUNC_IMPL(__imp__sub_82660F7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82660F80"))) PPC_WEAK_FUNC(sub_82660F80);
PPC_FUNC_IMPL(__imp__sub_82660F80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82660F88;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x82207e88
	ctx.lr = 0x82660F9C;
	sub_82207E88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82660fd8
	if (cr6.eq) goto loc_82660FD8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,92(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82660FC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82660fd8
	if (!cr6.eq) goto loc_82660FD8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82660FD8:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8265e758
	ctx.lr = 0x82660FE8;
	sub_8265E758(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82661000"))) PPC_WEAK_FUNC(sub_82661000);
PPC_FUNC_IMPL(__imp__sub_82661000) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82661008;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82256058
	ctx.lr = 0x82661014;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82661030
	if (cr6.eq) goto loc_82661030;
	// lwz r11,3152(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3152);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// b 0x82661034
	goto loc_82661034;
loc_82661030:
	// li r11,0
	r11.s64 = 0;
loc_82661034:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82661088
	if (cr6.eq) goto loc_82661088;
	// bl 0x8265eb48
	ctx.lr = 0x82661048;
	sub_8265EB48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82661064
	if (cr6.eq) goto loc_82661064;
loc_82661054:
	// addis r3,r29,1
	ctx.r3.s64 = r29.s64 + 65536;
	// addi r3,r3,-8208
	ctx.r3.s64 = ctx.r3.s64 + -8208;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82661064:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,72
	ctx.r4.s64 = 72;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8266107C;
	sub_82641CB0(ctx, base);
	// lbz r10,246(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 246);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82661054
	if (!cr6.eq) goto loc_82661054;
loc_82661088:
	// bl 0x82256058
	ctx.lr = 0x8266108C;
	sub_82256058(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r31,r10,1
	r31.u64 = ctx.r10.u64 ^ 1;
	// bl 0x82387a18
	ctx.lr = 0x8266109C;
	sub_82387A18(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826610d8
	if (cr6.eq) goto loc_826610D8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826610B0;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x826610C4;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x826610CC;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// beq cr6,0x826610d8
	if (cr6.eq) goto loc_826610D8;
	// li r31,0
	r31.s64 = 0;
loc_826610D8:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826611fc
	if (cr6.eq) goto loc_826611FC;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82204018
	ctx.lr = 0x826610F0;
	sub_82204018(ctx, base);
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// bgt cr6,0x826611ec
	if (cr6.gt) goto loc_826611EC;
	// lis r12,-32154
	r12.s64 = -2107244544;
	// addi r12,r12,4372
	r12.s64 = r12.s64 + 4372;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826611BC;
	case 1:
		goto loc_8266117C;
	case 2:
		goto loc_82661164;
	case 3:
		goto loc_82661170;
	case 4:
		goto loc_826611AC;
	case 5:
		goto loc_82661188;
	case 6:
		goto loc_82661194;
	case 7:
		goto loc_826611BC;
	case 8:
		goto loc_826611A0;
	case 9:
		goto loc_826611DC;
	case 10:
		goto loc_82661158;
	case 11:
		goto loc_826611BC;
	case 12:
		goto loc_826611CC;
	case 13:
		goto loc_826611CC;
	case 14:
		goto loc_826611BC;
	case 15:
		goto loc_826611BC;
	case 16:
		goto loc_826611BC;
	default:
		__builtin_unreachable();
	}
	// lwz r19,4540(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4540);
	// lwz r19,4476(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4476);
	// lwz r19,4452(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4452);
	// lwz r19,4464(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4464);
	// lwz r19,4524(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4524);
	// lwz r19,4488(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4488);
	// lwz r19,4500(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4500);
	// lwz r19,4540(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4540);
	// lwz r19,4512(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4512);
	// lwz r19,4572(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4572);
	// lwz r19,4440(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4440);
	// lwz r19,4540(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4540);
	// lwz r19,4556(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4556);
	// lwz r19,4556(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4556);
	// lwz r19,4540(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4540);
	// lwz r19,4540(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4540);
	// lwz r19,4540(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4540);
loc_82661158:
	// addi r3,r29,2416
	ctx.r3.s64 = r29.s64 + 2416;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82661164:
	// addi r3,r29,7408
	ctx.r3.s64 = r29.s64 + 7408;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82661170:
	// addi r3,r29,12400
	ctx.r3.s64 = r29.s64 + 12400;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8266117C:
	// addi r3,r29,17392
	ctx.r3.s64 = r29.s64 + 17392;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82661188:
	// addi r3,r29,22384
	ctx.r3.s64 = r29.s64 + 22384;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82661194:
	// addi r3,r29,27376
	ctx.r3.s64 = r29.s64 + 27376;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826611A0:
	// addi r3,r29,32368
	ctx.r3.s64 = r29.s64 + 32368;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826611AC:
	// addis r3,r29,1
	ctx.r3.s64 = r29.s64 + 65536;
	// addi r3,r3,-23184
	ctx.r3.s64 = ctx.r3.s64 + -23184;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826611BC:
	// addis r3,r29,1
	ctx.r3.s64 = r29.s64 + 65536;
	// addi r3,r3,-18192
	ctx.r3.s64 = ctx.r3.s64 + -18192;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826611CC:
	// addis r3,r29,1
	ctx.r3.s64 = r29.s64 + 65536;
	// addi r3,r3,-13200
	ctx.r3.s64 = ctx.r3.s64 + -13200;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826611DC:
	// addis r3,r29,1
	ctx.r3.s64 = r29.s64 + 65536;
	// addi r3,r3,-28176
	ctx.r3.s64 = ctx.r3.s64 + -28176;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826611EC:
	// addis r3,r29,1
	ctx.r3.s64 = r29.s64 + 65536;
	// addi r3,r3,1792
	ctx.r3.s64 = ctx.r3.s64 + 1792;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826611FC:
	// addis r3,r29,1
	ctx.r3.s64 = r29.s64 + 65536;
	// addi r3,r3,-3200
	ctx.r3.s64 = ctx.r3.s64 + -3200;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8266120C"))) PPC_WEAK_FUNC(sub_8266120C);
PPC_FUNC_IMPL(__imp__sub_8266120C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82661210"))) PPC_WEAK_FUNC(sub_82661210);
PPC_FUNC_IMPL(__imp__sub_82661210) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82661218;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,72
	ctx.r4.s64 = 72;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8266123C;
	sub_82641CB0(ctx, base);
	// lbz r9,246(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 246);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82661250
	if (cr6.eq) goto loc_82661250;
	// addi r31,r31,1152
	r31.s64 = r31.s64 + 1152;
	// b 0x82661268
	goto loc_82661268;
loc_82661250:
	// lwz r11,352(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 352);
	// lwz r10,356(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 356);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r7,68(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 68);
	// lwz r31,0(r7)
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
loc_82661268:
	// lwz r30,192(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r29,12(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x82631f88
	ctx.lr = 0x82661278;
	sub_82631F88(ctx, base);
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x82661288
	if (cr6.lt) goto loc_82661288;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_82661288:
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x8266129c
	if (!cr6.eq) goto loc_8266129C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8266129C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x826612A4;
	sub_82631F88(ctx, base);
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x826612b4
	if (cr6.lt) goto loc_826612B4;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_826612B4:
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwzx r4,r9,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x8268dcb0
	ctx.lr = 0x826612C8;
	sub_8268DCB0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826612D0"))) PPC_WEAK_FUNC(sub_826612D0);
PPC_FUNC_IMPL(__imp__sub_826612D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,66
	cr6.compare<int32_t>(ctx.r4.s32, 66, xer);
	// blt cr6,0x8266142c
	if (cr6.lt) goto loc_8266142C;
	// cmpwi cr6,r4,67
	cr6.compare<int32_t>(ctx.r4.s32, 67, xer);
	// bgt cr6,0x8266142c
	if (cr6.gt) goto loc_8266142C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cc8
	ctx.lr = 0x8266130C;
	sub_82641CC8(ctx, base);
	// cmplw cr6,r3,r31
	cr6.compare<uint32_t>(ctx.r3.u32, r31.u32, xer);
	// bne cr6,0x82661424
	if (!cr6.eq) goto loc_82661424;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82661334;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82661424
	if (!cr6.eq) goto loc_82661424;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r11,2832(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lbz r10,10850(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10850);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82661424
	if (!cr6.eq) goto loc_82661424;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266136C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82661380;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lwz r31,17268(r7)
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + 17268);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826613ac
	if (cr6.eq) goto loc_826613AC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8266139C;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x826613b0
	if (!cr6.eq) goto loc_826613B0;
loc_826613AC:
	// li r11,0
	r11.s64 = 0;
loc_826613B0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82661424
	if (cr6.eq) goto loc_82661424;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x826613C8;
	sub_822A3998(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x821a5cc0
	ctx.lr = 0x826613D0;
	sub_821A5CC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82661424
	if (!cr6.eq) goto loc_82661424;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821a5cc0
	ctx.lr = 0x826613E4;
	sub_821A5CC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82661424
	if (!cr6.eq) goto loc_82661424;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-18724
	ctx.r4.s64 = ctx.r10.s64 + -18724;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82691650
	ctx.lr = 0x82661410;
	sub_82691650(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,32(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82661424;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82661424:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82661434
	goto loc_82661434;
loc_8266142C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826309e0
	ctx.lr = 0x82661434;
	sub_826309E0(ctx, base);
loc_82661434:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266144C"))) PPC_WEAK_FUNC(sub_8266144C);
PPC_FUNC_IMPL(__imp__sub_8266144C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82661450"))) PPC_WEAK_FUNC(sub_82661450);
PPC_FUNC_IMPL(__imp__sub_82661450) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r3,r3,480
	ctx.r3.s64 = ctx.r3.s64 + 480;
	// bl 0x82661000
	ctx.lr = 0x82661464;
	sub_82661000(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82661474;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r4,60
	ctx.r4.s64 = 60;
	// lwz r11,-10236(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r8,1
	ctx.r3.s64 = ctx.r8.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82661490;
	sub_82641CB0(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,736(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 736);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826614A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821e6828
	ctx.lr = 0x826614AC;
	sub_821E6828(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826614BC"))) PPC_WEAK_FUNC(sub_826614BC);
PPC_FUNC_IMPL(__imp__sub_826614BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826614C0"))) PPC_WEAK_FUNC(sub_826614C0);
PPC_FUNC_IMPL(__imp__sub_826614C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stfd f31,-16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -16, f31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r3,r3,480
	ctx.r3.s64 = ctx.r3.s64 + 480;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// bl 0x82661000
	ctx.lr = 0x826614DC;
	sub_82661000(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826614F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-16(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82661504"))) PPC_WEAK_FUNC(sub_82661504);
PPC_FUNC_IMPL(__imp__sub_82661504) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82661508"))) PPC_WEAK_FUNC(sub_82661508);
PPC_FUNC_IMPL(__imp__sub_82661508) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82661538;
	sub_82691650(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,-10028(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82661554;
	sub_82641CB0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826615bc
	if (cr6.eq) goto loc_826615BC;
	// addi r3,r3,480
	ctx.r3.s64 = ctx.r3.s64 + 480;
	// bl 0x82661210
	ctx.lr = 0x82661564;
	sub_82661210(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bne cr6,0x826615bc
	if (!cr6.eq) goto loc_826615BC;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x82661584
	if (cr6.gt) goto loc_82661584;
	// li r11,0
	r11.s64 = 0;
loc_82661584:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826615b0
	if (!cr6.eq) goto loc_826615B0;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826615a8
	if (cr6.eq) goto loc_826615A8;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x826615A8;
	sub_821E6800(ctx, base);
loc_826615A8:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x826615c0
	goto loc_826615C0;
loc_826615B0:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x826615BC;
	sub_821E6800(ctx, base);
loc_826615BC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826615C0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826615D8"))) PPC_WEAK_FUNC(sub_826615D8);
PPC_FUNC_IMPL(__imp__sub_826615D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82660050
	ctx.lr = 0x826615F0;
	sub_82660050(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,5628
	ctx.r4.s64 = ctx.r10.s64 + 5628;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82691650
	ctx.lr = 0x82661610;
	sub_82691650(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r30,r9,6248
	r30.s64 = ctx.r9.s64 + 6248;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266162C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,5520
	ctx.r4.s64 = ctx.r6.s64 + 5520;
	// bl 0x82691650
	ctx.lr = 0x8266163C;
	sub_82691650(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,340(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 340);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82661650;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,5464
	ctx.r4.s64 = ctx.r10.s64 + 5464;
	// bl 0x82691650
	ctx.lr = 0x82661660;
	sub_82691650(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r30,r9,6228
	r30.s64 = ctx.r9.s64 + 6228;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266167C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,5504
	ctx.r4.s64 = ctx.r6.s64 + 5504;
	// bl 0x82691650
	ctx.lr = 0x8266168C;
	sub_82691650(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,340(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 340);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x826616A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,5452
	ctx.r4.s64 = ctx.r10.s64 + 5452;
	// bl 0x82691650
	ctx.lr = 0x826616B0;
	sub_82691650(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r4,r9,6204
	ctx.r4.s64 = ctx.r9.s64 + 6204;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826616C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,5492
	ctx.r4.s64 = ctx.r6.s64 + 5492;
	// bl 0x82691650
	ctx.lr = 0x826616D8;
	sub_82691650(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r4,r5,6184
	ctx.r4.s64 = ctx.r5.s64 + 6184;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826616F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82661708"))) PPC_WEAK_FUNC(sub_82661708);
PPC_FUNC_IMPL(__imp__sub_82661708) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82661710;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82660050
	ctx.lr = 0x82661718;
	sub_82660050(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,5464
	ctx.r4.s64 = ctx.r10.s64 + 5464;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82691650
	ctx.lr = 0x82661738;
	sub_82691650(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r30,r9,6316
	r30.s64 = ctx.r9.s64 + 6316;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82661754;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,5452
	ctx.r4.s64 = ctx.r6.s64 + 5452;
	// bl 0x82691650
	ctx.lr = 0x82661764;
	sub_82691650(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r29,r5,6292
	r29.s64 = ctx.r5.s64 + 6292;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82661780;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,5492
	ctx.r4.s64 = ctx.r9.s64 + 5492;
	// bl 0x82691650
	ctx.lr = 0x82661790;
	sub_82691650(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826617A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,5640
	ctx.r4.s64 = ctx.r6.s64 + 5640;
	// bl 0x82691650
	ctx.lr = 0x826617B4;
	sub_82691650(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,340(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 340);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x826617C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,5664
	ctx.r4.s64 = ctx.r10.s64 + 5664;
	// bl 0x82691650
	ctx.lr = 0x826617D8;
	sub_82691650(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r4,r9,6268
	ctx.r4.s64 = ctx.r9.s64 + 6268;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826617F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826617F8"))) PPC_WEAK_FUNC(sub_826617F8);
PPC_FUNC_IMPL(__imp__sub_826617F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82660310
	ctx.lr = 0x82661810;
	sub_82660310(ctx, base);
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826618bc
	if (cr6.eq) goto loc_826618BC;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5640
	ctx.r3.s64 = r11.s64 + 5640;
	// bl 0x821fa230
	ctx.lr = 0x82661828;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266183C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5664
	ctx.r3.s64 = ctx.r8.s64 + 5664;
	// bl 0x821fa230
	ctx.lr = 0x82661848;
	sub_821FA230(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8266185C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r3,r5,5492
	ctx.r3.s64 = ctx.r5.s64 + 5492;
	// bl 0x821fa230
	ctx.lr = 0x82661868;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266187C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5756
	ctx.r3.s64 = ctx.r9.s64 + 5756;
	// bl 0x821fa230
	ctx.lr = 0x82661888;
	sub_821FA230(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266189C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r3,r6,5520
	ctx.r3.s64 = ctx.r6.s64 + 5520;
	// bl 0x821fa230
	ctx.lr = 0x826618A8;
	sub_821FA230(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// b 0x82661938
	goto loc_82661938;
loc_826618BC:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5664
	ctx.r3.s64 = r11.s64 + 5664;
	// bl 0x821fa230
	ctx.lr = 0x826618C8;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826618DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5464
	ctx.r3.s64 = ctx.r8.s64 + 5464;
	// bl 0x821fa230
	ctx.lr = 0x826618E8;
	sub_821FA230(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826618FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r3,r5,5548
	ctx.r3.s64 = ctx.r5.s64 + 5548;
	// bl 0x821fa230
	ctx.lr = 0x82661908;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266191C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5452
	ctx.r3.s64 = ctx.r9.s64 + 5452;
	// bl 0x821fa230
	ctx.lr = 0x82661928;
	sub_821FA230(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
loc_82661938:
	// bctrl 
	ctx.lr = 0x8266193C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5652
	ctx.r3.s64 = r11.s64 + 5652;
	// bl 0x821fa230
	ctx.lr = 0x82661948;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266195C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5436
	ctx.r3.s64 = ctx.r8.s64 + 5436;
	// bl 0x821fa230
	ctx.lr = 0x82661968;
	sub_821FA230(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8266197C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82661990"))) PPC_WEAK_FUNC(sub_82661990);
PPC_FUNC_IMPL(__imp__sub_82661990) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82660310
	ctx.lr = 0x826619AC;
	sub_82660310(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,44
	ctx.r4.s64 = 44;
	// lwz r11,-10028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x826619C4;
	sub_82641CB0(ctx, base);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,24348
	ctx.r4.s64 = r11.s64 + 24348;
	// addi r3,r3,256
	ctx.r3.s64 = ctx.r3.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x826619D8;
	sub_8262FFE0(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r3,r10,5452
	ctx.r3.s64 = ctx.r10.s64 + 5452;
	// bl 0x821fa230
	ctx.lr = 0x826619E4;
	sub_821FA230(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826619F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r3,r7,5436
	ctx.r3.s64 = ctx.r7.s64 + 5436;
	// bl 0x821fa230
	ctx.lr = 0x82661A04;
	sub_821FA230(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,76(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82661A18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r3,r4,5652
	ctx.r3.s64 = ctx.r4.s64 + 5652;
	// bl 0x821fa230
	ctx.lr = 0x82661A24;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82661A38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5664
	ctx.r3.s64 = ctx.r9.s64 + 5664;
	// bl 0x821fa230
	ctx.lr = 0x82661A44;
	sub_821FA230(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82661A58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r30,24
	ctx.r6.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82661a94
	if (cr6.eq) goto loc_82661A94;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5640
	ctx.r3.s64 = r11.s64 + 5640;
	// bl 0x821fa230
	ctx.lr = 0x82661A70;
	sub_821FA230(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-10028(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82207138
	ctx.lr = 0x82661A80;
	sub_82207138(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// b 0x82661ab0
	goto loc_82661AB0;
loc_82661A94:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5464
	ctx.r3.s64 = r11.s64 + 5464;
	// bl 0x821fa230
	ctx.lr = 0x82661AA0;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82661AB0:
	// bctrl 
	ctx.lr = 0x82661AB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82661ACC"))) PPC_WEAK_FUNC(sub_82661ACC);
PPC_FUNC_IMPL(__imp__sub_82661ACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82661AD0"))) PPC_WEAK_FUNC(sub_82661AD0);
PPC_FUNC_IMPL(__imp__sub_82661AD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82660050
	ctx.lr = 0x82661AE8;
	sub_82660050(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,5452
	ctx.r4.s64 = ctx.r10.s64 + 5452;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82691650
	ctx.lr = 0x82661B08;
	sub_82691650(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r30,r9,6356
	r30.s64 = ctx.r9.s64 + 6356;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82661B24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,5492
	ctx.r4.s64 = ctx.r6.s64 + 5492;
	// bl 0x82691650
	ctx.lr = 0x82661B34;
	sub_82691650(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,340(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 340);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82661B48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,5628
	ctx.r4.s64 = ctx.r10.s64 + 5628;
	// bl 0x82691650
	ctx.lr = 0x82661B58;
	sub_82691650(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r30,r9,6336
	r30.s64 = ctx.r9.s64 + 6336;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82661B74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,5520
	ctx.r4.s64 = ctx.r6.s64 + 5520;
	// bl 0x82691650
	ctx.lr = 0x82661B84;
	sub_82691650(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,340(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 340);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82661B98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82661BB0"))) PPC_WEAK_FUNC(sub_82661BB0);
PPC_FUNC_IMPL(__imp__sub_82661BB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82660310
	ctx.lr = 0x82661BC0;
	sub_82660310(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5436
	ctx.r3.s64 = r11.s64 + 5436;
	// bl 0x821fa230
	ctx.lr = 0x82661BCC;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82661BE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5452
	ctx.r3.s64 = ctx.r8.s64 + 5452;
	// bl 0x821fa230
	ctx.lr = 0x82661BEC;
	sub_821FA230(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82661C00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r3,r5,5548
	ctx.r3.s64 = ctx.r5.s64 + 5548;
	// bl 0x821fa230
	ctx.lr = 0x82661C0C;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82661C20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82661C30"))) PPC_WEAK_FUNC(sub_82661C30);
PPC_FUNC_IMPL(__imp__sub_82661C30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82660050
	ctx.lr = 0x82661C44;
	sub_82660050(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,5452
	ctx.r4.s64 = ctx.r10.s64 + 5452;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82691650
	ctx.lr = 0x82661C64;
	sub_82691650(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r4,r9,5892
	ctx.r4.s64 = ctx.r9.s64 + 5892;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82661C7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,5492
	ctx.r4.s64 = ctx.r6.s64 + 5492;
	// bl 0x82691650
	ctx.lr = 0x82661C8C;
	sub_82691650(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r4,r5,6372
	ctx.r4.s64 = ctx.r5.s64 + 6372;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82661CA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82661CB8"))) PPC_WEAK_FUNC(sub_82661CB8);
PPC_FUNC_IMPL(__imp__sub_82661CB8) {
	PPC_FUNC_PROLOGUE();
	// b 0x82660050
	sub_82660050(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82661CBC"))) PPC_WEAK_FUNC(sub_82661CBC);
PPC_FUNC_IMPL(__imp__sub_82661CBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82661CC0"))) PPC_WEAK_FUNC(sub_82661CC0);
PPC_FUNC_IMPL(__imp__sub_82661CC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82661CC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r30,24(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// lwz r31,16(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// bl 0x82660310
	ctx.lr = 0x82661CE4;
	sub_82660310(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5652
	ctx.r3.s64 = ctx.r9.s64 + 5652;
	// bl 0x821fa230
	ctx.lr = 0x82661CF0;
	sub_821FA230(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82661D04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x82661d4c
	if (!cr6.eq) goto loc_82661D4C;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// blt cr6,0x82661d4c
	if (cr6.lt) goto loc_82661D4C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r29,r11,-15096
	r29.s64 = r11.s64 + -15096;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821fa230
	ctx.lr = 0x82661D24;
	sub_821FA230(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// ori r8,r9,512
	ctx.r8.u64 = ctx.r9.u64 | 512;
	// stw r8,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
	// bl 0x821fa230
	ctx.lr = 0x82661D3C;
	sub_821FA230(ctx, base);
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r6,r7,16
	ctx.r6.u64 = ctx.r7.u64 | 16;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// b 0x82661e10
	goto loc_82661E10;
loc_82661D4C:
	// bl 0x8265e5e8
	ctx.lr = 0x82661D50;
	sub_8265E5E8(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r11,2832(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lbz r10,10850(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10850);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82661dc0
	if (!cr6.eq) goto loc_82661DC0;
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82661dc0
	if (!cr6.eq) goto loc_82661DC0;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r29,r11,-15096
	r29.s64 = r11.s64 + -15096;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821fa230
	ctx.lr = 0x82661D80;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82661D94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821fa230
	ctx.lr = 0x82661D9C;
	sub_821FA230(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// rlwinm r6,r7,0,28,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r6,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, ctx.r6.u32);
	// bl 0x821fa230
	ctx.lr = 0x82661DB4;
	sub_821FA230(ctx, base);
	// lwz r5,16(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r4,r5,0,23,21
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFFFFFFFDFF;
	// b 0x82661e0c
	goto loc_82661E0C;
loc_82661DC0:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r29,r11,-15096
	r29.s64 = r11.s64 + -15096;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821fa230
	ctx.lr = 0x82661DD0;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82661DE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821fa230
	ctx.lr = 0x82661DEC;
	sub_821FA230(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// ori r6,r7,16
	ctx.r6.u64 = ctx.r7.u64 | 16;
	// stw r6,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, ctx.r6.u32);
	// bl 0x821fa230
	ctx.lr = 0x82661E04;
	sub_821FA230(ctx, base);
	// lwz r5,16(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r4,r5,512
	ctx.r4.u64 = ctx.r5.u64 | 512;
loc_82661E0C:
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
loc_82661E10:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5436
	ctx.r3.s64 = r11.s64 + 5436;
	// bl 0x821fa230
	ctx.lr = 0x82661E1C;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82661E30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5452
	ctx.r3.s64 = ctx.r8.s64 + 5452;
	// bl 0x821fa230
	ctx.lr = 0x82661E3C;
	sub_821FA230(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82661E50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r3,r5,5464
	ctx.r3.s64 = ctx.r5.s64 + 5464;
	// bl 0x821fa230
	ctx.lr = 0x82661E5C;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82661E70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bne cr6,0x82661e84
	if (!cr6.eq) goto loc_82661E84;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// li r31,1
	r31.s64 = 1;
	// blt cr6,0x82661e88
	if (cr6.lt) goto loc_82661E88;
loc_82661E84:
	// li r31,0
	r31.s64 = 0;
loc_82661E88:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5576
	ctx.r3.s64 = r11.s64 + 5576;
	// bl 0x821fa230
	ctx.lr = 0x82661E94;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82661EA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r3,-10028(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x82661EB4;
	sub_82207138(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82661f00
	if (cr6.eq) goto loc_82661F00;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5756
	ctx.r3.s64 = r11.s64 + 5756;
	// bl 0x821fa230
	ctx.lr = 0x82661ECC;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82661EE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5492
	ctx.r3.s64 = ctx.r8.s64 + 5492;
	// bl 0x821fa230
	ctx.lr = 0x82661EEC;
	sub_821FA230(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82661F00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82661F00:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,6420
	ctx.r3.s64 = r11.s64 + 6420;
	// bl 0x821fa230
	ctx.lr = 0x82661F0C;
	sub_821FA230(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82661F18;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r30,r1,84
	r30.s64 = ctx.r1.s64 + 84;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,-10240(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82661F34;
	sub_82270170(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82272fc0
	ctx.lr = 0x82661F40;
	sub_82272FC0(ctx, base);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bgt cr6,0x82661f78
	if (cr6.gt) goto loc_82661F78;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgt cr6,0x82661f78
	if (cr6.gt) goto loc_82661F78;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82661F70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82661F78:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82661F90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r9,340(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// ble cr6,0x82661fc0
	if (!cr6.gt) goto loc_82661FC0;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,6388
	ctx.r4.s64 = ctx.r10.s64 + 6388;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82661FB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82661FC0:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,25900
	ctx.r4.s64 = ctx.r10.s64 + 25900;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82661FD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82661FD8"))) PPC_WEAK_FUNC(sub_82661FD8);
PPC_FUNC_IMPL(__imp__sub_82661FD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82661FE0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82660310
	ctx.lr = 0x82661FEC;
	sub_82660310(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r30,r11,5452
	r30.s64 = r11.s64 + 5452;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821fa230
	ctx.lr = 0x82661FFC;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82662010;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r29,r8,5464
	r29.s64 = ctx.r8.s64 + 5464;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821fa230
	ctx.lr = 0x82662020;
	sub_821FA230(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82662034;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r28,r5,5480
	r28.s64 = ctx.r5.s64 + 5480;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821fa230
	ctx.lr = 0x82662044;
	sub_821FA230(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r31,0(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// bl 0x8265eb48
	ctx.lr = 0x82662050;
	sub_8265EB48(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82662064;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821fa230
	ctx.lr = 0x8266206C;
	sub_821FA230(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// rlwinm r8,r9,0,28,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r8,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r8.u32);
	// bl 0x821fa230
	ctx.lr = 0x82662084;
	sub_821FA230(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// rlwinm r5,r6,0,28,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r5,16(r7)
	PPC_STORE_U32(ctx.r7.u32 + 16, ctx.r5.u32);
	// bl 0x821fa230
	ctx.lr = 0x8266209C;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// addi r3,r3,5628
	ctx.r3.s64 = ctx.r3.s64 + 5628;
	// lwz r11,16(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// rlwinm r10,r11,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r10,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r10.u32);
	// bl 0x821fa230
	ctx.lr = 0x826620B8;
	sub_821FA230(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826620CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r3,r7,5608
	ctx.r3.s64 = ctx.r7.s64 + 5608;
	// bl 0x821fa230
	ctx.lr = 0x826620D8;
	sub_821FA230(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,76(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826620EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r3,r4,5396
	ctx.r3.s64 = ctx.r4.s64 + 5396;
	// bl 0x821fa230
	ctx.lr = 0x826620F8;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266210C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5380
	ctx.r3.s64 = ctx.r9.s64 + 5380;
	// bl 0x821fa230
	ctx.lr = 0x82662118;
	sub_821FA230(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266212C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r3,r6,5436
	ctx.r3.s64 = ctx.r6.s64 + 5436;
	// bl 0x821fa230
	ctx.lr = 0x82662138;
	sub_821FA230(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266214C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r3,r10,5592
	ctx.r3.s64 = ctx.r10.s64 + 5592;
	// bl 0x821fa230
	ctx.lr = 0x82662158;
	sub_821FA230(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266216C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r3,r7,5576
	ctx.r3.s64 = ctx.r7.s64 + 5576;
	// bl 0x821fa230
	ctx.lr = 0x82662178;
	sub_821FA230(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,76(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8266218C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r3,r4,5564
	ctx.r3.s64 = ctx.r4.s64 + 5564;
	// bl 0x821fa230
	ctx.lr = 0x82662198;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826621AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5548
	ctx.r3.s64 = ctx.r9.s64 + 5548;
	// bl 0x821fa230
	ctx.lr = 0x826621B8;
	sub_821FA230(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826621CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r3,r6,5532
	ctx.r3.s64 = ctx.r6.s64 + 5532;
	// bl 0x821fa230
	ctx.lr = 0x826621D8;
	sub_821FA230(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x826621EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826621F4"))) PPC_WEAK_FUNC(sub_826621F4);
PPC_FUNC_IMPL(__imp__sub_826621F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826621F8"))) PPC_WEAK_FUNC(sub_826621F8);
PPC_FUNC_IMPL(__imp__sub_826621F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82660050
	ctx.lr = 0x8266220C;
	sub_82660050(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,5480
	ctx.r4.s64 = ctx.r10.s64 + 5480;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82691650
	ctx.lr = 0x8266222C;
	sub_82691650(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r4,r9,6492
	ctx.r4.s64 = ctx.r9.s64 + 6492;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82662244;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,5452
	ctx.r4.s64 = ctx.r6.s64 + 5452;
	// bl 0x82691650
	ctx.lr = 0x82662254;
	sub_82691650(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r4,r5,6464
	ctx.r4.s64 = ctx.r5.s64 + 6464;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266226C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,5464
	ctx.r4.s64 = ctx.r9.s64 + 5464;
	// bl 0x82691650
	ctx.lr = 0x8266227C;
	sub_82691650(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r4,r8,6436
	ctx.r4.s64 = ctx.r8.s64 + 6436;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82662294;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826622A8"))) PPC_WEAK_FUNC(sub_826622A8);
PPC_FUNC_IMPL(__imp__sub_826622A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x826622B0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-10720
	ctx.r4.s64 = r11.s64 + -10720;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x826622D4;
	sub_82691650(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r10,6540
	ctx.r4.s64 = ctx.r10.s64 + 6540;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x826622F0;
	sub_82691650(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r4,r9,6524
	ctx.r4.s64 = ctx.r9.s64 + 6524;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8266230C;
	sub_82691650(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r4,r8,5368
	ctx.r4.s64 = ctx.r8.s64 + 5368;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82662328;
	sub_82691650(ctx, base);
	// lwz r7,2176(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 2176);
	// addi r29,r31,2176
	r29.s64 = r31.s64 + 2176;
	// li r30,4
	r30.s64 = 4;
	// stw r28,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, r28.u32);
	// lwz r6,2180(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 2180);
	// stw r27,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, r27.u32);
	// lwz r5,2184(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 2184);
	// stw r26,12(r5)
	PPC_STORE_U32(ctx.r5.u32 + 12, r26.u32);
	// lwz r4,2188(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 2188);
	// stw r3,12(r4)
	PPC_STORE_U32(ctx.r4.u32 + 12, ctx.r3.u32);
	// lwz r3,2188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2188);
	// lwz r10,2180(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 2180);
	// lwz r9,2184(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 2184);
	// lwz r11,2176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2176);
	// stw r11,1344(r31)
	PPC_STORE_U32(r31.u32 + 1344, r11.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r9,1856(r31)
	PPC_STORE_U32(r31.u32 + 1856, ctx.r9.u32);
	// stw r10,1600(r31)
	PPC_STORE_U32(r31.u32 + 1600, ctx.r10.u32);
	// stw r3,2112(r31)
	PPC_STORE_U32(r31.u32 + 2112, ctx.r3.u32);
	// addi r31,r11,3998
	r31.s64 = r11.s64 + 3998;
loc_82662378:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82662394;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x82662378
	if (!cr0.eq) goto loc_82662378;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826623A8"))) PPC_WEAK_FUNC(sub_826623A8);
PPC_FUNC_IMPL(__imp__sub_826623A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826623B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x82661000
	ctx.lr = 0x826623C4;
	sub_82661000(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826623DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826624a0
	if (!cr6.eq) goto loc_826624A0;
	// cmpwi cr6,r31,55
	cr6.compare<int32_t>(r31.s32, 55, xer);
	// beq cr6,0x8266243c
	if (cr6.eq) goto loc_8266243C;
	// cmpwi cr6,r31,59
	cr6.compare<int32_t>(r31.s32, 59, xer);
	// beq cr6,0x82662410
	if (cr6.eq) goto loc_82662410;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826309e0
	ctx.lr = 0x82662408;
	sub_826309E0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82662410:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r10,2368(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 2368);
	// addi r9,r11,28388
	ctx.r9.s64 = r11.s64 + 28388;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x826624a0
	if (!cr6.eq) goto loc_826624A0;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stb r11,-12456(r10)
	PPC_STORE_U8(ctx.r10.u32 + -12456, r11.u8);
	// bl 0x82650038
	ctx.lr = 0x82662434;
	sub_82650038(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8266243C:
	// li r11,52
	r11.s64 = 52;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82661210
	ctx.lr = 0x8266244C;
	sub_82661210(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826624a0
	if (cr6.eq) goto loc_826624A0;
	// bl 0x8265e550
	ctx.lr = 0x8266245C;
	sub_8265E550(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// bne cr6,0x82662478
	if (!cr6.eq) goto loc_82662478;
	// li r4,0
	ctx.r4.s64 = 0;
loc_82662478:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addis r5,r11,4
	ctx.r5.s64 = r11.s64 + 262144;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r5,976
	ctx.r5.s64 = ctx.r5.s64 + 976;
	// lwz r9,292(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 292);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826624A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826624A0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826624AC"))) PPC_WEAK_FUNC(sub_826624AC);
PPC_FUNC_IMPL(__imp__sub_826624AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826624B0"))) PPC_WEAK_FUNC(sub_826624B0);
PPC_FUNC_IMPL(__imp__sub_826624B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,192(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_826624C4"))) PPC_WEAK_FUNC(sub_826624C4);
PPC_FUNC_IMPL(__imp__sub_826624C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826624C8"))) PPC_WEAK_FUNC(sub_826624C8);
PPC_FUNC_IMPL(__imp__sub_826624C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r23{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x826624D0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// std r10,240(r1)
	PPC_STORE_U64(ctx.r1.u32 + 240, ctx.r10.u64);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r11,24324
	ctx.r4.s64 = r11.s64 + 24324;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r23,r8
	r23.u64 = ctx.r8.u64;
	// bl 0x8262ffe0
	ctx.lr = 0x82662504;
	sub_8262FFE0(ctx, base);
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r9,468(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 468);
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266251C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,196(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 196);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82662530;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82662548;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,496(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,340(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 340);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82662560;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r10,r31,1360
	ctx.r10.s64 = r31.s64 + 1360;
	// addi r11,r1,240
	r11.s64 = ctx.r1.s64 + 240;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82662570:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82662570
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82662570;
	// lhz r10,852(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r8,848(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// cmplw cr6,r10,r10
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r10.u32, xer);
	// beq cr6,0x826625bc
	if (cr6.eq) goto loc_826625BC;
	// subf r7,r10,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r10.s64;
loc_826625A8:
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r6.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x826625a8
	if (!cr6.eq) goto loc_826625A8;
loc_826625BC:
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// addi r29,r31,1152
	r29.s64 = r31.s64 + 1152;
	// srawi r8,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 2;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// clrlwi r5,r7,16
	ctx.r5.u64 = ctx.r7.u32 & 0xFFFF;
	// sth r7,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r7.u16);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// rotlwi r8,r5,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// sth r4,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r4.u16);
	// stwx r29,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r29.u32);
	// beq cr6,0x82662618
	if (cr6.eq) goto loc_82662618;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// addi r7,r31,944
	ctx.r7.s64 = r31.s64 + 944;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r6,r8,1
	ctx.r6.s64 = ctx.r8.s64 + 1;
	// sth r6,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r6.u16);
	// stwx r7,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r7.u32);
loc_82662618:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82662630;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,944(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 944);
	// addi r30,r31,944
	r30.s64 = r31.s64 + 944;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266264C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,944(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 944);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82662664;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r28,-32111
	r28.s64 = -2104426496;
	// li r25,1
	r25.s64 = 1;
	// lwz r3,-29340(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -29340);
	// bl 0x8269ec68
	ctx.lr = 0x82662674;
	sub_8269EC68(ctx, base);
	// lis r26,-32121
	r26.s64 = -2105081856;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x826626b8
	if (cr6.eq) goto loc_826626B8;
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826626b8
	if (cr6.eq) goto loc_826626B8;
	// lwz r3,-10028(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x82662694;
	sub_82207138(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826626b8
	if (!cr6.eq) goto loc_826626B8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826626B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826626B8:
	// lwz r3,-29340(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -29340);
	// bl 0x8269ea88
	ctx.lr = 0x826626C0;
	sub_8269EA88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x826626dc
	if (!cr6.eq) goto loc_826626DC;
	// lwz r3,-10028(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x826626D0;
	sub_82207138(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826626f8
	if (cr6.eq) goto loc_826626F8;
loc_826626DC:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r25,0
	r25.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826626F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826626F8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// stb r23,1380(r31)
	PPC_STORE_U8(r31.u32 + 1380, r23.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,704(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 704);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82662714;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,672(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r8,648(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 648);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266272C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82662734"))) PPC_WEAK_FUNC(sub_82662734);
PPC_FUNC_IMPL(__imp__sub_82662734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82662738"))) PPC_WEAK_FUNC(sub_82662738);
PPC_FUNC_IMPL(__imp__sub_82662738) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r30,r11,3998
	r30.s64 = r11.s64 + 3998;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x82662774;
	sub_8228F920(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r3,r31,944
	ctx.r3.s64 = r31.s64 + 944;
	// addi r9,r10,7300
	ctx.r9.s64 = ctx.r10.s64 + 7300;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82633d40
	ctx.lr = 0x82662790;
	sub_82633D40(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r31,1152
	ctx.r3.s64 = r31.s64 + 1152;
	// addi r4,r8,7280
	ctx.r4.s64 = ctx.r8.s64 + 7280;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82633d40
	ctx.lr = 0x826627A4;
	sub_82633D40(ctx, base);
	// addi r3,r31,1360
	ctx.r3.s64 = r31.s64 + 1360;
	// bl 0x821c2f70
	ctx.lr = 0x826627AC;
	sub_821C2F70(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826627C8"))) PPC_WEAK_FUNC(sub_826627C8);
PPC_FUNC_IMPL(__imp__sub_826627C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82630580
	ctx.lr = 0x826627E0;
	sub_82630580(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r31,1360
	ctx.r3.s64 = r31.s64 + 1360;
	// bl 0x821c3048
	ctx.lr = 0x826627EC;
	sub_821C3048(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82662800"))) PPC_WEAK_FUNC(sub_82662800);
PPC_FUNC_IMPL(__imp__sub_82662800) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5288
	ctx.r3.s64 = r11.s64 + 5288;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266280C"))) PPC_WEAK_FUNC(sub_8266280C);
PPC_FUNC_IMPL(__imp__sub_8266280C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82662810"))) PPC_WEAK_FUNC(sub_82662810);
PPC_FUNC_IMPL(__imp__sub_82662810) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5328
	ctx.r3.s64 = r11.s64 + 5328;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266281C"))) PPC_WEAK_FUNC(sub_8266281C);
PPC_FUNC_IMPL(__imp__sub_8266281C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82662820"))) PPC_WEAK_FUNC(sub_82662820);
PPC_FUNC_IMPL(__imp__sub_82662820) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,8224
	ctx.r3.s64 = r11.s64 + 8224;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266282C"))) PPC_WEAK_FUNC(sub_8266282C);
PPC_FUNC_IMPL(__imp__sub_8266282C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82662830"))) PPC_WEAK_FUNC(sub_82662830);
PPC_FUNC_IMPL(__imp__sub_82662830) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,8252
	ctx.r3.s64 = r11.s64 + 8252;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266283C"))) PPC_WEAK_FUNC(sub_8266283C);
PPC_FUNC_IMPL(__imp__sub_8266283C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82662840"))) PPC_WEAK_FUNC(sub_82662840);
PPC_FUNC_IMPL(__imp__sub_82662840) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// bl 0x82646f40
	ctx.lr = 0x82662864;
	sub_82646F40(ctx, base);
	// addi r3,r31,1808
	ctx.r3.s64 = r31.s64 + 1808;
	// bl 0x8221fbc8
	ctx.lr = 0x8266286C;
	sub_8221FBC8(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x8221fbc8
	ctx.lr = 0x82662874;
	sub_8221FBC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8266287C;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662894
	if (cr6.eq) goto loc_82662894;
	// bl 0x82130588
	ctx.lr = 0x82662890;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82662894:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826628AC"))) PPC_WEAK_FUNC(sub_826628AC);
PPC_FUNC_IMPL(__imp__sub_826628AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826628B0"))) PPC_WEAK_FUNC(sub_826628B0);
PPC_FUNC_IMPL(__imp__sub_826628B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x826628B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r31,r29,2176
	r31.s64 = r29.s64 + 2176;
	// addi r10,r11,8284
	ctx.r10.s64 = r11.s64 + 8284;
	// li r30,4
	r30.s64 = 4;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
loc_826628D4:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826628f4
	if (cr6.eq) goto loc_826628F4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826628F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826628F4:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x826628d4
	if (!cr0.eq) goto loc_826628D4;
	// addis r31,r29,1
	r31.s64 = r29.s64 + 65536;
	// addi r31,r31,8576
	r31.s64 = r31.s64 + 8576;
	// addi r30,r31,1152
	r30.s64 = r31.s64 + 1152;
	// lhz r11,1346(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1346);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662920
	if (cr6.eq) goto loc_82662920;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82662920;
	sub_82130588(ctx, base);
loc_82662920:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662928;
	sub_82633B00(ctx, base);
	// lhz r11,1138(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1138);
	// addi r30,r31,944
	r30.s64 = r31.s64 + 944;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662940
	if (cr6.eq) goto loc_82662940;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82662940;
	sub_82130588(ctx, base);
loc_82662940:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662948;
	sub_82633B00(ctx, base);
	// lhz r11,886(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 886);
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662960
	if (cr6.eq) goto loc_82662960;
	// lwz r3,208(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x82662960;
	sub_82130588(ctx, base);
loc_82662960:
	// lhz r11,182(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662974
	if (cr6.eq) goto loc_82662974;
	// lwz r3,176(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x82662974;
	sub_82130588(ctx, base);
loc_82662974:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266297C;
	sub_82633B00(ctx, base);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x82662984;
	sub_82633B00(ctx, base);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x8266298C;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662994;
	sub_82633B00(ctx, base);
	// addis r3,r29,1
	ctx.r3.s64 = r29.s64 + 65536;
	// addi r3,r3,6784
	ctx.r3.s64 = ctx.r3.s64 + 6784;
	// bl 0x8221fbc8
	ctx.lr = 0x826629A0;
	sub_8221FBC8(ctx, base);
	// addis r30,r29,1
	r30.s64 = r29.s64 + 65536;
	// addi r30,r30,1792
	r30.s64 = r30.s64 + 1792;
	// addi r31,r30,3600
	r31.s64 = r30.s64 + 3600;
	// addi r28,r31,1152
	r28.s64 = r31.s64 + 1152;
	// lhz r11,4946(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4946);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826629c4
	if (cr6.eq) goto loc_826629C4;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x826629C4;
	sub_82130588(ctx, base);
loc_826629C4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x826629CC;
	sub_82633B00(ctx, base);
	// lhz r11,1138(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1138);
	// addi r28,r31,944
	r28.s64 = r31.s64 + 944;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826629e4
	if (cr6.eq) goto loc_826629E4;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x826629E4;
	sub_82130588(ctx, base);
loc_826629E4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x826629EC;
	sub_82633B00(ctx, base);
	// lhz r11,886(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 886);
	// addi r28,r31,672
	r28.s64 = r31.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662a04
	if (cr6.eq) goto loc_82662A04;
	// lwz r3,208(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x82662A04;
	sub_82130588(ctx, base);
loc_82662A04:
	// lhz r11,182(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662a18
	if (cr6.eq) goto loc_82662A18;
	// lwz r3,176(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x82662A18;
	sub_82130588(ctx, base);
loc_82662A18:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662A20;
	sub_82633B00(ctx, base);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x82662A28;
	sub_82633B00(ctx, base);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x82662A30;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662A38;
	sub_82633B00(ctx, base);
	// addi r3,r30,1808
	ctx.r3.s64 = r30.s64 + 1808;
	// bl 0x8221fbc8
	ctx.lr = 0x82662A40;
	sub_8221FBC8(ctx, base);
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x8221fbc8
	ctx.lr = 0x82662A48;
	sub_8221FBC8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x82662A50;
	sub_821D2028(ctx, base);
	// addis r30,r29,1
	r30.s64 = r29.s64 + 65536;
	// addi r30,r30,-3200
	r30.s64 = r30.s64 + -3200;
	// addi r31,r30,3600
	r31.s64 = r30.s64 + 3600;
	// addi r28,r31,1152
	r28.s64 = r31.s64 + 1152;
	// lhz r11,4946(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4946);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662a74
	if (cr6.eq) goto loc_82662A74;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82662A74;
	sub_82130588(ctx, base);
loc_82662A74:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662A7C;
	sub_82633B00(ctx, base);
	// lhz r11,1138(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1138);
	// addi r28,r31,944
	r28.s64 = r31.s64 + 944;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662a94
	if (cr6.eq) goto loc_82662A94;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82662A94;
	sub_82130588(ctx, base);
loc_82662A94:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662A9C;
	sub_82633B00(ctx, base);
	// lhz r11,886(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 886);
	// addi r28,r31,672
	r28.s64 = r31.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662ab4
	if (cr6.eq) goto loc_82662AB4;
	// lwz r3,208(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x82662AB4;
	sub_82130588(ctx, base);
loc_82662AB4:
	// lhz r11,182(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662ac8
	if (cr6.eq) goto loc_82662AC8;
	// lwz r3,176(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x82662AC8;
	sub_82130588(ctx, base);
loc_82662AC8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662AD0;
	sub_82633B00(ctx, base);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x82662AD8;
	sub_82633B00(ctx, base);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x82662AE0;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662AE8;
	sub_82633B00(ctx, base);
	// addi r3,r30,1808
	ctx.r3.s64 = r30.s64 + 1808;
	// bl 0x8221fbc8
	ctx.lr = 0x82662AF0;
	sub_8221FBC8(ctx, base);
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x8221fbc8
	ctx.lr = 0x82662AF8;
	sub_8221FBC8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x82662B00;
	sub_821D2028(ctx, base);
	// addis r30,r29,1
	r30.s64 = r29.s64 + 65536;
	// addi r30,r30,-8208
	r30.s64 = r30.s64 + -8208;
	// addi r31,r30,3600
	r31.s64 = r30.s64 + 3600;
	// addi r28,r31,1152
	r28.s64 = r31.s64 + 1152;
	// lhz r11,4946(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4946);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662b24
	if (cr6.eq) goto loc_82662B24;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82662B24;
	sub_82130588(ctx, base);
loc_82662B24:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662B2C;
	sub_82633B00(ctx, base);
	// lhz r11,1138(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1138);
	// addi r28,r31,944
	r28.s64 = r31.s64 + 944;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662b44
	if (cr6.eq) goto loc_82662B44;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82662B44;
	sub_82130588(ctx, base);
loc_82662B44:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662B4C;
	sub_82633B00(ctx, base);
	// lhz r11,886(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 886);
	// addi r28,r31,672
	r28.s64 = r31.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662b64
	if (cr6.eq) goto loc_82662B64;
	// lwz r3,208(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x82662B64;
	sub_82130588(ctx, base);
loc_82662B64:
	// lhz r11,182(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662b78
	if (cr6.eq) goto loc_82662B78;
	// lwz r3,176(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x82662B78;
	sub_82130588(ctx, base);
loc_82662B78:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662B80;
	sub_82633B00(ctx, base);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x82662B88;
	sub_82633B00(ctx, base);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x82662B90;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662B98;
	sub_82633B00(ctx, base);
	// addi r3,r30,1808
	ctx.r3.s64 = r30.s64 + 1808;
	// bl 0x8221fbc8
	ctx.lr = 0x82662BA0;
	sub_8221FBC8(ctx, base);
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x8221fbc8
	ctx.lr = 0x82662BA8;
	sub_8221FBC8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x82662BB0;
	sub_821D2028(ctx, base);
	// addis r30,r29,1
	r30.s64 = r29.s64 + 65536;
	// addi r30,r30,-13200
	r30.s64 = r30.s64 + -13200;
	// addi r31,r30,3600
	r31.s64 = r30.s64 + 3600;
	// addi r28,r31,1152
	r28.s64 = r31.s64 + 1152;
	// lhz r11,4946(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4946);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662bd4
	if (cr6.eq) goto loc_82662BD4;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82662BD4;
	sub_82130588(ctx, base);
loc_82662BD4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662BDC;
	sub_82633B00(ctx, base);
	// lhz r11,1138(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1138);
	// addi r28,r31,944
	r28.s64 = r31.s64 + 944;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662bf4
	if (cr6.eq) goto loc_82662BF4;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82662BF4;
	sub_82130588(ctx, base);
loc_82662BF4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662BFC;
	sub_82633B00(ctx, base);
	// lhz r11,886(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 886);
	// addi r28,r31,672
	r28.s64 = r31.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662c14
	if (cr6.eq) goto loc_82662C14;
	// lwz r3,208(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x82662C14;
	sub_82130588(ctx, base);
loc_82662C14:
	// lhz r11,182(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662c28
	if (cr6.eq) goto loc_82662C28;
	// lwz r3,176(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x82662C28;
	sub_82130588(ctx, base);
loc_82662C28:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662C30;
	sub_82633B00(ctx, base);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x82662C38;
	sub_82633B00(ctx, base);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x82662C40;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662C48;
	sub_82633B00(ctx, base);
	// addi r3,r30,1808
	ctx.r3.s64 = r30.s64 + 1808;
	// bl 0x8221fbc8
	ctx.lr = 0x82662C50;
	sub_8221FBC8(ctx, base);
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x8221fbc8
	ctx.lr = 0x82662C58;
	sub_8221FBC8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x82662C60;
	sub_821D2028(ctx, base);
	// addis r30,r29,1
	r30.s64 = r29.s64 + 65536;
	// addi r30,r30,-18192
	r30.s64 = r30.s64 + -18192;
	// addi r31,r30,3600
	r31.s64 = r30.s64 + 3600;
	// addi r28,r31,1152
	r28.s64 = r31.s64 + 1152;
	// lhz r11,4946(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4946);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662c84
	if (cr6.eq) goto loc_82662C84;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82662C84;
	sub_82130588(ctx, base);
loc_82662C84:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662C8C;
	sub_82633B00(ctx, base);
	// lhz r11,1138(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1138);
	// addi r28,r31,944
	r28.s64 = r31.s64 + 944;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662ca4
	if (cr6.eq) goto loc_82662CA4;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82662CA4;
	sub_82130588(ctx, base);
loc_82662CA4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662CAC;
	sub_82633B00(ctx, base);
	// lhz r11,886(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 886);
	// addi r28,r31,672
	r28.s64 = r31.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662cc4
	if (cr6.eq) goto loc_82662CC4;
	// lwz r3,208(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x82662CC4;
	sub_82130588(ctx, base);
loc_82662CC4:
	// lhz r11,182(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662cd8
	if (cr6.eq) goto loc_82662CD8;
	// lwz r3,176(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x82662CD8;
	sub_82130588(ctx, base);
loc_82662CD8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662CE0;
	sub_82633B00(ctx, base);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x82662CE8;
	sub_82633B00(ctx, base);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x82662CF0;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662CF8;
	sub_82633B00(ctx, base);
	// addi r3,r30,1808
	ctx.r3.s64 = r30.s64 + 1808;
	// bl 0x8221fbc8
	ctx.lr = 0x82662D00;
	sub_8221FBC8(ctx, base);
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x8221fbc8
	ctx.lr = 0x82662D08;
	sub_8221FBC8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x82662D10;
	sub_821D2028(ctx, base);
	// addis r30,r29,1
	r30.s64 = r29.s64 + 65536;
	// addi r30,r30,-23184
	r30.s64 = r30.s64 + -23184;
	// addi r31,r30,3600
	r31.s64 = r30.s64 + 3600;
	// addi r28,r31,1152
	r28.s64 = r31.s64 + 1152;
	// lhz r11,4946(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4946);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662d34
	if (cr6.eq) goto loc_82662D34;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82662D34;
	sub_82130588(ctx, base);
loc_82662D34:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662D3C;
	sub_82633B00(ctx, base);
	// lhz r11,1138(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1138);
	// addi r28,r31,944
	r28.s64 = r31.s64 + 944;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662d54
	if (cr6.eq) goto loc_82662D54;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82662D54;
	sub_82130588(ctx, base);
loc_82662D54:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662D5C;
	sub_82633B00(ctx, base);
	// lhz r11,886(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 886);
	// addi r28,r31,672
	r28.s64 = r31.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662d74
	if (cr6.eq) goto loc_82662D74;
	// lwz r3,208(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x82662D74;
	sub_82130588(ctx, base);
loc_82662D74:
	// lhz r11,182(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662d88
	if (cr6.eq) goto loc_82662D88;
	// lwz r3,176(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x82662D88;
	sub_82130588(ctx, base);
loc_82662D88:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662D90;
	sub_82633B00(ctx, base);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x82662D98;
	sub_82633B00(ctx, base);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x82662DA0;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662DA8;
	sub_82633B00(ctx, base);
	// addi r3,r30,1808
	ctx.r3.s64 = r30.s64 + 1808;
	// bl 0x8221fbc8
	ctx.lr = 0x82662DB0;
	sub_8221FBC8(ctx, base);
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x8221fbc8
	ctx.lr = 0x82662DB8;
	sub_8221FBC8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x82662DC0;
	sub_821D2028(ctx, base);
	// addis r30,r29,1
	r30.s64 = r29.s64 + 65536;
	// addi r30,r30,-28176
	r30.s64 = r30.s64 + -28176;
	// addi r31,r30,3600
	r31.s64 = r30.s64 + 3600;
	// addi r28,r31,1152
	r28.s64 = r31.s64 + 1152;
	// lhz r11,4946(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4946);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662de4
	if (cr6.eq) goto loc_82662DE4;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82662DE4;
	sub_82130588(ctx, base);
loc_82662DE4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662DEC;
	sub_82633B00(ctx, base);
	// lhz r11,1138(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1138);
	// addi r28,r31,944
	r28.s64 = r31.s64 + 944;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662e04
	if (cr6.eq) goto loc_82662E04;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82662E04;
	sub_82130588(ctx, base);
loc_82662E04:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662E0C;
	sub_82633B00(ctx, base);
	// lhz r11,886(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 886);
	// addi r28,r31,672
	r28.s64 = r31.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662e24
	if (cr6.eq) goto loc_82662E24;
	// lwz r3,208(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x82662E24;
	sub_82130588(ctx, base);
loc_82662E24:
	// lhz r11,182(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662e38
	if (cr6.eq) goto loc_82662E38;
	// lwz r3,176(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x82662E38;
	sub_82130588(ctx, base);
loc_82662E38:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662E40;
	sub_82633B00(ctx, base);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x82662E48;
	sub_82633B00(ctx, base);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x82662E50;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662E58;
	sub_82633B00(ctx, base);
	// addi r3,r30,1808
	ctx.r3.s64 = r30.s64 + 1808;
	// bl 0x8221fbc8
	ctx.lr = 0x82662E60;
	sub_8221FBC8(ctx, base);
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x8221fbc8
	ctx.lr = 0x82662E68;
	sub_8221FBC8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x82662E70;
	sub_821D2028(ctx, base);
	// addi r30,r29,32368
	r30.s64 = r29.s64 + 32368;
	// addi r31,r30,3600
	r31.s64 = r30.s64 + 3600;
	// addi r28,r31,1152
	r28.s64 = r31.s64 + 1152;
	// lhz r11,4946(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4946);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662e90
	if (cr6.eq) goto loc_82662E90;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82662E90;
	sub_82130588(ctx, base);
loc_82662E90:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662E98;
	sub_82633B00(ctx, base);
	// lhz r11,1138(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1138);
	// addi r28,r31,944
	r28.s64 = r31.s64 + 944;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662eb0
	if (cr6.eq) goto loc_82662EB0;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82662EB0;
	sub_82130588(ctx, base);
loc_82662EB0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662EB8;
	sub_82633B00(ctx, base);
	// lhz r11,886(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 886);
	// addi r28,r31,672
	r28.s64 = r31.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662ed0
	if (cr6.eq) goto loc_82662ED0;
	// lwz r3,208(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x82662ED0;
	sub_82130588(ctx, base);
loc_82662ED0:
	// lhz r11,182(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662ee4
	if (cr6.eq) goto loc_82662EE4;
	// lwz r3,176(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x82662EE4;
	sub_82130588(ctx, base);
loc_82662EE4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662EEC;
	sub_82633B00(ctx, base);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x82662EF4;
	sub_82633B00(ctx, base);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x82662EFC;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662F04;
	sub_82633B00(ctx, base);
	// addi r3,r30,1808
	ctx.r3.s64 = r30.s64 + 1808;
	// bl 0x8221fbc8
	ctx.lr = 0x82662F0C;
	sub_8221FBC8(ctx, base);
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x8221fbc8
	ctx.lr = 0x82662F14;
	sub_8221FBC8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x82662F1C;
	sub_821D2028(ctx, base);
	// addi r30,r29,27376
	r30.s64 = r29.s64 + 27376;
	// lhz r11,32322(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 32322);
	// addi r31,r30,3600
	r31.s64 = r30.s64 + 3600;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r28,r31,1152
	r28.s64 = r31.s64 + 1152;
	// beq cr6,0x82662f3c
	if (cr6.eq) goto loc_82662F3C;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82662F3C;
	sub_82130588(ctx, base);
loc_82662F3C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662F44;
	sub_82633B00(ctx, base);
	// lhz r11,1138(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1138);
	// addi r28,r31,944
	r28.s64 = r31.s64 + 944;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662f5c
	if (cr6.eq) goto loc_82662F5C;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82662F5C;
	sub_82130588(ctx, base);
loc_82662F5C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662F64;
	sub_82633B00(ctx, base);
	// lhz r11,886(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 886);
	// addi r28,r31,672
	r28.s64 = r31.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662f7c
	if (cr6.eq) goto loc_82662F7C;
	// lwz r3,208(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x82662F7C;
	sub_82130588(ctx, base);
loc_82662F7C:
	// lhz r11,182(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82662f90
	if (cr6.eq) goto loc_82662F90;
	// lwz r3,176(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x82662F90;
	sub_82130588(ctx, base);
loc_82662F90:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662F98;
	sub_82633B00(ctx, base);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x82662FA0;
	sub_82633B00(ctx, base);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x82662FA8;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662FB0;
	sub_82633B00(ctx, base);
	// addi r3,r30,1808
	ctx.r3.s64 = r30.s64 + 1808;
	// bl 0x8221fbc8
	ctx.lr = 0x82662FB8;
	sub_8221FBC8(ctx, base);
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x8221fbc8
	ctx.lr = 0x82662FC0;
	sub_8221FBC8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x82662FC8;
	sub_821D2028(ctx, base);
	// addi r30,r29,22384
	r30.s64 = r29.s64 + 22384;
	// lhz r11,27330(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 27330);
	// addi r31,r30,3600
	r31.s64 = r30.s64 + 3600;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r28,r31,1152
	r28.s64 = r31.s64 + 1152;
	// beq cr6,0x82662fe8
	if (cr6.eq) goto loc_82662FE8;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82662FE8;
	sub_82130588(ctx, base);
loc_82662FE8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82662FF0;
	sub_82633B00(ctx, base);
	// lhz r11,1138(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1138);
	// addi r28,r31,944
	r28.s64 = r31.s64 + 944;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82663008
	if (cr6.eq) goto loc_82663008;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x82663008;
	sub_82130588(ctx, base);
loc_82663008:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82663010;
	sub_82633B00(ctx, base);
	// lhz r11,886(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 886);
	// addi r28,r31,672
	r28.s64 = r31.s64 + 672;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82663028
	if (cr6.eq) goto loc_82663028;
	// lwz r3,208(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x82663028;
	sub_82130588(ctx, base);
loc_82663028:
	// lhz r11,182(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266303c
	if (cr6.eq) goto loc_8266303C;
	// lwz r3,176(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x8266303C;
	sub_82130588(ctx, base);
loc_8266303C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x82663044;
	sub_82633B00(ctx, base);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// bl 0x82633b00
	ctx.lr = 0x8266304C;
	sub_82633B00(ctx, base);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x82633b00
	ctx.lr = 0x82663054;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266305C;
	sub_82633B00(ctx, base);
	// addi r3,r30,1808
	ctx.r3.s64 = r30.s64 + 1808;
	// bl 0x8221fbc8
	ctx.lr = 0x82663064;
	sub_8221FBC8(ctx, base);
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x8221fbc8
	ctx.lr = 0x8266306C;
	sub_8221FBC8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x82663074;
	sub_821D2028(ctx, base);
	// addi r31,r29,17392
	r31.s64 = r29.s64 + 17392;
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// bl 0x82646f40
	ctx.lr = 0x82663080;
	sub_82646F40(ctx, base);
	// addi r3,r31,1808
	ctx.r3.s64 = r31.s64 + 1808;
	// bl 0x8221fbc8
	ctx.lr = 0x82663088;
	sub_8221FBC8(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x8221fbc8
	ctx.lr = 0x82663090;
	sub_8221FBC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x82663098;
	sub_821D2028(ctx, base);
	// addi r31,r29,12400
	r31.s64 = r29.s64 + 12400;
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// bl 0x82646f40
	ctx.lr = 0x826630A4;
	sub_82646F40(ctx, base);
	// addi r3,r31,1808
	ctx.r3.s64 = r31.s64 + 1808;
	// bl 0x8221fbc8
	ctx.lr = 0x826630AC;
	sub_8221FBC8(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x8221fbc8
	ctx.lr = 0x826630B4;
	sub_8221FBC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x826630BC;
	sub_821D2028(ctx, base);
	// addi r31,r29,7408
	r31.s64 = r29.s64 + 7408;
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// bl 0x82646f40
	ctx.lr = 0x826630C8;
	sub_82646F40(ctx, base);
	// addi r3,r31,1808
	ctx.r3.s64 = r31.s64 + 1808;
	// bl 0x8221fbc8
	ctx.lr = 0x826630D0;
	sub_8221FBC8(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x8221fbc8
	ctx.lr = 0x826630D8;
	sub_8221FBC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x826630E0;
	sub_821D2028(ctx, base);
	// addi r31,r29,2416
	r31.s64 = r29.s64 + 2416;
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// bl 0x82646f40
	ctx.lr = 0x826630EC;
	sub_82646F40(ctx, base);
	// addi r3,r31,1808
	ctx.r3.s64 = r31.s64 + 1808;
	// bl 0x8221fbc8
	ctx.lr = 0x826630F4;
	sub_8221FBC8(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x8221fbc8
	ctx.lr = 0x826630FC;
	sub_8221FBC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x82663104;
	sub_821D2028(ctx, base);
	// addi r3,r29,2192
	ctx.r3.s64 = r29.s64 + 2192;
	// bl 0x82633b00
	ctx.lr = 0x8266310C;
	sub_82633B00(ctx, base);
	// lhz r11,2134(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 2134);
	// addi r31,r29,1920
	r31.s64 = r29.s64 + 1920;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82663124
	if (cr6.eq) goto loc_82663124;
	// lwz r3,208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x82663124;
	sub_82130588(ctx, base);
loc_82663124:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82663138
	if (cr6.eq) goto loc_82663138;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x82663138;
	sub_82130588(ctx, base);
loc_82663138:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82663140;
	sub_82633B00(ctx, base);
	// lhz r11,1878(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 1878);
	// addi r31,r29,1664
	r31.s64 = r29.s64 + 1664;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82663158
	if (cr6.eq) goto loc_82663158;
	// lwz r3,208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x82663158;
	sub_82130588(ctx, base);
loc_82663158:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266316c
	if (cr6.eq) goto loc_8266316C;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x8266316C;
	sub_82130588(ctx, base);
loc_8266316C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82663174;
	sub_82633B00(ctx, base);
	// lhz r11,1622(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 1622);
	// addi r31,r29,1408
	r31.s64 = r29.s64 + 1408;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266318c
	if (cr6.eq) goto loc_8266318C;
	// lwz r3,208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x8266318C;
	sub_82130588(ctx, base);
loc_8266318C:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826631a0
	if (cr6.eq) goto loc_826631A0;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x826631A0;
	sub_82130588(ctx, base);
loc_826631A0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x826631A8;
	sub_82633B00(ctx, base);
	// lhz r11,1366(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 1366);
	// addi r31,r29,1152
	r31.s64 = r29.s64 + 1152;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826631c0
	if (cr6.eq) goto loc_826631C0;
	// lwz r3,208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x826631C0;
	sub_82130588(ctx, base);
loc_826631C0:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826631d4
	if (cr6.eq) goto loc_826631D4;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x826631D4;
	sub_82130588(ctx, base);
loc_826631D4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x826631DC;
	sub_82633B00(ctx, base);
	// addi r3,r29,960
	ctx.r3.s64 = r29.s64 + 960;
	// bl 0x82633b00
	ctx.lr = 0x826631E4;
	sub_82633B00(ctx, base);
	// addi r3,r29,768
	ctx.r3.s64 = r29.s64 + 768;
	// bl 0x82633b00
	ctx.lr = 0x826631EC;
	sub_82633B00(ctx, base);
	// addi r3,r29,576
	ctx.r3.s64 = r29.s64 + 576;
	// bl 0x82633b00
	ctx.lr = 0x826631F4;
	sub_82633B00(ctx, base);
	// addi r3,r29,384
	ctx.r3.s64 = r29.s64 + 384;
	// bl 0x82633b00
	ctx.lr = 0x826631FC;
	sub_82633B00(ctx, base);
	// lhz r11,362(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 362);
	// addi r31,r29,176
	r31.s64 = r29.s64 + 176;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82663214
	if (cr6.eq) goto loc_82663214;
	// lwz r3,180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// bl 0x82130588
	ctx.lr = 0x82663214;
	sub_82130588(ctx, base);
loc_82663214:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266321C;
	sub_82633B00(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633b00
	ctx.lr = 0x82663224;
	sub_82633B00(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266322C"))) PPC_WEAK_FUNC(sub_8266322C);
PPC_FUNC_IMPL(__imp__sub_8266322C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82663230"))) PPC_WEAK_FUNC(sub_82663230);
PPC_FUNC_IMPL(__imp__sub_82663230) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82663238;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r30,r11,-21500
	r30.s64 = r11.s64 + -21500;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwz r29,-24180(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x823db670
	ctx.lr = 0x82663264;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821fd7c0
	ctx.lr = 0x82663278;
	sub_821FD7C0(ctx, base);
	// lwz r3,308(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// li r11,0
	r11.s64 = 0;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// lwz r9,10248(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// stb r11,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r11.u8);
	// stw r11,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r11.u32);
	// stw r9,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r9.u32);
	// bne cr6,0x826632ac
	if (!cr6.eq) goto loc_826632AC;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
loc_826632AC:
	// bl 0x822031a8
	ctx.lr = 0x826632B0;
	sub_822031A8(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826632BC"))) PPC_WEAK_FUNC(sub_826632BC);
PPC_FUNC_IMPL(__imp__sub_826632BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826632C0"))) PPC_WEAK_FUNC(sub_826632C0);
PPC_FUNC_IMPL(__imp__sub_826632C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,8972
	ctx.r3.s64 = r11.s64 + 8972;
	// bl 0x82663230
	ctx.lr = 0x826632DC;
	sub_82663230(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r10,8956
	ctx.r3.s64 = ctx.r10.s64 + 8956;
	// bl 0x82663230
	ctx.lr = 0x826632EC;
	sub_82663230(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r9,8940
	ctx.r3.s64 = ctx.r9.s64 + 8940;
	// bl 0x82663230
	ctx.lr = 0x826632FC;
	sub_82663230(ctx, base);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r8,2
	cr6.compare<int32_t>(ctx.r8.s32, 2, xer);
	// beq cr6,0x82663320
	if (cr6.eq) goto loc_82663320;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x82663320
	if (cr6.eq) goto loc_82663320;
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82663350
	if (!cr6.eq) goto loc_82663350;
loc_82663320:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,8932
	ctx.r4.s64 = ctx.r10.s64 + 8932;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82663344;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// bne cr6,0x82663354
	if (!cr6.eq) goto loc_82663354;
loc_82663350:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82663354:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82663364"))) PPC_WEAK_FUNC(sub_82663364);
PPC_FUNC_IMPL(__imp__sub_82663364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82663368"))) PPC_WEAK_FUNC(sub_82663368);
PPC_FUNC_IMPL(__imp__sub_82663368) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r31,r11,-21500
	r31.s64 = r11.s64 + -21500;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,8988
	ctx.r4.s64 = ctx.r9.s64 + 8988;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwz r30,-24180(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x823db670
	ctx.lr = 0x826633A4;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821fd7c0
	ctx.lr = 0x826633B8;
	sub_821FD7C0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// stb r11,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r11.u8);
	// stw r11,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r11.u32);
	// lwz r8,10248(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// stw r31,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r31.u32);
	// stw r8,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r8.u32);
	// lwz r11,308(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826633f4
	if (cr6.eq) goto loc_826633F4;
	// lwz r11,88(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// b 0x826633f8
	goto loc_826633F8;
loc_826633F4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826633F8:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82663410"))) PPC_WEAK_FUNC(sub_82663410);
PPC_FUNC_IMPL(__imp__sub_82663410) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r31,r11,-21500
	r31.s64 = r11.s64 + -21500;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,9000
	ctx.r4.s64 = ctx.r9.s64 + 9000;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwz r30,-24180(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x823db670
	ctx.lr = 0x8266344C;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821fd7c0
	ctx.lr = 0x82663460;
	sub_821FD7C0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// stb r11,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r11.u8);
	// stw r11,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r11.u32);
	// lwz r8,10248(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// stw r31,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r31.u32);
	// stw r8,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r8.u32);
	// lwz r11,308(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266349c
	if (cr6.eq) goto loc_8266349C;
	// lwz r11,88(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// b 0x826634a0
	goto loc_826634A0;
loc_8266349C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826634A0:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826634B8"))) PPC_WEAK_FUNC(sub_826634B8);
PPC_FUNC_IMPL(__imp__sub_826634B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x826634D8;
	sub_82207138(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82663528
	if (!cr6.eq) goto loc_82663528;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826634F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82663528
	if (cr6.eq) goto loc_82663528;
	// bl 0x82663368
	ctx.lr = 0x82663508;
	sub_82663368(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82663528
	if (!cr6.eq) goto loc_82663528;
	// bl 0x82663410
	ctx.lr = 0x82663518;
	sub_82663410(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266352c
	if (cr6.eq) goto loc_8266352C;
loc_82663528:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8266352C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82663540"))) PPC_WEAK_FUNC(sub_82663540);
PPC_FUNC_IMPL(__imp__sub_82663540) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82663368
	ctx.lr = 0x82663550;
	sub_82663368(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82663584
	if (!cr6.eq) goto loc_82663584;
	// bl 0x82663410
	ctx.lr = 0x82663560;
	sub_82663410(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82663584
	if (!cr6.eq) goto loc_82663584;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,9040
	ctx.r3.s64 = r11.s64 + 9040;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82663584:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,9012
	ctx.r3.s64 = r11.s64 + 9012;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266359C"))) PPC_WEAK_FUNC(sub_8266359C);
PPC_FUNC_IMPL(__imp__sub_8266359C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826635A0"))) PPC_WEAK_FUNC(sub_826635A0);
PPC_FUNC_IMPL(__imp__sub_826635A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82663368
	ctx.lr = 0x826635B0;
	sub_82663368(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826635e4
	if (!cr6.eq) goto loc_826635E4;
	// bl 0x82663410
	ctx.lr = 0x826635C0;
	sub_82663410(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826635e4
	if (!cr6.eq) goto loc_826635E4;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,9092
	ctx.r3.s64 = r11.s64 + 9092;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826635E4:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,9064
	ctx.r3.s64 = r11.s64 + 9064;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826635FC"))) PPC_WEAK_FUNC(sub_826635FC);
PPC_FUNC_IMPL(__imp__sub_826635FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82663600"))) PPC_WEAK_FUNC(sub_82663600);
PPC_FUNC_IMPL(__imp__sub_82663600) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82663368
	ctx.lr = 0x82663610;
	sub_82663368(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82663624
	if (!cr6.eq) goto loc_82663624;
	// bl 0x82663410
	ctx.lr = 0x82663620;
	sub_82663410(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
loc_82663624:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5104
	ctx.r3.s64 = r11.s64 + 5104;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266363C"))) PPC_WEAK_FUNC(sub_8266363C);
PPC_FUNC_IMPL(__imp__sub_8266363C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82663640"))) PPC_WEAK_FUNC(sub_82663640);
PPC_FUNC_IMPL(__imp__sub_82663640) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82663648;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x82660310
	ctx.lr = 0x82663654;
	sub_82660310(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,44
	ctx.r4.s64 = 44;
	// lwz r11,-10028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8266366C;
	sub_82641CB0(ctx, base);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,24348
	ctx.r4.s64 = r11.s64 + 24348;
	// addi r3,r3,256
	ctx.r3.s64 = ctx.r3.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82663680;
	sub_8262FFE0(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r3,r10,5436
	ctx.r3.s64 = ctx.r10.s64 + 5436;
	// bl 0x821fa230
	ctx.lr = 0x8266368C;
	sub_821FA230(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826636A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r3,r7,5492
	ctx.r3.s64 = ctx.r7.s64 + 5492;
	// bl 0x821fa230
	ctx.lr = 0x826636AC;
	sub_821FA230(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,-10028(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// lwz r30,0(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x82207138
	ctx.lr = 0x826636BC;
	sub_82207138(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r6,76(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826636D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r3,r5,5452
	ctx.r3.s64 = ctx.r5.s64 + 5452;
	// bl 0x821fa230
	ctx.lr = 0x826636DC;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826636F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5520
	ctx.r3.s64 = ctx.r9.s64 + 5520;
	// bl 0x821fa230
	ctx.lr = 0x826636FC;
	sub_821FA230(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82663710;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r29,24
	ctx.r6.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82663834
	if (cr6.eq) goto loc_82663834;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r30,r11,-21500
	r30.s64 = r11.s64 + -21500;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,9120
	ctx.r4.s64 = ctx.r9.s64 + 9120;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwz r29,-24180(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x823db670
	ctx.lr = 0x82663744;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821fd7c0
	ctx.lr = 0x82663758;
	sub_821FD7C0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// stb r11,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r11.u8);
	// stw r11,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r11.u32);
	// lwz r8,10248(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// stw r8,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r8.u32);
	// lwz r11,308(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// lwz r7,88(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x826637ac
	if (cr6.eq) goto loc_826637AC;
	// lwz r3,-10028(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x8266378C;
	sub_82207138(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826637ac
	if (!cr6.eq) goto loc_826637AC;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5700
	ctx.r3.s64 = r11.s64 + 5700;
	// bl 0x821fa230
	ctx.lr = 0x826637A4;
	sub_821FA230(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x826637bc
	goto loc_826637BC;
loc_826637AC:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5700
	ctx.r3.s64 = r11.s64 + 5700;
	// bl 0x821fa230
	ctx.lr = 0x826637B8;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
loc_826637BC:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826637CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5424
	ctx.r3.s64 = r11.s64 + 5424;
	// bl 0x821fa230
	ctx.lr = 0x826637D8;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826637EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5408
	ctx.r3.s64 = ctx.r8.s64 + 5408;
	// bl 0x821fa230
	ctx.lr = 0x826637F8;
	sub_821FA230(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8266380C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r3,r5,5756
	ctx.r3.s64 = ctx.r5.s64 + 5756;
	// bl 0x821fa230
	ctx.lr = 0x82663818;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266382C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9248
	return;
loc_82663834:
	// bl 0x82387a18
	ctx.lr = 0x82663838;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82663858
	if (!cr6.eq) goto loc_82663858;
	// bl 0x82660230
	ctx.lr = 0x82663848;
	sub_82660230(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8266385c
	if (!cr6.eq) goto loc_8266385C;
loc_82663858:
	// li r31,0
	r31.s64 = 0;
loc_8266385C:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5464
	ctx.r3.s64 = r11.s64 + 5464;
	// bl 0x821fa230
	ctx.lr = 0x82663868;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266387C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82663884"))) PPC_WEAK_FUNC(sub_82663884);
PPC_FUNC_IMPL(__imp__sub_82663884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82663888"))) PPC_WEAK_FUNC(sub_82663888);
PPC_FUNC_IMPL(__imp__sub_82663888) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82663368
	ctx.lr = 0x82663898;
	sub_82663368(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826638cc
	if (!cr6.eq) goto loc_826638CC;
	// bl 0x82663410
	ctx.lr = 0x826638A8;
	sub_82663410(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826638cc
	if (!cr6.eq) goto loc_826638CC;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,9132
	ctx.r3.s64 = r11.s64 + 9132;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826638CC:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,4972
	ctx.r3.s64 = r11.s64 + 4972;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826638E4"))) PPC_WEAK_FUNC(sub_826638E4);
PPC_FUNC_IMPL(__imp__sub_826638E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826638E8"))) PPC_WEAK_FUNC(sub_826638E8);
PPC_FUNC_IMPL(__imp__sub_826638E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82663368
	ctx.lr = 0x826638F8;
	sub_82663368(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8266392c
	if (!cr6.eq) goto loc_8266392C;
	// bl 0x82663410
	ctx.lr = 0x82663908;
	sub_82663410(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8266392c
	if (!cr6.eq) goto loc_8266392C;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,9156
	ctx.r3.s64 = r11.s64 + 9156;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8266392C:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5008
	ctx.r3.s64 = r11.s64 + 5008;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82663944"))) PPC_WEAK_FUNC(sub_82663944);
PPC_FUNC_IMPL(__imp__sub_82663944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82663948"))) PPC_WEAK_FUNC(sub_82663948);
PPC_FUNC_IMPL(__imp__sub_82663948) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82663964;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826639a4
	if (cr6.eq) goto loc_826639A4;
	// bl 0x82663368
	ctx.lr = 0x82663974;
	sub_82663368(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82663990
	if (!cr6.eq) goto loc_82663990;
	// bl 0x82663410
	ctx.lr = 0x82663984;
	sub_82663410(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826639a4
	if (cr6.eq) goto loc_826639A4;
loc_82663990:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826639A4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826639B8"))) PPC_WEAK_FUNC(sub_826639B8);
PPC_FUNC_IMPL(__imp__sub_826639B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826639E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82663b7c
	if (cr6.eq) goto loc_82663B7C;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5368
	ctx.r3.s64 = r11.s64 + 5368;
	// bl 0x821fa230
	ctx.lr = 0x826639F8;
	sub_821FA230(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82663368
	ctx.lr = 0x82663A00;
	sub_82663368(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82663a9c
	if (!cr6.eq) goto loc_82663A9C;
	// bl 0x82663410
	ctx.lr = 0x82663A10;
	sub_82663410(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82663a9c
	if (!cr6.eq) goto loc_82663A9C;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5520
	ctx.r3.s64 = r11.s64 + 5520;
	// bl 0x821fa230
	ctx.lr = 0x82663A28;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82663A34;
	sub_8268CC80(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r3,r10,5756
	ctx.r3.s64 = ctx.r10.s64 + 5756;
	// bl 0x821fa230
	ctx.lr = 0x82663A40;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82663A4C;
	sub_8268CC80(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5504
	ctx.r3.s64 = ctx.r9.s64 + 5504;
	// bl 0x821fa230
	ctx.lr = 0x82663A58;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82663A64;
	sub_8268CC80(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5492
	ctx.r3.s64 = ctx.r8.s64 + 5492;
	// bl 0x821fa230
	ctx.lr = 0x82663A70;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82663A7C;
	sub_8268CC80(ctx, base);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,40(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 40);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82663A90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// b 0x82663b00
	goto loc_82663B00;
loc_82663A9C:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5756
	ctx.r3.s64 = r11.s64 + 5756;
	// bl 0x821fa230
	ctx.lr = 0x82663AA8;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82663AB4;
	sub_8268CC80(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r3,r10,5504
	ctx.r3.s64 = ctx.r10.s64 + 5504;
	// bl 0x821fa230
	ctx.lr = 0x82663AC0;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82663ACC;
	sub_8268CC80(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5492
	ctx.r3.s64 = ctx.r9.s64 + 5492;
	// bl 0x821fa230
	ctx.lr = 0x82663AD8;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82663AE4;
	sub_8268CC80(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,40(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82663AF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
loc_82663B00:
	// beq cr6,0x82663b1c
	if (cr6.eq) goto loc_82663B1C;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5664
	ctx.r3.s64 = r11.s64 + 5664;
	// bl 0x821fa230
	ctx.lr = 0x82663B10;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82663B1C;
	sub_8268CC80(ctx, base);
loc_82663B1C:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5424
	ctx.r3.s64 = r11.s64 + 5424;
	// bl 0x821fa230
	ctx.lr = 0x82663B28;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82663B34;
	sub_8268CC80(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r3,r10,5408
	ctx.r3.s64 = ctx.r10.s64 + 5408;
	// bl 0x821fa230
	ctx.lr = 0x82663B40;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82663B4C;
	sub_8268CC80(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5652
	ctx.r3.s64 = ctx.r9.s64 + 5652;
	// bl 0x821fa230
	ctx.lr = 0x82663B58;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82663B64;
	sub_8268CC80(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5640
	ctx.r3.s64 = ctx.r8.s64 + 5640;
	// bl 0x821fa230
	ctx.lr = 0x82663B70;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82663B7C;
	sub_8268CC80(ctx, base);
loc_82663B7C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82663B94"))) PPC_WEAK_FUNC(sub_82663B94);
PPC_FUNC_IMPL(__imp__sub_82663B94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82663B98"))) PPC_WEAK_FUNC(sub_82663B98);
PPC_FUNC_IMPL(__imp__sub_82663B98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82663BB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82663bf8
	if (cr6.eq) goto loc_82663BF8;
	// bl 0x82663368
	ctx.lr = 0x82663BC4;
	sub_82663368(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82663be0
	if (!cr6.eq) goto loc_82663BE0;
	// bl 0x82663410
	ctx.lr = 0x82663BD4;
	sub_82663410(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82663bf8
	if (cr6.eq) goto loc_82663BF8;
loc_82663BE0:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,9204
	ctx.r3.s64 = r11.s64 + 9204;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82663BF8:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,9180
	ctx.r3.s64 = r11.s64 + 9180;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82663C10"))) PPC_WEAK_FUNC(sub_82663C10);
PPC_FUNC_IMPL(__imp__sub_82663C10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82663C18;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82660050
	ctx.lr = 0x82663C20;
	sub_82660050(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r31,52(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82663368
	ctx.lr = 0x82663C30;
	sub_82663368(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82663c50
	if (!cr6.eq) goto loc_82663C50;
	// bl 0x82663410
	ctx.lr = 0x82663C40;
	sub_82663410(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x82663c54
	if (cr6.eq) goto loc_82663C54;
loc_82663C50:
	// li r11,1
	r11.s64 = 1;
loc_82663C54:
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r29,r11,9364
	r29.s64 = r11.s64 + 9364;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r30,r10,9340
	r30.s64 = ctx.r10.s64 + 9340;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,5756
	ctx.r4.s64 = r11.s64 + 5756;
	// bne cr6,0x82663cbc
	if (!cr6.eq) goto loc_82663CBC;
	// bl 0x82691650
	ctx.lr = 0x82663C84;
	sub_82691650(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82663C98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,5492
	ctx.r4.s64 = ctx.r8.s64 + 5492;
	// bl 0x82691650
	ctx.lr = 0x82663CA8;
	sub_82691650(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// b 0x82663cfc
	goto loc_82663CFC;
loc_82663CBC:
	// bl 0x82691650
	ctx.lr = 0x82663CC0;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,5788
	ctx.r4.s64 = ctx.r10.s64 + 5788;
	// lwz r8,340(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 340);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82663CD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,5492
	ctx.r4.s64 = ctx.r7.s64 + 5492;
	// bl 0x82691650
	ctx.lr = 0x82663CE8;
	sub_82691650(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r4,r6,9316
	ctx.r4.s64 = ctx.r6.s64 + 9316;
	// lwz r11,340(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 340);
	// mtctr r11
	ctr.u64 = r11.u64;
loc_82663CFC:
	// bctrl 
	ctx.lr = 0x82663D00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,5464
	ctx.r4.s64 = r11.s64 + 5464;
	// bl 0x82691650
	ctx.lr = 0x82663D10;
	sub_82691650(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82663D24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,5504
	ctx.r4.s64 = ctx.r8.s64 + 5504;
	// bl 0x82691650
	ctx.lr = 0x82663D34;
	sub_82691650(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82663D48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,5452
	ctx.r4.s64 = ctx.r5.s64 + 5452;
	// bl 0x82691650
	ctx.lr = 0x82663D58;
	sub_82691650(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82663D6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,5520
	ctx.r4.s64 = ctx.r9.s64 + 5520;
	// bl 0x82691650
	ctx.lr = 0x82663D7C;
	sub_82691650(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r4,r8,9292
	ctx.r4.s64 = ctx.r8.s64 + 9292;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82663D94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,6160
	ctx.r4.s64 = ctx.r5.s64 + 6160;
	// bl 0x82691650
	ctx.lr = 0x82663DA4;
	sub_82691650(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r4,r4,9264
	ctx.r4.s64 = ctx.r4.s64 + 9264;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82663DBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,5664
	ctx.r4.s64 = ctx.r9.s64 + 5664;
	// bl 0x82691650
	ctx.lr = 0x82663DCC;
	sub_82691650(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r4,r8,9236
	ctx.r4.s64 = ctx.r8.s64 + 9236;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82663DE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82663DEC"))) PPC_WEAK_FUNC(sub_82663DEC);
PPC_FUNC_IMPL(__imp__sub_82663DEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82663DF0"))) PPC_WEAK_FUNC(sub_82663DF0);
PPC_FUNC_IMPL(__imp__sub_82663DF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82663368
	ctx.lr = 0x82663E08;
	sub_82663368(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82663e28
	if (!cr6.eq) goto loc_82663E28;
	// bl 0x82663410
	ctx.lr = 0x82663E18;
	sub_82663410(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x82663e2c
	if (cr6.eq) goto loc_82663E2C;
loc_82663E28:
	// li r11,1
	r11.s64 = 1;
loc_82663E2C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82663e50
	if (cr6.eq) goto loc_82663E50;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82663E50:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82663E64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r3,r7,1
	ctx.r3.u64 = ctx.r7.u64 ^ 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82663E88"))) PPC_WEAK_FUNC(sub_82663E88);
PPC_FUNC_IMPL(__imp__sub_82663E88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82663E90;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82660050
	ctx.lr = 0x82663E98;
	sub_82660050(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r31,52(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82663368
	ctx.lr = 0x82663EA8;
	sub_82663368(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82663ec8
	if (!cr6.eq) goto loc_82663EC8;
	// bl 0x82663410
	ctx.lr = 0x82663EB8;
	sub_82663410(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82663ecc
	if (cr6.eq) goto loc_82663ECC;
loc_82663EC8:
	// li r29,1
	r29.s64 = 1;
loc_82663ECC:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r4,r11,6160
	ctx.r4.s64 = r11.s64 + 6160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82691650
	ctx.lr = 0x82663EE0;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r30,r10,9480
	r30.s64 = ctx.r10.s64 + 9480;
	// lwz r8,340(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 340);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82663EFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,5664
	ctx.r4.s64 = ctx.r7.s64 + 5664;
	// bl 0x82691650
	ctx.lr = 0x82663F0C;
	sub_82691650(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,340(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 340);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82663F20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r4,5452
	ctx.r4.s64 = ctx.r4.s64 + 5452;
	// bl 0x82691650
	ctx.lr = 0x82663F30;
	sub_82691650(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r30,r11,9456
	r30.s64 = r11.s64 + 9456;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82663F4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// clrlwi r9,r29,24
	ctx.r9.u64 = r29.u32 & 0xFF;
	// addi r29,r11,9436
	r29.s64 = r11.s64 + 9436;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,5756
	ctx.r4.s64 = r11.s64 + 5756;
	// bne cr6,0x82663fa8
	if (!cr6.eq) goto loc_82663FA8;
	// bl 0x82691650
	ctx.lr = 0x82663F70;
	sub_82691650(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82663F84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,5492
	ctx.r4.s64 = ctx.r8.s64 + 5492;
	// bl 0x82691650
	ctx.lr = 0x82663F94;
	sub_82691650(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// b 0x82663fe8
	goto loc_82663FE8;
loc_82663FA8:
	// bl 0x82691650
	ctx.lr = 0x82663FAC;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,5788
	ctx.r4.s64 = ctx.r10.s64 + 5788;
	// lwz r8,340(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 340);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82663FC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,5492
	ctx.r4.s64 = ctx.r7.s64 + 5492;
	// bl 0x82691650
	ctx.lr = 0x82663FD4;
	sub_82691650(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r4,r6,9412
	ctx.r4.s64 = ctx.r6.s64 + 9412;
	// lwz r11,340(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 340);
	// mtctr r11
	ctr.u64 = r11.u64;
loc_82663FE8:
	// bctrl 
	ctx.lr = 0x82663FEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,5464
	ctx.r4.s64 = r11.s64 + 5464;
	// bl 0x82691650
	ctx.lr = 0x82663FFC;
	sub_82691650(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82664010;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,5504
	ctx.r4.s64 = ctx.r8.s64 + 5504;
	// bl 0x82691650
	ctx.lr = 0x82664020;
	sub_82691650(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r6,340(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 340);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82664034;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,5628
	ctx.r4.s64 = ctx.r5.s64 + 5628;
	// bl 0x82691650
	ctx.lr = 0x82664044;
	sub_82691650(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r30,r4,9392
	r30.s64 = ctx.r4.s64 + 9392;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82664060;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,5520
	ctx.r4.s64 = ctx.r9.s64 + 5520;
	// bl 0x82691650
	ctx.lr = 0x82664070;
	sub_82691650(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82664084;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8266408C"))) PPC_WEAK_FUNC(sub_8266408C);
PPC_FUNC_IMPL(__imp__sub_8266408C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82664090"))) PPC_WEAK_FUNC(sub_82664090);
PPC_FUNC_IMPL(__imp__sub_82664090) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82660310
	ctx.lr = 0x826640AC;
	sub_82660310(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5756
	ctx.r3.s64 = r11.s64 + 5756;
	// bl 0x821fa230
	ctx.lr = 0x826640B8;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826640CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5504
	ctx.r3.s64 = ctx.r8.s64 + 5504;
	// bl 0x821fa230
	ctx.lr = 0x826640D8;
	sub_821FA230(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826640EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r3,r5,5664
	ctx.r3.s64 = ctx.r5.s64 + 5664;
	// bl 0x821fa230
	ctx.lr = 0x826640F8;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266410C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82256058
	ctx.lr = 0x82664110;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82664130
	if (cr6.eq) goto loc_82664130;
	// bl 0x82256058
	ctx.lr = 0x8266411C;
	sub_82256058(ctx, base);
	// lwz r11,3144(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3144);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// b 0x82664134
	goto loc_82664134;
loc_82664130:
	// li r11,0
	r11.s64 = 0;
loc_82664134:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82664184
	if (cr6.eq) goto loc_82664184;
	// bl 0x82663368
	ctx.lr = 0x82664144;
	sub_82663368(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82664184
	if (cr6.eq) goto loc_82664184;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5492
	ctx.r3.s64 = r11.s64 + 5492;
	// bl 0x821fa230
	ctx.lr = 0x8266415C;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82664170;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5452
	ctx.r3.s64 = ctx.r8.s64 + 5452;
	// bl 0x821fa230
	ctx.lr = 0x8266417C;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x826641b4
	goto loc_826641B4;
loc_82664184:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5492
	ctx.r3.s64 = r11.s64 + 5492;
	// bl 0x821fa230
	ctx.lr = 0x82664190;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826641A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5452
	ctx.r3.s64 = ctx.r8.s64 + 5452;
	// bl 0x821fa230
	ctx.lr = 0x826641B0;
	sub_821FA230(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
loc_826641B4:
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826641C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r31,r11,6160
	r31.s64 = r11.s64 + 6160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821fa230
	ctx.lr = 0x826641D4;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826641E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r3,r9,5700
	ctx.r3.s64 = ctx.r9.s64 + 5700;
	// bl 0x821fa230
	ctx.lr = 0x826641F4;
	sub_821FA230(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82664254
	if (cr6.eq) goto loc_82664254;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,5684
	ctx.r4.s64 = r11.s64 + 5684;
	// bl 0x8268da78
	ctx.lr = 0x8266420C;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82664240
	if (cr6.eq) goto loc_82664240;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82664240
	if (!cr6.eq) goto loc_82664240;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82664240
	if (!cr6.eq) goto loc_82664240;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821fa230
	ctx.lr = 0x82664234;
	sub_821FA230(ctx, base);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
	// b 0x82664250
	goto loc_82664250;
loc_82664240:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821fa230
	ctx.lr = 0x82664248;
	sub_821FA230(ctx, base);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r11,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
loc_82664250:
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
loc_82664254:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266426C"))) PPC_WEAK_FUNC(sub_8266426C);
PPC_FUNC_IMPL(__imp__sub_8266426C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82664270"))) PPC_WEAK_FUNC(sub_82664270);
PPC_FUNC_IMPL(__imp__sub_82664270) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82664090
	ctx.lr = 0x82664288;
	sub_82664090(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,5616
	ctx.r3.s64 = r11.s64 + 5616;
	// bl 0x821fa230
	ctx.lr = 0x82664294;
	sub_821FA230(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826642fc
	if (cr6.eq) goto loc_826642FC;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,5596
	ctx.r4.s64 = r11.s64 + 5596;
	// bl 0x8268da78
	ctx.lr = 0x826642AC;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826642e4
	if (cr6.eq) goto loc_826642E4;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826642e4
	if (!cr6.eq) goto loc_826642E4;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826642e4
	if (!cr6.eq) goto loc_826642E4;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,6160
	ctx.r3.s64 = r11.s64 + 6160;
	// bl 0x821fa230
	ctx.lr = 0x826642D8;
	sub_821FA230(ctx, base);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// b 0x826642f8
	goto loc_826642F8;
loc_826642E4:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,6160
	ctx.r3.s64 = r11.s64 + 6160;
	// bl 0x821fa230
	ctx.lr = 0x826642F0;
	sub_821FA230(ctx, base);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r9,r10,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
loc_826642F8:
	// stw r9,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r9.u32);
loc_826642FC:
	// bl 0x82663368
	ctx.lr = 0x82664300;
	sub_82663368(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82664350
	if (!cr6.eq) goto loc_82664350;
	// bl 0x82663410
	ctx.lr = 0x82664310;
	sub_82663410(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82664350
	if (!cr6.eq) goto loc_82664350;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5756
	ctx.r3.s64 = r11.s64 + 5756;
	// bl 0x821fa230
	ctx.lr = 0x82664328;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266433C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5504
	ctx.r3.s64 = ctx.r8.s64 + 5504;
	// bl 0x821fa230
	ctx.lr = 0x82664348;
	sub_821FA230(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x82664380
	goto loc_82664380;
loc_82664350:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5756
	ctx.r3.s64 = r11.s64 + 5756;
	// bl 0x821fa230
	ctx.lr = 0x8266435C;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82664370;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5504
	ctx.r3.s64 = ctx.r8.s64 + 5504;
	// bl 0x821fa230
	ctx.lr = 0x8266437C;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
loc_82664380:
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82664390;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826643A4"))) PPC_WEAK_FUNC(sub_826643A4);
PPC_FUNC_IMPL(__imp__sub_826643A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826643A8"))) PPC_WEAK_FUNC(sub_826643A8);
PPC_FUNC_IMPL(__imp__sub_826643A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82660310
	ctx.lr = 0x826643B8;
	sub_82660310(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5452
	ctx.r3.s64 = r11.s64 + 5452;
	// bl 0x821fa230
	ctx.lr = 0x826643C4;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826643D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5464
	ctx.r3.s64 = ctx.r8.s64 + 5464;
	// bl 0x821fa230
	ctx.lr = 0x826643E4;
	sub_821FA230(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826643F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82663368
	ctx.lr = 0x826643FC;
	sub_82663368(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// addi r3,r11,5492
	ctx.r3.s64 = r11.s64 + 5492;
	// beq cr6,0x8266441c
	if (cr6.eq) goto loc_8266441C;
	// bl 0x821fa230
	ctx.lr = 0x82664414;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82664424
	goto loc_82664424;
loc_8266441C:
	// bl 0x821fa230
	ctx.lr = 0x82664420;
	sub_821FA230(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
loc_82664424:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82664434;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5756
	ctx.r3.s64 = r11.s64 + 5756;
	// bl 0x821fa230
	ctx.lr = 0x82664440;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82664454;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82664464"))) PPC_WEAK_FUNC(sub_82664464);
PPC_FUNC_IMPL(__imp__sub_82664464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82664468"))) PPC_WEAK_FUNC(sub_82664468);
PPC_FUNC_IMPL(__imp__sub_82664468) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82660050
	ctx.lr = 0x82664480;
	sub_82660050(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,5452
	ctx.r4.s64 = ctx.r10.s64 + 5452;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82691650
	ctx.lr = 0x826644A0;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r30,r11,9576
	r30.s64 = r11.s64 + 9576;
	// lwz r8,340(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 340);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826644BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82663410
	ctx.lr = 0x826644C0;
	sub_82663410(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,5492
	ctx.r4.s64 = r11.s64 + 5492;
	// beq cr6,0x826644f4
	if (cr6.eq) goto loc_826644F4;
	// bl 0x82691650
	ctx.lr = 0x826644DC;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,9556
	ctx.r4.s64 = ctx.r10.s64 + 9556;
	// lwz r8,340(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 340);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// b 0x82664508
	goto loc_82664508;
loc_826644F4:
	// bl 0x82691650
	ctx.lr = 0x826644F8;
	sub_82691650(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,340(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 340);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82664508:
	// bctrl 
	ctx.lr = 0x8266450C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,5464
	ctx.r4.s64 = r11.s64 + 5464;
	// bl 0x82691650
	ctx.lr = 0x8266451C;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,9532
	ctx.r4.s64 = ctx.r10.s64 + 9532;
	// lwz r8,340(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 340);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82664534;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,5664
	ctx.r4.s64 = ctx.r7.s64 + 5664;
	// bl 0x82691650
	ctx.lr = 0x82664544;
	sub_82691650(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r4,r6,9504
	ctx.r4.s64 = ctx.r6.s64 + 9504;
	// lwz r11,340(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 340);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266455C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82664574"))) PPC_WEAK_FUNC(sub_82664574);
PPC_FUNC_IMPL(__imp__sub_82664574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82664578"))) PPC_WEAK_FUNC(sub_82664578);
PPC_FUNC_IMPL(__imp__sub_82664578) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82663410
	ctx.lr = 0x82664588;
	sub_82663410(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826645ac
	if (cr6.eq) goto loc_826645AC;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,9628
	ctx.r3.s64 = r11.s64 + 9628;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826645AC:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,9600
	ctx.r3.s64 = r11.s64 + 9600;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826645C4"))) PPC_WEAK_FUNC(sub_826645C4);
PPC_FUNC_IMPL(__imp__sub_826645C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826645C8"))) PPC_WEAK_FUNC(sub_826645C8);
PPC_FUNC_IMPL(__imp__sub_826645C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82663410
	ctx.lr = 0x826645D8;
	sub_82663410(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826645fc
	if (cr6.eq) goto loc_826645FC;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,9688
	ctx.r3.s64 = r11.s64 + 9688;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826645FC:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,9660
	ctx.r3.s64 = r11.s64 + 9660;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82664614"))) PPC_WEAK_FUNC(sub_82664614);
PPC_FUNC_IMPL(__imp__sub_82664614) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82664618"))) PPC_WEAK_FUNC(sub_82664618);
PPC_FUNC_IMPL(__imp__sub_82664618) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82660310
	ctx.lr = 0x82664630;
	sub_82660310(ctx, base);
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826646f0
	if (cr6.eq) goto loc_826646F0;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5756
	ctx.r3.s64 = r11.s64 + 5756;
	// bl 0x821fa230
	ctx.lr = 0x82664648;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266465C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r3,-10028(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x82664668;
	sub_82207138(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82664698
	if (!cr6.eq) goto loc_82664698;
	// bl 0x82663410
	ctx.lr = 0x82664678;
	sub_82663410(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82664698
	if (!cr6.eq) goto loc_82664698;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5492
	ctx.r3.s64 = r11.s64 + 5492;
	// bl 0x821fa230
	ctx.lr = 0x82664690;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x826646a8
	goto loc_826646A8;
loc_82664698:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5492
	ctx.r3.s64 = r11.s64 + 5492;
	// bl 0x821fa230
	ctx.lr = 0x826646A4;
	sub_821FA230(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
loc_826646A8:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826646B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5424
	ctx.r3.s64 = r11.s64 + 5424;
	// bl 0x821fa230
	ctx.lr = 0x826646C4;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,80(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826646D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5408
	ctx.r3.s64 = ctx.r8.s64 + 5408;
	// bl 0x821fa230
	ctx.lr = 0x826646E0;
	sub_821FA230(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,80(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826646F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826646F0:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5452
	ctx.r3.s64 = r11.s64 + 5452;
	// bl 0x821fa230
	ctx.lr = 0x826646FC;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82664710;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5464
	ctx.r3.s64 = ctx.r8.s64 + 5464;
	// bl 0x821fa230
	ctx.lr = 0x8266471C;
	sub_821FA230(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82664730;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r3,r5,5504
	ctx.r3.s64 = ctx.r5.s64 + 5504;
	// bl 0x821fa230
	ctx.lr = 0x8266473C;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82664750;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5652
	ctx.r3.s64 = ctx.r9.s64 + 5652;
	// bl 0x821fa230
	ctx.lr = 0x8266475C;
	sub_821FA230(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82664770;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r3,r6,5436
	ctx.r3.s64 = ctx.r6.s64 + 5436;
	// bl 0x821fa230
	ctx.lr = 0x8266477C;
	sub_821FA230(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82664790;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826647A4"))) PPC_WEAK_FUNC(sub_826647A4);
PPC_FUNC_IMPL(__imp__sub_826647A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826647A8"))) PPC_WEAK_FUNC(sub_826647A8);
PPC_FUNC_IMPL(__imp__sub_826647A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826647C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82664844
	if (cr6.eq) goto loc_82664844;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5368
	ctx.r3.s64 = r11.s64 + 5368;
	// bl 0x821fa230
	ctx.lr = 0x826647E0;
	sub_821FA230(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82663368
	ctx.lr = 0x826647E8;
	sub_82663368(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826647fc
	if (!cr6.eq) goto loc_826647FC;
	// bl 0x82663410
	ctx.lr = 0x826647F8;
	sub_82663410(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
loc_826647FC:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5640
	ctx.r3.s64 = r11.s64 + 5640;
	// bl 0x821fa230
	ctx.lr = 0x82664808;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82664814;
	sub_8268CC80(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r3,r10,5492
	ctx.r3.s64 = ctx.r10.s64 + 5492;
	// bl 0x821fa230
	ctx.lr = 0x82664820;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x8266482C;
	sub_8268CC80(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5664
	ctx.r3.s64 = ctx.r9.s64 + 5664;
	// bl 0x821fa230
	ctx.lr = 0x82664838;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82664844;
	sub_8268CC80(ctx, base);
loc_82664844:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82664858"))) PPC_WEAK_FUNC(sub_82664858);
PPC_FUNC_IMPL(__imp__sub_82664858) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r31,r11,-21500
	r31.s64 = r11.s64 + -21500;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,9720
	ctx.r4.s64 = ctx.r9.s64 + 9720;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwz r30,-24180(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x823db670
	ctx.lr = 0x82664894;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821fd7c0
	ctx.lr = 0x826648A8;
	sub_821FD7C0(ctx, base);
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// li r11,0
	r11.s64 = 0;
	// lwz r8,10248(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// lwz r3,308(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// stw r31,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r31.u32);
	// stb r11,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r11.u8);
	// stw r11,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r11.u32);
	// stw r8,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r8.u32);
	// bl 0x822031a8
	ctx.lr = 0x826648CC;
	sub_822031A8(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,18508(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 18508);
	// bl 0x826b94e8
	ctx.lr = 0x826648DC;
	sub_826B94E8(ctx, base);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826648F4"))) PPC_WEAK_FUNC(sub_826648F4);
PPC_FUNC_IMPL(__imp__sub_826648F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826648F8"))) PPC_WEAK_FUNC(sub_826648F8);
PPC_FUNC_IMPL(__imp__sub_826648F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x82664918;
	sub_82207138(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8266495c
	if (!cr6.eq) goto loc_8266495C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82664938;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8266495c
	if (!cr6.eq) goto loc_8266495C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8266495C:
	// bl 0x826632c0
	ctx.lr = 0x82664960;
	sub_826632C0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82664974"))) PPC_WEAK_FUNC(sub_82664974);
PPC_FUNC_IMPL(__imp__sub_82664974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82664978"))) PPC_WEAK_FUNC(sub_82664978);
PPC_FUNC_IMPL(__imp__sub_82664978) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82664980;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82660310
	ctx.lr = 0x8266498C;
	sub_82660310(ctx, base);
	// clrlwi r9,r31,24
	ctx.r9.u64 = r31.u32 & 0xFF;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r31,r11,5492
	r31.s64 = r11.s64 + 5492;
	// addi r30,r10,5452
	r30.s64 = ctx.r10.s64 + 5452;
	// beq cr6,0x82664a04
	if (cr6.eq) goto loc_82664A04;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5756
	ctx.r3.s64 = r11.s64 + 5756;
	// bl 0x821fa230
	ctx.lr = 0x826649B4;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826649C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821fa230
	ctx.lr = 0x826649D0;
	sub_821FA230(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826649E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r3,r6,5712
	ctx.r3.s64 = ctx.r6.s64 + 5712;
	// bl 0x821fa230
	ctx.lr = 0x826649F0;
	sub_821FA230(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// b 0x82664a3c
	goto loc_82664A3C;
loc_82664A04:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821fa230
	ctx.lr = 0x82664A0C;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82664A20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5608
	ctx.r3.s64 = ctx.r9.s64 + 5608;
	// bl 0x821fa230
	ctx.lr = 0x82664A2C;
	sub_821FA230(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
loc_82664A3C:
	// bctrl 
	ctx.lr = 0x82664A40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r29,r11,-21500
	r29.s64 = r11.s64 + -21500;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,9720
	ctx.r4.s64 = ctx.r9.s64 + 9720;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwz r28,-24180(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// bl 0x823db670
	ctx.lr = 0x82664A68;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 10248);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821fd7c0
	ctx.lr = 0x82664A7C;
	sub_821FD7C0(ctx, base);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// li r11,0
	r11.s64 = 0;
	// lwz r8,10248(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 10248);
	// lwz r3,308(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// stw r29,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r29.u32);
	// stb r11,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r11.u8);
	// stw r11,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r11.u32);
	// stw r8,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r8.u32);
	// bl 0x822031a8
	ctx.lr = 0x82664AA0;
	sub_822031A8(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,18508(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 18508);
	// bl 0x826b94e8
	ctx.lr = 0x82664AB0;
	sub_826B94E8(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82664af0
	if (cr6.eq) goto loc_82664AF0;
	// bl 0x821fa230
	ctx.lr = 0x82664AC4;
	sub_821FA230(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rlwinm r9,r10,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// bl 0x821fa230
	ctx.lr = 0x82664ADC;
	sub_821FA230(ctx, base);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r7,r8,0,28,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r7,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9248
	return;
loc_82664AF0:
	// bl 0x821fa230
	ctx.lr = 0x82664AF4;
	sub_821FA230(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// bl 0x821fa230
	ctx.lr = 0x82664B0C;
	sub_821FA230(ctx, base);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r7,r8,16
	ctx.r7.u64 = ctx.r8.u64 | 16;
	// stw r7,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82664B20"))) PPC_WEAK_FUNC(sub_82664B20);
PPC_FUNC_IMPL(__imp__sub_82664B20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5368
	ctx.r3.s64 = r11.s64 + 5368;
	// bl 0x821fa230
	ctx.lr = 0x82664B40;
	sub_821FA230(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82663410
	ctx.lr = 0x82664B48;
	sub_82663410(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82664bd0
	if (!cr6.eq) goto loc_82664BD0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x82664B60;
	sub_82207138(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82664bd0
	if (!cr6.eq) goto loc_82664BD0;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,5756
	ctx.r4.s64 = r11.s64 + 5756;
	// bl 0x8265fbb0
	ctx.lr = 0x82664B7C;
	sub_8265FBB0(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,5712
	ctx.r4.s64 = ctx.r10.s64 + 5712;
	// bl 0x8265fbb0
	ctx.lr = 0x82664B8C;
	sub_8265FBB0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,5424
	ctx.r4.s64 = ctx.r9.s64 + 5424;
	// bl 0x8265fbb0
	ctx.lr = 0x82664B9C;
	sub_8265FBB0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,5408
	ctx.r4.s64 = ctx.r8.s64 + 5408;
	// bl 0x8265fbb0
	ctx.lr = 0x82664BAC;
	sub_8265FBB0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,5652
	ctx.r4.s64 = ctx.r7.s64 + 5652;
	// bl 0x8265fbb0
	ctx.lr = 0x82664BBC;
	sub_8265FBB0(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,5640
	ctx.r4.s64 = ctx.r6.s64 + 5640;
	// bl 0x8265fbb0
	ctx.lr = 0x82664BCC;
	sub_8265FBB0(ctx, base);
	// b 0x82664ca0
	goto loc_82664CA0;
loc_82664BD0:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5640
	ctx.r3.s64 = r11.s64 + 5640;
	// bl 0x821fa230
	ctx.lr = 0x82664BDC;
	sub_821FA230(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82664BEC;
	sub_8268CC80(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82664C04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5424
	ctx.r3.s64 = ctx.r8.s64 + 5424;
	// bl 0x821fa230
	ctx.lr = 0x82664C10;
	sub_821FA230(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82664C20;
	sub_8268CC80(ctx, base);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82664C38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r3,r5,5408
	ctx.r3.s64 = ctx.r5.s64 + 5408;
	// bl 0x821fa230
	ctx.lr = 0x82664C44;
	sub_821FA230(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82664C54;
	sub_8268CC80(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82664C6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5652
	ctx.r3.s64 = ctx.r9.s64 + 5652;
	// bl 0x821fa230
	ctx.lr = 0x82664C78;
	sub_821FA230(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8268cc80
	ctx.lr = 0x82664C88;
	sub_8268CC80(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82664CA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82664CA0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82664CB8"))) PPC_WEAK_FUNC(sub_82664CB8);
PPC_FUNC_IMPL(__imp__sub_82664CB8) {
	PPC_FUNC_PROLOGUE();
	// b 0x82663368
	sub_82663368(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82664CBC"))) PPC_WEAK_FUNC(sub_82664CBC);
PPC_FUNC_IMPL(__imp__sub_82664CBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82664CC0"))) PPC_WEAK_FUNC(sub_82664CC0);
PPC_FUNC_IMPL(__imp__sub_82664CC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82204018
	ctx.lr = 0x82664CE0;
	sub_82204018(ctx, base);
	// cmpwi cr6,r3,15
	cr6.compare<int32_t>(ctx.r3.s32, 15, xer);
	// beq cr6,0x82664da8
	if (cr6.eq) goto loc_82664DA8;
	// bl 0x82256058
	ctx.lr = 0x82664CEC;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82664d08
	if (cr6.eq) goto loc_82664D08;
	// bl 0x82256058
	ctx.lr = 0x82664CF8;
	sub_82256058(ctx, base);
	// lwz r11,3140(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3140);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82664d0c
	if (!cr6.eq) goto loc_82664D0C;
loc_82664D08:
	// li r11,0
	r11.s64 = 0;
loc_82664D0C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82664d54
	if (cr6.eq) goto loc_82664D54;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,3
	ctx.r3.s64 = r11.s64 + 196608;
	// addi r3,r3,-16384
	ctx.r3.s64 = ctx.r3.s64 + -16384;
	// bl 0x82654e08
	ctx.lr = 0x82664D2C;
	sub_82654E08(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x82664d3c
	if (cr6.gt) goto loc_82664D3C;
	// li r11,0
	r11.s64 = 0;
loc_82664D3C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82664D54:
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82204018
	ctx.lr = 0x82664D60;
	sub_82204018(ctx, base);
	// cmpwi cr6,r3,12
	cr6.compare<int32_t>(ctx.r3.s32, 12, xer);
	// beq cr6,0x82664da8
	if (cr6.eq) goto loc_82664DA8;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,9736
	ctx.r4.s64 = ctx.r10.s64 + 9736;
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x8220eea8
	ctx.lr = 0x82664D7C;
	sub_8220EEA8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82664da8
	if (cr6.eq) goto loc_82664DA8;
	// lwz r11,88(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82664DA8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82664DC0"))) PPC_WEAK_FUNC(sub_82664DC0);
PPC_FUNC_IMPL(__imp__sub_82664DC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82664DC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82387a18
	ctx.lr = 0x82664DD8;
	sub_82387A18(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82660310
	ctx.lr = 0x82664DE8;
	sub_82660310(ctx, base);
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82664ff8
	if (cr6.eq) goto loc_82664FF8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82204018
	ctx.lr = 0x82664E04;
	sub_82204018(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,8
	cr6.compare<int32_t>(r28.s32, 8, xer);
	// bne cr6,0x82664e54
	if (!cr6.eq) goto loc_82664E54;
	// bl 0x82663410
	ctx.lr = 0x82664E14;
	sub_82663410(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82664e30
	if (cr6.eq) goto loc_82664E30;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82664e34
	if (cr6.eq) goto loc_82664E34;
loc_82664E30:
	// li r31,0
	r31.s64 = 0;
loc_82664E34:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5492
	ctx.r3.s64 = r11.s64 + 5492;
	// bl 0x821fa230
	ctx.lr = 0x82664E40;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// b 0x82664e78
	goto loc_82664E78;
loc_82664E54:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5492
	ctx.r3.s64 = r11.s64 + 5492;
	// bl 0x821fa230
	ctx.lr = 0x82664E60;
	sub_821FA230(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// rlwinm r4,r9,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
loc_82664E78:
	// bctrl 
	ctx.lr = 0x82664E7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5756
	ctx.r3.s64 = r11.s64 + 5756;
	// bl 0x821fa230
	ctx.lr = 0x82664E88;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82664E9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5652
	ctx.r3.s64 = ctx.r8.s64 + 5652;
	// bl 0x821fa230
	ctx.lr = 0x82664EA8;
	sub_821FA230(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r7,r29,24
	ctx.r7.u64 = r29.u32 & 0xFF;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// rlwinm r4,r6,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82664EC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82664ED8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82664f14
	if (cr6.eq) goto loc_82664F14;
	// bl 0x82387a18
	ctx.lr = 0x82664EE8;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82664f14
	if (!cr6.eq) goto loc_82664F14;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// li r11,1
	r11.s64 = 1;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lbz r8,797(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 797);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82664f18
	if (cr6.eq) goto loc_82664F18;
loc_82664F14:
	// li r11,0
	r11.s64 = 0;
loc_82664F18:
	// clrlwi r29,r11,24
	r29.u64 = r11.u32 & 0xFF;
	// bl 0x8265e5e8
	ctx.lr = 0x82664F20;
	sub_8265E5E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82664f30
	if (cr6.eq) goto loc_82664F30;
	// li r29,0
	r29.s64 = 0;
loc_82664F30:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r31,r11,5520
	r31.s64 = r11.s64 + 5520;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821fa230
	ctx.lr = 0x82664F40;
	sub_821FA230(ctx, base);
	// addi r11,r28,-8
	r11.s64 = r28.s64 + -8;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r8,r10,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r28,r8,1
	r28.u64 = ctx.r8.u64 ^ 1;
	// lwz r7,76(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82664F64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r30,r11,5628
	r30.s64 = r11.s64 + 5628;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821fa230
	ctx.lr = 0x82664F74;
	sub_821FA230(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r5,76(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82664F88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r4,r29,24
	ctx.r4.u64 = r29.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82664fc8
	if (cr6.eq) goto loc_82664FC8;
	// bl 0x821fa230
	ctx.lr = 0x82664F9C;
	sub_821FA230(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rlwinm r9,r10,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// bl 0x821fa230
	ctx.lr = 0x82664FB4;
	sub_821FA230(ctx, base);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r7,r8,0,28,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r7,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82664FC8:
	// bl 0x821fa230
	ctx.lr = 0x82664FCC;
	sub_821FA230(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// bl 0x821fa230
	ctx.lr = 0x82664FE4;
	sub_821FA230(ctx, base);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r7,r8,16
	ctx.r7.u64 = ctx.r8.u64 | 16;
	// stw r7,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82664FF8:
	// bl 0x82387a18
	ctx.lr = 0x82664FFC;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82665038
	if (cr6.eq) goto loc_82665038;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82665010;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82665024;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x8266502C;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// li r31,0
	r31.s64 = 0;
	// bne cr6,0x8266503c
	if (!cr6.eq) goto loc_8266503C;
loc_82665038:
	// li r31,1
	r31.s64 = 1;
loc_8266503C:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5452
	ctx.r3.s64 = r11.s64 + 5452;
	// bl 0x821fa230
	ctx.lr = 0x82665048;
	sub_821FA230(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// rlwinm r4,r9,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82665064;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r3,r6,5464
	ctx.r3.s64 = ctx.r6.s64 + 5464;
	// bl 0x821fa230
	ctx.lr = 0x82665070;
	sub_821FA230(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r4,r31,24
	ctx.r4.u64 = r31.u32 & 0xFF;
	// lwz r11,76(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82665084;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266508C"))) PPC_WEAK_FUNC(sub_8266508C);
PPC_FUNC_IMPL(__imp__sub_8266508C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82665090"))) PPC_WEAK_FUNC(sub_82665090);
PPC_FUNC_IMPL(__imp__sub_82665090) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82204018
	ctx.lr = 0x826650B4;
	sub_82204018(ctx, base);
	// cmpwi cr6,r3,12
	cr6.compare<int32_t>(ctx.r3.s32, 12, xer);
	// beq cr6,0x8266510c
	if (cr6.eq) goto loc_8266510C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x826650C8;
	sub_82207138(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826650f4
	if (!cr6.eq) goto loc_826650F4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826650E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266510c
	if (cr6.eq) goto loc_8266510C;
loc_826650F4:
	// bl 0x826632c0
	ctx.lr = 0x826650F8;
	sub_826632C0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8266510C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82665124"))) PPC_WEAK_FUNC(sub_82665124);
PPC_FUNC_IMPL(__imp__sub_82665124) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82665128"))) PPC_WEAK_FUNC(sub_82665128);
PPC_FUNC_IMPL(__imp__sub_82665128) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82660310
	ctx.lr = 0x82665140;
	sub_82660310(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5452
	ctx.r3.s64 = r11.s64 + 5452;
	// bl 0x821fa230
	ctx.lr = 0x8266514C;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82665160;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5652
	ctx.r3.s64 = ctx.r8.s64 + 5652;
	// bl 0x821fa230
	ctx.lr = 0x8266516C;
	sub_821FA230(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82665180;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r3,r5,5436
	ctx.r3.s64 = ctx.r5.s64 + 5436;
	// bl 0x821fa230
	ctx.lr = 0x8266518C;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826651A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r9,5664
	ctx.r3.s64 = ctx.r9.s64 + 5664;
	// bl 0x821fa230
	ctx.lr = 0x826651AC;
	sub_821FA230(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826651C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r31,24
	ctx.r6.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82665278
	if (cr6.eq) goto loc_82665278;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x826651D8;
	sub_82207138(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82665230
	if (cr6.eq) goto loc_82665230;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5504
	ctx.r3.s64 = r11.s64 + 5504;
	// bl 0x821fa230
	ctx.lr = 0x826651F0;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82665204;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r8,5756
	ctx.r3.s64 = ctx.r8.s64 + 5756;
	// bl 0x821fa230
	ctx.lr = 0x82665210;
	sub_821FA230(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82665224;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5732
	ctx.r3.s64 = r11.s64 + 5732;
	// b 0x82665280
	goto loc_82665280;
loc_82665230:
	// bl 0x826632c0
	ctx.lr = 0x82665234;
	sub_826632C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5756
	ctx.r3.s64 = r11.s64 + 5756;
	// beq cr6,0x82665254
	if (cr6.eq) goto loc_82665254;
	// bl 0x821fa230
	ctx.lr = 0x8266524C;
	sub_821FA230(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x8266525c
	goto loc_8266525C;
loc_82665254:
	// bl 0x821fa230
	ctx.lr = 0x82665258;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
loc_8266525C:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266526C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5732
	ctx.r3.s64 = r11.s64 + 5732;
	// b 0x82665280
	goto loc_82665280;
loc_82665278:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5464
	ctx.r3.s64 = r11.s64 + 5464;
loc_82665280:
	// bl 0x821fa230
	ctx.lr = 0x82665284;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,76(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82665298;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826652AC"))) PPC_WEAK_FUNC(sub_826652AC);
PPC_FUNC_IMPL(__imp__sub_826652AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826652B0"))) PPC_WEAK_FUNC(sub_826652B0);
PPC_FUNC_IMPL(__imp__sub_826652B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826652B8;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r30,r11,-21500
	r30.s64 = r11.s64 + -21500;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r9,9748
	ctx.r4.s64 = ctx.r9.s64 + 9748;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lwz r29,-24180(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24180);
	// li r31,0
	r31.s64 = 0;
	// bl 0x823db670
	ctx.lr = 0x826652E8;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,10248(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821fd7c0
	ctx.lr = 0x826652FC;
	sub_821FD7C0(ctx, base);
	// lwz r11,308(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// lwz r8,10248(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 10248);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r31,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, r31.u8);
	// stw r31,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r31.u32);
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// stw r8,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r8.u32);
	// beq cr6,0x82665338
	if (cr6.eq) goto loc_82665338;
	// lwz r11,88(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
loc_82665338:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82665344"))) PPC_WEAK_FUNC(sub_82665344);
PPC_FUNC_IMPL(__imp__sub_82665344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82665348"))) PPC_WEAK_FUNC(sub_82665348);
PPC_FUNC_IMPL(__imp__sub_82665348) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82665364;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266539c
	if (cr6.eq) goto loc_8266539C;
	// bl 0x82663368
	ctx.lr = 0x82665374;
	sub_82663368(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82665388
	if (!cr6.eq) goto loc_82665388;
	// bl 0x82663410
	ctx.lr = 0x82665384;
	sub_82663410(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
loc_82665388:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8266539C:
	// bl 0x82660230
	ctx.lr = 0x826653A0;
	sub_82660230(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826653C0"))) PPC_WEAK_FUNC(sub_826653C0);
PPC_FUNC_IMPL(__imp__sub_826653C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82256058
	ctx.lr = 0x826653D8;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82665418
	if (cr6.eq) goto loc_82665418;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826653F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82665418
	if (!cr6.eq) goto loc_82665418;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82665418:
	// bl 0x826632c0
	ctx.lr = 0x8266541C;
	sub_826632C0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82665430"))) PPC_WEAK_FUNC(sub_82665430);
PPC_FUNC_IMPL(__imp__sub_82665430) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x826628b0
	ctx.lr = 0x82665450;
	sub_826628B0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82665468
	if (cr6.eq) goto loc_82665468;
	// bl 0x82130588
	ctx.lr = 0x82665464;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82665468:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82665480"))) PPC_WEAK_FUNC(sub_82665480);
PPC_FUNC_IMPL(__imp__sub_82665480) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,10000
	ctx.r3.s64 = r11.s64 + 10000;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266548C"))) PPC_WEAK_FUNC(sub_8266548C);
PPC_FUNC_IMPL(__imp__sub_8266548C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82665490"))) PPC_WEAK_FUNC(sub_82665490);
PPC_FUNC_IMPL(__imp__sub_82665490) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,9132
	ctx.r3.s64 = r11.s64 + 9132;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266549C"))) PPC_WEAK_FUNC(sub_8266549C);
PPC_FUNC_IMPL(__imp__sub_8266549C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826654A0"))) PPC_WEAK_FUNC(sub_826654A0);
PPC_FUNC_IMPL(__imp__sub_826654A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,9156
	ctx.r3.s64 = r11.s64 + 9156;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826654AC"))) PPC_WEAK_FUNC(sub_826654AC);
PPC_FUNC_IMPL(__imp__sub_826654AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826654B0"))) PPC_WEAK_FUNC(sub_826654B0);
PPC_FUNC_IMPL(__imp__sub_826654B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,10152
	ctx.r3.s64 = r11.s64 + 10152;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826654BC"))) PPC_WEAK_FUNC(sub_826654BC);
PPC_FUNC_IMPL(__imp__sub_826654BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826654C0"))) PPC_WEAK_FUNC(sub_826654C0);
PPC_FUNC_IMPL(__imp__sub_826654C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,10180
	ctx.r3.s64 = r11.s64 + 10180;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826654CC"))) PPC_WEAK_FUNC(sub_826654CC);
PPC_FUNC_IMPL(__imp__sub_826654CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826654D0"))) PPC_WEAK_FUNC(sub_826654D0);
PPC_FUNC_IMPL(__imp__sub_826654D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,10204
	ctx.r3.s64 = r11.s64 + 10204;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826654DC"))) PPC_WEAK_FUNC(sub_826654DC);
PPC_FUNC_IMPL(__imp__sub_826654DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826654E0"))) PPC_WEAK_FUNC(sub_826654E0);
PPC_FUNC_IMPL(__imp__sub_826654E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,10240
	ctx.r3.s64 = r11.s64 + 10240;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826654EC"))) PPC_WEAK_FUNC(sub_826654EC);
PPC_FUNC_IMPL(__imp__sub_826654EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826654F0"))) PPC_WEAK_FUNC(sub_826654F0);
PPC_FUNC_IMPL(__imp__sub_826654F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,10392
	ctx.r3.s64 = r11.s64 + 10392;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826654FC"))) PPC_WEAK_FUNC(sub_826654FC);
PPC_FUNC_IMPL(__imp__sub_826654FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82665500"))) PPC_WEAK_FUNC(sub_82665500);
PPC_FUNC_IMPL(__imp__sub_82665500) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,10416
	ctx.r3.s64 = r11.s64 + 10416;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266550C"))) PPC_WEAK_FUNC(sub_8266550C);
PPC_FUNC_IMPL(__imp__sub_8266550C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82665510"))) PPC_WEAK_FUNC(sub_82665510);
PPC_FUNC_IMPL(__imp__sub_82665510) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,10568
	ctx.r3.s64 = r11.s64 + 10568;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266551C"))) PPC_WEAK_FUNC(sub_8266551C);
PPC_FUNC_IMPL(__imp__sub_8266551C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82665520"))) PPC_WEAK_FUNC(sub_82665520);
PPC_FUNC_IMPL(__imp__sub_82665520) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,10604
	ctx.r3.s64 = r11.s64 + 10604;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266552C"))) PPC_WEAK_FUNC(sub_8266552C);
PPC_FUNC_IMPL(__imp__sub_8266552C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82665530"))) PPC_WEAK_FUNC(sub_82665530);
PPC_FUNC_IMPL(__imp__sub_82665530) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,10636
	ctx.r3.s64 = r11.s64 + 10636;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266553C"))) PPC_WEAK_FUNC(sub_8266553C);
PPC_FUNC_IMPL(__imp__sub_8266553C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82665540"))) PPC_WEAK_FUNC(sub_82665540);
PPC_FUNC_IMPL(__imp__sub_82665540) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,10668
	ctx.r3.s64 = r11.s64 + 10668;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266554C"))) PPC_WEAK_FUNC(sub_8266554C);
PPC_FUNC_IMPL(__imp__sub_8266554C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82665550"))) PPC_WEAK_FUNC(sub_82665550);
PPC_FUNC_IMPL(__imp__sub_82665550) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,10816
	ctx.r3.s64 = r11.s64 + 10816;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266555C"))) PPC_WEAK_FUNC(sub_8266555C);
PPC_FUNC_IMPL(__imp__sub_8266555C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82665560"))) PPC_WEAK_FUNC(sub_82665560);
PPC_FUNC_IMPL(__imp__sub_82665560) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,10848
	ctx.r3.s64 = r11.s64 + 10848;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266556C"))) PPC_WEAK_FUNC(sub_8266556C);
PPC_FUNC_IMPL(__imp__sub_8266556C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82665570"))) PPC_WEAK_FUNC(sub_82665570);
PPC_FUNC_IMPL(__imp__sub_82665570) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,10884
	ctx.r3.s64 = r11.s64 + 10884;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266557C"))) PPC_WEAK_FUNC(sub_8266557C);
PPC_FUNC_IMPL(__imp__sub_8266557C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82665580"))) PPC_WEAK_FUNC(sub_82665580);
PPC_FUNC_IMPL(__imp__sub_82665580) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,5104
	ctx.r3.s64 = r11.s64 + 5104;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266558C"))) PPC_WEAK_FUNC(sub_8266558C);
PPC_FUNC_IMPL(__imp__sub_8266558C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82665590"))) PPC_WEAK_FUNC(sub_82665590);
PPC_FUNC_IMPL(__imp__sub_82665590) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,10912
	ctx.r3.s64 = r11.s64 + 10912;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266559C"))) PPC_WEAK_FUNC(sub_8266559C);
PPC_FUNC_IMPL(__imp__sub_8266559C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826655A0"))) PPC_WEAK_FUNC(sub_826655A0);
PPC_FUNC_IMPL(__imp__sub_826655A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,10944
	ctx.r3.s64 = r11.s64 + 10944;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826655AC"))) PPC_WEAK_FUNC(sub_826655AC);
PPC_FUNC_IMPL(__imp__sub_826655AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

