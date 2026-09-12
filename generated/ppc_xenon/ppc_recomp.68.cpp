#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_823CA088"))) PPC_WEAK_FUNC(sub_823CA088);
PPC_FUNC_IMPL(__imp__sub_823CA088) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	ctx.lr = 0x823CA090;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,20
	ctx.r3.s64 = 20;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// bl 0x82130528
	ctx.lr = 0x823CA0A8;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823ca0fc
	if (cr6.eq) goto loc_823CA0FC;
	// li r30,0
	r30.s64 = 0;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// lhz r5,4(r29)
	ctx.r5.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x821c9650
	ctx.lr = 0x823CA0D0;
	sub_821C9650(ctx, base);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// sth r30,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r30.u16);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// sth r30,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r30.u16);
	// lhz r5,4(r28)
	ctx.r5.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x821c9650
	ctx.lr = 0x823CA0EC;
	sub_821C9650(ctx, base);
	// stw r27,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r27.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_823CA0FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823CA108"))) PPC_WEAK_FUNC(sub_823CA108);
PPC_FUNC_IMPL(__imp__sub_823CA108) {
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
	// li r30,0
	r30.s64 = 0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r3,r31,44
	ctx.r3.s64 = r31.s64 + 44;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r9,r10,3998
	ctx.r9.s64 = ctx.r10.s64 + 3998;
	// stfs f0,40(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// stfs f0,36(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stfs f0,28(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f0,40(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r11,r31,20
	r11.s64 = r31.s64 + 20;
	// bl 0x8239e458
	ctx.lr = 0x823CA174;
	sub_8239E458(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
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

__attribute__((alias("__imp__sub_823CA194"))) PPC_WEAK_FUNC(sub_823CA194);
PPC_FUNC_IMPL(__imp__sub_823CA194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CA198"))) PPC_WEAK_FUNC(sub_823CA198);
PPC_FUNC_IMPL(__imp__sub_823CA198) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
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
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8239e458
	ctx.lr = 0x823CA1D4;
	sub_8239E458(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823ca208
	if (cr6.eq) goto loc_823CA208;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_823CA1E4:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ca1e4
	if (!cr6.eq) goto loc_823CA1E4;
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ca210
	if (!cr6.eq) goto loc_823CA210;
loc_823CA208:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,24616
	ctx.r4.s64 = r11.s64 + 24616;
loc_823CA210:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,17432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17432);
	// bl 0x823d3730
	ctx.lr = 0x823CA220;
	sub_823D3730(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82130588
	ctx.lr = 0x823CA22C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_823CA244"))) PPC_WEAK_FUNC(sub_823CA244);
PPC_FUNC_IMPL(__imp__sub_823CA244) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CA248"))) PPC_WEAK_FUNC(sub_823CA248);
PPC_FUNC_IMPL(__imp__sub_823CA248) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823ca290
	if (cr6.eq) goto loc_823CA290;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_823CA26C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ca26c
	if (!cr6.eq) goto loc_823CA26C;
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ca298
	if (!cr6.eq) goto loc_823CA298;
loc_823CA290:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r31,r11,24616
	r31.s64 = r11.s64 + 24616;
loc_823CA298:
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x823CA2A0;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823ca2c8
	if (cr6.eq) goto loc_823CA2C8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137248
	ctx.lr = 0x823CA2B8;
	sub_82137248(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823c9ed8
	ctx.lr = 0x823CA2C4;
	sub_823C9ED8(ctx, base);
	// b 0x823ca2cc
	goto loc_823CA2CC;
loc_823CA2C8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823CA2CC:
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

__attribute__((alias("__imp__sub_823CA2E4"))) PPC_WEAK_FUNC(sub_823CA2E4);
PPC_FUNC_IMPL(__imp__sub_823CA2E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CA2E8"))) PPC_WEAK_FUNC(sub_823CA2E8);
PPC_FUNC_IMPL(__imp__sub_823CA2E8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x823CA2F0;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823ca328
	if (cr6.eq) goto loc_823CA328;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r3,r11,44
	ctx.r3.s64 = r11.s64 + 44;
	// bl 0x821ce0d8
	ctx.lr = 0x823CA328;
	sub_821CE0D8(ctx, base);
loc_823CA328:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823ca33c
	if (cr6.eq) goto loc_823CA33C;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// addi r3,r11,44
	ctx.r3.s64 = r11.s64 + 44;
	// bl 0x821ce0d8
	ctx.lr = 0x823CA33C;
	sub_821CE0D8(ctx, base);
loc_823CA33C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r3,17432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17432);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823d2330
	ctx.lr = 0x823CA364;
	sub_823D2330(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823CA370"))) PPC_WEAK_FUNC(sub_823CA370);
PPC_FUNC_IMPL(__imp__sub_823CA370) {
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
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x823ca3a0
	if (cr6.eq) goto loc_823CA3A0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17432);
	// bl 0x823d24a8
	ctx.lr = 0x823CA390;
	sub_823D24A8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_823CA3A0:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823ca40c
	if (cr6.eq) goto loc_823CA40C;
	// lwz r11,16(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ca40c
	if (cr6.eq) goto loc_823CA40C;
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ca3e4
	if (cr6.eq) goto loc_823CA3E4;
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-17784
	ctx.r3.s64 = r11.s64 + -17784;
	// bl 0x82130000
	ctx.lr = 0x823CA3D0;
	sub_82130000(ctx, base);
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
loc_823CA3E4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r11,3998
	ctx.r4.s64 = r11.s64 + 3998;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-17784
	ctx.r3.s64 = r11.s64 + -17784;
	// bl 0x82130000
	ctx.lr = 0x823CA3F8;
	sub_82130000(ctx, base);
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
loc_823CA40C:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,-17888
	ctx.r3.s64 = r11.s64 + -17888;
	// bl 0x82130000
	ctx.lr = 0x823CA418;
	sub_82130000(ctx, base);
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

__attribute__((alias("__imp__sub_823CA42C"))) PPC_WEAK_FUNC(sub_823CA42C);
PPC_FUNC_IMPL(__imp__sub_823CA42C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CA430"))) PPC_WEAK_FUNC(sub_823CA430);
PPC_FUNC_IMPL(__imp__sub_823CA430) {
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
	ctx.lr = 0x823CA438;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823ca47c
	if (cr6.eq) goto loc_823CA47C;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_823CA458:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ca458
	if (!cr6.eq) goto loc_823CA458;
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ca484
	if (!cr6.eq) goto loc_823CA484;
loc_823CA47C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r31,r11,24616
	r31.s64 = r11.s64 + 24616;
loc_823CA484:
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x823CA48C;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823ca4b8
	if (cr6.eq) goto loc_823CA4B8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137248
	ctx.lr = 0x823CA4A4;
	sub_82137248(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823c9ed8
	ctx.lr = 0x823CA4B0;
	sub_823C9ED8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x823ca4bc
	goto loc_823CA4BC;
loc_823CA4B8:
	// li r5,0
	ctx.r5.s64 = 0;
loc_823CA4BC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,17432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17432);
	// bl 0x823d1990
	ctx.lr = 0x823CA4D4;
	sub_823D1990(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823CA4DC"))) PPC_WEAK_FUNC(sub_823CA4DC);
PPC_FUNC_IMPL(__imp__sub_823CA4DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CA4E0"))) PPC_WEAK_FUNC(sub_823CA4E0);
PPC_FUNC_IMPL(__imp__sub_823CA4E0) {
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
	ctx.lr = 0x823CA4E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823ca50c
	if (cr6.eq) goto loc_823CA50C;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r3,r11,44
	ctx.r3.s64 = r11.s64 + 44;
	// bl 0x821ce0d8
	ctx.lr = 0x823CA50C;
	sub_821CE0D8(ctx, base);
loc_823CA50C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,17432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17432);
	// bl 0x823d08d0
	ctx.lr = 0x823CA524;
	sub_823D08D0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823CA52C"))) PPC_WEAK_FUNC(sub_823CA52C);
PPC_FUNC_IMPL(__imp__sub_823CA52C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CA530"))) PPC_WEAK_FUNC(sub_823CA530);
PPC_FUNC_IMPL(__imp__sub_823CA530) {
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
	ctx.lr = 0x823CA538;
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
	// beq cr6,0x823ca5a8
	if (cr6.eq) goto loc_823CA5A8;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x823CA554;
	sub_82130588(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ca5a8
	if (cr6.eq) goto loc_823CA5A8;
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
	// blt 0x823ca5a0
	if (cr0.lt) goto loc_823CA5A0;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r29,r11,-17996
	r29.s64 = r11.s64 + -17996;
loc_823CA588:
	// addi r30,r30,-24
	r30.s64 = r30.s64 + -24;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x823CA598;
	sub_82130588(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x823ca588
	if (!cr0.lt) goto loc_823CA588;
loc_823CA5A0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x823CA5A8;
	sub_82130588(ctx, base);
loc_823CA5A8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823CA5B0"))) PPC_WEAK_FUNC(sub_823CA5B0);
PPC_FUNC_IMPL(__imp__sub_823CA5B0) {
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
	ctx.lr = 0x823CA5B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r3,r30,6,0,25
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0xFFFFFFC0;
	// bl 0x82130528
	ctx.lr = 0x823CA5C8;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x823ca5f4
	if (!cr6.gt) goto loc_823CA5F4;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_823CA5D8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823ca5e8
	if (cr6.eq) goto loc_823CA5E8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823ca108
	ctx.lr = 0x823CA5E8;
	sub_823CA108(ctx, base);
loc_823CA5E8:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,64
	r31.s64 = r31.s64 + 64;
	// bne 0x823ca5d8
	if (!cr0.eq) goto loc_823CA5D8;
loc_823CA5F4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823CA600"))) PPC_WEAK_FUNC(sub_823CA600);
PPC_FUNC_IMPL(__imp__sub_823CA600) {
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
	ctx.lr = 0x823CA608;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// rlwinm r28,r11,0,2,3
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x823ca67c
	if (cr6.eq) goto loc_823CA67C;
	// bl 0x82793e10
	ctx.lr = 0x823CA628;
	sub_82793E10(ctx, base);
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r31,40
	r31.s64 = 40;
	// lis r11,12288
	r11.s64 = 805306368;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stwx r10,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, ctx.r10.u32);
	// bne cr6,0x823ca654
	if (!cr6.eq) goto loc_823CA654;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82177a08
	ctx.lr = 0x823CA650;
	sub_82177A08(ctx, base);
	// b 0x823ca65c
	goto loc_823CA65C;
loc_823CA654:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821e5598
	ctx.lr = 0x823CA65C;
	sub_821E5598(ctx, base);
loc_823CA65C:
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stwx r9,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, ctx.r9.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// bl 0x821e2808
	ctx.lr = 0x823CA67C;
	sub_821E2808(ctx, base);
loc_823CA67C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823CA684"))) PPC_WEAK_FUNC(sub_823CA684);
PPC_FUNC_IMPL(__imp__sub_823CA684) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CA688"))) PPC_WEAK_FUNC(sub_823CA688);
PPC_FUNC_IMPL(__imp__sub_823CA688) {
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
	ctx.lr = 0x823CA690;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823ca6b8
	if (!cr6.eq) goto loc_823CA6B8;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82608a98
	ctx.lr = 0x823CA6B8;
	sub_82608A98(ctx, base);
loc_823CA6B8:
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lhz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// clrlwi r9,r11,16
	ctx.r9.u64 = r11.u32 & 0xFFFF;
	// sth r9,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r9.u16);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x823ca6e8
	if (!cr6.eq) goto loc_823CA6E8;
	// bl 0x821c9438
	ctx.lr = 0x823CA6DC;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823c9750
	ctx.lr = 0x823CA6E8;
	sub_823C9750(ctx, base);
loc_823CA6E8:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821c95a0
	ctx.lr = 0x823CA6F0;
	sub_821C95A0(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// divwu r9,r3,r10
	ctx.r9.u32 = ctx.r3.u32 / ctx.r10.u32;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// sth r11,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r11.u16);
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// sth r11,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r11.u16);
	// twllei r10,0
	// subf r30,r8,r3
	r30.s64 = ctx.r3.s64 - ctx.r8.s64;
	// beq cr6,0x823ca748
	if (cr6.eq) goto loc_823CA748;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_823CA724:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ca724
	if (!cr6.eq) goto loc_823CA724;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823CA748;
	sub_821C9650(ctx, base);
loc_823CA748:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r30,r30,2,0,29
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,10
	ctx.r3.s64 = r31.s64 + 10;
	// lwzx r6,r30,r11
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x823ca088
	ctx.lr = 0x823CA764;
	sub_823CA088(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r3,r30,r10
	PPC_STORE_U32(r30.u32 + ctx.r10.u32, ctx.r3.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82130588
	ctx.lr = 0x823CA774;
	sub_82130588(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r3,r30,r9
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823CA784"))) PPC_WEAK_FUNC(sub_823CA784);
PPC_FUNC_IMPL(__imp__sub_823CA784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CA788"))) PPC_WEAK_FUNC(sub_823CA788);
PPC_FUNC_IMPL(__imp__sub_823CA788) {
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
	ctx.lr = 0x823CA790;
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
	// bne cr6,0x823ca7b8
	if (!cr6.eq) goto loc_823CA7B8;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82608a98
	ctx.lr = 0x823CA7B8;
	sub_82608A98(ctx, base);
loc_823CA7B8:
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
	// bne cr6,0x823ca7e8
	if (!cr6.eq) goto loc_823CA7E8;
	// bl 0x821c9438
	ctx.lr = 0x823CA7DC;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823c9658
	ctx.lr = 0x823CA7E8;
	sub_823C9658(ctx, base);
loc_823CA7E8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821c95a0
	ctx.lr = 0x823CA7F0;
	sub_821C95A0(ctx, base);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// li r29,0
	r29.s64 = 0;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// divwu r10,r3,r11
	ctx.r10.u32 = ctx.r3.u32 / r11.u32;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// sth r29,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r29.u16);
	// mullw r9,r10,r11
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// sth r29,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r29.u16);
	// twllei r11,0
	// subf r31,r9,r3
	r31.s64 = ctx.r3.s64 - ctx.r9.s64;
	// beq cr6,0x823ca848
	if (cr6.eq) goto loc_823CA848;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_823CA824:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ca824
	if (!cr6.eq) goto loc_823CA824;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823CA848;
	sub_821C9650(ctx, base);
loc_823CA848:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r27,r31,2,0,29
	r27.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,16
	ctx.r3.s64 = 16;
	// lwzx r28,r27,r11
	r28.u64 = PPC_LOAD_U32(r27.u32 + r11.u32);
	// bl 0x82130528
	ctx.lr = 0x823CA85C;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823ca890
	if (cr6.eq) goto loc_823CA890;
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
	ctx.lr = 0x823CA880;
	sub_821C9650(ctx, base);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r29,r31
	r29.u64 = r31.u64;
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
loc_823CA890:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stwx r29,r27,r11
	PPC_STORE_U32(r27.u32 + r11.u32, r29.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82130588
	ctx.lr = 0x823CA8A0;
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

__attribute__((alias("__imp__sub_823CA8B0"))) PPC_WEAK_FUNC(sub_823CA8B0);
PPC_FUNC_IMPL(__imp__sub_823CA8B0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x823CA8B8;
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// addi r5,r11,-14056
	ctx.r5.s64 = r11.s64 + -14056;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82137a08
	ctx.lr = 0x823CA8E4;
	sub_82137A08(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// sth r30,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r30.u16);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// sth r30,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r30.u16);
loc_823CA8FC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823ca8fc
	if (!cr6.eq) goto loc_823CA8FC;
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
	ctx.lr = 0x823CA924;
	sub_821C9650(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823c9e48
	ctx.lr = 0x823CA930;
	sub_823C9E48(ctx, base);
	// lwz r3,4(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 4);
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
	ctx.lr = 0x823CA94C;
	sub_823C9FC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// beq cr6,0x823ca974
	if (cr6.eq) goto loc_823CA974;
	// addi r10,r11,-17996
	ctx.r10.s64 = r11.s64 + -17996;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// bl 0x82130588
	ctx.lr = 0x823CA968;
	sub_82130588(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// b 0x823d9240
	return;
loc_823CA974:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r28,r11,-17996
	r28.s64 = r11.s64 + -17996;
	// beq cr6,0x823caa38
	if (cr6.eq) goto loc_823CAA38;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r29,r11,30576
	r29.s64 = r11.s64 + 30576;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ca540
	ctx.lr = 0x823CA994;
	sub_821CA540(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82507720
	ctx.lr = 0x823CA9A8;
	sub_82507720(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823caa30
	if (cr6.eq) goto loc_823CAA30;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r30,1
	r30.s64 = 1;
	// addi r3,r11,-17656
	ctx.r3.s64 = r11.s64 + -17656;
	// bl 0x82130000
	ctx.lr = 0x823CA9C8;
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
	ctx.lr = 0x823CA9FC;
	sub_82130000(ctx, base);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137248
	ctx.lr = 0x823CAA08;
	sub_82137248(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x823c9db8
	ctx.lr = 0x823CAA18;
	sub_823C9DB8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,4(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// bl 0x823d4b28
	ctx.lr = 0x823CAA24;
	sub_823D4B28(ctx, base);
	// stw r28,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r28.u32);
	// lwz r3,132(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x82130588
	ctx.lr = 0x823CAA30;
	sub_82130588(ctx, base);
loc_823CAA30:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x823CAA38;
	sub_821C9A90(ctx, base);
loc_823CAA38:
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r28.u32);
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82130588
	ctx.lr = 0x823CAA44;
	sub_82130588(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823CAA50"))) PPC_WEAK_FUNC(sub_823CAA50);
PPC_FUNC_IMPL(__imp__sub_823CAA50) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823caaa0
	if (cr6.eq) goto loc_823CAAA0;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823caaa0
	if (cr6.eq) goto loc_823CAAA0;
	// bl 0x823b7b70
	ctx.lr = 0x823CAA84;
	sub_823B7B70(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x823caaa0
	if (!cr6.eq) goto loc_823CAAA0;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x823b7b70
	ctx.lr = 0x823CAA94;
	sub_823B7B70(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x823d5ac0
	ctx.lr = 0x823CAAA0;
	sub_823D5AC0(ctx, base);
loc_823CAAA0:
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

__attribute__((alias("__imp__sub_823CAAB8"))) PPC_WEAK_FUNC(sub_823CAAB8);
PPC_FUNC_IMPL(__imp__sub_823CAAB8) {
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
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82137a08
	ctx.lr = 0x823CAAE8;
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
loc_823CAB00:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cab00
	if (!cr6.eq) goto loc_823CAB00;
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
	ctx.lr = 0x823CAB28;
	sub_821C9650(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823c9e48
	ctx.lr = 0x823CAB34;
	sub_823C9E48(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
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
	ctx.lr = 0x823CAB50;
	sub_823C9FC8(ctx, base);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r7,r8,-17996
	ctx.r7.s64 = ctx.r8.s64 + -17996;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// bl 0x82130588
	ctx.lr = 0x823CAB68;
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
}

__attribute__((alias("__imp__sub_823CAB80"))) PPC_WEAK_FUNC(sub_823CAB80);
PPC_FUNC_IMPL(__imp__sub_823CAB80) {
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
	ctx.lr = 0x823CAB88;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r31,0
	r31.s64 = 0;
	// stw r4,268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 268, ctx.r4.u32);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// sth r31,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r31.u16);
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// sth r31,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r31.u16);
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// mr r26,r10
	r26.u64 = ctx.r10.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823cabec
	if (cr6.eq) goto loc_823CABEC;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
loc_823CABC4:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cabc4
	if (!cr6.eq) goto loc_823CABC4;
	// subf r11,r5,r11
	r11.s64 = r11.s64 - ctx.r5.s64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823CABEC;
	sub_821C9650(ctx, base);
loc_823CABEC:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,268
	ctx.r4.s64 = ctx.r1.s64 + 268;
	// addi r3,r25,68
	ctx.r3.s64 = r25.s64 + 68;
	// bl 0x823ca688
	ctx.lr = 0x823CABFC;
	sub_823CA688(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82130588
	ctx.lr = 0x823CAC04;
	sub_82130588(ctx, base);
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// sth r31,92(r1)
	PPC_STORE_U16(ctx.r1.u32 + 92, r31.u16);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r31,94(r1)
	PPC_STORE_U16(ctx.r1.u32 + 94, r31.u16);
	// beq cr6,0x823cac44
	if (cr6.eq) goto loc_823CAC44;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_823CAC1C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cac1c
	if (!cr6.eq) goto loc_823CAC1C;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823CAC44;
	sub_821C9650(ctx, base);
loc_823CAC44:
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,268
	ctx.r4.s64 = ctx.r1.s64 + 268;
	// addi r3,r25,80
	ctx.r3.s64 = r25.s64 + 80;
	// bl 0x823ca688
	ctx.lr = 0x823CAC54;
	sub_823CA688(ctx, base);
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x82130588
	ctx.lr = 0x823CAC5C;
	sub_82130588(ctx, base);
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// sth r31,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, r31.u16);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// sth r31,102(r1)
	PPC_STORE_U16(ctx.r1.u32 + 102, r31.u16);
	// beq cr6,0x823cac9c
	if (cr6.eq) goto loc_823CAC9C;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_823CAC74:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cac74
	if (!cr6.eq) goto loc_823CAC74;
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823CAC9C;
	sub_821C9650(ctx, base);
loc_823CAC9C:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,268
	ctx.r4.s64 = ctx.r1.s64 + 268;
	// addi r3,r25,92
	ctx.r3.s64 = r25.s64 + 92;
	// bl 0x823ca688
	ctx.lr = 0x823CACAC;
	sub_823CA688(ctx, base);
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x82130588
	ctx.lr = 0x823CACB4;
	sub_82130588(ctx, base);
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
	// sth r31,108(r1)
	PPC_STORE_U16(ctx.r1.u32 + 108, r31.u16);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// sth r31,110(r1)
	PPC_STORE_U16(ctx.r1.u32 + 110, r31.u16);
	// beq cr6,0x823cacf4
	if (cr6.eq) goto loc_823CACF4;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_823CACCC:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823caccc
	if (!cr6.eq) goto loc_823CACCC;
	// subf r11,r28,r11
	r11.s64 = r11.s64 - r28.s64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823CACF4;
	sub_821C9650(ctx, base);
loc_823CACF4:
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,268
	ctx.r4.s64 = ctx.r1.s64 + 268;
	// addi r3,r25,104
	ctx.r3.s64 = r25.s64 + 104;
	// bl 0x823ca688
	ctx.lr = 0x823CAD04;
	sub_823CA688(ctx, base);
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// bl 0x82130588
	ctx.lr = 0x823CAD0C;
	sub_82130588(ctx, base);
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// sth r31,116(r1)
	PPC_STORE_U16(ctx.r1.u32 + 116, r31.u16);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// sth r31,118(r1)
	PPC_STORE_U16(ctx.r1.u32 + 118, r31.u16);
	// beq cr6,0x823cad4c
	if (cr6.eq) goto loc_823CAD4C;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_823CAD24:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cad24
	if (!cr6.eq) goto loc_823CAD24;
	// subf r11,r27,r11
	r11.s64 = r11.s64 - r27.s64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823CAD4C;
	sub_821C9650(ctx, base);
loc_823CAD4C:
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,268
	ctx.r4.s64 = ctx.r1.s64 + 268;
	// addi r3,r25,116
	ctx.r3.s64 = r25.s64 + 116;
	// bl 0x823ca688
	ctx.lr = 0x823CAD5C;
	sub_823CA688(ctx, base);
	// lwz r3,112(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// bl 0x82130588
	ctx.lr = 0x823CAD64;
	sub_82130588(ctx, base);
	// stw r31,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r31.u32);
	// sth r31,124(r1)
	PPC_STORE_U16(ctx.r1.u32 + 124, r31.u16);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// sth r31,126(r1)
	PPC_STORE_U16(ctx.r1.u32 + 126, r31.u16);
	// beq cr6,0x823cada4
	if (cr6.eq) goto loc_823CADA4;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_823CAD7C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cad7c
	if (!cr6.eq) goto loc_823CAD7C;
	// subf r11,r26,r11
	r11.s64 = r11.s64 - r26.s64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823CADA4;
	sub_821C9650(ctx, base);
loc_823CADA4:
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// addi r4,r1,268
	ctx.r4.s64 = ctx.r1.s64 + 268;
	// addi r3,r25,128
	ctx.r3.s64 = r25.s64 + 128;
	// bl 0x823ca688
	ctx.lr = 0x823CADB4;
	sub_823CA688(ctx, base);
	// lwz r3,120(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// bl 0x82130588
	ctx.lr = 0x823CADBC;
	sub_82130588(ctx, base);
	// lwz r4,324(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// stw r31,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r31.u32);
	// sth r31,132(r1)
	PPC_STORE_U16(ctx.r1.u32 + 132, r31.u16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// sth r31,134(r1)
	PPC_STORE_U16(ctx.r1.u32 + 134, r31.u16);
	// beq cr6,0x823cadfc
	if (cr6.eq) goto loc_823CADFC;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_823CADD8:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cadd8
	if (!cr6.eq) goto loc_823CADD8;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823CADFC;
	sub_821C9650(ctx, base);
loc_823CADFC:
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,268
	ctx.r4.s64 = ctx.r1.s64 + 268;
	// addi r3,r25,140
	ctx.r3.s64 = r25.s64 + 140;
	// bl 0x823ca688
	ctx.lr = 0x823CAE0C;
	sub_823CA688(ctx, base);
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// bl 0x82130588
	ctx.lr = 0x823CAE14;
	sub_82130588(ctx, base);
	// lwz r4,332(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	// stw r31,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r31.u32);
	// sth r31,140(r1)
	PPC_STORE_U16(ctx.r1.u32 + 140, r31.u16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// sth r31,142(r1)
	PPC_STORE_U16(ctx.r1.u32 + 142, r31.u16);
	// beq cr6,0x823cae54
	if (cr6.eq) goto loc_823CAE54;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_823CAE30:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cae30
	if (!cr6.eq) goto loc_823CAE30;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823CAE54;
	sub_821C9650(ctx, base);
loc_823CAE54:
	// addi r5,r1,136
	ctx.r5.s64 = ctx.r1.s64 + 136;
	// addi r4,r1,268
	ctx.r4.s64 = ctx.r1.s64 + 268;
	// addi r3,r25,152
	ctx.r3.s64 = r25.s64 + 152;
	// bl 0x823ca688
	ctx.lr = 0x823CAE64;
	sub_823CA688(ctx, base);
	// lwz r3,136(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// bl 0x82130588
	ctx.lr = 0x823CAE6C;
	sub_82130588(ctx, base);
	// lwz r4,340(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	// stw r31,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r31.u32);
	// sth r31,148(r1)
	PPC_STORE_U16(ctx.r1.u32 + 148, r31.u16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// sth r31,150(r1)
	PPC_STORE_U16(ctx.r1.u32 + 150, r31.u16);
	// beq cr6,0x823caeac
	if (cr6.eq) goto loc_823CAEAC;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_823CAE88:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cae88
	if (!cr6.eq) goto loc_823CAE88;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823CAEAC;
	sub_821C9650(ctx, base);
loc_823CAEAC:
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,268
	ctx.r4.s64 = ctx.r1.s64 + 268;
	// addi r3,r25,164
	ctx.r3.s64 = r25.s64 + 164;
	// bl 0x823ca688
	ctx.lr = 0x823CAEBC;
	sub_823CA688(ctx, base);
	// lwz r3,144(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// bl 0x82130588
	ctx.lr = 0x823CAEC4;
	sub_82130588(ctx, base);
	// lwz r4,348(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 348);
	// stw r31,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r31.u32);
	// sth r31,156(r1)
	PPC_STORE_U16(ctx.r1.u32 + 156, r31.u16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// sth r31,158(r1)
	PPC_STORE_U16(ctx.r1.u32 + 158, r31.u16);
	// beq cr6,0x823caf04
	if (cr6.eq) goto loc_823CAF04;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_823CAEE0:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823caee0
	if (!cr6.eq) goto loc_823CAEE0;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823CAF04;
	sub_821C9650(ctx, base);
loc_823CAF04:
	// addi r5,r1,152
	ctx.r5.s64 = ctx.r1.s64 + 152;
	// addi r4,r1,268
	ctx.r4.s64 = ctx.r1.s64 + 268;
	// addi r3,r25,176
	ctx.r3.s64 = r25.s64 + 176;
	// bl 0x823ca688
	ctx.lr = 0x823CAF14;
	sub_823CA688(ctx, base);
	// lwz r3,152(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// bl 0x82130588
	ctx.lr = 0x823CAF1C;
	sub_82130588(ctx, base);
	// lwz r4,356(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 356);
	// stw r31,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r31.u32);
	// sth r31,164(r1)
	PPC_STORE_U16(ctx.r1.u32 + 164, r31.u16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// sth r31,166(r1)
	PPC_STORE_U16(ctx.r1.u32 + 166, r31.u16);
	// beq cr6,0x823caf5c
	if (cr6.eq) goto loc_823CAF5C;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_823CAF38:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823caf38
	if (!cr6.eq) goto loc_823CAF38;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823CAF5C;
	sub_821C9650(ctx, base);
loc_823CAF5C:
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,268
	ctx.r4.s64 = ctx.r1.s64 + 268;
	// addi r3,r25,188
	ctx.r3.s64 = r25.s64 + 188;
	// bl 0x823ca688
	ctx.lr = 0x823CAF6C;
	sub_823CA688(ctx, base);
	// lwz r3,160(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// bl 0x82130588
	ctx.lr = 0x823CAF74;
	sub_82130588(ctx, base);
	// lwz r4,364(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 364);
	// stw r31,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r31.u32);
	// sth r31,172(r1)
	PPC_STORE_U16(ctx.r1.u32 + 172, r31.u16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// sth r31,174(r1)
	PPC_STORE_U16(ctx.r1.u32 + 174, r31.u16);
	// beq cr6,0x823cafb4
	if (cr6.eq) goto loc_823CAFB4;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_823CAF90:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823caf90
	if (!cr6.eq) goto loc_823CAF90;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r3,r1,168
	ctx.r3.s64 = ctx.r1.s64 + 168;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823CAFB4;
	sub_821C9650(ctx, base);
loc_823CAFB4:
	// addi r5,r1,168
	ctx.r5.s64 = ctx.r1.s64 + 168;
	// addi r4,r1,268
	ctx.r4.s64 = ctx.r1.s64 + 268;
	// addi r3,r25,200
	ctx.r3.s64 = r25.s64 + 200;
	// bl 0x823ca688
	ctx.lr = 0x823CAFC4;
	sub_823CA688(ctx, base);
	// lwz r3,168(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// bl 0x82130588
	ctx.lr = 0x823CAFCC;
	sub_82130588(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823CAFD4"))) PPC_WEAK_FUNC(sub_823CAFD4);
PPC_FUNC_IMPL(__imp__sub_823CAFD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CAFD8"))) PPC_WEAK_FUNC(sub_823CAFD8);
PPC_FUNC_IMPL(__imp__sub_823CAFD8) {
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
	ctx.lr = 0x823CAFE0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r31,0
	r31.s64 = 0;
	// stw r4,220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 220, ctx.r4.u32);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// sth r31,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r31.u16);
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// sth r31,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r31.u16);
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823cb040
	if (cr6.eq) goto loc_823CB040;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_823CB018:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cb018
	if (!cr6.eq) goto loc_823CB018;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823CB040;
	sub_821C9650(ctx, base);
loc_823CB040:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,220
	ctx.r4.s64 = ctx.r1.s64 + 220;
	// addi r3,r28,116
	ctx.r3.s64 = r28.s64 + 116;
	// bl 0x823ca688
	ctx.lr = 0x823CB050;
	sub_823CA688(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82130588
	ctx.lr = 0x823CB058;
	sub_82130588(ctx, base);
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// sth r31,92(r1)
	PPC_STORE_U16(ctx.r1.u32 + 92, r31.u16);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// sth r31,94(r1)
	PPC_STORE_U16(ctx.r1.u32 + 94, r31.u16);
	// beq cr6,0x823cb098
	if (cr6.eq) goto loc_823CB098;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_823CB070:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cb070
	if (!cr6.eq) goto loc_823CB070;
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823CB098;
	sub_821C9650(ctx, base);
loc_823CB098:
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,220
	ctx.r4.s64 = ctx.r1.s64 + 220;
	// addi r3,r28,128
	ctx.r3.s64 = r28.s64 + 128;
	// bl 0x823ca688
	ctx.lr = 0x823CB0A8;
	sub_823CA688(ctx, base);
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x82130588
	ctx.lr = 0x823CB0B0;
	sub_82130588(ctx, base);
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// sth r31,100(r1)
	PPC_STORE_U16(ctx.r1.u32 + 100, r31.u16);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r31,102(r1)
	PPC_STORE_U16(ctx.r1.u32 + 102, r31.u16);
	// beq cr6,0x823cb0f0
	if (cr6.eq) goto loc_823CB0F0;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_823CB0C8:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cb0c8
	if (!cr6.eq) goto loc_823CB0C8;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823CB0F0;
	sub_821C9650(ctx, base);
loc_823CB0F0:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,220
	ctx.r4.s64 = ctx.r1.s64 + 220;
	// addi r3,r28,140
	ctx.r3.s64 = r28.s64 + 140;
	// bl 0x823ca688
	ctx.lr = 0x823CB100;
	sub_823CA688(ctx, base);
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// bl 0x82130588
	ctx.lr = 0x823CB108;
	sub_82130588(ctx, base);
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
	// sth r31,108(r1)
	PPC_STORE_U16(ctx.r1.u32 + 108, r31.u16);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// sth r31,110(r1)
	PPC_STORE_U16(ctx.r1.u32 + 110, r31.u16);
	// beq cr6,0x823cb148
	if (cr6.eq) goto loc_823CB148;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_823CB120:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cb120
	if (!cr6.eq) goto loc_823CB120;
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823CB148;
	sub_821C9650(ctx, base);
loc_823CB148:
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,220
	ctx.r4.s64 = ctx.r1.s64 + 220;
	// addi r3,r28,152
	ctx.r3.s64 = r28.s64 + 152;
	// bl 0x823ca688
	ctx.lr = 0x823CB158;
	sub_823CA688(ctx, base);
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// bl 0x82130588
	ctx.lr = 0x823CB160;
	sub_82130588(ctx, base);
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// sth r31,116(r1)
	PPC_STORE_U16(ctx.r1.u32 + 116, r31.u16);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// sth r31,118(r1)
	PPC_STORE_U16(ctx.r1.u32 + 118, r31.u16);
	// beq cr6,0x823cb1a0
	if (cr6.eq) goto loc_823CB1A0;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_823CB178:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cb178
	if (!cr6.eq) goto loc_823CB178;
	// subf r11,r27,r11
	r11.s64 = r11.s64 - r27.s64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823CB1A0;
	sub_821C9650(ctx, base);
loc_823CB1A0:
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,220
	ctx.r4.s64 = ctx.r1.s64 + 220;
	// addi r3,r28,164
	ctx.r3.s64 = r28.s64 + 164;
	// bl 0x823ca688
	ctx.lr = 0x823CB1B0;
	sub_823CA688(ctx, base);
	// lwz r3,112(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// bl 0x82130588
	ctx.lr = 0x823CB1B8;
	sub_82130588(ctx, base);
	// stw r31,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r31.u32);
	// sth r31,124(r1)
	PPC_STORE_U16(ctx.r1.u32 + 124, r31.u16);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// sth r31,126(r1)
	PPC_STORE_U16(ctx.r1.u32 + 126, r31.u16);
	// beq cr6,0x823cb1f8
	if (cr6.eq) goto loc_823CB1F8;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_823CB1D0:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cb1d0
	if (!cr6.eq) goto loc_823CB1D0;
	// subf r11,r26,r11
	r11.s64 = r11.s64 - r26.s64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// rotlwi r5,r11,0
	ctx.r5.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x821c9650
	ctx.lr = 0x823CB1F8;
	sub_821C9650(ctx, base);
loc_823CB1F8:
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// addi r4,r1,220
	ctx.r4.s64 = ctx.r1.s64 + 220;
	// addi r3,r28,176
	ctx.r3.s64 = r28.s64 + 176;
	// bl 0x823ca688
	ctx.lr = 0x823CB208;
	sub_823CA688(ctx, base);
	// lwz r3,120(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// bl 0x82130588
	ctx.lr = 0x823CB210;
	sub_82130588(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823CB218"))) PPC_WEAK_FUNC(sub_823CB218);
PPC_FUNC_IMPL(__imp__sub_823CB218) {
	PPC_FUNC_PROLOGUE();
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
	// li r11,0
	r11.s64 = 0;
	// lwz r3,220(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// ld r7,88(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// bl 0x8246d2f8
	ctx.lr = 0x823CB24C;
	sub_8246D2F8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CB25C"))) PPC_WEAK_FUNC(sub_823CB25C);
PPC_FUNC_IMPL(__imp__sub_823CB25C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CB260"))) PPC_WEAK_FUNC(sub_823CB260);
PPC_FUNC_IMPL(__imp__sub_823CB260) {
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
	ctx.lr = 0x823CB268;
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
	// addi r26,r11,-17996
	r26.s64 = r11.s64 + -17996;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823cb2dc
	if (cr6.eq) goto loc_823CB2DC;
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x823CB290;
	sub_82130588(ctx, base);
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823cb2dc
	if (cr6.eq) goto loc_823CB2DC;
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
	// blt 0x823cb2d4
	if (cr0.lt) goto loc_823CB2D4;
loc_823CB2BC:
	// addi r30,r30,-24
	r30.s64 = r30.s64 + -24;
	// stw r26,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r26.u32);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x823CB2CC;
	sub_82130588(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x823cb2bc
	if (!cr0.lt) goto loc_823CB2BC;
loc_823CB2D4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x823CB2DC;
	sub_82130588(ctx, base);
loc_823CB2DC:
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
	// ble cr6,0x823cb330
	if (!cr6.gt) goto loc_823CB330;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823CB330:
	// bl 0x82130528
	ctx.lr = 0x823CB334;
	sub_82130528(ctx, base);
	// lis r11,2730
	r11.s64 = 178913280;
	// stw r3,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r3.u32);
	// ori r10,r11,43690
	ctx.r10.u64 = r11.u64 | 43690;
	// cmplw cr6,r27,r10
	cr6.compare<uint32_t>(r27.u32, ctx.r10.u32, xer);
	// bgt cr6,0x823cb364
	if (cr6.gt) goto loc_823CB364;
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
	// ble cr6,0x823cb368
	if (!cr6.gt) goto loc_823CB368;
loc_823CB364:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823CB368:
	// bl 0x82130528
	ctx.lr = 0x823CB36C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// beq cr6,0x823cb3c0
	if (cr6.eq) goto loc_823CB3C0;
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
	// blt 0x823cb3b8
	if (cr0.lt) goto loc_823CB3B8;
	// addi r11,r8,10
	r11.s64 = ctx.r8.s64 + 10;
loc_823CB390:
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
	// bge 0x823cb390
	if (!cr0.lt) goto loc_823CB390;
loc_823CB3B8:
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// b 0x823cb3c4
	goto loc_823CB3C4;
loc_823CB3C0:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_823CB3C4:
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
	// beq 0x823cb400
	if (cr0.eq) goto loc_823CB400;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
loc_823CB3E4:
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
	// bne 0x823cb3e4
	if (!cr0.eq) goto loc_823CB3E4;
loc_823CB400:
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
	ctx.lr = 0x823CB42C;
	sub_823D9890(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823CB434"))) PPC_WEAK_FUNC(sub_823CB434);
PPC_FUNC_IMPL(__imp__sub_823CB434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CB438"))) PPC_WEAK_FUNC(sub_823CB438);
PPC_FUNC_IMPL(__imp__sub_823CB438) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x823CB440;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// lhz r11,216(r22)
	r11.u64 = PPC_LOAD_U16(r22.u32 + 216);
	// addic. r20,r11,-1
	xer.ca = r11.u32 > 0;
	r20.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r20.s32, 0, xer);
	// blt 0x823cb6a0
	if (cr0.lt) goto loc_823CB6A0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r29,r22,212
	r29.s64 = r22.s64 + 212;
	// rlwinm r27,r20,6,0,25
	r27.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 6) & 0xFFFFFFC0;
	// ori r26,r9,65535
	r26.u64 = ctx.r9.u64 | 65535;
	// li r23,0
	r23.s64 = 0;
	// li r18,1
	r18.s64 = 1;
	// li r19,2
	r19.s64 = 2;
	// addi r24,r11,-10820
	r24.s64 = r11.s64 + -10820;
	// addi r21,r10,24616
	r21.s64 = ctx.r10.s64 + 24616;
loc_823CB484:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r31,r11,r27
	r31.u64 = r11.u64 + r27.u64;
	// lwzx r11,r11,r27
	r11.u64 = PPC_LOAD_U32(r11.u32 + r27.u32);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x823cb5a0
	if (!cr6.eq) goto loc_823CB5A0;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823cb4cc
	if (cr6.eq) goto loc_823CB4CC;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_823CB4A8:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cb4a8
	if (!cr6.eq) goto loc_823CB4A8;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cb4d0
	if (!cr6.eq) goto loc_823CB4D0;
loc_823CB4CC:
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
loc_823CB4D0:
	// addi r5,r31,44
	ctx.r5.s64 = r31.s64 + 44;
	// lwz r3,17432(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 17432);
	// bl 0x823d0838
	ctx.lr = 0x823CB4DC;
	sub_823D0838(ctx, base);
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r8,6
	ctx.r8.s64 = 6;
	// add r7,r11,r26
	ctx.r7.u64 = r11.u64 + r26.u64;
	// add r10,r27,r9
	ctx.r10.u64 = r27.u64 + ctx.r9.u64;
	// clrlwi r5,r7,16
	ctx.r5.u64 = ctx.r7.u32 & 0xFFFF;
	// addi r6,r10,20
	ctx.r6.s64 = ctx.r10.s64 + 20;
	// rlwinm r11,r5,6,10,25
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0x3FFFC0;
	// sth r5,4(r29)
	PPC_STORE_U16(r29.u32 + 4, ctx.r5.u16);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r7,r11,20
	ctx.r7.s64 = r11.s64 + 20;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stwx r4,r27,r9
	PPC_STORE_U32(r27.u32 + ctx.r9.u32, ctx.r4.u32);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r3,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
	// lbz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 8);
	// stb r9,8(r10)
	PPC_STORE_U8(ctx.r10.u32 + 8, ctx.r9.u8);
	// lwz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r5,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r5.u32);
	// lwz r4,16(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// stw r4,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r4.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_823CB534:
	// lwz r9,0(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// stw r9,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r9.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bdnz 0x823cb534
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823CB534;
	// lwz r7,44(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// addi r9,r10,44
	ctx.r9.s64 = ctx.r10.s64 + 44;
	// addi r8,r11,44
	ctx.r8.s64 = r11.s64 + 44;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// addi r3,r9,4
	ctx.r3.s64 = ctx.r9.s64 + 4;
	// stw r7,44(r10)
	PPC_STORE_U32(ctx.r10.u32 + 44, ctx.r7.u32);
	// lbz r6,48(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 48);
	// stb r6,48(r10)
	PPC_STORE_U8(ctx.r10.u32 + 48, ctx.r6.u8);
	// lbz r5,52(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 52);
	// stb r5,52(r10)
	PPC_STORE_U8(ctx.r10.u32 + 52, ctx.r5.u8);
	// lbz r4,53(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 53);
	// stb r4,53(r10)
	PPC_STORE_U8(ctx.r10.u32 + 53, ctx.r4.u8);
	// lbz r9,54(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 54);
	// stb r9,54(r10)
	PPC_STORE_U8(ctx.r10.u32 + 54, ctx.r9.u8);
	// lbz r8,55(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 55);
	// stb r8,55(r10)
	PPC_STORE_U8(ctx.r10.u32 + 55, ctx.r8.u8);
	// sth r23,60(r10)
	PPC_STORE_U16(ctx.r10.u32 + 60, r23.u16);
	// lhz r5,60(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 60);
	// lwz r4,56(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x821c9650
	ctx.lr = 0x823CB59C;
	sub_821C9650(ctx, base);
	// b 0x823cb694
	goto loc_823CB694;
loc_823CB5A0:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x823cb694
	if (!cr6.eq) goto loc_823CB694;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823cb5dc
	if (cr6.eq) goto loc_823CB5DC;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
loc_823CB5B8:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cb5b8
	if (!cr6.eq) goto loc_823CB5B8;
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cb5e0
	if (!cr6.eq) goto loc_823CB5E0;
loc_823CB5DC:
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
loc_823CB5E0:
	// addi r28,r31,44
	r28.s64 = r31.s64 + 44;
	// lwz r3,17432(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 17432);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x823d3730
	ctx.lr = 0x823CB5F0;
	sub_823D3730(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cb694
	if (cr6.eq) goto loc_823CB694;
	// lwz r11,4(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// beq cr6,0x823cb618
	if (cr6.eq) goto loc_823CB618;
	// stb r18,4(r28)
	PPC_STORE_U8(r28.u32 + 4, r18.u8);
loc_823CB618:
	// addi r30,r31,20
	r30.s64 = r31.s64 + 20;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x823ca430
	ctx.lr = 0x823CB62C;
	sub_823CA430(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cb684
	if (cr6.eq) goto loc_823CB684;
	// lwz r30,0(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823cb65c
	if (cr6.eq) goto loc_823CB65C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a93a8
	ctx.lr = 0x823CB650;
	sub_822A93A8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// bl 0x822aa8d8
	ctx.lr = 0x823CB65C;
	sub_822AA8D8(ctx, base);
loc_823CB65C:
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r9,r10,r26
	ctx.r9.u64 = ctx.r10.u64 + r26.u64;
	// add r3,r27,r11
	ctx.r3.u64 = r27.u64 + r11.u64;
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// sth r8,4(r29)
	PPC_STORE_U16(r29.u32 + 4, ctx.r8.u16);
	// rlwinm r10,r8,6,10,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0x3FFFC0;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x823c9420
	ctx.lr = 0x823CB680;
	sub_823C9420(ctx, base);
	// b 0x823cb694
	goto loc_823CB694;
loc_823CB684:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x823cb694
	if (!cr6.eq) goto loc_823CB694;
	// stw r19,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r19.u32);
loc_823CB694:
	// addic. r20,r20,-1
	xer.ca = r20.u32 > 0;
	r20.s64 = r20.s64 + -1;
	cr0.compare<int32_t>(r20.s32, 0, xer);
	// addi r27,r27,-64
	r27.s64 = r27.s64 + -64;
	// bge 0x823cb484
	if (!cr0.lt) goto loc_823CB484;
loc_823CB6A0:
	// lwz r3,17432(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 17432);
	// bl 0x823d1a90
	ctx.lr = 0x823CB6A8;
	sub_823D1A90(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_823CB6B0"))) PPC_WEAK_FUNC(sub_823CB6B0);
PPC_FUNC_IMPL(__imp__sub_823CB6B0) {
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
	ctx.lr = 0x823CB6B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r3,44
	r30.s64 = ctx.r3.s64 + 44;
	// stw r29,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r29.u32);
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823c95b0
	ctx.lr = 0x823CB6D4;
	sub_823C95B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823cb6e8
	if (cr6.eq) goto loc_823CB6E8;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_823CB6E8:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x823CB6F0;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823cb70c
	if (cr6.eq) goto loc_823CB70C;
	// bl 0x821e2748
	ctx.lr = 0x823CB700;
	sub_821E2748(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// b 0x823cb710
	goto loc_823CB710;
loc_823CB70C:
	// li r31,0
	r31.s64 = 0;
loc_823CB710:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r11,-17636
	ctx.r5.s64 = r11.s64 + -17636;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e2940
	ctx.lr = 0x823CB730;
	sub_821E2940(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823cb758
	if (cr6.eq) goto loc_823CB758;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823ca788
	ctx.lr = 0x823CB74C;
	sub_823CA788(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_823CB758:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823cb77c
	if (cr6.eq) goto loc_823CB77C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82765168
	ctx.lr = 0x823CB76C;
	sub_82765168(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e2a40
	ctx.lr = 0x823CB774;
	sub_821E2A40(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x823CB77C;
	sub_82130588(ctx, base);
loc_823CB77C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823CB788"))) PPC_WEAK_FUNC(sub_823CB788);
PPC_FUNC_IMPL(__imp__sub_823CB788) {
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
	ctx.lr = 0x823CB790;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lhz r31,6(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 6);
	// lwz r28,0(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x823cb7c0
	if (!cr6.gt) goto loc_823CB7C0;
	// addi r30,r28,56
	r30.s64 = r28.s64 + 56;
loc_823CB7AC:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x823CB7B4;
	sub_82130588(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,64
	r30.s64 = r30.s64 + 64;
	// bne 0x823cb7ac
	if (!cr0.eq) goto loc_823CB7AC;
loc_823CB7C0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x823CB7C8;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// sth r11,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r11.u16);
	// sth r11,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r11.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823CB7E0"))) PPC_WEAK_FUNC(sub_823CB7E0);
PPC_FUNC_IMPL(__imp__sub_823CB7E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-16032
	ctx.r9.s64 = ctx.r10.s64 + -16032;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// sth r11,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r11.u16);
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stb r11,19(r3)
	PPC_STORE_U8(ctx.r3.u32 + 19, r11.u8);
	// sth r11,26(r3)
	PPC_STORE_U16(ctx.r3.u32 + 26, r11.u16);
	// sth r11,24(r3)
	PPC_STORE_U16(ctx.r3.u32 + 24, r11.u16);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stb r11,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, r11.u8);
	// sth r11,38(r3)
	PPC_STORE_U16(ctx.r3.u32 + 38, r11.u16);
	// sth r11,36(r3)
	PPC_STORE_U16(ctx.r3.u32 + 36, r11.u16);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// stb r11,43(r3)
	PPC_STORE_U8(ctx.r3.u32 + 43, r11.u8);
	// sth r11,50(r3)
	PPC_STORE_U16(ctx.r3.u32 + 50, r11.u16);
	// sth r11,48(r3)
	PPC_STORE_U16(ctx.r3.u32 + 48, r11.u16);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stb r11,55(r3)
	PPC_STORE_U8(ctx.r3.u32 + 55, r11.u8);
	// sth r11,62(r3)
	PPC_STORE_U16(ctx.r3.u32 + 62, r11.u16);
	// sth r11,60(r3)
	PPC_STORE_U16(ctx.r3.u32 + 60, r11.u16);
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r11.u32);
	// stb r11,67(r3)
	PPC_STORE_U8(ctx.r3.u32 + 67, r11.u8);
	// sth r11,74(r3)
	PPC_STORE_U16(ctx.r3.u32 + 74, r11.u16);
	// sth r11,72(r3)
	PPC_STORE_U16(ctx.r3.u32 + 72, r11.u16);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r11.u32);
	// stb r11,79(r3)
	PPC_STORE_U8(ctx.r3.u32 + 79, r11.u8);
	// sth r11,86(r3)
	PPC_STORE_U16(ctx.r3.u32 + 86, r11.u16);
	// sth r11,84(r3)
	PPC_STORE_U16(ctx.r3.u32 + 84, r11.u16);
	// stw r11,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, r11.u32);
	// stb r11,91(r3)
	PPC_STORE_U8(ctx.r3.u32 + 91, r11.u8);
	// sth r11,98(r3)
	PPC_STORE_U16(ctx.r3.u32 + 98, r11.u16);
	// sth r11,96(r3)
	PPC_STORE_U16(ctx.r3.u32 + 96, r11.u16);
	// stw r11,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r11.u32);
	// stb r11,103(r3)
	PPC_STORE_U8(ctx.r3.u32 + 103, r11.u8);
	// sth r11,110(r3)
	PPC_STORE_U16(ctx.r3.u32 + 110, r11.u16);
	// sth r11,108(r3)
	PPC_STORE_U16(ctx.r3.u32 + 108, r11.u16);
	// stw r11,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, r11.u32);
	// stb r11,115(r3)
	PPC_STORE_U8(ctx.r3.u32 + 115, r11.u8);
	// sth r11,122(r3)
	PPC_STORE_U16(ctx.r3.u32 + 122, r11.u16);
	// sth r11,120(r3)
	PPC_STORE_U16(ctx.r3.u32 + 120, r11.u16);
	// stw r11,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, r11.u32);
	// stb r11,127(r3)
	PPC_STORE_U8(ctx.r3.u32 + 127, r11.u8);
	// sth r11,134(r3)
	PPC_STORE_U16(ctx.r3.u32 + 134, r11.u16);
	// sth r11,132(r3)
	PPC_STORE_U16(ctx.r3.u32 + 132, r11.u16);
	// stw r11,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, r11.u32);
	// stb r11,139(r3)
	PPC_STORE_U8(ctx.r3.u32 + 139, r11.u8);
	// sth r11,146(r3)
	PPC_STORE_U16(ctx.r3.u32 + 146, r11.u16);
	// sth r11,144(r3)
	PPC_STORE_U16(ctx.r3.u32 + 144, r11.u16);
	// stw r11,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, r11.u32);
	// stb r11,151(r3)
	PPC_STORE_U8(ctx.r3.u32 + 151, r11.u8);
	// sth r11,158(r3)
	PPC_STORE_U16(ctx.r3.u32 + 158, r11.u16);
	// sth r11,156(r3)
	PPC_STORE_U16(ctx.r3.u32 + 156, r11.u16);
	// stw r11,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, r11.u32);
	// stb r11,163(r3)
	PPC_STORE_U8(ctx.r3.u32 + 163, r11.u8);
	// sth r11,170(r3)
	PPC_STORE_U16(ctx.r3.u32 + 170, r11.u16);
	// sth r11,168(r3)
	PPC_STORE_U16(ctx.r3.u32 + 168, r11.u16);
	// stw r11,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, r11.u32);
	// stb r11,175(r3)
	PPC_STORE_U8(ctx.r3.u32 + 175, r11.u8);
	// sth r11,182(r3)
	PPC_STORE_U16(ctx.r3.u32 + 182, r11.u16);
	// sth r11,180(r3)
	PPC_STORE_U16(ctx.r3.u32 + 180, r11.u16);
	// stw r11,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, r11.u32);
	// stb r11,187(r3)
	PPC_STORE_U8(ctx.r3.u32 + 187, r11.u8);
	// sth r11,194(r3)
	PPC_STORE_U16(ctx.r3.u32 + 194, r11.u16);
	// sth r11,192(r3)
	PPC_STORE_U16(ctx.r3.u32 + 192, r11.u16);
	// stw r11,188(r3)
	PPC_STORE_U32(ctx.r3.u32 + 188, r11.u32);
	// stb r11,199(r3)
	PPC_STORE_U8(ctx.r3.u32 + 199, r11.u8);
	// sth r11,206(r3)
	PPC_STORE_U16(ctx.r3.u32 + 206, r11.u16);
	// sth r11,204(r3)
	PPC_STORE_U16(ctx.r3.u32 + 204, r11.u16);
	// stw r11,200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 200, r11.u32);
	// stb r11,211(r3)
	PPC_STORE_U8(ctx.r3.u32 + 211, r11.u8);
	// stw r11,212(r3)
	PPC_STORE_U32(ctx.r3.u32 + 212, r11.u32);
	// sth r11,216(r3)
	PPC_STORE_U16(ctx.r3.u32 + 216, r11.u16);
	// sth r11,218(r3)
	PPC_STORE_U16(ctx.r3.u32 + 218, r11.u16);
	// stw r11,220(r3)
	PPC_STORE_U32(ctx.r3.u32 + 220, r11.u32);
	// stw r11,224(r3)
	PPC_STORE_U32(ctx.r3.u32 + 224, r11.u32);
	// stw r11,228(r3)
	PPC_STORE_U32(ctx.r3.u32 + 228, r11.u32);
	// stw r11,232(r3)
	PPC_STORE_U32(ctx.r3.u32 + 232, r11.u32);
	// stw r11,236(r3)
	PPC_STORE_U32(ctx.r3.u32 + 236, r11.u32);
	// stw r11,240(r3)
	PPC_STORE_U32(ctx.r3.u32 + 240, r11.u32);
	// stw r11,244(r3)
	PPC_STORE_U32(ctx.r3.u32 + 244, r11.u32);
	// stw r11,248(r3)
	PPC_STORE_U32(ctx.r3.u32 + 248, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CB934"))) PPC_WEAK_FUNC(sub_823CB934);
PPC_FUNC_IMPL(__imp__sub_823CB934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CB938"))) PPC_WEAK_FUNC(sub_823CB938);
PPC_FUNC_IMPL(__imp__sub_823CB938) {
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
	ctx.lr = 0x823CB940;
	// stwu r1,-944(r1)
	ea = -944 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r31,r11,30576
	r31.s64 = r11.s64 + 30576;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r10,-17600
	ctx.r4.s64 = ctx.r10.s64 + -17600;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r29,0
	r29.s64 = 0;
	// bl 0x821ca540
	ctx.lr = 0x823CB968;
	sub_821CA540(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r9,-6232
	ctx.r5.s64 = ctx.r9.s64 + -6232;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x823CB984;
	sub_821CA6A8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x823cba48
	if (cr6.eq) goto loc_823CBA48;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// li r29,1
	r29.s64 = 1;
	// bl 0x821d1cd0
	ctx.lr = 0x823CB99C;
	sub_821D1CD0(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r11,-17628
	ctx.r4.s64 = r11.s64 + -17628;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821cf7b8
	ctx.lr = 0x823CB9B0;
	sub_821CF7B8(ctx, base);
loc_823CB9B0:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821cffe8
	ctx.lr = 0x823CB9C8;
	sub_821CFFE8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x823cb9b0
	if (cr6.eq) goto loc_823CB9B0;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-27180
	ctx.r4.s64 = r11.s64 + -27180;
	// bl 0x821ca540
	ctx.lr = 0x823CB9E4;
	sub_821CA540(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x823cba2c
	if (!cr6.gt) goto loc_823CBA2C;
loc_823CB9EC:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823cb6b0
	ctx.lr = 0x823CB9F8;
	sub_823CB6B0(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// and r29,r9,r29
	r29.u64 = ctx.r9.u64 & r29.u64;
loc_823CBA08:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821cffe8
	ctx.lr = 0x823CBA20;
	sub_821CFFE8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823cba08
	if (cr6.eq) goto loc_823CBA08;
	// bgt cr6,0x823cb9ec
	if (cr6.gt) goto loc_823CB9EC;
loc_823CBA2C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x823CBA34;
	sub_821C9A90(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821be610
	ctx.lr = 0x823CBA3C;
	sub_821BE610(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-30140
	ctx.r10.s64 = r11.s64 + -30140;
	// stw r10,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r10.u32);
loc_823CBA48:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x823CBA50;
	sub_821C9A90(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,944
	ctx.r1.s64 = ctx.r1.s64 + 944;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823CBA5C"))) PPC_WEAK_FUNC(sub_823CBA5C);
PPC_FUNC_IMPL(__imp__sub_823CBA5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CBA60"))) PPC_WEAK_FUNC(sub_823CBA60);
PPC_FUNC_IMPL(__imp__sub_823CBA60) {
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
	ctx.lr = 0x823CBA68;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17432);
	// bl 0x823cf148
	ctx.lr = 0x823CBA7C;
	sub_823CF148(ctx, base);
	// addi r3,r31,212
	ctx.r3.s64 = r31.s64 + 212;
	// bl 0x823cb788
	ctx.lr = 0x823CBA84;
	sub_823CB788(ctx, base);
	// lwz r30,4(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823cbaa0
	if (cr6.eq) goto loc_823CBAA0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823ca530
	ctx.lr = 0x823CBA98;
	sub_823CA530(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x823CBAA0;
	sub_82130588(ctx, base);
loc_823CBAA0:
	// lwz r30,220(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// li r29,0
	r29.s64 = 0;
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823cbac4
	if (cr6.eq) goto loc_823CBAC4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8246d470
	ctx.lr = 0x823CBABC;
	sub_8246D470(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x823CBAC4;
	sub_82130588(ctx, base);
loc_823CBAC4:
	// stw r29,220(r31)
	PPC_STORE_U32(r31.u32 + 220, r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823CBAD0"))) PPC_WEAK_FUNC(sub_823CBAD0);
PPC_FUNC_IMPL(__imp__sub_823CBAD0) {
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
	ctx.lr = 0x823CBAD8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r3,20
	r30.s64 = ctx.r3.s64 + 20;
	// stw r29,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r29.u32);
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823c95b0
	ctx.lr = 0x823CBAF4;
	sub_823C95B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823cbb08
	if (cr6.eq) goto loc_823CBB08;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_823CBB08:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x823CBB10;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823cbb2c
	if (cr6.eq) goto loc_823CBB2C;
	// bl 0x821e2748
	ctx.lr = 0x823CBB20;
	sub_821E2748(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// b 0x823cbb30
	goto loc_823CBB30;
loc_823CBB2C:
	// li r31,0
	r31.s64 = 0;
loc_823CBB30:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r11,-26428
	ctx.r5.s64 = r11.s64 + -26428;
	// li r6,6
	ctx.r6.s64 = 6;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e2940
	ctx.lr = 0x823CBB50;
	sub_821E2940(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823cbb78
	if (cr6.eq) goto loc_823CBB78;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823ca788
	ctx.lr = 0x823CBB6C;
	sub_823CA788(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_823CBB78:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823cbb9c
	if (cr6.eq) goto loc_823CBB9C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82765168
	ctx.lr = 0x823CBB8C;
	sub_82765168(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e2a40
	ctx.lr = 0x823CBB94;
	sub_821E2A40(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x823CBB9C;
	sub_82130588(ctx, base);
loc_823CBB9C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823CBBA8"))) PPC_WEAK_FUNC(sub_823CBBA8);
PPC_FUNC_IMPL(__imp__sub_823CBBA8) {
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
	ctx.lr = 0x823CBBB0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r3,32
	r30.s64 = ctx.r3.s64 + 32;
	// stw r29,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r29.u32);
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823c95b0
	ctx.lr = 0x823CBBCC;
	sub_823C95B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823cbbe0
	if (cr6.eq) goto loc_823CBBE0;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_823CBBE0:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x823CBBE8;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823cbc04
	if (cr6.eq) goto loc_823CBC04;
	// bl 0x821e2748
	ctx.lr = 0x823CBBF8;
	sub_821E2748(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// b 0x823cbc08
	goto loc_823CBC08;
loc_823CBC04:
	// li r31,0
	r31.s64 = 0;
loc_823CBC08:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r11,-17636
	ctx.r5.s64 = r11.s64 + -17636;
	// li r6,2
	ctx.r6.s64 = 2;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e2940
	ctx.lr = 0x823CBC28;
	sub_821E2940(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823cbc50
	if (cr6.eq) goto loc_823CBC50;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823ca788
	ctx.lr = 0x823CBC44;
	sub_823CA788(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_823CBC50:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823cbc74
	if (cr6.eq) goto loc_823CBC74;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82765168
	ctx.lr = 0x823CBC64;
	sub_82765168(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e2a40
	ctx.lr = 0x823CBC6C;
	sub_821E2A40(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x823CBC74;
	sub_82130588(ctx, base);
loc_823CBC74:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823CBC80"))) PPC_WEAK_FUNC(sub_823CBC80);
PPC_FUNC_IMPL(__imp__sub_823CBC80) {
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
	ctx.lr = 0x823CBC88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r3,56
	r30.s64 = ctx.r3.s64 + 56;
	// stw r29,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r29.u32);
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823c95b0
	ctx.lr = 0x823CBCA4;
	sub_823C95B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823cbcb8
	if (cr6.eq) goto loc_823CBCB8;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_823CBCB8:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x823CBCC0;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823cbcdc
	if (cr6.eq) goto loc_823CBCDC;
	// bl 0x821e2748
	ctx.lr = 0x823CBCD0;
	sub_821E2748(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// b 0x823cbce0
	goto loc_823CBCE0;
loc_823CBCDC:
	// li r31,0
	r31.s64 = 0;
loc_823CBCE0:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r11,-17576
	ctx.r5.s64 = r11.s64 + -17576;
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e2940
	ctx.lr = 0x823CBD00;
	sub_821E2940(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823cbd28
	if (cr6.eq) goto loc_823CBD28;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823ca788
	ctx.lr = 0x823CBD1C;
	sub_823CA788(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_823CBD28:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823cbd4c
	if (cr6.eq) goto loc_823CBD4C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823ca600
	ctx.lr = 0x823CBD3C;
	sub_823CA600(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e2a40
	ctx.lr = 0x823CBD44;
	sub_821E2A40(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x823CBD4C;
	sub_82130588(ctx, base);
loc_823CBD4C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823CBD58"))) PPC_WEAK_FUNC(sub_823CBD58);
PPC_FUNC_IMPL(__imp__sub_823CBD58) {
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
	ctx.lr = 0x823CBD60;
	// stwu r1,-928(r1)
	ea = -928 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r10,-17600
	ctx.r4.s64 = ctx.r10.s64 + -17600;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r31,0
	r31.s64 = 0;
	// bl 0x821ca540
	ctx.lr = 0x823CBD88;
	sub_821CA540(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-6232
	ctx.r5.s64 = ctx.r9.s64 + -6232;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x823CBDA4;
	sub_821CA6A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823cbe48
	if (cr6.eq) goto loc_823CBE48;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// li r31,1
	r31.s64 = 1;
	// bl 0x821d1cd0
	ctx.lr = 0x823CBDBC;
	sub_821D1CD0(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r11,-17568
	ctx.r4.s64 = r11.s64 + -17568;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821cf7b8
	ctx.lr = 0x823CBDD0;
	sub_821CF7B8(ctx, base);
loc_823CBDD0:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821cffe8
	ctx.lr = 0x823CBDE8;
	sub_821CFFE8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823cbdd0
	if (cr6.eq) goto loc_823CBDD0;
	// ble cr6,0x823cbe34
	if (!cr6.gt) goto loc_823CBE34;
loc_823CBDF4:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823cbba8
	ctx.lr = 0x823CBE00;
	sub_823CBBA8(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// and r31,r9,r31
	r31.u64 = ctx.r9.u64 & r31.u64;
loc_823CBE10:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821cffe8
	ctx.lr = 0x823CBE28;
	sub_821CFFE8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823cbe10
	if (cr6.eq) goto loc_823CBE10;
	// bgt cr6,0x823cbdf4
	if (cr6.gt) goto loc_823CBDF4;
loc_823CBE34:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be610
	ctx.lr = 0x823CBE3C;
	sub_821BE610(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-30140
	ctx.r10.s64 = r11.s64 + -30140;
	// stw r10,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r10.u32);
loc_823CBE48:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x823CBE50;
	sub_821C9A90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,928
	ctx.r1.s64 = ctx.r1.s64 + 928;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823CBE5C"))) PPC_WEAK_FUNC(sub_823CBE5C);
PPC_FUNC_IMPL(__imp__sub_823CBE5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CBE60"))) PPC_WEAK_FUNC(sub_823CBE60);
PPC_FUNC_IMPL(__imp__sub_823CBE60) {
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
	ctx.lr = 0x823CBE68;
	// stwu r1,-928(r1)
	ea = -928 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r10,-17600
	ctx.r4.s64 = ctx.r10.s64 + -17600;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r31,0
	r31.s64 = 0;
	// bl 0x821ca540
	ctx.lr = 0x823CBE90;
	sub_821CA540(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-6232
	ctx.r5.s64 = ctx.r9.s64 + -6232;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x823CBEAC;
	sub_821CA6A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823cbf50
	if (cr6.eq) goto loc_823CBF50;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// li r31,1
	r31.s64 = 1;
	// bl 0x821d1cd0
	ctx.lr = 0x823CBEC4;
	sub_821D1CD0(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r11,-17540
	ctx.r4.s64 = r11.s64 + -17540;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821cf7b8
	ctx.lr = 0x823CBED8;
	sub_821CF7B8(ctx, base);
loc_823CBED8:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821cffe8
	ctx.lr = 0x823CBEF0;
	sub_821CFFE8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823cbed8
	if (cr6.eq) goto loc_823CBED8;
	// ble cr6,0x823cbf3c
	if (!cr6.gt) goto loc_823CBF3C;
loc_823CBEFC:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823cbad0
	ctx.lr = 0x823CBF08;
	sub_823CBAD0(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// and r31,r9,r31
	r31.u64 = ctx.r9.u64 & r31.u64;
loc_823CBF18:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821cffe8
	ctx.lr = 0x823CBF30;
	sub_821CFFE8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823cbf18
	if (cr6.eq) goto loc_823CBF18;
	// bgt cr6,0x823cbefc
	if (cr6.gt) goto loc_823CBEFC;
loc_823CBF3C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be610
	ctx.lr = 0x823CBF44;
	sub_821BE610(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-30140
	ctx.r10.s64 = r11.s64 + -30140;
	// stw r10,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r10.u32);
loc_823CBF50:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x823CBF58;
	sub_821C9A90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,928
	ctx.r1.s64 = ctx.r1.s64 + 928;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823CBF64"))) PPC_WEAK_FUNC(sub_823CBF64);
PPC_FUNC_IMPL(__imp__sub_823CBF64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CBF68"))) PPC_WEAK_FUNC(sub_823CBF68);
PPC_FUNC_IMPL(__imp__sub_823CBF68) {
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
	ctx.lr = 0x823CBF70;
	// stwu r1,-928(r1)
	ea = -928 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r10,-17600
	ctx.r4.s64 = ctx.r10.s64 + -17600;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r31,0
	r31.s64 = 0;
	// bl 0x821ca540
	ctx.lr = 0x823CBF98;
	sub_821CA540(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-6232
	ctx.r5.s64 = ctx.r9.s64 + -6232;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x823CBFB4;
	sub_821CA6A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823cc058
	if (cr6.eq) goto loc_823CC058;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// li r31,1
	r31.s64 = 1;
	// bl 0x821d1cd0
	ctx.lr = 0x823CBFCC;
	sub_821D1CD0(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r11,-17512
	ctx.r4.s64 = r11.s64 + -17512;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821cf7b8
	ctx.lr = 0x823CBFE0;
	sub_821CF7B8(ctx, base);
loc_823CBFE0:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821cffe8
	ctx.lr = 0x823CBFF8;
	sub_821CFFE8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823cbfe0
	if (cr6.eq) goto loc_823CBFE0;
	// ble cr6,0x823cc044
	if (!cr6.gt) goto loc_823CC044;
loc_823CC004:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823cbc80
	ctx.lr = 0x823CC010;
	sub_823CBC80(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// and r31,r9,r31
	r31.u64 = ctx.r9.u64 & r31.u64;
loc_823CC020:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x821cffe8
	ctx.lr = 0x823CC038;
	sub_821CFFE8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823cc020
	if (cr6.eq) goto loc_823CC020;
	// bgt cr6,0x823cc004
	if (cr6.gt) goto loc_823CC004;
loc_823CC044:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be610
	ctx.lr = 0x823CC04C;
	sub_821BE610(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-30140
	ctx.r10.s64 = r11.s64 + -30140;
	// stw r10,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r10.u32);
loc_823CC058:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x823CC060;
	sub_821C9A90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,928
	ctx.r1.s64 = ctx.r1.s64 + 928;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823CC06C"))) PPC_WEAK_FUNC(sub_823CC06C);
PPC_FUNC_IMPL(__imp__sub_823CC06C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CC070"))) PPC_WEAK_FUNC(sub_823CC070);
PPC_FUNC_IMPL(__imp__sub_823CC070) {
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
	ctx.lr = 0x823CC078;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,-10996
	ctx.r10.s64 = r11.s64 + -10996;
	// li r3,11416
	ctx.r3.s64 = 11416;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r29,r8,1
	r29.u64 = ctx.r8.u64 ^ 1;
	// bl 0x82130528
	ctx.lr = 0x823CC0A0;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823cc0b4
	if (cr6.eq) goto loc_823CC0B4;
	// bl 0x8246d158
	ctx.lr = 0x823CC0B0;
	sub_8246D158(ctx, base);
	// b 0x823cc0b8
	goto loc_823CC0B8;
loc_823CC0B4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_823CC0B8:
	// stw r3,220(r31)
	PPC_STORE_U32(r31.u32 + 220, ctx.r3.u32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// ori r7,r7,32768
	ctx.r7.u64 = ctx.r7.u64 | 32768;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8246d510
	ctx.lr = 0x823CC0D8;
	sub_8246D510(ctx, base);
	// bl 0x823c9390
	ctx.lr = 0x823CC0DC;
	sub_823C9390(ctx, base);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x823CC0E4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823cc100
	if (cr6.eq) goto loc_823CC100;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r30.u32);
	// stw r30,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r30.u32);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r30.u32);
	// b 0x823cc104
	goto loc_823CC104;
loc_823CC100:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_823CC104:
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// li r4,32
	ctx.r4.s64 = 32;
	// bl 0x823cb260
	ctx.lr = 0x823CC110;
	sub_823CB260(ctx, base);
	// addi r3,r31,212
	ctx.r3.s64 = r31.s64 + 212;
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x823ca5b0
	ctx.lr = 0x823CC11C;
	sub_823CA5B0(ctx, base);
	// li r11,20
	r11.s64 = 20;
	// stw r3,212(r31)
	PPC_STORE_U32(r31.u32 + 212, ctx.r3.u32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// sth r11,218(r31)
	PPC_STORE_U16(r31.u32 + 218, r11.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,-17400
	ctx.r4.s64 = ctx.r10.s64 + -17400;
	// bl 0x823cbd58
	ctx.lr = 0x823CC138;
	sub_823CBD58(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,-17428
	ctx.r4.s64 = ctx.r9.s64 + -17428;
	// bl 0x823cb938
	ctx.lr = 0x823CC148;
	sub_823CB938(ctx, base);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,-17456
	ctx.r4.s64 = ctx.r8.s64 + -17456;
	// bl 0x823cbe60
	ctx.lr = 0x823CC158;
	sub_823CBE60(ctx, base);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,-17484
	ctx.r4.s64 = ctx.r7.s64 + -17484;
	// bl 0x823cbf68
	ctx.lr = 0x823CC168;
	sub_823CBF68(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823CC170"))) PPC_WEAK_FUNC(sub_823CC170);
PPC_FUNC_IMPL(__imp__sub_823CC170) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,16(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CC178"))) PPC_WEAK_FUNC(sub_823CC178);
PPC_FUNC_IMPL(__imp__sub_823CC178) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r11,-10920
	ctx.r9.s64 = r11.s64 + -10920;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r10,-16064
	ctx.r8.s64 = ctx.r10.s64 + -16064;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cntlzw r7,r10
	ctx.r7.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// stb r5,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CC1BC"))) PPC_WEAK_FUNC(sub_823CC1BC);
PPC_FUNC_IMPL(__imp__sub_823CC1BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CC1C0"))) PPC_WEAK_FUNC(sub_823CC1C0);
PPC_FUNC_IMPL(__imp__sub_823CC1C0) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x823cc1e0
	if (!cr6.lt) goto loc_823CC1E0;
	// li r11,0
	r11.s64 = 0;
loc_823CC1E0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CC1E8"))) PPC_WEAK_FUNC(sub_823CC1E8);
PPC_FUNC_IMPL(__imp__sub_823CC1E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fsel f1,f13,f13,f0
	ctx.f1.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CC200"))) PPC_WEAK_FUNC(sub_823CC200);
PPC_FUNC_IMPL(__imp__sub_823CC200) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// li r11,1
	r11.s64 = 1;
	// stw r5,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r5.u32);
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r11,-10952(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10952);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,-10952(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10952, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CC238"))) PPC_WEAK_FUNC(sub_823CC238);
PPC_FUNC_IMPL(__imp__sub_823CC238) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lbz r9,-10964(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -10964);
	// beq cr6,0x823cc26c
	if (cr6.eq) goto loc_823CC26C;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x823cc264
	if (!cr6.eq) goto loc_823CC264;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,-10964(r11)
	PPC_STORE_U8(r11.u32 + -10964, ctx.r10.u8);
	// blr 
	return;
loc_823CC264:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_823CC26C:
	// clrlwi r10,r9,24
	ctx.r10.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,-10964(r11)
	PPC_STORE_U8(r11.u32 + -10964, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CC284"))) PPC_WEAK_FUNC(sub_823CC284);
PPC_FUNC_IMPL(__imp__sub_823CC284) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CC288"))) PPC_WEAK_FUNC(sub_823CC288);
PPC_FUNC_IMPL(__imp__sub_823CC288) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r4,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r4,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r4,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f1,80(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// lwz r11,-10952(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10952);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CC2E8"))) PPC_WEAK_FUNC(sub_823CC2E8);
PPC_FUNC_IMPL(__imp__sub_823CC2E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-10952(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10952);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// addi r11,r3,96
	r11.s64 = ctx.r3.s64 + 96;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,16
	ctx.r8.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r4,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r4,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r4,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f1,160(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 160, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CC330"))) PPC_WEAK_FUNC(sub_823CC330);
PPC_FUNC_IMPL(__imp__sub_823CC330) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
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
	// lfs f0,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	f0.f64 = double(temp.f32);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lfs f13,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f0,-17060(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17060);
	f0.f64 = double(temp.f32);
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f13,f9,f8,f7
	ctx.f13.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x823cc548
	if (!cr6.lt) goto loc_823CC548;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,29464(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 29464);
	f0.f64 = double(temp.f32);
	// lfs f31,14980(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14980);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// stfs f31,0(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// ble cr6,0x823cc470
	if (!cr6.gt) goto loc_823CC470;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v60,v62,135
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x78));
	// vpermwi128 v59,v61,99
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x9C));
	// vor128 v58,v61,v61
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// vpermwi128 v13,v62,99
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x9C));
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// vmulfp128 v12,v60,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v59.f32)));
	// vpermwi128 v0,v58,135
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x78));
	// vnmsubfp v12,v13,v0,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v12,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,0(r5)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f10
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f8,f12,f12,f9
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f9.f64));
	// fmadds f7,f11,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fsqrts f1,f7
	ctx.f1.f64 = double(float(sqrt(ctx.f7.f64)));
	// stfs f1,80(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// beq cr6,0x823cc454
	if (cr6.eq) goto loc_823CC454;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r9,r10,-31664
	ctx.r9.s64 = ctx.r10.s64 + -31664;
	// lvlx128 v57,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v56,v57,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// lvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrefp128 v0,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v56.f32)));
	// vor128 v11,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vnmsubfp v9,v0,v11,v13
	simde_mm_store_ps(ctx.v9.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v8,v0,v9,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v55,v12,v8
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v8.f32)));
	// stvx128 v55,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x823cc440
	if (!cr6.gt) goto loc_823CC440;
	// bl 0x82227d68
	ctx.lr = 0x823CC434;
	sub_82227D68(ctx, base);
	// stfs f1,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823cc54c
	goto loc_823CC54C;
loc_823CC440:
	// bl 0x82227d68
	ctx.lr = 0x823CC444;
	sub_82227D68(ctx, base);
	// fsubs f1,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f31.f64 - ctx.f1.f64));
	// stfs f1,0(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823cc54c
	goto loc_823CC54C;
loc_823CC454:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r10,r11,-31632
	ctx.r10.s64 = r11.s64 + -31632;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// b 0x823cc54c
	goto loc_823CC54C;
loc_823CC470:
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// lfs f0,29460(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 29460);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x823cc494
	if (!cr6.lt) goto loc_823CC494;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r11,r11,-31632
	r11.s64 = r11.s64 + -31632;
	// b 0x823cc4b8
	goto loc_823CC4B8;
loc_823CC494:
	// lfs f13,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fabs f12,f13
	ctx.f12.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x823cc4b0
	if (!cr6.lt) goto loc_823CC4B0;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r11,r11,-31616
	r11.s64 = r11.s64 + -31616;
	// b 0x823cc4b8
	goto loc_823CC4B8;
loc_823CC4B0:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r11,r11,-31600
	r11.s64 = r11.s64 + -31600;
loc_823CC4B8:
	// lvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lvx128 v53,r0,r5
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v52,v54,135
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0x78));
	// vpermwi128 v51,v53,99
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0x9C));
	// vor128 v50,v53,v53
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_load_si128((simde__m128i*)v53.u8));
	// vpermwi128 v13,v54,99
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0x9C));
	// addi r10,r11,2240
	ctx.r10.s64 = r11.s64 + 2240;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// vmulfp128 v12,v52,v51
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v51.f32)));
	// vpermwi128 v0,v50,135
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0x78));
	// addi r7,r9,-31648
	ctx.r7.s64 = ctx.r9.s64 + -31648;
	// addi r6,r8,-31664
	ctx.r6.s64 = ctx.r8.s64 + -31664;
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// addi r3,r4,2528
	ctx.r3.s64 = ctx.r4.s64 + 2528;
	// vnmsubfp v0,v13,v0,v12
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v49,v0,v0
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32), 0xEF));
	// stvx128 v0,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v8,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,1
	ctx.r3.s64 = 1;
	// vrsqrtefp128 v48,v49
	simde_mm_store_ps(v48.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v49.f32))));
	// vor128 v11,v49,v49
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v49.u8));
	// vcmpeqfp128 v10,v48,v62
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v9,v48,v48
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v48.u8));
	// vsel v13,v9,v8,v10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8))));
	// vmulfp128 v7,v13,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v6,v61,v13
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vnmsubfp v5,v11,v7,v12
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v4,v5,v6,v13
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v47,v0,v4
	simde_mm_store_ps(v47.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v4.f32)));
	// stvx128 v47,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823cc54c
	goto loc_823CC54C;
loc_823CC548:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823CC54C:
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

__attribute__((alias("__imp__sub_823CC564"))) PPC_WEAK_FUNC(sub_823CC564);
PPC_FUNC_IMPL(__imp__sub_823CC564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CC568"))) PPC_WEAK_FUNC(sub_823CC568);
PPC_FUNC_IMPL(__imp__sub_823CC568) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,32
	r11.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r9,16
	ctx.r9.s64 = 16;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r31,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r8,2288
	ctx.r5.s64 = ctx.r8.s64 + 2288;
	// lvx128 v61,r31,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v60,v63,v62
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// lvx128 v59,r31,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v58,v63,v62
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrghw128 v57,v59,v61
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// vmrglw128 v56,v59,v61
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// vmrghw128 v55,v60,v57
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmrghw128 v54,v58,v56
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrglw128 v53,v60,v57
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmsum3fp128 v52,v63,v55
	ctx.fpscr.enableFlushMode();
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
	// stvx128 v47,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x823cc330
	ctx.lr = 0x823CC5F4;
	sub_823CC330(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x823cc610
	if (cr6.eq) goto loc_823CC610;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8222f3c8
	ctx.lr = 0x823CC610;
	sub_8222F3C8(ctx, base);
loc_823CC610:
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

__attribute__((alias("__imp__sub_823CC624"))) PPC_WEAK_FUNC(sub_823CC624);
PPC_FUNC_IMPL(__imp__sub_823CC624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CC628"))) PPC_WEAK_FUNC(sub_823CC628);
PPC_FUNC_IMPL(__imp__sub_823CC628) {
	PPC_FUNC_PROLOGUE();
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x823cc694
	if (!cr6.gt) goto loc_823CC694;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x823cc67c
	if (!cr6.lt) goto loc_823CC67C;
	// bl 0x823dcb30
	ctx.lr = 0x823CC65C;
	sub_823DCB30(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f0,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_823CC67C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_823CC694:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,14980(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14980);
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

__attribute__((alias("__imp__sub_823CC6AC"))) PPC_WEAK_FUNC(sub_823CC6AC);
PPC_FUNC_IMPL(__imp__sub_823CC6AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CC6B0"))) PPC_WEAK_FUNC(sub_823CC6B0);
PPC_FUNC_IMPL(__imp__sub_823CC6B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// blt cr6,0x823cc70c
	if (cr6.lt) goto loc_823CC70C;
	// beq cr6,0x823cc6e8
	if (cr6.eq) goto loc_823CC6E8;
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,24(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f11,24(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f10,28(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// blr 
	return;
loc_823CC6E8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f11,20(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f10,28(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// blr 
	return;
loc_823CC70C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,16(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f11,16(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f10,28(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CC730"))) PPC_WEAK_FUNC(sub_823CC730);
PPC_FUNC_IMPL(__imp__sub_823CC730) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f13,28(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// lbz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r8,r8,0,28,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r8,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r8.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CC764"))) PPC_WEAK_FUNC(sub_823CC764);
PPC_FUNC_IMPL(__imp__sub_823CC764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CC768"))) PPC_WEAK_FUNC(sub_823CC768);
PPC_FUNC_IMPL(__imp__sub_823CC768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// lis r9,32640
	ctx.r9.s64 = 2139095040;
	// ori r11,r9,1
	r11.u64 = ctx.r9.u64 | 1;
	// ori r8,r10,16
	ctx.r8.u64 = ctx.r10.u64 | 16;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stb r8,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r8.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CC790"))) PPC_WEAK_FUNC(sub_823CC790);
PPC_FUNC_IMPL(__imp__sub_823CC790) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// li r11,16
	r11.s64 = 16;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm r9,r9,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r9,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CC7B0"))) PPC_WEAK_FUNC(sub_823CC7B0);
PPC_FUNC_IMPL(__imp__sub_823CC7B0) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x823CC7B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x823cc628
	ctx.lr = 0x823CC7CC;
	sub_823CC628(ctx, base);
	// stfs f1,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,0(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f13,4(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,8(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// lfs f1,31292(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31292);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82165300
	ctx.lr = 0x823CC814;
	sub_82165300(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823CC81C"))) PPC_WEAK_FUNC(sub_823CC81C);
PPC_FUNC_IMPL(__imp__sub_823CC81C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CC820"))) PPC_WEAK_FUNC(sub_823CC820);
PPC_FUNC_IMPL(__imp__sub_823CC820) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f29,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f29.u64);
	// stfd f30,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, f30.u64);
	// stfd f31,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f29,f1
	f29.f64 = ctx.f1.f64;
	// bl 0x823cc628
	ctx.lr = 0x823CC848;
	sub_823CC628(ctx, base);
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lfs f1,31292(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31292);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v1,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82165300
	ctx.lr = 0x823CC890;
	sub_82165300(ctx, base);
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f12,32664(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 32664);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f10,f0,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fcmpu cr6,f9,f12
	cr6.compare(ctx.f9.f64, ctx.f12.f64);
	// ble cr6,0x823cc8d4
	if (!cr6.gt) goto loc_823CC8D4;
	// fmuls f0,f30,f30
	f0.f64 = double(float(f30.f64 * f30.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x823cc8d4
	if (!cr6.gt) goto loc_823CC8D4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmuls f1,f30,f29
	ctx.f1.f64 = double(float(f30.f64 * f29.f64));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821bb348
	ctx.lr = 0x823CC8D4;
	sub_821BB348(ctx, base);
loc_823CC8D4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f29,-40(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// lfd f30,-32(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CC8F4"))) PPC_WEAK_FUNC(sub_823CC8F4);
PPC_FUNC_IMPL(__imp__sub_823CC8F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CC8F8"))) PPC_WEAK_FUNC(sub_823CC8F8);
PPC_FUNC_IMPL(__imp__sub_823CC8F8) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x823CC900;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lbz r11,1(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// rlwinm r11,r11,0,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// bne cr6,0x823cca20
	if (!cr6.eq) goto loc_823CCA20;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823CC938;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r5,r31,4
	ctx.r5.s64 = r31.s64 + 4;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823CC954;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r5,r31,8
	ctx.r5.s64 = r31.s64 + 8;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x823CC970;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// addi r5,r31,12
	ctx.r5.s64 = r31.s64 + 12;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823CC98C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f11,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f11
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// lfs f9,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f7,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f7.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfd f0,32224(r10)
	f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + 32224);
	// lfd f13,21560(r9)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r9.u32 + 21560);
	// lfs f12,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f6,f9,f9,f10
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f10.f64));
	// fmadds f5,f8,f8,f6
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f6.f64));
	// fmadds f4,f7,f7,f5
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f5.f64));
	// frsqrte f3,f4
	// fneg f2,f4
	ctx.f2.u64 = ctx.f4.u64 ^ 0x8000000000000000;
	// fmul f1,f3,f3
	ctx.f1.f64 = ctx.f3.f64 * ctx.f3.f64;
	// fmul f10,f3,f0
	ctx.f10.f64 = ctx.f3.f64 * f0.f64;
	// fnmsub f6,f1,f4,f13
	ctx.f6.f64 = -(ctx.f1.f64 * ctx.f4.f64 - ctx.f13.f64);
	// fmadd f5,f6,f10,f3
	ctx.f5.f64 = ctx.f6.f64 * ctx.f10.f64 + ctx.f3.f64;
	// fmul f3,f5,f5
	ctx.f3.f64 = ctx.f5.f64 * ctx.f5.f64;
	// fmul f1,f5,f0
	ctx.f1.f64 = ctx.f5.f64 * f0.f64;
	// fnmsub f0,f3,f4,f13
	f0.f64 = -(ctx.f3.f64 * ctx.f4.f64 - ctx.f13.f64);
	// fmadd f13,f0,f1,f5
	ctx.f13.f64 = f0.f64 * ctx.f1.f64 + ctx.f5.f64;
	// frsp f10,f13
	ctx.f10.f64 = double(float(ctx.f13.f64));
	// fsel f6,f2,f12,f10
	ctx.f6.f64 = ctx.f2.f64 >= 0.0 ? ctx.f12.f64 : ctx.f10.f64;
	// fmuls f5,f9,f6
	ctx.f5.f64 = double(float(ctx.f9.f64 * ctx.f6.f64));
	// stfs f5,0(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// fmuls f4,f11,f6
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f6.f64));
	// stfs f4,4(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// fmuls f3,f8,f6
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f6.f64));
	// stfs f3,8(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// fmuls f2,f7,f6
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f6.f64));
	// stfs f2,12(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_823CCA20:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bne cr6,0x823cca44
	if (!cr6.eq) goto loc_823CCA44;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823CCA38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_823CCA44:
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823CCA50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r29,r31,4
	r29.s64 = r31.s64 + 4;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823CCA70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// addi r28,r31,8
	r28.s64 = r31.s64 + 8;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x823CCA90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f13,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f10,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f9,f13,f13,f11
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fmadds f11,f12,f12,f9
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f9.f64));
	// fcmpu cr6,f11,f10
	cr6.compare(ctx.f11.f64, ctx.f10.f64);
	// ble cr6,0x823ccaf0
	if (!cr6.gt) goto loc_823CCAF0;
	// fsqrts f9,f11
	ctx.f9.f64 = double(float(sqrt(ctx.f11.f64)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f11,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,12(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// fdivs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// fmuls f7,f13,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f8.f64));
	// stfs f7,0(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// fmuls f6,f0,f8
	ctx.f6.f64 = double(float(f0.f64 * ctx.f8.f64));
	// stfs f6,0(r29)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// fmuls f5,f12,f8
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f8.f64));
	// stfs f5,0(r28)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_823CCAF0:
	// fsubs f0,f10,f11
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// fsqrts f13,f0
	ctx.f13.f64 = double(float(sqrt(f0.f64)));
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823CCB08"))) PPC_WEAK_FUNC(sub_823CCB08);
PPC_FUNC_IMPL(__imp__sub_823CCB08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// lhz r11,12(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fdivs f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 / ctx.f12.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x823ccb50
	if (cr6.lt) goto loc_823CCB50;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_823CCB50:
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lwzx r3,r7,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fsubs f1,f1,f12
	ctx.f1.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// bl 0x823cc8f8
	ctx.lr = 0x823CCB7C;
	sub_823CC8F8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CCB8C"))) PPC_WEAK_FUNC(sub_823CCB8C);
PPC_FUNC_IMPL(__imp__sub_823CCB8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CCB90"))) PPC_WEAK_FUNC(sub_823CCB90);
PPC_FUNC_IMPL(__imp__sub_823CCB90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCVRegister v63{};
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
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x823CCBAC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ccc14
	if (cr6.eq) goto loc_823CCC14;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r9,r11,18640
	ctx.r9.s64 = r11.s64 + 18640;
	// li r11,16
	r11.s64 = 16;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r8,r10,-17052
	ctx.r8.s64 = ctx.r10.s64 + -17052;
	// lbz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// stb r7,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r7.u8);
	// lbz r6,5(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// stb r6,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r6.u8);
	// lhz r5,6(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// sth r5,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, ctx.r5.u16);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r4,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
loc_823CCC14:
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

__attribute__((alias("__imp__sub_823CCC2C"))) PPC_WEAK_FUNC(sub_823CCC2C);
PPC_FUNC_IMPL(__imp__sub_823CCC2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CCC30"))) PPC_WEAK_FUNC(sub_823CCC30);
PPC_FUNC_IMPL(__imp__sub_823CCC30) {
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
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// addi r5,r31,16
	ctx.r5.s64 = r31.s64 + 16;
	// bl 0x823ccb08
	ctx.lr = 0x823CCC50;
	sub_823CCB08(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_823CCC74"))) PPC_WEAK_FUNC(sub_823CCC74);
PPC_FUNC_IMPL(__imp__sub_823CCC74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CCC78"))) PPC_WEAK_FUNC(sub_823CCC78);
PPC_FUNC_IMPL(__imp__sub_823CCC78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
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
	// fmr f31,f2
	f31.f64 = ctx.f2.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// lfs f0,8884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x823cce24
	if (!cr6.gt) goto loc_823CCE24;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x823ccb08
	ctx.lr = 0x823CCCB0;
	sub_823CCB08(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,32664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32664);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bge cr6,0x823cce04
	if (!cr6.lt) goto loc_823CCE04;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cce04
	if (!cr6.eq) goto loc_823CCE04;
	// lfs f9,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f9.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,28(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// fmuls f5,f13,f9
	ctx.f5.f64 = double(float(ctx.f13.f64 * ctx.f9.f64));
	// lfs f8,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f8.f64 = double(temp.f32);
	// lfs f11,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f11.f64 = double(temp.f32);
	// lfs f7,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f7.f64 = double(temp.f32);
	// lfs f0,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	f0.f64 = double(temp.f32);
	// lfs f6,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f6.f64 = double(temp.f32);
	// lfs f10,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f10.f64 = double(temp.f32);
	// lfs f12,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f4,f11,f8,f5
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f3,f0,f7,f4
	ctx.f3.f64 = double(float(f0.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fmadds f2,f10,f6,f3
	ctx.f2.f64 = double(float(ctx.f10.f64 * ctx.f6.f64 + ctx.f3.f64));
	// fcmpu cr6,f2,f12
	cr6.compare(ctx.f2.f64, ctx.f12.f64);
	// bge cr6,0x823ccd34
	if (!cr6.lt) goto loc_823CCD34;
	// fneg f0,f0
	f0.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// fneg f10,f10
	ctx.f10.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// stfs f10,4(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// fneg f5,f11
	ctx.f5.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// stfs f5,8(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// fneg f4,f13
	ctx.f4.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f4,12(r11)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
loc_823CCD34:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmuls f10,f6,f31
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f6.f64 * f31.f64));
	// lfs f5,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f9,f31
	ctx.f4.f64 = double(float(ctx.f9.f64 * f31.f64));
	// fmuls f11,f7,f31
	ctx.f11.f64 = double(float(ctx.f7.f64 * f31.f64));
	// lfs f2,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f2.f64 = double(temp.f32);
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f8,f31
	ctx.f6.f64 = double(float(ctx.f8.f64 * f31.f64));
	// lfs f3,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fsubs f1,f0,f31
	ctx.f1.f64 = double(float(f0.f64 - f31.f64));
	// lfd f0,32224(r9)
	f0.u64 = PPC_LOAD_U64(ctx.r9.u32 + 32224);
	// lfd f13,21560(r8)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r8.u32 + 21560);
	// fmadds f10,f5,f1,f10
	ctx.f10.f64 = double(float(ctx.f5.f64 * ctx.f1.f64 + ctx.f10.f64));
	// stfs f10,4(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// fmadds f8,f2,f1,f4
	ctx.f8.f64 = double(float(ctx.f2.f64 * ctx.f1.f64 + ctx.f4.f64));
	// stfs f8,12(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// fmadds f11,f7,f1,f11
	ctx.f11.f64 = double(float(ctx.f7.f64 * ctx.f1.f64 + ctx.f11.f64));
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// fmadds f9,f3,f1,f6
	ctx.f9.f64 = double(float(ctx.f3.f64 * ctx.f1.f64 + ctx.f6.f64));
	// stfs f9,8(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// fmr f4,f10
	ctx.f4.f64 = ctx.f10.f64;
	// fmr f5,f8
	ctx.f5.f64 = ctx.f8.f64;
	// fmr f7,f11
	ctx.f7.f64 = ctx.f11.f64;
	// fmr f6,f9
	ctx.f6.f64 = ctx.f9.f64;
	// fmuls f3,f4,f4
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f4.f64));
	// fmadds f2,f7,f7,f3
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f3.f64));
	// fmadds f1,f6,f6,f2
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f2.f64));
	// fmadds f11,f5,f5,f1
	ctx.f11.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f1.f64));
	// frsqrte f10,f11
	// fneg f9,f11
	ctx.f9.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// fmul f8,f10,f10
	ctx.f8.f64 = ctx.f10.f64 * ctx.f10.f64;
	// fmul f3,f10,f0
	ctx.f3.f64 = ctx.f10.f64 * f0.f64;
	// fnmsub f2,f8,f11,f13
	ctx.f2.f64 = -(ctx.f8.f64 * ctx.f11.f64 - ctx.f13.f64);
	// fmadd f1,f2,f3,f10
	ctx.f1.f64 = ctx.f2.f64 * ctx.f3.f64 + ctx.f10.f64;
	// fmul f10,f1,f1
	ctx.f10.f64 = ctx.f1.f64 * ctx.f1.f64;
	// fmul f8,f1,f0
	ctx.f8.f64 = ctx.f1.f64 * f0.f64;
	// fnmsub f3,f10,f11,f13
	ctx.f3.f64 = -(ctx.f10.f64 * ctx.f11.f64 - ctx.f13.f64);
	// fmadd f2,f3,f8,f1
	ctx.f2.f64 = ctx.f3.f64 * ctx.f8.f64 + ctx.f1.f64;
	// frsp f1,f2
	ctx.f1.f64 = double(float(ctx.f2.f64));
	// fsel f0,f9,f12,f1
	f0.f64 = ctx.f9.f64 >= 0.0 ? ctx.f12.f64 : ctx.f1.f64;
	// fmuls f13,f7,f0
	ctx.f13.f64 = double(float(ctx.f7.f64 * f0.f64));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// fmuls f12,f4,f0
	ctx.f12.f64 = double(float(ctx.f4.f64 * f0.f64));
	// stfs f12,4(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// fmuls f11,f6,f0
	ctx.f11.f64 = double(float(ctx.f6.f64 * f0.f64));
	// stfs f11,8(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// fmuls f10,f5,f0
	ctx.f10.f64 = double(float(ctx.f5.f64 * f0.f64));
	// stfs f10,12(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// b 0x823cce14
	goto loc_823CCE14;
loc_823CCE04:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r10,16
	ctx.r10.s64 = 16;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823CCE14:
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r10.u8);
loc_823CCE24:
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

__attribute__((alias("__imp__sub_823CCE3C"))) PPC_WEAK_FUNC(sub_823CCE3C);
PPC_FUNC_IMPL(__imp__sub_823CCE3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CCE40"))) PPC_WEAK_FUNC(sub_823CCE40);
PPC_FUNC_IMPL(__imp__sub_823CCE40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823CCE48;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823db9d0
	ctx.lr = 0x823CCE50;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f27,f2
	ctx.fpscr.disableFlushMode();
	f27.f64 = ctx.f2.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// lfs f0,8884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f27,f0
	cr6.compare(f27.f64, f0.f64);
	// ble cr6,0x823cd258
	if (!cr6.gt) goto loc_823CD258;
	// lbz r11,1(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// rlwinm r11,r11,0,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
	// lfs f26,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f26.f64 = double(temp.f32);
	// lfs f30,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f30.f64 = double(temp.f32);
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// lfd f28,32224(r8)
	f28.u64 = PPC_LOAD_U64(ctx.r8.u32 + 32224);
	// lfd f29,21560(r7)
	f29.u64 = PPC_LOAD_U64(ctx.r7.u32 + 21560);
	// bne cr6,0x823cd038
	if (!cr6.eq) goto loc_823CD038;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// dcbt r0,r11
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// dcbt r0,r10
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// dcbt r0,r9
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// dcbt r0,r8
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r5,48(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x823CCEE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823CCF00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823CCF20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,48(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x823CCF40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823CCF60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,52(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823CCF84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stfs f1,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,52(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 52);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x823CCFA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stfs f1,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823CCFCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f13,f13
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fmadds f10,f1,f1,f11
	ctx.f10.f64 = double(float(ctx.f1.f64 * ctx.f1.f64 + ctx.f11.f64));
	// fmadds f9,f12,f12,f10
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f10.f64));
	// fmadds f8,f0,f0,f9
	ctx.f8.f64 = double(float(f0.f64 * f0.f64 + ctx.f9.f64));
	// frsqrte f7,f8
	// fmul f5,f7,f7
	ctx.f5.f64 = ctx.f7.f64 * ctx.f7.f64;
	// fmul f4,f7,f28
	ctx.f4.f64 = ctx.f7.f64 * f28.f64;
	// fneg f6,f8
	ctx.f6.u64 = ctx.f8.u64 ^ 0x8000000000000000;
	// fnmsub f3,f5,f8,f29
	ctx.f3.f64 = -(ctx.f5.f64 * ctx.f8.f64 - f29.f64);
	// fmadd f2,f3,f4,f7
	ctx.f2.f64 = ctx.f3.f64 * ctx.f4.f64 + ctx.f7.f64;
	// fmul f11,f2,f2
	ctx.f11.f64 = ctx.f2.f64 * ctx.f2.f64;
	// fmul f10,f2,f28
	ctx.f10.f64 = ctx.f2.f64 * f28.f64;
	// fnmsub f9,f11,f8,f29
	ctx.f9.f64 = -(ctx.f11.f64 * ctx.f8.f64 - f29.f64);
	// fmadd f8,f9,f10,f2
	ctx.f8.f64 = ctx.f9.f64 * ctx.f10.f64 + ctx.f2.f64;
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fsel f6,f6,f30,f7
	ctx.f6.f64 = ctx.f6.f64 >= 0.0 ? f30.f64 : ctx.f7.f64;
	// fmuls f0,f6,f0
	f0.f64 = double(float(ctx.f6.f64 * f0.f64));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f13,f13,f6
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f6.f64));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmuls f12,f12,f6
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f6.f64));
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmuls f11,f1,f6
	ctx.f11.f64 = double(float(ctx.f1.f64 * ctx.f6.f64));
	// b 0x823cd110
	goto loc_823CD110;
loc_823CD038:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bne cr6,0x823cd074
	if (!cr6.eq) goto loc_823CD074;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823CD060;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f11,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// b 0x823cd114
	goto loc_823CD114;
loc_823CD074:
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823CD080;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823CD0A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,36(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x823CD0C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f12,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f12
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fmadds f10,f13,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fmadds f11,f0,f0,f10
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f10.f64));
	// fcmpu cr6,f11,f26
	cr6.compare(ctx.f11.f64, f26.f64);
	// ble cr6,0x823cd108
	if (!cr6.gt) goto loc_823CD108;
	// fsqrts f11,f11
	ctx.f11.f64 = double(float(sqrt(ctx.f11.f64)));
	// fdivs f10,f26,f11
	ctx.f10.f64 = double(float(f26.f64 / ctx.f11.f64));
	// fmr f11,f30
	ctx.f11.f64 = f30.f64;
	// fmuls f0,f0,f10
	f0.f64 = double(float(f0.f64 * ctx.f10.f64));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f13,f13,f10
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmuls f12,f12,f10
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f10.f64));
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// b 0x823cd110
	goto loc_823CD110;
loc_823CD108:
	// fsubs f11,f26,f11
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(f26.f64 - ctx.f11.f64));
	// fsqrts f11,f11
	ctx.f11.f64 = double(float(sqrt(ctx.f11.f64)));
loc_823CD110:
	// stfs f11,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
loc_823CD114:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f10,32664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32664);
	ctx.f10.f64 = double(temp.f32);
	// fcmpu cr6,f27,f10
	cr6.compare(f27.f64, ctx.f10.f64);
	// bge cr6,0x823cd238
	if (!cr6.lt) goto loc_823CD238;
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cd238
	if (!cr6.eq) goto loc_823CD238;
	// lfs f9,24(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 24);
	ctx.f9.f64 = double(temp.f32);
	// addi r11,r29,16
	r11.s64 = r29.s64 + 16;
	// fmuls f6,f9,f12
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// lfs f10,16(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// lfs f8,20(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 20);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,28(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 28);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f5,f10,f0,f6
	ctx.f5.f64 = double(float(ctx.f10.f64 * f0.f64 + ctx.f6.f64));
	// fmadds f4,f8,f13,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f5.f64));
	// fmadds f3,f7,f11,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f11.f64 + ctx.f4.f64));
	// fcmpu cr6,f3,f30
	cr6.compare(ctx.f3.f64, f30.f64);
	// bge cr6,0x823cd180
	if (!cr6.lt) goto loc_823CD180;
	// fneg f10,f10
	ctx.f10.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// stfs f10,0(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// fneg f8,f8
	ctx.f8.u64 = ctx.f8.u64 ^ 0x8000000000000000;
	// stfs f8,4(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// fneg f6,f9
	ctx.f6.u64 = ctx.f9.u64 ^ 0x8000000000000000;
	// stfs f6,8(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// fneg f5,f7
	ctx.f5.u64 = ctx.f7.u64 ^ 0x8000000000000000;
	// stfs f5,12(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
loc_823CD180:
	// fsubs f10,f26,f27
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(f26.f64 - f27.f64));
	// lfs f9,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f7,f0,f27
	ctx.f7.f64 = double(float(f0.f64 * f27.f64));
	// lfs f8,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// lfs f5,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f6,f12,f27
	ctx.f6.f64 = double(float(ctx.f12.f64 * f27.f64));
	// lfs f4,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f10,f9
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f9.f64));
	// fmuls f2,f10,f8
	ctx.f2.f64 = double(float(ctx.f10.f64 * ctx.f8.f64));
	// fmadds f1,f5,f10,f7
	ctx.f1.f64 = double(float(ctx.f5.f64 * ctx.f10.f64 + ctx.f7.f64));
	// stfs f1,0(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// fmadds f0,f4,f10,f6
	f0.f64 = double(float(ctx.f4.f64 * ctx.f10.f64 + ctx.f6.f64));
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// fmadds f13,f13,f27,f3
	ctx.f13.f64 = double(float(ctx.f13.f64 * f27.f64 + ctx.f3.f64));
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// fmadds f12,f11,f27,f2
	ctx.f12.f64 = double(float(ctx.f11.f64 * f27.f64 + ctx.f2.f64));
	// stfs f12,12(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// fmr f11,f1
	ctx.f11.f64 = ctx.f1.f64;
	// fmr f10,f0
	ctx.f10.f64 = f0.f64;
	// fmr f8,f13
	ctx.f8.f64 = ctx.f13.f64;
	// fmr f9,f12
	ctx.f9.f64 = ctx.f12.f64;
	// fmuls f7,f8,f8
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fmadds f6,f11,f11,f7
	ctx.f6.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f7.f64));
	// fmadds f5,f10,f10,f6
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f6.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// frsqrte f3,f4
	// fneg f2,f4
	ctx.f2.u64 = ctx.f4.u64 ^ 0x8000000000000000;
	// fmul f1,f3,f3
	ctx.f1.f64 = ctx.f3.f64 * ctx.f3.f64;
	// fmul f0,f3,f28
	f0.f64 = ctx.f3.f64 * f28.f64;
	// fnmsub f13,f1,f4,f29
	ctx.f13.f64 = -(ctx.f1.f64 * ctx.f4.f64 - f29.f64);
	// fmadd f12,f13,f0,f3
	ctx.f12.f64 = ctx.f13.f64 * f0.f64 + ctx.f3.f64;
	// fmul f7,f12,f12
	ctx.f7.f64 = ctx.f12.f64 * ctx.f12.f64;
	// fmul f6,f12,f28
	ctx.f6.f64 = ctx.f12.f64 * f28.f64;
	// fnmsub f5,f7,f4,f29
	ctx.f5.f64 = -(ctx.f7.f64 * ctx.f4.f64 - f29.f64);
	// fmadd f4,f5,f6,f12
	ctx.f4.f64 = ctx.f5.f64 * ctx.f6.f64 + ctx.f12.f64;
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// fsel f2,f2,f30,f3
	ctx.f2.f64 = ctx.f2.f64 >= 0.0 ? f30.f64 : ctx.f3.f64;
	// fmuls f1,f11,f2
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f2.f64));
	// stfs f1,0(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// fmuls f0,f8,f2
	f0.f64 = double(float(ctx.f8.f64 * ctx.f2.f64));
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// fmuls f13,f10,f2
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f2.f64));
	// stfs f13,8(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// fmuls f12,f9,f2
	ctx.f12.f64 = double(float(ctx.f9.f64 * ctx.f2.f64));
	// stfs f12,12(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// b 0x823cd248
	goto loc_823CD248;
loc_823CD238:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r10,16
	ctx.r10.s64 = 16;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r29,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823CD248:
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,4(r29)
	PPC_STORE_U8(r29.u32 + 4, ctx.r10.u8);
loc_823CD258:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba1c
	ctx.lr = 0x823CD264;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823CD268"))) PPC_WEAK_FUNC(sub_823CD268);
PPC_FUNC_IMPL(__imp__sub_823CD268) {
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
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823CD270;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823cc628
	ctx.lr = 0x823CD290;
	sub_823CC628(ctx, base);
	// fmuls f0,f31,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 * f31.f64));
	// fmuls f13,f1,f1
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f1.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x823cd2e4
	if (!cr6.gt) goto loc_823CD2E4;
	// li r11,16
	r11.s64 = 16;
	// lvx128 v63,r29,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// rlwinm r9,r10,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823cd2d4
	if (cr6.eq) goto loc_823CD2D4;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
	// stb r10,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_823CD2D4:
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r10.u8);
loc_823CD2E4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823CD2F0"))) PPC_WEAK_FUNC(sub_823CD2F0);
PPC_FUNC_IMPL(__imp__sub_823CD2F0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// b 0x823cc820
	sub_823CC820(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823CD2F8"))) PPC_WEAK_FUNC(sub_823CD2F8);
PPC_FUNC_IMPL(__imp__sub_823CD2F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// addi r11,r4,16
	r11.s64 = ctx.r4.s64 + 16;
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// addi r9,r4,4
	ctx.r9.s64 = ctx.r4.s64 + 4;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,4(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// rlwinm r9,r9,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r9,4(r4)
	PPC_STORE_U8(ctx.r4.u32 + 4, ctx.r9.u8);
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// lbz r7,4(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// stb r7,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r7.u8);
	// stb r8,4(r4)
	PPC_STORE_U8(ctx.r4.u32 + 4, ctx.r8.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CD338"))) PPC_WEAK_FUNC(sub_823CD338);
PPC_FUNC_IMPL(__imp__sub_823CD338) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,18640
	ctx.r9.s64 = r11.s64 + 18640;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x823cd36c
	if (cr6.eq) goto loc_823CD36C;
	// bl 0x82130588
	ctx.lr = 0x823CD368;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823CD36C:
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

__attribute__((alias("__imp__sub_823CD380"))) PPC_WEAK_FUNC(sub_823CD380);
PPC_FUNC_IMPL(__imp__sub_823CD380) {
	PPC_FUNC_PROLOGUE();
	// li r3,32
	ctx.r3.s64 = 32;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CD388"))) PPC_WEAK_FUNC(sub_823CD388);
PPC_FUNC_IMPL(__imp__sub_823CD388) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,16(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	f0.f64 = double(temp.f32);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfs f13,16(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CD398"))) PPC_WEAK_FUNC(sub_823CD398);
PPC_FUNC_IMPL(__imp__sub_823CD398) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm r9,r9,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stb r9,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CD3B8"))) PPC_WEAK_FUNC(sub_823CD3B8);
PPC_FUNC_IMPL(__imp__sub_823CD3B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// lis r10,32640
	ctx.r10.s64 = 2139095040;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// ori r9,r11,16
	ctx.r9.u64 = r11.u64 | 16;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// stb r9,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CD3D4"))) PPC_WEAK_FUNC(sub_823CD3D4);
PPC_FUNC_IMPL(__imp__sub_823CD3D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CD3D8"))) PPC_WEAK_FUNC(sub_823CD3D8);
PPC_FUNC_IMPL(__imp__sub_823CD3D8) {
	PPC_FUNC_PROLOGUE();
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CD3E0"))) PPC_WEAK_FUNC(sub_823CD3E0);
PPC_FUNC_IMPL(__imp__sub_823CD3E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// stfs f1,16(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CD3F8"))) PPC_WEAK_FUNC(sub_823CD3F8);
PPC_FUNC_IMPL(__imp__sub_823CD3F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// lhz r11,12(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fdivs f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 / ctx.f12.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x823cd440
	if (cr6.lt) goto loc_823CD440;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_823CD440:
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lwzx r6,r7,r9
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lwz r3,4(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// fsubs f1,f1,f12
	ctx.f1.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// lwz r11,16(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823CD47C;
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

__attribute__((alias("__imp__sub_823CD48C"))) PPC_WEAK_FUNC(sub_823CD48C);
PPC_FUNC_IMPL(__imp__sub_823CD48C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CD490"))) PPC_WEAK_FUNC(sub_823CD490);
PPC_FUNC_IMPL(__imp__sub_823CD490) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x823CD4AC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823cd528
	if (cr6.eq) goto loc_823CD528;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r9,r11,18640
	ctx.r9.s64 = r11.s64 + 18640;
	// addi r8,r10,-16988
	ctx.r8.s64 = ctx.r10.s64 + -16988;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lbz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// stb r7,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r7.u8);
	// lbz r6,5(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// stb r6,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r6.u8);
	// lhz r5,6(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// sth r5,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, ctx.r5.u16);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r4,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lfs f0,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	f0.f64 = double(temp.f32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r8,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r8.u32);
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
loc_823CD528:
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

__attribute__((alias("__imp__sub_823CD540"))) PPC_WEAK_FUNC(sub_823CD540);
PPC_FUNC_IMPL(__imp__sub_823CD540) {
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
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// addi r5,r31,16
	ctx.r5.s64 = r31.s64 + 16;
	// bl 0x823cd3f8
	ctx.lr = 0x823CD560;
	sub_823CD3F8(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_823CD584"))) PPC_WEAK_FUNC(sub_823CD584);
PPC_FUNC_IMPL(__imp__sub_823CD584) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CD588"))) PPC_WEAK_FUNC(sub_823CD588);
PPC_FUNC_IMPL(__imp__sub_823CD588) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f2
	f31.f64 = ctx.f2.f64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x823cd3f8
	ctx.lr = 0x823CD5B0;
	sub_823CD3F8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,32664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32664);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bge cr6,0x823cd5f4
	if (!cr6.lt) goto loc_823CD5F4;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cd5f4
	if (!cr6.eq) goto loc_823CD5F4;
	// lfs f0,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	f0.f64 = double(temp.f32);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// rlwinm r11,r11,0,28,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// fmadds f11,f12,f31,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64 + f0.f64));
	// stfs f11,16(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// b 0x823cd61c
	goto loc_823CD61C;
loc_823CD5F4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,8884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x823cd61c
	if (!cr6.gt) goto loc_823CD61C;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r10.u8);
loc_823CD61C:
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

__attribute__((alias("__imp__sub_823CD634"))) PPC_WEAK_FUNC(sub_823CD634);
PPC_FUNC_IMPL(__imp__sub_823CD634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CD638"))) PPC_WEAK_FUNC(sub_823CD638);
PPC_FUNC_IMPL(__imp__sub_823CD638) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,4(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// fmr f31,f2
	f31.f64 = ctx.f2.f64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823CD66C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,32664(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32664);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bge cr6,0x823cd6b0
	if (!cr6.lt) goto loc_823CD6B0;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cd6b0
	if (!cr6.eq) goto loc_823CD6B0;
	// lfs f0,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	f0.f64 = double(temp.f32);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// rlwinm r11,r11,0,28,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// fmadds f11,f12,f31,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64 + f0.f64));
	// stfs f11,16(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// b 0x823cd6d8
	goto loc_823CD6D8;
loc_823CD6B0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,8884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x823cd6d8
	if (!cr6.gt) goto loc_823CD6D8;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r10.u8);
loc_823CD6D8:
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

__attribute__((alias("__imp__sub_823CD6F0"))) PPC_WEAK_FUNC(sub_823CD6F0);
PPC_FUNC_IMPL(__imp__sub_823CD6F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,16(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	f0.f64 = double(temp.f32);
	// fmuls f13,f1,f1
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f1.f64));
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// blelr cr6
	if (!cr6.gt) return;
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// lbz r11,4(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823cd728
	if (cr6.eq) goto loc_823CD728;
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
	// stb r10,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r10.u8);
	// blr 
	return;
loc_823CD728:
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r10,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CD73C"))) PPC_WEAK_FUNC(sub_823CD73C);
PPC_FUNC_IMPL(__imp__sub_823CD73C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CD740"))) PPC_WEAK_FUNC(sub_823CD740);
PPC_FUNC_IMPL(__imp__sub_823CD740) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r10,4(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// lfs f0,16(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	f0.f64 = double(temp.f32);
	// lfs f13,16(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r4,4
	r11.s64 = ctx.r4.s64 + 4;
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// stfs f0,16(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 16, temp.u32);
	// rlwinm r9,r9,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r9,4(r4)
	PPC_STORE_U8(ctx.r4.u32 + 4, ctx.r9.u8);
	// stfs f13,16(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// lbz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// lbz r7,4(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// stb r7,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r7.u8);
	// stb r8,4(r4)
	PPC_STORE_U8(ctx.r4.u32 + 4, ctx.r8.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CD778"))) PPC_WEAK_FUNC(sub_823CD778);
PPC_FUNC_IMPL(__imp__sub_823CD778) {
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
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-16924
	ctx.r9.s64 = r11.s64 + -16924;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x823cd7ac
	if (cr6.eq) goto loc_823CD7AC;
	// bl 0x82130588
	ctx.lr = 0x823CD7A8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823CD7AC:
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

__attribute__((alias("__imp__sub_823CD7C0"))) PPC_WEAK_FUNC(sub_823CD7C0);
PPC_FUNC_IMPL(__imp__sub_823CD7C0) {
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
	PPCRegister f23{};
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	ctx.lr = 0x823CD7C8;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9c4
	ctx.lr = 0x823CD7D0;
	// li r12,-160
	r12.s64 = -160;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-144
	r12.s64 = -144;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32129
	r27.s64 = -2105606144;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f23,f2
	f23.f64 = ctx.f2.f64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// fmr f28,f3
	f28.f64 = ctx.f3.f64;
	// lfs f0,-21800(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -21800);
	f0.f64 = double(temp.f32);
	// lfs f13,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x823cd810
	if (cr6.gt) goto loc_823CD810;
	// stfs f30,-21800(r27)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r27.u32 + -21800, temp.u32);
loc_823CD810:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// lfd f2,-16912(r11)
	ctx.f2.u64 = PPC_LOAD_U64(r11.u32 + -16912);
	// bl 0x823dc100
	ctx.lr = 0x823CD820;
	sub_823DC100(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lfs f13,-21800(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -21800);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f12,-16916(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -16916);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,3804(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3804);
	f0.f64 = double(temp.f32);
	// fsubs f31,f30,f11
	f31.f64 = double(float(f30.f64 - ctx.f11.f64));
	// fsubs f10,f31,f13
	ctx.f10.f64 = double(float(f31.f64 - ctx.f13.f64));
	// fmr f25,f31
	f25.f64 = f31.f64;
	// fcmpu cr6,f10,f12
	cr6.compare(ctx.f10.f64, ctx.f12.f64);
	// ble cr6,0x823cd850
	if (!cr6.gt) goto loc_823CD850;
	// fadds f31,f13,f0
	f31.f64 = double(float(ctx.f13.f64 + f0.f64));
loc_823CD850:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// fsubs f29,f31,f0
	ctx.fpscr.disableFlushMode();
	f29.f64 = double(float(f31.f64 - f0.f64));
	// li r28,0
	r28.s64 = 0;
	// fadds f26,f25,f0
	f26.f64 = double(float(f25.f64 + f0.f64));
	// addi r10,r11,18800
	ctx.r10.s64 = r11.s64 + 18800;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// stb r28,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, r28.u8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r28,117(r1)
	PPC_STORE_U8(ctx.r1.u32 + 117, r28.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// sth r28,118(r1)
	PPC_STORE_U16(ctx.r1.u32 + 118, r28.u16);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f0,27644(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27644);
	f0.f64 = double(temp.f32);
	// fmuls f24,f28,f0
	f24.f64 = double(float(f28.f64 * f0.f64));
	// bl 0x82503d98
	ctx.lr = 0x823CD898;
	sub_82503D98(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823cd8b8
	if (cr6.eq) goto loc_823CD8B8;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v126,r0,r11
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823cd8c4
	goto loc_823CD8C4;
loc_823CD8B8:
	// vspltisw128 v126,0
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stvx128 v126,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823CD8C4:
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f26
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f26.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82503d98
	ctx.lr = 0x823CD8DC;
	sub_82503D98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cd8fc
	if (cr6.eq) goto loc_823CD8FC;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v126,v126,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v126.f32, simde_mm_sub_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v126,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823CD8FC:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r31,r11,-10960
	r31.s64 = r11.s64 + -10960;
	// lfs f27,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f27.f64 = double(temp.f32);
	// lbz r9,-2(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + -2);
	// fmr f28,f27
	f28.f64 = f27.f64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823cd9c8
	if (!cr6.eq) goto loc_823CD9C8;
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82503d98
	ctx.lr = 0x823CD934;
	sub_82503D98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cd954
	if (cr6.eq) goto loc_823CD954;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823cd960
	goto loc_823CD960;
loc_823CD954:
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823CD960:
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82503d98
	ctx.lr = 0x823CD978;
	sub_82503D98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cd998
	if (cr6.eq) goto loc_823CD998;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v127,v127,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823CD998:
	// vsubfp128 v61,v127,v126
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v126.f32)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lfs f12,-16920(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -16920);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// fmadds f10,f0,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmuls f28,f9,f12
	f28.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
loc_823CD9C8:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// sth r28,150(r1)
	PPC_STORE_U16(ctx.r1.u32 + 150, r28.u16);
	// li r29,1
	r29.s64 = 1;
	// fmr f29,f27
	ctx.fpscr.disableFlushMode();
	f29.f64 = f27.f64;
	// addi r10,r11,-17052
	ctx.r10.s64 = r11.s64 + -17052;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// stb r29,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, r29.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r10,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r29,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, r29.u8);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82503d98
	ctx.lr = 0x823CDA00;
	sub_82503D98(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823cda20
	if (cr6.eq) goto loc_823CDA20;
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823cda30
	goto loc_823CDA30;
loc_823CDA20:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r9,r11,-26256
	ctx.r9.s64 = r11.s64 + -26256;
	// lvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823CDA30:
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f26
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f26.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82503d98
	ctx.lr = 0x823CDA48;
	sub_82503D98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cda64
	if (cr6.eq) goto loc_823CDA64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d59c8
	ctx.lr = 0x823CDA60;
	sub_821D59C8(ctx, base);
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
loc_823CDA64:
	// lfs f0,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// fmuls f12,f23,f23
	ctx.f12.f64 = double(float(f23.f64 * f23.f64));
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// fmadds f10,f0,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmuls f8,f9,f28
	ctx.f8.f64 = double(float(ctx.f9.f64 * f28.f64));
	// fcmpu cr6,f8,f12
	cr6.compare(ctx.f8.f64, ctx.f12.f64);
	// bgt cr6,0x823cda98
	if (cr6.gt) goto loc_823CDA98;
	// fcmpu cr6,f29,f24
	cr6.compare(f29.f64, f24.f64);
	// ble cr6,0x823cdaa0
	if (!cr6.gt) goto loc_823CDAA0;
loc_823CDA98:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// fmr f30,f31
	ctx.fpscr.disableFlushMode();
	f30.f64 = f31.f64;
loc_823CDAA0:
	// lbz r11,-3(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + -3);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cdac0
	if (cr6.eq) goto loc_823CDAC0;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// stb r10,-2(r31)
	PPC_STORE_U8(r31.u32 + -2, ctx.r10.u8);
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stfs f25,-21800(r27)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(r27.u32 + -21800, temp.u32);
	// stfs f30,0(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
loc_823CDAC0:
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// li r0,-160
	r0.s64 = -160;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-144
	r0.s64 = -144;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba10
	ctx.lr = 0x823CDAE0;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823CDAE4"))) PPC_WEAK_FUNC(sub_823CDAE4);
PPC_FUNC_IMPL(__imp__sub_823CDAE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CDAE8"))) PPC_WEAK_FUNC(sub_823CDAE8);
PPC_FUNC_IMPL(__imp__sub_823CDAE8) {
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
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x823CDAF0;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lfs f3,-21688(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -21688);
	ctx.f3.f64 = double(temp.f32);
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lfs f2,-21692(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21692);
	ctx.f2.f64 = double(temp.f32);
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// bl 0x823cd7c0
	ctx.lr = 0x823CDB20;
	sub_823CD7C0(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// li r30,0
	r30.s64 = 0;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// addi r8,r9,18800
	ctx.r8.s64 = ctx.r9.s64 + 18800;
	// stb r30,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, r30.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r30,117(r1)
	PPC_STORE_U8(ctx.r1.u32 + 117, r30.u8);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// sth r30,118(r1)
	PPC_STORE_U16(ctx.r1.u32 + 118, r30.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82503d98
	ctx.lr = 0x823CDB54;
	sub_82503D98(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823cdb70
	if (cr6.eq) goto loc_823CDB70;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r10,48
	ctx.r10.s64 = 48;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r29,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823CDB70:
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// sth r30,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r30.u16);
	// li r11,1
	r11.s64 = 1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r9,r10,-17052
	ctx.r9.s64 = ctx.r10.s64 + -17052;
	// stb r11,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r11.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r11,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, r11.u8);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82503d98
	ctx.lr = 0x823CDBA4;
	sub_82503D98(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823cdbcc
	if (cr6.eq) goto loc_823CDBCC;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821d1d30
	ctx.lr = 0x823CDBCC;
	sub_821D1D30(ctx, base);
loc_823CDBCC:
	// lis r11,-32250
	r11.s64 = -2113536000;
	// sth r30,182(r1)
	PPC_STORE_U16(ctx.r1.u32 + 182, r30.u16);
	// li r28,2
	r28.s64 = 2;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r29,r11,-16988
	r29.s64 = r11.s64 + -16988;
	// li r11,10
	r11.s64 = 10;
	// stb r28,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, r28.u8);
	// stw r29,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r29.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r11,181(r1)
	PPC_STORE_U8(ctx.r1.u32 + 181, r11.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82503d98
	ctx.lr = 0x823CDC04;
	sub_82503D98(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823cdc44
	if (cr6.eq) goto loc_823CDC44;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lfs f13,192(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lfs f0,-16900(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -16900);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f0,-16904(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -16904);
	f0.f64 = double(temp.f32);
	// fdivs f1,f0,f12
	ctx.f1.f64 = double(float(f0.f64 / ctx.f12.f64));
	// bl 0x823dccf0
	ctx.lr = 0x823CDC30;
	sub_823DCCF0(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f0,3732(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f10,0(r27)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
loc_823CDC44:
	// li r11,14
	r11.s64 = 14;
	// stw r29,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r29.u32);
	// stb r28,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, r28.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r11,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, r11.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// sth r30,150(r1)
	PPC_STORE_U16(ctx.r1.u32 + 150, r30.u16);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82503d98
	ctx.lr = 0x823CDC70;
	sub_82503D98(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823cdc84
	if (cr6.eq) goto loc_823CDC84;
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r26)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
loc_823CDC84:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823CDC90"))) PPC_WEAK_FUNC(sub_823CDC90);
PPC_FUNC_IMPL(__imp__sub_823CDC90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r11,20(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823cdcd8
	if (!cr6.eq) goto loc_823CDCD8;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x823cdcd8
	if (cr6.eq) goto loc_823CDCD8;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x823cdcc8
	if (!cr6.lt) goto loc_823CDCC8;
	// li r11,0
	r11.s64 = 0;
loc_823CDCC8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x823cdcdc
	if (!cr6.eq) goto loc_823CDCDC;
loc_823CDCD8:
	// li r11,0
	r11.s64 = 0;
loc_823CDCDC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CDCE4"))) PPC_WEAK_FUNC(sub_823CDCE4);
PPC_FUNC_IMPL(__imp__sub_823CDCE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CDCE8"))) PPC_WEAK_FUNC(sub_823CDCE8);
PPC_FUNC_IMPL(__imp__sub_823CDCE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r11,16
	r11.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
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
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r4,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r4,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r4,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,24(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// b 0x823cdae8
	sub_823CDAE8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823CDD20"))) PPC_WEAK_FUNC(sub_823CDD20);
PPC_FUNC_IMPL(__imp__sub_823CDD20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r11,16
	r11.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
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
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v61,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823cdae8
	sub_823CDAE8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823CDD60"))) PPC_WEAK_FUNC(sub_823CDD60);
PPC_FUNC_IMPL(__imp__sub_823CDD60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
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
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x823CDD68;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
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
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r29,r1,176
	r29.s64 = ctx.r1.s64 + 176;
	// addi r28,r1,128
	r28.s64 = ctx.r1.s64 + 128;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// addi r27,r1,192
	r27.s64 = ctx.r1.s64 + 192;
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// vpermwi128 v58,v62,234
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// vpermwi128 v57,v62,186
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// vpermwi128 v56,v62,174
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x823cdae8
	ctx.lr = 0x823CDDFC;
	sub_823CDAE8(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lfs f0,28636(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28636);
	f0.f64 = double(temp.f32);
	// fadds f1,f31,f0
	ctx.f1.f64 = double(float(f31.f64 + f0.f64));
	// bl 0x823cdae8
	ctx.lr = 0x823CDE1C;
	sub_823CDAE8(ctx, base);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lvx128 v53,r0,r9
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r8
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v51,v52,v53
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v51.f32, simde_mm_sub_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v53.f32)));
	// lfs f0,-16896(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -16896);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v55,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v54,v55,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// vmulfp128 v50,v51,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v50.f32, simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v54.f32)));
	// stvx128 v50,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823CDE5C"))) PPC_WEAK_FUNC(sub_823CDE5C);
PPC_FUNC_IMPL(__imp__sub_823CDE5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CDE60"))) PPC_WEAK_FUNC(sub_823CDE60);
PPC_FUNC_IMPL(__imp__sub_823CDE60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
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
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x823CDE68;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
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
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r29,r1,176
	r29.s64 = ctx.r1.s64 + 176;
	// addi r28,r1,128
	r28.s64 = ctx.r1.s64 + 128;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// addi r27,r1,192
	r27.s64 = ctx.r1.s64 + 192;
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// vpermwi128 v58,v62,234
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// vpermwi128 v57,v62,186
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// vpermwi128 v56,v62,174
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x823cdae8
	ctx.lr = 0x823CDEFC;
	sub_823CDAE8(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lfs f0,28636(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 28636);
	f0.f64 = double(temp.f32);
	// fadds f1,f31,f0
	ctx.f1.f64 = double(float(f31.f64 + f0.f64));
	// bl 0x823cdae8
	ctx.lr = 0x823CDF1C;
	sub_823CDAE8(ctx, base);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lvx128 v53,r0,r9
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r8
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v51,v52,v53
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v51.f32, simde_mm_sub_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v53.f32)));
	// lfs f0,-16896(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -16896);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v55,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v54,v55,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// vmulfp128 v50,v51,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v50.f32, simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v54.f32)));
	// stvx128 v50,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823CDF5C"))) PPC_WEAK_FUNC(sub_823CDF5C);
PPC_FUNC_IMPL(__imp__sub_823CDF5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CDF60"))) PPC_WEAK_FUNC(sub_823CDF60);
PPC_FUNC_IMPL(__imp__sub_823CDF60) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x823CDF68;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lfs f13,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f0,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x823cdfa4
	if (cr6.gt) goto loc_823CDFA4;
	// li r11,0
	r11.s64 = 0;
loc_823CDFA4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cdfbc
	if (cr6.eq) goto loc_823CDFBC;
	// lfs f12,84(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f12,f2,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f2.f64 + f0.f64));
	// stfs f11,0(r29)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
loc_823CDFBC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f31,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x823cdfd8
	if (!cr6.lt) goto loc_823CDFD8;
	// li r11,0
	r11.s64 = 0;
loc_823CDFD8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cdfec
	if (cr6.eq) goto loc_823CDFEC;
	// stfs f13,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// b 0x823cdff8
	goto loc_823CDFF8;
loc_823CDFEC:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f13.f64);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x823cdffc
	if (cr6.gt) goto loc_823CDFFC;
loc_823CDFF8:
	// li r11,0
	r11.s64 = 0;
loc_823CDFFC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ce054
	if (cr6.eq) goto loc_823CE054;
	// lfs f1,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82227ce8
	ctx.lr = 0x823CE010;
	sub_82227CE8(ctx, base);
	// fsubs f13,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f31.f64 - ctx.f1.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r29,16
	ctx.r4.s64 = r29.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f31,f13,f0
	f31.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x821d1f40
	ctx.lr = 0x823CE034;
	sub_821D1F40(ctx, base);
	// lfs f12,80(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f30,f12
	ctx.f11.f64 = double(float(f30.f64 - ctx.f12.f64));
	// fmadds f10,f11,f31,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * f31.f64 + ctx.f12.f64));
	// stfs f10,0(r28)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_823CE054:
	// li r9,16
	ctx.r9.s64 = 16;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,32
	ctx.r10.s64 = 32;
	// li r11,48
	r11.s64 = 48;
	// lvx128 v62,r30,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r30,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r30,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f30,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823CE094"))) PPC_WEAK_FUNC(sub_823CE094);
PPC_FUNC_IMPL(__imp__sub_823CE094) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CE098"))) PPC_WEAK_FUNC(sub_823CE098);
PPC_FUNC_IMPL(__imp__sub_823CE098) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r28{};
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,-10948(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10948);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x823ce250
	if (cr6.gt) goto loc_823CE250;
	// lis r12,-32195
	r12.s64 = -2109931520;
	// addi r12,r12,-7976
	r12.s64 = r12.s64 + -7976;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_823CE0E8;
	case 1:
		goto loc_823CE208;
	case 2:
		goto loc_823CE178;
	case 3:
		goto loc_823CE1A4;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-7960(r28)
	r17.u64 = PPC_LOAD_U32(r28.u32 + -7960);
	// lwz r17,-7672(r28)
	r17.u64 = PPC_LOAD_U32(r28.u32 + -7672);
	// lwz r17,-7816(r28)
	r17.u64 = PPC_LOAD_U32(r28.u32 + -7816);
	// lwz r17,-7772(r28)
	r17.u64 = PPC_LOAD_U32(r28.u32 + -7772);
loc_823CE0E8:
	// lwz r11,-10008(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10008);
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823ce120
	if (!cr6.eq) goto loc_823CE120;
	// lwz r10,-10008(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -10008);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// bne cr6,0x823ce120
	if (!cr6.eq) goto loc_823CE120;
	// li r11,1
	r11.s64 = 1;
	// addi r4,r3,96
	ctx.r4.s64 = ctx.r3.s64 + 96;
	// stw r11,-10948(r31)
	PPC_STORE_U32(r31.u32 + -10948, r11.u32);
	// lfs f1,160(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823cc288
	ctx.lr = 0x823CE11C;
	sub_823CC288(ctx, base);
	// b 0x823ce250
	goto loc_823CE250;
loc_823CE120:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lwz r10,-10952(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10952);
	// bne cr6,0x823ce158
	if (!cr6.eq) goto loc_823CE158;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823ce150
	if (cr6.eq) goto loc_823CE150;
	// li r11,3
	r11.s64 = 3;
	// addi r4,r3,96
	ctx.r4.s64 = ctx.r3.s64 + 96;
	// stw r11,-10948(r31)
	PPC_STORE_U32(r31.u32 + -10948, r11.u32);
	// lfs f1,160(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823cc288
	ctx.lr = 0x823CE14C;
	sub_823CC288(ctx, base);
	// b 0x823ce250
	goto loc_823CE250;
loc_823CE150:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ce250
	if (cr6.eq) goto loc_823CE250;
loc_823CE158:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823ce250
	if (cr6.eq) goto loc_823CE250;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// li r11,2
	r11.s64 = 2;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,-10948(r31)
	PPC_STORE_U32(r31.u32 + -10948, r11.u32);
	// stw r10,-10944(r9)
	PPC_STORE_U32(ctx.r9.u32 + -10944, ctx.r10.u32);
	// b 0x823ce250
	goto loc_823CE250;
loc_823CE178:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r11,-10944(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10944);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,-10944(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10944, r11.u32);
	// bgt 0x823ce250
	if (cr0.gt) goto loc_823CE250;
	// li r11,3
	r11.s64 = 3;
	// addi r4,r3,96
	ctx.r4.s64 = ctx.r3.s64 + 96;
	// stw r11,-10948(r31)
	PPC_STORE_U32(r31.u32 + -10948, r11.u32);
	// lfs f1,160(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823cc288
	ctx.lr = 0x823CE1A0;
	sub_823CC288(ctx, base);
	// b 0x823ce250
	goto loc_823CE250;
loc_823CE1A4:
	// lwz r11,-10008(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10008);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x823ce250
	if (!cr6.eq) goto loc_823CE250;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,1
	r11.s64 = 1;
	// addi r9,r10,17840
	ctx.r9.s64 = ctx.r10.s64 + 17840;
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// stw r11,-10948(r31)
	PPC_STORE_U32(r31.u32 + -10948, r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r10,-10952(r8)
	PPC_STORE_U32(ctx.r8.u32 + -10952, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823ce250
	if (!cr6.eq) goto loc_823CE250;
	// bl 0x82387a18
	ctx.lr = 0x823CE1E0;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ce250
	if (cr6.eq) goto loc_823CE250;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f3,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,25088(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 25088);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x82207ef0
	ctx.lr = 0x823CE204;
	sub_82207EF0(ctx, base);
	// b 0x823ce250
	goto loc_823CE250;
loc_823CE208:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x823ce224
	if (cr6.gt) goto loc_823CE224;
	// li r11,0
	r11.s64 = 0;
loc_823CE224:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823ce250
	if (!cr6.eq) goto loc_823CE250;
	// bl 0x823bbf80
	ctx.lr = 0x823CE234;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823ce250
	if (!cr6.eq) goto loc_823CE250;
	// lwz r10,-10008(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -10008);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,-10948(r31)
	PPC_STORE_U32(r31.u32 + -10948, r11.u32);
	// stw r9,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r9.u32);
loc_823CE250:
	// lwz r11,-10008(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10008);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x823ce274
	if (!cr6.eq) goto loc_823CE274;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x823ce2a4
	if (!cr6.eq) goto loc_823CE2A4;
	// li r10,3
	ctx.r10.s64 = 3;
	// b 0x823ce2a0
	goto loc_823CE2A0;
loc_823CE274:
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x823ce2a4
	if (!cr6.eq) goto loc_823CE2A4;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r10,-10000(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// lbz r9,305(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 305);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823ce2a4
	if (!cr6.eq) goto loc_823CE2A4;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x823ce2a4
	if (!cr6.eq) goto loc_823CE2A4;
	// li r10,2
	ctx.r10.s64 = 2;
loc_823CE2A0:
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
loc_823CE2A4:
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

__attribute__((alias("__imp__sub_823CE2BC"))) PPC_WEAK_FUNC(sub_823CE2BC);
PPC_FUNC_IMPL(__imp__sub_823CE2BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CE2C0"))) PPC_WEAK_FUNC(sub_823CE2C0);
PPC_FUNC_IMPL(__imp__sub_823CE2C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// lfs f1,160(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	ctx.f1.f64 = double(temp.f32);
	// addi r6,r3,96
	ctx.r6.s64 = ctx.r3.s64 + 96;
	// b 0x823cdf60
	sub_823CDF60(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823CE2D0"))) PPC_WEAK_FUNC(sub_823CE2D0);
PPC_FUNC_IMPL(__imp__sub_823CE2D0) {
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
	ctx.lr = 0x823CE300;
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
loc_823CE318:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823ce318
	if (!cr6.eq) goto loc_823CE318;
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
	ctx.lr = 0x823CE340;
	sub_821C9650(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823c9e48
	ctx.lr = 0x823CE34C;
	sub_823C9E48(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
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
	ctx.lr = 0x823CE368;
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
	// beq cr6,0x823ce3a0
	if (cr6.eq) goto loc_823CE3A0;
	// bl 0x82130588
	ctx.lr = 0x823CE388;
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
loc_823CE3A0:
	// bl 0x82130588
	ctx.lr = 0x823CE3A4;
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

__attribute__((alias("__imp__sub_823CE3BC"))) PPC_WEAK_FUNC(sub_823CE3BC);
PPC_FUNC_IMPL(__imp__sub_823CE3BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CE3C0"))) PPC_WEAK_FUNC(sub_823CE3C0);
PPC_FUNC_IMPL(__imp__sub_823CE3C0) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823ce408
	if (cr6.eq) goto loc_823CE408;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823ce408
	if (cr6.eq) goto loc_823CE408;
	// bl 0x823b7b70
	ctx.lr = 0x823CE3F4;
	sub_823B7B70(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x823d5ac0
	ctx.lr = 0x823CE400;
	sub_823D5AC0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r11.u32);
loc_823CE408:
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

__attribute__((alias("__imp__sub_823CE420"))) PPC_WEAK_FUNC(sub_823CE420);
PPC_FUNC_IMPL(__imp__sub_823CE420) {
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
	ctx.lr = 0x823CE428;
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
	ctx.lr = 0x823CE454;
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
loc_823CE46C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823ce46c
	if (!cr6.eq) goto loc_823CE46C;
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
	ctx.lr = 0x823CE494;
	sub_821C9650(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823c9e48
	ctx.lr = 0x823CE4A0;
	sub_823C9E48(ctx, base);
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 4);
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
	ctx.lr = 0x823CE4BC;
	sub_823C9FC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ce4ec
	if (cr6.eq) goto loc_823CE4EC;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r9,r10,-17996
	ctx.r9.s64 = ctx.r10.s64 + -17996;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r11,24(r27)
	PPC_STORE_U32(r27.u32 + 24, r11.u32);
	// bl 0x82130588
	ctx.lr = 0x823CE4E0;
	sub_82130588(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// b 0x823d9244
	return;
loc_823CE4EC:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x823CE500;
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
	ctx.lr = 0x823CE514;
	sub_82507720(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r28,r11,-17996
	r28.s64 = r11.s64 + -17996;
	// beq cr6,0x823ce5a8
	if (cr6.eq) goto loc_823CE5A8;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r29,1
	r29.s64 = 1;
	// addi r3,r11,-16892
	ctx.r3.s64 = r11.s64 + -16892;
	// bl 0x82130000
	ctx.lr = 0x823CE53C;
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
	ctx.lr = 0x823CE570;
	sub_82130000(ctx, base);
	// stw r31,24(r27)
	PPC_STORE_U32(r27.u32 + 24, r31.u32);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137248
	ctx.lr = 0x823CE580;
	sub_82137248(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x823c9db8
	ctx.lr = 0x823CE590;
	sub_823C9DB8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// bl 0x823d4b28
	ctx.lr = 0x823CE59C;
	sub_823D4B28(ctx, base);
	// stw r28,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r28.u32);
	// lwz r3,132(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x82130588
	ctx.lr = 0x823CE5A8;
	sub_82130588(ctx, base);
loc_823CE5A8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x823CE5B0;
	sub_821C9A90(ctx, base);
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r28.u32);
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82130588
	ctx.lr = 0x823CE5BC;
	sub_82130588(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823CE5C8"))) PPC_WEAK_FUNC(sub_823CE5C8);
PPC_FUNC_IMPL(__imp__sub_823CE5C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,112(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ce5e0
	if (cr6.eq) goto loc_823CE5E0;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// b 0x823ce5e4
	goto loc_823CE5E4;
loc_823CE5E0:
	// lwz r10,116(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 116);
loc_823CE5E4:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ce60c
	if (cr6.eq) goto loc_823CE60C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ce600
	if (cr6.eq) goto loc_823CE600;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lfs f1,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_823CE600:
	// lwz r11,116(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 116);
	// lfs f1,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_823CE60C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CE618"))) PPC_WEAK_FUNC(sub_823CE618);
PPC_FUNC_IMPL(__imp__sub_823CE618) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,112(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823ce630
	if (cr6.eq) goto loc_823CE630;
	// lwz r11,16(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// b 0x823ce634
	goto loc_823CE634;
loc_823CE630:
	// lwz r11,116(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 116);
loc_823CE634:
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f1,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// beqlr cr6
	if (cr6.eq) return;
	// lfs f0,120(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 120);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bltlr cr6
	if (cr6.lt) return;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823ce668
	if (cr6.eq) goto loc_823CE668;
	// lwz r11,16(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// lfs f13,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 - f0.f64));
	// blr 
	return;
loc_823CE668:
	// lwz r11,116(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	// lfs f13,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 - f0.f64));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CE678"))) PPC_WEAK_FUNC(sub_823CE678);
PPC_FUNC_IMPL(__imp__sub_823CE678) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
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
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
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
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lfs f0,-26872(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -26872);
	f0.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// lfs f0,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,112(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ce6f0
	if (cr6.eq) goto loc_823CE6F0;
	// lwz r9,16(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// b 0x823ce6f4
	goto loc_823CE6F4;
loc_823CE6F0:
	// lwz r9,116(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 116);
loc_823CE6F4:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823ce740
	if (cr6.eq) goto loc_823CE740;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ce70c
	if (cr6.eq) goto loc_823CE70C;
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// b 0x823ce710
	goto loc_823CE710;
loc_823CE70C:
	// lwz r7,116(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 116);
loc_823CE710:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x823cdae8
	ctx.lr = 0x823CE720;
	sub_823CDAE8(ctx, base);
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
loc_823CE740:
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

__attribute__((alias("__imp__sub_823CE758"))) PPC_WEAK_FUNC(sub_823CE758);
PPC_FUNC_IMPL(__imp__sub_823CE758) {
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
	ctx.lr = 0x823CE760;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r11,112(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ce7cc
	if (cr6.eq) goto loc_823CE7CC;
	// lwz r29,16(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r3,r29,44
	ctx.r3.s64 = r29.s64 + 44;
	// bl 0x821ce100
	ctx.lr = 0x823CE788;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x823ce7b4
	if (!cr6.eq) goto loc_823CE7B4;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x823ce7cc
	if (cr6.eq) goto loc_823CE7CC;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823CE7B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x823ce7cc
	goto loc_823CE7CC;
loc_823CE7B4:
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x823ce7cc
	if (!cr6.eq) goto loc_823CE7CC;
	// lwz r3,-10008(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10008);
	// lwz r4,112(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 112);
	// bl 0x823ce3c0
	ctx.lr = 0x823CE7C8;
	sub_823CE3C0(ctx, base);
	// stw r31,112(r30)
	PPC_STORE_U32(r30.u32 + 112, r31.u32);
loc_823CE7CC:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stw r31,116(r30)
	PPC_STORE_U32(r30.u32 + 116, r31.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// stb r31,289(r11)
	PPC_STORE_U8(r11.u32 + 289, r31.u8);
	// lfs f0,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// stfs f0,-21800(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + -21800, temp.u32);
	// stb r31,290(r11)
	PPC_STORE_U8(r11.u32 + 290, r31.u8);
	// lwz r11,-10008(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10008);
	// stw r31,24(r11)
	PPC_STORE_U32(r11.u32 + 24, r31.u32);
	// lwz r11,-10000(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10000);
	// stb r31,288(r11)
	PPC_STORE_U8(r11.u32 + 288, r31.u8);
	// stfs f0,120(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 120, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823CE810"))) PPC_WEAK_FUNC(sub_823CE810);
PPC_FUNC_IMPL(__imp__sub_823CE810) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x823CE830;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r31,0
	r31.s64 = 0;
	// beq cr6,0x823ce850
	if (cr6.eq) goto loc_823CE850;
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r31.u32);
	// stw r31,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r31.u32);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// stw r31,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r31.u32);
	// b 0x823ce854
	goto loc_823CE854;
loc_823CE850:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823CE854:
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x823cb260
	ctx.lr = 0x823CE860;
	sub_823CB260(ctx, base);
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82130528
	ctx.lr = 0x823CE868;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ce8d0
	if (cr6.eq) goto loc_823CE8D0;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r11,-16924
	ctx.r7.s64 = r11.s64 + -16924;
	// addi r11,r3,80
	r11.s64 = ctx.r3.s64 + 80;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stfs f0,100(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// stw r31,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, r31.u32);
	// stw r31,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r31.u32);
	// stfs f0,96(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// stfs f0,92(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// stfs f0,88(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// stfs f0,100(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// stw r31,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, r31.u32);
	// lfs f13,30280(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 30280);
	ctx.f13.f64 = double(temp.f32);
	// stw r31,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, r31.u32);
	// lfs f12,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,104(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// stfs f12,108(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// stfs f0,120(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// stw r3,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r3.u32);
	// b 0x823ce8d4
	goto loc_823CE8D4;
loc_823CE8D0:
	// stw r31,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r31.u32);
loc_823CE8D4:
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

__attribute__((alias("__imp__sub_823CE8EC"))) PPC_WEAK_FUNC(sub_823CE8EC);
PPC_FUNC_IMPL(__imp__sub_823CE8EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CE8F0"))) PPC_WEAK_FUNC(sub_823CE8F0);
PPC_FUNC_IMPL(__imp__sub_823CE8F0) {
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
	ctx.lr = 0x823CE8F8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r29,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r29.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823ce928
	if (cr6.eq) goto loc_823CE928;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823CE928;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823CE928:
	// lwz r30,4(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823ce948
	if (cr6.eq) goto loc_823CE948;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823ca530
	ctx.lr = 0x823CE940;
	sub_823CA530(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x823CE948;
	sub_82130588(ctx, base);
loc_823CE948:
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823CE954"))) PPC_WEAK_FUNC(sub_823CE954);
PPC_FUNC_IMPL(__imp__sub_823CE954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CE958"))) PPC_WEAK_FUNC(sub_823CE958);
PPC_FUNC_IMPL(__imp__sub_823CE958) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,32
	ctx.r7.s64 = 32;
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
	// li r6,48
	ctx.r6.s64 = 48;
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stw r8,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r8.u32);
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// lfs f0,30280(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 30280);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,104(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// stfs f13,108(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// bl 0x823ce758
	ctx.lr = 0x823CE9C4;
	sub_823CE758(ctx, base);
	// lis r3,-32115
	ctx.r3.s64 = -2104688640;
	// li r11,0
	r11.s64 = 0;
	// stb r11,-10964(r3)
	PPC_STORE_U8(ctx.r3.u32 + -10964, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CE9E0"))) PPC_WEAK_FUNC(sub_823CE9E0);
PPC_FUNC_IMPL(__imp__sub_823CE9E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v21{};
	PPCVRegister v22{};
	PPCVRegister v23{};
	PPCVRegister v24{};
	PPCVRegister v25{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823CE9E8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f0,120(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 120);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x823cea0c
	if (!cr6.lt) goto loc_823CEA0C;
	// li r11,0
	r11.s64 = 0;
loc_823CEA0C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cebd0
	if (cr6.eq) goto loc_823CEBD0;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r31,r30,16
	r31.s64 = r30.s64 + 16;
	// li r10,16
	ctx.r10.s64 = 16;
	// fadds f0,f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 + ctx.f1.f64));
	// li r9,32
	ctx.r9.s64 = 32;
	// stfs f0,120(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 120, temp.u32);
	// li r8,48
	ctx.r8.s64 = 48;
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
	// lis r29,-32115
	r29.s64 = -2104688640;
	// li r11,1
	r11.s64 = 1;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stb r11,-10963(r29)
	PPC_STORE_U8(r29.u32 + -10963, r11.u8);
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v61,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,112(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 112);
	// lfs f1,120(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 120);
	ctx.f1.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cea78
	if (cr6.eq) goto loc_823CEA78;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// b 0x823cea7c
	goto loc_823CEA7C;
loc_823CEA78:
	// lwz r10,116(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 116);
loc_823CEA7C:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823ceaa8
	if (cr6.eq) goto loc_823CEAA8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cea94
	if (cr6.eq) goto loc_823CEA94;
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// b 0x823cea98
	goto loc_823CEA98;
loc_823CEA94:
	// lwz r7,116(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 116);
loc_823CEA98:
	// addi r6,r30,108
	ctx.r6.s64 = r30.s64 + 108;
	// addi r5,r30,104
	ctx.r5.s64 = r30.s64 + 104;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823cdae8
	ctx.lr = 0x823CEAA8;
	sub_823CDAE8(ctx, base);
loc_823CEAA8:
	// li r11,0
	r11.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stb r11,-10963(r29)
	PPC_STORE_U8(r29.u32 + -10963, r11.u8);
	// addi r3,r30,80
	ctx.r3.s64 = r30.s64 + 80;
	// bl 0x823a3f00
	ctx.lr = 0x823CEABC;
	sub_823A3F00(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lbz r10,228(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 228);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cead8
	if (!cr6.eq) goto loc_823CEAD8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823cc568
	ctx.lr = 0x823CEAD8;
	sub_823CC568(ctx, base);
loc_823CEAD8:
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// lvx128 v58,r0,r31
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r31,32
	ctx.r10.s64 = r31.s64 + 32;
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// addi r9,r31,48
	ctx.r9.s64 = r31.s64 + 48;
	// vspltw128 v11,v58,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xAA));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// vspltw128 v10,v58,2
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x55));
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v54,v56,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// lvx128 v53,r0,r9
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v52,v55,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// vspltw128 v9,v53,0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xFF));
	// lvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v8,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v7,v0,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v57.f32)));
	// vmulfp128 v6,v0,v54
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v54.f32)));
	// vspltw128 v5,v56,1
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xAA));
	// vmulfp128 v4,v0,v52
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v52.f32)));
	// vspltw128 v3,v55,1
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xAA));
	// vmaddfp v2,v0,v9,v8
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vspltw128 v1,v53,1
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xAA));
	// lvx128 v13,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// vspltw128 v31,v56,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0x55));
	// vspltw128 v30,v55,2
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x55));
	// vspltw128 v29,v53,2
	simde_mm_store_si128((simde__m128i*)v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0x55));
	// lvx128 v12,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v28,v13,v11,v7
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v27,v13,v5,v6
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v26,v13,v3,v4
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v25,v13,v1,v2
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v24,v12,v10,v28
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(v28.f32)));
	// vmaddfp v23,v12,v31,v27
	simde_mm_store_ps(v23.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v27.f32)));
	// vmaddfp v22,v12,v30,v26
	simde_mm_store_ps(v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(v26.f32)));
	// vmaddfp v21,v12,v29,v25
	simde_mm_store_ps(v21.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v29.f32)), simde_mm_load_ps(v25.f32)));
	// stvx128 v24,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v23,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v22,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v21,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v21.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,112(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823ceb98
	if (cr6.eq) goto loc_823CEB98;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// b 0x823ceb9c
	goto loc_823CEB9C;
loc_823CEB98:
	// lwz r10,116(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 116);
loc_823CEB9C:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823cebd0
	if (cr6.eq) goto loc_823CEBD0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cebb4
	if (cr6.eq) goto loc_823CEBB4;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// b 0x823cebb8
	goto loc_823CEBB8;
loc_823CEBB4:
	// lwz r11,116(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 116);
loc_823CEBB8:
	// lfs f0,120(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 120);
	f0.f64 = double(temp.f32);
	// lfs f13,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x823cebd0
	if (!cr6.gt) goto loc_823CEBD0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823ce758
	ctx.lr = 0x823CEBD0;
	sub_823CE758(ctx, base);
loc_823CEBD0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823CEBD8"))) PPC_WEAK_FUNC(sub_823CEBD8);
PPC_FUNC_IMPL(__imp__sub_823CEBD8) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f13,120(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x823cec04
	if (!cr6.lt) goto loc_823CEC04;
	// li r11,0
	r11.s64 = 0;
loc_823CEC04:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cec28
	if (cr6.eq) goto loc_823CEC28;
	// bl 0x823ce9e0
	ctx.lr = 0x823CEC14;
	sub_823CE9E0(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-10956
	ctx.r10.s64 = r11.s64 + -10956;
	// lfs f13,-10956(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -10956);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	f0.f64 = double(temp.f32);
	// fsubs f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 - ctx.f13.f64));
loc_823CEC28:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CEC38"))) PPC_WEAK_FUNC(sub_823CEC38);
PPC_FUNC_IMPL(__imp__sub_823CEC38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x823CEC40;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stfs f3,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stfs f3,80(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r28,80(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// stw r4,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r4.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// stfs f1,104(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// li r6,16
	ctx.r6.s64 = 16;
	// stfs f2,108(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 108, temp.u32);
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
	// li r9,0
	ctx.r9.s64 = 0;
	// li r5,32
	ctx.r5.s64 = 32;
	// stfs f3,120(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// addi r31,r8,-10962
	r31.s64 = ctx.r8.s64 + -10962;
	// stw r9,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r9.u32);
	// li r30,48
	r30.s64 = 48;
	// stb r9,-10962(r8)
	PPC_STORE_U8(ctx.r8.u32 + -10962, ctx.r9.u8);
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// lis r29,-32129
	r29.s64 = -2105606144;
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// addi r4,r3,80
	ctx.r4.s64 = ctx.r3.s64 + 80;
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// li r8,6
	ctx.r8.s64 = 6;
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// stw r7,6(r31)
	PPC_STORE_U32(r31.u32 + 6, ctx.r7.u32);
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r28,2(r31)
	PPC_STORE_U32(r31.u32 + 2, r28.u32);
	// stvx128 v60,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f3,-21800(r29)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r29.u32 + -21800, temp.u32);
	// stvx128 v63,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_823CECD0:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x823cecd0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823CECD0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823ce9e0
	ctx.lr = 0x823CECF0;
	sub_823CE9E0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823CECF8"))) PPC_WEAK_FUNC(sub_823CECF8);
PPC_FUNC_IMPL(__imp__sub_823CECF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x823CED00;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stfs f3,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stfs f3,80(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r28,80(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// stw r4,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r4.u32);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// stfs f1,104(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// li r6,16
	ctx.r6.s64 = 16;
	// stfs f2,108(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 108, temp.u32);
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
	// li r9,0
	ctx.r9.s64 = 0;
	// li r5,32
	ctx.r5.s64 = 32;
	// stfs f3,120(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// addi r31,r8,-10962
	r31.s64 = ctx.r8.s64 + -10962;
	// stw r9,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r9.u32);
	// li r30,48
	r30.s64 = 48;
	// stb r9,-10962(r8)
	PPC_STORE_U8(ctx.r8.u32 + -10962, ctx.r9.u8);
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// lis r29,-32129
	r29.s64 = -2105606144;
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// addi r4,r3,80
	ctx.r4.s64 = ctx.r3.s64 + 80;
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// li r8,6
	ctx.r8.s64 = 6;
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// stw r7,6(r31)
	PPC_STORE_U32(r31.u32 + 6, ctx.r7.u32);
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r28,2(r31)
	PPC_STORE_U32(r31.u32 + 2, r28.u32);
	// stvx128 v60,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f3,-21800(r29)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r29.u32 + -21800, temp.u32);
	// stvx128 v63,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_823CED90:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x823ced90
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823CED90;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823ce9e0
	ctx.lr = 0x823CEDB0;
	sub_823CE9E0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823CEDB8"))) PPC_WEAK_FUNC(sub_823CEDB8);
PPC_FUNC_IMPL(__imp__sub_823CEDB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823CEDC0;
	// stfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f29.u64);
	// stfd f30,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// fmr f29,f3
	f29.f64 = ctx.f3.f64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823cee04
	if (cr6.eq) goto loc_823CEE04;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823cee04
	if (cr6.eq) goto loc_823CEE04;
	// addi r3,r11,44
	ctx.r3.s64 = r11.s64 + 44;
	// bl 0x821ce0d8
	ctx.lr = 0x823CEE04;
	sub_821CE0D8(ctx, base);
loc_823CEE04:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// fmr f3,f29
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f29.f64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823cec38
	ctx.lr = 0x823CEE20;
	sub_823CEC38(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// stb r10,288(r11)
	PPC_STORE_U8(r11.u32 + 288, ctx.r10.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f30,-48(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823CEE48"))) PPC_WEAK_FUNC(sub_823CEE48);
PPC_FUNC_IMPL(__imp__sub_823CEE48) {
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
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x823cecf8
	ctx.lr = 0x823CEE5C;
	sub_823CECF8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// stb r10,288(r11)
	PPC_STORE_U8(r11.u32 + 288, ctx.r10.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823CEE80"))) PPC_WEAK_FUNC(sub_823CEE80);
PPC_FUNC_IMPL(__imp__sub_823CEE80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// rlwinm r11,r4,0,14,15
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x30000;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823ceebc
	if (cr6.eq) goto loc_823CEEBC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,-7572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822f3918
	ctx.lr = 0x823CEEB0;
	sub_822F3918(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82311450
	ctx.lr = 0x823CEEBC;
	sub_82311450(ctx, base);
loc_823CEEBC:
	// lwz r3,-7572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// bl 0x822f2300
	ctx.lr = 0x823CEEC4;
	sub_822F2300(ctx, base);
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

__attribute__((alias("__imp__sub_823CEED8"))) PPC_WEAK_FUNC(sub_823CEED8);
PPC_FUNC_IMPL(__imp__sub_823CEED8) {
	PPC_FUNC_PROLOGUE();
	// b 0x822e69b0
	sub_822E69B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823CEEDC"))) PPC_WEAK_FUNC(sub_823CEEDC);
PPC_FUNC_IMPL(__imp__sub_823CEEDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CEEE0"))) PPC_WEAK_FUNC(sub_823CEEE0);
PPC_FUNC_IMPL(__imp__sub_823CEEE0) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lwz r11,-10864(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10864);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823cefa8
	if (!cr6.eq) goto loc_823CEFA8;
	// li r3,96
	ctx.r3.s64 = 96;
	// bl 0x82130528
	ctx.lr = 0x823CEF08;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823cef1c
	if (cr6.eq) goto loc_823CEF1C;
	// bl 0x82351038
	ctx.lr = 0x823CEF14;
	sub_82351038(ctx, base);
	// stw r3,-10864(r31)
	PPC_STORE_U32(r31.u32 + -10864, ctx.r3.u32);
	// b 0x823cef24
	goto loc_823CEF24;
loc_823CEF1C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10864(r31)
	PPC_STORE_U32(r31.u32 + -10864, r11.u32);
loc_823CEF24:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-24576
	ctx.r3.s64 = r11.s64 + -24576;
	// bl 0x8218a4e8
	ctx.lr = 0x823CEF34;
	sub_8218A4E8(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r9,-24584
	ctx.r3.s64 = ctx.r9.s64 + -24584;
	// stw r11,-10892(r10)
	PPC_STORE_U32(ctx.r10.u32 + -10892, r11.u32);
	// addi r31,r10,-10892
	r31.s64 = ctx.r10.s64 + -10892;
	// bl 0x8218a4e8
	ctx.lr = 0x823CEF54;
	sub_8218A4E8(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r8,-24592
	ctx.r3.s64 = ctx.r8.s64 + -24592;
	// bl 0x8218a4e8
	ctx.lr = 0x823CEF68;
	sub_8218A4E8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r7,-24600
	ctx.r3.s64 = ctx.r7.s64 + -24600;
	// bl 0x8218a4e8
	ctx.lr = 0x823CEF7C;
	sub_8218A4E8(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r6,-24608
	ctx.r3.s64 = ctx.r6.s64 + -24608;
	// bl 0x8218a4e8
	ctx.lr = 0x823CEF90;
	sub_8218A4E8(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r5,-24616
	ctx.r3.s64 = ctx.r5.s64 + -24616;
	// bl 0x8218a4e8
	ctx.lr = 0x823CEFA4;
	sub_8218A4E8(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
loc_823CEFA8:
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

__attribute__((alias("__imp__sub_823CEFBC"))) PPC_WEAK_FUNC(sub_823CEFBC);
PPC_FUNC_IMPL(__imp__sub_823CEFBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CEFC0"))) PPC_WEAK_FUNC(sub_823CEFC0);
PPC_FUNC_IMPL(__imp__sub_823CEFC0) {
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
	// addi r9,r11,-16528
	ctx.r9.s64 = r11.s64 + -16528;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x823CEFF8;
	sub_822E5148(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,17432(r8)
	PPC_STORE_U32(ctx.r8.u32 + 17432, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x823CF00C;
	sub_822E6940(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823cf024
	if (cr6.eq) goto loc_823CF024;
	// bl 0x82130588
	ctx.lr = 0x823CF020;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823CF024:
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

__attribute__((alias("__imp__sub_823CF03C"))) PPC_WEAK_FUNC(sub_823CF03C);
PPC_FUNC_IMPL(__imp__sub_823CF03C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CF040"))) PPC_WEAK_FUNC(sub_823CF040);
PPC_FUNC_IMPL(__imp__sub_823CF040) {
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
	ctx.lr = 0x823CF058;
	sub_822E6B38(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r10,531
	ctx.r10.s64 = 34799616;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r11,-16528
	ctx.r8.s64 = r11.s64 + -16528;
	// ori r7,r10,14304
	ctx.r7.u64 = ctx.r10.u64 | 14304;
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
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,-8092(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8092);
	// bl 0x822e5138
	ctx.lr = 0x823CF08C;
	sub_822E5138(ctx, base);
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// addi r4,r5,-16504
	ctx.r4.s64 = ctx.r5.s64 + -16504;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x823CF0A0;
	sub_821C8ED8(ctx, base);
	// bl 0x823ceee0
	ctx.lr = 0x823CF0A4;
	sub_823CEEE0(ctx, base);
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

__attribute__((alias("__imp__sub_823CF0BC"))) PPC_WEAK_FUNC(sub_823CF0BC);
PPC_FUNC_IMPL(__imp__sub_823CF0BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CF0C0"))) PPC_WEAK_FUNC(sub_823CF0C0);
PPC_FUNC_IMPL(__imp__sub_823CF0C0) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r30,-32115
	r30.s64 = -2104688640;
	// addi r10,r11,-16504
	ctx.r10.s64 = r11.s64 + -16504;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,-10864(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10864);
	// bl 0x82130588
	ctx.lr = 0x823CF0F0;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,-10864(r30)
	PPC_STORE_U32(r30.u32 + -10864, r11.u32);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82130000
	ctx.lr = 0x823CF100;
	sub_82130000(ctx, base);
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// addi r7,r9,-16528
	ctx.r7.s64 = ctx.r9.s64 + -16528;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// lwz r3,-8092(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x823CF11C;
	sub_822E5148(ctx, base);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,17432(r6)
	PPC_STORE_U32(ctx.r6.u32 + 17432, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x823CF130;
	sub_822E6940(ctx, base);
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

__attribute__((alias("__imp__sub_823CF148"))) PPC_WEAK_FUNC(sub_823CF148);
PPC_FUNC_IMPL(__imp__sub_823CF148) {
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
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c8f08
	ctx.lr = 0x823CF16C;
	sub_821C8F08(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823cf198
	if (cr6.eq) goto loc_823CF198;
loc_823CF178:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823CF18C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823cf178
	if (!cr6.eq) goto loc_823CF178;
loc_823CF198:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c8f70
	ctx.lr = 0x823CF1A0;
	sub_821C8F70(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r11,17432(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17432);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// lwz r3,17432(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17432);
	// lwz r7,12(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x823cf1d8
	if (!cr6.eq) goto loc_823CF1D8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823CF1D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823CF1D8:
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

__attribute__((alias("__imp__sub_823CF1F0"))) PPC_WEAK_FUNC(sub_823CF1F0);
PPC_FUNC_IMPL(__imp__sub_823CF1F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r10,-31280
	ctx.r4.s64 = ctx.r10.s64 + -31280;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x823CF21C;
	sub_8217C088(ctx, base);
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r3,-7572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// bl 0x822f21e8
	ctx.lr = 0x823CF228;
	sub_822F21E8(ctx, base);
	// rlwinm r9,r30,0,11,15
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1F0000;
	// rlwinm r9,r9,0,14,11
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFF3FFFF;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x823cf2cc
	if (cr6.eq) goto loc_823CF2CC;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lbz r10,-11756(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -11756);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823cf2b8
	if (cr6.eq) goto loc_823CF2B8;
	// lwz r3,-7572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x823CF250;
	sub_82205248(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823cf2b8
	if (!cr6.eq) goto loc_823CF2B8;
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lwz r3,-8092(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8092);
	// bl 0x822e5c10
	ctx.lr = 0x823CF268;
	sub_822E5C10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r4,0
	ctx.r4.s64 = 0;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x82311450
	ctx.lr = 0x823CF27C;
	sub_82311450(ctx, base);
	// lwz r3,-8092(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8092);
	// bl 0x822e5c10
	ctx.lr = 0x823CF284;
	sub_822E5C10(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823cf2a4
	if (cr6.eq) goto loc_823CF2A4;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r3,-7572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// lfs f1,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822f3918
	ctx.lr = 0x823CF2A0;
	sub_822F3918(ctx, base);
	// b 0x823cf2cc
	goto loc_823CF2CC;
loc_823CF2A4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,-7572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822f3918
	ctx.lr = 0x823CF2B4;
	sub_822F3918(ctx, base);
	// b 0x823cf2cc
	goto loc_823CF2CC;
loc_823CF2B8:
	// lwz r3,-7572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x823CF2C0;
	sub_82205248(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82311450
	ctx.lr = 0x823CF2CC;
	sub_82311450(ctx, base);
loc_823CF2CC:
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

__attribute__((alias("__imp__sub_823CF2E4"))) PPC_WEAK_FUNC(sub_823CF2E4);
PPC_FUNC_IMPL(__imp__sub_823CF2E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CF2E8"))) PPC_WEAK_FUNC(sub_823CF2E8);
PPC_FUNC_IMPL(__imp__sub_823CF2E8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// addi r5,r11,-27188
	ctx.r5.s64 = r11.s64 + -27188;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x823CF314;
	sub_82137A08(ctx, base);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821ca778
	ctx.lr = 0x823CF328;
	sub_821CA778(ctx, base);
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

__attribute__((alias("__imp__sub_823CF33C"))) PPC_WEAK_FUNC(sub_823CF33C);
PPC_FUNC_IMPL(__imp__sub_823CF33C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CF340"))) PPC_WEAK_FUNC(sub_823CF340);
PPC_FUNC_IMPL(__imp__sub_823CF340) {
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
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
	// addi r9,r4,8
	ctx.r9.s64 = ctx.r4.s64 + 8;
	// addi r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 4;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lbz r7,4(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// stb r7,4(r31)
	PPC_STORE_U8(r31.u32 + 4, ctx.r7.u8);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// sth r11,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r11.u16);
	// sth r11,18(r31)
	PPC_STORE_U16(r31.u32 + 18, r11.u16);
	// lbz r6,8(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// stb r6,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r6.u8);
	// lbz r5,9(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 9);
	// stb r5,9(r31)
	PPC_STORE_U8(r31.u32 + 9, ctx.r5.u8);
	// lbz r10,10(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 10);
	// stb r10,10(r31)
	PPC_STORE_U8(r31.u32 + 10, ctx.r10.u8);
	// lbz r9,11(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 11);
	// stb r9,11(r31)
	PPC_STORE_U8(r31.u32 + 11, ctx.r9.u8);
	// sth r11,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r11.u16);
	// lhz r5,16(r4)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r4.u32 + 16);
	// lwz r4,12(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// bl 0x821c9650
	ctx.lr = 0x823CF3B0;
	sub_821C9650(ctx, base);
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

__attribute__((alias("__imp__sub_823CF3C8"))) PPC_WEAK_FUNC(sub_823CF3C8);
PPC_FUNC_IMPL(__imp__sub_823CF3C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// lhz r11,76(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 76);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cf424
	if (cr6.eq) goto loc_823CF424;
	// lwz r11,72(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
loc_823CF3E8:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,16(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823cf410
	if (cr6.eq) goto loc_823CF410;
	// lwz r8,132(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bge cr6,0x823cf45c
	if (!cr6.lt) goto loc_823CF45C;
	// lbz r10,129(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 129);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cf45c
	if (!cr6.eq) goto loc_823CF45C;
loc_823CF410:
	// lhz r10,76(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 76);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x823cf3e8
	if (cr6.lt) goto loc_823CF3E8;
loc_823CF424:
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// bne 0x823cf45c
	if (!cr0.eq) goto loc_823CF45C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823CF448;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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
loc_823CF45C:
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

__attribute__((alias("__imp__sub_823CF470"))) PPC_WEAK_FUNC(sub_823CF470);
PPC_FUNC_IMPL(__imp__sub_823CF470) {
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
	// lhz r9,76(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 76);
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x823cf4d0
	if (!cr6.gt) goto loc_823CF4D0;
	// lwz r10,72(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
loc_823CF498:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r3,16(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823cf4c0
	if (cr6.eq) goto loc_823CF4C0;
	// lwz r7,132(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// bne cr6,0x823cf4c0
	if (!cr6.eq) goto loc_823CF4C0;
	// lbz r7,129(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 129);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823cf4e4
	if (cr6.eq) goto loc_823CF4E4;
loc_823CF4C0:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x823cf498
	if (cr6.lt) goto loc_823CF498;
loc_823CF4D0:
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
loc_823CF4E4:
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// bl 0x823a09c0
	ctx.lr = 0x823CF4EC;
	sub_823A09C0(ctx, base);
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

__attribute__((alias("__imp__sub_823CF500"))) PPC_WEAK_FUNC(sub_823CF500);
PPC_FUNC_IMPL(__imp__sub_823CF500) {
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
	// lhz r9,76(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 76);
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x823cf560
	if (!cr6.gt) goto loc_823CF560;
	// lwz r10,72(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
loc_823CF528:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r3,16(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823cf550
	if (cr6.eq) goto loc_823CF550;
	// lwz r7,132(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// bne cr6,0x823cf550
	if (!cr6.eq) goto loc_823CF550;
	// lbz r7,129(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 129);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823cf574
	if (cr6.eq) goto loc_823CF574;
loc_823CF550:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x823cf528
	if (cr6.lt) goto loc_823CF528;
loc_823CF560:
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
loc_823CF574:
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// bl 0x8239fc48
	ctx.lr = 0x823CF57C;
	sub_8239FC48(ctx, base);
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

__attribute__((alias("__imp__sub_823CF590"))) PPC_WEAK_FUNC(sub_823CF590);
PPC_FUNC_IMPL(__imp__sub_823CF590) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// lhz r9,76(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 76);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x823cf5e4
	if (!cr6.gt) goto loc_823CF5E4;
	// lwz r11,72(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
loc_823CF5B8:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r3,16(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823cf5d4
	if (cr6.eq) goto loc_823CF5D4;
	// lwz r8,132(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r8,r5
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r5.s32, xer);
	// beq cr6,0x823cf5fc
	if (cr6.eq) goto loc_823CF5FC;
loc_823CF5D4:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x823cf5b8
	if (cr6.lt) goto loc_823CF5B8;
loc_823CF5E4:
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
loc_823CF5FC:
	// bl 0x8239fcb8
	ctx.lr = 0x823CF600;
	sub_8239FCB8(ctx, base);
	// stfs f1,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
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
}

__attribute__((alias("__imp__sub_823CF61C"))) PPC_WEAK_FUNC(sub_823CF61C);
PPC_FUNC_IMPL(__imp__sub_823CF61C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CF620"))) PPC_WEAK_FUNC(sub_823CF620);
PPC_FUNC_IMPL(__imp__sub_823CF620) {
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
	ctx.lr = 0x823CF628;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,76(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cf694
	if (cr6.eq) goto loc_823CF694;
	// li r31,0
	r31.s64 = 0;
loc_823CF64C:
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r3,16(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823cf680
	if (cr6.eq) goto loc_823CF680;
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// bne cr6,0x823cf680
	if (!cr6.eq) goto loc_823CF680;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823CF680;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823CF680:
	// lhz r11,76(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 76);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x823cf64c
	if (cr6.lt) goto loc_823CF64C;
loc_823CF694:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823CF69C"))) PPC_WEAK_FUNC(sub_823CF69C);
PPC_FUNC_IMPL(__imp__sub_823CF69C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CF6A0"))) PPC_WEAK_FUNC(sub_823CF6A0);
PPC_FUNC_IMPL(__imp__sub_823CF6A0) {
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
	ctx.lr = 0x823CF6A8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,76(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cf700
	if (cr6.eq) goto loc_823CF700;
	// li r31,0
	r31.s64 = 0;
loc_823CF6C4:
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r3,16(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823cf6ec
	if (cr6.eq) goto loc_823CF6EC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823CF6EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823CF6EC:
	// lhz r11,76(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 76);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x823cf6c4
	if (cr6.lt) goto loc_823CF6C4;
loc_823CF700:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823CF708"))) PPC_WEAK_FUNC(sub_823CF708);
PPC_FUNC_IMPL(__imp__sub_823CF708) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x823CF710;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// mr r28,r27
	r28.u64 = r27.u64;
	// lhz r11,76(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cf824
	if (cr6.eq) goto loc_823CF824;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r29,r27
	r29.u64 = r27.u64;
	// addi r26,r11,-10820
	r26.s64 = r11.s64 + -10820;
loc_823CF738:
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// lwzx r10,r29,r11
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// lwz r31,16(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823cf7e0
	if (cr6.eq) goto loc_823CF7E0;
	// lbz r11,129(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 129);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cf7e0
	if (cr6.eq) goto loc_823CF7E0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823CF76C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,4(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823cf7ac
	if (!cr6.eq) goto loc_823CF7AC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823CF790;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,36(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// bl 0x8239e6a0
	ctx.lr = 0x823CF7A0;
	sub_8239E6A0(ctx, base);
	// lwz r9,72(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// lwzx r8,r29,r9
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + ctx.r9.u32);
	// stw r27,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, r27.u32);
loc_823CF7AC:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// bne 0x823cf7d8
	if (!cr0.eq) goto loc_823CF7D8;
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
	ctx.lr = 0x823CF7D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x823cf7e0
	goto loc_823CF7E0;
loc_823CF7D8:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x823cf7fc
	if (cr6.eq) goto loc_823CF7FC;
loc_823CF7E0:
	// lhz r11,76(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 76);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x823cf738
	if (cr6.lt) goto loc_823CF738;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_823CF7FC:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// bne 0x823cf824
	if (!cr0.eq) goto loc_823CF824;
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
	ctx.lr = 0x823CF824;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823CF824:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823CF82C"))) PPC_WEAK_FUNC(sub_823CF82C);
PPC_FUNC_IMPL(__imp__sub_823CF82C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CF830"))) PPC_WEAK_FUNC(sub_823CF830);
PPC_FUNC_IMPL(__imp__sub_823CF830) {
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
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x823CF838;
	// addi r12,r1,-88
	r12.s64 = ctx.r1.s64 + -88;
	// bl 0x823db9d4
	ctx.lr = 0x823CF840;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r23,0
	r23.s64 = 0;
	// lhz r11,76(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cf9e0
	if (cr6.eq) goto loc_823CF9E0;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lfs f27,-31384(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31384);
	f27.f64 = double(temp.f32);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lfs f30,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f30.f64 = double(temp.f32);
	// lfs f31,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r30,0
	r30.s64 = 0;
	// lfs f28,-6684(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -6684);
	f28.f64 = double(temp.f32);
	// li r26,272
	r26.s64 = 272;
	// lfs f29,-13028(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -13028);
	f29.f64 = double(temp.f32);
	// li r27,128
	r27.s64 = 128;
	// lis r22,-32111
	r22.s64 = -2104426496;
	// lis r24,-32115
	r24.s64 = -2104688640;
	// addi r28,r11,29952
	r28.s64 = r11.s64 + 29952;
	// addi r25,r10,-10840
	r25.s64 = ctx.r10.s64 + -10840;
loc_823CF8A4:
	// lwz r11,72(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r31,16(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823cf9cc
	if (cr6.eq) goto loc_823CF9CC;
	// lbz r11,129(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 129);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823cf9cc
	if (!cr6.eq) goto loc_823CF9CC;
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x823cf9cc
	if (cr6.lt) goto loc_823CF9CC;
	// lbz r10,-29347(r22)
	ctx.r10.u64 = PPC_LOAD_U8(r22.u32 + -29347);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823cf9cc
	if (!cr6.eq) goto loc_823CF9CC;
	// bl 0x8269a1b0
	ctx.lr = 0x823CF8E0;
	sub_8269A1B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823cf9cc
	if (!cr6.eq) goto loc_823CF9CC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8239fe08
	ctx.lr = 0x823CF8F4;
	sub_8239FE08(ctx, base);
	// lwz r31,96(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a86e8
	ctx.lr = 0x823CF900;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cf9cc
	if (cr6.eq) goto loc_823CF9CC;
	// lwz r31,48(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823cf9cc
	if (cr6.eq) goto loc_823CF9CC;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823cf9cc
	if (cr6.eq) goto loc_823CF9CC;
	// lwz r11,4(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823cf964
	if (!cr6.eq) goto loc_823CF964;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82332098
	ctx.lr = 0x823CF938;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cf964
	if (cr6.eq) goto loc_823CF964;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f0,224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f29
	ctx.f13.f64 = double(float(f0.f64 * f29.f64));
	// fmuls f12,f13,f28
	ctx.f12.f64 = double(float(ctx.f13.f64 * f28.f64));
	// fsel f11,f12,f12,f31
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f12.f64 : f31.f64;
	// fsubs f10,f11,f30
	ctx.f10.f64 = double(float(ctx.f11.f64 - f30.f64));
	// fsel f0,f10,f30,f11
	f0.f64 = ctx.f10.f64 >= 0.0 ? f30.f64 : ctx.f11.f64;
	// b 0x823cf968
	goto loc_823CF968;
loc_823CF964:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
loc_823CF968:
	// lwz r11,-12640(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -12640);
	// fmuls f13,f0,f27
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f0.f64 * f27.f64));
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823cf98c
	if (cr6.eq) goto loc_823CF98C;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x823cf990
	if (cr6.eq) goto loc_823CF990;
loc_823CF98C:
	// li r11,0
	r11.s64 = 0;
loc_823CF990:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cf9a0
	if (cr6.eq) goto loc_823CF9A0;
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f31.f64;
loc_823CF9A0:
	// lwz r11,72(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// lfs f12,8(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwzx r9,r30,r11
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r8,128(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	// lfs f11,112(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f12,f13,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f10,112(r9)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r9.u32 + 112, temp.u32);
	// stfs f0,116(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 116, temp.u32);
	// lvx128 v63,r8,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823CF9CC:
	// lhz r11,76(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 76);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// blt cr6,0x823cf8a4
	if (cr6.lt) goto loc_823CF8A4;
loc_823CF9E0:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-88
	r12.s64 = ctx.r1.s64 + -88;
	// bl 0x823dba20
	ctx.lr = 0x823CF9EC;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_823CF9F0"))) PPC_WEAK_FUNC(sub_823CF9F0);
PPC_FUNC_IMPL(__imp__sub_823CF9F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823CF9F8;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,76(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cfa58
	if (cr6.eq) goto loc_823CFA58;
	// li r31,0
	r31.s64 = 0;
loc_823CFA1C:
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r3,16(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823cfa44
	if (cr6.eq) goto loc_823CFA44;
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x823cfa44
	if (cr6.lt) goto loc_823CFA44;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823a4360
	ctx.lr = 0x823CFA44;
	sub_823A4360(ctx, base);
loc_823CFA44:
	// lhz r11,76(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 76);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x823cfa1c
	if (cr6.lt) goto loc_823CFA1C;
loc_823CFA58:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823CFA64"))) PPC_WEAK_FUNC(sub_823CFA64);
PPC_FUNC_IMPL(__imp__sub_823CFA64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CFA68"))) PPC_WEAK_FUNC(sub_823CFA68);
PPC_FUNC_IMPL(__imp__sub_823CFA68) {
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
	// lhz r9,76(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 76);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x823cfab4
	if (!cr6.gt) goto loc_823CFAB4;
	// lwz r11,72(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
loc_823CFA88:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r3,16(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823cfaa4
	if (cr6.eq) goto loc_823CFAA4;
	// lwz r8,132(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r8,r5
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r5.s32, xer);
	// beq cr6,0x823cfac8
	if (cr6.eq) goto loc_823CFAC8;
loc_823CFAA4:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x823cfa88
	if (cr6.lt) goto loc_823CFA88;
loc_823CFAB4:
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
loc_823CFAC8:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823CFAD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_823CFAEC"))) PPC_WEAK_FUNC(sub_823CFAEC);
PPC_FUNC_IMPL(__imp__sub_823CFAEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CFAF0"))) PPC_WEAK_FUNC(sub_823CFAF0);
PPC_FUNC_IMPL(__imp__sub_823CFAF0) {
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
	ctx.lr = 0x823CFAF8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,76(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cfb70
	if (cr6.eq) goto loc_823CFB70;
	// li r31,0
	r31.s64 = 0;
loc_823CFB14:
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// lwzx r11,r11,r31
	r11.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823cfb5c
	if (cr6.eq) goto loc_823CFB5C;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823cfb5c
	if (cr6.eq) goto loc_823CFB5C;
	// bl 0x8239f8d8
	ctx.lr = 0x823CFB34;
	sub_8239F8D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cfb5c
	if (cr6.eq) goto loc_823CFB5C;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r3,16(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823CFB5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823CFB5C:
	// lhz r11,76(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 76);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x823cfb14
	if (cr6.lt) goto loc_823CFB14;
loc_823CFB70:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823CFB78"))) PPC_WEAK_FUNC(sub_823CFB78);
PPC_FUNC_IMPL(__imp__sub_823CFB78) {
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
	ctx.lr = 0x823CFB80;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,76(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 76);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cfbd0
	if (cr6.eq) goto loc_823CFBD0;
	// li r31,0
	r31.s64 = 0;
loc_823CFB9C:
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// lwzx r11,r11,r31
	r11.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823cfbbc
	if (cr6.eq) goto loc_823CFBBC;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823cfbbc
	if (cr6.eq) goto loc_823CFBBC;
	// bl 0x8239f900
	ctx.lr = 0x823CFBBC;
	sub_8239F900(ctx, base);
loc_823CFBBC:
	// lhz r11,76(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 76);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x823cfb9c
	if (cr6.lt) goto loc_823CFB9C;
loc_823CFBD0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823CFBD8"))) PPC_WEAK_FUNC(sub_823CFBD8);
PPC_FUNC_IMPL(__imp__sub_823CFBD8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822e6f68
	ctx.lr = 0x823CFBF4;
	sub_822E6F68(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-16476
	ctx.r10.s64 = r11.s64 + -16476;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// addi r7,r9,2272
	ctx.r7.s64 = ctx.r9.s64 + 2272;
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// li r6,128
	ctx.r6.s64 = 128;
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// li r3,816
	ctx.r3.s64 = 816;
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// stw r30,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r30.u32);
	// stw r30,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r30.u32);
	// stw r30,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r30.u32);
	// stw r30,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r30.u32);
	// stw r30,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r30.u32);
	// stfs f0,112(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stfs f0,116(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82130528
	ctx.lr = 0x823CFC84;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823cfc94
	if (cr6.eq) goto loc_823CFC94;
	// bl 0x822f15e0
	ctx.lr = 0x823CFC90;
	sub_822F15E0(ctx, base);
	// b 0x823cfc98
	goto loc_823CFC98;
loc_823CFC94:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_823CFC98:
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// li r3,304
	ctx.r3.s64 = 304;
	// bl 0x82130528
	ctx.lr = 0x823CFCA4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823cfcbc
	if (cr6.eq) goto loc_823CFCBC;
	// bl 0x82351310
	ctx.lr = 0x823CFCB0;
	sub_82351310(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// b 0x823cfcc0
	goto loc_823CFCC0;
loc_823CFCBC:
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
loc_823CFCC0:
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

__attribute__((alias("__imp__sub_823CFCDC"))) PPC_WEAK_FUNC(sub_823CFCDC);
PPC_FUNC_IMPL(__imp__sub_823CFCDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823CFCE0"))) PPC_WEAK_FUNC(sub_823CFCE0);
PPC_FUNC_IMPL(__imp__sub_823CFCE0) {
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
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x823CFCE8;
	// stfd f30,-136(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -136, f30.u64);
	// stfd f31,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, f31.u64);
	// addi r12,r1,-144
	r12.s64 = ctx.r1.s64 + -144;
	// bl 0x823dd534
	ctx.lr = 0x823CFCF8;
	// stwu r1,-592(r1)
	ea = -592 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d0638
	if (cr6.eq) goto loc_823D0638;
	// lwz r20,188(r11)
	r20.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x823d0638
	if (cr6.eq) goto loc_823D0638;
	// lwz r11,24(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 24);
	// lbz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 28);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r19,r8,1
	r19.u64 = ctx.r8.u64 ^ 1;
	// bne cr6,0x823cff50
	if (!cr6.eq) goto loc_823CFF50;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x8239f620
	ctx.lr = 0x823CFD3C;
	sub_8239F620(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lwz r18,8(r3)
	r18.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r10,r31,32
	ctx.r10.s64 = r31.s64 + 32;
	// addi r30,r11,-16316
	r30.s64 = r11.s64 + -16316;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82193af8
	ctx.lr = 0x823CFD60;
	sub_82193AF8(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// addi r29,r11,-16340
	r29.s64 = r11.s64 + -16340;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82193af8
	ctx.lr = 0x823CFD7C;
	sub_82193AF8(ctx, base);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// addi r28,r11,-16364
	r28.s64 = r11.s64 + -16364;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82193af8
	ctx.lr = 0x823CFD98;
	sub_82193AF8(ctx, base);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// addi r27,r11,-16388
	r27.s64 = r11.s64 + -16388;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82193af8
	ctx.lr = 0x823CFDB4;
	sub_82193AF8(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// addi r26,r11,-16408
	r26.s64 = r11.s64 + -16408;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82193af8
	ctx.lr = 0x823CFDD0;
	sub_82193AF8(ctx, base);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// addi r25,r11,-16424
	r25.s64 = r11.s64 + -16424;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x82193af8
	ctx.lr = 0x823CFDEC;
	sub_82193AF8(ctx, base);
	// stw r3,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r3.u32);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// addi r24,r11,-16444
	r24.s64 = r11.s64 + -16444;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x82193af8
	ctx.lr = 0x823CFE08;
	sub_82193AF8(ctx, base);
	// stw r3,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r3.u32);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// addi r23,r11,-16456
	r23.s64 = r11.s64 + -16456;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x82193af8
	ctx.lr = 0x823CFE24;
	sub_82193AF8(ctx, base);
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// addi r22,r11,-24232
	r22.s64 = r11.s64 + -24232;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x82193af8
	ctx.lr = 0x823CFE40;
	sub_82193AF8(ctx, base);
	// stw r3,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r3.u32);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r21,r11,-24252
	r21.s64 = r11.s64 + -24252;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// bl 0x82193af8
	ctx.lr = 0x823CFE5C;
	sub_82193AF8(ctx, base);
	// clrlwi r9,r19,24
	ctx.r9.u64 = r19.u32 & 0xFF;
	// stw r3,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r3.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823cff48
	if (cr6.eq) goto loc_823CFF48;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x8218f5b0
	ctx.lr = 0x823CFE74;
	sub_8218F5B0(ctx, base);
	// lwz r20,8(r3)
	r20.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r11,r31,72
	r11.s64 = r31.s64 + 72;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82193af8
	ctx.lr = 0x823CFE90;
	sub_82193AF8(ctx, base);
	// stw r3,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82193af8
	ctx.lr = 0x823CFEA4;
	sub_82193AF8(ctx, base);
	// stw r3,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82193af8
	ctx.lr = 0x823CFEB8;
	sub_82193AF8(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82193af8
	ctx.lr = 0x823CFECC;
	sub_82193AF8(ctx, base);
	// stw r3,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82193af8
	ctx.lr = 0x823CFEE0;
	sub_82193AF8(ctx, base);
	// stw r3,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82193af8
	ctx.lr = 0x823CFEF4;
	sub_82193AF8(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82193af8
	ctx.lr = 0x823CFF08;
	sub_82193AF8(ctx, base);
	// stw r3,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82193af8
	ctx.lr = 0x823CFF1C;
	sub_82193AF8(ctx, base);
	// stw r3,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r3.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82193af8
	ctx.lr = 0x823CFF30;
	sub_82193AF8(ctx, base);
	// stw r3,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r3.u32);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82193af8
	ctx.lr = 0x823CFF44;
	sub_82193AF8(ctx, base);
	// stw r3,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r3.u32);
loc_823CFF48:
	// li r11,0
	r11.s64 = 0;
	// stb r11,28(r31)
	PPC_STORE_U8(r31.u32 + 28, r11.u8);
loc_823CFF50:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r24,0
	r24.s64 = 0;
	// lwz r30,96(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a86e8
	ctx.lr = 0x823CFF64;
	sub_822A86E8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lfs f30,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f30.f64 = double(temp.f32);
	// beq cr6,0x823d0530
	if (cr6.eq) goto loc_823D0530;
	// lwz r27,48(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x823d0530
	if (cr6.eq) goto loc_823D0530;
	// lwz r11,132(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d0530
	if (cr6.eq) goto loc_823D0530;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d0530
	if (cr6.eq) goto loc_823D0530;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d0530
	if (cr6.eq) goto loc_823D0530;
	// lwz r11,76(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 76);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d0530
	if (cr6.eq) goto loc_823D0530;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r24,1
	r24.s64 = 1;
	// lbz r10,147(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 147);
	// lwz r3,188(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823cffe4
	if (cr6.eq) goto loc_823CFFE4;
	// clrlwi r11,r19,24
	r11.u64 = r19.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823cffe4
	if (cr6.eq) goto loc_823CFFE4;
	// bl 0x8218f5b0
	ctx.lr = 0x823CFFDC;
	sub_8218F5B0(ctx, base);
	// addi r28,r31,72
	r28.s64 = r31.s64 + 72;
	// b 0x823cffec
	goto loc_823CFFEC;
loc_823CFFE4:
	// bl 0x8239f620
	ctx.lr = 0x823CFFE8;
	sub_8239F620(ctx, base);
	// addi r28,r31,32
	r28.s64 = r31.s64 + 32;
loc_823CFFEC:
	// lwz r25,132(r27)
	r25.u64 = PPC_LOAD_U32(r27.u32 + 132);
	// li r10,96
	ctx.r10.s64 = 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// lwz r26,8(r3)
	r26.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// lvx128 v63,r25,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x823d0018
	if (!cr6.eq) goto loc_823D0018;
	// li r11,0
	r11.s64 = 0;
loc_823D0018:
	// lfs f0,408(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 408);
	f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f13,268(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 268);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,372(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 372);
	ctx.f11.f64 = double(temp.f32);
	// lwz r4,4(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// fmuls f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v62,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmulfp128 v60,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x823d007c
	if (cr6.eq) goto loc_823D007C;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,208(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f13,212(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f12,216(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f30,220(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// bl 0x82192a88
	ctx.lr = 0x823D007C;
	sub_82192A88(ctx, base);
loc_823D007C:
	// lwz r11,76(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 76);
	// li r29,72
	r29.s64 = 72;
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,160
	ctx.r10.s64 = 160;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r8,96(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// addi r11,r27,208
	r11.s64 = r27.s64 + 208;
	// lbzx r7,r29,r30
	ctx.r7.u64 = PPC_LOAD_U8(r29.u32 + r30.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lvx128 v59,r8,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x823d00b0
	if (!cr6.eq) goto loc_823D00B0;
	// addi r11,r27,144
	r11.s64 = r27.s64 + 144;
loc_823D00B0:
	// li r10,48
	ctx.r10.s64 = 48;
	// lvx128 v126,r0,r11
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// lvx128 v125,r11,r10
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,32
	ctx.r5.s64 = 32;
	// lvlx128 v58,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v57,v125,v125
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_load_si128((simde__m128i*)v125.u8));
	// vspltw128 v56,v58,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// lvlx128 v55,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v54,v55,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// lvx128 v124,r11,r7
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v53,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// vspltw128 v52,v53,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xFF));
	// lvx128 v127,r11,r5
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v57,v126,v56,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v56.f32)), simde_mm_load_ps(v57.f32)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// stvx128 v125,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v57,v124,v54,v57
	simde_mm_store_ps(v57.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v54.f32)), simde_mm_load_ps(v57.f32)));
	// vmaddfp128 v57,v127,v52,v57
	simde_mm_store_ps(v57.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v52.f32)), simde_mm_load_ps(v57.f32)));
	// stvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x823d0144
	if (cr6.eq) goto loc_823D0144;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,256(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stfs f13,260(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f12,264(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stfs f30,268(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// bl 0x82192a88
	ctx.lr = 0x823D0144;
	sub_82192A88(ctx, base);
loc_823D0144:
	// lwz r11,76(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 76);
	// li r10,144
	ctx.r10.s64 = 144;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lwz r4,8(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// addi r8,r1,116
	ctx.r8.s64 = ctx.r1.s64 + 116;
	// addi r7,r1,120
	ctx.r7.s64 = ctx.r1.s64 + 120;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lwz r5,96(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// lvx128 v51,r5,r10
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v50,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v49,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v48,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v47,v48,0
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xFF));
	// vmaddfp128 v125,v126,v47,v125
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v125.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v47.f32)), simde_mm_load_ps(v125.f32)));
	// vspltw128 v46,v50,0
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// vspltw128 v45,v49,0
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0xFF));
	// vmaddfp128 v125,v124,v46,v125
	simde_mm_store_ps(v125.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v46.f32)), simde_mm_load_ps(v125.f32)));
	// vmaddfp128 v125,v127,v45,v125
	simde_mm_store_ps(v125.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v45.f32)), simde_mm_load_ps(v125.f32)));
	// stvx128 v125,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x823d01c8
	if (cr6.eq) goto loc_823D01C8;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
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
	// stfs f30,188(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// bl 0x82192a88
	ctx.lr = 0x823D01C8;
	sub_82192A88(ctx, base);
loc_823D01C8:
	// lwz r4,16(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x823d01f0
	if (cr6.eq) goto loc_823D01F0;
	// vspltisw128 v44,0
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,304
	r11.s64 = ctx.r1.s64 + 304;
	// addi r5,r1,304
	ctx.r5.s64 = ctx.r1.s64 + 304;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// vsubfp128 v43,v44,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v43.f32, simde_mm_sub_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v127.f32)));
	// stvx128 v43,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82192960
	ctx.lr = 0x823D01F0;
	sub_82192960(ctx, base);
loc_823D01F0:
	// lbzx r10,r29,r30
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + r30.u32);
	// addi r11,r27,208
	r11.s64 = r27.s64 + 208;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823d0208
	if (!cr6.eq) goto loc_823D0208;
	// addi r11,r27,144
	r11.s64 = r27.s64 + 144;
	// beq cr6,0x823d0210
	if (cr6.eq) goto loc_823D0210;
loc_823D0208:
	// addi r10,r27,208
	ctx.r10.s64 = r27.s64 + 208;
	// b 0x823d0214
	goto loc_823D0214;
loc_823D0210:
	// addi r10,r27,144
	ctx.r10.s64 = r27.s64 + 144;
loc_823D0214:
	// lfs f0,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	f0.f64 = double(temp.f32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stfs f0,144(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lfs f13,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lfs f12,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,152(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lfs f11,52(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,48(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,56(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f6.f64));
	// fmadds f4,f11,f10,f5
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f5.f64));
	// lfs f0,-332(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -332);
	f0.f64 = double(temp.f32);
	// fmadds f3,f9,f8,f4
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f4.f64));
	// fadds f2,f3,f0
	ctx.f2.f64 = double(float(ctx.f3.f64 + f0.f64));
	// stfs f2,156(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// bl 0x82332098
	ctx.lr = 0x823D026C;
	sub_82332098(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823d0284
	if (cr6.eq) goto loc_823D0284;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f0,-13544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13544);
	f0.f64 = double(temp.f32);
	// stfs f0,156(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
loc_823D0284:
	// lwz r4,20(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x823d029c
	if (cr6.eq) goto loc_823D029C;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82192a88
	ctx.lr = 0x823D029C;
	sub_82192A88(ctx, base);
loc_823D029C:
	// lwz r4,28(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x823d02c4
	if (cr6.eq) goto loc_823D02C4;
	// lfs f0,112(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	f0.f64 = double(temp.f32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lfs f13,116(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stfs f0,160(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// bl 0x821928d0
	ctx.lr = 0x823D02C4;
	sub_821928D0(ctx, base);
loc_823D02C4:
	// li r11,128
	r11.s64 = 128;
	// vspltisw128 v42,0
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lfs f11,372(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	ctx.f11.f64 = double(temp.f32);
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lfs f10,376(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 376);
	ctx.f10.f64 = double(temp.f32);
	// addi r8,r10,2528
	ctx.r8.s64 = ctx.r10.s64 + 2528;
	// lwz r4,24(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// addi r7,r9,2240
	ctx.r7.s64 = ctx.r9.s64 + 2240;
	// lfs f9,368(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 368);
	ctx.f9.f64 = double(temp.f32);
	// lvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// vmsum3fp128 v41,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r3,r6,-31648
	ctx.r3.s64 = ctx.r6.s64 + -31648;
	// lvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r5,-31664
	r11.s64 = ctx.r5.s64 + -31664;
	// lvx128 v0,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// addi r8,r10,2384
	ctx.r8.s64 = ctx.r10.s64 + 2384;
	// lvx128 v58,r0,r3
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r9,2352
	ctx.r6.s64 = ctx.r9.s64 + 2352;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,31292(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31292);
	f0.f64 = double(temp.f32);
	// addi r10,r3,-31600
	ctx.r10.s64 = ctx.r3.s64 + -31600;
	// lvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,116(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// vrsqrtefp128 v40,v41
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v40.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v41.f32))));
	// vor128 v12,v41,v41
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v41.u8));
	// vand128 v39,v41,v62
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// lvx128 v38,r0,r5
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v37,v38,v62
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128 v11,v40,v59
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v59.f32)));
	// vor128 v10,v40,v40
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v40.u8));
	// vor128 v36,v39,v60
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// vsubfp128 v9,v42,v61
	simde_mm_store_ps(ctx.v9.f32, simde_mm_sub_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128 v8,v36,v37
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v37.f32)));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v7,v0,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v6,v58,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v5,v12,v7,v13
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v4,v5,v6,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v3,v4,v63
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(v63.f32)));
	// vsel v2,v9,v3,v8
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8))));
	// stvx128 v2,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// fmuls f8,f11,f0
	ctx.f8.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fmadds f7,f10,f12,f8
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f12.f64 + ctx.f8.f64));
	// stfs f13,272(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// stfs f0,276(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// stfs f12,280(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// fmadds f6,f9,f13,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f7.f64));
	// stfs f6,284(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// beq cr6,0x823d03e0
	if (cr6.eq) goto loc_823D03E0;
	// addi r5,r1,272
	ctx.r5.s64 = ctx.r1.s64 + 272;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82192a88
	ctx.lr = 0x823D03E0;
	sub_82192A88(ctx, base);
loc_823D03E0:
	// li r10,112
	ctx.r10.s64 = 112;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// lvx128 v0,r25,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lfs f0,14884(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14884);
	f0.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f0,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// lfs f10,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,-28332(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -28332);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-16460(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -16460);
	ctx.f12.f64 = double(temp.f32);
	// lvlx128 v35,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v35,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), 0xFF));
	// lfs f11,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f8,f10,f13
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fadds f9,f11,f0
	ctx.f9.f64 = double(float(ctx.f11.f64 + f0.f64));
	// fmadds f7,f9,f12,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f12.f64 + ctx.f8.f64));
	// stfs f7,120(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f7,112(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f7,116(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v34,r0,r5
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v12,v34,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v0,v12,v13,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v0,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x823d0468
	if (!cr6.eq) goto loc_823D0468;
	// li r11,0
	r11.s64 = 0;
loc_823D0468:
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lfs f13,168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r4,12(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// lfs f0,-21516(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21516);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v33,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v32,v33,0
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), 0xFF));
	// vmulfp128 v63,v0,v32
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v32.f32)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x823d04c8
	if (cr6.eq) goto loc_823D04C8;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// addi r5,r1,240
	ctx.r5.s64 = ctx.r1.s64 + 240;
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,240(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f13,244(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f12,248(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f30,252(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// bl 0x82192a88
	ctx.lr = 0x823D04C8;
	sub_82192A88(ctx, base);
loc_823D04C8:
	// lwz r11,36(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d04fc
	if (cr6.eq) goto loc_823D04FC;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x823d04e8
	if (!cr6.eq) goto loc_823D04E8;
	// li r3,0
	ctx.r3.s64 = 0;
loc_823D04E8:
	// bl 0x82352e20
	ctx.lr = 0x823D04EC;
	sub_82352E20(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r4,36(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// bl 0x82192710
	ctx.lr = 0x823D04FC;
	sub_82192710(ctx, base);
loc_823D04FC:
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d0530
	if (cr6.eq) goto loc_823D0530;
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x823d051c
	if (!cr6.eq) goto loc_823D051C;
	// li r3,0
	ctx.r3.s64 = 0;
loc_823D051C:
	// bl 0x82352e08
	ctx.lr = 0x823D0520;
	sub_82352E08(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r4,32(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// bl 0x82192bb0
	ctx.lr = 0x823D0530;
	sub_82192BB0(ctx, base);
loc_823D0530:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d0638
	if (!cr6.eq) goto loc_823D0638;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lbz r10,147(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 147);
	// lwz r3,188(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d0568
	if (cr6.eq) goto loc_823D0568;
	// clrlwi r11,r19,24
	r11.u64 = r19.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d0568
	if (cr6.eq) goto loc_823D0568;
	// bl 0x8218f5b0
	ctx.lr = 0x823D0560;
	sub_8218F5B0(ctx, base);
	// addi r31,r31,72
	r31.s64 = r31.s64 + 72;
	// b 0x823d0570
	goto loc_823D0570;
loc_823D0568:
	// bl 0x8239f620
	ctx.lr = 0x823D056C;
	sub_8239F620(ctx, base);
	// addi r31,r31,32
	r31.s64 = r31.s64 + 32;
loc_823D0570:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r30,8(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// beq cr6,0x823d05ac
	if (cr6.eq) goto loc_823D05AC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f31,288(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// stfs f30,292(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// addi r5,r1,288
	ctx.r5.s64 = ctx.r1.s64 + 288;
	// stfs f31,296(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f0,11412(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11412);
	f0.f64 = double(temp.f32);
	// stfs f0,300(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// bl 0x82192a88
	ctx.lr = 0x823D05AC;
	sub_82192A88(ctx, base);
loc_823D05AC:
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x823d05cc
	if (cr6.eq) goto loc_823D05CC;
	// stfs f31,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stfs f31,132(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821928d0
	ctx.lr = 0x823D05CC;
	sub_821928D0(ctx, base);
loc_823D05CC:
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x823d05f4
	if (cr6.eq) goto loc_823D05F4;
	// stfs f31,192(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// stfs f31,196(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stfs f31,200(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f31,204(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// bl 0x82192a88
	ctx.lr = 0x823D05F4;
	sub_82192A88(ctx, base);
loc_823D05F4:
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x823d061c
	if (cr6.eq) goto loc_823D061C;
	// stfs f31,224(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// stfs f31,228(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stfs f31,232(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f31,236(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// bl 0x82192a88
	ctx.lr = 0x823D061C;
	sub_82192A88(ctx, base);
loc_823D061C:
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x823d0638
	if (cr6.eq) goto loc_823D0638;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,-25360(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -25360);
	// bl 0x82192710
	ctx.lr = 0x823D0638;
	sub_82192710(ctx, base);
loc_823D0638:
	// addi r1,r1,592
	ctx.r1.s64 = ctx.r1.s64 + 592;
	// addi r12,r1,-144
	r12.s64 = ctx.r1.s64 + -144;
	// bl 0x823dd7cc
	ctx.lr = 0x823D0644;
	// lfd f30,-136(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// lfd f31,-128(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_823D0650"))) PPC_WEAK_FUNC(sub_823D0650);
PPC_FUNC_IMPL(__imp__sub_823D0650) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x823a4360
	sub_823A4360(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823D0660"))) PPC_WEAK_FUNC(sub_823D0660);
PPC_FUNC_IMPL(__imp__sub_823D0660) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D0664"))) PPC_WEAK_FUNC(sub_823D0664);
PPC_FUNC_IMPL(__imp__sub_823D0664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D0668"))) PPC_WEAK_FUNC(sub_823D0668);
PPC_FUNC_IMPL(__imp__sub_823D0668) {
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
	ctx.lr = 0x823D0670;
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
	// bne cr6,0x823d071c
	if (!cr6.eq) goto loc_823D071C;
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
	ctx.lr = 0x823D06A8;
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
	// bl 0x823a0b50
	ctx.lr = 0x823D06E8;
	sub_823A0B50(ctx, base);
	// sth r28,2(r27)
	PPC_STORE_U16(r27.u32 + 2, r28.u16);
	// sth r28,0(r27)
	PPC_STORE_U16(r27.u32 + 0, r28.u16);
	// lis r4,12288
	ctx.r4.s64 = 805306368;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e2808
	ctx.lr = 0x823D06FC;
	sub_821E2808(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8276d240
	ctx.lr = 0x823D0704;
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
loc_823D071C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823D0724"))) PPC_WEAK_FUNC(sub_823D0724);
PPC_FUNC_IMPL(__imp__sub_823D0724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D0728"))) PPC_WEAK_FUNC(sub_823D0728);
PPC_FUNC_IMPL(__imp__sub_823D0728) {
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
	ctx.lr = 0x823D0730;
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
	// bne cr6,0x823d07dc
	if (!cr6.eq) goto loc_823D07DC;
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
	ctx.lr = 0x823D0768;
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
	// bl 0x826143f8
	ctx.lr = 0x823D07A8;
	sub_826143F8(ctx, base);
	// sth r28,2(r27)
	PPC_STORE_U16(r27.u32 + 2, r28.u16);
	// sth r28,0(r27)
	PPC_STORE_U16(r27.u32 + 0, r28.u16);
	// lis r4,12288
	ctx.r4.s64 = 805306368;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e2808
	ctx.lr = 0x823D07BC;
	sub_821E2808(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8276d240
	ctx.lr = 0x823D07C4;
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
loc_823D07DC:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823D07E4"))) PPC_WEAK_FUNC(sub_823D07E4);
PPC_FUNC_IMPL(__imp__sub_823D07E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D07E8"))) PPC_WEAK_FUNC(sub_823D07E8);
PPC_FUNC_IMPL(__imp__sub_823D07E8) {
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
	// bl 0x823cf0c0
	ctx.lr = 0x823D0808;
	sub_823CF0C0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d0820
	if (cr6.eq) goto loc_823D0820;
	// bl 0x82130588
	ctx.lr = 0x823D081C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823D0820:
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

__attribute__((alias("__imp__sub_823D0838"))) PPC_WEAK_FUNC(sub_823D0838);
PPC_FUNC_IMPL(__imp__sub_823D0838) {
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
	ctx.lr = 0x823D0840;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x823D085C;
	sub_821C8FE0(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8239e6b0
	ctx.lr = 0x823D086C;
	sub_8239E6B0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r5,r11,10372
	ctx.r5.s64 = r11.s64 + 10372;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82137a08
	ctx.lr = 0x823D0888;
	sub_82137A08(ctx, base);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822e6a80
	ctx.lr = 0x823D0894;
	sub_822E6A80(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d08b8
	if (cr6.eq) goto loc_823D08B8;
	// bl 0x823cf3c8
	ctx.lr = 0x823D08A0;
	sub_823CF3C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D08AC;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d924c
	return;
loc_823D08B8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D08C0;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823D08CC"))) PPC_WEAK_FUNC(sub_823D08CC);
PPC_FUNC_IMPL(__imp__sub_823D08CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D08D0"))) PPC_WEAK_FUNC(sub_823D08D0);
PPC_FUNC_IMPL(__imp__sub_823D08D0) {
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
	ctx.lr = 0x823D08D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x823D08F8;
	sub_821C8FE0(ctx, base);
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d0930
	if (cr6.eq) goto loc_823D0930;
loc_823D0904:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823cf470
	ctx.lr = 0x823D0918;
	sub_823CF470(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d0944
	if (!cr6.eq) goto loc_823D0944;
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823d0904
	if (!cr6.eq) goto loc_823D0904;
loc_823D0930:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D0938;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823D0944:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D094C;
	sub_821C9030(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823D0958"))) PPC_WEAK_FUNC(sub_823D0958);
PPC_FUNC_IMPL(__imp__sub_823D0958) {
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
	ctx.lr = 0x823D0960;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x823D0980;
	sub_821C8FE0(ctx, base);
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d09b8
	if (cr6.eq) goto loc_823D09B8;
loc_823D098C:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823cf500
	ctx.lr = 0x823D09A0;
	sub_823CF500(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d09cc
	if (!cr6.eq) goto loc_823D09CC;
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823d098c
	if (!cr6.eq) goto loc_823D098C;
loc_823D09B8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D09C0;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_823D09CC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D09D4;
	sub_821C9030(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823D09E0"))) PPC_WEAK_FUNC(sub_823D09E0);
PPC_FUNC_IMPL(__imp__sub_823D09E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c8fe0
	ctx.lr = 0x823D0A08;
	sub_821C8FE0(ctx, base);
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d0a3c
	if (cr6.eq) goto loc_823D0A3C;
loc_823D0A14:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823cf590
	ctx.lr = 0x823D0A24;
	sub_823CF590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d0a64
	if (!cr6.eq) goto loc_823D0A64;
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823d0a14
	if (!cr6.eq) goto loc_823D0A14;
loc_823D0A3C:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x823D0A44;
	sub_821C9030(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
loc_823D0A4C:
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
loc_823D0A64:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821c9030
	ctx.lr = 0x823D0A6C;
	sub_821C9030(ctx, base);
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// b 0x823d0a4c
	goto loc_823D0A4C;
}

__attribute__((alias("__imp__sub_823D0A74"))) PPC_WEAK_FUNC(sub_823D0A74);
PPC_FUNC_IMPL(__imp__sub_823D0A74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D0A78"))) PPC_WEAK_FUNC(sub_823D0A78);
PPC_FUNC_IMPL(__imp__sub_823D0A78) {
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
	ctx.lr = 0x823D0A80;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x823D0A9C;
	sub_821C8FE0(ctx, base);
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d0ac4
	if (cr6.eq) goto loc_823D0AC4;
loc_823D0AA8:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823cf620
	ctx.lr = 0x823D0AB8;
	sub_823CF620(ctx, base);
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823d0aa8
	if (!cr6.eq) goto loc_823D0AA8;
loc_823D0AC4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D0ACC;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823D0AD4"))) PPC_WEAK_FUNC(sub_823D0AD4);
PPC_FUNC_IMPL(__imp__sub_823D0AD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D0AD8"))) PPC_WEAK_FUNC(sub_823D0AD8);
PPC_FUNC_IMPL(__imp__sub_823D0AD8) {
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
	ctx.lr = 0x823D0AF8;
	sub_821C8FE0(ctx, base);
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d0b18
	if (cr6.eq) goto loc_823D0B18;
loc_823D0B04:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823cf6a0
	ctx.lr = 0x823D0B0C;
	sub_823CF6A0(ctx, base);
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823d0b04
	if (!cr6.eq) goto loc_823D0B04;
loc_823D0B18:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D0B20;
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

__attribute__((alias("__imp__sub_823D0B34"))) PPC_WEAK_FUNC(sub_823D0B34);
PPC_FUNC_IMPL(__imp__sub_823D0B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D0B38"))) PPC_WEAK_FUNC(sub_823D0B38);
PPC_FUNC_IMPL(__imp__sub_823D0B38) {
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
	ctx.lr = 0x823D0B40;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x823D0B60;
	sub_821C8FE0(ctx, base);
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d0bd4
	if (cr6.eq) goto loc_823D0BD4;
loc_823D0B6C:
	// lhz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x823d0bc8
	if (!cr6.gt) goto loc_823D0BC8;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
loc_823D0B80:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r3,16(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d0b9c
	if (cr6.eq) goto loc_823D0B9C;
	// lwz r8,132(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r8,r30
	cr6.compare<int32_t>(ctx.r8.s32, r30.s32, xer);
	// beq cr6,0x823d0bb0
	if (cr6.eq) goto loc_823D0BB0;
loc_823D0B9C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x823d0b80
	if (cr6.lt) goto loc_823D0B80;
	// b 0x823d0bc8
	goto loc_823D0BC8;
loc_823D0BB0:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D0BC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D0BC8:
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823d0b6c
	if (!cr6.eq) goto loc_823D0B6C;
loc_823D0BD4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D0BDC;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_823D0BE4"))) PPC_WEAK_FUNC(sub_823D0BE4);
PPC_FUNC_IMPL(__imp__sub_823D0BE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D0BE8"))) PPC_WEAK_FUNC(sub_823D0BE8);
PPC_FUNC_IMPL(__imp__sub_823D0BE8) {
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
	ctx.lr = 0x823D0BF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x823D0C0C;
	sub_821C8FE0(ctx, base);
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d0c70
	if (cr6.eq) goto loc_823D0C70;
loc_823D0C18:
	// lhz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x823d0c64
	if (!cr6.gt) goto loc_823D0C64;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
loc_823D0C2C:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r3,16(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d0c48
	if (cr6.eq) goto loc_823D0C48;
	// lwz r8,132(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r8,r30
	cr6.compare<int32_t>(ctx.r8.s32, r30.s32, xer);
	// beq cr6,0x823d0c5c
	if (cr6.eq) goto loc_823D0C5C;
loc_823D0C48:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x823d0c2c
	if (cr6.lt) goto loc_823D0C2C;
	// b 0x823d0c64
	goto loc_823D0C64;
loc_823D0C5C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8239efb0
	ctx.lr = 0x823D0C64;
	sub_8239EFB0(ctx, base);
loc_823D0C64:
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823d0c18
	if (!cr6.eq) goto loc_823D0C18;
loc_823D0C70:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D0C78;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823D0C80"))) PPC_WEAK_FUNC(sub_823D0C80);
PPC_FUNC_IMPL(__imp__sub_823D0C80) {
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
	ctx.lr = 0x823D0C88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x823D0CA4;
	sub_821C8FE0(ctx, base);
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d0d08
	if (cr6.eq) goto loc_823D0D08;
loc_823D0CB0:
	// lhz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x823d0cfc
	if (!cr6.gt) goto loc_823D0CFC;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
loc_823D0CC4:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r3,16(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d0ce0
	if (cr6.eq) goto loc_823D0CE0;
	// lwz r8,132(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r8,r30
	cr6.compare<int32_t>(ctx.r8.s32, r30.s32, xer);
	// beq cr6,0x823d0cf4
	if (cr6.eq) goto loc_823D0CF4;
loc_823D0CE0:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x823d0cc4
	if (cr6.lt) goto loc_823D0CC4;
	// b 0x823d0cfc
	goto loc_823D0CFC;
loc_823D0CF4:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8239fd30
	ctx.lr = 0x823D0CFC;
	sub_8239FD30(ctx, base);
loc_823D0CFC:
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823d0cb0
	if (!cr6.eq) goto loc_823D0CB0;
loc_823D0D08:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D0D10;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823D0D18"))) PPC_WEAK_FUNC(sub_823D0D18);
PPC_FUNC_IMPL(__imp__sub_823D0D18) {
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
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x823D0D40;
	sub_821C8FE0(ctx, base);
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d0dac
	if (cr6.eq) goto loc_823D0DAC;
loc_823D0D4C:
	// lhz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x823d0da0
	if (!cr6.gt) goto loc_823D0DA0;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
loc_823D0D60:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r3,16(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d0d7c
	if (cr6.eq) goto loc_823D0D7C;
	// lwz r8,132(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r8,r30
	cr6.compare<int32_t>(ctx.r8.s32, r30.s32, xer);
	// beq cr6,0x823d0d90
	if (cr6.eq) goto loc_823D0D90;
loc_823D0D7C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x823d0d60
	if (cr6.lt) goto loc_823D0D60;
	// b 0x823d0da0
	goto loc_823D0DA0;
loc_823D0D90:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D0DA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D0DA0:
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823d0d4c
	if (!cr6.eq) goto loc_823D0D4C;
loc_823D0DAC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D0DB4;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_823D0DCC"))) PPC_WEAK_FUNC(sub_823D0DCC);
PPC_FUNC_IMPL(__imp__sub_823D0DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D0DD0"))) PPC_WEAK_FUNC(sub_823D0DD0);
PPC_FUNC_IMPL(__imp__sub_823D0DD0) {
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
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x823D0DF8;
	sub_821C8FE0(ctx, base);
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d0e64
	if (cr6.eq) goto loc_823D0E64;
loc_823D0E04:
	// lhz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x823d0e58
	if (!cr6.gt) goto loc_823D0E58;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
loc_823D0E18:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r3,16(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d0e34
	if (cr6.eq) goto loc_823D0E34;
	// lwz r8,132(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r8,r30
	cr6.compare<int32_t>(ctx.r8.s32, r30.s32, xer);
	// beq cr6,0x823d0e48
	if (cr6.eq) goto loc_823D0E48;
loc_823D0E34:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x823d0e18
	if (cr6.lt) goto loc_823D0E18;
	// b 0x823d0e58
	goto loc_823D0E58;
loc_823D0E48:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D0E58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D0E58:
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823d0e04
	if (!cr6.eq) goto loc_823D0E04;
loc_823D0E64:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D0E6C;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_823D0E84"))) PPC_WEAK_FUNC(sub_823D0E84);
PPC_FUNC_IMPL(__imp__sub_823D0E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D0E88"))) PPC_WEAK_FUNC(sub_823D0E88);
PPC_FUNC_IMPL(__imp__sub_823D0E88) {
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
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x823D0EB0;
	sub_821C8FE0(ctx, base);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823d0f18
	if (cr6.eq) goto loc_823D0F18;
loc_823D0EBC:
	// lhz r8,76(r7)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r7.u32 + 76);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x823d0efc
	if (!cr6.gt) goto loc_823D0EFC;
	// lwz r11,72(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 72);
loc_823D0ED0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,16(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823d0eec
	if (cr6.eq) goto loc_823D0EEC;
	// lwz r9,132(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 132);
	// cmpw cr6,r9,r30
	cr6.compare<int32_t>(ctx.r9.s32, r30.s32, xer);
	// beq cr6,0x823d0f3c
	if (cr6.eq) goto loc_823D0F3C;
loc_823D0EEC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x823d0ed0
	if (cr6.lt) goto loc_823D0ED0;
loc_823D0EFC:
	// li r11,0
	r11.s64 = 0;
loc_823D0F00:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d0f44
	if (!cr6.eq) goto loc_823D0F44;
	// lwz r7,12(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x823d0ebc
	if (!cr6.eq) goto loc_823D0EBC;
loc_823D0F18:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D0F20;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_823D0F24:
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
loc_823D0F3C:
	// li r11,1
	r11.s64 = 1;
	// b 0x823d0f00
	goto loc_823D0F00;
loc_823D0F44:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D0F4C;
	sub_821C9030(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x823d0f24
	goto loc_823D0F24;
}

__attribute__((alias("__imp__sub_823D0F54"))) PPC_WEAK_FUNC(sub_823D0F54);
PPC_FUNC_IMPL(__imp__sub_823D0F54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D0F58"))) PPC_WEAK_FUNC(sub_823D0F58);
PPC_FUNC_IMPL(__imp__sub_823D0F58) {
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
	ctx.lr = 0x823D0F60;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c8fe0
	ctx.lr = 0x823D0F78;
	sub_821C8FE0(ctx, base);
	// lwz r30,8(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d0ff0
	if (cr6.eq) goto loc_823D0FF0;
loc_823D0F84:
	// lhz r9,76(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 76);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x823d0fe4
	if (!cr6.gt) goto loc_823D0FE4;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
loc_823D0F98:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r3,16(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d0fb4
	if (cr6.eq) goto loc_823D0FB4;
	// lwz r8,132(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r8,r29
	cr6.compare<int32_t>(ctx.r8.s32, r29.s32, xer);
	// beq cr6,0x823d0fc8
	if (cr6.eq) goto loc_823D0FC8;
loc_823D0FB4:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x823d0f98
	if (cr6.lt) goto loc_823D0F98;
	// b 0x823d0fe4
	goto loc_823D0FE4;
loc_823D0FC8:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D0FD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823d1004
	if (!cr6.eq) goto loc_823D1004;
loc_823D0FE4:
	// lwz r30,12(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x823d0f84
	if (!cr6.eq) goto loc_823D0F84;
loc_823D0FF0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D0FF8;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_823D1004:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D100C;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823D1018"))) PPC_WEAK_FUNC(sub_823D1018);
PPC_FUNC_IMPL(__imp__sub_823D1018) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823D1020;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x823D103C;
	sub_821C8FE0(ctx, base);
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d1070
	if (cr6.eq) goto loc_823D1070;
loc_823D1048:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823cfa68
	ctx.lr = 0x823D1058;
	sub_823CFA68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d1078
	if (!cr6.eq) goto loc_823D1078;
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823d1048
	if (!cr6.eq) goto loc_823D1048;
loc_823D1070:
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823D1078:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D1080;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823D1088"))) PPC_WEAK_FUNC(sub_823D1088);
PPC_FUNC_IMPL(__imp__sub_823D1088) {
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
	ctx.lr = 0x823D10A8;
	sub_821C8FE0(ctx, base);
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d10c8
	if (cr6.eq) goto loc_823D10C8;
loc_823D10B4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823cfaf0
	ctx.lr = 0x823D10BC;
	sub_823CFAF0(ctx, base);
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823d10b4
	if (!cr6.eq) goto loc_823D10B4;
loc_823D10C8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D10D0;
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

__attribute__((alias("__imp__sub_823D10E4"))) PPC_WEAK_FUNC(sub_823D10E4);
PPC_FUNC_IMPL(__imp__sub_823D10E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D10E8"))) PPC_WEAK_FUNC(sub_823D10E8);
PPC_FUNC_IMPL(__imp__sub_823D10E8) {
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
	ctx.lr = 0x823D1108;
	sub_821C8FE0(ctx, base);
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d1128
	if (cr6.eq) goto loc_823D1128;
loc_823D1114:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823cfb78
	ctx.lr = 0x823D111C;
	sub_823CFB78(ctx, base);
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823d1114
	if (!cr6.eq) goto loc_823D1114;
loc_823D1128:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D1130;
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

__attribute__((alias("__imp__sub_823D1144"))) PPC_WEAK_FUNC(sub_823D1144);
PPC_FUNC_IMPL(__imp__sub_823D1144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D1148"))) PPC_WEAK_FUNC(sub_823D1148);
PPC_FUNC_IMPL(__imp__sub_823D1148) {
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
	// bl 0x822e6d98
	ctx.lr = 0x823D1164;
	sub_822E6D98(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-16296
	ctx.r10.s64 = r11.s64 + -16296;
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// addi r11,r31,44
	r11.s64 = r31.s64 + 44;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// addi r9,r9,3998
	ctx.r9.s64 = ctx.r9.s64 + 3998;
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x8239e458
	ctx.lr = 0x823D11B8;
	sub_8239E458(ctx, base);
	// stb r30,68(r31)
	PPC_STORE_U8(r31.u32 + 68, r30.u8);
	// stb r30,69(r31)
	PPC_STORE_U8(r31.u32 + 69, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// sth r30,76(r31)
	PPC_STORE_U16(r31.u32 + 76, r30.u16);
	// sth r30,78(r31)
	PPC_STORE_U16(r31.u32 + 78, r30.u16);
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

__attribute__((alias("__imp__sub_823D11E8"))) PPC_WEAK_FUNC(sub_823D11E8);
PPC_FUNC_IMPL(__imp__sub_823D11E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d1234
	if (cr6.eq) goto loc_823D1234;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d1218
	if (cr6.eq) goto loc_823D1218;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r9,12288
	ctx.r9.s64 = 805306368;
	// rlwinm r8,r11,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x823d121c
	if (cr6.eq) goto loc_823D121C;
loc_823D1218:
	// li r11,0
	r11.s64 = 0;
loc_823D121C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d1234
	if (cr6.eq) goto loc_823D1234;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// blr 
	return;
loc_823D1234:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D123C"))) PPC_WEAK_FUNC(sub_823D123C);
PPC_FUNC_IMPL(__imp__sub_823D123C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D1240"))) PPC_WEAK_FUNC(sub_823D1240);
PPC_FUNC_IMPL(__imp__sub_823D1240) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,40(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d129c
	if (cr6.eq) goto loc_823D129C;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d1280
	if (cr6.eq) goto loc_823D1280;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r9,12288
	ctx.r9.s64 = 805306368;
	// rlwinm r8,r11,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x823d1284
	if (cr6.eq) goto loc_823D1284;
loc_823D1280:
	// li r11,0
	r11.s64 = 0;
loc_823D1284:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d129c
	if (cr6.eq) goto loc_823D129C;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// blr 
	return;
loc_823D129C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D12A4"))) PPC_WEAK_FUNC(sub_823D12A4);
PPC_FUNC_IMPL(__imp__sub_823D12A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D12A8"))) PPC_WEAK_FUNC(sub_823D12A8);
PPC_FUNC_IMPL(__imp__sub_823D12A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d12f4
	if (cr6.eq) goto loc_823D12F4;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d12d8
	if (cr6.eq) goto loc_823D12D8;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r9,12288
	ctx.r9.s64 = 805306368;
	// rlwinm r8,r11,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x823d12dc
	if (cr6.eq) goto loc_823D12DC;
loc_823D12D8:
	// li r11,0
	r11.s64 = 0;
loc_823D12DC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d12f4
	if (cr6.eq) goto loc_823D12F4;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// blr 
	return;
loc_823D12F4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D12FC"))) PPC_WEAK_FUNC(sub_823D12FC);
PPC_FUNC_IMPL(__imp__sub_823D12FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D1300"))) PPC_WEAK_FUNC(sub_823D1300);
PPC_FUNC_IMPL(__imp__sub_823D1300) {
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
	ctx.lr = 0x823D1308;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lhz r10,12(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 12);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// addi r24,r11,12
	r24.s64 = r11.s64 + 12;
	// rlwinm r25,r8,27,31,31
	r25.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// lwz r23,16(r11)
	r23.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// beq cr6,0x823d134c
	if (cr6.eq) goto loc_823D134C;
	// lwz r3,8(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// b 0x823d1354
	goto loc_823D1354;
loc_823D134C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
loc_823D1354:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r11,16192
	ctx.r4.s64 = r11.s64 + 16192;
	// bl 0x823dd800
	ctx.lr = 0x823D1364;
	sub_823DD800(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// rlwinm r28,r10,27,31,31
	r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x8239e4e8
	ctx.lr = 0x823D1374;
	sub_8239E4E8(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// lis r8,12288
	ctx.r8.s64 = 805306368;
	// stb r9,4(r29)
	PPC_STORE_U8(r29.u32 + 4, ctx.r9.u8);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d13dc
	if (!cr6.eq) goto loc_823D13DC;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d13d8
	if (cr6.eq) goto loc_823D13D8;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d13bc
	if (cr6.eq) goto loc_823D13BC;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r11,0,2,3
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// beq cr6,0x823d13c0
	if (cr6.eq) goto loc_823D13C0;
loc_823D13BC:
	// li r11,0
	r11.s64 = 0;
loc_823D13C0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d13d8
	if (cr6.eq) goto loc_823D13D8;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x823d13dc
	goto loc_823D13DC;
loc_823D13D8:
	// li r11,0
	r11.s64 = 0;
loc_823D13DC:
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823d1424
	if (cr6.eq) goto loc_823D1424;
	// lwz r10,12(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x823d1408
	if (cr6.eq) goto loc_823D1408;
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm r7,r10,0,2,3
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x30000000;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// beq cr6,0x823d140c
	if (cr6.eq) goto loc_823D140C;
loc_823D1408:
	// li r10,0
	ctx.r10.s64 = 0;
loc_823D140C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d1424
	if (cr6.eq) goto loc_823D1424;
	// lwz r10,12(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x823d1428
	goto loc_823D1428;
loc_823D1424:
	// li r7,0
	ctx.r7.s64 = 0;
loc_823D1428:
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r11,24(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823D1454;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x8239e6a0
	ctx.lr = 0x823D1464;
	sub_8239E6A0(ctx, base);
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// rlwinm r10,r26,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stw r30,16(r8)
	PPC_STORE_U32(ctx.r8.u32 + 16, r30.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_823D1480"))) PPC_WEAK_FUNC(sub_823D1480);
PPC_FUNC_IMPL(__imp__sub_823D1480) {
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
	ctx.lr = 0x823D1488;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823d14b8
	if (cr6.eq) goto loc_823D14B8;
	// bl 0x822a86e8
	ctx.lr = 0x823D14AC;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d1550
	if (cr6.eq) goto loc_823D1550;
loc_823D14B8:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d1504
	if (cr6.eq) goto loc_823D1504;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d14e8
	if (cr6.eq) goto loc_823D14E8;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r9,12288
	ctx.r9.s64 = 805306368;
	// rlwinm r8,r11,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x823d14ec
	if (cr6.eq) goto loc_823D14EC;
loc_823D14E8:
	// li r11,0
	r11.s64 = 0;
loc_823D14EC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d1504
	if (cr6.eq) goto loc_823D1504;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x823d1508
	goto loc_823D1508;
loc_823D1504:
	// li r30,0
	r30.s64 = 0;
loc_823D1508:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-10820
	ctx.r10.s64 = r11.s64 + -10820;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d15a0
	if (!cr6.eq) goto loc_823D15A0;
	// lhz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x823d1550
	if (!cr6.gt) goto loc_823D1550;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
loc_823D1530:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x823d155c
	if (cr6.eq) goto loc_823D155C;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r4,r10
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r10.s32, xer);
	// blt cr6,0x823d1530
	if (cr6.lt) goto loc_823D1530;
loc_823D1550:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_823D155C:
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d1300
	ctx.lr = 0x823D156C;
	sub_823D1300(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D1584;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8239fc00
	ctx.lr = 0x823D1594;
	sub_8239FC00(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_823D15A0:
	// lhz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x823d1550
	if (!cr6.gt) goto loc_823D1550;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
loc_823D15B4:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r31,16(r8)
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d15dc
	if (cr6.eq) goto loc_823D15DC;
	// lwz r8,132(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bge cr6,0x823d15dc
	if (!cr6.lt) goto loc_823D15DC;
	// lbz r8,129(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 129);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823d15f8
	if (cr6.eq) goto loc_823D15F8;
loc_823D15DC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x823d15b4
	if (cr6.lt) goto loc_823D15B4;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_823D15F8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D1610;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8239fc00
	ctx.lr = 0x823D1620;
	sub_8239FC00(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823D162C"))) PPC_WEAK_FUNC(sub_823D162C);
PPC_FUNC_IMPL(__imp__sub_823D162C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D1630"))) PPC_WEAK_FUNC(sub_823D1630);
PPC_FUNC_IMPL(__imp__sub_823D1630) {
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
	ctx.lr = 0x823D1638;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d16e8
	if (cr6.eq) goto loc_823D16E8;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d1670
	if (cr6.eq) goto loc_823D1670;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r9,12288
	ctx.r9.s64 = 805306368;
	// rlwinm r8,r11,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x823d1674
	if (cr6.eq) goto loc_823D1674;
loc_823D1670:
	// li r11,0
	r11.s64 = 0;
loc_823D1674:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d16e8
	if (cr6.eq) goto loc_823D16E8;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d16e8
	if (cr6.eq) goto loc_823D16E8;
	// lhz r11,76(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 76);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d16e8
	if (cr6.eq) goto loc_823D16E8;
	// li r31,0
	r31.s64 = 0;
loc_823D16A4:
	// lwz r11,72(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r3,16(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d16d4
	if (cr6.eq) goto loc_823D16D4;
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x823d16d4
	if (cr6.lt) goto loc_823D16D4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D16D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D16D4:
	// lhz r11,76(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 76);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x823d16a4
	if (cr6.lt) goto loc_823D16A4;
loc_823D16E8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823D16F0"))) PPC_WEAK_FUNC(sub_823D16F0);
PPC_FUNC_IMPL(__imp__sub_823D16F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d1720
	if (cr6.eq) goto loc_823D1720;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r9,12288
	ctx.r9.s64 = 805306368;
	// rlwinm r8,r11,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x823d1724
	if (cr6.eq) goto loc_823D1724;
loc_823D1720:
	// li r11,0
	r11.s64 = 0;
loc_823D1724:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822e6cb8
	sub_822E6CB8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823D1744"))) PPC_WEAK_FUNC(sub_823D1744);
PPC_FUNC_IMPL(__imp__sub_823D1744) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D1748"))) PPC_WEAK_FUNC(sub_823D1748);
PPC_FUNC_IMPL(__imp__sub_823D1748) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x823D1750;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d1970
	if (cr6.eq) goto loc_823D1970;
	// lwz r11,132(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x823d1970
	if (cr6.lt) goto loc_823D1970;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r10,-29347(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -29347);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823d1970
	if (!cr6.eq) goto loc_823D1970;
	// bl 0x8269a1b0
	ctx.lr = 0x823D1788;
	sub_8269A1B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d1970
	if (!cr6.eq) goto loc_823D1970;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8239f980
	ctx.lr = 0x823D17A0;
	sub_8239F980(ctx, base);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r27,-32130
	r27.s64 = -2105671680;
	// lis r7,64
	ctx.r7.s64 = 4194304;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// ori r7,r7,3
	ctx.r7.u64 = ctx.r7.u64 | 3;
	// lwz r3,-17628(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -17628);
	// lfs f1,30712(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,22080(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 22080);
	// bl 0x82175f20
	ctx.lr = 0x823D17C8;
	sub_82175F20(ctx, base);
	// lis r9,1024
	ctx.r9.s64 = 67108864;
	// rlwinm r8,r3,0,5,5
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4000000;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x823d17ec
	if (cr6.eq) goto loc_823D17EC;
	// rlwinm r11,r3,0,3,3
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10000000;
	// lis r10,4096
	ctx.r10.s64 = 268435456;
	// li r30,1
	r30.s64 = 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x823d17f0
	if (!cr6.eq) goto loc_823D17F0;
loc_823D17EC:
	// li r30,0
	r30.s64 = 0;
loc_823D17F0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8239fae0
	ctx.lr = 0x823D17FC;
	sub_8239FAE0(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d1970
	if (cr6.eq) goto loc_823D1970;
	// li r12,13792
	r12.s64 = 13792;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// and r11,r26,r12
	r11.u64 = r26.u64 & r12.u64;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823d18e0
	if (!cr6.eq) goto loc_823D18E0;
	// li r3,-1
	ctx.r3.s64 = -1;
	// bl 0x82187be0
	ctx.lr = 0x823D1828;
	sub_82187BE0(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D183C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x823d1880
	if (!cr6.eq) goto loc_823D1880;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r30,-7572(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x823bc5e0
	ctx.lr = 0x823D1854;
	sub_823BC5E0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822f5d98
	ctx.lr = 0x823D1874;
	sub_822F5D98(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823cfce0
	ctx.lr = 0x823D187C;
	sub_823CFCE0(ctx, base);
	// b 0x823d1904
	goto loc_823D1904;
loc_823D1880:
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lwz r3,-7572(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x823D188C;
	sub_82205248(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d18c8
	if (cr6.eq) goto loc_823D18C8;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-7436(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -7436);
	// bl 0x822f7480
	ctx.lr = 0x823D18A4;
	sub_822F7480(ctx, base);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,-7572(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x822f2c48
	ctx.lr = 0x823D18B8;
	sub_822F2C48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r29,1
	r29.s64 = 1;
	// bl 0x823cfce0
	ctx.lr = 0x823D18C4;
	sub_823CFCE0(ctx, base);
	// b 0x823d1904
	goto loc_823D1904;
loc_823D18C8:
	// lwz r11,-7572(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// addi r3,r11,32
	ctx.r3.s64 = r11.s64 + 32;
	// bl 0x821800a0
	ctx.lr = 0x823D18D4;
	sub_821800A0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823cfce0
	ctx.lr = 0x823D18DC;
	sub_823CFCE0(ctx, base);
	// b 0x823d1904
	goto loc_823D1904;
loc_823D18E0:
	// rlwinm r11,r26,0,21,21
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0x400;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d1904
	if (cr6.eq) goto loc_823D1904;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x823D18F8;
	sub_82205248(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d1970
	if (cr6.eq) goto loc_823D1970;
loc_823D1904:
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217fed0
	ctx.lr = 0x823D190C;
	sub_8217FED0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x823D191C;
	sub_8217F768(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,22080(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 22080);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// addi r9,r11,3
	ctx.r9.s64 = r11.s64 + 3;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r11,r9,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// lwz r7,36(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// lwz r10,-8092(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x823D194C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x823D1958;
	sub_8217F768(ctx, base);
	// clrlwi r6,r29,24
	ctx.r6.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x823d1970
	if (cr6.eq) goto loc_823D1970;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-7436(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -7436);
	// bl 0x822f7480
	ctx.lr = 0x823D1970;
	sub_822F7480(ctx, base);
loc_823D1970:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_823D1978"))) PPC_WEAK_FUNC(sub_823D1978);
PPC_FUNC_IMPL(__imp__sub_823D1978) {
	PPC_FUNC_PROLOGUE();
	// b 0x823d0668
	sub_823D0668(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823D197C"))) PPC_WEAK_FUNC(sub_823D197C);
PPC_FUNC_IMPL(__imp__sub_823D197C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D1980"))) PPC_WEAK_FUNC(sub_823D1980);
PPC_FUNC_IMPL(__imp__sub_823D1980) {
	PPC_FUNC_PROLOGUE();
	// b 0x823d0728
	sub_823D0728(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823D1984"))) PPC_WEAK_FUNC(sub_823D1984);
PPC_FUNC_IMPL(__imp__sub_823D1984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D1988"))) PPC_WEAK_FUNC(sub_823D1988);
PPC_FUNC_IMPL(__imp__sub_823D1988) {
	PPC_FUNC_PROLOGUE();
	// b 0x823ca600
	sub_823CA600(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823D198C"))) PPC_WEAK_FUNC(sub_823D198C);
PPC_FUNC_IMPL(__imp__sub_823D198C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D1990"))) PPC_WEAK_FUNC(sub_823D1990);
PPC_FUNC_IMPL(__imp__sub_823D1990) {
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
	ctx.lr = 0x823D1998;
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x823D19B8;
	sub_821C8FE0(ctx, base);
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d19cc
	if (cr6.eq) goto loc_823D19CC;
	// lwz r30,4(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// b 0x823d19d4
	goto loc_823D19D4;
loc_823D19CC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r30,r11,3998
	r30.s64 = r11.s64 + 3998;
loc_823D19D4:
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8239e6b0
	ctx.lr = 0x823D19E4;
	sub_8239E6B0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r5,r11,10372
	ctx.r5.s64 = r11.s64 + 10372;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82137a08
	ctx.lr = 0x823D1A00;
	sub_82137A08(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r3,17432(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17432);
	// bl 0x822e6a80
	ctx.lr = 0x823D1A10;
	sub_822E6A80(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d1a34
	if (cr6.eq) goto loc_823D1A34;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D1A34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D1A34:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d1a7c
	if (cr6.eq) goto loc_823D1A7C;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823d1480
	ctx.lr = 0x823D1A50;
	sub_823D1480(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d1a7c
	if (cr6.eq) goto loc_823D1A7C;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// bl 0x821c9030
	ctx.lr = 0x823D1A70;
	sub_821C9030(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x823d9244
	return;
loc_823D1A7C:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D1A84;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_823D1A90"))) PPC_WEAK_FUNC(sub_823D1A90);
PPC_FUNC_IMPL(__imp__sub_823D1A90) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// bl 0x821c8fe0
	ctx.lr = 0x823D1AB4;
	sub_821C8FE0(ctx, base);
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d1ad4
	if (cr6.eq) goto loc_823D1AD4;
loc_823D1AC0:
	// lwz r31,12(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// bl 0x823cf708
	ctx.lr = 0x823D1AC8;
	sub_823CF708(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823d1ac0
	if (!cr6.eq) goto loc_823D1AC0;
loc_823D1AD4:
	// lwz r31,8(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d1af4
	if (cr6.eq) goto loc_823D1AF4;
loc_823D1AE0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823cf830
	ctx.lr = 0x823D1AE8;
	sub_823CF830(ctx, base);
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823d1ae0
	if (!cr6.eq) goto loc_823D1AE0;
loc_823D1AF4:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D1AFC;
	sub_821C9030(ctx, base);
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

__attribute__((alias("__imp__sub_823D1B14"))) PPC_WEAK_FUNC(sub_823D1B14);
PPC_FUNC_IMPL(__imp__sub_823D1B14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D1B18"))) PPC_WEAK_FUNC(sub_823D1B18);
PPC_FUNC_IMPL(__imp__sub_823D1B18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// bl 0x821c8fe0
	ctx.lr = 0x823D1B44;
	sub_821C8FE0(ctx, base);
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d1bb8
	if (cr6.eq) goto loc_823D1BB8;
	// lis r30,12288
	r30.s64 = 805306368;
loc_823D1B54:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d1bac
	if (cr6.eq) goto loc_823D1BAC;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d1b80
	if (cr6.eq) goto loc_823D1B80;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r11,0,2,3
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r9,r30
	cr6.compare<int32_t>(ctx.r9.s32, r30.s32, xer);
	// beq cr6,0x823d1b84
	if (cr6.eq) goto loc_823D1B84;
loc_823D1B80:
	// li r11,0
	r11.s64 = 0;
loc_823D1B84:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d1bac
	if (cr6.eq) goto loc_823D1BAC;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d1bac
	if (cr6.eq) goto loc_823D1BAC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823cf9f0
	ctx.lr = 0x823D1BAC;
	sub_823CF9F0(ctx, base);
loc_823D1BAC:
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823d1b54
	if (!cr6.eq) goto loc_823D1B54;
loc_823D1BB8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D1BC0;
	sub_821C9030(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823D1BDC"))) PPC_WEAK_FUNC(sub_823D1BDC);
PPC_FUNC_IMPL(__imp__sub_823D1BDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D1BE0"))) PPC_WEAK_FUNC(sub_823D1BE0);
PPC_FUNC_IMPL(__imp__sub_823D1BE0) {
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
	ctx.lr = 0x823D1C00;
	sub_821C8FE0(ctx, base);
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d1c20
	if (cr6.eq) goto loc_823D1C20;
loc_823D1C0C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d1630
	ctx.lr = 0x823D1C14;
	sub_823D1630(ctx, base);
	// lwz r31,12(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x823d1c0c
	if (!cr6.eq) goto loc_823D1C0C;
loc_823D1C20:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D1C28;
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

__attribute__((alias("__imp__sub_823D1C3C"))) PPC_WEAK_FUNC(sub_823D1C3C);
PPC_FUNC_IMPL(__imp__sub_823D1C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D1C40"))) PPC_WEAK_FUNC(sub_823D1C40);
PPC_FUNC_IMPL(__imp__sub_823D1C40) {
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
	ctx.lr = 0x823D1C48;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d1d34
	if (!cr6.eq) goto loc_823D1D34;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-10800
	ctx.r10.s64 = r11.s64 + -10800;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d1d34
	if (cr6.eq) goto loc_823D1D34;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823a1490
	ctx.lr = 0x823D1C7C;
	sub_823A1490(ctx, base);
	// stw r3,40(r30)
	PPC_STORE_U32(r30.u32 + 40, ctx.r3.u32);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823b7bd0
	ctx.lr = 0x823D1C90;
	sub_823B7BD0(ctx, base);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x823b7c68
	ctx.lr = 0x823D1C9C;
	sub_823B7C68(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r29,r11,30576
	r29.s64 = r11.s64 + 30576;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ca540
	ctx.lr = 0x823D1CB0;
	sub_821CA540(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r4,r11,-29860
	ctx.r4.s64 = r11.s64 + -29860;
	// bl 0x823dd800
	ctx.lr = 0x823D1CC4;
	sub_823DD800(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x823d1cd4
	if (!cr6.eq) goto loc_823D1CD4;
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// b 0x823d1cec
	goto loc_823D1CEC;
loc_823D1CD4:
	// lhz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// ble cr6,0x823d1ce4
	if (!cr6.gt) goto loc_823D1CE4;
	// li r10,3
	ctx.r10.s64 = 3;
loc_823D1CE4:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
loc_823D1CEC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823d11e8
	ctx.lr = 0x823D1CF4;
	sub_823D11E8(ctx, base);
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// lhz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d1d0c
	if (cr6.eq) goto loc_823D1D0C;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x823d1d14
	goto loc_823D1D14;
loc_823D1D0C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r11,3998
	ctx.r4.s64 = r11.s64 + 3998;
loc_823D1D14:
	// lbz r11,1(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// lbz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lwz r3,40(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// rlwinm r7,r10,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x823b7d00
	ctx.lr = 0x823D1D2C;
	sub_823B7D00(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x823D1D34;
	sub_821C9A90(ctx, base);
loc_823D1D34:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823D1D3C"))) PPC_WEAK_FUNC(sub_823D1D3C);
PPC_FUNC_IMPL(__imp__sub_823D1D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D1D40"))) PPC_WEAK_FUNC(sub_823D1D40);
PPC_FUNC_IMPL(__imp__sub_823D1D40) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x823D1D48;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823d1d8c
	if (cr6.eq) goto loc_823D1D8C;
	// bl 0x822a86e8
	ctx.lr = 0x823D1D80;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d1e24
	if (cr6.eq) goto loc_823D1E24;
loc_823D1D8C:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d1dd8
	if (cr6.eq) goto loc_823D1DD8;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d1dbc
	if (cr6.eq) goto loc_823D1DBC;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r9,12288
	ctx.r9.s64 = 805306368;
	// rlwinm r8,r11,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x823d1dc0
	if (cr6.eq) goto loc_823D1DC0;
loc_823D1DBC:
	// li r11,0
	r11.s64 = 0;
loc_823D1DC0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d1dd8
	if (cr6.eq) goto loc_823D1DD8;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x823d1ddc
	goto loc_823D1DDC;
loc_823D1DD8:
	// li r30,0
	r30.s64 = 0;
loc_823D1DDC:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-10820
	ctx.r10.s64 = r11.s64 + -10820;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d1e98
	if (!cr6.eq) goto loc_823D1E98;
	// lhz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x823d1e24
	if (!cr6.gt) goto loc_823D1E24;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
loc_823D1E04:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x823d1e34
	if (cr6.eq) goto loc_823D1E34;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r4,r10
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r10.s32, xer);
	// blt cr6,0x823d1e04
	if (cr6.lt) goto loc_823D1E04;
loc_823D1E24:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_823D1E34:
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d1300
	ctx.lr = 0x823D1E44;
	sub_823D1300(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8239efb0
	ctx.lr = 0x823D1E50;
	sub_8239EFB0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D1E68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823a0980
	ctx.lr = 0x823D1E88;
	sub_823A0980(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_823D1E98:
	// lhz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x823d1e24
	if (!cr6.gt) goto loc_823D1E24;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
loc_823D1EAC:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r31,16(r8)
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d1ed4
	if (cr6.eq) goto loc_823D1ED4;
	// lwz r8,132(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bge cr6,0x823d1ed4
	if (!cr6.lt) goto loc_823D1ED4;
	// lbz r8,129(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 129);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823d1ef4
	if (cr6.eq) goto loc_823D1EF4;
loc_823D1ED4:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x823d1eac
	if (cr6.lt) goto loc_823D1EAC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_823D1EF4:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8239efb0
	ctx.lr = 0x823D1F00;
	sub_8239EFB0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D1F18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823a0980
	ctx.lr = 0x823D1F38;
	sub_823A0980(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823D1F48"))) PPC_WEAK_FUNC(sub_823D1F48);
PPC_FUNC_IMPL(__imp__sub_823D1F48) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x823D1F50;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x823d1f94
	if (cr6.eq) goto loc_823D1F94;
	// bl 0x822a86e8
	ctx.lr = 0x823D1F88;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d202c
	if (cr6.eq) goto loc_823D202C;
loc_823D1F94:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823d1fe0
	if (cr6.eq) goto loc_823D1FE0;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d1fc4
	if (cr6.eq) goto loc_823D1FC4;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r9,12288
	ctx.r9.s64 = 805306368;
	// rlwinm r8,r11,0,2,3
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x30000000;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x823d1fc8
	if (cr6.eq) goto loc_823D1FC8;
loc_823D1FC4:
	// li r11,0
	r11.s64 = 0;
loc_823D1FC8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d1fe0
	if (cr6.eq) goto loc_823D1FE0;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x823d1fe4
	goto loc_823D1FE4;
loc_823D1FE0:
	// li r30,0
	r30.s64 = 0;
loc_823D1FE4:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-10820
	ctx.r10.s64 = r11.s64 + -10820;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823d20a0
	if (!cr6.eq) goto loc_823D20A0;
	// lhz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x823d202c
	if (!cr6.gt) goto loc_823D202C;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
loc_823D200C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x823d203c
	if (cr6.eq) goto loc_823D203C;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r4,r10
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r10.s32, xer);
	// blt cr6,0x823d200c
	if (cr6.lt) goto loc_823D200C;
loc_823D202C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_823D203C:
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d1300
	ctx.lr = 0x823D204C;
	sub_823D1300(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8239efb0
	ctx.lr = 0x823D2058;
	sub_8239EFB0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D2070;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8239fb38
	ctx.lr = 0x823D2090;
	sub_8239FB38(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_823D20A0:
	// lhz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 76);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x823d202c
	if (!cr6.gt) goto loc_823D202C;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
loc_823D20B4:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r31,16(r8)
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d20dc
	if (cr6.eq) goto loc_823D20DC;
	// lwz r8,132(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bge cr6,0x823d20dc
	if (!cr6.lt) goto loc_823D20DC;
	// lbz r8,129(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 129);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823d20fc
	if (cr6.eq) goto loc_823D20FC;
loc_823D20DC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x823d20b4
	if (cr6.lt) goto loc_823D20B4;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_823D20FC:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8239efb0
	ctx.lr = 0x823D2108;
	sub_8239EFB0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D2120;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8239fb38
	ctx.lr = 0x823D2140;
	sub_8239FB38(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823D2150"))) PPC_WEAK_FUNC(sub_823D2150);
PPC_FUNC_IMPL(__imp__sub_823D2150) {
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
	// addi r10,r11,-16476
	ctx.r10.s64 = r11.s64 + -16476;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x823D2180;
	sub_82130588(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823d2190
	if (cr6.eq) goto loc_823D2190;
	// bl 0x82130588
	ctx.lr = 0x823D2190;
	sub_82130588(ctx, base);
loc_823D2190:
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,28(r31)
	PPC_STORE_U8(r31.u32 + 28, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// bl 0x822e6e68
	ctx.lr = 0x823D21A8;
	sub_822E6E68(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823d21c0
	if (cr6.eq) goto loc_823D21C0;
	// bl 0x82130588
	ctx.lr = 0x823D21BC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823D21C0:
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

__attribute__((alias("__imp__sub_823D21D8"))) PPC_WEAK_FUNC(sub_823D21D8);
PPC_FUNC_IMPL(__imp__sub_823D21D8) {
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
	// bl 0x822e6f68
	ctx.lr = 0x823D21F0;
	sub_822E6F68(ctx, base);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// addi r10,r11,-16476
	ctx.r10.s64 = r11.s64 + -16476;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x823D2204;
	sub_821B5A60(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
	// stw r11,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r11.u32);
	// stw r11,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r11.u32);
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

__attribute__((alias("__imp__sub_823D2270"))) PPC_WEAK_FUNC(sub_823D2270);
PPC_FUNC_IMPL(__imp__sub_823D2270) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r10,r11,-16280
	ctx.r10.s64 = r11.s64 + -16280;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x823D2298;
	sub_821B5A60(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821b5a60
	ctx.lr = 0x823D22A0;
	sub_821B5A60(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x821b5a60
	ctx.lr = 0x823D22A8;
	sub_821B5A60(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
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

__attribute__((alias("__imp__sub_823D22D0"))) PPC_WEAK_FUNC(sub_823D22D0);
PPC_FUNC_IMPL(__imp__sub_823D22D0) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r10,r11,-16264
	ctx.r10.s64 = r11.s64 + -16264;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x823D22F8;
	sub_821B5A60(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821b5a60
	ctx.lr = 0x823D2300;
	sub_821B5A60(ctx, base);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// bl 0x821b5a60
	ctx.lr = 0x823D2308;
	sub_821B5A60(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
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

__attribute__((alias("__imp__sub_823D2330"))) PPC_WEAK_FUNC(sub_823D2330);
PPC_FUNC_IMPL(__imp__sub_823D2330) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x823D2338;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x823D2368;
	sub_821C8FE0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r31,r11,3998
	r31.s64 = r11.s64 + 3998;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8239e458
	ctx.lr = 0x823D2394;
	sub_8239E458(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-10820
	ctx.r10.s64 = r11.s64 + -10820;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d23b0
	if (cr6.eq) goto loc_823D23B0;
	// li r11,1
	r11.s64 = 1;
	// stb r11,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, r11.u8);
loc_823D23B0:
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d23c0
	if (cr6.eq) goto loc_823D23C0;
	// lwz r31,4(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 4);
loc_823D23C0:
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8239e6b0
	ctx.lr = 0x823D23D0;
	sub_8239E6B0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r5,r11,10372
	ctx.r5.s64 = r11.s64 + 10372;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x82137a08
	ctx.lr = 0x823D23EC;
	sub_82137A08(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lwz r3,17432(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17432);
	// bl 0x822e6a80
	ctx.lr = 0x823D23FC;
	sub_822E6A80(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d2420
	if (cr6.eq) goto loc_823D2420;
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
	ctx.lr = 0x823D2420;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D2420:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d2484
	if (cr6.eq) goto loc_823D2484;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d1d40
	ctx.lr = 0x823D244C;
	sub_823D1D40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d2484
	if (cr6.eq) goto loc_823D2484;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lwz r3,108(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x82130588
	ctx.lr = 0x823D246C;
	sub_82130588(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D2474;
	sub_821C9030(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_823D2484:
	// lwz r3,108(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x82130588
	ctx.lr = 0x823D248C;
	sub_82130588(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D2494;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823D24A4"))) PPC_WEAK_FUNC(sub_823D24A4);
PPC_FUNC_IMPL(__imp__sub_823D24A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D24A8"))) PPC_WEAK_FUNC(sub_823D24A8);
PPC_FUNC_IMPL(__imp__sub_823D24A8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x823D24B0;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x823D24E0;
	sub_821C8FE0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r31,r11,3998
	r31.s64 = r11.s64 + 3998;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8239e458
	ctx.lr = 0x823D250C;
	sub_8239E458(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r10,r11,-10820
	ctx.r10.s64 = r11.s64 + -10820;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d2528
	if (cr6.eq) goto loc_823D2528;
	// li r11,1
	r11.s64 = 1;
	// stb r11,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, r11.u8);
loc_823D2528:
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d2538
	if (cr6.eq) goto loc_823D2538;
	// lwz r31,4(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 4);
loc_823D2538:
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8239e6b0
	ctx.lr = 0x823D2548;
	sub_8239E6B0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r5,r11,10372
	ctx.r5.s64 = r11.s64 + 10372;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x82137a08
	ctx.lr = 0x823D2564;
	sub_82137A08(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lwz r3,17432(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17432);
	// bl 0x822e6a80
	ctx.lr = 0x823D2574;
	sub_822E6A80(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823d2598
	if (cr6.eq) goto loc_823D2598;
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
	ctx.lr = 0x823D2598;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823D2598:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823d25fc
	if (cr6.eq) goto loc_823D25FC;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d1f48
	ctx.lr = 0x823D25C4;
	sub_823D1F48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d25fc
	if (cr6.eq) goto loc_823D25FC;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// lwz r3,108(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x82130588
	ctx.lr = 0x823D25E4;
	sub_82130588(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D25EC;
	sub_821C9030(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_823D25FC:
	// lwz r3,108(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// bl 0x82130588
	ctx.lr = 0x823D2604;
	sub_82130588(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x823D260C;
	sub_821C9030(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823D261C"))) PPC_WEAK_FUNC(sub_823D261C);
PPC_FUNC_IMPL(__imp__sub_823D261C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D2620"))) PPC_WEAK_FUNC(sub_823D2620);
PPC_FUNC_IMPL(__imp__sub_823D2620) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823D2628;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r3,-12720(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12720);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D2654;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d2664
	if (cr6.eq) goto loc_823D2664;
	// stw r30,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r30.u32);
loc_823D2664:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r7,-32137
	ctx.r7.s64 = -2106130432;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lis r6,-32195
	ctx.r6.s64 = -2109931520;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// addi r7,r7,-11448
	ctx.r7.s64 = ctx.r7.s64 + -11448;
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// addi r6,r6,6520
	ctx.r6.s64 = ctx.r6.s64 + 6520;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// oris r3,r5,2048
	ctx.r3.u64 = ctx.r5.u64 | 134217728;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// stw r31,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r31.u32);
	// lwz r3,-12720(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12720);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D26BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-12720(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12720);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823D26D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823D26DC"))) PPC_WEAK_FUNC(sub_823D26DC);
PPC_FUNC_IMPL(__imp__sub_823D26DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823D26E0"))) PPC_WEAK_FUNC(sub_823D26E0);
PPC_FUNC_IMPL(__imp__sub_823D26E0) {
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
	ctx.lr = 0x823D2710;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d2724
	if (cr6.eq) goto loc_823D2724;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
loc_823D2724:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d2738
	if (cr6.eq) goto loc_823D2738;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_823D2738:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// bne cr6,0x823d276c
	if (!cr6.eq) goto loc_823D276C;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x823d276c
	if (!cr6.eq) goto loc_823D276C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r9,r10,0,5,3
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFF7FFFFFF;
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
loc_823D276C:
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32137
	ctx.r10.s64 = -2106130432;
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
	// addi r6,r10,-11448
	ctx.r6.s64 = ctx.r10.s64 + -11448;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r5,r9,6520
	ctx.r5.s64 = ctx.r9.s64 + 6520;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823D27A4;
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
	ctx.lr = 0x823D27B8;
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

__attribute__((alias("__imp__sub_823D27D0"))) PPC_WEAK_FUNC(sub_823D27D0);
PPC_FUNC_IMPL(__imp__sub_823D27D0) {
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
	// beq cr6,0x823d2850
	if (cr6.eq) goto loc_823D2850;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823d2834
	if (cr6.eq) goto loc_823D2834;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823d2828
	if (!cr6.eq) goto loc_823D2828;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x823d2828
	if (!cr6.eq) goto loc_823D2828;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x823d282c
	if (!cr6.eq) goto loc_823D282C;
loc_823D2828:
	// li r11,1
	r11.s64 = 1;
loc_823D282C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// b 0x823d2838
	goto loc_823D2838;
loc_823D2834:
	// li r11,0
	r11.s64 = 0;
loc_823D2838:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d284c
	if (cr6.eq) goto loc_823D284C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d26e0
	ctx.lr = 0x823D284C;
	sub_823D26E0(ctx, base);
loc_823D284C:
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
loc_823D2850:
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

__attribute__((alias("__imp__sub_823D2868"))) PPC_WEAK_FUNC(sub_823D2868);
PPC_FUNC_IMPL(__imp__sub_823D2868) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x823D2870;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r3,-12720(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12720);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D289C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823d28ac
	if (cr6.eq) goto loc_823D28AC;
	// stw r30,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r30.u32);
loc_823D28AC:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r7,-32195
	ctx.r7.s64 = -2109931520;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lis r6,-32195
	ctx.r6.s64 = -2109931520;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// addi r7,r7,6536
	ctx.r7.s64 = ctx.r7.s64 + 6536;
	// stw r10,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r10.u32);
	// addi r6,r6,6528
	ctx.r6.s64 = ctx.r6.s64 + 6528;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// oris r3,r5,2048
	ctx.r3.u64 = ctx.r5.u64 | 134217728;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// stw r31,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r31.u32);
	// lwz r3,-12720(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12720);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D2904;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-12720(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12720);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823D2918;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

