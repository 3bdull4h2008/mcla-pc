#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_825364B8"))) PPC_WEAK_FUNC(sub_825364B8);
PPC_FUNC_IMPL(__imp__sub_825364B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// li r11,1024
	r11.s64 = 1024;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r9,1040
	ctx.r9.s64 = 1040;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,16(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_825364E0"))) PPC_WEAK_FUNC(sub_825364E0);
PPC_FUNC_IMPL(__imp__sub_825364E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	ctx.lr = 0x825364E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
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
	// li r7,1024
	ctx.r7.s64 = 1024;
	// li r6,1040
	ctx.r6.s64 = 1040;
	// li r31,96
	r31.s64 = 96;
	// li r30,112
	r30.s64 = 112;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// addi r5,r3,32
	ctx.r5.s64 = ctx.r3.s64 + 32;
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r3,r7
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r3,r6
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r3,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r3,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lvx128 v56,r11,r10
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v55,v56,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v55,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x82536560;
	sub_82202EC0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82536568"))) PPC_WEAK_FUNC(sub_82536568);
PPC_FUNC_IMPL(__imp__sub_82536568) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,15360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15360);
	f0.f64 = double(temp.f32);
	// addi r5,r10,-28340
	ctx.r5.s64 = ctx.r10.s64 + -28340;
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r8,r9,24,0,7
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFF000000;
	// oris r30,r8,255
	r30.u64 = ctx.r8.u64 | 16711680;
	// ori r30,r30,65535
	r30.u64 = r30.u64 | 65535;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82501dd8
	ctx.lr = 0x825365BC;
	sub_82501DD8(ctx, base);
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,-28372
	ctx.r5.s64 = ctx.r7.s64 + -28372;
	// bl 0x82501dd8
	ctx.lr = 0x825365D4;
	sub_82501DD8(ctx, base);
	// lis r5,-32248
	ctx.r5.s64 = -2113404928;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r5,-28404
	ctx.r5.s64 = ctx.r5.s64 + -28404;
	// bl 0x82501dd8
	ctx.lr = 0x825365EC;
	sub_82501DD8(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r11,-28464
	ctx.r5.s64 = r11.s64 + -28464;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82501dd8
	ctx.lr = 0x82536604;
	sub_82501DD8(ctx, base);
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

__attribute__((alias("__imp__sub_8253661C"))) PPC_WEAK_FUNC(sub_8253661C);
PPC_FUNC_IMPL(__imp__sub_8253661C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82536620"))) PPC_WEAK_FUNC(sub_82536620);
PPC_FUNC_IMPL(__imp__sub_82536620) {
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
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// bl 0x823d91f8
	ctx.lr = 0x82536628;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823db9d0
	ctx.lr = 0x82536630;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// bl 0x8260b990
	ctx.lr = 0x82536648;
	sub_8260B990(ctx, base);
	// lbz r10,978(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 978);
	// lbz r9,976(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 976);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// xor r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// lfs f26,30712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30712);
	f26.f64 = double(temp.f32);
	// subfic r6,r7,127
	xer.ca = ctx.r7.u32 <= 127;
	ctx.r6.s64 = 127 - ctx.r7.s64;
	// fmuls f30,f31,f26
	f30.f64 = double(float(f31.f64 * f26.f64));
	// subfe r5,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82536680
	if (cr6.eq) goto loc_82536680;
	// lfs f0,1012(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1012);
	f0.f64 = double(temp.f32);
	// b 0x82536684
	goto loc_82536684;
loc_82536680:
	// lfs f0,1016(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1016);
	f0.f64 = double(temp.f32);
loc_82536684:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// fmuls f27,f0,f31
	ctx.fpscr.disableFlushMode();
	f27.f64 = double(float(f0.f64 * f31.f64));
	// addi r3,r31,904
	ctx.r3.s64 = r31.s64 + 904;
	// lfs f31,-332(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -332);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x822a48f0
	ctx.lr = 0x8253669C;
	sub_822A48F0(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmuls f29,f1,f30
	ctx.fpscr.disableFlushMode();
	f29.f64 = double(float(ctx.f1.f64 * f30.f64));
	// addi r3,r31,916
	ctx.r3.s64 = r31.s64 + 916;
	// lfs f1,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822a48f0
	ctx.lr = 0x825366B0;
	sub_822A48F0(ctx, base);
	// addi r3,r31,928
	ctx.r3.s64 = r31.s64 + 928;
	// fmuls f30,f1,f30
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(ctx.f1.f64 * f30.f64));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x822a48f0
	ctx.lr = 0x825366C0;
	sub_822A48F0(ctx, base);
	// addi r3,r31,940
	ctx.r3.s64 = r31.s64 + 940;
	// fmuls f28,f1,f27
	ctx.fpscr.disableFlushMode();
	f28.f64 = double(float(ctx.f1.f64 * f27.f64));
	// stfs f28,88(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x822a48f0
	ctx.lr = 0x825366D4;
	sub_822A48F0(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fmuls f0,f1,f27
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 * f27.f64));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r28,0
	r28.s64 = 0;
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f29,f31
	cr6.compare(f29.f64, f31.f64);
	// bne cr6,0x82536708
	if (!cr6.eq) goto loc_82536708;
	// fcmpu cr6,f30,f31
	cr6.compare(f30.f64, f31.f64);
	// bne cr6,0x82536708
	if (!cr6.eq) goto loc_82536708;
	// fcmpu cr6,f28,f31
	cr6.compare(f28.f64, f31.f64);
	// bne cr6,0x82536708
	if (!cr6.eq) goto loc_82536708;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x8253670c
	if (cr6.eq) goto loc_8253670C;
loc_82536708:
	// li r28,1
	r28.s64 = 1;
loc_8253670C:
	// lbz r11,1000(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1000);
	// lbz r10,1002(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1002);
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82536754
	if (cr6.eq) goto loc_82536754;
	// lbz r10,1003(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1003);
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// li r11,1
	r11.s64 = 1;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82536758
	if (cr6.eq) goto loc_82536758;
loc_82536754:
	// li r11,0
	r11.s64 = 0;
loc_82536758:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82536798
	if (cr6.eq) goto loc_82536798;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// li r9,96
	ctx.r9.s64 = 96;
	// li r8,80
	ctx.r8.s64 = 80;
	// li r7,112
	ctx.r7.s64 = 112;
	// lfs f0,-12524(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12524);
	f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvlx128 v63,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v0,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v13,r31,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r31,r8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v12,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v11,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82536798:
	// lbz r11,1002(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1002);
	// addi r30,r31,48
	r30.s64 = r31.s64 + 48;
	// lbz r10,1000(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1000);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x825368d0
	if (cr6.eq) goto loc_825368D0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// addi r11,r31,96
	r11.s64 = r31.s64 + 96;
	// li r8,64
	ctx.r8.s64 = 64;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// lfs f0,32308(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32308);
	f0.f64 = double(temp.f32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// fmuls f13,f30,f0
	ctx.f13.f64 = double(float(f30.f64 * f0.f64));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f12,f29,f0
	ctx.f12.f64 = double(float(f29.f64 * f0.f64));
	// lvx128 v12,r31,r8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r31,112
	ctx.r10.s64 = r31.s64 + 112;
	// lvlx128 v60,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v6,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// lvlx128 v62,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r9,r31,80
	ctx.r9.s64 = r31.s64 + 80;
	// vspltw128 v0,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvlx128 v61,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v10,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vmaddfp v11,v12,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vor v9,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v8,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v7,v8,v10,v9
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vor v5,v7,v7
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)ctx.v7.u8));
	// stvx128 v7,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v3,v4,v6,v5
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// stvx128 v3,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,104(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,120(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 120);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,96(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,112(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,100(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 100);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,116(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fsubs f4,f11,f10
	ctx.f4.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// fmuls f3,f5,f5
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f5.f64));
	// fsubs f2,f9,f8
	ctx.f2.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// fmadds f1,f4,f4,f3
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f3.f64));
	// fmadds f0,f2,f2,f1
	f0.f64 = double(float(ctx.f2.f64 * ctx.f2.f64 + ctx.f1.f64));
	// fsqrts f13,f0
	ctx.f13.f64 = double(float(sqrt(f0.f64)));
	// fcmpu cr6,f13,f26
	cr6.compare(ctx.f13.f64, f26.f64);
	// bge cr6,0x825368a0
	if (!cr6.lt) goto loc_825368A0;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// vor v0,v3,v3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v3.u8));
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// lvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,30716(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 30716);
	f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvlx128 v59,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// vmaddfp v11,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_825368A0:
	// li r11,48
	r11.s64 = 48;
	// lvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r29,r31,32
	r29.s64 = r31.s64 + 32;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lvx128 v57,r30,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// vsubfp128 v56,v57,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v56.f32, simde_mm_sub_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v58.f32)));
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x825368CC;
	sub_82202EC0(ctx, base);
	// b 0x82536b2c
	goto loc_82536B2C;
loc_825368D0:
	// addi r29,r31,32
	r29.s64 = r31.s64 + 32;
	// fneg f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = f29.u64 ^ 0x8000000000000000;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82350940
	ctx.lr = 0x825368E4;
	sub_82350940(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x82350940
	ctx.lr = 0x825368F4;
	sub_82350940(ctx, base);
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// addi r11,r31,96
	r11.s64 = r31.s64 + 96;
	// lvx128 v12,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r31,80
	ctx.r10.s64 = r31.s64 + 80;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvlx128 v55,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// vspltw128 v0,v55,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v12,v0,v13
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r7,16(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// lfs f0,31292(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31292);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82536978
	if (cr6.eq) goto loc_82536978;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8253696c
	if (!cr6.lt) goto loc_8253696C;
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// fabs f12,f13
	ctx.f12.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x8253696c
	if (!cr6.lt) goto loc_8253696C;
	// vspltisw128 v54,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// vsubfp128 v13,v54,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x825369b8
	goto loc_825369B8;
loc_8253696C:
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f31,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// b 0x825369b4
	goto loc_825369B4;
loc_82536978:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x825369ac
	if (!cr6.lt) goto loc_825369AC;
	// lfs f13,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// fabs f12,f13
	ctx.f12.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x825369ac
	if (!cr6.lt) goto loc_825369AC;
	// li r9,64
	ctx.r9.s64 = 64;
	// vspltisw128 v53,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v52,r31,r9
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v53,v52
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v52.f32)));
	// stvx128 v13,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x825369b8
	goto loc_825369B8;
loc_825369AC:
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f31,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
loc_825369B4:
	// lvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_825369B8:
	// lfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// lfs f11,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// fmr f10,f11
	ctx.f10.f64 = ctx.f11.f64;
	// lfs f9,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// fmr f8,f9
	ctx.f8.f64 = ctx.f9.f64;
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f6,f9,f8,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f31
	cr6.compare(ctx.f6.f64, f31.f64);
	// beq cr6,0x82536aa4
	if (cr6.eq) goto loc_82536AA4;
	// vmsum3fp128 v51,v13,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32), 0xEF));
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lbz r7,990(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 990);
	// addi r6,r9,2528
	ctx.r6.s64 = ctx.r9.s64 + 2528;
	// lbz r5,988(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 988);
	// addi r4,r8,2240
	ctx.r4.s64 = ctx.r8.s64 + 2240;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r8,r3,-31648
	ctx.r8.s64 = ctx.r3.s64 + -31648;
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r9,-31664
	ctx.r6.s64 = ctx.r9.s64 + -31664;
	// lvx128 v0,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// xor r5,r7,r5
	ctx.r5.u64 = ctx.r7.u64 ^ ctx.r5.u64;
	// clrlwi r4,r5,24
	ctx.r4.u64 = ctx.r5.u32 & 0xFF;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// subfic r3,r4,127
	xer.ca = ctx.r4.u32 <= 127;
	ctx.r3.s64 = 127 - ctx.r4.s64;
	// subfe r9,r3,r3
	temp.u8 = (~ctx.r3.u32 + ctx.r3.u32 < ~ctx.r3.u32) | (~ctx.r3.u32 + ctx.r3.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r3.u64 + ctx.r3.u64 + xer.ca;
	xer.ca = temp.u8;
	// vrsqrtefp128 v50,v51
	simde_mm_store_ps(v50.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v51.f32))));
	// vor128 v11,v51,v51
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v51.u8));
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// vcmpeqfp128 v10,v50,v62
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v9,v50,v50
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v50.u8));
	// vsel v0,v9,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v8,v0,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v7,v63,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v6,v11,v8,v12
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v5,v6,v7,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v13,v13,v5
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)));
	// beq cr6,0x82536aa4
	if (cr6.eq) goto loc_82536AA4;
	// stvx128 v13,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r9,r31,64
	ctx.r9.s64 = r31.s64 + 64;
	// stfs f31,72(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stfs f31,64(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// lvx128 v47,r0,r9
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v46,v47,99
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0x9C));
	// lvx128 v49,r0,r10
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v48,v49,135
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0x78));
	// vmulfp128 v0,v48,v46
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v46.f32)));
	// vpermwi128 v12,v47,135
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), 0x78));
	// vpermwi128 v11,v49,99
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0x9C));
	// vnmsubfp v10,v11,v12,v0
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v10,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82536AA4:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r31,952
	ctx.r3.s64 = r31.s64 + 952;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lvlx128 v45,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v45,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0xFF));
	// vmaddfp v11,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82536afc
	if (cr6.eq) goto loc_82536AFC;
	// bl 0x822a49d0
	ctx.lr = 0x82536AD4;
	sub_822A49D0(ctx, base);
	// lfs f0,104(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 104);
	f0.f64 = double(temp.f32);
	// fnmsubs f13,f1,f27,f0
	ctx.f13.f64 = double(float(-(ctx.f1.f64 * f27.f64 - f0.f64)));
	// stfs f13,104(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// addi r3,r31,964
	ctx.r3.s64 = r31.s64 + 964;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x822a49d0
	ctx.lr = 0x82536AEC;
	sub_822A49D0(ctx, base);
	// lfs f12,104(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f1,f27,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 * f27.f64 + ctx.f12.f64));
	// stfs f11,104(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// b 0x82536b24
	goto loc_82536B24;
loc_82536AFC:
	// bl 0x822a49d0
	ctx.lr = 0x82536B00;
	sub_822A49D0(ctx, base);
	// lfs f0,100(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 100);
	f0.f64 = double(temp.f32);
	// fnmsubs f13,f1,f27,f0
	ctx.f13.f64 = double(float(-(ctx.f1.f64 * f27.f64 - f0.f64)));
	// stfs f13,100(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// addi r3,r31,964
	ctx.r3.s64 = r31.s64 + 964;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x822a49d0
	ctx.lr = 0x82536B18;
	sub_822A49D0(ctx, base);
	// lfs f12,100(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f1,f27,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 * f27.f64 + ctx.f12.f64));
	// stfs f11,100(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
loc_82536B24:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821b9c70
	ctx.lr = 0x82536B2C;
	sub_821B9C70(ctx, base);
loc_82536B2C:
	// lbz r11,1020(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1020);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82536b5c
	if (cr6.eq) goto loc_82536B5C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f31,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// bl 0x82202ec0
	ctx.lr = 0x82536B5C;
	sub_82202EC0(ctx, base);
loc_82536B5C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba1c
	ctx.lr = 0x82536B6C;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82536B70"))) PPC_WEAK_FUNC(sub_82536B70);
PPC_FUNC_IMPL(__imp__sub_82536B70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// li r11,240
	r11.s64 = 240;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r9,256
	ctx.r9.s64 = 256;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,16(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82536B98"))) PPC_WEAK_FUNC(sub_82536B98);
PPC_FUNC_IMPL(__imp__sub_82536B98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82536BA0;
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-64
	r12.s64 = -64;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,16
	r28.s64 = 16;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// li r29,32
	r29.s64 = 32;
	// vupkd3d128 v126,v127,4
	temp.f32 = 3.0f;
	temp.s32 += v127.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v127.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v126 = vTemp;
	// li r30,48
	r30.s64 = 48;
	// li r11,240
	r11.s64 = 240;
	// li r10,96
	ctx.r10.s64 = 96;
	// li r9,256
	ctx.r9.s64 = 256;
	// vpermwi128 v63,v126,234
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v126.u32), 0x15));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// vpermwi128 v62,v126,186
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v126.u32), 0x45));
	// addi r5,r31,32
	ctx.r5.s64 = r31.s64 + 32;
	// vpermwi128 v61,v126,174
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v126.u32), 0x51));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r3,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r3,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r3,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r31,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r3,r30
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r31,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v57,v59,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v58.f32)));
	// stvx128 v57,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x82536C20;
	sub_82202EC0(ctx, base);
	// vpermwi128 v56,v126,234
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v126.u32), 0x15));
	// vpermwi128 v55,v126,186
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v126.u32), 0x45));
	// addi r11,r31,112
	r11.s64 = r31.s64 + 112;
	// vpermwi128 v54,v126,174
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v126.u32), 0x51));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// li r4,0
	ctx.r4.s64 = 0;
	// lis r3,-32112
	ctx.r3.s64 = -2104492032;
	// stvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r4,397(r31)
	PPC_STORE_U8(r31.u32 + 397, ctx.r4.u8);
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,376(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 376, temp.u32);
	// stfs f0,372(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 372, temp.u32);
	// stfs f0,368(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 368, temp.u32);
	// stfs f13,380(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 380, temp.u32);
	// stfs f13,352(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 352, temp.u32);
	// lwz r11,21772(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 21772);
	// stw r11,384(r31)
	PPC_STORE_U32(r31.u32 + 384, r11.u32);
	// lwz r11,21784(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 21784);
	// stw r11,388(r31)
	PPC_STORE_U32(r31.u32 + 388, r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-64
	r0.s64 = -64;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82536C9C"))) PPC_WEAK_FUNC(sub_82536C9C);
PPC_FUNC_IMPL(__imp__sub_82536C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82536CA0"))) PPC_WEAK_FUNC(sub_82536CA0);
PPC_FUNC_IMPL(__imp__sub_82536CA0) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,15360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15360);
	f0.f64 = double(temp.f32);
	// addi r5,r10,-27912
	ctx.r5.s64 = ctx.r10.s64 + -27912;
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r8,r9,24,0,7
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFF000000;
	// oris r30,r8,255
	r30.u64 = ctx.r8.u64 | 16711680;
	// ori r30,r30,65535
	r30.u64 = r30.u64 | 65535;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82501dd8
	ctx.lr = 0x82536CF4;
	sub_82501DD8(ctx, base);
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,-27948
	ctx.r5.s64 = ctx.r7.s64 + -27948;
	// bl 0x82501dd8
	ctx.lr = 0x82536D0C;
	sub_82501DD8(ctx, base);
	// lis r5,-32248
	ctx.r5.s64 = -2113404928;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r5,-27972
	ctx.r5.s64 = ctx.r5.s64 + -27972;
	// bl 0x82501dd8
	ctx.lr = 0x82536D24;
	sub_82501DD8(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r11,-28000
	ctx.r5.s64 = r11.s64 + -28000;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82501dd8
	ctx.lr = 0x82536D3C;
	sub_82501DD8(ctx, base);
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

__attribute__((alias("__imp__sub_82536D54"))) PPC_WEAK_FUNC(sub_82536D54);
PPC_FUNC_IMPL(__imp__sub_82536D54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82536D58"))) PPC_WEAK_FUNC(sub_82536D58);
PPC_FUNC_IMPL(__imp__sub_82536D58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,396(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 396);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82536da0
	if (cr6.eq) goto loc_82536DA0;
	// addi r4,r31,48
	ctx.r4.s64 = r31.s64 + 48;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821713c0
	ctx.lr = 0x82536D84;
	sub_821713C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82536da0
	if (cr6.eq) goto loc_82536DA0;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r10,160
	ctx.r10.s64 = 160;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82536DA0:
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r31,176
	ctx.r10.s64 = r31.s64 + 176;
	// addi r8,r11,48
	ctx.r8.s64 = r11.s64 + 48;
	// addi r7,r11,32
	ctx.r7.s64 = r11.s64 + 32;
	// addi r6,r11,16
	ctx.r6.s64 = r11.s64 + 16;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,32
	ctx.r4.s64 = 32;
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r10,48
	ctx.r9.s64 = ctx.r10.s64 + 48;
	// lvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r6
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v61,v59
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v56,v58,v60
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrglw128 v55,v58,v60
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrglw128 v54,v61,v59
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v53,v57,v56
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrglw128 v52,v57,v56
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v51,v54,v55
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// stvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r10,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r10,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r0,r7
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r0,r6
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r0,r8
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r0,r11
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v45,v50,v48
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v48.f32), 0xEF));
	// vmsum3fp128 v46,v47,v48
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v48.f32), 0xEF));
	// vmsum3fp128 v44,v49,v48
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v48.f32), 0xEF));
	// vmrghw128 v43,v45,v46
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v42,v44,v43
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrghw128 v41,v43,v42
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vor128 v40,v41,v41
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_load_si128((simde__m128i*)v41.u8));
	// stvx128 v41,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v39,v62,v40
	simde_mm_store_ps(v39.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v40.f32)));
	// stvx128 v39,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

__attribute__((alias("__imp__sub_82536E48"))) PPC_WEAK_FUNC(sub_82536E48);
PPC_FUNC_IMPL(__imp__sub_82536E48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// stfs f1,240(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 240, temp.u32);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f2,244(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 244, temp.u32);
	// stfs f3,248(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 248, temp.u32);
	// stb r10,396(r31)
	PPC_STORE_U8(r31.u32 + 396, ctx.r10.u8);
	// stfs f4,356(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 356, temp.u32);
	// stfs f31,400(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 400, temp.u32);
	// stfs f31,404(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 404, temp.u32);
	// stfs f31,256(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 256, temp.u32);
	// stfs f31,260(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 260, temp.u32);
	// stfs f31,264(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 264, temp.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82536EA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82536d58
	ctx.lr = 0x82536EB0;
	sub_82536D58(ctx, base);
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

__attribute__((alias("__imp__sub_82536EC8"))) PPC_WEAK_FUNC(sub_82536EC8);
PPC_FUNC_IMPL(__imp__sub_82536EC8) {
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
	// bl 0x82536d58
	ctx.lr = 0x82536ED8;
	sub_82536D58(ctx, base);
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

__attribute__((alias("__imp__sub_82536EEC"))) PPC_WEAK_FUNC(sub_82536EEC);
PPC_FUNC_IMPL(__imp__sub_82536EEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82536EF0"))) PPC_WEAK_FUNC(sub_82536EF0);
PPC_FUNC_IMPL(__imp__sub_82536EF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f29,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f29.u64);
	// stfd f30,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f30.u64);
	// stfd f31,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,272
	ctx.r3.s64 = r31.s64 + 272;
	// li r30,0
	r30.s64 = 0;
	// lfs f31,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
	// bl 0x8260b990
	ctx.lr = 0x82536F30;
	sub_8260B990(ctx, base);
	// lbz r9,1062(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1062);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lbz r8,1060(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 1060);
	// xor r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// lfs f0,17032(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	f0.f64 = double(temp.f32);
	// subfic r5,r6,127
	xer.ca = ctx.r6.u32 <= 127;
	ctx.r5.s64 = 127 - ctx.r6.s64;
	// subfe r4,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + xer.ca < xer.ca);
	ctx.r4.u64 = ~ctx.r5.u64 + ctx.r5.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r4,31
	ctx.r3.u64 = ctx.r4.u32 & 0x1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82536fd0
	if (!cr6.eq) goto loc_82536FD0;
	// lbz r11,1086(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1086);
	// lbz r10,1084(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1084);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82536fd0
	if (!cr6.eq) goto loc_82536FD0;
	// lbz r11,1050(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1050);
	// lbz r10,1048(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1048);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82536fc8
	if (!cr6.eq) goto loc_82536FC8;
	// lbz r11,1098(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1098);
	// lbz r10,1096(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1096);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82536fd8
	if (cr6.eq) goto loc_82536FD8;
loc_82536FC8:
	// fmr f31,f0
	ctx.fpscr.disableFlushMode();
	f31.f64 = f0.f64;
	// b 0x82536fd8
	goto loc_82536FD8;
loc_82536FD0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,27640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f31.f64 = double(temp.f32);
loc_82536FD8:
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lwz r6,1172(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1172);
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// lwz r8,1168(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1168);
	// lwz r10,21784(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 21784);
	// lwz r11,21772(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 21772);
	// subf r5,r6,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r6.s64;
	// subf r4,r8,r11
	ctx.r4.s64 = r11.s64 - ctx.r8.s64;
	// extsw r3,r5
	ctx.r3.s64 = ctx.r5.s32;
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// stw r11,1168(r31)
	PPC_STORE_U32(r31.u32 + 1168, r11.u32);
	// lwz r11,21784(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 21784);
	// stw r11,1172(r31)
	PPC_STORE_U32(r31.u32 + 1172, r11.u32);
	// lbz r9,1074(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1074);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lbz r8,1072(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 1072);
	// xor r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// fcfid f10,f13
	ctx.f10.f64 = double(ctx.f13.s64);
	// frsp f13,f11
	ctx.f13.f64 = double(float(ctx.f11.f64));
	// subfic r5,r6,127
	xer.ca = ctx.r6.u32 <= 127;
	ctx.r5.s64 = 127 - ctx.r6.s64;
	// subfe r4,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + xer.ca < xer.ca);
	ctx.r4.u64 = ~ctx.r5.u64 + ctx.r5.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r4,31
	ctx.r3.u64 = ctx.r4.u32 & 0x1;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// frsp f12,f10
	ctx.f12.f64 = double(float(ctx.f10.f64));
	// beq cr6,0x82537160
	if (cr6.eq) goto loc_82537160;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r10,21788(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 21788);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82537100
	if (cr6.eq) goto loc_82537100;
	// fmuls f0,f13,f31
	f0.f64 = double(float(ctx.f13.f64 * f31.f64));
	// lfs f13,56(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// lfs f10,64(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	ctx.f10.f64 = double(temp.f32);
	// lbz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// fnmsubs f9,f0,f30,f13
	ctx.f9.f64 = double(float(-(f0.f64 * f30.f64 - ctx.f13.f64)));
	// stfs f9,56(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// fmadds f0,f11,f30,f10
	f0.f64 = double(float(ctx.f11.f64 * f30.f64 + ctx.f10.f64));
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// beq cr6,0x825370c8
	if (cr6.eq) goto loc_825370C8;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x825370ac
	if (!cr6.gt) goto loc_825370AC;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f0,18572(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 18572);
	f0.f64 = double(temp.f32);
	// b 0x825370fc
	goto loc_825370FC;
loc_825370AC:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f13,2432(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 2432);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82537100
	if (!cr6.lt) goto loc_82537100;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lfs f0,-27560(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -27560);
	f0.f64 = double(temp.f32);
	// b 0x825370fc
	goto loc_825370FC;
loc_825370C8:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,26468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 26468);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x825370e4
	if (!cr6.gt) goto loc_825370E4;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lfs f0,-27564(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -27564);
	f0.f64 = double(temp.f32);
	// b 0x825370fc
	goto loc_825370FC;
loc_825370E4:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f13,23884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 23884);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82537100
	if (!cr6.lt) goto loc_82537100;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// lfs f0,-27568(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -27568);
	f0.f64 = double(temp.f32);
loc_825370FC:
	// stfs f0,64(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
loc_82537100:
	// lwz r10,21788(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 21788);
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82537120
	if (cr6.eq) goto loc_82537120;
	// fmuls f0,f12,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f12.f64 * f31.f64));
	// lfs f13,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f11,f0,f30,f13
	ctx.f11.f64 = double(float(f0.f64 * f30.f64 + ctx.f13.f64));
	// stfs f11,52(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
loc_82537120:
	// lwz r11,21788(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 21788);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82537300
	if (cr6.eq) goto loc_82537300;
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// fmuls f0,f12,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f12.f64 * f31.f64));
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82537150
	if (cr6.eq) goto loc_82537150;
	// lfs f13,88(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f0,f30,f13
	ctx.f12.f64 = double(float(f0.f64 * f30.f64 + ctx.f13.f64));
	// stfs f12,88(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// b 0x82537300
	goto loc_82537300;
loc_82537150:
	// lfs f13,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f0,f30,f13
	ctx.f12.f64 = double(float(f0.f64 * f30.f64 + ctx.f13.f64));
	// stfs f12,84(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// b 0x82537300
	goto loc_82537300;
loc_82537160:
	// lbz r11,1146(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1146);
	// lbz r10,1144(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1144);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x825371b0
	if (cr6.eq) goto loc_825371B0;
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825371a0
	if (cr6.eq) goto loc_825371A0;
	// lfs f13,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f31,f0,f13
	ctx.f12.f64 = double(float(f31.f64 * f0.f64 + ctx.f13.f64));
	// stfs f12,88(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// b 0x825371ac
	goto loc_825371AC;
loc_825371A0:
	// lfs f13,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f31,f0,f13
	ctx.f12.f64 = double(float(f31.f64 * f0.f64 + ctx.f13.f64));
	// stfs f12,84(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
loc_825371AC:
	// li r30,1
	r30.s64 = 1;
loc_825371B0:
	// lbz r11,1158(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1158);
	// lbz r10,1156(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1156);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82537200
	if (cr6.eq) goto loc_82537200;
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825371f0
	if (cr6.eq) goto loc_825371F0;
	// lfs f13,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f12,f31,f0,f13
	ctx.f12.f64 = double(float(-(f31.f64 * f0.f64 - ctx.f13.f64)));
	// stfs f12,88(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// b 0x825371fc
	goto loc_825371FC;
loc_825371F0:
	// lfs f13,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f12,f31,f0,f13
	ctx.f12.f64 = double(float(-(f31.f64 * f0.f64 - ctx.f13.f64)));
	// stfs f12,84(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
loc_825371FC:
	// li r30,1
	r30.s64 = 1;
loc_82537200:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// fmuls f31,f31,f30
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(f31.f64 * f30.f64));
	// addi r3,r31,1132
	ctx.r3.s64 = r31.s64 + 1132;
	// lfs f30,-332(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -332);
	f30.f64 = double(temp.f32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x822a48f0
	ctx.lr = 0x82537218;
	sub_822A48F0(ctx, base);
	// fmuls f0,f1,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 * f31.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f29,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f29.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// beq cr6,0x8253723c
	if (cr6.eq) goto loc_8253723C;
	// lfs f13,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// li r30,1
	r30.s64 = 1;
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,52(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
loc_8253723C:
	// addi r3,r31,1108
	ctx.r3.s64 = r31.s64 + 1108;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x822a48f0
	ctx.lr = 0x82537248;
	sub_822A48F0(ctx, base);
	// fmuls f0,f1,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 * f31.f64));
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// beq cr6,0x82537264
	if (cr6.eq) goto loc_82537264;
	// lfs f13,56(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// li r30,1
	r30.s64 = 1;
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stfs f12,56(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
loc_82537264:
	// addi r3,r31,1120
	ctx.r3.s64 = r31.s64 + 1120;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x822a48f0
	ctx.lr = 0x82537270;
	sub_822A48F0(ctx, base);
	// fmuls f0,f1,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 * f31.f64));
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// beq cr6,0x82537300
	if (cr6.eq) goto loc_82537300;
	// lfs f13,64(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	ctx.f13.f64 = double(temp.f32);
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// fadds f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825372c8
	if (cr6.eq) goto loc_825372C8;
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x825372ac
	if (!cr6.gt) goto loc_825372AC;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f0,18572(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18572);
	f0.f64 = double(temp.f32);
	// b 0x825372fc
	goto loc_825372FC;
loc_825372AC:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f13,2432(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 2432);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82537300
	if (!cr6.lt) goto loc_82537300;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lfs f0,-27560(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -27560);
	f0.f64 = double(temp.f32);
	// b 0x825372fc
	goto loc_825372FC;
loc_825372C8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,26468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 26468);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x825372e4
	if (!cr6.gt) goto loc_825372E4;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lfs f0,-27564(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -27564);
	f0.f64 = double(temp.f32);
	// b 0x825372fc
	goto loc_825372FC;
loc_825372E4:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f13,23884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 23884);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82537300
	if (!cr6.lt) goto loc_82537300;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lfs f0,-27568(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -27568);
	f0.f64 = double(temp.f32);
loc_825372FC:
	// stfs f0,64(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
loc_82537300:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f29,-48(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
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

__attribute__((alias("__imp__sub_82537328"))) PPC_WEAK_FUNC(sub_82537328);
PPC_FUNC_IMPL(__imp__sub_82537328) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,12(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,-32
	ctx.r10.s64 = ctx.r1.s64 + -32;
	// lvx128 v0,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,240
	ctx.r9.s64 = 240;
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// lfs f0,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// li r6,80
	ctx.r6.s64 = 80;
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,-32(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// lvlx128 v63,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v12,r3,r9
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v12,v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,-8(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f9.f64 = double(temp.f32);
	// stvx128 v11,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,-8(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f6,f9
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f9.f64));
	// fsubs f4,f8,f11
	ctx.f4.f64 = double(float(ctx.f8.f64 - ctx.f11.f64));
	// fmuls f3,f5,f5
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f5.f64));
	// fsubs f2,f7,f10
	ctx.f2.f64 = double(float(ctx.f7.f64 - ctx.f10.f64));
	// fmadds f1,f4,f4,f3
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f3.f64));
	// fmadds f0,f2,f2,f1
	f0.f64 = double(float(ctx.f2.f64 * ctx.f2.f64 + ctx.f1.f64));
	// fsqrts f13,f0
	ctx.f13.f64 = double(float(sqrt(f0.f64)));
	// stfs f13,52(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stvx128 v0,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825373AC"))) PPC_WEAK_FUNC(sub_825373AC);
PPC_FUNC_IMPL(__imp__sub_825373AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825373B0"))) PPC_WEAK_FUNC(sub_825373B0);
PPC_FUNC_IMPL(__imp__sub_825373B0) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,15360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15360);
	f0.f64 = double(temp.f32);
	// addi r5,r10,-27488
	ctx.r5.s64 = ctx.r10.s64 + -27488;
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r8,r9,24,0,7
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFF000000;
	// oris r30,r8,255
	r30.u64 = ctx.r8.u64 | 16711680;
	// ori r30,r30,65535
	r30.u64 = r30.u64 | 65535;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82501dd8
	ctx.lr = 0x82537404;
	sub_82501DD8(ctx, base);
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,-27524
	ctx.r5.s64 = ctx.r7.s64 + -27524;
	// bl 0x82501dd8
	ctx.lr = 0x8253741C;
	sub_82501DD8(ctx, base);
	// lis r6,-32248
	ctx.r6.s64 = -2113404928;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r6,-27556
	ctx.r5.s64 = ctx.r6.s64 + -27556;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82501dd8
	ctx.lr = 0x82537434;
	sub_82501DD8(ctx, base);
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

__attribute__((alias("__imp__sub_8253744C"))) PPC_WEAK_FUNC(sub_8253744C);
PPC_FUNC_IMPL(__imp__sub_8253744C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82537450"))) PPC_WEAK_FUNC(sub_82537450);
PPC_FUNC_IMPL(__imp__sub_82537450) {
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
	ctx.lr = 0x82537458;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r31,208
	r30.s64 = r31.s64 + 208;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// lfs f0,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	f0.f64 = double(temp.f32);
	// lfs f13,56(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// lfs f3,64(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	ctx.f3.f64 = double(temp.f32);
	// fadds f2,f0,f13
	ctx.f2.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfs f1,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82535dd8
	ctx.lr = 0x82537480;
	sub_82535DD8(ctx, base);
	// addi r11,r31,256
	r11.s64 = r31.s64 + 256;
	// addi r10,r31,80
	ctx.r10.s64 = r31.s64 + 80;
	// li r27,32
	r27.s64 = 32;
	// li r28,48
	r28.s64 = 48;
	// li r29,16
	r29.s64 = 16;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,96(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82537530
	if (cr6.eq) goto loc_82537530;
	// vor128 v59,v61,v61
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// lvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v58,v59,v60
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	// stvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r9,100(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 100);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82537530
	if (cr6.eq) goto loc_82537530;
	// vor128 v56,v58,v58
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// lvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v55,v56,v57
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v47,v55,v55
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// lvx128 v51,r30,r28
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r30,r29
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r10
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r30,r27
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r30
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v48,v53,v54
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrghw128 v49,v50,v51
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrglw128 v46,v53,v54
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrglw128 v45,v50,v51
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrghw128 v44,v48,v49
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrglw128 v43,v48,v49
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v42,v46,v45
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmsum3fp128 v41,v52,v44
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v44.f32), 0xEF));
	// vmsum3fp128 v40,v52,v43
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v43.f32), 0xEF));
	// vmsum3fp128 v39,v52,v42
	simde_mm_store_ps(v39.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v42.f32), 0xEF));
	// vmrghw128 v38,v41,v39
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// vmrghw128 v37,v40,v38
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmrghw128 v36,v38,v37
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vaddfp128 v35,v47,v36
	simde_mm_store_ps(v35.f32, simde_mm_add_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v36.f32)));
	// stvx128 v35,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82537530:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821713c0
	ctx.lr = 0x8253753C;
	sub_821713C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825375b4
	if (cr6.eq) goto loc_825375B4;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r11,2384
	ctx.r9.s64 = r11.s64 + 2384;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r11,r31,144
	r11.s64 = r31.s64 + 144;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvx128 v34,r0,r10
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// vand128 v33,v34,v63
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v32,r0,r8
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r5,2352
	ctx.r4.s64 = ctx.r5.s64 + 2352;
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v33,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v60,v32,v63
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v60,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v59,v62,v63
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v59,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v58,v61,v63
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v57,v63,v58
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v58.u8)));
	// stvx128 v57,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_825375B4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_825375BC"))) PPC_WEAK_FUNC(sub_825375BC);
PPC_FUNC_IMPL(__imp__sub_825375BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825375C0"))) PPC_WEAK_FUNC(sub_825375C0);
PPC_FUNC_IMPL(__imp__sub_825375C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// bl 0x823d91f8
	ctx.lr = 0x825375C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
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
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r6,128
	ctx.r6.s64 = 128;
	// lfs f13,14988(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// li r5,80
	ctx.r5.s64 = 80;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r10,r31,208
	ctx.r10.s64 = r31.s64 + 208;
	// lfs f12,3732(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3732);
	ctx.f12.f64 = double(temp.f32);
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// li r9,16
	ctx.r9.s64 = 16;
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// li r11,0
	r11.s64 = 0;
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// li r8,32
	ctx.r8.s64 = 32;
	// li r29,48
	r29.s64 = 48;
	// lfs f11,14992(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14992);
	ctx.f11.f64 = double(temp.f32);
	// stvx128 v1,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,272(r31)
	PPC_STORE_U32(r31.u32 + 272, r11.u32);
	// stvx128 v1,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
	// stfs f1,52(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stw r11,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r11.u32);
	// stfs f2,56(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stb r11,100(r31)
	PPC_STORE_U8(r31.u32 + 100, r11.u8);
	// stfs f3,64(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// li r28,1
	r28.s64 = 1;
	// stfs f0,60(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// addi r30,r31,272
	r30.s64 = r31.s64 + 272;
	// stfs f1,108(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stfs f2,112(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stfs f3,116(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// addi r6,r31,1132
	ctx.r6.s64 = r31.s64 + 1132;
	// stfs f13,68(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stfs f12,72(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// li r4,9
	ctx.r4.s64 = 9;
	// stfs f11,76(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r28,48(r31)
	PPC_STORE_U8(r31.u32 + 48, r28.u8);
	// stw r11,1172(r31)
	PPC_STORE_U32(r31.u32 + 1172, r11.u32);
	// stw r11,1168(r31)
	PPC_STORE_U32(r31.u32 + 1168, r11.u32);
	// bl 0x8260b740
	ctx.lr = 0x8253769C;
	sub_8260B740(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// addi r6,r31,1108
	ctx.r6.s64 = r31.s64 + 1108;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x8260b740
	ctx.lr = 0x825376B4;
	sub_8260B740(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// addi r6,r31,1120
	ctx.r6.s64 = r31.s64 + 1120;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x8260b740
	ctx.lr = 0x825376CC;
	sub_8260B740(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// addi r6,r31,1144
	ctx.r6.s64 = r31.s64 + 1144;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8260b740
	ctx.lr = 0x825376E4;
	sub_8260B740(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// addi r6,r31,1156
	ctx.r6.s64 = r31.s64 + 1156;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8260b740
	ctx.lr = 0x825376FC;
	sub_8260B740(ctx, base);
	// addi r6,r31,1096
	ctx.r6.s64 = r31.s64 + 1096;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8260b740
	ctx.lr = 0x82537714;
	sub_8260B740(ctx, base);
	// addi r6,r31,1084
	ctx.r6.s64 = r31.s64 + 1084;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8260b740
	ctx.lr = 0x8253772C;
	sub_8260B740(ctx, base);
	// addi r7,r31,1048
	ctx.r7.s64 = r31.s64 + 1048;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r6,54
	ctx.r6.s64 = 54;
	// li r5,42
	ctx.r5.s64 = 42;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b790
	ctx.lr = 0x82537744;
	sub_8260B790(ctx, base);
	// addi r7,r31,1060
	ctx.r7.s64 = r31.s64 + 1060;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r6,157
	ctx.r6.s64 = 157;
	// li r5,29
	ctx.r5.s64 = 29;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b790
	ctx.lr = 0x8253775C;
	sub_8260B790(ctx, base);
	// addi r7,r31,1072
	ctx.r7.s64 = r31.s64 + 1072;
	// li r6,184
	ctx.r6.s64 = 184;
	// li r5,56
	ctx.r5.s64 = 56;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8260b790
	ctx.lr = 0x82537774;
	sub_8260B790(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82537450
	ctx.lr = 0x8253777C;
	sub_82537450(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82537784"))) PPC_WEAK_FUNC(sub_82537784);
PPC_FUNC_IMPL(__imp__sub_82537784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82537788"))) PPC_WEAK_FUNC(sub_82537788);
PPC_FUNC_IMPL(__imp__sub_82537788) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lfs f0,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f11,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lfs f8,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f10,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f7,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lbz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// fmuls f5,f12,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f31,f3
	f31.f64 = double(float(sqrt(ctx.f3.f64)));
	// beq cr6,0x82537840
	if (cr6.eq) goto loc_82537840;
	// lfs f0,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f11,f13,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f12.f64));
	// fsqrts f10,f11
	ctx.f10.f64 = double(float(sqrt(ctx.f11.f64)));
	// fdivs f1,f0,f10
	ctx.f1.f64 = double(float(f0.f64 / ctx.f10.f64));
	// bl 0x823dcb30
	ctx.lr = 0x8253781C;
	sub_823DCB30(ctx, base);
	// lfs f9,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f9.f64 = double(temp.f32);
	// frsp f30,f1
	f30.f64 = double(float(ctx.f1.f64));
	// fdivs f1,f9,f31
	ctx.f1.f64 = double(float(ctx.f9.f64 / f31.f64));
	// bl 0x823dcb30
	ctx.lr = 0x8253782C;
	sub_823DCB30(ctx, base);
	// frsp f8,f1
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(ctx.f1.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,26468(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 26468);
	f0.f64 = double(temp.f32);
	// fsubs f3,f0,f8
	ctx.f3.f64 = double(float(f0.f64 - ctx.f8.f64));
	// b 0x8253787c
	goto loc_8253787C;
loc_82537840:
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmadds f12,f0,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * f0.f64 + ctx.f13.f64));
	// fsqrts f11,f12
	ctx.f11.f64 = double(float(sqrt(ctx.f12.f64)));
	// fdivs f1,f0,f11
	ctx.f1.f64 = double(float(f0.f64 / ctx.f11.f64));
	// bl 0x823dcb30
	ctx.lr = 0x8253785C;
	sub_823DCB30(ctx, base);
	// lfs f10,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// frsp f30,f1
	f30.f64 = double(float(ctx.f1.f64));
	// fdivs f1,f10,f31
	ctx.f1.f64 = double(float(ctx.f10.f64 / f31.f64));
	// bl 0x823dcb30
	ctx.lr = 0x8253786C;
	sub_823DCB30(ctx, base);
	// frsp f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f1.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,26468(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 26468);
	f0.f64 = double(temp.f32);
	// fsubs f3,f0,f9
	ctx.f3.f64 = double(float(f0.f64 - ctx.f9.f64));
loc_8253787C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v1,r0,r31
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x825375c0
	ctx.lr = 0x82537890;
	sub_825375C0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
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

__attribute__((alias("__imp__sub_825378B0"))) PPC_WEAK_FUNC(sub_825378B0);
PPC_FUNC_IMPL(__imp__sub_825378B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// li r11,128
	r11.s64 = 128;
	// lfs f3,116(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,112(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,108(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v1,r3,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x825375c0
	sub_825375C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_825378C8"))) PPC_WEAK_FUNC(sub_825378C8);
PPC_FUNC_IMPL(__imp__sub_825378C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f30{};
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
	// stfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f30.u64);
	// stfd f31,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// li r30,0
	r30.s64 = 0;
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82537904
	if (cr6.eq) goto loc_82537904;
	// bl 0x82536ef0
	ctx.lr = 0x82537900;
	sub_82536EF0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_82537904:
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82537968
	if (cr6.eq) goto loc_82537968;
	// lbz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// lfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82537928
	if (cr6.eq) goto loc_82537928;
	// lfs f2,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// b 0x8253792c
	goto loc_8253792C;
loc_82537928:
	// lfs f2,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
loc_8253792C:
	// bl 0x823dcdd8
	ctx.lr = 0x82537930;
	sub_823DCDD8(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(ctx.f1.f64));
	// lfs f1,76(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,-26872(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -26872);
	f0.f64 = double(temp.f32);
	// fmuls f2,f30,f0
	ctx.f2.f64 = double(float(f30.f64 * f0.f64));
	// bl 0x823dc480
	ctx.lr = 0x82537948;
	sub_823DC480(ctx, base);
	// lfs f0,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	f0.f64 = double(temp.f32);
	// frsp f30,f1
	f30.f64 = double(float(ctx.f1.f64));
	// fsubs f1,f31,f0
	ctx.f1.f64 = double(float(f31.f64 - f0.f64));
	// bl 0x821bb3d8
	ctx.lr = 0x82537958;
	sub_821BB3D8(ctx, base);
	// lfs f13,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f1,f1,f30,f13
	ctx.f1.f64 = double(float(ctx.f1.f64 * f30.f64 + ctx.f13.f64));
	// bl 0x821bb3d8
	ctx.lr = 0x82537964;
	sub_821BB3D8(ctx, base);
	// stfs f1,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
loc_82537968:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82537450
	ctx.lr = 0x82537970;
	sub_82537450(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
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

__attribute__((alias("__imp__sub_82537994"))) PPC_WEAK_FUNC(sub_82537994);
PPC_FUNC_IMPL(__imp__sub_82537994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82537998"))) PPC_WEAK_FUNC(sub_82537998);
PPC_FUNC_IMPL(__imp__sub_82537998) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x823d91c8
	ctx.lr = 0x825379A0;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r9,r11,-31616
	ctx.r9.s64 = r11.s64 + -31616;
	// li r16,32
	r16.s64 = 32;
	// addi r8,r10,31476
	ctx.r8.s64 = ctx.r10.s64 + 31476;
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// li r30,0
	r30.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// addi r6,r7,-27112
	ctx.r6.s64 = ctx.r7.s64 + -27112;
	// stb r30,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r30.u8);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r16
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r16.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// addi r29,r31,48
	r29.s64 = r31.s64 + 48;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8260b730
	ctx.lr = 0x825379E8;
	sub_8260B730(ctx, base);
	// stb r30,824(r31)
	PPC_STORE_U8(r31.u32 + 824, r30.u8);
	// stb r30,825(r31)
	PPC_STORE_U8(r31.u32 + 825, r30.u8);
	// addi r6,r31,824
	ctx.r6.s64 = r31.s64 + 824;
	// stb r30,826(r31)
	PPC_STORE_U8(r31.u32 + 826, r30.u8);
	// addi r21,r31,836
	r21.s64 = r31.s64 + 836;
	// stb r30,827(r31)
	PPC_STORE_U8(r31.u32 + 827, r30.u8);
	// addi r28,r31,848
	r28.s64 = r31.s64 + 848;
	// stb r30,828(r31)
	PPC_STORE_U8(r31.u32 + 828, r30.u8);
	// addi r27,r31,860
	r27.s64 = r31.s64 + 860;
	// stw r30,832(r31)
	PPC_STORE_U32(r31.u32 + 832, r30.u32);
	// addi r26,r31,872
	r26.s64 = r31.s64 + 872;
	// stb r30,836(r31)
	PPC_STORE_U8(r31.u32 + 836, r30.u8);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r30,837(r31)
	PPC_STORE_U8(r31.u32 + 837, r30.u8);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stb r30,838(r31)
	PPC_STORE_U8(r31.u32 + 838, r30.u8);
	// stb r30,839(r31)
	PPC_STORE_U8(r31.u32 + 839, r30.u8);
	// stb r30,840(r31)
	PPC_STORE_U8(r31.u32 + 840, r30.u8);
	// stw r30,844(r31)
	PPC_STORE_U32(r31.u32 + 844, r30.u32);
	// stb r30,848(r31)
	PPC_STORE_U8(r31.u32 + 848, r30.u8);
	// stb r30,849(r31)
	PPC_STORE_U8(r31.u32 + 849, r30.u8);
	// stb r30,850(r31)
	PPC_STORE_U8(r31.u32 + 850, r30.u8);
	// stb r30,851(r31)
	PPC_STORE_U8(r31.u32 + 851, r30.u8);
	// stb r30,852(r31)
	PPC_STORE_U8(r31.u32 + 852, r30.u8);
	// stw r30,856(r31)
	PPC_STORE_U32(r31.u32 + 856, r30.u32);
	// stb r30,860(r31)
	PPC_STORE_U8(r31.u32 + 860, r30.u8);
	// stb r30,861(r31)
	PPC_STORE_U8(r31.u32 + 861, r30.u8);
	// stb r30,862(r31)
	PPC_STORE_U8(r31.u32 + 862, r30.u8);
	// stb r30,863(r31)
	PPC_STORE_U8(r31.u32 + 863, r30.u8);
	// stb r30,864(r31)
	PPC_STORE_U8(r31.u32 + 864, r30.u8);
	// stw r30,868(r31)
	PPC_STORE_U32(r31.u32 + 868, r30.u32);
	// stb r30,872(r31)
	PPC_STORE_U8(r31.u32 + 872, r30.u8);
	// stb r30,873(r31)
	PPC_STORE_U8(r31.u32 + 873, r30.u8);
	// stb r30,874(r31)
	PPC_STORE_U8(r31.u32 + 874, r30.u8);
	// stb r30,875(r31)
	PPC_STORE_U8(r31.u32 + 875, r30.u8);
	// stb r30,876(r31)
	PPC_STORE_U8(r31.u32 + 876, r30.u8);
	// stw r30,880(r31)
	PPC_STORE_U32(r31.u32 + 880, r30.u32);
	// stb r30,884(r31)
	PPC_STORE_U8(r31.u32 + 884, r30.u8);
	// stb r30,885(r31)
	PPC_STORE_U8(r31.u32 + 885, r30.u8);
	// stb r30,886(r31)
	PPC_STORE_U8(r31.u32 + 886, r30.u8);
	// stb r30,887(r31)
	PPC_STORE_U8(r31.u32 + 887, r30.u8);
	// stb r30,888(r31)
	PPC_STORE_U8(r31.u32 + 888, r30.u8);
	// stw r30,892(r31)
	PPC_STORE_U32(r31.u32 + 892, r30.u32);
	// stb r30,896(r31)
	PPC_STORE_U8(r31.u32 + 896, r30.u8);
	// stb r30,897(r31)
	PPC_STORE_U8(r31.u32 + 897, r30.u8);
	// stb r30,898(r31)
	PPC_STORE_U8(r31.u32 + 898, r30.u8);
	// stb r30,899(r31)
	PPC_STORE_U8(r31.u32 + 899, r30.u8);
	// stb r30,900(r31)
	PPC_STORE_U8(r31.u32 + 900, r30.u8);
	// stw r30,904(r31)
	PPC_STORE_U32(r31.u32 + 904, r30.u32);
	// stb r30,908(r31)
	PPC_STORE_U8(r31.u32 + 908, r30.u8);
	// stb r30,909(r31)
	PPC_STORE_U8(r31.u32 + 909, r30.u8);
	// stb r30,910(r31)
	PPC_STORE_U8(r31.u32 + 910, r30.u8);
	// stb r30,911(r31)
	PPC_STORE_U8(r31.u32 + 911, r30.u8);
	// stb r30,912(r31)
	PPC_STORE_U8(r31.u32 + 912, r30.u8);
	// stw r30,916(r31)
	PPC_STORE_U32(r31.u32 + 916, r30.u32);
	// stb r30,920(r31)
	PPC_STORE_U8(r31.u32 + 920, r30.u8);
	// stb r30,921(r31)
	PPC_STORE_U8(r31.u32 + 921, r30.u8);
	// stb r30,922(r31)
	PPC_STORE_U8(r31.u32 + 922, r30.u8);
	// stb r30,923(r31)
	PPC_STORE_U8(r31.u32 + 923, r30.u8);
	// stb r30,924(r31)
	PPC_STORE_U8(r31.u32 + 924, r30.u8);
	// stw r30,928(r31)
	PPC_STORE_U32(r31.u32 + 928, r30.u32);
	// stb r30,932(r31)
	PPC_STORE_U8(r31.u32 + 932, r30.u8);
	// stb r30,933(r31)
	PPC_STORE_U8(r31.u32 + 933, r30.u8);
	// stb r30,934(r31)
	PPC_STORE_U8(r31.u32 + 934, r30.u8);
	// stb r30,935(r31)
	PPC_STORE_U8(r31.u32 + 935, r30.u8);
	// li r5,2
	ctx.r5.s64 = 2;
	// stb r30,936(r31)
	PPC_STORE_U8(r31.u32 + 936, r30.u8);
	// li r4,9
	ctx.r4.s64 = 9;
	// stw r30,940(r31)
	PPC_STORE_U32(r31.u32 + 940, r30.u32);
	// addi r25,r31,884
	r25.s64 = r31.s64 + 884;
	// stb r30,944(r31)
	PPC_STORE_U8(r31.u32 + 944, r30.u8);
	// addi r24,r31,896
	r24.s64 = r31.s64 + 896;
	// stb r30,945(r31)
	PPC_STORE_U8(r31.u32 + 945, r30.u8);
	// addi r23,r31,908
	r23.s64 = r31.s64 + 908;
	// stb r30,946(r31)
	PPC_STORE_U8(r31.u32 + 946, r30.u8);
	// addi r22,r31,920
	r22.s64 = r31.s64 + 920;
	// stb r30,947(r31)
	PPC_STORE_U8(r31.u32 + 947, r30.u8);
	// addi r20,r31,932
	r20.s64 = r31.s64 + 932;
	// stb r30,948(r31)
	PPC_STORE_U8(r31.u32 + 948, r30.u8);
	// addi r19,r31,944
	r19.s64 = r31.s64 + 944;
	// stw r30,952(r31)
	PPC_STORE_U32(r31.u32 + 952, r30.u32);
	// addi r18,r31,956
	r18.s64 = r31.s64 + 956;
	// stb r30,956(r31)
	PPC_STORE_U8(r31.u32 + 956, r30.u8);
	// addi r17,r31,968
	r17.s64 = r31.s64 + 968;
	// stb r30,957(r31)
	PPC_STORE_U8(r31.u32 + 957, r30.u8);
	// stb r30,958(r31)
	PPC_STORE_U8(r31.u32 + 958, r30.u8);
	// stb r30,959(r31)
	PPC_STORE_U8(r31.u32 + 959, r30.u8);
	// stb r30,960(r31)
	PPC_STORE_U8(r31.u32 + 960, r30.u8);
	// stw r30,964(r31)
	PPC_STORE_U32(r31.u32 + 964, r30.u32);
	// stb r30,968(r31)
	PPC_STORE_U8(r31.u32 + 968, r30.u8);
	// stb r30,969(r31)
	PPC_STORE_U8(r31.u32 + 969, r30.u8);
	// stb r30,970(r31)
	PPC_STORE_U8(r31.u32 + 970, r30.u8);
	// stb r30,971(r31)
	PPC_STORE_U8(r31.u32 + 971, r30.u8);
	// stb r30,972(r31)
	PPC_STORE_U8(r31.u32 + 972, r30.u8);
	// stw r30,976(r31)
	PPC_STORE_U32(r31.u32 + 976, r30.u32);
	// stb r30,980(r31)
	PPC_STORE_U8(r31.u32 + 980, r30.u8);
	// stb r30,981(r31)
	PPC_STORE_U8(r31.u32 + 981, r30.u8);
	// stb r30,982(r31)
	PPC_STORE_U8(r31.u32 + 982, r30.u8);
	// stb r30,983(r31)
	PPC_STORE_U8(r31.u32 + 983, r30.u8);
	// stb r30,984(r31)
	PPC_STORE_U8(r31.u32 + 984, r30.u8);
	// stw r30,988(r31)
	PPC_STORE_U32(r31.u32 + 988, r30.u32);
	// addi r30,r31,980
	r30.s64 = r31.s64 + 980;
	// bl 0x8260b740
	ctx.lr = 0x82537B84;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r21
	ctx.r6.u64 = r21.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x8260b740
	ctx.lr = 0x82537B9C;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,4096
	ctx.r5.s64 = 4096;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8260b740
	ctx.lr = 0x82537BB4;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8260b740
	ctx.lr = 0x82537BCC;
	sub_8260B740(ctx, base);
	// lis r5,0
	ctx.r5.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// ori r5,r5,32768
	ctx.r5.u64 = ctx.r5.u64 | 32768;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8260b740
	ctx.lr = 0x82537BE8;
	sub_8260B740(ctx, base);
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8260b740
	ctx.lr = 0x82537C00;
	sub_8260B740(ctx, base);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8260b740
	ctx.lr = 0x82537C18;
	sub_8260B740(ctx, base);
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8260b740
	ctx.lr = 0x82537C30;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8260b740
	ctx.lr = 0x82537C48;
	sub_8260B740(ctx, base);
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8260b740
	ctx.lr = 0x82537C60;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,512
	ctx.r5.s64 = 512;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8260b740
	ctx.lr = 0x82537C78;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,17
	ctx.r5.s64 = 17;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b740
	ctx.lr = 0x82537C90;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r5,31
	ctx.r5.s64 = 31;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b740
	ctx.lr = 0x82537CA8;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// li r5,30
	ctx.r5.s64 = 30;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b740
	ctx.lr = 0x82537CC0;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b740
	ctx.lr = 0x82537CD8;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// li r5,44
	ctx.r5.s64 = 44;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b740
	ctx.lr = 0x82537CF0;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// li r5,46
	ctx.r5.s64 = 46;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b740
	ctx.lr = 0x82537D08;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// li r5,42
	ctx.r5.s64 = 42;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b740
	ctx.lr = 0x82537D20;
	sub_8260B740(ctx, base);
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r18
	ctx.r6.u64 = r18.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b740
	ctx.lr = 0x82537D38;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r19
	ctx.r6.u64 = r19.u64;
	// li r5,18
	ctx.r5.s64 = 18;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b740
	ctx.lr = 0x82537D50;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r17
	ctx.r6.u64 = r17.u64;
	// li r5,19
	ctx.r5.s64 = 19;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b740
	ctx.lr = 0x82537D68;
	sub_8260B740(ctx, base);
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,57
	ctx.r5.s64 = 57;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8260b740
	ctx.lr = 0x82537D80;
	sub_8260B740(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r11,r31,1104
	r11.s64 = r31.s64 + 1104;
	// li r4,16
	ctx.r4.s64 = 16;
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
	// li r3,48
	ctx.r3.s64 = 48;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f0,992(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 992, temp.u32);
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,14988(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14988);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r16
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r16.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f0,1008(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1008, temp.u32);
	// stfs f0,1012(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1012, temp.u32);
	// stfs f0,1016(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1016, temp.u32);
	// stfs f0,1024(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1024, temp.u32);
	// stfs f0,1028(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1028, temp.u32);
	// stfs f13,1032(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1032, temp.u32);
	// stfs f12,1156(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 1156, temp.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_82537DF4"))) PPC_WEAK_FUNC(sub_82537DF4);
PPC_FUNC_IMPL(__imp__sub_82537DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82537DF8"))) PPC_WEAK_FUNC(sub_82537DF8);
PPC_FUNC_IMPL(__imp__sub_82537DF8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,1104
	ctx.r3.s64 = ctx.r3.s64 + 1104;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82537E00"))) PPC_WEAK_FUNC(sub_82537E00);
PPC_FUNC_IMPL(__imp__sub_82537E00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r3,r11,-27060
	ctx.r3.s64 = r11.s64 + -27060;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82537E0C"))) PPC_WEAK_FUNC(sub_82537E0C);
PPC_FUNC_IMPL(__imp__sub_82537E0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82537E10"))) PPC_WEAK_FUNC(sub_82537E10);
PPC_FUNC_IMPL(__imp__sub_82537E10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// li r11,1008
	r11.s64 = 1008;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r9,1024
	ctx.r9.s64 = 1024;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,16(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82537E38"))) PPC_WEAK_FUNC(sub_82537E38);
PPC_FUNC_IMPL(__imp__sub_82537E38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r3,1104
	r11.s64 = ctx.r3.s64 + 1104;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
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
	// li r7,1024
	ctx.r7.s64 = 1024;
	// li r6,1008
	ctx.r6.s64 = 1008;
	// li r31,1152
	r31.s64 = 1152;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// addi r5,r3,32
	ctx.r5.s64 = ctx.r3.s64 + 32;
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r3,r7
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r3,r6
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r3,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lvx128 v56,r11,r10
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v55,v56,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v58.f32)));
	// stvx128 v55,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x82537EB8;
	sub_82202EC0(ctx, base);
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

__attribute__((alias("__imp__sub_82537ED0"))) PPC_WEAK_FUNC(sub_82537ED0);
PPC_FUNC_IMPL(__imp__sub_82537ED0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f13,12(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lvx128 v0,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r8,1136
	ctx.r8.s64 = 1136;
	// li r7,1152
	ctx.r7.s64 = 1152;
	// lfs f0,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f0.f64 = double(temp.f32);
	// addi r3,r11,1104
	ctx.r3.s64 = r11.s64 + 1104;
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v12,r11,r8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,48
	ctx.r6.s64 = 48;
	// vmaddfp v11,v12,v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r5,r11,32
	ctx.r5.s64 = r11.s64 + 32;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stvx128 v11,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r3,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v0
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x82537F3C;
	sub_82202EC0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82537F4C"))) PPC_WEAK_FUNC(sub_82537F4C);
PPC_FUNC_IMPL(__imp__sub_82537F4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82537F50"))) PPC_WEAK_FUNC(sub_82537F50);
PPC_FUNC_IMPL(__imp__sub_82537F50) {
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
	ctx.lr = 0x82537F58;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// lfs f0,15360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15360);
	f0.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// addi r5,r10,-26740
	ctx.r5.s64 = ctx.r10.s64 + -26740;
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r8,r9,24,0,7
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFF000000;
	// oris r31,r8,255
	r31.u64 = ctx.r8.u64 | 16711680;
	// ori r31,r31,65535
	r31.u64 = r31.u64 | 65535;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// bl 0x82501dd8
	ctx.lr = 0x82537FA0;
	sub_82501DD8(ctx, base);
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r7,-26784
	ctx.r5.s64 = ctx.r7.s64 + -26784;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82501dd8
	ctx.lr = 0x82537FB8;
	sub_82501DD8(ctx, base);
	// lbz r6,934(r29)
	ctx.r6.u64 = PPC_LOAD_U8(r29.u32 + 934);
	// lbz r5,932(r29)
	ctx.r5.u64 = PPC_LOAD_U8(r29.u32 + 932);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// xor r3,r6,r5
	ctx.r3.u64 = ctx.r6.u64 ^ ctx.r5.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8253800c
	if (!cr6.eq) goto loc_8253800C;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r5,r11,-26828
	ctx.r5.s64 = r11.s64 + -26828;
	// bl 0x82501dd8
	ctx.lr = 0x82537FE8;
	sub_82501DD8(ctx, base);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r10,-26868
	ctx.r5.s64 = ctx.r10.s64 + -26868;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82501dd8
	ctx.lr = 0x82538000;
	sub_82501DD8(ctx, base);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// addi r5,r9,-26896
	ctx.r5.s64 = ctx.r9.s64 + -26896;
	// b 0x82538038
	goto loc_82538038;
loc_8253800C:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r5,r11,-26940
	ctx.r5.s64 = r11.s64 + -26940;
	// bl 0x82501dd8
	ctx.lr = 0x82538018;
	sub_82501DD8(ctx, base);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r10,-26976
	ctx.r5.s64 = ctx.r10.s64 + -26976;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82501dd8
	ctx.lr = 0x82538030;
	sub_82501DD8(ctx, base);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// addi r5,r9,-27012
	ctx.r5.s64 = ctx.r9.s64 + -27012;
loc_82538038:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82501dd8
	ctx.lr = 0x82538048;
	sub_82501DD8(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r11,-27044
	ctx.r5.s64 = r11.s64 + -27044;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82501dd8
	ctx.lr = 0x82538060;
	sub_82501DD8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82538068"))) PPC_WEAK_FUNC(sub_82538068);
PPC_FUNC_IMPL(__imp__sub_82538068) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
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
	// addi r11,r3,1104
	r11.s64 = ctx.r3.s64 + 1104;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,16
	ctx.r8.s64 = 16;
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// li r9,32
	ctx.r9.s64 = 32;
	// li r6,48
	ctx.r6.s64 = 48;
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,1040
	ctx.r10.s64 = ctx.r3.s64 + 1040;
	// lvx128 v60,r4,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r5,2384
	ctx.r3.s64 = ctx.r5.s64 + 2384;
	// stvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r11,48
	ctx.r7.s64 = r11.s64 + 48;
	// lvx128 v59,r4,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// stvx128 v59,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r4,r6
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r5,2352
	ctx.r4.s64 = ctx.r5.s64 + 2352;
	// stvx128 v58,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r11,r9
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r11,r8
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r7
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v51,v57,v56
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v52,v53,v54
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vor128 v55,v56,v56
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vmrglw128 v49,v53,v54
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrglw128 v47,v57,v56
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v45,v52,v51
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmsum3fp128 v50,v54,v55
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vmrglw128 v44,v52,v51
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmsum3fp128 v48,v53,v55
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vmrghw128 v43,v49,v47
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmsum3fp128 v46,v57,v55
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v55.f32), 0xEF));
	// vand128 v42,v45,v63
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v42,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v41,v44,v63
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v41,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v40,v48,v50
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v39,v43,v63
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v39,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v38,v46,v40
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v37,v40,v38
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vsubfp128 v36,v61,v37
	simde_mm_store_ps(v36.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v37.f32)));
	// vand128 v35,v36,v63
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v34,v62,v35
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v35.u8)));
	// stvx128 v34,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253813C"))) PPC_WEAK_FUNC(sub_8253813C);
PPC_FUNC_IMPL(__imp__sub_8253813C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82538140"))) PPC_WEAK_FUNC(sub_82538140);
PPC_FUNC_IMPL(__imp__sub_82538140) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	// bl 0x823d91e8
	ctx.lr = 0x82538148;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823db9c8
	ctx.lr = 0x82538150;
	// li r12,-160
	r12.s64 = -160;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x8260b990
	ctx.lr = 0x82538170;
	sub_8260B990(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r25,r11,-27128
	r25.s64 = r11.s64 + -27128;
	// addi r28,r31,824
	r28.s64 = r31.s64 + 824;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f0,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// lfs f1,4(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// stfs f31,128(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f31,132(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// bl 0x822a48f0
	ctx.lr = 0x825381A4;
	sub_822A48F0(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bne cr6,0x825382cc
	if (!cr6.eq) goto loc_825382CC;
	// addi r3,r31,836
	ctx.r3.s64 = r31.s64 + 836;
	// lfs f1,8(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822a48f0
	ctx.lr = 0x825381B8;
	sub_822A48F0(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bne cr6,0x825382cc
	if (!cr6.eq) goto loc_825382CC;
	// lbz r11,850(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 850);
	// lbz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 848);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x825382cc
	if (!cr6.eq) goto loc_825382CC;
	// lbz r11,862(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 862);
	// lbz r10,860(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 860);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82538208
	if (cr6.eq) goto loc_82538208;
	// lbz r11,934(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 934);
	// lbz r10,932(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 932);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x825382cc
	if (cr6.eq) goto loc_825382CC;
loc_82538208:
	// lbz r11,874(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 874);
	// lbz r10,872(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 872);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x825382cc
	if (!cr6.eq) goto loc_825382CC;
	// lbz r11,886(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 886);
	// lbz r10,884(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 884);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x825382cc
	if (!cr6.eq) goto loc_825382CC;
	// lbz r11,934(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 934);
	// lbz r10,932(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 932);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x825382cc
	if (!cr6.eq) goto loc_825382CC;
	// lbz r11,946(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 946);
	// lbz r10,944(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 944);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x825382cc
	if (!cr6.eq) goto loc_825382CC;
	// lbz r11,958(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 958);
	// lbz r10,956(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 956);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x825382cc
	if (!cr6.eq) goto loc_825382CC;
	// lbz r11,970(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 970);
	// lbz r10,968(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 968);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x825382cc
	if (!cr6.eq) goto loc_825382CC;
	// lbz r11,898(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 898);
	// lbz r10,896(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 896);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x825382cc
	if (!cr6.eq) goto loc_825382CC;
	// lbz r11,910(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 910);
	// lbz r10,908(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 908);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// li r11,0
	r11.s64 = 0;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x825382d0
	if (cr6.eq) goto loc_825382D0;
loc_825382CC:
	// li r11,1
	r11.s64 = 1;
loc_825382D0:
	// lbz r10,934(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 934);
	// addi r27,r31,932
	r27.s64 = r31.s64 + 932;
	// lbz r9,932(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 932);
	// clrlwi r24,r11,24
	r24.u64 = r11.u32 & 0xFF;
	// xor r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82538338
	if (cr6.eq) goto loc_82538338;
	// lbz r11,850(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 850);
	// lbz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 848);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82538384
	if (!cr6.eq) goto loc_82538384;
	// lbz r11,874(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 874);
	// lbz r10,872(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 872);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82538384
	if (!cr6.eq) goto loc_82538384;
	// lbz r11,886(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 886);
	// lbz r10,884(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 884);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82538384
	if (!cr6.eq) goto loc_82538384;
loc_82538338:
	// lbz r11,946(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 946);
	// lbz r10,944(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 944);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82538384
	if (!cr6.eq) goto loc_82538384;
	// lbz r11,958(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 958);
	// lbz r10,956(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 956);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82538384
	if (!cr6.eq) goto loc_82538384;
	// lbz r11,970(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 970);
	// lbz r10,968(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 968);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// li r11,0
	r11.s64 = 0;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82538388
	if (cr6.eq) goto loc_82538388;
loc_82538384:
	// li r11,1
	r11.s64 = 1;
loc_82538388:
	// addi r29,r31,1104
	r29.s64 = r31.s64 + 1104;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
	// bl 0x821ba038
	ctx.lr = 0x8253839C;
	sub_821BA038(ctx, base);
	// lbz r11,982(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 982);
	// lbz r10,980(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 980);
	// addi r26,r31,1152
	r26.s64 = r31.s64 + 1152;
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// lvx128 v127,r0,r26
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x825383dc
	if (cr6.eq) goto loc_825383DC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f31,992(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 992, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825383D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82538b08
	goto loc_82538B08;
loc_825383DC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lfs f1,4(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822a48f0
	ctx.lr = 0x825383E8;
	sub_822A48F0(ctx, base);
	// fmuls f13,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 * f30.f64));
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lfs f1,8(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r31,836
	ctx.r3.s64 = r31.s64 + 836;
	// lfs f0,-26688(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -26688);
	f0.f64 = double(temp.f32);
	// fmuls f28,f13,f0
	f28.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x822a48f0
	ctx.lr = 0x82538404;
	sub_822A48F0(ctx, base);
	// fmuls f12,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64 * f30.f64));
	// lbz r10,2(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + 2);
	// lbz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// fmr f26,f31
	f26.f64 = f31.f64;
	// stfs f26,80(r1)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// xor r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// fmr f24,f31
	f24.f64 = f31.f64;
	// fmr f25,f31
	f25.f64 = f31.f64;
	// stfs f24,84(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// stfs f25,88(r1)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfs f0,23884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 23884);
	f0.f64 = double(temp.f32);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// fmuls f27,f12,f0
	f27.f64 = double(float(ctx.f12.f64 * f0.f64));
	// bne cr6,0x82538530
	if (!cr6.eq) goto loc_82538530;
	// lbz r11,970(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 970);
	// lbz r10,968(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 968);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82538530
	if (!cr6.eq) goto loc_82538530;
	// lbz r11,862(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 862);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lbz r9,860(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 860);
	// lis r8,-32248
	ctx.r8.s64 = -2113404928;
	// lbz r7,850(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 850);
	// lis r6,-32248
	ctx.r6.s64 = -2113404928;
	// lbz r5,848(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 848);
	// xor r4,r11,r9
	ctx.r4.u64 = r11.u64 ^ ctx.r9.u64;
	// lbz r11,896(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 896);
	// lbz r3,898(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 898);
	// xor r9,r7,r5
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r5.u64;
	// lbz r7,910(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 910);
	// lfs f0,1456(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 1456);
	f0.f64 = double(temp.f32);
	// lbz r5,908(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 908);
	// xor r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 ^ r11.u64;
	// subf r11,r9,r4
	r11.s64 = ctx.r4.s64 - ctx.r9.s64;
	// lbz r10,874(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 874);
	// xor r9,r7,r5
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r5.u64;
	// lbz r7,872(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 872);
	// extsw r5,r11
	ctx.r5.s64 = r11.s32;
	// lbz r4,886(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 886);
	// lbz r11,884(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 884);
	// lfs f13,-26692(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -26692);
	ctx.f13.f64 = double(temp.f32);
	// xor r8,r10,r7
	ctx.r8.u64 = ctx.r10.u64 ^ ctx.r7.u64;
	// lfs f12,-26696(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -26696);
	ctx.f12.f64 = double(temp.f32);
	// xor r7,r4,r11
	ctx.r7.u64 = ctx.r4.u64 ^ r11.u64;
	// std r5,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r5.u64);
	// subf r3,r3,r9
	ctx.r3.s64 = ctx.r9.s64 - ctx.r3.s64;
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// subf r6,r8,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r8.s64;
	// fcfid f6,f11
	ctx.f6.f64 = double(ctx.f11.s64);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// frsp f3,f6
	ctx.f3.f64 = double(float(ctx.f6.f64));
	// extsw r5,r6
	ctx.r5.s64 = ctx.r6.s32;
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f10,88(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r5,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r5.u64);
	// lfd f9,88(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f4,f7
	ctx.f4.f64 = double(float(ctx.f7.f64));
	// fmuls f11,f3,f30
	ctx.f11.f64 = double(float(ctx.f3.f64 * f30.f64));
	// frsp f5,f8
	ctx.f5.f64 = double(float(ctx.f8.f64));
	// fmuls f1,f4,f30
	ctx.f1.f64 = double(float(ctx.f4.f64 * f30.f64));
	// fmuls f26,f11,f0
	f26.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f26,80(r1)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f2,f5,f30
	ctx.f2.f64 = double(float(ctx.f5.f64 * f30.f64));
	// fmuls f25,f1,f13
	f25.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
	// stfs f25,88(r1)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmuls f24,f2,f12
	f24.f64 = double(float(ctx.f2.f64 * ctx.f12.f64));
	// stfs f24,84(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// b 0x82538600
	goto loc_82538600;
loc_82538530:
	// lbz r11,850(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 850);
	// lbz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 848);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82538560
	if (!cr6.eq) goto loc_82538560;
	// lbz r11,970(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 970);
	// lbz r10,968(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 968);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82538600
	if (cr6.eq) goto loc_82538600;
loc_82538560:
	// lfs f0,992(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 992);
	f0.f64 = double(temp.f32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// fneg f1,f0
	ctx.f1.u64 = f0.u64 ^ 0x8000000000000000;
	// li r28,1
	r28.s64 = 1;
	// bl 0x821bb348
	ctx.lr = 0x82538578;
	sub_821BB348(ctx, base);
	// lfs f12,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lfs f0,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f11,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f5,f12,f0
	ctx.f5.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lfs f10,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f6,f0,f13
	ctx.f6.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fmuls f4,f11,f12
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// lfs f8,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f3,f10,f12
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// lfs f9,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f1,f10,f8,f5
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmsubs f2,f9,f12,f6
	ctx.f2.f64 = double(float(ctx.f9.f64 * ctx.f12.f64 - ctx.f6.f64));
	// fmadds f12,f8,f9,f4
	ctx.f12.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 + ctx.f4.f64));
	// fmadds f6,f7,f9,f3
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f9.f64 + ctx.f3.f64));
	// fmadds f4,f9,f13,f1
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f1.f64));
	// fnmsubs f5,f11,f8,f2
	ctx.f5.f64 = double(float(-(ctx.f11.f64 * ctx.f8.f64 - ctx.f2.f64)));
	// fmadds f3,f7,f0,f12
	ctx.f3.f64 = double(float(ctx.f7.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f2,f11,f13,f6
	ctx.f2.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + ctx.f6.f64));
	// fnmsubs f12,f7,f11,f4
	ctx.f12.f64 = double(float(-(ctx.f7.f64 * ctx.f11.f64 - ctx.f4.f64)));
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fnmsubs f1,f10,f7,f5
	ctx.f1.f64 = double(float(-(ctx.f10.f64 * ctx.f7.f64 - ctx.f5.f64)));
	// stfs f1,124(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// fnmsubs f11,f10,f13,f3
	ctx.f11.f64 = double(float(-(ctx.f10.f64 * ctx.f13.f64 - ctx.f3.f64)));
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fnmsubs f10,f8,f0,f2
	ctx.f10.f64 = double(float(-(ctx.f8.f64 * f0.f64 - ctx.f2.f64)));
	// stfs f10,120(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// bl 0x821d1d30
	ctx.lr = 0x825385F4;
	sub_821D1D30(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822f18f0
	ctx.lr = 0x825385FC;
	sub_822F18F0(ctx, base);
	// stfs f31,992(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 992, temp.u32);
loc_82538600:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// fmr f8,f31
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = f31.f64;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// fmr f10,f31
	ctx.f10.f64 = f31.f64;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// fmr f7,f31
	ctx.f7.f64 = f31.f64;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// fmr f9,f31
	ctx.f9.f64 = f31.f64;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r11,21784(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 21784);
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lwz r10,21772(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 21772);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// extsw r4,r11
	ctx.r4.s64 = r11.s32;
	// lfs f13,2756(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 2756);
	ctx.f13.f64 = double(temp.f32);
	// extsw r3,r10
	ctx.r3.s64 = ctx.r10.s32;
	// lwz r11,21788(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 21788);
	// std r4,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r4.u64);
	// lfd f0,96(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// std r3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f4,f0
	ctx.f4.f64 = double(f0.s64);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// frsp f3,f4
	ctx.f3.f64 = double(float(ctx.f4.f64));
	// lfs f0,31308(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31308);
	f0.f64 = double(temp.f32);
	// lfs f12,2764(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 2764);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r11,r11,31,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// lfs f29,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f29.f64 = double(temp.f32);
	// lfs f6,-32032(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -32032);
	ctx.f6.f64 = double(temp.f32);
	// frsp f5,f11
	ctx.f5.f64 = double(float(ctx.f11.f64));
	// lfs f11,27640(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27640);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f12,f3,f12
	ctx.f12.f64 = double(float(ctx.f3.f64 * ctx.f12.f64));
	// fmuls f13,f5,f13
	ctx.f13.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x825386a0
	if (!cr6.lt) goto loc_825386A0;
	// fsubs f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fmuls f7,f13,f11
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// b 0x825386b4
	goto loc_825386B4;
loc_825386A0:
	// fcmpu cr6,f13,f6
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, ctx.f6.f64);
	// ble cr6,0x825386b4
	if (!cr6.gt) goto loc_825386B4;
	// fsubs f13,f13,f29
	ctx.f13.f64 = double(float(ctx.f13.f64 - f29.f64));
	// fadds f9,f13,f0
	ctx.f9.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fmuls f9,f9,f11
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
loc_825386B4:
	// fcmpu cr6,f12,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x825386c8
	if (!cr6.lt) goto loc_825386C8;
	// fsubs f0,f0,f12
	f0.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fmuls f8,f0,f11
	ctx.f8.f64 = double(float(f0.f64 * ctx.f11.f64));
	// b 0x825386dc
	goto loc_825386DC;
loc_825386C8:
	// fcmpu cr6,f12,f6
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, ctx.f6.f64);
	// ble cr6,0x825386dc
	if (!cr6.gt) goto loc_825386DC;
	// fsubs f13,f12,f29
	ctx.f13.f64 = double(float(ctx.f12.f64 - f29.f64));
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fmuls f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
loc_825386DC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82538708
	if (cr6.eq) goto loc_82538708;
	// fsubs f12,f7,f9
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f7.f64 - ctx.f9.f64));
	// lfs f0,-24(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -24);
	f0.f64 = double(temp.f32);
	// fsubs f11,f8,f10
	ctx.f11.f64 = double(float(ctx.f8.f64 - ctx.f10.f64));
	// lfs f13,-20(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -20);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f10,f12,f30
	ctx.f10.f64 = double(float(ctx.f12.f64 * f30.f64));
	// fmuls f9,f11,f30
	ctx.f9.f64 = double(float(ctx.f11.f64 * f30.f64));
	// fmuls f28,f10,f0
	f28.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fmuls f27,f9,f13
	f27.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
loc_82538708:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// li r30,1120
	r30.s64 = 1120;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82538884
	if (!cr6.eq) goto loc_82538884;
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32122
	r11.s64 = -2105147392;
	// vmsum3fp128 v59,v63,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lvx128 v62,r31,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v58,v62,v62
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// addi r10,r11,2528
	ctx.r10.s64 = r11.s64 + 2528;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// fmr f1,f27
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.f64 = f27.f64;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r7,r9,2240
	ctx.r7.s64 = ctx.r9.s64 + 2240;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r8,-31648
	ctx.r5.s64 = ctx.r8.s64 + -31648;
	// addi r4,r6,-31664
	ctx.r4.s64 = ctx.r6.s64 + -31664;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// vor128 v0,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// vor128 v13,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// lvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v57,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v59.f32))));
	// vor128 v11,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vrsqrtefp128 v56,v58
	simde_mm_store_ps(v56.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v58.f32))));
	// vor128 v10,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// vcmpeqfp128 v9,v57,v60
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v60.f32)));
	// vor128 v8,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// vcmpeqfp128 v7,v56,v60
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v60.f32)));
	// vor128 v6,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vsel v0,v8,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vsel v13,v6,v13,v7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vmulfp128 v5,v0,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v4,v61,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v3,v13,v13
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v2,v61,v13
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vnmsubfp v1,v11,v5,v12
	simde_mm_store_ps(ctx.v1.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp v31,v10,v3,v12
	simde_mm_store_ps(v31.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v30,v1,v4,v0
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v29,v31,v2,v13
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v31.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v55,v63,v30
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v30.f32)));
	// vmulfp128 v54,v62,v29
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v29.f32)));
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821bb348
	ctx.lr = 0x825387E0;
	sub_821BB348(ctx, base);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// fmr f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f28.f64;
	// bl 0x821bb348
	ctx.lr = 0x825387F0;
	sub_821BB348(ctx, base);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d58f0
	ctx.lr = 0x82538800;
	sub_821D58F0(ctx, base);
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// fmuls f6,f0,f13
	ctx.f6.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f12,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f12.f64 = double(temp.f32);
	// lfs f9,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f5,f12,f0
	ctx.f5.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lfs f11,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f10,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f4,f11,f12
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fmuls f3,f10,f12
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// lfs f8,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f7.f64 = double(temp.f32);
	// fmsubs f2,f9,f12,f6
	ctx.f2.f64 = double(float(ctx.f9.f64 * ctx.f12.f64 - ctx.f6.f64));
	// fmadds f1,f11,f8,f5
	ctx.f1.f64 = double(float(ctx.f11.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f12,f9,f7,f4
	ctx.f12.f64 = double(float(ctx.f9.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fmadds f6,f9,f8,f3
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f3.f64));
	// fnmsubs f5,f11,f7,f2
	ctx.f5.f64 = double(float(-(ctx.f11.f64 * ctx.f7.f64 - ctx.f2.f64)));
	// fmadds f4,f9,f13,f1
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f1.f64));
	// fmadds f3,f10,f13,f12
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f12.f64));
	// fmadds f2,f7,f0,f6
	ctx.f2.f64 = double(float(ctx.f7.f64 * f0.f64 + ctx.f6.f64));
	// fnmsubs f1,f10,f8,f5
	ctx.f1.f64 = double(float(-(ctx.f10.f64 * ctx.f8.f64 - ctx.f5.f64)));
	// fnmsubs f12,f10,f7,f4
	ctx.f12.f64 = double(float(-(ctx.f10.f64 * ctx.f7.f64 - ctx.f4.f64)));
	// stfs f1,124(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// fnmsubs f10,f8,f0,f3
	ctx.f10.f64 = double(float(-(ctx.f8.f64 * f0.f64 - ctx.f3.f64)));
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fnmsubs f9,f11,f13,f2
	ctx.f9.f64 = double(float(-(ctx.f11.f64 * ctx.f13.f64 - ctx.f2.f64)));
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f9,120(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// bl 0x821d1d30
	ctx.lr = 0x8253887C;
	sub_821D1D30(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822f18f0
	ctx.lr = 0x82538884;
	sub_822F18F0(ctx, base);
loc_82538884:
	// lbz r10,922(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 922);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lbz r8,920(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 920);
	// addi r11,r31,920
	r11.s64 = r31.s64 + 920;
	// xor r7,r10,r8
	ctx.r7.u64 = ctx.r10.u64 ^ ctx.r8.u64;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// lfs f13,15364(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 15364);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x825388f0
	if (cr6.eq) goto loc_825388F0;
	// lbz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// lfs f0,-16(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + -16);
	f0.f64 = double(temp.f32);
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// xor r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// clrlwi r6,r8,24
	ctx.r6.u64 = ctx.r8.u32 & 0xFF;
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * f0.f64));
	// fadds f7,f8,f29
	ctx.f7.f64 = double(float(ctx.f8.f64 + f29.f64));
	// fmuls f6,f7,f26
	ctx.f6.f64 = double(float(ctx.f7.f64 * f26.f64));
	// stfs f6,80(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f5,f7,f24
	ctx.f5.f64 = double(float(ctx.f7.f64 * f24.f64));
	// stfs f5,84(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmuls f4,f7,f25
	ctx.f4.f64 = double(float(ctx.f7.f64 * f25.f64));
	// stfs f4,88(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
loc_825388F0:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// vor128 v0,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// li r10,1136
	ctx.r10.s64 = 1136;
	// lvx128 v13,r0,r29
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// lvx128 v12,r31,r30
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// clrlwi r7,r28,24
	ctx.r7.u64 = r28.u32 & 0xFF;
	// lvlx128 v53,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v52,v53,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xFF));
	// lvx128 v51,r31,r10
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v50,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// vspltw128 v11,v50,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// lvlx128 v49,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v10,v49,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0xFF));
	// vmaddfp128 v0,v51,v52,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v52.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v9,v13,v11,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v8,v12,v10,v9
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// stvx128 v8,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x82538b04
	if (!cr6.eq) goto loc_82538B04;
	// lbz r11,2(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 2);
	// lbz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8253898c
	if (!cr6.eq) goto loc_8253898C;
	// lbz r11,946(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 946);
	// lbz r10,944(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 944);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8253898c
	if (!cr6.eq) goto loc_8253898C;
	// lbz r11,958(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 958);
	// lbz r10,956(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 956);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82538b04
	if (cr6.eq) goto loc_82538B04;
loc_8253898C:
	// lbz r10,886(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 886);
	// addi r11,r31,884
	r11.s64 = r31.s64 + 884;
	// lbz r9,884(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 884);
	// xor r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82538a20
	if (!cr6.eq) goto loc_82538A20;
	// lbz r10,874(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 874);
	// lbz r9,872(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 872);
	// xor r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82538a20
	if (!cr6.eq) goto loc_82538A20;
	// lbz r10,946(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 946);
	// addi r11,r31,944
	r11.s64 = r31.s64 + 944;
	// lbz r9,944(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 944);
	// xor r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x825389f4
	if (!cr6.eq) goto loc_825389F4;
	// lbz r10,958(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 958);
	// lbz r9,956(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 956);
	// xor r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82538b04
	if (cr6.eq) goto loc_82538B04;
loc_825389F4:
	// lbz r10,958(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 958);
	// lbz r9,956(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 956);
	// lbz r8,2(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// xor r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// xor r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 ^ ctx.r7.u64;
	// subf r4,r6,r5
	ctx.r4.s64 = ctx.r5.s64 - ctx.r6.s64;
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// std r3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// b 0x82538a48
	goto loc_82538A48;
loc_82538A20:
	// lbz r10,874(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 874);
	// lbz r9,872(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 872);
	// lbz r8,2(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// lbz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// xor r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// xor r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 ^ ctx.r7.u64;
	// subf r4,r6,r5
	ctx.r4.s64 = ctx.r5.s64 - ctx.r6.s64;
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// std r3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
loc_82538A48:
	// fcfid f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(f0.s64);
	// frsp f0,f12
	f0.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x82538b04
	if (cr6.eq) goto loc_82538B04;
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f0,0(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f12,992(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 992);
	ctx.f12.f64 = double(temp.f32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// fmuls f11,f13,f30
	ctx.f11.f64 = double(float(ctx.f13.f64 * f30.f64));
	// fmuls f1,f11,f0
	ctx.f1.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fadds f10,f12,f1
	ctx.f10.f64 = double(float(ctx.f12.f64 + ctx.f1.f64));
	// stfs f10,992(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 992, temp.u32);
	// bl 0x821bb348
	ctx.lr = 0x82538A80;
	sub_821BB348(ctx, base);
	// lfs f12,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lfs f0,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f11,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f5,f12,f0
	ctx.f5.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lfs f10,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f6,f0,f13
	ctx.f6.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fmuls f4,f11,f12
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// lfs f8,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f3,f10,f12
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// lfs f9,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f1,f10,f8,f5
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmsubs f2,f9,f12,f6
	ctx.f2.f64 = double(float(ctx.f9.f64 * ctx.f12.f64 - ctx.f6.f64));
	// fmadds f12,f9,f8,f4
	ctx.f12.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f4.f64));
	// fmadds f6,f9,f7,f3
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f7.f64 + ctx.f3.f64));
	// fmadds f4,f9,f13,f1
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f1.f64));
	// fnmsubs f5,f11,f8,f2
	ctx.f5.f64 = double(float(-(ctx.f11.f64 * ctx.f8.f64 - ctx.f2.f64)));
	// fmadds f3,f7,f0,f12
	ctx.f3.f64 = double(float(ctx.f7.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f2,f11,f13,f6
	ctx.f2.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + ctx.f6.f64));
	// fnmsubs f12,f11,f7,f4
	ctx.f12.f64 = double(float(-(ctx.f11.f64 * ctx.f7.f64 - ctx.f4.f64)));
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fnmsubs f1,f10,f7,f5
	ctx.f1.f64 = double(float(-(ctx.f10.f64 * ctx.f7.f64 - ctx.f5.f64)));
	// stfs f1,124(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// fnmsubs f11,f10,f13,f3
	ctx.f11.f64 = double(float(-(ctx.f10.f64 * ctx.f13.f64 - ctx.f3.f64)));
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fnmsubs f10,f8,f0,f2
	ctx.f10.f64 = double(float(-(ctx.f8.f64 * f0.f64 - ctx.f2.f64)));
	// stfs f10,120(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// bl 0x821d1d30
	ctx.lr = 0x82538AFC;
	sub_821D1D30(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822f18f0
	ctx.lr = 0x82538B04;
	sub_822F18F0(ctx, base);
loc_82538B04:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_82538B08:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// li r0,-160
	r0.s64 = -160;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba14
	ctx.lr = 0x82538B1C;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82538B20"))) PPC_WEAK_FUNC(sub_82538B20);
PPC_FUNC_IMPL(__imp__sub_82538B20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// addi r10,r3,112
	ctx.r10.s64 = ctx.r3.s64 + 112;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r7,48
	ctx.r7.s64 = 48;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,176
	ctx.r4.s64 = 176;
	// lvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r31,-32256
	r31.s64 = -2113929216;
	// stvx128 v62,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r3,192
	ctx.r8.s64 = ctx.r3.s64 + 192;
	// lvx128 v61,r11,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,0
	ctx.r9.s64 = 0;
	// stvx128 v61,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r9,1148(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1148, ctx.r9.u8);
	// lfs f0,3796(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r9,1149(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1149, ctx.r9.u8);
	// stfs f0,220(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 220, temp.u32);
	// stb r9,1150(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1150, ctx.r9.u8);
	// lfs f0,7444(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lvx128 v59,r3,r4
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,224(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 224, temp.u32);
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,200(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	f0.f64 = double(temp.f32);
	// lfs f13,168(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,192(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,160(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,196(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,164(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// fsubs f7,f0,f13
	ctx.f7.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fmuls f6,f8,f8
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fsubs f5,f12,f11
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// fmadds f4,f7,f7,f6
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fmadds f3,f5,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fsqrts f2,f3
	ctx.f2.f64 = double(float(sqrt(ctx.f3.f64)));
	// stfs f2,220(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 220, temp.u32);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82538BD0"))) PPC_WEAK_FUNC(sub_82538BD0);
PPC_FUNC_IMPL(__imp__sub_82538BD0) {
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
	// lbz r11,1152(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1152);
	// li r7,128
	ctx.r7.s64 = 128;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r3,160
	r11.s64 = ctx.r3.s64 + 160;
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82538c60
	if (cr6.eq) goto loc_82538C60;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,164(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,212(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// li r8,112
	ctx.r8.s64 = 112;
	// addi r6,r1,-16
	ctx.r6.s64 = ctx.r1.s64 + -16;
	// lfs f0,32688(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32688);
	f0.f64 = double(temp.f32);
	// fmadds f11,f13,f0,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f12.f64));
	// lvx128 v13,r3,r8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f10,f11,f1
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f1.f64));
	// fmuls f9,f10,f3
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f3.f64));
	// stfs f9,-16(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vmaddfp v11,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,164(r3)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,212(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f8,f0,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f7.f64));
	// lvx128 v9,r3,r7
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f5,f6,f2
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f2.f64));
	// vor v10,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
	// fmuls f4,f5,f3
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f3.f64));
	// fneg f3,f4
	ctx.f3.u64 = ctx.f4.u64 ^ 0x8000000000000000;
	// stfs f3,-16(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvlx128 v62,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v8,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmaddfp v7,v9,v8,v10
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// stvx128 v7,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
loc_82538C60:
	// lfs f0,212(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	f0.f64 = double(temp.f32);
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// fmuls f13,f0,f1
	ctx.f13.f64 = double(float(f0.f64 * ctx.f1.f64));
	// li r9,112
	ctx.r9.s64 = 112;
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// lvx128 v13,r3,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f12,f13,f3
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f3.f64));
	// stfs f12,-16(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvlx128 v61,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vmaddfp v11,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,212(r3)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f2
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f2.f64));
	// fmuls f9,f10,f3
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f3.f64));
	// vor v10,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
	// lvx128 v9,r3,r7
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fneg f8,f9
	ctx.f8.u64 = ctx.f9.u64 ^ 0x8000000000000000;
	// stfs f8,-16(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvlx128 v60,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v8,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vmaddfp v7,v9,v8,v10
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// stvx128 v7,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82538CC0"))) PPC_WEAK_FUNC(sub_82538CC0);
PPC_FUNC_IMPL(__imp__sub_82538CC0) {
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
	// lbz r11,1152(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1152);
	// fadds f13,f1,f2
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82538cd4
	if (cr6.eq) goto loc_82538CD4;
	// fneg f13,f13
	ctx.f13.u64 = ctx.f13.u64 ^ 0x8000000000000000;
loc_82538CD4:
	// lbz r11,1148(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1148);
	// li r10,144
	ctx.r10.s64 = 144;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// bne cr6,0x82538d3c
	if (!cr6.eq) goto loc_82538D3C;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82538d08
	if (!cr6.gt) goto loc_82538D08;
	// li r11,160
	r11.s64 = 160;
	// li r9,192
	ctx.r9.s64 = 192;
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82538db8
	goto loc_82538DB8;
loc_82538D08:
	// addi r11,r1,-16
	r11.s64 = ctx.r1.s64 + -16;
	// lfs f0,220(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	f0.f64 = double(temp.f32);
	// fneg f12,f0
	ctx.f12.u64 = f0.u64 ^ 0x8000000000000000;
	// li r9,160
	ctx.r9.s64 = 160;
	// stfs f12,-16(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// li r8,192
	ctx.r8.s64 = 192;
	// lvx128 v0,r3,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v62,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v12,r3,r9
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v0,v13,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v11,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82538db8
	goto loc_82538DB8;
loc_82538D3C:
	// lfs f11,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// bge cr6,0x82538db8
	if (!cr6.lt) goto loc_82538DB8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,220(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	f0.f64 = double(temp.f32);
	// lfs f12,11360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// blt cr6,0x82538da4
	if (cr6.lt) goto loc_82538DA4;
	// lfs f12,196(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f10,164(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f12,f10
	ctx.f9.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// lfs f8,200(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,168(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// lfs f5,192(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	ctx.f5.f64 = double(temp.f32);
	// lfs f12,-29232(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f1,f0,f12
	ctx.f1.f64 = double(float(f0.f64 * ctx.f12.f64));
	// lfs f4,160(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f2,f5,f4
	ctx.f2.f64 = double(float(ctx.f5.f64 - ctx.f4.f64));
	// fmuls f0,f9,f9
	f0.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f12,f6,f6,f0
	ctx.f12.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + f0.f64));
	// fmadds f10,f2,f2,f12
	ctx.f10.f64 = double(float(ctx.f2.f64 * ctx.f2.f64 + ctx.f12.f64));
	// fsqrts f9,f10
	ctx.f9.f64 = double(float(sqrt(ctx.f10.f64)));
	// fcmpu cr6,f9,f1
	cr6.compare(ctx.f9.f64, ctx.f1.f64);
	// bge cr6,0x82538db8
	if (!cr6.lt) goto loc_82538DB8;
loc_82538DA4:
	// li r11,160
	r11.s64 = 160;
	// stfs f11,220(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 220, temp.u32);
	// li r9,192
	ctx.r9.s64 = 192;
	// lvx128 v61,r3,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82538DB8:
	// lfs f0,208(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	f0.f64 = double(temp.f32);
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// fmuls f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 * ctx.f13.f64));
	// addi r11,r3,160
	r11.s64 = ctx.r3.s64 + 160;
	// lvx128 v0,r3,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f12,f13,f3
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f3.f64));
	// stfs f12,-16(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvlx128 v60,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vmaddfp v11,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82538DEC"))) PPC_WEAK_FUNC(sub_82538DEC);
PPC_FUNC_IMPL(__imp__sub_82538DEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82538DF0"))) PPC_WEAK_FUNC(sub_82538DF0);
PPC_FUNC_IMPL(__imp__sub_82538DF0) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x823d91cc
	ctx.lr = 0x82538DF8;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r9,r11,-31616
	ctx.r9.s64 = r11.s64 + -31616;
	// li r19,32
	r19.s64 = 32;
	// addi r8,r10,31476
	ctx.r8.s64 = ctx.r10.s64 + 31476;
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// li r30,0
	r30.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// addi r6,r7,-26376
	ctx.r6.s64 = ctx.r7.s64 + -26376;
	// stb r30,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r30.u8);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r19
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// addi r29,r31,240
	r29.s64 = r31.s64 + 240;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8260b730
	ctx.lr = 0x82538E40;
	sub_8260B730(ctx, base);
	// stb r30,1016(r31)
	PPC_STORE_U8(r31.u32 + 1016, r30.u8);
	// stb r30,1017(r31)
	PPC_STORE_U8(r31.u32 + 1017, r30.u8);
	// addi r27,r31,1016
	r27.s64 = r31.s64 + 1016;
	// stb r30,1018(r31)
	PPC_STORE_U8(r31.u32 + 1018, r30.u8);
	// addi r26,r31,1028
	r26.s64 = r31.s64 + 1028;
	// stb r30,1019(r31)
	PPC_STORE_U8(r31.u32 + 1019, r30.u8);
	// addi r6,r31,1040
	ctx.r6.s64 = r31.s64 + 1040;
	// stb r30,1020(r31)
	PPC_STORE_U8(r31.u32 + 1020, r30.u8);
	// addi r25,r31,1064
	r25.s64 = r31.s64 + 1064;
	// stw r30,1024(r31)
	PPC_STORE_U32(r31.u32 + 1024, r30.u32);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// stb r30,1028(r31)
	PPC_STORE_U8(r31.u32 + 1028, r30.u8);
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// stb r30,1029(r31)
	PPC_STORE_U8(r31.u32 + 1029, r30.u8);
	// li r8,16
	ctx.r8.s64 = 16;
	// stb r30,1030(r31)
	PPC_STORE_U8(r31.u32 + 1030, r30.u8);
	// stb r30,1031(r31)
	PPC_STORE_U8(r31.u32 + 1031, r30.u8);
	// stb r30,1032(r31)
	PPC_STORE_U8(r31.u32 + 1032, r30.u8);
	// stw r30,1036(r31)
	PPC_STORE_U32(r31.u32 + 1036, r30.u32);
	// stb r30,1040(r31)
	PPC_STORE_U8(r31.u32 + 1040, r30.u8);
	// stb r30,1041(r31)
	PPC_STORE_U8(r31.u32 + 1041, r30.u8);
	// stb r30,1042(r31)
	PPC_STORE_U8(r31.u32 + 1042, r30.u8);
	// stb r30,1043(r31)
	PPC_STORE_U8(r31.u32 + 1043, r30.u8);
	// stb r30,1044(r31)
	PPC_STORE_U8(r31.u32 + 1044, r30.u8);
	// stw r30,1048(r31)
	PPC_STORE_U32(r31.u32 + 1048, r30.u32);
	// stb r30,1052(r31)
	PPC_STORE_U8(r31.u32 + 1052, r30.u8);
	// stb r30,1053(r31)
	PPC_STORE_U8(r31.u32 + 1053, r30.u8);
	// stb r30,1054(r31)
	PPC_STORE_U8(r31.u32 + 1054, r30.u8);
	// stb r30,1055(r31)
	PPC_STORE_U8(r31.u32 + 1055, r30.u8);
	// stb r30,1056(r31)
	PPC_STORE_U8(r31.u32 + 1056, r30.u8);
	// stw r30,1060(r31)
	PPC_STORE_U32(r31.u32 + 1060, r30.u32);
	// stb r30,1064(r31)
	PPC_STORE_U8(r31.u32 + 1064, r30.u8);
	// stb r30,1065(r31)
	PPC_STORE_U8(r31.u32 + 1065, r30.u8);
	// stb r30,1066(r31)
	PPC_STORE_U8(r31.u32 + 1066, r30.u8);
	// stb r30,1067(r31)
	PPC_STORE_U8(r31.u32 + 1067, r30.u8);
	// stb r30,1068(r31)
	PPC_STORE_U8(r31.u32 + 1068, r30.u8);
	// stw r30,1072(r31)
	PPC_STORE_U32(r31.u32 + 1072, r30.u32);
	// stb r30,1076(r31)
	PPC_STORE_U8(r31.u32 + 1076, r30.u8);
	// stb r30,1077(r31)
	PPC_STORE_U8(r31.u32 + 1077, r30.u8);
	// stb r30,1078(r31)
	PPC_STORE_U8(r31.u32 + 1078, r30.u8);
	// stb r30,1079(r31)
	PPC_STORE_U8(r31.u32 + 1079, r30.u8);
	// stb r30,1080(r31)
	PPC_STORE_U8(r31.u32 + 1080, r30.u8);
	// stw r30,1084(r31)
	PPC_STORE_U32(r31.u32 + 1084, r30.u32);
	// stb r30,1088(r31)
	PPC_STORE_U8(r31.u32 + 1088, r30.u8);
	// stb r30,1089(r31)
	PPC_STORE_U8(r31.u32 + 1089, r30.u8);
	// stb r30,1090(r31)
	PPC_STORE_U8(r31.u32 + 1090, r30.u8);
	// stb r30,1091(r31)
	PPC_STORE_U8(r31.u32 + 1091, r30.u8);
	// stb r30,1092(r31)
	PPC_STORE_U8(r31.u32 + 1092, r30.u8);
	// stw r30,1096(r31)
	PPC_STORE_U32(r31.u32 + 1096, r30.u32);
	// stb r30,1100(r31)
	PPC_STORE_U8(r31.u32 + 1100, r30.u8);
	// stb r30,1101(r31)
	PPC_STORE_U8(r31.u32 + 1101, r30.u8);
	// stb r30,1102(r31)
	PPC_STORE_U8(r31.u32 + 1102, r30.u8);
	// stb r30,1103(r31)
	PPC_STORE_U8(r31.u32 + 1103, r30.u8);
	// stb r30,1104(r31)
	PPC_STORE_U8(r31.u32 + 1104, r30.u8);
	// stw r30,1108(r31)
	PPC_STORE_U32(r31.u32 + 1108, r30.u32);
	// stb r30,1112(r31)
	PPC_STORE_U8(r31.u32 + 1112, r30.u8);
	// stb r30,1113(r31)
	PPC_STORE_U8(r31.u32 + 1113, r30.u8);
	// stb r30,1114(r31)
	PPC_STORE_U8(r31.u32 + 1114, r30.u8);
	// stb r30,1115(r31)
	PPC_STORE_U8(r31.u32 + 1115, r30.u8);
	// stb r30,1116(r31)
	PPC_STORE_U8(r31.u32 + 1116, r30.u8);
	// stw r30,1120(r31)
	PPC_STORE_U32(r31.u32 + 1120, r30.u32);
	// stb r30,1124(r31)
	PPC_STORE_U8(r31.u32 + 1124, r30.u8);
	// stb r30,1125(r31)
	PPC_STORE_U8(r31.u32 + 1125, r30.u8);
	// stb r30,1126(r31)
	PPC_STORE_U8(r31.u32 + 1126, r30.u8);
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
	// li r9,48
	ctx.r9.s64 = 48;
	// stb r30,1127(r31)
	PPC_STORE_U8(r31.u32 + 1127, r30.u8);
	// addi r10,r31,112
	ctx.r10.s64 = r31.s64 + 112;
	// stb r30,1128(r31)
	PPC_STORE_U8(r31.u32 + 1128, r30.u8);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stw r30,1132(r31)
	PPC_STORE_U32(r31.u32 + 1132, r30.u32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stb r30,1136(r31)
	PPC_STORE_U8(r31.u32 + 1136, r30.u8);
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stb r30,1137(r31)
	PPC_STORE_U8(r31.u32 + 1137, r30.u8);
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stb r30,1138(r31)
	PPC_STORE_U8(r31.u32 + 1138, r30.u8);
	// vpermwi128 v58,v62,234
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stb r30,1139(r31)
	PPC_STORE_U8(r31.u32 + 1139, r30.u8);
	// vpermwi128 v57,v62,186
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stb r30,1140(r31)
	PPC_STORE_U8(r31.u32 + 1140, r30.u8);
	// vpermwi128 v56,v62,174
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stw r30,1144(r31)
	PPC_STORE_U32(r31.u32 + 1144, r30.u32);
	// lis r22,-32256
	r22.s64 = -2113929216;
	// lfs f0,12428(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12428);
	f0.f64 = double(temp.f32);
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r21,-32248
	r21.s64 = -2113404928;
	// stvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r18,192
	r18.s64 = 192;
	// stvx128 v59,r11,r19
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r17,176
	r17.s64 = 176;
	// stvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,-1
	ctx.r7.s64 = -1;
	// stvx128 v57,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,128
	ctx.r5.s64 = 128;
	// stvx128 v56,r10,r19
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r24,r31,1076
	r24.s64 = r31.s64 + 1076;
	// stvx128 v63,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r30,236(r31)
	PPC_STORE_U32(r31.u32 + 236, r30.u32);
	// lfs f13,27640(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// stw r30,232(r31)
	PPC_STORE_U32(r31.u32 + 232, r30.u32);
	// lfs f12,7444(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// li r4,6
	ctx.r4.s64 = 6;
	// lfs f11,-26384(r21)
	temp.u32 = PPC_LOAD_U32(r21.u32 + -26384);
	ctx.f11.f64 = double(temp.f32);
	// addi r23,r31,1088
	r23.s64 = r31.s64 + 1088;
	// stfs f0,208(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// addi r28,r31,1100
	r28.s64 = r31.s64 + 1100;
	// stfs f13,212(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 212, temp.u32);
	// addi r22,r31,1112
	r22.s64 = r31.s64 + 1112;
	// stfs f12,216(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 216, temp.u32);
	// addi r21,r31,1124
	r21.s64 = r31.s64 + 1124;
	// stfs f11,228(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 228, temp.u32);
	// addi r20,r31,1136
	r20.s64 = r31.s64 + 1136;
	// stvx128 v63,r31,r18
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r18.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r17
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r17.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8260b740
	ctx.lr = 0x8253901C;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8260b740
	ctx.lr = 0x82539034;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8260b740
	ctx.lr = 0x8253904C;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// li r5,512
	ctx.r5.s64 = 512;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8260b740
	ctx.lr = 0x82539064;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r5,256
	ctx.r5.s64 = 256;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x8260b740
	ctx.lr = 0x8253907C;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// li r6,54
	ctx.r6.s64 = 54;
	// li r5,42
	ctx.r5.s64 = 42;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b790
	ctx.lr = 0x82539094;
	sub_8260B790(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// li r6,157
	ctx.r6.s64 = 157;
	// li r5,29
	ctx.r5.s64 = 29;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b790
	ctx.lr = 0x825390AC;
	sub_8260B790(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,57
	ctx.r5.s64 = 57;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b740
	ctx.lr = 0x825390C4;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// li r6,184
	ctx.r6.s64 = 184;
	// li r5,56
	ctx.r5.s64 = 56;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b790
	ctx.lr = 0x825390DC;
	sub_8260B790(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x8260b740
	ctx.lr = 0x825390F4;
	sub_8260B740(ctx, base);
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8260b740
	ctx.lr = 0x8253910C;
	sub_8260B740(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r30,1152(r31)
	PPC_STORE_U8(r31.u32 + 1152, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,1151(r31)
	PPC_STORE_U8(r31.u32 + 1151, r11.u8);
	// bl 0x82538b20
	ctx.lr = 0x82539120;
	sub_82538B20(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_82539128"))) PPC_WEAK_FUNC(sub_82539128);
PPC_FUNC_IMPL(__imp__sub_82539128) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r3,r11,-26324
	ctx.r3.s64 = r11.s64 + -26324;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82539134"))) PPC_WEAK_FUNC(sub_82539134);
PPC_FUNC_IMPL(__imp__sub_82539134) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82539138"))) PPC_WEAK_FUNC(sub_82539138);
PPC_FUNC_IMPL(__imp__sub_82539138) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// addi r11,r3,112
	r11.s64 = ctx.r3.s64 + 112;
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
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253916C"))) PPC_WEAK_FUNC(sub_8253916C);
PPC_FUNC_IMPL(__imp__sub_8253916C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82539170"))) PPC_WEAK_FUNC(sub_82539170);
PPC_FUNC_IMPL(__imp__sub_82539170) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// li r8,32
	ctx.r8.s64 = 32;
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
	// li r11,48
	r11.s64 = 48;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// li r7,96
	ctx.r7.s64 = 96;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// addi r5,r31,32
	ctx.r5.s64 = r31.s64 + 32;
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v61,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r3,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r30
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v55,v57,v56
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v56.f32)));
	// stvx128 v55,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x825391F0;
	sub_82202EC0(ctx, base);
	// li r5,176
	ctx.r5.s64 = 176;
	// addi r11,r31,192
	r11.s64 = r31.s64 + 192;
	// lvx128 v54,r0,r30
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v54,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r30
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,16(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lfs f0,200(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 200);
	f0.f64 = double(temp.f32);
	// lfs f13,168(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,192(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 192);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,160(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 160);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,196(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 196);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,164(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// fsubs f7,f0,f13
	ctx.f7.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fmuls f6,f8,f8
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fsubs f5,f12,f11
	ctx.f5.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// fmadds f4,f7,f7,f6
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fmadds f3,f5,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fsqrts f2,f3
	ctx.f2.f64 = double(float(sqrt(ctx.f3.f64)));
	// stfs f2,220(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 220, temp.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82539254;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8253926C"))) PPC_WEAK_FUNC(sub_8253926C);
PPC_FUNC_IMPL(__imp__sub_8253926C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82539270"))) PPC_WEAK_FUNC(sub_82539270);
PPC_FUNC_IMPL(__imp__sub_82539270) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// addi r11,r3,160
	r11.s64 = ctx.r3.s64 + 160;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,144
	ctx.r9.s64 = 144;
	// vor128 v0,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// addi r10,r3,192
	ctx.r10.s64 = ctx.r3.s64 + 192;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r3,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3732(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3732);
	f0.f64 = double(temp.f32);
	// lfs f13,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,-16(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvlx128 v62,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmaddfp v11,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,200(r3)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,168(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,192(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,160(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,196(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,164(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fsubs f4,f11,f10
	ctx.f4.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// fmuls f3,f5,f5
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f5.f64));
	// fsubs f2,f9,f8
	ctx.f2.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// fmadds f1,f4,f4,f3
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f3.f64));
	// fmadds f0,f2,f2,f1
	f0.f64 = double(float(ctx.f2.f64 * ctx.f2.f64 + ctx.f1.f64));
	// fsqrts f13,f0
	ctx.f13.f64 = double(float(sqrt(f0.f64)));
	// stfs f13,220(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 220, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825392F8"))) PPC_WEAK_FUNC(sub_825392F8);
PPC_FUNC_IMPL(__imp__sub_825392F8) {
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
	ctx.lr = 0x82539300;
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lbz r11,1151(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 1151);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82539434
	if (cr6.eq) goto loc_82539434;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lbz r10,21662(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 21662);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82539344
	if (cr6.eq) goto loc_82539344;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-26244
	r30.s64 = r11.s64 + -26244;
	// b 0x8253934c
	goto loc_8253934C;
loc_82539344:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r30,r11,-26276
	r30.s64 = r11.s64 + -26276;
loc_8253934C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,255
	ctx.r9.s64 = 16711680;
	// ori r31,r9,65535
	r31.u64 = ctx.r9.u64 | 65535;
	// lbz r8,-17683(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + -17683);
	// lfs f31,15360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15360);
	f31.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x825393c8
	if (cr6.eq) goto loc_825393C8;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x825393c8
	if (cr6.eq) goto loc_825393C8;
	// lbz r11,1114(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 1114);
	// lbz r10,1112(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + 1112);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x825393c8
	if (!cr6.eq) goto loc_825393C8;
	// fmuls f0,f30,f31
	f0.f64 = double(float(f30.f64 * f31.f64));
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r11,-26308
	ctx.r5.s64 = r11.s64 + -26308;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r9,r10,24,0,7
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF000000;
	// or r6,r9,r31
	ctx.r6.u64 = ctx.r9.u64 | r31.u64;
	// bl 0x82501dd8
	ctx.lr = 0x825393C4;
	sub_82501DD8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_825393C8:
	// lfs f0,224(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 224);
	f0.f64 = double(temp.f32);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// li r4,24
	ctx.r4.s64 = 24;
	// addi r5,r11,-26312
	ctx.r5.s64 = r11.s64 + -26312;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82137a08
	ctx.lr = 0x825393EC;
	sub_82137A08(ctx, base);
	// fmuls f12,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f30.f64 * f31.f64));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r9,r10,24,0,7
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF000000;
	// or r31,r9,r31
	r31.u64 = ctx.r9.u64 | r31.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// bl 0x82501dd8
	ctx.lr = 0x82539418;
	sub_82501DD8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82539434
	if (cr6.eq) goto loc_82539434;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82501dd8
	ctx.lr = 0x82539434;
	sub_82501DD8(ctx, base);
loc_82539434:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82539444"))) PPC_WEAK_FUNC(sub_82539444);
PPC_FUNC_IMPL(__imp__sub_82539444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82539448"))) PPC_WEAK_FUNC(sub_82539448);
PPC_FUNC_IMPL(__imp__sub_82539448) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82539450;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f3
	f31.f64 = ctx.f3.f64;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// addi r29,r31,160
	r29.s64 = r31.s64 + 160;
	// addi r28,r31,144
	r28.s64 = r31.s64 + 144;
	// addi r30,r31,112
	r30.s64 = r31.s64 + 112;
	// lfs f0,220(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 220);
	f0.f64 = double(temp.f32);
	// lbz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,216(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 216);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmuls f13,f0,f1
	ctx.f13.f64 = double(float(f0.f64 * ctx.f1.f64));
	// lvlx128 v63,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lis r11,-32130
	r11.s64 = -2105671680;
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v127,r0,r29
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 * f31.f64));
	// addi r11,r11,-31280
	r11.s64 = r11.s64 + -31280;
	// lvx128 v61,r0,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// vmaddfp128 v127,v61,v62,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)), simde_mm_load_ps(v127.f32)));
	// addi r4,r11,32
	ctx.r4.s64 = r11.s64 + 32;
	// fneg f1,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// bne cr6,0x825394d4
	if (!cr6.eq) goto loc_825394D4;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
loc_825394D4:
	// bl 0x82350940
	ctx.lr = 0x825394D8;
	sub_82350940(ctx, base);
	// lfs f11,216(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 216);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f30
	ctx.f10.f64 = double(float(ctx.f11.f64 * f30.f64));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmuls f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 * f31.f64));
	// fneg f1,f9
	ctx.f1.u64 = ctx.f9.u64 ^ 0x8000000000000000;
	// bl 0x82227de0
	ctx.lr = 0x825394F0;
	sub_82227DE0(ctx, base);
	// addi r11,r1,84
	r11.s64 = ctx.r1.s64 + 84;
	// vor128 v13,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// lvx128 v0,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v60,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vmaddfp v11,v0,v12,v13
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v11,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82539528"))) PPC_WEAK_FUNC(sub_82539528);
PPC_FUNC_IMPL(__imp__sub_82539528) {
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
	ctx.lr = 0x82539530;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// fmr f0,f3
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f3.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f3,f4
	ctx.f3.f64 = ctx.f4.f64;
	// lbz r10,-17683(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -17683);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82539580
	if (cr6.eq) goto loc_82539580;
	// lbz r11,1114(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1114);
	// lbz r10,1112(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1112);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r3,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r3.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r3,31
	r11.u64 = ctx.r3.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82539580
	if (!cr6.eq) goto loc_82539580;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82539580:
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// li r28,0
	r28.s64 = 0;
	// li r29,0
	r29.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825395e4
	if (!cr6.eq) goto loc_825395E4;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825395b4
	if (cr6.eq) goto loc_825395B4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82538bd0
	ctx.lr = 0x825395AC;
	sub_82538BD0(ctx, base);
	// li r29,1
	r29.s64 = 1;
	// b 0x825395f0
	goto loc_825395F0;
loc_825395B4:
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825395d0
	if (cr6.eq) goto loc_825395D0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82539448
	ctx.lr = 0x825395C8;
	sub_82539448(ctx, base);
	// li r28,1
	r28.s64 = 1;
	// b 0x825395f0
	goto loc_825395F0;
loc_825395D0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f2,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f2.f64 = double(temp.f32);
	// fcmpu cr6,f0,f2
	cr6.compare(f0.f64, ctx.f2.f64);
	// beq cr6,0x825395f0
	if (cr6.eq) goto loc_825395F0;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
loc_825395E4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82538cc0
	ctx.lr = 0x825395EC;
	sub_82538CC0(ctx, base);
	// li r30,1
	r30.s64 = 1;
loc_825395F0:
	// lbz r11,1148(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82539640
	if (cr6.eq) goto loc_82539640;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82539640
	if (!cr6.eq) goto loc_82539640;
	// lfs f0,196(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 196);
	f0.f64 = double(temp.f32);
	// lfs f13,164(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,200(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 200);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,168(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 168);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,192(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 192);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,160(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 160);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// fmuls f5,f12,f12
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f2,f3
	ctx.f2.f64 = double(float(sqrt(ctx.f3.f64)));
	// stfs f2,220(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 220, temp.u32);
loc_82539640:
	// lbz r11,1088(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1088);
	// lbz r10,1090(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1090);
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82539688
	if (cr6.eq) goto loc_82539688;
	// lbz r10,1091(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1091);
	// xor r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 ^ r11.u64;
	// li r11,1
	r11.s64 = 1;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8253968c
	if (cr6.eq) goto loc_8253968C;
loc_82539688:
	// li r11,0
	r11.s64 = 0;
loc_8253968C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x825396c8
	if (cr6.eq) goto loc_825396C8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,224(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 224);
	f0.f64 = double(temp.f32);
	// lfs f13,15000(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15000);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x825396bc
	if (!cr6.lt) goto loc_825396BC;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// b 0x825396c4
	goto loc_825396C4;
loc_825396BC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
loc_825396C4:
	// stfs f0,224(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 224, temp.u32);
loc_825396C8:
	// lbz r11,1102(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1102);
	// lbz r10,1100(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1100);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82539700
	if (cr6.eq) goto loc_82539700;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82539700;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82539700:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// stb r30,1148(r31)
	PPC_STORE_U8(r31.u32 + 1148, r30.u8);
	// stb r29,1149(r31)
	PPC_STORE_U8(r31.u32 + 1149, r29.u8);
	// stb r28,1150(r31)
	PPC_STORE_U8(r31.u32 + 1150, r28.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82539734
	if (!cr6.eq) goto loc_82539734;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82539734
	if (!cr6.eq) goto loc_82539734;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x82539738
	if (cr6.eq) goto loc_82539738;
loc_82539734:
	// li r11,1
	r11.s64 = 1;
loc_82539738:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82539744"))) PPC_WEAK_FUNC(sub_82539744);
PPC_FUNC_IMPL(__imp__sub_82539744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82539748"))) PPC_WEAK_FUNC(sub_82539748);
PPC_FUNC_IMPL(__imp__sub_82539748) {
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
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lbz r11,1124(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1124);
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// lbz r5,1126(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1126);
	// lwz r8,236(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 236);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// xor r5,r5,r11
	ctx.r5.u64 = ctx.r5.u64 ^ r11.u64;
	// lwz r6,232(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 232);
	// fmr f4,f1
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = ctx.f1.f64;
	// lwz r9,21784(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 21784);
	// clrlwi r5,r5,24
	ctx.r5.u64 = ctx.r5.u32 & 0xFF;
	// lwz r11,21772(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 21772);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// lfs f0,7444(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 7444);
	f0.f64 = double(temp.f32);
	// subf r8,r6,r11
	ctx.r8.s64 = r11.s64 - ctx.r6.s64;
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f13
	ctx.f10.f64 = double(ctx.f13.s64);
	// subfic r4,r5,127
	xer.ca = ctx.r5.u32 <= 127;
	ctx.r4.s64 = 127 - ctx.r5.s64;
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// subfe r9,r4,r4
	temp.u8 = (~ctx.r4.u32 + ctx.r4.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r4.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r4.u64 + ctx.r4.u64 + xer.ca;
	xer.ca = temp.u8;
	// frsp f12,f10
	ctx.f12.f64 = double(float(ctx.f10.f64));
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// frsp f13,f11
	ctx.f13.f64 = double(float(ctx.f11.f64));
	// beq cr6,0x825397d4
	if (cr6.eq) goto loc_825397D4;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,31308(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31308);
	f0.f64 = double(temp.f32);
loc_825397D4:
	// lbz r9,1138(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1138);
	// lbz r8,1136(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1136);
	// xor r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// subfic r5,r6,127
	xer.ca = ctx.r6.u32 <= 127;
	ctx.r5.s64 = 127 - ctx.r6.s64;
	// subfe r4,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + xer.ca < xer.ca);
	ctx.r4.u64 = ~ctx.r5.u64 + ctx.r5.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r9,r4,31
	ctx.r9.u64 = ctx.r4.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82539804
	if (cr6.eq) goto loc_82539804;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f11,27640(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27640);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f0,f0,f11
	f0.f64 = double(float(f0.f64 * ctx.f11.f64));
loc_82539804:
	// stw r11,232(r3)
	PPC_STORE_U32(ctx.r3.u32 + 232, r11.u32);
	// fmuls f11,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lwz r11,21784(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 21784);
	// fmuls f10,f0,f12
	ctx.f10.f64 = double(float(f0.f64 * ctx.f12.f64));
	// stw r11,236(r3)
	PPC_STORE_U32(ctx.r3.u32 + 236, r11.u32);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,21788(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 21788);
	// rlwinm r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// lfs f13,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r4,r11,30,31,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1;
	// fmuls f12,f11,f13
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// fmuls f2,f10,f13
	ctx.f2.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// bne cr6,0x82539860
	if (!cr6.eq) goto loc_82539860;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82539858
	if (cr6.eq) goto loc_82539858;
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82539860
	if (!cr6.eq) goto loc_82539860;
loc_82539858:
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82539864
	goto loc_82539864;
loc_82539860:
	// li r10,1
	ctx.r10.s64 = 1;
loc_82539864:
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// clrlwi r9,r4,24
	ctx.r9.u64 = ctx.r4.u32 & 0xFF;
	// rlwinm r8,r10,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// clrlwi r6,r11,31
	ctx.r6.u64 = r11.u32 & 0x1;
	// xori r5,r8,1
	ctx.r5.u64 = ctx.r8.u64 ^ 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8253988c
	if (!cr6.eq) goto loc_8253988C;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82539894
	if (cr6.eq) goto loc_82539894;
loc_8253988C:
	// fneg f12,f12
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// fneg f2,f2
	ctx.f2.u64 = ctx.f2.u64 ^ 0x8000000000000000;
loc_82539894:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// fmr f1,f12
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f12.f64;
	// lfs f13,228(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 228);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,21800(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 21800);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// fmuls f3,f9,f0
	ctx.f3.f64 = double(float(ctx.f9.f64 * f0.f64));
	// bl 0x82539528
	ctx.lr = 0x825398C4;
	sub_82539528(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_825398D4"))) PPC_WEAK_FUNC(sub_825398D4);
PPC_FUNC_IMPL(__imp__sub_825398D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_825398D8"))) PPC_WEAK_FUNC(sub_825398D8);
PPC_FUNC_IMPL(__imp__sub_825398D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,1064
	ctx.r3.s64 = r31.s64 + 1064;
	// lfs f31,-6172(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6172);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x822a48f0
	ctx.lr = 0x82539910;
	sub_822A48F0(ctx, base);
	// addi r3,r31,1076
	ctx.r3.s64 = r31.s64 + 1076;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x822a48f0
	ctx.lr = 0x82539920;
	sub_822A48F0(ctx, base);
	// lbz r10,1042(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1042);
	// lbz r9,1040(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1040);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lbz r7,1030(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 1030);
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// xor r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// lbz r5,1028(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 1028);
	// lbz r4,1018(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1018);
	// fmr f4,f30
	ctx.f4.f64 = f30.f64;
	// clrlwi r3,r6,24
	ctx.r3.u64 = ctx.r6.u32 & 0xFF;
	// lbz r11,1016(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1016);
	// xor r10,r7,r5
	ctx.r10.u64 = ctx.r7.u64 ^ ctx.r5.u64;
	// lfs f3,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f3.f64 = double(temp.f32);
	// subfic r9,r3,127
	xer.ca = ctx.r3.u32 <= 127;
	ctx.r9.s64 = 127 - ctx.r3.s64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// xor r7,r4,r11
	ctx.r7.u64 = ctx.r4.u64 ^ r11.u64;
	// subfe r6,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// subfic r5,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r5.s64 = 127 - ctx.r8.s64;
	// clrlwi r4,r7,24
	ctx.r4.u64 = ctx.r7.u32 & 0xFF;
	// subfe r3,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + xer.ca < xer.ca);
	ctx.r3.u64 = ~ctx.r5.u64 + ctx.r5.u64 + xer.ca;
	xer.ca = temp.u8;
	// subfic r11,r4,127
	xer.ca = ctx.r4.u32 <= 127;
	r11.s64 = 127 - ctx.r4.s64;
	// clrlwi r5,r3,31
	ctx.r5.u64 = ctx.r3.u32 & 0x1;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r6,r6,31
	ctx.r6.u64 = ctx.r6.u32 & 0x1;
	// clrlwi r4,r10,31
	ctx.r4.u64 = ctx.r10.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82539528
	ctx.lr = 0x82539990;
	sub_82539528(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_825399B0"))) PPC_WEAK_FUNC(sub_825399B0);
PPC_FUNC_IMPL(__imp__sub_825399B0) {
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
	// lbz r11,1151(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1151);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x825399dc
	if (!cr6.eq) goto loc_825399DC;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82539a1c
	goto loc_82539A1C;
loc_825399DC:
	// lfs f0,224(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 224);
	f0.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,240
	ctx.r3.s64 = r31.s64 + 240;
	// fmuls f31,f0,f1
	f31.f64 = double(float(f0.f64 * ctx.f1.f64));
	// bl 0x8260b990
	ctx.lr = 0x825399F0;
	sub_8260B990(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82539748
	ctx.lr = 0x825399FC;
	sub_82539748(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82539a10
	if (cr6.eq) goto loc_82539A10;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82539a1c
	goto loc_82539A1C;
loc_82539A10:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x825398d8
	ctx.lr = 0x82539A1C;
	sub_825398D8(ctx, base);
loc_82539A1C:
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

__attribute__((alias("__imp__sub_82539A34"))) PPC_WEAK_FUNC(sub_82539A34);
PPC_FUNC_IMPL(__imp__sub_82539A34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82539A38"))) PPC_WEAK_FUNC(sub_82539A38);
PPC_FUNC_IMPL(__imp__sub_82539A38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	PPCVRegister v127{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82539A40;
	// li r12,-64
	r12.s64 = -64;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// li r28,16
	r28.s64 = 16;
	// vupkd3d128 v127,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v127 = vTemp;
	// li r29,32
	r29.s64 = 32;
	// li r30,48
	r30.s64 = 48;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r10,192
	ctx.r10.s64 = 192;
	// stfs f0,208(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// li r9,176
	ctx.r9.s64 = 176;
	// vpermwi128 v62,v127,234
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x15));
	// stfs f0,212(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 212, temp.u32);
	// vpermwi128 v61,v127,186
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x45));
	// li r8,96
	ctx.r8.s64 = 96;
	// vpermwi128 v60,v127,174
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x51));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r5,r31,32
	ctx.r5.s64 = r31.s64 + 32;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r3,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r3,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r31,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r31,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r3,r30
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v56,v57,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_sub_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v59.f32)));
	// stvx128 v56,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x82539AC8;
	sub_82202EC0(ctx, base);
	// vpermwi128 v55,v127,234
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x15));
	// vpermwi128 v54,v127,186
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x45));
	// addi r11,r31,112
	r11.s64 = r31.s64 + 112;
	// vpermwi128 v53,v127,174
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x51));
	// vpermwi128 v52,v127,171
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x54));
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// li r0,-64
	r0.s64 = -64;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82539AFC"))) PPC_WEAK_FUNC(sub_82539AFC);
PPC_FUNC_IMPL(__imp__sub_82539AFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82539B00"))) PPC_WEAK_FUNC(sub_82539B00);
PPC_FUNC_IMPL(__imp__sub_82539B00) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,15360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15360);
	f0.f64 = double(temp.f32);
	// addi r5,r10,-26088
	ctx.r5.s64 = ctx.r10.s64 + -26088;
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r8,r9,24,0,7
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFF000000;
	// oris r30,r8,255
	r30.u64 = ctx.r8.u64 | 16711680;
	// ori r30,r30,65535
	r30.u64 = r30.u64 | 65535;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82501dd8
	ctx.lr = 0x82539B54;
	sub_82501DD8(ctx, base);
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r7,-26124
	ctx.r5.s64 = ctx.r7.s64 + -26124;
	// bl 0x82501dd8
	ctx.lr = 0x82539B6C;
	sub_82501DD8(ctx, base);
	// lis r5,-32248
	ctx.r5.s64 = -2113404928;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r5,-26156
	ctx.r5.s64 = ctx.r5.s64 + -26156;
	// bl 0x82501dd8
	ctx.lr = 0x82539B84;
	sub_82501DD8(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r11,-26192
	ctx.r5.s64 = r11.s64 + -26192;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82501dd8
	ctx.lr = 0x82539B9C;
	sub_82501DD8(ctx, base);
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

__attribute__((alias("__imp__sub_82539BB4"))) PPC_WEAK_FUNC(sub_82539BB4);
PPC_FUNC_IMPL(__imp__sub_82539BB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82539BB8"))) PPC_WEAK_FUNC(sub_82539BB8);
PPC_FUNC_IMPL(__imp__sub_82539BB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r9,r11,-31616
	ctx.r9.s64 = r11.s64 + -31616;
	// addi r5,r10,31476
	ctx.r5.s64 = ctx.r10.s64 + 31476;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r8,32
	ctx.r8.s64 = 32;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// stb r4,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r4.u8);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r3,-32248
	ctx.r3.s64 = -2113404928;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r3,-26044
	ctx.r9.s64 = ctx.r3.s64 + -26044;
	// lfs f13,-4000(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -4000);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,17032(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 17032);
	ctx.f12.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stfs f13,216(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 216, temp.u32);
	// stfs f12,220(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 220, temp.u32);
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,176(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
	// stfs f0,180(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 180, temp.u32);
	// stfs f0,184(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 184, temp.u32);
	// stfs f0,192(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 192, temp.u32);
	// stfs f0,196(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 196, temp.u32);
	// stfs f13,200(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 200, temp.u32);
	// bl 0x82539a38
	ctx.lr = 0x82539C48;
	sub_82539A38(ctx, base);
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

__attribute__((alias("__imp__sub_82539C60"))) PPC_WEAK_FUNC(sub_82539C60);
PPC_FUNC_IMPL(__imp__sub_82539C60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r3,r11,-25992
	ctx.r3.s64 = r11.s64 + -25992;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82539C6C"))) PPC_WEAK_FUNC(sub_82539C6C);
PPC_FUNC_IMPL(__imp__sub_82539C6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82539C70"))) PPC_WEAK_FUNC(sub_82539C70);
PPC_FUNC_IMPL(__imp__sub_82539C70) {
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
	ctx.lr = 0x82539C78;
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lwz r11,21772(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 21772);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,2756(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 2756);
	f0.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// extsw r4,r11
	ctx.r4.s64 = r11.s32;
	// lfs f13,-26500(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -26500);
	ctx.f13.f64 = double(temp.f32);
	// lfs f31,208(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 208);
	f31.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lis r27,-32112
	r27.s64 = -2104492032;
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// lfs f12,14980(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14980);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,26468(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 26468);
	ctx.f11.f64 = double(temp.f32);
	// lfs f30,212(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 212);
	f30.f64 = double(temp.f32);
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fmuls f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// stfs f8,208(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// lfs f0,2764(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 2764);
	f0.f64 = double(temp.f32);
	// lwz r11,21784(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 21784);
	// extsw r3,r11
	ctx.r3.s64 = r11.s32;
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f6,80(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fmr f7,f8
	ctx.f7.f64 = ctx.f8.f64;
	// fmuls f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64));
	// fcmpu cr6,f31,f7
	cr6.compare(f31.f64, ctx.f7.f64);
	// fmsubs f1,f3,f12,f11
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f12.f64 - ctx.f11.f64));
	// stfs f1,212(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 212, temp.u32);
	// lwz r11,21788(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 21788);
	// clrlwi r30,r11,31
	r30.u64 = r11.u32 & 0x1;
	// rlwinm r28,r11,0,30,30
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// bne cr6,0x82539d3c
	if (!cr6.eq) goto loc_82539D3C;
	// fcmpu cr6,f30,f1
	cr6.compare(f30.f64, ctx.f1.f64);
	// bne cr6,0x82539d3c
	if (!cr6.eq) goto loc_82539D3C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82539d3c
	if (!cr6.eq) goto loc_82539D3C;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82539da4
	if (cr6.eq) goto loc_82539DA4;
loc_82539D3C:
	// addi r29,r31,48
	r29.s64 = r31.s64 + 48;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82224a40
	ctx.lr = 0x82539D48;
	sub_82224A40(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f1,208(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 208);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82204cb8
	ctx.lr = 0x82539D54;
	sub_82204CB8(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82539d78
	if (cr6.eq) goto loc_82539D78;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,220(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 220);
	f0.f64 = double(temp.f32);
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v63,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v0,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// b 0x82539d8c
	goto loc_82539D8C;
loc_82539D78:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82539da4
	if (cr6.eq) goto loc_82539DA4;
	// li r10,220
	ctx.r10.s64 = 220;
	// lvlx128 v62,r31,r10
	temp.u32 = r31.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v0,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
loc_82539D8C:
	// addi r11,r31,96
	r11.s64 = r31.s64 + 96;
	// li r9,80
	ctx.r9.s64 = 80;
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r31,r9
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v12,v0,v13
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82539DA4:
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// li r7,32
	ctx.r7.s64 = 32;
	// addi r9,r11,48
	ctx.r9.s64 = r11.s64 + 48;
	// li r8,16
	ctx.r8.s64 = 16;
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r31,112
	ctx.r10.s64 = r31.s64 + 112;
	// lvx128 v59,r11,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r6,2384
	ctx.r5.s64 = ctx.r6.s64 + 2384;
	// lvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v60,v59
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vor128 v53,v58,v58
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// lvx128 v55,r11,r8
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v56,v59,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// vmrglw128 v50,v60,v59
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmsum3fp128 v54,v60,v58
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v52,v55,v58
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// vmrghw128 v51,v55,v53
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// addi r11,r4,2352
	r11.s64 = ctx.r4.s64 + 2352;
	// vmrglw128 v49,v55,v53
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// li r3,48
	ctx.r3.s64 = 48;
	// vmrghw128 v48,v57,v51
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrglw128 v47,v57,v51
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v46,v50,v49
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vand128 v45,v48,v63
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v45,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v44,v47,v63
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v44,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v43,v54,v56
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrghw128 v41,v52,v43
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmrghw128 v40,v43,v41
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vsubfp128 v39,v61,v40
	simde_mm_store_ps(v39.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v40.f32)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v42,v46,v63
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v42,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v38,v39,v63
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v37,v63,v38
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v38.u8)));
	// stvx128 v37,r10,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,208(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 208);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bne cr6,0x82539e7c
	if (!cr6.eq) goto loc_82539E7C;
	// lfs f0,212(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 212);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// bne cr6,0x82539e7c
	if (!cr6.eq) goto loc_82539E7C;
	// lwz r11,21788(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 21788);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x82539e80
	if (cr6.eq) goto loc_82539E80;
loc_82539E7C:
	// li r11,1
	r11.s64 = 1;
loc_82539E80:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82539E94"))) PPC_WEAK_FUNC(sub_82539E94);
PPC_FUNC_IMPL(__imp__sub_82539E94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82539E98"))) PPC_WEAK_FUNC(sub_82539E98);
PPC_FUNC_IMPL(__imp__sub_82539E98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82539EA0;
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,16
	ctx.r7.s64 = 16;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// li r8,32
	ctx.r8.s64 = 32;
	// li r6,48
	ctx.r6.s64 = 48;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// lvx128 v61,r4,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r31,-32255
	r31.s64 = -2113863680;
	// stvx128 v61,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r30,-32112
	r30.s64 = -2104492032;
	// lvx128 v60,r4,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r29,-32122
	r29.s64 = -2105147392;
	// stvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r28,-32256
	r28.s64 = -2113929216;
	// lvx128 v59,r4,r6
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stvx128 v59,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,21772(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 21772);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// lfs f11,26468(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 26468);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,14980(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 14980);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r11,48
	ctx.r9.s64 = r11.s64 + 48;
	// std r10,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r10.u64);
	// lfd f0,-48(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,2756(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 2756);
	f0.f64 = double(temp.f32);
	// frsp f10,f13
	ctx.f10.f64 = double(float(ctx.f13.f64));
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// lfs f13,-26500(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -26500);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r3,112
	ctx.r10.s64 = ctx.r3.s64 + 112;
	// addi r4,r5,2384
	ctx.r4.s64 = ctx.r5.s64 + 2384;
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// addi r31,r5,2352
	r31.s64 = ctx.r5.s64 + 2352;
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fmuls f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// stfs f8,208(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 208, temp.u32);
	// lwz r5,21784(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 21784);
	// extsw r5,r5
	ctx.r5.s64 = ctx.r5.s32;
	// std r5,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r5.u64);
	// lfd f7,-48(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// lfs f0,2764(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 2764);
	f0.f64 = double(temp.f32);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fmuls f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * f0.f64));
	// fmsubs f3,f4,f12,f11
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f12.f64 - ctx.f11.f64));
	// stfs f3,212(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 212, temp.u32);
	// lvx128 v55,r11,r8
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r11,r7
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v56,v58,v58
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// vmsum3fp128 v52,v55,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// vmrghw128 v53,v54,v55
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmsum3fp128 v50,v54,v58
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// vmrghw128 v51,v57,v56
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmsum3fp128 v48,v57,v58
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// vmrglw128 v49,v54,v55
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrglw128 v47,v57,v56
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v46,v53,v51
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrglw128 v45,v53,v51
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrghw128 v44,v49,v47
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vand128 v43,v46,v63
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v43,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v42,v45,v63
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrghw128 v41,v50,v52
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// stvx128 v42,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v40,v44,v63
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrghw128 v39,v48,v41
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// stvx128 v40,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v38,v41,v39
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// vsubfp128 v37,v62,v38
	simde_mm_store_ps(v37.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v38.f32)));
	// vand128 v36,v37,v63
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v35,v63,v36
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v36.u8)));
	// stvx128 v35,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82539FEC"))) PPC_WEAK_FUNC(sub_82539FEC);
PPC_FUNC_IMPL(__imp__sub_82539FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82539FF0"))) PPC_WEAK_FUNC(sub_82539FF0);
PPC_FUNC_IMPL(__imp__sub_82539FF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
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
	// li r11,48
	r11.s64 = 48;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// li r6,96
	ctx.r6.s64 = 96;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// addi r5,r31,32
	ctx.r5.s64 = r31.s64 + 32;
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v61,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r3,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r3,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r0,r9
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v55,v57,v56
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v56.f32)));
	// stvx128 v55,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x8253A070;
	sub_82202EC0(ctx, base);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,16(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8253A084;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_8253A09C"))) PPC_WEAK_FUNC(sub_8253A09C);
PPC_FUNC_IMPL(__imp__sub_8253A09C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253A0A0"))) PPC_WEAK_FUNC(sub_8253A0A0);
PPC_FUNC_IMPL(__imp__sub_8253A0A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// addi r11,r3,160
	r11.s64 = ctx.r3.s64 + 160;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,144
	ctx.r10.s64 = 144;
	// vor128 v0,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r3,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3732(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3732);
	f0.f64 = double(temp.f32);
	// lfs f13,12(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,-16(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvlx128 v62,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmaddfp v11,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253A0E4"))) PPC_WEAK_FUNC(sub_8253A0E4);
PPC_FUNC_IMPL(__imp__sub_8253A0E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253A0E8"))) PPC_WEAK_FUNC(sub_8253A0E8);
PPC_FUNC_IMPL(__imp__sub_8253A0E8) {
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
	// lbz r10,1068(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1068);
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8253a13c
	if (cr6.eq) goto loc_8253A13C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r5,r9,-25696
	ctx.r5.s64 = ctx.r9.s64 + -25696;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lfs f0,15360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15360);
	f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r7,r8,24,0,7
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFF000000;
	// oris r6,r7,255
	ctx.r6.u64 = ctx.r7.u64 | 16711680;
	// ori r6,r6,65535
	ctx.r6.u64 = ctx.r6.u64 | 65535;
	// bl 0x82501dd8
	ctx.lr = 0x8253A13C;
	sub_82501DD8(ctx, base);
loc_8253A13C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253A14C"))) PPC_WEAK_FUNC(sub_8253A14C);
PPC_FUNC_IMPL(__imp__sub_8253A14C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253A150"))) PPC_WEAK_FUNC(sub_8253A150);
PPC_FUNC_IMPL(__imp__sub_8253A150) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// addi r10,r3,112
	ctx.r10.s64 = ctx.r3.s64 + 112;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,14988(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14988);
	f0.f64 = double(temp.f32);
	// lfs f13,-29232(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -29232);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v60,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,180(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 180, temp.u32);
	// stfs f13,184(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 184, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253A1A0"))) PPC_WEAK_FUNC(sub_8253A1A0);
PPC_FUNC_IMPL(__imp__sub_8253A1A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,1046(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1046);
	// lfs f0,180(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	f0.f64 = double(temp.f32);
	// lbz r10,1044(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1044);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8253a1e0
	if (cr6.eq) goto loc_8253A1E0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,17032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
loc_8253A1E0:
	// lbz r11,1058(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1058);
	// lbz r10,1056(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1056);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8253a210
	if (cr6.eq) goto loc_8253A210;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,14988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
loc_8253A210:
	// lbz r11,986(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 986);
	// li r10,144
	ctx.r10.s64 = 144;
	// lbz r9,984(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 984);
	// xor r8,r11,r9
	ctx.r8.u64 = r11.u64 ^ ctx.r9.u64;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// subfic r6,r7,127
	xer.ca = ctx.r7.u32 <= 127;
	ctx.r6.s64 = 127 - ctx.r7.s64;
	// subfe r5,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8253a264
	if (cr6.eq) goto loc_8253A264;
	// fmuls f13,f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f0.f64 * ctx.f1.f64));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r11,r3,160
	r11.s64 = ctx.r3.s64 + 160;
	// lvx128 v0,r3,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fneg f12,f13
	ctx.f12.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vmaddfp v11,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8253A264:
	// lbz r11,998(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 998);
	// lbz r9,996(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 996);
	// xor r8,r11,r9
	ctx.r8.u64 = r11.u64 ^ ctx.r9.u64;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// subfic r6,r7,127
	xer.ca = ctx.r7.u32 <= 127;
	ctx.r6.s64 = 127 - ctx.r7.s64;
	// subfe r5,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8253a2b0
	if (cr6.eq) goto loc_8253A2B0;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// fmuls f13,f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f0.f64 * ctx.f1.f64));
	// addi r11,r3,160
	r11.s64 = ctx.r3.s64 + 160;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v0,r3,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v62,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v12,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v0,v13,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8253A2B0:
	// lbz r11,1010(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1010);
	// li r10,112
	ctx.r10.s64 = 112;
	// lbz r9,1008(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1008);
	// xor r8,r11,r9
	ctx.r8.u64 = r11.u64 ^ ctx.r9.u64;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// subfic r6,r7,127
	xer.ca = ctx.r7.u32 <= 127;
	ctx.r6.s64 = 127 - ctx.r7.s64;
	// subfe r5,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8253a304
	if (cr6.eq) goto loc_8253A304;
	// fmuls f13,f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f0.f64 * ctx.f1.f64));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r11,r3,160
	r11.s64 = ctx.r3.s64 + 160;
	// lvx128 v0,r3,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fneg f12,f13
	ctx.f12.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v61,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vmaddfp v11,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8253A304:
	// lbz r11,1022(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1022);
	// lbz r9,1020(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1020);
	// xor r8,r11,r9
	ctx.r8.u64 = r11.u64 ^ ctx.r9.u64;
	// clrlwi r7,r8,24
	ctx.r7.u64 = ctx.r8.u32 & 0xFF;
	// subfic r6,r7,127
	xer.ca = ctx.r7.u32 <= 127;
	ctx.r6.s64 = 127 - ctx.r7.s64;
	// subfe r5,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8253a350
	if (cr6.eq) goto loc_8253A350;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// fmuls f0,f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * ctx.f1.f64));
	// addi r11,r3,160
	r11.s64 = ctx.r3.s64 + 160;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v0,r3,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v60,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// lvx128 v12,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v0,v13,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8253A350:
	// lbz r11,1034(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1034);
	// lbz r10,1032(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1032);
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// subfic r7,r8,127
	xer.ca = ctx.r8.u32 <= 127;
	ctx.r7.s64 = 127 - ctx.r8.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8253a384
	if (cr6.eq) goto loc_8253A384;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253A384;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8253A384:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253A394"))) PPC_WEAK_FUNC(sub_8253A394);
PPC_FUNC_IMPL(__imp__sub_8253A394) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253A398"))) PPC_WEAK_FUNC(sub_8253A398);
PPC_FUNC_IMPL(__imp__sub_8253A398) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x823d91d0
	ctx.lr = 0x8253A3A0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r9,r11,-31616
	ctx.r9.s64 = r11.s64 + -31616;
	// li r26,32
	r26.s64 = 32;
	// addi r8,r10,31476
	ctx.r8.s64 = ctx.r10.s64 + 31476;
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// li r30,0
	r30.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// addi r6,r7,-25636
	ctx.r6.s64 = ctx.r7.s64 + -25636;
	// stb r30,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r30.u8);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// addi r29,r31,196
	r29.s64 = r31.s64 + 196;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8260b730
	ctx.lr = 0x8253A3E8;
	sub_8260B730(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// stb r30,972(r31)
	PPC_STORE_U8(r31.u32 + 972, r30.u8);
	// addi r22,r31,984
	r22.s64 = r31.s64 + 984;
	// stb r30,973(r31)
	PPC_STORE_U8(r31.u32 + 973, r30.u8);
	// addi r21,r31,996
	r21.s64 = r31.s64 + 996;
	// stb r30,974(r31)
	PPC_STORE_U8(r31.u32 + 974, r30.u8);
	// addi r20,r31,1008
	r20.s64 = r31.s64 + 1008;
	// stb r30,975(r31)
	PPC_STORE_U8(r31.u32 + 975, r30.u8);
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
	// stb r30,976(r31)
	PPC_STORE_U8(r31.u32 + 976, r30.u8);
	// addi r19,r31,1020
	r19.s64 = r31.s64 + 1020;
	// stw r30,980(r31)
	PPC_STORE_U32(r31.u32 + 980, r30.u32);
	// li r23,16
	r23.s64 = 16;
	// stb r30,984(r31)
	PPC_STORE_U8(r31.u32 + 984, r30.u8);
	// li r24,48
	r24.s64 = 48;
	// stb r30,985(r31)
	PPC_STORE_U8(r31.u32 + 985, r30.u8);
	// addi r28,r31,48
	r28.s64 = r31.s64 + 48;
	// stb r30,986(r31)
	PPC_STORE_U8(r31.u32 + 986, r30.u8);
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stb r30,987(r31)
	PPC_STORE_U8(r31.u32 + 987, r30.u8);
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stb r30,988(r31)
	PPC_STORE_U8(r31.u32 + 988, r30.u8);
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stw r30,992(r31)
	PPC_STORE_U32(r31.u32 + 992, r30.u32);
	// vpermwi128 v58,v62,234
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stb r30,996(r31)
	PPC_STORE_U8(r31.u32 + 996, r30.u8);
	// vpermwi128 v57,v62,186
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stb r30,997(r31)
	PPC_STORE_U8(r31.u32 + 997, r30.u8);
	// vpermwi128 v56,v62,174
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stb r30,998(r31)
	PPC_STORE_U8(r31.u32 + 998, r30.u8);
	// addi r27,r31,112
	r27.s64 = r31.s64 + 112;
	// stb r30,999(r31)
	PPC_STORE_U8(r31.u32 + 999, r30.u8);
	// addi r25,r31,1032
	r25.s64 = r31.s64 + 1032;
	// stb r30,1000(r31)
	PPC_STORE_U8(r31.u32 + 1000, r30.u8);
	// stw r30,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, r30.u32);
	// stb r30,1008(r31)
	PPC_STORE_U8(r31.u32 + 1008, r30.u8);
	// stb r30,1009(r31)
	PPC_STORE_U8(r31.u32 + 1009, r30.u8);
	// stb r30,1010(r31)
	PPC_STORE_U8(r31.u32 + 1010, r30.u8);
	// stb r30,1011(r31)
	PPC_STORE_U8(r31.u32 + 1011, r30.u8);
	// stb r30,1012(r31)
	PPC_STORE_U8(r31.u32 + 1012, r30.u8);
	// stw r30,1016(r31)
	PPC_STORE_U32(r31.u32 + 1016, r30.u32);
	// stb r30,1020(r31)
	PPC_STORE_U8(r31.u32 + 1020, r30.u8);
	// stb r30,1021(r31)
	PPC_STORE_U8(r31.u32 + 1021, r30.u8);
	// stb r30,1022(r31)
	PPC_STORE_U8(r31.u32 + 1022, r30.u8);
	// stb r30,1023(r31)
	PPC_STORE_U8(r31.u32 + 1023, r30.u8);
	// stb r30,1024(r31)
	PPC_STORE_U8(r31.u32 + 1024, r30.u8);
	// stw r30,1028(r31)
	PPC_STORE_U32(r31.u32 + 1028, r30.u32);
	// stb r30,1032(r31)
	PPC_STORE_U8(r31.u32 + 1032, r30.u8);
	// stb r30,1033(r31)
	PPC_STORE_U8(r31.u32 + 1033, r30.u8);
	// stb r30,1034(r31)
	PPC_STORE_U8(r31.u32 + 1034, r30.u8);
	// stb r30,1035(r31)
	PPC_STORE_U8(r31.u32 + 1035, r30.u8);
	// stb r30,1036(r31)
	PPC_STORE_U8(r31.u32 + 1036, r30.u8);
	// stw r30,1040(r31)
	PPC_STORE_U32(r31.u32 + 1040, r30.u32);
	// stb r30,1044(r31)
	PPC_STORE_U8(r31.u32 + 1044, r30.u8);
	// stb r30,1045(r31)
	PPC_STORE_U8(r31.u32 + 1045, r30.u8);
	// stb r30,1046(r31)
	PPC_STORE_U8(r31.u32 + 1046, r30.u8);
	// stb r30,1047(r31)
	PPC_STORE_U8(r31.u32 + 1047, r30.u8);
	// stb r30,1048(r31)
	PPC_STORE_U8(r31.u32 + 1048, r30.u8);
	// stw r30,1052(r31)
	PPC_STORE_U32(r31.u32 + 1052, r30.u32);
	// stb r30,1056(r31)
	PPC_STORE_U8(r31.u32 + 1056, r30.u8);
	// stb r30,1057(r31)
	PPC_STORE_U8(r31.u32 + 1057, r30.u8);
	// stb r30,1058(r31)
	PPC_STORE_U8(r31.u32 + 1058, r30.u8);
	// stb r30,1059(r31)
	PPC_STORE_U8(r31.u32 + 1059, r30.u8);
	// stb r30,1060(r31)
	PPC_STORE_U8(r31.u32 + 1060, r30.u8);
	// stw r30,1064(r31)
	PPC_STORE_U32(r31.u32 + 1064, r30.u32);
	// stvx128 v61,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r28,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stvx128 v59,r28,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// stvx128 v63,r28,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,-1
	ctx.r7.s64 = -1;
	// stvx128 v58,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,256
	ctx.r5.s64 = 256;
	// stvx128 v57,r27,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,6
	ctx.r4.s64 = 6;
	// stvx128 v56,r27,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r31,1044
	r30.s64 = r31.s64 + 1044;
	// stvx128 v63,r27,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r18,r31,1056
	r18.s64 = r31.s64 + 1056;
	// bl 0x8260b740
	ctx.lr = 0x8253A52C;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// li r5,57
	ctx.r5.s64 = 57;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b740
	ctx.lr = 0x8253A544;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// li r5,17
	ctx.r5.s64 = 17;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b740
	ctx.lr = 0x8253A55C;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r21
	ctx.r6.u64 = r21.u64;
	// li r5,31
	ctx.r5.s64 = 31;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b740
	ctx.lr = 0x8253A574;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// li r5,30
	ctx.r5.s64 = 30;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b740
	ctx.lr = 0x8253A58C;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r19
	ctx.r6.u64 = r19.u64;
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b740
	ctx.lr = 0x8253A5A4;
	sub_8260B740(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r6,54
	ctx.r6.s64 = 54;
	// li r5,42
	ctx.r5.s64 = 42;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260b790
	ctx.lr = 0x8253A5BC;
	sub_8260B790(ctx, base);
	// mr r7,r18
	ctx.r7.u64 = r18.u64;
	// li r6,157
	ctx.r6.s64 = 157;
	// li r5,29
	ctx.r5.s64 = 29;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8260b790
	ctx.lr = 0x8253A5D4;
	sub_8260B790(ctx, base);
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// li r4,1
	ctx.r4.s64 = 1;
	// lis r3,-32112
	ctx.r3.s64 = -2104492032;
	// stb r4,1068(r31)
	PPC_STORE_U8(r31.u32 + 1068, ctx.r4.u8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r11,21772(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 21772);
	// extsw r8,r11
	ctx.r8.s64 = r11.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,188(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 188, temp.u32);
	// lwz r11,21784(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 21784);
	// extsw r7,r11
	ctx.r7.s64 = r11.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// lfs f13,-29232(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	ctx.f13.f64 = double(temp.f32);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// stfs f9,192(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 192, temp.u32);
	// lvx128 v55,r0,r28
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v55,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r28,r23
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r27,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r28,r26
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r27,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r28,r24
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r27,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,180(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 180, temp.u32);
	// stfs f13,184(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 184, temp.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_8253A660"))) PPC_WEAK_FUNC(sub_8253A660);
PPC_FUNC_IMPL(__imp__sub_8253A660) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r3,r11,-25584
	ctx.r3.s64 = r11.s64 + -25584;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253A66C"))) PPC_WEAK_FUNC(sub_8253A66C);
PPC_FUNC_IMPL(__imp__sub_8253A66C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253A670"))) PPC_WEAK_FUNC(sub_8253A670);
PPC_FUNC_IMPL(__imp__sub_8253A670) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8253A678;
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r10,21784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 21784);
	// li r29,0
	r29.s64 = 0;
	// lwz r9,21772(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 21772);
	// extsw r6,r10
	ctx.r6.s64 = ctx.r10.s32;
	// lfs f13,188(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 188);
	ctx.f13.f64 = double(temp.f32);
	// extsw r5,r9
	ctx.r5.s64 = ctx.r9.s32;
	// lwz r10,21788(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 21788);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// lfs f12,192(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 192);
	ctx.f12.f64 = double(temp.f32);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// lfs f11,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f11.f64 = double(temp.f32);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// clrlwi r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	// frsp f0,f8
	f0.f64 = double(float(ctx.f8.f64));
	// fsubs f12,f6,f12
	ctx.f12.f64 = double(float(ctx.f6.f64 - ctx.f12.f64));
	// fsubs f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// bne cr6,0x8253a6fc
	if (!cr6.eq) goto loc_8253A6FC;
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// beq cr6,0x8253a700
	if (cr6.eq) goto loc_8253A700;
loc_8253A6FC:
	// li r29,1
	r29.s64 = 1;
loc_8253A700:
	// stfs f0,188(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 188, temp.u32);
	// lwz r11,21784(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 21784);
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// fmuls f0,f13,f31
	f0.f64 = double(float(ctx.f13.f64 * f31.f64));
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// fmuls f30,f12,f31
	f30.f64 = double(float(ctx.f12.f64 * f31.f64));
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// stfs f10,192(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 192, temp.u32);
	// beq cr6,0x8253a788
	if (cr6.eq) goto loc_8253A788;
	// lfs f13,184(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 184);
	ctx.f13.f64 = double(temp.f32);
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// addi r30,r31,112
	r30.s64 = r31.s64 + 112;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r11,r11,-31280
	r11.s64 = r11.s64 + -31280;
	// addi r4,r11,32
	ctx.r4.s64 = r11.s64 + 32;
	// fmuls f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64));
	// fneg f1,f11
	ctx.f1.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// bne cr6,0x8253a768
	if (!cr6.eq) goto loc_8253A768;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
loc_8253A768:
	// bl 0x82350940
	ctx.lr = 0x8253A76C;
	sub_82350940(ctx, base);
	// lfs f10,184(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 184);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f30
	ctx.f9.f64 = double(float(ctx.f10.f64 * f30.f64));
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmuls f8,f9,f31
	ctx.f8.f64 = double(float(ctx.f9.f64 * f31.f64));
	// fneg f1,f8
	ctx.f1.u64 = ctx.f8.u64 ^ 0x8000000000000000;
	// bl 0x82350940
	ctx.lr = 0x8253A788;
	sub_82350940(ctx, base);
loc_8253A788:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8253A79C"))) PPC_WEAK_FUNC(sub_8253A79C);
PPC_FUNC_IMPL(__imp__sub_8253A79C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253A7A0"))) PPC_WEAK_FUNC(sub_8253A7A0);
PPC_FUNC_IMPL(__imp__sub_8253A7A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,1068(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1068);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8253a7d0
	if (!cr6.eq) goto loc_8253A7D0;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8253a804
	goto loc_8253A804;
loc_8253A7D0:
	// lfs f0,180(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 180);
	f0.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,196
	ctx.r3.s64 = r31.s64 + 196;
	// fmuls f31,f0,f1
	f31.f64 = double(float(f0.f64 * ctx.f1.f64));
	// bl 0x8260b990
	ctx.lr = 0x8253A7E4;
	sub_8260B990(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8253a670
	ctx.lr = 0x8253A7F0;
	sub_8253A670(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8253a1a0
	ctx.lr = 0x8253A800;
	sub_8253A1A0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8253A804:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
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

__attribute__((alias("__imp__sub_8253A820"))) PPC_WEAK_FUNC(sub_8253A820);
PPC_FUNC_IMPL(__imp__sub_8253A820) {
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
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-25536
	ctx.r9.s64 = r11.s64 + -25536;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8253a854
	if (cr6.eq) goto loc_8253A854;
	// bl 0x82130588
	ctx.lr = 0x8253A850;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8253A854:
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

__attribute__((alias("__imp__sub_8253A868"))) PPC_WEAK_FUNC(sub_8253A868);
PPC_FUNC_IMPL(__imp__sub_8253A868) {
	PPC_FUNC_PROLOGUE();
	// li r3,100
	ctx.r3.s64 = 100;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253A870"))) PPC_WEAK_FUNC(sub_8253A870);
PPC_FUNC_IMPL(__imp__sub_8253A870) {
	PPC_FUNC_PROLOGUE();
	// li r3,40
	ctx.r3.s64 = 40;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253A878"))) PPC_WEAK_FUNC(sub_8253A878);
PPC_FUNC_IMPL(__imp__sub_8253A878) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r18{};
	PPCRegister r19{};
	PPCRegister temp{};
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,6
	cr6.compare<uint32_t>(r11.u32, 6, xer);
	// bgt cr6,0x8253a8ec
	if (cr6.gt) goto loc_8253A8EC;
	// lis r12,-32172
	r12.s64 = -2108424192;
	// addi r12,r12,-22372
	r12.s64 = r12.s64 + -22372;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8253A8B8;
	case 1:
		goto loc_8253A8D8;
	case 2:
		goto loc_8253A8EC;
	case 3:
		goto loc_8253A8EC;
	case 4:
		goto loc_8253A8EC;
	case 5:
		goto loc_8253A8B8;
	case 6:
		goto loc_8253A8D8;
	default:
		__builtin_unreachable();
	}
	// lwz r18,-22344(r19)
	r18.u64 = PPC_LOAD_U32(r19.u32 + -22344);
	// lwz r18,-22312(r19)
	r18.u64 = PPC_LOAD_U32(r19.u32 + -22312);
	// lwz r18,-22292(r19)
	r18.u64 = PPC_LOAD_U32(r19.u32 + -22292);
	// lwz r18,-22292(r19)
	r18.u64 = PPC_LOAD_U32(r19.u32 + -22292);
	// lwz r18,-22292(r19)
	r18.u64 = PPC_LOAD_U32(r19.u32 + -22292);
	// lwz r18,-22344(r19)
	r18.u64 = PPC_LOAD_U32(r19.u32 + -22344);
	// lwz r18,-22312(r19)
	r18.u64 = PPC_LOAD_U32(r19.u32 + -22312);
loc_8253A8B8:
	// clrlwi r11,r5,16
	r11.u64 = ctx.r5.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8253a8d0
	if (!cr6.eq) goto loc_8253A8D0;
loc_8253A8C4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,14196(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14196);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_8253A8D0:
	// lfs f1,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_8253A8D8:
	// clrlwi r11,r5,16
	r11.u64 = ctx.r5.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253a8c4
	if (cr6.eq) goto loc_8253A8C4;
	// lfs f1,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_8253A8EC:
	// lfs f1,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
}

__attribute__((alias("__imp__sub_8253A8F4"))) PPC_WEAK_FUNC(sub_8253A8F4);
PPC_FUNC_IMPL(__imp__sub_8253A8F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253A8F8"))) PPC_WEAK_FUNC(sub_8253A8F8);
PPC_FUNC_IMPL(__imp__sub_8253A8F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,8(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// addic. r9,r11,-1
	xer.ca = r11.u32 > 0;
	ctx.r9.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt 0x8253a958
	if (cr0.lt) goto loc_8253A958;
	// rlwimi r5,r4,16,8,15
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r4.u32, 16) & 0xFF0000) | (ctx.r5.u64 & 0xFFFFFFFFFF00FFFF);
	// clrlwi r7,r5,8
	ctx.r7.u64 = ctx.r5.u32 & 0xFFFFFF;
loc_8253A910:
	// add r11,r9,r8
	r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// srawi r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r11.u32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,4(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwzx r4,r10,r5
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r5.u32);
	// lhz r10,2(r4)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + 2);
	// lbz r5,0(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rotlwi r4,r5,16
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 16);
	// or r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 | ctx.r10.u64;
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// beq cr6,0x8253a964
	if (cr6.eq) goto loc_8253A964;
	// ble cr6,0x8253a94c
	if (!cr6.gt) goto loc_8253A94C;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// b 0x8253a950
	goto loc_8253A950;
loc_8253A94C:
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
loc_8253A950:
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// ble cr6,0x8253a910
	if (!cr6.gt) goto loc_8253A910;
loc_8253A958:
	// stw r8,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r8.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8253A964:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253A974"))) PPC_WEAK_FUNC(sub_8253A974);
PPC_FUNC_IMPL(__imp__sub_8253A974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253A978"))) PPC_WEAK_FUNC(sub_8253A978);
PPC_FUNC_IMPL(__imp__sub_8253A978) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,8(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// li r3,32
	ctx.r3.s64 = 32;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253A994"))) PPC_WEAK_FUNC(sub_8253A994);
PPC_FUNC_IMPL(__imp__sub_8253A994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253A998"))) PPC_WEAK_FUNC(sub_8253A998);
PPC_FUNC_IMPL(__imp__sub_8253A998) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// sth r11,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r11.u16);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// sth r11,16(r3)
	PPC_STORE_U16(ctx.r3.u32 + 16, r11.u16);
	// sth r11,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, r11.u16);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r3,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253A9C4"))) PPC_WEAK_FUNC(sub_8253A9C4);
PPC_FUNC_IMPL(__imp__sub_8253A9C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253A9C8"))) PPC_WEAK_FUNC(sub_8253A9C8);
PPC_FUNC_IMPL(__imp__sub_8253A9C8) {
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
	ctx.lr = 0x8253A9D0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8253a9fc
	if (cr6.eq) goto loc_8253A9FC;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8217d890
	ctx.lr = 0x8253A9F0;
	sub_8217D890(ctx, base);
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r10.u32);
loc_8253A9FC:
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8253aa1c
	if (cr6.eq) goto loc_8253AA1C;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8217d890
	ctx.lr = 0x8253AA10;
	sub_8217D890(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
loc_8253AA1C:
	// lhz r11,18(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 18);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8253aabc
	if (!cr6.eq) goto loc_8253AABC;
	// lhz r11,8(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8253aabc
	if (!cr6.gt) goto loc_8253AABC;
	// mr r27,r11
	r27.u64 = r11.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r28,0
	r28.s64 = 0;
	// addi r25,r11,-26560
	r25.s64 = r11.s64 + -26560;
loc_8253AA48:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwzx r31,r28,r11
	r31.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8253aaa8
	if (cr6.eq) goto loc_8253AAA8;
	// lwz r30,0(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d828
	ctx.lr = 0x8253AA68;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8253aa90
	if (cr6.eq) goto loc_8253AA90;
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
	// b 0x8253aaa4
	goto loc_8253AAA4;
loc_8253AA90:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821d2378
	ctx.lr = 0x8253AAA0;
	sub_821D2378(ctx, base);
	// li r11,0
	r11.s64 = 0;
loc_8253AAA4:
	// add r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
loc_8253AAA8:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// stwx r31,r28,r11
	PPC_STORE_U32(r28.u32 + r11.u32, r31.u32);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x8253aa48
	if (!cr0.eq) goto loc_8253AA48;
loc_8253AABC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8253AAC8"))) PPC_WEAK_FUNC(sub_8253AAC8);
PPC_FUNC_IMPL(__imp__sub_8253AAC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x8253a9c8
	sub_8253A9C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8253AAD4"))) PPC_WEAK_FUNC(sub_8253AAD4);
PPC_FUNC_IMPL(__imp__sub_8253AAD4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253AAD8"))) PPC_WEAK_FUNC(sub_8253AAD8);
PPC_FUNC_IMPL(__imp__sub_8253AAD8) {
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
	ctx.lr = 0x8253AAE0;
	// stwu r1,-1728(r1)
	ea = -1728 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32112
	r27.s64 = -2104492032;
	// lwz r23,0(r13)
	r23.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r24,60
	r24.s64 = 60;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
	// li r25,0
	r25.s64 = 0;
	// lwz r11,23572(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 23572);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwzx r5,r24,r23
	ctx.r5.u64 = PPC_LOAD_U32(r24.u32 + r23.u32);
	// stwx r8,r24,r23
	PPC_STORE_U32(r24.u32 + r23.u32, ctx.r8.u32);
	// stw r4,23572(r27)
	PPC_STORE_U32(r27.u32 + 23572, ctx.r4.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// stw r9,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// sth r25,98(r1)
	PPC_STORE_U16(ctx.r1.u32 + 98, r25.u16);
	// sth r7,96(r1)
	PPC_STORE_U16(ctx.r1.u32 + 96, ctx.r7.u16);
	// stw r25,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r25.u32);
	// stb r25,92(r1)
	PPC_STORE_U8(ctx.r1.u32 + 92, r25.u8);
	// beq cr6,0x8253ab64
	if (cr6.eq) goto loc_8253AB64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8217d890
	ctx.lr = 0x8253AB58;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_8253AB64:
	// addi r28,r31,4
	r28.s64 = r31.s64 + 4;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8253ab90
	if (cr6.eq) goto loc_8253AB90;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8253ab90
	if (cr6.eq) goto loc_8253AB90;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8217d890
	ctx.lr = 0x8253AB84;
	sub_8217D890(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_8253AB90:
	// lhz r11,18(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 18);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8253aba8
	if (cr6.eq) goto loc_8253ABA8;
	// lis r11,20480
	r11.s64 = 1342177280;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
loc_8253ABA8:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8253ac48
	if (!cr6.gt) goto loc_8253AC48;
	// mr r29,r11
	r29.u64 = r11.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r30,r25
	r30.u64 = r25.u64;
	// addi r26,r11,-26560
	r26.s64 = r11.s64 + -26560;
loc_8253ABC4:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r31,r30,r11
	r31.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8253ac34
	if (cr6.eq) goto loc_8253AC34;
	// lwz r22,80(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8217d828
	ctx.lr = 0x8253ABE4;
	sub_8217D828(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8253ac0c
	if (cr6.eq) goto loc_8253AC0C;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r22
	r11.u64 = r11.u64 + r22.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r11,r9,r10
	r11.s64 = ctx.r10.s64 - ctx.r9.s64;
	// b 0x8253ac20
	goto loc_8253AC20;
loc_8253AC0C:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d2378
	ctx.lr = 0x8253AC1C;
	sub_821D2378(ctx, base);
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8253AC20:
	// add. r31,r11,r31
	r31.u64 = r11.u64 + r31.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x8253ac34
	if (cr0.eq) goto loc_8253AC34;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8253d960
	ctx.lr = 0x8253AC34;
	sub_8253D960(ctx, base);
loc_8253AC34:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// stwx r31,r30,r11
	PPC_STORE_U32(r30.u32 + r11.u32, r31.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8253abc4
	if (!cr0.eq) goto loc_8253ABC4;
loc_8253AC48:
	// lwz r11,23572(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 23572);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,23572(r27)
	PPC_STORE_U32(r27.u32 + 23572, r11.u32);
	// stwx r10,r24,r23
	PPC_STORE_U32(r24.u32 + r23.u32, ctx.r10.u32);
	// addi r1,r1,1728
	ctx.r1.s64 = ctx.r1.s64 + 1728;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8253AC64"))) PPC_WEAK_FUNC(sub_8253AC64);
PPC_FUNC_IMPL(__imp__sub_8253AC64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253AC68"))) PPC_WEAK_FUNC(sub_8253AC68);
PPC_FUNC_IMPL(__imp__sub_8253AC68) {
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
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x8253AC8C;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// sth r11,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r11.u16);
	// sth r11,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r11.u16);
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253acb0
	if (cr6.eq) goto loc_8253ACB0;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8253ACB0;
	sub_82130588(ctx, base);
loc_8253ACB0:
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

__attribute__((alias("__imp__sub_8253ACC8"))) PPC_WEAK_FUNC(sub_8253ACC8);
PPC_FUNC_IMPL(__imp__sub_8253ACC8) {
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
	ctx.lr = 0x8253ACD0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r3,32
	ctx.r3.s64 = 32;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82130528
	ctx.lr = 0x8253ACE4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r31,0
	r31.s64 = 0;
	// beq cr6,0x8253ad1c
	if (cr6.eq) goto loc_8253AD1C;
	// stw r31,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r31.u32);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// sth r31,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r31.u16);
	// sth r31,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r31.u16);
	// stw r31,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r31.u32);
	// sth r31,16(r3)
	PPC_STORE_U16(ctx.r3.u32 + 16, r31.u16);
	// sth r31,18(r3)
	PPC_STORE_U16(ctx.r3.u32 + 18, r31.u16);
	// stw r31,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r31.u32);
	// stw r31,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r31.u32);
	// stw r3,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r3.u32);
	// b 0x8253ad20
	goto loc_8253AD20;
loc_8253AD1C:
	// mr r26,r31
	r26.u64 = r31.u64;
loc_8253AD20:
	// stw r31,12(r26)
	PPC_STORE_U32(r26.u32 + 12, r31.u32);
	// addi r29,r26,4
	r29.s64 = r26.s64 + 4;
	// lhz r11,16(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 16);
	// sth r11,16(r26)
	PPC_STORE_U16(r26.u32 + 16, r11.u16);
	// lhz r10,18(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 18);
	// sth r10,18(r26)
	PPC_STORE_U16(r26.u32 + 18, ctx.r10.u16);
	// lwz r9,20(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// stw r9,20(r26)
	PPC_STORE_U32(r26.u32 + 20, ctx.r9.u32);
	// lwz r8,24(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// stw r8,24(r26)
	PPC_STORE_U32(r26.u32 + 24, ctx.r8.u32);
	// lhz r6,10(r26)
	ctx.r6.u64 = PPC_LOAD_U16(r26.u32 + 10);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// lhz r25,8(r27)
	r25.u64 = PPC_LOAD_U16(r27.u32 + 8);
	// bne cr6,0x8253ad7c
	if (!cr6.eq) goto loc_8253AD7C;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// sth r25,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r25.u16);
	// beq cr6,0x8253ad74
	if (cr6.eq) goto loc_8253AD74;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82504778
	ctx.lr = 0x8253AD70;
	sub_82504778(ctx, base);
	// b 0x8253ad78
	goto loc_8253AD78;
loc_8253AD74:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8253AD78:
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
loc_8253AD7C:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// sth r25,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r25.u16);
	// beq cr6,0x8253add0
	if (cr6.eq) goto loc_8253ADD0;
	// clrlwi r24,r30,24
	r24.u64 = r30.u32 & 0xFF;
loc_8253AD8C:
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x8253adb0
	if (cr6.eq) goto loc_8253ADB0;
	// rlwinm r30,r31,2,0,29
	r30.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r28,0(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x8253d9b0
	ctx.lr = 0x8253ADA8;
	sub_8253D9B0(ctx, base);
	// stwx r3,r30,r28
	PPC_STORE_U32(r30.u32 + r28.u32, ctx.r3.u32);
	// b 0x8253adc0
	goto loc_8253ADC0;
loc_8253ADB0:
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// stwx r8,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u32);
loc_8253ADC0:
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// clrlwi r31,r11,16
	r31.u64 = r11.u32 & 0xFFFF;
	// cmplw cr6,r31,r25
	cr6.compare<uint32_t>(r31.u32, r25.u32, xer);
	// blt cr6,0x8253ad8c
	if (cr6.lt) goto loc_8253AD8C;
loc_8253ADD0:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8253ADDC"))) PPC_WEAK_FUNC(sub_8253ADDC);
PPC_FUNC_IMPL(__imp__sub_8253ADDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253ADE0"))) PPC_WEAK_FUNC(sub_8253ADE0);
PPC_FUNC_IMPL(__imp__sub_8253ADE0) {
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
	ctx.lr = 0x8253ADE8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lhz r11,18(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 18);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8253ae34
	if (cr6.eq) goto loc_8253AE34;
	// li r5,32
	ctx.r5.s64 = 32;
	// bl 0x8244d5c0
	ctx.lr = 0x8253AE18;
	sub_8244D5C0(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r5,r31,32
	ctx.r5.s64 = r31.s64 + 32;
	// addi r4,r29,-32
	ctx.r4.s64 = r29.s64 + -32;
	// addi r3,r30,32
	ctx.r3.s64 = r30.s64 + 32;
	// addi r6,r11,-32
	ctx.r6.s64 = r11.s64 + -32;
	// bl 0x821d2e28
	ctx.lr = 0x8253AE30;
	sub_821D2E28(ctx, base);
	// b 0x8253ae3c
	goto loc_8253AE3C;
loc_8253AE34:
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x8244d5c0
	ctx.lr = 0x8253AE3C;
	sub_8244D5C0(ctx, base);
loc_8253AE3C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8253aad8
	ctx.lr = 0x8253AE44;
	sub_8253AAD8(ctx, base);
	// lhz r11,18(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 18);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// sth r10,18(r30)
	PPC_STORE_U16(r30.u32 + 18, ctx.r10.u16);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8253AE58"))) PPC_WEAK_FUNC(sub_8253AE58);
PPC_FUNC_IMPL(__imp__sub_8253AE58) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x8253ade0
	sub_8253ADE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8253AE60"))) PPC_WEAK_FUNC(sub_8253AE60);
PPC_FUNC_IMPL(__imp__sub_8253AE60) {
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
	ctx.lr = 0x8253AE68;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// addi r29,r26,4
	r29.s64 = r26.s64 + 4;
	// li r28,0
	r28.s64 = 0;
	// lhz r11,10(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8253aeac
	if (!cr6.eq) goto loc_8253AEAC;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r30.u16);
	// beq cr6,0x8253aea4
	if (cr6.eq) goto loc_8253AEA4;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8253AEA0;
	sub_82130528(ctx, base);
	// b 0x8253aea8
	goto loc_8253AEA8;
loc_8253AEA4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_8253AEA8:
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
loc_8253AEAC:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// sth r30,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r30.u16);
	// ble cr6,0x8253af14
	if (!cr6.gt) goto loc_8253AF14;
	// mr r31,r28
	r31.u64 = r28.u64;
loc_8253AEBC:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x8253AEC4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8253aee4
	if (cr6.eq) goto loc_8253AEE4;
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r28.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r28,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r28.u32);
	// stw r28,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r28.u32);
	// stw r28,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r28.u32);
	// b 0x8253aee8
	goto loc_8253AEE8;
loc_8253AEE4:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_8253AEE8:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stwx r11,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, r11.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r25,r31,r9
	r25.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// bl 0x82130550
	ctx.lr = 0x8253AF04;
	sub_82130550(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// stw r3,12(r25)
	PPC_STORE_U32(r25.u32 + 12, ctx.r3.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x8253aebc
	if (!cr0.eq) goto loc_8253AEBC;
loc_8253AF14:
	// stw r27,12(r26)
	PPC_STORE_U32(r26.u32 + 12, r27.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8253AF20"))) PPC_WEAK_FUNC(sub_8253AF20);
PPC_FUNC_IMPL(__imp__sub_8253AF20) {
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
	ctx.lr = 0x8253AF28;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x82529eb8
	ctx.lr = 0x8253AF4C;
	sub_82529EB8(ctx, base);
	// lis r8,32767
	ctx.r8.s64 = 2147418112;
	// li r28,-1
	r28.s64 = -1;
	// ori r8,r8,65535
	ctx.r8.u64 = ctx.r8.u64 | 65535;
	// li r11,0
	r11.s64 = 0;
	// lhz r25,8(r31)
	r25.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x8253b0c8
	if (!cr6.gt) goto loc_8253B0C8;
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
loc_8253AF70:
	// lwz r9,0(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplw cr6,r8,r10
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, xer);
	// blt cr6,0x8253af94
	if (cr6.lt) goto loc_8253AF94;
	// lwz r9,8(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8253af94
	if (!cr6.eq) goto loc_8253AF94;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_8253AF94:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmpw cr6,r11,r25
	cr6.compare<int32_t>(r11.s32, r25.s32, xer);
	// blt cr6,0x8253af70
	if (cr6.lt) goto loc_8253AF70;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x8253b0c8
	if (cr6.lt) goto loc_8253B0C8;
	// rlwinm r11,r28,2,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r29,r11,r6
	r29.u64 = PPC_LOAD_U32(r11.u32 + ctx.r6.u32);
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r27,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r27.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// lwz r5,12(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mtctr r26
	ctr.u64 = r26.u64;
	// bctrl 
	ctx.lr = 0x8253AFE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r30,r27
	cr6.compare<uint32_t>(r30.u32, r27.u32, xer);
	// ble cr6,0x8253b034
	if (!cr6.gt) goto loc_8253B034;
	// addic. r9,r28,-1
	xer.ca = r28.u32 > 0;
	ctx.r9.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt 0x8253b088
	if (cr0.lt) goto loc_8253B088;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
loc_8253AFF4:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r6,0(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r5,0(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cmplw cr6,r6,r5
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r5.u32, xer);
	// ble cr6,0x8253b088
	if (!cr6.gt) goto loc_8253B088;
	// rotlwi r8,r7,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// bge 0x8253aff4
	if (!cr0.lt) goto loc_8253AFF4;
	// b 0x8253b088
	goto loc_8253B088;
loc_8253B034:
	// bge cr6,0x8253b088
	if (!cr6.lt) goto loc_8253B088;
	// addi r9,r28,1
	ctx.r9.s64 = r28.s64 + 1;
	// cmpw cr6,r9,r25
	cr6.compare<int32_t>(ctx.r9.s32, r25.s32, xer);
	// bge cr6,0x8253b088
	if (!cr6.lt) goto loc_8253B088;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
loc_8253B048:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,-4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r6,0(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r5,0(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cmplw cr6,r6,r5
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r5.u32, xer);
	// bge cr6,0x8253b088
	if (!cr6.lt) goto loc_8253B088;
	// rotlwi r8,r7,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r9,r25
	cr6.compare<int32_t>(ctx.r9.s32, r25.s32, xer);
	// stw r7,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r7.u32);
	// blt cr6,0x8253b048
	if (cr6.lt) goto loc_8253B048;
loc_8253B088:
	// lwz r11,4(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// beq cr6,0x8253b0bc
	if (cr6.eq) goto loc_8253B0BC;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r11.u32);
	// lwz r11,4(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253b0b8
	if (cr6.eq) goto loc_8253B0B8;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
loc_8253B0B8:
	// stw r29,4(r24)
	PPC_STORE_U32(r24.u32 + 4, r29.u32);
loc_8253B0BC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_8253B0C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8253B0D4"))) PPC_WEAK_FUNC(sub_8253B0D4);
PPC_FUNC_IMPL(__imp__sub_8253B0D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253B0D8"))) PPC_WEAK_FUNC(sub_8253B0D8);
PPC_FUNC_IMPL(__imp__sub_8253B0D8) {
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
	ctx.lr = 0x8253B0E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// sth r11,8(r31)
	PPC_STORE_U16(r31.u32 + 8, r11.u16);
	// sth r11,10(r31)
	PPC_STORE_U16(r31.u32 + 10, r11.u16);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// bl 0x821c8ed8
	ctx.lr = 0x8253B110;
	sub_821C8ED8(ctx, base);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8253ae60
	ctx.lr = 0x8253B124;
	sub_8253AE60(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8253B130"))) PPC_WEAK_FUNC(sub_8253B130);
PPC_FUNC_IMPL(__imp__sub_8253B130) {
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
	// li r11,0
	r11.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// bl 0x82529e18
	ctx.lr = 0x8253B158;
	sub_82529E18(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82529e18
	ctx.lr = 0x8253B160;
	sub_82529E18(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82130000
	ctx.lr = 0x8253B168;
	sub_82130000(ctx, base);
	// lhz r10,10(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8253b17c
	if (cr6.eq) goto loc_8253B17C;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x8253B17C;
	sub_82130588(ctx, base);
loc_8253B17C:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253b194
	if (cr6.eq) goto loc_8253B194;
	// bl 0x82130588
	ctx.lr = 0x8253B190;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8253B194:
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

__attribute__((alias("__imp__sub_8253B1AC"))) PPC_WEAK_FUNC(sub_8253B1AC);
PPC_FUNC_IMPL(__imp__sub_8253B1AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253B1B0"))) PPC_WEAK_FUNC(sub_8253B1B0);
PPC_FUNC_IMPL(__imp__sub_8253B1B0) {
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
	ctx.lr = 0x8253B1B8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x8253B1D8;
	sub_821C8FE0(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82529f90
	ctx.lr = 0x8253B1E8;
	sub_82529F90(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8253B1F4;
	sub_821C9030(ctx, base);
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8253b23c
	if (!cr6.eq) goto loc_8253B23C;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253b23c
	if (cr6.eq) goto loc_8253B23C;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8253b23c
	if (cr6.gt) goto loc_8253B23C;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// lis r11,-32172
	r11.s64 = -2108424192;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r11,-20904
	ctx.r5.s64 = r11.s64 + -20904;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8252a198
	ctx.lr = 0x8253B23C;
	sub_8252A198(ctx, base);
loc_8253B23C:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253b260
	if (cr6.eq) goto loc_8253B260;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r10,1
	ctx.r3.u64 = ctx.r10.u64 ^ 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8253B260:
	// li r11,0
	r11.s64 = 0;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r10,1
	ctx.r3.u64 = ctx.r10.u64 ^ 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8253B278"))) PPC_WEAK_FUNC(sub_8253B278);
PPC_FUNC_IMPL(__imp__sub_8253B278) {
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
	// lis r31,-32114
	r31.s64 = -2104623104;
	// lwz r3,-32560(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -32560);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8253b2a8
	if (cr6.eq) goto loc_8253B2A8;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8253b130
	ctx.lr = 0x8253B2A0;
	sub_8253B130(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,-32560(r31)
	PPC_STORE_U32(r31.u32 + -32560, r11.u32);
loc_8253B2A8:
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

__attribute__((alias("__imp__sub_8253B2BC"))) PPC_WEAK_FUNC(sub_8253B2BC);
PPC_FUNC_IMPL(__imp__sub_8253B2BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253B2C0"))) PPC_WEAK_FUNC(sub_8253B2C0);
PPC_FUNC_IMPL(__imp__sub_8253B2C0) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lbz r11,0(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,35
	cr6.compare<uint32_t>(r11.u32, 35, xer);
	// bne cr6,0x8253b300
	if (!cr6.eq) goto loc_8253B300;
	// addi r3,r4,1
	ctx.r3.s64 = ctx.r4.s64 + 1;
	// bl 0x823dd7f0
	ctx.lr = 0x8253B2E8;
	sub_823DD7F0(ctx, base);
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
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
loc_8253B300:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137248
	ctx.lr = 0x8253B308;
	sub_82137248(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823b8608
	ctx.lr = 0x8253B310;
	sub_823B8608(ctx, base);
	// lhz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8253b324
	if (cr6.eq) goto loc_8253B324;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8253b32c
	goto loc_8253B32C;
loc_8253B324:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,3998
	ctx.r3.s64 = r11.s64 + 3998;
loc_8253B32C:
	// bl 0x821c9608
	ctx.lr = 0x8253B330;
	sub_821C9608(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82130588
	ctx.lr = 0x8253B33C;
	sub_82130588(ctx, base);
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

__attribute__((alias("__imp__sub_8253B354"))) PPC_WEAK_FUNC(sub_8253B354);
PPC_FUNC_IMPL(__imp__sub_8253B354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253B358"))) PPC_WEAK_FUNC(sub_8253B358);
PPC_FUNC_IMPL(__imp__sub_8253B358) {
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
	ctx.lr = 0x8253B360;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r28,16
	r28.s64 = 16;
	// li r31,0
	r31.s64 = 0;
	// lhz r11,12(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253b3a8
	if (cr6.eq) goto loc_8253B3A8;
	// li r30,0
	r30.s64 = 0;
loc_8253B380:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x8253c9d8
	ctx.lr = 0x8253B38C;
	sub_8253C9D8(ctx, base);
	// lhz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// add r11,r3,r28
	r11.u64 = ctx.r3.u64 + r28.u64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r28,r11,4
	r28.s64 = r11.s64 + 4;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// blt cr6,0x8253b380
	if (cr6.lt) goto loc_8253B380;
loc_8253B3A8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8253B3B4"))) PPC_WEAK_FUNC(sub_8253B3B4);
PPC_FUNC_IMPL(__imp__sub_8253B3B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253B3B8"))) PPC_WEAK_FUNC(sub_8253B3B8);
PPC_FUNC_IMPL(__imp__sub_8253B3B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// li r10,255
	ctx.r10.s64 = 255;
	// li r9,15
	ctx.r9.s64 = 15;
	// sth r11,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, r11.u16);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stb r10,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r10.u8);
	// li r7,127
	ctx.r7.s64 = 127;
	// stb r9,1(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1, ctx.r9.u8);
	// sth r8,2(r3)
	PPC_STORE_U16(ctx.r3.u32 + 2, ctx.r8.u16);
	// sth r7,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r7.u16);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
	// sth r11,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253B3F0"))) PPC_WEAK_FUNC(sub_8253B3F0);
PPC_FUNC_IMPL(__imp__sub_8253B3F0) {
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
	ctx.lr = 0x8253B3F8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// lhz r29,12(r30)
	r29.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x8253b448
	if (!cr6.gt) goto loc_8253B448;
	// mr r31,r27
	r31.u64 = r27.u64;
loc_8253B414:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwzx r28,r11,r31
	r28.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8253b434
	if (cr6.eq) goto loc_8253B434;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8253d020
	ctx.lr = 0x8253B42C;
	sub_8253D020(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x8253B434;
	sub_82130588(ctx, base);
loc_8253B434:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// stwx r27,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r27.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x8253b414
	if (!cr0.eq) goto loc_8253B414;
loc_8253B448:
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x8253B450;
	sub_82130588(ctx, base);
	// stw r27,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r27.u32);
	// sth r27,12(r30)
	PPC_STORE_U16(r30.u32 + 12, r27.u16);
	// sth r27,14(r30)
	PPC_STORE_U16(r30.u32 + 14, r27.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8253B464"))) PPC_WEAK_FUNC(sub_8253B464);
PPC_FUNC_IMPL(__imp__sub_8253B464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253B468"))) PPC_WEAK_FUNC(sub_8253B468);
PPC_FUNC_IMPL(__imp__sub_8253B468) {
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
	ctx.lr = 0x8253B470;
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
	// beq cr6,0x8253b498
	if (cr6.eq) goto loc_8253B498;
	// bl 0x8217d890
	ctx.lr = 0x8253B48C;
	sub_8217D890(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_8253B498:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// li r23,0
	r23.s64 = 0;
	// mr r24,r23
	r24.u64 = r23.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253b528
	if (cr6.eq) goto loc_8253B528;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,60
	r27.s64 = 60;
	// mr r25,r23
	r25.u64 = r23.u64;
loc_8253B4B8:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r30,r27,r26
	r30.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// add r31,r25,r11
	r31.u64 = r25.u64 + r11.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8253b510
	if (cr6.eq) goto loc_8253B510;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8253b510
	if (cr6.eq) goto loc_8253B510;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8253B4E4;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8253b510
	if (cr6.eq) goto loc_8253B510;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8253B4F8;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r27,r26
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + r26.u32);
	// bl 0x8253d998
	ctx.lr = 0x8253B50C;
	sub_8253D998(ctx, base);
	// b 0x8253b514
	goto loc_8253B514;
loc_8253B510:
	// stw r23,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r23.u32);
loc_8253B514:
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x8253b4b8
	if (cr6.lt) goto loc_8253B4B8;
loc_8253B528:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8253B534"))) PPC_WEAK_FUNC(sub_8253B534);
PPC_FUNC_IMPL(__imp__sub_8253B534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253B538"))) PPC_WEAK_FUNC(sub_8253B538);
PPC_FUNC_IMPL(__imp__sub_8253B538) {
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
	// bl 0x8253b3f0
	ctx.lr = 0x8253B550;
	sub_8253B3F0(ctx, base);
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253b564
	if (cr6.eq) goto loc_8253B564;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x8253B564;
	sub_82130588(ctx, base);
loc_8253B564:
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

__attribute__((alias("__imp__sub_8253B578"))) PPC_WEAK_FUNC(sub_8253B578);
PPC_FUNC_IMPL(__imp__sub_8253B578) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// b 0x8253b468
	sub_8253B468(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8253B58C"))) PPC_WEAK_FUNC(sub_8253B58C);
PPC_FUNC_IMPL(__imp__sub_8253B58C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253B590"))) PPC_WEAK_FUNC(sub_8253B590);
PPC_FUNC_IMPL(__imp__sub_8253B590) {
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
	// bne cr6,0x8253b5d4
	if (!cr6.eq) goto loc_8253B5D4;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x8253b5cc
	if (cr6.eq) goto loc_8253B5CC;
	// bl 0x825048c0
	ctx.lr = 0x8253B5C8;
	sub_825048C0(ctx, base);
	// b 0x8253b5d0
	goto loc_8253B5D0;
loc_8253B5CC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8253B5D0:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_8253B5D4:
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

__attribute__((alias("__imp__sub_8253B5F0"))) PPC_WEAK_FUNC(sub_8253B5F0);
PPC_FUNC_IMPL(__imp__sub_8253B5F0) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8253B5F8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lhz r11,2(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 2);
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bge cr6,0x8253b6ac
	if (!cr6.lt) goto loc_8253B6AC;
	// lhz r11,14(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 14);
	// addi r31,r28,8
	r31.s64 = r28.s64 + 8;
	// li r29,1
	r29.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8253b638
	if (!cr6.eq) goto loc_8253B638;
	// sth r29,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r29.u16);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825048c0
	ctx.lr = 0x8253B634;
	sub_825048C0(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_8253B638:
	// sth r29,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r29.u16);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x8253B644;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8253b654
	if (cr6.eq) goto loc_8253B654;
	// bl 0x8253d920
	ctx.lr = 0x8253B650;
	sub_8253D920(ctx, base);
	// b 0x8253b658
	goto loc_8253B658;
loc_8253B654:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8253B658:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8253c808
	ctx.lr = 0x8253B670;
	sub_8253C808(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// li r9,-1
	ctx.r9.s64 = -1;
	// lbz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// stb r6,0(r28)
	PPC_STORE_U8(r28.u32 + 0, ctx.r6.u8);
	// lwz r5,0(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lbz r4,1(r5)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r5.u32 + 1);
	// clrlwi r3,r4,28
	ctx.r3.u64 = ctx.r4.u32 & 0xF;
	// stb r3,1(r28)
	PPC_STORE_U8(r28.u32 + 1, ctx.r3.u8);
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// sth r10,2(r28)
	PPC_STORE_U16(r28.u32 + 2, ctx.r10.u16);
	// sth r9,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r9.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8253B6AC:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
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
	// beq cr6,0x8253b6dc
	if (cr6.eq) goto loc_8253B6DC;
	// bl 0x821be250
	ctx.lr = 0x8253B6D8;
	sub_821BE250(ctx, base);
	// b 0x8253b6e0
	goto loc_8253B6E0;
loc_8253B6DC:
	// bl 0x821be3d8
	ctx.lr = 0x8253B6E0;
	sub_821BE3D8(ctx, base);
loc_8253B6E0:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// addi r4,r28,1
	ctx.r4.s64 = r28.s64 + 1;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
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
	// beq cr6,0x8253b710
	if (cr6.eq) goto loc_8253B710;
	// bl 0x821be250
	ctx.lr = 0x8253B70C;
	sub_821BE250(ctx, base);
	// b 0x8253b714
	goto loc_8253B714;
loc_8253B710:
	// bl 0x821be3d8
	ctx.lr = 0x8253B714;
	sub_821BE3D8(ctx, base);
loc_8253B714:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// addi r4,r28,2
	ctx.r4.s64 = r28.s64 + 2;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
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
	// beq cr6,0x8253b744
	if (cr6.eq) goto loc_8253B744;
	// bl 0x821be6a8
	ctx.lr = 0x8253B740;
	sub_821BE6A8(ctx, base);
	// b 0x8253b748
	goto loc_8253B748;
loc_8253B744:
	// bl 0x821be780
	ctx.lr = 0x8253B748;
	sub_821BE780(ctx, base);
loc_8253B748:
	// lhz r11,2(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 2);
	// cmplwi cr6,r11,9
	cr6.compare<uint32_t>(r11.u32, 9, xer);
	// blt cr6,0x8253b788
	if (cr6.lt) goto loc_8253B788;
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// addi r4,r28,6
	ctx.r4.s64 = r28.s64 + 6;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
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
	// beq cr6,0x8253b784
	if (cr6.eq) goto loc_8253B784;
	// bl 0x821be6a8
	ctx.lr = 0x8253B780;
	sub_821BE6A8(ctx, base);
	// b 0x8253b788
	goto loc_8253B788;
loc_8253B784:
	// bl 0x821be780
	ctx.lr = 0x8253B788;
	sub_821BE780(ctx, base);
loc_8253B788:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// lhz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 12);
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
	// beq cr6,0x8253b7c0
	if (cr6.eq) goto loc_8253B7C0;
	// bl 0x821be6a8
	ctx.lr = 0x8253B7BC;
	sub_821BE6A8(ctx, base);
	// b 0x8253b7c4
	goto loc_8253B7C4;
loc_8253B7C0:
	// bl 0x821be780
	ctx.lr = 0x8253B7C4;
	sub_821BE780(ctx, base);
loc_8253B7C4:
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
	// beq cr6,0x8253b840
	if (cr6.eq) goto loc_8253B840;
	// addi r29,r28,8
	r29.s64 = r28.s64 + 8;
	// lhz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8253b590
	ctx.lr = 0x8253B7F0;
	sub_8253B590(ctx, base);
	// lhz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8253b840
	if (cr6.eq) goto loc_8253B840;
	// li r31,0
	r31.s64 = 0;
loc_8253B800:
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x8253B808;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8253b818
	if (cr6.eq) goto loc_8253B818;
	// bl 0x8253d920
	ctx.lr = 0x8253B814;
	sub_8253D920(ctx, base);
	// b 0x8253b81c
	goto loc_8253B81C;
loc_8253B818:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8253B81C:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r9,r31,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r31,1
	ctx.r8.s64 = r31.s64 + 1;
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// stwx r3,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r3.u32);
	// mr r31,r11
	r31.u64 = r11.u64;
	// lhz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// cmplw cr6,r11,r6
	cr6.compare<uint32_t>(r11.u32, ctx.r6.u32, xer);
	// blt cr6,0x8253b800
	if (cr6.lt) goto loc_8253B800;
loc_8253B840:
	// lhz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8253b878
	if (cr6.eq) goto loc_8253B878;
	// li r31,0
	r31.s64 = 0;
loc_8253B850:
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// bl 0x8253c808
	ctx.lr = 0x8253B864;
	sub_8253C808(ctx, base);
	// addi r9,r31,1
	ctx.r9.s64 = r31.s64 + 1;
	// lhz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// clrlwi r31,r9,16
	r31.u64 = ctx.r9.u32 & 0xFFFF;
	// cmplw cr6,r31,r7
	cr6.compare<uint32_t>(r31.u32, ctx.r7.u32, xer);
	// blt cr6,0x8253b850
	if (cr6.lt) goto loc_8253B850;
loc_8253B878:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// addi r4,r28,4
	ctx.r4.s64 = r28.s64 + 4;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
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
	// beq cr6,0x8253b8ac
	if (cr6.eq) goto loc_8253B8AC;
	// bl 0x821be6a8
	ctx.lr = 0x8253B8A4;
	sub_821BE6A8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8253B8AC:
	// bl 0x821be780
	ctx.lr = 0x8253B8B0;
	sub_821BE780(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8253B8B8"))) PPC_WEAK_FUNC(sub_8253B8B8);
PPC_FUNC_IMPL(__imp__sub_8253B8B8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x8253B8C0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r22,r7
	r22.u64 = ctx.r7.u64;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// bl 0x8253b3f0
	ctx.lr = 0x8253B8E0;
	sub_8253B3F0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r25,0(r27)
	PPC_STORE_U8(r27.u32 + 0, r25.u8);
	// sth r24,2(r27)
	PPC_STORE_U16(r27.u32 + 2, r24.u16);
	// stb r11,1(r27)
	PPC_STORE_U8(r27.u32 + 1, r11.u8);
	// sth r31,4(r27)
	PPC_STORE_U16(r27.u32 + 4, r31.u16);
	// lhz r21,4(r23)
	r21.u64 = PPC_LOAD_U16(r23.u32 + 4);
	// cmplwi cr6,r21,1
	cr6.compare<uint32_t>(r21.u32, 1, xer);
	// ble cr6,0x8253b92c
	if (!cr6.gt) goto loc_8253B92C;
	// addi r10,r21,-2
	ctx.r10.s64 = r21.s64 + -2;
	// clrlwi r9,r31,16
	ctx.r9.u64 = r31.u32 & 0xFFFF;
	// rotlwi r11,r10,1
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r10,r10,r9
	ctx.r10.s32 = ctx.r10.s32 / ctx.r9.s32;
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// andc r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 & ~ctx.r8.u64;
	// twllei r9,0
	// clrlwi r11,r7,16
	r11.u64 = ctx.r7.u32 & 0xFFFF;
	// twlgei r6,-1
	// b 0x8253b930
	goto loc_8253B930;
loc_8253B92C:
	// li r11,1
	r11.s64 = 1;
loc_8253B930:
	// lhz r10,14(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 14);
	// addi r30,r27,8
	r30.s64 = r27.s64 + 8;
	// clrlwi r26,r11,16
	r26.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8253b968
	if (!cr6.eq) goto loc_8253B968;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// sth r26,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r26.u16);
	// beq cr6,0x8253b960
	if (cr6.eq) goto loc_8253B960;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825048c0
	ctx.lr = 0x8253B95C;
	sub_825048C0(ctx, base);
	// b 0x8253b964
	goto loc_8253B964;
loc_8253B960:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8253B964:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_8253B968:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// sth r26,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r26.u16);
	// beq cr6,0x8253ba0c
	if (cr6.eq) goto loc_8253BA0C;
	// li r31,0
	r31.s64 = 0;
loc_8253B978:
	// lhz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// mullw r11,r31,r10
	r11.s64 = int64_t(r31.s32) * int64_t(ctx.r10.s32);
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// subf r9,r11,r21
	ctx.r9.s64 = r21.s64 - r11.s64;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// mr r28,r11
	r28.u64 = r11.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// blt cr6,0x8253b9a8
	if (cr6.lt) goto loc_8253B9A8;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
loc_8253B9A8:
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x8253B9B0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8253b9c0
	if (cr6.eq) goto loc_8253B9C0;
	// bl 0x8253d920
	ctx.lr = 0x8253B9BC;
	sub_8253D920(ctx, base);
	// b 0x8253b9c4
	goto loc_8253B9C4;
loc_8253B9C0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8253B9C4:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r9,r31,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r28,4,0,27
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// clrlwi r7,r29,16
	ctx.r7.u64 = r29.u32 & 0xFFFF;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// stwx r3,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r3.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// lwzx r3,r3,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r9.u32);
	// bl 0x8253d028
	ctx.lr = 0x8253B9F8;
	sub_8253D028(ctx, base);
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplw cr6,r11,r26
	cr6.compare<uint32_t>(r11.u32, r26.u32, xer);
	// blt cr6,0x8253b978
	if (cr6.lt) goto loc_8253B978;
loc_8253BA0C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8253BA14"))) PPC_WEAK_FUNC(sub_8253BA14);
PPC_FUNC_IMPL(__imp__sub_8253BA14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253BA18"))) PPC_WEAK_FUNC(sub_8253BA18);
PPC_FUNC_IMPL(__imp__sub_8253BA18) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x8253BA20;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r22,r7
	r22.u64 = ctx.r7.u64;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// bl 0x8253b3f0
	ctx.lr = 0x8253BA40;
	sub_8253B3F0(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r25,0(r27)
	PPC_STORE_U8(r27.u32 + 0, r25.u8);
	// sth r24,2(r27)
	PPC_STORE_U16(r27.u32 + 2, r24.u16);
	// stb r11,1(r27)
	PPC_STORE_U8(r27.u32 + 1, r11.u8);
	// sth r31,4(r27)
	PPC_STORE_U16(r27.u32 + 4, r31.u16);
	// lhz r21,4(r23)
	r21.u64 = PPC_LOAD_U16(r23.u32 + 4);
	// cmplwi cr6,r21,1
	cr6.compare<uint32_t>(r21.u32, 1, xer);
	// ble cr6,0x8253ba88
	if (!cr6.gt) goto loc_8253BA88;
	// addi r10,r21,-2
	ctx.r10.s64 = r21.s64 + -2;
	// clrlwi r9,r31,16
	ctx.r9.u64 = r31.u32 & 0xFFFF;
	// rotlwi r11,r10,1
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r10,r10,r9
	ctx.r10.s32 = ctx.r10.s32 / ctx.r9.s32;
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// andc r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 & ~ctx.r8.u64;
	// twllei r9,0
	// clrlwi r11,r7,16
	r11.u64 = ctx.r7.u32 & 0xFFFF;
	// twlgei r6,-1
loc_8253BA88:
	// lhz r10,14(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 14);
	// addi r30,r27,8
	r30.s64 = r27.s64 + 8;
	// clrlwi r26,r11,16
	r26.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8253bac0
	if (!cr6.eq) goto loc_8253BAC0;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// sth r26,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r26.u16);
	// beq cr6,0x8253bab8
	if (cr6.eq) goto loc_8253BAB8;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825048c0
	ctx.lr = 0x8253BAB4;
	sub_825048C0(ctx, base);
	// b 0x8253babc
	goto loc_8253BABC;
loc_8253BAB8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8253BABC:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_8253BAC0:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// sth r26,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r26.u16);
	// beq cr6,0x8253bb64
	if (cr6.eq) goto loc_8253BB64;
	// li r31,0
	r31.s64 = 0;
loc_8253BAD0:
	// lhz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// mullw r11,r31,r10
	r11.s64 = int64_t(r31.s32) * int64_t(ctx.r10.s32);
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// subf r9,r11,r21
	ctx.r9.s64 = r21.s64 - r11.s64;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// mr r28,r11
	r28.u64 = r11.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// blt cr6,0x8253bb00
	if (cr6.lt) goto loc_8253BB00;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
loc_8253BB00:
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x8253BB08;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8253bb18
	if (cr6.eq) goto loc_8253BB18;
	// bl 0x8253d920
	ctx.lr = 0x8253BB14;
	sub_8253D920(ctx, base);
	// b 0x8253bb1c
	goto loc_8253BB1C;
loc_8253BB18:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8253BB1C:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r9,r31,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r28,4,0,27
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// clrlwi r7,r29,16
	ctx.r7.u64 = r29.u32 & 0xFFFF;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// stwx r3,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r3.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// lwzx r3,r3,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r9.u32);
	// bl 0x8253d270
	ctx.lr = 0x8253BB50;
	sub_8253D270(ctx, base);
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplw cr6,r11,r26
	cr6.compare<uint32_t>(r11.u32, r26.u32, xer);
	// blt cr6,0x8253bad0
	if (cr6.lt) goto loc_8253BAD0;
loc_8253BB64:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8253BB6C"))) PPC_WEAK_FUNC(sub_8253BB6C);
PPC_FUNC_IMPL(__imp__sub_8253BB6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253BB70"))) PPC_WEAK_FUNC(sub_8253BB70);
PPC_FUNC_IMPL(__imp__sub_8253BB70) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x8253BB78;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r22,r7
	r22.u64 = ctx.r7.u64;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// bl 0x8253b3f0
	ctx.lr = 0x8253BB98;
	sub_8253B3F0(ctx, base);
	// li r11,2
	r11.s64 = 2;
	// stb r25,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r25.u8);
	// sth r24,2(r26)
	PPC_STORE_U16(r26.u32 + 2, r24.u16);
	// stb r11,1(r26)
	PPC_STORE_U8(r26.u32 + 1, r11.u8);
	// sth r31,4(r26)
	PPC_STORE_U16(r26.u32 + 4, r31.u16);
	// lhz r21,4(r23)
	r21.u64 = PPC_LOAD_U16(r23.u32 + 4);
	// cmplwi cr6,r21,1
	cr6.compare<uint32_t>(r21.u32, 1, xer);
	// ble cr6,0x8253bbe4
	if (!cr6.gt) goto loc_8253BBE4;
	// addi r10,r21,-2
	ctx.r10.s64 = r21.s64 + -2;
	// clrlwi r9,r31,16
	ctx.r9.u64 = r31.u32 & 0xFFFF;
	// rotlwi r11,r10,1
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r10,r10,r9
	ctx.r10.s32 = ctx.r10.s32 / ctx.r9.s32;
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// andc r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 & ~ctx.r8.u64;
	// twllei r9,0
	// clrlwi r11,r7,16
	r11.u64 = ctx.r7.u32 & 0xFFFF;
	// twlgei r6,-1
	// b 0x8253bbe8
	goto loc_8253BBE8;
loc_8253BBE4:
	// li r11,1
	r11.s64 = 1;
loc_8253BBE8:
	// lhz r10,14(r26)
	ctx.r10.u64 = PPC_LOAD_U16(r26.u32 + 14);
	// addi r30,r26,8
	r30.s64 = r26.s64 + 8;
	// clrlwi r27,r11,16
	r27.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8253bc20
	if (!cr6.eq) goto loc_8253BC20;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// sth r27,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r27.u16);
	// beq cr6,0x8253bc18
	if (cr6.eq) goto loc_8253BC18;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825048c0
	ctx.lr = 0x8253BC14;
	sub_825048C0(ctx, base);
	// b 0x8253bc1c
	goto loc_8253BC1C;
loc_8253BC18:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8253BC1C:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_8253BC20:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// sth r27,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r27.u16);
	// beq cr6,0x8253bcc4
	if (cr6.eq) goto loc_8253BCC4;
	// li r31,0
	r31.s64 = 0;
loc_8253BC30:
	// lhz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// mullw r11,r31,r10
	r11.s64 = int64_t(r31.s32) * int64_t(ctx.r10.s32);
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// subf r9,r11,r21
	ctx.r9.s64 = r21.s64 - r11.s64;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// mr r28,r11
	r28.u64 = r11.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// blt cr6,0x8253bc60
	if (cr6.lt) goto loc_8253BC60;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
loc_8253BC60:
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x8253BC68;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8253bc78
	if (cr6.eq) goto loc_8253BC78;
	// bl 0x8253d920
	ctx.lr = 0x8253BC74;
	sub_8253D920(ctx, base);
	// b 0x8253bc7c
	goto loc_8253BC7C;
loc_8253BC78:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8253BC7C:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r9,r31,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r28,2,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// clrlwi r7,r29,16
	ctx.r7.u64 = r29.u32 & 0xFFFF;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// stwx r3,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r3.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r6,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// lwz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8253caa8
	ctx.lr = 0x8253BCB0;
	sub_8253CAA8(ctx, base);
	// addi r5,r31,1
	ctx.r5.s64 = r31.s64 + 1;
	// clrlwi r11,r5,16
	r11.u64 = ctx.r5.u32 & 0xFFFF;
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// blt cr6,0x8253bc30
	if (cr6.lt) goto loc_8253BC30;
loc_8253BCC4:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8253BCCC"))) PPC_WEAK_FUNC(sub_8253BCCC);
PPC_FUNC_IMPL(__imp__sub_8253BCCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253BCD0"))) PPC_WEAK_FUNC(sub_8253BCD0);
PPC_FUNC_IMPL(__imp__sub_8253BCD0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x8253BCD8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r22,r7
	r22.u64 = ctx.r7.u64;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// bl 0x8253b3f0
	ctx.lr = 0x8253BCF8;
	sub_8253B3F0(ctx, base);
	// li r11,3
	r11.s64 = 3;
	// stb r25,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r25.u8);
	// sth r24,2(r26)
	PPC_STORE_U16(r26.u32 + 2, r24.u16);
	// stb r11,1(r26)
	PPC_STORE_U8(r26.u32 + 1, r11.u8);
	// sth r31,4(r26)
	PPC_STORE_U16(r26.u32 + 4, r31.u16);
	// lhz r21,4(r23)
	r21.u64 = PPC_LOAD_U16(r23.u32 + 4);
	// cmplwi cr6,r21,1
	cr6.compare<uint32_t>(r21.u32, 1, xer);
	// ble cr6,0x8253bd44
	if (!cr6.gt) goto loc_8253BD44;
	// addi r10,r21,-2
	ctx.r10.s64 = r21.s64 + -2;
	// clrlwi r9,r31,16
	ctx.r9.u64 = r31.u32 & 0xFFFF;
	// rotlwi r11,r10,1
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r10,r10,r9
	ctx.r10.s32 = ctx.r10.s32 / ctx.r9.s32;
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// andc r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 & ~ctx.r8.u64;
	// twllei r9,0
	// clrlwi r11,r7,16
	r11.u64 = ctx.r7.u32 & 0xFFFF;
	// twlgei r6,-1
	// b 0x8253bd48
	goto loc_8253BD48;
loc_8253BD44:
	// li r11,1
	r11.s64 = 1;
loc_8253BD48:
	// lhz r10,14(r26)
	ctx.r10.u64 = PPC_LOAD_U16(r26.u32 + 14);
	// addi r30,r26,8
	r30.s64 = r26.s64 + 8;
	// clrlwi r27,r11,16
	r27.u64 = r11.u32 & 0xFFFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8253bd80
	if (!cr6.eq) goto loc_8253BD80;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// sth r27,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r27.u16);
	// beq cr6,0x8253bd78
	if (cr6.eq) goto loc_8253BD78;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825048c0
	ctx.lr = 0x8253BD74;
	sub_825048C0(ctx, base);
	// b 0x8253bd7c
	goto loc_8253BD7C;
loc_8253BD78:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8253BD7C:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_8253BD80:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// sth r27,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r27.u16);
	// beq cr6,0x8253be24
	if (cr6.eq) goto loc_8253BE24;
	// li r31,0
	r31.s64 = 0;
loc_8253BD90:
	// lhz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// mullw r11,r31,r10
	r11.s64 = int64_t(r31.s32) * int64_t(ctx.r10.s32);
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// subf r9,r11,r21
	ctx.r9.s64 = r21.s64 - r11.s64;
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// mr r28,r11
	r28.u64 = r11.u64;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// blt cr6,0x8253bdc0
	if (cr6.lt) goto loc_8253BDC0;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
loc_8253BDC0:
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x8253BDC8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8253bdd8
	if (cr6.eq) goto loc_8253BDD8;
	// bl 0x8253d920
	ctx.lr = 0x8253BDD4;
	sub_8253D920(ctx, base);
	// b 0x8253bddc
	goto loc_8253BDDC;
loc_8253BDD8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8253BDDC:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r9,r31,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r28,2,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// clrlwi r7,r29,16
	ctx.r7.u64 = r29.u32 & 0xFFFF;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// stwx r3,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r3.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r6,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// lwz r10,0(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8253cb90
	ctx.lr = 0x8253BE10;
	sub_8253CB90(ctx, base);
	// addi r5,r31,1
	ctx.r5.s64 = r31.s64 + 1;
	// clrlwi r11,r5,16
	r11.u64 = ctx.r5.u32 & 0xFFFF;
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// blt cr6,0x8253bd90
	if (cr6.lt) goto loc_8253BD90;
loc_8253BE24:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8253BE2C"))) PPC_WEAK_FUNC(sub_8253BE2C);
PPC_FUNC_IMPL(__imp__sub_8253BE2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253BE30"))) PPC_WEAK_FUNC(sub_8253BE30);
PPC_FUNC_IMPL(__imp__sub_8253BE30) {
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
	ctx.lr = 0x8253BE38;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// addi r29,r3,8
	r29.s64 = ctx.r3.s64 + 8;
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// lbz r10,1(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1);
	// stb r10,1(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1, ctx.r10.u8);
	// lhz r9,2(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// sth r9,2(r3)
	PPC_STORE_U16(ctx.r3.u32 + 2, ctx.r9.u16);
	// lhz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// sth r8,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r8.u16);
	// lhz r7,6(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// sth r7,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, ctx.r7.u16);
	// lhz r6,14(r3)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r3.u32 + 14);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// lhz r30,12(r31)
	r30.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// bne cr6,0x8253bea4
	if (!cr6.eq) goto loc_8253BEA4;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r30.u16);
	// beq cr6,0x8253be9c
	if (cr6.eq) goto loc_8253BE9C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825048c0
	ctx.lr = 0x8253BE98;
	sub_825048C0(ctx, base);
	// b 0x8253bea0
	goto loc_8253BEA0;
loc_8253BE9C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8253BEA0:
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
loc_8253BEA4:
	// sth r30,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r30.u16);
	// li r27,0
	r27.s64 = 0;
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8253bf00
	if (cr6.eq) goto loc_8253BF00;
	// clrlwi r26,r28,24
	r26.u64 = r28.u32 & 0xFF;
	// li r30,0
	r30.s64 = 0;
loc_8253BEC0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8253bee0
	if (cr6.eq) goto loc_8253BEE0;
	// lwz r28,0(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x8253d9b0
	ctx.lr = 0x8253BED8;
	sub_8253D9B0(ctx, base);
	// stwx r3,r28,r30
	PPC_STORE_U32(r28.u32 + r30.u32, ctx.r3.u32);
	// b 0x8253beec
	goto loc_8253BEEC;
loc_8253BEE0:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r9,r30,r11
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// stwx r9,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, ctx.r9.u32);
loc_8253BEEC:
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// blt cr6,0x8253bec0
	if (cr6.lt) goto loc_8253BEC0;
loc_8253BF00:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8253BF08"))) PPC_WEAK_FUNC(sub_8253BF08);
PPC_FUNC_IMPL(__imp__sub_8253BF08) {
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
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// sth r11,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r11.u16);
	// sth r11,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r11.u16);
	// bl 0x8253be30
	ctx.lr = 0x8253BF34;
	sub_8253BE30(ctx, base);
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

__attribute__((alias("__imp__sub_8253BF4C"))) PPC_WEAK_FUNC(sub_8253BF4C);
PPC_FUNC_IMPL(__imp__sub_8253BF4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253BF50"))) PPC_WEAK_FUNC(sub_8253BF50);
PPC_FUNC_IMPL(__imp__sub_8253BF50) {
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
	ctx.lr = 0x8253BF58;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,16
	ctx.r3.s64 = 16;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x82130528
	ctx.lr = 0x8253BF6C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8253bfb0
	if (cr6.eq) goto loc_8253BFB0;
	// li r11,0
	r11.s64 = 0;
	// li r10,255
	ctx.r10.s64 = 255;
	// li r9,15
	ctx.r9.s64 = 15;
	// sth r11,6(r3)
	PPC_STORE_U16(ctx.r3.u32 + 6, r11.u16);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stb r10,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r10.u8);
	// li r7,127
	ctx.r7.s64 = 127;
	// stb r9,1(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1, ctx.r9.u8);
	// sth r8,2(r3)
	PPC_STORE_U16(ctx.r3.u32 + 2, ctx.r8.u16);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// sth r7,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r7.u16);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
	// sth r11,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r11.u16);
	// b 0x8253bfb4
	goto loc_8253BFB4;
loc_8253BFB0:
	// li r31,0
	r31.s64 = 0;
loc_8253BFB4:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8253be30
	ctx.lr = 0x8253BFC4;
	sub_8253BE30(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8253BFD0"))) PPC_WEAK_FUNC(sub_8253BFD0);
PPC_FUNC_IMPL(__imp__sub_8253BFD0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8253BFD8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r29,r28,8
	r29.s64 = r28.s64 + 8;
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
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
	// beq cr6,0x8253c018
	if (cr6.eq) goto loc_8253C018;
	// bl 0x821be710
	ctx.lr = 0x8253C014;
	sub_821BE710(ctx, base);
	// b 0x8253c01c
	goto loc_8253C01C;
loc_8253C018:
	// bl 0x821be7e8
	ctx.lr = 0x8253C01C;
	sub_821BE7E8(ctx, base);
loc_8253C01C:
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// addi r30,r28,4
	r30.s64 = r28.s64 + 4;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
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
	// beq cr6,0x8253c050
	if (cr6.eq) goto loc_8253C050;
	// bl 0x821be710
	ctx.lr = 0x8253C04C;
	sub_821BE710(ctx, base);
	// b 0x8253c054
	goto loc_8253C054;
loc_8253C050:
	// bl 0x821be7e8
	ctx.lr = 0x8253C054;
	sub_821BE7E8(ctx, base);
loc_8253C054:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mullw r9,r10,r11
	ctx.r9.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// clrlwi r8,r9,27
	ctx.r8.u64 = ctx.r9.u32 & 0x1F;
	// rlwinm r29,r9,27,5,31
	r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8253c074
	if (cr6.eq) goto loc_8253C074;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
loc_8253C074:
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
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
	// beq cr6,0x8253c0b0
	if (cr6.eq) goto loc_8253C0B0;
	// lis r11,16383
	r11.s64 = 1073676288;
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// ble cr6,0x8253c0a8
	if (!cr6.gt) goto loc_8253C0A8;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8253C0A8:
	// bl 0x82130528
	ctx.lr = 0x8253C0AC;
	sub_82130528(ctx, base);
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
loc_8253C0B0:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8253c100
	if (cr6.eq) goto loc_8253C100;
	// li r30,0
	r30.s64 = 0;
loc_8253C0BC:
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r4,r30,r11
	ctx.r4.u64 = r30.u64 + r11.u64;
	// subfic r8,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r8.s64 = 0 - ctx.r9.s64;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8253c0f0
	if (cr6.eq) goto loc_8253C0F0;
	// bl 0x821be710
	ctx.lr = 0x8253C0EC;
	sub_821BE710(ctx, base);
	// b 0x8253c0f4
	goto loc_8253C0F4;
loc_8253C0F0:
	// bl 0x821be7e8
	ctx.lr = 0x8253C0F4;
	sub_821BE7E8(ctx, base);
loc_8253C0F4:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8253c0bc
	if (!cr0.eq) goto loc_8253C0BC;
loc_8253C100:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8253C108"))) PPC_WEAK_FUNC(sub_8253C108);
PPC_FUNC_IMPL(__imp__sub_8253C108) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8253C110;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r30,r28,4
	r30.s64 = r28.s64 + 4;
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
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
	// beq cr6,0x8253c150
	if (cr6.eq) goto loc_8253C150;
	// bl 0x821be710
	ctx.lr = 0x8253C14C;
	sub_821BE710(ctx, base);
	// b 0x8253c154
	goto loc_8253C154;
loc_8253C150:
	// bl 0x821be7e8
	ctx.lr = 0x8253C154;
	sub_821BE7E8(ctx, base);
loc_8253C154:
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// addi r4,r28,8
	ctx.r4.s64 = r28.s64 + 8;
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
	// beq cr6,0x8253c184
	if (cr6.eq) goto loc_8253C184;
	// bl 0x821be250
	ctx.lr = 0x8253C180;
	sub_821BE250(ctx, base);
	// b 0x8253c188
	goto loc_8253C188;
loc_8253C184:
	// bl 0x821be3d8
	ctx.lr = 0x8253C188;
	sub_821BE3D8(ctx, base);
loc_8253C188:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// clrlwi r9,r11,27
	ctx.r9.u64 = r11.u32 & 0x1F;
	// clrlwi r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// subfic r6,r8,0
	xer.ca = ctx.r8.u32 <= 0;
	ctx.r6.s64 = 0 - ctx.r8.s64;
	// rlwinm r5,r7,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// subfe r4,r6,r6
	temp.u8 = (~ctx.r6.u32 + ctx.r6.u32 < ~ctx.r6.u32) | (~ctx.r6.u32 + ctx.r6.u32 + xer.ca < xer.ca);
	ctx.r4.u64 = ~ctx.r6.u64 + ctx.r6.u64 + xer.ca;
	xer.ca = temp.u8;
	// xori r10,r5,1
	ctx.r10.u64 = ctx.r5.u64 ^ 1;
	// rlwinm r11,r11,27,5,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r3,r4,31
	ctx.r3.u64 = ctx.r4.u32 & 0x1;
	// add r29,r10,r11
	r29.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8253c1e0
	if (cr6.eq) goto loc_8253C1E0;
	// lis r11,16383
	r11.s64 = 1073676288;
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// ble cr6,0x8253c1d8
	if (!cr6.gt) goto loc_8253C1D8;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8253C1D8:
	// bl 0x82130528
	ctx.lr = 0x8253C1DC;
	sub_82130528(ctx, base);
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
loc_8253C1E0:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8253c230
	if (cr6.eq) goto loc_8253C230;
	// li r30,0
	r30.s64 = 0;
loc_8253C1EC:
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r4,r30,r11
	ctx.r4.u64 = r30.u64 + r11.u64;
	// subfic r8,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r8.s64 = 0 - ctx.r9.s64;
	// subfe r7,r8,r8
	temp.u8 = (~ctx.r8.u32 + ctx.r8.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r8.u32 + xer.ca < xer.ca);
	ctx.r7.u64 = ~ctx.r8.u64 + ctx.r8.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r6,r7,31
	ctx.r6.u64 = ctx.r7.u32 & 0x1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8253c220
	if (cr6.eq) goto loc_8253C220;
	// bl 0x821be710
	ctx.lr = 0x8253C21C;
	sub_821BE710(ctx, base);
	// b 0x8253c224
	goto loc_8253C224;
loc_8253C220:
	// bl 0x821be7e8
	ctx.lr = 0x8253C224;
	sub_821BE7E8(ctx, base);
loc_8253C224:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8253c1ec
	if (!cr0.eq) goto loc_8253C1EC;
loc_8253C230:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8253C238"))) PPC_WEAK_FUNC(sub_8253C238);
PPC_FUNC_IMPL(__imp__sub_8253C238) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// cmplwi cr6,r7,128
	cr6.compare<uint32_t>(ctx.r7.u32, 128, xer);
	// bge cr6,0x8253c258
	if (!cr6.lt) goto loc_8253C258;
	// lwz r11,-32556(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -32556);
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// blr 
	return;
loc_8253C258:
	// addi r11,r11,-32556
	r11.s64 = r11.s64 + -32556;
	// li r10,14
	ctx.r10.s64 = 14;
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmpwi cr6,r9,14
	cr6.compare<int32_t>(ctx.r9.s32, 14, xer);
	// ble cr6,0x8253c2a0
	if (!cr6.gt) goto loc_8253C2A0;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r8,56
	r11.s64 = ctx.r8.s64 + 56;
loc_8253C274:
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8253c290
	if (cr6.eq) goto loc_8253C290;
	// rotlwi r6,r6,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// lbz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + 0);
	// cmplw cr6,r5,r7
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r7.u32, xer);
	// beq cr6,0x8253c2a8
	if (cr6.eq) goto loc_8253C2A8;
loc_8253C290:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x8253c274
	if (cr6.lt) goto loc_8253C274;
loc_8253C2A0:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8253C2A8:
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r8
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253C2B4"))) PPC_WEAK_FUNC(sub_8253C2B4);
PPC_FUNC_IMPL(__imp__sub_8253C2B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253C2B8"))) PPC_WEAK_FUNC(sub_8253C2B8);
PPC_FUNC_IMPL(__imp__sub_8253C2B8) {
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
	// bl 0x8253c238
	ctx.lr = 0x8253C2C8;
	sub_8253C238(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8253C2D4;
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

__attribute__((alias("__imp__sub_8253C2E4"))) PPC_WEAK_FUNC(sub_8253C2E4);
PPC_FUNC_IMPL(__imp__sub_8253C2E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253C2E8"))) PPC_WEAK_FUNC(sub_8253C2E8);
PPC_FUNC_IMPL(__imp__sub_8253C2E8) {
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
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,128
	cr6.compare<uint32_t>(r11.u32, 128, xer);
	// lis r11,-32114
	r11.s64 = -2104623104;
	// bge cr6,0x8253c378
	if (!cr6.lt) goto loc_8253C378;
	// addi r31,r11,-32556
	r31.s64 = r11.s64 + -32556;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8253c364
	if (!cr6.eq) goto loc_8253C364;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8253c340
	if (!cr6.eq) goto loc_8253C340;
	// li r11,14
	r11.s64 = 14;
	// li r3,56
	ctx.r3.s64 = 56;
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// bl 0x82130528
	ctx.lr = 0x8253C33C;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_8253C340:
	// li r10,14
	ctx.r10.s64 = 14;
	// li r9,0
	ctx.r9.s64 = 0;
	// sth r10,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r10.u16);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8253C350:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r9,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r11,56
	cr6.compare<int32_t>(r11.s32, 56, xer);
	// blt cr6,0x8253c350
	if (cr6.lt) goto loc_8253C350;
loc_8253C364:
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// stwx r30,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r30.u32);
	// b 0x8253c388
	goto loc_8253C388;
loc_8253C378:
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,-32556
	ctx.r3.s64 = r11.s64 + -32556;
	// bl 0x8262e420
	ctx.lr = 0x8253C384;
	sub_8262E420(ctx, base);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
loc_8253C388:
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

__attribute__((alias("__imp__sub_8253C3A0"))) PPC_WEAK_FUNC(sub_8253C3A0);
PPC_FUNC_IMPL(__imp__sub_8253C3A0) {
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
	// lis r31,-32114
	r31.s64 = -2104623104;
	// addi r30,r31,-32556
	r30.s64 = r31.s64 + -32556;
	// lwz r3,-32556(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -32556);
	// bl 0x82130588
	ctx.lr = 0x8253C3C4;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,-32556(r31)
	PPC_STORE_U32(r31.u32 + -32556, r11.u32);
	// sth r10,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r10.u16);
	// sth r9,6(r30)
	PPC_STORE_U16(r30.u32 + 6, ctx.r9.u16);
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

__attribute__((alias("__imp__sub_8253C3F4"))) PPC_WEAK_FUNC(sub_8253C3F4);
PPC_FUNC_IMPL(__imp__sub_8253C3F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253C3F8"))) PPC_WEAK_FUNC(sub_8253C3F8);
PPC_FUNC_IMPL(__imp__sub_8253C3F8) {
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
	// lbz r3,5(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// bl 0x8253c238
	ctx.lr = 0x8253C414;
	sub_8253C238(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253C428;
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

__attribute__((alias("__imp__sub_8253C43C"))) PPC_WEAK_FUNC(sub_8253C43C);
PPC_FUNC_IMPL(__imp__sub_8253C43C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253C440"))) PPC_WEAK_FUNC(sub_8253C440);
PPC_FUNC_IMPL(__imp__sub_8253C440) {
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
	// lis r11,-32127
	r11.s64 = -2105475072;
	// addi r3,r11,1136
	ctx.r3.s64 = r11.s64 + 1136;
	// bl 0x8253c2e8
	ctx.lr = 0x8253C458;
	sub_8253C2E8(ctx, base);
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// addi r3,r10,1148
	ctx.r3.s64 = ctx.r10.s64 + 1148;
	// bl 0x8253c2e8
	ctx.lr = 0x8253C464;
	sub_8253C2E8(ctx, base);
	// lis r9,-32127
	ctx.r9.s64 = -2105475072;
	// addi r3,r9,1160
	ctx.r3.s64 = ctx.r9.s64 + 1160;
	// bl 0x8253c2e8
	ctx.lr = 0x8253C470;
	sub_8253C2E8(ctx, base);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r3,r8,1196
	ctx.r3.s64 = ctx.r8.s64 + 1196;
	// bl 0x8253c2e8
	ctx.lr = 0x8253C47C;
	sub_8253C2E8(ctx, base);
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// addi r3,r7,1756
	ctx.r3.s64 = ctx.r7.s64 + 1756;
	// bl 0x8253c2e8
	ctx.lr = 0x8253C488;
	sub_8253C2E8(ctx, base);
	// lis r6,-32127
	ctx.r6.s64 = -2105475072;
	// addi r3,r6,1912
	ctx.r3.s64 = ctx.r6.s64 + 1912;
	// bl 0x8253c2e8
	ctx.lr = 0x8253C494;
	sub_8253C2E8(ctx, base);
	// lis r5,-32127
	ctx.r5.s64 = -2105475072;
	// addi r3,r5,1172
	ctx.r3.s64 = ctx.r5.s64 + 1172;
	// bl 0x8253c2e8
	ctx.lr = 0x8253C4A0;
	sub_8253C2E8(ctx, base);
	// lis r4,-32127
	ctx.r4.s64 = -2105475072;
	// addi r3,r4,1184
	ctx.r3.s64 = ctx.r4.s64 + 1184;
	// bl 0x8253c2e8
	ctx.lr = 0x8253C4AC;
	sub_8253C2E8(ctx, base);
	// lis r3,-32127
	ctx.r3.s64 = -2105475072;
	// addi r3,r3,1208
	ctx.r3.s64 = ctx.r3.s64 + 1208;
	// bl 0x8253c2e8
	ctx.lr = 0x8253C4B8;
	sub_8253C2E8(ctx, base);
	// lis r11,-32127
	r11.s64 = -2105475072;
	// addi r3,r11,1560
	ctx.r3.s64 = r11.s64 + 1560;
	// bl 0x8253c2e8
	ctx.lr = 0x8253C4C4;
	sub_8253C2E8(ctx, base);
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// addi r3,r10,1220
	ctx.r3.s64 = ctx.r10.s64 + 1220;
	// bl 0x8253c2e8
	ctx.lr = 0x8253C4D0;
	sub_8253C2E8(ctx, base);
	// lis r9,-32127
	ctx.r9.s64 = -2105475072;
	// addi r3,r9,1976
	ctx.r3.s64 = ctx.r9.s64 + 1976;
	// bl 0x8253c2e8
	ctx.lr = 0x8253C4DC;
	sub_8253C2E8(ctx, base);
	// lis r8,-32127
	ctx.r8.s64 = -2105475072;
	// addi r3,r8,1232
	ctx.r3.s64 = ctx.r8.s64 + 1232;
	// bl 0x8253c2e8
	ctx.lr = 0x8253C4E8;
	sub_8253C2E8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253C4F8"))) PPC_WEAK_FUNC(sub_8253C4F8);
PPC_FUNC_IMPL(__imp__sub_8253C4F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// clrldi r11,r4,32
	r11.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// fadds f1,f12,f1
	ctx.f1.f64 = double(float(ctx.f12.f64 + ctx.f1.f64));
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8253C530;
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

__attribute__((alias("__imp__sub_8253C540"))) PPC_WEAK_FUNC(sub_8253C540);
PPC_FUNC_IMPL(__imp__sub_8253C540) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// clrldi r11,r4,32
	r11.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// fadds f1,f12,f1
	ctx.f1.f64 = double(float(ctx.f12.f64 + ctx.f1.f64));
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8253C578;
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

__attribute__((alias("__imp__sub_8253C588"))) PPC_WEAK_FUNC(sub_8253C588);
PPC_FUNC_IMPL(__imp__sub_8253C588) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// clrldi r11,r4,32
	r11.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// fadds f1,f12,f1
	ctx.f1.f64 = double(float(ctx.f12.f64 + ctx.f1.f64));
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8253C5C0;
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

__attribute__((alias("__imp__sub_8253C5D0"))) PPC_WEAK_FUNC(sub_8253C5D0);
PPC_FUNC_IMPL(__imp__sub_8253C5D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// clrldi r11,r4,32
	r11.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// fadds f1,f12,f1
	ctx.f1.f64 = double(float(ctx.f12.f64 + ctx.f1.f64));
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8253C608;
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

__attribute__((alias("__imp__sub_8253C618"))) PPC_WEAK_FUNC(sub_8253C618);
PPC_FUNC_IMPL(__imp__sub_8253C618) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253C638;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
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

__attribute__((alias("__imp__sub_8253C64C"))) PPC_WEAK_FUNC(sub_8253C64C);
PPC_FUNC_IMPL(__imp__sub_8253C64C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253C650"))) PPC_WEAK_FUNC(sub_8253C650);
PPC_FUNC_IMPL(__imp__sub_8253C650) {
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
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-24636
	ctx.r9.s64 = r11.s64 + -24636;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8253c684
	if (cr6.eq) goto loc_8253C684;
	// bl 0x82130588
	ctx.lr = 0x8253C680;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8253C684:
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

__attribute__((alias("__imp__sub_8253C698"))) PPC_WEAK_FUNC(sub_8253C698);
PPC_FUNC_IMPL(__imp__sub_8253C698) {
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
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x8253C6A0;
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// li r11,1
	r11.s64 = 1;
	// li r29,0
	r29.s64 = 0;
	// li r10,4
	ctx.r10.s64 = 4;
	// stb r11,83(r1)
	PPC_STORE_U8(ctx.r1.u32 + 83, r11.u8);
	// li r8,10
	ctx.r8.s64 = 10;
	// stb r29,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, r29.u8);
	// li r7,6
	ctx.r7.s64 = 6;
	// stb r10,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// stb r8,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r8.u8);
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// stb r7,82(r1)
	PPC_STORE_U8(ctx.r1.u32 + 82, ctx.r7.u8);
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// stb r11,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r11.u8);
	// mr r30,r29
	r30.u64 = r29.u64;
	// stb r11,86(r1)
	PPC_STORE_U8(ctx.r1.u32 + 86, r11.u8);
	// clrlwi r25,r9,24
	r25.u64 = ctx.r9.u32 & 0xFF;
	// stb r11,87(r1)
	PPC_STORE_U8(ctx.r1.u32 + 87, r11.u8);
loc_8253C6F8:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lbzx r31,r29,r11
	r31.u64 = PPC_LOAD_U8(r29.u32 + r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8253c238
	ctx.lr = 0x8253C708;
	sub_8253C238(ctx, base);
	// lbz r10,1(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// cmplw cr6,r10,r25
	cr6.compare<uint32_t>(ctx.r10.u32, r25.u32, xer);
	// bgt cr6,0x8253c7e8
	if (cr6.gt) goto loc_8253C7E8;
	// lbz r11,2(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// clrlwi r10,r24,24
	ctx.r10.u64 = r24.u32 & 0xFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8253c7e8
	if (cr6.gt) goto loc_8253C7E8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8253c2b8
	ctx.lr = 0x8253C72C;
	sub_8253C2B8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253C750;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8253c7b8
	if (cr6.eq) goto loc_8253C7B8;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8253c7b0
	if (cr6.eq) goto loc_8253C7B0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253C778;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8253C790;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r3,r23
	cr6.compare<int32_t>(ctx.r3.s32, r23.s32, xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// ble cr6,0x8253c7bc
	if (!cr6.gt) goto loc_8253C7BC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253C7B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8253C7B0:
	// mr r30,r31
	r30.u64 = r31.u64;
	// b 0x8253c7d0
	goto loc_8253C7D0;
loc_8253C7B8:
	// li r4,1
	ctx.r4.s64 = 1;
loc_8253C7BC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253C7D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8253C7D0:
	// addi r11,r1,84
	r11.s64 = ctx.r1.s64 + 84;
	// lbzx r10,r29,r11
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8253c7e8
	if (cr6.eq) goto loc_8253C7E8;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8253c7f4
	if (!cr6.eq) goto loc_8253C7F4;
loc_8253C7E8:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// blt cr6,0x8253c6f8
	if (cr6.lt) goto loc_8253C6F8;
loc_8253C7F4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8253C804"))) PPC_WEAK_FUNC(sub_8253C804);
PPC_FUNC_IMPL(__imp__sub_8253C804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253C808"))) PPC_WEAK_FUNC(sub_8253C808);
PPC_FUNC_IMPL(__imp__sub_8253C808) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8253C810;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
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
	// beq cr6,0x8253c84c
	if (cr6.eq) goto loc_8253C84C;
	// bl 0x821be250
	ctx.lr = 0x8253C848;
	sub_821BE250(ctx, base);
	// b 0x8253c850
	goto loc_8253C850;
loc_8253C84C:
	// bl 0x821be3d8
	ctx.lr = 0x8253C850;
	sub_821BE3D8(ctx, base);
loc_8253C850:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// addi r4,r31,1
	ctx.r4.s64 = r31.s64 + 1;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
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
	// beq cr6,0x8253c880
	if (cr6.eq) goto loc_8253C880;
	// bl 0x821be250
	ctx.lr = 0x8253C87C;
	sub_821BE250(ctx, base);
	// b 0x8253c884
	goto loc_8253C884;
loc_8253C880:
	// bl 0x821be3d8
	ctx.lr = 0x8253C884;
	sub_821BE3D8(ctx, base);
loc_8253C884:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// addi r4,r31,2
	ctx.r4.s64 = r31.s64 + 2;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
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
	// beq cr6,0x8253c8b4
	if (cr6.eq) goto loc_8253C8B4;
	// bl 0x821be6a8
	ctx.lr = 0x8253C8B0;
	sub_821BE6A8(ctx, base);
	// b 0x8253c8b8
	goto loc_8253C8B8;
loc_8253C8B4:
	// bl 0x821be780
	ctx.lr = 0x8253C8B8;
	sub_821BE780(ctx, base);
loc_8253C8B8:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// addi r4,r1,82
	ctx.r4.s64 = ctx.r1.s64 + 82;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// subfic r7,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r9.s64;
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// sth r10,82(r1)
	PPC_STORE_U16(ctx.r1.u32 + 82, ctx.r10.u16);
	// clrlwi r5,r6,31
	ctx.r5.u64 = ctx.r6.u32 & 0x1;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// li r5,1
	ctx.r5.s64 = 1;
	// beq cr6,0x8253c8f0
	if (cr6.eq) goto loc_8253C8F0;
	// bl 0x821be6a8
	ctx.lr = 0x8253C8EC;
	sub_821BE6A8(ctx, base);
	// b 0x8253c8f4
	goto loc_8253C8F4;
loc_8253C8F0:
	// bl 0x821be780
	ctx.lr = 0x8253C8F4;
	sub_821BE780(ctx, base);
loc_8253C8F4:
	// lhz r10,82(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8253c9cc
	if (cr6.eq) goto loc_8253C9CC;
	// addi r29,r31,4
	r29.s64 = r31.s64 + 4;
	// mr r28,r29
	r28.u64 = r29.u64;
loc_8253C90C:
	// lhz r11,0(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 0);
	// li r31,0
	r31.s64 = 0;
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
	// bne cr6,0x8253c938
	if (!cr6.eq) goto loc_8253C938;
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lbz r10,5(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// stb r10,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
loc_8253C938:
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
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8253c960
	if (cr6.eq) goto loc_8253C960;
	// bl 0x821be250
	ctx.lr = 0x8253C95C;
	sub_821BE250(ctx, base);
	// b 0x8253c964
	goto loc_8253C964;
loc_8253C960:
	// bl 0x821be3d8
	ctx.lr = 0x8253C964;
	sub_821BE3D8(ctx, base);
loc_8253C964:
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
	// beq cr6,0x8253c9a0
	if (cr6.eq) goto loc_8253C9A0;
	// lbz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// bl 0x8253c2b8
	ctx.lr = 0x8253C988;
	sub_8253C2B8(ctx, base);
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,16(r29)
	PPC_STORE_U32(r29.u32 + 16, r11.u32);
	// stwx r31,r10,r29
	PPC_STORE_U32(ctx.r10.u32 + r29.u32, r31.u32);
loc_8253C9A0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253C9B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,82(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r27,r8
	cr6.compare<int32_t>(r27.s32, ctx.r8.s32, xer);
	// blt cr6,0x8253c90c
	if (cr6.lt) goto loc_8253C90C;
loc_8253C9CC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8253C9D4"))) PPC_WEAK_FUNC(sub_8253C9D4);
PPC_FUNC_IMPL(__imp__sub_8253C9D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253C9D8"))) PPC_WEAK_FUNC(sub_8253C9D8);
PPC_FUNC_IMPL(__imp__sub_8253C9D8) {
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
	ctx.lr = 0x8253C9E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r29,24
	r29.s64 = 24;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,20(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8253ca2c
	if (!cr6.gt) goto loc_8253CA2C;
	// addi r31,r28,4
	r31.s64 = r28.s64 + 4;
loc_8253CA00:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253CA14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,20(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// add r29,r3,r29
	r29.u64 = ctx.r3.u64 + r29.u64;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// blt cr6,0x8253ca00
	if (cr6.lt) goto loc_8253CA00;
loc_8253CA2C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8253CA38"))) PPC_WEAK_FUNC(sub_8253CA38);
PPC_FUNC_IMPL(__imp__sub_8253CA38) {
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
	ctx.lr = 0x8253CA40;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r30,20(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8253ca98
	if (!cr6.gt) goto loc_8253CA98;
	// addi r31,r28,4
	r31.s64 = r28.s64 + 4;
	// li r29,0
	r29.s64 = 0;
loc_8253CA5C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8253ca7c
	if (cr6.eq) goto loc_8253CA7C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253CA7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8253CA7C:
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x8253ca5c
	if (!cr0.eq) goto loc_8253CA5C;
	// stw r29,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8253CA98:
	// li r11,0
	r11.s64 = 0;
	// stw r11,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8253CAA8"))) PPC_WEAK_FUNC(sub_8253CAA8);
PPC_FUNC_IMPL(__imp__sub_8253CAA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8253CAB0;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// bl 0x8253ca38
	ctx.lr = 0x8253CAD4;
	sub_8253CA38(ctx, base);
	// stb r30,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r30.u8);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// sth r29,2(r31)
	PPC_STORE_U16(r31.u32 + 2, r29.u16);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// li r6,2
	ctx.r6.s64 = 2;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253CAFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// li r6,2
	ctx.r6.s64 = 2;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8253CB20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// clrlwi r25,r3,24
	r25.u64 = ctx.r3.u32 & 0xFF;
	// li r6,2
	ctx.r6.s64 = 2;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8253CB44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// stb r10,1(r31)
	PPC_STORE_U8(r31.u32 + 1, ctx.r10.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r9.u32);
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8253c698
	ctx.lr = 0x8253CB80;
	sub_8253C698(ctx, base);
	// stwx r3,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r3.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8253CB90"))) PPC_WEAK_FUNC(sub_8253CB90);
PPC_FUNC_IMPL(__imp__sub_8253CB90) {
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
	ctx.lr = 0x8253CB98;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// bl 0x8253ca38
	ctx.lr = 0x8253CBB8;
	sub_8253CA38(ctx, base);
	// stb r29,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r29.u8);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// sth r28,2(r30)
	PPC_STORE_U16(r30.u32 + 2, r28.u16);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// li r6,3
	ctx.r6.s64 = 3;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253CBE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// clrlwi r31,r3,24
	r31.u64 = ctx.r3.u32 & 0xFF;
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8253CC04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r28,0
	r28.s64 = 0;
	// li r11,1
	r11.s64 = 1;
	// li r7,3
	ctx.r7.s64 = 3;
	// stb r28,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, r28.u8);
	// li r6,11
	ctx.r6.s64 = 11;
	// stb r11,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r11.u8);
	// li r5,12
	ctx.r5.s64 = 12;
	// stb r7,1(r30)
	PPC_STORE_U8(r30.u32 + 1, ctx.r7.u8);
	// li r4,7
	ctx.r4.s64 = 7;
	// stb r6,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r6.u8);
	// mr r29,r28
	r29.u64 = r28.u64;
	// stb r5,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r5.u8);
	// stb r4,82(r1)
	PPC_STORE_U8(ctx.r1.u32 + 82, ctx.r4.u8);
	// clrlwi r24,r3,24
	r24.u64 = ctx.r3.u32 & 0xFF;
	// stb r11,86(r1)
	PPC_STORE_U8(ctx.r1.u32 + 86, r11.u8);
	// mr r25,r31
	r25.u64 = r31.u64;
loc_8253CC44:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lbzx r31,r28,r11
	r31.u64 = PPC_LOAD_U8(r28.u32 + r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8253c238
	ctx.lr = 0x8253CC54;
	sub_8253C238(ctx, base);
	// lbz r10,1(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// cmplw cr6,r10,r25
	cr6.compare<uint32_t>(ctx.r10.u32, r25.u32, xer);
	// bgt cr6,0x8253cd2c
	if (cr6.gt) goto loc_8253CD2C;
	// lbz r11,2(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// clrlwi r10,r24,24
	ctx.r10.u64 = r24.u32 & 0xFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8253cd2c
	if (cr6.gt) goto loc_8253CD2C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8253c2b8
	ctx.lr = 0x8253CC78;
	sub_8253C2B8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253CC94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8253ccfc
	if (cr6.eq) goto loc_8253CCFC;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8253ccf4
	if (cr6.eq) goto loc_8253CCF4;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253CCBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8253CCD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r23,r3
	cr6.compare<int32_t>(r23.s32, ctx.r3.s32, xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// ble cr6,0x8253cd00
	if (!cr6.gt) goto loc_8253CD00;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253CCF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8253CCF4:
	// mr r29,r31
	r29.u64 = r31.u64;
	// b 0x8253cd14
	goto loc_8253CD14;
loc_8253CCFC:
	// li r4,1
	ctx.r4.s64 = 1;
loc_8253CD00:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253CD14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8253CD14:
	// addi r11,r1,84
	r11.s64 = ctx.r1.s64 + 84;
	// lbzx r10,r28,r11
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8253cd2c
	if (cr6.eq) goto loc_8253CD2C;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8253cd38
	if (!cr6.eq) goto loc_8253CD38;
loc_8253CD2C:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpwi cr6,r28,3
	cr6.compare<int32_t>(r28.s32, 3, xer);
	// blt cr6,0x8253cc44
	if (cr6.lt) goto loc_8253CC44;
loc_8253CD38:
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r10,r30,4
	ctx.r10.s64 = r30.s64 + 4;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8253CD58"))) PPC_WEAK_FUNC(sub_8253CD58);
PPC_FUNC_IMPL(__imp__sub_8253CD58) {
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
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x8253CD74;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8253cd98
	if (cr6.eq) goto loc_8253CD98;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82541ed0
	ctx.lr = 0x8253CD84;
	sub_82541ED0(ctx, base);
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
loc_8253CD98:
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

__attribute__((alias("__imp__sub_8253CDB0"))) PPC_WEAK_FUNC(sub_8253CDB0);
PPC_FUNC_IMPL(__imp__sub_8253CDB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r10,r4,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// li r9,16
	ctx.r9.s64 = 16;
	// stfs f1,36(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 36, temp.u32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r8,r1,36
	ctx.r8.s64 = ctx.r1.s64 + 36;
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v63,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v62,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmaddfp v11,v13,v12,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253CDE8"))) PPC_WEAK_FUNC(sub_8253CDE8);
PPC_FUNC_IMPL(__imp__sub_8253CDE8) {
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
	// addi r10,r11,-24548
	ctx.r10.s64 = r11.s64 + -24548;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r9,14(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8253ce24
	if (cr6.eq) goto loc_8253CE24;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x8253CE24;
	sub_82130588(ctx, base);
loc_8253CE24:
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
	// beq cr6,0x8253ce48
	if (cr6.eq) goto loc_8253CE48;
	// bl 0x82130588
	ctx.lr = 0x8253CE44;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8253CE48:
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

__attribute__((alias("__imp__sub_8253CE60"))) PPC_WEAK_FUNC(sub_8253CE60);
PPC_FUNC_IMPL(__imp__sub_8253CE60) {
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
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x8253CE7C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8253cea0
	if (cr6.eq) goto loc_8253CEA0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x825420d8
	ctx.lr = 0x8253CE8C;
	sub_825420D8(ctx, base);
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
loc_8253CEA0:
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

__attribute__((alias("__imp__sub_8253CEB8"))) PPC_WEAK_FUNC(sub_8253CEB8);
PPC_FUNC_IMPL(__imp__sub_8253CEB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r10,r4,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f0,f1
	ctx.f11.f64 = double(float(f0.f64 - ctx.f1.f64));
	// fmuls f10,f13,f1
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f1.f64));
	// lfs f9,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfd f0,32224(r8)
	f0.u64 = PPC_LOAD_U64(ctx.r8.u32 + 32224);
	// lfd f13,21560(r7)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r7.u32 + 21560);
	// lfs f12,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f8,f9,f11,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f11.f64 + ctx.f10.f64));
	// stfs f8,0(r6)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// lfs f7,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f6,f1
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f1.f64));
	// fmadds f4,f7,f11,f5
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f11.f64 + ctx.f5.f64));
	// stfs f4,4(r6)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// lfs f3,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// lfs f10,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f1
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f1.f64));
	// fmadds f7,f3,f11,f9
	ctx.f7.f64 = double(float(ctx.f3.f64 * ctx.f11.f64 + ctx.f9.f64));
	// stfs f7,8(r6)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r6.u32 + 8, temp.u32);
	// lfs f5,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f5.f64 = double(temp.f32);
	// fmr f2,f4
	ctx.f2.f64 = ctx.f4.f64;
	// lfs f3,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f1,f3,f1
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f1.f64));
	// fmuls f6,f2,f2
	ctx.f6.f64 = double(float(ctx.f2.f64 * ctx.f2.f64));
	// fmr f4,f7
	ctx.f4.f64 = ctx.f7.f64;
	// fmadds f9,f5,f11,f1
	ctx.f9.f64 = double(float(ctx.f5.f64 * ctx.f11.f64 + ctx.f1.f64));
	// stfs f9,12(r6)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r6.u32 + 12, temp.u32);
	// fmadds f10,f8,f8,f6
	ctx.f10.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f6.f64));
	// fmr f7,f9
	ctx.f7.f64 = ctx.f9.f64;
	// fmadds f6,f4,f4,f10
	ctx.f6.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f10.f64));
	// fmadds f5,f9,f9,f6
	ctx.f5.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f6.f64));
	// frsqrte f3,f5
	// fneg f1,f5
	ctx.f1.u64 = ctx.f5.u64 ^ 0x8000000000000000;
	// fmul f11,f3,f3
	ctx.f11.f64 = ctx.f3.f64 * ctx.f3.f64;
	// fmul f10,f3,f0
	ctx.f10.f64 = ctx.f3.f64 * f0.f64;
	// fnmsub f9,f11,f5,f13
	ctx.f9.f64 = -(ctx.f11.f64 * ctx.f5.f64 - ctx.f13.f64);
	// fmadd f6,f9,f10,f3
	ctx.f6.f64 = ctx.f9.f64 * ctx.f10.f64 + ctx.f3.f64;
	// fmul f3,f6,f6
	ctx.f3.f64 = ctx.f6.f64 * ctx.f6.f64;
	// fmul f0,f6,f0
	f0.f64 = ctx.f6.f64 * f0.f64;
	// fnmsub f13,f3,f5,f13
	ctx.f13.f64 = -(ctx.f3.f64 * ctx.f5.f64 - ctx.f13.f64);
	// fmadd f11,f13,f0,f6
	ctx.f11.f64 = ctx.f13.f64 * f0.f64 + ctx.f6.f64;
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fsel f9,f1,f12,f10
	ctx.f9.f64 = ctx.f1.f64 >= 0.0 ? ctx.f12.f64 : ctx.f10.f64;
	// fmuls f5,f4,f9
	ctx.f5.f64 = double(float(ctx.f4.f64 * ctx.f9.f64));
	// stfs f5,8(r6)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r6.u32 + 8, temp.u32);
	// fmuls f8,f8,f9
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f9.f64));
	// stfs f8,0(r6)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// fmuls f6,f2,f9
	ctx.f6.f64 = double(float(ctx.f2.f64 * ctx.f9.f64));
	// stfs f6,4(r6)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// fmuls f4,f7,f9
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f9.f64));
	// stfs f4,12(r6)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r6.u32 + 12, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253CFA8"))) PPC_WEAK_FUNC(sub_8253CFA8);
PPC_FUNC_IMPL(__imp__sub_8253CFA8) {
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
	// addi r10,r11,-24460
	ctx.r10.s64 = r11.s64 + -24460;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r9,14(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8253cfe4
	if (cr6.eq) goto loc_8253CFE4;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x8253CFE4;
	sub_82130588(ctx, base);
loc_8253CFE4:
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
	// beq cr6,0x8253d008
	if (cr6.eq) goto loc_8253D008;
	// bl 0x82130588
	ctx.lr = 0x8253D004;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8253D008:
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

__attribute__((alias("__imp__sub_8253D020"))) PPC_WEAK_FUNC(sub_8253D020);
PPC_FUNC_IMPL(__imp__sub_8253D020) {
	PPC_FUNC_PROLOGUE();
	// b 0x8253ca38
	sub_8253CA38(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8253D024"))) PPC_WEAK_FUNC(sub_8253D024);
PPC_FUNC_IMPL(__imp__sub_8253D024) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253D028"))) PPC_WEAK_FUNC(sub_8253D028);
PPC_FUNC_IMPL(__imp__sub_8253D028) {
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
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x8253D030;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// bl 0x8253ca38
	ctx.lr = 0x8253D054;
	sub_8253CA38(ctx, base);
	// stb r30,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r30.u8);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// sth r28,2(r31)
	PPC_STORE_U16(r31.u32 + 2, r28.u16);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253D07C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8253D0A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// clrlwi r26,r3,24
	r26.u64 = ctx.r3.u32 & 0xFF;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8253D0C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r25,r3,24
	r25.u64 = ctx.r3.u32 & 0xFF;
	// li r3,13
	ctx.r3.s64 = 13;
	// bl 0x8253c238
	ctx.lr = 0x8253D0D0;
	sub_8253C238(ctx, base);
	// lbz r10,1(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// li r28,0
	r28.s64 = 0;
	// mr r27,r26
	r27.u64 = r26.u64;
	// cmplw cr6,r26,r10
	cr6.compare<uint32_t>(r26.u32, ctx.r10.u32, xer);
	// blt cr6,0x8253d17c
	if (cr6.lt) goto loc_8253D17C;
	// lbz r11,2(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x8253d17c
	if (cr6.lt) goto loc_8253D17C;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x8253D0FC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8253d110
	if (cr6.eq) goto loc_8253D110;
	// bl 0x82541538
	ctx.lr = 0x8253D108;
	sub_82541538(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8253d114
	goto loc_8253D114;
loc_8253D110:
	// mr r30,r28
	r30.u64 = r28.u64;
loc_8253D114:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253D134;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8253d164
	if (cr6.eq) goto loc_8253D164;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r10,r31,4
	ctx.r10.s64 = r31.s64 + 4;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_8253D164:
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
	ctx.lr = 0x8253D17C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8253D17C:
	// cmplwi cr6,r27,20
	cr6.compare<uint32_t>(r27.u32, 20, xer);
	// blt cr6,0x8253d1ec
	if (cr6.lt) goto loc_8253D1EC;
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,20
	cr6.compare<uint32_t>(r11.u32, 20, xer);
	// blt cr6,0x8253d1ec
	if (cr6.lt) goto loc_8253D1EC;
	// li r11,16
	r11.s64 = 16;
	// addi r28,r31,4
	r28.s64 = r31.s64 + 4;
	// stb r11,1(r31)
	PPC_STORE_U8(r31.u32 + 1, r11.u8);
	// li r30,3
	r30.s64 = 3;
loc_8253D1A0:
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// li r6,3
	ctx.r6.s64 = 3;
	// stw r10,16(r28)
	PPC_STORE_U32(r28.u32 + 16, ctx.r10.u32);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r27,r11,2,0,29
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8253c698
	ctx.lr = 0x8253D1D0;
	sub_8253C698(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// stwx r3,r27,r28
	PPC_STORE_U32(r27.u32 + r28.u32, ctx.r3.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x8253d1a0
	if (!cr0.eq) goto loc_8253D1A0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_8253D1EC:
	// stb r28,1(r31)
	PPC_STORE_U8(r31.u32 + 1, r28.u8);
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x8253D1F8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8253d228
	if (cr6.eq) goto loc_8253D228;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r9,r11,-24548
	ctx.r9.s64 = r11.s64 + -24548;
	// stb r10,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r10.u8);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r28,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r28.u32);
	// sth r28,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r28.u16);
	// sth r28,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r28.u16);
	// b 0x8253d22c
	goto loc_8253D22C;
loc_8253D228:
	// mr r30,r28
	r30.u64 = r28.u64;
loc_8253D22C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253D24C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r8.u32);
	// stwx r30,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r30.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8253D270"))) PPC_WEAK_FUNC(sub_8253D270);
PPC_FUNC_IMPL(__imp__sub_8253D270) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x8253D278;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// bl 0x8253ca38
	ctx.lr = 0x8253D29C;
	sub_8253CA38(ctx, base);
	// stb r31,0(r27)
	PPC_STORE_U8(r27.u32 + 0, r31.u8);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// sth r29,2(r27)
	PPC_STORE_U16(r27.u32 + 2, r29.u16);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253D2C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8253D2E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// clrlwi r25,r3,24
	r25.u64 = ctx.r3.u32 & 0xFF;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8253D30C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r29,1
	r29.s64 = 1;
	// clrlwi r24,r3,24
	r24.u64 = ctx.r3.u32 & 0xFF;
	// stb r29,1(r27)
	PPC_STORE_U8(r27.u32 + 1, r29.u8);
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x8253c238
	ctx.lr = 0x8253D320;
	sub_8253C238(ctx, base);
	// lbz r10,1(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// li r28,0
	r28.s64 = 0;
	// cmplw cr6,r25,r10
	cr6.compare<uint32_t>(r25.u32, ctx.r10.u32, xer);
	// blt cr6,0x8253d3c8
	if (cr6.lt) goto loc_8253D3C8;
	// lbz r11,2(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// clrlwi r10,r24,24
	ctx.r10.u64 = r24.u32 & 0xFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x8253d3c8
	if (cr6.lt) goto loc_8253D3C8;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x8253D348;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8253d35c
	if (cr6.eq) goto loc_8253D35C;
	// bl 0x825413f0
	ctx.lr = 0x8253D354;
	sub_825413F0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8253d360
	goto loc_8253D360;
loc_8253D35C:
	// mr r31,r28
	r31.u64 = r28.u64;
loc_8253D360:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253D380;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8253d3b0
	if (cr6.eq) goto loc_8253D3B0;
	// lwz r11,20(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// addi r10,r27,4
	ctx.r10.s64 = r27.s64 + 4;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,20(r27)
	PPC_STORE_U32(r27.u32 + 20, r11.u32);
	// stwx r31,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r31.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_8253D3B0:
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
	ctx.lr = 0x8253D3C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8253D3C8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	f0.f64 = double(temp.f32);
	// lfs f10,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f10.f64 = double(temp.f32);
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bge cr6,0x8253d408
	if (!cr6.lt) goto loc_8253D408;
	// lfs f13,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f0
	ctx.f12.u64 = f0.u64 ^ 0x8000000000000000;
	// lfs f11,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fneg f9,f13
	ctx.f9.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// lfs f8,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// fneg f7,f11
	ctx.f7.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// fneg f6,f8
	ctx.f6.u64 = ctx.f8.u64 ^ 0x8000000000000000;
	// stfs f9,0(r30)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// stfs f7,4(r30)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// stfs f6,8(r30)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// stfs f12,12(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 12, temp.u32);
loc_8253D408:
	// addi r11,r26,-1
	r11.s64 = r26.s64 + -1;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// blt cr6,0x8253d660
	if (cr6.lt) goto loc_8253D660;
	// addi r10,r26,-5
	ctx.r10.s64 = r26.s64 + -5;
	// addi r11,r30,44
	r11.s64 = r30.s64 + 44;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
loc_8253D434:
	// lfs f0,-32(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -32);
	f0.f64 = double(temp.f32);
	// lfs f13,-16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,-44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -44);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,-28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28);
	f0.f64 = double(temp.f32);
	// lfs f9,-40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -40);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,-24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -24);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -36);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -20);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f5,f11,f0,f12
	ctx.f5.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f4,f9,f8,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f3,f6,f7,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fcmpu cr6,f3,f10
	cr6.compare(ctx.f3.f64, ctx.f10.f64);
	// bge cr6,0x8253d498
	if (!cr6.lt) goto loc_8253D498;
	// fneg f0,f0
	f0.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f0,-28(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -28, temp.u32);
	// lfs f13,-24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -24);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f13
	ctx.f12.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f12,-24(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + -24, temp.u32);
	// lfs f11,-20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -20);
	ctx.f11.f64 = double(temp.f32);
	// fneg f9,f11
	ctx.f9.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// stfs f9,-20(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + -20, temp.u32);
	// lfs f8,-16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -16);
	ctx.f8.f64 = double(temp.f32);
	// fneg f7,f8
	ctx.f7.u64 = ctx.f8.u64 ^ 0x8000000000000000;
	// stfs f7,-16(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + -16, temp.u32);
loc_8253D498:
	// clrlwi r10,r8,24
	ctx.r10.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8253d4b4
	if (!cr6.eq) goto loc_8253D4B4;
	// lfs f0,-16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -16);
	f0.f64 = double(temp.f32);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bge cr6,0x8253d4b8
	if (!cr6.lt) goto loc_8253D4B8;
loc_8253D4B4:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8253D4B8:
	// lfs f0,-20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -20);
	f0.f64 = double(temp.f32);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lfs f13,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f11,-28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,-12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12);
	f0.f64 = double(temp.f32);
	// lfs f9,-24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -24);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,-8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -16);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f5,f0,f11,f12
	ctx.f5.f64 = double(float(f0.f64 * ctx.f11.f64 + ctx.f12.f64));
	// fmadds f4,f8,f9,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f7,f6,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fcmpu cr6,f3,f10
	cr6.compare(ctx.f3.f64, ctx.f10.f64);
	// bge cr6,0x8253d520
	if (!cr6.lt) goto loc_8253D520;
	// fneg f0,f0
	f0.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f0,-12(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -12, temp.u32);
	// lfs f13,-8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f13
	ctx.f12.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f12,-8(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + -8, temp.u32);
	// lfs f11,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f11.f64 = double(temp.f32);
	// fneg f9,f11
	ctx.f9.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// stfs f9,-4(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// lfs f8,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fneg f7,f8
	ctx.f7.u64 = ctx.f8.u64 ^ 0x8000000000000000;
	// stfs f7,0(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
loc_8253D520:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8253d53c
	if (!cr6.eq) goto loc_8253D53C;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bge cr6,0x8253d540
	if (!cr6.lt) goto loc_8253D540;
loc_8253D53C:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8253D540:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lfs f13,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,-8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,-12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12);
	ctx.f8.f64 = double(temp.f32);
	// lfs f0,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f7,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f5,f11,f9,f12
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f9.f64 + ctx.f12.f64));
	// fmadds f4,f8,f0,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f5.f64));
	// fmadds f3,f7,f6,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fcmpu cr6,f3,f10
	cr6.compare(ctx.f3.f64, ctx.f10.f64);
	// bge cr6,0x8253d5a8
	if (!cr6.lt) goto loc_8253D5A8;
	// fneg f0,f0
	f0.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// lfs f13,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f13
	ctx.f12.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f12,8(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lfs f11,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// fneg f9,f11
	ctx.f9.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// stfs f9,12(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// lfs f8,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// fneg f7,f8
	ctx.f7.u64 = ctx.f8.u64 ^ 0x8000000000000000;
	// stfs f7,16(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
loc_8253D5A8:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8253d5c4
	if (!cr6.eq) goto loc_8253D5C4;
	// lfs f0,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	f0.f64 = double(temp.f32);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bge cr6,0x8253d5c8
	if (!cr6.lt) goto loc_8253D5C8;
loc_8253D5C4:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8253D5C8:
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lfs f0,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f9,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f5.f64 = double(temp.f32);
	// fmadds f4,f9,f11,f12
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f11.f64 + ctx.f12.f64));
	// fmadds f3,f8,f7,f4
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fmadds f2,f5,f6,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f6.f64 + ctx.f3.f64));
	// fcmpu cr6,f2,f10
	cr6.compare(ctx.f2.f64, ctx.f10.f64);
	// bge cr6,0x8253d630
	if (!cr6.lt) goto loc_8253D630;
	// fneg f0,f0
	f0.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f0,20(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// lfs f13,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f13
	ctx.f12.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f12,24(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 24, temp.u32);
	// lfs f11,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f11.f64 = double(temp.f32);
	// fneg f9,f11
	ctx.f9.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// stfs f9,28(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 28, temp.u32);
	// lfs f8,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f8.f64 = double(temp.f32);
	// fneg f7,f8
	ctx.f7.u64 = ctx.f8.u64 ^ 0x8000000000000000;
	// stfs f7,32(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
loc_8253D630:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8253d64c
	if (!cr6.eq) goto loc_8253D64C;
	// lfs f0,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	f0.f64 = double(temp.f32);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bge cr6,0x8253d650
	if (!cr6.lt) goto loc_8253D650;
loc_8253D64C:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8253D650:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// bne 0x8253d434
	if (!cr0.eq) goto loc_8253D434;
loc_8253D660:
	// cmpw cr6,r7,r26
	cr6.compare<int32_t>(ctx.r7.s32, r26.s32, xer);
	// bge cr6,0x8253d700
	if (!cr6.lt) goto loc_8253D700;
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r9,r7,r26
	ctx.r9.s64 = r26.s64 - ctx.r7.s64;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
loc_8253D678:
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	f0.f64 = double(temp.f32);
	// fmuls f9,f13,f0
	ctx.f9.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f8,-8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	ctx.f8.f64 = double(temp.f32);
	// lfs f13,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f7,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f7.f64 = double(temp.f32);
	// lfs f12,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// lfs f6,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lfs f11,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f5,f8,f13,f9
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f9.f64));
	// fmadds f4,f7,f12,f5
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f12.f64 + ctx.f5.f64));
	// fmadds f3,f6,f11,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f11.f64 + ctx.f4.f64));
	// fcmpu cr6,f3,f10
	cr6.compare(ctx.f3.f64, ctx.f10.f64);
	// bge cr6,0x8253d6d0
	if (!cr6.lt) goto loc_8253D6D0;
	// fneg f13,f13
	ctx.f13.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f13,8(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// fneg f12,f12
	ctx.f12.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// stfs f12,12(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// fneg f11,f11
	ctx.f11.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// stfs f11,16(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// fneg f9,f0
	ctx.f9.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f9,20(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
loc_8253D6D0:
	// clrlwi r10,r8,24
	ctx.r10.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8253d6ec
	if (!cr6.eq) goto loc_8253D6EC;
	// lfs f0,20(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	f0.f64 = double(temp.f32);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// bge cr6,0x8253d6f0
	if (!cr6.lt) goto loc_8253D6F0;
loc_8253D6EC:
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8253D6F0:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// clrlwi r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x8253d678
	if (!cr0.eq) goto loc_8253D678;
loc_8253D700:
	// cmplwi cr6,r25,20
	cr6.compare<uint32_t>(r25.u32, 20, xer);
	// blt cr6,0x8253d774
	if (cr6.lt) goto loc_8253D774;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,20
	cr6.compare<uint32_t>(r11.u32, 20, xer);
	// blt cr6,0x8253d774
	if (cr6.lt) goto loc_8253D774;
	// lbz r11,1(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 1);
	// addi r29,r27,4
	r29.s64 = r27.s64 + 4;
	// li r31,4
	r31.s64 = 4;
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
	// stb r10,1(r27)
	PPC_STORE_U8(r27.u32 + 1, ctx.r10.u8);
loc_8253D728:
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// li r6,3
	ctx.r6.s64 = 3;
	// stw r10,16(r29)
	PPC_STORE_U32(r29.u32 + 16, ctx.r10.u32);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// rlwinm r28,r11,2,0,29
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8253c698
	ctx.lr = 0x8253D758;
	sub_8253C698(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// stwx r3,r28,r29
	PPC_STORE_U32(r28.u32 + r29.u32, ctx.r3.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8253d728
	if (!cr0.eq) goto loc_8253D728;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
loc_8253D774:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x8253D77C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8253d7ac
	if (cr6.eq) goto loc_8253D7AC;
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r10,3
	ctx.r10.s64 = 3;
	// addi r9,r11,-24460
	ctx.r9.s64 = r11.s64 + -24460;
	// stb r10,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r10.u8);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r28,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r28.u32);
	// sth r28,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r28.u16);
	// sth r28,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r28.u16);
	// b 0x8253d7b0
	goto loc_8253D7B0;
loc_8253D7AC:
	// mr r31,r28
	r31.u64 = r28.u64;
loc_8253D7B0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253D7D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r29,1(r27)
	PPC_STORE_U8(r27.u32 + 1, r29.u8);
	// lwz r10,20(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// addi r11,r27,4
	r11.s64 = r27.s64 + 4;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,20(r27)
	PPC_STORE_U32(r27.u32 + 20, ctx.r8.u32);
	// stwx r31,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r31.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8253D7F8"))) PPC_WEAK_FUNC(sub_8253D7F8);
PPC_FUNC_IMPL(__imp__sub_8253D7F8) {
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
	ctx.lr = 0x8253D800;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// mr r31,r25
	r31.u64 = r25.u64;
	// li r26,3
	r26.s64 = 3;
	// li r24,0
	r24.s64 = 0;
loc_8253D81C:
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8253d86c
	if (cr6.eq) goto loc_8253D86C;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8253d86c
	if (cr6.eq) goto loc_8253D86C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8253D840;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8253d86c
	if (cr6.eq) goto loc_8253D86C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8253D854;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x8253c3f8
	ctx.lr = 0x8253D868;
	sub_8253C3F8(ctx, base);
	// b 0x8253d870
	goto loc_8253D870;
loc_8253D86C:
	// stw r24,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r24.u32);
loc_8253D870:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bge 0x8253d81c
	if (!cr0.lt) goto loc_8253D81C;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r24,16(r25)
	PPC_STORE_U32(r25.u32 + 16, r24.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8253D88C"))) PPC_WEAK_FUNC(sub_8253D88C);
PPC_FUNC_IMPL(__imp__sub_8253D88C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253D890"))) PPC_WEAK_FUNC(sub_8253D890);
PPC_FUNC_IMPL(__imp__sub_8253D890) {
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
	ctx.lr = 0x8253D898;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lwz r27,0(r13)
	r27.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,60
	r28.s64 = 60;
	// mr r31,r25
	r31.u64 = r25.u64;
	// li r26,3
	r26.s64 = 3;
	// li r24,0
	r24.s64 = 0;
loc_8253D8B4:
	// lwzx r30,r28,r27
	r30.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8253d904
	if (cr6.eq) goto loc_8253D904;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8253d904
	if (cr6.eq) goto loc_8253D904;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x8253D8D8;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8253d904
	if (cr6.eq) goto loc_8253D904;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8253D8EC;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r28,r27
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r27.u32);
	// bl 0x8253c3f8
	ctx.lr = 0x8253D900;
	sub_8253C3F8(ctx, base);
	// b 0x8253d908
	goto loc_8253D908;
loc_8253D904:
	// stw r24,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r24.u32);
loc_8253D908:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bge 0x8253d8b4
	if (!cr0.lt) goto loc_8253D8B4;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8253D920"))) PPC_WEAK_FUNC(sub_8253D920);
PPC_FUNC_IMPL(__imp__sub_8253D920) {
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
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stb r11,1(r31)
	PPC_STORE_U8(r31.u32 + 1, r11.u8);
	// bl 0x8253d7f8
	ctx.lr = 0x8253D944;
	sub_8253D7F8(ctx, base);
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

__attribute__((alias("__imp__sub_8253D95C"))) PPC_WEAK_FUNC(sub_8253D95C);
PPC_FUNC_IMPL(__imp__sub_8253D95C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253D960"))) PPC_WEAK_FUNC(sub_8253D960);
PPC_FUNC_IMPL(__imp__sub_8253D960) {
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
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x8253d890
	ctx.lr = 0x8253D980;
	sub_8253D890(ctx, base);
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

__attribute__((alias("__imp__sub_8253D998"))) PPC_WEAK_FUNC(sub_8253D998);
PPC_FUNC_IMPL(__imp__sub_8253D998) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// b 0x8253d890
	sub_8253D890(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8253D9AC"))) PPC_WEAK_FUNC(sub_8253D9AC);
PPC_FUNC_IMPL(__imp__sub_8253D9AC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253D9B0"))) PPC_WEAK_FUNC(sub_8253D9B0);
PPC_FUNC_IMPL(__imp__sub_8253D9B0) {
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
	ctx.lr = 0x8253D9B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x8253D9C8;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8253d9e8
	if (cr6.eq) goto loc_8253D9E8;
	// li r11,0
	r11.s64 = 0;
	// addi r3,r28,4
	ctx.r3.s64 = r28.s64 + 4;
	// stb r11,1(r28)
	PPC_STORE_U8(r28.u32 + 1, r11.u8);
	// bl 0x8253d7f8
	ctx.lr = 0x8253D9E4;
	sub_8253D7F8(ctx, base);
	// b 0x8253d9ec
	goto loc_8253D9EC;
loc_8253D9E8:
	// li r28,0
	r28.s64 = 0;
loc_8253D9EC:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// li r29,0
	r29.s64 = 0;
	// stb r11,0(r28)
	PPC_STORE_U8(r28.u32 + 0, r11.u8);
	// lbz r10,1(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 1);
	// stb r10,1(r28)
	PPC_STORE_U8(r28.u32 + 1, ctx.r10.u8);
	// lhz r9,2(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 2);
	// sth r9,2(r28)
	PPC_STORE_U16(r28.u32 + 2, ctx.r9.u16);
	// lwz r8,20(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stw r8,20(r28)
	PPC_STORE_U32(r28.u32 + 20, ctx.r8.u32);
	// lwz r7,20(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x8253da50
	if (!cr6.gt) goto loc_8253DA50;
	// addi r31,r28,4
	r31.s64 = r28.s64 + 4;
	// subf r27,r28,r30
	r27.s64 = r30.s64 - r28.s64;
loc_8253DA24:
	// lwzx r3,r27,r31
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + r31.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253DA38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// lwz r9,20(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// blt cr6,0x8253da24
	if (cr6.lt) goto loc_8253DA24;
loc_8253DA50:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8253DA5C"))) PPC_WEAK_FUNC(sub_8253DA5C);
PPC_FUNC_IMPL(__imp__sub_8253DA5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253DA60"))) PPC_WEAK_FUNC(sub_8253DA60);
PPC_FUNC_IMPL(__imp__sub_8253DA60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r10,r11,-24092
	ctx.r10.s64 = r11.s64 + -24092;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253DA70"))) PPC_WEAK_FUNC(sub_8253DA70);
PPC_FUNC_IMPL(__imp__sub_8253DA70) {
	PPC_FUNC_PROLOGUE();
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253DA78"))) PPC_WEAK_FUNC(sub_8253DA78);
PPC_FUNC_IMPL(__imp__sub_8253DA78) {
	PPC_FUNC_PROLOGUE();
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// stw r7,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r7.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253DA8C"))) PPC_WEAK_FUNC(sub_8253DA8C);
PPC_FUNC_IMPL(__imp__sub_8253DA8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253DA90"))) PPC_WEAK_FUNC(sub_8253DA90);
PPC_FUNC_IMPL(__imp__sub_8253DA90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32248
	r11.s64 = -2113404928;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-24092
	ctx.r9.s64 = r11.s64 + -24092;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253DAAC"))) PPC_WEAK_FUNC(sub_8253DAAC);
PPC_FUNC_IMPL(__imp__sub_8253DAAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253DAB0"))) PPC_WEAK_FUNC(sub_8253DAB0);
PPC_FUNC_IMPL(__imp__sub_8253DAB0) {
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
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-24092
	ctx.r9.s64 = r11.s64 + -24092;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8253dae4
	if (cr6.eq) goto loc_8253DAE4;
	// bl 0x82130588
	ctx.lr = 0x8253DAE0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8253DAE4:
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

__attribute__((alias("__imp__sub_8253DAF8"))) PPC_WEAK_FUNC(sub_8253DAF8);
PPC_FUNC_IMPL(__imp__sub_8253DAF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253DB08"))) PPC_WEAK_FUNC(sub_8253DB08);
PPC_FUNC_IMPL(__imp__sub_8253DB08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// lis r11,-32114
	r11.s64 = -2104623104;
	// bge cr6,0x8253db24
	if (!cr6.lt) goto loc_8253DB24;
	// lwz r11,-32544(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -32544);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// blr 
	return;
loc_8253DB24:
	// addi r11,r11,-32544
	r11.s64 = r11.s64 + -32544;
	// li r10,6
	ctx.r10.s64 = 6;
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmpwi cr6,r9,6
	cr6.compare<int32_t>(ctx.r9.s32, 6, xer);
	// ble cr6,0x8253db6c
	if (!cr6.gt) goto loc_8253DB6C;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r8,24
	r11.s64 = ctx.r8.s64 + 24;
loc_8253DB40:
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8253db5c
	if (cr6.eq) goto loc_8253DB5C;
	// rotlwi r7,r7,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cmpw cr6,r6,r3
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r3.s32, xer);
	// beq cr6,0x8253db74
	if (cr6.eq) goto loc_8253DB74;
loc_8253DB5C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x8253db40
	if (cr6.lt) goto loc_8253DB40;
loc_8253DB6C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8253DB74:
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r8
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253DB80"))) PPC_WEAK_FUNC(sub_8253DB80);
PPC_FUNC_IMPL(__imp__sub_8253DB80) {
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
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r3,4(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// bl 0x8253db08
	ctx.lr = 0x8253DBA0;
	sub_8253DB08(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253DBB8;
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

__attribute__((alias("__imp__sub_8253DBCC"))) PPC_WEAK_FUNC(sub_8253DBCC);
PPC_FUNC_IMPL(__imp__sub_8253DBCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253DBD0"))) PPC_WEAK_FUNC(sub_8253DBD0);
PPC_FUNC_IMPL(__imp__sub_8253DBD0) {
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
	// lbz r11,-32548(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + -32548);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8253dc5c
	if (!cr6.eq) goto loc_8253DC5C;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r31,r11,-32544
	r31.s64 = r11.s64 + -32544;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8253dc1c
	if (!cr6.eq) goto loc_8253DC1C;
	// li r11,6
	r11.s64 = 6;
	// li r3,24
	ctx.r3.s64 = 24;
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// bl 0x82130528
	ctx.lr = 0x8253DC18;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_8253DC1C:
	// li r10,6
	ctx.r10.s64 = 6;
	// li r9,0
	ctx.r9.s64 = 0;
	// sth r10,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r10.u16);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8253DC2C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stwx r9,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r11,24
	cr6.compare<int32_t>(r11.s32, 24, xer);
	// blt cr6,0x8253dc2c
	if (cr6.lt) goto loc_8253DC2C;
	// bl 0x8253fb70
	ctx.lr = 0x8253DC44;
	sub_8253FB70(ctx, base);
	// bl 0x8253fee0
	ctx.lr = 0x8253DC48;
	sub_8253FEE0(ctx, base);
	// bl 0x8253edb8
	ctx.lr = 0x8253DC4C;
	sub_8253EDB8(ctx, base);
	// bl 0x82546e88
	ctx.lr = 0x8253DC50;
	sub_82546E88(ctx, base);
	// bl 0x8253dd80
	ctx.lr = 0x8253DC54;
	sub_8253DD80(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,-32548(r30)
	PPC_STORE_U8(r30.u32 + -32548, r11.u8);
loc_8253DC5C:
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

__attribute__((alias("__imp__sub_8253DC74"))) PPC_WEAK_FUNC(sub_8253DC74);
PPC_FUNC_IMPL(__imp__sub_8253DC74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253DC78"))) PPC_WEAK_FUNC(sub_8253DC78);
PPC_FUNC_IMPL(__imp__sub_8253DC78) {
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
	// lis r31,-32114
	r31.s64 = -2104623104;
	// addi r30,r31,-32544
	r30.s64 = r31.s64 + -32544;
	// lwz r3,-32544(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -32544);
	// bl 0x82130588
	ctx.lr = 0x8253DC9C;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,-32544(r31)
	PPC_STORE_U32(r31.u32 + -32544, r11.u32);
	// sth r10,4(r30)
	PPC_STORE_U16(r30.u32 + 4, ctx.r10.u16);
	// sth r9,6(r30)
	PPC_STORE_U16(r30.u32 + 6, ctx.r9.u16);
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

__attribute__((alias("__imp__sub_8253DCCC"))) PPC_WEAK_FUNC(sub_8253DCCC);
PPC_FUNC_IMPL(__imp__sub_8253DCCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253DCD0"))) PPC_WEAK_FUNC(sub_8253DCD0);
PPC_FUNC_IMPL(__imp__sub_8253DCD0) {
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
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,-24092
	ctx.r10.s64 = r11.s64 + -24092;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x8253DCF8;
	sub_821B5A60(ctx, base);
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

__attribute__((alias("__imp__sub_8253DD10"))) PPC_WEAK_FUNC(sub_8253DD10);
PPC_FUNC_IMPL(__imp__sub_8253DD10) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// bge cr6,0x8253dd54
	if (!cr6.lt) goto loc_8253DD54;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-32544(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -32544);
	// stwx r31,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r31.u32);
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
loc_8253DD54:
	// lis r11,-32114
	r11.s64 = -2104623104;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r11,-32544
	ctx.r3.s64 = r11.s64 + -32544;
	// bl 0x8262e420
	ctx.lr = 0x8253DD64;
	sub_8262E420(ctx, base);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
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

__attribute__((alias("__imp__sub_8253DD7C"))) PPC_WEAK_FUNC(sub_8253DD7C);
PPC_FUNC_IMPL(__imp__sub_8253DD7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253DD80"))) PPC_WEAK_FUNC(sub_8253DD80);
PPC_FUNC_IMPL(__imp__sub_8253DD80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r11,-32536
	ctx.r3.s64 = r11.s64 + -32536;
	// b 0x8253dd10
	sub_8253DD10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8253DD8C"))) PPC_WEAK_FUNC(sub_8253DD8C);
PPC_FUNC_IMPL(__imp__sub_8253DD8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253DD90"))) PPC_WEAK_FUNC(sub_8253DD90);
PPC_FUNC_IMPL(__imp__sub_8253DD90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r11,-32536
	ctx.r3.s64 = r11.s64 + -32536;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253DD9C"))) PPC_WEAK_FUNC(sub_8253DD9C);
PPC_FUNC_IMPL(__imp__sub_8253DD9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253DDA0"))) PPC_WEAK_FUNC(sub_8253DDA0);
PPC_FUNC_IMPL(__imp__sub_8253DDA0) {
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
	// beq cr6,0x8253ddfc
	if (cr6.eq) goto loc_8253DDFC;
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8253ddf4
	if (cr6.eq) goto loc_8253DDF4;
	// rlwinm r3,r10,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8253DDEC;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// b 0x8253ddfc
	goto loc_8253DDFC;
loc_8253DDF4:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_8253DDFC:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253de44
	if (cr6.eq) goto loc_8253DE44;
	// li r11,0
	r11.s64 = 0;
loc_8253DE0C:
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r7,r8,r10
	ctx.r7.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// lhzx r5,r8,r10
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r10.u32);
	// sthx r5,r10,r9
	PPC_STORE_U16(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u16);
	// lhz r4,2(r7)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// sth r4,2(r6)
	PPC_STORE_U16(ctx.r6.u32 + 2, ctx.r4.u16);
	// lhz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// blt cr6,0x8253de0c
	if (cr6.lt) goto loc_8253DE0C;
loc_8253DE44:
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

__attribute__((alias("__imp__sub_8253DE5C"))) PPC_WEAK_FUNC(sub_8253DE5C);
PPC_FUNC_IMPL(__imp__sub_8253DE5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253DE60"))) PPC_WEAK_FUNC(sub_8253DE60);
PPC_FUNC_IMPL(__imp__sub_8253DE60) {
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
	ctx.lr = 0x8253DE68;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r27,8(r31)
	r27.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x8253dee0
	if (!cr6.gt) goto loc_8253DEE0;
	// li r30,0
	r30.s64 = 0;
loc_8253DE88:
	// lhz r11,20(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 20);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253deb4
	if (cr6.eq) goto loc_8253DEB4;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// add r6,r10,r30
	ctx.r6.u64 = ctx.r10.u64 + r30.u64;
	// lhz r5,2(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lbz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// b 0x8253decc
	goto loc_8253DECC;
loc_8253DEB4:
	// lhz r10,14(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// lbz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// add r6,r11,r30
	ctx.r6.u64 = r11.u64 + r30.u64;
	// clrlwi r5,r10,16
	ctx.r5.u64 = ctx.r10.u32 & 0xFFFF;
loc_8253DECC:
	// bl 0x82509b98
	ctx.lr = 0x8253DED0;
	sub_82509B98(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// blt cr6,0x8253de88
	if (cr6.lt) goto loc_8253DE88;
loc_8253DEE0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8253DEE8"))) PPC_WEAK_FUNC(sub_8253DEE8);
PPC_FUNC_IMPL(__imp__sub_8253DEE8) {
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
	ctx.lr = 0x8253DEF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r27,8(r31)
	r27.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x8253df60
	if (!cr6.gt) goto loc_8253DF60;
	// li r30,0
	r30.s64 = 0;
loc_8253DF10:
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lhz r11,20(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfsx f1,r10,r30
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	ctx.f1.f64 = double(temp.f32);
	// beq cr6,0x8253df3c
	if (cr6.eq) goto loc_8253DF3C;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lhz r5,2(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lbz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// b 0x8253df4c
	goto loc_8253DF4C;
loc_8253DF3C:
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// lbz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// add r9,r11,r29
	ctx.r9.u64 = r11.u64 + r29.u64;
	// clrlwi r5,r9,16
	ctx.r5.u64 = ctx.r9.u32 & 0xFFFF;
loc_8253DF4C:
	// bl 0x82509c00
	ctx.lr = 0x8253DF50;
	sub_82509C00(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// blt cr6,0x8253df10
	if (cr6.lt) goto loc_8253DF10;
loc_8253DF60:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8253DF68"))) PPC_WEAK_FUNC(sub_8253DF68);
PPC_FUNC_IMPL(__imp__sub_8253DF68) {
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
	ctx.lr = 0x8253DF70;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r27,8(r31)
	r27.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x8253dfdc
	if (!cr6.gt) goto loc_8253DFDC;
	// li r29,0
	r29.s64 = 0;
loc_8253DF90:
	// lhz r11,20(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 20);
	// li r6,2
	ctx.r6.s64 = 2;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253dfb8
	if (cr6.eq) goto loc_8253DFB8;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lhz r5,2(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lbz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// b 0x8253dfc8
	goto loc_8253DFC8;
loc_8253DFB8:
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// lbz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// clrlwi r5,r11,16
	ctx.r5.u64 = r11.u32 & 0xFFFF;
loc_8253DFC8:
	// bl 0x825265e0
	ctx.lr = 0x8253DFCC;
	sub_825265E0(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// blt cr6,0x8253df90
	if (cr6.lt) goto loc_8253DF90;
loc_8253DFDC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8253DFE4"))) PPC_WEAK_FUNC(sub_8253DFE4);
PPC_FUNC_IMPL(__imp__sub_8253DFE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253DFE8"))) PPC_WEAK_FUNC(sub_8253DFE8);
PPC_FUNC_IMPL(__imp__sub_8253DFE8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8253DFF0;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r27,8(r31)
	r27.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x8253e068
	if (!cr6.gt) goto loc_8253E068;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r29,0
	r29.s64 = 0;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_8253E01C:
	// lhz r11,20(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 20);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253e044
	if (cr6.eq) goto loc_8253E044;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// lhz r5,2(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lbz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// b 0x8253e054
	goto loc_8253E054;
loc_8253E044:
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// lbz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// clrlwi r5,r11,16
	ctx.r5.u64 = r11.u32 & 0xFFFF;
loc_8253E054:
	// bl 0x82509c00
	ctx.lr = 0x8253E058;
	sub_82509C00(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// blt cr6,0x8253e01c
	if (cr6.lt) goto loc_8253E01C;
loc_8253E068:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8253E074"))) PPC_WEAK_FUNC(sub_8253E074);
PPC_FUNC_IMPL(__imp__sub_8253E074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253E078"))) PPC_WEAK_FUNC(sub_8253E078);
PPC_FUNC_IMPL(__imp__sub_8253E078) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lhz r6,8(r3)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r6,4
	cr6.compare<int32_t>(ctx.r6.s32, 4, xer);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// blt cr6,0x8253e0dc
	if (cr6.lt) goto loc_8253E0DC;
	// addi r10,r6,-4
	ctx.r10.s64 = ctx.r6.s64 + -4;
	// li r11,0
	r11.s64 = 0;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_8253E0A4:
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
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
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + r11.u64;
	// stfs f0,4(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stfs f0,-4(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + -4, temp.u32);
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stfsx f0,r8,r9
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, temp.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x8253e0a4
	if (!cr0.eq) goto loc_8253E0A4;
loc_8253E0DC:
	// cmpw cr6,r7,r6
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r7,r6
	r11.s64 = ctx.r6.s64 - ctx.r7.s64;
loc_8253E0EC:
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stfsx f0,r10,r9
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x8253e0ec
	if (!cr0.eq) goto loc_8253E0EC;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253E104"))) PPC_WEAK_FUNC(sub_8253E104);
PPC_FUNC_IMPL(__imp__sub_8253E104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253E108"))) PPC_WEAK_FUNC(sub_8253E108);
PPC_FUNC_IMPL(__imp__sub_8253E108) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8253e214
	if (cr6.eq) goto loc_8253E214;
	// lhz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r5,1
	cr6.compare<uint32_t>(ctx.r5.u32, 1, xer);
	// ble cr6,0x8253e208
	if (!cr6.gt) goto loc_8253E208;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r11,-12768
	ctx.r9.s64 = r11.s64 + -12768;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r5,4
	cr6.compare<int32_t>(ctx.r5.s32, 4, xer);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blt cr6,0x8253e1b4
	if (cr6.lt) goto loc_8253E1B4;
	// addi r11,r5,-4
	r11.s64 = ctx.r5.s64 + -4;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r11,30,2,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// addi r11,r8,8
	r11.s64 = ctx.r8.s64 + 8;
	// subf r8,r8,r6
	ctx.r8.s64 = ctx.r6.s64 - ctx.r8.s64;
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_8253E184:
	// lfs f0,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	f0.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stfs f0,-4(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + -4, temp.u32);
	// lfs f13,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,0(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfsx f12,r7,r11
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r7.u32 + r11.u32, temp.u32);
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// stfsx f11,r8,r11
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, temp.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x8253e184
	if (!cr0.eq) goto loc_8253E184;
loc_8253E1B4:
	// cmpw cr6,r6,r5
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r5.s32, xer);
	// bge cr6,0x8253e1ec
	if (!cr6.lt) goto loc_8253E1EC;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// subf r10,r6,r5
	ctx.r10.s64 = ctx.r5.s64 - ctx.r6.s64;
loc_8253E1D8:
	// lfsx f0,r9,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8253e1d8
	if (!cr0.eq) goto loc_8253E1D8;
loc_8253E1EC:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x82192a88
	ctx.lr = 0x8253E1F4;
	sub_82192A88(ctx, base);
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
loc_8253E208:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82192798
	ctx.lr = 0x8253E214;
	sub_82192798(ctx, base);
loc_8253E214:
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

__attribute__((alias("__imp__sub_8253E228"))) PPC_WEAK_FUNC(sub_8253E228);
PPC_FUNC_IMPL(__imp__sub_8253E228) {
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
	ctx.lr = 0x8253E230;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lhz r31,16(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8253e270
	if (!cr6.gt) goto loc_8253E270;
	// li r30,0
	r30.s64 = 0;
loc_8253E250:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x8253de60
	ctx.lr = 0x8253E264;
	sub_8253DE60(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,24
	r30.s64 = r30.s64 + 24;
	// bne 0x8253e250
	if (!cr0.eq) goto loc_8253E250;
loc_8253E270:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8253E278"))) PPC_WEAK_FUNC(sub_8253E278);
PPC_FUNC_IMPL(__imp__sub_8253E278) {
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
	ctx.lr = 0x8253E280;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lhz r31,16(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8253e2c0
	if (!cr6.gt) goto loc_8253E2C0;
	// li r30,0
	r30.s64 = 0;
loc_8253E2A0:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x8253dee8
	ctx.lr = 0x8253E2B4;
	sub_8253DEE8(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,24
	r30.s64 = r30.s64 + 24;
	// bne 0x8253e2a0
	if (!cr0.eq) goto loc_8253E2A0;
loc_8253E2C0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8253E2C8"))) PPC_WEAK_FUNC(sub_8253E2C8);
PPC_FUNC_IMPL(__imp__sub_8253E2C8) {
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
	ctx.lr = 0x8253E2D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lhz r31,16(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8253e310
	if (!cr6.gt) goto loc_8253E310;
	// li r30,0
	r30.s64 = 0;
loc_8253E2F0:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x8253df68
	ctx.lr = 0x8253E304;
	sub_8253DF68(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,24
	r30.s64 = r30.s64 + 24;
	// bne 0x8253e2f0
	if (!cr0.eq) goto loc_8253E2F0;
loc_8253E310:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8253E318"))) PPC_WEAK_FUNC(sub_8253E318);
PPC_FUNC_IMPL(__imp__sub_8253E318) {
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
	ctx.lr = 0x8253E320;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lhz r31,16(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8253e360
	if (!cr6.gt) goto loc_8253E360;
	// li r30,0
	r30.s64 = 0;
loc_8253E340:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x8253dfe8
	ctx.lr = 0x8253E354;
	sub_8253DFE8(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,24
	r30.s64 = r30.s64 + 24;
	// bne 0x8253e340
	if (!cr0.eq) goto loc_8253E340;
loc_8253E360:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8253E368"))) PPC_WEAK_FUNC(sub_8253E368);
PPC_FUNC_IMPL(__imp__sub_8253E368) {
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
	ctx.lr = 0x8253E370;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lhz r31,16(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8253e3a0
	if (!cr6.gt) goto loc_8253E3A0;
	// li r30,0
	r30.s64 = 0;
loc_8253E388:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x8253e078
	ctx.lr = 0x8253E394;
	sub_8253E078(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,24
	r30.s64 = r30.s64 + 24;
	// bne 0x8253e388
	if (!cr0.eq) goto loc_8253E388;
loc_8253E3A0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8253E3A8"))) PPC_WEAK_FUNC(sub_8253E3A8);
PPC_FUNC_IMPL(__imp__sub_8253E3A8) {
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
	ctx.lr = 0x8253E3B0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8253e3f0
	if (cr6.eq) goto loc_8253E3F0;
	// lhz r31,16(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 16);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8253e3f0
	if (!cr6.gt) goto loc_8253E3F0;
	// li r30,0
	r30.s64 = 0;
loc_8253E3D4:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwz r4,20(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x8253e108
	ctx.lr = 0x8253E3E4;
	sub_8253E108(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,24
	r30.s64 = r30.s64 + 24;
	// bne 0x8253e3d4
	if (!cr0.eq) goto loc_8253E3D4;
loc_8253E3F0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8253E3F8"))) PPC_WEAK_FUNC(sub_8253E3F8);
PPC_FUNC_IMPL(__imp__sub_8253E3F8) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8253E400;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// addi r31,r29,4
	r31.s64 = r29.s64 + 4;
	// stw r4,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r4.u32);
	// lhz r11,10(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8253e448
	if (!cr6.eq) goto loc_8253E448;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x8253e440
	if (cr6.eq) goto loc_8253E440;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8253E43C;
	sub_82130528(ctx, base);
	// b 0x8253e444
	goto loc_8253E444;
loc_8253E440:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8253E444:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_8253E448:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// sth r30,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r30.u16);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// blt cr6,0x8253e4ac
	if (cr6.lt) goto loc_8253E4AC;
	// addi r10,r30,-4
	ctx.r10.s64 = r30.s64 + -4;
	// li r11,0
	r11.s64 = 0;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_8253E474:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r11,12
	ctx.r9.s64 = r11.s64 + 12;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stfsx f0,r11,r8
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, temp.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r8
	ctx.r6.u64 = r11.u64 + ctx.r8.u64;
	// stfs f0,4(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stfs f0,-4(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + -4, temp.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfsx f0,r9,r4
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r4.u32, temp.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x8253e474
	if (!cr0.eq) goto loc_8253E474;
loc_8253E4AC:
	// cmpw cr6,r7,r30
	cr6.compare<int32_t>(ctx.r7.s32, r30.s32, xer);
	// bge cr6,0x8253e4d0
	if (!cr6.lt) goto loc_8253E4D0;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r7,r30
	r11.s64 = r30.s64 - ctx.r7.s64;
loc_8253E4BC:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stfsx f0,r10,r9
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x8253e4bc
	if (!cr0.eq) goto loc_8253E4BC;
loc_8253E4D0:
	// sth r27,14(r29)
	PPC_STORE_U16(r29.u32 + 14, r27.u16);
	// stb r28,12(r29)
	PPC_STORE_U8(r29.u32 + 12, r28.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8253E4E0"))) PPC_WEAK_FUNC(sub_8253E4E0);
PPC_FUNC_IMPL(__imp__sub_8253E4E0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8253E4E8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// lhz r11,10(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8253e530
	if (!cr6.eq) goto loc_8253E530;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// sth r29,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r29.u16);
	// beq cr6,0x8253e528
	if (cr6.eq) goto loc_8253E528;
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8253E524;
	sub_82130528(ctx, base);
	// b 0x8253e52c
	goto loc_8253E52C;
loc_8253E528:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8253E52C:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_8253E530:
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// clrlwi r28,r29,16
	r28.u64 = r29.u32 & 0xFFFF;
	// sth r28,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r28.u16);
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8253e568
	if (!cr6.eq) goto loc_8253E568;
	// sth r28,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r28.u16);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8253e560
	if (cr6.eq) goto loc_8253E560;
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8253E55C;
	sub_82130528(ctx, base);
	// b 0x8253e564
	goto loc_8253E564;
loc_8253E560:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8253E564:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_8253E568:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// sth r28,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r28.u16);
	// li r5,0
	ctx.r5.s64 = 0;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// blt cr6,0x8253e650
	if (cr6.lt) goto loc_8253E650;
	// addi r10,r29,-4
	ctx.r10.s64 = r29.s64 + -4;
	// li r11,0
	r11.s64 = 0;
	// rlwinm r9,r10,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r27,1
	ctx.r10.s64 = r27.s64 + 1;
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// addi r9,r26,4
	ctx.r9.s64 = r26.s64 + 4;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
loc_8253E59C:
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r8,r11,12
	ctx.r8.s64 = r11.s64 + 12;
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r6,r8,-4
	ctx.r6.s64 = ctx.r8.s64 + -4;
	// stfsx f0,r11,r4
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + ctx.r4.u32, temp.u32);
	// lbz r3,-1(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + -1);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stbx r3,r11,r4
	PPC_STORE_U8(r11.u32 + ctx.r4.u32, ctx.r3.u8);
	// lhz r3,-4(r9)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r9.u32 + -4);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r4,r11,r4
	ctx.r4.u64 = r11.u64 + ctx.r4.u64;
	// sth r3,2(r4)
	PPC_STORE_U16(ctx.r4.u32 + 2, ctx.r3.u16);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r3,r11,r4
	ctx.r3.u64 = r11.u64 + ctx.r4.u64;
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lbz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r4,r11,r4
	ctx.r4.u64 = r11.u64 + ctx.r4.u64;
	// stb r3,4(r4)
	PPC_STORE_U8(ctx.r4.u32 + 4, ctx.r3.u8);
	// lhz r3,-2(r9)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r9.u32 + -2);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r4,r11,r4
	ctx.r4.u64 = r11.u64 + ctx.r4.u64;
	// sth r3,6(r4)
	PPC_STORE_U16(ctx.r4.u32 + 6, ctx.r3.u16);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stfsx f0,r6,r3
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + ctx.r3.u32, temp.u32);
	// lbz r4,1(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stbx r4,r6,r3
	PPC_STORE_U8(ctx.r6.u32 + ctx.r3.u32, ctx.r4.u8);
	// lhz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r9.u32 + 0);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r11,r6
	ctx.r3.u64 = r11.u64 + ctx.r6.u64;
	// sth r4,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, ctx.r4.u16);
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stfsx f0,r8,r6
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + ctx.r6.u32, temp.u32);
	// lbz r4,2(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stbx r4,r8,r3
	PPC_STORE_U8(ctx.r8.u32 + ctx.r3.u32, ctx.r4.u8);
	// lhz r6,2(r9)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r9.u32 + 2);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r4,r11,r8
	ctx.r4.u64 = r11.u64 + ctx.r8.u64;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// sth r6,14(r4)
	PPC_STORE_U16(ctx.r4.u32 + 14, ctx.r6.u16);
	// bne 0x8253e59c
	if (!cr0.eq) goto loc_8253E59C;
loc_8253E650:
	// cmpw cr6,r5,r29
	cr6.compare<int32_t>(ctx.r5.s32, r29.s32, xer);
	// bge cr6,0x8253e69c
	if (!cr6.lt) goto loc_8253E69C;
	// rlwinm r10,r5,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 + r26.u64;
loc_8253E664:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stfsx f0,r11,r9
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, temp.u32);
	// lbzx r8,r5,r27
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + r27.u32);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmpw cr6,r5,r29
	cr6.compare<int32_t>(ctx.r5.s32, r29.s32, xer);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stbx r8,r11,r7
	PPC_STORE_U8(r11.u32 + ctx.r7.u32, ctx.r8.u8);
	// lhz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// sth r4,2(r6)
	PPC_STORE_U16(ctx.r6.u32 + 2, ctx.r4.u16);
	// blt cr6,0x8253e664
	if (cr6.lt) goto loc_8253E664;
loc_8253E69C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8253E6A4"))) PPC_WEAK_FUNC(sub_8253E6A4);
PPC_FUNC_IMPL(__imp__sub_8253E6A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253E6A8"))) PPC_WEAK_FUNC(sub_8253E6A8);
PPC_FUNC_IMPL(__imp__sub_8253E6A8) {
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
	ctx.lr = 0x8253E6B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r28,r30,4
	r28.s64 = r30.s64 + 4;
	// addi r29,r31,4
	r29.s64 = r31.s64 + 4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r29,r28
	cr6.compare<uint32_t>(r29.u32, r28.u32, xer);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// beq cr6,0x8253e704
	if (cr6.eq) goto loc_8253E704;
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8253e6f8
	if (cr6.eq) goto loc_8253E6F8;
	// lhz r11,6(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253e6f8
	if (cr6.eq) goto loc_8253E6F8;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8253E6F8;
	sub_82130588(ctx, base);
loc_8253E6F8:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8224fb18
	ctx.lr = 0x8253E704;
	sub_8224FB18(ctx, base);
loc_8253E704:
	// lbz r11,12(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// addi r28,r30,16
	r28.s64 = r30.s64 + 16;
	// addi r29,r31,16
	r29.s64 = r31.s64 + 16;
	// cmplw cr6,r29,r28
	cr6.compare<uint32_t>(r29.u32, r28.u32, xer);
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// lhz r10,14(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 14);
	// sth r10,14(r31)
	PPC_STORE_U16(r31.u32 + 14, ctx.r10.u16);
	// beq cr6,0x8253e754
	if (cr6.eq) goto loc_8253E754;
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8253e748
	if (cr6.eq) goto loc_8253E748;
	// lhz r11,6(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253e748
	if (cr6.eq) goto loc_8253E748;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8253E748;
	sub_82130588(ctx, base);
loc_8253E748:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8253dda0
	ctx.lr = 0x8253E754;
	sub_8253DDA0(ctx, base);
loc_8253E754:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8253E760"))) PPC_WEAK_FUNC(sub_8253E760);
PPC_FUNC_IMPL(__imp__sub_8253E760) {
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
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r3,r11,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130528
	ctx.lr = 0x8253E784;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8253e7cc
	if (!cr6.gt) goto loc_8253E7CC;
	// addi r11,r3,10
	r11.s64 = ctx.r3.s64 + 10;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,255
	ctx.r9.s64 = 255;
loc_8253E798:
	// addic. r8,r11,-10
	xer.ca = r11.u32 > 9;
	ctx.r8.s64 = r11.s64 + -10;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x8253e7c0
	if (cr0.eq) goto loc_8253E7C0;
	// stw r10,-6(r11)
	PPC_STORE_U32(r11.u32 + -6, ctx.r10.u32);
	// sth r10,-2(r11)
	PPC_STORE_U16(r11.u32 + -2, ctx.r10.u16);
	// sth r10,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r10.u16);
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// sth r10,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r10.u16);
	// stw r10,6(r11)
	PPC_STORE_U32(r11.u32 + 6, ctx.r10.u32);
	// sth r10,10(r11)
	PPC_STORE_U16(r11.u32 + 10, ctx.r10.u16);
	// sth r10,12(r11)
	PPC_STORE_U16(r11.u32 + 12, ctx.r10.u16);
loc_8253E7C0:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// bne 0x8253e798
	if (!cr0.eq) goto loc_8253E798;
loc_8253E7CC:
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

__attribute__((alias("__imp__sub_8253E7E0"))) PPC_WEAK_FUNC(sub_8253E7E0);
PPC_FUNC_IMPL(__imp__sub_8253E7E0) {
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
	ctx.lr = 0x8253E7E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x8253e830
	if (cr6.eq) goto loc_8253E830;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r11,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r11.u16);
	// sth r11,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r11.u16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8253e82c
	if (cr6.eq) goto loc_8253E82C;
	// bl 0x8253e760
	ctx.lr = 0x8253E824;
	sub_8253E760(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// b 0x8253e830
	goto loc_8253E830;
loc_8253E82C:
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
loc_8253E830:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253e870
	if (cr6.eq) goto loc_8253E870;
loc_8253E83C:
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + r11.u64;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8253e6a8
	ctx.lr = 0x8253E85C;
	sub_8253E6A8(ctx, base);
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
	// lhz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// clrlwi r31,r10,16
	r31.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// blt cr6,0x8253e83c
	if (cr6.lt) goto loc_8253E83C;
loc_8253E870:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8253E878"))) PPC_WEAK_FUNC(sub_8253E878);
PPC_FUNC_IMPL(__imp__sub_8253E878) {
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
	ctx.lr = 0x8253E880;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x8253e8cc
	if (!cr6.gt) goto loc_8253E8CC;
	// addi r31,r29,10
	r31.s64 = r29.s64 + 10;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
loc_8253E898:
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253e8ac
	if (cr6.eq) goto loc_8253E8AC;
	// lwz r3,6(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 6);
	// bl 0x82130588
	ctx.lr = 0x8253E8AC;
	sub_82130588(ctx, base);
loc_8253E8AC:
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253e8c0
	if (cr6.eq) goto loc_8253E8C0;
	// lwz r3,-6(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -6);
	// bl 0x82130588
	ctx.lr = 0x8253E8C0;
	sub_82130588(ctx, base);
loc_8253E8C0:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,24
	r31.s64 = r31.s64 + 24;
	// bne 0x8253e898
	if (!cr0.eq) goto loc_8253E898;
loc_8253E8CC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x8253E8D4;
	sub_82130588(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8253E8DC"))) PPC_WEAK_FUNC(sub_8253E8DC);
PPC_FUNC_IMPL(__imp__sub_8253E8DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253E8E0"))) PPC_WEAK_FUNC(sub_8253E8E0);
PPC_FUNC_IMPL(__imp__sub_8253E8E0) {
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
	ctx.lr = 0x8253E8E8;
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
	// bne cr6,0x8253e968
	if (!cr6.eq) goto loc_8253E968;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x8253e760
	ctx.lr = 0x8253E910;
	sub_8253E760(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8253e954
	if (cr6.eq) goto loc_8253E954;
	// li r30,0
	r30.s64 = 0;
loc_8253E924:
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x8253e6a8
	ctx.lr = 0x8253E940;
	sub_8253E6A8(ctx, base);
	// addi r10,r30,1
	ctx.r10.s64 = r30.s64 + 1;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// clrlwi r30,r10,16
	r30.u64 = ctx.r10.u32 & 0xFFFF;
	// cmplw cr6,r30,r9
	cr6.compare<uint32_t>(r30.u32, ctx.r9.u32, xer);
	// blt cr6,0x8253e924
	if (cr6.lt) goto loc_8253E924;
loc_8253E954:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8253e878
	ctx.lr = 0x8253E964;
	sub_8253E878(ctx, base);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
loc_8253E968:
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
	// rlwinm r11,r7,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8253E990"))) PPC_WEAK_FUNC(sub_8253E990);
PPC_FUNC_IMPL(__imp__sub_8253E990) {
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
	ctx.lr = 0x8253E998;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x8253da90
	ctx.lr = 0x8253E9B0;
	sub_8253DA90(ctx, base);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-23756
	ctx.r9.s64 = ctx.r10.s64 + -23756;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// sth r11,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r11.u16);
	// sth r11,18(r31)
	PPC_STORE_U16(r31.u32 + 18, r11.u16);
	// bl 0x821b5a60
	ctx.lr = 0x8253E9D4;
	sub_821B5A60(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8253E9EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,8(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r6.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8253EA00"))) PPC_WEAK_FUNC(sub_8253EA00);
PPC_FUNC_IMPL(__imp__sub_8253EA00) {
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
	// bl 0x8253dcd0
	ctx.lr = 0x8253EA20;
	sub_8253DCD0(ctx, base);
	// lis r11,-32248
	r11.s64 = -2113404928;
	// addi r10,r11,-23756
	ctx.r10.s64 = r11.s64 + -23756;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8253ea4c
	if (cr6.eq) goto loc_8253EA4C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x8253EA40;
	sub_8217D890(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
loc_8253EA4C:
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// bl 0x821b5a60
	ctx.lr = 0x8253EA54;
	sub_821B5A60(ctx, base);
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

__attribute__((alias("__imp__sub_8253EA70"))) PPC_WEAK_FUNC(sub_8253EA70);
PPC_FUNC_IMPL(__imp__sub_8253EA70) {
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
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x8253EA88;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8253ead8
	if (cr6.eq) goto loc_8253EAD8;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x8253da90
	ctx.lr = 0x8253EA9C;
	sub_8253DA90(ctx, base);
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-23756
	ctx.r9.s64 = ctx.r10.s64 + -23756;
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// sth r11,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r11.u16);
	// sth r11,18(r31)
	PPC_STORE_U16(r31.u32 + 18, r11.u16);
	// bl 0x821b5a60
	ctx.lr = 0x8253EAC0;
	sub_821B5A60(ctx, base);
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
loc_8253EAD8:
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

__attribute__((alias("__imp__sub_8253EAF0"))) PPC_WEAK_FUNC(sub_8253EAF0);
PPC_FUNC_IMPL(__imp__sub_8253EAF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x8253ea00
	sub_8253EA00(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8253EB08"))) PPC_WEAK_FUNC(sub_8253EB08);
PPC_FUNC_IMPL(__imp__sub_8253EB08) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8253EB0C"))) PPC_WEAK_FUNC(sub_8253EB0C);
PPC_FUNC_IMPL(__imp__sub_8253EB0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253EB10"))) PPC_WEAK_FUNC(sub_8253EB10);
PPC_FUNC_IMPL(__imp__sub_8253EB10) {
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
	// addi r9,r11,-24092
	ctx.r9.s64 = r11.s64 + -24092;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// li r11,0
	r11.s64 = 0;
	// addi r8,r10,-23756
	ctx.r8.s64 = ctx.r10.s64 + -23756;
	// lwz r7,4(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// addi r4,r30,12
	ctx.r4.s64 = r30.s64 + 12;
	// lwz r6,8(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stw r6,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r6.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// sth r11,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r11.u16);
	// sth r11,18(r31)
	PPC_STORE_U16(r31.u32 + 18, r11.u16);
	// bl 0x8253e7e0
	ctx.lr = 0x8253EB70;
	sub_8253E7E0(ctx, base);
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r5.u32);
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

__attribute__((alias("__imp__sub_8253EB94"))) PPC_WEAK_FUNC(sub_8253EB94);
PPC_FUNC_IMPL(__imp__sub_8253EB94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253EB98"))) PPC_WEAK_FUNC(sub_8253EB98);
PPC_FUNC_IMPL(__imp__sub_8253EB98) {
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
	// addi r3,r31,12
	ctx.r3.s64 = r31.s64 + 12;
	// lhz r5,18(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 18);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x8253e878
	ctx.lr = 0x8253EBBC;
	sub_8253E878(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// sth r11,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r11.u16);
	// sth r11,18(r31)
	PPC_STORE_U16(r31.u32 + 18, r11.u16);
	// bl 0x8253daf8
	ctx.lr = 0x8253EBD4;
	sub_8253DAF8(ctx, base);
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

__attribute__((alias("__imp__sub_8253EBE8"))) PPC_WEAK_FUNC(sub_8253EBE8);
PPC_FUNC_IMPL(__imp__sub_8253EBE8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8253EBF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x8253ec2c
	if (cr6.eq) goto loc_8253EC2C;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// bl 0x8253e8e0
	ctx.lr = 0x8253EC18;
	sub_8253E8E0(ctx, base);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8253e3f8
	ctx.lr = 0x8253EC2C;
	sub_8253E3F8(ctx, base);
loc_8253EC2C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8253EC34"))) PPC_WEAK_FUNC(sub_8253EC34);
PPC_FUNC_IMPL(__imp__sub_8253EC34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253EC38"))) PPC_WEAK_FUNC(sub_8253EC38);
PPC_FUNC_IMPL(__imp__sub_8253EC38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8253EC40;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x8253ec7c
	if (cr6.eq) goto loc_8253EC7C;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// bl 0x8253e8e0
	ctx.lr = 0x8253EC68;
	sub_8253E8E0(ctx, base);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8253e4e0
	ctx.lr = 0x8253EC7C;
	sub_8253E4E0(ctx, base);
loc_8253EC7C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8253EC84"))) PPC_WEAK_FUNC(sub_8253EC84);
PPC_FUNC_IMPL(__imp__sub_8253EC84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8253EC88"))) PPC_WEAK_FUNC(sub_8253EC88);
PPC_FUNC_IMPL(__imp__sub_8253EC88) {
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
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
	// addi r10,r11,-23756
	ctx.r10.s64 = r11.s64 + -23756;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r5,18(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 18);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x8253e878
	ctx.lr = 0x8253ECC0;
	sub_8253E878(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r11,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r11.u16);
	// sth r11,18(r31)
	PPC_STORE_U16(r31.u32 + 18, r11.u16);
	// bl 0x8253daf8
	ctx.lr = 0x8253ECD8;
	sub_8253DAF8(ctx, base);
	// lhz r5,18(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 18);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8253ecf0
	if (cr6.eq) goto loc_8253ECF0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8253e878
	ctx.lr = 0x8253ECF0;
	sub_8253E878(ctx, base);
loc_8253ECF0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8253da60
	ctx.lr = 0x8253ECF8;
	sub_8253DA60(ctx, base);
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

__attribute__((alias("__imp__sub_8253ED10"))) PPC_WEAK_FUNC(sub_8253ED10);
PPC_FUNC_IMPL(__imp__sub_8253ED10) {
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
	ctx.lr = 0x8253ED2C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8253ed50
	if (cr6.eq) goto loc_8253ED50;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8253eb10
	ctx.lr = 0x8253ED3C;
	sub_8253EB10(ctx, base);
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
loc_8253ED50:
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

__attribute__((alias("__imp__sub_8253ED68"))) PPC_WEAK_FUNC(sub_8253ED68);
PPC_FUNC_IMPL(__imp__sub_8253ED68) {
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
	// bl 0x8253ec88
	ctx.lr = 0x8253ED88;
	sub_8253EC88(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8253eda0
	if (cr6.eq) goto loc_8253EDA0;
	// bl 0x82130588
	ctx.lr = 0x8253ED9C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8253EDA0:
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

__attribute__((alias("__imp__sub_8253EDB8"))) PPC_WEAK_FUNC(sub_8253EDB8);
PPC_FUNC_IMPL(__imp__sub_8253EDB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32114
	r11.s64 = -2104623104;
	// addi r3,r11,-32520
	ctx.r3.s64 = r11.s64 + -32520;
	// b 0x8253dd10
	sub_8253DD10(ctx, base);
	return;
}

