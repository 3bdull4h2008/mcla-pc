#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8275A69C"))) PPC_WEAK_FUNC(sub_8275A69C);
PPC_FUNC_IMPL(__imp__sub_8275A69C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275A6A0"))) PPC_WEAK_FUNC(sub_8275A6A0);
PPC_FUNC_IMPL(__imp__sub_8275A6A0) {
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
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275a6d8
	if (cr6.eq) goto loc_8275A6D8;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-21252(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21252);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275A6D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_8275A6D8:
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

__attribute__((alias("__imp__sub_8275A6EC"))) PPC_WEAK_FUNC(sub_8275A6EC);
PPC_FUNC_IMPL(__imp__sub_8275A6EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275A6F0"))) PPC_WEAK_FUNC(sub_8275A6F0);
PPC_FUNC_IMPL(__imp__sub_8275A6F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// fmr f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f1.f64;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// lfs f0,-23908(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -23908);
	f0.f64 = double(temp.f32);
	// fmuls f12,f2,f0
	ctx.f12.f64 = double(float(ctx.f2.f64 * f0.f64));
	// lfs f0,3464(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3464);
	f0.f64 = double(temp.f32);
	// fctiwz f12,f12
	ctx.f12.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f12,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f12.u64);
	// lwz r9,-12(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// ble cr6,0x8275a76c
	if (!cr6.gt) goto loc_8275A76C;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// lfs f12,11376(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11376);
	ctx.f12.f64 = double(temp.f32);
loc_8275A72C:
	// lfs f11,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// fadds f11,f11,f13
	ctx.f11.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// stfs f11,0(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fadds f13,f13,f1
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f1.f64));
	// blt cr6,0x8275a748
	if (cr6.lt) goto loc_8275A748;
	// fadds f0,f0,f12
	f0.f64 = double(float(f0.f64 + ctx.f12.f64));
loc_8275A748:
	// clrlwi. r8,r11,31
	ctx.r8.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne 0x8275a75c
	if (!cr0.eq) goto loc_8275A75C;
	// lfs f11,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fadds f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 + f0.f64));
	// stfs f11,0(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
loc_8275A75C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// blt cr6,0x8275a72c
	if (cr6.lt) goto loc_8275A72C;
loc_8275A76C:
	// addi r11,r4,3
	r11.s64 = ctx.r4.s64 + 3;
	// srawi. r10,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r10.s64 = r11.s32 >> 2;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blelr 
	if (!cr0.gt) return;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
loc_8275A77C:
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// vexptefp128 v63,v63
	ctx.fpscr.enableFlushMode();
	v63.f32[0] = exp2f(v63.f32[0]);
	v63.f32[1] = exp2f(v63.f32[1]);
	v63.f32[2] = exp2f(v63.f32[2]);
	v63.f32[3] = exp2f(v63.f32[3]);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x8275a77c
	if (!cr0.eq) goto loc_8275A77C;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275A798"))) PPC_WEAK_FUNC(sub_8275A798);
PPC_FUNC_IMPL(__imp__sub_8275A798) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f0{};
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
	ctx.lr = 0x8275A7A0;
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823db9cc
	ctx.lr = 0x8275A7A8;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r23,r10
	r23.u64 = ctx.r10.u64;
	// fmr f26,f3
	f26.f64 = ctx.f3.f64;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// fmr f25,f4
	f25.f64 = ctx.f4.f64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// fmr f28,f5
	f28.f64 = ctx.f5.f64;
	// mr r18,r4
	r18.u64 = ctx.r4.u64;
	// lfs f30,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f30.f64 = double(temp.f32);
	// mr r19,r5
	r19.u64 = ctx.r5.u64;
	// mr r17,r6
	r17.u64 = ctx.r6.u64;
	// lfs f0,-23584(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -23584);
	f0.f64 = double(temp.f32);
	// mr r24,r9
	r24.u64 = ctx.r9.u64;
	// fmuls f13,f29,f30
	ctx.f13.f64 = double(float(f29.f64 * f30.f64));
	// fdivs f31,f0,f29
	f31.f64 = double(float(f0.f64 / f29.f64));
	// fctiwz f0,f13
	f0.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, f0.u64);
	// lwz r31,116(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// extsw r11,r31
	r11.s64 = r31.s32;
	// std r11,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, r11.u64);
	// lfd f0,112(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// frsp f0,f0
	f0.f64 = double(float(f0.f64));
	// fmadds f0,f0,f31,f30
	f0.f64 = double(float(f0.f64 * f31.f64 + f30.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, f0.u64);
	// lwz r11,116(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// cmpwi cr6,r11,256
	cr6.compare<int32_t>(r11.s32, 256, xer);
	// blt cr6,0x8275a828
	if (cr6.lt) goto loc_8275A828;
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_8275A828:
	// cmpwi cr6,r31,100
	cr6.compare<int32_t>(r31.s32, 100, xer);
	// ble cr6,0x8275a834
	if (!cr6.gt) goto loc_8275A834;
	// li r31,100
	r31.s64 = 100;
loc_8275A834:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f13,-740(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -740);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f2,f13
	f0.f64 = double(float(ctx.f2.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8275a858
	if (!cr6.lt) goto loc_8275A858;
	// li r11,100
	r11.s64 = 100;
	// twllei r31,0
	// divw r27,r11,r31
	r27.s32 = r11.s32 / r31.s32;
	// b 0x8275a85c
	goto loc_8275A85C;
loc_8275A858:
	// li r27,1
	r27.s64 = 1;
loc_8275A85C:
	// fmuls f13,f0,f29
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f0.f64 * f29.f64));
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// extsw r11,r27
	r11.s64 = r27.s32;
	// mullw r21,r27,r31
	r21.s64 = int64_t(r27.s32) * int64_t(r31.s32);
	// std r11,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, r11.u64);
	// lfd f12,112(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// lfs f0,11384(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11384);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r28,0
	r28.s64 = 0;
	// addi r22,r11,11324
	r22.s64 = r11.s64 + 11324;
	// addi r11,r22,28
	r11.s64 = r22.s64 + 28;
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, f0.u64);
	// fcfid f0,f12
	f0.f64 = double(ctx.f12.s64);
	// frsp f0,f0
	f0.f64 = double(float(f0.f64));
	// lwz r29,116(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// mullw r20,r29,r27
	r20.s64 = int64_t(r29.s32) * int64_t(r27.s32);
	// fdivs f27,f31,f0
	f27.f64 = double(float(f31.f64 / f0.f64));
loc_8275A8A8:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f29,f0
	cr6.compare(f29.f64, f0.f64);
	// bgt cr6,0x8275a8cc
	if (cr6.gt) goto loc_8275A8CC;
	// addi r10,r22,28
	ctx.r10.s64 = r22.s64 + 28;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8275a8a8
	if (cr6.lt) goto loc_8275A8A8;
loc_8275A8CC:
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// bl 0x82758910
	ctx.lr = 0x8275A8D4;
	sub_82758910(ctx, base);
	// addi r11,r22,4
	r11.s64 = r22.s64 + 4;
	// lwz r30,388(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// rlwinm r7,r28,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r25,396(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// fmr f4,f28
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = f28.f64;
	// mr r10,r24
	ctx.r10.u64 = r24.u64;
	// stw r23,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r23.u32);
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// fmr f3,f27
	ctx.f3.f64 = f27.f64;
	// mr r8,r19
	ctx.r8.u64 = r19.u64;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// lfsx f0,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// fmadds f13,f1,f30,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * f30.f64 + f0.f64));
	// lfs f0,11372(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 11372);
	f0.f64 = double(temp.f32);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fsubs f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 - f0.f64));
	// bl 0x8275c450
	ctx.lr = 0x8275A924;
	sub_8275C450(ctx, base);
	// lfs f13,8(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// fadds f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 + f31.f64));
	// lfs f11,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,11380(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11380);
	f0.f64 = double(temp.f32);
	// lfs f12,12160(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12160);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f13,f13,f0,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f11.f64));
	// fmuls f0,f13,f12
	f0.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// ble cr6,0x8275a96c
	if (!cr6.gt) goto loc_8275A96C;
	// fadds f0,f0,f30
	f0.f64 = double(float(f0.f64 + f30.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, f0.u64);
	// lwz r11,116(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// b 0x8275a97c
	goto loc_8275A97C;
loc_8275A96C:
	// fsubs f0,f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 - f30.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, f0.u64);
	// lwz r11,116(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
loc_8275A97C:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// stfs f31,8(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r26.u32 + 8, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// std r11,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, r11.u64);
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lfd f0,112(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// frsp f12,f0
	ctx.f12.f64 = double(float(f0.f64));
	// lfs f0,18204(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 18204);
	f0.f64 = double(temp.f32);
	// fnmsubs f1,f12,f0,f13
	ctx.f1.f64 = double(float(-(ctx.f12.f64 * f0.f64 - ctx.f13.f64)));
	// stfs f1,0(r26)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
	// bl 0x8275a6f0
	ctx.lr = 0x8275A9B8;
	sub_8275A6F0(ctx, base);
	// addi r11,r31,-1
	r11.s64 = r31.s64 + -1;
	// addi r10,r21,-1
	ctx.r10.s64 = r21.s64 + -1;
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// blt cr6,0x8275aa2c
	if (cr6.lt) goto loc_8275AA2C;
	// subf r9,r29,r11
	ctx.r9.s64 = r11.s64 - r29.s64;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r27,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r8,r30
	ctx.r9.u64 = ctx.r8.u64 + r30.u64;
	// add r7,r7,r30
	ctx.r7.u64 = ctx.r7.u64 + r30.u64;
	// subf r3,r30,r25
	ctx.r3.s64 = r25.s64 - r30.s64;
	// subf r11,r6,r11
	r11.s64 = r11.s64 - ctx.r6.s64;
loc_8275A9EC:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x8275aa20
	if (!cr6.gt) goto loc_8275AA20;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// subf r10,r27,r10
	ctx.r10.s64 = ctx.r10.s64 - r27.s64;
	// subf r9,r4,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r4.s64;
loc_8275AA04:
	// lfsx f0,r7,r3
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	f0.f64 = double(temp.f32);
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// stfsx f0,r3,r8
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + ctx.r8.u32, temp.u32);
	// lfs f0,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r8,r8,-4
	ctx.r8.s64 = ctx.r8.s64 + -4;
	// bne 0x8275aa04
	if (!cr0.eq) goto loc_8275AA04;
loc_8275AA20:
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// addi r7,r7,-4
	ctx.r7.s64 = ctx.r7.s64 + -4;
	// bne 0x8275a9ec
	if (!cr0.eq) goto loc_8275A9EC;
loc_8275AA2C:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8275aa90
	if (cr6.lt) goto loc_8275AA90;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r6,r30,r25
	ctx.r6.s64 = r25.s64 - r30.s64;
	// add r7,r9,r30
	ctx.r7.u64 = ctx.r9.u64 + r30.u64;
loc_8275AA40:
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r7,r6
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	f0.f64 = double(temp.f32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmpwi cr6,r27,1
	cr6.compare<int32_t>(r27.s32, 1, xer);
	// stfsx f0,r9,r25
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + r25.u32, temp.u32);
	// lfs f0,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfsx f0,r9,r30
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + r30.u32, temp.u32);
	// ble cr6,0x8275aa84
	if (!cr6.gt) goto loc_8275AA84;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r27,-1
	ctx.r9.s64 = r27.s64 + -1;
	// add r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 + r30.u64;
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
loc_8275AA70:
	// stfsx f10,r8,r6
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r8.u32 + ctx.r6.u32, temp.u32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stfs f10,0(r8)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r8,r8,-4
	ctx.r8.s64 = ctx.r8.s64 + -4;
	// bne 0x8275aa70
	if (!cr0.eq) goto loc_8275AA70;
loc_8275AA84:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r7,r7,-4
	ctx.r7.s64 = ctx.r7.s64 + -4;
	// bge 0x8275aa40
	if (!cr0.lt) goto loc_8275AA40;
loc_8275AA90:
	// cmpw cr6,r20,r21
	cr6.compare<int32_t>(r20.s32, r21.s32, xer);
	// bge cr6,0x8275ab14
	if (!cr6.lt) goto loc_8275AB14;
	// rlwinm r10,r20,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,428(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 428);
	// lfs f0,0(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r22.u32 + 0);
	f0.f64 = double(temp.f32);
	// subf r11,r20,r21
	r11.s64 = r21.s64 - r20.s64;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
loc_8275AAAC:
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// srawi r9,r7,16
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r7.s32 >> 16;
	// clrlwi r7,r7,16
	ctx.r7.u64 = ctx.r7.u32 & 0xFFFF;
	// mulli r6,r9,16807
	ctx.r6.s64 = ctx.r9.s64 * 16807;
	// mulli r7,r7,16807
	ctx.r7.s64 = ctx.r7.s64 * 16807;
	// rlwinm r9,r6,16,1,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0x7FFF0000;
	// rlwinm r6,r6,17,15,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 17) & 0x1FFFF;
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// rlwinm r7,r9,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// clrlwi r9,r9,1
	ctx.r9.u64 = ctx.r9.u32 & 0x7FFFFFFF;
	// add r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 + ctx.r7.u64;
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
	// rlwinm r7,r9,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
	// clrlwi r9,r9,1
	ctx.r9.u64 = ctx.r9.u32 & 0x7FFFFFFF;
	// extsw r7,r9
	ctx.r7.s64 = ctx.r9.s32;
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// std r7,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r7.u64);
	// lfd f13,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x8275aaac
	if (!cr0.eq) goto loc_8275AAAC;
loc_8275AB14:
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// mtctr r21
	ctr.u64 = r21.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// lfs f13,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// ble cr6,0x8275ab78
	if (!cr6.gt) goto loc_8275AB78;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// mr r11,r21
	r11.u64 = r21.u64;
loc_8275AB34:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// fadds f10,f10,f0
	ctx.f10.f64 = double(float(ctx.f10.f64 + f0.f64));
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x8275ab34
	if (!cr0.eq) goto loc_8275AB34;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f0,12892(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12892);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f10,f0
	cr6.compare(ctx.f10.f64, f0.f64);
	// ble cr6,0x8275ab5c
	if (!cr6.gt) goto loc_8275AB5C;
	// fdivs f13,f0,f10
	ctx.f13.f64 = double(float(f0.f64 / ctx.f10.f64));
loc_8275AB5C:
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// ble cr6,0x8275ab78
	if (!cr6.gt) goto loc_8275AB78;
loc_8275AB64:
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f0,0(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x8275ab64
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8275AB64;
loc_8275AB78:
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// fmr f3,f25
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f25.f64;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// fmr f2,f26
	ctx.f2.f64 = f26.f64;
	// mr r8,r17
	ctx.r8.u64 = r17.u64;
	// fmr f1,f27
	ctx.f1.f64 = f27.f64;
	// mr r7,r19
	ctx.r7.u64 = r19.u64;
	// mr r6,r18
	ctx.r6.u64 = r18.u64;
	// li r5,160
	ctx.r5.s64 = 160;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// bl 0x82756728
	ctx.lr = 0x8275ABA4;
	sub_82756728(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823dba18
	ctx.lr = 0x8275ABB0;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_8275ABB4"))) PPC_WEAK_FUNC(sub_8275ABB4);
PPC_FUNC_IMPL(__imp__sub_8275ABB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275ABB8"))) PPC_WEAK_FUNC(sub_8275ABB8);
PPC_FUNC_IMPL(__imp__sub_8275ABB8) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8275ABC0;
	// extsw r11,r6
	r11.s64 = ctx.r6.s32;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// std r11,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, r11.u64);
	// lfd f0,-64(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lfs f0,-23584(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -23584);
	f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fdivs f11,f0,f1
	ctx.f11.f64 = double(float(f0.f64 / ctx.f1.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,6332(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 6332);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f0,f11,f0,f13
	f0.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f13.f64));
	// fdivs f13,f12,f11
	ctx.f13.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f0.u64);
	// lwz r30,-60(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + -60);
	// fctiwz f0,f13
	f0.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f0.u64);
	// lwz r27,-60(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + -60);
	// srawi r29,r30,1
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x1) != 0);
	r29.s64 = r30.s32 >> 1;
	// addi r11,r29,16384
	r11.s64 = r29.s64 + 16384;
	// cmpwi cr6,r27,1
	cr6.compare<int32_t>(r27.s32, 1, xer);
	// srawi r31,r11,15
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7FFF) != 0);
	r31.s64 = r11.s32 >> 15;
	// blt cr6,0x8275ad74
	if (cr6.lt) goto loc_8275AD74;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r8,16384
	ctx.r8.s64 = 16384;
	// mr r26,r27
	r26.u64 = r27.u64;
	// addi r28,r11,12880
	r28.s64 = r11.s64 + 12880;
	// lfs f9,13776(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 13776);
	ctx.f9.f64 = double(temp.f32);
loc_8275AC44:
	// add r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 + r30.u64;
	// fmr f0,f9
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f9.f64;
	// mr r11,r31
	r11.u64 = r31.u64;
	// add r10,r8,r29
	ctx.r10.u64 = ctx.r8.u64 + r29.u64;
	// addi r9,r8,-15872
	ctx.r9.s64 = ctx.r8.s64 + -15872;
	// srawi r31,r10,15
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFF) != 0);
	r31.s64 = ctx.r10.s32 >> 15;
	// srawi r10,r8,15
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFF) != 0);
	ctx.r10.s64 = ctx.r8.s32 >> 15;
	// rlwinm r7,r11,5,0,26
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r10,r9,10
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3FF) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 10;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r10,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r10.s64;
	// add r7,r9,r4
	ctx.r7.u64 = ctx.r9.u64 + ctx.r4.u64;
	// lfsx f12,r6,r4
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r4.u32);
	ctx.f12.f64 = double(temp.f32);
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// lfsx f11,r6,r5
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r5.u32);
	ctx.f11.f64 = double(temp.f32);
	// cmpwi cr6,r10,-112
	cr6.compare<int32_t>(ctx.r10.s32, -112, xer);
	// bgt cr6,0x8275acc8
	if (cr6.gt) goto loc_8275ACC8;
	// subfic r6,r10,-112
	xer.ca = ctx.r10.u32 <= 4294967184;
	ctx.r6.s64 = -112 - ctx.r10.s64;
	// rlwinm r6,r6,27,5,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x7FFFFFF;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// rlwinm r3,r6,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r6,r11
	r11.u64 = ctx.r6.u64 + r11.u64;
	// add r10,r3,r10
	ctx.r10.u64 = ctx.r3.u64 + ctx.r10.u64;
loc_8275ACA4:
	// lfs f13,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// fmuls f13,f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// lfs f8,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// fmadds f13,f8,f8,f13
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f13.f64));
	// fadds f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 + f0.f64));
	// bne 0x8275aca4
	if (!cr0.eq) goto loc_8275ACA4;
loc_8275ACC8:
	// fmr f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f0.f64;
	// cmpwi cr6,r10,112
	cr6.compare<int32_t>(ctx.r10.s32, 112, xer);
	// bge cr6,0x8275ad30
	if (!cr6.lt) goto loc_8275AD30;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r28,448
	ctx.r10.s64 = r28.s64 + 448;
	// add r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 + ctx.r10.u64;
loc_8275ACE0:
	// cmpw cr6,r11,r31
	cr6.compare<int32_t>(r11.s32, r31.s32, xer);
	// bge cr6,0x8275ad64
	if (!cr6.lt) goto loc_8275AD64;
	// lfs f8,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// addi r6,r28,896
	ctx.r6.s64 = r28.s64 + 896;
	// lfs f7,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f8,f8
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fnmsubs f8,f7,f12,f8
	ctx.f8.f64 = double(float(-(ctx.f7.f64 * ctx.f12.f64 - ctx.f8.f64)));
	// lfs f5,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// fnmsubs f7,f7,f11,f5
	ctx.f7.f64 = double(float(-(ctx.f7.f64 * ctx.f11.f64 - ctx.f5.f64)));
	// addi r10,r10,128
	ctx.r10.s64 = ctx.r10.s64 + 128;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// fmadds f6,f5,f5,f6
	ctx.f6.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f6.f64));
	// fmuls f8,f8,f8
	ctx.f8.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fadds f0,f6,f0
	f0.f64 = double(float(ctx.f6.f64 + f0.f64));
	// fmadds f8,f7,f7,f8
	ctx.f8.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f8.f64));
	// fadds f13,f8,f13
	ctx.f13.f64 = double(float(ctx.f8.f64 + ctx.f13.f64));
	// blt cr6,0x8275ace0
	if (cr6.lt) goto loc_8275ACE0;
loc_8275AD30:
	// cmpw cr6,r11,r31
	cr6.compare<int32_t>(r11.s32, r31.s32, xer);
	// bge cr6,0x8275ad64
	if (!cr6.lt) goto loc_8275AD64;
	// subf r11,r11,r31
	r11.s64 = r31.s64 - r11.s64;
loc_8275AD3C:
	// lfs f12,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// fmuls f12,f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// lfs f11,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// fmadds f12,f11,f11,f12
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f12.f64));
	// fadds f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 + f0.f64));
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// bne 0x8275ad3c
	if (!cr0.eq) goto loc_8275AD3C;
loc_8275AD64:
	// fdivs f0,f13,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f13.f64 / f0.f64));
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// fadds f10,f0,f10
	ctx.f10.f64 = double(float(f0.f64 + ctx.f10.f64));
	// bne 0x8275ac44
	if (!cr0.eq) goto loc_8275AC44;
loc_8275AD74:
	// extsw r11,r27
	r11.s64 = r27.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, r11.u64);
	// lfd f0,-64(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// frsp f13,f0
	ctx.f13.f64 = double(float(f0.f64));
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fdivs f13,f10,f13
	ctx.f13.f64 = double(float(ctx.f10.f64 / ctx.f13.f64));
	// fsubs f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 - ctx.f13.f64));
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8275AD9C"))) PPC_WEAK_FUNC(sub_8275AD9C);
PPC_FUNC_IMPL(__imp__sub_8275AD9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275ADA0"))) PPC_WEAK_FUNC(sub_8275ADA0);
PPC_FUNC_IMPL(__imp__sub_8275ADA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,-23584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -23584);
	f0.f64 = double(temp.f32);
	// fdivs f12,f0,f1
	ctx.f12.f64 = double(float(f0.f64 / ctx.f1.f64));
	// lfs f0,13780(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 13780);
	f0.f64 = double(temp.f32);
	// lfs f13,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f12,f0,f13
	f0.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f13.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f0.u64);
	// lwz r11,-12(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// ble cr6,0x8275add8
	if (!cr6.gt) goto loc_8275ADD8;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_8275ADD8:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275ADE0"))) PPC_WEAK_FUNC(sub_8275ADE0);
PPC_FUNC_IMPL(__imp__sub_8275ADE0) {
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8275ADE8;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823db9d8
	ctx.lr = 0x8275ADF0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lfs f31,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f31.f64 = double(temp.f32);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lfs f30,13788(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 13788);
	f30.f64 = double(temp.f32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lfs f28,-32024(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -32024);
	f28.f64 = double(temp.f32);
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// lfs f29,28900(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 28900);
	f29.f64 = double(temp.f32);
	// li r27,0
	r27.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// li r11,73
	r11.s64 = 73;
	// addi r29,r10,5160
	r29.s64 = ctx.r10.s64 + 5160;
loc_8275AE34:
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82758450
	ctx.lr = 0x8275AE48;
	sub_82758450(ctx, base);
	// fmuls f13,f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f31.f64 * f29.f64));
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8275aeec
	if (cr6.lt) goto loc_8275AEEC;
	// fmuls f13,f31,f28
	ctx.f13.f64 = double(float(f31.f64 * f28.f64));
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8275ae70
	if (cr6.lt) goto loc_8275AE70;
	// mr r27,r31
	r27.u64 = r31.u64;
loc_8275AE70:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// fmr f31,f0
	ctx.fpscr.disableFlushMode();
	f31.f64 = f0.f64;
	// lfs f12,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// lfs f13,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f30
	f0.f64 = double(float(ctx.f13.f64 * f30.f64));
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// blt cr6,0x8275aeec
	if (cr6.lt) goto loc_8275AEEC;
	// b 0x8275aea8
	goto loc_8275AEA8;
loc_8275AE9C:
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
loc_8275AEA8:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x8275ae9c
	if (cr6.gt) goto loc_8275AE9C;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8275aeec
	if (cr6.lt) goto loc_8275AEEC;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + r28.u64;
loc_8275AEC0:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8275aedc
	if (!cr6.lt) goto loc_8275AEDC;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// bge 0x8275aec0
	if (!cr0.lt) goto loc_8275AEC0;
loc_8275AEDC:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8275aeec
	if (cr6.lt) goto loc_8275AEEC;
	// cmpwi cr6,r31,5
	cr6.compare<int32_t>(r31.s32, 5, xer);
	// blt cr6,0x8275ae34
	if (cr6.lt) goto loc_8275AE34;
loc_8275AEEC:
	// stw r27,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r27.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba24
	ctx.lr = 0x8275AF00;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8275AF04"))) PPC_WEAK_FUNC(sub_8275AF04);
PPC_FUNC_IMPL(__imp__sub_8275AF04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275AF08"))) PPC_WEAK_FUNC(sub_8275AF08);
PPC_FUNC_IMPL(__imp__sub_8275AF08) {
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
	ctx.lr = 0x8275AF10;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r9,r11,5160
	ctx.r9.s64 = r11.s64 + 5160;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r30,0(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r29
	r11.u64 = ctx.r10.u64 + r29.u64;
	// lfs f0,27632(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 27632);
	f0.f64 = double(temp.f32);
	// lwz r26,0(r27)
	r26.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r31,-4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// lfsx f12,r11,r9
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bgt cr6,0x8275b038
	if (cr6.gt) goto loc_8275B038;
	// lfsx f11,r11,r3
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	ctx.f11.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f0,31308(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31308);
	f0.f64 = double(temp.f32);
	// lfs f13,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fmuls f0,f12,f13
	f0.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
loc_8275AF78:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x8275af78
	if (cr6.lt) goto loc_8275AF78;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r3
	r11.u64 = ctx.r10.u64 + ctx.r3.u64;
	// lfs f0,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x8275afb0
	if (!cr6.lt) goto loc_8275AFB0;
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x8275afb0
	if (!cr6.lt) goto loc_8275AFB0;
	// li r8,1
	ctx.r8.s64 = 1;
loc_8275AFB0:
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// add r11,r10,r9
	r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lfs f0,30712(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 30712);
	f0.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 * f0.f64));
loc_8275AFC0:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x8275afc0
	if (cr6.lt) goto loc_8275AFC0;
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r3
	ctx.r3.u64 = r11.u64 + ctx.r3.u64;
	// lfs f0,-4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -4);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x8275aff8
	if (!cr6.lt) goto loc_8275AFF8;
	// lfs f0,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x8275aff8
	if (!cr6.lt) goto loc_8275AFF8;
	// li r8,1
	ctx.r8.s64 = 1;
loc_8275AFF8:
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// bne cr6,0x8275b038
	if (!cr6.eq) goto loc_8275B038;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// bne cr6,0x8275b028
	if (!cr6.eq) goto loc_8275B028;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// subfic r4,r31,74
	xer.ca = r31.u32 <= 74;
	ctx.r4.s64 = 74 - r31.s64;
	// bl 0x82758450
	ctx.lr = 0x8275B018;
	sub_82758450(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// b 0x8275b038
	goto loc_8275B038;
loc_8275B028:
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// cmpw cr6,r26,r30
	cr6.compare<int32_t>(r26.s32, r30.s32, xer);
	// bne cr6,0x8275b038
	if (!cr6.eq) goto loc_8275B038;
	// li r26,0
	r26.s64 = 0;
loc_8275B038:
	// stw r26,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r26.u32);
	// stw r30,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r30.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8275B048"))) PPC_WEAK_FUNC(sub_8275B048);
PPC_FUNC_IMPL(__imp__sub_8275B048) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
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
	// bl 0x823d91c4
	ctx.lr = 0x8275B050;
	// addi r12,r1,-144
	r12.s64 = ctx.r1.s64 + -144;
	// bl 0x823db9d0
	ctx.lr = 0x8275B058;
	// stwu r1,-624(r1)
	ea = -624 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r17,r4
	r17.u64 = ctx.r4.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// fmr f27,f2
	f27.f64 = ctx.f2.f64;
	// mr r16,r5
	r16.u64 = ctx.r5.u64;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// mr r15,r6
	r15.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// bl 0x827583c0
	ctx.lr = 0x8275B088;
	sub_827583C0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r31,0
	r31.s64 = 0;
	// lfs f0,14196(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14196);
	f0.f64 = double(temp.f32);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// fadds f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 + f0.f64));
	// lfs f0,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	f0.f64 = double(temp.f32);
	// addi r19,r11,5160
	r19.s64 = r11.s64 + 5160;
	// fdivs f26,f0,f13
	f26.f64 = double(float(f0.f64 / ctx.f13.f64));
loc_8275B0AC:
	// mr r7,r17
	ctx.r7.u64 = r17.u64;
	// lfsx f1,r31,r19
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + r19.u32);
	ctx.f1.f64 = double(temp.f32);
	// mr r6,r18
	ctx.r6.u64 = r18.u64;
	// fmr f2,f26
	ctx.f2.f64 = f26.f64;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// bl 0x8275c5b8
	ctx.lr = 0x8275B0C8;
	sub_8275C5B8(ctx, base);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// stfsx f1,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + r11.u32, temp.u32);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// cmpwi cr6,r31,296
	cr6.compare<int32_t>(r31.s32, 296, xer);
	// blt cr6,0x8275b0ac
	if (cr6.lt) goto loc_8275B0AC;
	// addi r11,r1,132
	r11.s64 = ctx.r1.s64 + 132;
	// li r10,37
	ctx.r10.s64 = 37;
loc_8275B0E4:
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	f0.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x8275b0e4
	if (!cr0.eq) goto loc_8275B0E4;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f12,0(r19)
	temp.u32 = PPC_LOAD_U32(r19.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// lfs f0,-13148(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13148);
	f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	f0.f64 = double(float(f31.f64 * f0.f64));
	// lfs f13,13784(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 13784);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f31,f13
	ctx.f11.f64 = double(float(f31.f64 * ctx.f13.f64));
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x8275b138
	if (!cr6.lt) goto loc_8275B138;
	// mr r10,r19
	ctx.r10.u64 = r19.u64;
loc_8275B124:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x8275b124
	if (cr6.lt) goto loc_8275B124;
loc_8275B138:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// mr r21,r11
	r21.u64 = r11.u64;
	// lfsx f0,r10,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	f0.f64 = double(temp.f32);
loc_8275B148:
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfsx f13,r10,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8275b160
	if (!cr6.lt) goto loc_8275B160;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// mr r21,r11
	r21.u64 = r11.u64;
loc_8275B160:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r10,296
	cr6.compare<int32_t>(ctx.r10.s32, 296, xer);
	// bge cr6,0x8275b17c
	if (!cr6.lt) goto loc_8275B17C;
	// lfsx f13,r10,r19
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r19.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// ble cr6,0x8275b148
	if (!cr6.gt) goto loc_8275B148;
loc_8275B17C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fcmpu cr6,f27,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f27.f64, f0.f64);
	// lfs f28,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f28.f64 = double(temp.f32);
	// ble cr6,0x8275b194
	if (!cr6.gt) goto loc_8275B194;
	// fadds f0,f0,f27
	f0.f64 = double(float(f0.f64 + f27.f64));
	// fmuls f0,f0,f28
	f0.f64 = double(float(f0.f64 * f28.f64));
loc_8275B194:
	// rlwinm r30,r21,2,0,29
	r30.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r1,128
	r31.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfsx f31,r30,r31
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + r31.u32);
	f31.f64 = double(temp.f32);
	// stfsx f0,r30,r31
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + r31.u32, temp.u32);
	// bl 0x8275ade0
	ctx.lr = 0x8275B1B4;
	sub_8275ADE0(ctx, base);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8275af08
	ctx.lr = 0x8275B1CC;
	sub_8275AF08(ctx, base);
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r20,r7
	r20.u64 = ctx.r7.u64;
	// mr r23,r11
	r23.u64 = r11.u64;
	// ble cr6,0x8275b218
	if (!cr6.gt) goto loc_8275B218;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
loc_8275B1F0:
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r21,r8
	cr6.compare<int32_t>(r21.s32, ctx.r8.s32, xer);
	// bne cr6,0x8275b204
	if (!cr6.eq) goto loc_8275B204;
	// li r6,1
	ctx.r6.s64 = 1;
	// cmpw cr6,r21,r8
	cr6.compare<int32_t>(r21.s32, ctx.r8.s32, xer);
loc_8275B204:
	// bgt cr6,0x8275b218
	if (cr6.gt) goto loc_8275B218;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x8275b1f0
	if (cr6.lt) goto loc_8275B1F0;
loc_8275B218:
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// bne cr6,0x8275b2d0
	if (!cr6.eq) goto loc_8275B2D0;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r30,r31
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + r31.u32);
	f0.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// lwzx r9,r9,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f13,-32024(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -32024);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r9,r6
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// bne cr6,0x8275b274
	if (!cr6.eq) goto loc_8275B274;
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f12,13792(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 13792);
	ctx.f12.f64 = double(temp.f32);
	// lfsx f11,r9,r8
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f12,f11,f12
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x8275b284
	if (!cr6.lt) goto loc_8275B284;
loc_8275B274:
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// ble cr6,0x8275b2d0
	if (!cr6.gt) goto loc_8275B2D0;
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8275b2d0
	if (cr6.lt) goto loc_8275B2D0;
loc_8275B284:
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// ble cr6,0x8275b2b4
	if (!cr6.gt) goto loc_8275B2B4;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// subf r8,r10,r11
	ctx.r8.s64 = r11.s64 - ctx.r10.s64;
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
loc_8275B29C:
	// lwz r6,-4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// addi r7,r9,-4
	ctx.r7.s64 = ctx.r9.s64 + -4;
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stw r6,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// bne 0x8275b29c
	if (!cr0.eq) goto loc_8275B29C;
loc_8275B2B4:
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f13.f64);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stwx r21,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r21.u32);
	// blt cr6,0x8275b2cc
	if (cr6.lt) goto loc_8275B2CC;
	// mr r20,r10
	r20.u64 = ctx.r10.u64;
