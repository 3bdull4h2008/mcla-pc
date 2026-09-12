#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_823D2924"))) PPC_WEAK_FUNC(sub_823D2924);
PPC_FUNC_IMPL(__imp__sub_823D2924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D2928"))) PPC_WEAK_FUNC(sub_823D2928);
PPC_FUNC_IMPL(__imp__sub_823D2928) {
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
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-12720(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12720);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D2958;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d296c
	if (cr6.eq) goto loc_823D296C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
loc_823D296C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d2980
	if (cr6.eq) goto loc_823D2980;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_823D2980:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// bne cr6,0x823d29b4
	if (!cr6.eq) goto loc_823D29B4;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x823d29b4
	if (!cr6.eq) goto loc_823D29B4;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,0,5,3
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFF7FFFFFF;
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
loc_823D29B4:
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32195
	ctx.r10.s64 = -2109931520;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lis r9,-32195
	ctx.r9.s64 = -2109931520;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// lwz r3,-12720(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12720);
	// addi r6,r10,6536
	ctx.r6.s64 = ctx.r10.s64 + 6536;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r5,r9,6528
	ctx.r5.s64 = ctx.r9.s64 + 6528;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823D29EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-12720(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12720);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823D2A00;
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

__attribute__((alias("__imp__sub_823D2A18"))) PPC_WEAK_FUNC(sub_823D2A18);
PPC_FUNC_IMPL(__imp__sub_823D2A18) {
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
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// beq cr6,0x823d2a98
	if (cr6.eq) goto loc_823D2A98;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d2a7c
	if (cr6.eq) goto loc_823D2A7C;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823d2a70
	if (!cr6.eq) goto loc_823D2A70;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823d2a70
	if (!cr6.eq) goto loc_823D2A70;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x823d2a74
	if (!cr6.eq) goto loc_823D2A74;
loc_823D2A70:
	// li r11,1
	r11.s64 = 1;
loc_823D2A74:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// b 0x823d2a80
	goto loc_823D2A80;
loc_823D2A7C:
	// li r11,0
	r11.s64 = 0;
loc_823D2A80:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d2a94
	if (cr6.eq) goto loc_823D2A94;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d2928
	ctx.lr = 0x823D2A94;
	sub_823D2928(ctx, base);
loc_823D2A94:
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
loc_823D2A98:
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

__attribute__((alias("__imp__sub_823D2AB0"))) PPC_WEAK_FUNC(sub_823D2AB0);
PPC_FUNC_IMPL(__imp__sub_823D2AB0) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x823D2AB8;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r29,44(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 44);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823d2e78
	if (cr6.eq) goto loc_823D2E78;
	// addi r4,r27,48
	ctx.r4.s64 = r27.s64 + 48;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823cf340
	ctx.lr = 0x823D2ADC;
	sub_823CF340(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r31,r11,-15992
	r31.s64 = r11.s64 + -15992;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82137a08
	ctx.lr = 0x823D2AFC;
	sub_82137A08(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r30,r11,-15996
	r30.s64 = r11.s64 + -15996;
	// addi r5,r10,-27188
	ctx.r5.s64 = ctx.r10.s64 + -27188;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82137a08
	ctx.lr = 0x823D2B1C;
	sub_82137A08(ctx, base);
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r3,r9,30576
	ctx.r3.s64 = ctx.r9.s64 + 30576;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// bl 0x821ca778
	ctx.lr = 0x823D2B30;
	sub_821CA778(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x823d2b64
	if (!cr6.eq) goto loc_823D2B64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r6,r11,-16016
	ctx.r6.s64 = r11.s64 + -16016;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82137a08
	ctx.lr = 0x823D2B58;
	sub_82137A08(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823cf2e8
	ctx.lr = 0x823D2B64;
	sub_823CF2E8(ctx, base);
loc_823D2B64:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d2e5c
	if (cr6.eq) goto loc_823D2E5C;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lwz r3,-4960(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -4960);
	// bl 0x823cbad0
	ctx.lr = 0x823D2B80;
	sub_823CBAD0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d2e68
	if (cr6.eq) goto loc_823D2E68;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,-16068
	ctx.r3.s64 = r11.s64 + -16068;
	// bl 0x82130000
	ctx.lr = 0x823D2B9C;
	sub_82130000(ctx, base);
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x823D2BA4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d2bb4
	if (cr6.eq) goto loc_823D2BB4;
	// bl 0x823d2270
	ctx.lr = 0x823D2BB0;
	sub_823D2270(ctx, base);
	// b 0x823d2bb8
	goto loc_823D2BB8;
loc_823D2BB4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823D2BB8:
	// stw r3,24(r27)
	PPC_STORE_U32(r27.u32 + 24, ctx.r3.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823d27d0
	ctx.lr = 0x823D2BC4;
	sub_823D27D0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,24(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// lfs f31,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823d2620
	ctx.lr = 0x823D2BDC;
	sub_823D2620(ctx, base);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r7,r9,-11788
	ctx.r7.s64 = ctx.r9.s64 + -11788;
	// stb r8,68(r27)
	PPC_STORE_U8(r27.u32 + 68, ctx.r8.u8);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d2c34
	if (!cr6.eq) goto loc_823D2C34;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// ble cr6,0x823d2c10
	if (!cr6.gt) goto loc_823D2C10;
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x823d2c14
	if (cr6.lt) goto loc_823D2C14;
loc_823D2C10:
	// li r11,0
	r11.s64 = 0;
loc_823D2C14:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d2c34
	if (!cr6.eq) goto loc_823D2C34;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r4,r11,-16072
	ctx.r4.s64 = r11.s64 + -16072;
	// bl 0x823cf2e8
	ctx.lr = 0x823D2C30;
	sub_823CF2E8(ctx, base);
	// b 0x823d2c38
	goto loc_823D2C38;
loc_823D2C34:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823D2C38:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d2c94
	if (cr6.eq) goto loc_823D2C94;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,-4960(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -4960);
	// bl 0x823cbc80
	ctx.lr = 0x823D2C50;
	sub_823CBC80(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d2c94
	if (cr6.eq) goto loc_823D2C94;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x823D2C64;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d2c74
	if (cr6.eq) goto loc_823D2C74;
	// bl 0x823d22d0
	ctx.lr = 0x823D2C70;
	sub_823D22D0(ctx, base);
	// b 0x823d2c78
	goto loc_823D2C78;
loc_823D2C74:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823D2C78:
	// stw r3,28(r27)
	PPC_STORE_U32(r27.u32 + 28, ctx.r3.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823d2a18
	ctx.lr = 0x823D2C84;
	sub_823D2A18(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,28(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823d2868
	ctx.lr = 0x823D2C94;
	sub_823D2868(ctx, base);
loc_823D2C94:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x823d2cac
	if (!cr6.gt) goto loc_823D2CAC;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x823d2cb0
	if (cr6.lt) goto loc_823D2CB0;
loc_823D2CAC:
	// li r11,0
	r11.s64 = 0;
loc_823D2CB0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d2e68
	if (cr6.eq) goto loc_823D2E68;
	// lbz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 88);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d2cd4
	if (cr6.eq) goto loc_823D2CD4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r28,r11,21364
	r28.s64 = r11.s64 + 21364;
	// b 0x823d2cdc
	goto loc_823D2CDC;
loc_823D2CD4:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r28,r11,-32760
	r28.s64 = r11.s64 + -32760;
loc_823D2CDC:
	// lbz r10,89(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 89);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d2cf4
	if (cr6.eq) goto loc_823D2CF4;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r29,r11,-29828
	r29.s64 = r11.s64 + -29828;
	// b 0x823d2cfc
	goto loc_823D2CFC;
loc_823D2CF4:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r29,r11,-29836
	r29.s64 = r11.s64 + -29836;
loc_823D2CFC:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r11,-29860
	ctx.r4.s64 = r11.s64 + -29860;
	// bl 0x823dd800
	ctx.lr = 0x823D2D10;
	sub_823DD800(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x823d2d20
	if (!cr6.eq) goto loc_823D2D20;
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// b 0x823d2d38
	goto loc_823D2D38;
loc_823D2D20:
	// lhz r11,96(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 96);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// ble cr6,0x823d2d30
	if (!cr6.gt) goto loc_823D2D30;
	// li r11,3
	r11.s64 = 3;
loc_823D2D30:
	// lwz r10,92(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
loc_823D2D38:
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// bl 0x823b7c68
	ctx.lr = 0x823D2D44;
	sub_823B7C68(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// addi r31,r11,-16108
	r31.s64 = r11.s64 + -16108;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82137a08
	ctx.lr = 0x823D2D68;
	sub_82137A08(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r30,r11,-27184
	r30.s64 = r11.s64 + -27184;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823cf2e8
	ctx.lr = 0x823D2D7C;
	sub_823CF2E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d2dcc
	if (!cr6.eq) goto loc_823D2DCC;
	// lbz r10,90(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 90);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d2da0
	if (cr6.eq) goto loc_823D2DA0;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r8,r11,-29576
	ctx.r8.s64 = r11.s64 + -29576;
	// b 0x823d2da8
	goto loc_823D2DA8;
loc_823D2DA0:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r8,r11,23472
	ctx.r8.s64 = r11.s64 + 23472;
loc_823D2DA8:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82137a08
	ctx.lr = 0x823D2DC0;
	sub_82137A08(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823cf2e8
	ctx.lr = 0x823D2DCC;
	sub_823CF2E8(ctx, base);
loc_823D2DCC:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-10800
	ctx.r10.s64 = r11.s64 + -10800;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d2de4
	if (cr6.eq) goto loc_823D2DE4;
	// li r3,0
	ctx.r3.s64 = 0;
loc_823D2DE4:
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d2e44
	if (cr6.eq) goto loc_823D2E44;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,-4960(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -4960);
	// bl 0x823cbba8
	ctx.lr = 0x823D2DFC;
	sub_823CBBA8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d2e68
	if (cr6.eq) goto loc_823D2E68;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x823D2E10;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d2e20
	if (cr6.eq) goto loc_823D2E20;
	// bl 0x823c2188
	ctx.lr = 0x823D2E1C;
	sub_823C2188(ctx, base);
	// b 0x823d2e24
	goto loc_823D2E24;
loc_823D2E20:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823D2E24:
	// stw r3,32(r27)
	PPC_STORE_U32(r27.u32 + 32, ctx.r3.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823c5bc0
	ctx.lr = 0x823D2E30;
	sub_823C5BC0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,32(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 32);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823c5a10
	ctx.lr = 0x823D2E40;
	sub_823C5A10(ctx, base);
	// b 0x823d2e68
	goto loc_823D2E68;
loc_823D2E44:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d2e68
	if (!cr6.eq) goto loc_823D2E68;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r11,-16176
	ctx.r3.s64 = r11.s64 + -16176;
	// b 0x823d2e64
	goto loc_823D2E64;
loc_823D2E5C:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-16248
	ctx.r3.s64 = r11.s64 + -16248;
loc_823D2E64:
	// bl 0x821bd618
	ctx.lr = 0x823D2E68;
	sub_821BD618(ctx, base);
loc_823D2E68:
	// li r11,0
	r11.s64 = 0;
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// stw r11,44(r27)
	PPC_STORE_U32(r27.u32 + 44, r11.u32);
	// bl 0x82130588
	ctx.lr = 0x823D2E78;
	sub_82130588(ctx, base);
loc_823D2E78:
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823D2E84"))) PPC_WEAK_FUNC(sub_823D2E84);
PPC_FUNC_IMPL(__imp__sub_823D2E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D2E88"))) PPC_WEAK_FUNC(sub_823D2E88);
PPC_FUNC_IMPL(__imp__sub_823D2E88) {
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
	ctx.lr = 0x823D2E90;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r29,r28
	r29.u64 = r28.u64;
	// lhz r11,76(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// stw r28,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r28.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d2eec
	if (cr6.eq) goto loc_823D2EEC;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_823D2EB4:
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d2ed8
	if (cr6.eq) goto loc_823D2ED8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D2ED8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D2ED8:
	// lhz r11,76(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x823d2eb4
	if (cr6.lt) goto loc_823D2EB4;
loc_823D2EEC:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x82130588
	ctx.lr = 0x823D2EF4;
	sub_82130588(ctx, base);
	// stw r28,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r28.u32);
	// sth r28,76(r31)
	PPC_STORE_U16(r31.u32 + 76, r28.u16);
	// sth r28,78(r31)
	PPC_STORE_U16(r31.u32 + 78, r28.u16);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d2f20
	if (cr6.eq) goto loc_823D2F20;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D2F20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D2F20:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// stw r28,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r28.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d2f44
	if (cr6.eq) goto loc_823D2F44;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D2F44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D2F44:
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r28,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r28.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d2f7c
	if (cr6.eq) goto loc_823D2F7C;
	// bl 0x823d2928
	ctx.lr = 0x823D2F58;
	sub_823D2928(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d2f78
	if (cr6.eq) goto loc_823D2F78;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D2F78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D2F78:
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
loc_823D2F7C:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d2fb0
	if (cr6.eq) goto loc_823D2FB0;
	// bl 0x823d26e0
	ctx.lr = 0x823D2F8C;
	sub_823D26E0(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d2fac
	if (cr6.eq) goto loc_823D2FAC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D2FAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D2FAC:
	// stw r28,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r28.u32);
loc_823D2FB0:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d2fe4
	if (cr6.eq) goto loc_823D2FE4;
	// bl 0x823c5ad0
	ctx.lr = 0x823D2FC0;
	sub_823C5AD0(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d2fe0
	if (cr6.eq) goto loc_823D2FE0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D2FE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D2FE0:
	// stw r28,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r28.u32);
loc_823D2FE4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823D2FEC"))) PPC_WEAK_FUNC(sub_823D2FEC);
PPC_FUNC_IMPL(__imp__sub_823D2FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D2FF0"))) PPC_WEAK_FUNC(sub_823D2FF0);
PPC_FUNC_IMPL(__imp__sub_823D2FF0) {
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
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r9,r10,-16280
	ctx.r9.s64 = ctx.r10.s64 + -16280;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d3050
	if (cr6.eq) goto loc_823D3050;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823d3044
	if (!cr6.eq) goto loc_823D3044;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823d3044
	if (!cr6.eq) goto loc_823D3044;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x823d3048
	if (!cr6.eq) goto loc_823D3048;
loc_823D3044:
	// li r11,1
	r11.s64 = 1;
loc_823D3048:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// b 0x823d3054
	goto loc_823D3054;
loc_823D3050:
	// li r11,0
	r11.s64 = 0;
loc_823D3054:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d3068
	if (cr6.eq) goto loc_823D3068;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d26e0
	ctx.lr = 0x823D3068;
	sub_823D26E0(ctx, base);
loc_823D3068:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r10,r11,-27808
	ctx.r10.s64 = r11.s64 + -27808;
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

__attribute__((alias("__imp__sub_823D3088"))) PPC_WEAK_FUNC(sub_823D3088);
PPC_FUNC_IMPL(__imp__sub_823D3088) {
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
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r9,r10,-16264
	ctx.r9.s64 = ctx.r10.s64 + -16264;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d30e8
	if (cr6.eq) goto loc_823D30E8;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823d30dc
	if (!cr6.eq) goto loc_823D30DC;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823d30dc
	if (!cr6.eq) goto loc_823D30DC;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x823d30e0
	if (!cr6.eq) goto loc_823D30E0;
loc_823D30DC:
	// li r11,1
	r11.s64 = 1;
loc_823D30E0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// b 0x823d30ec
	goto loc_823D30EC;
loc_823D30E8:
	// li r11,0
	r11.s64 = 0;
loc_823D30EC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d3100
	if (cr6.eq) goto loc_823D3100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d2928
	ctx.lr = 0x823D3100;
	sub_823D2928(ctx, base);
loc_823D3100:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r10,r11,-27808
	ctx.r10.s64 = r11.s64 + -27808;
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

__attribute__((alias("__imp__sub_823D3120"))) PPC_WEAK_FUNC(sub_823D3120);
PPC_FUNC_IMPL(__imp__sub_823D3120) {
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
	// bl 0x823d2ff0
	ctx.lr = 0x823D3140;
	sub_823D2FF0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d3158
	if (cr6.eq) goto loc_823D3158;
	// bl 0x82130588
	ctx.lr = 0x823D3154;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823D3158:
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

__attribute__((alias("__imp__sub_823D3170"))) PPC_WEAK_FUNC(sub_823D3170);
PPC_FUNC_IMPL(__imp__sub_823D3170) {
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
	// bl 0x823d3088
	ctx.lr = 0x823D3190;
	sub_823D3088(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d31a8
	if (cr6.eq) goto loc_823D31A8;
	// bl 0x82130588
	ctx.lr = 0x823D31A4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823D31A8:
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

__attribute__((alias("__imp__sub_823D31C0"))) PPC_WEAK_FUNC(sub_823D31C0);
PPC_FUNC_IMPL(__imp__sub_823D31C0) {
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
	ctx.lr = 0x823D31C8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x823D31D8;
	sub_82130528(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x823d3268
	if (!cr6.gt) goto loc_823D3268;
	// mr r31,r24
	r31.u64 = r24.u64;
	// mr r26,r30
	r26.u64 = r30.u64;
	// li r25,0
	r25.s64 = 0;
loc_823D31F0:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d325c
	if (cr6.eq) goto loc_823D325C;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d3258
	if (cr6.eq) goto loc_823D3258;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823d3258
	if (cr6.eq) goto loc_823D3258;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x823D3224;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823d3258
	if (cr6.eq) goto loc_823D3258;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x823D3238;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d325c
	if (cr6.eq) goto loc_823D325C;
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x823d21d8
	ctx.lr = 0x823D3254;
	sub_823D21D8(ctx, base);
	// b 0x823d325c
	goto loc_823D325C;
loc_823D3258:
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
loc_823D325C:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x823d31f0
	if (!cr0.eq) goto loc_823D31F0;
loc_823D3268:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823D3274"))) PPC_WEAK_FUNC(sub_823D3274);
PPC_FUNC_IMPL(__imp__sub_823D3274) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D3278"))) PPC_WEAK_FUNC(sub_823D3278);
PPC_FUNC_IMPL(__imp__sub_823D3278) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// bl 0x821c8fe0
	ctx.lr = 0x823D3298;
	sub_821C8FE0(ctx, base);
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d32b8
	if (cr6.eq) goto loc_823D32B8;
loc_823D32A4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d2ab0
	ctx.lr = 0x823D32AC;
	sub_823D2AB0(ctx, base);
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823d32a4
	if (!cr6.eq) goto loc_823D32A4;
loc_823D32B8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D32C0;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_823D32D4"))) PPC_WEAK_FUNC(sub_823D32D4);
PPC_FUNC_IMPL(__imp__sub_823D32D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D32D8"))) PPC_WEAK_FUNC(sub_823D32D8);
PPC_FUNC_IMPL(__imp__sub_823D32D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d3304
	if (cr6.eq) goto loc_823D3304;
	// bl 0x823d31c0
	ctx.lr = 0x823D3300;
	sub_823D31C0(ctx, base);
	// b 0x823d3308
	goto loc_823D3308;
loc_823D3304:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823D3308:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
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

__attribute__((alias("__imp__sub_823D3328"))) PPC_WEAK_FUNC(sub_823D3328);
PPC_FUNC_IMPL(__imp__sub_823D3328) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-16296
	ctx.r10.s64 = r11.s64 + -16296;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x823d2e88
	ctx.lr = 0x823D3354;
	sub_823D2E88(ctx, base);
	// lhz r9,78(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 78);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823d3368
	if (cr6.eq) goto loc_823D3368;
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x82130588
	ctx.lr = 0x823D3368;
	sub_82130588(ctx, base);
loc_823D3368:
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// bl 0x82130588
	ctx.lr = 0x823D3370;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822e6bc0
	ctx.lr = 0x823D3378;
	sub_822E6BC0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d3390
	if (cr6.eq) goto loc_823D3390;
	// bl 0x82130588
	ctx.lr = 0x823D338C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823D3390:
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

__attribute__((alias("__imp__sub_823D33A8"))) PPC_WEAK_FUNC(sub_823D33A8);
PPC_FUNC_IMPL(__imp__sub_823D33A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	ctx.lr = 0x823D33B0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lbz r11,69(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 69);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d33dc
	if (cr6.eq) goto loc_823D33DC;
	// li r11,1
	r11.s64 = 1;
	// stb r11,0(r24)
	PPC_STORE_U8(r24.u32 + 0, r11.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_823D33DC:
	// lbz r11,68(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d3710
	if (cr6.eq) goto loc_823D3710;
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// li r25,0
	r25.s64 = 0;
	// li r26,1
	r26.s64 = 1;
	// lis r9,12288
	ctx.r9.s64 = 805306368;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d3418
	if (cr6.eq) goto loc_823D3418;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r11,0,2,3
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// beq cr6,0x823d341c
	if (cr6.eq) goto loc_823D341C;
loc_823D3418:
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
loc_823D341C:
	// lwz r11,28(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d3458
	if (cr6.eq) goto loc_823D3458;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d344c
	if (cr6.eq) goto loc_823D344C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r10,r11,0,2,3
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// mr r11,r26
	r11.u64 = r26.u64;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// beq cr6,0x823d3450
	if (cr6.eq) goto loc_823D3450;
loc_823D344C:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823D3450:
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// b 0x823d345c
	goto loc_823D345C;
loc_823D3458:
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
loc_823D345C:
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d3494
	if (cr6.eq) goto loc_823D3494;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d3488
	if (cr6.eq) goto loc_823D3488;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r7,r11,0,2,3
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// mr r11,r26
	r11.u64 = r26.u64;
	// cmpw cr6,r7,r9
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, xer);
	// beq cr6,0x823d348c
	if (cr6.eq) goto loc_823D348C;
loc_823D3488:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823D348C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// b 0x823d3498
	goto loc_823D3498;
loc_823D3494:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_823D3498:
	// clrlwi r9,r8,24
	ctx.r9.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823d3704
	if (cr6.eq) goto loc_823D3704;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d3704
	if (cr6.eq) goto loc_823D3704;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d3704
	if (cr6.eq) goto loc_823D3704;
	// stb r25,68(r29)
	PPC_STORE_U8(r29.u32 + 68, r25.u8);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823d1240
	ctx.lr = 0x823D34C8;
	sub_823D1240(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823d3504
	if (!cr6.eq) goto loc_823D3504;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x823d34e8
	if (!cr6.gt) goto loc_823D34E8;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// mr r11,r26
	r11.u64 = r26.u64;
	// blt cr6,0x823d34ec
	if (cr6.lt) goto loc_823D34EC;
loc_823D34E8:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823D34EC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d3504
	if (cr6.eq) goto loc_823D3504;
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823d1c40
	ctx.lr = 0x823D3504;
	sub_823D1C40(ctx, base);
loc_823D3504:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-10820
	ctx.r10.s64 = r11.s64 + -10820;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d35cc
	if (!cr6.eq) goto loc_823D35CC;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x823D3520;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d3530
	if (cr6.eq) goto loc_823D3530;
	// bl 0x8239e7e8
	ctx.lr = 0x823D352C;
	sub_8239E7E8(ctx, base);
	// b 0x823d3534
	goto loc_823D3534;
loc_823D3530:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_823D3534:
	// stw r3,36(r29)
	PPC_STORE_U32(r29.u32 + 36, ctx.r3.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8239ea58
	ctx.lr = 0x823D3544;
	sub_8239EA58(ctx, base);
	// addi r28,r29,72
	r28.s64 = r29.s64 + 72;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823d32d8
	ctx.lr = 0x823D3554;
	sub_823D32D8(ctx, base);
	// mr r30,r25
	r30.u64 = r25.u64;
loc_823D3558:
	// li r3,144
	ctx.r3.s64 = 144;
	// bl 0x82130528
	ctx.lr = 0x823D3560;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d3574
	if (cr6.eq) goto loc_823D3574;
	// bl 0x823cfbd8
	ctx.lr = 0x823D356C;
	sub_823CFBD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x823d3578
	goto loc_823D3578;
loc_823D3574:
	// mr r31,r25
	r31.u64 = r25.u64;
loc_823D3578:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,36(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// bl 0x8239e690
	ctx.lr = 0x823D3584;
	sub_8239E690(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// stb r26,28(r31)
	PPC_STORE_U8(r31.u32 + 28, r26.u8);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r8.u16);
	// stwx r31,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r31.u32);
	// bl 0x822e6c50
	ctx.lr = 0x823D35B0;
	sub_822E6C50(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,16
	cr6.compare<int32_t>(r30.s32, 16, xer);
	// blt cr6,0x823d3558
	if (cr6.lt) goto loc_823D3558;
	// stb r26,69(r29)
	PPC_STORE_U8(r29.u32 + 69, r26.u8);
	// stb r26,0(r24)
	PPC_STORE_U8(r24.u32 + 0, r26.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_823D35CC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x823d35e4
	if (!cr6.gt) goto loc_823D35E4;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// mr r11,r26
	r11.u64 = r26.u64;
	// blt cr6,0x823d35e8
	if (cr6.lt) goto loc_823D35E8;
loc_823D35E4:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823D35E8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d35fc
	if (!cr6.eq) goto loc_823D35FC;
	// li r27,2
	r27.s64 = 2;
	// b 0x823d361c
	goto loc_823D361C;
loc_823D35FC:
	// lbz r11,8(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d3618
	if (cr6.eq) goto loc_823D3618;
	// lbz r11,10(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 10);
	// li r27,16
	r27.s64 = 16;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d361c
	if (cr6.eq) goto loc_823D361C;
loc_823D3618:
	// li r27,8
	r27.s64 = 8;
loc_823D361C:
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x823D3624;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d3638
	if (cr6.eq) goto loc_823D3638;
	// bl 0x8239e7e8
	ctx.lr = 0x823D3630;
	sub_8239E7E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x823d363c
	goto loc_823D363C;
loc_823D3638:
	// mr r31,r25
	r31.u64 = r25.u64;
loc_823D363C:
	// stw r31,36(r29)
	PPC_STORE_U32(r29.u32 + 36, r31.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823d1240
	ctx.lr = 0x823D3648;
	sub_823D1240(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823d12a8
	ctx.lr = 0x823D3654;
	sub_823D12A8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x823d11e8
	ctx.lr = 0x823D3664;
	sub_823D11E8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// bl 0x8239eb08
	ctx.lr = 0x823D3674;
	sub_8239EB08(ctx, base);
	// addi r28,r29,72
	r28.s64 = r29.s64 + 72;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823d32d8
	ctx.lr = 0x823D3684;
	sub_823D32D8(ctx, base);
	// mr r30,r25
	r30.u64 = r25.u64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x823d36f4
	if (!cr6.gt) goto loc_823D36F4;
loc_823D3690:
	// li r3,144
	ctx.r3.s64 = 144;
	// bl 0x82130528
	ctx.lr = 0x823D3698;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d36ac
	if (cr6.eq) goto loc_823D36AC;
	// bl 0x823cfbd8
	ctx.lr = 0x823D36A4;
	sub_823CFBD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x823d36b0
	goto loc_823D36B0;
loc_823D36AC:
	// mr r31,r25
	r31.u64 = r25.u64;
loc_823D36B0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,36(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// bl 0x8239e690
	ctx.lr = 0x823D36BC;
	sub_8239E690(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// stb r26,28(r31)
	PPC_STORE_U8(r31.u32 + 28, r26.u8);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// sth r8,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r8.u16);
	// stwx r31,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r31.u32);
	// bl 0x822e6c50
	ctx.lr = 0x823D36E8;
	sub_822E6C50(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// blt cr6,0x823d3690
	if (cr6.lt) goto loc_823D3690;
loc_823D36F4:
	// stb r26,69(r29)
	PPC_STORE_U8(r29.u32 + 69, r26.u8);
	// stb r26,0(r24)
	PPC_STORE_U8(r24.u32 + 0, r26.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_823D3704:
	// stb r25,0(r24)
	PPC_STORE_U8(r24.u32 + 0, r25.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_823D3710:
	// stw r5,44(r29)
	PPC_STORE_U32(r29.u32 + 44, ctx.r5.u32);
	// addi r11,r29,44
	r11.s64 = r29.s64 + 44;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x823c92e0
	ctx.lr = 0x823D3724;
	sub_823C92E0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823D372C"))) PPC_WEAK_FUNC(sub_823D372C);
PPC_FUNC_IMPL(__imp__sub_823D372C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D3730"))) PPC_WEAK_FUNC(sub_823D3730);
PPC_FUNC_IMPL(__imp__sub_823D3730) {
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
	ctx.lr = 0x823D3738;
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x823D3754;
	sub_821C8FE0(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// stb r31,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r31.u8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8239e6b0
	ctx.lr = 0x823D376C;
	sub_8239E6B0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r5,r11,10372
	ctx.r5.s64 = r11.s64 + 10372;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x823D3788;
	sub_82137A08(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822e6a80
	ctx.lr = 0x823D3794;
	sub_822E6A80(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d37c0
	if (cr6.eq) goto loc_823D37C0;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x823d33a8
	ctx.lr = 0x823D37AC;
	sub_823D33A8(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x823D37B4;
	sub_821C9030(ctx, base);
	// lbz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x823d9248
	return;
loc_823D37C0:
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x82130528
	ctx.lr = 0x823D37C8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d37d8
	if (cr6.eq) goto loc_823D37D8;
	// bl 0x823d1148
	ctx.lr = 0x823D37D4;
	sub_823D1148(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_823D37D8:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822e6c18
	ctx.lr = 0x823D37E4;
	sub_822E6C18(ctx, base);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d33a8
	ctx.lr = 0x823D37F8;
	sub_823D33A8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822e6ad0
	ctx.lr = 0x823D3804;
	sub_822E6AD0(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x823D380C;
	sub_821C9030(ctx, base);
	// lbz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823D3818"))) PPC_WEAK_FUNC(sub_823D3818);
PPC_FUNC_IMPL(__imp__sub_823D3818) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d3830
	if (cr6.eq) goto loc_823D3830;
	// lbz r11,101(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 101);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823D3830:
	// li r11,1
	r11.s64 = 1;
	// stb r11,100(r3)
	PPC_STORE_U8(ctx.r3.u32 + 100, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D383C"))) PPC_WEAK_FUNC(sub_823D383C);
PPC_FUNC_IMPL(__imp__sub_823D383C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D3840"))) PPC_WEAK_FUNC(sub_823D3840);
PPC_FUNC_IMPL(__imp__sub_823D3840) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-15620
	ctx.r9.s64 = r11.s64 + -15620;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x823D3878;
	sub_822E5148(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-27436(r8)
	PPC_STORE_U32(ctx.r8.u32 + -27436, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x823D388C;
	sub_822E6940(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823d38a4
	if (cr6.eq) goto loc_823D38A4;
	// bl 0x82130588
	ctx.lr = 0x823D38A0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823D38A4:
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

__attribute__((alias("__imp__sub_823D38BC"))) PPC_WEAK_FUNC(sub_823D38BC);
PPC_FUNC_IMPL(__imp__sub_823D38BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D38C0"))) PPC_WEAK_FUNC(sub_823D38C0);
PPC_FUNC_IMPL(__imp__sub_823D38C0) {
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
	ctx.lr = 0x823D38C8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d394c
	if (cr6.eq) goto loc_823D394C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c95a0
	ctx.lr = 0x823D38E8;
	sub_821C95A0(ctx, base);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// divwu r9,r3,r11
	ctx.r9.u32 = ctx.r3.u32 / r11.u32;
	// twllei r11,0
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r6,r10
	r31.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d394c
	if (cr6.eq) goto loc_823D394C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r29,r11,3998
	r29.s64 = r11.s64 + 3998;
loc_823D3918:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d392c
	if (cr6.eq) goto loc_823D392C;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x823d3930
	goto loc_823D3930;
loc_823D392C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
loc_823D3930:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823db730
	ctx.lr = 0x823D3938;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823d3958
	if (cr6.eq) goto loc_823D3958;
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823d3918
	if (!cr6.eq) goto loc_823D3918;
loc_823D394C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823D3958:
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823D3964"))) PPC_WEAK_FUNC(sub_823D3964);
PPC_FUNC_IMPL(__imp__sub_823D3964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D3968"))) PPC_WEAK_FUNC(sub_823D3968);
PPC_FUNC_IMPL(__imp__sub_823D3968) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x823D3970;
	// stfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f30.u64);
	// stfd f31,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// li r12,-144
	r12.s64 = -144;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-128
	r12.s64 = -128;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r26,-32120
	r26.s64 = -2105016320;
	// rlwinm r22,r30,0,23,27
	r22.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1F0;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// beq cr6,0x823d39b0
	if (cr6.eq) goto loc_823D39B0;
	// lwz r11,-7572(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -7572);
	// lbz r11,14546(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 14546);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d3dd4
	if (!cr6.eq) goto loc_823D3DD4;
loc_823D39B0:
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d3dd4
	if (cr6.eq) goto loc_823D3DD4;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r9,12288
	ctx.r9.s64 = 805306368;
	// rlwinm r8,r10,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x30000000;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// bne cr6,0x823d3dd4
	if (!cr6.eq) goto loc_823D3DD4;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x823d3dd4
	if (!cr6.eq) goto loc_823D3DD4;
	// lwz r25,0(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r3,r25,16
	ctx.r3.s64 = r25.s64 + 16;
	// bl 0x82612bf0
	ctx.lr = 0x823D39E8;
	sub_82612BF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d3dd4
	if (!cr6.eq) goto loc_823D3DD4;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r10,-31280
	ctx.r4.s64 = ctx.r10.s64 + -31280;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x823D3A08;
	sub_8217C088(ctx, base);
	// vspltisw128 v126,0
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r28,-32120
	r28.s64 = -2105016320;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// vupkd3d128 v127,v126,4
	temp.f32 = 3.0f;
	temp.s32 += v126.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v126.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v127 = vTemp;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lis r23,-32124
	r23.s64 = -2105278464;
	// lwz r4,-8092(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// li r11,1
	r11.s64 = 1;
	// rlwinm r5,r30,0,18,18
	ctx.r5.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x2000;
	// stvx128 v126,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v63,v127,234
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x15));
	// vpermwi128 v62,v127,186
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x45));
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// vpermwi128 v61,v127,174
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x51));
	// stb r11,-13430(r23)
	PPC_STORE_U8(r23.u32 + -13430, r11.u8);
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,360(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 360);
	// rlwinm r24,r3,21,31,31
	r24.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 21) & 0x1;
	// bne cr6,0x823d3b20
	if (!cr6.eq) goto loc_823D3B20;
	// rlwinm r11,r30,0,17,17
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x4000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823d3ad0
	if (!cr6.eq) goto loc_823D3AD0;
	// lis r12,2
	r12.s64 = 131072;
	// ori r12,r12,4606
	r12.u64 = r12.u64 | 4606;
	// and r11,r30,r12
	r11.u64 = r30.u64 & r12.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823d3b48
	if (!cr6.eq) goto loc_823D3B48;
	// cmpwi cr6,r30,1024
	cr6.compare<int32_t>(r30.s32, 1024, xer);
	// bne cr6,0x823d3aa0
	if (!cr6.eq) goto loc_823D3AA0;
	// lwz r3,-7572(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x823D3A94;
	sub_82205248(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d3b48
	if (!cr6.eq) goto loc_823D3B48;
loc_823D3AA0:
	// rlwinm r11,r30,0,11,13
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1C0000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d3dcc
	if (cr6.eq) goto loc_823D3DCC;
	// lis r11,4
	r11.s64 = 262144;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// beq cr6,0x823d3b20
	if (cr6.eq) goto loc_823D3B20;
	// lis r11,8
	r11.s64 = 524288;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// beq cr6,0x823d3af8
	if (cr6.eq) goto loc_823D3AF8;
	// lis r11,16
	r11.s64 = 1048576;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bne cr6,0x823d3dcc
	if (!cr6.eq) goto loc_823D3DCC;
loc_823D3AD0:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D3AF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x823d3dcc
	goto loc_823D3DCC;
loc_823D3AF8:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D3B1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x823d3dcc
	goto loc_823D3DCC;
loc_823D3B20:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D3B44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x823d3dcc
	goto loc_823D3DCC;
loc_823D3B48:
	// rlwinm r11,r30,0,28,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xE;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d3b60
	if (cr6.eq) goto loc_823D3B60;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82311450
	ctx.lr = 0x823D3B60;
	sub_82311450(ctx, base);
loc_823D3B60:
	// vpermwi128 v60,v127,234
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x15));
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// vpermwi128 v59,v127,186
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x45));
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// vpermwi128 v58,v127,174
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x51));
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// rlwinm r5,r30,0,30,30
	ctx.r5.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x2;
	// stvx128 v126,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// lfs f31,3732(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3732);
	f31.f64 = double(temp.f32);
	// lfs f30,14192(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14192);
	f30.f64 = double(temp.f32);
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x823d3bbc
	if (cr6.eq) goto loc_823D3BBC;
	// lwz r11,-8092(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// lfs f0,340(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 340);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// stfs f30,164(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f13,196(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
loc_823D3BBC:
	// lwz r11,-8092(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// lbz r10,393(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 393);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823d3bf0
	if (!cr6.eq) goto loc_823D3BF0;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D3BF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D3BF0:
	// rlwinm r29,r30,0,14,30
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x3FFFE;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// rlwinm r29,r29,0,28,14
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0xFFFFFFFFFFFE000F;
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x823d3c78
	if (cr6.eq) goto loc_823D3C78;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190890
	ctx.lr = 0x823D3C10;
	sub_82190890(ctx, base);
	// lwz r11,-7572(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -7572);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82205248
	ctx.lr = 0x823D3C20;
	sub_82205248(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d3c38
	if (!cr6.eq) goto loc_823D3C38;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f7338
	ctx.lr = 0x823D3C38;
	sub_822F7338(ctx, base);
loc_823D3C38:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f74f0
	ctx.lr = 0x823D3C44;
	sub_822F74F0(ctx, base);
	// lwz r3,-7572(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -7572);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x822f3918
	ctx.lr = 0x823D3C50;
	sub_822F3918(ctx, base);
	// rlwinm r11,r30,0,28,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d3c78
	if (cr6.eq) goto loc_823D3C78;
	// lwz r11,-8092(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// li r3,1
	ctx.r3.s64 = 1;
	// lbz r11,393(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 393);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d3c74
	if (!cr6.eq) goto loc_823D3C74;
	// li r3,0
	ctx.r3.s64 = 0;
loc_823D3C74:
	// bl 0x8233a5a0
	ctx.lr = 0x823D3C78;
	sub_8233A5A0(ctx, base);
loc_823D3C78:
	// lwz r11,-8092(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// lbz r10,393(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 393);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d3cac
	if (cr6.eq) goto loc_823D3CAC;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D3CAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D3CAC:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D3CD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x823d3d24
	if (cr6.eq) goto loc_823D3D24;
	// lwz r3,-7572(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x823D3CE0;
	sub_82205248(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d3d08
	if (!cr6.eq) goto loc_823D3D08;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822f74f0
	ctx.lr = 0x823D3CF8;
	sub_822F74F0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f7338
	ctx.lr = 0x823D3D04;
	sub_822F7338(ctx, base);
	// b 0x823d3d10
	goto loc_823D3D10;
loc_823D3D08:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822f7480
	ctx.lr = 0x823D3D10;
	sub_822F7480(ctx, base);
loc_823D3D10:
	// lwz r3,-7572(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -7572);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x822f3918
	ctx.lr = 0x823D3D1C;
	sub_822F3918(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82190890
	ctx.lr = 0x823D3D24;
	sub_82190890(ctx, base);
loc_823D3D24:
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// beq cr6,0x823d3d50
	if (cr6.eq) goto loc_823D3D50;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D3D50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D3D50:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d3dcc
	if (!cr6.eq) goto loc_823D3DCC;
	// rlwinm r11,r30,0,19,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1FF0;
	// rlwinm r11,r11,0,23,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFF1FF;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d3dcc
	if (cr6.eq) goto loc_823D3DCC;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823112c0
	ctx.lr = 0x823D3D80;
	sub_823112C0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190890
	ctx.lr = 0x823D3D88;
	sub_82190890(ctx, base);
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D3DB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82190890
	ctx.lr = 0x823D3DB8;
	sub_82190890(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823112c0
	ctx.lr = 0x823D3DCC;
	sub_823112C0(ctx, base);
loc_823D3DCC:
	// li r11,0
	r11.s64 = 0;
	// stb r11,-13430(r23)
	PPC_STORE_U8(r23.u32 + -13430, r11.u8);
loc_823D3DD4:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// li r0,-144
	r0.s64 = -144;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_823D3DF4"))) PPC_WEAK_FUNC(sub_823D3DF4);
PPC_FUNC_IMPL(__imp__sub_823D3DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D3DF8"))) PPC_WEAK_FUNC(sub_823D3DF8);
PPC_FUNC_IMPL(__imp__sub_823D3DF8) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x823d3e54
	if (cr6.eq) goto loc_823D3E54;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x823d3e54
	if (cr6.eq) goto loc_823D3E54;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823d3e4c
	if (!cr6.eq) goto loc_823D3E4C;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// bl 0x82137a08
	ctx.lr = 0x823D3E40;
	sub_82137A08(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r30,101(r31)
	PPC_STORE_U8(r31.u32 + 101, r30.u8);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
loc_823D3E4C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823d3e58
	goto loc_823D3E58;
loc_823D3E54:
	// li r3,1
	ctx.r3.s64 = 1;
loc_823D3E58:
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

__attribute__((alias("__imp__sub_823D3E70"))) PPC_WEAK_FUNC(sub_823D3E70);
PPC_FUNC_IMPL(__imp__sub_823D3E70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	ctx.lr = 0x823D3E78;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r10,8192
	ctx.r10.s64 = 536870912;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rlwinm r9,r11,0,2,3
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bne cr6,0x823d3f24
	if (!cr6.eq) goto loc_823D3F24;
	// lwz r31,0(r13)
	r31.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r26,68
	r26.s64 = 68;
	// lwz r25,0(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stwx r30,r31,r26
	PPC_STORE_U32(r31.u32 + r26.u32, r30.u32);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x821bc6b8
	ctx.lr = 0x823D3EB0;
	sub_821BC6B8(ctx, base);
	// li r29,60
	r29.s64 = 60;
	// lis r24,-32112
	r24.s64 = -2104492032;
	// lwzx r10,r31,r29
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r29.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// li r28,0
	r28.s64 = 0;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// stwx r9,r31,r29
	PPC_STORE_U32(r31.u32 + r29.u32, ctx.r9.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stb r28,92(r1)
	PPC_STORE_U8(ctx.r1.u32 + 92, r28.u8);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r11,23572(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 23572);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,23572(r24)
	PPC_STORE_U32(r24.u32 + 23572, r11.u32);
	// bl 0x826122b0
	ctx.lr = 0x823D3EF0;
	sub_826122B0(ctx, base);
	// sth r28,2(r27)
	PPC_STORE_U16(r27.u32 + 2, r28.u16);
	// sth r28,0(r27)
	PPC_STORE_U16(r27.u32 + 0, r28.u16);
	// lis r4,12288
	ctx.r4.s64 = 805306368;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e2808
	ctx.lr = 0x823D3F04;
	sub_821E2808(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8276d240
	ctx.lr = 0x823D3F0C;
	sub_8276D240(ctx, base);
	// lwz r11,23572(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 23572);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r28,r31,r26
	PPC_STORE_U32(r31.u32 + r26.u32, r28.u32);
	// stw r11,23572(r24)
	PPC_STORE_U32(r24.u32 + 23572, r11.u32);
	// stwx r8,r31,r29
	PPC_STORE_U32(r31.u32 + r29.u32, ctx.r8.u32);
loc_823D3F24:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823D3F2C"))) PPC_WEAK_FUNC(sub_823D3F2C);
PPC_FUNC_IMPL(__imp__sub_823D3F2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D3F30"))) PPC_WEAK_FUNC(sub_823D3F30);
PPC_FUNC_IMPL(__imp__sub_823D3F30) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x823D3F38;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d3f60
	if (!cr6.eq) goto loc_823D3F60;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82608a98
	ctx.lr = 0x823D3F60;
	sub_82608A98(ctx, base);
loc_823D3F60:
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// lhz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// sth r9,6(r30)
	PPC_STORE_U16(r30.u32 + 6, ctx.r9.u16);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x823d3f90
	if (!cr6.eq) goto loc_823D3F90;
	// bl 0x821c9438
	ctx.lr = 0x823D3F84;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823c9658
	ctx.lr = 0x823D3F90;
	sub_823C9658(ctx, base);
loc_823D3F90:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c95a0
	ctx.lr = 0x823D3F98;
	sub_821C95A0(ctx, base);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// li r29,0
	r29.s64 = 0;
	// divwu r10,r3,r11
	ctx.r10.u32 = ctx.r3.u32 / r11.u32;
	// twllei r11,0
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// mullw r9,r10,r11
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// sth r29,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r29.u16);
	// sth r29,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r29.u16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// subf r28,r9,r3
	r28.s64 = ctx.r3.s64 - ctx.r9.s64;
	// beq cr6,0x823d3ff0
	if (cr6.eq) goto loc_823D3FF0;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_823D3FC8:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823d3fc8
	if (!cr6.eq) goto loc_823D3FC8;
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823D3FF0;
	sub_821C9650(ctx, base);
loc_823D3FF0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r27,r28,2,0,29
	r27.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,16
	ctx.r3.s64 = 16;
	// lwzx r28,r27,r11
	r28.u64 = PPC_LOAD_U32(r27.u32 + r11.u32);
	// bl 0x82130528
	ctx.lr = 0x823D4004;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d4038
	if (cr6.eq) goto loc_823D4038;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// sth r29,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r29.u16);
	// sth r29,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r29.u16);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lhz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// bl 0x821c9650
	ctx.lr = 0x823D4028;
	sub_821C9650(ctx, base);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r29,r31
	r29.u64 = r31.u64;
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_823D4038:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stwx r29,r27,r11
	PPC_STORE_U32(r27.u32 + r11.u32, r29.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82130588
	ctx.lr = 0x823D4048;
	sub_82130588(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r27,r10
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823D4058"))) PPC_WEAK_FUNC(sub_823D4058);
PPC_FUNC_IMPL(__imp__sub_823D4058) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	ctx.lr = 0x823D4060;
	// stwu r1,-880(r1)
	ea = -880 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// addi r5,r11,-32764
	ctx.r5.s64 = r11.s64 + -32764;
	// addi r4,r10,-15552
	ctx.r4.s64 = ctx.r10.s64 + -15552;
	// addi r3,r9,30576
	ctx.r3.s64 = ctx.r9.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x823D408C;
	sub_821CA6A8(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x823d41d0
	if (cr6.eq) goto loc_823D41D0;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x821d1cd0
	ctx.lr = 0x823D40A0;
	sub_821D1CD0(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r11,-15568
	ctx.r4.s64 = r11.s64 + -15568;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x821cf7b8
	ctx.lr = 0x823D40B4;
	sub_821CF7B8(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-6772
	ctx.r4.s64 = ctx.r10.s64 + -6772;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x821cff40
	ctx.lr = 0x823D40C8;
	sub_821CFF40(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823d41bc
	if (cr6.eq) goto loc_823D41BC;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// addi r4,r11,-29624
	ctx.r4.s64 = r11.s64 + -29624;
	// bl 0x821d0898
	ctx.lr = 0x823D40E8;
	sub_821D0898(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r26,r11,-29628
	r26.s64 = r11.s64 + -29628;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x821cfe80
	ctx.lr = 0x823D4100;
	sub_821CFE80(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823d41bc
	if (!cr6.eq) goto loc_823D41BC;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lis r29,-32247
	r29.s64 = -2113339392;
	// addi r30,r11,-11208
	r30.s64 = r11.s64 + -11208;
	// addi r28,r10,-15600
	r28.s64 = ctx.r10.s64 + -15600;
loc_823D4120:
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x821cfaa8
	ctx.lr = 0x823D4130;
	sub_821CFAA8(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r4,84
	ctx.r4.s64 = 84;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82137a08
	ctx.lr = 0x823D4144;
	sub_82137A08(ctx, base);
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x823D414C;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d4168
	if (cr6.eq) goto loc_823D4168;
	// bl 0x821e2748
	ctx.lr = 0x823D415C;
	sub_821E2748(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r27.u32);
	// b 0x823d416c
	goto loc_823D416C;
loc_823D4168:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_823D416C:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r6,-27448(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + -27448);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// bl 0x821e2940
	ctx.lr = 0x823D4184;
	sub_821E2940(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d41a0
	if (cr6.eq) goto loc_823D41A0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r24,20
	ctx.r3.s64 = r24.s64 + 20;
	// bl 0x823d3f30
	ctx.lr = 0x823D41A0;
	sub_823D3F30(ctx, base);
loc_823D41A0:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x821cfe80
	ctx.lr = 0x823D41B0;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d4120
	if (cr6.eq) goto loc_823D4120;
loc_823D41BC:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821be610
	ctx.lr = 0x823D41C4;
	sub_821BE610(ctx, base);
	// stw r27,16(r24)
	PPC_STORE_U32(r24.u32 + 16, r27.u32);
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x823d9238
	return;
loc_823D41D0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,16(r24)
	PPC_STORE_U32(r24.u32 + 16, r11.u32);
	// addi r1,r1,880
	ctx.r1.s64 = ctx.r1.s64 + 880;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823D41E0"))) PPC_WEAK_FUNC(sub_823D41E0);
PPC_FUNC_IMPL(__imp__sub_823D41E0) {
	PPC_FUNC_PROLOGUE();
	// b 0x823d3e70
	sub_823D3E70(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823D41E4"))) PPC_WEAK_FUNC(sub_823D41E4);
PPC_FUNC_IMPL(__imp__sub_823D41E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D41E8"))) PPC_WEAK_FUNC(sub_823D41E8);
PPC_FUNC_IMPL(__imp__sub_823D41E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r29{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x823d4350
	if (cr6.gt) goto loc_823D4350;
	// lis r12,-32195
	r12.s64 = -2109931520;
	// addi r12,r12,16928
	r12.s64 = r12.s64 + 16928;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_823D4244;
	case 1:
		goto loc_823D42D8;
	case 2:
		goto loc_823D42B8;
	case 3:
		goto loc_823D4260;
	case 4:
		goto loc_823D4274;
	case 5:
		goto loc_823D4288;
	case 6:
		goto loc_823D4290;
	case 7:
		goto loc_823D4298;
	case 8:
		goto loc_823D42A0;
	default:
		__builtin_unreachable();
	}
	// lwz r17,16964(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 16964);
	// lwz r17,17112(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 17112);
	// lwz r17,17080(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 17080);
	// lwz r17,16992(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 16992);
	// lwz r17,17012(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 17012);
	// lwz r17,17032(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 17032);
	// lwz r17,17040(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 17040);
	// lwz r17,17048(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 17048);
	// lwz r17,17056(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 17056);
loc_823D4244:
	// li r11,0
	r11.s64 = 0;
	// stb r11,100(r31)
	PPC_STORE_U8(r31.u32 + 100, r11.u8);
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
loc_823D4260:
	// lbz r11,100(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d4350
	if (cr6.eq) goto loc_823D4350;
	// li r11,5
	r11.s64 = 5;
	// b 0x823d434c
	goto loc_823D434C;
loc_823D4274:
	// lbz r11,100(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d4350
	if (cr6.eq) goto loc_823D4350;
loc_823D4280:
	// li r11,0
	r11.s64 = 0;
	// b 0x823d434c
	goto loc_823D434C;
loc_823D4288:
	// li r11,6
	r11.s64 = 6;
	// b 0x823d434c
	goto loc_823D434C;
loc_823D4290:
	// li r11,7
	r11.s64 = 7;
	// b 0x823d434c
	goto loc_823D434C;
loc_823D4298:
	// li r11,8
	r11.s64 = 8;
	// b 0x823d434c
	goto loc_823D434C;
loc_823D42A0:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82765168
	ctx.lr = 0x823D42AC;
	sub_82765168(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// b 0x823d434c
	goto loc_823D434C;
loc_823D42B8:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lis r10,12288
	ctx.r10.s64 = 805306368;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r8,r9,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x30000000;
	// cmpw cr6,r8,r10
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, xer);
	// bne cr6,0x823d4350
	if (!cr6.eq) goto loc_823D4350;
	// li r11,3
	r11.s64 = 3;
	// b 0x823d434c
	goto loc_823D434C;
loc_823D42D8:
	// lbz r11,100(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d4280
	if (!cr6.eq) goto loc_823D4280;
	// addi r4,r31,36
	ctx.r4.s64 = r31.s64 + 36;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x823d38c0
	ctx.lr = 0x823D42F0;
	sub_823D38C0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d4300
	if (cr6.eq) goto loc_823D4300;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x823d4304
	goto loc_823D4304;
loc_823D4300:
	// li r11,0
	r11.s64 = 0;
loc_823D4304:
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d4348
	if (cr6.eq) goto loc_823D4348;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32195
	ctx.r10.s64 = -2109931520;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r10,16864
	ctx.r5.s64 = ctx.r10.s64 + 16864;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821e27d8
	ctx.lr = 0x823D432C;
	sub_821E27D8(ctx, base);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r9,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r9.u32);
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
loc_823D4348:
	// li r11,4
	r11.s64 = 4;
loc_823D434C:
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
loc_823D4350:
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

__attribute__((alias("__imp__sub_823D4364"))) PPC_WEAK_FUNC(sub_823D4364);
PPC_FUNC_IMPL(__imp__sub_823D4364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D4368"))) PPC_WEAK_FUNC(sub_823D4368);
PPC_FUNC_IMPL(__imp__sub_823D4368) {
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
	// bl 0x822e6b38
	ctx.lr = 0x823D4380;
	sub_822E6B38(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,14
	ctx.r10.s64 = 917504;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r11,-15620
	ctx.r8.s64 = r11.s64 + -15620;
	// ori r7,r10,30718
	ctx.r7.u64 = ctx.r10.u64 | 30718;
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
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,-8092(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8092);
	// bl 0x822e5138
	ctx.lr = 0x823D43B4;
	sub_822E5138(ctx, base);
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// addi r4,r5,-15516
	ctx.r4.s64 = ctx.r5.s64 + -15516;
	// li r11,0
	r11.s64 = 0;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r11,26(r31)
	PPC_STORE_U16(r31.u32 + 26, r11.u16);
	// sth r11,24(r31)
	PPC_STORE_U16(r31.u32 + 24, r11.u16);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stb r11,31(r31)
	PPC_STORE_U8(r31.u32 + 31, r11.u8);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// stb r11,36(r31)
	PPC_STORE_U8(r31.u32 + 36, r11.u8);
	// stb r11,100(r31)
	PPC_STORE_U8(r31.u32 + 100, r11.u8);
	// stb r11,101(r31)
	PPC_STORE_U8(r31.u32 + 101, r11.u8);
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

__attribute__((alias("__imp__sub_823D4400"))) PPC_WEAK_FUNC(sub_823D4400);
PPC_FUNC_IMPL(__imp__sub_823D4400) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-15496
	ctx.r3.s64 = r11.s64 + -15496;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D440C"))) PPC_WEAK_FUNC(sub_823D440C);
PPC_FUNC_IMPL(__imp__sub_823D440C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D4410"))) PPC_WEAK_FUNC(sub_823D4410);
PPC_FUNC_IMPL(__imp__sub_823D4410) {
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
	// lis r10,-32137
	ctx.r10.s64 = -2106130432;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r10,-11448
	ctx.r6.s64 = ctx.r10.s64 + -11448;
	// lwz r3,-12720(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12720);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823D4450;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r11,r7,0,2,3
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x30000000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d4484
	if (cr6.eq) goto loc_823D4484;
	// lis r10,4096
	ctx.r10.s64 = 268435456;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x823d449c
	if (cr6.eq) goto loc_823D449C;
	// lis r10,8192
	ctx.r10.s64 = 536870912;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x823d4484
	if (cr6.eq) goto loc_823D4484;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82765168
	ctx.lr = 0x823D4484;
	sub_82765168(ctx, base);
loc_823D4484:
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
loc_823D449C:
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

__attribute__((alias("__imp__sub_823D44B4"))) PPC_WEAK_FUNC(sub_823D44B4);
PPC_FUNC_IMPL(__imp__sub_823D44B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D44B8"))) PPC_WEAK_FUNC(sub_823D44B8);
PPC_FUNC_IMPL(__imp__sub_823D44B8) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r10,r11,-15516
	ctx.r10.s64 = r11.s64 + -15516;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d44e8
	if (cr6.eq) goto loc_823D44E8;
	// bl 0x823d4410
	ctx.lr = 0x823D44E8;
	sub_823D4410(ctx, base);
loc_823D44E8:
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x82138a18
	ctx.lr = 0x823D44F0;
	sub_82138A18(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-15620
	ctx.r9.s64 = r11.s64 + -15620;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x823D450C;
	sub_822E5148(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-27436(r8)
	PPC_STORE_U32(ctx.r8.u32 + -27436, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x823D4520;
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

__attribute__((alias("__imp__sub_823D4534"))) PPC_WEAK_FUNC(sub_823D4534);
PPC_FUNC_IMPL(__imp__sub_823D4534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D4538"))) PPC_WEAK_FUNC(sub_823D4538);
PPC_FUNC_IMPL(__imp__sub_823D4538) {
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
	// bl 0x823d44b8
	ctx.lr = 0x823D4558;
	sub_823D44B8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d4570
	if (cr6.eq) goto loc_823D4570;
	// bl 0x82130588
	ctx.lr = 0x823D456C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823D4570:
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

__attribute__((alias("__imp__sub_823D4588"))) PPC_WEAK_FUNC(sub_823D4588);
PPC_FUNC_IMPL(__imp__sub_823D4588) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-15168
	ctx.r10.s64 = r11.s64 + -15168;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x823D45B8;
	sub_82130588(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823d45d0
	if (cr6.eq) goto loc_823D45D0;
	// bl 0x82130588
	ctx.lr = 0x823D45CC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823D45D0:
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

__attribute__((alias("__imp__sub_823D45E8"))) PPC_WEAK_FUNC(sub_823D45E8);
PPC_FUNC_IMPL(__imp__sub_823D45E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d4608
	if (cr6.eq) goto loc_823D4608;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x823d4608
	if (!cr6.eq) goto loc_823D4608;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// blr 
	return;
loc_823D4608:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D4610"))) PPC_WEAK_FUNC(sub_823D4610);
PPC_FUNC_IMPL(__imp__sub_823D4610) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823a4030
	ctx.lr = 0x823D4628;
	sub_823A4030(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,-15160
	ctx.r9.s64 = r11.s64 + -15160;
	// li r11,0
	r11.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
	// stfs f0,156(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 156, temp.u32);
	// stb r11,152(r31)
	PPC_STORE_U8(r31.u32 + 152, r11.u8);
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

__attribute__((alias("__imp__sub_823D4668"))) PPC_WEAK_FUNC(sub_823D4668);
PPC_FUNC_IMPL(__imp__sub_823D4668) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823a4088
	ctx.lr = 0x823D4680;
	sub_823A4088(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// stw r11,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r11.u32);
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r11,152(r31)
	PPC_STORE_U8(r31.u32 + 152, r11.u8);
	// stfs f0,156(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 156, temp.u32);
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

__attribute__((alias("__imp__sub_823D46B0"))) PPC_WEAK_FUNC(sub_823D46B0);
PPC_FUNC_IMPL(__imp__sub_823D46B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x823D46B8;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9d0
	ctx.lr = 0x823D46C0;
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// fmr f26,f2
	ctx.fpscr.disableFlushMode();
	f26.f64 = ctx.f2.f64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// fmr f29,f1
	f29.f64 = ctx.f1.f64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// fmr f30,f3
	f30.f64 = ctx.f3.f64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// lfd f2,-16912(r11)
	ctx.f2.u64 = PPC_LOAD_U64(r11.u32 + -16912);
	// bl 0x823dc100
	ctx.lr = 0x823D46F0;
	sub_823DC100(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lfs f0,0(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	f0.f64 = double(temp.f32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f12,-16916(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -16916);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,3804(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3804);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f31,f29,f11
	f31.f64 = double(float(f29.f64 - ctx.f11.f64));
	// fsubs f10,f31,f0
	ctx.f10.f64 = double(float(f31.f64 - f0.f64));
	// fmr f28,f31
	f28.f64 = f31.f64;
	// fcmpu cr6,f10,f12
	cr6.compare(ctx.f10.f64, ctx.f12.f64);
	// ble cr6,0x823d4720
	if (!cr6.gt) goto loc_823D4720;
	// fadds f31,f0,f13
	f31.f64 = double(float(f0.f64 + ctx.f13.f64));
loc_823D4720:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// fadds f27,f28,f13
	ctx.fpscr.disableFlushMode();
	f27.f64 = double(float(f28.f64 + ctx.f13.f64));
	// li r30,0
	r30.s64 = 0;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// addi r10,r11,18800
	ctx.r10.s64 = r11.s64 + 18800;
	// li r9,5
	ctx.r9.s64 = 5;
	// stb r30,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, r30.u8);
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stb r9,117(r1)
	PPC_STORE_U8(ctx.r1.u32 + 117, ctx.r9.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// sth r30,118(r1)
	PPC_STORE_U16(ctx.r1.u32 + 118, r30.u16);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,27644(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 27644);
	f0.f64 = double(temp.f32);
	// fmuls f30,f30,f0
	f30.f64 = double(float(f30.f64 * f0.f64));
	// bl 0x82503d98
	ctx.lr = 0x823D4768;
	sub_82503D98(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823d4788
	if (cr6.eq) goto loc_823D4788;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d4794
	goto loc_823D4794;
loc_823D4788:
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823D4794:
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82503d98
	ctx.lr = 0x823D47AC;
	sub_82503D98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d47cc
	if (cr6.eq) goto loc_823D47CC;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v127,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823D47CC:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// sth r30,150(r1)
	PPC_STORE_U16(ctx.r1.u32 + 150, r30.u16);
	// li r9,6
	ctx.r9.s64 = 6;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r10,r11,-17052
	ctx.r10.s64 = r11.s64 + -17052;
	// li r29,1
	r29.s64 = 1;
	// stb r9,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, ctx.r9.u8);
	// stw r10,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stb r29,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, r29.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f31,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// bl 0x82503d98
	ctx.lr = 0x823D480C;
	sub_82503D98(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823d482c
	if (cr6.eq) goto loc_823D482C;
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d483c
	goto loc_823D483C;
loc_823D482C:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r9,r11,-26256
	ctx.r9.s64 = r11.s64 + -26256;
	// lvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823D483C:
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82503d98
	ctx.lr = 0x823D4854;
	sub_82503D98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d4870
	if (cr6.eq) goto loc_823D4870;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d59c8
	ctx.lr = 0x823D486C;
	sub_821D59C8(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
loc_823D4870:
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmuls f12,f26,f26
	ctx.f12.f64 = double(float(f26.f64 * f26.f64));
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stb r30,0(r28)
	PPC_STORE_U8(r28.u32 + 0, r30.u8);
	// fmadds f10,f0,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fcmpu cr6,f9,f12
	cr6.compare(ctx.f9.f64, ctx.f12.f64);
	// bgt cr6,0x823d48a0
	if (cr6.gt) goto loc_823D48A0;
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// ble cr6,0x823d48ac
	if (!cr6.gt) goto loc_823D48AC;
loc_823D48A0:
	// stb r29,0(r28)
	PPC_STORE_U8(r28.u32 + 0, r29.u8);
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// b 0x823d48b0
	goto loc_823D48B0;
loc_823D48AC:
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
loc_823D48B0:
	// stfs f28,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba1c
	ctx.lr = 0x823D48C8;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823D48CC"))) PPC_WEAK_FUNC(sub_823D48CC);
PPC_FUNC_IMPL(__imp__sub_823D48CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D48D0"))) PPC_WEAK_FUNC(sub_823D48D0);
PPC_FUNC_IMPL(__imp__sub_823D48D0) {
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
	ctx.lr = 0x823D48D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d4930
	if (cr6.eq) goto loc_823D4930;
	// li r31,0
	r31.s64 = 0;
loc_823D48F8:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r10,132(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r10,r28
	cr6.compare<int32_t>(ctx.r10.s32, r28.s32, xer);
	// bne cr6,0x823d491c
	if (!cr6.eq) goto loc_823D491C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D491C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D491C:
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x823d48f8
	if (cr6.lt) goto loc_823D48F8;
loc_823D4930:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823D4938"))) PPC_WEAK_FUNC(sub_823D4938);
PPC_FUNC_IMPL(__imp__sub_823D4938) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x823D4940;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823d4980
	if (cr6.eq) goto loc_823D4980;
	// bl 0x822a86e8
	ctx.lr = 0x823D4974;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d4a20
	if (cr6.eq) goto loc_823D4A20;
loc_823D4980:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,3998
	ctx.r9.s64 = r11.s64 + 3998;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8239e458
	ctx.lr = 0x823D49A8;
	sub_8239E458(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8239e348
	ctx.lr = 0x823D49B0;
	sub_8239E348(ctx, base);
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// sth r8,8(r31)
	PPC_STORE_U16(r31.u32 + 8, ctx.r8.u16);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stwx r24,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r24.u32);
	// lwz r6,0(r24)
	ctx.r6.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r5,16(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x823D49E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823a4100
	ctx.lr = 0x823D4A04;
	sub_823A4100(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r28,144(r24)
	PPC_STORE_U32(r24.u32 + 144, r28.u32);
	// stfs f31,156(r24)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r24.u32 + 156, temp.u32);
	// stb r25,152(r24)
	PPC_STORE_U8(r24.u32 + 152, r25.u8);
	// stw r10,148(r24)
	PPC_STORE_U32(r24.u32 + 148, ctx.r10.u32);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82130588
	ctx.lr = 0x823D4A20;
	sub_82130588(ctx, base);
loc_823D4A20:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823D4A30"))) PPC_WEAK_FUNC(sub_823D4A30);
PPC_FUNC_IMPL(__imp__sub_823D4A30) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x823D4A38;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823d4a74
	if (cr6.eq) goto loc_823D4A74;
	// bl 0x822a86e8
	ctx.lr = 0x823D4A68;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d4b14
	if (cr6.eq) goto loc_823D4B14;
loc_823D4A74:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,3998
	ctx.r9.s64 = r11.s64 + 3998;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8239e458
	ctx.lr = 0x823D4A9C;
	sub_8239E458(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8239e348
	ctx.lr = 0x823D4AA4;
	sub_8239E348(ctx, base);
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// sth r8,8(r31)
	PPC_STORE_U16(r31.u32 + 8, ctx.r8.u16);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stwx r25,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r25.u32);
	// lwz r6,0(r25)
	ctx.r6.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r5,16(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x823D4AD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823a4100
	ctx.lr = 0x823D4AF8;
	sub_823A4100(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r28,144(r25)
	PPC_STORE_U32(r25.u32 + 144, r28.u32);
	// stfs f31,156(r25)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r25.u32 + 156, temp.u32);
	// stb r26,152(r25)
	PPC_STORE_U8(r25.u32 + 152, r26.u8);
	// stw r10,148(r25)
	PPC_STORE_U32(r25.u32 + 148, ctx.r10.u32);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82130588
	ctx.lr = 0x823D4B14;
	sub_82130588(ctx, base);
loc_823D4B14:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823D4B24"))) PPC_WEAK_FUNC(sub_823D4B24);
PPC_FUNC_IMPL(__imp__sub_823D4B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D4B28"))) PPC_WEAK_FUNC(sub_823D4B28);
PPC_FUNC_IMPL(__imp__sub_823D4B28) {
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
	ctx.lr = 0x823D4B30;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r31,12(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r9,12(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// lwz r7,8(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// and r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 & ctx.r9.u64;
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r5,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r5.u32);
	// lwzx r11,r7,r4
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r4.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stwx r31,r9,r4
	PPC_STORE_U32(ctx.r9.u32 + ctx.r4.u32, r31.u32);
	// sth r10,8(r31)
	PPC_STORE_U16(r31.u32 + 8, ctx.r10.u16);
	// lhz r5,8(r29)
	ctx.r5.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x821c9650
	ctx.lr = 0x823D4B88;
	sub_821C9650(ctx, base);
	// lwz r8,12(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,16(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// stw r7,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r7.u32);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r6.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823D4BB0"))) PPC_WEAK_FUNC(sub_823D4BB0);
PPC_FUNC_IMPL(__imp__sub_823D4BB0) {
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
	ctx.lr = 0x823D4BB8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-15168
	ctx.r9.s64 = ctx.r10.s64 + -15168;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// sth r11,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r11.u16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// sth r11,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r11.u16);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r5,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r5.u32);
	// sth r11,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r11.u16);
	// lhz r5,4(r29)
	ctx.r5.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x821c9650
	ctx.lr = 0x823D4C00;
	sub_821C9650(ctx, base);
	// lhz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823d4c14
	if (cr6.eq) goto loc_823D4C14;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x823d4c1c
	goto loc_823D4C1C;
loc_823D4C14:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
loc_823D4C1C:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821c9790
	ctx.lr = 0x823D4C24;
	sub_821C9790(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823D4C30;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823D4C3C"))) PPC_WEAK_FUNC(sub_823D4C3C);
PPC_FUNC_IMPL(__imp__sub_823D4C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D4C40"))) PPC_WEAK_FUNC(sub_823D4C40);
PPC_FUNC_IMPL(__imp__sub_823D4C40) {
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
	ctx.lr = 0x823D4C48;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-15168
	ctx.r9.s64 = ctx.r10.s64 + -15168;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// sth r11,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r11.u16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// sth r11,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r11.u16);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// sth r11,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r11.u16);
	// lhz r5,4(r29)
	ctx.r5.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x821c9650
	ctx.lr = 0x823D4C90;
	sub_821C9650(ctx, base);
	// lhz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823d4ca4
	if (cr6.eq) goto loc_823D4CA4;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// b 0x823d4cac
	goto loc_823D4CAC;
loc_823D4CA4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
loc_823D4CAC:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821c9790
	ctx.lr = 0x823D4CB4;
	sub_821C9790(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823D4CC0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823D4CCC"))) PPC_WEAK_FUNC(sub_823D4CCC);
PPC_FUNC_IMPL(__imp__sub_823D4CCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D4CD0"))) PPC_WEAK_FUNC(sub_823D4CD0);
PPC_FUNC_IMPL(__imp__sub_823D4CD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	PPCRegister f14{};
	PPCRegister f15{};
	PPCRegister f16{};
	PPCRegister f17{};
	PPCRegister f18{};
	PPCRegister f19{};
	PPCRegister f20{};
	PPCRegister f21{};
	PPCRegister f22{};
	PPCRegister f23{};
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
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
	PPCVRegister v120{};
	PPCVRegister v121{};
	PPCVRegister v122{};
	PPCVRegister v123{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x823D4CD8;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823db9a0
	ctx.lr = 0x823D4CE0;
	// addi r12,r1,-224
	r12.s64 = ctx.r1.s64 + -224;
	// bl 0x823dd514
	ctx.lr = 0x823D4CE8;
	// stwu r1,-720(r1)
	ea = -720 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// lbz r11,152(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d56f4
	if (!cr6.eq) goto loc_823D56F4;
	// li r25,0
	r25.s64 = 0;
	// lwz r6,120(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 120);
	// mr r24,r25
	r24.u64 = r25.u64;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// stb r24,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r24.u8);
	// beq cr6,0x823d4d44
	if (cr6.eq) goto loc_823D4D44;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lfs f1,124(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 124);
	ctx.f1.f64 = double(temp.f32);
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// addi r4,r28,156
	ctx.r4.s64 = r28.s64 + 156;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f3,-21168(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -21168);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-21172(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21172);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x823d46b0
	ctx.lr = 0x823D4D38;
	sub_823D46B0(ctx, base);
	// lbz r24,80(r1)
	r24.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// fmr f14,f1
	ctx.fpscr.disableFlushMode();
	f14.f64 = ctx.f1.f64;
	// b 0x823d4d48
	goto loc_823D4D48;
loc_823D4D44:
	// lfs f14,124(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 124);
	f14.f64 = double(temp.f32);
loc_823D4D48:
	// vspltisw128 v121,0
	simde_mm_store_si128((simde__m128i*)v121.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r29,r28,32
	r29.s64 = r28.s64 + 32;
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// addi r27,r29,16
	r27.s64 = r29.s64 + 16;
	// addi r30,r29,32
	r30.s64 = r29.s64 + 32;
	// vupkd3d128 v63,v121,4
	temp.f32 = 3.0f;
	temp.s32 += v121.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v121.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v63 = vTemp;
	// addi r31,r29,48
	r31.s64 = r29.s64 + 48;
	// addi r3,r28,96
	ctx.r3.s64 = r28.s64 + 96;
	// vpermwi128 v62,v63,234
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x15));
	// vpermwi128 v61,v63,186
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x45));
	// vpermwi128 v60,v63,174
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x51));
	// stvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v121,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v121.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x823a3f00
	ctx.lr = 0x823D4D88;
	sub_823A3F00(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r9,r1,352
	ctx.r9.s64 = ctx.r1.s64 + 352;
	// lwz r3,120(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 120);
	// addi r8,r1,336
	ctx.r8.s64 = ctx.r1.s64 + 336;
	// addi r7,r1,320
	ctx.r7.s64 = ctx.r1.s64 + 320;
	// addi r6,r1,304
	ctx.r6.s64 = ctx.r1.s64 + 304;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// fmr f26,f31
	f26.f64 = f31.f64;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// fmr f30,f31
	f30.f64 = f31.f64;
	// lfs f27,11412(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11412);
	f27.f64 = double(temp.f32);
	// lfs f19,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f19.f64 = double(temp.f32);
	// lvx128 v120,r0,r9
	simde_mm_store_si128((simde__m128i*)v120.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v126,r0,r7
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v125,r0,r6
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x823d5560
	if (cr6.eq) goto loc_823D5560;
	// lwz r11,144(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 144);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d5560
	if (cr6.eq) goto loc_823D5560;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x823d5560
	if (!cr6.eq) goto loc_823D5560;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d5560
	if (cr6.eq) goto loc_823D5560;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stb r25,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, r25.u8);
	// li r10,5
	ctx.r10.s64 = 5;
	// sth r25,182(r1)
	PPC_STORE_U16(ctx.r1.u32 + 182, r25.u16);
	// addi r9,r11,18800
	ctx.r9.s64 = r11.s64 + 18800;
	// fmr f1,f14
	ctx.f1.f64 = f14.f64;
	// stb r10,181(r1)
	PPC_STORE_U8(ctx.r1.u32 + 181, ctx.r10.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r9,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r9.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// bl 0x82503d98
	ctx.lr = 0x823D4E2C;
	sub_82503D98(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823d4e44
	if (cr6.eq) goto loc_823D4E44;
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823D4E44:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// sth r25,262(r1)
	PPC_STORE_U16(ctx.r1.u32 + 262, r25.u16);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r3,120(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 120);
	// addi r9,r11,-17052
	ctx.r9.s64 = r11.s64 + -17052;
	// fmr f1,f14
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f14.f64;
	// li r8,6
	ctx.r8.s64 = 6;
	// stb r10,260(r1)
	PPC_STORE_U8(ctx.r1.u32 + 260, ctx.r10.u8);
	// stw r9,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r9.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r8,261(r1)
	PPC_STORE_U8(ctx.r1.u32 + 261, ctx.r8.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// bl 0x82503d98
	ctx.lr = 0x823D4E7C;
	sub_82503D98(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823d4e94
	if (cr6.eq) goto loc_823D4E94;
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d1d30
	ctx.lr = 0x823D4E94;
	sub_821D1D30(ctx, base);
loc_823D4E94:
	// clrlwi r26,r24,24
	r26.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x823d4ee0
	if (!cr6.eq) goto loc_823D4EE0;
	// fsubs f0,f14,f29
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f14.f64 - f29.f64));
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,120(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 120);
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// fsel f1,f13,f31,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? f31.f64 : f0.f64;
	// bl 0x82503d98
	ctx.lr = 0x823D4EC0;
	sub_82503D98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d4ee0
	if (cr6.eq) goto loc_823D4EE0;
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v122,r0,r11
	simde_mm_store_si128((simde__m128i*)v122.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v122,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v122.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d4eec
	goto loc_823D4EEC;
loc_823D4EE0:
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lvx128 v122,r0,r31
	simde_mm_store_si128((simde__m128i*)v122.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v122,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v122.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823D4EEC:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// lfs f15,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f15.f64 = double(temp.f32);
	// bne cr6,0x823d4f34
	if (!cr6.eq) goto loc_823D4F34;
	// fnmsubs f0,f29,f15,f14
	f0.f64 = double(float(-(f29.f64 * f15.f64 - f14.f64)));
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,120(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 120);
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// fsel f1,f13,f31,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? f31.f64 : f0.f64;
	// bl 0x82503d98
	ctx.lr = 0x823D4F1C;
	sub_82503D98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d4f34
	if (cr6.eq) goto loc_823D4F34;
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// lvx128 v123,r0,r11
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d4f38
	goto loc_823D4F38;
loc_823D4F34:
	// vor128 v123,v122,v122
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_load_si128((simde__m128i*)v122.u8));
loc_823D4F38:
	// fadds f0,f14,f29
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f14.f64 + f29.f64));
	// lwz r3,120(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 120);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lfs f13,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f1,f12,f0,f13
	ctx.f1.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// bl 0x82503d98
	ctx.lr = 0x823D4F5C;
	sub_82503D98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d4f7c
	if (cr6.eq) goto loc_823D4F7C;
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lvx128 v124,r0,r11
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v124,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d4f88
	goto loc_823D4F88;
loc_823D4F7C:
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// lvx128 v124,r0,r31
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v124,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823D4F88:
	// fmadds f0,f29,f15,f14
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f29.f64 * f15.f64 + f14.f64));
	// lwz r3,120(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 120);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lfs f13,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f1,f12,f0,f13
	ctx.f1.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// bl 0x82503d98
	ctx.lr = 0x823D4FAC;
	sub_82503D98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d4fcc
	if (cr6.eq) goto loc_823D4FCC;
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d4fd8
	goto loc_823D4FD8;
loc_823D4FCC:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// vor128 v63,v124,v124
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_load_si128((simde__m128i*)v124.u8));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823D4FD8:
	// lfs f13,148(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// vsubfp128 v124,v124,v122
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v124.f32, simde_mm_sub_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v122.f32)));
	// fsubs f10,f13,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f3,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f3.f64 = double(temp.f32);
	// lfs f5,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f1,f3,f13
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f13.f64));
	// lfs f2,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f2.f64 = double(temp.f32);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// lfs f0,14196(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14196);
	f0.f64 = double(temp.f32);
	// fsubs f13,f5,f2
	ctx.f13.f64 = double(float(ctx.f5.f64 - ctx.f2.f64));
	// lfs f9,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f6,f0,f29
	ctx.f6.f64 = double(float(f0.f64 - f29.f64));
	// lfs f12,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// fsubs f8,f12,f9
	ctx.f8.f64 = double(float(ctx.f12.f64 - ctx.f9.f64));
	// lfs f11,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f11.f64 = double(temp.f32);
	// lfs f7,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fsubs f4,f11,f7
	ctx.f4.f64 = double(float(ctx.f11.f64 - ctx.f7.f64));
	// lfs f7,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f7.f64 = double(temp.f32);
	// lfs f3,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f2,f7,f12
	ctx.f2.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// lfs f10,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f1,f1,f1
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f1.f64));
	// lfs f7,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f12,f9,f3
	ctx.f12.f64 = double(float(ctx.f9.f64 - ctx.f3.f64));
	// lfs f9,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// lvx128 v58,r0,r31
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsubs f3,f10,f7
	ctx.f3.f64 = double(float(ctx.f10.f64 - ctx.f7.f64));
	// fsel f22,f6,f0,f29
	f22.f64 = ctx.f6.f64 >= 0.0 ? f0.f64 : f29.f64;
	// vsubfp128 v57,v63,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v58.f32)));
	// fmuls f0,f13,f13
	ctx.fpscr.disableFlushModeUnconditional();
	f0.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// stvx128 v124,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsubs f6,f9,f11
	ctx.f6.f64 = double(float(ctx.f9.f64 - ctx.f11.f64));
	// lfs f28,27640(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 27640);
	f28.f64 = double(temp.f32);
	// vsubfp128 v56,v58,v123
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v123.f32)));
	// addi r7,r1,224
	ctx.r7.s64 = ctx.r1.s64 + 224;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// fmadds f13,f8,f8,f5
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f10,f2,f2,f1
	ctx.f10.f64 = double(float(ctx.f2.f64 * ctx.f2.f64 + ctx.f1.f64));
	// fdivs f11,f19,f22
	ctx.f11.f64 = double(float(f19.f64 / f22.f64));
	// fmadds f9,f12,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + f0.f64));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f8,f4,f4,f13
	ctx.f8.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f13.f64));
	// fmadds f7,f6,f6,f10
	ctx.f7.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f10.f64));
	// fmadds f6,f3,f3,f9
	ctx.f6.f64 = double(float(ctx.f3.f64 * ctx.f3.f64 + ctx.f9.f64));
	// fsqrts f5,f8
	ctx.f5.f64 = double(float(sqrt(ctx.f8.f64)));
	// fmuls f30,f5,f11
	f30.f64 = double(float(ctx.f5.f64 * ctx.f11.f64));
	// fsqrts f4,f7
	ctx.f4.f64 = double(float(sqrt(ctx.f7.f64)));
	// fsqrts f3,f6
	ctx.f3.f64 = double(float(sqrt(ctx.f6.f64)));
	// fsubs f2,f28,f30
	ctx.f2.f64 = double(float(f28.f64 - f30.f64));
	// fmuls f18,f4,f11
	f18.f64 = double(float(ctx.f4.f64 * ctx.f11.f64));
	// fmuls f27,f3,f11
	f27.f64 = double(float(ctx.f3.f64 * ctx.f11.f64));
	// fsel f29,f2,f28,f30
	f29.f64 = ctx.f2.f64 >= 0.0 ? f28.f64 : f30.f64;
	// bl 0x8216c9c0
	ctx.lr = 0x823D50C8;
	sub_8216C9C0(ctx, base);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// fdivs f1,f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64 / f29.f64));
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// stfs f1,128(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// bl 0x8216c9c0
	ctx.lr = 0x823D50DC;
	sub_8216C9C0(ctx, base);
	// fsubs f0,f28,f27
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f28.f64 - f27.f64));
	// lwz r9,144(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 144);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// fsel f13,f0,f28,f27
	ctx.f13.f64 = f0.f64 >= 0.0 ? f28.f64 : f27.f64;
	// fdivs f17,f1,f13
	f17.f64 = double(float(ctx.f1.f64 / ctx.f13.f64));
	// beq cr6,0x823d510c
	if (cr6.eq) goto loc_823D510C;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x823d510c
	if (!cr6.eq) goto loc_823D510C;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// b 0x823d5110
	goto loc_823D5110;
loc_823D510C:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823D5110:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// li r8,272
	ctx.r8.s64 = 272;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lwz r6,128(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	// lvx128 v60,r6,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x823d5148
	if (cr6.eq) goto loc_823D5148;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x823d5148
	if (!cr6.eq) goto loc_823D5148;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// b 0x823d514c
	goto loc_823D514C;
loc_823D5148:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823D514C:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// li r8,288
	ctx.r8.s64 = 288;
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lwz r6,128(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	// lvx128 v61,r6,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x823d5184
	if (cr6.eq) goto loc_823D5184;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x823d5184
	if (!cr6.eq) goto loc_823D5184;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// b 0x823d5188
	goto loc_823D5188;
loc_823D5184:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823D5188:
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r8,72
	ctx.r8.s64 = 72;
	// lbzx r8,r8,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823d51a4
	if (cr6.eq) goto loc_823D51A4;
	// addi r10,r11,272
	ctx.r10.s64 = r11.s64 + 272;
	// b 0x823d51ac
	goto loc_823D51AC;
loc_823D51A4:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
loc_823D51AC:
	// li r7,48
	ctx.r7.s64 = 48;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lvx128 v59,r10,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x823d51d4
	if (cr6.eq) goto loc_823D51D4;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x823d51d4
	if (!cr6.eq) goto loc_823D51D4;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// b 0x823d51d8
	goto loc_823D51D8;
loc_823D51D4:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823D51D8:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823d51e8
	if (cr6.eq) goto loc_823D51E8;
	// addi r10,r11,272
	ctx.r10.s64 = r11.s64 + 272;
	// b 0x823d51f0
	goto loc_823D51F0;
loc_823D51E8:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
loc_823D51F0:
	// li r7,32
	ctx.r7.s64 = 32;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lvx128 v55,r10,r7
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v121,v55
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v121.f32), simde_mm_load_ps(v55.f32)));
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x823d5224
	if (cr6.eq) goto loc_823D5224;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x823d5224
	if (!cr6.eq) goto loc_823D5224;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// b 0x823d5228
	goto loc_823D5228;
loc_823D5224:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823D5228:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823d5238
	if (cr6.eq) goto loc_823D5238;
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// b 0x823d5240
	goto loc_823D5240;
loc_823D5238:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_823D5240:
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v54,v59,v120
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v120.f32)));
	// lfs f0,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// vmsum3fp128 v53,v127,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v53.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmsum3fp128 v52,v125,v63
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// fmuls f12,f0,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// vmsum3fp128 v51,v127,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// vmsum3fp128 v50,v125,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// vmsum3fp128 v49,v127,v62
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// vmsum3fp128 v48,v125,v62
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// lfs f13,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// vmsum3fp128 v47,v127,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// vmsum3fp128 v46,v125,v61
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// vmsum3fp128 v45,v126,v63
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v44,v126,v60
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// vmsum3fp128 v43,v126,v62
	simde_mm_store_ps(v43.f32, simde_mm_dp_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// vmsum3fp128 v42,v126,v61
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// fmadds f11,f0,f0,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// vmsum3fp128 v41,v126,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// vmsum3fp128 v40,v127,v54
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmsum3fp128 v39,v125,v54
	simde_mm_store_ps(v39.f32, simde_mm_dp_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmrghw128 v38,v52,v53
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrghw128 v37,v50,v51
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrghw128 v36,v48,v49
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// fmadds f10,f13,f13,f11
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// vmrghw128 v35,v46,v47
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v34,v45,v38
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v33,v44,v37
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrghw128 v32,v43,v36
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmrghw128 v63,v42,v35
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrghw128 v62,v38,v34
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrghw128 v61,v37,v33
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vmrghw128 v60,v36,v32
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v36.u32)));
	// vmrghw128 v59,v35,v63
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// fsqrts f16,f10
	f16.f64 = double(float(sqrt(ctx.f10.f64)));
	// vmrghw128 v58,v41,v41
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// vmrghw128 v57,v39,v40
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// stvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v63,v57,v58
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// stvx128 v59,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x823d5324
	if (cr6.eq) goto loc_823D5324;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x823d5324
	if (!cr6.eq) goto loc_823D5324;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// b 0x823d5328
	goto loc_823D5328;
loc_823D5324:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823D5328:
	// lwz r11,104(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f13,48(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fcmpu cr6,f30,f12
	cr6.compare(f30.f64, ctx.f12.f64);
	// ble cr6,0x823d5548
	if (!cr6.gt) goto loc_823D5548;
	// vsubfp128 v56,v121,v124
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_sub_ps(simde_mm_load_ps(v121.f32), simde_mm_load_ps(v124.f32)));
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lvx128 v55,r0,r31
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r10,2240
	ctx.r8.s64 = ctx.r10.s64 + 2240;
	// vsubfp128 v54,v55,v63
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v63.f32)));
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// addi r9,r11,2528
	ctx.r9.s64 = r11.s64 + 2528;
	// addi r5,r7,-31664
	ctx.r5.s64 = ctx.r7.s64 + -31664;
	// addi r11,r6,-31648
	r11.s64 = ctx.r6.s64 + -31648;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// vor128 v53,v56,v56
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// stvx128 v56,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v52,v53,v53
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,14884(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stvx128 v54,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f28,f29,f0
	f28.f64 = double(float(f29.f64 * f0.f64));
	// vrsqrtefp128 v51,v52
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v51.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v52.f32))));
	// vor128 v12,v52,v52
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// vcmpeqfp128 v11,v51,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v51,v51
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v51.u8));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v63,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v50,v53,v6
	simde_mm_store_ps(v50.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vor128 v49,v50,v50
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_load_si128((simde__m128i*)v50.u8));
	// stvx128 v50,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r0,r27
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v47,v48,99
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0x9C));
	// vpermwi128 v46,v49,135
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0x78));
	// vpermwi128 v5,v48,135
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0x78));
	// vpermwi128 v4,v49,99
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0x9C));
	// vmulfp128 v3,v46,v47
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v47.f32)));
	// vnmsubfp v2,v4,v5,v3
	simde_mm_store_ps(ctx.v2.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v3.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v2,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216c9c0
	ctx.lr = 0x823D53FC;
	sub_8216C9C0(ctx, base);
	// lfs f0,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f0.f64 = double(temp.f32);
	// lfs f27,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	f27.f64 = double(temp.f32);
	// fmr f20,f1
	f20.f64 = ctx.f1.f64;
	// fmuls f13,f27,f0
	ctx.f13.f64 = double(float(f27.f64 * f0.f64));
	// lfs f12,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// lfs f26,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	f26.f64 = double(temp.f32);
	// fmr f2,f28
	ctx.f2.f64 = f28.f64;
	// lfs f11,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f11.f64 = double(temp.f32);
	// lfs f25,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	f25.f64 = double(temp.f32);
	// fmadds f10,f26,f12,f13
	ctx.f10.f64 = double(float(f26.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fnmadds f1,f25,f11,f10
	ctx.f1.f64 = double(float(-(f25.f64 * ctx.f11.f64 + ctx.f10.f64)));
	// bl 0x823dcdd8
	ctx.lr = 0x823D542C;
	sub_823DCDD8(ctx, base);
	// lfs f24,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	f24.f64 = double(temp.f32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lfs f23,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	f23.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stfs f24,112(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// frsp f21,f1
	f21.f64 = double(float(ctx.f1.f64));
	// stfs f23,120(r1)
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f19,160(r1)
	temp.f32 = float(f19.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f31,164(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f31,168(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lfs f1,31292(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 31292);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v1,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82165300
	ctx.lr = 0x823D5468;
	sub_82165300(ctx, base);
	// lfs f9,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f8.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f9,96(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmr f1,f19
	ctx.f1.f64 = f19.f64;
	// stfs f8,104(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v1,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82165300
	ctx.lr = 0x823D5490;
	sub_82165300(ctx, base);
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8216c9c0
	ctx.lr = 0x823D549C;
	sub_8216C9C0(ctx, base);
	// lfs f7,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f25,f23
	ctx.f5.f64 = double(float(f25.f64 * f23.f64));
	// fmuls f4,f6,f7
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f7.f64));
	// lfs f12,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f12.f64 = double(temp.f32);
	// lfs f3,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f11,f18,f30
	ctx.f11.f64 = double(float(f18.f64 - f30.f64));
	// lfs f2,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f13,f30,f16
	ctx.f13.f64 = double(float(f30.f64 - f16.f64));
	// lfs f10,212(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	ctx.f10.f64 = double(temp.f32);
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// lfs f9,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f9.f64 = double(temp.f32);
	// fdivs f8,f10,f29
	ctx.f8.f64 = double(float(ctx.f10.f64 / f29.f64));
	// lfs f7,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f7.f64 = double(temp.f32);
	// fcmpu cr6,f14,f31
	cr6.compare(f14.f64, f31.f64);
	// lfs f0,-17876(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -17876);
	f0.f64 = double(temp.f32);
	// fmadds f6,f12,f27,f5
	ctx.f6.f64 = double(float(ctx.f12.f64 * f27.f64 + ctx.f5.f64));
	// fmadds f5,f2,f3,f4
	ctx.f5.f64 = double(float(ctx.f2.f64 * ctx.f3.f64 + ctx.f4.f64));
	// fdivs f10,f11,f22
	ctx.f10.f64 = double(float(ctx.f11.f64 / f22.f64));
	// fmuls f13,f13,f15
	ctx.f13.f64 = double(float(ctx.f13.f64 * f15.f64));
	// fsubs f12,f17,f8
	ctx.f12.f64 = double(float(f17.f64 - ctx.f8.f64));
	// fmadds f4,f26,f24,f6
	ctx.f4.f64 = double(float(f26.f64 * f24.f64 + ctx.f6.f64));
	// fmadds f3,f7,f9,f5
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmuls f0,f4,f0
	f0.f64 = double(float(ctx.f4.f64 * f0.f64));
	// fmuls f11,f1,f3
	ctx.f11.f64 = double(float(ctx.f1.f64 * ctx.f3.f64));
	// beq cr6,0x823d550c
	if (cr6.eq) goto loc_823D550C;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x823d5524
	if (cr6.eq) goto loc_823D5524;
loc_823D550C:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
	// fmr f13,f31
	ctx.f13.f64 = f31.f64;
	// fmr f12,f31
	ctx.f12.f64 = f31.f64;
	// fmr f11,f31
	ctx.f11.f64 = f31.f64;
	// fmr f21,f31
	f21.f64 = f31.f64;
	// fmr f20,f31
	f20.f64 = f31.f64;
loc_823D5524:
	// fadds f11,f11,f21
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f11.f64 + f21.f64));
	// lfs f9,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f9.f64 = double(temp.f32);
	// fadds f8,f0,f10
	ctx.f8.f64 = double(float(f0.f64 + ctx.f10.f64));
	// fadds f7,f11,f20
	ctx.f7.f64 = double(float(ctx.f11.f64 + f20.f64));
	// fadds f27,f8,f13
	f27.f64 = double(float(ctx.f8.f64 + ctx.f13.f64));
	// fdivs f6,f7,f28
	ctx.f6.f64 = double(float(ctx.f7.f64 / f28.f64));
	// fadds f5,f6,f12
	ctx.f5.f64 = double(float(ctx.f6.f64 + ctx.f12.f64));
	// fadds f26,f5,f9
	f26.f64 = double(float(ctx.f5.f64 + ctx.f9.f64));
	// b 0x823d5550
	goto loc_823D5550;
loc_823D5548:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f27,3800(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3800);
	f27.f64 = double(temp.f32);
loc_823D5550:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r10,r11,18640
	ctx.r10.s64 = r11.s64 + 18640;
	// stw r10,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r10.u32);
	// stw r10,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r10.u32);
loc_823D5560:
	// lvx128 v45,r0,r30
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcmpu cr6,f14,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f14.f64, f31.f64);
	// vspltw128 v44,v45,0
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0xFF));
	// lvx128 v43,r0,r29
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r0,r27
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v41,v43,0
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), 0xFF));
	// lvx128 v40,r0,r31
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v39,v42,0
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), 0xFF));
	// vspltw128 v38,v40,0
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0xFF));
	// vmulfp128 v37,v125,v44
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v37.f32, simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v44.f32)));
	// vspltw128 v36,v45,1
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0xAA));
	// vmulfp128 v35,v125,v41
	simde_mm_store_ps(v35.f32, simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v41.f32)));
	// vspltw128 v34,v43,1
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), 0xAA));
	// vmulfp128 v33,v125,v39
	simde_mm_store_ps(v33.f32, simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v39.f32)));
	// vspltw128 v32,v42,1
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), 0xAA));
	// vmaddfp128 v120,v125,v38,v120
	simde_mm_store_ps(v120.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v38.f32)), simde_mm_load_ps(v120.f32)));
	// vspltw128 v63,v40,1
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0xAA));
	// vspltw128 v62,v45,2
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0x55));
	// vspltw128 v61,v43,2
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), 0x55));
	// vspltw128 v60,v42,2
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), 0x55));
	// vspltw128 v59,v40,2
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0x55));
	// vmaddfp128 v37,v126,v36,v37
	simde_mm_store_ps(v37.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v36.f32)), simde_mm_load_ps(v37.f32)));
	// vmaddfp128 v35,v126,v34,v35
	simde_mm_store_ps(v35.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v34.f32)), simde_mm_load_ps(v35.f32)));
	// vmaddfp128 v33,v126,v32,v33
	simde_mm_store_ps(v33.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v32.f32)), simde_mm_load_ps(v33.f32)));
	// vmaddfp128 v120,v126,v63,v120
	simde_mm_store_ps(v120.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v63.f32)), simde_mm_load_ps(v120.f32)));
	// vor128 v0,v37,v37
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v37.u8));
	// vmaddfp128 v35,v127,v61,v35
	simde_mm_store_ps(v35.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v61.f32)), simde_mm_load_ps(v35.f32)));
	// vmaddfp128 v33,v127,v60,v33
	simde_mm_store_ps(v33.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v60.f32)), simde_mm_load_ps(v33.f32)));
	// vmaddfp128 v120,v127,v59,v120
	simde_mm_store_ps(v120.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v59.f32)), simde_mm_load_ps(v120.f32)));
	// vmaddfp128 v0,v127,v62,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v62.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v35,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v33,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v120,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v120.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x823d55f8
	if (cr6.eq) goto loc_823D55F8;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d5698
	if (cr6.eq) goto loc_823D5698;
loc_823D55F8:
	// lwz r10,144(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 144);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d561c
	if (cr6.eq) goto loc_823D561C;
	// lwz r9,656(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// bne cr6,0x823d561c
	if (!cr6.eq) goto loc_823D561C;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// b 0x823d5620
	goto loc_823D5620;
loc_823D561C:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823D5620:
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d5698
	if (cr6.eq) goto loc_823D5698;
	// lwz r31,8(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d5698
	if (cr6.eq) goto loc_823D5698;
	// lbz r11,152(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d5698
	if (!cr6.eq) goto loc_823D5698;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// fneg f0,f30
	ctx.fpscr.disableFlushMode();
	f0.u64 = f30.u64 ^ 0x8000000000000000;
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r10,r1,288
	ctx.r10.s64 = ctx.r1.s64 + 288;
	// fmuls f13,f30,f26
	ctx.f13.f64 = double(float(f30.f64 * f26.f64));
	// stfs f31,240(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f13,244(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f31,248(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// lvlx128 v58,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vmulfp128 v56,v0,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v57.f32)));
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// addi r5,r1,288
	ctx.r5.s64 = ctx.r1.s64 + 288;
	// lfs f2,30712(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 30712);
	ctx.f2.f64 = double(temp.f32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// fmr f1,f19
	ctx.f1.f64 = f19.f64;
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a9930
	ctx.lr = 0x823D5694;
	sub_822A9930(ctx, base);
	// stw r25,624(r31)
	PPC_STORE_U32(r31.u32 + 624, r25.u32);
loc_823D5698:
	// lwz r11,144(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 144);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d56f4
	if (cr6.eq) goto loc_823D56F4;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d56f4
	if (cr6.eq) goto loc_823D56F4;
	// lwz r3,68(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823d56f4
	if (cr6.eq) goto loc_823D56F4;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r4,824(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 824);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823D56D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823d56f4
	if (cr6.eq) goto loc_823D56F4;
	// lwz r11,144(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 144);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,68(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// stfs f27,12(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// stfs f26,16(r9)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r9.u32 + 16, temp.u32);
loc_823D56F4:
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-224
	r12.s64 = ctx.r1.s64 + -224;
	// bl 0x823dd7ac
	ctx.lr = 0x823D5700;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823db9ec
	ctx.lr = 0x823D5708;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823D570C"))) PPC_WEAK_FUNC(sub_823D570C);
PPC_FUNC_IMPL(__imp__sub_823D570C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D5710"))) PPC_WEAK_FUNC(sub_823D5710);
PPC_FUNC_IMPL(__imp__sub_823D5710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-16048
	ctx.r9.s64 = ctx.r10.s64 + -16048;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// sth r11,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r11.u16);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D5748"))) PPC_WEAK_FUNC(sub_823D5748);
PPC_FUNC_IMPL(__imp__sub_823D5748) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x823D5750;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// mr r24,r9
	r24.u64 = ctx.r9.u64;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823d5790
	if (cr6.eq) goto loc_823D5790;
	// bl 0x822a86e8
	ctx.lr = 0x823D5784;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d5858
	if (cr6.eq) goto loc_823D5858;
loc_823D5790:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,3998
	ctx.r9.s64 = r11.s64 + 3998;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8239e458
	ctx.lr = 0x823D57B8;
	sub_8239E458(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8239e348
	ctx.lr = 0x823D57C0;
	sub_8239E348(ctx, base);
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// addi r11,r30,4
	r11.s64 = r30.s64 + 4;
	// sth r8,8(r30)
	PPC_STORE_U16(r30.u32 + 8, ctx.r8.u16);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stwx r31,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r31.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,16(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x823D57F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823d5804
	if (cr6.eq) goto loc_823D5804;
	// lwz r5,16(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// b 0x823d5808
	goto loc_823D5808;
loc_823D5804:
	// li r5,0
	ctx.r5.s64 = 0;
loc_823D5808:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823a4100
	ctx.lr = 0x823D5824;
	sub_823A4100(ctx, base);
	// stw r26,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r26.u32);
	// stfs f31,156(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 156, temp.u32);
	// stw r29,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r29.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stb r24,152(r31)
	PPC_STORE_U8(r31.u32 + 152, r24.u8);
	// beq cr6,0x823d5850
	if (cr6.eq) goto loc_823D5850;
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d5850
	if (cr6.eq) goto loc_823D5850;
	// addi r3,r11,44
	ctx.r3.s64 = r11.s64 + 44;
	// bl 0x821ce0d8
	ctx.lr = 0x823D5850;
	sub_821CE0D8(ctx, base);
loc_823D5850:
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82130588
	ctx.lr = 0x823D5858;
	sub_82130588(ctx, base);
loc_823D5858:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823D5868"))) PPC_WEAK_FUNC(sub_823D5868);
PPC_FUNC_IMPL(__imp__sub_823D5868) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x823D5870;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d58e0
	if (cr6.eq) goto loc_823D58E0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x823D588C;
	sub_82130588(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d58e0
	if (cr6.eq) goto loc_823D58E0;
	// lwz r11,-4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// addi r28,r10,-4
	r28.s64 = ctx.r10.s64 + -4;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addic. r31,r11,-1
	xer.ca = r11.u32 > 0;
	r31.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r30,r11,r10
	r30.u64 = r11.u64 + ctx.r10.u64;
	// blt 0x823d58d8
	if (cr0.lt) goto loc_823D58D8;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r29,r11,-15168
	r29.s64 = r11.s64 + -15168;
loc_823D58C0:
	// addi r30,r30,-24
	r30.s64 = r30.s64 + -24;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x823D58D0;
	sub_82130588(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x823d58c0
	if (!cr0.lt) goto loc_823D58C0;
loc_823D58D8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x823D58E0;
	sub_82130588(ctx, base);
loc_823D58E0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823D58E8"))) PPC_WEAK_FUNC(sub_823D58E8);
PPC_FUNC_IMPL(__imp__sub_823D58E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x823D58F0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r26,r11,-15168
	r26.s64 = r11.s64 + -15168;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d5964
	if (cr6.eq) goto loc_823D5964;
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x823D5918;
	sub_82130588(ctx, base);
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d5964
	if (cr6.eq) goto loc_823D5964;
	// lwz r11,-4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// addi r28,r10,-4
	r28.s64 = ctx.r10.s64 + -4;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addic. r31,r11,-1
	xer.ca = r11.u32 > 0;
	r31.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r30,r11,r10
	r30.u64 = r11.u64 + ctx.r10.u64;
	// blt 0x823d595c
	if (cr0.lt) goto loc_823D595C;
loc_823D5944:
	// addi r30,r30,-24
	r30.s64 = r30.s64 + -24;
	// stw r26,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r26.u32);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x823D5954;
	sub_82130588(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x823d5944
	if (!cr0.lt) goto loc_823D5944;
loc_823D595C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x823D5964;
	sub_82130588(ctx, base);
loc_823D5964:
	// rlwinm r11,r27,31,1,31
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 31) & 0x7FFFFFFF;
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// rlwinm r8,r11,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// li r31,-1
	r31.s64 = -1;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | r11.u64;
	// rlwinm r6,r7,30,2,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x3FFFFFFF;
	// or r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 | ctx.r7.u64;
	// rlwinm r4,r5,28,4,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 28) & 0xFFFFFFF;
	// or r3,r4,r5
	ctx.r3.u64 = ctx.r4.u64 | ctx.r5.u64;
	// rlwinm r11,r3,24,8,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xFFFFFF;
	// or r10,r11,r3
	ctx.r10.u64 = r11.u64 | ctx.r3.u64;
	// rlwinm r8,r10,16,16,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF;
	// or r11,r8,r10
	r11.u64 = ctx.r8.u64 | ctx.r10.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x823d59b8
	if (!cr6.gt) goto loc_823D59B8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823D59B8:
	// bl 0x82130528
	ctx.lr = 0x823D59BC;
	sub_82130528(ctx, base);
	// lis r11,2730
	r11.s64 = 178913280;
	// stw r3,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r3.u32);
	// ori r10,r11,43690
	ctx.r10.u64 = r11.u64 | 43690;
	// cmplw cr6,r27,r10
	cr6.compare<uint32_t>(r27.u32, ctx.r10.u32, xer);
	// bgt cr6,0x823d59ec
	if (cr6.gt) goto loc_823D59EC;
	// rlwinm r11,r27,1,0,30
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,-5
	ctx.r10.s64 = -5;
	// add r9,r27,r11
	ctx.r9.u64 = r27.u64 + r11.u64;
	// rlwinm r11,r9,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// ble cr6,0x823d59f0
	if (!cr6.gt) goto loc_823D59F0;
loc_823D59EC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823D59F0:
	// bl 0x82130528
	ctx.lr = 0x823D59F4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// beq cr6,0x823d5a48
	if (cr6.eq) goto loc_823D5A48;
	// addi r7,r3,4
	ctx.r7.s64 = ctx.r3.s64 + 4;
	// stw r27,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r27.u32);
	// addic. r9,r27,-1
	xer.ca = r27.u32 > 0;
	ctx.r9.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// blt 0x823d5a40
	if (cr0.lt) goto loc_823D5A40;
	// addi r11,r8,10
	r11.s64 = ctx.r8.s64 + 10;
loc_823D5A18:
	// stw r26,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r26.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r10,-6(r11)
	PPC_STORE_U32(r11.u32 + -6, ctx.r10.u32);
	// addi r8,r8,24
	ctx.r8.s64 = ctx.r8.s64 + 24;
	// sth r10,-2(r11)
	PPC_STORE_U16(r11.u32 + -2, ctx.r10.u16);
	// sth r10,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r10.u16);
	// stw r10,2(r11)
	PPC_STORE_U32(r11.u32 + 2, ctx.r10.u32);
	// stw r10,6(r11)
	PPC_STORE_U32(r11.u32 + 6, ctx.r10.u32);
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// bge 0x823d5a18
	if (!cr0.lt) goto loc_823D5A18;
loc_823D5A40:
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// b 0x823d5a4c
	goto loc_823D5A4C;
loc_823D5A48:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_823D5A4C:
	// addic. r11,r27,-1
	xer.ca = r27.u32 > 0;
	r11.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r9,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r9.u32);
	// stw r10,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r10.u32);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// stw r9,16(r29)
	PPC_STORE_U32(r29.u32 + 16, ctx.r9.u32);
	// beq 0x823d5a88
	if (cr0.eq) goto loc_823D5A88;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
loc_823D5A6C:
	// lwz r8,16(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r9,24
	ctx.r9.s64 = ctx.r9.s64 + 24;
	// addi r6,r8,24
	ctx.r6.s64 = ctx.r8.s64 + 24;
	// stw r6,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, ctx.r6.u32);
	// bne 0x823d5a6c
	if (!cr0.eq) goto loc_823D5A6C;
loc_823D5A88:
	// rlwinm r11,r7,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,16(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// li r4,0
	ctx.r4.s64 = 0;
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r5,r8,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x823d9890
	ctx.lr = 0x823D5AB4;
	sub_823D9890(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823D5ABC"))) PPC_WEAK_FUNC(sub_823D5ABC);
PPC_FUNC_IMPL(__imp__sub_823D5ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D5AC0"))) PPC_WEAK_FUNC(sub_823D5AC0);
PPC_FUNC_IMPL(__imp__sub_823D5AC0) {
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
	// lwz r10,12(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// and r30,r9,r10
	r30.u64 = ctx.r9.u64 & ctx.r10.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x823ca020
	ctx.lr = 0x823D5AF4;
	sub_823CA020(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d5b48
	if (cr6.eq) goto loc_823D5B48;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d5b18
	if (cr6.eq) goto loc_823D5B18;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// stw r9,20(r10)
	PPC_STORE_U32(ctx.r10.u32 + 20, ctx.r9.u32);
	// b 0x823d5b28
	goto loc_823D5B28;
loc_823D5B18:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_823D5B28:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// b 0x823d5b4c
	goto loc_823D5B4C;
loc_823D5B48:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823D5B4C:
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

__attribute__((alias("__imp__sub_823D5B64"))) PPC_WEAK_FUNC(sub_823D5B64);
PPC_FUNC_IMPL(__imp__sub_823D5B64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D5B68"))) PPC_WEAK_FUNC(sub_823D5B68);
PPC_FUNC_IMPL(__imp__sub_823D5B68) {
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
	// bl 0x823a44d8
	ctx.lr = 0x823D5B80;
	sub_823A44D8(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// addi r10,r11,-15160
	ctx.r10.s64 = r11.s64 + -15160;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x823D5B94;
	sub_821B5A60(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,148(r31)
	PPC_STORE_U32(r31.u32 + 148, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_823D5BB4"))) PPC_WEAK_FUNC(sub_823D5BB4);
PPC_FUNC_IMPL(__imp__sub_823D5BB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D5BB8"))) PPC_WEAK_FUNC(sub_823D5BB8);
PPC_FUNC_IMPL(__imp__sub_823D5BB8) {
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
	ctx.lr = 0x823D5BC0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// stw r29,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r29.u32);
	// lwz r11,148(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d5c4c
	if (cr6.eq) goto loc_823D5C4C;
	// lwz r30,16(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r3,r30,44
	ctx.r3.s64 = r30.s64 + 44;
	// bl 0x821ce100
	ctx.lr = 0x823D5BE8;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x823d5c20
	if (!cr6.eq) goto loc_823D5C20;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d5c4c
	if (cr6.eq) goto loc_823D5C4C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D5C10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823a4088
	ctx.lr = 0x823D5C18;
	sub_823A4088(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_823D5C20:
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x823d5c4c
	if (!cr6.eq) goto loc_823D5C4C;
	// lwz r11,148(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x823b7b70
	ctx.lr = 0x823D5C34;
	sub_823B7B70(ctx, base);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r4,148(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lwz r11,-27432(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27432);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x823d5ac0
	ctx.lr = 0x823D5C48;
	sub_823D5AC0(ctx, base);
	// stw r29,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r29.u32);
loc_823D5C4C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823a4088
	ctx.lr = 0x823D5C54;
	sub_823A4088(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823D5C5C"))) PPC_WEAK_FUNC(sub_823D5C5C);
PPC_FUNC_IMPL(__imp__sub_823D5C5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D5C60"))) PPC_WEAK_FUNC(sub_823D5C60);
PPC_FUNC_IMPL(__imp__sub_823D5C60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x823D5C68;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// bl 0x822a86e8
	ctx.lr = 0x823D5C80;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d5d1c
	if (cr6.eq) goto loc_823D5D1C;
	// lwz r11,48(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d5d1c
	if (cr6.eq) goto loc_823D5D1C;
	// lwz r11,76(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d5d1c
	if (cr6.eq) goto loc_823D5D1C;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r24,r11,8
	r24.s64 = r11.s64 + 8;
	// bl 0x82137248
	ctx.lr = 0x823D5CB4;
	sub_82137248(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823d4c40
	ctx.lr = 0x823D5CC0;
	sub_823D4C40(ctx, base);
	// lwz r3,16(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// and r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 & ctx.r10.u64;
	// bl 0x823c9fc8
	ctx.lr = 0x823D5CDC;
	sub_823C9FC8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r25,0
	r25.s64 = 0;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823d5eb8
	if (cr6.eq) goto loc_823D5EB8;
	// lwz r10,16(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823d5d28
	if (!cr6.eq) goto loc_823D5D28;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r11,-14980
	ctx.r3.s64 = r11.s64 + -14980;
loc_823D5D04:
	// bl 0x82130000
	ctx.lr = 0x823D5D08;
	sub_82130000(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r9,r10,-15168
	ctx.r9.s64 = ctx.r10.s64 + -15168;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// bl 0x82130588
	ctx.lr = 0x823D5D1C;
	sub_82130588(ctx, base);
loc_823D5D1C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9230
	return;
loc_823D5D28:
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d5d4c
	if (cr6.eq) goto loc_823D5D4C;
	// lwz r9,656(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// bne cr6,0x823d5d4c
	if (!cr6.eq) goto loc_823D5D4C;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d5d5c
	if (!cr6.eq) goto loc_823D5D5C;
loc_823D5D4C:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r11,-15040
	ctx.r3.s64 = r11.s64 + -15040;
	// b 0x823d5d04
	goto loc_823D5D04;
loc_823D5D5C:
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d5d7c
	if (cr6.eq) goto loc_823D5D7C;
	// lwz r9,656(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// bne cr6,0x823d5d7c
	if (!cr6.eq) goto loc_823D5D7C;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// b 0x823d5d80
	goto loc_823D5D80;
loc_823D5D7C:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823D5D80:
	// lwz r11,76(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823d5d9c
	if (!cr6.eq) goto loc_823D5D9C;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r11,-15100
	ctx.r3.s64 = r11.s64 + -15100;
	// b 0x823d5d04
	goto loc_823D5D04;
loc_823D5D9C:
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d5dbc
	if (cr6.eq) goto loc_823D5DBC;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x823d5dbc
	if (!cr6.eq) goto loc_823D5DBC;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// b 0x823d5dc0
	goto loc_823D5DC0;
loc_823D5DBC:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_823D5DC0:
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mr r11,r24
	r11.u64 = r24.u64;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
loc_823D5DCC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x823d5df0
	if (cr6.eq) goto loc_823D5DF0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823d5dcc
	if (cr6.eq) goto loc_823D5DCC;
loc_823D5DF0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x823d5e18
	if (!cr6.eq) goto loc_823D5E18;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r10,r11,-15168
	ctx.r10.s64 = r11.s64 + -15168;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// bl 0x82130588
	ctx.lr = 0x823D5E0C;
	sub_82130588(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9230
	return;
loc_823D5E18:
	// lhz r11,8(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 8);
	// mr r28,r25
	r28.u64 = r25.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d5eb8
	if (cr6.eq) goto loc_823D5EB8;
	// addi r30,r26,4
	r30.s64 = r26.s64 + 4;
	// mr r31,r25
	r31.u64 = r25.u64;
loc_823D5E30:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r29,16(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwz r9,144(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// cmpw cr6,r9,r29
	cr6.compare<int32_t>(ctx.r9.s32, r29.s32, xer);
	// bne cr6,0x823d5ea4
	if (!cr6.eq) goto loc_823D5EA4;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823d5e60
	if (cr6.eq) goto loc_823D5E60;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823D5E58;
	sub_82130588(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x823D5E60;
	sub_82130588(ctx, base);
loc_823D5E60:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,16(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// bl 0x823d5ac0
	ctx.lr = 0x823D5E6C;
	sub_823D5AC0(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d5e90
	if (cr6.eq) goto loc_823D5E90;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D5E90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D5E90:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stwx r25,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, r25.u32);
	// bl 0x8262cb88
	ctx.lr = 0x823D5EA4;
	sub_8262CB88(ctx, base);
loc_823D5EA4:
	// lhz r11,8(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 8);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x823d5e30
	if (cr6.lt) goto loc_823D5E30;
loc_823D5EB8:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// addi r3,r11,-15136
	ctx.r3.s64 = r11.s64 + -15136;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x82130000
	ctx.lr = 0x823D5ECC;
	sub_82130000(ctx, base);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x823D5ED4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d5ef8
	if (cr6.eq) goto loc_823D5EF8;
	// stw r25,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r25.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r25,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r25.u32);
	// stw r25,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r25.u32);
	// stw r25,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r25.u32);
	// stw r25,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r25.u32);
	// b 0x823d5efc
	goto loc_823D5EFC;
loc_823D5EF8:
	// mr r31,r25
	r31.u64 = r25.u64;
loc_823D5EFC:
	// stw r22,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r22.u32);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821378b8
	ctx.lr = 0x823D5F08;
	sub_821378B8(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137248
	ctx.lr = 0x823D5F18;
	sub_82137248(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x823d4bb0
	ctx.lr = 0x823D5F28;
	sub_823D4BB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,16(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// bl 0x823d4b28
	ctx.lr = 0x823D5F34;
	sub_823D4B28(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lwz r3,132(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// addi r31,r11,-15168
	r31.s64 = r11.s64 + -15168;
	// stw r31,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r31.u32);
	// bl 0x82130588
	ctx.lr = 0x823D5F48;
	sub_82130588(ctx, base);
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82130588
	ctx.lr = 0x823D5F54;
	sub_82130588(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_823D5F60"))) PPC_WEAK_FUNC(sub_823D5F60);
PPC_FUNC_IMPL(__imp__sub_823D5F60) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x823D5F68;
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// addi r5,r11,-14056
	ctx.r5.s64 = r11.s64 + -14056;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,255
	ctx.r4.s64 = 255;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82137a08
	ctx.lr = 0x823D5F94;
	sub_82137A08(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// sth r29,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r29.u16);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// sth r29,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r29.u16);
loc_823D5FAC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823d5fac
	if (!cr6.eq) goto loc_823D5FAC;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823D5FD4;
	sub_821C9650(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823c9e48
	ctx.lr = 0x823D5FE0;
	sub_823C9E48(ctx, base);
	// lwz r3,12(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// and r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 & ctx.r10.u64;
	// bl 0x823c9fc8
	ctx.lr = 0x823D5FFC;
	sub_823C9FC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d6024
	if (cr6.eq) goto loc_823D6024;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r10,r11,-17996
	ctx.r10.s64 = r11.s64 + -17996;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// bl 0x82130588
	ctx.lr = 0x823D6018;
	sub_82130588(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// b 0x823d9244
	return;
loc_823D6024:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x823D6038;
	sub_821CA540(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82507720
	ctx.lr = 0x823D604C;
	sub_82507720(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r28,r11,-17996
	r28.s64 = r11.s64 + -17996;
	// beq cr6,0x823d60dc
	if (cr6.eq) goto loc_823D60DC;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r29,1
	r29.s64 = 1;
	// addi r3,r11,-17656
	ctx.r3.s64 = r11.s64 + -17656;
	// bl 0x82130000
	ctx.lr = 0x823D6074;
	sub_82130000(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f1,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// lfs f0,27632(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27632);
	f0.f64 = double(temp.f32);
	// addi r3,r8,-17692
	ctx.r3.s64 = ctx.r8.s64 + -17692;
	// lfs f13,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f2,f1,f0,f13
	ctx.f2.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f13.f64));
	// stfd f2,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f2.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x82130000
	ctx.lr = 0x823D60A8;
	sub_82130000(ctx, base);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137248
	ctx.lr = 0x823D60B4;
	sub_82137248(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x823c9db8
	ctx.lr = 0x823D60C4;
	sub_823C9DB8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,12(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// bl 0x823d4b28
	ctx.lr = 0x823D60D0;
	sub_823D4B28(ctx, base);
	// stw r28,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r28.u32);
	// lwz r3,132(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x82130588
	ctx.lr = 0x823D60DC;
	sub_82130588(ctx, base);
loc_823D60DC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x823D60E4;
	sub_821C9A90(ctx, base);
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r28.u32);
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82130588
	ctx.lr = 0x823D60F0;
	sub_82130588(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823D60FC"))) PPC_WEAK_FUNC(sub_823D60FC);
PPC_FUNC_IMPL(__imp__sub_823D60FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D6100"))) PPC_WEAK_FUNC(sub_823D6100);
PPC_FUNC_IMPL(__imp__sub_823D6100) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x823D6108;
	// stfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// li r26,0
	r26.s64 = 0;
	// mr r28,r26
	r28.u64 = r26.u64;
	// mr r31,r26
	r31.u64 = r26.u64;
	// lhz r11,8(r22)
	r11.u64 = PPC_LOAD_U16(r22.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d6184
	if (cr6.eq) goto loc_823D6184;
	// mr r30,r26
	r30.u64 = r26.u64;
	// addi r29,r1,128
	r29.s64 = ctx.r1.s64 + 128;
loc_823D6138:
	// lwz r11,4(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 4);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,132(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x823d6158
	if (cr6.lt) goto loc_823D6158;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823a4360
	ctx.lr = 0x823D6154;
	sub_823A4360(ctx, base);
	// b 0x823d6170
	goto loc_823D6170;
loc_823D6158:
	// lbz r11,129(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 129);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d6170
	if (cr6.eq) goto loc_823D6170;
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
loc_823D6170:
	// lhz r11,8(r22)
	r11.u64 = PPC_LOAD_U16(r22.u32 + 8);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x823d6138
	if (cr6.lt) goto loc_823D6138;
loc_823D6184:
	// addic. r24,r28,-1
	xer.ca = r28.u32 > 0;
	r24.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// blt 0x823d6378
	if (cr0.lt) goto loc_823D6378;
	// rlwinm r10,r24,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lis r9,0
	ctx.r9.s64 = 0;
	// add r25,r10,r11
	r25.u64 = ctx.r10.u64 + r11.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r31,r22,4
	r31.s64 = r22.s64 + 4;
	// ori r21,r9,65535
	r21.u64 = ctx.r9.u64 | 65535;
	// addi r20,r10,3998
	r20.s64 = ctx.r10.s64 + 3998;
	// addi r23,r11,-15168
	r23.s64 = r11.s64 + -15168;
loc_823D61B4:
	// lwz r27,0(r25)
	r27.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r28,r27,2,0,29
	r28.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r28,r11
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// lwz r9,144(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// sth r26,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r26.u16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// sth r26,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r26.u16);
	// beq cr6,0x823d6208
	if (cr6.eq) goto loc_823D6208;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_823D61E4:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823d61e4
	if (!cr6.eq) goto loc_823D61E4;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823D6208;
	sub_821C9650(ctx, base);
loc_823D6208:
	// stw r23,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r23.u32);
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// sth r26,106(r1)
	PPC_STORE_U16(ctx.r1.u32 + 106, r26.u16);
	// stw r26,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r26.u32);
	// stw r26,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r26.u32);
	// sth r26,104(r1)
	PPC_STORE_U16(ctx.r1.u32 + 104, r26.u16);
	// lhz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x821c9650
	ctx.lr = 0x823D6230;
	sub_821C9650(ctx, base);
	// lhz r9,104(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 104);
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823d6244
	if (!cr6.eq) goto loc_823D6244;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
loc_823D6244:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821c9790
	ctx.lr = 0x823D624C;
	sub_821C9790(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82130588
	ctx.lr = 0x823D6258;
	sub_82130588(ctx, base);
	// lwz r9,16(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 16);
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// and r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 & ctx.r10.u64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r5,r8
	r30.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d62e8
	if (cr6.eq) goto loc_823D62E8;
loc_823D6280:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d6298
	if (cr6.eq) goto loc_823D6298;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x823d629c
	if (cr6.eq) goto loc_823D629C;
loc_823D6298:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_823D629C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d62b8
	if (!cr6.eq) goto loc_823D62B8;
	// lwz r30,20(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x823d6280
	if (!cr6.eq) goto loc_823D6280;
	// b 0x823d62e8
	goto loc_823D62E8;
loc_823D62B8:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d62e8
	if (cr6.eq) goto loc_823D62E8;
	// lwz r29,16(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823d62dc
	if (cr6.eq) goto loc_823D62DC;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823D62D4;
	sub_82130588(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x823D62DC;
	sub_82130588(ctx, base);
loc_823D62DC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,16(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + 16);
	// bl 0x823d5ac0
	ctx.lr = 0x823D62E8;
	sub_823D5AC0(ctx, base);
loc_823D62E8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r3,r28,r11
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d630c
	if (cr6.eq) goto loc_823D630C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D630C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D630C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r11,r27,16
	r11.u64 = r27.u32 & 0xFFFF;
	// stwx r26,r28,r10
	PPC_STORE_U32(r28.u32 + ctx.r10.u32, r26.u32);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x823d6354
	if (!cr6.lt) goto loc_823D6354;
loc_823D6328:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x823d6328
	if (cr6.lt) goto loc_823D6328;
loc_823D6354:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// stw r23,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r23.u32);
	// add r10,r11,r21
	ctx.r10.u64 = r11.u64 + r21.u64;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// sth r10,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r10.u16);
	// bl 0x82130588
	ctx.lr = 0x823D636C;
	sub_82130588(ctx, base);
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r25,r25,-4
	r25.s64 = r25.s64 + -4;
	// bge 0x823d61b4
	if (!cr0.lt) goto loc_823D61B4;
loc_823D6378:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_823D6384"))) PPC_WEAK_FUNC(sub_823D6384);
PPC_FUNC_IMPL(__imp__sub_823D6384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D6388"))) PPC_WEAK_FUNC(sub_823D6388);
PPC_FUNC_IMPL(__imp__sub_823D6388) {
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
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// addi r5,r11,-14056
	ctx.r5.s64 = r11.s64 + -14056;
	// li r4,255
	ctx.r4.s64 = 255;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82137a08
	ctx.lr = 0x823D63B8;
	sub_82137A08(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// sth r10,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, ctx.r10.u16);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// sth r10,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r10.u16);
loc_823D63D0:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823d63d0
	if (!cr6.eq) goto loc_823D63D0;
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823D63F8;
	sub_821C9650(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823c9e48
	ctx.lr = 0x823D6404;
	sub_823C9E48(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// and r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 & ctx.r10.u64;
	// bl 0x823c9fc8
	ctx.lr = 0x823D6420;
	sub_823C9FC8(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r10,r11,-17996
	ctx.r10.s64 = r11.s64 + -17996;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// beq cr6,0x823d6458
	if (cr6.eq) goto loc_823D6458;
	// bl 0x82130588
	ctx.lr = 0x823D6440;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_823D6458:
	// bl 0x82130588
	ctx.lr = 0x823D645C;
	sub_82130588(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D6474"))) PPC_WEAK_FUNC(sub_823D6474);
PPC_FUNC_IMPL(__imp__sub_823D6474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D6478"))) PPC_WEAK_FUNC(sub_823D6478);
PPC_FUNC_IMPL(__imp__sub_823D6478) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// sth r11,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r11.u16);
	// sth r11,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r11.u16);
	// beq cr6,0x823d64cc
	if (cr6.eq) goto loc_823D64CC;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_823D64A8:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823d64a8
	if (!cr6.eq) goto loc_823D64A8;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823D64CC;
	sub_821C9650(ctx, base);
loc_823D64CC:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823d4c40
	ctx.lr = 0x823D64D8;
	sub_823D4C40(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// and r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 & ctx.r10.u64;
	// bl 0x823c9fc8
	ctx.lr = 0x823D64F4;
	sub_823C9FC8(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r10,r11,-15168
	ctx.r10.s64 = r11.s64 + -15168;
	// beq cr6,0x823d652c
	if (cr6.eq) goto loc_823D652C;
	// lwz r31,16(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82130588
	ctx.lr = 0x823D6514;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_823D652C:
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82130588
	ctx.lr = 0x823D6538;
	sub_82130588(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D6550"))) PPC_WEAK_FUNC(sub_823D6550);
PPC_FUNC_IMPL(__imp__sub_823D6550) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x823D6558;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r25,r28
	r25.u64 = r28.u64;
	// lhz r11,8(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d6758
	if (cr6.eq) goto loc_823D6758;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r31,r26,4
	r31.s64 = r26.s64 + 4;
	// mr r27,r28
	r27.u64 = r28.u64;
	// ori r23,r9,65535
	r23.u64 = ctx.r9.u64 | 65535;
	// addi r22,r11,3998
	r22.s64 = r11.s64 + 3998;
	// addi r24,r10,-15168
	r24.s64 = ctx.r10.s64 + -15168;
loc_823D6594:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r10,r27,r11
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + r11.u32);
	// lwz r9,144(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// sth r28,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r28.u16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// sth r28,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r28.u16);
	// beq cr6,0x823d65e0
	if (cr6.eq) goto loc_823D65E0;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_823D65BC:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823d65bc
	if (!cr6.eq) goto loc_823D65BC;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823D65E0;
	sub_821C9650(ctx, base);
loc_823D65E0:
	// stw r24,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r24.u32);
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r28.u32);
	// sth r28,106(r1)
	PPC_STORE_U16(ctx.r1.u32 + 106, r28.u16);
	// stw r28,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r28.u32);
	// stw r28,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r28.u32);
	// sth r28,104(r1)
	PPC_STORE_U16(ctx.r1.u32 + 104, r28.u16);
	// lhz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x821c9650
	ctx.lr = 0x823D6608;
	sub_821C9650(ctx, base);
	// lhz r9,104(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 104);
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823d661c
	if (!cr6.eq) goto loc_823D661C;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
loc_823D661C:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821c9790
	ctx.lr = 0x823D6624;
	sub_821C9790(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82130588
	ctx.lr = 0x823D6630;
	sub_82130588(ctx, base);
	// lwz r9,16(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// and r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 & ctx.r10.u64;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r5,r8
	r30.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d66c0
	if (cr6.eq) goto loc_823D66C0;
loc_823D6658:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d6670
	if (cr6.eq) goto loc_823D6670;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x823d6674
	if (cr6.eq) goto loc_823D6674;
loc_823D6670:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_823D6674:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d6690
	if (!cr6.eq) goto loc_823D6690;
	// lwz r30,20(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x823d6658
	if (!cr6.eq) goto loc_823D6658;
	// b 0x823d66c0
	goto loc_823D66C0;
loc_823D6690:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d66c0
	if (cr6.eq) goto loc_823D66C0;
	// lwz r29,16(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823d66b4
	if (cr6.eq) goto loc_823D66B4;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823D66AC;
	sub_82130588(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x823D66B4;
	sub_82130588(ctx, base);
loc_823D66B4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,16(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// bl 0x823d5ac0
	ctx.lr = 0x823D66C0;
	sub_823D5AC0(ctx, base);
loc_823D66C0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r3,r27,r11
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d66e4
	if (cr6.eq) goto loc_823D66E4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D66E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D66E4:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r11,r25,16
	r11.u64 = r25.u32 & 0xFFFF;
	// stwx r28,r27,r10
	PPC_STORE_U32(r27.u32 + ctx.r10.u32, r28.u32);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x823d672c
	if (!cr6.lt) goto loc_823D672C;
loc_823D6700:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x823d6700
	if (cr6.lt) goto loc_823D6700;
loc_823D672C:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// stw r24,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r24.u32);
	// add r10,r11,r23
	ctx.r10.u64 = r11.u64 + r23.u64;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// sth r10,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r10.u16);
	// bl 0x82130588
	ctx.lr = 0x823D6744;
	sub_82130588(ctx, base);
	// lhz r8,8(r26)
	ctx.r8.u64 = PPC_LOAD_U16(r26.u32 + 8);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r25,r8
	cr6.compare<int32_t>(r25.s32, ctx.r8.s32, xer);
	// blt cr6,0x823d6594
	if (cr6.lt) goto loc_823D6594;
loc_823D6758:
	// lwz r3,4(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x823D6760;
	sub_82130588(ctx, base);
	// sth r28,8(r26)
	PPC_STORE_U16(r26.u32 + 8, r28.u16);
	// sth r28,10(r26)
	PPC_STORE_U16(r26.u32 + 10, r28.u16);
	// stw r28,4(r26)
	PPC_STORE_U32(r26.u32 + 4, r28.u32);
	// lwz r31,16(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d6788
	if (cr6.eq) goto loc_823D6788;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d5868
	ctx.lr = 0x823D6780;
	sub_823D5868(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x823D6788;
	sub_82130588(ctx, base);
loc_823D6788:
	// lwz r31,12(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// stw r28,16(r26)
	PPC_STORE_U32(r26.u32 + 16, r28.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d67a8
	if (cr6.eq) goto loc_823D67A8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823ca530
	ctx.lr = 0x823D67A0;
	sub_823CA530(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x823D67A8;
	sub_82130588(ctx, base);
loc_823D67A8:
	// stw r28,12(r26)
	PPC_STORE_U32(r26.u32 + 12, r28.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_823D67B4"))) PPC_WEAK_FUNC(sub_823D67B4);
PPC_FUNC_IMPL(__imp__sub_823D67B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D67B8"))) PPC_WEAK_FUNC(sub_823D67B8);
PPC_FUNC_IMPL(__imp__sub_823D67B8) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-15160
	ctx.r10.s64 = r11.s64 + -15160;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x823d5bb8
	ctx.lr = 0x823D67E4;
	sub_823D5BB8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823a42d8
	ctx.lr = 0x823D67EC;
	sub_823A42D8(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823d6804
	if (cr6.eq) goto loc_823D6804;
	// bl 0x82130588
	ctx.lr = 0x823D6800;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823D6804:
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

__attribute__((alias("__imp__sub_823D681C"))) PPC_WEAK_FUNC(sub_823D681C);
PPC_FUNC_IMPL(__imp__sub_823D681C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D6820"))) PPC_WEAK_FUNC(sub_823D6820);
PPC_FUNC_IMPL(__imp__sub_823D6820) {
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
	ctx.lr = 0x823D6828;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm r3,r31,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x823D6838;
	sub_82130528(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x823d68e4
	if (!cr6.gt) goto loc_823D68E4;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r30,r23
	r30.u64 = r23.u64;
	// mr r24,r31
	r24.u64 = r31.u64;
	// li r26,0
	r26.s64 = 0;
	// addi r25,r11,-15160
	r25.s64 = r11.s64 + -15160;
loc_823D6858:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d68d8
	if (cr6.eq) goto loc_823D68D8;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// lwzx r31,r28,r27
	r31.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d68d4
	if (cr6.eq) goto loc_823D68D4;
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823d68d4
	if (cr6.eq) goto loc_823D68D4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x823D688C;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823d68d4
	if (cr6.eq) goto loc_823D68D4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217d890
	ctx.lr = 0x823D68A0;
	sub_8217D890(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r31,r3,r11
	r31.u64 = ctx.r3.u64 + r11.u64;
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d68d8
	if (cr6.eq) goto loc_823D68D8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x823a44d8
	ctx.lr = 0x823D68C0;
	sub_823A44D8(ctx, base);
	// stw r25,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r25.u32);
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// bl 0x821b5a60
	ctx.lr = 0x823D68CC;
	sub_821B5A60(ctx, base);
	// stw r26,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r26.u32);
	// b 0x823d68d8
	goto loc_823D68D8;
loc_823D68D4:
	// stw r26,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r26.u32);
loc_823D68D8:
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x823d6858
	if (!cr0.eq) goto loc_823D6858;
loc_823D68E4:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_823D68F0"))) PPC_WEAK_FUNC(sub_823D68F0);
PPC_FUNC_IMPL(__imp__sub_823D68F0) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x823d6820
	ctx.lr = 0x823D6914;
	sub_823D6820(ctx, base);
	// li r11,16
	r11.s64 = 16;
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// li r3,20
	ctx.r3.s64 = 20;
	// sth r11,10(r30)
	PPC_STORE_U16(r30.u32 + 10, r11.u16);
	// bl 0x82130528
	ctx.lr = 0x823D6928;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r31,0
	r31.s64 = 0;
	// beq cr6,0x823d6948
	if (cr6.eq) goto loc_823D6948;
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r31.u32);
	// stw r31,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r31.u32);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// stw r31,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r31.u32);
	// b 0x823d694c
	goto loc_823D694C;
loc_823D6948:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823D694C:
	// stw r3,12(r30)
	PPC_STORE_U32(r30.u32 + 12, ctx.r3.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x823cb260
	ctx.lr = 0x823D6958;
	sub_823CB260(ctx, base);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x823D6960;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d697c
	if (cr6.eq) goto loc_823D697C;
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r31.u32);
	// stw r31,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r31.u32);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// stw r31,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r31.u32);
	// b 0x823d6980
	goto loc_823D6980;
loc_823D697C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823D6980:
	// stw r3,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r3.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x823d58e8
	ctx.lr = 0x823D698C;
	sub_823D58E8(ctx, base);
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

__attribute__((alias("__imp__sub_823D69A4"))) PPC_WEAK_FUNC(sub_823D69A4);
PPC_FUNC_IMPL(__imp__sub_823D69A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D69A8"))) PPC_WEAK_FUNC(sub_823D69A8);
PPC_FUNC_IMPL(__imp__sub_823D69A8) {
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
	// bl 0x824a4590
	ctx.lr = 0x823D69C0;
	sub_824A4590(ctx, base);
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

__attribute__((alias("__imp__sub_823D69D8"))) PPC_WEAK_FUNC(sub_823D69D8);
PPC_FUNC_IMPL(__imp__sub_823D69D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,364(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 364, temp.u32);
	// b 0x824a4680
	sub_824A4680(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823D69E0"))) PPC_WEAK_FUNC(sub_823D69E0);
PPC_FUNC_IMPL(__imp__sub_823D69E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r11,360(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 360);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lfs f0,364(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 364);
	f0.f64 = double(temp.f32);
	// fadds f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 + ctx.f1.f64));
	// stfs f1,364(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 364, temp.u32);
	// b 0x824a48f8
	sub_824A48F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823D69FC"))) PPC_WEAK_FUNC(sub_823D69FC);
PPC_FUNC_IMPL(__imp__sub_823D69FC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D6A00"))) PPC_WEAK_FUNC(sub_823D6A00);
PPC_FUNC_IMPL(__imp__sub_823D6A00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,344(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 344);
	ctx.f13.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f0,31016(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	f0.f64 = double(temp.f32);
	// fadds f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 + f0.f64));
	// b 0x824a5038
	sub_824A5038(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823D6A18"))) PPC_WEAK_FUNC(sub_823D6A18);
PPC_FUNC_IMPL(__imp__sub_823D6A18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// stw r4,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r4.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// addi r10,r3,56
	ctx.r10.s64 = ctx.r3.s64 + 56;
	// stw r6,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r6.u32);
	// stw r8,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r8.u32);
	// stw r8,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r8.u32);
	// li r8,6
	ctx.r8.s64 = 6;
	// stw r7,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r7.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_823D6A44:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x823d6a44
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823D6A44;
	// stfs f1,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stw r9,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r9.u32);
	// stfs f2,8(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D6A68"))) PPC_WEAK_FUNC(sub_823D6A68);
PPC_FUNC_IMPL(__imp__sub_823D6A68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister temp{};
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r4,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r4.u32);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// addi r8,r3,56
	ctx.r8.s64 = ctx.r3.s64 + 56;
	// stw r10,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r10.u32);
	// stw r10,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r10.u32);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// stw r6,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r6.u32);
	// li r8,6
	ctx.r8.s64 = 6;
	// stw r7,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r7.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_823D6A98:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x823d6a98
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823D6A98;
	// stfs f1,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stw r9,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r9.u32);
	// stfs f2,8(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D6ABC"))) PPC_WEAK_FUNC(sub_823D6ABC);
PPC_FUNC_IMPL(__imp__sub_823D6ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D6AC0"))) PPC_WEAK_FUNC(sub_823D6AC0);
PPC_FUNC_IMPL(__imp__sub_823D6AC0) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82490568
	ctx.lr = 0x823D6AE0;
	sub_82490568(ctx, base);
	// lwz r8,32(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// addi r11,r30,56
	r11.s64 = r30.s64 + 56;
	// addi r10,r31,56
	ctx.r10.s64 = r31.s64 + 56;
	// li r9,6
	ctx.r9.s64 = 6;
	// stw r8,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r8.u32);
	// lwz r7,36(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// stw r7,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r7.u32);
	// lwz r6,40(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// stw r6,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r6.u32);
	// lwz r5,44(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// stw r5,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r5.u32);
	// lwz r4,48(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// stw r4,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r4.u32);
	// lwz r3,52(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// stw r3,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r3.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_823D6B20:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x823d6b20
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823D6B20;
	// lwz r11,80(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
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

__attribute__((alias("__imp__sub_823D6B54"))) PPC_WEAK_FUNC(sub_823D6B54);
PPC_FUNC_IMPL(__imp__sub_823D6B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D6B58"))) PPC_WEAK_FUNC(sub_823D6B58);
PPC_FUNC_IMPL(__imp__sub_823D6B58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r11,3208
	ctx.r6.s64 = r11.s64 + 3208;
	// addi r5,r10,3148
	ctx.r5.s64 = ctx.r10.s64 + 3148;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x823dedd8
	sub_823DEDD8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823D6B78"))) PPC_WEAK_FUNC(sub_823D6B78);
PPC_FUNC_IMPL(__imp__sub_823D6B78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister temp{};
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r4,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r4.u32);
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stw r10,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r10.u32);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// stw r6,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r6.u32);
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_823D6BA0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x823d6ba0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823D6BA0;
	// stfs f1,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stw r8,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r8.u32);
	// stfs f2,8(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D6BC4"))) PPC_WEAK_FUNC(sub_823D6BC4);
PPC_FUNC_IMPL(__imp__sub_823D6BC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D6BC8"))) PPC_WEAK_FUNC(sub_823D6BC8);
PPC_FUNC_IMPL(__imp__sub_823D6BC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister temp{};
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r4,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r4.u32);
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stw r10,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r10.u32);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// stw r6,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r6.u32);
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_823D6BF0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x823d6bf0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823D6BF0;
	// stfs f1,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stw r8,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r8.u32);
	// stfs f2,8(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D6C14"))) PPC_WEAK_FUNC(sub_823D6C14);
PPC_FUNC_IMPL(__imp__sub_823D6C14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D6C18"))) PPC_WEAK_FUNC(sub_823D6C18);
PPC_FUNC_IMPL(__imp__sub_823D6C18) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82490568
	ctx.lr = 0x823D6C38;
	sub_82490568(ctx, base);
	// lwz r8,32(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// addi r11,r30,48
	r11.s64 = r30.s64 + 48;
	// addi r10,r31,48
	ctx.r10.s64 = r31.s64 + 48;
	// li r9,6
	ctx.r9.s64 = 6;
	// stw r8,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r8.u32);
	// lwz r7,36(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// stw r7,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r7.u32);
	// lwz r6,40(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// stw r6,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r6.u32);
	// lwz r5,44(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// stw r5,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r5.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_823D6C68:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x823d6c68
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823D6C68;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
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

__attribute__((alias("__imp__sub_823D6C9C"))) PPC_WEAK_FUNC(sub_823D6C9C);
PPC_FUNC_IMPL(__imp__sub_823D6C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D6CA0"))) PPC_WEAK_FUNC(sub_823D6CA0);
PPC_FUNC_IMPL(__imp__sub_823D6CA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister temp{};
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r4,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r4.u32);
	// addi r9,r3,40
	ctx.r9.s64 = ctx.r3.s64 + 40;
	// stw r10,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r10.u32);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_823D6CC0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x823d6cc0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823D6CC0;
	// lbz r11,87(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stfs f1,64(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f2,68(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stfs f5,72(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stfs f3,4(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f4,8(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stb r11,76(r3)
	PPC_STORE_U8(ctx.r3.u32 + 76, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D6CF4"))) PPC_WEAK_FUNC(sub_823D6CF4);
PPC_FUNC_IMPL(__imp__sub_823D6CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D6CF8"))) PPC_WEAK_FUNC(sub_823D6CF8);
PPC_FUNC_IMPL(__imp__sub_823D6CF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister temp{};
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r4,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r4.u32);
	// addi r9,r3,40
	ctx.r9.s64 = ctx.r3.s64 + 40;
	// stw r10,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r10.u32);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_823D6D18:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x823d6d18
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823D6D18;
	// lbz r11,87(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stfs f1,64(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f2,68(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stfs f5,72(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stfs f3,4(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f4,8(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stb r11,76(r3)
	PPC_STORE_U8(ctx.r3.u32 + 76, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D6D4C"))) PPC_WEAK_FUNC(sub_823D6D4C);
PPC_FUNC_IMPL(__imp__sub_823D6D4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D6D50"))) PPC_WEAK_FUNC(sub_823D6D50);
PPC_FUNC_IMPL(__imp__sub_823D6D50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82490568
	ctx.lr = 0x823D6D70;
	sub_82490568(ctx, base);
	// lfs f0,64(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	f0.f64 = double(temp.f32);
	// addi r11,r31,40
	r11.s64 = r31.s64 + 40;
	// stfs f0,64(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 64, temp.u32);
	// addi r10,r30,40
	ctx.r10.s64 = r30.s64 + 40;
	// lfs f13,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// li r9,6
	ctx.r9.s64 = 6;
	// stfs f13,68(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 68, temp.u32);
	// lfs f12,72(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,72(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 72, temp.u32);
	// lbz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 76);
	// stb r8,76(r30)
	PPC_STORE_U8(r30.u32 + 76, ctx.r8.u8);
	// lwz r7,32(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// stw r7,32(r30)
	PPC_STORE_U32(r30.u32 + 32, ctx.r7.u32);
	// lwz r6,36(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r6,36(r30)
	PPC_STORE_U32(r30.u32 + 36, ctx.r6.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_823D6DB0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x823d6db0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823D6DB0;
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

__attribute__((alias("__imp__sub_823D6DDC"))) PPC_WEAK_FUNC(sub_823D6DDC);
PPC_FUNC_IMPL(__imp__sub_823D6DDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D6DE0"))) PPC_WEAK_FUNC(sub_823D6DE0);
PPC_FUNC_IMPL(__imp__sub_823D6DE0) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82490568
	ctx.lr = 0x823D6E00;
	sub_82490568(ctx, base);
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// stw r10,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r10.u32);
	// lfs f0,40(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 40);
	f0.f64 = double(temp.f32);
	// stfs f0,40(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// lfs f13,44(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,44(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
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

__attribute__((alias("__imp__sub_823D6E38"))) PPC_WEAK_FUNC(sub_823D6E38);
PPC_FUNC_IMPL(__imp__sub_823D6E38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r29{};
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r11,3108
	ctx.r6.s64 = r11.s64 + 3108;
	// addi r5,r10,3148
	ctx.r5.s64 = ctx.r10.s64 + 3148;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x823D6E6C;
	sub_823DEDD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d7104
	if (cr6.eq) goto loc_823D7104;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,91
	cr6.compare<uint32_t>(r11.u32, 91, xer);
	// bgt cr6,0x823d7104
	if (cr6.gt) goto loc_823D7104;
	// lis r12,-32195
	r12.s64 = -2109931520;
	// addi r12,r12,28316
	r12.s64 = r12.s64 + 28316;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_823D700C;
	case 1:
		goto loc_823D700C;
	case 2:
		goto loc_823D700C;
	case 3:
		goto loc_823D700C;
	case 4:
		goto loc_823D700C;
	case 5:
		goto loc_823D700C;
	case 6:
		goto loc_823D700C;
	case 7:
		goto loc_823D700C;
	case 8:
		goto loc_823D700C;
	case 9:
		goto loc_823D700C;
	case 10:
		goto loc_823D700C;
	case 11:
		goto loc_823D7104;
	case 12:
		goto loc_823D7104;
	case 13:
		goto loc_823D7104;
	case 14:
		goto loc_823D7104;
	case 15:
		goto loc_823D7104;
	case 16:
		goto loc_823D7104;
	case 17:
		goto loc_823D7104;
	case 18:
		goto loc_823D7104;
	case 19:
		goto loc_823D7104;
	case 20:
		goto loc_823D7104;
	case 21:
		goto loc_823D7104;
	case 22:
		goto loc_823D7104;
	case 23:
		goto loc_823D7104;
	case 24:
		goto loc_823D7104;
	case 25:
		goto loc_823D7104;
	case 26:
		goto loc_823D7104;
	case 27:
		goto loc_823D7104;
	case 28:
		goto loc_823D7104;
	case 29:
		goto loc_823D7104;
	case 30:
		goto loc_823D7104;
	case 31:
		goto loc_823D7104;
	case 32:
		goto loc_823D7104;
	case 33:
		goto loc_823D7104;
	case 34:
		goto loc_823D7104;
	case 35:
		goto loc_823D7104;
	case 36:
		goto loc_823D7104;
	case 37:
		goto loc_823D7104;
	case 38:
		goto loc_823D7104;
	case 39:
		goto loc_823D7104;
	case 40:
		goto loc_823D7104;
	case 41:
		goto loc_823D7104;
	case 42:
		goto loc_823D7104;
	case 43:
		goto loc_823D7104;
	case 44:
		goto loc_823D7104;
	case 45:
		goto loc_823D7104;
	case 46:
		goto loc_823D7104;
	case 47:
		goto loc_823D7104;
	case 48:
		goto loc_823D700C;
	case 49:
		goto loc_823D700C;
	case 50:
		goto loc_823D700C;
	case 51:
		goto loc_823D700C;
	case 52:
		goto loc_823D7104;
	case 53:
		goto loc_823D7090;
	case 54:
		goto loc_823D700C;
	case 55:
		goto loc_823D707C;
	case 56:
		goto loc_823D7104;
	case 57:
		goto loc_823D7104;
	case 58:
		goto loc_823D7104;
	case 59:
		goto loc_823D7104;
	case 60:
		goto loc_823D7104;
	case 61:
		goto loc_823D7104;
	case 62:
		goto loc_823D7104;
	case 63:
		goto loc_823D70CC;
	case 64:
		goto loc_823D70D4;
	case 65:
		goto loc_823D70CC;
	case 66:
		goto loc_823D70DC;
	case 67:
		goto loc_823D70C4;
	case 68:
		goto loc_823D7104;
	case 69:
		goto loc_823D7104;
	case 70:
		goto loc_823D7104;
	case 71:
		goto loc_823D7104;
	case 72:
		goto loc_823D7104;
	case 73:
		goto loc_823D7104;
	case 74:
		goto loc_823D7104;
	case 75:
		goto loc_823D7104;
	case 76:
		goto loc_823D7104;
	case 77:
		goto loc_823D7104;
	case 78:
		goto loc_823D7104;
	case 79:
		goto loc_823D7104;
	case 80:
		goto loc_823D7104;
	case 81:
		goto loc_823D7104;
	case 82:
		goto loc_823D7104;
	case 83:
		goto loc_823D7104;
	case 84:
		goto loc_823D7104;
	case 85:
		goto loc_823D7104;
	case 86:
		goto loc_823D7104;
	case 87:
		goto loc_823D7104;
	case 88:
		goto loc_823D7104;
	case 89:
		goto loc_823D7104;
	case 90:
		goto loc_823D70A4;
	case 91:
		goto loc_823D70B4;
	default:
		__builtin_unreachable();
	}
	// lwz r17,28684(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28684);
	// lwz r17,28684(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28684);
	// lwz r17,28684(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28684);
	// lwz r17,28684(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28684);
	// lwz r17,28684(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28684);
	// lwz r17,28684(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28684);
	// lwz r17,28684(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28684);
	// lwz r17,28684(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28684);
	// lwz r17,28684(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28684);
	// lwz r17,28684(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28684);
	// lwz r17,28684(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28684);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28684(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28684);
	// lwz r17,28684(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28684);
	// lwz r17,28684(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28684);
	// lwz r17,28684(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28684);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28816(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28816);
	// lwz r17,28684(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28684);
	// lwz r17,28796(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28796);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28876(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28876);
	// lwz r17,28884(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28884);
	// lwz r17,28876(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28876);
	// lwz r17,28892(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28892);
	// lwz r17,28868(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28868);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28932(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28932);
	// lwz r17,28836(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28836);
	// lwz r17,28852(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 28852);
loc_823D700C:
	// lwz r30,36(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d7104
	if (cr6.eq) goto loc_823D7104;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a9090
	ctx.lr = 0x823D7020;
	sub_822A9090(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// blt cr6,0x823d704c
	if (cr6.lt) goto loc_823D704C;
	// li r11,0
	r11.s64 = 0;
loc_823D704C:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// beq cr6,0x823d7104
	if (cr6.eq) goto loc_823D7104;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a90b0
	ctx.lr = 0x823D7078;
	sub_822A90B0(ctx, base);
	// b 0x823d7104
	goto loc_823D7104;
loc_823D707C:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d7104
	if (cr6.eq) goto loc_823D7104;
	// bl 0x822a90b0
	ctx.lr = 0x823D708C;
	sub_822A90B0(ctx, base);
	// b 0x823d7104
	goto loc_823D7104;
loc_823D7090:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d7104
	if (cr6.eq) goto loc_823D7104;
	// bl 0x822a9090
	ctx.lr = 0x823D70A0;
	sub_822A9090(ctx, base);
	// b 0x823d7104
	goto loc_823D7104;
loc_823D70A4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823076f8
	ctx.lr = 0x823D70B0;
	sub_823076F8(ctx, base);
	// b 0x823d7104
	goto loc_823D7104;
loc_823D70B4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82307720
	ctx.lr = 0x823D70C0;
	sub_82307720(ctx, base);
	// b 0x823d7104
	goto loc_823D7104;
loc_823D70C4:
	// li r4,70
	ctx.r4.s64 = 70;
	// b 0x823d70e0
	goto loc_823D70E0;
loc_823D70CC:
	// li r4,45
	ctx.r4.s64 = 45;
	// b 0x823d70e0
	goto loc_823D70E0;
loc_823D70D4:
	// li r4,46
	ctx.r4.s64 = 46;
	// b 0x823d70e0
	goto loc_823D70E0;
loc_823D70DC:
	// li r4,47
	ctx.r4.s64 = 47;
loc_823D70E0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x823D70F4;
	sub_82641CB0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823D7104;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D7104:
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

__attribute__((alias("__imp__sub_823D711C"))) PPC_WEAK_FUNC(sub_823D711C);
PPC_FUNC_IMPL(__imp__sub_823D711C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D7120"))) PPC_WEAK_FUNC(sub_823D7120);
PPC_FUNC_IMPL(__imp__sub_823D7120) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r11,3208
	ctx.r6.s64 = r11.s64 + 3208;
	// addi r5,r10,3148
	ctx.r5.s64 = ctx.r10.s64 + 3148;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x823D714C;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d71c8
	if (cr6.eq) goto loc_823D71C8;
	// lwz r6,40(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// addi r8,r3,56
	ctx.r8.s64 = ctx.r3.s64 + 56;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x823d7198
	if (cr6.eq) goto loc_823D7198;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r9,80(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r7,44(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// lwz r5,36(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// lwz r4,32(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823ca2e8
	ctx.lr = 0x823D7188;
	sub_823CA2E8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_823D7198:
	// lwz r6,48(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x823d71c8
	if (cr6.eq) goto loc_823D71C8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r9,80(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r7,52(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r5,36(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// lwz r4,32(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823ca370
	ctx.lr = 0x823D71C8;
	sub_823CA370(ctx, base);
loc_823D71C8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D71D8"))) PPC_WEAK_FUNC(sub_823D71D8);
PPC_FUNC_IMPL(__imp__sub_823D71D8) {
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r11,3252
	ctx.r6.s64 = r11.s64 + 3252;
	// addi r5,r10,3148
	ctx.r5.s64 = ctx.r10.s64 + 3148;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x823D7204;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d7270
	if (cr6.eq) goto loc_823D7270;
	// lwz r6,40(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// addi r7,r3,48
	ctx.r7.s64 = ctx.r3.s64 + 48;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x823d7248
	if (cr6.eq) goto loc_823D7248;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r8,72(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r5,36(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// lwz r4,32(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r3,-27432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27432);
	// bl 0x823d5748
	ctx.lr = 0x823D7238;
	sub_823D5748(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_823D7248:
	// lwz r6,44(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x823d7270
	if (cr6.eq) goto loc_823D7270;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r8,72(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r5,36(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// lwz r4,32(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r3,-27432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27432);
	// bl 0x823d4938
	ctx.lr = 0x823D7270;
	sub_823D4938(ctx, base);
loc_823D7270:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D7280"))) PPC_WEAK_FUNC(sub_823D7280);
PPC_FUNC_IMPL(__imp__sub_823D7280) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r11,3292
	ctx.r6.s64 = r11.s64 + 3292;
	// addi r5,r10,3148
	ctx.r5.s64 = ctx.r10.s64 + 3148;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x823D72AC;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d7310
	if (cr6.eq) goto loc_823D7310;
	// lwz r4,32(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// addi r5,r3,40
	ctx.r5.s64 = ctx.r3.s64 + 40;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x823d72ec
	if (cr6.eq) goto loc_823D72EC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f3,72(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,68(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,64(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823cedb8
	ctx.lr = 0x823D72DC;
	sub_823CEDB8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_823D72EC:
	// lwz r4,36(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x823d7310
	if (cr6.eq) goto loc_823D7310;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f3,72(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,68(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,64(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823cee48
	ctx.lr = 0x823D7310;
	sub_823CEE48(ctx, base);
loc_823D7310:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D7320"))) PPC_WEAK_FUNC(sub_823D7320);
PPC_FUNC_IMPL(__imp__sub_823D7320) {
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r11,3292
	ctx.r6.s64 = r11.s64 + 3292;
	// addi r5,r10,3148
	ctx.r5.s64 = ctx.r10.s64 + 3148;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x823D734C;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d7374
	if (cr6.eq) goto loc_823D7374;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,76(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 76);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// stb r10,304(r11)
	PPC_STORE_U8(r11.u32 + 304, ctx.r10.u8);
	// lwz r11,-10008(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10008);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x823ce758
	ctx.lr = 0x823D7374;
	sub_823CE758(ctx, base);
loc_823D7374:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D7384"))) PPC_WEAK_FUNC(sub_823D7384);
PPC_FUNC_IMPL(__imp__sub_823D7384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D7388"))) PPC_WEAK_FUNC(sub_823D7388);
PPC_FUNC_IMPL(__imp__sub_823D7388) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823D7390;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823db9d8
	ctx.lr = 0x823D7398;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f28,f3
	f28.f64 = ctx.f3.f64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmpwi cr6,r30,83
	cr6.compare<int32_t>(r30.s32, 83, xer);
	// lfs f29,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f29.f64 = double(temp.f32);
	// bne cr6,0x823d73d8
	if (!cr6.eq) goto loc_823D73D8;
	// fcmpu cr6,f31,f29
	cr6.compare(f31.f64, f29.f64);
	// bne cr6,0x823d740c
	if (!cr6.eq) goto loc_823D740C;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lfs f31,-13108(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13108);
	f31.f64 = double(temp.f32);
	// b 0x823d740c
	goto loc_823D740C;
loc_823D73D8:
	// cmpwi cr6,r30,78
	cr6.compare<int32_t>(r30.s32, 78, xer);
	// bne cr6,0x823d740c
	if (!cr6.eq) goto loc_823D740C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823ce5c8
	ctx.lr = 0x823D73EC;
	sub_823CE5C8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,18612(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 18612);
	f0.f64 = double(temp.f32);
	// fsubs f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 - f0.f64));
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// blt cr6,0x823d740c
	if (cr6.lt) goto loc_823D740C;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lfs f0,-13108(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13108);
	f0.f64 = double(temp.f32);
	// fsubs f31,f31,f0
	f31.f64 = double(float(f31.f64 - f0.f64));
loc_823D740C:
	// stfs f30,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// stfs f28,44(r31)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// stw r29,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r29.u32);
	// stfs f31,4(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// fcmpu cr6,f30,f29
	cr6.compare(f30.f64, f29.f64);
	// ble cr6,0x823d7440
	if (!cr6.gt) goto loc_823D7440;
	// fadds f0,f31,f30
	f0.f64 = double(float(f31.f64 + f30.f64));
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba24
	ctx.lr = 0x823D743C;
	// b 0x823d924c
	return;
loc_823D7440:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f0,-31400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31400);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba24
	ctx.lr = 0x823D7458;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823D745C"))) PPC_WEAK_FUNC(sub_823D745C);
PPC_FUNC_IMPL(__imp__sub_823D745C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D7460"))) PPC_WEAK_FUNC(sub_823D7460);
PPC_FUNC_IMPL(__imp__sub_823D7460) {
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
	ctx.lr = 0x823D7468;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x823D7488;
	sub_82137A08(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823de4d8
	ctx.lr = 0x823D7490;
	sub_823DE4D8(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r11,-21152
	r29.s64 = r11.s64 + -21152;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_823D74A0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823d90b0
	ctx.lr = 0x823D74AC;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823d74e4
	if (!cr6.eq) goto loc_823D74E4;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r29,388
	r11.s64 = r29.s64 + 388;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x823d74a0
	if (cr6.lt) goto loc_823D74A0;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r11,-13104
	ctx.r3.s64 = r11.s64 + -13104;
	// bl 0x82130000
	ctx.lr = 0x823D74D8;
	sub_82130000(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9248
	return;
loc_823D74E4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823D74F0"))) PPC_WEAK_FUNC(sub_823D74F0);
PPC_FUNC_IMPL(__imp__sub_823D74F0) {
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r11,3108
	ctx.r6.s64 = r11.s64 + 3108;
	// addi r5,r10,3148
	ctx.r5.s64 = ctx.r10.s64 + 3148;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x823D751C;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d7584
	if (cr6.eq) goto loc_823D7584;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// beq cr6,0x823d757c
	if (cr6.eq) goto loc_823D757C;
	// cmpwi cr6,r11,58
	cr6.compare<int32_t>(r11.s32, 58, xer);
	// bne cr6,0x823d7584
	if (!cr6.eq) goto loc_823D7584;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823d7584
	if (!cr6.eq) goto loc_823D7584;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lbz r10,305(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 305);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d7584
	if (cr6.eq) goto loc_823D7584;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x823cc200
	ctx.lr = 0x823D756C;
	sub_823CC200(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_823D757C:
	// lwz r3,36(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// bl 0x822a8ea0
	ctx.lr = 0x823D7584;
	sub_822A8EA0(ctx, base);
loc_823D7584:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D7594"))) PPC_WEAK_FUNC(sub_823D7594);
PPC_FUNC_IMPL(__imp__sub_823D7594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D7598"))) PPC_WEAK_FUNC(sub_823D7598);
PPC_FUNC_IMPL(__imp__sub_823D7598) {
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
	ctx.lr = 0x823D75A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x823d75e4
	if (!cr6.gt) goto loc_823D75E4;
	// mr r31,r29
	r31.u64 = r29.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
loc_823D75B8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d75d8
	if (cr6.eq) goto loc_823D75D8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D75D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D75D8:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x823d75b8
	if (!cr0.eq) goto loc_823D75B8;
loc_823D75E4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x823D75EC;
	sub_82130588(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823D75F4"))) PPC_WEAK_FUNC(sub_823D75F4);
PPC_FUNC_IMPL(__imp__sub_823D75F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D75F8"))) PPC_WEAK_FUNC(sub_823D75F8);
PPC_FUNC_IMPL(__imp__sub_823D75F8) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x823D7600;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// lhz r11,18(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d765c
	if (cr6.eq) goto loc_823D765C;
	// mr r29,r26
	r29.u64 = r26.u64;
	// mr r30,r26
	r30.u64 = r26.u64;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// lis r27,-32249
	r27.s64 = -2113470464;
loc_823D7628:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,3040(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 3040);
	// lwzx r9,r11,r30
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// beq cr6,0x823d764c
	if (cr6.eq) goto loc_823D764C;
	// lwz r11,-27428(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -27428);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x824a63a0
	ctx.lr = 0x823D764C;
	sub_824A63A0(ctx, base);
loc_823D764C:
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r30,512
	cr6.compare<int32_t>(r30.s32, 512, xer);
	// blt cr6,0x823d7628
	if (cr6.lt) goto loc_823D7628;
loc_823D765C:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x823D7664;
	sub_82130588(ctx, base);
	// stw r26,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r26.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r26,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r26.u16);
	// sth r26,18(r31)
	PPC_STORE_U16(r31.u32 + 18, r26.u16);
	// lhz r5,6(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x823d7598
	ctx.lr = 0x823D7680;
	sub_823D7598(ctx, base);
	// stw r26,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r26.u32);
	// sth r26,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r26.u16);
	// sth r26,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r26.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823D7694"))) PPC_WEAK_FUNC(sub_823D7694);
PPC_FUNC_IMPL(__imp__sub_823D7694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D7698"))) PPC_WEAK_FUNC(sub_823D7698);
PPC_FUNC_IMPL(__imp__sub_823D7698) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,-10744
	ctx.r3.s64 = r11.s64 + -10744;
	// b 0x823d75f8
	sub_823D75F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823D76A4"))) PPC_WEAK_FUNC(sub_823D76A4);
PPC_FUNC_IMPL(__imp__sub_823D76A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D76A8"))) PPC_WEAK_FUNC(sub_823D76A8);
PPC_FUNC_IMPL(__imp__sub_823D76A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x823D76B0;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r11,3108
	ctx.r6.s64 = r11.s64 + 3108;
	// addi r5,r10,3148
	ctx.r5.s64 = ctx.r10.s64 + 3148;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x823D76D4;
	sub_823DEDD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r4,96
	cr6.compare<uint32_t>(ctx.r4.u32, 96, xer);
	// bgt cr6,0x823d905c
	if (cr6.gt) goto loc_823D905C;
	// lis r12,-32195
	r12.s64 = -2109931520;
	// addi r12,r12,30468
	r12.s64 = r12.s64 + 30468;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_823D7888;
	case 1:
		goto loc_823D78FC;
	case 2:
		goto loc_823D7970;
	case 3:
		goto loc_823D79E4;
	case 4:
		goto loc_823D7A58;
	case 5:
		goto loc_823D7ACC;
	case 6:
		goto loc_823D7B40;
	case 7:
		goto loc_823D7BB4;
	case 8:
		goto loc_823D7C28;
	case 9:
		goto loc_823D7C9C;
	case 10:
		goto loc_823D7D10;
	case 11:
		goto loc_823D7FBC;
	case 12:
		goto loc_823D7FD8;
	case 13:
		goto loc_823D7FF4;
	case 14:
		goto loc_823D800C;
	case 15:
		goto loc_823D8040;
	case 16:
		goto loc_823D8074;
	case 17:
		goto loc_823D80A8;
	case 18:
		goto loc_823D8074;
	case 19:
		goto loc_823D80A8;
	case 20:
		goto loc_823D80A8;
	case 21:
		goto loc_823D8040;
	case 22:
		goto loc_823D87DC;
	case 23:
		goto loc_823D880C;
	case 24:
		goto loc_823D8844;
	case 25:
		goto loc_823D80DC;
	case 26:
		goto loc_823D824C;
	case 27:
		goto loc_823D83BC;
	case 28:
		goto loc_823D8534;
	case 29:
		goto loc_823D86B4;
	case 30:
		goto loc_823D86E8;
	case 31:
		goto loc_823D871C;
	case 32:
		goto loc_823D8768;
	case 33:
		goto loc_823D87B4;
	case 34:
		goto loc_823D87C8;
	case 35:
		goto loc_823D8860;
	case 36:
		goto loc_823D8888;
	case 37:
		goto loc_823D88B0;
	case 38:
		goto loc_823D88F0;
	case 39:
		goto loc_823D8918;
	case 40:
		goto loc_823D8930;
	case 41:
		goto loc_823D8954;
	case 42:
		goto loc_823D89A4;
	case 43:
		goto loc_823D89C8;
	case 44:
		goto loc_823D89DC;
	case 45:
		goto loc_823D89F4;
	case 46:
		goto loc_823D8A0C;
	case 47:
		goto loc_823D89BC;
	case 48:
		goto loc_823D7D84;
	case 49:
		goto loc_823D7DF8;
	case 50:
		goto loc_823D7E6C;
	case 51:
		goto loc_823D7EE0;
	case 52:
		goto loc_823D7EF8;
	case 53:
		goto loc_823D7F10;
	case 54:
		goto loc_823D7F20;
	case 55:
		goto loc_823D7F38;
	case 56:
		goto loc_823D7F50;
	case 57:
		goto loc_823D905C;
	case 58:
		goto loc_823D8A24;
	case 59:
		goto loc_823D8AAC;
	case 60:
		goto loc_823D8A5C;
	case 61:
		goto loc_823D8A84;
	case 62:
		goto loc_823D8B9C;
	case 63:
		goto loc_823D8B10;
	case 64:
		goto loc_823D8BCC;
	case 65:
		goto loc_823D8C30;
	case 66:
		goto loc_823D8CBC;
	case 67:
		goto loc_823D8AD4;
	case 68:
		goto loc_823D8D20;
	case 69:
		goto loc_823D8D80;
	case 70:
		goto loc_823D90A4;
	case 71:
		goto loc_823D90A4;
	case 72:
		goto loc_823D8F30;
	case 73:
		goto loc_823D8F24;
	case 74:
		goto loc_823D8F34;
	case 75:
		goto loc_823D8F0C;
	case 76:
		goto loc_823D905C;
	case 77:
		goto loc_823D905C;
	case 78:
		goto loc_823D8E10;
	case 79:
		goto loc_823D8E38;
	case 80:
		goto loc_823D8E80;
	case 81:
		goto loc_823D8F00;
	case 82:
		goto loc_823D8E58;
	case 83:
		goto loc_823D8E6C;
	case 84:
		goto loc_823D90A4;
	case 85:
		goto loc_823D8EE0;
	case 86:
		goto loc_823D8EF0;
	case 87:
		goto loc_823D90A4;
	case 88:
		goto loc_823D8F80;
	case 89:
		goto loc_823D8FCC;
	case 90:
		goto loc_823D8DE0;
	case 91:
		goto loc_823D8DF0;
	case 92:
		goto loc_823D8E00;
	case 93:
		goto loc_823D9038;
	case 94:
		goto loc_823D8E44;
	case 95:
		goto loc_823D9018;
	case 96:
		goto loc_823D9028;
	default:
		__builtin_unreachable();
	}
	// lwz r17,30856(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 30856);
	// lwz r17,30972(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 30972);
	// lwz r17,31088(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 31088);
	// lwz r17,31204(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 31204);
	// lwz r17,31320(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 31320);
	// lwz r17,31436(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 31436);
	// lwz r17,31552(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 31552);
	// lwz r17,31668(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 31668);
	// lwz r17,31784(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 31784);
	// lwz r17,31900(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 31900);
	// lwz r17,32016(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 32016);
	// lwz r17,32700(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 32700);
	// lwz r17,32728(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 32728);
	// lwz r17,32756(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 32756);
	// lwz r17,-32756(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -32756);
	// lwz r17,-32704(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -32704);
	// lwz r17,-32652(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -32652);
	// lwz r17,-32600(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -32600);
	// lwz r17,-32652(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -32652);
	// lwz r17,-32600(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -32600);
	// lwz r17,-32600(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -32600);
	// lwz r17,-32704(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -32704);
	// lwz r17,-30756(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30756);
	// lwz r17,-30708(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30708);
	// lwz r17,-30652(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30652);
	// lwz r17,-32548(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -32548);
	// lwz r17,-32180(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -32180);
	// lwz r17,-31812(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -31812);
	// lwz r17,-31436(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -31436);
	// lwz r17,-31052(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -31052);
	// lwz r17,-31000(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -31000);
	// lwz r17,-30948(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30948);
	// lwz r17,-30872(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30872);
	// lwz r17,-30796(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30796);
	// lwz r17,-30776(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30776);
	// lwz r17,-30624(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30624);
	// lwz r17,-30584(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30584);
	// lwz r17,-30544(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30544);
	// lwz r17,-30480(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30480);
	// lwz r17,-30440(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30440);
	// lwz r17,-30416(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30416);
	// lwz r17,-30380(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30380);
	// lwz r17,-30300(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30300);
	// lwz r17,-30264(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30264);
	// lwz r17,-30244(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30244);
	// lwz r17,-30220(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30220);
	// lwz r17,-30196(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30196);
	// lwz r17,-30276(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30276);
	// lwz r17,32132(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 32132);
	// lwz r17,32248(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 32248);
	// lwz r17,32364(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 32364);
	// lwz r17,32480(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 32480);
	// lwz r17,32504(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 32504);
	// lwz r17,32528(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 32528);
	// lwz r17,32544(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 32544);
	// lwz r17,32568(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 32568);
	// lwz r17,32592(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + 32592);
	// lwz r17,-28580(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -28580);
	// lwz r17,-30172(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30172);
	// lwz r17,-30036(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30036);
	// lwz r17,-30116(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30116);
	// lwz r17,-30076(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -30076);
	// lwz r17,-29796(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -29796);
	// lwz r17,-29936(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -29936);
	// lwz r17,-29748(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -29748);
	// lwz r17,-29648(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -29648);
	// lwz r17,-29508(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -29508);
	// lwz r17,-29996(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -29996);
	// lwz r17,-29408(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -29408);
	// lwz r17,-29312(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -29312);
	// lwz r17,-28508(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -28508);
	// lwz r17,-28508(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -28508);
	// lwz r17,-28880(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -28880);
	// lwz r17,-28892(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -28892);
	// lwz r17,-28876(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -28876);
	// lwz r17,-28916(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -28916);
	// lwz r17,-28580(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -28580);
	// lwz r17,-28580(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -28580);
	// lwz r17,-29168(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -29168);
	// lwz r17,-29128(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -29128);
	// lwz r17,-29056(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -29056);
	// lwz r17,-28928(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -28928);
	// lwz r17,-29096(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -29096);
	// lwz r17,-29076(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -29076);
	// lwz r17,-28508(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -28508);
	// lwz r17,-28960(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -28960);
	// lwz r17,-28944(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -28944);
	// lwz r17,-28508(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -28508);
	// lwz r17,-28800(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -28800);
	// lwz r17,-28724(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -28724);
	// lwz r17,-29216(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -29216);
	// lwz r17,-29200(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -29200);
	// lwz r17,-29184(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -29184);
	// lwz r17,-28616(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -28616);
	// lwz r17,-29116(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -29116);
	// lwz r17,-28648(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -28648);
	// lwz r17,-28632(r29)
	r17.u64 = PPC_LOAD_U32(r29.u32 + -28632);
loc_823D7888:
	// lwz r30,36(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8f60
	ctx.lr = 0x823D789C;
	sub_822A8F60(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// blt cr6,0x823d78c8
	if (cr6.lt) goto loc_823D78C8;
	// li r11,0
	r11.s64 = 0;
loc_823D78C8:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a90a0
	ctx.lr = 0x823D78F4;
	sub_822A90A0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D78FC:
	// lwz r30,36(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8f70
	ctx.lr = 0x823D7910;
	sub_822A8F70(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// blt cr6,0x823d793c
	if (cr6.lt) goto loc_823D793C;
	// li r11,0
	r11.s64 = 0;
loc_823D793C:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a90a0
	ctx.lr = 0x823D7968;
	sub_822A90A0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D7970:
	// lwz r30,36(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8f80
	ctx.lr = 0x823D7984;
	sub_822A8F80(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// blt cr6,0x823d79b0
	if (cr6.lt) goto loc_823D79B0;
	// li r11,0
	r11.s64 = 0;
loc_823D79B0:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a90a0
	ctx.lr = 0x823D79DC;
	sub_822A90A0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D79E4:
	// lwz r30,36(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8f90
	ctx.lr = 0x823D79F8;
	sub_822A8F90(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// blt cr6,0x823d7a24
	if (cr6.lt) goto loc_823D7A24;
	// li r11,0
	r11.s64 = 0;
loc_823D7A24:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a90a0
	ctx.lr = 0x823D7A50;
	sub_822A90A0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D7A58:
	// lwz r30,36(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8fa0
	ctx.lr = 0x823D7A6C;
	sub_822A8FA0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// blt cr6,0x823d7a98
	if (cr6.lt) goto loc_823D7A98;
	// li r11,0
	r11.s64 = 0;
loc_823D7A98:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a90a0
	ctx.lr = 0x823D7AC4;
	sub_822A90A0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D7ACC:
	// lwz r30,36(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8fb0
	ctx.lr = 0x823D7AE0;
	sub_822A8FB0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// blt cr6,0x823d7b0c
	if (cr6.lt) goto loc_823D7B0C;
	// li r11,0
	r11.s64 = 0;
loc_823D7B0C:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a90a0
	ctx.lr = 0x823D7B38;
	sub_822A90A0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D7B40:
	// lwz r30,36(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8fc0
	ctx.lr = 0x823D7B54;
	sub_822A8FC0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// blt cr6,0x823d7b80
	if (cr6.lt) goto loc_823D7B80;
	// li r11,0
	r11.s64 = 0;
loc_823D7B80:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a90a0
	ctx.lr = 0x823D7BAC;
	sub_822A90A0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D7BB4:
	// lwz r30,36(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8fd0
	ctx.lr = 0x823D7BC8;
	sub_822A8FD0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// blt cr6,0x823d7bf4
	if (cr6.lt) goto loc_823D7BF4;
	// li r11,0
	r11.s64 = 0;
loc_823D7BF4:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a90a0
	ctx.lr = 0x823D7C20;
	sub_822A90A0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D7C28:
	// lwz r30,36(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8fe0
	ctx.lr = 0x823D7C3C;
	sub_822A8FE0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// blt cr6,0x823d7c68
	if (cr6.lt) goto loc_823D7C68;
	// li r11,0
	r11.s64 = 0;
loc_823D7C68:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a90a0
	ctx.lr = 0x823D7C94;
	sub_822A90A0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D7C9C:
	// lwz r30,36(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8ff0
	ctx.lr = 0x823D7CB0;
	sub_822A8FF0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// blt cr6,0x823d7cdc
	if (cr6.lt) goto loc_823D7CDC;
	// li r11,0
	r11.s64 = 0;
loc_823D7CDC:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a90a0
	ctx.lr = 0x823D7D08;
	sub_822A90A0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D7D10:
	// lwz r30,36(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a9000
	ctx.lr = 0x823D7D24;
	sub_822A9000(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// blt cr6,0x823d7d50
	if (cr6.lt) goto loc_823D7D50;
	// li r11,0
	r11.s64 = 0;
loc_823D7D50:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a90a0
	ctx.lr = 0x823D7D7C;
	sub_822A90A0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D7D84:
	// lwz r30,36(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a9010
	ctx.lr = 0x823D7D98;
	sub_822A9010(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// blt cr6,0x823d7dc4
	if (cr6.lt) goto loc_823D7DC4;
	// li r11,0
	r11.s64 = 0;
loc_823D7DC4:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a90a0
	ctx.lr = 0x823D7DF0;
	sub_822A90A0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D7DF8:
	// lwz r30,36(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a9020
	ctx.lr = 0x823D7E0C;
	sub_822A9020(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// blt cr6,0x823d7e38
	if (cr6.lt) goto loc_823D7E38;
	// li r11,0
	r11.s64 = 0;
loc_823D7E38:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a90a0
	ctx.lr = 0x823D7E64;
	sub_822A90A0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D7E6C:
	// lwz r30,36(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a9030
	ctx.lr = 0x823D7E80;
	sub_822A9030(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f13,8884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// fabs f10,f11
	ctx.f10.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// blt cr6,0x823d7eac
	if (cr6.lt) goto loc_823D7EAC;
	// li r11,0
	r11.s64 = 0;
loc_823D7EAC:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a90a0
	ctx.lr = 0x823D7ED8;
	sub_822A90A0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D7EE0:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// bl 0x822a9050
	ctx.lr = 0x823D7EF0;
	sub_822A9050(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D7EF8:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// bl 0x822a9060
	ctx.lr = 0x823D7F08;
	sub_822A9060(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D7F10:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x822a9070
	ctx.lr = 0x823D7F18;
	sub_822A9070(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D7F20:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// bl 0x822a9080
	ctx.lr = 0x823D7F30;
	sub_822A9080(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D7F38:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// bl 0x822a90a0
	ctx.lr = 0x823D7F48;
	sub_822A90A0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D7F50:
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,72
	r27.s64 = 72;
	// li r30,0
	r30.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// lis r29,-32121
	r29.s64 = -2105081856;
loc_823D7F64:
	// lbzx r9,r27,r28
	ctx.r9.u64 = PPC_LOAD_U8(r27.u32 + r28.u32);
	// lwz r11,17892(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 17892);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823d7f7c
	if (cr6.eq) goto loc_823D7F7C;
	// lwz r10,804(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// b 0x823d7f80
	goto loc_823D7F80;
loc_823D7F7C:
	// lwz r10,400(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 400);
loc_823D7F80:
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// bge cr6,0x823d90a4
	if (!cr6.lt) goto loc_823D90A4;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823d7fa8
	if (cr6.eq) goto loc_823D7FA8;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lwz r3,404(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 404);
	// bl 0x822a8878
	ctx.lr = 0x823D7F9C;
	sub_822A8878(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// b 0x823d7f64
	goto loc_823D7F64;
loc_823D7FA8:
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x822a8878
	ctx.lr = 0x823D7FB0;
	sub_822A8878(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// b 0x823d7f64
	goto loc_823D7F64;
loc_823D7FBC:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822aa900
	ctx.lr = 0x823D7FD0;
	sub_822AA900(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D7FD8:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822aa900
	ctx.lr = 0x823D7FEC;
	sub_822AA900(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D7FF4:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// bl 0x822a8ea0
	ctx.lr = 0x823D8004;
	sub_822A8EA0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D800C:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,84(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,2151(r11)
	PPC_STORE_U8(r11.u32 + 2151, ctx.r10.u8);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8040:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,84(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,2152(r11)
	PPC_STORE_U8(r11.u32 + 2152, ctx.r10.u8);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8074:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,84(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,2149(r11)
	PPC_STORE_U8(r11.u32 + 2149, ctx.r10.u8);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D80A8:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,84(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,2150(r11)
	PPC_STORE_U8(r11.u32 + 2150, ctx.r10.u8);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D80DC:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r31,48(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lbzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,160(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stfs f0,164(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// beq cr6,0x823d8124
	if (cr6.eq) goto loc_823D8124;
	// addi r11,r31,272
	r11.s64 = r31.s64 + 272;
	// b 0x823d812c
	goto loc_823D812C;
loc_823D8124:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_823D812C:
	// li r8,32
	ctx.r8.s64 = 32;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,48
	ctx.r9.s64 = 48;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// lvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v60,v63,v62
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// lvx128 v59,r11,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v58,v63,v62
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrghw128 v57,v59,v61
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v56,v59,v61
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// lfs f13,-12624(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -12624);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// vmrghw128 v55,v60,v57
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// vmrghw128 v54,v58,v56
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrglw128 v53,v60,v57
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmsum3fp128 v52,v63,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vmsum3fp128 v51,v63,v54
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vmsum3fp128 v50,v63,v53
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vmrghw128 v49,v52,v51
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrghw128 v48,v50,v49
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrghw128 v47,v49,v48
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// stvx128 v47,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x823d81b0
	if (cr6.eq) goto loc_823D81B0;
	// addi r11,r31,272
	r11.s64 = r31.s64 + 272;
	// b 0x823d81b8
	goto loc_823D81B8;
loc_823D81B0:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_823D81B8:
	// lvx128 v42,r11,r10
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lvx128 v46,r0,r11
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvx128 v45,r11,r8
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lvx128 v44,r11,r9
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v43,v46,v45
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v40,v42,v44
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrglw128 v41,v46,v45
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v39,v42,v44
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrghw128 v38,v43,v40
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmrglw128 v36,v43,v40
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmrghw128 v37,v41,v39
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// vmsum3fp128 v35,v63,v38
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v35.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v38.f32), 0xEF));
	// vmsum3fp128 v33,v63,v36
	simde_mm_store_ps(v33.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v36.f32), 0xEF));
	// vmsum3fp128 v34,v63,v37
	simde_mm_store_ps(v34.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v37.f32), 0xEF));
	// vmrghw128 v32,v35,v34
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vmrghw128 v63,v33,v32
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v33.u32)));
	// vmrghw128 v62,v32,v63
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,128(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 128);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 164);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D8228;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,128(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 128);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,172(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 172);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x823D8244;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D824C:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r31,48(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lbzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,192(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stfs f0,196(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f0,200(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// beq cr6,0x823d8294
	if (cr6.eq) goto loc_823D8294;
	// addi r11,r31,272
	r11.s64 = r31.s64 + 272;
	// b 0x823d829c
	goto loc_823D829C;
loc_823D8294:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_823D829C:
	// li r8,32
	ctx.r8.s64 = 32;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,48
	ctx.r9.s64 = 48;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// lvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lvx128 v59,r11,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v58,v61,v60
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// lvx128 v57,r11,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v56,v61,v60
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v55,v57,v59
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v54,v57,v59
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// lfs f13,-12628(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -12628);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// vmrghw128 v53,v58,v55
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// vmrghw128 v52,v56,v54
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrglw128 v51,v58,v55
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmsum3fp128 v50,v63,v53
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vmsum3fp128 v49,v63,v52
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v52.f32), 0xEF));
	// vmsum3fp128 v48,v63,v51
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v51.f32), 0xEF));
	// vmrghw128 v47,v50,v49
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrghw128 v46,v48,v47
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v45,v47,v46
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// stvx128 v45,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x823d8320
	if (cr6.eq) goto loc_823D8320;
	// addi r11,r31,272
	r11.s64 = r31.s64 + 272;
	// b 0x823d8328
	goto loc_823D8328;
loc_823D8320:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_823D8328:
	// lvx128 v40,r11,r10
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v44,r0,r11
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lvx128 v43,r11,r8
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lvx128 v42,r11,r9
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v41,v44,v43
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrghw128 v38,v40,v42
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmrglw128 v39,v44,v43
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v37,v40,v42
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmrghw128 v36,v41,v38
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// vmrglw128 v34,v41,v38
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// vmrghw128 v35,v39,v37
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// vmsum3fp128 v33,v63,v36
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v33.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v36.f32), 0xEF));
	// vmsum3fp128 v32,v63,v35
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v35.f32), 0xEF));
	// vmsum3fp128 v63,v63,v34
	simde_mm_store_ps(v63.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v34.f32), 0xEF));
	// vmrghw128 v62,v33,v32
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v33.u32)));
	// vmrghw128 v61,v63,v62
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrghw128 v60,v62,v61
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,128(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 128);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 164);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D8398;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,128(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 128);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,172(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 172);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x823D83B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D83BC:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r31,48(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lbzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,-29232(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -29232);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// beq cr6,0x823d840c
	if (cr6.eq) goto loc_823D840C;
	// addi r11,r31,272
	r11.s64 = r31.s64 + 272;
	// b 0x823d8414
	goto loc_823D8414;
loc_823D840C:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_823D8414:
	// li r8,32
	ctx.r8.s64 = 32;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,48
	ctx.r9.s64 = 48;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// lvx128 v58,r11,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lvx128 v57,r11,r9
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v56,v59,v58
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// lvx128 v55,r11,r10
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v54,v59,v58
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrghw128 v53,v55,v57
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v52,v55,v57
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// lfs f13,-12632(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -12632);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,144(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stfs f0,148(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// vmrghw128 v51,v56,v53
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// vmrghw128 v50,v54,v52
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrglw128 v49,v56,v53
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmsum3fp128 v48,v63,v51
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v51.f32), 0xEF));
	// vmsum3fp128 v47,v63,v50
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v50.f32), 0xEF));
	// vmsum3fp128 v46,v63,v49
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v49.f32), 0xEF));
	// vmrghw128 v45,v48,v47
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v44,v46,v45
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v43,v45,v44
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// stvx128 v43,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x823d8498
	if (cr6.eq) goto loc_823D8498;
	// addi r11,r31,272
	r11.s64 = r31.s64 + 272;
	// b 0x823d84a0
	goto loc_823D84A0;
loc_823D8498:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_823D84A0:
	// lvx128 v38,r11,r10
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lvx128 v42,r0,r11
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lvx128 v41,r11,r8
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lvx128 v40,r11,r9
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v39,v42,v41
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrghw128 v36,v38,v40
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrglw128 v37,v42,v41
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v35,v38,v40
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrghw128 v34,v39,v36
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// vmrglw128 v32,v39,v36
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// vmrghw128 v33,v37,v35
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vmsum3fp128 v62,v63,v34
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v34.f32), 0xEF));
	// vmsum3fp128 v60,v63,v32
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v32.f32), 0xEF));
	// vmsum3fp128 v61,v63,v33
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v33.f32), 0xEF));
	// vmrghw128 v59,v62,v61
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrghw128 v58,v60,v59
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmrghw128 v57,v59,v58
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// stvx128 v57,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,128(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 128);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 164);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D8510;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r3,128(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 128);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,172(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 172);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x823D852C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8534:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r31,48(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// lbzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lfs f0,-12636(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -12636);
	f0.f64 = double(temp.f32);
	// lfs f13,-29232(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -29232);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f12,-12640(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -12640);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,176(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f12,184(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// beq cr6,0x823d858c
	if (cr6.eq) goto loc_823D858C;
	// addi r11,r31,272
	r11.s64 = r31.s64 + 272;
	// b 0x823d8594
	goto loc_823D8594;
loc_823D858C:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_823D8594:
	// li r8,32
	ctx.r8.s64 = 32;
	// lvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,48
	ctx.r9.s64 = 48;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lvx128 v55,r11,r8
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// lvx128 v54,r11,r9
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v53,v56,v55
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// lvx128 v52,r11,r10
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v51,v56,v55
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v50,v52,v54
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v49,v52,v54
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// lfs f0,3796(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,208(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stfs f0,212(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// vmrghw128 v48,v53,v50
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// stfs f0,216(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// vmrghw128 v47,v51,v49
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrglw128 v46,v53,v50
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmsum3fp128 v45,v63,v48
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v48.f32), 0xEF));
	// vmsum3fp128 v44,v63,v47
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v47.f32), 0xEF));
	// vmsum3fp128 v43,v63,v46
	simde_mm_store_ps(v43.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v46.f32), 0xEF));
	// vmrghw128 v42,v45,v44
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v41,v43,v42
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmrghw128 v40,v42,v41
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// stvx128 v40,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x823d8618
	if (cr6.eq) goto loc_823D8618;
	// addi r11,r31,272
	r11.s64 = r31.s64 + 272;
	// b 0x823d8620
	goto loc_823D8620;
loc_823D8618:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_823D8620:
	// lvx128 v35,r11,r10
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// lvx128 v39,r0,r11
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// lvx128 v38,r11,r8
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// lvx128 v37,r11,r9
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v36,v39,v38
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// vmrghw128 v33,v35,v37
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vmrglw128 v34,v39,v38
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v32,v35,v37
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vmrghw128 v62,v36,v33
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v36.u32)));
	// vmrglw128 v60,v36,v33
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v36.u32)));
	// vmrghw128 v61,v34,v32
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// vmsum3fp128 v59,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// vmsum3fp128 v57,v63,v60
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmsum3fp128 v58,v63,v61
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// vmrghw128 v56,v59,v58
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrghw128 v55,v57,v56
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v54,v56,v55
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// stvx128 v54,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,128(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 128);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 164);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D8690;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// lwz r3,128(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 128);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,172(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 172);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x823D86AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D86B4:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,84(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,2154(r11)
	PPC_STORE_U8(r11.u32 + 2154, ctx.r10.u8);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D86E8:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,84(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,2156(r11)
	PPC_STORE_U8(r11.u32 + 2156, ctx.r10.u8);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D871C:
	// lwz r31,36(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r3,84(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// bl 0x8233b608
	ctx.lr = 0x823D8744;
	sub_8233B608(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d90a4
	if (!cr6.eq) goto loc_823D90A4;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stb r10,2153(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2153, ctx.r10.u8);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8768:
	// lwz r31,36(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r3,84(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// bl 0x8233b608
	ctx.lr = 0x823D8790;
	sub_8233B608(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d90a4
	if (!cr6.eq) goto loc_823D90A4;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// stb r10,2155(r9)
	PPC_STORE_U8(ctx.r9.u32 + 2155, ctx.r10.u8);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D87B4:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x822a85d8
	ctx.lr = 0x823D87C0;
	sub_822A85D8(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D87C8:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x822a85d8
	ctx.lr = 0x823D87D4;
	sub_822A85D8(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D87DC:
	// lwz r31,36(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// bl 0x823318d0
	ctx.lr = 0x823D87F8;
	sub_823318D0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a85d8
	ctx.lr = 0x823D8804;
	sub_822A85D8(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D880C:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// sth r10,46(r9)
	PPC_STORE_U16(ctx.r9.u32 + 46, ctx.r10.u16);
	// bl 0x822a85d8
	ctx.lr = 0x823D883C;
	sub_822A85D8(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8844:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822aacf0
	ctx.lr = 0x823D8858;
	sub_822AACF0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8860:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a8828
	ctx.lr = 0x823D8880;
	sub_822A8828(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8888:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822a8828
	ctx.lr = 0x823D88A8;
	sub_822A8828(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D88B0:
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D88E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D88F0:
	// lwz r31,36(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12216(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// bl 0x821f0208
	ctx.lr = 0x823D8908;
	sub_821F0208(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8ec0
	ctx.lr = 0x823D8910;
	sub_822A8EC0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8918:
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// bl 0x822a8ee8
	ctx.lr = 0x823D8928;
	sub_822A8EE8(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8930:
	// bl 0x823bbff0
	ctx.lr = 0x823D8934;
	sub_823BBFF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10000(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// bl 0x823bd310
	ctx.lr = 0x823D894C;
	sub_823BD310(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8954:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r10,2260(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2260);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d8988
	if (cr6.eq) goto loc_823D8988;
	// lwz r11,2256(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d8988
	if (cr6.eq) goto loc_823D8988;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r10,420(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 420);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823d898c
	if (cr6.eq) goto loc_823D898C;
loc_823D8988:
	// li r11,0
	r11.s64 = 0;
loc_823D898C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d90a4
	if (cr6.eq) goto loc_823D90A4;
	// bl 0x821f2a60
	ctx.lr = 0x823D899C;
	sub_821F2A60(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D89A4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-12216(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// bl 0x821f0108
	ctx.lr = 0x823D89B4;
	sub_821F0108(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D89BC:
	// bl 0x821e60c0
	ctx.lr = 0x823D89C0;
	sub_821E60C0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D89C8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12216(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// bl 0x821ef7a8
	ctx.lr = 0x823D89D4;
	sub_821EF7A8(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D89DC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,-12216(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// bl 0x821ef878
	ctx.lr = 0x823D89EC;
	sub_821EF878(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D89F4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12216(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// bl 0x821f0270
	ctx.lr = 0x823D8A04;
	sub_821F0270(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8A0C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12216(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// bl 0x821f0400
	ctx.lr = 0x823D8A1C;
	sub_821F0400(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8A24:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// li r8,1500
	ctx.r8.s64 = 1500;
	// addi r3,r9,-12676
	ctx.r3.s64 = ctx.r9.s64 + -12676;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r10,318(r11)
	PPC_STORE_U8(r11.u32 + 318, ctx.r10.u8);
	// bl 0x82727908
	ctx.lr = 0x823D8A54;
	sub_82727908(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8A5C:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r8,1500
	ctx.r8.s64 = 1500;
	// addi r3,r11,-12712
	ctx.r3.s64 = r11.s64 + -12712;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82727908
	ctx.lr = 0x823D8A7C;
	sub_82727908(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8A84:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r8,1500
	ctx.r8.s64 = 1500;
	// addi r3,r11,-12748
	ctx.r3.s64 = r11.s64 + -12748;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82727908
	ctx.lr = 0x823D8AA4;
	sub_82727908(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8AAC:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r8,1500
	ctx.r8.s64 = 1500;
	// addi r3,r11,-12784
	ctx.r3.s64 = r11.s64 + -12784;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82727908
	ctx.lr = 0x823D8ACC;
	sub_82727908(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8AD4:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,1
	r11.s64 = 65536;
	// li r4,70
	ctx.r4.s64 = 70;
	// ori r31,r11,16256
	r31.u64 = r11.u64 | 16256;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x823D8AF0;
	sub_82641CB0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// lwz r9,704(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 704);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823D8B08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8B10:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226c270
	ctx.lr = 0x823D8B1C;
	sub_8226C270(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823d90a4
	if (!cr6.eq) goto loc_823D90A4;
	// bl 0x82387a18
	ctx.lr = 0x823D8B2C;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d90a4
	if (!cr6.eq) goto loc_823D90A4;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,1
	r11.s64 = 65536;
	// li r4,45
	ctx.r4.s64 = 45;
	// ori r31,r11,16256
	r31.u64 = r11.u64 | 16256;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x823D8B54;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r10,-12796
	ctx.r4.s64 = ctx.r10.s64 + -12796;
	// lwz r8,340(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 340);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823D8B6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// li r4,45
	ctx.r4.s64 = 45;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x823D8B7C;
	sub_82641CB0(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// lwz r6,704(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 704);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x823D8B94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8B9C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,45
	ctx.r4.s64 = 45;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x823D8BB4;
	sub_82641CB0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823D8BC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8BCC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226c270
	ctx.lr = 0x823D8BD8;
	sub_8226C270(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823d90a4
	if (!cr6.eq) goto loc_823D90A4;
	// bl 0x82387a18
	ctx.lr = 0x823D8BE8;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d90a4
	if (!cr6.eq) goto loc_823D90A4;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,1
	r11.s64 = 65536;
	// li r4,46
	ctx.r4.s64 = 46;
	// ori r31,r11,16256
	r31.u64 = r11.u64 | 16256;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x823D8C10;
	sub_82641CB0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// lwz r9,704(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 704);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823D8C28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8C30:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226c270
	ctx.lr = 0x823D8C3C;
	sub_8226C270(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823d90a4
	if (!cr6.eq) goto loc_823D90A4;
	// bl 0x82387a18
	ctx.lr = 0x823D8C4C;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d90a4
	if (!cr6.eq) goto loc_823D90A4;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,1
	r11.s64 = 65536;
	// li r4,45
	ctx.r4.s64 = 45;
	// ori r31,r11,16256
	r31.u64 = r11.u64 | 16256;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x823D8C74;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r4,r10,-12808
	ctx.r4.s64 = ctx.r10.s64 + -12808;
	// lwz r8,340(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 340);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823D8C8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// li r4,45
	ctx.r4.s64 = 45;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x823D8C9C;
	sub_82641CB0(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// lwz r6,704(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 704);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x823D8CB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8CBC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226c270
	ctx.lr = 0x823D8CC8;
	sub_8226C270(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823d90a4
	if (!cr6.eq) goto loc_823D90A4;
	// bl 0x82387a18
	ctx.lr = 0x823D8CD8;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d90a4
	if (!cr6.eq) goto loc_823D90A4;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,1
	r11.s64 = 65536;
	// li r4,47
	ctx.r4.s64 = 47;
	// ori r31,r11,16256
	r31.u64 = r11.u64 | 16256;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x823D8D00;
	sub_82641CB0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// lwz r9,704(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 704);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823D8D18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8D20:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lfs f0,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r31,r11,-10780
	r31.s64 = r11.s64 + -10780;
	// lfs f13,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x823d8d4c
	if (cr6.gt) goto loc_823D8D4C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
loc_823D8D4C:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-12836
	ctx.r3.s64 = r11.s64 + -12836;
	// bl 0x82130000
	ctx.lr = 0x823D8D58;
	sub_82130000(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r3,r10,-12872
	ctx.r3.s64 = ctx.r10.s64 + -12872;
	// li r8,1500
	ctx.r8.s64 = 1500;
	// li r7,24
	ctx.r7.s64 = 24;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82727908
	ctx.lr = 0x823D8D78;
	sub_82727908(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8D80:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lfs f0,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r31,r11,-10780
	r31.s64 = r11.s64 + -10780;
	// lfs f13,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x823d8dac
	if (cr6.gt) goto loc_823D8DAC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
loc_823D8DAC:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-12900
	ctx.r3.s64 = r11.s64 + -12900;
	// bl 0x82130000
	ctx.lr = 0x823D8DB8;
	sub_82130000(ctx, base);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r3,r10,-12936
	ctx.r3.s64 = ctx.r10.s64 + -12936;
	// li r8,1500
	ctx.r8.s64 = 1500;
	// li r7,24
	ctx.r7.s64 = 24;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82727908
	ctx.lr = 0x823D8DD8;
	sub_82727908(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8DE0:
	// lfs f1,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823076f8
	ctx.lr = 0x823D8DE8;
	sub_823076F8(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8DF0:
	// lfs f1,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82307720
	ctx.lr = 0x823D8DF8;
	sub_82307720(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8E00:
	// lfs f1,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823077b0
	ctx.lr = 0x823D8E08;
	sub_823077B0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8E10:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823d90a4
	if (!cr6.eq) goto loc_823D90A4;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823cc200
	ctx.lr = 0x823D8E30;
	sub_823CC200(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8E38:
	// bl 0x82203728
	ctx.lr = 0x823D8E3C;
	sub_82203728(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8E44:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-6136
	ctx.r3.s64 = r11.s64 + -6136;
	// bl 0x821fa358
	ctx.lr = 0x823D8E50;
	sub_821FA358(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8E58:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82206f18
	ctx.lr = 0x823D8E64;
	sub_82206F18(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8E6C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82203e10
	ctx.lr = 0x823D8E78;
	sub_82203E10(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8E80:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-25440
	ctx.r4.s64 = ctx.r10.s64 + -25440;
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x8220eea8
	ctx.lr = 0x823D8E94;
	sub_8220EEA8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d8ed4
	if (cr6.eq) goto loc_823D8ED4;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r11,r3,92
	r11.s64 = ctx.r3.s64 + 92;
	// addi r10,r10,-12940
	ctx.r10.s64 = ctx.r10.s64 + -12940;
loc_823D8EA8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x823d8ecc
	if (cr6.eq) goto loc_823D8ECC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823d8ea8
	if (cr6.eq) goto loc_823D8EA8;
loc_823D8ECC:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823d8f00
	if (cr6.eq) goto loc_823D8F00;
loc_823D8ED4:
	// bl 0x8269fcc8
	ctx.lr = 0x823D8ED8;
	sub_8269FCC8(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8EE0:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82304648
	ctx.lr = 0x823D8EE8;
	sub_82304648(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8EF0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82304648
	ctx.lr = 0x823D8EF8;
	sub_82304648(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8F00:
	// bl 0x826a62d0
	ctx.lr = 0x823D8F04;
	sub_826A62D0(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8F0C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// stb r10,228(r11)
	PPC_STORE_U8(r11.u32 + 228, ctx.r10.u8);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8F24:
	// bl 0x823bfd88
	ctx.lr = 0x823D8F28;
	sub_823BFD88(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8F30:
	// bl 0x823bfd88
	ctx.lr = 0x823D8F34;
	sub_823BFD88(ctx, base);
loc_823D8F34:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823d90a4
	if (!cr6.eq) goto loc_823D90A4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lbz r10,319(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 319);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d8f70
	if (cr6.eq) goto loc_823D8F70;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x823cc200
	ctx.lr = 0x823D8F68;
	sub_823CC200(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8F70:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x823cc200
	ctx.lr = 0x823D8F78;
	sub_823CC200(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8F80:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r4,r10,-12952
	ctx.r4.s64 = ctx.r10.s64 + -12952;
	// addi r3,r9,-20092
	ctx.r3.s64 = ctx.r9.s64 + -20092;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r31,48(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x821fa3d0
	ctx.lr = 0x823D8FA0;
	sub_821FA3D0(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// li r4,109
	ctx.r4.s64 = 109;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x823D8FB0;
	sub_82641CB0(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r8,5684(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5684, ctx.r8.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82207190
	ctx.lr = 0x823D8FC4;
	sub_82207190(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D8FCC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r4,r10,-12964
	ctx.r4.s64 = ctx.r10.s64 + -12964;
	// addi r3,r9,-20092
	ctx.r3.s64 = ctx.r9.s64 + -20092;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r31,48(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x821fa3d0
	ctx.lr = 0x823D8FEC;
	sub_821FA3D0(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// li r4,109
	ctx.r4.s64 = 109;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x823D8FFC;
	sub_82641CB0(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r8,5684(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5684, ctx.r8.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82207190
	ctx.lr = 0x823D9010;
	sub_82207190(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D9018:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82304680
	ctx.lr = 0x823D9020;
	sub_82304680(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D9028:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82304680
	ctx.lr = 0x823D9030;
	sub_82304680(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D9038:
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82204a48
	ctx.lr = 0x823D9040;
	sub_82204A48(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,-1
	ctx.r3.s64 = -1;
	// bl 0x82204a48
	ctx.lr = 0x823D904C;
	sub_82204A48(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82204a60
	ctx.lr = 0x823D9054;
	sub_82204A60(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D905C:
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x823d9090
	if (cr6.lt) goto loc_823D9090;
	// cmpwi cr6,r4,97
	cr6.compare<int32_t>(ctx.r4.s32, 97, xer);
	// bge cr6,0x823d9090
	if (!cr6.lt) goto loc_823D9090;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-21152
	ctx.r9.s64 = r11.s64 + -21152;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-13004
	ctx.r3.s64 = r11.s64 + -13004;
	// lwzx r5,r10,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x82130000
	ctx.lr = 0x823D9088;
	sub_82130000(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_823D9090:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r5,r11,-13016
	ctx.r5.s64 = r11.s64 + -13016;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-13004
	ctx.r3.s64 = r11.s64 + -13004;
	// bl 0x82130000
	ctx.lr = 0x823D90A4;
	sub_82130000(ctx, base);
loc_823D90A4:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823D90AC"))) PPC_WEAK_FUNC(sub_823D90AC);
PPC_FUNC_IMPL(__imp__sub_823D90AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D90B0"))) PPC_WEAK_FUNC(sub_823D90B0);
PPC_FUNC_IMPL(__imp__sub_823D90B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// extsb. r10,r11
	ctx.r10.s64 = r11.s8;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823d9124
	if (cr0.eq) goto loc_823D9124;
	// subf r9,r4,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r4.s64;
loc_823D90CC:
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823d9104
	if (cr6.eq) goto loc_823D9104;
loc_823D90D8:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// extsb. r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x823d9104
	if (cr0.eq) goto loc_823D9104;
	// lbzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// subf. r10,r10,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r10.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823d9104
	if (!cr0.eq) goto loc_823D9104;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823d90d8
	if (!cr6.eq) goto loc_823D90D8;
loc_823D9104:
	// lbz r11,0(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// extsb. r10,r11
	ctx.r10.s64 = r11.s8;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x823d90cc
	if (!cr0.eq) goto loc_823D90CC;
loc_823D9124:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D912C"))) PPC_WEAK_FUNC(sub_823D912C);
PPC_FUNC_IMPL(__imp__sub_823D912C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D9130"))) PPC_WEAK_FUNC(sub_823D9130);
PPC_FUNC_IMPL(__imp__sub_823D9130) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r11,r11,-12608
	r11.s64 = r11.s64 + -12608;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bl 0x823df358
	ctx.lr = 0x823D915C;
	sub_823DF358(ctx, base);
	// clrlwi. r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823d916c
	if (cr0.eq) goto loc_823D916C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x823D916C;
	sub_82130588(ctx, base);
loc_823D916C:
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

__attribute__((alias("__imp__sub_823D9188"))) PPC_WEAK_FUNC(sub_823D9188);
PPC_FUNC_IMPL(__imp__sub_823D9188) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// addi r10,r3,9
	ctx.r10.s64 = ctx.r3.s64 + 9;
	// addi r11,r4,9
	r11.s64 = ctx.r4.s64 + 9;
loc_823D9190:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi r9,0
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq 0x823d91b4
	if (cr0.eq) goto loc_823D91B4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823d9190
	if (cr6.eq) goto loc_823D9190;
loc_823D91B4:
	// cntlzw r11,r9
	r11.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp____savegprlr_14"))) PPC_WEAK_FUNC(__savegprlr_14);
PPC_FUNC_IMPL(__imp____savegprlr_14) {
	PPC_FUNC_PROLOGUE();
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
	// std r14,-152(r1)
	PPC_STORE_U64(ctx.r1.u32 + -152, r14.u64);
	// std r15,-144(r1)
	PPC_STORE_U64(ctx.r1.u32 + -144, r15.u64);
	// std r16,-136(r1)
	PPC_STORE_U64(ctx.r1.u32 + -136, r16.u64);
	// std r17,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, r17.u64);
	// std r18,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, r18.u64);
	// std r19,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, r19.u64);
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____savegprlr_15"))) PPC_WEAK_FUNC(__savegprlr_15);
PPC_FUNC_IMPL(__imp____savegprlr_15) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
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
	// std r15,-144(r1)
	PPC_STORE_U64(ctx.r1.u32 + -144, r15.u64);
	// std r16,-136(r1)
	PPC_STORE_U64(ctx.r1.u32 + -136, r16.u64);
	// std r17,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, r17.u64);
	// std r18,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, r18.u64);
	// std r19,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, r19.u64);
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____savegprlr_16"))) PPC_WEAK_FUNC(__savegprlr_16);
PPC_FUNC_IMPL(__imp____savegprlr_16) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
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
	// std r16,-136(r1)
	PPC_STORE_U64(ctx.r1.u32 + -136, r16.u64);
	// std r17,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, r17.u64);
	// std r18,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, r18.u64);
	// std r19,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, r19.u64);
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____savegprlr_17"))) PPC_WEAK_FUNC(__savegprlr_17);
PPC_FUNC_IMPL(__imp____savegprlr_17) {
	PPC_FUNC_PROLOGUE();
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
	// std r17,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, r17.u64);
	// std r18,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, r18.u64);
	// std r19,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, r19.u64);
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____savegprlr_18"))) PPC_WEAK_FUNC(__savegprlr_18);
PPC_FUNC_IMPL(__imp____savegprlr_18) {
	PPC_FUNC_PROLOGUE();
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
	// std r18,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, r18.u64);
	// std r19,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, r19.u64);
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____savegprlr_19"))) PPC_WEAK_FUNC(__savegprlr_19);
PPC_FUNC_IMPL(__imp____savegprlr_19) {
	PPC_FUNC_PROLOGUE();
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
	// std r19,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, r19.u64);
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____savegprlr_20"))) PPC_WEAK_FUNC(__savegprlr_20);
PPC_FUNC_IMPL(__imp____savegprlr_20) {
	PPC_FUNC_PROLOGUE();
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
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____savegprlr_21"))) PPC_WEAK_FUNC(__savegprlr_21);
PPC_FUNC_IMPL(__imp____savegprlr_21) {
	PPC_FUNC_PROLOGUE();
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
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____savegprlr_22"))) PPC_WEAK_FUNC(__savegprlr_22);
PPC_FUNC_IMPL(__imp____savegprlr_22) {
	PPC_FUNC_PROLOGUE();
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
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____savegprlr_23"))) PPC_WEAK_FUNC(__savegprlr_23);
PPC_FUNC_IMPL(__imp____savegprlr_23) {
	PPC_FUNC_PROLOGUE();
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
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____savegprlr_24"))) PPC_WEAK_FUNC(__savegprlr_24);
PPC_FUNC_IMPL(__imp____savegprlr_24) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____savegprlr_25"))) PPC_WEAK_FUNC(__savegprlr_25);
PPC_FUNC_IMPL(__imp____savegprlr_25) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____savegprlr_26"))) PPC_WEAK_FUNC(__savegprlr_26);
PPC_FUNC_IMPL(__imp____savegprlr_26) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____savegprlr_27"))) PPC_WEAK_FUNC(__savegprlr_27);
PPC_FUNC_IMPL(__imp____savegprlr_27) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____savegprlr_28"))) PPC_WEAK_FUNC(__savegprlr_28);
PPC_FUNC_IMPL(__imp____savegprlr_28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____savegprlr_29"))) PPC_WEAK_FUNC(__savegprlr_29);
PPC_FUNC_IMPL(__imp____savegprlr_29) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____savegprlr_30"))) PPC_WEAK_FUNC(__savegprlr_30);
PPC_FUNC_IMPL(__imp____savegprlr_30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____savegprlr_31"))) PPC_WEAK_FUNC(__savegprlr_31);
PPC_FUNC_IMPL(__imp____savegprlr_31) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r31{};
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_14"))) PPC_WEAK_FUNC(__restgprlr_14);
PPC_FUNC_IMPL(__imp____restgprlr_14) {
	PPC_FUNC_PROLOGUE();
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
	// ld r14,-152(r1)
	r14.u64 = PPC_LOAD_U64(ctx.r1.u32 + -152);
	// ld r15,-144(r1)
	r15.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// ld r16,-136(r1)
	r16.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// ld r17,-128(r1)
	r17.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// ld r18,-120(r1)
	r18.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// ld r19,-112(r1)
	r19.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// ld r20,-104(r1)
	r20.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// ld r21,-96(r1)
	r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// ld r22,-88(r1)
	r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// ld r23,-80(r1)
	r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_15"))) PPC_WEAK_FUNC(__restgprlr_15);
PPC_FUNC_IMPL(__imp____restgprlr_15) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
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
	// ld r15,-144(r1)
	r15.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// ld r16,-136(r1)
	r16.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// ld r17,-128(r1)
	r17.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// ld r18,-120(r1)
	r18.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// ld r19,-112(r1)
	r19.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// ld r20,-104(r1)
	r20.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// ld r21,-96(r1)
	r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// ld r22,-88(r1)
	r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// ld r23,-80(r1)
	r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_16"))) PPC_WEAK_FUNC(__restgprlr_16);
PPC_FUNC_IMPL(__imp____restgprlr_16) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
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
	// ld r16,-136(r1)
	r16.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// ld r17,-128(r1)
	r17.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// ld r18,-120(r1)
	r18.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// ld r19,-112(r1)
	r19.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// ld r20,-104(r1)
	r20.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// ld r21,-96(r1)
	r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// ld r22,-88(r1)
	r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// ld r23,-80(r1)
	r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_17"))) PPC_WEAK_FUNC(__restgprlr_17);
PPC_FUNC_IMPL(__imp____restgprlr_17) {
	PPC_FUNC_PROLOGUE();
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
	// ld r17,-128(r1)
	r17.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// ld r18,-120(r1)
	r18.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// ld r19,-112(r1)
	r19.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// ld r20,-104(r1)
	r20.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// ld r21,-96(r1)
	r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// ld r22,-88(r1)
	r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// ld r23,-80(r1)
	r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_18"))) PPC_WEAK_FUNC(__restgprlr_18);
PPC_FUNC_IMPL(__imp____restgprlr_18) {
	PPC_FUNC_PROLOGUE();
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
	// ld r18,-120(r1)
	r18.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// ld r19,-112(r1)
	r19.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// ld r20,-104(r1)
	r20.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// ld r21,-96(r1)
	r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// ld r22,-88(r1)
	r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// ld r23,-80(r1)
	r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_19"))) PPC_WEAK_FUNC(__restgprlr_19);
PPC_FUNC_IMPL(__imp____restgprlr_19) {
	PPC_FUNC_PROLOGUE();
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
	// ld r19,-112(r1)
	r19.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// ld r20,-104(r1)
	r20.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// ld r21,-96(r1)
	r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// ld r22,-88(r1)
	r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// ld r23,-80(r1)
	r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_20"))) PPC_WEAK_FUNC(__restgprlr_20);
PPC_FUNC_IMPL(__imp____restgprlr_20) {
	PPC_FUNC_PROLOGUE();
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
	// ld r20,-104(r1)
	r20.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// ld r21,-96(r1)
	r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// ld r22,-88(r1)
	r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// ld r23,-80(r1)
	r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_21"))) PPC_WEAK_FUNC(__restgprlr_21);
PPC_FUNC_IMPL(__imp____restgprlr_21) {
	PPC_FUNC_PROLOGUE();
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
	// ld r21,-96(r1)
	r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// ld r22,-88(r1)
	r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// ld r23,-80(r1)
	r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_22"))) PPC_WEAK_FUNC(__restgprlr_22);
PPC_FUNC_IMPL(__imp____restgprlr_22) {
	PPC_FUNC_PROLOGUE();
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
	// ld r22,-88(r1)
	r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// ld r23,-80(r1)
	r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_23"))) PPC_WEAK_FUNC(__restgprlr_23);
PPC_FUNC_IMPL(__imp____restgprlr_23) {
	PPC_FUNC_PROLOGUE();
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
	// ld r23,-80(r1)
	r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_24"))) PPC_WEAK_FUNC(__restgprlr_24);
PPC_FUNC_IMPL(__imp____restgprlr_24) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r24{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// ld r24,-72(r1)
	r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_25"))) PPC_WEAK_FUNC(__restgprlr_25);
PPC_FUNC_IMPL(__imp____restgprlr_25) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r25{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// ld r25,-64(r1)
	r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_26"))) PPC_WEAK_FUNC(__restgprlr_26);
PPC_FUNC_IMPL(__imp____restgprlr_26) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// ld r26,-56(r1)
	r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_27"))) PPC_WEAK_FUNC(__restgprlr_27);
PPC_FUNC_IMPL(__imp____restgprlr_27) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// ld r27,-48(r1)
	r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_28"))) PPC_WEAK_FUNC(__restgprlr_28);
PPC_FUNC_IMPL(__imp____restgprlr_28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// ld r28,-40(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_29"))) PPC_WEAK_FUNC(__restgprlr_29);
PPC_FUNC_IMPL(__imp____restgprlr_29) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// ld r29,-32(r1)
	r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_30"))) PPC_WEAK_FUNC(__restgprlr_30);
PPC_FUNC_IMPL(__imp____restgprlr_30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_31"))) PPC_WEAK_FUNC(__restgprlr_31);
PPC_FUNC_IMPL(__imp____restgprlr_31) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r31{};
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D9264"))) PPC_WEAK_FUNC(sub_823D9264);
PPC_FUNC_IMPL(__imp__sub_823D9264) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r12{};
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// mr r12,r5
	r12.u64 = ctx.r5.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_823D9270"))) PPC_WEAK_FUNC(sub_823D9270);
PPC_FUNC_IMPL(__imp__sub_823D9270) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// lis r11,-32194
	r11.s64 = -2109865984;
	// addi r30,r8,-19820
	r30.s64 = ctx.r8.s64 + -19820;
	// addi r11,r11,576
	r11.s64 = r11.s64 + 576;
	// lis r10,-32194
	ctx.r10.s64 = -2109865984;
	// lis r9,-32194
	ctx.r9.s64 = -2109865984;
	// stw r11,-19820(r8)
	PPC_STORE_U32(ctx.r8.u32 + -19820, r11.u32);
	// lis r31,-32194
	r31.s64 = -2109865984;
	// addi r10,r10,-2544
	ctx.r10.s64 = ctx.r10.s64 + -2544;
	// addi r9,r9,-2560
	ctx.r9.s64 = ctx.r9.s64 + -2560;
	// addi r11,r31,-2552
	r11.s64 = r31.s64 + -2552;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// lis r3,-32194
	ctx.r3.s64 = -2109865984;
	// stw r9,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r9.u32);
	// lis r4,-32194
	ctx.r4.s64 = -2109865984;
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// lis r5,-32194
	ctx.r5.s64 = -2109865984;
	// addi r10,r3,-2688
	ctx.r10.s64 = ctx.r3.s64 + -2688;
	// addi r9,r4,576
	ctx.r9.s64 = ctx.r4.s64 + 576;
	// addi r11,r5,496
	r11.s64 = ctx.r5.s64 + 496;
	// stw r10,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r10.u32);
	// lis r6,-32194
	ctx.r6.s64 = -2109865984;
	// stw r9,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r9.u32);
	// lis r7,-32194
	ctx.r7.s64 = -2109865984;
	// stw r11,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r11.u32);
	// lis r8,-32194
	ctx.r8.s64 = -2109865984;
	// addi r10,r6,-2656
	ctx.r10.s64 = ctx.r6.s64 + -2656;
	// addi r9,r7,-2872
	ctx.r9.s64 = ctx.r7.s64 + -2872;
	// addi r11,r8,-3032
	r11.s64 = ctx.r8.s64 + -3032;
	// stw r10,28(r30)
	PPC_STORE_U32(r30.u32 + 28, ctx.r10.u32);
	// stw r9,32(r30)
	PPC_STORE_U32(r30.u32 + 32, ctx.r9.u32);
	// stw r11,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r11.u32);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D9304"))) PPC_WEAK_FUNC(sub_823D9304);
PPC_FUNC_IMPL(__imp__sub_823D9304) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D9308"))) PPC_WEAK_FUNC(sub_823D9308);
PPC_FUNC_IMPL(__imp__sub_823D9308) {
	PPC_FUNC_PROLOGUE();
	// b 0x823d9270
	sub_823D9270(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823D930C"))) PPC_WEAK_FUNC(sub_823D930C);
PPC_FUNC_IMPL(__imp__sub_823D930C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D9310"))) PPC_WEAK_FUNC(sub_823D9310);
PPC_FUNC_IMPL(__imp__sub_823D9310) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bne cr6,0x823d9370
	if (!cr6.eq) goto loc_823D9370;
loc_823D9344:
	// bl 0x823e1000
	ctx.lr = 0x823D9348;
	sub_823E1000(ctx, base);
	// li r11,22
	r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823D9368;
	sub_823E02A8(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x823d9664
	goto loc_823D9664;
loc_823D9370:
	// li r5,36
	ctx.r5.s64 = 36;
	// li r4,255
	ctx.r4.s64 = 255;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x823D9380;
	sub_823D9890(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d9344
	if (cr6.eq) goto loc_823D9344;
	// ld r11,0(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// cmpdi cr6,r11,0
	cr6.compare<int64_t>(r11.s64, 0, xer);
	// bge cr6,0x823d93ac
	if (!cr6.lt) goto loc_823D93AC;
	// bl 0x823e1000
	ctx.lr = 0x823D9398;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,22
	ctx.r10.s64 = 22;
	// li r3,22
	ctx.r3.s64 = 22;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x823d9664
	goto loc_823D9664;
loc_823D93AC:
	// lis r10,-27840
	ctx.r10.s64 = -1824522240;
	// li r9,7
	ctx.r9.s64 = 7;
	// ori r10,r10,28671
	ctx.r10.u64 = ctx.r10.u64 | 28671;
	// rldimi r10,r9,32,0
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r10.u64 & 0xFFFFFFFF);
	// cmpd cr6,r11,r10
	cr6.compare<int64_t>(r11.s64, ctx.r10.s64, xer);
	// bgt cr6,0x823d9344
	if (cr6.gt) goto loc_823D9344;
	// bl 0x823e0a78
	ctx.lr = 0x823D93C8;
	sub_823E0A78(ctx, base);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x823e0e20
	ctx.lr = 0x823D93D0;
	sub_823E0E20(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823d93f0
	if (cr0.eq) goto loc_823D93F0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02f0
	ctx.lr = 0x823D93F0;
	sub_823E02F0(ctx, base);
loc_823D93F0:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x823e0e88
	ctx.lr = 0x823D93F8;
	sub_823E0E88(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823d9418
	if (cr0.eq) goto loc_823D9418;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02f0
	ctx.lr = 0x823D9418;
	sub_823E02F0(ctx, base);
loc_823D9418:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823e0ef0
	ctx.lr = 0x823D9420;
	sub_823E0EF0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823d9440
	if (cr0.eq) goto loc_823D9440;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02f0
	ctx.lr = 0x823D9440;
	sub_823E02F0(ctx, base);
loc_823D9440:
	// lis r10,3
	ctx.r10.s64 = 196608;
	// ld r11,0(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r10,r10,62592
	ctx.r10.u64 = ctx.r10.u64 | 62592;
	// cmpd cr6,r11,r10
	cr6.compare<int64_t>(r11.s64, ctx.r10.s64, xer);
	// ble cr6,0x823d94c0
	if (!cr6.gt) goto loc_823D94C0;
	// lwa r10,80(r1)
	ctx.r10.s64 = int32_t(PPC_LOAD_U32(ctx.r1.u32 + 80));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// bl 0x823e0b98
	ctx.lr = 0x823D946C;
	sub_823E0B98(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823d9664
	if (!cr0.eq) goto loc_823D9664;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d9660
	if (cr6.eq) goto loc_823D9660;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e0b18
	ctx.lr = 0x823D9488;
	sub_823E0B18(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823d9660
	if (cr0.eq) goto loc_823D9660;
	// ld r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwa r11,88(r1)
	r11.s64 = int32_t(PPC_LOAD_U32(ctx.r1.u32 + 88));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// bl 0x823e0b98
	ctx.lr = 0x823D94AC;
	sub_823E0B98(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823d9664
	if (!cr0.eq) goto loc_823D9664;
	// li r11,1
	r11.s64 = 1;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// b 0x823d9660
	goto loc_823D9660;
loc_823D94C0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823e0b98
	ctx.lr = 0x823D94C8;
	sub_823E0B98(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823d9664
	if (!cr0.eq) goto loc_823D9664;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d9510
	if (cr6.eq) goto loc_823D9510;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e0b18
	ctx.lr = 0x823D94E4;
	sub_823E0B18(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823d9510
	if (cr0.eq) goto loc_823D9510;
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwa r8,0(r31)
	ctx.r8.s64 = int32_t(PPC_LOAD_U32(r31.u32 + 0));
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r9,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r9.u32);
	// extsw r11,r11
	r11.s64 = r11.s32;
	// subf r11,r11,r8
	r11.s64 = ctx.r8.s64 - r11.s64;
	// b 0x823d951c
	goto loc_823D951C;
loc_823D9510:
	// lwa r11,0(r31)
	r11.s64 = int32_t(PPC_LOAD_U32(r31.u32 + 0));
	// lwa r10,80(r1)
	ctx.r10.s64 = int32_t(PPC_LOAD_U32(ctx.r1.u32 + 80));
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
loc_823D951C:
	// li r9,60
	ctx.r9.s64 = 60;
	// divd r10,r11,r9
	ctx.r10.s64 = r11.s64 / ctx.r9.s64;
	// mulli r10,r10,60
	ctx.r10.s64 = ctx.r10.s64 * 60;
	// subf r10,r10,r11
	ctx.r10.s64 = r11.s64 - ctx.r10.s64;
	// extsw. r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bge 0x823d9544
	if (!cr0.lt) goto loc_823D9544;
	// addi r10,r10,60
	ctx.r10.s64 = ctx.r10.s64 + 60;
	// addi r11,r11,-60
	r11.s64 = r11.s64 + -60;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_823D9544:
	// lwa r8,4(r31)
	ctx.r8.s64 = int32_t(PPC_LOAD_U32(r31.u32 + 4));
	// divd r10,r11,r9
	ctx.r10.s64 = r11.s64 / ctx.r9.s64;
	// add r11,r10,r8
	r11.u64 = ctx.r10.u64 + ctx.r8.u64;
	// divd r10,r11,r9
	ctx.r10.s64 = r11.s64 / ctx.r9.s64;
	// mulli r10,r10,60
	ctx.r10.s64 = ctx.r10.s64 * 60;
	// subf r10,r10,r11
	ctx.r10.s64 = r11.s64 - ctx.r10.s64;
	// extsw. r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// bge 0x823d9574
	if (!cr0.lt) goto loc_823D9574;
	// addi r10,r10,60
	ctx.r10.s64 = ctx.r10.s64 + 60;
	// addi r11,r11,-60
	r11.s64 = r11.s64 + -60;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
loc_823D9574:
	// lwa r10,8(r31)
	ctx.r10.s64 = int32_t(PPC_LOAD_U32(r31.u32 + 8));
	// divd r11,r11,r9
	r11.s64 = r11.s64 / ctx.r9.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// li r8,24
	ctx.r8.s64 = 24;
	// divd r10,r11,r8
	ctx.r10.s64 = r11.s64 / ctx.r8.s64;
	// mulli r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 * 24;
	// subf r10,r10,r11
	ctx.r10.s64 = r11.s64 - ctx.r10.s64;
	// extsw. r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bge 0x823d95a8
	if (!cr0.lt) goto loc_823D95A8;
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// addi r11,r11,-24
	r11.s64 = r11.s64 + -24;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_823D95A8:
	// divd r11,r11,r8
	r11.s64 = r11.s64 / ctx.r8.s64;
	// cmpdi cr6,r11,0
	cr6.compare<int64_t>(r11.s64, 0, xer);
	// ble cr6,0x823d95f0
	if (!cr6.gt) goto loc_823D95F0;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// extsw r11,r11
	r11.s64 = r11.s32;
	// li r8,7
	ctx.r8.s64 = 7;
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// divw r8,r7,r8
	ctx.r8.s32 = ctx.r7.s32 / ctx.r8.s32;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// mulli r10,r8,7
	ctx.r10.s64 = ctx.r8.s64 * 7;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// subf r11,r10,r7
	r11.s64 = ctx.r7.s64 - ctx.r10.s64;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// b 0x823d9660
	goto loc_823D9660;
loc_823D95F0:
	// bge cr6,0x823d9660
	if (!cr6.lt) goto loc_823D9660;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// extsw r11,r11
	r11.s64 = r11.s32;
	// li r8,7
	ctx.r8.s64 = 7;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r9,r9,7
	ctx.r9.s64 = ctx.r9.s64 + 7;
	// add. r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// divw r8,r9,r8
	ctx.r8.s32 = ctx.r9.s32 / ctx.r8.s32;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// mulli r8,r8,7
	ctx.r8.s64 = ctx.r8.s64 * 7;
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// bgt 0x823d9654
	if (cr0.gt) goto loc_823D9654;
	// addi r8,r10,31
	ctx.r8.s64 = ctx.r10.s64 + 31;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r7,11
	ctx.r7.s64 = 11;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// stw r7,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r7.u32);
	// addi r11,r11,365
	r11.s64 = r11.s64 + 365;
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// b 0x823d965c
	goto loc_823D965C;
loc_823D9654:
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
loc_823D965C:
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
loc_823D9660:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823D9664:
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

__attribute__((alias("__imp__sub_823D967C"))) PPC_WEAK_FUNC(sub_823D967C);
PPC_FUNC_IMPL(__imp__sub_823D967C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D9680"))) PPC_WEAK_FUNC(sub_823D9680);
PPC_FUNC_IMPL(__imp__sub_823D9680) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// bl 0x823e10e0
	ctx.lr = 0x823D969C;
	sub_823E10E0(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x823d96ac
	if (!cr0.eq) goto loc_823D96AC;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823d96c8
	goto loc_823D96C8;
loc_823D96AC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9310
	ctx.lr = 0x823D96B8;
	sub_823D9310(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bne 0x823d96c8
	if (!cr0.eq) goto loc_823D96C8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823D96C8:
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

__attribute__((alias("__imp__sub_823D96E0"))) PPC_WEAK_FUNC(sub_823D96E0);
PPC_FUNC_IMPL(__imp__sub_823D96E0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82457b40
	ctx.lr = 0x823D96FC;
	sub_82457B40(ctx, base);
	// lis r12,-414
	r12.s64 = -27131904;
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r11,152
	r11.s64 = 9961472;
	// ori r12,r12,20001
	r12.u64 = r12.u64 | 20001;
	// ori r11,r11,38528
	r11.u64 = r11.u64 | 38528;
	// rldicr r12,r12,32,31
	r12.u64 = __builtin_rotateleft64(r12.u64, 32) & 0xFFFFFFFF00000000;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// oris r12,r12,10945
	r12.u64 = r12.u64 | 717291520;
	// ori r12,r12,32768
	r12.u64 = r12.u64 | 32768;
	// add r10,r10,r12
	ctx.r10.u64 = ctx.r10.u64 + r12.u64;
	// divdu r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 / r11.u64;
	// beq cr6,0x823d9730
	if (cr6.eq) goto loc_823D9730;
	// std r3,0(r31)
	PPC_STORE_U64(r31.u32 + 0, ctx.r3.u64);
loc_823D9730:
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

__attribute__((alias("__imp__sub_823D9744"))) PPC_WEAK_FUNC(sub_823D9744);
PPC_FUNC_IMPL(__imp__sub_823D9744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D9748"))) PPC_WEAK_FUNC(sub_823D9748);
PPC_FUNC_IMPL(__imp__sub_823D9748) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r27{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9464(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9464);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823D9758;
	// std r4,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.r4.u64);
	// std r5,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.r5.u64);
	// std r6,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.r6.u64);
	// std r7,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.r7.u64);
	// std r8,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.r8.u64);
	// std r9,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.r9.u64);
	// std r10,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.r10.u64);
	// addi r31,r1,-128
	r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cntlzw r11,r30
	r11.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823d97c0
	if (!cr6.eq) goto loc_823D97C0;
	// bl 0x823e1000
	ctx.lr = 0x823D9798;
	sub_823E1000(ctx, base);
	// li r11,22
	r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823D97B8;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823d982c
	goto loc_823D982C;
loc_823D97C0:
	// addi r11,r31,80
	r11.s64 = r31.s64 + 80;
	// addi r10,r31,152
	ctx.r10.s64 = r31.s64 + 152;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x823e1160
	ctx.lr = 0x823D97D0;
	sub_823E1160(ctx, base);
	// addi r4,r3,32
	ctx.r4.s64 = ctx.r3.s64 + 32;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823e1340
	ctx.lr = 0x823D97DC;
	sub_823E1340(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// bl 0x823e1160
	ctx.lr = 0x823D97E4;
	sub_823E1160(ctx, base);
	// addi r3,r3,32
	ctx.r3.s64 = ctx.r3.s64 + 32;
	// bl 0x823e13f8
	ctx.lr = 0x823D97EC;
	sub_823E13F8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x823e1160
	ctx.lr = 0x823D97F4;
	sub_823E1160(ctx, base);
	// addi r3,r3,32
	ctx.r3.s64 = ctx.r3.s64 + 32;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x823e1668
	ctx.lr = 0x823D9808;
	sub_823E1668(ctx, base);
	// stw r3,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r3.u32);
	// bl 0x823e1160
	ctx.lr = 0x823D9810;
	sub_823E1160(ctx, base);
	// addi r4,r3,32
	ctx.r4.s64 = ctx.r3.s64 + 32;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823e14d0
	ctx.lr = 0x823D981C;
	sub_823E14D0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,128
	r12.s64 = r31.s64 + 128;
	// bl 0x823d9834
	ctx.lr = 0x823D9828;
	sub_823D9834(ctx, base);
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
loc_823D982C:
	// addi r1,r31,128
	ctx.r1.s64 = r31.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823D9750"))) PPC_WEAK_FUNC(sub_823D9750);
PPC_FUNC_IMPL(__imp__sub_823D9750) {
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
	ctx.lr = 0x823D9758;
	// std r4,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.r4.u64);
	// std r5,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.r5.u64);
	// std r6,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.r6.u64);
	// std r7,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.r7.u64);
	// std r8,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.r8.u64);
	// std r9,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.r9.u64);
	// std r10,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.r10.u64);
	// addi r31,r1,-128
	r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cntlzw r11,r30
	r11.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823d97c0
	if (!cr6.eq) goto loc_823D97C0;
	// bl 0x823e1000
	ctx.lr = 0x823D9798;
	sub_823E1000(ctx, base);
	// li r11,22
	r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823D97B8;
	sub_823E02A8(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823d982c
	goto loc_823D982C;
loc_823D97C0:
	// addi r11,r31,80
	r11.s64 = r31.s64 + 80;
	// addi r10,r31,152
	ctx.r10.s64 = r31.s64 + 152;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x823e1160
	ctx.lr = 0x823D97D0;
	sub_823E1160(ctx, base);
	// addi r4,r3,32
	ctx.r4.s64 = ctx.r3.s64 + 32;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823e1340
	ctx.lr = 0x823D97DC;
	sub_823E1340(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// bl 0x823e1160
	ctx.lr = 0x823D97E4;
	sub_823E1160(ctx, base);
	// addi r3,r3,32
	ctx.r3.s64 = ctx.r3.s64 + 32;
	// bl 0x823e13f8
	ctx.lr = 0x823D97EC;
	sub_823E13F8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x823e1160
	ctx.lr = 0x823D97F4;
	sub_823E1160(ctx, base);
	// addi r3,r3,32
	ctx.r3.s64 = ctx.r3.s64 + 32;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x823e1668
	ctx.lr = 0x823D9808;
	sub_823E1668(ctx, base);
	// stw r3,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r3.u32);
	// bl 0x823e1160
	ctx.lr = 0x823D9810;
	sub_823E1160(ctx, base);
	// addi r4,r3,32
	ctx.r4.s64 = ctx.r3.s64 + 32;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823e14d0
	ctx.lr = 0x823D981C;
	sub_823E14D0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,128
	r12.s64 = r31.s64 + 128;
	// bl 0x823d9834
	ctx.lr = 0x823D9828;
	sub_823D9834(ctx, base);
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
loc_823D982C:
	// addi r1,r31,128
	ctx.r1.s64 = r31.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823D9834"))) PPC_WEAK_FUNC(sub_823D9834);
PPC_FUNC_IMPL(__imp__sub_823D9834) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x823e1160
	ctx.lr = 0x823D9844;
	sub_823E1160(ctx, base);
	// addi r4,r3,32
	ctx.r4.s64 = ctx.r3.s64 + 32;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823e13d0
	ctx.lr = 0x823D9850;
	sub_823E13D0(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D9860"))) PPC_WEAK_FUNC(sub_823D9860);
PPC_FUNC_IMPL(__imp__sub_823D9860) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r11,-18592(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -18592);
	// lwz r10,-10696(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10696);
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D9884"))) PPC_WEAK_FUNC(sub_823D9884);
PPC_FUNC_IMPL(__imp__sub_823D9884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D9888"))) PPC_WEAK_FUNC(sub_823D9888);
PPC_FUNC_IMPL(__imp__sub_823D9888) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D988C"))) PPC_WEAK_FUNC(sub_823D988C);
PPC_FUNC_IMPL(__imp__sub_823D988C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D9890"))) PPC_WEAK_FUNC(sub_823D9890);
PPC_FUNC_IMPL(__imp__sub_823D9890) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r0{};
	// addi r0,r5,1
	r0.s64 = ctx.r5.s64 + 1;
	// mtctr r0
	ctr.u64 = r0.u64;
	// ori r6,r3,0
	ctx.r6.u64 = ctx.r3.u64 | 0;
	// b 0x823d98ac
	goto loc_823D98AC;
loc_823D98A0:
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// stb r4,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, ctx.r4.u8);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
loc_823D98AC:
	// andi. r0,r6,3
	r0.u64 = ctx.r6.u64 & 3;
	cr0.compare<int32_t>(r0.s32, 0, xer);
	// bdnzf eq,0x823d98a0
	--ctr.u64;
	if (ctr.u32 != 0 && !cr0.eq) goto loc_823D98A0;
	// rlwimi r4,r4,8,16,23
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0xFF00) | (ctx.r4.u64 & 0xFFFFFFFFFFFF00FF);
	// rlwinm. r0,r5,28,4,31
	r0.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 28) & 0xFFFFFFF;
	cr0.compare<int32_t>(r0.s32, 0, xer);
	// rlwimi r4,r4,16,0,15
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r4.u32, 16) & 0xFFFF0000) | (ctx.r4.u64 & 0xFFFFFFFF0000FFFF);
	// beq+ 0x823d98e0
	if (cr0.eq) goto loc_823D98E0;
	// mtctr r0
	ctr.u64 = r0.u64;
loc_823D98C8:
	// stw r4,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r4.u32);
	// stw r4,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r4.u32);
	// stw r4,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r4.u32);
	// stw r4,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, ctx.r4.u32);
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// bdnz+ 0x823d98c8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823D98C8;
loc_823D98E0:
	// rlwinm. r0,r5,30,30,31
	r0.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3;
	cr0.compare<int32_t>(r0.s32, 0, xer);
	// beq- 0x823d990c
	if (cr0.eq) goto loc_823D990C;
	// mtctr r0
	ctr.u64 = r0.u64;
	// stw r4,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r4.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bdz- 0x823d990c
	--ctr.u64;
	if (ctr.u32 == 0) goto loc_823D990C;
	// stw r4,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r4.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bdz- 0x823d990c
	--ctr.u64;
	if (ctr.u32 == 0) goto loc_823D990C;
	// stw r4,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r4.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
loc_823D990C:
	// andi. r0,r5,3
	r0.u64 = ctx.r5.u64 & 3;
	cr0.compare<int32_t>(r0.s32, 0, xer);
	// mtctr r0
	ctr.u64 = r0.u64;
	// beqlr+ 
	if (cr0.eq) return;
	// stb r4,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, ctx.r4.u8);
	// bdzlr- 
	--ctr.u64;
	if (ctr.u32 == 0) return;
}

__attribute__((alias("__imp__sub_823D9920"))) PPC_WEAK_FUNC(sub_823D9920);
PPC_FUNC_IMPL(__imp__sub_823D9920) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	// stb r4,1(r6)
	PPC_STORE_U8(ctx.r6.u32 + 1, ctx.r4.u8);
	// bdzlr- 
	--ctr.u64;
	if (ctr.u32 == 0) return;
}

__attribute__((alias("__imp__sub_823D9928"))) PPC_WEAK_FUNC(sub_823D9928);
PPC_FUNC_IMPL(__imp__sub_823D9928) {
	PPC_FUNC_PROLOGUE();
	// stb r4,2(r6)
	PPC_STORE_U8(ctx.r6.u32 + 2, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D9930"))) PPC_WEAK_FUNC(sub_823D9930);
PPC_FUNC_IMPL(__imp__sub_823D9930) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x823e24c8
	ctx.lr = 0x823D9948;
	sub_823E24C8(ctx, base);
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// lis r9,-32107
	ctx.r9.s64 = -2104164352;
	// mr. r11,r3
	r11.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,-22832(r10)
	PPC_STORE_U32(ctx.r10.u32 + -22832, r11.u32);
	// stw r11,-22836(r9)
	PPC_STORE_U32(ctx.r9.u32 + -22836, r11.u32);
	// bne 0x823d9968
	if (!cr0.eq) goto loc_823D9968;
	// li r3,24
	ctx.r3.s64 = 24;
	// b 0x823d9974
	goto loc_823D9974;
loc_823D9968:
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_823D9974:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D9984"))) PPC_WEAK_FUNC(sub_823D9984);
PPC_FUNC_IMPL(__imp__sub_823D9984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D9988"))) PPC_WEAK_FUNC(sub_823D9988);
PPC_FUNC_IMPL(__imp__sub_823D9988) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
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
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9488(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9488);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x823D9998;
	// addi r31,r1,-176
	r31.s64 = ctx.r1.s64 + -176;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// bl 0x823daed0
	ctx.lr = 0x823D99A8;
	sub_823DAED0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lis r24,-32107
	r24.s64 = -2104164352;
	// lis r25,-32107
	r25.s64 = -2104164352;
	// lwz r30,-22836(r24)
	r30.u64 = PPC_LOAD_U32(r24.u32 + -22836);
	// lwz r28,-22832(r25)
	r28.u64 = PPC_LOAD_U32(r25.u32 + -22832);
	// cmplw cr6,r30,r28
	cr6.compare<uint32_t>(r30.u32, r28.u32, xer);
	// blt cr6,0x823d9a54
	if (cr6.lt) goto loc_823D9A54;
	// subf r26,r28,r30
	r26.s64 = r30.s64 - r28.s64;
	// addi r27,r26,4
	r27.s64 = r26.s64 + 4;
	// cmplwi cr6,r27,4
	cr6.compare<uint32_t>(r27.u32, 4, xer);
	// blt cr6,0x823d9a54
	if (cr6.lt) goto loc_823D9A54;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823e2380
	ctx.lr = 0x823D99DC;
	sub_823E2380(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplw cr6,r29,r27
	cr6.compare<uint32_t>(r29.u32, r27.u32, xer);
	// bge cr6,0x823d9a40
	if (!cr6.lt) goto loc_823D9A40;
	// cmplwi cr6,r29,2048
	cr6.compare<uint32_t>(r29.u32, 2048, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// blt cr6,0x823d99f8
	if (cr6.lt) goto loc_823D99F8;
	// li r11,2048
	r11.s64 = 2048;
loc_823D99F8:
	// add r4,r11,r29
	ctx.r4.u64 = r11.u64 + r29.u64;
	// cmplw cr6,r4,r29
	cr6.compare<uint32_t>(ctx.r4.u32, r29.u32, xer);
	// blt cr6,0x823d9a14
	if (cr6.lt) goto loc_823D9A14;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823e21e0
	ctx.lr = 0x823D9A0C;
	sub_823E21E0(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x823d9a30
	if (!cr0.eq) goto loc_823D9A30;
loc_823D9A14:
	// addi r4,r29,16
	ctx.r4.s64 = r29.s64 + 16;
	// cmplw cr6,r4,r29
	cr6.compare<uint32_t>(ctx.r4.u32, r29.u32, xer);
	// blt cr6,0x823d9a54
	if (cr6.lt) goto loc_823D9A54;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823e21e0
	ctx.lr = 0x823D9A28;
	sub_823E21E0(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x823d9a54
	if (cr0.eq) goto loc_823D9A54;
loc_823D9A30:
	// srawi r11,r26,2
	xer.ca = (r26.s32 < 0) & ((r26.u32 & 0x3) != 0);
	r11.s64 = r26.s32 >> 2;
	// stw r3,-22832(r25)
	PPC_STORE_U32(r25.u32 + -22832, ctx.r3.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r11,r3
	r30.u64 = r11.u64 + ctx.r3.u64;
loc_823D9A40:
	// addi r11,r30,4
	r11.s64 = r30.s64 + 4;
	// stw r23,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r23.u32);
	// stw r23,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r23.u32);
	// stw r11,-22836(r24)
	PPC_STORE_U32(r24.u32 + -22836, r11.u32);
	// b 0x823d9a5c
	goto loc_823D9A5C;
loc_823D9A54:
	// li r11,0
	r11.s64 = 0;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
loc_823D9A5C:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,176
	r12.s64 = r31.s64 + 176;
	// bl 0x823d9a74
	ctx.lr = 0x823D9A68;
	sub_823D9A74(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r1,r31,176
	ctx.r1.s64 = r31.s64 + 176;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_823D9990"))) PPC_WEAK_FUNC(sub_823D9990);
PPC_FUNC_IMPL(__imp__sub_823D9990) {
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
	ctx.lr = 0x823D9998;
	// addi r31,r1,-176
	r31.s64 = ctx.r1.s64 + -176;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// bl 0x823daed0
	ctx.lr = 0x823D99A8;
	sub_823DAED0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lis r24,-32107
	r24.s64 = -2104164352;
	// lis r25,-32107
	r25.s64 = -2104164352;
	// lwz r30,-22836(r24)
	r30.u64 = PPC_LOAD_U32(r24.u32 + -22836);
	// lwz r28,-22832(r25)
	r28.u64 = PPC_LOAD_U32(r25.u32 + -22832);
	// cmplw cr6,r30,r28
	cr6.compare<uint32_t>(r30.u32, r28.u32, xer);
	// blt cr6,0x823d9a54
	if (cr6.lt) goto loc_823D9A54;
	// subf r26,r28,r30
	r26.s64 = r30.s64 - r28.s64;
	// addi r27,r26,4
	r27.s64 = r26.s64 + 4;
	// cmplwi cr6,r27,4
	cr6.compare<uint32_t>(r27.u32, 4, xer);
	// blt cr6,0x823d9a54
	if (cr6.lt) goto loc_823D9A54;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823e2380
	ctx.lr = 0x823D99DC;
	sub_823E2380(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplw cr6,r29,r27
	cr6.compare<uint32_t>(r29.u32, r27.u32, xer);
	// bge cr6,0x823d9a40
	if (!cr6.lt) goto loc_823D9A40;
	// cmplwi cr6,r29,2048
	cr6.compare<uint32_t>(r29.u32, 2048, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// blt cr6,0x823d99f8
	if (cr6.lt) goto loc_823D99F8;
	// li r11,2048
	r11.s64 = 2048;
loc_823D99F8:
	// add r4,r11,r29
	ctx.r4.u64 = r11.u64 + r29.u64;
	// cmplw cr6,r4,r29
	cr6.compare<uint32_t>(ctx.r4.u32, r29.u32, xer);
	// blt cr6,0x823d9a14
	if (cr6.lt) goto loc_823D9A14;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823e21e0
	ctx.lr = 0x823D9A0C;
	sub_823E21E0(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x823d9a30
	if (!cr0.eq) goto loc_823D9A30;
loc_823D9A14:
	// addi r4,r29,16
	ctx.r4.s64 = r29.s64 + 16;
	// cmplw cr6,r4,r29
	cr6.compare<uint32_t>(ctx.r4.u32, r29.u32, xer);
	// blt cr6,0x823d9a54
	if (cr6.lt) goto loc_823D9A54;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823e21e0
	ctx.lr = 0x823D9A28;
	sub_823E21E0(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x823d9a54
	if (cr0.eq) goto loc_823D9A54;
loc_823D9A30:
	// srawi r11,r26,2
	xer.ca = (r26.s32 < 0) & ((r26.u32 & 0x3) != 0);
	r11.s64 = r26.s32 >> 2;
	// stw r3,-22832(r25)
	PPC_STORE_U32(r25.u32 + -22832, ctx.r3.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r11,r3
	r30.u64 = r11.u64 + ctx.r3.u64;
loc_823D9A40:
	// addi r11,r30,4
	r11.s64 = r30.s64 + 4;
	// stw r23,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r23.u32);
	// stw r23,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r23.u32);
	// stw r11,-22836(r24)
	PPC_STORE_U32(r24.u32 + -22836, r11.u32);
	// b 0x823d9a5c
	goto loc_823D9A5C;
loc_823D9A54:
	// li r11,0
	r11.s64 = 0;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
loc_823D9A5C:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,176
	r12.s64 = r31.s64 + 176;
	// bl 0x823d9a74
	ctx.lr = 0x823D9A68;
	sub_823D9A74(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r1,r31,176
	ctx.r1.s64 = r31.s64 + 176;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_823D9A74"))) PPC_WEAK_FUNC(sub_823D9A74);
PPC_FUNC_IMPL(__imp__sub_823D9A74) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x823daed8
	ctx.lr = 0x823D9A84;
	sub_823DAED8(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D9A94"))) PPC_WEAK_FUNC(sub_823D9A94);
PPC_FUNC_IMPL(__imp__sub_823D9A94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D9A98"))) PPC_WEAK_FUNC(sub_823D9A98);
PPC_FUNC_IMPL(__imp__sub_823D9A98) {
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
	// bl 0x823d9990
	ctx.lr = 0x823D9AA8;
	sub_823D9990(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// neg r3,r11
	ctx.r3.s64 = -r11.s64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D9AC4"))) PPC_WEAK_FUNC(sub_823D9AC4);
PPC_FUNC_IMPL(__imp__sub_823D9AC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D9AC8"))) PPC_WEAK_FUNC(sub_823D9AC8);
PPC_FUNC_IMPL(__imp__sub_823D9AC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823d9b50
	if (cr6.eq) goto loc_823D9B50;
	// lwz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// ble cr6,0x823d9b20
	if (!cr6.gt) goto loc_823D9B20;
	// li r9,10
	ctx.r9.s64 = 10;
loc_823D9AEC:
	// divw r8,r11,r9
	ctx.r8.s32 = r11.s32 / ctx.r9.s32;
	// mulli r8,r8,10
	ctx.r8.s64 = ctx.r8.s64 * 10;
	// subf r8,r8,r11
	ctx.r8.s64 = r11.s64 - ctx.r8.s64;
	// divw. r11,r11,r9
	r11.s32 = r11.s32 / ctx.r9.s32;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r8,r8,48
	ctx.r8.s64 = ctx.r8.s64 + 48;
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r8,0(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// stw r8,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r8.u32);
	// ble 0x823d9b20
	if (!cr0.gt) goto loc_823D9B20;
	// cmplwi cr6,r8,1
	cr6.compare<uint32_t>(ctx.r8.u32, 1, xer);
	// bgt cr6,0x823d9aec
	if (cr6.gt) goto loc_823D9AEC;
loc_823D9B20:
	// lwz r9,0(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
loc_823D9B2C:
	// lbz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stb r8,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r8.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// blt cr6,0x823d9b2c
	if (cr6.lt) goto loc_823D9B2C;
	// blr 
	return;
loc_823D9B50:
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// bge cr6,0x823d9bb4
	if (!cr6.lt) goto loc_823D9BB4;
	// addi r10,r4,-1
	ctx.r10.s64 = ctx.r4.s64 + -1;
	// addic. r9,r10,1
	xer.ca = ctx.r10.u32 > 4294967294;
	ctx.r9.s64 = ctx.r10.s64 + 1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x823d9b98
	if (cr0.eq) goto loc_823D9B98;
	// li r9,10
	ctx.r9.s64 = 10;
loc_823D9B6C:
	// divw r7,r11,r9
	ctx.r7.s32 = r11.s32 / ctx.r9.s32;
	// lwz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// mulli r7,r7,10
	ctx.r7.s64 = ctx.r7.s64 * 10;
	// subf r7,r7,r11
	ctx.r7.s64 = r11.s64 - ctx.r7.s64;
	// divw r11,r11,r9
	r11.s32 = r11.s32 / ctx.r9.s32;
	// addi r7,r7,48
	ctx.r7.s64 = ctx.r7.s64 + 48;
	// stbx r7,r4,r10
	PPC_STORE_U8(ctx.r4.u32 + ctx.r10.u32, ctx.r7.u8);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x823d9b6c
	if (!cr6.eq) goto loc_823D9B6C;
loc_823D9B98:
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r11.u32);
	// blr 
	return;
loc_823D9BB4:
	// stw r8,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D9BBC"))) PPC_WEAK_FUNC(sub_823D9BBC);
PPC_FUNC_IMPL(__imp__sub_823D9BBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D9BC0"))) PPC_WEAK_FUNC(sub_823D9BC0);
PPC_FUNC_IMPL(__imp__sub_823D9BC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x823D9BC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// extsb r11,r4
	r11.s64 = ctx.r4.s8;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// cmpwi cr6,r11,89
	cr6.compare<int32_t>(r11.s32, 89, xer);
	// bgt cr6,0x823d9e7c
	if (cr6.gt) goto loc_823D9E7C;
	// beq cr6,0x823d9e3c
	if (cr6.eq) goto loc_823D9E3C;
	// cmpwi cr6,r11,73
	cr6.compare<int32_t>(r11.s32, 73, xer);
	// bgt cr6,0x823d9d68
	if (cr6.gt) goto loc_823D9D68;
	// beq cr6,0x823d9d38
	if (cr6.eq) goto loc_823D9D38;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x823da234
	if (cr6.eq) goto loc_823DA234;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// beq cr6,0x823da234
	if (cr6.eq) goto loc_823DA234;
	// cmpwi cr6,r11,37
	cr6.compare<int32_t>(r11.s32, 37, xer);
	// beq cr6,0x823d9d10
	if (cr6.eq) goto loc_823D9D10;
	// cmpwi cr6,r11,65
	cr6.compare<int32_t>(r11.s32, 65, xer);
	// beq cr6,0x823d9cac
	if (cr6.eq) goto loc_823D9CAC;
	// cmpwi cr6,r11,66
	cr6.compare<int32_t>(r11.s32, 66, xer);
	// beq cr6,0x823d9c48
	if (cr6.eq) goto loc_823D9C48;
	// cmpwi cr6,r11,72
	cr6.compare<int32_t>(r11.s32, 72, xer);
	// bne cr6,0x823da028
	if (!cr6.eq) goto loc_823DA028;
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823da004
	if (cr6.lt) goto loc_823DA004;
	// cmpwi cr6,r3,23
	cr6.compare<int32_t>(ctx.r3.s32, 23, xer);
loc_823D9C40:
	// ble cr6,0x823d9eec
	if (!cr6.gt) goto loc_823D9EEC;
	// b 0x823da004
	goto loc_823DA004;
loc_823D9C48:
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x823da004
	if (cr6.lt) goto loc_823DA004;
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// bgt cr6,0x823da004
	if (cr6.gt) goto loc_823DA004;
	// addi r11,r11,26
	r11.s64 = r11.s64 + 26;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r27
	r11.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// b 0x823d9c9c
	goto loc_823D9C9C;
loc_823D9C6C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x823da234
	if (cr0.eq) goto loc_823DA234;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_823D9C9C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823d9c6c
	if (!cr6.eq) goto loc_823D9C6C;
	// b 0x823da234
	goto loc_823DA234;
loc_823D9CAC:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x823da004
	if (cr6.lt) goto loc_823DA004;
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// bgt cr6,0x823da004
	if (cr6.gt) goto loc_823DA004;
	// addi r11,r11,7
	r11.s64 = r11.s64 + 7;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r27
	r11.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// b 0x823d9d00
	goto loc_823D9D00;
loc_823D9CD0:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x823da234
	if (cr0.eq) goto loc_823DA234;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_823D9D00:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823d9cd0
	if (!cr6.eq) goto loc_823D9CD0;
	// b 0x823da234
	goto loc_823DA234;
loc_823D9D10:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,37
	ctx.r10.s64 = 37;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// b 0x823da234
	goto loc_823DA234;
loc_823D9D38:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x823da004
	if (cr6.lt) goto loc_823DA004;
	// cmpwi cr6,r11,23
	cr6.compare<int32_t>(r11.s32, 23, xer);
	// bgt cr6,0x823da004
	if (cr6.gt) goto loc_823DA004;
	// li r10,12
	ctx.r10.s64 = 12;
	// divw r10,r11,r10
	ctx.r10.s32 = r11.s32 / ctx.r10.s32;
	// mulli r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 * 12;
	// subf. r3,r10,r11
	ctx.r3.s64 = r11.s64 - ctx.r10.s64;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823d9eec
	if (!cr0.eq) goto loc_823D9EEC;
	// li r3,12
	ctx.r3.s64 = 12;
	// b 0x823d9eec
	goto loc_823D9EEC;
loc_823D9D68:
	// cmpwi cr6,r11,77
	cr6.compare<int32_t>(r11.s32, 77, xer);
	// beq cr6,0x823d9e28
	if (cr6.eq) goto loc_823D9E28;
	// cmpwi cr6,r11,83
	cr6.compare<int32_t>(r11.s32, 83, xer);
	// beq cr6,0x823d9e20
	if (cr6.eq) goto loc_823D9E20;
	// cmpwi cr6,r11,85
	cr6.compare<int32_t>(r11.s32, 85, xer);
	// beq cr6,0x823d9dc0
	if (cr6.eq) goto loc_823D9DC0;
	// cmpwi cr6,r11,87
	cr6.compare<int32_t>(r11.s32, 87, xer);
	// beq cr6,0x823d9d94
	if (cr6.eq) goto loc_823D9D94;
	// cmpwi cr6,r11,88
	cr6.compare<int32_t>(r11.s32, 88, xer);
	// bne cr6,0x823da028
	if (!cr6.eq) goto loc_823DA028;
	// b 0x823d9f5c
	goto loc_823D9F5C;
loc_823D9D94:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x823da004
	if (cr6.lt) goto loc_823DA004;
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// bgt cr6,0x823da004
	if (cr6.gt) goto loc_823DA004;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823d9db8
	if (!cr6.eq) goto loc_823D9DB8;
	// li r11,6
	r11.s64 = 6;
	// b 0x823d9dd4
	goto loc_823D9DD4;
loc_823D9DB8:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// b 0x823d9dd4
	goto loc_823D9DD4;
loc_823D9DC0:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x823da004
	if (cr6.lt) goto loc_823DA004;
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// bgt cr6,0x823da004
	if (cr6.gt) goto loc_823DA004;
loc_823D9DD4:
	// lwz r10,28(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x823da004
	if (cr6.lt) goto loc_823DA004;
	// cmpwi cr6,r10,365
	cr6.compare<int32_t>(ctx.r10.s32, 365, xer);
	// bgt cr6,0x823da004
	if (cr6.gt) goto loc_823DA004;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x823d9df8
	if (!cr6.lt) goto loc_823D9DF8;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823d9eec
	goto loc_823D9EEC;
loc_823D9DF8:
	// lwz r9,28(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// li r10,7
	ctx.r10.s64 = 7;
	// divw r8,r9,r10
	ctx.r8.s32 = ctx.r9.s32 / ctx.r10.s32;
	// divw r3,r9,r10
	ctx.r3.s32 = ctx.r9.s32 / ctx.r10.s32;
	// mulli r10,r8,7
	ctx.r10.s64 = ctx.r8.s64 * 7;
	// subf r10,r10,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r10.s64;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x823d9eec
	if (cr6.lt) goto loc_823D9EEC;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// b 0x823d9eec
	goto loc_823D9EEC;
loc_823D9E20:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// b 0x823d9e2c
	goto loc_823D9E2C;
loc_823D9E28:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
loc_823D9E2C:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823da004
	if (cr6.lt) goto loc_823DA004;
	// cmpwi cr6,r3,59
	cr6.compare<int32_t>(ctx.r3.s32, 59, xer);
	// b 0x823d9c40
	goto loc_823D9C40;
loc_823D9E3C:
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// cmpwi cr6,r11,-1900
	cr6.compare<int32_t>(r11.s32, -1900, xer);
	// blt cr6,0x823da004
	if (cr6.lt) goto loc_823DA004;
	// cmpwi cr6,r11,8099
	cr6.compare<int32_t>(r11.s32, 8099, xer);
	// bgt cr6,0x823da004
	if (cr6.gt) goto loc_823DA004;
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// li r10,100
	ctx.r10.s64 = 100;
	// li r4,4
	ctx.r4.s64 = 4;
	// divw r11,r9,r10
	r11.s32 = ctx.r9.s32 / ctx.r10.s32;
	// divw r10,r9,r10
	ctx.r10.s32 = ctx.r9.s32 / ctx.r10.s32;
	// addi r11,r11,19
	r11.s64 = r11.s64 + 19;
	// mulli r8,r10,100
	ctx.r8.s64 = ctx.r10.s64 * 100;
	// mulli r10,r11,100
	ctx.r10.s64 = r11.s64 * 100;
	// subf r11,r8,r9
	r11.s64 = ctx.r9.s64 - ctx.r8.s64;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x823d9ef0
	goto loc_823D9EF0;
loc_823D9E7C:
	// cmpwi cr6,r11,109
	cr6.compare<int32_t>(r11.s32, 109, xer);
	// bgt cr6,0x823da098
	if (cr6.gt) goto loc_823DA098;
	// beq cr6,0x823da07c
	if (cr6.eq) goto loc_823DA07C;
	// cmpwi cr6,r11,90
	cr6.compare<int32_t>(r11.s32, 90, xer);
	// beq cr6,0x823da0c0
	if (cr6.eq) goto loc_823DA0C0;
	// cmpwi cr6,r11,97
	cr6.compare<int32_t>(r11.s32, 97, xer);
	// beq cr6,0x823d9ff0
	if (cr6.eq) goto loc_823D9FF0;
	// cmpwi cr6,r11,98
	cr6.compare<int32_t>(r11.s32, 98, xer);
	// beq cr6,0x823d9f8c
	if (cr6.eq) goto loc_823D9F8C;
	// cmpwi cr6,r11,99
	cr6.compare<int32_t>(r11.s32, 99, xer);
	// beq cr6,0x823d9f00
	if (cr6.eq) goto loc_823D9F00;
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x823d9ed8
	if (cr6.eq) goto loc_823D9ED8;
	// cmpwi cr6,r11,106
	cr6.compare<int32_t>(r11.s32, 106, xer);
	// bne cr6,0x823da028
	if (!cr6.eq) goto loc_823DA028;
	// lwz r11,28(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x823da004
	if (cr6.lt) goto loc_823DA004;
	// cmpwi cr6,r11,365
	cr6.compare<int32_t>(r11.s32, 365, xer);
	// bgt cr6,0x823da004
	if (cr6.gt) goto loc_823DA004;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// b 0x823d9ef0
	goto loc_823D9EF0;
loc_823D9ED8:
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// blt cr6,0x823da004
	if (cr6.lt) goto loc_823DA004;
	// cmpwi cr6,r3,31
	cr6.compare<int32_t>(ctx.r3.s32, 31, xer);
	// bgt cr6,0x823da004
	if (cr6.gt) goto loc_823DA004;
loc_823D9EEC:
	// li r4,2
	ctx.r4.s64 = 2;
loc_823D9EF0:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// bl 0x823d9ac8
	ctx.lr = 0x823D9EFC;
	sub_823D9AC8(ctx, base);
	// b 0x823da234
	goto loc_823DA234;
loc_823D9F00:
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// beq cr6,0x823d9f84
	if (cr6.eq) goto loc_823D9F84;
	// li r4,1
	ctx.r4.s64 = 1;
loc_823D9F20:
	// bl 0x823da240
	ctx.lr = 0x823D9F24;
	sub_823DA240(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823da028
	if (cr0.eq) goto loc_823DA028;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823da028
	if (cr6.eq) goto loc_823DA028;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,32
	ctx.r10.s64 = 32;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_823D9F5C:
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_823D9F74:
	// bl 0x823da240
	ctx.lr = 0x823D9F78;
	sub_823DA240(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823da234
	if (!cr0.eq) goto loc_823DA234;
	// b 0x823da028
	goto loc_823DA028;
loc_823D9F84:
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x823d9f20
	goto loc_823D9F20;
loc_823D9F8C:
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x823da004
	if (cr6.lt) goto loc_823DA004;
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// bgt cr6,0x823da004
	if (cr6.gt) goto loc_823DA004;
	// addi r11,r11,14
	r11.s64 = r11.s64 + 14;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r27
	r11.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// b 0x823d9fe0
	goto loc_823D9FE0;
loc_823D9FB0:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x823da234
	if (cr0.eq) goto loc_823DA234;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_823D9FE0:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823d9fb0
	if (!cr6.eq) goto loc_823D9FB0;
	// b 0x823da234
	goto loc_823DA234;
loc_823D9FF0:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x823da004
	if (cr6.lt) goto loc_823DA004;
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// ble cr6,0x823da030
	if (!cr6.gt) goto loc_823DA030;
loc_823DA004:
	// bl 0x823e1000
	ctx.lr = 0x823DA008;
	sub_823E1000(ctx, base);
	// li r11,22
	r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823DA028;
	sub_823E02A8(ctx, base);
loc_823DA028:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823da238
	goto loc_823DA238;
loc_823DA030:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r27
	r11.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// b 0x823da06c
	goto loc_823DA06C;
loc_823DA03C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x823da234
	if (cr0.eq) goto loc_823DA234;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_823DA06C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823da03c
	if (!cr6.eq) goto loc_823DA03C;
	// b 0x823da234
	goto loc_823DA234;
loc_823DA07C:
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x823da004
	if (cr6.lt) goto loc_823DA004;
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// bgt cr6,0x823da004
	if (cr6.gt) goto loc_823DA004;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// b 0x823d9eec
	goto loc_823D9EEC;
loc_823DA098:
	// cmpwi cr6,r11,112
	cr6.compare<int32_t>(r11.s32, 112, xer);
	// beq cr6,0x823da188
	if (cr6.eq) goto loc_823DA188;
	// cmpwi cr6,r11,119
	cr6.compare<int32_t>(r11.s32, 119, xer);
	// beq cr6,0x823da16c
	if (cr6.eq) goto loc_823DA16C;
	// cmpwi cr6,r11,120
	cr6.compare<int32_t>(r11.s32, 120, xer);
	// beq cr6,0x823da140
	if (cr6.eq) goto loc_823DA140;
	// cmpwi cr6,r11,121
	cr6.compare<int32_t>(r11.s32, 121, xer);
	// beq cr6,0x823da120
	if (cr6.eq) goto loc_823DA120;
	// cmpwi cr6,r11,122
	cr6.compare<int32_t>(r11.s32, 122, xer);
	// bne cr6,0x823da028
	if (!cr6.eq) goto loc_823DA028;
loc_823DA0C0:
	// bl 0x823e0a78
	ctx.lr = 0x823DA0C4;
	sub_823E0A78(ctx, base);
	// bl 0x823e0f88
	ctx.lr = 0x823DA0C8;
	sub_823E0F88(ctx, base);
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r11,29,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x4;
	// xori r11,r11,4
	r11.u64 = r11.u64 ^ 4;
	// lwzx r11,r3,r11
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + r11.u32);
	// b 0x823da110
	goto loc_823DA110;
loc_823DA0E0:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x823da234
	if (cr0.eq) goto loc_823DA234;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_823DA110:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823da0e0
	if (!cr6.eq) goto loc_823DA0E0;
	// b 0x823da234
	goto loc_823DA234;
loc_823DA120:
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x823da004
	if (cr6.lt) goto loc_823DA004;
	// li r10,100
	ctx.r10.s64 = 100;
	// divw r10,r11,r10
	ctx.r10.s32 = r11.s32 / ctx.r10.s32;
	// mulli r10,r10,100
	ctx.r10.s64 = ctx.r10.s64 * 100;
	// subf r3,r10,r11
	ctx.r3.s64 = r11.s64 - ctx.r10.s64;
	// b 0x823d9eec
	goto loc_823D9EEC;
loc_823DA140:
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// beq cr6,0x823da164
	if (cr6.eq) goto loc_823DA164;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x823d9f74
	goto loc_823D9F74;
loc_823DA164:
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x823d9f74
	goto loc_823D9F74;
loc_823DA16C:
	// lwz r3,24(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x823da004
	if (cr6.lt) goto loc_823DA004;
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// bgt cr6,0x823da004
	if (cr6.gt) goto loc_823DA004;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x823d9ef0
	goto loc_823D9EF0;
loc_823DA188:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x823da004
	if (cr6.lt) goto loc_823DA004;
	// cmpwi cr6,r11,23
	cr6.compare<int32_t>(r11.s32, 23, xer);
	// bgt cr6,0x823da004
	if (cr6.gt) goto loc_823DA004;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// bgt cr6,0x823da1f0
	if (cr6.gt) goto loc_823DA1F0;
	// lwz r11,152(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 152);
	// b 0x823da1e4
	goto loc_823DA1E4;
loc_823DA1B0:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x823da234
	if (cr0.eq) goto loc_823DA234;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
loc_823DA1E4:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823da1b0
	if (!cr6.eq) goto loc_823DA1B0;
	// b 0x823da234
	goto loc_823DA234;
loc_823DA1F0:
	// lwz r11,156(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 156);
	// b 0x823da22c
	goto loc_823DA22C;
loc_823DA1F8:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq 0x823da234
	if (cr0.eq) goto loc_823DA234;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r10,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r10.u8);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
loc_823DA22C:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823da1f8
	if (!cr6.eq) goto loc_823DA1F8;
loc_823DA234:
	// li r3,1
	ctx.r3.s64 = 1;
loc_823DA238:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823DA240"))) PPC_WEAK_FUNC(sub_823DA240);
PPC_FUNC_IMPL(__imp__sub_823DA240) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x823DA248;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r22,r5
	r22.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// blt cr6,0x823da27c
	if (cr6.lt) goto loc_823DA27C;
	// beq cr6,0x823da274
	if (cr6.eq) goto loc_823DA274;
	// lwz r31,168(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 168);
	// b 0x823da280
	goto loc_823DA280;
loc_823DA274:
	// lwz r31,164(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 164);
	// b 0x823da280
	goto loc_823DA280;
loc_823DA27C:
	// lwz r31,160(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 160);
loc_823DA280:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// extsb. r9,r11
	ctx.r9.s64 = r11.s8;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x823da734
	if (cr0.eq) goto loc_823DA734;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r24,r10,-12292
	r24.s64 = ctx.r10.s64 + -12292;
	// addi r23,r11,-12300
	r23.s64 = r11.s64 + -12300;
loc_823DA29C:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823da734
	if (cr6.eq) goto loc_823DA734;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// mr r27,r31
	r27.u64 = r31.u64;
loc_823DA2B8:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lbz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// extsb r8,r8
	ctx.r8.s64 = ctx.r8.s8;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x823da2b8
	if (cr6.eq) goto loc_823DA2B8;
	// cmpwi cr6,r9,100
	cr6.compare<int32_t>(ctx.r9.s32, 100, xer);
	// bgt cr6,0x823da488
	if (cr6.gt) goto loc_823DA488;
	// beq cr6,0x823da44c
	if (cr6.eq) goto loc_823DA44C;
	// cmpwi cr6,r9,39
	cr6.compare<int32_t>(ctx.r9.s32, 39, xer);
	// beq cr6,0x823da39c
	if (cr6.eq) goto loc_823DA39C;
	// cmpwi cr6,r9,65
	cr6.compare<int32_t>(ctx.r9.s32, 65, xer);
	// beq cr6,0x823da304
	if (cr6.eq) goto loc_823DA304;
	// cmpwi cr6,r9,72
	cr6.compare<int32_t>(ctx.r9.s32, 72, xer);
	// beq cr6,0x823da35c
	if (cr6.eq) goto loc_823DA35C;
	// cmpwi cr6,r9,77
	cr6.compare<int32_t>(ctx.r9.s32, 77, xer);
	// beq cr6,0x823da320
	if (cr6.eq) goto loc_823DA320;
	// cmpwi cr6,r9,97
	cr6.compare<int32_t>(ctx.r9.s32, 97, xer);
	// bne cr6,0x823da670
	if (!cr6.eq) goto loc_823DA670;
loc_823DA304:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e26f8
	ctx.lr = 0x823DA310;
	sub_823E26F8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823da37c
	if (!cr0.eq) goto loc_823DA37C;
	// addi r27,r31,5
	r27.s64 = r31.s64 + 5;
	// b 0x823da394
	goto loc_823DA394;
loc_823DA320:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x823da350
	if (cr6.eq) goto loc_823DA350;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x823da354
	if (cr6.eq) goto loc_823DA354;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x823da348
	if (cr6.eq) goto loc_823DA348;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x823da670
	if (!cr6.eq) goto loc_823DA670;
	// li r4,66
	ctx.r4.s64 = 66;
	// b 0x823da670
	goto loc_823DA670;
loc_823DA348:
	// li r4,98
	ctx.r4.s64 = 98;
	// b 0x823da670
	goto loc_823DA670;
loc_823DA350:
	// li r28,1
	r28.s64 = 1;
loc_823DA354:
	// li r4,109
	ctx.r4.s64 = 109;
	// b 0x823da670
	goto loc_823DA670;
loc_823DA35C:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x823da370
	if (cr6.eq) goto loc_823DA370;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x823da374
	if (cr6.eq) goto loc_823DA374;
	// b 0x823da670
	goto loc_823DA670;
loc_823DA370:
	// li r28,1
	r28.s64 = 1;
loc_823DA374:
	// li r4,72
	ctx.r4.s64 = 72;
	// b 0x823da670
	goto loc_823DA670;
loc_823DA37C:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e26f8
	ctx.lr = 0x823DA388;
	sub_823E26F8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823da394
	if (!cr0.eq) goto loc_823DA394;
	// addi r27,r31,3
	r27.s64 = r31.s64 + 3;
loc_823DA394:
	// li r4,112
	ctx.r4.s64 = 112;
	// b 0x823da670
	goto loc_823DA670;
loc_823DA39C:
	// clrlwi. r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
	// beq 0x823da728
	if (cr0.eq) goto loc_823DA728;
	// b 0x823da43c
	goto loc_823DA43C;
loc_823DA3AC:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823da728
	if (cr6.eq) goto loc_823DA728;
	// cmpwi cr6,r3,39
	cr6.compare<int32_t>(ctx.r3.s32, 39, xer);
	// beq cr6,0x823da724
	if (cr6.eq) goto loc_823DA724;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x823e26d8
	ctx.lr = 0x823DA3C8;
	sub_823E26D8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823da414
	if (cr0.eq) goto loc_823DA414;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x823da414
	if (!cr6.gt) goto loc_823DA414;
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823da740
	if (cr6.eq) goto loc_823DA740;
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// mr r31,r11
	r31.u64 = r11.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_823DA414:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_823DA43C:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// extsb. r3,r11
	ctx.r3.s64 = r11.s8;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823da3ac
	if (!cr0.eq) goto loc_823DA3AC;
	// b 0x823da728
	goto loc_823DA728;
loc_823DA44C:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x823da47c
	if (cr6.eq) goto loc_823DA47C;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x823da480
	if (cr6.eq) goto loc_823DA480;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x823da474
	if (cr6.eq) goto loc_823DA474;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x823da670
	if (!cr6.eq) goto loc_823DA670;
	// li r4,65
	ctx.r4.s64 = 65;
	// b 0x823da670
	goto loc_823DA670;
loc_823DA474:
	// li r4,97
	ctx.r4.s64 = 97;
	// b 0x823da670
	goto loc_823DA670;
loc_823DA47C:
	// li r28,1
	r28.s64 = 1;
loc_823DA480:
	// li r4,100
	ctx.r4.s64 = 100;
	// b 0x823da670
	goto loc_823DA670;
loc_823DA488:
	// cmpwi cr6,r9,104
	cr6.compare<int32_t>(ctx.r9.s32, 104, xer);
	// beq cr6,0x823da654
	if (cr6.eq) goto loc_823DA654;
	// cmpwi cr6,r9,109
	cr6.compare<int32_t>(ctx.r9.s32, 109, xer);
	// beq cr6,0x823da634
	if (cr6.eq) goto loc_823DA634;
	// cmpwi cr6,r9,115
	cr6.compare<int32_t>(ctx.r9.s32, 115, xer);
	// beq cr6,0x823da614
	if (cr6.eq) goto loc_823DA614;
	// cmpwi cr6,r9,116
	cr6.compare<int32_t>(ctx.r9.s32, 116, xer);
	// beq cr6,0x823da4d0
	if (cr6.eq) goto loc_823DA4D0;
	// cmpwi cr6,r9,121
	cr6.compare<int32_t>(ctx.r9.s32, 121, xer);
	// bne cr6,0x823da670
	if (!cr6.eq) goto loc_823DA670;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x823da4c8
	if (cr6.eq) goto loc_823DA4C8;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x823da670
	if (!cr6.eq) goto loc_823DA670;
	// li r4,89
	ctx.r4.s64 = 89;
	// b 0x823da670
	goto loc_823DA670;
loc_823DA4C8:
	// li r4,121
	ctx.r4.s64 = 121;
	// b 0x823da670
	goto loc_823DA670;
loc_823DA4D0:
	// lwz r9,8(r22)
	ctx.r9.u64 = PPC_LOAD_U32(r22.u32 + 8);
	// cmpwi cr6,r9,11
	cr6.compare<int32_t>(ctx.r9.s32, 11, xer);
	// bgt cr6,0x823da4e4
	if (cr6.gt) goto loc_823DA4E4;
	// lwz r31,152(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 152);
	// b 0x823da4e8
	goto loc_823DA4E8;
loc_823DA4E4:
	// lwz r31,156(r26)
	r31.u64 = PPC_LOAD_U32(r26.u32 + 156);
loc_823DA4E8:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x823da604
	if (!cr6.eq) goto loc_823DA604;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823da604
	if (cr6.eq) goto loc_823DA604;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// extsb r3,r11
	ctx.r3.s64 = r11.s8;
	// bl 0x823e26d8
	ctx.lr = 0x823DA508;
	sub_823E26D8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823da554
	if (cr0.eq) goto loc_823DA554;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x823da554
	if (!cr6.gt) goto loc_823DA554;
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823da740
	if (cr6.eq) goto loc_823DA740;
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// mr r31,r11
	r31.u64 = r11.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_823DA554:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// b 0x823da69c
	goto loc_823DA69C;
loc_823DA57C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x823da69c
	if (!cr6.gt) goto loc_823DA69C;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x823e26d8
	ctx.lr = 0x823DA590;
	sub_823E26D8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823da5dc
	if (cr0.eq) goto loc_823DA5DC;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x823da5dc
	if (!cr6.gt) goto loc_823DA5DC;
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823da740
	if (cr6.eq) goto loc_823DA740;
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// mr r31,r11
	r31.u64 = r11.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_823DA5DC:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_823DA604:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// extsb. r3,r11
	ctx.r3.s64 = r11.s8;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x823da57c
	if (!cr0.eq) goto loc_823DA57C;
	// b 0x823da69c
	goto loc_823DA69C;
loc_823DA614:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x823da628
	if (cr6.eq) goto loc_823DA628;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x823da62c
	if (cr6.eq) goto loc_823DA62C;
	// b 0x823da670
	goto loc_823DA670;
loc_823DA628:
	// li r28,1
	r28.s64 = 1;
loc_823DA62C:
	// li r4,83
	ctx.r4.s64 = 83;
	// b 0x823da670
	goto loc_823DA670;
loc_823DA634:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x823da648
	if (cr6.eq) goto loc_823DA648;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x823da64c
	if (cr6.eq) goto loc_823DA64C;
	// b 0x823da670
	goto loc_823DA670;
loc_823DA648:
	// li r28,1
	r28.s64 = 1;
loc_823DA64C:
	// li r4,77
	ctx.r4.s64 = 77;
	// b 0x823da670
	goto loc_823DA670;
loc_823DA654:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x823da668
	if (cr6.eq) goto loc_823DA668;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x823da66c
	if (cr6.eq) goto loc_823DA66C;
	// b 0x823da670
	goto loc_823DA670;
loc_823DA668:
	// li r28,1
	r28.s64 = 1;
loc_823DA66C:
	// li r4,73
	ctx.r4.s64 = 73;
loc_823DA670:
	// extsb. r11,r4
	r11.s64 = ctx.r4.s8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x823da6a4
	if (cr0.eq) goto loc_823DA6A4;
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x823d9bc0
	ctx.lr = 0x823DA694;
	sub_823D9BC0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823da740
	if (cr0.eq) goto loc_823DA740;
loc_823DA69C:
	// mr r31,r27
	r31.u64 = r27.u64;
	// b 0x823da728
	goto loc_823DA728;
loc_823DA6A4:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// extsb r3,r11
	ctx.r3.s64 = r11.s8;
	// bl 0x823e26d8
	ctx.lr = 0x823DA6B4;
	sub_823E26D8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823da700
	if (cr0.eq) goto loc_823DA700;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x823da700
	if (!cr6.gt) goto loc_823DA700;
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823da740
	if (cr6.eq) goto loc_823DA740;
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// mr r31,r11
	r31.u64 = r11.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_823DA700:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_823DA724:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_823DA728:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// extsb. r9,r11
	ctx.r9.s64 = r11.s8;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x823da29c
	if (!cr0.eq) goto loc_823DA29C;
loc_823DA734:
	// li r3,1
	ctx.r3.s64 = 1;
loc_823DA738:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
loc_823DA740:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823da738
	goto loc_823DA738;
}

__attribute__((alias("__imp__sub_823DA748"))) PPC_WEAK_FUNC(sub_823DA748);
PPC_FUNC_IMPL(__imp__sub_823DA748) {
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
	ctx.lr = 0x823DA750;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r25,0
	r25.s64 = 0;
	// stw r3,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r3.u32);
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r26,r25
	r26.u64 = r25.u64;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823da908
	if (cr6.eq) goto loc_823DA908;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823da908
	if (cr6.eq) goto loc_823DA908;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stb r25,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r25.u8);
	// beq cr6,0x823da908
	if (cr6.eq) goto loc_823DA908;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// addi r30,r11,-18352
	r30.s64 = r11.s64 + -18352;
	// bne cr6,0x823da7a8
	if (!cr6.eq) goto loc_823DA7A8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r29,212(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 212);
	// b 0x823da7ac
	goto loc_823DA7AC;
loc_823DA7A8:
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
loc_823DA7AC:
	// mr r11,r27
	r11.u64 = r27.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// beq cr6,0x823da8e0
	if (cr6.eq) goto loc_823DA8E0;
loc_823DA7BC:
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// extsb. r3,r10
	ctx.r3.s64 = ctx.r10.s8;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823da8a4
	if (cr0.eq) goto loc_823DA8A4;
	// cmpwi cr6,r3,37
	cr6.compare<int32_t>(ctx.r3.s32, 37, xer);
	// beq cr6,0x823da84c
	if (cr6.eq) goto loc_823DA84C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823e26d8
	ctx.lr = 0x823DA7D8;
	sub_823E26D8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823da824
	if (cr0.eq) goto loc_823DA824;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// ble cr6,0x823da824
	if (!cr6.gt) goto loc_823DA824;
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823da8dc
	if (cr6.eq) goto loc_823DA8DC;
	// lwz r10,180(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lbz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// mr r31,r11
	r31.u64 = r11.u64;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r11,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r11.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_823DA824:
	// lwz r10,180(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// lwz r10,180(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r10.u32);
	// b 0x823da898
	goto loc_823DA898;
loc_823DA84C:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x823da8c0
	if (cr6.eq) goto loc_823DA8C0;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,35
	cr6.compare<uint32_t>(r11.u32, 35, xer);
	// bne cr6,0x823da870
	if (!cr6.eq) goto loc_823DA870;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_823DA870:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,180
	ctx.r6.s64 = ctx.r1.s64 + 180;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x823d9bc0
	ctx.lr = 0x823DA88C;
	sub_823D9BC0(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823da8d4
	if (cr0.eq) goto loc_823DA8D4;
loc_823DA898:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823da7bc
	if (!cr6.eq) goto loc_823DA7BC;
loc_823DA8A4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823da8e0
	if (cr6.eq) goto loc_823DA8E0;
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// stb r25,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r25.u8);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// subf r3,r11,r27
	ctx.r3.s64 = r27.s64 - r11.s64;
	// b 0x823da930
	goto loc_823DA930;
loc_823DA8C0:
	// bl 0x823e1000
	ctx.lr = 0x823DA8C4;
	sub_823E1000(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,22
	ctx.r10.s64 = 22;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x823da92c
	goto loc_823DA92C;
loc_823DA8D4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823da8e0
	if (cr6.eq) goto loc_823DA8E0;
loc_823DA8DC:
	// li r26,1
	r26.s64 = 1;
loc_823DA8E0:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// stb r25,0(r24)
	PPC_STORE_U8(r24.u32 + 0, r25.u8);
	// bne cr6,0x823da908
	if (!cr6.eq) goto loc_823DA908;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823da908
	if (!cr6.eq) goto loc_823DA908;
	// bl 0x823e1000
	ctx.lr = 0x823DA8FC;
	sub_823E1000(ctx, base);
	// li r11,34
	r11.s64 = 34;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// b 0x823da92c
	goto loc_823DA92C;
loc_823DA908:
	// bl 0x823e1000
	ctx.lr = 0x823DA90C;
	sub_823E1000(ctx, base);
	// li r11,22
	r11.s64 = 22;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e02a8
	ctx.lr = 0x823DA92C;
	sub_823E02A8(ctx, base);
loc_823DA92C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823DA930:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823DA938"))) PPC_WEAK_FUNC(sub_823DA938);
PPC_FUNC_IMPL(__imp__sub_823DA938) {
	PPC_FUNC_PROLOGUE();
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// b 0x823da748
	sub_823DA748(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823DA944"))) PPC_WEAK_FUNC(sub_823DA944);
PPC_FUNC_IMPL(__imp__sub_823DA944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DA948"))) PPC_WEAK_FUNC(sub_823DA948);
PPC_FUNC_IMPL(__imp__sub_823DA948) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DA94C"))) PPC_WEAK_FUNC(sub_823DA94C);
PPC_FUNC_IMPL(__imp__sub_823DA94C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DA950"))) PPC_WEAK_FUNC(sub_823DA950);
PPC_FUNC_IMPL(__imp__sub_823DA950) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr1{};
	PPCCRRegister cr6{};
	PPCCRRegister cr7{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// std r3,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r3.u64);
	// clrlwi r6,r3,29
	ctx.r6.u64 = ctx.r3.u32 & 0x7;
	// dcbt r0,r4
	// cmplwi r6,0
	cr0.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// subfic r6,r6,8
	xer.ca = ctx.r6.u32 <= 8;
	ctx.r6.s64 = 8 - ctx.r6.s64;
	// beq 0x823da9b4
	if (cr0.eq) goto loc_823DA9B4;
	// cmplw r5,r6
	cr0.compare<uint32_t>(ctx.r5.u32, ctx.r6.u32, xer);
	// ble 0x823da9d0
	if (!cr0.gt) goto loc_823DA9D0;
	// cmplwi r6,4
	cr0.compare<uint32_t>(ctx.r6.u32, 4, xer);
	// beq 0x823da9a0
	if (cr0.eq) goto loc_823DA9A0;
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
loc_823DA988:
	// lbzu r6,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// stbu r6,1(r3)
	ea = 1 + ctx.r3.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r3.u32 = ea;
	// bdnz 0x823da988
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DA988;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// b 0x823da9b4
	goto loc_823DA9B4;
loc_823DA9A0:
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// lwz r6,0(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
loc_823DA9B4:
	// clrlwi r6,r4,29
	ctx.r6.u64 = ctx.r4.u32 & 0x7;
	// cmplwi cr6,r6,4
	cr6.compare<uint32_t>(ctx.r6.u32, 4, xer);
	// cmplwi cr1,r6,0
	cr1.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// cmplwi cr7,r5,128
	cr7.compare<uint32_t>(ctx.r5.u32, 128, xer);
	// beq cr6,0x823dab98
	if (cr6.eq) goto loc_823DAB98;
	// bne cr1,0x823dacc8
	if (!cr1.eq) goto loc_823DACC8;
	// bge cr7,0x823daa6c
	if (!cr7.lt) goto loc_823DAA6C;
loc_823DA9D0:
	// dcbtst r0,r3
	// addi r4,r4,-8
	ctx.r4.s64 = ctx.r4.s64 + -8;
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
loc_823DA9DC:
	// rlwinm r7,r5,29,28,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 29) & 0xF;
	// clrlwi r6,r5,29
	ctx.r6.u64 = ctx.r5.u32 & 0x7;
	// cmplwi cr1,r7,0
	cr1.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr1,0x823daa00
	if (cr1.eq) goto loc_823DAA00;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
loc_823DA9F4:
	// ldu r7,8(r4)
	ea = 8 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U64(ea);
	ctx.r4.u32 = ea;
	// stdu r7,8(r3)
	ea = 8 + ctx.r3.u32;
	PPC_STORE_U64(ea, ctx.r7.u64);
	ctx.r3.u32 = ea;
	// bdnz 0x823da9f4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DA9F4;
loc_823DAA00:
	// cmplwi cr1,r6,4
	cr1.compare<uint32_t>(ctx.r6.u32, 4, xer);
	// beq cr6,0x823daa24
	if (cr6.eq) goto loc_823DAA24;
	// beq cr1,0x823daa2c
	if (cr1.eq) goto loc_823DAA2C;
	// addi r3,r3,7
	ctx.r3.s64 = ctx.r3.s64 + 7;
	// addi r4,r4,7
	ctx.r4.s64 = ctx.r4.s64 + 7;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
loc_823DAA18:
	// lbzu r7,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// stbu r7,1(r3)
	ea = 1 + ctx.r3.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r3.u32 = ea;
	// bdnz 0x823daa18
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DAA18;
loc_823DAA24:
	// ld r3,-8(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_823DAA2C:
	// clrlwi r6,r3,30
	ctx.r6.u64 = ctx.r3.u32 & 0x3;
	// lwz r5,8(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi r6,0
	cr0.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne 0x823daa48
	if (!cr0.eq) goto loc_823DAA48;
	// stw r5,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// ld r3,-8(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_823DAA48:
	// lbz r8,8(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// lbz r7,9(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 9);
	// lbz r6,10(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 10);
	// stb r8,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r8.u8);
	// stb r7,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, ctx.r7.u8);
	// stb r6,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, ctx.r6.u8);
	// stb r5,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r5.u8);
	// ld r3,-8(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_823DAA6C:
	// clrlwi r6,r3,25
	ctx.r6.u64 = ctx.r3.u32 & 0x7F;
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// addi r4,r4,-8
	ctx.r4.s64 = ctx.r4.s64 + -8;
	// cmplwi r6,0
	cr0.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// subfic r6,r6,128
	xer.ca = ctx.r6.u32 <= 128;
	ctx.r6.s64 = 128 - ctx.r6.s64;
	// beq 0x823daa9c
	if (cr0.eq) goto loc_823DAA9C;
	// rlwinm r7,r6,29,3,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 29) & 0x1FFFFFFF;
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
loc_823DAA90:
	// ldu r7,8(r4)
	ea = 8 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U64(ea);
	ctx.r4.u32 = ea;
	// stdu r7,8(r3)
	ea = 8 + ctx.r3.u32;
	PPC_STORE_U64(ea, ctx.r7.u64);
	ctx.r3.u32 = ea;
	// bdnz 0x823daa90
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DAA90;
loc_823DAA9C:
	// rlwinm r6,r5,25,7,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi r6,0
	cr0.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq 0x823da9dc
	if (cr0.eq) goto loc_823DA9DC;
	// addi r10,r5,127
	ctx.r10.s64 = ctx.r5.s64 + 127;
	// clrlwi r8,r5,25
	ctx.r8.u64 = ctx.r5.u32 & 0x7F;
	// rlwinm r10,r10,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr1,r8,0
	cr1.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// li r9,8
	ctx.r9.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_823DAACC:
	// dcbt r9,r4
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// bdnz 0x823daacc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DAACC;
	// add r12,r4,r5
	r12.u64 = ctx.r4.u64 + ctx.r5.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// subf r11,r9,r12
	r11.s64 = r12.s64 - ctx.r9.s64;
	// add r12,r3,r5
	r12.u64 = ctx.r3.u64 + ctx.r5.u64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
loc_823DAAEC:
	// ld r6,8(r4)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r4.u32 + 8);
	// ld r7,16(r4)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r4.u32 + 16);
	// ld r8,24(r4)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r4.u32 + 24);
	// std r6,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r6.u64);
	// ld r6,32(r4)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r4.u32 + 32);
	// std r7,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r7.u64);
	// ld r7,40(r4)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r4.u32 + 40);
	// std r8,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r8.u64);
	// ld r8,48(r4)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r4.u32 + 48);
	// std r6,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, ctx.r6.u64);
	// ld r6,56(r4)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r4.u32 + 56);
	// std r7,40(r3)
	PPC_STORE_U64(ctx.r3.u32 + 40, ctx.r7.u64);
	// ld r7,64(r4)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r4.u32 + 64);
	// std r8,48(r3)
	PPC_STORE_U64(ctx.r3.u32 + 48, ctx.r8.u64);
	// ld r8,72(r4)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r4.u32 + 72);
	// std r6,56(r3)
	PPC_STORE_U64(ctx.r3.u32 + 56, ctx.r6.u64);
	// ld r6,80(r4)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r4.u32 + 80);
	// std r7,64(r3)
	PPC_STORE_U64(ctx.r3.u32 + 64, ctx.r7.u64);
	// ld r7,88(r4)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r4.u32 + 88);
	// std r8,72(r3)
	PPC_STORE_U64(ctx.r3.u32 + 72, ctx.r8.u64);
	// ld r8,96(r4)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r4.u32 + 96);
	// std r6,80(r3)
	PPC_STORE_U64(ctx.r3.u32 + 80, ctx.r6.u64);
	// ld r6,104(r4)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r4.u32 + 104);
	// std r7,88(r3)
	PPC_STORE_U64(ctx.r3.u32 + 88, ctx.r7.u64);
	// ld r7,112(r4)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r4.u32 + 112);
	// std r8,96(r3)
	PPC_STORE_U64(ctx.r3.u32 + 96, ctx.r8.u64);
	// ld r8,120(r4)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r4.u32 + 120);
	// std r6,104(r3)
	PPC_STORE_U64(ctx.r3.u32 + 104, ctx.r6.u64);
	// ldu r6,128(r4)
	ea = 128 + ctx.r4.u32;
	ctx.r6.u64 = PPC_LOAD_U64(ea);
	ctx.r4.u32 = ea;
	// std r7,112(r3)
	PPC_STORE_U64(ctx.r3.u32 + 112, ctx.r7.u64);
	// std r8,120(r3)
	PPC_STORE_U64(ctx.r3.u32 + 120, ctx.r8.u64);
	// stdu r6,128(r3)
	ea = 128 + ctx.r3.u32;
	PPC_STORE_U64(ea, ctx.r6.u64);
	ctx.r3.u32 = ea;
	// cmplw r4,r11
	cr0.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bge 0x823dab80
	if (!cr0.lt) goto loc_823DAB80;
	// dcbt r9,r4
	// bdnz 0x823daaec
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DAAEC;
	// b 0x823da9dc
	goto loc_823DA9DC;
loc_823DAB80:
	// beq cr1,0x823dab90
	if (cr1.eq) goto loc_823DAB90;
	// li r8,-1
	ctx.r8.s64 = -1;
	// dcbtst r8,r12
	// cmplwi cr1,r8,0
	cr1.compare<uint32_t>(ctx.r8.u32, 0, xer);
loc_823DAB90:
	// bdnz 0x823daaec
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DAAEC;
	// b 0x823da9dc
	goto loc_823DA9DC;
loc_823DAB98:
	// addi r4,r4,-4
	ctx.r4.s64 = ctx.r4.s64 + -4;
	// bge cr7,0x823dabf0
	if (!cr7.lt) goto loc_823DABF0;
	// dcbtst r0,r3
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
loc_823DABA8:
	// rlwinm r7,r5,30,27,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x1F;
	// clrlwi r6,r5,30
	ctx.r6.u64 = ctx.r5.u32 & 0x3;
	// cmplwi cr1,r7,0
	cr1.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr1,0x823dabcc
	if (cr1.eq) goto loc_823DABCC;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
loc_823DABC0:
	// lwzu r7,4(r4)
	ea = 4 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r4.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// bdnz 0x823dabc0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DABC0;
loc_823DABCC:
	// beq cr6,0x823dabe8
	if (cr6.eq) goto loc_823DABE8;
	// addi r3,r3,3
	ctx.r3.s64 = ctx.r3.s64 + 3;
	// addi r4,r4,3
	ctx.r4.s64 = ctx.r4.s64 + 3;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
loc_823DABDC:
	// lbzu r7,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// stbu r7,1(r3)
	ea = 1 + ctx.r3.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r3.u32 = ea;
	// bdnz 0x823dabdc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DABDC;
loc_823DABE8:
	// ld r3,-8(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_823DABF0:
	// clrlwi r6,r3,25
	ctx.r6.u64 = ctx.r3.u32 & 0x7F;
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// cmplwi r6,0
	cr0.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// subfic r6,r6,128
	xer.ca = ctx.r6.u32 <= 128;
	ctx.r6.s64 = 128 - ctx.r6.s64;
	// beq 0x823dac1c
	if (cr0.eq) goto loc_823DAC1C;
	// rlwinm r7,r6,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
loc_823DAC10:
	// lwzu r7,4(r4)
	ea = 4 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r4.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// bdnz 0x823dac10
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DAC10;
loc_823DAC1C:
	// rlwinm r6,r5,25,7,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi r6,0
	cr0.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq 0x823daba8
	if (cr0.eq) goto loc_823DABA8;
	// addi r10,r5,127
	ctx.r10.s64 = ctx.r5.s64 + 127;
	// clrlwi r8,r5,25
	ctx.r8.u64 = ctx.r5.u32 & 0x7F;
	// rlwinm r10,r10,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr1,r8,0
	cr1.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// li r9,4
	ctx.r9.s64 = 4;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_823DAC4C:
	// dcbt r9,r4
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// bdnz 0x823dac4c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DAC4C;
	// add r12,r4,r5
	r12.u64 = ctx.r4.u64 + ctx.r5.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// subf r11,r9,r12
	r11.s64 = r12.s64 - ctx.r9.s64;
	// add r12,r3,r5
	r12.u64 = ctx.r3.u64 + ctx.r5.u64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
loc_823DAC6C:
	// li r6,8
	ctx.r6.s64 = 8;
loc_823DAC70:
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// lwz r0,4(r4)
	r0.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r7,8(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r8,12(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmplwi r6,0
	cr0.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r0,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r0.u32);
	// lwzu r0,16(r4)
	ea = 16 + ctx.r4.u32;
	r0.u64 = PPC_LOAD_U32(ea);
	ctx.r4.u32 = ea;
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// stw r8,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
	// stwu r0,16(r3)
	ea = 16 + ctx.r3.u32;
	PPC_STORE_U32(ea, r0.u32);
	ctx.r3.u32 = ea;
	// bne 0x823dac70
	if (!cr0.eq) goto loc_823DAC70;
	// cmplw r4,r11
	cr0.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bge 0x823dacb0
	if (!cr0.lt) goto loc_823DACB0;
	// dcbt r9,r4
	// bdnz 0x823dac6c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DAC6C;
	// b 0x823daba8
	goto loc_823DABA8;
loc_823DACB0:
	// beq cr1,0x823dacc0
	if (cr1.eq) goto loc_823DACC0;
	// li r8,-1
	ctx.r8.s64 = -1;
	// dcbtst r8,r12
	// cmplwi cr1,r8,0
	cr1.compare<uint32_t>(ctx.r8.u32, 0, xer);
loc_823DACC0:
	// bdnz 0x823dac6c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DAC6C;
	// b 0x823daba8
	goto loc_823DABA8;
loc_823DACC8:
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// bge cr7,0x823dacfc
	if (!cr7.lt) goto loc_823DACFC;
	// dcbtst r0,r3
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
loc_823DACD8:
	// clrlwi r6,r5,25
	ctx.r6.u64 = ctx.r5.u32 & 0x7F;
	// cmplwi r6,0
	cr0.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// beq 0x823dacf4
	if (cr0.eq) goto loc_823DACF4;
loc_823DACE8:
	// lbzu r6,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// stbu r6,1(r3)
	ea = 1 + ctx.r3.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r3.u32 = ea;
	// bdnz 0x823dace8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DACE8;
loc_823DACF4:
	// ld r3,-8(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_823DACFC:
	// clrlwi r6,r3,25
	ctx.r6.u64 = ctx.r3.u32 & 0x7F;
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
	// cmplwi r6,0
	cr0.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// subfic r6,r6,128
	xer.ca = ctx.r6.u32 <= 128;
	ctx.r6.s64 = 128 - ctx.r6.s64;
	// beq 0x823dad24
	if (cr0.eq) goto loc_823DAD24;
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
loc_823DAD18:
	// lbzu r6,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// stbu r6,1(r3)
	ea = 1 + ctx.r3.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r3.u32 = ea;
	// bdnz 0x823dad18
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DAD18;
loc_823DAD24:
	// rlwinm r6,r5,25,7,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi r6,0
	cr0.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq 0x823dacd8
	if (cr0.eq) goto loc_823DACD8;
	// addi r10,r5,127
	ctx.r10.s64 = ctx.r5.s64 + 127;
	// clrlwi r8,r5,25
	ctx.r8.u64 = ctx.r5.u32 & 0x7F;
	// rlwinm r10,r10,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr1,r8,0
	cr1.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_823DAD54:
	// dcbt r9,r4
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// bdnz 0x823dad54
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DAD54;
	// add r12,r4,r5
	r12.u64 = ctx.r4.u64 + ctx.r5.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// subf r11,r9,r12
	r11.s64 = r12.s64 - ctx.r9.s64;
	// add r12,r3,r5
	r12.u64 = ctx.r3.u64 + ctx.r5.u64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
loc_823DAD74:
	// li r6,32
	ctx.r6.s64 = 32;
loc_823DAD78:
	// lbz r7,4(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// lbz r8,3(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// rlwimi r7,r8,8,16,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r7.u64 & 0xFFFFFFFFFFFF00FF);
	// lbz r9,2(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// cmplwi r6,0
	cr0.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// rlwimi r7,r9,16,8,15
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r9.u32, 16) & 0xFF0000) | (ctx.r7.u64 & 0xFFFFFFFFFF00FFFF);
	// lbz r10,1(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// rlwimi r7,r10,24,0,7
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r10.u32, 24) & 0xFF000000) | (ctx.r7.u64 & 0xFFFFFFFF00FFFFFF);
	// stw r7,1(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1, ctx.r7.u32);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// bne 0x823dad78
	if (!cr0.eq) goto loc_823DAD78;
	// cmplw r4,r11
	cr0.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bge 0x823dadc0
	if (!cr0.lt) goto loc_823DADC0;
	// dcbt r9,r4
	// bdnz 0x823dad74
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DAD74;
	// b 0x823dacd8
	goto loc_823DACD8;
loc_823DADC0:
	// beq cr1,0x823dadd0
	if (cr1.eq) goto loc_823DADD0;
	// li r8,-1
	ctx.r8.s64 = -1;
	// dcbtst r8,r12
	// cmplwi cr1,r8,0
	cr1.compare<uint32_t>(ctx.r8.u32, 0, xer);
loc_823DADD0:
	// bdnz 0x823dad74
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DAD74;
	// b 0x823dacd8
	goto loc_823DACD8;
}

__attribute__((alias("__imp__sub_823DADD8"))) PPC_WEAK_FUNC(sub_823DADD8);
PPC_FUNC_IMPL(__imp__sub_823DADD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r0{};
	// addi r0,r5,1
	r0.s64 = ctx.r5.s64 + 1;
	// ori r6,r3,0
	ctx.r6.u64 = ctx.r3.u64 | 0;
	// mtctr r0
	ctr.u64 = r0.u64;
	// b 0x823dadfc
	goto loc_823DADFC;
loc_823DADE8:
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// lbz r0,0(r4)
	r0.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// stb r0,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, r0.u8);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
loc_823DADFC:
	// andi. r0,r6,3
	r0.u64 = ctx.r6.u64 & 3;
	cr0.compare<int32_t>(r0.s32, 0, xer);
	// bdnzf eq,0x823dade8
	--ctr.u64;
	if (ctr.u32 != 0 && !cr0.eq) goto loc_823DADE8;
	// rlwinm. r0,r5,30,2,31
	r0.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	cr0.compare<int32_t>(r0.s32, 0, xer);
	// beq- 0x823dae2c
	if (cr0.eq) goto loc_823DAE2C;
	// mtctr r0
	ctr.u64 = r0.u64;
	// andi. r0,r4,3
	r0.u64 = ctx.r4.u64 & 3;
	cr0.compare<int32_t>(r0.s32, 0, xer);
	// bne- 0x823dae50
	if (!cr0.eq) goto loc_823DAE50;
loc_823DAE18:
	// lwz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// stw r7,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r7.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bdnz+ 0x823dae18
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DAE18;
loc_823DAE2C:
	// andi. r0,r5,3
	r0.u64 = ctx.r5.u64 & 3;
	cr0.compare<int32_t>(r0.s32, 0, xer);
	// mtctr r0
	ctr.u64 = r0.u64;
	// beqlr+ 
	if (cr0.eq) return;
loc_823DAE38:
	// lbz r0,0(r4)
	r0.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// stb r0,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, r0.u8);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// bdnz+ 0x823dae38
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DAE38;
	// blr 
	return;
loc_823DAE50:
	// lbz r7,3(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// lbz r8,2(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// rlwimi r7,r8,8,16,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r7.u64 & 0xFFFFFFFFFFFF00FF);
	// lbz r9,1(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// rlwimi r7,r9,16,8,15
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r9.u32, 16) & 0xFF0000) | (ctx.r7.u64 & 0xFFFFFFFFFF00FFFF);
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwimi r7,r10,24,0,7
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r10.u32, 24) & 0xFF000000) | (ctx.r7.u64 & 0xFFFFFFFF00FFFFFF);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// stw r7,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r7.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bdnz 0x823dae50
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DAE50;
	// b 0x823dae2c
	goto loc_823DAE2C;
}

__attribute__((alias("__imp__sub_823DAE80"))) PPC_WEAK_FUNC(sub_823DAE80);
PPC_FUNC_IMPL(__imp__sub_823DAE80) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x823e2788
	ctx.lr = 0x823DAE98;
	sub_823E2788(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e2740
	ctx.lr = 0x823DAEA0;
	sub_823E2740(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r3,255
	ctx.r3.s64 = 255;
	// lwz r11,-20544(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -20544);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823DAEB4;
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

__attribute__((alias("__imp__sub_823DAEC8"))) PPC_WEAK_FUNC(sub_823DAEC8);
PPC_FUNC_IMPL(__imp__sub_823DAEC8) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x827bd4b4
	__imp__KeBugCheck(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823DAED0"))) PPC_WEAK_FUNC(sub_823DAED0);
PPC_FUNC_IMPL(__imp__sub_823DAED0) {
	PPC_FUNC_PROLOGUE();
	// li r3,8
	ctx.r3.s64 = 8;
	// b 0x823e2a08
	sub_823E2A08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823DAED8"))) PPC_WEAK_FUNC(sub_823DAED8);
PPC_FUNC_IMPL(__imp__sub_823DAED8) {
	PPC_FUNC_PROLOGUE();
	// li r3,8
	ctx.r3.s64 = 8;
	// b 0x823e28a8
	sub_823E28A8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823DAEE0"))) PPC_WEAK_FUNC(sub_823DAEE0);
PPC_FUNC_IMPL(__imp__sub_823DAEE0) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// b 0x823daf18
	goto loc_823DAF18;
loc_823DAF00:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823daf14
	if (cr6.eq) goto loc_823DAF14;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823DAF14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823DAF14:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
loc_823DAF18:
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// blt cr6,0x823daf00
	if (cr6.lt) goto loc_823DAF00;
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

__attribute__((alias("__imp__sub_823DAF38"))) PPC_WEAK_FUNC(sub_823DAF38);
PPC_FUNC_IMPL(__imp__sub_823DAF38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// lwz r19,-12540(r27)
	r19.u64 = PPC_LOAD_U32(r27.u32 + -12540);
	// lwz r16,9512(r16)
	r16.u64 = PPC_LOAD_U32(r16.u32 + 9512);
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x823DAF48;
	// addi r31,r1,-128
	r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// stw r28,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r28.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x823e2a08
	ctx.lr = 0x823DAF64;
	sub_823E2A08(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-10680(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10680);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x823db018
	if (cr6.eq) goto loc_823DB018;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lwz r11,-10684(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10684);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x823daf90
	if (!cr6.eq) goto loc_823DAF90;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x827bd4b4
	ctx.lr = 0x823DAF90;
	__imp__KeBugCheck(ctx, base);
loc_823DAF90:
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// li r11,1
	r11.s64 = 1;
	// stw r11,-10684(r9)
	PPC_STORE_U32(ctx.r9.u32 + -10684, r11.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// stb r28,-10688(r8)
	PPC_STORE_U8(ctx.r8.u32 + -10688, r28.u8);
	// bne cr6,0x823db004
	if (!cr6.eq) goto loc_823DB004;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// lwz r30,-22836(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -22836);
	// lwz r29,-22832(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22832);
	// cmplwi r29,0
	cr0.compare<uint32_t>(r29.u32, 0, xer);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// beq 0x823daff0
	if (cr0.eq) goto loc_823DAFF0;
loc_823DAFC4:
	// addi r30,r30,-4
	r30.s64 = r30.s64 + -4;
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// blt cr6,0x823daff0
	if (cr6.lt) goto loc_823DAFF0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823dafe8
	if (cr6.eq) goto loc_823DAFE8;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823DAFE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823DAFE8:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x823dafc4
	goto loc_823DAFC4;
loc_823DAFF0:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r4,r11,5124
	ctx.r4.s64 = r11.s64 + 5124;
	// addi r3,r10,5116
	ctx.r3.s64 = ctx.r10.s64 + 5116;
	// bl 0x823daee0
	ctx.lr = 0x823DB004;
	sub_823DAEE0(ctx, base);
loc_823DB004:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r4,r11,5132
	ctx.r4.s64 = r11.s64 + 5132;
	// addi r3,r10,5128
	ctx.r3.s64 = ctx.r10.s64 + 5128;
	// bl 0x823daee0
	ctx.lr = 0x823DB018;
	sub_823DAEE0(ctx, base);
loc_823DB018:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,128
	r12.s64 = r31.s64 + 128;
	// bl 0x823db060
	ctx.lr = 0x823DB024;
	sub_823DB060(ctx, base);
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823db038
	if (!cr6.eq) goto loc_823DB038;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x827bd4b4
	ctx.lr = 0x823DB038;
	__imp__KeBugCheck(ctx, base);
loc_823DB038:
	// addi r1,r31,128
	ctx.r1.s64 = r31.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823DAF40"))) PPC_WEAK_FUNC(sub_823DAF40);
PPC_FUNC_IMPL(__imp__sub_823DAF40) {
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
	ctx.lr = 0x823DAF48;
	// addi r31,r1,-128
	r31.s64 = ctx.r1.s64 + -128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// stw r28,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r28.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x823e2a08
	ctx.lr = 0x823DAF64;
	sub_823E2A08(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-10680(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10680);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x823db018
	if (cr6.eq) goto loc_823DB018;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lwz r11,-10684(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10684);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x823daf90
	if (!cr6.eq) goto loc_823DAF90;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x827bd4b4
	ctx.lr = 0x823DAF90;
	__imp__KeBugCheck(ctx, base);
loc_823DAF90:
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// li r11,1
	r11.s64 = 1;
	// stw r11,-10684(r9)
	PPC_STORE_U32(ctx.r9.u32 + -10684, r11.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// stb r28,-10688(r8)
	PPC_STORE_U8(ctx.r8.u32 + -10688, r28.u8);
	// bne cr6,0x823db004
	if (!cr6.eq) goto loc_823DB004;
	// lis r11,-32107
	r11.s64 = -2104164352;
	// lis r10,-32107
	ctx.r10.s64 = -2104164352;
	// lwz r30,-22836(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -22836);
	// lwz r29,-22832(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -22832);
	// cmplwi r29,0
	cr0.compare<uint32_t>(r29.u32, 0, xer);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// beq 0x823daff0
	if (cr0.eq) goto loc_823DAFF0;
loc_823DAFC4:
	// addi r30,r30,-4
	r30.s64 = r30.s64 + -4;
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// blt cr6,0x823daff0
	if (cr6.lt) goto loc_823DAFF0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823dafe8
	if (cr6.eq) goto loc_823DAFE8;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823DAFE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823DAFE8:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x823dafc4
	goto loc_823DAFC4;
loc_823DAFF0:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r4,r11,5124
	ctx.r4.s64 = r11.s64 + 5124;
	// addi r3,r10,5116
	ctx.r3.s64 = ctx.r10.s64 + 5116;
	// bl 0x823daee0
	ctx.lr = 0x823DB004;
	sub_823DAEE0(ctx, base);
loc_823DB004:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r4,r11,5132
	ctx.r4.s64 = r11.s64 + 5132;
	// addi r3,r10,5128
	ctx.r3.s64 = ctx.r10.s64 + 5128;
	// bl 0x823daee0
	ctx.lr = 0x823DB018;
	sub_823DAEE0(ctx, base);
loc_823DB018:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,128
	r12.s64 = r31.s64 + 128;
	// bl 0x823db060
	ctx.lr = 0x823DB024;
	sub_823DB060(ctx, base);
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823db038
	if (!cr6.eq) goto loc_823DB038;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x827bd4b4
	ctx.lr = 0x823DB038;
	__imp__KeBugCheck(ctx, base);
loc_823DB038:
	// addi r1,r31,128
	ctx.r1.s64 = r31.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823DB040"))) PPC_WEAK_FUNC(sub_823DB040);
PPC_FUNC_IMPL(__imp__sub_823DB040) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-128
	r31.s64 = r12.s64 + -128;
	// std r28,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r28.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r28,164(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// b 0x823db078
	goto loc_823DB078;
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-128
	r31.s64 = r12.s64 + -128;
	// std r28,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r28.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_823DB078:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x823db088
	if (cr6.eq) goto loc_823DB088;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x823e28a8
	ctx.lr = 0x823DB088;
	sub_823E28A8(ctx, base);
loc_823DB088:
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r28,-16(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DB060"))) PPC_WEAK_FUNC(sub_823DB060);
PPC_FUNC_IMPL(__imp__sub_823DB060) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r31,r12,-128
	r31.s64 = r12.s64 + -128;
	// std r28,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r28.u64);
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x823db088
	if (cr6.eq) goto loc_823DB088;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x823e28a8
	ctx.lr = 0x823DB088;
	sub_823E28A8(ctx, base);
loc_823DB088:
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r28,-16(r1)
	r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DB0A0"))) PPC_WEAK_FUNC(sub_823DB0A0);
PPC_FUNC_IMPL(__imp__sub_823DB0A0) {
	PPC_FUNC_PROLOGUE();
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x823daf40
	sub_823DAF40(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823DB0AC"))) PPC_WEAK_FUNC(sub_823DB0AC);
PPC_FUNC_IMPL(__imp__sub_823DB0AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DB0B0"))) PPC_WEAK_FUNC(sub_823DB0B0);
PPC_FUNC_IMPL(__imp__sub_823DB0B0) {
	PPC_FUNC_PROLOGUE();
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x823daf40
	sub_823DAF40(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823DB0BC"))) PPC_WEAK_FUNC(sub_823DB0BC);
PPC_FUNC_IMPL(__imp__sub_823DB0BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DB0C0"))) PPC_WEAK_FUNC(sub_823DB0C0);
PPC_FUNC_IMPL(__imp__sub_823DB0C0) {
	PPC_FUNC_PROLOGUE();
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823daf40
	sub_823DAF40(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823DB0D0"))) PPC_WEAK_FUNC(sub_823DB0D0);
PPC_FUNC_IMPL(__imp__sub_823DB0D0) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e2be0
	ctx.lr = 0x823DB0E4;
	sub_823E2BE0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e2af0
	ctx.lr = 0x823DB0EC;
	sub_823E2AF0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e0298
	ctx.lr = 0x823DB0F4;
	sub_823E0298(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e2ae0
	ctx.lr = 0x823DB0FC;
	sub_823E2AE0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82130000
	ctx.lr = 0x823DB104;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823e2ac8
	ctx.lr = 0x823DB10C;
	sub_823E2AC8(ctx, base);
	// lis r11,-32194
	r11.s64 = -2109865984;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// addi r11,r11,-20304
	r11.s64 = r11.s64 + -20304;
	// stw r11,-20544(r10)
	PPC_STORE_U32(ctx.r10.u32 + -20544, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DB12C"))) PPC_WEAK_FUNC(sub_823DB12C);
PPC_FUNC_IMPL(__imp__sub_823DB12C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DB130"))) PPC_WEAK_FUNC(sub_823DB130);
PPC_FUNC_IMPL(__imp__sub_823DB130) {
	PPC_FUNC_PROLOGUE();
	// b 0x827bd4c4
	__imp__KeTlsAlloc(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823DB134"))) PPC_WEAK_FUNC(sub_823DB134);
PPC_FUNC_IMPL(__imp__sub_823DB134) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DB138"))) PPC_WEAK_FUNC(sub_823DB138);
PPC_FUNC_IMPL(__imp__sub_823DB138) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// lis r30,-32129
	r30.s64 = -2105606144;
	// lwz r3,-20536(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -20536);
	// bl 0x827bd4d4
	ctx.lr = 0x823DB158;
	__imp__KeTlsGetValue(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x823db174
	if (!cr0.eq) goto loc_823DB174;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,-20536(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -20536);
	// lwz r4,-10660(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -10660);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x827bd4e4
	ctx.lr = 0x823DB174;
	__imp__KeTlsSetValue(ctx, base);
loc_823DB174:
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

__attribute__((alias("__imp__sub_823DB190"))) PPC_WEAK_FUNC(sub_823DB190);
PPC_FUNC_IMPL(__imp__sub_823DB190) {
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
	// lis r31,-32129
	r31.s64 = -2105606144;
	// li r30,-1
	r30.s64 = -1;
	// lwz r3,-20540(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -20540);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823db1d0
	if (cr6.eq) goto loc_823DB1D0;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-10652(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10652);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823DB1C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r11,r30
	r11.u64 = r30.u64;
	// stw r11,-20540(r31)
	PPC_STORE_U32(r31.u32 + -20540, r11.u32);
loc_823DB1D0:
	// lis r31,-32129
	r31.s64 = -2105606144;
	// lwz r3,-20536(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -20536);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823db1ec
	if (cr6.eq) goto loc_823DB1EC;
	// bl 0x827bd4f4
	ctx.lr = 0x823DB1E4;
	__imp__KeTlsFree(ctx, base);
	// mr r11,r30
	r11.u64 = r30.u64;
	// stw r11,-20536(r31)
	PPC_STORE_U32(r31.u32 + -20536, r11.u32);
loc_823DB1EC:
	// bl 0x823e2838
	ctx.lr = 0x823DB1F0;
	sub_823E2838(ctx, base);
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

__attribute__((alias("__imp__sub_823DB208"))) PPC_WEAK_FUNC(sub_823DB208);
PPC_FUNC_IMPL(__imp__sub_823DB208) {
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
	ctx.lr = 0x823DB210;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82135db0
	ctx.lr = 0x823DB218;
	sub_82135DB0(ctx, base);
	// lis r30,-32129
	r30.s64 = -2105606144;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r31,-20540(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -20540);
	// bl 0x823db138
	ctx.lr = 0x823DB228;
	sub_823DB138(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823DB238;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x823db2d4
	if (!cr0.eq) goto loc_823DB2D4;
	// lis r29,-32115
	r29.s64 = -2104688640;
	// lwz r3,-20540(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -20540);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,-10656(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10656);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823DB258;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823db2e0
	if (cr0.eq) goto loc_823DB2E0;
	// li r4,196
	ctx.r4.s64 = 196;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823e24c8
	ctx.lr = 0x823DB26C;
	sub_823E24C8(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// lwz r3,-20540(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -20540);
	// lwz r11,-10656(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10656);
	// beq 0x823db2c4
	if (cr0.eq) goto loc_823DB2C4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823DB288;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823db2b8
	if (cr0.eq) goto loc_823DB2B8;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r11,-17872
	r11.s64 = r11.s64 + -17872;
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// bl 0x8244fec8
	ctx.lr = 0x823DB2A8;
	sub_8244FEC8(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// b 0x823db2e0
	goto loc_823DB2E0;
loc_823DB2B8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e2c38
	ctx.lr = 0x823DB2C0;
	sub_823E2C38(ctx, base);
	// b 0x823db2dc
	goto loc_823DB2DC;
loc_823DB2C4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823DB2D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x823db2e0
	goto loc_823DB2E0;
loc_823DB2D4:
	// cmplwi cr6,r31,1
	cr6.compare<uint32_t>(r31.u32, 1, xer);
	// bne cr6,0x823db2e0
	if (!cr6.eq) goto loc_823DB2E0;
loc_823DB2DC:
	// li r31,0
	r31.s64 = 0;
loc_823DB2E0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82135d38
	ctx.lr = 0x823DB2E8;
	sub_82135D38(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823DB2F4"))) PPC_WEAK_FUNC(sub_823DB2F4);
PPC_FUNC_IMPL(__imp__sub_823DB2F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DB2F8"))) PPC_WEAK_FUNC(sub_823DB2F8);
PPC_FUNC_IMPL(__imp__sub_823DB2F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// bl 0x823db208
	ctx.lr = 0x823DB30C;
	sub_823DB208(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x823db31c
	if (!cr0.eq) goto loc_823DB31C;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x823dae80
	ctx.lr = 0x823DB31C;
	sub_823DAE80(ctx, base);
loc_823DB31C:
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

__attribute__((alias("__imp__sub_823DB334"))) PPC_WEAK_FUNC(sub_823DB334);
PPC_FUNC_IMPL(__imp__sub_823DB334) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DB338"))) PPC_WEAK_FUNC(sub_823DB338);
PPC_FUNC_IMPL(__imp__sub_823DB338) {
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
	// beq cr6,0x823db3d4
	if (cr6.eq) goto loc_823DB3D4;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823db364
	if (cr6.eq) goto loc_823DB364;
	// bl 0x823e2c38
	ctx.lr = 0x823DB364;
	sub_823E2C38(ctx, base);
loc_823DB364:
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823db374
	if (cr6.eq) goto loc_823DB374;
	// bl 0x823e2c38
	ctx.lr = 0x823DB374;
	sub_823E2C38(ctx, base);
loc_823DB374:
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823db384
	if (cr6.eq) goto loc_823DB384;
	// bl 0x823e2c38
	ctx.lr = 0x823DB384;
	sub_823E2C38(ctx, base);
loc_823DB384:
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823db394
	if (cr6.eq) goto loc_823DB394;
	// bl 0x823e2c38
	ctx.lr = 0x823DB394;
	sub_823E2C38(ctx, base);
loc_823DB394:
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823db3a4
	if (cr6.eq) goto loc_823DB3A4;
	// bl 0x823e2c38
	ctx.lr = 0x823DB3A4;
	sub_823E2C38(ctx, base);
loc_823DB3A4:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823db3b4
	if (cr6.eq) goto loc_823DB3B4;
	// bl 0x823e2c38
	ctx.lr = 0x823DB3B4;
	sub_823E2C38(ctx, base);
loc_823DB3B4:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r11,r11,-17872
	r11.s64 = r11.s64 + -17872;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// beq cr6,0x823db3cc
	if (cr6.eq) goto loc_823DB3CC;
	// bl 0x823e2c38
	ctx.lr = 0x823DB3CC;
	sub_823E2C38(ctx, base);
loc_823DB3CC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823e2c38
	ctx.lr = 0x823DB3D4;
	sub_823E2C38(ctx, base);
loc_823DB3D4:
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

__attribute__((alias("__imp__sub_823DB3E8"))) PPC_WEAK_FUNC(sub_823DB3E8);
PPC_FUNC_IMPL(__imp__sub_823DB3E8) {
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
	ctx.lr = 0x823DB3F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32129
	r30.s64 = -2105606144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r29,-32129
	r29.s64 = -2105606144;
	// lwz r11,-20540(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -20540);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x823db464
	if (cr6.eq) goto loc_823DB464;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823db444
	if (!cr6.eq) goto loc_823DB444;
	// lwz r3,-20536(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -20536);
	// bl 0x827bd4d4
	ctx.lr = 0x823DB41C;
	__imp__KeTlsGetValue(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x823db444
	if (cr0.eq) goto loc_823DB444;
	// lwz r3,-20536(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -20536);
	// lwz r31,-20540(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -20540);
	// bl 0x827bd4d4
	ctx.lr = 0x823DB430;
	__imp__KeTlsGetValue(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823DB440;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_823DB444:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,-20540(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -20540);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10656(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10656);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823DB45C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823db338
	ctx.lr = 0x823DB464;
	sub_823DB338(ctx, base);
loc_823DB464:
	// lwz r3,-20536(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -20536);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x823db478
	if (cr6.eq) goto loc_823DB478;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bd4e4
	ctx.lr = 0x823DB478;
	__imp__KeTlsSetValue(ctx, base);
loc_823DB478:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823DB480"))) PPC_WEAK_FUNC(sub_823DB480);
PPC_FUNC_IMPL(__imp__sub_823DB480) {
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
	ctx.lr = 0x823DB488;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32115
	r30.s64 = -2104688640;
	// lis r11,-32194
	r11.s64 = -2109865984;
	// lis r8,-32132
	ctx.r8.s64 = -2105802752;
	// addi r11,r11,-20176
	r11.s64 = r11.s64 + -20176;
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// lis r31,-32115
	r31.s64 = -2104688640;
	// stw r11,-10664(r30)
	PPC_STORE_U32(r30.u32 + -10664, r11.u32);
	// lis r29,-32115
	r29.s64 = -2104688640;
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// lis r9,-32132
	ctx.r9.s64 = -2105802752;
	// addi r10,r10,-11052
	ctx.r10.s64 = ctx.r10.s64 + -11052;
	// addi r9,r9,-11036
	ctx.r9.s64 = ctx.r9.s64 + -11036;
	// addi r11,r8,-11020
	r11.s64 = ctx.r8.s64 + -11020;
	// stw r10,-10660(r31)
	PPC_STORE_U32(r31.u32 + -10660, ctx.r10.u32);
	// stw r9,-10656(r29)
	PPC_STORE_U32(r29.u32 + -10656, ctx.r9.u32);
	// stw r11,-10652(r7)
	PPC_STORE_U32(ctx.r7.u32 + -10652, r11.u32);
	// bl 0x827bd4c4
	ctx.lr = 0x823DB4D0;
	__imp__KeTlsAlloc(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// stw r3,-20536(r11)
	PPC_STORE_U32(r11.u32 + -20536, ctx.r3.u32);
	// beq cr6,0x823db5a4
	if (cr6.eq) goto loc_823DB5A4;
	// lwz r4,-10660(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -10660);
	// bl 0x827bd4e4
	ctx.lr = 0x823DB4E8;
	__imp__KeTlsSetValue(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823db5a4
	if (cr0.eq) goto loc_823DB5A4;
	// bl 0x823db0d0
	ctx.lr = 0x823DB4F4;
	sub_823DB0D0(ctx, base);
	// bl 0x823e27b8
	ctx.lr = 0x823DB4F8;
	sub_823E27B8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823db5a0
	if (cr0.eq) goto loc_823DB5A0;
	// lis r11,-32194
	r11.s64 = -2109865984;
	// lwz r10,-10664(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -10664);
	// addi r3,r11,-19656
	ctx.r3.s64 = r11.s64 + -19656;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823DB514;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r30,-32129
	r30.s64 = -2105606144;
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// stw r3,-20540(r30)
	PPC_STORE_U32(r30.u32 + -20540, ctx.r3.u32);
	// beq cr6,0x823db5a0
	if (cr6.eq) goto loc_823DB5A0;
	// li r4,196
	ctx.r4.s64 = 196;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x823e24c8
	ctx.lr = 0x823DB530;
	sub_823E24C8(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x823db5a0
	if (cr0.eq) goto loc_823DB5A0;
	// lwz r3,-20540(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -20540);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,-10656(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10656);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823DB54C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823db5a0
	if (cr0.eq) goto loc_823DB5A0;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r11,r11,-17872
	r11.s64 = r11.s64 + -17872;
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// bl 0x8244fec8
	ctx.lr = 0x823DB56C;
	sub_8244FEC8(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r11,-32194
	r11.s64 = -2109865984;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// addi r10,r10,-10676
	ctx.r10.s64 = ctx.r10.s64 + -10676;
	// li r9,-1
	ctx.r9.s64 = -1;
	// addi r11,r11,11416
	r11.s64 = r11.s64 + 11416;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// bl 0x82132900
	ctx.lr = 0x823DB598;
	sub_82132900(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823db5a8
	goto loc_823DB5A8;
loc_823DB5A0:
	// bl 0x823db190
	ctx.lr = 0x823DB5A4;
	sub_823DB190(ctx, base);
loc_823DB5A4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823DB5A8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823DB5B0"))) PPC_WEAK_FUNC(sub_823DB5B0);
PPC_FUNC_IMPL(__imp__sub_823DB5B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r0{};
	// cmpw r3,r4
	cr0.compare<int32_t>(ctx.r3.s32, ctx.r4.s32, xer);
	// beqlr- 
	if (cr0.eq) return;
	// bge+ 0x823db5c0
	if (!cr0.lt) goto loc_823DB5C0;
	// b 0x823da950
	sub_823DA950(ctx, base);
	return;
loc_823DB5C0:
	// addi r0,r5,1
	r0.s64 = ctx.r5.s64 + 1;
	// add r3,r3,r5
	ctx.r3.u64 = ctx.r3.u64 + ctx.r5.u64;
	// add r4,r4,r5
	ctx.r4.u64 = ctx.r4.u64 + ctx.r5.u64;
	// mtctr r0
	ctr.u64 = r0.u64;
	// b 0x823db5e8
	goto loc_823DB5E8;
loc_823DB5D4:
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// lbz r0,-1(r4)
	r0.u64 = PPC_LOAD_U8(ctx.r4.u32 + -1);
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// stb r0,-1(r3)
	PPC_STORE_U8(ctx.r3.u32 + -1, r0.u8);
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
loc_823DB5E8:
	// andi. r0,r3,3
	r0.u64 = ctx.r3.u64 & 3;
	cr0.compare<int32_t>(r0.s32, 0, xer);
	// bdnzf eq,0x823db5d4
	--ctr.u64;
	if (ctr.u32 != 0 && !cr0.eq) goto loc_823DB5D4;
	// rlwinm. r0,r5,30,2,31
	r0.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	cr0.compare<int32_t>(r0.s32, 0, xer);
	// beq- 0x823db618
	if (cr0.eq) goto loc_823DB618;
	// mtctr r0
	ctr.u64 = r0.u64;
	// andi. r0,r4,3
	r0.u64 = ctx.r4.u64 & 3;
	cr0.compare<int32_t>(r0.s32, 0, xer);
	// bne- 0x823db63c
	if (!cr0.eq) goto loc_823DB63C;
loc_823DB604:
	// lwz r7,-4(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + -4);
	// addi r4,r4,-4
	ctx.r4.s64 = ctx.r4.s64 + -4;
	// stw r7,-4(r3)
	PPC_STORE_U32(ctx.r3.u32 + -4, ctx.r7.u32);
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// bdnz+ 0x823db604
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DB604;
loc_823DB618:
	// andi. r0,r5,3
	r0.u64 = ctx.r5.u64 & 3;
	cr0.compare<int32_t>(r0.s32, 0, xer);
	// mtctr r0
	ctr.u64 = r0.u64;
	// beqlr+ 
	if (cr0.eq) return;
loc_823DB624:
	// lbz r0,-1(r4)
	r0.u64 = PPC_LOAD_U8(ctx.r4.u32 + -1);
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// stb r0,-1(r3)
	PPC_STORE_U8(ctx.r3.u32 + -1, r0.u8);
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
	// bdnz+ 0x823db624
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DB624;
	// blr 
	return;
loc_823DB63C:
	// lbz r7,-1(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + -1);
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// lbz r8,-2(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + -2);
	// rlwimi r7,r8,8,16,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r7.u64 & 0xFFFFFFFFFFFF00FF);
	// lbz r9,-3(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + -3);
	// rlwimi r7,r9,16,8,15
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r9.u32, 16) & 0xFF0000) | (ctx.r7.u64 & 0xFFFFFFFFFF00FFFF);
	// lbz r10,-4(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + -4);
	// rlwimi r7,r10,24,0,7
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r10.u32, 24) & 0xFF000000) | (ctx.r7.u64 & 0xFFFFFFFF00FFFFFF);
	// addi r4,r4,-4
	ctx.r4.s64 = ctx.r4.s64 + -4;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// bdnz 0x823db63c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DB63C;
	// b 0x823db618
	goto loc_823DB618;
}

__attribute__((alias("__imp__sub_823DB66C"))) PPC_WEAK_FUNC(sub_823DB66C);
PPC_FUNC_IMPL(__imp__sub_823DB66C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DB670"))) PPC_WEAK_FUNC(sub_823DB670);
PPC_FUNC_IMPL(__imp__sub_823DB670) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_823DB67C:
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// beq 0x823db69c
	if (cr0.eq) goto loc_823DB69C;
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne 0x823db67c
	if (!cr0.eq) goto loc_823DB67C;
loc_823DB69C:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addic. r10,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r10.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beqlr 
	if (cr0.eq) return;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr 
	if (cr0.eq) return;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_823DB6BC:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x823db6bc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823DB6BC;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DB6CC"))) PPC_WEAK_FUNC(sub_823DB6CC);
PPC_FUNC_IMPL(__imp__sub_823DB6CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DB6D0"))) PPC_WEAK_FUNC(sub_823DB6D0);
PPC_FUNC_IMPL(__imp__sub_823DB6D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	uint32_t ea{};
	// lbz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// cmpw r5,r4
	cr0.compare<int32_t>(ctx.r5.s32, ctx.r4.s32, xer);
	// beq cr6,0x823db714
	if (cr6.eq) goto loc_823DB714;
	// li r3,0
	ctx.r3.s64 = 0;
	// beq 0x823db700
	if (cr0.eq) goto loc_823DB700;
loc_823DB6EC:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x823db724
	if (cr6.eq) goto loc_823DB724;
	// lbzu r5,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r5.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// cmpw r4,r5
	cr0.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, xer);
	// bne 0x823db6ec
	if (!cr0.eq) goto loc_823DB6EC;
loc_823DB700:
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// lbzu r5,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r5.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// cmpw r4,r5
	cr0.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, xer);
	// beq 0x823db700
	if (cr0.eq) goto loc_823DB700;
	// b 0x823db6ec
	goto loc_823DB6EC;
loc_823DB714:
	// beq 0x823db724
	if (cr0.eq) goto loc_823DB724;
	// lbzu r5,1(r3)
	ea = 1 + ctx.r3.u32;
	ctx.r5.u64 = PPC_LOAD_U8(ea);
	ctx.r3.u32 = ea;
	// cmpwi r5,0
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// b 0x823db714
	goto loc_823DB714;
loc_823DB724:
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DB728"))) PPC_WEAK_FUNC(sub_823DB728);
PPC_FUNC_IMPL(__imp__sub_823DB728) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DB72C"))) PPC_WEAK_FUNC(sub_823DB72C);
PPC_FUNC_IMPL(__imp__sub_823DB72C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DB730"))) PPC_WEAK_FUNC(sub_823DB730);
PPC_FUNC_IMPL(__imp__sub_823DB730) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr1{};
	PPCCRRegister cr5{};
	PPCCRRegister cr6{};
	PPCCRRegister cr7{};
	uint32_t ea{};
	// addi r9,r3,-1
	ctx.r9.s64 = ctx.r3.s64 + -1;
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
loc_823DB738:
	// lbzu r6,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// lbzu r5,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r5.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// cmpwi cr7,r6,0
	cr7.compare<int32_t>(ctx.r6.s32, 0, xer);
	// subf. r3,r6,r5
	ctx.r3.s64 = ctx.r5.s64 - ctx.r6.s64;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr7,0x823db780
	if (cr7.eq) goto loc_823DB780;
	// beq 0x823db738
	if (cr0.eq) goto loc_823DB738;
	// cmpwi cr5,r6,65
	cr5.compare<int32_t>(ctx.r6.s32, 65, xer);
	// cmpwi cr6,r6,90
	cr6.compare<int32_t>(ctx.r6.s32, 90, xer);
	// blt cr5,0x823db764
	if (cr5.lt) goto loc_823DB764;
	// bgt cr6,0x823db764
	if (cr6.gt) goto loc_823DB764;
	// ori r6,r6,32
	ctx.r6.u64 = ctx.r6.u64 | 32;
loc_823DB764:
	// cmpwi r5,65
	cr0.compare<int32_t>(ctx.r5.s32, 65, xer);
	// cmpwi cr1,r5,90
	cr1.compare<int32_t>(ctx.r5.s32, 90, xer);
	// blt 0x823db778
	if (cr0.lt) goto loc_823DB778;
	// bgt cr1,0x823db778
	if (cr1.gt) goto loc_823DB778;
	// ori r5,r5,32
	ctx.r5.u64 = ctx.r5.u64 | 32;
loc_823DB778:
	// subf. r3,r6,r5
	ctx.r3.s64 = ctx.r5.s64 - ctx.r6.s64;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x823db738
	if (cr0.eq) goto loc_823DB738;
loc_823DB780:
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DB784"))) PPC_WEAK_FUNC(sub_823DB784);
PPC_FUNC_IMPL(__imp__sub_823DB784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DB788"))) PPC_WEAK_FUNC(sub_823DB788);
PPC_FUNC_IMPL(__imp__sub_823DB788) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfd f1,16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// lfd f6,21560(r11)
	ctx.f6.u64 = PPC_LOAD_U64(r11.u32 + 21560);
	// fcmpu cr6,f1,f6
	cr6.compare(ctx.f1.f64, ctx.f6.f64);
	// bne cr6,0x823db7a8
	if (!cr6.eq) goto loc_823DB7A8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfd f1,-17600(r11)
	ctx.f1.u64 = PPC_LOAD_U64(r11.u32 + -17600);
	// blr 
	return;
loc_823DB7A8:
	// lhz r10,16(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 16);
	// rlwinm r11,r10,0,17,27
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x7FF0;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// cmplwi cr6,r11,32752
	cr6.compare<uint32_t>(r11.u32, 32752, xer);
	// bne cr6,0x823db7dc
	if (!cr6.eq) goto loc_823DB7DC;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lfd f0,-12152(r11)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r11.u32 + -12152);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgtlr cr6
	if (cr6.gt) return;
loc_823DB7CC:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lfd f0,-17728(r11)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r11.u32 + -17728);
loc_823DB7D4:
	// fneg f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = f0.u64 ^ 0x8000000000000000;
	// blr 
	return;
loc_823DB7DC:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfd f0,-17600(r10)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + -17600);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x823db800
	if (cr6.gt) goto loc_823DB800;
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bne cr6,0x823db7cc
	if (!cr6.eq) goto loc_823DB7CC;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lfd f0,-17736(r11)
	f0.u64 = PPC_LOAD_U64(r11.u32 + -17736);
	// b 0x823db7d4
	goto loc_823DB7D4;
loc_823DB800:
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lfd f0,-12160(r10)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + -12160);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x823db838
	if (!cr6.lt) goto loc_823DB838;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lfd f0,-12168(r11)
	f0.u64 = PPC_LOAD_U64(r11.u32 + -12168);
	// fmul f1,f1,f0
	ctx.f1.f64 = ctx.f1.f64 * f0.f64;
	// stfd f1,16(r1)
	PPC_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// lhz r11,16(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 16);
	// rlwinm r10,r11,28,21,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0x7FF;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// addi r10,r11,-1075
	ctx.r10.s64 = r11.s64 + -1075;
	// b 0x823db840
	goto loc_823DB840;
loc_823DB838:
	// rlwinm r11,r11,28,20,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0xFFF;
	// addi r10,r11,-1022
	ctx.r10.s64 = r11.s64 + -1022;
loc_823DB840:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// stfd f1,-16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f1.u64);
	// andi. r9,r9,32783
	ctx.r9.u64 = ctx.r9.u64 & 32783;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,-12288
	r11.s64 = r11.s64 + -12288;
	// ori r9,r9,16352
	ctx.r9.u64 = ctx.r9.u64 | 16352;
	// sth r9,-16(r1)
	PPC_STORE_U16(ctx.r1.u32 + -16, ctx.r9.u16);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfd f0,0(r11)
	f0.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x823db884
	if (!cr6.gt) goto loc_823DB884;
	// lfd f0,32224(r9)
	f0.u64 = PPC_LOAD_U64(ctx.r9.u32 + 32224);
	// fadd f12,f13,f6
	ctx.f12.f64 = ctx.f13.f64 + ctx.f6.f64;
	// fsub f11,f13,f0
	ctx.f11.f64 = ctx.f13.f64 - f0.f64;
	// fmul f13,f12,f0
	ctx.f13.f64 = ctx.f12.f64 * f0.f64;
	// fsub f0,f11,f0
	f0.f64 = ctx.f11.f64 - f0.f64;
	// b 0x823db898
	goto loc_823DB898;
loc_823DB884:
	// lfd f12,32224(r9)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r9.u32 + 32224);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// fsub f0,f13,f12
	f0.f64 = ctx.f13.f64 - ctx.f12.f64;
	// fadd f13,f0,f6
	ctx.f13.f64 = f0.f64 + ctx.f6.f64;
	// fmul f13,f13,f12
	ctx.f13.f64 = ctx.f13.f64 * ctx.f12.f64;
loc_823DB898:
	// fdiv f5,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = f0.f64 / ctx.f13.f64;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// lfd f12,40(r11)
	ctx.f12.u64 = PPC_LOAD_U64(r11.u32 + 40);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// lfd f9,64(r11)
	ctx.f9.u64 = PPC_LOAD_U64(r11.u32 + 64);
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// lfd f7,8(r11)
	ctx.f7.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// extsw r11,r10
	r11.s64 = ctx.r10.s32;
	// lfd f13,-12176(r9)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r9.u32 + -12176);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lfd f11,-12184(r8)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r8.u32 + -12184);
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f10,-12192(r7)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r7.u32 + -12192);
	// lfd f8,-12200(r6)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r6.u32 + -12200);
	// lfd f0,-16(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f4,f0
	ctx.f4.f64 = double(f0.s64);
	// fmul f3,f5,f5
	ctx.f3.f64 = ctx.f5.f64 * ctx.f5.f64;
	// lfd f0,-12208(r10)
	f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + -12208);
	// fmul f0,f4,f0
	f0.f64 = ctx.f4.f64 * f0.f64;
	// fnmsub f13,f3,f13,f12
	ctx.f13.f64 = -(ctx.f3.f64 * ctx.f13.f64 - ctx.f12.f64);
	// fsub f12,f3,f11
	ctx.f12.f64 = ctx.f3.f64 - ctx.f11.f64;
	// fmsub f13,f13,f3,f10
	ctx.f13.f64 = ctx.f13.f64 * ctx.f3.f64 - ctx.f10.f64;
	// fmadd f12,f12,f3,f9
	ctx.f12.f64 = ctx.f12.f64 * ctx.f3.f64 + ctx.f9.f64;
	// fmul f13,f13,f3
	ctx.f13.f64 = ctx.f13.f64 * ctx.f3.f64;
	// fmsub f12,f12,f3,f8
	ctx.f12.f64 = ctx.f12.f64 * ctx.f3.f64 - ctx.f8.f64;
	// fdiv f13,f13,f12
	ctx.f13.f64 = ctx.f13.f64 / ctx.f12.f64;
	// fadd f13,f13,f6
	ctx.f13.f64 = ctx.f13.f64 + ctx.f6.f64;
	// fmsub f0,f13,f5,f0
	f0.f64 = ctx.f13.f64 * ctx.f5.f64 - f0.f64;
	// fmadd f1,f4,f7,f0
	ctx.f1.f64 = ctx.f4.f64 * ctx.f7.f64 + f0.f64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DB914"))) PPC_WEAK_FUNC(sub_823DB914);
PPC_FUNC_IMPL(__imp__sub_823DB914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DB918"))) PPC_WEAK_FUNC(sub_823DB918);
PPC_FUNC_IMPL(__imp__sub_823DB918) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x823db788
	ctx.lr = 0x823DB928;
	sub_823DB788(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lfd f0,-12264(r11)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r11.u32 + -12264);
	// fmul f1,f1,f0
	ctx.f1.f64 = ctx.f1.f64 * f0.f64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DB944"))) PPC_WEAK_FUNC(sub_823DB944);
PPC_FUNC_IMPL(__imp__sub_823DB944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DB948"))) PPC_WEAK_FUNC(sub_823DB948);
PPC_FUNC_IMPL(__imp__sub_823DB948) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_823DB94C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823db94c
	if (!cr6.eq) goto loc_823DB94C;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// b 0x823db980
	goto loc_823DB980;
loc_823DB964:
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// beqlr 
	if (cr0.eq) return;
loc_823DB980:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x823db964
	if (!cr6.eq) goto loc_823DB964;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823DB994"))) PPC_WEAK_FUNC(sub_823DB994);
PPC_FUNC_IMPL(__imp__sub_823DB994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DB998"))) PPC_WEAK_FUNC(sub_823DB998);
PPC_FUNC_IMPL(__imp__sub_823DB998) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823DB99C"))) PPC_WEAK_FUNC(sub_823DB99C);
PPC_FUNC_IMPL(__imp__sub_823DB99C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp____savefpr_14"))) PPC_WEAK_FUNC(__savefpr_14);
PPC_FUNC_IMPL(__imp____savefpr_14) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister f14{};
	PPCRegister f15{};
	PPCRegister f16{};
	PPCRegister f17{};
	PPCRegister f18{};
	PPCRegister f19{};
	PPCRegister f20{};
	PPCRegister f21{};
	PPCRegister f22{};
	PPCRegister f23{};
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	// stfd f14,-144(r12)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(r12.u32 + -144, f14.u64);
	// stfd f15,-136(r12)
	PPC_STORE_U64(r12.u32 + -136, f15.u64);
	// stfd f16,-128(r12)
	PPC_STORE_U64(r12.u32 + -128, f16.u64);
	// stfd f17,-120(r12)
	PPC_STORE_U64(r12.u32 + -120, f17.u64);
	// stfd f18,-112(r12)
	PPC_STORE_U64(r12.u32 + -112, f18.u64);
	// stfd f19,-104(r12)
	PPC_STORE_U64(r12.u32 + -104, f19.u64);
	// stfd f20,-96(r12)
	PPC_STORE_U64(r12.u32 + -96, f20.u64);
	// stfd f21,-88(r12)
	PPC_STORE_U64(r12.u32 + -88, f21.u64);
	// stfd f22,-80(r12)
	PPC_STORE_U64(r12.u32 + -80, f22.u64);
	// stfd f23,-72(r12)
	PPC_STORE_U64(r12.u32 + -72, f23.u64);
	// stfd f24,-64(r12)
	PPC_STORE_U64(r12.u32 + -64, f24.u64);
	// stfd f25,-56(r12)
	PPC_STORE_U64(r12.u32 + -56, f25.u64);
	// stfd f26,-48(r12)
	PPC_STORE_U64(r12.u32 + -48, f26.u64);
	// stfd f27,-40(r12)
	PPC_STORE_U64(r12.u32 + -40, f27.u64);
	// stfd f28,-32(r12)
	PPC_STORE_U64(r12.u32 + -32, f28.u64);
	// stfd f29,-24(r12)
	PPC_STORE_U64(r12.u32 + -24, f29.u64);
	// stfd f30,-16(r12)
	PPC_STORE_U64(r12.u32 + -16, f30.u64);
	// stfd f31,-8(r12)
	PPC_STORE_U64(r12.u32 + -8, f31.u64);
	// blr 
	return;
}

