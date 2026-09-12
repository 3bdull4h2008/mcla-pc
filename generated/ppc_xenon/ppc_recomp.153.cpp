#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82733160"))) PPC_WEAK_FUNC(sub_82733160);
PPC_FUNC_IMPL(__imp__sub_82733160) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82733168;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r9,r10,-16232
	ctx.r9.s64 = ctx.r10.s64 + -16232;
	// lhz r11,16(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 16);
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827331e8
	if (!cr6.gt) goto loc_827331E8;
	// li r31,0
	r31.s64 = 0;
	// mr r29,r11
	r29.u64 = r11.u64;
loc_82733190:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r10,80(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827331b8
	if (cr6.eq) goto loc_827331B8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,160(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 160);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827331B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827331B8:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827331dc
	if (cr6.eq) goto loc_827331DC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827331DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827331DC:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82733190
	if (!cr0.eq) goto loc_82733190;
loc_827331E8:
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82733208
	if (cr6.eq) goto loc_82733208;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82733208;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82733208:
	// lhz r11,18(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273321c
	if (cr6.eq) goto loc_8273321C;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x8273321C;
	sub_82130588(ctx, base);
loc_8273321C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2810
	ctx.lr = 0x82733224;
	sub_821D2810(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8273322C"))) PPC_WEAK_FUNC(sub_8273322C);
PPC_FUNC_IMPL(__imp__sub_8273322C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82733230"))) PPC_WEAK_FUNC(sub_82733230);
PPC_FUNC_IMPL(__imp__sub_82733230) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82733238;
	// stwu r1,-528(r1)
	ea = -528 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,-4964(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -4964);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r29,8(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x821c9790
	ctx.lr = 0x82733260;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822d7638
	ctx.lr = 0x8273326C;
	sub_822D7638(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x827333f4
	if (!cr6.eq) goto loc_827333F4;
	// lwz r31,8(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// cmplw cr6,r31,r29
	cr6.compare<uint32_t>(r31.u32, r29.u32, xer);
	// beq cr6,0x827332a8
	if (cr6.eq) goto loc_827332A8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9790
	ctx.lr = 0x82733290;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822d7638
	ctx.lr = 0x8273329C;
	sub_822D7638(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x827333f4
	if (!cr6.eq) goto loc_827333F4;
loc_827332A8:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r11,-16028
	ctx.r4.s64 = r11.s64 + -16028;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x823dc018
	ctx.lr = 0x827332BC;
	sub_823DC018(ctx, base);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// bl 0x82732a20
	ctx.lr = 0x827332C4;
	sub_82732A20(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x821a5cc0
	ctx.lr = 0x827332CC;
	sub_821A5CC0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82733330
	if (cr6.eq) goto loc_82733330;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-31280
	ctx.r5.s64 = r11.s64 + -31280;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8248aa28
	ctx.lr = 0x827332F0;
	sub_8248AA28(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8248a828
	ctx.lr = 0x827332FC;
	sub_8248A828(ctx, base);
	// lwz r3,164(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8273331c
	if (!cr6.eq) goto loc_8273331C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8248a3b0
	ctx.lr = 0x82733310;
	sub_8248A3B0(ctx, base);
	// lwz r3,164(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82733320
	if (cr6.eq) goto loc_82733320;
loc_8273331C:
	// bl 0x824aae80
	ctx.lr = 0x82733320;
	sub_824AAE80(ctx, base);
loc_82733320:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8248ae08
	ctx.lr = 0x82733328;
	sub_8248AE08(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82489ce8
	ctx.lr = 0x82733330;
	sub_82489CE8(ctx, base);
loc_82733330:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82735be0
	ctx.lr = 0x82733338;
	sub_82735BE0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,13536
	ctx.r4.s64 = r11.s64 + 13536;
	// bl 0x823d90b0
	ctx.lr = 0x82733348;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82733358
	if (cr6.eq) goto loc_82733358;
	// li r11,1
	r11.s64 = 1;
	// stb r11,308(r31)
	PPC_STORE_U8(r31.u32 + 308, r11.u8);
loc_82733358:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82733380
	if (!cr6.eq) goto loc_82733380;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r11,-16144
	ctx.r3.s64 = r11.s64 + -16144;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// bl 0x82130000
	ctx.lr = 0x82733374;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// b 0x823d9248
	return;
loc_82733380:
	// lhz r11,20(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 20);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// blt cr6,0x8273339c
	if (cr6.lt) goto loc_8273339C;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r11,-16200
	ctx.r3.s64 = r11.s64 + -16200;
	// bl 0x821bd618
	ctx.lr = 0x8273339C;
	sub_821BD618(ctx, base);
loc_8273339C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8249e270
	ctx.lr = 0x827333A4;
	sub_8249E270(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827333c8
	if (!cr6.eq) goto loc_827333C8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,316(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 316);
	ctx.f13.f64 = double(temp.f32);
	// li r4,1
	ctx.r4.s64 = 1;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x827333cc
	if (cr6.lt) goto loc_827333CC;
loc_827333C8:
	// li r4,0
	ctx.r4.s64 = 0;
loc_827333CC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82735db0
	ctx.lr = 0x827333D4;
	sub_82735DB0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,8(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// bl 0x821c9790
	ctx.lr = 0x827333E4;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82732fb8
	ctx.lr = 0x827333F4;
	sub_82732FB8(ctx, base);
loc_827333F4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82733400"))) PPC_WEAK_FUNC(sub_82733400);
PPC_FUNC_IMPL(__imp__sub_82733400) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82733408;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82733430
	if (cr6.eq) goto loc_82733430;
	// bl 0x8217d890
	ctx.lr = 0x82733424;
	sub_8217D890(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_82733430:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// mr r24,r23
	r24.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827334c4
	if (cr6.eq) goto loc_827334C4;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,60
	r27.s64 = 60;
	// mr r25,r23
	r25.u64 = r23.u64;
loc_82733450:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r30,r27,r26
	r30.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// add r31,r25,r11
	r31.u64 = r25.u64 + r11.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x827334ac
	if (cr6.eq) goto loc_827334AC;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x827334ac
	if (cr6.eq) goto loc_827334AC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8273347C;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x827334ac
	if (cr6.eq) goto loc_827334AC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82733490;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwzx r5,r27,r26
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// bl 0x827363a0
	ctx.lr = 0x827334A8;
	sub_827363A0(ctx, base);
	// b 0x827334b0
	goto loc_827334B0;
loc_827334AC:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_827334B0:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x82733450
	if (cr6.lt) goto loc_82733450;
loc_827334C4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_827334D0"))) PPC_WEAK_FUNC(sub_827334D0);
PPC_FUNC_IMPL(__imp__sub_827334D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91e8
	ctx.lr = 0x827334D8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x827334E8;
	sub_82130528(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82733574
	if (!cr6.gt) goto loc_82733574;
	// mr r31,r24
	r31.u64 = r24.u64;
	// mr r26,r30
	r26.u64 = r30.u64;
	// li r25,0
	r25.s64 = 0;
loc_82733500:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82733568
	if (cr6.eq) goto loc_82733568;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82733564
	if (cr6.eq) goto loc_82733564;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82733564
	if (cr6.eq) goto loc_82733564;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82733534;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82733564
	if (cr6.eq) goto loc_82733564;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82733548;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwzx r5,r28,r27
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x827363a0
	ctx.lr = 0x82733560;
	sub_827363A0(ctx, base);
	// b 0x82733568
	goto loc_82733568;
loc_82733564:
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_82733568:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82733500
	if (!cr0.eq) goto loc_82733500;
loc_82733574:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82733580"))) PPC_WEAK_FUNC(sub_82733580);
PPC_FUNC_IMPL(__imp__sub_82733580) {
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
	// bl 0x821d2970
	ctx.lr = 0x827335A0;
	sub_821D2970(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,-19128
	ctx.r10.s64 = r11.s64 + -19128;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x827335B4;
	sub_821B5A60(ctx, base);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x827335d4
	if (cr6.eq) goto loc_827335D4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x827335C8;
	sub_8217D890(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
loc_827335D4:
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,24
	ctx.r3.s64 = r31.s64 + 24;
	// bl 0x82733090
	ctx.lr = 0x827335E4;
	sub_82733090(ctx, base);
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

__attribute__((alias("__imp__sub_82733600"))) PPC_WEAK_FUNC(sub_82733600);
PPC_FUNC_IMPL(__imp__sub_82733600) {
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
	// bl 0x82733160
	ctx.lr = 0x82733620;
	sub_82733160(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82733638
	if (cr6.eq) goto loc_82733638;
	// bl 0x82130588
	ctx.lr = 0x82733634;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82733638:
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

__attribute__((alias("__imp__sub_82733650"))) PPC_WEAK_FUNC(sub_82733650);
PPC_FUNC_IMPL(__imp__sub_82733650) {
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
	ctx.lr = 0x82733658;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x821d2970
	ctx.lr = 0x82733668;
	sub_821D2970(ctx, base);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-16232
	ctx.r9.s64 = ctx.r10.s64 + -16232;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// sth r11,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r11.u16);
	// sth r29,18(r31)
	PPC_STORE_U16(r31.u32 + 18, r29.u16);
	// beq cr6,0x827336a0
	if (cr6.eq) goto loc_827336A0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827334d0
	ctx.lr = 0x8273369C;
	sub_827334D0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_827336A0:
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827336B0"))) PPC_WEAK_FUNC(sub_827336B0);
PPC_FUNC_IMPL(__imp__sub_827336B0) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x827336B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82733724
	if (cr6.eq) goto loc_82733724;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82733724
	if (cr6.eq) goto loc_82733724;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x827336EC;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82733724
	if (cr6.eq) goto loc_82733724;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82733700;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273372c
	if (cr6.eq) goto loc_8273372C;
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x82733580
	ctx.lr = 0x8273371C;
	sub_82733580(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82733724:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_8273372C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82733734"))) PPC_WEAK_FUNC(sub_82733734);
PPC_FUNC_IMPL(__imp__sub_82733734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82733738"))) PPC_WEAK_FUNC(sub_82733738);
PPC_FUNC_IMPL(__imp__sub_82733738) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r15{};
	PPCRegister r16{};
	PPCRegister r17{};
	PPCRegister r18{};
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
	// bl 0x823d91c0
	ctx.lr = 0x82733740;
	// stwu r1,-832(r1)
	ea = -832 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r16,r5
	r16.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x82130528
	ctx.lr = 0x8273375C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82733770
	if (cr6.eq) goto loc_82733770;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8272c260
	ctx.lr = 0x8273376C;
	sub_8272C260(ctx, base);
	// b 0x82733774
	goto loc_82733774;
loc_82733770:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82733774:
	// stw r3,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r3.u32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,13552
	ctx.r4.s64 = r11.s64 + 13552;
	// li r14,0
	r14.s64 = 0;
	// li r15,0
	r15.s64 = 0;
	// bl 0x821d0898
	ctx.lr = 0x82733790;
	sub_821D0898(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827337A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r17,r11,-29624
	r17.s64 = r11.s64 + -29624;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// bl 0x821d0898
	ctx.lr = 0x827337C0;
	sub_821D0898(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82733a30
	if (!cr6.gt) goto loc_82733A30;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// lis r30,-32131
	r30.s64 = -2105737216;
	// lis r4,-32243
	ctx.r4.s64 = -2113077248;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r21,r3,13544
	r21.s64 = ctx.r3.s64 + 13544;
	// addi r27,r30,30576
	r27.s64 = r30.s64 + 30576;
	// addi r26,r4,-16244
	r26.s64 = ctx.r4.s64 + -16244;
	// addi r25,r5,13536
	r25.s64 = ctx.r5.s64 + 13536;
	// addi r24,r6,-29628
	r24.s64 = ctx.r6.s64 + -29628;
	// addi r23,r7,13528
	r23.s64 = ctx.r7.s64 + 13528;
	// addi r22,r8,13520
	r22.s64 = ctx.r8.s64 + 13520;
	// addi r20,r9,12868
	r20.s64 = ctx.r9.s64 + 12868;
	// addi r19,r10,13508
	r19.s64 = ctx.r10.s64 + 13508;
	// addi r18,r11,13500
	r18.s64 = r11.s64 + 13500;
loc_8273381C:
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82733828;
	sub_821D0898(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82733840;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x8273384C;
	sub_821D0898(ctx, base);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82733858;
	sub_821D0898(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,416
	ctx.r4.s64 = ctx.r1.s64 + 416;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82733874;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r4,r1,416
	ctx.r4.s64 = ctx.r1.s64 + 416;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x823dc018
	ctx.lr = 0x82733880;
	sub_823DC018(ctx, base);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x823d90b0
	ctx.lr = 0x8273388C;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273389c
	if (cr6.eq) goto loc_8273389C;
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
loc_8273389C:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x827338A8;
	sub_821D0898(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827338C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cntlzw r9,r3
	ctx.r9.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// xori r30,r8,1
	r30.u64 = ctx.r8.u64 ^ 1;
	// bl 0x821d0898
	ctx.lr = 0x827338D8;
	sub_821D0898(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,40(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 40);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x827338F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82733910;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8273392C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,40(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 40);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82733948;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d0898
	ctx.lr = 0x82733954;
	sub_821D0898(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x823d90b0
	ctx.lr = 0x82733960;
	sub_823D90B0(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x823d90b0
	ctx.lr = 0x8273396C;
	sub_823D90B0(ctx, base);
	// cntlzw r5,r3
	ctx.r5.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// xori r29,r4,1
	r29.u64 = ctx.r4.u64 ^ 1;
	// bne cr6,0x827339b8
	if (!cr6.eq) goto loc_827339B8;
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8273399c
	if (!cr6.eq) goto loc_8273399C;
	// addi r14,r14,1
	r14.s64 = r14.s64 + 1;
	// cmpwi cr6,r14,24576
	cr6.compare<int32_t>(r14.s32, 24576, xer);
	// b 0x827339a4
	goto loc_827339A4;
loc_8273399C:
	// addi r15,r15,1
	r15.s64 = r15.s64 + 1;
	// cmpwi cr6,r15,512
	cr6.compare<int32_t>(r15.s32, 512, xer);
loc_827339A4:
	// bgt cr6,0x82733a20
	if (cr6.gt) goto loc_82733A20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827339b8
	if (!cr6.eq) goto loc_827339B8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821b9c70
	ctx.lr = 0x827339B8;
	sub_821B9C70(ctx, base);
loc_827339B8:
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821ca540
	ctx.lr = 0x827339C4;
	sub_821CA540(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827339EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821c9a90
	ctx.lr = 0x827339F8;
	sub_821C9A90(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82733a20
	if (cr6.eq) goto loc_82733A20;
	// lhz r11,16(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 16);
	// addi r10,r28,12
	ctx.r10.s64 = r28.s64 + 12;
	// lwz r8,16(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r9,12(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,16(r28)
	PPC_STORE_U16(r28.u32 + 16, ctx.r7.u16);
	// stwx r8,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u32);
loc_82733A20:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bne 0x8273381c
	if (!cr0.eq) goto loc_8273381C;
loc_82733A30:
	// addi r1,r1,832
	ctx.r1.s64 = ctx.r1.s64 + 832;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82733A38"))) PPC_WEAK_FUNC(sub_82733A38);
PPC_FUNC_IMPL(__imp__sub_82733A38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82733A40;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// bl 0x821d2970
	ctx.lr = 0x82733A50;
	sub_821D2970(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r26,8
	ctx.r3.s64 = r26.s64 + 8;
	// addi r10,r11,-16232
	ctx.r10.s64 = r11.s64 + -16232;
	// stw r10,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r10.u32);
	// bl 0x827336b0
	ctx.lr = 0x82733A64;
	sub_827336B0(ctx, base);
	// addi r23,r26,12
	r23.s64 = r26.s64 + 12;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82733400
	ctx.lr = 0x82733A78;
	sub_82733400(ctx, base);
	// lhz r5,18(r26)
	ctx.r5.u64 = PPC_LOAD_U16(r26.u32 + 18);
	// lhz r4,16(r26)
	ctx.r4.u64 = PPC_LOAD_U16(r26.u32 + 16);
	// cmplw cr6,r4,r5
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r5.u32, xer);
	// beq cr6,0x82733a94
	if (cr6.eq) goto loc_82733A94;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-16008
	ctx.r3.s64 = r11.s64 + -16008;
	// bl 0x82130000
	ctx.lr = 0x82733A94;
	sub_82130000(ctx, base);
loc_82733A94:
	// lhz r11,16(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 16);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82733ad4
	if (!cr6.gt) goto loc_82733AD4;
	// li r31,0
	r31.s64 = 0;
	// mr r30,r11
	r30.u64 = r11.u64;
loc_82733AAC:
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82735850
	ctx.lr = 0x82733AB8;
	sub_82735850(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82733ac8
	if (cr6.eq) goto loc_82733AC8;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
loc_82733AC8:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x82733aac
	if (!cr0.eq) goto loc_82733AAC;
loc_82733AD4:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-7436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7436);
	// bl 0x822f7288
	ctx.lr = 0x82733AE4;
	sub_822F7288(ctx, base);
	// lhz r11,16(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82733b94
	if (!cr6.gt) goto loc_82733B94;
	// mr r27,r11
	r27.u64 = r11.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r28,0
	r28.s64 = 0;
	// addi r25,r11,-26560
	r25.s64 = r11.s64 + -26560;
loc_82733B00:
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// lwzx r29,r11,r28
	r29.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82735898
	ctx.lr = 0x82733B10;
	sub_82735898(ctx, base);
	// lwz r31,12(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82733b6c
	if (cr6.eq) goto loc_82733B6C;
	// lwz r30,0(r24)
	r30.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d828
	ctx.lr = 0x82733B2C;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82733b54
	if (cr6.eq) goto loc_82733B54;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// b 0x82733b68
	goto loc_82733B68;
loc_82733B54:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821d2378
	ctx.lr = 0x82733B64;
	sub_821D2378(ctx, base);
	// li r11,0
	r11.s64 = 0;
loc_82733B68:
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
loc_82733B6C:
	// stw r31,12(r29)
	PPC_STORE_U32(r29.u32 + 12, r31.u32);
	// addi r4,r29,16
	ctx.r4.s64 = r29.s64 + 16;
	// lwz r31,140(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82735580
	ctx.lr = 0x82733B80;
	sub_82735580(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82735280
	ctx.lr = 0x82733B88;
	sub_82735280(ctx, base);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x82733b00
	if (!cr0.eq) goto loc_82733B00;
loc_82733B94:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82733BA0"))) PPC_WEAK_FUNC(sub_82733BA0);
PPC_FUNC_IMPL(__imp__sub_82733BA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82733a38
	sub_82733A38(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82733BAC"))) PPC_WEAK_FUNC(sub_82733BAC);
PPC_FUNC_IMPL(__imp__sub_82733BAC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82733BB0"))) PPC_WEAK_FUNC(sub_82733BB0);
PPC_FUNC_IMPL(__imp__sub_82733BB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82733BB8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// lfs f1,92(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 92);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822da7e8
	ctx.lr = 0x82733BCC;
	sub_822DA7E8(ctx, base);
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r29,-1
	r29.s64 = -1;
	// ori r30,r10,65535
	r30.u64 = ctx.r10.u64 | 65535;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// ble cr6,0x82733bec
	if (!cr6.gt) goto loc_82733BEC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_82733BEC:
	// bl 0x82130528
	ctx.lr = 0x82733BF0;
	sub_82130528(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x823d9890
	ctx.lr = 0x82733C04;
	sub_823D9890(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x82733c18
	if (!cr6.gt) goto loc_82733C18;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_82733C18:
	// bl 0x82130528
	ctx.lr = 0x82733C1C;
	sub_82130528(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lwz r7,80(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// lfs f0,-15528(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -15528);
	f0.f64 = double(temp.f32);
	// blt cr6,0x82733c84
	if (cr6.lt) goto loc_82733C84;
	// addi r10,r7,-4
	ctx.r10.s64 = ctx.r7.s64 + -4;
	// li r11,0
	r11.s64 = 0;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_82733C4C:
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r9,r11,12
	ctx.r9.s64 = r11.s64 + 12;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stfsx f0,r8,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, temp.u32);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + r11.u64;
	// stfs f0,4(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stfs f0,-4(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + -4, temp.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stfsx f0,r3,r9
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + ctx.r9.u32, temp.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x82733c4c
	if (!cr0.eq) goto loc_82733C4C;
loc_82733C84:
	// cmpw cr6,r6,r7
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r7.s32, xer);
	// bge cr6,0x82733ca8
	if (!cr6.lt) goto loc_82733CA8;
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r6,r7
	r11.s64 = ctx.r7.s64 - ctx.r6.s64;
loc_82733C94:
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stfsx f0,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x82733c94
	if (!cr0.eq) goto loc_82733C94;
loc_82733CA8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82733CB0"))) PPC_WEAK_FUNC(sub_82733CB0);
PPC_FUNC_IMPL(__imp__sub_82733CB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x82680098
	ctx.lr = 0x82733CDC;
	sub_82680098(ctx, base);
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r5,0
	ctx.r5.s64 = 0;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// blt cr6,0x82733d30
	if (cr6.lt) goto loc_82733D30;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// bge cr6,0x82733d30
	if (!cr6.lt) goto loc_82733D30;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// blt cr6,0x82733d30
	if (cr6.lt) goto loc_82733D30;
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r8,r10
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, xer);
	// bge cr6,0x82733d30
	if (!cr6.lt) goto loc_82733D30;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// add. r11,r11,r6
	r11.u64 = r11.u64 + ctx.r6.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x82733d30
	if (!cr0.gt) goto loc_82733D30;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r7,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r7.u32);
	// b 0x82733d34
	goto loc_82733D34;
loc_82733D30:
	// stw r5,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r5.u32);
loc_82733D34:
	// addi r11,r6,-1
	r11.s64 = ctx.r6.s64 + -1;
	// addi r7,r8,-1
	ctx.r7.s64 = ctx.r8.s64 + -1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82733d84
	if (cr6.lt) goto loc_82733D84;
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82733d84
	if (!cr6.lt) goto loc_82733D84;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blt cr6,0x82733d84
	if (cr6.lt) goto loc_82733D84;
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r7,r9
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, xer);
	// bge cr6,0x82733d84
	if (!cr6.lt) goto loc_82733D84;
	// mullw r10,r10,r7
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// add. r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble 0x82733d84
	if (!cr0.gt) goto loc_82733D84;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r4,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// b 0x82733d88
	goto loc_82733D88;
loc_82733D84:
	// stw r5,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r5.u32);
loc_82733D88:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82733dd0
	if (cr6.lt) goto loc_82733DD0;
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82733dd0
	if (!cr6.lt) goto loc_82733DD0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// blt cr6,0x82733dd0
	if (cr6.lt) goto loc_82733DD0;
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// bge cr6,0x82733dd0
	if (!cr6.lt) goto loc_82733DD0;
	// mullw r10,r10,r8
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// add. r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble 0x82733dd0
	if (!cr0.gt) goto loc_82733DD0;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r4,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	// stw r3,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r3.u32);
	// b 0x82733dd4
	goto loc_82733DD4;
loc_82733DD0:
	// stw r5,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r5.u32);
loc_82733DD4:
	// addi r9,r8,1
	ctx.r9.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82733e20
	if (cr6.lt) goto loc_82733E20;
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82733e20
	if (!cr6.lt) goto loc_82733E20;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt cr6,0x82733e20
	if (cr6.lt) goto loc_82733E20;
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// bge cr6,0x82733e20
	if (!cr6.lt) goto loc_82733E20;
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// add. r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x82733e20
	if (!cr0.gt) goto loc_82733E20;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r4,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// stw r3,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r3.u32);
	// b 0x82733e24
	goto loc_82733E24;
loc_82733E20:
	// stw r5,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r5.u32);
loc_82733E24:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// blt cr6,0x82733e6c
	if (cr6.lt) goto loc_82733E6C;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// bge cr6,0x82733e6c
	if (!cr6.lt) goto loc_82733E6C;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt cr6,0x82733e6c
	if (cr6.lt) goto loc_82733E6C;
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bge cr6,0x82733e6c
	if (!cr6.lt) goto loc_82733E6C;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add. r11,r11,r6
	r11.u64 = r11.u64 + ctx.r6.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x82733e6c
	if (!cr0.gt) goto loc_82733E6C;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r4,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// stw r3,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r3.u32);
	// b 0x82733e70
	goto loc_82733E70;
loc_82733E6C:
	// stw r5,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r5.u32);
loc_82733E70:
	// addi r10,r6,1
	ctx.r10.s64 = ctx.r6.s64 + 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82733ebc
	if (cr6.lt) goto loc_82733EBC;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x82733ebc
	if (!cr6.lt) goto loc_82733EBC;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt cr6,0x82733ebc
	if (cr6.lt) goto loc_82733EBC;
	// lwz r4,88(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// bge cr6,0x82733ebc
	if (!cr6.lt) goto loc_82733EBC;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add. r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x82733ebc
	if (!cr0.gt) goto loc_82733EBC;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r4,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	// stw r3,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r3.u32);
	// b 0x82733ec0
	goto loc_82733EC0;
loc_82733EBC:
	// stw r5,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r5.u32);
loc_82733EC0:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82733f08
	if (cr6.lt) goto loc_82733F08;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x82733f08
	if (!cr6.lt) goto loc_82733F08;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// blt cr6,0x82733f08
	if (cr6.lt) goto loc_82733F08;
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// bge cr6,0x82733f08
	if (!cr6.lt) goto loc_82733F08;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// add. r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x82733f08
	if (!cr0.gt) goto loc_82733F08;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r8,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// stw r4,24(r30)
	PPC_STORE_U32(r30.u32 + 24, ctx.r4.u32);
	// b 0x82733f0c
	goto loc_82733F0C;
loc_82733F08:
	// stw r5,24(r30)
	PPC_STORE_U32(r30.u32 + 24, ctx.r5.u32);
loc_82733F0C:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82733f54
	if (cr6.lt) goto loc_82733F54;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x82733f54
	if (!cr6.lt) goto loc_82733F54;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blt cr6,0x82733f54
	if (cr6.lt) goto loc_82733F54;
	// lwz r9,88(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r7,r9
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, xer);
	// bge cr6,0x82733f54
	if (!cr6.lt) goto loc_82733F54;
	// mullw r11,r11,r7
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r7.s32);
	// add. r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x82733f54
	if (!cr0.gt) goto loc_82733F54;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,28(r30)
	PPC_STORE_U32(r30.u32 + 28, ctx.r8.u32);
	// b 0x82733f58
	goto loc_82733F58;
loc_82733F54:
	// stw r5,28(r30)
	PPC_STORE_U32(r30.u32 + 28, ctx.r5.u32);
loc_82733F58:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// blt cr6,0x82733fa0
	if (cr6.lt) goto loc_82733FA0;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// bge cr6,0x82733fa0
	if (!cr6.lt) goto loc_82733FA0;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blt cr6,0x82733fa0
	if (cr6.lt) goto loc_82733FA0;
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r7,r10
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, xer);
	// bge cr6,0x82733fa0
	if (!cr6.lt) goto loc_82733FA0;
	// mullw r11,r11,r7
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r7.s32);
	// add. r11,r11,r6
	r11.u64 = r11.u64 + ctx.r6.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x82733fa0
	if (!cr0.gt) goto loc_82733FA0;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,32(r30)
	PPC_STORE_U32(r30.u32 + 32, ctx.r8.u32);
	// b 0x82733fa4
	goto loc_82733FA4;
loc_82733FA0:
	// stw r5,32(r30)
	PPC_STORE_U32(r30.u32 + 32, ctx.r5.u32);
loc_82733FA4:
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

__attribute__((alias("__imp__sub_82733FBC"))) PPC_WEAK_FUNC(sub_82733FBC);
PPC_FUNC_IMPL(__imp__sub_82733FBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82733FC0"))) PPC_WEAK_FUNC(sub_82733FC0);
PPC_FUNC_IMPL(__imp__sub_82733FC0) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-15520
	ctx.r9.s64 = r11.s64 + -15520;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x82733FF8;
	sub_822E5148(ctx, base);
	// lis r8,-32119
	ctx.r8.s64 = -2104950784;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-10404(r8)
	PPC_STORE_U32(ctx.r8.u32 + -10404, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x8273400C;
	sub_822E6940(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82734024
	if (cr6.eq) goto loc_82734024;
	// bl 0x82130588
	ctx.lr = 0x82734020;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82734024:
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

__attribute__((alias("__imp__sub_8273403C"))) PPC_WEAK_FUNC(sub_8273403C);
PPC_FUNC_IMPL(__imp__sub_8273403C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82734040"))) PPC_WEAK_FUNC(sub_82734040);
PPC_FUNC_IMPL(__imp__sub_82734040) {
	PPC_FUNC_PROLOGUE();
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822e6b38
	ctx.lr = 0x8273405C;
	sub_822E6B38(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,24
	ctx.r10.s64 = 1572864;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r11,-15520
	ctx.r8.s64 = r11.s64 + -15520;
	// ori r7,r10,40946
	ctx.r7.u64 = ctx.r10.u64 | 40946;
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-8092(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8092);
	// bl 0x822e5138
	ctx.lr = 0x82734090;
	sub_822E5138(ctx, base);
	// lis r5,-32243
	ctx.r5.s64 = -2113077248;
	// addi r4,r5,-15496
	ctx.r4.s64 = ctx.r5.s64 + -15496;
	// li r30,0
	r30.s64 = 0;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// bl 0x822da7b0
	ctx.lr = 0x827340AC;
	sub_822DA7B0(ctx, base);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// stw r30,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r30.u32);
	// lfs f0,3796(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 3796);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
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

__attribute__((alias("__imp__sub_827340D8"))) PPC_WEAK_FUNC(sub_827340D8);
PPC_FUNC_IMPL(__imp__sub_827340D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,13500
	ctx.r3.s64 = r11.s64 + 13500;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827340E4"))) PPC_WEAK_FUNC(sub_827340E4);
PPC_FUNC_IMPL(__imp__sub_827340E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827340E8"))) PPC_WEAK_FUNC(sub_827340E8);
PPC_FUNC_IMPL(__imp__sub_827340E8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-15496
	ctx.r10.s64 = r11.s64 + -15496;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x82130588
	ctx.lr = 0x82734110;
	sub_82130588(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x82734118;
	sub_82130588(ctx, base);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// addi r7,r9,-15520
	ctx.r7.s64 = ctx.r9.s64 + -15520;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// lwz r3,-8092(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x82734134;
	sub_822E5148(ctx, base);
	// lis r6,-32119
	ctx.r6.s64 = -2104950784;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-10404(r6)
	PPC_STORE_U32(ctx.r6.u32 + -10404, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x82734148;
	sub_822E6940(ctx, base);
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

__attribute__((alias("__imp__sub_8273415C"))) PPC_WEAK_FUNC(sub_8273415C);
PPC_FUNC_IMPL(__imp__sub_8273415C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82734160"))) PPC_WEAK_FUNC(sub_82734160);
PPC_FUNC_IMPL(__imp__sub_82734160) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r18{};
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
	PPCRegister f0{};
	PPCRegister f23{};
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x82734168;
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823db9c4
	ctx.lr = 0x82734170;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,20(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 20);
	// lwzx r24,r10,r11
	r24.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x8273447c
	if (cr6.eq) goto loc_8273447C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lfs f27,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f27.f64 = double(temp.f32);
	// lfs f23,-12072(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12072);
	f23.f64 = double(temp.f32);
	// li r18,96
	r18.s64 = 96;
	// lfs f26,31020(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31020);
	f26.f64 = double(temp.f32);
	// lis r20,1024
	r20.s64 = 67108864;
	// lfs f28,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f28.f64 = double(temp.f32);
	// lis r17,4096
	r17.s64 = 268435456;
	// lfs f24,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f24.f64 = double(temp.f32);
	// lis r21,-32243
	r21.s64 = -2113077248;
	// lfs f25,-6172(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -6172);
	f25.f64 = double(temp.f32);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lis r23,-32119
	r23.s64 = -2104950784;
	// lis r19,-32115
	r19.s64 = -2104688640;
	// lis r22,-32119
	r22.s64 = -2104950784;
loc_827341DC:
	// lhz r11,30(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 30);
	// rlwinm r10,r11,0,0,16
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFF8000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82734470
	if (cr6.eq) goto loc_82734470;
	// lwz r26,16(r24)
	r26.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82734204;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// bne cr6,0x82734220
	if (!cr6.eq) goto loc_82734220;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8248a510
	ctx.lr = 0x82734214;
	sub_8248A510(ctx, base);
	// lbz r11,308(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 308);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82734470
	if (cr6.eq) goto loc_82734470;
loc_82734220:
	// lwz r11,19684(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 19684);
	// lwz r3,16(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// lfs f31,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f31.f64 = double(temp.f32);
	// bl 0x8248a510
	ctx.lr = 0x82734230;
	sub_8248A510(ctx, base);
	// lfs f30,28(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f30,f25
	cr6.compare(f30.f64, f25.f64);
	// bge cr6,0x82734284
	if (!cr6.lt) goto loc_82734284;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82734250;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// beq cr6,0x82734274
	if (cr6.eq) goto loc_82734274;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8273426C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// bne cr6,0x82734284
	if (!cr6.eq) goto loc_82734284;
loc_82734274:
	// lwz r11,156(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 156);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82734284
	if (cr6.eq) goto loc_82734284;
	// fmr f30,f24
	ctx.fpscr.disableFlushMode();
	f30.f64 = f24.f64;
loc_82734284:
	// lwz r11,16(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f13,184(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 184);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,180(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 180);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,176(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 176);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,-15540(r21)
	temp.u32 = PPC_LOAD_U32(r21.u32 + -15540);
	f0.f64 = double(temp.f32);
	// lvx128 v1,r11,r18
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f29,f31,f0
	f29.f64 = double(float(f31.f64 * f0.f64));
	// stvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f13,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f8.f64));
	// fsubs f6,f12,f10
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// fmuls f5,f7,f7
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f7.f64));
	// fsubs f4,f11,f9
	ctx.f4.f64 = double(float(ctx.f11.f64 - ctx.f9.f64));
	// fmadds f3,f6,f6,f5
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f5.f64));
	// fmadds f2,f4,f4,f3
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f3.f64));
	// fsqrts f1,f2
	ctx.f1.f64 = double(float(sqrt(ctx.f2.f64)));
	// fsubs f31,f1,f30
	f31.f64 = double(float(ctx.f1.f64 - f30.f64));
	// fcmpu cr6,f31,f28
	cr6.compare(f31.f64, f28.f64);
	// bge cr6,0x827342e0
	if (!cr6.lt) goto loc_827342E0;
	// fmr f31,f28
	f31.f64 = f28.f64;
loc_827342E0:
	// lfs f0,192(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 192);
	f0.f64 = double(temp.f32);
	// li r30,0
	r30.s64 = 0;
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// li r29,0
	r29.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// bge cr6,0x82734348
	if (!cr6.lt) goto loc_82734348;
	// lwz r3,112(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 112);
	// bl 0x8217c148
	ctx.lr = 0x82734304;
	sub_8217C148(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82734324
	if (cr6.eq) goto loc_82734324;
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f29.f64);
	// li r11,1
	r11.s64 = 1;
	// ble cr6,0x8273431c
	if (!cr6.gt) goto loc_8273431C;
	// li r11,0
	r11.s64 = 0;
loc_8273431C:
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
	// b 0x82734334
	goto loc_82734334;
loc_82734324:
	// lfs f0,196(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 196);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// bge cr6,0x82734348
	if (!cr6.lt) goto loc_82734348;
loc_82734334:
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f31,f26
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f26.f64);
	// ble cr6,0x82734344
	if (!cr6.gt) goto loc_82734344;
	// li r11,0
	r11.s64 = 0;
loc_82734344:
	// clrlwi r28,r11,24
	r28.u64 = r11.u32 & 0xFF;
loc_82734348:
	// lfs f0,200(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 200);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// bge cr6,0x8273436c
	if (!cr6.lt) goto loc_8273436C;
	// fcmpu cr6,f31,f23
	cr6.compare(f31.f64, f23.f64);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x82734368
	if (cr6.lt) goto loc_82734368;
	// li r11,0
	r11.s64 = 0;
loc_82734368:
	// clrlwi r29,r11,24
	r29.u64 = r11.u32 & 0xFF;
loc_8273436C:
	// lfs f0,192(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 192);
	f0.f64 = double(temp.f32);
	// clrlwi r31,r30,24
	r31.u64 = r30.u32 & 0xFF;
	// fdivs f13,f30,f0
	ctx.f13.f64 = double(float(f30.f64 / f0.f64));
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// fnmsubs f12,f30,f27,f13
	ctx.f12.f64 = double(float(-(f30.f64 * f27.f64 - ctx.f13.f64)));
	// fsel f11,f12,f12,f28
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f12.f64 : f28.f64;
	// fsubs f10,f11,f29
	ctx.f10.f64 = double(float(ctx.f11.f64 - f29.f64));
	// fsel f30,f10,f29,f11
	f30.f64 = ctx.f10.f64 >= 0.0 ? f29.f64 : ctx.f11.f64;
	// bne cr6,0x8273439c
	if (!cr6.eq) goto loc_8273439C;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827343e4
	if (cr6.eq) goto loc_827343E4;
loc_8273439C:
	// li r6,2
	ctx.r6.s64 = 2;
	// lwz r4,-17936(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + -17936);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,-17628(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -17628);
	// bl 0x82175238
	ctx.lr = 0x827343B0;
	sub_82175238(ctx, base);
	// rlwinm r11,r3,0,5,5
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4000000;
	// cmpw cr6,r11,r20
	cr6.compare<int32_t>(r11.s32, r20.s32, xer);
	// beq cr6,0x827343cc
	if (cr6.eq) goto loc_827343CC;
	// rlwinm r11,r3,0,3,3
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10000000;
	// cmpw cr6,r11,r17
	cr6.compare<int32_t>(r11.s32, r17.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x827343d0
	if (!cr6.eq) goto loc_827343D0;
loc_827343CC:
	// li r11,0
	r11.s64 = 0;
loc_827343D0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// and r9,r11,r31
	ctx.r9.u64 = r11.u64 & r31.u64;
	// and r29,r10,r11
	r29.u64 = ctx.r10.u64 & r11.u64;
	// clrlwi r30,r9,24
	r30.u64 = ctx.r9.u32 & 0xFF;
loc_827343E4:
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82734408
	if (!cr6.eq) goto loc_82734408;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82734408
	if (!cr6.eq) goto loc_82734408;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82734470
	if (cr6.eq) goto loc_82734470;
loc_82734408:
	// lwz r11,-4964(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -4964);
	// clrlwi r9,r29,24
	ctx.r9.u64 = r29.u32 & 0xFF;
	// clrlwi r8,r28,24
	ctx.r8.u64 = r28.u32 & 0xFF;
	// subfic r7,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r9.s64;
	// cntlzw r6,r10
	ctx.r6.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// subfe r5,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// stw r26,112(r11)
	PPC_STORE_U32(r11.u32 + 112, r26.u32);
	// subfic r4,r8,0
	xer.ca = ctx.r8.u32 <= 0;
	ctx.r4.s64 = 0 - ctx.r8.s64;
	// rlwinm r3,r6,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// subfe r10,r4,r4
	temp.u8 = (~ctx.r4.u32 + ctx.r4.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r4.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~ctx.r4.u64 + ctx.r4.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r9,r5,0,26,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x3E;
	// xori r7,r3,1
	ctx.r7.u64 = ctx.r3.u64 ^ 1;
	// rlwinm r8,r10,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// rlwinm r9,r9,0,30,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF3;
	// rotlwi r5,r7,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// lwz r11,-4964(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -4964);
	// addi r10,r11,116
	ctx.r10.s64 = r11.s64 + 116;
	// stw r7,116(r11)
	PPC_STORE_U32(r11.u32 + 116, ctx.r7.u32);
	// stw r4,116(r11)
	PPC_STORE_U32(r11.u32 + 116, ctx.r4.u32);
	// lwz r11,-4964(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -4964);
	// stfs f30,120(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 120, temp.u32);
	// stfs f31,124(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 124, temp.u32);
	// bl 0x8248a518
	ctx.lr = 0x82734470;
	sub_8248A518(ctx, base);
loc_82734470:
	// lwz r24,24(r24)
	r24.u64 = PPC_LOAD_U32(r24.u32 + 24);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// bne cr6,0x827341dc
	if (!cr6.eq) goto loc_827341DC;
loc_8273447C:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823dba10
	ctx.lr = 0x82734488;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_8273448C"))) PPC_WEAK_FUNC(sub_8273448C);
PPC_FUNC_IMPL(__imp__sub_8273448C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82734490"))) PPC_WEAK_FUNC(sub_82734490);
PPC_FUNC_IMPL(__imp__sub_82734490) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// cmpwi cr6,r4,1024
	cr6.compare<int32_t>(ctx.r4.s32, 1024, xer);
	// stw r4,-21564(r11)
	PPC_STORE_U32(r11.u32 + -21564, ctx.r4.u32);
	// bgt cr6,0x8273493c
	if (cr6.gt) goto loc_8273493C;
	// beq cr6,0x82734918
	if (cr6.eq) goto loc_82734918;
	// addi r11,r4,-2
	r11.s64 = ctx.r4.s64 + -2;
	// cmplwi cr6,r11,254
	cr6.compare<uint32_t>(r11.u32, 254, xer);
	// bgt cr6,0x827349c4
	if (cr6.gt) goto loc_827349C4;
	// lis r12,-32141
	r12.s64 = -2106392576;
	// addi r12,r12,17624
	r12.s64 = r12.s64 + 17624;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_827348D4;
	case 1:
		goto loc_827349C4;
	case 2:
		goto loc_827349C4;
	case 3:
		goto loc_827349C4;
	case 4:
		goto loc_827349C4;
	case 5:
		goto loc_827349C4;
	case 6:
		goto loc_827349C4;
	case 7:
		goto loc_827349C4;
	case 8:
		goto loc_827349C4;
	case 9:
		goto loc_827349C4;
	case 10:
		goto loc_827349C4;
	case 11:
		goto loc_827349C4;
	case 12:
		goto loc_827349C4;
	case 13:
		goto loc_827349C4;
	case 14:
		goto loc_827348F8;
	case 15:
		goto loc_827349C4;
	case 16:
		goto loc_827349C4;
	case 17:
		goto loc_827349C4;
	case 18:
		goto loc_827349C4;
	case 19:
		goto loc_827349C4;
	case 20:
		goto loc_827349C4;
	case 21:
		goto loc_827349C4;
	case 22:
		goto loc_827349C4;
	case 23:
		goto loc_827349C4;
	case 24:
		goto loc_827349C4;
	case 25:
		goto loc_827349C4;
	case 26:
		goto loc_827349C4;
	case 27:
		goto loc_827349C4;
	case 28:
		goto loc_827349C4;
	case 29:
		goto loc_827349C4;
	case 30:
		goto loc_827348F8;
	case 31:
		goto loc_827349C4;
	case 32:
		goto loc_827349C4;
	case 33:
		goto loc_827349C4;
	case 34:
		goto loc_827349C4;
	case 35:
		goto loc_827349C4;
	case 36:
		goto loc_827349C4;
	case 37:
		goto loc_827349C4;
	case 38:
		goto loc_827349C4;
	case 39:
		goto loc_827349C4;
	case 40:
		goto loc_827349C4;
	case 41:
		goto loc_827349C4;
	case 42:
		goto loc_827349C4;
	case 43:
		goto loc_827349C4;
	case 44:
		goto loc_827349C4;
	case 45:
		goto loc_827349C4;
	case 46:
		goto loc_827349C4;
	case 47:
		goto loc_827349C4;
	case 48:
		goto loc_827349C4;
	case 49:
		goto loc_827349C4;
	case 50:
		goto loc_827349C4;
	case 51:
		goto loc_827349C4;
	case 52:
		goto loc_827349C4;
	case 53:
		goto loc_827349C4;
	case 54:
		goto loc_827349C4;
	case 55:
		goto loc_827349C4;
	case 56:
		goto loc_827349C4;
	case 57:
		goto loc_827349C4;
	case 58:
		goto loc_827349C4;
	case 59:
		goto loc_827349C4;
	case 60:
		goto loc_827349C4;
	case 61:
		goto loc_827349C4;
	case 62:
		goto loc_827348F8;
	case 63:
		goto loc_827349C4;
	case 64:
		goto loc_827349C4;
	case 65:
		goto loc_827349C4;
	case 66:
		goto loc_827349C4;
	case 67:
		goto loc_827349C4;
	case 68:
		goto loc_827349C4;
	case 69:
		goto loc_827349C4;
	case 70:
		goto loc_827349C4;
	case 71:
		goto loc_827349C4;
	case 72:
		goto loc_827349C4;
	case 73:
		goto loc_827349C4;
	case 74:
		goto loc_827349C4;
	case 75:
		goto loc_827349C4;
	case 76:
		goto loc_827349C4;
	case 77:
		goto loc_827349C4;
	case 78:
		goto loc_827349C4;
	case 79:
		goto loc_827349C4;
	case 80:
		goto loc_827349C4;
	case 81:
		goto loc_827349C4;
	case 82:
		goto loc_827349C4;
	case 83:
		goto loc_827349C4;
	case 84:
		goto loc_827349C4;
	case 85:
		goto loc_827349C4;
	case 86:
		goto loc_827349C4;
	case 87:
		goto loc_827349C4;
	case 88:
		goto loc_827349C4;
	case 89:
		goto loc_827349C4;
	case 90:
		goto loc_827349C4;
	case 91:
		goto loc_827349C4;
	case 92:
		goto loc_827349C4;
	case 93:
		goto loc_827349C4;
	case 94:
		goto loc_827349C4;
	case 95:
		goto loc_827349C4;
	case 96:
		goto loc_827349C4;
	case 97:
		goto loc_827349C4;
	case 98:
		goto loc_827349C4;
	case 99:
		goto loc_827349C4;
	case 100:
		goto loc_827349C4;
	case 101:
		goto loc_827349C4;
	case 102:
		goto loc_827349C4;
	case 103:
		goto loc_827349C4;
	case 104:
		goto loc_827349C4;
	case 105:
		goto loc_827349C4;
	case 106:
		goto loc_827349C4;
	case 107:
		goto loc_827349C4;
	case 108:
		goto loc_827349C4;
	case 109:
		goto loc_827349C4;
	case 110:
		goto loc_827349C4;
	case 111:
		goto loc_827349C4;
	case 112:
		goto loc_827349C4;
	case 113:
		goto loc_827349C4;
	case 114:
		goto loc_827349C4;
	case 115:
		goto loc_827349C4;
	case 116:
		goto loc_827349C4;
	case 117:
		goto loc_827349C4;
	case 118:
		goto loc_827349C4;
	case 119:
		goto loc_827349C4;
	case 120:
		goto loc_827349C4;
	case 121:
		goto loc_827349C4;
	case 122:
		goto loc_827349C4;
	case 123:
		goto loc_827349C4;
	case 124:
		goto loc_827349C4;
	case 125:
		goto loc_827349C4;
	case 126:
		goto loc_827348F8;
	case 127:
		goto loc_827349C4;
	case 128:
		goto loc_827349C4;
	case 129:
		goto loc_827349C4;
	case 130:
		goto loc_827349C4;
	case 131:
		goto loc_827349C4;
	case 132:
		goto loc_827349C4;
	case 133:
		goto loc_827349C4;
	case 134:
		goto loc_827349C4;
	case 135:
		goto loc_827349C4;
	case 136:
		goto loc_827349C4;
	case 137:
		goto loc_827349C4;
	case 138:
		goto loc_827349C4;
	case 139:
		goto loc_827349C4;
	case 140:
		goto loc_827349C4;
	case 141:
		goto loc_827349C4;
	case 142:
		goto loc_827349C4;
	case 143:
		goto loc_827349C4;
	case 144:
		goto loc_827349C4;
	case 145:
		goto loc_827349C4;
	case 146:
		goto loc_827349C4;
	case 147:
		goto loc_827349C4;
	case 148:
		goto loc_827349C4;
	case 149:
		goto loc_827349C4;
	case 150:
		goto loc_827349C4;
	case 151:
		goto loc_827349C4;
	case 152:
		goto loc_827349C4;
	case 153:
		goto loc_827349C4;
	case 154:
		goto loc_827349C4;
	case 155:
		goto loc_827349C4;
	case 156:
		goto loc_827349C4;
	case 157:
		goto loc_827349C4;
	case 158:
		goto loc_827349C4;
	case 159:
		goto loc_827349C4;
	case 160:
		goto loc_827349C4;
	case 161:
		goto loc_827349C4;
	case 162:
		goto loc_827349C4;
	case 163:
		goto loc_827349C4;
	case 164:
		goto loc_827349C4;
	case 165:
		goto loc_827349C4;
	case 166:
		goto loc_827349C4;
	case 167:
		goto loc_827349C4;
	case 168:
		goto loc_827349C4;
	case 169:
		goto loc_827349C4;
	case 170:
		goto loc_827349C4;
	case 171:
		goto loc_827349C4;
	case 172:
		goto loc_827349C4;
	case 173:
		goto loc_827349C4;
	case 174:
		goto loc_827349C4;
	case 175:
		goto loc_827349C4;
	case 176:
		goto loc_827349C4;
	case 177:
		goto loc_827349C4;
	case 178:
		goto loc_827349C4;
	case 179:
		goto loc_827349C4;
	case 180:
		goto loc_827349C4;
	case 181:
		goto loc_827349C4;
	case 182:
		goto loc_827349C4;
	case 183:
		goto loc_827349C4;
	case 184:
		goto loc_827349C4;
	case 185:
		goto loc_827349C4;
	case 186:
		goto loc_827349C4;
	case 187:
		goto loc_827349C4;
	case 188:
		goto loc_827349C4;
	case 189:
		goto loc_827349C4;
	case 190:
		goto loc_827349C4;
	case 191:
		goto loc_827349C4;
	case 192:
		goto loc_827349C4;
	case 193:
		goto loc_827349C4;
	case 194:
		goto loc_827349C4;
	case 195:
		goto loc_827349C4;
	case 196:
		goto loc_827349C4;
	case 197:
		goto loc_827349C4;
	case 198:
		goto loc_827349C4;
	case 199:
		goto loc_827349C4;
	case 200:
		goto loc_827349C4;
	case 201:
		goto loc_827349C4;
	case 202:
		goto loc_827349C4;
	case 203:
		goto loc_827349C4;
	case 204:
		goto loc_827349C4;
	case 205:
		goto loc_827349C4;
	case 206:
		goto loc_827349C4;
	case 207:
		goto loc_827349C4;
	case 208:
		goto loc_827349C4;
	case 209:
		goto loc_827349C4;
	case 210:
		goto loc_827349C4;
	case 211:
		goto loc_827349C4;
	case 212:
		goto loc_827349C4;
	case 213:
		goto loc_827349C4;
	case 214:
		goto loc_827349C4;
	case 215:
		goto loc_827349C4;
	case 216:
		goto loc_827349C4;
	case 217:
		goto loc_827349C4;
	case 218:
		goto loc_827349C4;
	case 219:
		goto loc_827349C4;
	case 220:
		goto loc_827349C4;
	case 221:
		goto loc_827349C4;
	case 222:
		goto loc_827349C4;
	case 223:
		goto loc_827349C4;
	case 224:
		goto loc_827349C4;
	case 225:
		goto loc_827349C4;
	case 226:
		goto loc_827349C4;
	case 227:
		goto loc_827349C4;
	case 228:
		goto loc_827349C4;
	case 229:
		goto loc_827349C4;
	case 230:
		goto loc_827349C4;
	case 231:
		goto loc_827349C4;
	case 232:
		goto loc_827349C4;
	case 233:
		goto loc_827349C4;
	case 234:
		goto loc_827349C4;
	case 235:
		goto loc_827349C4;
	case 236:
		goto loc_827349C4;
	case 237:
		goto loc_827349C4;
	case 238:
		goto loc_827349C4;
	case 239:
		goto loc_827349C4;
	case 240:
		goto loc_827349C4;
	case 241:
		goto loc_827349C4;
	case 242:
		goto loc_827349C4;
	case 243:
		goto loc_827349C4;
	case 244:
		goto loc_827349C4;
	case 245:
		goto loc_827349C4;
	case 246:
		goto loc_827349C4;
	case 247:
		goto loc_827349C4;
	case 248:
		goto loc_827349C4;
	case 249:
		goto loc_827349C4;
	case 250:
		goto loc_827349C4;
	case 251:
		goto loc_827349C4;
	case 252:
		goto loc_827349C4;
	case 253:
		goto loc_827349C4;
	case 254:
		goto loc_827348F8;
	default:
		__builtin_unreachable();
	}
	// lwz r19,18644(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18644);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18680(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18680);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18680(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18680);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18680(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18680);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18680(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18680);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18884(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18884);
	// lwz r19,18680(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 18680);
loc_827348D4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-4964(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4964);
	// bl 0x82729438
	ctx.lr = 0x827348E4;
	sub_82729438(ctx, base);
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
loc_827348F8:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r10,-31280
	ctx.r4.s64 = ctx.r10.s64 + -31280;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x8273490C;
	sub_8217C088(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r3,-4964(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4964);
	// b 0x827349c0
	goto loc_827349C0;
loc_82734918:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x82734924;
	sub_82205248(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827349c4
	if (cr6.eq) goto loc_827349C4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4964(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4964);
	// b 0x827349c0
	goto loc_827349C0;
loc_8273493C:
	// lis r11,0
	r11.s64 = 0;
	// ori r10,r11,32768
	ctx.r10.u64 = r11.u64 | 32768;
	// cmpw cr6,r4,r10
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r10.s32, xer);
	// bgt cr6,0x82734994
	if (cr6.gt) goto loc_82734994;
	// cmplwi cr6,r4,32768
	cr6.compare<uint32_t>(ctx.r4.u32, 32768, xer);
	// beq cr6,0x82734970
	if (cr6.eq) goto loc_82734970;
	// cmpwi cr6,r4,2048
	cr6.compare<int32_t>(ctx.r4.s32, 2048, xer);
	// beq cr6,0x82734918
	if (cr6.eq) goto loc_82734918;
	// cmpwi cr6,r4,4096
	cr6.compare<int32_t>(ctx.r4.s32, 4096, xer);
	// bne cr6,0x827349c4
	if (!cr6.eq) goto loc_827349C4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4964(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4964);
	// b 0x827349c0
	goto loc_827349C0;
loc_82734970:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-4964(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4964);
	// bl 0x82729438
	ctx.lr = 0x82734980;
	sub_82729438(ctx, base);
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
loc_82734994:
	// lis r11,8
	r11.s64 = 524288;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// beq cr6,0x827349bc
	if (cr6.eq) goto loc_827349BC;
	// lis r11,16
	r11.s64 = 1048576;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bne cr6,0x827349c4
	if (!cr6.eq) goto loc_827349C4;
	// lwz r11,-4964(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -4964);
	// lwz r3,108(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// bl 0x8272fee0
	ctx.lr = 0x827349BC;
	sub_8272FEE0(ctx, base);
loc_827349BC:
	// lwz r3,-4964(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4964);
loc_827349C0:
	// bl 0x8272ac98
	ctx.lr = 0x827349C4;
	sub_8272AC98(ctx, base);
loc_827349C4:
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

__attribute__((alias("__imp__sub_827349D8"))) PPC_WEAK_FUNC(sub_827349D8);
PPC_FUNC_IMPL(__imp__sub_827349D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,24(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827349ec
	if (cr6.eq) goto loc_827349EC;
	// lwz r10,20(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
loc_827349EC:
	// lwz r11,20(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82734a04
	if (cr6.eq) goto loc_82734A04;
	// lwz r10,24(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// stw r10,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r10.u32);
	// b 0x82734a30
	goto loc_82734A30;
loc_82734A04:
	// lhz r11,28(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 28);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82734a30
	if (cr6.lt) goto loc_82734A30;
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// cmplw cr6,r9,r4
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r4.u32, xer);
	// bne cr6,0x82734a30
	if (!cr6.eq) goto loc_82734A30;
	// lwz r9,24(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// stwx r9,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r9.u32);
loc_82734A30:
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,24(r4)
	PPC_STORE_U32(ctx.r4.u32 + 24, r11.u32);
	// stw r11,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, r11.u32);
	// sth r10,28(r4)
	PPC_STORE_U16(ctx.r4.u32 + 28, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82734A48"))) PPC_WEAK_FUNC(sub_82734A48);
PPC_FUNC_IMPL(__imp__sub_82734A48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91ec
	ctx.lr = 0x82734A50;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r27,r28,48
	r27.s64 = r28.s64 + 48;
	// addi r29,r30,48
	r29.s64 = r30.s64 + 48;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lhz r25,28(r31)
	r25.u64 = PPC_LOAD_U16(r31.u32 + 28);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82680098
	ctx.lr = 0x82734A80;
	sub_82680098(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8248a510
	ctx.lr = 0x82734A88;
	sub_8248A510(ctx, base);
	// lwz r11,276(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 276);
	// li r26,0
	r26.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82734abc
	if (cr6.eq) goto loc_82734ABC;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8248a510
	ctx.lr = 0x82734AA0;
	sub_8248A510(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,28(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-12736(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12736);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82734abc
	if (cr6.lt) goto loc_82734ABC;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// b 0x82734ad0
	goto loc_82734AD0;
loc_82734ABC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x822da900
	ctx.lr = 0x82734ACC;
	sub_822DA900(ctx, base);
	// extsh r5,r3
	ctx.r5.s64 = ctx.r3.s16;
loc_82734AD0:
	// extsh r11,r5
	r11.s64 = ctx.r5.s16;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82734b48
	if (!cr6.eq) goto loc_82734B48;
	// lwz r31,16(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8248a510
	ctx.lr = 0x82734AE8;
	sub_8248A510(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,176(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 176);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82734b0c
	if (cr6.eq) goto loc_82734B0C;
	// li r4,47
	ctx.r4.s64 = 47;
	// bl 0x823db6d0
	ctx.lr = 0x82734B00;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r4,r3,1
	ctx.r4.s64 = ctx.r3.s64 + 1;
	// bne cr6,0x82734b10
	if (!cr6.eq) goto loc_82734B10;
loc_82734B0C:
	// lwz r4,176(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 176);
loc_82734B10:
	// lfs f3,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 120);
	ctx.f3.f64 = double(temp.f32);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f2,116(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,112(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r11,-15332
	ctx.r3.s64 = r11.s64 + -15332;
	// stfd f3,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f3.u64);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// stfd f2,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f2.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x82130000
	ctx.lr = 0x82734B40;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82734B48:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82734c08
	if (!cr6.lt) goto loc_82734C08;
	// extsh r11,r25
	r11.s64 = r25.s16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82734b7c
	if (cr6.lt) goto loc_82734B7C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827349d8
	ctx.lr = 0x82734B68;
	sub_827349D8(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-15360
	ctx.r3.s64 = r11.s64 + -15360;
	// bl 0x82130000
	ctx.lr = 0x82734B74;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82734B7C:
	// lfs f1,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f3,56(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 56);
	ctx.f3.f64 = double(temp.f32);
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// stfd f3,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f3.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// lfs f2,52(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 52);
	ctx.f2.f64 = double(temp.f32);
	// addi r3,r11,-15384
	ctx.r3.s64 = r11.s64 + -15384;
	// stfd f2,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f2.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x82130000
	ctx.lr = 0x82734BAC;
	sub_82130000(ctx, base);
	// lfs f6,72(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 72);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f5.f64 = double(temp.f32);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lfs f4,68(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 68);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// addi r3,r10,-15472
	ctx.r3.s64 = ctx.r10.s64 + -15472;
	// lfs f2,64(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 64);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// stfd f6,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.f6.u64);
	// ld r9,64(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 64);
	// stfd f5,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.f5.u64);
	// ld r8,56(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 56);
	// stfd f4,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f4.u64);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// stfd f3,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f3.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// stfd f2,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f2.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// bl 0x82130000
	ctx.lr = 0x82734C00;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82734C08:
	// lwz r10,80(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82734d0c
	if (!cr6.lt) goto loc_82734D0C;
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// lfsx f13,r10,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-15528(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -15528);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x82734c38
	if (!cr6.eq) goto loc_82734C38;
	// lfs f0,52(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 52);
	f0.f64 = double(temp.f32);
	// stfsx f0,r10,r8
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, temp.u32);
loc_82734C38:
	// extsh r10,r25
	ctx.r10.s64 = r25.s16;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x82734d0c
	if (cr6.eq) goto loc_82734D0C;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82734ccc
	if (!cr6.gt) goto loc_82734CCC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827349d8
	ctx.lr = 0x82734C58;
	sub_827349D8(ctx, base);
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwzx r6,r8,r11
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82734c84
	if (!cr6.eq) goto loc_82734C84;
	// stw r26,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r26.u32);
	// stw r26,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r26.u32);
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stwx r31,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, r31.u32);
	// sth r5,28(r31)
	PPC_STORE_U16(r31.u32 + 28, ctx.r5.u16);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82734C84:
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// lwzx r9,r8,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r7,19684(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 19684);
	// lfs f0,8(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// beq cr6,0x82734cbc
	if (cr6.eq) goto loc_82734CBC;
loc_82734CA4:
	// fcmpu cr6,f0,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f0.f64);
	// ble cr6,0x82734d14
	if (!cr6.gt) goto loc_82734D14;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82734ca4
	if (!cr6.eq) goto loc_82734CA4;
loc_82734CBC:
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// stw r26,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r26.u32);
	// sth r5,28(r31)
	PPC_STORE_U16(r31.u32 + 28, ctx.r5.u16);
loc_82734CCC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827349d8
	ctx.lr = 0x82734CD8;
	sub_827349D8(ctx, base);
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwzx r10,r8,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82734cf0
	if (cr6.eq) goto loc_82734CF0;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r31,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r31.u32);
loc_82734CF0:
	// stw r26,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r26.u32);
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lwzx r10,r8,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// lwz r9,20(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stwx r31,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r31.u32);
	// sth r5,28(r31)
	PPC_STORE_U16(r31.u32 + 28, ctx.r5.u16);
loc_82734D0C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82734D14:
	// cmplw cr6,r11,r6
	cr6.compare<uint32_t>(r11.u32, ctx.r6.u32, xer);
	// bne cr6,0x82734d24
	if (!cr6.eq) goto loc_82734D24;
	// stw r31,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r31.u32);
	// b 0x82734cf0
	goto loc_82734CF0;
loc_82734D24:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82734d4c
	if (!cr6.eq) goto loc_82734D4C;
	// stw r31,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r31.u32);
	// stw r26,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r26.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stwx r31,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, r31.u32);
	// sth r5,28(r31)
	PPC_STORE_U16(r31.u32 + 28, ctx.r5.u16);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82734D4C:
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stw r31,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r31.u32);
	// stw r31,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, r31.u32);
	// sth r5,28(r31)
	PPC_STORE_U16(r31.u32 + 28, ctx.r5.u16);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82734D68"))) PPC_WEAK_FUNC(sub_82734D68);
PPC_FUNC_IMPL(__imp__sub_82734D68) {
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
	// bl 0x827340e8
	ctx.lr = 0x82734D88;
	sub_827340E8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82734da0
	if (cr6.eq) goto loc_82734DA0;
	// bl 0x82130588
	ctx.lr = 0x82734D9C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82734DA0:
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

__attribute__((alias("__imp__sub_82734DB8"))) PPC_WEAK_FUNC(sub_82734DB8);
PPC_FUNC_IMPL(__imp__sub_82734DB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r14{};
	PPCRegister r15{};
	PPCRegister r16{};
	PPCRegister r17{};
	PPCRegister r18{};
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
	PPCRegister f0{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v55{};
	PPCVRegister v56{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82734DC0;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9d4
	ctx.lr = 0x82734DC8;
	// li r12,-224
	r12.s64 = -224;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-208
	r12.s64 = -208;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
	// addi r5,r31,128
	ctx.r5.s64 = r31.s64 + 128;
	// lwz r10,-8092(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r6,r11,45
	ctx.r6.s64 = r11.s64 + 45;
	// li r9,48
	ctx.r9.s64 = 48;
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r29,-32115
	r29.s64 = -2104688640;
	// lwzx r10,r4,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r10.u32);
	// addi r11,r10,64
	r11.s64 = ctx.r10.s64 + 64;
	// stw r10,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r10.u32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r5,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r5,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r5,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,19620(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 19620);
	// lwz r4,112(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// bl 0x82475e00
	ctx.lr = 0x82734E48;
	sub_82475E00(ctx, base);
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f12,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,19620(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 19620);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// li r9,736
	ctx.r9.s64 = 736;
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// li r27,1
	r27.s64 = 1;
	// lfs f0,-1540(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -1540);
	f0.f64 = double(temp.f32);
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// stfs f0,140(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stfs f11,136(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,19620(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 19620);
	// lfs f31,-15264(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -15264);
	f31.f64 = double(temp.f32);
	// lfs f0,17032(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 17032);
	f0.f64 = double(temp.f32);
	// lfd f1,-15272(r6)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r6.u32 + -15272);
	// stb r27,776(r11)
	PPC_STORE_U8(r11.u32 + 776, r27.u8);
	// lwz r5,112(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// lfs f10,712(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 712);
	ctx.f10.f64 = double(temp.f32);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// fmuls f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64));
	// stfs f9,192(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 192, temp.u32);
	// lfs f8,712(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 712);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// stfs f7,196(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 196, temp.u32);
	// bl 0x823dbf10
	ctx.lr = 0x82734EC8;
	sub_823DBF10(ctx, base);
	// frsp f6,f1
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = double(float(ctx.f1.f64));
	// li r22,0
	r22.s64 = 0;
	// addi r16,r31,176
	r16.s64 = r31.s64 + 176;
	// stw r22,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r22.u32);
	// addi r30,r31,48
	r30.s64 = r31.s64 + 48;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stw r22,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r22.u32);
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmuls f5,f6,f31
	ctx.f5.f64 = double(float(ctx.f6.f64 * f31.f64));
	// stfs f5,200(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 200, temp.u32);
	// bl 0x82680098
	ctx.lr = 0x82734EFC;
	sub_82680098(ctx, base);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r11,r22
	r11.u64 = r22.u64;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,14884(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stb r11,-21560(r10)
	PPC_STORE_U8(ctx.r10.u32 + -21560, r11.u8);
	// lfs f31,92(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 92);
	f31.f64 = double(temp.f32);
	// fmuls f29,f31,f0
	f29.f64 = double(float(f31.f64 * f0.f64));
	// lfs f4,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f4.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f13,-31324(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -31324);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r9,-32224
	r11.s64 = ctx.r9.s64 + -32224;
	// fmuls f28,f31,f13
	f28.f64 = double(float(f31.f64 * ctx.f13.f64));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f30,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f30.f64 = double(temp.f32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f12,14976(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14976);
	ctx.f12.f64 = double(temp.f32);
	// li r4,512
	ctx.r4.s64 = 512;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f27,f31,f12
	f27.f64 = double(float(f31.f64 * ctx.f12.f64));
	// fadds f3,f4,f29
	ctx.f3.f64 = double(float(ctx.f4.f64 + f29.f64));
	// fdivs f2,f3,f31
	ctx.f2.f64 = double(float(ctx.f3.f64 / f31.f64));
	// fadds f0,f2,f0
	f0.f64 = double(float(ctx.f2.f64 + f0.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r29,100(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82734160
	ctx.lr = 0x82734F80;
	sub_82734160(ctx, base);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v57,r0,r30
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f12,92(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// stfs f31,156(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// mr r20,r27
	r20.u64 = r27.u64;
	// stfs f31,152(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// mr r21,r27
	r21.u64 = r27.u64;
	// stfs f31,148(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// mr r24,r22
	r24.u64 = r22.u64;
	// stvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r25,r22
	r25.u64 = r22.u64;
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// mr r26,r22
	r26.u64 = r22.u64;
	// lfs f11,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// fdivs f1,f11,f12
	ctx.f1.f64 = double(float(ctx.f11.f64 / ctx.f12.f64));
	// stfs f31,144(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f29,160(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f30,164(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f29,168(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,172(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// bl 0x823dba38
	ctx.lr = 0x82734FD8;
	sub_823DBA38(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// lfs f9,92(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 92);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f8.f64 = double(temp.f32);
	// fdivs f1,f8,f9
	ctx.f1.f64 = double(float(ctx.f8.f64 / ctx.f9.f64));
	// fctiwz f7,f10
	ctx.f7.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f7.u64);
	// lwz r30,100(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823dba38
	ctx.lr = 0x82734FF8;
	sub_823DBA38(ctx, base);
	// frsp f6,f1
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = double(float(ctx.f1.f64));
	// mullw r7,r29,r29
	ctx.r7.s64 = int64_t(r29.s32) * int64_t(r29.s32);
	// stw r22,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r22.u32);
	// rlwinm r15,r7,2,0,29
	r15.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// fctiwz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r15,0
	cr6.compare<int32_t>(r15.s32, 0, xer);
	// blt cr6,0x8273525c
	if (cr6.lt) goto loc_8273525C;
	// lwz r17,112(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lwz r14,120(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// add r23,r11,r17
	r23.u64 = r11.u64 + r17.u64;
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// li r19,-1
	r19.s64 = -1;
	// lvx128 v126,r0,r10
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r18,-1
	r18.s64 = -1;
	// lfs f29,-14120(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -14120);
	f29.f64 = double(temp.f32);
	// mr r29,r17
	r29.u64 = r17.u64;
	// mr r28,r14
	r28.u64 = r14.u64;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r30,r30,r14
	r30.u64 = r30.u64 + r14.u64;
loc_82735054:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x827351a0
	if (cr6.lt) goto loc_827351A0;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// bge cr6,0x827351a0
	if (!cr6.lt) goto loc_827351A0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x827351a0
	if (cr6.lt) goto loc_827351A0;
	// lwz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// bge cr6,0x827351a0
	if (!cr6.lt) goto loc_827351A0;
	// mullw r11,r29,r11
	r11.s64 = int64_t(r29.s32) * int64_t(r11.s32);
	// add. r5,r11,r28
	ctx.r5.u64 = r11.u64 + r28.u64;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble 0x827351a0
	if (!cr0.gt) goto loc_827351A0;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827351a0
	if (cr6.eq) goto loc_827351A0;
	// extsw r9,r30
	ctx.r9.s64 = r30.s32;
	// stfs f30,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// extsw r10,r23
	ctx.r10.s64 = r23.s32;
	// vor128 v56,v126,v126
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// std r9,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r9.u64);
	// lfd f13,112(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// std r10,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r10.u64);
	// lfd f0,120(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// stfs f9,136(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// stfs f30,140(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lwz r6,28(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r17,-1
	ctx.r4.s64 = r17.s64 + -1;
	// cmpw cr6,r29,r4
	cr6.compare<int32_t>(r29.s32, ctx.r4.s32, xer);
	// lfsx f0,r6,r11
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// stfs f10,128(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v56,v55,v127,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v127.f32)), simde_mm_load_ps(v56.f32)));
	// stvx128 v56,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blt cr6,0x8273512c
	if (cr6.lt) goto loc_8273512C;
	// addi r11,r17,1
	r11.s64 = r17.s64 + 1;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bgt cr6,0x8273512c
	if (cr6.gt) goto loc_8273512C;
	// addi r11,r14,-1
	r11.s64 = r14.s64 + -1;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8273512c
	if (cr6.lt) goto loc_8273512C;
	// addi r11,r14,1
	r11.s64 = r14.s64 + 1;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// bgt cr6,0x8273512c
	if (cr6.gt) goto loc_8273512C;
	// stfs f27,140(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// b 0x82735130
	goto loc_82735130;
loc_8273512C:
	// stfs f28,140(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
loc_82735130:
	// lfs f13,4(r16)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r16.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f31,f29
	ctx.f12.f64 = double(float(f31.f64 + f29.f64));
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f10,8(r16)
	temp.u32 = PPC_LOAD_U32(r16.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// lfs f7,0(r16)
	temp.u32 = PPC_LOAD_U32(r16.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fmuls f4,f12,f12
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmuls f3,f11,f11
	ctx.f3.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f2,f8,f8,f3
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f3.f64));
	// fmadds f0,f5,f5,f2
	f0.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f2.f64));
	// fcmpu cr6,f0,f4
	cr6.compare(f0.f64, ctx.f4.f64);
	// bgt cr6,0x82735190
	if (cr6.gt) goto loc_82735190;
	// fsqrts f0,f0
	f0.f64 = double(float(sqrt(f0.f64)));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r4,512
	ctx.r4.s64 = 512;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// fneg f12,f13
	ctx.f12.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// fsel f1,f12,f30,f13
	ctx.f1.f64 = ctx.f12.f64 >= 0.0 ? f30.f64 : ctx.f13.f64;
	// bl 0x82734160
	ctx.lr = 0x8273518C;
	sub_82734160(ctx, base);
	// b 0x827351a0
	goto loc_827351A0;
loc_82735190:
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// beq cr6,0x8273525c
	if (cr6.eq) goto loc_8273525C;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// beq cr6,0x8273525c
	if (cr6.eq) goto loc_8273525C;
loc_827351A0:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// beq cr6,0x827351fc
	if (cr6.eq) goto loc_827351FC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827351d4
	if (cr6.eq) goto loc_827351D4;
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r24,r20
	cr6.compare<int32_t>(r24.s32, r20.s32, xer);
	// bne cr6,0x82735248
	if (!cr6.eq) goto loc_82735248;
	// mr r26,r22
	r26.u64 = r22.u64;
	// b 0x82735244
	goto loc_82735244;
loc_827351D4:
	// addi r24,r24,-1
	r24.s64 = r24.s64 + -1;
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// cmpw cr6,r24,r18
	cr6.compare<int32_t>(r24.s32, r18.s32, xer);
	// bne cr6,0x82735248
	if (!cr6.eq) goto loc_82735248;
	// mr r26,r22
	r26.u64 = r22.u64;
	// li r27,1
	r27.s64 = 1;
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// addi r18,r18,-1
	r18.s64 = r18.s64 + -1;
	// b 0x82735248
	goto loc_82735248;
loc_827351FC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82735224
	if (cr6.eq) goto loc_82735224;
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// cmpw cr6,r25,r21
	cr6.compare<int32_t>(r25.s32, r21.s32, xer);
	// bne cr6,0x82735248
	if (!cr6.eq) goto loc_82735248;
	// li r26,1
	r26.s64 = 1;
	// li r27,1
	r27.s64 = 1;
	// b 0x82735248
	goto loc_82735248;
loc_82735224:
	// addi r25,r25,-1
	r25.s64 = r25.s64 + -1;
	// addi r29,r29,-1
	r29.s64 = r29.s64 + -1;
	// addi r23,r23,-1
	r23.s64 = r23.s64 + -1;
	// cmpw cr6,r25,r19
	cr6.compare<int32_t>(r25.s32, r19.s32, xer);
	// bne cr6,0x82735248
	if (!cr6.eq) goto loc_82735248;
	// li r26,1
	r26.s64 = 1;
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// addi r19,r19,-1
	r19.s64 = r19.s64 + -1;
loc_82735244:
	// mr r27,r22
	r27.u64 = r22.u64;
loc_82735248:
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// cmpw cr6,r11,r15
	cr6.compare<int32_t>(r11.s32, r15.s32, xer);
	// ble cr6,0x82735054
	if (!cr6.gt) goto loc_82735054;
loc_8273525C:
	// stw r22,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r22.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// li r0,-224
	r0.s64 = -224;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-208
	r0.s64 = -208;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba20
	ctx.lr = 0x8273527C;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82735280"))) PPC_WEAK_FUNC(sub_82735280);
PPC_FUNC_IMPL(__imp__sub_82735280) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	// lhz r9,30(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 30);
	// li r10,-32768
	ctx.r10.s64 = -32768;
	// li r4,1
	ctx.r4.s64 = 1;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// sth r8,30(r3)
	PPC_STORE_U16(ctx.r3.u32 + 30, ctx.r8.u16);
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,156(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 156);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_827352A8"))) PPC_WEAK_FUNC(sub_827352A8);
PPC_FUNC_IMPL(__imp__sub_827352A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827352B4"))) PPC_WEAK_FUNC(sub_827352B4);
PPC_FUNC_IMPL(__imp__sub_827352B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827352B8"))) PPC_WEAK_FUNC(sub_827352B8);
PPC_FUNC_IMPL(__imp__sub_827352B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r3,r11,2272
	ctx.r3.s64 = r11.s64 + 2272;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827352C4"))) PPC_WEAK_FUNC(sub_827352C4);
PPC_FUNC_IMPL(__imp__sub_827352C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827352C8"))) PPC_WEAK_FUNC(sub_827352C8);
PPC_FUNC_IMPL(__imp__sub_827352C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x827352D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x824900a8
	ctx.lr = 0x827352E0;
	sub_824900A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82735304
	if (cr6.eq) goto loc_82735304;
	// lwz r5,52(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x82735304
	if (!cr6.gt) goto loc_82735304;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8272f6a0
	ctx.lr = 0x82735304;
	sub_8272F6A0(ctx, base);
loc_82735304:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82735310"))) PPC_WEAK_FUNC(sub_82735310);
PPC_FUNC_IMPL(__imp__sub_82735310) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82735318;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8248fb40
	ctx.lr = 0x82735328;
	sub_8248FB40(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272f750
	ctx.lr = 0x82735338;
	sub_8272F750(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82735344"))) PPC_WEAK_FUNC(sub_82735344);
PPC_FUNC_IMPL(__imp__sub_82735344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82735348"))) PPC_WEAK_FUNC(sub_82735348);
PPC_FUNC_IMPL(__imp__sub_82735348) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-14924
	ctx.r10.s64 = r11.s64 + -14924;
	// lhz r4,146(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 146);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82735380
	if (cr6.eq) goto loc_82735380;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x822f1348
	ctx.lr = 0x82735380;
	sub_822F1348(ctx, base);
loc_82735380:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272db28
	ctx.lr = 0x82735388;
	sub_8272DB28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82489ce8
	ctx.lr = 0x82735390;
	sub_82489CE8(ctx, base);
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

__attribute__((alias("__imp__sub_827353A4"))) PPC_WEAK_FUNC(sub_827353A4);
PPC_FUNC_IMPL(__imp__sub_827353A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827353A8"))) PPC_WEAK_FUNC(sub_827353A8);
PPC_FUNC_IMPL(__imp__sub_827353A8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-17600(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -17600);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273541c
	if (cr6.eq) goto loc_8273541C;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lbz r10,-17596(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -17596);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273541c
	if (cr6.eq) goto loc_8273541C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,64
	ctx.r4.s64 = r31.s64 + 64;
	// bl 0x82689ee8
	ctx.lr = 0x827353E8;
	sub_82689EE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82735414
	if (cr6.eq) goto loc_82735414;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82735414:
	// li r11,0
	r11.s64 = 0;
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
loc_8273541C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82735434"))) PPC_WEAK_FUNC(sub_82735434);
PPC_FUNC_IMPL(__imp__sub_82735434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82735438"))) PPC_WEAK_FUNC(sub_82735438);
PPC_FUNC_IMPL(__imp__sub_82735438) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8248af18
	ctx.lr = 0x82735450;
	sub_8248AF18(ctx, base);
	// lhz r4,146(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 146);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8273546c
	if (cr6.eq) goto loc_8273546C;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x822f1358
	ctx.lr = 0x8273546C;
	sub_822F1358(ctx, base);
loc_8273546C:
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

__attribute__((alias("__imp__sub_82735480"))) PPC_WEAK_FUNC(sub_82735480);
PPC_FUNC_IMPL(__imp__sub_82735480) {
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
	ctx.lr = 0x82735488;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lbz r10,-12497(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -12497);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82735508
	if (cr6.eq) goto loc_82735508;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r30,-32111
	r30.s64 = -2104426496;
	// addi r31,r11,19856
	r31.s64 = r11.s64 + 19856;
	// lwz r11,-21552(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21552);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x827354dc
	if (!cr6.eq) goto loc_827354DC;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r11,-21552(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21552, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,-16732
	ctx.r4.s64 = ctx.r9.s64 + -16732;
	// bl 0x82144a20
	ctx.lr = 0x827354D8;
	sub_82144A20(ctx, base);
	// stw r3,-21556(r30)
	PPC_STORE_U32(r30.u32 + -21556, ctx.r3.u32);
loc_827354DC:
	// lwz r4,176(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 176);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x827354f4
	if (cr6.eq) goto loc_827354F4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82144a20
	ctx.lr = 0x827354F0;
	sub_82144A20(ctx, base);
	// stw r3,352(r29)
	PPC_STORE_U32(r29.u32 + 352, ctx.r3.u32);
loc_827354F4:
	// lwz r11,352(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 352);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82735504
	if (!cr6.eq) goto loc_82735504;
	// lwz r11,-21556(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21556);
loc_82735504:
	// stw r11,352(r29)
	PPC_STORE_U32(r29.u32 + 352, r11.u32);
loc_82735508:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82735510"))) PPC_WEAK_FUNC(sub_82735510);
PPC_FUNC_IMPL(__imp__sub_82735510) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82740f18
	ctx.lr = 0x82735534;
	sub_82740F18(ctx, base);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// addi r9,r10,-14656
	ctx.r9.s64 = ctx.r10.s64 + -14656;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// lhz r7,30(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 30);
	// clrlwi r6,r7,17
	ctx.r6.u64 = ctx.r7.u32 & 0x7FFF;
	// sth r8,28(r31)
	PPC_STORE_U16(r31.u32 + 28, ctx.r8.u16);
	// sth r6,30(r31)
	PPC_STORE_U16(r31.u32 + 30, ctx.r6.u16);
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

__attribute__((alias("__imp__sub_82735580"))) PPC_WEAK_FUNC(sub_82735580);
PPC_FUNC_IMPL(__imp__sub_82735580) {
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
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10404(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10404);
	// bl 0x82734a48
	ctx.lr = 0x827355A8;
	sub_82734A48(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-3660(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -3660);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827355d8
	if (cr6.eq) goto loc_827355D8;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827355d8
	if (cr6.eq) goto loc_827355D8;
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x827355d8
	if (!cr6.eq) goto loc_827355D8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8226adb0
	ctx.lr = 0x827355D8;
	sub_8226ADB0(ctx, base);
loc_827355D8:
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

__attribute__((alias("__imp__sub_827355EC"))) PPC_WEAK_FUNC(sub_827355EC);
PPC_FUNC_IMPL(__imp__sub_827355EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827355F0"))) PPC_WEAK_FUNC(sub_827355F0);
PPC_FUNC_IMPL(__imp__sub_827355F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x8248a510
	ctx.lr = 0x8273560C;
	sub_8248A510(ctx, base);
	// lwz r11,336(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 336);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r10,340(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 340);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lfs f1,344(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 344);
	ctx.f1.f64 = double(temp.f32);
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

__attribute__((alias("__imp__sub_82735634"))) PPC_WEAK_FUNC(sub_82735634);
PPC_FUNC_IMPL(__imp__sub_82735634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82735638"))) PPC_WEAK_FUNC(sub_82735638);
PPC_FUNC_IMPL(__imp__sub_82735638) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// bl 0x8248a510
	ctx.lr = 0x8273564C;
	sub_8248A510(ctx, base);
	// lfs f1,344(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 344);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82735660"))) PPC_WEAK_FUNC(sub_82735660);
PPC_FUNC_IMPL(__imp__sub_82735660) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82735668;
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v125,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-64
	r12.s64 = -64;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-48
	r12.s64 = -48;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// vupkd3d128 v62,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v62 = vTemp;
	// vpermwi128 v127,v62,234
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v126,v62,186
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v125,v62,174
	simde_mm_store_si128((simde__m128i*)v125.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// bl 0x8248a510
	ctx.lr = 0x827356A4;
	sub_8248A510(ctx, base);
	// lwz r3,180(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82735724
	if (cr6.eq) goto loc_82735724;
	// lwz r30,12(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82735724
	if (cr6.eq) goto loc_82735724;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827356D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82735724
	if (cr6.eq) goto loc_82735724;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// li r9,96
	ctx.r9.s64 = 96;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lvx128 v61,r0,r3
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mulli r10,r10,224
	ctx.r10.s64 = ctx.r10.s64 * 224;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lvx128 v60,r8,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v60,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// beq cr6,0x8273571c
	if (cr6.eq) goto loc_8273571C;
	// li r11,16
	r11.s64 = 16;
	// stvx128 v127,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// stvx128 v126,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v125,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8273571C:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82735728
	goto loc_82735728;
loc_82735724:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82735728:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v125,r1,r0
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-64
	r0.s64 = -64;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-48
	r0.s64 = -48;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82735748"))) PPC_WEAK_FUNC(sub_82735748);
PPC_FUNC_IMPL(__imp__sub_82735748) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8248c058
	ctx.lr = 0x82735760;
	sub_8248C058(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8248a510
	ctx.lr = 0x82735768;
	sub_8248A510(ctx, base);
	// bl 0x8249e270
	ctx.lr = 0x8273576C;
	sub_8249E270(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82735798
	if (!cr6.eq) goto loc_82735798;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r4,2048
	ctx.r4.s64 = 2048;
	// bl 0x8258e640
	ctx.lr = 0x82735788;
	sub_8258E640(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,256
	ctx.r4.s64 = 256;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8258e640
	ctx.lr = 0x82735798;
	sub_8258E640(ctx, base);
loc_82735798:
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

__attribute__((alias("__imp__sub_827357AC"))) PPC_WEAK_FUNC(sub_827357AC);
PPC_FUNC_IMPL(__imp__sub_827357AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827357B0"))) PPC_WEAK_FUNC(sub_827357B0);
PPC_FUNC_IMPL(__imp__sub_827357B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r4,146(r3)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r3.u32 + 146);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// b 0x822f1358
	sub_822F1358(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827357CC"))) PPC_WEAK_FUNC(sub_827357CC);
PPC_FUNC_IMPL(__imp__sub_827357CC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827357D0"))) PPC_WEAK_FUNC(sub_827357D0);
PPC_FUNC_IMPL(__imp__sub_827357D0) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-14924
	ctx.r10.s64 = r11.s64 + -14924;
	// lhz r4,146(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 146);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82735810
	if (cr6.eq) goto loc_82735810;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x822f1348
	ctx.lr = 0x82735810;
	sub_822F1348(ctx, base);
loc_82735810:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272db28
	ctx.lr = 0x82735818;
	sub_8272DB28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82489ce8
	ctx.lr = 0x82735820;
	sub_82489CE8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82735838
	if (cr6.eq) goto loc_82735838;
	// bl 0x82130588
	ctx.lr = 0x82735834;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82735838:
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

__attribute__((alias("__imp__sub_82735850"))) PPC_WEAK_FUNC(sub_82735850);
PPC_FUNC_IMPL(__imp__sub_82735850) {
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
	// lwz r11,156(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 156);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8273587c
	if (cr6.eq) goto loc_8273587C;
	// bl 0x8248a510
	ctx.lr = 0x8273586C;
	sub_8248A510(ctx, base);
	// lwz r11,348(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 348);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82735880
	if (!cr6.eq) goto loc_82735880;
loc_8273587C:
	// li r11,0
	r11.s64 = 0;
loc_82735880:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82735894"))) PPC_WEAK_FUNC(sub_82735894);
PPC_FUNC_IMPL(__imp__sub_82735894) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82735898"))) PPC_WEAK_FUNC(sub_82735898);
PPC_FUNC_IMPL(__imp__sub_82735898) {
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
	// lwz r11,156(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827358fc
	if (cr6.eq) goto loc_827358FC;
	// lis r30,-32120
	r30.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// sth r11,146(r31)
	PPC_STORE_U16(r31.u32 + 146, r11.u16);
	// lwz r11,-7572(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827358fc
	if (cr6.eq) goto loc_827358FC;
	// bl 0x8248a510
	ctx.lr = 0x827358D8;
	sub_8248A510(ctx, base);
	// lwz r4,348(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 348);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x827358fc
	if (cr6.eq) goto loc_827358FC;
	// lwz r11,156(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// addi r6,r31,16
	ctx.r6.s64 = r31.s64 + 16;
	// lwz r3,-7572(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x822f1338
	ctx.lr = 0x827358F8;
	sub_822F1338(ctx, base);
	// sth r3,146(r31)
	PPC_STORE_U16(r31.u32 + 146, ctx.r3.u16);
loc_827358FC:
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

__attribute__((alias("__imp__sub_82735914"))) PPC_WEAK_FUNC(sub_82735914);
PPC_FUNC_IMPL(__imp__sub_82735914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82735918"))) PPC_WEAK_FUNC(sub_82735918);
PPC_FUNC_IMPL(__imp__sub_82735918) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82130000
	ctx.lr = 0x82735934;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8248a510
	ctx.lr = 0x8273593C;
	sub_8248A510(ctx, base);
	// lwz r30,352(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 352);
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r10,86(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 86);
	// lwz r11,-32452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -32452);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82735a20
	if (cr6.eq) goto loc_82735A20;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82735968;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,62(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 62);
	// rlwinm r8,r9,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82735998
	if (cr6.eq) goto loc_82735998;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82735998
	if (cr6.eq) goto loc_82735998;
	// lhz r11,32(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 32);
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// rotlwi r9,r11,3
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 3);
	// lwzx r11,r9,r10
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r4,r11,48
	ctx.r4.s64 = r11.s64 + 48;
	// b 0x8273599c
	goto loc_8273599C;
loc_82735998:
	// addi r4,r31,64
	ctx.r4.s64 = r31.s64 + 64;
loc_8273599C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f13,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lwz r10,90(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 90);
	// addi r9,r11,-12352
	ctx.r9.s64 = r11.s64 + -12352;
	// lfs f11,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,52(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	f0.f64 = double(temp.f32);
	// fmuls f9,f10,f10
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fsubs f8,f13,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f0,56(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	f0.f64 = double(temp.f32);
	// fsubs f7,f12,f0
	ctx.f7.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f0,48(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	f0.f64 = double(temp.f32);
	// fsubs f6,f11,f0
	ctx.f6.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fmuls f5,f8,f8
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fmadds f4,f7,f7,f5
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f5.f64));
	// fmadds f1,f6,f6,f4
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fcmpu cr6,f1,f9
	cr6.compare(ctx.f1.f64, ctx.f9.f64);
	// bgt cr6,0x82735a18
	if (cr6.gt) goto loc_82735A18;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// rlwinm r10,r11,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82735a0c
	if (cr6.eq) goto loc_82735A0C;
	// lbz r11,85(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 85);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82735a18
	if (cr6.eq) goto loc_82735A18;
loc_82735A0C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272f4b0
	ctx.lr = 0x82735A14;
	sub_8272F4B0(ctx, base);
	// b 0x82735a20
	goto loc_82735A20;
loc_82735A18:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8272dae8
	ctx.lr = 0x82735A20;
	sub_8272DAE8(ctx, base);
loc_82735A20:
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

__attribute__((alias("__imp__sub_82735A38"))) PPC_WEAK_FUNC(sub_82735A38);
PPC_FUNC_IMPL(__imp__sub_82735A38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82735a88
	if (cr6.eq) goto loc_82735A88;
	// lwz r10,376(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 376);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82735a88
	if (cr6.eq) goto loc_82735A88;
	// lwz r11,364(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 364);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82735a88
	if (!cr6.eq) goto loc_82735A88;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lhz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + 8);
	// li r3,0
	ctx.r3.s64 = 0;
	// rotlwi r10,r10,3
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// lwz r11,-23452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23452);
	// lwz r11,112(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// clrlwi r7,r8,30
	ctx.r7.u64 = ctx.r8.u32 & 0x3;
	// cmpwi cr6,r7,2
	cr6.compare<int32_t>(ctx.r7.s32, 2, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_82735A88:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82735A90"))) PPC_WEAK_FUNC(sub_82735A90);
PPC_FUNC_IMPL(__imp__sub_82735A90) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// bl 0x82489dc0
	ctx.lr = 0x82735AD4;
	sub_82489DC0(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r5.u32);
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// bl 0x82741078
	ctx.lr = 0x82735AFC;
	sub_82741078(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,92(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 92);
	// bl 0x822a7c08
	ctx.lr = 0x82735B08;
	sub_822A7C08(ctx, base);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82735b4c
	if (!cr6.eq) goto loc_82735B4C;
loc_82735B14:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f0,320(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 320);
	f0.f64 = double(temp.f32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stfs f0,44(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 44, temp.u32);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// bl 0x822a7c08
	ctx.lr = 0x82735B40;
	sub_822A7C08(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82735b14
	if (cr6.eq) goto loc_82735B14;
loc_82735B4C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_82735B64"))) PPC_WEAK_FUNC(sub_82735B64);
PPC_FUNC_IMPL(__imp__sub_82735B64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82735B68"))) PPC_WEAK_FUNC(sub_82735B68);
PPC_FUNC_IMPL(__imp__sub_82735B68) {
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
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8249ee08
	ctx.lr = 0x82735B84;
	sub_8249EE08(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,-14616
	ctx.r9.s64 = r11.s64 + -14616;
	// li r11,0
	r11.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,336(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 336, temp.u32);
	// stfs f0,340(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 340, temp.u32);
	// stw r11,348(r31)
	PPC_STORE_U32(r31.u32 + 348, r11.u32);
	// stfs f0,344(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 344, temp.u32);
	// stw r11,352(r31)
	PPC_STORE_U32(r31.u32 + 352, r11.u32);
	// stw r11,356(r31)
	PPC_STORE_U32(r31.u32 + 356, r11.u32);
	// stw r11,360(r31)
	PPC_STORE_U32(r31.u32 + 360, r11.u32);
	// stw r11,364(r31)
	PPC_STORE_U32(r31.u32 + 364, r11.u32);
	// bl 0x82735480
	ctx.lr = 0x82735BC4;
	sub_82735480(ctx, base);
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

__attribute__((alias("__imp__sub_82735BDC"))) PPC_WEAK_FUNC(sub_82735BDC);
PPC_FUNC_IMPL(__imp__sub_82735BDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82735BE0"))) PPC_WEAK_FUNC(sub_82735BE0);
PPC_FUNC_IMPL(__imp__sub_82735BE0) {
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
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822fe3a8
	ctx.lr = 0x82735BFC;
	sub_822FE3A8(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-7572(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82735c74
	if (cr6.eq) goto loc_82735C74;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82735c2c
	if (cr6.eq) goto loc_82735C2C;
	// li r4,47
	ctx.r4.s64 = 47;
	// bl 0x823db6d0
	ctx.lr = 0x82735C20;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r4,r3,1
	ctx.r4.s64 = ctx.r3.s64 + 1;
	// bne cr6,0x82735c30
	if (!cr6.eq) goto loc_82735C30;
loc_82735C2C:
	// lwz r4,176(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 176);
loc_82735C30:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,-7436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7436);
	// bl 0x822f8718
	ctx.lr = 0x82735C40;
	sub_822F8718(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82735c74
	if (cr6.eq) goto loc_82735C74;
	// li r3,96
	ctx.r3.s64 = 96;
	// bl 0x82130528
	ctx.lr = 0x82735C54;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82735c64
	if (cr6.eq) goto loc_82735C64;
	// bl 0x822fe3a8
	ctx.lr = 0x82735C60;
	sub_822FE3A8(ctx, base);
	// b 0x82735c68
	goto loc_82735C68;
loc_82735C64:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82735C68:
	// stw r3,348(r31)
	PPC_STORE_U32(r31.u32 + 348, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822f1538
	ctx.lr = 0x82735C74;
	sub_822F1538(ctx, base);
loc_82735C74:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82735C88"))) PPC_WEAK_FUNC(sub_82735C88);
PPC_FUNC_IMPL(__imp__sub_82735C88) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,-14656
	ctx.r8.s64 = ctx.r10.s64 + -14656;
	// lhz r11,30(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 30);
	// stw r9,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r9.u32);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// rlwinm r7,r11,0,16,16
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8000;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x82735cf4
	if (cr6.eq) goto loc_82735CF4;
	// clrlwi r11,r11,17
	r11.u64 = r11.u32 & 0x7FFF;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// sth r11,30(r31)
	PPC_STORE_U16(r31.u32 + 30, r11.u16);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10404(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10404);
	// bl 0x827349d8
	ctx.lr = 0x82735CDC;
	sub_827349D8(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r3,-3660(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3660);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82735cf4
	if (cr6.eq) goto loc_82735CF4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8226a930
	ctx.lr = 0x82735CF4;
	sub_8226A930(ctx, base);
loc_82735CF4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82740ec0
	ctx.lr = 0x82735CFC;
	sub_82740EC0(ctx, base);
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

__attribute__((alias("__imp__sub_82735D10"))) PPC_WEAK_FUNC(sub_82735D10);
PPC_FUNC_IMPL(__imp__sub_82735D10) {
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
	// bl 0x82735c88
	ctx.lr = 0x82735D30;
	sub_82735C88(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82735d48
	if (cr6.eq) goto loc_82735D48;
	// bl 0x82130588
	ctx.lr = 0x82735D44;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82735D48:
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

__attribute__((alias("__imp__sub_82735D60"))) PPC_WEAK_FUNC(sub_82735D60);
PPC_FUNC_IMPL(__imp__sub_82735D60) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8249efb8
	ctx.lr = 0x82735D78;
	sub_8249EFB8(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-14616
	ctx.r10.s64 = r11.s64 + -14616;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82735be0
	ctx.lr = 0x82735D8C;
	sub_82735BE0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82735480
	ctx.lr = 0x82735D94;
	sub_82735480(ctx, base);
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

__attribute__((alias("__imp__sub_82735DAC"))) PPC_WEAK_FUNC(sub_82735DAC);
PPC_FUNC_IMPL(__imp__sub_82735DAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82735DB0"))) PPC_WEAK_FUNC(sub_82735DB0);
PPC_FUNC_IMPL(__imp__sub_82735DB0) {
	PPC_FUNC_PROLOGUE();
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r11,228(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 228);
	// lwz r30,12(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// beq cr6,0x82735e20
	if (cr6.eq) goto loc_82735E20;
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// bne cr6,0x82735e20
	if (!cr6.eq) goto loc_82735E20;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82599f10
	ctx.lr = 0x82735DF0;
	sub_82599F10(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// ble cr6,0x82735e54
	if (!cr6.gt) goto loc_82735E54;
	// lwz r11,128(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r6,r10,24408
	ctx.r6.s64 = ctx.r10.s64 + 24408;
	// addi r5,r9,24380
	ctx.r5.s64 = ctx.r9.s64 + 24380;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x823dedd8
	ctx.lr = 0x82735E1C;
	sub_823DEDD8(ctx, base);
	// b 0x82735e2c
	goto loc_82735E2C;
loc_82735E20:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82735e54
	if (!cr6.eq) goto loc_82735E54;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82735E2C:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82735e54
	if (cr6.eq) goto loc_82735E54;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,128(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,344(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 344, temp.u32);
	// lfs f0,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,336(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 336, temp.u32);
	// stfs f12,340(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 340, temp.u32);
	// b 0x82735ec8
	goto loc_82735EC8;
loc_82735E54:
	// lfs f0,24(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 24);
	f0.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f13,40(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fabs f12,f0
	ctx.f12.u64 = f0.u64 & ~0x8000000000000000;
	// fabs f10,f13
	ctx.f10.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// lfs f11,16(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f9,32(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// fabs f8,f11
	ctx.f8.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fabs f7,f9
	ctx.f7.u64 = ctx.f9.u64 & ~0x8000000000000000;
	// addi r11,r31,336
	r11.s64 = r31.s64 + 336;
	// lfs f0,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fsubs f6,f10,f12
	ctx.f6.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// fsubs f5,f7,f8
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// fsel f4,f6,f10,f12
	ctx.f4.f64 = ctx.f6.f64 >= 0.0 ? ctx.f10.f64 : ctx.f12.f64;
	// stfs f4,340(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 340, temp.u32);
	// fsel f3,f5,f7,f8
	ctx.f3.f64 = ctx.f5.f64 >= 0.0 ? ctx.f7.f64 : ctx.f8.f64;
	// stfs f3,336(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 336, temp.u32);
	// fmr f1,f4
	ctx.f1.f64 = ctx.f4.f64;
	// fmr f2,f3
	ctx.f2.f64 = ctx.f3.f64;
	// fmuls f13,f1,f1
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f1.f64));
	// fmadds f12,f2,f2,f13
	ctx.f12.f64 = double(float(ctx.f2.f64 * ctx.f2.f64 + ctx.f13.f64));
	// fsqrts f11,f12
	ctx.f11.f64 = double(float(sqrt(ctx.f12.f64)));
	// stfs f11,344(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 344, temp.u32);
	// lfs f10,336(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 336);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,340(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 340);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 * f0.f64));
	// stfs f8,336(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 336, temp.u32);
	// fmuls f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 * f0.f64));
	// stfs f7,340(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 340, temp.u32);
loc_82735EC8:
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

__attribute__((alias("__imp__sub_82735EE0"))) PPC_WEAK_FUNC(sub_82735EE0);
PPC_FUNC_IMPL(__imp__sub_82735EE0) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82735EE8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r29,60
	r29.s64 = 60;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwzx r30,r29,r28
	r30.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82735f4c
	if (cr6.eq) goto loc_82735F4C;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82735f4c
	if (cr6.eq) goto loc_82735F4C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x82735F1C;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82735f4c
	if (cr6.eq) goto loc_82735F4C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82735F30;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x821c96f8
	ctx.lr = 0x82735F44;
	sub_821C96F8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82735F4C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82735F5C"))) PPC_WEAK_FUNC(sub_82735F5C);
PPC_FUNC_IMPL(__imp__sub_82735F5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82735F60"))) PPC_WEAK_FUNC(sub_82735F60);
PPC_FUNC_IMPL(__imp__sub_82735F60) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82735f9c
	if (cr6.eq) goto loc_82735F9C;
	// bl 0x8249efb8
	ctx.lr = 0x82735F80;
	sub_8249EFB8(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-14616
	ctx.r10.s64 = r11.s64 + -14616;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82735be0
	ctx.lr = 0x82735F94;
	sub_82735BE0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82735480
	ctx.lr = 0x82735F9C;
	sub_82735480(ctx, base);
loc_82735F9C:
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

__attribute__((alias("__imp__sub_82735FB0"))) PPC_WEAK_FUNC(sub_82735FB0);
PPC_FUNC_IMPL(__imp__sub_82735FB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82735FB8;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x8248aa28
	ctx.lr = 0x82735FCC;
	sub_8248AA28(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r23,r28,152
	r23.s64 = r28.s64 + 152;
	// addi r10,r11,-14924
	ctx.r10.s64 = r11.s64 + -14924;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// bl 0x82735ee0
	ctx.lr = 0x82735FE4;
	sub_82735EE0(ctx, base);
	// addi r24,r28,156
	r24.s64 = r28.s64 + 156;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82735ee0
	ctx.lr = 0x82735FF0;
	sub_82735EE0(ctx, base);
	// li r9,4
	ctx.r9.s64 = 4;
	// clrlwi r8,r31,24
	ctx.r8.u64 = r31.u32 & 0xFF;
	// stb r31,145(r28)
	PPC_STORE_U8(r28.u32 + 145, r31.u8);
	// stb r9,144(r28)
	PPC_STORE_U8(r28.u32 + 144, ctx.r9.u8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82736010
	if (cr6.eq) goto loc_82736010;
	// li r11,3
	r11.s64 = 3;
	// b 0x82736044
	goto loc_82736044;
loc_82736010:
	// lwz r3,92(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 92);
	// bl 0x8249e270
	ctx.lr = 0x82736018;
	sub_8249E270(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82736040
	if (!cr6.eq) goto loc_82736040;
	// lwz r11,92(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 92);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,316(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 316);
	ctx.f13.f64 = double(temp.f32);
	// li r11,2
	r11.s64 = 2;
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82736044
	if (cr6.lt) goto loc_82736044;
loc_82736040:
	// li r11,1
	r11.s64 = 1;
loc_82736044:
	// stw r11,128(r28)
	PPC_STORE_U32(r28.u32 + 128, r11.u32);
	// li r22,0
	r22.s64 = 0;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r27,r22
	r27.u64 = r22.u64;
	// stw r22,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r22.u32);
	// addi r25,r11,-14604
	r25.s64 = r11.s64 + -14604;
loc_8273605C:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823dc018
	ctx.lr = 0x8273606C;
	sub_823DC018(ctx, base);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82735660
	ctx.lr = 0x8273607C;
	sub_82735660(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82736094
	if (cr6.eq) goto loc_82736094;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmpwi cr6,r27,100
	cr6.compare<int32_t>(r27.s32, 100, xer);
	// blt cr6,0x8273605c
	if (cr6.lt) goto loc_8273605C;
loc_82736094:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x827361dc
	if (cr6.eq) goto loc_827361DC;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x827360A4;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827360d0
	if (cr6.eq) goto loc_827360D0;
	// clrlwi r11,r27,16
	r11.u64 = r27.u32 & 0xFFFF;
	// rlwinm r3,r27,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 4) & 0xFFFFFFF0;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// bl 0x82130528
	ctx.lr = 0x827360C4;
	sub_82130528(ctx, base);
	// mr r11,r31
	r11.u64 = r31.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// b 0x827360d4
	goto loc_827360D4;
loc_827360D0:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_827360D4:
	// stw r11,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r11.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x827360E0;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8273610c
	if (cr6.eq) goto loc_8273610C;
	// clrlwi r11,r27,16
	r11.u64 = r27.u32 & 0xFFFF;
	// rlwinm r3,r27,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// bl 0x82130528
	ctx.lr = 0x82736100;
	sub_82130528(ctx, base);
	// mr r11,r31
	r11.u64 = r31.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// b 0x82736110
	goto loc_82736110;
loc_8273610C:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_82736110:
	// stw r11,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r11.u32);
	// mr r31,r22
	r31.u64 = r22.u64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82736180
	if (!cr6.gt) goto loc_82736180;
	// mr r29,r22
	r29.u64 = r22.u64;
	// mr r30,r22
	r30.u64 = r22.u64;
	// li r26,-1
	r26.s64 = -1;
loc_8273612C:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823dc018
	ctx.lr = 0x8273613C;
	sub_823DC018(ctx, base);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82735660
	ctx.lr = 0x8273614C;
	sub_82735660(ctx, base);
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r27
	cr6.compare<int32_t>(r31.s32, r27.s32, xer);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,0(r23)
	ctx.r8.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// stwx r26,r7,r29
	PPC_STORE_U32(ctx.r7.u32 + r29.u32, r26.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// blt cr6,0x8273612c
	if (cr6.lt) goto loc_8273612C;
loc_82736180:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827361e0
	if (cr6.eq) goto loc_827361E0;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// sth r22,146(r28)
	PPC_STORE_U16(r28.u32 + 146, r22.u16);
	// lwz r11,-7572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827361e0
	if (cr6.eq) goto loc_827361E0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8248a510
	ctx.lr = 0x827361A8;
	sub_8248A510(ctx, base);
	// lwz r4,348(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 348);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x827361e0
	if (cr6.eq) goto loc_827361E0;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// addi r6,r28,16
	ctx.r6.s64 = r28.s64 + 16;
	// lwz r3,-7572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x822f1338
	ctx.lr = 0x827361C8;
	sub_822F1338(ctx, base);
	// sth r3,146(r28)
	PPC_STORE_U16(r28.u32 + 146, ctx.r3.u16);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r22,148(r28)
	PPC_STORE_U32(r28.u32 + 148, r22.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9230
	return;
loc_827361DC:
	// sth r22,146(r28)
	PPC_STORE_U16(r28.u32 + 146, r22.u16);
loc_827361E0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r22,148(r28)
	PPC_STORE_U32(r28.u32 + 148, r22.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_827361F0"))) PPC_WEAK_FUNC(sub_827361F0);
PPC_FUNC_IMPL(__imp__sub_827361F0) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8248c620
	ctx.lr = 0x82736208;
	sub_8248C620(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r31,152
	ctx.r3.s64 = r31.s64 + 152;
	// addi r10,r11,-14924
	ctx.r10.s64 = r11.s64 + -14924;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82735ee0
	ctx.lr = 0x8273621C;
	sub_82735EE0(ctx, base);
	// addi r3,r31,156
	ctx.r3.s64 = r31.s64 + 156;
	// bl 0x82735ee0
	ctx.lr = 0x82736224;
	sub_82735EE0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825953b0
	ctx.lr = 0x82736234;
	sub_825953B0(ctx, base);
	// lbz r9,145(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 145);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8273624c
	if (cr6.eq) goto loc_8273624C;
	// li r11,3
	r11.s64 = 3;
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// b 0x8273629c
	goto loc_8273629C;
loc_8273624C:
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// bl 0x8249e270
	ctx.lr = 0x82736254;
	sub_8249E270(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82736284
	if (!cr6.eq) goto loc_82736284;
	// lwz r11,92(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,316(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 316);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82736284
	if (!cr6.lt) goto loc_82736284;
	// li r11,2
	r11.s64 = 2;
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// b 0x8273629c
	goto loc_8273629C;
loc_82736284:
	// li r11,1
	r11.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825953b0
	ctx.lr = 0x8273629C;
	sub_825953B0(ctx, base);
loc_8273629C:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-17600(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -17600);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82736384
	if (cr6.eq) goto loc_82736384;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lbz r10,-17596(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -17596);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82736384
	if (cr6.eq) goto loc_82736384;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,64
	ctx.r4.s64 = r31.s64 + 64;
	// bl 0x82689ee8
	ctx.lr = 0x827362C8;
	sub_82689EE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273637c
	if (cr6.eq) goto loc_8273637C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r6,r11,24
	ctx.r6.u64 = r11.u32 & 0xFF;
	// rlwinm r4,r11,16,24,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f12,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// rlwinm r3,r11,24,24,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// fcfid f8,f12
	ctx.f8.f64 = double(ctx.f12.s64);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// lfs f0,-14596(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -14596);
	f0.f64 = double(temp.f32);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// lfs f13,15360(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 15360);
	ctx.f13.f64 = double(temp.f32);
	// frsp f5,f8
	ctx.f5.f64 = double(float(ctx.f8.f64));
	// lis r11,-1
	r11.s64 = -65536;
	// fcfid f6,f11
	ctx.f6.f64 = double(ctx.f11.s64);
	// fmuls f4,f7,f0
	ctx.f4.f64 = double(float(ctx.f7.f64 * f0.f64));
	// fmuls f2,f5,f0
	ctx.f2.f64 = double(float(ctx.f5.f64 * f0.f64));
	// frsp f3,f6
	ctx.f3.f64 = double(float(ctx.f6.f64));
	// fmuls f1,f4,f13
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
	// fmuls f12,f2,f13
	ctx.f12.f64 = double(float(ctx.f2.f64 * ctx.f13.f64));
	// fmuls f0,f3,f0
	f0.f64 = double(float(ctx.f3.f64 * f0.f64));
	// fctiwz f11,f1
	ctx.f11.s64 = (ctx.f1.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f9,f12
	ctx.f9.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fmuls f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 * ctx.f13.f64));
	// clrlwi r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	// fctiwz f8,f10
	ctx.f8.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwimi r11,r8,8,16,23
	r11.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (r11.u64 & 0xFFFFFFFFFFFF00FF);
	// or r6,r11,r7
	ctx.r6.u64 = r11.u64 | ctx.r7.u64;
	// rlwimi r9,r6,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// stw r9,148(r31)
	PPC_STORE_U32(r31.u32 + 148, ctx.r9.u32);
	// b 0x82736384
	goto loc_82736384;
loc_8273637C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
loc_82736384:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273639C"))) PPC_WEAK_FUNC(sub_8273639C);
PPC_FUNC_IMPL(__imp__sub_8273639C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827363A0"))) PPC_WEAK_FUNC(sub_827363A0);
PPC_FUNC_IMPL(__imp__sub_827363A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	// lbz r10,144(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 144);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplwi cr6,r10,8
	cr6.compare<uint32_t>(ctx.r10.u32, 8, xer);
	// bgtlr cr6
	if (cr6.gt) return;
	// lis r12,-32141
	r12.s64 = -2106392576;
	// addi r12,r12,25552
	r12.s64 = r12.s64 + 25552;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_827363F4;
	case 1:
		goto loc_82736404;
	case 2:
		goto loc_82736450;
	case 3:
		goto loc_82736450;
	case 4:
		goto loc_82736450;
	case 5:
		goto loc_82736414;
	case 6:
		goto loc_82736424;
	case 7:
		goto loc_82736434;
	case 8:
		goto loc_82736440;
	default:
		__builtin_unreachable();
	}
	// lwz r19,25588(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 25588);
	// lwz r19,25604(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 25604);
	// lwz r19,25680(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 25680);
	// lwz r19,25680(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 25680);
	// lwz r19,25680(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 25680);
	// lwz r19,25620(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 25620);
	// lwz r19,25636(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 25636);
	// lwz r19,25652(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 25652);
	// lwz r19,25664(r19)
	r19.u64 = PPC_LOAD_U32(r19.u32 + 25664);
loc_827363F4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x827361f0
	sub_827361F0(ctx, base);
	return;
loc_82736404:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x82737d68
	sub_82737D68(ctx, base);
	return;
loc_82736414:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x8272f9b8
	sub_8272F9B8(ctx, base);
	return;
loc_82736424:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x82737968
	sub_82737968(ctx, base);
	return;
loc_82736434:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-14592
	ctx.r3.s64 = r11.s64 + -14592;
	// b 0x821bd618
	sub_821BD618(ctx, base);
	return;
loc_82736440:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x827376e0
	sub_827376E0(ctx, base);
	return;
loc_82736450:
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82736454"))) PPC_WEAK_FUNC(sub_82736454);
PPC_FUNC_IMPL(__imp__sub_82736454) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82736458"))) PPC_WEAK_FUNC(sub_82736458);
PPC_FUNC_IMPL(__imp__sub_82736458) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,20284
	ctx.r3.s64 = r11.s64 + 20284;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82736464"))) PPC_WEAK_FUNC(sub_82736464);
PPC_FUNC_IMPL(__imp__sub_82736464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82736468"))) PPC_WEAK_FUNC(sub_82736468);
PPC_FUNC_IMPL(__imp__sub_82736468) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-21132(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21132);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82736474"))) PPC_WEAK_FUNC(sub_82736474);
PPC_FUNC_IMPL(__imp__sub_82736474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82736478"))) PPC_WEAK_FUNC(sub_82736478);
PPC_FUNC_IMPL(__imp__sub_82736478) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-14188
	ctx.r3.s64 = r11.s64 + -14188;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82736484"))) PPC_WEAK_FUNC(sub_82736484);
PPC_FUNC_IMPL(__imp__sub_82736484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82736488"))) PPC_WEAK_FUNC(sub_82736488);
PPC_FUNC_IMPL(__imp__sub_82736488) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-21128(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21128);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82736494"))) PPC_WEAK_FUNC(sub_82736494);
PPC_FUNC_IMPL(__imp__sub_82736494) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82736498"))) PPC_WEAK_FUNC(sub_82736498);
PPC_FUNC_IMPL(__imp__sub_82736498) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-14156
	ctx.r3.s64 = r11.s64 + -14156;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827364A4"))) PPC_WEAK_FUNC(sub_827364A4);
PPC_FUNC_IMPL(__imp__sub_827364A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827364A8"))) PPC_WEAK_FUNC(sub_827364A8);
PPC_FUNC_IMPL(__imp__sub_827364A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-21124(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21124);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827364B4"))) PPC_WEAK_FUNC(sub_827364B4);
PPC_FUNC_IMPL(__imp__sub_827364B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827364B8"))) PPC_WEAK_FUNC(sub_827364B8);
PPC_FUNC_IMPL(__imp__sub_827364B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r11,-14124
	ctx.r3.s64 = r11.s64 + -14124;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827364C4"))) PPC_WEAK_FUNC(sub_827364C4);
PPC_FUNC_IMPL(__imp__sub_827364C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827364C8"))) PPC_WEAK_FUNC(sub_827364C8);
PPC_FUNC_IMPL(__imp__sub_827364C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-21120(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21120);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827364D4"))) PPC_WEAK_FUNC(sub_827364D4);
PPC_FUNC_IMPL(__imp__sub_827364D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827364D8"))) PPC_WEAK_FUNC(sub_827364D8);
PPC_FUNC_IMPL(__imp__sub_827364D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x827364E0;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lbzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// addi r31,r11,17268
	r31.s64 = r11.s64 + 17268;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// beq cr6,0x8273652c
	if (cr6.eq) goto loc_8273652C;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82736548
	if (!cr6.gt) goto loc_82736548;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x8273653c
	goto loc_8273653C;
loc_8273652C:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82736548
	if (!cr6.gt) goto loc_82736548;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_8273653C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8273654c
	if (!cr6.eq) goto loc_8273654C;
loc_82736548:
	// li r11,0
	r11.s64 = 0;
loc_8273654C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82736634
	if (cr6.eq) goto loc_82736634;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3998
	ctx.lr = 0x82736560;
	sub_822A3998(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r31,r29,224
	r31.s64 = r29.s64 + 224;
	// lwz r30,1216(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 1216);
	// bl 0x822a3998
	ctx.lr = 0x82736578;
	sub_822A3998(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x8273657C;
	sub_822A8108(ctx, base);
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// lfs f0,224(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 224);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lfs f13,228(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 228);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,232(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 232);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f9,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f13,f10,f13
	ctx.f13.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fsubs f12,f9,f12
	ctx.f12.f64 = double(float(ctx.f9.f64 - ctx.f12.f64));
	// beq cr6,0x827365cc
	if (cr6.eq) goto loc_827365CC;
	// fmuls f11,f13,f13
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,31016(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f10,f12,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f11.f64));
	// fmadds f9,f0,f0,f10
	ctx.f9.f64 = double(float(f0.f64 * f0.f64 + ctx.f10.f64));
	// fcmpu cr6,f9,f13
	cr6.compare(ctx.f9.f64, ctx.f13.f64);
	// ble cr6,0x827365cc
	if (!cr6.gt) goto loc_827365CC;
	// li r30,0
	r30.s64 = 0;
loc_827365CC:
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82736634
	if (cr6.eq) goto loc_82736634;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v2,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// vsubfp128 v1,v63,v61
	simde_mm_store_ps(ctx.v1.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// bl 0x8247a588
	ctx.lr = 0x82736620;
	sub_8247A588(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82736634
	if (cr6.eq) goto loc_82736634;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
loc_82736634:
	// stw r30,512(r29)
	PPC_STORE_U32(r29.u32 + 512, r30.u32);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r4,r11,-14112
	ctx.r4.s64 = r11.s64 + -14112;
	// bl 0x8247a6a0
	ctx.lr = 0x8273664C;
	sub_8247A6A0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82736658"))) PPC_WEAK_FUNC(sub_82736658);
PPC_FUNC_IMPL(__imp__sub_82736658) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r4,20(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,136(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 136);
	// lwz r10,300(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 300);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lbz r9,-21548(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + -21548);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8273668c
	if (cr6.eq) goto loc_8273668C;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// b 0x8247a8d0
	sub_8247A8D0(ctx, base);
	return;
loc_8273668C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,136(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 136);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_827366A8"))) PPC_WEAK_FUNC(sub_827366A8);
PPC_FUNC_IMPL(__imp__sub_827366A8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827366AC"))) PPC_WEAK_FUNC(sub_827366AC);
PPC_FUNC_IMPL(__imp__sub_827366AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827366B0"))) PPC_WEAK_FUNC(sub_827366B0);
PPC_FUNC_IMPL(__imp__sub_827366B0) {
	PPC_FUNC_PROLOGUE();
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x82130000
	ctx.lr = 0x827366C8;
	sub_82130000(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82736730
	if (cr6.eq) goto loc_82736730;
	// lwz r10,612(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 612);
	// rlwinm r9,r10,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82736730
	if (cr6.eq) goto loc_82736730;
	// rlwinm r10,r10,28,29,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x7;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// addi r8,r10,109
	ctx.r8.s64 = ctx.r10.s64 + 109;
	// addi r7,r9,29952
	ctx.r7.s64 = ctx.r9.s64 + 29952;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f0,8(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfsx f12,r10,r11
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,-7176(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -7176);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f11,f0,f13,f12
	ctx.f11.f64 = double(float(-(f0.f64 * ctx.f13.f64 - ctx.f12.f64)));
	// lfs f0,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fsel f10,f11,f11,f0
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? ctx.f11.f64 : f0.f64;
	// fsel f9,f11,f11,f0
	ctx.f9.f64 = ctx.f11.f64 >= 0.0 ? ctx.f11.f64 : f0.f64;
	// fsubs f8,f10,f13
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fsel f7,f8,f13,f9
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? ctx.f13.f64 : ctx.f9.f64;
	// stfsx f7,r10,r11
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, temp.u32);
loc_82736730:
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

__attribute__((alias("__imp__sub_82736744"))) PPC_WEAK_FUNC(sub_82736744);
PPC_FUNC_IMPL(__imp__sub_82736744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82736748"))) PPC_WEAK_FUNC(sub_82736748);
PPC_FUNC_IMPL(__imp__sub_82736748) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// li r3,176
	ctx.r3.s64 = 176;
	// bl 0x82130528
	ctx.lr = 0x8273675C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82736778
	if (cr6.eq) goto loc_82736778;
	// bl 0x8275e7a8
	ctx.lr = 0x82736768;
	sub_8275E7A8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82736778:
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
}

__attribute__((alias("__imp__sub_8273678C"))) PPC_WEAK_FUNC(sub_8273678C);
PPC_FUNC_IMPL(__imp__sub_8273678C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82736790"))) PPC_WEAK_FUNC(sub_82736790);
PPC_FUNC_IMPL(__imp__sub_82736790) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827367bc
	if (cr6.eq) goto loc_827367BC;
	// bl 0x824905e0
	ctx.lr = 0x827367B0;
	sub_824905E0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-14224
	ctx.r10.s64 = r11.s64 + -14224;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_827367BC:
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

__attribute__((alias("__imp__sub_827367D0"))) PPC_WEAK_FUNC(sub_827367D0);
PPC_FUNC_IMPL(__imp__sub_827367D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// li r3,44
	ctx.r3.s64 = 44;
	// bl 0x82130528
	ctx.lr = 0x827367E4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82736800
	if (cr6.eq) goto loc_82736800;
	// bl 0x8275ed38
	ctx.lr = 0x827367F0;
	sub_8275ED38(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82736800:
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
}

__attribute__((alias("__imp__sub_82736814"))) PPC_WEAK_FUNC(sub_82736814);
PPC_FUNC_IMPL(__imp__sub_82736814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82736818"))) PPC_WEAK_FUNC(sub_82736818);
PPC_FUNC_IMPL(__imp__sub_82736818) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82736844
	if (cr6.eq) goto loc_82736844;
	// bl 0x824905e0
	ctx.lr = 0x82736838;
	sub_824905E0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-14204
	ctx.r10.s64 = r11.s64 + -14204;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_82736844:
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

__attribute__((alias("__imp__sub_82736858"))) PPC_WEAK_FUNC(sub_82736858);
PPC_FUNC_IMPL(__imp__sub_82736858) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x8273686C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82736888
	if (cr6.eq) goto loc_82736888;
	// bl 0x8275ede8
	ctx.lr = 0x82736878;
	sub_8275EDE8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82736888:
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
}

__attribute__((alias("__imp__sub_8273689C"))) PPC_WEAK_FUNC(sub_8273689C);
PPC_FUNC_IMPL(__imp__sub_8273689C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827368A0"))) PPC_WEAK_FUNC(sub_827368A0);
PPC_FUNC_IMPL(__imp__sub_827368A0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827368cc
	if (cr6.eq) goto loc_827368CC;
	// bl 0x824905e0
	ctx.lr = 0x827368C0;
	sub_824905E0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-14172
	ctx.r10.s64 = r11.s64 + -14172;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_827368CC:
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

__attribute__((alias("__imp__sub_827368E0"))) PPC_WEAK_FUNC(sub_827368E0);
PPC_FUNC_IMPL(__imp__sub_827368E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// li r3,112
	ctx.r3.s64 = 112;
	// bl 0x82130528
	ctx.lr = 0x827368F4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82736910
	if (cr6.eq) goto loc_82736910;
	// bl 0x8275eea0
	ctx.lr = 0x82736900;
	sub_8275EEA0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82736910:
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
}

__attribute__((alias("__imp__sub_82736924"))) PPC_WEAK_FUNC(sub_82736924);
PPC_FUNC_IMPL(__imp__sub_82736924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82736928"))) PPC_WEAK_FUNC(sub_82736928);
PPC_FUNC_IMPL(__imp__sub_82736928) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82736954
	if (cr6.eq) goto loc_82736954;
	// bl 0x824905e0
	ctx.lr = 0x82736948;
	sub_824905E0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-14140
	ctx.r10.s64 = r11.s64 + -14140;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_82736954:
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

__attribute__((alias("__imp__sub_82736968"))) PPC_WEAK_FUNC(sub_82736968);
PPC_FUNC_IMPL(__imp__sub_82736968) {
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
	// bl 0x821d2028
	ctx.lr = 0x82736988;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827369a0
	if (cr6.eq) goto loc_827369A0;
	// bl 0x82130588
	ctx.lr = 0x8273699C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_827369A0:
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

__attribute__((alias("__imp__sub_827369B8"))) PPC_WEAK_FUNC(sub_827369B8);
PPC_FUNC_IMPL(__imp__sub_827369B8) {
	PPC_FUNC_PROLOGUE();
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82736a44
	if (cr6.eq) goto loc_82736A44;
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// lwz r3,256(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 256);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827369f8
	if (cr6.eq) goto loc_827369F8;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r4,r11,-14072
	ctx.r4.s64 = r11.s64 + -14072;
	// bl 0x8247bc80
	ctx.lr = 0x827369F0;
	sub_8247BC80(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x82736a18
	if (!cr6.lt) goto loc_82736A18;
loc_827369F8:
	// lwz r11,612(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 612);
	// rlwinm r10,r11,0,29,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// stw r10,612(r31)
	PPC_STORE_U32(r31.u32 + 612, ctx.r10.u32);
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
loc_82736A18:
	// lwz r11,612(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 612);
	// rlwinm r10,r3,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r9,r3,109
	ctx.r9.s64 = ctx.r3.s64 + 109;
	// rlwinm r8,r11,0,28,24
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF8F;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// or r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 | ctx.r10.u64;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r4,r6,8
	ctx.r4.u64 = ctx.r6.u64 | 8;
	// lfs f0,7444(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r4,612(r31)
	PPC_STORE_U32(r31.u32 + 612, ctx.r4.u32);
	// stfsx f0,r5,r31
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + r31.u32, temp.u32);
loc_82736A44:
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

__attribute__((alias("__imp__sub_82736A58"))) PPC_WEAK_FUNC(sub_82736A58);
PPC_FUNC_IMPL(__imp__sub_82736A58) {
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
	// beq cr6,0x82736ad0
	if (cr6.eq) goto loc_82736AD0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82736a94
	if (cr6.eq) goto loc_82736A94;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82736A90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82736a9c
	goto loc_82736A9C;
loc_82736A94:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,-7004
	ctx.r3.s64 = r11.s64 + -7004;
loc_82736A9C:
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r4,r11,-29148
	ctx.r4.s64 = r11.s64 + -29148;
	// bl 0x823d9188
	ctx.lr = 0x82736AA8;
	sub_823D9188(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82736ad0
	if (cr6.eq) goto loc_82736AD0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
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
loc_82736AD0:
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

__attribute__((alias("__imp__sub_82736AE8"))) PPC_WEAK_FUNC(sub_82736AE8);
PPC_FUNC_IMPL(__imp__sub_82736AE8) {
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
	// beq cr6,0x82736b60
	if (cr6.eq) goto loc_82736B60;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82736b24
	if (cr6.eq) goto loc_82736B24;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82736B20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82736b2c
	goto loc_82736B2C;
loc_82736B24:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,-7004
	ctx.r3.s64 = r11.s64 + -7004;
loc_82736B2C:
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r4,r11,-28760
	ctx.r4.s64 = r11.s64 + -28760;
	// bl 0x823d9188
	ctx.lr = 0x82736B38;
	sub_823D9188(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82736b60
	if (cr6.eq) goto loc_82736B60;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
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
loc_82736B60:
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

__attribute__((alias("__imp__sub_82736B78"))) PPC_WEAK_FUNC(sub_82736B78);
PPC_FUNC_IMPL(__imp__sub_82736B78) {
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
	// beq cr6,0x82736bf0
	if (cr6.eq) goto loc_82736BF0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82736bb4
	if (cr6.eq) goto loc_82736BB4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82736BB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82736bbc
	goto loc_82736BBC;
loc_82736BB4:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,-7004
	ctx.r3.s64 = r11.s64 + -7004;
loc_82736BBC:
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r4,r11,-29220
	ctx.r4.s64 = r11.s64 + -29220;
	// bl 0x823d9188
	ctx.lr = 0x82736BC8;
	sub_823D9188(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82736bf0
	if (cr6.eq) goto loc_82736BF0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
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
loc_82736BF0:
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

__attribute__((alias("__imp__sub_82736C08"))) PPC_WEAK_FUNC(sub_82736C08);
PPC_FUNC_IMPL(__imp__sub_82736C08) {
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
	// lis r31,-32125
	r31.s64 = -2105344000;
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82736c3c
	if (cr6.eq) goto loc_82736C3C;
	// bl 0x821bbea8
	ctx.lr = 0x82736C3C;
	sub_821BBEA8(ctx, base);
loc_82736C3C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-21120(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -21120);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82736c54
	if (cr6.eq) goto loc_82736C54;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x82736C54;
	sub_821BFA90(ctx, base);
loc_82736C54:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82736c60
	if (cr6.eq) goto loc_82736C60;
	// bl 0x821bbf00
	ctx.lr = 0x82736C60;
	sub_821BBF00(ctx, base);
loc_82736C60:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82736c7c
	if (cr6.eq) goto loc_82736C7C;
	// bl 0x821bbea8
	ctx.lr = 0x82736C7C;
	sub_821BBEA8(ctx, base);
loc_82736C7C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-21124(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -21124);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82736c94
	if (cr6.eq) goto loc_82736C94;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x82736C94;
	sub_821BFA90(ctx, base);
loc_82736C94:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82736ca0
	if (cr6.eq) goto loc_82736CA0;
	// bl 0x821bbf00
	ctx.lr = 0x82736CA0;
	sub_821BBF00(ctx, base);
loc_82736CA0:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82736cbc
	if (cr6.eq) goto loc_82736CBC;
	// bl 0x821bbea8
	ctx.lr = 0x82736CBC;
	sub_821BBEA8(ctx, base);
loc_82736CBC:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-21128(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -21128);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82736cd4
	if (cr6.eq) goto loc_82736CD4;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x82736CD4;
	sub_821BFA90(ctx, base);
loc_82736CD4:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82736ce0
	if (cr6.eq) goto loc_82736CE0;
	// bl 0x821bbf00
	ctx.lr = 0x82736CE0;
	sub_821BBF00(ctx, base);
loc_82736CE0:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82736cfc
	if (cr6.eq) goto loc_82736CFC;
	// bl 0x821bbea8
	ctx.lr = 0x82736CFC;
	sub_821BBEA8(ctx, base);
loc_82736CFC:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-21132(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -21132);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82736d14
	if (cr6.eq) goto loc_82736D14;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x82736D14;
	sub_821BFA90(ctx, base);
loc_82736D14:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82736d20
	if (cr6.eq) goto loc_82736D20;
	// bl 0x821bbf00
	ctx.lr = 0x82736D20;
	sub_821BBF00(ctx, base);
loc_82736D20:
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

__attribute__((alias("__imp__sub_82736D38"))) PPC_WEAK_FUNC(sub_82736D38);
PPC_FUNC_IMPL(__imp__sub_82736D38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82736D40;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwz r4,100(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 100);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x824a5b20
	ctx.lr = 0x82736D5C;
	sub_824A5B20(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lwz r4,108(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 108);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x824a5b20
	ctx.lr = 0x82736D70;
	sub_824A5B20(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r4,116(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 116);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x824a5b20
	ctx.lr = 0x82736D84;
	sub_824A5B20(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82736db0
	if (cr6.eq) goto loc_82736DB0;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,116(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 116);
	// bl 0x824a5b00
	ctx.lr = 0x82736D9C;
	sub_824A5B00(ctx, base);
	// bl 0x82736a58
	ctx.lr = 0x82736DA0;
	sub_82736A58(ctx, base);
	// lfs f0,172(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 172);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82736ef4
	if (cr6.lt) goto loc_82736EF4;
loc_82736DB0:
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r30,r27,48
	r30.s64 = r27.s64 + 48;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-4916(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -4916);
	// bl 0x824804d0
	ctx.lr = 0x82736DCC;
	sub_824804D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// bne cr6,0x82736e0c
	if (!cr6.eq) goto loc_82736E0C;
	// lwz r3,-4916(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -4916);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82736DF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-4916(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -4916);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824804d0
	ctx.lr = 0x82736E08;
	sub_824804D0(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
loc_82736E0C:
	// lwz r30,20(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82736ef4
	if (cr6.eq) goto loc_82736EF4;
	// addi r4,r27,32
	ctx.r4.s64 = r27.s64 + 32;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8247a178
	ctx.lr = 0x82736E24;
	sub_8247A178(ctx, base);
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// lwz r3,256(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 256);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82736e78
	if (cr6.eq) goto loc_82736E78;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r4,r11,-14112
	ctx.r4.s64 = r11.s64 + -14112;
	// bl 0x8247bc80
	ctx.lr = 0x82736E40;
	sub_8247BC80(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82736e78
	if (cr6.lt) goto loc_82736E78;
	// lis r11,-32141
	r11.s64 = -2106392576;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,25816
	ctx.r4.s64 = r11.s64 + 25816;
	// bl 0x822ed130
	ctx.lr = 0x82736E58;
	sub_822ED130(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r9,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r9.u32);
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r8,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r8.u32);
	// lwz r7,12(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r7,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r7.u32);
loc_82736E78:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82736ea8
	if (cr6.eq) goto loc_82736EA8;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,100(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 100);
	// bl 0x824a5b00
	ctx.lr = 0x82736E90;
	sub_824A5B00(ctx, base);
	// bl 0x82736ae8
	ctx.lr = 0x82736E94;
	sub_82736AE8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8247a128
	ctx.lr = 0x82736EA4;
	sub_8247A128(ctx, base);
	// b 0x82736ee0
	goto loc_82736EE0;
loc_82736EA8:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82736ef4
	if (cr6.eq) goto loc_82736EF4;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,108(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 108);
	// bl 0x824a5b00
	ctx.lr = 0x82736EC0;
	sub_824A5B00(ctx, base);
	// bl 0x82736b78
	ctx.lr = 0x82736EC4;
	sub_82736B78(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8247a020
	ctx.lr = 0x82736EE0;
	sub_8247A020(ctx, base);
loc_82736EE0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827369b8
	ctx.lr = 0x82736EEC;
	sub_827369B8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8247a838
	ctx.lr = 0x82736EF4;
	sub_8247A838(ctx, base);
loc_82736EF4:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82736EFC"))) PPC_WEAK_FUNC(sub_82736EFC);
PPC_FUNC_IMPL(__imp__sub_82736EFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82736F00"))) PPC_WEAK_FUNC(sub_82736F00);
PPC_FUNC_IMPL(__imp__sub_82736F00) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32141
	r11.s64 = -2106392576;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,26440
	ctx.r5.s64 = r11.s64 + 26440;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x82736F30;
	sub_821D4268(ctx, base);
	// lis r10,-32211
	ctx.r10.s64 = -2110980096;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,16176
	ctx.r8.s64 = ctx.r10.s64 + 16176;
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lis r5,-32141
	ctx.r5.s64 = -2106392576;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r5,26512
	ctx.r5.s64 = ctx.r5.s64 + 26512;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r9.u32);
	// bl 0x821d4268
	ctx.lr = 0x82736F80;
	sub_821D4268(ctx, base);
	// lis r8,-32182
	ctx.r8.s64 = -2109079552;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r8,-30160
	ctx.r6.s64 = ctx.r8.s64 + -30160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r5,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r5.u32);
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r4,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r4.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82736FC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82736FD8"))) PPC_WEAK_FUNC(sub_82736FD8);
PPC_FUNC_IMPL(__imp__sub_82736FD8) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32141
	r11.s64 = -2106392576;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,26576
	ctx.r5.s64 = r11.s64 + 26576;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x82737008;
	sub_821D4268(ctx, base);
	// lis r10,-32211
	ctx.r10.s64 = -2110980096;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,16176
	ctx.r8.s64 = ctx.r10.s64 + 16176;
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lis r5,-32141
	ctx.r5.s64 = -2106392576;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r5,26648
	ctx.r5.s64 = ctx.r5.s64 + 26648;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r9.u32);
	// bl 0x821d4268
	ctx.lr = 0x82737058;
	sub_821D4268(ctx, base);
	// lis r8,-32182
	ctx.r8.s64 = -2109079552;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r8,-30160
	ctx.r6.s64 = ctx.r8.s64 + -30160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r5,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r5.u32);
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r4,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r4.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8273709C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827370B0"))) PPC_WEAK_FUNC(sub_827370B0);
PPC_FUNC_IMPL(__imp__sub_827370B0) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32141
	r11.s64 = -2106392576;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,26712
	ctx.r5.s64 = r11.s64 + 26712;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827370E0;
	sub_821D4268(ctx, base);
	// lis r10,-32211
	ctx.r10.s64 = -2110980096;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,16176
	ctx.r8.s64 = ctx.r10.s64 + 16176;
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lis r5,-32141
	ctx.r5.s64 = -2106392576;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r5,26784
	ctx.r5.s64 = ctx.r5.s64 + 26784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r9.u32);
	// bl 0x821d4268
	ctx.lr = 0x82737130;
	sub_821D4268(ctx, base);
	// lis r8,-32182
	ctx.r8.s64 = -2109079552;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r8,-30160
	ctx.r6.s64 = ctx.r8.s64 + -30160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r5,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r5.u32);
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r4,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r4.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82737174;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82737188"))) PPC_WEAK_FUNC(sub_82737188);
PPC_FUNC_IMPL(__imp__sub_82737188) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32141
	r11.s64 = -2106392576;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,26848
	ctx.r5.s64 = r11.s64 + 26848;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x827371B8;
	sub_821D4268(ctx, base);
	// lis r10,-32211
	ctx.r10.s64 = -2110980096;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,16176
	ctx.r8.s64 = ctx.r10.s64 + 16176;
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// lis r5,-32141
	ctx.r5.s64 = -2106392576;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r5,26920
	ctx.r5.s64 = ctx.r5.s64 + 26920;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r9,4(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r10.u32);
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r9,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r9.u32);
	// bl 0x821d4268
	ctx.lr = 0x82737208;
	sub_821D4268(ctx, base);
	// lis r8,-32182
	ctx.r8.s64 = -2109079552;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r8,-30160
	ctx.r6.s64 = ctx.r8.s64 + -30160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// lwz r4,12(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,8(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r8,20(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r5,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r5.u32);
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r4,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r4.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8273724C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82737260"))) PPC_WEAK_FUNC(sub_82737260);
PPC_FUNC_IMPL(__imp__sub_82737260) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82737268;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32120
	r30.s64 = -2105016320;
	// li r3,120
	ctx.r3.s64 = 120;
	// lwz r28,-27428(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// bl 0x82130528
	ctx.lr = 0x8273727C;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8273729c
	if (cr6.eq) goto loc_8273729C;
	// bl 0x8275e9e0
	ctx.lr = 0x8273728C;
	sub_8275E9E0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-14096
	ctx.r10.s64 = r11.s64 + -14096;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x827372a0
	goto loc_827372A0;
loc_8273729C:
	// li r31,0
	r31.s64 = 0;
loc_827372A0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82736f00
	ctx.lr = 0x827372A8;
	sub_82736F00(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r29,r11,-18228
	r29.s64 = r11.s64 + -18228;
	// addi r5,r10,20284
	ctx.r5.s64 = ctx.r10.s64 + 20284;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82490a08
	ctx.lr = 0x827372C8;
	sub_82490A08(ctx, base);
	// li r3,124
	ctx.r3.s64 = 124;
	// lwz r28,-27428(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// bl 0x82130528
	ctx.lr = 0x827372D4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827372e8
	if (cr6.eq) goto loc_827372E8;
	// bl 0x8275f3f8
	ctx.lr = 0x827372E0;
	sub_8275F3F8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x827372ec
	goto loc_827372EC;
loc_827372E8:
	// li r31,0
	r31.s64 = 0;
loc_827372EC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82736fd8
	ctx.lr = 0x827372F4;
	sub_82736FD8(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r5,r11,20424
	ctx.r5.s64 = r11.s64 + 20424;
	// addi r4,r10,-14064
	ctx.r4.s64 = ctx.r10.s64 + -14064;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82490a08
	ctx.lr = 0x82737310;
	sub_82490A08(ctx, base);
	// li r3,124
	ctx.r3.s64 = 124;
	// lwz r28,-27428(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// bl 0x82130528
	ctx.lr = 0x8273731C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82737330
	if (cr6.eq) goto loc_82737330;
	// bl 0x8275f140
	ctx.lr = 0x82737328;
	sub_8275F140(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x82737334
	goto loc_82737334;
loc_82737330:
	// li r31,0
	r31.s64 = 0;
loc_82737334:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827370b0
	ctx.lr = 0x8273733C;
	sub_827370B0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r11,20512
	ctx.r5.s64 = r11.s64 + 20512;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82490a08
	ctx.lr = 0x82737354;
	sub_82490A08(ctx, base);
	// li r3,104
	ctx.r3.s64 = 104;
	// lwz r30,-27428(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// bl 0x82130528
	ctx.lr = 0x82737360;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82737374
	if (cr6.eq) goto loc_82737374;
	// bl 0x8275f260
	ctx.lr = 0x8273736C;
	sub_8275F260(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x82737378
	goto loc_82737378;
loc_82737374:
	// li r31,0
	r31.s64 = 0;
loc_82737378:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82737188
	ctx.lr = 0x82737380;
	sub_82737188(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r11,20568
	ctx.r5.s64 = r11.s64 + 20568;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82490a08
	ctx.lr = 0x82737398;
	sub_82490A08(ctx, base);
	// lis r31,-32125
	r31.s64 = -2105344000;
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827373b8
	if (cr6.eq) goto loc_827373B8;
	// bl 0x821bbea8
	ctx.lr = 0x827373B8;
	sub_821BBEA8(ctx, base);
loc_827373B8:
	// bl 0x8275ebd0
	ctx.lr = 0x827373BC;
	sub_8275EBD0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x827373c8
	if (cr6.eq) goto loc_827373C8;
	// bl 0x821bbf00
	ctx.lr = 0x827373C8;
	sub_821BBF00(ctx, base);
loc_827373C8:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827373e4
	if (cr6.eq) goto loc_827373E4;
	// bl 0x821bbea8
	ctx.lr = 0x827373E4;
	sub_821BBEA8(ctx, base);
loc_827373E4:
	// bl 0x8275fee0
	ctx.lr = 0x827373E8;
	sub_8275FEE0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x827373f4
	if (cr6.eq) goto loc_827373F4;
	// bl 0x821bbf00
	ctx.lr = 0x827373F4;
	sub_821BBF00(ctx, base);
loc_827373F4:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82737410
	if (cr6.eq) goto loc_82737410;
	// bl 0x821bbea8
	ctx.lr = 0x82737410;
	sub_821BBEA8(ctx, base);
loc_82737410:
	// bl 0x8275f440
	ctx.lr = 0x82737414;
	sub_8275F440(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82737420
	if (cr6.eq) goto loc_82737420;
	// bl 0x821bbf00
	ctx.lr = 0x82737420;
	sub_821BBF00(ctx, base);
loc_82737420:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273743c
	if (cr6.eq) goto loc_8273743C;
	// bl 0x821bbea8
	ctx.lr = 0x8273743C;
	sub_821BBEA8(ctx, base);
loc_8273743C:
	// bl 0x8275f5a0
	ctx.lr = 0x82737440;
	sub_8275F5A0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8273744c
	if (cr6.eq) goto loc_8273744C;
	// bl 0x821bbf00
	ctx.lr = 0x8273744C;
	sub_821BBF00(ctx, base);
loc_8273744C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82737454"))) PPC_WEAK_FUNC(sub_82737454);
PPC_FUNC_IMPL(__imp__sub_82737454) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82737458"))) PPC_WEAK_FUNC(sub_82737458);
PPC_FUNC_IMPL(__imp__sub_82737458) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8275da68
	ctx.lr = 0x82737470;
	sub_8275DA68(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r9,r11,-13736
	ctx.r9.s64 = r11.s64 + -13736;
	// addi r8,r10,-13768
	ctx.r8.s64 = ctx.r10.s64 + -13768;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_827374A0"))) PPC_WEAK_FUNC(sub_827374A0);
PPC_FUNC_IMPL(__imp__sub_827374A0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-100
	ctx.r3.s64 = ctx.r3.s64 + -100;
	// b 0x827374a8
	sub_827374A8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827374A8"))) PPC_WEAK_FUNC(sub_827374A8);
PPC_FUNC_IMPL(__imp__sub_827374A8) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r3,r31,100
	ctx.r3.s64 = r31.s64 + 100;
	// bne cr6,0x827374d4
	if (!cr6.eq) goto loc_827374D4;
	// li r3,0
	ctx.r3.s64 = 0;
loc_827374D4:
	// bl 0x82548b50
	ctx.lr = 0x827374D8;
	sub_82548B50(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// clrlwi r10,r30,31
	ctx.r10.u64 = r30.u32 & 0x1;
	// addi r9,r11,-15292
	ctx.r9.s64 = r11.s64 + -15292;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x827374fc
	if (cr6.eq) goto loc_827374FC;
	// bl 0x82130588
	ctx.lr = 0x827374F8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_827374FC:
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

__attribute__((alias("__imp__sub_82737514"))) PPC_WEAK_FUNC(sub_82737514);
PPC_FUNC_IMPL(__imp__sub_82737514) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82737518"))) PPC_WEAK_FUNC(sub_82737518);
PPC_FUNC_IMPL(__imp__sub_82737518) {
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
	// beq cr6,0x82737590
	if (cr6.eq) goto loc_82737590;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82737554
	if (cr6.eq) goto loc_82737554;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82737550;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8273755c
	goto loc_8273755C;
loc_82737554:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,-7004
	ctx.r3.s64 = r11.s64 + -7004;
loc_8273755C:
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r4,r11,-29000
	ctx.r4.s64 = r11.s64 + -29000;
	// bl 0x823d9188
	ctx.lr = 0x82737568;
	sub_823D9188(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82737590
	if (cr6.eq) goto loc_82737590;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
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
loc_82737590:
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

__attribute__((alias("__imp__sub_827375A8"))) PPC_WEAK_FUNC(sub_827375A8);
PPC_FUNC_IMPL(__imp__sub_827375A8) {
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
	// beq cr6,0x82737620
	if (cr6.eq) goto loc_82737620;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x827375e4
	if (cr6.eq) goto loc_827375E4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827375E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x827375ec
	goto loc_827375EC;
loc_827375E4:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,-7004
	ctx.r3.s64 = r11.s64 + -7004;
loc_827375EC:
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r4,r11,18408
	ctx.r4.s64 = r11.s64 + 18408;
	// bl 0x823d9188
	ctx.lr = 0x827375F8;
	sub_823D9188(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82737620
	if (cr6.eq) goto loc_82737620;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
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
loc_82737620:
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

__attribute__((alias("__imp__sub_82737638"))) PPC_WEAK_FUNC(sub_82737638);
PPC_FUNC_IMPL(__imp__sub_82737638) {
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
	ctx.lr = 0x82737640;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r4,112(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x824a5b20
	ctx.lr = 0x8273765C;
	sub_824A5B20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827376d4
	if (cr6.eq) goto loc_827376D4;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r4,112(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// bl 0x824a5b00
	ctx.lr = 0x82737674;
	sub_824A5B00(ctx, base);
	// bl 0x82737518
	ctx.lr = 0x82737678;
	sub_82737518(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r4,108(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r29,0(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x824a5b20
	ctx.lr = 0x8273768C;
	sub_824A5B20(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827376a8
	if (cr6.eq) goto loc_827376A8;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r4,108(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// bl 0x824a5b00
	ctx.lr = 0x827376A4;
	sub_824A5B00(ctx, base);
	// bl 0x827375a8
	ctx.lr = 0x827376A8;
	sub_827375A8(ctx, base);
loc_827376A8:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827376BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x827376C4;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8272f908
	ctx.lr = 0x827376D4;
	sub_8272F908(ctx, base);
loc_827376D4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827376DC"))) PPC_WEAK_FUNC(sub_827376DC);
PPC_FUNC_IMPL(__imp__sub_827376DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827376E0"))) PPC_WEAK_FUNC(sub_827376E0);
PPC_FUNC_IMPL(__imp__sub_827376E0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x827361f0
	ctx.lr = 0x827376F8;
	sub_827361F0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-18804
	ctx.r10.s64 = r11.s64 + -18804;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_8273771C"))) PPC_WEAK_FUNC(sub_8273771C);
PPC_FUNC_IMPL(__imp__sub_8273771C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82737720"))) PPC_WEAK_FUNC(sub_82737720);
PPC_FUNC_IMPL(__imp__sub_82737720) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// stw r4,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r4.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,16(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// rlwinm r10,r11,0,30,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stw r10,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273773C"))) PPC_WEAK_FUNC(sub_8273773C);
PPC_FUNC_IMPL(__imp__sub_8273773C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82737740"))) PPC_WEAK_FUNC(sub_82737740);
PPC_FUNC_IMPL(__imp__sub_82737740) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v63{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82735918
	ctx.lr = 0x8273775C;
	sub_82735918(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x82737768;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82737878
	if (cr6.eq) goto loc_82737878;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8273777C;
	sub_822A39C8(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x82737780;
	sub_822A8108(ctx, base);
	// li r11,48
	r11.s64 = 48;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	f0.f64 = double(temp.f32);
	// lfs f13,72(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lfs f12,64(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	ctx.f12.f64 = double(temp.f32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f0,f9
	ctx.f8.f64 = double(float(f0.f64 - ctx.f9.f64));
	// fsubs f7,f13,f11
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// lfs f0,-6836(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -6836);
	f0.f64 = double(temp.f32);
	// fmuls f6,f8,f8
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// lfs f13,-6828(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -6828);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f5,f12,f10
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// fmuls f4,f0,f0
	ctx.f4.f64 = double(float(f0.f64 * f0.f64));
	// fmadds f3,f7,f7,f6
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fmadds f0,f5,f5,f3
	f0.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fcmpu cr6,f0,f4
	cr6.compare(f0.f64, ctx.f4.f64);
	// bgt cr6,0x82737834
	if (cr6.gt) goto loc_82737834;
	// fmuls f12,f13,f13
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// blt cr6,0x82737834
	if (cr6.lt) goto loc_82737834;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f13,-6832(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6832);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82737878
	if (!cr6.lt) goto loc_82737878;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f13,-6824(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6824);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82737878
	if (!cr6.gt) goto loc_82737878;
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82737878
	if (cr6.eq) goto loc_82737878;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r11,29,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82737878
	if (!cr6.eq) goto loc_82737878;
	// bl 0x824a8e40
	ctx.lr = 0x82737830;
	sub_824A8E40(ctx, base);
	// b 0x82737878
	goto loc_82737878;
loc_82737834:
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82737878
	if (cr6.eq) goto loc_82737878;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r11,29,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82737878
	if (cr6.eq) goto loc_82737878;
	// fmuls f13,f13,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lis r31,-32111
	r31.s64 = -2104426496;
	// li r11,1
	r11.s64 = 1;
	// lbz r30,-21548(r31)
	r30.u64 = PPC_LOAD_U8(r31.u32 + -21548);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8273786c
	if (cr6.lt) goto loc_8273786C;
	// li r11,0
	r11.s64 = 0;
loc_8273786C:
	// stb r11,-21548(r31)
	PPC_STORE_U8(r31.u32 + -21548, r11.u8);
	// bl 0x824a8f08
	ctx.lr = 0x82737874;
	sub_824A8F08(ctx, base);
	// stb r30,-21548(r31)
	PPC_STORE_U8(r31.u32 + -21548, r30.u8);
loc_82737878:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_82737890"))) PPC_WEAK_FUNC(sub_82737890);
PPC_FUNC_IMPL(__imp__sub_82737890) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, r11.u32);
	// b 0x82735438
	sub_82735438(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8273789C"))) PPC_WEAK_FUNC(sub_8273789C);
PPC_FUNC_IMPL(__imp__sub_8273789C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827378A0"))) PPC_WEAK_FUNC(sub_827378A0);
PPC_FUNC_IMPL(__imp__sub_827378A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// lwz r11,80(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// lwz r3,128(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// bl 0x82257af0
	ctx.lr = 0x827378CC;
	sub_82257AF0(ctx, base);
	// stw r3,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r3.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,80(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// lfs f1,31016(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31016);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827378F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,80(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// bl 0x82332a00
	ctx.lr = 0x827378F8;
	sub_82332A00(ctx, base);
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

__attribute__((alias("__imp__sub_82737910"))) PPC_WEAK_FUNC(sub_82737910);
PPC_FUNC_IMPL(__imp__sub_82737910) {
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
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82735fb0
	ctx.lr = 0x82737930;
	sub_82735FB0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r10,10
	ctx.r10.s64 = 10;
	// addi r9,r11,-13100
	ctx.r9.s64 = r11.s64 + -13100;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r10,144(r31)
	PPC_STORE_U8(r31.u32 + 144, ctx.r10.u8);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_82737964"))) PPC_WEAK_FUNC(sub_82737964);
PPC_FUNC_IMPL(__imp__sub_82737964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82737968"))) PPC_WEAK_FUNC(sub_82737968);
PPC_FUNC_IMPL(__imp__sub_82737968) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x827361f0
	ctx.lr = 0x82737980;
	sub_827361F0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-13100
	ctx.r10.s64 = r11.s64 + -13100;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_827379A4"))) PPC_WEAK_FUNC(sub_827379A4);
PPC_FUNC_IMPL(__imp__sub_827379A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827379A8"))) PPC_WEAK_FUNC(sub_827379A8);
PPC_FUNC_IMPL(__imp__sub_827379A8) {
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
	// bl 0x82735748
	ctx.lr = 0x827379C0;
	sub_82735748(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r4,256
	ctx.r4.s64 = 256;
	// bl 0x8258e620
	ctx.lr = 0x827379D0;
	sub_8258E620(ctx, base);
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

__attribute__((alias("__imp__sub_827379E4"))) PPC_WEAK_FUNC(sub_827379E4);
PPC_FUNC_IMPL(__imp__sub_827379E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827379E8"))) PPC_WEAK_FUNC(sub_827379E8);
PPC_FUNC_IMPL(__imp__sub_827379E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91ec
	ctx.lr = 0x827379F0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x827352c8
	ctx.lr = 0x82737A00;
	sub_827352C8(ctx, base);
	// lwz r11,160(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 160);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82737acc
	if (!cr6.eq) goto loc_82737ACC;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82737acc
	if (cr6.eq) goto loc_82737ACC;
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82737acc
	if (!cr6.gt) goto loc_82737ACC;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// li r27,0
	r27.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// addi r29,r11,24092
	r29.s64 = r11.s64 + 24092;
	// addi r28,r10,24064
	r28.s64 = ctx.r10.s64 + 24064;
loc_82737A3C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r9,160(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// lwz r3,4(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x823dedd8
	ctx.lr = 0x82737A60;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82737a94
	if (!cr6.eq) goto loc_82737A94;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r9,160(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x823dedd8
	ctx.lr = 0x82737A8C;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82737aa0
	if (cr6.eq) goto loc_82737AA0;
loc_82737A94:
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82737ac0
	if (!cr6.eq) goto loc_82737AC0;
loc_82737AA0:
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x82737a3c
	if (cr6.lt) goto loc_82737A3C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82737AC0:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x827378a0
	ctx.lr = 0x82737ACC;
	sub_827378A0(ctx, base);
loc_82737ACC:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82737AD8"))) PPC_WEAK_FUNC(sub_82737AD8);
PPC_FUNC_IMPL(__imp__sub_82737AD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	ctx.lr = 0x82737AE0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r23,r8
	r23.u64 = ctx.r8.u64;
	// bl 0x82735310
	ctx.lr = 0x82737AF4;
	sub_82735310(ctx, base);
	// lwz r11,160(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82737bc8
	if (!cr6.eq) goto loc_82737BC8;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x82737b14
	if (cr6.eq) goto loc_82737B14;
	// lwz r25,0(r24)
	r25.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// b 0x82737b18
	goto loc_82737B18;
loc_82737B14:
	// li r25,1
	r25.s64 = 1;
loc_82737B18:
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x82737bc8
	if (!cr6.gt) goto loc_82737BC8;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r29,r24,16
	r29.s64 = r24.s64 + 16;
	// addi r27,r11,24092
	r27.s64 = r11.s64 + 24092;
	// addi r26,r10,24064
	r26.s64 = ctx.r10.s64 + 24064;
loc_82737B38:
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// bne cr6,0x82737b48
	if (!cr6.eq) goto loc_82737B48;
	// mr r11,r23
	r11.u64 = r23.u64;
loc_82737B48:
	// lwz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 192);
	// lwz r3,196(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// cmplw cr6,r10,r30
	cr6.compare<uint32_t>(ctx.r10.u32, r30.u32, xer);
	// beq cr6,0x82737b64
	if (cr6.eq) goto loc_82737B64;
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// bne cr6,0x82737ba0
	if (!cr6.eq) goto loc_82737BA0;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
loc_82737B64:
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82737B78;
	sub_823DEDD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82737ba0
	if (cr6.eq) goto loc_82737BA0;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82737ba0
	if (cr6.eq) goto loc_82737BA0;
	// bl 0x82331d28
	ctx.lr = 0x82737B94;
	sub_82331D28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82737bbc
	if (!cr6.eq) goto loc_82737BBC;
loc_82737BA0:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,208
	r29.s64 = r29.s64 + 208;
	// cmpw cr6,r28,r25
	cr6.compare<int32_t>(r28.s32, r25.s32, xer);
	// blt cr6,0x82737b38
	if (cr6.lt) goto loc_82737B38;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
loc_82737BBC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827378a0
	ctx.lr = 0x82737BC8;
	sub_827378A0(ctx, base);
loc_82737BC8:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82737BD4"))) PPC_WEAK_FUNC(sub_82737BD4);
PPC_FUNC_IMPL(__imp__sub_82737BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82737BD8"))) PPC_WEAK_FUNC(sub_82737BD8);
PPC_FUNC_IMPL(__imp__sub_82737BD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCVRegister v56{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-15860
	ctx.r4.s64 = r11.s64 + -15860;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82735660
	ctx.lr = 0x82737BFC;
	sub_82735660(ctx, base);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// li r9,160
	ctx.r9.s64 = 160;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,-12468
	ctx.r4.s64 = ctx.r8.s64 + -12468;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82735660
	ctx.lr = 0x82737C20;
	sub_82735660(ctx, base);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// li r6,176
	ctx.r6.s64 = 176;
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,-3016
	ctx.r4.s64 = ctx.r5.s64 + -3016;
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v62,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82735660
	ctx.lr = 0x82737C44;
	sub_82735660(ctx, base);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r10,192
	ctx.r10.s64 = 192;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,-12476
	ctx.r4.s64 = ctx.r9.s64 + -12476;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v61,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82735660
	ctx.lr = 0x82737C68;
	sub_82735660(ctx, base);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// li r7,208
	ctx.r7.s64 = 208;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,-3008
	ctx.r4.s64 = ctx.r6.s64 + -3008;
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v60,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82735660
	ctx.lr = 0x82737C8C;
	sub_82735660(ctx, base);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r10,224
	ctx.r10.s64 = 224;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,-12484
	ctx.r4.s64 = ctx.r9.s64 + -12484;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v59,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82735660
	ctx.lr = 0x82737CB0;
	sub_82735660(ctx, base);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// li r7,240
	ctx.r7.s64 = 240;
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,-12492
	ctx.r4.s64 = ctx.r6.s64 + -12492;
	// lvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v58,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82735660
	ctx.lr = 0x82737CD4;
	sub_82735660(ctx, base);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r10,256
	ctx.r10.s64 = 256;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,-12500
	ctx.r4.s64 = ctx.r9.s64 + -12500;
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v57,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82735660
	ctx.lr = 0x82737CF8;
	sub_82735660(ctx, base);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// li r7,272
	ctx.r7.s64 = 272;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v56,r0,r8
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8248a510
	ctx.lr = 0x82737D10;
	sub_8248A510(ctx, base);
	// lwz r6,180(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// lwz r3,8(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82737d50
	if (cr6.eq) goto loc_82737D50;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r4,r11,-12520
	ctx.r4.s64 = r11.s64 + -12520;
	// bl 0x82192680
	ctx.lr = 0x82737D2C;
	sub_82192680(ctx, base);
	// stw r3,288(r31)
	PPC_STORE_U32(r31.u32 + 288, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82737d50
	if (cr6.eq) goto loc_82737D50;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-12532
	ctx.r4.s64 = r11.s64 + -12532;
	// bl 0x8218a568
	ctx.lr = 0x82737D4C;
	sub_8218A568(ctx, base);
	// stw r3,292(r31)
	PPC_STORE_U32(r31.u32 + 292, ctx.r3.u32);
loc_82737D50:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82737D64"))) PPC_WEAK_FUNC(sub_82737D64);
PPC_FUNC_IMPL(__imp__sub_82737D64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82737D68"))) PPC_WEAK_FUNC(sub_82737D68);
PPC_FUNC_IMPL(__imp__sub_82737D68) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x827361f0
	ctx.lr = 0x82737D80;
	sub_827361F0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-18532
	ctx.r9.s64 = r11.s64 + -18532;
	// stw r10,296(r31)
	PPC_STORE_U32(r31.u32 + 296, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_82737DAC"))) PPC_WEAK_FUNC(sub_82737DAC);
PPC_FUNC_IMPL(__imp__sub_82737DAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82737DB0"))) PPC_WEAK_FUNC(sub_82737DB0);
PPC_FUNC_IMPL(__imp__sub_82737DB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stb r11,189(r3)
	PPC_STORE_U8(ctx.r3.u32 + 189, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82737DBC"))) PPC_WEAK_FUNC(sub_82737DBC);
PPC_FUNC_IMPL(__imp__sub_82737DBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82737DC0"))) PPC_WEAK_FUNC(sub_82737DC0);
PPC_FUNC_IMPL(__imp__sub_82737DC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v56{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// li r5,16
	ctx.r5.s64 = 16;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,48
	ctx.r6.s64 = 48;
	// li r7,64
	ctx.r7.s64 = 64;
	// li r8,96
	ctx.r8.s64 = 96;
	// li r9,112
	ctx.r9.s64 = 112;
	// lvx128 v62,r4,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,128
	ctx.r10.s64 = 128;
	// stvx128 v62,r3,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,144
	r11.s64 = 144;
	// lfs f0,32(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	f0.f64 = double(temp.f32);
	// stfs f0,32(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// lfs f13,36(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,36(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lvx128 v61,r4,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r4,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r3,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,80(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// lvx128 v59,r4,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r4,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r4,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r4,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,160(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 160);
	// lbz r10,160(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 160);
	// rlwimi r11,r10,0,24,24
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0x80) | (r11.u64 & 0xFFFFFFFFFFFFFF7F);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// stb r9,160(r3)
	PPC_STORE_U8(ctx.r3.u32 + 160, ctx.r9.u8);
	// lbz r7,160(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 160);
	// rlwimi r8,r7,0,25,25
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 0) & 0x40) | (ctx.r8.u64 & 0xFFFFFFFFFFFFFFBF);
	// clrlwi r6,r8,24
	ctx.r6.u64 = ctx.r8.u32 & 0xFF;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// stb r6,160(r3)
	PPC_STORE_U8(ctx.r3.u32 + 160, ctx.r6.u8);
	// lbz r4,160(r4)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + 160);
	// rlwimi r5,r4,0,26,26
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r4.u32, 0) & 0x20) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFFDF);
	// stb r5,160(r3)
	PPC_STORE_U8(ctx.r3.u32 + 160, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82737E70"))) PPC_WEAK_FUNC(sub_82737E70);
PPC_FUNC_IMPL(__imp__sub_82737E70) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,104(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 104);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82737E78"))) PPC_WEAK_FUNC(sub_82737E78);
PPC_FUNC_IMPL(__imp__sub_82737E78) {
	PPC_FUNC_PROLOGUE();
	// stb r4,104(r3)
	PPC_STORE_U8(ctx.r3.u32 + 104, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82737E80"))) PPC_WEAK_FUNC(sub_82737E80);
PPC_FUNC_IMPL(__imp__sub_82737E80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r7,r9,-18980
	ctx.r7.s64 = ctx.r9.s64 + -18980;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// addi r6,r8,-19568
	ctx.r6.s64 = ctx.r8.s64 + -19568;
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// lis r5,-32243
	ctx.r5.s64 = -2113077248;
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, r11.u32);
	// addi r8,r4,-18972
	ctx.r8.s64 = ctx.r4.s64 + -18972;
	// stw r7,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r7.u32);
	// stfs f0,68(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stb r11,79(r3)
	PPC_STORE_U8(ctx.r3.u32 + 79, r11.u8);
	// stfs f0,72(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stw r11,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, r11.u32);
	// addi r9,r5,-11844
	ctx.r9.s64 = ctx.r5.s64 + -11844;
	// sth r11,84(r3)
	PPC_STORE_U16(ctx.r3.u32 + 84, r11.u16);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// sth r10,76(r3)
	PPC_STORE_U16(ctx.r3.u32 + 76, ctx.r10.u16);
	// stb r10,78(r3)
	PPC_STORE_U8(ctx.r3.u32 + 78, ctx.r10.u8);
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// ori r6,r4,1
	ctx.r6.u64 = ctx.r4.u64 | 1;
	// stw r6,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r6.u32);
	// stw r11,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, r11.u32);
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, r11.u32);
	// stb r11,104(r3)
	PPC_STORE_U8(ctx.r3.u32 + 104, r11.u8);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, r11.u32);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, r11.u32);
	// stw r11,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, r11.u32);
	// stw r8,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, ctx.r8.u32);
	// stw r11,136(r3)
	PPC_STORE_U32(ctx.r3.u32 + 136, r11.u32);
	// stw r11,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, r11.u32);
	// stw r7,132(r3)
	PPC_STORE_U32(ctx.r3.u32 + 132, ctx.r7.u32);
	// stfs f0,144(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 144, temp.u32);
	// stb r11,155(r3)
	PPC_STORE_U8(ctx.r3.u32 + 155, r11.u8);
	// stfs f0,148(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 148, temp.u32);
	// sth r10,152(r3)
	PPC_STORE_U16(ctx.r3.u32 + 152, ctx.r10.u16);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// stb r10,154(r3)
	PPC_STORE_U8(ctx.r3.u32 + 154, ctx.r10.u8);
	// lfs f0,14192(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14192);
	f0.f64 = double(temp.f32);
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// ori r10,r4,2048
	ctx.r10.u64 = ctx.r4.u64 | 2048;
	// addi r11,r3,112
	r11.s64 = ctx.r3.s64 + 112;
	// stfs f0,156(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 156, temp.u32);
	// addi r11,r3,124
	r11.s64 = ctx.r3.s64 + 124;
	// stw r3,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r3.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82737F64"))) PPC_WEAK_FUNC(sub_82737F64);
PPC_FUNC_IMPL(__imp__sub_82737F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82737F68"))) PPC_WEAK_FUNC(sub_82737F68);
PPC_FUNC_IMPL(__imp__sub_82737F68) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,124
	ctx.r3.s64 = ctx.r3.s64 + 124;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82737F70"))) PPC_WEAK_FUNC(sub_82737F70);
PPC_FUNC_IMPL(__imp__sub_82737F70) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,124
	ctx.r3.s64 = ctx.r3.s64 + 124;
	// b 0x82585f70
	sub_82585F70(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82737F78"))) PPC_WEAK_FUNC(sub_82737F78);
PPC_FUNC_IMPL(__imp__sub_82737F78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,156(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 156, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82737F80"))) PPC_WEAK_FUNC(sub_82737F80);
PPC_FUNC_IMPL(__imp__sub_82737F80) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r31,124
	ctx.r3.s64 = r31.s64 + 124;
	// addi r10,r11,-11844
	ctx.r10.s64 = r11.s64 + -11844;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82586680
	ctx.lr = 0x82737FA8;
	sub_82586680(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r7,r9,-19540
	ctx.r7.s64 = ctx.r9.s64 + -19540;
	// addi r6,r8,-19568
	ctx.r6.s64 = ctx.r8.s64 + -19568;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// stw r6,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r6.u32);
	// bl 0x82586680
	ctx.lr = 0x82737FC8;
	sub_82586680(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,-19596
	ctx.r4.s64 = ctx.r5.s64 + -19596;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// bl 0x821d2028
	ctx.lr = 0x82737FDC;
	sub_821D2028(ctx, base);
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

__attribute__((alias("__imp__sub_82737FF0"))) PPC_WEAK_FUNC(sub_82737FF0);
PPC_FUNC_IMPL(__imp__sub_82737FF0) {
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
	// bl 0x82737f80
	ctx.lr = 0x82738010;
	sub_82737F80(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82738028
	if (cr6.eq) goto loc_82738028;
	// bl 0x82130588
	ctx.lr = 0x82738024;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82738028:
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

__attribute__((alias("__imp__sub_82738040"))) PPC_WEAK_FUNC(sub_82738040);
PPC_FUNC_IMPL(__imp__sub_82738040) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82738048;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r11,0
	r11.s64 = 0;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r7,r9,-18980
	ctx.r7.s64 = ctx.r9.s64 + -18980;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r6,r8,-19568
	ctx.r6.s64 = ctx.r8.s64 + -19568;
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// lis r5,-32243
	ctx.r5.s64 = -2113077248;
	// stw r7,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r7.u32);
	// li r7,112
	ctx.r7.s64 = 112;
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// addi r8,r5,-11740
	ctx.r8.s64 = ctx.r5.s64 + -11740;
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, r11.u32);
	// stfs f0,68(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// sth r10,76(r3)
	PPC_STORE_U16(ctx.r3.u32 + 76, ctx.r10.u16);
	// stfs f0,72(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stb r10,78(r3)
	PPC_STORE_U8(ctx.r3.u32 + 78, ctx.r10.u8);
	// addi r10,r3,128
	ctx.r10.s64 = ctx.r3.s64 + 128;
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
	// li r5,144
	ctx.r5.s64 = 144;
	// stb r11,79(r3)
	PPC_STORE_U8(ctx.r3.u32 + 79, r11.u8);
	// li r4,96
	ctx.r4.s64 = 96;
	// stw r11,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, r11.u32);
	// li r6,128
	ctx.r6.s64 = 128;
	// sth r11,84(r3)
	PPC_STORE_U16(ctx.r3.u32 + 84, r11.u16);
	// li r31,16
	r31.s64 = 16;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// ori r9,r9,1
	ctx.r9.u64 = ctx.r9.u64 | 1;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// li r30,48
	r30.s64 = 48;
	// stw r11,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, r11.u32);
	// li r29,64
	r29.s64 = 64;
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, r11.u32);
	// lis r28,-32256
	r28.s64 = -2113929216;
	// stb r11,104(r3)
	PPC_STORE_U8(ctx.r3.u32 + 104, r11.u8);
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// addi r9,r3,112
	ctx.r9.s64 = ctx.r3.s64 + 112;
	// stw r11,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, r11.u32);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, r11.u32);
	// stvx128 v63,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r8,288(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 288);
	// stvx128 v63,r10,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// clrlwi r7,r8,27
	ctx.r7.u64 = ctx.r8.u32 & 0x1F;
	// stfs f0,208(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 208, temp.u32);
	// stb r7,288(r3)
	PPC_STORE_U8(ctx.r3.u32 + 288, ctx.r7.u8);
	// stfs f0,160(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 160, temp.u32);
	// stfs f0,164(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 164, temp.u32);
	// stvx128 v63,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,4(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// ori r5,r6,4096
	ctx.r5.u64 = ctx.r6.u64 | 4096;
	// lfs f13,14192(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,304(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 304, temp.u32);
	// stw r3,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r3.u32);
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82738154"))) PPC_WEAK_FUNC(sub_82738154);
PPC_FUNC_IMPL(__imp__sub_82738154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82738158"))) PPC_WEAK_FUNC(sub_82738158);
PPC_FUNC_IMPL(__imp__sub_82738158) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// b 0x8279cc10
	sub_8279CC10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82738160"))) PPC_WEAK_FUNC(sub_82738160);
PPC_FUNC_IMPL(__imp__sub_82738160) {
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
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8279c720
	ctx.lr = 0x8273817C;
	sub_8279C720(ctx, base);
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

__attribute__((alias("__imp__sub_82738194"))) PPC_WEAK_FUNC(sub_82738194);
PPC_FUNC_IMPL(__imp__sub_82738194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82738198"))) PPC_WEAK_FUNC(sub_82738198);
PPC_FUNC_IMPL(__imp__sub_82738198) {
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
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8279caa8
	ctx.lr = 0x827381B4;
	sub_8279CAA8(ctx, base);
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

__attribute__((alias("__imp__sub_827381CC"))) PPC_WEAK_FUNC(sub_827381CC);
PPC_FUNC_IMPL(__imp__sub_827381CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827381D0"))) PPC_WEAK_FUNC(sub_827381D0);
PPC_FUNC_IMPL(__imp__sub_827381D0) {
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
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8279caf8
	ctx.lr = 0x827381EC;
	sub_8279CAF8(ctx, base);
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

__attribute__((alias("__imp__sub_82738204"))) PPC_WEAK_FUNC(sub_82738204);
PPC_FUNC_IMPL(__imp__sub_82738204) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82738208"))) PPC_WEAK_FUNC(sub_82738208);
PPC_FUNC_IMPL(__imp__sub_82738208) {
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
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8279c8c8
	ctx.lr = 0x82738224;
	sub_8279C8C8(ctx, base);
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

__attribute__((alias("__imp__sub_8273823C"))) PPC_WEAK_FUNC(sub_8273823C);
PPC_FUNC_IMPL(__imp__sub_8273823C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82738240"))) PPC_WEAK_FUNC(sub_82738240);
PPC_FUNC_IMPL(__imp__sub_82738240) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// b 0x8279cb58
	sub_8279CB58(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82738248"))) PPC_WEAK_FUNC(sub_82738248);
PPC_FUNC_IMPL(__imp__sub_82738248) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// b 0x8279cb60
	sub_8279CB60(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82738250"))) PPC_WEAK_FUNC(sub_82738250);
PPC_FUNC_IMPL(__imp__sub_82738250) {
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
	// addi r4,r4,128
	ctx.r4.s64 = ctx.r4.s64 + 128;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8279cc70
	ctx.lr = 0x8273826C;
	sub_8279CC70(ctx, base);
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

__attribute__((alias("__imp__sub_82738284"))) PPC_WEAK_FUNC(sub_82738284);
PPC_FUNC_IMPL(__imp__sub_82738284) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82738288"))) PPC_WEAK_FUNC(sub_82738288);
PPC_FUNC_IMPL(__imp__sub_82738288) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// b 0x8279cb68
	sub_8279CB68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82738290"))) PPC_WEAK_FUNC(sub_82738290);
PPC_FUNC_IMPL(__imp__sub_82738290) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,304(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 304, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82738298"))) PPC_WEAK_FUNC(sub_82738298);
PPC_FUNC_IMPL(__imp__sub_82738298) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,304(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 304);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827382A0"))) PPC_WEAK_FUNC(sub_827382A0);
PPC_FUNC_IMPL(__imp__sub_827382A0) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,-19540
	ctx.r9.s64 = r11.s64 + -19540;
	// addi r8,r10,-19568
	ctx.r8.s64 = ctx.r10.s64 + -19568;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// stw r8,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r8.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82586680
	ctx.lr = 0x827382DC;
	sub_82586680(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,-19596
	ctx.r6.s64 = ctx.r7.s64 + -19596;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// bl 0x821d2028
	ctx.lr = 0x827382F0;
	sub_821D2028(ctx, base);
	// clrlwi r5,r30,31
	ctx.r5.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82738308
	if (cr6.eq) goto loc_82738308;
	// bl 0x82130588
	ctx.lr = 0x82738304;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82738308:
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

__attribute__((alias("__imp__sub_82738320"))) PPC_WEAK_FUNC(sub_82738320);
PPC_FUNC_IMPL(__imp__sub_82738320) {
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
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273834c
	if (cr6.eq) goto loc_8273834C;
	// li r11,1
	r11.s64 = 1;
	// stb r11,164(r31)
	PPC_STORE_U8(r31.u32 + 164, r11.u8);
loc_8273834C:
	// lwz r4,148(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82738380
	if (cr6.eq) goto loc_82738380;
	// lwz r3,-10012(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10012);
	// bl 0x826d5390
	ctx.lr = 0x82738364;
	sub_826D5390(ctx, base);
	// stw r3,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82738380
	if (!cr6.eq) goto loc_82738380;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lwz r4,148(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// addi r3,r11,-11640
	ctx.r3.s64 = r11.s64 + -11640;
	// bl 0x82130000
	ctx.lr = 0x82738380;
	sub_82130000(ctx, base);
loc_82738380:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,-10012(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10012);
	// addis r4,r11,6
	ctx.r4.s64 = r11.s64 + 393216;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r4,r4,16704
	ctx.r4.s64 = ctx.r4.s64 + 16704;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827383A0;
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

__attribute__((alias("__imp__sub_827383B8"))) PPC_WEAK_FUNC(sub_827383B8);
PPC_FUNC_IMPL(__imp__sub_827383B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x827383C0;
	// addi r31,r1,-160
	r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lwz r11,180(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 180);
	// lhz r25,36(r24)
	r25.u64 = PPC_LOAD_U16(r24.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827383e0
	if (cr6.eq) goto loc_827383E0;
	// addi r25,r25,-1
	r25.s64 = r25.s64 + -1;
loc_827383E0:
	// addi r11,r25,-1
	r11.s64 = r25.s64 + -1;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bge cr6,0x827383f4
	if (!cr6.lt) goto loc_827383F4;
	// li r28,1
	r28.s64 = 1;
	// b 0x82738404
	goto loc_82738404;
loc_827383F4:
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r28,3
	r28.s64 = 3;
	// bgt cr6,0x82738404
	if (cr6.gt) goto loc_82738404;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_82738404:
	// add r11,r28,r25
	r11.u64 = r28.u64 + r25.u64;
	// addi r26,r11,-1
	r26.s64 = r11.s64 + -1;
	// rlwinm r11,r26,2,0,29
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// neg r10,r11
	ctx.r10.s64 = -r11.s64;
	// rlwinm r12,r10,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x8273841C;
	sub_823DBFF4(ctx, base);
	// lwz r9,0(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// stwux r9,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r1.u32 = ea;
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x82738458
	if (!cr6.gt) goto loc_82738458;
	// mr r11,r27
	r11.u64 = r27.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82738454
	if (cr6.eq) goto loc_82738454;
	// mtctr r28
	ctr.u64 = r28.u64;
loc_82738448:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82738448
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82738448;
loc_82738454:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82738458:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// subf r10,r28,r26
	ctx.r10.s64 = r26.s64 - r28.s64;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// lfs f13,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// bge cr6,0x82738494
	if (!cr6.lt) goto loc_82738494;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r11,r10
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// add r9,r9,r27
	ctx.r9.u64 = ctx.r9.u64 + r27.u64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
loc_82738480:
	// stfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x82738480
	if (!cr0.eq) goto loc_82738480;
loc_82738494:
	// cmpw cr6,r11,r26
	cr6.compare<int32_t>(r11.s32, r26.s32, xer);
	// bge cr6,0x827384c0
	if (!cr6.lt) goto loc_827384C0;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r11,r26
	r11.s64 = r26.s64 - r11.s64;
	// add r4,r10,r27
	ctx.r4.u64 = ctx.r10.u64 + r27.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r4,4
	ctx.r3.s64 = ctx.r4.s64 + 4;
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// stfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// rlwinm r5,r10,0,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// bl 0x823dadd8
	ctx.lr = 0x827384C0;
	sub_823DADD8(ctx, base);
loc_827384C0:
	// rlwinm r11,r25,4,0,27
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 4) & 0xFFFFFFF0;
	// neg r10,r11
	ctx.r10.s64 = -r11.s64;
	// rlwinm r12,r10,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x827384D0;
	sub_823DBFF4(ctx, base);
	// lwz r9,0(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// stwux r9,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r1.u32 = ea;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x82738504
	if (!cr6.gt) goto loc_82738504;
	// li r11,0
	r11.s64 = 0;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
loc_827384EC:
	// lwz r9,32(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lvx128 v63,r9,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x827384ec
	if (!cr0.eq) goto loc_827384EC;
loc_82738504:
	// li r3,160
	ctx.r3.s64 = 160;
	// bl 0x82130528
	ctx.lr = 0x8273850C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82738520
	if (cr6.eq) goto loc_82738520;
	// bl 0x82737e80
	ctx.lr = 0x82738518;
	sub_82737E80(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x82738524
	goto loc_82738524;
loc_82738520:
	// li r30,0
	r30.s64 = 0;
loc_82738524:
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r30,124
	ctx.r3.s64 = r30.s64 + 124;
	// bl 0x825867f8
	ctx.lr = 0x82738544;
	sub_825867F8(ctx, base);
	// stw r30,176(r24)
	PPC_STORE_U32(r24.u32 + 176, r30.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r31,160
	ctx.r1.s64 = r31.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82738554"))) PPC_WEAK_FUNC(sub_82738554);
PPC_FUNC_IMPL(__imp__sub_82738554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82738558"))) PPC_WEAK_FUNC(sub_82738558);
PPC_FUNC_IMPL(__imp__sub_82738558) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v55{};
	PPCVRegister v56{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82738560;
	// stfd f30,-120(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -120, f30.u64);
	// stfd f31,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, f31.u64);
	// stwu r1,-1104(r1)
	ea = -1104 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r7,144(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 144);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82738590
	if (!cr6.eq) goto loc_82738590;
loc_8273857C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,1104
	ctx.r1.s64 = ctx.r1.s64 + 1104;
	// lfd f30,-120(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f31,-112(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
loc_82738590:
	// li r9,112
	ctx.r9.s64 = 112;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lhz r11,20(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 20);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r10,32(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// addi r29,r28,48
	r29.s64 = r28.s64 + 48;
	// addi r5,r11,-2
	ctx.r5.s64 = r11.s64 + -2;
	// rotlwi r8,r11,4
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 4);
	// lvx128 v62,r28,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r9,r5,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// vsubfp128 v61,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r31,r10,r9
	r31.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r30,r8,-16
	r30.s64 = ctx.r8.s64 + -16;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x827385f4
	if (!cr6.gt) goto loc_827385F4;
	// addi r11,r11,-3
	r11.s64 = r11.s64 + -3;
	// lwz r10,16(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// rlwinm r6,r11,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v60,r10,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r6,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v58,v60,v59
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v59.f32)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_827385F4:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lbz r5,256(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 256);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lbz r8,608(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 608);
	// lis r3,-32122
	ctx.r3.s64 = -2105147392;
	// lbz r10,432(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 432);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r25,r1,192
	r25.s64 = ctx.r1.s64 + 192;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r9,r3,2528
	ctx.r9.s64 = ctx.r3.s64 + 2528;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r6,r11,2240
	ctx.r6.s64 = r11.s64 + 2240;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v57,v62,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// vrsqrtefp128 v56,v57
	simde_mm_store_ps(v56.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v57.f32))));
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// vor128 v12,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// addi r4,r11,-31648
	ctx.r4.s64 = r11.s64 + -31648;
	// addi r3,r6,-31664
	ctx.r3.s64 = ctx.r6.s64 + -31664;
	// addi r24,r1,208
	r24.s64 = ctx.r1.s64 + 208;
	// addi r23,r1,224
	r23.s64 = ctx.r1.s64 + 224;
	// addi r22,r1,240
	r22.s64 = ctx.r1.s64 + 240;
	// stvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v13,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r25,r1,96
	r25.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r24,r1,112
	r24.s64 = ctx.r1.s64 + 112;
	// addi r20,r1,144
	r20.s64 = ctx.r1.s64 + 144;
	// stfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// vcmpeqfp128 v11,v56,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v10,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// stvx128 v63,r0,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r23,r1,160
	r23.s64 = ctx.r1.s64 + 160;
	// stfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r6,r1,384
	ctx.r6.s64 = ctx.r1.s64 + 384;
	// stvx128 v63,r0,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,400
	ctx.r4.s64 = ctx.r1.s64 + 400;
	// addi r3,r1,416
	ctx.r3.s64 = ctx.r1.s64 + 416;
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r9,r1,368
	ctx.r9.s64 = ctx.r1.s64 + 368;
	// stvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r27,r1,272
	r27.s64 = ctx.r1.s64 + 272;
	// stvx128 v63,r0,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r26,r1,288
	r26.s64 = ctx.r1.s64 + 288;
	// stvx128 v63,r0,r20
	simde_mm_store_si128((simde__m128i*)(base + ((r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r22,r1,320
	r22.s64 = ctx.r1.s64 + 320;
	// stvx128 v63,r0,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// clrlwi r5,r5,27
	ctx.r5.u64 = ctx.r5.u32 & 0x1F;
	// lis r21,-32255
	r21.s64 = -2113863680;
	// stb r5,256(r1)
	PPC_STORE_U8(ctx.r1.u32 + 256, ctx.r5.u8);
	// clrlwi r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// rlwinm r8,r8,0,26,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// lfs f31,-31400(r21)
	temp.u32 = PPC_LOAD_U32(r21.u32 + -31400);
	f31.f64 = double(temp.f32);
	// vmulfp128 v9,v0,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v60,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v55,v62,v6
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f30,160(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 160);
	f30.f64 = double(temp.f32);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r7,784(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 784);
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r6,960(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 960);
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// clrlwi r5,r7,24
	ctx.r5.u64 = ctx.r7.u32 & 0xFF;
	// stfs f0,352(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 352, temp.u32);
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// stvx128 v63,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r5,r5,0,26,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stfs f0,304(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// stvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,308(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// addi r11,r1,544
	r11.s64 = ctx.r1.s64 + 544;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// addi r9,r1,560
	ctx.r9.s64 = ctx.r1.s64 + 560;
	// addi r7,r1,576
	ctx.r7.s64 = ctx.r1.s64 + 576;
	// stvx128 v63,r0,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,592
	ctx.r6.s64 = ctx.r1.s64 + 592;
	// stfs f0,528(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 528, temp.u32);
	// addi r27,r1,448
	r27.s64 = ctx.r1.s64 + 448;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// stfs f0,480(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 480, temp.u32);
	// addi r26,r1,496
	r26.s64 = ctx.r1.s64 + 496;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,512
	r11.s64 = ctx.r1.s64 + 512;
	// stfs f0,484(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 484, temp.u32);
	// addi r25,r1,720
	r25.s64 = ctx.r1.s64 + 720;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,736
	ctx.r9.s64 = ctx.r1.s64 + 736;
	// stfs f0,704(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 704, temp.u32);
	// addi r24,r1,752
	r24.s64 = ctx.r1.s64 + 752;
	// addi r23,r1,768
	r23.s64 = ctx.r1.s64 + 768;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,624
	ctx.r7.s64 = ctx.r1.s64 + 624;
	// stfs f0,656(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 656, temp.u32);
	// addi r22,r1,640
	r22.s64 = ctx.r1.s64 + 640;
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,672
	ctx.r6.s64 = ctx.r1.s64 + 672;
	// stfs f0,660(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 660, temp.u32);
	// addi r21,r1,688
	r21.s64 = ctx.r1.s64 + 688;
	// stvx128 v63,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r27,r1,896
	r27.s64 = ctx.r1.s64 + 896;
	// stfs f0,880(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 880, temp.u32);
	// addi r20,r1,912
	r20.s64 = ctx.r1.s64 + 912;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,928
	ctx.r3.s64 = ctx.r1.s64 + 928;
	// stvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r26,r1,944
	r26.s64 = ctx.r1.s64 + 944;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,800
	r11.s64 = ctx.r1.s64 + 800;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// stvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// addi r5,r1,816
	ctx.r5.s64 = ctx.r1.s64 + 816;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r25,r1,848
	r25.s64 = ctx.r1.s64 + 848;
	// stvx128 v63,r0,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r24,r1,864
	r24.s64 = ctx.r1.s64 + 864;
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// clrlwi r7,r9,25
	ctx.r7.u64 = ctx.r9.u32 & 0x7F;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// clrlwi r6,r8,25
	ctx.r6.u64 = ctx.r8.u32 & 0x7F;
	// stvx128 v63,r0,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r7,r7,0,27,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stvx128 v63,r0,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r6,r6,0,27,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stvx128 v63,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// clrlwi r10,r10,27
	ctx.r10.u64 = ctx.r10.u32 & 0x1F;
	// stvx128 v63,r0,r20
	simde_mm_store_si128((simde__m128i*)(base + ((r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// clrlwi r3,r4,27
	ctx.r3.u64 = ctx.r4.u32 & 0x1F;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r7,608(r1)
	PPC_STORE_U8(ctx.r1.u32 + 608, ctx.r7.u8);
	// stb r6,784(r1)
	PPC_STORE_U8(ctx.r1.u32 + 784, ctx.r6.u8);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r10,432(r1)
	PPC_STORE_U8(ctx.r1.u32 + 432, ctx.r10.u8);
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,832(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 832, temp.u32);
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// stfs f0,836(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 836, temp.u32);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// stvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,0
	ctx.r6.s64 = 0;
	// stvx128 v63,r0,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r3,960(r1)
	PPC_STORE_U8(ctx.r1.u32 + 960, ctx.r3.u8);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x8279e518
	ctx.lr = 0x82738878;
	sub_8279E518(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,448
	ctx.r3.s64 = ctx.r1.s64 + 448;
	// bl 0x8279e518
	ctx.lr = 0x8273889C;
	sub_8279E518(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,624
	ctx.r3.s64 = ctx.r1.s64 + 624;
	// bl 0x8279e518
	ctx.lr = 0x827388C0;
	sub_8279E518(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,800
	ctx.r3.s64 = ctx.r1.s64 + 800;
	// bl 0x8279e518
	ctx.lr = 0x827388E4;
	sub_8279E518(ctx, base);
	// addi r31,r1,272
	r31.s64 = ctx.r1.s64 + 272;
	// li r30,4
	r30.s64 = 4;
loc_827388EC:
	// lbz r11,160(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 160);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273891c
	if (cr6.eq) goto loc_8273891C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8279cb68
	ctx.lr = 0x82738904;
	sub_8279CB68(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bge cr6,0x8273891c
	if (!cr6.lt) goto loc_8273891C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82737dc0
	ctx.lr = 0x8273891C;
	sub_82737DC0(ctx, base);
loc_8273891C:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,176
	r31.s64 = r31.s64 + 176;
	// bne 0x827388ec
	if (!cr0.eq) goto loc_827388EC;
	// lbz r11,256(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 256);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273857c
	if (cr6.eq) goto loc_8273857C;
	// li r3,320
	ctx.r3.s64 = 320;
	// bl 0x82130528
	ctx.lr = 0x82738940;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82738954
	if (cr6.eq) goto loc_82738954;
	// bl 0x82738040
	ctx.lr = 0x8273894C;
	sub_82738040(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x82738958
	goto loc_82738958;
loc_82738954:
	// li r31,0
	r31.s64 = 0;
loc_82738958:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// bl 0x82737dc0
	ctx.lr = 0x82738964;
	sub_82737DC0(ctx, base);
	// stw r31,180(r28)
	PPC_STORE_U32(r28.u32 + 180, r31.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1104
	ctx.r1.s64 = ctx.r1.s64 + 1104;
	// lfd f30,-120(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f31,-112(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8273897C"))) PPC_WEAK_FUNC(sub_8273897C);
PPC_FUNC_IMPL(__imp__sub_8273897C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82738980"))) PPC_WEAK_FUNC(sub_82738980);
PPC_FUNC_IMPL(__imp__sub_82738980) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// lwz r3,176(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r3,180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 180);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lfs f0,68(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 68);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// lwz r3,64(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827389B8"))) PPC_WEAK_FUNC(sub_827389B8);
PPC_FUNC_IMPL(__imp__sub_827389B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827389e8
	if (cr6.eq) goto loc_827389E8;
	// lwz r3,180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 180);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827389fc
	if (!cr6.eq) goto loc_827389FC;
loc_827389E8:
	// lwz r10,180(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 180);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827389fc
	if (!cr6.eq) goto loc_827389FC;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_827389FC:
	// lfs f0,68(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 68);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// lwz r3,64(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82738A0C"))) PPC_WEAK_FUNC(sub_82738A0C);
PPC_FUNC_IMPL(__imp__sub_82738A0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82738A10"))) PPC_WEAK_FUNC(sub_82738A10);
PPC_FUNC_IMPL(__imp__sub_82738A10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -24, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r9,176(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82738a40
	if (cr6.eq) goto loc_82738A40;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// b 0x82738a50
	goto loc_82738A50;
loc_82738A40:
	// lwz r10,180(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 180);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82738a50
	if (!cr6.eq) goto loc_82738A50;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
loc_82738A50:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82738a6c
	if (cr6.eq) goto loc_82738A6C;
	// lwz r31,180(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 180);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82738a80
	if (!cr6.eq) goto loc_82738A80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82738a7c
	if (!cr6.eq) goto loc_82738A7C;
loc_82738A6C:
	// lwz r9,180(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 180);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82738a80
	if (cr6.eq) goto loc_82738A80;
loc_82738A7C:
	// lwz r31,64(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 64);
loc_82738A80:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82738ab8
	if (cr6.eq) goto loc_82738AB8;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r9,r11,0,19,20
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1800;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82738ab8
	if (!cr6.eq) goto loc_82738AB8;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82738AB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82738AB8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82738af0
	if (cr6.eq) goto loc_82738AF0;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r10,r11,0,19,20
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1800;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82738af0
	if (!cr6.eq) goto loc_82738AF0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82738AF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82738AF0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82738B08"))) PPC_WEAK_FUNC(sub_82738B08);
PPC_FUNC_IMPL(__imp__sub_82738B08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,173(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 173);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82738b2c
	if (cr6.eq) goto loc_82738B2C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// addi r3,r11,8536
	ctx.r3.s64 = r11.s64 + 8536;
	// b 0x826da8d0
	sub_826DA8D0(ctx, base);
	return;
loc_82738B2C:
	// lbz r11,172(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 172);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82738b50
	if (cr6.eq) goto loc_82738B50;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// addi r3,r11,8536
	ctx.r3.s64 = r11.s64 + 8536;
	// b 0x826da8d0
	sub_826DA8D0(ctx, base);
	return;
loc_82738B50:
	// lwz r3,144(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82738B58"))) PPC_WEAK_FUNC(sub_82738B58);
PPC_FUNC_IMPL(__imp__sub_82738B58) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,-11592
	ctx.r10.s64 = r11.s64 + -11592;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r9,38(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 38);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82738b8c
	if (cr6.eq) goto loc_82738B8C;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x82130588
	ctx.lr = 0x82738B8C;
	sub_82130588(ctx, base);
loc_82738B8C:
	// lhz r11,30(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 30);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82738ba0
	if (cr6.eq) goto loc_82738BA0;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x82738BA0;
	sub_82130588(ctx, base);
loc_82738BA0:
	// lhz r11,22(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82738bb4
	if (cr6.eq) goto loc_82738BB4;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x82738BB4;
	sub_82130588(ctx, base);
loc_82738BB4:
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

__attribute__((alias("__imp__sub_82738BC8"))) PPC_WEAK_FUNC(sub_82738BC8);
PPC_FUNC_IMPL(__imp__sub_82738BC8) {
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
	// bl 0x82738b58
	ctx.lr = 0x82738BE8;
	sub_82738B58(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82738c00
	if (cr6.eq) goto loc_82738C00;
	// bl 0x82130588
	ctx.lr = 0x82738BFC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82738C00:
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

__attribute__((alias("__imp__sub_82738C18"))) PPC_WEAK_FUNC(sub_82738C18);
PPC_FUNC_IMPL(__imp__sub_82738C18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r9,r11,-11592
	ctx.r9.s64 = r11.s64 + -11592;
	// li r11,0
	r11.s64 = 0;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r8,r10,2256
	ctx.r8.s64 = ctx.r10.s64 + 2256;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// li r9,48
	ctx.r9.s64 = 48;
	// sth r11,20(r3)
	PPC_STORE_U16(ctx.r3.u32 + 20, r11.u16);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// sth r11,22(r3)
	PPC_STORE_U16(ctx.r3.u32 + 22, r11.u16);
	// lis r5,-32243
	ctx.r5.s64 = -2113077248;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// addi r4,r7,-31280
	ctx.r4.s64 = ctx.r7.s64 + -31280;
	// sth r11,28(r3)
	PPC_STORE_U16(ctx.r3.u32 + 28, r11.u16);
	// sth r11,30(r3)
	PPC_STORE_U16(ctx.r3.u32 + 30, r11.u16);
	// addi r7,r5,-11572
	ctx.r7.s64 = ctx.r5.s64 + -11572;
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// addi r10,r3,80
	ctx.r10.s64 = ctx.r3.s64 + 80;
	// sth r11,36(r3)
	PPC_STORE_U16(ctx.r3.u32 + 36, r11.u16);
	// lfs f0,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// sth r11,38(r3)
	PPC_STORE_U16(ctx.r3.u32 + 38, r11.u16);
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stfs f0,68(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stw r11,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, r11.u32);
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,16
	ctx.r6.s64 = 16;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,16
	ctx.r5.s64 = 16;
	// lvx128 v63,r4,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,32
	ctx.r8.s64 = 32;
	// stvx128 v63,r10,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,32
	ctx.r7.s64 = 32;
	// lvx128 v63,r4,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,48
	ctx.r6.s64 = 48;
	// stvx128 v63,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,-1
	ctx.r5.s64 = -1;
	// lvx128 v63,r4,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, r11.u32);
	// stw r11,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, r11.u32);
	// stfs f0,152(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 152, temp.u32);
	// stfs f0,156(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 156, temp.u32);
	// stb r11,164(r3)
	PPC_STORE_U8(ctx.r3.u32 + 164, r11.u8);
	// stfs f0,160(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 160, temp.u32);
	// stb r11,165(r3)
	PPC_STORE_U8(ctx.r3.u32 + 165, r11.u8);
	// stb r11,166(r3)
	PPC_STORE_U8(ctx.r3.u32 + 166, r11.u8);
	// addi r10,r3,176
	ctx.r10.s64 = ctx.r3.s64 + 176;
	// stb r11,167(r3)
	PPC_STORE_U8(ctx.r3.u32 + 167, r11.u8);
	// stb r11,168(r3)
	PPC_STORE_U8(ctx.r3.u32 + 168, r11.u8);
	// stb r11,169(r3)
	PPC_STORE_U8(ctx.r3.u32 + 169, r11.u8);
	// stb r11,170(r3)
	PPC_STORE_U8(ctx.r3.u32 + 170, r11.u8);
	// stb r11,171(r3)
	PPC_STORE_U8(ctx.r3.u32 + 171, r11.u8);
	// stb r11,172(r3)
	PPC_STORE_U8(ctx.r3.u32 + 172, r11.u8);
	// stb r11,173(r3)
	PPC_STORE_U8(ctx.r3.u32 + 173, r11.u8);
	// stw r5,184(r3)
	PPC_STORE_U32(ctx.r3.u32 + 184, ctx.r5.u32);
	// stb r11,188(r3)
	PPC_STORE_U8(ctx.r3.u32 + 188, r11.u8);
	// stb r11,189(r3)
	PPC_STORE_U8(ctx.r3.u32 + 189, r11.u8);
	// stw r11,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, r11.u32);
	// stw r11,180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 180, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82738D18"))) PPC_WEAK_FUNC(sub_82738D18);
PPC_FUNC_IMPL(__imp__sub_82738D18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-21544(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21544);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82738D24"))) PPC_WEAK_FUNC(sub_82738D24);
PPC_FUNC_IMPL(__imp__sub_82738D24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82738D28"))) PPC_WEAK_FUNC(sub_82738D28);
PPC_FUNC_IMPL(__imp__sub_82738D28) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r31,148
	ctx.r3.s64 = r31.s64 + 148;
	// addi r10,r11,-11572
	ctx.r10.s64 = r11.s64 + -11572;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2aa0
	ctx.lr = 0x82738D58;
	sub_821D2AA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82738b58
	ctx.lr = 0x82738D60;
	sub_82738B58(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82738d78
	if (cr6.eq) goto loc_82738D78;
	// bl 0x82130588
	ctx.lr = 0x82738D74;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82738D78:
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

__attribute__((alias("__imp__sub_82738D90"))) PPC_WEAK_FUNC(sub_82738D90);
PPC_FUNC_IMPL(__imp__sub_82738D90) {
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
	ctx.lr = 0x82738D98;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-11552
	ctx.r3.s64 = r11.s64 + -11552;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x82130000
	ctx.lr = 0x82738DB4;
	sub_82130000(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lwz r29,2828(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2828);
	// beq cr6,0x82738de0
	if (cr6.eq) goto loc_82738DE0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82738DD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// b 0x82738de8
	goto loc_82738DE8;
loc_82738DE0:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r6,-21540(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -21540);
loc_82738DE8:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r5,r11,5276
	ctx.r5.s64 = r11.s64 + 5276;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c04b0
	ctx.lr = 0x82738E04;
	sub_821C04B0(ctx, base);
	// lhz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82738e3c
	if (cr6.eq) goto loc_82738E3C;
	// li r29,0
	r29.s64 = 0;
loc_82738E18:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r29,r11
	ctx.r3.u64 = r29.u64 + r11.u64;
	// bl 0x82738320
	ctx.lr = 0x82738E28;
	sub_82738320(ctx, base);
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82738e18
	if (cr6.lt) goto loc_82738E18;
loc_82738E3C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82738E44"))) PPC_WEAK_FUNC(sub_82738E44);
PPC_FUNC_IMPL(__imp__sub_82738E44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82738E48"))) PPC_WEAK_FUNC(sub_82738E48);
PPC_FUNC_IMPL(__imp__sub_82738E48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f31{};
	PPCVRegister v25{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
	PPCVRegister v48{};
	PPCVRegister v49{};
	PPCVRegister v50{};
	PPCVRegister v51{};
	PPCVRegister v52{};
	PPCVRegister v53{};
	PPCVRegister v54{};
	PPCVRegister v55{};
	PPCVRegister v56{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -24, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r4,176(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bne cr6,0x82738e94
	if (!cr6.eq) goto loc_82738E94;
	// lwz r4,180(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x82738e94
	if (!cr6.eq) goto loc_82738E94;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lfs f1,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	ctx.f1.f64 = double(temp.f32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82738fa0
	if (cr6.eq) goto loc_82738FA0;
loc_82738E94:
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82738EA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f31,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// vspltisw128 v60,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r6,r8,2528
	ctx.r6.s64 = ctx.r8.s64 + 2528;
	// addi r5,r7,2240
	ctx.r5.s64 = ctx.r7.s64 + 2240;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v59,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vrsqrtefp128 v58,v59
	simde_mm_store_ps(v58.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v59.f32))));
	// lvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// vor128 v12,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// addi r8,r4,-31648
	ctx.r8.s64 = ctx.r4.s64 + -31648;
	// addi r7,r3,-31664
	ctx.r7.s64 = ctx.r3.s64 + -31664;
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// addi r10,r31,112
	ctx.r10.s64 = r31.s64 + 112;
	// addi r3,r4,-31616
	ctx.r3.s64 = ctx.r4.s64 + -31616;
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r31,96
	ctx.r9.s64 = r31.s64 + 96;
	// lvx128 v13,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,80
	r11.s64 = r31.s64 + 80;
	// vcmpeqfp128 v11,v58,v61
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v10,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v62,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v57,v63,v6
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vsubfp128 v56,v60,v57
	simde_mm_store_ps(v56.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v54,v63,v63
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v53,v54,99
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0x9C));
	// lvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v52,v55,135
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x78));
	// vmulfp128 v3,v52,v53
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v53.f32)));
	// vpermwi128 v5,v54,135
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0x78));
	// vpermwi128 v4,v55,99
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x9C));
	// vnmsubfp v2,v4,v5,v3
	simde_mm_store_ps(ctx.v2.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v3.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vor128 v51,v2,v2
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// stvx128 v2,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v50,v51,v51
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v51.f32), 0xEF));
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v49,v50
	simde_mm_store_ps(v49.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v50.f32))));
	// vor128 v31,v50,v50
	simde_mm_store_si128((simde__m128i*)v31.u8, simde_mm_load_si128((simde__m128i*)v50.u8));
	// vcmpeqfp128 v30,v49,v62
	simde_mm_store_ps(v30.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v29,v49,v49
	simde_mm_store_si128((simde__m128i*)v29.u8, simde_mm_load_si128((simde__m128i*)v49.u8));
	// vsel v0,v29,v1,v30
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v30.u8), simde_mm_load_si128((simde__m128i*)v29.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8))));
	// vmulfp128 v28,v0,v0
	simde_mm_store_ps(v28.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v27,v63,v0
	simde_mm_store_ps(v27.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v26,v31,v28,v13
	simde_mm_store_ps(v26.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(v28.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v25,v26,v27,v0
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v26.f32), simde_mm_load_ps(v27.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v48,v51,v25
	simde_mm_store_ps(v48.f32, simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v25.f32)));
	// stvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82738FA0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82738FB8"))) PPC_WEAK_FUNC(sub_82738FB8);
PPC_FUNC_IMPL(__imp__sub_82738FB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r18{};
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
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x82738FC0;
	// stfd f30,-136(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -136, f30.u64);
	// stfd f31,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r18,r4
	r18.u64 = ctx.r4.u64;
	// addi r29,r31,32
	r29.s64 = r31.s64 + 32;
	// lhz r23,20(r31)
	r23.u64 = PPC_LOAD_U16(r31.u32 + 20);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x82130588
	ctx.lr = 0x82738FE4;
	sub_82130588(ctx, base);
	// li r20,0
	r20.s64 = 0;
	// clrlwi r11,r20,16
	r11.u64 = r20.u32 & 0xFFFF;
	// stw r20,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r20.u32);
	// sth r20,36(r31)
	PPC_STORE_U16(r31.u32 + 36, r20.u16);
	// sth r20,38(r31)
	PPC_STORE_U16(r31.u32 + 38, r20.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82739020
	if (!cr6.eq) goto loc_82739020;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// sth r23,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r23.u16);
	// beq cr6,0x82739018
	if (cr6.eq) goto loc_82739018;
	// rlwinm r3,r23,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x82739014;
	sub_82130528(ctx, base);
	// b 0x8273901c
	goto loc_8273901C;
loc_82739018:
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
loc_8273901C:
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
loc_82739020:
	// li r19,1
	r19.s64 = 1;
	// sth r23,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r23.u16);
	// mr r28,r20
	r28.u64 = r20.u64;
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// ble cr6,0x82739184
	if (!cr6.gt) goto loc_82739184;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lfs f31,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lfs f30,27632(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 27632);
	f30.f64 = double(temp.f32);
	// mr r30,r20
	r30.u64 = r20.u64;
	// li r21,48
	r21.s64 = 48;
	// addi r27,r11,-31664
	r27.s64 = r11.s64 + -31664;
	// addi r26,r10,-31648
	r26.s64 = ctx.r10.s64 + -31648;
	// addi r25,r9,2240
	r25.s64 = ctx.r9.s64 + 2240;
	// addi r24,r8,2528
	r24.s64 = ctx.r8.s64 + 2528;
	// addi r22,r7,2256
	r22.s64 = ctx.r7.s64 + 2256;
loc_82739074:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lvx128 v63,r11,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r30,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lbzx r8,r9,r28
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r28.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82739174
	if (cr6.eq) goto loc_82739174;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r22
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r11,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r20,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r20.u32);
	// stfs f31,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f30,92(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8224a868
	ctx.lr = 0x827390D8;
	sub_8224A868(ctx, base);
	// lwz r7,112(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82739170
	if (cr6.eq) goto loc_82739170;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r9,r23,-1
	ctx.r9.s64 = r23.s64 + -1;
	// cmpw cr6,r28,r9
	cr6.compare<int32_t>(r28.s32, ctx.r9.s32, xer);
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r30,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x82739174
	if (!cr6.eq) goto loc_82739174;
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// lvx128 v62,r0,r24
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v0,r0,r25
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v61,r0,r26
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r27
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,112(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lfs f0,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f0.f64 = double(temp.f32);
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v59,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vrsqrtefp128 v58,v59
	simde_mm_store_ps(v58.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v59.f32))));
	// vor128 v12,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vcmpeqfp128 v11,v58,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v61,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v57,v63,v6
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v57,r31,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r8,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r8.u32);
	// stfs f0,68(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// b 0x82739174
	goto loc_82739174;
loc_82739170:
	// mr r19,r20
	r19.u64 = r20.u64;
loc_82739174:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// cmpw cr6,r28,r23
	cr6.compare<int32_t>(r28.s32, r23.s32, xer);
	// blt cr6,0x82739074
	if (cr6.lt) goto loc_82739074;
loc_82739184:
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f30,-136(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f31,-128(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_82739198"))) PPC_WEAK_FUNC(sub_82739198);
PPC_FUNC_IMPL(__imp__sub_82739198) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v63{};
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x827391B8;
	sub_82130588(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// stw r31,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r31.u32);
	// sth r31,20(r30)
	PPC_STORE_U16(r30.u32 + 20, r31.u16);
	// sth r31,22(r30)
	PPC_STORE_U16(r30.u32 + 22, r31.u16);
	// lwz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x827391D0;
	sub_82130588(ctx, base);
	// stw r31,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r31.u32);
	// sth r31,28(r30)
	PPC_STORE_U16(r30.u32 + 28, r31.u16);
	// sth r31,30(r30)
	PPC_STORE_U16(r30.u32 + 30, r31.u16);
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// bl 0x82130588
	ctx.lr = 0x827391E4;
	sub_82130588(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r31,32(r30)
	PPC_STORE_U32(r30.u32 + 32, r31.u32);
	// li r10,48
	ctx.r10.s64 = 48;
	// sth r31,36(r30)
	PPC_STORE_U16(r30.u32 + 36, r31.u16);
	// sth r31,38(r30)
	PPC_STORE_U16(r30.u32 + 38, r31.u16);
	// stw r31,64(r30)
	PPC_STORE_U32(r30.u32 + 64, r31.u32);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,68(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 68, temp.u32);
	// stvx128 v63,r30,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

__attribute__((alias("__imp__sub_82739224"))) PPC_WEAK_FUNC(sub_82739224);
PPC_FUNC_IMPL(__imp__sub_82739224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82739228"))) PPC_WEAK_FUNC(sub_82739228);
PPC_FUNC_IMPL(__imp__sub_82739228) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82739230;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-10012(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82739268
	if (cr6.eq) goto loc_82739268;
	// addis r3,r11,6
	ctx.r3.s64 = r11.s64 + 393216;
	// lwz r4,184(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// li r5,11
	ctx.r5.s64 = 11;
	// addi r3,r3,16928
	ctx.r3.s64 = ctx.r3.s64 + 16928;
	// bl 0x826e1a20
	ctx.lr = 0x8273925C;
	sub_826E1A20(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10012(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10012);
	// bl 0x826d4b88
	ctx.lr = 0x82739268;
	sub_826D4B88(ctx, base);
loc_82739268:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82739198
	ctx.lr = 0x82739270;
	sub_82739198(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r31,176
	r30.s64 = r31.s64 + 176;
	// stw r29,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r29.u32);
	// li r28,2
	r28.s64 = 2;
	// stb r29,166(r31)
	PPC_STORE_U8(r31.u32 + 166, r29.u8);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r29,167(r31)
	PPC_STORE_U8(r31.u32 + 167, r29.u8);
	// stfs f0,152(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
	// stb r29,168(r31)
	PPC_STORE_U8(r31.u32 + 168, r29.u8);
	// stfs f0,156(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 156, temp.u32);
	// stb r29,169(r31)
	PPC_STORE_U8(r31.u32 + 169, r29.u8);
	// stfs f0,160(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 160, temp.u32);
	// stb r29,170(r31)
	PPC_STORE_U8(r31.u32 + 170, r29.u8);
	// stb r29,171(r31)
	PPC_STORE_U8(r31.u32 + 171, r29.u8);
loc_827392AC:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827392ec
	if (cr6.eq) goto loc_827392EC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827392C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827392e8
	if (cr6.eq) goto loc_827392E8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827392E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827392E8:
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
loc_827392EC:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x827392ac
	if (!cr0.eq) goto loc_827392AC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8273930C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82739314"))) PPC_WEAK_FUNC(sub_82739314);
PPC_FUNC_IMPL(__imp__sub_82739314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82739318"))) PPC_WEAK_FUNC(sub_82739318);
PPC_FUNC_IMPL(__imp__sub_82739318) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// li r3,192
	ctx.r3.s64 = 192;
	// bl 0x82130528
	ctx.lr = 0x8273932C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82739348
	if (cr6.eq) goto loc_82739348;
	// bl 0x82738c18
	ctx.lr = 0x82739338;
	sub_82738C18(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82739348:
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
}

__attribute__((alias("__imp__sub_8273935C"))) PPC_WEAK_FUNC(sub_8273935C);
PPC_FUNC_IMPL(__imp__sub_8273935C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82739360"))) PPC_WEAK_FUNC(sub_82739360);
PPC_FUNC_IMPL(__imp__sub_82739360) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82739368;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r3,r11,6,0,25
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// bl 0x82130528
	ctx.lr = 0x82739380;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x827393ac
	if (!cr6.gt) goto loc_827393AC;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_82739390:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827393a0
	if (cr6.eq) goto loc_827393A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82738c18
	ctx.lr = 0x827393A0;
	sub_82738C18(ctx, base);
loc_827393A0:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,192
	r31.s64 = r31.s64 + 192;
	// bne 0x82739390
	if (!cr0.eq) goto loc_82739390;
loc_827393AC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827393B8"))) PPC_WEAK_FUNC(sub_827393B8);
PPC_FUNC_IMPL(__imp__sub_827393B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x827393C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lbz r11,164(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 164);
	// stb r10,188(r31)
	PPC_STORE_U8(r31.u32 + 188, ctx.r10.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82739404
	if (!cr6.eq) goto loc_82739404;
	// lhz r11,20(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 20);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82739404
	if (!cr6.eq) goto loc_82739404;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82739404
	if (!cr6.eq) goto loc_82739404;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
loc_82739404:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82738fb8
	ctx.lr = 0x82739410;
	sub_82738FB8(ctx, base);
	// lhz r11,20(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 20);
	// li r30,1
	r30.s64 = 1;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x82739444
	if (cr6.lt) goto loc_82739444;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lbz r10,-1(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x82739444
	if (!cr6.eq) goto loc_82739444;
	// lbz r11,-2(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + -2);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82739448
	if (cr6.eq) goto loc_82739448;
loc_82739444:
	// li r11,0
	r11.s64 = 0;
loc_82739448:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82739464
	if (cr6.eq) goto loc_82739464;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82738558
	ctx.lr = 0x82739460;
	sub_82738558(ctx, base);
	// clrlwi r30,r3,31
	r30.u64 = ctx.r3.u32 & 0x1;
loc_82739464:
	// lhz r11,20(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 20);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bge cr6,0x82739478
	if (!cr6.lt) goto loc_82739478;
	// li r11,0
	r11.s64 = 0;
	// b 0x827394a0
	goto loc_827394A0;
loc_82739478:
	// bne cr6,0x8273949c
	if (!cr6.eq) goto loc_8273949C;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8273949c
	if (!cr6.eq) goto loc_8273949C;
	// lbz r11,1(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x827394a0
	if (cr6.eq) goto loc_827394A0;
loc_8273949C:
	// li r11,1
	r11.s64 = 1;
loc_827394A0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827394c4
	if (cr6.eq) goto loc_827394C4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827383b8
	ctx.lr = 0x827394B8;
	sub_827383B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// and r30,r11,r10
	r30.u64 = r11.u64 & ctx.r10.u64;
loc_827394C4:
	// lhz r11,36(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827394e0
	if (cr6.eq) goto loc_827394E0;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r10,128
	ctx.r10.s64 = 128;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_827394E0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82738e48
	ctx.lr = 0x827394E8;
	sub_82738E48(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,156(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 156);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,-19948(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -19948);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x82738a10
	ctx.lr = 0x82739500;
	sub_82738A10(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8273950C"))) PPC_WEAK_FUNC(sub_8273950C);
PPC_FUNC_IMPL(__imp__sub_8273950C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82739510"))) PPC_WEAK_FUNC(sub_82739510);
PPC_FUNC_IMPL(__imp__sub_82739510) {
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
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x82739524;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82739558
	if (cr6.eq) goto loc_82739558;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-14920
	ctx.r9.s64 = ctx.r10.s64 + -14920;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// sth r11,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r11.u16);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82739558:
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
}

__attribute__((alias("__imp__sub_8273956C"))) PPC_WEAK_FUNC(sub_8273956C);
PPC_FUNC_IMPL(__imp__sub_8273956C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82739570"))) PPC_WEAK_FUNC(sub_82739570);
PPC_FUNC_IMPL(__imp__sub_82739570) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-21544
	r31.s64 = r11.s64 + -21544;
	// lwz r11,-21544(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21544);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82739780
	if (!cr6.eq) goto loc_82739780;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x827395A0;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827395b4
	if (cr6.eq) goto loc_827395B4;
	// bl 0x821d5408
	ctx.lr = 0x827395B0;
	sub_821D5408(ctx, base);
	// b 0x827395b8
	goto loc_827395B8;
loc_827395B4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_827395B8:
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-11520
	ctx.r7.s64 = ctx.r10.s64 + -11520;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25688
	ctx.r9.s64 = r11.s64 + 25688;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,192
	ctx.r5.s64 = 192;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32140
	ctx.r8.s64 = -2106327040;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,-27880
	ctx.r4.s64 = ctx.r8.s64 + -27880;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,-6744
	ctx.r9.s64 = ctx.r3.s64 + -6744;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r8,r10,-6184
	ctx.r8.s64 = ctx.r10.s64 + -6184;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,16
	ctx.r10.s64 = 16;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r11,80
	r11.s64 = 80;
	// addi r6,r5,-6136
	ctx.r6.s64 = ctx.r5.s64 + -6136;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,24
	ctx.r9.s64 = 24;
	// addi r5,r4,-6636
	ctx.r5.s64 = ctx.r4.s64 + -6636;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r7,-6612
	ctx.r4.s64 = ctx.r7.s64 + -6612;
	// addi r6,r8,-6588
	ctx.r6.s64 = ctx.r8.s64 + -6588;
	// li r11,152
	r11.s64 = 152;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// li r10,156
	ctx.r10.s64 = 156;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r30,-32125
	r30.s64 = -2105344000;
	// li r9,160
	ctx.r9.s64 = 160;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r5,r7,-6564
	ctx.r5.s64 = ctx.r7.s64 + -6564;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r30,-6540
	ctx.r4.s64 = r30.s64 + -6540;
	// addi r6,r8,-6516
	ctx.r6.s64 = ctx.r8.s64 + -6516;
	// li r11,164
	r11.s64 = 164;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// li r10,165
	ctx.r10.s64 = 165;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r30,-32125
	r30.s64 = -2105344000;
	// li r9,166
	ctx.r9.s64 = 166;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r5,r7,-6492
	ctx.r5.s64 = ctx.r7.s64 + -6492;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r30,-6468
	ctx.r4.s64 = r30.s64 + -6468;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lis r30,-32125
	r30.s64 = -2105344000;
	// addi r6,r8,-6444
	ctx.r6.s64 = ctx.r8.s64 + -6444;
	// li r11,167
	r11.s64 = 167;
	// li r10,168
	ctx.r10.s64 = 168;
	// addi r8,r7,-6420
	ctx.r8.s64 = ctx.r7.s64 + -6420;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// addi r7,r30,-6396
	ctx.r7.s64 = r30.s64 + -6396;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// li r9,169
	ctx.r9.s64 = 169;
	// li r11,170
	r11.s64 = 170;
	// li r10,171
	ctx.r10.s64 = 171;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r8,r6,-6372
	ctx.r8.s64 = ctx.r6.s64 + -6372;
	// addi r7,r11,-6348
	ctx.r7.s64 = r11.s64 + -6348;
	// addi r6,r10,-6324
	ctx.r6.s64 = ctx.r10.s64 + -6324;
	// li r11,172
	r11.s64 = 172;
	// li r10,173
	ctx.r10.s64 = 173;
	// li r9,148
	ctx.r9.s64 = 148;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// bl 0x821d4458
	ctx.lr = 0x8273972C;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8273973C;
	sub_821D4100(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x821d41d0
	ctx.lr = 0x82739758;
	sub_821D41D0(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r10,-6264
	ctx.r4.s64 = ctx.r10.s64 + -6264;
	// bl 0x821d4b00
	ctx.lr = 0x82739768;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x82739780;
	sub_821C0548(ctx, base);
loc_82739780:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_82739798"))) PPC_WEAK_FUNC(sub_82739798);
PPC_FUNC_IMPL(__imp__sub_82739798) {
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
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827397dc
	if (!cr6.eq) goto loc_827397DC;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x827397d4
	if (cr6.eq) goto loc_827397D4;
	// bl 0x82739360
	ctx.lr = 0x827397D0;
	sub_82739360(ctx, base);
	// b 0x827397d8
	goto loc_827397D8;
loc_827397D4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_827397D8:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_827397DC:
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
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

__attribute__((alias("__imp__sub_827397F8"))) PPC_WEAK_FUNC(sub_827397F8);
PPC_FUNC_IMPL(__imp__sub_827397F8) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-21540
	r31.s64 = r11.s64 + -21540;
	// lwz r11,-21540(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21540);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273992c
	if (!cr6.eq) goto loc_8273992C;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x82739828;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273983c
	if (cr6.eq) goto loc_8273983C;
	// bl 0x821d5408
	ctx.lr = 0x82739838;
	sub_821D5408(ctx, base);
	// b 0x82739840
	goto loc_82739840;
loc_8273983C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82739840:
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-11504
	ctx.r7.s64 = ctx.r10.s64 + -11504;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32140
	ctx.r8.s64 = -2106327040;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,-27376
	ctx.r4.s64 = ctx.r8.s64 + -27376;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,-6088
	ctx.r9.s64 = ctx.r3.s64 + -6088;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,4
	ctx.r10.s64 = 4;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r11,-21544(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21544);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x827398bc
	if (!cr6.eq) goto loc_827398BC;
	// bl 0x82739570
	ctx.lr = 0x827398B8;
	sub_82739570(ctx, base);
	// lwz r11,-21544(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21544);
loc_827398BC:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r10,-6300
	ctx.r9.s64 = ctx.r10.s64 + -6300;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r11.u32);
	// bl 0x821d4458
	ctx.lr = 0x827398D8;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x827398E8;
	sub_821D4100(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bl 0x821d41d0
	ctx.lr = 0x82739904;
	sub_821D41D0(ctx, base);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r6,-6192
	ctx.r4.s64 = ctx.r6.s64 + -6192;
	// bl 0x821d4b00
	ctx.lr = 0x82739914;
	sub_821D4B00(ctx, base);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,2828(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2828);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821c0548
	ctx.lr = 0x8273992C;
	sub_821C0548(ctx, base);
loc_8273992C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_82739944"))) PPC_WEAK_FUNC(sub_82739944);
PPC_FUNC_IMPL(__imp__sub_82739944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82739948"))) PPC_WEAK_FUNC(sub_82739948);
PPC_FUNC_IMPL(__imp__sub_82739948) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
	PPCVRegister v32{};
	PPCVRegister v33{};
	PPCVRegister v34{};
	PPCVRegister v35{};
	PPCVRegister v36{};
	PPCVRegister v37{};
	PPCVRegister v38{};
	PPCVRegister v39{};
	PPCVRegister v40{};
	PPCVRegister v41{};
	PPCVRegister v42{};
	PPCVRegister v43{};
	PPCVRegister v44{};
	PPCVRegister v45{};
	PPCVRegister v46{};
	PPCVRegister v47{};
	PPCVRegister v48{};
	PPCVRegister v49{};
	PPCVRegister v50{};
	PPCVRegister v51{};
	PPCVRegister v52{};
	PPCVRegister v53{};
	PPCVRegister v54{};
	PPCVRegister v55{};
	PPCVRegister v56{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82739950;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// li r12,-64
	r12.s64 = -64;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lvx128 v59,r0,r5
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,16
	r11.s64 = ctx.r4.s64 + 16;
	// addi r5,r10,2384
	ctx.r5.s64 = ctx.r10.s64 + 2384;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,48
	ctx.r8.s64 = 48;
	// li r7,16
	ctx.r7.s64 = 16;
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r10,r4,2352
	ctx.r10.s64 = ctx.r4.s64 + 2352;
	// lvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v60,v63
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// lvx128 v58,r11,r7
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v55,v59,v61
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vmrghw128 v56,v58,v62
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// vmrglw128 v54,v60,v63
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// vmrglw128 v53,v58,v62
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v51,v61,v55
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v55.u8)));
	// lis r31,-32124
	r31.s64 = -2105278464;
	// vmrglw128 v52,v57,v56
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// vmrghw128 v50,v57,v56
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// lfs f0,-332(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -332);
	f0.f64 = double(temp.f32);
	// vmrghw128 v49,v54,v53
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v48,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v47,v48,0
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xFF));
	// vmsum4fp128 v46,v51,v52
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v52.f32), 0xFF));
	// vmulfp128 v45,v63,v47
	simde_mm_store_ps(v45.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v47.f32)));
	// vmsum4fp128 v44,v51,v50
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// lwz r3,-26876(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -26876);
	// vmsum4fp128 v43,v51,v49
	simde_mm_store_ps(v43.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v49.f32), 0xFF));
	// li r4,112
	ctx.r4.s64 = 112;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// addi r9,r11,2528
	ctx.r9.s64 = r11.s64 + 2528;
	// lvx128 v42,r3,r4
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r8,2240
	ctx.r5.s64 = ctx.r8.s64 + 2240;
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// vmrghw128 v41,v46,v51
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v40,v44,v43
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// lvx128 v0,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lfs f0,152(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	f0.f64 = double(temp.f32);
	// addi r5,r8,-31648
	ctx.r5.s64 = ctx.r8.s64 + -31648;
	// lfs f13,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r7,-31664
	ctx.r4.s64 = ctx.r7.s64 + -31664;
	// vmrghw128 v39,v40,v41
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// vsubfp128 v127,v39,v45
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v45.f32)));
	// lvx128 v13,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v42,v127
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v127.f32)));
	// vmsum3fp128 v38,v63,v63
	simde_mm_store_ps(v38.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v37,v38
	simde_mm_store_ps(v37.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v38.f32))));
	// vor128 v12,v38,v38
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v38.u8));
	// vcmpeqfp128 v11,v37,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v37,v37
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v37.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v61,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v36,v63,v6
	simde_mm_store_ps(v36.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v36,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lfs f10,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fmadds f9,f10,f13,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f11.f64));
	// lfs f8,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f7.f64 = double(temp.f32);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f12,-7596(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -7596);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8884(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8884);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f6,f7,f8,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f8.f64 + ctx.f9.f64));
	// fsel f5,f6,f6,f13
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f6.f64 : ctx.f13.f64;
	// fsubs f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 - f0.f64));
	// fsel f3,f4,f0,f5
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? f0.f64 : ctx.f5.f64;
	// fmuls f31,f3,f12
	f31.f64 = double(float(ctx.f3.f64 * ctx.f12.f64));
	// fcmpu cr6,f31,f11
	cr6.compare(f31.f64, ctx.f11.f64);
	// ble cr6,0x82739be0
	if (!cr6.gt) goto loc_82739BE0;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82739b94
	if (cr6.eq) goto loc_82739B94;
	// vspltisw128 v35,0
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lfs f13,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// vupkd3d128 v34,v35,4
	temp.f32 = 3.0f;
	temp.s32 += v35.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v35.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v34 = vTemp;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lfs f0,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stvx128 v35,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v33,v34,186
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0x45));
	// stfs f12,164(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// vpermwi128 v32,v34,234
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0x15));
	// lfs f0,14192(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14192);
	f0.f64 = double(temp.f32);
	// vpermwi128 v63,v34,174
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0x51));
	// stvx128 v33,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stvx128 v32,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217c088
	ctx.lr = 0x82739B54;
	sub_8217C088(ctx, base);
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r10,r5,-7468
	ctx.r10.s64 = ctx.r5.s64 + -7468;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f13,-7468(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -7468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,11360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f0.f64 = double(temp.f32);
	// lfs f12,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// bl 0x822fb508
	ctx.lr = 0x82739B90;
	sub_822FB508(ctx, base);
	// b 0x82739bdc
	goto loc_82739BDC;
loc_82739B94:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r4,r11,-31280
	ctx.r4.s64 = r11.s64 + -31280;
	// bl 0x8217c088
	ctx.lr = 0x82739BA0;
	sub_8217C088(ctx, base);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// li r10,1
	ctx.r10.s64 = 1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f0,-7616(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -7616);
	f0.f64 = double(temp.f32);
	// li r7,-3
	ctx.r7.s64 = -3;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f2,14884(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14884);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x822fc250
	ctx.lr = 0x82739BDC;
	sub_822FC250(ctx, base);
loc_82739BDC:
	// lwz r3,-26876(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -26876);
loc_82739BE0:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8217c088
	ctx.lr = 0x82739BE8;
	sub_8217C088(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// li r0,-64
	r0.s64 = -64;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82739BFC"))) PPC_WEAK_FUNC(sub_82739BFC);
PPC_FUNC_IMPL(__imp__sub_82739BFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82739C00"))) PPC_WEAK_FUNC(sub_82739C00);
PPC_FUNC_IMPL(__imp__sub_82739C00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r3,-21536(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + -21536);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82739C0C"))) PPC_WEAK_FUNC(sub_82739C0C);
PPC_FUNC_IMPL(__imp__sub_82739C0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82739C10"))) PPC_WEAK_FUNC(sub_82739C10);
PPC_FUNC_IMPL(__imp__sub_82739C10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,28(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lfs f0,11360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f11,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// fmuls f1,f10,f1
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f1.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82739C34"))) PPC_WEAK_FUNC(sub_82739C34);
PPC_FUNC_IMPL(__imp__sub_82739C34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82739C38"))) PPC_WEAK_FUNC(sub_82739C38);
PPC_FUNC_IMPL(__imp__sub_82739C38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,160(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// bne cr6,0x82739c70
	if (!cr6.eq) goto loc_82739C70;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f13,164(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-5852(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5852);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82739c60
	if (cr6.lt) goto loc_82739C60;
	// li r11,0
	r11.s64 = 0;
loc_82739C60:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82739c74
	if (!cr6.eq) goto loc_82739C74;
loc_82739C70:
	// li r11,0
	r11.s64 = 0;
loc_82739C74:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,6
	ctx.r9.s64 = 393216;
	// ori r8,r9,16948
	ctx.r8.u64 = ctx.r9.u64 | 16948;
	// lwz r10,-10012(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10012);
	// lbzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// or r6,r7,r11
	ctx.r6.u64 = ctx.r7.u64 | r11.u64;
	// clrlwi r3,r6,24
	ctx.r3.u64 = ctx.r6.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82739C94"))) PPC_WEAK_FUNC(sub_82739C94);
PPC_FUNC_IMPL(__imp__sub_82739C94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82739C98"))) PPC_WEAK_FUNC(sub_82739C98);
PPC_FUNC_IMPL(__imp__sub_82739C98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,160(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// bne cr6,0x82739ce4
	if (!cr6.eq) goto loc_82739CE4;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f0,164(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	f0.f64 = double(temp.f32);
	// lfs f13,-5852(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5852);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x82739cd0
	if (cr6.lt) goto loc_82739CD0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f12,-5856(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5856);
	ctx.f12.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fadds f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x82739cd4
	if (cr6.lt) goto loc_82739CD4;
loc_82739CD0:
	// li r11,0
	r11.s64 = 0;
loc_82739CD4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82739ce8
	if (!cr6.eq) goto loc_82739CE8;
loc_82739CE4:
	// li r11,0
	r11.s64 = 0;
loc_82739CE8:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,6
	ctx.r9.s64 = 393216;
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// ori r7,r9,16948
	ctx.r7.u64 = ctx.r9.u64 | 16948;
	// lwz r11,-10012(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10012);
	// lbzx r6,r11,r7
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + ctx.r7.u32);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// and r3,r4,r8
	ctx.r3.u64 = ctx.r4.u64 & ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82739D10"))) PPC_WEAK_FUNC(sub_82739D10);
PPC_FUNC_IMPL(__imp__sub_82739D10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,160(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// bne cr6,0x82739d54
	if (!cr6.eq) goto loc_82739D54;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f12,164(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lfs f0,-5856(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5856);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f13,-5852(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -5852);
	ctx.f13.f64 = double(temp.f32);
	// fadds f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 + ctx.f13.f64));
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bge cr6,0x82739d44
	if (!cr6.lt) goto loc_82739D44;
	// li r11,0
	r11.s64 = 0;
loc_82739D44:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x82739d58
	if (cr6.eq) goto loc_82739D58;
loc_82739D54:
	// li r11,1
	r11.s64 = 1;
loc_82739D58:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,6
	ctx.r9.s64 = 393216;
	// clrlwi r8,r11,24
	ctx.r8.u64 = r11.u32 & 0xFF;
	// ori r7,r9,16948
	ctx.r7.u64 = ctx.r9.u64 | 16948;
	// lwz r11,-10012(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10012);
	// lbzx r6,r11,r7
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + ctx.r7.u32);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// and r3,r4,r8
	ctx.r3.u64 = ctx.r4.u64 & ctx.r8.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82739D80"))) PPC_WEAK_FUNC(sub_82739D80);
PPC_FUNC_IMPL(__imp__sub_82739D80) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r31,0
	r31.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82739ecc
	if (cr6.eq) goto loc_82739ECC;
	// lhz r9,172(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 172);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82739ecc
	if (!cr6.gt) goto loc_82739ECC;
	// lwz r11,168(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
loc_82739DB8:
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r6,r4
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r4.u32, xer);
	// beq cr6,0x82739dd8
	if (cr6.eq) goto loc_82739DD8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x82739db8
	if (cr6.lt) goto loc_82739DB8;
	// b 0x82739ecc
	goto loc_82739ECC;
loc_82739DD8:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82739ecc
	if (cr6.lt) goto loc_82739ECC;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r7,160(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// cmpw cr6,r7,r10
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, xer);
	// lfs f12,-5856(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5856);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,-5852(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -5852);
	f0.f64 = double(temp.f32);
	// bne cr6,0x82739e2c
	if (!cr6.eq) goto loc_82739E2C;
	// lfs f13,164(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82739e18
	if (cr6.lt) goto loc_82739E18;
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + f0.f64));
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// blt cr6,0x82739e1c
	if (cr6.lt) goto loc_82739E1C;
loc_82739E18:
	// li r11,0
	r11.s64 = 0;
loc_82739E1C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// li r9,1
	ctx.r9.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82739e30
	if (!cr6.eq) goto loc_82739E30;
loc_82739E2C:
	// li r9,0
	ctx.r9.s64 = 0;
loc_82739E30:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r8,6
	ctx.r8.s64 = 393216;
	// cmpw cr6,r7,r10
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, xer);
	// ori r6,r8,16948
	ctx.r6.u64 = ctx.r8.u64 | 16948;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// lbzx r8,r11,r6
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r6.u32);
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r6,r11,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// and r31,r6,r9
	r31.u64 = ctx.r6.u64 & ctx.r9.u64;
	// bne cr6,0x82739e80
	if (!cr6.eq) goto loc_82739E80;
	// lfs f13,164(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82739e70
	if (cr6.lt) goto loc_82739E70;
	// li r11,0
	r11.s64 = 0;
loc_82739E70:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82739e84
	if (!cr6.eq) goto loc_82739E84;
loc_82739E80:
	// li r11,0
	r11.s64 = 0;
loc_82739E84:
	// clrlwi r9,r8,24
	ctx.r9.u64 = ctx.r8.u32 & 0xFF;
	// cmpw cr6,r7,r10
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r10.s32, xer);
	// or r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 | r11.u64;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// bne cr6,0x82739ec0
	if (!cr6.eq) goto loc_82739EC0;
	// fadds f0,f12,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f12.f64 + f0.f64));
	// lfs f13,164(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82739eb0
	if (!cr6.lt) goto loc_82739EB0;
	// li r11,0
	r11.s64 = 0;
loc_82739EB0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x82739ec4
	if (cr6.eq) goto loc_82739EC4;
loc_82739EC0:
	// li r11,1
	r11.s64 = 1;
loc_82739EC4:
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// and r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 & r11.u64;
loc_82739ECC:
	// lwz r11,288(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 288);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82739f5c
	if (cr6.eq) goto loc_82739F5C;
	// lwz r5,292(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 292);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x82739f5c
	if (cr6.eq) goto loc_82739F5C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r7,r7,24
	ctx.r7.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f13,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// beq cr6,0x82739f08
	if (cr6.eq) goto loc_82739F08;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
	// b 0x82739f0c
	goto loc_82739F0C;
loc_82739F08:
	// fmr f11,f0
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = f0.f64;
loc_82739F0C:
	// clrlwi r10,r31,24
	ctx.r10.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82739f20
	if (cr6.eq) goto loc_82739F20;
	// fmr f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f13.f64;
	// b 0x82739f24
	goto loc_82739F24;
loc_82739F20:
	// fmr f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = f0.f64;
loc_82739F24:
	// clrlwi r10,r8,24
	ctx.r10.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82739f34
	if (cr6.eq) goto loc_82739F34;
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f13.f64;
loc_82739F34:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x8218a6e0
	ctx.lr = 0x82739F5C;
	sub_8218A6E0(ctx, base);
loc_82739F5C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82739F70"))) PPC_WEAK_FUNC(sub_82739F70);
PPC_FUNC_IMPL(__imp__sub_82739F70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82739F78;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x82489d40
	ctx.lr = 0x82739F94;
	sub_82489D40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273a16c
	if (!cr6.eq) goto loc_8273A16C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// vspltisw128 v63,2
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x2)));
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// li r8,48
	ctx.r8.s64 = 48;
	// li r7,112
	ctx.r7.s64 = 112;
	// vcuxwfp128 v62,v63,0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v63.u32)));
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r6,64
	ctx.r6.s64 = 64;
	// lwz r3,-26876(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -26876);
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v1,r31,r6
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v60,r3,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v59,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// vrlimi128 v1,v62,1,1
	simde_mm_store_ps(ctx.v1.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_permute_ps(simde_mm_load_ps(v62.f32), 147), 1));
	// lvx128 v58,r11,r5
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217c1d8
	ctx.lr = 0x8273A000;
	sub_8217C1D8(ctx, base);
	// lfs f0,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// beq cr6,0x8273a028
	if (cr6.eq) goto loc_8273A028;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,-1540(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1540);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f10,f11
	cr6.compare(ctx.f10.f64, ctx.f11.f64);
	// ble cr6,0x8273a044
	if (!cr6.gt) goto loc_8273A044;
loc_8273A028:
	// fmuls f10,f12,f12
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f11,-12988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12988);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f8,f0,f0,f9
	ctx.f8.f64 = double(float(f0.f64 * f0.f64 + ctx.f9.f64));
	// fcmpu cr6,f8,f11
	cr6.compare(ctx.f8.f64, ctx.f11.f64);
	// bgt cr6,0x8273a16c
	if (cr6.gt) goto loc_8273A16C;
loc_8273A044:
	// lfs f11,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// lfs f9,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f9,f13,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f6,f8,f0,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f31
	cr6.compare(ctx.f6.f64, f31.f64);
	// bgt cr6,0x8273a16c
	if (cr6.gt) goto loc_8273A16C;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8273a13c
	if (cr6.eq) goto loc_8273A13C;
	// lhz r10,172(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 172);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8273a13c
	if (!cr6.gt) goto loc_8273A13C;
	// lwz r11,168(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 168);
loc_8273A080:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r9,r31
	cr6.compare<uint32_t>(ctx.r9.u32, r31.u32, xer);
	// beq cr6,0x8273a0a0
	if (cr6.eq) goto loc_8273A0A0;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x8273a080
	if (cr6.lt) goto loc_8273A080;
	// b 0x8273a13c
	goto loc_8273A13C;
loc_8273A0A0:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x8273a13c
	if (cr6.lt) goto loc_8273A13C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82739d10
	ctx.lr = 0x8273A0B4;
	sub_82739D10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a0e4
	if (cr6.eq) goto loc_8273A0E4;
	// lis r30,-1
	r30.s64 = -65536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r31,160
	ctx.r5.s64 = r31.s64 + 160;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82739948
	ctx.lr = 0x8273A0D8;
	sub_82739948(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r31,176
	ctx.r5.s64 = r31.s64 + 176;
	// b 0x8273a160
	goto loc_8273A160;
loc_8273A0E4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82739c98
	ctx.lr = 0x8273A0F0;
	sub_82739C98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a124
	if (cr6.eq) goto loc_8273A124;
	// lis r3,-32
	ctx.r3.s64 = -2097152;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// ori r3,r3,32832
	ctx.r3.u64 = ctx.r3.u64 | 32832;
	// addi r5,r31,192
	ctx.r5.s64 = r31.s64 + 192;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82739948
	ctx.lr = 0x8273A114;
	sub_82739948(ctx, base);
	// lis r3,-32
	ctx.r3.s64 = -2097152;
	// addi r5,r31,208
	ctx.r5.s64 = r31.s64 + 208;
	// ori r3,r3,32832
	ctx.r3.u64 = ctx.r3.u64 | 32832;
	// b 0x8273a160
	goto loc_8273A160;
loc_8273A124:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82739c38
	ctx.lr = 0x8273A130;
	sub_82739C38(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a16c
	if (cr6.eq) goto loc_8273A16C;
loc_8273A13C:
	// lis r3,-256
	ctx.r3.s64 = -16777216;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r5,r31,224
	ctx.r5.s64 = r31.s64 + 224;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// ori r3,r3,65280
	ctx.r3.u64 = ctx.r3.u64 | 65280;
	// bl 0x82739948
	ctx.lr = 0x8273A154;
	sub_82739948(ctx, base);
	// lis r3,-256
	ctx.r3.s64 = -16777216;
	// addi r5,r31,240
	ctx.r5.s64 = r31.s64 + 240;
	// ori r3,r3,65280
	ctx.r3.u64 = ctx.r3.u64 | 65280;
loc_8273A160:
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82739948
	ctx.lr = 0x8273A16C;
	sub_82739948(ctx, base);
loc_8273A16C:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8273A178"))) PPC_WEAK_FUNC(sub_8273A178);
PPC_FUNC_IMPL(__imp__sub_8273A178) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8273A180;
	// li r12,-48
	r12.s64 = -48;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,6
	ctx.r10.s64 = 393216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// ori r9,r10,16948
	ctx.r9.u64 = ctx.r10.u64 | 16948;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8273a1c4
	if (cr6.eq) goto loc_8273A1C4;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// li r0,-48
	r0.s64 = -48;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d924c
	return;
loc_8273A1C4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8273A1D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8273A1F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8273A20C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8273A22C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v63,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v127.f32)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f13,164(r30)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lis r3,-32122
	ctx.r3.s64 = -2105147392;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lfs f0,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r10,r3,2528
	ctx.r10.s64 = ctx.r3.s64 + 2528;
	// addi r7,r9,2240
	ctx.r7.s64 = ctx.r9.s64 + 2240;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r6,r9,-31664
	ctx.r6.s64 = ctx.r9.s64 + -31664;
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v61,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vrsqrtefp128 v60,v61
	simde_mm_store_ps(v60.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v61.f32))));
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r11,-31648
	ctx.r7.s64 = r11.s64 + -31648;
	// vor128 v12,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// lvx128 v13,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-5852(r3)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -5852);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// lvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128 v11,v60,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v61,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v59,v63,v6
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v59,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blt cr6,0x8273a2d0
	if (cr6.lt) goto loc_8273A2D0;
	// li r11,0
	r11.s64 = 0;
loc_8273A2D0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a304
	if (cr6.eq) goto loc_8273A304;
	// lwz r11,160(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8273a304
	if (cr6.lt) goto loc_8273A304;
	// lhz r10,48(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 48);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x8273a304
	if (!cr6.lt) goto loc_8273A304;
	// lwz r10,44(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8273a30c
	goto loc_8273A30C;
loc_8273A304:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r11,r11,2272
	r11.s64 = r11.s64 + 2272;
loc_8273A30C:
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f8,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f8.f64 = double(temp.f32);
	// lfs f0,-5848(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -5848);
	f0.f64 = double(temp.f32);
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f6,f9,f8,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f0
	cr6.compare(ctx.f6.f64, f0.f64);
	// bgt cr6,0x8273a348
	if (cr6.gt) goto loc_8273A348;
	// li r11,0
	r11.s64 = 0;
loc_8273A348:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// li r0,-48
	r0.s64 = -48;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8273A35C"))) PPC_WEAK_FUNC(sub_8273A35C);
PPC_FUNC_IMPL(__imp__sub_8273A35C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273A360"))) PPC_WEAK_FUNC(sub_8273A360);
PPC_FUNC_IMPL(__imp__sub_8273A360) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,6
	ctx.r10.s64 = 393216;
	// ori r9,r10,16948
	ctx.r9.u64 = ctx.r10.u64 | 16948;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8273a384
	if (cr6.eq) goto loc_8273A384;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8273A384:
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f13,164(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r6,2528
	ctx.r4.s64 = ctx.r6.s64 + 2528;
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r9,r11,2240
	ctx.r9.s64 = r11.s64 + 2240;
	// stfs f0,-12(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v61,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vrsqrtefp128 v60,v61
	simde_mm_store_ps(v60.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v61.f32))));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r9,r11,-31664
	ctx.r9.s64 = r11.s64 + -31664;
	// vor128 v12,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// addi r10,r5,-31648
	ctx.r10.s64 = ctx.r5.s64 + -31648;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// li r11,1
	r11.s64 = 1;
	// lvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-5852(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -5852);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// vcmpeqfp128 v11,v60,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v61,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v59,v63,v6
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blt cr6,0x8273a424
	if (cr6.lt) goto loc_8273A424;
	// li r11,0
	r11.s64 = 0;
loc_8273A424:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a458
	if (cr6.eq) goto loc_8273A458;
	// lwz r11,160(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8273a458
	if (cr6.lt) goto loc_8273A458;
	// lhz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 48);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x8273a458
	if (!cr6.lt) goto loc_8273A458;
	// lwz r10,44(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8273a460
	goto loc_8273A460;
loc_8273A458:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r11,r11,2272
	r11.s64 = r11.s64 + 2272;
loc_8273A460:
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lfs f13,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-8(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f8,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f8.f64 = double(temp.f32);
	// lfs f0,-5848(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -5848);
	f0.f64 = double(temp.f32);
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f6,f9,f8,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f0
	cr6.compare(ctx.f6.f64, f0.f64);
	// bgt cr6,0x8273a49c
	if (cr6.gt) goto loc_8273A49C;
	// li r11,0
	r11.s64 = 0;
loc_8273A49C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273A4A4"))) PPC_WEAK_FUNC(sub_8273A4A4);
PPC_FUNC_IMPL(__imp__sub_8273A4A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273A4A8"))) PPC_WEAK_FUNC(sub_8273A4A8);
PPC_FUNC_IMPL(__imp__sub_8273A4A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lhz r10,148(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 148);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lfs f0,-5856(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5856);
	f0.f64 = double(temp.f32);
	// lfs f13,-5852(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -5852);
	ctx.f13.f64 = double(temp.f32);
	// stw r9,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r9.u32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f0,164(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 164, temp.u32);
	// beq cr6,0x8273a4f8
	if (cr6.eq) goto loc_8273A4F8;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8273A4DC:
	// lwz r8,144(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lhz r7,148(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 148);
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x8273a4dc
	if (cr6.lt) goto loc_8273A4DC;
loc_8273A4F8:
	// lhz r11,156(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 156);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a530
	if (cr6.eq) goto loc_8273A530;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8273A514:
	// lwz r8,152(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stfsx f0,r8,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lhz r7,156(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 156);
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x8273a514
	if (cr6.lt) goto loc_8273A514;
loc_8273A530:
	// li r11,-1
	r11.s64 = -1;
	// stb r9,180(r3)
	PPC_STORE_U8(ctx.r3.u32 + 180, ctx.r9.u8);
	// stw r11,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273A540"))) PPC_WEAK_FUNC(sub_8273A540);
PPC_FUNC_IMPL(__imp__sub_8273A540) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8273A548;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,80
	r11.s64 = 80;
	// lfs f0,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f11,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f10,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lvx128 v62,r31,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f30,-31400(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -31400);
	f30.f64 = double(temp.f32);
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f9,f0,f13
	ctx.f9.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fmadds f8,f11,f12,f9
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f12.f64 + ctx.f9.f64));
	// fmadds f7,f10,f31,f8
	ctx.f7.f64 = double(float(ctx.f10.f64 * f31.f64 + ctx.f8.f64));
	// fcmpu cr6,f7,f31
	cr6.compare(ctx.f7.f64, f31.f64);
	// ble cr6,0x8273a5f0
	if (!cr6.gt) goto loc_8273A5F0;
	// fmuls f10,f11,f11
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// lfs f9,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f8,f9,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f10.f64));
	// fmadds f7,f0,f0,f8
	ctx.f7.f64 = double(float(f0.f64 * f0.f64 + ctx.f8.f64));
	// fsqrts f0,f7
	f0.f64 = double(float(sqrt(ctx.f7.f64)));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x8273a5f0
	if (cr6.eq) goto loc_8273A5F0;
	// fmuls f11,f13,f13
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f10,64(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f9,f12,f12,f11
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f11.f64));
	// fsqrts f8,f9
	ctx.f8.f64 = double(float(sqrt(ctx.f9.f64)));
	// fnmsubs f7,f10,f13,f8
	ctx.f7.f64 = double(float(-(ctx.f10.f64 * ctx.f13.f64 - ctx.f8.f64)));
	// fdivs f30,f7,f0
	f30.f64 = double(float(ctx.f7.f64 / f0.f64));
loc_8273A5F0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8273e210
	ctx.lr = 0x8273A5F8;
	sub_8273E210(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8273a750
	if (cr6.lt) goto loc_8273A750;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273a640
	if (!cr6.eq) goto loc_8273A640;
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// beq cr6,0x8273a750
	if (cr6.eq) goto loc_8273A750;
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// add r9,r30,r9
	ctx.r9.u64 = r30.u64 + ctx.r9.u64;
	// stwx r9,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r9.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8273A640:
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lfs f0,164(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	f0.f64 = double(temp.f32);
	// lfs f12,-5852(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -5852);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x8273a6b4
	if (!cr6.lt) goto loc_8273A6B4;
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// bne cr6,0x8273a684
	if (!cr6.eq) goto loc_8273A684;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a750
	if (cr6.eq) goto loc_8273A750;
	// stfs f31,164(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8273A684:
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// add r9,r30,r9
	ctx.r9.u64 = r30.u64 + ctx.r9.u64;
	// stwx r9,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r9.u32);
	// lfs f0,-5852(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -5852);
	f0.f64 = double(temp.f32);
	// stfs f0,164(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8273A6B4:
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lfs f13,-5856(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -5856);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8273a708
	if (!cr6.lt) goto loc_8273A708;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lfs f12,-29232(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fsel f11,f12,f0,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// stfs f11,164(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// add r8,r30,r9
	ctx.r8.u64 = r30.u64 + ctx.r9.u64;
	// stwx r8,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r8.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8273A708:
	// lwz r10,144(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// add r4,r30,r9
	ctx.r4.u64 = r30.u64 + ctx.r9.u64;
	// lfs f11,-29232(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -29232);
	ctx.f11.f64 = double(temp.f32);
	// stwx r4,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r4.u32);
	// lfs f10,164(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	ctx.f10.f64 = double(temp.f32);
	// lfs f12,-5852(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -5852);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,-5860(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -5860);
	f0.f64 = double(temp.f32);
	// lfs f13,-5856(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -5856);
	ctx.f13.f64 = double(temp.f32);
	// fadds f9,f0,f13
	ctx.f9.f64 = double(float(f0.f64 + ctx.f13.f64));
	// fadds f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 + ctx.f12.f64));
	// fsubs f7,f8,f11
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f11.f64));
	// fsubs f6,f10,f7
	ctx.f6.f64 = double(float(ctx.f10.f64 - ctx.f7.f64));
	// fsel f5,f6,f10,f7
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f10.f64 : ctx.f7.f64;
	// stfs f5,164(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
loc_8273A750:
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8273A764"))) PPC_WEAK_FUNC(sub_8273A764);
PPC_FUNC_IMPL(__imp__sub_8273A764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273A768"))) PPC_WEAK_FUNC(sub_8273A768);
PPC_FUNC_IMPL(__imp__sub_8273A768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r9,-21536(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -21536);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273A77C"))) PPC_WEAK_FUNC(sub_8273A77C);
PPC_FUNC_IMPL(__imp__sub_8273A77C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273A780"))) PPC_WEAK_FUNC(sub_8273A780);
PPC_FUNC_IMPL(__imp__sub_8273A780) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stb r6,-21536(r10)
	PPC_STORE_U8(ctx.r10.u32 + -21536, ctx.r6.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273A7A0"))) PPC_WEAK_FUNC(sub_8273A7A0);
PPC_FUNC_IMPL(__imp__sub_8273A7A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
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
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a82c
	if (cr6.eq) goto loc_8273A82C;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addis r3,r11,6
	ctx.r3.s64 = r11.s64 + 393216;
	// addi r3,r3,16704
	ctx.r3.s64 = ctx.r3.s64 + 16704;
	// bl 0x822499f8
	ctx.lr = 0x8273A7D8;
	sub_822499F8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8273a82c
	if (cr6.eq) goto loc_8273A82C;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r11,2384
	ctx.r10.s64 = r11.s64 + 2384;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v60,v62,v63
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v59,v60,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	cr6.setFromMask(simde_mm_load_ps(v59.f32), 0xF);
	// mfocrf r9,2
	ctx.r9.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r8,r9,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8273a82c
	if (!cr6.eq) goto loc_8273A82C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8273e210
	ctx.lr = 0x8273A818;
	sub_8273E210(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8273a82c
	if (cr6.lt) goto loc_8273A82C;
	// li r11,0
	r11.s64 = 0;
	// stw r3,176(r31)
	PPC_STORE_U32(r31.u32 + 176, ctx.r3.u32);
	// stb r11,180(r31)
	PPC_STORE_U8(r31.u32 + 180, r11.u8);
loc_8273A82C:
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

__attribute__((alias("__imp__sub_8273A844"))) PPC_WEAK_FUNC(sub_8273A844);
PPC_FUNC_IMPL(__imp__sub_8273A844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273A848"))) PPC_WEAK_FUNC(sub_8273A848);
PPC_FUNC_IMPL(__imp__sub_8273A848) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x8273A850;
	// stfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f30.u64);
	// stfd f31,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r25,0(r13)
	r25.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// li r24,72
	r24.s64 = 72;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// li r31,0
	r31.s64 = 0;
	// lfs f31,11712(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11712);
	f31.f64 = double(temp.f32);
	// li r29,8
	r29.s64 = 8;
	// lis r28,-32253
	r28.s64 = -2113732608;
loc_8273A888:
	// lbzx r10,r24,r25
	ctx.r10.u64 = PPC_LOAD_U8(r24.u32 + r25.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273a89c
	if (cr6.eq) goto loc_8273A89C;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// b 0x8273a8a0
	goto loc_8273A8A0;
loc_8273A89C:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
loc_8273A8A0:
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x8273a970
	if (!cr6.lt) goto loc_8273A970;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273a8d4
	if (cr6.eq) goto loc_8273A8D4;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8273a8f8
	if (cr6.lt) goto loc_8273A8F8;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x8273a8f8
	if (!cr6.lt) goto loc_8273A8F8;
	// add r11,r29,r3
	r11.u64 = r29.u64 + ctx.r3.u64;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// b 0x8273a8f0
	goto loc_8273A8F0;
loc_8273A8D4:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8273a8f8
	if (cr6.lt) goto loc_8273A8F8;
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x8273a8f8
	if (!cr6.lt) goto loc_8273A8F8;
	// lwzx r11,r29,r3
	r11.u64 = PPC_LOAD_U32(r29.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
loc_8273A8F0:
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8273a8fc
	if (!cr6.eq) goto loc_8273A8FC;
loc_8273A8F8:
	// li r11,0
	r11.s64 = 0;
loc_8273A8FC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a950
	if (cr6.eq) goto loc_8273A950;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x8273A910;
	sub_822A3998(ctx, base);
	// lwz r3,640(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 640);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273a94c
	if (cr6.eq) goto loc_8273A94C;
	// bl 0x822452f8
	ctx.lr = 0x8273A920;
	sub_822452F8(ctx, base);
	// cmplw cr6,r3,r26
	cr6.compare<uint32_t>(ctx.r3.u32, r26.u32, xer);
	// bne cr6,0x8273a94c
	if (!cr6.eq) goto loc_8273A94C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8273A934;
	sub_822A3998(ctx, base);
	// lfs f0,-18988(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + -18988);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f31
	f0.f64 = double(float(f0.f64 * f31.f64));
	// lfs f13,644(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 644);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// blt cr6,0x8273a95c
	if (cr6.lt) goto loc_8273A95C;
loc_8273A94C:
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
loc_8273A950:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// b 0x8273a888
	goto loc_8273A888;
loc_8273A95C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_8273A970:
	// li r11,0
	r11.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, r11.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8273c1b8
	ctx.lr = 0x8273A988;
	sub_8273C1B8(ctx, base);
	// lwz r10,352(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8273abac
	if (!cr6.gt) goto loc_8273ABAC;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r29,r1,96
	r29.s64 = ctx.r1.s64 + 96;
	// lis r27,-32130
	r27.s64 = -2105671680;
	// lfs f30,-12084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12084);
	f30.f64 = double(temp.f32);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_8273A9B0:
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplw cr6,r30,r23
	cr6.compare<uint32_t>(r30.u32, r23.u32, xer);
	// beq cr6,0x8273ab98
	if (cr6.eq) goto loc_8273AB98;
	// lwz r11,448(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 448);
	// lbz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 112);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8273ab98
	if (!cr6.eq) goto loc_8273AB98;
	// lwz r11,452(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a95c
	if (cr6.eq) goto loc_8273A95C;
	// lwz r4,188(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8273a95c
	if (cr6.eq) goto loc_8273A95C;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// rlwinm r10,r11,0,19,20
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1800;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8273aa30
	if (cr6.eq) goto loc_8273AA30;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8273a178
	ctx.lr = 0x8273AA04;
	sub_8273A178(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273ab98
	if (!cr6.eq) goto loc_8273AB98;
	// lfs f0,412(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 412);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x8273aa24
	if (cr6.eq) goto loc_8273AA24;
	// li r11,0
	r11.s64 = 0;
loc_8273AA24:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a95c
	if (cr6.eq) goto loc_8273A95C;
loc_8273AA30:
	// lbz r11,500(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 500);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273aa64
	if (cr6.eq) goto loc_8273AA64;
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273aa64
	if (cr6.eq) goto loc_8273AA64;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8273aa64
	if (cr6.eq) goto loc_8273AA64;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// b 0x8273aab8
	goto loc_8273AAB8;
loc_8273AA64:
	// lbzx r11,r24,r25
	r11.u64 = PPC_LOAD_U8(r24.u32 + r25.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273aa84
	if (cr6.eq) goto loc_8273AA84;
	// lwz r11,22080(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 22080);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// b 0x8273aab4
	goto loc_8273AAB4;
loc_8273AA84:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273aaac
	if (cr6.eq) goto loc_8273AAAC;
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273aaac
	if (cr6.eq) goto loc_8273AAAC;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8273aaac
	if (cr6.eq) goto loc_8273AAAC;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// b 0x8273aab0
	goto loc_8273AAB0;
loc_8273AAAC:
	// addi r11,r30,112
	r11.s64 = r30.s64 + 112;
loc_8273AAB0:
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_8273AAB4:
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
loc_8273AAB8:
	// lfs f13,88(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f12,116(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// lfs f10,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,80(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,120(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 120);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f13,f10,f9
	ctx.f13.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// lfs f7,112(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 112);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,60(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 60);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f6,f30
	ctx.f5.f64 = double(float(ctx.f6.f64 * f30.f64));
	// fmadds f4,f8,f0,f11
	ctx.f4.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f3,f7,f13,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 + ctx.f4.f64));
	// fabs f2,f3
	ctx.f2.u64 = ctx.f3.u64 & ~0x8000000000000000;
	// fcmpu cr6,f2,f5
	cr6.compare(ctx.f2.f64, ctx.f5.f64);
	// bge cr6,0x8273ab2c
	if (!cr6.lt) goto loc_8273AB2C;
	// lfs f12,100(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// lfs f10,104(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,96(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,64(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 64);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f30
	ctx.f7.f64 = double(float(ctx.f8.f64 * f30.f64));
	// fmadds f6,f10,f0,f11
	ctx.f6.f64 = double(float(ctx.f10.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f5,f9,f13,f6
	ctx.f5.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f6.f64));
	// fabs f4,f5
	ctx.f4.u64 = ctx.f5.u64 & ~0x8000000000000000;
	// fcmpu cr6,f4,f7
	cr6.compare(ctx.f4.f64, ctx.f7.f64);
	// blt cr6,0x8273ab30
	if (cr6.lt) goto loc_8273AB30;
loc_8273AB2C:
	// li r11,0
	r11.s64 = 0;
loc_8273AB30:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273ab98
	if (cr6.eq) goto loc_8273AB98;
	// lwz r11,452(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 452);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a95c
	if (cr6.eq) goto loc_8273A95C;
	// lwz r31,192(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 192);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8273a95c
	if (cr6.eq) goto loc_8273A95C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822452f8
	ctx.lr = 0x8273AB5C;
	sub_822452F8(ctx, base);
	// cmplw cr6,r3,r26
	cr6.compare<uint32_t>(ctx.r3.u32, r26.u32, xer);
	// bne cr6,0x8273ab74
	if (!cr6.eq) goto loc_8273AB74;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8273a178
	ctx.lr = 0x8273AB70;
	sub_8273A178(ctx, base);
	// b 0x8273ab8c
	goto loc_8273AB8C;
loc_8273AB74:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826ddd90
	ctx.lr = 0x8273AB80;
	sub_826DDD90(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8273a360
	ctx.lr = 0x8273AB8C;
	sub_8273A360(ctx, base);
loc_8273AB8C:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273a95c
	if (cr6.eq) goto loc_8273A95C;
loc_8273AB98:
	// lwz r11,352(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8273a9b0
	if (cr6.lt) goto loc_8273A9B0;
loc_8273ABAC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8273ABC0"))) PPC_WEAK_FUNC(sub_8273ABC0);
PPC_FUNC_IMPL(__imp__sub_8273ABC0) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8273ABC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lis r9,6
	ctx.r9.s64 = 393216;
	// lis r8,6
	ctx.r8.s64 = 393216;
	// lfs f0,-5860(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -5860);
	f0.f64 = double(temp.f32);
	// ori r7,r9,16980
	ctx.r7.u64 = ctx.r9.u64 | 16980;
	// lfs f13,-5856(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -5856);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lwz r11,-10012(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10012);
	// ori r5,r8,16977
	ctx.r5.u64 = ctx.r8.u64 | 16977;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f0,-5852(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -5852);
	f0.f64 = double(temp.f32);
	// lwzx r30,r11,r7
	r30.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// lbzx r29,r11,r5
	r29.u64 = PPC_LOAD_U8(r11.u32 + ctx.r5.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// fadds f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 + f0.f64));
	// bge cr6,0x8273ac24
	if (!cr6.lt) goto loc_8273AC24;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8273aca8
	if (!cr6.eq) goto loc_8273ACA8;
loc_8273AC24:
	// lbz r10,180(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 180);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8273ac40
	if (!cr6.eq) goto loc_8273AC40;
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// blt cr6,0x8273ac44
	if (cr6.lt) goto loc_8273AC44;
loc_8273AC40:
	// li r11,1
	r11.s64 = 1;
loc_8273AC44:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273ac58
	if (cr6.eq) goto loc_8273AC58;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8273aca8
	if (!cr6.eq) goto loc_8273ACA8;
loc_8273AC58:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r9,-21536(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -21536);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8273aca8
	if (!cr6.eq) goto loc_8273ACA8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8273ac80
	if (!cr6.eq) goto loc_8273AC80;
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// blt cr6,0x8273ac84
	if (cr6.lt) goto loc_8273AC84;
loc_8273AC80:
	// li r11,1
	r11.s64 = 1;
loc_8273AC84:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273acb4
	if (cr6.eq) goto loc_8273ACB4;
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8273acb4
	if (cr6.lt) goto loc_8273ACB4;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r11,160(r31)
	PPC_STORE_U32(r31.u32 + 160, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8273ACA8:
	// stfs f0,164(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8273ACB4:
	// lfs f13,164(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f1
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f1.f64));
	// stfs f12,164(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x8273ace0
	if (!cr6.gt) goto loc_8273ACE0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8273a848
	ctx.lr = 0x8273ACD4;
	sub_8273A848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273acf4
	if (cr6.eq) goto loc_8273ACF4;
loc_8273ACE0:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lfs f13,164(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-21532(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -21532);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8273adec
	if (!cr6.gt) goto loc_8273ADEC;
loc_8273ACF4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmpwi cr6,r30,1500
	cr6.compare<int32_t>(r30.s32, 1500, xer);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,164(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// bge cr6,0x8273ad48
	if (!cr6.lt) goto loc_8273AD48;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8273ad48
	if (cr6.eq) goto loc_8273AD48;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8273AD24;
	sub_822A3998(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8273AD34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r4,r3,48
	ctx.r4.s64 = ctx.r3.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8273e210
	ctx.lr = 0x8273AD40;
	sub_8273E210(ctx, base);
	// stw r3,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r3.u32);
	// b 0x8273ad90
	goto loc_8273AD90;
loc_8273AD48:
	// lhz r10,148(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 148);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8273ad8c
	if (cr6.eq) goto loc_8273AD8C;
	// lwz r9,144(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// clrlwi r6,r10,16
	ctx.r6.u64 = ctx.r10.u32 & 0xFFFF;
loc_8273AD68:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// ble cr6,0x8273ad7c
	if (!cr6.gt) goto loc_8273AD7C;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
loc_8273AD7C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// blt cr6,0x8273ad68
	if (cr6.lt) goto loc_8273AD68;
loc_8273AD8C:
	// stw r7,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r7.u32);
loc_8273AD90:
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8273adc4
	if (cr6.lt) goto loc_8273ADC4;
	// lhz r10,156(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 156);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x8273adc4
	if (!cr6.lt) goto loc_8273ADC4;
	// lis r9,6
	ctx.r9.s64 = 393216;
	// lwz r10,-10012(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10012);
	// lwz r8,152(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r6,r9,16952
	ctx.r6.u64 = ctx.r9.u64 | 16952;
	// lfsx f0,r10,r6
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	f0.f64 = double(temp.f32);
	// stfsx f0,r7,r8
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, temp.u32);
loc_8273ADC4:
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8273adec
	if (cr6.lt) goto loc_8273ADEC;
	// lhz r10,148(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 148);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x8273adec
	if (!cr6.lt) goto loc_8273ADEC;
	// lwz r10,144(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r8,0
	ctx.r8.s64 = 0;
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8273ADEC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8273ADF4"))) PPC_WEAK_FUNC(sub_8273ADF4);
PPC_FUNC_IMPL(__imp__sub_8273ADF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273ADF8"))) PPC_WEAK_FUNC(sub_8273ADF8);
PPC_FUNC_IMPL(__imp__sub_8273ADF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-10012(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f0,8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// beq cr6,0x8273ae5c
	if (cr6.eq) goto loc_8273AE5C;
	// addis r3,r11,6
	ctx.r3.s64 = r11.s64 + 393216;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r3,16704
	ctx.r3.s64 = ctx.r3.s64 + 16704;
	// bl 0x822499f8
	ctx.lr = 0x8273AE44;
	sub_822499F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8273ae5c
	if (cr6.eq) goto loc_8273AE5C;
	// li r11,-1
	r11.s64 = -1;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, r11.u32);
	// stb r10,180(r3)
	PPC_STORE_U8(ctx.r3.u32 + 180, ctx.r10.u8);
loc_8273AE5C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273AE6C"))) PPC_WEAK_FUNC(sub_8273AE6C);
PPC_FUNC_IMPL(__imp__sub_8273AE6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273AE70"))) PPC_WEAK_FUNC(sub_8273AE70);
PPC_FUNC_IMPL(__imp__sub_8273AE70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f11,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,96(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x8273a7a0
	ctx.lr = 0x8273AEC4;
	sub_8273A7A0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8273AED4"))) PPC_WEAK_FUNC(sub_8273AED4);
PPC_FUNC_IMPL(__imp__sub_8273AED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8273AED8"))) PPC_WEAK_FUNC(sub_8273AED8);
PPC_FUNC_IMPL(__imp__sub_8273AED8) {
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
	// lis r11,-32140
	r11.s64 = -2106327040;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// addi r4,r11,-22680
	ctx.r4.s64 = r11.s64 + -22680;
	// addi r3,r10,-11012
	ctx.r3.s64 = ctx.r10.s64 + -11012;
	// bl 0x82554798
	ctx.lr = 0x8273AEF8;
	sub_82554798(ctx, base);
	// lis r9,-32140
	ctx.r9.s64 = -2106327040;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// addi r4,r9,-22656
	ctx.r4.s64 = ctx.r9.s64 + -22656;
	// addi r3,r8,-11052
	ctx.r3.s64 = ctx.r8.s64 + -11052;
	// bl 0x82554798
	ctx.lr = 0x8273AF0C;
	sub_82554798(ctx, base);
	// lis r7,-32140
	ctx.r7.s64 = -2106327040;
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// addi r4,r7,-21000
	ctx.r4.s64 = ctx.r7.s64 + -21000;
	// addi r3,r6,-11096
	ctx.r3.s64 = ctx.r6.s64 + -11096;
	// bl 0x82554798
	ctx.lr = 0x8273AF20;
	sub_82554798(ctx, base);
	// lis r5,-32140
	ctx.r5.s64 = -2106327040;
	// lis r3,-32243
	ctx.r3.s64 = -2113077248;
	// addi r4,r5,-20880
	ctx.r4.s64 = ctx.r5.s64 + -20880;
	// addi r3,r3,-11140
	ctx.r3.s64 = ctx.r3.s64 + -11140;
	// bl 0x82554798
	ctx.lr = 0x8273AF34;
	sub_82554798(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

