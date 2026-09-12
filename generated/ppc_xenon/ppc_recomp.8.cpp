#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8217BC98"))) PPC_WEAK_FUNC(sub_8217BC98);
PPC_FUNC_IMPL(__imp__sub_8217BC98) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r31,r11,-26904
	r31.s64 = r11.s64 + -26904;
	// lwz r11,-16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8217bce4
	if (cr6.eq) goto loc_8217BCE4;
	// bl 0x821784a8
	ctx.lr = 0x8217BCC0;
	sub_821784A8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,-16(r31)
	PPC_STORE_U32(r31.u32 + -16, r11.u32);
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
loc_8217BCE4:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_8217BD00"))) PPC_WEAK_FUNC(sub_8217BD00);
PPC_FUNC_IMPL(__imp__sub_8217BD00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// stfd f29,-24(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -24, f29.u64);
	// stfd f30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f30.u64);
	// stfd f31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, f31.u64);
	// addi r11,r1,-48
	r11.s64 = ctx.r1.s64 + -48;
	// lfs f11,16(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// addi r10,r1,-48
	ctx.r10.s64 = ctx.r1.s64 + -48;
	// lfs f10,20(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,24(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	ctx.f9.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f8,32(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	ctx.f8.f64 = double(temp.f32);
	// addi r8,r1,-64
	ctx.r8.s64 = ctx.r1.s64 + -64;
	// lfs f7,36(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	ctx.f7.f64 = double(temp.f32);
	// stvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-40(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -40);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-48(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -48);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,-44(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -44);
	f0.f64 = double(temp.f32);
	// fmuls f6,f11,f0
	ctx.f6.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fmuls f5,f10,f0
	ctx.f5.f64 = double(float(ctx.f10.f64 * f0.f64));
	// lfs f4,40(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f9,f0
	ctx.f3.f64 = double(float(ctx.f9.f64 * f0.f64));
	// lfs f2,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f1,f8,f13,f6
	ctx.f1.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f6.f64));
	// lfs f8,28(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64));
	// lfs f30,44(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 44);
	f30.f64 = double(temp.f32);
	// lfs f10,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,48(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	f0.f64 = double(temp.f32);
	// lfs f8,52(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 52);
	ctx.f8.f64 = double(temp.f32);
	// lfs f31,56(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 56);
	f31.f64 = double(temp.f32);
	// lfs f29,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	f29.f64 = double(temp.f32);
	// fmadds f7,f7,f13,f5
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 + ctx.f5.f64));
	// lfs f5,60(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 60);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f4,f13,f3
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f13.f64 + ctx.f3.f64));
	// lfs f11,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f3,f2,f12,f1
	ctx.f3.f64 = double(float(ctx.f2.f64 * ctx.f12.f64 + ctx.f1.f64));
	// fmadds f2,f30,f13,f6
	ctx.f2.f64 = double(float(f30.f64 * ctx.f13.f64 + ctx.f6.f64));
	// fmadds f1,f10,f12,f7
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f12.f64 + ctx.f7.f64));
	// fmadds f13,f9,f12,f4
	ctx.f13.f64 = double(float(ctx.f9.f64 * ctx.f12.f64 + ctx.f4.f64));
	// fadds f10,f3,f0
	ctx.f10.f64 = double(float(ctx.f3.f64 + f0.f64));
	// stfs f10,-48(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + -48, temp.u32);
	// fmadds f9,f29,f12,f2
	ctx.f9.f64 = double(float(f29.f64 * ctx.f12.f64 + ctx.f2.f64));
	// fadds f8,f1,f8
	ctx.f8.f64 = double(float(ctx.f1.f64 + ctx.f8.f64));
	// stfs f8,-44(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -44, temp.u32);
	// fadds f7,f13,f31
	ctx.f7.f64 = double(float(ctx.f13.f64 + f31.f64));
	// stfs f7,-40(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + -40, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f6,f9,f5
	ctx.f6.f64 = double(float(ctx.f9.f64 + ctx.f5.f64));
	// fdivs f5,f11,f6
	ctx.f5.f64 = double(float(ctx.f11.f64 / ctx.f6.f64));
	// stfs f5,-64(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// lvlx128 v62,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmulfp128 v60,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f29,-24(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// lfd f30,-16(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lfd f31,-8(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217BDE8"))) PPC_WEAK_FUNC(sub_8217BDE8);
PPC_FUNC_IMPL(__imp__sub_8217BDE8) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r11,-27780(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27780);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8217be5c
	if (!cr6.eq) goto loc_8217BE5C;
	// lis r30,-32124
	r30.s64 = -2105278464;
	// addi r31,r3,128
	r31.s64 = ctx.r3.s64 + 128;
	// li r7,15
	ctx.r7.s64 = 15;
	// li r6,16
	ctx.r6.s64 = 16;
	// rldicr r7,r7,60,3
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 60) & 0xF000000000000000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,-28076(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -28076);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82417678
	ctx.lr = 0x8217BE30;
	sub_82417678(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lbz r10,17292(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 17292);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8217be5c
	if (cr6.eq) goto loc_8217BE5C;
	// li r7,15
	ctx.r7.s64 = 15;
	// lwz r3,-28076(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -28076);
	// li r6,16
	ctx.r6.s64 = 16;
	// rldicr r7,r7,60,3
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 60) & 0xF000000000000000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82417758
	ctx.lr = 0x8217BE5C;
	sub_82417758(ctx, base);
loc_8217BE5C:
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

__attribute__((alias("__imp__sub_8217BE74"))) PPC_WEAK_FUNC(sub_8217BE74);
PPC_FUNC_IMPL(__imp__sub_8217BE74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217BE78"))) PPC_WEAK_FUNC(sub_8217BE78);
PPC_FUNC_IMPL(__imp__sub_8217BE78) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x8217BE80;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x821789d8
	ctx.lr = 0x8217BE8C;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r25,-32131
	r25.s64 = -2105737216;
	// lis r24,-32131
	r24.s64 = -2105737216;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8217bea8
	if (cr6.eq) goto loc_8217BEA8;
	// lwz r11,17004(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 17004);
	// b 0x8217beac
	goto loc_8217BEAC;
loc_8217BEA8:
	// lwz r11,17012(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 17012);
loc_8217BEAC:
	// lwz r10,688(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 688);
	// lis r27,-32131
	r27.s64 = -2105737216;
	// lis r26,-32131
	r26.s64 = -2105737216;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bne cr6,0x8217bee8
	if (!cr6.eq) goto loc_8217BEE8;
	// bl 0x821789d8
	ctx.lr = 0x8217BEC4;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8217bed8
	if (cr6.eq) goto loc_8217BED8;
	// lwz r11,17008(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 17008);
	// b 0x8217bedc
	goto loc_8217BEDC;
loc_8217BED8:
	// lwz r11,17016(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 17016);
loc_8217BEDC:
	// lwz r10,692(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 692);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x8217c00c
	if (cr6.eq) goto loc_8217C00C;
loc_8217BEE8:
	// addi r30,r31,640
	r30.s64 = r31.s64 + 640;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821797d0
	ctx.lr = 0x8217BEF4;
	sub_821797D0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82179830
	ctx.lr = 0x8217BF00;
	sub_82179830(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82179890
	ctx.lr = 0x8217BF0C;
	sub_82179890(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821798f0
	ctx.lr = 0x8217BF18;
	sub_821798F0(ctx, base);
	// neg r10,r3
	ctx.r10.s64 = -ctx.r3.s64;
	// srawi r11,r23,1
	xer.ca = (r23.s32 < 0) & ((r23.u32 & 0x1) != 0);
	r11.s64 = r23.s32 >> 1;
	// srawi r8,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 1;
	// srawi r10,r3,1
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 1;
	// add r9,r11,r29
	ctx.r9.u64 = r11.u64 + r29.u64;
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// add r6,r10,r28
	ctx.r6.u64 = ctx.r10.u64 + r28.u64;
	// extsw r5,r9
	ctx.r5.s64 = ctx.r9.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// extsw r4,r6
	ctx.r4.s64 = ctx.r6.s32;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// extsw r3,r11
	ctx.r3.s64 = r11.s32;
	// fcfid f9,f0
	ctx.f9.f64 = double(f0.s64);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fcfid f8,f13
	ctx.f8.f64 = double(ctx.f13.s64);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fcfid f7,f12
	ctx.f7.f64 = double(ctx.f12.s64);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// frsp f6,f10
	ctx.f6.f64 = double(float(ctx.f10.f64));
	// stfs f0,580(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 580, temp.u32);
	// stfs f0,584(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 584, temp.u32);
	// frsp f5,f9
	ctx.f5.f64 = double(float(ctx.f9.f64));
	// stfs f0,588(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 588, temp.u32);
	// stfs f6,576(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 576, temp.u32);
	// stfs f0,592(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 592, temp.u32);
	// stfs f0,600(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 600, temp.u32);
	// stfs f0,604(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 604, temp.u32);
	// stfs f5,596(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 596, temp.u32);
	// lfs f4,656(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 656);
	ctx.f4.f64 = double(temp.f32);
	// frsp f3,f8
	ctx.f3.f64 = double(float(ctx.f8.f64));
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// frsp f2,f7
	ctx.f2.f64 = double(float(ctx.f7.f64));
	// stfs f3,624(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 624, temp.u32);
	// stfs f2,628(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 628, temp.u32);
	// stfs f4,632(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 632, temp.u32);
	// stfs f0,636(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 636, temp.u32);
	// bl 0x821789d8
	ctx.lr = 0x8217BFC8;
	sub_821789D8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8217bfdc
	if (cr6.eq) goto loc_8217BFDC;
	// lwz r11,17004(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 17004);
	// b 0x8217bfe0
	goto loc_8217BFE0;
loc_8217BFDC:
	// lwz r11,17012(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 17012);
loc_8217BFE0:
	// stw r11,688(r31)
	PPC_STORE_U32(r31.u32 + 688, r11.u32);
	// bl 0x821789d8
	ctx.lr = 0x8217BFE8;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8217c004
	if (cr6.eq) goto loc_8217C004;
	// lwz r11,17008(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 17008);
	// stw r11,692(r31)
	PPC_STORE_U32(r31.u32 + 692, r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
loc_8217C004:
	// lwz r11,17016(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 17016);
	// stw r11,692(r31)
	PPC_STORE_U32(r31.u32 + 692, r11.u32);
loc_8217C00C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8217C014"))) PPC_WEAK_FUNC(sub_8217C014);
PPC_FUNC_IMPL(__imp__sub_8217C014) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217C018"))) PPC_WEAK_FUNC(sub_8217C018);
PPC_FUNC_IMPL(__imp__sub_8217C018) {
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
	// addi r5,r31,128
	ctx.r5.s64 = r31.s64 + 128;
	// addi r4,r31,384
	ctx.r4.s64 = r31.s64 + 384;
	// addi r3,r31,192
	ctx.r3.s64 = r31.s64 + 192;
	// bl 0x8215e000
	ctx.lr = 0x8217C03C;
	sub_8215E000(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r31,448
	ctx.r4.s64 = r31.s64 + 448;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8215e000
	ctx.lr = 0x8217C04C;
	sub_8215E000(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r31,576
	ctx.r4.s64 = r31.s64 + 576;
	// addi r3,r31,512
	ctx.r3.s64 = r31.s64 + 512;
	// bl 0x8215e000
	ctx.lr = 0x8217C05C;
	sub_8215E000(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r11,-26876(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bne cr6,0x8217c074
	if (!cr6.eq) goto loc_8217C074;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217bde8
	ctx.lr = 0x8217C074;
	sub_8217BDE8(ctx, base);
loc_8217C074:
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

__attribute__((alias("__imp__sub_8217C088"))) PPC_WEAK_FUNC(sub_8217C088);
PPC_FUNC_IMPL(__imp__sub_8217C088) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// li r5,16
	ctx.r5.s64 = 16;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// li r6,32
	ctx.r6.s64 = 32;
	// addi r9,r3,32
	ctx.r9.s64 = ctx.r3.s64 + 32;
	// li r7,48
	ctx.r7.s64 = 48;
	// lvx128 v62,r4,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r3,48
	ctx.r8.s64 = ctx.r3.s64 + 48;
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lvx128 v61,r4,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r11,2384
	r31.s64 = r11.s64 + 2384;
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r3,128
	r11.s64 = ctx.r3.s64 + 128;
	// lvx128 v60,r4,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r4,2352
	ctx.r4.s64 = ctx.r4.s64 + 2352;
	// lvx128 v59,r0,r3
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v58,v59,v63
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v56,v57,v63
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v56,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r0,r9
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v54,v55,v63
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v54,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r8
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v52,v53,v63
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v51,v63,v52
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v52.u8)));
	// stvx128 v51,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217c018
	ctx.lr = 0x8217C130;
	sub_8217C018(ctx, base);
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

__attribute__((alias("__imp__sub_8217C144"))) PPC_WEAK_FUNC(sub_8217C144);
PPC_FUNC_IMPL(__imp__sub_8217C144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217C148"))) PPC_WEAK_FUNC(sub_8217C148);
PPC_FUNC_IMPL(__imp__sub_8217C148) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
	PPCVRegister v56{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// li r11,976
	r11.s64 = 976;
	// vspltw v0,v1,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0x55));
	// li r10,960
	ctx.r10.s64 = 960;
	// vspltw v13,v1,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0xAA));
	// li r9,912
	ctx.r9.s64 = 912;
	// vspltw v12,v1,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0xFF));
	// li r8,896
	ctx.r8.s64 = 896;
	// vspltw128 v63,v1,3
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0x0));
	// li r7,944
	ctx.r7.s64 = 944;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v11,r3,r11
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,880
	ctx.r6.s64 = 880;
	// lvx128 v10,r3,r10
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,928
	ctx.r5.s64 = 928;
	// lvx128 v9,r3,r9
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v8,v0,v10,v11
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// lvx128 v7,r3,r8
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,864
	ctx.r4.s64 = 864;
	// vmaddfp v6,v0,v7,v9
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// lvx128 v5,r3,r7
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r3,r6
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lvx128 v3,r3,r5
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v60,-1
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lvx128 v2,r3,r4
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v1,v13,v5,v8
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v31,v13,v4,v6
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v30,v12,v3,v1
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v29,v12,v2,v31
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v31.f32)));
	// vcmpgefp128 v59,v30,v61
	simde_mm_store_ps(v59.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v61.f32)));
	// vcmpgefp128 v58,v29,v61
	simde_mm_store_ps(v58.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v29.f32), simde_mm_load_ps(v61.f32)));
	// vand128 v57,v58,v59
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vcmpequw128. v56,v57,v60
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	cr6.setFromMask(simde_mm_load_ps(v56.f32), 0xF);
	// mfocrf r3,2
	ctx.r3.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r3,r3,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 25) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217C1D8"))) PPC_WEAK_FUNC(sub_8217C1D8);
PPC_FUNC_IMPL(__imp__sub_8217C1D8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	uint32_t ea{};
	// li r11,912
	r11.s64 = 912;
	// vspltw v0,v1,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0x55));
	// li r10,896
	ctx.r10.s64 = 896;
	// vspltw v13,v1,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0xAA));
	// li r9,976
	ctx.r9.s64 = 976;
	// vspltw v12,v1,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0xFF));
	// li r8,960
	ctx.r8.s64 = 960;
	// vspltw128 v63,v1,3
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0x0));
	// li r7,880
	ctx.r7.s64 = 880;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v11,r3,r11
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,944
	ctx.r6.s64 = 944;
	// lvx128 v10,r3,r10
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,864
	ctx.r5.s64 = 864;
	// lvx128 v9,r3,r9
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v8,v0,v10,v11
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// lvx128 v7,r3,r8
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,928
	r11.s64 = 928;
	// vmaddfp v6,v0,v7,v9
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// lvx128 v5,r3,r7
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r3,r6
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v61,-1
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lvx128 v3,r3,r5
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r3,r11
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v1,v13,v5,v8
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v31,v13,v4,v6
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v30,v12,v3,v1
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v29,v12,v2,v31
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v31.f32)));
	// vaddfp128 v60,v30,v63
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v63.f32)));
	// vaddfp128 v59,v29,v63
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(v29.f32), simde_mm_load_ps(v63.f32)));
	// vcmpgefp128 v58,v60,v62
	simde_mm_store_ps(v58.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v62.f32)));
	// vspltw128 v57,v60,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vcmpgefp128 v56,v59,v62
	simde_mm_store_ps(v56.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v62.f32)));
	// stvewx128 v57,r0,r4
	ea = (ctx.r4.u32) & ~0x3;
	PPC_STORE_U32(ea, v57.u32[3 - ((ea & 0xF) >> 2)]);
	// vand128 v55,v58,v56
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v56.u8)));
	// vcmpequw128. v54,v55,v61
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	cr6.setFromMask(simde_mm_load_ps(v54.f32), 0xF);
	// mfocrf r10,2
	ctx.r10.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r3,r10,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217C274"))) PPC_WEAK_FUNC(sub_8217C274);
PPC_FUNC_IMPL(__imp__sub_8217C274) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217C278"))) PPC_WEAK_FUNC(sub_8217C278);
PPC_FUNC_IMPL(__imp__sub_8217C278) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
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
	// li r11,912
	r11.s64 = 912;
	// vspltw v0,v1,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0x55));
	// li r10,896
	ctx.r10.s64 = 896;
	// vspltw v13,v1,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0xAA));
	// li r9,976
	ctx.r9.s64 = 976;
	// vspltw v12,v1,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0xFF));
	// li r8,960
	ctx.r8.s64 = 960;
	// vspltw128 v63,v1,3
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0x0));
	// li r7,880
	ctx.r7.s64 = 880;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v11,r3,r11
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,944
	ctx.r6.s64 = 944;
	// lvx128 v10,r3,r10
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,864
	ctx.r5.s64 = 864;
	// lvx128 v9,r3,r9
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v8,v0,v10,v11
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// lvx128 v7,r3,r8
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,928
	ctx.r4.s64 = 928;
	// vmaddfp v6,v0,v7,v9
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// lvx128 v5,r3,r7
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r3,r6
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lvx128 v3,r3,r5
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v60,-1
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lvx128 v2,r3,r4
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v1,v13,v5,v8
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v31,v13,v4,v6
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v30,v12,v3,v1
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v29,v12,v2,v31
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(v31.f32)));
	// vcmpgefp128 v59,v30,v61
	simde_mm_store_ps(v59.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v61.f32)));
	// vcmpgefp128 v58,v29,v61
	simde_mm_store_ps(v58.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v29.f32), simde_mm_load_ps(v61.f32)));
	// vand128 v57,v59,v58
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v58.u8)));
	// vcmpequw128. v56,v57,v60
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	cr6.setFromMask(simde_mm_load_ps(v56.f32), 0xF);
	// mfocrf r3,2
	ctx.r3.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// vcmpgefp128 v55,v29,v63
	simde_mm_store_ps(v55.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v29.f32), simde_mm_load_ps(v63.f32)));
	// vcmpgefp128 v54,v30,v63
	simde_mm_store_ps(v54.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v63.f32)));
	// vand128 v53,v54,v55
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)v55.u8)));
	// vcmpequw128. v52,v53,v60
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	cr6.setFromMask(simde_mm_load_ps(v52.f32), 0xF);
	// mfocrf r10,2
	ctx.r10.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r11,r3,25,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 25) & 0x1;
	// rlwinm r10,r10,25,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217C324"))) PPC_WEAK_FUNC(sub_8217C324);
PPC_FUNC_IMPL(__imp__sub_8217C324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217C328"))) PPC_WEAK_FUNC(sub_8217C328);
PPC_FUNC_IMPL(__imp__sub_8217C328) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	// addi r11,r1,-16
	r11.s64 = ctx.r1.s64 + -16;
	// stfs f1,-16(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// stfs f2,-12(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stfs f3,-8(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// li r10,912
	ctx.r10.s64 = 912;
	// stfs f4,-4(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// li r9,896
	ctx.r9.s64 = 896;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v0,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// beq cr6,0x8217c40c
	if (cr6.eq) goto loc_8217C40C;
	// li r7,976
	ctx.r7.s64 = 976;
	// lvx128 v12,r3,r10
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,960
	ctx.r6.s64 = 960;
	// lvx128 v11,r3,r9
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v10,v0,v11,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// li r5,880
	ctx.r5.s64 = 880;
	// vspltw128 v13,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// li r4,944
	ctx.r4.s64 = 944;
	// li r11,864
	r11.s64 = 864;
	// vspltw128 v12,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v9,r3,r7
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,928
	ctx.r10.s64 = 928;
	// lvx128 v8,r3,r6
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v61,v63,3
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x0));
	// vmaddfp v7,v0,v8,v9
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// lvx128 v6,r3,r5
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v5,r3,r4
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v4,r3,r11
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,-32
	ctx.r9.s64 = ctx.r1.s64 + -32;
	// lvx128 v3,r3,r10
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v60,-1
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// vsubfp128 v59,v62,v61
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
	// vmaddfp v2,v13,v6,v10
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v1,v13,v5,v7
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v31,v12,v4,v2
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v30,v12,v3,v1
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vaddfp128 v58,v31,v61
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(v61.f32)));
	// vcmpgefp128 v57,v31,v59
	simde_mm_store_ps(v57.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(v59.f32)));
	// vcmpgefp128 v56,v30,v59
	simde_mm_store_ps(v56.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v59.f32)));
	// vspltw128 v55,v58,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vand128 v54,v57,v56
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v56.u8)));
	// stvewx128 v55,r0,r9
	ea = (ctx.r9.u32) & ~0x3;
	PPC_STORE_U32(ea, v55.u32[3 - ((ea & 0xF) >> 2)]);
	// lfs f0,-32(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -32);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// vcmpequw128. v53,v54,v60
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	cr6.setFromMask(simde_mm_load_ps(v53.f32), 0xF);
	// mfocrf r8,2
	ctx.r8.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// vcmpgefp128 v52,v30,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v52.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v61.f32)));
	// vcmpgefp128 v51,v31,v61
	simde_mm_store_ps(v51.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(v61.f32)));
	// vand128 v50,v51,v52
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)v52.u8)));
	// vcmpequw128. v49,v50,v60
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	cr6.setFromMask(simde_mm_load_ps(v49.f32), 0xF);
	// mfocrf r7,2
	ctx.r7.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r11,r8,25,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 25) & 0x1;
	// rlwinm r10,r7,25,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 25) & 0x1;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// blr 
	return;
loc_8217C40C:
	// li r8,976
	ctx.r8.s64 = 976;
	// lvx128 v13,r3,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,960
	ctx.r7.s64 = 960;
	// lvx128 v12,r3,r9
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v5,v0,v12,v13
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// li r6,880
	ctx.r6.s64 = 880;
	// li r5,944
	ctx.r5.s64 = 944;
	// vspltw128 v13,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// li r4,864
	ctx.r4.s64 = 864;
	// vspltw128 v12,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v11,r3,r8
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,928
	ctx.r10.s64 = 928;
	// lvx128 v10,r3,r7
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v48,0
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_set1_epi32(int(0x0)));
	// vmaddfp v4,v0,v10,v11
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// lvx128 v9,r3,r6
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v8,r3,r5
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v46,v63,3
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x0));
	// lvx128 v7,r3,r4
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v47,-1
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lvx128 v6,r3,r10
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v45,v48,v46
	simde_mm_store_ps(v45.f32, simde_mm_sub_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v46.f32)));
	// vmaddfp v3,v13,v9,v5
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v2,v13,v8,v4
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v1,v12,v7,v3
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v31,v12,v6,v2
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vcmpgefp128 v44,v1,v45
	simde_mm_store_ps(v44.f32, simde_mm_cmpge_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(v45.f32)));
	// vcmpgefp128 v43,v31,v45
	simde_mm_store_ps(v43.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(v45.f32)));
	// vand128 v42,v44,v43
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)v43.u8)));
	// vcmpequw128. v41,v42,v47
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	cr6.setFromMask(simde_mm_load_ps(v41.f32), 0xF);
	// mfocrf r9,2
	ctx.r9.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// vcmpgefp128 v40,v31,v46
	simde_mm_store_ps(v40.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(v46.f32)));
	// vcmpgefp128 v39,v1,v46
	simde_mm_store_ps(v39.f32, simde_mm_cmpge_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(v46.f32)));
	// vand128 v38,v39,v40
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)v40.u8)));
	// vcmpequw128. v37,v38,v47
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	cr6.setFromMask(simde_mm_load_ps(v37.f32), 0xF);
	// mfocrf r8,2
	ctx.r8.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r11,r9,25,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0x1;
	// rlwinm r10,r8,25,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 25) & 0x1;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217C4AC"))) PPC_WEAK_FUNC(sub_8217C4AC);
PPC_FUNC_IMPL(__imp__sub_8217C4AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217C4B0"))) PPC_WEAK_FUNC(sub_8217C4B0);
PPC_FUNC_IMPL(__imp__sub_8217C4B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f13,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// lfs f12,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r3,128
	r11.s64 = ctx.r3.s64 + 128;
	// li r7,48
	ctx.r7.s64 = 48;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r6,32
	ctx.r6.s64 = 32;
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// li r10,16
	ctx.r10.s64 = 16;
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v62,v63,3
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x0));
	// lvx128 v61,r11,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v0,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vmulfp128 v13,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
	// lvx128 v12,r11,r6
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v11,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// lvx128 v10,r11,r10
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v9,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v8,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f4,12(r4)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f4.f64 = double(temp.f32);
	// vmaddfp v7,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v6,v11,v10,v7
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v5,v9,v8,v6
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v5,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217c328
	ctx.lr = 0x8217C54C;
	sub_8217C328(ctx, base);
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

__attribute__((alias("__imp__sub_8217C560"))) PPC_WEAK_FUNC(sub_8217C560);
PPC_FUNC_IMPL(__imp__sub_8217C560) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,640
	ctx.r3.s64 = ctx.r3.s64 + 640;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217C568"))) PPC_WEAK_FUNC(sub_8217C568);
PPC_FUNC_IMPL(__imp__sub_8217C568) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,448
	ctx.r3.s64 = ctx.r3.s64 + 448;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217C570"))) PPC_WEAK_FUNC(sub_8217C570);
PPC_FUNC_IMPL(__imp__sub_8217C570) {
	PPC_FUNC_PROLOGUE();
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
	// lvx128 v1,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r3,512
	ctx.r4.s64 = ctx.r3.s64 + 512;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x8217bd00
	ctx.lr = 0x8217C59C;
	sub_8217BD00(ctx, base);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// stfs f13,0(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
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

__attribute__((alias("__imp__sub_8217C5C4"))) PPC_WEAK_FUNC(sub_8217C5C4);
PPC_FUNC_IMPL(__imp__sub_8217C5C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217C5C8"))) PPC_WEAK_FUNC(sub_8217C5C8);
PPC_FUNC_IMPL(__imp__sub_8217C5C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
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
	// addi r10,r4,48
	ctx.r10.s64 = ctx.r4.s64 + 48;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r4,32
	ctx.r9.s64 = ctx.r4.s64 + 32;
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r8,r4,16
	ctx.r8.s64 = ctx.r4.s64 + 16;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r6,32
	ctx.r6.s64 = 32;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v58,v63,v60
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrghw128 v57,v59,v62
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrglw128 v56,v59,v62
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrglw128 v55,v63,v60
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrghw128 v54,v58,v57
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrglw128 v53,v58,v57
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrghw128 v52,v55,v56
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// stvx128 v54,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r3,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r0,r9
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r0,r8
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r0,r10
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r4
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v46,v51,v49
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v49.f32), 0xEF));
	// vmsum3fp128 v47,v48,v49
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v49.f32), 0xEF));
	// vmsum3fp128 v45,v50,v49
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v49.f32), 0xEF));
	// vmrghw128 v44,v46,v47
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v43,v45,v44
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v42,v44,v43
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vor128 v41,v42,v42
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_load_si128((simde__m128i*)v42.u8));
	// stvx128 v42,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v40,v61,v41
	simde_mm_store_ps(v40.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v41.f32)));
	// stvx128 v40,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217C658"))) PPC_WEAK_FUNC(sub_8217C658);
PPC_FUNC_IMPL(__imp__sub_8217C658) {
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
	ctx.lr = 0x8217C660;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r30,-32124
	r30.s64 = -2105278464;
	// addi r31,r11,-26888
	r31.s64 = r11.s64 + -26888;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwz r28,-26876(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + -26876);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8217c69c
	if (!cr6.eq) goto loc_8217C69C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-26880
	ctx.r3.s64 = r11.s64 + -26880;
	// bl 0x8218a4e8
	ctx.lr = 0x8217C698;
	sub_8218A4E8(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
loc_8217C69C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8217c6bc
	if (!cr6.eq) goto loc_8217C6BC;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-26892
	ctx.r3.s64 = r11.s64 + -26892;
	// bl 0x8218a4e8
	ctx.lr = 0x8217C6B8;
	sub_8218A4E8(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_8217C6BC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8217c6dc
	if (!cr6.eq) goto loc_8217C6DC;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-26912
	ctx.r3.s64 = r11.s64 + -26912;
	// bl 0x8218a4e8
	ctx.lr = 0x8217C6D8;
	sub_8218A4E8(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
loc_8217C6DC:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8217c6fc
	if (!cr6.eq) goto loc_8217C6FC;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-26924
	ctx.r3.s64 = r11.s64 + -26924;
	// bl 0x8218a4e8
	ctx.lr = 0x8217C6F8;
	sub_8218A4E8(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
loc_8217C6FC:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r29,-26876(r30)
	PPC_STORE_U32(r30.u32 + -26876, r29.u32);
	// beq cr6,0x8217c730
	if (cr6.eq) goto loc_8217C730;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8217c730
	if (cr6.eq) goto loc_8217C730;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8217be78
	ctx.lr = 0x8217C71C;
	sub_8217BE78(ctx, base);
	// lwz r3,-26876(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -26876);
	// bl 0x8217bde8
	ctx.lr = 0x8217C724;
	sub_8217BDE8(ctx, base);
	// lwz r11,-26876(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -26876);
	// addi r3,r11,640
	ctx.r3.s64 = r11.s64 + 640;
	// bl 0x82179950
	ctx.lr = 0x8217C730;
	sub_82179950(ctx, base);
loc_8217C730:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8217C73C"))) PPC_WEAK_FUNC(sub_8217C73C);
PPC_FUNC_IMPL(__imp__sub_8217C73C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217C740"))) PPC_WEAK_FUNC(sub_8217C740);
PPC_FUNC_IMPL(__imp__sub_8217C740) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f30.u64);
	// stfd f31,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r5,r31,384
	ctx.r5.s64 = r31.s64 + 384;
	// addi r4,r31,448
	ctx.r4.s64 = r31.s64 + 448;
	// bl 0x8215e000
	ctx.lr = 0x8217C770;
	sub_8215E000(ctx, base);
	// lfs f0,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	f0.f64 = double(temp.f32);
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// addi r11,r31,768
	r11.s64 = r31.s64 + 768;
	// lfs f13,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// fadds f5,f10,f0
	ctx.f5.f64 = double(float(ctx.f10.f64 + f0.f64));
	// lfs f9,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f1,f0,f10
	ctx.f1.f64 = double(float(f0.f64 - ctx.f10.f64));
	// lfs f12,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f12.f64 = double(temp.f32);
	// fadds f4,f9,f13
	ctx.f4.f64 = double(float(ctx.f9.f64 + ctx.f13.f64));
	// lfs f11,140(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f13,f9
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// lfs f8,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f8.f64 = double(temp.f32);
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// lfs f7,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f7.f64 = double(temp.f32);
	// fadds f3,f8,f12
	ctx.f3.f64 = double(float(ctx.f8.f64 + ctx.f12.f64));
	// lfs f6,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f6.f64 = double(temp.f32);
	// fadds f2,f7,f11
	ctx.f2.f64 = double(float(ctx.f7.f64 + ctx.f11.f64));
	// fsubs f9,f12,f8
	ctx.f9.f64 = double(float(ctx.f12.f64 - ctx.f8.f64));
	// stfs f5,784(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 784, temp.u32);
	// stfs f4,788(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 788, temp.u32);
	// fsubs f8,f11,f7
	ctx.f8.f64 = double(float(ctx.f11.f64 - ctx.f7.f64));
	// stfs f3,792(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 792, temp.u32);
	// fsubs f7,f0,f6
	ctx.f7.f64 = double(float(f0.f64 - ctx.f6.f64));
	// stfs f2,796(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 796, temp.u32);
	// fadds f6,f6,f0
	ctx.f6.f64 = double(float(ctx.f6.f64 + f0.f64));
	// stfs f1,800(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 800, temp.u32);
	// addi r4,r5,2528
	ctx.r4.s64 = ctx.r5.s64 + 2528;
	// stfs f10,804(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 804, temp.u32);
	// addi r10,r31,784
	ctx.r10.s64 = r31.s64 + 784;
	// stfs f9,808(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 808, temp.u32);
	// addi r9,r31,800
	ctx.r9.s64 = r31.s64 + 800;
	// stfs f8,812(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 812, temp.u32);
	// addi r8,r31,832
	ctx.r8.s64 = r31.s64 + 832;
	// stfs f7,832(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 832, temp.u32);
	// addi r7,r31,848
	ctx.r7.s64 = r31.s64 + 848;
	// addi r6,r31,816
	ctx.r6.s64 = r31.s64 + 816;
	// lis r3,-32122
	ctx.r3.s64 = -2105147392;
	// lfs f5,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f5.f64 = double(temp.f32);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lfs f4,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f2,f13,f5
	ctx.f2.f64 = double(float(ctx.f13.f64 - ctx.f5.f64));
	// lfs f3,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f1,f12,f4
	ctx.f1.f64 = double(float(ctx.f12.f64 - ctx.f4.f64));
	// stfs f2,836(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 836, temp.u32);
	// fsubs f10,f11,f3
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f3.f64));
	// stfs f1,840(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 840, temp.u32);
	// fadds f9,f5,f13
	ctx.f9.f64 = double(float(ctx.f5.f64 + ctx.f13.f64));
	// lfs f2,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f2.f64 = double(temp.f32);
	// fadds f8,f4,f12
	ctx.f8.f64 = double(float(ctx.f4.f64 + ctx.f12.f64));
	// stfs f10,844(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 844, temp.u32);
	// fadds f7,f3,f11
	ctx.f7.f64 = double(float(ctx.f3.f64 + ctx.f11.f64));
	// lfs f1,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f5,f0,f2
	ctx.f5.f64 = double(float(f0.f64 - ctx.f2.f64));
	// lfs f31,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f31.f64 = double(temp.f32);
	// fsubs f4,f13,f1
	ctx.f4.f64 = double(float(ctx.f13.f64 - ctx.f1.f64));
	// lfs f30,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	f30.f64 = double(temp.f32);
	// fsubs f3,f12,f31
	ctx.f3.f64 = double(float(ctx.f12.f64 - f31.f64));
	// stfs f6,848(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 848, temp.u32);
	// fsubs f0,f11,f30
	f0.f64 = double(float(ctx.f11.f64 - f30.f64));
	// stfs f9,852(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 852, temp.u32);
	// stfs f8,856(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 856, temp.u32);
	// stfs f7,860(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 860, temp.u32);
	// stfs f2,768(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 768, temp.u32);
	// stfs f1,772(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 772, temp.u32);
	// stfs f31,776(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 776, temp.u32);
	// stfs f30,780(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 780, temp.u32);
	// stfs f5,816(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 816, temp.u32);
	// stfs f4,820(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 820, temp.u32);
	// stfs f3,824(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 824, temp.u32);
	// stfs f0,828(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 828, temp.u32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v62,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vrsqrtefp128 v61,v62
	simde_mm_store_ps(v61.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v62.f32))));
	// vor128 v60,v63,v63
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vor128 v12,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// vor128 v11,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r3,2240
	ctx.r3.s64 = ctx.r3.s64 + 2240;
	// vcmpeqfp128 v10,v61,v63
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// lis r30,-32130
	r30.s64 = -2105671680;
	// addi r5,r5,-31648
	ctx.r5.s64 = ctx.r5.s64 + -31648;
	// addi r30,r30,-31664
	r30.s64 = r30.s64 + -31664;
	// lvx128 v9,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel v0,v11,v9,v10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8))));
	// vmulfp128 v8,v0,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v7,v63,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v6,v12,v8,v13
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v5,v6,v7,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v59,v60,v5
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v5.f32)));
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v57,v58,v58
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// vrsqrtefp128 v56,v57
	simde_mm_store_ps(v56.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v57.f32))));
	// lvx128 v13,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v3,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// lvx128 v4,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v55,v58,v58
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// vcmpeqfp128 v2,v56,v62
	simde_mm_store_ps(ctx.v2.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v1,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vsel v0,v1,v4,v2
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8))));
	// vmulfp128 v31,v0,v0
	simde_mm_store_ps(v31.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v30,v63,v0
	simde_mm_store_ps(v30.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v29,v3,v31,v13
	simde_mm_store_ps(v29.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v28,v29,v30,v0
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v29.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v54,v55,v28
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v28.f32)));
	// stvx128 v54,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r9
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v52,v53,v53
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vrsqrtefp128 v51,v52
	simde_mm_store_ps(v51.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v52.f32))));
	// lvx128 v13,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v26,v52,v52
	simde_mm_store_si128((simde__m128i*)v26.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// lvx128 v27,r0,r3
	simde_mm_store_si128((simde__m128i*)v27.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v50,v53,v53
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_load_si128((simde__m128i*)v53.u8));
	// vcmpeqfp128 v25,v51,v62
	simde_mm_store_ps(v25.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v24,v51,v51
	simde_mm_store_si128((simde__m128i*)v24.u8, simde_mm_load_si128((simde__m128i*)v51.u8));
	// vsel v0,v24,v27,v25
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)v24.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v25.u8), simde_mm_load_si128((simde__m128i*)v27.u8))));
	// vmulfp128 v23,v0,v0
	simde_mm_store_ps(v23.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v22,v63,v0
	simde_mm_store_ps(v22.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v21,v26,v23,v13
	simde_mm_store_ps(v21.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v26.f32), simde_mm_load_ps(v23.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v20,v21,v22,v0
	simde_mm_store_ps(v20.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v21.f32), simde_mm_load_ps(v22.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v49,v50,v20
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v20.f32)));
	// stvx128 v49,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r0,r6
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v47,v48,v48
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v48.f32), 0xEF));
	// vrsqrtefp128 v46,v47
	simde_mm_store_ps(v46.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v47.f32))));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v18,v47,v47
	simde_mm_store_si128((simde__m128i*)v18.u8, simde_mm_load_si128((simde__m128i*)v47.u8));
	// lvx128 v19,r0,r3
	simde_mm_store_si128((simde__m128i*)v19.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v45,v48,v48
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_load_si128((simde__m128i*)v48.u8));
	// vcmpeqfp128 v17,v46,v62
	simde_mm_store_ps(v17.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v16,v46,v46
	simde_mm_store_si128((simde__m128i*)v16.u8, simde_mm_load_si128((simde__m128i*)v46.u8));
	// vsel v0,v16,v19,v17
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v17.u8), simde_mm_load_si128((simde__m128i*)v16.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v17.u8), simde_mm_load_si128((simde__m128i*)v19.u8))));
	// vmulfp128 v15,v0,v0
	simde_mm_store_ps(v15.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v14,v63,v0
	simde_mm_store_ps(v14.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v13,v18,v15,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v18.f32), simde_mm_load_ps(v15.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v12,v13,v14,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v14.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v44,v45,v12
	simde_mm_store_ps(v44.f32, simde_mm_mul_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v44,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r0,r8
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v42,v43,v43
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v43.f32), 0xEF));
	// vrsqrtefp128 v41,v42
	simde_mm_store_ps(v41.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v42.f32))));
	// lvx128 v10,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v8,v42,v42
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v42.u8));
	// lvx128 v13,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v40,v43,v43
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_load_si128((simde__m128i*)v43.u8));
	// vcmpeqfp128 v11,v41,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v9,v41,v41
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v41.u8));
	// vsel v0,v9,v10,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8))));
	// vmulfp128 v7,v0,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v6,v63,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v5,v8,v7,v13
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v4,v5,v6,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v39,v40,v4
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(ctx.v4.f32)));
	// stvx128 v39,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r0,r7
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v37,v38,v38
	simde_mm_store_ps(v37.f32, simde_mm_dp_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v38.f32), 0xEF));
	// vrsqrtefp128 v36,v37
	simde_mm_store_ps(v36.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v37.f32))));
	// lvx128 v13,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v2,v37,v37
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v37.u8));
	// lvx128 v3,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v35,v38,v38
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_load_si128((simde__m128i*)v38.u8));
	// vcmpeqfp128 v1,v36,v62
	simde_mm_store_ps(ctx.v1.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v31,v36,v36
	simde_mm_store_si128((simde__m128i*)v31.u8, simde_mm_load_si128((simde__m128i*)v36.u8));
	// vsel v0,v31,v3,v1
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)v31.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8))));
	// vmulfp128 v30,v0,v0
	simde_mm_store_ps(v30.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v29,v63,v0
	simde_mm_store_ps(v29.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v28,v2,v30,v13
	simde_mm_store_ps(v28.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(v30.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v27,v28,v29,v0
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v28.f32), simde_mm_load_ps(v29.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v34,v35,v27
	simde_mm_store_ps(v34.f32, simde_mm_mul_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(v27.f32)));
	// stvx128 v34,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,800(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 800);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,784(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 784);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,768(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 768);
	ctx.f11.f64 = double(temp.f32);
	// stfs f13,872(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 872, temp.u32);
	// stfs f13,876(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 876, temp.u32);
	// stfs f11,864(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 864, temp.u32);
	// stfs f12,868(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 868, temp.u32);
	// lfs f10,804(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 804);
	ctx.f10.f64 = double(temp.f32);
	// lfs f8,772(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 772);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,788(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 788);
	ctx.f9.f64 = double(temp.f32);
	// stfs f8,880(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 880, temp.u32);
	// stfs f9,884(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 884, temp.u32);
	// stfs f10,888(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 888, temp.u32);
	// stfs f10,892(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 892, temp.u32);
	// lfs f7,808(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 808);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,792(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 792);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,776(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 776);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,896(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 896, temp.u32);
	// stfs f6,900(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 900, temp.u32);
	// stfs f7,904(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 904, temp.u32);
	// stfs f7,908(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 908, temp.u32);
	// lfs f4,796(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 796);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,780(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 780);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,812(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 812);
	ctx.f2.f64 = double(temp.f32);
	// stfs f4,916(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 916, temp.u32);
	// stfs f3,912(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 912, temp.u32);
	// stfs f2,920(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 920, temp.u32);
	// stfs f2,924(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 924, temp.u32);
	// lfs f1,848(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 848);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,832(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 832);
	f0.f64 = double(temp.f32);
	// lfs f13,816(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 816);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,928(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 928, temp.u32);
	// stfs f0,932(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 932, temp.u32);
	// stfs f1,936(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 936, temp.u32);
	// stfs f1,940(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 940, temp.u32);
	// lfs f12,852(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 852);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,836(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 836);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,820(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 820);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,944(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 944, temp.u32);
	// stfs f11,948(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 948, temp.u32);
	// stfs f12,952(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 952, temp.u32);
	// stfs f12,956(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 956, temp.u32);
	// lfs f9,856(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 856);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,840(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 840);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,824(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 824);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,960(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 960, temp.u32);
	// stfs f9,968(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 968, temp.u32);
	// stfs f9,972(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 972, temp.u32);
	// stfs f8,964(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 964, temp.u32);
	// lfs f6,860(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 860);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,844(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 844);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,828(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 828);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,976(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 976, temp.u32);
	// stfs f5,980(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 980, temp.u32);
	// stfs f6,984(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 984, temp.u32);
	// stfs f6,988(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 988, temp.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f30,-40(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// lfd f31,-32(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217CB48"))) PPC_WEAK_FUNC(sub_8217CB48);
PPC_FUNC_IMPL(__imp__sub_8217CB48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r11,-26876(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8217c658
	sub_8217C658(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217CB64"))) PPC_WEAK_FUNC(sub_8217CB64);
PPC_FUNC_IMPL(__imp__sub_8217CB64) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217CB68"))) PPC_WEAK_FUNC(sub_8217CB68);
PPC_FUNC_IMPL(__imp__sub_8217CB68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82171600
	ctx.lr = 0x8217CB84;
	sub_82171600(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f13,696(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 696);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lfs f0,-31064(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31064);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f0,17296(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17296);
	f0.f64 = double(temp.f32);
	// fmuls f31,f1,f0
	f31.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fmr f1,f12
	ctx.f1.f64 = ctx.f12.f64;
	// bl 0x823dbf10
	ctx.lr = 0x8217CBA8;
	sub_823DBF10(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// addi r11,r31,448
	r11.s64 = r31.s64 + 448;
	// stfs f11,712(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 712, temp.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// lfs f10,704(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 704);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,708(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 708);
	ctx.f9.f64 = double(temp.f32);
	// addi r9,r11,32
	ctx.r9.s64 = r11.s64 + 32;
	// addi r8,r11,48
	ctx.r8.s64 = r11.s64 + 48;
	// fsubs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmuls f7,f11,f31
	ctx.f7.f64 = double(float(ctx.f11.f64 * f31.f64));
	// stfs f7,716(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 716, temp.u32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_setzero_si128());
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fdivs f6,f0,f11
	ctx.f6.f64 = double(float(f0.f64 / ctx.f11.f64));
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v60,v61,v61
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_setzero_si128());
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fdivs f5,f9,f8
	ctx.f5.f64 = double(float(ctx.f9.f64 / ctx.f8.f64));
	// lvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v58,v59,v59
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_setzero_si128());
	// stvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fdivs f4,f6,f31
	ctx.f4.f64 = double(float(ctx.f6.f64 / f31.f64));
	// lvx128 v57,r0,r8
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v56,v57,v57
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_setzero_si128());
	// stvx128 v56,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f3,f5,f10
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f10.f64));
	// lfs f12,720(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 720);
	ctx.f12.f64 = double(temp.f32);
	// lfs f1,728(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 728);
	ctx.f1.f64 = double(temp.f32);
	// lfs f13,732(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 732);
	ctx.f13.f64 = double(temp.f32);
	// lfs f2,724(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 724);
	ctx.f2.f64 = double(temp.f32);
	// fmuls f10,f2,f6
	ctx.f10.f64 = double(float(ctx.f2.f64 * ctx.f6.f64));
	// lfs f0,14192(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fmuls f11,f4,f12
	ctx.f11.f64 = double(float(ctx.f4.f64 * ctx.f12.f64));
	// stfs f11,448(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 448, temp.u32);
	// stfs f10,468(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 468, temp.u32);
	// stfs f1,480(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 480, temp.u32);
	// stfs f13,484(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 484, temp.u32);
	// stfs f0,492(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 492, temp.u32);
	// stfs f5,488(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 488, temp.u32);
	// stfs f3,504(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 504, temp.u32);
	// bl 0x8217c018
	ctx.lr = 0x8217CC60;
	sub_8217C018(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217c740
	ctx.lr = 0x8217CC68;
	sub_8217C740(ctx, base);
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

__attribute__((alias("__imp__sub_8217CC80"))) PPC_WEAK_FUNC(sub_8217CC80);
PPC_FUNC_IMPL(__imp__sub_8217CC80) {
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
	// fsubs f0,f2,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f2.f64 - ctx.f1.f64));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsubs f11,f4,f3
	ctx.f11.f64 = double(float(ctx.f4.f64 - ctx.f3.f64));
	// fsubs f9,f3,f4
	ctx.f9.f64 = double(float(ctx.f3.f64 - ctx.f4.f64));
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// fsubs f10,f1,f2
	ctx.f10.f64 = double(float(ctx.f1.f64 - ctx.f2.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fsubs f8,f5,f6
	ctx.f8.f64 = double(float(ctx.f5.f64 - ctx.f6.f64));
	// li r8,0
	ctx.r8.s64 = 0;
	// stfs f6,708(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 708, temp.u32);
	// fadds f7,f1,f2
	ctx.f7.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// stfs f5,704(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 704, temp.u32);
	// stfs f4,744(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 744, temp.u32);
	// fadds f4,f3,f4
	ctx.f4.f64 = double(float(ctx.f3.f64 + ctx.f4.f64));
	// lfs f13,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f3,748(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 748, temp.u32);
	// fdivs f3,f13,f0
	ctx.f3.f64 = double(float(ctx.f13.f64 / f0.f64));
	// stfs f1,736(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 736, temp.u32);
	// stfs f2,740(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 740, temp.u32);
	// fdivs f2,f13,f11
	ctx.f2.f64 = double(float(ctx.f13.f64 / ctx.f11.f64));
	// lfs f6,720(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 720);
	ctx.f6.f64 = double(temp.f32);
	// lfs f12,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f11,f13,f10
	ctx.f11.f64 = double(float(ctx.f13.f64 / ctx.f10.f64));
	// fdivs f10,f13,f9
	ctx.f10.f64 = double(float(ctx.f13.f64 / ctx.f9.f64));
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fdivs f9,f13,f8
	ctx.f9.f64 = double(float(ctx.f13.f64 / ctx.f8.f64));
	// stfs f0,452(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 452, temp.u32);
	// fmuls f1,f3,f6
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f6.f64));
	// stfs f0,456(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 456, temp.u32);
	// stfs f0,460(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 460, temp.u32);
	// fdivs f8,f5,f8
	ctx.f8.f64 = double(float(ctx.f5.f64 / ctx.f8.f64));
	// fmuls f6,f1,f12
	ctx.f6.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// stfs f6,448(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 448, temp.u32);
	// lfs f5,724(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 724);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f3,f2,f5
	ctx.f3.f64 = double(float(ctx.f2.f64 * ctx.f5.f64));
	// fmuls f2,f3,f12
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f12.f64));
	// stfs f0,464(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 464, temp.u32);
	// stfs f2,468(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 468, temp.u32);
	// fmuls f1,f11,f7
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f7.f64));
	// stfs f0,472(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 472, temp.u32);
	// fmuls f12,f10,f4
	ctx.f12.f64 = double(float(ctx.f10.f64 * ctx.f4.f64));
	// stfs f0,476(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 476, temp.u32);
	// lfs f11,732(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 732);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,728(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 728);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,480(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 480, temp.u32);
	// stfs f11,484(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 484, temp.u32);
	// stfs f9,488(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 488, temp.u32);
	// stfs f0,492(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 492, temp.u32);
	// stfs f1,496(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 496, temp.u32);
	// stfs f12,500(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 500, temp.u32);
	// stfs f8,504(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 504, temp.u32);
	// stfs f13,508(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 508, temp.u32);
	// stb r8,752(r31)
	PPC_STORE_U8(r31.u32 + 752, ctx.r8.u8);
	// bl 0x8217c018
	ctx.lr = 0x8217CD6C;
	sub_8217C018(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217c740
	ctx.lr = 0x8217CD74;
	sub_8217C740(ctx, base);
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

__attribute__((alias("__imp__sub_8217CD88"))) PPC_WEAK_FUNC(sub_8217CD88);
PPC_FUNC_IMPL(__imp__sub_8217CD88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r11,r31,448
	r11.s64 = r31.s64 + 448;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,32
	ctx.r9.s64 = 32;
	// stb r10,752(r31)
	PPC_STORE_U8(r31.u32 + 752, ctx.r10.u8);
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// bl 0x8217c018
	ctx.lr = 0x8217CDD8;
	sub_8217C018(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217c740
	ctx.lr = 0x8217CDE0;
	sub_8217C740(ctx, base);
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

__attribute__((alias("__imp__sub_8217CDF4"))) PPC_WEAK_FUNC(sub_8217CDF4);
PPC_FUNC_IMPL(__imp__sub_8217CDF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217CDF8"))) PPC_WEAK_FUNC(sub_8217CDF8);
PPC_FUNC_IMPL(__imp__sub_8217CDF8) {
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
	// lbz r11,752(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 752);
	// lfs f0,704(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 704);
	f0.f64 = double(temp.f32);
	// lfs f13,708(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 708);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// beq cr6,0x8217ce30
	if (cr6.eq) goto loc_8217CE30;
	// fdivs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// b 0x8217ce40
	goto loc_8217CE40;
loc_8217CE30:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fdivs f10,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(f0.f64 / ctx.f12.f64));
	// lfs f13,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
loc_8217CE40:
	// stfs f10,504(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 504, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f11,488(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 488, temp.u32);
	// bl 0x8217c018
	ctx.lr = 0x8217CE50;
	sub_8217C018(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217c740
	ctx.lr = 0x8217CE58;
	sub_8217C740(ctx, base);
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

__attribute__((alias("__imp__sub_8217CE6C"))) PPC_WEAK_FUNC(sub_8217CE6C);
PPC_FUNC_IMPL(__imp__sub_8217CE6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217CE70"))) PPC_WEAK_FUNC(sub_8217CE70);
PPC_FUNC_IMPL(__imp__sub_8217CE70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,704(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 704, temp.u32);
	// b 0x8217cdf8
	sub_8217CDF8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217CE78"))) PPC_WEAK_FUNC(sub_8217CE78);
PPC_FUNC_IMPL(__imp__sub_8217CE78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,708(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 708, temp.u32);
	// b 0x8217cdf8
	sub_8217CDF8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217CE80"))) PPC_WEAK_FUNC(sub_8217CE80);
PPC_FUNC_IMPL(__imp__sub_8217CE80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8217CE88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r4,16
	ctx.r8.s64 = ctx.r4.s64 + 16;
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r31,64
	r11.s64 = r31.s64 + 64;
	// li r30,16
	r30.s64 = 16;
	// addi r7,r4,32
	ctx.r7.s64 = ctx.r4.s64 + 32;
	// li r5,32
	ctx.r5.s64 = 32;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// addi r10,r4,48
	ctx.r10.s64 = ctx.r4.s64 + 48;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,48
	ctx.r6.s64 = 48;
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r9,2384
	r29.s64 = ctx.r9.s64 + 2384;
	// stvx128 v60,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r31,320
	ctx.r9.s64 = r31.s64 + 320;
	// stvx128 v59,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r3,-32122
	ctx.r3.s64 = -2105147392;
	// lvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r3,2352
	r28.s64 = ctx.r3.s64 + 2352;
	// stvx128 v58,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,384
	r11.s64 = r31.s64 + 384;
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v57,r0,r4
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v56,v57,v63
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v56,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v54,v55,v63
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v54,r9,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r7
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v52,v53,v63
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v52,r9,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r10
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v50,v51,v63
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v49,v63,v50
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v50.u8)));
	// stvx128 v49,r9,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r0,r7
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r0,r4
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r0,r8
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r0,r10
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v42,v48,v47
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v43,v44,v45
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vor128 v46,v47,v47
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_load_si128((simde__m128i*)v47.u8));
	// vmrglw128 v40,v44,v45
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrglw128 v38,v48,v47
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v36,v43,v42
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmsum3fp128 v41,v45,v46
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v46.f32), 0xEF));
	// vmrglw128 v35,v43,v42
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmsum3fp128 v39,v44,v46
	simde_mm_store_ps(v39.f32, simde_mm_dp_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v46.f32), 0xEF));
	// vmrghw128 v34,v40,v38
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmsum3fp128 v37,v48,v46
	simde_mm_store_ps(v37.f32, simde_mm_dp_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v46.f32), 0xEF));
	// vand128 v33,v36,v63
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v33,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v32,v35,v63
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v32,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v60,v39,v41
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v59,v34,v63
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v59,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v58,v37,v60
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// lvx128 v62,r0,r28
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v60,v58
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vsubfp128 v56,v61,v57
	simde_mm_store_ps(v56.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v57.f32)));
	// vand128 v55,v56,v63
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v54,v62,v55
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v55.u8)));
	// stvx128 v54,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217c018
	ctx.lr = 0x8217CFBC;
	sub_8217C018(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217c740
	ctx.lr = 0x8217CFC4;
	sub_8217C740(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8217CFCC"))) PPC_WEAK_FUNC(sub_8217CFCC);
PPC_FUNC_IMPL(__imp__sub_8217CFCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217CFD0"))) PPC_WEAK_FUNC(sub_8217CFD0);
PPC_FUNC_IMPL(__imp__sub_8217CFD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r4,16
	ctx.r6.s64 = ctx.r4.s64 + 16;
	// addi r11,r31,64
	r11.s64 = r31.s64 + 64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r5,r4,32
	ctx.r5.s64 = ctx.r4.s64 + 32;
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r3,r4,48
	ctx.r3.s64 = ctx.r4.s64 + 48;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,48
	ctx.r9.s64 = 48;
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r31,320
	ctx.r10.s64 = r31.s64 + 320;
	// lvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,384
	r11.s64 = r31.s64 + 384;
	// lvx128 v59,r0,r4
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r6
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r5
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r3
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v56,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r0,r30
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r30,r7
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r30,r8
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r30,r9
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217c018
	ctx.lr = 0x8217D078;
	sub_8217C018(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217c740
	ctx.lr = 0x8217D080;
	sub_8217C740(ctx, base);
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

__attribute__((alias("__imp__sub_8217D098"))) PPC_WEAK_FUNC(sub_8217D098);
PPC_FUNC_IMPL(__imp__sub_8217D098) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,688(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 688);
	// lfs f0,644(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 644);
	f0.f64 = double(temp.f32);
	// lwz r10,692(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 692);
	// lfs f12,652(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 652);
	ctx.f12.f64 = double(temp.f32);
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// lfs f13,640(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 640);
	ctx.f13.f64 = double(temp.f32);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// lfs f11,648(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 648);
	ctx.f11.f64 = double(temp.f32);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// fadds f2,f12,f0
	ctx.f2.f64 = double(float(ctx.f12.f64 + f0.f64));
	// lfs f6,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f6.f64 = double(temp.f32);
	// fadds f12,f11,f13
	ctx.f12.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// frsp f11,f7
	ctx.f11.f64 = double(float(ctx.f7.f64));
	// lfs f5,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	ctx.f5.f64 = double(temp.f32);
	// frsp f3,f8
	ctx.f3.f64 = double(float(ctx.f8.f64));
	// fmuls f1,f11,f13
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fmuls f4,f0,f3
	ctx.f4.f64 = double(float(f0.f64 * ctx.f3.f64));
	// fmuls f3,f2,f3
	ctx.f3.f64 = double(float(ctx.f2.f64 * ctx.f3.f64));
	// fmuls f2,f12,f11
	ctx.f2.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// bl 0x8217cc80
	ctx.lr = 0x8217D110;
	sub_8217CC80(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217D120"))) PPC_WEAK_FUNC(sub_8217D120);
PPC_FUNC_IMPL(__imp__sub_8217D120) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8217D128;
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bge cr6,0x8217d158
	if (!cr6.lt) goto loc_8217D158;
	// add r6,r4,r6
	ctx.r6.u64 = ctx.r4.u64 + ctx.r6.u64;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8217D158:
	// lwz r10,688(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 688);
	// add r11,r4,r6
	r11.u64 = ctx.r4.u64 + ctx.r6.u64;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// ble cr6,0x8217d16c
	if (!cr6.gt) goto loc_8217D16C;
	// subf r6,r4,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r4.s64;
loc_8217D16C:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bge cr6,0x8217d17c
	if (!cr6.lt) goto loc_8217D17C;
	// add r7,r5,r7
	ctx.r7.u64 = ctx.r5.u64 + ctx.r7.u64;
	// li r5,0
	ctx.r5.s64 = 0;
loc_8217D17C:
	// lwz r11,692(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 692);
	// add r30,r5,r7
	r30.u64 = ctx.r5.u64 + ctx.r7.u64;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// ble cr6,0x8217d190
	if (!cr6.gt) goto loc_8217D190;
	// subf r7,r5,r11
	ctx.r7.s64 = r11.s64 - ctx.r5.s64;
loc_8217D190:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bge cr6,0x8217d19c
	if (!cr6.lt) goto loc_8217D19C;
	// li r6,0
	ctx.r6.s64 = 0;
loc_8217D19C:
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bge cr6,0x8217d1a8
	if (!cr6.lt) goto loc_8217D1A8;
	// li r7,0
	ctx.r7.s64 = 0;
loc_8217D1A8:
	// extsw r28,r6
	r28.s64 = ctx.r6.s32;
	// stfs f1,680(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 680, temp.u32);
	// extsw r30,r5
	r30.s64 = ctx.r5.s32;
	// stfs f2,684(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 684, temp.u32);
	// std r28,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r28.u64);
	// extsw r28,r29
	r28.s64 = r29.s32;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r30,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r30.u64);
	// std r28,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, r28.u64);
	// extsw r30,r3
	r30.s64 = ctx.r3.s32;
	// std r10,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r10.u64);
	// extsw r28,r4
	r28.s64 = ctx.r4.s32;
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lfd f9,112(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// std r30,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r30.u64);
	// extsw r27,r7
	r27.s64 = ctx.r7.s32;
	// std r28,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r28.u64);
	// lfd f6,136(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// extsw r30,r8
	r30.s64 = ctx.r8.s32;
	// lfd f5,80(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfd f3,112(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// std r27,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r27.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r30,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, r30.u64);
	// lfd f11,96(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// srawi r11,r6,1
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	r11.s64 = ctx.r6.s32 >> 1;
	// lfd f10,104(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// extsw r27,r9
	r27.s64 = ctx.r9.s32;
	// lfd f7,128(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// std r27,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, r27.u64);
	// std r10,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r10.u64);
	// lfd f4,136(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// lfd f8,120(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// fcfid f6,f6
	ctx.f6.f64 = double(ctx.f6.s64);
	// lis r28,-32256
	r28.s64 = -2113929216;
	// fcfid f5,f5
	ctx.f5.f64 = double(ctx.f5.s64);
	// stfs f1,656(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 656, temp.u32);
	// fcfid f3,f3
	ctx.f3.f64 = double(ctx.f3.s64);
	// stfs f2,660(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 660, temp.u32);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// addi r30,r31,640
	r30.s64 = r31.s64 + 640;
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// fcfid f31,f10
	f31.f64 = double(ctx.f10.s64);
	// lfs f0,3796(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcfid f7,f7
	ctx.f7.f64 = double(ctx.f7.s64);
	// fcfid f8,f8
	ctx.f8.f64 = double(ctx.f8.s64);
	// frsp f6,f6
	ctx.f6.f64 = double(float(ctx.f6.f64));
	// frsp f5,f5
	ctx.f5.f64 = double(float(ctx.f5.f64));
	// frsp f3,f3
	ctx.f3.f64 = double(float(ctx.f3.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// frsp f30,f9
	f30.f64 = double(float(ctx.f9.f64));
	// frsp f9,f7
	ctx.f9.f64 = double(float(ctx.f7.f64));
	// frsp f11,f8
	ctx.f11.f64 = double(float(ctx.f8.f64));
	// frsp f31,f31
	f31.f64 = double(float(f31.f64));
	// fcfid f8,f4
	ctx.f8.f64 = double(ctx.f4.s64);
	// fdivs f7,f5,f6
	ctx.f7.f64 = double(float(ctx.f5.f64 / ctx.f6.f64));
	// stfs f7,640(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 640, temp.u32);
	// fdivs f5,f13,f3
	ctx.f5.f64 = double(float(ctx.f13.f64 / ctx.f3.f64));
	// stfs f5,644(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 644, temp.u32);
	// fdivs f4,f12,f6
	ctx.f4.f64 = double(float(ctx.f12.f64 / ctx.f6.f64));
	// stfs f4,648(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 648, temp.u32);
	// fdivs f13,f10,f3
	ctx.f13.f64 = double(float(ctx.f10.f64 / ctx.f3.f64));
	// stfs f13,652(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 652, temp.u32);
	// fdivs f5,f30,f3
	ctx.f5.f64 = double(float(f30.f64 / ctx.f3.f64));
	// stfs f5,668(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 668, temp.u32);
	// fdivs f3,f9,f3
	ctx.f3.f64 = double(float(ctx.f9.f64 / ctx.f3.f64));
	// stfs f3,676(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 676, temp.u32);
	// fdivs f4,f11,f6
	ctx.f4.f64 = double(float(ctx.f11.f64 / ctx.f6.f64));
	// stfs f4,672(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 672, temp.u32);
	// fdivs f7,f31,f6
	ctx.f7.f64 = double(float(f31.f64 / ctx.f6.f64));
	// stfs f7,664(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 664, temp.u32);
	// frsp f13,f8
	ctx.f13.f64 = double(float(ctx.f8.f64));
	// stfs f13,576(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 576, temp.u32);
	// stfs f0,580(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 580, temp.u32);
	// neg r10,r7
	ctx.r10.s64 = -ctx.r7.s64;
	// fsubs f8,f2,f1
	ctx.f8.f64 = double(float(ctx.f2.f64 - ctx.f1.f64));
	// add r4,r11,r4
	ctx.r4.u64 = r11.u64 + ctx.r4.u64;
	// stfs f0,584(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 584, temp.u32);
	// srawi r10,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// stfs f0,588(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 588, temp.u32);
	// srawi r11,r7,1
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	r11.s64 = ctx.r7.s32 >> 1;
	// stfs f0,592(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 592, temp.u32);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// stfs f0,600(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 600, temp.u32);
	// add r5,r11,r5
	ctx.r5.u64 = r11.u64 + ctx.r5.u64;
	// stfs f0,604(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 604, temp.u32);
	// std r10,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r10.u64);
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// extsw r11,r5
	r11.s64 = ctx.r5.s32;
	// lfd f7,136(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// std r10,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r10.u64);
	// fcfid f3,f7
	ctx.f3.f64 = double(ctx.f7.s64);
	// std r11,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, r11.u64);
	// lfd f6,136(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// frsp f6,f3
	ctx.f6.f64 = double(float(ctx.f3.f64));
	// stfs f6,596(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 596, temp.u32);
	// stfs f0,608(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 608, temp.u32);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// stfs f0,612(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 612, temp.u32);
	// stfs f8,616(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 616, temp.u32);
	// lfs f13,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,620(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 620, temp.u32);
	// stfs f1,632(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 632, temp.u32);
	// stfs f13,636(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 636, temp.u32);
	// frsp f7,f5
	ctx.f7.f64 = double(float(ctx.f5.f64));
	// stfs f7,624(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 624, temp.u32);
	// lfd f4,128(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f2,f4
	ctx.f2.f64 = double(ctx.f4.s64);
	// frsp f5,f2
	ctx.f5.f64 = double(float(ctx.f2.f64));
	// stfs f5,628(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 628, temp.u32);
	// beq cr6,0x8217d3b8
	if (cr6.eq) goto loc_8217D3B8;
	// subf r11,r6,r9
	r11.s64 = ctx.r9.s64 - ctx.r6.s64;
	// fdivs f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r10.u64);
	// lfd f8,136(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// fmuls f5,f11,f12
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// stfs f5,720(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 720, temp.u32);
	// fmuls f4,f6,f12
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f12.f64));
	// stfs f4,728(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 728, temp.u32);
	// b 0x8217d3c0
	goto loc_8217D3C0;
loc_8217D3B8:
	// stfs f13,720(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 720, temp.u32);
	// stfs f0,728(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 728, temp.u32);
loc_8217D3C0:
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x8217d3f4
	if (cr6.eq) goto loc_8217D3F4;
	// subf r11,r7,r8
	r11.s64 = ctx.r8.s64 - ctx.r7.s64;
	// fdivs f0,f13,f10
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f13.f64 / ctx.f10.f64));
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r10.u64);
	// lfd f12,136(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f13,f9,f0
	ctx.f13.f64 = double(float(ctx.f9.f64 * f0.f64));
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// stfs f9,732(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 732, temp.u32);
	// b 0x8217d3f8
	goto loc_8217D3F8;
loc_8217D3F4:
	// stfs f0,732(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 732, temp.u32);
loc_8217D3F8:
	// stfs f13,724(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 724, temp.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8217d410
	if (!cr6.gt) goto loc_8217D410;
	// lfs f0,728(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 728);
	f0.f64 = double(temp.f32);
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f13,728(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 728, temp.u32);
loc_8217D410:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bge cr6,0x8217d424
	if (!cr6.lt) goto loc_8217D424;
	// lfs f0,732(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 732);
	f0.f64 = double(temp.f32);
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f13,732(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 732, temp.u32);
loc_8217D424:
	// lbz r11,752(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 752);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8217d438
	if (cr6.eq) goto loc_8217D438;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217cb68
	ctx.lr = 0x8217D438;
	sub_8217CB68(ctx, base);
loc_8217D438:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r11,-26876(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bne cr6,0x8217d450
	if (!cr6.eq) goto loc_8217D450;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82179950
	ctx.lr = 0x8217D450;
	sub_82179950(ctx, base);
loc_8217D450:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8217D460"))) PPC_WEAK_FUNC(sub_8217D460);
PPC_FUNC_IMPL(__imp__sub_8217D460) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// li r11,1
	r11.s64 = 1;
	// stfs f1,696(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 696, temp.u32);
	// stfs f2,700(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 700, temp.u32);
	// stfs f3,704(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 704, temp.u32);
	// stb r11,752(r3)
	PPC_STORE_U8(ctx.r3.u32 + 752, r11.u8);
	// stfs f4,708(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 708, temp.u32);
	// b 0x8217cb68
	sub_8217CB68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217D47C"))) PPC_WEAK_FUNC(sub_8217D47C);
PPC_FUNC_IMPL(__imp__sub_8217D47C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217D480"))) PPC_WEAK_FUNC(sub_8217D480);
PPC_FUNC_IMPL(__imp__sub_8217D480) {
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
	// lis r30,-32124
	r30.s64 = -2105278464;
	// lwz r31,-26880(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -26880);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8217d4c8
	if (cr6.eq) goto loc_8217D4C8;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r11,-26876(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// bne cr6,0x8217d4c0
	if (!cr6.eq) goto loc_8217D4C0;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217c658
	ctx.lr = 0x8217D4C0;
	sub_8217C658(ctx, base);
loc_8217D4C0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x8217D4C8;
	sub_82130588(ctx, base);
loc_8217D4C8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-26880(r30)
	PPC_STORE_U32(r30.u32 + -26880, r11.u32);
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

__attribute__((alias("__imp__sub_8217D4E8"))) PPC_WEAK_FUNC(sub_8217D4E8);
PPC_FUNC_IMPL(__imp__sub_8217D4E8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// stw r11,692(r31)
	PPC_STORE_U32(r31.u32 + 692, r11.u32);
	// stw r11,688(r31)
	PPC_STORE_U32(r31.u32 + 688, r11.u32);
	// bl 0x8217be78
	ctx.lr = 0x8217D50C;
	sub_8217BE78(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r7,692(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 692);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r6,688(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 688);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f2,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217d120
	ctx.lr = 0x8217D534;
	sub_8217D120(ctx, base);
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

__attribute__((alias("__imp__sub_8217D548"))) PPC_WEAK_FUNC(sub_8217D548);
PPC_FUNC_IMPL(__imp__sub_8217D548) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,688(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 688);
	// fmr f13,f2
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f2.f64;
	// lwz r10,692(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 692);
	// fmr f0,f1
	f0.f64 = ctx.f1.f64;
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// fmr f2,f6
	ctx.f2.f64 = ctx.f6.f64;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// fmr f1,f5
	ctx.f1.f64 = ctx.f5.f64;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f12
	ctx.f9.f64 = double(ctx.f12.s64);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fmuls f6,f8,f4
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f4.f64));
	// fmuls f5,f8,f13
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f13.f64));
	// fmuls f4,f7,f3
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f3.f64));
	// fmuls f3,f7,f0
	ctx.f3.f64 = double(float(ctx.f7.f64 * f0.f64));
	// fctiwz f0,f6
	f0.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// fctiwz f13,f5
	ctx.f13.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f13,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f12,f4
	ctx.f12.s64 = (ctx.f4.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// lwz r5,92(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// fctiwz f11,f3
	ctx.f11.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f12,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f12.u64);
	// lwz r6,92(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8217d120
	ctx.lr = 0x8217D5D8;
	sub_8217D120(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217D5E8"))) PPC_WEAK_FUNC(sub_8217D5E8);
PPC_FUNC_IMPL(__imp__sub_8217D5E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -32, f30.u64);
	// stfd f31,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r9,16
	ctx.r9.s64 = 16;
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
	// li r10,32
	ctx.r10.s64 = 32;
	// lfs f31,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r11,48
	r11.s64 = 48;
	// lfs f30,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f30.f64 = double(temp.f32);
	// addi r8,r31,128
	ctx.r8.s64 = r31.s64 + 128;
	// stfs f31,640(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 640, temp.u32);
	// addi r7,r31,64
	ctx.r7.s64 = r31.s64 + 64;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stfs f31,644(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 644, temp.u32);
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stfs f30,648(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 648, temp.u32);
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stfs f30,652(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 652, temp.u32);
	// vpermwi128 v58,v62,234
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stfs f31,656(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 656, temp.u32);
	// vpermwi128 v57,v62,186
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stfs f30,660(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 660, temp.u32);
	// vpermwi128 v56,v62,174
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stfs f31,664(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 664, temp.u32);
	// stfs f31,668(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 668, temp.u32);
	// vpermwi128 v55,v62,171
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x54));
	// stfs f30,672(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 672, temp.u32);
	// vpermwi128 v54,v62,234
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stfs f30,676(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 676, temp.u32);
	// vpermwi128 v53,v62,186
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stfs f31,680(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 680, temp.u32);
	// vpermwi128 v52,v62,174
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stfs f30,684(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 684, temp.u32);
	// vpermwi128 v51,v62,234
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stvx128 v61,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v50,v62,186
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stvx128 v60,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r31,320
	ctx.r6.s64 = r31.s64 + 320;
	// stvx128 v59,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v49,v62,174
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v48,v62,171
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x54));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v47,v62,234
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stvx128 v57,r8,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v46,v62,186
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stvx128 v56,r8,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v45,v62,174
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v55,r8,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r31,384
	ctx.r8.s64 = r31.s64 + 384;
	// stvx128 v54,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v44,v62,171
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x54));
	// stvx128 v53,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v43,v62,234
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stvx128 v52,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v42,v62,186
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stvx128 v63,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r31,576
	ctx.r7.s64 = r31.s64 + 576;
	// stvx128 v51,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v41,v62,174
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v50,r6,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v40,v62,171
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x54));
	// stvx128 v49,r6,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// stvx128 v48,r6,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stvx128 v47,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,1
	ctx.r3.s64 = 1;
	// stvx128 v46,r8,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r8,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r8,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,0
	ctx.r8.s64 = 0;
	// stvx128 v43,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v40,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r3,752(r31)
	PPC_STORE_U8(r31.u32 + 752, ctx.r3.u8);
	// lfs f0,-26872(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -26872);
	f0.f64 = double(temp.f32);
	// stw r8,692(r31)
	PPC_STORE_U32(r31.u32 + 692, ctx.r8.u32);
	// lfs f13,11364(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 11364);
	ctx.f13.f64 = double(temp.f32);
	// stfs f31,700(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 700, temp.u32);
	// stw r8,688(r31)
	PPC_STORE_U32(r31.u32 + 688, ctx.r8.u32);
	// stfs f30,704(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 704, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f30,724(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 724, temp.u32);
	// stfs f30,720(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 720, temp.u32);
	// stfs f31,732(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 732, temp.u32);
	// stfs f31,728(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 728, temp.u32);
	// stfs f0,696(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 696, temp.u32);
	// stfs f13,708(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 708, temp.u32);
	// bl 0x8217be78
	ctx.lr = 0x8217D770;
	sub_8217BE78(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r7,692(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 692);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,688(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 688);
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8217d120
	ctx.lr = 0x8217D790;
	sub_8217D120(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f30,-32(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217D7B0"))) PPC_WEAK_FUNC(sub_8217D7B0);
PPC_FUNC_IMPL(__imp__sub_8217D7B0) {
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
	// li r3,992
	ctx.r3.s64 = 992;
	// bl 0x82130528
	ctx.lr = 0x8217D7C8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8217d7dc
	if (cr6.eq) goto loc_8217D7DC;
	// bl 0x8217d5e8
	ctx.lr = 0x8217D7D4;
	sub_8217D5E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8217d7e0
	goto loc_8217D7E0;
loc_8217D7DC:
	// li r31,0
	r31.s64 = 0;
loc_8217D7E0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217d098
	ctx.lr = 0x8217D7E8;
	sub_8217D098(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,-26848
	ctx.r3.s64 = ctx.r10.s64 + -26848;
	// stw r31,-26880(r11)
	PPC_STORE_U32(r11.u32 + -26880, r31.u32);
	// bl 0x8218a4e8
	ctx.lr = 0x8217D800;
	sub_8218A4E8(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r9,-26868
	ctx.r3.s64 = ctx.r9.s64 + -26868;
	// bl 0x8218a4e8
	ctx.lr = 0x8217D810;
	sub_8218A4E8(ctx, base);
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

__attribute__((alias("__imp__sub_8217D824"))) PPC_WEAK_FUNC(sub_8217D824);
PPC_FUNC_IMPL(__imp__sub_8217D824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217D828"))) PPC_WEAK_FUNC(sub_8217D828);
PPC_FUNC_IMPL(__imp__sub_8217D828) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// add. r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble 0x8217d884
	if (!cr0.gt) goto loc_8217D884;
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
loc_8217D844:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// blt cr6,0x8217d864
	if (cr6.lt) goto loc_8217D864;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8217d868
	if (cr6.lt) goto loc_8217D868;
loc_8217D864:
	// li r11,0
	r11.s64 = 0;
loc_8217D868:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// cmpw cr6,r3,r8
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r8.s32, xer);
	// blt cr6,0x8217d844
	if (cr6.lt) goto loc_8217D844;
loc_8217D884:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217D88C"))) PPC_WEAK_FUNC(sub_8217D88C);
PPC_FUNC_IMPL(__imp__sub_8217D88C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217D890"))) PPC_WEAK_FUNC(sub_8217D890);
PPC_FUNC_IMPL(__imp__sub_8217D890) {
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
	ctx.lr = 0x8217D898;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217d828
	ctx.lr = 0x8217D8B0;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8217d8dc
	if (cr6.eq) goto loc_8217D8DC;
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
	// subf r3,r9,r10
	ctx.r3.s64 = ctx.r10.s64 - ctx.r9.s64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8217D8DC:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r11,-26560
	ctx.r4.s64 = r11.s64 + -26560;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2378
	ctx.lr = 0x8217D8F0;
	sub_821D2378(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8217D8FC"))) PPC_WEAK_FUNC(sub_8217D8FC);
PPC_FUNC_IMPL(__imp__sub_8217D8FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217D900"))) PPC_WEAK_FUNC(sub_8217D900);
PPC_FUNC_IMPL(__imp__sub_8217D900) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r10,-31280
	ctx.r4.s64 = ctx.r10.s64 + -31280;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// b 0x8217c088
	sub_8217C088(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217D914"))) PPC_WEAK_FUNC(sub_8217D914);
PPC_FUNC_IMPL(__imp__sub_8217D914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217D918"))) PPC_WEAK_FUNC(sub_8217D918);
PPC_FUNC_IMPL(__imp__sub_8217D918) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// b 0x8217c088
	sub_8217C088(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217D928"))) PPC_WEAK_FUNC(sub_8217D928);
PPC_FUNC_IMPL(__imp__sub_8217D928) {
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
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217fed0
	ctx.lr = 0x8217D944;
	sub_8217FED0(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// clrlwi r10,r31,24
	ctx.r10.u64 = r31.u32 & 0xFF;
	// rlwinm r9,r11,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// xori r31,r9,1
	r31.u64 = ctx.r9.u64 ^ 1;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// beq cr6,0x8217d968
	if (cr6.eq) goto loc_8217D968;
	// lwz r4,17320(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 17320);
	// b 0x8217d97c
	goto loc_8217D97C;
loc_8217D968:
	// lwz r11,17320(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17320);
	// li r4,0
	ctx.r4.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x8217d97c
	if (!cr6.lt) goto loc_8217D97C;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_8217D97C:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x8217D984;
	sub_8217F768(ctx, base);
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

__attribute__((alias("__imp__sub_8217D99C"))) PPC_WEAK_FUNC(sub_8217D99C);
PPC_FUNC_IMPL(__imp__sub_8217D99C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217D9A0"))) PPC_WEAK_FUNC(sub_8217D9A0);
PPC_FUNC_IMPL(__imp__sub_8217D9A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8217d9b4
	if (!cr6.eq) goto loc_8217D9B4;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r6,-25360(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -25360);
loc_8217D9B4:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// addi r3,r9,-27296
	ctx.r3.s64 = ctx.r9.s64 + -27296;
	// stw r6,-26864(r11)
	PPC_STORE_U32(r11.u32 + -26864, ctx.r6.u32);
	// lwz r5,-28096(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28096);
	// addi r4,r3,48
	ctx.r4.s64 = ctx.r3.s64 + 48;
	// b 0x82189ce0
	sub_82189CE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8217D9D4"))) PPC_WEAK_FUNC(sub_8217D9D4);
PPC_FUNC_IMPL(__imp__sub_8217D9D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217D9D8"))) PPC_WEAK_FUNC(sub_8217D9D8);
PPC_FUNC_IMPL(__imp__sub_8217D9D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r3,-26864(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26864);
	// lwz r11,-25360(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -25360);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217D9F8"))) PPC_WEAK_FUNC(sub_8217D9F8);
PPC_FUNC_IMPL(__imp__sub_8217D9F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8217DA18"))) PPC_WEAK_FUNC(sub_8217DA18);
PPC_FUNC_IMPL(__imp__sub_8217DA18) {
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
	// beq cr6,0x8217da5c
	if (cr6.eq) goto loc_8217DA5C;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8217DA3C;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8217da5c
	if (!cr6.eq) goto loc_8217DA5C;
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
	ctx.lr = 0x8217DA5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8217DA5C:
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

__attribute__((alias("__imp__sub_8217DA70"))) PPC_WEAK_FUNC(sub_8217DA70);
PPC_FUNC_IMPL(__imp__sub_8217DA70) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x8217DA78;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x8217bb68
	ctx.lr = 0x8217DA94;
	sub_8217BB68(ctx, base);
	// lis r28,-32124
	r28.s64 = -2105278464;
	// lis r27,-32124
	r27.s64 = -2105278464;
	// lis r26,-32124
	r26.s64 = -2105278464;
	// lis r25,-32124
	r25.s64 = -2105278464;
	// lis r24,-32124
	r24.s64 = -2105278464;
	// stw r31,-26892(r28)
	PPC_STORE_U32(r28.u32 + -26892, r31.u32);
	// lis r23,-32124
	r23.s64 = -2105278464;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// lfs f8,-26924(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-26896(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DAD8;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + -26892);
	// lfs f8,-26924(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-26896(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DB00;
	sub_8217BC28(ctx, base);
	// bl 0x8217bc98
	ctx.lr = 0x8217DB04;
	sub_8217BC98(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8217DB0C"))) PPC_WEAK_FUNC(sub_8217DB0C);
PPC_FUNC_IMPL(__imp__sub_8217DB0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217DB10"))) PPC_WEAK_FUNC(sub_8217DB10);
PPC_FUNC_IMPL(__imp__sub_8217DB10) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8217DB18;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823db9ac
	ctx.lr = 0x8217DB20;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v62,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmulfp128 v60,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// lwz r3,-26876(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -26876);
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f29,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f29.f64 = double(temp.f32);
	// lfs f31,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f31.f64 = double(temp.f32);
	// lfs f30,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f30.f64 = double(temp.f32);
	// fneg f13,f30
	ctx.f13.u64 = f30.u64 ^ 0x8000000000000000;
	// fneg f0,f31
	f0.u64 = f31.u64 ^ 0x8000000000000000;
	// fneg f12,f29
	ctx.f12.u64 = f29.u64 ^ 0x8000000000000000;
	// fmr f24,f13
	f24.f64 = ctx.f13.f64;
	// fmr f22,f13
	f22.f64 = ctx.f13.f64;
	// fmr f18,f13
	f18.f64 = ctx.f13.f64;
	// fmr f17,f13
	f17.f64 = ctx.f13.f64;
	// fmr f28,f0
	f28.f64 = f0.f64;
	// fmr f27,f0
	f27.f64 = f0.f64;
	// fmr f26,f0
	f26.f64 = f0.f64;
	// fmr f25,f0
	f25.f64 = f0.f64;
	// fmr f23,f12
	f23.f64 = ctx.f12.f64;
	// fmr f21,f12
	f21.f64 = ctx.f12.f64;
	// fmr f20,f12
	f20.f64 = ctx.f12.f64;
	// fmr f19,f12
	f19.f64 = ctx.f12.f64;
	// bl 0x8217c088
	ctx.lr = 0x8217DBA4;
	sub_8217C088(ctx, base);
	// li r4,24
	ctx.r4.s64 = 24;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217bb68
	ctx.lr = 0x8217DBB0;
	sub_8217BB68(ctx, base);
	// lis r30,-32124
	r30.s64 = -2105278464;
	// lis r29,-32124
	r29.s64 = -2105278464;
	// fmr f3,f23
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f23.f64;
	// lis r28,-32124
	r28.s64 = -2105278464;
	// fmr f2,f24
	ctx.f2.f64 = f24.f64;
	// lis r27,-32124
	r27.s64 = -2105278464;
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// lis r26,-32124
	r26.s64 = -2105278464;
	// stw r31,-26892(r30)
	PPC_STORE_U32(r30.u32 + -26892, r31.u32);
	// lis r25,-32124
	r25.s64 = -2105278464;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// lfs f8,-26924(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DBF4;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f3,f21
	ctx.f3.f64 = f21.f64;
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f2,f22
	ctx.f2.f64 = f22.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DC1C;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f21
	ctx.f3.f64 = f21.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f22
	ctx.f2.f64 = f22.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DC44;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f20
	ctx.f3.f64 = f20.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DC6C;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f3,f20
	ctx.f3.f64 = f20.f64;
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DC94;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f19
	ctx.f3.f64 = f19.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DCBC;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f19
	ctx.f3.f64 = f19.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DCE4;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f23
	ctx.f3.f64 = f23.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f24
	ctx.f2.f64 = f24.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DD0C;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f23
	ctx.f3.f64 = f23.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f24
	ctx.f2.f64 = f24.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DD34;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f18
	ctx.f2.f64 = f18.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f26
	ctx.f1.f64 = f26.f64;
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DD5C;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f21
	ctx.f3.f64 = f21.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f22
	ctx.f2.f64 = f22.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DD84;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f17
	ctx.f2.f64 = f17.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DDAC;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f20
	ctx.f3.f64 = f20.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DDD4;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DDFC;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f19
	ctx.f3.f64 = f19.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DE24;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f25
	ctx.f1.f64 = f25.f64;
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DE4C;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f18
	ctx.f2.f64 = f18.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f26
	ctx.f1.f64 = f26.f64;
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DE74;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f2,f17
	ctx.f2.f64 = f17.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DE9C;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f17
	ctx.f2.f64 = f17.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DEC4;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DEEC;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DF14;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f25
	ctx.f1.f64 = f25.f64;
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DF3C;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f25
	ctx.f1.f64 = f25.f64;
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DF64;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -26892);
	// lfs f8,-26924(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// lfs f6,-26896(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f18
	ctx.f2.f64 = f18.f64;
	// lfs f5,-26908(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f26
	ctx.f1.f64 = f26.f64;
	// lfs f4,-26928(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217DF8C;
	sub_8217BC28(ctx, base);
	// bl 0x8217bc98
	ctx.lr = 0x8217DF90;
	sub_8217BC98(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823db9f8
	ctx.lr = 0x8217DF9C;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8217DFA0"))) PPC_WEAK_FUNC(sub_8217DFA0);
PPC_FUNC_IMPL(__imp__sub_8217DFA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// vaddfp128 v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// vspltisw128 v60,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x0)));
	// vsubfp128 v59,v62,v63
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
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
	// lvlx128 v57,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v56,v57,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// vmulfp128 v55,v61,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v56.f32)));
	// vpermwi128 v54,v58,234
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x15));
	// vpermwi128 v53,v58,186
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x45));
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// vpermwi128 v52,v58,174
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x51));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217db10
	ctx.lr = 0x8217E020;
	sub_8217DB10(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217E030"))) PPC_WEAK_FUNC(sub_8217E030);
PPC_FUNC_IMPL(__imp__sub_8217E030) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
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
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	// bl 0x823d91c8
	ctx.lr = 0x8217E038;
	// addi r12,r1,-136
	r12.s64 = ctx.r1.s64 + -136;
	// bl 0x823db9bc
	ctx.lr = 0x8217E040;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32124
	r28.s64 = -2105278464;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r19,r6
	r19.u64 = ctx.r6.u64;
	// lwz r3,-26876(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -26876);
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x8217c088
	ctx.lr = 0x8217E064;
	sub_8217C088(ctx, base);
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8217e364
	if (cr6.eq) goto loc_8217E364;
	// srawi r18,r29,1
	xer.ca = (r29.s32 < 0) & ((r29.u32 & 0x1) != 0);
	r18.s64 = r29.s32 >> 1;
	// cmpwi cr6,r18,0
	cr6.compare<int32_t>(r18.s32, 0, xer);
	// ble cr6,0x8217e5dc
	if (!cr6.gt) goto loc_8217E5DC;
	// extsw r11,r18
	r11.s64 = r18.s32;
	// addi r10,r29,1
	ctx.r10.s64 = r29.s64 + 1;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f26,18204(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 18204);
	f26.f64 = double(temp.f32);
	// rlwinm r16,r10,1,0,30
	r16.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// frsp f24,f13
	f24.f64 = double(float(ctx.f13.f64));
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lfs f25,14980(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14980);
	f25.f64 = double(temp.f32);
	// addi r17,r18,-1
	r17.s64 = r18.s64 + -1;
	// lis r24,-32124
	r24.s64 = -2105278464;
	// lis r23,-32124
	r23.s64 = -2105278464;
	// lis r22,-32124
	r22.s64 = -2105278464;
	// lis r21,-32124
	r21.s64 = -2105278464;
	// lis r20,-32124
	r20.s64 = -2105278464;
	// lis r19,-32124
	r19.s64 = -2105278464;
	// addi r28,r11,-31664
	r28.s64 = r11.s64 + -31664;
	// addi r27,r10,-31648
	r27.s64 = ctx.r10.s64 + -31648;
	// addi r26,r9,2240
	r26.s64 = ctx.r9.s64 + 2240;
	// addi r25,r8,2528
	r25.s64 = ctx.r8.s64 + 2528;
loc_8217E0E4:
	// extsw r11,r18
	r11.s64 = r18.s32;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f25
	ctx.f11.f64 = double(float(ctx.f12.f64 * f25.f64));
	// fdivs f30,f11,f24
	f30.f64 = double(float(ctx.f11.f64 / f24.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x8217E108;
	sub_823DBBC8(ctx, base);
	// extsw r10,r17
	ctx.r10.s64 = r17.s32;
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// lfs f9,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// std r10,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r10.u64);
	// lfd f8,104(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// fmuls f31,f9,f10
	f31.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// fmuls f5,f6,f25
	ctx.f5.f64 = double(float(ctx.f6.f64 * f25.f64));
	// fdivs f28,f5,f24
	f28.f64 = double(float(ctx.f5.f64 / f24.f64));
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x8217E138;
	sub_823DBBC8(ctx, base);
	// frsp f4,f1
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = double(float(ctx.f1.f64));
	// lfs f3,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// fmuls f30,f3,f4
	f30.f64 = double(float(ctx.f3.f64 * ctx.f4.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8217E14C;
	sub_823DBAE8(ctx, base);
	// frsp f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = double(float(ctx.f1.f64));
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// bl 0x823dbae8
	ctx.lr = 0x8217E158;
	sub_823DBAE8(ctx, base);
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// frsp f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = double(float(ctx.f1.f64));
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x8217bb68
	ctx.lr = 0x8217E168;
	sub_8217BB68(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x8217e344
	if (cr6.lt) goto loc_8217E344;
	// extsw r11,r29
	r11.s64 = r29.s32;
	// std r11,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, r11.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f27,f13
	f27.f64 = double(float(ctx.f13.f64));
loc_8217E188:
	// extsw r11,r30
	r11.s64 = r30.s32;
	// std r11,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, r11.u64);
	// lfd f0,120(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f26
	ctx.f11.f64 = double(float(ctx.f12.f64 * f26.f64));
	// fdivs f23,f11,f27
	f23.f64 = double(float(ctx.f11.f64 / f27.f64));
	// fmr f1,f23
	ctx.f1.f64 = f23.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x8217E1AC;
	sub_823DBBC8(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// lfs f9,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// extsw r10,r30
	ctx.r10.s64 = r30.s32;
	// std r10,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r10.u64);
	// lfd f8,128(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// fmuls f5,f9,f10
	ctx.f5.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// fmuls f4,f6,f26
	ctx.f4.f64 = double(float(ctx.f6.f64 * f26.f64));
	// fmuls f22,f5,f29
	f22.f64 = double(float(ctx.f5.f64 * f29.f64));
	// fdivs f21,f4,f27
	f21.f64 = double(float(ctx.f4.f64 / f27.f64));
	// fmr f1,f21
	ctx.f1.f64 = f21.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x8217E1E4;
	sub_823DBBC8(ctx, base);
	// frsp f3,f1
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = double(float(ctx.f1.f64));
	// lfs f2,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f23
	ctx.f1.f64 = f23.f64;
	// fmuls f0,f2,f3
	f0.f64 = double(float(ctx.f2.f64 * ctx.f3.f64));
	// fmuls f23,f0,f28
	f23.f64 = double(float(f0.f64 * f28.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8217E1FC;
	sub_823DBAE8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lfs f12,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fmr f1,f21
	ctx.f1.f64 = f21.f64;
	// fmuls f11,f13,f29
	ctx.f11.f64 = double(float(ctx.f13.f64 * f29.f64));
	// fmuls f21,f11,f12
	f21.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8217E214;
	sub_823DBAE8(ctx, base);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lvx128 v62,r0,r25
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// stfs f22,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f22.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f21,152(r1)
	temp.f32 = float(f21.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// frsp f10,f1
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// stfs f31,148(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// fmr f1,f22
	ctx.f1.f64 = f22.f64;
	// lvx128 v0,r0,r26
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,-26892(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + -26892);
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v61,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// vrsqrtefp128 v60,v61
	simde_mm_store_ps(v60.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v61.f32))));
	// vor128 v12,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// lvx128 v61,r0,r27
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f9,f10,f28
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f9.f64 = double(float(ctx.f10.f64 * f28.f64));
	// lvx128 v13,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f3,f21
	ctx.f3.f64 = f21.f64;
	// lfs f6,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// lfs f8,-26924(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f22,f9,f6
	f22.f64 = double(float(ctx.f9.f64 * ctx.f6.f64));
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
	// lfs f6,152(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f6.f64 = double(temp.f32);
	// lfs f4,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f4.f64 = double(temp.f32);
	// lfs f5,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,-26908(r20)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r20.u32 + -26908, temp.u32);
	// stfs f4,-26928(r19)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r19.u32 + -26928, temp.u32);
	// stfs f6,-26896(r21)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r21.u32 + -26896, temp.u32);
	// bl 0x8217bc28
	ctx.lr = 0x8217E2B0;
	sub_8217BC28(ctx, base);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lwz r9,-26892(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + -26892);
	// lvx128 v61,r0,r25
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f23,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f22,168(r1)
	temp.f32 = float(f22.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f30,164(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f3,f22
	ctx.f3.f64 = f22.f64;
	// vmsum3fp128 v58,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lvx128 v5,r0,r26
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f2,f30
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f2.f64 = f30.f64;
	// lvx128 v13,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f23
	ctx.f1.f64 = f23.f64;
	// lfs f8,-26924(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// vrsqrtefp128 v57,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v58.f32))));
	// vor128 v4,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// vcmpeqfp128 v3,v57,v61
	simde_mm_store_ps(ctx.v3.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v2,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// vsel v0,v2,v5,v3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8))));
	// vmulfp128 v1,v0,v0
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v31,v62,v0
	simde_mm_store_ps(v31.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v30,v4,v1,v13
	simde_mm_store_ps(v30.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v29,v30,v31,v0
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v56,v63,v29
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v29.f32)));
	// stvx128 v56,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f6,168(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f6.f64 = double(temp.f32);
	// lfs f4,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f4.f64 = double(temp.f32);
	// lfs f5,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,-26908(r20)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r20.u32 + -26908, temp.u32);
	// stfs f4,-26928(r19)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r19.u32 + -26928, temp.u32);
	// stfs f6,-26896(r21)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r21.u32 + -26896, temp.u32);
	// bl 0x8217bc28
	ctx.lr = 0x8217E33C;
	sub_8217BC28(ctx, base);
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// ble cr6,0x8217e188
	if (!cr6.gt) goto loc_8217E188;
loc_8217E344:
	// bl 0x8217bc98
	ctx.lr = 0x8217E348;
	sub_8217BC98(ctx, base);
	// addic. r18,r18,-1
	xer.ca = r18.u32 > 0;
	r18.s64 = r18.s64 + -1;
	cr0.compare<int32_t>(r18.s32, 0, xer);
	// addi r17,r17,-1
	r17.s64 = r17.s64 + -1;
	// bgt 0x8217e0e4
	if (cr0.gt) goto loc_8217E0E4;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// addi r12,r1,-136
	r12.s64 = ctx.r1.s64 + -136;
	// bl 0x823dba08
	ctx.lr = 0x8217E360;
	// b 0x823d9218
	return;
loc_8217E364:
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// bge cr6,0x8217e370
	if (!cr6.lt) goto loc_8217E370;
	// li r29,4
	r29.s64 = 4;
loc_8217E370:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-26876(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x8217E37C;
	sub_8217C088(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// srawi r20,r29,1
	xer.ca = (r29.s32 < 0) & ((r29.u32 & 0x1) != 0);
	r20.s64 = r29.s32 >> 1;
	// lis r28,-32124
	r28.s64 = -2105278464;
	// lis r27,-32124
	r27.s64 = -2105278464;
	// lfs f30,18204(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18204);
	f30.f64 = double(temp.f32);
	// lis r26,-32124
	r26.s64 = -2105278464;
	// lfs f26,14980(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14980);
	f26.f64 = double(temp.f32);
	// lis r25,-32124
	r25.s64 = -2105278464;
	// lis r24,-32124
	r24.s64 = -2105278464;
	// lis r23,-32124
	r23.s64 = -2105278464;
	// li r22,1
	r22.s64 = 1;
	// cmpwi cr6,r20,1
	cr6.compare<int32_t>(r20.s32, 1, xer);
	// ble cr6,0x8217e4c0
	if (!cr6.gt) goto loc_8217E4C0;
	// extsw r11,r20
	r11.s64 = r20.s32;
	// addi r21,r29,1
	r21.s64 = r29.s64 + 1;
	// std r11,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, r11.u64);
	// lfd f0,128(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f27,f13
	f27.f64 = double(float(ctx.f13.f64));
loc_8217E3CC:
	// extsw r11,r22
	r11.s64 = r22.s32;
	// std r11,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, r11.u64);
	// lfd f0,128(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f26
	ctx.f11.f64 = double(float(ctx.f12.f64 * f26.f64));
	// fdivs f31,f11,f27
	f31.f64 = double(float(ctx.f11.f64 / f27.f64));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x8217E3F0;
	sub_823DBBC8(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// lfs f9,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// fmuls f29,f9,f10
	f29.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8217E404;
	sub_823DBAE8(ctx, base);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(ctx.f1.f64));
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8217bb68
	ctx.lr = 0x8217E414;
	sub_8217BB68(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x8217e4b0
	if (cr6.lt) goto loc_8217E4B0;
	// extsw r11,r29
	r11.s64 = r29.s32;
	// std r11,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, r11.u64);
	// lfd f0,120(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f28,f13
	f28.f64 = double(float(ctx.f13.f64));
loc_8217E434:
	// extsw r11,r30
	r11.s64 = r30.s32;
	// std r11,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, r11.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 * f30.f64));
	// fdivs f25,f11,f28
	f25.f64 = double(float(ctx.f11.f64 / f28.f64));
	// fmr f1,f25
	ctx.f1.f64 = f25.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x8217E458;
	sub_823DBBC8(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// lfs f9,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// fmr f1,f25
	ctx.f1.f64 = f25.f64;
	// fmuls f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// fmuls f25,f8,f31
	f25.f64 = double(float(ctx.f8.f64 * f31.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8217E470;
	sub_823DBAE8(ctx, base);
	// frsp f3,f1
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = double(float(ctx.f1.f64));
	// lfs f0,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r9,-26892(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + -26892);
	// lfs f8,-26924(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// lfs f6,-26896(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f1,f25
	ctx.f1.f64 = f25.f64;
	// lfs f5,-26908(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f13,f3,f31
	ctx.f13.f64 = double(float(ctx.f3.f64 * f31.f64));
	// fmuls f3,f13,f0
	ctx.f3.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x8217bc28
	ctx.lr = 0x8217E4A4;
	sub_8217BC28(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// ble cr6,0x8217e434
	if (!cr6.gt) goto loc_8217E434;
loc_8217E4B0:
	// bl 0x8217bc98
	ctx.lr = 0x8217E4B4;
	sub_8217BC98(ctx, base);
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// cmpw cr6,r22,r20
	cr6.compare<int32_t>(r22.s32, r20.s32, xer);
	// blt cr6,0x8217e3cc
	if (cr6.lt) goto loc_8217E3CC;
loc_8217E4C0:
	// clrlwi r11,r19,24
	r11.u64 = r19.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8217e5dc
	if (cr6.eq) goto loc_8217E5DC;
	// li r22,0
	r22.s64 = 0;
	// cmpwi cr6,r20,0
	cr6.compare<int32_t>(r20.s32, 0, xer);
	// ble cr6,0x8217e5dc
	if (!cr6.gt) goto loc_8217E5DC;
	// extsw r11,r20
	r11.s64 = r20.s32;
	// addi r21,r29,1
	r21.s64 = r29.s64 + 1;
	// std r11,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, r11.u64);
	// lfd f0,128(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f27,f13
	f27.f64 = double(float(ctx.f13.f64));
loc_8217E4F0:
	// extsw r11,r22
	r11.s64 = r22.s32;
	// std r11,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, r11.u64);
	// lfd f0,128(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f26
	ctx.f11.f64 = double(float(ctx.f12.f64 * f26.f64));
	// fdivs f31,f11,f27
	f31.f64 = double(float(ctx.f11.f64 / f27.f64));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x8217E514;
	sub_823DBBC8(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// lfs f9,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// fmuls f31,f9,f10
	f31.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8217E528;
	sub_823DBAE8(ctx, base);
	// frsp f8,f1
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(ctx.f1.f64));
	// lfs f7,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// fmuls f29,f7,f8
	f29.f64 = double(float(ctx.f7.f64 * ctx.f8.f64));
	// bl 0x8217bb68
	ctx.lr = 0x8217E540;
	sub_8217BB68(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x8217e5cc
	if (cr6.lt) goto loc_8217E5CC;
	// extsw r11,r29
	r11.s64 = r29.s32;
	// std r11,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, r11.u64);
	// lfd f0,120(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f28,f13
	f28.f64 = double(float(ctx.f13.f64));
loc_8217E560:
	// extsw r11,r30
	r11.s64 = r30.s32;
	// std r11,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, r11.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 * f30.f64));
	// fdivs f25,f11,f28
	f25.f64 = double(float(ctx.f11.f64 / f28.f64));
	// fmr f1,f25
	ctx.f1.f64 = f25.f64;
	// bl 0x823dbae8
	ctx.lr = 0x8217E584;
	sub_823DBAE8(ctx, base);
	// frsp f24,f1
	ctx.fpscr.disableFlushMode();
	f24.f64 = double(float(ctx.f1.f64));
	// fmr f1,f25
	ctx.f1.f64 = f25.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x8217E590;
	sub_823DBBC8(ctx, base);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// lfs f9,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// lwz r9,-26892(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + -26892);
	// lfs f8,-26924(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f3,f29,f24
	ctx.f3.f64 = double(float(f29.f64 * f24.f64));
	// lfs f6,-26896(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f1,f31,f24
	ctx.f1.f64 = double(float(f31.f64 * f24.f64));
	// lfs f5,-26908(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f2,f9,f10
	ctx.f2.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// bl 0x8217bc28
	ctx.lr = 0x8217E5C0;
	sub_8217BC28(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// ble cr6,0x8217e560
	if (!cr6.gt) goto loc_8217E560;
loc_8217E5CC:
	// bl 0x8217bc98
	ctx.lr = 0x8217E5D0;
	sub_8217BC98(ctx, base);
	// addi r22,r22,1
	r22.s64 = r22.s64 + 1;
	// cmpw cr6,r22,r20
	cr6.compare<int32_t>(r22.s32, r20.s32, xer);
	// blt cr6,0x8217e4f0
	if (cr6.lt) goto loc_8217E4F0;
loc_8217E5DC:
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// addi r12,r1,-136
	r12.s64 = ctx.r1.s64 + -136;
	// bl 0x823dba08
	ctx.lr = 0x8217E5E8;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_8217E5EC"))) PPC_WEAK_FUNC(sub_8217E5EC);
PPC_FUNC_IMPL(__imp__sub_8217E5EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217E5F0"))) PPC_WEAK_FUNC(sub_8217E5F0);
PPC_FUNC_IMPL(__imp__sub_8217E5F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8217E5F8;
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32124
	r30.s64 = -2105278464;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r3,-26880(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -26880);
	// lwz r31,-26876(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// beq cr6,0x8217e630
	if (cr6.eq) goto loc_8217E630;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8217c658
	ctx.lr = 0x8217E630;
	sub_8217C658(ctx, base);
loc_8217E630:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// lfs f5,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f5.f64 = double(temp.f32);
	// lwz r7,-26892(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + -26892);
	// fmr f4,f5
	ctx.f4.f64 = ctx.f5.f64;
	// lwz r3,-25824(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -25824);
	// lfs f3,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	ctx.f3.f64 = double(temp.f32);
	// bl 0x8217f148
	ctx.lr = 0x8217E664;
	sub_8217F148(ctx, base);
	// lwz r11,-26880(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -26880);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// beq cr6,0x8217e67c
	if (cr6.eq) goto loc_8217E67C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8217c658
	ctx.lr = 0x8217E67C;
	sub_8217C658(ctx, base);
loc_8217E67C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8217E68C"))) PPC_WEAK_FUNC(sub_8217E68C);
PPC_FUNC_IMPL(__imp__sub_8217E68C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217E690"))) PPC_WEAK_FUNC(sub_8217E690);
PPC_FUNC_IMPL(__imp__sub_8217E690) {
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
	// bl 0x823d91e8
	ctx.lr = 0x8217E698;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823db9c8
	ctx.lr = 0x8217E6A0;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// lwz r3,-26876(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x8217E6B8;
	sub_8217C088(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217bb68
	ctx.lr = 0x8217E6C4;
	sub_8217BB68(ctx, base);
	// lis r31,-32124
	r31.s64 = -2105278464;
	// lis r25,-1
	r25.s64 = -65536;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// lis r30,-32124
	r30.s64 = -2105278464;
	// stw r9,-26892(r31)
	PPC_STORE_U32(r31.u32 + -26892, ctx.r9.u32);
	// lis r29,-32124
	r29.s64 = -2105278464;
	// lis r28,-32124
	r28.s64 = -2105278464;
	// lis r27,-32124
	r27.s64 = -2105278464;
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r26,-32124
	r26.s64 = -2105278464;
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f8,-26924(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217E714;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217E73C;
	sub_8217BC28(ctx, base);
	// lis r9,-256
	ctx.r9.s64 = -16777216;
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// ori r9,r9,65280
	ctx.r9.u64 = ctx.r9.u64 | 65280;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// stw r9,-26892(r31)
	PPC_STORE_U32(r31.u32 + -26892, ctx.r9.u32);
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8217bc28
	ctx.lr = 0x8217E76C;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217E794;
	sub_8217BC28(ctx, base);
	// lis r9,-256
	ctx.r9.s64 = -16777216;
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// ori r9,r9,255
	ctx.r9.u64 = ctx.r9.u64 | 255;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// stw r9,-26892(r31)
	PPC_STORE_U32(r31.u32 + -26892, ctx.r9.u32);
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8217bc28
	ctx.lr = 0x8217E7C4;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217E7EC;
	sub_8217BC28(ctx, base);
	// bl 0x8217bc98
	ctx.lr = 0x8217E7F0;
	sub_8217BC98(ctx, base);
	// clrlwi r9,r24,24
	ctx.r9.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8217ebe4
	if (cr6.eq) goto loc_8217EBE4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r4,9
	ctx.r4.s64 = 9;
	// li r3,3
	ctx.r3.s64 = 3;
	// lfs f0,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	f0.f64 = double(temp.f32);
	// fmuls f12,f30,f0
	ctx.f12.f64 = double(float(f30.f64 * f0.f64));
	// lfs f13,-32032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -32032);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-26504(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -26504);
	f0.f64 = double(temp.f32);
	// fmuls f29,f30,f13
	f29.f64 = double(float(f30.f64 * ctx.f13.f64));
	// fmuls f28,f30,f0
	f28.f64 = double(float(f30.f64 * f0.f64));
	// fsubs f27,f30,f12
	f27.f64 = double(float(f30.f64 - ctx.f12.f64));
	// fadds f26,f12,f29
	f26.f64 = double(float(ctx.f12.f64 + f29.f64));
	// fsubs f25,f28,f12
	f25.f64 = double(float(f28.f64 - ctx.f12.f64));
	// bl 0x8217bb68
	ctx.lr = 0x8217E838;
	sub_8217BB68(ctx, base);
	// lis r9,32767
	ctx.r9.s64 = 2147418112;
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// stw r9,-26892(r31)
	PPC_STORE_U32(r31.u32 + -26892, ctx.r9.u32);
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// bl 0x8217bc28
	ctx.lr = 0x8217E864;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f1,f26
	ctx.f1.f64 = f26.f64;
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f25
	ctx.f3.f64 = f25.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f25
	ctx.f2.f64 = f25.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217E88C;
	sub_8217BC28(ctx, base);
	// fneg f24,f25
	ctx.fpscr.disableFlushMode();
	f24.u64 = f25.u64 ^ 0x8000000000000000;
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f1,f26
	ctx.f1.f64 = f26.f64;
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fmr f3,f24
	ctx.f3.f64 = f24.f64;
	// fmr f2,f24
	ctx.f2.f64 = f24.f64;
	// bl 0x8217bc28
	ctx.lr = 0x8217E8B8;
	sub_8217BC28(ctx, base);
	// lis r9,32512
	ctx.r9.s64 = 2130706432;
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f2,f27
	ctx.f2.f64 = f27.f64;
	// ori r9,r9,65280
	ctx.r9.u64 = ctx.r9.u64 | 65280;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// stw r9,-26892(r31)
	PPC_STORE_U32(r31.u32 + -26892, ctx.r9.u32);
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8217bc28
	ctx.lr = 0x8217E8E8;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f3,f25
	ctx.f3.f64 = f25.f64;
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f2,f26
	ctx.f2.f64 = f26.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f1,f25
	ctx.f1.f64 = f25.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217E910;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f24
	ctx.f3.f64 = f24.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f26
	ctx.f2.f64 = f26.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f24
	ctx.f1.f64 = f24.f64;
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217E938;
	sub_8217BC28(ctx, base);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lis r9,32512
	ctx.r9.s64 = 2130706432;
	// ori r9,r9,255
	ctx.r9.u64 = ctx.r9.u64 | 255;
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f3,f27
	ctx.f3.f64 = f27.f64;
	// stw r9,-26892(r31)
	PPC_STORE_U32(r31.u32 + -26892, ctx.r9.u32);
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8217bc28
	ctx.lr = 0x8217E968;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f2,f25
	ctx.f2.f64 = f25.f64;
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f26
	ctx.f3.f64 = f26.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f1,f25
	ctx.f1.f64 = f25.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217E990;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f2,f24
	ctx.f2.f64 = f24.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f3,f26
	ctx.f3.f64 = f26.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f24
	ctx.f1.f64 = f24.f64;
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217E9B8;
	sub_8217BC28(ctx, base);
	// bl 0x8217bc98
	ctx.lr = 0x8217E9BC;
	sub_8217BC98(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8217bb68
	ctx.lr = 0x8217E9C8;
	sub_8217BB68(ctx, base);
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// stw r9,-26892(r31)
	PPC_STORE_U32(r31.u32 + -26892, ctx.r9.u32);
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217E9F4;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f28
	ctx.f3.f64 = f28.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f28
	ctx.f2.f64 = f28.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217EA1C;
	sub_8217BC28(ctx, base);
	// fneg f27,f28
	ctx.fpscr.disableFlushMode();
	f27.u64 = f28.u64 ^ 0x8000000000000000;
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fmr f3,f27
	ctx.f3.f64 = f27.f64;
	// fmr f2,f27
	ctx.f2.f64 = f27.f64;
	// bl 0x8217bc28
	ctx.lr = 0x8217EA48;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217EA70;
	sub_8217BC28(ctx, base);
	// bl 0x8217bc98
	ctx.lr = 0x8217EA74;
	sub_8217BC98(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8217bb68
	ctx.lr = 0x8217EA80;
	sub_8217BB68(ctx, base);
	// lis r9,-256
	ctx.r9.s64 = -16777216;
	// ori r9,r9,65280
	ctx.r9.u64 = ctx.r9.u64 | 65280;
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// stw r9,-26892(r31)
	PPC_STORE_U32(r31.u32 + -26892, ctx.r9.u32);
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8217bc28
	ctx.lr = 0x8217EAB0;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f3,f28
	ctx.f3.f64 = f28.f64;
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217EAD8;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f27
	ctx.f3.f64 = f27.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217EB00;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217EB28;
	sub_8217BC28(ctx, base);
	// bl 0x8217bc98
	ctx.lr = 0x8217EB2C;
	sub_8217BC98(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8217bb68
	ctx.lr = 0x8217EB38;
	sub_8217BB68(ctx, base);
	// lis r9,-256
	ctx.r9.s64 = -16777216;
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// ori r9,r9,255
	ctx.r9.u64 = ctx.r9.u64 | 255;
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// stw r9,-26892(r31)
	PPC_STORE_U32(r31.u32 + -26892, ctx.r9.u32);
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8217bc28
	ctx.lr = 0x8217EB68;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f2,f28
	ctx.f2.f64 = f28.f64;
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217EB90;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f2,f27
	ctx.f2.f64 = f27.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217EBB8;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217EBE0;
	sub_8217BC28(ctx, base);
	// bl 0x8217bc98
	ctx.lr = 0x8217EBE4;
	sub_8217BC98(ctx, base);
loc_8217EBE4:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba14
	ctx.lr = 0x8217EBF0;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8217EBF4"))) PPC_WEAK_FUNC(sub_8217EBF4);
PPC_FUNC_IMPL(__imp__sub_8217EBF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217EBF8"))) PPC_WEAK_FUNC(sub_8217EBF8);
PPC_FUNC_IMPL(__imp__sub_8217EBF8) {
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
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8217ec4c
	if (cr6.eq) goto loc_8217EC4C;
	// bl 0x8217d890
	ctx.lr = 0x8217EC24;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// add r5,r3,r11
	ctx.r5.u64 = ctx.r3.u64 + r11.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// lwz r3,-25232(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -25232);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8217EC4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8217EC4C:
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

__attribute__((alias("__imp__sub_8217EC64"))) PPC_WEAK_FUNC(sub_8217EC64);
PPC_FUNC_IMPL(__imp__sub_8217EC64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217EC68"))) PPC_WEAK_FUNC(sub_8217EC68);
PPC_FUNC_IMPL(__imp__sub_8217EC68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// bl 0x823d91e8
	ctx.lr = 0x8217EC70;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823db9c0
	ctx.lr = 0x8217EC78;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fneg f0,f3
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f3.u64 ^ 0x8000000000000000;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// lfs f13,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f23,f1,f13
	f23.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
	// lwz r3,-26876(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -26876);
	// fmuls f22,f2,f13
	f22.f64 = double(float(ctx.f2.f64 * ctx.f13.f64));
	// stfs f23,96(r1)
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f22,100(r1)
	temp.f32 = float(f22.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f23,112(r1)
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmr f31,f0
	f31.f64 = f0.f64;
	// stfs f22,132(r1)
	temp.f32 = float(f22.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// fmr f30,f0
	f30.f64 = f0.f64;
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmr f29,f0
	f29.f64 = f0.f64;
	// stfs f30,120(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmr f28,f0
	f28.f64 = f0.f64;
	// stfs f29,136(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f28,152(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// fneg f0,f23
	f0.u64 = f23.u64 ^ 0x8000000000000000;
	// fneg f13,f22
	ctx.f13.u64 = f22.u64 ^ 0x8000000000000000;
	// fmr f27,f0
	f27.f64 = f0.f64;
	// stfs f27,128(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fmr f26,f13
	f26.f64 = ctx.f13.f64;
	// stfs f26,116(r1)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fmr f25,f0
	f25.f64 = f0.f64;
	// stfs f25,144(r1)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// fmr f24,f13
	f24.f64 = ctx.f13.f64;
	// stfs f24,148(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// bl 0x8217c088
	ctx.lr = 0x8217ECFC;
	sub_8217C088(ctx, base);
	// lis r31,-32124
	r31.s64 = -2105278464;
	// li r4,5
	ctx.r4.s64 = 5;
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r30,-26892(r31)
	PPC_STORE_U32(r31.u32 + -26892, r30.u32);
	// bl 0x8217bb68
	ctx.lr = 0x8217ED10;
	sub_8217BB68(ctx, base);
	// lis r30,-32124
	r30.s64 = -2105278464;
	// lis r29,-32124
	r29.s64 = -2105278464;
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lis r28,-32124
	r28.s64 = -2105278464;
	// fmr f1,f23
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f23.f64;
	// lis r27,-32124
	r27.s64 = -2105278464;
	// fmr f2,f22
	ctx.f2.f64 = f22.f64;
	// lis r26,-32124
	r26.s64 = -2105278464;
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f8,-26924(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217ED4C;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f1,f23
	ctx.f1.f64 = f23.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f2,f26
	ctx.f2.f64 = f26.f64;
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217ED74;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f28
	ctx.f3.f64 = f28.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f24
	ctx.f2.f64 = f24.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f25
	ctx.f1.f64 = f25.f64;
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217ED9C;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f2,f22
	ctx.f2.f64 = f22.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f3,f29
	ctx.f3.f64 = f29.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217EDC4;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f2,f22
	ctx.f2.f64 = f22.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f1,f23
	ctx.f1.f64 = f23.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217EDEC;
	sub_8217BC28(ctx, base);
	// bl 0x8217bc98
	ctx.lr = 0x8217EDF0;
	sub_8217BC98(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217bb68
	ctx.lr = 0x8217EDFC;
	sub_8217BB68(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r25,r1,100
	r25.s64 = ctx.r1.s64 + 100;
	// li r24,4
	r24.s64 = 4;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_8217EE0C:
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217EE34;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + -26892);
	// lfs f8,-26924(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-26896(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,-26928(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,4(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,0(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-4(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8217EE5C;
	sub_8217BC28(ctx, base);
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r25,r25,16
	r25.s64 = r25.s64 + 16;
	// bne 0x8217ee0c
	if (!cr0.eq) goto loc_8217EE0C;
	// bl 0x8217bc98
	ctx.lr = 0x8217EE6C;
	sub_8217BC98(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba0c
	ctx.lr = 0x8217EE78;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8217EE7C"))) PPC_WEAK_FUNC(sub_8217EE7C);
PPC_FUNC_IMPL(__imp__sub_8217EE7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217EE80"))) PPC_WEAK_FUNC(sub_8217EE80);
PPC_FUNC_IMPL(__imp__sub_8217EE80) {
	PPC_FUNC_PROLOGUE();
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
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f1,84(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f1,88(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x8217e030
	ctx.lr = 0x8217EEA0;
	sub_8217E030(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217EEB0"))) PPC_WEAK_FUNC(sub_8217EEB0);
PPC_FUNC_IMPL(__imp__sub_8217EEB0) {
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
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8217ef04
	if (cr6.eq) goto loc_8217EF04;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8217EEDC;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8217ef04
	if (!cr6.eq) goto loc_8217EF04;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8217ef04
	if (cr6.eq) goto loc_8217EF04;
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
	ctx.lr = 0x8217EF04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8217EF04:
	// lwz r3,24(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x8217EF0C;
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

__attribute__((alias("__imp__sub_8217EF24"))) PPC_WEAK_FUNC(sub_8217EF24);
PPC_FUNC_IMPL(__imp__sub_8217EF24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217EF28"))) PPC_WEAK_FUNC(sub_8217EF28);
PPC_FUNC_IMPL(__imp__sub_8217EF28) {
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
	// bl 0x823d91fc
	ctx.lr = 0x8217EF30;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823db9c4
	ctx.lr = 0x8217EF38;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f29,f2
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f2.f64;
	// fmr f25,f3
	f25.f64 = ctx.f3.f64;
	// stw r7,276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 276, ctx.r7.u32);
	// fmr f24,f4
	f24.f64 = ctx.f4.f64;
	// fmr f23,f5
	f23.f64 = ctx.f5.f64;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// subf. r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x8217f0ec
	if (cr0.lt) goto loc_8217F0EC;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x8217f0ec
	if (!cr6.lt) goto loc_8217F0EC;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f0,28(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	f0.f64 = double(temp.f32);
	// divw r7,r11,r9
	ctx.r7.s32 = r11.s32 / ctx.r9.s32;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// divw r5,r11,r9
	ctx.r5.s32 = r11.s32 / ctx.r9.s32;
	// lfs f13,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// mullw r4,r7,r9
	ctx.r4.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// subf r3,r4,r11
	ctx.r3.s64 = r11.s64 - ctx.r4.s64;
	// mullw r7,r5,r6
	ctx.r7.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// mullw r5,r3,r8
	ctx.r5.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// extsw r4,r6
	ctx.r4.s64 = ctx.r6.s32;
	// extsw r3,r5
	ctx.r3.s64 = ctx.r5.s32;
	// extsw r7,r7
	ctx.r7.s64 = ctx.r7.s32;
	// std r4,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r4.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// std r3,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r3.u64);
	// std r7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// lfd f11,104(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// lfd f10,96(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// fcfid f5,f12
	ctx.f5.f64 = double(ctx.f12.s64);
	// rotlwi r11,r11,1
	r11.u64 = __builtin_rotateleft32(r11.u32, 1);
	// std r6,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r6.u64);
	// lfd f9,104(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// fcfid f6,f11
	ctx.f6.f64 = double(ctx.f11.s64);
	// andc r3,r9,r5
	ctx.r3.u64 = ctx.r9.u64 & ~ctx.r5.u64;
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// andc r11,r9,r4
	r11.u64 = ctx.r9.u64 & ~ctx.r4.u64;
	// frsp f12,f5
	ctx.f12.f64 = double(float(ctx.f5.f64));
	// twllei r9,0
	// twllei r9,0
	// twlgei r3,-1
	// twlgei r11,-1
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// frsp f2,f6
	ctx.f2.f64 = double(float(ctx.f6.f64));
	// fmuls f27,f4,f0
	f27.f64 = double(float(ctx.f4.f64 * f0.f64));
	// fmuls f26,f12,f13
	f26.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// fmuls f30,f3,f13
	f30.f64 = double(float(ctx.f3.f64 * ctx.f13.f64));
	// fmuls f31,f2,f0
	f31.f64 = double(float(ctx.f2.f64 * f0.f64));
	// bl 0x823dba38
	ctx.lr = 0x8217F024;
	sub_823DBA38(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// lfs f29,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f29.f64 = double(temp.f32);
	// fsubs f28,f11,f29
	f28.f64 = double(float(ctx.f11.f64 - f29.f64));
	// bl 0x823dba38
	ctx.lr = 0x8217F03C;
	sub_823DBA38(ctx, base);
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r29,8
	r29.s64 = 8;
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// lwzx r11,r29,r30
	r11.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r11,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, r11.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// fsubs f29,f10,f29
	f29.f64 = double(float(ctx.f10.f64 - f29.f64));
	// bne cr6,0x8217f068
	if (!cr6.eq) goto loc_8217F068;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8218f118
	ctx.lr = 0x8217F068;
	sub_8218F118(ctx, base);
loc_8217F068:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r1,276
	ctx.r10.s64 = ctx.r1.s64 + 276;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fadds f9,f26,f30
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(f26.f64 + f30.f64));
	// extsw r8,r11
	ctx.r8.s64 = r11.s32;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// fadds f8,f27,f31
	ctx.f8.f64 = double(float(f27.f64 + f31.f64));
	// std r8,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r8.u64);
	// lfd f0,104(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// std r7,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r7.u64);
	// lfd f13,104(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f3,f11
	ctx.f3.f64 = double(float(ctx.f11.f64));
	// fmr f7,f30
	ctx.f7.f64 = f30.f64;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f25
	ctx.f5.f64 = f25.f64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fmadds f3,f3,f24,f28
	ctx.f3.f64 = double(float(ctx.f3.f64 * f24.f64 + f28.f64));
	// fmadds f4,f10,f23,f29
	ctx.f4.f64 = double(float(ctx.f10.f64 * f23.f64 + f29.f64));
	// bl 0x8218f138
	ctx.lr = 0x8217F0C8;
	sub_8218F138(ctx, base);
	// lwzx r6,r29,r30
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// addic. r11,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	r11.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stwx r11,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, r11.u32);
	// bne 0x8217f134
	if (!cr0.eq) goto loc_8217F134;
	// bl 0x8218f130
	ctx.lr = 0x8217F0DC;
	sub_8218F130(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba10
	ctx.lr = 0x8217F0E8;
	// b 0x823d924c
	return;
loc_8217F0EC:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,8
	ctx.r10.s64 = 8;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8217f134
	if (cr6.eq) goto loc_8217F134;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r1,276
	ctx.r10.s64 = ctx.r1.s64 + 276;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// lfs f9,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f9.f64 = double(temp.f32);
	// fmr f8,f9
	ctx.f8.f64 = ctx.f9.f64;
	// fmr f7,f9
	ctx.f7.f64 = ctx.f9.f64;
	// fmr f6,f9
	ctx.f6.f64 = ctx.f9.f64;
	// fmr f5,f9
	ctx.f5.f64 = ctx.f9.f64;
	// fmr f4,f9
	ctx.f4.f64 = ctx.f9.f64;
	// fmr f3,f9
	ctx.f3.f64 = ctx.f9.f64;
	// fmr f2,f9
	ctx.f2.f64 = ctx.f9.f64;
	// fmr f1,f9
	ctx.f1.f64 = ctx.f9.f64;
	// bl 0x8218f138
	ctx.lr = 0x8217F134;
	sub_8218F138(ctx, base);
loc_8217F134:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba10
	ctx.lr = 0x8217F140;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8217F144"))) PPC_WEAK_FUNC(sub_8217F144);
PPC_FUNC_IMPL(__imp__sub_8217F144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217F148"))) PPC_WEAK_FUNC(sub_8217F148);
PPC_FUNC_IMPL(__imp__sub_8217F148) {
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
	PPCRegister f0{};
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
	// bl 0x823d91f8
	ctx.lr = 0x8217F150;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823db9d0
	ctx.lr = 0x8217F158;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r10
	r30.u64 = ctx.r10.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// fmr f27,f3
	f27.f64 = ctx.f3.f64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// fmr f29,f4
	f29.f64 = ctx.f4.f64;
	// fmr f28,f5
	f28.f64 = ctx.f5.f64;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8217f310
	if (cr6.eq) goto loc_8217F310;
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// fmr f26,f31
	f26.f64 = f31.f64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8217f1a8
	if (!cr6.eq) goto loc_8217F1A8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8217d9a0
	ctx.lr = 0x8217F1A8;
	sub_8217D9A0(ctx, base);
loc_8217F1A8:
	// lfs f0,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	f0.f64 = double(temp.f32);
	// mr r11,r30
	r11.u64 = r30.u64;
	// fmuls f29,f0,f29
	f29.f64 = double(float(f0.f64 * f29.f64));
	// fmuls f28,f0,f28
	f28.f64 = double(float(f0.f64 * f28.f64));
loc_8217F1B8:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8217f1b8
	if (!cr6.eq) goto loc_8217F1B8;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r29,r11,0
	r29.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmpwi cr6,r29,341
	cr6.compare<int32_t>(r29.s32, 341, xer);
	// bgt cr6,0x8217f200
	if (cr6.gt) goto loc_8217F200;
	// lwz r9,0(r13)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,8
	ctx.r10.s64 = 8;
	// lwzx r11,r10,r9
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8217f200
	if (!cr6.eq) goto loc_8217F200;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218f118
	ctx.lr = 0x8217F200;
	sub_8218F118(ctx, base);
loc_8217F200:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8217f2d4
	if (cr6.eq) goto loc_8217F2D4;
loc_8217F210:
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// fmr f5,f28
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = f28.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f4,f29
	ctx.f4.f64 = f29.f64;
	// fmr f3,f27
	ctx.f3.f64 = f27.f64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8217ef28
	ctx.lr = 0x8217F230;
	sub_8217EF28(ctx, base);
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// bne cr6,0x8217f264
	if (!cr6.eq) goto loc_8217F264;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f31,f26
	ctx.fpscr.disableFlushMode();
	f31.f64 = f26.f64;
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmadds f30,f12,f28,f30
	f30.f64 = double(float(ctx.f12.f64 * f28.f64 + f30.f64));
	// b 0x8217f2c0
	goto loc_8217F2C0;
loc_8217F264:
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8217f2a4
	if (cr6.eq) goto loc_8217F2A4;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8217f2a4
	if (cr6.lt) goto loc_8217F2A4;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x8217f2a4
	if (!cr6.lt) goto loc_8217F2A4;
	// subf r10,r10,r8
	ctx.r10.s64 = ctx.r8.s64 - ctx.r10.s64;
	// lbzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// b 0x8217f2b4
	goto loc_8217F2B4;
loc_8217F2A4:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
loc_8217F2B4:
	// fcfid f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmadds f31,f12,f29,f31
	f31.f64 = double(float(ctx.f12.f64 * f29.f64 + f31.f64));
loc_8217F2C0:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8217f210
	if (!cr6.eq) goto loc_8217F210;
loc_8217F2D4:
	// cmpwi cr6,r29,341
	cr6.compare<int32_t>(r29.s32, 341, xer);
	// bgt cr6,0x8217f2f8
	if (cr6.gt) goto loc_8217F2F8;
	// lwz r9,0(r13)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,8
	ctx.r10.s64 = 8;
	// lwzx r11,r10,r9
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// bne 0x8217f2f8
	if (!cr0.eq) goto loc_8217F2F8;
	// bl 0x8218f130
	ctx.lr = 0x8217F2F8;
	sub_8218F130(ctx, base);
loc_8217F2F8:
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// bne 0x8217f310
	if (!cr0.eq) goto loc_8217F310;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217d9a0
	ctx.lr = 0x8217F310;
	sub_8217D9A0(ctx, base);
loc_8217F310:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba1c
	ctx.lr = 0x8217F31C;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8217F320"))) PPC_WEAK_FUNC(sub_8217F320);
PPC_FUNC_IMPL(__imp__sub_8217F320) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x8217F328;
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r3,48
	ctx.r3.s64 = 48;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r21,r7
	r21.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// bl 0x82130528
	ctx.lr = 0x8217F350;
	sub_82130528(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r22,0
	r22.s64 = 0;
	// lfs f31,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
	// beq cr6,0x8217f3a8
	if (cr6.eq) goto loc_8217F3A8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f31,36(r3)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r22,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r22.u32);
	// stw r22,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r22.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r22,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r22.u32);
	// stw r22,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r22.u32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r22,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r22.u32);
	// stfs f0,28(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stw r22,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r22.u32);
	// stfs f0,32(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stw r22,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r22.u32);
	// stw r10,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r10.u32);
	// stw r22,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r22.u32);
	// b 0x8217f3ac
	goto loc_8217F3AC;
loc_8217F3A8:
	// mr r31,r22
	r31.u64 = r22.u64;
loc_8217F3AC:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8217F3CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// stw r21,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r21.u32);
	// twllei r30,0
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// lhz r8,0(r24)
	ctx.r8.u64 = PPC_LOAD_U16(r24.u32 + 0);
	// divw r7,r8,r30
	ctx.r7.s32 = ctx.r8.s32 / r30.s32;
	// stw r7,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r7.u32);
	// rotlwi r11,r8,1
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// lhz r6,0(r24)
	ctx.r6.u64 = PPC_LOAD_U16(r24.u32 + 0);
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// andc r3,r30,r4
	ctx.r3.u64 = r30.u64 & ~ctx.r4.u64;
	// twlgei r3,-1
	// fdivs f11,f31,f12
	ctx.f11.f64 = double(float(f31.f64 / ctx.f12.f64));
	// stfs f11,28(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// lhz r11,2(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 2);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fdivs f7,f31,f8
	ctx.f7.f64 = double(float(f31.f64 / ctx.f8.f64));
	// stfs f7,32(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// beq cr6,0x8217f530
	if (cr6.eq) goto loc_8217F530;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x82130528
	ctx.lr = 0x8217F450;
	sub_82130528(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// mr r28,r22
	r28.u64 = r22.u64;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// ble cr6,0x8217f530
	if (!cr6.gt) goto loc_8217F530;
loc_8217F460:
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rotlwi r11,r28,1
	r11.u64 = __builtin_rotateleft32(r28.u32, 1);
	// rotlwi r10,r28,1
	ctx.r10.u64 = __builtin_rotateleft32(r28.u32, 1);
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// divw r7,r28,r9
	ctx.r7.s32 = r28.s32 / ctx.r9.s32;
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// mullw r4,r7,r9
	ctx.r4.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// addi r3,r10,-1
	ctx.r3.s64 = ctx.r10.s64 + -1;
	// andc r11,r9,r5
	r11.u64 = ctx.r9.u64 & ~ctx.r5.u64;
	// subf r10,r4,r28
	ctx.r10.s64 = r28.s64 - ctx.r4.s64;
	// divw r7,r28,r9
	ctx.r7.s32 = r28.s32 / ctx.r9.s32;
	// andc r5,r9,r3
	ctx.r5.u64 = ctx.r9.u64 & ~ctx.r3.u64;
	// twllei r9,0
	// twllei r9,0
	// twlgei r11,-1
	// mullw r23,r10,r8
	r23.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// twlgei r5,-1
	// mullw r26,r7,r6
	r26.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32);
	// li r27,4
	r27.s64 = 4;
	// cmpwi cr6,r8,4
	cr6.compare<int32_t>(ctx.r8.s32, 4, xer);
	// ble cr6,0x8217f51c
	if (!cr6.gt) goto loc_8217F51C;
loc_8217F4B8:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r25,1
	r25.s64 = 1;
	// mr r30,r22
	r30.u64 = r22.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8217f500
	if (!cr6.gt) goto loc_8217F500;
	// add r29,r27,r23
	r29.u64 = r27.u64 + r23.u64;
loc_8217F4D0:
	// add r5,r30,r26
	ctx.r5.u64 = r30.u64 + r26.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8218d270
	ctx.lr = 0x8217F4E0;
	sub_8218D270(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8217f4fc
	if (!cr6.eq) goto loc_8217F4FC;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8217f4d0
	if (cr6.lt) goto loc_8217F4D0;
	// b 0x8217f500
	goto loc_8217F500;
loc_8217F4FC:
	// mr r25,r22
	r25.u64 = r22.u64;
loc_8217F500:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8217f51c
	if (!cr6.eq) goto loc_8217F51C;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x8217f4b8
	if (cr6.lt) goto loc_8217F4B8;
loc_8217F51C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// stbx r27,r11,r28
	PPC_STORE_U8(r11.u32 + r28.u32, r27.u8);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpw cr6,r28,r21
	cr6.compare<int32_t>(r28.s32, r21.s32, xer);
	// blt cr6,0x8217f460
	if (cr6.lt) goto loc_8217F460;
loc_8217F530:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8217F540"))) PPC_WEAK_FUNC(sub_8217F540);
PPC_FUNC_IMPL(__imp__sub_8217F540) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addic. r3,r11,-1
	xer.ca = r11.u32 > 0;
	ctx.r3.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// bne 0x8217f578
	if (!cr0.eq) goto loc_8217F578;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218cd10
	ctx.lr = 0x8217F56C;
	sub_8218CD10(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x8217F574;
	sub_82130588(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8217F578:
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

__attribute__((alias("__imp__sub_8217F58C"))) PPC_WEAK_FUNC(sub_8217F58C);
PPC_FUNC_IMPL(__imp__sub_8217F58C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217F590"))) PPC_WEAK_FUNC(sub_8217F590);
PPC_FUNC_IMPL(__imp__sub_8217F590) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x8217F598;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// mr r17,r6
	r17.u64 = ctx.r6.u64;
	// mr r18,r7
	r18.u64 = ctx.r7.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,64
	ctx.r4.s64 = 64;
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x8218de38
	ctx.lr = 0x8217F5D4;
	sub_8218DE38(ctx, base);
	// li r22,128
	r22.s64 = 128;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// divw r23,r22,r30
	r23.s32 = r22.s32 / r30.s32;
	// twllei r30,0
	// li r25,0
	r25.s64 = 0;
	// cmpwi cr6,r18,0
	cr6.compare<int32_t>(r18.s32, 0, xer);
	// ble cr6,0x8217f6a4
	if (!cr6.gt) goto loc_8217F6A4;
loc_8217F5F0:
	// rotlwi r11,r25,1
	r11.u64 = __builtin_rotateleft32(r25.u32, 1);
	// divw r9,r25,r23
	ctx.r9.s32 = r25.s32 / r23.s32;
	// rotlwi r10,r25,1
	ctx.r10.u64 = __builtin_rotateleft32(r25.u32, 1);
	// mullw r7,r9,r23
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(r23.s32);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// andc r5,r23,r8
	ctx.r5.u64 = r23.u64 & ~ctx.r8.u64;
	// subf r4,r7,r25
	ctx.r4.s64 = r25.s64 - ctx.r7.s64;
	// divw r3,r25,r23
	ctx.r3.s32 = r25.s32 / r23.s32;
	// andc r11,r23,r6
	r11.u64 = r23.u64 & ~ctx.r6.u64;
	// twllei r23,0
	// twllei r23,0
	// twlgei r5,-1
	// mullw r27,r4,r30
	r27.s64 = int64_t(ctx.r4.s32) * int64_t(r30.s32);
	// twlgei r11,-1
	// mullw r20,r3,r21
	r20.s64 = int64_t(ctx.r3.s32) * int64_t(r21.s32);
	// li r24,0
	r24.s64 = 0;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// ble cr6,0x8217f698
	if (!cr6.gt) goto loc_8217F698;
	// srawi r19,r30,3
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x7) != 0);
	r19.s64 = r30.s32 >> 3;
loc_8217F640:
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8217f688
	if (!cr6.gt) goto loc_8217F688;
	// add r29,r24,r20
	r29.u64 = r24.u64 + r20.u64;
loc_8217F650:
	// clrlwi r11,r31,29
	r11.u64 = r31.u32 & 0x7;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// sraw r10,r22,r11
	temp.u32 = r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (r22.s32 < 0) & (((r22.s32 >> temp.u32) << temp.u32) != r22.s32);
	ctx.r10.s64 = r22.s32 >> temp.u32;
	// srawi r9,r31,3
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x7) != 0);
	ctx.r9.s64 = r31.s32 >> 3;
	// add r4,r31,r27
	ctx.r4.u64 = r31.u64 + r27.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lbzx r8,r9,r28
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r28.u32);
	// and r7,r10,r8
	ctx.r7.u64 = ctx.r10.u64 & ctx.r8.u64;
	// subfic r6,r7,0
	xer.ca = ctx.r7.u32 <= 0;
	ctx.r6.s64 = 0 - ctx.r7.s64;
	// subfe r6,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// bl 0x8218d4f8
	ctx.lr = 0x8217F67C;
	sub_8218D4F8(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// blt cr6,0x8217f650
	if (cr6.lt) goto loc_8217F650;
loc_8217F688:
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// add r28,r19,r28
	r28.u64 = r19.u64 + r28.u64;
	// cmpw cr6,r24,r21
	cr6.compare<int32_t>(r24.s32, r21.s32, xer);
	// blt cr6,0x8217f640
	if (cr6.lt) goto loc_8217F640;
loc_8217F698:
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// cmpw cr6,r25,r18
	cr6.compare<int32_t>(r25.s32, r18.s32, xer);
	// blt cr6,0x8217f5f0
	if (cr6.lt) goto loc_8217F5F0;
loc_8217F6A4:
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r18
	ctx.r7.u64 = r18.u64;
	// mr r6,r17
	ctx.r6.u64 = r17.u64;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8217f320
	ctx.lr = 0x8217F6C0;
	sub_8217F320(ctx, base);
	// lwz r11,32(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,32(r26)
	PPC_STORE_U32(r26.u32 + 32, r11.u32);
	// bne 0x8217f6e4
	if (!cr0.eq) goto loc_8217F6E4;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8218cd10
	ctx.lr = 0x8217F6DC;
	sub_8218CD10(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130588
	ctx.lr = 0x8217F6E4;
	sub_82130588(ctx, base);
loc_8217F6E4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_8217F6F0"))) PPC_WEAK_FUNC(sub_8217F6F0);
PPC_FUNC_IMPL(__imp__sub_8217F6F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32124
	r31.s64 = -2105278464;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r3,-25800(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -25800);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8217f72c
	if (!cr6.eq) goto loc_8217F72C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-25680
	ctx.r3.s64 = r11.s64 + -25680;
	// bl 0x8218a4e8
	ctx.lr = 0x8217F728;
	sub_8218A4E8(ctx, base);
	// stw r3,-25800(r31)
	PPC_STORE_U32(r31.u32 + -25800, ctx.r3.u32);
loc_8217F72C:
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r6,2
	ctx.r6.s64 = 2;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8218aef8
	ctx.lr = 0x8217F740;
	sub_8218AEF8(ctx, base);
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

__attribute__((alias("__imp__sub_8217F758"))) PPC_WEAK_FUNC(sub_8217F758);
PPC_FUNC_IMPL(__imp__sub_8217F758) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-25788(r10)
	PPC_STORE_U32(ctx.r10.u32 + -25788, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217F768"))) PPC_WEAK_FUNC(sub_8217F768);
PPC_FUNC_IMPL(__imp__sub_8217F768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r23{};
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-25776
	ctx.r9.s64 = r11.s64 + -25776;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,39
	cr6.compare<uint32_t>(ctx.r3.u32, 39, xer);
	// stwx r31,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r31.u32);
	// bgt cr6,0x8217fd54
	if (cr6.gt) goto loc_8217FD54;
	// lis r12,-32232
	r12.s64 = -2112356352;
	// addi r12,r12,-2132
	r12.s64 = r12.s64 + -2132;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r3.u64) {
	case 0:
		goto loc_8217F84C;
	case 1:
		goto loc_8217FB94;
	case 2:
		goto loc_8217F8A8;
	case 3:
		goto loc_8217FB00;
	case 4:
		goto loc_8217FB38;
	case 5:
		goto loc_8217FB40;
	case 6:
		goto loc_8217FB7C;
	case 7:
		goto loc_8217F8A0;
	case 8:
		goto loc_8217F884;
	case 9:
		goto loc_8217F898;
	case 10:
		goto loc_8217FB1C;
	case 11:
		goto loc_8217FB74;
	case 12:
		goto loc_8217FB84;
	case 13:
		goto loc_8217FB8C;
	case 14:
		goto loc_8217FBB0;
	case 15:
		goto loc_8217FBB8;
	case 16:
		goto loc_8217F868;
	case 17:
		goto loc_8217FBD4;
	case 18:
		goto loc_8217FBF0;
	case 19:
		goto loc_8217FC0C;
	case 20:
		goto loc_8217FC28;
	case 21:
		goto loc_8217FC30;
	case 22:
		goto loc_8217FC48;
	case 23:
		goto loc_8217FC60;
	case 24:
		goto loc_8217FC78;
	case 25:
		goto loc_8217FC94;
	case 26:
		goto loc_8217FC9C;
	case 27:
		goto loc_8217FCA4;
	case 28:
		goto loc_8217FCAC;
	case 29:
		goto loc_8217FCB4;
	case 30:
		goto loc_8217FCBC;
	case 31:
		goto loc_8217FCC4;
	case 32:
		goto loc_8217FCDC;
	case 33:
		goto loc_8217FCF4;
	case 34:
		goto loc_8217FD0C;
	case 35:
		goto loc_8217FD28;
	case 36:
		goto loc_8217FD30;
	case 37:
		goto loc_8217FD38;
	case 38:
		goto loc_8217FD40;
	case 39:
		goto loc_8217FD48;
	default:
		__builtin_unreachable();
	}
	// lwz r16,-1972(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1972);
	// lwz r16,-1132(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1132);
	// lwz r16,-1880(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1880);
	// lwz r16,-1280(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1280);
	// lwz r16,-1224(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1224);
	// lwz r16,-1216(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1216);
	// lwz r16,-1156(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1156);
	// lwz r16,-1888(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1888);
	// lwz r16,-1916(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1916);
	// lwz r16,-1896(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1896);
	// lwz r16,-1252(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1252);
	// lwz r16,-1164(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1164);
	// lwz r16,-1148(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1148);
	// lwz r16,-1140(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1140);
	// lwz r16,-1104(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1104);
	// lwz r16,-1096(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1096);
	// lwz r16,-1944(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1944);
	// lwz r16,-1068(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1068);
	// lwz r16,-1040(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1040);
	// lwz r16,-1012(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1012);
	// lwz r16,-984(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -984);
	// lwz r16,-976(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -976);
	// lwz r16,-952(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -952);
	// lwz r16,-928(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -928);
	// lwz r16,-904(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -904);
	// lwz r16,-876(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -876);
	// lwz r16,-868(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -868);
	// lwz r16,-860(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -860);
	// lwz r16,-852(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -852);
	// lwz r16,-844(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -844);
	// lwz r16,-836(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -836);
	// lwz r16,-828(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -828);
	// lwz r16,-804(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -804);
	// lwz r16,-780(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -780);
	// lwz r16,-756(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -756);
	// lwz r16,-728(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -728);
	// lwz r16,-720(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -720);
	// lwz r16,-712(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -712);
	// lwz r16,-704(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -704);
	// lwz r16,-696(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -696);
loc_8217F84C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-25756
	r11.s64 = r11.s64 + -25756;
	// li r3,6
	ctx.r3.s64 = 6;
	// addi r9,r11,-44
	ctx.r9.s64 = r11.s64 + -44;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217F868:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-25756
	r11.s64 = r11.s64 + -25756;
	// li r3,19
	ctx.r3.s64 = 19;
	// addi r9,r11,-108
	ctx.r9.s64 = r11.s64 + -108;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217F884:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82189e80
	ctx.lr = 0x8217F890;
	sub_82189E80(ctx, base);
	// li r3,10
	ctx.r3.s64 = 10;
	// b 0x8217fd4c
	goto loc_8217FD4C;
loc_8217F898:
	// li r3,28
	ctx.r3.s64 = 28;
	// b 0x8217fd4c
	goto loc_8217FD4C;
loc_8217F8A0:
	// li r3,3
	ctx.r3.s64 = 3;
	// b 0x8217fd4c
	goto loc_8217FD4C;
loc_8217F8A8:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// cmplwi cr6,r31,13
	cr6.compare<uint32_t>(r31.u32, 13, xer);
	// stw r31,-25600(r11)
	PPC_STORE_U32(r11.u32 + -25600, r31.u32);
	// bgt cr6,0x8217fd54
	if (cr6.gt) goto loc_8217FD54;
	// lis r12,-32232
	r12.s64 = -2112356352;
	// addi r12,r12,-1840
	r12.s64 = r12.s64 + -1840;
	// rlwinm r0,r31,2,0,29
	r0.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r31.u64) {
	case 0:
		goto loc_8217F908;
	case 1:
		goto loc_8217F92C;
	case 2:
		goto loc_8217F950;
	case 3:
		goto loc_8217F974;
	case 4:
		goto loc_8217F998;
	case 5:
		goto loc_8217F9E0;
	case 6:
		goto loc_8217FA04;
	case 7:
		goto loc_8217FA28;
	case 8:
		goto loc_8217FA4C;
	case 9:
		goto loc_8217FA70;
	case 10:
		goto loc_8217FA94;
	case 11:
		goto loc_8217FAB8;
	case 12:
		goto loc_8217F9BC;
	case 13:
		goto loc_8217FADC;
	default:
		__builtin_unreachable();
	}
	// lwz r16,-1784(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1784);
	// lwz r16,-1748(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1748);
	// lwz r16,-1712(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1712);
	// lwz r16,-1676(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1676);
	// lwz r16,-1640(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1640);
	// lwz r16,-1568(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1568);
	// lwz r16,-1532(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1532);
	// lwz r16,-1496(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1496);
	// lwz r16,-1460(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1460);
	// lwz r16,-1424(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1424);
	// lwz r16,-1388(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1388);
	// lwz r16,-1352(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1352);
	// lwz r16,-1604(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1604);
	// lwz r16,-1316(r23)
	r16.u64 = PPC_LOAD_U32(r23.u32 + -1316);
loc_8217F908:
	// li r4,6
	ctx.r4.s64 = 6;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e80
	ctx.lr = 0x8217F914;
	sub_82189E80(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e80
	ctx.lr = 0x8217F920;
	sub_82189E80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,23
	ctx.r3.s64 = 23;
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217F92C:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e80
	ctx.lr = 0x8217F938;
	sub_82189E80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e80
	ctx.lr = 0x8217F944;
	sub_82189E80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,23
	ctx.r3.s64 = 23;
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217F950:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e80
	ctx.lr = 0x8217F95C;
	sub_82189E80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e80
	ctx.lr = 0x8217F968;
	sub_82189E80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,23
	ctx.r3.s64 = 23;
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217F974:
	// li r4,7
	ctx.r4.s64 = 7;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e80
	ctx.lr = 0x8217F980;
	sub_82189E80(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e80
	ctx.lr = 0x8217F98C;
	sub_82189E80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,23
	ctx.r3.s64 = 23;
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217F998:
	// li r4,10
	ctx.r4.s64 = 10;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e80
	ctx.lr = 0x8217F9A4;
	sub_82189E80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e80
	ctx.lr = 0x8217F9B0;
	sub_82189E80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,23
	ctx.r3.s64 = 23;
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217F9BC:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e80
	ctx.lr = 0x8217F9C8;
	sub_82189E80(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e80
	ctx.lr = 0x8217F9D4;
	sub_82189E80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,23
	ctx.r3.s64 = 23;
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217F9E0:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e80
	ctx.lr = 0x8217F9EC;
	sub_82189E80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e80
	ctx.lr = 0x8217F9F8;
	sub_82189E80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,23
	ctx.r3.s64 = 23;
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FA04:
	// li r4,10
	ctx.r4.s64 = 10;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e80
	ctx.lr = 0x8217FA10;
	sub_82189E80(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e80
	ctx.lr = 0x8217FA1C;
	sub_82189E80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,23
	ctx.r3.s64 = 23;
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FA28:
	// li r4,6
	ctx.r4.s64 = 6;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e80
	ctx.lr = 0x8217FA34;
	sub_82189E80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e80
	ctx.lr = 0x8217FA40;
	sub_82189E80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,23
	ctx.r3.s64 = 23;
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FA4C:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e80
	ctx.lr = 0x8217FA58;
	sub_82189E80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e80
	ctx.lr = 0x8217FA64;
	sub_82189E80(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,23
	ctx.r3.s64 = 23;
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FA70:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e80
	ctx.lr = 0x8217FA7C;
	sub_82189E80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e80
	ctx.lr = 0x8217FA88;
	sub_82189E80(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,23
	ctx.r3.s64 = 23;
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FA94:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e80
	ctx.lr = 0x8217FAA0;
	sub_82189E80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e80
	ctx.lr = 0x8217FAAC;
	sub_82189E80(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// li r3,23
	ctx.r3.s64 = 23;
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FAB8:
	// li r4,6
	ctx.r4.s64 = 6;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e80
	ctx.lr = 0x8217FAC4;
	sub_82189E80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e80
	ctx.lr = 0x8217FAD0;
	sub_82189E80(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,23
	ctx.r3.s64 = 23;
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FADC:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x82189e80
	ctx.lr = 0x8217FAE8;
	sub_82189E80(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x82189e80
	ctx.lr = 0x8217FAF4;
	sub_82189E80(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,23
	ctx.r3.s64 = 23;
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FB00:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-25756
	r11.s64 = r11.s64 + -25756;
	// li r3,9
	ctx.r3.s64 = 9;
loc_8217FB10:
	// addi r9,r11,-32
	ctx.r9.s64 = r11.s64 + -32;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FB1C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-25756
	r11.s64 = r11.s64 + -25756;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r9,r11,32
	ctx.r9.s64 = r11.s64 + 32;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FB38:
	// li r3,8
	ctx.r3.s64 = 8;
	// b 0x8217fd4c
	goto loc_8217FD4C;
loc_8217FB40:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,6690
	ctx.r10.s64 = 438435840;
	// li r3,7
	ctx.r3.s64 = 7;
	// ori r9,r10,407
	ctx.r9.u64 = ctx.r10.u64 | 407;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,17068(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17068);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r11,r11,-25756
	r11.s64 = r11.s64 + -25756;
	// bne cr6,0x8217fb10
	if (!cr6.eq) goto loc_8217FB10;
	// addi r9,r11,44
	ctx.r9.s64 = r11.s64 + 44;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FB74:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8217fd4c
	goto loc_8217FD4C;
loc_8217FB7C:
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x8217fd4c
	goto loc_8217FD4C;
loc_8217FB84:
	// li r3,30
	ctx.r3.s64 = 30;
	// b 0x8217fd4c
	goto loc_8217FD4C;
loc_8217FB8C:
	// li r3,29
	ctx.r3.s64 = 29;
	// b 0x8217fd4c
	goto loc_8217FD4C;
loc_8217FB94:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// stw r31,-25604(r11)
	PPC_STORE_U32(r11.u32 + -25604, r31.u32);
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
loc_8217FBB0:
	// li r3,32
	ctx.r3.s64 = 32;
	// b 0x8217fd4c
	goto loc_8217FD4C;
loc_8217FBB8:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-25756
	r11.s64 = r11.s64 + -25756;
	// li r3,33
	ctx.r3.s64 = 33;
	// addi r9,r11,-116
	ctx.r9.s64 = r11.s64 + -116;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FBD4:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-25756
	r11.s64 = r11.s64 + -25756;
	// li r3,20
	ctx.r3.s64 = 20;
	// addi r9,r11,-108
	ctx.r9.s64 = r11.s64 + -108;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FBF0:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-25756
	r11.s64 = r11.s64 + -25756;
	// li r3,21
	ctx.r3.s64 = 21;
	// addi r9,r11,-108
	ctx.r9.s64 = r11.s64 + -108;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FC0C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-25756
	r11.s64 = r11.s64 + -25756;
	// li r3,22
	ctx.r3.s64 = 22;
	// addi r9,r11,-108
	ctx.r9.s64 = r11.s64 + -108;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FC28:
	// li r3,11
	ctx.r3.s64 = 11;
	// b 0x8217fd4c
	goto loc_8217FD4C;
loc_8217FC30:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-25756
	ctx.r9.s64 = r11.s64 + -25756;
	// li r3,12
	ctx.r3.s64 = 12;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FC48:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-25756
	ctx.r9.s64 = r11.s64 + -25756;
	// li r3,13
	ctx.r3.s64 = 13;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FC60:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-25756
	ctx.r9.s64 = r11.s64 + -25756;
	// li r3,14
	ctx.r3.s64 = 14;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FC78:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-25756
	r11.s64 = r11.s64 + -25756;
	// li r3,15
	ctx.r3.s64 = 15;
	// addi r9,r11,-32
	ctx.r9.s64 = r11.s64 + -32;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FC94:
	// li r3,16
	ctx.r3.s64 = 16;
	// b 0x8217fd4c
	goto loc_8217FD4C;
loc_8217FC9C:
	// li r3,17
	ctx.r3.s64 = 17;
	// b 0x8217fd4c
	goto loc_8217FD4C;
loc_8217FCA4:
	// li r3,18
	ctx.r3.s64 = 18;
	// b 0x8217fd4c
	goto loc_8217FD4C;
loc_8217FCAC:
	// li r3,34
	ctx.r3.s64 = 34;
	// b 0x8217fd4c
	goto loc_8217FD4C;
loc_8217FCB4:
	// li r3,25
	ctx.r3.s64 = 25;
	// b 0x8217fd4c
	goto loc_8217FD4C;
loc_8217FCBC:
	// li r3,35
	ctx.r3.s64 = 35;
	// b 0x8217fd4c
	goto loc_8217FD4C;
loc_8217FCC4:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-25756
	ctx.r9.s64 = r11.s64 + -25756;
	// li r3,36
	ctx.r3.s64 = 36;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FCDC:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-25756
	ctx.r9.s64 = r11.s64 + -25756;
	// li r3,37
	ctx.r3.s64 = 37;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FCF4:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-25756
	ctx.r9.s64 = r11.s64 + -25756;
	// li r3,38
	ctx.r3.s64 = 38;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FD0C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-25756
	r11.s64 = r11.s64 + -25756;
	// li r3,39
	ctx.r3.s64 = 39;
	// addi r9,r11,-32
	ctx.r9.s64 = r11.s64 + -32;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// b 0x8217fd50
	goto loc_8217FD50;
loc_8217FD28:
	// li r3,40
	ctx.r3.s64 = 40;
	// b 0x8217fd4c
	goto loc_8217FD4C;
loc_8217FD30:
	// li r3,41
	ctx.r3.s64 = 41;
	// b 0x8217fd4c
	goto loc_8217FD4C;
loc_8217FD38:
	// li r3,42
	ctx.r3.s64 = 42;
	// b 0x8217fd4c
	goto loc_8217FD4C;
loc_8217FD40:
	// li r3,43
	ctx.r3.s64 = 43;
	// b 0x8217fd4c
	goto loc_8217FD4C;
loc_8217FD48:
	// li r3,44
	ctx.r3.s64 = 44;
loc_8217FD4C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
loc_8217FD50:
	// bl 0x82189e80
	ctx.lr = 0x8217FD54;
	sub_82189E80(ctx, base);
loc_8217FD54:
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

__attribute__((alias("__imp__sub_8217FD68"))) PPC_WEAK_FUNC(sub_8217FD68);
PPC_FUNC_IMPL(__imp__sub_8217FD68) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r3,25
	ctx.r3.s64 = 25;
	// subf r11,r31,r30
	r11.s64 = r30.s64 - r31.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r4,r9,1
	ctx.r4.u64 = ctx.r9.u64 ^ 1;
	// bl 0x82189e80
	ctx.lr = 0x8217FD9C;
	sub_82189E80(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// rlwinm r7,r31,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r8,-25952
	r31.s64 = ctx.r8.s64 + -25952;
	// li r3,4
	ctx.r3.s64 = 4;
	// lwzx r4,r7,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// bl 0x82189e80
	ctx.lr = 0x8217FDB4;
	sub_82189E80(ctx, base);
	// rlwinm r6,r30,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,26
	ctx.r3.s64 = 26;
	// lwzx r4,r6,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// bl 0x82189e80
	ctx.lr = 0x8217FDC4;
	sub_82189E80(ctx, base);
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

__attribute__((alias("__imp__sub_8217FDDC"))) PPC_WEAK_FUNC(sub_8217FDDC);
PPC_FUNC_IMPL(__imp__sub_8217FDDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217FDE0"))) PPC_WEAK_FUNC(sub_8217FDE0);
PPC_FUNC_IMPL(__imp__sub_8217FDE0) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r3,25
	ctx.r3.s64 = 25;
	// subf r11,r31,r30
	r11.s64 = r30.s64 - r31.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r4,r9,1
	ctx.r4.u64 = ctx.r9.u64 ^ 1;
	// bl 0x82189e80
	ctx.lr = 0x8217FE14;
	sub_82189E80(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// rlwinm r7,r31,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r8,-25892
	r31.s64 = ctx.r8.s64 + -25892;
	// li r3,23
	ctx.r3.s64 = 23;
	// lwzx r4,r7,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// bl 0x82189e80
	ctx.lr = 0x8217FE2C;
	sub_82189E80(ctx, base);
	// rlwinm r6,r30,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,24
	ctx.r3.s64 = 24;
	// lwzx r4,r6,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// bl 0x82189e80
	ctx.lr = 0x8217FE3C;
	sub_82189E80(ctx, base);
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

__attribute__((alias("__imp__sub_8217FE54"))) PPC_WEAK_FUNC(sub_8217FE54);
PPC_FUNC_IMPL(__imp__sub_8217FE54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217FE58"))) PPC_WEAK_FUNC(sub_8217FE58);
PPC_FUNC_IMPL(__imp__sub_8217FE58) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r3,25
	ctx.r3.s64 = 25;
	// subf r11,r31,r30
	r11.s64 = r30.s64 - r31.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r4,r9,1
	ctx.r4.u64 = ctx.r9.u64 ^ 1;
	// bl 0x82189e80
	ctx.lr = 0x8217FE8C;
	sub_82189E80(ctx, base);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// rlwinm r7,r31,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r8,-25952
	r31.s64 = ctx.r8.s64 + -25952;
	// li r3,5
	ctx.r3.s64 = 5;
	// lwzx r4,r7,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// bl 0x82189e80
	ctx.lr = 0x8217FEA4;
	sub_82189E80(ctx, base);
	// rlwinm r6,r30,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,27
	ctx.r3.s64 = 27;
	// lwzx r4,r6,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// bl 0x82189e80
	ctx.lr = 0x8217FEB4;
	sub_82189E80(ctx, base);
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

__attribute__((alias("__imp__sub_8217FECC"))) PPC_WEAK_FUNC(sub_8217FECC);
PPC_FUNC_IMPL(__imp__sub_8217FECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217FED0"))) PPC_WEAK_FUNC(sub_8217FED0);
PPC_FUNC_IMPL(__imp__sub_8217FED0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-25776
	ctx.r9.s64 = r11.s64 + -25776;
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217FEE4"))) PPC_WEAK_FUNC(sub_8217FEE4);
PPC_FUNC_IMPL(__imp__sub_8217FEE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217FEE8"))) PPC_WEAK_FUNC(sub_8217FEE8);
PPC_FUNC_IMPL(__imp__sub_8217FEE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
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
	// li r8,16
	ctx.r8.s64 = 16;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,32
	ctx.r9.s64 = 32;
	// addi r11,r4,64
	r11.s64 = ctx.r4.s64 + 64;
	// addi r10,r3,64
	ctx.r10.s64 = ctx.r3.s64 + 64;
	// lvx128 v62,r4,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r4,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,48(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	f0.f64 = double(temp.f32);
	// stfs f0,48(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// lfs f13,52(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,52(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// lfs f12,56(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,56(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// lbz r7,60(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 60);
	// stb r7,60(r3)
	PPC_STORE_U8(ctx.r3.u32 + 60, ctx.r7.u8);
	// lbz r6,61(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 61);
	// stb r6,61(r3)
	PPC_STORE_U8(ctx.r3.u32 + 61, ctx.r6.u8);
	// lbz r5,62(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 62);
	// stb r5,62(r3)
	PPC_STORE_U8(ctx.r3.u32 + 62, ctx.r5.u8);
	// lbz r7,63(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 63);
	// stb r7,63(r3)
	PPC_STORE_U8(ctx.r3.u32 + 63, ctx.r7.u8);
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r11,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r11,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,128
	r11.s64 = ctx.r4.s64 + 128;
	// stvx128 v58,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,128
	ctx.r10.s64 = ctx.r3.s64 + 128;
	// lfs f11,112(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,112(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// lfs f10,116(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 116);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,116(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// lfs f9,120(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 120);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,120(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// lbz r6,124(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 124);
	// stb r6,124(r3)
	PPC_STORE_U8(ctx.r3.u32 + 124, ctx.r6.u8);
	// lbz r5,125(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 125);
	// stb r5,125(r3)
	PPC_STORE_U8(ctx.r3.u32 + 125, ctx.r5.u8);
	// lbz r7,126(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 126);
	// stb r7,126(r3)
	PPC_STORE_U8(ctx.r3.u32 + 126, ctx.r7.u8);
	// lbz r6,127(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 127);
	// stb r6,127(r3)
	PPC_STORE_U8(ctx.r3.u32 + 127, ctx.r6.u8);
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r11,r8
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r11,r9
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,176(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 176);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,48(r10)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r10.u32 + 48, temp.u32);
	// lfs f7,180(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 180);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,52(r10)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + 52, temp.u32);
	// lfs f6,184(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 184);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,56(r10)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r10.u32 + 56, temp.u32);
	// lbz r5,188(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 188);
	// stb r5,60(r10)
	PPC_STORE_U8(ctx.r10.u32 + 60, ctx.r5.u8);
	// lbz r11,189(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 189);
	// stb r11,61(r10)
	PPC_STORE_U8(ctx.r10.u32 + 61, r11.u8);
	// lbz r9,190(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 190);
	// stb r9,62(r10)
	PPC_STORE_U8(ctx.r10.u32 + 62, ctx.r9.u8);
	// lbz r8,191(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 191);
	// stb r8,63(r10)
	PPC_STORE_U8(ctx.r10.u32 + 63, ctx.r8.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8217FFF4"))) PPC_WEAK_FUNC(sub_8217FFF4);
PPC_FUNC_IMPL(__imp__sub_8217FFF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8217FFF8"))) PPC_WEAK_FUNC(sub_8217FFF8);
PPC_FUNC_IMPL(__imp__sub_8217FFF8) {
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
	ctx.lr = 0x82180000;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r11,17328
	r29.s64 = r11.s64 + 17328;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_82180014:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8217f768
	ctx.lr = 0x82180020;
	sub_8217F768(ctx, base);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r29,160
	r11.s64 = r29.s64 + 160;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x82180014
	if (cr6.lt) goto loc_82180014;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217d9a0
	ctx.lr = 0x8218003C;
	sub_8217D9A0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82180044"))) PPC_WEAK_FUNC(sub_82180044);
PPC_FUNC_IMPL(__imp__sub_82180044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82180048"))) PPC_WEAK_FUNC(sub_82180048);
PPC_FUNC_IMPL(__imp__sub_82180048) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8217fee8
	ctx.lr = 0x82180068;
	sub_8217FEE8(ctx, base);
	// li r11,192
	r11.s64 = 192;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v63,r30,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhz r11,208(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 208);
	// sth r11,208(r31)
	PPC_STORE_U16(r31.u32 + 208, r11.u16);
	// lhz r10,210(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 210);
	// sth r10,210(r31)
	PPC_STORE_U16(r31.u32 + 210, ctx.r10.u16);
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

__attribute__((alias("__imp__sub_821800A0"))) PPC_WEAK_FUNC(sub_821800A0);
PPC_FUNC_IMPL(__imp__sub_821800A0) {
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
	ctx.lr = 0x821800A8;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r11,-25584
	r30.s64 = r11.s64 + -25584;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217fee8
	ctx.lr = 0x821800C4;
	sub_8217FEE8(ctx, base);
	// addi r27,r31,192
	r27.s64 = r31.s64 + 192;
	// li r10,192
	ctx.r10.s64 = 192;
	// lvx128 v63,r0,r27
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r30,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhz r11,208(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 208);
	// sth r11,208(r30)
	PPC_STORE_U16(r30.u32 + 208, r11.u16);
	// lhz r11,210(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 210);
	// sth r11,210(r30)
	PPC_STORE_U16(r30.u32 + 210, r11.u16);
	// lhz r9,208(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 208);
	// extsh r30,r9
	r30.s64 = ctx.r9.s16;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82180278
	if (!cr6.gt) goto loc_82180278;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r6,r11,-25776
	ctx.r6.s64 = r11.s64 + -25776;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// addi r10,r31,60
	ctx.r10.s64 = r31.s64 + 60;
	// lfs f0,14192(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	f0.f64 = double(temp.f32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r4,4(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r31,r30
	r31.u64 = r30.u64;
	// li r3,-28
	ctx.r3.s64 = -28;
	// addi r29,r11,-25600
	r29.s64 = r11.s64 + -25600;
	// addi r28,r8,-32224
	r28.s64 = ctx.r8.s64 + -32224;
loc_8218012C:
	// lfs f13,-8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	ctx.f13.f64 = double(temp.f32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// blt cr6,0x82180158
	if (cr6.lt) goto loc_82180158;
	// lbz r11,0(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82180158
	if (!cr6.eq) goto loc_82180158;
	// addi r11,r10,-44
	r11.s64 = ctx.r10.s64 + -44;
	// li r6,1
	ctx.r6.s64 = 1;
	// b 0x82180180
	goto loc_82180180;
loc_82180158:
	// cmpwi cr6,r4,3
	cr6.compare<int32_t>(ctx.r4.s32, 3, xer);
	// bne cr6,0x8218017c
	if (!cr6.eq) goto loc_8218017C;
	// lbz r11,0(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x8218017c
	if (!cr6.eq) goto loc_8218017C;
	// addi r11,r10,-44
	r11.s64 = ctx.r10.s64 + -44;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r8,r10,-60
	ctx.r8.s64 = ctx.r10.s64 + -60;
	// b 0x82180180
	goto loc_82180180;
loc_8218017C:
	// addi r11,r10,-60
	r11.s64 = ctx.r10.s64 + -60;
loc_82180180:
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// addi r11,r1,220
	r11.s64 = ctx.r1.s64 + 220;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stvx128 v63,r9,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfsx f13,r9,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, temp.u32);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// beq cr6,0x821801f4
	if (cr6.eq) goto loc_821801F4;
	// addi r7,r1,120
	ctx.r7.s64 = ctx.r1.s64 + 120;
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 + r11.u64;
	// lfs f13,-4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// add r11,r9,r7
	r11.u64 = ctx.r9.u64 + ctx.r7.u64;
	// addi r26,r1,124
	r26.s64 = ctx.r1.s64 + 124;
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfsx f9,r9,r7
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f7.f64 = double(temp.f32);
	// lfs f12,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f8,f12,f0
	ctx.f8.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f8,0(r8)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// fmuls f6,f9,f0
	ctx.f6.f64 = double(float(ctx.f9.f64 * f0.f64));
	// stfsx f6,r9,r7
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r7.u32, temp.u32);
	// fmuls f5,f7,f0
	ctx.f5.f64 = double(float(ctx.f7.f64 * f0.f64));
	// stfs f5,-4(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// stfs f10,4(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfsx f13,r9,r26
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + r26.u32, temp.u32);
	// b 0x821801fc
	goto loc_821801FC;
loc_821801F4:
	// lvx128 v61,r0,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r9,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_821801FC:
	// extsw r8,r6
	ctx.r8.s64 = ctx.r6.s32;
	// lbz r7,2(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lvx128 v60,r10,r3
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// addi r8,r1,172
	ctx.r8.s64 = ctx.r1.s64 + 172;
	// lfs f11,-12(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12);
	ctx.f11.f64 = double(temp.f32);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f10,0(r5)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stfsx f11,r9,r8
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, temp.u32);
	// beq cr6,0x8218024c
	if (cr6.eq) goto loc_8218024C;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r29
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v57,v59,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v58.f32)));
	// stvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8218024C:
	// lbz r11,1(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82180264
	if (cr6.eq) goto loc_82180264;
	// lfsx f13,r9,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfsx f12,r9,r8
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, temp.u32);
loc_82180264:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r5,r5,4
	ctx.r5.s64 = ctx.r5.s64 + 4;
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bne 0x8218012c
	if (!cr0.eq) goto loc_8218012C;
loc_82180278:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r31,r11,-25616
	r31.s64 = r11.s64 + -25616;
	// lwz r11,-172(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -172);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x821802f4
	if (!cr6.eq) goto loc_821802F4;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-25620
	ctx.r3.s64 = r11.s64 + -25620;
	// bl 0x8218a4e8
	ctx.lr = 0x8218029C;
	sub_8218A4E8(ctx, base);
	// stw r3,-172(r31)
	PPC_STORE_U32(r31.u32 + -172, ctx.r3.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,-25632
	ctx.r3.s64 = ctx.r10.s64 + -25632;
	// bl 0x8218a4e8
	ctx.lr = 0x821802B0;
	sub_8218A4E8(ctx, base);
	// stw r3,-180(r31)
	PPC_STORE_U32(r31.u32 + -180, ctx.r3.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r9,-25644
	ctx.r3.s64 = ctx.r9.s64 + -25644;
	// bl 0x8218a4e8
	ctx.lr = 0x821802C4;
	sub_8218A4E8(ctx, base);
	// stw r3,-188(r31)
	PPC_STORE_U32(r31.u32 + -188, ctx.r3.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r8,-25656
	ctx.r3.s64 = ctx.r8.s64 + -25656;
	// bl 0x8218a4e8
	ctx.lr = 0x821802D8;
	sub_8218A4E8(ctx, base);
	// stw r3,-176(r31)
	PPC_STORE_U32(r31.u32 + -176, ctx.r3.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r7,-25664
	ctx.r3.s64 = ctx.r7.s64 + -25664;
	// bl 0x8218a4e8
	ctx.lr = 0x821802EC;
	sub_8218A4E8(ctx, base);
	// lwz r11,-172(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -172);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_821802F4:
	// li r6,5
	ctx.r6.s64 = 5;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8218aef8
	ctx.lr = 0x82180308;
	sub_8218AEF8(ctx, base);
	// li r6,5
	ctx.r6.s64 = 5;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r3,-180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -180);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// bl 0x8218aef8
	ctx.lr = 0x8218031C;
	sub_8218AEF8(ctx, base);
	// li r6,5
	ctx.r6.s64 = 5;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r3,-188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -188);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x8218aef8
	ctx.lr = 0x82180330;
	sub_8218AEF8(ctx, base);
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,-176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -176);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x8218aef8
	ctx.lr = 0x82180344;
	sub_8218AEF8(ctx, base);
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8218aef8
	ctx.lr = 0x82180358;
	sub_8218AEF8(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82180360"))) PPC_WEAK_FUNC(sub_82180360);
PPC_FUNC_IMPL(__imp__sub_82180360) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-25292
	ctx.r10.s64 = r11.s64 + -25292;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82180370"))) PPC_WEAK_FUNC(sub_82180370);
PPC_FUNC_IMPL(__imp__sub_82180370) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r9,r10,-25292
	ctx.r9.s64 = ctx.r10.s64 + -25292;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// lwz r10,-25232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// cmplw cr6,r10,r3
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,-25232(r11)
	PPC_STORE_U32(r11.u32 + -25232, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82180398"))) PPC_WEAK_FUNC(sub_82180398);
PPC_FUNC_IMPL(__imp__sub_82180398) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-25308
	ctx.r10.s64 = r11.s64 + -25308;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x821d2810
	sub_821D2810(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821803A8"))) PPC_WEAK_FUNC(sub_821803A8);
PPC_FUNC_IMPL(__imp__sub_821803A8) {
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
	ctx.lr = 0x821803B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r28,0
	r28.s64 = 0;
	// addi r29,r11,-25336
	r29.s64 = r11.s64 + -25336;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_821803C4:
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82180404
	if (cr6.eq) goto loc_82180404;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x821803D8;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82180400
	if (!cr6.eq) goto loc_82180400;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82180400
	if (cr6.eq) goto loc_82180400;
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
	ctx.lr = 0x82180400;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82180400:
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
loc_82180404:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r29,96
	r11.s64 = r29.s64 + 96;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x821803c4
	if (cr6.lt) goto loc_821803C4;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8218041C"))) PPC_WEAK_FUNC(sub_8218041C);
PPC_FUNC_IMPL(__imp__sub_8218041C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82180420"))) PPC_WEAK_FUNC(sub_82180420);
PPC_FUNC_IMPL(__imp__sub_82180420) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x82184458
	sub_82184458(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8218042C"))) PPC_WEAK_FUNC(sub_8218042C);
PPC_FUNC_IMPL(__imp__sub_8218042C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82180430"))) PPC_WEAK_FUNC(sub_82180430);
PPC_FUNC_IMPL(__imp__sub_82180430) {
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
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stb r10,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r10.u8);
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// stb r10,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r10.u8);
	// stb r10,17(r31)
	PPC_STORE_U8(r31.u32 + 17, ctx.r10.u8);
	// stb r11,18(r31)
	PPC_STORE_U8(r31.u32 + 18, r11.u8);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stb r11,24(r31)
	PPC_STORE_U8(r31.u32 + 24, r11.u8);
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// stb r11,36(r31)
	PPC_STORE_U8(r31.u32 + 36, r11.u8);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// beq cr6,0x82180494
	if (cr6.eq) goto loc_82180494;
	// li r5,44
	ctx.r5.s64 = 44;
	// bl 0x823da950
	ctx.lr = 0x82180490;
	sub_823DA950(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82180494:
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

__attribute__((alias("__imp__sub_821804A8"))) PPC_WEAK_FUNC(sub_821804A8);
PPC_FUNC_IMPL(__imp__sub_821804A8) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r30,r31,24
	r30.s64 = r31.s64 + 24;
	// addi r4,r11,-25120
	ctx.r4.s64 = r11.s64 + -25120;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8218c760
	ctx.lr = 0x821804D8;
	sub_8218C760(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r10,-25132
	ctx.r4.s64 = ctx.r10.s64 + -25132;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8218b688
	ctx.lr = 0x821804EC;
	sub_8218B688(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r9,-27772
	ctx.r4.s64 = ctx.r9.s64 + -27772;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8218b688
	ctx.lr = 0x82180504;
	sub_8218B688(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r8,-25144
	ctx.r4.s64 = ctx.r8.s64 + -25144;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8218b688
	ctx.lr = 0x8218051C;
	sub_8218B688(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r7,-25152
	ctx.r4.s64 = ctx.r7.s64 + -25152;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8218a568
	ctx.lr = 0x82180534;
	sub_8218A568(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-25164
	ctx.r4.s64 = ctx.r6.s64 + -25164;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8218a568
	ctx.lr = 0x8218054C;
	sub_8218A568(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// stb r5,112(r31)
	PPC_STORE_U8(r31.u32 + 112, ctx.r5.u8);
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

__attribute__((alias("__imp__sub_82180570"))) PPC_WEAK_FUNC(sub_82180570);
PPC_FUNC_IMPL(__imp__sub_82180570) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// addic. r10,r11,-1
	xer.ca = r11.u32 > 0;
	ctx.r10.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt 0x821805b8
	if (cr0.lt) goto loc_821805B8;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
loc_82180588:
	// add r11,r10,r9
	r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// srawi r3,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r3.s64 = r11.s32 >> 1;
	// rlwinm r6,r3,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r6,r7
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r7.u32);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// bge cr6,0x821805ac
	if (!cr6.lt) goto loc_821805AC;
	// addi r10,r3,-1
	ctx.r10.s64 = ctx.r3.s64 + -1;
	// b 0x821805b0
	goto loc_821805B0;
loc_821805AC:
	// addi r9,r3,1
	ctx.r9.s64 = ctx.r3.s64 + 1;
loc_821805B0:
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// ble cr6,0x82180588
	if (!cr6.gt) goto loc_82180588;
loc_821805B8:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821805C0"))) PPC_WEAK_FUNC(sub_821805C0);
PPC_FUNC_IMPL(__imp__sub_821805C0) {
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
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218065c
	if (cr6.eq) goto loc_8218065C;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821c9550
	ctx.lr = 0x821805F0;
	sub_821C9550(ctx, base);
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
	// lwzx r8,r6,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8218065c
	if (cr6.eq) goto loc_8218065C;
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_8218061C:
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
loc_82180624:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// beq cr6,0x82180648
	if (cr6.eq) goto loc_82180648;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82180624
	if (cr6.eq) goto loc_82180624;
loc_82180648:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82180678
	if (cr6.eq) goto loc_82180678;
	// lwz r8,20(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8218061c
	if (!cr6.eq) goto loc_8218061C;
loc_8218065C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82180660:
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
loc_82180678:
	// addi r3,r8,4
	ctx.r3.s64 = ctx.r8.s64 + 4;
	// b 0x82180660
	goto loc_82180660;
}

__attribute__((alias("__imp__sub_82180680"))) PPC_WEAK_FUNC(sub_82180680);
PPC_FUNC_IMPL(__imp__sub_82180680) {
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
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821806f8
	if (cr6.eq) goto loc_821806F8;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821c95a0
	ctx.lr = 0x821806B0;
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
	// beq cr6,0x821806f8
	if (cr6.eq) goto loc_821806F8;
loc_821806D8:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x823db730
	ctx.lr = 0x821806E4;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82180714
	if (cr6.eq) goto loc_82180714;
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x821806d8
	if (!cr6.eq) goto loc_821806D8;
loc_821806F8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821806FC:
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
loc_82180714:
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// b 0x821806fc
	goto loc_821806FC;
}

__attribute__((alias("__imp__sub_8218071C"))) PPC_WEAK_FUNC(sub_8218071C);
PPC_FUNC_IMPL(__imp__sub_8218071C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82180720"))) PPC_WEAK_FUNC(sub_82180720);
PPC_FUNC_IMPL(__imp__sub_82180720) {
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
	ctx.lr = 0x82180728;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// lbz r11,11(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 11);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821807f4
	if (cr6.eq) goto loc_821807F4;
	// rlwinm r3,r24,2,14,29
	ctx.r3.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0x3FFFC;
	// clrlwi r29,r24,16
	r29.u64 = r24.u32 & 0xFFFF;
	// bl 0x82130528
	ctx.lr = 0x8218074C;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82180770
	if (cr6.eq) goto loc_82180770;
	// mr r11,r28
	r11.u64 = r28.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mtctr r29
	ctr.u64 = r29.u64;
loc_82180764:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82180764
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82180764;
loc_82180770:
	// lhz r11,4(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821807e4
	if (cr6.eq) goto loc_821807E4;
	// li r27,0
	r27.s64 = 0;
loc_82180784:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwzx r31,r27,r11
	r31.u64 = PPC_LOAD_U32(r27.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821807d0
	if (cr6.eq) goto loc_821807D0;
loc_82180794:
	// mr r23,r31
	r23.u64 = r31.u64;
	// addi r30,r31,8
	r30.s64 = r31.s64 + 8;
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// bl 0x821c95a0
	ctx.lr = 0x821807A8;
	sub_821C95A0(ctx, base);
	// divwu r11,r3,r29
	r11.u32 = ctx.r3.u32 / r29.u32;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// mullw r10,r11,r29
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(r29.s32);
	// subf r9,r10,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r10.s64;
	// twllei r29,0
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r11,r28
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
	// stwx r23,r11,r28
	PPC_STORE_U32(r11.u32 + r28.u32, r23.u32);
	// bne cr6,0x82180794
	if (!cr6.eq) goto loc_82180794;
loc_821807D0:
	// lhz r11,4(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// blt cr6,0x82180784
	if (cr6.lt) goto loc_82180784;
loc_821807E4:
	// sth r24,4(r25)
	PPC_STORE_U16(r25.u32 + 4, r24.u16);
	// lwz r3,0(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x821807F0;
	sub_82130588(ctx, base);
	// stw r28,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r28.u32);
loc_821807F4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_821807FC"))) PPC_WEAK_FUNC(sub_821807FC);
PPC_FUNC_IMPL(__imp__sub_821807FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82180800"))) PPC_WEAK_FUNC(sub_82180800);
PPC_FUNC_IMPL(__imp__sub_82180800) {
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
	ctx.lr = 0x82180808;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// lbz r11,11(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 11);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821808d4
	if (cr6.eq) goto loc_821808D4;
	// rlwinm r3,r24,2,14,29
	ctx.r3.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0x3FFFC;
	// clrlwi r29,r24,16
	r29.u64 = r24.u32 & 0xFFFF;
	// bl 0x82130528
	ctx.lr = 0x8218082C;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82180850
	if (cr6.eq) goto loc_82180850;
	// mr r11,r28
	r11.u64 = r28.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mtctr r29
	ctr.u64 = r29.u64;
loc_82180844:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82180844
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82180844;
loc_82180850:
	// lhz r11,4(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821808c4
	if (cr6.eq) goto loc_821808C4;
	// li r27,0
	r27.s64 = 0;
loc_82180864:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwzx r31,r27,r11
	r31.u64 = PPC_LOAD_U32(r27.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821808b0
	if (cr6.eq) goto loc_821808B0;
loc_82180874:
	// mr r23,r31
	r23.u64 = r31.u64;
	// addi r30,r31,20
	r30.s64 = r31.s64 + 20;
	// lwz r31,20(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r3,0(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// bl 0x821c9550
	ctx.lr = 0x82180888;
	sub_821C9550(ctx, base);
	// divwu r11,r3,r29
	r11.u32 = ctx.r3.u32 / r29.u32;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// mullw r10,r11,r29
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(r29.s32);
	// subf r9,r10,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r10.s64;
	// twllei r29,0
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r11,r28
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
	// stwx r23,r11,r28
	PPC_STORE_U32(r11.u32 + r28.u32, r23.u32);
	// bne cr6,0x82180874
	if (!cr6.eq) goto loc_82180874;
loc_821808B0:
	// lhz r11,4(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmplw cr6,r26,r11
	cr6.compare<uint32_t>(r26.u32, r11.u32, xer);
	// blt cr6,0x82180864
	if (cr6.lt) goto loc_82180864;
loc_821808C4:
	// sth r24,4(r25)
	PPC_STORE_U16(r25.u32 + 4, r24.u16);
	// lwz r3,0(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x821808D0;
	sub_82130588(ctx, base);
	// stw r28,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r28.u32);
loc_821808D4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_821808DC"))) PPC_WEAK_FUNC(sub_821808DC);
PPC_FUNC_IMPL(__imp__sub_821808DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821808E0"))) PPC_WEAK_FUNC(sub_821808E0);
PPC_FUNC_IMPL(__imp__sub_821808E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mulli r10,r4,28
	ctx.r10.s64 = ctx.r4.s64 * 28;
	// addi r11,r11,-25032
	r11.s64 = r11.s64 + -25032;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r5,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82180900"))) PPC_WEAK_FUNC(sub_82180900);
PPC_FUNC_IMPL(__imp__sub_82180900) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mulli r10,r4,28
	ctx.r10.s64 = ctx.r4.s64 * 28;
	// addi r11,r11,-25032
	r11.s64 = r11.s64 + -25032;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82180920"))) PPC_WEAK_FUNC(sub_82180920);
PPC_FUNC_IMPL(__imp__sub_82180920) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mulli r10,r4,28
	ctx.r10.s64 = ctx.r4.s64 * 28;
	// addi r11,r11,-25032
	r11.s64 = r11.s64 + -25032;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// bne cr6,0x82180958
	if (!cr6.eq) goto loc_82180958;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
loc_82180958:
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r5,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, ctx.r5.u32);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82180974"))) PPC_WEAK_FUNC(sub_82180974);
PPC_FUNC_IMPL(__imp__sub_82180974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82180978"))) PPC_WEAK_FUNC(sub_82180978);
PPC_FUNC_IMPL(__imp__sub_82180978) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mulli r10,r4,28
	ctx.r10.s64 = ctx.r4.s64 * 28;
	// addi r11,r11,-25032
	r11.s64 = r11.s64 + -25032;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r9.u32);
	// bne cr6,0x821809b4
	if (!cr6.eq) goto loc_821809B4;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r9,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r9.u32);
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// blr 
	return;
loc_821809B4:
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// stw r8,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r8.u32);
	// lwzx r3,r9,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821809C8"))) PPC_WEAK_FUNC(sub_821809C8);
PPC_FUNC_IMPL(__imp__sub_821809C8) {
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
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r9,r10,-25292
	ctx.r9.s64 = ctx.r10.s64 + -25292;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r10,-25232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// bne cr6,0x82180a00
	if (!cr6.eq) goto loc_82180A00;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,-25232(r11)
	PPC_STORE_U32(r11.u32 + -25232, ctx.r10.u32);
loc_82180A00:
	// clrlwi r11,r4,31
	r11.u64 = ctx.r4.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82180a18
	if (cr6.eq) goto loc_82180A18;
	// bl 0x82130588
	ctx.lr = 0x82180A14;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82180A18:
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

__attribute__((alias("__imp__sub_82180A2C"))) PPC_WEAK_FUNC(sub_82180A2C);
PPC_FUNC_IMPL(__imp__sub_82180A2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82180A30"))) PPC_WEAK_FUNC(sub_82180A30);
PPC_FUNC_IMPL(__imp__sub_82180A30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r5,96
	ctx.r5.s64 = 96;
	// addi r3,r11,-25336
	ctx.r3.s64 = r11.s64 + -25336;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x82180A58;
	sub_823D9890(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-25064
	ctx.r4.s64 = ctx.r9.s64 + -25064;
	// lwz r3,-25232(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -25232);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,12(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82180A80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32124
	ctx.r6.s64 = -2105278464;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r5,-25076
	ctx.r4.s64 = ctx.r5.s64 + -25076;
	// stw r11,-25360(r6)
	PPC_STORE_U32(ctx.r6.u32 + -25360, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82180AAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// lis r5,-203
	ctx.r5.s64 = -13303808;
	// li r4,-6859
	ctx.r4.s64 = -6859;
	// ori r5,r5,65023
	ctx.r5.u64 = ctx.r5.u64 | 65023;
	// stw r3,-25356(r9)
	PPC_STORE_U32(ctx.r9.u32 + -25356, ctx.r3.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8218ecf8
	ctx.lr = 0x82180AC8;
	sub_8218ECF8(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82180AE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32124
	ctx.r6.s64 = -2105278464;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r4,r5,-25092
	ctx.r4.s64 = ctx.r5.s64 + -25092;
	// li r8,32
	ctx.r8.s64 = 32;
	// stw r3,-25240(r6)
	PPC_STORE_U32(ctx.r6.u32 + -25240, ctx.r3.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82180B20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// stw r3,-25236(r9)
	PPC_STORE_U32(ctx.r9.u32 + -25236, ctx.r3.u32);
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addic. r11,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	r11.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// bne 0x82180b48
	if (!cr0.eq) goto loc_82180B48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218cd10
	ctx.lr = 0x82180B40;
	sub_8218CD10(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82180B48;
	sub_82130588(ctx, base);
loc_82180B48:
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

__attribute__((alias("__imp__sub_82180B60"))) PPC_WEAK_FUNC(sub_82180B60);
PPC_FUNC_IMPL(__imp__sub_82180B60) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r11,-24892
	ctx.r3.s64 = r11.s64 + -24892;
	// bl 0x821805c0
	ctx.lr = 0x82180B80;
	sub_821805C0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82180B90"))) PPC_WEAK_FUNC(sub_82180B90);
PPC_FUNC_IMPL(__imp__sub_82180B90) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r11,-25044
	ctx.r3.s64 = r11.s64 + -25044;
	// bl 0x82180680
	ctx.lr = 0x82180BB0;
	sub_82180680(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82180bcc
	if (cr6.eq) goto loc_82180BCC;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82180BCC:
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

__attribute__((alias("__imp__sub_82180BE0"))) PPC_WEAK_FUNC(sub_82180BE0);
PPC_FUNC_IMPL(__imp__sub_82180BE0) {
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
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82180BE8;
	// stfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f29.u64);
	// stfd f30,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,-1
	ctx.r10.s64 = -1;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addi r31,r29,24
	r31.s64 = r29.s64 + 24;
	// fsel f13,f1,f1,f31
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f31.f64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// lfs f0,12428(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12428);
	f0.f64 = double(temp.f32);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r4,r31,48
	ctx.r4.s64 = r31.s64 + 48;
	// lwz r5,12(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f30,f12,f0,f13
	f30.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// bl 0x82189ce0
	ctx.lr = 0x82180C44;
	sub_82189CE0(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lfs f11,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmuls f29,f11,f30
	f29.f64 = double(float(ctx.f11.f64 * f30.f64));
	// lwz r7,28(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82180C60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r6,r3
	ctx.r6.s64 = ctx.r3.s32;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lfs f10,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// std r6,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r6.u64);
	// lfd f9,104(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// lwz r4,24(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	// fmuls f30,f10,f30
	f30.f64 = double(float(ctx.f10.f64 * f30.f64));
	// fdivs f29,f29,f7
	f29.f64 = double(float(f29.f64 / ctx.f7.f64));
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x82180C94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r3,r3
	ctx.r3.s64 = ctx.r3.s32;
	// stfs f29,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r4,r31,48
	ctx.r4.s64 = r31.s64 + 48;
	// std r3,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r3.u64);
	// lfd f6,104(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// stfs f31,124(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,16(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fdivs f3,f30,f4
	ctx.f3.f64 = double(float(f30.f64 / ctx.f4.f64));
	// stfs f3,112(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x8218a6e0
	ctx.lr = 0x82180CDC;
	sub_8218A6E0(ctx, base);
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lis r27,-32124
	r27.s64 = -2105278464;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,-21076(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21076, r11.u32);
	// beq cr6,0x82180d14
	if (cr6.eq) goto loc_82180D14;
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// stb r10,-21095(r8)
	PPC_STORE_U8(ctx.r8.u32 + -21095, ctx.r10.u8);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// stw r11,-21088(r27)
	PPC_STORE_U32(r27.u32 + -21088, r11.u32);
loc_82180D14:
	// addi r5,r31,48
	ctx.r5.s64 = r31.s64 + 48;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218bb08
	ctx.lr = 0x82180D24;
	sub_8218BB08(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82180D38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// std r9,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r9.u64);
	// lfd f0,104(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lwz r7,28(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// frsp f30,f13
	f30.f64 = double(float(ctx.f13.f64));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82180D60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r6,r3
	ctx.r6.s64 = ctx.r3.s32;
	// lfs f7,4(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f6,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// std r6,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r6.u64);
	// lfd f12,104(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f0,14884(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// lfs f2,31492(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 31492);
	ctx.f2.f64 = double(temp.f32);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// lfs f9,4(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f3,f30,f0
	ctx.f3.f64 = double(float(f30.f64 - f0.f64));
	// lfs f8,0(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fadds f9,f9,f7
	ctx.f9.f64 = double(float(ctx.f9.f64 + ctx.f7.f64));
	// fadds f8,f6,f8
	ctx.f8.f64 = double(float(ctx.f6.f64 + ctx.f8.f64));
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// fsubs f4,f10,f0
	ctx.f4.f64 = double(float(ctx.f10.f64 - f0.f64));
	// bl 0x8217a2e0
	ctx.lr = 0x82180DB8;
	sub_8217A2E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218ad48
	ctx.lr = 0x82180DC0;
	sub_8218AD48(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// stw r11,-21088(r27)
	PPC_STORE_U32(r27.u32 + -21088, r11.u32);
	// addi r4,r31,48
	ctx.r4.s64 = r31.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,12(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwz r6,-25360(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -25360);
	// bl 0x82189ce0
	ctx.lr = 0x82180DE0;
	sub_82189CE0(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82180DF4"))) PPC_WEAK_FUNC(sub_82180DF4);
PPC_FUNC_IMPL(__imp__sub_82180DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82180DF8"))) PPC_WEAK_FUNC(sub_82180DF8);
PPC_FUNC_IMPL(__imp__sub_82180DF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// beq cr6,0x82180e74
	if (cr6.eq) goto loc_82180E74;
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// beq cr6,0x82180e74
	if (cr6.eq) goto loc_82180E74;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// ble cr6,0x82180e30
	if (!cr6.gt) goto loc_82180E30;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// b 0x82180e34
	goto loc_82180E34;
loc_82180E30:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82180E34:
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r8,r4,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r4,8(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r3,4(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// extsw r9,r4
	ctx.r9.s64 = ctx.r4.s32;
	// extsw r8,r3
	ctx.r8.s64 = ctx.r3.s32;
	// std r9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f13,f12
	ctx.f13.f64 = double(float(ctx.f12.f64));
	// frsp f12,f11
	ctx.f12.f64 = double(float(ctx.f11.f64));
	// b 0x82180ed4
	goto loc_82180ED4;
loc_82180E74:
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// ble cr6,0x82180e94
	if (!cr6.gt) goto loc_82180E94;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// b 0x82180e98
	goto loc_82180E98;
loc_82180E94:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82180E98:
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// rlwinm r8,r4,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// extsw r9,r4
	ctx.r9.s64 = ctx.r4.s32;
	// extsw r8,r3
	ctx.r8.s64 = ctx.r3.s32;
	// std r9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// lfd f13,-16(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f13,f11
	ctx.f13.f64 = double(float(ctx.f11.f64));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
loc_82180ED4:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// stfs f0,-12(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// ld r7,-16(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// std r7,0(r5)
	PPC_STORE_U64(ctx.r5.u32 + 0, ctx.r7.u64);
	// stfs f0,-12(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// ld r4,-16(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r4,0(r6)
	PPC_STORE_U64(ctx.r6.u32 + 0, ctx.r4.u64);
	// beq cr6,0x82180fc4
	if (cr6.eq) goto loc_82180FC4;
	// lhz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 48);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// extsw r4,r8
	ctx.r4.s64 = ctx.r8.s32;
	// std r7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f0,-16(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r4.u64);
	// lfd f11,-16(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// fcfid f9,f0
	ctx.f9.f64 = double(f0.s64);
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fdivs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 / ctx.f7.f64));
	// stfs f6,0(r5)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// lhz r8,50(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 50);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f5,-16(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f4,-16(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f2,f4
	ctx.f2.f64 = double(ctx.f4.s64);
	// fcfid f3,f5
	ctx.f3.f64 = double(ctx.f5.s64);
	// frsp f0,f2
	f0.f64 = double(float(ctx.f2.f64));
	// frsp f1,f3
	ctx.f1.f64 = double(float(ctx.f3.f64));
	// fdivs f11,f1,f0
	ctx.f11.f64 = double(float(ctx.f1.f64 / f0.f64));
	// stfs f11,4(r5)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// lhz r5,48(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 48);
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r4.u64);
	// lfd f10,-16(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fdivs f7,f13,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 / ctx.f8.f64));
	// stfs f7,0(r6)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// lhz r11,50(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 50);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r10.u64);
	// lfd f6,-16(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fdivs f3,f12,f4
	ctx.f3.f64 = double(float(ctx.f12.f64 / ctx.f4.f64));
	// stfs f3,4(r6)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// blr 
	return;
loc_82180FC4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82180FCC"))) PPC_WEAK_FUNC(sub_82180FCC);
PPC_FUNC_IMPL(__imp__sub_82180FCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82180FD0"))) PPC_WEAK_FUNC(sub_82180FD0);
PPC_FUNC_IMPL(__imp__sub_82180FD0) {
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
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82181078
	if (!cr6.eq) goto loc_82181078;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r3,r10,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x82181014;
	sub_82130528(ctx, base);
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8218106c
	if (cr6.eq) goto loc_8218106C;
	// li r11,0
	r11.s64 = 0;
loc_82181028:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r5,r10,r30
	ctx.r5.u64 = ctx.r10.u64 + r30.u64;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// stwx r4,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, ctx.r4.u32);
	// lwz r3,4(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r3,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r3.u32);
	// lwz r10,8(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// blt cr6,0x82181028
	if (cr6.lt) goto loc_82181028;
loc_8218106C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82181074;
	sub_82130588(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
loc_82181078:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r9,r11,1
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 1);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
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

__attribute__((alias("__imp__sub_821810B0"))) PPC_WEAK_FUNC(sub_821810B0);
PPC_FUNC_IMPL(__imp__sub_821810B0) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82180570
	ctx.lr = 0x821810D4;
	sub_82180570(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x821810fc
	if (cr6.eq) goto loc_821810FC;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
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
loc_821810FC:
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

__attribute__((alias("__imp__sub_82181114"))) PPC_WEAK_FUNC(sub_82181114);
PPC_FUNC_IMPL(__imp__sub_82181114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82181118"))) PPC_WEAK_FUNC(sub_82181118);
PPC_FUNC_IMPL(__imp__sub_82181118) {
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
	// lwz r3,0(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x821378b8
	ctx.lr = 0x8218113C;
	sub_821378B8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// stb r11,5(r31)
	PPC_STORE_U8(r31.u32 + 5, r11.u8);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
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

__attribute__((alias("__imp__sub_82181180"))) PPC_WEAK_FUNC(sub_82181180);
PPC_FUNC_IMPL(__imp__sub_82181180) {
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
	ctx.lr = 0x82181188;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r11,-25080
	ctx.r3.s64 = r11.s64 + -25080;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x82180fd0
	ctx.lr = 0x821811A8;
	sub_82180FD0(ctx, base);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r30.u32);
	// stw r29,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r29.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821811BC"))) PPC_WEAK_FUNC(sub_821811BC);
PPC_FUNC_IMPL(__imp__sub_821811BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821811C0"))) PPC_WEAK_FUNC(sub_821811C0);
PPC_FUNC_IMPL(__imp__sub_821811C0) {
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
	ctx.lr = 0x821811C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r10,r11,-25064
	ctx.r10.s64 = r11.s64 + -25064;
	// stw r28,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r28.u32);
	// li r30,0
	r30.s64 = 0;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_821811E4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82181208
	if (cr6.eq) goto loc_82181208;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821811e4
	if (cr6.eq) goto loc_821811E4;
loc_82181208:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82181220
	if (!cr6.eq) goto loc_82181220;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r31,-25360(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -25360);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82181244
	if (!cr6.eq) goto loc_82181244;
loc_82181220:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// addi r3,r11,-25044
	ctx.r3.s64 = r11.s64 + -25044;
	// bl 0x82180680
	ctx.lr = 0x82181230;
	sub_82180680(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82181258
	if (cr6.eq) goto loc_82181258;
	// lwz r31,0(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82181314
	if (cr6.eq) goto loc_82181314;
loc_82181244:
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce0d8
	ctx.lr = 0x8218124C;
	sub_821CE0D8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82181258:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r29,-24880(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + -24880);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82181320
	if (cr6.eq) goto loc_82181320;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9790
	ctx.lr = 0x82181274;
	sub_821C9790(ctx, base);
loc_82181274:
	// lhz r11,20(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 20);
	// li r8,0
	ctx.r8.s64 = 0;
	// addic. r9,r11,-1
	xer.ca = r11.u32 > 0;
	ctx.r9.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt 0x821812b8
	if (cr0.lt) goto loc_821812B8;
	// lwz r7,16(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 16);
loc_82181288:
	// add r11,r9,r8
	r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// srawi r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r7
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// cmplw cr6,r3,r10
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, xer);
	// beq cr6,0x821812e4
	if (cr6.eq) goto loc_821812E4;
	// bge cr6,0x821812ac
	if (!cr6.lt) goto loc_821812AC;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// b 0x821812b0
	goto loc_821812B0;
loc_821812AC:
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
loc_821812B0:
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// ble cr6,0x82181288
	if (!cr6.gt) goto loc_82181288;
loc_821812B8:
	// li r31,0
	r31.s64 = 0;
loc_821812BC:
	// lwz r29,8(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821812fc
	if (cr6.eq) goto loc_821812FC;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82181274
	if (cr6.eq) goto loc_82181274;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce0d8
	ctx.lr = 0x821812D8;
	sub_821CE0D8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821812E4:
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x821812b8
	if (cr6.eq) goto loc_821812B8;
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r9,r10
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// b 0x821812bc
	goto loc_821812BC;
loc_821812FC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82181244
	if (!cr6.eq) goto loc_82181244;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r11,-25056
	ctx.r3.s64 = r11.s64 + -25056;
	// bl 0x82130000
	ctx.lr = 0x82181314;
	sub_82130000(ctx, base);
loc_82181314:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82181320:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8218132C"))) PPC_WEAK_FUNC(sub_8218132C);
PPC_FUNC_IMPL(__imp__sub_8218132C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82181330"))) PPC_WEAK_FUNC(sub_82181330);
PPC_FUNC_IMPL(__imp__sub_82181330) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r31.u32);
	// addi r4,r1,132
	ctx.r4.s64 = ctx.r1.s64 + 132;
	// addi r3,r11,-25044
	ctx.r3.s64 = r11.s64 + -25044;
	// bl 0x82180680
	ctx.lr = 0x8218135C;
	sub_82180680(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82181390
	if (cr6.eq) goto loc_82181390;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x82181370;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82181388
	if (cr6.eq) goto loc_82181388;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8218fad0
	ctx.lr = 0x82181384;
	sub_8218FAD0(ctx, base);
	// b 0x82181444
	goto loc_82181444;
loc_82181388:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82181444
	goto loc_82181444;
loc_82181390:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r30,-24880(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -24880);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821813d4
	if (cr6.eq) goto loc_821813D4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9790
	ctx.lr = 0x821813AC;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821810b0
	ctx.lr = 0x821813B8;
	sub_821810B0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x821813d4
	if (cr6.eq) goto loc_821813D4;
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce0d8
	ctx.lr = 0x821813CC;
	sub_821CE0D8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// b 0x82181444
	goto loc_82181444;
loc_821813D4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218eda8
	ctx.lr = 0x821813DC;
	sub_8218EDA8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82181418
	if (cr6.eq) goto loc_82181418;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82181408;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217f540
	ctx.lr = 0x82181414;
	sub_8217F540(ctx, base);
	// b 0x82181440
	goto loc_82181440;
loc_82181418:
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x82181420;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218143c
	if (cr6.eq) goto loc_8218143C;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8218fad0
	ctx.lr = 0x82181434;
	sub_8218FAD0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x82181440
	goto loc_82181440;
loc_8218143C:
	// li r31,0
	r31.s64 = 0;
loc_82181440:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82181444:
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

__attribute__((alias("__imp__sub_8218145C"))) PPC_WEAK_FUNC(sub_8218145C);
PPC_FUNC_IMPL(__imp__sub_8218145C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82181460"))) PPC_WEAK_FUNC(sub_82181460);
PPC_FUNC_IMPL(__imp__sub_82181460) {
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
	ctx.lr = 0x82181468;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821814e0
	if (cr6.eq) goto loc_821814E0;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821c95a0
	ctx.lr = 0x82181488;
	sub_821C95A0(ctx, base);
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// divwu r9,r3,r10
	ctx.r9.u32 = ctx.r3.u32 / ctx.r10.u32;
	// twllei r10,0
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r10,r11
	r31.u64 = ctx.r10.u64 + r11.u64;
	// lwzx r6,r10,r11
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x821814e0
	if (cr6.eq) goto loc_821814E0;
loc_821814B4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823db730
	ctx.lr = 0x821814C4;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821814ec
	if (cr6.eq) goto loc_821814EC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r31,r11,8
	r31.s64 = r11.s64 + 8;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821814b4
	if (!cr6.eq) goto loc_821814B4;
loc_821814E0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821814EC:
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// beq cr6,0x82181510
	if (cr6.eq) goto loc_82181510;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x82181508;
	sub_821D2AA0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82181510;
	sub_82130588(ctx, base);
loc_82181510:
	// lhz r11,6(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 6);
	// li r3,1
	ctx.r3.s64 = 1;
	// addis r10,r11,1
	ctx.r10.s64 = r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sth r10,6(r29)
	PPC_STORE_U16(r29.u32 + 6, ctx.r10.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8218152C"))) PPC_WEAK_FUNC(sub_8218152C);
PPC_FUNC_IMPL(__imp__sub_8218152C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82181530"))) PPC_WEAK_FUNC(sub_82181530);
PPC_FUNC_IMPL(__imp__sub_82181530) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r11,-25044
	ctx.r3.s64 = r11.s64 + -25044;
	// bl 0x82181460
	ctx.lr = 0x82181550;
	sub_82181460(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82181560"))) PPC_WEAK_FUNC(sub_82181560);
PPC_FUNC_IMPL(__imp__sub_82181560) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
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
	ctx.lr = 0x82181568;
	// stfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f30.u64);
	// stfd f31,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,-1
	r11.s64 = -1;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r31,r29,24
	r31.s64 = r29.s64 + 24;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r4,r31,48
	ctx.r4.s64 = r31.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r5,12(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// mr r23,r8
	r23.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// bl 0x82189ce0
	ctx.lr = 0x821815B0;
	sub_82189CE0(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821815C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// sraw r11,r3,r26
	temp.u32 = r26.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r3.s32 < 0) & (((ctx.r3.s32 >> temp.u32) << temp.u32) != ctx.r3.s32);
	r11.s64 = ctx.r3.s32 >> temp.u32;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// mr r28,r11
	r28.u64 = r11.u64;
	// bgt cr6,0x821815d8
	if (cr6.gt) goto loc_821815D8;
	// li r28,1
	r28.s64 = 1;
loc_821815D8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821815EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// sraw r11,r3,r26
	temp.u32 = r26.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r3.s32 < 0) & (((ctx.r3.s32 >> temp.u32) << temp.u32) != ctx.r3.s32);
	r11.s64 = ctx.r3.s32 >> temp.u32;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bgt cr6,0x821815fc
	if (cr6.gt) goto loc_821815FC;
	// li r11,1
	r11.s64 = 1;
loc_821815FC:
	// clrldi r10,r28,32
	ctx.r10.u64 = r28.u64 & 0xFFFFFFFF;
	// lwz r5,16(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// clrldi r9,r11,32
	ctx.r9.u64 = r11.u64 & 0xFFFFFFFF;
	// std r10,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r10.u64);
	// lfd f0,104(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// std r9,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r9.u64);
	// lfd f13,104(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// frsp f31,f11
	f31.f64 = double(float(ctx.f11.f64));
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r4,r31,48
	ctx.r4.s64 = r31.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// frsp f30,f12
	f30.f64 = double(float(ctx.f12.f64));
	// stfs f30,124(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// fdivs f9,f0,f31
	ctx.f9.f64 = double(float(f0.f64 / f31.f64));
	// stfs f9,112(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fdivs f10,f0,f30
	ctx.f10.f64 = double(float(f0.f64 / f30.f64));
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// bl 0x8218a6e0
	ctx.lr = 0x82181664;
	sub_8218A6E0(ctx, base);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x82181688
	if (!cr6.gt) goto loc_82181688;
	// addi r30,r26,-1
	r30.s64 = r26.s64 + -1;
	// li r3,11
	ctx.r3.s64 = 11;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82189e38
	ctx.lr = 0x8218167C;
	sub_82189E38(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82189e38
	ctx.lr = 0x82181688;
	sub_82189E38(ctx, base);
loc_82181688:
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r27,3
	cr6.compare<uint32_t>(r27.u32, 3, xer);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// bgt cr6,0x82181970
	if (cr6.gt) goto loc_82181970;
	// lis r12,-32232
	r12.s64 = -2112356352;
	// addi r12,r12,5808
	r12.s64 = r12.s64 + 5808;
	// rlwinm r0,r27,2,0,29
	r0.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r27.u64) {
	case 0:
		goto loc_821816C0;
	case 1:
		goto loc_8218176C;
	case 2:
		goto loc_82181818;
	case 3:
		goto loc_821818C4;
	default:
		__builtin_unreachable();
	}
	// lwz r16,5824(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 5824);
	// lwz r16,5996(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 5996);
	// lwz r16,6168(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 6168);
	// lwz r16,6340(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 6340);
loc_821816C0:
	// li r11,16
	r11.s64 = 16;
	// li r3,16
	ctx.r3.s64 = 16;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// bl 0x8217fed0
	ctx.lr = 0x821816D0;
	sub_8217FED0(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r4,15
	ctx.r4.s64 = 15;
	// ld r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// li r3,16
	ctx.r3.s64 = 16;
	// std r10,132(r1)
	PPC_STORE_U64(ctx.r1.u32 + 132, ctx.r10.u64);
	// bl 0x8217f768
	ctx.lr = 0x821816E8;
	sub_8217F768(ctx, base);
	// li r9,17
	ctx.r9.s64 = 17;
	// li r3,17
	ctx.r3.s64 = 17;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// bl 0x8217fed0
	ctx.lr = 0x821816F8;
	sub_8217FED0(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r8,104(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// li r3,17
	ctx.r3.s64 = 17;
	// std r8,140(r1)
	PPC_STORE_U64(ctx.r1.u32 + 140, ctx.r8.u64);
	// bl 0x8217f768
	ctx.lr = 0x82181710;
	sub_8217F768(ctx, base);
	// li r7,18
	ctx.r7.s64 = 18;
	// li r3,18
	ctx.r3.s64 = 18;
	// stw r7,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r7.u32);
	// bl 0x8217fed0
	ctx.lr = 0x82181720;
	sub_8217FED0(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r6,104(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// li r3,18
	ctx.r3.s64 = 18;
	// std r6,148(r1)
	PPC_STORE_U64(ctx.r1.u32 + 148, ctx.r6.u64);
	// bl 0x8217f768
	ctx.lr = 0x82181738;
	sub_8217F768(ctx, base);
	// li r5,19
	ctx.r5.s64 = 19;
	// li r3,19
	ctx.r3.s64 = 19;
	// stw r5,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r5.u32);
	// bl 0x8217fed0
	ctx.lr = 0x82181748;
	sub_8217FED0(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r11,4
	r11.s64 = 4;
	// ld r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// li r4,0
	ctx.r4.s64 = 0;
	// std r10,156(r1)
	PPC_STORE_U64(ctx.r1.u32 + 156, ctx.r10.u64);
	// li r3,19
	ctx.r3.s64 = 19;
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// bl 0x8217f768
	ctx.lr = 0x82181768;
	sub_8217F768(ctx, base);
	// b 0x8218197c
	goto loc_8218197C;
loc_8218176C:
	// li r11,17
	r11.s64 = 17;
	// li r3,17
	ctx.r3.s64 = 17;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// bl 0x8217fed0
	ctx.lr = 0x8218177C;
	sub_8217FED0(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r4,15
	ctx.r4.s64 = 15;
	// ld r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// li r3,17
	ctx.r3.s64 = 17;
	// std r10,132(r1)
	PPC_STORE_U64(ctx.r1.u32 + 132, ctx.r10.u64);
	// bl 0x8217f768
	ctx.lr = 0x82181794;
	sub_8217F768(ctx, base);
	// li r9,16
	ctx.r9.s64 = 16;
	// li r3,16
	ctx.r3.s64 = 16;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// bl 0x8217fed0
	ctx.lr = 0x821817A4;
	sub_8217FED0(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r8,104(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// li r3,16
	ctx.r3.s64 = 16;
	// std r8,140(r1)
	PPC_STORE_U64(ctx.r1.u32 + 140, ctx.r8.u64);
	// bl 0x8217f768
	ctx.lr = 0x821817BC;
	sub_8217F768(ctx, base);
	// li r7,18
	ctx.r7.s64 = 18;
	// li r3,18
	ctx.r3.s64 = 18;
	// stw r7,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r7.u32);
	// bl 0x8217fed0
	ctx.lr = 0x821817CC;
	sub_8217FED0(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r6,104(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// li r3,18
	ctx.r3.s64 = 18;
	// std r6,148(r1)
	PPC_STORE_U64(ctx.r1.u32 + 148, ctx.r6.u64);
	// bl 0x8217f768
	ctx.lr = 0x821817E4;
	sub_8217F768(ctx, base);
	// li r5,19
	ctx.r5.s64 = 19;
	// li r3,19
	ctx.r3.s64 = 19;
	// stw r5,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r5.u32);
	// bl 0x8217fed0
	ctx.lr = 0x821817F4;
	sub_8217FED0(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r11,4
	r11.s64 = 4;
	// ld r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// li r4,0
	ctx.r4.s64 = 0;
	// std r10,156(r1)
	PPC_STORE_U64(ctx.r1.u32 + 156, ctx.r10.u64);
	// li r3,19
	ctx.r3.s64 = 19;
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// bl 0x8217f768
	ctx.lr = 0x82181814;
	sub_8217F768(ctx, base);
	// b 0x8218197c
	goto loc_8218197C;
loc_82181818:
	// li r11,18
	r11.s64 = 18;
	// li r3,18
	ctx.r3.s64 = 18;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// bl 0x8217fed0
	ctx.lr = 0x82181828;
	sub_8217FED0(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r4,15
	ctx.r4.s64 = 15;
	// li r3,18
	ctx.r3.s64 = 18;
	// ld r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// std r10,132(r1)
	PPC_STORE_U64(ctx.r1.u32 + 132, ctx.r10.u64);
	// bl 0x8217f768
	ctx.lr = 0x82181840;
	sub_8217F768(ctx, base);
	// li r9,16
	ctx.r9.s64 = 16;
	// li r3,16
	ctx.r3.s64 = 16;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// bl 0x8217fed0
	ctx.lr = 0x82181850;
	sub_8217FED0(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r8,104(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// li r3,16
	ctx.r3.s64 = 16;
	// std r8,140(r1)
	PPC_STORE_U64(ctx.r1.u32 + 140, ctx.r8.u64);
	// bl 0x8217f768
	ctx.lr = 0x82181868;
	sub_8217F768(ctx, base);
	// li r7,17
	ctx.r7.s64 = 17;
	// li r3,17
	ctx.r3.s64 = 17;
	// stw r7,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r7.u32);
	// bl 0x8217fed0
	ctx.lr = 0x82181878;
	sub_8217FED0(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r6,104(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// li r3,17
	ctx.r3.s64 = 17;
	// std r6,148(r1)
	PPC_STORE_U64(ctx.r1.u32 + 148, ctx.r6.u64);
	// bl 0x8217f768
	ctx.lr = 0x82181890;
	sub_8217F768(ctx, base);
	// li r5,19
	ctx.r5.s64 = 19;
	// li r3,19
	ctx.r3.s64 = 19;
	// stw r5,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r5.u32);
	// bl 0x8217fed0
	ctx.lr = 0x821818A0;
	sub_8217FED0(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r11,4
	r11.s64 = 4;
	// ld r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// li r4,0
	ctx.r4.s64 = 0;
	// std r10,156(r1)
	PPC_STORE_U64(ctx.r1.u32 + 156, ctx.r10.u64);
	// li r3,19
	ctx.r3.s64 = 19;
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// bl 0x8217f768
	ctx.lr = 0x821818C0;
	sub_8217F768(ctx, base);
	// b 0x8218197c
	goto loc_8218197C;
loc_821818C4:
	// li r11,19
	r11.s64 = 19;
	// li r3,19
	ctx.r3.s64 = 19;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// bl 0x8217fed0
	ctx.lr = 0x821818D4;
	sub_8217FED0(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r4,15
	ctx.r4.s64 = 15;
	// ld r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// li r3,19
	ctx.r3.s64 = 19;
	// std r10,132(r1)
	PPC_STORE_U64(ctx.r1.u32 + 132, ctx.r10.u64);
	// bl 0x8217f768
	ctx.lr = 0x821818EC;
	sub_8217F768(ctx, base);
	// li r9,16
	ctx.r9.s64 = 16;
	// li r3,16
	ctx.r3.s64 = 16;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// bl 0x8217fed0
	ctx.lr = 0x821818FC;
	sub_8217FED0(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r8,104(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// li r3,16
	ctx.r3.s64 = 16;
	// std r8,140(r1)
	PPC_STORE_U64(ctx.r1.u32 + 140, ctx.r8.u64);
	// bl 0x8217f768
	ctx.lr = 0x82181914;
	sub_8217F768(ctx, base);
	// li r7,17
	ctx.r7.s64 = 17;
	// li r3,17
	ctx.r3.s64 = 17;
	// stw r7,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r7.u32);
	// bl 0x8217fed0
	ctx.lr = 0x82181924;
	sub_8217FED0(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r6,104(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// li r3,17
	ctx.r3.s64 = 17;
	// std r6,148(r1)
	PPC_STORE_U64(ctx.r1.u32 + 148, ctx.r6.u64);
	// bl 0x8217f768
	ctx.lr = 0x8218193C;
	sub_8217F768(ctx, base);
	// li r5,18
	ctx.r5.s64 = 18;
	// li r3,18
	ctx.r3.s64 = 18;
	// stw r5,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r5.u32);
	// bl 0x8217fed0
	ctx.lr = 0x8218194C;
	sub_8217FED0(ctx, base);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r11,4
	r11.s64 = 4;
	// ld r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// li r4,0
	ctx.r4.s64 = 0;
	// std r10,156(r1)
	PPC_STORE_U64(ctx.r1.u32 + 156, ctx.r10.u64);
	// li r3,18
	ctx.r3.s64 = 18;
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// bl 0x8217f768
	ctx.lr = 0x8218196C;
	sub_8217F768(ctx, base);
	// b 0x8218197c
	goto loc_8218197C;
loc_82181970:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-24992
	ctx.r3.s64 = r11.s64 + -24992;
	// bl 0x821bd618
	ctx.lr = 0x8218197C;
	sub_821BD618(ctx, base);
loc_8218197C:
	// lis r30,-32124
	r30.s64 = -2105278464;
	// cmpwi cr6,r25,2
	cr6.compare<int32_t>(r25.s32, 2, xer);
	// beq cr6,0x82181998
	if (cr6.eq) goto loc_82181998;
	// cmpwi cr6,r25,5
	cr6.compare<int32_t>(r25.s32, 5, xer);
	// beq cr6,0x82181998
	if (cr6.eq) goto loc_82181998;
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// b 0x8218199c
	goto loc_8218199C;
loc_82181998:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
loc_8218199C:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,-21076(r11)
	PPC_STORE_U32(r11.u32 + -21076, ctx.r10.u32);
	// beq cr6,0x82181a38
	if (cr6.eq) goto loc_82181A38;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// li r11,0
	r11.s64 = 0;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// stb r11,-21095(r9)
	PPC_STORE_U8(ctx.r9.u32 + -21095, r11.u8);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// stw r11,-21088(r30)
	PPC_STORE_U32(r30.u32 + -21088, r11.u32);
	// lhz r11,12(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82181a38
	if (!cr6.gt) goto loc_82181A38;
	// addi r5,r31,48
	ctx.r5.s64 = r31.s64 + 48;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218bb08
	ctx.lr = 0x821819E8;
	sub_8218BB08(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f7,4(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f6,0(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f13,0(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f8,f6,f13
	ctx.f8.f64 = double(float(ctx.f6.f64 + ctx.f13.f64));
	// lfs f0,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// fsubs f4,f30,f0
	ctx.f4.f64 = double(float(f30.f64 - f0.f64));
	// lfs f2,31492(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31492);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f3,f31,f0
	ctx.f3.f64 = double(float(f31.f64 - f0.f64));
	// lfs f5,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// lfs f0,4(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 4);
	f0.f64 = double(temp.f32);
	// fadds f9,f0,f7
	ctx.f9.f64 = double(float(f0.f64 + ctx.f7.f64));
	// bl 0x8217a2e0
	ctx.lr = 0x82181A30;
	sub_8217A2E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218ad48
	ctx.lr = 0x82181A38;
	sub_8218AD48(ctx, base);
loc_82181A38:
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// stw r11,-21088(r30)
	PPC_STORE_U32(r30.u32 + -21088, r11.u32);
	// addi r4,r31,48
	ctx.r4.s64 = r31.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,12(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwz r6,-25360(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -25360);
	// bl 0x82189ce0
	ctx.lr = 0x82181A58;
	sub_82189CE0(ctx, base);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x82181a70
	if (!cr6.gt) goto loc_82181A70;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x82189e60
	ctx.lr = 0x82181A68;
	sub_82189E60(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82189e60
	ctx.lr = 0x82181A70;
	sub_82189E60(ctx, base);
loc_82181A70:
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82491668
	ctx.lr = 0x82181A78;
	sub_82491668(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f30,-96(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82181A88"))) PPC_WEAK_FUNC(sub_82181A88);
PPC_FUNC_IMPL(__imp__sub_82181A88) {
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
	ctx.lr = 0x82181A90;
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
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82181af4
	if (cr6.eq) goto loc_82181AF4;
	// mr r29,r27
	r29.u64 = r27.u64;
loc_82181AB0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r31,r29,r11
	r31.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82181ae0
	if (cr6.eq) goto loc_82181AE0;
loc_82181AC0:
	// mr r26,r31
	r26.u64 = r31.u64;
	// lwz r31,20(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x82181AD0;
	sub_821D2AA0(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82130588
	ctx.lr = 0x82181AD8;
	sub_82130588(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82181ac0
	if (!cr6.eq) goto loc_82181AC0;
loc_82181AE0:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x82181ab0
	if (cr6.lt) goto loc_82181AB0;
loc_82181AF4:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82181AFC;
	sub_82130588(ctx, base);
	// stw r27,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r27.u32);
	// sth r27,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r27.u16);
	// sth r27,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r27.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82181B10"))) PPC_WEAK_FUNC(sub_82181B10);
PPC_FUNC_IMPL(__imp__sub_82181B10) {
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
	ctx.lr = 0x82181B18;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82181b3c
	if (!cr6.eq) goto loc_82181B3C;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82608a98
	ctx.lr = 0x82181B3C;
	sub_82608A98(ctx, base);
loc_82181B3C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9550
	ctx.lr = 0x82181B44;
	sub_821C9550(ctx, base);
	// lhz r6,4(r29)
	ctx.r6.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// divwu r10,r3,r7
	ctx.r10.u32 = ctx.r3.u32 / ctx.r7.u32;
	// twllei r7,0
	// mullw r9,r10,r7
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// subf r30,r9,r3
	r30.s64 = ctx.r3.s64 - ctx.r9.s64;
	// rlwinm r8,r30,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r8,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82181bb0
	if (cr6.eq) goto loc_82181BB0;
loc_82181B70:
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mr r11,r31
	r11.u64 = r31.u64;
loc_82181B78:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r5,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r5.s64;
	// beq cr6,0x82181b9c
	if (cr6.eq) goto loc_82181B9C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82181b78
	if (cr6.eq) goto loc_82181B78;
loc_82181B9C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82181c34
	if (cr6.eq) goto loc_82181C34;
	// lwz r8,20(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82181b70
	if (!cr6.eq) goto loc_82181B70;
loc_82181BB0:
	// lhz r11,6(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 6);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// sth r10,6(r29)
	PPC_STORE_U16(r29.u32 + 6, ctx.r10.u16);
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// bne cr6,0x82181bf8
	if (!cr6.eq) goto loc_82181BF8;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x821c9438
	ctx.lr = 0x82181BD0;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82180800
	ctx.lr = 0x82181BDC;
	sub_82180800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9550
	ctx.lr = 0x82181BE4;
	sub_821C9550(ctx, base);
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// divwu r10,r3,r11
	ctx.r10.u32 = ctx.r3.u32 / r11.u32;
	// twllei r11,0
	// mullw r9,r10,r11
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// subf r30,r9,r3
	r30.s64 = ctx.r3.s64 - ctx.r9.s64;
loc_82181BF8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821378b8
	ctx.lr = 0x82181C00;
	sub_821378B8(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r31,r30,2,0,29
	r31.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// li r3,24
	ctx.r3.s64 = 24;
	// lwzx r30,r31,r11
	r30.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x82130528
	ctx.lr = 0x82181C18;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82181c40
	if (cr6.eq) goto loc_82181C40;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82181118
	ctx.lr = 0x82181C2C;
	sub_82181118(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82181c44
	goto loc_82181C44;
loc_82181C34:
	// addi r3,r8,4
	ctx.r3.s64 = ctx.r8.s64 + 4;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82181C40:
	// li r11,0
	r11.s64 = 0;
loc_82181C44:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stwx r11,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r11.u32);
	// bl 0x821d2aa0
	ctx.lr = 0x82181C54;
	sub_821D2AA0(ctx, base);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r11,r31,r9
	r11.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82181C68"))) PPC_WEAK_FUNC(sub_82181C68);
PPC_FUNC_IMPL(__imp__sub_82181C68) {
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
	ctx.lr = 0x82181C70;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82181c98
	if (!cr6.eq) goto loc_82181C98;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x82608a98
	ctx.lr = 0x82181C98;
	sub_82608A98(ctx, base);
loc_82181C98:
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
	// bne cr6,0x82181cc8
	if (!cr6.eq) goto loc_82181CC8;
	// bl 0x821c9438
	ctx.lr = 0x82181CBC;
	sub_821C9438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82180720
	ctx.lr = 0x82181CC8;
	sub_82180720(ctx, base);
loc_82181CC8:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x821c95a0
	ctx.lr = 0x82181CD0;
	sub_821C95A0(ctx, base);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// divwu r9,r10,r11
	ctx.r9.u32 = ctx.r10.u32 / r11.u32;
	// twllei r11,0
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// subf r30,r8,r10
	r30.s64 = ctx.r10.s64 - ctx.r8.s64;
	// bl 0x821378b8
	ctx.lr = 0x82181CF0;
	sub_821378B8(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// rlwinm r29,r30,2,0,29
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r3,12
	ctx.r3.s64 = 12;
	// lwzx r28,r29,r7
	r28.u64 = PPC_LOAD_U32(r29.u32 + ctx.r7.u32);
	// bl 0x82130528
	ctx.lr = 0x82181D08;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82181d34
	if (cr6.eq) goto loc_82181D34;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x821378b8
	ctx.lr = 0x82181D1C;
	sub_821378B8(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// mr r11,r30
	r11.u64 = r30.u64;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// stw r28,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r28.u32);
	// b 0x82181d38
	goto loc_82181D38;
loc_82181D34:
	// li r11,0
	r11.s64 = 0;
loc_82181D38:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stwx r11,r29,r10
	PPC_STORE_U32(r29.u32 + ctx.r10.u32, r11.u32);
	// bl 0x821d2aa0
	ctx.lr = 0x82181D48;
	sub_821D2AA0(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r3,r29,r9
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + ctx.r9.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82181D58"))) PPC_WEAK_FUNC(sub_82181D58);
PPC_FUNC_IMPL(__imp__sub_82181D58) {
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
	ctx.lr = 0x82181D60;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x821803a8
	ctx.lr = 0x82181D68;
	sub_821803A8(ctx, base);
	// lis r29,-32124
	r29.s64 = -2105278464;
	// lwz r31,-25360(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -25360);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x82181D78;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82181da0
	if (!cr6.eq) goto loc_82181DA0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82181da0
	if (cr6.eq) goto loc_82181DA0;
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
	ctx.lr = 0x82181DA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82181DA0:
	// li r11,0
	r11.s64 = 0;
	// lis r30,-32124
	r30.s64 = -2105278464;
	// stw r11,-25360(r29)
	PPC_STORE_U32(r29.u32 + -25360, r11.u32);
	// lwz r31,-25356(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -25356);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x82181DB8;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82181de0
	if (!cr6.eq) goto loc_82181DE0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82181de0
	if (cr6.eq) goto loc_82181DE0;
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
	ctx.lr = 0x82181DE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82181DE0:
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// stw r11,-25356(r30)
	PPC_STORE_U32(r30.u32 + -25356, r11.u32);
	// addi r3,r10,-25044
	ctx.r3.s64 = ctx.r10.s64 + -25044;
	// bl 0x8229d838
	ctx.lr = 0x82181DF4;
	sub_8229D838(ctx, base);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// lwz r31,-25240(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25240);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x82181E04;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82181e2c
	if (!cr6.eq) goto loc_82181E2C;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82181e2c
	if (cr6.eq) goto loc_82181E2C;
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
	ctx.lr = 0x82181E2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82181E2C:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r31,-25236(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -25236);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82181e6c
	if (cr6.eq) goto loc_82181E6C;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x82181E44;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82181e6c
	if (!cr6.eq) goto loc_82181E6C;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82181e6c
	if (cr6.eq) goto loc_82181E6C;
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
	ctx.lr = 0x82181E6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82181E6C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82181E74"))) PPC_WEAK_FUNC(sub_82181E74);
PPC_FUNC_IMPL(__imp__sub_82181E74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82181E78"))) PPC_WEAK_FUNC(sub_82181E78);
PPC_FUNC_IMPL(__imp__sub_82181E78) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82181E80;
	// stwu r1,-1040(r1)
	ea = -1040 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r5,r11,-24872
	ctx.r5.s64 = r11.s64 + -24872;
	// addi r3,r10,30576
	ctx.r3.s64 = ctx.r10.s64 + 30576;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// bl 0x821ca6a8
	ctx.lr = 0x82181EA4;
	sub_821CA6A8(ctx, base);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x82182114
	if (cr6.eq) goto loc_82182114;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821d1ce8
	ctx.lr = 0x82181EC0;
	sub_821D1CE8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// stb r11,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r11.u8);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x821bbea8
	ctx.lr = 0x82181EE4;
	sub_821BBEA8(ctx, base);
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,688
	ctx.r4.s64 = ctx.r1.s64 + 688;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821cfaa8
	ctx.lr = 0x82181EF4;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821820fc
	if (cr6.eq) goto loc_821820FC;
	// lis r7,-32124
	ctx.r7.s64 = -2105278464;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r24,r7,-24892
	r24.s64 = ctx.r7.s64 + -24892;
	// addi r30,r6,-24916
	r30.s64 = ctx.r6.s64 + -24916;
	// addi r29,r5,-24932
	r29.s64 = ctx.r5.s64 + -24932;
	// addi r28,r4,-24944
	r28.s64 = ctx.r4.s64 + -24944;
	// addi r27,r3,-24956
	r27.s64 = ctx.r3.s64 + -24956;
	// addi r26,r8,-24964
	r26.s64 = ctx.r8.s64 + -24964;
	// addi r25,r9,-24972
	r25.s64 = ctx.r9.s64 + -24972;
	// addi r31,r10,-29628
	r31.s64 = ctx.r10.s64 + -29628;
	// addi r23,r11,-29624
	r23.s64 = r11.s64 + -29624;
loc_82181F44:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821d0898
	ctx.lr = 0x82181F50;
	sub_821D0898(ctx, base);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821cfaa8
	ctx.lr = 0x82181F60;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821820b0
	if (cr6.eq) goto loc_821820B0;
loc_82181F68:
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
loc_82181F70:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82181f94
	if (cr6.eq) goto loc_82181F94;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82181f70
	if (cr6.eq) goto loc_82181F70;
loc_82181F94:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821820b0
	if (cr6.eq) goto loc_821820B0;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823db730
	ctx.lr = 0x82181FA8;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82181fd0
	if (!cr6.eq) goto loc_82181FD0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821d0490
	ctx.lr = 0x82181FBC;
	sub_821D0490(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// stb r9,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r9.u8);
	// b 0x82182098
	goto loc_82182098;
loc_82181FD0:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823db730
	ctx.lr = 0x82181FDC;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82182004
	if (!cr6.eq) goto loc_82182004;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821d0490
	ctx.lr = 0x82181FF0;
	sub_821D0490(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// stb r9,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r9.u8);
	// b 0x82182098
	goto loc_82182098;
loc_82182004:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823db730
	ctx.lr = 0x82182010;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8218202c
	if (!cr6.eq) goto loc_8218202C;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821d0528
	ctx.lr = 0x82182024;
	sub_821D0528(ctx, base);
	// stfs f1,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// b 0x82182098
	goto loc_82182098;
loc_8218202C:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823db730
	ctx.lr = 0x82182038;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82182054
	if (!cr6.eq) goto loc_82182054;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821d0528
	ctx.lr = 0x8218204C;
	sub_821D0528(ctx, base);
	// stfs f1,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// b 0x82182098
	goto loc_82182098;
loc_82182054:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823db730
	ctx.lr = 0x82182060;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8218207c
	if (!cr6.eq) goto loc_8218207C;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821d0490
	ctx.lr = 0x82182074;
	sub_821D0490(ctx, base);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// b 0x82182098
	goto loc_82182098;
loc_8218207C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,136(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x82130000
	ctx.lr = 0x82182090;
	sub_82130000(ctx, base);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821d0170
	ctx.lr = 0x82182098;
	sub_821D0170(ctx, base);
loc_82182098:
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821cfaa8
	ctx.lr = 0x821820A8;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82181f68
	if (!cr6.eq) goto loc_82181F68;
loc_821820B0:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r4,r1,688
	ctx.r4.s64 = ctx.r1.s64 + 688;
	// bl 0x82181b10
	ctx.lr = 0x821820BC;
	sub_82181B10(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,688
	ctx.r4.s64 = ctx.r1.s64 + 688;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// stw r7,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
	// stw r6,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r6.u32);
	// bl 0x821cfaa8
	ctx.lr = 0x821820F4;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82181f44
	if (!cr6.eq) goto loc_82181F44;
loc_821820FC:
	// bl 0x821bbf00
	ctx.lr = 0x82182100;
	sub_821BBF00(ctx, base);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x821be610
	ctx.lr = 0x82182108;
	sub_821BE610(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,1040
	ctx.r1.s64 = ctx.r1.s64 + 1040;
	// b 0x823d922c
	return;
loc_82182114:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,1040
	ctx.r1.s64 = ctx.r1.s64 + 1040;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82182120"))) PPC_WEAK_FUNC(sub_82182120);
PPC_FUNC_IMPL(__imp__sub_82182120) {
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
	// bl 0x821bbea8
	ctx.lr = 0x82182130;
	sub_821BBEA8(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r3,r11,-24892
	ctx.r3.s64 = r11.s64 + -24892;
	// bl 0x82181a88
	ctx.lr = 0x8218213C;
	sub_82181A88(ctx, base);
	// bl 0x821bbf00
	ctx.lr = 0x82182140;
	sub_821BBF00(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82182150"))) PPC_WEAK_FUNC(sub_82182150);
PPC_FUNC_IMPL(__imp__sub_82182150) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// stw r5,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r5.u32);
	// addi r5,r1,132
	ctx.r5.s64 = ctx.r1.s64 + 132;
	// addi r3,r11,-25044
	ctx.r3.s64 = r11.s64 + -25044;
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// bl 0x82181c68
	ctx.lr = 0x82182178;
	sub_82181C68(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82182188"))) PPC_WEAK_FUNC(sub_82182188);
PPC_FUNC_IMPL(__imp__sub_82182188) {
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
	ctx.lr = 0x82182190;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-24860
	ctx.r10.s64 = r11.s64 + -24860;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// lhz r31,42(r28)
	r31.u64 = PPC_LOAD_U16(r28.u32 + 42);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821821dc
	if (cr6.eq) goto loc_821821DC;
	// lwz r29,36(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x821821d4
	if (!cr6.gt) goto loc_821821D4;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_821821C0:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x821821C8;
	sub_82130588(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x821821c0
	if (!cr0.eq) goto loc_821821C0;
loc_821821D4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x821821DC;
	sub_82130588(ctx, base);
loc_821821DC:
	// lhz r31,34(r28)
	r31.u64 = PPC_LOAD_U16(r28.u32 + 34);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82182214
	if (cr6.eq) goto loc_82182214;
	// lwz r29,28(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8218220c
	if (!cr6.gt) goto loc_8218220C;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_821821F8:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82182200;
	sub_82130588(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x821821f8
	if (!cr0.eq) goto loc_821821F8;
loc_8218220C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82182214;
	sub_82130588(ctx, base);
loc_82182214:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r10,r11,-25308
	ctx.r10.s64 = r11.s64 + -25308;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// bl 0x821d2810
	ctx.lr = 0x82182228;
	sub_821D2810(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82182230"))) PPC_WEAK_FUNC(sub_82182230);
PPC_FUNC_IMPL(__imp__sub_82182230) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8218223C"))) PPC_WEAK_FUNC(sub_8218223C);
PPC_FUNC_IMPL(__imp__sub_8218223C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182240"))) PPC_WEAK_FUNC(sub_82182240);
PPC_FUNC_IMPL(__imp__sub_82182240) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82182248;
	// stwu r1,-976(r1)
	ea = -976 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// addi r30,r11,-25336
	r30.s64 = r11.s64 + -25336;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_82182268:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8218228c
	if (!cr6.eq) goto loc_8218228C;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r9,r30,96
	ctx.r9.s64 = r30.s64 + 96;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x82182268
	if (cr6.lt) goto loc_82182268;
	// b 0x82182290
	goto loc_82182290;
loc_8218228C:
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
loc_82182290:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r28,r11,30576
	r28.s64 = r11.s64 + 30576;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ca540
	ctx.lr = 0x821822A4;
	sub_821CA540(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r31,r11,-24480
	r31.s64 = r11.s64 + -24480;
	// addi r5,r10,-24488
	ctx.r5.s64 = ctx.r10.s64 + -24488;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x821822C8;
	sub_821CA6A8(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82182400
	if (cr6.eq) goto loc_82182400;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-24528
	ctx.r3.s64 = r11.s64 + -24528;
	// bl 0x82130000
	ctx.lr = 0x821822E4;
	sub_82130000(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// bl 0x821d1ce8
	ctx.lr = 0x821822F4;
	sub_821D1CE8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ca540
	ctx.lr = 0x82182300;
	sub_821CA540(ctx, base);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// bl 0x821cfaa8
	ctx.lr = 0x82182310;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x821823d4
	if (cr6.eq) goto loc_821823D4;
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r29,r10,-25044
	r29.s64 = ctx.r10.s64 + -25044;
	// addi r26,r11,-24588
	r26.s64 = r11.s64 + -24588;
loc_82182330:
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// bl 0x821cfaa8
	ctx.lr = 0x82182340;
	sub_821CFAA8(ctx, base);
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218235C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82182378
	if (!cr6.eq) goto loc_82182378;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x82130000
	ctx.lr = 0x82182374;
	sub_82130000(ctx, base);
	// b 0x821823a8
	goto loc_821823A8;
loc_82182378:
	// addi r11,r1,224
	r11.s64 = ctx.r1.s64 + 224;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bl 0x82181c68
	ctx.lr = 0x8218239C;
	sub_82181C68(ctx, base);
	// addi r10,r30,96
	ctx.r10.s64 = r30.s64 + 96;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// bge cr6,0x821823c4
	if (!cr6.lt) goto loc_821823C4;
loc_821823A8:
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// bl 0x821cfaa8
	ctx.lr = 0x821823B8;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82182330
	if (!cr6.eq) goto loc_82182330;
	// b 0x821823d4
	goto loc_821823D4;
loc_821823C4:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r11,-24656
	ctx.r3.s64 = r11.s64 + -24656;
	// bl 0x82130000
	ctx.lr = 0x821823D4;
	sub_82130000(ctx, base);
loc_821823D4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9a90
	ctx.lr = 0x821823DC;
	sub_821C9A90(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821be610
	ctx.lr = 0x821823E4;
	sub_821BE610(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r10,r11,-30140
	ctx.r10.s64 = r11.s64 + -30140;
	// stw r10,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, ctx.r10.u32);
	// bl 0x821c9a90
	ctx.lr = 0x821823F8;
	sub_821C9A90(ctx, base);
	// addi r1,r1,976
	ctx.r1.s64 = ctx.r1.s64 + 976;
	// b 0x823d9238
	return;
loc_82182400:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-24696
	ctx.r3.s64 = r11.s64 + -24696;
	// bl 0x82130000
	ctx.lr = 0x8218240C;
	sub_82130000(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9a90
	ctx.lr = 0x82182414;
	sub_821C9A90(ctx, base);
	// addi r1,r1,976
	ctx.r1.s64 = ctx.r1.s64 + 976;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8218241C"))) PPC_WEAK_FUNC(sub_8218241C);
PPC_FUNC_IMPL(__imp__sub_8218241C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182420"))) PPC_WEAK_FUNC(sub_82182420);
PPC_FUNC_IMPL(__imp__sub_82182420) {
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
	// bl 0x82182188
	ctx.lr = 0x82182440;
	sub_82182188(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82182458
	if (cr6.eq) goto loc_82182458;
	// bl 0x82130588
	ctx.lr = 0x82182454;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82182458:
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

__attribute__((alias("__imp__sub_82182470"))) PPC_WEAK_FUNC(sub_82182470);
PPC_FUNC_IMPL(__imp__sub_82182470) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// addi r9,r11,-23628
	ctx.r9.s64 = r11.s64 + -23628;
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// lwz r3,-27812(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27812);
	// bl 0x824221d8
	ctx.lr = 0x821824A0;
	sub_824221D8(ctx, base);
	// lwz r31,60(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x821824AC;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x821824d4
	if (!cr6.eq) goto loc_821824D4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821824d4
	if (cr6.eq) goto loc_821824D4;
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
	ctx.lr = 0x821824D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821824D4:
	// lwz r31,64(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 64);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x821824E0;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82182508
	if (!cr6.eq) goto loc_82182508;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82182508
	if (cr6.eq) goto loc_82182508;
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
	ctx.lr = 0x82182508;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82182508:
	// lwz r31,72(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x82182514;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8218253c
	if (!cr6.eq) goto loc_8218253C;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8218253c
	if (cr6.eq) goto loc_8218253C;
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
	ctx.lr = 0x8218253C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8218253C:
	// lwz r31,68(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x82182548;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82182570
	if (!cr6.eq) goto loc_82182570;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82182570
	if (cr6.eq) goto loc_82182570;
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
	ctx.lr = 0x82182570;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82182570:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82180370
	ctx.lr = 0x82182578;
	sub_82180370(ctx, base);
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

__attribute__((alias("__imp__sub_82182590"))) PPC_WEAK_FUNC(sub_82182590);
PPC_FUNC_IMPL(__imp__sub_82182590) {
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
	ctx.lr = 0x82182598;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r26,0
	r26.s64 = 0;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// bne cr6,0x82182660
	if (!cr6.eq) goto loc_82182660;
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82182660
	if (cr6.eq) goto loc_82182660;
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82182660
	if (cr6.eq) goto loc_82182660;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x821825e4
	if (cr6.eq) goto loc_821825E4;
	// lbz r11,23(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 23);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82182660
	if (cr6.eq) goto loc_82182660;
loc_821825E4:
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821825f8
	if (!cr6.eq) goto loc_821825F8;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
loc_821825F8:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82182610;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82182624;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// ble cr6,0x82182660
	if (!cr6.gt) goto loc_82182660;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82182640
	if (cr6.eq) goto loc_82182640;
	// lbz r11,24(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82182660
	if (cr6.eq) goto loc_82182660;
loc_82182640:
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82182660;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82182660:
	// addi r11,r27,6
	r11.s64 = r27.s64 + 6;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r10,r30
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82182778
	if (cr6.eq) goto loc_82182778;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82182708
	if (cr6.eq) goto loc_82182708;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r11,r29
	r11.u64 = r29.u64;
	// li r9,7
	ctx.r9.s64 = 7;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8218268C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8218268c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8218268C;
	// lwz r11,56(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821826b0
	if (!cr6.eq) goto loc_821826B0;
	// stb r26,101(r1)
	PPC_STORE_U8(ctx.r1.u32 + 101, r26.u8);
loc_821826B0:
	// lbz r11,23(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 23);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821826dc
	if (cr6.eq) goto loc_821826DC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821826DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821826DC:
	// lbz r11,22(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82182728
	if (cr6.eq) goto loc_82182728;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82182704;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82182728
	goto loc_82182728;
loc_82182708:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82182728;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82182728:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218273C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// ble cr6,0x82182778
	if (!cr6.gt) goto loc_82182778;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82182758
	if (cr6.eq) goto loc_82182758;
	// lbz r11,24(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82182778
	if (cr6.eq) goto loc_82182778;
loc_82182758:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82182778;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82182778:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// bne cr6,0x821827b8
	if (!cr6.eq) goto loc_821827B8;
	// lbz r11,4(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218279c
	if (cr6.eq) goto loc_8218279C;
	// lwz r3,40(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// bl 0x82177e48
	ctx.lr = 0x82182794;
	sub_82177E48(ctx, base);
	// lwz r3,40(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// bl 0x824221d8
	ctx.lr = 0x8218279C;
	sub_824221D8(ctx, base);
loc_8218279C:
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lwz r10,44(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// stw r26,40(r30)
	PPC_STORE_U32(r30.u32 + 40, r26.u32);
	// stw r10,17004(r9)
	PPC_STORE_U32(ctx.r9.u32 + 17004, ctx.r10.u32);
	// stw r11,17008(r8)
	PPC_STORE_U32(ctx.r8.u32 + 17008, r11.u32);
loc_821827B8:
	// addi r11,r27,2
	r11.s64 = r27.s64 + 2;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// rlwinm r31,r11,2,0,29
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r31,r30
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// bl 0x82178330
	ctx.lr = 0x821827CC;
	sub_82178330(ctx, base);
	// lwzx r3,r31,r30
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821827dc
	if (cr6.eq) goto loc_821827DC;
	// bl 0x824221d8
	ctx.lr = 0x821827DC;
	sub_824221D8(ctx, base);
loc_821827DC:
	// stwx r26,r31,r30
	PPC_STORE_U32(r31.u32 + r30.u32, r26.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821827E8"))) PPC_WEAK_FUNC(sub_821827E8);
PPC_FUNC_IMPL(__imp__sub_821827E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r11,-27788(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27788);
	// addi r10,r11,17
	ctx.r10.s64 = r11.s64 + 17;
	// bne cr6,0x82182804
	if (!cr6.eq) goto loc_82182804;
	// subfic r10,r11,18
	xer.ca = r11.u32 <= 18;
	ctx.r10.s64 = 18 - r11.s64;
loc_82182804:
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82182810"))) PPC_WEAK_FUNC(sub_82182810);
PPC_FUNC_IMPL(__imp__sub_82182810) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82182820"))) PPC_WEAK_FUNC(sub_82182820);
PPC_FUNC_IMPL(__imp__sub_82182820) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82182830"))) PPC_WEAK_FUNC(sub_82182830);
PPC_FUNC_IMPL(__imp__sub_82182830) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82182840"))) PPC_WEAK_FUNC(sub_82182840);
PPC_FUNC_IMPL(__imp__sub_82182840) {
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
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// beq cr6,0x82182884
	if (cr6.eq) goto loc_82182884;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82182880;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
loc_82182884:
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

__attribute__((alias("__imp__sub_82182898"))) PPC_WEAK_FUNC(sub_82182898);
PPC_FUNC_IMPL(__imp__sub_82182898) {
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
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821828CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
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

__attribute__((alias("__imp__sub_821828E4"))) PPC_WEAK_FUNC(sub_821828E4);
PPC_FUNC_IMPL(__imp__sub_821828E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821828E8"))) PPC_WEAK_FUNC(sub_821828E8);
PPC_FUNC_IMPL(__imp__sub_821828E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,40(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821828F8"))) PPC_WEAK_FUNC(sub_821828F8);
PPC_FUNC_IMPL(__imp__sub_821828F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,6690
	r11.s64 = 438435840;
	// ori r10,r11,43869
	ctx.r10.u64 = r11.u64 | 43869;
	// cmpw cr6,r3,r10
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r3,6690
	ctx.r3.s64 = 438435840;
	// ori r3,r3,43872
	ctx.r3.u64 = ctx.r3.u64 | 43872;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82182914"))) PPC_WEAK_FUNC(sub_82182914);
PPC_FUNC_IMPL(__imp__sub_82182914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182918"))) PPC_WEAK_FUNC(sub_82182918);
PPC_FUNC_IMPL(__imp__sub_82182918) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82182920;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82182948;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r30,0
	r30.s64 = 0;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// rlwinm r8,r9,0,20,20
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82182964
	if (!cr6.eq) goto loc_82182964;
	// li r30,1
	r30.s64 = 1;
loc_82182964:
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r10,r11,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80000000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82182978
	if (cr6.eq) goto loc_82182978;
	// ori r30,r30,2
	r30.u64 = r30.u64 | 2;
loc_82182978:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r28,104(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r27,120(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// mr r26,r11
	r26.u64 = r11.u64;
	// mr r25,r11
	r25.u64 = r11.u64;
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x821829A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,24(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x821829B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// stw r26,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r26.u32);
	// stw r6,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r6.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// clrlwi r6,r27,26
	ctx.r6.u64 = r27.u32 & 0x3F;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x82432440
	ctx.lr = 0x821829E4;
	sub_82432440(ctx, base);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,80(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 80);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x821829FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82182A04"))) PPC_WEAK_FUNC(sub_82182A04);
PPC_FUNC_IMPL(__imp__sub_82182A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182A08"))) PPC_WEAK_FUNC(sub_82182A08);
PPC_FUNC_IMPL(__imp__sub_82182A08) {
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
	ctx.lr = 0x82182A10;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r29,80(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 80);
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82432d28
	ctx.lr = 0x82182A38;
	sub_82432D28(ctx, base);
	// lwz r11,140(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// lwz r10,116(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r8,128(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r9.u32);
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// bl 0x82421a18
	ctx.lr = 0x82182A68;
	sub_82421A18(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// beq cr6,0x82182b10
	if (cr6.eq) goto loc_82182B10;
	// cmpwi cr6,r3,17
	cr6.compare<int32_t>(ctx.r3.s32, 17, xer);
	// beq cr6,0x82182ad0
	if (cr6.eq) goto loc_82182AD0;
	// cmpwi cr6,r3,18
	cr6.compare<int32_t>(ctx.r3.s32, 18, xer);
	// beq cr6,0x82182a98
	if (cr6.eq) goto loc_82182A98;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-23500
	ctx.r3.s64 = r11.s64 + -23500;
	// bl 0x821bd618
	ctx.lr = 0x82182A8C;
	sub_821BD618(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
loc_82182A98:
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,80(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 80);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82410c20
	ctx.lr = 0x82182AB4;
	sub_82410C20(ctx, base);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
loc_82182AD0:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,80(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 80);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82410c48
	ctx.lr = 0x82182AE8;
	sub_82410C48(ctx, base);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mullw r11,r11,r30
	r11.s64 = int64_t(r11.s32) * int64_t(r30.s32);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
loc_82182B10:
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82410c00
	ctx.lr = 0x82182B28;
	sub_82410C00(ctx, base);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82182B44"))) PPC_WEAK_FUNC(sub_82182B44);
PPC_FUNC_IMPL(__imp__sub_82182B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182B48"))) PPC_WEAK_FUNC(sub_82182B48);
PPC_FUNC_IMPL(__imp__sub_82182B48) {
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
	ctx.lr = 0x82182B50;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r30,80(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 80);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82421a18
	ctx.lr = 0x82182B68;
	sub_82421A18(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// beq cr6,0x82182bc0
	if (cr6.eq) goto loc_82182BC0;
	// cmpwi cr6,r3,17
	cr6.compare<int32_t>(ctx.r3.s32, 17, xer);
	// beq cr6,0x82182bac
	if (cr6.eq) goto loc_82182BAC;
	// cmpwi cr6,r3,18
	cr6.compare<int32_t>(ctx.r3.s32, 18, xer);
	// beq cr6,0x82182b94
	if (cr6.eq) goto loc_82182B94;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-23500
	ctx.r3.s64 = r11.s64 + -23500;
	// bl 0x821bd618
	ctx.lr = 0x82182B8C;
	sub_821BD618(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82182B94:
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r3,80(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 80);
	// bl 0x8240f220
	ctx.lr = 0x82182BA4;
	sub_8240F220(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82182BAC:
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r3,80(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 80);
	// bl 0x8240f220
	ctx.lr = 0x82182BB8;
	sub_8240F220(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82182BC0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8240f220
	ctx.lr = 0x82182BCC;
	sub_8240F220(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82182BD4"))) PPC_WEAK_FUNC(sub_82182BD4);
PPC_FUNC_IMPL(__imp__sub_82182BD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182BD8"))) PPC_WEAK_FUNC(sub_82182BD8);
PPC_FUNC_IMPL(__imp__sub_82182BD8) {
	PPC_FUNC_PROLOGUE();
	// lhz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82182BE0"))) PPC_WEAK_FUNC(sub_82182BE0);
PPC_FUNC_IMPL(__imp__sub_82182BE0) {
	PPC_FUNC_PROLOGUE();
	// lhz r3,34(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 34);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82182BE8"))) PPC_WEAK_FUNC(sub_82182BE8);
PPC_FUNC_IMPL(__imp__sub_82182BE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,40(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	f0.f64 = double(temp.f32);
	// lfs f13,44(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,48(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f13,4(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f12,8(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82182C04"))) PPC_WEAK_FUNC(sub_82182C04);
PPC_FUNC_IMPL(__imp__sub_82182C04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182C08"))) PPC_WEAK_FUNC(sub_82182C08);
PPC_FUNC_IMPL(__imp__sub_82182C08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,52(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 52);
	f0.f64 = double(temp.f32);
	// lfs f13,56(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,60(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 60);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f13,4(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f12,8(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82182C24"))) PPC_WEAK_FUNC(sub_82182C24);
PPC_FUNC_IMPL(__imp__sub_82182C24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82182C28"))) PPC_WEAK_FUNC(sub_82182C28);
PPC_FUNC_IMPL(__imp__sub_82182C28) {
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
	ctx.lr = 0x82182C30;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// bl 0x8218fd18
	ctx.lr = 0x82182C48;
	sub_8218FD18(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// stw r27,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r27.u32);
	// li r30,0
	r30.s64 = 0;
	// stw r27,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r27.u32);
	// addi r9,r11,-23460
	ctx.r9.s64 = r11.s64 + -23460;
	// sth r29,32(r31)
	PPC_STORE_U16(r31.u32 + 32, r29.u16);
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// sth r28,34(r31)
	PPC_STORE_U16(r31.u32 + 34, r28.u16);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// bl 0x82410be8
	ctx.lr = 0x82182C78;
	sub_82410BE8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82182ccc
	if (cr6.eq) goto loc_82182CCC;
loc_82182C80:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82432d28
	ctx.lr = 0x82182C90;
	sub_82432D28(ctx, base);
	// lwz r10,116(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r9,112(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lwz r8,120(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// mullw r7,r9,r10
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// lwz r6,124(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mullw r5,r7,r8
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32);
	// mullw r10,r5,r6
	ctx.r10.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// stw r4,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r4.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x82410be8
	ctx.lr = 0x82182CC4;
	sub_82410BE8(ctx, base);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// blt cr6,0x82182c80
	if (cr6.lt) goto loc_82182C80;
loc_82182CCC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82182CD8"))) PPC_WEAK_FUNC(sub_82182CD8);
PPC_FUNC_IMPL(__imp__sub_82182CD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r24{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82182cf0
	if (cr6.eq) goto loc_82182CF0;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// b 0x82182cf4
	goto loc_82182CF4;
loc_82182CF0:
	// li r11,0
	r11.s64 = 0;
loc_82182CF4:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// clrlwi r10,r10,1
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFFFFFF;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r10,21
	cr6.compare<uint32_t>(ctx.r10.u32, 21, xer);
	// bgt cr6,0x82182f98
	if (cr6.gt) goto loc_82182F98;
	// lis r12,-32232
	r12.s64 = -2112356352;
	// addi r12,r12,11556
	r12.s64 = r12.s64 + 11556;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_82182D7C;
	case 1:
		goto loc_82182DB4;
	case 2:
		goto loc_82182DD4;
	case 3:
		goto loc_82182DF4;
	case 4:
		goto loc_82182E14;
	case 5:
		goto loc_82182E34;
	case 6:
		goto loc_82182E4C;
	case 7:
		goto loc_82182E64;
	case 8:
		goto loc_82182F98;
	case 9:
		goto loc_82182F98;
	case 10:
		goto loc_82182E70;
	case 11:
		goto loc_82182E90;
	case 12:
		goto loc_82182EA8;
	case 13:
		goto loc_82182EB4;
	case 14:
		goto loc_82182ECC;
	case 15:
		goto loc_82182EEC;
	case 16:
		goto loc_82182F0C;
	case 17:
		goto loc_82182F2C;
	case 18:
		goto loc_82182F4C;
	case 19:
		goto loc_82182F58;
	case 20:
		goto loc_82182D94;
	case 21:
		goto loc_82182F78;
	default:
		__builtin_unreachable();
	}
	// lwz r16,11644(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 11644);
	// lwz r16,11700(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 11700);
	// lwz r16,11732(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 11732);
	// lwz r16,11764(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 11764);
	// lwz r16,11796(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 11796);
	// lwz r16,11828(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 11828);
	// lwz r16,11852(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 11852);
	// lwz r16,11876(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 11876);
	// lwz r16,12184(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 12184);
	// lwz r16,12184(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 12184);
	// lwz r16,11888(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 11888);
	// lwz r16,11920(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 11920);
	// lwz r16,11944(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 11944);
	// lwz r16,11956(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 11956);
	// lwz r16,11980(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 11980);
	// lwz r16,12012(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 12012);
	// lwz r16,12044(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 12044);
	// lwz r16,12076(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 12076);
	// lwz r16,12108(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 12108);
	// lwz r16,12120(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 12120);
	// lwz r16,11668(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 11668);
	// lwz r16,12152(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 12152);
loc_82182D7C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r3,6184
	ctx.r3.s64 = 405274624;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82182f50
	if (!cr6.eq) goto loc_82182F50;
loc_82182D8C:
	// ori r3,r3,390
	ctx.r3.u64 = ctx.r3.u64 | 390;
	// blr 
	return;
loc_82182D94:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r3,6688
	ctx.r3.s64 = 438304768;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82182dac
	if (cr6.eq) goto loc_82182DAC;
	// ori r3,r3,43654
	ctx.r3.u64 = ctx.r3.u64 | 43654;
	// blr 
	return;
loc_82182DAC:
	// ori r3,r3,43910
	ctx.r3.u64 = ctx.r3.u64 | 43910;
	// blr 
	return;
loc_82182DB4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r3,6688
	ctx.r3.s64 = 438304768;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82182dcc
	if (cr6.eq) goto loc_82182DCC;
	// ori r3,r3,82
	ctx.r3.u64 = ctx.r3.u64 | 82;
	// blr 
	return;
loc_82182DCC:
	// ori r3,r3,338
	ctx.r3.u64 = ctx.r3.u64 | 338;
	// blr 
	return;
loc_82182DD4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r3,6688
	ctx.r3.s64 = 438304768;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82182dec
	if (cr6.eq) goto loc_82182DEC;
	// ori r3,r3,83
	ctx.r3.u64 = ctx.r3.u64 | 83;
	// blr 
	return;
loc_82182DEC:
	// ori r3,r3,339
	ctx.r3.u64 = ctx.r3.u64 | 339;
	// blr 
	return;
loc_82182DF4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r3,6688
	ctx.r3.s64 = 438304768;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82182e0c
	if (cr6.eq) goto loc_82182E0C;
	// ori r3,r3,84
	ctx.r3.u64 = ctx.r3.u64 | 84;
	// blr 
	return;
loc_82182E0C:
	// ori r3,r3,340
	ctx.r3.u64 = ctx.r3.u64 | 340;
	// blr 
	return;
loc_82182E14:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r3,6688
	ctx.r3.s64 = 438304768;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82182e2c
	if (cr6.eq) goto loc_82182E2C;
	// ori r3,r3,113
	ctx.r3.u64 = ctx.r3.u64 | 113;
	// blr 
	return;
loc_82182E2C:
	// ori r3,r3,369
	ctx.r3.u64 = ctx.r3.u64 | 369;
	// blr 
	return;
loc_82182E34:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r3,1168
	ctx.r3.s64 = 76546048;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82182e68
	if (!cr6.eq) goto loc_82182E68;
loc_82182E44:
	// ori r3,r3,258
	ctx.r3.u64 = ctx.r3.u64 | 258;
	// blr 
	return;
loc_82182E4C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r3,10240
	ctx.r3.s64 = 671088640;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82182e44
	if (cr6.eq) goto loc_82182E44;
	// ori r3,r3,2
	ctx.r3.u64 = ctx.r3.u64 | 2;
	// blr 
	return;
loc_82182E64:
	// lis r3,10240
	ctx.r3.s64 = 671088640;
loc_82182E68:
	// ori r3,r3,2
	ctx.r3.u64 = ctx.r3.u64 | 2;
	// blr 
	return;
loc_82182E70:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r3,6690
	ctx.r3.s64 = 438435840;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82182e88
	if (cr6.eq) goto loc_82182E88;
	// ori r3,r3,43616
	ctx.r3.u64 = ctx.r3.u64 | 43616;
	// blr 
	return;
loc_82182E88:
	// ori r3,r3,43869
	ctx.r3.u64 = ctx.r3.u64 | 43869;
	// blr 
	return;
loc_82182E90:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r3,6690
	ctx.r3.s64 = 438435840;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82182eac
	if (!cr6.eq) goto loc_82182EAC;
	// ori r3,r3,43942
	ctx.r3.u64 = ctx.r3.u64 | 43942;
	// blr 
	return;
loc_82182EA8:
	// lis r3,6690
	ctx.r3.s64 = 438435840;
loc_82182EAC:
	// ori r3,r3,43686
	ctx.r3.u64 = ctx.r3.u64 | 43686;
	// blr 
	return;
loc_82182EB4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r3,6184
	ctx.r3.s64 = 405274624;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82182d8c
	if (cr6.eq) goto loc_82182D8C;
	// ori r3,r3,134
	ctx.r3.u64 = ctx.r3.u64 | 134;
	// blr 
	return;
loc_82182ECC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r3,11682
	ctx.r3.s64 = 765591552;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82182ee4
	if (cr6.eq) goto loc_82182EE4;
	// ori r3,r3,43684
	ctx.r3.u64 = ctx.r3.u64 | 43684;
	// blr 
	return;
loc_82182EE4:
	// ori r3,r3,43940
	ctx.r3.u64 = ctx.r3.u64 | 43940;
	// blr 
	return;
loc_82182EEC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r3,11554
	ctx.r3.s64 = 757202944;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82182f04
	if (cr6.eq) goto loc_82182F04;
	// ori r3,r3,43679
	ctx.r3.u64 = ctx.r3.u64 | 43679;
	// blr 
	return;
loc_82182F04:
	// ori r3,r3,43935
	ctx.r3.u64 = ctx.r3.u64 | 43935;
	// blr 
	return;
loc_82182F0C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r3,11552
	ctx.r3.s64 = 757071872;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82182f24
	if (cr6.eq) goto loc_82182F24;
	// ori r3,r3,153
	ctx.r3.u64 = ctx.r3.u64 | 153;
	// blr 
	return;
loc_82182F24:
	// ori r3,r3,409
	ctx.r3.u64 = ctx.r3.u64 | 409;
	// blr 
	return;
loc_82182F2C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r3,6688
	ctx.r3.s64 = 438304768;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82182f44
	if (cr6.eq) goto loc_82182F44;
	// ori r3,r3,90
	ctx.r3.u64 = ctx.r3.u64 | 90;
	// blr 
	return;
loc_82182F44:
	// ori r3,r3,346
	ctx.r3.u64 = ctx.r3.u64 | 346;
	// blr 
	return;
loc_82182F4C:
	// lis r3,6184
	ctx.r3.s64 = 405274624;
loc_82182F50:
	// ori r3,r3,134
	ctx.r3.u64 = ctx.r3.u64 | 134;
	// blr 
	return;
loc_82182F58:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r3,6184
	ctx.r3.s64 = 405274624;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82182f70
	if (cr6.eq) goto loc_82182F70;
	// ori r3,r3,79
	ctx.r3.u64 = ctx.r3.u64 | 79;
	// blr 
	return;
loc_82182F70:
	// ori r3,r3,335
	ctx.r3.u64 = ctx.r3.u64 | 335;
	// blr 
	return;
loc_82182F78:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// lis r3,11554
	ctx.r3.s64 = 757202944;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82182f90
	if (cr6.eq) goto loc_82182F90;
	// ori r3,r3,43685
	ctx.r3.u64 = ctx.r3.u64 | 43685;
	// blr 
	return;
loc_82182F90:
	// ori r3,r3,43941
	ctx.r3.u64 = ctx.r3.u64 | 43941;
	// blr 
	return;
loc_82182F98:
	// li r3,-1
	ctx.r3.s64 = -1;
}

__attribute__((alias("__imp__sub_82182FA0"))) PPC_WEAK_FUNC(sub_82182FA0);
PPC_FUNC_IMPL(__imp__sub_82182FA0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82182FA8;
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r19,r4
	r19.u64 = ctx.r4.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lhz r11,14(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 14);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// bl 0x8218d798
	ctx.lr = 0x82182FC4;
	sub_8218D798(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bne cr6,0x82183290
	if (!cr6.eq) goto loc_82183290;
	// lhz r11,32(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 32);
	// lhz r10,0(r19)
	ctx.r10.u64 = PPC_LOAD_U16(r19.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82183290
	if (!cr6.eq) goto loc_82183290;
	// lhz r11,34(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 34);
	// lhz r10,2(r19)
	ctx.r10.u64 = PPC_LOAD_U16(r19.u32 + 2);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82183290
	if (!cr6.eq) goto loc_82183290;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x8218cd80
	ctx.lr = 0x82182FF4;
	sub_8218CD80(ctx, base);
	// lwz r11,36(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 36);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82183290
	if (!cr6.eq) goto loc_82183290;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,8(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 8);
	// stw r30,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r30.u32);
	// clrlwi r18,r11,24
	r18.u64 = r11.u32 & 0xFF;
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// stw r30,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r30.u32);
	// stw r30,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r30.u32);
	// stw r30,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r30.u32);
	// bl 0x821bbea8
	ctx.lr = 0x82183028;
	sub_821BBEA8(ctx, base);
	// lwz r10,28(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 28);
	// mr r21,r19
	r21.u64 = r19.u64;
	// mr r20,r30
	r20.u64 = r30.u64;
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// rlwinm r23,r9,21,31,31
	r23.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 21) & 0x1;
loc_8218303C:
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// lwz r3,28(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 28);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r25,r21
	r25.u64 = r21.u64;
	// bl 0x82432d28
	ctx.lr = 0x82183050;
	sub_82432D28(ctx, base);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// mr r31,r30
	r31.u64 = r30.u64;
	// bl 0x8218cd80
	ctx.lr = 0x8218305C;
	sub_8218CD80(ctx, base);
	// addic. r11,r3,1
	xer.ca = ctx.r3.u32 > 4294967294;
	r11.s64 = ctx.r3.s64 + 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x82183240
	if (!cr0.gt) goto loc_82183240;
	// clrlwi r22,r18,24
	r22.u64 = r18.u32 & 0xFF;
loc_82183068:
	// lwz r3,28(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 28);
	// cmplwi cr6,r22,1
	cr6.compare<uint32_t>(r22.u32, 1, xer);
	// li r7,0
	ctx.r7.s64 = 0;
	// bne cr6,0x82183090
	if (!cr6.eq) goto loc_82183090;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// bl 0x82410c20
	ctx.lr = 0x8218308C;
	sub_82410C20(ctx, base);
	// b 0x821830b4
	goto loc_821830B4;
loc_82183090:
	// cmplwi cr6,r22,3
	cr6.compare<uint32_t>(r22.u32, 3, xer);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bne cr6,0x821830ac
	if (!cr6.eq) goto loc_821830AC;
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// bl 0x82410c48
	ctx.lr = 0x821830A8;
	sub_82410C48(ctx, base);
	// b 0x821830b4
	goto loc_821830B4;
loc_821830AC:
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// bl 0x82410c00
	ctx.lr = 0x821830B4;
	sub_82410C00(ctx, base);
loc_821830B4:
	// lwz r3,208(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// rlwinm r11,r3,0,23,23
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x100;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821831b8
	if (cr6.eq) goto loc_821831B8;
	// lwz r11,224(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	// cmplwi cr6,r22,3
	cr6.compare<uint32_t>(r22.u32, 3, xer);
	// lwz r29,196(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	// lhz r10,12(r25)
	ctx.r10.u64 = PPC_LOAD_U16(r25.u32 + 12);
	// twllei r11,0
	// divwu r9,r29,r11
	ctx.r9.u32 = r29.u32 / r11.u32;
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// mullw r28,r9,r10
	r28.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// bne cr6,0x8218317c
	if (!cr6.eq) goto loc_8218317C;
	// lwz r27,200(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// srw r10,r29,r31
	ctx.r10.u64 = r31.u8 & 0x20 ? 0 : (r29.u32 >> (r31.u8 & 0x3F));
	// lwz r26,204(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// srw r9,r27,r31
	ctx.r9.u64 = r31.u8 & 0x20 ? 0 : (r27.u32 >> (r31.u8 & 0x3F));
	// srw r8,r26,r31
	ctx.r8.u64 = r31.u8 & 0x20 ? 0 : (r26.u32 >> (r31.u8 & 0x3F));
	// lwz r17,16(r25)
	r17.u64 = PPC_LOAD_U32(r25.u32 + 16);
	// stw r30,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r30.u32);
	// addi r16,r1,160
	r16.s64 = ctx.r1.s64 + 160;
	// stw r30,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r30.u32);
	// addi r15,r1,136
	r15.s64 = ctx.r1.s64 + 136;
	// stw r30,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r30.u32);
	// cntlzw r14,r11
	r14.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// stw r30,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r30.u32);
	// stw r10,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r10.u32);
	// stw r9,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r9.u32);
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r30.u32);
	// stw r8,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r8.u32);
	// bl 0x821828f8
	ctx.lr = 0x82183134;
	sub_821828F8(ctx, base);
	// lwz r11,124(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// clrlwi r7,r3,26
	ctx.r7.u64 = ctx.r3.u32 & 0x3F;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// stw r17,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r17.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r16,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r16.u32);
	// rlwinm r8,r14,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(r14.u32 | (r14.u64 << 32), 27) & 0x1;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// mr r10,r15
	ctx.r10.u64 = r15.u64;
	// bl 0x824333d0
	ctx.lr = 0x8218316C;
	sub_824333D0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,28(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 28);
	// bl 0x8240f220
	ctx.lr = 0x82183178;
	sub_8240F220(ctx, base);
	// b 0x82183224
	goto loc_82183224;
loc_8218317C:
	// lwz r27,16(r25)
	r27.u64 = PPC_LOAD_U32(r25.u32 + 16);
	// cntlzw r26,r11
	r26.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// bl 0x821828f8
	ctx.lr = 0x82183188;
	sub_821828F8(ctx, base);
	// clrlwi r6,r3,26
	ctx.r6.u64 = ctx.r3.u32 & 0x3F;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,200(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,116(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// rlwinm r7,r26,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 27) & 0x1;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// bl 0x824321e0
	ctx.lr = 0x821831B4;
	sub_824321E0(ctx, base);
	// b 0x821831e4
	goto loc_821831E4;
loc_821831B8:
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// cmplwi cr6,r22,3
	cr6.compare<uint32_t>(r22.u32, 3, xer);
	// beq cr6,0x821831c8
	if (cr6.eq) goto loc_821831C8;
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
loc_821831C8:
	// lhz r11,14(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 14);
	// lhz r10,12(r25)
	ctx.r10.u64 = PPC_LOAD_U16(r25.u32 + 12);
	// lhz r9,2(r25)
	ctx.r9.u64 = PPC_LOAD_U16(r25.u32 + 2);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r4,16(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 16);
	// mullw r5,r8,r9
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// bl 0x823da950
	ctx.lr = 0x821831E4;
	sub_823DA950(ctx, base);
loc_821831E4:
	// cmplwi cr6,r22,1
	cr6.compare<uint32_t>(r22.u32, 1, xer);
	// bne cr6,0x82183200
	if (!cr6.eq) goto loc_82183200;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,28(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 28);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// bl 0x8240f220
	ctx.lr = 0x821831FC;
	sub_8240F220(ctx, base);
	// b 0x82183224
	goto loc_82183224;
loc_82183200:
	// cmplwi cr6,r22,3
	cr6.compare<uint32_t>(r22.u32, 3, xer);
	// bne cr6,0x82183218
	if (!cr6.eq) goto loc_82183218;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,28(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 28);
	// bl 0x8240f220
	ctx.lr = 0x82183214;
	sub_8240F220(ctx, base);
	// b 0x82183224
	goto loc_82183224;
loc_82183218:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,28(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 28);
	// bl 0x8240f220
	ctx.lr = 0x82183224;
	sub_8240F220(ctx, base);
loc_82183224:
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// lwz r25,24(r25)
	r25.u64 = PPC_LOAD_U32(r25.u32 + 24);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bl 0x8218cd80
	ctx.lr = 0x82183234;
	sub_8218CD80(ctx, base);
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x82183068
	if (cr6.lt) goto loc_82183068;
loc_82183240:
	// lwz r21,28(r21)
	r21.u64 = PPC_LOAD_U32(r21.u32 + 28);
	// addi r20,r20,1
	r20.s64 = r20.s64 + 1;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// bne cr6,0x8218303c
	if (!cr6.eq) goto loc_8218303C;
	// bl 0x821bbf00
	ctx.lr = 0x82183254;
	sub_821BBF00(ctx, base);
	// lfs f0,48(r19)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r19.u32 + 48);
	f0.f64 = double(temp.f32);
	// stfs f0,40(r24)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r24.u32 + 40, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f13,52(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,44(r24)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r24.u32 + 44, temp.u32);
	// lfs f12,56(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,48(r24)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r24.u32 + 48, temp.u32);
	// lfs f11,64(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 64);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,52(r24)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r24.u32 + 52, temp.u32);
	// lfs f10,68(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 68);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,56(r24)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r24.u32 + 56, temp.u32);
	// lfs f9,72(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 72);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,60(r24)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r24.u32 + 60, temp.u32);
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d9210
	return;
loc_82183290:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8218329C"))) PPC_WEAK_FUNC(sub_8218329C);
PPC_FUNC_IMPL(__imp__sub_8218329C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821832A0"))) PPC_WEAK_FUNC(sub_821832A0);
PPC_FUNC_IMPL(__imp__sub_821832A0) {
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
	ctx.lr = 0x821832A8;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r27,28(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82432d28
	ctx.lr = 0x821832CC;
	sub_82432D28(ctx, base);
	// lwz r11,32(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 32);
	// li r30,0
	r30.s64 = 0;
	// lwz r7,128(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r27.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r30,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r30.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// rlwinm r26,r11,20,12,31
	r26.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 20) & 0xFFFFF;
	// bl 0x82430938
	ctx.lr = 0x8218330C;
	sub_82430938(ctx, base);
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// sth r29,32(r31)
	PPC_STORE_U16(r31.u32 + 32, r29.u16);
	// sth r28,34(r31)
	PPC_STORE_U16(r31.u32 + 34, r28.u16);
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r8,32(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 32);
	// rlwimi r8,r26,12,0,19
	ctx.r8.u64 = (__builtin_rotateleft32(r26.u32, 12) & 0xFFFFF000) | (ctx.r8.u64 & 0xFFFFFFFF00000FFF);
	// oris r6,r7,32
	ctx.r6.u64 = ctx.r7.u64 | 2097152;
	// stw r8,32(r27)
	PPC_STORE_U32(r27.u32 + 32, ctx.r8.u32);
	// stw r6,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r6.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x82410be8
	ctx.lr = 0x8218333C;
	sub_82410BE8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82183390
	if (cr6.eq) goto loc_82183390;
loc_82183344:
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82432d28
	ctx.lr = 0x82183354;
	sub_82432D28(ctx, base);
	// lwz r10,148(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r9,144(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lwz r8,152(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// mullw r7,r9,r10
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// lwz r6,156(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mullw r5,r7,r8
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32);
	// mullw r10,r5,r6
	ctx.r10.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// stw r4,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r4.u32);
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x82410be8
	ctx.lr = 0x82183388;
	sub_82410BE8(ctx, base);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// blt cr6,0x82183344
	if (cr6.lt) goto loc_82183344;
loc_82183390:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82183398"))) PPC_WEAK_FUNC(sub_82183398);
PPC_FUNC_IMPL(__imp__sub_82183398) {
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
	ctx.lr = 0x821833A0;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r29,28(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82432d28
	ctx.lr = 0x821833C8;
	sub_82432D28(ctx, base);
	// lwz r11,140(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// lwz r10,116(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r8,128(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r9.u32);
	// stw r8,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r8.u32);
	// bl 0x82421a18
	ctx.lr = 0x821833F8;
	sub_82421A18(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// beq cr6,0x821834a0
	if (cr6.eq) goto loc_821834A0;
	// cmpwi cr6,r3,17
	cr6.compare<int32_t>(ctx.r3.s32, 17, xer);
	// beq cr6,0x82183460
	if (cr6.eq) goto loc_82183460;
	// cmpwi cr6,r3,18
	cr6.compare<int32_t>(ctx.r3.s32, 18, xer);
	// beq cr6,0x82183428
	if (cr6.eq) goto loc_82183428;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-23500
	ctx.r3.s64 = r11.s64 + -23500;
	// bl 0x821bd618
	ctx.lr = 0x8218341C;
	sub_821BD618(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
loc_82183428:
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,28(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82410c20
	ctx.lr = 0x82183444;
	sub_82410C20(ctx, base);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
loc_82183460:
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,28(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82410c48
	ctx.lr = 0x82183478;
	sub_82410C48(ctx, base);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r10,104(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mullw r11,r11,r30
	r11.s64 = int64_t(r11.s32) * int64_t(r30.s32);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
loc_821834A0:
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82410c00
	ctx.lr = 0x821834B8;
	sub_82410C00(ctx, base);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821834D4"))) PPC_WEAK_FUNC(sub_821834D4);
PPC_FUNC_IMPL(__imp__sub_821834D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821834D8"))) PPC_WEAK_FUNC(sub_821834D8);
PPC_FUNC_IMPL(__imp__sub_821834D8) {
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
	ctx.lr = 0x821834E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r30,28(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82421a18
	ctx.lr = 0x821834F8;
	sub_82421A18(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// beq cr6,0x82183550
	if (cr6.eq) goto loc_82183550;
	// cmpwi cr6,r3,17
	cr6.compare<int32_t>(ctx.r3.s32, 17, xer);
	// beq cr6,0x8218353c
	if (cr6.eq) goto loc_8218353C;
	// cmpwi cr6,r3,18
	cr6.compare<int32_t>(ctx.r3.s32, 18, xer);
	// beq cr6,0x82183524
	if (cr6.eq) goto loc_82183524;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-23500
	ctx.r3.s64 = r11.s64 + -23500;
	// bl 0x821bd618
	ctx.lr = 0x8218351C;
	sub_821BD618(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82183524:
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r3,28(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// bl 0x8240f220
	ctx.lr = 0x82183534;
	sub_8240F220(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8218353C:
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r3,28(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// bl 0x8240f220
	ctx.lr = 0x82183548;
	sub_8240F220(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82183550:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8240f220
	ctx.lr = 0x8218355C;
	sub_8240F220(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82183564"))) PPC_WEAK_FUNC(sub_82183564);
PPC_FUNC_IMPL(__imp__sub_82183564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82183568"))) PPC_WEAK_FUNC(sub_82183568);
PPC_FUNC_IMPL(__imp__sub_82183568) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r9,r10,28,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r8,r10,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// and r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 & ctx.r8.u64;
	// and r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 & ctx.r10.u64;
	// rlwinm r11,r6,0,28,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xC;
	// addi r5,r11,-12
	ctx.r5.s64 = r11.s64 + -12;
	// cntlzw r4,r5
	ctx.r4.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r3,r4,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82183594"))) PPC_WEAK_FUNC(sub_82183594);
PPC_FUNC_IMPL(__imp__sub_82183594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82183598"))) PPC_WEAK_FUNC(sub_82183598);
PPC_FUNC_IMPL(__imp__sub_82183598) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821835ec
	if (cr6.eq) goto loc_821835EC;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// clrlwi r9,r10,26
	ctx.r9.u64 = ctx.r10.u32 & 0x3F;
	// cmplwi cr6,r9,6
	cr6.compare<uint32_t>(ctx.r9.u32, 6, xer);
	// bne cr6,0x821835ec
	if (!cr6.eq) goto loc_821835EC;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// ori r9,r10,12
	ctx.r9.u64 = ctx.r10.u64 | 12;
	// stw r9,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r9.u32);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// ori r7,r8,48
	ctx.r7.u64 = ctx.r8.u64 | 48;
	// stw r7,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r7.u32);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r6,28(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// ori r5,r6,192
	ctx.r5.u64 = ctx.r6.u64 | 192;
	// stw r5,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r5.u32);
	// blr 
	return;
loc_821835EC:
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r9,r10,0,30,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF3;
	// stw r9,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r9.u32);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r7,r8,0,28,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFCF;
	// stw r7,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r7.u32);
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r6,28(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r5,r6,0,26,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFF3F;
	// stw r5,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82183620"))) PPC_WEAK_FUNC(sub_82183620);
PPC_FUNC_IMPL(__imp__sub_82183620) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// lwz r3,80(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82183630
	if (cr6.eq) goto loc_82183630;
	// b 0x82410be8
	sub_82410BE8(ctx, base);
	return;
loc_82183630:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82183638"))) PPC_WEAK_FUNC(sub_82183638);
PPC_FUNC_IMPL(__imp__sub_82183638) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82183674
	if (cr6.eq) goto loc_82183674;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r9,r10,28,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// rlwinm r8,r10,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// and r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 & ctx.r8.u64;
	// and r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 & ctx.r10.u64;
	// rlwinm r11,r6,0,28,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xC;
	// addi r5,r11,-12
	ctx.r5.s64 = r11.s64 + -12;
	// cntlzw r4,r5
	ctx.r4.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r3,r4,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// blr 
	return;
loc_82183674:
	// li r11,0
	r11.s64 = 0;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82183680"))) PPC_WEAK_FUNC(sub_82183680);
PPC_FUNC_IMPL(__imp__sub_82183680) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821836dc
	if (cr6.eq) goto loc_821836DC;
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// clrlwi r10,r11,26
	ctx.r10.u64 = r11.u32 & 0x3F;
	// cmplwi cr6,r10,6
	cr6.compare<uint32_t>(ctx.r10.u32, 6, xer);
	// bne cr6,0x821836dc
	if (!cr6.eq) goto loc_821836DC;
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// ori r9,r10,12
	ctx.r9.u64 = ctx.r10.u64 | 12;
	// stw r9,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r9.u32);
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// lwz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// ori r7,r8,48
	ctx.r7.u64 = ctx.r8.u64 | 48;
	// stw r7,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r7.u32);
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// lwz r6,28(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// ori r5,r6,192
	ctx.r5.u64 = ctx.r6.u64 | 192;
	// stw r5,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r5.u32);
	// blr 
	return;
loc_821836DC:
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r9,r10,0,30,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF3;
	// stw r9,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r9.u32);
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// lwz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r7,r8,0,28,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFCF;
	// stw r7,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r7.u32);
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// lwz r6,28(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r5,r6,0,26,23
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFF3F;
	// stw r5,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82183710"))) PPC_WEAK_FUNC(sub_82183710);
PPC_FUNC_IMPL(__imp__sub_82183710) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// stw r4,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218373c
	if (cr6.eq) goto loc_8218373C;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// li r8,0
	ctx.r8.s64 = 0;
	// stwx r8,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r8.u32);
	// stw r3,-24876(r9)
	PPC_STORE_U32(ctx.r9.u32 + -24876, ctx.r3.u32);
	// blr 
	return;
loc_8218373C:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// stw r3,-24876(r11)
	PPC_STORE_U32(r11.u32 + -24876, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82183748"))) PPC_WEAK_FUNC(sub_82183748);
PPC_FUNC_IMPL(__imp__sub_82183748) {
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
	// lis r31,-32124
	r31.s64 = -2105278464;
	// add r11,r3,r4
	r11.u64 = ctx.r3.u64 + ctx.r4.u64;
	// addi r10,r4,-1
	ctx.r10.s64 = ctx.r4.s64 + -1;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// lwz r11,-24876(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -24876);
	// andc r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r10.u64;
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r10,r11
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// add r7,r30,r9
	ctx.r7.u64 = r30.u64 + ctx.r9.u64;
	// stwx r7,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r7.u32);
	// lwz r5,-24876(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + -24876);
	// lwz r11,16(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	// lwz r10,12(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// lwz r6,20(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r4
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	// lwzx r8,r11,r4
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r4.u32);
	// cmpw cr6,r3,r8
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r8.s32, xer);
	// ble cr6,0x821837c4
	if (!cr6.gt) goto loc_821837C4;
	// rotlwi r8,r6,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r7,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// stwx r6,r7,r11
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, ctx.r6.u32);
	// lwz r5,-24876(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + -24876);
loc_821837C4:
	// lwz r6,20(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r10,12(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// rlwinm r8,r6,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,8(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// addi r3,r11,-23344
	ctx.r3.s64 = r11.s64 + -23344;
	// lwzx r4,r8,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// subf r11,r4,r7
	r11.s64 = ctx.r7.s64 - ctx.r4.s64;
	// srawi r10,r11,10
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3FF) != 0);
	ctx.r10.s64 = r11.s32 >> 10;
	// addze r7,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r7.s64 = temp.s64;
	// srawi r9,r9,10
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3FF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 10;
	// addze r4,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r4.s64 = temp.s64;
	// bl 0x82130000
	ctx.lr = 0x821837F8;
	sub_82130000(ctx, base);
	// lwz r11,-24876(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -24876);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
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

__attribute__((alias("__imp__sub_8218381C"))) PPC_WEAK_FUNC(sub_8218381C);
PPC_FUNC_IMPL(__imp__sub_8218381C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82183820"))) PPC_WEAK_FUNC(sub_82183820);
PPC_FUNC_IMPL(__imp__sub_82183820) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218384c
	if (cr6.eq) goto loc_8218384C;
	// bl 0x82130588
	ctx.lr = 0x8218384C;
	sub_82130588(ctx, base);
loc_8218384C:
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
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

__attribute__((alias("__imp__sub_8218386C"))) PPC_WEAK_FUNC(sub_8218386C);
PPC_FUNC_IMPL(__imp__sub_8218386C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82183870"))) PPC_WEAK_FUNC(sub_82183870);
PPC_FUNC_IMPL(__imp__sub_82183870) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addic. r9,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r9.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble 0x821838c4
	if (!cr0.gt) goto loc_821838C4;
loc_8218387C:
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821838c4
	if (cr6.eq) goto loc_821838C4;
	// cmplwi cr6,r11,65
	cr6.compare<uint32_t>(r11.u32, 65, xer);
	// blt cr6,0x821838a8
	if (cr6.lt) goto loc_821838A8;
	// cmplwi cr6,r11,90
	cr6.compare<uint32_t>(r11.u32, 90, xer);
	// bgt cr6,0x821838a8
	if (cr6.gt) goto loc_821838A8;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// b 0x821838b4
	goto loc_821838B4;
loc_821838A8:
	// cmplwi cr6,r11,92
	cr6.compare<uint32_t>(r11.u32, 92, xer);
	// bne cr6,0x821838b4
	if (!cr6.eq) goto loc_821838B4;
	// li r11,47
	r11.s64 = 47;
loc_821838B4:
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bgt 0x8218387c
	if (cr0.gt) goto loc_8218387C;
loc_821838C4:
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821838D0"))) PPC_WEAK_FUNC(sub_821838D0);
PPC_FUNC_IMPL(__imp__sub_821838D0) {
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
	// bl 0x82182470
	ctx.lr = 0x821838F0;
	sub_82182470(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82183908
	if (cr6.eq) goto loc_82183908;
	// bl 0x82130588
	ctx.lr = 0x82183904;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82183908:
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

__attribute__((alias("__imp__sub_82183920"))) PPC_WEAK_FUNC(sub_82183920);
PPC_FUNC_IMPL(__imp__sub_82183920) {
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
	ctx.lr = 0x82183928;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,52
	ctx.r3.s64 = 52;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x82130528
	ctx.lr = 0x82183944;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r30,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r30.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82430938
	ctx.lr = 0x82183980;
	sub_82430938(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r3,64
	ctx.r3.s64 = 64;
	// oris r9,r11,32
	ctx.r9.u64 = r11.u64 | 2097152;
	// rlwimi r10,r26,0,0,19
	ctx.r10.u64 = (__builtin_rotateleft32(r26.u32, 0) & 0xFFFFF000) | (ctx.r10.u64 & 0xFFFFFFFF00000FFF);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r10,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r10.u32);
	// bl 0x82130528
	ctx.lr = 0x821839A0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821839c0
	if (cr6.eq) goto loc_821839C0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82182c28
	ctx.lr = 0x821839B8;
	sub_82182C28(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_821839C0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821839CC"))) PPC_WEAK_FUNC(sub_821839CC);
PPC_FUNC_IMPL(__imp__sub_821839CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821839D0"))) PPC_WEAK_FUNC(sub_821839D0);
PPC_FUNC_IMPL(__imp__sub_821839D0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x821839D8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r11,r25,2
	r11.s64 = r25.s64 + 2;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// add r4,r11,r26
	ctx.r4.u64 = r11.u64 + r26.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
	// bl 0x821782f0
	ctx.lr = 0x82183A0C;
	sub_821782F0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82183a24
	if (cr6.eq) goto loc_82183A24;
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r29,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r29.u32);
	// stw r28,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r28.u32);
	// b 0x82183a28
	goto loc_82183A28;
loc_82183A24:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82183A28:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82183a4c
	if (cr6.eq) goto loc_82183A4C;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82183a4c
	if (cr6.eq) goto loc_82183A4C;
	// lwz r27,68(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r29,72(r30)
	PPC_STORE_U32(r30.u32 + 72, r29.u32);
	// stw r28,76(r30)
	PPC_STORE_U32(r30.u32 + 76, r28.u32);
	// b 0x82183a50
	goto loc_82183A50;
loc_82183A4C:
	// li r27,0
	r27.s64 = 0;
loc_82183A50:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82178330
	ctx.lr = 0x82183A58;
	sub_82178330(ctx, base);
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// bne cr6,0x82183b4c
	if (!cr6.eq) goto loc_82183B4C;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82183a80
	if (cr6.eq) goto loc_82183A80;
	// addi r3,r26,40
	ctx.r3.s64 = r26.s64 + 40;
	// bl 0x82177e10
	ctx.lr = 0x82183A74;
	sub_82177E10(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82177e48
	ctx.lr = 0x82183A7C;
	sub_82177E48(ctx, base);
	// stw r30,56(r26)
	PPC_STORE_U32(r26.u32 + 56, r30.u32);
loc_82183A80:
	// bl 0x821789d8
	ctx.lr = 0x82183A84;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r27,-32131
	r27.s64 = -2105737216;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82183a9c
	if (cr6.eq) goto loc_82183A9C;
	// lwz r11,17004(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 17004);
	// b 0x82183aa4
	goto loc_82183AA4;
loc_82183A9C:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17012);
loc_82183AA4:
	// stw r11,44(r26)
	PPC_STORE_U32(r26.u32 + 44, r11.u32);
	// bl 0x821789d8
	ctx.lr = 0x82183AAC;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r28,-32131
	r28.s64 = -2105737216;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82183ac4
	if (cr6.eq) goto loc_82183AC4;
	// lwz r11,17008(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 17008);
	// b 0x82183acc
	goto loc_82183ACC;
loc_82183AC4:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17016);
loc_82183ACC:
	// stw r11,48(r26)
	PPC_STORE_U32(r26.u32 + 48, r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82183b0c
	if (cr6.eq) goto loc_82183B0C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82183AEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82183B04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,17008(r28)
	PPC_STORE_U32(r28.u32 + 17008, r30.u32);
	// b 0x82183b44
	goto loc_82183B44;
loc_82183B0C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82183b48
	if (cr6.eq) goto loc_82183B48;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82183B28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82183B40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,17008(r28)
	PPC_STORE_U32(r28.u32 + 17008, r29.u32);
loc_82183B44:
	// stw r3,17004(r27)
	PPC_STORE_U32(r27.u32 + 17004, ctx.r3.u32);
loc_82183B48:
	// stb r24,4(r26)
	PPC_STORE_U8(r26.u32 + 4, r24.u8);
loc_82183B4C:
	// addi r11,r25,6
	r11.s64 = r25.s64 + 6;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r31,r10,r26
	PPC_STORE_U32(ctx.r10.u32 + r26.u32, r31.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82183B60"))) PPC_WEAK_FUNC(sub_82183B60);
PPC_FUNC_IMPL(__imp__sub_82183B60) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r7,-256
	ctx.r7.s64 = -16777216;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// lwz r8,60(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lis r6,6690
	ctx.r6.s64 = 438435840;
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stb r11,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, r11.u8);
	// stb r11,101(r1)
	PPC_STORE_U8(ctx.r1.u32 + 101, r11.u8);
	// ori r5,r6,447
	ctx.r5.u64 = ctx.r6.u64 | 447;
	// stb r11,102(r1)
	PPC_STORE_U8(ctx.r1.u32 + 102, r11.u8);
	// stb r10,103(r1)
	PPC_STORE_U8(ctx.r1.u32 + 103, ctx.r10.u8);
	// stb r10,104(r1)
	PPC_STORE_U8(ctx.r1.u32 + 104, ctx.r10.u8);
	// lwz r3,68(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 68);
	// lwz r10,40(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// cmpw cr6,r10,r5
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, xer);
	// bne cr6,0x82183bdc
	if (!cr6.eq) goto loc_82183BDC;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r10,-27692(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27692);
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
loc_82183BDC:
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// stb r11,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, r11.u8);
	// stb r11,101(r1)
	PPC_STORE_U8(ctx.r1.u32 + 101, r11.u8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82183c14
	if (cr6.eq) goto loc_82183C14;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,120(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82183C10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
loc_82183C14:
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

__attribute__((alias("__imp__sub_82183C28"))) PPC_WEAK_FUNC(sub_82183C28);
PPC_FUNC_IMPL(__imp__sub_82183C28) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82183C30"))) PPC_WEAK_FUNC(sub_82183C30);
PPC_FUNC_IMPL(__imp__sub_82183C30) {
	PPC_FUNC_PROLOGUE();
	// lhz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 56);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82183C38"))) PPC_WEAK_FUNC(sub_82183C38);
PPC_FUNC_IMPL(__imp__sub_82183C38) {
	PPC_FUNC_PROLOGUE();
	// lhz r3,58(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 58);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82183C40"))) PPC_WEAK_FUNC(sub_82183C40);
PPC_FUNC_IMPL(__imp__sub_82183C40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,68(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwimi r10,r4,20,6,11
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r4.u32, 20) & 0x3F00000) | (ctx.r10.u64 & 0xFFFFFFFFFC0FFFFF);
	// stw r10,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82183C54"))) PPC_WEAK_FUNC(sub_82183C54);
PPC_FUNC_IMPL(__imp__sub_82183C54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82183C58"))) PPC_WEAK_FUNC(sub_82183C58);
PPC_FUNC_IMPL(__imp__sub_82183C58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,68(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r3,r10,12,26,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0x3F;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82183C68"))) PPC_WEAK_FUNC(sub_82183C68);
PPC_FUNC_IMPL(__imp__sub_82183C68) {
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
	ctx.lr = 0x82183C70;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// lwz r6,80(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82183fd4
	if (cr6.eq) goto loc_82183FD4;
	// lhz r8,56(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 56);
	// li r31,0
	r31.s64 = 0;
	// lhz r7,58(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 58);
	// lwz r9,24(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// stw r31,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r31.u32);
	// stw r31,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r31.u32);
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// stw r8,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r8.u32);
	// stw r7,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r7.u32);
	// bne cr6,0x82183d7c
	if (!cr6.eq) goto loc_82183D7C;
	// lwz r9,44(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x82183cd0
	if (!cr6.gt) goto loc_82183CD0;
	// lwz r9,36(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r9,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// addi r7,r10,12
	ctx.r7.s64 = ctx.r10.s64 + 12;
	// b 0x82183cd4
	goto loc_82183CD4;
loc_82183CD0:
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
loc_82183CD4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r4,20
	ctx.r4.s64 = 20;
	// beq cr6,0x82183d48
	if (cr6.eq) goto loc_82183D48;
	// lbz r10,21(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 21);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82183cf0
	if (cr6.eq) goto loc_82183CF0;
	// li r4,532
	ctx.r4.s64 = 532;
loc_82183CF0:
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lis r9,6690
	ctx.r9.s64 = 438435840;
	// ori r8,r9,407
	ctx.r8.u64 = ctx.r9.u64 | 407;
	// lwz r10,17068(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17068);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// bne cr6,0x82183d18
	if (!cr6.eq) goto loc_82183D18;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 - ctx.f1.f64));
loc_82183D18:
	// lis r5,-32124
	ctx.r5.s64 = -2105278464;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,-28076(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -28076);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// bl 0x82420ba8
	ctx.lr = 0x82183D40;
	sub_82420BA8(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
loc_82183D48:
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f1,3796(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// bl 0x82420ba8
	ctx.lr = 0x82183D74;
	sub_82420BA8(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
loc_82183D7C:
	// cmpwi cr6,r9,5
	cr6.compare<int32_t>(ctx.r9.s32, 5, xer);
	// lwz r9,44(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// bne cr6,0x82183e50
	if (!cr6.eq) goto loc_82183E50;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x82183da4
	if (!cr6.gt) goto loc_82183DA4;
	// lwz r9,36(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r9,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// addi r7,r10,12
	ctx.r7.s64 = ctx.r10.s64 + 12;
	// b 0x82183da8
	goto loc_82183DA8;
loc_82183DA4:
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
loc_82183DA8:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r4,20
	ctx.r4.s64 = 20;
	// beq cr6,0x82183e1c
	if (cr6.eq) goto loc_82183E1C;
	// lbz r10,21(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 21);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82183dc4
	if (cr6.eq) goto loc_82183DC4;
	// li r4,532
	ctx.r4.s64 = 532;
loc_82183DC4:
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lis r9,6690
	ctx.r9.s64 = 438435840;
	// ori r8,r9,407
	ctx.r8.u64 = ctx.r9.u64 | 407;
	// lwz r10,17068(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17068);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// bne cr6,0x82183dec
	if (!cr6.eq) goto loc_82183DEC;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 - ctx.f1.f64));
loc_82183DEC:
	// lis r5,-32124
	ctx.r5.s64 = -2105278464;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,-28076(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -28076);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// bl 0x82420ba8
	ctx.lr = 0x82183E14;
	sub_82420BA8(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
loc_82183E1C:
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f1,3796(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// bl 0x82420ba8
	ctx.lr = 0x82183E48;
	sub_82420BA8(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
loc_82183E50:
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x82183e6c
	if (!cr6.gt) goto loc_82183E6C;
	// lwz r9,28(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r9,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// addi r7,r10,12
	ctx.r7.s64 = ctx.r10.s64 + 12;
	// b 0x82183e70
	goto loc_82183E70;
loc_82183E6C:
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
loc_82183E70:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// beq cr6,0x82183f9c
	if (cr6.eq) goto loc_82183F9C;
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 20);
	// addi r5,r10,23400
	ctx.r5.s64 = ctx.r10.s64 + 23400;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwzx r4,r8,r5
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r5.u32);
	// beq cr6,0x82183e98
	if (cr6.eq) goto loc_82183E98;
	// ori r4,r4,256
	ctx.r4.u64 = ctx.r4.u64 | 256;
loc_82183E98:
	// lbz r10,21(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 21);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82183ea8
	if (cr6.eq) goto loc_82183EA8;
	// ori r4,r4,512
	ctx.r4.u64 = ctx.r4.u64 | 512;
loc_82183EA8:
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82183ebc
	if (cr6.eq) goto loc_82183EBC;
	// rlwinm r10,r10,26,0,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0xFC000000;
	// or r4,r10,r4
	ctx.r4.u64 = ctx.r10.u64 | ctx.r4.u64;
loc_82183EBC:
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r29,r9,8,24,31
	r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFF;
	// rlwinm r30,r9,24,24,31
	r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFF;
	// std r29,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, r29.u64);
	// lfd f12,112(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// std r30,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, r30.u64);
	// fcfid f5,f12
	ctx.f5.f64 = double(ctx.f12.s64);
	// lwz r10,17068(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 17068);
	// lfs f0,15364(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 15364);
	f0.f64 = double(temp.f32);
	// rlwinm r8,r9,16,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFF;
	// lfd f11,112(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// clrlwi r5,r9,24
	ctx.r5.u64 = ctx.r9.u32 & 0xFF;
	// fcfid f7,f11
	ctx.f7.f64 = double(ctx.f11.s64);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// frsp f1,f5
	ctx.f1.f64 = double(float(ctx.f5.f64));
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// std r9,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r9.u64);
	// lfd f8,128(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// std r8,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r8.u64);
	// lfd f10,112(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f6,f8
	ctx.f6.f64 = double(ctx.f8.s64);
	// lis r5,6690
	ctx.r5.s64 = 438435840;
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// ori r9,r5,407
	ctx.r9.u64 = ctx.r5.u64 | 407;
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// frsp f2,f6
	ctx.f2.f64 = double(float(ctx.f6.f64));
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// frsp f4,f9
	ctx.f4.f64 = double(float(ctx.f9.f64));
	// fmuls f11,f3,f0
	ctx.f11.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfs f11,132(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// fmuls f10,f2,f0
	ctx.f10.f64 = double(float(ctx.f2.f64 * f0.f64));
	// stfs f10,128(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fmuls f9,f1,f0
	ctx.f9.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfs f9,140(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// fmuls f12,f4,f0
	ctx.f12.f64 = double(float(ctx.f4.f64 * f0.f64));
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// bne cr6,0x82183f68
	if (!cr6.eq) goto loc_82183F68;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 - ctx.f13.f64));
loc_82183F68:
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lis r30,-32124
	r30.s64 = -2105278464;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwz r9,72(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lwz r8,76(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// fmr f1,f13
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f13.f64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// lwz r3,-28076(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -28076);
	// bl 0x82420ba8
	ctx.lr = 0x82183F94;
	sub_82420BA8(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
loc_82183F9C:
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// rlwinm r30,r5,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r10,23400
	r31.s64 = ctx.r10.s64 + 23400;
	// lwz r9,72(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r8,76(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lfs f1,3796(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lwzx r4,r30,r31
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + r31.u32);
	// lwz r3,-28076(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -28076);
	// bl 0x82420ba8
	ctx.lr = 0x82183FD4;
	sub_82420BA8(ctx, base);
loc_82183FD4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82183FDC"))) PPC_WEAK_FUNC(sub_82183FDC);
PPC_FUNC_IMPL(__imp__sub_82183FDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82183FE0"))) PPC_WEAK_FUNC(sub_82183FE0);
PPC_FUNC_IMPL(__imp__sub_82183FE0) {
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
	ctx.lr = 0x82183FE8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-23040
	ctx.r3.s64 = r11.s64 + -23040;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x821378b8
	ctx.lr = 0x82184000;
	sub_821378B8(ctx, base);
	// stw r3,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r3.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82432d28
	ctx.lr = 0x82184014;
	sub_82432D28(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r29,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r29.u32);
	// lis r8,-32131
	ctx.r8.s64 = -2105737216;
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// addi r30,r31,80
	r30.s64 = r31.s64 + 80;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r5,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r5.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// sth r4,58(r31)
	PPC_STORE_U16(r31.u32 + 58, ctx.r4.u16);
	// sth r3,56(r31)
	PPC_STORE_U16(r31.u32 + 56, ctx.r3.u16);
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r29,108(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// mullw r11,r29,r11
	r11.s64 = int64_t(r29.s32) * int64_t(r11.s32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// lwz r8,17068(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 17068);
	// bl 0x82177eb0
	ctx.lr = 0x82184074;
	sub_82177EB0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x82184098
	if (!cr6.lt) goto loc_82184098;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-23096
	ctx.r3.s64 = r11.s64 + -23096;
	// bl 0x821bd618
	ctx.lr = 0x82184088;
	sub_821BD618(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
loc_82184098:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821840A8"))) PPC_WEAK_FUNC(sub_821840A8);
PPC_FUNC_IMPL(__imp__sub_821840A8) {
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
	ctx.lr = 0x821840B0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-22968
	ctx.r3.s64 = r11.s64 + -22968;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x821378b8
	ctx.lr = 0x821840C8;
	sub_821378B8(ctx, base);
	// stw r3,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r3.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82432d28
	ctx.lr = 0x821840DC;
	sub_82432D28(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lis r6,6690
	ctx.r6.s64 = 438435840;
	// lwz r4,104(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r8,120(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// addi r9,r10,-27316
	ctx.r9.s64 = ctx.r10.s64 + -27316;
	// lwz r7,108(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// addi r30,r31,80
	r30.s64 = r31.s64 + 80;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// ori r11,r6,447
	r11.u64 = ctx.r6.u64 | 447;
	// mullw r6,r7,r8
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32);
	// sth r3,56(r31)
	PPC_STORE_U16(r31.u32 + 56, ctx.r3.u16);
	// sth r4,58(r31)
	PPC_STORE_U16(r31.u32 + 58, ctx.r4.u16);
	// stw r6,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r6.u32);
	// lwz r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// stw r5,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r5.u32);
	// subfic r5,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r5.s64 = 0 - r11.s64;
	// subfe r11,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + xer.ca < xer.ca);
	r11.u64 = ~ctx.r5.u64 + ctx.r5.u64 + xer.ca;
	xer.ca = temp.u8;
	// stw r29,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r29.u32);
	// clrlwi r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	// addi r9,r11,2
	ctx.r9.s64 = r11.s64 + 2;
	// stw r9,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r9.u32);
	// bne cr6,0x82184158
	if (!cr6.eq) goto loc_82184158;
	// lis r8,6690
	ctx.r8.s64 = 438435840;
	// ori r8,r8,43869
	ctx.r8.u64 = ctx.r8.u64 | 43869;
	// b 0x8218415c
	goto loc_8218415C;
loc_82184158:
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
loc_8218415C:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82177eb0
	ctx.lr = 0x82184178;
	sub_82177EB0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x8218419c
	if (!cr6.lt) goto loc_8218419C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-23020
	ctx.r3.s64 = r11.s64 + -23020;
	// bl 0x821bd618
	ctx.lr = 0x8218418C;
	sub_821BD618(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
loc_8218419C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821841AC"))) PPC_WEAK_FUNC(sub_821841AC);
PPC_FUNC_IMPL(__imp__sub_821841AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821841B0"))) PPC_WEAK_FUNC(sub_821841B0);
PPC_FUNC_IMPL(__imp__sub_821841B0) {
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
	ctx.lr = 0x821841B8;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82182cd8
	ctx.lr = 0x821841D8;
	sub_82182CD8(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// li r26,0
	r26.s64 = 0;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lbz r10,24712(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 24712);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82184204
	if (cr6.eq) goto loc_82184204;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r10,r11,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80000000;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82184208
	if (!cr6.eq) goto loc_82184208;
loc_82184204:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_82184208:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82184218
	if (cr6.eq) goto loc_82184218;
	// ori r25,r25,32256
	r25.u64 = r25.u64 | 32256;
loc_82184218:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lbz r10,22903(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 22903);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82184234
	if (cr6.eq) goto loc_82184234;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821378b8
	ctx.lr = 0x82184230;
	sub_821378B8(ctx, base);
	// b 0x82184238
	goto loc_82184238;
loc_82184234:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_82184238:
	// stw r3,24(r30)
	PPC_STORE_U32(r30.u32 + 24, ctx.r3.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// clrlwi r27,r11,24
	r27.u64 = r11.u32 & 0xFF;
	// beq cr6,0x8218438c
	if (cr6.eq) goto loc_8218438C;
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8218438c
	if (cr6.eq) goto loc_8218438C;
	// li r3,52
	ctx.r3.s64 = 52;
	// bl 0x82130528
	ctx.lr = 0x82184260;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r29,0(r31)
	r29.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// lhz r24,2(r31)
	r24.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// bl 0x8218cd80
	ctx.lr = 0x82184274;
	sub_8218CD80(ctx, base);
	// addi r5,r3,1
	ctx.r5.s64 = ctx.r3.s64 + 1;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r27.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r26,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r26.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// stw r26,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r26.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// bl 0x82430938
	ctx.lr = 0x821842A8;
	sub_82430938(ctx, base);
	// stw r27,28(r30)
	PPC_STORE_U32(r30.u32 + 28, r27.u32);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// oris r10,r11,32
	ctx.r10.u64 = r11.u64 | 2097152;
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,12(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// addi r29,r30,28
	r29.s64 = r30.s64 + 28;
	// bl 0x82430c38
	ctx.lr = 0x821842C8;
	sub_82430C38(ctx, base);
loc_821842C8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218d798
	ctx.lr = 0x821842D0;
	sub_8218D798(ctx, base);
	// addis r11,r3,1
	r11.s64 = ctx.r3.s64 + 65536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// sth r11,14(r30)
	PPC_STORE_U16(r30.u32 + 14, r11.u16);
	// lhz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// sth r9,32(r30)
	PPC_STORE_U16(r30.u32 + 32, ctx.r9.u16);
	// lhz r8,2(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// sth r8,34(r30)
	PPC_STORE_U16(r30.u32 + 34, ctx.r8.u16);
	// bl 0x8218cd80
	ctx.lr = 0x821842F4;
	sub_8218CD80(ctx, base);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r6,r3,1
	ctx.r6.s64 = ctx.r3.s64 + 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// clrlwi r5,r6,24
	ctx.r5.u64 = ctx.r6.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,108(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 108);
	// stw r5,36(r30)
	PPC_STORE_U32(r30.u32 + 36, ctx.r5.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82184318;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r26,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r26.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r31,r26
	r31.u64 = r26.u64;
	// bl 0x82410be8
	ctx.lr = 0x82184328;
	sub_82410BE8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218437c
	if (cr6.eq) goto loc_8218437C;
loc_82184330:
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82432d28
	ctx.lr = 0x82184340;
	sub_82432D28(ctx, base);
	// lwz r10,148(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r9,144(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// lwz r8,152(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// mullw r7,r9,r10
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// lwz r6,156(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mullw r5,r7,r8
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32);
	// mullw r10,r5,r6
	ctx.r10.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// stw r4,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r4.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82410be8
	ctx.lr = 0x82184374;
	sub_82410BE8(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// blt cr6,0x82184330
	if (cr6.lt) goto loc_82184330;
loc_8218437C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r11,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r11.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9230
	return;
loc_8218438C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r28,0(r31)
	r28.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// lhz r23,14(r31)
	r23.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// addi r29,r30,28
	r29.s64 = r30.s64 + 28;
	// lhz r22,2(r31)
	r22.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// bl 0x8218cd80
	ctx.lr = 0x821843A4;
	sub_8218CD80(ctx, base);
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// addi r6,r3,1
	ctx.r6.s64 = ctx.r3.s64 + 1;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r7,4
	ctx.r7.s64 = 4;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// clrlwi r10,r27,24
	ctx.r10.u64 = r27.u32 & 0xFF;
	// bl 0x82177eb0
	ctx.lr = 0x821843CC;
	sub_82177EB0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x821842c8
	if (!cr6.lt) goto loc_821842C8;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lhz r6,14(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// lhz r5,2(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// addi r3,r11,-22944
	ctx.r3.s64 = r11.s64 + -22944;
	// lhz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// bl 0x82130000
	ctx.lr = 0x821843F0;
	sub_82130000(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_821843F8"))) PPC_WEAK_FUNC(sub_821843F8);
PPC_FUNC_IMPL(__imp__sub_821843F8) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// addi r9,r11,-23460
	ctx.r9.s64 = r11.s64 + -23460;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8218442c
	if (cr6.eq) goto loc_8218442C;
	// bl 0x82177cb0
	ctx.lr = 0x8218442C;
	sub_82177CB0(ctx, base);
loc_8218442C:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218443c
	if (cr6.eq) goto loc_8218443C;
	// bl 0x82130588
	ctx.lr = 0x8218443C;
	sub_82130588(ctx, base);
loc_8218443C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218fd70
	ctx.lr = 0x82184444;
	sub_8218FD70(ctx, base);
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

__attribute__((alias("__imp__sub_82184458"))) PPC_WEAK_FUNC(sub_82184458);
PPC_FUNC_IMPL(__imp__sub_82184458) {
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
	ctx.lr = 0x82184460;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// bl 0x8218fd80
	ctx.lr = 0x82184470;
	sub_8218FD80(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r10,r11,-23460
	ctx.r10.s64 = r11.s64 + -23460;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8218449c
	if (cr6.eq) goto loc_8218449C;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8217d890
	ctx.lr = 0x82184490;
	sub_8217D890(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
loc_8218449C:
	// lwz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821844bc
	if (cr6.eq) goto loc_821844BC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8217d890
	ctx.lr = 0x821844B0;
	sub_8217D890(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
loc_821844BC:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r30,0(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// rlwinm r29,r10,0,0,19
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFF000;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8217d828
	ctx.lr = 0x821844D8;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82184500
	if (cr6.eq) goto loc_82184500;
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
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// b 0x82184518
	goto loc_82184518;
loc_82184500:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r11,-26560
	ctx.r4.s64 = r11.s64 + -26560;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821d2378
	ctx.lr = 0x82184514;
	sub_821D2378(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
loc_82184518:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// srawi r10,r10,12
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 12;
	// rlwinm r9,r10,12,0,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFFF000;
	// lwz r8,32(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// rlwinm r10,r8,0,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFF000;
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwimi r7,r8,0,20,31
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r8.u32, 0) & 0xFFF) | (ctx.r7.u64 & 0xFFFFFFFFFFFFF000);
	// stw r7,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r7.u32);
	// lwz r6,28(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r5,48(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 48);
	// rlwinm r11,r5,20,12,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 20) & 0xFFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82184574
	if (cr6.eq) goto loc_82184574;
	// rlwinm r4,r11,12,0,19
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFFFF000;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8217d890
	ctx.lr = 0x82184558;
	sub_8217D890(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// srawi r10,r3,12
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 12;
	// rlwinm r9,r10,12,0,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFFF000;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwimi r9,r10,0,20,31
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFFF) | (ctx.r9.u64 & 0xFFFFFFFFFFFFF000);
	// stw r9,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r9.u32);
loc_82184574:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82184588"))) PPC_WEAK_FUNC(sub_82184588);
PPC_FUNC_IMPL(__imp__sub_82184588) {
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
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x82184590;
	// stfd f30,-128(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -128, f30.u64);
	// stfd f31,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, f31.u64);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821845BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x8218497c
	if (cr6.eq) goto loc_8218497C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// stw r29,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r29.u32);
	// lfs f30,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
	// stw r29,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r29.u32);
	// lfs f31,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f31.f64 = double(temp.f32);
	// stfs f30,136(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f30,140(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f31,128(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f31,132(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// ble cr6,0x82184610
	if (!cr6.gt) goto loc_82184610;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// addi r28,r11,12
	r28.s64 = r11.s64 + 12;
	// b 0x82184614
	goto loc_82184614;
loc_82184610:
	// addi r28,r1,144
	r28.s64 = ctx.r1.s64 + 144;
loc_82184614:
	// bl 0x821789d8
	ctx.lr = 0x82184618;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82184630
	if (cr6.eq) goto loc_82184630;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17004);
	// b 0x82184638
	goto loc_82184638;
loc_82184630:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r11,17012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17012);
loc_82184638:
	// lhz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 56);
	// li r19,1
	r19.s64 = 1;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bgt cr6,0x8218465c
	if (cr6.gt) goto loc_8218465C;
	// bl 0x821771e8
	ctx.lr = 0x8218464C;
	sub_821771E8(ctx, base);
	// lhz r11,58(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 58);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// ble cr6,0x82184660
	if (!cr6.gt) goto loc_82184660;
loc_8218465C:
	// mr r11,r19
	r11.u64 = r19.u64;
loc_82184660:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// stw r29,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r29.u32);
	// mr r20,r11
	r20.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82184694
	if (cr6.eq) goto loc_82184694;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821782f0
	ctx.lr = 0x82184680;
	sub_821782F0(ctx, base);
	// stw r29,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r29.u32);
	// stw r29,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r29.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x82178330
	ctx.lr = 0x82184694;
	sub_82178330(ctx, base);
loc_82184694:
	// ld r11,0(r28)
	r11.u64 = PPC_LOAD_U64(r28.u32 + 0);
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// lhz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 56);
	// lhz r9,58(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 58);
	// stw r29,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r29.u32);
	// stw r29,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r29.u32);
	// std r11,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, r11.u64);
	// stw r10,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r10.u32);
	// stw r9,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r9.u32);
	// beq cr6,0x821846dc
	if (cr6.eq) goto loc_821846DC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,136
	ctx.r5.s64 = ctx.r1.s64 + 136;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,148(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 148);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821846DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821846DC:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82184760
	if (cr6.eq) goto loc_82184760;
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// rlwinm r6,r11,8,24,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFF;
	// rlwinm r5,r11,16,24,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF;
	// rlwinm r4,r11,24,24,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// std r6,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r6.u64);
	// lfd f13,144(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// std r5,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r5.u64);
	// std r4,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r4.u64);
	// lfd f12,152(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// lfd f11,144(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// fcfid f6,f13
	ctx.f6.f64 = double(ctx.f13.s64);
	// lfs f0,15364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15364);
	f0.f64 = double(temp.f32);
	// std r11,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, r11.u64);
	// lfd f10,152(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// fcfid f7,f12
	ctx.f7.f64 = double(ctx.f12.s64);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
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
	// stfs f1,184(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// fmuls f13,f4,f0
	ctx.f13.f64 = double(float(ctx.f4.f64 * f0.f64));
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// fmuls f12,f3,f0
	ctx.f12.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfs f12,176(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// fmuls f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 * f0.f64));
	// stfs f11,188(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
loc_82184760:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r22,r11,-25200
	r22.s64 = r11.s64 + -25200;
	// lbz r11,112(r22)
	r11.u64 = PPC_LOAD_U8(r22.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8218477c
	if (!cr6.eq) goto loc_8218477C;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x821804a8
	ctx.lr = 0x8218477C;
	sub_821804A8(ctx, base);
loc_8218477C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82184790;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// mr r30,r19
	r30.u64 = r19.u64;
	// cmplwi cr6,r21,1
	cr6.compare<uint32_t>(r21.u32, 1, xer);
	// ble cr6,0x82184960
	if (!cr6.gt) goto loc_82184960;
	// lis r10,6690
	ctx.r10.s64 = 438435840;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// ori r25,r10,407
	r25.u64 = ctx.r10.u64 | 407;
	// lis r28,-32124
	r28.s64 = -2105278464;
	// lis r23,-32131
	r23.s64 = -2105737216;
	// addi r26,r11,23416
	r26.s64 = r11.s64 + 23416;
loc_821847B8:
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r10,124(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// lwz r9,168(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// srawi r8,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r8.s64 = r11.s32 >> 1;
	// srawi r7,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 1;
	// srawi r11,r9,1
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	r11.s64 = ctx.r9.s32 >> 1;
	// stw r8,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
	// stw r7,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// stw r11,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r11.u32);
	// bgt cr6,0x821847e8
	if (cr6.gt) goto loc_821847E8;
	// stw r19,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r19.u32);
loc_821847E8:
	// lwz r11,172(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// srawi r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// stw r11,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r11.u32);
	// bgt cr6,0x82184800
	if (cr6.gt) goto loc_82184800;
	// stw r19,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r19.u32);
loc_82184800:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,136
	ctx.r7.s64 = ctx.r1.s64 + 136;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82181560
	ctx.lr = 0x82184820;
	sub_82181560(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// beq cr6,0x821848d4
	if (cr6.eq) goto loc_821848D4;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x821848d4
	if (cr6.eq) goto loc_821848D4;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8218489c
	if (cr6.eq) goto loc_8218489C;
	// lwz r11,17068(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 17068);
	// lfs f1,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// cmpw cr6,r11,r25
	cr6.compare<int32_t>(r11.s32, r25.s32, xer);
	// bne cr6,0x82184850
	if (!cr6.eq) goto loc_82184850;
	// fsubs f1,f31,f1
	ctx.f1.f64 = double(float(f31.f64 - ctx.f1.f64));
loc_82184850:
	// lbz r11,20(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 20);
	// rlwinm r8,r24,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,12(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// subfic r5,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r5.s64 = 0 - r11.s64;
	// lwz r3,-28076(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -28076);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r6,80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// subfe r4,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + xer.ca < xer.ca);
	ctx.r4.u64 = ~ctx.r5.u64 + ctx.r5.u64 + xer.ca;
	xer.ca = temp.u8;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// lwzx r11,r8,r26
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + r26.u32);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// rlwinm r4,r4,0,23,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x100;
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// addi r7,r1,120
	ctx.r7.s64 = ctx.r1.s64 + 120;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// or r4,r4,r11
	ctx.r4.u64 = ctx.r4.u64 | r11.u64;
	// bl 0x82420ba8
	ctx.lr = 0x82184898;
	sub_82420BA8(ctx, base);
	// b 0x82184954
	goto loc_82184954;
loc_8218489C:
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// rlwinm r11,r24,2,0,29
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,-28076(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -28076);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r6,80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r7,r1,120
	ctx.r7.s64 = ctx.r1.s64 + 120;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lwzx r4,r11,r26
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r26.u32);
	// bl 0x82420ba8
	ctx.lr = 0x821848D0;
	sub_82420BA8(ctx, base);
	// b 0x82184954
	goto loc_82184954;
loc_821848D4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82184924
	if (cr6.eq) goto loc_82184924;
	// lwz r11,17068(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 17068);
	// lfs f1,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// cmpw cr6,r11,r25
	cr6.compare<int32_t>(r11.s32, r25.s32, xer);
	// bne cr6,0x821848f0
	if (!cr6.eq) goto loc_821848F0;
	// fsubs f1,f31,f1
	ctx.f1.f64 = double(float(f31.f64 - ctx.f1.f64));
loc_821848F0:
	// lwz r11,12(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,-28076(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -28076);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// lwz r6,80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// bl 0x82420ba8
	ctx.lr = 0x82184920;
	sub_82420BA8(ctx, base);
	// b 0x82184954
	goto loc_82184954;
loc_82184924:
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,-28076(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -28076);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r6,80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x82420ba8
	ctx.lr = 0x82184954;
	sub_82420BA8(ctx, base);
loc_82184954:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplw cr6,r30,r21
	cr6.compare<uint32_t>(r30.u32, r21.u32, xer);
	// blt cr6,0x821847b8
	if (cr6.lt) goto loc_821847B8;
loc_82184960:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x8218497c
	if (cr6.eq) goto loc_8218497C;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r4,112(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// bl 0x82178330
	ctx.lr = 0x82184974;
	sub_82178330(ctx, base);
	// lwz r3,112(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// bl 0x824221d8
	ctx.lr = 0x8218497C;
	sub_824221D8(ctx, base);
loc_8218497C:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// lfd f30,-128(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f31,-120(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_8218498C"))) PPC_WEAK_FUNC(sub_8218498C);
PPC_FUNC_IMPL(__imp__sub_8218498C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82184990"))) PPC_WEAK_FUNC(sub_82184990);
PPC_FUNC_IMPL(__imp__sub_82184990) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82184998;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// li r27,0
	r27.s64 = 0;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f31,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f31.f64 = double(temp.f32);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// stfs f0,120(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f31,112(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ble cr6,0x821849f0
	if (!cr6.gt) goto loc_821849F0;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// addi r28,r11,12
	r28.s64 = r11.s64 + 12;
	// b 0x821849f4
	goto loc_821849F4;
loc_821849F0:
	// mr r28,r27
	r28.u64 = r27.u64;
loc_821849F4:
	// lhz r11,56(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 56);
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// lhz r10,58(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 58);
	// stw r27,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r27.u32);
	// stw r27,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r27.u32);
	// stw r11,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r11.u32);
	// stw r10,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r10.u32);
	// beq cr6,0x82184a30
	if (cr6.eq) goto loc_82184A30;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,148(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 148);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82184A30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82184A30:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82184ab4
	if (cr6.eq) goto loc_82184AB4;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// rlwinm r6,r11,8,24,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFF;
	// rlwinm r5,r11,16,24,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF;
	// rlwinm r4,r11,24,24,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// std r6,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r6.u64);
	// lfd f13,128(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// std r5,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r5.u64);
	// std r4,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r4.u64);
	// lfd f12,136(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// lfd f11,128(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// fcfid f6,f13
	ctx.f6.f64 = double(ctx.f13.s64);
	// lfs f0,15364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15364);
	f0.f64 = double(temp.f32);
	// std r11,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, r11.u64);
	// lfd f10,136(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// fcfid f7,f12
	ctx.f7.f64 = double(ctx.f12.s64);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
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
	// stfs f1,152(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// fmuls f13,f4,f0
	ctx.f13.f64 = double(float(ctx.f4.f64 * f0.f64));
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// fmuls f12,f3,f0
	ctx.f12.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// fmuls f11,f2,f0
	ctx.f11.f64 = double(float(ctx.f2.f64 * f0.f64));
	// stfs f11,156(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
loc_82184AB4:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r30,r11,-25200
	r30.s64 = r11.s64 + -25200;
	// lbz r11,112(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82184ad0
	if (!cr6.eq) goto loc_82184AD0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821804a8
	ctx.lr = 0x82184AD0;
	sub_821804A8(ctx, base);
loc_82184AD0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82180be0
	ctx.lr = 0x82184AE8;
	sub_82180BE0(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,6690
	ctx.r10.s64 = 438435840;
	// lfs f1,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// ori r9,r10,407
	ctx.r9.u64 = ctx.r10.u64 | 407;
	// lwz r11,17068(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17068);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bne cr6,0x82184b08
	if (!cr6.eq) goto loc_82184B08;
	// fsubs f1,f31,f1
	ctx.f1.f64 = double(float(f31.f64 - ctx.f1.f64));
loc_82184B08:
	// lbz r11,20(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 20);
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// lwz r5,12(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// subfic r4,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r4.s64 = 0 - r11.s64;
	// lwz r6,80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// subfe r11,r4,r4
	temp.u8 = (~ctx.r4.u32 + ctx.r4.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r4.u32 + xer.ca < xer.ca);
	r11.u64 = ~ctx.r4.u64 + ctx.r4.u64 + xer.ca;
	xer.ca = temp.u8;
	// lwz r3,-28076(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -28076);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r5,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r5.u32);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// rlwinm r4,r11,0,23,23
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x100;
	// bl 0x82420ba8
	ctx.lr = 0x82184B48;
	sub_82420BA8(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82184B54"))) PPC_WEAK_FUNC(sub_82184B54);
PPC_FUNC_IMPL(__imp__sub_82184B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82184B58"))) PPC_WEAK_FUNC(sub_82184B58);
PPC_FUNC_IMPL(__imp__sub_82184B58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r24{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bge cr6,0x82184bf8
	if (!cr6.lt) goto loc_82184BF8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,0(r5)
	PPC_STORE_U64(ctx.r5.u32 + 0, ctx.r10.u64);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82184BA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r7,r3
	ctx.r7.s64 = ctx.r3.s32;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lwz r5,24(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// frsp f31,f13
	f31.f64 = double(float(ctx.f13.f64));
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82184BD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// extsw r4,r3
	ctx.r4.s64 = ctx.r3.s32;
	// stfs f31,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// std r4,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r4.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r3,0(r30)
	PPC_STORE_U64(r30.u32 + 0, ctx.r3.u64);
	// b 0x82184e24
	goto loc_82184E24;
loc_82184BF8:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x82184e18
	if (cr6.gt) goto loc_82184E18;
	// lis r12,-32232
	r12.s64 = -2112356352;
	// addi r12,r12,19484
	r12.s64 = r12.s64 + 19484;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82184D38;
	case 1:
		goto loc_82184D38;
	case 2:
		goto loc_82184E18;
	case 3:
		goto loc_82184D38;
	case 4:
		goto loc_82184E18;
	case 5:
		goto loc_82184C34;
	default:
		__builtin_unreachable();
	}
	// lwz r16,19768(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 19768);
	// lwz r16,19768(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 19768);
	// lwz r16,19992(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 19992);
	// lwz r16,19768(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 19768);
	// lwz r16,19992(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 19992);
	// lwz r16,19508(r24)
	r16.u64 = PPC_LOAD_U32(r24.u32 + 19508);
loc_82184C34:
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x82184c8c
	if (!cr6.gt) goto loc_82184C8C;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// lwz r6,12(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// extsw r3,r7
	ctx.r3.s64 = ctx.r7.s32;
	// extsw r10,r6
	ctx.r10.s64 = ctx.r6.s32;
	// std r3,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r3.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// stfs f9,84(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// b 0x82184c9c
	goto loc_82184C9C;
loc_82184C8C:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
loc_82184C9C:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// stfs f13,4(r5)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x82184d14
	if (!cr6.gt) goto loc_82184D14;
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r6,8(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// extsw r4,r6
	ctx.r4.s64 = ctx.r6.s32;
	// std r5,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r5.u64);
	// lfd f0,88(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r4,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r4.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// stfs f10,84(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// stfs f13,4(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// b 0x82184e24
	goto loc_82184E24;
loc_82184D14:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,4(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// b 0x82184e24
	goto loc_82184E24;
loc_82184D38:
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x82184d90
	if (!cr6.gt) goto loc_82184D90;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r6,16(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// lwz r7,12(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// extsw r10,r6
	ctx.r10.s64 = ctx.r6.s32;
	// extsw r3,r7
	ctx.r3.s64 = ctx.r7.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r3,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r3.u64);
	// lfd f0,88(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// stfs f9,84(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// b 0x82184da0
	goto loc_82184DA0;
loc_82184D90:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
loc_82184DA0:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// stfs f13,4(r5)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x82184d14
	if (!cr6.gt) goto loc_82184D14;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r6,8(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// extsw r4,r6
	ctx.r4.s64 = ctx.r6.s32;
	// extsw r5,r7
	ctx.r5.s64 = ctx.r7.s32;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// std r5,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r5.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// lfd f0,88(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// stfs f9,84(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,4(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// b 0x82184e24
	goto loc_82184E24;
loc_82184E18:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-22876
	ctx.r3.s64 = r11.s64 + -22876;
	// bl 0x821bd618
	ctx.lr = 0x82184E24;
	sub_821BD618(ctx, base);
loc_82184E24:
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

__attribute__((alias("__imp__sub_82184E40"))) PPC_WEAK_FUNC(sub_82184E40);
PPC_FUNC_IMPL(__imp__sub_82184E40) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-23260
	ctx.r10.s64 = r11.s64 + -23260;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x82130588
	ctx.lr = 0x82184E70;
	sub_82130588(ctx, base);
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82184e84
	if (cr6.eq) goto loc_82184E84;
	// bl 0x82177cb0
	ctx.lr = 0x82184E84;
	sub_82177CB0(ctx, base);
loc_82184E84:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r3,r31,68
	ctx.r3.s64 = r31.s64 + 68;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82184e98
	if (cr6.eq) goto loc_82184E98;
	// bl 0x82177d90
	ctx.lr = 0x82184E98;
	sub_82177D90(ctx, base);
loc_82184E98:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82182188
	ctx.lr = 0x82184EA0;
	sub_82182188(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82184eb8
	if (cr6.eq) goto loc_82184EB8;
	// bl 0x82130588
	ctx.lr = 0x82184EB4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82184EB8:
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

__attribute__((alias("__imp__sub_82184ED0"))) PPC_WEAK_FUNC(sub_82184ED0);
PPC_FUNC_IMPL(__imp__sub_82184ED0) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r9,r11,-23460
	ctx.r9.s64 = r11.s64 + -23460;
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82184f0c
	if (cr6.eq) goto loc_82184F0C;
	// bl 0x82177cb0
	ctx.lr = 0x82184F0C;
	sub_82177CB0(ctx, base);
loc_82184F0C:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82184f1c
	if (cr6.eq) goto loc_82184F1C;
	// bl 0x82130588
	ctx.lr = 0x82184F1C;
	sub_82130588(ctx, base);
loc_82184F1C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218fd70
	ctx.lr = 0x82184F24;
	sub_8218FD70(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82184f3c
	if (cr6.eq) goto loc_82184F3C;
	// bl 0x82130588
	ctx.lr = 0x82184F38;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82184F3C:
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

__attribute__((alias("__imp__sub_82184F54"))) PPC_WEAK_FUNC(sub_82184F54);
PPC_FUNC_IMPL(__imp__sub_82184F54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82184F58"))) PPC_WEAK_FUNC(sub_82184F58);
PPC_FUNC_IMPL(__imp__sub_82184F58) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82184F60;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// bl 0x8218fd18
	ctx.lr = 0x82184F74;
	sub_8218FD18(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r31,0
	r31.s64 = 0;
	// addi r10,r11,-23460
	ctx.r10.s64 = r11.s64 + -23460;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// bl 0x821bbea8
	ctx.lr = 0x82184F88;
	sub_821BBEA8(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r11,r29
	r11.u64 = r29.u64;
	// addi r10,r10,-25064
	ctx.r10.s64 = ctx.r10.s64 + -25064;
loc_82184F94:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82184fb8
	if (cr6.eq) goto loc_82184FB8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82184f94
	if (cr6.eq) goto loc_82184F94;
loc_82184FB8:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r30,r11,-25076
	r30.s64 = r11.s64 + -25076;
	// beq cr6,0x82185008
	if (cr6.eq) goto loc_82185008;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82184FD0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82184ff4
	if (cr6.eq) goto loc_82184FF4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82184fd0
	if (cr6.eq) goto loc_82184FD0;
loc_82184FF4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82185008
	if (cr6.eq) goto loc_82185008;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218eda8
	ctx.lr = 0x82185004;
	sub_8218EDA8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_82185008:
	// bl 0x821bbf00
	ctx.lr = 0x8218500C;
	sub_821BBF00(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8218506c
	if (cr6.eq) goto loc_8218506C;
	// lhz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// lhz r6,2(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// clrlwi r11,r5,30
	r11.u64 = ctx.r5.u32 & 0x3;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82185034
	if (!cr6.eq) goto loc_82185034;
	// clrlwi r11,r6,30
	r11.u64 = ctx.r6.u32 & 0x3;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821850f8
	if (cr6.eq) goto loc_821850F8;
loc_82185034:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,-22816
	ctx.r3.s64 = r11.s64 + -22816;
	// bl 0x82130000
	ctx.lr = 0x82185044;
	sub_82130000(ctx, base);
	// bl 0x821bbea8
	ctx.lr = 0x82185048;
	sub_821BBEA8(ctx, base);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// bne 0x82185068
	if (!cr0.eq) goto loc_82185068;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218cd10
	ctx.lr = 0x82185060;
	sub_8218CD10(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82185068;
	sub_82130588(ctx, base);
loc_82185068:
	// bl 0x821bbf00
	ctx.lr = 0x8218506C;
	sub_821BBF00(ctx, base);
loc_8218506C:
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82185074:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82185098
	if (cr6.eq) goto loc_82185098;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82185074
	if (cr6.eq) goto loc_82185074;
loc_82185098:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x821850a8
	if (cr6.eq) goto loc_821850A8;
	// li r30,-1
	r30.s64 = -1;
	// b 0x821850b0
	goto loc_821850B0;
loc_821850A8:
	// lis r30,16639
	r30.s64 = 1090453504;
	// ori r30,r30,65535
	r30.u64 = r30.u64 | 65535;
loc_821850B0:
	// bl 0x821bbea8
	ctx.lr = 0x821850B4;
	sub_821BBEA8(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,32
	ctx.r4.s64 = 32;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x8218de38
	ctx.lr = 0x821850D8;
	sub_8218DE38(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x821bbf00
	ctx.lr = 0x821850E0;
	sub_821BBF00(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r10,1024
	ctx.r10.s64 = 1024;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_821850EC:
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x821850ec
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_821850EC;
loc_821850F8:
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821841b0
	ctx.lr = 0x8218510C;
	sub_821841B0(ctx, base);
	// bl 0x821bbea8
	ctx.lr = 0x82185110;
	sub_821BBEA8(ctx, base);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// bne 0x82185130
	if (!cr0.eq) goto loc_82185130;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218cd10
	ctx.lr = 0x82185128;
	sub_8218CD10(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82185130;
	sub_82130588(ctx, base);
loc_82185130:
	// bl 0x821bbf00
	ctx.lr = 0x82185134;
	sub_821BBF00(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82185140"))) PPC_WEAK_FUNC(sub_82185140);
PPC_FUNC_IMPL(__imp__sub_82185140) {
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
	ctx.lr = 0x82185148;
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
	// bl 0x8218fd18
	ctx.lr = 0x8218515C;
	sub_8218FD18(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r9,r11,-23460
	ctx.r9.s64 = r11.s64 + -23460;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r4,r10,-22752
	ctx.r4.s64 = ctx.r10.s64 + -22752;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x821841b0
	ctx.lr = 0x82185180;
	sub_821841B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8218518C"))) PPC_WEAK_FUNC(sub_8218518C);
PPC_FUNC_IMPL(__imp__sub_8218518C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82185190"))) PPC_WEAK_FUNC(sub_82185190);
PPC_FUNC_IMPL(__imp__sub_82185190) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// lhz r11,12(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x821851c0
	if (cr6.lt) goto loc_821851C0;
	// beqlr cr6
	if (cr6.eq) return;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x821851bc
	if (cr6.lt) goto loc_821851BC;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// addi r3,r10,-22744
	ctx.r3.s64 = ctx.r10.s64 + -22744;
	// b 0x821bd618
	sub_821BD618(ctx, base);
	return;
loc_821851BC:
	// b 0x8218fbb0
	sub_8218FBB0(ctx, base);
	return;
loc_821851C0:
	// b 0x82184458
	sub_82184458(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821851C4"))) PPC_WEAK_FUNC(sub_821851C4);
PPC_FUNC_IMPL(__imp__sub_821851C4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821851C8"))) PPC_WEAK_FUNC(sub_821851C8);
PPC_FUNC_IMPL(__imp__sub_821851C8) {
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
	ctx.lr = 0x821851D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// li r4,16
	ctx.r4.s64 = 16;
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// addi r3,r11,-25072
	ctx.r3.s64 = r11.s64 + -25072;
	// stw r28,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r28.u32);
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// bl 0x8262e420
	ctx.lr = 0x82185200;
	sub_8262E420(ctx, base);
	// lwz r11,212(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82185218
	if (cr6.eq) goto loc_82185218;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// b 0x8218522c
	goto loc_8218522C;
loc_82185218:
	// lis r4,-17280
	ctx.r4.s64 = -1132462080;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// ori r4,r4,16384
	ctx.r4.u64 = ctx.r4.u64 | 16384;
	// bl 0x82130b50
	ctx.lr = 0x82185228;
	sub_82130B50(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
loc_8218522C:
	// lis r11,16383
	r11.s64 = 1073676288;
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// li r27,-1
	r27.s64 = -1;
	// ori r29,r11,65535
	r29.u64 = r11.u64 | 65535;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// ble cr6,0x8218524c
	if (!cr6.gt) goto loc_8218524C;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_8218524C:
	// bl 0x82130528
	ctx.lr = 0x82185250;
	sub_82130528(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x82185264
	if (!cr6.gt) goto loc_82185264;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_82185264:
	// bl 0x82130528
	ctx.lr = 0x82185268;
	sub_82130528(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82185298
	if (!cr6.gt) goto loc_82185298;
	// mr r11,r28
	r11.u64 = r28.u64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
loc_8218527C:
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stwx r28,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r28.u32);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stwx r28,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, r28.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8218527c
	if (!cr0.eq) goto loc_8218527C;
loc_82185298:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821852A4"))) PPC_WEAK_FUNC(sub_821852A4);
PPC_FUNC_IMPL(__imp__sub_821852A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821852A8"))) PPC_WEAK_FUNC(sub_821852A8);
PPC_FUNC_IMPL(__imp__sub_821852A8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x821852C4;
	sub_82130588(ctx, base);
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,-25072
	ctx.r3.s64 = r11.s64 + -25072;
	// bl 0x824a30d0
	ctx.lr = 0x821852D8;
	sub_824A30D0(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82132608
	ctx.lr = 0x821852E0;
	sub_82132608(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x821852E8;
	sub_82130588(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x821852F0;
	sub_82130588(ctx, base);
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

__attribute__((alias("__imp__sub_82185304"))) PPC_WEAK_FUNC(sub_82185304);
PPC_FUNC_IMPL(__imp__sub_82185304) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82185308"))) PPC_WEAK_FUNC(sub_82185308);
PPC_FUNC_IMPL(__imp__sub_82185308) {
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
	// bne cr6,0x8218534c
	if (!cr6.eq) goto loc_8218534C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x82185344
	if (cr6.eq) goto loc_82185344;
	// bl 0x82195e48
	ctx.lr = 0x82185340;
	sub_82195E48(ctx, base);
	// b 0x82185348
	goto loc_82185348;
loc_82185344:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82185348:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_8218534C:
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

__attribute__((alias("__imp__sub_82185368"))) PPC_WEAK_FUNC(sub_82185368);
PPC_FUNC_IMPL(__imp__sub_82185368) {
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
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82183870
	ctx.lr = 0x82185390;
	sub_82183870(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821811c0
	ctx.lr = 0x8218539C;
	sub_821811C0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x821853f4
	if (!cr6.eq) goto loc_821853F4;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x821853AC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821853c8
	if (cr6.eq) goto loc_821853C8;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82184f58
	ctx.lr = 0x821853C0;
	sub_82184F58(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x821853cc
	goto loc_821853CC;
loc_821853C8:
	// li r31,0
	r31.s64 = 0;
loc_821853CC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821853E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x821853f4
	if (!cr6.eq) goto loc_821853F4;
	// bl 0x82177a08
	ctx.lr = 0x821853F0;
	sub_82177A08(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_821853F4:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
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

__attribute__((alias("__imp__sub_8218540C"))) PPC_WEAK_FUNC(sub_8218540C);
PPC_FUNC_IMPL(__imp__sub_8218540C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82185410"))) PPC_WEAK_FUNC(sub_82185410);
PPC_FUNC_IMPL(__imp__sub_82185410) {
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
	ctx.lr = 0x82185418;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,64
	ctx.r3.s64 = 64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x82130528
	ctx.lr = 0x8218542C;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82185464
	if (cr6.eq) goto loc_82185464;
	// bl 0x8218fd18
	ctx.lr = 0x8218543C;
	sub_8218FD18(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r9,r11,-23460
	ctx.r9.s64 = r11.s64 + -23460;
	// addi r4,r10,-22752
	ctx.r4.s64 = ctx.r10.s64 + -22752;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821841b0
	ctx.lr = 0x82185460;
	sub_821841B0(ctx, base);
	// b 0x82185468
	goto loc_82185468;
loc_82185464:
	// li r31,0
	r31.s64 = 0;
loc_82185468:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8218547C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x821854b8
	if (!cr6.eq) goto loc_821854B8;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x8218548C;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x821854ac
	if (!cr6.eq) goto loc_821854AC;
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
	ctx.lr = 0x821854AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_821854AC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821854B8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821854C4"))) PPC_WEAK_FUNC(sub_821854C4);
PPC_FUNC_IMPL(__imp__sub_821854C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821854C8"))) PPC_WEAK_FUNC(sub_821854C8);
PPC_FUNC_IMPL(__imp__sub_821854C8) {
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
	// bl 0x821d2970
	ctx.lr = 0x821854E0;
	sub_821D2970(ctx, base);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r8,r9,-24860
	ctx.r8.s64 = ctx.r9.s64 + -24860;
	// sth r11,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r11.u16);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// sth r10,12(r31)
	PPC_STORE_U16(r31.u32 + 12, ctx.r10.u16);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// sth r11,32(r31)
	PPC_STORE_U16(r31.u32 + 32, r11.u16);
	// sth r11,34(r31)
	PPC_STORE_U16(r31.u32 + 34, r11.u16);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// sth r11,40(r31)
	PPC_STORE_U16(r31.u32 + 40, r11.u16);
	// sth r11,42(r31)
	PPC_STORE_U16(r31.u32 + 42, r11.u16);
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

__attribute__((alias("__imp__sub_82185538"))) PPC_WEAK_FUNC(sub_82185538);
PPC_FUNC_IMPL(__imp__sub_82185538) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x821854c8
	ctx.lr = 0x82185558;
	sub_821854C8(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r9,r11,-23260
	ctx.r9.s64 = r11.s64 + -23260;
	// addi r3,r10,-22680
	ctx.r3.s64 = ctx.r10.s64 + -22680;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// bl 0x821378b8
	ctx.lr = 0x82185570;
	sub_821378B8(ctx, base);
	// stw r3,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r3.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82432d28
	ctx.lr = 0x8218558C;
	sub_82432D28(ctx, base);
	// lwz r8,116(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r7,112(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// li r30,1
	r30.s64 = 1;
	// lwz r6,120(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// mullw r5,r7,r8
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32);
	// lwz r4,124(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// sth r11,56(r31)
	PPC_STORE_U16(r31.u32 + 56, r11.u16);
	// sth r10,58(r31)
	PPC_STORE_U16(r31.u32 + 58, ctx.r10.u16);
	// mullw r9,r5,r6
	ctx.r9.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// mullw r8,r9,r4
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r4.s32);
	// stw r8,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r8.u32);
	// bl 0x82410be8
	ctx.lr = 0x821855C8;
	sub_82410BE8(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// ble cr6,0x8218561c
	if (!cr6.gt) goto loc_8218561C;
loc_821855D0:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82432d28
	ctx.lr = 0x821855E0;
	sub_82432D28(ctx, base);
	// lwz r10,116(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r9,112(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lwz r8,120(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// mullw r7,r9,r10
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// lwz r6,124(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mullw r5,r7,r8
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32);
	// mullw r10,r5,r6
	ctx.r10.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// stw r4,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r4.u32);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// bl 0x82410be8
	ctx.lr = 0x82185614;
	sub_82410BE8(ctx, base);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// blt cr6,0x821855d0
	if (cr6.lt) goto loc_821855D0;
loc_8218561C:
	// li r11,2
	r11.s64 = 2;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_82185648"))) PPC_WEAK_FUNC(sub_82185648);
PPC_FUNC_IMPL(__imp__sub_82185648) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82185650;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r17,r5
	r17.u64 = ctx.r5.u64;
	// mr r21,r6
	r21.u64 = ctx.r6.u64;
	// mr r20,r7
	r20.u64 = ctx.r7.u64;
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// mr r31,r9
	r31.u64 = ctx.r9.u64;
	// bl 0x821854c8
	ctx.lr = 0x82185674;
	sub_821854C8(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r10,r11,-23260
	ctx.r10.s64 = r11.s64 + -23260;
	// stw r10,0(r19)
	PPC_STORE_U32(r19.u32 + 0, ctx.r10.u32);
	// bl 0x821378b8
	ctx.lr = 0x82185688;
	sub_821378B8(ctx, base);
	// li r18,0
	r18.s64 = 0;
	// stw r3,52(r19)
	PPC_STORE_U32(r19.u32 + 52, ctx.r3.u32);
	// addi r14,r19,80
	r14.s64 = r19.s64 + 80;
	// stw r17,24(r19)
	PPC_STORE_U32(r19.u32 + 24, r17.u32);
	// addi r30,r19,68
	r30.s64 = r19.s64 + 68;
	// sth r21,56(r19)
	PPC_STORE_U16(r19.u32 + 56, r21.u16);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// sth r20,58(r19)
	PPC_STORE_U16(r19.u32 + 58, r20.u16);
	// stw r18,80(r19)
	PPC_STORE_U32(r19.u32 + 80, r18.u32);
	// stw r18,68(r19)
	PPC_STORE_U32(r19.u32 + 68, r18.u32);
	// beq cr6,0x821856c0
	if (cr6.eq) goto loc_821856C0;
	// lbz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// b 0x821856cc
	goto loc_821856CC;
loc_821856C0:
	// mr r8,r18
	ctx.r8.u64 = r18.u64;
	// stw r18,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r18.u32);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
loc_821856CC:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821856f0
	if (cr6.eq) goto loc_821856F0;
	// lbz r29,8(r31)
	r29.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// lbz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// lbz r4,17(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 17);
	// lwz r15,12(r31)
	r15.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// b 0x82185704
	goto loc_82185704;
loc_821856F0:
	// li r29,1
	r29.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r15,1
	r15.s64 = 1;
	// li r11,1
	r11.s64 = 1;
loc_82185704:
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// stw r11,44(r19)
	PPC_STORE_U32(r19.u32 + 44, r11.u32);
	// bne cr6,0x82185718
	if (!cr6.eq) goto loc_82185718;
	// li r6,2
	ctx.r6.s64 = 2;
	// b 0x82185724
	goto loc_82185724;
loc_82185718:
	// addi r11,r10,-2
	r11.s64 = ctx.r10.s64 + -2;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r6,r10,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
loc_82185724:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82185738
	if (cr6.eq) goto loc_82185738;
	// lwz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82185758
	if (!cr6.eq) goto loc_82185758;
loc_82185738:
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r25,-32
	r11.s64 = r25.s64 + -32;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r9,r11,3
	ctx.r9.s64 = r11.s64 + 3;
	// bne cr6,0x82185758
	if (!cr6.eq) goto loc_82185758;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
loc_82185758:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// stw r9,60(r19)
	PPC_STORE_U32(r19.u32 + 60, ctx.r9.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r7,r11,-22392
	ctx.r7.s64 = r11.s64 + -22392;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r10,-22472
	r11.s64 = ctx.r10.s64 + -22472;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lwzx r5,r8,r7
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// lwzx r16,r8,r11
	r16.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// beq cr6,0x821857ac
	if (cr6.eq) goto loc_821857AC;
	// lbz r11,36(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821857ac
	if (cr6.eq) goto loc_821857AC;
	// clrlwi r11,r5,26
	r11.u64 = ctx.r5.u32 & 0x3F;
	// cmplwi cr6,r11,6
	cr6.compare<uint32_t>(r11.u32, 6, xer);
	// bne cr6,0x821857ac
	if (!cr6.eq) goto loc_821857AC;
	// clrlwi r11,r16,26
	r11.u64 = r16.u32 & 0x3F;
	// cmplwi cr6,r11,6
	cr6.compare<uint32_t>(r11.u32, 6, xer);
	// bne cr6,0x821857ac
	if (!cr6.eq) goto loc_821857AC;
	// ori r5,r5,32256
	ctx.r5.u64 = ctx.r5.u64 | 32256;
	// ori r16,r16,32256
	r16.u64 = r16.u64 | 32256;
loc_821857AC:
	// stw r18,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r18.u32);
	// mr r7,r18
	ctx.r7.u64 = r18.u64;
	// stw r18,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r18.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r18,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r18.u32);
	// stw r18,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r18.u32);
	// beq cr6,0x82185824
	if (cr6.eq) goto loc_82185824;
	// lbz r11,18(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82185824
	if (cr6.eq) goto loc_82185824;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82185808
	if (cr6.eq) goto loc_82185808;
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// li r8,5120
	ctx.r8.s64 = 5120;
	// lwz r11,44(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// lwz r10,28(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// addi r28,r11,5119
	r28.s64 = r11.s64 + 5119;
	// clrlwi r11,r10,20
	r11.u64 = ctx.r10.u32 & 0xFFF;
	// divwu r10,r28,r8
	ctx.r10.u32 = r28.u32 / ctx.r8.u32;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82185818
	goto loc_82185818;
loc_82185808:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r11,-27812(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27812);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// clrlwi r8,r10,20
	ctx.r8.u64 = ctx.r10.u32 & 0xFFF;
loc_82185818:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
loc_82185824:
	// mr r24,r21
	r24.u64 = r21.u64;
	// mr r22,r20
	r22.u64 = r20.u64;
	// cmpwi cr6,r17,3
	cr6.compare<int32_t>(r17.s32, 3, xer);
	// beq cr6,0x82185b24
	if (cr6.eq) goto loc_82185B24;
	// cmpwi cr6,r17,1
	cr6.compare<int32_t>(r17.s32, 1, xer);
	// beq cr6,0x82185b2c
	if (cr6.eq) goto loc_82185B2C;
	// cmpwi cr6,r17,4
	cr6.compare<int32_t>(r17.s32, 4, xer);
	// beq cr6,0x82185b24
	if (cr6.eq) goto loc_82185B24;
	// cmpwi cr6,r17,2
	cr6.compare<int32_t>(r17.s32, 2, xer);
	// beq cr6,0x82185854
	if (cr6.eq) goto loc_82185854;
	// cmpwi cr6,r17,5
	cr6.compare<int32_t>(r17.s32, 5, xer);
	// bne cr6,0x82185d6c
	if (!cr6.eq) goto loc_82185D6C;
loc_82185854:
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82185868
	if (!cr6.eq) goto loc_82185868;
	// li r11,-1
	r11.s64 = -1;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
loc_82185868:
	// lis r26,-32131
	r26.s64 = -2105737216;
	// cmpwi cr6,r9,15
	cr6.compare<int32_t>(ctx.r9.s32, 15, xer);
	// beq cr6,0x821858a8
	if (cr6.eq) goto loc_821858A8;
	// cmpwi cr6,r25,32
	cr6.compare<int32_t>(r25.s32, 32, xer);
	// bne cr6,0x821858a0
	if (!cr6.eq) goto loc_821858A0;
	// lwz r11,17068(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 17068);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82185894
	if (cr6.eq) goto loc_82185894;
	// lis r5,6690
	ctx.r5.s64 = 438435840;
	// ori r5,r5,407
	ctx.r5.u64 = ctx.r5.u64 | 407;
	// b 0x821858a8
	goto loc_821858A8;
loc_82185894:
	// lis r5,11552
	ctx.r5.s64 = 757071872;
	// ori r5,r5,406
	ctx.r5.u64 = ctx.r5.u64 | 406;
	// b 0x821858a8
	goto loc_821858A8;
loc_821858A0:
	// lis r5,6690
	ctx.r5.s64 = 438435840;
	// ori r5,r5,344
	ctx.r5.u64 = ctx.r5.u64 | 344;
loc_821858A8:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821858e0
	if (cr6.eq) goto loc_821858E0;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x82410d70
	ctx.lr = 0x821858C0;
	sub_82410D70(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x821858e0
	if (!cr6.eq) goto loc_821858E0;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// addi r3,r11,-22524
	ctx.r3.s64 = r11.s64 + -22524;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// bl 0x821bd618
	ctx.lr = 0x821858E0;
	sub_821BD618(ctx, base);
loc_821858E0:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82185d6c
	if (cr6.eq) goto loc_82185D6C;
	// lwz r4,44(r19)
	ctx.r4.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// ble cr6,0x82185aa4
	if (!cr6.gt) goto loc_82185AA4;
	// cmpwi cr6,r17,5
	cr6.compare<int32_t>(r17.s32, 5, xer);
	// bne cr6,0x82185aa4
	if (!cr6.eq) goto loc_82185AA4;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// subf. r7,r8,r11
	ctx.r7.s64 = r11.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne 0x82185a98
	if (!cr0.eq) goto loc_82185A98;
	// addi r30,r19,36
	r30.s64 = r19.s64 + 36;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82185308
	ctx.lr = 0x82185924;
	sub_82185308(ctx, base);
	// lwz r10,44(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// srawi r8,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 1;
	// addi r11,r11,-23776
	r11.s64 = r11.s64 + -23776;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// rlwinm r10,r7,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// add r5,r10,r9
	ctx.r5.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r29,-8(r6)
	r29.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8);
	// lwz r27,-8(r5)
	r27.u64 = PPC_LOAD_U32(ctx.r5.u32 + -8);
	// mullw r24,r29,r21
	r24.s64 = int64_t(r29.s32) * int64_t(r21.s32);
	// sth r24,48(r19)
	PPC_STORE_U16(r19.u32 + 48, r24.u16);
	// mullw r22,r27,r20
	r22.s64 = int64_t(r27.s32) * int64_t(r20.s32);
	// sth r22,50(r19)
	PPC_STORE_U16(r19.u32 + 50, r22.u16);
	// cmpwi cr6,r24,4096
	cr6.compare<int32_t>(r24.s32, 4096, xer);
	// bgt cr6,0x82185970
	if (cr6.gt) goto loc_82185970;
	// cmpwi cr6,r22,4096
	cr6.compare<int32_t>(r22.s32, 4096, xer);
	// ble cr6,0x8218597c
	if (!cr6.gt) goto loc_8218597C;
loc_82185970:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-22572
	ctx.r3.s64 = r11.s64 + -22572;
	// bl 0x821bd618
	ctx.lr = 0x8218597C;
	sub_821BD618(ctx, base);
loc_8218597C:
	// lhz r11,40(r19)
	r11.u64 = PPC_LOAD_U16(r19.u32 + 40);
	// mr r28,r18
	r28.u64 = r18.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82185a04
	if (cr6.eq) goto loc_82185A04;
	// mr r31,r18
	r31.u64 = r18.u64;
	// li r23,1600
	r23.s64 = 1600;
loc_82185994:
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x8218599C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821859bc
	if (cr6.eq) goto loc_821859BC;
	// stw r23,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r23.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stw r23,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r23.u32);
	// stw r18,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r18.u32);
	// stw r18,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r18.u32);
	// b 0x821859c0
	goto loc_821859C0;
loc_821859BC:
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
loc_821859C0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r3,r31,r11
	ctx.r3.u64 = r31.u64 + r11.u64;
	// bl 0x82183820
	ctx.lr = 0x821859CC;
	sub_82183820(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// stw r21,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r21.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r8,r31,r9
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// stw r20,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r20.u32);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r6,r31,r7
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stw r28,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r28.u32);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// lhz r5,40(r19)
	ctx.r5.u64 = PPC_LOAD_U16(r19.u32 + 40);
	// cmpw cr6,r28,r5
	cr6.compare<int32_t>(r28.s32, ctx.r5.s32, xer);
	// blt cr6,0x82185994
	if (cr6.lt) goto loc_82185994;
loc_82185A04:
	// mr r8,r18
	ctx.r8.u64 = r18.u64;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x82185aa4
	if (!cr6.gt) goto loc_82185AA4;
loc_82185A14:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82185a88
	if (!cr6.gt) goto loc_82185A88;
	// rotlwi r11,r22,1
	r11.u64 = __builtin_rotateleft32(r22.u32, 1);
	// rotlwi r10,r24,1
	ctx.r10.u64 = __builtin_rotateleft32(r24.u32, 1);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// andc r7,r27,r11
	ctx.r7.u64 = r27.u64 & ~r11.u64;
	// divw r9,r22,r27
	ctx.r9.s32 = r22.s32 / r27.s32;
	// andc r4,r29,r10
	ctx.r4.u64 = r29.u64 & ~ctx.r10.u64;
	// twlgei r7,-1
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// mullw r7,r9,r5
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r5.s32);
	// twllei r27,0
	// mr r9,r18
	ctx.r9.u64 = r18.u64;
	// divw r6,r24,r29
	ctx.r6.s32 = r24.s32 / r29.s32;
	// twllei r29,0
	// twlgei r4,-1
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// add r8,r8,r29
	ctx.r8.u64 = ctx.r8.u64 + r29.u64;
loc_82185A60:
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwzx r3,r11,r4
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r4.u32);
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// add r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 + ctx.r9.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r11,r4
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r4.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r7,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// bne 0x82185a60
	if (!cr0.eq) goto loc_82185A60;
loc_82185A88:
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmpw cr6,r5,r27
	cr6.compare<int32_t>(ctx.r5.s32, r27.s32, xer);
	// blt cr6,0x82185a14
	if (cr6.lt) goto loc_82185A14;
	// b 0x82185aa4
	goto loc_82185AA4;
loc_82185A98:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-22604
	ctx.r3.s64 = r11.s64 + -22604;
	// bl 0x821bd618
	ctx.lr = 0x82185AA4;
	sub_821BD618(ctx, base);
loc_82185AA4:
	// lwz r11,60(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 60);
	// cmpwi cr6,r11,15
	cr6.compare<int32_t>(r11.s32, 15, xer);
	// bne cr6,0x82185ab8
	if (!cr6.eq) goto loc_82185AB8;
	// mr r8,r16
	ctx.r8.u64 = r16.u64;
	// b 0x82185aec
	goto loc_82185AEC;
loc_82185AB8:
	// cmpwi cr6,r25,32
	cr6.compare<int32_t>(r25.s32, 32, xer);
	// bne cr6,0x82185ae4
	if (!cr6.eq) goto loc_82185AE4;
	// lwz r11,17068(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 17068);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82185ad8
	if (cr6.eq) goto loc_82185AD8;
	// lis r8,6690
	ctx.r8.s64 = 438435840;
	// ori r8,r8,407
	ctx.r8.u64 = ctx.r8.u64 | 407;
	// b 0x82185aec
	goto loc_82185AEC;
loc_82185AD8:
	// lis r8,11552
	ctx.r8.s64 = 757071872;
	// ori r8,r8,406
	ctx.r8.u64 = ctx.r8.u64 | 406;
	// b 0x82185aec
	goto loc_82185AEC;
loc_82185AE4:
	// lis r8,6690
	ctx.r8.s64 = 438435840;
	// ori r8,r8,344
	ctx.r8.u64 = ctx.r8.u64 | 344;
loc_82185AEC:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r14,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r14.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r15
	ctx.r6.u64 = r15.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82177eb0
	ctx.lr = 0x82185B10;
	sub_82177EB0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x82185d6c
	if (!cr6.lt) goto loc_82185D6C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-23096
	ctx.r3.s64 = r11.s64 + -23096;
	// b 0x82185d68
	goto loc_82185D68;
loc_82185B24:
	// cmpwi cr6,r17,1
	cr6.compare<int32_t>(r17.s32, 1, xer);
	// bne cr6,0x82185b44
	if (!cr6.eq) goto loc_82185B44;
loc_82185B2C:
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lwz r11,-28080(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28080);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r3,-28080(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28080);
	// bl 0x82422160
	ctx.lr = 0x82185B40;
	sub_82422160(ctx, base);
	// b 0x82185b60
	goto loc_82185B60;
loc_82185B44:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82185b60
	if (cr6.eq) goto loc_82185B60;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x82410d70
	ctx.lr = 0x82185B5C;
	sub_82410D70(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_82185B60:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82185d6c
	if (cr6.eq) goto loc_82185D6C;
	// lwz r4,44(r19)
	ctx.r4.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// ble cr6,0x82185d28
	if (!cr6.gt) goto loc_82185D28;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// subf. r7,r8,r11
	ctx.r7.s64 = r11.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne 0x82185d1c
	if (!cr0.eq) goto loc_82185D1C;
	// addi r30,r19,28
	r30.s64 = r19.s64 + 28;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82185308
	ctx.lr = 0x82185B9C;
	sub_82185308(ctx, base);
	// lwz r10,44(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 44);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// srawi r8,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 1;
	// addi r11,r11,-23776
	r11.s64 = r11.s64 + -23776;
	// addze r7,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r7.s64 = temp.s64;
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// rlwinm r10,r7,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// add r5,r10,r9
	ctx.r5.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r29,-8(r6)
	r29.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8);
	// lwz r25,-8(r5)
	r25.u64 = PPC_LOAD_U32(ctx.r5.u32 + -8);
	// mullw r24,r29,r21
	r24.s64 = int64_t(r29.s32) * int64_t(r21.s32);
	// sth r24,48(r19)
	PPC_STORE_U16(r19.u32 + 48, r24.u16);
	// mullw r22,r25,r20
	r22.s64 = int64_t(r25.s32) * int64_t(r20.s32);
	// sth r22,50(r19)
	PPC_STORE_U16(r19.u32 + 50, r22.u16);
	// cmpwi cr6,r24,4096
	cr6.compare<int32_t>(r24.s32, 4096, xer);
	// bgt cr6,0x82185be8
	if (cr6.gt) goto loc_82185BE8;
	// cmpwi cr6,r22,4096
	cr6.compare<int32_t>(r22.s32, 4096, xer);
	// ble cr6,0x82185bf4
	if (!cr6.gt) goto loc_82185BF4;
loc_82185BE8:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-22572
	ctx.r3.s64 = r11.s64 + -22572;
	// bl 0x821bd618
	ctx.lr = 0x82185BF4;
	sub_821BD618(ctx, base);
loc_82185BF4:
	// lhz r11,32(r19)
	r11.u64 = PPC_LOAD_U16(r19.u32 + 32);
	// mr r28,r18
	r28.u64 = r18.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82185c88
	if (cr6.eq) goto loc_82185C88;
	// mr r31,r18
	r31.u64 = r18.u64;
	// li r23,1600
	r23.s64 = 1600;
loc_82185C0C:
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x82185C14;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82185c34
	if (cr6.eq) goto loc_82185C34;
	// stw r23,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r23.u32);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// stw r23,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r23.u32);
	// stw r18,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r18.u32);
	// stw r18,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r18.u32);
	// b 0x82185c38
	goto loc_82185C38;
loc_82185C34:
	// mr r26,r18
	r26.u64 = r18.u64;
loc_82185C38:
	// lwz r27,0(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r27,r31
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82185c4c
	if (cr6.eq) goto loc_82185C4C;
	// bl 0x82130588
	ctx.lr = 0x82185C4C;
	sub_82130588(ctx, base);
loc_82185C4C:
	// stwx r26,r27,r31
	PPC_STORE_U32(r27.u32 + r31.u32, r26.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// stw r21,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r21.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r8,r9,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// stw r20,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r20.u32);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r6,r7,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stw r28,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r28.u32);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// lhz r5,32(r19)
	ctx.r5.u64 = PPC_LOAD_U16(r19.u32 + 32);
	// cmpw cr6,r28,r5
	cr6.compare<int32_t>(r28.s32, ctx.r5.s32, xer);
	// blt cr6,0x82185c0c
	if (cr6.lt) goto loc_82185C0C;
loc_82185C88:
	// mr r8,r18
	ctx.r8.u64 = r18.u64;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x82185d28
	if (!cr6.gt) goto loc_82185D28;
loc_82185C98:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82185d0c
	if (!cr6.gt) goto loc_82185D0C;
	// rotlwi r11,r22,1
	r11.u64 = __builtin_rotateleft32(r22.u32, 1);
	// rotlwi r10,r24,1
	ctx.r10.u64 = __builtin_rotateleft32(r24.u32, 1);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// andc r7,r25,r11
	ctx.r7.u64 = r25.u64 & ~r11.u64;
	// divw r9,r22,r25
	ctx.r9.s32 = r22.s32 / r25.s32;
	// andc r4,r29,r10
	ctx.r4.u64 = r29.u64 & ~ctx.r10.u64;
	// twlgei r7,-1
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// mullw r7,r9,r5
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r5.s32);
	// twllei r25,0
	// mr r9,r18
	ctx.r9.u64 = r18.u64;
	// divw r6,r24,r29
	ctx.r6.s32 = r24.s32 / r29.s32;
	// twllei r29,0
	// twlgei r4,-1
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// add r8,r8,r29
	ctx.r8.u64 = ctx.r8.u64 + r29.u64;
loc_82185CE4:
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwzx r3,r4,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// add r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 + ctx.r9.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r4,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + r11.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r7,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r7.u32);
	// bne 0x82185ce4
	if (!cr0.eq) goto loc_82185CE4;
loc_82185D0C:
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmpw cr6,r5,r25
	cr6.compare<int32_t>(ctx.r5.s32, r25.s32, xer);
	// blt cr6,0x82185c98
	if (cr6.lt) goto loc_82185C98;
	// b 0x82185d28
	goto loc_82185D28;
loc_82185D1C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-22660
	ctx.r3.s64 = r11.s64 + -22660;
	// bl 0x821bd618
	ctx.lr = 0x82185D28;
	sub_821BD618(ctx, base);
loc_82185D28:
	// addi r11,r17,-4
	r11.s64 = r17.s64 + -4;
	// stw r14,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r14.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// mr r8,r16
	ctx.r8.u64 = r16.u64;
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r15
	ctx.r6.u64 = r15.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82177eb0
	ctx.lr = 0x82185D58;
	sub_82177EB0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x82185d6c
	if (!cr6.lt) goto loc_82185D6C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r3,r11,-23020
	ctx.r3.s64 = r11.s64 + -23020;
loc_82185D68:
	// bl 0x821bd618
	ctx.lr = 0x82185D6C;
	sub_821BD618(ctx, base);
loc_82185D6C:
	// lwz r11,0(r14)
	r11.u64 = PPC_LOAD_U32(r14.u32 + 0);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// stw r11,16(r19)
	PPC_STORE_U32(r19.u32 + 16, r11.u32);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82185D80"))) PPC_WEAK_FUNC(sub_82185D80);
PPC_FUNC_IMPL(__imp__sub_82185D80) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82185D88;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82180360
	ctx.lr = 0x82185D94;
	sub_82180360(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r31,r11,-25032
	r31.s64 = r11.s64 + -25032;
	// li r26,1
	r26.s64 = 1;
	// li r30,0
	r30.s64 = 0;
	// addi r9,r10,-23628
	ctx.r9.s64 = ctx.r10.s64 + -23628;
	// mr r11,r26
	r11.u64 = r26.u64;
	// stb r30,4(r29)
	PPC_STORE_U8(r29.u32 + 4, r30.u8);
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// addi r7,r31,28
	ctx.r7.s64 = r31.s64 + 28;
	// stw r30,40(r29)
	PPC_STORE_U32(r29.u32 + 40, r30.u32);
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// stw r30,44(r29)
	PPC_STORE_U32(r29.u32 + 44, r30.u32);
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// stw r30,48(r29)
	PPC_STORE_U32(r29.u32 + 48, r30.u32);
	// addi r6,r31,56
	ctx.r6.s64 = r31.s64 + 56;
	// stw r30,52(r29)
	PPC_STORE_U32(r29.u32 + 52, r30.u32);
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// stw r30,56(r29)
	PPC_STORE_U32(r29.u32 + 56, r30.u32);
	// addi r5,r31,84
	ctx.r5.s64 = r31.s64 + 84;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// addi r4,r31,112
	ctx.r4.s64 = r31.s64 + 112;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r3,r11,2
	ctx.r3.s64 = r11.s64 + 2;
	// srawi r11,r3,2
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3) != 0);
	r11.s64 = ctx.r3.s32 >> 2;
	// addze r11,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r11.s64 = temp.s64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r11,r3
	r11.s64 = ctx.r3.s64 - r11.s64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stwx r30,r3,r31
	PPC_STORE_U32(ctx.r3.u32 + r31.u32, r30.u32);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// srawi r3,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r3.s64 = r11.s32 >> 2;
	// stw r10,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r10.u32);
	// addze r3,r3
	temp.s64 = ctx.r3.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r3.s64 = temp.s64;
	// rlwinm r3,r3,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r3,r11
	r11.s64 = r11.s64 - ctx.r3.s64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// stwx r30,r3,r7
	PPC_STORE_U32(ctx.r3.u32 + ctx.r7.u32, r30.u32);
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// stw r9,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r9.u32);
	// addze r3,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r3.s64 = temp.s64;
	// rlwinm r9,r3,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
	// stwx r30,r7,r6
	PPC_STORE_U32(ctx.r7.u32 + ctx.r6.u32, r30.u32);
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// addi r6,r11,2
	ctx.r6.s64 = r11.s64 + 2;
	// srawi r3,r6,2
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r6.s32 >> 2;
	// stw r8,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r8.u32);
	// addze r11,r3
	temp.s64 = ctx.r3.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r3.u32;
	r11.s64 = temp.s64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r9,r6
	r11.s64 = ctx.r6.s64 - ctx.r9.s64;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
	// stwx r30,r8,r5
	PPC_STORE_U32(ctx.r8.u32 + ctx.r5.u32, r30.u32);
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// addi r7,r11,2
	ctx.r7.s64 = r11.s64 + 2;
	// srawi r6,r7,2
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 2;
	// stw r10,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r10.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// addze r5,r6
	temp.s64 = ctx.r6.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r5.s64 = temp.s64;
	// rlwinm r3,r5,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r3,r7
	r11.s64 = ctx.r7.s64 - ctx.r3.s64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// addi r11,r29,24
	r11.s64 = r29.s64 + 24;
	// stwx r30,r9,r4
	PPC_STORE_U32(ctx.r9.u32 + ctx.r4.u32, r30.u32);
loc_82185EB8:
	// stw r30,-16(r11)
	PPC_STORE_U32(r11.u32 + -16, r30.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82185eb8
	if (!cr0.eq) goto loc_82185EB8;
	// li r3,84
	ctx.r3.s64 = 84;
	// bl 0x82130528
	ctx.lr = 0x82185ED4;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r25,2
	r25.s64 = 2;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// addi r27,r11,-23260
	r27.s64 = r11.s64 + -23260;
	// beq cr6,0x82185f48
	if (cr6.eq) goto loc_82185F48;
	// bl 0x821d2970
	ctx.lr = 0x82185EF0;
	sub_821D2970(ctx, base);
	// stw r26,8(r28)
	PPC_STORE_U32(r28.u32 + 8, r26.u32);
	// sth r26,12(r28)
	PPC_STORE_U16(r28.u32 + 12, r26.u16);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// sth r30,14(r28)
	PPC_STORE_U16(r28.u32 + 14, r30.u16);
	// stw r30,16(r28)
	PPC_STORE_U32(r28.u32 + 16, r30.u32);
	// stw r30,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r30.u32);
	// stw r30,28(r28)
	PPC_STORE_U32(r28.u32 + 28, r30.u32);
	// sth r30,32(r28)
	PPC_STORE_U16(r28.u32 + 32, r30.u16);
	// sth r30,34(r28)
	PPC_STORE_U16(r28.u32 + 34, r30.u16);
	// stw r30,36(r28)
	PPC_STORE_U32(r28.u32 + 36, r30.u32);
	// sth r30,40(r28)
	PPC_STORE_U16(r28.u32 + 40, r30.u16);
	// sth r30,42(r28)
	PPC_STORE_U16(r28.u32 + 42, r30.u16);
	// stw r27,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r27.u32);
	// stw r30,52(r28)
	PPC_STORE_U32(r28.u32 + 52, r30.u32);
	// sth r30,56(r28)
	PPC_STORE_U16(r28.u32 + 56, r30.u16);
	// sth r30,58(r28)
	PPC_STORE_U16(r28.u32 + 58, r30.u16);
	// stw r25,60(r28)
	PPC_STORE_U32(r28.u32 + 60, r25.u32);
	// stw r30,64(r28)
	PPC_STORE_U32(r28.u32 + 64, r30.u32);
	// stw r30,68(r28)
	PPC_STORE_U32(r28.u32 + 68, r30.u32);
	// stw r30,72(r28)
	PPC_STORE_U32(r28.u32 + 72, r30.u32);
	// stw r30,76(r28)
	PPC_STORE_U32(r28.u32 + 76, r30.u32);
	// b 0x82185f4c
	goto loc_82185F4C;
loc_82185F48:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82185F4C:
	// stw r3,60(r29)
	PPC_STORE_U32(r29.u32 + 60, ctx.r3.u32);
	// lis r28,-32124
	r28.s64 = -2105278464;
	// lwz r4,-28080(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + -28080);
	// bl 0x821840a8
	ctx.lr = 0x82185F5C;
	sub_821840A8(ctx, base);
	// lwz r3,-28080(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -28080);
	// bl 0x82422160
	ctx.lr = 0x82185F64;
	sub_82422160(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,60(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 60);
	// li r3,84
	ctx.r3.s64 = 84;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r10.u32);
	// bl 0x82130528
	ctx.lr = 0x82185F7C;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82185fe4
	if (cr6.eq) goto loc_82185FE4;
	// bl 0x821d2970
	ctx.lr = 0x82185F8C;
	sub_821D2970(ctx, base);
	// stw r26,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r26.u32);
	// sth r26,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r26.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r30,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r30.u16);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// sth r30,32(r31)
	PPC_STORE_U16(r31.u32 + 32, r30.u16);
	// sth r30,34(r31)
	PPC_STORE_U16(r31.u32 + 34, r30.u16);
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// sth r30,40(r31)
	PPC_STORE_U16(r31.u32 + 40, r30.u16);
	// sth r30,42(r31)
	PPC_STORE_U16(r31.u32 + 42, r30.u16);
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// sth r30,56(r31)
	PPC_STORE_U16(r31.u32 + 56, r30.u16);
	// sth r30,58(r31)
	PPC_STORE_U16(r31.u32 + 58, r30.u16);
	// stw r25,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r25.u32);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// stw r30,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r30.u32);
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// b 0x82185fe8
	goto loc_82185FE8;
loc_82185FE4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82185FE8:
	// stw r3,64(r29)
	PPC_STORE_U32(r29.u32 + 64, ctx.r3.u32);
	// lis r31,-32124
	r31.s64 = -2105278464;
	// lwz r4,-27812(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -27812);
	// bl 0x82183fe0
	ctx.lr = 0x82185FF8;
	sub_82183FE0(ctx, base);
	// lwz r3,-27812(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -27812);
	// bl 0x82422160
	ctx.lr = 0x82186000;
	sub_82422160(ctx, base);
	// li r3,84
	ctx.r3.s64 = 84;
	// bl 0x82130528
	ctx.lr = 0x82186008;
	sub_82130528(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r31,r11,-27732
	r31.s64 = r11.s64 + -27732;
	// beq cr6,0x82186024
	if (cr6.eq) goto loc_82186024;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82185538
	ctx.lr = 0x82186020;
	sub_82185538(ctx, base);
	// b 0x82186028
	goto loc_82186028;
loc_82186024:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82186028:
	// stw r3,68(r29)
	PPC_STORE_U32(r29.u32 + 68, ctx.r3.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82422160
	ctx.lr = 0x82186034;
	sub_82422160(ctx, base);
	// li r3,84
	ctx.r3.s64 = 84;
	// bl 0x82130528
	ctx.lr = 0x8218603C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82186050
	if (cr6.eq) goto loc_82186050;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82185538
	ctx.lr = 0x8218604C;
	sub_82185538(ctx, base);
	// b 0x82186054
	goto loc_82186054;
loc_82186050:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82186054:
	// stw r3,72(r29)
	PPC_STORE_U32(r29.u32 + 72, ctx.r3.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82422160
	ctx.lr = 0x82186060;
	sub_82422160(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8218606C"))) PPC_WEAK_FUNC(sub_8218606C);
PPC_FUNC_IMPL(__imp__sub_8218606C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82186070"))) PPC_WEAK_FUNC(sub_82186070);
PPC_FUNC_IMPL(__imp__sub_82186070) {
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
	ctx.lr = 0x82186078;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,84
	ctx.r3.s64 = 84;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// bl 0x82130528
	ctx.lr = 0x8218609C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821860c8
	if (cr6.eq) goto loc_821860C8;
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82185648
	ctx.lr = 0x821860C0;
	sub_82185648(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x821860cc
	goto loc_821860CC;
loc_821860C8:
	// li r31,0
	r31.s64 = 0;
loc_821860CC:
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lwz r4,-24876(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -24876);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821860f4
	if (cr6.eq) goto loc_821860F4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,20(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// bl 0x82181180
	ctx.lr = 0x821860E8;
	sub_82181180(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821860F4:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82181180
	ctx.lr = 0x82186100;
	sub_82181180(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8218610C"))) PPC_WEAK_FUNC(sub_8218610C);
PPC_FUNC_IMPL(__imp__sub_8218610C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82186110"))) PPC_WEAK_FUNC(sub_82186110);
PPC_FUNC_IMPL(__imp__sub_82186110) {
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
	// li r3,76
	ctx.r3.s64 = 76;
	// bl 0x82130528
	ctx.lr = 0x8218612C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8218613c
	if (cr6.eq) goto loc_8218613C;
	// bl 0x82185d80
	ctx.lr = 0x82186138;
	sub_82185D80(ctx, base);
	// b 0x82186140
	goto loc_82186140;
loc_8218613C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82186140:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82186154
	if (cr6.eq) goto loc_82186154;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// stw r3,-25232(r11)
	PPC_STORE_U32(r11.u32 + -25232, ctx.r3.u32);
loc_82186154:
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