loc_8275B2CC:
	// addi r23,r11,1
	r23.s64 = r11.s64 + 1;
loc_8275B2D0:
	// stfsx f31,r30,r31
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + r31.u32, temp.u32);
	// li r25,0
	r25.s64 = 0;
	// addi r22,r23,-1
	r22.s64 = r23.s64 + -1;
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// ble cr6,0x8275b400
	if (!cr6.gt) goto loc_8275B400;
	// addi r27,r1,96
	r27.s64 = ctx.r1.s64 + 96;
	// subf r24,r26,r29
	r24.s64 = r29.s64 - r26.s64;
loc_8275B2F0:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x8275b308
	if (cr6.eq) goto loc_8275B308;
	// cmpw cr6,r28,r22
	cr6.compare<int32_t>(r28.s32, r22.s32, xer);
	// beq cr6,0x8275b308
	if (cr6.eq) goto loc_8275B308;
	// cmpw cr6,r28,r20
	cr6.compare<int32_t>(r28.s32, r20.s32, xer);
	// bne cr6,0x8275b3f0
	if (!cr6.eq) goto loc_8275B3F0;
loc_8275B308:
	// cmpw cr6,r28,r20
	cr6.compare<int32_t>(r28.s32, r20.s32, xer);
	// bne cr6,0x8275b318
	if (!cr6.eq) goto loc_8275B318;
	// lwz r11,708(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 708);
	// stw r25,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r25.u32);
loc_8275B318:
	// lwz r30,0(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// li r11,0
	r11.s64 = 0;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// add r9,r10,r19
	ctx.r9.u64 = ctx.r10.u64 + r19.u64;
	// lfsx f31,r10,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	f31.f64 = double(temp.f32);
	// lfsx f29,r10,r19
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r19.u32);
	f29.f64 = double(temp.f32);
	// ble cr6,0x8275b350
	if (!cr6.gt) goto loc_8275B350;
	// lfs f0,-4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fadds f0,f0,f29
	f0.f64 = double(float(f0.f64 + f29.f64));
	// fmuls f0,f0,f28
	f0.f64 = double(float(f0.f64 * f28.f64));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_8275B350:
	// addi r10,r30,1
	ctx.r10.s64 = r30.s64 + 1;
	// cmpwi cr6,r10,74
	cr6.compare<int32_t>(ctx.r10.s32, 74, xer);
	// bge cr6,0x8275b37c
	if (!cr6.lt) goto loc_8275B37C;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lfsx f0,r10,r19
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r19.u32);
	f0.f64 = double(temp.f32);
	// fadds f0,f0,f29
	f0.f64 = double(float(f0.f64 + f29.f64));
	// fmuls f0,f0,f28
	f0.f64 = double(float(f0.f64 * f28.f64));
	// stfsx f0,r9,r8
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, temp.u32);
loc_8275B37C:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8275b3c8
	if (!cr6.gt) goto loc_8275B3C8;
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// mr r29,r11
	r29.u64 = r11.u64;
loc_8275B38C:
	// lfs f30,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f30.f64 = double(temp.f32);
	// mr r7,r17
	ctx.r7.u64 = r17.u64;
	// mr r6,r18
	ctx.r6.u64 = r18.u64;
	// fmr f2,f26
	ctx.f2.f64 = f26.f64;
	// mr r5,r15
	ctx.r5.u64 = r15.u64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// bl 0x8275c5b8
	ctx.lr = 0x8275B3AC;
	sub_8275C5B8(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x8275b3bc
	if (!cr6.gt) goto loc_8275B3BC;
	// fmr f29,f30
	f29.f64 = f30.f64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
loc_8275B3BC:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x8275b38c
	if (!cr0.eq) goto loc_8275B38C;
loc_8275B3C8:
	// stfsx f29,r24,r26
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r24.u32 + r26.u32, temp.u32);
	// cmpw cr6,r30,r21
	cr6.compare<int32_t>(r30.s32, r21.s32, xer);
	// bne cr6,0x8275b3e4
	if (!cr6.eq) goto loc_8275B3E4;
	// fcmpu cr6,f27,f31
	cr6.compare(f27.f64, f31.f64);
	// ble cr6,0x8275b3e4
	if (!cr6.gt) goto loc_8275B3E4;
	// fadds f0,f31,f27
	f0.f64 = double(float(f31.f64 + f27.f64));
	// fmuls f31,f0,f28
	f31.f64 = double(float(f0.f64 * f28.f64));
loc_8275B3E4:
	// stfs f31,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
loc_8275B3F0:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// cmpw cr6,r28,r23
	cr6.compare<int32_t>(r28.s32, r23.s32, xer);
	// blt cr6,0x8275b2f0
	if (cr6.lt) goto loc_8275B2F0;
loc_8275B400:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,624
	ctx.r1.s64 = ctx.r1.s64 + 624;
	// addi r12,r1,-144
	r12.s64 = ctx.r1.s64 + -144;
	// bl 0x823dba1c
	ctx.lr = 0x8275B410;
	// b 0x823d9214
	return;
}

__attribute__((alias("__imp__sub_8275B414"))) PPC_WEAK_FUNC(sub_8275B414);
PPC_FUNC_IMPL(__imp__sub_8275B414) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275B418"))) PPC_WEAK_FUNC(sub_8275B418);
PPC_FUNC_IMPL(__imp__sub_8275B418) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f13,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// add r11,r10,r3
	r11.u64 = ctx.r10.u64 + ctx.r3.u64;
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// fsubs f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f12,0(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
	// cmpwi cr6,r5,256
	cr6.compare<int32_t>(ctx.r5.s32, 256, xer);
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r8,r4,4
	ctx.r8.s64 = ctx.r4.s64 + 4;
	// stfs f0,0(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// bne cr6,0x8275b470
	if (!cr6.eq) goto loc_8275B470;
	// addi r6,r7,13800
	ctx.r6.s64 = ctx.r7.s64 + 13800;
	// b 0x8275b478
	goto loc_8275B478;
loc_8275B470:
	// addi r7,r7,13800
	ctx.r7.s64 = ctx.r7.s64 + 13800;
	// addi r6,r7,1016
	ctx.r6.s64 = ctx.r7.s64 + 1016;
loc_8275B478:
	// srawi r7,r5,1
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r5.s32 >> 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// cmpwi cr6,r7,1
	cr6.compare<int32_t>(ctx.r7.s32, 1, xer);
	// ble cr6,0x8275b524
	if (!cr6.gt) goto loc_8275B524;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// addi r5,r7,1
	ctx.r5.s64 = ctx.r7.s64 + 1;
	// lfs f0,14884(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14884);
	f0.f64 = double(temp.f32);
loc_8275B498:
	// lfs f12,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lfs f13,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// lfs f9,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfs f10,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fsubs f12,f10,f9
	ctx.f12.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// lfs f8,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// fadds f10,f9,f10
	ctx.f10.f64 = double(float(ctx.f9.f64 + ctx.f10.f64));
	// lfs f9,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f10,f10,f0
	ctx.f10.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fmuls f7,f11,f9
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f9.f64));
	// fmuls f9,f12,f9
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f9.f64));
	// fmsubs f12,f12,f8,f7
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f8.f64 - ctx.f7.f64));
	// fmadds f11,f11,f8,f9
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f8.f64 + ctx.f9.f64));
	// fadds f9,f12,f13
	ctx.f9.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// stfs f13,0(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// fadds f13,f11,f10
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f10.f64));
	// stfs f13,0(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// fsubs f13,f10,f11
	ctx.f13.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// fneg f13,f9
	ctx.f13.u64 = ctx.f9.u64 ^ 0x8000000000000000;
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// bne 0x8275b498
	if (!cr0.eq) goto loc_8275B498;
loc_8275B524:
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r11,r4
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r4.u32);
	f0.f64 = double(temp.f32);
	// fneg f0,f0
	f0.u64 = f0.u64 ^ 0x8000000000000000;
	// stfsx f0,r11,r4
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + ctx.r4.u32, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275B538"))) PPC_WEAK_FUNC(sub_8275B538);
PPC_FUNC_IMPL(__imp__sub_8275B538) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
	// add r11,r10,r3
	r11.u64 = ctx.r10.u64 + ctx.r3.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// addi r8,r4,4
	ctx.r8.s64 = ctx.r4.s64 + 4;
	// cmpwi cr6,r5,256
	cr6.compare<int32_t>(ctx.r5.s32, 256, xer);
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// lfs f11,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fadds f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 + f0.f64));
	// fadds f9,f11,f13
	ctx.f9.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// fsubs f0,f0,f12
	f0.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fsubs f13,f13,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// fsubs f12,f10,f9
	ctx.f12.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// stfs f12,0(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// fadds f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f0,0(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// bne cr6,0x8275b59c
	if (!cr6.eq) goto loc_8275B59C;
	// addi r6,r7,13800
	ctx.r6.s64 = ctx.r7.s64 + 13800;
	// b 0x8275b5a4
	goto loc_8275B5A4;
loc_8275B59C:
	// addi r7,r7,13800
	ctx.r7.s64 = ctx.r7.s64 + 13800;
	// addi r6,r7,1016
	ctx.r6.s64 = ctx.r7.s64 + 1016;
loc_8275B5A4:
	// srawi r7,r5,1
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r5.s32 >> 1;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// rlwinm r31,r7,2,0,29
	r31.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r7,1
	cr6.compare<int32_t>(ctx.r7.s32, 1, xer);
	// lfs f0,3732(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3732);
	f0.f64 = double(temp.f32);
	// lfsx f13,r31,r3
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r3.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r31,r4
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r4.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fmuls f0,f12,f0
	f0.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfsx f13,r31,r3
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, temp.u32);
	// stfsx f0,r31,r4
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, temp.u32);
	// ble cr6,0x8275b654
	if (!cr6.gt) goto loc_8275B654;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
loc_8275B5D8:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lfs f0,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f10,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fadds f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lfs f11,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 + ctx.f11.f64));
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// fsubs f11,f11,f10
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f10,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// fmuls f8,f13,f12
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmuls f12,f10,f12
	ctx.f12.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// fmadds f10,f10,f9,f8
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fmsubs f13,f13,f9,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f9.f64 - ctx.f12.f64));
	// fsubs f12,f11,f10
	ctx.f12.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// fsubs f9,f0,f13
	ctx.f9.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f9,0(r9)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// fadds f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// fadds f11,f10,f11
	ctx.f11.f64 = double(float(ctx.f10.f64 + ctx.f11.f64));
	// stfs f11,0(r8)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// fneg f0,f12
	f0.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// bne 0x8275b5d8
	if (!cr0.eq) goto loc_8275B5D8;
loc_8275B654:
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275B65C"))) PPC_WEAK_FUNC(sub_8275B65C);
PPC_FUNC_IMPL(__imp__sub_8275B65C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275B660"))) PPC_WEAK_FUNC(sub_8275B660);
PPC_FUNC_IMPL(__imp__sub_8275B660) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x8275B668;
	// stfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f31.u64);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r29,1
	r29.s64 = 1;
	// addi r11,r11,15064
	r11.s64 = r11.s64 + 15064;
	// cmpwi cr6,r5,256
	cr6.compare<int32_t>(ctx.r5.s32, 256, xer);
	// addi r31,r11,1536
	r31.s64 = r11.s64 + 1536;
	// beq cr6,0x8275b688
	if (cr6.eq) goto loc_8275B688;
	// addi r31,r11,1920
	r31.s64 = r11.s64 + 1920;
loc_8275B688:
	// srawi r11,r5,4
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xF) != 0);
	r11.s64 = ctx.r5.s32 >> 4;
	// mulli r20,r11,96
	r20.s64 = r11.s64 * 96;
loc_8275B690:
	// rlwinm r11,r29,4,0,27
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// srawi r27,r5,2
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	r27.s64 = ctx.r5.s32 >> 2;
	// addi r11,r11,-12
	r11.s64 = r11.s64 + -12;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// mullw r11,r11,r27
	r11.s64 = int64_t(r11.s32) * int64_t(r27.s32);
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// addi r28,r10,-16
	r28.s64 = ctx.r10.s64 + -16;
	// addi r10,r11,-16
	ctx.r10.s64 = r11.s64 + -16;
	// ble cr6,0x8275b800
	if (!cr6.gt) goto loc_8275B800;
	// addi r21,r27,-4
	r21.s64 = r27.s64 + -4;
	// mulli r24,r27,12
	r24.s64 = r27.s64 * 12;
	// mr r22,r29
	r22.u64 = r29.u64;
loc_8275B6C4:
	// subf r31,r20,r31
	r31.s64 = r31.s64 - r20.s64;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// blt cr6,0x8275b7f0
	if (cr6.lt) goto loc_8275B7F0;
	// addi r11,r21,4
	r11.s64 = r21.s64 + 4;
	// rlwinm r26,r27,3,0,28
	r26.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r25,r27,2,0,29
	r25.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r23,r11,30,2,31
	r23.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
loc_8275B6E0:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// add r6,r24,r10
	ctx.r6.u64 = r24.u64 + ctx.r10.u64;
	// add r7,r26,r10
	ctx.r7.u64 = r26.u64 + ctx.r10.u64;
	// add r8,r25,r10
	ctx.r8.u64 = r25.u64 + ctx.r10.u64;
	// subf r11,r10,r28
	r11.s64 = r28.s64 - ctx.r10.s64;
	// li r30,4
	r30.s64 = 4;
loc_8275B6F8:
	// lfs f12,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// lfs f11,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 + f0.f64));
	// fadds f8,f11,f13
	ctx.f8.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// lfsx f7,r11,r6
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r6.u32);
	ctx.f7.f64 = double(temp.f32);
	// lfsx f9,r11,r8
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f0,f0,f12
	f0.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fsubs f12,f9,f7
	ctx.f12.f64 = double(float(ctx.f9.f64 - ctx.f7.f64));
	// lfsx f5,r11,r7
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	ctx.f5.f64 = double(temp.f32);
	// lfsx f6,r11,r9
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	ctx.f6.f64 = double(temp.f32);
	// fadds f9,f7,f9
	ctx.f9.f64 = double(float(ctx.f7.f64 + ctx.f9.f64));
	// fadds f7,f5,f6
	ctx.f7.f64 = double(float(ctx.f5.f64 + ctx.f6.f64));
	// lfs f4,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f6,f6,f5
	ctx.f6.f64 = double(float(ctx.f6.f64 - ctx.f5.f64));
	// lfs f5,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f13,f13,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// lfs f3,48(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f3.f64 = double(temp.f32);
	// lfs f11,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f11.f64 = double(temp.f32);
	// lfs f1,80(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,64(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	ctx.f2.f64 = double(temp.f32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// fsubs f31,f10,f8
	f31.f64 = double(float(ctx.f10.f64 - ctx.f8.f64));
	// fadds f10,f8,f10
	ctx.f10.f64 = double(float(ctx.f8.f64 + ctx.f10.f64));
	// stfs f10,0(r9)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// fsubs f10,f0,f12
	ctx.f10.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fadds f0,f0,f12
	f0.f64 = double(float(f0.f64 + ctx.f12.f64));
	// fsubs f12,f7,f9
	ctx.f12.f64 = double(float(ctx.f7.f64 - ctx.f9.f64));
	// fadds f9,f9,f7
	ctx.f9.f64 = double(float(ctx.f9.f64 + ctx.f7.f64));
	// stfsx f9,r11,r9
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, temp.u32);
	// fadds f9,f13,f6
	ctx.f9.f64 = double(float(ctx.f13.f64 + ctx.f6.f64));
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// fsubs f13,f6,f13
	ctx.f13.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// fmuls f8,f31,f5
	ctx.f8.f64 = double(float(f31.f64 * ctx.f5.f64));
	// fmuls f7,f31,f4
	ctx.f7.f64 = double(float(f31.f64 * ctx.f4.f64));
	// fmuls f6,f10,f3
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f3.f64));
	// fmuls f10,f10,f11
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// fmuls f31,f0,f1
	f31.f64 = double(float(f0.f64 * ctx.f1.f64));
	// fmuls f0,f0,f2
	f0.f64 = double(float(f0.f64 * ctx.f2.f64));
	// fmsubs f8,f12,f4,f8
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f4.f64 - ctx.f8.f64));
	// stfsx f8,r11,r8
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, temp.u32);
	// fmadds f12,f12,f5,f7
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f5.f64 + ctx.f7.f64));
	// stfs f12,0(r8)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// fmsubs f12,f9,f11,f6
	ctx.f12.f64 = double(float(ctx.f9.f64 * ctx.f11.f64 - ctx.f6.f64));
	// stfsx f12,r11,r7
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + ctx.r7.u32, temp.u32);
	// fmadds f12,f9,f3,f10
	ctx.f12.f64 = double(float(ctx.f9.f64 * ctx.f3.f64 + ctx.f10.f64));
	// stfs f12,0(r7)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// fmsubs f12,f13,f2,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f2.f64 - f31.f64));
	// stfsx f12,r11,r6
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + ctx.r6.u32, temp.u32);
	// fmadds f0,f13,f1,f0
	f0.f64 = double(float(ctx.f13.f64 * ctx.f1.f64 + f0.f64));
	// stfs f0,0(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bne 0x8275b6f8
	if (!cr0.eq) goto loc_8275B6F8;
	// addic. r23,r23,-1
	xer.ca = r23.u32 > 0;
	r23.s64 = r23.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// addi r28,r28,-16
	r28.s64 = r28.s64 + -16;
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// addi r31,r31,80
	r31.s64 = r31.s64 + 80;
	// bne 0x8275b6e0
	if (!cr0.eq) goto loc_8275B6E0;
loc_8275B7F0:
	// addic. r22,r22,-1
	xer.ca = r22.u32 > 0;
	r22.s64 = r22.s64 + -1;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// subf r28,r24,r28
	r28.s64 = r28.s64 - r24.s64;
	// subf r10,r24,r10
	ctx.r10.s64 = ctx.r10.s64 - r24.s64;
	// bne 0x8275b6c4
	if (!cr0.eq) goto loc_8275B6C4;
loc_8275B800:
	// srawi r11,r5,2
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	r11.s64 = ctx.r5.s32 >> 2;
	// rlwinm r29,r29,2,0,29
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addze r5,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	ctx.r5.s64 = temp.s64;
	// srawi r11,r5,4
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xF) != 0);
	r11.s64 = ctx.r5.s32 >> 4;
	// cmpwi cr6,r5,4
	cr6.compare<int32_t>(ctx.r5.s32, 4, xer);
	// mulli r20,r11,96
	r20.s64 = r11.s64 * 96;
	// add r31,r20,r31
	r31.u64 = r20.u64 + r31.u64;
	// bgt cr6,0x8275b690
	if (cr6.gt) goto loc_8275B690;
	// rlwinm r11,r29,4,0,27
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 4) & 0xFFFFFFF0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r10,r11,-16
	ctx.r10.s64 = r11.s64 + -16;
	// ble cr6,0x8275b8d8
	if (!cr6.gt) goto loc_8275B8D8;
	// subf r11,r3,r10
	r11.s64 = ctx.r10.s64 - ctx.r3.s64;
	// subf r8,r4,r3
	ctx.r8.s64 = ctx.r3.s64 - ctx.r4.s64;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
loc_8275B848:
	// lfs f12,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lfs f11,12(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfsx f13,r8,r11
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fadds f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 + f0.f64));
	// fadds f8,f11,f13
	ctx.f8.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// lfs f7,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// lfs f9,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f13,f13,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// fsubs f0,f0,f12
	f0.f64 = double(float(f0.f64 - ctx.f12.f64));
	// lfs f11,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fadds f6,f7,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 + ctx.f9.f64));
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f9,f9,f7
	ctx.f9.f64 = double(float(ctx.f9.f64 - ctx.f7.f64));
	// fadds f7,f11,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 + ctx.f12.f64));
	// fsubs f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// fadds f11,f8,f10
	ctx.f11.f64 = double(float(ctx.f8.f64 + ctx.f10.f64));
	// stfs f11,0(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fsubs f11,f10,f8
	ctx.f11.f64 = double(float(ctx.f10.f64 - ctx.f8.f64));
	// stfsx f11,r8,r11
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, temp.u32);
	// fsubs f11,f9,f13
	ctx.f11.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// stfs f11,4(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// fadds f11,f7,f6
	ctx.f11.f64 = double(float(ctx.f7.f64 + ctx.f6.f64));
	// stfs f11,-4(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + f0.f64));
	// stfs f11,8(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// fsubs f0,f0,f12
	f0.f64 = double(float(f0.f64 - ctx.f12.f64));
	// stfs f0,12(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// fsubs f11,f6,f7
	ctx.f11.f64 = double(float(ctx.f6.f64 - ctx.f7.f64));
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// fadds f0,f9,f13
	f0.f64 = double(float(ctx.f9.f64 + ctx.f13.f64));
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne 0x8275b848
	if (!cr0.eq) goto loc_8275B848;
loc_8275B8D8:
	// rlwinm r6,r29,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r5,r6,-1
	ctx.r5.s64 = ctx.r6.s64 + -1;
	// srawi r9,r6,1
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 1;
	// cmpwi cr6,r5,1
	cr6.compare<int32_t>(ctx.r5.s32, 1, xer);
	// ble cr6,0x8275b948
	if (!cr6.gt) goto loc_8275B948;
	// addi r11,r4,4
	r11.s64 = ctx.r4.s64 + 4;
	// subf r8,r4,r3
	ctx.r8.s64 = ctx.r3.s64 - ctx.r4.s64;
loc_8275B8F8:
	// cmpw cr6,r7,r9
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, xer);
	// ble cr6,0x8275b924
	if (!cr6.gt) goto loc_8275B924;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r11,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r10,r3
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfsx f11,r10,r4
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	ctx.f11.f64 = double(temp.f32);
	// stfsx f12,r11,r8
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, temp.u32);
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfsx f0,r10,r3
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r3.u32, temp.u32);
	// stfsx f13,r10,r4
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r4.u32, temp.u32);
loc_8275B924:
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
loc_8275B928:
	// srawi r10,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// xor r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 ^ ctx.r9.u64;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x8275b928
	if (cr6.lt) goto loc_8275B928;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r7,r5
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r5.s32, xer);
	// blt cr6,0x8275b8f8
	if (cr6.lt) goto loc_8275B8F8;
