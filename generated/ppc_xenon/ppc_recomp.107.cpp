#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_825454E0"))) PPC_WEAK_FUNC(sub_825454E0);
PPC_FUNC_IMPL(__imp__sub_825454E0) {
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
	ctx.lr = 0x825454E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r11,6(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82545530
	if (cr6.eq) goto loc_82545530;
	// lwz r29,0(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82545528
	if (!cr6.gt) goto loc_82545528;
	// addi r31,r29,4
	r31.s64 = r29.s64 + 4;
	// mr r30,r11
	r30.u64 = r11.u64;
loc_8254550C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8254551c
	if (cr6.eq) goto loc_8254551C;
	// bl 0x82130588
	ctx.lr = 0x8254551C;
	sub_82130588(ctx, base);
loc_8254551C:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x8254550c
	if (!cr0.eq) goto loc_8254550C;
loc_82545528:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82545530;
	sub_82130588(ctx, base);
loc_82545530:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82545538"))) PPC_WEAK_FUNC(sub_82545538);
PPC_FUNC_IMPL(__imp__sub_82545538) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825455a4
	if (cr6.eq) goto loc_825455A4;
	// li r30,0
	r30.s64 = 0;
loc_82545560:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82545594
	if (cr6.eq) goto loc_82545594;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r30.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplw cr6,r10,r3
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, xer);
	// bne cr6,0x82545588
	if (!cr6.eq) goto loc_82545588;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
loc_82545588:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
loc_82545594:
	// bl 0x82130588
	ctx.lr = 0x82545598;
	sub_82130588(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82545560
	if (!cr6.eq) goto loc_82545560;
loc_825455A4:
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

__attribute__((alias("__imp__sub_825455BC"))) PPC_WEAK_FUNC(sub_825455BC);
PPC_FUNC_IMPL(__imp__sub_825455BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825455C0"))) PPC_WEAK_FUNC(sub_825455C0);
PPC_FUNC_IMPL(__imp__sub_825455C0) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x825455C8;
	// stfd f29,-128(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -128, f29.u64);
	// stfd f30,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, f30.u64);
	// stfd f31,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// subf r11,r28,r25
	r11.s64 = r25.s64 - r28.s64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r24,r11,1
	r24.s64 = r11.s64 + 1;
	// mr r20,r8
	r20.u64 = ctx.r8.u64;
	// addi r11,r24,-1
	r11.s64 = r24.s64 + -1;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// mr r22,r11
	r22.u64 = r11.u64;
	// blt cr6,0x8254560c
	if (cr6.lt) goto loc_8254560C;
	// li r22,8
	r22.s64 = 8;
loc_8254560C:
	// li r21,0
	r21.s64 = 0;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// mr r27,r21
	r27.u64 = r21.u64;
	// blt cr6,0x825456c8
	if (cr6.lt) goto loc_825456C8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f29,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f29.f64 = double(temp.f32);
loc_82545624:
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x825450e8
	ctx.lr = 0x82545640;
	sub_825450E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825456bc
	if (cr6.eq) goto loc_825456BC;
	// fmr f31,f29
	ctx.fpscr.disableFlushMode();
	f31.f64 = f29.f64;
	// cmpw cr6,r28,r25
	cr6.compare<int32_t>(r28.s32, r25.s32, xer);
	// bgt cr6,0x825456b4
	if (cr6.gt) goto loc_825456B4;
	// rlwinm r11,r28,2,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r30,r21
	r30.u64 = r21.u64;
	// add r29,r11,r26
	r29.u64 = r11.u64 + r26.u64;
	// mr r31,r24
	r31.u64 = r24.u64;
loc_82545668:
	// extsw r11,r30
	r11.s64 = r30.s32;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
	// bl 0x825440f0
	ctx.lr = 0x8254568C;
	sub_825440F0(ctx, base);
	// lfs f12,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// fabs f9,f10
	ctx.f9.u64 = ctx.f10.u64 & ~0x8000000000000000;
	// fsubs f8,f31,f9
	ctx.f8.f64 = double(float(f31.f64 - ctx.f9.f64));
	// fsel f31,f8,f31,f9
	f31.f64 = ctx.f8.f64 >= 0.0 ? f31.f64 : ctx.f9.f64;
	// bne 0x82545668
	if (!cr0.eq) goto loc_82545668;
loc_825456B4:
	// fcmpu cr6,f31,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f30.f64);
	// blt cr6,0x825457bc
	if (cr6.lt) goto loc_825457BC;
loc_825456BC:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmpw cr6,r27,r22
	cr6.compare<int32_t>(r27.s32, r22.s32, xer);
	// ble cr6,0x82545624
	if (!cr6.gt) goto loc_82545624;
loc_825456C8:
	// cmpwi cr6,r24,2
	cr6.compare<int32_t>(r24.s32, 2, xer);
	// ble cr6,0x82545910
	if (!cr6.gt) goto loc_82545910;
	// stw r21,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r21.u32);
	// add r11,r28,r25
	r11.u64 = r28.u64 + r25.u64;
	// stw r21,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r21.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stw r21,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r21.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addze r31,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r31.s64 = temp.s64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// bl 0x825455c0
	ctx.lr = 0x82545708;
	sub_825455C0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82545740
	if (cr6.eq) goto loc_82545740;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x825455c0
	ctx.lr = 0x82545730;
	sub_825455C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82545744
	if (!cr6.eq) goto loc_82545744;
loc_82545740:
	// mr r11,r21
	r11.u64 = r21.u64;
loc_82545744:
	// clrlwi r29,r11,24
	r29.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x825458b4
	if (cr6.eq) goto loc_825458B4;
loc_82545750:
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825458f8
	if (cr6.eq) goto loc_825458F8;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r21,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r21.u32);
	// lwz r8,100(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// bne cr6,0x8254577c
	if (!cr6.eq) goto loc_8254577C;
	// stw r21,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r21.u32);
loc_8254577C:
	// lwz r9,104(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r10,4(r20)
	ctx.r10.u64 = PPC_LOAD_U32(r20.u32 + 4);
	// addi r8,r9,-1
	ctx.r8.s64 = ctx.r9.s64 + -1;
	// stw r11,4(r20)
	PPC_STORE_U32(r20.u32 + 4, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// beq cr6,0x8254579c
	if (cr6.eq) goto loc_8254579C;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
loc_8254579C:
	// lwz r10,0(r20)
	ctx.r10.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x825457ac
	if (!cr6.eq) goto loc_825457AC;
	// stw r11,0(r20)
	PPC_STORE_U32(r20.u32 + 0, r11.u32);
loc_825457AC:
	// lwz r11,8(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r20)
	PPC_STORE_U32(r20.u32 + 8, r11.u32);
	// b 0x82545750
	goto loc_82545750;
loc_825457BC:
	// cmpw cr6,r27,r22
	cr6.compare<int32_t>(r27.s32, r22.s32, xer);
	// bgt cr6,0x825456c8
	if (cr6.gt) goto loc_825456C8;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x825457CC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825457ec
	if (cr6.eq) goto loc_825457EC;
	// sth r21,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, r21.u16);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stb r21,2(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2, r21.u8);
	// stb r21,3(r3)
	PPC_STORE_U8(ctx.r3.u32 + 3, r21.u8);
	// stw r21,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r21.u32);
	// b 0x825457f0
	goto loc_825457F0;
loc_825457EC:
	// mr r31,r21
	r31.u64 = r21.u64;
loc_825457F0:
	// lis r11,16383
	r11.s64 = 1073676288;
	// sth r25,0(r31)
	PPC_STORE_U16(r31.u32 + 0, r25.u16);
	// addi r30,r27,1
	r30.s64 = r27.s64 + 1;
	// stb r27,2(r31)
	PPC_STORE_U8(r31.u32 + 2, r27.u8);
	// ori r8,r11,65535
	ctx.r8.u64 = r11.u64 | 65535;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r30,r8
	cr6.compare<uint32_t>(r30.u32, ctx.r8.u32, xer);
	// ble cr6,0x82545814
	if (!cr6.gt) goto loc_82545814;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_82545814:
	// bl 0x82130528
	ctx.lr = 0x82545818;
	sub_82130528(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// blt cr6,0x82545848
	if (cr6.lt) goto loc_82545848;
	// mr r11,r21
	r11.u64 = r21.u64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
loc_8254582C:
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfsx f0,r11,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	f0.f64 = double(temp.f32);
	// stfsx f0,r11,r8
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8254582c
	if (!cr0.eq) goto loc_8254582C;
loc_82545848:
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82545850;
	sub_82130528(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82545864
	if (cr6.eq) goto loc_82545864;
	// stw r21,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r21.u32);
	// b 0x82545868
	goto loc_82545868;
loc_82545864:
	// mr r11,r21
	r11.u64 = r21.u64;
loc_82545868:
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// lwz r10,4(r20)
	ctx.r10.u64 = PPC_LOAD_U32(r20.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,4(r20)
	PPC_STORE_U32(r20.u32 + 4, r11.u32);
	// beq cr6,0x82545880
	if (cr6.eq) goto loc_82545880;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
loc_82545880:
	// lwz r10,0(r20)
	ctx.r10.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82545890
	if (!cr6.eq) goto loc_82545890;
	// stw r11,0(r20)
	PPC_STORE_U32(r20.u32 + 0, r11.u32);
loc_82545890:
	// lwz r11,8(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 8);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r20)
	PPC_STORE_U32(r20.u32 + 8, r11.u32);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f29,-128(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f30,-120(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f31,-112(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
loc_825458B4:
	// lwz r30,96(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x825458f0
	if (cr6.eq) goto loc_825458F0;
loc_825458C0:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825458e4
	if (cr6.eq) goto loc_825458E4;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825458dc
	if (cr6.eq) goto loc_825458DC;
	// bl 0x82130588
	ctx.lr = 0x825458DC;
	sub_82130588(ctx, base);
loc_825458DC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x825458E4;
	sub_82130588(ctx, base);
loc_825458E4:
	// lwz r30,4(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x825458c0
	if (!cr6.eq) goto loc_825458C0;
loc_825458F0:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82545538
	ctx.lr = 0x825458F8;
	sub_82545538(ctx, base);
loc_825458F8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f29,-128(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f30,-120(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f31,-112(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
loc_82545910:
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f29,-128(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f30,-120(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f31,-112(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82545928"))) PPC_WEAK_FUNC(sub_82545928);
PPC_FUNC_IMPL(__imp__sub_82545928) {
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
	ctx.lr = 0x82545930;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x82545978
	if (cr6.eq) goto loc_82545978;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82545974
	if (cr6.eq) goto loc_82545974;
	// bl 0x825443a0
	ctx.lr = 0x8254596C;
	sub_825443A0(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// b 0x82545978
	goto loc_82545978;
loc_82545974:
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
loc_82545978:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825459b0
	if (cr6.eq) goto loc_825459B0;
loc_82545984:
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r11,r30,3,0,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + r11.u64;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x825441c0
	ctx.lr = 0x8254599C;
	sub_825441C0(ctx, base);
	// addi r11,r30,1
	r11.s64 = r30.s64 + 1;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// clrlwi r30,r11,16
	r30.u64 = r11.u32 & 0xFFFF;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// blt cr6,0x82545984
	if (cr6.lt) goto loc_82545984;
loc_825459B0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_825459B8"))) PPC_WEAK_FUNC(sub_825459B8);
PPC_FUNC_IMPL(__imp__sub_825459B8) {
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
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x825459CC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82545a08
	if (cr6.eq) goto loc_82545A08;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r11,-20404
	ctx.r9.s64 = r11.s64 + -20404;
	// li r11,0
	r11.s64 = 0;
	// stb r10,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r10.u8);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
	// sth r11,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r11.u16);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82545A08:
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

__attribute__((alias("__imp__sub_82545A1C"))) PPC_WEAK_FUNC(sub_82545A1C);
PPC_FUNC_IMPL(__imp__sub_82545A1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82545A20"))) PPC_WEAK_FUNC(sub_82545A20);
PPC_FUNC_IMPL(__imp__sub_82545A20) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,-20404
	ctx.r10.s64 = r11.s64 + -20404;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x825454e0
	ctx.lr = 0x82545A50;
	sub_825454E0(ctx, base);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// clrlwi r8,r30,31
	ctx.r8.u64 = r30.u32 & 0x1;
	// addi r7,r9,-24636
	ctx.r7.s64 = ctx.r9.s64 + -24636;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x82545a74
	if (cr6.eq) goto loc_82545A74;
	// bl 0x82130588
	ctx.lr = 0x82545A70;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82545A74:
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

__attribute__((alias("__imp__sub_82545A8C"))) PPC_WEAK_FUNC(sub_82545A8C);
PPC_FUNC_IMPL(__imp__sub_82545A8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82545A90"))) PPC_WEAK_FUNC(sub_82545A90);
PPC_FUNC_IMPL(__imp__sub_82545A90) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r9,r11,-24636
	ctx.r9.s64 = r11.s64 + -24636;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// li r11,0
	r11.s64 = 0;
	// addi r8,r10,-20404
	ctx.r8.s64 = ctx.r10.s64 + -20404;
	// lbz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stb r7,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r7.u8);
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// lbz r6,5(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// stb r6,5(r31)
	PPC_STORE_U8(r31.u32 + 5, ctx.r6.u8);
	// lhz r5,6(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// sth r5,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r5.u16);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// sth r11,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r11.u16);
	// sth r11,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r11.u16);
	// bl 0x82545928
	ctx.lr = 0x82545AF8;
	sub_82545928(ctx, base);
	// lfs f0,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 16);
	f0.f64 = double(temp.f32);
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f13,20(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,20(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
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

__attribute__((alias("__imp__sub_82545B24"))) PPC_WEAK_FUNC(sub_82545B24);
PPC_FUNC_IMPL(__imp__sub_82545B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82545B28"))) PPC_WEAK_FUNC(sub_82545B28);
PPC_FUNC_IMPL(__imp__sub_82545B28) {
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
	ctx.lr = 0x82545B30;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r10,r11,-20404
	ctx.r10.s64 = r11.s64 + -20404;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// lwz r4,8(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82545b68
	if (cr6.eq) goto loc_82545B68;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8217d890
	ctx.lr = 0x82545B5C;
	sub_8217D890(ctx, base);
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r10.u32);
loc_82545B68:
	// lhz r11,12(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 12);
	// li r25,0
	r25.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82545c08
	if (cr6.eq) goto loc_82545C08;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r26,0
	r26.s64 = 0;
	// addi r24,r11,-26560
	r24.s64 = r11.s64 + -26560;
loc_82545B84:
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// add. r29,r11,r26
	r29.u64 = r11.u64 + r26.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// beq 0x82545bf4
	if (cr0.eq) goto loc_82545BF4;
	// lwz r30,4(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82545bf4
	if (cr6.eq) goto loc_82545BF4;
	// lwz r31,0(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217d828
	ctx.lr = 0x82545BAC;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82545bd4
	if (cr6.eq) goto loc_82545BD4;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// b 0x82545be8
	goto loc_82545BE8;
loc_82545BD4:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821d2378
	ctx.lr = 0x82545BE4;
	sub_821D2378(ctx, base);
	// li r11,0
	r11.s64 = 0;
loc_82545BE8:
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
loc_82545BF4:
	// lhz r11,12(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 12);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r26,r26,8
	r26.s64 = r26.s64 + 8;
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// blt cr6,0x82545b84
	if (cr6.lt) goto loc_82545B84;
loc_82545C08:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82545C14"))) PPC_WEAK_FUNC(sub_82545C14);
PPC_FUNC_IMPL(__imp__sub_82545C14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82545C18"))) PPC_WEAK_FUNC(sub_82545C18);
PPC_FUNC_IMPL(__imp__sub_82545C18) {
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
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82545C20;
	// stfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f30.u64);
	// stfd f31,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r31,3
	cr6.compare<int32_t>(r31.s32, 3, xer);
	// bge cr6,0x82545c58
	if (!cr6.lt) goto loc_82545C58;
loc_82545C44:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_82545C58:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// beq cr6,0x82545c44
	if (cr6.eq) goto loc_82545C44;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r30,r6,1
	r30.s64 = ctx.r6.s64 + 1;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// lfs f13,-29632(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29632);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-31400(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31400);
	f0.f64 = double(temp.f32);
	// ble cr6,0x82545cb0
	if (!cr6.gt) goto loc_82545CB0;
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_82545C90:
	// lfs f12,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// fsubs f10,f0,f12
	ctx.f10.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fsel f13,f11,f13,f12
	ctx.f13.f64 = ctx.f11.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsel f0,f10,f12,f0
	f0.f64 = ctx.f10.f64 >= 0.0 ? ctx.f12.f64 : f0.f64;
	// bne 0x82545c90
	if (!cr0.eq) goto loc_82545C90;
loc_82545CB0:
	// fsubs f12,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// stfs f12,16(r28)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r28.u32 + 16, temp.u32);
	// stfs f0,20(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 20, temp.u32);
	// rlwinm r3,r31,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// lfs f13,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// fdivs f31,f13,f12
	f31.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// ble cr6,0x82545ce0
	if (!cr6.gt) goto loc_82545CE0;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_82545CE0:
	// bl 0x82130528
	ctx.lr = 0x82545CE4;
	sub_82130528(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82545d24
	if (!cr6.gt) goto loc_82545D24;
	// rlwinm r8,r30,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_82545D00:
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lfs f13,20(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// stfs f11,0(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x82545d00
	if (!cr0.eq) goto loc_82545D00;
loc_82545D24:
	// li r25,0
	r25.s64 = 0;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// addi r6,r31,-1
	ctx.r6.s64 = r31.s64 + -1;
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r25.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r25.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r25,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r25.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r31,r25
	r31.u64 = r25.u64;
	// bl 0x825455c0
	ctx.lr = 0x82545D54;
	sub_825455C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82545e1c
	if (cr6.eq) goto loc_82545E1C;
	// addi r29,r28,8
	r29.s64 = r28.s64 + 8;
	// lwz r28,88(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82545d80
	if (cr6.eq) goto loc_82545D80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825443a0
	ctx.lr = 0x82545D7C;
	sub_825443A0(ctx, base);
	// b 0x82545d84
	goto loc_82545D84;
loc_82545D80:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_82545D84:
	// lwz r26,84(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r27,80(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// sth r28,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r28.u16);
loc_82545D94:
	// mr r30,r27
	r30.u64 = r27.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82545e0c
	if (cr6.eq) goto loc_82545E0C;
	// addi r11,r27,4
	r11.s64 = r27.s64 + 4;
	// lwz r27,4(r27)
	r27.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// cmplw cr6,r26,r30
	cr6.compare<uint32_t>(r26.u32, r30.u32, xer);
	// stw r25,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r25.u32);
	// bne cr6,0x82545db8
	if (!cr6.eq) goto loc_82545DB8;
	// mr r26,r25
	r26.u64 = r25.u64;
loc_82545DB8:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r11,r11,3
	r11.u64 = __builtin_rotateleft32(r11.u32, 3);
	// sth r9,4(r29)
	PPC_STORE_U16(r29.u32 + 4, ctx.r9.u16);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x825441c0
	ctx.lr = 0x82545DDC;
	sub_825441C0(ctx, base);
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82545e00
	if (cr6.eq) goto loc_82545E00;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82545df8
	if (cr6.eq) goto loc_82545DF8;
	// bl 0x82130588
	ctx.lr = 0x82545DF8;
	sub_82130588(ctx, base);
loc_82545DF8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82545E00;
	sub_82130588(ctx, base);
loc_82545E00:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82545E08;
	sub_82130588(ctx, base);
	// b 0x82545d94
	goto loc_82545D94;
loc_82545E0C:
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// li r31,1
	r31.s64 = 1;
	// stw r26,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r26.u32);
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
loc_82545E1C:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82130588
	ctx.lr = 0x82545E24;
	sub_82130588(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82545538
	ctx.lr = 0x82545E2C;
	sub_82545538(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82545E40"))) PPC_WEAK_FUNC(sub_82545E40);
PPC_FUNC_IMPL(__imp__sub_82545E40) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x82545E5C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82545e80
	if (cr6.eq) goto loc_82545E80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82545a90
	ctx.lr = 0x82545E6C;
	sub_82545A90(ctx, base);
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
loc_82545E80:
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

__attribute__((alias("__imp__sub_82545E98"))) PPC_WEAK_FUNC(sub_82545E98);
PPC_FUNC_IMPL(__imp__sub_82545E98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82545b28
	sub_82545B28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82545EA4"))) PPC_WEAK_FUNC(sub_82545EA4);
PPC_FUNC_IMPL(__imp__sub_82545EA4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82545EA8"))) PPC_WEAK_FUNC(sub_82545EA8);
PPC_FUNC_IMPL(__imp__sub_82545EA8) {
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
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x82545EBC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82545ef8
	if (cr6.eq) goto loc_82545EF8;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r10,6
	ctx.r10.s64 = 6;
	// addi r9,r11,-20044
	ctx.r9.s64 = r11.s64 + -20044;
	// li r11,0
	r11.s64 = 0;
	// stb r10,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r10.u8);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82545EF8:
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

__attribute__((alias("__imp__sub_82545F0C"))) PPC_WEAK_FUNC(sub_82545F0C);
PPC_FUNC_IMPL(__imp__sub_82545F0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82545F10"))) PPC_WEAK_FUNC(sub_82545F10);
PPC_FUNC_IMPL(__imp__sub_82545F10) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-20044
	ctx.r10.s64 = r11.s64 + -20044;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x82545F40;
	sub_82130588(ctx, base);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// clrlwi r8,r30,31
	ctx.r8.u64 = r30.u32 & 0x1;
	// addi r7,r9,-24636
	ctx.r7.s64 = ctx.r9.s64 + -24636;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x82545f64
	if (cr6.eq) goto loc_82545F64;
	// bl 0x82130588
	ctx.lr = 0x82545F60;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82545F64:
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

__attribute__((alias("__imp__sub_82545F7C"))) PPC_WEAK_FUNC(sub_82545F7C);
PPC_FUNC_IMPL(__imp__sub_82545F7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82545F80"))) PPC_WEAK_FUNC(sub_82545F80);
PPC_FUNC_IMPL(__imp__sub_82545F80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r7,r4,1
	ctx.r7.s64 = ctx.r4.s64 + 1;
	// mullw r5,r9,r4
	ctx.r5.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r4.s32);
	// rlwinm r10,r5,29,3,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 29) & 0x1FFFFFFC;
	// addi r4,r8,1576
	ctx.r4.s64 = ctx.r8.s64 + 1576;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r3,8
	ctx.r10.s64 = ctx.r3.s64 + 8;
	// clrldi r8,r5,59
	ctx.r8.u64 = ctx.r5.u64 & 0x1F;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rldicr r11,r10,32,63
	r11.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// lwzx r10,r5,r4
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r4.u32);
	// or r9,r11,r9
	ctx.r9.u64 = r11.u64 | ctx.r9.u64;
	// srd r8,r9,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r8.u8 & 0x7F));
	// rotlwi r5,r8,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// and r11,r5,r10
	r11.u64 = ctx.r5.u64 & ctx.r10.u64;
	// std r11,0(r6)
	PPC_STORE_U64(ctx.r6.u32 + 0, r11.u64);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mullw r8,r7,r9
	ctx.r8.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// rlwinm r10,r8,29,3,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 29) & 0x1FFFFFFC;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrldi r5,r8,59
	ctx.r5.u64 = ctx.r8.u64 & 0x1F;
	// lwzx r4,r7,r4
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r4.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// or r9,r10,r3
	ctx.r9.u64 = ctx.r10.u64 | ctx.r3.u64;
	// srd r8,r9,r5
	ctx.r8.u64 = ctx.r5.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r5.u8 & 0x7F));
	// rotlwi r7,r8,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// and r5,r7,r4
	ctx.r5.u64 = ctx.r7.u64 & ctx.r4.u64;
	// std r5,8(r6)
	PPC_STORE_U64(ctx.r6.u32 + 8, ctx.r5.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82546014"))) PPC_WEAK_FUNC(sub_82546014);
PPC_FUNC_IMPL(__imp__sub_82546014) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82546018"))) PPC_WEAK_FUNC(sub_82546018);
PPC_FUNC_IMPL(__imp__sub_82546018) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r9,r11,-24636
	ctx.r9.s64 = r11.s64 + -24636;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r8,r10,-20044
	ctx.r8.s64 = ctx.r10.s64 + -20044;
	// lbz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// stb r7,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r7.u8);
	// lbz r6,5(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// stb r6,5(r31)
	PPC_STORE_U8(r31.u32 + 5, ctx.r6.u8);
	// lhz r5,6(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// sth r5,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r5.u16);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bl 0x82543350
	ctx.lr = 0x82546070;
	sub_82543350(ctx, base);
	// lfs f0,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f13,24(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,24(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
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

__attribute__((alias("__imp__sub_8254609C"))) PPC_WEAK_FUNC(sub_8254609C);
PPC_FUNC_IMPL(__imp__sub_8254609C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825460A0"))) PPC_WEAK_FUNC(sub_825460A0);
PPC_FUNC_IMPL(__imp__sub_825460A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bgt cr6,0x825460b4
	if (cr6.gt) goto loc_825460B4;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_825460B4:
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lfs f0,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	f0.f64 = double(temp.f32);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lfs f13,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// mullw r7,r11,r9
	ctx.r7.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// rlwinm r11,r7,29,3,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1FFFFFFC;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r6,r8,1576
	ctx.r6.s64 = ctx.r8.s64 + 1576;
	// rlwinm r4,r9,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// clrldi r5,r7,59
	ctx.r5.u64 = ctx.r7.u64 & 0x1F;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rldicr r10,r3,32,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// lwzx r9,r4,r6
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// or r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 | r11.u64;
	// srd r7,r8,r5
	ctx.r7.u64 = ctx.r5.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r5.u8 & 0x7F));
	// rotlwi r6,r7,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// and r5,r6,r9
	ctx.r5.u64 = ctx.r6.u64 & ctx.r9.u64;
	// clrldi r4,r5,32
	ctx.r4.u64 = ctx.r5.u64 & 0xFFFFFFFF;
	// std r4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r4.u64);
	// lfd f12,-16(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmadds f1,f10,f0,f13
	ctx.f1.f64 = double(float(ctx.f10.f64 * f0.f64 + ctx.f13.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8254611C"))) PPC_WEAK_FUNC(sub_8254611C);
PPC_FUNC_IMPL(__imp__sub_8254611C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82546120"))) PPC_WEAK_FUNC(sub_82546120);
PPC_FUNC_IMPL(__imp__sub_82546120) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lwz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r5,r4,1
	ctx.r5.s64 = ctx.r4.s64 + 1;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// mullw r4,r8,r4
	ctx.r4.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r4.s32);
	// lfs f0,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	f0.f64 = double(temp.f32);
	// lfs f13,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r9,r4,29,3,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 29) & 0x1FFFFFFC;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// rlwinm r9,r8,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// mullw r8,r5,r31
	ctx.r8.s64 = int64_t(ctx.r5.s32) * int64_t(r31.s32);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rldicr r5,r5,32,63
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// rlwinm r11,r8,29,3,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 29) & 0x1FFFFFFC;
	// clrldi r4,r4,59
	ctx.r4.u64 = ctx.r4.u64 & 0x1F;
	// or r5,r5,r30
	ctx.r5.u64 = ctx.r5.u64 | r30.u64;
	// addi r7,r7,1576
	ctx.r7.s64 = ctx.r7.s64 + 1576;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// srd r4,r5,r4
	ctx.r4.u64 = ctx.r4.u8 & 0x40 ? 0 : (ctx.r5.u64 >> (ctx.r4.u8 & 0x7F));
	// lwzx r9,r9,r7
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// rotlwi r10,r4,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r4.u32, 0);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrldi r8,r8,59
	ctx.r8.u64 = ctx.r8.u64 & 0x1F;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// and r11,r10,r9
	r11.u64 = ctx.r10.u64 & ctx.r9.u64;
	// rldicr r10,r5,32,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// clrldi r9,r11,32
	ctx.r9.u64 = r11.u64 & 0xFFFFFFFF;
	// or r4,r10,r4
	ctx.r4.u64 = ctx.r10.u64 | ctx.r4.u64;
	// std r9,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r9.u64);
	// rlwinm r5,r31,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// srd r3,r4,r8
	ctx.r3.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r4.u64 >> (ctx.r8.u8 & 0x7F));
	// lwzx r11,r5,r7
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// rotlwi r10,r3,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// and r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & r11.u64;
	// lfd f12,-32(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// clrldi r8,r9,32
	ctx.r8.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// std r8,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r8.u64);
	// lfd f10,-32(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// frsp f7,f11
	ctx.f7.f64 = double(float(ctx.f11.f64));
	// fmadds f6,f8,f0,f13
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f13.f64));
	// fmadds f5,f7,f0,f13
	ctx.f5.f64 = double(float(ctx.f7.f64 * f0.f64 + ctx.f13.f64));
	// fsubs f4,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f5.f64));
	// fmadds f3,f4,f1,f5
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f1.f64 + ctx.f5.f64));
	// stfs f3,0(r6)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82546200"))) PPC_WEAK_FUNC(sub_82546200);
PPC_FUNC_IMPL(__imp__sub_82546200) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// lfd f0,0(r6)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r6.u32 + 0);
	// lfd f13,8(r6)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r6.u32 + 8);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// lfs f10,20(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f9.f64 = double(temp.f32);
	// frsp f8,f12
	ctx.f8.f64 = double(float(ctx.f12.f64));
	// frsp f7,f11
	ctx.f7.f64 = double(float(ctx.f11.f64));
	// fmadds f6,f8,f10,f9
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f10.f64 + ctx.f9.f64));
	// fmadds f5,f7,f10,f9
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 + ctx.f9.f64));
	// fsubs f4,f5,f6
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f6.f64));
	// fmadds f1,f4,f1,f6
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f1.f64 + ctx.f6.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82546234"))) PPC_WEAK_FUNC(sub_82546234);
PPC_FUNC_IMPL(__imp__sub_82546234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82546238"))) PPC_WEAK_FUNC(sub_82546238);
PPC_FUNC_IMPL(__imp__sub_82546238) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91fc
	ctx.lr = 0x82546240;
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x823dba38
	ctx.lr = 0x8254625C;
	sub_823DBA38(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,32664(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32664);
	f0.f64 = double(temp.f32);
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwz r31,84(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r10,r31
	ctx.r10.s64 = r31.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// fsubs f31,f31,f9
	f31.f64 = double(float(f31.f64 - ctx.f9.f64));
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x825462b8
	if (!cr6.gt) goto loc_825462B8;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_82546298:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825460a0
	ctx.lr = 0x825462A4;
	sub_825460A0(ctx, base);
	// stfs f1,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_825462B8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,8884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x82546298
	if (!cr6.gt) goto loc_82546298;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825460a0
	ctx.lr = 0x825462D4;
	sub_825460A0(ctx, base);
	// addi r4,r31,1
	ctx.r4.s64 = r31.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// bl 0x825460a0
	ctx.lr = 0x825462E4;
	sub_825460A0(ctx, base);
	// fsubs f0,f1,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 - f30.f64));
	// fmadds f13,f0,f31,f30
	ctx.f13.f64 = double(float(f0.f64 * f31.f64 + f30.f64));
	// stfs f13,0(r29)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82546300"))) PPC_WEAK_FUNC(sub_82546300);
PPC_FUNC_IMPL(__imp__sub_82546300) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mullw r9,r11,r10
	ctx.r9.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// clrlwi r8,r9,27
	ctx.r8.u64 = ctx.r9.u32 & 0x1F;
	// rlwinm r11,r9,27,5,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82546320
	if (cr6.eq) goto loc_82546320;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_82546320:
	// addi r11,r11,7
	r11.s64 = r11.s64 + 7;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8254632C"))) PPC_WEAK_FUNC(sub_8254632C);
PPC_FUNC_IMPL(__imp__sub_8254632C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82546330"))) PPC_WEAK_FUNC(sub_82546330);
PPC_FUNC_IMPL(__imp__sub_82546330) {
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
	ctx.lr = 0x82546338;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82130000
	ctx.lr = 0x82546348;
	sub_82130000(ctx, base);
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// addi r28,r30,20
	r28.s64 = r30.s64 + 20;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8254637c
	if (cr6.eq) goto loc_8254637C;
	// bl 0x821be710
	ctx.lr = 0x82546378;
	sub_821BE710(ctx, base);
	// b 0x82546380
	goto loc_82546380;
loc_8254637C:
	// bl 0x821be7e8
	ctx.lr = 0x82546380;
	sub_821BE7E8(ctx, base);
loc_82546380:
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// addi r4,r30,24
	ctx.r4.s64 = r30.s64 + 24;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x825463b0
	if (cr6.eq) goto loc_825463B0;
	// bl 0x821be710
	ctx.lr = 0x825463AC;
	sub_821BE710(ctx, base);
	// b 0x825463b4
	goto loc_825463B4;
loc_825463B0:
	// bl 0x821be7e8
	ctx.lr = 0x825463B4;
	sub_821BE7E8(ctx, base);
loc_825463B4:
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// blt cr6,0x825463d4
	if (cr6.lt) goto loc_825463D4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x8253bfd0
	ctx.lr = 0x825463CC;
	sub_8253BFD0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_825463D4:
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82546404
	if (cr6.eq) goto loc_82546404;
	// bl 0x821be6a8
	ctx.lr = 0x82546400;
	sub_821BE6A8(ctx, base);
	// b 0x82546408
	goto loc_82546408;
loc_82546404:
	// bl 0x821be780
	ctx.lr = 0x82546408;
	sub_821BE780(ctx, base);
loc_82546408:
	// addi r29,r30,8
	r29.s64 = r30.s64 + 8;
	// lhz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82543078
	ctx.lr = 0x8254641C;
	sub_82543078(ctx, base);
	// lhz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82546480
	if (cr6.eq) goto loc_82546480;
loc_8254642C:
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r4,r1,82
	ctx.r4.s64 = ctx.r1.s64 + 82;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8254645c
	if (cr6.eq) goto loc_8254645C;
	// bl 0x821be6a8
	ctx.lr = 0x82546458;
	sub_821BE6A8(ctx, base);
	// b 0x82546460
	goto loc_82546460;
loc_8254645C:
	// bl 0x821be780
	ctx.lr = 0x82546460;
	sub_821BE780(ctx, base);
loc_82546460:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lhz r5,82(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82542ee0
	ctx.lr = 0x82546470;
	sub_82542EE0(ctx, base);
	// lhz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// blt cr6,0x8254642c
	if (cr6.lt) goto loc_8254642C;
loc_82546480:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lfs f13,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-19960(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -19960);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,0(r28)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8254649C"))) PPC_WEAK_FUNC(sub_8254649C);
PPC_FUNC_IMPL(__imp__sub_8254649C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825464A0"))) PPC_WEAK_FUNC(sub_825464A0);
PPC_FUNC_IMPL(__imp__sub_825464A0) {
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
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x825464A8;
	// stfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f30.u64);
	// stfd f31,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r24,r9
	r24.u64 = ctx.r9.u64;
	// cmpwi cr6,r29,3
	cr6.compare<int32_t>(r29.s32, 3, xer);
	// bge cr6,0x825464e4
	if (!cr6.lt) goto loc_825464E4;
loc_825464D0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_825464E4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// beq cr6,0x825464d0
	if (cr6.eq) goto loc_825464D0;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r26,r5,1
	r26.s64 = ctx.r5.s64 + 1;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// lfs f13,-29632(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29632);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-31400(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31400);
	f0.f64 = double(temp.f32);
	// ble cr6,0x8254653c
	if (!cr6.gt) goto loc_8254653C;
	// rlwinm r9,r26,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8254651C:
	// lfs f12,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// fsubs f10,f0,f12
	ctx.f10.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fsel f13,f11,f13,f12
	ctx.f13.f64 = ctx.f11.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsel f0,f10,f12,f0
	f0.f64 = ctx.f10.f64 >= 0.0 ? ctx.f12.f64 : f0.f64;
	// bne 0x8254651c
	if (!cr0.eq) goto loc_8254651C;
loc_8254653C:
	// fsubs f13,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stfs f0,0(r24)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r24.u32 + 0, temp.u32);
	// stfs f13,0(r27)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
	// fdivs f1,f13,f1
	ctx.f1.f64 = double(float(ctx.f13.f64 / ctx.f1.f64));
	// bl 0x823dbaa8
	ctx.lr = 0x82546550;
	sub_823DBAA8(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lfs f31,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lfs f13,-19956(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -19956);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 - f31.f64));
	// fsel f0,f11,f12,f31
	f0.f64 = ctx.f11.f64 >= 0.0 ? ctx.f12.f64 : f31.f64;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x825464d0
	if (!cr6.lt) goto loc_825464D0;
	// fctidz f0,f0
	f0.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8254659c
	if (cr6.eq) goto loc_8254659C;
loc_8254658C:
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8254658c
	if (!cr6.eq) goto loc_8254658C;
loc_8254659C:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82543078
	ctx.lr = 0x825465AC;
	sub_82543078(ctx, base);
	// subfic r11,r31,32
	xer.ca = r31.u32 <= 32;
	r11.s64 = 32 - r31.s64;
	// li r10,-1
	ctx.r10.s64 = -1;
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	f0.f64 = double(temp.f32);
	// li r31,0
	r31.s64 = 0;
	// srw r28,r10,r11
	r28.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (r11.u8 & 0x3F));
	// clrldi r9,r28,32
	ctx.r9.u64 = r28.u64 & 0xFFFFFFFF;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fdivs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 / ctx.f11.f64));
	// stfs f10,0(r27)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
	// fdivs f30,f31,f10
	f30.f64 = double(float(f31.f64 / ctx.f10.f64));
	// ble cr6,0x82546638
	if (!cr6.gt) goto loc_82546638;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// rlwinm r27,r26,2,0,29
	r27.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f31,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f31.f64 = double(temp.f32);
loc_825465F4:
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fmadds f11,f12,f30,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f30.f64 + f31.f64));
	// fctidz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r5,r28
	cr6.compare<uint32_t>(ctx.r5.u32, r28.u32, xer);
	// ble cr6,0x8254661c
	if (!cr6.gt) goto loc_8254661C;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
loc_8254661C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82542ee0
	ctx.lr = 0x82546628;
	sub_82542EE0(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// add r30,r27,r30
	r30.u64 = r27.u64 + r30.u64;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x825465f4
	if (cr6.lt) goto loc_825465F4;
loc_82546638:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8254664C"))) PPC_WEAK_FUNC(sub_8254664C);
PPC_FUNC_IMPL(__imp__sub_8254664C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82546650"))) PPC_WEAK_FUNC(sub_82546650);
PPC_FUNC_IMPL(__imp__sub_82546650) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x8254666C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82546690
	if (cr6.eq) goto loc_82546690;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82546018
	ctx.lr = 0x8254667C;
	sub_82546018(ctx, base);
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
loc_82546690:
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

__attribute__((alias("__imp__sub_825466A8"))) PPC_WEAK_FUNC(sub_825466A8);
PPC_FUNC_IMPL(__imp__sub_825466A8) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825466f0
	if (cr6.eq) goto loc_825466F0;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r10,r11,-20044
	ctx.r10.s64 = r11.s64 + -20044;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x825466f0
	if (cr6.eq) goto loc_825466F0;
	// bl 0x8217d890
	ctx.lr = 0x825466E4;
	sub_8217D890(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_825466F0:
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

__attribute__((alias("__imp__sub_82546704"))) PPC_WEAK_FUNC(sub_82546704);
PPC_FUNC_IMPL(__imp__sub_82546704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82546708"))) PPC_WEAK_FUNC(sub_82546708);
PPC_FUNC_IMPL(__imp__sub_82546708) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r9,r11,24
	ctx.r9.s64 = r11.s64 + 24;
	// addi r8,r11,20
	ctx.r8.s64 = r11.s64 + 20;
	// addi r7,r11,8
	ctx.r7.s64 = r11.s64 + 8;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// b 0x825464a0
	sub_825464A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82546728"))) PPC_WEAK_FUNC(sub_82546728);
PPC_FUNC_IMPL(__imp__sub_82546728) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lhz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// clrlwi r9,r11,27
	ctx.r9.u64 = r11.u32 & 0x1F;
	// rlwinm r11,r11,27,5,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r9,r7,1
	ctx.r9.u64 = ctx.r7.u64 ^ 1;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r6,r11,7
	ctx.r6.s64 = r11.s64 + 7;
	// rlwinm r3,r6,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82546758"))) PPC_WEAK_FUNC(sub_82546758);
PPC_FUNC_IMPL(__imp__sub_82546758) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82546760;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// lhz r27,12(r28)
	r27.u64 = PPC_LOAD_U16(r28.u32 + 12);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82546808
	if (!cr6.gt) goto loc_82546808;
	// lbz r30,24(r28)
	r30.u64 = PPC_LOAD_U8(r28.u32 + 24);
	// addi r31,r28,16
	r31.s64 = r28.s64 + 16;
loc_82546788:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825431a0
	ctx.lr = 0x82546794;
	sub_825431A0(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82543218
	ctx.lr = 0x825467B4;
	sub_82543218(ctx, base);
	// slw r9,r25,r30
	ctx.r9.u64 = r30.u8 & 0x20 ? 0 : (r25.u32 << (r30.u8 & 0x3F));
	// or r11,r3,r9
	r11.u64 = ctx.r3.u64 | ctx.r9.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x825467f4
	if (cr6.eq) goto loc_825467F4;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r6,r10,29,3,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r7,r10,27
	ctx.r7.u64 = ctx.r10.u32 & 0x1F;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// lwzx r4,r6,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// srw r3,r4,r7
	ctx.r3.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r4.u32 >> (ctx.r7.u8 & 0x3F));
	// clrlwi r10,r3,31
	ctx.r10.u64 = ctx.r3.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x825467f4
	if (cr6.eq) goto loc_825467F4;
	// neg r11,r11
	r11.s64 = -r11.s64;
loc_825467F4:
	// subf. r26,r11,r26
	r26.s64 = r26.s64 - r11.s64;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// blt 0x82546820
	if (cr0.lt) goto loc_82546820;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// blt cr6,0x82546788
	if (cr6.lt) goto loc_82546788;
loc_82546808:
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// rlwinm r10,r27,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r3,-4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82546820:
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82546834"))) PPC_WEAK_FUNC(sub_82546834);
PPC_FUNC_IMPL(__imp__sub_82546834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82546838"))) PPC_WEAK_FUNC(sub_82546838);
PPC_FUNC_IMPL(__imp__sub_82546838) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r9,r11,-24636
	ctx.r9.s64 = r11.s64 + -24636;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// li r11,0
	r11.s64 = 0;
	// addi r8,r10,-19676
	ctx.r8.s64 = ctx.r10.s64 + -19676;
	// lbz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// stb r7,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r7.u8);
	// addi r4,r30,8
	ctx.r4.s64 = r30.s64 + 8;
	// lbz r6,5(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// stb r6,5(r31)
	PPC_STORE_U8(r31.u32 + 5, ctx.r6.u8);
	// lhz r5,6(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// sth r5,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r5.u16);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// sth r11,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r11.u16);
	// sth r11,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r11.u16);
	// bl 0x826c7480
	ctx.lr = 0x825468A0;
	sub_826C7480(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// bl 0x825433e8
	ctx.lr = 0x825468AC;
	sub_825433E8(ctx, base);
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

__attribute__((alias("__imp__sub_825468C8"))) PPC_WEAK_FUNC(sub_825468C8);
PPC_FUNC_IMPL(__imp__sub_825468C8) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x825468D0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// blt cr6,0x825468f4
	if (cr6.lt) goto loc_825468F4;
	// addi r26,r4,1
	r26.s64 = ctx.r4.s64 + 1;
loc_825468F4:
	// lhz r28,12(r27)
	r28.u64 = PPC_LOAD_U16(r27.u32 + 12);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// ble cr6,0x82546990
	if (!cr6.gt) goto loc_82546990;
	// lbz r30,24(r27)
	r30.u64 = PPC_LOAD_U8(r27.u32 + 24);
	// addi r31,r27,16
	r31.s64 = r27.s64 + 16;
loc_82546910:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825431a0
	ctx.lr = 0x8254691C;
	sub_825431A0(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82543218
	ctx.lr = 0x8254693C;
	sub_82543218(ctx, base);
	// slw r9,r24,r30
	ctx.r9.u64 = r30.u8 & 0x20 ? 0 : (r24.u32 << (r30.u8 & 0x3F));
	// or r11,r3,r9
	r11.u64 = ctx.r3.u64 | ctx.r9.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8254697c
	if (cr6.eq) goto loc_8254697C;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r6,r10,29,3,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r7,r10,27
	ctx.r7.u64 = ctx.r10.u32 & 0x1F;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// lwzx r4,r6,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// srw r3,r4,r7
	ctx.r3.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r4.u32 >> (ctx.r7.u8 & 0x3F));
	// clrlwi r10,r3,31
	ctx.r10.u64 = ctx.r3.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8254697c
	if (cr6.eq) goto loc_8254697C;
	// neg r11,r11
	r11.s64 = -r11.s64;
loc_8254697C:
	// subf. r26,r11,r26
	r26.s64 = r26.s64 - r11.s64;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// blt 0x825469ac
	if (cr0.lt) goto loc_825469AC;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r28
	cr6.compare<int32_t>(r29.s32, r28.s32, xer);
	// blt cr6,0x82546910
	if (cr6.lt) goto loc_82546910;
loc_82546990:
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// rlwinm r10,r28,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// stw r10,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_825469AC:
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// stw r9,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r9.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_825469C4"))) PPC_WEAK_FUNC(sub_825469C4);
PPC_FUNC_IMPL(__imp__sub_825469C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825469C8"))) PPC_WEAK_FUNC(sub_825469C8);
PPC_FUNC_IMPL(__imp__sub_825469C8) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-19676
	ctx.r10.s64 = r11.s64 + -19676;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82546a10
	if (cr6.eq) goto loc_82546A10;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82546A04;
	sub_8217D890(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_82546A10:
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82546a30
	if (cr6.eq) goto loc_82546A30;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x82546A24;
	sub_8217D890(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
loc_82546A30:
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

__attribute__((alias("__imp__sub_82546A4C"))) PPC_WEAK_FUNC(sub_82546A4C);
PPC_FUNC_IMPL(__imp__sub_82546A4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82546A50"))) PPC_WEAK_FUNC(sub_82546A50);
PPC_FUNC_IMPL(__imp__sub_82546A50) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 + f0.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82546758
	ctx.lr = 0x82546A80;
	sub_82546758(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_82546A98"))) PPC_WEAK_FUNC(sub_82546A98);
PPC_FUNC_IMPL(__imp__sub_82546A98) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82546AA0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82130000
	ctx.lr = 0x82546AB0;
	sub_82130000(ctx, base);
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// lhz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// subfic r8,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r8.s64 = 0 - ctx.r9.s64;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// sth r10,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, ctx.r10.u16);
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82546ae8
	if (cr6.eq) goto loc_82546AE8;
	// bl 0x821be6a8
	ctx.lr = 0x82546AE4;
	sub_821BE6A8(ctx, base);
	// b 0x82546aec
	goto loc_82546AEC;
loc_82546AE8:
	// bl 0x821be780
	ctx.lr = 0x82546AEC;
	sub_821BE780(ctx, base);
loc_82546AEC:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82546b14
	if (cr6.eq) goto loc_82546B14;
	// addi r3,r29,8
	ctx.r3.s64 = r29.s64 + 8;
	// lhz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// bl 0x8247bb70
	ctx.lr = 0x82546B14;
	sub_8247BB70(ctx, base);
loc_82546B14:
	// lhz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// li r27,0
	r27.s64 = 0;
	// mr r28,r27
	r28.u64 = r27.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82546bc0
	if (cr6.eq) goto loc_82546BC0;
	// mr r31,r27
	r31.u64 = r27.u64;
loc_82546B2C:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r27.u32);
	// clrlwi r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82546b58
	if (!cr6.eq) goto loc_82546B58;
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwzx r9,r10,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
loc_82546B58:
	// subfic r11,r11,0
	xer.ca = r11.u32 <= 0;
	r11.s64 = 0 - r11.s64;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82546b80
	if (cr6.eq) goto loc_82546B80;
	// bl 0x821be710
	ctx.lr = 0x82546B7C;
	sub_821BE710(ctx, base);
	// b 0x82546b84
	goto loc_82546B84;
loc_82546B80:
	// bl 0x821be7e8
	ctx.lr = 0x82546B84;
	sub_821BE7E8(ctx, base);
loc_82546B84:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82546bac
	if (cr6.eq) goto loc_82546BAC;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stwx r10,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r10.u32);
loc_82546BAC:
	// lhz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r28,r10
	cr6.compare<int32_t>(r28.s32, ctx.r10.s32, xer);
	// blt cr6,0x82546b2c
	if (cr6.lt) goto loc_82546B2C;
loc_82546BC0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// bl 0x8253c108
	ctx.lr = 0x82546BCC;
	sub_8253C108(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82546BD4"))) PPC_WEAK_FUNC(sub_82546BD4);
PPC_FUNC_IMPL(__imp__sub_82546BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82546BD8"))) PPC_WEAK_FUNC(sub_82546BD8);
PPC_FUNC_IMPL(__imp__sub_82546BD8) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x82546BF4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82546c18
	if (cr6.eq) goto loc_82546C18;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82546838
	ctx.lr = 0x82546C04;
	sub_82546838(ctx, base);
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
loc_82546C18:
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

__attribute__((alias("__imp__sub_82546C30"))) PPC_WEAK_FUNC(sub_82546C30);
PPC_FUNC_IMPL(__imp__sub_82546C30) {
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
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x82546C44;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82546c8c
	if (cr6.eq) goto loc_82546C8C;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r10,12
	ctx.r10.s64 = 12;
	// addi r9,r11,-19676
	ctx.r9.s64 = r11.s64 + -19676;
	// li r11,0
	r11.s64 = 0;
	// stb r10,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r10.u8);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
	// sth r11,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r11.u16);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stb r11,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82546C8C:
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

__attribute__((alias("__imp__sub_82546CA0"))) PPC_WEAK_FUNC(sub_82546CA0);
PPC_FUNC_IMPL(__imp__sub_82546CA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x825469c8
	sub_825469C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82546CAC"))) PPC_WEAK_FUNC(sub_82546CAC);
PPC_FUNC_IMPL(__imp__sub_82546CAC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82546CB0"))) PPC_WEAK_FUNC(sub_82546CB0);
PPC_FUNC_IMPL(__imp__sub_82546CB0) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-19676
	ctx.r10.s64 = r11.s64 + -19676;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x82546CE0;
	sub_82130588(ctx, base);
	// lhz r9,14(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82546cf4
	if (cr6.eq) goto loc_82546CF4;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x82546CF4;
	sub_82130588(ctx, base);
loc_82546CF4:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// clrlwi r10,r30,31
	ctx.r10.u64 = r30.u32 & 0x1;
	// addi r9,r11,-24636
	ctx.r9.s64 = r11.s64 + -24636;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x82546d18
	if (cr6.eq) goto loc_82546D18;
	// bl 0x82130588
	ctx.lr = 0x82546D14;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82546D18:
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

__attribute__((alias("__imp__sub_82546D30"))) PPC_WEAK_FUNC(sub_82546D30);
PPC_FUNC_IMPL(__imp__sub_82546D30) {
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
	ctx.lr = 0x82546D38;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r5,2
	cr6.compare<int32_t>(ctx.r5.s32, 2, xer);
	// bge cr6,0x82546d54
	if (!cr6.lt) goto loc_82546D54;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82546D54:
	// li r26,0
	r26.s64 = 0;
	// lwz r31,0(r4)
	r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// li r30,1
	r30.s64 = 1;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// cmpwi cr6,r5,1
	cr6.compare<int32_t>(ctx.r5.s32, 1, xer);
	// sth r26,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r26.u16);
	// sth r26,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r26.u16);
	// ble cr6,0x82546dc8
	if (!cr6.gt) goto loc_82546DC8;
	// addi r29,r4,4
	r29.s64 = ctx.r4.s64 + 4;
	// addi r28,r5,-1
	r28.s64 = ctx.r5.s64 + -1;
loc_82546D7C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bne cr6,0x82546d90
	if (!cr6.eq) goto loc_82546D90;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// b 0x82546dbc
	goto loc_82546DBC;
loc_82546D90:
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r27,8
	ctx.r3.s64 = r27.s64 + 8;
	// bl 0x8262e420
	ctx.lr = 0x82546D9C;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// bl 0x8262e420
	ctx.lr = 0x82546DB0;
	sub_8262E420(ctx, base);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r30,1
	r30.s64 = 1;
loc_82546DBC:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x82546d7c
	if (!cr0.eq) goto loc_82546D7C;
loc_82546DC8:
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r27,8
	ctx.r3.s64 = r27.s64 + 8;
	// bl 0x8262e420
	ctx.lr = 0x82546DD4;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// bl 0x8262e420
	ctx.lr = 0x82546DE8;
	sub_8262E420(ctx, base);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// li r29,-1
	r29.s64 = -1;
	// mr r28,r26
	r28.u64 = r26.u64;
	// li r31,4
	r31.s64 = 4;
	// li r30,6
	r30.s64 = 6;
loc_82546DFC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82543128
	ctx.lr = 0x82546E08;
	sub_82543128(ctx, base);
	// cmplw cr6,r3,r29
	cr6.compare<uint32_t>(ctx.r3.u32, r29.u32, xer);
	// bge cr6,0x82546e18
	if (!cr6.lt) goto loc_82546E18;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r31
	r28.u64 = r31.u64;
loc_82546E18:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// rotlwi r31,r31,1
	r31.u64 = __builtin_rotateleft32(r31.u32, 1);
	// bne 0x82546dfc
	if (!cr0.eq) goto loc_82546DFC;
	// addi r31,r27,16
	r31.s64 = r27.s64 + 16;
	// stb r26,24(r27)
	PPC_STORE_U8(r27.u32 + 24, r26.u8);
	// mr r11,r28
	r11.u64 = r28.u64;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
loc_82546E34:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm r11,r11,31,1,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// bne cr6,0x82546e34
	if (!cr6.eq) goto loc_82546E34;
	// addi r11,r10,255
	r11.s64 = ctx.r10.s64 + 255;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stb r11,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r11.u8);
	// bl 0x82130588
	ctx.lr = 0x82546E5C;
	sub_82130588(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82543938
	ctx.lr = 0x82546E68;
	sub_82543938(ctx, base);
	// lhz r8,86(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82546e7c
	if (cr6.eq) goto loc_82546E7C;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82130588
	ctx.lr = 0x82546E7C;
	sub_82130588(ctx, base);
loc_82546E7C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82546E88"))) PPC_WEAK_FUNC(sub_82546E88);
PPC_FUNC_IMPL(__imp__sub_82546E88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r11,-32472
	ctx.r3.s64 = r11.s64 + -32472;
	// b 0x8253dd10
	sub_8253DD10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82546E94"))) PPC_WEAK_FUNC(sub_82546E94);
PPC_FUNC_IMPL(__imp__sub_82546E94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82546E98"))) PPC_WEAK_FUNC(sub_82546E98);
PPC_FUNC_IMPL(__imp__sub_82546E98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r11,-32472
	ctx.r3.s64 = r11.s64 + -32472;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82546EA4"))) PPC_WEAK_FUNC(sub_82546EA4);
PPC_FUNC_IMPL(__imp__sub_82546EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82546EA8"))) PPC_WEAK_FUNC(sub_82546EA8);
PPC_FUNC_IMPL(__imp__sub_82546EA8) {
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
	// li r30,0
	r30.s64 = 0;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82546ee8
	if (cr6.eq) goto loc_82546EE8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82546EE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
loc_82546EE8:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82546f0c
	if (cr6.eq) goto loc_82546F0C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82546F08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
loc_82546F0C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8253daf8
	ctx.lr = 0x82546F14;
	sub_8253DAF8(ctx, base);
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

__attribute__((alias("__imp__sub_82546F2C"))) PPC_WEAK_FUNC(sub_82546F2C);
PPC_FUNC_IMPL(__imp__sub_82546F2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82546F30"))) PPC_WEAK_FUNC(sub_82546F30);
PPC_FUNC_IMPL(__imp__sub_82546F30) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// b 0x825290d8
	sub_825290D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82546F38"))) PPC_WEAK_FUNC(sub_82546F38);
PPC_FUNC_IMPL(__imp__sub_82546F38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x825290d8
	sub_825290D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82546F48"))) PPC_WEAK_FUNC(sub_82546F48);
PPC_FUNC_IMPL(__imp__sub_82546F48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lwz r4,12(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x825278e8
	sub_825278E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82546F60"))) PPC_WEAK_FUNC(sub_82546F60);
PPC_FUNC_IMPL(__imp__sub_82546F60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lwz r4,12(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x825290d8
	sub_825290D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82546F70"))) PPC_WEAK_FUNC(sub_82546F70);
PPC_FUNC_IMPL(__imp__sub_82546F70) {
	PPC_FUNC_PROLOGUE();
	// lwz r4,12(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// b 0x825290d8
	sub_825290D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82546F80"))) PPC_WEAK_FUNC(sub_82546F80);
PPC_FUNC_IMPL(__imp__sub_82546F80) {
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
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x82546F9C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82546ff0
	if (cr6.eq) goto loc_82546FF0;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// addi r9,r11,-24092
	ctx.r9.s64 = r11.s64 + -24092;
	// addi r8,r10,-19308
	ctx.r8.s64 = ctx.r10.s64 + -19308;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r5,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r5.u32);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
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
loc_82546FF0:
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

__attribute__((alias("__imp__sub_82547008"))) PPC_WEAK_FUNC(sub_82547008);
PPC_FUNC_IMPL(__imp__sub_82547008) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-19308
	ctx.r10.s64 = r11.s64 + -19308;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82546ea8
	ctx.lr = 0x82547034;
	sub_82546EA8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8253da60
	ctx.lr = 0x8254703C;
	sub_8253DA60(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82547054
	if (cr6.eq) goto loc_82547054;
	// bl 0x82130588
	ctx.lr = 0x82547050;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82547054:
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

__attribute__((alias("__imp__sub_8254706C"))) PPC_WEAK_FUNC(sub_8254706C);
PPC_FUNC_IMPL(__imp__sub_8254706C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82547070"))) PPC_WEAK_FUNC(sub_82547070);
PPC_FUNC_IMPL(__imp__sub_82547070) {
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
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x82547088;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825470d0
	if (cr6.eq) goto loc_825470D0;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x8253da90
	ctx.lr = 0x8254709C;
	sub_8253DA90(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// addi r10,r11,-19308
	ctx.r10.s64 = r11.s64 + -19308;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82323eb8
	ctx.lr = 0x825470B0;
	sub_82323EB8(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82323eb8
	ctx.lr = 0x825470B8;
	sub_82323EB8(ctx, base);
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
loc_825470D0:
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

__attribute__((alias("__imp__sub_825470E8"))) PPC_WEAK_FUNC(sub_825470E8);
PPC_FUNC_IMPL(__imp__sub_825470E8) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8254712c
	if (cr6.eq) goto loc_8254712C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8253da90
	ctx.lr = 0x82547110;
	sub_8253DA90(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// addi r10,r11,-19308
	ctx.r10.s64 = r11.s64 + -19308;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82323eb8
	ctx.lr = 0x82547124;
	sub_82323EB8(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82323eb8
	ctx.lr = 0x8254712C;
	sub_82323EB8(ctx, base);
loc_8254712C:
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

__attribute__((alias("__imp__sub_82547140"))) PPC_WEAK_FUNC(sub_82547140);
PPC_FUNC_IMPL(__imp__sub_82547140) {
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
	ctx.lr = 0x82547148;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addis r31,r29,1
	r31.s64 = r29.s64 + 65536;
	// addis r30,r29,1
	r30.s64 = r29.s64 + 65536;
	// addi r31,r31,-6032
	r31.s64 = r31.s64 + -6032;
	// addi r30,r30,-6028
	r30.s64 = r30.s64 + -6028;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bne cr6,0x82547190
	if (!cr6.eq) goto loc_82547190;
loc_82547174:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c91b8
	ctx.lr = 0x8254717C;
	sub_821C91B8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x82547174
	if (cr6.eq) goto loc_82547174;
loc_82547190:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r8,r11,14873
	ctx.r8.s64 = r11.s64 + 14873;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r7,r29
	PPC_STORE_U32(ctx.r7.u32 + r29.u32, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_825471B8"))) PPC_WEAK_FUNC(sub_825471B8);
PPC_FUNC_IMPL(__imp__sub_825471B8) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x825471C0;
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	r11.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r9,r11,59504
	ctx.r9.u64 = r11.u64 | 59504;
	// lis r10,21845
	ctx.r10.s64 = 1431633920;
	// addis r30,r31,1
	r30.s64 = r31.s64 + 65536;
	// ori r8,r10,21846
	ctx.r8.u64 = ctx.r10.u64 | 21846;
	// addi r30,r30,-6028
	r30.s64 = r30.s64 + -6028;
	// lwzx r11,r31,r9
	r11.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// addi r7,r11,2
	ctx.r7.s64 = r11.s64 + 2;
	// mulhw r11,r7,r8
	r11.s64 = (int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32)) >> 32;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// subf r5,r6,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r6.s64;
	// stw r5,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r5.u32);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r11,r4,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addis r4,r11,1
	ctx.r4.s64 = r11.s64 + 65536;
	// addi r4,r4,-6140
	ctx.r4.s64 = ctx.r4.s64 + -6140;
	// bl 0x821c8fe0
	ctx.lr = 0x82547228;
	sub_821C8FE0(ctx, base);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addis r4,r31,1
	ctx.r4.s64 = r31.s64 + 65536;
	// addi r9,r10,19856
	ctx.r9.s64 = ctx.r10.s64 + 19856;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-6020
	ctx.r4.s64 = ctx.r4.s64 + -6020;
	// lwz r25,72(r9)
	r25.u64 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	// lfs f30,808(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 808);
	f30.f64 = double(temp.f32);
	// bl 0x821c8fe0
	ctx.lr = 0x82547248;
	sub_821C8FE0(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r8,r11,14873
	ctx.r8.s64 = r11.s64 + 14873;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// ble cr6,0x825472b0
	if (!cr6.gt) goto loc_825472B0;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r10,14873
	ctx.r10.s64 = ctx.r10.s64 + 14873;
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r9,13,0,18
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 13) & 0xFFFFE000;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lwzx r4,r8,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// bl 0x825484c8
	ctx.lr = 0x82547288;
	sub_825484C8(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addis r7,r31,1
	ctx.r7.s64 = r31.s64 + 65536;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,14873
	ctx.r5.s64 = r11.s64 + 14873;
	// addi r7,r7,-6024
	ctx.r7.s64 = ctx.r7.s64 + -6024;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r6,r4,r31
	PPC_STORE_U32(ctx.r4.u32 + r31.u32, ctx.r6.u32);
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// stw r3,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r3.u32);
loc_825472B0:
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8254739c
	if (cr6.eq) goto loc_8254739C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addis r26,r31,1
	r26.s64 = r31.s64 + 65536;
	// li r29,0
	r29.s64 = 0;
	// addi r26,r26,-3940
	r26.s64 = r26.s64 + -3940;
	// lis r27,-32125
	r27.s64 = -2105344000;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_825472D4:
	// extsh r10,r28
	ctx.r10.s64 = r28.s16;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x825472f0
	if (cr6.eq) goto loc_825472F0;
	// lwz r11,26656(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 26656);
	// mulli r10,r10,136
	ctx.r10.s64 = ctx.r10.s64 * 136;
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// b 0x825472f4
	goto loc_825472F4;
loc_825472F0:
	// li r30,0
	r30.s64 = 0;
loc_825472F4:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lhzx r10,r29,r11
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + r11.u32);
	// extsh r11,r10
	r11.s64 = ctx.r10.s16;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x8254735c
	if (cr6.eq) goto loc_8254735C;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8254735c
	if (cr6.eq) goto loc_8254735C;
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// srawi r5,r11,6
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3F) != 0);
	ctx.r5.s64 = r11.s32 >> 6;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82548888
	ctx.lr = 0x82547330;
	sub_82548888(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82149478
	ctx.lr = 0x8254733C;
	sub_82149478(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lhz r4,100(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 100);
	// bl 0x82149488
	ctx.lr = 0x82547348;
	sub_82149488(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lhz r4,102(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 102);
	// bl 0x82149808
	ctx.lr = 0x82547354;
	sub_82149808(ctx, base);
	// lhz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 104);
	// b 0x82547384
	goto loc_82547384;
loc_8254735C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82149478
	ctx.lr = 0x82547368;
	sub_82149478(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82149488
	ctx.lr = 0x82547374;
	sub_82149488(ctx, base);
	// li r4,23900
	ctx.r4.s64 = 23900;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82149808
	ctx.lr = 0x82547380;
	sub_82149808(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
loc_82547384:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82149810
	ctx.lr = 0x8254738C;
	sub_82149810(ctx, base);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,2
	r29.s64 = r29.s64 + 2;
	// cmplw cr6,r28,r25
	cr6.compare<uint32_t>(r28.u32, r25.u32, xer);
	// blt cr6,0x825472d4
	if (cr6.lt) goto loc_825472D4;
loc_8254739C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x825473A4;
	sub_821C9030(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x825473AC;
	sub_821C9030(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_825473BC"))) PPC_WEAK_FUNC(sub_825473BC);
PPC_FUNC_IMPL(__imp__sub_825473BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825473C0"))) PPC_WEAK_FUNC(sub_825473C0);
PPC_FUNC_IMPL(__imp__sub_825473C0) {
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
	ctx.lr = 0x825473C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,2
	r30.s64 = 2;
	// addis r29,r31,1
	r29.s64 = r31.s64 + 65536;
	// addi r29,r29,-6140
	r29.s64 = r29.s64 + -6140;
loc_825473DC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c8ed8
	ctx.lr = 0x825473E4;
	sub_821C8ED8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,32
	r29.s64 = r29.s64 + 32;
	// bge 0x825473dc
	if (!cr0.lt) goto loc_825473DC;
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,-6020
	ctx.r3.s64 = ctx.r3.s64 + -6020;
	// bl 0x821c8ed8
	ctx.lr = 0x825473FC;
	sub_821C8ED8(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addis r10,r31,1
	ctx.r10.s64 = r31.s64 + 65536;
	// addi r27,r11,19856
	r27.s64 = r11.s64 + 19856;
	// addi r10,r10,-3932
	ctx.r10.s64 = ctx.r10.s64 + -3932;
	// lwz r11,72(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 72);
	// rotlwi r29,r11,0
	r29.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// clrlwi r11,r29,28
	r11.u64 = r29.u32 & 0xF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82547430
	if (cr6.eq) goto loc_82547430;
	// subf r11,r11,r29
	r11.s64 = r29.s64 - r11.s64;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// b 0x82547434
	goto loc_82547434;
loc_82547430:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82547434:
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r5,0
	ctx.r5.s64 = 0;
	// ori r9,r10,61608
	ctx.r9.u64 = ctx.r10.u64 | 61608;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stwx r11,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r11.u32);
	// bl 0x8244d150
	ctx.lr = 0x82547454;
	sub_8244D150(ctx, base);
	// lis r8,0
	ctx.r8.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// ori r7,r8,59392
	ctx.r7.u64 = ctx.r8.u64 | 59392;
	// addis r10,r31,1
	ctx.r10.s64 = r31.s64 + 65536;
	// mr r11,r30
	r11.u64 = r30.u64;
	// addi r10,r10,-8192
	ctx.r10.s64 = ctx.r10.s64 + -8192;
	// stwx r30,r31,r7
	PPC_STORE_U32(r31.u32 + ctx.r7.u32, r30.u32);
loc_82547470:
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r11,512
	cr6.compare<uint32_t>(r11.u32, 512, xer);
	// blt cr6,0x82547470
	if (cr6.lt) goto loc_82547470;
	// lis r11,0
	r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r6,0
	ctx.r6.s64 = 0;
	// addis r28,r31,1
	r28.s64 = r31.s64 + 65536;
	// ori r4,r10,59508
	ctx.r4.u64 = ctx.r10.u64 | 59508;
	// ori r5,r11,59504
	ctx.r5.u64 = r11.u64 | 59504;
	// ori r3,r9,59500
	ctx.r3.u64 = ctx.r9.u64 | 59500;
	// ori r10,r8,59496
	ctx.r10.u64 = ctx.r8.u64 | 59496;
	// ori r9,r7,59492
	ctx.r9.u64 = ctx.r7.u64 | 59492;
	// ori r8,r6,59512
	ctx.r8.u64 = ctx.r6.u64 | 59512;
	// addi r28,r28,-3940
	r28.s64 = r28.s64 + -3940;
	// stwx r30,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, r30.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// stwx r30,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, r30.u32);
	// rlwinm r11,r29,1,28,30
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xE;
	// stwx r30,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r30.u32);
	// stwx r7,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, ctx.r7.u32);
	// rlwinm r4,r29,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
	// stwx r30,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stwx r30,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r30.u32);
	// stw r30,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r30.u32);
	// beq cr6,0x825474f4
	if (cr6.eq) goto loc_825474F4;
	// subf r11,r11,r4
	r11.s64 = ctx.r4.s64 - r11.s64;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
loc_825474F4:
	// lis r11,0
	r11.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// ori r10,r11,61600
	ctx.r10.u64 = r11.u64 | 61600;
	// li r5,16
	ctx.r5.s64 = 16;
	// stwx r4,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, ctx.r4.u32);
	// bl 0x82144a60
	ctx.lr = 0x8254750C;
	sub_82144A60(ctx, base);
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82547538
	if (cr6.eq) goto loc_82547538;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82547524:
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// sthx r8,r10,r9
	PPC_STORE_U16(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u16);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// bne 0x82547524
	if (!cr0.eq) goto loc_82547524;
loc_82547538:
	// addis r9,r31,1
	ctx.r9.s64 = r31.s64 + 65536;
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// addi r9,r9,-5988
	ctx.r9.s64 = ctx.r9.s64 + -5988;
	// addi r11,r11,-24576
	r11.s64 = r11.s64 + -24576;
	// li r10,512
	ctx.r10.s64 = 512;
loc_8254754C:
	// stw r8,-8192(r11)
	PPC_STORE_U32(r11.u32 + -8192, ctx.r8.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stw r8,8192(r11)
	PPC_STORE_U32(r11.u32 + 8192, ctx.r8.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// stw r30,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r30.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x8254754c
	if (!cr0.eq) goto loc_8254754C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82547578"))) PPC_WEAK_FUNC(sub_82547578);
PPC_FUNC_IMPL(__imp__sub_82547578) {
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
	// lis r11,0
	r11.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r10,r11,61596
	ctx.r10.u64 = r11.u64 | 61596;
	// lwzx r4,r31,r10
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x825475b0
	if (cr6.eq) goto loc_825475B0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// bl 0x82144a78
	ctx.lr = 0x825475B0;
	sub_82144A78(ctx, base);
loc_825475B0:
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,-6020
	ctx.r3.s64 = ctx.r3.s64 + -6020;
	// bl 0x82130000
	ctx.lr = 0x825475BC;
	sub_82130000(ctx, base);
	// addis r31,r31,1
	r31.s64 = r31.s64 + 65536;
	// li r30,2
	r30.s64 = 2;
	// addi r31,r31,-6044
	r31.s64 = r31.s64 + -6044;
loc_825475C8:
	// addi r31,r31,-32
	r31.s64 = r31.s64 + -32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x825475D4;
	sub_82130000(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x825475c8
	if (!cr0.lt) goto loc_825475C8;
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

__attribute__((alias("__imp__sub_825475F4"))) PPC_WEAK_FUNC(sub_825475F4);
PPC_FUNC_IMPL(__imp__sub_825475F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825475F8"))) PPC_WEAK_FUNC(sub_825475F8);
PPC_FUNC_IMPL(__imp__sub_825475F8) {
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
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r3,r3,61612
	ctx.r3.u64 = ctx.r3.u64 | 61612;
	// bl 0x82130528
	ctx.lr = 0x82547610;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82547620
	if (cr6.eq) goto loc_82547620;
	// bl 0x825473c0
	ctx.lr = 0x8254761C;
	sub_825473C0(ctx, base);
	// b 0x82547624
	goto loc_82547624;
loc_82547620:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82547624:
	// lis r11,-32114
	r11.s64 = -2104623104;
	// stw r3,-32456(r11)
	PPC_STORE_U32(r11.u32 + -32456, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8254763C"))) PPC_WEAK_FUNC(sub_8254763C);
PPC_FUNC_IMPL(__imp__sub_8254763C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82547640"))) PPC_WEAK_FUNC(sub_82547640);
PPC_FUNC_IMPL(__imp__sub_82547640) {
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
	ctx.lr = 0x82547648;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addis r4,r31,1
	ctx.r4.s64 = r31.s64 + 65536;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-6020
	ctx.r4.s64 = ctx.r4.s64 + -6020;
	// bl 0x821c8fe0
	ctx.lr = 0x82547664;
	sub_821C8FE0(ctx, base);
	// addis r29,r31,1
	r29.s64 = r31.s64 + 65536;
	// addi r29,r29,-6144
	r29.s64 = r29.s64 + -6144;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,512
	cr6.compare<int32_t>(r11.s32, 512, xer);
	// bne cr6,0x8254768c
	if (!cr6.eq) goto loc_8254768C;
loc_82547678:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82547680;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8254768C:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// bl 0x8214a200
	ctx.lr = 0x8254769C;
	sub_8214A200(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82547678
	if (cr6.eq) goto loc_82547678;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r10,-2
	ctx.r10.s64 = -2;
	// addi r9,r11,14336
	ctx.r9.s64 = r11.s64 + 14336;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r11,r31
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// stwx r10,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r10.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r10,r8,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// add. r30,r10,r31
	r30.u64 = ctx.r10.u64 + r31.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// stw r7,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r7.u32);
	// beq 0x825476e0
	if (cr0.eq) goto loc_825476E0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82548638
	ctx.lr = 0x825476E0;
	sub_82548638(ctx, base);
loc_825476E0:
	// stw r28,52(r30)
	PPC_STORE_U32(r30.u32 + 52, r28.u32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r10,136
	ctx.r10.s64 = 136;
	// addis r28,r31,1
	r28.s64 = r31.s64 + 65536;
	// addi r28,r28,-3940
	r28.s64 = r28.s64 + -3940;
	// lwz r11,26656(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 26656);
	// subf r9,r11,r27
	ctx.r9.s64 = r27.s64 - r11.s64;
	// divw r8,r9,r10
	ctx.r8.s32 = ctx.r9.s32 / ctx.r10.s32;
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// sth r7,60(r30)
	PPC_STORE_U16(r30.u32 + 60, ctx.r7.u16);
	// rlwinm r5,r7,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lhzx r3,r5,r4
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r5.u32 + ctx.r4.u32);
	// extsh r11,r3
	r11.s64 = ctx.r3.s16;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82547748
	if (cr6.eq) goto loc_82547748;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r29,r11,r31
	r29.u64 = r11.u64 + r31.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82547748
	if (cr6.eq) goto loc_82547748;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82548708
	ctx.lr = 0x8254773C;
	sub_82548708(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82548738
	ctx.lr = 0x82547748;
	sub_82548738(ctx, base);
loc_82547748:
	// lhz r11,60(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 60);
	// subf r10,r31,r30
	ctx.r10.s64 = r30.s64 - r31.s64;
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// extsh r8,r11
	ctx.r8.s64 = r11.s16;
	// srawi r7,r10,6
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3F) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 6;
	// rlwinm r6,r8,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r7,r6,r9
	PPC_STORE_U16(ctx.r6.u32 + ctx.r9.u32, ctx.r7.u16);
	// bl 0x821c9030
	ctx.lr = 0x8254776C;
	sub_821C9030(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82547778"))) PPC_WEAK_FUNC(sub_82547778);
PPC_FUNC_IMPL(__imp__sub_82547778) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82547780;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addis r4,r30,1
	ctx.r4.s64 = r30.s64 + 65536;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-6020
	ctx.r4.s64 = ctx.r4.s64 + -6020;
	// bl 0x821c8fe0
	ctx.lr = 0x8254779C;
	sub_821C8FE0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82548248
	ctx.lr = 0x825477A4;
	sub_82548248(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82548278
	ctx.lr = 0x825477B0;
	sub_82548278(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x825477c8
	if (cr6.eq) goto loc_825477C8;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82548738
	ctx.lr = 0x825477C8;
	sub_82548738(ctx, base);
loc_825477C8:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x825477e0
	if (cr6.eq) goto loc_825477E0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82548708
	ctx.lr = 0x825477DC;
	sub_82548708(ctx, base);
	// b 0x8254785c
	goto loc_8254785C;
loc_825477E0:
	// lhz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// lis r11,0
	r11.s64 = 0;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// ori r8,r11,61596
	ctx.r8.u64 = r11.u64 | 61596;
	// extsh r7,r10
	ctx.r7.s64 = ctx.r10.s16;
	// beq cr6,0x82547810
	if (cr6.eq) goto loc_82547810;
	// lwzx r3,r30,r8
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + ctx.r8.u32);
	// subf r9,r30,r29
	ctx.r9.s64 = r29.s64 - r30.s64;
	// rlwinm r5,r7,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r6,r9,6
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3F) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 6;
	// sthx r6,r5,r3
	PPC_STORE_U16(ctx.r5.u32 + ctx.r3.u32, ctx.r6.u16);
	// b 0x8254785c
	goto loc_8254785C;
loc_82547810:
	// lwzx r5,r30,r8
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + ctx.r8.u32);
	// rlwinm r6,r7,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// li r9,-1
	ctx.r9.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sthx r9,r6,r5
	PPC_STORE_U16(ctx.r6.u32 + ctx.r5.u32, ctx.r9.u16);
	// bl 0x825482a8
	ctx.lr = 0x82547828;
	sub_825482A8(ctx, base);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lfs f1,3796(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82149478
	ctx.lr = 0x82547838;
	sub_82149478(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82149488
	ctx.lr = 0x82547844;
	sub_82149488(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r4,23900
	ctx.r4.s64 = 23900;
	// bl 0x82149808
	ctx.lr = 0x82547850;
	sub_82149808(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82149810
	ctx.lr = 0x8254785C;
	sub_82149810(ctx, base);
loc_8254785C:
	// addis r10,r30,1
	ctx.r10.s64 = r30.s64 + 65536;
	// subf r9,r30,r31
	ctx.r9.s64 = r31.s64 - r30.s64;
	// addi r10,r10,-6144
	ctx.r10.s64 = ctx.r10.s64 + -6144;
	// srawi r8,r9,6
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3F) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 6;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r7,r11,14336
	ctx.r7.s64 = r11.s64 + 14336;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r8,r6,r30
	PPC_STORE_U32(ctx.r6.u32 + r30.u32, ctx.r8.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8254789C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x825478A4;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_825478AC"))) PPC_WEAK_FUNC(sub_825478AC);
PPC_FUNC_IMPL(__imp__sub_825478AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825478B0"))) PPC_WEAK_FUNC(sub_825478B0);
PPC_FUNC_IMPL(__imp__sub_825478B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x825478B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addis r4,r29,1
	ctx.r4.s64 = r29.s64 + 65536;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-6020
	ctx.r4.s64 = ctx.r4.s64 + -6020;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x825478D8;
	sub_821C8FE0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x825478f8
	if (cr6.eq) goto loc_825478F8;
loc_825478E0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82547778
	ctx.lr = 0x825478EC;
	sub_82547778(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x825478e0
	if (!cr0.eq) goto loc_825478E0;
loc_825478F8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82547900;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82547908"))) PPC_WEAK_FUNC(sub_82547908);
PPC_FUNC_IMPL(__imp__sub_82547908) {
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
	ctx.lr = 0x82547910;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addis r29,r31,1
	r29.s64 = r31.s64 + 65536;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r29,r29,-6032
	r29.s64 = r29.s64 + -6032;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// addis r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 65536;
	// addi r4,r4,-6140
	ctx.r4.s64 = ctx.r4.s64 + -6140;
	// bl 0x821c8fe0
	ctx.lr = 0x82547944;
	sub_821C8FE0(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r9,r11,14873
	ctx.r9.s64 = r11.s64 + 14873;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// cmplwi cr6,r7,512
	cr6.compare<uint32_t>(ctx.r7.u32, 512, xer);
	// blt cr6,0x82547970
	if (cr6.lt) goto loc_82547970;
	// bl 0x821c9030
	ctx.lr = 0x82547964;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82547970:
	// subf r11,r31,r28
	r11.s64 = r28.s64 - r31.s64;
	// lis r10,0
	ctx.r10.s64 = 0;
	// srawi r11,r11,6
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3F) != 0);
	r11.s64 = r11.s32 >> 6;
	// ori r9,r10,59512
	ctx.r9.u64 = ctx.r10.u64 | 59512;
	// addi r8,r11,14887
	ctx.r8.s64 = r11.s64 + 14887;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r31,r9
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// stwx r6,r7,r31
	PPC_STORE_U32(ctx.r7.u32 + r31.u32, ctx.r6.u32);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r4,r10,14873
	ctx.r4.s64 = ctx.r10.s64 + 14873;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r10,9,0,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 9) & 0xFFFFFE00;
	// lwzx r9,r11,r31
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r9,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r8,r10,r31
	ctx.r8.u64 = ctx.r10.u64 + r31.u64;
	// stwx r5,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, ctx.r5.u32);
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r7,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// lwz r6,8(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stw r6,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r6.u32);
	// lwz r5,12(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r5,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r5.u32);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// stwx r4,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r4.u32);
	// bl 0x821c9030
	ctx.lr = 0x825479EC;
	sub_821C9030(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_825479F8"))) PPC_WEAK_FUNC(sub_825479F8);
PPC_FUNC_IMPL(__imp__sub_825479F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister temp{};
	// subf r11,r3,r4
	r11.s64 = ctx.r4.s64 - ctx.r3.s64;
	// lis r10,0
	ctx.r10.s64 = 0;
	// srawi r11,r11,6
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3F) != 0);
	r11.s64 = r11.s32 >> 6;
	// ori r9,r10,59512
	ctx.r9.u64 = ctx.r10.u64 | 59512;
	// addi r8,r11,14887
	ctx.r8.s64 = r11.s64 + 14887;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r3,r9
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r9.u32);
	// lwzx r5,r7,r3
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	// subfc r4,r6,r5
	xer.ca = ctx.r5.u32 >= ctx.r6.u32;
	ctx.r4.s64 = ctx.r5.s64 - ctx.r6.s64;
	// subfe r11,r4,r4
	temp.u8 = (~ctx.r4.u32 + ctx.r4.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r4.u32 + xer.ca < xer.ca);
	r11.u64 = ~ctx.r4.u64 + ctx.r4.u64 + xer.ca;
	xer.ca = temp.u8;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82547A28"))) PPC_WEAK_FUNC(sub_82547A28);
PPC_FUNC_IMPL(__imp__sub_82547A28) {
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
	// lis r30,-32114
	r30.s64 = -2104623104;
	// lwz r31,-32456(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -32456);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82547a5c
	if (cr6.eq) goto loc_82547A5C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82547578
	ctx.lr = 0x82547A54;
	sub_82547578(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82547A5C;
	sub_82130588(ctx, base);
loc_82547A5C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-32456(r30)
	PPC_STORE_U32(r30.u32 + -32456, r11.u32);
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

__attribute__((alias("__imp__sub_82547A7C"))) PPC_WEAK_FUNC(sub_82547A7C);
PPC_FUNC_IMPL(__imp__sub_82547A7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82547A80"))) PPC_WEAK_FUNC(sub_82547A80);
PPC_FUNC_IMPL(__imp__sub_82547A80) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x82547AA0;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82547640
	ctx.lr = 0x82547AAC;
	sub_82547640(ctx, base);
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

__attribute__((alias("__imp__sub_82547AC0"))) PPC_WEAK_FUNC(sub_82547AC0);
PPC_FUNC_IMPL(__imp__sub_82547AC0) {
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
	ctx.lr = 0x82547AC8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// addis r4,r27,1
	ctx.r4.s64 = r27.s64 + 65536;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-6020
	ctx.r4.s64 = ctx.r4.s64 + -6020;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x82547AF0;
	sub_821C8FE0(ctx, base);
	// li r24,0
	r24.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82547b38
	if (cr6.eq) goto loc_82547B38;
	// mr r29,r25
	r29.u64 = r25.u64;
loc_82547B04:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82547640
	ctx.lr = 0x82547B10;
	sub_82547640(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82547b34
	if (cr6.eq) goto loc_82547B34;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// add r30,r30,r26
	r30.u64 = r30.u64 + r26.u64;
	// cmplw cr6,r31,r28
	cr6.compare<uint32_t>(r31.u32, r28.u32, xer);
	// blt cr6,0x82547b04
	if (cr6.lt) goto loc_82547B04;
	// b 0x82547b38
	goto loc_82547B38;
loc_82547B34:
	// li r24,1
	r24.s64 = 1;
loc_82547B38:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82547b7c
	if (cr6.eq) goto loc_82547B7C;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82547b68
	if (cr6.eq) goto loc_82547B68;
	// mr r30,r25
	r30.u64 = r25.u64;
loc_82547B50:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82547778
	ctx.lr = 0x82547B5C;
	sub_82547778(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82547b50
	if (!cr0.eq) goto loc_82547B50;
loc_82547B68:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82547B70;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_82547B7C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x82547B84;
	sub_821C9030(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82547B90"))) PPC_WEAK_FUNC(sub_82547B90);
PPC_FUNC_IMPL(__imp__sub_82547B90) {
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
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-32456(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -32456);
	// bl 0x825479f8
	ctx.lr = 0x82547BB4;
	sub_825479F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82547c3c
	if (!cr6.eq) goto loc_82547C3C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x82547c3c
	if (!cr6.eq) goto loc_82547C3C;
	// lfs f13,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x82547c3c
	if (!cr6.eq) goto loc_82547C3C;
	// lfs f13,36(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x82547c3c
	if (!cr6.eq) goto loc_82547C3C;
	// lfs f13,48(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x82547c3c
	if (!cr6.eq) goto loc_82547C3C;
	// lfs f13,28(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x82547c3c
	if (!cr6.eq) goto loc_82547C3C;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lfs f13,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-18560(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -18560);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x82547c3c
	if (cr6.gt) goto loc_82547C3C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x82547c3c
	if (!cr6.eq) goto loc_82547C3C;
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beq cr6,0x82547c40
	if (cr6.eq) goto loc_82547C40;
loc_82547C3C:
	// li r11,0
	r11.s64 = 0;
loc_82547C40:
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

__attribute__((alias("__imp__sub_82547C58"))) PPC_WEAK_FUNC(sub_82547C58);
PPC_FUNC_IMPL(__imp__sub_82547C58) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// bl 0x821493f8
	ctx.lr = 0x82547C78;
	sub_821493F8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f1,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r3,-32456(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -32456);
	// bl 0x82547908
	ctx.lr = 0x82547C9C;
	sub_82547908(ctx, base);
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

__attribute__((alias("__imp__sub_82547CB0"))) PPC_WEAK_FUNC(sub_82547CB0);
PPC_FUNC_IMPL(__imp__sub_82547CB0) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f1,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r3,-32456(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -32456);
	// bl 0x82547908
	ctx.lr = 0x82547CE8;
	sub_82547908(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82547CF8"))) PPC_WEAK_FUNC(sub_82547CF8);
PPC_FUNC_IMPL(__imp__sub_82547CF8) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f0,11324(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11324);
	f0.f64 = double(temp.f32);
	// lfs f13,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvlx v2,0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx v1,0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// bl 0x821476b0
	ctx.lr = 0x82547D3C;
	sub_821476B0(ctx, base);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// li r5,1
	ctx.r5.s64 = 1;
	// lis r3,-32114
	ctx.r3.s64 = -2104623104;
	// stw r5,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r5.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stvx128 v1,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lfs f0,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r3,-32456(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -32456);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x82547908
	ctx.lr = 0x82547D74;
	sub_82547908(ctx, base);
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

__attribute__((alias("__imp__sub_82547D88"))) PPC_WEAK_FUNC(sub_82547D88);
PPC_FUNC_IMPL(__imp__sub_82547D88) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f1,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r3,-32456(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -32456);
	// bl 0x82547908
	ctx.lr = 0x82547DC0;
	sub_82547908(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82547DD0"))) PPC_WEAK_FUNC(sub_82547DD0);
PPC_FUNC_IMPL(__imp__sub_82547DD0) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lis r9,-32127
	ctx.r9.s64 = -2105475072;
	// li r8,2
	ctx.r8.s64 = 2;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f0,11368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11368);
	f0.f64 = double(temp.f32);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// fsubs f11,f1,f0
	ctx.f11.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f13,-18580(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -18580);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2160(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 2160);
	ctx.f12.f64 = double(temp.f32);
	// fsel f10,f11,f1,f0
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fsel f8,f9,f13,f10
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? ctx.f13.f64 : ctx.f10.f64;
	// fmuls f1,f8,f12
	ctx.f1.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// bl 0x823db788
	ctx.lr = 0x82547E1C;
	sub_823DB788(ctx, base);
	// frsp f7,f1
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(ctx.f1.f64));
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r3,-32114
	ctx.r3.s64 = -2104623104;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lfs f13,-22768(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -22768);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r3,-32456(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -32456);
	// fmuls f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// stfs f6,88(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x82547908
	ctx.lr = 0x82547E50;
	sub_82547908(ctx, base);
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

__attribute__((alias("__imp__sub_82547E64"))) PPC_WEAK_FUNC(sub_82547E64);
PPC_FUNC_IMPL(__imp__sub_82547E64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82547E68"))) PPC_WEAK_FUNC(sub_82547E68);
PPC_FUNC_IMPL(__imp__sub_82547E68) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lis r9,-32127
	ctx.r9.s64 = -2105475072;
	// li r8,3
	ctx.r8.s64 = 3;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f0,11368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11368);
	f0.f64 = double(temp.f32);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// fsubs f11,f1,f0
	ctx.f11.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f13,-18580(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -18580);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2160(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 2160);
	ctx.f12.f64 = double(temp.f32);
	// fsel f10,f11,f1,f0
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fsel f8,f9,f13,f10
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? ctx.f13.f64 : ctx.f10.f64;
	// fmuls f1,f8,f12
	ctx.f1.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// bl 0x823db788
	ctx.lr = 0x82547EB4;
	sub_823DB788(ctx, base);
	// frsp f7,f1
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(ctx.f1.f64));
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r3,-32114
	ctx.r3.s64 = -2104623104;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lfs f13,-22768(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -22768);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r3,-32456(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -32456);
	// fmuls f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// stfs f6,88(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x82547908
	ctx.lr = 0x82547EE8;
	sub_82547908(ctx, base);
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

__attribute__((alias("__imp__sub_82547EFC"))) PPC_WEAK_FUNC(sub_82547EFC);
PPC_FUNC_IMPL(__imp__sub_82547EFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82547F00"))) PPC_WEAK_FUNC(sub_82547F00);
PPC_FUNC_IMPL(__imp__sub_82547F00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f31{};
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
	// lis r11,1
	r11.s64 = 65536;
	// fmr f31,f2
	f31.f64 = ctx.f2.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// bl 0x821493f8
	ctx.lr = 0x82547F28;
	sub_821493F8(ctx, base);
	// stfs f1,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-32456(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -32456);
	// bl 0x82547908
	ctx.lr = 0x82547F44;
	sub_82547908(ctx, base);
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

__attribute__((alias("__imp__sub_82547F5C"))) PPC_WEAK_FUNC(sub_82547F5C);
PPC_FUNC_IMPL(__imp__sub_82547F5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82547F60"))) PPC_WEAK_FUNC(sub_82547F60);
PPC_FUNC_IMPL(__imp__sub_82547F60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// lis r11,1
	r11.s64 = 65536;
	// stfs f1,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f2,84(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,-32456(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -32456);
	// bl 0x82547908
	ctx.lr = 0x82547F90;
	sub_82547908(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82547FA0"))) PPC_WEAK_FUNC(sub_82547FA0);
PPC_FUNC_IMPL(__imp__sub_82547FA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// lis r11,1
	r11.s64 = 65536;
	// stfs f1,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f2,84(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// ori r9,r11,1
	ctx.r9.u64 = r11.u64 | 1;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,-32456(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -32456);
	// bl 0x82547908
	ctx.lr = 0x82547FD4;
	sub_82547908(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82547FE4"))) PPC_WEAK_FUNC(sub_82547FE4);
PPC_FUNC_IMPL(__imp__sub_82547FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82547FE8"))) PPC_WEAK_FUNC(sub_82547FE8);
PPC_FUNC_IMPL(__imp__sub_82547FE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f31,f2
	f31.f64 = ctx.f2.f64;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lis r9,-32127
	ctx.r9.s64 = -2105475072;
	// lis r8,1
	ctx.r8.s64 = 65536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f0,11368(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11368);
	f0.f64 = double(temp.f32);
	// ori r7,r8,2
	ctx.r7.u64 = ctx.r8.u64 | 2;
	// fsubs f11,f1,f0
	ctx.f11.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f13,-18580(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -18580);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2160(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 2160);
	ctx.f12.f64 = double(temp.f32);
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// fsel f10,f11,f1,f0
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fsel f8,f9,f13,f10
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? ctx.f13.f64 : ctx.f10.f64;
	// fmuls f1,f8,f12
	ctx.f1.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// bl 0x823db788
	ctx.lr = 0x82548040;
	sub_823DB788(ctx, base);
	// frsp f7,f1
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(ctx.f1.f64));
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r3,-32114
	ctx.r3.s64 = -2104623104;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lfs f0,-22768(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -22768);
	f0.f64 = double(temp.f32);
	// lwz r3,-32456(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -32456);
	// fmuls f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64));
	// stfs f6,88(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x82547908
	ctx.lr = 0x8254806C;
	sub_82547908(ctx, base);
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

__attribute__((alias("__imp__sub_82548084"))) PPC_WEAK_FUNC(sub_82548084);
PPC_FUNC_IMPL(__imp__sub_82548084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82548088"))) PPC_WEAK_FUNC(sub_82548088);
PPC_FUNC_IMPL(__imp__sub_82548088) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f31,f2
	f31.f64 = ctx.f2.f64;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lis r9,-32127
	ctx.r9.s64 = -2105475072;
	// lis r8,1
	ctx.r8.s64 = 65536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f0,11368(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11368);
	f0.f64 = double(temp.f32);
	// ori r7,r8,3
	ctx.r7.u64 = ctx.r8.u64 | 3;
	// fsubs f11,f1,f0
	ctx.f11.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f13,-18580(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -18580);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2160(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 2160);
	ctx.f12.f64 = double(temp.f32);
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// fsel f10,f11,f1,f0
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// fsel f8,f9,f13,f10
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? ctx.f13.f64 : ctx.f10.f64;
	// fmuls f1,f8,f12
	ctx.f1.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// bl 0x823db788
	ctx.lr = 0x825480E0;
	sub_823DB788(ctx, base);
	// frsp f7,f1
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(ctx.f1.f64));
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r3,-32114
	ctx.r3.s64 = -2104623104;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lfs f0,-22768(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -22768);
	f0.f64 = double(temp.f32);
	// lwz r3,-32456(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -32456);
	// fmuls f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64));
	// stfs f6,88(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x82547908
	ctx.lr = 0x8254810C;
	sub_82547908(ctx, base);
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

__attribute__((alias("__imp__sub_82548124"))) PPC_WEAK_FUNC(sub_82548124);
PPC_FUNC_IMPL(__imp__sub_82548124) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82548128"))) PPC_WEAK_FUNC(sub_82548128);
PPC_FUNC_IMPL(__imp__sub_82548128) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lfs f13,32(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r3,32
	r11.s64 = ctx.r3.s64 + 32;
	// addi r31,r10,-18580
	r31.s64 = ctx.r10.s64 + -18580;
	// lfs f0,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x82548170
	if (cr6.gt) goto loc_82548170;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,11368(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11368);
	ctx.f1.f64 = double(temp.f32);
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
loc_82548170:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lvlx v2,0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f0,3732(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx v1,0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// bl 0x821476b0
	ctx.lr = 0x8254818C;
	sub_821476B0(ctx, base);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// stvx128 v1,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
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

__attribute__((alias("__imp__sub_825481B4"))) PPC_WEAK_FUNC(sub_825481B4);
PPC_FUNC_IMPL(__imp__sub_825481B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825481B8"))) PPC_WEAK_FUNC(sub_825481B8);
PPC_FUNC_IMPL(__imp__sub_825481B8) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lfs f13,44(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r3,44
	r11.s64 = ctx.r3.s64 + 44;
	// addi r31,r10,-18580
	r31.s64 = ctx.r10.s64 + -18580;
	// lfs f0,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x82548200
	if (cr6.gt) goto loc_82548200;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,11368(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11368);
	ctx.f1.f64 = double(temp.f32);
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
loc_82548200:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lvlx v2,0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f0,3732(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx v1,0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// bl 0x821476b0
	ctx.lr = 0x8254821C;
	sub_821476B0(ctx, base);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// stvx128 v1,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
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

__attribute__((alias("__imp__sub_82548244"))) PPC_WEAK_FUNC(sub_82548244);
PPC_FUNC_IMPL(__imp__sub_82548244) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82548248"))) PPC_WEAK_FUNC(sub_82548248);
PPC_FUNC_IMPL(__imp__sub_82548248) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,58(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 58);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82548260
	if (!cr6.eq) goto loc_82548260;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82548260:
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// lwz r11,-32456(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -32456);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82548274"))) PPC_WEAK_FUNC(sub_82548274);
PPC_FUNC_IMPL(__imp__sub_82548274) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82548278"))) PPC_WEAK_FUNC(sub_82548278);
PPC_FUNC_IMPL(__imp__sub_82548278) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,56(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 56);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82548290
	if (!cr6.eq) goto loc_82548290;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82548290:
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// lwz r11,-32456(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -32456);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825482A4"))) PPC_WEAK_FUNC(sub_825482A4);
PPC_FUNC_IMPL(__imp__sub_825482A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825482A8"))) PPC_WEAK_FUNC(sub_825482A8);
PPC_FUNC_IMPL(__imp__sub_825482A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,60(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 60);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x825482d4
	if (cr6.eq) goto loc_825482D4;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x825482d4
	if (cr6.eq) goto loc_825482D4;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// mulli r10,r11,136
	ctx.r10.s64 = r11.s64 * 136;
	// lwz r11,26656(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26656);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// blr 
	return;
loc_825482D4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825482DC"))) PPC_WEAK_FUNC(sub_825482DC);
PPC_FUNC_IMPL(__imp__sub_825482DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825482E0"))) PPC_WEAK_FUNC(sub_825482E0);
PPC_FUNC_IMPL(__imp__sub_825482E0) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f2,f12
	cr6.compare(ctx.f2.f64, ctx.f12.f64);
	// bgt cr6,0x82548310
	if (cr6.gt) goto loc_82548310;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lfs f0,-18876(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -18876);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x82548304
	if (cr6.gt) goto loc_82548304;
	// fmr f1,f12
	ctx.f1.f64 = ctx.f12.f64;
loc_82548304:
	// stfs f1,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f12,12(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// blr 
	return;
loc_82548310:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lfs f0,14988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	f0.f64 = double(temp.f32);
	// fsubs f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 - f0.f64));
	// lfs f13,-18876(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -18876);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f1,f13
	cr6.compare(ctx.f1.f64, ctx.f13.f64);
	// fsel f0,f11,f0,f2
	f0.f64 = ctx.f11.f64 >= 0.0 ? f0.f64 : ctx.f2.f64;
	// bgt cr6,0x82548334
	if (cr6.gt) goto loc_82548334;
	// fmr f1,f12
	ctx.f1.f64 = ctx.f12.f64;
loc_82548334:
	// lfs f13,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f1,f13
	ctx.f11.f64 = double(float(ctx.f1.f64 - ctx.f13.f64));
	// fcmpu cr6,f11,f12
	cr6.compare(ctx.f11.f64, ctx.f12.f64);
	// ble cr6,0x8254835c
	if (!cr6.gt) goto loc_8254835C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f1,8(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// lfs f13,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 / f0.f64));
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// blr 
	return;
loc_8254835C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f1,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// lfs f13,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 / f0.f64));
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82548374"))) PPC_WEAK_FUNC(sub_82548374);
PPC_FUNC_IMPL(__imp__sub_82548374) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82548378"))) PPC_WEAK_FUNC(sub_82548378);
PPC_FUNC_IMPL(__imp__sub_82548378) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f2,f13
	cr6.compare(ctx.f2.f64, ctx.f13.f64);
	// bgt cr6,0x82548394
	if (cr6.gt) goto loc_82548394;
	// stfs f1,16(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f13,24(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// blr 
	return;
loc_82548394:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,16(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	f0.f64 = double(temp.f32);
	// fsubs f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f0,14988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	f0.f64 = double(temp.f32);
	// fsubs f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 - f0.f64));
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// fsel f0,f11,f0,f2
	f0.f64 = ctx.f11.f64 >= 0.0 ? f0.f64 : ctx.f2.f64;
	// ble cr6,0x825483cc
	if (!cr6.gt) goto loc_825483CC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f1,20(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// lfs f13,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 / f0.f64));
	// stfs f0,24(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// blr 
	return;
loc_825483CC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f1,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// lfs f13,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 / f0.f64));
	// stfs f0,24(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825483E4"))) PPC_WEAK_FUNC(sub_825483E4);
PPC_FUNC_IMPL(__imp__sub_825483E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825483E8"))) PPC_WEAK_FUNC(sub_825483E8);
PPC_FUNC_IMPL(__imp__sub_825483E8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f2,f13
	cr6.compare(ctx.f2.f64, ctx.f13.f64);
	// bgt cr6,0x82548404
	if (cr6.gt) goto loc_82548404;
	// stfs f1,28(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f13,36(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// blr 
	return;
loc_82548404:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,28(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	f0.f64 = double(temp.f32);
	// fsubs f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f0,14988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	f0.f64 = double(temp.f32);
	// fsubs f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 - f0.f64));
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// fsel f0,f11,f0,f2
	f0.f64 = ctx.f11.f64 >= 0.0 ? f0.f64 : ctx.f2.f64;
	// ble cr6,0x8254843c
	if (!cr6.gt) goto loc_8254843C;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// stfs f1,32(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// lfs f13,-18548(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -18548);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 / f0.f64));
	// stfs f0,36(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// blr 
	return;
loc_8254843C:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// stfs f1,32(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// lfs f13,-18560(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -18560);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 / f0.f64));
	// stfs f0,36(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82548454"))) PPC_WEAK_FUNC(sub_82548454);
PPC_FUNC_IMPL(__imp__sub_82548454) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82548458"))) PPC_WEAK_FUNC(sub_82548458);
PPC_FUNC_IMPL(__imp__sub_82548458) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f2,f13
	cr6.compare(ctx.f2.f64, ctx.f13.f64);
	// bgt cr6,0x82548474
	if (cr6.gt) goto loc_82548474;
	// stfs f1,40(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f13,48(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// blr 
	return;
loc_82548474:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,40(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	f0.f64 = double(temp.f32);
	// fsubs f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f0,14988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	f0.f64 = double(temp.f32);
	// fsubs f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 - f0.f64));
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// fsel f0,f11,f0,f2
	f0.f64 = ctx.f11.f64 >= 0.0 ? f0.f64 : ctx.f2.f64;
	// ble cr6,0x825484ac
	if (!cr6.gt) goto loc_825484AC;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// stfs f1,44(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// lfs f13,-18548(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -18548);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 / f0.f64));
	// stfs f0,48(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// blr 
	return;
loc_825484AC:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// stfs f1,44(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// lfs f13,-18560(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -18560);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 / f0.f64));
	// stfs f0,48(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825484C4"))) PPC_WEAK_FUNC(sub_825484C4);
PPC_FUNC_IMPL(__imp__sub_825484C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825484C8"))) PPC_WEAK_FUNC(sub_825484C8);
PPC_FUNC_IMPL(__imp__sub_825484C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r18{};
	PPCRegister r20{};
	PPCRegister f0{};
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
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82548624
	if (cr6.eq) goto loc_82548624;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r3,8
	ctx.r9.s64 = ctx.r3.s64 + 8;
	// lfs f9,-18876(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -18876);
	ctx.f9.f64 = double(temp.f32);
	// lfs f10,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f10.f64 = double(temp.f32);
loc_825484F0:
	// lwz r11,-8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82548618
	if (cr6.eq) goto loc_82548618;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lhz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addi r11,r9,-4
	r11.s64 = ctx.r9.s64 + -4;
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r3,r10,r5
	ctx.r3.u64 = ctx.r10.u64 + ctx.r5.u64;
	// extsh r10,r8
	ctx.r10.s64 = ctx.r8.s16;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// blt cr6,0x82548598
	if (cr6.lt) goto loc_82548598;
	// bne cr6,0x82548618
	if (!cr6.eq) goto loc_82548618;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// cmplwi cr6,r10,3
	cr6.compare<uint32_t>(ctx.r10.u32, 3, xer);
	// bgt cr6,0x82548618
	if (cr6.gt) goto loc_82548618;
	// lis r12,-32171
	r12.s64 = -2108358656;
	// addi r12,r12,-31416
	r12.s64 = r12.s64 + -31416;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_82548568;
	case 1:
		goto loc_82548558;
	case 2:
		goto loc_82548588;
	case 3:
		goto loc_82548578;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-31384(r20)
	r18.u64 = PPC_LOAD_U32(r20.u32 + -31384);
	// lwz r18,-31400(r20)
	r18.u64 = PPC_LOAD_U32(r20.u32 + -31400);
	// lwz r18,-31352(r20)
	r18.u64 = PPC_LOAD_U32(r20.u32 + -31352);
	// lwz r18,-31368(r20)
	r18.u64 = PPC_LOAD_U32(r20.u32 + -31368);
loc_82548558:
	// lfs f2,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82548378
	ctx.lr = 0x82548564;
	sub_82548378(ctx, base);
	// b 0x82548618
	goto loc_82548618;
loc_82548568:
	// lfs f2,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825482e0
	ctx.lr = 0x82548574;
	sub_825482E0(ctx, base);
	// b 0x82548618
	goto loc_82548618;
loc_82548578:
	// lfs f2,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82548458
	ctx.lr = 0x82548584;
	sub_82548458(ctx, base);
	// b 0x82548618
	goto loc_82548618;
loc_82548588:
	// lfs f2,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825483e8
	ctx.lr = 0x82548594;
	sub_825483E8(ctx, base);
	// b 0x82548618
	goto loc_82548618;
loc_82548598:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x82548618
	if (cr6.gt) goto loc_82548618;
	// lis r12,-32171
	r12.s64 = -2108358656;
	// addi r12,r12,-31296
	r12.s64 = r12.s64 + -31296;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_825485E0;
	case 1:
		goto loc_825485D0;
	case 2:
		goto loc_8254860C;
	case 3:
		goto loc_825485FC;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-31264(r20)
	r18.u64 = PPC_LOAD_U32(r20.u32 + -31264);
	// lwz r18,-31280(r20)
	r18.u64 = PPC_LOAD_U32(r20.u32 + -31280);
	// lwz r18,-31220(r20)
	r18.u64 = PPC_LOAD_U32(r20.u32 + -31220);
	// lwz r18,-31236(r20)
	r18.u64 = PPC_LOAD_U32(r20.u32 + -31236);
loc_825485D0:
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f10,24(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// b 0x82548618
	goto loc_82548618;
loc_825485E0:
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f9
	cr6.compare(f0.f64, ctx.f9.f64);
	// bgt cr6,0x825485f0
	if (cr6.gt) goto loc_825485F0;
	// fmr f0,f10
	f0.f64 = ctx.f10.f64;
loc_825485F0:
	// stfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f10,12(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// b 0x82548618
	goto loc_82548618;
loc_825485FC:
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,40(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f10,48(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// b 0x82548618
	goto loc_82548618;
loc_8254860C:
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,28(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f10,36(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
loc_82548618:
	// addic. r4,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bne 0x825484f0
	if (!cr0.eq) goto loc_825484F0;
loc_82548624:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82548634"))) PPC_WEAK_FUNC(sub_82548634);
PPC_FUNC_IMPL(__imp__sub_82548634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82548638"))) PPC_WEAK_FUNC(sub_82548638);
PPC_FUNC_IMPL(__imp__sub_82548638) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32248
	ctx.r8.s64 = -2113404928;
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// li r11,-1
	r11.s64 = -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f13,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r7,-18552
	ctx.r5.s64 = ctx.r7.s64 + -18552;
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f12,-18560(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -18560);
	ctx.f12.f64 = double(temp.f32);
	// stw r6,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r6.u32);
	// stfs f13,4(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// stfs f13,8(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// sth r11,56(r3)
	PPC_STORE_U16(ctx.r3.u32 + 56, r11.u16);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// sth r11,58(r3)
	PPC_STORE_U16(ctx.r3.u32 + 58, r11.u16);
	// stfs f13,16(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// sth r11,60(r3)
	PPC_STORE_U16(ctx.r3.u32 + 60, r11.u16);
	// stfs f13,20(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f0,28(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f0,32(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f0,36(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f12,40(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f12,44(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f0,48(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825486A8"))) PPC_WEAK_FUNC(sub_825486A8);
PPC_FUNC_IMPL(__imp__sub_825486A8) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-18552
	ctx.r10.s64 = r11.s64 + -18552;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x825486D4;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x825486ec
	if (cr6.eq) goto loc_825486EC;
	// bl 0x82130588
	ctx.lr = 0x825486E8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_825486EC:
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

__attribute__((alias("__imp__sub_82548704"))) PPC_WEAK_FUNC(sub_82548704);
PPC_FUNC_IMPL(__imp__sub_82548704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82548708"))) PPC_WEAK_FUNC(sub_82548708);
PPC_FUNC_IMPL(__imp__sub_82548708) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8254871c
	if (!cr6.eq) goto loc_8254871C;
	// li r11,-1
	r11.s64 = -1;
	// sth r11,58(r3)
	PPC_STORE_U16(ctx.r3.u32 + 58, r11.u16);
	// blr 
	return;
loc_8254871C:
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r11,-32456(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -32456);
	// subf r10,r11,r4
	ctx.r10.s64 = ctx.r4.s64 - r11.s64;
	// srawi r9,r10,6
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3F) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 6;
	// sth r9,58(r3)
	PPC_STORE_U16(ctx.r3.u32 + 58, ctx.r9.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82548734"))) PPC_WEAK_FUNC(sub_82548734);
PPC_FUNC_IMPL(__imp__sub_82548734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82548738"))) PPC_WEAK_FUNC(sub_82548738);
PPC_FUNC_IMPL(__imp__sub_82548738) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8254874c
	if (!cr6.eq) goto loc_8254874C;
	// li r11,-1
	r11.s64 = -1;
	// sth r11,56(r3)
	PPC_STORE_U16(ctx.r3.u32 + 56, r11.u16);
	// blr 
	return;
loc_8254874C:
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r11,-32456(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -32456);
	// subf r10,r11,r4
	ctx.r10.s64 = ctx.r4.s64 - r11.s64;
	// srawi r9,r10,6
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3F) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 6;
	// sth r9,56(r3)
	PPC_STORE_U16(ctx.r3.u32 + 56, ctx.r9.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82548764"))) PPC_WEAK_FUNC(sub_82548764);
PPC_FUNC_IMPL(__imp__sub_82548764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82548768"))) PPC_WEAK_FUNC(sub_82548768);
PPC_FUNC_IMPL(__imp__sub_82548768) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f13,f1,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f1.f64 + f0.f64));
	// stfs f12,4(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82548794
	if (!cr6.gt) goto loc_82548794;
	// lfs f11,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bge cr6,0x825487ac
	if (!cr6.lt) goto loc_825487AC;
loc_82548794:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x825487b4
	if (!cr6.lt) goto loc_825487B4;
	// lfs f11,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// bgt cr6,0x825487b4
	if (cr6.gt) goto loc_825487B4;
loc_825487AC:
	// stfs f11,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
loc_825487B4:
	// lfs f12,16(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f13,f1,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f1.f64 + ctx.f12.f64));
	// stfs f12,16(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x825487d8
	if (!cr6.gt) goto loc_825487D8;
	// lfs f11,20(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bge cr6,0x825487f0
	if (!cr6.lt) goto loc_825487F0;
loc_825487D8:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x825487f8
	if (!cr6.lt) goto loc_825487F8;
	// lfs f11,20(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// bgt cr6,0x825487f8
	if (cr6.gt) goto loc_825487F8;
loc_825487F0:
	// stfs f11,16(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
loc_825487F8:
	// lfs f12,28(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,36(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f13,f1,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f1.f64 + ctx.f12.f64));
	// stfs f12,28(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8254881c
	if (!cr6.gt) goto loc_8254881C;
	// lfs f11,32(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bge cr6,0x82548834
	if (!cr6.lt) goto loc_82548834;
loc_8254881C:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8254883c
	if (!cr6.lt) goto loc_8254883C;
	// lfs f11,32(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// bgt cr6,0x8254883c
	if (cr6.gt) goto loc_8254883C;
loc_82548834:
	// stfs f11,28(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f0,36(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
loc_8254883C:
	// lfs f12,40(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,48(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f13,f1,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f1.f64 + ctx.f12.f64));
	// stfs f12,40(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82548860
	if (!cr6.gt) goto loc_82548860;
	// lfs f11,44(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bge cr6,0x82548878
	if (!cr6.lt) goto loc_82548878;
loc_82548860:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgelr cr6
	if (!cr6.lt) return;
	// lfs f11,44(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// bgtlr cr6
	if (cr6.gt) return;
loc_82548878:
	// stfs f11,40(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f0,48(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82548884"))) PPC_WEAK_FUNC(sub_82548884);
PPC_FUNC_IMPL(__imp__sub_82548884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82548888"))) PPC_WEAK_FUNC(sub_82548888);
PPC_FUNC_IMPL(__imp__sub_82548888) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
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
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823db9d8
	ctx.lr = 0x825488A0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r31,r11,-18880
	r31.s64 = r11.s64 + -18880;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r5,-1
	cr6.compare<int32_t>(ctx.r5.s32, -1, xer);
	// lfs f7,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f7.f64 = double(temp.f32);
	// lfs f28,320(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 320);
	f28.f64 = double(temp.f32);
	// fmr f9,f7
	ctx.f9.f64 = ctx.f7.f64;
	// lfs f10,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f10.f64 = double(temp.f32);
	// fmr f31,f28
	f31.f64 = f28.f64;
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmr f8,f10
	ctx.f8.f64 = ctx.f10.f64;
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// beq cr6,0x8254894c
	if (cr6.eq) goto loc_8254894C;
	// rlwinm r11,r5,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
	// add r3,r11,r4
	ctx.r3.u64 = r11.u64 + ctx.r4.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8254894c
	if (cr6.eq) goto loc_8254894C;
loc_825488F0:
	// bl 0x82548768
	ctx.lr = 0x825488F4;
	sub_82548768(ctx, base);
	// lfs f0,28(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	f0.f64 = double(temp.f32);
	// lfs f13,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f9,f0
	ctx.f12.f64 = double(float(ctx.f9.f64 - f0.f64));
	// fsubs f11,f31,f13
	ctx.f11.f64 = double(float(f31.f64 - ctx.f13.f64));
	// lhz r11,58(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 58);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// fsel f9,f12,f0,f9
	ctx.f9.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f9.f64;
	// fsel f31,f11,f31,f13
	f31.f64 = ctx.f11.f64 >= 0.0 ? f31.f64 : ctx.f13.f64;
	// lfs f6,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f10,f6,f10
	ctx.f10.f64 = double(float(ctx.f6.f64 * ctx.f10.f64));
	// fmuls f8,f5,f8
	ctx.f8.f64 = double(float(ctx.f5.f64 * ctx.f8.f64));
	// beq cr6,0x82548938
	if (cr6.eq) goto loc_82548938;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r3,r11,r4
	ctx.r3.u64 = r11.u64 + ctx.r4.u64;
	// b 0x8254893c
	goto loc_8254893C;
loc_82548938:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8254893C:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x825488f0
	if (!cr6.eq) goto loc_825488F0;
	// stfs f31,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_8254894C:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stfs f10,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f7,100(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// li r10,16
	ctx.r10.s64 = 16;
	// stfs f7,104(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// fsubs f13,f10,f0
	ctx.f13.f64 = double(float(ctx.f10.f64 - f0.f64));
	// lfs f0,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	v62.f32[0] = log2f(v63.f32[0]);
	v62.f32[1] = log2f(v63.f32[1]);
	v62.f32[2] = log2f(v63.f32[2]);
	v62.f32[3] = log2f(v63.f32[3]);
	// lvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f8
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.f64 = ctx.f8.f64;
	// vmulfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lfs f29,11368(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11368);
	f29.f64 = double(temp.f32);
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f29
	ctx.f11.f64 = double(float(ctx.f12.f64 * f29.f64));
	// fsel f10,f13,f11,f0
	ctx.f10.f64 = ctx.f13.f64 >= 0.0 ? ctx.f11.f64 : f0.f64;
	// stfs f10,0(r30)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// bl 0x823db918
	ctx.lr = 0x825489A4;
	sub_823DB918(ctx, base);
	// frsp f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f1.f64));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,11332(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11332);
	f0.f64 = double(temp.f32);
	// lfs f13,11328(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 11328);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * f0.f64));
	// fmuls f7,f8,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// fctiwz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f6.u64);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmpwi cr6,r11,-32768
	cr6.compare<int32_t>(r11.s32, -32768, xer);
	// bge cr6,0x825489dc
	if (!cr6.lt) goto loc_825489DC;
	// li r11,-32768
	r11.s64 = -32768;
	// b 0x825489e8
	goto loc_825489E8;
loc_825489DC:
	// cmpwi cr6,r11,32767
	cr6.compare<int32_t>(r11.s32, 32767, xer);
	// ble cr6,0x825489e8
	if (!cr6.gt) goto loc_825489E8;
	// li r11,32767
	r11.s64 = 32767;
loc_825489E8:
	// sth r11,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r11.u16);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f30,3732(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f30.f64 = double(temp.f32);
	// stfs f30,96(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx v2,0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx v1,0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// bl 0x821476b0
	ctx.lr = 0x82548A0C;
	sub_821476B0(ctx, base);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lfs f0,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 300);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f28
	cr6.compare(f31.f64, f28.f64);
	// stvx128 v1,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f31,f13,f0
	f31.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bgt cr6,0x82548a30
	if (cr6.gt) goto loc_82548A30;
	// fmr f0,f29
	f0.f64 = f29.f64;
	// b 0x82548a5c
	goto loc_82548A5C;
loc_82548A30:
	// addi r11,r1,88
	r11.s64 = ctx.r1.s64 + 88;
	// stfs f30,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvlx v2,0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx v1,0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// bl 0x821476b0
	ctx.lr = 0x82548A48;
	sub_821476B0(ctx, base);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f0,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 300);
	f0.f64 = double(temp.f32);
	// stvx128 v1,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
loc_82548A5C:
	// fctidz f0,f0
	ctx.fpscr.disableFlushMode();
	f0.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f0,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, f0.u64);
	// lhz r11,102(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 102);
	// fctidz f13,f31
	ctx.f13.s64 = (f31.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f31.f64));
	// stfd f13,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lhz r9,94(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 94);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// sth r9,6(r30)
	PPC_STORE_U16(r30.u32 + 6, ctx.r9.u16);
	// fcmpu cr6,f10,f29
	cr6.compare(ctx.f10.f64, f29.f64);
	// bgt cr6,0x82548a98
	if (cr6.gt) goto loc_82548A98;
	// li r11,0
	r11.s64 = 0;
loc_82548A98:
	// sth r11,8(r30)
	PPC_STORE_U16(r30.u32 + 8, r11.u16);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823dba24
	ctx.lr = 0x82548AA8;
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

__attribute__((alias("__imp__sub_82548ABC"))) PPC_WEAK_FUNC(sub_82548ABC);
PPC_FUNC_IMPL(__imp__sub_82548ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82548AC0"))) PPC_WEAK_FUNC(sub_82548AC0);
PPC_FUNC_IMPL(__imp__sub_82548AC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r11,-18224
	ctx.r9.s64 = r11.s64 + -18224;
	// sth r10,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r10.u16);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82548AD8"))) PPC_WEAK_FUNC(sub_82548AD8);
PPC_FUNC_IMPL(__imp__sub_82548AD8) {
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
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x82548b10
	if (cr6.eq) goto loc_82548B10;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,27076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 27076);
	// bl 0x821609c8
	ctx.lr = 0x82548B08;
	sub_821609C8(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// sth r10,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r10.u16);
loc_82548B10:
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

__attribute__((alias("__imp__sub_82548B24"))) PPC_WEAK_FUNC(sub_82548B24);
PPC_FUNC_IMPL(__imp__sub_82548B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82548B28"))) PPC_WEAK_FUNC(sub_82548B28);
PPC_FUNC_IMPL(__imp__sub_82548B28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,27076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 27076);
	// b 0x82160b60
	sub_82160B60(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82548B48"))) PPC_WEAK_FUNC(sub_82548B48);
PPC_FUNC_IMPL(__imp__sub_82548B48) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82548B4C"))) PPC_WEAK_FUNC(sub_82548B4C);
PPC_FUNC_IMPL(__imp__sub_82548B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82548B50"))) PPC_WEAK_FUNC(sub_82548B50);
PPC_FUNC_IMPL(__imp__sub_82548B50) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r9,r11,-18224
	ctx.r9.s64 = r11.s64 + -18224;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,65535
	cr6.compare<uint32_t>(ctx.r10.u32, 65535, xer);
	// beq cr6,0x82548b94
	if (cr6.eq) goto loc_82548B94;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,27076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 27076);
	// bl 0x821609c8
	ctx.lr = 0x82548B8C;
	sub_821609C8(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// sth r10,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r10.u16);
loc_82548B94:
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

__attribute__((alias("__imp__sub_82548BA8"))) PPC_WEAK_FUNC(sub_82548BA8);
PPC_FUNC_IMPL(__imp__sub_82548BA8) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,27076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 27076);
	// bl 0x82160578
	ctx.lr = 0x82548BCC;
	sub_82160578(ctx, base);
	// sth r3,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r3.u16);
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

__attribute__((alias("__imp__sub_82548BE4"))) PPC_WEAK_FUNC(sub_82548BE4);
PPC_FUNC_IMPL(__imp__sub_82548BE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82548BE8"))) PPC_WEAK_FUNC(sub_82548BE8);
PPC_FUNC_IMPL(__imp__sub_82548BE8) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r9,r11,-18224
	ctx.r9.s64 = r11.s64 + -18224;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,65535
	cr6.compare<uint32_t>(ctx.r10.u32, 65535, xer);
	// beq cr6,0x82548c34
	if (cr6.eq) goto loc_82548C34;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,27076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 27076);
	// bl 0x821609c8
	ctx.lr = 0x82548C2C;
	sub_821609C8(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// sth r10,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r10.u16);
loc_82548C34:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82548c4c
	if (cr6.eq) goto loc_82548C4C;
	// bl 0x82130588
	ctx.lr = 0x82548C48;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82548C4C:
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

__attribute__((alias("__imp__sub_82548C64"))) PPC_WEAK_FUNC(sub_82548C64);
PPC_FUNC_IMPL(__imp__sub_82548C64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82548C68"))) PPC_WEAK_FUNC(sub_82548C68);
PPC_FUNC_IMPL(__imp__sub_82548C68) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82548C70;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82548fc8
	if (cr6.eq) goto loc_82548FC8;
	// lbz r11,4(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lbz r8,70(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 70);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// addi r31,r9,7216
	r31.s64 = ctx.r9.s64 + 7216;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// beq cr6,0x82548cc8
	if (cr6.eq) goto loc_82548CC8;
	// lbz r10,64(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,200(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82548ccc
	goto loc_82548CCC;
loc_82548CC8:
	// li r11,0
	r11.s64 = 0;
loc_82548CCC:
	// lbz r10,200(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 200);
	// clrlwi r9,r7,24
	ctx.r9.u64 = ctx.r7.u32 & 0xFF;
	// rlwimi r10,r9,6,25,25
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 6) & 0x40) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFBF);
	// stb r10,200(r11)
	PPC_STORE_U8(r11.u32 + 200, ctx.r10.u8);
	// lfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82548d14
	if (cr6.eq) goto loc_82548D14;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r11,r10
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82548d18
	goto loc_82548D18;
loc_82548D14:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82548D18:
	// bl 0x82148cb0
	ctx.lr = 0x82548D1C;
	sub_82148CB0(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82548d54
	if (cr6.eq) goto loc_82548D54;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r11,r10
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82548d58
	goto loc_82548D58;
loc_82548D54:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82548D58:
	// bl 0x82148c60
	ctx.lr = 0x82548D5C;
	sub_82148C60(ctx, base);
	// lbz r11,70(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 70);
	// lwz r4,36(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// rlwinm r5,r11,26,31,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x1;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8213b7b0
	ctx.lr = 0x82548D70;
	sub_8213B7B0(ctx, base);
	// lfs f1,60(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 60);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8234db80
	ctx.lr = 0x82548D7C;
	sub_8234DB80(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r4,64(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 64);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82548db4
	if (cr6.eq) goto loc_82548DB4;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r11,r10
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82548db8
	goto loc_82548DB8;
loc_82548DB4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82548DB8:
	// bl 0x82148c38
	ctx.lr = 0x82548DBC;
	sub_82148C38(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lbz r9,70(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 70);
	// rlwinm r7,r9,28,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0x1;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82548df8
	if (cr6.eq) goto loc_82548DF8;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r11,r10
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82548dfc
	goto loc_82548DFC;
loc_82548DF8:
	// li r11,0
	r11.s64 = 0;
loc_82548DFC:
	// lbz r10,200(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 200);
	// rlwimi r10,r7,7,17,24
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r7.u32, 7) & 0x7F80) | (ctx.r10.u64 & 0xFFFFFFFFFFFF807F);
	// stb r10,200(r11)
	PPC_STORE_U8(r11.u32 + 200, ctx.r10.u8);
	// lwz r8,48(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82548e80
	if (cr6.eq) goto loc_82548E80;
	// rotlwi r11,r8,0
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82548e48
	if (cr6.eq) goto loc_82548E48;
	// lbz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// add r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 + ctx.r8.u64;
	// twllei r10,0
	// lwz r6,11440(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// subf r5,r6,r11
	ctx.r5.s64 = r11.s64 - ctx.r6.s64;
	// divwu r10,r5,r10
	ctx.r10.u32 = ctx.r5.u32 / ctx.r10.u32;
	// b 0x82548e4c
	goto loc_82548E4C;
loc_82548E48:
	// li r10,255
	ctx.r10.s64 = 255;
loc_82548E4C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// clrlwi r4,r10,24
	ctx.r4.u64 = ctx.r10.u32 & 0xFF;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82548ef8
	if (cr6.eq) goto loc_82548EF8;
	// lbz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r10,r11,r10
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r11,11444(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11444);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82548efc
	goto loc_82548EFC;
loc_82548E80:
	// lbz r11,70(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 70);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82548f00
	if (cr6.eq) goto loc_82548F00;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82548ec4
	if (cr6.eq) goto loc_82548EC4;
	// lbz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// add r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 + ctx.r8.u64;
	// twllei r10,0
	// lwz r6,11440(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// subf r5,r6,r11
	ctx.r5.s64 = r11.s64 - ctx.r6.s64;
	// divwu r10,r5,r10
	ctx.r10.u32 = ctx.r5.u32 / ctx.r10.u32;
	// b 0x82548ec8
	goto loc_82548EC8;
loc_82548EC4:
	// li r10,255
	ctx.r10.s64 = 255;
loc_82548EC8:
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// clrlwi r4,r10,24
	ctx.r4.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82548ef8
	if (cr6.eq) goto loc_82548EF8;
	// lbz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mullw r10,r11,r9
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r11,11444(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11444);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82548efc
	goto loc_82548EFC;
loc_82548EF8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82548EFC:
	// bl 0x82148f10
	ctx.lr = 0x82548F00;
	sub_82148F10(ctx, base);
loc_82548F00:
	// lwz r4,20(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82548f14
	if (cr6.eq) goto loc_82548F14;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8213b860
	ctx.lr = 0x82548F14;
	sub_8213B860(ctx, base);
loc_82548F14:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lbz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r7,255
	cr6.compare<uint32_t>(ctx.r7.u32, 255, xer);
	// beq cr6,0x82548fc8
	if (cr6.eq) goto loc_82548FC8;
	// lbz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,200(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r7,r10,r7
	ctx.r7.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// lwz r8,11444(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11444);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82548fc8
	if (cr6.eq) goto loc_82548FC8;
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82548f74
	if (cr6.eq) goto loc_82548F74;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// mullw r10,r8,r10
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82548f78
	goto loc_82548F78;
loc_82548F74:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82548F78:
	// lwz r4,32(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// bl 0x82148ea8
	ctx.lr = 0x82548F80;
	sub_82148EA8(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r7,52(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82548fc0
	if (cr6.eq) goto loc_82548FC0;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r7,172(r11)
	PPC_STORE_U32(r11.u32 + 172, ctx.r7.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82548FC0:
	// li r11,0
	r11.s64 = 0;
	// stw r7,172(r11)
	PPC_STORE_U32(r11.u32 + 172, ctx.r7.u32);
loc_82548FC8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82548FD0"))) PPC_WEAK_FUNC(sub_82548FD0);
PPC_FUNC_IMPL(__imp__sub_82548FD0) {
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
	ctx.lr = 0x82548FD8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// lwz r11,-32452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -32452);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// beq cr6,0x82549060
	if (cr6.eq) goto loc_82549060;
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x82549060
	if (cr6.eq) goto loc_82549060;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82549070
	if (cr6.eq) goto loc_82549070;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821e8080
	ctx.lr = 0x82549018;
	sub_821E8080(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82549024
	if (!cr6.eq) goto loc_82549024;
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
loc_82549024:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,27076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 27076);
	// bl 0x82161890
	ctx.lr = 0x82549044;
	sub_82161890(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82548c68
	ctx.lr = 0x82549058;
	sub_82548C68(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
loc_82549060:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82549070
	if (cr6.eq) goto loc_82549070;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
loc_82549070:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82549078"))) PPC_WEAK_FUNC(sub_82549078);
PPC_FUNC_IMPL(__imp__sub_82549078) {
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
	ctx.lr = 0x82549080;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// lwz r11,-32452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -32452);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// beq cr6,0x82549104
	if (cr6.eq) goto loc_82549104;
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x82549104
	if (cr6.eq) goto loc_82549104;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82549104
	if (cr6.eq) goto loc_82549104;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821e8080
	ctx.lr = 0x825490C0;
	sub_821E8080(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x825490cc
	if (!cr6.eq) goto loc_825490CC;
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
loc_825490CC:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,27076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 27076);
	// bl 0x82161b58
	ctx.lr = 0x825490EC;
	sub_82161B58(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82548c68
	ctx.lr = 0x825490FC;
	sub_82548C68(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
loc_82549104:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82549114"))) PPC_WEAK_FUNC(sub_82549114);
PPC_FUNC_IMPL(__imp__sub_82549114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82549118"))) PPC_WEAK_FUNC(sub_82549118);
PPC_FUNC_IMPL(__imp__sub_82549118) {
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
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// li r11,0
	r11.s64 = 0;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r7,-1
	ctx.r7.s64 = -1;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r6,255
	ctx.r6.s64 = 255;
	// li r10,4
	ctx.r10.s64 = 4;
	// lfs f13,-18544(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -18544);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// stw r11,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r11.u32);
	// stw r11,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r11.u32);
	// stw r11,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r11.u32);
	// stw r11,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r11.u32);
	// stw r8,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r8.u32);
	// stw r7,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r7.u32);
	// stb r6,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, ctx.r6.u8);
	// stb r11,165(r1)
	PPC_STORE_U8(ctx.r1.u32 + 165, r11.u8);
	// stb r10,166(r1)
	PPC_STORE_U8(ctx.r1.u32 + 166, ctx.r10.u8);
	// bne cr6,0x825491ac
	if (!cr6.eq) goto loc_825491AC;
	// addi r31,r1,96
	r31.s64 = ctx.r1.s64 + 96;
loc_825491AC:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x82548fd0
	ctx.lr = 0x825491B8;
	sub_82548FD0(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x825491d8
	if (cr6.eq) goto loc_825491D8;
	// lbz r11,70(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 70);
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r5,r11,29,31,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1;
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x8213c0c0
	ctx.lr = 0x825491D8;
	sub_8213C0C0(ctx, base);
loc_825491D8:
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

__attribute__((alias("__imp__sub_825491EC"))) PPC_WEAK_FUNC(sub_825491EC);
PPC_FUNC_IMPL(__imp__sub_825491EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825491F0"))) PPC_WEAK_FUNC(sub_825491F0);
PPC_FUNC_IMPL(__imp__sub_825491F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	ctx.lr = 0x825491F8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r31,0
	r31.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,-1
	ctx.r8.s64 = -1;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r7,255
	ctx.r7.s64 = 255;
	// lfs f13,-18544(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -18544);
	ctx.f13.f64 = double(temp.f32);
	// li r5,4
	ctx.r5.s64 = 4;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r31.u32);
	// stw r31,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r31.u32);
	// stw r31,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r31.u32);
	// stw r31,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r31.u32);
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r31.u32);
	// stw r9,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r9.u32);
	// stw r8,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r8.u32);
	// stb r7,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r7.u8);
	// stb r31,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, r31.u8);
	// stb r5,150(r1)
	PPC_STORE_U8(ctx.r1.u32 + 150, ctx.r5.u8);
	// bne cr6,0x82549284
	if (!cr6.eq) goto loc_82549284;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
loc_82549284:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x82549078
	ctx.lr = 0x82549290;
	sub_82549078(ctx, base);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x825492a8
	if (!cr6.eq) goto loc_825492A8;
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
loc_825492A8:
	// lbz r11,70(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 70);
	// lwz r6,8(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rlwinm r5,r11,29,31,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1;
	// lwz r4,24(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// bl 0x8213c0c0
	ctx.lr = 0x825492BC;
	sub_8213C0C0(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_825492C4"))) PPC_WEAK_FUNC(sub_825492C4);
PPC_FUNC_IMPL(__imp__sub_825492C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825492C8"))) PPC_WEAK_FUNC(sub_825492C8);
PPC_FUNC_IMPL(__imp__sub_825492C8) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// li r11,0
	r11.s64 = 0;
	// rlwinm r8,r6,2,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0x4;
	// li r7,-1
	ctx.r7.s64 = -1;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r10,255
	ctx.r10.s64 = 255;
	// li r31,-1
	r31.s64 = -1;
	// lfs f13,-18544(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -18544);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stb r8,150(r1)
	PPC_STORE_U8(ctx.r1.u32 + 150, ctx.r8.u8);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// stw r7,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r7.u32);
	// stw r31,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r31.u32);
	// stb r10,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r10.u8);
	// stb r11,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, r11.u8);
	// bl 0x82549078
	ctx.lr = 0x82549354;
	sub_82549078(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82549368"))) PPC_WEAK_FUNC(sub_82549368);
PPC_FUNC_IMPL(__imp__sub_82549368) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	ctx.lr = 0x82549370;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r11,0
	r11.s64 = 0;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// lfs f13,-18544(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -18544);
	ctx.f13.f64 = double(temp.f32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r5,255
	ctx.r5.s64 = 255;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// stw r8,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r8.u32);
	// stw r7,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r7.u32);
	// stb r5,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r5.u8);
	// stb r11,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, r11.u8);
	// stb r4,150(r1)
	PPC_STORE_U8(ctx.r1.u32 + 150, ctx.r4.u8);
	// bne cr6,0x82549404
	if (!cr6.eq) goto loc_82549404;
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
loc_82549404:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x8254940C;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// bl 0x82549078
	ctx.lr = 0x82549420;
	sub_82549078(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82549428"))) PPC_WEAK_FUNC(sub_82549428);
PPC_FUNC_IMPL(__imp__sub_82549428) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91f0
	ctx.lr = 0x82549430;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// lbz r5,319(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 319);
	// lis r31,-32248
	r31.s64 = -2113404928;
	// lwz r30,300(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 300);
	// rlwimi r6,r11,1,30,30
	ctx.r6.u64 = (__builtin_rotateleft32(r11.u32, 1) & 0x2) | (ctx.r6.u64 & 0xFFFFFFFFFFFFFFFD);
	// lwz r29,308(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// lwz r28,324(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r6,r6,30
	ctx.r6.u64 = ctx.r6.u32 & 0x3;
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r27,255
	r27.s64 = 255;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// rlwimi r5,r6,1,0,30
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r6.u32, 1) & 0xFFFFFFFE) | (ctx.r5.u64 & 0xFFFFFFFF00000001);
	// lfs f0,-18544(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -18544);
	f0.f64 = double(temp.f32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stfs f0,140(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// rlwinm r5,r5,3,24,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xF8;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// li r31,-1
	r31.s64 = -1;
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// ori r26,r5,4
	r26.u64 = ctx.r5.u64 | 4;
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// stw r6,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r6.u32);
	// stw r31,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r31.u32);
	// stb r27,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, r27.u8);
	// stb r11,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, r11.u8);
	// stb r26,150(r1)
	PPC_STORE_U8(ctx.r1.u32 + 150, r26.u8);
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// stw r29,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r29.u32);
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// bl 0x82549118
	ctx.lr = 0x825494CC;
	sub_82549118(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_825494D4"))) PPC_WEAK_FUNC(sub_825494D4);
PPC_FUNC_IMPL(__imp__sub_825494D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825494D8"))) PPC_WEAK_FUNC(sub_825494D8);
PPC_FUNC_IMPL(__imp__sub_825494D8) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// li r8,-1
	ctx.r8.s64 = -1;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// lfs f13,-18544(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -18544);
	ctx.f13.f64 = double(temp.f32);
	// li r6,255
	ctx.r6.s64 = 255;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// stw r8,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r8.u32);
	// stw r7,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r7.u32);
	// stb r6,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r6.u8);
	// stb r11,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, r11.u8);
	// stb r4,150(r1)
	PPC_STORE_U8(ctx.r1.u32 + 150, ctx.r4.u8);
	// bne cr6,0x82549578
	if (!cr6.eq) goto loc_82549578;
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
loc_82549578:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x82549580;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82549118
	ctx.lr = 0x82549590;
	sub_82549118(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
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

__attribute__((alias("__imp__sub_825495A8"))) PPC_WEAK_FUNC(sub_825495A8);
PPC_FUNC_IMPL(__imp__sub_825495A8) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x825495B0;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// lbz r6,351(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 351);
	// lis r30,-32248
	r30.s64 = -2113404928;
	// lbz r31,335(r1)
	r31.u64 = PPC_LOAD_U8(ctx.r1.u32 + 335);
	// rlwimi r7,r11,1,30,30
	ctx.r7.u64 = (__builtin_rotateleft32(r11.u32, 1) & 0x2) | (ctx.r7.u64 & 0xFFFFFFFFFFFFFFFD);
	// lwz r29,308(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// lwz r28,324(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r7,r7,30
	ctx.r7.u64 = ctx.r7.u32 & 0x3;
	// lwz r27,356(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 356);
	// li r26,-1
	r26.s64 = -1;
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// rlwimi r6,r7,1,0,30
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r7.u32, 1) & 0xFFFFFFFE) | (ctx.r6.u64 & 0xFFFFFFFF00000001);
	// lwz r7,340(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	// lfs f0,-18544(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -18544);
	f0.f64 = double(temp.f32);
	// li r30,-1
	r30.s64 = -1;
	// rlwimi r31,r6,1,0,30
	r31.u64 = (__builtin_rotateleft32(ctx.r6.u32, 1) & 0xFFFFFFFE) | (r31.u64 & 0xFFFFFFFF00000001);
	// stfs f0,140(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// li r25,255
	r25.s64 = 255;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// rlwinm r31,r31,2,24,29
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFC;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// stw r26,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r26.u32);
	// stw r30,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r30.u32);
	// stb r25,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, r25.u8);
	// stb r11,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, r11.u8);
	// stb r31,150(r1)
	PPC_STORE_U8(ctx.r1.u32 + 150, r31.u8);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// stw r29,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r29.u32);
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// stw r7,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r7.u32);
	// stw r27,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r27.u32);
	// bl 0x825491f0
	ctx.lr = 0x82549654;
	sub_825491F0(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8254965C"))) PPC_WEAK_FUNC(sub_8254965C);
PPC_FUNC_IMPL(__imp__sub_8254965C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82549660"))) PPC_WEAK_FUNC(sub_82549660);
PPC_FUNC_IMPL(__imp__sub_82549660) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	ctx.lr = 0x82549668;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r11,0
	r11.s64 = 0;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// lfs f13,-18544(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -18544);
	ctx.f13.f64 = double(temp.f32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r5,255
	ctx.r5.s64 = 255;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// stw r8,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r8.u32);
	// stw r7,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r7.u32);
	// stb r5,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r5.u8);
	// stb r11,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, r11.u8);
	// stb r4,150(r1)
	PPC_STORE_U8(ctx.r1.u32 + 150, ctx.r4.u8);
	// bne cr6,0x825496fc
	if (!cr6.eq) goto loc_825496FC;
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
loc_825496FC:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x82549704;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// bl 0x825491f0
	ctx.lr = 0x82549718;
	sub_825491F0(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82549720"))) PPC_WEAK_FUNC(sub_82549720);
PPC_FUNC_IMPL(__imp__sub_82549720) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82549728;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// bl 0x821c9790
	ctx.lr = 0x8254974C;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// bl 0x825492c8
	ctx.lr = 0x82549768;
	sub_825492C8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82549770"))) PPC_WEAK_FUNC(sub_82549770);
PPC_FUNC_IMPL(__imp__sub_82549770) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f12,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lfs f11,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// addi r11,r3,76
	r11.s64 = ctx.r3.s64 + 76;
	// lfs f0,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	f0.f64 = double(temp.f32);
	// li r10,128
	ctx.r10.s64 = 128;
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lfs f0,21524(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 21524);
	f0.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fdivs f9,f0,f11
	ctx.f9.f64 = double(float(f0.f64 / ctx.f11.f64));
	// lfs f0,14672(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14672);
	f0.f64 = double(temp.f32);
	// lfs f13,16680(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 16680);
	ctx.f13.f64 = double(temp.f32);
	// stfs f10,36(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f9,44(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// fsubs f8,f12,f10
	ctx.f8.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// fdivs f7,f13,f10
	ctx.f7.f64 = double(float(ctx.f13.f64 / ctx.f10.f64));
	// stfs f7,32(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// fdivs f6,f0,f8
	ctx.f6.f64 = double(float(f0.f64 / ctx.f8.f64));
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f6,40(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
loc_825497CC:
	// stfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfs f13,512(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 512);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f13
	ctx.f12.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// fsel f11,f12,f0,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfs f10,1024(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1024);
	ctx.f10.f64 = double(temp.f32);
	// fmr f9,f11
	ctx.f9.f64 = ctx.f11.f64;
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fsel f7,f8,f9,f10
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? ctx.f9.f64 : ctx.f10.f64;
	// stfs f7,0(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfs f6,1536(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1536);
	ctx.f6.f64 = double(temp.f32);
	// fmr f5,f7
	ctx.f5.f64 = ctx.f7.f64;
	// fsubs f4,f5,f6
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f6.f64));
	// fsel f3,f4,f5,f6
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? ctx.f5.f64 : ctx.f6.f64;
	// stfs f3,0(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfs f2,2048(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 2048);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// fsubs f13,f1,f2
	ctx.f13.f64 = double(float(ctx.f1.f64 - ctx.f2.f64));
	// fsel f12,f13,f1,f2
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? ctx.f1.f64 : ctx.f2.f64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfs f11,2560(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 2560);
	ctx.f11.f64 = double(temp.f32);
	// fmr f10,f12
	ctx.f10.f64 = ctx.f12.f64;
	// fsubs f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// fsel f8,f9,f10,f11
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? ctx.f10.f64 : ctx.f11.f64;
	// stfs f8,0(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfs f7,3072(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3072);
	ctx.f7.f64 = double(temp.f32);
	// fmr f6,f8
	ctx.f6.f64 = ctx.f8.f64;
	// fsubs f5,f6,f7
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f7.f64));
	// fsel f4,f5,f6,f7
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f6.f64 : ctx.f7.f64;
	// stfs f4,0(r11)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfs f3,3584(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3584);
	ctx.f3.f64 = double(temp.f32);
	// fmr f2,f4
	ctx.f2.f64 = ctx.f4.f64;
	// fsubs f1,f2,f3
	ctx.f1.f64 = double(float(ctx.f2.f64 - ctx.f3.f64));
	// fsel f13,f1,f2,f3
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f2.f64 : ctx.f3.f64;
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x825497cc
	if (!cr0.eq) goto loc_825497CC;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82549868"))) PPC_WEAK_FUNC(sub_82549868);
PPC_FUNC_IMPL(__imp__sub_82549868) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lfs f13,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,-17216(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17216);
	f0.f64 = double(temp.f32);
	// fmuls f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f10,20(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// fmuls f9,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f9,24(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// fmuls f8,f11,f0
	ctx.f8.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f8,28(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82549898"))) PPC_WEAK_FUNC(sub_82549898);
PPC_FUNC_IMPL(__imp__sub_82549898) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lfs f13,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,-17212(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17212);
	f0.f64 = double(temp.f32);
	// fmuls f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f10,20(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// fmuls f9,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f9,24(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// fmuls f8,f11,f0
	ctx.f8.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f8,28(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// b 0x82549770
	sub_82549770(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_825498C8"))) PPC_WEAK_FUNC(sub_825498C8);
PPC_FUNC_IMPL(__imp__sub_825498C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// li r10,20
	ctx.r10.s64 = 20;
	// addi r9,r11,-32440
	ctx.r9.s64 = r11.s64 + -32440;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cntlzw r4,r11
	ctx.r4.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,14884(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f11,-11624(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -11624);
	ctx.f11.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f8,31308(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 31308);
	ctx.f8.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stfs f12,12(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stfs f11,16(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// lfs f13,17032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// lfs f10,27640(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	ctx.f10.f64 = double(temp.f32);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f7,14988(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14988);
	ctx.f7.f64 = double(temp.f32);
	// rlwinm r9,r4,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// lfs f9,-13148(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -13148);
	ctx.f9.f64 = double(temp.f32);
	// li r8,3
	ctx.r8.s64 = 3;
	// lfs f6,12932(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 12932);
	ctx.f6.f64 = double(temp.f32);
	// xori r7,r9,1
	ctx.r7.u64 = ctx.r9.u64 ^ 1;
	// lfs f5,-31376(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -31376);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,31016(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	ctx.f4.f64 = double(temp.f32);
	// stw r8,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r8.u32);
	// lfs f3,24920(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24920);
	ctx.f3.f64 = double(temp.f32);
	// stb r7,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r7.u8);
	// stfs f8,24(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f13,28(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f10,32(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f0,36(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f7,40(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f9,48(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f13,44(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f13,52(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f0,56(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stfs f6,60(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stfs f0,64(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f5,68(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stfs f0,72(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stfs f0,76(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// stfs f9,80(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// stfs f0,84(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f12,88(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// stfs f10,92(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// stfs f11,96(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// stfs f4,100(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// stfs f3,104(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825499BC"))) PPC_WEAK_FUNC(sub_825499BC);
PPC_FUNC_IMPL(__imp__sub_825499BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825499C0"))) PPC_WEAK_FUNC(sub_825499C0);
PPC_FUNC_IMPL(__imp__sub_825499C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r3,-32448(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -32448);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825499CC"))) PPC_WEAK_FUNC(sub_825499CC);
PPC_FUNC_IMPL(__imp__sub_825499CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825499D0"))) PPC_WEAK_FUNC(sub_825499D0);
PPC_FUNC_IMPL(__imp__sub_825499D0) {
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
	// li r3,108
	ctx.r3.s64 = 108;
	// bl 0x82130528
	ctx.lr = 0x825499E4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82549a00
	if (cr6.eq) goto loc_82549A00;
	// bl 0x825498c8
	ctx.lr = 0x825499F0;
	sub_825498C8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82549A00:
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

__attribute__((alias("__imp__sub_82549A14"))) PPC_WEAK_FUNC(sub_82549A14);
PPC_FUNC_IMPL(__imp__sub_82549A14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82549A18"))) PPC_WEAK_FUNC(sub_82549A18);
PPC_FUNC_IMPL(__imp__sub_82549A18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r3,-32444(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -32444);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82549A24"))) PPC_WEAK_FUNC(sub_82549A24);
PPC_FUNC_IMPL(__imp__sub_82549A24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82549A28"))) PPC_WEAK_FUNC(sub_82549A28);
PPC_FUNC_IMPL(__imp__sub_82549A28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f11,31308(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31308);
	ctx.f11.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f13,14988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r3,8268
	r11.s64 = ctx.r3.s64 + 8268;
	// lfs f12,-26872(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -26872);
	ctx.f12.f64 = double(temp.f32);
	// li r10,128
	ctx.r10.s64 = 128;
	// lfs f10,11368(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11368);
	ctx.f10.f64 = double(temp.f32);
	// stfs f13,16(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f0,28(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// lfs f13,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,12428(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12428);
	f0.f64 = double(temp.f32);
	// stfs f12,0(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f11,8(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f10,12(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
loc_82549A94:
	// stfs f0,-8192(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -8192, temp.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfs f12,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82549a94
	if (!cr0.eq) goto loc_82549A94;
	// addi r11,r3,4172
	r11.s64 = ctx.r3.s64 + 4172;
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// li r8,7
	ctx.r8.s64 = 7;
loc_82549ABC:
	// stfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// li r10,128
	ctx.r10.s64 = 128;
loc_82549AC4:
	// stfs f0,-3584(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -3584, temp.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82549ac4
	if (!cr0.eq) goto loc_82549AC4;
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x82549abc
	if (!cr0.eq) goto loc_82549ABC;
	// bl 0x82549770
	ctx.lr = 0x82549AE8;
	sub_82549770(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,7756
	ctx.r10.s64 = ctx.r3.s64 + 7756;
	// lfs f0,8884(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8884);
	f0.f64 = double(temp.f32);
loc_82549AF8:
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// lfs f13,32(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,36(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// fmuls f7,f12,f0
	ctx.f7.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lfs f9,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f9.f64 = double(temp.f32);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fdivs f6,f8,f13
	ctx.f6.f64 = double(float(ctx.f8.f64 / ctx.f13.f64));
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fsel f4,f5,f7,f6
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f7.f64 : ctx.f6.f64;
	// fdivs f3,f9,f4
	ctx.f3.f64 = double(float(ctx.f9.f64 / ctx.f4.f64));
	// fsqrts f2,f3
	ctx.f2.f64 = double(float(sqrt(ctx.f3.f64)));
	// stfs f2,256(r10)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r10.u32 + 256, temp.u32);
	// lfs f1,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f1.f64 = double(temp.f32);
	// lfs f13,36(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f11,f8,f1
	ctx.f11.f64 = double(float(ctx.f8.f64 / ctx.f1.f64));
	// fadds f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// fdivs f9,f12,f10
	ctx.f9.f64 = double(float(ctx.f12.f64 / ctx.f10.f64));
	// fsqrts f8,f9
	ctx.f8.f64 = double(float(sqrt(ctx.f9.f64)));
	// stfs f8,0(r10)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// blt cr6,0x82549af8
	if (cr6.lt) goto loc_82549AF8;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82549B74"))) PPC_WEAK_FUNC(sub_82549B74);
PPC_FUNC_IMPL(__imp__sub_82549B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82549B78"))) PPC_WEAK_FUNC(sub_82549B78);
PPC_FUNC_IMPL(__imp__sub_82549B78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,44(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmuls f8,f0,f1
	ctx.f8.f64 = double(float(f0.f64 * ctx.f1.f64));
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// rlwinm r10,r4,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 7) & 0xFFFFFF80;
	// lfs f13,-31404(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31404);
	ctx.f13.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f11,8880(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8880);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8876(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8876);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f9.f64 = double(temp.f32);
	// fneg f7,f8
	ctx.f7.u64 = ctx.f8.u64 ^ 0x8000000000000000;
	// lfs f12,17032(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 17032);
	ctx.f12.f64 = double(temp.f32);
	// fsel f6,f7,f0,f8
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? f0.f64 : ctx.f8.f64;
	// fsel f5,f6,f6,f0
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f6.f64 : f0.f64;
	// fsubs f4,f5,f13
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f13.f64));
	// fsel f3,f4,f13,f5
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? ctx.f13.f64 : ctx.f5.f64;
	// fsel f2,f3,f11,f10
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f11.f64 : ctx.f10.f64;
	// fsubs f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// fadds f0,f1,f2
	f0.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// fsubs f13,f3,f0
	ctx.f13.f64 = double(float(ctx.f3.f64 - f0.f64));
	// fsubs f11,f0,f9
	ctx.f11.f64 = double(float(f0.f64 - ctx.f9.f64));
	// fsel f10,f13,f0,f11
	ctx.f10.f64 = ctx.f13.f64 >= 0.0 ? f0.f64 : ctx.f11.f64;
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lwz r11,-12(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r4,r11,147
	ctx.r4.s64 = r11.s64 + 147;
	// fsubs f8,f6,f10
	ctx.f8.f64 = double(float(ctx.f6.f64 - ctx.f10.f64));
	// addi r11,r11,148
	r11.s64 = r11.s64 + 148;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f7,r10,r3
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	ctx.f7.f64 = double(temp.f32);
	// lfsx f6,r9,r3
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f6,f7
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f7.f64));
	// fmadds f4,f5,f8,f7
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fsubs f3,f12,f4
	ctx.f3.f64 = double(float(ctx.f12.f64 - ctx.f4.f64));
	// fsel f1,f3,f12,f4
	ctx.f1.f64 = ctx.f3.f64 >= 0.0 ? ctx.f12.f64 : ctx.f4.f64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82549C20"))) PPC_WEAK_FUNC(sub_82549C20);
PPC_FUNC_IMPL(__imp__sub_82549C20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,44(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmuls f8,f0,f1
	ctx.f8.f64 = double(float(f0.f64 * ctx.f1.f64));
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// rlwinm r10,r4,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 7) & 0xFFFFFF80;
	// lfs f13,-31404(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31404);
	ctx.f13.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f11,8880(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8880);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8876(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8876);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f9.f64 = double(temp.f32);
	// fneg f7,f8
	ctx.f7.u64 = ctx.f8.u64 ^ 0x8000000000000000;
	// lfs f12,17032(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 17032);
	ctx.f12.f64 = double(temp.f32);
	// fsel f6,f7,f0,f8
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? f0.f64 : ctx.f8.f64;
	// fsel f5,f6,f6,f0
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f6.f64 : f0.f64;
	// fsubs f4,f5,f13
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f13.f64));
	// fsel f3,f4,f13,f5
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? ctx.f13.f64 : ctx.f5.f64;
	// fsel f2,f3,f11,f10
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f11.f64 : ctx.f10.f64;
	// fsubs f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// fadds f0,f1,f2
	f0.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// fsubs f13,f3,f0
	ctx.f13.f64 = double(float(ctx.f3.f64 - f0.f64));
	// fsubs f11,f0,f9
	ctx.f11.f64 = double(float(f0.f64 - ctx.f9.f64));
	// fsel f10,f13,f0,f11
	ctx.f10.f64 = ctx.f13.f64 >= 0.0 ? f0.f64 : ctx.f11.f64;
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f9.u64);
	// lwz r11,-12(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r4,r11,1043
	ctx.r4.s64 = r11.s64 + 1043;
	// fsubs f8,f6,f10
	ctx.f8.f64 = double(float(ctx.f6.f64 - ctx.f10.f64));
	// addi r11,r11,1044
	r11.s64 = r11.s64 + 1044;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f7,r10,r3
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	ctx.f7.f64 = double(temp.f32);
	// lfsx f6,r9,r3
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f6,f7
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f7.f64));
	// fmadds f4,f5,f8,f7
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fsubs f3,f12,f4
	ctx.f3.f64 = double(float(ctx.f12.f64 - ctx.f4.f64));
	// fsel f1,f3,f12,f4
	ctx.f1.f64 = ctx.f3.f64 >= 0.0 ? ctx.f12.f64 : ctx.f4.f64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82549CC8"))) PPC_WEAK_FUNC(sub_82549CC8);
PPC_FUNC_IMPL(__imp__sub_82549CC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// fabs f0,f1
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// lfs f13,44(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f12,8880(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8880);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8876(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8876);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f9,f0,f13
	ctx.f9.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,-31404(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31404);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f10.f64 = double(temp.f32);
	// fneg f8,f9
	ctx.f8.u64 = ctx.f9.u64 ^ 0x8000000000000000;
	// fsel f7,f8,f0,f9
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? f0.f64 : ctx.f9.f64;
	// fsel f6,f7,f7,f0
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f7.f64 : f0.f64;
	// fsubs f5,f6,f13
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// fsel f4,f5,f13,f6
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f13.f64 : ctx.f6.f64;
	// fsel f3,f4,f12,f11
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? ctx.f12.f64 : ctx.f11.f64;
	// fsubs f2,f4,f3
	ctx.f2.f64 = double(float(ctx.f4.f64 - ctx.f3.f64));
	// fadds f1,f2,f3
	ctx.f1.f64 = double(float(ctx.f2.f64 + ctx.f3.f64));
	// fsubs f13,f1,f10
	ctx.f13.f64 = double(float(ctx.f1.f64 - ctx.f10.f64));
	// fsubs f0,f4,f1
	f0.f64 = double(float(ctx.f4.f64 - ctx.f1.f64));
	// fsel f12,f0,f1,f13
	ctx.f12.f64 = f0.f64 >= 0.0 ? ctx.f1.f64 : ctx.f13.f64;
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f11.u64);
	// lwz r11,-12(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// addi r6,r11,2067
	ctx.r6.s64 = r11.s64 + 2067;
	// addi r5,r11,2068
	ctx.r5.s64 = r11.s64 + 2068;
	// fsubs f10,f7,f12
	ctx.f10.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f9,r4,r3
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r3.u32);
	ctx.f9.f64 = double(temp.f32);
	// lfsx f8,r11,r3
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// fmadds f1,f7,f10,f9
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f10.f64 + ctx.f9.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82549D5C"))) PPC_WEAK_FUNC(sub_82549D5C);
PPC_FUNC_IMPL(__imp__sub_82549D5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82549D60"))) PPC_WEAK_FUNC(sub_82549D60);
PPC_FUNC_IMPL(__imp__sub_82549D60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
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
	// stfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lfs f0,16(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	f0.f64 = double(temp.f32);
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lfs f13,16(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r5,8272
	ctx.r9.s64 = ctx.r5.s64 + 8272;
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// addi r10,r3,8268
	ctx.r10.s64 = ctx.r3.s64 + 8268;
	// addi r11,r6,76
	r11.s64 = ctx.r6.s64 + 76;
	// subf r4,r6,r5
	ctx.r4.s64 = ctx.r5.s64 - ctx.r6.s64;
	// subf r31,r6,r3
	r31.s64 = ctx.r3.s64 - ctx.r6.s64;
	// subf r30,r3,r5
	r30.s64 = ctx.r5.s64 - ctx.r3.s64;
	// li r8,16
	ctx.r8.s64 = 16;
	// fmadds f11,f12,f31,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64 + f0.f64));
	// stfs f11,16(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// lfs f10,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmadds f7,f8,f31,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64 + ctx.f10.f64));
	// stfs f7,0(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lfs f6,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f5,f6
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f6.f64));
	// fmadds f3,f4,f31,f6
	ctx.f3.f64 = double(float(ctx.f4.f64 * f31.f64 + ctx.f6.f64));
	// stfs f3,8(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// lfs f2,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f0,f1,f2
	f0.f64 = double(float(ctx.f1.f64 - ctx.f2.f64));
	// fmadds f13,f0,f31,f2
	ctx.f13.f64 = double(float(f0.f64 * f31.f64 + ctx.f2.f64));
	// stfs f13,4(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lfs f12,12(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,12(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fmadds f9,f10,f31,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64 + ctx.f12.f64));
	// stfs f9,12(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// lfs f8,20(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,20(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// fmadds f5,f6,f31,f8
	ctx.f5.f64 = double(float(ctx.f6.f64 * f31.f64 + ctx.f8.f64));
	// stfs f5,20(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// lfs f4,24(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,24(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f4.f64));
	// fmadds f1,f2,f31,f4
	ctx.f1.f64 = double(float(ctx.f2.f64 * f31.f64 + ctx.f4.f64));
	// stfs f1,24(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// lfs f0,28(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	f0.f64 = double(temp.f32);
	// lfs f13,28(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmadds f11,f12,f31,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64 + f0.f64));
	// stfs f11,28(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
loc_82549E38:
	// lfsx f0,r4,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmadds f11,f12,f31,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64 + f0.f64));
	// stfsx f11,r31,r11
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + r11.u32, temp.u32);
	// lfsx f10,r30,r10
	temp.u32 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8192);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmadds f7,f8,f31,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64 + ctx.f10.f64));
	// stfs f7,0(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfs f6,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-8192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -8192);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f5.f64));
	// fmadds f3,f4,f31,f5
	ctx.f3.f64 = double(float(ctx.f4.f64 * f31.f64 + ctx.f5.f64));
	// stfs f3,-8188(r10)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r10.u32 + -8188, temp.u32);
	// lfs f2,8196(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8196);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f0,f2,f1
	f0.f64 = double(float(ctx.f2.f64 - ctx.f1.f64));
	// fmadds f13,f0,f31,f1
	ctx.f13.f64 = double(float(f0.f64 * f31.f64 + ctx.f1.f64));
	// stfs f13,4(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// lfs f12,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-8188(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -8188);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// fmadds f9,f10,f31,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64 + ctx.f11.f64));
	// stfs f9,-8184(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + -8184, temp.u32);
	// lfs f8,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,8200(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8200);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// fmadds f5,f6,f31,f8
	ctx.f5.f64 = double(float(ctx.f6.f64 * f31.f64 + ctx.f8.f64));
	// stfs f5,8(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lfs f4,-8184(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -8184);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f4.f64));
	// fmadds f1,f2,f31,f4
	ctx.f1.f64 = double(float(ctx.f2.f64 * f31.f64 + ctx.f4.f64));
	// stfs f1,-8180(r10)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + -8180, temp.u32);
	// lfs f0,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,8204(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8204);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmadds f11,f12,f31,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64 + f0.f64));
	// stfs f11,12(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// lfs f10,-8180(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -8180);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmadds f7,f8,f31,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64 + ctx.f10.f64));
	// stfs f7,-8176(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + -8176, temp.u32);
	// lfs f6,12(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,8208(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8208);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f5,f6
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f6.f64));
	// fmadds f3,f4,f31,f6
	ctx.f3.f64 = double(float(ctx.f4.f64 * f31.f64 + ctx.f6.f64));
	// stfs f3,16(r10)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// lfs f2,-8176(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -8176);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f0,f1,f2
	f0.f64 = double(float(ctx.f1.f64 - ctx.f2.f64));
	// fmadds f13,f0,f31,f2
	ctx.f13.f64 = double(float(f0.f64 * f31.f64 + ctx.f2.f64));
	// stfs f13,-8172(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + -8172, temp.u32);
	// lfs f12,16(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8212(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8212);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fmadds f9,f10,f31,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64 + ctx.f12.f64));
	// stfs f9,20(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 20, temp.u32);
	// lfs f8,-8172(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -8172);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// fmadds f5,f6,f31,f8
	ctx.f5.f64 = double(float(ctx.f6.f64 * f31.f64 + ctx.f8.f64));
	// stfs f5,-8168(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + -8168, temp.u32);
	// lfs f4,20(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,8216(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8216);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f4.f64));
	// fmadds f1,f2,f31,f4
	ctx.f1.f64 = double(float(ctx.f2.f64 * f31.f64 + ctx.f4.f64));
	// stfs f1,24(r10)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 24, temp.u32);
	// lfs f0,-8168(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -8168);
	f0.f64 = double(temp.f32);
	// lfs f13,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmadds f11,f12,f31,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64 + f0.f64));
	// stfs f11,-8164(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + -8164, temp.u32);
	// lfs f10,24(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8220(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8220);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmadds f7,f8,f31,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64 + ctx.f10.f64));
	// stfs f7,28(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + 28, temp.u32);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// addi r9,r9,32
	ctx.r9.s64 = ctx.r9.s64 + 32;
	// bne 0x82549e38
	if (!cr0.eq) goto loc_82549E38;
	// addi r11,r6,588
	r11.s64 = ctx.r6.s64 + 588;
	// addi r10,r3,4172
	ctx.r10.s64 = ctx.r3.s64 + 4172;
	// addi r9,r5,4176
	ctx.r9.s64 = ctx.r5.s64 + 4176;
	// li r7,7
	ctx.r7.s64 = 7;
loc_82549F9C:
	// li r8,16
	ctx.r8.s64 = 16;
loc_82549FA0:
	// lfsx f0,r11,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r4.u32);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmadds f11,f12,f31,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64 + f0.f64));
	// stfsx f11,r11,r31
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + r31.u32, temp.u32);
	// lfsx f10,r10,r30
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,3584(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3584);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmadds f7,f8,f31,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64 + ctx.f10.f64));
	// stfs f7,0(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfs f6,-3584(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -3584);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f5,f6
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f6.f64));
	// fmadds f3,f4,f31,f6
	ctx.f3.f64 = double(float(ctx.f4.f64 * f31.f64 + ctx.f6.f64));
	// stfs f3,-3580(r10)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r10.u32 + -3580, temp.u32);
	// lfs f2,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,3588(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3588);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f0,f1,f2
	f0.f64 = double(float(ctx.f1.f64 - ctx.f2.f64));
	// fmadds f13,f0,f31,f2
	ctx.f13.f64 = double(float(f0.f64 * f31.f64 + ctx.f2.f64));
	// stfs f13,4(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// lfs f12,-3580(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -3580);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fmadds f9,f10,f31,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64 + ctx.f12.f64));
	// stfs f9,-3576(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + -3576, temp.u32);
	// lfs f8,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,3592(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3592);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// fmadds f5,f6,f31,f8
	ctx.f5.f64 = double(float(ctx.f6.f64 * f31.f64 + ctx.f8.f64));
	// stfs f5,8(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lfs f4,-3576(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -3576);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f4.f64));
	// fmadds f1,f2,f31,f4
	ctx.f1.f64 = double(float(ctx.f2.f64 * f31.f64 + ctx.f4.f64));
	// stfs f1,-3572(r10)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + -3572, temp.u32);
	// lfs f0,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,3596(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3596);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmadds f11,f12,f31,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64 + f0.f64));
	// stfs f11,12(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// lfs f10,-3572(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -3572);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmadds f7,f8,f31,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64 + ctx.f10.f64));
	// stfs f7,-3568(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + -3568, temp.u32);
	// lfs f6,12(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,3600(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3600);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f5,f6
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f6.f64));
	// fmadds f3,f4,f31,f6
	ctx.f3.f64 = double(float(ctx.f4.f64 * f31.f64 + ctx.f6.f64));
	// stfs f3,16(r10)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// lfs f2,-3568(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -3568);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f0,f1,f2
	f0.f64 = double(float(ctx.f1.f64 - ctx.f2.f64));
	// fmadds f13,f0,f31,f2
	ctx.f13.f64 = double(float(f0.f64 * f31.f64 + ctx.f2.f64));
	// stfs f13,-3564(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + -3564, temp.u32);
	// lfs f12,16(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,3604(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3604);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fmadds f9,f10,f31,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64 + ctx.f12.f64));
	// stfs f9,20(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 20, temp.u32);
	// lfs f8,-3564(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -3564);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// fmadds f5,f6,f31,f8
	ctx.f5.f64 = double(float(ctx.f6.f64 * f31.f64 + ctx.f8.f64));
	// stfs f5,-3560(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + -3560, temp.u32);
	// lfs f4,20(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,3608(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3608);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f4.f64));
	// fmadds f1,f2,f31,f4
	ctx.f1.f64 = double(float(ctx.f2.f64 * f31.f64 + ctx.f4.f64));
	// stfs f1,24(r10)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 24, temp.u32);
	// lfs f0,-3560(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -3560);
	f0.f64 = double(temp.f32);
	// lfs f13,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmadds f11,f12,f31,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64 + f0.f64));
	// stfs f11,-3556(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + -3556, temp.u32);
	// lfs f10,24(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,3612(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3612);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmadds f7,f8,f31,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64 + ctx.f10.f64));
	// stfs f7,28(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + 28, temp.u32);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// addi r9,r9,32
	ctx.r9.s64 = ctx.r9.s64 + 32;
	// bne 0x82549fa0
	if (!cr0.eq) goto loc_82549FA0;
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne 0x82549f9c
	if (!cr0.eq) goto loc_82549F9C;
	// bl 0x82549770
	ctx.lr = 0x8254A100;
	sub_82549770(ctx, base);
	// addi r9,r5,7760
	ctx.r9.s64 = ctx.r5.s64 + 7760;
	// addi r10,r3,7756
	ctx.r10.s64 = ctx.r3.s64 + 7756;
	// addi r11,r6,8012
	r11.s64 = ctx.r6.s64 + 8012;
	// li r8,8
	ctx.r8.s64 = 8;
loc_8254A110:
	// lfsx f0,r4,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmadds f11,f12,f31,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64 + f0.f64));
	// stfsx f11,r31,r11
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + r11.u32, temp.u32);
	// lfsx f10,r30,r10
	temp.u32 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,-256(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -256);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmadds f7,f8,f31,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64 + ctx.f10.f64));
	// stfs f7,0(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfs f6,256(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 256);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f5,f6
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f6.f64));
	// fmadds f3,f4,f31,f6
	ctx.f3.f64 = double(float(ctx.f4.f64 * f31.f64 + ctx.f6.f64));
	// stfs f3,260(r10)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r10.u32 + 260, temp.u32);
	// lfs f2,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-252(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -252);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f0,f1,f2
	f0.f64 = double(float(ctx.f1.f64 - ctx.f2.f64));
	// fmadds f13,f0,f31,f2
	ctx.f13.f64 = double(float(f0.f64 * f31.f64 + ctx.f2.f64));
	// stfs f13,4(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// lfs f12,260(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 260);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fmadds f9,f10,f31,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64 + ctx.f12.f64));
	// stfs f9,264(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 264, temp.u32);
	// lfs f8,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-248(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -248);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// fmadds f5,f6,f31,f8
	ctx.f5.f64 = double(float(ctx.f6.f64 * f31.f64 + ctx.f8.f64));
	// stfs f5,8(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lfs f4,264(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 264);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f4.f64));
	// fmadds f1,f2,f31,f4
	ctx.f1.f64 = double(float(ctx.f2.f64 * f31.f64 + ctx.f4.f64));
	// stfs f1,268(r10)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 268, temp.u32);
	// lfs f0,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,-244(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -244);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmadds f11,f12,f31,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64 + f0.f64));
	// stfs f11,12(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// lfs f10,268(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 268);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmadds f7,f8,f31,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64 + ctx.f10.f64));
	// stfs f7,272(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + 272, temp.u32);
	// lfs f6,12(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-240(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -240);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f5,f6
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f6.f64));
	// fmadds f3,f4,f31,f6
	ctx.f3.f64 = double(float(ctx.f4.f64 * f31.f64 + ctx.f6.f64));
	// stfs f3,16(r10)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// lfs f2,272(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 272);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f0,f1,f2
	f0.f64 = double(float(ctx.f1.f64 - ctx.f2.f64));
	// fmadds f13,f0,f31,f2
	ctx.f13.f64 = double(float(f0.f64 * f31.f64 + ctx.f2.f64));
	// stfs f13,276(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 276, temp.u32);
	// lfs f12,16(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-236(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -236);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fmadds f9,f10,f31,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64 + ctx.f12.f64));
	// stfs f9,20(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 20, temp.u32);
	// lfs f8,276(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 276);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// fmadds f5,f6,f31,f8
	ctx.f5.f64 = double(float(ctx.f6.f64 * f31.f64 + ctx.f8.f64));
	// stfs f5,280(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + 280, temp.u32);
	// lfs f4,20(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,-232(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -232);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f4.f64));
	// fmadds f1,f2,f31,f4
	ctx.f1.f64 = double(float(ctx.f2.f64 * f31.f64 + ctx.f4.f64));
	// stfs f1,24(r10)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 24, temp.u32);
	// lfs f0,280(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 280);
	f0.f64 = double(temp.f32);
	// lfs f13,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmadds f11,f12,f31,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64 + f0.f64));
	// stfs f11,284(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 284, temp.u32);
	// lfs f10,24(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,-228(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -228);
	ctx.f9.f64 = double(temp.f32);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmadds f7,f8,f31,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64 + ctx.f10.f64));
	// stfs f7,28(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + 28, temp.u32);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// addi r9,r9,32
	ctx.r9.s64 = ctx.r9.s64 + 32;
	// bne 0x8254a110
	if (!cr0.eq) goto loc_8254A110;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-32(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8254A280"))) PPC_WEAK_FUNC(sub_8254A280);
PPC_FUNC_IMPL(__imp__sub_8254A280) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	ctx.lr = 0x8254A288;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9b4
	ctx.lr = 0x8254A290;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,356(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 356);
	// fmr f21,f7
	ctx.fpscr.disableFlushMode();
	f21.f64 = ctx.f7.f64;
	// lwz r30,364(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 364);
	// fmr f20,f8
	f20.f64 = ctx.f8.f64;
	// fmr f22,f6
	f22.f64 = ctx.f6.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f24,f4
	f24.f64 = ctx.f4.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f23,f5
	f23.f64 = ctx.f5.f64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f8,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// fmr f10,f1
	ctx.f10.f64 = ctx.f1.f64;
	// lfs f7,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// fmr f26,f2
	f26.f64 = ctx.f2.f64;
	// fmuls f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f7.f64));
	// lfs f5,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f4.f64 = double(temp.f32);
	// fmr f28,f3
	f28.f64 = ctx.f3.f64;
	// lfs f3,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f3.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f2,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f9,44(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f9.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// lfs f0,-31404(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31404);
	f0.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f12,8880(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8880);
	ctx.f12.f64 = double(temp.f32);
	// lwz r28,380(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 380);
	// lfs f11,8876(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8876);
	ctx.f11.f64 = double(temp.f32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lfs f29,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f29.f64 = double(temp.f32);
	// fmadds f1,f5,f4,f6
	ctx.f1.f64 = double(float(ctx.f5.f64 * ctx.f4.f64 + ctx.f6.f64));
	// lfs f13,14192(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f30,f3,f2,f1
	f30.f64 = double(float(ctx.f3.f64 * ctx.f2.f64 + ctx.f1.f64));
	// fabs f8,f30
	ctx.f8.u64 = f30.u64 & ~0x8000000000000000;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// fmuls f7,f8,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f9.f64));
	// fneg f6,f7
	ctx.f6.u64 = ctx.f7.u64 ^ 0x8000000000000000;
	// fsel f5,f6,f31,f7
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? f31.f64 : ctx.f7.f64;
	// fsel f4,f5,f5,f31
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f5.f64 : f31.f64;
	// fsubs f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 - f0.f64));
	// fsel f2,f3,f0,f4
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? f0.f64 : ctx.f4.f64;
	// fsel f0,f2,f12,f11
	f0.f64 = ctx.f2.f64 >= 0.0 ? ctx.f12.f64 : ctx.f11.f64;
	// fsubs f12,f2,f0
	ctx.f12.f64 = double(float(ctx.f2.f64 - f0.f64));
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + f0.f64));
	// fsubs f9,f2,f11
	ctx.f9.f64 = double(float(ctx.f2.f64 - ctx.f11.f64));
	// fsubs f8,f11,f29
	ctx.f8.f64 = double(float(ctx.f11.f64 - f29.f64));
	// fsel f7,f9,f11,f8
	ctx.f7.f64 = ctx.f9.f64 >= 0.0 ? ctx.f11.f64 : ctx.f8.f64;
	// fctiwz f6,f7
	ctx.f6.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f6.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r5,r11,2067
	ctx.r5.s64 = r11.s64 + 2067;
	// addi r11,r11,2068
	r11.s64 = r11.s64 + 2068;
	// fsubs f5,f5,f7
	ctx.f5.f64 = double(float(ctx.f5.f64 - ctx.f7.f64));
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f4,r10,r31
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	ctx.f4.f64 = double(temp.f32);
	// lfsx f3,r9,r31
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f4.f64));
	// fmadds f25,f2,f5,f4
	f25.f64 = double(float(ctx.f2.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fmuls f0,f25,f10
	f0.f64 = double(float(f25.f64 * ctx.f10.f64));
	// fneg f12,f0
	ctx.f12.u64 = f0.u64 ^ 0x8000000000000000;
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fsel f10,f11,f12,f13
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? ctx.f12.f64 : ctx.f13.f64;
	// fsubs f9,f10,f29
	ctx.f9.f64 = double(float(ctx.f10.f64 - f29.f64));
	// fsel f19,f9,f29,f10
	f19.f64 = ctx.f9.f64 >= 0.0 ? f29.f64 : ctx.f10.f64;
	// stfs f19,0(r28)
	temp.f32 = float(f19.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// bl 0x82549b78
	ctx.lr = 0x8254A3AC;
	sub_82549B78(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// fmr f27,f1
	ctx.fpscr.disableFlushMode();
	f27.f64 = ctx.f1.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x82549c20
	ctx.lr = 0x8254A3BC;
	sub_82549C20(ctx, base);
	// fdivs f8,f19,f25
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(f19.f64 / f25.f64));
	// lfs f6,28(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	ctx.f6.f64 = double(temp.f32);
	// lfs f4,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f4.f64 = double(temp.f32);
	// fneg f7,f24
	ctx.f7.u64 = f24.u64 ^ 0x8000000000000000;
	// lfs f3,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f3.f64 = double(temp.f32);
	// fneg f5,f22
	ctx.f5.u64 = f22.u64 ^ 0x8000000000000000;
	// fmr f25,f1
	f25.f64 = ctx.f1.f64;
	// fabs f1,f8
	ctx.f1.u64 = ctx.f8.u64 & ~0x8000000000000000;
	// lfs f2,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// fsel f13,f5,f31,f22
	ctx.f13.f64 = ctx.f5.f64 >= 0.0 ? f31.f64 : f22.f64;
	// fsel f0,f7,f31,f24
	f0.f64 = ctx.f7.f64 >= 0.0 ? f31.f64 : f24.f64;
	// fcmpu cr6,f28,f31
	cr6.compare(f28.f64, f31.f64);
	// fmadds f12,f1,f6,f4
	ctx.f12.f64 = double(float(ctx.f1.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fmuls f10,f13,f13
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// fmadds f9,f12,f30,f3
	ctx.f9.f64 = double(float(ctx.f12.f64 * f30.f64 + ctx.f3.f64));
	// fmuls f7,f10,f13
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fmuls f8,f11,f23
	ctx.f8.f64 = double(float(ctx.f11.f64 * f23.f64));
	// fneg f6,f9
	ctx.f6.u64 = ctx.f9.u64 ^ 0x8000000000000000;
	// fmadds f24,f7,f21,f8
	f24.f64 = double(float(ctx.f7.f64 * f21.f64 + ctx.f8.f64));
	// fsel f5,f6,f31,f9
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? f31.f64 : ctx.f9.f64;
	// fmuls f4,f5,f5
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f5.f64));
	// fmuls f3,f4,f5
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f5.f64));
	// fmadds f1,f3,f5,f26
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f5.f64 + f26.f64));
	// fnmsubs f26,f20,f2,f1
	f26.f64 = double(float(-(f20.f64 * ctx.f2.f64 - ctx.f1.f64)));
	// beq cr6,0x8254a4e8
	if (cr6.eq) goto loc_8254A4E8;
	// fcmpu cr6,f30,f29
	cr6.compare(f30.f64, f29.f64);
	// ble cr6,0x8254a4e8
	if (!cr6.gt) goto loc_8254A4E8;
	// lvx128 v61,r0,r29
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32122
	r11.s64 = -2105147392;
	// vmsum3fp128 v60,v61,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r9,r11,2528
	ctx.r9.s64 = r11.s64 + 2528;
	// lwz r11,372(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// addi r8,r10,2240
	ctx.r8.s64 = ctx.r10.s64 + 2240;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// addi r5,r7,-31648
	ctx.r5.s64 = ctx.r7.s64 + -31648;
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r6,-31664
	ctx.r4.s64 = ctx.r6.s64 + -31664;
	// lvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// vrsqrtefp128 v59,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v60.f32))));
	// vor128 v12,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vcmpeqfp128 v11,v59,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
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
	// vmulfp128 v58,v61,v6
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v58,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f0,f9
	ctx.f8.f64 = double(float(f0.f64 * ctx.f9.f64));
	// fmadds f7,f13,f11,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fmadds f6,f12,f10,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f10.f64 + ctx.f7.f64));
	// fabs f5,f6
	ctx.f5.u64 = ctx.f6.u64 & ~0x8000000000000000;
	// fsel f4,f5,f5,f31
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f5.f64 : f31.f64;
	// fsubs f3,f4,f29
	ctx.f3.f64 = double(float(ctx.f4.f64 - f29.f64));
	// fsel f1,f3,f29,f4
	ctx.f1.f64 = ctx.f3.f64 >= 0.0 ? f29.f64 : ctx.f4.f64;
	// bl 0x82227c18
	ctx.lr = 0x8254A4D0;
	sub_82227C18(ctx, base);
	// lfs f2,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fabs f0,f2
	f0.u64 = ctx.f2.u64 & ~0x8000000000000000;
	// fsubs f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 - f0.f64));
	// fsel f12,f13,f1,f0
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// fmadds f11,f12,f28,f29
	ctx.f11.f64 = double(float(ctx.f12.f64 * f28.f64 + f29.f64));
	// fmuls f27,f11,f27
	f27.f64 = double(float(ctx.f11.f64 * f27.f64));
loc_8254A4E8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,396(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lwz r11,388(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// fmuls f0,f24,f0
	f0.f64 = double(float(f24.f64 * f0.f64));
	// fcmpu cr6,f26,f0
	cr6.compare(f26.f64, f0.f64);
	// blt cr6,0x8254a524
	if (cr6.lt) goto loc_8254A524;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// fadds f13,f27,f26
	ctx.f13.f64 = double(float(f27.f64 + f26.f64));
	// lfs f0,3732(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fmadds f12,f27,f0,f24
	ctx.f12.f64 = double(float(f27.f64 * f0.f64 + f24.f64));
	// fdivs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f31,0(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// b 0x8254a568
	goto loc_8254A568;
loc_8254A524:
	// fneg f0,f25
	ctx.fpscr.disableFlushMode();
	f0.u64 = f25.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f26,f0
	cr6.compare(f26.f64, f0.f64);
	// blt cr6,0x8254a550
	if (cr6.lt) goto loc_8254A550;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// fadds f13,f25,f26
	ctx.f13.f64 = double(float(f25.f64 + f26.f64));
	// lfs f0,3732(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fmadds f12,f25,f0,f24
	ctx.f12.f64 = double(float(f25.f64 * f0.f64 + f24.f64));
	// fdivs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f31,0(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// b 0x8254a568
	goto loc_8254A568;
loc_8254A550:
	// fadds f0,f25,f26
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f25.f64 + f26.f64));
	// stfs f31,0(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfs f13,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 / ctx.f13.f64));
	// fneg f11,f12
	ctx.f11.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// stfs f11,0(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
loc_8254A568:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lwz r9,404(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 404);
	// fsel f13,f0,f0,f31
	ctx.f13.f64 = f0.f64 >= 0.0 ? f0.f64 : f31.f64;
	// fsubs f12,f13,f29
	ctx.f12.f64 = double(float(ctx.f13.f64 - f29.f64));
	// fsel f11,f12,f29,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f29.f64 : ctx.f13.f64;
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfs f10,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fsel f9,f10,f10,f31
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? ctx.f10.f64 : f31.f64;
	// fsubs f8,f9,f29
	ctx.f8.f64 = double(float(ctx.f9.f64 - f29.f64));
	// fsel f7,f8,f29,f9
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? f29.f64 : ctx.f9.f64;
	// stfs f7,0(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f31,0(r9)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba00
	ctx.lr = 0x8254A5A4;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8254A5A8"))) PPC_WEAK_FUNC(sub_8254A5A8);
PPC_FUNC_IMPL(__imp__sub_8254A5A8) {
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
	// li r3,8780
	ctx.r3.s64 = 8780;
	// bl 0x82130528
	ctx.lr = 0x8254A5BC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8254a5d8
	if (cr6.eq) goto loc_8254A5D8;
	// bl 0x82549a28
	ctx.lr = 0x8254A5C8;
	sub_82549A28(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8254A5D8:
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

__attribute__((alias("__imp__sub_8254A5EC"))) PPC_WEAK_FUNC(sub_8254A5EC);
PPC_FUNC_IMPL(__imp__sub_8254A5EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8254A5F0"))) PPC_WEAK_FUNC(sub_8254A5F0);
PPC_FUNC_IMPL(__imp__sub_8254A5F0) {
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
	ctx.lr = 0x8254A5F8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r31,r11,-32444
	r31.s64 = r11.s64 + -32444;
	// lwz r11,-32444(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -32444);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8254a898
	if (!cr6.eq) goto loc_8254A898;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8254A618;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8254a62c
	if (cr6.eq) goto loc_8254A62C;
	// bl 0x821d5408
	ctx.lr = 0x8254A628;
	sub_821D5408(ctx, base);
	// b 0x8254a630
	goto loc_8254A630;
loc_8254A62C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8254A630:
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-17208
	ctx.r7.s64 = ctx.r10.s64 + -17208;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,-26088
	ctx.r9.s64 = r11.s64 + -26088;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,108
	ctx.r5.s64 = 108;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32171
	ctx.r8.s64 = -2108358656;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32127
	ctx.r3.s64 = -2105475072;
	// addi r4,r8,-26160
	ctx.r4.s64 = ctx.r8.s64 + -26160;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,2616
	ctx.r9.s64 = ctx.r3.s64 + 2616;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r8,r10,2640
	ctx.r8.s64 = ctx.r10.s64 + 2640;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// lis r5,-32127
	ctx.r5.s64 = -2105475072;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// mr r11,r30
	r11.u64 = r30.u64;
	// addi r6,r5,2664
	ctx.r6.s64 = ctx.r5.s64 + 2664;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// lis r4,-32127
	ctx.r4.s64 = -2105475072;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r5,r4,2688
	ctx.r5.s64 = ctx.r4.s64 + 2688;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r7,2712
	ctx.r4.s64 = ctx.r7.s64 + 2712;
	// addi r6,r8,2736
	ctx.r6.s64 = ctx.r8.s64 + 2736;
	// li r11,12
	r11.s64 = 12;
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r30,-32127
	r30.s64 = -2105475072;
	// li r9,20
	ctx.r9.s64 = 20;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r5,r7,2760
	ctx.r5.s64 = ctx.r7.s64 + 2760;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r30,2784
	ctx.r4.s64 = r30.s64 + 2784;
	// addi r6,r8,2808
	ctx.r6.s64 = ctx.r8.s64 + 2808;
	// li r11,24
	r11.s64 = 24;
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// li r10,28
	ctx.r10.s64 = 28;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r30,-32127
	r30.s64 = -2105475072;
	// li r9,32
	ctx.r9.s64 = 32;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r5,r7,2832
	ctx.r5.s64 = ctx.r7.s64 + 2832;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r30,2856
	ctx.r4.s64 = r30.s64 + 2856;
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// lis r30,-32127
	r30.s64 = -2105475072;
	// addi r6,r8,2880
	ctx.r6.s64 = ctx.r8.s64 + 2880;
	// li r11,36
	r11.s64 = 36;
	// li r10,40
	ctx.r10.s64 = 40;
	// addi r8,r7,2904
	ctx.r8.s64 = ctx.r7.s64 + 2904;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// addi r7,r30,2928
	ctx.r7.s64 = r30.s64 + 2928;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// li r9,48
	ctx.r9.s64 = 48;
	// li r11,44
	r11.s64 = 44;
	// li r10,52
	ctx.r10.s64 = 52;
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
	// lis r6,-32127
	ctx.r6.s64 = -2105475072;
	// addi r9,r6,2952
	ctx.r9.s64 = ctx.r6.s64 + 2952;
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// li r11,56
	r11.s64 = 56;
	// addi r6,r10,2976
	ctx.r6.s64 = ctx.r10.s64 + 2976;
	// addi r8,r8,3000
	ctx.r8.s64 = ctx.r8.s64 + 3000;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// addi r7,r7,3024
	ctx.r7.s64 = ctx.r7.s64 + 3024;
	// li r10,60
	ctx.r10.s64 = 60;
	// li r9,64
	ctx.r9.s64 = 64;
	// li r11,68
	r11.s64 = 68;
	// stw r10,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r10.u32);
	// lis r30,-32127
	r30.s64 = -2105475072;
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// lis r29,-32127
	r29.s64 = -2105475072;
	// stw r11,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, r11.u32);
	// lis r28,-32127
	r28.s64 = -2105475072;
	// addi r6,r30,3048
	ctx.r6.s64 = r30.s64 + 3048;
	// addi r8,r29,3072
	ctx.r8.s64 = r29.s64 + 3072;
	// addi r7,r28,3096
	ctx.r7.s64 = r28.s64 + 3096;
	// li r10,72
	ctx.r10.s64 = 72;
	// li r9,76
	ctx.r9.s64 = 76;
	// li r11,80
	r11.s64 = 80;
	// stw r10,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r10.u32);
	// lis r30,-32127
	r30.s64 = -2105475072;
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// lis r29,-32127
	r29.s64 = -2105475072;
	// stw r11,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, r11.u32);
	// lis r28,-32127
	r28.s64 = -2105475072;
	// addi r6,r30,3120
	ctx.r6.s64 = r30.s64 + 3120;
	// addi r8,r29,3144
	ctx.r8.s64 = r29.s64 + 3144;
	// addi r7,r28,3168
	ctx.r7.s64 = r28.s64 + 3168;
	// li r10,84
	ctx.r10.s64 = 84;
	// li r9,88
	ctx.r9.s64 = 88;
	// li r11,92
	r11.s64 = 92;
	// stw r10,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r10.u32);
	// lis r30,-32127
	r30.s64 = -2105475072;
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// lis r29,-32127
	r29.s64 = -2105475072;
	// stw r11,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, r11.u32);
	// lis r28,-32127
	r28.s64 = -2105475072;
	// addi r6,r30,3192
	ctx.r6.s64 = r30.s64 + 3192;
	// addi r8,r29,3216
	ctx.r8.s64 = r29.s64 + 3216;
	// addi r7,r28,3240
	ctx.r7.s64 = r28.s64 + 3240;
	// li r10,96
	ctx.r10.s64 = 96;
	// li r9,100
	ctx.r9.s64 = 100;
	// li r11,104
	r11.s64 = 104;
	// stw r10,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r10.u32);
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// stw r11,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, r11.u32);
	// bl 0x821d4458
	ctx.lr = 0x8254A844;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8254A854;
	sub_821D4100(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// bl 0x821d41d0
	ctx.lr = 0x8254A870;
	sub_821D41D0(ctx, base);
	// lis r4,-32127
	ctx.r4.s64 = -2105475072;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r4,3264
	ctx.r4.s64 = ctx.r4.s64 + 3264;
	// bl 0x821d4b00
	ctx.lr = 0x8254A880;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x8254A898;
	sub_821C0548(ctx, base);
loc_8254A898:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8254A8A0"))) PPC_WEAK_FUNC(sub_8254A8A0);
PPC_FUNC_IMPL(__imp__sub_8254A8A0) {
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
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r31,r11,-32448
	r31.s64 = r11.s64 + -32448;
	// lwz r11,-32448(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -32448);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8254ab08
	if (!cr6.eq) goto loc_8254AB08;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8254A8D0;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8254a8e4
	if (cr6.eq) goto loc_8254A8E4;
	// bl 0x821d5408
	ctx.lr = 0x8254A8E0;
	sub_821D5408(ctx, base);
	// b 0x8254a8e8
	goto loc_8254A8E8;
loc_8254A8E4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8254A8E8:
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32171
	r11.s64 = -2108358656;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-17188
	ctx.r7.s64 = ctx.r10.s64 + -17188;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,-26176
	ctx.r9.s64 = r11.s64 + -26176;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,8780
	ctx.r5.s64 = 8780;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32171
	ctx.r8.s64 = -2108358656;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32127
	ctx.r3.s64 = -2105475072;
	// addi r4,r8,-23128
	ctx.r4.s64 = ctx.r8.s64 + -23128;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r5,-32127
	ctx.r5.s64 = -2105475072;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r8,r10,2244
	ctx.r8.s64 = ctx.r10.s64 + 2244;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r9,r3,2220
	ctx.r9.s64 = ctx.r3.s64 + 2220;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r4,-32127
	ctx.r4.s64 = -2105475072;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// addi r6,r5,2268
	ctx.r6.s64 = ctx.r5.s64 + 2268;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r4,2292
	ctx.r5.s64 = ctx.r4.s64 + 2292;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r4,r7,2316
	ctx.r4.s64 = ctx.r7.s64 + 2316;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// li r9,8
	ctx.r9.s64 = 8;
	// li r11,12
	r11.s64 = 12;
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// lis r30,-32127
	r30.s64 = -2105475072;
	// addi r6,r8,2340
	ctx.r6.s64 = ctx.r8.s64 + 2340;
	// addi r5,r7,2364
	ctx.r5.s64 = ctx.r7.s64 + 2364;
	// addi r4,r30,2388
	ctx.r4.s64 = r30.s64 + 2388;
	// li r9,20
	ctx.r9.s64 = 20;
	// li r11,24
	r11.s64 = 24;
	// li r10,28
	ctx.r10.s64 = 28;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// lis r30,-32127
	r30.s64 = -2105475072;
	// addi r6,r8,3376
	ctx.r6.s64 = ctx.r8.s64 + 3376;
	// addi r5,r7,3472
	ctx.r5.s64 = ctx.r7.s64 + 3472;
	// addi r4,r30,3568
	ctx.r4.s64 = r30.s64 + 3568;
	// li r9,48
	ctx.r9.s64 = 48;
	// li r11,588
	r11.s64 = 588;
	// li r10,4172
	ctx.r10.s64 = 4172;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// lis r30,-32127
	r30.s64 = -2105475072;
	// addi r5,r7,3664
	ctx.r5.s64 = ctx.r7.s64 + 3664;
	// addi r6,r8,3616
	ctx.r6.s64 = ctx.r8.s64 + 3616;
	// addi r4,r30,3712
	ctx.r4.s64 = r30.s64 + 3712;
	// li r9,7756
	ctx.r9.s64 = 7756;
	// li r11,8012
	r11.s64 = 8012;
	// li r10,8268
	ctx.r10.s64 = 8268;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// bl 0x821d4458
	ctx.lr = 0x8254AA2C;
	sub_821D4458(ctx, base);
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r3,16
	ctx.r3.s64 = 16;
	// addi r11,r30,52
	r11.s64 = r30.s64 + 52;
	// bl 0x82130528
	ctx.lr = 0x8254AA3C;
	sub_82130528(ctx, base);
	// li r11,2
	r11.s64 = 2;
	// stw r3,52(r30)
	PPC_STORE_U32(r30.u32 + 52, ctx.r3.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// sth r11,58(r30)
	PPC_STORE_U16(r30.u32 + 58, r11.u16);
	// lis r9,-32171
	ctx.r9.s64 = -2108358656;
	// stb r10,60(r30)
	PPC_STORE_U8(r30.u32 + 60, ctx.r10.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r8,r9,-26472
	ctx.r8.s64 = ctx.r9.s64 + -26472;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// bl 0x82130000
	ctx.lr = 0x8254AA64;
	sub_82130000(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r4,r7,3520
	ctx.r4.s64 = ctx.r7.s64 + 3520;
	// bl 0x82197d98
	ctx.lr = 0x8254AA80;
	sub_82197D98(ctx, base);
	// lis r6,-32171
	ctx.r6.s64 = -2108358656;
	// addi r5,r6,-26520
	ctx.r5.s64 = ctx.r6.s64 + -26520;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r5,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r5.u32);
	// bl 0x82130000
	ctx.lr = 0x8254AA94;
	sub_82130000(ctx, base);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// addi r4,r4,3512
	ctx.r4.s64 = ctx.r4.s64 + 3512;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x82197d98
	ctx.lr = 0x8254AAAC;
	sub_82197D98(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82196758
	ctx.lr = 0x8254AAB4;
	sub_82196758(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8254AAC4;
	sub_821D4100(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821d41d0
	ctx.lr = 0x8254AAE0;
	sub_821D41D0(ctx, base);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,2556
	ctx.r4.s64 = ctx.r8.s64 + 2556;
	// bl 0x821d4b00
	ctx.lr = 0x8254AAF0;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x8254AB08;
	sub_821C0548(ctx, base);
loc_8254AB08:
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

__attribute__((alias("__imp__sub_8254AB20"))) PPC_WEAK_FUNC(sub_8254AB20);
PPC_FUNC_IMPL(__imp__sub_8254AB20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// addi r9,r10,-17020
	ctx.r9.s64 = ctx.r10.s64 + -17020;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8254ab4c
	if (cr6.eq) goto loc_8254AB4C;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// stw r9,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
loc_8254AB4C:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,-30128
	ctx.r10.s64 = r11.s64 + -30128;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8254AB60"))) PPC_WEAK_FUNC(sub_8254AB60);
PPC_FUNC_IMPL(__imp__sub_8254AB60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8254ab78
	if (cr6.eq) goto loc_8254AB78;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_8254AB78:
	// stw r4,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r4.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8254AB94"))) PPC_WEAK_FUNC(sub_8254AB94);
PPC_FUNC_IMPL(__imp__sub_8254AB94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8254AB98"))) PPC_WEAK_FUNC(sub_8254AB98);
PPC_FUNC_IMPL(__imp__sub_8254AB98) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// li r30,0
	r30.s64 = 0;
	// addi r9,r10,-17020
	ctx.r9.s64 = ctx.r10.s64 + -17020;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// bl 0x82550d08
	ctx.lr = 0x8254ABD8;
	sub_82550D08(ctx, base);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
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

__attribute__((alias("__imp__sub_8254ABF8"))) PPC_WEAK_FUNC(sub_8254ABF8);
PPC_FUNC_IMPL(__imp__sub_8254ABF8) {
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
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// addi r9,r10,-17020
	ctx.r9.s64 = ctx.r10.s64 + -17020;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8254ac38
	if (cr6.eq) goto loc_8254AC38;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// stw r9,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r9.u32);
loc_8254AC38:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-30128
	ctx.r9.s64 = r11.s64 + -30128;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8254ac60
	if (cr6.eq) goto loc_8254AC60;
	// bl 0x82130588
	ctx.lr = 0x8254AC5C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8254AC60:
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

__attribute__((alias("__imp__sub_8254AC74"))) PPC_WEAK_FUNC(sub_8254AC74);
PPC_FUNC_IMPL(__imp__sub_8254AC74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8254AC78"))) PPC_WEAK_FUNC(sub_8254AC78);
PPC_FUNC_IMPL(__imp__sub_8254AC78) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-17020
	ctx.r9.s64 = r11.s64 + -17020;
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// bl 0x82550d08
	ctx.lr = 0x8254ACB0;
	sub_82550D08(ctx, base);
	// lfs f0,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f13,20(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,20(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// lfs f12,24(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,24(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// lfs f11,28(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,28(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// beq cr6,0x8254acf0
	if (cr6.eq) goto loc_8254ACF0;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_8254ACF0:
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

__attribute__((alias("__imp__sub_8254AD08"))) PPC_WEAK_FUNC(sub_8254AD08);
PPC_FUNC_IMPL(__imp__sub_8254AD08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// cmplw cr6,r4,r3
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r3.u32, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lfs f0,8(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// lfs f13,20(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,20(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// lfs f12,24(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,24(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// lfs f11,28(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,28(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r10,32(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8254ad4c
	if (cr6.eq) goto loc_8254AD4C;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
loc_8254AD4C:
	// stw r10,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r10.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8254AD68"))) PPC_WEAK_FUNC(sub_8254AD68);
PPC_FUNC_IMPL(__imp__sub_8254AD68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stfd f29,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f29.u64);
	// stfd f30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, f30.u64);
	// stfd f31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lfs f0,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f11,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// lfs f31,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f31.f64 = double(temp.f32);
	// lfs f30,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fmadds f8,f10,f11,f12
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + ctx.f12.f64));
	// fmsubs f29,f11,f0,f9
	f29.f64 = double(float(ctx.f11.f64 * f0.f64 - ctx.f9.f64));
	// fsubs f7,f8,f31
	ctx.f7.f64 = double(float(ctx.f8.f64 - f31.f64));
	// fsel f6,f7,f8,f31
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f8.f64 : f31.f64;
	// fsubs f5,f6,f30
	ctx.f5.f64 = double(float(ctx.f6.f64 - f30.f64));
	// fsel f1,f5,f30,f6
	ctx.f1.f64 = ctx.f5.f64 >= 0.0 ? f30.f64 : ctx.f6.f64;
	// bl 0x823dcb30
	ctx.lr = 0x8254ADC4;
	sub_823DCB30(ctx, base);
	// frsp f4,f1
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = double(float(ctx.f1.f64));
	// fsel f3,f29,f30,f31
	ctx.f3.f64 = f29.f64 >= 0.0 ? f30.f64 : f31.f64;
	// fmuls f1,f4,f3
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f3.f64));
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f29,-32(r1)
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f30,-24(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// lfd f31,-16(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8254ADEC"))) PPC_WEAK_FUNC(sub_8254ADEC);
PPC_FUNC_IMPL(__imp__sub_8254ADEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8254ADF0"))) PPC_WEAK_FUNC(sub_8254ADF0);
PPC_FUNC_IMPL(__imp__sub_8254ADF0) {
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
	PPCRegister f30{};
	PPCRegister f31{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8254ADF8;
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// vor128 v126,v2,v2
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// addi r11,r30,16
	r11.s64 = r30.s64 + 16;
	// li r27,0
	r27.s64 = 0;
	// lwz r10,22544(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 22544);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,22544(r30)
	PPC_STORE_U32(r30.u32 + 22544, ctx.r10.u32);
	// cmpwi cr6,r10,128
	cr6.compare<int32_t>(ctx.r10.s32, 128, xer);
	// bne cr6,0x8254ae4c
	if (!cr6.eq) goto loc_8254AE4C;
	// stw r27,22528(r11)
	PPC_STORE_U32(r11.u32 + 22528, r27.u32);
loc_8254AE4C:
	// lwz r10,22528(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 22528);
	// li r8,64
	ctx.r8.s64 = 64;
	// lwz r9,22536(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 22536);
	// li r5,96
	ctx.r5.s64 = 96;
	// mulli r10,r10,176
	ctx.r10.s64 = ctx.r10.s64 * 176;
	// add r31,r10,r11
	r31.u64 = ctx.r10.u64 + r11.u64;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// addi r29,r31,16
	r29.s64 = r31.s64 + 16;
	// stw r7,22536(r11)
	PPC_STORE_U32(r11.u32 + 22536, ctx.r7.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// stvx128 v127,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v3,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8244d150
	ctx.lr = 0x8254AE88;
	sub_8244D150(ctx, base);
	// lwz r10,22704(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 22704);
	// addi r11,r30,22576
	r11.s64 = r30.s64 + 22576;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,22704(r30)
	PPC_STORE_U32(r30.u32 + 22704, ctx.r10.u32);
	// cmpwi cr6,r10,128
	cr6.compare<int32_t>(ctx.r10.s32, 128, xer);
	// bne cr6,0x8254aea4
	if (!cr6.eq) goto loc_8254AEA4;
	// stw r27,128(r11)
	PPC_STORE_U32(r11.u32 + 128, r27.u32);
loc_8254AEA4:
	// vsubfp128 v63,v126,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v127.f32)));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r9,136(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// rlwinm r6,r28,7,24,24
	ctx.r6.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 7) & 0x80;
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// clrlwi r9,r28,24
	ctx.r9.u64 = r28.u32 & 0xFF;
	// stw r5,136(r11)
	PPC_STORE_U32(r11.u32 + 136, ctx.r5.u32);
	// lfs f11,31308(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31308);
	ctx.f11.f64 = double(temp.f32);
	// stbx r6,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r6.u8);
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// fmadds f10,f0,f0,f12
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fsqrts f12,f9
	ctx.f12.f64 = double(float(sqrt(ctx.f9.f64)));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// ble cr6,0x8254afec
	if (!cr6.gt) goto loc_8254AFEC;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// fadds f0,f12,f31
	f0.f64 = double(float(ctx.f12.f64 + f31.f64));
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lfs f10,25168(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 25168);
	ctx.f10.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f9,25396(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 25396);
	ctx.f9.f64 = double(temp.f32);
	// addi r5,r7,-31664
	ctx.r5.s64 = ctx.r7.s64 + -31664;
	// vor128 v62,v127,v127
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// vor128 v61,v126,v126
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// lvlx128 v60,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lfs f13,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// li r3,32
	ctx.r3.s64 = 32;
	// lvx128 v13,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f8,f10,f13,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f9.f64));
	// lfs f11,14992(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14992);
	ctx.f11.f64 = double(temp.f32);
	// li r11,48
	r11.s64 = 48;
	// vrefp128 v0,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v59.f32)));
	// fadds f7,f0,f30
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f7.f64 = double(float(f0.f64 + f30.f64));
	// vor128 v12,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// fmsubs f6,f7,f13,f11
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 - ctx.f11.f64));
	// vnmsubfp v10,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// fsubs f5,f8,f6
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f5.f64 = double(float(ctx.f8.f64 - ctx.f6.f64));
	// vmaddfp v9,v0,v10,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// fsel f0,f5,f6,f8
	ctx.fpscr.disableFlushModeUnconditional();
	f0.f64 = ctx.f5.f64 >= 0.0 ? ctx.f6.f64 : ctx.f8.f64;
	// vmulfp128 v0,v63,v9
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v9.f32)));
	// fsubs f4,f31,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f4.f64 = double(float(f31.f64 - f0.f64));
	// stfs f4,84(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvlx128 v58,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fsubs f3,f30,f0
	ctx.f3.f64 = double(float(f30.f64 - f0.f64));
	// stfs f3,84(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// vspltw128 v55,v58,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// lvlx128 v57,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v56,v57,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// vor128 v54,v0,v0
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vmaddfp128 v61,v0,v56,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v56.f32)), simde_mm_load_ps(v61.f32)));
	// vnmsubfp128 v62,v54,v55,v62
	simde_mm_store_ps(v62.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v55.f32)), simde_mm_load_ps(v62.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v61,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8254affc
	if (cr6.eq) goto loc_8254AFFC;
	// fmsubs f13,f12,f13,f11
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 - ctx.f11.f64));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// vor128 v53,v0,v0
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fsel f11,f12,f13,f0
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v51,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v52,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v49,v52,0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0xFF));
	// vspltw128 v50,v51,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// vmaddfp128 v127,v0,v49,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v49.f32)), simde_mm_load_ps(v127.f32)));
	// vnmsubfp128 v126,v53,v50,v126
	simde_mm_store_ps(v126.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v50.f32)), simde_mm_load_ps(v126.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v127,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8254affc
	goto loc_8254AFFC;
loc_8254AFEC:
	// li r11,32
	r11.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// stvx128 v127,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8254AFFC:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8254B01C"))) PPC_WEAK_FUNC(sub_8254B01C);
PPC_FUNC_IMPL(__imp__sub_8254B01C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8254B020"))) PPC_WEAK_FUNC(sub_8254B020);
PPC_FUNC_IMPL(__imp__sub_8254B020) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,25104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 25104, r11.u32);
	// stw r11,25152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 25152, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8254B030"))) PPC_WEAK_FUNC(sub_8254B030);
PPC_FUNC_IMPL(__imp__sub_8254B030) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	ctx.lr = 0x8254B038;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// addi r11,r31,23056
	r11.s64 = r31.s64 + 23056;
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// li r8,16
	ctx.r8.s64 = 16;
	// lwz r10,25104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 25104);
	// addi r28,r1,96
	r28.s64 = ctx.r1.s64 + 96;
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// rlwinm r9,r10,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r3,25104(r31)
	PPC_STORE_U32(r31.u32 + 25104, ctx.r3.u32);
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// addi r3,r11,32
	ctx.r3.s64 = r11.s64 + 32;
	// lfs f0,14884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// li r10,48
	ctx.r10.s64 = 48;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f0,3796(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f13,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvlx128 v62,r0,r27
	temp.u32 = r27.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r6
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v57,v58,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v57,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,36(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 36, temp.u32);
	// lfs f1,31292(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 31292);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82165300
	ctx.lr = 0x8254B0DC;
	sub_82165300(ctx, base);
	// lwz r10,25152(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 25152);
	// addi r11,r31,25120
	r11.s64 = r31.s64 + 25120;
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// clrlwi r9,r29,24
	ctx.r9.u64 = r29.u32 & 0xFF;
	// stw r3,25152(r31)
	PPC_STORE_U32(r31.u32 + 25152, ctx.r3.u32);
	// lbzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// rlwimi r8,r30,7,17,24
	ctx.r8.u64 = (__builtin_rotateleft32(r30.u32, 7) & 0x7F80) | (ctx.r8.u64 & 0xFFFFFFFFFFFF807F);
	// clrlwi r7,r8,17
	ctx.r7.u64 = ctx.r8.u32 & 0x7FFF;
	// rlwinm r7,r7,0,26,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// rlwimi r7,r9,6,25,25
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r9.u32, 6) & 0x40) | (ctx.r7.u64 & 0xFFFFFFFFFFFFFFBF);
	// stbx r7,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r7.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8254B110"))) PPC_WEAK_FUNC(sub_8254B110);
PPC_FUNC_IMPL(__imp__sub_8254B110) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// addi r12,r1,-8
	r12.s64 = ctx.r1.s64 + -8;
	// bl 0x823db9a0
	ctx.lr = 0x8254B120;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,25280(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 25280);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r11,30468(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 30468);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwz r8,30464(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 30464);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// addi r7,r3,25440
	ctx.r7.s64 = ctx.r3.s64 + 25440;
	// lfs f12,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	ctx.f12.f64 = double(temp.f32);
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// fsubs f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lfs f0,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f11,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// fmr f7,f0
	ctx.f7.f64 = f0.f64;
	// fmr f5,f0
	ctx.f5.f64 = f0.f64;
	// fsel f10,f10,f12,f13
	ctx.f10.f64 = ctx.f10.f64 >= 0.0 ? ctx.f12.f64 : ctx.f13.f64;
	// fmr f13,f10
	ctx.f13.f64 = ctx.f10.f64;
	// bge cr6,0x8254b3e4
	if (!cr6.lt) goto loc_8254B3E4;
	// mulli r10,r9,56
	ctx.r10.s64 = ctx.r9.s64 * 56;
	// lfs f9,25300(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 25300);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,25328(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 25328);
	ctx.f8.f64 = double(temp.f32);
	// fdivs f6,f11,f9
	ctx.f6.f64 = double(float(ctx.f11.f64 / ctx.f9.f64));
	// lfs f1,25296(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 25296);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stfs f8,-172(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -172, temp.u32);
	// stfs f6,-176(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + -176, temp.u32);
	// stfs f1,-168(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + -168, temp.u32);
	// subf r9,r9,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r9.s64;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lfs f8,3732(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3732);
	ctx.f8.f64 = double(temp.f32);
	// lfs f3,8876(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8876);
	ctx.f3.f64 = double(temp.f32);
	// addi r10,r10,1348
	ctx.r10.s64 = ctx.r10.s64 + 1348;
	// lfs f4,8880(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8880);
	ctx.f4.f64 = double(temp.f32);
	// lfs f9,-31404(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -31404);
	ctx.f9.f64 = double(temp.f32);
	// b 0x8254b1c0
	goto loc_8254B1C0;
loc_8254B1BC:
	// lfs f6,-176(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -176);
	ctx.f6.f64 = double(temp.f32);
loc_8254B1C0:
	// lfs f2,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f2.f64 = double(temp.f32);
	// fnmsubs f31,f6,f5,f11
	f31.f64 = double(float(-(ctx.f6.f64 * ctx.f5.f64 - ctx.f11.f64)));
	// fmuls f30,f2,f13
	f30.f64 = double(float(ctx.f2.f64 * ctx.f13.f64));
	// lfs f2,-4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f29,-172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -172);
	f29.f64 = double(temp.f32);
	// fnmsubs f22,f6,f7,f11
	f22.f64 = double(float(-(ctx.f6.f64 * ctx.f7.f64 - ctx.f11.f64)));
	// fmuls f29,f2,f29
	f29.f64 = double(float(ctx.f2.f64 * f29.f64));
	// lfs f2,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fabs f27,f2
	f27.u64 = ctx.f2.u64 & ~0x8000000000000000;
	// lfs f26,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	f26.f64 = double(temp.f32);
	// lfs f25,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	f25.f64 = double(temp.f32);
	// fmr f15,f26
	f15.f64 = f26.f64;
	// lfs f23,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	f23.f64 = double(temp.f32);
	// fmuls f24,f2,f13
	f24.f64 = double(float(ctx.f2.f64 * ctx.f13.f64));
	// lfs f6,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f28,f13,f13
	f28.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f21,12(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	f21.f64 = double(temp.f32);
	// lfs f20,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	f20.f64 = double(temp.f32);
	// fneg f19,f31
	f19.u64 = f31.u64 ^ 0x8000000000000000;
	// lfs f18,16(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	f18.f64 = double(temp.f32);
	// fneg f17,f30
	f17.u64 = f30.u64 ^ 0x8000000000000000;
	// lfs f2,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f2,f2,f10
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f10.f64));
	// lfs f16,-16(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -16);
	f16.f64 = double(temp.f32);
	// fmuls f29,f29,f13
	f29.f64 = double(float(f29.f64 * ctx.f13.f64));
	// fmadds f26,f26,f27,f25
	f26.f64 = double(float(f26.f64 * f27.f64 + f25.f64));
	// fmadds f6,f24,f13,f6
	ctx.f6.f64 = double(float(f24.f64 * ctx.f13.f64 + ctx.f6.f64));
	// fmuls f24,f18,f8
	f24.f64 = double(float(f18.f64 * ctx.f8.f64));
	// fsel f31,f19,f0,f31
	f31.f64 = f19.f64 >= 0.0 ? f0.f64 : f31.f64;
	// fsel f30,f17,f0,f30
	f30.f64 = f17.f64 >= 0.0 ? f0.f64 : f30.f64;
	// fnmsubs f29,f29,f13,f11
	f29.f64 = double(float(-(f29.f64 * ctx.f13.f64 - ctx.f11.f64)));
	// fmadds f26,f26,f13,f23
	f26.f64 = double(float(f26.f64 * ctx.f13.f64 + f23.f64));
	// fmuls f6,f6,f6
	ctx.f6.f64 = double(float(ctx.f6.f64 * ctx.f6.f64));
	// fmuls f1,f1,f31
	ctx.f1.f64 = double(float(ctx.f1.f64 * f31.f64));
	// fsel f23,f30,f30,f0
	f23.f64 = f30.f64 >= 0.0 ? f30.f64 : f0.f64;
	// fsel f29,f29,f29,f0
	f29.f64 = f29.f64 >= 0.0 ? f29.f64 : f0.f64;
	// fneg f19,f26
	f19.u64 = f26.u64 ^ 0x8000000000000000;
	// fsubs f17,f23,f9
	f17.f64 = double(float(f23.f64 - ctx.f9.f64));
	// fsubs f14,f29,f11
	f14.f64 = double(float(f29.f64 - ctx.f11.f64));
	// fsel f26,f19,f0,f26
	f26.f64 = f19.f64 >= 0.0 ? f0.f64 : f26.f64;
	// fsel f23,f17,f9,f23
	f23.f64 = f17.f64 >= 0.0 ? ctx.f9.f64 : f23.f64;
	// fsel f29,f14,f11,f29
	f29.f64 = f14.f64 >= 0.0 ? ctx.f11.f64 : f29.f64;
	// fmuls f19,f26,f26
	f19.f64 = double(float(f26.f64 * f26.f64));
	// fsel f17,f23,f4,f3
	f17.f64 = f23.f64 >= 0.0 ? ctx.f4.f64 : ctx.f3.f64;
	// fmuls f29,f29,f21
	f29.f64 = double(float(f29.f64 * f21.f64));
	// fmuls f21,f19,f26
	f21.f64 = double(float(f19.f64 * f26.f64));
	// fsubs f19,f23,f17
	f19.f64 = double(float(f23.f64 - f17.f64));
	// fmsubs f6,f29,f29,f6
	ctx.f6.f64 = double(float(f29.f64 * f29.f64 - ctx.f6.f64));
	// fadds f29,f19,f17
	f29.f64 = double(float(f19.f64 + f17.f64));
	// fneg f19,f6
	f19.u64 = ctx.f6.u64 ^ 0x8000000000000000;
	// fsubs f23,f23,f29
	f23.f64 = double(float(f23.f64 - f29.f64));
	// fsubs f17,f29,f11
	f17.f64 = double(float(f29.f64 - ctx.f11.f64));
	// fsel f6,f19,f0,f6
	ctx.f6.f64 = f19.f64 >= 0.0 ? f0.f64 : ctx.f6.f64;
	// fsel f29,f23,f29,f17
	f29.f64 = f23.f64 >= 0.0 ? f29.f64 : f17.f64;
	// fsqrts f6,f6
	ctx.f6.f64 = double(float(sqrt(ctx.f6.f64)));
	// fctiwz f23,f29
	f23.s64 = (f29.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f29.f64));
	// stfd f23,-160(r1)
	PPC_STORE_U64(ctx.r1.u32 + -160, f23.u64);
	// lwz r8,-156(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -156);
	// addi r6,r8,19
	ctx.r6.s64 = ctx.r8.s64 + 19;
	// addi r5,r8,20
	ctx.r5.s64 = ctx.r8.s64 + 20;
	// fsubs f30,f30,f29
	f30.f64 = double(float(f30.f64 - f29.f64));
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r5,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f29,r4,r11
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	f29.f64 = double(temp.f32);
	// lfsx f23,r3,r11
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + r11.u32);
	f23.f64 = double(temp.f32);
	// fsubs f23,f23,f29
	f23.f64 = double(float(f23.f64 - f29.f64));
	// fmadds f30,f23,f30,f29
	f30.f64 = double(float(f23.f64 * f30.f64 + f29.f64));
	// fsubs f29,f12,f30
	f29.f64 = double(float(ctx.f12.f64 - f30.f64));
	// fsel f30,f29,f12,f30
	f30.f64 = f29.f64 >= 0.0 ? ctx.f12.f64 : f30.f64;
	// fnmsubs f30,f21,f26,f30
	f30.f64 = double(float(-(f21.f64 * f26.f64 - f30.f64)));
	// fmadds f1,f1,f31,f30
	ctx.f1.f64 = double(float(ctx.f1.f64 * f31.f64 + f30.f64));
	// fneg f30,f2
	f30.u64 = ctx.f2.u64 ^ 0x8000000000000000;
	// fadds f1,f1,f20
	ctx.f1.f64 = double(float(ctx.f1.f64 + f20.f64));
	// fsubs f31,f1,f6
	f31.f64 = double(float(ctx.f1.f64 - ctx.f6.f64));
	// fsel f6,f31,f6,f1
	ctx.f6.f64 = f31.f64 >= 0.0 ? ctx.f6.f64 : ctx.f1.f64;
	// fmuls f1,f6,f18
	ctx.f1.f64 = double(float(ctx.f6.f64 * f18.f64));
	// fmadds f6,f1,f8,f28
	ctx.f6.f64 = double(float(ctx.f1.f64 * ctx.f8.f64 + f28.f64));
	// fsubs f1,f12,f6
	ctx.f1.f64 = double(float(ctx.f12.f64 - ctx.f6.f64));
	// fsel f6,f1,f12,f6
	ctx.f6.f64 = ctx.f1.f64 >= 0.0 ? ctx.f12.f64 : ctx.f6.f64;
	// fsqrts f6,f6
	ctx.f6.f64 = double(float(sqrt(ctx.f6.f64)));
	// fsubs f31,f6,f16
	f31.f64 = double(float(ctx.f6.f64 - f16.f64));
	// fmadds f28,f15,f27,f25
	f28.f64 = double(float(f15.f64 * f27.f64 + f25.f64));
	// lfs f29,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	f29.f64 = double(temp.f32);
	// fsel f6,f31,f16,f6
	ctx.f6.f64 = f31.f64 >= 0.0 ? f16.f64 : ctx.f6.f64;
	// lfs f1,-168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -168);
	ctx.f1.f64 = double(temp.f32);
	// fsel f2,f30,f0,f2
	ctx.f2.f64 = f30.f64 >= 0.0 ? f0.f64 : ctx.f2.f64;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// fneg f27,f22
	f27.u64 = f22.u64 ^ 0x8000000000000000;
	// addi r10,r10,56
	ctx.r10.s64 = ctx.r10.s64 + 56;
	// fmuls f26,f10,f10
	f26.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f31,f28,f10,f29
	f31.f64 = double(float(f28.f64 * ctx.f10.f64 + f29.f64));
	// fadds f29,f6,f13
	f29.f64 = double(float(ctx.f6.f64 + ctx.f13.f64));
	// fmr f13,f6
	ctx.f13.f64 = ctx.f6.f64;
	// fsel f6,f2,f2,f0
	ctx.f6.f64 = ctx.f2.f64 >= 0.0 ? ctx.f2.f64 : f0.f64;
	// fsel f30,f27,f0,f22
	f30.f64 = f27.f64 >= 0.0 ? f0.f64 : f22.f64;
	// fneg f28,f31
	f28.u64 = f31.u64 ^ 0x8000000000000000;
	// fdivs f29,f24,f29
	f29.f64 = double(float(f24.f64 / f29.f64));
	// fsubs f25,f6,f9
	f25.f64 = double(float(ctx.f6.f64 - ctx.f9.f64));
	// fmuls f27,f1,f30
	f27.f64 = double(float(ctx.f1.f64 * f30.f64));
	// fsel f31,f28,f0,f31
	f31.f64 = f28.f64 >= 0.0 ? f0.f64 : f31.f64;
	// fadds f5,f29,f5
	ctx.f5.f64 = double(float(f29.f64 + ctx.f5.f64));
	// fsel f6,f25,f9,f6
	ctx.f6.f64 = f25.f64 >= 0.0 ? ctx.f9.f64 : ctx.f6.f64;
	// fmuls f29,f31,f31
	f29.f64 = double(float(f31.f64 * f31.f64));
	// fsel f28,f6,f4,f3
	f28.f64 = ctx.f6.f64 >= 0.0 ? ctx.f4.f64 : ctx.f3.f64;
	// fmuls f29,f29,f31
	f29.f64 = double(float(f29.f64 * f31.f64));
	// fsubs f25,f6,f28
	f25.f64 = double(float(ctx.f6.f64 - f28.f64));
	// fadds f28,f25,f28
	f28.f64 = double(float(f25.f64 + f28.f64));
	// fsubs f6,f6,f28
	ctx.f6.f64 = double(float(ctx.f6.f64 - f28.f64));
	// fsubs f25,f28,f11
	f25.f64 = double(float(f28.f64 - ctx.f11.f64));
	// fsel f6,f6,f28,f25
	ctx.f6.f64 = ctx.f6.f64 >= 0.0 ? f28.f64 : f25.f64;
	// fctiwz f28,f6
	f28.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f28,-160(r1)
	PPC_STORE_U64(ctx.r1.u32 + -160, f28.u64);
	// lwz r8,-156(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -156);
	// addi r6,r8,19
	ctx.r6.s64 = ctx.r8.s64 + 19;
	// addi r5,r8,20
	ctx.r5.s64 = ctx.r8.s64 + 20;
	// fsubs f2,f2,f6
	ctx.f2.f64 = double(float(ctx.f2.f64 - ctx.f6.f64));
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r5,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f6,r4,r11
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	ctx.f6.f64 = double(temp.f32);
	// lfsx f28,r3,r11
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + r11.u32);
	f28.f64 = double(temp.f32);
	// fsubs f28,f28,f6
	f28.f64 = double(float(f28.f64 - ctx.f6.f64));
	// fmadds f2,f28,f2,f6
	ctx.f2.f64 = double(float(f28.f64 * ctx.f2.f64 + ctx.f6.f64));
	// fsubs f6,f12,f2
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f2.f64));
	// fsel f2,f6,f12,f2
	ctx.f2.f64 = ctx.f6.f64 >= 0.0 ? ctx.f12.f64 : ctx.f2.f64;
	// fmadds f6,f27,f30,f2
	ctx.f6.f64 = double(float(f27.f64 * f30.f64 + ctx.f2.f64));
	// fnmsubs f2,f29,f31,f6
	ctx.f2.f64 = double(float(-(f29.f64 * f31.f64 - ctx.f6.f64)));
	// fadds f6,f2,f20
	ctx.f6.f64 = double(float(ctx.f2.f64 + f20.f64));
	// fmuls f2,f6,f18
	ctx.f2.f64 = double(float(ctx.f6.f64 * f18.f64));
	// fmadds f6,f2,f8,f26
	ctx.f6.f64 = double(float(ctx.f2.f64 * ctx.f8.f64 + f26.f64));
	// fsubs f2,f12,f6
	ctx.f2.f64 = double(float(ctx.f12.f64 - ctx.f6.f64));
	// fsel f6,f2,f12,f6
	ctx.f6.f64 = ctx.f2.f64 >= 0.0 ? ctx.f12.f64 : ctx.f6.f64;
	// fsqrts f6,f6
	ctx.f6.f64 = double(float(sqrt(ctx.f6.f64)));
	// fadds f2,f6,f10
	ctx.f2.f64 = double(float(ctx.f6.f64 + ctx.f10.f64));
	// fmr f10,f6
	ctx.f10.f64 = ctx.f6.f64;
	// fdivs f6,f24,f2
	ctx.f6.f64 = double(float(f24.f64 / ctx.f2.f64));
	// fadds f7,f6,f7
	ctx.f7.f64 = double(float(ctx.f6.f64 + ctx.f7.f64));
	// bne 0x8254b1bc
	if (!cr0.eq) goto loc_8254B1BC;
loc_8254B3E4:
	// lfs f13,5036(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 5036);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsubs f12,f13,f7
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f7.f64));
	// lfs f13,14196(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14196);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x8254b410
	if (!cr6.gt) goto loc_8254B410;
	// lfs f13,5036(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 5036);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f5
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f5.f64));
	// fsubs f10,f13,f7
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f7.f64));
	// fdivs f13,f12,f10
	ctx.f13.f64 = double(float(ctx.f12.f64 / ctx.f10.f64));
	// b 0x8254b414
	goto loc_8254B414;
loc_8254B410:
	// fmr f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f0.f64;
loc_8254B414:
	// fsel f0,f13,f13,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// fsubs f13,f0,f11
	ctx.f13.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fsel f1,f13,f11,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? ctx.f11.f64 : f0.f64;
	// addi r12,r1,-8
	r12.s64 = ctx.r1.s64 + -8;
	// bl 0x823db9ec
	ctx.lr = 0x8254B428;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8254B434"))) PPC_WEAK_FUNC(sub_8254B434);
PPC_FUNC_IMPL(__imp__sub_8254B434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8254B438"))) PPC_WEAK_FUNC(sub_8254B438);
PPC_FUNC_IMPL(__imp__sub_8254B438) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// addi r12,r1,-8
	r12.s64 = ctx.r1.s64 + -8;
	// bl 0x823db9a0
	ctx.lr = 0x8254B448;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,25280(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 25280);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r11,30468(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 30468);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwz r8,30464(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 30464);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// addi r7,r3,25440
	ctx.r7.s64 = ctx.r3.s64 + 25440;
	// lfs f12,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	ctx.f12.f64 = double(temp.f32);
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// fsubs f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lfs f0,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f11,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// fmr f7,f0
	ctx.f7.f64 = f0.f64;
	// fmr f5,f0
	ctx.f5.f64 = f0.f64;
	// fsel f10,f10,f12,f13
	ctx.f10.f64 = ctx.f10.f64 >= 0.0 ? ctx.f12.f64 : ctx.f13.f64;
	// fmr f13,f10
	ctx.f13.f64 = ctx.f10.f64;
	// bge cr6,0x8254b714
	if (!cr6.lt) goto loc_8254B714;
	// mulli r10,r9,56
	ctx.r10.s64 = ctx.r9.s64 * 56;
	// lfs f9,25316(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 25316);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,25328(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 25328);
	ctx.f8.f64 = double(temp.f32);
	// fdivs f6,f11,f9
	ctx.f6.f64 = double(float(ctx.f11.f64 / ctx.f9.f64));
	// lfs f1,25312(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 25312);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stfs f8,-172(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -172, temp.u32);
	// stfs f6,-176(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + -176, temp.u32);
	// stfs f1,-168(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + -168, temp.u32);
	// subf r9,r9,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r9.s64;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lfs f8,3732(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3732);
	ctx.f8.f64 = double(temp.f32);
	// lfs f3,8876(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8876);
	ctx.f3.f64 = double(temp.f32);
	// addi r10,r10,1348
	ctx.r10.s64 = ctx.r10.s64 + 1348;
	// lfs f4,8880(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8880);
	ctx.f4.f64 = double(temp.f32);
	// lfs f9,-31404(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -31404);
	ctx.f9.f64 = double(temp.f32);
	// b 0x8254b4e8
	goto loc_8254B4E8;
loc_8254B4E4:
	// lfs f6,-176(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -176);
	ctx.f6.f64 = double(temp.f32);
loc_8254B4E8:
	// lfs f2,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f2.f64 = double(temp.f32);
	// fnmsubs f31,f6,f5,f11
	f31.f64 = double(float(-(ctx.f6.f64 * ctx.f5.f64 - ctx.f11.f64)));
	// fmuls f30,f2,f13
	f30.f64 = double(float(ctx.f2.f64 * ctx.f13.f64));
	// lfs f2,-4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f29,-172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -172);
	f29.f64 = double(temp.f32);
	// fmuls f28,f13,f13
	f28.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fmuls f29,f2,f29
	f29.f64 = double(float(ctx.f2.f64 * f29.f64));
	// lfs f2,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fabs f27,f2
	f27.u64 = ctx.f2.u64 & ~0x8000000000000000;
	// lfs f26,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	f26.f64 = double(temp.f32);
	// lfs f25,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	f25.f64 = double(temp.f32);
	// fmr f15,f26
	f15.f64 = f26.f64;
	// lfs f23,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	f23.f64 = double(temp.f32);
	// fmuls f24,f2,f13
	f24.f64 = double(float(ctx.f2.f64 * ctx.f13.f64));
	// lfs f22,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f22.f64 = double(temp.f32);
	// fnmsubs f6,f6,f7,f11
	ctx.f6.f64 = double(float(-(ctx.f6.f64 * ctx.f7.f64 - ctx.f11.f64)));
	// lfs f21,12(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	f21.f64 = double(temp.f32);
	// lfs f20,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	f20.f64 = double(temp.f32);
	// fneg f19,f31
	f19.u64 = f31.u64 ^ 0x8000000000000000;
	// lfs f18,16(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	f18.f64 = double(temp.f32);
	// fneg f17,f30
	f17.u64 = f30.u64 ^ 0x8000000000000000;
	// lfs f2,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f2,f2,f10
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f10.f64));
	// lfs f16,-16(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -16);
	f16.f64 = double(temp.f32);
	// fmuls f29,f29,f13
	f29.f64 = double(float(f29.f64 * ctx.f13.f64));
	// fmadds f26,f26,f27,f25
	f26.f64 = double(float(f26.f64 * f27.f64 + f25.f64));
	// fmadds f24,f24,f13,f22
	f24.f64 = double(float(f24.f64 * ctx.f13.f64 + f22.f64));
	// fmuls f22,f18,f8
	f22.f64 = double(float(f18.f64 * ctx.f8.f64));
	// fsel f31,f19,f0,f31
	f31.f64 = f19.f64 >= 0.0 ? f0.f64 : f31.f64;
	// fsel f30,f17,f0,f30
	f30.f64 = f17.f64 >= 0.0 ? f0.f64 : f30.f64;
	// fnmsubs f29,f29,f13,f11
	f29.f64 = double(float(-(f29.f64 * ctx.f13.f64 - ctx.f11.f64)));
	// fmadds f26,f26,f13,f23
	f26.f64 = double(float(f26.f64 * ctx.f13.f64 + f23.f64));
	// fmuls f24,f24,f24
	f24.f64 = double(float(f24.f64 * f24.f64));
	// fmuls f1,f1,f31
	ctx.f1.f64 = double(float(ctx.f1.f64 * f31.f64));
	// fsel f23,f30,f30,f0
	f23.f64 = f30.f64 >= 0.0 ? f30.f64 : f0.f64;
	// fsel f29,f29,f29,f0
	f29.f64 = f29.f64 >= 0.0 ? f29.f64 : f0.f64;
	// fneg f19,f26
	f19.u64 = f26.u64 ^ 0x8000000000000000;
	// fmuls f1,f1,f31
	ctx.f1.f64 = double(float(ctx.f1.f64 * f31.f64));
	// fsubs f17,f23,f9
	f17.f64 = double(float(f23.f64 - ctx.f9.f64));
	// fsubs f14,f29,f11
	f14.f64 = double(float(f29.f64 - ctx.f11.f64));
	// fsel f26,f19,f0,f26
	f26.f64 = f19.f64 >= 0.0 ? f0.f64 : f26.f64;
	// fsel f23,f17,f9,f23
	f23.f64 = f17.f64 >= 0.0 ? ctx.f9.f64 : f23.f64;
	// fsel f29,f14,f11,f29
	f29.f64 = f14.f64 >= 0.0 ? ctx.f11.f64 : f29.f64;
	// fmuls f19,f26,f26
	f19.f64 = double(float(f26.f64 * f26.f64));
	// fsel f17,f23,f4,f3
	f17.f64 = f23.f64 >= 0.0 ? ctx.f4.f64 : ctx.f3.f64;
	// fmuls f29,f29,f21
	f29.f64 = double(float(f29.f64 * f21.f64));
	// fmuls f21,f19,f26
	f21.f64 = double(float(f19.f64 * f26.f64));
	// fsubs f19,f23,f17
	f19.f64 = double(float(f23.f64 - f17.f64));
	// fmsubs f29,f29,f29,f24
	f29.f64 = double(float(f29.f64 * f29.f64 - f24.f64));
	// fadds f24,f19,f17
	f24.f64 = double(float(f19.f64 + f17.f64));
	// fneg f19,f29
	f19.u64 = f29.u64 ^ 0x8000000000000000;
	// fsubs f23,f23,f24
	f23.f64 = double(float(f23.f64 - f24.f64));
	// fsubs f17,f24,f11
	f17.f64 = double(float(f24.f64 - ctx.f11.f64));
	// fsel f29,f19,f0,f29
	f29.f64 = f19.f64 >= 0.0 ? f0.f64 : f29.f64;
	// fsel f24,f23,f24,f17
	f24.f64 = f23.f64 >= 0.0 ? f24.f64 : f17.f64;
	// fsqrts f29,f29
	f29.f64 = double(float(sqrt(f29.f64)));
	// fctiwz f23,f24
	f23.s64 = (f24.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f24.f64));
	// stfd f23,-160(r1)
	PPC_STORE_U64(ctx.r1.u32 + -160, f23.u64);
	// lwz r8,-156(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -156);
	// addi r6,r8,19
	ctx.r6.s64 = ctx.r8.s64 + 19;
	// addi r5,r8,20
	ctx.r5.s64 = ctx.r8.s64 + 20;
	// fsubs f30,f30,f24
	f30.f64 = double(float(f30.f64 - f24.f64));
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r5,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f24,r4,r11
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	f24.f64 = double(temp.f32);
	// lfsx f23,r3,r11
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + r11.u32);
	f23.f64 = double(temp.f32);
	// fsubs f23,f23,f24
	f23.f64 = double(float(f23.f64 - f24.f64));
	// fmadds f30,f23,f30,f24
	f30.f64 = double(float(f23.f64 * f30.f64 + f24.f64));
	// fsubs f24,f12,f30
	f24.f64 = double(float(ctx.f12.f64 - f30.f64));
	// fsel f30,f24,f12,f30
	f30.f64 = f24.f64 >= 0.0 ? ctx.f12.f64 : f30.f64;
	// fnmsubs f30,f21,f26,f30
	f30.f64 = double(float(-(f21.f64 * f26.f64 - f30.f64)));
	// fmadds f1,f1,f31,f30
	ctx.f1.f64 = double(float(ctx.f1.f64 * f31.f64 + f30.f64));
	// fneg f30,f2
	f30.u64 = ctx.f2.u64 ^ 0x8000000000000000;
	// fadds f1,f1,f20
	ctx.f1.f64 = double(float(ctx.f1.f64 + f20.f64));
	// fsubs f31,f1,f29
	f31.f64 = double(float(ctx.f1.f64 - f29.f64));
	// fsel f1,f31,f29,f1
	ctx.f1.f64 = f31.f64 >= 0.0 ? f29.f64 : ctx.f1.f64;
	// fmuls f1,f1,f18
	ctx.f1.f64 = double(float(ctx.f1.f64 * f18.f64));
	// fmadds f1,f1,f8,f28
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f8.f64 + f28.f64));
	// fsubs f31,f12,f1
	f31.f64 = double(float(ctx.f12.f64 - ctx.f1.f64));
	// fsel f1,f31,f12,f1
	ctx.f1.f64 = f31.f64 >= 0.0 ? ctx.f12.f64 : ctx.f1.f64;
	// fsqrts f31,f1
	f31.f64 = double(float(sqrt(ctx.f1.f64)));
	// fmadds f28,f15,f27,f25
	f28.f64 = double(float(f15.f64 * f27.f64 + f25.f64));
	// lfs f29,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	f29.f64 = double(temp.f32);
	// fneg f27,f6
	f27.u64 = ctx.f6.u64 ^ 0x8000000000000000;
	// lfs f1,-168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -168);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f25,f31,f16
	f25.f64 = double(float(f31.f64 - f16.f64));
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// fsel f2,f30,f0,f2
	ctx.f2.f64 = f30.f64 >= 0.0 ? f0.f64 : ctx.f2.f64;
	// addi r10,r10,56
	ctx.r10.s64 = ctx.r10.s64 + 56;
	// fmuls f26,f10,f10
	f26.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f30,f28,f10,f29
	f30.f64 = double(float(f28.f64 * ctx.f10.f64 + f29.f64));
	// fsel f29,f27,f0,f6
	f29.f64 = f27.f64 >= 0.0 ? f0.f64 : ctx.f6.f64;
	// fsel f6,f25,f16,f31
	ctx.f6.f64 = f25.f64 >= 0.0 ? f16.f64 : f31.f64;
	// fsel f31,f2,f2,f0
	f31.f64 = ctx.f2.f64 >= 0.0 ? ctx.f2.f64 : f0.f64;
	// fneg f28,f30
	f28.u64 = f30.u64 ^ 0x8000000000000000;
	// fmuls f27,f1,f29
	f27.f64 = double(float(ctx.f1.f64 * f29.f64));
	// fadds f25,f6,f13
	f25.f64 = double(float(ctx.f6.f64 + ctx.f13.f64));
	// fmr f13,f6
	ctx.f13.f64 = ctx.f6.f64;
	// fsubs f6,f31,f9
	ctx.f6.f64 = double(float(f31.f64 - ctx.f9.f64));
	// fsel f30,f28,f0,f30
	f30.f64 = f28.f64 >= 0.0 ? f0.f64 : f30.f64;
	// fmuls f28,f27,f29
	f28.f64 = double(float(f27.f64 * f29.f64));
	// fdivs f27,f22,f25
	f27.f64 = double(float(f22.f64 / f25.f64));
	// fsel f6,f6,f9,f31
	ctx.f6.f64 = ctx.f6.f64 >= 0.0 ? ctx.f9.f64 : f31.f64;
	// fmuls f31,f30,f30
	f31.f64 = double(float(f30.f64 * f30.f64));
	// fadds f5,f27,f5
	ctx.f5.f64 = double(float(f27.f64 + ctx.f5.f64));
	// fsel f27,f6,f4,f3
	f27.f64 = ctx.f6.f64 >= 0.0 ? ctx.f4.f64 : ctx.f3.f64;
	// fmuls f31,f31,f30
	f31.f64 = double(float(f31.f64 * f30.f64));
	// fsubs f25,f6,f27
	f25.f64 = double(float(ctx.f6.f64 - f27.f64));
	// fadds f27,f25,f27
	f27.f64 = double(float(f25.f64 + f27.f64));
	// fsubs f6,f6,f27
	ctx.f6.f64 = double(float(ctx.f6.f64 - f27.f64));
	// fsubs f25,f27,f11
	f25.f64 = double(float(f27.f64 - ctx.f11.f64));
	// fsel f6,f6,f27,f25
	ctx.f6.f64 = ctx.f6.f64 >= 0.0 ? f27.f64 : f25.f64;
	// fctiwz f27,f6
	f27.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f27,-160(r1)
	PPC_STORE_U64(ctx.r1.u32 + -160, f27.u64);
	// lwz r8,-156(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -156);
	// addi r6,r8,19
	ctx.r6.s64 = ctx.r8.s64 + 19;
	// addi r5,r8,20
	ctx.r5.s64 = ctx.r8.s64 + 20;
	// fsubs f2,f2,f6
	ctx.f2.f64 = double(float(ctx.f2.f64 - ctx.f6.f64));
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r5,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f6,r4,r11
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	ctx.f6.f64 = double(temp.f32);
	// lfsx f27,r3,r11
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + r11.u32);
	f27.f64 = double(temp.f32);
	// fsubs f27,f27,f6
	f27.f64 = double(float(f27.f64 - ctx.f6.f64));
	// fmadds f2,f27,f2,f6
	ctx.f2.f64 = double(float(f27.f64 * ctx.f2.f64 + ctx.f6.f64));
	// fsubs f6,f12,f2
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f2.f64));
	// fsel f2,f6,f12,f2
	ctx.f2.f64 = ctx.f6.f64 >= 0.0 ? ctx.f12.f64 : ctx.f2.f64;
	// fmadds f6,f28,f29,f2
	ctx.f6.f64 = double(float(f28.f64 * f29.f64 + ctx.f2.f64));
	// fnmsubs f2,f31,f30,f6
	ctx.f2.f64 = double(float(-(f31.f64 * f30.f64 - ctx.f6.f64)));
	// fadds f6,f2,f20
	ctx.f6.f64 = double(float(ctx.f2.f64 + f20.f64));
	// fmuls f2,f6,f18
	ctx.f2.f64 = double(float(ctx.f6.f64 * f18.f64));
	// fmadds f6,f2,f8,f26
	ctx.f6.f64 = double(float(ctx.f2.f64 * ctx.f8.f64 + f26.f64));
	// fsubs f2,f12,f6
	ctx.f2.f64 = double(float(ctx.f12.f64 - ctx.f6.f64));
	// fsel f6,f2,f12,f6
	ctx.f6.f64 = ctx.f2.f64 >= 0.0 ? ctx.f12.f64 : ctx.f6.f64;
	// fsqrts f6,f6
	ctx.f6.f64 = double(float(sqrt(ctx.f6.f64)));
	// fadds f2,f6,f10
	ctx.f2.f64 = double(float(ctx.f6.f64 + ctx.f10.f64));
	// fmr f10,f6
	ctx.f10.f64 = ctx.f6.f64;
	// fdivs f6,f22,f2
	ctx.f6.f64 = double(float(f22.f64 / ctx.f2.f64));
	// fadds f7,f6,f7
	ctx.f7.f64 = double(float(ctx.f6.f64 + ctx.f7.f64));
	// bne 0x8254b4e4
	if (!cr0.eq) goto loc_8254B4E4;
loc_8254B714:
	// lfs f13,5036(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 5036);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsubs f12,f13,f7
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f7.f64));
	// lfs f13,14196(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14196);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x8254b740
	if (!cr6.gt) goto loc_8254B740;
	// lfs f13,5036(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 5036);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f5
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f5.f64));
	// fsubs f10,f13,f7
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f7.f64));
	// fdivs f13,f12,f10
	ctx.f13.f64 = double(float(ctx.f12.f64 / ctx.f10.f64));
	// b 0x8254b744
	goto loc_8254B744;
loc_8254B740:
	// fmr f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f0.f64;
loc_8254B744:
	// fsel f0,f13,f13,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// fsubs f13,f0,f11
	ctx.f13.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fsel f1,f13,f11,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? ctx.f11.f64 : f0.f64;
	// addi r12,r1,-8
	r12.s64 = ctx.r1.s64 + -8;
	// bl 0x823db9ec
	ctx.lr = 0x8254B758;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8254B764"))) PPC_WEAK_FUNC(sub_8254B764);
PPC_FUNC_IMPL(__imp__sub_8254B764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8254B768"))) PPC_WEAK_FUNC(sub_8254B768);
PPC_FUNC_IMPL(__imp__sub_8254B768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// li r11,0
	r11.s64 = 0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r11,30840(r3)
	PPC_STORE_U32(ctx.r3.u32 + 30840, r11.u32);
	// stw r11,30836(r3)
	PPC_STORE_U32(ctx.r3.u32 + 30836, r11.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,30832(r3)
	PPC_STORE_U32(ctx.r3.u32 + 30832, r11.u32);
	// stw r11,22552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 22552, r11.u32);
	// stw r11,22548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 22548, r11.u32);
	// lfs f13,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,22544(r3)
	PPC_STORE_U32(ctx.r3.u32 + 22544, r11.u32);
	// lfs f0,-31380(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -31380);
	f0.f64 = double(temp.f32);
	// stw r11,22560(r3)
	PPC_STORE_U32(ctx.r3.u32 + 22560, r11.u32);
	// stw r11,22712(r3)
	PPC_STORE_U32(ctx.r3.u32 + 22712, r11.u32);
	// stw r11,22708(r3)
	PPC_STORE_U32(ctx.r3.u32 + 22708, r11.u32);
	// stw r11,22704(r3)
	PPC_STORE_U32(ctx.r3.u32 + 22704, r11.u32);
	// stw r11,22716(r3)
	PPC_STORE_U32(ctx.r3.u32 + 22716, r11.u32);
	// stw r11,22984(r3)
	PPC_STORE_U32(ctx.r3.u32 + 22984, r11.u32);
	// stw r11,22980(r3)
	PPC_STORE_U32(ctx.r3.u32 + 22980, r11.u32);
	// stw r11,22976(r3)
	PPC_STORE_U32(ctx.r3.u32 + 22976, r11.u32);
	// stw r11,22992(r3)
	PPC_STORE_U32(ctx.r3.u32 + 22992, r11.u32);
	// stw r11,23048(r3)
	PPC_STORE_U32(ctx.r3.u32 + 23048, r11.u32);
	// stw r11,23044(r3)
	PPC_STORE_U32(ctx.r3.u32 + 23044, r11.u32);
	// stw r11,23040(r3)
	PPC_STORE_U32(ctx.r3.u32 + 23040, r11.u32);
	// stw r11,23052(r3)
	PPC_STORE_U32(ctx.r3.u32 + 23052, r11.u32);
	// stw r11,30760(r3)
	PPC_STORE_U32(ctx.r3.u32 + 30760, r11.u32);
	// stw r11,30756(r3)
	PPC_STORE_U32(ctx.r3.u32 + 30756, r11.u32);
	// stw r11,30752(r3)
	PPC_STORE_U32(ctx.r3.u32 + 30752, r11.u32);
	// stw r11,30764(r3)
	PPC_STORE_U32(ctx.r3.u32 + 30764, r11.u32);
	// stfs f13,30776(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 30776, temp.u32);
	// stfs f0,30472(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 30472, temp.u32);
	// stw r10,30784(r3)
	PPC_STORE_U32(ctx.r3.u32 + 30784, ctx.r10.u32);
	// stfs f0,30476(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 30476, temp.u32);
	// stw r10,30772(r3)
	PPC_STORE_U32(ctx.r3.u32 + 30772, ctx.r10.u32);
	// stfs f0,30768(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 30768, temp.u32);
	// stw r11,30780(r3)
	PPC_STORE_U32(ctx.r3.u32 + 30780, r11.u32);
	// stw r11,30468(r3)
	PPC_STORE_U32(ctx.r3.u32 + 30468, r11.u32);
	// stw r11,26472(r3)
	PPC_STORE_U32(ctx.r3.u32 + 26472, r11.u32);
	// stw r11,26468(r3)
	PPC_STORE_U32(ctx.r3.u32 + 26468, r11.u32);
	// stw r11,26464(r3)
	PPC_STORE_U32(ctx.r3.u32 + 26464, r11.u32);
	// stw r11,26480(r3)
	PPC_STORE_U32(ctx.r3.u32 + 26480, r11.u32);
	// stw r11,26760(r3)
	PPC_STORE_U32(ctx.r3.u32 + 26760, r11.u32);
	// stw r11,26756(r3)
	PPC_STORE_U32(ctx.r3.u32 + 26756, r11.u32);
	// stw r11,26752(r3)
	PPC_STORE_U32(ctx.r3.u32 + 26752, r11.u32);
	// stw r11,26764(r3)
	PPC_STORE_U32(ctx.r3.u32 + 26764, r11.u32);
	// stw r11,30464(r3)
	PPC_STORE_U32(ctx.r3.u32 + 30464, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8254B824"))) PPC_WEAK_FUNC(sub_8254B824);
PPC_FUNC_IMPL(__imp__sub_8254B824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8254B828"))) PPC_WEAK_FUNC(sub_8254B828);
PPC_FUNC_IMPL(__imp__sub_8254B828) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,22552(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 22552);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r10,22544(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 22544);
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// li r8,127
	ctx.r8.s64 = 127;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,22552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 22552, ctx.r9.u32);
	// bne cr6,0x8254b85c
	if (!cr6.eq) goto loc_8254B85C;
	// stw r8,22528(r11)
	PPC_STORE_U32(r11.u32 + 22528, ctx.r8.u32);
	// b 0x8254b864
	goto loc_8254B864;
loc_8254B85C:
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,22528(r11)
	PPC_STORE_U32(r11.u32 + 22528, ctx.r10.u32);
loc_8254B864:
	// lwz r9,22712(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 22712);
	// addi r10,r3,22576
	ctx.r10.s64 = ctx.r3.s64 + 22576;
	// addi r7,r9,-1
	ctx.r7.s64 = ctx.r9.s64 + -1;
	// lwz r9,22704(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 22704);
	// stw r7,22712(r3)
	PPC_STORE_U32(ctx.r3.u32 + 22712, ctx.r7.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8254b888
	if (!cr6.eq) goto loc_8254B888;
	// stw r8,128(r10)
	PPC_STORE_U32(ctx.r10.u32 + 128, ctx.r8.u32);
	// b 0x8254b890
	goto loc_8254B890;
loc_8254B888:
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stw r9,128(r10)
	PPC_STORE_U32(ctx.r10.u32 + 128, ctx.r9.u32);
loc_8254B890:
	// lwz r10,22544(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 22544);
	// lwz r11,22536(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22536);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lwz r11,30832(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 30832);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8254b8b0
	if (cr6.lt) goto loc_8254B8B0;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8254B8B0:
	// stw r11,30832(r3)
	PPC_STORE_U32(ctx.r3.u32 + 30832, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8254B8B8"))) PPC_WEAK_FUNC(sub_8254B8B8);
PPC_FUNC_IMPL(__imp__sub_8254B8B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x8254B8C0;
	// stfd f31,-136(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -136, f31.u64);
	// li r12,-176
	r12.s64 = -176;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-160
	r12.s64 = -160;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r28,r21,16
	r28.s64 = r21.s64 + 16;
	// lwz r11,22560(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 22560);
	// lwz r9,22552(r21)
	ctx.r9.u64 = PPC_LOAD_U32(r21.u32 + 22552);
	// lfs f0,18612(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 18612);
	f0.f64 = double(temp.f32);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// lwz r10,30832(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 30832);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// add r17,r8,r9
	r17.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// ble cr6,0x8254b918
	if (!cr6.gt) goto loc_8254B918;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8254B918:
	// stw r11,30832(r21)
	PPC_STORE_U32(r21.u32 + 30832, r11.u32);
	// cmpw cr6,r11,r17
	cr6.compare<int32_t>(r11.s32, r17.s32, xer);
	// bge cr6,0x8254bdbc
	if (!cr6.lt) goto loc_8254BDBC;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lvx128 v126,r0,r7
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lfs f0,-29232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	f0.f64 = double(temp.f32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lfs f31,-31408(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -31408);
	f31.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r18,32
	r18.s64 = 32;
	// li r19,48
	r19.s64 = 48;
	// addi r20,r11,-31664
	r20.s64 = r11.s64 + -31664;
	// addi r24,r10,2352
	r24.s64 = ctx.r10.s64 + 2352;
	// addi r23,r9,2384
	r23.s64 = ctx.r9.s64 + 2384;
	// addi r22,r8,-31568
	r22.s64 = ctx.r8.s64 + -31568;
	// addi r25,r7,2272
	r25.s64 = ctx.r7.s64 + 2272;
loc_8254B970:
	// lwz r7,22544(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 22544);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lwz r10,22532(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 22532);
	// lvx128 v63,r0,r22
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,30832(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 30832);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// subf r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
	// lwz r9,22532(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 22532);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// lvlx128 v62,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// subf r11,r6,r11
	r11.s64 = r11.s64 - ctx.r6.s64;
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// srawi r4,r5,7
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7F) != 0);
	ctx.r4.s64 = ctx.r5.s32 >> 7;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addze r3,r4
	temp.s64 = ctx.r4.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r3.s64 = temp.s64;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// rlwinm r9,r3,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 7) & 0xFFFFFF80;
	// srawi r8,r10,7
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7F) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 7;
	// subf r7,r9,r5
	ctx.r7.s64 = ctx.r5.s64 - ctx.r9.s64;
	// addze r6,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r6.s64 = temp.s64;
	// mulli r11,r7,176
	r11.s64 = ctx.r7.s64 * 176;
	// add r31,r11,r28
	r31.u64 = r11.u64 + r28.u64;
	// rlwinm r5,r6,7,0,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 7) & 0xFFFFFF80;
	// addi r27,r31,16
	r27.s64 = r31.s64 + 16;
	// subf r4,r5,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r5.s64;
	// addi r30,r31,80
	r30.s64 = r31.s64 + 80;
	// lvx128 v60,r0,r31
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mulli r11,r4,176
	r11.s64 = ctx.r4.s64 * 176;
	// lvx128 v59,r0,r27
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v58,v59,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	// add r29,r11,r28
	r29.u64 = r11.u64 + r28.u64;
	// addi r26,r29,16
	r26.s64 = r29.s64 + 16;
	// lvx128 v57,r0,r29
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v56,v58,v57
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v57.f32)));
	// lvx128 v55,r0,r26
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v54,v57,v55
	simde_mm_store_ps(v54.f32, simde_mm_add_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v55.f32)));
	// vaddfp128 v53,v56,v55
	simde_mm_store_ps(v53.f32, simde_mm_add_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v55.f32)));
	// vmulfp128 v52,v54,v63
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v63.f32)));
	// vmulfp128 v127,v53,v61
	simde_mm_store_ps(v127.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v61.f32)));
	// vsubfp128 v51,v52,v127
	simde_mm_store_ps(v51.f32, simde_mm_sub_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v127.f32)));
	// stvx128 v51,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r23
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r24
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r0,r29
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r0,r26
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v49,v50
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v50.f32)));
	// vmsum3fp128 v62,v63,v63
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vand128 v48,v126,v61
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vand128 v47,v62,v61
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vor128 v46,v47,v60
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vcmpgtfp128. v45,v46,v48
	simde_mm_store_ps(v45.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v48.f32)));
	cr6.setFromMask(simde_mm_load_ps(v45.f32), 0xF);
	// mfocrf r3,2
	ctx.r3.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r11,r3,0,24,24
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8254ba78
	if (cr6.eq) goto loc_8254BA78;
	// vrefp128 v0,v62
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v62.f32)));
	// vor128 v11,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// lvx128 v12,r0,r20
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v13,v51,v51
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v51.u8));
	// vor128 v10,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vmsum3fp128 v44,v13,v63
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vnmsubfp v8,v0,v11,v12
	simde_mm_store_ps(ctx.v8.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v7,v0,v8,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v6,v44,v7
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(ctx.v7.f32)));
	// vnmsubfp v5,v10,v6,v13
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v5,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8254BA78:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v1,r0,r25
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82165300
	ctx.lr = 0x8254BA88;
	sub_82165300(ctx, base);
	// lvx128 v43,r0,r27
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r0,r31
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// vaddfp128 v41,v42,v43
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v41.f32, simde_mm_add_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v43.f32)));
	// lvx128 v63,r0,r22
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v40,v41,v63
	simde_mm_store_ps(v40.f32, simde_mm_mul_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v63.f32)));
	// vor128 v39,v40,v40
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_load_si128((simde__m128i*)v40.u8));
	// stvx128 v40,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v38,v39,v127
	simde_mm_store_ps(v38.f32, simde_mm_sub_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v127.f32)));
	// stvx128 v38,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r23
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r24
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v37,r0,r31
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v36,r0,r27
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v36,v37
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v37.f32)));
	// vmsum3fp128 v62,v63,v63
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vand128 v35,v126,v61
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vand128 v34,v62,v61
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vor128 v33,v34,v60
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vcmpgtfp128. v32,v33,v35
	simde_mm_store_ps(v32.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v33.f32), simde_mm_load_ps(v35.f32)));
	cr6.setFromMask(simde_mm_load_ps(v32.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8254bb18
	if (cr6.eq) goto loc_8254BB18;
	// vrefp128 v0,v62
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v62.f32)));
	// vor128 v12,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// lvx128 v13,r0,r20
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v62,v38,v38
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_load_si128((simde__m128i*)v38.u8));
	// vor128 v11,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vor128 v10,v38,v38
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v38.u8));
	// vmsum3fp128 v61,v62,v63
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vnmsubfp v8,v0,v12,v13
	simde_mm_store_ps(ctx.v8.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v7,v0,v8,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v6,v61,v7
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v7.f32)));
	// vnmsubfp v5,v11,v6,v10
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v10.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v5,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8254BB18:
	// lvx128 v1,r0,r25
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82165300
	ctx.lr = 0x8254BB24;
	sub_82165300(ctx, base);
	// lvx128 v61,r0,r31
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r29
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v60,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// lvx128 v59,r0,r23
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r24
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v57,v126,v59
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vmsum3fp128 v62,v63,v63
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vand128 v56,v62,v59
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vor128 v55,v56,v58
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)v58.u8)));
	// vcmpgtfp128. v54,v55,v57
	simde_mm_store_ps(v54.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v57.f32)));
	cr6.setFromMask(simde_mm_load_ps(v54.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// fmr f1,f31
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.f64 = f31.f64;
	// addi r3,r30,32
	ctx.r3.s64 = r30.s64 + 32;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8254bbb4
	if (cr6.eq) goto loc_8254BBB4;
	// vaddfp128 v53,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v53.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// lvx128 v61,r0,r22
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrefp128 v0,v62
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v62.f32)));
	// vor128 v12,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// vor128 v11,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vmulfp128 v52,v53,v61
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v51,v52,v52
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// stvx128 v52,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v50,v51,v127
	simde_mm_store_ps(v50.f32, simde_mm_sub_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v127.f32)));
	// stvx128 v50,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v49,v50,v50
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_load_si128((simde__m128i*)v50.u8));
	// lvx128 v13,r0,r20
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v8,v0,v12,v13
	simde_mm_store_ps(ctx.v8.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v48,v49,v63
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmaddfp v7,v0,v8,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vor128 v9,v50,v50
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v50.u8));
	// vmulfp128 v6,v48,v7
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(ctx.v7.f32)));
	// vnmsubfp v5,v11,v6,v9
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v9.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v5,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8254bbbc
	goto loc_8254BBBC;
loc_8254BBB4:
	// vsubfp128 v47,v61,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v47.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v127.f32)));
	// stvx128 v47,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8254BBBC:
	// lvx128 v1,r0,r25
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82165300
	ctx.lr = 0x8254BBC4;
	sub_82165300(ctx, base);
	// lvx128 v61,r0,r27
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r26
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v60,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// lvx128 v59,r0,r23
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r24
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v46,v126,v59
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vmsum3fp128 v62,v63,v63
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vand128 v45,v62,v59
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vor128 v44,v45,v58
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)v58.u8)));
	// vcmpgtfp128. v43,v44,v46
	simde_mm_store_ps(v43.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v46.f32)));
	cr6.setFromMask(simde_mm_load_ps(v43.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// fmr f1,f31
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.f64 = f31.f64;
	// addi r3,r30,48
	ctx.r3.s64 = r30.s64 + 48;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8254bc54
	if (cr6.eq) goto loc_8254BC54;
	// vaddfp128 v42,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v42.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// lvx128 v61,r0,r22
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrefp128 v0,v62
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v62.f32)));
	// vor128 v12,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// vor128 v11,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vmulfp128 v41,v42,v61
	simde_mm_store_ps(v41.f32, simde_mm_mul_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v40,v41,v41
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_load_si128((simde__m128i*)v41.u8));
	// stvx128 v41,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v39,v40,v127
	simde_mm_store_ps(v39.f32, simde_mm_sub_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v127.f32)));
	// stvx128 v39,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v38,v39,v39
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_load_si128((simde__m128i*)v39.u8));
	// lvx128 v13,r0,r20
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v9,v0,v12,v13
	simde_mm_store_ps(ctx.v9.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v37,v38,v63
	simde_mm_store_ps(v37.f32, simde_mm_dp_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vmaddfp v7,v0,v9,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vor128 v8,v39,v39
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v39.u8));
	// vmulfp128 v6,v37,v7
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(ctx.v7.f32)));
	// vnmsubfp v5,v11,v6,v8
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v8.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v5,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8254bc5c
	goto loc_8254BC5C;
loc_8254BC54:
	// vsubfp128 v36,v61,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v36.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v127.f32)));
	// stvx128 v36,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8254BC5C:
	// lvx128 v1,r0,r25
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82165300
	ctx.lr = 0x8254BC64;
	sub_82165300(ctx, base);
	// lvx128 v61,r31,r18
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r29,r18
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v60,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// lvx128 v59,r0,r23
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r24
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v35,v126,v59
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vmsum3fp128 v62,v63,v63
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vand128 v34,v62,v59
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vor128 v33,v34,v58
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)v58.u8)));
	// vcmpgtfp128. v32,v33,v35
	simde_mm_store_ps(v32.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v33.f32), simde_mm_load_ps(v35.f32)));
	cr6.setFromMask(simde_mm_load_ps(v32.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// fmr f1,f31
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.f64 = f31.f64;
	// addi r3,r30,64
	ctx.r3.s64 = r30.s64 + 64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8254bcf4
	if (cr6.eq) goto loc_8254BCF4;
	// vaddfp128 v60,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// lvx128 v61,r0,r22
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrefp128 v0,v62
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v62.f32)));
	// vor128 v12,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// vor128 v11,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vmulfp128 v59,v60,v61
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v58,v59,v59
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// stvx128 v59,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v57,v58,v127
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v127.f32)));
	// stvx128 v57,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v56,v57,v57
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// vor128 v9,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// vmsum3fp128 v55,v56,v63
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lvx128 v13,r0,r20
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v8,v0,v12,v13
	simde_mm_store_ps(ctx.v8.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v7,v0,v8,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v6,v55,v7
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(ctx.v7.f32)));
	// vnmsubfp v5,v11,v6,v9
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v9.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v5,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8254bcfc
	goto loc_8254BCFC;
loc_8254BCF4:
	// vsubfp128 v54,v61,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v127.f32)));
	// stvx128 v54,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8254BCFC:
	// lvx128 v1,r0,r25
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82165300
	ctx.lr = 0x8254BD04;
	sub_82165300(ctx, base);
	// lvx128 v61,r31,r19
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r29,r19
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v60,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// lvx128 v59,r0,r23
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r24
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v53,v126,v59
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vmsum3fp128 v62,v63,v63
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vand128 v52,v62,v59
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vor128 v51,v52,v58
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)v58.u8)));
	// vcmpgtfp128. v50,v51,v53
	simde_mm_store_ps(v50.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v53.f32)));
	cr6.setFromMask(simde_mm_load_ps(v50.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// fmr f1,f31
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.f64 = f31.f64;
	// addi r3,r30,80
	ctx.r3.s64 = r30.s64 + 80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8254bd94
	if (cr6.eq) goto loc_8254BD94;
	// vaddfp128 v49,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v49.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// lvx128 v61,r0,r22
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrefp128 v0,v62
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v62.f32)));
	// vor128 v12,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// vor128 v11,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vmulfp128 v48,v49,v61
	simde_mm_store_ps(v48.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v47,v48,v48
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_load_si128((simde__m128i*)v48.u8));
	// stvx128 v48,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v46,v47,v127
	simde_mm_store_ps(v46.f32, simde_mm_sub_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v127.f32)));
	// stvx128 v46,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v45,v46,v46
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_load_si128((simde__m128i*)v46.u8));
	// vor128 v8,v46,v46
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v46.u8));
	// vmsum3fp128 v44,v45,v63
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lvx128 v13,r0,r20
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v9,v0,v12,v13
	simde_mm_store_ps(ctx.v9.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v7,v0,v9,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v6,v44,v7
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(ctx.v7.f32)));
	// vnmsubfp v5,v11,v6,v8
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v8.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v5,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8254bd9c
	goto loc_8254BD9C;
loc_8254BD94:
	// vsubfp128 v43,v61,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v43.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v127.f32)));
	// stvx128 v43,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8254BD9C:
	// lvx128 v1,r0,r25
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82165300
	ctx.lr = 0x8254BDA4;
	sub_82165300(ctx, base);
	// lwz r11,30832(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 30832);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r11,30832(r21)
	PPC_STORE_U32(r21.u32 + 30832, r11.u32);
	// cmpw cr6,r10,r17
	cr6.compare<int32_t>(ctx.r10.s32, r17.s32, xer);
	// blt cr6,0x8254b970
	if (cr6.lt) goto loc_8254B970;
loc_8254BDBC:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// li r0,-176
	r0.s64 = -176;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-160
	r0.s64 = -160;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-136(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_8254BDD8"))) PPC_WEAK_FUNC(sub_8254BDD8);
PPC_FUNC_IMPL(__imp__sub_8254BDD8) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8254BDE0;
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-64
	r12.s64 = -64;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// vor128 v126,v2,v2
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f11,25348(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 25348);
	ctx.f11.f64 = double(temp.f32);
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// stvx128 v126,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f6.f64 = double(temp.f32);
	// lfs f0,14196(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14196);
	f0.f64 = double(temp.f32);
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// lfs f10,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f12,f12,f10
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// fsubs f13,f7,f6
	ctx.f13.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fsubs f0,f9,f8
	f0.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// ble cr6,0x8254be9c
	if (!cr6.gt) goto loc_8254BE9C;
	// fmuls f9,f13,f13
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,17032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f8,f12,f12,f9
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f9.f64));
	// fmadds f7,f0,f0,f8
	ctx.f7.f64 = double(float(f0.f64 * f0.f64 + ctx.f8.f64));
	// fsqrts f6,f7
	ctx.f6.f64 = double(float(sqrt(ctx.f7.f64)));
	// fadds f5,f6,f13
	ctx.f5.f64 = double(float(ctx.f6.f64 + ctx.f13.f64));
	// fdivs f4,f5,f11
	ctx.f4.f64 = double(float(ctx.f5.f64 / ctx.f11.f64));
	// fadds f3,f4,f10
	ctx.f3.f64 = double(float(ctx.f4.f64 + ctx.f10.f64));
	// fctiwz f2,f3
	ctx.f2.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f2,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f2.u64);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,32
	cr6.compare<int32_t>(r11.s32, 32, xer);
	// ble cr6,0x8254be9c
	if (!cr6.gt) goto loc_8254BE9C;
loc_8254BE94:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8254bf74
	goto loc_8254BF74;
loc_8254BE9C:
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmpw cr6,r4,r29
	cr6.compare<int32_t>(ctx.r4.s32, r29.s32, xer);
	// bgt cr6,0x8254bf70
	if (cr6.gt) goto loc_8254BF70;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r31,r3,16
	r31.s64 = ctx.r3.s64 + 16;
	// lfs f30,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f30.f64 = double(temp.f32);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_8254BEBC:
	// lwz r11,22532(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 22532);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r7,22544(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 22544);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// subf r11,r7,r11
	r11.s64 = r11.s64 - ctx.r7.s64;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// stvx128 v126,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// subf r11,r3,r4
	r11.s64 = ctx.r4.s64 - ctx.r3.s64;
	// stvx128 v127,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// srawi r8,r10,7
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7F) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 7;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// addze r5,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r5.s64 = temp.s64;
	// srawi r4,r7,7
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7F) != 0);
	ctx.r4.s64 = ctx.r7.s32 >> 7;
	// rlwinm r3,r5,7,0,24
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 7) & 0xFFFFFF80;
	// addze r11,r4
	temp.s64 = ctx.r4.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r4.u32;
	r11.s64 = temp.s64;
	// subf r10,r3,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r3.s64;
	// rlwinm r8,r11,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// mulli r11,r10,176
	r11.s64 = ctx.r10.s64 * 176;
	// subf r7,r8,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r8.s64;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// mulli r10,r7,176
	ctx.r10.s64 = ctx.r7.s64 * 176;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r8,r11,48
	ctx.r8.s64 = r11.s64 + 48;
	// addi r7,r10,32
	ctx.r7.s64 = ctx.r10.s64 + 32;
	// bl 0x8216ca78
	ctx.lr = 0x8254BF44;
	sub_8216CA78(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8254be94
	if (cr6.eq) goto loc_8254BE94;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x8254be94
	if (cr6.lt) goto loc_8254BE94;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bgt cr6,0x8254be94
	if (cr6.gt) goto loc_8254BE94;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// ble cr6,0x8254bebc
	if (!cr6.gt) goto loc_8254BEBC;
loc_8254BF70:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8254BF74:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-64
	r0.s64 = -64;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8254BF94"))) PPC_WEAK_FUNC(sub_8254BF94);
PPC_FUNC_IMPL(__imp__sub_8254BF94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8254BF98"))) PPC_WEAK_FUNC(sub_8254BF98);
PPC_FUNC_IMPL(__imp__sub_8254BF98) {
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
	// bl 0x823d91e0
	ctx.lr = 0x8254BFA0;
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// addi r29,r31,22720
	r29.s64 = r31.s64 + 22720;
	// lwz r10,22560(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 22560);
	// lwz r11,22552(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 22552);
	// lwz r8,22992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 22992);
	// lwz r9,22984(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 22984);
	// add r23,r10,r11
	r23.u64 = ctx.r10.u64 + r11.u64;
	// add r22,r8,r9
	r22.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmpwi cr6,r23,2
	cr6.compare<int32_t>(r23.s32, 2, xer);
	// ble cr6,0x8254c1dc
	if (!cr6.gt) goto loc_8254C1DC;
	// lwz r8,26764(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 26764);
	// addi r11,r31,26496
	r11.s64 = r31.s64 + 26496;
	// lwz r9,26756(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 26756);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// lwz r8,26760(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 26760);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r10,30840(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 30840);
	// add r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmpw cr6,r10,r22
	cr6.compare<int32_t>(ctx.r10.s32, r22.s32, xer);
	// srawi r6,r7,6
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3F) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 6;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// rlwinm r4,r5,6,0,25
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r3,r4,r7
	ctx.r3.s64 = ctx.r7.s64 - ctx.r4.s64;
	// rlwinm r9,r3,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// srawi r24,r8,1
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	r24.s64 = ctx.r8.s32 >> 1;
	// bge cr6,0x8254c068
	if (!cr6.lt) goto loc_8254C068;
	// lwz r8,23052(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 23052);
	// addi r11,r31,23008
	r11.s64 = r31.s64 + 23008;
	// lwz r9,23044(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 23044);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// srawi r6,r7,3
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 3;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// rlwinm r4,r5,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r3,r4,r7
	ctx.r3.s64 = ctx.r7.s64 - ctx.r4.s64;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// srawi r8,r9,13
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1FFF) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 13;
	// cmpw cr6,r8,r24
	cr6.compare<int32_t>(ctx.r8.s32, r24.s32, xer);
	// bgt cr6,0x8254c068
	if (cr6.gt) goto loc_8254C068;
	// addi r3,r24,1
	ctx.r3.s64 = r24.s64 + 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_8254C068:
	// lwz r9,26480(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 26480);
	// addi r11,r31,25440
	r11.s64 = r31.s64 + 25440;
	// lwz r10,26472(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 26472);
	// addi r28,r24,2
	r28.s64 = r24.s64 + 2;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// cmpw cr6,r28,r23
	cr6.compare<int32_t>(r28.s32, r23.s32, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// lwz r8,26468(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 26468);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r7,r10,r8
	ctx.r7.u64 = ctx.r10.u64 + ctx.r8.u64;
	// srawi r6,r7,6
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3F) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 6;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// rlwinm r4,r5,6,0,25
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r3,r4,r7
	ctx.r3.s64 = ctx.r7.s64 - ctx.r4.s64;
	// rlwinm r10,r3,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// add r27,r10,r11
	r27.u64 = ctx.r10.u64 + r11.u64;
	// bge cr6,0x8254c1dc
	if (!cr6.lt) goto loc_8254C1DC;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r26,16
	r26.s64 = 16;
	// addi r25,r11,-31568
	r25.s64 = r11.s64 + -31568;
	// lfs f31,-31408(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31408);
	f31.f64 = double(temp.f32);
loc_8254C0C0:
	// lwz r11,22532(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22532);
	// lvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,22544(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 22544);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// lfs f0,4(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	f0.f64 = double(temp.f32);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// lfs f13,8(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// lfs f12,0(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// subf r10,r7,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r7.s64;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// add r11,r10,r28
	r11.u64 = ctx.r10.u64 + r28.u64;
	// srawi r5,r6,7
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7F) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 7;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// addze r3,r5
	temp.s64 = ctx.r5.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r3.s64 = temp.s64;
	// srawi r11,r4,7
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7F) != 0);
	r11.s64 = ctx.r4.s32 >> 7;
	// rlwinm r10,r3,7,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 7) & 0xFFFFFF80;
	// addze r8,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	ctx.r8.s64 = temp.s64;
	// subf r7,r10,r6
	ctx.r7.s64 = ctx.r6.s64 - ctx.r10.s64;
	// rlwinm r6,r8,7,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// mulli r5,r7,176
	ctx.r5.s64 = ctx.r7.s64 * 176;
	// lvx128 v62,r5,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// subf r4,r6,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r6.s64;
	// mulli r11,r4,176
	r11.s64 = ctx.r4.s64 * 176;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// lvx128 v61,r3,r26
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// vmulfp128 v2,v60,v63
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v2,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 - f0.f64));
	// fsubs f7,f11,f13
	ctx.f7.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// fmuls f6,f8,f8
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fsubs f5,f10,f12
	ctx.f5.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// fmadds f4,f7,f7,f6
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fmadds f3,f5,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fcmpu cr6,f3,f31
	cr6.compare(ctx.f3.f64, f31.f64);
	// blt cr6,0x8254c1d0
	if (cr6.lt) goto loc_8254C1D0;
	// addi r5,r28,-1
	ctx.r5.s64 = r28.s64 + -1;
	// lvx128 v1,r0,r27
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r24,1
	ctx.r4.s64 = r24.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8254bdd8
	ctx.lr = 0x8254C17C;
	sub_8254BDD8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8254c1ec
	if (cr6.eq) goto loc_8254C1EC;
	// lwz r10,30840(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 30840);
	// cmpw cr6,r10,r22
	cr6.compare<int32_t>(ctx.r10.s32, r22.s32, xer);
	// bge cr6,0x8254c1d0
	if (!cr6.lt) goto loc_8254C1D0;
	// lwz r8,23052(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 23052);
	// addi r11,r31,23008
	r11.s64 = r31.s64 + 23008;
	// lwz r9,23044(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 23044);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// srawi r6,r7,3
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 3;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// rlwinm r4,r5,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r3,r4,r7
	ctx.r3.s64 = ctx.r7.s64 - ctx.r4.s64;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// srawi r8,r9,13
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1FFF) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 13;
	// cmpw cr6,r8,r28
	cr6.compare<int32_t>(ctx.r8.s32, r28.s32, xer);
	// beq cr6,0x8254c1fc
	if (cr6.eq) goto loc_8254C1FC;
loc_8254C1D0:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpw cr6,r28,r23
	cr6.compare<int32_t>(r28.s32, r23.s32, xer);
	// blt cr6,0x8254c0c0
	if (cr6.lt) goto loc_8254C0C0;
loc_8254C1DC:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_8254C1EC:
	// addi r3,r28,-1
	ctx.r3.s64 = r28.s64 + -1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_8254C1FC:
	// lwz r8,23052(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 23052);
	// addi r10,r31,23008
	ctx.r10.s64 = r31.s64 + 23008;
	// lwz r9,23044(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 23044);
	// lwz r11,30840(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 30840);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// srawi r6,r7,3
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 3;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// rlwinm r4,r5,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r3,r4,r7
	ctx.r3.s64 = ctx.r7.s64 - ctx.r4.s64;
	// rlwinm r9,r3,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r10,260(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 260);
	// clrlwi r7,r8,31
	ctx.r7.u64 = ctx.r8.u32 & 0x1;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x8254c2e0
	if (cr6.eq) goto loc_8254C2E0;
	// lwz r7,272(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 272);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r6,260(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 260);
	// li r8,12
	ctx.r8.s64 = 12;
	// subf r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// subf r10,r5,r6
	ctx.r10.s64 = ctx.r6.s64 - ctx.r5.s64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// subf r9,r3,r4
	ctx.r9.s64 = ctx.r4.s64 - ctx.r3.s64;
	// srawi r6,r7,3
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 3;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// addze r4,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r4.s64 = temp.s64;
	// srawi r3,r5,3
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7) != 0);
	ctx.r3.s64 = ctx.r5.s32 >> 3;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addze r10,r3
	temp.s64 = ctx.r3.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r10.s64 = temp.s64;
	// srawi r9,r11,3
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7) != 0);
	ctx.r9.s64 = r11.s32 >> 3;
	// rlwinm r6,r4,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// addze r4,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r4.s64 = temp.s64;
	// subf r3,r6,r7
	ctx.r3.s64 = ctx.r7.s64 - ctx.r6.s64;
	// rlwinm r9,r4,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r7,r10,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r6,r9,r11
	ctx.r6.s64 = r11.s64 - ctx.r9.s64;
	// rlwinm r4,r3,5,0,26
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r11,r6,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r3,r7,r5
	ctx.r3.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r10,r11,r29
	ctx.r10.u64 = r11.u64 + r29.u64;
	// rlwinm r11,r3,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// lvx128 v0,r4,r29
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r9,r11,r29
	ctx.r9.u64 = r11.u64 + r29.u64;
	// lvx128 v59,r10,r26
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v59,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v58,r9,r8
	temp.u32 = ctx.r9.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v58,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vmaddfp v2,v13,v12,v0
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// b 0x8254c308
	goto loc_8254C308;
loc_8254C2E0:
	// lwz r9,272(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 272);
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// srawi r7,r8,3
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 3;
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// rlwinm r5,r6,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r4,r5,r8
	ctx.r4.s64 = ctx.r8.s64 - ctx.r5.s64;
	// rlwinm r3,r4,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// lvx128 v2,r3,r29
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8254C308:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lvx128 v1,r0,r27
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r24,1
	ctx.r4.s64 = r24.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8254bdd8
	ctx.lr = 0x8254C31C;
	sub_8254BDD8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8254c338
	if (!cr6.eq) goto loc_8254C338;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_8254C338:
	// addi r3,r28,1
	ctx.r3.s64 = r28.s64 + 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8254C348"))) PPC_WEAK_FUNC(sub_8254C348);
PPC_FUNC_IMPL(__imp__sub_8254C348) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x8254C350;
	// stfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -120, f31.u64);
	// li r12,-176
	r12.s64 = -176;
	// stvx128 v125,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-160
	r12.s64 = -160;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-144
	r12.s64 = -144;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// vor128 v125,v2,v2
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// stvx128 v125,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r19,r5
	r19.u64 = ctx.r5.u64;
	// stvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r27,r26,16
	r27.s64 = r26.s64 + 16;
	// lfs f9,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f9.f64 = double(temp.f32);
	// lwz r10,22560(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 22560);
	// lfs f8,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
	// lwz r11,22552(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 22552);
	// lfs f7,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f6.f64 = double(temp.f32);
	// add r20,r10,r11
	r20.u64 = ctx.r10.u64 + r11.u64;
	// lfs f13,14196(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14196);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,25348(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 25348);
	f0.f64 = double(temp.f32);
	// lfs f11,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// lfs f10,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f11,f11,f10
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// fsubs f12,f7,f6
	ctx.f12.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fsubs f13,f9,f8
	ctx.f13.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// ble cr6,0x8254c410
	if (!cr6.gt) goto loc_8254C410;
	// fmuls f10,f12,f12
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f9,f11,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f10.f64));
	// fmadds f8,f13,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f9.f64));
	// fsqrts f7,f8
	ctx.f7.f64 = double(float(sqrt(ctx.f8.f64)));
	// fdivs f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 / f0.f64));
	// fadds f5,f6,f12
	ctx.f5.f64 = double(float(ctx.f6.f64 + ctx.f12.f64));
	// fctiwz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f4.u64);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// b 0x8254c414
	goto loc_8254C414;
loc_8254C410:
	// li r10,1
	ctx.r10.s64 = 1;
loc_8254C414:
	// lwz r11,26472(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 26472);
	// subfic r9,r11,64
	xer.ca = r11.u32 <= 64;
	ctx.r9.s64 = 64 - r11.s64;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// ble cr6,0x8254c42c
	if (!cr6.gt) goto loc_8254C42C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8254c6b8
	goto loc_8254C6B8;
loc_8254C42C:
	// li r21,0
	r21.s64 = 0;
	// addic. r25,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r25.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// mr r11,r21
	r11.u64 = r21.u64;
	// ble 0x8254c5f4
	if (!cr0.gt) goto loc_8254C5F4;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// vsubfp128 v126,v125,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v126.f32, simde_mm_sub_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v127.f32)));
	// addi r29,r26,30496
	r29.s64 = r26.s64 + 30496;
	// std r10,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// addi r22,r20,-2
	r22.s64 = r20.s64 + -2;
	// frsp f31,f13
	f31.f64 = double(float(ctx.f13.f64));
	// addi r31,r26,26496
	r31.s64 = r26.s64 + 26496;
	// addi r30,r26,25440
	r30.s64 = r26.s64 + 25440;
	// li r24,-1
	r24.s64 = -1;
loc_8254C468:
	// lwz r10,1024(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 1024);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,1024(r30)
	PPC_STORE_U32(r30.u32 + 1024, ctx.r10.u32);
	// cmpwi cr6,r10,64
	cr6.compare<int32_t>(ctx.r10.s32, 64, xer);
	// bne cr6,0x8254c480
	if (!cr6.eq) goto loc_8254C480;
	// stw r21,1024(r30)
	PPC_STORE_U32(r30.u32 + 1024, r21.u32);
loc_8254C480:
	// addi r28,r11,1
	r28.s64 = r11.s64 + 1;
	// vor128 v63,v127,v127
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwz r9,1024(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 1024);
	// extsw r8,r28
	ctx.r8.s64 = r28.s32;
	// lwz r11,1032(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1032);
	// rlwinm r7,r9,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// std r8,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r8.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stw r6,1032(r30)
	PPC_STORE_U32(r30.u32 + 1032, ctx.r6.u32);
	// fdivs f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 / f31.f64));
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v62,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmaddfp128 v63,v126,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v61.f32)), simde_mm_load_ps(v63.f32)));
	// stvx128 v63,r7,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,256(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 256);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,256(r29)
	PPC_STORE_U32(r29.u32 + 256, r11.u32);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// bne cr6,0x8254c4e4
	if (!cr6.eq) goto loc_8254C4E4;
	// stw r21,256(r29)
	PPC_STORE_U32(r29.u32 + 256, r21.u32);
loc_8254C4E4:
	// lwz r10,256(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 256);
	// lwz r11,264(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 264);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,264(r29)
	PPC_STORE_U32(r29.u32 + 264, ctx.r8.u32);
	// stwx r24,r9,r29
	PPC_STORE_U32(ctx.r9.u32 + r29.u32, r24.u32);
	// lwz r9,264(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 264);
	// lwz r6,268(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 268);
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// lwz r7,260(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// subf r10,r6,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r6.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// add r5,r11,r9
	ctx.r5.u64 = r11.u64 + ctx.r9.u64;
	// srawi r4,r5,6
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3F) != 0);
	ctx.r4.s64 = ctx.r5.s32 >> 6;
	// addze r3,r4
	temp.s64 = ctx.r4.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r3.s64 = temp.s64;
	// rlwinm r11,r3,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r10,r11,r5
	ctx.r10.s64 = ctx.r5.s64 - r11.s64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// srawi r11,r8,1
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	r11.s64 = ctx.r8.s32 >> 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r23
	cr6.compare<int32_t>(r11.s32, r23.s32, xer);
	// blt cr6,0x8254c544
	if (cr6.lt) goto loc_8254C544;
	// mr r11,r23
	r11.u64 = r23.u64;
loc_8254C544:
	// cmpw cr6,r11,r22
	cr6.compare<int32_t>(r11.s32, r22.s32, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// blt cr6,0x8254c554
	if (cr6.lt) goto loc_8254C554;
	// stw r22,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r22.u32);
loc_8254C554:
	// lwz r10,1040(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 1040);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,1028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1028);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// lwz r10,1032(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 1032);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// srawi r8,r9,6
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3F) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 6;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// rlwinm r6,r7,6,0,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r5,r6,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r6.s64;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v1,r11,r30
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216d1c8
	ctx.lr = 0x8254C594;
	sub_8216D1C8(ctx, base);
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r11.u32);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// bne cr6,0x8254c5ac
	if (!cr6.eq) goto loc_8254C5AC;
	// stw r21,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r21.u32);
loc_8254C5AC:
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,264(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 264);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r8,264(r31)
	PPC_STORE_U32(r31.u32 + 264, ctx.r8.u32);
	// stwx r7,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r7.u32);
	// lwz r11,1040(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1040);
	// lwz r10,1032(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 1032);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// bl 0x8216f898
	ctx.lr = 0x8254C5E8;
	sub_8216F898(ctx, base);
	// mr r11,r28
	r11.u64 = r28.u64;
	// cmpw cr6,r28,r25
	cr6.compare<int32_t>(r28.s32, r25.s32, xer);
	// blt cr6,0x8254c468
	if (cr6.lt) goto loc_8254C468;
loc_8254C5F4:
	// lwz r11,26464(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 26464);
	// addi r10,r26,25440
	ctx.r10.s64 = r26.s64 + 25440;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,26464(r26)
	PPC_STORE_U32(r26.u32 + 26464, r11.u32);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// bne cr6,0x8254c610
	if (!cr6.eq) goto loc_8254C610;
	// stw r21,1024(r10)
	PPC_STORE_U32(ctx.r10.u32 + 1024, r21.u32);
loc_8254C610:
	// lwz r8,1024(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1024);
	// addi r11,r26,30496
	r11.s64 = r26.s64 + 30496;
	// lwz r9,1032(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1032);
	// rlwinm r7,r8,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// stw r6,1032(r10)
	PPC_STORE_U32(ctx.r10.u32 + 1032, ctx.r6.u32);
	// stvx128 v125,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,30752(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 30752);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,30752(r26)
	PPC_STORE_U32(r26.u32 + 30752, ctx.r10.u32);
	// cmpwi cr6,r10,64
	cr6.compare<int32_t>(ctx.r10.s32, 64, xer);
	// bne cr6,0x8254c644
	if (!cr6.eq) goto loc_8254C644;
	// stw r21,256(r11)
	PPC_STORE_U32(r11.u32 + 256, r21.u32);
loc_8254C644:
	// lwz r9,264(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// addi r10,r26,26496
	ctx.r10.s64 = r26.s64 + 26496;
	// lwz r8,256(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 256);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r6,264(r11)
	PPC_STORE_U32(r11.u32 + 264, ctx.r6.u32);
	// stwx r19,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, r19.u32);
	// lwz r11,26752(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 26752);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,26752(r26)
	PPC_STORE_U32(r26.u32 + 26752, r11.u32);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// bne cr6,0x8254c678
	if (!cr6.eq) goto loc_8254C678;
	// stw r21,256(r10)
	PPC_STORE_U32(ctx.r10.u32 + 256, r21.u32);
loc_8254C678:
	// lwz r11,264(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 264);
	// addi r9,r20,-2
	ctx.r9.s64 = r20.s64 + -2;
	// lwz r8,256(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 256);
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r7,264(r10)
	PPC_STORE_U32(ctx.r10.u32 + 264, ctx.r7.u32);
	// bge cr6,0x8254c6a0
	if (!cr6.lt) goto loc_8254C6A0;
	// mr r9,r21
	ctx.r9.u64 = r21.u64;
	// b 0x8254c6ac
	goto loc_8254C6AC;
loc_8254C6A0:
	// cmpw cr6,r23,r9
	cr6.compare<int32_t>(r23.s32, ctx.r9.s32, xer);
	// bgt cr6,0x8254c6ac
	if (cr6.gt) goto loc_8254C6AC;
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
loc_8254C6AC:
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// li r3,1
	ctx.r3.s64 = 1;
	// stwx r9,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r9.u32);
loc_8254C6B8:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// li r0,-176
	r0.s64 = -176;
	// lvx128 v125,r1,r0
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-160
	r0.s64 = -160;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-144
	r0.s64 = -144;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-120(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_8254C6DC"))) PPC_WEAK_FUNC(sub_8254C6DC);
PPC_FUNC_IMPL(__imp__sub_8254C6DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8254C6E0"))) PPC_WEAK_FUNC(sub_8254C6E0);
PPC_FUNC_IMPL(__imp__sub_8254C6E0) {
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
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8254C6E8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// addi r29,r30,25440
	r29.s64 = r30.s64 + 25440;
	// lwz r9,26480(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 26480);
	// lwz r10,26472(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 26472);
	// lwz r11,30784(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 30784);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8254c720
	if (cr6.lt) goto loc_8254C720;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
loc_8254C720:
	// lwz r9,26764(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 26764);
	// addi r27,r30,25184
	r27.s64 = r30.s64 + 25184;
	// lwz r10,26756(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 26756);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r31,r30,26496
	r31.s64 = r30.s64 + 26496;
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// addi r28,r30,16
	r28.s64 = r30.s64 + 16;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lvx128 v63,r0,r27
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// srawi r6,r7,6
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3F) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 6;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addze r11,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	r11.s64 = temp.s64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r9,r10,r7
	ctx.r9.s64 = ctx.r7.s64 - ctx.r10.s64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// srawi r6,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 1;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x8216d5c0
	ctx.lr = 0x8254C778;
	sub_8216D5C0(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8216db50
	ctx.lr = 0x8254C788;
	sub_8216DB50(ctx, base);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8254c79c
	if (cr6.eq) goto loc_8254C79C;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8254C79C:
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	f0.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f11,8(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// lfs f0,-4728(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4728);
	f0.f64 = double(temp.f32);
	// fmuls f8,f12,f12
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f7,f9,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fcmpu cr6,f7,f0
	cr6.compare(ctx.f7.f64, f0.f64);
	// bgt cr6,0x8254c87c
	if (cr6.gt) goto loc_8254C87C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,25188(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 25188);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f0.f64 = double(temp.f32);
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// blt cr6,0x8254c87c
	if (cr6.lt) goto loc_8254C87C;
	// lwz r9,268(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 268);
	// addi r27,r1,112
	r27.s64 = ctx.r1.s64 + 112;
	// lwz r10,260(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// lwz r11,30784(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 30784);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// lwz r6,1028(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 1028);
	// lwz r3,1040(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 1040);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// subf r9,r3,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r3.s64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// srawi r9,r10,6
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3F) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 6;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addze r9,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r9.s64 = temp.s64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// rlwinm r6,r9,6,0,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r10,r6,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r6.s64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r9,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// srawi r6,r6,1
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 1;
	// srawi r10,r11,6
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3F) != 0);
	ctx.r10.s64 = r11.s32 >> 6;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r10,r9,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v61,r11,r29
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216d7b0
	ctx.lr = 0x8254C868;
	sub_8216D7B0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r3,r9,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
loc_8254C87C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8254C888"))) PPC_WEAK_FUNC(sub_8254C888);
PPC_FUNC_IMPL(__imp__sub_8254C888) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r10,30784(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 30784);
	// addi r11,r3,25440
	r11.s64 = ctx.r3.s64 + 25440;
	// lwz r8,26480(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 26480);
	// lwz r9,26468(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 26468);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// srawi r6,r7,6
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3F) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 6;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// rlwinm r4,r5,6,0,25
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r3,r4,r7
	ctx.r3.s64 = ctx.r7.s64 - ctx.r4.s64;
	// rlwinm r10,r3,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8254C8C0"))) PPC_WEAK_FUNC(sub_8254C8C0);
PPC_FUNC_IMPL(__imp__sub_8254C8C0) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8254C8C8;
	// lwz r9,22560(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 22560);
	// addi r11,r4,16
	r11.s64 = ctx.r4.s64 + 16;
	// lwz r10,22552(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 22552);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// lwz r6,22544(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 22544);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// bne cr6,0x8254ca00
	if (!cr6.eq) goto loc_8254CA00;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r7,22532(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 22532);
	// lwz r31,22544(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 22544);
	// addi r5,r1,-64
	ctx.r5.s64 = ctx.r1.s64 + -64;
	// subf r9,r6,r7
	ctx.r9.s64 = ctx.r7.s64 - ctx.r6.s64;
	// lwz r30,22544(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 22544);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// addi r4,r1,-60
	ctx.r4.s64 = ctx.r1.s64 + -60;
	// lfs f0,-29232(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -29232);
	f0.f64 = double(temp.f32);
	// add r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stfs f0,-64(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// subf r9,r31,r6
	ctx.r9.s64 = ctx.r6.s64 - r31.s64;
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// stfs f0,-60(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stfs f0,-56(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// srawi r31,r8,7
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7F) != 0);
	r31.s64 = ctx.r8.s32 >> 7;
	// stfs f0,-52(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// addi r29,r9,2
	r29.s64 = ctx.r9.s64 + 2;
	// addze r9,r31
	temp.s64 = r31.s64 + xer.ca;
	xer.ca = temp.u32 < r31.u32;
	ctx.r9.s64 = temp.s64;
	// lwz r31,22532(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 22532);
	// srawi r28,r29,7
	xer.ca = (r29.s32 < 0) & ((r29.u32 & 0x7F) != 0);
	r28.s64 = r29.s32 >> 7;
	// rlwinm r9,r9,7,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// addze r28,r28
	temp.s64 = r28.s64 + xer.ca;
	xer.ca = temp.u32 < r28.u32;
	r28.s64 = temp.s64;
	// subf r8,r9,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r9.s64;
	// rotlwi r6,r6,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// mulli r9,r8,176
	ctx.r9.s64 = ctx.r8.s64 * 176;
	// lvx128 v63,r9,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r28,r28,7,0,24
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 7) & 0xFFFFFF80;
	// lvlx128 v62,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// subf r9,r30,r6
	ctx.r9.s64 = ctx.r6.s64 - r30.s64;
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// subf r6,r28,r29
	ctx.r6.s64 = r29.s64 - r28.s64;
	// add r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lvlx128 v60,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// mulli r9,r6,176
	ctx.r9.s64 = ctx.r6.s64 * 176;
	// vspltw128 v0,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vmulfp128 v13,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// addi r5,r8,1
	ctx.r5.s64 = ctx.r8.s64 + 1;
	// mr r27,r30
	r27.u64 = r30.u64;
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + r11.u64;
	// li r7,16
	ctx.r7.s64 = 16;
	// srawi r8,r5,7
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7F) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 7;
	// subf r9,r27,r31
	ctx.r9.s64 = r31.s64 - r27.s64;
	// addze r6,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r6.s64 = temp.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lvx128 v12,r4,r7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r4,r6,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 7) & 0xFFFFFF80;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// vmaddfp v11,v12,v0,v13
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// addi r9,r1,-56
	ctx.r9.s64 = ctx.r1.s64 + -56;
	// subf r8,r4,r5
	ctx.r8.s64 = ctx.r5.s64 - ctx.r4.s64;
	// srawi r6,r10,7
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7F) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 7;
	// mulli r5,r8,176
	ctx.r5.s64 = ctx.r8.s64 * 176;
	// lvlx128 v59,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v10,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// lvx128 v9,r5,r11
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addze r4,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r4.s64 = temp.s64;
	// vmaddfp v8,v9,v10,v11
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// addi r9,r1,-52
	ctx.r9.s64 = ctx.r1.s64 + -52;
	// rlwinm r8,r4,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 7) & 0xFFFFFF80;
	// subf r6,r8,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r8.s64;
	// mulli r10,r6,176
	ctx.r10.s64 = ctx.r6.s64 * 176;
	// lvlx128 v58,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v7,v58,0
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// lvx128 v6,r5,r7
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v5,v6,v7,v8
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// stvx128 v5,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9244
	return;
loc_8254CA00:
	// lwz r9,22532(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 22532);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lwz r4,22532(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 22532);
	// li r7,16
	ctx.r7.s64 = 16;
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// lwz r8,22544(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 22544);
	// addi r6,r5,-31568
	ctx.r6.s64 = ctx.r5.s64 + -31568;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// subf r8,r8,r4
	ctx.r8.s64 = ctx.r4.s64 - ctx.r8.s64;
	// addi r5,r9,2
	ctx.r5.s64 = ctx.r9.s64 + 2;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// srawi r4,r5,7
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7F) != 0);
	ctx.r4.s64 = ctx.r5.s32 >> 7;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// addze r9,r4
	temp.s64 = ctx.r4.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r9.s64 = temp.s64;
	// srawi r8,r10,7
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7F) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 7;
	// rlwinm r6,r9,7,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// addze r4,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r4.s64 = temp.s64;
	// subf r9,r6,r5
	ctx.r9.s64 = ctx.r5.s64 - ctx.r6.s64;
	// rlwinm r8,r4,7,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 7) & 0xFFFFFF80;
	// mulli r6,r9,176
	ctx.r6.s64 = ctx.r9.s64 * 176;
	// lvx128 v57,r6,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// subf r5,r8,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r8.s64;
	// mulli r10,r5,176
	ctx.r10.s64 = ctx.r5.s64 * 176;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// lvx128 v56,r4,r7
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v55,v56,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_add_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v57.f32)));
	// vmulfp128 v54,v55,v63
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v54,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8254CA78"))) PPC_WEAK_FUNC(sub_8254CA78);
PPC_FUNC_IMPL(__imp__sub_8254CA78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,26480(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 26480);
	// lwz r10,26472(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 26472);
	// lwz r9,30784(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 30784);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bge cr6,0x8254ca98
	if (!cr6.lt) goto loc_8254CA98;
	// li r11,0
	r11.s64 = 0;
loc_8254CA98:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8254CAA0"))) PPC_WEAK_FUNC(sub_8254CAA0);
PPC_FUNC_IMPL(__imp__sub_8254CAA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v57{};
	PPCVRegister v58{};
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
	// bl 0x823d91e4
	ctx.lr = 0x8254CAA8;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823db9cc
	ctx.lr = 0x8254CAB0;
	// li r12,-160
	r12.s64 = -160;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// addi r30,r31,25440
	r30.s64 = r31.s64 + 25440;
	// lwz r11,30468(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 30468);
	// lwz r10,30464(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 30464);
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// bgt cr6,0x8254cb00
	if (cr6.gt) goto loc_8254CB00;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,20160(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20160);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r25)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r25.u32 + 0, temp.u32);
	// stfs f13,0(r23)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r23.u32 + 0, temp.u32);
	// b 0x8254cdd4
	goto loc_8254CDD4;
loc_8254CB00:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,25216(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 25216);
	f0.f64 = double(temp.f32);
	// lfs f13,25224(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 25224);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r28,r10,2272
	r28.s64 = ctx.r10.s64 + 2272;
	// mulli r11,r11,56
	r11.s64 = r11.s64 * 56;
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f30,31292(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31292);
	f30.f64 = double(temp.f32);
	// lvx128 v127,r0,r28
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r27,r11,1384
	r27.s64 = r11.s64 + 1384;
	// bl 0x82165300
	ctx.lr = 0x8254CB4C;
	sub_82165300(ctx, base);
	// lfs f12,25232(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 25232);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,25240(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 25240);
	ctx.f11.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r26,r31,25232
	r26.s64 = r31.s64 + 25232;
	// lfs f29,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f29.f64 = double(temp.f32);
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x82165300
	ctx.lr = 0x8254CB7C;
	sub_82165300(ctx, base);
	// lfs f10,25208(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 25208);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,25200(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 25200);
	ctx.f9.f64 = double(temp.f32);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// stfs f10,120(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r29,r31,25200
	r29.s64 = r31.s64 + 25200;
	// stfs f9,112(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x82165300
	ctx.lr = 0x8254CBA4;
	sub_82165300(ctx, base);
	// lfs f8,25236(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 25236);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f8
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// lfs f6,25232(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 25232);
	ctx.f6.f64 = double(temp.f32);
	// fmr f5,f6
	ctx.f5.f64 = ctx.f6.f64;
	// lfs f3,25240(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 25240);
	ctx.f3.f64 = double(temp.f32);
	// lfs f4,25200(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 25200);
	ctx.f4.f64 = double(temp.f32);
	// fmr f0,f3
	f0.f64 = ctx.f3.f64;
	// lfs f1,25208(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 25208);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fmadds f13,f6,f6,f7
	ctx.f13.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f7.f64));
	// fmuls f2,f5,f4
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f4.f64));
	// fmadds f12,f3,f3,f13
	ctx.f12.f64 = double(float(ctx.f3.f64 * ctx.f3.f64 + ctx.f13.f64));
	// fmadds f25,f1,f0,f2
	f25.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f2.f64));
	// fsqrts f27,f12
	f27.f64 = double(float(sqrt(ctx.f12.f64)));
	// bl 0x8254ad68
	ctx.lr = 0x8254CBE4;
	sub_8254AD68(ctx, base);
	// lfs f11,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lfs f10,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f9,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f10,f11
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// fmr f28,f1
	f28.f64 = ctx.f1.f64;
	// fmadds f4,f8,f9,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f26,f6,f7,f4
	f26.f64 = double(float(ctx.f6.f64 * ctx.f7.f64 + ctx.f4.f64));
	// bl 0x8254ad68
	ctx.lr = 0x8254CC18;
	sub_8254AD68(ctx, base);
	// fneg f3,f26
	ctx.fpscr.disableFlushMode();
	ctx.f3.u64 = f26.u64 ^ 0x8000000000000000;
	// lwz r6,25352(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 25352);
	// lwz r5,30468(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 30468);
	// rlwinm r11,r6,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// cmpw cr6,r5,r4
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r4.s32, xer);
	// fsel f2,f3,f31,f26
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? f31.f64 : f26.f64;
	// fmuls f26,f1,f2
	f26.f64 = double(float(ctx.f1.f64 * ctx.f2.f64));
	// bne cr6,0x8254ccb4
	if (!cr6.eq) goto loc_8254CCB4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f27,f0
	cr6.compare(f27.f64, f0.f64);
	// bge cr6,0x8254ccb4
	if (!cr6.lt) goto loc_8254CCB4;
	// lwz r8,1040(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 1040);
	// li r9,25184
	ctx.r9.s64 = 25184;
	// lwz r10,30784(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 30784);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lwz r11,1028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1028);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// lvx128 v1,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lvx128 v63,r31,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// srawi r5,r6,6
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3F) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 6;
	// addze r4,r5
	temp.s64 = ctx.r5.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r4.s64 = temp.s64;
	// rlwinm r11,r4,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r10,r11,r6
	ctx.r10.s64 = ctx.r6.s64 - r11.s64;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v62,r9,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// bl 0x82165300
	ctx.lr = 0x8254CCA4;
	sub_82165300(ctx, base);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8254ad68
	ctx.lr = 0x8254CCB0;
	sub_8254AD68(ctx, base);
	// fadds f28,f1,f28
	ctx.fpscr.disableFlushMode();
	f28.f64 = double(float(ctx.f1.f64 + f28.f64));
loc_8254CCB4:
	// fadds f0,f26,f28
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f26.f64 + f28.f64));
	// lfs f13,36(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,20(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fdivs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 / ctx.f13.f64));
	// fadds f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// stfs f10,0(r25)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r25.u32 + 0, temp.u32);
	// bne cr6,0x8254cd04
	if (!cr6.eq) goto loc_8254CD04;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f11,f10
	ctx.f11.f64 = ctx.f10.f64;
	// lfs f13,25252(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 25252);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,20(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f0.f64 = double(temp.f32);
	// fsubs f10,f0,f27
	ctx.f10.f64 = double(float(f0.f64 - f27.f64));
	// fsel f9,f10,f0,f27
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? f0.f64 : f27.f64;
	// fdivs f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 / ctx.f9.f64));
	// fsubs f7,f12,f8
	ctx.f7.f64 = double(float(ctx.f12.f64 - ctx.f8.f64));
	// fadds f6,f7,f11
	ctx.f6.f64 = double(float(ctx.f7.f64 + ctx.f11.f64));
	// stfs f6,0(r25)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r25.u32 + 0, temp.u32);
loc_8254CD04:
	// lfs f13,36(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// fsubs f12,f29,f13
	ctx.f12.f64 = double(float(f29.f64 - ctx.f13.f64));
	// lfs f11,25280(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 25280);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f11
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// lfs f9,4(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fsel f8,f12,f29,f13
	ctx.f8.f64 = ctx.f12.f64 >= 0.0 ? f29.f64 : ctx.f13.f64;
	// fmsubs f7,f9,f9,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 - ctx.f10.f64));
	// fmuls f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fdivs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 / ctx.f6.f64));
	// stfs f5,0(r23)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r23.u32 + 0, temp.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f1,25280(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 25280);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82549cc8
	ctx.lr = 0x8254CD40;
	sub_82549CC8(ctx, base);
	// fdivs f4,f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = double(float(f29.f64 / ctx.f1.f64));
	// fneg f3,f4
	ctx.f3.u64 = ctx.f4.u64 ^ 0x8000000000000000;
	// lfs f2,20(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 20);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,25288(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 25288);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fsubs f0,f2,f3
	f0.f64 = double(float(ctx.f2.f64 - ctx.f3.f64));
	// fsel f13,f0,f2,f3
	ctx.f13.f64 = f0.f64 >= 0.0 ? ctx.f2.f64 : ctx.f3.f64;
	// fsubs f12,f13,f4
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f4.f64));
	// fsel f11,f12,f4,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f4.f64 : ctx.f13.f64;
	// fmuls f10,f11,f1
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f1.f64));
	// fmuls f1,f10,f25
	ctx.f1.f64 = double(float(ctx.f10.f64 * f25.f64));
	// bl 0x8216c890
	ctx.lr = 0x8254CD70;
	sub_8216C890(ctx, base);
	// lvx128 v60,r0,r29
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// vmsum3fp128 v59,v60,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// addi r8,r10,2528
	ctx.r8.s64 = ctx.r10.s64 + 2528;
	// addi r7,r9,2240
	ctx.r7.s64 = ctx.r9.s64 + 2240;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r4,r6,-31648
	ctx.r4.s64 = ctx.r6.s64 + -31648;
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r5,-31664
	ctx.r3.s64 = ctx.r5.s64 + -31664;
	// lvx128 v0,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// vmulfp128 v8,v63,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v7,v12,v9,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v6,v7,v8,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v57,v60,v6
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v57,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8254CDD4:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// li r0,-160
	r0.s64 = -160;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba18
	ctx.lr = 0x8254CDE8;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8254CDEC"))) PPC_WEAK_FUNC(sub_8254CDEC);
PPC_FUNC_IMPL(__imp__sub_8254CDEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8254CDF0"))) PPC_WEAK_FUNC(sub_8254CDF0);
PPC_FUNC_IMPL(__imp__sub_8254CDF0) {
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
	// li r11,0
	r11.s64 = 0;
	// addi r3,r31,25316
	ctx.r3.s64 = r31.s64 + 25316;
	// stw r11,22536(r31)
	PPC_STORE_U32(r31.u32 + 22536, r11.u32);
	// stw r11,22532(r31)
	PPC_STORE_U32(r31.u32 + 22532, r11.u32);
	// stw r11,22528(r31)
	PPC_STORE_U32(r31.u32 + 22528, r11.u32);
	// stw r11,22544(r31)
	PPC_STORE_U32(r31.u32 + 22544, r11.u32);
	// stw r11,22696(r31)
	PPC_STORE_U32(r31.u32 + 22696, r11.u32);
	// stw r11,22692(r31)
	PPC_STORE_U32(r31.u32 + 22692, r11.u32);
	// stw r11,22688(r31)
	PPC_STORE_U32(r31.u32 + 22688, r11.u32);
	// stw r11,22700(r31)
	PPC_STORE_U32(r31.u32 + 22700, r11.u32);
	// stw r11,22968(r31)
	PPC_STORE_U32(r31.u32 + 22968, r11.u32);
	// stw r11,22964(r31)
	PPC_STORE_U32(r31.u32 + 22964, r11.u32);
	// stw r11,22960(r31)
	PPC_STORE_U32(r31.u32 + 22960, r11.u32);
	// stw r11,22976(r31)
	PPC_STORE_U32(r31.u32 + 22976, r11.u32);
	// stw r11,23032(r31)
	PPC_STORE_U32(r31.u32 + 23032, r11.u32);
	// stw r11,23028(r31)
	PPC_STORE_U32(r31.u32 + 23028, r11.u32);
	// stw r11,23024(r31)
	PPC_STORE_U32(r31.u32 + 23024, r11.u32);
	// stw r11,23036(r31)
	PPC_STORE_U32(r31.u32 + 23036, r11.u32);
	// stw r11,25088(r31)
	PPC_STORE_U32(r31.u32 + 25088, r11.u32);
	// stw r11,25136(r31)
	PPC_STORE_U32(r31.u32 + 25136, r11.u32);
	// bl 0x825498c8
	ctx.lr = 0x8254CE58;
	sub_825498C8(ctx, base);
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

__attribute__((alias("__imp__sub_8254CE70"))) PPC_WEAK_FUNC(sub_8254CE70);
PPC_FUNC_IMPL(__imp__sub_8254CE70) {
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
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// bl 0x8254b768
	ctx.lr = 0x8254CE8C;
	sub_8254B768(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r6,30816
	ctx.r6.s64 = 30816;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// li r11,25184
	r11.s64 = 25184;
	// li r10,25200
	ctx.r10.s64 = 25200;
	// li r9,25216
	ctx.r9.s64 = 25216;
	// lfs f13,3732(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// li r8,25232
	ctx.r8.s64 = 25232;
	// lfs f0,-31384(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -31384);
	f0.f64 = double(temp.f32);
	// lfs f12,27640(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 27640);
	ctx.f12.f64 = double(temp.f32);
	// li r5,25248
	ctx.r5.s64 = 25248;
	// stvx128 v63,r7,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,25264
	ctx.r4.s64 = 25264;
	// stfs f0,25172(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 25172, temp.u32);
	// lis r3,-32131
	ctx.r3.s64 = -2105737216;
	// stfs f12,25176(r7)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r7.u32 + 25176, temp.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stfs f13,25168(r7)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r7.u32 + 25168, temp.u32);
	// lis r31,-32256
	r31.s64 = -2113929216;
	// stvx128 v63,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stvx128 v63,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r30,-32254
	r30.s64 = -2113798144;
	// stvx128 v63,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stvx128 v63,r7,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stvx128 v63,r7,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32248
	ctx.r8.s64 = -2113404928;
	// stvx128 v63,r7,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r3,29952
	ctx.r5.s64 = ctx.r3.s64 + 29952;
	// li r4,30480
	ctx.r4.s64 = 30480;
	// lfs f12,-1684(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1684);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// lfs f11,14192(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14192);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,15004(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 15004);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,-11624(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11624);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,-31128(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31128);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-16720(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -16720);
	ctx.f7.f64 = double(temp.f32);
	// stfs f0,25280(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 25280, temp.u32);
	// stfs f11,25284(r7)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r7.u32 + 25284, temp.u32);
	// stfs f13,25292(r7)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r7.u32 + 25292, temp.u32);
	// stfs f10,25296(r7)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r7.u32 + 25296, temp.u32);
	// stfs f12,25300(r7)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r7.u32 + 25300, temp.u32);
	// stfs f0,25304(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 25304, temp.u32);
	// stfs f13,25308(r7)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r7.u32 + 25308, temp.u32);
	// stfs f9,25312(r7)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r7.u32 + 25312, temp.u32);
	// stfs f12,25316(r7)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r7.u32 + 25316, temp.u32);
	// stfs f0,25320(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 25320, temp.u32);
	// stfs f8,25324(r7)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r7.u32 + 25324, temp.u32);
	// stfs f7,25328(r7)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r7.u32 + 25328, temp.u32);
	// lfs f13,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,25104(r7)
	PPC_STORE_U32(ctx.r7.u32 + 25104, r11.u32);
	// stfs f13,25288(r7)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r7.u32 + 25288, temp.u32);
	// stw r11,25152(r7)
	PPC_STORE_U32(ctx.r7.u32 + 25152, r11.u32);
	// stfs f0,30800(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 30800, temp.u32);
	// stw r11,30796(r7)
	PPC_STORE_U32(ctx.r7.u32 + 30796, r11.u32);
	// stvx128 v63,r7,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,30792(r7)
	PPC_STORE_U32(ctx.r7.u32 + 30792, r11.u32);
	// stw r11,30788(r7)
	PPC_STORE_U32(ctx.r7.u32 + 30788, r11.u32);
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

__attribute__((alias("__imp__sub_8254CFA0"))) PPC_WEAK_FUNC(sub_8254CFA0);
PPC_FUNC_IMPL(__imp__sub_8254CFA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,25264
	r11.s64 = 25264;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r7,r3,16
	ctx.r7.s64 = ctx.r3.s64 + 16;
	// stvx128 v1,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-31380(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31380);
	f0.f64 = double(temp.f32);
	// stfs f0,30768(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 30768, temp.u32);
	// stfs f0,30472(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 30472, temp.u32);
	// stfs f0,30476(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 30476, temp.u32);
	// lwz r10,22560(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 22560);
	// lwz r11,22552(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 22552);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// blt cr6,0x8254d14c
	if (cr6.lt) goto loc_8254D14C;
	// lwz r11,26472(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 26472);
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8254d0a8
	if (!cr6.eq) goto loc_8254D0A8;
	// li r11,25184
	r11.s64 = 25184;
	// addi r9,r3,30480
	ctx.r9.s64 = ctx.r3.s64 + 30480;
	// addi r10,r3,25440
	ctx.r10.s64 = ctx.r3.s64 + 25440;
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,26464(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 26464);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,26464(r3)
	PPC_STORE_U32(ctx.r3.u32 + 26464, r11.u32);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// bne cr6,0x8254d020
	if (!cr6.eq) goto loc_8254D020;
	// stw r6,1024(r10)
	PPC_STORE_U32(ctx.r10.u32 + 1024, ctx.r6.u32);
loc_8254D020:
	// lwz r31,1024(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1024);
	// addi r11,r3,26496
	r11.s64 = ctx.r3.s64 + 26496;
	// lwz r8,1032(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1032);
	// rlwinm r31,r31,4,0,27
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stw r8,1032(r10)
	PPC_STORE_U32(ctx.r10.u32 + 1032, ctx.r8.u32);
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,26752(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 26752);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,26752(r3)
	PPC_STORE_U32(ctx.r3.u32 + 26752, ctx.r10.u32);
	// cmpwi cr6,r10,64
	cr6.compare<int32_t>(ctx.r10.s32, 64, xer);
	// bne cr6,0x8254d058
	if (!cr6.eq) goto loc_8254D058;
	// stw r6,256(r11)
	PPC_STORE_U32(r11.u32 + 256, ctx.r6.u32);
loc_8254D058:
	// lwz r9,264(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// addi r10,r3,30496
	ctx.r10.s64 = ctx.r3.s64 + 30496;
	// lwz r8,256(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 256);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r9,264(r11)
	PPC_STORE_U32(r11.u32 + 264, ctx.r9.u32);
	// stwx r6,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r6.u32);
	// lwz r11,30752(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 30752);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,30752(r3)
	PPC_STORE_U32(ctx.r3.u32 + 30752, r11.u32);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// bne cr6,0x8254d08c
	if (!cr6.eq) goto loc_8254D08C;
	// stw r6,256(r10)
	PPC_STORE_U32(ctx.r10.u32 + 256, ctx.r6.u32);
loc_8254D08C:
	// lwz r9,256(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 256);
	// li r8,-1
	ctx.r8.s64 = -1;
	// lwz r11,264(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 264);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,264(r10)
	PPC_STORE_U32(ctx.r10.u32 + 264, r11.u32);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8254D0A8:
	// lwz r10,22976(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 22976);
	// addi r11,r3,22720
	r11.s64 = ctx.r3.s64 + 22720;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,22976(r3)
	PPC_STORE_U32(ctx.r3.u32 + 22976, ctx.r10.u32);
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// bne cr6,0x8254d0c4
	if (!cr6.eq) goto loc_8254D0C4;
	// stw r6,256(r11)
	PPC_STORE_U32(r11.u32 + 256, ctx.r6.u32);
loc_8254D0C4:
	// lwz r10,256(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 256);
	// li r8,16
	ctx.r8.s64 = 16;
	// lwz r9,264(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stw r9,264(r11)
	PPC_STORE_U32(r11.u32 + 264, ctx.r9.u32);
	// lvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r3,23008
	r11.s64 = ctx.r3.s64 + 23008;
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r4,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f1,28(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 28, temp.u32);
	// lwz r10,23040(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23040);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,23040(r3)
	PPC_STORE_U32(ctx.r3.u32 + 23040, ctx.r10.u32);
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// bne cr6,0x8254d110
	if (!cr6.eq) goto loc_8254D110;
	// stw r6,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r6.u32);
loc_8254D110:
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// lwz r9,32(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r8,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r8.u32);
	// lwz r6,0(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// stwx r6,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r6.u32);
	// lwz r8,22536(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 22536);
	// lwz r9,22544(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 22544);
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// rlwinm r9,r5,13,0,18
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 13) & 0xFFFFE000;
	// addi r4,r9,-8193
	ctx.r4.s64 = ctx.r9.s64 + -8193;
	// rlwimi r4,r6,0,19,31
	ctx.r4.u64 = (__builtin_rotateleft32(ctx.r6.u32, 0) & 0x1FFF) | (ctx.r4.u64 & 0xFFFFFFFFFFFFE000);
	// stwx r4,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r4.u32);
	// bl 0x8254b8b8
	ctx.lr = 0x8254D14C;
	sub_8254B8B8(ctx, base);
loc_8254D14C:
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

__attribute__((alias("__imp__sub_8254D160"))) PPC_WEAK_FUNC(sub_8254D160);
PPC_FUNC_IMPL(__imp__sub_8254D160) {
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
	PPCRegister f0{};
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
	// bl 0x823d91f0
	ctx.lr = 0x8254D168;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r28,r31,16
	r28.s64 = r31.s64 + 16;
	// addi r30,r31,22720
	r30.s64 = r31.s64 + 22720;
	// lwz r10,22560(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 22560);
	// lwz r11,22552(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 22552);
	// lwz r8,22992(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 22992);
	// lwz r9,22984(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 22984);
	// add r26,r10,r11
	r26.u64 = ctx.r10.u64 + r11.u64;
	// add r27,r8,r9
	r27.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmpwi cr6,r26,2
	cr6.compare<int32_t>(r26.s32, 2, xer);
	// blt cr6,0x8254d568
	if (cr6.lt) goto loc_8254D568;
	// lwz r11,26472(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 26472);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// beq cr6,0x8254d568
	if (cr6.eq) goto loc_8254D568;
	// lwz r11,30836(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 30836);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8254d1b8
	if (!cr6.eq) goto loc_8254D1B8;
	// bl 0x8254bf98
	ctx.lr = 0x8254D1B4;
	sub_8254BF98(ctx, base);
	// stw r3,30836(r31)
	PPC_STORE_U32(r31.u32 + 30836, ctx.r3.u32);
loc_8254D1B8:
	// lwz r10,30836(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 30836);
	// lwz r29,30840(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 30840);
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// bge cr6,0x8254d23c
	if (!cr6.lt) goto loc_8254D23C;
	// lwz r8,23052(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 23052);
	// addi r11,r31,23008
	r11.s64 = r31.s64 + 23008;
	// lwz r9,23044(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 23044);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + r29.u64;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// srawi r6,r7,3
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 3;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// rlwinm r3,r5,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r9,r3,r7
	ctx.r9.s64 = ctx.r7.s64 - ctx.r3.s64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// srawi r6,r7,13
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1FFF) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 13;
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// ble cr6,0x8254d23c
	if (!cr6.gt) goto loc_8254D23C;
	// lwz r8,44(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + r29.u64;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// srawi r6,r7,3
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 3;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// rlwinm r4,r5,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r3,r4,r7
	ctx.r3.s64 = ctx.r7.s64 - ctx.r4.s64;
	// rlwinm r9,r3,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// srawi r4,r8,13
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1FFF) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 13;
	// b 0x8254d240
	goto loc_8254D240;
loc_8254D23C:
	// li r29,-1
	r29.s64 = -1;
loc_8254D240:
	// cmpw cr6,r4,r26
	cr6.compare<int32_t>(ctx.r4.s32, r26.s32, xer);
	// bge cr6,0x8254d568
	if (!cr6.lt) goto loc_8254D568;
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// bne cr6,0x8254d2cc
	if (!cr6.eq) goto loc_8254D2CC;
	// lwz r11,22532(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 22532);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lwz r7,22544(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 22544);
	// li r8,16
	ctx.r8.s64 = 16;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// subf r11,r7,r11
	r11.s64 = r11.s64 - ctx.r7.s64;
	// addi r6,r6,-31568
	ctx.r6.s64 = ctx.r6.s64 + -31568;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// subf r11,r7,r5
	r11.s64 = ctx.r5.s64 - ctx.r7.s64;
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// srawi r10,r5,7
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7F) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 7;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// addze r7,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r7.s64 = temp.s64;
	// srawi r6,r9,7
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7F) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 7;
	// rlwinm r11,r7,7,0,24
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 7) & 0xFFFFFF80;
	// addze r10,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r10.s64 = temp.s64;
	// subf r7,r11,r5
	ctx.r7.s64 = ctx.r5.s64 - r11.s64;
	// rlwinm r6,r10,7,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// mulli r5,r7,176
	ctx.r5.s64 = ctx.r7.s64 * 176;
	// lvx128 v62,r5,r28
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// subf r11,r6,r9
	r11.s64 = ctx.r9.s64 - ctx.r6.s64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mulli r11,r11,176
	r11.s64 = r11.s64 * 176;
	// add r10,r11,r28
	ctx.r10.u64 = r11.u64 + r28.u64;
	// lvx128 v61,r10,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v60,v61,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// vmulfp128 v2,v60,v63
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v2,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8254d3e4
	goto loc_8254D3E4;
loc_8254D2CC:
	// lwz r9,23052(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 23052);
	// addi r11,r31,23008
	r11.s64 = r31.s64 + 23008;
	// lwz r10,23044(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 23044);
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// srawi r7,r8,3
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 3;
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// rlwinm r5,r6,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r3,r5,r8
	ctx.r3.s64 = ctx.r8.s64 - ctx.r5.s64;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r11,260(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 260);
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x8254d3b4
	if (cr6.eq) goto loc_8254D3B4;
	// lwz r8,272(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 272);
	// rotlwi r6,r11,0
	ctx.r6.u64 = __builtin_rotateleft32(r11.u32, 0);
	// li r9,16
	ctx.r9.s64 = 16;
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// lwz r8,260(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 260);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// subf r10,r3,r6
	ctx.r10.s64 = ctx.r6.s64 - ctx.r3.s64;
	// rotlwi r28,r3,0
	r28.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// add r11,r10,r29
	r11.u64 = ctx.r10.u64 + r29.u64;
	// subf r10,r28,r8
	ctx.r10.s64 = ctx.r8.s64 - r28.s64;
	// srawi r3,r6,3
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7) != 0);
	ctx.r3.s64 = ctx.r6.s32 >> 3;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// add r11,r10,r29
	r11.u64 = ctx.r10.u64 + r29.u64;
	// addze r3,r3
	temp.s64 = ctx.r3.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r3.s64 = temp.s64;
	// srawi r10,r8,3
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r8.s32 >> 3;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// srawi r28,r11,3
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7) != 0);
	r28.s64 = r11.s32 >> 3;
	// rlwinm r3,r3,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addze r28,r28
	temp.s64 = r28.s64 + xer.ca;
	xer.ca = temp.u32 < r28.u32;
	r28.s64 = temp.s64;
	// subf r6,r3,r6
	ctx.r6.s64 = ctx.r6.s64 - ctx.r3.s64;
	// rlwinm r3,r28,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r3,r3,r11
	ctx.r3.s64 = r11.s64 - ctx.r3.s64;
	// rlwinm r6,r6,5,0,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r11,r3,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r3,r10,r8
	ctx.r3.s64 = ctx.r8.s64 - ctx.r10.s64;
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// rlwinm r11,r3,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// lvx128 v0,r6,r30
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,12
	ctx.r7.s64 = 12;
	// add r8,r11,r30
	ctx.r8.u64 = r11.u64 + r30.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lvx128 v59,r10,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v59,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v58,r8,r7
	temp.u32 = ctx.r8.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v58,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vmaddfp v2,v13,v12,v0
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v2,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8254d3e4
	goto loc_8254D3E4;
loc_8254D3B4:
	// lwz r9,272(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 272);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// srawi r7,r8,3
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 3;
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// rlwinm r5,r6,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r3,r5,r8
	ctx.r3.s64 = ctx.r8.s64 - ctx.r5.s64;
	// rlwinm r11,r3,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// lvx128 v2,r11,r30
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v2,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8254D3E4:
	// lwz r10,26480(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 26480);
	// addi r11,r31,25440
	r11.s64 = r31.s64 + 25440;
	// lwz r9,26472(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 26472);
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// lwz r8,26468(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 26468);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r6,30756(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 30756);
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// lwz r5,30764(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 30764);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// subf r9,r5,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r5.s64;
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r3,r8,1
	ctx.r3.s64 = ctx.r8.s64 + 1;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// srawi r6,r3,6
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3F) != 0);
	ctx.r6.s64 = ctx.r3.s32 >> 6;
	// addi r8,r31,30496
	ctx.r8.s64 = r31.s64 + 30496;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// srawi r9,r7,6
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3F) != 0);
	ctx.r9.s64 = ctx.r7.s32 >> 6;
	// rlwinm r6,r5,6,0,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
	// addze r5,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r5.s64 = temp.s64;
	// subf r3,r6,r3
	ctx.r3.s64 = ctx.r3.s64 - ctx.r6.s64;
	// rlwinm r6,r5,6,0,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
	// rlwinm r9,r3,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r5,r6,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r6.s64;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// rlwinm r7,r5,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f12,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f13,f6,f6,f4
	ctx.f13.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// beq cr6,0x8254d520
	if (cr6.eq) goto loc_8254D520;
	// lwzx r9,r7,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// bne cr6,0x8254d520
	if (!cr6.eq) goto loc_8254D520;
	// lwz r9,30784(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 30784);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x8254d520
	if (cr6.lt) goto loc_8254D520;
	// lwz r6,23052(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 23052);
	// addi r10,r31,23008
	ctx.r10.s64 = r31.s64 + 23008;
	// lwz r9,23044(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 23044);
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + r29.u64;
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// srawi r3,r5,3
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7) != 0);
	ctx.r3.s64 = ctx.r5.s32 >> 3;
	// addze r9,r3
	temp.s64 = ctx.r3.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r6,r9,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// rlwinm r3,r5,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r3,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r10.u32);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8254d520
	if (!cr6.eq) goto loc_8254D520;
	// lwz r9,272(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 272);
	// lwz r10,260(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 260);
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// srawi r5,r6,3
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 3;
	// addze r3,r5
	temp.s64 = ctx.r5.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r3.s64 = temp.s64;
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r9,r10,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r10.s64;
	// rlwinm r10,r9,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// add r6,r10,r30
	ctx.r6.u64 = ctx.r10.u64 + r30.u64;
	// lfs f0,12(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bge cr6,0x8254d520
	if (!cr6.lt) goto loc_8254D520;
	// stwx r29,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, r29.u32);
	// b 0x8254d54c
	goto loc_8254D54C;
loc_8254D520:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f0,-31408(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31408);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8254d54c
	if (!cr6.gt) goto loc_8254D54C;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8254c348
	ctx.lr = 0x8254D540;
	sub_8254C348(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8254d568
	if (cr6.eq) goto loc_8254D568;
loc_8254D54C:
	// cmpwi cr6,r29,-1
	cr6.compare<int32_t>(r29.s32, -1, xer);
	// beq cr6,0x8254d560
	if (cr6.eq) goto loc_8254D560;
	// lwz r11,30840(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 30840);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,30840(r31)
	PPC_STORE_U32(r31.u32 + 30840, r11.u32);
loc_8254D560:
	// li r11,0
	r11.s64 = 0;
	// stw r11,30836(r31)
	PPC_STORE_U32(r31.u32 + 30836, r11.u32);
loc_8254D568:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8254D570"))) PPC_WEAK_FUNC(sub_8254D570);
PPC_FUNC_IMPL(__imp__sub_8254D570) {
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
	// bl 0x823d91ec
	ctx.lr = 0x8254D578;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r9,48
	ctx.r9.s64 = 48;
	// addi r29,r30,25184
	r29.s64 = r30.s64 + 25184;
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r10,r30,25216
	ctx.r10.s64 = r30.s64 + 25216;
	// addi r11,r30,25232
	r11.s64 = r30.s64 + 25232;
	// lvx128 v62,r4,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,25248
	ctx.r6.s64 = 25248;
	// lvx128 v61,r4,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v60,v63,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32131
	ctx.r5.s64 = -2105737216;
	// stvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,30816
	ctx.r3.s64 = 30816;
	// stvx128 v2,r30,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r5,29952
	ctx.r9.s64 = ctx.r5.s64 + 29952;
	// stvx128 v1,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,25220(r30)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 25220);
	f0.f64 = double(temp.f32);
	// addi r27,r30,25200
	r27.s64 = r30.s64 + 25200;
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,25216(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 25216);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,25224(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 25224);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f9.f64));
	// fmadds f7,f0,f13,f8
	ctx.f7.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f8.f64));
	// lfs f13,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f6,f11,f12,f7
	ctx.f6.f64 = double(float(ctx.f11.f64 * ctx.f12.f64 + ctx.f7.f64));
	// stfs f6,25280(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r30.u32 + 25280, temp.u32);
	// lfs f0,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfs f0,25288(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 25288, temp.u32);
	// stfs f1,25304(r30)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 25304, temp.u32);
	// stfs f2,25320(r30)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r30.u32 + 25320, temp.u32);
	// stfs f3,25284(r30)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r30.u32 + 25284, temp.u32);
	// lvx128 v59,r0,r4
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r30,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,25208(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 25208);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,25240(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 25240);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,25200(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 25200);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,25232(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 25232);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,25204(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 25204);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,25236(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 25236);
	f0.f64 = double(temp.f32);
	// fmuls f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fmadds f11,f5,f4,f12
	ctx.f11.f64 = double(float(ctx.f5.f64 * ctx.f4.f64 + ctx.f12.f64));
	// fmadds f10,f3,f2,f11
	ctx.f10.f64 = double(float(ctx.f3.f64 * ctx.f2.f64 + ctx.f11.f64));
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// blt cr6,0x8254d670
	if (cr6.lt) goto loc_8254D670;
	// lfs f0,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,-11624(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -11624);
	f0.f64 = double(temp.f32);
	// fmadds f10,f12,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmadds f9,f11,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f10.f64));
	// fcmpu cr6,f9,f0
	cr6.compare(ctx.f9.f64, f0.f64);
	// bge cr6,0x8254d678
	if (!cr6.lt) goto loc_8254D678;
loc_8254D670:
	// lvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8254D678:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8254d160
	ctx.lr = 0x8254D680;
	sub_8254D160(ctx, base);
	// lwz r10,26480(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 26480);
	// lwz r11,26472(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 26472);
	// addi r31,r30,25440
	r31.s64 = r30.s64 + 25440;
	// add r26,r10,r11
	r26.u64 = ctx.r10.u64 + r11.u64;
	// cmpwi cr6,r26,2
	cr6.compare<int32_t>(r26.s32, 2, xer);
	// blt cr6,0x8254dcc4
	if (cr6.lt) goto loc_8254DCC4;
	// lwz r11,30784(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 30784);
	// li r25,0
	r25.s64 = 0;
	// cmpw cr6,r11,r26
	cr6.compare<int32_t>(r11.s32, r26.s32, xer);
	// bge cr6,0x8254d8dc
	if (!cr6.lt) goto loc_8254D8DC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r5,r26,-1
	ctx.r5.s64 = r26.s64 + -1;
	// addi r7,r30,30480
	ctx.r7.s64 = r30.s64 + 30480;
	// lfs f10,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f10.f64 = double(temp.f32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// lfs f8,-13148(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13148);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,17032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	ctx.f9.f64 = double(temp.f32);
loc_8254D6CC:
	// lwz r9,1040(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// lvx128 v57,r0,r7
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,1028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// lvx128 v56,r0,r29
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,30784(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 30784);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lwz r4,1028(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// subf r11,r3,r4
	r11.s64 = ctx.r4.s64 - ctx.r3.s64;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// srawi r4,r9,6
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3F) != 0);
	ctx.r4.s64 = ctx.r9.s32 >> 6;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// addze r11,r4
	temp.s64 = ctx.r4.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r4.u32;
	r11.s64 = temp.s64;
	// srawi r4,r3,6
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3F) != 0);
	ctx.r4.s64 = ctx.r3.s32 >> 6;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// addze r4,r4
	temp.s64 = ctx.r4.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r4.s64 = temp.s64;
	// subf r11,r11,r9
	r11.s64 = ctx.r9.s64 - r11.s64;
	// rlwinm r9,r4,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// rlwinm r4,r11,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r3,r9,r3
	ctx.r3.s64 = ctx.r3.s64 - ctx.r9.s64;
	// addi r28,r1,112
	r28.s64 = ctx.r1.s64 + 112;
	// rlwinm r11,r3,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// cmpw cr6,r10,r5
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, xer);
	// lvx128 v55,r4,r31
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v54,v55,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v57.f32)));
	// lvx128 v53,r11,r31
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v52,v53,v56
	simde_mm_store_ps(v52.f32, simde_mm_sub_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v56.f32)));
	// stvx128 v54,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x8254d758
	if (!cr6.eq) goto loc_8254D758;
	// fmr f11,f9
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.f64 = ctx.f9.f64;
	// b 0x8254d75c
	goto loc_8254D75C;
loc_8254D758:
	// fmr f11,f8
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = ctx.f8.f64;
loc_8254D75C:
	// lfs f13,8(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// fmuls f7,f0,f13
	ctx.f7.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lfs f6,4(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// lfs f5,0(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f13,f6,f7
	ctx.f4.f64 = double(float(ctx.f13.f64 * ctx.f6.f64 + ctx.f7.f64));
	// fmadds f3,f5,f12,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f12.f64 + ctx.f4.f64));
	// fcmpu cr6,f3,f10
	cr6.compare(ctx.f3.f64, ctx.f10.f64);
	// blt cr6,0x8254d8dc
	if (cr6.lt) goto loc_8254D8DC;
	// fmuls f7,f13,f13
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f6,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f6,f13
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// lfs f4,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f3.f64 = double(temp.f32);
	// fmadds f2,f12,f12,f7
	ctx.f2.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f7.f64));
	// fmadds f1,f4,f12,f5
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f12.f64 + ctx.f5.f64));
	// fmadds f13,f0,f0,f2
	ctx.f13.f64 = double(float(f0.f64 * f0.f64 + ctx.f2.f64));
	// fmadds f12,f3,f0,f1
	ctx.f12.f64 = double(float(ctx.f3.f64 * f0.f64 + ctx.f1.f64));
	// fmuls f11,f13,f11
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bgt cr6,0x8254d8dc
	if (cr6.gt) goto loc_8254D8DC;
	// lwz r8,1040(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// addi r11,r30,30496
	r11.s64 = r30.s64 + 30496;
	// lwz r9,1028(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// srawi r3,r4,6
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3F) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 6;
	// addze r10,r3
	temp.s64 = ctx.r3.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r9,r10,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r8,r9,r4
	ctx.r8.s64 = ctx.r4.s64 - ctx.r9.s64;
	// rlwinm r4,r8,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v51,r4,r31
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,30784(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 30784);
	// lwz r3,30756(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 30756);
	// lwz r9,30764(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 30764);
	// subf r9,r9,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r9.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// srawi r4,r8,6
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3F) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 6;
	// addze r3,r4
	temp.s64 = ctx.r4.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r3.s64 = temp.s64;
	// rlwinm r10,r3,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r9,r10,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r10.s64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r6,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r6.u32);
	// lwz r9,1040(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// lwz r10,1028(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,1028(r31)
	PPC_STORE_U32(r31.u32 + 1028, ctx.r10.u32);
	// cmpwi cr6,r10,64
	cr6.compare<int32_t>(ctx.r10.s32, 64, xer);
	// lwz r10,1032(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1032);
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// addi r3,r10,-1
	ctx.r3.s64 = ctx.r10.s64 + -1;
	// stw r4,1040(r31)
	PPC_STORE_U32(r31.u32 + 1040, ctx.r4.u32);
	// stw r3,1032(r31)
	PPC_STORE_U32(r31.u32 + 1032, ctx.r3.u32);
	// bne cr6,0x8254d84c
	if (!cr6.eq) goto loc_8254D84C;
	// stw r25,1028(r31)
	PPC_STORE_U32(r31.u32 + 1028, r25.u32);
loc_8254D84C:
	// lwz r9,26764(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 26764);
	// addi r10,r30,26496
	ctx.r10.s64 = r30.s64 + 26496;
	// lwz r8,26760(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 26760);
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// lwz r9,26756(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 26756);
	// addi r3,r8,-1
	ctx.r3.s64 = ctx.r8.s64 + -1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r4,26764(r30)
	PPC_STORE_U32(r30.u32 + 26764, ctx.r4.u32);
	// stw r3,26760(r30)
	PPC_STORE_U32(r30.u32 + 26760, ctx.r3.u32);
	// stw r9,26756(r30)
	PPC_STORE_U32(r30.u32 + 26756, ctx.r9.u32);
	// cmpwi cr6,r9,64
	cr6.compare<int32_t>(ctx.r9.s32, 64, xer);
	// bne cr6,0x8254d880
	if (!cr6.eq) goto loc_8254D880;
	// stw r25,260(r10)
	PPC_STORE_U32(ctx.r10.u32 + 260, r25.u32);
loc_8254D880:
	// lwz r10,268(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 268);
	// lwz r9,264(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// addi r4,r9,-1
	ctx.r4.s64 = ctx.r9.s64 + -1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r8,268(r11)
	PPC_STORE_U32(r11.u32 + 268, ctx.r8.u32);
	// stw r4,264(r11)
	PPC_STORE_U32(r11.u32 + 264, ctx.r4.u32);
	// stw r10,260(r11)
	PPC_STORE_U32(r11.u32 + 260, ctx.r10.u32);
	// cmpwi cr6,r10,64
	cr6.compare<int32_t>(ctx.r10.s32, 64, xer);
	// bne cr6,0x8254d8b0
	if (!cr6.eq) goto loc_8254D8B0;
	// stw r25,260(r11)
	PPC_STORE_U32(r11.u32 + 260, r25.u32);
loc_8254D8B0:
	// lwz r11,30784(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 30784);
	// lwz r10,30772(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 30772);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bgt cr6,0x8254d8c8
	if (cr6.gt) goto loc_8254D8C8;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8254D8C8:
	// stw r11,30784(r30)
	PPC_STORE_U32(r30.u32 + 30784, r11.u32);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r10,30772(r30)
	PPC_STORE_U32(r30.u32 + 30772, ctx.r10.u32);
	// cmpw cr6,r11,r26
	cr6.compare<int32_t>(r11.s32, r26.s32, xer);
	// blt cr6,0x8254d6cc
	if (cr6.lt) goto loc_8254D6CC;
loc_8254D8DC:
	// lwz r10,30784(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 30784);
	// cmpw cr6,r10,r26
	cr6.compare<int32_t>(ctx.r10.s32, r26.s32, xer);
	// bge cr6,0x8254dcc4
	if (!cr6.lt) goto loc_8254DCC4;
	// lbz r11,25336(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 25336);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8254d8f8
	if (cr6.eq) goto loc_8254D8F8;
	// stw r10,30772(r30)
	PPC_STORE_U32(r30.u32 + 30772, ctx.r10.u32);
loc_8254D8F8:
	// lwz r9,1040(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// lvx128 v50,r0,r29
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,1028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// addi r29,r30,26496
	r29.s64 = r30.s64 + 26496;
	// addi r28,r30,16
	r28.s64 = r30.s64 + 16;
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// srawi r7,r8,6
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3F) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 6;
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// rlwinm r5,r6,6,0,25
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r11,r5,r8
	r11.s64 = ctx.r8.s64 - ctx.r5.s64;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// stvx128 v50,r10,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,30784(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 30784);
	// lwz r9,1028(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// lwz r8,1040(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// lwz r7,26764(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 26764);
	// lwz r6,26756(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 26756);
	// subf r10,r7,r6
	ctx.r10.s64 = ctx.r6.s64 - ctx.r7.s64;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// subf r10,r8,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r8.s64;
	// srawi r9,r5,6
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3F) != 0);
	ctx.r9.s64 = ctx.r5.s32 >> 6;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// addze r7,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r7.s64 = temp.s64;
	// rlwinm r6,r7,6,0,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r29
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// srawi r9,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 1;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// srawi r7,r8,6
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3F) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 6;
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// rlwinm r5,r6,6,0,25
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r11,r5,r8
	r11.s64 = ctx.r8.s64 - ctx.r5.s64;
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v1,r10,r31
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216d1c8
	ctx.lr = 0x8254D994;
	sub_8216D1C8(ctx, base);
	// lwz r9,26756(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 26756);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r8,26764(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 26764);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r11,30784(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 30784);
	// subf r10,r8,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r8.s64;
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// srawi r5,r6,6
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3F) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 6;
	// addze r11,r5
	temp.s64 = ctx.r5.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r5.u32;
	r11.s64 = temp.s64;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r9,r10,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r10.s64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r11,r29
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// rlwimi r8,r7,1,0,30
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 1) & 0xFFFFFFFE) | (ctx.r8.u64 & 0xFFFFFFFF00000001);
	// stwx r8,r11,r29
	PPC_STORE_U32(r11.u32 + r29.u32, ctx.r8.u32);
	// lwz r11,30784(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 30784);
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// bl 0x8216f898
	ctx.lr = 0x8254D9E0;
	sub_8216F898(ctx, base);
	// lwz r7,26756(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 26756);
	// lwz r6,26764(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 26764);
	// lwz r11,30784(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 30784);
	// subf r10,r6,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r6.s64;
	// lwz r5,22560(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 22560);
	// lwz r9,22548(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 22548);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// srawi r3,r4,6
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3F) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 6;
	// addze r10,r3
	temp.s64 = ctx.r3.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r8,r10,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r7,r8,r4
	ctx.r7.s64 = ctx.r4.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r6,r29
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + r29.u32);
	// srawi r3,r4,1
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 1;
	// subf r10,r5,r3
	ctx.r10.s64 = ctx.r3.s64 - ctx.r5.s64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// srawi r9,r10,7
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7F) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 7;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// rlwinm r7,r8,7,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 7) & 0xFFFFFF80;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// mulli r10,r6,176
	ctx.r10.s64 = ctx.r6.s64 * 176;
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + r28.u64;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// lfs f0,14884(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8254da90
	if (!cr6.gt) goto loc_8254DA90;
	// lvx128 v49,r0,r10
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r0,r27
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v47,v49,135
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0x78));
	// vpermwi128 v46,v48,99
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0x9C));
	// vpermwi128 v0,v48,135
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0x78));
	// vpermwi128 v13,v49,99
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0x9C));
	// vpermwi128 v45,v49,99
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0x9C));
	// vmulfp128 v12,v47,v46
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v46.f32)));
	// vpermwi128 v11,v49,135
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0x78));
	// vnmsubfp v10,v13,v0,v12
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vpermwi128 v44,v10,135
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v10.u32), 0x78));
	// vpermwi128 v9,v10,99
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v10.u32), 0x9C));
	// vmulfp128 v8,v44,v45
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v45.f32)));
	// vnmsubfp v7,v9,v11,v8
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v8.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v7,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8254DA90:
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// lwz r6,30832(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 30832);
	// lwz r4,30840(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 30840);
	// cmpw cr6,r10,r26
	cr6.compare<int32_t>(ctx.r10.s32, r26.s32, xer);
	// bge cr6,0x8254dbc8
	if (!cr6.lt) goto loc_8254DBC8;
	// lwz r9,260(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 260);
	// addi r11,r30,30496
	r11.s64 = r30.s64 + 30496;
	// lwz r8,268(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 268);
	// subf r5,r8,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r8.s64;
loc_8254DAB4:
	// add r9,r5,r10
	ctx.r9.u64 = ctx.r5.u64 + ctx.r10.u64;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// srawi r8,r9,6
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3F) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 6;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// rlwinm r3,r7,6,0,25
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r9,r3,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r3.s64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r29
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r29.u32);
	// srawi r9,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r7.s32 >> 1;
	// cmpw cr6,r6,r9
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r9.s32, xer);
	// blt cr6,0x8254dae4
	if (cr6.lt) goto loc_8254DAE4;
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
loc_8254DAE4:
	// lwz r8,268(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 268);
	// lwz r9,260(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// srawi r3,r7,6
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3F) != 0);
	ctx.r3.s64 = ctx.r7.s32 >> 6;
	// addze r9,r3
	temp.s64 = ctx.r3.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r7,r8,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r8.s64;
	// rlwinm r3,r7,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r3,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + r11.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt cr6,0x8254dbbc
	if (cr6.lt) goto loc_8254DBBC;
	// lwz r8,268(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 268);
	// lwz r9,260(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// srawi r3,r7,6
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3F) != 0);
	ctx.r3.s64 = ctx.r7.s32 >> 6;
	// addze r9,r3
	temp.s64 = ctx.r3.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r7,r8,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r8.s64;
	// rlwinm r3,r7,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r3,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + r11.u32);
	// cmpw cr6,r4,r9
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r9.s32, xer);
	// blt cr6,0x8254db50
	if (cr6.lt) goto loc_8254DB50;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
loc_8254DB50:
	// lwz r7,268(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 268);
	// addi r9,r30,23008
	ctx.r9.s64 = r30.s64 + 23008;
	// lwz r8,260(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// lwz r3,23052(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 23052);
	// subf r8,r7,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r7.s64;
	// lwz r7,23044(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 23044);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// srawi r31,r8,6
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3F) != 0);
	r31.s64 = ctx.r8.s32 >> 6;
	// addze r31,r31
	temp.s64 = r31.s64 + xer.ca;
	xer.ca = temp.u32 < r31.u32;
	r31.s64 = temp.s64;
	// rlwinm r31,r31,6,0,25
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r8,r31,r8
	ctx.r8.s64 = ctx.r8.s64 - r31.s64;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r8,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// subf r8,r3,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r3.s64;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// addi r7,r8,1
	ctx.r7.s64 = ctx.r8.s64 + 1;
	// srawi r3,r7,3
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r3.s64 = ctx.r7.s32 >> 3;
	// addze r8,r3
	temp.s64 = ctx.r3.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r8.s64 = temp.s64;
	// rlwinm r3,r8,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r8,r3,r7
	ctx.r8.s64 = ctx.r7.s64 - ctx.r3.s64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r7,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// srawi r9,r3,13
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1FFF) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 13;
	// cmpw cr6,r6,r9
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r9.s32, xer);
	// blt cr6,0x8254dbbc
	if (cr6.lt) goto loc_8254DBBC;
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
loc_8254DBBC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r10,r26
	cr6.compare<int32_t>(ctx.r10.s32, r26.s32, xer);
	// blt cr6,0x8254dab4
	if (cr6.lt) goto loc_8254DAB4;
loc_8254DBC8:
	// lwz r11,22560(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22560);
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// bge cr6,0x8254dc44
	if (!cr6.lt) goto loc_8254DC44;
	// addi r11,r30,22576
	r11.s64 = r30.s64 + 22576;
loc_8254DBD8:
	// lwz r8,22544(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 22544);
	// lwz r9,22536(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 22536);
	// lwz r10,22532(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 22532);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r7,r9,-1
	ctx.r7.s64 = ctx.r9.s64 + -1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r8,22544(r28)
	PPC_STORE_U32(r28.u32 + 22544, ctx.r8.u32);
	// stw r7,22536(r28)
	PPC_STORE_U32(r28.u32 + 22536, ctx.r7.u32);
	// stw r10,22532(r28)
	PPC_STORE_U32(r28.u32 + 22532, ctx.r10.u32);
	// cmpwi cr6,r10,128
	cr6.compare<int32_t>(ctx.r10.s32, 128, xer);
	// bne cr6,0x8254dc08
	if (!cr6.eq) goto loc_8254DC08;
	// stw r25,22532(r28)
	PPC_STORE_U32(r28.u32 + 22532, r25.u32);
loc_8254DC08:
	// lwz r8,140(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// lwz r9,136(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r7,r9,-1
	ctx.r7.s64 = ctx.r9.s64 + -1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r8,140(r11)
	PPC_STORE_U32(r11.u32 + 140, ctx.r8.u32);
	// stw r7,136(r11)
	PPC_STORE_U32(r11.u32 + 136, ctx.r7.u32);
	// stw r10,132(r11)
	PPC_STORE_U32(r11.u32 + 132, ctx.r10.u32);
	// cmpwi cr6,r10,128
	cr6.compare<int32_t>(ctx.r10.s32, 128, xer);
	// bne cr6,0x8254dc38
	if (!cr6.eq) goto loc_8254DC38;
	// stw r25,132(r11)
	PPC_STORE_U32(r11.u32 + 132, r25.u32);
loc_8254DC38:
	// lwz r10,22560(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 22560);
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// blt cr6,0x8254dbd8
	if (cr6.lt) goto loc_8254DBD8;
loc_8254DC44:
	// lwz r11,22992(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22992);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// bge cr6,0x8254dcc4
	if (!cr6.lt) goto loc_8254DCC4;
	// addi r11,r30,22720
	r11.s64 = r30.s64 + 22720;
	// addi r10,r30,23008
	ctx.r10.s64 = r30.s64 + 23008;
loc_8254DC58:
	// lwz r7,272(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 272);
	// lwz r8,264(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// lwz r9,260(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r6,r8,-1
	ctx.r6.s64 = ctx.r8.s64 + -1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r7,272(r11)
	PPC_STORE_U32(r11.u32 + 272, ctx.r7.u32);
	// stw r6,264(r11)
	PPC_STORE_U32(r11.u32 + 264, ctx.r6.u32);
	// stw r9,260(r11)
	PPC_STORE_U32(r11.u32 + 260, ctx.r9.u32);
	// cmpwi cr6,r9,8
	cr6.compare<int32_t>(ctx.r9.s32, 8, xer);
	// bne cr6,0x8254dc88
	if (!cr6.eq) goto loc_8254DC88;
	// stw r25,260(r11)
	PPC_STORE_U32(r11.u32 + 260, r25.u32);
loc_8254DC88:
	// lwz r7,44(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// lwz r8,40(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r6,r8,-1
	ctx.r6.s64 = ctx.r8.s64 + -1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r7,44(r10)
	PPC_STORE_U32(ctx.r10.u32 + 44, ctx.r7.u32);
	// stw r6,40(r10)
	PPC_STORE_U32(ctx.r10.u32 + 40, ctx.r6.u32);
	// stw r9,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, ctx.r9.u32);
	// cmpwi cr6,r9,8
	cr6.compare<int32_t>(ctx.r9.s32, 8, xer);
	// bne cr6,0x8254dcb8
	if (!cr6.eq) goto loc_8254DCB8;
	// stw r25,36(r10)
	PPC_STORE_U32(ctx.r10.u32 + 36, r25.u32);
loc_8254DCB8:
	// lwz r9,22992(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 22992);
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// blt cr6,0x8254dc58
	if (cr6.lt) goto loc_8254DC58;
loc_8254DCC4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8254DCCC"))) PPC_WEAK_FUNC(sub_8254DCCC);
PPC_FUNC_IMPL(__imp__sub_8254DCCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8254DCD0"))) PPC_WEAK_FUNC(sub_8254DCD0);
PPC_FUNC_IMPL(__imp__sub_8254DCD0) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8254DCD8;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f2
	f31.f64 = ctx.f2.f64;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r10,26480(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 26480);
	// lwz r11,26472(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 26472);
	// lwz r9,30784(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 30784);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// blt cr6,0x8254dd20
	if (cr6.lt) goto loc_8254DD20;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8254DD20:
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// addi r5,r1,164
	ctx.r5.s64 = ctx.r1.s64 + 164;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8254caa0
	ctx.lr = 0x8254DD34;
	sub_8254CAA0(ctx, base);
	// lwz r30,324(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// addi r11,r31,30816
	r11.s64 = r31.s64 + 30816;
	// lfs f8,25324(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 25324);
	ctx.f8.f64 = double(temp.f32);
	// addi r10,r31,25216
	ctx.r10.s64 = r31.s64 + 25216;
	// lfs f7,25312(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 25312);
	ctx.f7.f64 = double(temp.f32);
	// addi r9,r31,25232
	ctx.r9.s64 = r31.s64 + 25232;
	// lfs f6,25320(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 25320);
	ctx.f6.f64 = double(temp.f32);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lfs f5,25296(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 25296);
	ctx.f5.f64 = double(temp.f32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f4,25304(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 25304);
	ctx.f4.f64 = double(temp.f32);
	// lfs f2,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f2.f64 = double(temp.f32);
	// stw r30,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r30.u32);
	// lfs f1,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f1.f64 = double(temp.f32);
	// stw r29,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r29.u32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// stw r26,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r26.u32);
	// stw r27,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r27.u32);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// stw r9,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// bl 0x8254a280
	ctx.lr = 0x8254DD8C;
	sub_8254A280(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beq cr6,0x8254ddc0
	if (cr6.eq) goto loc_8254DDC0;
	// stfs f0,0(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// lfs f13,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beq cr6,0x8254ddc0
	if (cr6.eq) goto loc_8254DDC0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,0(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// stfs f0,0(r26)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
loc_8254DDC0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8254DDD0"))) PPC_WEAK_FUNC(sub_8254DDD0);
PPC_FUNC_IMPL(__imp__sub_8254DDD0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8254DDD8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r29,1
	r29.s64 = 1;
	// addi r30,r27,1316
	r30.s64 = r27.s64 + 1316;
	// li r31,0
	r31.s64 = 0;
loc_8254DDEC:
	// lis r11,-32237
	r11.s64 = -2112684032;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r6,r11,0
	ctx.r6.s64 = r11.s64 + 0;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r30,-1316
	ctx.r3.s64 = r30.s64 + -1316;
	// bl 0x821305f0
	ctx.lr = 0x8254DE04;
	sub_821305F0(ctx, base);
	// stw r31,-284(r30)
	PPC_STORE_U32(r30.u32 + -284, r31.u32);
	// stw r31,-288(r30)
	PPC_STORE_U32(r30.u32 + -288, r31.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// stw r31,-292(r30)
	PPC_STORE_U32(r30.u32 + -292, r31.u32);
	// stw r31,-276(r30)
	PPC_STORE_U32(r30.u32 + -276, r31.u32);
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// stw r31,-4(r30)
	PPC_STORE_U32(r30.u32 + -4, r31.u32);
	// stw r31,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r31.u32);
	// stw r31,3708(r30)
	PPC_STORE_U32(r30.u32 + 3708, r31.u32);
	// addi r30,r30,5040
	r30.s64 = r30.s64 + 5040;
	// bge 0x8254ddec
	if (!cr0.lt) goto loc_8254DDEC;
	// addi r29,r27,10080
	r29.s64 = r27.s64 + 10080;
	// li r28,1
	r28.s64 = 1;
	// addi r30,r29,1316
	r30.s64 = r29.s64 + 1316;
loc_8254DE40:
	// lis r11,-32237
	r11.s64 = -2112684032;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r6,r11,0
	ctx.r6.s64 = r11.s64 + 0;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821305f0
	ctx.lr = 0x8254DE58;
	sub_821305F0(ctx, base);
	// stw r31,-284(r30)
	PPC_STORE_U32(r30.u32 + -284, r31.u32);
	// stw r31,-288(r30)
	PPC_STORE_U32(r30.u32 + -288, r31.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// stw r31,-292(r30)
	PPC_STORE_U32(r30.u32 + -292, r31.u32);
	// addi r29,r29,5040
	r29.s64 = r29.s64 + 5040;
	// stw r31,-276(r30)
	PPC_STORE_U32(r30.u32 + -276, r31.u32);
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// stw r31,-4(r30)
	PPC_STORE_U32(r30.u32 + -4, r31.u32);
	// stw r31,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r31.u32);
	// stw r31,3708(r30)
	PPC_STORE_U32(r30.u32 + 3708, r31.u32);
	// addi r30,r30,5040
	r30.s64 = r30.s64 + 5040;
	// bge 0x8254de40
	if (!cr0.lt) goto loc_8254DE40;
	// stw r31,20160(r27)
	PPC_STORE_U32(r27.u32 + 20160, r31.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r31,21584(r27)
	PPC_STORE_U32(r27.u32 + 21584, r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8254DEA0"))) PPC_WEAK_FUNC(sub_8254DEA0);
PPC_FUNC_IMPL(__imp__sub_8254DEA0) {
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
	// li r12,-21696
	r12.s64 = -21696;
	// bl 0x823dbff4
	ctx.lr = 0x8254DEB4;
	sub_823DBFF4(ctx, base);
	// stwux r1,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8254ddd0
	ctx.lr = 0x8254DEC4;
	sub_8254DDD0(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r31,25440
	ctx.r5.s64 = r31.s64 + 25440;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82171078
	ctx.lr = 0x8254DED8;
	sub_82171078(ctx, base);
	// addi r1,r1,21696
	ctx.r1.s64 = ctx.r1.s64 + 21696;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8254DEEC"))) PPC_WEAK_FUNC(sub_8254DEEC);
PPC_FUNC_IMPL(__imp__sub_8254DEEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8254DEF0"))) PPC_WEAK_FUNC(sub_8254DEF0);
PPC_FUNC_IMPL(__imp__sub_8254DEF0) {
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
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x8254cdf0
	ctx.lr = 0x8254DF0C;
	sub_8254CDF0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// stw r11,26472(r31)
	PPC_STORE_U32(r31.u32 + 26472, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,26468(r31)
	PPC_STORE_U32(r31.u32 + 26468, r11.u32);
	// addi r9,r10,-32416
	ctx.r9.s64 = ctx.r10.s64 + -32416;
	// stw r11,26464(r31)
	PPC_STORE_U32(r31.u32 + 26464, r11.u32);
	// stw r11,26480(r31)
	PPC_STORE_U32(r31.u32 + 26480, r11.u32);
	// stw r11,26760(r31)
	PPC_STORE_U32(r31.u32 + 26760, r11.u32);
	// stw r11,26756(r31)
	PPC_STORE_U32(r31.u32 + 26756, r11.u32);
	// stw r11,26752(r31)
	PPC_STORE_U32(r31.u32 + 26752, r11.u32);
	// stw r11,26764(r31)
	PPC_STORE_U32(r31.u32 + 26764, r11.u32);
	// stw r11,30464(r31)
	PPC_STORE_U32(r31.u32 + 30464, r11.u32);
	// stw r11,30760(r31)
	PPC_STORE_U32(r31.u32 + 30760, r11.u32);
	// stw r11,30756(r31)
	PPC_STORE_U32(r31.u32 + 30756, r11.u32);
	// stw r11,30752(r31)
	PPC_STORE_U32(r31.u32 + 30752, r11.u32);
	// stw r11,30764(r31)
	PPC_STORE_U32(r31.u32 + 30764, r11.u32);
	// addi r11,r31,25440
	r11.s64 = r31.s64 + 25440;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// bl 0x8254ce70
	ctx.lr = 0x8254DF5C;
	sub_8254CE70(ctx, base);
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

__attribute__((alias("__imp__sub_8254DF74"))) PPC_WEAK_FUNC(sub_8254DF74);
PPC_FUNC_IMPL(__imp__sub_8254DF74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8254DF78"))) PPC_WEAK_FUNC(sub_8254DF78);
PPC_FUNC_IMPL(__imp__sub_8254DF78) {
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
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82550840
	ctx.lr = 0x8254DF94;
	sub_82550840(ctx, base);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x82551428
	ctx.lr = 0x8254DF9C;
	sub_82551428(ctx, base);
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82130000
	ctx.lr = 0x8254DFA4;
	sub_82130000(ctx, base);
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

__attribute__((alias("__imp__sub_8254DFB8"))) PPC_WEAK_FUNC(sub_8254DFB8);
PPC_FUNC_IMPL(__imp__sub_8254DFB8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// b 0x82550c50
	sub_82550C50(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8254DFC0"))) PPC_WEAK_FUNC(sub_8254DFC0);
PPC_FUNC_IMPL(__imp__sub_8254DFC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// b 0x82550aa0
	sub_82550AA0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8254DFD4"))) PPC_WEAK_FUNC(sub_8254DFD4);
PPC_FUNC_IMPL(__imp__sub_8254DFD4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8254DFD8"))) PPC_WEAK_FUNC(sub_8254DFD8);
PPC_FUNC_IMPL(__imp__sub_8254DFD8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// b 0x82550ba0
	sub_82550BA0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8254DFE0"))) PPC_WEAK_FUNC(sub_8254DFE0);
PPC_FUNC_IMPL(__imp__sub_8254DFE0) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8254E010;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x825512e0
	ctx.lr = 0x8254E01C;
	sub_825512E0(ctx, base);
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

__attribute__((alias("__imp__sub_8254E034"))) PPC_WEAK_FUNC(sub_8254E034);
PPC_FUNC_IMPL(__imp__sub_8254E034) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8254E038"))) PPC_WEAK_FUNC(sub_8254E038);
PPC_FUNC_IMPL(__imp__sub_8254E038) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,40(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// b 0x82551058
	sub_82551058(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8254E040"))) PPC_WEAK_FUNC(sub_8254E040);
PPC_FUNC_IMPL(__imp__sub_8254E040) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8254E070;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8254e088
	if (!cr6.eq) goto loc_8254E088;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82551538
	ctx.lr = 0x8254E084;
	sub_82551538(ctx, base);
	// b 0x8254e094
	goto loc_8254E094;
loc_8254E088:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,44(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// bl 0x82551ce8
	ctx.lr = 0x8254E094;
	sub_82551CE8(ctx, base);
loc_8254E094:
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

__attribute__((alias("__imp__sub_8254E0AC"))) PPC_WEAK_FUNC(sub_8254E0AC);
PPC_FUNC_IMPL(__imp__sub_8254E0AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8254E0B0"))) PPC_WEAK_FUNC(sub_8254E0B0);
PPC_FUNC_IMPL(__imp__sub_8254E0B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,20(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 20);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x8254e0c4
	if (!cr6.eq) goto loc_8254E0C4;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// b 0x825515a8
	sub_825515A8(ctx, base);
	return;
loc_8254E0C4:
	// lwz r3,44(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// b 0x825519f8
	sub_825519F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8254E0CC"))) PPC_WEAK_FUNC(sub_8254E0CC);
PPC_FUNC_IMPL(__imp__sub_8254E0CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8254E0D0"))) PPC_WEAK_FUNC(sub_8254E0D0);
PPC_FUNC_IMPL(__imp__sub_8254E0D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-16412
	ctx.r9.s64 = r11.s64 + -16412;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lwz r8,48(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// stwx r3,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8254E0F0"))) PPC_WEAK_FUNC(sub_8254E0F0);
PPC_FUNC_IMPL(__imp__sub_8254E0F0) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-16380
	ctx.r10.s64 = r11.s64 + -16380;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lis r8,16383
	ctx.r8.s64 = 1073676288;
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// ori r7,r8,65535
	ctx.r7.u64 = ctx.r8.u64 | 65535;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// stfs f0,28(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// cmplw cr6,r4,r7
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r7.u32, xer);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// lbz r6,36(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 36);
	// clrlwi r5,r6,25
	ctx.r5.u64 = ctx.r6.u32 & 0x7F;
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// stb r5,36(r31)
	PPC_STORE_U8(r31.u32 + 36, ctx.r5.u8);
	// stw r4,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r4.u32);
	// ble cr6,0x8254e170
	if (!cr6.gt) goto loc_8254E170;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8254E170:
	// bl 0x82130528
	ctx.lr = 0x8254E174;
	sub_82130528(ctx, base);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// mr r11,r30
	r11.u64 = r30.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8254e1a8
	if (!cr6.gt) goto loc_8254E1A8;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
loc_8254E18C:
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r8,52(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x8254e18c
	if (cr6.lt) goto loc_8254E18C;
loc_8254E1A8:
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8254E1B0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8254e1c4
	if (cr6.eq) goto loc_8254E1C4;
	// li r4,1019
	ctx.r4.s64 = 1019;
	// bl 0x82550f48
	ctx.lr = 0x8254E1C0;
	sub_82550F48(ctx, base);
	// b 0x8254e1c8
	goto loc_8254E1C8;
loc_8254E1C4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8254E1C8:
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8254E1D4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8254e1f0
	if (cr6.eq) goto loc_8254E1F0;
	// li r4,256
	ctx.r4.s64 = 256;
	// bl 0x82551870
	ctx.lr = 0x8254E1E4;
	sub_82551870(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// b 0x8254e1f4
	goto loc_8254E1F4;
loc_8254E1F0:
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
loc_8254E1F4:
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

__attribute__((alias("__imp__sub_8254E210"))) PPC_WEAK_FUNC(sub_8254E210);
PPC_FUNC_IMPL(__imp__sub_8254E210) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r10,r11,-16380
	ctx.r10.s64 = r11.s64 + -16380;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8254e254
	if (cr6.eq) goto loc_8254E254;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8254E254;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8254E254:
	// lwz r30,40(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8254e270
	if (cr6.eq) goto loc_8254E270;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82551008
	ctx.lr = 0x8254E268;
	sub_82551008(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x8254E270;
	sub_82130588(ctx, base);
loc_8254E270:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x82130588
	ctx.lr = 0x8254E278;
	sub_82130588(ctx, base);
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

__attribute__((alias("__imp__sub_8254E290"))) PPC_WEAK_FUNC(sub_8254E290);
PPC_FUNC_IMPL(__imp__sub_8254E290) {
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
	// bl 0x8254e210
	ctx.lr = 0x8254E2B0;
	sub_8254E210(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8254e2c8
	if (cr6.eq) goto loc_8254E2C8;
	// bl 0x82130588
	ctx.lr = 0x8254E2C4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8254E2C8:
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

__attribute__((alias("__imp__sub_8254E2E0"))) PPC_WEAK_FUNC(sub_8254E2E0);
PPC_FUNC_IMPL(__imp__sub_8254E2E0) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r10,-1
	ctx.r10.s64 = -1;
	// lis r9,-32127
	ctx.r9.s64 = -2105475072;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// addi r4,r9,3780
	ctx.r4.s64 = ctx.r9.s64 + 3780;
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// bl 0x8254ac78
	ctx.lr = 0x8254E320;
	sub_8254AC78(ctx, base);
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

__attribute__((alias("__imp__sub_8254E338"))) PPC_WEAK_FUNC(sub_8254E338);
PPC_FUNC_IMPL(__imp__sub_8254E338) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// b 0x8254ab20
	sub_8254AB20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8254E340"))) PPC_WEAK_FUNC(sub_8254E340);
PPC_FUNC_IMPL(__imp__sub_8254E340) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-16268
	ctx.r9.s64 = ctx.r10.s64 + -16268;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// sth r11,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r11.u16);
	// blr 
	return;
}

