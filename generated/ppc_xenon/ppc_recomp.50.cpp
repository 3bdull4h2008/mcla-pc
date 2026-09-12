#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82302980"))) PPC_WEAK_FUNC(sub_82302980);
PPC_FUNC_IMPL(__imp__sub_82302980) {
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
	ctx.lr = 0x82302988;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r3,r30,7,0,24
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 7) & 0xFFFFFF80;
	// bl 0x82130528
	ctx.lr = 0x82302998;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x823029c4
	if (!cr6.gt) goto loc_823029C4;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_823029A8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823029b8
	if (cr6.eq) goto loc_823029B8;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x822fe3a8
	ctx.lr = 0x823029B8;
	sub_822FE3A8(ctx, base);
loc_823029B8:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,128
	r31.s64 = r31.s64 + 128;
	// bne 0x823029a8
	if (!cr0.eq) goto loc_823029A8;
loc_823029C4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823029D0"))) PPC_WEAK_FUNC(sub_823029D0);
PPC_FUNC_IMPL(__imp__sub_823029D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
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
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r31,r10,-18216
	r31.s64 = ctx.r10.s64 + -18216;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lhz r10,6(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bge cr6,0x82302ad4
	if (!cr6.lt) goto loc_82302AD4;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,-7436(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -7436);
	// rlwinm r10,r8,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,24(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x822f1b08
	ctx.lr = 0x82302A34;
	sub_822F1B08(ctx, base);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lbz r4,184(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 184);
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x82302ad4
	if (!cr6.eq) goto loc_82302AD4;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,-26876(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -26876);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,11436(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11436);
	f0.f64 = double(temp.f32);
	// fmuls f10,f0,f0
	ctx.f10.f64 = double(float(f0.f64 * f0.f64));
	// lfs f9,116(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 116);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f11.f64));
	// lfs f7,120(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 120);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f13.f64));
	// lfs f5,112(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 112);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f4,f8,f8
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fsubs f3,f5,f12
	ctx.f3.f64 = double(float(ctx.f5.f64 - ctx.f12.f64));
	// fmadds f2,f6,f6,f4
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fmadds f0,f3,f3,f2
	f0.f64 = double(float(ctx.f3.f64 * ctx.f3.f64 + ctx.f2.f64));
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bge cr6,0x82302ad4
	if (!cr6.lt) goto loc_82302AD4;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// fsqrts f0,f0
	f0.f64 = double(float(sqrt(f0.f64)));
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,7
	r11.u64 = __builtin_rotateleft32(r11.u32, 7);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// add r30,r11,r10
	r30.u64 = r11.u64 + ctx.r10.u64;
	// sth r9,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r9.u16);
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// stfs f0,0(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// bl 0x822f1538
	ctx.lr = 0x82302AD0;
	sub_822F1538(ctx, base);
	// stfs f31,112(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 112, temp.u32);
loc_82302AD4:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
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

__attribute__((alias("__imp__sub_82302AF0"))) PPC_WEAK_FUNC(sub_82302AF0);
PPC_FUNC_IMPL(__imp__sub_82302AF0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82302AF8;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f0,17032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	f0.f64 = double(temp.f32);
	// li r3,16
	ctx.r3.s64 = 16;
	// lfs f13,15000(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15000);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stw r9,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r9.u32);
	// stfs f13,56(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stw r8,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r8.u32);
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// bl 0x82130528
	ctx.lr = 0x82302B38;
	sub_82130528(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r30,r11,6300
	r30.s64 = r11.s64 + 6300;
	// lfs f31,7444(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f31.f64 = double(temp.f32);
	// beq cr6,0x82302b74
	if (cr6.eq) goto loc_82302B74;
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x82612890
	ctx.lr = 0x82302B70;
	sub_82612890(ctx, base);
	// b 0x82302b78
	goto loc_82302B78;
loc_82302B74:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82302B78:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x82302B84;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82302bb0
	if (cr6.eq) goto loc_82302BB0;
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,24
	ctx.r5.s64 = 24;
	// li r4,12
	ctx.r4.s64 = 12;
	// bl 0x82612890
	ctx.lr = 0x82302BAC;
	sub_82612890(ctx, base);
	// b 0x82302bb4
	goto loc_82302BB4;
loc_82302BB0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82302BB4:
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,6284
	ctx.r4.s64 = r11.s64 + 6284;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82302BD4;
	sub_8218A568(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r7,6272
	ctx.r4.s64 = ctx.r7.s64 + 6272;
	// lwz r6,12(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r3,20(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82302BF4;
	sub_8218A568(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,6256
	ctx.r4.s64 = ctx.r4.s64 + 6256;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82302C14;
	sub_8218A568(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,6244
	ctx.r4.s64 = ctx.r9.s64 + 6244;
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82302C34;
	sub_8218A568(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r7,6228
	ctx.r4.s64 = ctx.r7.s64 + 6228;
	// lwz r3,12(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82302C54;
	sub_8218A568(ctx, base);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,6216
	ctx.r4.s64 = ctx.r10.s64 + 6216;
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82302C74;
	sub_8218A568(ctx, base);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,6200
	ctx.r4.s64 = ctx.r8.s64 + 6200;
	// lwz r6,12(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r3,20(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82302C94;
	sub_8218A568(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// lis r30,-32119
	r30.s64 = -2104950784;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r29,r30,-18216
	r29.s64 = r30.s64 + -18216;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82302980
	ctx.lr = 0x82302CAC;
	sub_82302980(ctx, base);
	// li r11,256
	r11.s64 = 256;
	// stw r3,-18216(r30)
	PPC_STORE_U32(r30.u32 + -18216, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r11,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r11.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82302CC8"))) PPC_WEAK_FUNC(sub_82302CC8);
PPC_FUNC_IMPL(__imp__sub_82302CC8) {
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
	// lwz r31,16(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x82302CEC;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82302d14
	if (!cr6.eq) goto loc_82302D14;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82302d14
	if (cr6.eq) goto loc_82302D14;
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
	ctx.lr = 0x82302D14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82302D14:
	// lwz r31,24(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x82302D20;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82302d48
	if (!cr6.eq) goto loc_82302D48;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82302d48
	if (cr6.eq) goto loc_82302D48;
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
	ctx.lr = 0x82302D48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82302D48:
	// lwz r31,28(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x82302D54;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82302d7c
	if (!cr6.eq) goto loc_82302D7C;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82302d7c
	if (cr6.eq) goto loc_82302D7C;
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
	ctx.lr = 0x82302D7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82302D7C:
	// lwz r31,32(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x82302D88;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82302db0
	if (!cr6.eq) goto loc_82302DB0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82302db0
	if (cr6.eq) goto loc_82302DB0;
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
	ctx.lr = 0x82302DB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82302DB0:
	// lwz r31,36(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x82302DBC;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82302de4
	if (!cr6.eq) goto loc_82302DE4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82302de4
	if (cr6.eq) goto loc_82302DE4;
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
	ctx.lr = 0x82302DE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82302DE4:
	// lwz r3,272(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 272);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82302df4
	if (cr6.eq) goto loc_82302DF4;
	// bl 0x82130588
	ctx.lr = 0x82302DF4;
	sub_82130588(ctx, base);
loc_82302DF4:
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

__attribute__((alias("__imp__sub_82302E0C"))) PPC_WEAK_FUNC(sub_82302E0C);
PPC_FUNC_IMPL(__imp__sub_82302E0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82302E10"))) PPC_WEAK_FUNC(sub_82302E10);
PPC_FUNC_IMPL(__imp__sub_82302E10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bge cr6,0x82302e2c
	if (!cr6.lt) goto loc_82302E2C;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
loc_82302E2C:
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rotlwi r11,r4,1
	r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// divw r7,r4,r9
	ctx.r7.s32 = ctx.r4.s32 / ctx.r9.s32;
	// addi r31,r11,-1
	r31.s64 = r11.s64 + -1;
	// mullw r11,r7,r9
	r11.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// lfs f0,15360(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 15360);
	f0.f64 = double(temp.f32);
	// subf r8,r11,r4
	ctx.r8.s64 = ctx.r4.s64 - r11.s64;
	// rotlwi r10,r4,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r7,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r7.u32);
	// twllei r9,0
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// andc r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r10.u64;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// divw r7,r4,r8
	ctx.r7.s32 = ctx.r4.s32 / ctx.r8.s32;
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// extsw r4,r7
	ctx.r4.s64 = ctx.r7.s32;
	// extsw r3,r5
	ctx.r3.s64 = ctx.r5.s32;
	// std r4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r4.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r3,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r3.u64);
	// lfd f12,-16(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// andc r11,r8,r31
	r11.u64 = ctx.r8.u64 & ~r31.u64;
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// twllei r8,0
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// twlgei r9,-1
	// twlgei r11,-1
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fdivs f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 / ctx.f8.f64));
	// fmuls f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64));
	// fctiwz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfiwx f5,0,r6
	PPC_STORE_U32(ctx.r6.u32, ctx.f5.u32);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82302EC4"))) PPC_WEAK_FUNC(sub_82302EC4);
PPC_FUNC_IMPL(__imp__sub_82302EC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82302EC8"))) PPC_WEAK_FUNC(sub_82302EC8);
PPC_FUNC_IMPL(__imp__sub_82302EC8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82302ED0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// addi r6,r1,92
	ctx.r6.s64 = ctx.r1.s64 + 92;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// mr r25,r10
	r25.u64 = ctx.r10.u64;
	// bl 0x82302e10
	ctx.lr = 0x82302F00;
	sub_82302E10(ctx, base);
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82302e10
	ctx.lr = 0x82302F14;
	sub_82302E10(ctx, base);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82302e10
	ctx.lr = 0x82302F28;
	sub_82302E10(ctx, base);
	// addi r6,r1,104
	ctx.r6.s64 = ctx.r1.s64 + 104;
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// lwz r4,260(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82302e10
	ctx.lr = 0x82302F3C;
	sub_82302E10(ctx, base);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// rlwimi r10,r9,8,16,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFF00) | (ctx.r10.u64 & 0xFFFFFFFFFFFF00FF);
	// lwz r8,88(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mullw r11,r11,r27
	r11.s64 = int64_t(r11.s32) * int64_t(r27.s32);
	// lwz r7,92(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r6,96(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r5,100(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// clrlwi r3,r10,16
	ctx.r3.u64 = ctx.r10.u32 & 0xFFFF;
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// rlwimi r7,r3,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r3.u32, 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwimi r5,r7,8,0,23
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFFFFFF00) | (ctx.r5.u64 & 0xFFFFFFFF000000FF);
	// lwz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r9,108(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// rlwimi r8,r10,8,16,23
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF00) | (ctx.r8.u64 & 0xFFFFFFFFFFFF00FF);
	// stwx r5,r11,r28
	PPC_STORE_U32(r11.u32 + r28.u32, ctx.r5.u32);
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// rlwimi r6,r8,8,0,23
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFFFFFF00) | (ctx.r6.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r9,r6,8,0,23
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r6.u32, 8) & 0xFFFFFF00) | (ctx.r9.u64 & 0xFFFFFFFF000000FF);
	// stwx r9,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, ctx.r9.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82302F9C"))) PPC_WEAK_FUNC(sub_82302F9C);
PPC_FUNC_IMPL(__imp__sub_82302F9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82302FA0"))) PPC_WEAK_FUNC(sub_82302FA0);
PPC_FUNC_IMPL(__imp__sub_82302FA0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82302FA8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// addi r4,r10,-11956
	ctx.r4.s64 = ctx.r10.s64 + -11956;
	// stw r5,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r5.u32);
	// stw r6,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r6.u32);
	// stw r6,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r6.u32);
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x823db730
	ctx.lr = 0x82302FD4;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82302fe8
	if (!cr6.eq) goto loc_82302FE8;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
loc_82302FE8:
	// li r29,0
	r29.s64 = 0;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// li r6,11
	ctx.r6.s64 = 11;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8218de38
	ctx.lr = 0x82303020;
	sub_8218DE38(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8218de38
	ctx.lr = 0x82303048;
	sub_8218DE38(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8218de38
	ctx.lr = 0x82303070;
	sub_8218DE38(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x8218de38
	ctx.lr = 0x82303098;
	sub_8218DE38(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x8218de38
	ctx.lr = 0x823030C0;
	sub_8218DE38(ctx, base);
	// lis r24,-32124
	r24.s64 = -2105278464;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r3,-25232(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -25232);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823030E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lwz r3,-25232(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -25232);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82303104;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// lwz r3,-25232(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -25232);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82303124;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// lwz r3,-25232(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -25232);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82303144;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,-25232(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -25232);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82303164;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r29.u32);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// lwz r8,32(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// addic. r11,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	r11.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,32(r30)
	PPC_STORE_U32(r30.u32 + 32, r11.u32);
	// bne 0x8230318c
	if (!cr0.eq) goto loc_8230318C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8218cd10
	ctx.lr = 0x82303184;
	sub_8218CD10(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x8230318C;
	sub_82130588(ctx, base);
loc_8230318C:
	// lwz r11,32(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,32(r28)
	PPC_STORE_U32(r28.u32 + 32, r11.u32);
	// bne 0x823031ac
	if (!cr0.eq) goto loc_823031AC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8218cd10
	ctx.lr = 0x823031A4;
	sub_8218CD10(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x823031AC;
	sub_82130588(ctx, base);
loc_823031AC:
	// lwz r11,32(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,32(r27)
	PPC_STORE_U32(r27.u32 + 32, r11.u32);
	// bne 0x823031cc
	if (!cr0.eq) goto loc_823031CC;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8218cd10
	ctx.lr = 0x823031C4;
	sub_8218CD10(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130588
	ctx.lr = 0x823031CC;
	sub_82130588(ctx, base);
loc_823031CC:
	// lwz r11,32(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,32(r26)
	PPC_STORE_U32(r26.u32 + 32, r11.u32);
	// bne 0x823031ec
	if (!cr0.eq) goto loc_823031EC;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8218cd10
	ctx.lr = 0x823031E4;
	sub_8218CD10(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130588
	ctx.lr = 0x823031EC;
	sub_82130588(ctx, base);
loc_823031EC:
	// lwz r11,32(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,32(r25)
	PPC_STORE_U32(r25.u32 + 32, r11.u32);
	// bne 0x8230320c
	if (!cr0.eq) goto loc_8230320C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8218cd10
	ctx.lr = 0x82303204;
	sub_8218CD10(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82130588
	ctx.lr = 0x8230320C;
	sub_82130588(ctx, base);
loc_8230320C:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r30,r31,40
	r30.s64 = r31.s64 + 40;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82303230;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82303248;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8230328c
	if (cr6.eq) goto loc_8230328C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r30,r31,72
	r30.s64 = r31.s64 + 72;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82303274;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8230328C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8230328C:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r30,r31,104
	r30.s64 = r31.s64 + 104;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823032B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823032C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r30,r31,168
	r30.s64 = r31.s64 + 168;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,76(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823032EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,80(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82303304;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r30,r31,136
	r30.s64 = r31.s64 + 136;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82303328;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,80(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 80);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82303340;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r30,r31,200
	r30.s64 = r31.s64 + 200;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82303364;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8230337C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// addi r6,r7,-7432
	ctx.r6.s64 = ctx.r7.s64 + -7432;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823033dc
	if (cr6.eq) goto loc_823033DC;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// ori r8,r10,65535
	ctx.r8.u64 = ctx.r10.u64 | 65535;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bgt cr6,0x823033c4
	if (cr6.gt) goto loc_823033C4;
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// rlwinm r3,r11,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// ble cr6,0x823033c8
	if (!cr6.gt) goto loc_823033C8;
loc_823033C4:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_823033C8:
	// bl 0x82130528
	ctx.lr = 0x823033CC;
	sub_82130528(ctx, base);
	// stw r3,272(r31)
	PPC_STORE_U32(r31.u32 + 272, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_823033DC:
	// stw r29,272(r31)
	PPC_STORE_U32(r31.u32 + 272, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_823033EC"))) PPC_WEAK_FUNC(sub_823033EC);
PPC_FUNC_IMPL(__imp__sub_823033EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823033F0"))) PPC_WEAK_FUNC(sub_823033F0);
PPC_FUNC_IMPL(__imp__sub_823033F0) {
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
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x823033F8;
	// stfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f30.u64);
	// stfd f31,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mullw r7,r10,r11
	ctx.r7.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// bge cr6,0x82303654
	if (!cr6.lt) goto loc_82303654;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lfs f13,64(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lbz r5,89(r9)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r9.u32 + 89);
	// rotlwi r10,r8,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// rotlwi r7,r8,1
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// divw r31,r8,r11
	r31.s32 = ctx.r8.s32 / r11.s32;
	// lfs f0,9896(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 9896);
	f0.f64 = double(temp.f32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// lfs f0,-32720(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -32720);
	f0.f64 = double(temp.f32);
	// mullw r6,r31,r11
	ctx.r6.s64 = int64_t(r31.s32) * int64_t(r11.s32);
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * f0.f64));
	// andc r4,r11,r10
	ctx.r4.u64 = r11.u64 & ~ctx.r10.u64;
	// andc r7,r11,r7
	ctx.r7.u64 = r11.u64 & ~ctx.r7.u64;
	// subf r10,r6,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r6.s64;
	// twllei r11,0
	// twlgei r4,-1
	// divw r8,r8,r11
	ctx.r8.s32 = ctx.r8.s32 / r11.s32;
	// twllei r11,0
	// twlgei r7,-1
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82303490
	if (!cr6.eq) goto loc_82303490;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f12,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
loc_82303490:
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f11,244(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 244);
	ctx.f11.f64 = double(temp.f32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lfs f10,260(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	ctx.f10.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lfs f31,76(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	f31.f64 = double(temp.f32);
	// addi r31,r1,112
	r31.s64 = ctx.r1.s64 + 112;
	// lfs f30,80(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	f30.f64 = double(temp.f32);
	// lfs f13,31492(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 31492);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r29,r1,128
	r29.s64 = ctx.r1.s64 + 128;
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r28,r1,128
	r28.s64 = ctx.r1.s64 + 128;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r6,16
	ctx.r6.s64 = 16;
	// lvx128 v0,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r24,r1,96
	r24.s64 = ctx.r1.s64 + 96;
	// lfs f0,14884(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14884);
	f0.f64 = double(temp.f32);
	// li r7,32
	ctx.r7.s64 = 32;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lvlx128 v62,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lvx128 v13,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r9,r7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lfs f9,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f9.f64 = double(temp.f32);
	// vmaddfp v11,v12,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v11,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lvx128 v60,r9,r6
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmsubs f8,f11,f9,f10
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f9.f64 - ctx.f10.f64));
	// vmulfp128 v59,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// lfs f5,132(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f4.f64 = double(temp.f32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lfs f6,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f6.f64 = double(temp.f32);
	// stvx128 v63,r0,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// stfs f8,140(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f6,128(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stvx128 v59,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r31,r11,2,0,29
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f3,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f2.f64 = double(temp.f32);
	// lfs f7,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f7.f64 = double(temp.f32);
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f7,120(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f2,116(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f3,112(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f5,132(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f4,136(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// bne cr6,0x823035d4
	if (!cr6.eq) goto loc_823035D4;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// add r30,r11,r27
	r30.u64 = r11.u64 + r27.u64;
	// bl 0x8213e850
	ctx.lr = 0x8230358C;
	sub_8213E850(ctx, base);
	// lhz r11,80(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lfs f1,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f1.f64 = double(temp.f32);
	// sth r11,0(r30)
	PPC_STORE_U16(r30.u32 + 0, r11.u16);
	// bl 0x8213e850
	ctx.lr = 0x823035A0;
	sub_8213E850(ctx, base);
	// lhz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// sth r10,2(r30)
	PPC_STORE_U16(r30.u32 + 2, ctx.r10.u16);
	// bl 0x8213e850
	ctx.lr = 0x823035B4;
	sub_8213E850(ctx, base);
	// lhz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// sth r9,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r9.u16);
	// bl 0x8213e850
	ctx.lr = 0x823035C8;
	sub_8213E850(ctx, base);
	// lhz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// sth r8,6(r30)
	PPC_STORE_U16(r30.u32 + 6, ctx.r8.u16);
	// b 0x82303628
	goto loc_82303628;
loc_823035D4:
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// add r29,r31,r27
	r29.u64 = r31.u64 + r27.u64;
	// add r28,r31,r30
	r28.u64 = r31.u64 + r30.u64;
	// bl 0x8213e850
	ctx.lr = 0x823035E4;
	sub_8213E850(ctx, base);
	// lhz r11,84(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f1,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f1.f64 = double(temp.f32);
	// sthx r11,r31,r27
	PPC_STORE_U16(r31.u32 + r27.u32, r11.u16);
	// bl 0x8213e850
	ctx.lr = 0x823035F8;
	sub_8213E850(ctx, base);
	// lhz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// sth r10,2(r29)
	PPC_STORE_U16(r29.u32 + 2, ctx.r10.u16);
	// bl 0x8213e850
	ctx.lr = 0x8230360C;
	sub_8213E850(ctx, base);
	// lhz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// sthx r9,r31,r30
	PPC_STORE_U16(r31.u32 + r30.u32, ctx.r9.u16);
	// bl 0x8213e850
	ctx.lr = 0x82303620;
	sub_8213E850(ctx, base);
	// lhz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// sth r8,2(r28)
	PPC_STORE_U16(r28.u32 + 2, ctx.r8.u16);
loc_82303628:
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// bl 0x821d2470
	ctx.lr = 0x82303634;
	sub_821D2470(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stwx r10,r31,r26
	PPC_STORE_U32(r31.u32 + r26.u32, ctx.r10.u32);
	// bl 0x821d2470
	ctx.lr = 0x8230364C;
	sub_821D2470(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stwx r9,r31,r25
	PPC_STORE_U32(r31.u32 + r25.u32, ctx.r9.u32);
loc_82303654:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82303664"))) PPC_WEAK_FUNC(sub_82303664);
PPC_FUNC_IMPL(__imp__sub_82303664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82303668"))) PPC_WEAK_FUNC(sub_82303668);
PPC_FUNC_IMPL(__imp__sub_82303668) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// lwz r4,44(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x82303688
	if (cr6.eq) goto loc_82303688;
	// lwz r11,76(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
loc_82303688:
	// lwz r7,172(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 172);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r6,108(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// b 0x823033f0
	sub_823033F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8230369C"))) PPC_WEAK_FUNC(sub_8230369C);
PPC_FUNC_IMPL(__imp__sub_8230369C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823036A0"))) PPC_WEAK_FUNC(sub_823036A0);
PPC_FUNC_IMPL(__imp__sub_823036A0) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister f0{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x823036A8;
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lfs f0,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	f0.f64 = double(temp.f32);
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// fsubs f12,f0,f1
	ctx.f12.f64 = double(float(f0.f64 - ctx.f1.f64));
	// extsw r11,r9
	r11.s64 = ctx.r9.s32;
	// lfs f13,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// extsw r10,r8
	ctx.r10.s64 = ctx.r8.s32;
	// fadds f11,f0,f1
	ctx.f11.f64 = double(float(f0.f64 + ctx.f1.f64));
	// std r11,-144(r1)
	PPC_STORE_U64(ctx.r1.u32 + -144, r11.u64);
	// lfd f10,-144(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// std r10,-144(r1)
	PPC_STORE_U64(ctx.r1.u32 + -144, ctx.r10.u64);
	// lfd f9,-144(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// fsubs f4,f13,f1
	ctx.f4.f64 = double(float(ctx.f13.f64 - ctx.f1.f64));
	// lfs f7,240(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 240);
	ctx.f7.f64 = double(temp.f32);
	// fadds f2,f13,f1
	ctx.f2.f64 = double(float(ctx.f13.f64 + ctx.f1.f64));
	// lfs f5,256(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	ctx.f5.f64 = double(temp.f32);
	// fcfid f6,f10
	ctx.f6.f64 = double(ctx.f10.s64);
	// lfs f3,248(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 248);
	ctx.f3.f64 = double(temp.f32);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// lfs f1,264(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 264);
	ctx.f1.f64 = double(temp.f32);
	// fmsubs f13,f12,f7,f5
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f7.f64 - ctx.f5.f64));
	// addi r11,r8,-1
	r11.s64 = ctx.r8.s64 + -1;
	// fmsubs f12,f11,f7,f5
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f7.f64 - ctx.f5.f64));
	// fmsubs f10,f4,f3,f1
	ctx.f10.f64 = double(float(ctx.f4.f64 * ctx.f3.f64 - ctx.f1.f64));
	// fmsubs f9,f2,f3,f1
	ctx.f9.f64 = double(float(ctx.f2.f64 * ctx.f3.f64 - ctx.f1.f64));
	// frsp f11,f6
	ctx.f11.f64 = double(float(ctx.f6.f64));
	// frsp f0,f8
	f0.f64 = double(float(ctx.f8.f64));
	// fmuls f6,f10,f11
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// fmuls f5,f9,f11
	ctx.f5.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// fmuls f8,f13,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fmuls f7,f12,f0
	ctx.f7.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fctiwz f2,f6
	ctx.f2.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// fctiwz f1,f5
	ctx.f1.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f1,-136(r1)
	PPC_STORE_U64(ctx.r1.u32 + -136, ctx.f1.u64);
	// lwz r6,-132(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + -132);
	// fctiwz f4,f8
	ctx.f4.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f4,-144(r1)
	PPC_STORE_U64(ctx.r1.u32 + -144, ctx.f4.u64);
	// lwz r24,-140(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + -140);
	// fctiwz f3,f7
	ctx.f3.s64 = (ctx.f7.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f3,-144(r1)
	PPC_STORE_U64(ctx.r1.u32 + -144, ctx.f3.u64);
	// lwz r21,-140(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + -140);
	// stfd f2,-144(r1)
	PPC_STORE_U64(ctx.r1.u32 + -144, ctx.f2.u64);
	// lwz r10,-140(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -140);
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// bge cr6,0x82303764
	if (!cr6.lt) goto loc_82303764;
	// li r24,0
	r24.s64 = 0;
	// b 0x82303770
	goto loc_82303770;
loc_82303764:
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// ble cr6,0x82303770
	if (!cr6.gt) goto loc_82303770;
	// mr r24,r11
	r24.u64 = r11.u64;
loc_82303770:
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// bge cr6,0x82303780
	if (!cr6.lt) goto loc_82303780;
	// li r21,0
	r21.s64 = 0;
	// b 0x8230378c
	goto loc_8230378C;
loc_82303780:
	// cmpw cr6,r21,r11
	cr6.compare<int32_t>(r21.s32, r11.s32, xer);
	// ble cr6,0x8230378c
	if (!cr6.gt) goto loc_8230378C;
	// mr r21,r11
	r21.u64 = r11.u64;
loc_8230378C:
	// addi r11,r9,-1
	r11.s64 = ctx.r9.s64 + -1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge cr6,0x823037a0
	if (!cr6.lt) goto loc_823037A0;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x823037ac
	goto loc_823037AC;
loc_823037A0:
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// ble cr6,0x823037ac
	if (!cr6.gt) goto loc_823037AC;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_823037AC:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bge cr6,0x823037bc
	if (!cr6.lt) goto loc_823037BC;
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x823037c8
	goto loc_823037C8;
loc_823037BC:
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// ble cr6,0x823037c8
	if (!cr6.gt) goto loc_823037C8;
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
loc_823037C8:
	// lwz r11,140(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// lwz r7,204(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 204);
	// bgt cr6,0x823038f8
	if (cr6.gt) goto loc_823038F8;
	// mullw r9,r10,r8
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// add r5,r9,r24
	ctx.r5.u64 = ctx.r9.u64 + r24.u64;
	// subf r9,r10,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r10.s64;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r22,r8,2,0,29
	r22.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r25,r10,r11
	r25.u64 = ctx.r10.u64 + r11.u64;
	// subf r27,r11,r7
	r27.s64 = ctx.r7.s64 - r11.s64;
	// addi r23,r9,1
	r23.s64 = ctx.r9.s64 + 1;
loc_823037F8:
	// mr r29,r25
	r29.u64 = r25.u64;
	// cmpw cr6,r24,r21
	cr6.compare<int32_t>(r24.s32, r21.s32, xer);
	// bgt cr6,0x823038ec
	if (cr6.gt) goto loc_823038EC;
	// subf r11,r24,r21
	r11.s64 = r21.s64 - r24.s64;
	// addi r26,r11,1
	r26.s64 = r11.s64 + 1;
loc_8230380C:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r30,r1,-144
	r30.s64 = ctx.r1.s64 + -144;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r28,4
	r28.s64 = 4;
	// lwzx r8,r27,r29
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + r29.u32);
	// rlwinm r6,r10,24,24,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF;
	// clrlwi r20,r7,16
	r20.u64 = ctx.r7.u32 & 0xFFFF;
	// rlwinm r31,r10,8,24,31
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFF;
	// rlwinm r19,r8,24,24,31
	r19.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFF;
	// rlwinm r18,r8,8,24,31
	r18.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFF;
	// rlwinm r11,r10,15,25,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x7F;
	// rlwinm r9,r10,31,25,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7F;
	// rlwinm r7,r8,15,25,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 15) & 0x7F;
	// mullw r10,r6,r20
	ctx.r10.s64 = int64_t(ctx.r6.s32) * int64_t(r20.s32);
	// rlwinm r5,r8,31,25,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7F;
	// mullw r8,r31,r20
	ctx.r8.s64 = int64_t(r31.s32) * int64_t(r20.s32);
	// mullw r6,r19,r20
	ctx.r6.s64 = int64_t(r19.s32) * int64_t(r20.s32);
	// mullw r31,r18,r20
	r31.s64 = int64_t(r18.s32) * int64_t(r20.s32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r9,r6,r7
	ctx.r9.u64 = ctx.r6.u64 + ctx.r7.u64;
	// sth r11,-144(r1)
	PPC_STORE_U16(ctx.r1.u32 + -144, r11.u16);
	// add r8,r31,r5
	ctx.r8.u64 = r31.u64 + ctx.r5.u64;
	// sth r10,-142(r1)
	PPC_STORE_U16(ctx.r1.u32 + -142, ctx.r10.u16);
	// sth r9,-140(r1)
	PPC_STORE_U16(ctx.r1.u32 + -140, ctx.r9.u16);
	// sth r8,-138(r1)
	PPC_STORE_U16(ctx.r1.u32 + -138, ctx.r8.u16);
loc_82303874:
	// lhz r11,4(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// lhz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x823038ac
	if (!cr6.gt) goto loc_823038AC;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// clrlwi r8,r7,16
	ctx.r8.u64 = ctx.r7.u32 & 0xFFFF;
loc_82303890:
	// lhz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// cmplw cr6,r6,r8
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r8.u32, xer);
	// beq cr6,0x823038d4
	if (cr6.eq) goto loc_823038D4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// blt cr6,0x82303890
	if (cr6.lt) goto loc_82303890;
loc_823038AC:
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// bne cr6,0x823038d4
	if (!cr6.eq) goto loc_823038D4;
	// lhz r9,6(r4)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + 6);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x823038d4
	if (!cr6.lt) goto loc_823038D4;
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// sth r10,4(r4)
	PPC_STORE_U16(ctx.r4.u32 + 4, ctx.r10.u16);
	// sthx r7,r11,r9
	PPC_STORE_U16(r11.u32 + ctx.r9.u32, ctx.r7.u16);
loc_823038D4:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// bne 0x82303874
	if (!cr0.eq) goto loc_82303874;
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x8230380c
	if (!cr0.eq) goto loc_8230380C;
loc_823038EC:
	// addic. r23,r23,-1
	xer.ca = r23.u32 > 0;
	r23.s64 = r23.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// add r25,r22,r25
	r25.u64 = r22.u64 + r25.u64;
	// bne 0x823037f8
	if (!cr0.eq) goto loc_823037F8;
loc_823038F8:
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_823038FC"))) PPC_WEAK_FUNC(sub_823038FC);
PPC_FUNC_IMPL(__imp__sub_823038FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82303900"))) PPC_WEAK_FUNC(sub_82303900);
PPC_FUNC_IMPL(__imp__sub_82303900) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82303908;
	// lwz r9,12(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// li r10,240
	ctx.r10.s64 = 240;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// extsw r6,r11
	ctx.r6.s64 = r11.s32;
	// std r8,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r8.u64);
	// lfd f0,-64(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// std r6,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r6.u64);
	// lfd f13,-64(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lvx128 v62,r3,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,256
	ctx.r7.s64 = 256;
	// vmulfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// fcfid f11,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.f64 = double(f0.s64);
	// lvx128 v60,r3,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// vsubfp128 v59,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r8,r1,-64
	ctx.r8.s64 = ctx.r1.s64 + -64;
	// frsp f9,f11
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// stfs f9,-56(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// addi r7,r1,-48
	ctx.r7.s64 = ctx.r1.s64 + -48;
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// lfs f0,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,-60(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// stfs f10,-64(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// lvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v57,v59,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v58.f32)));
	// stvx128 v57,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,-48(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -48);
	ctx.f8.f64 = double(temp.f32);
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f7.u64);
	// lwz r11,-60(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -60);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x823039a0
	if (!cr6.lt) goto loc_823039A0;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x823039ac
	goto loc_823039AC;
loc_823039A0:
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bgt cr6,0x823039ac
	if (cr6.gt) goto loc_823039AC;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_823039AC:
	// lfs f0,-40(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -40);
	f0.f64 = double(temp.f32);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.f13.u64);
	// lwz r11,-60(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -60);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x823039d0
	if (!cr6.lt) goto loc_823039D0;
	// li r11,0
	r11.s64 = 0;
	// b 0x823039dc
	goto loc_823039DC;
loc_823039D0:
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// ble cr6,0x823039dc
	if (!cr6.gt) goto loc_823039DC;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_823039DC:
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r8,140(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r7,204(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 204);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// clrlwi r11,r6,16
	r11.u64 = ctx.r6.u32 & 0xFFFF;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r8,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lwzx r6,r7,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// rlwinm r3,r8,24,24,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFF;
	// rlwinm r31,r8,8,24,31
	r31.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFF;
	// rlwinm r30,r6,24,24,31
	r30.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0xFF;
	// rlwinm r29,r6,8,24,31
	r29.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFF;
	// rlwinm r9,r8,15,25,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 15) & 0x7F;
	// rlwinm r7,r8,31,25,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7F;
	// mullw r8,r3,r11
	ctx.r8.s64 = int64_t(ctx.r3.s32) * int64_t(r11.s32);
	// rlwinm r5,r6,15,25,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 15) & 0x7F;
	// rlwinm r10,r6,31,25,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7F;
	// mullw r6,r31,r11
	ctx.r6.s64 = int64_t(r31.s32) * int64_t(r11.s32);
	// mullw r3,r30,r11
	ctx.r3.s64 = int64_t(r30.s32) * int64_t(r11.s32);
	// mullw r11,r29,r11
	r11.s64 = int64_t(r29.s32) * int64_t(r11.s32);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r8,r6,r7
	ctx.r8.u64 = ctx.r6.u64 + ctx.r7.u64;
	// add r7,r3,r5
	ctx.r7.u64 = ctx.r3.u64 + ctx.r5.u64;
	// sth r9,0(r4)
	PPC_STORE_U16(ctx.r4.u32 + 0, ctx.r9.u16);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// sth r8,2(r4)
	PPC_STORE_U16(ctx.r4.u32 + 2, ctx.r8.u16);
	// sth r7,4(r4)
	PPC_STORE_U16(ctx.r4.u32 + 4, ctx.r7.u16);
	// sth r6,6(r4)
	PPC_STORE_U16(ctx.r4.u32 + 6, ctx.r6.u16);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82303A58"))) PPC_WEAK_FUNC(sub_82303A58);
PPC_FUNC_IMPL(__imp__sub_82303A58) {
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
	PPCVRegister v42{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82303A60;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9bc
	ctx.lr = 0x82303A68;
	// li r12,-256
	r12.s64 = -256;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-544(r1)
	ea = -544 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// stw r21,572(r1)
	PPC_STORE_U32(ctx.r1.u32 + 572, r21.u32);
	// stw r23,588(r1)
	PPC_STORE_U32(ctx.r1.u32 + 588, r23.u32);
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
loc_82303A8C:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82303a8c
	if (cr6.eq) goto loc_82303A8C;
	// lvx128 v62,r0,r25
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lvx128 v63,r0,r23
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// addi r3,r19,240
	ctx.r3.s64 = r19.s64 + 240;
	// addi r9,r10,-31664
	ctx.r9.s64 = ctx.r10.s64 + -31664;
	// std r11,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, r11.u64);
	// addi r10,r8,2384
	ctx.r10.s64 = ctx.r8.s64 + 2384;
	// vspltisw128 v60,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// addi r11,r19,256
	r11.s64 = r19.s64 + 256;
	// addi r8,r7,-31488
	ctx.r8.s64 = ctx.r7.s64 + -31488;
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// addi r31,r1,224
	r31.s64 = ctx.r1.s64 + 224;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// stvx128 v61,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v59,v61,v61
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v10,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrefp128 v0,v59
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v59.f32)));
	// vor128 v11,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vxor128 v57,v59,v59
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_setzero_si128());
	// vnmsubfp v12,v0,v11,v13
	simde_mm_store_ps(ctx.v12.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vand128 v58,v59,v62
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vmaddfp v9,v0,v12,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vcmpeqfp128 v13,v57,v58
	simde_mm_store_ps(ctx.v13.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v58.f32)));
	// vsel v8,v9,v10,v13
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8))));
	// vor128 v56,v8,v8
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// stvx128 v8,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r0,r23
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v54,v55,v56
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v56.f32)));
	// vor128 v53,v54,v54
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_load_si128((simde__m128i*)v54.u8));
	// stvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r23
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r25
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v50,v51,v52
	simde_mm_store_ps(v50.f32, simde_mm_sub_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v52.f32)));
	// vsubfp128 v49,v60,v53
	simde_mm_store_ps(v49.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v53.f32)));
	// stvx128 v50,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822fd3e8
	ctx.lr = 0x82303B4C;
	sub_822FD3E8(ctx, base);
	// lwz r6,20(r19)
	ctx.r6.u64 = PPC_LOAD_U32(r19.u32 + 20);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// lwz r26,44(r19)
	r26.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// beq cr6,0x82303b64
	if (cr6.eq) goto loc_82303B64;
	// lwz r27,76(r19)
	r27.u64 = PPC_LOAD_U32(r19.u32 + 76);
loc_82303B64:
	// lhz r24,4(r21)
	r24.u64 = PPC_LOAD_U16(r21.u32 + 4);
	// li r31,0
	r31.s64 = 0;
	// lwz r29,108(r19)
	r29.u64 = PPC_LOAD_U32(r19.u32 + 108);
	// lwz r28,172(r19)
	r28.u64 = PPC_LOAD_U32(r19.u32 + 172);
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// stw r24,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r24.u32);
	// ble cr6,0x82303bbc
	if (!cr6.gt) goto loc_82303BBC;
	// li r30,0
	r30.s64 = 0;
loc_82303B84:
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwzx r9,r11,r30
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x823033f0
	ctx.lr = 0x82303BAC;
	sub_823033F0(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r24
	cr6.compare<int32_t>(r31.s32, r24.s32, xer);
	// blt cr6,0x82303b84
	if (cr6.lt) goto loc_82303B84;
loc_82303BBC:
	// lvx128 v48,r0,r23
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lvx128 v47,r0,r25
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r17,8(r19)
	r17.u64 = PPC_LOAD_U32(r19.u32 + 8);
	// vsubfp128 v46,v47,v48
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v46.f32, simde_mm_sub_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v48.f32)));
	// lwz r22,12(r19)
	r22.u64 = PPC_LOAD_U32(r19.u32 + 12);
	// extsw r10,r17
	ctx.r10.s64 = r17.s32;
	// extsw r8,r22
	ctx.r8.s64 = r22.s32;
	// std r10,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r10.u64);
	// lfd f0,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// std r8,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r8.u64);
	// lfd f13,104(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// stvx128 v46,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// lfs f9,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f9.f64 = double(temp.f32);
	// frsp f23,f12
	f23.f64 = double(float(ctx.f12.f64));
	// addi r7,r9,-7432
	ctx.r7.s64 = ctx.r9.s64 + -7432;
	// lfs f10,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f10.f64 = double(temp.f32);
	// stw r22,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r22.u32);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// frsp f24,f11
	f24.f64 = double(float(ctx.f11.f64));
	// fdivs f21,f10,f23
	f21.f64 = double(float(ctx.f10.f64 / f23.f64));
	// stfs f21,136(r1)
	temp.f32 = float(f21.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// fdivs f26,f9,f24
	f26.f64 = double(float(ctx.f9.f64 / f24.f64));
	// stfs f26,128(r1)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// bne cr6,0x82303c40
	if (!cr6.eq) goto loc_82303C40;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lwz r11,-18028(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -18028);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,-18028(r10)
	PPC_STORE_U32(ctx.r10.u32 + -18028, r11.u32);
loc_82303C40:
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r20,r11,-18176
	r20.s64 = r11.s64 + -18176;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r11,-18032(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -18032);
	// clrlwi r7,r11,31
	ctx.r7.u64 = r11.u32 & 0x1;
	// lfs f25,14884(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f25.f64 = double(temp.f32);
	// lfs f29,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f29.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82303ce8
	if (!cr6.eq) goto loc_82303CE8;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f29,0(r20)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r20.u32 + 0, temp.u32);
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// stfs f29,4(r20)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r20.u32 + 4, temp.u32);
	// stfs f29,8(r20)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r20.u32 + 8, temp.u32);
	// stfs f29,20(r20)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r20.u32 + 20, temp.u32);
	// stw r11,-18032(r10)
	PPC_STORE_U32(ctx.r10.u32 + -18032, r11.u32);
	// stfs f29,36(r20)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r20.u32 + 36, temp.u32);
	// lfs f0,31492(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31492);
	f0.f64 = double(temp.f32);
	// stfs f0,16(r20)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r20.u32 + 16, temp.u32);
	// stfs f0,24(r20)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r20.u32 + 24, temp.u32);
	// stfs f0,32(r20)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r20.u32 + 32, temp.u32);
	// stfs f25,40(r20)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(r20.u32 + 40, temp.u32);
	// stfs f25,48(r20)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(r20.u32 + 48, temp.u32);
	// stfs f29,52(r20)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r20.u32 + 52, temp.u32);
	// stfs f25,56(r20)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(r20.u32 + 56, temp.u32);
	// stfs f25,64(r20)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(r20.u32 + 64, temp.u32);
	// stfs f29,68(r20)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r20.u32 + 68, temp.u32);
	// stfs f0,72(r20)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r20.u32 + 72, temp.u32);
	// stfs f29,80(r20)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r20.u32 + 80, temp.u32);
	// stfs f29,84(r20)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r20.u32 + 84, temp.u32);
	// stfs f0,88(r20)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r20.u32 + 88, temp.u32);
	// stfs f29,96(r20)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r20.u32 + 96, temp.u32);
	// stfs f29,100(r20)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r20.u32 + 100, temp.u32);
	// stfs f25,104(r20)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(r20.u32 + 104, temp.u32);
	// stfs f0,112(r20)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r20.u32 + 112, temp.u32);
	// stfs f29,116(r20)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r20.u32 + 116, temp.u32);
	// stfs f29,120(r20)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r20.u32 + 120, temp.u32);
	// stfs f25,128(r20)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(r20.u32 + 128, temp.u32);
	// stfs f29,132(r20)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r20.u32 + 132, temp.u32);
	// stfs f29,136(r20)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r20.u32 + 136, temp.u32);
loc_82303CE8:
	// lwz r11,272(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 272);
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// lis r9,32767
	ctx.r9.s64 = 2147418112;
	// ori r31,r10,65535
	r31.u64 = ctx.r10.u64 | 65535;
	// ori r30,r9,65535
	r30.u64 = ctx.r9.u64 | 65535;
	// li r29,-1
	r29.s64 = -1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82303d14
	if (cr6.eq) goto loc_82303D14;
	// mr r23,r11
	r23.u64 = r11.u64;
	// stw r23,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r23.u32);
	// b 0x82303d48
	goto loc_82303D48;
loc_82303D14:
	// lwz r11,8(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 8);
	// lwz r10,12(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 12);
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bgt cr6,0x82303d38
	if (cr6.gt) goto loc_82303D38;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// rlwinm r3,r11,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// ble cr6,0x82303d3c
	if (!cr6.gt) goto loc_82303D3C;
loc_82303D38:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_82303D3C:
	// bl 0x82130528
	ctx.lr = 0x82303D40;
	sub_82130528(ctx, base);
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// rotlwi r23,r3,0
	r23.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
loc_82303D48:
	// lwz r11,8(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 8);
	// lwz r10,12(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 12);
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bgt cr6,0x82303d6c
	if (cr6.gt) goto loc_82303D6C;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// rlwinm r3,r11,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// ble cr6,0x82303d70
	if (!cr6.gt) goto loc_82303D70;
loc_82303D6C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_82303D70:
	// bl 0x82130528
	ctx.lr = 0x82303D74;
	sub_82130528(ctx, base);
	// mullw r11,r22,r17
	r11.s64 = int64_t(r22.s32) * int64_t(r17.s32);
	// rlwinm r31,r11,3,0,28
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823d9890
	ctx.lr = 0x82303D94;
	sub_823D9890(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823d9890
	ctx.lr = 0x82303DA4;
	sub_823D9890(ctx, base);
	// li r18,0
	r18.s64 = 0;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// ble cr6,0x8230409c
	if (!cr6.gt) goto loc_8230409C;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r15,r17,-1
	r15.s64 = r17.s64 + -1;
	// addi r14,r22,-1
	r14.s64 = r22.s64 + -1;
	// li r16,0
	r16.s64 = 0;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f22,-740(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -740);
	f22.f64 = double(temp.f32);
loc_82303DCC:
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// lwzx r4,r11,r16
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r16.u32);
	// bl 0x822fcdf0
	ctx.lr = 0x82303DDC;
	sub_822FCDF0(ctx, base);
	// lfs f0,252(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 252);
	f0.f64 = double(temp.f32);
	// addi r11,r19,240
	r11.s64 = r19.s64 + 240;
	// lfs f12,240(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r19,256
	r11.s64 = r19.s64 + 256;
	// lfs f13,248(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 248);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fadds f9,f0,f12
	ctx.f9.f64 = double(float(f0.f64 + ctx.f12.f64));
	// lfs f7,240(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 240);
	ctx.f7.f64 = double(temp.f32);
	// fadds f8,f13,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfs f6,256(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 256);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,248(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 248);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f3,264(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 264);
	ctx.f3.f64 = double(temp.f32);
	// fmsubs f4,f11,f7,f6
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f7.f64 - ctx.f6.f64));
	// fmsubs f2,f9,f7,f6
	ctx.f2.f64 = double(float(ctx.f9.f64 * ctx.f7.f64 - ctx.f6.f64));
	// fmsubs f0,f8,f5,f3
	f0.f64 = double(float(ctx.f8.f64 * ctx.f5.f64 - ctx.f3.f64));
	// fmsubs f1,f10,f5,f3
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f5.f64 - ctx.f3.f64));
	// fmuls f13,f4,f24
	ctx.f13.f64 = double(float(ctx.f4.f64 * f24.f64));
	// fmuls f12,f2,f24
	ctx.f12.f64 = double(float(ctx.f2.f64 * f24.f64));
	// fmuls f10,f0,f23
	ctx.f10.f64 = double(float(f0.f64 * f23.f64));
	// fmuls f11,f1,f23
	ctx.f11.f64 = double(float(ctx.f1.f64 * f23.f64));
	// fctiwz f9,f13
	ctx.f9.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f9,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.f9.u64);
	// lwz r25,116(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// fctiwz f8,f12
	ctx.f8.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// fctiwz f6,f10
	ctx.f6.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f8,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.f8.u64);
	// stfd f6,168(r1)
	PPC_STORE_U64(ctx.r1.u32 + 168, ctx.f6.u64);
	// fctiwz f7,f11
	ctx.f7.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f7,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.f7.u64);
	// lwz r11,124(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// lwz r22,116(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r9,172(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// bge cr6,0x82303e70
	if (!cr6.lt) goto loc_82303E70;
	// li r25,0
	r25.s64 = 0;
	// b 0x82303e7c
	goto loc_82303E7C;
loc_82303E70:
	// cmpw cr6,r25,r15
	cr6.compare<int32_t>(r25.s32, r15.s32, xer);
	// ble cr6,0x82303e7c
	if (!cr6.gt) goto loc_82303E7C;
	// mr r25,r15
	r25.u64 = r15.u64;
loc_82303E7C:
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// bge cr6,0x82303e8c
	if (!cr6.lt) goto loc_82303E8C;
	// li r22,0
	r22.s64 = 0;
	// b 0x82303e98
	goto loc_82303E98;
loc_82303E8C:
	// cmpw cr6,r22,r15
	cr6.compare<int32_t>(r22.s32, r15.s32, xer);
	// ble cr6,0x82303e98
	if (!cr6.gt) goto loc_82303E98;
	// mr r22,r15
	r22.u64 = r15.u64;
loc_82303E98:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82303ea8
	if (!cr6.lt) goto loc_82303EA8;
	// li r11,0
	r11.s64 = 0;
	// b 0x82303eb4
	goto loc_82303EB4;
loc_82303EA8:
	// cmpw cr6,r11,r14
	cr6.compare<int32_t>(r11.s32, r14.s32, xer);
	// ble cr6,0x82303eb4
	if (!cr6.gt) goto loc_82303EB4;
	// mr r11,r14
	r11.u64 = r14.u64;
loc_82303EB4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bge cr6,0x82303ec4
	if (!cr6.lt) goto loc_82303EC4;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x82303ed0
	goto loc_82303ED0;
loc_82303EC4:
	// cmpw cr6,r9,r14
	cr6.compare<int32_t>(ctx.r9.s32, r14.s32, xer);
	// ble cr6,0x82303ed0
	if (!cr6.gt) goto loc_82303ED0;
	// mr r9,r14
	ctx.r9.u64 = r14.u64;
loc_82303ED0:
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// lwz r8,588(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 588);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// std r10,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r10.u64);
	// lfd f0,152(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f11,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fadds f10,f12,f25
	ctx.f10.f64 = double(float(ctx.f12.f64 + f25.f64));
	// fmadds f28,f10,f21,f11
	f28.f64 = double(float(ctx.f10.f64 * f21.f64 + ctx.f11.f64));
	// bgt cr6,0x82304084
	if (cr6.gt) goto loc_82304084;
	// extsw r8,r25
	ctx.r8.s64 = r25.s32;
	// lwz r7,100(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// mullw r10,r11,r17
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(r17.s32);
	// std r8,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r8.u64);
	// add r6,r10,r25
	ctx.r6.u64 = ctx.r10.u64 + r25.u64;
	// subf r10,r11,r9
	ctx.r10.s64 = ctx.r9.s64 - r11.s64;
	// rlwinm r11,r6,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r24,r23,r7
	r24.s64 = ctx.r7.s64 - r23.s64;
	// add r26,r11,r23
	r26.u64 = r11.u64 + r23.u64;
	// rlwinm r21,r17,3,0,28
	r21.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r23,r10,1
	r23.s64 = ctx.r10.s64 + 1;
	// lfd f0,128(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fadds f11,f12,f25
	ctx.f11.f64 = double(float(ctx.f12.f64 + f25.f64));
	// fmuls f27,f11,f26
	f27.f64 = double(float(ctx.f11.f64 * f26.f64));
loc_82303F3C:
	// lwz r11,588(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 588);
	// mr r29,r26
	r29.u64 = r26.u64;
	// cmpw cr6,r25,r22
	cr6.compare<int32_t>(r25.s32, r22.s32, xer);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fadds f30,f27,f0
	f30.f64 = double(float(f27.f64 + f0.f64));
	// bgt cr6,0x82304068
	if (cr6.gt) goto loc_82304068;
	// subf r11,r25,r22
	r11.s64 = r22.s64 - r25.s64;
	// add r28,r24,r26
	r28.u64 = r24.u64 + r26.u64;
	// addi r27,r11,1
	r27.s64 = r11.s64 + 1;
loc_82303F60:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// fmr f31,f29
	ctx.fpscr.disableFlushMode();
	f31.f64 = f29.f64;
	// lbz r10,-18192(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -18192);
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r7,r8,0,28,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x8;
	// addic. r31,r7,1
	xer.ca = ctx.r7.u32 > 4294967294;
	r31.s64 = ctx.r7.s64 + 1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// ble 0x82303fcc
	if (!cr0.gt) goto loc_82303FCC;
	// mr r30,r20
	r30.u64 = r20.u64;
loc_82303F84:
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// lvx128 v45,r0,r30
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f28,184(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// stfs f30,176(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// stfs f29,180(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// lvx128 v42,r0,r11
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v42,v127,v45,v42
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v42.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v45.f32)), simde_mm_load_ps(v42.f32)));
	// stvx128 v42,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822fd140
	ctx.lr = 0x82303FB4;
	sub_822FD140(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x82303fc0
	if (!cr6.gt) goto loc_82303FC0;
	// fadds f31,f1,f31
	f31.f64 = double(float(ctx.f1.f64 + f31.f64));
loc_82303FC0:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// bne 0x82303f84
	if (!cr0.eq) goto loc_82303F84;
loc_82303FCC:
	// fmuls f0,f31,f22
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 * f22.f64));
	// fctidz f13,f0
	ctx.f13.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f13,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.f13.u64);
	// lhz r6,126(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 126);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82304054
	if (cr6.eq) goto loc_82304054;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82303FF0:
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bgt cr6,0x82304010
	if (cr6.gt) goto loc_82304010;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// cmpwi cr6,r8,4
	cr6.compare<int32_t>(ctx.r8.s32, 4, xer);
	// blt cr6,0x82303ff0
	if (cr6.lt) goto loc_82303FF0;
	// b 0x82304054
	goto loc_82304054;
loc_82304010:
	// cmpwi cr6,r8,3
	cr6.compare<int32_t>(ctx.r8.s32, 3, xer);
	// bge cr6,0x82304048
	if (!cr6.lt) goto loc_82304048;
	// addi r9,r28,6
	ctx.r9.s64 = r28.s64 + 6;
	// addi r11,r29,4
	r11.s64 = r29.s64 + 4;
	// subf r7,r29,r28
	ctx.r7.s64 = r28.s64 - r29.s64;
	// subfic r10,r8,3
	xer.ca = ctx.r8.u32 <= 3;
	ctx.r10.s64 = 3 - ctx.r8.s64;
loc_82304028:
	// lhzx r5,r7,r11
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r7.u32 + r11.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// sth r5,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r5.u16);
	// addi r9,r9,-2
	ctx.r9.s64 = ctx.r9.s64 + -2;
	// lhz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// sth r4,2(r11)
	PPC_STORE_U16(r11.u32 + 2, ctx.r4.u16);
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
	// bne 0x82304028
	if (!cr0.eq) goto loc_82304028;
loc_82304048:
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r18,r11,r28
	PPC_STORE_U16(r11.u32 + r28.u32, r18.u16);
	// sthx r6,r11,r29
	PPC_STORE_U16(r11.u32 + r29.u32, ctx.r6.u16);
loc_82304054:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// fadds f30,f30,f26
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(f30.f64 + f26.f64));
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// bne 0x82303f60
	if (!cr0.eq) goto loc_82303F60;
loc_82304068:
	// addic. r23,r23,-1
	xer.ca = r23.u32 > 0;
	r23.s64 = r23.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// fadds f28,f28,f21
	ctx.fpscr.disableFlushMode();
	f28.f64 = double(float(f28.f64 + f21.f64));
	// add r26,r21,r26
	r26.u64 = r21.u64 + r26.u64;
	// bne 0x82303f3c
	if (!cr0.eq) goto loc_82303F3C;
	// lwz r23,96(r1)
	r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r24,144(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// lwz r21,572(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 572);
loc_82304084:
	// addi r18,r18,1
	r18.s64 = r18.s64 + 1;
	// addi r16,r16,4
	r16.s64 = r16.s64 + 4;
	// cmpw cr6,r18,r24
	cr6.compare<int32_t>(r18.s32, r24.s32, xer);
	// blt cr6,0x82303dcc
	if (cr6.lt) goto loc_82303DCC;
	// lwz r22,104(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r26,100(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
loc_8230409C:
	// mullw r11,r22,r17
	r11.s64 = int64_t(r22.s32) * int64_t(r17.s32);
	// lwz r28,140(r19)
	r28.u64 = PPC_LOAD_U32(r19.u32 + 140);
	// lwz r27,204(r19)
	r27.u64 = PPC_LOAD_U32(r19.u32 + 204);
	// rlwinm r31,r11,2,0,29
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823d9890
	ctx.lr = 0x823040BC;
	sub_823D9890(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823d9890
	ctx.lr = 0x823040CC;
	sub_823D9890(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// ble cr6,0x82304138
	if (!cr6.gt) goto loc_82304138;
	// rlwinm r25,r17,3,0,28
	r25.u64 = __builtin_rotateleft64(r17.u32 | (r17.u64 << 32), 3) & 0xFFFFFFF8;
loc_823040DC:
	// mr r31,r26
	r31.u64 = r26.u64;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r17,0
	cr6.compare<int32_t>(r17.s32, 0, xer);
	// ble cr6,0x82304128
	if (!cr6.gt) goto loc_82304128;
loc_823040EC:
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lhz r9,2(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lhz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82302ec8
	ctx.lr = 0x82304118;
	sub_82302EC8(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// cmpw cr6,r30,r17
	cr6.compare<int32_t>(r30.s32, r17.s32, xer);
	// blt cr6,0x823040ec
	if (cr6.lt) goto loc_823040EC;
loc_82304128:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// add r26,r26,r25
	r26.u64 = r26.u64 + r25.u64;
	// cmpw cr6,r29,r22
	cr6.compare<int32_t>(r29.s32, r22.s32, xer);
	// blt cr6,0x823040dc
	if (cr6.lt) goto loc_823040DC;
loc_82304138:
	// lwz r11,272(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 272);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8230414c
	if (!cr6.eq) goto loc_8230414C;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82130588
	ctx.lr = 0x8230414C;
	sub_82130588(ctx, base);
loc_8230414C:
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82130588
	ctx.lr = 0x82304154;
	sub_82130588(ctx, base);
loc_82304154:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82304154
	if (cr6.eq) goto loc_82304154;
	// ld r11,160(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 160);
	// addi r1,r1,544
	ctx.r1.s64 = ctx.r1.s64 + 544;
	// li r0,-256
	r0.s64 = -256;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba08
	ctx.lr = 0x8230417C;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82304180"))) PPC_WEAK_FUNC(sub_82304180);
PPC_FUNC_IMPL(__imp__sub_82304180) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,7504
	ctx.r10.s64 = r11.s64 + 7504;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822ee510
	ctx.lr = 0x823041AC;
	sub_822EE510(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x823041B4;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823041cc
	if (cr6.eq) goto loc_823041CC;
	// bl 0x82130588
	ctx.lr = 0x823041C8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823041CC:
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

__attribute__((alias("__imp__sub_823041E4"))) PPC_WEAK_FUNC(sub_823041E4);
PPC_FUNC_IMPL(__imp__sub_823041E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823041E8"))) PPC_WEAK_FUNC(sub_823041E8);
PPC_FUNC_IMPL(__imp__sub_823041E8) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r9,3
	ctx.r9.s64 = 3;
	// addi r8,r11,-7924
	ctx.r8.s64 = r11.s64 + -7924;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82304224
	if (cr6.eq) goto loc_82304224;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_82304224:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-17932(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17932);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82304238
	if (!cr6.eq) goto loc_82304238;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_82304238:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,-27512
	ctx.r3.s64 = r11.s64 + -27512;
	// bl 0x821c0750
	ctx.lr = 0x82304248;
	sub_821C0750(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82179ba0
	ctx.lr = 0x82304254;
	sub_82179BA0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82177330
	ctx.lr = 0x82304264;
	sub_82177330(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82304278;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82178910
	ctx.lr = 0x82304280;
	sub_82178910(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r31,0
	r31.s64 = 0;
	// addi r30,r11,21808
	r30.s64 = r11.s64 + 21808;
	// lwz r3,21808(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 21808);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823042b0
	if (cr6.eq) goto loc_823042B0;
loc_82304298:
	// bl 0x82188248
	ctx.lr = 0x8230429C;
	sub_82188248(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82304298
	if (!cr6.eq) goto loc_82304298;
loc_823042B0:
	// bl 0x82130000
	ctx.lr = 0x823042B4;
	sub_82130000(ctx, base);
	// bl 0x822e7098
	ctx.lr = 0x823042B8;
	sub_822E7098(ctx, base);
	// bl 0x822e4ab0
	ctx.lr = 0x823042BC;
	sub_822E4AB0(ctx, base);
	// bl 0x826123e0
	ctx.lr = 0x823042C0;
	sub_826123E0(ctx, base);
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

__attribute__((alias("__imp__sub_823042D8"))) PPC_WEAK_FUNC(sub_823042D8);
PPC_FUNC_IMPL(__imp__sub_823042D8) {
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
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823042F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lwz r11,-18012(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -18012);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82304314
	if (!cr6.gt) goto loc_82304314;
	// li r10,1000
	ctx.r10.s64 = 1000;
	// divw r3,r11,r10
	ctx.r3.s32 = r11.s32 / ctx.r10.s32;
	// bl 0x821c91b8
	ctx.lr = 0x82304314;
	sub_821C91B8(ctx, base);
loc_82304314:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7436);
	// bl 0x822f8550
	ctx.lr = 0x82304320;
	sub_822F8550(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82304330"))) PPC_WEAK_FUNC(sub_82304330);
PPC_FUNC_IMPL(__imp__sub_82304330) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
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

__attribute__((alias("__imp__sub_82304344"))) PPC_WEAK_FUNC(sub_82304344);
PPC_FUNC_IMPL(__imp__sub_82304344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82304348"))) PPC_WEAK_FUNC(sub_82304348);
PPC_FUNC_IMPL(__imp__sub_82304348) {
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
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8230436C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lwz r11,-18008(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -18008);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82304388
	if (!cr6.gt) goto loc_82304388;
	// li r10,1000
	ctx.r10.s64 = 1000;
	// divw r3,r11,r10
	ctx.r3.s32 = r11.s32 / ctx.r10.s32;
	// bl 0x821c91b8
	ctx.lr = 0x82304388;
	sub_821C91B8(ctx, base);
loc_82304388:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82304398"))) PPC_WEAK_FUNC(sub_82304398);
PPC_FUNC_IMPL(__imp__sub_82304398) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82189e80
	ctx.lr = 0x823043B8;
	sub_82189E80(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x822f24b0
	ctx.lr = 0x823043C4;
	sub_822F24B0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x823043D0;
	sub_8217F768(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823043E4;
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

__attribute__((alias("__imp__sub_823043F8"))) PPC_WEAK_FUNC(sub_823043F8);
PPC_FUNC_IMPL(__imp__sub_823043F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,68(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82304410
	if (!cr6.gt) goto loc_82304410;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, r11.u32);
	// stw r10,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r10.u32);
loc_82304410:
	// lwz r11,72(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82304428"))) PPC_WEAK_FUNC(sub_82304428);
PPC_FUNC_IMPL(__imp__sub_82304428) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82304430;
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,72(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bgt cr6,0x82304454
	if (cr6.gt) goto loc_82304454;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82304454:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823045a0
	if (cr6.eq) goto loc_823045A0;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x8217f768
	ctx.lr = 0x8230446C;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x8217f768
	ctx.lr = 0x82304478;
	sub_8217F768(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82304494;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x8217d9a0
	ctx.lr = 0x82304498;
	sub_8217D9A0(ctx, base);
	// bl 0x821789d8
	ctx.lr = 0x8230449C;
	sub_821789D8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823044b4
	if (cr6.eq) goto loc_823044B4;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17004);
	// b 0x823044bc
	goto loc_823044BC;
loc_823044B4:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17012);
loc_823044BC:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, r11.u64);
	// lfd f0,128(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f30,f13
	f30.f64 = double(float(ctx.f13.f64));
	// bl 0x821789d8
	ctx.lr = 0x823044D4;
	sub_821789D8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823044ec
	if (cr6.eq) goto loc_823044EC;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17008);
	// b 0x823044f4
	goto loc_823044F4;
loc_823044EC:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17016);
loc_823044F4:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lis r30,-32124
	r30.s64 = -2105278464;
	// std r11,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, r11.u64);
	// lfd f0,128(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r31,-26876(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -26876);
	// frsp f31,f13
	f31.f64 = double(float(ctx.f13.f64));
	// lwz r3,-26880(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -26880);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// beq cr6,0x82304528
	if (cr6.eq) goto loc_82304528;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8217c658
	ctx.lr = 0x82304528;
	sub_8217C658(ctx, base);
loc_82304528:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmr f4,f31
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = f31.f64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// lis r8,-32119
	ctx.r8.s64 = -2104950784;
	// stw r29,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r29.u32);
	// li r11,-1
	r11.s64 = -1;
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r29.u32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// li r6,1
	ctx.r6.s64 = 1;
	// lfs f7,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f7.f64 = double(temp.f32);
	// lfs f9,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f9.f64 = double(temp.f32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// lwz r3,-12280(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12280);
	// fmr f6,f7
	ctx.f6.f64 = ctx.f7.f64;
	// stw r7,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
	// fmr f5,f7
	ctx.f5.f64 = ctx.f7.f64;
	// stb r6,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, ctx.r6.u8);
	// fmr f2,f7
	ctx.f2.f64 = ctx.f7.f64;
	// fmr f8,f9
	ctx.f8.f64 = ctx.f9.f64;
	// fmr f1,f7
	ctx.f1.f64 = ctx.f7.f64;
	// bl 0x823083f8
	ctx.lr = 0x82304580;
	sub_823083F8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217d9a0
	ctx.lr = 0x82304588;
	sub_8217D9A0(ctx, base);
	// lwz r11,-26880(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -26880);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// beq cr6,0x823045a0
	if (cr6.eq) goto loc_823045A0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217c658
	ctx.lr = 0x823045A0;
	sub_8217C658(ctx, base);
loc_823045A0:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823045B0"))) PPC_WEAK_FUNC(sub_823045B0);
PPC_FUNC_IMPL(__imp__sub_823045B0) {
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
	// lwz r3,44(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// bl 0x822f0a38
	ctx.lr = 0x823045C4;
	sub_822F0A38(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x822f1db0
	ctx.lr = 0x823045D0;
	sub_822F1DB0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823045E0"))) PPC_WEAK_FUNC(sub_823045E0);
PPC_FUNC_IMPL(__imp__sub_823045E0) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x822f3bd8
	ctx.lr = 0x823045F8;
	sub_822F3BD8(ctx, base);
	// bl 0x82306a20
	ctx.lr = 0x823045FC;
	sub_82306A20(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8230460C"))) PPC_WEAK_FUNC(sub_8230460C);
PPC_FUNC_IMPL(__imp__sub_8230460C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82304610"))) PPC_WEAK_FUNC(sub_82304610);
PPC_FUNC_IMPL(__imp__sub_82304610) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8230461C"))) PPC_WEAK_FUNC(sub_8230461C);
PPC_FUNC_IMPL(__imp__sub_8230461C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82304620"))) PPC_WEAK_FUNC(sub_82304620);
PPC_FUNC_IMPL(__imp__sub_82304620) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// b 0x822f24b0
	sub_822F24B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8230462C"))) PPC_WEAK_FUNC(sub_8230462C);
PPC_FUNC_IMPL(__imp__sub_8230462C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82304630"))) PPC_WEAK_FUNC(sub_82304630);
PPC_FUNC_IMPL(__imp__sub_82304630) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822f1518
	sub_822F1518(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82304644"))) PPC_WEAK_FUNC(sub_82304644);
PPC_FUNC_IMPL(__imp__sub_82304644) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82304648"))) PPC_WEAK_FUNC(sub_82304648);
PPC_FUNC_IMPL(__imp__sub_82304648) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-7572(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8230466c
	if (cr6.eq) goto loc_8230466C;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// stb r3,14546(r11)
	PPC_STORE_U8(r11.u32 + 14546, ctx.r3.u8);
	// lwz r11,-8092(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// stb r3,393(r11)
	PPC_STORE_U8(r11.u32 + 393, ctx.r3.u8);
	// blr 
	return;
loc_8230466C:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-8092(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// stb r3,393(r11)
	PPC_STORE_U8(r11.u32 + 393, ctx.r3.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8230467C"))) PPC_WEAK_FUNC(sub_8230467C);
PPC_FUNC_IMPL(__imp__sub_8230467C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82304680"))) PPC_WEAK_FUNC(sub_82304680);
PPC_FUNC_IMPL(__imp__sub_82304680) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-18004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x823076e8
	sub_823076E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823046A0"))) PPC_WEAK_FUNC(sub_823046A0);
PPC_FUNC_IMPL(__imp__sub_823046A0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823046A4"))) PPC_WEAK_FUNC(sub_823046A4);
PPC_FUNC_IMPL(__imp__sub_823046A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823046A8"))) PPC_WEAK_FUNC(sub_823046A8);
PPC_FUNC_IMPL(__imp__sub_823046A8) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,7512
	ctx.r10.s64 = r11.s64 + 7512;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x823046D4;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823046ec
	if (cr6.eq) goto loc_823046EC;
	// bl 0x82130588
	ctx.lr = 0x823046E8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823046EC:
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

__attribute__((alias("__imp__sub_82304704"))) PPC_WEAK_FUNC(sub_82304704);
PPC_FUNC_IMPL(__imp__sub_82304704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82304708"))) PPC_WEAK_FUNC(sub_82304708);
PPC_FUNC_IMPL(__imp__sub_82304708) {
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
	// li r3,84
	ctx.r3.s64 = 84;
	// bl 0x82130528
	ctx.lr = 0x82304724;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823047a8
	if (cr6.eq) goto loc_823047A8;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r10,r10,-18004
	ctx.r10.s64 = ctx.r10.s64 + -18004;
	// li r11,0
	r11.s64 = 0;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r7,r8,7512
	ctx.r7.s64 = ctx.r8.s64 + 7512;
	// li r6,1
	ctx.r6.s64 = 1;
	// stfs f0,64(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// li r5,4
	ctx.r5.s64 = 4;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, r11.u32);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r11.u32);
	// stb r11,60(r3)
	PPC_STORE_U8(ctx.r3.u32 + 60, r11.u8);
	// stb r6,80(r3)
	PPC_STORE_U8(ctx.r3.u32 + 80, ctx.r6.u8);
	// stw r5,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r5.u32);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// b 0x823047b8
	goto loc_823047B8;
loc_823047A8:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r11,-18004
	ctx.r10.s64 = r11.s64 + -18004;
	// stw r9,-18004(r11)
	PPC_STORE_U32(r11.u32 + -18004, ctx.r9.u32);
loc_823047B8:
	// stw r31,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r31.u32);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x823041e8
	ctx.lr = 0x823047C4;
	sub_823041E8(ctx, base);
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

__attribute__((alias("__imp__sub_823047D8"))) PPC_WEAK_FUNC(sub_823047D8);
PPC_FUNC_IMPL(__imp__sub_823047D8) {
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
	ctx.lr = 0x823047E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r10,7572
	ctx.r4.s64 = ctx.r10.s64 + 7572;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// bl 0x82182240
	ctx.lr = 0x823047FC;
	sub_82182240(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r3,r9,7560
	ctx.r3.s64 = ctx.r9.s64 + 7560;
	// bl 0x8218a9e0
	ctx.lr = 0x82304808;
	sub_8218A9E0(ctx, base);
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// addi r31,r8,30576
	r31.s64 = ctx.r8.s64 + 30576;
	// addi r4,r7,24280
	ctx.r4.s64 = ctx.r7.s64 + 24280;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ca540
	ctx.lr = 0x82304820;
	sub_821CA540(ctx, base);
	// lis r30,-32124
	r30.s64 = -2105278464;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-3316
	ctx.r4.s64 = ctx.r6.s64 + -3316;
	// lwz r3,-24728(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24728);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82304844;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-24728(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24728);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,19612
	ctx.r4.s64 = ctx.r9.s64 + 19612;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,28(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82304864;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-24728(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24728);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,7552
	ctx.r4.s64 = ctx.r6.s64 + 7552;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82304884;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-24728(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24728);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,7540
	ctx.r4.s64 = ctx.r9.s64 + 7540;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,28(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x823048A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-24728(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24728);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,7532
	ctx.r4.s64 = ctx.r6.s64 + 7532;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823048C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x823048CC;
	sub_821C9A90(ctx, base);
	// bl 0x822fbaf8
	ctx.lr = 0x823048D0;
	sub_822FBAF8(ctx, base);
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82130528
	ctx.lr = 0x823048D8;
	sub_82130528(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823048f0
	if (cr6.eq) goto loc_823048F0;
	// bl 0x823074b0
	ctx.lr = 0x823048E8;
	sub_823074B0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x823048f4
	goto loc_823048F4;
loc_823048F0:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
loc_823048F4:
	// stw r5,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r5.u32);
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lis r4,6146
	ctx.r4.s64 = 402784256;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// bl 0x822e50d8
	ctx.lr = 0x82304908;
	sub_822E50D8(ctx, base);
	// bl 0x822f96e0
	ctx.lr = 0x8230490C;
	sub_822F96E0(ctx, base);
	// bl 0x822f38c0
	ctx.lr = 0x82304910;
	sub_822F38C0(ctx, base);
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82130528
	ctx.lr = 0x82304918;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8230492c
	if (cr6.eq) goto loc_8230492C;
	// bl 0x823109e8
	ctx.lr = 0x82304924;
	sub_823109E8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x82304930
	goto loc_82304930;
loc_8230492C:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
loc_82304930:
	// stw r5,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r5.u32);
	// li r4,32224
	ctx.r4.s64 = 32224;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// bl 0x822e50d8
	ctx.lr = 0x82304940;
	sub_822E50D8(ctx, base);
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82130528
	ctx.lr = 0x82304948;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8230495c
	if (cr6.eq) goto loc_8230495C;
	// bl 0x823064c0
	ctx.lr = 0x82304954;
	sub_823064C0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x82304960
	goto loc_82304960;
loc_8230495C:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
loc_82304960:
	// stw r5,16(r29)
	PPC_STORE_U32(r29.u32 + 16, ctx.r5.u32);
	// lis r4,257
	ctx.r4.s64 = 16842752;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// ori r4,r4,13
	ctx.r4.u64 = ctx.r4.u64 | 13;
	// bl 0x822e50d8
	ctx.lr = 0x82304974;
	sub_822E50D8(ctx, base);
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x8230497C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82304990
	if (cr6.eq) goto loc_82304990;
	// bl 0x82314588
	ctx.lr = 0x82304988;
	sub_82314588(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x82304994
	goto loc_82304994;
loc_82304990:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
loc_82304994:
	// stw r5,32(r29)
	PPC_STORE_U32(r29.u32 + 32, ctx.r5.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// bl 0x822e50d8
	ctx.lr = 0x823049A4;
	sub_822E50D8(ctx, base);
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x823049AC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823049c0
	if (cr6.eq) goto loc_823049C0;
	// bl 0x82314218
	ctx.lr = 0x823049B8;
	sub_82314218(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x823049c4
	goto loc_823049C4;
loc_823049C0:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
loc_823049C4:
	// stw r5,36(r29)
	PPC_STORE_U32(r29.u32 + 36, ctx.r5.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// bl 0x822e50d8
	ctx.lr = 0x823049D4;
	sub_822E50D8(ctx, base);
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82130528
	ctx.lr = 0x823049DC;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82304a00
	if (cr6.eq) goto loc_82304A00;
	// bl 0x822e7028
	ctx.lr = 0x823049EC;
	sub_822E7028(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r10,r11,7520
	ctx.r10.s64 = r11.s64 + 7520;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x82304a04
	goto loc_82304A04;
loc_82304A00:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
loc_82304A04:
	// stw r5,56(r29)
	PPC_STORE_U32(r29.u32 + 56, ctx.r5.u32);
	// lis r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// ori r4,r4,32768
	ctx.r4.u64 = ctx.r4.u64 | 32768;
	// bl 0x822e50d8
	ctx.lr = 0x82304A18;
	sub_822E50D8(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x82304A20;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82304a34
	if (cr6.eq) goto loc_82304A34;
	// bl 0x82306860
	ctx.lr = 0x82304A2C;
	sub_82306860(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x82304a38
	goto loc_82304A38;
loc_82304A34:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
loc_82304A38:
	// stw r5,20(r29)
	PPC_STORE_U32(r29.u32 + 20, ctx.r5.u32);
	// lis r4,672
	ctx.r4.s64 = 44040192;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// bl 0x822e50d8
	ctx.lr = 0x82304A48;
	sub_822E50D8(ctx, base);
	// bl 0x82377950
	ctx.lr = 0x82304A4C;
	sub_82377950(ctx, base);
	// bl 0x82313fa8
	ctx.lr = 0x82304A50;
	sub_82313FA8(ctx, base);
	// bl 0x822e8390
	ctx.lr = 0x82304A54;
	sub_822E8390(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7896(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7896);
	// bl 0x822e80d8
	ctx.lr = 0x82304A60;
	sub_822E80D8(ctx, base);
	// bl 0x82360ba0
	ctx.lr = 0x82304A64;
	sub_82360BA0(ctx, base);
	// bl 0x822eade8
	ctx.lr = 0x82304A68;
	sub_822EADE8(ctx, base);
	// bl 0x827494e8
	ctx.lr = 0x82304A6C;
	sub_827494E8(ctx, base);
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82130528
	ctx.lr = 0x82304A74;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82304a8c
	if (cr6.eq) goto loc_82304A8C;
	// bl 0x823083a8
	ctx.lr = 0x82304A80;
	sub_823083A8(ctx, base);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// stw r3,-12280(r11)
	PPC_STORE_U32(r11.u32 + -12280, ctx.r3.u32);
	// b 0x82304a98
	goto loc_82304A98;
loc_82304A8C:
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// mr r11,r28
	r11.u64 = r28.u64;
	// stw r11,-12280(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12280, r11.u32);
loc_82304A98:
	// bl 0x8239e258
	ctx.lr = 0x82304A9C;
	sub_8239E258(ctx, base);
	// bl 0x82308640
	ctx.lr = 0x82304AA0;
	sub_82308640(ctx, base);
	// bl 0x82307ed0
	ctx.lr = 0x82304AA4;
	sub_82307ED0(ctx, base);
	// bl 0x822eba28
	ctx.lr = 0x82304AA8;
	sub_822EBA28(ctx, base);
	// bl 0x8237b1b8
	ctx.lr = 0x82304AAC;
	sub_8237B1B8(ctx, base);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x82304AB4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82304ac4
	if (cr6.eq) goto loc_82304AC4;
	// bl 0x82313e20
	ctx.lr = 0x82304AC0;
	sub_82313E20(ctx, base);
	// b 0x82304ac8
	goto loc_82304AC8;
loc_82304AC4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_82304AC8:
	// stw r3,48(r29)
	PPC_STORE_U32(r29.u32 + 48, ctx.r3.u32);
	// li r3,752
	ctx.r3.s64 = 752;
	// bl 0x82130528
	ctx.lr = 0x82304AD4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82304b18
	if (cr6.eq) goto loc_82304B18;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stb r28,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, r28.u8);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r28,624(r3)
	PPC_STORE_U32(ctx.r3.u32 + 624, r28.u32);
	// addi r9,r11,7504
	ctx.r9.s64 = r11.s64 + 7504;
	// stw r28,628(r3)
	PPC_STORE_U32(ctx.r3.u32 + 628, r28.u32);
	// stb r10,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r10.u8);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r28,632(r3)
	PPC_STORE_U32(ctx.r3.u32 + 632, r28.u32);
	// stw r28,636(r3)
	PPC_STORE_U32(ctx.r3.u32 + 636, r28.u32);
	// stw r28,640(r3)
	PPC_STORE_U32(ctx.r3.u32 + 640, r28.u32);
	// stw r28,644(r3)
	PPC_STORE_U32(ctx.r3.u32 + 644, r28.u32);
	// stw r28,648(r3)
	PPC_STORE_U32(ctx.r3.u32 + 648, r28.u32);
	// stw r28,652(r3)
	PPC_STORE_U32(ctx.r3.u32 + 652, r28.u32);
	// b 0x82304b1c
	goto loc_82304B1C;
loc_82304B18:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_82304B1C:
	// stw r3,40(r29)
	PPC_STORE_U32(r29.u32 + 40, ctx.r3.u32);
	// li r4,16384
	ctx.r4.s64 = 16384;
	// bl 0x822ef0d8
	ctx.lr = 0x82304B28;
	sub_822EF0D8(ctx, base);
	// li r3,272
	ctx.r3.s64 = 272;
	// bl 0x82130528
	ctx.lr = 0x82304B30;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82304b40
	if (cr6.eq) goto loc_82304B40;
	// bl 0x822f0cd0
	ctx.lr = 0x82304B3C;
	sub_822F0CD0(ctx, base);
	// b 0x82304b44
	goto loc_82304B44;
loc_82304B40:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_82304B44:
	// stw r3,44(r29)
	PPC_STORE_U32(r29.u32 + 44, ctx.r3.u32);
	// bl 0x822f0c18
	ctx.lr = 0x82304B4C;
	sub_822F0C18(ctx, base);
	// bl 0x82379c68
	ctx.lr = 0x82304B50;
	sub_82379C68(ctx, base);
	// li r3,1872
	ctx.r3.s64 = 1872;
	// bl 0x82130528
	ctx.lr = 0x82304B58;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82304b70
	if (cr6.eq) goto loc_82304B70;
	// bl 0x82746b78
	ctx.lr = 0x82304B64;
	sub_82746B78(ctx, base);
	// stw r3,52(r29)
	PPC_STORE_U32(r29.u32 + 52, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82304B70:
	// mr r11,r28
	r11.u64 = r28.u64;
	// stw r11,52(r29)
	PPC_STORE_U32(r29.u32 + 52, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82304B80"))) PPC_WEAK_FUNC(sub_82304B80);
PPC_FUNC_IMPL(__imp__sub_82304B80) {
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
	// bl 0x822e7018
	ctx.lr = 0x82304BA0;
	sub_822E7018(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82304bb8
	if (cr6.eq) goto loc_82304BB8;
	// bl 0x82130588
	ctx.lr = 0x82304BB4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82304BB8:
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

__attribute__((alias("__imp__sub_82304BD0"))) PPC_WEAK_FUNC(sub_82304BD0);
PPC_FUNC_IMPL(__imp__sub_82304BD0) {
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
	ctx.lr = 0x82304BD8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822fa1b8
	ctx.lr = 0x82304BE4;
	sub_822FA1B8(ctx, base);
	// lwz r30,52(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82304c00
	if (cr6.eq) goto loc_82304C00;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827470a8
	ctx.lr = 0x82304BF8;
	sub_827470A8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82304C00;
	sub_82130588(ctx, base);
loc_82304C00:
	// bl 0x82379a30
	ctx.lr = 0x82304C04;
	sub_82379A30(ctx, base);
	// lwz r30,48(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82304c20
	if (cr6.eq) goto loc_82304C20;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82313c80
	ctx.lr = 0x82304C18;
	sub_82313C80(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82304C20;
	sub_82130588(ctx, base);
loc_82304C20:
	// lwz r30,28(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82304c3c
	if (cr6.eq) goto loc_82304C3C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82313e50
	ctx.lr = 0x82304C34;
	sub_82313E50(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82304C3C;
	sub_82130588(ctx, base);
loc_82304C3C:
	// li r28,0
	r28.s64 = 0;
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
	// bl 0x822eb6b8
	ctx.lr = 0x82304C48;
	sub_822EB6B8(ctx, base);
	// bl 0x82308358
	ctx.lr = 0x82304C4C;
	sub_82308358(ctx, base);
	// bl 0x8230a070
	ctx.lr = 0x82304C50;
	sub_8230A070(ctx, base);
	// bl 0x8239e2b0
	ctx.lr = 0x82304C54;
	sub_8239E2B0(ctx, base);
	// lis r30,-32119
	r30.s64 = -2104950784;
	// lwz r29,-12280(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + -12280);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82304c74
	if (cr6.eq) goto loc_82304C74;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82308600
	ctx.lr = 0x82304C6C;
	sub_82308600(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82304C74;
	sub_82130588(ctx, base);
loc_82304C74:
	// mr r11,r28
	r11.u64 = r28.u64;
	// stw r11,-12280(r30)
	PPC_STORE_U32(r30.u32 + -12280, r11.u32);
	// bl 0x822e9bb0
	ctx.lr = 0x82304C80;
	sub_822E9BB0(ctx, base);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r30,-32120
	r30.s64 = -2105016320;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82304cbc
	if (cr6.eq) goto loc_82304CBC;
	// lwz r3,-8092(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8092);
	// bl 0x822e5108
	ctx.lr = 0x82304C98;
	sub_822E5108(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82304cb8
	if (cr6.eq) goto loc_82304CB8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82304CB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82304CB8:
	// stw r28,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r28.u32);
loc_82304CBC:
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82304cf4
	if (cr6.eq) goto loc_82304CF4;
	// lwz r3,-8092(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8092);
	// bl 0x822e5108
	ctx.lr = 0x82304CD0;
	sub_822E5108(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82304cf0
	if (cr6.eq) goto loc_82304CF0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82304CF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82304CF0:
	// stw r28,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r28.u32);
loc_82304CF4:
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82304d2c
	if (cr6.eq) goto loc_82304D2C;
	// lwz r3,-8092(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8092);
	// bl 0x822e5108
	ctx.lr = 0x82304D08;
	sub_822E5108(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82304d28
	if (cr6.eq) goto loc_82304D28;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82304D28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82304D28:
	// stw r28,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r28.u32);
loc_82304D2C:
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82304d64
	if (cr6.eq) goto loc_82304D64;
	// lwz r3,-8092(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8092);
	// bl 0x822e5108
	ctx.lr = 0x82304D40;
	sub_822E5108(ctx, base);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82304d60
	if (cr6.eq) goto loc_82304D60;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82304D60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82304D60:
	// stw r28,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r28.u32);
loc_82304D64:
	// bl 0x822f0ed8
	ctx.lr = 0x82304D68;
	sub_822F0ED8(ctx, base);
	// bl 0x822f72e8
	ctx.lr = 0x82304D6C;
	sub_822F72E8(ctx, base);
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82304da4
	if (cr6.eq) goto loc_82304DA4;
	// lwz r3,-8092(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8092);
	// bl 0x822e5108
	ctx.lr = 0x82304D80;
	sub_822E5108(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82304da0
	if (cr6.eq) goto loc_82304DA0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82304DA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82304DA0:
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
loc_82304DA4:
	// bl 0x822e6390
	ctx.lr = 0x82304DA8;
	sub_822E6390(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82304DBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x821773e8
	ctx.lr = 0x82304DC4;
	sub_821773E8(ctx, base);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82304de4
	if (cr6.eq) goto loc_82304DE4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82304DE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82304DE4:
	// stw r28,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82304DF0"))) PPC_WEAK_FUNC(sub_82304DF0);
PPC_FUNC_IMPL(__imp__sub_82304DF0) {
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
	// lbz r11,80(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 80);
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// and r9,r11,r10
	ctx.r9.u64 = r11.u64 & ctx.r10.u64;
	// clrlwi r30,r9,24
	r30.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82304e24
	if (cr6.eq) goto loc_82304E24;
	// lwz r11,76(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// b 0x82304e28
	goto loc_82304E28;
loc_82304E24:
	// li r11,0
	r11.s64 = 0;
loc_82304E28:
	// lis r31,-32124
	r31.s64 = -2105278464;
	// li r3,14
	ctx.r3.s64 = 14;
	// stw r11,-27692(r31)
	PPC_STORE_U32(r31.u32 + -27692, r11.u32);
	// bl 0x8217fed0
	ctx.lr = 0x82304E38;
	sub_8217FED0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82304e68
	if (!cr6.eq) goto loc_82304E68;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82304e68
	if (cr6.eq) goto loc_82304E68;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r4,-27692(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -27692);
	// lfs f1,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82179778
	ctx.lr = 0x82304E58;
	sub_82179778(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fdivs f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 / ctx.f1.f64));
	// b 0x82304e70
	goto loc_82304E70;
loc_82304E68:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
loc_82304E70:
	// bl 0x8217f6f0
	ctx.lr = 0x82304E74;
	sub_8217F6F0(ctx, base);
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

__attribute__((alias("__imp__sub_82304E8C"))) PPC_WEAK_FUNC(sub_82304E8C);
PPC_FUNC_IMPL(__imp__sub_82304E8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82304E90"))) PPC_WEAK_FUNC(sub_82304E90);
PPC_FUNC_IMPL(__imp__sub_82304E90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-7572(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lfs f2,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// b 0x822f1518
	sub_822F1518(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82304EB4"))) PPC_WEAK_FUNC(sub_82304EB4);
PPC_FUNC_IMPL(__imp__sub_82304EB4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82304EB8"))) PPC_WEAK_FUNC(sub_82304EB8);
PPC_FUNC_IMPL(__imp__sub_82304EB8) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82304efc
	if (cr6.eq) goto loc_82304EFC;
	// bl 0x822f10d0
	ctx.lr = 0x82304EE0;
	sub_822F10D0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
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
loc_82304EFC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
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

__attribute__((alias("__imp__sub_82304F20"))) PPC_WEAK_FUNC(sub_82304F20);
PPC_FUNC_IMPL(__imp__sub_82304F20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,-7572(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -7572);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r9,r7,1
	ctx.r9.u64 = ctx.r7.u64 ^ 1;
	// beq cr6,0x82304f5c
	if (cr6.eq) goto loc_82304F5C;
	// lbz r10,14545(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 14545);
	// stb r9,14545(r11)
	PPC_STORE_U8(r11.u32 + 14545, ctx.r9.u8);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
loc_82304F5C:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82304F70"))) PPC_WEAK_FUNC(sub_82304F70);
PPC_FUNC_IMPL(__imp__sub_82304F70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r9,r10,-17980
	ctx.r9.s64 = ctx.r10.s64 + -17980;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// xori r10,r6,1
	ctx.r10.u64 = ctx.r6.u64 ^ 1;
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-7572(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stb r10,14584(r11)
	PPC_STORE_U8(r11.u32 + 14584, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82304FB0"))) PPC_WEAK_FUNC(sub_82304FB0);
PPC_FUNC_IMPL(__imp__sub_82304FB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// lwz r3,-8092(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82304fe0
	if (cr6.eq) goto loc_82304FE0;
	// b 0x822e5b00
	sub_822E5B00(ctx, base);
	return;
loc_82304FE0:
	// b 0x822e5b10
	sub_822E5B10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82304FE4"))) PPC_WEAK_FUNC(sub_82304FE4);
PPC_FUNC_IMPL(__imp__sub_82304FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82304FE8"))) PPC_WEAK_FUNC(sub_82304FE8);
PPC_FUNC_IMPL(__imp__sub_82304FE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r5,-8193
	ctx.r5.s64 = -536936448;
	// ori r5,r5,65535
	ctx.r5.u64 = ctx.r5.u64 | 65535;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r4,r6,24
	ctx.r4.u64 = ctx.r6.u32 & 0xFF;
	// cntlzw r11,r4
	r11.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// rlwinm r4,r11,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// b 0x822e51f8
	sub_822E51F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8230501C"))) PPC_WEAK_FUNC(sub_8230501C);
PPC_FUNC_IMPL(__imp__sub_8230501C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82305020"))) PPC_WEAK_FUNC(sub_82305020);
PPC_FUNC_IMPL(__imp__sub_82305020) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-18004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82305044"))) PPC_WEAK_FUNC(sub_82305044);
PPC_FUNC_IMPL(__imp__sub_82305044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82305048"))) PPC_WEAK_FUNC(sub_82305048);
PPC_FUNC_IMPL(__imp__sub_82305048) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,-18004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82305080"))) PPC_WEAK_FUNC(sub_82305080);
PPC_FUNC_IMPL(__imp__sub_82305080) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lwz r11,-18004(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -18004);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// xori r11,r6,1
	r11.u64 = ctx.r6.u64 ^ 1;
	// beqlr cr6
	if (cr6.eq) return;
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// b 0x823076e8
	sub_823076E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823050B0"))) PPC_WEAK_FUNC(sub_823050B0);
PPC_FUNC_IMPL(__imp__sub_823050B0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823050B4"))) PPC_WEAK_FUNC(sub_823050B4);
PPC_FUNC_IMPL(__imp__sub_823050B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823050B8"))) PPC_WEAK_FUNC(sub_823050B8);
PPC_FUNC_IMPL(__imp__sub_823050B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,-7572(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -7572);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// beq cr6,0x823050f4
	if (cr6.eq) goto loc_823050F4;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// stb r11,14546(r10)
	PPC_STORE_U8(ctx.r10.u32 + 14546, r11.u8);
	// lwz r10,-8092(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8092);
	// stb r11,393(r10)
	PPC_STORE_U8(ctx.r10.u32 + 393, r11.u8);
	// blr 
	return;
loc_823050F4:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r10,-8092(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// stb r11,393(r10)
	PPC_STORE_U8(ctx.r10.u32 + 393, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82305104"))) PPC_WEAK_FUNC(sub_82305104);
PPC_FUNC_IMPL(__imp__sub_82305104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82305108"))) PPC_WEAK_FUNC(sub_82305108);
PPC_FUNC_IMPL(__imp__sub_82305108) {
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
	ctx.lr = 0x82305110;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82305148
	if (cr6.eq) goto loc_82305148;
	// bl 0x822f10d0
	ctx.lr = 0x82305130;
	sub_822F10D0(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f0,-26872(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -26872);
	f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
loc_82305148:
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// lis r7,-30584
	ctx.r7.s64 = -2004353024;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// ori r6,r7,34953
	ctx.r6.u64 = ctx.r7.u64 | 34953;
	// li r5,60
	ctx.r5.s64 = 60;
	// mulhw r9,r11,r6
	ctx.r9.s64 = (int64_t(r11.s32) * int64_t(ctx.r6.s32)) >> 32;
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + r11.u64;
	// divw r31,r10,r5
	r31.s32 = ctx.r10.s32 / ctx.r5.s32;
	// srawi r11,r4,5
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1F) != 0);
	r11.s64 = ctx.r4.s32 >> 5;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// mulli r10,r11,60
	ctx.r10.s64 = r11.s64 * 60;
	// subf r30,r10,r8
	r30.s64 = ctx.r8.s64 - ctx.r10.s64;
	// bl 0x82457a30
	ctx.lr = 0x82305184;
	sub_82457A30(ctx, base);
	// lhz r10,118(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 118);
	// cmpwi cr6,r31,12
	cr6.compare<int32_t>(r31.s32, 12, xer);
	// lhz r9,114(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 114);
	// lhz r11,112(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 112);
	// blt cr6,0x823051a4
	if (cr6.lt) goto loc_823051A4;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r8,r8,7628
	ctx.r8.s64 = ctx.r8.s64 + 7628;
	// b 0x823051ac
	goto loc_823051AC;
loc_823051A4:
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r8,r8,7624
	ctx.r8.s64 = ctx.r8.s64 + 7624;
loc_823051AC:
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r7,7596
	ctx.r5.s64 = ctx.r7.s64 + 7596;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r4,63
	ctx.r4.s64 = 63;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x823051CC;
	sub_82137A08(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823051D4"))) PPC_WEAK_FUNC(sub_823051D4);
PPC_FUNC_IMPL(__imp__sub_823051D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823051D8"))) PPC_WEAK_FUNC(sub_823051D8);
PPC_FUNC_IMPL(__imp__sub_823051D8) {
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
	// lis r31,-32119
	r31.s64 = -2104950784;
	// lwz r3,-18004(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -18004);
	// bl 0x82304bd0
	ctx.lr = 0x823051F4;
	sub_82304BD0(ctx, base);
	// lwz r3,-18004(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -18004);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82305214
	if (cr6.eq) goto loc_82305214;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82305214;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82305214:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-18004(r31)
	PPC_STORE_U32(r31.u32 + -18004, r11.u32);
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

__attribute__((alias("__imp__sub_82305230"))) PPC_WEAK_FUNC(sub_82305230);
PPC_FUNC_IMPL(__imp__sub_82305230) {
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
	ctx.lr = 0x82305238;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// bl 0x822e4cc8
	ctx.lr = 0x82305250;
	sub_822E4CC8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// bl 0x822e5d40
	ctx.lr = 0x8230525C;
	sub_822E5D40(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,-1
	ctx.r5.s64 = -1;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822e5048
	ctx.lr = 0x82305270;
	sub_822E5048(ctx, base);
	// lis r28,-32124
	r28.s64 = -2105278464;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// lwz r11,-24876(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -24876);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r27,r8,r9
	r27.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// bl 0x822e50b8
	ctx.lr = 0x82305290;
	sub_822E50B8(ctx, base);
	// lis r7,-32119
	ctx.r7.s64 = -2104950784;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-9052(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -9052);
	// bl 0x82338fc0
	ctx.lr = 0x823052A0;
	sub_82338FC0(ctx, base);
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82305318
	if (cr6.eq) goto loc_82305318;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82310e40
	ctx.lr = 0x823052B4;
	sub_82310E40(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,-1
	ctx.r5.s64 = -1;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822e5048
	ctx.lr = 0x823052C8;
	sub_822E5048(ctx, base);
	// lwz r11,-24876(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -24876);
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r29,r8,r9
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// bl 0x822e50b8
	ctx.lr = 0x823052E4;
	sub_822E50B8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822e5048
	ctx.lr = 0x823052F8;
	sub_822E5048(ctx, base);
	// li r4,4096
	ctx.r4.s64 = 4096;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82183748
	ctx.lr = 0x82305304;
	sub_82183748(ctx, base);
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// bl 0x822e50b8
	ctx.lr = 0x8230530C;
	sub_822E50B8(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x82310ce8
	ctx.lr = 0x82305318;
	sub_82310CE8(ctx, base);
loc_82305318:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-12128(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12128);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82305330
	if (cr6.eq) goto loc_82305330;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x8230c388
	ctx.lr = 0x82305330;
	sub_8230C388(ctx, base);
loc_82305330:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7896(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7896);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82305348
	if (cr6.eq) goto loc_82305348;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x822e8060
	ctx.lr = 0x82305348;
	sub_822E8060(ctx, base);
loc_82305348:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9dc8
	ctx.lr = 0x8230535C;
	sub_821F9DC8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x822e5048
	ctx.lr = 0x82305370;
	sub_822E5048(ctx, base);
	// lwz r11,-24876(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -24876);
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r29,r8,r9
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// bl 0x822e50b8
	ctx.lr = 0x8230538C;
	sub_822E50B8(ctx, base);
	// lwz r7,8(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823053d8
	if (cr6.eq) goto loc_823053D8;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x822e5048
	ctx.lr = 0x823053AC;
	sub_822E5048(ctx, base);
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bgt cr6,0x823053bc
	if (cr6.gt) goto loc_823053BC;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_823053BC:
	// li r4,4096
	ctx.r4.s64 = 4096;
	// bl 0x82183748
	ctx.lr = 0x823053C4;
	sub_82183748(ctx, base);
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// bl 0x822e50b8
	ctx.lr = 0x823053CC;
	sub_822E50B8(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x823075c0
	ctx.lr = 0x823053D8;
	sub_823075C0(ctx, base);
loc_823053D8:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r29,0
	r29.s64 = 0;
	// addi r27,r11,22040
	r27.s64 = r11.s64 + 22040;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r30,r27
	r30.u64 = r27.u64;
	// addi r26,r11,7632
	r26.s64 = r11.s64 + 7632;
loc_823053F0:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// li r5,-1
	ctx.r5.s64 = -1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x822e5048
	ctx.lr = 0x82305404;
	sub_822E5048(ctx, base);
	// lwz r11,-24876(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -24876);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwzx r11,r8,r9
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// subf r6,r11,r6
	ctx.r6.s64 = ctx.r6.s64 - r11.s64;
	// bl 0x82130000
	ctx.lr = 0x82305434;
	sub_82130000(ctx, base);
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// bl 0x822e50b8
	ctx.lr = 0x8230543C;
	sub_822E50B8(ctx, base);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r10,r27,36
	ctx.r10.s64 = r27.s64 + 36;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x823053f0
	if (cr6.lt) goto loc_823053F0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82305458"))) PPC_WEAK_FUNC(sub_82305458);
PPC_FUNC_IMPL(__imp__sub_82305458) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82305108
	sub_82305108(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82305464"))) PPC_WEAK_FUNC(sub_82305464);
PPC_FUNC_IMPL(__imp__sub_82305464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82305468"))) PPC_WEAK_FUNC(sub_82305468);
PPC_FUNC_IMPL(__imp__sub_82305468) {
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
	// lis r11,-32208
	r11.s64 = -2110783488;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,20112
	ctx.r4.s64 = r11.s64 + 20112;
	// addi r3,r10,8104
	ctx.r3.s64 = ctx.r10.s64 + 8104;
	// bl 0x82554798
	ctx.lr = 0x82305488;
	sub_82554798(ctx, base);
	// lis r9,-32208
	ctx.r9.s64 = -2110783488;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,20152
	ctx.r4.s64 = ctx.r9.s64 + 20152;
	// addi r3,r8,8080
	ctx.r3.s64 = ctx.r8.s64 + 8080;
	// bl 0x82554798
	ctx.lr = 0x8230549C;
	sub_82554798(ctx, base);
	// lis r7,-32208
	ctx.r7.s64 = -2110783488;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,20256
	ctx.r4.s64 = ctx.r7.s64 + 20256;
	// addi r3,r6,8040
	ctx.r3.s64 = ctx.r6.s64 + 8040;
	// bl 0x82554798
	ctx.lr = 0x823054B0;
	sub_82554798(ctx, base);
	// lis r5,-32208
	ctx.r5.s64 = -2110783488;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,20336
	ctx.r4.s64 = ctx.r5.s64 + 20336;
	// addi r3,r3,8012
	ctx.r3.s64 = ctx.r3.s64 + 8012;
	// bl 0x82554798
	ctx.lr = 0x823054C4;
	sub_82554798(ctx, base);
	// lis r11,-32237
	r11.s64 = -2112684032;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,0
	ctx.r4.s64 = r11.s64 + 0;
	// addi r3,r10,7976
	ctx.r3.s64 = ctx.r10.s64 + 7976;
	// bl 0x82554798
	ctx.lr = 0x823054D8;
	sub_82554798(ctx, base);
	// lis r9,-32208
	ctx.r9.s64 = -2110783488;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,20400
	ctx.r4.s64 = ctx.r9.s64 + 20400;
	// addi r3,r8,7944
	ctx.r3.s64 = ctx.r8.s64 + 7944;
	// bl 0x82554798
	ctx.lr = 0x823054EC;
	sub_82554798(ctx, base);
	// lis r7,-32208
	ctx.r7.s64 = -2110783488;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,20456
	ctx.r4.s64 = ctx.r7.s64 + 20456;
	// addi r3,r6,7912
	ctx.r3.s64 = ctx.r6.s64 + 7912;
	// bl 0x82554798
	ctx.lr = 0x82305500;
	sub_82554798(ctx, base);
	// lis r5,-32208
	ctx.r5.s64 = -2110783488;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,20512
	ctx.r4.s64 = ctx.r5.s64 + 20512;
	// addi r3,r3,7876
	ctx.r3.s64 = ctx.r3.s64 + 7876;
	// bl 0x82554798
	ctx.lr = 0x82305514;
	sub_82554798(ctx, base);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,20552
	ctx.r4.s64 = r11.s64 + 20552;
	// addi r3,r10,7832
	ctx.r3.s64 = ctx.r10.s64 + 7832;
	// bl 0x82554798
	ctx.lr = 0x82305528;
	sub_82554798(ctx, base);
	// lis r9,-32208
	ctx.r9.s64 = -2110783488;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,20608
	ctx.r4.s64 = ctx.r9.s64 + 20608;
	// addi r3,r8,7808
	ctx.r3.s64 = ctx.r8.s64 + 7808;
	// bl 0x82554798
	ctx.lr = 0x8230553C;
	sub_82554798(ctx, base);
	// lis r7,-32208
	ctx.r7.s64 = -2110783488;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,21592
	ctx.r4.s64 = ctx.r7.s64 + 21592;
	// addi r3,r6,7780
	ctx.r3.s64 = ctx.r6.s64 + 7780;
	// bl 0x82554798
	ctx.lr = 0x82305550;
	sub_82554798(ctx, base);
	// lis r5,-32208
	ctx.r5.s64 = -2110783488;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,20664
	ctx.r4.s64 = ctx.r5.s64 + 20664;
	// addi r3,r3,7752
	ctx.r3.s64 = ctx.r3.s64 + 7752;
	// bl 0x82554798
	ctx.lr = 0x82305564;
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

__attribute__((alias("__imp__sub_82305574"))) PPC_WEAK_FUNC(sub_82305574);
PPC_FUNC_IMPL(__imp__sub_82305574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82305578"))) PPC_WEAK_FUNC(sub_82305578);
PPC_FUNC_IMPL(__imp__sub_82305578) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r9,r11,8480
	ctx.r9.s64 = r11.s64 + 8480;
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823055ac
	if (cr6.eq) goto loc_823055AC;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x821c90c0
	ctx.lr = 0x823055AC;
	sub_821C90C0(ctx, base);
loc_823055AC:
	// lis r11,-32123
	r11.s64 = -2105212928;
	// addi r10,r31,88
	ctx.r10.s64 = r31.s64 + 88;
	// addi r11,r11,23088
	r11.s64 = r11.s64 + 23088;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_823055C0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x823055c0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823055C0;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x821c9108
	ctx.lr = 0x823055DC;
	sub_821C9108(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x821c9108
	ctx.lr = 0x823055E4;
	sub_821C9108(ctx, base);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x821c90c0
	ctx.lr = 0x823055EC;
	sub_821C90C0(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x821c9168
	ctx.lr = 0x823055F4;
	sub_821C9168(ctx, base);
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bl 0x821c9158
	ctx.lr = 0x823055FC;
	sub_821C9158(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x821c9158
	ctx.lr = 0x82305604;
	sub_821C9158(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x821c9158
	ctx.lr = 0x8230560C;
	sub_821C9158(ctx, base);
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x821c9158
	ctx.lr = 0x82305614;
	sub_821C9158(ctx, base);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x821c9158
	ctx.lr = 0x8230561C;
	sub_821C9158(ctx, base);
	// addi r3,r31,52
	ctx.r3.s64 = r31.s64 + 52;
	// bl 0x82130000
	ctx.lr = 0x82305624;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8230562C;
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

__attribute__((alias("__imp__sub_82305640"))) PPC_WEAK_FUNC(sub_82305640);
PPC_FUNC_IMPL(__imp__sub_82305640) {
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
	// lis r31,-32119
	r31.s64 = -2104950784;
	// lwz r3,-17944(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -17944);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82305674
	if (cr6.eq) goto loc_82305674;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82305674;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82305674:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-17944(r31)
	PPC_STORE_U32(r31.u32 + -17944, r11.u32);
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

__attribute__((alias("__imp__sub_82305690"))) PPC_WEAK_FUNC(sub_82305690);
PPC_FUNC_IMPL(__imp__sub_82305690) {
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
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82305728
	if (!cr6.eq) goto loc_82305728;
	// addi r10,r31,88
	ctx.r10.s64 = r31.s64 + 88;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_823056C0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x823056c0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823056C0;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// stb r5,7(r31)
	PPC_STORE_U8(r31.u32 + 7, ctx.r5.u8);
	// lwz r11,-17932(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17932);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82305718
	if (!cr6.gt) goto loc_82305718;
	// bl 0x82178950
	ctx.lr = 0x823056EC;
	sub_82178950(ctx, base);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x821c9108
	ctx.lr = 0x823056F4;
	sub_821C9108(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x821c9108
	ctx.lr = 0x823056FC;
	sub_821C9108(ctx, base);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x821c90c0
	ctx.lr = 0x82305704;
	sub_821C90C0(ctx, base);
	// lbz r11,7(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 7);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82305718
	if (cr6.eq) goto loc_82305718;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x821c9108
	ctx.lr = 0x82305718;
	sub_821C9108(ctx, base);
loc_82305718:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// li r11,1
	r11.s64 = 1;
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// stb r11,22084(r10)
	PPC_STORE_U8(ctx.r10.u32 + 22084, r11.u8);
loc_82305728:
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

__attribute__((alias("__imp__sub_8230573C"))) PPC_WEAK_FUNC(sub_8230573C);
PPC_FUNC_IMPL(__imp__sub_8230573C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82305740"))) PPC_WEAK_FUNC(sub_82305740);
PPC_FUNC_IMPL(__imp__sub_82305740) {
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
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823057d4
	if (cr6.eq) goto loc_823057D4;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-17932(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17932);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8230579c
	if (!cr6.gt) goto loc_8230579C;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x821c9108
	ctx.lr = 0x82305778;
	sub_821C9108(ctx, base);
	// lbz r11,7(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 7);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8230578c
	if (!cr6.eq) goto loc_8230578C;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x821c9108
	ctx.lr = 0x8230578C;
	sub_821C9108(ctx, base);
loc_8230578C:
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x821c90c0
	ctx.lr = 0x82305794;
	sub_821C90C0(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x821c9078
	ctx.lr = 0x8230579C;
	sub_821C9078(ctx, base);
loc_8230579C:
	// lis r11,-32123
	r11.s64 = -2105212928;
	// addi r10,r31,88
	ctx.r10.s64 = r31.s64 + 88;
	// addi r11,r11,23088
	r11.s64 = r11.s64 + 23088;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_823057B0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x823057b0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_823057B0;
	// bl 0x82178990
	ctx.lr = 0x823057C8;
	sub_82178990(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// stb r11,7(r31)
	PPC_STORE_U8(r31.u32 + 7, r11.u8);
loc_823057D4:
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

__attribute__((alias("__imp__sub_823057E8"))) PPC_WEAK_FUNC(sub_823057E8);
PPC_FUNC_IMPL(__imp__sub_823057E8) {
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
	// lbz r11,7(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 7);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82305850
	if (!cr6.eq) goto loc_82305850;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82305850
	if (!cr6.eq) goto loc_82305850;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-17932(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17932);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82305850
	if (!cr6.gt) goto loc_82305850;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lbz r10,22084(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 22084);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82305850
	if (!cr6.eq) goto loc_82305850;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x821c9078
	ctx.lr = 0x8230583C;
	sub_821C9078(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82305850
	if (!cr6.eq) goto loc_82305850;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x821c90c0
	ctx.lr = 0x82305850;
	sub_821C90C0(ctx, base);
loc_82305850:
	// li r11,1
	r11.s64 = 1;
	// stb r11,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r11.u8);
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

__attribute__((alias("__imp__sub_8230586C"))) PPC_WEAK_FUNC(sub_8230586C);
PPC_FUNC_IMPL(__imp__sub_8230586C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82305870"))) PPC_WEAK_FUNC(sub_82305870);
PPC_FUNC_IMPL(__imp__sub_82305870) {
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
	// addi r10,r11,-17924
	ctx.r10.s64 = r11.s64 + -17924;
	// lbz r11,-16(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + -16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823058d8
	if (cr6.eq) goto loc_823058D8;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823058b0
	if (cr6.eq) goto loc_823058B0;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r4,r11,8576
	ctx.r4.s64 = r11.s64 + 8576;
	// b 0x823058b8
	goto loc_823058B8;
loc_823058B0:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r4,r11,8568
	ctx.r4.s64 = r11.s64 + 8568;
loc_823058B8:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,56
	ctx.r9.s64 = 56;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r8,8488
	ctx.r3.s64 = ctx.r8.s64 + 8488;
	// lwzx r7,r9,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// bl 0x82130000
	ctx.lr = 0x823058D8;
	sub_82130000(ctx, base);
loc_823058D8:
	// addi r3,r31,52
	ctx.r3.s64 = r31.s64 + 52;
	// bl 0x821c8f08
	ctx.lr = 0x823058E0;
	sub_821C8F08(ctx, base);
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

__attribute__((alias("__imp__sub_823058F4"))) PPC_WEAK_FUNC(sub_823058F4);
PPC_FUNC_IMPL(__imp__sub_823058F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823058F8"))) PPC_WEAK_FUNC(sub_823058F8);
PPC_FUNC_IMPL(__imp__sub_823058F8) {
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
	// addi r10,r11,-17924
	ctx.r10.s64 = r11.s64 + -17924;
	// lbz r11,-16(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + -16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82305960
	if (cr6.eq) goto loc_82305960;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82305938
	if (cr6.eq) goto loc_82305938;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r4,r11,8576
	ctx.r4.s64 = r11.s64 + 8576;
	// b 0x82305940
	goto loc_82305940;
loc_82305938:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r4,r11,8568
	ctx.r4.s64 = r11.s64 + 8568;
loc_82305940:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,56
	ctx.r9.s64 = 56;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r8,8584
	ctx.r3.s64 = ctx.r8.s64 + 8584;
	// lwzx r7,r9,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// bl 0x82130000
	ctx.lr = 0x82305960;
	sub_82130000(ctx, base);
loc_82305960:
	// addi r3,r31,52
	ctx.r3.s64 = r31.s64 + 52;
	// bl 0x821c8f70
	ctx.lr = 0x82305968;
	sub_821C8F70(ctx, base);
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

__attribute__((alias("__imp__sub_8230597C"))) PPC_WEAK_FUNC(sub_8230597C);
PPC_FUNC_IMPL(__imp__sub_8230597C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82305980"))) PPC_WEAK_FUNC(sub_82305980);
PPC_FUNC_IMPL(__imp__sub_82305980) {
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
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x821c9078
	ctx.lr = 0x8230599C;
	sub_821C9078(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823059b0
	if (cr6.eq) goto loc_823059B0;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x821c90c0
	ctx.lr = 0x823059B0;
	sub_821C90C0(ctx, base);
loc_823059B0:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x821c9108
	ctx.lr = 0x823059B8;
	sub_821C9108(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821c9108
	ctx.lr = 0x823059C0;
	sub_821C9108(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x821c90c0
	ctx.lr = 0x823059C8;
	sub_821C90C0(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x821c9168
	ctx.lr = 0x823059D0;
	sub_821C9168(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821c9158
	ctx.lr = 0x823059D8;
	sub_821C9158(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x821c9158
	ctx.lr = 0x823059E0;
	sub_821C9158(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x821c9158
	ctx.lr = 0x823059E8;
	sub_821C9158(ctx, base);
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

__attribute__((alias("__imp__sub_823059FC"))) PPC_WEAK_FUNC(sub_823059FC);
PPC_FUNC_IMPL(__imp__sub_823059FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82305A00"))) PPC_WEAK_FUNC(sub_82305A00);
PPC_FUNC_IMPL(__imp__sub_82305A00) {
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
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82305a28
	if (cr6.eq) goto loc_82305A28;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x821c90c0
	ctx.lr = 0x82305A28;
	sub_821C90C0(ctx, base);
loc_82305A28:
	// li r11,0
	r11.s64 = 0;
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
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

__attribute__((alias("__imp__sub_82305A44"))) PPC_WEAK_FUNC(sub_82305A44);
PPC_FUNC_IMPL(__imp__sub_82305A44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82305A48"))) PPC_WEAK_FUNC(sub_82305A48);
PPC_FUNC_IMPL(__imp__sub_82305A48) {
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
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821c90c0
	ctx.lr = 0x82305A68;
	sub_821C90C0(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x821c9078
	ctx.lr = 0x82305A70;
	sub_821C9078(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82305ab8
	if (!cr6.eq) goto loc_82305AB8;
	// lis r30,-32121
	r30.s64 = -2105081856;
loc_82305A80:
	// lwz r3,-12720(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12720);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82305A94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x821c9108
	ctx.lr = 0x82305A9C;
	sub_821C9108(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821c90c0
	ctx.lr = 0x82305AA4;
	sub_821C90C0(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x821c9078
	ctx.lr = 0x82305AAC;
	sub_821C9078(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82305a80
	if (cr6.eq) goto loc_82305A80;
loc_82305AB8:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x821c9108
	ctx.lr = 0x82305AC0;
	sub_821C9108(ctx, base);
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

__attribute__((alias("__imp__sub_82305AD8"))) PPC_WEAK_FUNC(sub_82305AD8);
PPC_FUNC_IMPL(__imp__sub_82305AD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12720(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12720);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82305AE4"))) PPC_WEAK_FUNC(sub_82305AE4);
PPC_FUNC_IMPL(__imp__sub_82305AE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82305AE8"))) PPC_WEAK_FUNC(sub_82305AE8);
PPC_FUNC_IMPL(__imp__sub_82305AE8) {
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
	// bl 0x82305578
	ctx.lr = 0x82305B08;
	sub_82305578(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82305b20
	if (cr6.eq) goto loc_82305B20;
	// bl 0x82130588
	ctx.lr = 0x82305B1C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82305B20:
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

__attribute__((alias("__imp__sub_82305B38"))) PPC_WEAK_FUNC(sub_82305B38);
PPC_FUNC_IMPL(__imp__sub_82305B38) {
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
	ctx.lr = 0x82305B40;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lis r31,-32130
	r31.s64 = -2105671680;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,-17936(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17936);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r11,22080(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 22080);
	// lwz r10,-10236(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// srawi r7,r8,1
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 1;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// addze r5,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r5.s64 = temp.s64;
	// srawi r4,r6,1
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r6.s32 >> 1;
	// rlwinm r3,r5,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// addze r7,r4
	temp.s64 = ctx.r4.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r7.s64 = temp.s64;
	// subf r11,r3,r8
	r11.s64 = ctx.r8.s64 - ctx.r3.s64;
	// rlwinm r5,r7,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r11,-17936(r9)
	PPC_STORE_U32(ctx.r9.u32 + -17936, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// subf r11,r5,r6
	r11.s64 = ctx.r6.s64 - ctx.r5.s64;
	// stw r11,22080(r31)
	PPC_STORE_U32(r31.u32 + 22080, r11.u32);
	// beq cr6,0x82305ca4
	if (cr6.eq) goto loc_82305CA4;
	// bl 0x822c4eb8
	ctx.lr = 0x82305B98;
	sub_822C4EB8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x822c4ec8
	ctx.lr = 0x82305BA0;
	sub_822C4EC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82305bbc
	if (cr6.eq) goto loc_82305BBC;
	// lwz r29,22080(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 22080);
	// bl 0x822c4eb8
	ctx.lr = 0x82305BB0;
	sub_822C4EB8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x822c53c8
	ctx.lr = 0x82305BBC;
	sub_822C53C8(ctx, base);
loc_82305BBC:
	// bl 0x822c4eb8
	ctx.lr = 0x82305BC0;
	sub_822C4EB8(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x822c4ec8
	ctx.lr = 0x82305BC8;
	sub_822C4EC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82305be4
	if (cr6.eq) goto loc_82305BE4;
	// lwz r29,22080(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 22080);
	// bl 0x822c4eb8
	ctx.lr = 0x82305BD8;
	sub_822C4EB8(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x822c53c8
	ctx.lr = 0x82305BE4;
	sub_822C53C8(ctx, base);
loc_82305BE4:
	// bl 0x822c4eb8
	ctx.lr = 0x82305BE8;
	sub_822C4EB8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822c4ec8
	ctx.lr = 0x82305BF0;
	sub_822C4EC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82305c0c
	if (cr6.eq) goto loc_82305C0C;
	// lwz r31,22080(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 22080);
	// bl 0x822c4eb8
	ctx.lr = 0x82305C00;
	sub_822C4EB8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x822c53c8
	ctx.lr = 0x82305C0C;
	sub_822C53C8(ctx, base);
loc_82305C0C:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,2836(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2836);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82305c20
	if (cr6.eq) goto loc_82305C20;
	// bl 0x821fced8
	ctx.lr = 0x82305C20;
	sub_821FCED8(ctx, base);
loc_82305C20:
	// lwz r3,-10236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// bl 0x821fd5b8
	ctx.lr = 0x82305C28;
	sub_821FD5B8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4964(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4964);
	// bl 0x82728b40
	ctx.lr = 0x82305C34;
	sub_82728B40(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-10012(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10012);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82305c48
	if (cr6.eq) goto loc_82305C48;
	// bl 0x826d6710
	ctx.lr = 0x82305C48;
	sub_826D6710(ctx, base);
loc_82305C48:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4960);
	// bl 0x823cb438
	ctx.lr = 0x82305C54;
	sub_823CB438(ctx, base);
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r3,-7572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82305c74
	if (cr6.eq) goto loc_82305C74;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7436);
	// bl 0x822f7368
	ctx.lr = 0x82305C70;
	sub_822F7368(ctx, base);
	// lwz r3,-7572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7572);
loc_82305C74:
	// bl 0x822f1740
	ctx.lr = 0x82305C78;
	sub_822F1740(ctx, base);
	// bl 0x822ecd40
	ctx.lr = 0x82305C7C;
	sub_822ECD40(ctx, base);
	// bl 0x822ecd28
	ctx.lr = 0x82305C80;
	sub_822ECD28(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,-12640(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82305C98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82324510
	ctx.lr = 0x82305C9C;
	sub_82324510(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x82305CA0;
	sub_82130000(ctx, base);
	// b 0x82305cb8
	goto loc_82305CB8;
loc_82305CA4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82305cb8
	if (cr6.eq) goto loc_82305CB8;
	// bl 0x826d6710
	ctx.lr = 0x82305CB8;
	sub_826D6710(ctx, base);
loc_82305CB8:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-18004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82305cd8
	if (cr6.eq) goto loc_82305CD8;
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82305cd8
	if (cr6.eq) goto loc_82305CD8;
	// bl 0x82311f80
	ctx.lr = 0x82305CD8;
	sub_82311F80(ctx, base);
loc_82305CD8:
	// bl 0x82740698
	ctx.lr = 0x82305CDC;
	sub_82740698(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-8092(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// bl 0x822e5b60
	ctx.lr = 0x82305CE8;
	sub_822E5B60(ctx, base);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lwz r11,-17924(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -17924);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,-17924(r10)
	PPC_STORE_U32(ctx.r10.u32 + -17924, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82305D00"))) PPC_WEAK_FUNC(sub_82305D00);
PPC_FUNC_IMPL(__imp__sub_82305D00) {
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
	ctx.lr = 0x82305D08;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lbz r11,4(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82305e2c
	if (cr6.eq) goto loc_82305E2C;
	// lbz r11,7(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 7);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82305e2c
	if (!cr6.eq) goto loc_82305E2C;
loc_82305D28:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82305d28
	if (cr6.eq) goto loc_82305D28;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
loc_82305D3C:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82305d3c
	if (cr6.eq) goto loc_82305D3C;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lbz r11,8(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82305d64
	if (!cr6.eq) goto loc_82305D64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823057e8
	ctx.lr = 0x82305D64;
	sub_823057E8(ctx, base);
loc_82305D64:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// li r28,0
	r28.s64 = 0;
	// stb r28,8(r27)
	PPC_STORE_U8(r27.u32 + 8, r28.u8);
	// lbz r10,-17940(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -17940);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82305da4
	if (cr6.eq) goto loc_82305DA4;
loc_82305D7C:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82305d7c
	if (cr6.eq) goto loc_82305D7C;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
loc_82305D90:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82305d90
	if (cr6.eq) goto loc_82305D90;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
loc_82305DA4:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82305b38
	ctx.lr = 0x82305DAC;
	sub_82305B38(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lbz r10,22084(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 22084);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82305dc4
	if (cr6.eq) goto loc_82305DC4;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// stb r10,22084(r11)
	PPC_STORE_U8(r11.u32 + 22084, ctx.r10.u8);
loc_82305DC4:
	// lis r29,-32119
	r29.s64 = -2104950784;
	// lwz r11,-17932(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17932);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82305de0
	if (!cr6.gt) goto loc_82305DE0;
	// lwz r3,20(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// bl 0x821c9108
	ctx.lr = 0x82305DDC;
	sub_821C9108(ctx, base);
	// b 0x82305e00
	goto loc_82305E00;
loc_82305DE0:
	// lwz r31,0(r13)
	r31.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r30,72
	r30.s64 = 72;
	// li r11,1
	r11.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r27,88
	ctx.r3.s64 = r27.s64 + 88;
	// stbx r11,r30,r31
	PPC_STORE_U8(r30.u32 + r31.u32, r11.u8);
	// bl 0x821c3048
	ctx.lr = 0x82305DFC;
	sub_821C3048(ctx, base);
	// stbx r28,r30,r31
	PPC_STORE_U8(r30.u32 + r31.u32, r28.u8);
loc_82305E00:
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lwz r11,-17932(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -17932);
	// lwz r10,-17928(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -17928);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x82305e1c
	if (cr6.eq) goto loc_82305E1C;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// stw r11,-17932(r29)
	PPC_STORE_U32(r29.u32 + -17932, r11.u32);
loc_82305E1C:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82305e2c
	if (!cr6.eq) goto loc_82305E2C;
	// lwz r3,24(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// bl 0x821c90c0
	ctx.lr = 0x82305E2C;
	sub_821C90C0(ctx, base);
loc_82305E2C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82305E34"))) PPC_WEAK_FUNC(sub_82305E34);
PPC_FUNC_IMPL(__imp__sub_82305E34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82305E38"))) PPC_WEAK_FUNC(sub_82305E38);
PPC_FUNC_IMPL(__imp__sub_82305E38) {
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
	ctx.lr = 0x82305E40;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-17932(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17932);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82305e68
	if (!cr6.gt) goto loc_82305E68;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// li r9,1
	ctx.r9.s64 = 1;
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
loc_82305E68:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82305e68
	if (cr6.eq) goto loc_82305E68;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lis r30,-32119
	r30.s64 = -2104950784;
	// lis r27,-32252
	r27.s64 = -2113667072;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// lis r26,-32122
	r26.s64 = -2105147392;
loc_82305E8C:
	// li r29,0
	r29.s64 = 0;
loc_82305E90:
	// lbz r11,-17940(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + -17940);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82305eb0
	if (cr6.eq) goto loc_82305EB0;
loc_82305E9C:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82305e9c
	if (cr6.eq) goto loc_82305E9C;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
loc_82305EB0:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x821c90c0
	ctx.lr = 0x82305EB8;
	sub_821C90C0(ctx, base);
	// lbz r11,-17940(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + -17940);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82305f00
	if (cr6.eq) goto loc_82305F00;
loc_82305EC4:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82305ec4
	if (cr6.eq) goto loc_82305EC4;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
loc_82305ED8:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82305ed8
	if (cr6.eq) goto loc_82305ED8;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
loc_82305EEC:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82305eec
	if (cr6.eq) goto loc_82305EEC;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
loc_82305F00:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x821c9078
	ctx.lr = 0x82305F08;
	sub_821C9078(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82305f24
	if (cr6.eq) goto loc_82305F24;
	// bl 0x82178950
	ctx.lr = 0x82305F18;
	sub_82178950(ctx, base);
	// lwz r3,40(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// bl 0x821c9108
	ctx.lr = 0x82305F20;
	sub_821C9108(ctx, base);
	// b 0x82305e8c
	goto loc_82305E8C;
loc_82305F24:
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x821c9078
	ctx.lr = 0x82305F2C;
	sub_821C9078(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82305f4c
	if (cr6.eq) goto loc_82305F4C;
	// bl 0x82178990
	ctx.lr = 0x82305F3C;
	sub_82178990(ctx, base);
	// lwz r3,36(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x821c9108
	ctx.lr = 0x82305F44;
	sub_821C9108(ctx, base);
	// li r29,1
	r29.s64 = 1;
	// b 0x82305e90
	goto loc_82305E90;
loc_82305F4C:
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x821c9078
	ctx.lr = 0x82305F54;
	sub_821C9078(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8230604c
	if (!cr6.eq) goto loc_8230604C;
loc_82305F60:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82305f60
	if (cr6.eq) goto loc_82305F60;
	// li r4,0
	ctx.r4.s64 = 0;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// bl 0x821c3048
	ctx.lr = 0x82305F80;
	sub_821C3048(ctx, base);
	// lwz r11,-8092(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -8092);
	// lbz r10,372(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 372);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82305fdc
	if (cr6.eq) goto loc_82305FDC;
loc_82305F90:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82305f90
	if (cr6.eq) goto loc_82305F90;
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lfs f0,8452(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8452);
	f0.f64 = double(temp.f32);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f9.u64);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// bge cr6,0x82305fdc
	if (!cr6.lt) goto loc_82305FDC;
	// subfic r3,r11,64
	xer.ca = r11.u32 <= 64;
	ctx.r3.s64 = 64 - r11.s64;
	// bl 0x821c91b8
	ctx.lr = 0x82305FDC;
	sub_821C91B8(ctx, base);
loc_82305FDC:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217c658
	ctx.lr = 0x82305FE8;
	sub_8217C658(ctx, base);
	// lbz r11,-17940(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + -17940);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8230601c
	if (cr6.eq) goto loc_8230601C;
loc_82305FF4:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82305ff4
	if (cr6.eq) goto loc_82305FF4;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
loc_82306008:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82306008
	if (cr6.eq) goto loc_82306008;
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
loc_8230601C:
	// lbz r11,7(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 7);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82306040
	if (!cr6.eq) goto loc_82306040;
	// lbz r11,1852(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 1852);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82306040
	if (!cr6.eq) goto loc_82306040;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x821c9108
	ctx.lr = 0x8230603C;
	sub_821C9108(ctx, base);
	// b 0x82305e90
	goto loc_82305E90;
loc_82306040:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x821c9108
	ctx.lr = 0x82306048;
	sub_821C9108(ctx, base);
	// b 0x82305e90
	goto loc_82305E90;
loc_8230604C:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8230605c
	if (cr6.eq) goto loc_8230605C;
	// bl 0x82178950
	ctx.lr = 0x8230605C;
	sub_82178950(ctx, base);
loc_8230605C:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// bl 0x821c9108
	ctx.lr = 0x82306064;
	sub_821C9108(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8230606C"))) PPC_WEAK_FUNC(sub_8230606C);
PPC_FUNC_IMPL(__imp__sub_8230606C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82306070"))) PPC_WEAK_FUNC(sub_82306070);
PPC_FUNC_IMPL(__imp__sub_82306070) {
	PPC_FUNC_PROLOGUE();
	// b 0x82305a48
	sub_82305A48(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82306074"))) PPC_WEAK_FUNC(sub_82306074);
PPC_FUNC_IMPL(__imp__sub_82306074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82306078"))) PPC_WEAK_FUNC(sub_82306078);
PPC_FUNC_IMPL(__imp__sub_82306078) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// bl 0x821c9060
	ctx.lr = 0x823060A0;
	sub_821C9060(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c9060
	ctx.lr = 0x823060AC;
	sub_821C9060(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c9060
	ctx.lr = 0x823060B8;
	sub_821C9060(ctx, base);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r8,r10,-17896
	ctx.r8.s64 = ctx.r10.s64 + -17896;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r3,-32208
	ctx.r3.s64 = -2110783488;
	// addi r7,r9,8668
	ctx.r7.s64 = ctx.r9.s64 + 8668;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r10,5(r31)
	PPC_STORE_U8(r31.u32 + 5, ctx.r10.u8);
	// li r6,-2
	ctx.r6.s64 = -2;
	// addi r3,r3,24688
	ctx.r3.s64 = ctx.r3.s64 + 24688;
	// bl 0x821c9308
	ctx.lr = 0x823060FC;
	sub_821C9308(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_82306118"))) PPC_WEAK_FUNC(sub_82306118);
PPC_FUNC_IMPL(__imp__sub_82306118) {
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
	ctx.lr = 0x8230612C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82306158
	if (cr6.eq) goto loc_82306158;
	// lis r4,0
	ctx.r4.s64 = 0;
	// ori r4,r4,32768
	ctx.r4.u64 = ctx.r4.u64 | 32768;
	// bl 0x82306078
	ctx.lr = 0x82306140;
	sub_82306078(ctx, base);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// stw r3,-17920(r11)
	PPC_STORE_U32(r11.u32 + -17920, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82306158:
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-17920(r10)
	PPC_STORE_U32(ctx.r10.u32 + -17920, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82306174"))) PPC_WEAK_FUNC(sub_82306174);
PPC_FUNC_IMPL(__imp__sub_82306174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82306178"))) PPC_WEAK_FUNC(sub_82306178);
PPC_FUNC_IMPL(__imp__sub_82306178) {
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
	// lis r30,-32119
	r30.s64 = -2104950784;
	// lwz r31,-17920(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -17920);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x823061ac
	if (cr6.eq) goto loc_823061AC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82305980
	ctx.lr = 0x823061A4;
	sub_82305980(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x823061AC;
	sub_82130588(ctx, base);
loc_823061AC:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-17920(r30)
	PPC_STORE_U32(r30.u32 + -17920, r11.u32);
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

__attribute__((alias("__imp__sub_823061CC"))) PPC_WEAK_FUNC(sub_823061CC);
PPC_FUNC_IMPL(__imp__sub_823061CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823061D0"))) PPC_WEAK_FUNC(sub_823061D0);
PPC_FUNC_IMPL(__imp__sub_823061D0) {
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
	// li r11,1
	r11.s64 = 1;
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821c9108
	ctx.lr = 0x823061F4;
	sub_821C9108(ctx, base);
	// lbz r10,5(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8230621c
	if (!cr6.eq) goto loc_8230621C;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82306214
	if (cr6.eq) goto loc_82306214;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x821c90c0
	ctx.lr = 0x82306214;
	sub_821C90C0(ctx, base);
loc_82306214:
	// li r11,0
	r11.s64 = 0;
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
loc_8230621C:
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

__attribute__((alias("__imp__sub_82306230"))) PPC_WEAK_FUNC(sub_82306230);
PPC_FUNC_IMPL(__imp__sub_82306230) {
	PPC_FUNC_PROLOGUE();
	// b 0x82305e38
	sub_82305E38(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82306234"))) PPC_WEAK_FUNC(sub_82306234);
PPC_FUNC_IMPL(__imp__sub_82306234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82306238"))) PPC_WEAK_FUNC(sub_82306238);
PPC_FUNC_IMPL(__imp__sub_82306238) {
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
	// li r30,0
	r30.s64 = 0;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,8480
	ctx.r9.s64 = r11.s64 + 8480;
	// stb r30,5(r31)
	PPC_STORE_U8(r31.u32 + 5, r30.u8);
	// addi r3,r31,52
	ctx.r3.s64 = r31.s64 + 52;
	// stb r10,6(r31)
	PPC_STORE_U8(r31.u32 + 6, ctx.r10.u8);
	// stb r30,7(r31)
	PPC_STORE_U8(r31.u32 + 7, r30.u8);
	// stw r4,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r4.u32);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stb r30,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r30.u8);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x82306288;
	sub_821C8ED8(ctx, base);
	// addi r3,r31,88
	ctx.r3.s64 = r31.s64 + 88;
	// bl 0x821c2f70
	ctx.lr = 0x82306290;
	sub_821C2F70(ctx, base);
	// lis r8,-32119
	ctx.r8.s64 = -2104950784;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// stw r30,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r30.u32);
	// addi r7,r8,-17876
	ctx.r7.s64 = ctx.r8.s64 + -17876;
	// li r11,2
	r11.s64 = 2;
	// stw r11,-17932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -17932, r11.u32);
	// lwz r9,4(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823062bc
	if (cr6.eq) goto loc_823062BC;
	// li r11,1
	r11.s64 = 1;
	// stw r11,-17932(r10)
	PPC_STORE_U32(ctx.r10.u32 + -17932, r11.u32);
loc_823062BC:
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,-17928(r10)
	PPC_STORE_U32(ctx.r10.u32 + -17928, r11.u32);
	// bl 0x821c9060
	ctx.lr = 0x823062CC;
	sub_821C9060(ctx, base);
	// stw r3,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c9060
	ctx.lr = 0x823062D8;
	sub_821C9060(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c9060
	ctx.lr = 0x823062E4;
	sub_821C9060(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c9060
	ctx.lr = 0x823062F0;
	sub_821C9060(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c9060
	ctx.lr = 0x823062FC;
	sub_821C9060(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c9060
	ctx.lr = 0x82306308;
	sub_821C9060(ctx, base);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c9060
	ctx.lr = 0x82306314;
	sub_821C9060(ctx, base);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c9060
	ctx.lr = 0x82306320;
	sub_821C9060(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821c9060
	ctx.lr = 0x8230632C;
	sub_821C9060(ctx, base);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lis r3,-32208
	ctx.r3.s64 = -2110783488;
	// addi r7,r9,8692
	ctx.r7.s64 = ctx.r9.s64 + 8692;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r3,25136
	ctx.r3.s64 = ctx.r3.s64 + 25136;
	// bl 0x821c9308
	ctx.lr = 0x82306358;
	sub_821C9308(ctx, base);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-17916
	ctx.r10.s64 = r11.s64 + -17916;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82306380
	if (cr6.eq) goto loc_82306380;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// li r11,1
	r11.s64 = 1;
	// stb r11,-17940(r10)
	PPC_STORE_U8(ctx.r10.u32 + -17940, r11.u8);
loc_82306380:
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

__attribute__((alias("__imp__sub_82306398"))) PPC_WEAK_FUNC(sub_82306398);
PPC_FUNC_IMPL(__imp__sub_82306398) {
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
	// li r3,112
	ctx.r3.s64 = 112;
	// bl 0x82130528
	ctx.lr = 0x823063AC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823063d4
	if (cr6.eq) goto loc_823063D4;
	// lis r4,1
	ctx.r4.s64 = 65536;
	// bl 0x82306238
	ctx.lr = 0x823063BC;
	sub_82306238(ctx, base);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// stw r3,-17944(r11)
	PPC_STORE_U32(r11.u32 + -17944, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_823063D4:
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-17944(r10)
	PPC_STORE_U32(ctx.r10.u32 + -17944, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823063F0"))) PPC_WEAK_FUNC(sub_823063F0);
PPC_FUNC_IMPL(__imp__sub_823063F0) {
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
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,8192
	ctx.r4.s64 = 8192;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82178598
	ctx.lr = 0x82306420;
	sub_82178598(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x82306468
	if (!cr6.eq) goto loc_82306468;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r10,r11,-17856
	ctx.r10.s64 = r11.s64 + -17856;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82306468
	if (!cr6.eq) goto loc_82306468;
	// bl 0x821d6348
	ctx.lr = 0x82306440;
	sub_821D6348(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82306468
	if (!cr6.eq) goto loc_82306468;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r5,r11,9040
	ctx.r5.s64 = r11.s64 + 9040;
	// addi r4,r10,9024
	ctx.r4.s64 = ctx.r10.s64 + 9024;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821772d8
	ctx.lr = 0x82306464;
	sub_821772D8(ctx, base);
	// b 0x823064a8
	goto loc_823064A8;
loc_82306468:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r5,r11,9040
	ctx.r5.s64 = r11.s64 + 9040;
	// addi r4,r10,-27836
	ctx.r4.s64 = ctx.r10.s64 + -27836;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821772d8
	ctx.lr = 0x82306480;
	sub_821772D8(ctx, base);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// addi r8,r9,-27408
	ctx.r8.s64 = ctx.r9.s64 + -27408;
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823064a8
	if (!cr6.eq) goto loc_823064A8;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r9,r10,-10144
	ctx.r9.s64 = ctx.r10.s64 + -10144;
	// addi r11,r11,3998
	r11.s64 = r11.s64 + 3998;
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
loc_823064A8:
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

__attribute__((alias("__imp__sub_823064C0"))) PPC_WEAK_FUNC(sub_823064C0);
PPC_FUNC_IMPL(__imp__sub_823064C0) {
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
	// bl 0x822e7028
	ctx.lr = 0x823064D8;
	sub_822E7028(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,9376
	ctx.r10.s64 = r11.s64 + 9376;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8233ab18
	ctx.lr = 0x823064E8;
	sub_8233AB18(ctx, base);
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

__attribute__((alias("__imp__sub_82306500"))) PPC_WEAK_FUNC(sub_82306500);
PPC_FUNC_IMPL(__imp__sub_82306500) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,1
	r11.s64 = 65536;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bgt cr6,0x82306710
	if (cr6.gt) goto loc_82306710;
	// beq cr6,0x823066cc
	if (cr6.eq) goto loc_823066CC;
	// cmpwi cr6,r4,4
	cr6.compare<int32_t>(ctx.r4.s32, 4, xer);
	// beq cr6,0x82306564
	if (cr6.eq) goto loc_82306564;
	// cmpwi cr6,r4,8
	cr6.compare<int32_t>(ctx.r4.s32, 8, xer);
	// bne cr6,0x82306740
	if (!cr6.eq) goto loc_82306740;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r4,2
	ctx.r4.s64 = 131072;
	// lwz r3,-7436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7436);
	// bl 0x822f7550
	ctx.lr = 0x82306540;
	sub_822F7550(ctx, base);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-9052(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -9052);
	// bl 0x8233ab98
	ctx.lr = 0x82306550;
	sub_8233AB98(ctx, base);
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
loc_82306564:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r4,2
	ctx.r4.s64 = 131072;
	// lwz r3,-7436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7436);
	// bl 0x822f7550
	ctx.lr = 0x82306574;
	sub_822F7550(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lis r8,-32119
	ctx.r8.s64 = -2104950784;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r11,-26876(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -26876);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r10,-17812(r8)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + -17812);
	// li r8,48
	ctx.r8.s64 = 48;
	// lvx128 v61,r11,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x823065e4
	if (cr6.eq) goto loc_823065E4;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r11,-17808
	ctx.r9.s64 = r11.s64 + -17808;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82306688
	goto loc_82306688;
loc_823065E4:
	// bl 0x823bbf80
	ctx.lr = 0x823065E8;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82306608
	if (cr6.eq) goto loc_82306608;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-8092(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// lbz r10,393(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 393);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82306688
	if (!cr6.eq) goto loc_82306688;
loc_82306608:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82306688
	if (cr6.eq) goto loc_82306688;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82306640
	if (cr6.eq) goto loc_82306640;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8230665c
	if (!cr6.gt) goto loc_8230665C;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x82306650
	goto loc_82306650;
loc_82306640:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8230665c
	if (!cr6.gt) goto loc_8230665C;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_82306650:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82306660
	if (!cr6.eq) goto loc_82306660;
loc_8230665C:
	// li r11,0
	r11.s64 = 0;
loc_82306660:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82306688
	if (cr6.eq) goto loc_82306688;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3998
	ctx.lr = 0x82306674;
	sub_822A3998(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x82306678;
	sub_822A8108(ctx, base);
	// li r11,48
	r11.s64 = 48;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v59,r3,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82306688:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// lis r31,-32119
	r31.s64 = -2104950784;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f0,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lwz r3,-9052(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -9052);
	// bl 0x8233a450
	ctx.lr = 0x823066AC;
	sub_8233A450(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-9052(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -9052);
	// bl 0x8233ab98
	ctx.lr = 0x823066B8;
	sub_8233AB98(ctx, base);
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
loc_823066CC:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x822f21e8
	ctx.lr = 0x823066D8;
	sub_822F21E8(ctx, base);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r11,-8092(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// lwz r9,364(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 364);
	// rlwinm r8,r9,0,7,7
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000000;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82306740
	if (cr6.eq) goto loc_82306740;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-12284(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12284);
	// bl 0x82307f28
	ctx.lr = 0x823066FC;
	sub_82307F28(ctx, base);
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
loc_82306710:
	// lis r11,256
	r11.s64 = 16777216;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bne cr6,0x82306740
	if (!cr6.eq) goto loc_82306740;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-8092(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// lwz r10,364(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 364);
	// rlwinm r9,r10,0,7,7
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000000;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82306740
	if (cr6.eq) goto loc_82306740;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-12284(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12284);
	// bl 0x82308178
	ctx.lr = 0x82306740;
	sub_82308178(ctx, base);
loc_82306740:
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

__attribute__((alias("__imp__sub_82306754"))) PPC_WEAK_FUNC(sub_82306754);
PPC_FUNC_IMPL(__imp__sub_82306754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82306758"))) PPC_WEAK_FUNC(sub_82306758);
PPC_FUNC_IMPL(__imp__sub_82306758) {
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
	// lis r11,1
	r11.s64 = 65536;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bgt cr6,0x82306818
	if (cr6.gt) goto loc_82306818;
	// beq cr6,0x823067f8
	if (cr6.eq) goto loc_823067F8;
	// cmpwi cr6,r4,4
	cr6.compare<int32_t>(ctx.r4.s32, 4, xer);
	// beq cr6,0x823067cc
	if (cr6.eq) goto loc_823067CC;
	// cmpwi cr6,r4,8
	cr6.compare<int32_t>(ctx.r4.s32, 8, xer);
	// bne cr6,0x82306848
	if (!cr6.eq) goto loc_82306848;
	// lis r31,-32119
	r31.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-9052(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -9052);
	// bl 0x8233af30
	ctx.lr = 0x82306798;
	sub_8233AF30(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190870
	ctx.lr = 0x823067A0;
	sub_82190870(ctx, base);
	// lwz r3,-9052(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -9052);
	// bl 0x82339868
	ctx.lr = 0x823067A8;
	sub_82339868(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r4,16
	ctx.r4.s64 = 1048576;
	// lwz r3,-7436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7436);
	// bl 0x822f7570
	ctx.lr = 0x823067B8;
	sub_822F7570(ctx, base);
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
loc_823067CC:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-9052(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -9052);
	// bl 0x8233af30
	ctx.lr = 0x823067DC;
	sub_8233AF30(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190870
	ctx.lr = 0x823067E4;
	sub_82190870(ctx, base);
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
loc_823067F8:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x822f2300
	ctx.lr = 0x82306804;
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
loc_82306818:
	// lis r11,256
	r11.s64 = 16777216;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bne cr6,0x82306848
	if (!cr6.eq) goto loc_82306848;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-8092(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// lwz r10,364(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 364);
	// rlwinm r9,r10,0,7,7
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000000;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82306848
	if (cr6.eq) goto loc_82306848;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-12284(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12284);
	// bl 0x823082b0
	ctx.lr = 0x82306848;
	sub_823082B0(ctx, base);
loc_82306848:
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

__attribute__((alias("__imp__sub_8230685C"))) PPC_WEAK_FUNC(sub_8230685C);
PPC_FUNC_IMPL(__imp__sub_8230685C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82306860"))) PPC_WEAK_FUNC(sub_82306860);
PPC_FUNC_IMPL(__imp__sub_82306860) {
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
	// bl 0x822e7028
	ctx.lr = 0x82306878;
	sub_822E7028(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,9392
	ctx.r10.s64 = r11.s64 + 9392;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822e7418
	ctx.lr = 0x82306888;
	sub_822E7418(ctx, base);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// addi r8,r9,-7924
	ctx.r8.s64 = ctx.r9.s64 + -7924;
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823068b4
	if (!cr6.eq) goto loc_823068B4;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r10,r11,-17772
	ctx.r10.s64 = r11.s64 + -17772;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x823068b8
	if (cr6.eq) goto loc_823068B8;
loc_823068B4:
	// li r11,0
	r11.s64 = 0;
loc_823068B8:
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r10,-17792
	ctx.r8.s64 = ctx.r10.s64 + -17792;
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cntlzw r7,r11
	ctx.r7.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stb r6,5(r31)
	PPC_STORE_U8(r31.u32 + 5, ctx.r6.u8);
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

__attribute__((alias("__imp__sub_823068EC"))) PPC_WEAK_FUNC(sub_823068EC);
PPC_FUNC_IMPL(__imp__sub_823068EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823068F0"))) PPC_WEAK_FUNC(sub_823068F0);
PPC_FUNC_IMPL(__imp__sub_823068F0) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,9376
	ctx.r10.s64 = r11.s64 + 9376;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82339178
	ctx.lr = 0x8230691C;
	sub_82339178(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822e7018
	ctx.lr = 0x82306924;
	sub_822E7018(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8230693c
	if (cr6.eq) goto loc_8230693C;
	// bl 0x82130588
	ctx.lr = 0x82306938;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8230693C:
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

__attribute__((alias("__imp__sub_82306954"))) PPC_WEAK_FUNC(sub_82306954);
PPC_FUNC_IMPL(__imp__sub_82306954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82306958"))) PPC_WEAK_FUNC(sub_82306958);
PPC_FUNC_IMPL(__imp__sub_82306958) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,9392
	ctx.r10.s64 = r11.s64 + 9392;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822e75b0
	ctx.lr = 0x82306984;
	sub_822E75B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822e7018
	ctx.lr = 0x8230698C;
	sub_822E7018(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823069a4
	if (cr6.eq) goto loc_823069A4;
	// bl 0x82130588
	ctx.lr = 0x823069A0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823069A4:
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

__attribute__((alias("__imp__sub_823069BC"))) PPC_WEAK_FUNC(sub_823069BC);
PPC_FUNC_IMPL(__imp__sub_823069BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823069C0"))) PPC_WEAK_FUNC(sub_823069C0);
PPC_FUNC_IMPL(__imp__sub_823069C0) {
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
	// lis r11,512
	r11.s64 = 33554432;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bne cr6,0x82306a10
	if (!cr6.eq) goto loc_82306A10;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7900(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7900);
	// bl 0x822e7620
	ctx.lr = 0x823069E4;
	sub_822E7620(ctx, base);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lwz r11,-18004(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -18004);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x827481c0
	ctx.lr = 0x823069F4;
	sub_827481C0(ctx, base);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lwz r3,-7788(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -7788);
	// bl 0x822eb798
	ctx.lr = 0x82306A00;
	sub_822EB798(ctx, base);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lwz r11,3528(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 3528);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x822dd720
	ctx.lr = 0x82306A10;
	sub_822DD720(ctx, base);
loc_82306A10:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82306A20"))) PPC_WEAK_FUNC(sub_82306A20);
PPC_FUNC_IMPL(__imp__sub_82306A20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r11,-17408
	ctx.r5.s64 = r11.s64 + -17408;
	// addi r6,r5,60
	ctx.r6.s64 = ctx.r5.s64 + 60;
loc_82306A30:
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// li r8,4
	ctx.r8.s64 = 4;
loc_82306A38:
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// li r11,4
	r11.s64 = 4;
loc_82306A40:
	// stb r7,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r7.u8);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1280
	ctx.r10.s64 = ctx.r10.s64 + 1280;
	// bne 0x82306a40
	if (!cr0.eq) goto loc_82306A40;
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r9,r9,320
	ctx.r9.s64 = ctx.r9.s64 + 320;
	// bne 0x82306a38
	if (!cr0.eq) goto loc_82306A38;
	// addi r6,r6,80
	ctx.r6.s64 = ctx.r6.s64 + 80;
	// addi r11,r5,380
	r11.s64 = ctx.r5.s64 + 380;
	// cmpw cr6,r6,r11
	cr6.compare<int32_t>(ctx.r6.s32, r11.s32, xer);
	// blt cr6,0x82306a30
	if (cr6.lt) goto loc_82306A30;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// stw r11,-17432(r10)
	PPC_STORE_U32(ctx.r10.u32 + -17432, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82306A7C"))) PPC_WEAK_FUNC(sub_82306A7C);
PPC_FUNC_IMPL(__imp__sub_82306A7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82306A80"))) PPC_WEAK_FUNC(sub_82306A80);
PPC_FUNC_IMPL(__imp__sub_82306A80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82306A88;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r27,r11,-17408
	r27.s64 = r11.s64 + -17408;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// addi r7,r11,22320
	ctx.r7.s64 = r11.s64 + 22320;
	// addi r6,r9,22304
	ctx.r6.s64 = ctx.r9.s64 + 22304;
	// lfs f10,22304(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 22304);
	ctx.f10.f64 = double(temp.f32);
	// addi r31,r10,-17424
	r31.s64 = ctx.r10.s64 + -17424;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f7,22320(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 22320);
	ctx.f7.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lwz r8,-17424(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -17424);
	// lis r3,23772
	ctx.r3.s64 = 1557921792;
	// lfs f9,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,8(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// addi r28,r27,40
	r28.s64 = r27.s64 + 40;
	// lfs f11,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f8,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f8.f64 = double(temp.f32);
	// ori r11,r3,64167
	r11.u64 = ctx.r3.u64 | 64167;
	// lfs f0,14348(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14348);
	f0.f64 = double(temp.f32);
	// lfs f13,14884(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
loc_82306AE8:
	// mr r30,r28
	r30.u64 = r28.u64;
	// li r29,4
	r29.s64 = 4;
loc_82306AF0:
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r4,4
	ctx.r4.s64 = 4;
loc_82306AF8:
	// clrldi r8,r8,32
	ctx.r8.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// mulld r8,r8,r11
	ctx.r8.s64 = ctx.r8.s64 * r11.s64;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addic. r4,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// rotlwi r8,r9,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// rldicl r7,r9,32,32
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF;
	// mulld r8,r8,r11
	ctx.r8.s64 = ctx.r8.s64 * r11.s64;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// clrlwi r9,r9,9
	ctx.r9.u64 = ctx.r9.u32 & 0x7FFFFF;
	// rotlwi r7,r8,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// rldicl r6,r8,32,32
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// mulld r7,r7,r11
	ctx.r7.s64 = ctx.r7.s64 * r11.s64;
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// clrlwi r8,r8,9
	ctx.r8.u64 = ctx.r8.u32 & 0x7FFFFF;
	// rotlwi r6,r7,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// rldicl r5,r7,32,32
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF;
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// mulld r6,r6,r11
	ctx.r6.s64 = ctx.r6.s64 * r11.s64;
	// lfd f6,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f4,f6
	ctx.f4.f64 = double(ctx.f6.s64);
	// add r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 + ctx.r5.u64;
	// clrlwi r7,r7,9
	ctx.r7.u64 = ctx.r7.u32 & 0x7FFFFF;
	// std r7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// rldicl r3,r6,32,32
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u64, 32) & 0xFFFFFFFF;
	// rotlwi r5,r6,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// clrlwi r6,r6,9
	ctx.r6.u64 = ctx.r6.u32 & 0x7FFFFF;
	// lfd f5,88(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// mulld r5,r5,r11
	ctx.r5.s64 = ctx.r5.s64 * r11.s64;
	// fcfid f2,f5
	ctx.f2.f64 = double(ctx.f5.s64);
	// std r6,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r6.u64);
	// lfd f1,104(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// add r5,r5,r3
	ctx.r5.u64 = ctx.r5.u64 + ctx.r3.u64;
	// lfd f3,96(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// rotlwi r9,r5,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// fcfid f6,f3
	ctx.f6.f64 = double(ctx.f3.s64);
	// rldicl r8,r5,32,32
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u64, 32) & 0xFFFFFFFF;
	// mulld r9,r9,r11
	ctx.r9.s64 = ctx.r9.s64 * r11.s64;
	// frsp f6,f6
	ctx.f6.f64 = double(float(ctx.f6.f64));
	// clrlwi r3,r5,9
	ctx.r3.u64 = ctx.r5.u32 & 0x7FFFFF;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// std r3,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r3.u64);
	// lfd f5,112(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// clrlwi r6,r9,9
	ctx.r6.u64 = ctx.r9.u32 & 0x7FFFFF;
	// fmsubs f6,f6,f0,f13
	ctx.f6.f64 = double(float(ctx.f6.f64 * f0.f64 - ctx.f13.f64));
	// rotlwi r8,r9,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// std r6,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r6.u64);
	// rldicl r9,r9,32,32
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// fcfid f3,f1
	ctx.f3.f64 = double(ctx.f1.s64);
	// fcfid f1,f5
	ctx.f1.f64 = double(ctx.f5.s64);
	// frsp f5,f4
	ctx.f5.f64 = double(float(ctx.f4.f64));
	// frsp f4,f2
	ctx.f4.f64 = double(float(ctx.f2.f64));
	// lfd f2,120(r1)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f2,f2
	ctx.f2.f64 = double(ctx.f2.s64);
	// frsp f3,f3
	ctx.f3.f64 = double(float(ctx.f3.f64));
	// frsp f1,f1
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// frsp f2,f2
	ctx.f2.f64 = double(float(ctx.f2.f64));
	// fmsubs f5,f5,f0,f13
	ctx.f5.f64 = double(float(ctx.f5.f64 * f0.f64 - ctx.f13.f64));
	// fmsubs f4,f4,f0,f13
	ctx.f4.f64 = double(float(ctx.f4.f64 * f0.f64 - ctx.f13.f64));
	// fmuls f6,f6,f10
	ctx.f6.f64 = double(float(ctx.f6.f64 * ctx.f10.f64));
	// stfs f6,-8(r10)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r10.u32 + -8, temp.u32);
	// fmsubs f3,f3,f0,f13
	ctx.f3.f64 = double(float(ctx.f3.f64 * f0.f64 - ctx.f13.f64));
	// fmsubs f1,f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64 - ctx.f13.f64));
	// fmsubs f2,f2,f0,f13
	ctx.f2.f64 = double(float(ctx.f2.f64 * f0.f64 - ctx.f13.f64));
	// fmuls f5,f5,f12
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f12.f64));
	// stfs f5,0(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fmuls f5,f4,f11
	ctx.f5.f64 = double(float(ctx.f4.f64 * ctx.f11.f64));
	// stfs f5,-4(r10)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r10.u32 + -4, temp.u32);
	// fmuls f4,f3,f9
	ctx.f4.f64 = double(float(ctx.f3.f64 * ctx.f9.f64));
	// stfs f4,-16(r10)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r10.u32 + -16, temp.u32);
	// fmuls f3,f1,f8
	ctx.f3.f64 = double(float(ctx.f1.f64 * ctx.f8.f64));
	// stfs f3,-20(r10)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r10.u32 + -20, temp.u32);
	// fmuls f1,f2,f7
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f7.f64));
	// stfs f1,-24(r10)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + -24, temp.u32);
	// addi r10,r10,1280
	ctx.r10.s64 = ctx.r10.s64 + 1280;
	// bne 0x82306af8
	if (!cr0.eq) goto loc_82306AF8;
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,320
	r30.s64 = r30.s64 + 320;
	// bne 0x82306af0
	if (!cr0.eq) goto loc_82306AF0;
	// addi r28,r28,80
	r28.s64 = r28.s64 + 80;
	// addi r10,r27,360
	ctx.r10.s64 = r27.s64 + 360;
	// cmpw cr6,r28,r10
	cr6.compare<int32_t>(r28.s32, ctx.r10.s32, xer);
	// blt cr6,0x82306ae8
	if (cr6.lt) goto loc_82306AE8;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// lis r31,-32119
	r31.s64 = -2104950784;
	// lwz r11,-17428(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -17428);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82306cac
	if (!cr6.eq) goto loc_82306CAC;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// addi r4,r10,10092
	ctx.r4.s64 = ctx.r10.s64 + 10092;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x82306C78;
	sub_821CA540(ctx, base);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r8,-18148
	ctx.r4.s64 = ctx.r8.s64 + -18148;
	// lwz r3,-25232(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25232);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,12(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82306C9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,-17428(r31)
	PPC_STORE_U32(r31.u32 + -17428, r11.u32);
	// bl 0x821c9a90
	ctx.lr = 0x82306CAC;
	sub_821C9A90(ctx, base);
loc_82306CAC:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82306CB4"))) PPC_WEAK_FUNC(sub_82306CB4);
PPC_FUNC_IMPL(__imp__sub_82306CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82306CB8"))) PPC_WEAK_FUNC(sub_82306CB8);
PPC_FUNC_IMPL(__imp__sub_82306CB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	PPCVRegister v19{};
	PPCVRegister v20{};
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
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82306CC0;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9a8
	ctx.lr = 0x82306CC8;
	// li r12,-336
	r12.s64 = -336;
	// stvx128 v125,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-320
	r12.s64 = -320;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-304
	r12.s64 = -304;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-704(r1)
	ea = -704 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32112
	r28.s64 = -2104492032;
	// lwz r11,21664(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 21664);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82307484
	if (cr6.eq) goto loc_82307484;
	// lis r29,-32124
	r29.s64 = -2105278464;
	// lwz r31,-26876(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -26876);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f16,696(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 696);
	f16.f64 = double(temp.f32);
	// lfs f31,708(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 708);
	f31.f64 = double(temp.f32);
	// lfs f30,704(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 704);
	f30.f64 = double(temp.f32);
	// bl 0x82171600
	ctx.lr = 0x82306D10;
	sub_82171600(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// lfs f1,22260(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 22260);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217d460
	ctx.lr = 0x82306D2C;
	sub_8217D460(ctx, base);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lwz r3,-26876(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -26876);
	// addi r4,r10,-31280
	ctx.r4.s64 = ctx.r10.s64 + -31280;
	// bl 0x8217c088
	ctx.lr = 0x82306D3C;
	sub_8217C088(ctx, base);
	// lwz r3,-26876(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -26876);
	// bl 0x8217c568
	ctx.lr = 0x82306D44;
	sub_8217C568(ctx, base);
	// lwz r3,-26876(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -26876);
	// bl 0x8217c568
	ctx.lr = 0x82306D4C;
	sub_8217C568(ctx, base);
	// lis r16,-32256
	r16.s64 = -2113929216;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f1,7444(r16)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r16.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82178370
	ctx.lr = 0x82306D6C;
	sub_82178370(ctx, base);
	// lwz r11,21664(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 21664);
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// lwz r6,-17428(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17428);
	// addi r4,r10,16
	ctx.r4.s64 = ctx.r10.s64 + 16;
	// lwz r5,176(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x82306D8C;
	sub_82189CE0(ctx, base);
	// lis r17,-32130
	r17.s64 = -2105671680;
	// lwz r11,-26876(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -26876);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f0,22264(r17)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r17.u32 + 22264);
	f0.f64 = double(temp.f32);
	// li r5,112
	ctx.r5.s64 = 112;
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lis r26,-32130
	r26.s64 = -2105671680;
	// stfs f0,136(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v59,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// vaddfp128 v60,v62,v61
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
	// lfs f2,22256(r26)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 22256);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,120(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 120);
	ctx.f1.f64 = double(temp.f32);
	// stvx128 v59,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x823dc100
	ctx.lr = 0x82306DF4;
	sub_823DC100(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lfs f11,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f11.f64 = double(temp.f32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lfs f17,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	f17.f64 = double(temp.f32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// lfs f30,3796(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 3796);
	f30.f64 = double(temp.f32);
	// fsubs f25,f11,f12
	f25.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// stfs f25,200(r1)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// fcmpu cr6,f25,f17
	cr6.compare(f25.f64, f17.f64);
	// bge cr6,0x823073b0
	if (!cr6.lt) goto loc_823073B0;
	// addi r9,r1,352
	ctx.r9.s64 = ctx.r1.s64 + 352;
	// lfs f20,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	f20.f64 = double(temp.f32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lfs f21,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	f21.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f18,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f18.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f19,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f19.f64 = double(temp.f32);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f29,22256(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 22256);
	f29.f64 = double(temp.f32);
	// lvx128 v127,r0,r9
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f23,-332(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -332);
	f23.f64 = double(temp.f32);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lfs f22,14884(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14884);
	f22.f64 = double(temp.f32);
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lfs f24,18612(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 18612);
	f24.f64 = double(temp.f32);
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lis r6,-32119
	ctx.r6.s64 = -2104950784;
	// lwz r31,-26876(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -26876);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// lis r3,-32119
	ctx.r3.s64 = -2104950784;
	// addi r11,r11,29952
	r11.s64 = r11.s64 + 29952;
	// addi r10,r10,-31664
	ctx.r10.s64 = ctx.r10.s64 + -31664;
	// addi r9,r9,-31648
	ctx.r9.s64 = ctx.r9.s64 + -31648;
	// stw r11,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r11.u32);
	// addi r8,r8,2240
	ctx.r8.s64 = ctx.r8.s64 + 2240;
	// stw r10,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r10.u32);
	// addi r7,r7,2528
	ctx.r7.s64 = ctx.r7.s64 + 2528;
	// stw r9,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r9.u32);
	// addi r6,r6,-17440
	ctx.r6.s64 = ctx.r6.s64 + -17440;
	// stw r8,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r8.u32);
	// addi r5,r5,22288
	ctx.r5.s64 = ctx.r5.s64 + 22288;
	// stw r7,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r7.u32);
	// li r14,16
	r14.s64 = 16;
	// stw r6,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r6.u32);
	// li r25,-1
	r25.s64 = -1;
	// stw r5,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r5.u32);
	// lis r27,-32119
	r27.s64 = -2104950784;
	// lis r23,-32119
	r23.s64 = -2104950784;
	// lis r22,-32130
	r22.s64 = -2105671680;
	// lis r21,-32130
	r21.s64 = -2105671680;
	// lis r20,-32130
	r20.s64 = -2105671680;
	// lis r19,-32130
	r19.s64 = -2105671680;
	// lis r18,-32130
	r18.s64 = -2105671680;
	// addi r15,r4,22272
	r15.s64 = ctx.r4.s64 + 22272;
	// addi r24,r3,-17408
	r24.s64 = ctx.r3.s64 + -17408;
loc_82306EE8:
	// lfs f1,116(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	ctx.f1.f64 = double(temp.f32);
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// bl 0x823dc100
	ctx.lr = 0x82306EF4;
	sub_823DC100(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// lfs f29,22256(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 22256);
	f29.f64 = double(temp.f32);
	// lwz r31,-26876(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -26876);
	// fsubs f26,f18,f0
	f26.f64 = double(float(f18.f64 - f0.f64));
	// stfs f26,196(r1)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// fcmpu cr6,f26,f20
	cr6.compare(f26.f64, f20.f64);
	// bge cr6,0x823073a0
	if (!cr6.lt) goto loc_823073A0;
loc_82306F10:
	// lfs f1,112(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// bl 0x823dc100
	ctx.lr = 0x82306F1C;
	sub_823DC100(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// lwz r31,-26876(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -26876);
	// lfs f29,22256(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 22256);
	f29.f64 = double(temp.f32);
	// fsubs f27,f19,f0
	f27.f64 = double(float(f19.f64 - f0.f64));
	// stfs f27,192(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// fcmpu cr6,f27,f21
	cr6.compare(f27.f64, f21.f64);
	// bge cr6,0x82307390
	if (!cr6.lt) goto loc_82307390;
	// lfs f28,22264(r17)
	temp.u32 = PPC_LOAD_U32(r17.u32 + 22264);
	f28.f64 = double(temp.f32);
	// lfs f31,7444(r16)
	temp.u32 = PPC_LOAD_U32(r16.u32 + 7444);
	f31.f64 = double(temp.f32);
loc_82306F40:
	// fdivs f0,f31,f29
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 / f29.f64));
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// addi r4,r31,384
	ctx.r4.s64 = r31.s64 + 384;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// lvx128 v126,r0,r11
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f13,f0,f26
	ctx.f13.f64 = double(float(f0.f64 * f26.f64));
	// fmuls f12,f0,f25
	ctx.f12.f64 = double(float(f0.f64 * f25.f64));
	// fmuls f11,f0,f27
	ctx.f11.f64 = double(float(f0.f64 * f27.f64));
	// fctiwz f10,f13
	ctx.f10.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f9,f12
	ctx.f9.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f8,f11
	ctx.f8.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// clrlwi r11,r9,30
	r11.u64 = ctx.r9.u32 & 0x3;
	// clrlwi r9,r8,30
	ctx.r9.u64 = ctx.r8.u32 & 0x3;
	// rlwinm r10,r7,2,28,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xC;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// add r30,r11,r24
	r30.u64 = r11.u64 + r24.u64;
	// lvx128 v58,r30,r14
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r14.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v125,v126,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v125.f32, simde_mm_add_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v58.f32)));
	// vor128 v1,v125,v125
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v125.u8));
	// bl 0x8217bd00
	ctx.lr = 0x82306FBC;
	sub_8217BD00(ctx, base);
	// vor128 v1,v125,v125
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v125.u8));
	// addi r4,r31,256
	ctx.r4.s64 = r31.s64 + 256;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x8217bd00
	ctx.lr = 0x82306FCC;
	sub_8217BD00(ctx, base);
	// lfs f0,260(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 260);
	f0.f64 = double(temp.f32);
	// fmuls f7,f0,f0
	ctx.f7.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,264(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 264);
	f0.f64 = double(temp.f32);
	// lfs f13,256(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 256);
	ctx.f13.f64 = double(temp.f32);
	// fneg f6,f0
	ctx.f6.u64 = f0.u64 ^ 0x8000000000000000;
	// lfs f5,22240(r18)
	temp.u32 = PPC_LOAD_U32(r18.u32 + 22240);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,22236(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 22236);
	ctx.f4.f64 = double(temp.f32);
	// fadds f3,f0,f5
	ctx.f3.f64 = double(float(f0.f64 + ctx.f5.f64));
	// lfs f2,22244(r21)
	temp.u32 = PPC_LOAD_U32(r21.u32 + 22244);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,22248(r20)
	temp.u32 = PPC_LOAD_U32(r20.u32 + 22248);
	ctx.f1.f64 = double(temp.f32);
	// lfs f12,22268(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 22268);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-17436(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -17436);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f13,f13,f7
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f7.f64));
	// fsubs f9,f6,f4
	ctx.f9.f64 = double(float(ctx.f6.f64 - ctx.f4.f64));
	// fmuls f8,f3,f2
	ctx.f8.f64 = double(float(ctx.f3.f64 * ctx.f2.f64));
	// fmadds f7,f0,f0,f10
	ctx.f7.f64 = double(float(f0.f64 * f0.f64 + ctx.f10.f64));
	// fmuls f6,f9,f1
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f1.f64));
	// fsel f5,f8,f8,f30
	ctx.f5.f64 = ctx.f8.f64 >= 0.0 ? ctx.f8.f64 : f30.f64;
	// fmsubs f4,f28,f28,f7
	ctx.f4.f64 = double(float(f28.f64 * f28.f64 - ctx.f7.f64));
	// fsel f3,f6,f6,f30
	ctx.f3.f64 = ctx.f6.f64 >= 0.0 ? ctx.f6.f64 : f30.f64;
	// fsubs f2,f5,f31
	ctx.f2.f64 = double(float(ctx.f5.f64 - f31.f64));
	// fmuls f1,f4,f12
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f12.f64));
	// fsubs f0,f3,f31
	f0.f64 = double(float(ctx.f3.f64 - f31.f64));
	// fsel f13,f2,f31,f5
	ctx.f13.f64 = ctx.f2.f64 >= 0.0 ? f31.f64 : ctx.f5.f64;
	// fsel f12,f1,f1,f30
	ctx.f12.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f30.f64;
	// fsel f10,f0,f31,f3
	ctx.f10.f64 = f0.f64 >= 0.0 ? f31.f64 : ctx.f3.f64;
	// fsubs f9,f12,f31
	ctx.f9.f64 = double(float(ctx.f12.f64 - f31.f64));
	// fmuls f8,f10,f13
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fsel f7,f9,f31,f12
	ctx.f7.f64 = ctx.f9.f64 >= 0.0 ? f31.f64 : ctx.f12.f64;
	// fmuls f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f7.f64));
	// fmuls f0,f6,f11
	f0.f64 = double(float(ctx.f6.f64 * ctx.f11.f64));
	// fcmpu cr6,f0,f24
	cr6.compare(f0.f64, f24.f64);
	// blt cr6,0x82307380
	if (cr6.lt) goto loc_82307380;
	// lfs f10,700(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 700);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,0(r15)
	temp.u32 = PPC_LOAD_U32(r15.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f10,f30
	cr6.compare(ctx.f10.f64, f30.f64);
	// fmuls f9,f13,f22
	ctx.f9.f64 = double(float(ctx.f13.f64 * f22.f64));
	// bne cr6,0x823070b8
	if (!cr6.eq) goto loc_823070B8;
	// lfs f13,676(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 676);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// beq cr6,0x823070b4
	if (cr6.eq) goto loc_823070B4;
	// lwz r10,688(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 688);
	// lfs f12,672(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 672);
	ctx.f12.f64 = double(temp.f32);
	// lwz r11,692(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 692);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// std r8,168(r1)
	PPC_STORE_U64(ctx.r1.u32 + 168, ctx.r8.u64);
	// lfd f10,168(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 168);
	// std r9,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r9.u64);
	// lfd f11,144(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f7,f11
	ctx.f7.f64 = double(ctx.f11.s64);
	// fcfid f8,f10
	ctx.f8.f64 = double(ctx.f10.s64);
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// fmuls f3,f5,f13
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// fmuls f4,f6,f12
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f12.f64));
	// fdivs f10,f4,f3
	ctx.f10.f64 = double(float(ctx.f4.f64 / ctx.f3.f64));
	// b 0x823070b8
	goto loc_823070B8;
loc_823070B4:
	// fmr f10,f31
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = f31.f64;
loc_823070B8:
	// addi r10,r1,288
	ctx.r10.s64 = ctx.r1.s64 + 288;
	// lfs f13,112(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,116(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// lwz r9,152(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// lfs f11,120(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 120);
	ctx.f11.f64 = double(temp.f32);
	// lwz r8,156(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// stfs f13,288(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// lwz r7,188(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	// stfs f12,292(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// lwz r6,176(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// stfs f11,296(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// addi r5,r1,320
	ctx.r5.s64 = ctx.r1.s64 + 320;
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,21664(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 21664);
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,180(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// vor128 v0,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// lvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v13,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// lfs f8,80(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	ctx.f8.f64 = double(temp.f32);
	// stw r25,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, r25.u32);
	// lfs f7,84(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f7.f64 = double(temp.f32);
	// lwz r3,3276(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3276);
	// lfs f6,88(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	ctx.f6.f64 = double(temp.f32);
	// stfs f8,320(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// stfs f7,324(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// stfs f6,328(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v57,v63,135
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// lvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v11,v63,99
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// vsubfp128 v55,v56,v126
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v126.f32)));
	// lfs f13,4(r15)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r15.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f5,f10,f13
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// lfs f4,280(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 280);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f3,f31,f4
	ctx.f3.f64 = double(float(f31.f64 - ctx.f4.f64));
	// stfs f0,252(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// lfs f12,272(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 272);
	ctx.f12.f64 = double(temp.f32);
	// stw r3,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r3.u32);
	// lfs f11,276(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	ctx.f11.f64 = double(temp.f32);
	// lvlx128 v54,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// stfs f30,228(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f30,232(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f31,236(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stfs f31,240(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f3,224(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// fmuls f2,f5,f23
	ctx.f2.f64 = double(float(ctx.f5.f64 * f23.f64));
	// vmsum3fp128 v53,v55,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v53.f32, simde_mm_dp_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// fmuls f1,f3,f9
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f9.f64));
	// fmuls f0,f3,f2
	f0.f64 = double(float(ctx.f3.f64 * ctx.f2.f64));
	// fsubs f13,f12,f1
	ctx.f13.f64 = double(float(ctx.f12.f64 - ctx.f1.f64));
	// stfs f13,208(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// fadds f12,f1,f12
	ctx.f12.f64 = double(float(ctx.f1.f64 + ctx.f12.f64));
	// stfs f12,216(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// vrsqrtefp128 v52,v53
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v52.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v53.f32))));
	// vor128 v10,v53,v53
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v53.u8));
	// fsubs f10,f11,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// stfs f10,212(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// fadds f9,f0,f11
	ctx.f9.f64 = double(float(f0.f64 + ctx.f11.f64));
	// stfs f9,220(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// vcmpeqfp128 v9,v52,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v8,v52,v52
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// vsel v0,v8,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v7,v0,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v6,v61,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v5,v10,v7,v12
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v4,v5,v6,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v51,v55,v4
	simde_mm_store_ps(v51.f32, simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(ctx.v4.f32)));
	// vpermwi128 v50,v51,99
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0x9C));
	// vpermwi128 v49,v51,135
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0x78));
	// vmulfp128 v3,v57,v50
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v50.f32)));
	// vor128 v2,v49,v49
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v49.u8));
	// vor128 v1,v49,v49
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v49.u8));
	// vnmsubfp v31,v11,v2,v3
	simde_mm_store_ps(v31.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v3.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v48,v31,v31
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(v31.f32), 0xEF));
	// vrsqrtefp128 v47,v48
	simde_mm_store_ps(v47.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v48.f32))));
	// vor128 v30,v48,v48
	simde_mm_store_si128((simde__m128i*)v30.u8, simde_mm_load_si128((simde__m128i*)v48.u8));
	// vcmpeqfp128 v29,v47,v62
	simde_mm_store_ps(v29.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v28,v47,v47
	simde_mm_store_si128((simde__m128i*)v28.u8, simde_mm_load_si128((simde__m128i*)v47.u8));
	// vsel v0,v28,v13,v29
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v29.u8), simde_mm_load_si128((simde__m128i*)v28.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v29.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vmulfp128 v26,v0,v0
	simde_mm_store_ps(v26.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lwz r10,160(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// vmulfp128 v25,v61,v0
	simde_mm_store_ps(v25.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// li r9,32
	ctx.r9.s64 = 32;
	// vspltw128 v27,v54,0
	simde_mm_store_si128((simde__m128i*)v27.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// addi r6,r1,320
	ctx.r6.s64 = ctx.r1.s64 + 320;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lbz r7,60(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 60);
	// lvx128 v13,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lvx128 v24,r30,r9
	simde_mm_store_si128((simde__m128i*)v24.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v13,v24,v27,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v24.f32), simde_mm_load_ps(v27.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vnmsubfp v23,v30,v26,v12
	simde_mm_store_ps(v23.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v26.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v22,v23,v25,v0
	simde_mm_store_ps(v22.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v23.f32), simde_mm_load_ps(v25.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v46,v31,v22
	simde_mm_store_ps(v46.f32, simde_mm_mul_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(v22.f32)));
	// vpermwi128 v45,v46,135
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0x78));
	// vpermwi128 v21,v46,99
	simde_mm_store_si128((simde__m128i*)v21.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0x9C));
	// vmrghw128 v44,v46,v51
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrglw128 v43,v46,v51
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmulfp128 v20,v45,v50
	simde_mm_store_ps(v20.f32, simde_mm_mul_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v50.f32)));
	// vnmsubfp v19,v21,v1,v20
	simde_mm_store_ps(v19.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v21.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v20.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmrghw128 v42,v19,v127
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), simde_mm_load_si128((simde__m128i*)v19.u32)));
	// vmrglw128 v41,v19,v127
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), simde_mm_load_si128((simde__m128i*)v19.u32)));
	// vmrglw128 v63,v44,v42
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrghw128 v40,v44,v42
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrghw128 v39,v43,v41
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmrghw128 v38,v63,v127
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrglw128 v37,v63,v127
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrghw128 v36,v40,v39
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmrglw128 v35,v40,v39
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v34,v36,v38
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v36.u32)));
	// vmrghw128 v33,v35,v37
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vmrglw128 v32,v36,v38
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v36.u32)));
	// vmsum3fp128 v63,v13,v34
	simde_mm_store_ps(v63.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v34.f32), 0xEF));
	// vmsum3fp128 v62,v13,v33
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v33.f32), 0xEF));
	// vmsum3fp128 v61,v13,v32
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v32.f32), 0xEF));
	// vmrghw128 v60,v63,v62
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrghw128 v59,v61,v60
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v58,v60,v59
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x823072d4
	if (!cr6.eq) goto loc_823072D4;
	// lwz r10,184(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// lfs f13,48(r30)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,52(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 52);
	ctx.f12.f64 = double(temp.f32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f11,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f10.f64 = double(temp.f32);
	// stb r9,60(r30)
	PPC_STORE_U8(r30.u32 + 60, ctx.r9.u8);
	// lfs f0,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmadds f9,f0,f11,f13
	ctx.f9.f64 = double(float(f0.f64 * ctx.f11.f64 + ctx.f13.f64));
	// stfs f9,48(r30)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r30.u32 + 48, temp.u32);
	// fmadds f8,f0,f10,f12
	ctx.f8.f64 = double(float(f0.f64 * ctx.f10.f64 + ctx.f12.f64));
	// stfs f8,52(r30)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r30.u32 + 52, temp.u32);
loc_823072D4:
	// lfs f0,48(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 48);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x823072e8
	if (!cr6.gt) goto loc_823072E8;
	// fsubs f0,f0,f31
	f0.f64 = double(float(f0.f64 - f31.f64));
	// stfs f0,48(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 48, temp.u32);
loc_823072E8:
	// lfs f0,52(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 52);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x823072fc
	if (!cr6.gt) goto loc_823072FC;
	// fsubs f0,f0,f31
	f0.f64 = double(float(f0.f64 - f31.f64));
	// stfs f0,52(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 52, temp.u32);
loc_823072FC:
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r4,92(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lfs f0,52(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 52);
	f0.f64 = double(temp.f32);
	// lfs f13,48(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r11,448
	ctx.r6.s64 = r11.s64 + 448;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lfs f0,22228(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 22228);
	f0.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// lfs f13,22252(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 22252);
	ctx.f13.f64 = double(temp.f32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v57,r0,r5
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,128(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// lwz r5,1584(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1584);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82307358;
	sub_8218A6E0(ctx, base);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// lwz r3,21664(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 21664);
	// bl 0x822fa0f0
	ctx.lr = 0x82307364;
	sub_822FA0F0(ctx, base);
	// lwz r11,-17432(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -17432);
	// lfs f31,7444(r16)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r16.u32 + 7444);
	f31.f64 = double(temp.f32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,-17432(r27)
	PPC_STORE_U32(r27.u32 + -17432, r11.u32);
	// lfs f28,22264(r17)
	temp.u32 = PPC_LOAD_U32(r17.u32 + 22264);
	f28.f64 = double(temp.f32);
	// lwz r31,-26876(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -26876);
	// lfs f29,22256(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 22256);
	f29.f64 = double(temp.f32);
loc_82307380:
	// fadds f27,f29,f27
	ctx.fpscr.disableFlushMode();
	f27.f64 = double(float(f29.f64 + f27.f64));
	// stfs f27,192(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// fcmpu cr6,f27,f21
	cr6.compare(f27.f64, f21.f64);
	// blt cr6,0x82306f40
	if (cr6.lt) goto loc_82306F40;
loc_82307390:
	// fadds f26,f29,f26
	ctx.fpscr.disableFlushMode();
	f26.f64 = double(float(f29.f64 + f26.f64));
	// stfs f26,196(r1)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// fcmpu cr6,f26,f20
	cr6.compare(f26.f64, f20.f64);
	// blt cr6,0x82306f10
	if (cr6.lt) goto loc_82306F10;
loc_823073A0:
	// fadds f25,f29,f25
	ctx.fpscr.disableFlushMode();
	f25.f64 = double(float(f29.f64 + f25.f64));
	// stfs f25,200(r1)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// fcmpu cr6,f25,f17
	cr6.compare(f25.f64, f17.f64);
	// blt cr6,0x82306ee8
	if (cr6.lt) goto loc_82306EE8;
loc_823073B0:
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lwz r4,92(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r11,21664(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 21664);
	// stfs f30,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// addi r6,r11,448
	ctx.r6.s64 = r11.s64 + 448;
	// lfs f0,22228(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 22228);
	f0.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// lfs f13,22252(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 22252);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,22232(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 22232);
	f0.f64 = double(temp.f32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v56,r0,r3
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,1584(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 1584);
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8230740C;
	sub_8218A6E0(ctx, base);
	// lwz r3,-26876(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -26876);
	// lfs f0,700(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 700);
	f0.f64 = double(temp.f32);
	// lfs f4,708(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 708);
	ctx.f4.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// lfs f3,704(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 704);
	ctx.f3.f64 = double(temp.f32);
	// bne cr6,0x82307478
	if (!cr6.eq) goto loc_82307478;
	// lfs f0,676(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 676);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// beq cr6,0x82307474
	if (cr6.eq) goto loc_82307474;
	// lwz r11,688(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 688);
	// lfs f13,672(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 672);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,692(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 692);
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// std r9,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r9.u64);
	// std r8,168(r1)
	PPC_STORE_U64(ctx.r1.u32 + 168, ctx.r8.u64);
	// lfd f12,168(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 168);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lfd f10,144(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fcfid f8,f10
	ctx.f8.f64 = double(ctx.f10.s64);
	// fmuls f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 * f0.f64));
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// fmuls f5,f6,f13
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// fdivs f0,f5,f7
	f0.f64 = double(float(ctx.f5.f64 / ctx.f7.f64));
	// b 0x82307478
	goto loc_82307478;
loc_82307474:
	// lfs f0,7444(r16)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r16.u32 + 7444);
	f0.f64 = double(temp.f32);
loc_82307478:
	// fmr f2,f0
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f0.f64;
	// fmr f1,f16
	ctx.f1.f64 = f16.f64;
	// bl 0x8217d460
	ctx.lr = 0x82307484;
	sub_8217D460(ctx, base);
loc_82307484:
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// li r0,-336
	r0.s64 = -336;
	// lvx128 v125,r1,r0
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-320
	r0.s64 = -320;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-304
	r0.s64 = -304;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9f4
	ctx.lr = 0x823074A8;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_823074AC"))) PPC_WEAK_FUNC(sub_823074AC);
PPC_FUNC_IMPL(__imp__sub_823074AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823074B0"))) PPC_WEAK_FUNC(sub_823074B0);
PPC_FUNC_IMPL(__imp__sub_823074B0) {
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
	ctx.lr = 0x823074B8;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x822e7028
	ctx.lr = 0x823074C4;
	sub_822E7028(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r8,r10,10656
	ctx.r8.s64 = ctx.r10.s64 + 10656;
	// addi r11,r11,10640
	r11.s64 = r11.s64 + 10640;
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
	// stw r11,21672(r9)
	PPC_STORE_U32(ctx.r9.u32 + 21672, r11.u32);
	// bl 0x8260ff50
	ctx.lr = 0x823074E4;
	sub_8260FF50(ctx, base);
	// lis r31,-32112
	r31.s64 = -2104492032;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// addi r4,r7,10624
	ctx.r4.s64 = ctx.r7.s64 + 10624;
	// lwz r3,21664(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 21664);
	// bl 0x8260c8e0
	ctx.lr = 0x823074F8;
	sub_8260C8E0(ctx, base);
	// lwz r11,21664(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 21664);
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r6,356(r11)
	PPC_STORE_U8(r11.u32 + 356, ctx.r6.u8);
	// bl 0x82306a80
	ctx.lr = 0x82307508;
	sub_82306A80(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r29,r11,-7536
	r29.s64 = r11.s64 + -7536;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r5,-27856(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// beq cr6,0x82307534
	if (cr6.eq) goto loc_82307534;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,10588
	ctx.r4.s64 = ctx.r10.s64 + 10588;
	// b 0x8230753c
	goto loc_8230753C;
loc_82307534:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,10564
	ctx.r4.s64 = ctx.r10.s64 + 10564;
loc_8230753C:
	// bl 0x823dc018
	ctx.lr = 0x82307540;
	sub_823DC018(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,21664(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 21664);
	// bl 0x82610930
	ctx.lr = 0x8230754C;
	sub_82610930(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82307590
	if (!cr6.eq) goto loc_82307590;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,10480
	ctx.r3.s64 = r11.s64 + 10480;
	// bl 0x82130000
	ctx.lr = 0x82307568;
	sub_82130000(ctx, base);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r3,21664(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 21664);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82307584
	if (cr6.eq) goto loc_82307584;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r4,r11,10436
	ctx.r4.s64 = r11.s64 + 10436;
	// b 0x8230758c
	goto loc_8230758C;
loc_82307584:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r4,r11,10408
	ctx.r4.s64 = r11.s64 + 10408;
loc_8230758C:
	// bl 0x82610930
	ctx.lr = 0x82307590;
	sub_82610930(ctx, base);
loc_82307590:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lwz r11,21664(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 21664);
	// li r9,240
	ctx.r9.s64 = 240;
	// addi r8,r10,22352
	ctx.r8.s64 = ctx.r10.s64 + 22352;
	// li r7,2
	ctx.r7.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r7,316(r11)
	PPC_STORE_U32(r11.u32 + 316, ctx.r7.u32);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823075BC"))) PPC_WEAK_FUNC(sub_823075BC);
PPC_FUNC_IMPL(__imp__sub_823075BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823075C0"))) PPC_WEAK_FUNC(sub_823075C0);
PPC_FUNC_IMPL(__imp__sub_823075C0) {
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
	// lis r31,-32120
	r31.s64 = -2105016320;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,-1
	ctx.r5.s64 = -1;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// bl 0x822e5048
	ctx.lr = 0x823075E4;
	sub_822E5048(ctx, base);
	// lwz r11,-8092(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r3,21664(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 21664);
	// lwz r5,420(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 420);
	// lwz r4,416(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 416);
	// bl 0x8260d308
	ctx.lr = 0x823075FC;
	sub_8260D308(ctx, base);
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// bl 0x822e50b8
	ctx.lr = 0x82307604;
	sub_822E50B8(ctx, base);
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

__attribute__((alias("__imp__sub_82307618"))) PPC_WEAK_FUNC(sub_82307618);
PPC_FUNC_IMPL(__imp__sub_82307618) {
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
	// rlwinm r11,r4,0,4,4
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x8000000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823076cc
	if (!cr6.eq) goto loc_823076CC;
	// rlwinm r11,r4,0,3,3
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823076cc
	if (cr6.eq) goto loc_823076CC;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// bl 0x82130000
	ctx.lr = 0x82307654;
	sub_82130000(ctx, base);
	// lis r30,-32112
	r30.s64 = -2104492032;
	// lwz r3,21664(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// bl 0x8260faa0
	ctx.lr = 0x82307660;
	sub_8260FAA0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// bl 0x82130000
	ctx.lr = 0x8230766C;
	sub_82130000(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r10,-31280
	ctx.r4.s64 = ctx.r10.s64 + -31280;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x82307680;
	sub_8217C088(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,38
	ctx.r3.s64 = 38;
	// bl 0x8217f768
	ctx.lr = 0x8230768C;
	sub_8217F768(ctx, base);
	// bl 0x822fa550
	ctx.lr = 0x82307690;
	sub_822FA550(ctx, base);
	// bl 0x822fa698
	ctx.lr = 0x82307694;
	sub_822FA698(ctx, base);
	// bl 0x822fb058
	ctx.lr = 0x82307698;
	sub_822FB058(ctx, base);
	// lwz r3,21664(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// bl 0x8260efd0
	ctx.lr = 0x823076A0;
	sub_8260EFD0(ctx, base);
	// lwz r11,-8092(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// lbz r9,375(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 375);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x823076cc
	if (cr6.eq) goto loc_823076CC;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823076CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823076CC:
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

__attribute__((alias("__imp__sub_823076E4"))) PPC_WEAK_FUNC(sub_823076E4);
PPC_FUNC_IMPL(__imp__sub_823076E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823076E8"))) PPC_WEAK_FUNC(sub_823076E8);
PPC_FUNC_IMPL(__imp__sub_823076E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r11,21664(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 21664);
	// stb r4,340(r11)
	PPC_STORE_U8(r11.u32 + 340, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823076F8"))) PPC_WEAK_FUNC(sub_823076F8);
PPC_FUNC_IMPL(__imp__sub_823076F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// li r11,1
	r11.s64 = 1;
	// lfs f0,22416(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 22416);
	f0.f64 = double(temp.f32);
	// fsel f0,f1,f1,f0
	f0.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// stfs f0,22400(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 22400, temp.u32);
	// stb r11,22344(r8)
	PPC_STORE_U8(ctx.r8.u32 + 22344, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8230771C"))) PPC_WEAK_FUNC(sub_8230771C);
PPC_FUNC_IMPL(__imp__sub_8230771C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82307720"))) PPC_WEAK_FUNC(sub_82307720);
PPC_FUNC_IMPL(__imp__sub_82307720) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r9,r11,22416
	ctx.r9.s64 = r11.s64 + 22416;
	// addi r8,r10,22400
	ctx.r8.s64 = ctx.r10.s64 + 22400;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// li r11,1
	r11.s64 = 1;
	// lfs f0,4(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	f0.f64 = double(temp.f32);
	// fsel f0,f1,f1,f0
	f0.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// stfs f0,4(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 4, temp.u32);
	// stb r11,22344(r7)
	PPC_STORE_U8(ctx.r7.u32 + 22344, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8230774C"))) PPC_WEAK_FUNC(sub_8230774C);
PPC_FUNC_IMPL(__imp__sub_8230774C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82307750"))) PPC_WEAK_FUNC(sub_82307750);
PPC_FUNC_IMPL(__imp__sub_82307750) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// li r11,3
	r11.s64 = 3;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,-12288(r9)
	PPC_STORE_U32(ctx.r9.u32 + -12288, r11.u32);
	// stb r10,22344(r8)
	PPC_STORE_U8(ctx.r8.u32 + 22344, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8230776C"))) PPC_WEAK_FUNC(sub_8230776C);
PPC_FUNC_IMPL(__imp__sub_8230776C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82307770"))) PPC_WEAK_FUNC(sub_82307770);
PPC_FUNC_IMPL(__imp__sub_82307770) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r9,r11,22352
	ctx.r9.s64 = r11.s64 + 22352;
	// li r11,1
	r11.s64 = 1;
	// stb r11,22344(r10)
	PPC_STORE_U8(ctx.r10.u32 + 22344, r11.u8);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82307790"))) PPC_WEAK_FUNC(sub_82307790);
PPC_FUNC_IMPL(__imp__sub_82307790) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r9,r11,22432
	ctx.r9.s64 = r11.s64 + 22432;
	// li r11,1
	r11.s64 = 1;
	// stb r11,22344(r10)
	PPC_STORE_U8(ctx.r10.u32 + 22344, r11.u8);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823077B0"))) PPC_WEAK_FUNC(sub_823077B0);
PPC_FUNC_IMPL(__imp__sub_823077B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// li r11,1
	r11.s64 = 1;
	// stfs f1,22340(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 22340, temp.u32);
	// stb r11,22344(r9)
	PPC_STORE_U8(ctx.r9.u32 + 22344, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823077C8"))) PPC_WEAK_FUNC(sub_823077C8);
PPC_FUNC_IMPL(__imp__sub_823077C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// li r11,2
	r11.s64 = 2;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,-12288(r9)
	PPC_STORE_U32(ctx.r9.u32 + -12288, r11.u32);
	// stb r10,22344(r8)
	PPC_STORE_U8(ctx.r8.u32 + 22344, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823077E4"))) PPC_WEAK_FUNC(sub_823077E4);
PPC_FUNC_IMPL(__imp__sub_823077E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823077E8"))) PPC_WEAK_FUNC(sub_823077E8);
PPC_FUNC_IMPL(__imp__sub_823077E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// li r11,1
	r11.s64 = 1;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,-12288(r9)
	PPC_STORE_U32(ctx.r9.u32 + -12288, r11.u32);
	// stb r10,22344(r8)
	PPC_STORE_U8(ctx.r8.u32 + 22344, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82307804"))) PPC_WEAK_FUNC(sub_82307804);
PPC_FUNC_IMPL(__imp__sub_82307804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82307808"))) PPC_WEAK_FUNC(sub_82307808);
PPC_FUNC_IMPL(__imp__sub_82307808) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r7,r11,22368
	ctx.r7.s64 = r11.s64 + 22368;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r3,r9,22352
	ctx.r3.s64 = ctx.r9.s64 + 22352;
	// addi r6,r10,22416
	ctx.r6.s64 = ctx.r10.s64 + 22416;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r8,22400
	ctx.r9.s64 = ctx.r8.s64 + 22400;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32119
	ctx.r4.s64 = -2104950784;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,0
	r11.s64 = 0;
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f0,17032(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 17032);
	f0.f64 = double(temp.f32);
	// stw r11,-12288(r4)
	PPC_STORE_U32(ctx.r4.u32 + -12288, r11.u32);
	// stfs f0,22340(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 22340, temp.u32);
	// stb r10,22344(r7)
	PPC_STORE_U8(ctx.r7.u32 + 22344, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82307864"))) PPC_WEAK_FUNC(sub_82307864);
PPC_FUNC_IMPL(__imp__sub_82307864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82307868"))) PPC_WEAK_FUNC(sub_82307868);
PPC_FUNC_IMPL(__imp__sub_82307868) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,10656
	ctx.r9.s64 = r11.s64 + 10656;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r3,21664(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 21664);
	// bl 0x8260f460
	ctx.lr = 0x8230789C;
	sub_8260F460(ctx, base);
	// bl 0x8260f020
	ctx.lr = 0x823078A0;
	sub_8260F020(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822e7018
	ctx.lr = 0x823078A8;
	sub_822E7018(ctx, base);
	// clrlwi r8,r30,31
	ctx.r8.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x823078c0
	if (cr6.eq) goto loc_823078C0;
	// bl 0x82130588
	ctx.lr = 0x823078BC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_823078C0:
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

__attribute__((alias("__imp__sub_823078D8"))) PPC_WEAK_FUNC(sub_823078D8);
PPC_FUNC_IMPL(__imp__sub_823078D8) {
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
	// bl 0x823d91fc
	ctx.lr = 0x823078E0;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r11,r4,0,4,4
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x8000000;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82307b90
	if (cr6.eq) goto loc_82307B90;
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lis r10,10240
	ctx.r10.s64 = 671088640;
	// lwz r11,-8092(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -8092);
	// lwz r9,364(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 364);
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// beq cr6,0x82307b90
	if (cr6.eq) goto loc_82307B90;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-18004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// lwz r3,28(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82307924
	if (cr6.eq) goto loc_82307924;
	// bl 0x82313f38
	ctx.lr = 0x82307924;
	sub_82313F38(ctx, base);
loc_82307924:
	// lis r29,-32119
	r29.s64 = -2104950784;
	// lwz r11,-12288(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -12288);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82307a4c
	if (!cr6.eq) goto loc_82307A4C;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x82307940;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82307a48
	if (cr6.eq) goto loc_82307A48;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82307954;
	sub_822A39C8(ctx, base);
	// lwz r11,880(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82307a48
	if (cr6.eq) goto loc_82307A48;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82307968;
	sub_822A39C8(ctx, base);
	// lwz r10,880(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r11,80(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// addi r9,r11,11
	ctx.r9.s64 = r11.s64 + 11;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x82307a48
	if (cr6.eq) goto loc_82307A48;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8230798C;
	sub_822A39C8(ctx, base);
	// lwz r10,880(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r11,80(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// addi r9,r11,11
	ctx.r9.s64 = r11.s64 + 11;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lwz r6,144(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 144);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x82307a48
	if (cr6.eq) goto loc_82307A48;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r11,22384
	ctx.r9.s64 = r11.s64 + 22384;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a39c8
	ctx.lr = 0x823079C8;
	sub_822A39C8(ctx, base);
	// lwz r8,880(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lwz r10,-8092(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -8092);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lwz r9,80(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 80);
	// lwz r11,22080(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 22080);
	// addi r6,r9,11
	ctx.r6.s64 = ctx.r9.s64 + 11;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,240
	ctx.r10.s64 = r11.s64 + 240;
	// lwzx r4,r5,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// lfs f12,244(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 244);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,248(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 248);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,240(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 240);
	ctx.f10.f64 = double(temp.f32);
	// lwz r11,144(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 144);
	// lfs f9,52(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 52);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f12,f9
	ctx.f8.f64 = double(float(ctx.f12.f64 - ctx.f9.f64));
	// lfs f7,56(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 56);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f11,f7
	ctx.f6.f64 = double(float(ctx.f11.f64 - ctx.f7.f64));
	// lfs f5,48(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f10,f5
	ctx.f4.f64 = double(float(ctx.f10.f64 - ctx.f5.f64));
	// fmuls f3,f8,f8
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fmadds f2,f6,f6,f3
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f3.f64));
	// fmadds f1,f4,f4,f2
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f2.f64));
	// fsqrts f12,f1
	ctx.f12.f64 = double(float(sqrt(ctx.f1.f64)));
	// fadds f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 + ctx.f12.f64));
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fadds f10,f13,f12
	ctx.f10.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// b 0x82307a88
	goto loc_82307A88;
loc_82307A48:
	// lwz r11,-12288(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -12288);
loc_82307A4C:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82307a60
	if (!cr6.eq) goto loc_82307A60;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r9,r11,22400
	ctx.r9.s64 = r11.s64 + 22400;
	// b 0x82307a7c
	goto loc_82307A7C;
loc_82307A60:
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82307a74
	if (!cr6.eq) goto loc_82307A74;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r9,r11,22432
	ctx.r9.s64 = r11.s64 + 22432;
	// b 0x82307a7c
	goto loc_82307A7C;
loc_82307A74:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r9,r11,22352
	ctx.r9.s64 = r11.s64 + 22352;
loc_82307A7C:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82307A88:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f1,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lfs f0,10668(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 10668);
	f0.f64 = double(temp.f32);
	// addi r6,r8,-29952
	ctx.r6.s64 = ctx.r8.s64 + -29952;
	// lfs f13,22340(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 22340);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// addi r31,r7,22464
	r31.s64 = ctx.r7.s64 + 22464;
	// lis r3,-32131
	ctx.r3.s64 = -2105737216;
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// lvx128 v13,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r3,29952
	r11.s64 = ctx.r3.s64 + 29952;
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r4,22480
	r30.s64 = ctx.r4.s64 + 22480;
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lfs f31,8(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f31.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// fsel f11,f12,f0,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v60,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vrefp128 v0,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v59.f32)));
	// vor128 v12,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vnmsubfp v10,v0,v12,v13
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v9,v0,v10,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v63,v61,v9
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v9.f32)));
	// vxor128 v58,v63,v63
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_setzero_si128());
	// vsubfp128 v57,v58,v63
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v63.f32)));
	// vmaxfp128 v63,v63,v57
	simde_mm_store_ps(v63.f32, simde_mm_max_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,22480(r4)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 22480);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x821ce490
	ctx.lr = 0x82307B20;
	sub_821CE490(ctx, base);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// lfs f2,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f1.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// bl 0x821ce490
	ctx.lr = 0x82307B34;
	sub_821CE490(ctx, base);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// lfs f2,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f1,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821ce490
	ctx.lr = 0x82307B48;
	sub_821CE490(ctx, base);
	// lis r30,-32112
	r30.s64 = -2104492032;
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,240
	ctx.r10.s64 = 240;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// stvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-7572(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x82307B68;
	sub_82205248(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// stb r5,122(r11)
	PPC_STORE_U8(r11.u32 + 122, ctx.r5.u8);
	// lwz r3,21664(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// bl 0x8260d8c8
	ctx.lr = 0x82307B88;
	sub_8260D8C8(ctx, base);
	// lwz r3,21664(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// bl 0x8260ebb8
	ctx.lr = 0x82307B90;
	sub_8260EBB8(ctx, base);
loc_82307B90:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82307B9C"))) PPC_WEAK_FUNC(sub_82307B9C);
PPC_FUNC_IMPL(__imp__sub_82307B9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82307BA0"))) PPC_WEAK_FUNC(sub_82307BA0);
PPC_FUNC_IMPL(__imp__sub_82307BA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// li r11,1
	r11.s64 = 1;
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,22416(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 22416);
	f0.f64 = double(temp.f32);
	// stb r11,22344(r8)
	PPC_STORE_U8(ctx.r8.u32 + 22344, r11.u8);
	// fsel f0,f13,f13,f0
	f0.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// stfs f0,22400(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 22400, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82307BCC"))) PPC_WEAK_FUNC(sub_82307BCC);
PPC_FUNC_IMPL(__imp__sub_82307BCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82307BD0"))) PPC_WEAK_FUNC(sub_82307BD0);
PPC_FUNC_IMPL(__imp__sub_82307BD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r8,r11,22416
	ctx.r8.s64 = r11.s64 + 22416;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// addi r6,r9,22400
	ctx.r6.s64 = ctx.r9.s64 + 22400;
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f0,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	f0.f64 = double(temp.f32);
	// fsel f0,f13,f13,f0
	f0.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// stb r11,22344(r7)
	PPC_STORE_U8(ctx.r7.u32 + 22344, r11.u8);
	// stfs f0,4(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82307C04"))) PPC_WEAK_FUNC(sub_82307C04);
PPC_FUNC_IMPL(__imp__sub_82307C04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82307C08"))) PPC_WEAK_FUNC(sub_82307C08);
PPC_FUNC_IMPL(__imp__sub_82307C08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// li r11,1
	r11.s64 = 1;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,22340(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 22340, temp.u32);
	// stb r11,22344(r8)
	PPC_STORE_U8(ctx.r8.u32 + 22344, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82307C28"))) PPC_WEAK_FUNC(sub_82307C28);
PPC_FUNC_IMPL(__imp__sub_82307C28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// lwz r11,21664(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 21664);
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,400
	r11.s64 = r11.s64 + 400;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,-8(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stfs f13,-4(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82307C64"))) PPC_WEAK_FUNC(sub_82307C64);
PPC_FUNC_IMPL(__imp__sub_82307C64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82307C68"))) PPC_WEAK_FUNC(sub_82307C68);
PPC_FUNC_IMPL(__imp__sub_82307C68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,21664(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 21664);
	// lfs f0,408(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 408);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82307C80"))) PPC_WEAK_FUNC(sub_82307C80);
PPC_FUNC_IMPL(__imp__sub_82307C80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,21664(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 21664);
	// lfs f0,412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 412);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82307C98"))) PPC_WEAK_FUNC(sub_82307C98);
PPC_FUNC_IMPL(__imp__sub_82307C98) {
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
	// lis r11,-32208
	r11.s64 = -2110783488;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,31648
	ctx.r4.s64 = r11.s64 + 31648;
	// addi r3,r10,10920
	ctx.r3.s64 = ctx.r10.s64 + 10920;
	// bl 0x82554798
	ctx.lr = 0x82307CB8;
	sub_82554798(ctx, base);
	// lis r9,-32208
	ctx.r9.s64 = -2110783488;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,31696
	ctx.r4.s64 = ctx.r9.s64 + 31696;
	// addi r3,r8,10884
	ctx.r3.s64 = ctx.r8.s64 + 10884;
	// bl 0x82554798
	ctx.lr = 0x82307CCC;
	sub_82554798(ctx, base);
	// lis r7,-32208
	ctx.r7.s64 = -2110783488;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,30664
	ctx.r4.s64 = ctx.r7.s64 + 30664;
	// addi r3,r6,10852
	ctx.r3.s64 = ctx.r6.s64 + 10852;
	// bl 0x82554798
	ctx.lr = 0x82307CE0;
	sub_82554798(ctx, base);
	// lis r5,-32208
	ctx.r5.s64 = -2110783488;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,30696
	ctx.r4.s64 = ctx.r5.s64 + 30696;
	// addi r3,r3,10824
	ctx.r3.s64 = ctx.r3.s64 + 10824;
	// bl 0x82554798
	ctx.lr = 0x82307CF4;
	sub_82554798(ctx, base);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,30728
	ctx.r4.s64 = r11.s64 + 30728;
	// addi r3,r10,10796
	ctx.r3.s64 = ctx.r10.s64 + 10796;
	// bl 0x82554798
	ctx.lr = 0x82307D08;
	sub_82554798(ctx, base);
	// lis r9,-32208
	ctx.r9.s64 = -2110783488;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,31752
	ctx.r4.s64 = ctx.r9.s64 + 31752;
	// addi r3,r8,10760
	ctx.r3.s64 = ctx.r8.s64 + 10760;
	// bl 0x82554798
	ctx.lr = 0x82307D1C;
	sub_82554798(ctx, base);
	// lis r7,-32208
	ctx.r7.s64 = -2110783488;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,31784
	ctx.r4.s64 = ctx.r7.s64 + 31784;
	// addi r3,r6,10728
	ctx.r3.s64 = ctx.r6.s64 + 10728;
	// bl 0x82554798
	ctx.lr = 0x82307D30;
	sub_82554798(ctx, base);
	// lis r5,-32208
	ctx.r5.s64 = -2110783488;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,31848
	ctx.r4.s64 = ctx.r5.s64 + 31848;
	// addi r3,r3,10700
	ctx.r3.s64 = ctx.r3.s64 + 10700;
	// bl 0x82554798
	ctx.lr = 0x82307D44;
	sub_82554798(ctx, base);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,31872
	ctx.r4.s64 = r11.s64 + 31872;
	// addi r3,r10,10672
	ctx.r3.s64 = ctx.r10.s64 + 10672;
	// bl 0x82554798
	ctx.lr = 0x82307D58;
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

__attribute__((alias("__imp__sub_82307D68"))) PPC_WEAK_FUNC(sub_82307D68);
PPC_FUNC_IMPL(__imp__sub_82307D68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// li r9,960
	ctx.r9.s64 = 960;
	// li r8,57
	ctx.r8.s64 = 57;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r7,256
	ctx.r7.s64 = 256;
	// lfs f0,32668(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32668);
	f0.f64 = double(temp.f32);
	// li r6,51
	ctx.r6.s64 = 51;
	// stfs f31,16(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stb r30,33(r31)
	PPC_STORE_U8(r31.u32 + 33, r30.u8);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// li r3,992
	ctx.r3.s64 = 992;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// stw r6,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r6.u32);
	// stb r30,32(r31)
	PPC_STORE_U8(r31.u32 + 32, r30.u8);
	// bl 0x82130528
	ctx.lr = 0x82307DD0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82307de0
	if (cr6.eq) goto loc_82307DE0;
	// bl 0x8217d5e8
	ctx.lr = 0x82307DDC;
	sub_8217D5E8(ctx, base);
	// b 0x82307de4
	goto loc_82307DE4;
loc_82307DE0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82307DE4:
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f2,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x8217d120
	ctx.lr = 0x82307E08;
	sub_8217D120(ctx, base);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// lfs f1,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f4,32312(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32312);
	ctx.f4.f64 = double(temp.f32);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// lfs f3,17032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	ctx.f3.f64 = double(temp.f32);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fdivs f2,f10,f9
	ctx.f2.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// bl 0x8217d460
	ctx.lr = 0x82307E58;
	sub_8217D460(ctx, base);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// stfs f31,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// addi r11,r31,128
	r11.s64 = r31.s64 + 128;
	// addi r10,r4,-31280
	ctx.r10.s64 = ctx.r4.s64 + -31280;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r7,32
	ctx.r7.s64 = 32;
	// li r6,32
	ctx.r6.s64 = 32;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,48
	ctx.r5.s64 = 48;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,48
	ctx.r4.s64 = 48;
	// lvx128 v63,r10,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,-1
	ctx.r9.s64 = -1;
	// stvx128 v63,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v63,r10,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r10,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r9,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_82307ECC"))) PPC_WEAK_FUNC(sub_82307ECC);
PPC_FUNC_IMPL(__imp__sub_82307ECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82307ED0"))) PPC_WEAK_FUNC(sub_82307ED0);
PPC_FUNC_IMPL(__imp__sub_82307ED0) {
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
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x82307EE4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82307f08
	if (cr6.eq) goto loc_82307F08;
	// bl 0x82307d68
	ctx.lr = 0x82307EF0;
	sub_82307D68(ctx, base);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// stw r3,-12284(r11)
	PPC_STORE_U32(r11.u32 + -12284, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82307F08:
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-12284(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12284, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82307F24"))) PPC_WEAK_FUNC(sub_82307F24);
PPC_FUNC_IMPL(__imp__sub_82307F24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82307F28"))) PPC_WEAK_FUNC(sub_82307F28);
PPC_FUNC_IMPL(__imp__sub_82307F28) {
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
	PPCRegister f31{};
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
	// bl 0x823d91e4
	ctx.lr = 0x82307F30;
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// lbz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82308168
	if (cr6.eq) goto loc_82308168;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r25,0
	r25.s64 = 0;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r8,-1
	ctx.r8.s64 = -65536;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r25,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r25.u32);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r7,1
	ctx.r7.s64 = 1;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// stb r10,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, ctx.r10.u8);
	// bl 0x82178c40
	ctx.lr = 0x82307F90;
	sub_82178C40(ctx, base);
	// lis r29,-32124
	r29.s64 = -2105278464;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r30,r11,22532
	r30.s64 = r11.s64 + 22532;
	// li r26,16
	r26.s64 = 16;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// li r27,32
	r27.s64 = 32;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// lbz r5,4(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// li r28,48
	r28.s64 = 48;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// lwz r11,-26876(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -26876);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r26
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r27
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r28
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82308064
	if (cr6.eq) goto loc_82308064;
	// lis r24,-32121
	r24.s64 = -2105081856;
	// lwz r3,17268(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x82307FF8;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82308064
	if (cr6.eq) goto loc_82308064;
	// lwz r3,17268(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8230800C;
	sub_822A39C8(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x82308010;
	sub_822A8108(ctx, base);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lvx128 v59,r0,r3
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// stfs f31,112(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,116(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// lvx128 v58,r3,r26
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r3,r27
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r3,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r8
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v55,v63,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v56.f32)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82308064:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r7,12(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r30,r1,128
	r30.s64 = ctx.r1.s64 + 128;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r24,r1,128
	r24.s64 = ctx.r1.s64 + 128;
	// lvlx128 v52,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lis r23,-32256
	r23.s64 = -2113929216;
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lvlx128 v54,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v53,v54,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// vspltw128 v51,v52,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0xFF));
	// lvx128 v50,r0,r8
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r0,r30
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v48,v50,v53
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v48.f32, simde_mm_mul_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v53.f32)));
	// lfs f2,7444(r23)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 7444);
	ctx.f2.f64 = double(temp.f32);
	// vmulfp128 v47,v49,v51
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v47.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v51.f32)));
	// stvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r0,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217d120
	ctx.lr = 0x823080D8;
	sub_8217D120(ctx, base);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f1,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// lwz r11,-26876(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -26876);
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// std r8,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r8.u64);
	// lfs f4,708(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 708);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,704(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 704);
	ctx.f3.f64 = double(temp.f32);
	// lfd f0,112(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// std r7,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r7.u64);
	// lfd f13,112(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fdivs f2,f10,f9
	ctx.f2.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// bl 0x8217d460
	ctx.lr = 0x82308124;
	sub_8217D460(ctx, base);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x8217ce80
	ctx.lr = 0x82308130;
	sub_8217CE80(ctx, base);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stw r25,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r25.u32);
	// addi r11,r31,128
	r11.s64 = r31.s64 + 128;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lvx128 v46,r0,r6
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r0,r5
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r0,r4
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r0,r3
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82308168:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82308174"))) PPC_WEAK_FUNC(sub_82308174);
PPC_FUNC_IMPL(__imp__sub_82308174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82308178"))) PPC_WEAK_FUNC(sub_82308178);
PPC_FUNC_IMPL(__imp__sub_82308178) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// lbz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82308280
	if (cr6.eq) goto loc_82308280;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r6,12(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r30,1
	r30.s64 = 1;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r8,-256
	ctx.r8.s64 = -16777216;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// stb r30,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, r30.u8);
	// bl 0x82178c40
	ctx.lr = 0x823081E0;
	sub_82178C40(ctx, base);
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lwz r11,-7572(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// addi r3,r11,32
	ctx.r3.s64 = r11.s64 + 32;
	// bl 0x821800a0
	ctx.lr = 0x823081F0;
	sub_821800A0(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r3,-7572(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// lfs f1,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822f3918
	ctx.lr = 0x82308200;
	sub_822F3918(ctx, base);
	// lis r6,-32124
	ctx.r6.s64 = -2105278464;
	// addi r11,r31,64
	r11.s64 = r31.s64 + 64;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// lwz r10,-26876(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + -26876);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r10,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r10.u32);
	// lwz r10,-26876(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + -26876);
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r10,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r10,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r10,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x8217c658
	ctx.lr = 0x82308250;
	sub_8217C658(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82311450
	ctx.lr = 0x8230825C;
	sub_82311450(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x82308268;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8217f768
	ctx.lr = 0x82308274;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x82308280;
	sub_8217F768(ctx, base);
loc_82308280:
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

__attribute__((alias("__imp__sub_82308298"))) PPC_WEAK_FUNC(sub_82308298);
PPC_FUNC_IMPL(__imp__sub_82308298) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// stb r4,32(r10)
	PPC_STORE_U8(ctx.r10.u32 + 32, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823082AC"))) PPC_WEAK_FUNC(sub_823082AC);
PPC_FUNC_IMPL(__imp__sub_823082AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823082B0"))) PPC_WEAK_FUNC(sub_823082B0);
PPC_FUNC_IMPL(__imp__sub_823082B0) {
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
	ctx.lr = 0x823082B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// lbz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8230834c
	if (cr6.eq) goto loc_8230834C;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r29,-32124
	r29.s64 = -2105278464;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r10,-31280
	ctx.r4.s64 = ctx.r10.s64 + -31280;
	// lwz r11,3528(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 3528);
	// lwz r3,-26876(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -26876);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r31,r11,16
	r31.s64 = r11.s64 + 16;
	// bl 0x8217c088
	ctx.lr = 0x823082FC;
	sub_8217C088(ctx, base);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82308310;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82494258
	ctx.lr = 0x82308320;
	sub_82494258(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82311450
	ctx.lr = 0x8230832C;
	sub_82311450(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,48(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// bl 0x8217c658
	ctx.lr = 0x82308338;
	sub_8217C658(ctx, base);
	// addi r4,r30,64
	ctx.r4.s64 = r30.s64 + 64;
	// lwz r3,-26876(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -26876);
	// bl 0x8217ce80
	ctx.lr = 0x82308344;
	sub_8217CE80(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r7,48(r30)
	PPC_STORE_U32(r30.u32 + 48, ctx.r7.u32);
loc_8230834C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82308354"))) PPC_WEAK_FUNC(sub_82308354);
PPC_FUNC_IMPL(__imp__sub_82308354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82308358"))) PPC_WEAK_FUNC(sub_82308358);
PPC_FUNC_IMPL(__imp__sub_82308358) {
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
	ctx.lr = 0x82308360;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32119
	r29.s64 = -2104950784;
	// lwz r31,-12284(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -12284);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82308398
	if (cr6.eq) goto loc_82308398;
	// lwz r30,44(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82308390
	if (cr6.eq) goto loc_82308390;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217cb48
	ctx.lr = 0x82308388;
	sub_8217CB48(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82308390;
	sub_82130588(ctx, base);
loc_82308390:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82308398;
	sub_82130588(ctx, base);
loc_82308398:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-12284(r29)
	PPC_STORE_U32(r29.u32 + -12284, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823083A8"))) PPC_WEAK_FUNC(sub_823083A8);
PPC_FUNC_IMPL(__imp__sub_823083A8) {
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
	// li r3,992
	ctx.r3.s64 = 992;
	// bl 0x82130528
	ctx.lr = 0x823083C4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823083d4
	if (cr6.eq) goto loc_823083D4;
	// bl 0x8217d5e8
	ctx.lr = 0x823083D0;
	sub_8217D5E8(ctx, base);
	// b 0x823083d8
	goto loc_823083D8;
loc_823083D4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823083D8:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// bl 0x8217d098
	ctx.lr = 0x823083E0;
	sub_8217D098(ctx, base);
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

__attribute__((alias("__imp__sub_823083F8"))) PPC_WEAK_FUNC(sub_823083F8);
PPC_FUNC_IMPL(__imp__sub_823083F8) {
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
	PPCRegister f0{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82308400;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823db9c0
	ctx.lr = 0x82308408;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// fmr f29,f3
	f29.f64 = ctx.f3.f64;
	// li r27,1
	r27.s64 = 1;
	// fmr f28,f4
	f28.f64 = ctx.f4.f64;
	// fmr f22,f5
	f22.f64 = ctx.f5.f64;
	// lwz r26,-26876(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// fmr f26,f6
	f26.f64 = ctx.f6.f64;
	// fmr f25,f7
	f25.f64 = ctx.f7.f64;
	// fmr f24,f8
	f24.f64 = ctx.f8.f64;
	// fmr f23,f9
	f23.f64 = ctx.f9.f64;
	// bl 0x821789d8
	ctx.lr = 0x82308444;
	sub_821789D8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8230845c
	if (cr6.eq) goto loc_8230845C;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17004);
	// b 0x82308464
	goto loc_82308464;
loc_8230845C:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17012);
loc_82308464:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f27,f13
	f27.f64 = double(float(ctx.f13.f64));
	// bl 0x821789d8
	ctx.lr = 0x8230847C;
	sub_821789D8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82308494
	if (cr6.eq) goto loc_82308494;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17008);
	// b 0x8230849c
	goto loc_8230849C;
loc_82308494:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17016);
loc_8230849C:
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmr f2,f27
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f27.f64;
	// std r9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lfd f0,96(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f5,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f5.f64 = double(temp.f32);
	// frsp f3,f13
	ctx.f3.f64 = double(float(ctx.f13.f64));
	// lfs f6,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f6.f64 = double(temp.f32);
	// fmr f4,f5
	ctx.f4.f64 = ctx.f5.f64;
	// fmr f1,f5
	ctx.f1.f64 = ctx.f5.f64;
	// bl 0x8217cc80
	ctx.lr = 0x823084D4;
	sub_8217CC80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8217c658
	ctx.lr = 0x823084E0;
	sub_8217C658(ctx, base);
	// lbz r6,351(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 351);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82308504
	if (cr6.eq) goto loc_82308504;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fsubs f31,f31,f0
	f31.f64 = double(float(f31.f64 - f0.f64));
	// fsubs f30,f30,f0
	f30.f64 = double(float(f30.f64 - f0.f64));
	// fsubs f29,f29,f0
	f29.f64 = double(float(f29.f64 - f0.f64));
	// fsubs f28,f28,f0
	f28.f64 = double(float(f28.f64 - f0.f64));
loc_82308504:
	// lwz r28,356(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 356);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8230852c
	if (cr6.eq) goto loc_8230852C;
	// lwz r11,364(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 364);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82187f40
	ctx.lr = 0x82308528;
	sub_82187F40(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_8230852C:
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x823085d4
	if (!cr6.gt) goto loc_823085D4;
	// lwz r31,0(r13)
	r31.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r30,8
	r30.s64 = 8;
	// fneg f27,f22
	ctx.fpscr.disableFlushMode();
	f27.u64 = f22.u64 ^ 0x8000000000000000;
loc_82308544:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82308558
	if (cr6.eq) goto loc_82308558;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82187b88
	ctx.lr = 0x82308558;
	sub_82187B88(ctx, base);
loc_82308558:
	// lwzx r11,r30,r31
	r11.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82308574
	if (!cr6.eq) goto loc_82308574;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8218f118
	ctx.lr = 0x82308574;
	sub_8218F118(ctx, base);
loc_82308574:
	// addi r11,r1,340
	r11.s64 = ctx.r1.s64 + 340;
	// fmr f9,f23
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = f23.f64;
	// fmr f8,f24
	ctx.f8.f64 = f24.f64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// fmr f7,f25
	ctx.f7.f64 = f25.f64;
	// fmr f6,f26
	ctx.f6.f64 = f26.f64;
	// fmr f5,f27
	ctx.f5.f64 = f27.f64;
	// fmr f4,f28
	ctx.f4.f64 = f28.f64;
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8218f138
	ctx.lr = 0x823085A4;
	sub_8218F138(ctx, base);
	// lwzx r10,r30,r31
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stwx r11,r30,r31
	PPC_STORE_U32(r30.u32 + r31.u32, r11.u32);
	// bne 0x823085b8
	if (!cr0.eq) goto loc_823085B8;
	// bl 0x8218f130
	ctx.lr = 0x823085B8;
	sub_8218F130(ctx, base);
loc_823085B8:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x823085c8
	if (cr6.eq) goto loc_823085C8;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82187ba8
	ctx.lr = 0x823085C8;
	sub_82187BA8(ctx, base);
loc_823085C8:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// blt cr6,0x82308544
	if (cr6.lt) goto loc_82308544;
loc_823085D4:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x823085e4
	if (cr6.eq) goto loc_823085E4;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82187bd0
	ctx.lr = 0x823085E4;
	sub_82187BD0(ctx, base);
loc_823085E4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8217c658
	ctx.lr = 0x823085F0;
	sub_8217C658(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba0c
	ctx.lr = 0x823085FC;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82308600"))) PPC_WEAK_FUNC(sub_82308600);
PPC_FUNC_IMPL(__imp__sub_82308600) {
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
	// lwz r31,0(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8230862c
	if (cr6.eq) goto loc_8230862C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217cb48
	ctx.lr = 0x82308624;
	sub_8217CB48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x8230862C;
	sub_82130588(ctx, base);
loc_8230862C:
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

__attribute__((alias("__imp__sub_82308640"))) PPC_WEAK_FUNC(sub_82308640);
PPC_FUNC_IMPL(__imp__sub_82308640) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x82308648;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r28,r11,30576
	r28.s64 = r11.s64 + 30576;
	// addi r4,r10,-3680
	ctx.r4.s64 = ctx.r10.s64 + -3680;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ca540
	ctx.lr = 0x82308664;
	sub_821CA540(ctx, base);
	// li r24,0
	r24.s64 = 0;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// mr r31,r24
	r31.u64 = r24.u64;
	// lis r23,-32124
	r23.s64 = -2105278464;
	// addi r30,r11,22548
	r30.s64 = r11.s64 + 22548;
	// addi r29,r10,-12276
	r29.s64 = ctx.r10.s64 + -12276;
loc_82308680:
	// lwz r3,-25232(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -25232);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwzx r4,r31,r30
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8230869C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stwx r3,r31,r29
	PPC_STORE_U32(r31.u32 + r29.u32, ctx.r3.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpwi cr6,r31,8
	cr6.compare<int32_t>(r31.s32, 8, xer);
	// blt cr6,0x82308680
	if (cr6.lt) goto loc_82308680;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9a90
	ctx.lr = 0x823086B4;
	sub_821C9A90(ctx, base);
	// lis r29,-32119
	r29.s64 = -2104950784;
	// lis r28,-32119
	r28.s64 = -2104950784;
	// li r11,256
	r11.s64 = 256;
	// li r10,256
	ctx.r10.s64 = 256;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,-12212(r29)
	PPC_STORE_U32(r29.u32 + -12212, r11.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r10,-12208(r28)
	PPC_STORE_U32(r28.u32 + -12208, ctx.r10.u32);
	// bl 0x82180430
	ctx.lr = 0x823086D8;
	sub_82180430(ctx, base);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r24,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r24.u32);
	// addi r27,r11,-12268
	r27.s64 = r11.s64 + -12268;
	// li r11,2
	r11.s64 = 2;
	// stb r10,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, ctx.r10.u8);
	// stb r10,114(r1)
	PPC_STORE_U8(ctx.r1.u32 + 114, ctx.r10.u8);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r11,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r11.u32);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r31,r27
	r31.u64 = r27.u64;
	// mr r30,r24
	r30.u64 = r24.u64;
	// addi r26,r11,-12236
	r26.s64 = r11.s64 + -12236;
	// addi r25,r10,11892
	r25.s64 = ctx.r10.s64 + 11892;
loc_82308710:
	// lwz r3,-25232(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -25232);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r7,-12208(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + -12208);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lwz r6,-12212(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + -12212);
	// li r8,32
	ctx.r8.s64 = 32;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8230873C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stbx r24,r30,r26
	PPC_STORE_U8(r30.u32 + r26.u32, r24.u8);
	// addi r9,r27,32
	ctx.r9.s64 = r27.s64 + 32;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// blt cr6,0x82308710
	if (cr6.lt) goto loc_82308710;
	// li r3,992
	ctx.r3.s64 = 992;
	// bl 0x82130528
	ctx.lr = 0x82308760;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82308770
	if (cr6.eq) goto loc_82308770;
	// bl 0x8217d5e8
	ctx.lr = 0x8230876C;
	sub_8217D5E8(ctx, base);
	// b 0x82308774
	goto loc_82308774;
loc_82308770:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_82308774:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r7,-12208(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + -12208);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r6,-12212(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + -12212);
	// addi r11,r11,-12216
	r11.s64 = r11.s64 + -12216;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f2,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x8217d120
	ctx.lr = 0x823087A4;
	sub_8217D120(ctx, base);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r31,r8,11876
	r31.s64 = ctx.r8.s64 + 11876;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-24728(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -24728);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x823087D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r30,-32119
	r30.s64 = -2104950784;
	// stw r24,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r24.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r3,-12220(r30)
	PPC_STORE_U32(r30.u32 + -12220, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82308808;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-12220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12220);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,11864
	ctx.r4.s64 = ctx.r10.s64 + 11864;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x82308820;
	sub_8218B688(ctx, base);
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lwz r11,-12220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12220);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,11848
	ctx.r4.s64 = ctx.r8.s64 + 11848;
	// stw r3,-12224(r9)
	PPC_STORE_U32(ctx.r9.u32 + -12224, ctx.r3.u32);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82308840;
	sub_8218A568(ctx, base);
	// lis r7,-32119
	ctx.r7.s64 = -2104950784;
	// stw r3,-12228(r7)
	PPC_STORE_U32(ctx.r7.u32 + -12228, ctx.r3.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82308850"))) PPC_WEAK_FUNC(sub_82308850);
PPC_FUNC_IMPL(__imp__sub_82308850) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82308864
	if (!cr6.eq) goto loc_82308864;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82308864:
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,-12268
	ctx.r8.s64 = ctx.r10.s64 + -12268;
	// lwzx r3,r9,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82308878"))) PPC_WEAK_FUNC(sub_82308878);
PPC_FUNC_IMPL(__imp__sub_82308878) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,1
	r11.s64 = 1;
	// stb r11,2149(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2149, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82308884"))) PPC_WEAK_FUNC(sub_82308884);
PPC_FUNC_IMPL(__imp__sub_82308884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82308888"))) PPC_WEAK_FUNC(sub_82308888);
PPC_FUNC_IMPL(__imp__sub_82308888) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,2150(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2150, r11.u8);
	// stb r10,2154(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2154, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8230889C"))) PPC_WEAK_FUNC(sub_8230889C);
PPC_FUNC_IMPL(__imp__sub_8230889C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823088A0"))) PPC_WEAK_FUNC(sub_823088A0);
PPC_FUNC_IMPL(__imp__sub_823088A0) {
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
	PPCRegister f0{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x823088A8;
	// stfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f29.u64);
	// stfd f30,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, f30.u64);
	// stfd f31,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82308c6c
	if (cr6.eq) goto loc_82308C6C;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217f768
	ctx.lr = 0x823088D4;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x823088E0;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x823088EC;
	sub_8217F768(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r29,-32124
	r29.s64 = -2105278464;
	// addi r23,r11,-31280
	r23.s64 = r11.s64 + -31280;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r3,-26876(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x82308904;
	sub_8217C088(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8217f768
	ctx.lr = 0x82308910;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x8230891C;
	sub_8217F768(ctx, base);
	// li r4,15
	ctx.r4.s64 = 15;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8217f768
	ctx.lr = 0x82308928;
	sub_8217F768(ctx, base);
	// lwz r10,-26876(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -26876);
	// addi r11,r31,2080
	r11.s64 = r31.s64 + 2080;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// stw r10,2144(r31)
	PPC_STORE_U32(r31.u32 + 2144, ctx.r10.u32);
	// lis r30,-32119
	r30.s64 = -2104950784;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,-26876(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -26876);
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r10,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r10,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r10,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-12216(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// bl 0x8217c658
	ctx.lr = 0x82308978;
	sub_8217C658(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,-12216(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f31,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lfs f29,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f29.f64 = double(temp.f32);
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// lfs f30,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f30.f64 = double(temp.f32);
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// fmr f5,f30
	ctx.f5.f64 = f30.f64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x8217cc80
	ctx.lr = 0x823089B0;
	sub_8217CC80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12216(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// bl 0x8217c658
	ctx.lr = 0x823089BC;
	sub_8217C658(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x823089d4
	if (!cr6.eq) goto loc_823089D4;
	// mr r24,r30
	r24.u64 = r30.u64;
	// b 0x823089e4
	goto loc_823089E4;
loc_823089D4:
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,-12268
	ctx.r8.s64 = ctx.r10.s64 + -12268;
	// lwzx r24,r9,r8
	r24.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
loc_823089E4:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82308A18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82178370
	ctx.lr = 0x82308A34;
	sub_82178370(ctx, base);
	// lbz r10,2150(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 2150);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82308ad8
	if (!cr6.eq) goto loc_82308AD8;
	// lbz r11,2149(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2149);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82308ad8
	if (!cr6.eq) goto loc_82308AD8;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8217d9a0
	ctx.lr = 0x82308A54;
	sub_8217D9A0(ctx, base);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// stw r30,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r30.u32);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// lis r7,-32119
	ctx.r7.s64 = -2104950784;
	// fmr f9,f31
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = f31.f64;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// li r6,1
	ctx.r6.s64 = 1;
	// fmr f7,f30
	ctx.f7.f64 = f30.f64;
	// stw r8,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r8.u32);
	// fmr f6,f30
	ctx.f6.f64 = f30.f64;
	// stb r6,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, ctx.r6.u8);
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// lwz r3,-12280(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12280);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// lwz r10,-12208(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12208);
	// lwz r11,-12212(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12212);
	// extsw r5,r10
	ctx.r5.s64 = ctx.r10.s32;
	// extsw r4,r11
	ctx.r4.s64 = r11.s32;
	// std r5,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r5.u64);
	// lfd f0,136(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// std r4,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r4.u64);
	// lfd f12,136(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f4,f13
	ctx.f4.f64 = double(float(ctx.f13.f64));
	// frsp f3,f11
	ctx.f3.f64 = double(float(ctx.f11.f64));
	// bl 0x823083f8
	ctx.lr = 0x82308AD4;
	sub_823083F8(ctx, base);
	// b 0x82308c00
	goto loc_82308C00;
loc_82308AD8:
	// lbz r11,2149(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2149);
	// li r25,1
	r25.s64 = 1;
	// lis r28,-32119
	r28.s64 = -2104950784;
	// lis r27,-32119
	r27.s64 = -2104950784;
	// lis r26,-32119
	r26.s64 = -2104950784;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82308b78
	if (cr6.eq) goto loc_82308B78;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8217d9a0
	ctx.lr = 0x82308AFC;
	sub_8217D9A0(ctx, base);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// li r11,-1
	r11.s64 = -1;
	// stw r30,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r30.u32);
	// stw r10,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
	// fmr f9,f31
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = f31.f64;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// lwz r3,-12280(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12280);
	// fmr f7,f30
	ctx.f7.f64 = f30.f64;
	// fmr f6,f30
	ctx.f6.f64 = f30.f64;
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// stb r25,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r25.u8);
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lwz r10,-12212(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + -12212);
	// lwz r11,-12208(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -12208);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// extsw r8,r11
	ctx.r8.s64 = r11.s32;
	// std r9,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r9.u64);
	// lfd f0,136(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// std r8,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r8.u64);
	// lfd f12,136(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f3,f13
	ctx.f3.f64 = double(float(ctx.f13.f64));
	// frsp f4,f11
	ctx.f4.f64 = double(float(ctx.f11.f64));
	// bl 0x823083f8
	ctx.lr = 0x82308B6C;
	sub_823083F8(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8217f768
	ctx.lr = 0x82308B78;
	sub_8217F768(ctx, base);
loc_82308B78:
	// lwz r3,2032(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2032);
	// bl 0x8217d9a0
	ctx.lr = 0x82308B80;
	sub_8217D9A0(ctx, base);
	// lis r11,-256
	r11.s64 = -16777216;
	// lwz r10,-12208(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + -12208);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stb r25,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r25.u8);
	// ori r11,r11,65280
	r11.u64 = r11.u64 | 65280;
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// stw r9,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// fmr f9,f31
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = f31.f64;
	// stw r30,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r30.u32);
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// std r8,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r8.u64);
	// lfd f0,136(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lwz r3,-12280(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12280);
	// lwz r11,-12212(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -12212);
	// fmr f7,f30
	ctx.f7.f64 = f30.f64;
	// fmr f6,f30
	ctx.f6.f64 = f30.f64;
	// extsw r7,r11
	ctx.r7.s64 = r11.s32;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// std r7,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r7.u64);
	// lfd f12,136(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// frsp f3,f11
	ctx.f3.f64 = double(float(ctx.f11.f64));
	// frsp f4,f13
	ctx.f4.f64 = double(float(ctx.f13.f64));
	// bl 0x823083f8
	ctx.lr = 0x82308BF4;
	sub_823083F8(ctx, base);
	// li r4,15
	ctx.r4.s64 = 15;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8217f768
	ctx.lr = 0x82308C00;
	sub_8217F768(ctx, base);
loc_82308C00:
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f29,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// li r11,16
	r11.s64 = 16;
	// stb r30,2149(r31)
	PPC_STORE_U8(r31.u32 + 2149, r30.u8);
	// stb r30,2150(r31)
	PPC_STORE_U8(r31.u32 + 2150, r30.u8);
	// li r10,48
	ctx.r10.s64 = 48;
	// lwz r3,-26876(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -26876);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r0,r23
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v59,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r6,32
	ctx.r6.s64 = 32;
	// lvx128 v63,r23,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lvx128 v61,r23,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v58,v59,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// lvx128 v62,r23,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// stvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v57,v63,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v58.f32)));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217ce80
	ctx.lr = 0x82308C6C;
	sub_8217CE80(ctx, base);
loc_82308C6C:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// lfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f30,-96(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82308C80"))) PPC_WEAK_FUNC(sub_82308C80);
PPC_FUNC_IMPL(__imp__sub_82308C80) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,80(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82308d20
	if (cr6.eq) goto loc_82308D20;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r31,0
	r31.s64 = 0;
	// li r11,1
	r11.s64 = 1;
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,-25232(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -25232);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stb r31,102(r1)
	PPC_STORE_U8(ctx.r1.u32 + 102, r31.u8);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stb r11,103(r1)
	PPC_STORE_U8(ctx.r1.u32 + 103, r11.u8);
	// stb r11,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, r11.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, r11.u8);
	// stb r11,101(r1)
	PPC_STORE_U8(ctx.r1.u32 + 101, r11.u8);
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82308D00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,2144(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 2144);
	// bl 0x8217c658
	ctx.lr = 0x82308D0C;
	sub_8217C658(ctx, base);
	// lis r6,-32124
	ctx.r6.s64 = -2105278464;
	// addi r4,r30,2080
	ctx.r4.s64 = r30.s64 + 2080;
	// lwz r3,-26876(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -26876);
	// bl 0x8217ce80
	ctx.lr = 0x82308D1C;
	sub_8217CE80(ctx, base);
	// stw r31,2144(r30)
	PPC_STORE_U32(r30.u32 + 2144, r31.u32);
loc_82308D20:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
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

__attribute__((alias("__imp__sub_82308D38"))) PPC_WEAK_FUNC(sub_82308D38);
PPC_FUNC_IMPL(__imp__sub_82308D38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82308D40;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823db9d4
	ctx.lr = 0x82308D48;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lbz r11,2153(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2153);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82308f04
	if (cr6.eq) goto loc_82308F04;
	// lwz r11,80(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82308f04
	if (cr6.eq) goto loc_82308F04;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217f768
	ctx.lr = 0x82308D74;
	sub_8217F768(ctx, base);
	// li r4,15
	ctx.r4.s64 = 15;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8217f768
	ctx.lr = 0x82308D80;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x82308D8C;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8217f768
	ctx.lr = 0x82308D98;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x82308DA4;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x82308DB0;
	sub_8217F768(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r3,-25360(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25360);
	// bl 0x8217d9a0
	ctx.lr = 0x82308DBC;
	sub_8217D9A0(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r4,r9,-31280
	ctx.r4.s64 = ctx.r9.s64 + -31280;
	// lwz r3,-26876(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x82308DD0;
	sub_8217C088(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e20
	ctx.lr = 0x82308DDC;
	sub_82189E20(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e20
	ctx.lr = 0x82308DE8;
	sub_82189E20(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x82189e20
	ctx.lr = 0x82308DF4;
	sub_82189E20(ctx, base);
	// lwz r11,80(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82308e0c
	if (!cr6.eq) goto loc_82308E0C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x82308e1c
	goto loc_82308E1C;
loc_82308E0C:
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,-12268
	ctx.r8.s64 = ctx.r10.s64 + -12268;
	// lwzx r3,r9,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
loc_82308E1C:
	// bl 0x8217d9a0
	ctx.lr = 0x82308E20;
	sub_8217D9A0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r31,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r31.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r31.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lfs f30,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f30.f64 = double(temp.f32);
	// lis r28,-32119
	r28.s64 = -2104950784;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r29,-1
	r29.s64 = -1;
	// lfs f29,11908(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11908);
	f29.f64 = double(temp.f32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lfs f28,11904(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11904);
	f28.f64 = double(temp.f32);
	// mr r11,r29
	r11.u64 = r29.u64;
	// lfs f27,27636(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 27636);
	f27.f64 = double(temp.f32);
	// li r30,1
	r30.s64 = 1;
	// lfs f1,-1540(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -1540);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,-12280(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12280);
	// fmr f9,f30
	ctx.f9.f64 = f30.f64;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// stw r5,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r5.u32);
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// stb r30,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r30.u8);
	// fmr f8,f30
	ctx.f8.f64 = f30.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f29
	ctx.f4.f64 = f29.f64;
	// fmr f3,f28
	ctx.f3.f64 = f28.f64;
	// fmr f2,f27
	ctx.f2.f64 = f27.f64;
	// bl 0x823083f8
	ctx.lr = 0x82308EA0;
	sub_823083F8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x8217fd68
	ctx.lr = 0x82308EAC;
	sub_8217FD68(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217fe58
	ctx.lr = 0x82308EB8;
	sub_8217FE58(ctx, base);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// mr r11,r29
	r11.u64 = r29.u64;
	// lwz r3,-12280(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12280);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// fmr f9,f30
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = f30.f64;
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// stw r31,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r31.u32);
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// lfs f3,11900(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 11900);
	ctx.f3.f64 = double(temp.f32);
	// fmr f8,f30
	ctx.f8.f64 = f30.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// stw r10,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
	// fmr f4,f29
	ctx.f4.f64 = f29.f64;
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r31.u32);
	// stb r30,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r30.u8);
	// fmr f2,f27
	ctx.f2.f64 = f27.f64;
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// bl 0x823083f8
	ctx.lr = 0x82308F04;
	sub_823083F8(ctx, base);
loc_82308F04:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba20
	ctx.lr = 0x82308F10;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82308F14"))) PPC_WEAK_FUNC(sub_82308F14);
PPC_FUNC_IMPL(__imp__sub_82308F14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82308F18"))) PPC_WEAK_FUNC(sub_82308F18);
PPC_FUNC_IMPL(__imp__sub_82308F18) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v25{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x82308F20;
	// stfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f29.u64);
	// stfd f30,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, f30.u64);
	// stfd f31,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// li r12,-160
	r12.s64 = -160;
	// stvx128 v125,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-144
	r12.s64 = -144;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-128
	r12.s64 = -128;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f0,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f13,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// addi r7,r9,2528
	ctx.r7.s64 = ctx.r9.s64 + 2528;
	// fmr f29,f1
	f29.f64 = ctx.f1.f64;
	// lfs f0,-15876(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -15876);
	f0.f64 = double(temp.f32);
	// addi r6,r8,2240
	ctx.r6.s64 = ctx.r8.s64 + 2240;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v61,v127,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v127.f32), 0xEF));
	// vrsqrtefp128 v60,v61
	simde_mm_store_ps(v60.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v61.f32))));
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// vor128 v0,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// addi r3,r5,-31648
	ctx.r3.s64 = ctx.r5.s64 + -31648;
	// vor128 v12,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// addi r11,r4,-31664
	r11.s64 = ctx.r4.s64 + -31664;
	// vor128 v11,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r29,-32119
	r29.s64 = -2104950784;
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f30,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f30.f64 = double(temp.f32);
	// vcmpeqfp128 v10,v60,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v9,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// stfs f31,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r3,-12220(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12220);
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f30,104(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v59,v61,135
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x78));
	// vsel v0,v9,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vpermwi128 v8,v61,99
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x9C));
	// vmulfp128 v7,v0,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v6,v63,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v5,v12,v7,v13
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v4,v5,v6,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v126,v127,v4
	simde_mm_store_ps(v126.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(ctx.v4.f32)));
	// vpermwi128 v58,v126,99
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v126.u32), 0x9C));
	// vpermwi128 v3,v126,135
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v126.u32), 0x78));
	// vmulfp128 v2,v59,v58
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v58.f32)));
	// vnmsubfp v1,v8,v3,v2
	simde_mm_store_ps(ctx.v1.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v2.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v57,v1,v1
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v1.f32), 0xEF));
	// vrsqrtefp128 v56,v57
	simde_mm_store_ps(v56.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v57.f32))));
	// vor128 v31,v57,v57
	simde_mm_store_si128((simde__m128i*)v31.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// vcmpeqfp128 v30,v56,v62
	simde_mm_store_ps(v30.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v29,v56,v56
	simde_mm_store_si128((simde__m128i*)v29.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vsel v0,v29,v11,v30
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v30.u8), simde_mm_load_si128((simde__m128i*)v29.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vmulfp128 v28,v0,v0
	simde_mm_store_ps(v28.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v27,v63,v0
	simde_mm_store_ps(v27.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v26,v31,v28,v13
	simde_mm_store_ps(v26.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(v28.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v25,v26,v27,v0
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v26.f32), simde_mm_load_ps(v27.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v125,v1,v25
	simde_mm_store_ps(v125.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(v25.f32)));
	// bl 0x82187b88
	ctx.lr = 0x82309050;
	sub_82187B88(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x8217bb68
	ctx.lr = 0x8230905C;
	sub_8217BB68(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r28,-32124
	r28.s64 = -2105278464;
	// lis r27,-32124
	r27.s64 = -2105278464;
	// lis r6,-1
	ctx.r6.s64 = -65536;
	// lfs f0,15360(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 15360);
	f0.f64 = double(temp.f32);
	// fmuls f12,f29,f0
	ctx.f12.f64 = double(float(f29.f64 * f0.f64));
	// stfs f31,-26916(r28)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + -26916, temp.u32);
	// stfs f31,-26924(r27)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r27.u32 + -26924, temp.u32);
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f11.u64);
	// lwz r5,100(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// clrlwi r4,r5,24
	ctx.r4.u64 = ctx.r5.u32 & 0xFF;
	// rlwimi r6,r4,8,16,23
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0xFF00) | (ctx.r6.u64 & 0xFFFFFFFFFFFF00FF);
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// lis r26,-32124
	r26.s64 = -2105278464;
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// or r3,r6,r4
	ctx.r3.u64 = ctx.r6.u64 | ctx.r4.u64;
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// rlwinm r11,r3,8,0,23
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 8) & 0xFFFFFF00;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// or r9,r11,r4
	ctx.r9.u64 = r11.u64 | ctx.r4.u64;
	// lis r25,-32124
	r25.s64 = -2105278464;
	// stw r9,-26892(r26)
	PPC_STORE_U32(r26.u32 + -26892, ctx.r9.u32);
	// lvlx128 v55,r0,r30
	temp.u32 = r30.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v54,r0,r31
	temp.u32 = r31.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v53,v54,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// vmulfp128 v52,v125,v53
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v53.f32)));
	// vspltw128 v51,v55,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// lis r24,-32124
	r24.s64 = -2105278464;
	// lfs f6,-26896(r25)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lis r23,-32124
	r23.s64 = -2105278464;
	// vmulfp128 v50,v126,v51
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v50.f32, simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v51.f32)));
	// lfs f5,-26908(r24)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r24.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// vsubfp128 v49,v127,v52
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v49.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v52.f32)));
	// vsubfp128 v48,v49,v50
	simde_mm_store_ps(v48.f32, simde_mm_sub_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v50.f32)));
	// stvx128 v48,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x82309100;
	sub_8217BC28(ctx, base);
	// stfs f31,-26916(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + -26916, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f30,-26924(r27)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r27.u32 + -26924, temp.u32);
	// lwz r9,-26892(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + -26892);
	// lvlx128 v47,r0,r30
	temp.u32 = r30.u32;
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fmr f8,f30
	ctx.f8.f64 = f30.f64;
	// lvlx128 v46,r0,r31
	temp.u32 = r31.u32;
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v45,v46,0
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0xFF));
	// vmulfp128 v44,v125,v45
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v44.f32, simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v45.f32)));
	// vspltw128 v43,v47,0
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0xFF));
	// lfs f6,-26896(r25)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// lfs f5,-26908(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// vsubfp128 v42,v127,v44
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v42.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v44.f32)));
	// vmaddfp128 v42,v126,v43,v42
	simde_mm_store_ps(v42.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v43.f32)), simde_mm_load_ps(v42.f32)));
	// stvx128 v42,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// lfs f3,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x82309154;
	sub_8217BC28(ctx, base);
	// stfs f30,-26916(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r28.u32 + -26916, temp.u32);
	// vor128 v41,v127,v127
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// stfs f31,-26924(r27)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r27.u32 + -26924, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvlx128 v39,r0,r30
	temp.u32 = r30.u32;
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lwz r9,-26892(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + -26892);
	// lvlx128 v40,r0,r31
	temp.u32 = r31.u32;
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v37,v40,0
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), 0xFF));
	// vspltw128 v38,v39,0
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), 0xFF));
	// vmaddfp128 v41,v125,v37,v41
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v41.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v37.f32)), simde_mm_load_ps(v41.f32)));
	// lfs f6,-26896(r25)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// lfs f5,-26908(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f7,f30
	ctx.f7.f64 = f30.f64;
	// lfs f4,-26928(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// vmulfp128 v36,v126,v38
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v36.f32, simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v38.f32)));
	// vsubfp128 v35,v41,v36
	simde_mm_store_ps(v35.f32, simde_mm_sub_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v36.f32)));
	// stvx128 v35,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x823091AC;
	sub_8217BC28(ctx, base);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r9,-26892(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + -26892);
	// lfs f6,-26896(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f8,f30
	ctx.f8.f64 = f30.f64;
	// lfs f5,-26908(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f7,f30
	ctx.f7.f64 = f30.f64;
	// lfs f4,-26928(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// stfs f30,-26916(r28)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r28.u32 + -26916, temp.u32);
	// stfs f30,-26924(r27)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r27.u32 + -26924, temp.u32);
	// lvlx128 v33,r0,r31
	temp.u32 = r31.u32;
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v32,v33,0
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), 0xFF));
	// lvlx128 v34,r0,r30
	temp.u32 = r30.u32;
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v34,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0xFF));
	// vmaddfp128 v127,v125,v32,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v32.f32)), simde_mm_load_ps(v127.f32)));
	// vmaddfp128 v127,v126,v63,v127
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v63.f32)), simde_mm_load_ps(v127.f32)));
	// stvx128 v127,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// lfs f3,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f3.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x823091FC;
	sub_8217BC28(ctx, base);
	// bl 0x8217bc98
	ctx.lr = 0x82309200;
	sub_8217BC98(ctx, base);
	// lwz r3,-12220(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12220);
	// bl 0x82187ba8
	ctx.lr = 0x82309208;
	sub_82187BA8(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// li r0,-160
	r0.s64 = -160;
	// lvx128 v125,r1,r0
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-144
	r0.s64 = -144;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f30,-96(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82309234"))) PPC_WEAK_FUNC(sub_82309234);
PPC_FUNC_IMPL(__imp__sub_82309234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82309238"))) PPC_WEAK_FUNC(sub_82309238);
PPC_FUNC_IMPL(__imp__sub_82309238) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82309240;
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,2151(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2151);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823092b0
	if (!cr6.eq) goto loc_823092B0;
	// lbz r11,2152(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823092b0
	if (!cr6.eq) goto loc_823092B0;
	// lbz r11,2153(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2153);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823092b0
	if (!cr6.eq) goto loc_823092B0;
	// lbz r11,2150(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2150);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823092b0
	if (!cr6.eq) goto loc_823092B0;
	// lbz r11,2149(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2149);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823092b0
	if (!cr6.eq) goto loc_823092B0;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82309598
	if (cr6.eq) goto loc_82309598;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x823092b0
	if (!cr6.eq) goto loc_823092B0;
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82309598
	if (cr6.eq) goto loc_82309598;
loc_823092B0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823088a0
	ctx.lr = 0x823092B8;
	sub_823088A0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217f768
	ctx.lr = 0x823092C4;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x823092D0;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x823092DC;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217fd68
	ctx.lr = 0x823092E8;
	sub_8217FD68(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217fe58
	ctx.lr = 0x823092F4;
	sub_8217FE58(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r10,-31280
	ctx.r4.s64 = ctx.r10.s64 + -31280;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x82309308;
	sub_8217C088(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8217f768
	ctx.lr = 0x82309314;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x82309320;
	sub_8217F768(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lbz r7,2151(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 2151);
	// li r30,1
	r30.s64 = 1;
	// li r29,0
	r29.s64 = 0;
	// li r25,-1
	r25.s64 = -1;
	// lfs f30,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f30.f64 = double(temp.f32);
	// lis r28,-32119
	r28.s64 = -2104950784;
	// lfs f31,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r27,-32119
	r27.s64 = -2104950784;
	// lis r26,-32119
	r26.s64 = -2104950784;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x823093dc
	if (cr6.eq) goto loc_823093DC;
	// stb r30,2154(r31)
	PPC_STORE_U8(r31.u32 + 2154, r30.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217d9a0
	ctx.lr = 0x82309360;
	sub_8217D9A0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8217f768
	ctx.lr = 0x8230936C;
	sub_8217F768(ctx, base);
	// mr r11,r25
	r11.u64 = r25.u64;
	// lwz r10,-12208(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + -12208);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// fmr f9,f30
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = f30.f64;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// lwz r3,-12280(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12280);
	// stw r29,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r29.u32);
	// fmr f8,f30
	ctx.f8.f64 = f30.f64;
	// std r8,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r8.u64);
	// lfd f0,136(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// stw r9,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// lwz r11,-12212(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -12212);
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r29.u32);
	// extsw r7,r11
	ctx.r7.s64 = r11.s32;
	// stb r30,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r30.u8);
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// std r7,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r7.u64);
	// lfd f12,136(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// frsp f3,f11
	ctx.f3.f64 = double(float(ctx.f11.f64));
	// frsp f4,f13
	ctx.f4.f64 = double(float(ctx.f13.f64));
	// bl 0x823083f8
	ctx.lr = 0x823093DC;
	sub_823083F8(ctx, base);
loc_823093DC:
	// lbz r11,2152(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82309470
	if (cr6.eq) goto loc_82309470;
	// stb r30,2154(r31)
	PPC_STORE_U8(r31.u32 + 2154, r30.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217d9a0
	ctx.lr = 0x823093F4;
	sub_8217D9A0(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8217f768
	ctx.lr = 0x82309400;
	sub_8217F768(ctx, base);
	// mr r11,r25
	r11.u64 = r25.u64;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lwz r10,-12212(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + -12212);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// fmr f9,f30
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = f30.f64;
	// stw r29,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r29.u32);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// stw r9,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// fmr f8,f30
	ctx.f8.f64 = f30.f64;
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r29.u32);
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// std r8,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r8.u64);
	// lfd f0,136(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lwz r3,-12280(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12280);
	// lwz r11,-12208(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -12208);
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// stb r30,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r30.u8);
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// extsw r7,r11
	ctx.r7.s64 = r11.s32;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// std r7,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r7.u64);
	// lfd f12,136(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f4,f11
	ctx.f4.f64 = double(float(ctx.f11.f64));
	// frsp f3,f13
	ctx.f3.f64 = double(float(ctx.f13.f64));
	// bl 0x823083f8
	ctx.lr = 0x82309470;
	sub_823083F8(ctx, base);
loc_82309470:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82309598
	if (cr6.eq) goto loc_82309598;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r25,-32119
	r25.s64 = -2104950784;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,-12224(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -12224);
	// lwz r3,-12220(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -12220);
	// bl 0x82187f40
	ctx.lr = 0x82309498;
	sub_82187F40(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82309584
	if (cr6.eq) goto loc_82309584;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8217f768
	ctx.lr = 0x823094AC;
	sub_8217F768(ctx, base);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r26,-32119
	r26.s64 = -2104950784;
	// addi r27,r11,-12276
	r27.s64 = r11.s64 + -12276;
	// lwz r5,-12228(r26)
	ctx.r5.u64 = PPC_LOAD_U32(r26.u32 + -12228);
	// lwz r6,4(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lwz r11,-12220(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -12220);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x823094D0;
	sub_82189CE0(ctx, base);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// mr r28,r29
	r28.u64 = r29.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82309510
	if (!cr6.gt) goto loc_82309510;
	// addi r30,r31,160
	r30.s64 = r31.s64 + 160;
loc_823094E4:
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f1,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r30,-16
	ctx.r4.s64 = r30.s64 + -16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82308f18
	ctx.lr = 0x823094FC;
	sub_82308F18(ctx, base);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,96
	r30.s64 = r30.s64 + 96;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x823094e4
	if (cr6.lt) goto loc_823094E4;
loc_82309510:
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8217f768
	ctx.lr = 0x8230951C;
	sub_8217F768(ctx, base);
	// lwz r11,-12220(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -12220);
	// lwz r6,0(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,-12228(r26)
	ctx.r5.u64 = PPC_LOAD_U32(r26.u32 + -12228);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x82309534;
	sub_82189CE0(ctx, base);
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// mr r28,r29
	r28.u64 = r29.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82309574
	if (!cr6.gt) goto loc_82309574;
	// addi r30,r31,928
	r30.s64 = r31.s64 + 928;
loc_82309548:
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f1,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r30,-16
	ctx.r4.s64 = r30.s64 + -16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82308f18
	ctx.lr = 0x82309560;
	sub_82308F18(ctx, base);
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,96
	r30.s64 = r30.s64 + 96;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x82309548
	if (cr6.lt) goto loc_82309548;
loc_82309574:
	// stw r29,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r29.u32);
	// stw r29,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r29.u32);
	// lwz r3,-12220(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -12220);
	// bl 0x82187bd0
	ctx.lr = 0x82309584;
	sub_82187BD0(ctx, base);
loc_82309584:
	// li r4,15
	ctx.r4.s64 = 15;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8217f768
	ctx.lr = 0x82309590;
	sub_8217F768(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82308c80
	ctx.lr = 0x82309598;
	sub_82308C80(ctx, base);
loc_82309598:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_823095A8"))) PPC_WEAK_FUNC(sub_823095A8);
PPC_FUNC_IMPL(__imp__sub_823095A8) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x823095B0;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stw r3,20(r1)
	PPC_STORE_U32(ctx.r1.u32 + 20, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r11,r11,-31280
	r11.s64 = r11.s64 + -31280;
	// addi r10,r3,96
	ctx.r10.s64 = ctx.r3.s64 + 96;
	// addi r8,r9,11844
	ctx.r8.s64 = ctx.r9.s64 + 11844;
	// stw r11,-304(r1)
	PPC_STORE_U32(ctx.r1.u32 + -304, r11.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r10,-300(r1)
	PPC_STORE_U32(ctx.r1.u32 + -300, ctx.r10.u32);
	// li r6,16
	ctx.r6.s64 = 16;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,32
	ctx.r5.s64 = 32;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,32
	ctx.r9.s64 = 32;
	// lvx128 v63,r11,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,48
	ctx.r8.s64 = 48;
	// stvx128 v63,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r6,48
	ctx.r6.s64 = 48;
	// lvx128 v63,r11,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,0
	ctx.r9.s64 = 0;
	// lvx128 v63,r11,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,96
	ctx.r5.s64 = 96;
	// stvx128 v63,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,16
	ctx.r8.s64 = 16;
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r7,112
	ctx.r7.s64 = 112;
	// stfs f0,160(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 160, temp.u32);
	// li r6,32
	ctx.r6.s64 = 32;
	// stfs f0,164(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 164, temp.u32);
	// li r31,128
	r31.s64 = 128;
	// stfs f0,168(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 168, temp.u32);
	// stw r9,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, ctx.r9.u32);
	// stfs f0,180(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 180, temp.u32);
	// li r30,48
	r30.s64 = 48;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,144
	r29.s64 = 144;
	// stvx128 v63,r10,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,208
	ctx.r5.s64 = 208;
	// lvx128 v63,r11,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,224
	ctx.r8.s64 = 224;
	// stvx128 v63,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,240
	ctx.r7.s64 = 240;
	// lvx128 v63,r11,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,288
	ctx.r6.s64 = 288;
	// stvx128 v63,r10,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r31,304
	r31.s64 = 304;
	// lvx128 v63,r11,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r30,320
	r30.s64 = 320;
	// stvx128 v63,r10,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,576
	r29.s64 = 576;
	// stfs f0,256(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 256, temp.u32);
	// li r10,528
	ctx.r10.s64 = 528;
	// stfs f0,260(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 260, temp.u32);
	// li r28,592
	r28.s64 = 592;
	// stfs f0,264(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 264, temp.u32);
	// stw r5,-296(r1)
	PPC_STORE_U32(ctx.r1.u32 + -296, ctx.r5.u32);
	// stfs f0,276(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 276, temp.u32);
	// stw r7,-260(r1)
	PPC_STORE_U32(ctx.r1.u32 + -260, ctx.r7.u32);
	// stw r6,-264(r1)
	PPC_STORE_U32(ctx.r1.u32 + -264, ctx.r6.u32);
	// li r27,608
	r27.s64 = 608;
	// stw r31,-268(r1)
	PPC_STORE_U32(ctx.r1.u32 + -268, r31.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// stw r30,-276(r1)
	PPC_STORE_U32(ctx.r1.u32 + -276, r30.u32);
	// li r7,32
	ctx.r7.s64 = 32;
	// stw r9,272(r3)
	PPC_STORE_U32(ctx.r3.u32 + 272, ctx.r9.u32);
	// li r26,48
	r26.s64 = 48;
	// stw r29,-280(r1)
	PPC_STORE_U32(ctx.r1.u32 + -280, r29.u32);
	// li r6,16
	ctx.r6.s64 = 16;
	// stw r8,-252(r1)
	PPC_STORE_U32(ctx.r1.u32 + -252, ctx.r8.u32);
	// li r31,32
	r31.s64 = 32;
	// stw r9,-284(r1)
	PPC_STORE_U32(ctx.r1.u32 + -284, ctx.r9.u32);
	// li r30,48
	r30.s64 = 48;
	// li r3,16
	ctx.r3.s64 = 16;
	// stw r10,-288(r1)
	PPC_STORE_U32(ctx.r1.u32 + -288, ctx.r10.u32);
	// li r25,32
	r25.s64 = 32;
	// stw r28,-272(r1)
	PPC_STORE_U32(ctx.r1.u32 + -272, r28.u32);
	// li r24,48
	r24.s64 = 48;
	// li r29,16
	r29.s64 = 16;
	// lwz r10,-300(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -300);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r27,-292(r1)
	PPC_STORE_U32(ctx.r1.u32 + -292, r27.u32);
	// li r28,192
	r28.s64 = 192;
	// rotlwi r27,r11,0
	r27.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,-296(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -296);
	// mr r22,r10
	r22.u64 = ctx.r10.u64;
	// lwz r20,-304(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + -304);
	// stw r9,-284(r1)
	PPC_STORE_U32(ctx.r1.u32 + -284, ctx.r9.u32);
	// li r23,336
	r23.s64 = 336;
	// li r21,384
	r21.s64 = 384;
	// stvx128 v63,r10,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,-252(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -252);
	// lvx128 v63,r27,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r5,r22,0
	ctx.r5.u64 = __builtin_rotateleft32(r22.u32, 0);
	// stvx128 v63,r22,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r22.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r28,r20
	r28.u64 = r20.u64;
	// lvx128 v63,r20,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,-300(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + -300);
	// lwz r22,-260(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + -260);
	// stvx128 v63,r5,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,20(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 20);
	// lvx128 v63,r28,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r7,r22
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r5,r9,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// stfs f0,352(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 352, temp.u32);
	// rotlwi r10,r7,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// stfs f0,356(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 356, temp.u32);
	// rotlwi r9,r20,0
	ctx.r9.u64 = __builtin_rotateleft32(r20.u32, 0);
	// stfs f0,360(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 360, temp.u32);
	// stw r5,368(r11)
	PPC_STORE_U32(r11.u32 + 368, ctx.r5.u32);
	// stfs f0,372(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 372, temp.u32);
	// lwz r7,-264(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + -264);
	// lwz r28,-268(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + -268);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r26,-276(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + -276);
	// li r27,400
	r27.s64 = 400;
	// li r5,416
	ctx.r5.s64 = 416;
	// li r22,432
	r22.s64 = 432;
	// li r20,48
	r20.s64 = 48;
	// li r19,16
	r19.s64 = 16;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,480
	ctx.r7.s64 = 480;
	// lvx128 v63,r9,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,496
	ctx.r6.s64 = 496;
	// stvx128 v63,r10,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,32
	r28.s64 = 32;
	// lvx128 v63,r9,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r31,512
	r31.s64 = 512;
	// stvx128 v63,r10,r26
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r26,624
	r26.s64 = 624;
	// lvx128 v63,r9,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r26,-276(r1)
	PPC_STORE_U32(ctx.r1.u32 + -276, r26.u32);
	// stvx128 v63,r10,r23
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r26,16
	r26.s64 = 16;
	// stfs f0,448(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 448, temp.u32);
	// li r23,32
	r23.s64 = 32;
	// stfs f0,452(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 452, temp.u32);
	// stfs f0,456(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 456, temp.u32);
	// stw r8,464(r11)
	PPC_STORE_U32(r11.u32 + 464, ctx.r8.u32);
	// stfs f0,468(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 468, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r21
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r9,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r9,r25
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r9,r24
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r22
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,544(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 544, temp.u32);
	// stfs f0,548(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 548, temp.u32);
	// stfs f0,552(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 552, temp.u32);
	// stw r8,560(r11)
	PPC_STORE_U32(r11.u32 + 560, ctx.r8.u32);
	// stfs f0,564(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 564, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r9,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r9,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,864
	r11.s64 = r11.s64 + 864;
	// lwz r5,-304(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + -304);
	// lwz r9,-300(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -300);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,-288(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -288);
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// stw r11,-296(r1)
	PPC_STORE_U32(ctx.r1.u32 + -296, r11.u32);
	// mr r24,r9
	r24.u64 = ctx.r9.u64;
	// lwz r11,20(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 20);
	// mr r22,r5
	r22.u64 = ctx.r5.u64;
	// lvx128 v63,r5,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,-280(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + -280);
	// lwz r25,-272(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + -272);
	// li r7,672
	ctx.r7.s64 = 672;
	// stvx128 v63,r9,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// li r6,688
	ctx.r6.s64 = 688;
	// stw r8,-272(r1)
	PPC_STORE_U32(ctx.r1.u32 + -272, ctx.r8.u32);
	// stfs f0,640(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 640, temp.u32);
	// li r31,32
	r31.s64 = 32;
	// stfs f0,644(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 644, temp.u32);
	// li r29,704
	r29.s64 = 704;
	// stfs f0,648(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 648, temp.u32);
	// stw r10,656(r11)
	PPC_STORE_U32(r11.u32 + 656, ctx.r10.u32);
	// stfs f0,660(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 660, temp.u32);
	// rotlwi r10,r22,0
	ctx.r10.u64 = __builtin_rotateleft32(r22.u32, 0);
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,-292(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + -292);
	// stvx128 v63,r3,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-276(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -276);
	// lvx128 v63,r28,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r27,48
	r27.s64 = 48;
	// stvx128 v63,r24,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r30,720
	r30.s64 = 720;
	// lvx128 v63,r22,r23
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,32
	r28.s64 = 32;
	// stvx128 v63,r9,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,-284(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + -284);
	// lvx128 v63,r10,r20
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r26,32
	r26.s64 = 32;
	// stvx128 v63,r9,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,16
	ctx.r3.s64 = 16;
	// stfs f0,736(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 736, temp.u32);
	// li r25,144
	r25.s64 = 144;
	// stfs f0,740(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 740, temp.u32);
	// li r24,208
	r24.s64 = 208;
	// stfs f0,744(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 744, temp.u32);
	// stw r5,752(r11)
	PPC_STORE_U32(r11.u32 + 752, ctx.r5.u32);
	// stfs f0,756(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 756, temp.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r25,-292(r1)
	PPC_STORE_U32(ctx.r1.u32 + -292, r25.u32);
	// stvx128 v63,r9,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r25,48
	r25.s64 = 48;
	// lvx128 v63,r10,r19
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r23,224
	r23.s64 = 224;
	// stvx128 v63,r9,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r24,-280(r1)
	PPC_STORE_U32(ctx.r1.u32 + -280, r24.u32);
	// lvx128 v63,r10,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r24,16
	r24.s64 = 16;
	// stvx128 v63,r9,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r23,-288(r1)
	PPC_STORE_U32(ctx.r1.u32 + -288, r23.u32);
	// lvx128 v63,r10,r27
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,96
	ctx.r7.s64 = 96;
	// stvx128 v63,r9,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,-296(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -296);
	// stfs f0,832(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 832, temp.u32);
	// rotlwi r6,r22,0
	ctx.r6.u64 = __builtin_rotateleft32(r22.u32, 0);
	// stfs f0,836(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 836, temp.u32);
	// stfs f0,840(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 840, temp.u32);
	// stw r8,848(r11)
	PPC_STORE_U32(r11.u32 + 848, ctx.r8.u32);
	// stfs f0,852(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 852, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r10,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,48
	ctx.r3.s64 = 48;
	// stvx128 v63,r9,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,112
	ctx.r5.s64 = 112;
	// lvx128 v63,r10,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r26
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r10,r25
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r30,32
	r30.s64 = 32;
	// stfs f0,928(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 928, temp.u32);
	// li r28,128
	r28.s64 = 128;
	// stfs f0,932(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 932, temp.u32);
	// lwz r31,-292(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + -292);
	// stfs f0,936(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 936, temp.u32);
	// stw r8,944(r11)
	PPC_STORE_U32(r11.u32 + 944, ctx.r8.u32);
	// stfs f0,948(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 948, temp.u32);
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// rotlwi r27,r11,0
	r27.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r4,-204(r1)
	PPC_STORE_U32(ctx.r1.u32 + -204, ctx.r4.u32);
	// rotlwi r26,r11,0
	r26.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r16,-288(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + -288);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r18,-280(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + -280);
	// rotlwi r25,r8,0
	r25.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lwz r20,-304(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + -304);
	// li r15,512
	r15.s64 = 512;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r15,-292(r1)
	PPC_STORE_U32(ctx.r1.u32 + -292, r15.u32);
	// li r14,528
	r14.s64 = 528;
	// stw r4,-288(r1)
	PPC_STORE_U32(ctx.r1.u32 + -288, ctx.r4.u32);
	// li r4,608
	ctx.r4.s64 = 608;
	// stw r14,-280(r1)
	PPC_STORE_U32(ctx.r1.u32 + -280, r14.u32);
	// rotlwi r8,r22,0
	ctx.r8.u64 = __builtin_rotateleft32(r22.u32, 0);
	// stw r4,-264(r1)
	PPC_STORE_U32(ctx.r1.u32 + -264, ctx.r4.u32);
	// li r15,576
	r15.s64 = 576;
	// li r14,592
	r14.s64 = 592;
	// li r4,672
	ctx.r4.s64 = 672;
	// stw r15,-276(r1)
	PPC_STORE_U32(ctx.r1.u32 + -276, r15.u32);
	// mr r22,r9
	r22.u64 = ctx.r9.u64;
	// stw r14,-268(r1)
	PPC_STORE_U32(ctx.r1.u32 + -268, r14.u32);
	// li r23,192
	r23.s64 = 192;
	// stw r4,-252(r1)
	PPC_STORE_U32(ctx.r1.u32 + -252, ctx.r4.u32);
	// li r21,16
	r21.s64 = 16;
	// li r15,624
	r15.s64 = 624;
	// li r14,0
	r14.s64 = 0;
	// li r4,720
	ctx.r4.s64 = 720;
	// stw r15,-284(r1)
	PPC_STORE_U32(ctx.r1.u32 + -284, r15.u32);
	// li r19,32
	r19.s64 = 32;
	// stw r14,-260(r1)
	PPC_STORE_U32(ctx.r1.u32 + -260, r14.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r17,48
	r17.s64 = 48;
	// stvx128 v63,r9,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r4,-196(r1)
	PPC_STORE_U32(ctx.r1.u32 + -196, ctx.r4.u32);
	// lvx128 v63,r10,r24
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r15,688
	r15.s64 = 688;
	// stvx128 v63,r9,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r14,704
	r14.s64 = 704;
	// lvx128 v63,r10,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r10,r20,0
	ctx.r10.u64 = __builtin_rotateleft32(r20.u32, 0);
	// stvx128 v63,r9,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r9,r9,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lvx128 v63,r6,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,48
	ctx.r4.s64 = 48;
	// stvx128 v63,r29,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r15,-256(r1)
	PPC_STORE_U32(ctx.r1.u32 + -256, r15.u32);
	// stfs f0,1024(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 1024, temp.u32);
	// stw r14,-248(r1)
	PPC_STORE_U32(ctx.r1.u32 + -248, r14.u32);
	// stfs f0,1028(r26)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r26.u32 + 1028, temp.u32);
	// stw r4,-272(r1)
	PPC_STORE_U32(ctx.r1.u32 + -272, ctx.r4.u32);
	// stfs f0,1032(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1032, temp.u32);
	// stw r25,1040(r11)
	PPC_STORE_U32(r11.u32 + 1040, r25.u32);
	// stfs f0,1044(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1044, temp.u32);
	// lwz r11,20(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 20);
	// lwz r30,-292(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + -292);
	// li r15,16
	r15.s64 = 16;
	// li r14,32
	r14.s64 = 32;
	// li r4,16
	ctx.r4.s64 = 16;
	// li r7,32
	ctx.r7.s64 = 32;
	// li r24,48
	r24.s64 = 48;
	// li r3,240
	ctx.r3.s64 = 240;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,0
	ctx.r8.s64 = 0;
	// stvx128 v63,r22,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r22.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r20,r21
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32 + r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r18
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r18.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r10,r19
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r16
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r16.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r10,r17
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r31,288
	r31.s64 = 288;
	// stfs f0,1120(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1120, temp.u32);
	// li r5,304
	ctx.r5.s64 = 304;
	// stfs f0,1124(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1124, temp.u32);
	// li r6,320
	ctx.r6.s64 = 320;
	// stfs f0,1128(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1128, temp.u32);
	// stw r8,1136(r11)
	PPC_STORE_U32(r11.u32 + 1136, ctx.r8.u32);
	// stfs f0,1140(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1140, temp.u32);
	// stw r7,-292(r1)
	PPC_STORE_U32(ctx.r1.u32 + -292, ctx.r7.u32);
	// li r7,336
	ctx.r7.s64 = 336;
	// stw r3,-220(r1)
	PPC_STORE_U32(ctx.r1.u32 + -220, ctx.r3.u32);
	// li r27,384
	r27.s64 = 384;
	// stw r8,-208(r1)
	PPC_STORE_U32(ctx.r1.u32 + -208, ctx.r8.u32);
	// li r26,400
	r26.s64 = 400;
	// stw r8,-212(r1)
	PPC_STORE_U32(ctx.r1.u32 + -212, ctx.r8.u32);
	// li r25,416
	r25.s64 = 416;
	// li r23,432
	r23.s64 = 432;
	// li r3,480
	ctx.r3.s64 = 480;
	// li r16,48
	r16.s64 = 48;
	// addi r19,r11,1648
	r19.s64 = r11.s64 + 1648;
	// stw r16,-244(r1)
	PPC_STORE_U32(ctx.r1.u32 + -244, r16.u32);
	// li r16,16
	r16.s64 = 16;
	// stw r19,-300(r1)
	PPC_STORE_U32(ctx.r1.u32 + -300, r19.u32);
	// li r18,112
	r18.s64 = 112;
	// stw r16,-232(r1)
	PPC_STORE_U32(ctx.r1.u32 + -232, r16.u32);
	// li r17,128
	r17.s64 = 128;
	// li r19,144
	r19.s64 = 144;
	// stw r18,-188(r1)
	PPC_STORE_U32(ctx.r1.u32 + -188, r18.u32);
	// li r16,32
	r16.s64 = 32;
	// stw r17,-216(r1)
	PPC_STORE_U32(ctx.r1.u32 + -216, r17.u32);
	// rotlwi r29,r22,0
	r29.u64 = __builtin_rotateleft32(r22.u32, 0);
	// stw r19,-192(r1)
	PPC_STORE_U32(ctx.r1.u32 + -192, r19.u32);
	// li r22,16
	r22.s64 = 16;
	// stw r16,-200(r1)
	PPC_STORE_U32(ctx.r1.u32 + -200, r16.u32);
	// li r18,192
	r18.s64 = 192;
	// li r17,208
	r17.s64 = 208;
	// li r19,224
	r19.s64 = 224;
	// stw r18,-240(r1)
	PPC_STORE_U32(ctx.r1.u32 + -240, r18.u32);
	// li r16,48
	r16.s64 = 48;
	// stw r17,-236(r1)
	PPC_STORE_U32(ctx.r1.u32 + -236, r17.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r28,r20,0
	r28.u64 = __builtin_rotateleft32(r20.u32, 0);
	// stvx128 v63,r9,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r19,-228(r1)
	PPC_STORE_U32(ctx.r1.u32 + -228, r19.u32);
	// lvx128 v63,r10,r15
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r15,-272(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + -272);
	// stvx128 v63,r9,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r16,-224(r1)
	PPC_STORE_U32(ctx.r1.u32 + -224, r16.u32);
	// lvx128 v63,r10,r14
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r14.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r21,496
	r21.s64 = 496;
	// stvx128 v63,r9,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r20,32
	r20.s64 = 32;
	// lvx128 v63,r10,r15
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r18,48
	r18.s64 = 48;
	// stvx128 v63,r9,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r17,16
	r17.s64 = 16;
	// stfs f0,1216(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1216, temp.u32);
	// li r19,32
	r19.s64 = 32;
	// stfs f0,1220(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1220, temp.u32);
	// li r16,16
	r16.s64 = 16;
	// stfs f0,1224(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1224, temp.u32);
	// stw r8,1232(r11)
	PPC_STORE_U32(r11.u32 + 1232, ctx.r8.u32);
	// stfs f0,1236(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1236, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r27,-292(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + -292);
	// lvx128 v63,r10,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r26
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r10,r27
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r25
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r10,r24
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r23
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,1312(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1312, temp.u32);
	// stfs f0,1316(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1316, temp.u32);
	// stfs f0,1320(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1320, temp.u32);
	// stw r8,1328(r11)
	PPC_STORE_U32(r11.u32 + 1328, ctx.r8.u32);
	// stfs f0,1332(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1332, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r10,r22
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r21
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-280(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -280);
	// lvx128 v63,r10,r20
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,-296(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -296);
	// stvx128 v63,r29,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,-288(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -288);
	// lvx128 v63,r28,r18
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-304(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -304);
	// stvx128 v63,r10,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,20(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 20);
	// stfs f0,1408(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1408, temp.u32);
	// lwz r30,-276(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + -276);
	// stfs f0,1412(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1412, temp.u32);
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
	// stfs f0,1416(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1416, temp.u32);
	// stw r9,1424(r11)
	PPC_STORE_U32(r11.u32 + 1424, ctx.r9.u32);
	// stfs f0,1428(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1428, temp.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r25,-268(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + -268);
	// mr r23,r10
	r23.u64 = ctx.r10.u64;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// lwz r18,-264(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + -264);
	// mr r14,r10
	r14.u64 = ctx.r10.u64;
	// std r5,-168(r1)
	PPC_STORE_U64(ctx.r1.u32 + -168, ctx.r5.u64);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// std r31,-184(r1)
	PPC_STORE_U64(ctx.r1.u32 + -184, r31.u64);
	// li r5,32
	ctx.r5.s64 = 32;
	// std r6,-176(r1)
	PPC_STORE_U64(ctx.r1.u32 + -176, ctx.r6.u64);
	// li r11,32
	r11.s64 = 32;
	// stw r10,-292(r1)
	PPC_STORE_U32(ctx.r1.u32 + -292, ctx.r10.u32);
	// stw r5,-276(r1)
	PPC_STORE_U32(ctx.r1.u32 + -276, ctx.r5.u32);
	// rotlwi r10,r3,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// li r5,16
	ctx.r5.s64 = 16;
	// lwz r4,-284(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + -284);
	// li r31,48
	r31.s64 = 48;
	// stw r11,-272(r1)
	PPC_STORE_U32(ctx.r1.u32 + -272, r11.u32);
	// rotlwi r6,r14,0
	ctx.r6.u64 = __builtin_rotateleft32(r14.u32, 0);
	// lwz r11,20(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 20);
	// stw r5,-264(r1)
	PPC_STORE_U32(ctx.r1.u32 + -264, ctx.r5.u32);
	// li r9,48
	ctx.r9.s64 = 48;
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r31,-268(r1)
	PPC_STORE_U32(ctx.r1.u32 + -268, r31.u32);
	// lwz r31,-260(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + -260);
	// li r15,16
	r15.s64 = 16;
	// stw r9,-280(r1)
	PPC_STORE_U32(ctx.r1.u32 + -280, ctx.r9.u32);
	// rotlwi r9,r14,0
	ctx.r9.u64 = __builtin_rotateleft32(r14.u32, 0);
	// stw r5,-284(r1)
	PPC_STORE_U32(ctx.r1.u32 + -284, ctx.r5.u32);
	// li r20,48
	r20.s64 = 48;
	// lwz r5,-252(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + -252);
	// li r28,16
	r28.s64 = 16;
	// std r7,-160(r1)
	PPC_STORE_U64(ctx.r1.u32 + -160, ctx.r7.u64);
	// li r7,16
	ctx.r7.s64 = 16;
	// li r26,32
	r26.s64 = 32;
	// stw r7,-288(r1)
	PPC_STORE_U32(ctx.r1.u32 + -288, ctx.r7.u32);
	// li r24,32
	r24.s64 = 32;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-244(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -244);
	// stvx128 v63,r29,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r30,r21,0
	r30.u64 = __builtin_rotateleft32(r21.u32, 0);
	// lvx128 v63,r27,r17
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,-256(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + -256);
	// stvx128 v63,r23,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r15,-256(r1)
	PPC_STORE_U32(ctx.r1.u32 + -256, r15.u32);
	// lvx128 v63,r21,r19
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32 + r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r15,-248(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + -248);
	// stvx128 v63,r14,r18
	simde_mm_store_si128((simde__m128i*)(base + ((r14.u32 + r18.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r20,-248(r1)
	PPC_STORE_U32(ctx.r1.u32 + -248, r20.u32);
	// lvx128 v63,r30,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-232(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -232);
	// stvx128 v63,r6,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r20,-196(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + -196);
	// stfs f0,1504(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1504, temp.u32);
	// li r22,48
	r22.s64 = 48;
	// stfs f0,1508(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1508, temp.u32);
	// stfs f0,1512(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1512, temp.u32);
	// stw r31,1520(r11)
	PPC_STORE_U32(r11.u32 + 1520, r31.u32);
	// stfs f0,1524(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1524, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r10,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-200(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -200);
	// rotlwi r29,r21,0
	r29.u64 = __builtin_rotateleft32(r21.u32, 0);
	// lwz r27,-188(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + -188);
	// rotlwi r25,r21,0
	r25.u64 = __builtin_rotateleft32(r21.u32, 0);
	// lwz r19,-208(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + -208);
	// lwz r18,-304(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + -304);
	// lwz r17,-240(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -240);
	// lvx128 v63,r10,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-224(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -224);
	// stvx128 v63,r9,r15
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r15.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r15,-236(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + -236);
	// lwz r14,-228(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + -228);
	// lwz r7,-220(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + -220);
	// lwz r6,-212(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + -212);
	// lvx128 v63,r10,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-248(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -248);
	// stvx128 v63,r9,r20
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r20.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,-300(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -300);
	// stfs f0,1600(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1600, temp.u32);
	// stfs f0,1604(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1604, temp.u32);
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
	// stfs f0,1608(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1608, temp.u32);
	// stw r8,1616(r11)
	PPC_STORE_U32(r11.u32 + 1616, ctx.r8.u32);
	// stfs f0,1620(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1620, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r10,r16
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,48
	r28.s64 = 48;
	// lvx128 v63,r10,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// stvx128 v63,r9,r24
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r24,-216(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + -216);
	// rotlwi r23,r26,0
	r23.u64 = __builtin_rotateleft32(r26.u32, 0);
	// rotlwi r20,r26,0
	r20.u64 = __builtin_rotateleft32(r26.u32, 0);
	// rotlwi r16,r26,0
	r16.u64 = __builtin_rotateleft32(r26.u32, 0);
	// lvx128 v63,r10,r22
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r22,r21,0
	r22.u64 = __builtin_rotateleft32(r21.u32, 0);
	// stvx128 v63,r9,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r21,-192(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + -192);
	// stfs f0,1712(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1712, temp.u32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// stfs f0,1716(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1716, temp.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stfs f0,1720(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1720, temp.u32);
	// stw r8,1728(r11)
	PPC_STORE_U32(r11.u32 + 1728, ctx.r8.u32);
	// stfs f0,1732(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1732, temp.u32);
	// li r8,96
	ctx.r8.s64 = 96;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lfs f13,7444(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,20(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 20);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r10,r18
	ctx.r10.u64 = r18.u64;
	// stvx128 v63,r30,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,-256(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + -256);
	// lvx128 v63,r29,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,-272(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + -272);
	// stvx128 v63,r26,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r25,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,-280(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + -280);
	// stvx128 v63,r23,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r22,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,-288(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + -288);
	// stvx128 v63,r20,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r20.u32 + r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,1808(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1808, temp.u32);
	// stfs f0,1812(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1812, temp.u32);
	// stfs f0,1816(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1816, temp.u32);
	// stw r19,1824(r11)
	PPC_STORE_U32(r11.u32 + 1824, r19.u32);
	// stfs f0,1828(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1828, temp.u32);
	// rotlwi r11,r26,0
	r11.u64 = __builtin_rotateleft32(r26.u32, 0);
	// lvx128 v63,r0,r18
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r16,r17
	simde_mm_store_si128((simde__m128i*)(base + ((r16.u32 + r17.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r10,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,-276(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + -276);
	// stvx128 v63,r11,r15
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r15.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r10,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,-268(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + -268);
	// stvx128 v63,r11,r14
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r14.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r10,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,1904(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1904, temp.u32);
	// stfs f0,1908(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1908, temp.u32);
	// ld r31,-184(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -184);
	// stfs f0,1912(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1912, temp.u32);
	// stw r6,1920(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1920, ctx.r6.u32);
	// stfs f0,1924(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1924, temp.u32);
	// lwz r30,-264(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + -264);
	// ld r5,-168(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + -168);
	// ld r6,-176(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + -176);
	// ld r7,-160(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// lwz r4,-204(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + -204);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r10,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r30,-284(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + -284);
	// stvx128 v63,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r10,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,-1
	ctx.r6.s64 = -1;
	// lvx128 v63,r10,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,0
	r11.s64 = 0;
	// stfs f0,2000(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 2000, temp.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stfs f0,2004(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 2004, temp.u32);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// stfs f0,2008(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 2008, temp.u32);
	// stw r11,2016(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2016, r11.u32);
	// stfs f0,2020(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 2020, temp.u32);
	// stw r4,2032(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2032, ctx.r4.u32);
	// stb r11,2154(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2154, r11.u8);
	// stb r9,2148(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2148, ctx.r9.u8);
	// stb r9,2150(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2150, ctx.r9.u8);
	// stb r11,2151(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2151, r11.u8);
	// stb r11,2152(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2152, r11.u8);
	// stb r11,2153(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2153, r11.u8);
	// stb r11,2149(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2149, r11.u8);
	// stw r11,2144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2144, r11.u32);
	// stfs f13,2064(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 2064, temp.u32);
	// lfs f13,14884(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// lis r7,-32119
	ctx.r7.s64 = -2104950784;
	// stfs f0,2068(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 2068, temp.u32);
	// stfs f0,2072(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 2072, temp.u32);
	// stw r11,2036(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2036, r11.u32);
	// stfs f13,2048(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 2048, temp.u32);
	// addi r7,r7,-12236
	ctx.r7.s64 = ctx.r7.s64 + -12236;
	// stfs f13,2052(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 2052, temp.u32);
	// stfs f13,2056(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 2056, temp.u32);
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r11.u32);
	// stw r11,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, r11.u32);
	// stw r6,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r6.u32);
loc_82309F54:
	// lbzx r6,r8,r7
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r7.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82309fdc
	if (cr6.eq) goto loc_82309FDC;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r8,8
	cr6.compare<int32_t>(ctx.r8.s32, 8, xer);
	// blt cr6,0x82309f54
	if (cr6.lt) goto loc_82309F54;
	// li r8,-1
	ctx.r8.s64 = -1;
loc_82309F70:
	// stw r8,80(r3)
	PPC_STORE_U32(ctx.r3.u32 + 80, ctx.r8.u32);
	// addi r9,r3,1680
	ctx.r9.s64 = ctx.r3.s64 + 1680;
	// stw r11,1632(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1632, r11.u32);
	// li r8,4
	ctx.r8.s64 = 4;
	// li r5,-32
	ctx.r5.s64 = -32;
	// li r6,-16
	ctx.r6.s64 = -16;
	// li r7,16
	ctx.r7.s64 = 16;
loc_82309F8C:
	// stfs f0,52(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 52, temp.u32);
	// stw r11,48(r9)
	PPC_STORE_U32(ctx.r9.u32 + 48, r11.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,16
	ctx.r4.s64 = 16;
	// stvx128 v63,r9,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r31,32
	r31.s64 = 32;
	// lvx128 v63,r10,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,48
	ctx.r4.s64 = 48;
	// stvx128 v63,r9,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// lvx128 v63,r10,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r10,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r9,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,32(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 32, temp.u32);
	// stfs f0,36(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 36, temp.u32);
	// stfs f0,40(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 40, temp.u32);
	// addi r9,r9,96
	ctx.r9.s64 = ctx.r9.s64 + 96;
	// bne 0x82309f8c
	if (!cr0.eq) goto loc_82309F8C;
	// b 0x823d9210
	return;
loc_82309FDC:
	// stbx r9,r8,r7
	PPC_STORE_U8(ctx.r8.u32 + ctx.r7.u32, ctx.r9.u8);
	// b 0x82309f70
	goto loc_82309F70;
}

__attribute__((alias("__imp__sub_82309FE4"))) PPC_WEAK_FUNC(sub_82309FE4);
PPC_FUNC_IMPL(__imp__sub_82309FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82309FE8"))) PPC_WEAK_FUNC(sub_82309FE8);
PPC_FUNC_IMPL(__imp__sub_82309FE8) {
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
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r9,r10,11844
	ctx.r9.s64 = ctx.r10.s64 + 11844;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8230a034
	if (cr6.lt) goto loc_8230A034;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bge cr6,0x8230a034
	if (!cr6.lt) goto loc_8230A034;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,-12236
	ctx.r8.s64 = ctx.r10.s64 + -12236;
	// stbx r9,r11,r8
	PPC_STORE_U8(r11.u32 + ctx.r8.u32, ctx.r9.u8);
loc_8230A034:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8230A03C;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8230a054
	if (cr6.eq) goto loc_8230A054;
	// bl 0x82130588
	ctx.lr = 0x8230A050;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8230A054:
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

__attribute__((alias("__imp__sub_8230A06C"))) PPC_WEAK_FUNC(sub_8230A06C);
PPC_FUNC_IMPL(__imp__sub_8230A06C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230A070"))) PPC_WEAK_FUNC(sub_8230A070);
PPC_FUNC_IMPL(__imp__sub_8230A070) {
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
	ctx.lr = 0x8230A078;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-12220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8230a0a0
	if (cr6.eq) goto loc_8230A0A0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8230A0A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8230A0A0:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r31,-12216(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8230a0c0
	if (cr6.eq) goto loc_8230A0C0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217cb48
	ctx.lr = 0x8230A0B8;
	sub_8217CB48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x8230A0C0;
	sub_82130588(ctx, base);
loc_8230A0C0:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// li r26,0
	r26.s64 = 0;
	// addi r28,r11,-12268
	r28.s64 = r11.s64 + -12268;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r30,r26
	r30.u64 = r26.u64;
	// mr r31,r28
	r31.u64 = r28.u64;
	// addi r27,r11,-12236
	r27.s64 = r11.s64 + -12236;
loc_8230A0DC:
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r29,8
	ctx.r3.s64 = r29.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8230A0E8;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8230a110
	if (!cr6.eq) goto loc_8230A110;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8230a110
	if (cr6.eq) goto loc_8230A110;
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
	ctx.lr = 0x8230A110;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8230A110:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stbx r26,r30,r27
	PPC_STORE_U8(r30.u32 + r27.u32, r26.u8);
	// addi r11,r28,32
	r11.s64 = r28.s64 + 32;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8230a0dc
	if (cr6.lt) goto loc_8230A0DC;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r29,r11,-12276
	r29.s64 = r11.s64 + -12276;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_8230A134:
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8230A140;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8230a168
	if (!cr6.eq) goto loc_8230A168;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8230a168
	if (cr6.eq) goto loc_8230A168;
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
	ctx.lr = 0x8230A168;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8230A168:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r29,8
	r11.s64 = r29.s64 + 8;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8230a134
	if (cr6.lt) goto loc_8230A134;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8230A180"))) PPC_WEAK_FUNC(sub_8230A180);
PPC_FUNC_IMPL(__imp__sub_8230A180) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r8,r11,-31280
	ctx.r8.s64 = r11.s64 + -31280;
	// li r7,32
	ctx.r7.s64 = 32;
	// li r9,1
	ctx.r9.s64 = 1;
	// clrlwi r6,r5,24
	ctx.r6.u64 = ctx.r5.u32 & 0xFF;
	// stb r9,2154(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2154, ctx.r9.u8);
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// lvx128 v61,r8,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r8,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8230a27c
	if (cr6.eq) goto loc_8230A27C;
	// lwz r11,88(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bge cr6,0x8230a344
	if (!cr6.lt) goto loc_8230A344;
	// addi r11,r11,9
	r11.s64 = r11.s64 + 9;
	// li r8,16
	ctx.r8.s64 = 16;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r5,48
	ctx.r5.s64 = 48;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// rlwinm r11,r6,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r31,r1,-32
	r31.s64 = ctx.r1.s64 + -32;
	// lfs f0,-12084(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -12084);
	f0.f64 = double(temp.f32);
	// li r30,928
	r30.s64 = 928;
	// stfs f0,-32(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// lfs f13,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,88(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stfs f0,-28(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// stfs f13,-24(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r11,r5,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// add r4,r11,r3
	ctx.r4.u64 = r11.u64 + ctx.r3.u64;
	// stvx128 v63,r4,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,88(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// stw r9,944(r10)
	PPC_STORE_U32(ctx.r10.u32 + 944, ctx.r9.u32);
	// lwz r11,88(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r9,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// add r8,r11,r3
	ctx.r8.u64 = r11.u64 + ctx.r3.u64;
	// stfs f1,948(r8)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r8.u32 + 948, temp.u32);
	// lwz r11,88(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r7,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r7.u32);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8230A27C:
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bge cr6,0x8230a344
	if (!cr6.lt) goto loc_8230A344;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// li r9,16
	ctx.r9.s64 = 16;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// li r8,32
	ctx.r8.s64 = 32;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// li r6,48
	ctx.r6.s64 = 48;
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// addi r7,r1,-32
	ctx.r7.s64 = ctx.r1.s64 + -32;
	// lfs f12,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// li r31,0
	r31.s64 = 0;
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f13,-29232(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -29232);
	ctx.f13.f64 = double(temp.f32);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// lfs f0,11912(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 11912);
	f0.f64 = double(temp.f32);
	// li r5,160
	ctx.r5.s64 = 160;
	// fmadds f0,f1,f0,f13
	f0.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f13.f64));
	// rlwinm r11,r4,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// stfs f12,-24(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// stfs f0,-32(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stfs f0,-28(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// stw r31,176(r9)
	PPC_STORE_U32(ctx.r9.u32 + 176, r31.u32);
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r7,r11,r3
	ctx.r7.u64 = r11.u64 + ctx.r3.u64;
	// stfs f1,180(r7)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r7.u32 + 180, temp.u32);
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r6.u32);
loc_8230A344:
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8230A350"))) PPC_WEAK_FUNC(sub_8230A350);
PPC_FUNC_IMPL(__imp__sub_8230A350) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8230A358;
	// vor128 v63,v1,v1
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// addi r11,r1,-64
	r11.s64 = ctx.r1.s64 + -64;
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,-8
	ctx.r9.s64 = -8;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// vpkd3d128 v63,v1,5,2,2
	ctx.fpscr.enableFlushMode();
	temp.u32 = (ctx.v1.u32[0]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((ctx.v1.u32[0]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((ctx.v1.u32[0]&0x7FE000)>>13) : 0x0;
	v63.u16[4] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	v63.u16[4] |= ((ctx.v1.u32[0]&0x80000000)>>16);
	temp.u32 = (ctx.v1.u32[1]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((ctx.v1.u32[1]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((ctx.v1.u32[1]&0x7FE000)>>13) : 0x0;
	v63.u16[5] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	v63.u16[5] |= ((ctx.v1.u32[1]&0x80000000)>>16);
	temp.u32 = (ctx.v1.u32[2]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((ctx.v1.u32[2]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((ctx.v1.u32[2]&0x7FE000)>>13) : 0x0;
	v63.u16[6] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	v63.u16[6] |= ((ctx.v1.u32[2]&0x80000000)>>16);
	temp.u32 = (ctx.v1.u32[3]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((ctx.v1.u32[3]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((ctx.v1.u32[3]&0x7FE000)>>13) : 0x0;
	v63.u16[7] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	v63.u16[7] |= ((ctx.v1.u32[3]&0x80000000)>>16);
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// addi r5,r7,-31664
	ctx.r5.s64 = ctx.r7.s64 + -31664;
	// addi r7,r4,2240
	ctx.r7.s64 = ctx.r4.s64 + 2240;
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// addi r4,r4,-31648
	ctx.r4.s64 = ctx.r4.s64 + -31648;
	// addi r6,r8,2528
	ctx.r6.s64 = ctx.r8.s64 + 2528;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhz r31,-58(r1)
	r31.u64 = PPC_LOAD_U16(ctx.r1.u32 + -58);
	// lhz r30,-64(r1)
	r30.u64 = PPC_LOAD_U16(ctx.r1.u32 + -64);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lhz r28,-62(r1)
	r28.u64 = PPC_LOAD_U16(ctx.r1.u32 + -62);
	// addi r29,r1,-64
	r29.s64 = ctx.r1.s64 + -64;
	// lhz r11,-60(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + -60);
	// addi r8,r8,-12736
	ctx.r8.s64 = ctx.r8.s64 + -12736;
	// sth r11,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r11.u16);
	// sth r28,2(r3)
	PPC_STORE_U16(ctx.r3.u32 + 2, r28.u16);
	// sth r30,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, r30.u16);
	// sth r31,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, r31.u16);
	// lvrx128 v62,r10,r3
	temp.u32 = ctx.r10.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v61,r9,r3
	temp.u32 = ctx.r9.u32 + ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v60,v61,v62
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vupkd3d128 v59,v60,20
	__builtin_debugtrap();
	// lvx128 v0,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v58,v59,v1
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(ctx.v1.f32)));
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v13,v58,v58
	simde_mm_store_ps(ctx.v13.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// vspltw128 v11,v58,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x0));
	// vrsqrtefp128 v57,v13
	simde_mm_store_ps(v57.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v13.f32))));
	// vcmpeqfp128 v9,v57,v62
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v8,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// vsel v0,v8,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v7,v0,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v6,v63,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v5,v13,v7,v12
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v4,v5,v6,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v3,v13,v4,v11
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vand128 v56,v3,v61
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vaddfp128 v55,v56,v1
	simde_mm_store_ps(v55.f32, simde_mm_add_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(ctx.v1.f32)));
	// vor128 v54,v55,v55
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vpkd3d128 v54,v55,5,2,2
	temp.u32 = (v55.u32[0]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((v55.u32[0]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((v55.u32[0]&0x7FE000)>>13) : 0x0;
	v54.u16[4] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	v54.u16[4] |= ((v55.u32[0]&0x80000000)>>16);
	temp.u32 = (v55.u32[1]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((v55.u32[1]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((v55.u32[1]&0x7FE000)>>13) : 0x0;
	v54.u16[5] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	v54.u16[5] |= ((v55.u32[1]&0x80000000)>>16);
	temp.u32 = (v55.u32[2]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((v55.u32[2]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((v55.u32[2]&0x7FE000)>>13) : 0x0;
	v54.u16[6] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	v54.u16[6] |= ((v55.u32[2]&0x80000000)>>16);
	temp.u32 = (v55.u32[3]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((v55.u32[3]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((v55.u32[3]&0x7FE000)>>13) : 0x0;
	v54.u16[7] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	v54.u16[7] |= ((v55.u32[3]&0x80000000)>>16);
	// stvx128 v54,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhz r10,-58(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + -58);
	// lhz r9,-64(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + -64);
	// lhz r8,-62(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + -62);
	// lhz r11,-60(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + -60);
	// sth r11,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, r11.u16);
	// sth r8,2(r3)
	PPC_STORE_U16(ctx.r3.u32 + 2, ctx.r8.u16);
	// sth r9,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, ctx.r9.u16);
	// sth r10,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, ctx.r10.u16);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8230A448"))) PPC_WEAK_FUNC(sub_8230A448);
PPC_FUNC_IMPL(__imp__sub_8230A448) {
	PPC_FUNC_PROLOGUE();
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
	PPCVRegister vTemp{};
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// vmrghw128 v61,v1,v3
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v3.u32), simde_mm_load_si128((simde__m128i*)ctx.v1.u32)));
	// vmrghw128 v60,v2,v4
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v4.u32), simde_mm_load_si128((simde__m128i*)ctx.v2.u32)));
	// vor128 v59,v63,v63
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vmrglw128 v56,v1,v3
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v3.u32), simde_mm_load_si128((simde__m128i*)ctx.v1.u32)));
	// vupkd3d128 v57,v62,4
	temp.f32 = 3.0f;
	temp.s32 += v62.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v62.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v57 = vTemp;
	// vmrglw128 v58,v2,v4
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)ctx.v4.u32), simde_mm_load_si128((simde__m128i*)ctx.v2.u32)));
	// vmrghw128 v55,v61,v60
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vpkd3d128 v59,v63,0,1,0
	ctx.fpscr.enableFlushMode();
	vTemp.u32[0] = 0x404000FF;
	vTemp.f32[0] = v63.f32[0] < 3.0f ? 3.0f : (v63.f32[0] > vTemp.f32[0] ? vTemp.f32[0] : v63.f32[0]);
	temp.u32 = uint32_t(vTemp.u8[0]) << 24;
	vTemp.u32[1] = 0x404000FF;
	vTemp.f32[1] = v63.f32[1] < 3.0f ? 3.0f : (v63.f32[1] > vTemp.f32[1] ? vTemp.f32[1] : v63.f32[1]);
	temp.u32 |= uint32_t(vTemp.u8[4]) << 0;
	vTemp.u32[2] = 0x404000FF;
	vTemp.f32[2] = v63.f32[2] < 3.0f ? 3.0f : (v63.f32[2] > vTemp.f32[2] ? vTemp.f32[2] : v63.f32[2]);
	temp.u32 |= uint32_t(vTemp.u8[8]) << 8;
	vTemp.u32[3] = 0x404000FF;
	vTemp.f32[3] = v63.f32[3] < 3.0f ? 3.0f : (v63.f32[3] > vTemp.f32[3] ? vTemp.f32[3] : v63.f32[3]);
	temp.u32 |= uint32_t(vTemp.u8[12]) << 16;
	v59.u32[0] = temp.u32;
	// vpermwi128 v54,v57,171
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0x54));
	// vmrghw128 v53,v56,v58
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrglw128 v52,v61,v60
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vand128 v51,v5,v59
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vor128 v50,v51,v54
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)v54.u8)));
	// vmsum4fp128 v49,v55,v50
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// vmsum4fp128 v48,v53,v50
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// vmsum4fp128 v47,v52,v50
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// vmrghw128 v46,v49,v48
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v1,v46,v47
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8230A49C"))) PPC_WEAK_FUNC(sub_8230A49C);
PPC_FUNC_IMPL(__imp__sub_8230A49C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230A4A0"))) PPC_WEAK_FUNC(sub_8230A4A0);
PPC_FUNC_IMPL(__imp__sub_8230A4A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// addi r9,r1,-32
	ctx.r9.s64 = ctx.r1.s64 + -32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// rlwinm r7,r11,16,24,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF;
	// rlwinm r8,r11,8,24,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFF;
	// rlwinm r31,r11,24,24,31
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// std r7,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r7.u64);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lfd f12,-32(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// addi r7,r1,-32
	ctx.r7.s64 = ctx.r1.s64 + -32;
	// std r8,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r8.u64);
	// std r11,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r11.u64);
	// lfd f10,-32(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f13,-48(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// fcfid f7,f12
	ctx.f7.f64 = double(ctx.f12.s64);
	// lfs f0,15364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15364);
	f0.f64 = double(temp.f32);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// std r10,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r10.u64);
	// lfd f11,-48(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// fcfid f6,f13
	ctx.f6.f64 = double(ctx.f13.s64);
	// frsp f5,f9
	ctx.f5.f64 = double(float(ctx.f9.f64));
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// frsp f2,f6
	ctx.f2.f64 = double(float(ctx.f6.f64));
	// fmuls f1,f5,f0
	ctx.f1.f64 = double(float(ctx.f5.f64 * f0.f64));
	// stfs f1,-24(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// fmuls f13,f4,f0
	ctx.f13.f64 = double(float(ctx.f4.f64 * f0.f64));
	// stfs f13,-28(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// fmuls f12,f3,f0
	ctx.f12.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfs f12,-32(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// fmuls f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 * f0.f64));
	// stfs f11,-20(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// rlwinm r4,r10,24,24,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF;
	// rlwinm r11,r10,8,24,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFF;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// std r11,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r11.u64);
	// lfd f10,-32(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// std r8,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r8.u64);
	// rlwinm r9,r10,16,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFF;
	// lfd f8,-32(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// std r11,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r11.u64);
	// lfd f7,-32(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// std r9,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r9.u64);
	// lfd f9,-48(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// fcfid f3,f10
	ctx.f3.f64 = double(ctx.f10.s64);
	// frsp f12,f3
	ctx.f12.f64 = double(float(ctx.f3.f64));
	// fcfid f5,f8
	ctx.f5.f64 = double(ctx.f8.s64);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// fcfid f4,f9
	ctx.f4.f64 = double(ctx.f9.s64);
	// fmuls f8,f12,f0
	ctx.f8.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f8,-20(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// frsp f1,f5
	ctx.f1.f64 = double(float(ctx.f5.f64));
	// frsp f2,f6
	ctx.f2.f64 = double(float(ctx.f6.f64));
	// frsp f13,f4
	ctx.f13.f64 = double(float(ctx.f4.f64));
	// fmuls f10,f1,f0
	ctx.f10.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfs f10,-28(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// fmuls f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 * f0.f64));
	// stfs f11,-24(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// fmuls f9,f13,f0
	ctx.f9.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f9,-32(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// rlwinm r7,r10,24,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF;
	// rlwinm r5,r10,16,24,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFF;
	// std r7,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r7.u64);
	// lfd f7,-32(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// std r5,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r5.u64);
	// lfd f6,-32(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// fcfid f3,f7
	ctx.f3.f64 = double(ctx.f7.s64);
	// std r11,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, r11.u64);
	// lfd f4,-32(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// rlwinm r10,r10,8,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFF;
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// addi r9,r1,-32
	ctx.r9.s64 = ctx.r1.s64 + -32;
	// std r10,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r10.u64);
	// lfd f1,-32(r1)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f13,f1
	ctx.f13.f64 = double(ctx.f1.s64);
	// fcfid f12,f4
	ctx.f12.f64 = double(ctx.f4.s64);
	// frsp f2,f5
	ctx.f2.f64 = double(float(ctx.f5.f64));
	// frsp f11,f3
	ctx.f11.f64 = double(float(ctx.f3.f64));
	// frsp f10,f13
	ctx.f10.f64 = double(float(ctx.f13.f64));
	// frsp f8,f12
	ctx.f8.f64 = double(float(ctx.f12.f64));
	// fmuls f9,f2,f0
	ctx.f9.f64 = double(float(ctx.f2.f64 * f0.f64));
	// stfs f9,-32(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// fmuls f7,f11,f0
	ctx.f7.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f7,-28(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// fmuls f6,f10,f0
	ctx.f6.f64 = double(float(ctx.f10.f64 * f0.f64));
	// stfs f6,-20(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// fmuls f5,f8,f0
	ctx.f5.f64 = double(float(ctx.f8.f64 * f0.f64));
	// stfs f5,-24(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8230A63C"))) PPC_WEAK_FUNC(sub_8230A63C);
PPC_FUNC_IMPL(__imp__sub_8230A63C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230A640"))) PPC_WEAK_FUNC(sub_8230A640);
PPC_FUNC_IMPL(__imp__sub_8230A640) {
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
	// beq cr6,0x8230a680
	if (cr6.eq) goto loc_8230A680;
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82178a48
	ctx.lr = 0x8230A670;
	sub_82178A48(ctx, base);
	// addi r10,r30,4
	ctx.r10.s64 = r30.s64 + 4;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// b 0x8230a684
	goto loc_8230A684;
loc_8230A680:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8230A684:
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

__attribute__((alias("__imp__sub_8230A69C"))) PPC_WEAK_FUNC(sub_8230A69C);
PPC_FUNC_IMPL(__imp__sub_8230A69C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230A6A0"))) PPC_WEAK_FUNC(sub_8230A6A0);
PPC_FUNC_IMPL(__imp__sub_8230A6A0) {
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
	ctx.lr = 0x8230A6A8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,-12140(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + -12140);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r11,1(r31)
	PPC_STORE_U8(r31.u32 + 1, r11.u8);
	// bne cr6,0x8230a6d4
	if (!cr6.eq) goto loc_8230A6D4;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8230A6D4:
	// li r11,0
	r11.s64 = 0;
	// addi r29,r31,8
	r29.s64 = r31.s64 + 8;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82178f38
	ctx.lr = 0x8230A6E8;
	sub_82178F38(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x8230a770
	if (!cr6.eq) goto loc_8230A770;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r30,r11,-12148
	r30.s64 = r11.s64 + -12148;
	// lwz r11,-12148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8230a720
	if (!cr6.eq) goto loc_8230A720;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r3,12288
	ctx.r3.s64 = 12288;
	// bl 0x82178a10
	ctx.lr = 0x8230A720;
	sub_82178A10(ctx, base);
loc_8230A720:
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8230a640
	ctx.lr = 0x8230A72C;
	sub_8230A640(ctx, base);
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-12144(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12144);
	// subf r11,r3,r11
	r11.s64 = r11.s64 - ctx.r3.s64;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// stw r11,-12144(r9)
	PPC_STORE_U32(ctx.r9.u32 + -12144, r11.u32);
	// bl 0x82179c20
	ctx.lr = 0x8230A750;
	sub_82179C20(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x8217f768
	ctx.lr = 0x8230A75C;
	sub_8217F768(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r8,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r8.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8230A770:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8230A77C"))) PPC_WEAK_FUNC(sub_8230A77C);
PPC_FUNC_IMPL(__imp__sub_8230A77C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230A780"))) PPC_WEAK_FUNC(sub_8230A780);
PPC_FUNC_IMPL(__imp__sub_8230A780) {
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
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8230a7fc
	if (cr6.eq) goto loc_8230A7FC;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82179d38
	ctx.lr = 0x8230A7B4;
	sub_82179D38(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8230a7d8
	if (!cr6.eq) goto loc_8230A7D8;
	// li r11,0
	r11.s64 = 0;
	// stb r11,1(r31)
	PPC_STORE_U8(r31.u32 + 1, r11.u8);
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
loc_8230A7D8:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.r3.u32);
	// lwz r11,-12144(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12144);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stw r11,-12144(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12144, r11.u32);
loc_8230A7FC:
	// lbz r11,1(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8230a820
	if (cr6.eq) goto loc_8230A820;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x82178ac8
	ctx.lr = 0x8230A820;
	sub_82178AC8(ctx, base);
loc_8230A820:
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

__attribute__((alias("__imp__sub_8230A834"))) PPC_WEAK_FUNC(sub_8230A834);
PPC_FUNC_IMPL(__imp__sub_8230A834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230A838"))) PPC_WEAK_FUNC(sub_8230A838);
PPC_FUNC_IMPL(__imp__sub_8230A838) {
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
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8230aa28
	if (!cr6.eq) goto loc_8230AA28;
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r3,r11,-11920
	ctx.r3.s64 = r11.s64 + -11920;
	// lwz r11,-11752(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -11752);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8230a99c
	if (!cr6.eq) goto loc_8230A99C;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r11,-11752(r9)
	PPC_STORE_U32(ctx.r9.u32 + -11752, r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r5,r10,-16224
	ctx.r5.s64 = ctx.r10.s64 + -16224;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// li r8,6
	ctx.r8.s64 = 6;
	// stw r9,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r9.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,24(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// li r11,0
	r11.s64 = 0;
	// sth r9,52(r3)
	PPC_STORE_U16(ctx.r3.u32 + 52, ctx.r9.u16);
	// li r9,9
	ctx.r9.s64 = 9;
	// stw r8,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r8.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r9,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, ctx.r9.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r8,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r8.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// li r10,9
	ctx.r10.s64 = 9;
	// stw r8,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r8.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r10,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, ctx.r10.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, ctx.r9.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,64(r3)
	PPC_STORE_U32(ctx.r3.u32 + 64, ctx.r10.u32);
	// stw r10,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, ctx.r10.u32);
	// stw r8,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r8.u32);
	// li r8,9
	ctx.r8.s64 = 9;
	// stw r10,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r10.u32);
	// li r10,9
	ctx.r10.s64 = 9;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lwz r11,36(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 36);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r9,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, ctx.r9.u32);
	// stw r8,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r8.u32);
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r10,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, ctx.r10.u32);
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r9,132(r3)
	PPC_STORE_U32(ctx.r3.u32 + 132, ctx.r9.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// sth r6,24(r3)
	PPC_STORE_U16(ctx.r3.u32 + 24, ctx.r6.u16);
	// li r6,5
	ctx.r6.s64 = 5;
	// stw r8,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, ctx.r8.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r10,144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 144, ctx.r10.u32);
	// li r10,9
	ctx.r10.s64 = 9;
	// stw r9,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r9.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r11.u32);
	// stw r11,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, r11.u32);
	// stw r11,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, r11.u32);
	// stw r11,152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 152, r11.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r7,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r7.u32);
	// stw r7,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r7.u32);
	// stw r6,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, ctx.r6.u32);
	// sth r7,80(r3)
	PPC_STORE_U16(ctx.r3.u32 + 80, ctx.r7.u16);
	// stw r6,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r6.u32);
	// sth r7,108(r3)
	PPC_STORE_U16(ctx.r3.u32 + 108, ctx.r7.u16);
	// stw r5,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r5.u32);
	// stw r6,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, ctx.r6.u32);
	// sth r7,136(r3)
	PPC_STORE_U16(ctx.r3.u32 + 136, ctx.r7.u16);
	// stw r8,140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 140, ctx.r8.u32);
	// stw r10,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, ctx.r10.u32);
	// stw r9,160(r3)
	PPC_STORE_U32(ctx.r3.u32 + 160, ctx.r9.u32);
	// sth r11,164(r3)
	PPC_STORE_U16(ctx.r3.u32 + 164, r11.u16);
loc_8230A99C:
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8217aac0
	ctx.lr = 0x8230A9A4;
	sub_8217AAC0(ctx, base);
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// addi r31,r30,40
	r31.s64 = r30.s64 + 40;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,6
	ctx.r5.s64 = 6;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821902b0
	ctx.lr = 0x8230A9C0;
	sub_821902B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,9
	ctx.r5.s64 = 9;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82190540
	ctx.lr = 0x8230A9D0;
	sub_82190540(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r6,9
	ctx.r6.s64 = 9;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82190640
	ctx.lr = 0x8230A9E4;
	sub_82190640(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r6,9
	ctx.r6.s64 = 9;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82190640
	ctx.lr = 0x8230A9F8;
	sub_82190640(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r6,9
	ctx.r6.s64 = 9;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x82190640
	ctx.lr = 0x8230AA0C;
	sub_82190640(ctx, base);
	// li r6,9
	ctx.r6.s64 = 9;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82190640
	ctx.lr = 0x8230AA20;
	sub_82190640(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
loc_8230AA28:
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

__attribute__((alias("__imp__sub_8230AA40"))) PPC_WEAK_FUNC(sub_8230AA40);
PPC_FUNC_IMPL(__imp__sub_8230AA40) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,12368
	ctx.r4.s64 = r11.s64 + 12368;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8230AA70;
	sub_8218A568(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r4,r10,12360
	ctx.r4.s64 = ctx.r10.s64 + 12360;
	// bl 0x8218a568
	ctx.lr = 0x8230AA88;
	sub_8218A568(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,12344
	ctx.r4.s64 = ctx.r9.s64 + 12344;
	// bl 0x8218a568
	ctx.lr = 0x8230AAA0;
	sub_8218A568(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,12336
	ctx.r4.s64 = ctx.r8.s64 + 12336;
	// bl 0x8218a568
	ctx.lr = 0x8230AAB8;
	sub_8218A568(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r7,12328
	ctx.r4.s64 = ctx.r7.s64 + 12328;
	// bl 0x8218a568
	ctx.lr = 0x8230AAD0;
	sub_8218A568(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,12316
	ctx.r4.s64 = ctx.r6.s64 + 12316;
	// bl 0x8218a568
	ctx.lr = 0x8230AAE8;
	sub_8218A568(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,12300
	ctx.r4.s64 = ctx.r4.s64 + 12300;
	// bl 0x8218a568
	ctx.lr = 0x8230AB00;
	sub_8218A568(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8230AB1C"))) PPC_WEAK_FUNC(sub_8230AB1C);
PPC_FUNC_IMPL(__imp__sub_8230AB1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230AB20"))) PPC_WEAK_FUNC(sub_8230AB20);
PPC_FUNC_IMPL(__imp__sub_8230AB20) {
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
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8230ab70
	if (cr6.eq) goto loc_8230AB70;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8230AB54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r9.u32);
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
loc_8230AB70:
	// li r11,0
	r11.s64 = 0;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
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

__attribute__((alias("__imp__sub_8230AB8C"))) PPC_WEAK_FUNC(sub_8230AB8C);
PPC_FUNC_IMPL(__imp__sub_8230AB8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230AB90"))) PPC_WEAK_FUNC(sub_8230AB90);
PPC_FUNC_IMPL(__imp__sub_8230AB90) {
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
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// beq cr6,0x8230abf8
	if (cr6.eq) goto loc_8230ABF8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82187f40
	ctx.lr = 0x8230ABC4;
	sub_82187F40(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// beq cr6,0x8230abdc
	if (cr6.eq) goto loc_8230ABDC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82187b88
	ctx.lr = 0x8230ABD8;
	sub_82187B88(ctx, base);
	// b 0x8230ac04
	goto loc_8230AC04;
loc_8230ABDC:
	// bl 0x82187bd0
	ctx.lr = 0x8230ABE0;
	sub_82187BD0(ctx, base);
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
loc_8230ABF8:
	// bl 0x82187ba8
	ctx.lr = 0x8230ABFC;
	sub_82187BA8(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82187bd0
	ctx.lr = 0x8230AC04;
	sub_82187BD0(ctx, base);
loc_8230AC04:
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

__attribute__((alias("__imp__sub_8230AC1C"))) PPC_WEAK_FUNC(sub_8230AC1C);
PPC_FUNC_IMPL(__imp__sub_8230AC1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230AC20"))) PPC_WEAK_FUNC(sub_8230AC20);
PPC_FUNC_IMPL(__imp__sub_8230AC20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,12(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,112
	cr6.compare<uint32_t>(r11.u32, 112, xer);
	// bne cr6,0x8230ac44
	if (!cr6.eq) goto loc_8230AC44;
	// lbz r11,13(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// cmplwi cr6,r11,97
	cr6.compare<uint32_t>(r11.u32, 97, xer);
	// bne cr6,0x8230ac44
	if (!cr6.eq) goto loc_8230AC44;
	// lbz r11,14(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 14);
	// cmplwi cr6,r11,108
	cr6.compare<uint32_t>(r11.u32, 108, xer);
	// beq cr6,0x8230ac68
	if (cr6.eq) goto loc_8230AC68;
loc_8230AC44:
	// lbz r11,17(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 17);
	// cmplwi cr6,r11,112
	cr6.compare<uint32_t>(r11.u32, 112, xer);
	// bne cr6,0x8230ac74
	if (!cr6.eq) goto loc_8230AC74;
	// lbz r11,18(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 18);
	// cmplwi cr6,r11,97
	cr6.compare<uint32_t>(r11.u32, 97, xer);
	// bne cr6,0x8230ac74
	if (!cr6.eq) goto loc_8230AC74;
	// lbz r11,19(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 19);
	// cmplwi cr6,r11,108
	cr6.compare<uint32_t>(r11.u32, 108, xer);
	// bne cr6,0x8230ac74
	if (!cr6.eq) goto loc_8230AC74;
loc_8230AC68:
	// li r11,1
	r11.s64 = 1;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
loc_8230AC74:
	// li r11,0
	r11.s64 = 0;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8230AC80"))) PPC_WEAK_FUNC(sub_8230AC80);
PPC_FUNC_IMPL(__imp__sub_8230AC80) {
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
	ctx.lr = 0x8230AC88;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// lwz r3,-17600(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -17600);
	// lis r31,-256
	r31.s64 = -16777216;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8230acdc
	if (cr6.eq) goto loc_8230ACDC;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lbz r10,-17596(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -17596);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8230acdc
	if (cr6.eq) goto loc_8230ACDC;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x82689ee8
	ctx.lr = 0x8230ACCC;
	sub_82689EE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8230acdc
	if (cr6.eq) goto loc_8230ACDC;
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_8230ACDC:
	// li r11,-1
	r11.s64 = -1;
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8230acf8
	if (cr6.eq) goto loc_8230ACF8;
	// stw r31,12(r27)
	PPC_STORE_U32(r27.u32 + 12, r31.u32);
loc_8230ACF8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8230AD00"))) PPC_WEAK_FUNC(sub_8230AD00);
PPC_FUNC_IMPL(__imp__sub_8230AD00) {
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
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8230AD08;
	// lis r31,-32119
	r31.s64 = -2104950784;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r28,r11,-11696
	r28.s64 = r11.s64 + -11696;
	// lwz r11,-11680(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -11680);
	// clrlwi r30,r11,31
	r30.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8230ad3c
	if (!cr6.eq) goto loc_8230AD3C;
	// lis r30,-32252
	r30.s64 = -2113667072;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// addi r30,r30,12432
	r30.s64 = r30.s64 + 12432;
	// stw r11,-11680(r31)
	PPC_STORE_U32(r31.u32 + -11680, r11.u32);
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8230AD3C:
	// rlwinm r29,r11,0,30,30
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// lis r30,-32119
	r30.s64 = -2104950784;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// addi r27,r30,-11712
	r27.s64 = r30.s64 + -11712;
	// bne cr6,0x8230ad68
	if (!cr6.eq) goto loc_8230AD68;
	// lis r30,-32252
	r30.s64 = -2113667072;
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// addi r30,r30,12416
	r30.s64 = r30.s64 + 12416;
	// stw r11,-11680(r31)
	PPC_STORE_U32(r31.u32 + -11680, r11.u32);
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8230AD68:
	// rlwinm r29,r11,0,29,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// lis r30,-32119
	r30.s64 = -2104950784;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// addi r29,r30,-11728
	r29.s64 = r30.s64 + -11728;
	// bne cr6,0x8230ad94
	if (!cr6.eq) goto loc_8230AD94;
	// lis r30,-32252
	r30.s64 = -2113667072;
	// ori r11,r11,4
	r11.u64 = r11.u64 | 4;
	// addi r30,r30,12400
	r30.s64 = r30.s64 + 12400;
	// stw r11,-11680(r31)
	PPC_STORE_U32(r31.u32 + -11680, r11.u32);
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8230AD94:
	// rlwinm r26,r11,0,28,28
	r26.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// lis r30,-32119
	r30.s64 = -2104950784;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// addi r30,r30,-11744
	r30.s64 = r30.s64 + -11744;
	// bne cr6,0x8230adc0
	if (!cr6.eq) goto loc_8230ADC0;
	// lis r26,-32252
	r26.s64 = -2113667072;
	// ori r11,r11,8
	r11.u64 = r11.u64 | 8;
	// addi r26,r26,12384
	r26.s64 = r26.s64 + 12384;
	// stw r11,-11680(r31)
	PPC_STORE_U32(r31.u32 + -11680, r11.u32);
	// lvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8230ADC0:
	// lvx128 v0,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,80
	r11.s64 = 80;
	// li r6,64
	ctx.r6.s64 = 64;
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	f0.f64 = double(temp.f32);
	// lis r31,-32256
	r31.s64 = -2113929216;
	// lfs f13,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r26,r1,-80
	r26.s64 = ctx.r1.s64 + -80;
	// stfs f0,-80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// lfs f12,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v13,r3,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r3,r6
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// lfs f0,3796(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,-68(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -68, temp.u32);
	// stfs f13,-76(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// stfs f12,-72(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -72, temp.u32);
	// lvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v11,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r29
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v10,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v9,v10,v13,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v9,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r27
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v8,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v7,v8,v13,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v7,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8230AE38"))) PPC_WEAK_FUNC(sub_8230AE38);
PPC_FUNC_IMPL(__imp__sub_8230AE38) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x8230ad00
	ctx.lr = 0x8230AE6C;
	sub_8230AD00(ctx, base);
	// lfs f12,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// fdivs f9,f0,f10
	ctx.f9.f64 = double(float(f0.f64 / ctx.f10.f64));
	// fmuls f8,f12,f9
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f9.f64));
	// fneg f11,f9
	ctx.f11.u64 = ctx.f9.u64 ^ 0x8000000000000000;
	// fneg f7,f8
	ctx.f7.u64 = ctx.f8.u64 ^ 0x8000000000000000;
	// fsubs f10,f0,f7
	ctx.f10.f64 = double(float(f0.f64 - ctx.f7.f64));
	// bge cr6,0x8230aeb4
	if (!cr6.lt) goto loc_8230AEB4;
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x8230aeb4
	if (!cr6.lt) goto loc_8230AEB4;
	// fmr f11,f13
	ctx.f11.f64 = ctx.f13.f64;
	// fmr f10,f0
	ctx.f10.f64 = f0.f64;
loc_8230AEB4:
	// stfs f11,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// stfs f10,108(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-12152(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12152);
	// bl 0x8218aef8
	ctx.lr = 0x8230AED4;
	sub_8218AEF8(ctx, base);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,-12172(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12172);
	// bl 0x8218aef8
	ctx.lr = 0x8230AEEC;
	sub_8218AEF8(ctx, base);
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,-12160(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12160);
	// bl 0x8218aef8
	ctx.lr = 0x8230AF04;
	sub_8218AEF8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8230AF14"))) PPC_WEAK_FUNC(sub_8230AF14);
PPC_FUNC_IMPL(__imp__sub_8230AF14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230AF18"))) PPC_WEAK_FUNC(sub_8230AF18);
PPC_FUNC_IMPL(__imp__sub_8230AF18) {
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
	// lis r11,-32119
	r11.s64 = -2104950784;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r31,-12112(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -12112);
	// stb r10,56(r31)
	PPC_STORE_U8(r31.u32 + 56, ctx.r10.u8);
	// bl 0x82177c50
	ctx.lr = 0x8230AF44;
	sub_82177C50(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8230af58
	if (cr6.eq) goto loc_8230AF58;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82177c50
	ctx.lr = 0x8230AF58;
	sub_82177C50(ctx, base);
loc_8230AF58:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82178430
	ctx.lr = 0x8230AF60;
	sub_82178430(ctx, base);
	// lis r31,-32119
	r31.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-12128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12128);
	// bl 0x8230ab90
	ctx.lr = 0x8230AF70;
	sub_8230AB90(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r31,-12128(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + -12128);
	// lwz r30,-25360(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -25360);
	// addi r11,r31,20
	r11.s64 = r31.s64 + 20;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8230AF98;
	sub_82189CE0(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8230AFB0;
	sub_82189CE0(ctx, base);
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

__attribute__((alias("__imp__sub_8230AFC8"))) PPC_WEAK_FUNC(sub_8230AFC8);
PPC_FUNC_IMPL(__imp__sub_8230AFC8) {
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
	// lwz r11,144(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x8230b05c
	if (!cr6.gt) goto loc_8230B05C;
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8230affc
	if (cr6.eq) goto loc_8230AFFC;
	// lfs f13,132(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// b 0x8230b000
	goto loc_8230B000;
loc_8230AFFC:
	// lfs f13,136(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	ctx.f13.f64 = double(temp.f32);
loc_8230B000:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r11,r11,12276
	r11.s64 = r11.s64 + 12276;
	// beq cr6,0x8230b018
	if (cr6.eq) goto loc_8230B018;
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// b 0x8230b020
	goto loc_8230B020;
loc_8230B018:
	// lfs f0,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
loc_8230B020:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8230b0e0
	if (cr6.eq) goto loc_8230B0E0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f12,-12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fnmsubs f12,f0,f12,f13
	ctx.f12.f64 = double(float(-(f0.f64 * ctx.f12.f64 - ctx.f13.f64)));
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f13,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 / f0.f64));
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f10,88(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// b 0x8230b100
	goto loc_8230B100;
loc_8230B05C:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// addi r11,r11,12276
	r11.s64 = r11.s64 + 12276;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f12,-12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f12,f1
	f0.f64 = double(float(ctx.f12.f64 - ctx.f1.f64));
	// fsel f13,f0,f1,f12
	ctx.f13.f64 = f0.f64 >= 0.0 ? ctx.f1.f64 : ctx.f12.f64;
	// beq cr6,0x8230b084
	if (cr6.eq) goto loc_8230B084;
	// lfs f0,132(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	f0.f64 = double(temp.f32);
	// b 0x8230b088
	goto loc_8230B088;
loc_8230B084:
	// lfs f0,136(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	f0.f64 = double(temp.f32);
loc_8230B088:
	// fmuls f13,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f0.f64 * ctx.f13.f64));
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8230b09c
	if (cr6.eq) goto loc_8230B09C;
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// b 0x8230b0a4
	goto loc_8230B0A4;
loc_8230B09C:
	// lfs f0,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
loc_8230B0A4:
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8230b0e0
	if (cr6.eq) goto loc_8230B0E0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fnmsubs f12,f0,f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(-(f0.f64 * ctx.f12.f64 - ctx.f13.f64)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f13,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 / f0.f64));
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f10,88(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// b 0x8230b100
	goto loc_8230B100;
loc_8230B0E0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsubs f12,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f13,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 / f0.f64));
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
loc_8230B100:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-12164(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12164);
	// bl 0x8218aef8
	ctx.lr = 0x8230B118;
	sub_8218AEF8(ctx, base);
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8230B12C"))) PPC_WEAK_FUNC(sub_8230B12C);
PPC_FUNC_IMPL(__imp__sub_8230B12C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230B130"))) PPC_WEAK_FUNC(sub_8230B130);
PPC_FUNC_IMPL(__imp__sub_8230B130) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r11,r11,-11964
	r11.s64 = r11.s64 + -11964;
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x8230b150
	if (cr6.gt) goto loc_8230B150;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8230B150:
	// lfs f12,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x8230b164
	if (!cr6.gt) goto loc_8230B164;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_8230B164:
	// lfs f12,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// li r11,2
	r11.s64 = 2;
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bgt cr6,0x8230b178
	if (cr6.gt) goto loc_8230B178;
	// li r11,0
	r11.s64 = 0;
loc_8230B178:
	// lfs f13,8(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8230b188
	if (!cr6.gt) goto loc_8230B188;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_8230B188:
	// subf r3,r11,r10
	ctx.r3.s64 = ctx.r10.s64 - r11.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8230B190"))) PPC_WEAK_FUNC(sub_8230B190);
PPC_FUNC_IMPL(__imp__sub_8230B190) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,22080(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 22080);
	// lwz r3,-17628(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -17628);
	// bl 0x82175238
	ctx.lr = 0x8230B1C0;
	sub_82175238(ctx, base);
	// lis r8,1024
	ctx.r8.s64 = 67108864;
	// rlwinm r7,r3,0,5,5
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4000000;
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// beq cr6,0x8230b1e4
	if (cr6.eq) goto loc_8230B1E4;
	// rlwinm r11,r3,0,3,3
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10000000;
	// lis r10,4096
	ctx.r10.s64 = 268435456;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x8230b1e8
	if (!cr6.eq) goto loc_8230B1E8;
loc_8230B1E4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8230B1E8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8230B1F8"))) PPC_WEAK_FUNC(sub_8230B1F8);
PPC_FUNC_IMPL(__imp__sub_8230B1F8) {
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
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8230B200;
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-64
	r12.s64 = -64;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// vmulfp128 v127,v1,v1
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v127.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v1.f32)));
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r9,112
	ctx.r9.s64 = 112;
	// clrlwi r8,r4,24
	ctx.r8.u64 = ctx.r4.u32 & 0xFF;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r30,-12100(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -12100);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r11,-26876(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -26876);
	// lwz r10,208(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// lvx128 v126,r11,r9
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x8230b2e0
	if (!cr6.eq) goto loc_8230B2E0;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// vcmpgtfp128. v62,v1,v63
	simde_mm_store_ps(v62.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v62.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r9,r11,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8230b2e0
	if (cr6.eq) goto loc_8230B2E0;
	// lhz r31,10(r28)
	r31.u64 = PPC_LOAD_U16(r28.u32 + 10);
	// lhz r11,12(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 12);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bgt cr6,0x8230b328
	if (cr6.gt) goto loc_8230B328;
	// rlwinm r11,r31,5,0,26
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 5) & 0xFFFFFFE0;
	// lis r27,-32131
	r27.s64 = -2105737216;
	// add r29,r11,r10
	r29.u64 = r11.u64 + ctx.r10.u64;
loc_8230B278:
	// lvx128 v61,r0,r29
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v60,v61,v126
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v126.f32)));
	// vmsum3fp128 v59,v60,v60
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vcmpgefp128. v58,v59,v127
	simde_mm_store_ps(v58.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v127.f32)));
	cr6.setFromMask(simde_mm_load_ps(v58.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8230b2c8
	if (cr6.eq) goto loc_8230B2C8;
	// lwz r11,212(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8230b2b0
	if (cr6.eq) goto loc_8230B2B0;
	// lwz r10,11724(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 11724);
	// stw r10,156(r11)
	PPC_STORE_U32(r11.u32 + 156, ctx.r10.u32);
	// b 0x8230b2b8
	goto loc_8230B2B8;
loc_8230B2B0:
	// lwz r11,11724(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 11724);
	// stw r11,156(r30)
	PPC_STORE_U32(r30.u32 + 156, r11.u32);
loc_8230B2B8:
	// li r5,4
	ctx.r5.s64 = 4;
	// rlwinm r4,r31,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x821795f8
	ctx.lr = 0x8230B2C8;
	sub_821795F8(ctx, base);
loc_8230B2C8:
	// lhz r11,12(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 12);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r29,r29,32
	r29.s64 = r29.s64 + 32;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// ble cr6,0x8230b278
	if (!cr6.gt) goto loc_8230B278;
	// b 0x8230b328
	goto loc_8230B328;
loc_8230B2E0:
	// lwz r11,212(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 212);
	// lhz r8,12(r28)
	ctx.r8.u64 = PPC_LOAD_U16(r28.u32 + 12);
	// lhz r10,10(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8230b304
	if (cr6.eq) goto loc_8230B304;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lwz r9,11724(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11724);
	// stw r9,156(r11)
	PPC_STORE_U32(r11.u32 + 156, ctx.r9.u32);
	// b 0x8230b310
	goto loc_8230B310;
loc_8230B304:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,11724(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 11724);
	// stw r11,156(r30)
	PPC_STORE_U32(r30.u32 + 156, r11.u32);
loc_8230B310:
	// subf r11,r10,r8
	r11.s64 = ctx.r8.s64 - ctx.r10.s64;
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// li r3,6
	ctx.r3.s64 = 6;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x821795f8
	ctx.lr = 0x8230B328;
	sub_821795F8(ctx, base);
loc_8230B328:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-64
	r0.s64 = -64;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8230B340"))) PPC_WEAK_FUNC(sub_8230B340);
PPC_FUNC_IMPL(__imp__sub_8230B340) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// rlwinm r11,r31,3,0,28
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r3,r11,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x82130528
	ctx.lr = 0x8230B364;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8230b390
	if (!cr6.gt) goto loc_8230B390;
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8230B374:
	// addic. r9,r11,-16
	xer.ca = r11.u32 > 15;
	ctx.r9.s64 = r11.s64 + -16;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x8230b384
	if (cr0.eq) goto loc_8230B384;
	// sth r10,-2(r11)
	PPC_STORE_U16(r11.u32 + -2, ctx.r10.u16);
	// sth r10,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r10.u16);
loc_8230B384:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,18
	r11.s64 = r11.s64 + 18;
	// bne 0x8230b374
	if (!cr0.eq) goto loc_8230B374;
loc_8230B390:
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

__attribute__((alias("__imp__sub_8230B3A4"))) PPC_WEAK_FUNC(sub_8230B3A4);
PPC_FUNC_IMPL(__imp__sub_8230B3A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230B3A8"))) PPC_WEAK_FUNC(sub_8230B3A8);
PPC_FUNC_IMPL(__imp__sub_8230B3A8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x8230b400
	if (cr6.eq) goto loc_8230B400;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8230b3f8
	if (cr6.eq) goto loc_8230B3F8;
	// bl 0x8230b340
	ctx.lr = 0x8230B3F0;
	sub_8230B340(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// b 0x8230b400
	goto loc_8230B400;
loc_8230B3F8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_8230B400:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8230b45c
	if (cr6.eq) goto loc_8230B45C;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8230B410:
	// rlwinm r11,r10,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r8,9
	ctx.r8.s64 = 9;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// add r11,r7,r11
	r11.u64 = ctx.r7.u64 + r11.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_8230B434:
	// lhz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// sth r8,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r8.u16);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// bdnz 0x8230b434
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8230B434;
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// blt cr6,0x8230b410
	if (cr6.lt) goto loc_8230B410;
loc_8230B45C:
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

__attribute__((alias("__imp__sub_8230B474"))) PPC_WEAK_FUNC(sub_8230B474);
PPC_FUNC_IMPL(__imp__sub_8230B474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230B478"))) PPC_WEAK_FUNC(sub_8230B478);
PPC_FUNC_IMPL(__imp__sub_8230B478) {
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
	ctx.lr = 0x8230B48C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8230b4ac
	if (cr6.eq) goto loc_8230B4AC;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8230B4AC:
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

__attribute__((alias("__imp__sub_8230B4C0"))) PPC_WEAK_FUNC(sub_8230B4C0);
PPC_FUNC_IMPL(__imp__sub_8230B4C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-12136(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12136);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8230B4CC"))) PPC_WEAK_FUNC(sub_8230B4CC);
PPC_FUNC_IMPL(__imp__sub_8230B4CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230B4D0"))) PPC_WEAK_FUNC(sub_8230B4D0);
PPC_FUNC_IMPL(__imp__sub_8230B4D0) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x823d91e8
	ctx.lr = 0x8230B4D8;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// fmuls f11,f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64 * ctx.f1.f64));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r11,168(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 168);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// lfs f12,148(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 148);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lis r26,-32256
	r26.s64 = -2113929216;
	// lfs f0,14884(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14884);
	f0.f64 = double(temp.f32);
	// addi r25,r1,112
	r25.s64 = ctx.r1.s64 + 112;
	// addi r24,r1,128
	r24.s64 = ctx.r1.s64 + 128;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lvx128 v62,r11,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// clrlwi r9,r7,24
	ctx.r9.u64 = ctx.r7.u32 & 0xFF;
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v57,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_add_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// vsubfp128 v55,v61,v62
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v60,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v56,v60,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vmulfp128 v54,v57,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v56.f32)));
	// lvlx128 v59,r0,r28
	temp.u32 = r28.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v58,v59,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// vmulfp128 v53,v55,v58
	simde_mm_store_ps(v53.f32, simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v58.f32)));
	// vspltw128 v52,v54,1
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xAA));
	// lfs f0,7444(r26)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 7444);
	f0.f64 = double(temp.f32);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// lfs f13,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// xori r28,r7,1
	r28.u64 = ctx.r7.u64 ^ 1;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// rlwinm r11,r28,4,0,27
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// stvx128 v52,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r5,8(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// add r6,r11,r29
	ctx.r6.u64 = r11.u64 + r29.u64;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// vspltw128 v51,v53,1
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xAA));
	// stvx128 v51,r0,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8218a6e0
	ctx.lr = 0x8230B5C0;
	sub_8218A6E0(ctx, base);
	// addi r6,r28,2
	ctx.r6.s64 = r28.s64 + 2;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,12(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// rlwinm r11,r6,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// add r6,r11,r29
	ctx.r6.u64 = r11.u64 + r29.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x8230B5E8;
	sub_8218A6E0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r9,4
	ctx.r9.s64 = 4;
	// lwz r5,16(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// bl 0x8218a6e0
	ctx.lr = 0x8230B608;
	sub_8218A6E0(ctx, base);
	// lwz r5,20(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// bl 0x8218a6e0
	ctx.lr = 0x8230B628;
	sub_8218A6E0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r9,4
	ctx.r9.s64 = 4;
	// lwz r5,24(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// bl 0x8218a6e0
	ctx.lr = 0x8230B648;
	sub_8218A6E0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r9,3
	ctx.r9.s64 = 3;
	// lwz r5,28(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r7,8
	ctx.r7.s64 = 8;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// bl 0x8218a6e0
	ctx.lr = 0x8230B668;
	sub_8218A6E0(ctx, base);
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r4,-7572(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + -7572);
	// bl 0x822f32f0
	ctx.lr = 0x8230B678;
	sub_822F32F0(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r5,32(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 32);
	// li r9,4
	ctx.r9.s64 = 4;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x8230B698;
	sub_8218A6E0(ctx, base);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// addi r3,r4,-31280
	ctx.r3.s64 = ctx.r4.s64 + -31280;
	// bl 0x8217d918
	ctx.lr = 0x8230B6A4;
	sub_8217D918(ctx, base);
	// stw r29,60(r27)
	PPC_STORE_U32(r27.u32 + 60, r29.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8230B6B0"))) PPC_WEAK_FUNC(sub_8230B6B0);
PPC_FUNC_IMPL(__imp__sub_8230B6B0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8230B6B8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8230b710
	if (cr6.eq) goto loc_8230B710;
	// li r29,0
	r29.s64 = 0;
loc_8230B6E0:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwzx r10,r11,r29
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x823db730
	ctx.lr = 0x8230B6F4;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8230b748
	if (cr6.eq) goto loc_8230B748;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8230b6e0
	if (cr6.lt) goto loc_8230B6E0;
loc_8230B710:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r11,12784
	ctx.r4.s64 = r11.s64 + 12784;
	// bl 0x823d90b0
	ctx.lr = 0x8230B720;
	sub_823D90B0(ctx, base);
	// subfic r10,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	ctx.r10.s64 = 0 - ctx.r3.s64;
	// li r9,3
	ctx.r9.s64 = 3;
	// subfe r8,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// rlwinm r11,r11,0,31,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF9;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r7,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r7.u32);
	// stw r9,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r9.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8230B748:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r8,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r8.u32);
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r6,r7,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stw r5,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r5.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8230B774"))) PPC_WEAK_FUNC(sub_8230B774);
PPC_FUNC_IMPL(__imp__sub_8230B774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230B778"))) PPC_WEAK_FUNC(sub_8230B778);
PPC_FUNC_IMPL(__imp__sub_8230B778) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x8230B780;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,-12072
	ctx.r10.s64 = r11.s64 + -12072;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8230b9a4
	if (!cr6.eq) goto loc_8230B9A4;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82180430
	ctx.lr = 0x8230B7A8;
	sub_82180430(ctx, base);
	// lis r27,-32119
	r27.s64 = -2104950784;
	// li r25,1
	r25.s64 = 1;
	// li r30,0
	r30.s64 = 0;
	// li r24,2
	r24.s64 = 2;
	// stb r25,97(r1)
	PPC_STORE_U8(ctx.r1.u32 + 97, r25.u8);
	// li r11,4
	r11.s64 = 4;
	// stb r25,98(r1)
	PPC_STORE_U8(ctx.r1.u32 + 98, r25.u8);
	// lwz r3,-12120(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -12120);
	// lis r26,-32124
	r26.s64 = -2105278464;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stw r24,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r24.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// stw r30,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r30.u32);
	// bne cr6,0x8230b81c
	if (!cr6.eq) goto loc_8230B81C;
	// lwz r3,-25232(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -25232);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stb r30,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r30.u8);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,12848
	ctx.r4.s64 = r11.s64 + 12848;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r7,256
	ctx.r7.s64 = 256;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,256
	ctx.r6.s64 = 256;
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r11,56(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8230B818;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,-12120(r27)
	PPC_STORE_U32(r27.u32 + -12120, ctx.r3.u32);
loc_8230B81C:
	// lis r28,-32119
	r28.s64 = -2104950784;
	// lwz r11,-12112(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -12112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8230b87c
	if (!cr6.eq) goto loc_8230B87C;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8230B834;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8230b858
	if (cr6.eq) goto loc_8230B858;
	// addi r3,r29,40
	ctx.r3.s64 = r29.s64 + 40;
	// bl 0x8218fe20
	ctx.lr = 0x8230B848;
	sub_8218FE20(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r30,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r30.u32);
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// b 0x8230b85c
	goto loc_8230B85C;
loc_8230B858:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8230B85C:
	// stw r3,-12112(r28)
	PPC_STORE_U32(r28.u32 + -12112, ctx.r3.u32);
	// bl 0x8230a838
	ctx.lr = 0x8230B864;
	sub_8230A838(ctx, base);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-12112(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -12112);
	// lwz r11,-12128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12128);
	// lwz r4,20(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8230aa40
	ctx.lr = 0x8230B878;
	sub_8230AA40(ctx, base);
	// lwz r3,-12120(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -12120);
loc_8230B87C:
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmpwi cr6,r11,250
	cr6.compare<int32_t>(r11.s32, 250, xer);
	// bge cr6,0x8230b9a4
	if (!cr6.lt) goto loc_8230B9A4;
	// lbz r11,218(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 218);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8230b998
	if (!cr6.eq) goto loc_8230B998;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r10,168(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// li r9,13
	ctx.r9.s64 = 13;
	// stb r25,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r25.u8);
	// li r6,128
	ctx.r6.s64 = 128;
	// stw r9,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r9.u32);
	// li r7,128
	ctx.r7.s64 = 128;
	// lfs f0,12264(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12264);
	f0.f64 = double(temp.f32);
	// lfs f13,112(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8230b8dc
	if (!cr6.gt) goto loc_8230B8DC;
	// li r6,256
	ctx.r6.s64 = 256;
	// li r7,256
	ctx.r7.s64 = 256;
loc_8230B8DC:
	// lwz r3,-25232(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -25232);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,12832
	ctx.r4.s64 = r11.s64 + 12832;
	// li r8,8
	ctx.r8.s64 = 8;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8230B904;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,196(r31)
	PPC_STORE_U32(r31.u32 + 196, ctx.r3.u32);
	// lwz r3,-25232(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -25232);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// stw r24,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r24.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r25,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r25.u32);
	// addi r4,r8,12816
	ctx.r4.s64 = ctx.r8.s64 + 12816;
	// lwz r10,144(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// li r8,32
	ctx.r8.s64 = 32;
	// li r5,3
	ctx.r5.s64 = 3;
	// rlwinm r6,r10,7,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// li r7,128
	ctx.r7.s64 = 128;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8230B944;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r6,144(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// li r8,14
	ctx.r8.s64 = 14;
	// stw r10,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r10.u32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lwz r3,-25232(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -25232);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r8,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
	// addi r4,r5,12800
	ctx.r4.s64 = ctx.r5.s64 + 12800;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// li r8,16
	ctx.r8.s64 = 16;
	// li r7,128
	ctx.r7.s64 = 128;
	// rlwinm r6,r6,7,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 7) & 0xFFFFFF80;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8230B98C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r3.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
loc_8230B998:
	// stw r30,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r30.u32);
	// stw r30,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r30.u32);
	// stw r30,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r30.u32);
loc_8230B9A4:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8230B9AC"))) PPC_WEAK_FUNC(sub_8230B9AC);
PPC_FUNC_IMPL(__imp__sub_8230B9AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230B9B0"))) PPC_WEAK_FUNC(sub_8230B9B0);
PPC_FUNC_IMPL(__imp__sub_8230B9B0) {
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
	ctx.lr = 0x8230B9B8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8230ba04
	if (cr6.eq) goto loc_8230BA04;
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lwz r3,-7572(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x8230B9E0;
	sub_82205248(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8230ba04
	if (cr6.eq) goto loc_8230BA04;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-7572(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// bl 0x822f3ba8
	ctx.lr = 0x8230B9F8;
	sub_822F3BA8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-7572(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// bl 0x822f20e0
	ctx.lr = 0x8230BA04;
	sub_822F20E0(ctx, base);
loc_8230BA04:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r27,r30
	r27.u64 = r30.u64;
	// beq cr6,0x8230ba2c
	if (cr6.eq) goto loc_8230BA2C;
	// lwz r11,168(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 168);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8230ba2c
	if (cr6.eq) goto loc_8230BA2C;
	// li r27,1
	r27.s64 = 1;
loc_8230BA2C:
	// lwz r11,204(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 204);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r30,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r30.u8);
	// addi r8,r27,16
	ctx.r8.s64 = r27.s64 + 16;
	// stb r10,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r10.u8);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,168(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 168);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// lwz r3,-26876(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -26876);
	// lwzx r29,r6,r7
	r29.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// bl 0x8217c088
	ctx.lr = 0x8230BA64;
	sub_8217C088(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8230a6a0
	ctx.lr = 0x8230BA6C;
	sub_8230A6A0(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8230badc
	if (cr6.eq) goto loc_8230BADC;
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// mr r28,r30
	r28.u64 = r30.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8230badc
	if (cr6.eq) goto loc_8230BADC;
loc_8230BA88:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r31,r11,r30
	r31.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x8230bac8
	if (cr6.eq) goto loc_8230BAC8;
	// lwz r11,168(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 168);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x82190bd8
	ctx.lr = 0x8230BAB0;
	sub_82190BD8(ctx, base);
	// lwz r10,168(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 168);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x82190bd8
	ctx.lr = 0x8230BAC8;
	sub_82190BD8(ctx, base);
loc_8230BAC8:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8230ba88
	if (cr6.lt) goto loc_8230BA88;
loc_8230BADC:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8230a780
	ctx.lr = 0x8230BAE4;
	sub_8230A780(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8230BAEC"))) PPC_WEAK_FUNC(sub_8230BAEC);
PPC_FUNC_IMPL(__imp__sub_8230BAEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230BAF0"))) PPC_WEAK_FUNC(sub_8230BAF0);
PPC_FUNC_IMPL(__imp__sub_8230BAF0) {
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
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8230BAF8;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r31,r11,-12128
	r31.s64 = r11.s64 + -12128;
	// lwz r29,-12128(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + -12128);
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// lwz r5,24(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// beq cr6,0x8230bb44
	if (cr6.eq) goto loc_8230BB44;
	// lwz r6,196(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// bl 0x82189ce0
	ctx.lr = 0x8230BB3C;
	sub_82189CE0(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x8230bb54
	goto loc_8230BB54;
loc_8230BB44:
	// lwz r27,192(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 192);
	// lwz r6,188(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82189ce0
	ctx.lr = 0x8230BB50;
	sub_82189CE0(ctx, base);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
loc_8230BB54:
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// lwz r5,28(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8230BB68;
	sub_82189CE0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r29,-32119
	r29.s64 = -2104950784;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-12112(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12112);
	// lwz r5,20(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8230b4d0
	ctx.lr = 0x8230BB88;
	sub_8230B4D0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8230ab90
	ctx.lr = 0x8230BB94;
	sub_8230AB90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8230bbec
	if (cr6.eq) goto loc_8230BBEC;
	// lwz r4,200(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r31,-12112(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -12112);
	// lwz r6,12(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// bl 0x82177bf8
	ctx.lr = 0x8230BBB8;
	sub_82177BF8(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8230bbd4
	if (cr6.eq) goto loc_8230BBD4;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r6,12(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82177bf8
	ctx.lr = 0x8230BBD4;
	sub_82177BF8(ctx, base);
loc_8230BBD4:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82178430
	ctx.lr = 0x8230BBDC;
	sub_82178430(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_8230BBEC:
	// lwz r31,0(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r30,-25360(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -25360);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8230BC10;
	sub_82189CE0(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8230BC28;
	sub_82189CE0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8230BC38"))) PPC_WEAK_FUNC(sub_8230BC38);
PPC_FUNC_IMPL(__imp__sub_8230BC38) {
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
	PPCVRegister v31{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8230BC40;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9d0
	ctx.lr = 0x8230BC48;
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r28,r11,-31616
	r28.s64 = r11.s64 + -31616;
	// vsubfp128 v127,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// li r8,32
	ctx.r8.s64 = 32;
	// lwz r10,168(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// vpermwi128 v59,v63,135
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// vpermwi128 v0,v63,99
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// addi r3,r5,2528
	ctx.r3.s64 = ctx.r5.s64 + 2528;
	// lvx128 v62,r11,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,2240
	r11.s64 = ctx.r4.s64 + 2240;
	// vsubfp128 v58,v61,v62
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// cntlzw r10,r30
	ctx.r10.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// vpermwi128 v57,v127,99
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x9C));
	// lvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v56,v127,135
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x78));
	// stvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f0.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// vmulfp128 v12,v59,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v58,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// vor128 v11,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// clrlwi r7,r7,24
	ctx.r7.u64 = ctx.r7.u32 & 0xFF;
	// lfs f10,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f10.f64 = double(temp.f32);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r11,r8,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// lfs f28,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f28.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f11,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// addi r3,r11,2
	ctx.r3.s64 = r11.s64 + 2;
	// fmadds f7,f11,f28,f0
	ctx.f7.f64 = double(float(ctx.f11.f64 * f28.f64 + f0.f64));
	// vnmsubfp v9,v0,v11,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// fsubs f8,f13,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// rlwinm r10,r3,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// stfs f31,112(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// vor128 v10,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// stfs f7,116(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// fsubs f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 - f0.f64));
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// addi r5,r6,-31648
	ctx.r5.s64 = ctx.r6.s64 + -31648;
	// addi r3,r4,-31664
	ctx.r3.s64 = ctx.r4.s64 + -31664;
	// fsel f27,f8,f13,f12
	f27.f64 = ctx.f8.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// vmsum3fp128 v55,v9,v9
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v9.f32), 0xEF));
	// fmuls f29,f27,f28
	ctx.fpscr.disableFlushModeUnconditional();
	f29.f64 = double(float(f27.f64 * f28.f64));
	// stfs f29,80(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v53,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v52,v53,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xFF));
	// vrsqrtefp128 v54,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v54.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v55.f32))));
	// stfs f29,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f29,104(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// vor128 v8,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vcmpeqfp128 v7,v54,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v60.f32)));
	// vor128 v6,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)v54.u8));
	// vsel v0,v6,v13,v7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vmulfp128 v5,v0,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v13,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v4,v63,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v3,v8,v5,v13
	simde_mm_store_ps(ctx.v3.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lvx128 v51,r0,r8
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f30,7444(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f30.f64 = double(temp.f32);
	// vmaddfp v2,v3,v4,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v50,v9,v2
	simde_mm_store_ps(v50.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v2.f32)));
	// vpermwi128 v49,v50,99
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0x9C));
	// vor128 v48,v50,v50
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_load_si128((simde__m128i*)v50.u8));
	// vpermwi128 v1,v50,135
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0x78));
	// stvx128 v50,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v31,v56,v49
	simde_mm_store_ps(v31.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v49.f32)));
	// vmulfp128 v47,v48,v52
	simde_mm_store_ps(v47.f32, simde_mm_mul_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v52.f32)));
	// vnmsubfp v0,v10,v1,v31
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v31.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v47,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v46,v0,v0
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// stvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// fnmsubs f6,f0,f0,f30
	ctx.f6.f64 = double(float(-(f0.f64 * f0.f64 - f30.f64)));
	// vmulfp128 v45,v46,v51
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v45.f32, simde_mm_mul_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v51.f32)));
	// fmuls f5,f9,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f5.f64 = double(float(ctx.f9.f64 * f0.f64));
	// stvx128 v0,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f26,f6,f27,f5
	f26.f64 = double(float(ctx.f6.f64 * f27.f64 + ctx.f5.f64));
	// stvx128 v45,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x8230bf38
	if (!cr6.eq) goto loc_8230BF38;
	// lis r29,-32119
	r29.s64 = -2104950784;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12116(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12116);
	// bl 0x8217c658
	ctx.lr = 0x8230BE1C;
	sub_8217C658(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8230be54
	if (cr6.eq) goto loc_8230BE54;
	// extsw r11,r30
	r11.s64 = r30.s32;
	// lfs f13,148(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// lfs f0,18204(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 18204);
	f0.f64 = double(temp.f32);
	// fmuls f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// fmuls f1,f9,f0
	ctx.f1.f64 = double(float(ctx.f9.f64 * f0.f64));
	// bl 0x82202e38
	ctx.lr = 0x8230BE54;
	sub_82202E38(ctx, base);
loc_8230BE54:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lfs f0,12864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12864);
	f0.f64 = double(temp.f32);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvlx128 v44,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v44,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), 0xFF));
	// lvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// vmaddcfp128 v13,v127,v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsubfp128 v43,v13,v0
	simde_mm_store_ps(v43.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v13,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x8230BE9C;
	sub_82202EC0(ctx, base);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,-12116(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12116);
	// bl 0x8217ce80
	ctx.lr = 0x8230BEA8;
	sub_8217CE80(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,-12116(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12116);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmuls f4,f26,f28
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = double(float(f26.f64 * f28.f64));
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// lfs f0,31492(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31492);
	f0.f64 = double(temp.f32);
	// lfs f6,31016(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f3,f26,f0
	ctx.f3.f64 = double(float(f26.f64 * f0.f64));
	// lfs f5,3800(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3800);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f1,f27,f0
	ctx.f1.f64 = double(float(f27.f64 * f0.f64));
	// bge cr6,0x8230befc
	if (!cr6.lt) goto loc_8230BEFC;
	// bl 0x8217cc80
	ctx.lr = 0x8230BEE0;
	sub_8217CC80(ctx, base);
	// fmr f6,f30
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = f30.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f30
	ctx.f4.f64 = f30.f64;
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// b 0x8230bf30
	goto loc_8230BF30;
loc_8230BEFC:
	// bl 0x8217cc80
	ctx.lr = 0x8230BF00;
	sub_8217CC80(ctx, base);
	// extsw r8,r30
	ctx.r8.s64 = r30.s32;
	// lfs f11,148(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 148);
	ctx.f11.f64 = double(temp.f32);
	// fmr f6,f30
	ctx.f6.f64 = f30.f64;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f30
	ctx.f4.f64 = f30.f64;
	// fmr f3,f11
	ctx.f3.f64 = ctx.f11.f64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f11
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
loc_8230BF30:
	// lwz r3,-12116(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12116);
	// bl 0x8217d548
	ctx.lr = 0x8230BF38;
	sub_8217D548(ctx, base);
loc_8230BF38:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba1c
	ctx.lr = 0x8230BF4C;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8230BF50"))) PPC_WEAK_FUNC(sub_8230BF50);
PPC_FUNC_IMPL(__imp__sub_8230BF50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8230BF58;
	// addi r11,r1,28
	r11.s64 = ctx.r1.s64 + 28;
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r9,r1,-48
	ctx.r9.s64 = ctx.r1.s64 + -48;
	// li r8,112
	ctx.r8.s64 = 112;
	// li r3,0
	ctx.r3.s64 = 0;
	// lvlx128 v63,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lwz r11,-26876(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -26876);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-48(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8230c020
	if (cr6.eq) goto loc_8230C020;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// lis r30,-32119
	r30.s64 = -2104950784;
	// li r6,-8
	ctx.r6.s64 = -8;
	// li r7,16
	ctx.r7.s64 = 16;
	// lis r31,-32119
	r31.s64 = -2104950784;
loc_8230BFA8:
	// lwz r8,-12104(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + -12104);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8230bfbc
	if (!cr6.eq) goto loc_8230BFBC;
	// lwz r9,-12100(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -12100);
	// addi r8,r9,180
	ctx.r8.s64 = ctx.r9.s64 + 180;
loc_8230BFBC:
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r1,-64
	r29.s64 = ctx.r1.s64 + -64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r9,r1,-48
	ctx.r9.s64 = ctx.r1.s64 + -48;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// lvrx128 v61,r4,r11
	temp.u32 = ctx.r4.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v60,r6,r11
	temp.u32 = ctx.r6.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v59,v60,v61
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vupkd3d128 v58,v59,20
	__builtin_debugtrap();
	// vsubfp128 v57,v62,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v58.f32)));
	// vmsum3fp128 v56,v57,v57
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// stvx128 v56,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhz r8,14(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 14);
	// stw r8,-64(r1)
	PPC_STORE_U32(ctx.r1.u32 + -64, ctx.r8.u32);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// lvlx128 v55,r0,r29
	temp.u32 = r29.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v55,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-48(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8230bfa8
	if (!cr6.eq) goto loc_8230BFA8;
loc_8230C020:
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8230c098
	if (!cr6.gt) goto loc_8230C098;
	// addi r10,r5,16
	ctx.r10.s64 = ctx.r5.s64 + 16;
	// cmpw cr6,r6,r3
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r3.s32, xer);
	// bge cr6,0x8230c088
	if (!cr6.lt) goto loc_8230C088;
loc_8230C038:
	// addi r8,r10,-16
	ctx.r8.s64 = ctx.r10.s64 + -16;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// subf r7,r6,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r6.s64;
loc_8230C044:
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v54,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v54.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	cr6.setFromMask(simde_mm_load_ps(v54.f32), 0xF);
	// mfocrf r9,2
	ctx.r9.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r5,r9,0,24,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8230c07c
	if (cr6.eq) goto loc_8230C07C;
	// addi r9,r11,-16
	ctx.r9.s64 = r11.s64 + -16;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r8
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r9
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8230C07C:
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// bne 0x8230c044
	if (!cr0.eq) goto loc_8230C044;
loc_8230C088:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// cmpw cr6,r6,r3
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r3.s32, xer);
	// blt cr6,0x8230c038
	if (cr6.lt) goto loc_8230C038;
loc_8230C098:
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8230C09C"))) PPC_WEAK_FUNC(sub_8230C09C);
PPC_FUNC_IMPL(__imp__sub_8230C09C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230C0A0"))) PPC_WEAK_FUNC(sub_8230C0A0);
PPC_FUNC_IMPL(__imp__sub_8230C0A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v14{};
	PPCVRegister v15{};
	PPCVRegister v16{};
	PPCVRegister v17{};
	PPCVRegister v18{};
	PPCVRegister v19{};
	PPCVRegister v20{};
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
	PPCVRegister vTemp{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// vspltisw v0,1
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_set1_epi32(int(0x1)));
	// addi r9,r11,12528
	ctx.r9.s64 = r11.s64 + 12528;
	// vmsum3fp128 v61,v2,v2
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v2.f32), 0xEF));
	// li r8,148
	ctx.r8.s64 = 148;
	// vspltisw128 v60,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x0)));
	// vslw128 v10,v63,v63
	ctx.v10.u32[0] = v63.u32[0] << (v63.u8[0] & 0x1F);
	ctx.v10.u32[1] = v63.u32[1] << (v63.u8[4] & 0x1F);
	ctx.v10.u32[2] = v63.u32[2] << (v63.u8[8] & 0x1F);
	ctx.v10.u32[3] = v63.u32[3] << (v63.u8[12] & 0x1F);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// vcuxwfp128 v59,v0,1
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)ctx.v0.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lwz r11,-12100(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12100);
	// addi r5,r7,12512
	ctx.r5.s64 = ctx.r7.s64 + 12512;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vupkd3d128 v58,v60,4
	temp.f32 = 3.0f;
	temp.s32 += v60.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v60.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v58 = vTemp;
	// vmulfp128 v57,v63,v1
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v1.f32)));
	// addi r10,r6,12624
	ctx.r10.s64 = ctx.r6.s64 + 12624;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// vspltisw128 v56,3
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_set1_epi32(int(0x3)));
	// vspltisw128 v55,2
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_set1_epi32(int(0x2)));
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lvlx128 v54,r11,r8
	temp.u32 = r11.u32 + ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v58,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x0));
	// vspltw128 v53,v54,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r9,12640
	ctx.r6.s64 = ctx.r9.s64 + 12640;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// addi r9,r7,12672
	ctx.r9.s64 = ctx.r7.s64 + 12672;
	// addi r8,r5,12656
	ctx.r8.s64 = ctx.r5.s64 + 12656;
	// vor128 v3,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// vrsqrtefp128 v12,v61
	simde_mm_store_ps(ctx.v12.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v61.f32))));
	// vor128 v1,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// lvx128 v31,r0,r6
	simde_mm_store_si128((simde__m128i*)v31.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32252
	r11.s64 = -2113667072;
	// vmulfp128 v9,v57,v53
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v53.f32)));
	// lvx128 v8,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v7,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// addi r6,r10,12688
	ctx.r6.s64 = ctx.r10.s64 + 12688;
	// vrsqrtefp128 v11,v61
	simde_mm_store_ps(ctx.v11.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v61.f32))));
	// addi r7,r11,12704
	ctx.r7.s64 = r11.s64 + 12704;
	// addi r10,r5,12720
	ctx.r10.s64 = ctx.r5.s64 + 12720;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lvx128 v5,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r11,12736
	ctx.r9.s64 = r11.s64 + 12736;
	// lvx128 v6,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v30,v12,v12
	simde_mm_store_ps(v30.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v29,v59,v12
	simde_mm_store_ps(v29.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v52,v9,v62
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(v62.f32)));
	// vnmsubfp v28,v1,v30,v13
	simde_mm_store_ps(v28.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vor128 v27,v52,v52
	simde_mm_store_si128((simde__m128i*)v27.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// vsel v26,v3,v27,v10
	simde_mm_store_si128((simde__m128i*)v26.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)v27.u8))));
	// vaddfp128 v51,v52,v26
	simde_mm_store_ps(v51.f32, simde_mm_add_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v26.f32)));
	// vmaddfp v25,v28,v29,v12
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v28.f32), simde_mm_load_ps(v29.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vcfpsxws128 v50,v51,0
	simde_mm_store_si128((simde__m128i*)v50.s32, simde_mm_vctsxs(simde_mm_load_ps(v51.f32)));
	// vmulfp128 v49,v2,v25
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(v25.f32)));
	// vcsxwfp128 v48,v50,0
	simde_mm_store_ps(v48.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vand128 v12,v50,v56
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v56.u8)));
	// vpermwi128 v47,v49,135
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0x78));
	// vadduwm v24,v0,v12
	simde_mm_store_si128((simde__m128i*)v24.u32, simde_mm_add_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), simde_mm_load_si128((simde__m128i*)ctx.v12.u32)));
	// vand128 v46,v12,v0
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vand128 v45,v12,v55
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)v55.u8)));
	// vand128 v44,v24,v0
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vand128 v43,v24,v55
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v24.u8), simde_mm_load_si128((simde__m128i*)v55.u8)));
	// vcmpequw128 v23,v46,v60
	simde_mm_store_si128((simde__m128i*)v23.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vcmpequw128 v22,v45,v60
	simde_mm_store_si128((simde__m128i*)v22.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vor128 v21,v48,v48
	simde_mm_store_si128((simde__m128i*)v21.u8, simde_mm_load_si128((simde__m128i*)v48.u8));
	// vor128 v20,v48,v48
	simde_mm_store_si128((simde__m128i*)v20.u8, simde_mm_load_si128((simde__m128i*)v48.u8));
	// vcmpequw128 v18,v44,v60
	simde_mm_store_si128((simde__m128i*)v18.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vcmpequw128 v17,v43,v60
	simde_mm_store_si128((simde__m128i*)v17.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vnmsubfp v19,v21,v4,v9
	simde_mm_store_ps(v19.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v21.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v9.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// lvx128 v9,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v12,v20,v31,v19
	simde_mm_store_ps(ctx.v12.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v20.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(v19.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmulfp128 v0,v12,v12
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v16,v8,v0,v7
	simde_mm_store_ps(v16.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v15,v6,v0,v5
	simde_mm_store_ps(v15.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmulfp128 v14,v0,v12
	simde_mm_store_ps(v14.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v9,v16,v0,v9
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v16.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// lvx128 v8,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v29,v9,v0,v13
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v30,v15,v0,v8
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v15.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vor128 v5,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// vmulfp128 v6,v11,v11
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v11.f32)));
	// vpermwi128 v7,v49,99
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0x9C));
	// vmulfp128 v4,v59,v11
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(ctx.v11.f32)));
	// vpermwi128 v42,v49,99
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0x9C));
	// vcmpeqfp128 v3,v61,v60
	simde_mm_store_ps(ctx.v3.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// vspltw128 v41,v2,3
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v2.u32), 0x0));
	// vor128 v1,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vpermwi128 v31,v49,135
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0x78));
	// li r8,16
	ctx.r8.s64 = 16;
	// li r7,32
	ctx.r7.s64 = 32;
	// li r6,48
	ctx.r6.s64 = 48;
	// vmaddfp v27,v30,v14,v12
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v14.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vnmsubfp v28,v5,v6,v13
	simde_mm_store_ps(v28.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vsel v23,v29,v27,v23
	simde_mm_store_si128((simde__m128i*)v23.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)v29.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v23.u8), simde_mm_load_si128((simde__m128i*)v27.u8))));
	// vsel v20,v29,v27,v18
	simde_mm_store_si128((simde__m128i*)v20.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v18.u8), simde_mm_load_si128((simde__m128i*)v29.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v18.u8), simde_mm_load_si128((simde__m128i*)v27.u8))));
	// vmaddfp v26,v28,v4,v11
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v28.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vxor v18,v10,v23
	simde_mm_store_si128((simde__m128i*)v18.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)v23.u8)));
	// vxor v15,v10,v20
	simde_mm_store_si128((simde__m128i*)v15.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)v20.u8)));
	// vsel v0,v18,v23,v22
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v22.u8), simde_mm_load_si128((simde__m128i*)v18.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v22.u8), simde_mm_load_si128((simde__m128i*)v23.u8))));
	// vsel v12,v15,v20,v17
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v17.u8), simde_mm_load_si128((simde__m128i*)v15.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v17.u8), simde_mm_load_si128((simde__m128i*)v20.u8))));
	// vsubfp128 v39,v60,v0
	simde_mm_store_ps(v39.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v21,v61,v26
	simde_mm_store_ps(v21.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v26.f32)));
	// vmrghw128 v38,v12,v39
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)ctx.v12.u32)));
	// vsel v14,v21,v1,v3
	simde_mm_store_si128((simde__m128i*)v14.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)v21.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8))));
	// vmrghw128 v37,v38,v60
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmulfp128 v40,v49,v14
	simde_mm_store_ps(v40.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v14.f32)));
	// vpermwi128 v36,v37,99
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), 0x9C));
	// vpermwi128 v11,v37,135
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), 0x78));
	// stvx128 v37,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v10,v36,v47
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v47.f32)));
	// stvx128 v40,r4,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v9,v11,v7,v10
	simde_mm_store_ps(ctx.v9.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v10.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v35,v9,v9
	simde_mm_store_ps(v35.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v9.f32), 0xEF));
	// vrsqrtefp128 v0,v35
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v35.f32))));
	// vor128 v8,v35,v35
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v35.u8));
	// vmulfp128 v7,v0,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v6,v59,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v5,v8,v7,v13
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v4,v5,v6,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v34,v9,v4
	simde_mm_store_ps(v34.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v4.f32)));
	// vpermwi128 v33,v34,135
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0x78));
	// vmulfp128 v32,v34,v41
	simde_mm_store_ps(v32.f32, simde_mm_mul_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v41.f32)));
	// vpermwi128 v3,v34,99
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0x9C));
	// vmulfp128 v2,v42,v33
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v33.f32)));
	// stvx128 v32,r4,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v1,v31,v3,v2
	simde_mm_store_ps(ctx.v1.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v2.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmulfp128 v63,v1,v41
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(v41.f32)));
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r4,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8230C2C0"))) PPC_WEAK_FUNC(sub_8230C2C0);
PPC_FUNC_IMPL(__imp__sub_8230C2C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8230c354
	if (!cr6.eq) goto loc_8230C354;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// sth r10,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r10.u16);
	// rlwinm r3,r10,5,11,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0x1FFFE0;
	// bl 0x82130528
	ctx.lr = 0x8230C2FC;
	sub_82130528(ctx, base);
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8230c348
	if (cr6.eq) goto loc_8230C348;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,16
	ctx.r8.s64 = 16;
loc_8230C314:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r10,r9,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r9,r7
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, xer);
	// blt cr6,0x8230c314
	if (cr6.lt) goto loc_8230C314;
loc_8230C348:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8230C350;
	sub_82130588(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
loc_8230C354:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r10,r11,5
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 5);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
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

__attribute__((alias("__imp__sub_8230C384"))) PPC_WEAK_FUNC(sub_8230C384);
PPC_FUNC_IMPL(__imp__sub_8230C384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230C388"))) PPC_WEAK_FUNC(sub_8230C388);
PPC_FUNC_IMPL(__imp__sub_8230C388) {
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
	ctx.lr = 0x8230C390;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8230c558
	if (cr6.eq) goto loc_8230C558;
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// li r25,0
	r25.s64 = 0;
	// mr r30,r25
	r30.u64 = r25.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8230c3f4
	if (cr6.eq) goto loc_8230C3F4;
	// mr r31,r25
	r31.u64 = r25.u64;
loc_8230C3C0:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lwz r11,168(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8230c3dc
	if (cr6.eq) goto loc_8230C3DC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8230b778
	ctx.lr = 0x8230C3DC;
	sub_8230B778(ctx, base);
loc_8230C3DC:
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,224
	r31.s64 = r31.s64 + 224;
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x8230c3c0
	if (cr6.lt) goto loc_8230C3C0;
loc_8230C3F4:
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// mr r27,r25
	r27.u64 = r25.u64;
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8230c558
	if (cr6.eq) goto loc_8230C558;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r29,r25
	r29.u64 = r25.u64;
	// addi r26,r10,12868
	r26.s64 = ctx.r10.s64 + 12868;
loc_8230C414:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lbz r10,218(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 218);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8230c540
	if (cr6.eq) goto loc_8230C540;
	// li r5,255
	ctx.r5.s64 = 255;
	// lwz r4,128(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823db670
	ctx.lr = 0x8230C448;
	sub_823DB670(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823d90b0
	ctx.lr = 0x8230C454;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8230c460
	if (cr6.eq) goto loc_8230C460;
	// stb r25,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r25.u8);
loc_8230C460:
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// lhz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x8230c540
	if (!cr6.gt) goto loc_8230C540;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r11,128
	ctx.r8.s64 = r11.s64 + 128;
loc_8230C47C:
	// lbz r11,90(r8)
	r11.u64 = PPC_LOAD_U8(ctx.r8.u32 + 90);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// clrlwi r4,r5,24
	ctx.r4.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8230c4cc
	if (!cr6.eq) goto loc_8230C4CC;
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
loc_8230C4A0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r5,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r5.s64;
	// beq cr6,0x8230c4c4
	if (cr6.eq) goto loc_8230C4C4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8230c4a0
	if (cr6.eq) goto loc_8230C4A0;
loc_8230C4C4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8230c4e0
	if (cr6.eq) goto loc_8230C4E0;
loc_8230C4CC:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,224
	ctx.r8.s64 = ctx.r8.s64 + 224;
	// cmpw cr6,r7,r6
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, xer);
	// blt cr6,0x8230c47c
	if (cr6.lt) goto loc_8230C47C;
	// b 0x8230c540
	goto loc_8230C540;
loc_8230C4E0:
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// mulli r10,r7,224
	ctx.r10.s64 = ctx.r7.s64 * 224;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r31,r29,r11
	r31.u64 = r29.u64 + r11.u64;
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// stw r30,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r30.u32);
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
	// beq cr6,0x8230c510
	if (cr6.eq) goto loc_8230C510;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x821ce0d8
	ctx.lr = 0x8230C510;
	sub_821CE0D8(ctx, base);
loc_8230C510:
	// lwz r11,188(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r11.u32);
	// beq cr6,0x8230c528
	if (cr6.eq) goto loc_8230C528;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x821ce0d8
	ctx.lr = 0x8230C528;
	sub_821CE0D8(ctx, base);
loc_8230C528:
	// lwz r11,192(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 192);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r11.u32);
	// beq cr6,0x8230c540
	if (cr6.eq) goto loc_8230C540;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x821ce0d8
	ctx.lr = 0x8230C540;
	sub_821CE0D8(ctx, base);
loc_8230C540:
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,224
	r29.s64 = r29.s64 + 224;
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// cmpw cr6,r27,r10
	cr6.compare<int32_t>(r27.s32, ctx.r10.s32, xer);
	// blt cr6,0x8230c414
	if (cr6.lt) goto loc_8230C414;
loc_8230C558:
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8230C560"))) PPC_WEAK_FUNC(sub_8230C560);
PPC_FUNC_IMPL(__imp__sub_8230C560) {
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
	// bl 0x823d91f0
	ctx.lr = 0x8230C568;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lhz r11,176(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 176);
	// cmplwi cr6,r11,32678
	cr6.compare<uint32_t>(r11.u32, 32678, xer);
	// bge cr6,0x8230c784
	if (!cr6.lt) goto loc_8230C784;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r30,172
	ctx.r3.s64 = r30.s64 + 172;
	// bl 0x8230c2c0
	ctx.lr = 0x8230C594;
	sub_8230C2C0(ctx, base);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r6,2528
	ctx.r4.s64 = ctx.r6.s64 + 2528;
	// lfs f31,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addi r9,r11,2240
	ctx.r9.s64 = r11.s64 + 2240;
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r10,r5,-31648
	ctx.r10.s64 = ctx.r5.s64 + -31648;
	// vor128 v12,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// addi r9,r11,-31664
	ctx.r9.s64 = r11.s64 + -31664;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128 v11,v60,v62
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
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f2.f64 = double(temp.f32);
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// fneg f1,f0
	ctx.f1.u64 = f0.u64 ^ 0x8000000000000000;
	// bl 0x823dcdd8
	ctx.lr = 0x8230C62C;
	sub_823DCDD8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8230c644
	if (!cr6.lt) goto loc_8230C644;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,18204(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18204);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
loc_8230C644:
	// lwz r11,144(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 144);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// extsw r8,r11
	ctx.r8.s64 = r11.s32;
	// std r8,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// lfd f13,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f13,12160(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12160);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f31,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f31.f64 = double(temp.f32);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fmadds f9,f11,f10,f31
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + f31.f64));
	// fctiwz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f8.u64);
	// lwz r26,100(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x8230c68c
	if (cr6.lt) goto loc_8230C68C;
	// li r26,0
	r26.s64 = 0;
loc_8230C68C:
	// addi r28,r31,48
	r28.s64 = r31.s64 + 48;
	// lis r11,-256
	r11.s64 = -16777216;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8230ac80
	ctx.lr = 0x8230C6C0;
	sub_8230AC80(ctx, base);
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,36(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// fmuls f11,f13,f13
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f10,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// lfs f8,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f8
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// lfs f6,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,160(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 160);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f1,f10,f10,f12
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f0,f9,f9,f11
	f0.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f11.f64));
	// fmadds f13,f4,f4,f7
	ctx.f13.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f7.f64));
	// fmadds f12,f6,f6,f1
	ctx.f12.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f1.f64));
	// fmadds f11,f5,f5,f0
	ctx.f11.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + f0.f64));
	// fmadds f10,f3,f3,f13
	ctx.f10.f64 = double(float(ctx.f3.f64 * ctx.f3.f64 + ctx.f13.f64));
	// fsqrts f9,f12
	ctx.f9.f64 = double(float(sqrt(ctx.f12.f64)));
	// fsqrts f8,f11
	ctx.f8.f64 = double(float(sqrt(ctx.f11.f64)));
	// fadds f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 + ctx.f8.f64));
	// fsqrts f0,f10
	f0.f64 = double(float(sqrt(ctx.f10.f64)));
	// fmuls f13,f7,f31
	ctx.f13.f64 = double(float(ctx.f7.f64 * f31.f64));
	// fcmpu cr6,f0,f2
	cr6.compare(f0.f64, ctx.f2.f64);
	// ble cr6,0x8230c730
	if (!cr6.gt) goto loc_8230C730;
	// stfs f0,160(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 160, temp.u32);
loc_8230C730:
	// lfs f0,164(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 164);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8230c740
	if (!cr6.gt) goto loc_8230C740;
	// stfs f13,164(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 164, temp.u32);
loc_8230C740:
	// lvx128 v58,r0,r28
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stvx128 v58,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,16
	ctx.r9.s64 = 16;
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lfs f12,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// clrlwi r7,r26,24
	ctx.r7.u64 = r26.u32 & 0xFF;
	// lfs f11,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// rlwimi r8,r7,24,0,7
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 24) & 0xFF000000) | (ctx.r8.u64 & 0xFFFFFFFF00FFFFFF);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r29,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r8,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r8.u32);
loc_8230C784:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8230C790"))) PPC_WEAK_FUNC(sub_8230C790);
PPC_FUNC_IMPL(__imp__sub_8230C790) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8230c844
	if (cr6.eq) goto loc_8230C844;
	// lwz r11,168(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 168);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8230c844
	if (cr6.eq) goto loc_8230C844;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r10,96
	ctx.r10.s64 = 96;
	// lwz r9,144(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 144);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
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
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lwz r11,-26876(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r31,0
	r31.s64 = 0;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// lvx128 v58,r11,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x8230c844
	if (!cr6.gt) goto loc_8230C844;
loc_8230C81C:
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8230bc38
	ctx.lr = 0x8230C834;
	sub_8230BC38(ctx, base);
	// lwz r11,144(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 144);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8230c81c
	if (cr6.lt) goto loc_8230C81C;
loc_8230C844:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
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

__attribute__((alias("__imp__sub_8230C85C"))) PPC_WEAK_FUNC(sub_8230C85C);
PPC_FUNC_IMPL(__imp__sub_8230C85C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230C860"))) PPC_WEAK_FUNC(sub_8230C860);
PPC_FUNC_IMPL(__imp__sub_8230C860) {
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
	// bl 0x823d91e8
	ctx.lr = 0x8230C868;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8230ca3c
	if (cr6.eq) goto loc_8230CA3C;
	// lbz r11,218(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 218);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8230c8cc
	if (cr6.eq) goto loc_8230C8CC;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v62,r0,r25
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// vsubfp128 v61,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// li r5,-1
	ctx.r5.s64 = -1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8230bc38
	ctx.lr = 0x8230C8C4;
	sub_8230BC38(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_8230C8CC:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r27,-26876(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217fed0
	ctx.lr = 0x8230C8DC;
	sub_8217FED0(ctx, base);
	// lis r29,-32124
	r29.s64 = -2105278464;
	// lwz r5,196(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r6,-32119
	ctx.r6.s64 = -2104950784;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,-12120(r6)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + -12120);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8230C918;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f1,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82178370
	ctx.lr = 0x8230C938;
	sub_82178370(ctx, base);
	// lis r28,-32131
	r28.s64 = -2105737216;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,17320(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 17320);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bge cr6,0x8230c950
	if (!cr6.lt) goto loc_8230C950;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_8230C950:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x8230C958;
	sub_8217F768(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8217f768
	ctx.lr = 0x8230C964;
	sub_8217F768(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217fed0
	ctx.lr = 0x8230C96C;
	sub_8217FED0(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217f768
	ctx.lr = 0x8230C97C;
	sub_8217F768(ctx, base);
	// bl 0x82187bf0
	ctx.lr = 0x8230C980;
	sub_82187BF0(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lwz r3,22736(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 22736);
	// bl 0x82187be0
	ctx.lr = 0x8230C990;
	sub_82187BE0(ctx, base);
	// vspltisw128 v60,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v59,r0,r25
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// vsubfp128 v58,v60,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v59.f32)));
	// li r5,-1
	ctx.r5.s64 = -1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8230bc38
	ctx.lr = 0x8230C9BC;
	sub_8230BC38(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r9,-31280
	ctx.r4.s64 = ctx.r9.s64 + -31280;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8230b9b0
	ctx.lr = 0x8230C9D4;
	sub_8230B9B0(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82187be0
	ctx.lr = 0x8230C9DC;
	sub_82187BE0(ctx, base);
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8230C9FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8217c658
	ctx.lr = 0x8230CA08;
	sub_8217C658(ctx, base);
	// lwz r11,17320(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 17320);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// ble cr6,0x8230ca1c
	if (!cr6.gt) goto loc_8230CA1C;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_8230CA1C:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x8230CA24;
	sub_8217F768(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8217f768
	ctx.lr = 0x8230CA30;
	sub_8217F768(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217f768
	ctx.lr = 0x8230CA3C;
	sub_8217F768(ctx, base);
loc_8230CA3C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8230CA44"))) PPC_WEAK_FUNC(sub_8230CA44);
PPC_FUNC_IMPL(__imp__sub_8230CA44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8230CA48"))) PPC_WEAK_FUNC(sub_8230CA48);
PPC_FUNC_IMPL(__imp__sub_8230CA48) {
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
	PPCVRegister v117{};
	PPCVRegister v118{};
	PPCVRegister v119{};
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
	// bl 0x823d91ec
	ctx.lr = 0x8230CA50;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dd4fc
	ctx.lr = 0x8230CA58;
	// stwu r1,-528(r1)
	ea = -528 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// vspltisw128 v126,0
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// vor128 v123,v126,v126
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// lfs f0,12892(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12892);
	f0.f64 = double(temp.f32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvlx128 v63,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f13,12888(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12888);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lvlx128 v59,r0,r31
	temp.u32 = r31.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r28,r1,112
	r28.s64 = ctx.r1.s64 + 112;
	// lvlx128 v58,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lis r3,-32119
	ctx.r3.s64 = -2104950784;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// vspltw128 v56,v63,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvlx128 v62,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lis r27,-32252
	r27.s64 = -2113667072;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r7,96
	ctx.r7.s64 = 96;
	// lvlx128 v61,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v52,v61,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v60,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lwz r11,-12100(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -12100);
	// lvx128 v55,r0,r9
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v53,v62,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v54,r0,r28
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrlimi128 v56,v55,7,0
	simde_mm_store_ps(v56.f32, simde_mm_blend_ps(simde_mm_load_ps(v56.f32), simde_mm_permute_ps(simde_mm_load_ps(v55.f32), 228), 7));
	// vrlimi128 v57,v54,7,0
	simde_mm_store_ps(v57.f32, simde_mm_blend_ps(simde_mm_load_ps(v57.f32), simde_mm_permute_ps(simde_mm_load_ps(v54.f32), 228), 7));
	// addi r4,r27,12752
	ctx.r4.s64 = r27.s64 + 12752;
	// vspltw128 v63,v60,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// addi r27,r1,192
	r27.s64 = ctx.r1.s64 + 192;
	// lwz r10,168(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// vspltw128 v62,v59,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// vrlimi128 v52,v57,11,0
	simde_mm_store_ps(v52.f32, simde_mm_blend_ps(simde_mm_load_ps(v52.f32), simde_mm_permute_ps(simde_mm_load_ps(v57.f32), 228), 11));
	// lvx128 v122,r0,r4
	simde_mm_store_si128((simde__m128i*)v122.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrlimi128 v53,v56,11,0
	simde_mm_store_ps(v53.f32, simde_mm_blend_ps(simde_mm_load_ps(v53.f32), simde_mm_permute_ps(simde_mm_load_ps(v56.f32), 228), 11));
	// addi r9,r10,16
	ctx.r9.s64 = ctx.r10.s64 + 16;
	// addi r26,r1,208
	r26.s64 = ctx.r1.s64 + 208;
	// lhz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// addi r25,r1,128
	r25.s64 = ctx.r1.s64 + 128;
	// lhz r10,10(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 10);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// vrlimi128 v62,v52,13,0
	simde_mm_store_ps(v62.f32, simde_mm_blend_ps(simde_mm_load_ps(v62.f32), simde_mm_permute_ps(simde_mm_load_ps(v52.f32), 228), 13));
	// lis r28,-32256
	r28.s64 = -2113929216;
	// vrlimi128 v63,v53,13,0
	simde_mm_store_ps(v63.f32, simde_mm_blend_ps(simde_mm_load_ps(v63.f32), simde_mm_permute_ps(simde_mm_load_ps(v53.f32), 228), 13));
	// lvlx128 v51,r9,r7
	temp.u32 = ctx.r9.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r31,112
	r31.s64 = 112;
	// lvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// stvx128 v123,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v117,v51,0
	simde_mm_store_si128((simde__m128i*)v117.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// stvx128 v122,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v122.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,15364(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 15364);
	f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bgt cr6,0x8230cc7c
	if (cr6.gt) goto loc_8230CC7C;
	// lwz r4,172(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 172);
	// rlwinm r9,r10,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r8,r10,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r10.s64;
	// lvx128 v0,r11,r31
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r4,r9
	ctx.r10.u64 = ctx.r4.u64 + ctx.r9.u64;
	// lvx128 v13,r11,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r8,1
	ctx.r9.s64 = ctx.r8.s64 + 1;
loc_8230CB88:
	// lwz r11,16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// lvx128 v50,r0,r10
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r28,r11,24,24,31
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// rlwinm r27,r11,8,24,31
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFF;
	// clrlwi r26,r11,24
	r26.u64 = r11.u32 & 0xFF;
	// std r28,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r28.u64);
	// rlwinm r11,r11,16,24,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF;
	// std r27,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r27.u64);
	// std r26,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, r26.u64);
	// lfd f12,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r11.u64);
	// lfd f11,160(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 160);
	// lfd f10,104(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f7,f13
	ctx.f7.f64 = double(ctx.f13.s64);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// fcfid f6,f12
	ctx.f6.f64 = double(ctx.f12.s64);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// frsp f2,f6
	ctx.f2.f64 = double(float(ctx.f6.f64));
	// frsp f5,f9
	ctx.f5.f64 = double(float(ctx.f9.f64));
	// fmuls f12,f3,f0
	ctx.f12.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfs f12,148(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// fmuls f13,f4,f0
	ctx.f13.f64 = double(float(ctx.f4.f64 * f0.f64));
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// fmuls f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 * f0.f64));
	// stfs f11,156(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// fmuls f1,f5,f0
	ctx.f1.f64 = double(float(ctx.f5.f64 * f0.f64));
	// stfs f1,144(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v12,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v12,v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,184(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,188(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f10,f13,f13
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f13,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f8,f12,f12,f9
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f9.f64));
	// fsqrts f7,f8
	ctx.f7.f64 = double(float(sqrt(ctx.f8.f64)));
	// fsubs f6,f7,f11
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f11.f64));
	// fsel f5,f6,f7,f11
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f7.f64 : ctx.f11.f64;
	// stfs f5,80(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v49,r0,r28
	temp.u32 = r28.u32;
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v48,v49,0
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0xFF));
	// vmulfp128 v47,v48,v117
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v47.f32, simde_mm_mul_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v117.f32)));
	// vsubfp128 v46,v50,v47
	simde_mm_store_ps(v46.f32, simde_mm_sub_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v47.f32)));
	// vaddfp128 v45,v50,v47
	simde_mm_store_ps(v45.f32, simde_mm_add_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v47.f32)));
	// vminfp128 v63,v63,v46
	simde_mm_store_ps(v63.f32, simde_mm_min_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v46.f32)));
	// vmaxfp128 v62,v62,v45
	simde_mm_store_ps(v62.f32, simde_mm_max_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v45.f32)));
	// bne 0x8230cb88
	if (!cr0.eq) goto loc_8230CB88;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8230CC7C:
	// vsubfp128 v44,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v44.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vspltisw128 v43,1
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_set1_epi32(int(0x1)));
	// vupkd3d128 v61,v126,4
	temp.f32 = 3.0f;
	temp.s32 += v126.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v126.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v61 = vTemp;
	// lfs f13,136(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,4(r5)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// vaddfp128 v42,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v42.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vor128 v13,v126,v126
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// lfs f12,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// vcuxwfp128 v124,v43,1
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v124.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v43.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// lfs f11,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// vspltw128 v121,v61,3
	simde_mm_store_si128((simde__m128i*)v121.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x0));
	// lfs f10,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f10.f64 = double(temp.f32);
	// stfs f12,0(r5)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// vor128 v125,v126,v126
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// stfs f11,0(r6)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// stfs f10,4(r6)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// lhz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// vor128 v12,v121,v121
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v121.u8));
	// vmsum3fp128 v41,v44,v44
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v44.f32), 0xEF));
	// lhz r10,10(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 10);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// vrsqrtefp128 v0,v41
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v41.f32))));
	// vor128 v40,v41,v41
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_load_si128((simde__m128i*)v41.u8));
	// vcmpeqfp128 v11,v41,v126
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v126.f32)));
	// vmulfp128 v39,v0,v0
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v10,v124,v0
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp128 v12,v40,v39,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v39.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v9,v12,v10,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v41,v9
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(ctx.v9.f32)));
	// vsel v7,v8,v13,v11
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vrlimi128 v42,v7,1,1
	simde_mm_store_ps(v42.f32, simde_mm_blend_ps(simde_mm_load_ps(v42.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v7.f32), 147), 1));
	// vmulfp128 v120,v42,v124
	simde_mm_store_ps(v120.f32, simde_mm_mul_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v124.f32)));
	// bgt cr6,0x8230cee4
	if (cr6.gt) goto loc_8230CEE4;
	// vspltisw128 v38,-1
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lwz r11,-12100(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -12100);
	// vpermwi128 v37,v61,171
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x54));
	// rlwinm r9,r10,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r8,r10,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r10.s64;
	// vor128 v36,v38,v38
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_load_si128((simde__m128i*)v38.u8));
	// lwz r10,172(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 172);
	// lvx128 v119,r11,r31
	simde_mm_store_si128((simde__m128i*)v119.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v118,r11,r7
	simde_mm_store_si128((simde__m128i*)v118.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r8,1
	r31.s64 = ctx.r8.s64 + 1;
	// add r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	// vpkd3d128 v36,v38,0,1,0
	vTemp.u32[0] = 0x404000FF;
	vTemp.f32[0] = v38.f32[0] < 3.0f ? 3.0f : (v38.f32[0] > vTemp.f32[0] ? vTemp.f32[0] : v38.f32[0]);
	temp.u32 = uint32_t(vTemp.u8[0]) << 24;
	vTemp.u32[1] = 0x404000FF;
	vTemp.f32[1] = v38.f32[1] < 3.0f ? 3.0f : (v38.f32[1] > vTemp.f32[1] ? vTemp.f32[1] : v38.f32[1]);
	temp.u32 |= uint32_t(vTemp.u8[4]) << 0;
	vTemp.u32[2] = 0x404000FF;
	vTemp.f32[2] = v38.f32[2] < 3.0f ? 3.0f : (v38.f32[2] > vTemp.f32[2] ? vTemp.f32[2] : v38.f32[2]);
	temp.u32 |= uint32_t(vTemp.u8[8]) << 8;
	vTemp.u32[3] = 0x404000FF;
	vTemp.f32[3] = v38.f32[3] < 3.0f ? 3.0f : (v38.f32[3] > vTemp.f32[3] ? vTemp.f32[3] : v38.f32[3]);
	temp.u32 |= uint32_t(vTemp.u8[12]) << 16;
	v36.u32[0] = temp.u32;
	// vand128 v35,v60,v36
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v36.u8)));
	// vor128 v127,v35,v37
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)v37.u8)));
loc_8230CD38:
	// lbz r8,12(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 12);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// std r8,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r8.u64);
	// lfd f13,104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lvx128 v2,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v34,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v1,v34,0
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0xFF));
	// bl 0x8230c0a0
	ctx.lr = 0x8230CD6C;
	sub_8230C0A0(ctx, base);
	// lwz r7,16(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// vor128 v33,v119,v119
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_load_si128((simde__m128i*)v119.u8));
	// rlwinm r9,r7,8,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFF;
	// vor128 v13,v126,v126
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// rlwinm r8,r7,16,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 16) & 0xFF;
	// vor128 v12,v121,v121
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v121.u8));
	// std r9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// rlwinm r9,r7,24,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 24) & 0xFF;
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f9,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// std r5,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r5.u64);
	// lfd f8,88(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lfd f6,144(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// vmrghw128 v32,v63,v62
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// clrlwi r10,r7,24
	ctx.r10.u64 = ctx.r7.u32 & 0xFF;
	// vmrglw128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// std r10,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, ctx.r10.u64);
	// lfd f10,160(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 160);
	// lvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcfid f3,f10
	ctx.f3.f64 = double(ctx.f10.s64);
	// lvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// vmrghw128 v62,v61,v60
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// fcfid f5,f9
	ctx.f5.f64 = double(ctx.f9.s64);
	// vmrglw128 v61,v61,v60
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// fcfid f4,f6
	ctx.f4.f64 = double(ctx.f6.s64);
	// frsp f12,f3
	ctx.f12.f64 = double(float(ctx.f3.f64));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// vmrghw128 v60,v32,v62
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// vmrghw128 v59,v63,v61
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrglw128 v58,v32,v62
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// vmsum4fp128 v57,v60,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v127.f32), 0xFF));
	// vmsum4fp128 v56,v59,v127
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v127.f32), 0xFF));
	// frsp f2,f7
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f2.f64 = double(float(ctx.f7.f64));
	// vmsum4fp128 v55,v58,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v127.f32), 0xFF));
	// frsp f1,f5
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.f64 = double(float(ctx.f5.f64));
	// frsp f13,f4
	ctx.f13.f64 = double(float(ctx.f4.f64));
	// fmuls f8,f12,f0
	ctx.f8.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f8,120(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmuls f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 * f0.f64));
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmuls f10,f1,f0
	ctx.f10.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfs f10,124(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// fmuls f9,f13,f0
	ctx.f9.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f9,112(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v52,r0,r10
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v33,v52,v118,v33
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v33.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v118.f32)), simde_mm_load_ps(v33.f32)));
	// vmrghw128 v54,v57,v56
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// stvx128 v33,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,132(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f7,f13,f13
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// vmrghw128 v53,v54,v55
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// lfs f13,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f6,f13,f13,f7
	ctx.f6.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f7.f64));
	// vsubfp128 v51,v53,v120
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v51.f32, simde_mm_sub_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v120.f32)));
	// vmsum3fp128 v50,v51,v51
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v51.f32), 0xEF));
	// vrsqrtefp128 v0,v50
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v50.f32))));
	// vor128 v49,v50,v50
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_load_si128((simde__m128i*)v50.u8));
	// vmulfp128 v48,v0,v0
	simde_mm_store_ps(v48.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// fmadds f5,f12,f12,f6
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f6.f64));
	// vmulfp128 v10,v124,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lfs f13,140(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	ctx.f13.f64 = double(temp.f32);
	// vcmpeqfp128 v11,v50,v126
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v126.f32)));
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r3,r3,32
	ctx.r3.s64 = ctx.r3.s64 + 32;
	// fsqrts f4,f5
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f4.f64 = double(float(sqrt(ctx.f5.f64)));
	// vnmsubfp128 v12,v49,v48,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v48.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v9,v12,v10,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v8,v50,v9
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(ctx.v9.f32)));
	// vsel v7,v8,v13,v11
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// fsubs f3,f4,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f3.f64 = double(float(ctx.f4.f64 - ctx.f13.f64));
	// fsel f2,f3,f4,f13
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f4.f64 : ctx.f13.f64;
	// stfs f2,80(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v47,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v0,v47,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0xFF));
	// vmaddfp128 v7,v0,v117,v7
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v117.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaxfp128 v123,v123,v0
	simde_mm_store_ps(v123.f32, simde_mm_max_ps(simde_mm_load_ps(v123.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vminfp128 v122,v122,v0
	simde_mm_store_ps(v122.f32, simde_mm_min_ps(simde_mm_load_ps(v122.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmaxfp128 v125,v125,v7
	simde_mm_store_ps(v125.f32, simde_mm_max_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(ctx.v7.f32)));
	// bne 0x8230cd38
	if (!cr0.eq) goto loc_8230CD38;
	// addi r11,r1,208
	r11.s64 = ctx.r1.s64 + 208;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stvx128 v122,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v122.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v123,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8230CEE4:
	// vrlimi128 v120,v125,1,1
	simde_mm_store_ps(v120.f32, simde_mm_blend_ps(simde_mm_load_ps(v120.f32), simde_mm_permute_ps(simde_mm_load_ps(v125.f32), 147), 1));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// vor128 v1,v120,v120
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v120.u8));
	// bl 0x8230a350
	ctx.lr = 0x8230CEF4;
	sub_8230A350(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,192(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f12,208(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	ctx.f12.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stvx128 v120,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v120.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-4728(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4728);
	f0.f64 = double(temp.f32);
	// fadds f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfs f0,15000(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15000);
	f0.f64 = double(temp.f32);
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f9,f11,f0
	ctx.f9.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fctiwz f8,f10
	ctx.f8.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f8,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.f8.u64);
	// lwz r7,108(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// fctiwz f7,f9
	ctx.f7.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f7,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.f7.u64);
	// lwz r9,148(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// stb r9,8(r30)
	PPC_STORE_U8(r30.u32 + 8, ctx.r9.u8);
	// stb r7,9(r30)
	PPC_STORE_U8(r30.u32 + 9, ctx.r7.u8);
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dd794
	ctx.lr = 0x8230CF4C;
	// b 0x823d923c
	return;
}