loc_8275B948:
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8275B950"))) PPC_WEAK_FUNC(sub_8275B950);
PPC_FUNC_IMPL(__imp__sub_8275B950) {
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
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8275B958;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9d4
	ctx.lr = 0x8275B960;
	// stwu r1,-608(r1)
	ea = -608 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// lfs f27,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f27.f64 = double(temp.f32);
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8275b9cc
	if (!cr6.gt) goto loc_8275B9CC;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// subf r9,r10,r5
	ctx.r9.s64 = ctx.r5.s64 - ctx.r10.s64;
	// lfs f13,8884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// lfs f0,16368(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 16368);
	f0.f64 = double(temp.f32);
loc_8275B9AC:
	// lfsx f12,r9,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// fmadds f12,f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f13.f64));
	// fadds f12,f12,f27
	ctx.f12.f64 = double(float(ctx.f12.f64 + f27.f64));
	// fctiwz f12,f12
	ctx.f12.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfiwx f12,0,r11
	PPC_STORE_U32(r11.u32, ctx.f12.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8275b9ac
	if (!cr0.eq) goto loc_8275B9AC;
loc_8275B9CC:
	// addi r4,r1,108
	ctx.r4.s64 = ctx.r1.s64 + 108;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82757ee8
	ctx.lr = 0x8275B9D8;
	sub_82757EE8(ctx, base);
	// lwz r9,104(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// stfs f28,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r7,108(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r7,1
	cr6.compare<int32_t>(ctx.r7.s32, 1, xer);
	// lfs f0,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f0,f28,f0
	f0.f64 = double(float(f28.f64 - f0.f64));
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// ble cr6,0x8275ba68
	if (!cr6.gt) goto loc_8275BA68;
	// addi r8,r9,4
	ctx.r8.s64 = ctx.r9.s64 + 4;
loc_8275BA04:
	// lfs f0,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f0,f28,f0
	f0.f64 = double(float(f28.f64 - f0.f64));
	// fmuls f0,f0,f0
	f0.f64 = double(float(f0.f64 * f0.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8275ba20
	if (!cr6.lt) goto loc_8275BA20;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8275BA20:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x8275ba04
	if (cr6.lt) goto loc_8275BA04;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// blt cr6,0x8275ba68
	if (cr6.lt) goto loc_8275BA68;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r7,-1
	ctx.r8.s64 = ctx.r7.s64 + -1;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f31,f13,f0
	f31.f64 = double(float(ctx.f13.f64 - f0.f64));
	// bge cr6,0x8275ba7c
	if (!cr6.lt) goto loc_8275BA7C;
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmuls f31,f0,f27
	f31.f64 = double(float(f0.f64 * f27.f64));
	// b 0x8275ba7c
	goto loc_8275BA7C;
loc_8275BA68:
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f31,f0,f13
	f31.f64 = double(float(f0.f64 - ctx.f13.f64));
loc_8275BA7C:
	// lis r11,-32248
	r11.s64 = -2113404928;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// lfs f29,16364(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16364);
	f29.f64 = double(temp.f32);
	// ble cr6,0x8275baa8
	if (!cr6.gt) goto loc_8275BAA8;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8275BA94:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// fadds f29,f29,f0
	f29.f64 = double(float(f29.f64 + f0.f64));
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x8275ba94
	if (!cr0.eq) goto loc_8275BA94;
loc_8275BAA8:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,-13148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13148);
	f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	f0.f64 = double(float(f31.f64 * f0.f64));
	// lfs f13,-28668(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28668);
	ctx.f13.f64 = double(temp.f32);
	// lfs f30,-17876(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -17876);
	f30.f64 = double(temp.f32);
	// fmuls f1,f31,f13
	ctx.f1.f64 = double(float(f31.f64 * ctx.f13.f64));
	// lfs f13,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fsubs f2,f28,f0
	ctx.f2.f64 = double(float(f28.f64 - f0.f64));
	// fcmpu cr6,f2,f30
	cr6.compare(ctx.f2.f64, f30.f64);
	// bge cr6,0x8275bae4
	if (!cr6.lt) goto loc_8275BAE4;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
loc_8275BAE4:
	// fadds f3,f0,f28
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = double(float(f0.f64 + f28.f64));
	// lis r11,-32248
	r11.s64 = -2113404928;
	// lfs f28,26200(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 26200);
	f28.f64 = double(temp.f32);
	// fcmpu cr6,f3,f28
	cr6.compare(ctx.f3.f64, f28.f64);
	// ble cr6,0x8275bafc
	if (!cr6.gt) goto loc_8275BAFC;
	// fmr f3,f28
	ctx.f3.f64 = f28.f64;
loc_8275BAFC:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// fmr f4,f29
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = f29.f64;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// addi r6,r1,100
	ctx.r6.s64 = ctx.r1.s64 + 100;
	// bl 0x8275c710
	ctx.lr = 0x8275BB1C;
	sub_8275C710(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,-29232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	f0.f64 = double(float(f31.f64 * f0.f64));
	// lfs f13,12424(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12424);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f31,f13
	ctx.f1.f64 = double(float(f31.f64 * ctx.f13.f64));
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f2,f13,f0
	ctx.f2.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fcmpu cr6,f2,f30
	cr6.compare(ctx.f2.f64, f30.f64);
	// bge cr6,0x8275bb48
	if (!cr6.lt) goto loc_8275BB48;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
loc_8275BB48:
	// fadds f3,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = double(float(f0.f64 + ctx.f13.f64));
	// fcmpu cr6,f3,f28
	cr6.compare(ctx.f3.f64, f28.f64);
	// ble cr6,0x8275bb58
	if (!cr6.gt) goto loc_8275BB58;
	// fmr f3,f28
	ctx.f3.f64 = f28.f64;
loc_8275BB58:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// fmr f4,f29
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = f29.f64;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// addi r6,r1,100
	ctx.r6.s64 = ctx.r1.s64 + 100;
	// bl 0x8275c710
	ctx.lr = 0x8275BB78;
	sub_8275C710(ctx, base);
	// lfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f27
	f0.f64 = double(float(f0.f64 * f27.f64));
	// stfs f29,0(r29)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// fdivs f0,f0,f29
	f0.f64 = double(float(f0.f64 / f29.f64));
	// stfs f0,0(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
	// stfs f13,0(r28)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// addi r1,r1,608
	ctx.r1.s64 = ctx.r1.s64 + 608;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba20
	ctx.lr = 0x8275BBA4;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8275BBA8"))) PPC_WEAK_FUNC(sub_8275BBA8);
PPC_FUNC_IMPL(__imp__sub_8275BBA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r11,r4,1020
	r11.s64 = ctx.r4.s64 + 1020;
	// li r10,255
	ctx.r10.s64 = 255;
	// ori r9,r9,41600
	ctx.r9.u64 = ctx.r9.u64 | 41600;
loc_8275BBB8:
	// addi r9,r9,-162
	ctx.r9.s64 = ctx.r9.s64 + -162;
	// rlwinm r8,r9,24,8,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFFFFFF;
	// addi r8,r8,65
	ctx.r8.s64 = ctx.r8.s64 + 65;
	// mullw r8,r8,r10
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// addi r8,r8,209
	ctx.r8.s64 = ctx.r8.s64 + 209;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r8,r8,24,8,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFFFFFF;
	// cmplwi cr6,r10,86
	cr6.compare<uint32_t>(ctx.r10.u32, 86, xer);
	// addi r8,r8,29
	ctx.r8.s64 = ctx.r8.s64 + 29;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f0,r8,r3
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// bgt cr6,0x8275bbb8
	if (cr6.gt) goto loc_8275BBB8;
	// li r10,17789
	ctx.r10.s64 = 17789;
	// li r9,87
	ctx.r9.s64 = 87;
loc_8275BBF8:
	// addi r10,r10,-203
	ctx.r10.s64 = ctx.r10.s64 + -203;
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rlwinm r8,r10,26,6,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0x3FFFFFC;
	// lfsx f0,r8,r3
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// bne 0x8275bbf8
	if (!cr0.eq) goto loc_8275BBF8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275BC18"))) PPC_WEAK_FUNC(sub_8275BC18);
PPC_FUNC_IMPL(__imp__sub_8275BC18) {
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
	// extsh. r11,r4
	r11.s64 = ctx.r4.s16;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bgt 0x8275bc30
	if (cr0.gt) goto loc_8275BC30;
	// li r4,176
	ctx.r4.s64 = 176;
loc_8275BC30:
	// extsh r11,r4
	r11.s64 = ctx.r4.s16;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	f0.f64 = double(temp.f32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// lfs f13,15000(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15000);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-208(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -208);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x8275bc6c
	if (cr6.gt) goto loc_8275BC6C;
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x8275bc90
	if (!cr6.lt) goto loc_8275BC90;
loc_8275BC6C:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x8275bc7c
	if (!cr6.lt) goto loc_8275BC7C;
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// b 0x8275bc80
	goto loc_8275BC80;
loc_8275BC7C:
	// fsubs f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
loc_8275BC80:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bne cr6,0x8275bc98
	if (!cr6.eq) goto loc_8275BC98;
loc_8275BC90:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8275bd48
	goto loc_8275BD48;
loc_8275BC98:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f13.f64);
	// lfd f1,14704(r10)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r10.u32 + 14704);
	// bge cr6,0x8275bcfc
	if (!cr6.lt) goto loc_8275BCFC;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f13,17092(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17092);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f2,f0,f13
	ctx.f2.f64 = double(float(f0.f64 * ctx.f13.f64));
	// bl 0x823dc480
	ctx.lr = 0x8275BCB8;
	sub_823DC480(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f13,17088(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17088);
	ctx.f13.f64 = double(temp.f32);
	// fneg f0,f0
	f0.u64 = f0.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8275bcd4
	if (!cr6.lt) goto loc_8275BCD4;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_8275BCD4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f13,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfs f0,-28736(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28736);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lhz r3,86(r1)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
	// b 0x8275bd48
	goto loc_8275BD48;
loc_8275BCFC:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f13,17084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17084);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f2,f0,f13
	ctx.f2.f64 = double(float(f0.f64 * ctx.f13.f64));
	// bl 0x823dc480
	ctx.lr = 0x8275BD0C;
	sub_823DC480(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f13,17080(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17080);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8275bd24
	if (!cr6.gt) goto loc_8275BD24;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_8275BD24:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f13,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f0,-28736(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28736);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctiwz f0,f0
	f0.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lhz r3,86(r1)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
loc_8275BD48:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275BD58"))) PPC_WEAK_FUNC(sub_8275BD58);
PPC_FUNC_IMPL(__imp__sub_8275BD58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// rlwinm. r9,r3,29,27,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 29) & 0x1F;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// lfsx f0,r10,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// lfs f12,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f0,f12
	f0.f64 = double(float(f0.f64 - ctx.f12.f64));
	// lfs f13,17096(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 17096);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	f0.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfsx f0,r10,r11
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, temp.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lfsx f0,r11,r10
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	f0.f64 = double(temp.f32);
	// ble 0x8275bdbc
	if (!cr0.gt) goto loc_8275BDBC;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
loc_8275BD98:
	// lfsx f11,r10,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// fmuls f11,f11,f13
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// stfsx f11,r10,r11
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, temp.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lfsx f11,r10,r11
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fadds f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 + f0.f64));
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x8275bd98
	if (!cr0.eq) goto loc_8275BD98;
loc_8275BDBC:
	// addi r11,r9,1
	r11.s64 = ctx.r9.s64 + 1;
	// cmpwi cr6,r11,32
	cr6.compare<int32_t>(r11.s32, 32, xer);
	// bgt cr6,0x8275bdf4
	if (cr6.gt) goto loc_8275BDF4;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
loc_8275BDD0:
	// lfsx f11,r11,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f11,f11,f13
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// stfsx f11,r11,r10
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, temp.u32);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lfsx f11,r11,r10
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// fadds f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 + f0.f64));
	// cmpwi cr6,r11,128
	cr6.compare<int32_t>(r11.s32, 128, xer);
	// ble cr6,0x8275bdd0
	if (!cr6.gt) goto loc_8275BDD0;
loc_8275BDF4:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fdivs f13,f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f12.f64 / f0.f64));
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,4(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
loc_8275BE0C:
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f12,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// std r9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f11,-16(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// cmpwi cr6,r11,32
	cr6.compare<int32_t>(r11.s32, 32, xer);
	// fmuls f0,f11,f0
	f0.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fmadds f0,f0,f13,f12
	f0.f64 = double(float(f0.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f0,4(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// ble cr6,0x8275be0c
	if (!cr6.gt) goto loc_8275BE0C;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r10,8(r4)
	PPC_STORE_U16(ctx.r4.u32 + 8, ctx.r10.u16);
	// lfs f0,-17876(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17876);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f0,4(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275BE64"))) PPC_WEAK_FUNC(sub_8275BE64);
PPC_FUNC_IMPL(__imp__sub_8275BE64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275BE68"))) PPC_WEAK_FUNC(sub_8275BE68);
PPC_FUNC_IMPL(__imp__sub_8275BE68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275BE70"))) PPC_WEAK_FUNC(sub_8275BE70);
PPC_FUNC_IMPL(__imp__sub_8275BE70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lha r11,8(r3)
	r11.s64 = int16_t(PPC_LOAD_U16(ctx.r3.u32 + 8));
	// cmpwi cr6,r11,84
	cr6.compare<int32_t>(r11.s32, 84, xer);
	// bgt cr6,0x8275beb0
	if (cr6.gt) goto loc_8275BEB0;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// lfs f0,17100(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17100);
	f0.f64 = double(temp.f32);
loc_8275BE88:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// lfsx f13,r9,r10
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r11,32
	cr6.compare<int32_t>(r11.s32, 32, xer);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfsx f13,r9,r10
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
	// ble cr6,0x8275be88
	if (!cr6.gt) goto loc_8275BE88;
	// b 0x8275beb8
	goto loc_8275BEB8;
loc_8275BEB0:
	// li r11,84
	r11.s64 = 84;
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
loc_8275BEB8:
	// lhz r11,8(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275BEC8"))) PPC_WEAK_FUNC(sub_8275BEC8);
PPC_FUNC_IMPL(__imp__sub_8275BEC8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,-19440(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -19440);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8275befc
	if (!cr6.gt) goto loc_8275BEFC;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// lfs f13,17124(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17124);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,17120(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17120);
	ctx.f12.f64 = double(temp.f32);
	// fnmsubs f12,f0,f13,f12
	ctx.f12.f64 = double(float(-(f0.f64 * ctx.f13.f64 - ctx.f12.f64)));
	// lfs f13,17116(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17116);
	ctx.f13.f64 = double(temp.f32);
	// b 0x8275bf18
	goto loc_8275BF18;
loc_8275BEFC:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// lfs f13,17112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,17108(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17108);
	ctx.f12.f64 = double(temp.f32);
	// fnmsubs f12,f0,f13,f12
	ctx.f12.f64 = double(float(-(f0.f64 * ctx.f13.f64 - ctx.f12.f64)));
	// lfs f13,17104(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17104);
	ctx.f13.f64 = double(temp.f32);
loc_8275BF18:
	// fmadds f0,f12,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f13.f64));
	// stfs f0,4(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x8275bf30
	if (cr6.gt) goto loc_8275BF30;
	// li r11,0
	r11.s64 = 0;
loc_8275BF30:
	// stb r11,19(r4)
	PPC_STORE_U8(ctx.r4.u32 + 19, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275BF38"))) PPC_WEAK_FUNC(sub_8275BF38);
PPC_FUNC_IMPL(__imp__sub_8275BF38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r11,19(r6)
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + 19);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8275bfac
	if (cr6.eq) goto loc_8275BFAC;
	// extsh r11,r5
	r11.s64 = ctx.r5.s16;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// frsp f12,f0
	ctx.f12.f64 = double(float(f0.f64));
	// lfs f0,17132(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17132);
	f0.f64 = double(temp.f32);
	// lfs f13,17128(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17128);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f2,f0
	f0.f64 = double(float(ctx.f2.f64 - f0.f64));
	// fsubs f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8275bf7c
	if (!cr6.lt) goto loc_8275BF7C;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_8275BF7C:
	// fcmpu cr6,f1,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f0.f64);
	// blt cr6,0x8275bfac
	if (cr6.lt) goto loc_8275BFAC;
	// lhz r11,14(r6)
	r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 14);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// extsh r11,r11
	r11.s64 = r11.s16;
	// sth r11,14(r6)
	PPC_STORE_U16(ctx.r6.u32 + 14, r11.u16);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x8275bfa4
	if (!cr6.gt) goto loc_8275BFA4;
	// li r11,1
	r11.s64 = 1;
	// b 0x8275bfb0
	goto loc_8275BFB0;
loc_8275BFA4:
	// li r11,0
	r11.s64 = 0;
	// b 0x8275bfb4
	goto loc_8275BFB4;
loc_8275BFAC:
	// li r11,0
	r11.s64 = 0;
loc_8275BFB0:
	// sth r11,14(r6)
	PPC_STORE_U16(ctx.r6.u32 + 14, r11.u16);
loc_8275BFB4:
	// stb r11,20(r6)
	PPC_STORE_U8(ctx.r6.u32 + 20, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275BFBC"))) PPC_WEAK_FUNC(sub_8275BFBC);
PPC_FUNC_IMPL(__imp__sub_8275BFBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275BFC0"))) PPC_WEAK_FUNC(sub_8275BFC0);
PPC_FUNC_IMPL(__imp__sub_8275BFC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f13,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-19440(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -19440);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8275bffc
	if (!cr6.lt) goto loc_8275BFFC;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lfs f0,17156(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17156);
	f0.f64 = double(temp.f32);
	// lfs f12,17152(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17152);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fadds f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x8275c024
	if (!cr6.lt) goto loc_8275C024;
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
	// b 0x8275c024
	goto loc_8275C024;
loc_8275BFFC:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f0,17148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17148);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8275c018
	if (!cr6.lt) goto loc_8275C018;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f0,17144(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17144);
	f0.f64 = double(temp.f32);
	// b 0x8275c020
	goto loc_8275C020;
loc_8275C018:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f0,17140(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17140);
	f0.f64 = double(temp.f32);
loc_8275C020:
	// fmuls f0,f13,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
loc_8275C024:
	// fcmpu cr6,f1,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, ctx.f13.f64);
	// bge cr6,0x8275c11c
	if (!cr6.lt) goto loc_8275C11C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lbz r11,18(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 18);
	// extsb. r11,r11
	r11.s64 = r11.s8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lfs f9,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f9.f64 = double(temp.f32);
	// bgt 0x8275c068
	if (cr0.gt) goto loc_8275C068;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fadds f12,f1,f9
	ctx.f12.f64 = double(float(ctx.f1.f64 + ctx.f9.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f11,17032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f11,f13,f11
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// lfs f10,32680(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32680);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f8,f12,f10,f11
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f10.f64 + ctx.f11.f64));
	// fcmpu cr6,f8,f0
	cr6.compare(ctx.f8.f64, f0.f64);
	// bgt cr6,0x8275c068
	if (cr6.gt) goto loc_8275C068;
	// fmadds f0,f12,f10,f11
	f0.f64 = double(float(ctx.f12.f64 * ctx.f10.f64 + ctx.f11.f64));
loc_8275C068:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,8884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fcmpu cr6,f1,f12
	cr6.compare(ctx.f1.f64, ctx.f12.f64);
	// bgt cr6,0x8275c0d4
	if (cr6.gt) goto loc_8275C0D4;
	// fcmpu cr6,f1,f9
	cr6.compare(ctx.f1.f64, ctx.f9.f64);
	// bge cr6,0x8275c0b0
	if (!cr6.lt) goto loc_8275C0B0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// fadds f12,f1,f9
	ctx.f12.f64 = double(float(ctx.f1.f64 + ctx.f9.f64));
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f11,-19928(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -19928);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f13,f13,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f11.f64));
	// lfs f11,-11316(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11316);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f12,f11,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f13.f64));
	// fcmpu cr6,f10,f0
	cr6.compare(ctx.f10.f64, f0.f64);
	// bgt cr6,0x8275c14c
	if (cr6.gt) goto loc_8275C14C;
	// fmadds f0,f12,f11,f13
	f0.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f13.f64));
	// b 0x8275c14c
	goto loc_8275C14C;
loc_8275C0B0:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f12,-12084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12084);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lfs f13,-6176(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -6176);
	ctx.f13.f64 = double(temp.f32);
loc_8275C0C4:
	// fmadds f13,f1,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f13.f64 + ctx.f12.f64));
loc_8275C0C8:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x8275c14c
	if (cr6.gt) goto loc_8275C14C;
	// b 0x8275c148
	goto loc_8275C148;
loc_8275C0D4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fcmpu cr6,f1,f12
	cr6.compare(ctx.f1.f64, ctx.f12.f64);
	// bgt cr6,0x8275c100
	if (cr6.gt) goto loc_8275C100;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f12,-332(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -332);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lfs f13,-17424(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -17424);
	ctx.f13.f64 = double(temp.f32);
	// b 0x8275c0c4
	goto loc_8275C0C4;
loc_8275C100:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f12,-32032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -32032);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// lfs f12,31308(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31308);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f13,f12,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + ctx.f11.f64));
	// b 0x8275c0c8
	goto loc_8275C0C8;
loc_8275C11C:
	// lbz r11,19(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 19);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8275c14c
	if (!cr6.eq) goto loc_8275C14C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f12,-29232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// lfs f12,-13148(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13148);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f13,f12,f11
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + ctx.f11.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x8275c14c
	if (cr6.lt) goto loc_8275C14C;
loc_8275C148:
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f13.f64;
loc_8275C14C:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f13,17136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17136);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8275c160
	if (!cr6.gt) goto loc_8275C160;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_8275C160:
	// lbz r11,18(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 18);
	// extsb. r11,r11
	r11.s64 = r11.s8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bgt 0x8275c174
	if (cr0.gt) goto loc_8275C174;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r11,18(r4)
	PPC_STORE_U8(ctx.r4.u32 + 18, r11.u8);
loc_8275C174:
	// stfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275C17C"))) PPC_WEAK_FUNC(sub_8275C17C);
PPC_FUNC_IMPL(__imp__sub_8275C17C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275C180"))) PPC_WEAK_FUNC(sub_8275C180);
PPC_FUNC_IMPL(__imp__sub_8275C180) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// extsh r11,r4
	r11.s64 = ctx.r4.s16;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// blt cr6,0x8275c190
	if (cr6.lt) goto loc_8275C190;
	// li r4,255
	ctx.r4.s64 = 255;
loc_8275C190:
	// lbz r11,20(r6)
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + 20);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8275c1d8
	if (!cr6.eq) goto loc_8275C1D8;
	// lbz r11,21(r6)
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + 21);
	// li r10,0
	ctx.r10.s64 = 0;
	// sth r10,16(r6)
	PPC_STORE_U16(ctx.r6.u32 + 16, ctx.r10.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8275c240
	if (!cr6.eq) goto loc_8275C240;
	// extsh r11,r4
	r11.s64 = ctx.r4.s16;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// frsp f0,f0
	f0.f64 = double(float(f0.f64));
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// blt cr6,0x8275c240
	if (cr6.lt) goto loc_8275C240;
	// li r11,1
	r11.s64 = 1;
	// stb r11,21(r6)
	PPC_STORE_U8(ctx.r6.u32 + 21, r11.u8);
	// b 0x8275c240
	goto loc_8275C240;
loc_8275C1D8:
	// clrlwi r8,r5,16
	ctx.r8.u64 = ctx.r5.u32 & 0xFFFF;
	// lfs f13,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lhz r9,16(r6)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r6.u32 + 16);
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f0,-16(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// addi r11,r9,1
	r11.s64 = ctx.r9.s64 + 1;
	// frsp f12,f0
	ctx.f12.f64 = double(float(f0.f64));
	// lfs f0,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// sth r11,16(r6)
	PPC_STORE_U16(ctx.r6.u32 + 16, r11.u16);
	// fmadds f0,f13,f12,f0
	f0.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + f0.f64));
	// fctidz f0,f0
	f0.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f0.u64);
	// lha r11,-10(r1)
	r11.s64 = int16_t(PPC_LOAD_U16(ctx.r1.u32 + -10));
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// ble cr6,0x8275c240
	if (!cr6.gt) goto loc_8275C240;
	// extsh r11,r10
	r11.s64 = ctx.r10.s16;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,32700
	cr6.compare<int32_t>(r11.s32, 32700, xer);
	// stb r10,21(r6)
	PPC_STORE_U8(ctx.r6.u32 + 21, ctx.r10.u8);
	// ble cr6,0x8275c240
	if (!cr6.gt) goto loc_8275C240;
	// li r11,32700
	r11.s64 = 32700;
	// sth r11,16(r6)
	PPC_STORE_U16(ctx.r6.u32 + 16, r11.u16);
loc_8275C240:
	// lbz r11,21(r6)
	r11.u64 = PPC_LOAD_U8(ctx.r6.u32 + 21);
	// extsb r3,r11
	ctx.r3.s64 = r11.s8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275C24C"))) PPC_WEAK_FUNC(sub_8275C24C);
PPC_FUNC_IMPL(__imp__sub_8275C24C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275C250"))) PPC_WEAK_FUNC(sub_8275C250);
PPC_FUNC_IMPL(__imp__sub_8275C250) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r11,20(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 20);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8275c288
	if (!cr6.eq) goto loc_8275C288;
	// extsh r11,r4
	r11.s64 = ctx.r4.s16;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8275c288
	if (!cr6.eq) goto loc_8275C288;
	// lbz r11,21(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 21);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8275c288
	if (!cr6.eq) goto loc_8275C288;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,-3164(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -3164);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgelr cr6
	if (!cr6.lt) return;
loc_8275C288:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275C290"))) PPC_WEAK_FUNC(sub_8275C290);
PPC_FUNC_IMPL(__imp__sub_8275C290) {
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8275C298;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9d8
	ctx.lr = 0x8275C2A0;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// li r4,64
	ctx.r4.s64 = 64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x82758450
	ctx.lr = 0x8275C2C0;
	sub_82758450(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r10,r31,4
	ctx.r10.s64 = r31.s64 + 4;
	// li r11,11
	r11.s64 = 11;
	// lfs f31,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
loc_8275C2D4:
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// fnmsubs f0,f0,f0,f31
	f0.f64 = double(float(-(f0.f64 * f0.f64 - f31.f64)));
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// fmuls f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 * ctx.f1.f64));
	// bne 0x8275c2d4
	if (!cr0.eq) goto loc_8275C2D4;
	// bl 0x82758910
	ctx.lr = 0x8275C2F0;
	sub_82758910(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f29,f13,f13,f31
	f29.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + f31.f64));
	// li r31,0
	r31.s64 = 0;
	// addi r29,r1,112
	r29.s64 = ctx.r1.s64 + 112;
	// li r30,5
	r30.s64 = 5;
	// lfs f31,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f31.f64 = double(temp.f32);
	// lis r28,-32125
	r28.s64 = -2105344000;
	// lfs f0,14880(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14880);
	f0.f64 = double(temp.f32);
	// fnmsubs f30,f1,f31,f30
	f30.f64 = double(float(-(ctx.f1.f64 * f31.f64 - f30.f64)));
	// fmuls f28,f13,f0
	f28.f64 = double(float(ctx.f13.f64 * f0.f64));
loc_8275C320:
	// lwz r11,-3624(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// lfsx f0,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + r11.u32);
	f0.f64 = double(temp.f32);
	// addi r31,r31,128
	r31.s64 = r31.s64 + 128;
	// fmadds f1,f0,f28,f29
	ctx.f1.f64 = double(float(f0.f64 * f28.f64 + f29.f64));
	// bl 0x82758910
	ctx.lr = 0x8275C334;
	sub_82758910(ctx, base);
	// fnmsubs f0,f1,f31,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(-(ctx.f1.f64 * f31.f64 - f30.f64)));
	// stfs f0,0(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x8275c320
	if (!cr0.eq) goto loc_8275C320;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// li r11,1
	r11.s64 = 1;
	// addi r8,r9,17160
	ctx.r8.s64 = ctx.r9.s64 + 17160;
	// addi r10,r27,4
	ctx.r10.s64 = r27.s64 + 4;
	// lfs f12,17160(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17160);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f11,12(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
loc_8275C364:
	// clrlwi r8,r11,28
	ctx.r8.u64 = r11.u32 & 0xF;
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// srawi r9,r11,4
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0xF) != 0);
	ctx.r9.s64 = r11.s32 >> 4;
	// std r8,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// lfd f0,96(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// frsp f0,f0
	f0.f64 = double(float(f0.f64));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,116
	ctx.r7.s64 = ctx.r1.s64 + 116;
	// lfsx f9,r9,r8
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	ctx.f9.f64 = double(temp.f32);
	// lfsx f8,r9,r7
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f8,f8,f9
	ctx.f8.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// fmuls f0,f0,f11
	f0.f64 = double(float(f0.f64 * ctx.f11.f64));
	// fmadds f0,f8,f0,f9
	f0.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f9.f64));
	// fsubs f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmuls f0,f0,f31
	f0.f64 = double(float(f0.f64 * f31.f64));
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// ble cr6,0x8275c3b4
	if (!cr6.gt) goto loc_8275C3B4;
	// fmr f0,f12
	f0.f64 = ctx.f12.f64;
loc_8275C3B4:
	// fcmpu cr6,f0,f10
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f10.f64);
	// bgt cr6,0x8275c3c0
	if (cr6.gt) goto loc_8275C3C0;
	// fmr f0,f10
	f0.f64 = ctx.f10.f64;
loc_8275C3C0:
	// cmpwi cr6,r11,16
	cr6.compare<int32_t>(r11.s32, 16, xer);
	// bge cr6,0x8275c3e4
	if (!cr6.lt) goto loc_8275C3E4;
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// std r9,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r9.u64);
	// lfd f9,104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// frsp f9,f9
	ctx.f9.f64 = double(float(ctx.f9.f64));
	// fmuls f9,f9,f11
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// fmuls f0,f9,f0
	f0.f64 = double(float(ctx.f9.f64 * f0.f64));
loc_8275C3E4:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// fadds f0,f13,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// blt cr6,0x8275c364
	if (cr6.lt) goto loc_8275C364;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// li r4,64
	ctx.r4.s64 = 64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82758450
	ctx.lr = 0x8275C410;
	sub_82758450(ctx, base);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// mr r11,r27
	r11.u64 = r27.u64;
	// li r10,64
	ctx.r10.s64 = 64;
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
loc_8275C424:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8275c424
	if (!cr0.eq) goto loc_8275C424;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba24
	ctx.lr = 0x8275C448;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8275C44C"))) PPC_WEAK_FUNC(sub_8275C44C);
PPC_FUNC_IMPL(__imp__sub_8275C44C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275C450"))) PPC_WEAK_FUNC(sub_8275C450);
PPC_FUNC_IMPL(__imp__sub_8275C450) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8275C458;
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// lfs f13,2308(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 2308);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r8,2056
	ctx.r4.s64 = ctx.r8.s64 + 2056;
	// stfs f13,2312(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + 2312, temp.u32);
	// fmr f0,f2
	f0.f64 = ctx.f2.f64;
	// lfs f13,2568(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 2568);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r8,2316
	ctx.r3.s64 = ctx.r8.s64 + 2316;
	// stfs f13,2572(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + 2572, temp.u32);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x8275c580
	if (!cr6.gt) goto loc_8275C580;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lis r31,-32243
	r31.s64 = -2113077248;
	// lwz r27,92(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lis r30,-32243
	r30.s64 = -2113077248;
	// lis r29,-32243
	r29.s64 = -2113077248;
	// lis r28,-32243
	r28.s64 = -2113077248;
	// lis r25,-32250
	r25.s64 = -2113536000;
	// lfs f9,-29232(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,17180(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 17180);
	ctx.f8.f64 = double(temp.f32);
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// lfs f10,17184(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 17184);
	ctx.f10.f64 = double(temp.f32);
	// subf r26,r8,r9
	r26.s64 = ctx.r9.s64 - ctx.r8.s64;
	// lfs f11,17188(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 17188);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,17192(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 17192);
	ctx.f12.f64 = double(temp.f32);
	// lfs f7,132(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 132);
	ctx.f7.f64 = double(temp.f32);
loc_8275C4C4:
	// fcmpu cr6,f0,f7
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f7.f64);
	// ble cr6,0x8275c4d8
	if (!cr6.gt) goto loc_8275C4D8;
	// fnmsubs f13,f0,f12,f11
	ctx.f13.f64 = double(float(-(f0.f64 * ctx.f12.f64 - ctx.f11.f64)));
	// fmadds f13,f13,f0,f10
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f10.f64));
	// b 0x8275c4dc
	goto loc_8275C4DC;
loc_8275C4D8:
	// fmuls f13,f0,f8
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f0.f64 * ctx.f8.f64));
loc_8275C4DC:
	// fmuls f13,f13,f9
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f9.f64));
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// fadds f0,f0,f2
	f0.f64 = double(float(f0.f64 + ctx.f2.f64));
	// fctiwz f6,f13
	ctx.f6.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f6,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.f6.u64);
	// lwz r11,-92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -92);
	// extsw r31,r11
	r31.s64 = r11.s32;
	// std r31,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, r31.u64);
	// lfd f6,-88(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// fcfid f6,f6
	ctx.f6.f64 = double(ctx.f6.s64);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// frsp f6,f6
	ctx.f6.f64 = double(float(ctx.f6.f64));
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// add r30,r11,r4
	r30.u64 = r11.u64 + ctx.r4.u64;
	// lfsx f5,r11,r10
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	ctx.f5.f64 = double(temp.f32);
	// lfsx f3,r11,r4
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r4.u32);
	ctx.f3.f64 = double(temp.f32);
	// add r29,r11,r3
	r29.u64 = r11.u64 + ctx.r3.u64;
	// add r28,r11,r27
	r28.u64 = r11.u64 + r27.u64;
	// lfs f31,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f31.f64 = double(temp.f32);
	// lfs f30,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	f30.f64 = double(temp.f32);
	// fsubs f31,f31,f5
	f31.f64 = double(float(f31.f64 - ctx.f5.f64));
	// fsubs f30,f30,f3
	f30.f64 = double(float(f30.f64 - ctx.f3.f64));
	// fsubs f13,f13,f6
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f6.f64));
	// fmadds f6,f31,f13,f5
	ctx.f6.f64 = double(float(f31.f64 * ctx.f13.f64 + ctx.f5.f64));
	// fmadds f5,f30,f13,f3
	ctx.f5.f64 = double(float(f30.f64 * ctx.f13.f64 + ctx.f3.f64));
	// fsubs f5,f5,f6
	ctx.f5.f64 = double(float(ctx.f5.f64 - ctx.f6.f64));
	// fmadds f6,f5,f4,f6
	ctx.f6.f64 = double(float(ctx.f5.f64 * ctx.f4.f64 + ctx.f6.f64));
	// stfsx f6,r26,r8
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r26.u32 + ctx.r8.u32, temp.u32);
	// lfsx f6,r11,r3
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f5.f64 = double(temp.f32);
	// lfsx f3,r11,r27
	temp.u32 = PPC_LOAD_U32(r11.u32 + r27.u32);
	ctx.f3.f64 = double(temp.f32);
	// lfs f31,4(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 4);
	f31.f64 = double(temp.f32);
	// fsubs f31,f31,f3
	f31.f64 = double(float(f31.f64 - ctx.f3.f64));
	// fsubs f5,f5,f6
	ctx.f5.f64 = double(float(ctx.f5.f64 - ctx.f6.f64));
	// fmadds f3,f31,f13,f3
	ctx.f3.f64 = double(float(f31.f64 * ctx.f13.f64 + ctx.f3.f64));
	// fmadds f13,f5,f13,f6
	ctx.f13.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + ctx.f6.f64));
	// fsubs f13,f13,f3
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f3.f64));
	// fmadds f13,f13,f4,f3
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f4.f64 + ctx.f3.f64));
	// stfs f13,0(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// bne 0x8275c4c4
	if (!cr0.eq) goto loc_8275C4C4;
loc_8275C580:
	// cmpw cr6,r7,r6
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, xer);
	// bge cr6,0x8275c5ac
	if (!cr6.lt) goto loc_8275C5AC;
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r7,r6
	ctx.r10.s64 = ctx.r6.s64 - ctx.r7.s64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
loc_8275C594:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// fadds f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 + f0.f64));
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x8275c594
	if (!cr0.eq) goto loc_8275C594;
loc_8275C5AC:
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8275C5B8"))) PPC_WEAK_FUNC(sub_8275C5B8);
PPC_FUNC_IMPL(__imp__sub_8275C5B8) {
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8275C5C0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// lis r5,-32243
	ctx.r5.s64 = -2113077248;
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// li r31,16384
	r31.s64 = 16384;
	// lfs f0,27580(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27580);
	f0.f64 = double(temp.f32);
	// li r9,0
	ctx.r9.s64 = 0;
	// fmuls f11,f1,f0
	ctx.f11.f64 = double(float(ctx.f1.f64 * f0.f64));
	// lfs f0,16680(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 16680);
	f0.f64 = double(temp.f32);
	// fmuls f10,f1,f0
	ctx.f10.f64 = double(float(ctx.f1.f64 * f0.f64));
	// lfs f0,13776(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 13776);
	f0.f64 = double(temp.f32);
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// fctiwz f11,f11
	ctx.f11.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f11,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.f11.u64);
	// lwz r8,-52(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + -52);
	// fctiwz f11,f10
	ctx.f11.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f11,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.f11.u64);
	// lwz r5,-52(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + -52);
	// divw r29,r3,r8
	r29.s32 = ctx.r3.s32 / ctx.r8.s32;
	// mullw r11,r10,r5
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// twllei r8,0
	// cmpwi cr6,r11,16384
	cr6.compare<int32_t>(r11.s32, 16384, xer);
	// bge cr6,0x8275c640
	if (!cr6.lt) goto loc_8275C640;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
loc_8275C628:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mullw r11,r11,r5
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r5.s32);
	// cmpwi cr6,r11,16384
	cr6.compare<int32_t>(r11.s32, 16384, xer);
	// blt cr6,0x8275c628
	if (cr6.lt) goto loc_8275C628;
loc_8275C640:
	// addi r10,r29,2048
	ctx.r10.s64 = r29.s64 + 2048;
	// srawi r8,r10,12
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFFF) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 12;
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// bge cr6,0x8275c6f0
	if (!cr6.lt) goto loc_8275C6F0;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r30,-32125
	r30.s64 = -2105344000;
	// lfs f11,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// lwz r30,-3624(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + -3624);
loc_8275C664:
	// addis r31,r31,1
	r31.s64 = r31.s64 + 65536;
	// stfs f0,-64(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// addi r31,r31,-32768
	r31.s64 = r31.s64 + -32768;
	// cmpw cr6,r11,r31
	cr6.compare<int32_t>(r11.s32, r31.s32, xer);
	// bge cr6,0x8275c6cc
	if (!cr6.lt) goto loc_8275C6CC;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r4
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
loc_8275C680:
	// srawi r11,r11,7
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7F) != 0);
	r11.s64 = r11.s32 >> 7;
	// lwz r28,-64(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + -64);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,2,22,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x3FC;
	// lfsx f10,r10,r6
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	ctx.f10.f64 = double(temp.f32);
	// lfsx f9,r11,r30
	temp.u32 = PPC_LOAD_U32(r11.u32 + r30.u32);
	ctx.f9.f64 = double(temp.f32);
	// fadds f9,f9,f11
	ctx.f9.f64 = double(float(ctx.f9.f64 + ctx.f11.f64));
	// fmuls f10,f9,f10
	ctx.f10.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// stfs f10,-56(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// lwz r11,-56(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -56);
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// ble cr6,0x8275c6b4
	if (!cr6.gt) goto loc_8275C6B4;
	// stw r11,-64(r1)
	PPC_STORE_U32(ctx.r1.u32 + -64, r11.u32);
loc_8275C6B4:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r4
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r4.u32);
	// mullw r11,r10,r5
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// cmpw cr6,r11,r31
	cr6.compare<int32_t>(r11.s32, r31.s32, xer);
	// blt cr6,0x8275c680
	if (cr6.lt) goto loc_8275C680;
loc_8275C6CC:
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f10,-64(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -64);
	ctx.f10.f64 = double(temp.f32);
	// add r3,r3,r29
	ctx.r3.u64 = ctx.r3.u64 + r29.u64;
	// srawi r8,r3,12
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFF) != 0);
	ctx.r8.s64 = ctx.r3.s32 >> 12;
	// lfsx f9,r10,r6
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	ctx.f9.f64 = double(temp.f32);
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// fmadds f13,f9,f10,f13
	ctx.f13.f64 = double(float(ctx.f9.f64 * ctx.f10.f64 + ctx.f13.f64));
	// fmadds f12,f9,f9,f12
	ctx.f12.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f12.f64));
	// blt cr6,0x8275c664
	if (cr6.lt) goto loc_8275C664;
loc_8275C6F0:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,-28668(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28668);
	f0.f64 = double(temp.f32);
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lfs f0,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmsubs f0,f13,f0,f12
	f0.f64 = double(float(ctx.f13.f64 * f0.f64 - ctx.f12.f64));
	// fmuls f1,f0,f2
	ctx.f1.f64 = double(float(f0.f64 * ctx.f2.f64));
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8275C710"))) PPC_WEAK_FUNC(sub_8275C710);
PPC_FUNC_IMPL(__imp__sub_8275C710) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// fcmpu cr6,f2,f3
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f2.f64, ctx.f3.f64);
	// bgt cr6,0x8275c7ac
	if (cr6.gt) goto loc_8275C7AC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// lfs f12,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,-23960(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -23960);
	ctx.f13.f64 = double(temp.f32);
loc_8275C734:
	// fmadds f11,f2,f13,f12
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f2.f64 * ctx.f13.f64 + ctx.f12.f64));
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// fmr f0,f4
	f0.f64 = ctx.f4.f64;
	// fctiwz f11,f11
	ctx.f11.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f11,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.f11.u64);
	// lwz r4,-28(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + -28);
	// ble cr6,0x8275c788
	if (!cr6.gt) goto loc_8275C788;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// subf r5,r8,r10
	ctx.r5.s64 = ctx.r10.s64 - ctx.r8.s64;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
loc_8275C75C:
	// lwzx r31,r5,r11
	r31.u64 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	// lfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lwz r30,-3624(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + -3624);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// mullw r31,r31,r4
	r31.s64 = int64_t(r31.s32) * int64_t(ctx.r4.s32);
	// addis r31,r31,128
	r31.s64 = r31.s64 + 8388608;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// rlwinm r31,r31,10,22,29
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 10) & 0x3FC;
	// lfsx f10,r31,r30
	temp.u32 = PPC_LOAD_U32(r31.u32 + r30.u32);
	ctx.f10.f64 = double(temp.f32);
	// fmadds f0,f10,f11,f0
	f0.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + f0.f64));
	// bne 0x8275c75c
	if (!cr0.eq) goto loc_8275C75C;
loc_8275C788:
	// lfs f11,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// ble cr6,0x8275c7a0
	if (!cr6.gt) goto loc_8275C7A0;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// stfs f0,0(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// stfs f2,0(r11)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
loc_8275C7A0:
	// fadds f2,f1,f2
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// fcmpu cr6,f2,f3
	cr6.compare(ctx.f2.f64, ctx.f3.f64);
	// ble cr6,0x8275c734
	if (!cr6.gt) goto loc_8275C734;
loc_8275C7AC:
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275C7B8"))) PPC_WEAK_FUNC(sub_8275C7B8);
PPC_FUNC_IMPL(__imp__sub_8275C7B8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x827bd894
	ctx.lr = 0x8275C7E0;
	__imp__XexGetModuleHandle(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8275c7f8
	if (cr0.lt) goto loc_8275C7F8;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x827bd884
	ctx.lr = 0x8275C7F8;
	__imp__XexGetProcedureAddress(ctx, base);
loc_8275C7F8:
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
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

__attribute__((alias("__imp__sub_8275C810"))) PPC_WEAK_FUNC(sub_8275C810);
PPC_FUNC_IMPL(__imp__sub_8275C810) {
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
	ctx.lr = 0x8275C818;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// li r5,19
	ctx.r5.s64 = 19;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// addi r3,r1,81
	ctx.r3.s64 = ctx.r1.s64 + 81;
	// bl 0x823d9890
	ctx.lr = 0x8275C83C;
	sub_823D9890(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8275cb70
	ctx.lr = 0x8275C84C;
	sub_8275CB70(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x8275c8a4
	if (!cr0.eq) goto loc_8275C8A4;
	// lhz r11,82(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 82);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8275c868
	if (!cr0.eq) goto loc_8275C868;
	// li r30,22
	r30.s64 = 22;
	// b 0x8275c8a4
	goto loc_8275C8A4;
loc_8275C868:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r10,-21228(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -21228);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8275c880
	if (!cr6.eq) goto loc_8275C880;
	// li r30,1
	r30.s64 = 1;
	// b 0x8275c8a4
	goto loc_8275C8A4;
loc_8275C880:
	// lwz r11,-21228(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21228);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275C898;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8275c8a4
	if (!cr0.lt) goto loc_8275C8A4;
	// li r30,1167
	r30.s64 = 1167;
loc_8275C8A4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8275C8B0"))) PPC_WEAK_FUNC(sub_8275C8B0);
PPC_FUNC_IMPL(__imp__sub_8275C8B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-16384
	r11.s64 = -1073741824;
	// ori r11,r11,157
	r11.u64 = r11.u64 | 157;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bgt cr6,0x8275c924
	if (cr6.gt) goto loc_8275C924;
	// beq cr6,0x8275c91c
	if (cr6.eq) goto loc_8275C91C;
	// lis r11,-32768
	r11.s64 = -2147483648;
	// ori r11,r11,17
	r11.u64 = r11.u64 | 17;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// beq cr6,0x8275c914
	if (cr6.eq) goto loc_8275C914;
	// lis r11,-16384
	r11.s64 = -1073741824;
	// ori r11,r11,8
	r11.u64 = r11.u64 | 8;
	// subf. r11,r11,r3
	r11.s64 = ctx.r3.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8275c90c
	if (cr0.eq) goto loc_8275C90C;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// beq cr6,0x8275c904
	if (cr6.eq) goto loc_8275C904;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// beq cr6,0x8275c968
	if (cr6.eq) goto loc_8275C968;
	// cmplwi cr6,r11,146
	cr6.compare<uint32_t>(r11.u32, 146, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// li r3,14
	ctx.r3.s64 = 14;
	// blr 
	return;
loc_8275C904:
	// li r3,87
	ctx.r3.s64 = 87;
	// blr 
	return;
loc_8275C90C:
	// li r3,6
	ctx.r3.s64 = 6;
	// blr 
	return;
loc_8275C914:
	// li r3,170
	ctx.r3.s64 = 170;
	// blr 
	return;
loc_8275C91C:
	// li r3,1167
	ctx.r3.s64 = 1167;
	// blr 
	return;
loc_8275C924:
	// lis r11,-16384
	r11.s64 = -1073741824;
	// ori r11,r11,163
	r11.u64 = r11.u64 | 163;
	// subf. r11,r11,r3
	r11.s64 = ctx.r3.s64 - r11.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8275c978
	if (cr0.eq) goto loc_8275C978;
	// cmplwi cr6,r11,158
	cr6.compare<uint32_t>(r11.u32, 158, xer);
	// beq cr6,0x8275c970
	if (cr6.eq) goto loc_8275C970;
	// cmplwi cr6,r11,560
	cr6.compare<uint32_t>(r11.u32, 560, xer);
	// beq cr6,0x8275c968
	if (cr6.eq) goto loc_8275C968;
	// addis r11,r11,-16384
	r11.s64 = r11.s64 + -1073741824;
	// addic. r11,r11,163
	xer.ca = r11.u32 > 4294967132;
	r11.s64 = r11.s64 + 163;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8275c960
	if (cr0.eq) goto loc_8275C960;
	// cmplwi cr6,r11,259
	cr6.compare<uint32_t>(r11.u32, 259, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// li r3,997
	ctx.r3.s64 = 997;
	// blr 
	return;
loc_8275C960:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8275C968:
	// li r3,22
	ctx.r3.s64 = 22;
	// blr 
	return;
loc_8275C970:
	// li r3,1413
	ctx.r3.s64 = 1413;
	// blr 
	return;
loc_8275C978:
	// li r3,21
	ctx.r3.s64 = 21;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275C980"))) PPC_WEAK_FUNC(sub_8275C980);
PPC_FUNC_IMPL(__imp__sub_8275C980) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8275c810
	ctx.lr = 0x8275C99C;
	sub_8275C810(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8275c9cc
	if (!cr0.eq) goto loc_8275C9CC;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r10,-21224(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -21224);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8275c9cc
	if (cr6.eq) goto loc_8275C9CC;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275C9C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x8275c8b0
	ctx.lr = 0x8275C9CC;
	sub_8275C8B0(ctx, base);
loc_8275C9CC:
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

__attribute__((alias("__imp__sub_8275C9E0"))) PPC_WEAK_FUNC(sub_8275C9E0);
PPC_FUNC_IMPL(__imp__sub_8275C9E0) {
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
	ctx.lr = 0x8275C9E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x8275c810
	ctx.lr = 0x8275CA00;
	sub_8275C810(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8275ca38
	if (!cr0.eq) goto loc_8275CA38;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r10,-21204(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -21204);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8275ca38
	if (cr6.eq) goto loc_8275CA38;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275CA34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x8275c8b0
	ctx.lr = 0x8275CA38;
	sub_8275C8B0(ctx, base);
loc_8275CA38:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8275CA40"))) PPC_WEAK_FUNC(sub_8275CA40);
PPC_FUNC_IMPL(__imp__sub_8275CA40) {
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
	ctx.lr = 0x8275CA48;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x8275c810
	ctx.lr = 0x8275CA60;
	sub_8275C810(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8275ca98
	if (!cr0.eq) goto loc_8275CA98;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r10,-21196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -21196);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8275ca98
	if (cr6.eq) goto loc_8275CA98;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275CA94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x8275c8b0
	ctx.lr = 0x8275CA98;
	sub_8275C8B0(ctx, base);
loc_8275CA98:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8275CAA0"))) PPC_WEAK_FUNC(sub_8275CAA0);
PPC_FUNC_IMPL(__imp__sub_8275CAA0) {
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
	ctx.lr = 0x8275CAA8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// bl 0x8275c810
	ctx.lr = 0x8275CAC4;
	sub_8275C810(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8275cb00
	if (!cr0.eq) goto loc_8275CB00;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r10,-21212(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -21212);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8275cb00
	if (cr6.eq) goto loc_8275CB00;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275CAFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x8275c8b0
	ctx.lr = 0x8275CB00;
	sub_8275C8B0(ctx, base);
loc_8275CB00:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8275CB08"))) PPC_WEAK_FUNC(sub_8275CB08);
PPC_FUNC_IMPL(__imp__sub_8275CB08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8275c810
	ctx.lr = 0x8275CB24;
	sub_8275C810(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8275cb58
	if (!cr0.eq) goto loc_8275CB58;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r10,-21216(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -21216);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8275cb58
	if (cr6.eq) goto loc_8275CB58;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// li r4,4
	ctx.r4.s64 = 4;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275CB54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x8275c8b0
	ctx.lr = 0x8275CB58;
	sub_8275C8B0(ctx, base);
loc_8275CB58:
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

__attribute__((alias("__imp__sub_8275CB6C"))) PPC_WEAK_FUNC(sub_8275CB6C);
PPC_FUNC_IMPL(__imp__sub_8275CB6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275CB70"))) PPC_WEAK_FUNC(sub_8275CB70);
PPC_FUNC_IMPL(__imp__sub_8275CB70) {
	PPC_FUNC_PROLOGUE();
	// b 0x827bdc54
	__imp__XamInputGetCapabilities(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8275CB74"))) PPC_WEAK_FUNC(sub_8275CB74);
PPC_FUNC_IMPL(__imp__sub_8275CB74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275CB78"))) PPC_WEAK_FUNC(sub_8275CB78);
PPC_FUNC_IMPL(__imp__sub_8275CB78) {
	PPC_FUNC_PROLOGUE();
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x827bdc64
	__imp__XamInputGetState(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8275CB84"))) PPC_WEAK_FUNC(sub_8275CB84);
PPC_FUNC_IMPL(__imp__sub_8275CB84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275CB88"))) PPC_WEAK_FUNC(sub_8275CB88);
PPC_FUNC_IMPL(__imp__sub_8275CB88) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,2204(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2204);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// bne cr6,0x8275cc1c
	if (!cr6.eq) goto loc_8275CC1C;
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// cmplwi r10,0
	cr0.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne 0x8275cc1c
	if (!cr0.eq) goto loc_8275CC1C;
	// lhz r11,4(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmplwi cr6,r11,5611
	cr6.compare<uint32_t>(r11.u32, 5611, xer);
	// bge cr6,0x8275cc1c
	if (!cr6.lt) goto loc_8275CC1C;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x827bdc54
	ctx.lr = 0x8275CBE4;
	__imp__XamInputGetCapabilities(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne 0x8275cc1c
	if (!cr0.eq) goto loc_8275CC1C;
	// lbz r11,97(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 97);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x8275cc1c
	if (!cr6.eq) goto loc_8275CC1C;
	// lhz r11,98(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 98);
	// clrlwi. r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8275cc1c
	if (cr0.eq) goto loc_8275CC1C;
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8275cc1c
	if (cr0.eq) goto loc_8275CC1C;
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// sth r11,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r11.u16);
	// sth r10,82(r1)
	PPC_STORE_U16(ctx.r1.u32 + 82, ctx.r10.u16);
loc_8275CC1C:
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827bdc74
	ctx.lr = 0x8275CC38;
	__imp__XamInputSetState(ctx, base);
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

__attribute__((alias("__imp__sub_8275CC50"))) PPC_WEAK_FUNC(sub_8275CC50);
PPC_FUNC_IMPL(__imp__sub_8275CC50) {
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
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// cmplwi cr6,r3,255
	cr6.compare<uint32_t>(ctx.r3.u32, 255, xer);
	// bne cr6,0x8275cc74
	if (!cr6.eq) goto loc_8275CC74;
	// li r11,0
	r11.s64 = 0;
	// oris r4,r4,16384
	ctx.r4.u64 = ctx.r4.u64 | 1073741824;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
loc_8275CC74:
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// bl 0x827bdc84
	ctx.lr = 0x8275CC7C;
	__imp__XamInputGetKeystrokeEx(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275CC8C"))) PPC_WEAK_FUNC(sub_8275CC8C);
PPC_FUNC_IMPL(__imp__sub_8275CC8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275CC90"))) PPC_WEAK_FUNC(sub_8275CC90);
PPC_FUNC_IMPL(__imp__sub_8275CC90) {
	PPC_FUNC_PROLOGUE();
	// b 0x8244eee0
	sub_8244EEE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8275CC94"))) PPC_WEAK_FUNC(sub_8275CC94);
PPC_FUNC_IMPL(__imp__sub_8275CC94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275CC98"))) PPC_WEAK_FUNC(sub_8275CC98);
PPC_FUNC_IMPL(__imp__sub_8275CC98) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x827bdc94
	ctx.lr = 0x8275CCA8;
	__imp__XamUserGetSigninInfo(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8275ccb8
	if (cr0.lt) goto loc_8275CCB8;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8275ccd0
	goto loc_8275CCD0;
loc_8275CCB8:
	// rlwinm r11,r3,0,3,15
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1FFF0000;
	// lis r10,7
	ctx.r10.s64 = 458752;
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x8275ccd0
	if (cr6.eq) goto loc_8275CCD0;
	// li r3,1627
	ctx.r3.s64 = 1627;
loc_8275CCD0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275CCE0"))) PPC_WEAK_FUNC(sub_8275CCE0);
PPC_FUNC_IMPL(__imp__sub_8275CCE0) {
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
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x827bdc24
	ctx.lr = 0x8275CCF4;
	__imp__XMsgCancelIORequest(ctx, base);
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

__attribute__((alias("__imp__sub_8275CD08"))) PPC_WEAK_FUNC(sub_8275CD08);
PPC_FUNC_IMPL(__imp__sub_8275CD08) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,259
	cr6.compare<uint32_t>(r11.u32, 259, xer);
	// bne cr6,0x8275cd74
	if (!cr6.eq) goto loc_8275CD74;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x8275cd54
	if (cr6.eq) goto loc_8275CD54;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8275cd48
	if (cr6.eq) goto loc_8275CD48;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
loc_8275CD48:
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x82135db8
	ctx.lr = 0x8275CD50;
	sub_82135DB8(ctx, base);
	// b 0x8275cd58
	goto loc_8275CD58;
loc_8275CD54:
	// li r3,258
	ctx.r3.s64 = 258;
loc_8275CD58:
	// cmplwi cr6,r3,258
	cr6.compare<uint32_t>(ctx.r3.u32, 258, xer);
	// bne cr6,0x8275cd6c
	if (!cr6.eq) goto loc_8275CD6C;
	// li r3,996
	ctx.r3.s64 = 996;
	// bl 0x82135d38
	ctx.lr = 0x8275CD68;
	sub_82135D38(ctx, base);
	// b 0x8275cd94
	goto loc_8275CD94;
loc_8275CD6C:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8275cd94
	if (!cr6.eq) goto loc_8275CD94;
loc_8275CD74:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8275cd90
	if (cr6.lt) goto loc_8275CD90;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8275cd98
	goto loc_8275CD98;
loc_8275CD90:
	// bl 0x82135d58
	ctx.lr = 0x8275CD94;
	sub_82135D58(ctx, base);
loc_8275CD94:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8275CD98:
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

__attribute__((alias("__imp__sub_8275CDB0"))) PPC_WEAK_FUNC(sub_8275CDB0);
PPC_FUNC_IMPL(__imp__sub_8275CDB0) {
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
	ctx.lr = 0x8275CDB8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// li r7,34
	ctx.r7.s64 = 34;
	// lwz r11,14800(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 14800);
	// li r6,56
	ctx.r6.s64 = 56;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,32(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8275CDEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8275ce2c
	if (cr0.lt) goto loc_8275CE2C;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8275ce04
	if (cr6.eq) goto loc_8275CE04;
	// ld r11,96(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,0(r31)
	PPC_STORE_U64(r31.u32 + 0, r11.u64);
loc_8275CE04:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8275ce14
	if (cr6.eq) goto loc_8275CE14;
	// ld r11,104(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// std r11,0(r30)
	PPC_STORE_U64(r30.u32 + 0, r11.u64);
loc_8275CE14:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8275ce24
	if (cr6.eq) goto loc_8275CE24;
	// ld r11,112(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,0(r29)
	PPC_STORE_U64(r29.u32 + 0, r11.u64);
loc_8275CE24:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8275ce34
	goto loc_8275CE34;
loc_8275CE2C:
	// bl 0x82135d58
	ctx.lr = 0x8275CE30;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8275CE34:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8275CE3C"))) PPC_WEAK_FUNC(sub_8275CE3C);
PPC_FUNC_IMPL(__imp__sub_8275CE3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275CE40"))) PPC_WEAK_FUNC(sub_8275CE40);
PPC_FUNC_IMPL(__imp__sub_8275CE40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x827bdcb4
	ctx.lr = 0x8275CE54;
	__imp__NtCancelTimer(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8275ce68
	if (!cr0.lt) goto loc_8275CE68;
	// bl 0x82135d58
	ctx.lr = 0x8275CE60;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8275ce6c
	goto loc_8275CE6C;
loc_8275CE68:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8275CE6C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275CE7C"))) PPC_WEAK_FUNC(sub_8275CE7C);
PPC_FUNC_IMPL(__imp__sub_8275CE7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275CE80"))) PPC_WEAK_FUNC(sub_8275CE80);
PPC_FUNC_IMPL(__imp__sub_8275CE80) {
	PPC_FUNC_PROLOGUE();
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
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// clrlwi r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// bl 0x827bdcc4
	ctx.lr = 0x8275CEA8;
	__imp__NtSetTimerEx(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge 0x8275cebc
	if (!cr0.lt) goto loc_8275CEBC;
	// bl 0x82135d58
	ctx.lr = 0x8275CEB4;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8275cedc
	goto loc_8275CEDC;
loc_8275CEBC:
	// lis r11,16384
	r11.s64 = 1073741824;
	// ori r11,r11,37
	r11.u64 = r11.u64 | 37;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// li r3,50
	ctx.r3.s64 = 50;
	// beq cr6,0x8275ced4
	if (cr6.eq) goto loc_8275CED4;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8275CED4:
	// bl 0x82135d38
	ctx.lr = 0x8275CED8;
	sub_82135D38(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
loc_8275CEDC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275CEEC"))) PPC_WEAK_FUNC(sub_8275CEEC);
PPC_FUNC_IMPL(__imp__sub_8275CEEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275CEF0"))) PPC_WEAK_FUNC(sub_8275CEF0);
PPC_FUNC_IMPL(__imp__sub_8275CEF0) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8275cf20
	if (cr6.eq) goto loc_8275CF20;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8245ff00
	ctx.lr = 0x8275CF18;
	sub_8245FF00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x8275cf24
	goto loc_8275CF24;
loc_8275CF20:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8275CF24:
	// cntlzw r11,r31
	r11.u64 = r31.u32 == 0 ? 32 : __builtin_clz(r31.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rlwinm r5,r11,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// bl 0x827bdcd4
	ctx.lr = 0x8275CF34;
	__imp__NtCreateTimer(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8275cf5c
	if (cr0.lt) goto loc_8275CF5C;
	// lis r11,16384
	r11.s64 = 1073741824;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// li r3,183
	ctx.r3.s64 = 183;
	// beq cr6,0x8275cf50
	if (cr6.eq) goto loc_8275CF50;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8275CF50:
	// bl 0x82135d38
	ctx.lr = 0x8275CF54;
	sub_82135D38(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x8275cf64
	goto loc_8275CF64;
loc_8275CF5C:
	// bl 0x82135d58
	ctx.lr = 0x8275CF60;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8275CF64:
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

__attribute__((alias("__imp__sub_8275CF78"))) PPC_WEAK_FUNC(sub_8275CF78);
PPC_FUNC_IMPL(__imp__sub_8275CF78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r5,r9
	ctx.r5.u64 = ctx.r9.u64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x827bdba4
	ctx.lr = 0x8275CF94;
	__imp__NtDuplicateObject(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8275cfa4
	if (cr0.lt) goto loc_8275CFA4;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8275cfac
	goto loc_8275CFAC;
loc_8275CFA4:
	// bl 0x82135d58
	ctx.lr = 0x8275CFA8;
	sub_82135D58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8275CFAC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275CFBC"))) PPC_WEAK_FUNC(sub_8275CFBC);
PPC_FUNC_IMPL(__imp__sub_8275CFBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275CFC0"))) PPC_WEAK_FUNC(sub_8275CFC0);
PPC_FUNC_IMPL(__imp__sub_8275CFC0) {
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
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275cff0
	if (cr6.eq) goto loc_8275CFF0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8275CFF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8275CFF0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
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

__attribute__((alias("__imp__sub_8275D010"))) PPC_WEAK_FUNC(sub_8275D010);
PPC_FUNC_IMPL(__imp__sub_8275D010) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8275D018;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x824741f0
	ctx.lr = 0x8275D030;
	sub_824741F0(ctx, base);
	// lwz r4,24(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x82474300
	ctx.lr = 0x8275D03C;
	sub_82474300(ctx, base);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823a77b8
	ctx.lr = 0x8275D050;
	sub_823A77B8(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8275D05C"))) PPC_WEAK_FUNC(sub_8275D05C);
PPC_FUNC_IMPL(__imp__sub_8275D05C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275D060"))) PPC_WEAK_FUNC(sub_8275D060);
PPC_FUNC_IMPL(__imp__sub_8275D060) {
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
	ctx.lr = 0x8275D068;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x8246bef0
	ctx.lr = 0x8275D07C;
	sub_8246BEF0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,17492
	ctx.r9.s64 = r11.s64 + 17492;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r29,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r29.u32);
	// beq cr6,0x8275d0b0
	if (cr6.eq) goto loc_8275D0B0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8275D0B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8275D0B0:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275d0cc
	if (cr6.eq) goto loc_8275D0CC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8275D0CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8275D0CC:
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8275D0DC"))) PPC_WEAK_FUNC(sub_8275D0DC);
PPC_FUNC_IMPL(__imp__sub_8275D0DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275D0E0"))) PPC_WEAK_FUNC(sub_8275D0E0);
PPC_FUNC_IMPL(__imp__sub_8275D0E0) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,17492
	ctx.r10.s64 = r11.s64 + 17492;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275d11c
	if (cr6.eq) goto loc_8275D11C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8275D11C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8275D11C:
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,21656
	ctx.r9.s64 = ctx.r10.s64 + 21656;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// bl 0x8246bf58
	ctx.lr = 0x8275D13C;
	sub_8246BF58(ctx, base);
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

__attribute__((alias("__imp__sub_8275D150"))) PPC_WEAK_FUNC(sub_8275D150);
PPC_FUNC_IMPL(__imp__sub_8275D150) {
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
	// bl 0x8275d0e0
	ctx.lr = 0x8275D170;
	sub_8275D0E0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8275d188
	if (cr6.eq) goto loc_8275D188;
	// bl 0x82130588
	ctx.lr = 0x8275D184;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8275D188:
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

__attribute__((alias("__imp__sub_8275D1A0"))) PPC_WEAK_FUNC(sub_8275D1A0);
PPC_FUNC_IMPL(__imp__sub_8275D1A0) {
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
	// bl 0x82490568
	ctx.lr = 0x8275D1C0;
	sub_82490568(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r30,32
	ctx.r4.s64 = r30.s64 + 32;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x823db670
	ctx.lr = 0x8275D1D0;
	sub_823DB670(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,95(r31)
	PPC_STORE_U8(r31.u32 + 95, r11.u8);
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

__attribute__((alias("__imp__sub_8275D1F0"))) PPC_WEAK_FUNC(sub_8275D1F0);
PPC_FUNC_IMPL(__imp__sub_8275D1F0) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// addi r6,r11,-8044
	ctx.r6.s64 = r11.s64 + -8044;
	// addi r5,r10,3148
	ctx.r5.s64 = ctx.r10.s64 + 3148;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8275D224;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275d254
	if (cr6.eq) goto loc_8275D254;
	// lfs f2,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f2.f64 = double(temp.f32);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f1,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r3,32
	ctx.r4.s64 = ctx.r3.s64 + 32;
	// stfd f2,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f2.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// addi r3,r11,17776
	ctx.r3.s64 = r11.s64 + 17776;
	// bl 0x82130000
	ctx.lr = 0x8275D254;
	sub_82130000(ctx, base);
loc_8275D254:
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

__attribute__((alias("__imp__sub_8275D268"))) PPC_WEAK_FUNC(sub_8275D268);
PPC_FUNC_IMPL(__imp__sub_8275D268) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r11,-8044
	ctx.r6.s64 = r11.s64 + -8044;
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

__attribute__((alias("__imp__sub_8275D288"))) PPC_WEAK_FUNC(sub_8275D288);
PPC_FUNC_IMPL(__imp__sub_8275D288) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// addi r6,r11,-8044
	ctx.r6.s64 = r11.s64 + -8044;
	// addi r5,r10,3148
	ctx.r5.s64 = ctx.r10.s64 + 3148;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8275D2BC;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275d2ec
	if (cr6.eq) goto loc_8275D2EC;
	// lfs f2,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f2.f64 = double(temp.f32);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f1,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r3,32
	ctx.r4.s64 = ctx.r3.s64 + 32;
	// stfd f2,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f2.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// addi r3,r11,17804
	ctx.r3.s64 = r11.s64 + 17804;
	// bl 0x82130000
	ctx.lr = 0x8275D2EC;
	sub_82130000(ctx, base);
loc_8275D2EC:
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

__attribute__((alias("__imp__sub_8275D300"))) PPC_WEAK_FUNC(sub_8275D300);
PPC_FUNC_IMPL(__imp__sub_8275D300) {
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
	// bl 0x82490568
	ctx.lr = 0x8275D320;
	sub_82490568(ctx, base);
	// li r11,32
	r11.s64 = 32;
	// lvx128 v63,r30,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// lbz r10,52(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 52);
	// stb r10,52(r31)
	PPC_STORE_U8(r31.u32 + 52, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8275D354"))) PPC_WEAK_FUNC(sub_8275D354);
PPC_FUNC_IMPL(__imp__sub_8275D354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275D358"))) PPC_WEAK_FUNC(sub_8275D358);
PPC_FUNC_IMPL(__imp__sub_8275D358) {
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
	// li r3,96
	ctx.r3.s64 = 96;
	// bl 0x82130528
	ctx.lr = 0x8275D370;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8275d3ac
	if (cr6.eq) goto loc_8275D3AC;
	// bl 0x824905e0
	ctx.lr = 0x8275D380;
	sub_824905E0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-19612
	ctx.r9.s64 = r11.s64 + -19612;
	// stb r10,32(r31)
	PPC_STORE_U8(r31.u32 + 32, ctx.r10.u8);
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
loc_8275D3AC:
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

__attribute__((alias("__imp__sub_8275D3C4"))) PPC_WEAK_FUNC(sub_8275D3C4);
PPC_FUNC_IMPL(__imp__sub_8275D3C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275D3C8"))) PPC_WEAK_FUNC(sub_8275D3C8);
PPC_FUNC_IMPL(__imp__sub_8275D3C8) {
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
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,15280
	ctx.r4.s64 = r11.s64 + 15280;
	// lwz r11,-27428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x824a5b58
	ctx.lr = 0x8275D3F8;
	sub_824A5B58(ctx, base);
	// stw r3,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r3.u32);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lwz r11,-27428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// addi r4,r10,2692
	ctx.r4.s64 = ctx.r10.s64 + 2692;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x824a5b58
	ctx.lr = 0x8275D410;
	sub_824A5B58(ctx, base);
	// stw r3,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8275D42C"))) PPC_WEAK_FUNC(sub_8275D42C);
PPC_FUNC_IMPL(__imp__sub_8275D42C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275D430"))) PPC_WEAK_FUNC(sub_8275D430);
PPC_FUNC_IMPL(__imp__sub_8275D430) {
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
	// beq cr6,0x8275d4a8
	if (cr6.eq) goto loc_8275D4A8;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8275d46c
	if (cr6.eq) goto loc_8275D46C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8275D468;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8275d474
	goto loc_8275D474;
loc_8275D46C:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,-7004
	ctx.r3.s64 = r11.s64 + -7004;
loc_8275D474:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r4,r11,-3436
	ctx.r4.s64 = r11.s64 + -3436;
	// bl 0x823d9188
	ctx.lr = 0x8275D480;
	sub_823D9188(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8275d4a8
	if (cr6.eq) goto loc_8275D4A8;
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
loc_8275D4A8:
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

__attribute__((alias("__imp__sub_8275D4C0"))) PPC_WEAK_FUNC(sub_8275D4C0);
PPC_FUNC_IMPL(__imp__sub_8275D4C0) {
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
	// beq cr6,0x8275d538
	if (cr6.eq) goto loc_8275D538;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8275d4fc
	if (cr6.eq) goto loc_8275D4FC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8275D4F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8275d504
	goto loc_8275D504;
loc_8275D4FC:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,-7004
	ctx.r3.s64 = r11.s64 + -7004;
loc_8275D504:
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r4,r11,18492
	ctx.r4.s64 = r11.s64 + 18492;
	// bl 0x823d9188
	ctx.lr = 0x8275D510;
	sub_823D9188(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8275d538
	if (cr6.eq) goto loc_8275D538;
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
loc_8275D538:
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

__attribute__((alias("__imp__sub_8275D550"))) PPC_WEAK_FUNC(sub_8275D550);
PPC_FUNC_IMPL(__imp__sub_8275D550) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// addi r8,r10,17836
	ctx.r8.s64 = ctx.r10.s64 + 17836;
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r11.u32);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r11.u32);
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r11.u32);
	// stw r11,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r11.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r11,3040(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, r11.u32);
	// lwz r11,3040(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stw r11,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275D588"))) PPC_WEAK_FUNC(sub_8275D588);
PPC_FUNC_IMPL(__imp__sub_8275D588) {
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
	// addi r31,r11,-21188
	r31.s64 = r11.s64 + -21188;
	// lwz r11,-21188(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8275d6d4
	if (!cr6.eq) goto loc_8275D6D4;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8275D5B8;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275d5cc
	if (cr6.eq) goto loc_8275D5CC;
	// bl 0x821d5408
	ctx.lr = 0x8275D5C8;
	sub_821D5408(ctx, base);
	// b 0x8275d5d0
	goto loc_8275D5D0;
loc_8275D5CC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8275D5D0:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,20328
	ctx.r7.s64 = ctx.r10.s64 + 20328;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25672
	ctx.r9.s64 = r11.s64 + 25672;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32141
	ctx.r8.s64 = -2106392576;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,-29128
	ctx.r4.s64 = ctx.r8.s64 + -29128;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r7,r3,-3536
	ctx.r7.s64 = ctx.r3.s64 + -3536;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lis r30,-32115
	r30.s64 = -2104688640;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r10,-3512
	ctx.r5.s64 = ctx.r10.s64 + -3512;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r3,r9,-3476
	ctx.r3.s64 = ctx.r9.s64 + -3476;
	// li r10,52
	ctx.r10.s64 = 52;
	// lwz r4,20376(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20376);
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,48
	ctx.r8.s64 = 48;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// bne cr6,0x8275d66c
	if (!cr6.eq) goto loc_8275D66C;
	// bl 0x824906d8
	ctx.lr = 0x8275D668;
	sub_824906D8(ctx, base);
	// lwz r4,20376(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20376);
loc_8275D66C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x8275D678;
	sub_821D4458(ctx, base);
	// lwz r11,20376(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20376);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x8275D690;
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
	ctx.lr = 0x8275D6AC;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-3452
	ctx.r4.s64 = ctx.r8.s64 + -3452;
	// bl 0x821d4b00
	ctx.lr = 0x8275D6BC;
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
	ctx.lr = 0x8275D6D4;
	sub_821C0548(ctx, base);
loc_8275D6D4:
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

__attribute__((alias("__imp__sub_8275D6EC"))) PPC_WEAK_FUNC(sub_8275D6EC);
PPC_FUNC_IMPL(__imp__sub_8275D6EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275D6F0"))) PPC_WEAK_FUNC(sub_8275D6F0);
PPC_FUNC_IMPL(__imp__sub_8275D6F0) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r6,r11,-8004
	ctx.r6.s64 = r11.s64 + -8004;
	// addi r5,r10,3148
	ctx.r5.s64 = ctx.r10.s64 + 3148;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8275D72C;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275d770
	if (cr6.eq) goto loc_8275D770;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lwz r11,3040(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 3040);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// beq cr6,0x8275d758
	if (cr6.eq) goto loc_8275D758;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x824a5b00
	ctx.lr = 0x8275D750;
	sub_824A5B00(ctx, base);
	// bl 0x8275d430
	ctx.lr = 0x8275D754;
	sub_8275D430(ctx, base);
	// b 0x8275d770
	goto loc_8275D770;
loc_8275D758:
	// lwz r4,104(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// beq cr6,0x8275d770
	if (cr6.eq) goto loc_8275D770;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x824a5b00
	ctx.lr = 0x8275D76C;
	sub_824A5B00(ctx, base);
	// bl 0x8275d4c0
	ctx.lr = 0x8275D770;
	sub_8275D4C0(ctx, base);
loc_8275D770:
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

__attribute__((alias("__imp__sub_8275D788"))) PPC_WEAK_FUNC(sub_8275D788);
PPC_FUNC_IMPL(__imp__sub_8275D788) {
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
	// addi r31,r11,-21192
	r31.s64 = r11.s64 + -21192;
	// lwz r11,-21192(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21192);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8275d8b4
	if (!cr6.eq) goto loc_8275D8B4;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8275D7B8;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275d7cc
	if (cr6.eq) goto loc_8275D7CC;
	// bl 0x821d5408
	ctx.lr = 0x8275D7C8;
	sub_821D5408(ctx, base);
	// b 0x8275d7d0
	goto loc_8275D7D0;
loc_8275D7CC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8275D7D0:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,20300
	ctx.r7.s64 = ctx.r10.s64 + 20300;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25672
	ctx.r9.s64 = r11.s64 + 25672;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,96
	ctx.r5.s64 = 96;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32138
	ctx.r8.s64 = -2106195968;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,-11432
	ctx.r4.s64 = ctx.r8.s64 + -11432;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32115
	r30.s64 = -2104688640;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,-3568
	ctx.r9.s64 = ctx.r3.s64 + -3568;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,32
	ctx.r10.s64 = 32;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r4,20376(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20376);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x8275d84c
	if (!cr6.eq) goto loc_8275D84C;
	// bl 0x824906d8
	ctx.lr = 0x8275D848;
	sub_824906D8(ctx, base);
	// lwz r4,20376(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20376);
loc_8275D84C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x8275D858;
	sub_821D4458(ctx, base);
	// lwz r11,20376(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20376);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x8275D870;
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
	ctx.lr = 0x8275D88C;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-3544
	ctx.r4.s64 = ctx.r8.s64 + -3544;
	// bl 0x821d4b00
	ctx.lr = 0x8275D89C;
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
	ctx.lr = 0x8275D8B4;
	sub_821C0548(ctx, base);
loc_8275D8B4:
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

__attribute__((alias("__imp__sub_8275D8CC"))) PPC_WEAK_FUNC(sub_8275D8CC);
PPC_FUNC_IMPL(__imp__sub_8275D8CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275D8D0"))) PPC_WEAK_FUNC(sub_8275D8D0);
PPC_FUNC_IMPL(__imp__sub_8275D8D0) {
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
	// bl 0x824905e0
	ctx.lr = 0x8275D8E8;
	sub_824905E0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-19552
	ctx.r9.s64 = r11.s64 + -19552;
	// stb r10,32(r31)
	PPC_STORE_U8(r31.u32 + 32, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8275D914"))) PPC_WEAK_FUNC(sub_8275D914);
PPC_FUNC_IMPL(__imp__sub_8275D914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275D918"))) PPC_WEAK_FUNC(sub_8275D918);
PPC_FUNC_IMPL(__imp__sub_8275D918) {
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
	ctx.lr = 0x8275D938;
	sub_82490568(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8275D94C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// li r5,128
	ctx.r5.s64 = 128;
	// bl 0x823db670
	ctx.lr = 0x8275D95C;
	sub_823DB670(ctx, base);
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

__attribute__((alias("__imp__sub_8275D974"))) PPC_WEAK_FUNC(sub_8275D974);
PPC_FUNC_IMPL(__imp__sub_8275D974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275D978"))) PPC_WEAK_FUNC(sub_8275D978);
PPC_FUNC_IMPL(__imp__sub_8275D978) {
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
	// li r3,160
	ctx.r3.s64 = 160;
	// bl 0x82130528
	ctx.lr = 0x8275D990;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8275d9cc
	if (cr6.eq) goto loc_8275D9CC;
	// bl 0x824905e0
	ctx.lr = 0x8275D9A0;
	sub_824905E0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-19552
	ctx.r9.s64 = r11.s64 + -19552;
	// stb r10,32(r31)
	PPC_STORE_U8(r31.u32 + 32, ctx.r10.u8);
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
loc_8275D9CC:
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

__attribute__((alias("__imp__sub_8275D9E4"))) PPC_WEAK_FUNC(sub_8275D9E4);
PPC_FUNC_IMPL(__imp__sub_8275D9E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275D9E8"))) PPC_WEAK_FUNC(sub_8275D9E8);
PPC_FUNC_IMPL(__imp__sub_8275D9E8) {
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
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,15188
	ctx.r4.s64 = r11.s64 + 15188;
	// lwz r11,-27428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x824a5b58
	ctx.lr = 0x8275DA18;
	sub_824A5B58(ctx, base);
	// stw r3,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r3.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r11,-27428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// addi r4,r10,-18184
	ctx.r4.s64 = ctx.r10.s64 + -18184;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x824a5b58
	ctx.lr = 0x8275DA30;
	sub_824A5B58(ctx, base);
	// stw r3,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r3.u32);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lwz r11,-27428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r4,r9,15072
	ctx.r4.s64 = ctx.r9.s64 + 15072;
	// bl 0x824a5b58
	ctx.lr = 0x8275DA48;
	sub_824A5B58(ctx, base);
	// stw r3,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8275DA64"))) PPC_WEAK_FUNC(sub_8275DA64);
PPC_FUNC_IMPL(__imp__sub_8275DA64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275DA68"))) PPC_WEAK_FUNC(sub_8275DA68);
PPC_FUNC_IMPL(__imp__sub_8275DA68) {
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
	ctx.lr = 0x8275DA70;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-15292
	ctx.r10.s64 = r11.s64 + -15292;
	// addi r29,r31,100
	r29.s64 = r31.s64 + 100;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stw r30,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r30.u32);
	// bl 0x82548ac0
	ctx.lr = 0x8275DAA4;
	sub_82548AC0(ctx, base);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// addi r6,r9,18224
	ctx.r6.s64 = ctx.r9.s64 + 18224;
	// addi r5,r8,18192
	ctx.r5.s64 = ctx.r8.s64 + 18192;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stw r5,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r5.u32);
	// lwz r11,3040(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 3040);
	// stw r11,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r11.u32);
	// lwz r11,3040(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 3040);
	// stb r30,120(r31)
	PPC_STORE_U8(r31.u32 + 120, r30.u8);
	// stb r30,121(r31)
	PPC_STORE_U8(r31.u32 + 121, r30.u8);
	// stw r30,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r30.u32);
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
	// bl 0x82160450
	ctx.lr = 0x8275DAE0;
	sub_82160450(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275daf0
	if (cr6.eq) goto loc_8275DAF0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82548ba8
	ctx.lr = 0x8275DAF0;
	sub_82548BA8(ctx, base);
loc_8275DAF0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8275DAFC"))) PPC_WEAK_FUNC(sub_8275DAFC);
PPC_FUNC_IMPL(__imp__sub_8275DAFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275DB00"))) PPC_WEAK_FUNC(sub_8275DB00);
PPC_FUNC_IMPL(__imp__sub_8275DB00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8275DB08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r4,108(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x824a5b20
	ctx.lr = 0x8275DB24;
	sub_824A5B20(ctx, base);
	// stb r3,121(r31)
	PPC_STORE_U8(r31.u32 + 121, ctx.r3.u8);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r4,112(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// bl 0x824a5b20
	ctx.lr = 0x8275DB34;
	sub_824A5B20(ctx, base);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r10,r11,2256
	ctx.r10.s64 = r11.s64 + 2256;
	// stb r3,120(r31)
	PPC_STORE_U8(r31.u32 + 120, ctx.r3.u8);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8275db84
	if (cr6.eq) goto loc_8275DB84;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r4,112(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// bl 0x824a5b00
	ctx.lr = 0x8275DB64;
	sub_824A5B00(ctx, base);
	// bl 0x82737518
	ctx.lr = 0x8275DB68;
	sub_82737518(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,64
	ctx.r10.s64 = 64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r11,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r11.u32);
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8275dbac
	goto loc_8275DBAC;
loc_8275DB84:
	// lbz r11,121(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 121);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8275dbac
	if (cr6.eq) goto loc_8275DBAC;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r4,108(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// bl 0x824a5b00
	ctx.lr = 0x8275DB9C;
	sub_824A5B00(ctx, base);
	// bl 0x827375a8
	ctx.lr = 0x8275DBA0;
	sub_827375A8(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8275DBAC:
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// addi r30,r31,128
	r30.s64 = r31.s64 + 128;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275dbc4
	if (cr6.eq) goto loc_8275DBC4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x8275DBC4;
	sub_8213C218(ctx, base);
loc_8275DBC4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8275DBD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r31,100
	ctx.r3.s64 = r31.s64 + 100;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x82549720
	ctx.lr = 0x8275DBF4;
	sub_82549720(ctx, base);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275dc1c
	if (cr6.eq) goto loc_8275DC1C;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8213b860
	ctx.lr = 0x8275DC08;
	sub_8213B860(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c0c0
	ctx.lr = 0x8275DC1C;
	sub_8213C0C0(ctx, base);
loc_8275DC1C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8275DC24"))) PPC_WEAK_FUNC(sub_8275DC24);
PPC_FUNC_IMPL(__imp__sub_8275DC24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275DC28"))) PPC_WEAK_FUNC(sub_8275DC28);
PPC_FUNC_IMPL(__imp__sub_8275DC28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
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
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8275dcb4
	if (cr6.eq) goto loc_8275DCB4;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lbz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 120);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r11,2256
	ctx.r8.s64 = r11.s64 + 2256;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8275dc80
	if (cr6.eq) goto loc_8275DC80;
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// li r10,64
	ctx.r10.s64 = 64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8275dca8
	goto loc_8275DCA8;
loc_8275DC80:
	// lbz r11,121(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 121);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8275dca8
	if (cr6.eq) goto loc_8275DCA8;
	// lwz r3,16(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	// lwz r4,108(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// bl 0x824a5b00
	ctx.lr = 0x8275DC98;
	sub_824A5B00(ctx, base);
	// bl 0x827375a8
	ctx.lr = 0x8275DC9C;
	sub_827375A8(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8275DCA8:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// bl 0x8213b860
	ctx.lr = 0x8275DCB4;
	sub_8213B860(ctx, base);
loc_8275DCB4:
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

__attribute__((alias("__imp__sub_8275DCC8"))) PPC_WEAK_FUNC(sub_8275DCC8);
PPC_FUNC_IMPL(__imp__sub_8275DCC8) {
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
	// addi r31,r11,-21184
	r31.s64 = r11.s64 + -21184;
	// lwz r11,-21184(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21184);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8275ddf4
	if (!cr6.eq) goto loc_8275DDF4;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8275DCF8;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275dd0c
	if (cr6.eq) goto loc_8275DD0C;
	// bl 0x821d5408
	ctx.lr = 0x8275DD08;
	sub_821D5408(ctx, base);
	// b 0x8275dd10
	goto loc_8275DD10;
loc_8275DD0C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8275DD10:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,20600
	ctx.r7.s64 = ctx.r10.s64 + 20600;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25672
	ctx.r9.s64 = r11.s64 + 25672;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,160
	ctx.r5.s64 = 160;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32138
	ctx.r8.s64 = -2106195968;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,-9864
	ctx.r4.s64 = ctx.r8.s64 + -9864;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32115
	r30.s64 = -2104688640;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,-3368
	ctx.r9.s64 = ctx.r3.s64 + -3368;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,32
	ctx.r10.s64 = 32;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r4,20376(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20376);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x8275dd8c
	if (!cr6.eq) goto loc_8275DD8C;
	// bl 0x824906d8
	ctx.lr = 0x8275DD88;
	sub_824906D8(ctx, base);
	// lwz r4,20376(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20376);
loc_8275DD8C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x8275DD98;
	sub_821D4458(ctx, base);
	// lwz r11,20376(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20376);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x8275DDB0;
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
	ctx.lr = 0x8275DDCC;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-3344
	ctx.r4.s64 = ctx.r8.s64 + -3344;
	// bl 0x821d4b00
	ctx.lr = 0x8275DDDC;
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
	ctx.lr = 0x8275DDF4;
	sub_821C0548(ctx, base);
loc_8275DDF4:
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

__attribute__((alias("__imp__sub_8275DE0C"))) PPC_WEAK_FUNC(sub_8275DE0C);
PPC_FUNC_IMPL(__imp__sub_8275DE0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275DE10"))) PPC_WEAK_FUNC(sub_8275DE10);
PPC_FUNC_IMPL(__imp__sub_8275DE10) {
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
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,18948
	ctx.r9.s64 = r11.s64 + 18948;
	// addi r3,r10,3998
	ctx.r3.s64 = ctx.r10.s64 + 3998;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// bl 0x821378b8
	ctx.lr = 0x8275DE3C;
	sub_821378B8(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f13,14192(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,17032(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 17032);
	f0.f64 = double(temp.f32);
	// stfs f13,8(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
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

__attribute__((alias("__imp__sub_8275DE74"))) PPC_WEAK_FUNC(sub_8275DE74);
PPC_FUNC_IMPL(__imp__sub_8275DE74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275DE78"))) PPC_WEAK_FUNC(sub_8275DE78);
PPC_FUNC_IMPL(__imp__sub_8275DE78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-21180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21180);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275DE84"))) PPC_WEAK_FUNC(sub_8275DE84);
PPC_FUNC_IMPL(__imp__sub_8275DE84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275DE88"))) PPC_WEAK_FUNC(sub_8275DE88);
PPC_FUNC_IMPL(__imp__sub_8275DE88) {
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
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x821d2aa0
	ctx.lr = 0x8275DEAC;
	sub_821D2AA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x8275DEB4;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8275decc
	if (cr6.eq) goto loc_8275DECC;
	// bl 0x82130588
	ctx.lr = 0x8275DEC8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8275DECC:
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

__attribute__((alias("__imp__sub_8275DEE4"))) PPC_WEAK_FUNC(sub_8275DEE4);
PPC_FUNC_IMPL(__imp__sub_8275DEE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275DEE8"))) PPC_WEAK_FUNC(sub_8275DEE8);
PPC_FUNC_IMPL(__imp__sub_8275DEE8) {
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
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x8275DEFC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275df18
	if (cr6.eq) goto loc_8275DF18;
	// bl 0x8275de10
	ctx.lr = 0x8275DF08;
	sub_8275DE10(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8275DF18:
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

__attribute__((alias("__imp__sub_8275DF2C"))) PPC_WEAK_FUNC(sub_8275DF2C);
PPC_FUNC_IMPL(__imp__sub_8275DF2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275DF30"))) PPC_WEAK_FUNC(sub_8275DF30);
PPC_FUNC_IMPL(__imp__sub_8275DF30) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8275DF38;
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8275DF58;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8275dfbc
	if (!cr6.gt) goto loc_8275DFBC;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r31,r27,8
	r31.s64 = r27.s64 + 8;
	// lis r28,-32256
	r28.s64 = -2113929216;
	// lfs f31,17032(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	f31.f64 = double(temp.f32);
	// addi r29,r11,18948
	r29.s64 = r11.s64 + 18948;
	// lfs f30,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f30.f64 = double(temp.f32);
loc_8275DF84:
	// addic. r11,r31,-8
	xer.ca = r31.u32 > 7;
	r11.s64 = r31.s64 + -8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8275dfb0
	if (cr0.eq) goto loc_8275DFB0;
	// stw r29,-8(r31)
	PPC_STORE_U32(r31.u32 + -8, r29.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82130528
	ctx.lr = 0x8275DF98;
	sub_82130528(ctx, base);
	// lbz r11,3998(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 3998);
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// stw r3,-4(r31)
	PPC_STORE_U32(r31.u32 + -4, ctx.r3.u32);
	// stfs f30,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// stfs f31,4(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stfs f31,8(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
loc_8275DFB0:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,20
	r31.s64 = r31.s64 + 20;
	// bne 0x8275df84
	if (!cr0.eq) goto loc_8275DF84;
loc_8275DFBC:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8275DFD0"))) PPC_WEAK_FUNC(sub_8275DFD0);
PPC_FUNC_IMPL(__imp__sub_8275DFD0) {
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
	ctx.lr = 0x8275DFD8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r29,r11,30576
	r29.s64 = r11.s64 + 30576;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,580(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 580);
	// bl 0x821ca540
	ctx.lr = 0x8275DFF4;
	sub_821CA540(ctx, base);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r31,2828(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2828);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8275E010;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r4,-32243
	ctx.r4.s64 = -2113077248;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r7,5276
	ctx.r5.s64 = ctx.r7.s64 + 5276;
	// addi r4,r4,18956
	ctx.r4.s64 = ctx.r4.s64 + 18956;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c04b0
	ctx.lr = 0x8275E034;
	sub_821C04B0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8275E03C;
	sub_821C9A90(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8275E044"))) PPC_WEAK_FUNC(sub_8275E044);
PPC_FUNC_IMPL(__imp__sub_8275E044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275E048"))) PPC_WEAK_FUNC(sub_8275E048);
PPC_FUNC_IMPL(__imp__sub_8275E048) {
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
	ctx.lr = 0x8275E050;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r10,r11,18972
	ctx.r10.s64 = r11.s64 + 18972;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lwz r3,632(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 632);
	// bl 0x82130588
	ctx.lr = 0x8275E06C;
	sub_82130588(ctx, base);
	// lis r31,-32125
	r31.s64 = -2105344000;
	// lwz r9,2828(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// rlwinm r11,r8,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 15) & 0x1;
	// mr r29,r11
	r29.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8275e08c
	if (cr6.eq) goto loc_8275E08C;
	// bl 0x821bbea8
	ctx.lr = 0x8275E08C;
	sub_821BBEA8(ctx, base);
loc_8275E08C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-21180(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -21180);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8275e0a4
	if (cr6.eq) goto loc_8275E0A4;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x8275E0A4;
	sub_821BFA90(ctx, base);
loc_8275E0A4:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8275e0b0
	if (cr6.eq) goto loc_8275E0B0;
	// bl 0x821bbf00
	ctx.lr = 0x8275E0B0;
	sub_821BBF00(ctx, base);
loc_8275E0B0:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r29,r11
	r29.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8275e0cc
	if (cr6.eq) goto loc_8275E0CC;
	// bl 0x821bbea8
	ctx.lr = 0x8275E0CC;
	sub_821BBEA8(ctx, base);
loc_8275E0CC:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-21176(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -21176);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8275e0e4
	if (cr6.eq) goto loc_8275E0E4;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x8275E0E4;
	sub_821BFA90(ctx, base);
loc_8275E0E4:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8275e0f0
	if (cr6.eq) goto loc_8275E0F0;
	// bl 0x821bbf00
	ctx.lr = 0x8275E0F0;
	sub_821BBF00(ctx, base);
loc_8275E0F0:
	// lhz r5,62(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 62);
	// addi r3,r30,56
	ctx.r3.s64 = r30.s64 + 56;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8275e108
	if (cr6.eq) goto loc_8275E108;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x82728de0
	ctx.lr = 0x8275E108;
	sub_82728DE0(ctx, base);
loc_8275E108:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8275E110;
	sub_821D2028(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8275E118"))) PPC_WEAK_FUNC(sub_8275E118);
PPC_FUNC_IMPL(__imp__sub_8275E118) {
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
	// bne cr6,0x8275e15c
	if (!cr6.eq) goto loc_8275E15C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x8275e154
	if (cr6.eq) goto loc_8275E154;
	// bl 0x8275df30
	ctx.lr = 0x8275E150;
	sub_8275DF30(ctx, base);
	// b 0x8275e158
	goto loc_8275E158;
loc_8275E154:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8275E158:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_8275E15C:
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

__attribute__((alias("__imp__sub_8275E178"))) PPC_WEAK_FUNC(sub_8275E178);
PPC_FUNC_IMPL(__imp__sub_8275E178) {
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
	ctx.lr = 0x8275E180;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-21180
	r31.s64 = r11.s64 + -21180;
	// lwz r11,-21180(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21180);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8275e2b0
	if (!cr6.eq) goto loc_8275E2B0;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8275E1A0;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275e1b4
	if (cr6.eq) goto loc_8275E1B4;
	// bl 0x821d5408
	ctx.lr = 0x8275E1B0;
	sub_821D5408(ctx, base);
	// b 0x8275e1b8
	goto loc_8275E1B8;
loc_8275E1B4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8275E1B8:
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,18980
	ctx.r7.s64 = ctx.r10.s64 + 18980;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,20
	ctx.r5.s64 = 20;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32138
	ctx.r8.s64 = -2106195968;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,-8472
	ctx.r4.s64 = ctx.r8.s64 + -8472;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r5,r3,-3332
	ctx.r5.s64 = ctx.r3.s64 + -3332;
	// addi r4,r10,-3308
	ctx.r4.s64 = ctx.r10.s64 + -3308;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r30,r9,-3284
	r30.s64 = ctx.r9.s64 + -3284;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r29,r8,-3260
	r29.s64 = ctx.r8.s64 + -3260;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// li r9,8
	ctx.r9.s64 = 8;
	// li r8,12
	ctx.r8.s64 = 12;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// stw r8,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r8.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r7,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r7.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821d4458
	ctx.lr = 0x8275E25C;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8275E26C;
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
	ctx.lr = 0x8275E288;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-3236
	ctx.r4.s64 = ctx.r8.s64 + -3236;
	// bl 0x821d4b00
	ctx.lr = 0x8275E298;
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
	ctx.lr = 0x8275E2B0;
	sub_821C0548(ctx, base);
loc_8275E2B0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8275E2B8"))) PPC_WEAK_FUNC(sub_8275E2B8);
PPC_FUNC_IMPL(__imp__sub_8275E2B8) {
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
	// bl 0x8275e048
	ctx.lr = 0x8275E2D8;
	sub_8275E048(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8275e2f0
	if (cr6.eq) goto loc_8275E2F0;
	// bl 0x82130588
	ctx.lr = 0x8275E2EC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8275E2F0:
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

__attribute__((alias("__imp__sub_8275E308"))) PPC_WEAK_FUNC(sub_8275E308);
PPC_FUNC_IMPL(__imp__sub_8275E308) {
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
	// addi r31,r11,-21176
	r31.s64 = r11.s64 + -21176;
	// lwz r11,-21176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21176);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8275e500
	if (!cr6.eq) goto loc_8275E500;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8275E338;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275e348
	if (cr6.eq) goto loc_8275E348;
	// bl 0x821d5408
	ctx.lr = 0x8275E344;
	sub_821D5408(ctx, base);
	// b 0x8275e34c
	goto loc_8275E34C;
loc_8275E348:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8275E34C:
	// lis r11,-32208
	r11.s64 = -2110783488;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r8,-32243
	ctx.r8.s64 = -2113077248;
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// addi r11,r8,19008
	r11.s64 = ctx.r8.s64 + 19008;
	// li r10,1448
	ctx.r10.s64 = 1448;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// addi r7,r7,-3216
	ctx.r7.s64 = ctx.r7.s64 + -3216;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r5,r5,-3192
	ctx.r5.s64 = ctx.r5.s64 + -3192;
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,8
	ctx.r10.s64 = 8;
	// addi r4,r4,-3168
	ctx.r4.s64 = ctx.r4.s64 + -3168;
	// li r9,12
	ctx.r9.s64 = 12;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// lis r30,-32125
	r30.s64 = -2105344000;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r5,r11,-3096
	ctx.r5.s64 = r11.s64 + -3096;
	// addi r7,r3,-3144
	ctx.r7.s64 = ctx.r3.s64 + -3144;
	// stw r8,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r8.u32);
	// addi r6,r30,-3120
	ctx.r6.s64 = r30.s64 + -3120;
	// li r10,20
	ctx.r10.s64 = 20;
	// li r9,24
	ctx.r9.s64 = 24;
	// li r8,28
	ctx.r8.s64 = 28;
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stw r8,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r8.u32);
	// addi r7,r4,-3072
	ctx.r7.s64 = ctx.r4.s64 + -3072;
	// addi r5,r11,-3024
	ctx.r5.s64 = r11.s64 + -3024;
	// addi r6,r3,-3048
	ctx.r6.s64 = ctx.r3.s64 + -3048;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,36
	ctx.r9.s64 = 36;
	// li r8,37
	ctx.r8.s64 = 37;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// stw r8,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r8.u32);
	// addi r7,r4,-3000
	ctx.r7.s64 = ctx.r4.s64 + -3000;
	// addi r5,r11,-2952
	ctx.r5.s64 = r11.s64 + -2952;
	// addi r6,r3,-2976
	ctx.r6.s64 = ctx.r3.s64 + -2976;
	// li r10,38
	ctx.r10.s64 = 38;
	// li r9,40
	ctx.r9.s64 = 40;
	// li r8,44
	ctx.r8.s64 = 44;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r8,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r8.u32);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// addi r5,r11,-2776
	ctx.r5.s64 = r11.s64 + -2776;
	// addi r7,r4,-2928
	ctx.r7.s64 = ctx.r4.s64 + -2928;
	// addi r6,r3,-2904
	ctx.r6.s64 = ctx.r3.s64 + -2904;
	// li r10,48
	ctx.r10.s64 = 48;
	// li r9,52
	ctx.r9.s64 = 52;
	// lwz r11,-21180(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21180);
	// li r8,56
	ctx.r8.s64 = 56;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// stw r8,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r8.u32);
	// bne cr6,0x8275e490
	if (!cr6.eq) goto loc_8275E490;
	// bl 0x8275e178
	ctx.lr = 0x8275E48C;
	sub_8275E178(ctx, base);
	// lwz r11,-21180(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -21180);
loc_8275E490:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r10,-2880
	ctx.r9.s64 = ctx.r10.s64 + -2880;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r11.u32);
	// bl 0x821d4458
	ctx.lr = 0x8275E4AC;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8275E4BC;
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
	ctx.lr = 0x8275E4D8;
	sub_821D41D0(ctx, base);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r6,-2840
	ctx.r4.s64 = ctx.r6.s64 + -2840;
	// bl 0x821d4b00
	ctx.lr = 0x8275E4E8;
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
	ctx.lr = 0x8275E500;
	sub_821C0548(ctx, base);
loc_8275E500:
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

__attribute__((alias("__imp__sub_8275E518"))) PPC_WEAK_FUNC(sub_8275E518);
PPC_FUNC_IMPL(__imp__sub_8275E518) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8275E520;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lis r7,-32248
	ctx.r7.s64 = -2113404928;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lfs f11,-12072(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12072);
	ctx.f11.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stfs f13,4(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lfs f12,17032(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 17032);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lfs f10,8116(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8116);
	ctx.f10.f64 = double(temp.f32);
	// li r30,0
	r30.s64 = 0;
	// lfs f9,3732(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3732);
	ctx.f9.f64 = double(temp.f32);
	// addi r10,r11,18972
	ctx.r10.s64 = r11.s64 + 18972;
	// lfs f8,27632(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 27632);
	ctx.f8.f64 = double(temp.f32);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lfs f7,14884(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14884);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,31016(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 31016);
	ctx.f6.f64 = double(temp.f32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stfs f11,8(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stb r30,36(r31)
	PPC_STORE_U8(r31.u32 + 36, r30.u8);
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stb r30,37(r31)
	PPC_STORE_U8(r31.u32 + 37, r30.u8);
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stb r30,38(r31)
	PPC_STORE_U8(r31.u32 + 38, r30.u8);
	// stfs f12,20(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// addi r8,r9,1952
	ctx.r8.s64 = ctx.r9.s64 + 1952;
	// stfs f10,24(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// li r7,2048
	ctx.r7.s64 = 2048;
	// stfs f9,28(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// addi r27,r31,636
	r27.s64 = r31.s64 + 636;
	// stfs f8,32(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f0,40(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stfs f12,44(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// stfs f7,48(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f6,52(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
	// sth r30,60(r31)
	PPC_STORE_U16(r31.u32 + 60, r30.u16);
	// sth r30,62(r31)
	PPC_STORE_U16(r31.u32 + 62, r30.u16);
	// stw r30,576(r31)
	PPC_STORE_U32(r31.u32 + 576, r30.u32);
	// stfs f13,596(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 596, temp.u32);
	// stw r8,580(r31)
	PPC_STORE_U32(r31.u32 + 580, ctx.r8.u32);
	// stw r30,584(r31)
	PPC_STORE_U32(r31.u32 + 584, r30.u32);
	// stw r30,588(r31)
	PPC_STORE_U32(r31.u32 + 588, r30.u32);
	// stw r30,592(r31)
	PPC_STORE_U32(r31.u32 + 592, r30.u32);
	// stw r30,600(r31)
	PPC_STORE_U32(r31.u32 + 600, r30.u32);
	// stw r30,604(r31)
	PPC_STORE_U32(r31.u32 + 604, r30.u32);
	// stw r30,608(r31)
	PPC_STORE_U32(r31.u32 + 608, r30.u32);
	// stw r30,612(r31)
	PPC_STORE_U32(r31.u32 + 612, r30.u32);
	// stw r30,616(r31)
	PPC_STORE_U32(r31.u32 + 616, r30.u32);
	// stw r30,620(r31)
	PPC_STORE_U32(r31.u32 + 620, r30.u32);
	// stw r7,624(r31)
	PPC_STORE_U32(r31.u32 + 624, ctx.r7.u32);
	// stw r30,628(r31)
	PPC_STORE_U32(r31.u32 + 628, r30.u32);
	// stw r30,632(r31)
	PPC_STORE_U32(r31.u32 + 632, r30.u32);
	// bl 0x8260b730
	ctx.lr = 0x8275E61C;
	sub_8260B730(ctx, base);
	// lis r26,-32125
	r26.s64 = -2105344000;
	// stb r30,1412(r31)
	PPC_STORE_U8(r31.u32 + 1412, r30.u8);
	// addi r29,r31,1412
	r29.s64 = r31.s64 + 1412;
	// stb r30,1413(r31)
	PPC_STORE_U8(r31.u32 + 1413, r30.u8);
	// addi r28,r31,1424
	r28.s64 = r31.s64 + 1424;
	// stb r30,1414(r31)
	PPC_STORE_U8(r31.u32 + 1414, r30.u8);
	// stb r30,1415(r31)
	PPC_STORE_U8(r31.u32 + 1415, r30.u8);
	// stb r30,1416(r31)
	PPC_STORE_U8(r31.u32 + 1416, r30.u8);
	// stw r30,1420(r31)
	PPC_STORE_U32(r31.u32 + 1420, r30.u32);
	// stb r30,1424(r31)
	PPC_STORE_U8(r31.u32 + 1424, r30.u8);
	// stb r30,1425(r31)
	PPC_STORE_U8(r31.u32 + 1425, r30.u8);
	// stb r30,1426(r31)
	PPC_STORE_U8(r31.u32 + 1426, r30.u8);
	// stb r30,1427(r31)
	PPC_STORE_U8(r31.u32 + 1427, r30.u8);
	// stb r30,1428(r31)
	PPC_STORE_U8(r31.u32 + 1428, r30.u8);
	// stw r30,1432(r31)
	PPC_STORE_U32(r31.u32 + 1432, r30.u32);
	// stb r30,1444(r31)
	PPC_STORE_U8(r31.u32 + 1444, r30.u8);
	// stb r30,1445(r31)
	PPC_STORE_U8(r31.u32 + 1445, r30.u8);
	// lwz r11,2828(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 2828);
	// lwz r6,40(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r6,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 15) & 0x1;
	// mr r25,r11
	r25.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8275e67c
	if (cr6.eq) goto loc_8275E67C;
	// bl 0x821bbea8
	ctx.lr = 0x8275E67C;
	sub_821BBEA8(ctx, base);
loc_8275E67C:
	// bl 0x8275e178
	ctx.lr = 0x8275E680;
	sub_8275E178(ctx, base);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x8275e68c
	if (cr6.eq) goto loc_8275E68C;
	// bl 0x821bbf00
	ctx.lr = 0x8275E68C;
	sub_821BBF00(ctx, base);
loc_8275E68C:
	// lwz r11,2828(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r26,r11
	r26.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8275e6a8
	if (cr6.eq) goto loc_8275E6A8;
	// bl 0x821bbea8
	ctx.lr = 0x8275E6A8;
	sub_821BBEA8(ctx, base);
loc_8275E6A8:
	// bl 0x8275e308
	ctx.lr = 0x8275E6AC;
	sub_8275E308(ctx, base);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8275e6b8
	if (cr6.eq) goto loc_8275E6B8;
	// bl 0x821bbf00
	ctx.lr = 0x8275E6B8;
	sub_821BBF00(ctx, base);
loc_8275E6B8:
	// stw r30,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r30.u32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,56
	ctx.r5.s64 = 56;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8260b740
	ctx.lr = 0x8275E6D4;
	sub_8260B740(ctx, base);
	// li r7,-1
	ctx.r7.s64 = -1;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8260b740
	ctx.lr = 0x8275E6EC;
	sub_8260B740(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r29,r11,-21152
	r29.s64 = r11.s64 + -21152;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c0750
	ctx.lr = 0x8275E700;
	sub_821C0750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8275e720
	if (cr6.eq) goto loc_8275E720;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// stb r8,37(r31)
	PPC_STORE_U8(r31.u32 + 37, ctx.r8.u8);
loc_8275E720:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// bl 0x821c0750
	ctx.lr = 0x8275E72C;
	sub_821C0750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8275e74c
	if (cr6.eq) goto loc_8275E74C;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// stb r8,38(r31)
	PPC_STORE_U8(r31.u32 + 38, ctx.r8.u8);
loc_8275E74C:
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// lwz r11,624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 624);
	// stw r30,620(r31)
	PPC_STORE_U32(r31.u32 + 620, r30.u32);
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// stw r30,604(r31)
	PPC_STORE_U32(r31.u32 + 604, r30.u32);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// ble cr6,0x8275e770
	if (!cr6.gt) goto loc_8275E770;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8275E770:
	// bl 0x82130528
	ctx.lr = 0x8275E774;
	sub_82130528(ctx, base);
	// addi r10,r31,64
	ctx.r10.s64 = r31.s64 + 64;
	// stw r3,632(r31)
	PPC_STORE_U32(r31.u32 + 632, ctx.r3.u32);
	// li r11,128
	r11.s64 = 128;
loc_8275E780:
	// lwz r9,512(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 512);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,512(r10)
	PPC_STORE_U32(ctx.r10.u32 + 512, ctx.r9.u32);
	// stwx r30,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, r30.u32);
	// bne 0x8275e780
	if (!cr0.eq) goto loc_8275E780;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8275E7A8"))) PPC_WEAK_FUNC(sub_8275E7A8);
PPC_FUNC_IMPL(__imp__sub_8275E7A8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x824905e0
	ctx.lr = 0x8275E7C0;
	sub_824905E0(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r9,32
	ctx.r9.s64 = 32;
	// addi r8,r10,-14224
	ctx.r8.s64 = ctx.r10.s64 + -14224;
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stfs f0,172(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
	// stb r7,48(r31)
	PPC_STORE_U8(r31.u32 + 48, ctx.r7.u8);
	// stvx128 v63,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

__attribute__((alias("__imp__sub_8275E804"))) PPC_WEAK_FUNC(sub_8275E804);
PPC_FUNC_IMPL(__imp__sub_8275E804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275E808"))) PPC_WEAK_FUNC(sub_8275E808);
PPC_FUNC_IMPL(__imp__sub_8275E808) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82490568
	ctx.lr = 0x8275E828;
	sub_82490568(ctx, base);
	// li r5,124
	ctx.r5.s64 = 124;
	// addi r4,r31,48
	ctx.r4.s64 = r31.s64 + 48;
	// addi r3,r30,48
	ctx.r3.s64 = r30.s64 + 48;
	// bl 0x823db670
	ctx.lr = 0x8275E838;
	sub_823DB670(ctx, base);
	// li r11,32
	r11.s64 = 32;
	// lvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r30,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,172(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 172);
	f0.f64 = double(temp.f32);
	// stfs f0,172(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 172, temp.u32);
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

__attribute__((alias("__imp__sub_8275E864"))) PPC_WEAK_FUNC(sub_8275E864);
PPC_FUNC_IMPL(__imp__sub_8275E864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275E868"))) PPC_WEAK_FUNC(sub_8275E868);
PPC_FUNC_IMPL(__imp__sub_8275E868) {
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
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
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

__attribute__((alias("__imp__sub_8275E8A0"))) PPC_WEAK_FUNC(sub_8275E8A0);
PPC_FUNC_IMPL(__imp__sub_8275E8A0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275E8A4"))) PPC_WEAK_FUNC(sub_8275E8A4);
PPC_FUNC_IMPL(__imp__sub_8275E8A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275E8A8"))) PPC_WEAK_FUNC(sub_8275E8A8);
PPC_FUNC_IMPL(__imp__sub_8275E8A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,176
	ctx.r3.s64 = 176;
	// bl 0x82130528
	ctx.lr = 0x8275E8C0;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8275e914
	if (cr6.eq) goto loc_8275E914;
	// bl 0x824905e0
	ctx.lr = 0x8275E8D0;
	sub_824905E0(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r9,32
	ctx.r9.s64 = 32;
	// addi r8,r10,-14224
	ctx.r8.s64 = ctx.r10.s64 + -14224;
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stfs f0,172(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
	// stb r7,48(r31)
	PPC_STORE_U8(r31.u32 + 48, ctx.r7.u8);
	// stvx128 v63,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
loc_8275E914:
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

__attribute__((alias("__imp__sub_8275E92C"))) PPC_WEAK_FUNC(sub_8275E92C);
PPC_FUNC_IMPL(__imp__sub_8275E92C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275E930"))) PPC_WEAK_FUNC(sub_8275E930);
PPC_FUNC_IMPL(__imp__sub_8275E930) {
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
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,15280
	ctx.r4.s64 = r11.s64 + 15280;
	// lwz r11,-27428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x824a5b58
	ctx.lr = 0x8275E960;
	sub_824A5B58(ctx, base);
	// stw r3,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r3.u32);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lwz r11,-27428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// addi r4,r10,19368
	ctx.r4.s64 = ctx.r10.s64 + 19368;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x824a5b58
	ctx.lr = 0x8275E978;
	sub_824A5B58(ctx, base);
	// stw r3,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r3.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r11,-27428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r4,r9,-18184
	ctx.r4.s64 = ctx.r9.s64 + -18184;
	// bl 0x824a5b58
	ctx.lr = 0x8275E990;
	sub_824A5B58(ctx, base);
	// stw r3,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r3.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r11,-27428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r4,r8,-18172
	ctx.r4.s64 = ctx.r8.s64 + -18172;
	// bl 0x824a5b58
	ctx.lr = 0x8275E9A8;
	sub_824A5B58(ctx, base);
	// stw r3,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r3.u32);
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// lwz r11,-27428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r4,r7,15244
	ctx.r4.s64 = ctx.r7.s64 + 15244;
	// bl 0x824a5b58
	ctx.lr = 0x8275E9C0;
	sub_824A5B58(ctx, base);
	// stw r3,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8275E9DC"))) PPC_WEAK_FUNC(sub_8275E9DC);
PPC_FUNC_IMPL(__imp__sub_8275E9DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275E9E0"))) PPC_WEAK_FUNC(sub_8275E9E0);
PPC_FUNC_IMPL(__imp__sub_8275E9E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// addi r8,r10,19384
	ctx.r8.s64 = ctx.r10.s64 + 19384;
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r11.u32);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r11.u32);
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r11.u32);
	// stw r11,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r11.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r11,3040(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, r11.u32);
	// lwz r11,3040(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stw r11,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275EA18"))) PPC_WEAK_FUNC(sub_8275EA18);
PPC_FUNC_IMPL(__imp__sub_8275EA18) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-15292
	ctx.r9.s64 = r11.s64 + -15292;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8275ea4c
	if (cr6.eq) goto loc_8275EA4C;
	// bl 0x82130588
	ctx.lr = 0x8275EA48;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8275EA4C:
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

__attribute__((alias("__imp__sub_8275EA60"))) PPC_WEAK_FUNC(sub_8275EA60);
PPC_FUNC_IMPL(__imp__sub_8275EA60) {
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
	ctx.lr = 0x8275EA68;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
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
	ctx.lr = 0x8275EA84;
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
	ctx.lr = 0x8275EA98;
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
	ctx.lr = 0x8275EAAC;
	sub_824A5B20(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8275ead8
	if (cr6.eq) goto loc_8275EAD8;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,116(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 116);
	// bl 0x824a5b00
	ctx.lr = 0x8275EAC4;
	sub_824A5B00(ctx, base);
	// bl 0x82736a58
	ctx.lr = 0x8275EAC8;
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
	// blt cr6,0x8275ebc8
	if (cr6.lt) goto loc_8275EBC8;
loc_8275EAD8:
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
	ctx.lr = 0x8275EAF4;
	sub_824804D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// bne cr6,0x8275eb34
	if (!cr6.eq) goto loc_8275EB34;
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
	ctx.lr = 0x8275EB1C;
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
	ctx.lr = 0x8275EB30;
	sub_824804D0(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
loc_8275EB34:
	// lwz r30,20(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8275ebc8
	if (cr6.eq) goto loc_8275EBC8;
	// addi r4,r27,32
	ctx.r4.s64 = r27.s64 + 32;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8247a178
	ctx.lr = 0x8275EB4C;
	sub_8247A178(ctx, base);
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8275eb88
	if (cr6.eq) goto loc_8275EB88;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,100(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 100);
	// bl 0x824a5b00
	ctx.lr = 0x8275EB64;
	sub_824A5B00(ctx, base);
	// bl 0x8275d430
	ctx.lr = 0x8275EB68;
	sub_8275D430(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8247a128
	ctx.lr = 0x8275EB78;
	sub_8247A128(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8247a838
	ctx.lr = 0x8275EB80;
	sub_8247A838(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_8275EB88:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8275ebc8
	if (cr6.eq) goto loc_8275EBC8;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,108(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 108);
	// bl 0x824a5b00
	ctx.lr = 0x8275EBA0;
	sub_824A5B00(ctx, base);
	// bl 0x827375a8
	ctx.lr = 0x8275EBA4;
	sub_827375A8(ctx, base);
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
	ctx.lr = 0x8275EBC0;
	sub_8247A020(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8247a838
	ctx.lr = 0x8275EBC8;
	sub_8247A838(ctx, base);
loc_8275EBC8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8275EBD0"))) PPC_WEAK_FUNC(sub_8275EBD0);
PPC_FUNC_IMPL(__imp__sub_8275EBD0) {
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
	// addi r31,r11,-21132
	r31.s64 = r11.s64 + -21132;
	// lwz r11,-21132(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21132);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8275ed1c
	if (!cr6.eq) goto loc_8275ED1C;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8275EC00;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275ec14
	if (cr6.eq) goto loc_8275EC14;
	// bl 0x821d5408
	ctx.lr = 0x8275EC10;
	sub_821D5408(ctx, base);
	// b 0x8275ec18
	goto loc_8275EC18;
loc_8275EC14:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8275EC18:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,20272
	ctx.r7.s64 = ctx.r10.s64 + 20272;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25672
	ctx.r9.s64 = r11.s64 + 25672;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,176
	ctx.r5.s64 = 176;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32138
	ctx.r8.s64 = -2106195968;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,-5976
	ctx.r4.s64 = ctx.r8.s64 + -5976;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r7,r3,-2684
	ctx.r7.s64 = ctx.r3.s64 + -2684;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lis r30,-32115
	r30.s64 = -2104688640;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r10,-2660
	ctx.r5.s64 = ctx.r10.s64 + -2660;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r3,r9,-2624
	ctx.r3.s64 = ctx.r9.s64 + -2624;
	// li r10,48
	ctx.r10.s64 = 48;
	// lwz r4,20376(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20376);
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,172
	ctx.r8.s64 = 172;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// bne cr6,0x8275ecb4
	if (!cr6.eq) goto loc_8275ECB4;
	// bl 0x824906d8
	ctx.lr = 0x8275ECB0;
	sub_824906D8(ctx, base);
	// lwz r4,20376(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20376);
loc_8275ECB4:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x8275ECC0;
	sub_821D4458(ctx, base);
	// lwz r11,20376(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20376);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x8275ECD8;
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
	ctx.lr = 0x8275ECF4;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-2600
	ctx.r4.s64 = ctx.r8.s64 + -2600;
	// bl 0x821d4b00
	ctx.lr = 0x8275ED04;
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
	ctx.lr = 0x8275ED1C;
	sub_821C0548(ctx, base);
loc_8275ED1C:
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

__attribute__((alias("__imp__sub_8275ED34"))) PPC_WEAK_FUNC(sub_8275ED34);
PPC_FUNC_IMPL(__imp__sub_8275ED34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275ED38"))) PPC_WEAK_FUNC(sub_8275ED38);
PPC_FUNC_IMPL(__imp__sub_8275ED38) {
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
	// bl 0x824905e0
	ctx.lr = 0x8275ED50;
	sub_824905E0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// li r8,-1
	ctx.r8.s64 = -1;
	// addi r7,r9,-14204
	ctx.r7.s64 = ctx.r9.s64 + -14204;
	// lfs f0,14880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14880);
	f0.f64 = double(temp.f32);
	// stw r8,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r8.u32);
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
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

__attribute__((alias("__imp__sub_8275ED94"))) PPC_WEAK_FUNC(sub_8275ED94);
PPC_FUNC_IMPL(__imp__sub_8275ED94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275ED98"))) PPC_WEAK_FUNC(sub_8275ED98);
PPC_FUNC_IMPL(__imp__sub_8275ED98) {
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
	ctx.lr = 0x8275EDB8;
	sub_82490568(ctx, base);
	// lfs f0,32(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 32);
	f0.f64 = double(temp.f32);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// lfs f13,36(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
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

__attribute__((alias("__imp__sub_8275EDE8"))) PPC_WEAK_FUNC(sub_8275EDE8);
PPC_FUNC_IMPL(__imp__sub_8275EDE8) {
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
	// bl 0x824905e0
	ctx.lr = 0x8275EE00;
	sub_824905E0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// li r8,-1
	ctx.r8.s64 = -1;
	// addi r7,r9,-14172
	ctx.r7.s64 = ctx.r9.s64 + -14172;
	// lfs f13,14880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14880);
	ctx.f13.f64 = double(temp.f32);
	// stw r8,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r8.u32);
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stfs f13,32(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f0,36(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// stfs f0,44(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
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

__attribute__((alias("__imp__sub_8275EE48"))) PPC_WEAK_FUNC(sub_8275EE48);
PPC_FUNC_IMPL(__imp__sub_8275EE48) {
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
	ctx.lr = 0x8275EE68;
	sub_82490568(ctx, base);
	// lfs f0,32(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 32);
	f0.f64 = double(temp.f32);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// lfs f13,36(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// lwz r11,40(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// lfs f12,44(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,44(r31)
	temp.f32 = float(ctx.f12.f64);
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

__attribute__((alias("__imp__sub_8275EEA0"))) PPC_WEAK_FUNC(sub_8275EEA0);
PPC_FUNC_IMPL(__imp__sub_8275EEA0) {
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
	// bl 0x824905e0
	ctx.lr = 0x8275EEB8;
	sub_824905E0(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32243
	ctx.r7.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// addi r6,r7,-14140
	ctx.r6.s64 = ctx.r7.s64 + -14140;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stb r11,108(r31)
	PPC_STORE_U8(r31.u32 + 108, r11.u8);
	// lfs f12,14192(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14192);
	ctx.f12.f64 = double(temp.f32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stfs f0,96(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stb r11,32(r31)
	PPC_STORE_U8(r31.u32 + 32, r11.u8);
	// stfs f13,100(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f12,104(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stb r11,109(r31)
	PPC_STORE_U8(r31.u32 + 109, r11.u8);
	// stb r11,110(r31)
	PPC_STORE_U8(r31.u32 + 110, r11.u8);
	// stb r11,111(r31)
	PPC_STORE_U8(r31.u32 + 111, r11.u8);
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

__attribute__((alias("__imp__sub_8275EF18"))) PPC_WEAK_FUNC(sub_8275EF18);
PPC_FUNC_IMPL(__imp__sub_8275EF18) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82490568
	ctx.lr = 0x8275EF38;
	sub_82490568(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r31,32
	ctx.r4.s64 = r31.s64 + 32;
	// addi r3,r30,32
	ctx.r3.s64 = r30.s64 + 32;
	// bl 0x823db670
	ctx.lr = 0x8275EF48;
	sub_823DB670(ctx, base);
	// lfs f0,96(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 96);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 96, temp.u32);
	// lfs f13,100(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,100(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 100, temp.u32);
	// lfs f12,104(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,104(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 104, temp.u32);
	// lbz r11,108(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 108);
	// stb r11,108(r30)
	PPC_STORE_U8(r30.u32 + 108, r11.u8);
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

__attribute__((alias("__imp__sub_8275EF80"))) PPC_WEAK_FUNC(sub_8275EF80);
PPC_FUNC_IMPL(__imp__sub_8275EF80) {
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
	// li r3,44
	ctx.r3.s64 = 44;
	// bl 0x82130528
	ctx.lr = 0x8275EF98;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8275efec
	if (cr6.eq) goto loc_8275EFEC;
	// bl 0x824905e0
	ctx.lr = 0x8275EFA8;
	sub_824905E0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// li r8,-1
	ctx.r8.s64 = -1;
	// addi r7,r9,-14204
	ctx.r7.s64 = ctx.r9.s64 + -14204;
	// lfs f0,14880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14880);
	f0.f64 = double(temp.f32);
	// stw r8,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r8.u32);
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
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
loc_8275EFEC:
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

__attribute__((alias("__imp__sub_8275F004"))) PPC_WEAK_FUNC(sub_8275F004);
PPC_FUNC_IMPL(__imp__sub_8275F004) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275F008"))) PPC_WEAK_FUNC(sub_8275F008);
PPC_FUNC_IMPL(__imp__sub_8275F008) {
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
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,15220
	ctx.r4.s64 = r11.s64 + 15220;
	// lwz r11,-27428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x824a5b58
	ctx.lr = 0x8275F038;
	sub_824A5B58(ctx, base);
	// stw r3,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r3.u32);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lwz r11,-27428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// addi r4,r10,15208
	ctx.r4.s64 = ctx.r10.s64 + 15208;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x824a5b58
	ctx.lr = 0x8275F050;
	sub_824A5B58(ctx, base);
	// stw r3,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r3.u32);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lwz r11,-27428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r4,r9,15160
	ctx.r4.s64 = ctx.r9.s64 + 15160;
	// bl 0x824a5b58
	ctx.lr = 0x8275F068;
	sub_824A5B58(ctx, base);
	// stw r3,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r3.u32);
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// lwz r11,-27428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r4,r8,15148
	ctx.r4.s64 = ctx.r8.s64 + 15148;
	// bl 0x824a5b58
	ctx.lr = 0x8275F080;
	sub_824A5B58(ctx, base);
	// stw r3,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8275F09C"))) PPC_WEAK_FUNC(sub_8275F09C);
PPC_FUNC_IMPL(__imp__sub_8275F09C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275F0A0"))) PPC_WEAK_FUNC(sub_8275F0A0);
PPC_FUNC_IMPL(__imp__sub_8275F0A0) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8275F0A8;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,84(r4)
	r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 84);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8275f130
	if (cr6.eq) goto loc_8275F130;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x8248a510
	ctx.lr = 0x8275F0C8;
	sub_8248A510(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lbz r11,70(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 70);
	// lbz r10,71(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 71);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x8275f130
	if (!cr6.lt) goto loc_8275F130;
	// rlwinm r31,r11,2,0,29
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r29,r11,r10
	r29.s64 = ctx.r10.s64 - r11.s64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r28,0
	r28.s64 = 0;
	// lfs f31,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
loc_8275F100:
	// lwz r11,144(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 144);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275f124
	if (cr6.eq) goto loc_8275F124;
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x824a5038
	ctx.lr = 0x8275F11C;
	sub_824A5038(ctx, base);
	// lwz r11,144(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 144);
	// stwx r28,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r28.u32);
loc_8275F124:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x8275f100
	if (!cr0.eq) goto loc_8275F100;
loc_8275F130:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8275F13C"))) PPC_WEAK_FUNC(sub_8275F13C);
PPC_FUNC_IMPL(__imp__sub_8275F13C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275F140"))) PPC_WEAK_FUNC(sub_8275F140);
PPC_FUNC_IMPL(__imp__sub_8275F140) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r10,19708
	ctx.r8.s64 = ctx.r10.s64 + 19708;
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r11.u32);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r11.u32);
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r11.u32);
	// stw r11,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r11.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r11,3040(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, r11.u32);
	// lwz r11,3040(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stw r11,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, r11.u32);
	// lwz r11,3040(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, r11.u32);
	// lwz r11,3040(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stw r11,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, r11.u32);
	// lwz r11,3040(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stw r11,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, r11.u32);
	// lwz r11,3040(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275F198"))) PPC_WEAK_FUNC(sub_8275F198);
PPC_FUNC_IMPL(__imp__sub_8275F198) {
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
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,15220
	ctx.r4.s64 = r11.s64 + 15220;
	// lwz r11,-27428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x824a5b58
	ctx.lr = 0x8275F1C8;
	sub_824A5B58(ctx, base);
	// stw r3,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r3.u32);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lwz r11,-27428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// addi r4,r10,15208
	ctx.r4.s64 = ctx.r10.s64 + 15208;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x824a5b58
	ctx.lr = 0x8275F1E0;
	sub_824A5B58(ctx, base);
	// stw r3,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r3.u32);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lwz r11,-27428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r4,r9,15160
	ctx.r4.s64 = ctx.r9.s64 + 15160;
	// bl 0x824a5b58
	ctx.lr = 0x8275F1F8;
	sub_824A5B58(ctx, base);
	// stw r3,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r3.u32);
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// lwz r11,-27428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r4,r8,15116
	ctx.r4.s64 = ctx.r8.s64 + 15116;
	// bl 0x824a5b58
	ctx.lr = 0x8275F210;
	sub_824A5B58(ctx, base);
	// stw r3,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r3.u32);
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// lwz r11,-27428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r4,r7,15148
	ctx.r4.s64 = ctx.r7.s64 + 15148;
	// bl 0x824a5b58
	ctx.lr = 0x8275F228;
	sub_824A5B58(ctx, base);
	// stw r3,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r3.u32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lwz r11,-27428(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r4,r6,-18184
	ctx.r4.s64 = ctx.r6.s64 + -18184;
	// bl 0x824a5b58
	ctx.lr = 0x8275F240;
	sub_824A5B58(ctx, base);
	// stw r3,120(r31)
	PPC_STORE_U32(r31.u32 + 120, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8275F25C"))) PPC_WEAK_FUNC(sub_8275F25C);
PPC_FUNC_IMPL(__imp__sub_8275F25C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275F260"))) PPC_WEAK_FUNC(sub_8275F260);
PPC_FUNC_IMPL(__imp__sub_8275F260) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// addi r8,r10,19736
	ctx.r8.s64 = ctx.r10.s64 + 19736;
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r11.u32);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r11.u32);
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r11.u32);
	// stw r11,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r11.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r11,3040(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275F290"))) PPC_WEAK_FUNC(sub_8275F290);
PPC_FUNC_IMPL(__imp__sub_8275F290) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,15160
	ctx.r4.s64 = ctx.r10.s64 + 15160;
	// lwz r11,-27428(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x824a5b58
	ctx.lr = 0x8275F2BC;
	sub_824A5B58(ctx, base);
	// stw r3,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8275F2D4"))) PPC_WEAK_FUNC(sub_8275F2D4);
PPC_FUNC_IMPL(__imp__sub_8275F2D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275F2D8"))) PPC_WEAK_FUNC(sub_8275F2D8);
PPC_FUNC_IMPL(__imp__sub_8275F2D8) {
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
	// beq cr6,0x8275f350
	if (cr6.eq) goto loc_8275F350;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8275f314
	if (cr6.eq) goto loc_8275F314;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8275F310;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8275f31c
	goto loc_8275F31C;
loc_8275F314:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,-7004
	ctx.r3.s64 = r11.s64 + -7004;
loc_8275F31C:
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r4,r11,-28936
	ctx.r4.s64 = r11.s64 + -28936;
	// bl 0x823d9188
	ctx.lr = 0x8275F328;
	sub_823D9188(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8275f350
	if (cr6.eq) goto loc_8275F350;
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
loc_8275F350:
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

__attribute__((alias("__imp__sub_8275F368"))) PPC_WEAK_FUNC(sub_8275F368);
PPC_FUNC_IMPL(__imp__sub_8275F368) {
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
	// beq cr6,0x8275f3e0
	if (cr6.eq) goto loc_8275F3E0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8275f3a4
	if (cr6.eq) goto loc_8275F3A4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8275F3A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8275f3ac
	goto loc_8275F3AC;
loc_8275F3A4:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,-7004
	ctx.r3.s64 = r11.s64 + -7004;
loc_8275F3AC:
	// lis r11,-32128
	r11.s64 = -2105540608;
	// addi r4,r11,-29080
	ctx.r4.s64 = r11.s64 + -29080;
	// bl 0x823d9188
	ctx.lr = 0x8275F3B8;
	sub_823D9188(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8275f3e0
	if (cr6.eq) goto loc_8275F3E0;
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
loc_8275F3E0:
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

__attribute__((alias("__imp__sub_8275F3F8"))) PPC_WEAK_FUNC(sub_8275F3F8);
PPC_FUNC_IMPL(__imp__sub_8275F3F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// addi r8,r10,19764
	ctx.r8.s64 = ctx.r10.s64 + 19764;
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r11.u32);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r11.u32);
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r11.u32);
	// stw r11,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, r11.u32);
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// lwz r11,3040(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, r11.u32);
	// lwz r11,3040(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stw r11,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, r11.u32);
	// lwz r11,3040(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, r11.u32);
	// lwz r11,3040(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stw r11,116(r3)
	PPC_STORE_U32(ctx.r3.u32 + 116, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8275F440"))) PPC_WEAK_FUNC(sub_8275F440);
PPC_FUNC_IMPL(__imp__sub_8275F440) {
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
	ctx.lr = 0x8275F448;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-21124
	r31.s64 = r11.s64 + -21124;
	// lwz r11,-21124(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21124);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8275f594
	if (!cr6.eq) goto loc_8275F594;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8275F468;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275f47c
	if (cr6.eq) goto loc_8275F47C;
	// bl 0x821d5408
	ctx.lr = 0x8275F478;
	sub_821D5408(ctx, base);
	// b 0x8275f480
	goto loc_8275F480;
loc_8275F47C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8275F480:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,20496
	ctx.r7.s64 = ctx.r10.s64 + 20496;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25672
	ctx.r9.s64 = r11.s64 + 25672;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,48
	ctx.r5.s64 = 48;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32141
	ctx.r8.s64 = -2106392576;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,26712
	ctx.r4.s64 = ctx.r8.s64 + 26712;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r5,r3,-2492
	ctx.r5.s64 = ctx.r3.s64 + -2492;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r30,-32115
	r30.s64 = -2104688640;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r3,r10,-2468
	ctx.r3.s64 = ctx.r10.s64 + -2468;
	// addi r29,r9,-2444
	r29.s64 = ctx.r9.s64 + -2444;
	// lwz r4,20376(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20376);
	// addi r11,r8,-2420
	r11.s64 = ctx.r8.s64 + -2420;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,36
	ctx.r9.s64 = 36;
	// li r8,40
	ctx.r8.s64 = 40;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// li r7,44
	ctx.r7.s64 = 44;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r8,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r8.u32);
	// stw r7,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r7.u32);
	// bne cr6,0x8275f52c
	if (!cr6.eq) goto loc_8275F52C;
	// bl 0x824906d8
	ctx.lr = 0x8275F528;
	sub_824906D8(ctx, base);
	// lwz r4,20376(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20376);
loc_8275F52C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x8275F538;
	sub_821D4458(ctx, base);
	// lwz r11,20376(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20376);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x8275F550;
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
	ctx.lr = 0x8275F56C;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-2396
	ctx.r4.s64 = ctx.r8.s64 + -2396;
	// bl 0x821d4b00
	ctx.lr = 0x8275F57C;
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
	ctx.lr = 0x8275F594;
	sub_821C0548(ctx, base);
loc_8275F594:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8275F59C"))) PPC_WEAK_FUNC(sub_8275F59C);
PPC_FUNC_IMPL(__imp__sub_8275F59C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275F5A0"))) PPC_WEAK_FUNC(sub_8275F5A0);
PPC_FUNC_IMPL(__imp__sub_8275F5A0) {
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
	ctx.lr = 0x8275F5A8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-21120
	r31.s64 = r11.s64 + -21120;
	// lwz r11,-21120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21120);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8275f704
	if (!cr6.eq) goto loc_8275F704;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8275F5C8;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275f5dc
	if (cr6.eq) goto loc_8275F5DC;
	// bl 0x821d5408
	ctx.lr = 0x8275F5D8;
	sub_821D5408(ctx, base);
	// b 0x8275f5e0
	goto loc_8275F5E0;
loc_8275F5DC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8275F5E0:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,20552
	ctx.r7.s64 = ctx.r10.s64 + 20552;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25672
	ctx.r9.s64 = r11.s64 + 25672;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,112
	ctx.r5.s64 = 112;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32141
	ctx.r8.s64 = -2106392576;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r4,r8,26848
	ctx.r4.s64 = ctx.r8.s64 + 26848;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r30,-32115
	r30.s64 = -2104688640;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r29,r10,-2352
	r29.s64 = ctx.r10.s64 + -2352;
	// addi r6,r9,-2328
	ctx.r6.s64 = ctx.r9.s64 + -2328;
	// lwz r4,20376(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20376);
	// addi r28,r8,-2304
	r28.s64 = ctx.r8.s64 + -2304;
	// addi r3,r3,-2376
	ctx.r3.s64 = ctx.r3.s64 + -2376;
	// addi r5,r5,-2280
	ctx.r5.s64 = ctx.r5.s64 + -2280;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,96
	ctx.r9.s64 = 96;
	// li r8,100
	ctx.r8.s64 = 100;
	// li r7,104
	ctx.r7.s64 = 104;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// li r11,108
	r11.s64 = 108;
	// stw r9,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r9.u32);
	// stw r8,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r8.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r7,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r7.u32);
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// bne cr6,0x8275f69c
	if (!cr6.eq) goto loc_8275F69C;
	// bl 0x824906d8
	ctx.lr = 0x8275F698;
	sub_824906D8(ctx, base);
	// lwz r4,20376(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20376);
loc_8275F69C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x8275F6A8;
	sub_821D4458(ctx, base);
	// lwz r11,20376(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20376);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x8275F6C0;
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
	ctx.lr = 0x8275F6DC;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-2256
	ctx.r4.s64 = ctx.r8.s64 + -2256;
	// bl 0x821d4b00
	ctx.lr = 0x8275F6EC;
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
	ctx.lr = 0x8275F704;
	sub_821C0548(ctx, base);
loc_8275F704:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8275F70C"))) PPC_WEAK_FUNC(sub_8275F70C);
PPC_FUNC_IMPL(__imp__sub_8275F70C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275F710"))) PPC_WEAK_FUNC(sub_8275F710);
PPC_FUNC_IMPL(__imp__sub_8275F710) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8275F718;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lis r29,-32249
	r29.s64 = -2113470464;
	// lfs f13,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// li r28,1
	r28.s64 = 1;
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x8275f7a8
	if (cr6.lt) goto loc_8275F7A8;
	// lwz r4,100(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// lwz r11,3040(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3040);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// beq cr6,0x8275f7a8
	if (cr6.eq) goto loc_8275F7A8;
	// lwz r10,104(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 104);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x8275f7a8
	if (cr6.eq) goto loc_8275F7A8;
	// lwz r3,16(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// bl 0x824a5b00
	ctx.lr = 0x8275F770;
	sub_824A5B00(ctx, base);
	// bl 0x82736a58
	ctx.lr = 0x8275F774;
	sub_82736A58(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,16(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// lwz r4,104(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 104);
	// lfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f31.f64 = double(temp.f32);
	// bl 0x824a5b00
	ctx.lr = 0x8275F788;
	sub_824A5B00(ctx, base);
	// bl 0x82736a58
	ctx.lr = 0x8275F78C;
	sub_82736A58(ctx, base);
	// lfs f0,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8275f7a4
	if (cr6.lt) goto loc_8275F7A4;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x8275f7a8
	if (cr6.lt) goto loc_8275F7A8;
loc_8275F7A4:
	// li r28,0
	r28.s64 = 0;
loc_8275F7A8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8275f830
	if (!cr6.lt) goto loc_8275F830;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f0,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x821ce460
	ctx.lr = 0x8275F7DC;
	sub_821CE460(ctx, base);
	// lis r9,23772
	ctx.r9.s64 = 1557921792;
	// lwz r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// ori r7,r9,64167
	ctx.r7.u64 = ctx.r9.u64 | 64167;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// mulld r10,r4,r7
	ctx.r10.s64 = ctx.r4.s64 * ctx.r7.s64;
	// lfs f13,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14348(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14348);
	f0.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r9,r11,9
	ctx.r9.u64 = r11.u32 & 0x7FFFFF;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// rldicl r8,r11,32,32
	ctx.r8.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fcmpu cr6,f9,f13
	cr6.compare(ctx.f9.f64, ctx.f13.f64);
	// ble cr6,0x8275f830
	if (!cr6.gt) goto loc_8275F830;
	// li r28,0
	r28.s64 = 0;
loc_8275F830:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8275f8b0
	if (cr6.eq) goto loc_8275F8B0;
	// lwz r31,40(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmpwi cr6,r31,-1
	cr6.compare<int32_t>(r31.s32, -1, xer);
	// bne cr6,0x8275f868
	if (!cr6.eq) goto loc_8275F868;
	// lwz r4,116(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 116);
	// lwz r11,3040(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3040);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// beq cr6,0x8275f868
	if (cr6.eq) goto loc_8275F868;
	// lwz r3,16(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// bl 0x824a5b00
	ctx.lr = 0x8275F860;
	sub_824A5B00(ctx, base);
	// bl 0x8275f2d8
	ctx.lr = 0x8275F864;
	sub_8275F2D8(ctx, base);
	// lwz r31,0(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_8275F868:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bge cr6,0x8275f874
	if (!cr6.lt) goto loc_8275F874;
	// li r31,0
	r31.s64 = 0;
loc_8275F874:
	// lwz r3,16(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// lwz r4,108(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 108);
	// bl 0x824a5b00
	ctx.lr = 0x8275F880;
	sub_824A5B00(ctx, base);
	// bl 0x8275f368
	ctx.lr = 0x8275F884;
	sub_8275F368(ctx, base);
	// lwz r29,0(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8248a510
	ctx.lr = 0x8275F890;
	sub_8248A510(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,212(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 212);
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lbz r5,12(r8)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + 12);
	// bl 0x8275f0a0
	ctx.lr = 0x8275F8B0;
	sub_8275F0A0(ctx, base);
loc_8275F8B0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8275F8BC"))) PPC_WEAK_FUNC(sub_8275F8BC);
PPC_FUNC_IMPL(__imp__sub_8275F8BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275F8C0"))) PPC_WEAK_FUNC(sub_8275F8C0);
PPC_FUNC_IMPL(__imp__sub_8275F8C0) {
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
	PPCRegister f31{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8275F8C8;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// li r26,0
	r26.s64 = 0;
	// lfs f13,32(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// lis r27,-32249
	r27.s64 = -2113470464;
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// li r31,1
	r31.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x8275f95c
	if (cr6.lt) goto loc_8275F95C;
	// lwz r4,100(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// lwz r11,3040(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 3040);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// beq cr6,0x8275f95c
	if (cr6.eq) goto loc_8275F95C;
	// lwz r10,104(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 104);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x8275f95c
	if (cr6.eq) goto loc_8275F95C;
	// lwz r3,16(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// bl 0x824a5b00
	ctx.lr = 0x8275F924;
	sub_824A5B00(ctx, base);
	// bl 0x82736a58
	ctx.lr = 0x8275F928;
	sub_82736A58(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,16(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// lwz r4,104(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 104);
	// lfs f31,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f31.f64 = double(temp.f32);
	// bl 0x824a5b00
	ctx.lr = 0x8275F93C;
	sub_824A5B00(ctx, base);
	// bl 0x82736a58
	ctx.lr = 0x8275F940;
	sub_82736A58(ctx, base);
	// lfs f0,32(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 32);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8275f958
	if (cr6.lt) goto loc_8275F958;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// blt cr6,0x8275f95c
	if (cr6.lt) goto loc_8275F95C;
loc_8275F958:
	// mr r31,r26
	r31.u64 = r26.u64;
loc_8275F95C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,36(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8275f9e4
	if (!cr6.lt) goto loc_8275F9E4;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f0,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x821ce460
	ctx.lr = 0x8275F990;
	sub_821CE460(ctx, base);
	// lis r9,23772
	ctx.r9.s64 = 1557921792;
	// lwz r4,96(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// ori r7,r9,64167
	ctx.r7.u64 = ctx.r9.u64 | 64167;
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// mulld r10,r4,r7
	ctx.r10.s64 = ctx.r4.s64 * ctx.r7.s64;
	// lfs f13,36(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14348(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14348);
	f0.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r9,r11,9
	ctx.r9.u64 = r11.u32 & 0x7FFFFF;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// rldicl r8,r11,32,32
	ctx.r8.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fcmpu cr6,f9,f13
	cr6.compare(ctx.f9.f64, ctx.f13.f64);
	// ble cr6,0x8275f9e4
	if (!cr6.gt) goto loc_8275F9E4;
	// mr r31,r26
	r31.u64 = r26.u64;
loc_8275F9E4:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8275fae0
	if (cr6.eq) goto loc_8275FAE0;
	// lwz r31,40(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// cmpwi cr6,r31,-1
	cr6.compare<int32_t>(r31.s32, -1, xer);
	// bne cr6,0x8275fa1c
	if (!cr6.eq) goto loc_8275FA1C;
	// lwz r4,116(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 116);
	// lwz r11,3040(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 3040);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// beq cr6,0x8275fa1c
	if (cr6.eq) goto loc_8275FA1C;
	// lwz r3,16(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// bl 0x824a5b00
	ctx.lr = 0x8275FA14;
	sub_824A5B00(ctx, base);
	// bl 0x8275f2d8
	ctx.lr = 0x8275FA18;
	sub_8275F2D8(ctx, base);
	// lwz r31,0(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_8275FA1C:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bge cr6,0x8275fa28
	if (!cr6.lt) goto loc_8275FA28;
	// mr r31,r26
	r31.u64 = r26.u64;
loc_8275FA28:
	// lwz r4,108(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 108);
	// lwz r3,16(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// bl 0x824a5b00
	ctx.lr = 0x8275FA34;
	sub_824A5B00(ctx, base);
	// bl 0x8275f368
	ctx.lr = 0x8275FA38;
	sub_8275F368(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,16(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// lwz r4,112(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 112);
	// lwz r27,0(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x824a5b00
	ctx.lr = 0x8275FA4C;
	sub_824A5B00(ctx, base);
	// bl 0x8275f368
	ctx.lr = 0x8275FA50;
	sub_8275F368(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r4,120(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 120);
	// lwz r3,16(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// lwz r30,0(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x824a5b00
	ctx.lr = 0x8275FA64;
	sub_824A5B00(ctx, base);
	// bl 0x82736b78
	ctx.lr = 0x8275FA68;
	sub_82736B78(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lbz r6,188(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 188);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfs f0,44(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 44);
	f0.f64 = double(temp.f32);
	// vupkd3d128 v61,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v61 = vTemp;
	// ori r11,r6,128
	r11.u64 = ctx.r6.u64 | 128;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,164(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stw r31,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r11,188(r1)
	PPC_STORE_U8(ctx.r1.u32 + 188, r11.u8);
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v60,v61,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x45));
	// lfs f0,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,160(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stw r30,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r30.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stvx128 v60,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r26,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r26.u32);
	// stw r26,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r26.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r26,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r26.u32);
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r8,244(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 244);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8275FAE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8275FAE0:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8275FAEC"))) PPC_WEAK_FUNC(sub_8275FAEC);
PPC_FUNC_IMPL(__imp__sub_8275FAEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8275FAF0"))) PPC_WEAK_FUNC(sub_8275FAF0);
PPC_FUNC_IMPL(__imp__sub_8275FAF0) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x8275FAF8;
	// stfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r22,r27,32
	r22.s64 = r27.s64 + 32;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82183870
	ctx.lr = 0x8275FB20;
	sub_82183870(ctx, base);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r4,100(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// bl 0x824a5b00
	ctx.lr = 0x8275FB2C;
	sub_824A5B00(ctx, base);
	// bl 0x8275f368
	ctx.lr = 0x8275FB30;
	sub_8275F368(ctx, base);
	// lwz r21,0(r3)
	r21.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x8275fd14
	if (cr6.eq) goto loc_8275FD14;
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8275FB50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x8275fd14
	if (cr6.eq) goto loc_8275FD14;
	// lwz r11,84(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 84);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// addi r30,r11,256
	r30.s64 = r11.s64 + 256;
	// bl 0x8248a510
	ctx.lr = 0x8275FB6C;
	sub_8248A510(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,156(r30)
	PPC_STORE_U32(r30.u32 + 156, ctx.r3.u32);
	// beq cr6,0x8275fd14
	if (cr6.eq) goto loc_8275FD14;
	// lwz r23,180(r3)
	r23.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// lhz r11,236(r23)
	r11.u64 = PPC_LOAD_U16(r23.u32 + 236);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8275fcc8
	if (!cr6.gt) goto loc_8275FCC8;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r24,r11
	r24.u64 = r11.u64;
	// lis r8,23772
	ctx.r8.s64 = 1557921792;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lfs f31,14348(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14348);
	f31.f64 = double(temp.f32);
	// li r25,0
	r25.s64 = 0;
	// ori r28,r8,64167
	r28.u64 = ctx.r8.u64 | 64167;
	// addi r26,r11,19888
	r26.s64 = r11.s64 + 19888;
	// addi r31,r10,2192
	r31.s64 = ctx.r10.s64 + 2192;
loc_8275FBB0:
	// lwz r11,232(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 232);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwzx r29,r25,r11
	r29.u64 = PPC_LOAD_U32(r25.u32 + r11.u32);
	// lwz r4,12(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// bl 0x823db730
	ctx.lr = 0x8275FBC4;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8275fcbc
	if (!cr6.eq) goto loc_8275FCBC;
	// stw r29,152(r30)
	PPC_STORE_U32(r30.u32 + 152, r29.u32);
	// lfs f0,100(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 100);
	f0.f64 = double(temp.f32);
	// stfs f0,160(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 160, temp.u32);
	// lbz r11,108(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 108);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8275fc4c
	if (cr6.eq) goto loc_8275FC4C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lfs f13,104(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,100(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// lfs f0,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f0.f64 = double(temp.f32);
	// blt cr6,0x8275fc08
	if (cr6.lt) goto loc_8275FC08;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8275fc08
	if (!cr6.lt) goto loc_8275FC08;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_8275FC08:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fsubs f0,f0,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 - ctx.f12.f64));
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mulld r10,r9,r28
	ctx.r10.s64 = ctx.r9.s64 * r28.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r7,r11,9
	ctx.r7.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// fmuls f9,f0,f10
	ctx.f9.f64 = double(float(f0.f64 * ctx.f10.f64));
	// fmadds f8,f9,f31,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * f31.f64 + ctx.f12.f64));
	// stfs f8,160(r30)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r30.u32 + 160, temp.u32);
loc_8275FC4C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lfs f13,100(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8275fc8c
	if (!cr6.lt) goto loc_8275FC8C;
	// stfs f0,160(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 160, temp.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lfs f1,100(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 100);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// lfs f2,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f2.f64 = double(temp.f32);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// stfd f2,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f2.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// bl 0x82130000
	ctx.lr = 0x8275FC8C;
	sub_82130000(ctx, base);
loc_8275FC8C:
	// lwz r11,156(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 156);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,160(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 160);
	ctx.f1.f64 = double(temp.f32);
	// lwz r29,276(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 276);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825031a8
	ctx.lr = 0x8275FCAC;
	sub_825031A8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825286e8
	ctx.lr = 0x8275FCBC;
	sub_825286E8(ctx, base);
loc_8275FCBC:
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// bne 0x8275fbb0
	if (!cr0.eq) goto loc_8275FBB0;
loc_8275FCC8:
	// lwz r11,152(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8275fd14
	if (!cr6.eq) goto loc_8275FD14;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8248a510
	ctx.lr = 0x8275FCDC;
	sub_8248A510(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275fd00
	if (cr6.eq) goto loc_8275FD00;
	// li r4,47
	ctx.r4.s64 = 47;
	// bl 0x823db6d0
	ctx.lr = 0x8275FCF4;
	sub_823DB6D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r5,r3,1
	ctx.r5.s64 = ctx.r3.s64 + 1;
	// bne cr6,0x8275fd04
	if (!cr6.eq) goto loc_8275FD04;
loc_8275FD00:
	// lwz r5,176(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 176);
loc_8275FD04:
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r11,19792
	ctx.r3.s64 = r11.s64 + 19792;
	// bl 0x82130000
	ctx.lr = 0x8275FD14;
	sub_82130000(ctx, base);
loc_8275FD14:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8275FD20"))) PPC_WEAK_FUNC(sub_8275FD20);
PPC_FUNC_IMPL(__imp__sub_8275FD20) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x8275FD28;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,16(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 16);
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// lwz r4,100(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x824a5b00
	ctx.lr = 0x8275FD40;
	sub_824A5B00(ctx, base);
	// bl 0x8275f368
	ctx.lr = 0x8275FD44;
	sub_8275F368(ctx, base);
	// lwz r28,0(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8275fed8
	if (cr6.eq) goto loc_8275FED8;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8275FD64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x8275fed8
	if (cr6.eq) goto loc_8275FED8;
	// lwz r11,84(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 84);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r31,r11,256
	r31.s64 = r11.s64 + 256;
	// bl 0x8248a510
	ctx.lr = 0x8275FD80;
	sub_8248A510(ctx, base);
	// lwz r11,156(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// beq cr6,0x8275fdf0
	if (cr6.eq) goto loc_8275FDF0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8248a510
	ctx.lr = 0x8275FD94;
	sub_8248A510(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// stw r30,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r30.u32);
	// addi r4,r25,32
	ctx.r4.s64 = r25.s64 + 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82183870
	ctx.lr = 0x8275FDAC;
	sub_82183870(ctx, base);
	// lwz r26,180(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 180);
	// lhz r11,236(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 236);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8275fdf0
	if (!cr6.gt) goto loc_8275FDF0;
	// li r29,0
	r29.s64 = 0;
	// mr r27,r11
	r27.u64 = r11.u64;
loc_8275FDC4:
	// lwz r11,232(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 232);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r30,r29,r11
	r30.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x823db730
	ctx.lr = 0x8275FDD8;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8275fde4
	if (!cr6.eq) goto loc_8275FDE4;
	// stw r30,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r30.u32);
loc_8275FDE4:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x8275fdc4
	if (!cr0.eq) goto loc_8275FDC4;
loc_8275FDF0:
	// lwz r10,152(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8275fed8
	if (cr6.eq) goto loc_8275FED8;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,96(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,160(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r11,29952
	r11.s64 = r11.s64 + 29952;
	// lfs f0,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmadds f12,f13,f0,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f12.f64));
	// stfs f12,160(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 160, temp.u32);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f13,104(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,100(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f13,f11
	cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// lfs f0,12(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	f0.f64 = double(temp.f32);
	// blt cr6,0x8275fe3c
	if (cr6.lt) goto loc_8275FE3C;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8275fe3c
	if (!cr6.lt) goto loc_8275FE3C;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_8275FE3C:
	// fcmpu cr6,f12,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x8275fe70
	if (!cr6.gt) goto loc_8275FE70;
	// lbz r9,108(r25)
	ctx.r9.u64 = PPC_LOAD_U8(r25.u32 + 108);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8275fe6c
	if (cr6.eq) goto loc_8275FE6C;
	// fsubs f13,f0,f11
	ctx.f13.f64 = double(float(f0.f64 - ctx.f11.f64));
	// lfs f0,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fsel f10,f11,f0,f13
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// fsubs f9,f12,f10
	ctx.f9.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// stfs f9,160(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 160, temp.u32);
	// b 0x8275fe70
	goto loc_8275FE70;
loc_8275FE6C:
	// stfs f0,160(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 160, temp.u32);
loc_8275FE70:
	// lwz r11,156(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// lfs f1,160(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 160);
	ctx.f1.f64 = double(temp.f32);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r31,276(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 276);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x825031a8
	ctx.lr = 0x8275FE90;
	sub_825031A8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825286e8
	ctx.lr = 0x8275FEA0;
	sub_825286E8(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x821b4de0
	ctx.lr = 0x8275FEA8;
	sub_821B4DE0(ctx, base);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r5,16(r24)
	ctx.r5.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r4,20(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 20);
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8275FEC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r7,188(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 188);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8275FED8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8275FED8:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8275FEE0"))) PPC_WEAK_FUNC(sub_8275FEE0);
PPC_FUNC_IMPL(__imp__sub_8275FEE0) {
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
	// addi r31,r11,-21128
	r31.s64 = r11.s64 + -21128;
	// lwz r11,-21128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -21128);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8276002c
	if (!cr6.eq) goto loc_8276002C;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8275FF10;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8275ff24
	if (cr6.eq) goto loc_8275FF24;
	// bl 0x821d5408
	ctx.lr = 0x8275FF20;
	sub_821D5408(ctx, base);
	// b 0x8275ff28
	goto loc_8275FF28;
loc_8275FF24:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8275FF28:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,20408
	ctx.r7.s64 = ctx.r10.s64 + 20408;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25672
	ctx.r9.s64 = r11.s64 + 25672;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,44
	ctx.r5.s64 = 44;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32138
	ctx.r8.s64 = -2106195968;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,-4224
	ctx.r4.s64 = ctx.r8.s64 + -4224;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r7,r3,-2580
	ctx.r7.s64 = ctx.r3.s64 + -2580;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lis r30,-32115
	r30.s64 = -2104688640;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r10,-2556
	ctx.r5.s64 = ctx.r10.s64 + -2556;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r3,r9,-2532
	ctx.r3.s64 = ctx.r9.s64 + -2532;
	// li r10,32
	ctx.r10.s64 = 32;
	// lwz r4,20376(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20376);
	// li r9,36
	ctx.r9.s64 = 36;
	// li r8,40
	ctx.r8.s64 = 40;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// bne cr6,0x8275ffc4
	if (!cr6.eq) goto loc_8275FFC4;
	// bl 0x824906d8
	ctx.lr = 0x8275FFC0;
	sub_824906D8(ctx, base);
	// lwz r4,20376(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20376);
loc_8275FFC4:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x8275FFD0;
	sub_821D4458(ctx, base);
	// lwz r11,20376(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20376);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x8275FFE8;
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
	ctx.lr = 0x82760004;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-2508
	ctx.r4.s64 = ctx.r8.s64 + -2508;
	// bl 0x821d4b00
	ctx.lr = 0x82760014;
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
	ctx.lr = 0x8276002C;
	sub_821C0548(ctx, base);
loc_8276002C:
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

__attribute__((alias("__imp__sub_82760044"))) PPC_WEAK_FUNC(sub_82760044);
PPC_FUNC_IMPL(__imp__sub_82760044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82760048"))) PPC_WEAK_FUNC(sub_82760048);
PPC_FUNC_IMPL(__imp__sub_82760048) {
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
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8276007c
	if (cr6.eq) goto loc_8276007C;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x821be8d8
	ctx.lr = 0x82760078;
	sub_821BE8D8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_8276007C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cf7b8
	ctx.lr = 0x82760088;
	sub_821CF7B8(ctx, base);
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

__attribute__((alias("__imp__sub_827600A0"))) PPC_WEAK_FUNC(sub_827600A0);
PPC_FUNC_IMPL(__imp__sub_827600A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r22{};
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
	ctx.lr = 0x827600A8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
loc_827600B8:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r11,32
	cr6.compare<int32_t>(r11.s32, 32, xer);
	// beq cr6,0x827600e4
	if (cr6.eq) goto loc_827600E4;
	// cmpwi cr6,r11,9
	cr6.compare<int32_t>(r11.s32, 9, xer);
	// beq cr6,0x827600e4
	if (cr6.eq) goto loc_827600E4;
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// beq cr6,0x827600ec
	if (cr6.eq) goto loc_827600EC;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// beq cr6,0x827600e4
	if (cr6.eq) goto loc_827600E4;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82760134
	if (!cr6.eq) goto loc_82760134;
loc_827600E4:
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// bne cr6,0x827600f8
	if (!cr6.eq) goto loc_827600F8;
loc_827600EC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
loc_827600F8:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82760124
	if (!cr6.lt) goto loc_82760124;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// b 0x827600b8
	goto loc_827600B8;
loc_82760124:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x8276012C;
	sub_821BE4F0(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// b 0x827600b8
	goto loc_827600B8;
loc_82760134:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r28,0
	r28.s64 = 0;
	// addi r10,r11,-34
	ctx.r10.s64 = r11.s64 + -34;
	// cmplwi cr6,r10,29
	cr6.compare<uint32_t>(ctx.r10.u32, 29, xer);
	// bgt cr6,0x8276069c
	if (cr6.gt) goto loc_8276069C;
	// lis r12,-32138
	r12.s64 = -2106195968;
	// addi r12,r12,352
	r12.s64 = r12.s64 + 352;
	// rlwinm r0,r10,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r10.u64) {
	case 0:
		goto loc_827601D8;
	case 1:
		goto loc_8276069C;
	case 2:
		goto loc_8276069C;
	case 3:
		goto loc_8276069C;
	case 4:
		goto loc_8276069C;
	case 5:
		goto loc_8276069C;
	case 6:
		goto loc_8276069C;
	case 7:
		goto loc_8276069C;
	case 8:
		goto loc_8276069C;
	case 9:
		goto loc_8276069C;
	case 10:
		goto loc_8276069C;
	case 11:
		goto loc_8276059C;
	case 12:
		goto loc_8276069C;
	case 13:
		goto loc_82760528;
	case 14:
		goto loc_8276069C;
	case 15:
		goto loc_8276069C;
	case 16:
		goto loc_8276069C;
	case 17:
		goto loc_8276069C;
	case 18:
		goto loc_8276069C;
	case 19:
		goto loc_8276069C;
	case 20:
		goto loc_8276069C;
	case 21:
		goto loc_8276069C;
	case 22:
		goto loc_8276069C;
	case 23:
		goto loc_8276069C;
	case 24:
		goto loc_8276069C;
	case 25:
		goto loc_8276069C;
	case 26:
		goto loc_827602D0;
	case 27:
		goto loc_8276066C;
	case 28:
		goto loc_8276066C;
	case 29:
		goto loc_82760528;
	default:
		__builtin_unreachable();
	}
	// lwz r19,472(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 472);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1436(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1436);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1320(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1320);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,1692(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1692);
	// lwz r19,720(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 720);
	// lwz r19,1644(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1644);
	// lwz r19,1644(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1644);
	// lwz r19,1320(r22)
	r19.u64 = PPC_LOAD_U32(r22.u32 + 1320);
loc_827601D8:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82760200
	if (!cr6.lt) goto loc_82760200;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x82760208
	goto loc_82760208;
loc_82760200:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x82760208;
	sub_821BE4F0(ctx, base);
loc_82760208:
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82760274
	if (cr6.eq) goto loc_82760274;
loc_82760214:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r11,34
	cr6.compare<int32_t>(r11.s32, 34, xer);
	// beq cr6,0x82760274
	if (cr6.eq) goto loc_82760274;
	// addi r10,r27,-1
	ctx.r10.s64 = r27.s64 + -1;
	// cmpw cr6,r28,r10
	cr6.compare<int32_t>(r28.s32, ctx.r10.s32, xer);
	// bge cr6,0x82760234
	if (!cr6.lt) goto loc_82760234;
	// stbx r11,r28,r26
	PPC_STORE_U8(r28.u32 + r26.u32, r11.u8);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
loc_82760234:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x8276025c
	if (!cr6.lt) goto loc_8276025C;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x82760264
	goto loc_82760264;
loc_8276025C:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x82760264;
	sub_821BE4F0(ctx, base);
loc_82760264:
	// rotlwi r11,r3,0
	r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82760214
	if (!cr6.eq) goto loc_82760214;
loc_82760274:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x827602b0
	if (!cr6.lt) goto loc_827602B0;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stbx r11,r28,r26
	PPC_STORE_U8(r28.u32 + r26.u32, r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_827602B0:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x827602B8;
	sub_821BE4F0(ctx, base);
loc_827602B8:
	// li r11,0
	r11.s64 = 0;
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stbx r11,r28,r26
	PPC_STORE_U8(r28.u32 + r26.u32, r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_827602D0:
	// stb r11,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r11.u8);
	// li r28,1
	r28.s64 = 1;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821bdcf8
	ctx.lr = 0x827602E0;
	sub_821BDCF8(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82760308
	if (!cr6.lt) goto loc_82760308;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x82760310
	goto loc_82760310;
loc_82760308:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x82760310;
	sub_821BE4F0(ctx, base);
loc_82760310:
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// cmpwi cr6,r3,33
	cr6.compare<int32_t>(ctx.r3.s32, 33, xer);
	// beq cr6,0x8276035c
	if (cr6.eq) goto loc_8276035C;
	// cmpwi cr6,r3,47
	cr6.compare<int32_t>(ctx.r3.s32, 47, xer);
	// beq cr6,0x8276032c
	if (cr6.eq) goto loc_8276032C;
	// cmpwi cr6,r3,63
	cr6.compare<int32_t>(ctx.r3.s32, 63, xer);
	// bne cr6,0x827607e8
	if (!cr6.eq) goto loc_827607E8;
loc_8276032C:
	// stb r3,1(r26)
	PPC_STORE_U8(r26.u32 + 1, ctx.r3.u8);
	// li r28,2
	r28.s64 = 2;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x827602b0
	if (!cr6.lt) goto loc_827602B0;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x827602b8
	goto loc_827602B8;
loc_8276035C:
	// stb r3,1(r26)
	PPC_STORE_U8(r26.u32 + 1, ctx.r3.u8);
	// li r28,2
	r28.s64 = 2;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821bdcf8
	ctx.lr = 0x8276036C;
	sub_821BDCF8(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82760398
	if (!cr6.lt) goto loc_82760398;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x827603a0
	goto loc_827603A0;
loc_82760398:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x827603A0;
	sub_821BE4F0(ctx, base);
loc_827603A0:
	// cmpwi cr6,r3,45
	cr6.compare<int32_t>(ctx.r3.s32, 45, xer);
	// bne cr6,0x827604f4
	if (!cr6.eq) goto loc_827604F4;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x827603d0
	if (!cr6.lt) goto loc_827603D0;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x827603d8
	goto loc_827603D8;
loc_827603D0:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x827603D8;
	sub_821BE4F0(ctx, base);
loc_827603D8:
	// cmpwi cr6,r3,45
	cr6.compare<int32_t>(ctx.r3.s32, 45, xer);
	// bne cr6,0x827604f4
	if (!cr6.eq) goto loc_827604F4;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82760408
	if (!cr6.lt) goto loc_82760408;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// lbzx r29,r10,r11
	r29.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x82760410
	goto loc_82760410;
loc_82760408:
	// bl 0x821be4f0
	ctx.lr = 0x8276040C;
	sub_821BE4F0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_82760410:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,28(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82760438
	if (!cr6.lt) goto loc_82760438;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// lbzx r30,r10,r11
	r30.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// stw r9,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r9.u32);
	// b 0x82760440
	goto loc_82760440;
loc_82760438:
	// bl 0x821be4f0
	ctx.lr = 0x8276043C;
	sub_821BE4F0(ctx, base);
loc_8276043C:
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_82760440:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82760468
	if (!cr6.lt) goto loc_82760468;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x82760470
	goto loc_82760470;
loc_82760468:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x82760470;
	sub_821BE4F0(ctx, base);
loc_82760470:
	// cmpwi cr6,r29,45
	cr6.compare<int32_t>(r29.s32, 45, xer);
	// bne cr6,0x82760488
	if (!cr6.eq) goto loc_82760488;
	// cmpwi cr6,r30,45
	cr6.compare<int32_t>(r30.s32, 45, xer);
	// bne cr6,0x82760488
	if (!cr6.eq) goto loc_82760488;
	// cmpwi cr6,r3,62
	cr6.compare<int32_t>(ctx.r3.s32, 62, xer);
	// beq cr6,0x82760490
	if (cr6.eq) goto loc_82760490;
loc_82760488:
	// mr r29,r30
	r29.u64 = r30.u64;
	// b 0x8276043c
	goto loc_8276043C;
loc_82760490:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x827604b8
	if (!cr6.lt) goto loc_827604B8;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x827604c0
	goto loc_827604C0;
loc_827604B8:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x827604C0;
	sub_821BE4F0(ctx, base);
loc_827604C0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827604E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stbx r11,r28,r26
	PPC_STORE_U8(r28.u32 + r26.u32, r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_827604F4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821be568
	ctx.lr = 0x82760500;
	sub_821BE568(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x827602b0
	if (!cr6.lt) goto loc_827602B0;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x827602b8
	goto loc_827602B8;
loc_82760528:
	// stb r11,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r11.u8);
	// li r28,1
	r28.s64 = 1;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82760558
	if (!cr6.lt) goto loc_82760558;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x82760560
	goto loc_82760560;
loc_82760558:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x82760560;
	sub_821BE4F0(ctx, base);
loc_82760560:
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// cmpwi cr6,r3,62
	cr6.compare<int32_t>(ctx.r3.s32, 62, xer);
	// bne cr6,0x827607e8
	if (!cr6.eq) goto loc_827607E8;
	// stb r3,1(r26)
	PPC_STORE_U8(r26.u32 + 1, ctx.r3.u8);
	// li r28,2
	r28.s64 = 2;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x827602b0
	if (!cr6.lt) goto loc_827602B0;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x827602b8
	goto loc_827602B8;
loc_8276059C:
	// stb r11,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r11.u8);
	// li r28,1
	r28.s64 = 1;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821bdcf8
	ctx.lr = 0x827605AC;
	sub_821BDCF8(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x827605d8
	if (!cr6.lt) goto loc_827605D8;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x827605e0
	goto loc_827605E0;
loc_827605D8:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x827605E0;
	sub_821BE4F0(ctx, base);
loc_827605E0:
	// cmpwi cr6,r3,45
	cr6.compare<int32_t>(ctx.r3.s32, 45, xer);
	// bne cr6,0x82760638
	if (!cr6.eq) goto loc_82760638;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82760610
	if (!cr6.lt) goto loc_82760610;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x82760618
	goto loc_82760618;
loc_82760610:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x82760618;
	sub_821BE4F0(ctx, base);
loc_82760618:
	// cmpwi cr6,r3,62
	cr6.compare<int32_t>(ctx.r3.s32, 62, xer);
	// bne cr6,0x82760638
	if (!cr6.eq) goto loc_82760638;
	// li r11,45
	r11.s64 = 45;
	// li r10,62
	ctx.r10.s64 = 62;
	// stb r11,1(r26)
	PPC_STORE_U8(r26.u32 + 1, r11.u8);
	// li r28,3
	r28.s64 = 3;
	// stb r10,2(r26)
	PPC_STORE_U8(r26.u32 + 2, ctx.r10.u8);
	// b 0x82760644
	goto loc_82760644;
loc_82760638:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821be568
	ctx.lr = 0x82760644;
	sub_821BE568(ctx, base);
loc_82760644:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x827602b0
	if (!cr6.lt) goto loc_827602B0;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x827602b8
	goto loc_827602B8;
loc_8276066C:
	// stb r11,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r11.u8);
	// li r28,1
	r28.s64 = 1;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x827602b0
	if (!cr6.lt) goto loc_827602B0;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x827602b8
	goto loc_827602B8;
loc_8276069C:
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x827607e8
	if (cr6.eq) goto loc_827607E8;
	// lis r30,-32130
	r30.s64 = -2105671680;
loc_827606A8:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r11,32
	cr6.compare<int32_t>(r11.s32, 32, xer);
	// beq cr6,0x827607e8
	if (cr6.eq) goto loc_827607E8;
	// cmpwi cr6,r11,9
	cr6.compare<int32_t>(r11.s32, 9, xer);
	// beq cr6,0x827607e8
	if (cr6.eq) goto loc_827607E8;
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// beq cr6,0x827607e8
	if (cr6.eq) goto loc_827607E8;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// beq cr6,0x827607e8
	if (cr6.eq) goto loc_827607E8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827607e8
	if (cr6.eq) goto loc_827607E8;
	// cmpwi cr6,r11,61
	cr6.compare<int32_t>(r11.s32, 61, xer);
	// beq cr6,0x827607e8
	if (cr6.eq) goto loc_827607E8;
	// cmpwi cr6,r11,47
	cr6.compare<int32_t>(r11.s32, 47, xer);
	// beq cr6,0x827607e8
	if (cr6.eq) goto loc_827607E8;
	// cmpwi cr6,r11,63
	cr6.compare<int32_t>(r11.s32, 63, xer);
	// beq cr6,0x827607e8
	if (cr6.eq) goto loc_827607E8;
	// cmpwi cr6,r11,62
	cr6.compare<int32_t>(r11.s32, 62, xer);
	// beq cr6,0x827607e8
	if (cr6.eq) goto loc_827607E8;
	// lwz r10,-31340(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -31340);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82760788
	if (!cr6.eq) goto loc_82760788;
loc_82760700:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cf9b8
	ctx.lr = 0x82760708;
	sub_821CF9B8(ctx, base);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bne cr6,0x82760788
	if (!cr6.eq) goto loc_82760788;
loc_82760710:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r11,32
	cr6.compare<int32_t>(r11.s32, 32, xer);
	// beq cr6,0x8276073c
	if (cr6.eq) goto loc_8276073C;
	// cmpwi cr6,r11,9
	cr6.compare<int32_t>(r11.s32, 9, xer);
	// beq cr6,0x8276073c
	if (cr6.eq) goto loc_8276073C;
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// beq cr6,0x8276073c
	if (cr6.eq) goto loc_8276073C;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// beq cr6,0x8276073c
	if (cr6.eq) goto loc_8276073C;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82760778
	if (!cr6.eq) goto loc_82760778;
loc_8276073C:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82760768
	if (!cr6.lt) goto loc_82760768;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// b 0x82760710
	goto loc_82760710;
loc_82760768:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x82760770;
	sub_821BE4F0(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// b 0x82760710
	goto loc_82760710;
loc_82760778:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,-31340(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -31340);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x82760700
	if (cr6.eq) goto loc_82760700;
loc_82760788:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x827607a8
	if (cr6.eq) goto loc_827607A8;
	// addi r10,r27,-1
	ctx.r10.s64 = r27.s64 + -1;
	// cmpw cr6,r28,r10
	cr6.compare<int32_t>(r28.s32, ctx.r10.s32, xer);
	// bge cr6,0x827607a8
	if (!cr6.lt) goto loc_827607A8;
	// stbx r11,r28,r26
	PPC_STORE_U8(r28.u32 + r26.u32, r11.u8);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
loc_827607A8:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x827607d0
	if (!cr6.lt) goto loc_827607D0;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// lbzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// stw r8,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r8.u32);
	// b 0x827607d8
	goto loc_827607D8;
loc_827607D0:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821be4f0
	ctx.lr = 0x827607D8;
	sub_821BE4F0(ctx, base);
loc_827607D8:
	// rotlwi r11,r3,0
	r11.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x827606a8
	if (!cr6.eq) goto loc_827606A8;
loc_827607E8:
	// li r11,0
	r11.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stbx r11,r28,r26
	PPC_STORE_U8(r28.u32 + r26.u32, r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_827607FC"))) PPC_WEAK_FUNC(sub_827607FC);
PPC_FUNC_IMPL(__imp__sub_827607FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82760800"))) PPC_WEAK_FUNC(sub_82760800);
PPC_FUNC_IMPL(__imp__sub_82760800) {
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
	ctx.lr = 0x82760808;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821bdcf8
	ctx.lr = 0x8276081C;
	sub_821BDCF8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r28,16(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stb r10,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82760848;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82760890
	if (cr6.eq) goto loc_82760890;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_82760858:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8276087c
	if (cr6.eq) goto loc_8276087C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82760858
	if (cr6.eq) goto loc_82760858;
loc_8276087C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82760890
	if (!cr6.eq) goto loc_82760890;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9248
	return;
loc_82760890:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821be568
	ctx.lr = 0x8276089C;
	sub_821BE568(ctx, base);
	// stw r28,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r28.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827608AC"))) PPC_WEAK_FUNC(sub_827608AC);
PPC_FUNC_IMPL(__imp__sub_827608AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827608B0"))) PPC_WEAK_FUNC(sub_827608B0);
PPC_FUNC_IMPL(__imp__sub_827608B0) {
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
	ctx.lr = 0x827608B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r4,r10,24092
	ctx.r4.s64 = ctx.r10.s64 + 24092;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x827608E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,48(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827608F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r6,r29,24
	ctx.r6.u64 = r29.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// beq cr6,0x82760928
	if (cr6.eq) goto loc_82760928;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r4,r10,24040
	ctx.r4.s64 = ctx.r10.s64 + 24040;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82760920;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82760928:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r4,r10,24096
	ctx.r4.s64 = ctx.r10.s64 + 24096;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82760938;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82760940"))) PPC_WEAK_FUNC(sub_82760940);
PPC_FUNC_IMPL(__imp__sub_82760940) {
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
	ctx.lr = 0x82760948;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821bdcf8
	ctx.lr = 0x8276095C;
	sub_821BDCF8(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r28,16(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r11,24092
	ctx.r4.s64 = r11.s64 + 24092;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82760800
	ctx.lr = 0x82760974;
	sub_82760800(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8276099c
	if (cr6.eq) goto loc_8276099C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82760800
	ctx.lr = 0x8276098C;
	sub_82760800(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827609a0
	if (!cr6.eq) goto loc_827609A0;
loc_8276099C:
	// li r30,0
	r30.s64 = 0;
loc_827609A0:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821be568
	ctx.lr = 0x827609AC;
	sub_821BE568(ctx, base);
	// stw r28,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r28.u32);
	// clrlwi r3,r30,24
	ctx.r3.u64 = r30.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827609BC"))) PPC_WEAK_FUNC(sub_827609BC);
PPC_FUNC_IMPL(__imp__sub_827609BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827609C0"))) PPC_WEAK_FUNC(sub_827609C0);
PPC_FUNC_IMPL(__imp__sub_827609C0) {
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
	ctx.lr = 0x827609C8;
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
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821bdcf8
	ctx.lr = 0x827609E0;
	sub_821BDCF8(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r27,16(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r11,24092
	ctx.r4.s64 = r11.s64 + 24092;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82760800
	ctx.lr = 0x827609F8;
	sub_82760800(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82760a28
	if (cr6.eq) goto loc_82760A28;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82760A20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x82760a2c
	goto loc_82760A2C;
loc_82760A28:
	// li r30,0
	r30.s64 = 0;
loc_82760A2C:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821be568
	ctx.lr = 0x82760A38;
	sub_821BE568(ctx, base);
	// stw r27,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r27.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82760A48"))) PPC_WEAK_FUNC(sub_82760A48);
PPC_FUNC_IMPL(__imp__sub_82760A48) {
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
	ctx.lr = 0x82760A50;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821bdcf8
	ctx.lr = 0x82760A6C;
	sub_821BDCF8(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r27,16(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r11,24092
	ctx.r4.s64 = r11.s64 + 24092;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82760800
	ctx.lr = 0x82760A84;
	sub_82760800(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82760afc
	if (cr6.eq) goto loc_82760AFC;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82760800
	ctx.lr = 0x82760A9C;
	sub_82760800(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82760afc
	if (cr6.eq) goto loc_82760AFC;
	// clrlwi r30,r29,24
	r30.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82760ad8
	if (!cr6.eq) goto loc_82760AD8;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,24096
	ctx.r4.s64 = r11.s64 + 24096;
	// bl 0x82760800
	ctx.lr = 0x82760AC4;
	sub_82760800(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82760af4
	if (!cr6.eq) goto loc_82760AF4;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82760afc
	if (cr6.eq) goto loc_82760AFC;
loc_82760AD8:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,24040
	ctx.r4.s64 = r11.s64 + 24040;
	// bl 0x82760800
	ctx.lr = 0x82760AE8;
	sub_82760800(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82760afc
	if (cr6.eq) goto loc_82760AFC;
loc_82760AF4:
	// li r11,1
	r11.s64 = 1;
	// b 0x82760b00
	goto loc_82760B00;
loc_82760AFC:
	// li r11,0
	r11.s64 = 0;
loc_82760B00:
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82760b18
	if (cr6.eq) goto loc_82760B18;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82760b28
	if (!cr6.eq) goto loc_82760B28;
loc_82760B18:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821be568
	ctx.lr = 0x82760B24;
	sub_821BE568(ctx, base);
	// stw r27,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r27.u32);
loc_82760B28:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82760B34"))) PPC_WEAK_FUNC(sub_82760B34);
PPC_FUNC_IMPL(__imp__sub_82760B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82760B38"))) PPC_WEAK_FUNC(sub_82760B38);
PPC_FUNC_IMPL(__imp__sub_82760B38) {
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
	ctx.lr = 0x82760B40;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821bdcf8
	ctx.lr = 0x82760B58;
	sub_821BDCF8(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r28,16(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r11,24108
	ctx.r4.s64 = r11.s64 + 24108;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82760800
	ctx.lr = 0x82760B70;
	sub_82760800(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82760bb4
	if (cr6.eq) goto loc_82760BB4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82760800
	ctx.lr = 0x82760B88;
	sub_82760800(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82760bb4
	if (cr6.eq) goto loc_82760BB4;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,24096
	ctx.r4.s64 = r11.s64 + 24096;
	// bl 0x82760800
	ctx.lr = 0x82760BA4;
	sub_82760800(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82760bb8
	if (!cr6.eq) goto loc_82760BB8;
loc_82760BB4:
	// li r11,0
	r11.s64 = 0;
loc_82760BB8:
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82760bd0
	if (cr6.eq) goto loc_82760BD0;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82760be0
	if (!cr6.eq) goto loc_82760BE0;
loc_82760BD0:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x821be568
	ctx.lr = 0x82760BDC;
	sub_821BE568(ctx, base);
	// stw r28,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r28.u32);
loc_82760BE0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82760BEC"))) PPC_WEAK_FUNC(sub_82760BEC);
PPC_FUNC_IMPL(__imp__sub_82760BEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82760BF0"))) PPC_WEAK_FUNC(sub_82760BF0);
PPC_FUNC_IMPL(__imp__sub_82760BF0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82760BF8;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// addi r4,r10,24092
	ctx.r4.s64 = ctx.r10.s64 + 24092;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82760C2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,48(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82760C44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r28,24
	ctx.r6.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82760c5c
	if (cr6.eq) goto loc_82760C5C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r27,r11,24040
	r27.s64 = r11.s64 + 24040;
	// b 0x82760c64
	goto loc_82760C64;
loc_82760C5C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r27,r11,24096
	r27.s64 = r11.s64 + 24096;
loc_82760C64:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82760800
	ctx.lr = 0x82760C70;
	sub_82760800(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82760d4c
	if (!cr6.eq) goto loc_82760D4C;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r28,r11,-7532
	r28.s64 = r11.s64 + -7532;
loc_82760C84:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82760CA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r30,0
	r30.s64 = 0;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82760cfc
	if (cr6.eq) goto loc_82760CFC;
loc_82760CB4:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
loc_82760CB8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82760cdc
	if (cr6.eq) goto loc_82760CDC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82760cb8
	if (cr6.eq) goto loc_82760CB8;
loc_82760CDC:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82760cfc
	if (cr6.eq) goto loc_82760CFC;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r29
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82760cb4
	if (!cr6.eq) goto loc_82760CB4;
loc_82760CFC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82760D14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwzx r4,r9,r25
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + r25.u32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82760D34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82760800
	ctx.lr = 0x82760D40;
	sub_82760800(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82760c84
	if (cr6.eq) goto loc_82760C84;
loc_82760D4C:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82760D54"))) PPC_WEAK_FUNC(sub_82760D54);
PPC_FUNC_IMPL(__imp__sub_82760D54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82760D58"))) PPC_WEAK_FUNC(sub_82760D58);
PPC_FUNC_IMPL(__imp__sub_82760D58) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32243
	r11.s64 = -2113077248;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,19996
	ctx.r4.s64 = r11.s64 + 19996;
	// bl 0x82760800
	ctx.lr = 0x82760D7C;
	sub_82760800(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82760e68
	if (cr6.eq) goto loc_82760E68;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,5276
	ctx.r4.s64 = ctx.r10.s64 + 5276;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82760DA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,-17952
	ctx.r4.s64 = ctx.r8.s64 + -17952;
	// lwz r6,48(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82760DC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r5,-7532
	r30.s64 = ctx.r5.s64 + -7532;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82760DE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,23416
	ctx.r4.s64 = ctx.r9.s64 + 23416;
	// lwz r7,48(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82760DFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r6,-32243
	ctx.r6.s64 = -2113077248;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,19984
	ctx.r4.s64 = ctx.r6.s64 + 19984;
	// lwz r11,48(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 48);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82760E18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82760E30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,40
	ctx.r5.s64 = 40;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82760E4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,24088
	ctx.r4.s64 = ctx.r6.s64 + 24088;
	// lwz r11,48(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 48);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82760E68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82760E68:
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

__attribute__((alias("__imp__sub_82760E80"))) PPC_WEAK_FUNC(sub_82760E80);
PPC_FUNC_IMPL(__imp__sub_82760E80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r4,r3,80
	ctx.r4.s64 = ctx.r3.s64 + 80;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x8276c448
	sub_8276C448(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82760E94"))) PPC_WEAK_FUNC(sub_82760E94);
PPC_FUNC_IMPL(__imp__sub_82760E94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82760E98"))) PPC_WEAK_FUNC(sub_82760E98);
PPC_FUNC_IMPL(__imp__sub_82760E98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r4,r3,80
	ctx.r4.s64 = ctx.r3.s64 + 80;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x8276c3e8
	sub_8276C3E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82760EAC"))) PPC_WEAK_FUNC(sub_82760EAC);
PPC_FUNC_IMPL(__imp__sub_82760EAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82760EB0"))) PPC_WEAK_FUNC(sub_82760EB0);
PPC_FUNC_IMPL(__imp__sub_82760EB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lwz r11,-21116(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21116);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r11,-21116(r9)
	PPC_STORE_U32(ctx.r9.u32 + -21116, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82760ED0"))) PPC_WEAK_FUNC(sub_82760ED0);
PPC_FUNC_IMPL(__imp__sub_82760ED0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r3,-21116(r10)
	PPC_STORE_U32(ctx.r10.u32 + -21116, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82760EE8"))) PPC_WEAK_FUNC(sub_82760EE8);
PPC_FUNC_IMPL(__imp__sub_82760EE8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,152
	ctx.r3.s64 = ctx.r3.s64 + 152;
	// b 0x8276bf08
	sub_8276BF08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82760EF0"))) PPC_WEAK_FUNC(sub_82760EF0);
PPC_FUNC_IMPL(__imp__sub_82760EF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stw r30,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r30.u32);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r9.u32);
	// lfs f0,-31400(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31400);
	f0.f64 = double(temp.f32);
	// stw r5,196(r31)
	PPC_STORE_U32(r31.u32 + 196, ctx.r5.u32);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r8.u32);
	// stfs f0,144(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 144, temp.u32);
	// stfs f1,148(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// bne cr6,0x82760f4c
	if (!cr6.eq) goto loc_82760F4C;
	// lis r11,-32127
	r11.s64 = -2105475072;
	// addi r7,r11,3780
	ctx.r7.s64 = r11.s64 + 3780;
loc_82760F4C:
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// addi r3,r31,44
	ctx.r3.s64 = r31.s64 + 44;
	// bl 0x8254ad08
	ctx.lr = 0x82760F58;
	sub_8254AD08(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82760F6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82760f9c
	if (cr6.eq) goto loc_82760F9C;
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82761940
	ctx.lr = 0x82760F84;
	sub_82761940(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r10,112
	ctx.r10.s64 = 112;
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r9,136(r31)
	PPC_STORE_U8(r31.u32 + 136, ctx.r9.u8);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82760F9C:
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

__attribute__((alias("__imp__sub_82760FB4"))) PPC_WEAK_FUNC(sub_82760FB4);
PPC_FUNC_IMPL(__imp__sub_82760FB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82760FB8"))) PPC_WEAK_FUNC(sub_82760FB8);
PPC_FUNC_IMPL(__imp__sub_82760FB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stb r8,208(r3)
	PPC_STORE_U8(ctx.r3.u32 + 208, ctx.r8.u8);
	// stb r11,209(r3)
	PPC_STORE_U8(ctx.r3.u32 + 209, r11.u8);
	// b 0x82760ef0
	sub_82760EF0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82760FC8"))) PPC_WEAK_FUNC(sub_82760FC8);
PPC_FUNC_IMPL(__imp__sub_82760FC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,208(r3)
	PPC_STORE_U32(ctx.r3.u32 + 208, ctx.r4.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// stw r7,212(r3)
	PPC_STORE_U32(ctx.r3.u32 + 212, ctx.r7.u32);
	// beq cr6,0x82761000
	if (cr6.eq) goto loc_82761000;
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
loc_82761000:
	// li r6,192
	ctx.r6.s64 = 192;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lis r4,23772
	ctx.r4.s64 = 1557921792;
	// addi r5,r7,2192
	ctx.r5.s64 = ctx.r7.s64 + 2192;
	// ori r11,r4,64167
	r11.u64 = ctx.r4.u64 | 64167;
	// stvx128 v63,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r31,2192(r7)
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2192);
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lwz r10,4(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// mulld r10,r31,r6
	ctx.r10.s64 = r31.s64 * ctx.r6.s64;
	// lfs f0,-31400(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31400);
	f0.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// mulld r10,r10,r4
	ctx.r10.s64 = ctx.r10.s64 * ctx.r4.s64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// clrlwi r9,r11,1
	ctx.r9.u64 = r11.u32 & 0x7FFFFFFF;
	// clrldi r6,r10,33
	ctx.r6.u64 = ctx.r10.u64 & 0x7FFFFFFF;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// rldicl r10,r10,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// rldimi r6,r9,32,0
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r6.u64 & 0xFFFFFFFF);
	// stw r11,2192(r7)
	PPC_STORE_U32(ctx.r7.u32 + 2192, r11.u32);
	// stw r10,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r10.u32);
	// stfs f0,144(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 144, temp.u32);
	// stfs f1,148(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 148, temp.u32);
	// std r6,216(r3)
	PPC_STORE_U64(ctx.r3.u32 + 216, ctx.r6.u64);
	// bne cr6,0x82761088
	if (!cr6.eq) goto loc_82761088;
	// lis r11,-32127
	r11.s64 = -2105475072;
	// addi r8,r11,3780
	ctx.r8.s64 = r11.s64 + 3780;
loc_82761088:
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// addi r3,r3,44
	ctx.r3.s64 = ctx.r3.s64 + 44;
	// bl 0x8254ad08
	ctx.lr = 0x82761094;
	sub_8254AD08(ctx, base);
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

__attribute__((alias("__imp__sub_827610A8"))) PPC_WEAK_FUNC(sub_827610A8);
PPC_FUNC_IMPL(__imp__sub_827610A8) {
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
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,20044
	ctx.r10.s64 = r11.s64 + 20044;
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// stb r4,26(r31)
	PPC_STORE_U8(r31.u32 + 26, ctx.r4.u8);
	// stb r8,24(r31)
	PPC_STORE_U8(r31.u32 + 24, ctx.r8.u8);
	// stb r30,25(r31)
	PPC_STORE_U8(r31.u32 + 25, r30.u8);
	// bl 0x8254e2e0
	ctx.lr = 0x827610F8;
	sub_8254E2E0(ctx, base);
	// stw r30,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r30.u32);
	// stw r30,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r30.u32);
	// stb r30,88(r31)
	PPC_STORE_U8(r31.u32 + 88, r30.u8);
	// stw r30,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r30.u32);
loc_82761108:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82761108
	if (cr6.eq) goto loc_82761108;
	// std r11,96(r31)
	PPC_STORE_U64(r31.u32 + 96, r11.u64);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r31,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r31.u32);
	// stw r31,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r31.u32);
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

__attribute__((alias("__imp__sub_82761140"))) PPC_WEAK_FUNC(sub_82761140);
PPC_FUNC_IMPL(__imp__sub_82761140) {
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
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// addi r10,r11,20044
	ctx.r10.s64 = r11.s64 + 20044;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8254e338
	ctx.lr = 0x82761170;
	sub_8254E338(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// clrlwi r8,r30,31
	ctx.r8.u64 = r30.u32 & 0x1;
	// addi r7,r9,-30128
	ctx.r7.s64 = ctx.r9.s64 + -30128;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x82761194
	if (cr6.eq) goto loc_82761194;
	// bl 0x82130588
	ctx.lr = 0x82761190;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82761194:
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

__attribute__((alias("__imp__sub_827611AC"))) PPC_WEAK_FUNC(sub_827611AC);
PPC_FUNC_IMPL(__imp__sub_827611AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827611B0"))) PPC_WEAK_FUNC(sub_827611B0);
PPC_FUNC_IMPL(__imp__sub_827611B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827611f8
	if (cr6.eq) goto loc_827611F8;
	// addi r9,r10,8
	ctx.r9.s64 = ctx.r10.s64 + 8;
loc_827611CC:
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r8,4(r7)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// addi r6,r8,-1
	ctx.r6.s64 = ctx.r8.s64 + -1;
	// stw r6,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r6.u32);
	// lwz r5,8(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// bne cr6,0x827611cc
	if (!cr6.eq) goto loc_827611CC;
loc_827611F8:
	// li r10,0
	ctx.r10.s64 = 0;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82761224"))) PPC_WEAK_FUNC(sub_82761224);
PPC_FUNC_IMPL(__imp__sub_82761224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82761228"))) PPC_WEAK_FUNC(sub_82761228);
PPC_FUNC_IMPL(__imp__sub_82761228) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r31,152
	ctx.r3.s64 = r31.s64 + 152;
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,148(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// bl 0x8276bf08
	ctx.lr = 0x82761254;
	sub_8276BF08(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// stb r30,136(r31)
	PPC_STORE_U8(r31.u32 + 136, r30.u8);
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// bl 0x827611b0
	ctx.lr = 0x82761268;
	sub_827611B0(ctx, base);
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82761284
	if (cr6.eq) goto loc_82761284;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r30,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r30.u32);
loc_82761284:
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

__attribute__((alias("__imp__sub_8276129C"))) PPC_WEAK_FUNC(sub_8276129C);
PPC_FUNC_IMPL(__imp__sub_8276129C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827612A0"))) PPC_WEAK_FUNC(sub_827612A0);
PPC_FUNC_IMPL(__imp__sub_827612A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r9,196(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// lwz r7,192(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// stw r10,196(r3)
	PPC_STORE_U32(ctx.r3.u32 + 196, ctx.r10.u32);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// stw r6,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r6.u32);
	// stw r10,192(r3)
	PPC_STORE_U32(ctx.r3.u32 + 192, ctx.r10.u32);
	// b 0x82761228
	sub_82761228(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827612D0"))) PPC_WEAK_FUNC(sub_827612D0);
PPC_FUNC_IMPL(__imp__sub_827612D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r9,196(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// li r11,0
	r11.s64 = 0;
	// stb r11,208(r3)
	PPC_STORE_U8(ctx.r3.u32 + 208, r11.u8);
	// stb r11,209(r3)
	PPC_STORE_U8(ctx.r3.u32 + 209, r11.u8);
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// lwz r7,192(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// stw r11,196(r3)
	PPC_STORE_U32(ctx.r3.u32 + 196, r11.u32);
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// stw r6,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r6.u32);
	// stw r11,192(r3)
	PPC_STORE_U32(ctx.r3.u32 + 192, r11.u32);
	// b 0x82761228
	sub_82761228(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82761308"))) PPC_WEAK_FUNC(sub_82761308);
PPC_FUNC_IMPL(__imp__sub_82761308) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,212(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 212);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82761328
	if (cr6.eq) goto loc_82761328;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r9,212(r3)
	PPC_STORE_U32(ctx.r3.u32 + 212, ctx.r9.u32);
loc_82761328:
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// stw r9,208(r3)
	PPC_STORE_U32(ctx.r3.u32 + 208, ctx.r9.u32);
	// b 0x82761228
	sub_82761228(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82761340"))) PPC_WEAK_FUNC(sub_82761340);
PPC_FUNC_IMPL(__imp__sub_82761340) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r10,148(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 148);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82761364
	if (cr6.eq) goto loc_82761364;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// stw r8,148(r11)
	PPC_STORE_U32(r11.u32 + 148, ctx.r8.u32);
loc_82761364:
	// lbz r9,144(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 144);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stb r8,136(r11)
	PPC_STORE_U8(r11.u32 + 136, ctx.r8.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// addi r3,r11,128
	ctx.r3.s64 = r11.s64 + 128;
	// rlwinm r8,r8,0,27,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFF9F;
	// lfs f0,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,152(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 152, temp.u32);
	// stb r8,144(r11)
	PPC_STORE_U8(r11.u32 + 144, ctx.r8.u8);
	// b 0x827611b0
	sub_827611B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82761390"))) PPC_WEAK_FUNC(sub_82761390);
PPC_FUNC_IMPL(__imp__sub_82761390) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,192(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827613A4"))) PPC_WEAK_FUNC(sub_827613A4);
PPC_FUNC_IMPL(__imp__sub_827613A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827613A8"))) PPC_WEAK_FUNC(sub_827613A8);
PPC_FUNC_IMPL(__imp__sub_827613A8) {
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
	// addi r3,r31,152
	ctx.r3.s64 = r31.s64 + 152;
	// addi r10,r11,20084
	ctx.r10.s64 = r11.s64 + 20084;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8276bf70
	ctx.lr = 0x827613D0;
	sub_8276BF70(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// bl 0x827611b0
	ctx.lr = 0x827613DC;
	sub_827611B0(ctx, base);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// addi r8,r9,20044
	ctx.r8.s64 = ctx.r9.s64 + 20044;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bl 0x8254e338
	ctx.lr = 0x827613F0;
	sub_8254E338(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// addi r6,r7,-30128
	ctx.r6.s64 = ctx.r7.s64 + -30128;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_82761410"))) PPC_WEAK_FUNC(sub_82761410);
PPC_FUNC_IMPL(__imp__sub_82761410) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82761424"))) PPC_WEAK_FUNC(sub_82761424);
PPC_FUNC_IMPL(__imp__sub_82761424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82761428"))) PPC_WEAK_FUNC(sub_82761428);
PPC_FUNC_IMPL(__imp__sub_82761428) {
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
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r10,r11,20104
	ctx.r10.s64 = r11.s64 + 20104;
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x827611b0
	ctx.lr = 0x82761454;
	sub_827611B0(ctx, base);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// addi r8,r9,20044
	ctx.r8.s64 = ctx.r9.s64 + 20044;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bl 0x8254e338
	ctx.lr = 0x82761468;
	sub_8254E338(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// addi r6,r7,-30128
	ctx.r6.s64 = ctx.r7.s64 + -30128;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_82761488"))) PPC_WEAK_FUNC(sub_82761488);
PPC_FUNC_IMPL(__imp__sub_82761488) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,144(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 144);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82761494"))) PPC_WEAK_FUNC(sub_82761494);
PPC_FUNC_IMPL(__imp__sub_82761494) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82761498"))) PPC_WEAK_FUNC(sub_82761498);
PPC_FUNC_IMPL(__imp__sub_82761498) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// bl 0x827610a8
	ctx.lr = 0x827614B8;
	sub_827610A8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r30,0
	r30.s64 = 0;
	// addi r9,r10,20124
	ctx.r9.s64 = ctx.r10.s64 + 20124;
	// stw r30,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r30.u32);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f31,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f31.f64 = double(temp.f32);
	// stw r30,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r30.u32);
	// stfs f31,144(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 144, temp.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stb r30,136(r31)
	PPC_STORE_U8(r31.u32 + 136, r30.u8);
	// addi r3,r31,152
	ctx.r3.s64 = r31.s64 + 152;
	// lwz r4,-21116(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + -21116);
	// bl 0x8276b8a0
	ctx.lr = 0x827614F0;
	sub_8276B8A0(ctx, base);
	// stfs f31,148(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// stw r30,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_82761518"))) PPC_WEAK_FUNC(sub_82761518);
PPC_FUNC_IMPL(__imp__sub_82761518) {
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
	// addi r3,r31,152
	ctx.r3.s64 = r31.s64 + 152;
	// bl 0x8276bf70
	ctx.lr = 0x8276153C;
	sub_8276BF70(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// bl 0x827611b0
	ctx.lr = 0x82761548;
	sub_827611B0(ctx, base);
	// lis r11,-32243
	r11.s64 = -2113077248;
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// addi r10,r11,20044
	ctx.r10.s64 = r11.s64 + 20044;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8254e338
	ctx.lr = 0x8276155C;
	sub_8254E338(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// clrlwi r8,r30,31
	ctx.r8.u64 = r30.u32 & 0x1;
	// addi r7,r9,-30128
	ctx.r7.s64 = ctx.r9.s64 + -30128;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x82761580
	if (cr6.eq) goto loc_82761580;
	// bl 0x82130588
	ctx.lr = 0x8276157C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82761580:
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

__attribute__((alias("__imp__sub_82761598"))) PPC_WEAK_FUNC(sub_82761598);
PPC_FUNC_IMPL(__imp__sub_82761598) {
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
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82761498
	ctx.lr = 0x827615B4;
	sub_82761498(ctx, base);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,20084
	ctx.r9.s64 = ctx.r10.s64 + 20084;
	// stw r11,208(r31)
	PPC_STORE_U32(r31.u32 + 208, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r11.u32);
	// std r11,216(r31)
	PPC_STORE_U64(r31.u32 + 216, r11.u64);
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

__attribute__((alias("__imp__sub_827615E8"))) PPC_WEAK_FUNC(sub_827615E8);
PPC_FUNC_IMPL(__imp__sub_827615E8) {
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
	// addi r3,r31,152
	ctx.r3.s64 = r31.s64 + 152;
	// addi r10,r11,20084
	ctx.r10.s64 = r11.s64 + 20084;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8276bf70
	ctx.lr = 0x82761618;
	sub_8276BF70(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// bl 0x827611b0
	ctx.lr = 0x82761624;
	sub_827611B0(ctx, base);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// addi r8,r9,20044
	ctx.r8.s64 = ctx.r9.s64 + 20044;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bl 0x8254e338
	ctx.lr = 0x82761638;
	sub_8254E338(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// clrlwi r6,r30,31
	ctx.r6.u64 = r30.u32 & 0x1;
	// addi r5,r7,-30128
	ctx.r5.s64 = ctx.r7.s64 + -30128;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x8276165c
	if (cr6.eq) goto loc_8276165C;
	// bl 0x82130588
	ctx.lr = 0x82761658;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8276165C:
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

__attribute__((alias("__imp__sub_82761674"))) PPC_WEAK_FUNC(sub_82761674);
PPC_FUNC_IMPL(__imp__sub_82761674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82761678"))) PPC_WEAK_FUNC(sub_82761678);
PPC_FUNC_IMPL(__imp__sub_82761678) {
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
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x827610a8
	ctx.lr = 0x82761694;
	sub_827610A8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r7,144(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 144);
	// clrlwi r6,r7,25
	ctx.r6.u64 = ctx.r7.u32 & 0x7F;
	// addi r8,r9,20104
	ctx.r8.s64 = ctx.r9.s64 + 20104;
	// lfs f0,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f0.f64 = double(temp.f32);
	// rlwinm r6,r6,0,27,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stfs f0,152(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
	// stb r11,136(r31)
	PPC_STORE_U8(r31.u32 + 136, r11.u8);
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stb r6,144(r31)
	PPC_STORE_U8(r31.u32 + 144, ctx.r6.u8);
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

__attribute__((alias("__imp__sub_827616E8"))) PPC_WEAK_FUNC(sub_827616E8);
PPC_FUNC_IMPL(__imp__sub_827616E8) {
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
	// addi r10,r11,20104
	ctx.r10.s64 = r11.s64 + 20104;
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// bl 0x827611b0
	ctx.lr = 0x8276171C;
	sub_827611B0(ctx, base);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// addi r8,r9,20044
	ctx.r8.s64 = ctx.r9.s64 + 20044;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bl 0x8254e338
	ctx.lr = 0x82761730;
	sub_8254E338(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// clrlwi r6,r30,31
	ctx.r6.u64 = r30.u32 & 0x1;
	// addi r5,r7,-30128
	ctx.r5.s64 = ctx.r7.s64 + -30128;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x82761754
	if (cr6.eq) goto loc_82761754;
	// bl 0x82130588
	ctx.lr = 0x82761750;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82761754:
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

__attribute__((alias("__imp__sub_8276176C"))) PPC_WEAK_FUNC(sub_8276176C);
PPC_FUNC_IMPL(__imp__sub_8276176C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82761770"))) PPC_WEAK_FUNC(sub_82761770);
PPC_FUNC_IMPL(__imp__sub_82761770) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82761498
	ctx.lr = 0x8276178C;
	sub_82761498(ctx, base);
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,20144
	ctx.r9.s64 = ctx.r10.s64 + 20144;
	// stw r11,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
	// stb r11,208(r31)
	PPC_STORE_U8(r31.u32 + 208, r11.u8);
	// stb r11,209(r31)
	PPC_STORE_U8(r31.u32 + 209, r11.u8);
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

__attribute__((alias("__imp__sub_827617C4"))) PPC_WEAK_FUNC(sub_827617C4);
PPC_FUNC_IMPL(__imp__sub_827617C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827617C8"))) PPC_WEAK_FUNC(sub_827617C8);
PPC_FUNC_IMPL(__imp__sub_827617C8) {
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
	// addi r3,r31,152
	ctx.r3.s64 = r31.s64 + 152;
	// addi r10,r11,20064
	ctx.r10.s64 = r11.s64 + 20064;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8276bf70
	ctx.lr = 0x827617F8;
	sub_8276BF70(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// bl 0x827611b0
	ctx.lr = 0x82761804;
	sub_827611B0(ctx, base);
	// lis r9,-32243
	ctx.r9.s64 = -2113077248;
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// addi r8,r9,20044
	ctx.r8.s64 = ctx.r9.s64 + 20044;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bl 0x8254e338
	ctx.lr = 0x82761818;
	sub_8254E338(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// clrlwi r6,r30,31
	ctx.r6.u64 = r30.u32 & 0x1;
	// addi r5,r7,-30128
	ctx.r5.s64 = ctx.r7.s64 + -30128;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x8276183c
	if (cr6.eq) goto loc_8276183C;
	// bl 0x82130588
	ctx.lr = 0x82761838;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8276183C:
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

__attribute__((alias("__imp__sub_82761854"))) PPC_WEAK_FUNC(sub_82761854);
PPC_FUNC_IMPL(__imp__sub_82761854) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82761858"))) PPC_WEAK_FUNC(sub_82761858);
PPC_FUNC_IMPL(__imp__sub_82761858) {
	PPC_FUNC_PROLOGUE();
	PPCVRegister v62{};
	PPCVRegister v63{};
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_setzero_si128());
	// stvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82761868"))) PPC_WEAK_FUNC(sub_82761868);
PPC_FUNC_IMPL(__imp__sub_82761868) {
	PPC_FUNC_PROLOGUE();
	PPCVRegister v63{};
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r5,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82761878"))) PPC_WEAK_FUNC(sub_82761878);
PPC_FUNC_IMPL(__imp__sub_82761878) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-1768(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -1768);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82761890"))) PPC_WEAK_FUNC(sub_82761890);
PPC_FUNC_IMPL(__imp__sub_82761890) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
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
	// stw r5,36(r1)
	PPC_STORE_U32(ctx.r1.u32 + 36, ctx.r5.u32);
	// lhz r11,36(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 36);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x827618b8
	if (!cr6.eq) goto loc_827618B8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-1768(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -1768);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// blr 
	return;
loc_827618B8:
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lhz r7,38(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 38);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,-21104(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21104);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lhz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmplw cr6,r6,r7
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, xer);
	// bne cr6,0x8276192c
	if (!cr6.eq) goto loc_8276192C;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8276192c
	if (cr6.eq) goto loc_8276192C;
	// li r10,48
	ctx.r10.s64 = 48;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,16
	ctx.r9.s64 = 16;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,32
	ctx.r8.s64 = 32;
	// lvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v59,v62,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v60.f32)));
	// lvx128 v58,r11,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r11,r8
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v56,v58,v59
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// vmsum3fp128 v55,v57,v59
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// vmsum3fp128 v54,v61,v59
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// vmrghw128 v53,v56,v56
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v52,v54,v55
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrghw128 v51,v52,v53
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// stvx128 v51,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r5,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r5.u32);
	// blr 
	return;
loc_8276192C:
	// lvx128 v50,r0,r3
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v49,v50,v50
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_setzero_si128());
	// stvx128 v49,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8276193C"))) PPC_WEAK_FUNC(sub_8276193C);
PPC_FUNC_IMPL(__imp__sub_8276193C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82761940"))) PPC_WEAK_FUNC(sub_82761940);
PPC_FUNC_IMPL(__imp__sub_82761940) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
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
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r11,-16(r1)
	PPC_STORE_U32(ctx.r1.u32 + -16, r11.u32);
	// lhz r11,-16(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + -16);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82761960
	if (!cr6.eq) goto loc_82761960;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
loc_82761960:
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lhz r7,-14(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + -14);
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,-21104(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21104);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lhz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmplw cr6,r6,r7
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, xer);
	// bne cr6,0x82761a08
	if (!cr6.eq) goto loc_82761A08;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82761a08
	if (cr6.eq) goto loc_82761A08;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,32
	ctx.r9.s64 = 32;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,48
	ctx.r8.s64 = 48;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r10,2384
	ctx.r6.s64 = ctx.r10.s64 + 2384;
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// lvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r5,2352
	ctx.r4.s64 = ctx.r5.s64 + 2352;
	// lvx128 v59,r11,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r11,r7
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v62,v60
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v56,v58,v59
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vand128 v55,v61,v63
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrglw128 v54,v62,v60
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrglw128 v53,v58,v59
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v52,v57,v56
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vor128 v51,v63,v55
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v55.u8)));
	// vmrghw128 v50,v57,v56
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v49,v54,v53
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmsum4fp128 v48,v51,v52
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v52.f32), 0xFF));
	// vmsum4fp128 v47,v51,v49
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v49.f32), 0xFF));
	// vmsum4fp128 v46,v51,v50
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// vmrghw128 v45,v48,v51
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v44,v46,v47
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v43,v44,v45
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// stvx128 v43,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
loc_82761A08:
	// vspltisw128 v42,0
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_set1_epi32(int(0x0)));
	// stvx128 v42,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82761A14"))) PPC_WEAK_FUNC(sub_82761A14);
PPC_FUNC_IMPL(__imp__sub_82761A14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82761A18"))) PPC_WEAK_FUNC(sub_82761A18);
PPC_FUNC_IMPL(__imp__sub_82761A18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r4,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r4.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82761940
	ctx.lr = 0x82761A40;
	sub_82761940(ctx, base);
	// lvx128 v1,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82761A54"))) PPC_WEAK_FUNC(sub_82761A54);
PPC_FUNC_IMPL(__imp__sub_82761A54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82761A58"))) PPC_WEAK_FUNC(sub_82761A58);
PPC_FUNC_IMPL(__imp__sub_82761A58) {
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
	// rlwinm r11,r4,0,30,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x2;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82761ac8
	if (cr6.eq) goto loc_82761AC8;
	// lwz r11,-16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -16);
	// addi r30,r31,-16
	r30.s64 = r31.s64 + -16;
	// rlwinm r10,r11,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// blt 0x82761aac
	if (cr0.lt) goto loc_82761AAC;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r9,r9,-30128
	ctx.r9.s64 = ctx.r9.s64 + -30128;
loc_82761A9C:
	// addi r10,r10,-32
	ctx.r10.s64 = ctx.r10.s64 + -32;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// bge 0x82761a9c
	if (!cr0.lt) goto loc_82761A9C;
loc_82761AAC:
	// clrlwi r11,r4,31
	r11.u64 = ctx.r4.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82761ac0
	if (cr6.eq) goto loc_82761AC0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x82761AC0;
	sub_82130588(ctx, base);
loc_82761AC0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// b 0x82761aec
	goto loc_82761AEC;
loc_82761AC8:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,-30128
	ctx.r9.s64 = r11.s64 + -30128;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82761ae8
	if (cr6.eq) goto loc_82761AE8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x82761AE8;
	sub_82130588(ctx, base);
loc_82761AE8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82761AEC:
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

__attribute__((alias("__imp__sub_82761B04"))) PPC_WEAK_FUNC(sub_82761B04);
PPC_FUNC_IMPL(__imp__sub_82761B04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82761B08"))) PPC_WEAK_FUNC(sub_82761B08);
PPC_FUNC_IMPL(__imp__sub_82761B08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82761940
	ctx.lr = 0x82761B28;
	sub_82761940(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82761B58;
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

__attribute__((alias("__imp__sub_82761B6C"))) PPC_WEAK_FUNC(sub_82761B6C);
PPC_FUNC_IMPL(__imp__sub_82761B6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82761B70"))) PPC_WEAK_FUNC(sub_82761B70);
PPC_FUNC_IMPL(__imp__sub_82761B70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x82761940
	ctx.lr = 0x82761B98;
	sub_82761940(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,68(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 68);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82761BC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_82761BDC"))) PPC_WEAK_FUNC(sub_82761BDC);
PPC_FUNC_IMPL(__imp__sub_82761BDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82761BE0"))) PPC_WEAK_FUNC(sub_82761BE0);
PPC_FUNC_IMPL(__imp__sub_82761BE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x82761940
	ctx.lr = 0x82761C08;
	sub_82761940(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,96(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 96);
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82761C34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_82761C4C"))) PPC_WEAK_FUNC(sub_82761C4C);
PPC_FUNC_IMPL(__imp__sub_82761C4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82761C50"))) PPC_WEAK_FUNC(sub_82761C50);
PPC_FUNC_IMPL(__imp__sub_82761C50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82761940
	ctx.lr = 0x82761C70;
	sub_82761940(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82761C98;
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

__attribute__((alias("__imp__sub_82761CAC"))) PPC_WEAK_FUNC(sub_82761CAC);
PPC_FUNC_IMPL(__imp__sub_82761CAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82761CB0"))) PPC_WEAK_FUNC(sub_82761CB0);
PPC_FUNC_IMPL(__imp__sub_82761CB0) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82761940
	ctx.lr = 0x82761CD0;
	sub_82761940(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f12,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f9,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f6,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// fmuls f8,f10,f10
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fsubs f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 - f0.f64));
	// fsubs f5,f6,f13
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// fmadds f4,f7,f7,f8
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f8.f64));
	// fmadds f3,f5,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fsqrts f1,f3
	ctx.f1.f64 = double(float(sqrt(ctx.f3.f64)));
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

__attribute__((alias("__imp__sub_82761D28"))) PPC_WEAK_FUNC(sub_82761D28);
PPC_FUNC_IMPL(__imp__sub_82761D28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82761D30;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x82761940
	ctx.lr = 0x82761D4C;
	sub_82761940(ctx, base);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// cmpwi cr6,r31,-1
	cr6.compare<int32_t>(r31.s32, -1, xer);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82761d88
	if (cr6.eq) goto loc_82761D88;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82761D80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x82761d90
	goto loc_82761D90;
loc_82761D88:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r11,r11,-1768
	r11.s64 = r11.s64 + -1768;
loc_82761D90:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82761858
	ctx.lr = 0x82761D9C;
	sub_82761858(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82761890
	ctx.lr = 0x82761DAC;
	sub_82761890(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8276c058
	ctx.lr = 0x82761DD0;
	sub_8276C058(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82761DD8"))) PPC_WEAK_FUNC(sub_82761DD8);
PPC_FUNC_IMPL(__imp__sub_82761DD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32243
	ctx.r10.s64 = -2113077248;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,20772
	ctx.r9.s64 = ctx.r10.s64 + 20772;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stb r11,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, r11.u8);
	// stb r11,21(r3)
	PPC_STORE_U8(ctx.r3.u32 + 21, r11.u8);
	// sth r11,22(r3)
	PPC_STORE_U16(ctx.r3.u32 + 22, r11.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82761E08"))) PPC_WEAK_FUNC(sub_82761E08);
PPC_FUNC_IMPL(__imp__sub_82761E08) {
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
	// addi r10,r11,20772
	ctx.r10.s64 = r11.s64 + 20772;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x82761E30;
	sub_82130588(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r8,r9,-30128
	ctx.r8.s64 = ctx.r9.s64 + -30128;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
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

