#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_826F7CA8"))) PPC_WEAK_FUNC(sub_826F7CA8);
PPC_FUNC_IMPL(__imp__sub_826F7CA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-24484(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24484);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826F7CB4"))) PPC_WEAK_FUNC(sub_826F7CB4);
PPC_FUNC_IMPL(__imp__sub_826F7CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826F7CB8"))) PPC_WEAK_FUNC(sub_826F7CB8);
PPC_FUNC_IMPL(__imp__sub_826F7CB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-24480(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24480);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826F7CC4"))) PPC_WEAK_FUNC(sub_826F7CC4);
PPC_FUNC_IMPL(__imp__sub_826F7CC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826F7CC8"))) PPC_WEAK_FUNC(sub_826F7CC8);
PPC_FUNC_IMPL(__imp__sub_826F7CC8) {
	PPC_FUNC_PROLOGUE();
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
	PPCRegister f0{};
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
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x826F7CD0;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823db9b8
	ctx.lr = 0x826F7CD8;
	// addi r31,r1,-368
	r31.s64 = ctx.r1.s64 + -368;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// fmr f20,f1
	ctx.fpscr.disableFlushMode();
	f20.f64 = ctx.f1.f64;
	// mr r20,r4
	r20.u64 = ctx.r4.u64;
	// fmr f27,f2
	f27.f64 = ctx.f2.f64;
	// lwz r10,0(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826f7d10
	if (!cr6.eq) goto loc_826F7D10;
loc_826F7CFC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r31,368
	ctx.r1.s64 = r31.s64 + 368;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba04
	ctx.lr = 0x826F7D0C;
	// b 0x823d9228
	return;
loc_826F7D10:
	// lhz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 12);
	// rotlwi r8,r9,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// neg r7,r8
	ctx.r7.s64 = -ctx.r8.s64;
	// rlwinm r12,r7,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x826F7D24;
	sub_823DBFF4(ctx, base);
	// lwz r6,0(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// neg r5,r8
	ctx.r5.s64 = -ctx.r8.s64;
	// stwux r6,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r1.u32 = ea;
	// rlwinm r12,r5,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFF0;
	// addi r25,r1,80
	r25.s64 = ctx.r1.s64 + 80;
	// bl 0x823dbff4
	ctx.lr = 0x826F7D3C;
	sub_823DBFF4(ctx, base);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lwz r3,0(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// fmuls f23,f4,f4
	ctx.fpscr.disableFlushMode();
	f23.f64 = double(float(ctx.f4.f64 * ctx.f4.f64));
	// li r29,0
	r29.s64 = 0;
	// fmuls f22,f5,f5
	f22.f64 = double(float(ctx.f5.f64 * ctx.f5.f64));
	// li r26,0
	r26.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lfs f0,-29232(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -29232);
	f0.f64 = double(temp.f32);
	// stwux r3,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r1.u32 = ea;
	// fsubs f13,f3,f0
	ctx.f13.f64 = double(float(ctx.f3.f64 - f0.f64));
	// addi r23,r1,80
	r23.s64 = ctx.r1.s64 + 80;
	// fsel f26,f13,f3,f0
	f26.f64 = ctx.f13.f64 >= 0.0 ? ctx.f3.f64 : f0.f64;
	// ble cr6,0x826f7cfc
	if (!cr6.gt) goto loc_826F7CFC;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lfs f24,15296(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15296);
	f24.f64 = double(temp.f32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f28,18204(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 18204);
	f28.f64 = double(temp.f32);
	// lfs f29,14980(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14980);
	f29.f64 = double(temp.f32);
	// li r28,0
	r28.s64 = 0;
	// lfs f25,26468(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 26468);
	f25.f64 = double(temp.f32);
	// mr r27,r25
	r27.u64 = r25.u64;
	// lfs f21,-28412(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -28412);
	f21.f64 = double(temp.f32);
	// subf r24,r25,r23
	r24.s64 = r23.s64 - r25.s64;
	// lfs f30,30280(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 30280);
	f30.f64 = double(temp.f32);
	// addi r21,r11,-31600
	r21.s64 = r11.s64 + -31600;
loc_826F7DB4:
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// add r30,r11,r28
	r30.u64 = r11.u64 + r28.u64;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826f7f14
	if (cr6.eq) goto loc_826F7F14;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826f7df0
	if (cr6.eq) goto loc_826F7DF0;
	// clrlwi r10,r20,24
	ctx.r10.u64 = r20.u32 & 0xFF;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r10,r8,1
	ctx.r10.u64 = ctx.r8.u64 ^ 1;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// bne cr6,0x826f7f14
	if (!cr6.eq) goto loc_826F7F14;
loc_826F7DF0:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x826f7e08
	if (!cr6.eq) goto loc_826F7E08;
	// fabs f0,f27
	ctx.fpscr.disableFlushMode();
	f0.u64 = f27.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bgt cr6,0x826f7f14
	if (cr6.gt) goto loc_826F7F14;
loc_826F7E08:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x826f7e1c
	if (!cr6.eq) goto loc_826F7E1C;
	// fabs f0,f27
	ctx.fpscr.disableFlushMode();
	f0.u64 = f27.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f21
	cr6.compare(f0.f64, f21.f64);
	// blt cr6,0x826f7f14
	if (cr6.lt) goto loc_826F7F14;
loc_826F7E1C:
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x826f7e34
	if (!cr6.eq) goto loc_826F7E34;
	// fsubs f0,f27,f25
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f27.f64 - f25.f64));
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// bgt cr6,0x826f7f14
	if (cr6.gt) goto loc_826F7F14;
loc_826F7E34:
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x826f7e4c
	if (!cr6.eq) goto loc_826F7E4C;
	// fadds f0,f27,f25
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f27.f64 + f25.f64));
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// bgt cr6,0x826f7f14
	if (cr6.gt) goto loc_826F7F14;
loc_826F7E4C:
	// addi r7,r31,96
	ctx.r7.s64 = r31.s64 + 96;
	// fmr f2,f26
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f26.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f26
	ctx.f1.f64 = f26.f64;
	// bl 0x82506320
	ctx.lr = 0x826F7E60;
	sub_82506320(ctx, base);
	// lfs f0,116(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f13,120(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,112(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	f0.f64 = double(temp.f32);
	// fmadds f11,f0,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f10,f13,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fcmpu cr6,f10,f23
	cr6.compare(ctx.f10.f64, f23.f64);
	// blt cr6,0x826f7f14
	if (cr6.lt) goto loc_826F7F14;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v63,r0,r21
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,80
	r11.s64 = r31.s64 + 80;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216c9c0
	ctx.lr = 0x826F7EA0;
	sub_8216C9C0(ctx, base);
	// fsubs f0,f1,f20
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 - f20.f64));
	// fsubs f13,f0,f29
	ctx.f13.f64 = double(float(f0.f64 - f29.f64));
	// fsubs f12,f0,f28
	ctx.f12.f64 = double(float(f0.f64 - f28.f64));
	// fneg f11,f13
	ctx.f11.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// fsel f10,f11,f0,f12
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? f0.f64 : ctx.f12.f64;
	// fadds f9,f10,f29
	ctx.f9.f64 = double(float(ctx.f10.f64 + f29.f64));
	// fadds f8,f10,f28
	ctx.f8.f64 = double(float(ctx.f10.f64 + f28.f64));
	// fsel f31,f9,f10,f8
	f31.f64 = ctx.f9.f64 >= 0.0 ? ctx.f10.f64 : ctx.f8.f64;
	// fabs f7,f31
	ctx.f7.u64 = f31.u64 & ~0x8000000000000000;
	// fcmpu cr6,f7,f24
	cr6.compare(ctx.f7.f64, f24.f64);
	// bgt cr6,0x826f7f14
	if (cr6.gt) goto loc_826F7F14;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// addi r7,r31,128
	ctx.r7.s64 = r31.s64 + 128;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,12(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// fmr f2,f1
	ctx.f2.f64 = ctx.f1.f64;
	// bl 0x82506320
	ctx.lr = 0x826F7EE4;
	sub_82506320(ctx, base);
	// lfs f0,148(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 148);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f13,152(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 152);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,144(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 144);
	f0.f64 = double(temp.f32);
	// fmadds f11,f0,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f10,f13,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fcmpu cr6,f10,f22
	cr6.compare(ctx.f10.f64, f22.f64);
	// bgt cr6,0x826f7f14
	if (cr6.gt) goto loc_826F7F14;
	// stfsx f31,r24,r27
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r24.u32 + r27.u32, temp.u32);
	// stw r30,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r30.u32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
loc_826F7F14:
	// lwz r10,0(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 0);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r28,r28,20
	r28.s64 = r28.s64 + 20;
	// lhz r11,12(r10)
	r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 12);
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x826f7db4
	if (cr6.lt) goto loc_826F7DB4;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x826f7cfc
	if (cr6.eq) goto loc_826F7CFC;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lwz r7,452(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 452);
	// lis r6,23772
	ctx.r6.s64 = 1557921792;
	// addi r5,r8,2192
	ctx.r5.s64 = ctx.r8.s64 + 2192;
	// ori r4,r6,64167
	ctx.r4.u64 = ctx.r6.u64 | 64167;
	// twllei r29,0
	// lwz r3,2192(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2192);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mulld r10,r3,r4
	ctx.r10.s64 = ctx.r3.s64 * ctx.r4.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r6,r11,1
	ctx.r6.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,2192(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2192, r11.u32);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// divw r4,r6,r29
	ctx.r4.s32 = ctx.r6.s32 / r29.s32;
	// rotlwi r9,r6,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// stw r11,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, r11.u32);
	// mullw r3,r4,r29
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(r29.s32);
	// subf r10,r3,r6
	ctx.r10.s64 = ctx.r6.s64 - ctx.r3.s64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// andc r6,r29,r9
	ctx.r6.u64 = r29.u64 & ~ctx.r9.u64;
	// twlgei r6,-1
	// lfsx f0,r8,r23
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r23.u32);
	f0.f64 = double(temp.f32);
	// lwzx r3,r8,r25
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + r25.u32);
	// stfs f0,0(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 0, temp.u32);
	// addi r1,r31,368
	ctx.r1.s64 = r31.s64 + 368;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba04
	ctx.lr = 0x826F7FA4;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_826F7FA8"))) PPC_WEAK_FUNC(sub_826F7FA8);
PPC_FUNC_IMPL(__imp__sub_826F7FA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x826F7FB0;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823db9d8
	ctx.lr = 0x826F7FB8;
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826f7fe4
	if (!cr6.eq) goto loc_826F7FE4;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x826f80e0
	goto loc_826F80E0;
loc_826F7FE4:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lhz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// li r27,0
	r27.s64 = 0;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lfs f29,-31380(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31380);
	f29.f64 = double(temp.f32);
	// beq cr6,0x826f80dc
	if (cr6.eq) goto loc_826F80DC;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// li r30,0
	r30.s64 = 0;
	// addi r26,r10,-31600
	r26.s64 = ctx.r10.s64 + -31600;
	// lfs f30,18204(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 18204);
	f30.f64 = double(temp.f32);
	// lfs f31,14980(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14980);
	f31.f64 = double(temp.f32);
loc_826F801C:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r31,r11,r30
	r31.u64 = r11.u64 + r30.u64;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826f80c4
	if (cr6.eq) goto loc_826F80C4;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x826f80c4
	if (!cr6.eq) goto loc_826F80C4;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f1,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// fmr f2,f1
	ctx.f2.f64 = ctx.f1.f64;
	// bl 0x82506320
	ctx.lr = 0x826F8054;
	sub_82506320(ctx, base);
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// vsubfp128 v127,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821bb520
	ctx.lr = 0x826F8078;
	sub_821BB520(ctx, base);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216c9c0
	ctx.lr = 0x826F808C;
	sub_8216C9C0(ctx, base);
	// fsubs f0,f1,f28
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 - f28.f64));
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// fsubs f12,f0,f30
	ctx.f12.f64 = double(float(f0.f64 - f30.f64));
	// fneg f11,f13
	ctx.f11.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// fsel f10,f11,f0,f12
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? f0.f64 : ctx.f12.f64;
	// fadds f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 + f31.f64));
	// fadds f8,f10,f30
	ctx.f8.f64 = double(float(ctx.f10.f64 + f30.f64));
	// fsel f0,f9,f10,f8
	f0.f64 = ctx.f9.f64 >= 0.0 ? ctx.f10.f64 : ctx.f8.f64;
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f29
	cr6.compare(ctx.f13.f64, f29.f64);
	// bge cr6,0x826f80c4
	if (!cr6.lt) goto loc_826F80C4;
	// stfs f0,0(r25)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r25.u32 + 0, temp.u32);
	// fmr f29,f13
	f29.f64 = ctx.f13.f64;
	// mr r27,r31
	r27.u64 = r31.u64;
loc_826F80C4:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,20
	r30.s64 = r30.s64 + 20;
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x826f801c
	if (cr6.lt) goto loc_826F801C;
loc_826F80DC:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_826F80E0:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dba24
	ctx.lr = 0x826F80F4;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_826F80F8"))) PPC_WEAK_FUNC(sub_826F80F8);
PPC_FUNC_IMPL(__imp__sub_826F80F8) {
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
	// addi r31,r1,-96
	r31.s64 = ctx.r1.s64 + -96;
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826f8130
	if (!cr6.eq) goto loc_826F8130;
loc_826F8118:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r31,96
	ctx.r1.s64 = r31.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_826F8130:
	// lhz r9,12(r8)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r8.u32 + 12);
	// rotlwi r11,r9,2
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// neg r10,r11
	ctx.r10.s64 = -r11.s64;
	// rlwinm r12,r10,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x826F8144;
	sub_823DBFF4(ctx, base);
	// lwz r7,0(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stwux r7,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r1.u32 = ea;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x826f8118
	if (!cr6.gt) goto loc_826F8118;
	// lwz r11,8(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
loc_826F8164:
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x826f819c
	if (cr6.eq) goto loc_826F819C;
	// clrlwi r7,r4,24
	ctx.r7.u64 = ctx.r4.u32 & 0xFF;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cntlzw r3,r7
	ctx.r3.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r7,r3,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// xori r7,r7,1
	ctx.r7.u64 = ctx.r7.u64 ^ 1;
	// addi r3,r7,4
	ctx.r3.s64 = ctx.r7.s64 + 4;
	// cmpw cr6,r5,r3
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r3.s32, xer);
	// bne cr6,0x826f819c
	if (!cr6.eq) goto loc_826F819C;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
loc_826F819C:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// bne 0x826f8164
	if (!cr0.eq) goto loc_826F8164;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826f8118
	if (cr6.eq) goto loc_826F8118;
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lis r5,23772
	ctx.r5.s64 = 1557921792;
	// addi r4,r7,2192
	ctx.r4.s64 = ctx.r7.s64 + 2192;
	// ori r3,r5,64167
	ctx.r3.u64 = ctx.r5.u64 | 64167;
	// twllei r10,0
	// lwz r11,2192(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2192);
	// lwz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// mulld r11,r11,r3
	r11.s64 = r11.s64 * ctx.r3.s64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// clrlwi r5,r11,1
	ctx.r5.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,2192(r7)
	PPC_STORE_U32(ctx.r7.u32 + 2192, r11.u32);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// divw r3,r5,r10
	ctx.r3.s32 = ctx.r5.s32 / ctx.r10.s32;
	// rotlwi r8,r5,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// mullw r9,r3,r10
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r10.s32);
	// subf r7,r9,r5
	ctx.r7.s64 = ctx.r5.s64 - ctx.r9.s64;
	// addi r5,r8,-1
	ctx.r5.s64 = ctx.r8.s64 + -1;
	// rlwinm r3,r7,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// andc r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 & ~ctx.r5.u64;
	// twlgei r10,-1
	// lwzx r3,r3,r6
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r6.u32);
	// addi r1,r31,96
	ctx.r1.s64 = r31.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826F821C"))) PPC_WEAK_FUNC(sub_826F821C);
PPC_FUNC_IMPL(__imp__sub_826F821C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826F8220"))) PPC_WEAK_FUNC(sub_826F8220);
PPC_FUNC_IMPL(__imp__sub_826F8220) {
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
	ctx.lr = 0x826F8228;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// lwz r4,0(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826f8254
	if (cr6.eq) goto loc_826F8254;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8217d890
	ctx.lr = 0x826F8248;
	sub_8217D890(ctx, base);
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r10.u32);
loc_826F8254:
	// lhz r11,4(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// li r22,0
	r22.s64 = 0;
	// mr r24,r22
	r24.u64 = r22.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826f82f8
	if (cr6.eq) goto loc_826F82F8;
	// mr r25,r22
	r25.u64 = r22.u64;
loc_826F826C:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// add. r31,r25,r11
	r31.u64 = r25.u64 + r11.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x826f82e4
	if (cr0.eq) goto loc_826F82E4;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2aa8
	ctx.lr = 0x826F8284;
	sub_821D2AA8(ctx, base);
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r29,60
	r29.s64 = 60;
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// lwzx r30,r29,r28
	r30.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826f82e0
	if (cr6.eq) goto loc_826F82E0;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x826f82e0
	if (cr6.eq) goto loc_826F82E0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x826F82B4;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x826f82e0
	if (cr6.eq) goto loc_826F82E0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x826F82C8;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x82504be0
	ctx.lr = 0x826F82DC;
	sub_82504BE0(ctx, base);
	// b 0x826f82e4
	goto loc_826F82E4;
loc_826F82E0:
	// stw r22,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r22.u32);
loc_826F82E4:
	// lhz r11,4(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r25,r25,20
	r25.s64 = r25.s64 + 20;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x826f826c
	if (cr6.lt) goto loc_826F826C;
loc_826F82F8:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_826F8304"))) PPC_WEAK_FUNC(sub_826F8304);
PPC_FUNC_IMPL(__imp__sub_826F8304) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826F8308"))) PPC_WEAK_FUNC(sub_826F8308);
PPC_FUNC_IMPL(__imp__sub_826F8308) {
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
	ctx.lr = 0x826F8320;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826f8354
	if (cr6.eq) goto loc_826F8354;
	// li r11,0
	r11.s64 = 0;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bl 0x82323db8
	ctx.lr = 0x826F833C;
	sub_82323DB8(ctx, base);
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
loc_826F8354:
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

__attribute__((alias("__imp__sub_826F836C"))) PPC_WEAK_FUNC(sub_826F836C);
PPC_FUNC_IMPL(__imp__sub_826F836C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826F8370"))) PPC_WEAK_FUNC(sub_826F8370);
PPC_FUNC_IMPL(__imp__sub_826F8370) {
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
	ctx.lr = 0x826F8378;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
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
	ctx.lr = 0x826F8390;
	sub_82130528(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x826f841c
	if (!cr6.gt) goto loc_826F841C;
	// addi r31,r24,16
	r31.s64 = r24.s64 + 16;
	// mr r25,r30
	r25.u64 = r30.u64;
	// li r26,0
	r26.s64 = 0;
loc_826F83A8:
	// addic. r11,r31,-16
	xer.ca = r31.u32 > 15;
	r11.s64 = r31.s64 + -16;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x826f8410
	if (cr0.eq) goto loc_826F8410;
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r29,60
	r29.s64 = 60;
	// stw r26,-16(r31)
	PPC_STORE_U32(r31.u32 + -16, r26.u32);
	// lwzx r30,r29,r28
	r30.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826f840c
	if (cr6.eq) goto loc_826F840C;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x826f840c
	if (cr6.eq) goto loc_826F840C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82187a38
	ctx.lr = 0x826F83E0;
	sub_82187A38(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x826f840c
	if (cr6.eq) goto loc_826F840C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217d890
	ctx.lr = 0x826F83F4;
	sub_8217D890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwzx r4,r29,r28
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r28.u32);
	// bl 0x82504be0
	ctx.lr = 0x826F8408;
	sub_82504BE0(ctx, base);
	// b 0x826f8410
	goto loc_826F8410;
loc_826F840C:
	// stw r26,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r26.u32);
loc_826F8410:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r31,r31,20
	r31.s64 = r31.s64 + 20;
	// bne 0x826f83a8
	if (!cr0.eq) goto loc_826F83A8;
loc_826F841C:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_826F8428"))) PPC_WEAK_FUNC(sub_826F8428);
PPC_FUNC_IMPL(__imp__sub_826F8428) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x826F8430;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lhz r31,14(r28)
	r31.u64 = PPC_LOAD_U16(r28.u32 + 14);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826f8470
	if (cr6.eq) goto loc_826F8470;
	// lwz r29,8(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x826f8468
	if (!cr6.gt) goto loc_826F8468;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_826F8454:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x826F845C;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,20
	r30.s64 = r30.s64 + 20;
	// bne 0x826f8454
	if (!cr0.eq) goto loc_826F8454;
loc_826F8468:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x826F8470;
	sub_82130588(ctx, base);
loc_826F8470:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821d2810
	ctx.lr = 0x826F8478;
	sub_821D2810(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826F8480"))) PPC_WEAK_FUNC(sub_826F8480);
PPC_FUNC_IMPL(__imp__sub_826F8480) {
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
	ctx.lr = 0x826F8488;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-24484
	r31.s64 = r11.s64 + -24484;
	// lwz r11,-24484(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -24484);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826f85b8
	if (!cr6.eq) goto loc_826F85B8;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826F84A8;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826f84bc
	if (cr6.eq) goto loc_826F84BC;
	// bl 0x821d5408
	ctx.lr = 0x826F84B8;
	sub_821D5408(ctx, base);
	// b 0x826f84c0
	goto loc_826F84C0;
loc_826F84BC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826F84C0:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32145
	r11.s64 = -2106654720;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,15316
	ctx.r7.s64 = ctx.r10.s64 + 15316;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,31912
	ctx.r9.s64 = r11.s64 + 31912;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,20
	ctx.r5.s64 = 20;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32144
	ctx.r8.s64 = -2106589184;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,-31992
	ctx.r4.s64 = ctx.r8.s64 + -31992;
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
	// addi r5,r3,-17556
	ctx.r5.s64 = ctx.r3.s64 + -17556;
	// addi r4,r10,-17532
	ctx.r4.s64 = ctx.r10.s64 + -17532;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r29,r9,-17496
	r29.s64 = ctx.r9.s64 + -17496;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r28,r8,-17460
	r28.s64 = ctx.r8.s64 + -17460;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,8
	ctx.r8.s64 = 8;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// li r7,12
	ctx.r7.s64 = 12;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// stw r8,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r8.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r7,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r7.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821d4458
	ctx.lr = 0x826F8564;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x826F8574;
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
	ctx.lr = 0x826F8590;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-17424
	ctx.r4.s64 = ctx.r8.s64 + -17424;
	// bl 0x821d4b00
	ctx.lr = 0x826F85A0;
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
	ctx.lr = 0x826F85B8;
	sub_821C0548(ctx, base);
loc_826F85B8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826F85C0"))) PPC_WEAK_FUNC(sub_826F85C0);
PPC_FUNC_IMPL(__imp__sub_826F85C0) {
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
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x826F85D8;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826f861c
	if (cr6.eq) goto loc_826F861C;
	// bl 0x821d2970
	ctx.lr = 0x826F85E8;
	sub_821D2970(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,15304
	ctx.r9.s64 = ctx.r10.s64 + 15304;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// sth r11,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r11.u16);
	// sth r11,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r11.u16);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_826F861C:
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

__attribute__((alias("__imp__sub_826F8634"))) PPC_WEAK_FUNC(sub_826F8634);
PPC_FUNC_IMPL(__imp__sub_826F8634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826F8638"))) PPC_WEAK_FUNC(sub_826F8638);
PPC_FUNC_IMPL(__imp__sub_826F8638) {
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
	ctx.lr = 0x826F8640;
	// stwu r1,-1712(r1)
	ea = -1712 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r27,0
	r27.s64 = 0;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// sth r27,114(r1)
	PPC_STORE_U16(ctx.r1.u32 + 114, r27.u16);
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// sth r27,112(r1)
	PPC_STORE_U16(ctx.r1.u32 + 112, r27.u16);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821e5fd0
	ctx.lr = 0x826F8674;
	sub_821E5FD0(ctx, base);
	// lis r31,-32112
	r31.s64 = -2104492032;
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// li r29,60
	r29.s64 = 60;
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r26.u32);
	// stb r27,92(r1)
	PPC_STORE_U8(ctx.r1.u32 + 92, r27.u8);
	// lwz r11,23572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23572);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lwzx r10,r29,r30
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// stwx r9,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r9.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// lwz r28,0(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x826f86fc
	if (cr6.eq) goto loc_826F86FC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821d2970
	ctx.lr = 0x826F86C4;
	sub_821D2970(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r10,r11,15304
	ctx.r10.s64 = r11.s64 + 15304;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// addi r3,r28,8
	ctx.r3.s64 = r28.s64 + 8;
	// bl 0x826f8220
	ctx.lr = 0x826F86E0;
	sub_826F8220(ctx, base);
	// lwz r11,23572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23572);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// stwx r9,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r9.u32);
	// addi r1,r1,1712
	ctx.r1.s64 = ctx.r1.s64 + 1712;
	// b 0x823d9240
	return;
loc_826F86FC:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stwx r10,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r10.u32);
	// stw r11,23572(r31)
	PPC_STORE_U32(r31.u32 + 23572, r11.u32);
	// addi r1,r1,1712
	ctx.r1.s64 = ctx.r1.s64 + 1712;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826F8710"))) PPC_WEAK_FUNC(sub_826F8710);
PPC_FUNC_IMPL(__imp__sub_826F8710) {
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
	// bl 0x826f8428
	ctx.lr = 0x826F8730;
	sub_826F8428(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826f8748
	if (cr6.eq) goto loc_826F8748;
	// bl 0x82130588
	ctx.lr = 0x826F8744;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826F8748:
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

__attribute__((alias("__imp__sub_826F8760"))) PPC_WEAK_FUNC(sub_826F8760);
PPC_FUNC_IMPL(__imp__sub_826F8760) {
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
	// addi r31,r11,-24480
	r31.s64 = r11.s64 + -24480;
	// lwz r11,-24480(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -24480);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826f8894
	if (!cr6.eq) goto loc_826F8894;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826F8790;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826f87a4
	if (cr6.eq) goto loc_826F87A4;
	// bl 0x821d5408
	ctx.lr = 0x826F87A0;
	sub_821D5408(ctx, base);
	// b 0x826f87a8
	goto loc_826F87A8;
loc_826F87A4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826F87A8:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32145
	r11.s64 = -2106654720;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,15328
	ctx.r7.s64 = ctx.r10.s64 + 15328;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,31928
	ctx.r9.s64 = r11.s64 + 31928;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32144
	ctx.r8.s64 = -2106589184;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,-31296
	ctx.r4.s64 = ctx.r8.s64 + -31296;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,-17360
	ctx.r9.s64 = ctx.r3.s64 + -17360;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,8
	ctx.r10.s64 = 8;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r11,-24484(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -24484);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x826f8824
	if (!cr6.eq) goto loc_826F8824;
	// bl 0x826f8480
	ctx.lr = 0x826F8820;
	sub_826F8480(ctx, base);
	// lwz r11,-24484(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -24484);
loc_826F8824:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r10,-17404
	ctx.r9.s64 = ctx.r10.s64 + -17404;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r11.u32);
	// bl 0x821d4458
	ctx.lr = 0x826F8840;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x826F8850;
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
	ctx.lr = 0x826F886C;
	sub_821D41D0(ctx, base);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r6,-17368
	ctx.r4.s64 = ctx.r6.s64 + -17368;
	// bl 0x821d4b00
	ctx.lr = 0x826F887C;
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
	ctx.lr = 0x826F8894;
	sub_821C0548(ctx, base);
loc_826F8894:
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

__attribute__((alias("__imp__sub_826F88AC"))) PPC_WEAK_FUNC(sub_826F88AC);
PPC_FUNC_IMPL(__imp__sub_826F88AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826F88B0"))) PPC_WEAK_FUNC(sub_826F88B0);
PPC_FUNC_IMPL(__imp__sub_826F88B0) {
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
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,15372
	ctx.r4.s64 = ctx.r10.s64 + 15372;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x826F88E0;
	sub_821CA540(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r5,r9,15368
	ctx.r5.s64 = ctx.r9.s64 + 15368;
	// addi r4,r8,15348
	ctx.r4.s64 = ctx.r8.s64 + 15348;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,454
	ctx.r6.s64 = 454;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826f8638
	ctx.lr = 0x826F8900;
	sub_826F8638(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826F8908;
	sub_821C9A90(ctx, base);
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

__attribute__((alias("__imp__sub_826F8920"))) PPC_WEAK_FUNC(sub_826F8920);
PPC_FUNC_IMPL(__imp__sub_826F8920) {
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
	// bne cr6,0x826f8964
	if (!cr6.eq) goto loc_826F8964;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x826f895c
	if (cr6.eq) goto loc_826F895C;
	// bl 0x826f8370
	ctx.lr = 0x826F8958;
	sub_826F8370(ctx, base);
	// b 0x826f8960
	goto loc_826F8960;
loc_826F895C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826F8960:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_826F8964:
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

__attribute__((alias("__imp__sub_826F8980"))) PPC_WEAK_FUNC(sub_826F8980);
PPC_FUNC_IMPL(__imp__sub_826F8980) {
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
	ctx.lr = 0x826F8988;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r29,r11,30576
	r29.s64 = r11.s64 + 30576;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r10,5008
	ctx.r4.s64 = ctx.r10.s64 + 5008;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ca540
	ctx.lr = 0x826F89AC;
	sub_821CA540(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8218eda8
	ctx.lr = 0x826F89B4;
	sub_8218EDA8(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826F89C0;
	sub_821C9A90(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826F89C8"))) PPC_WEAK_FUNC(sub_826F89C8);
PPC_FUNC_IMPL(__imp__sub_826F89C8) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	f0.f64 = double(temp.f32);
	// lis r11,32640
	r11.s64 = 2139095040;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r9,r10,0,1,8
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x7F800000;
	// subf r8,r9,r11
	ctx.r8.s64 = r11.s64 - ctx.r9.s64;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826f8ae0
	if (cr6.eq) goto loc_826F8AE0;
	// lfs f0,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r9,r10,0,1,8
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x7F800000;
	// subf r8,r9,r11
	ctx.r8.s64 = r11.s64 - ctx.r9.s64;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826f8ae0
	if (cr6.eq) goto loc_826F8AE0;
	// lfs f0,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r9,r10,0,1,8
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x7F800000;
	// subf r8,r9,r11
	ctx.r8.s64 = r11.s64 - ctx.r9.s64;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826f8ae0
	if (cr6.eq) goto loc_826F8AE0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r9,r11,-17216
	ctx.r9.s64 = r11.s64 + -17216;
	// addi r8,r10,-17232
	ctx.r8.s64 = ctx.r10.s64 + -17232;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lfs f13,-17216(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17216);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// lfs f0,-17232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -17232);
	f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// vminfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_min_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,8(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f10,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// vmaxfp128 v60,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_max_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f8.f64 = double(temp.f32);
	// lfs f9,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f6,f9,f0
	ctx.f6.f64 = double(float(ctx.f9.f64 - f0.f64));
	// fsubs f7,f8,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// fdivs f1,f6,f11
	ctx.f1.f64 = double(float(ctx.f6.f64 / ctx.f11.f64));
	// fdivs f2,f7,f10
	ctx.f2.f64 = double(float(ctx.f7.f64 / ctx.f10.f64));
	// beq cr6,0x826f8ae0
	if (cr6.eq) goto loc_826F8AE0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8218d7c0
	ctx.lr = 0x826F8ACC;
	sub_8218D7C0(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826F8AE0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826F8AF4"))) PPC_WEAK_FUNC(sub_826F8AF4);
PPC_FUNC_IMPL(__imp__sub_826F8AF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826F8AF8"))) PPC_WEAK_FUNC(sub_826F8AF8);
PPC_FUNC_IMPL(__imp__sub_826F8AF8) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826f8b44
	if (cr6.eq) goto loc_826F8B44;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// bne 0x826f8b3c
	if (!cr0.eq) goto loc_826F8B3C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8218cd10
	ctx.lr = 0x826F8B34;
	sub_8218CD10(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x826F8B3C;
	sub_82130588(ctx, base);
loc_826F8B3C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
loc_826F8B44:
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

__attribute__((alias("__imp__sub_826F8B5C"))) PPC_WEAK_FUNC(sub_826F8B5C);
PPC_FUNC_IMPL(__imp__sub_826F8B5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826F8B60"))) PPC_WEAK_FUNC(sub_826F8B60);
PPC_FUNC_IMPL(__imp__sub_826F8B60) {
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
	// bl 0x8271e4c8
	ctx.lr = 0x826F8B78;
	sub_8271E4C8(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r8,r11,16000
	ctx.r8.s64 = r11.s64 + 16000;
	// li r11,0
	r11.s64 = 0;
	// li r7,-1
	ctx.r7.s64 = -1;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r5,255
	ctx.r5.s64 = 255;
	// lfs f13,15696(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 15696);
	ctx.f13.f64 = double(temp.f32);
	// li r4,4
	ctx.r4.s64 = 4;
	// stfs f0,96(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f13,156(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 156, temp.u32);
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
	// stw r11,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r11.u32);
	// addi r10,r31,96
	ctx.r10.s64 = r31.s64 + 96;
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
	// stw r11,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r11.u32);
	// stw r11,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r11.u32);
	// stw r11,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r11.u32);
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// stw r11,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r11.u32);
	// stw r11,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r11.u32);
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
	// stw r7,152(r31)
	PPC_STORE_U32(r31.u32 + 152, ctx.r7.u32);
	// stw r6,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r6.u32);
	// stb r5,164(r31)
	PPC_STORE_U8(r31.u32 + 164, ctx.r5.u8);
	// stb r11,165(r31)
	PPC_STORE_U8(r31.u32 + 165, r11.u8);
	// stb r4,166(r31)
	PPC_STORE_U8(r31.u32 + 166, ctx.r4.u8);
	// stfs f0,172(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
	// stw r11,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r11.u32);
	// stw r11,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r11.u32);
	// stw r11,184(r31)
	PPC_STORE_U32(r31.u32 + 184, r11.u32);
	// stw r11,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r11.u32);
	// bl 0x82548ba8
	ctx.lr = 0x826F8C18;
	sub_82548BA8(ctx, base);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r4,r3,29696
	ctx.r4.s64 = ctx.r3.s64 + 29696;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// bl 0x82144a20
	ctx.lr = 0x826F8C2C;
	sub_82144A20(ctx, base);
	// stw r3,176(r31)
	PPC_STORE_U32(r31.u32 + 176, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8271e618
	ctx.lr = 0x826F8C38;
	sub_8271E618(ctx, base);
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r10.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826F8C58"))) PPC_WEAK_FUNC(sub_826F8C58);
PPC_FUNC_IMPL(__imp__sub_826F8C58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r10,r11,16000
	ctx.r10.s64 = r11.s64 + 16000;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x8271e550
	sub_8271E550(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826F8C68"))) PPC_WEAK_FUNC(sub_826F8C68);
PPC_FUNC_IMPL(__imp__sub_826F8C68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x826F8C70;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,4
	ctx.r9.s64 = 4;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// addi r11,r8,19856
	r11.s64 = ctx.r8.s64 + 19856;
	// lwzx r5,r9,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r11,r11,1392
	r11.s64 = r11.s64 + 1392;
	// lwz r31,-3660(r7)
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + -3660);
	// rlwinm r10,r5,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 6) & 0xFFFFFFC0;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lis r6,-32111
	ctx.r6.s64 = -2104426496;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r25,r6,-24476
	r25.s64 = ctx.r6.s64 + -24476;
	// bl 0x8226ad80
	ctx.lr = 0x826F8CB8;
	sub_8226AD80(ctx, base);
	// clrlwi r4,r3,16
	ctx.r4.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8226a808
	ctx.lr = 0x826F8CC8;
	sub_8226A808(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// li r24,9
	r24.s64 = 9;
loc_826F8CD0:
	// lwz r29,0(r25)
	r29.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826f8db4
	if (cr6.eq) goto loc_826F8DB4;
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r27,r11,r28
	r27.u64 = r11.u64 + r28.u64;
loc_826F8CE4:
	// lbz r11,6(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 6);
	// cmpw cr6,r11,r23
	cr6.compare<int32_t>(r11.s32, r23.s32, xer);
	// bne cr6,0x826f8da8
	if (!cr6.eq) goto loc_826F8DA8;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826F8D04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,128(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// lwz r31,472(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 472);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826f8da8
	if (cr6.eq) goto loc_826F8DA8;
	// lwz r3,452(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 452);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826f8da8
	if (cr6.eq) goto loc_826F8DA8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826F8D30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826f8da8
	if (!cr6.eq) goto loc_826F8DA8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826F8D50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r30,r26
	cr6.compare<uint32_t>(r30.u32, r26.u32, xer);
	// bge cr6,0x826f8d68
	if (!cr6.lt) goto loc_826F8D68;
	// stw r31,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r31.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// b 0x826f8da8
	goto loc_826F8DA8;
loc_826F8D68:
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826f8da8
	if (cr6.eq) goto loc_826F8DA8;
	// lfs f0,172(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 172);
	f0.f64 = double(temp.f32);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
loc_826F8D7C:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f13,172(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 172);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x826f8da0
	if (cr6.lt) goto loc_826F8DA0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// blt cr6,0x826f8d7c
	if (cr6.lt) goto loc_826F8D7C;
	// b 0x826f8da8
	goto loc_826F8DA8;
loc_826F8DA0:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r31,r11,r28
	PPC_STORE_U32(r11.u32 + r28.u32, r31.u32);
loc_826F8DA8:
	// lwz r29,12(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x826f8ce4
	if (!cr6.eq) goto loc_826F8CE4;
loc_826F8DB4:
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// bne 0x826f8cd0
	if (!cr0.eq) goto loc_826F8CD0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_826F8DCC"))) PPC_WEAK_FUNC(sub_826F8DCC);
PPC_FUNC_IMPL(__imp__sub_826F8DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826F8DD0"))) PPC_WEAK_FUNC(sub_826F8DD0);
PPC_FUNC_IMPL(__imp__sub_826F8DD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r15{};
	PPCRegister r19{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r4,27
	cr6.compare<uint32_t>(ctx.r4.u32, 27, xer);
	// bgtlr cr6
	if (cr6.gt) return;
	// lis r12,-32144
	r12.s64 = -2106589184;
	// addi r12,r12,-29192
	r12.s64 = r12.s64 + -29192;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_826F8E68;
	case 1:
		goto loc_826F8E7C;
	case 2:
		goto loc_826F8E90;
	case 3:
		goto loc_826F8EA4;
	case 4:
		goto loc_826F8EB8;
	case 5:
		goto loc_826F8ECC;
	case 6:
		goto loc_826F8EE0;
	case 7:
		goto loc_826F8EF4;
	case 8:
		goto loc_826F8F08;
	case 9:
		goto loc_826F8F1C;
	case 10:
		goto loc_826F8F30;
	case 11:
		goto loc_826F9034;
	case 12:
		goto loc_826F8F44;
	case 13:
		goto loc_826F8F58;
	case 14:
		goto loc_826F8F6C;
	case 15:
		goto loc_826F8F80;
	case 16:
		goto loc_826F8F94;
	case 17:
		goto loc_826F8FA8;
	case 18:
		goto loc_826F8FBC;
	case 19:
		goto loc_826F8FD0;
	case 20:
		goto loc_826F8FE4;
	case 21:
		goto loc_826F8FF8;
	case 22:
		goto loc_826F9034;
	case 23:
		goto loc_826F9034;
	case 24:
		goto loc_826F9034;
	case 25:
		goto loc_826F9034;
	case 26:
		goto loc_826F900C;
	case 27:
		goto loc_826F9020;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-29080(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -29080);
	// lwz r19,-29060(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -29060);
	// lwz r19,-29040(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -29040);
	// lwz r19,-29020(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -29020);
	// lwz r19,-29000(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -29000);
	// lwz r19,-28980(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28980);
	// lwz r19,-28960(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28960);
	// lwz r19,-28940(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28940);
	// lwz r19,-28920(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28920);
	// lwz r19,-28900(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28900);
	// lwz r19,-28880(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28880);
	// lwz r19,-28620(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28620);
	// lwz r19,-28860(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28860);
	// lwz r19,-28840(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28840);
	// lwz r19,-28820(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28820);
	// lwz r19,-28800(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28800);
	// lwz r19,-28780(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28780);
	// lwz r19,-28760(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28760);
	// lwz r19,-28740(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28740);
	// lwz r19,-28720(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28720);
	// lwz r19,-28700(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28700);
	// lwz r19,-28680(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28680);
	// lwz r19,-28620(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28620);
	// lwz r19,-28620(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28620);
	// lwz r19,-28620(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28620);
	// lwz r19,-28620(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28620);
	// lwz r19,-28660(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28660);
	// lwz r19,-28640(r15)
	r19.u64 = PPC_LOAD_U32(r15.u32 + -28640);
loc_826F8E68:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,10(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 10);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F8E7C:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,14(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 14);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F8E90:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,18(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 18);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F8EA4:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,22(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 22);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F8EB8:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,26(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 26);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F8ECC:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,30(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 30);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F8EE0:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,34(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 34);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F8EF4:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,38(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 38);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F8F08:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,42(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 42);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F8F1C:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,46(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 46);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F8F30:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,50(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 50);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F8F44:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,54(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 54);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F8F58:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,58(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 58);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F8F6C:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,62(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 62);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F8F80:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,66(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 66);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F8F94:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,70(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 70);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F8FA8:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,74(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 74);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F8FBC:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,78(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 78);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F8FD0:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,82(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 82);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F8FE4:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,86(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 86);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F8FF8:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,90(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 90);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F900C:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,94(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 94);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F9020:
	// lwz r11,176(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r3,r10,19856
	ctx.r3.s64 = ctx.r10.s64 + 19856;
	// lwz r4,98(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 98);
	// b 0x82144a28
	sub_82144A28(ctx, base);
	return;
loc_826F9034:
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826F9038"))) PPC_WEAK_FUNC(sub_826F9038);
PPC_FUNC_IMPL(__imp__sub_826F9038) {
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
	ctx.lr = 0x826F9040;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826f8dd0
	ctx.lr = 0x826F904C;
	sub_826F8DD0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826f9110
	if (cr6.eq) goto loc_826F9110;
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// addi r30,r31,184
	r30.s64 = r31.s64 + 184;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826f9070
	if (cr6.eq) goto loc_826F9070;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x826F9070;
	sub_8213C218(ctx, base);
loc_826F9070:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r4,255
	ctx.r4.s64 = 255;
	// lfs f13,15696(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 15696);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r31,64
	ctx.r10.s64 = r31.s64 + 64;
	// li r8,36
	ctx.r8.s64 = 36;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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
	// stw r6,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r6.u32);
	// stb r4,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r4.u8);
	// stb r11,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, r11.u8);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// stb r8,150(r1)
	PPC_STORE_U8(ctx.r1.u32 + 150, ctx.r8.u8);
	// lwz r4,30(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 30);
	// bl 0x82549118
	ctx.lr = 0x826F90FC;
	sub_82549118(ctx, base);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r4,34(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 34);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825491f0
	ctx.lr = 0x826F9110;
	sub_825491F0(ctx, base);
loc_826F9110:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826F9118"))) PPC_WEAK_FUNC(sub_826F9118);
PPC_FUNC_IMPL(__imp__sub_826F9118) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826f8dd0
	ctx.lr = 0x826F9134;
	sub_826F8DD0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826f91e0
	if (cr6.eq) goto loc_826F91E0;
	// lwz r3,184(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826f9154
	if (cr6.eq) goto loc_826F9154;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x826F9154;
	sub_8213C218(ctx, base);
loc_826F9154:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,80(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r4,255
	ctx.r4.s64 = 255;
	// lfs f13,15696(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 15696);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r31,64
	ctx.r10.s64 = r31.s64 + 64;
	// li r8,36
	ctx.r8.s64 = 36;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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
	// stw r6,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r6.u32);
	// stb r4,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r4.u8);
	// stb r11,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, r11.u8);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// stb r8,150(r1)
	PPC_STORE_U8(ctx.r1.u32 + 150, ctx.r8.u8);
	// lwz r4,38(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 38);
	// bl 0x82549118
	ctx.lr = 0x826F91E0;
	sub_82549118(ctx, base);
loc_826F91E0:
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

__attribute__((alias("__imp__sub_826F91F8"))) PPC_WEAK_FUNC(sub_826F91F8);
PPC_FUNC_IMPL(__imp__sub_826F91F8) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,16000
	ctx.r10.s64 = r11.s64 + 16000;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8271e550
	ctx.lr = 0x826F9224;
	sub_8271E550(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826f923c
	if (cr6.eq) goto loc_826F923C;
	// bl 0x82130588
	ctx.lr = 0x826F9238;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826F923C:
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

__attribute__((alias("__imp__sub_826F9254"))) PPC_WEAK_FUNC(sub_826F9254);
PPC_FUNC_IMPL(__imp__sub_826F9254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826F9258"))) PPC_WEAK_FUNC(sub_826F9258);
PPC_FUNC_IMPL(__imp__sub_826F9258) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lwz r11,168(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826f9288
	if (cr6.eq) goto loc_826F9288;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lwz r10,22080(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 22080);
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// rlwinm r10,r9,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// b 0x826f92c0
	goto loc_826F92C0;
loc_826F9288:
	// lbz r10,500(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 500);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826f92b8
	if (cr6.eq) goto loc_826F92B8;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826f92b8
	if (cr6.eq) goto loc_826F92B8;
	// lwz r10,48(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826f92b8
	if (cr6.eq) goto loc_826F92B8;
	// lwz r11,28(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// b 0x826f92bc
	goto loc_826F92BC;
loc_826F92B8:
	// addi r11,r11,112
	r11.s64 = r11.s64 + 112;
loc_826F92BC:
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
loc_826F92C0:
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,16
	ctx.r7.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
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
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826F92F4"))) PPC_WEAK_FUNC(sub_826F92F4);
PPC_FUNC_IMPL(__imp__sub_826F92F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826F92F8"))) PPC_WEAK_FUNC(sub_826F92F8);
PPC_FUNC_IMPL(__imp__sub_826F92F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// li r12,-32
	r12.s64 = -32;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,4
	ctx.r9.s64 = 4;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r11,r8,19856
	r11.s64 = ctx.r8.s64 + 19856;
	// lwz r3,168(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lwzx r6,r9,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r5,r11,1392
	ctx.r5.s64 = r11.s64 + 1392;
	// rlwinm r11,r6,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 6) & 0xFFFFFFC0;
	// lbz r4,500(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 500);
	// rlwinm r10,r4,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x20;
	// lvx128 v127,r11,r5
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stvx128 v127,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x826f9374
	if (cr6.eq) goto loc_826F9374;
	// lwz r11,52(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826f9374
	if (cr6.eq) goto loc_826F9374;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826f9374
	if (cr6.eq) goto loc_826F9374;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// b 0x826f937c
	goto loc_826F937C;
loc_826F9374:
	// bl 0x82794ee8
	ctx.lr = 0x826F9378;
	sub_82794EE8(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
loc_826F937C:
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// vsubfp128 v62,v127,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// fmadds f11,f0,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f10,f13,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f10,172(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// li r0,-32
	r0.s64 = -32;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826F93C4"))) PPC_WEAK_FUNC(sub_826F93C4);
PPC_FUNC_IMPL(__imp__sub_826F93C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826F93C8"))) PPC_WEAK_FUNC(sub_826F93C8);
PPC_FUNC_IMPL(__imp__sub_826F93C8) {
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
	// lwz r3,168(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lbz r11,500(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 500);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826f9414
	if (cr6.eq) goto loc_826F9414;
	// lwz r11,52(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826f9414
	if (cr6.eq) goto loc_826F9414;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826f9414
	if (cr6.eq) goto loc_826F9414;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r4,r11,64
	ctx.r4.s64 = r11.s64 + 64;
	// b 0x826f941c
	goto loc_826F941C;
loc_826F9414:
	// bl 0x82794ee8
	ctx.lr = 0x826F9418;
	sub_82794EE8(ctx, base);
	// addi r4,r3,48
	ctx.r4.s64 = ctx.r3.s64 + 48;
loc_826F941C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b860
	ctx.lr = 0x826F9424;
	sub_8213B860(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826F9438"))) PPC_WEAK_FUNC(sub_826F9438);
PPC_FUNC_IMPL(__imp__sub_826F9438) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826F9460;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826F9470;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x826f94c8
	if (cr6.eq) goto loc_826F94C8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,-23636(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -23636);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826F9498;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8254dfc0
	ctx.lr = 0x826F94A4;
	sub_8254DFC0(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826F94B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826F94C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826F94C8:
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

__attribute__((alias("__imp__sub_826F94E0"))) PPC_WEAK_FUNC(sub_826F94E0);
PPC_FUNC_IMPL(__imp__sub_826F94E0) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826F9504;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826F9514;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x826f9538
	if (!cr6.eq) goto loc_826F9538;
loc_826F9520:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_826F9538:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826F954C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826f9520
	if (cr6.eq) goto loc_826F9520;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r31,-23636(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -23636);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826F9574;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8254dfd8
	ctx.lr = 0x826F9580;
	sub_8254DFD8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r3,r6,1
	ctx.r3.u64 = ctx.r6.u64 ^ 1;
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826F95A4"))) PPC_WEAK_FUNC(sub_826F95A4);
PPC_FUNC_IMPL(__imp__sub_826F95A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826F95A8"))) PPC_WEAK_FUNC(sub_826F95A8);
PPC_FUNC_IMPL(__imp__sub_826F95A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,188(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// addi r11,r11,168
	r11.s64 = r11.s64 + 168;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r3,r8,1
	ctx.r3.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x826f95d0
	if (!cr6.eq) goto loc_826F95D0;
	// li r11,0
	r11.s64 = 0;
loc_826F95D0:
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826F95D8"))) PPC_WEAK_FUNC(sub_826F95D8);
PPC_FUNC_IMPL(__imp__sub_826F95D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82761dd8
	ctx.lr = 0x826F95F0;
	sub_82761DD8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r7,r31,32
	ctx.r7.s64 = r31.s64 + 32;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r9,r31,48
	ctx.r9.s64 = r31.s64 + 48;
	// stw r8,3636(r31)
	PPC_STORE_U32(r31.u32 + 3636, ctx.r8.u32);
	// addi r11,r31,2608
	r11.s64 = r31.s64 + 2608;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r10,128
	ctx.r10.s64 = 128;
	// stfs f0,3632(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 3632, temp.u32);
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v61,v62,v62
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_setzero_si128());
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826F9624:
	// stfs f0,512(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 512, temp.u32);
	// stw r8,-512(r11)
	PPC_STORE_U32(r11.u32 + -512, ctx.r8.u32);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bne 0x826f9624
	if (!cr0.eq) goto loc_826F9624;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82761e78
	ctx.lr = 0x826F9650;
	sub_82761E78(ctx, base);
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

__attribute__((alias("__imp__sub_826F9668"))) PPC_WEAK_FUNC(sub_826F9668);
PPC_FUNC_IMPL(__imp__sub_826F9668) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r7,r3,32
	ctx.r7.s64 = ctx.r3.s64 + 32;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// stw r8,3636(r3)
	PPC_STORE_U32(ctx.r3.u32 + 3636, ctx.r8.u32);
	// addi r11,r3,2608
	r11.s64 = ctx.r3.s64 + 2608;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r10,128
	ctx.r10.s64 = 128;
	// stfs f0,3632(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 3632, temp.u32);
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v61,v62,v62
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_setzero_si128());
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826F969C:
	// stfs f0,512(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 512, temp.u32);
	// stw r8,-512(r11)
	PPC_STORE_U32(r11.u32 + -512, ctx.r8.u32);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bne 0x826f969c
	if (!cr0.eq) goto loc_826F969C;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826F96C0"))) PPC_WEAK_FUNC(sub_826F96C0);
PPC_FUNC_IMPL(__imp__sub_826F96C0) {
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
	PPCRegister f31{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x826F96C8;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r26,-32114
	r26.s64 = -2104623104;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r11,-23636(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -23636);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826f97e4
	if (cr6.eq) goto loc_826F97E4;
	// lbz r11,36(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 36);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826f97e4
	if (cr6.eq) goto loc_826F97E4;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,12064
	ctx.r9.s64 = r11.s64 + 12064;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// addi r30,r27,48
	r30.s64 = r27.s64 + 48;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82761878
	ctx.lr = 0x826F9724;
	sub_82761878(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r6,256
	ctx.r6.s64 = 256;
	// addi r5,r8,-30128
	ctx.r5.s64 = ctx.r8.s64 + -30128;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r5,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x826f9774
	if (cr6.eq) goto loc_826F9774;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f2,31016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826fc258
	ctx.lr = 0x826F9764;
	sub_826FC258(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826f9778
	if (!cr6.eq) goto loc_826F9778;
loc_826F9774:
	// li r4,0
	ctx.r4.s64 = 0;
loc_826F9778:
	// addi r28,r31,272
	r28.s64 = r31.s64 + 272;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8254ab60
	ctx.lr = 0x826F9784;
	sub_8254AB60(ctx, base);
	// li r11,32
	r11.s64 = 32;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v61,r27,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// vsubfp128 v60,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,240
	ctx.r4.s64 = r31.s64 + 240;
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82760fc8
	ctx.lr = 0x826F97BC;
	sub_82760FC8(ctx, base);
	// lwz r3,-23636(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -23636);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826F97D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_826F97E4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826F97F4"))) PPC_WEAK_FUNC(sub_826F97F4);
PPC_FUNC_IMPL(__imp__sub_826F97F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826F97F8"))) PPC_WEAK_FUNC(sub_826F97F8);
PPC_FUNC_IMPL(__imp__sub_826F97F8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x826F9800;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r11,-23636(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23636);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826f99fc
	if (cr6.eq) goto loc_826F99FC;
	// lbz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 36);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826f99fc
	if (cr6.eq) goto loc_826F99FC;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826f99fc
	if (cr6.eq) goto loc_826F99FC;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826f99fc
	if (cr6.eq) goto loc_826F99FC;
	// lfs f0,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	f0.f64 = double(temp.f32);
	// li r26,0
	r26.s64 = 0;
	// lfs f13,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,32(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// stfs f0,40(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stfs f31,44(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// lwz r11,656(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826f988c
	if (cr6.eq) goto loc_826F988C;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// b 0x826f9894
	goto loc_826F9894;
loc_826F988C:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
loc_826F9894:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r28,0(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82761e50
	ctx.lr = 0x826F98A0;
	sub_82761E50(ctx, base);
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827644f8
	ctx.lr = 0x826F98BC;
	sub_827644F8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r26,3636(r31)
	PPC_STORE_U32(r31.u32 + 3636, r26.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,3632(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 3632, temp.u32);
	// bl 0x82761f20
	ctx.lr = 0x826F98D4;
	sub_82761F20(ctx, base);
	// lwz r29,80(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r27,r26
	r27.u64 = r26.u64;
loc_826F98DC:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// bne cr6,0x826f98f0
	if (!cr6.eq) goto loc_826F98F0;
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x826f9904
	goto loc_826F9904;
loc_826F98F0:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r9,r27,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// li r11,1
	r11.s64 = 1;
	// lwzx r29,r9,r10
	r29.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_826F9904:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826f99e4
	if (cr6.eq) goto loc_826F99E4;
	// lwz r11,3636(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3636);
	// clrlwi r30,r29,20
	r30.u64 = r29.u32 & 0xFFF;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r9,r11,3
	ctx.r9.s64 = r11.s64 + 3;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r8,100(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	// add r5,r11,r31
	ctx.r5.u64 = r11.u64 + r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826F993C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,48(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// rlwinm r7,r29,22,15,29
	ctx.r7.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 22) & 0x1FFFC;
	// lwzx r10,r7,r6
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lhz r9,80(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 80);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826f997c
	if (cr6.eq) goto loc_826F997C;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwzx r8,r8,r9
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x826f9984
	if (!cr6.eq) goto loc_826F9984;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// b 0x826f9984
	goto loc_826F9984;
loc_826F997C:
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
loc_826F9984:
	// lwz r11,3636(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3636);
	// mulli r9,r30,28
	ctx.r9.s64 = r30.s64 * 28;
	// lwz r8,16(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// addi r7,r11,780
	ctx.r7.s64 = r11.s64 + 780;
	// add r11,r8,r9
	r11.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfsx f0,r6,r31
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + r31.u32, temp.u32);
	// lwz r9,3636(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3636);
	// lfs f13,3632(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 3632);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r9,652
	ctx.r5.s64 = ctx.r9.s64 + 652;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,3632(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 3632, temp.u32);
	// stwx r11,r4,r31
	PPC_STORE_U32(ctx.r4.u32 + r31.u32, r11.u32);
	// lwz r11,3636(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3636);
	// addi r3,r11,524
	ctx.r3.s64 = r11.s64 + 524;
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, ctx.r10.u32);
	// lwz r11,3636(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3636);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,3636(r31)
	PPC_STORE_U32(r31.u32 + 3636, r11.u32);
	// cmpwi cr6,r11,128
	cr6.compare<int32_t>(r11.s32, 128, xer);
	// bne cr6,0x826f98dc
	if (!cr6.eq) goto loc_826F98DC;
loc_826F99E4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82761e68
	ctx.lr = 0x826F99EC;
	sub_82761E68(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_826F99FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826F9A0C"))) PPC_WEAK_FUNC(sub_826F9A0C);
PPC_FUNC_IMPL(__imp__sub_826F9A0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826F9A10"))) PPC_WEAK_FUNC(sub_826F9A10);
PPC_FUNC_IMPL(__imp__sub_826F9A10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// addi r11,r8,524
	r11.s64 = ctx.r8.s64 + 524;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f30,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f30.f64 = double(temp.f32);
	// lwzx r11,r10,r9
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// fmr f31,f30
	f31.f64 = f30.f64;
	// addi r5,r11,16
	ctx.r5.s64 = r11.s64 + 16;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lhz r11,80(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 80);
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x826f9a88
	if (cr6.eq) goto loc_826F9A88;
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r7,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne cr6,0x826f9a94
	if (!cr6.eq) goto loc_826F9A94;
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// b 0x826f9a94
	goto loc_826F9A94;
loc_826F9A88:
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r7,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
loc_826F9A94:
	// addi r11,r8,652
	r11.s64 = ctx.r8.s64 + 652;
	// li r7,4
	ctx.r7.s64 = 4;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x8254fb60
	ctx.lr = 0x826F9AAC;
	sub_8254FB60(ctx, base);
	// addi r7,r3,-2
	ctx.r7.s64 = ctx.r3.s64 + -2;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x826f9b34
	if (!cr6.gt) goto loc_826F9B34;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826F9ACC:
	// addi r8,r10,16
	ctx.r8.s64 = ctx.r10.s64 + 16;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v59,v60,v63
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// vpermwi128 v58,v61,99
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x9C));
	// vpermwi128 v0,v61,135
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x78));
	// vpermwi128 v57,v59,135
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0x78));
	// vpermwi128 v13,v59,99
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0x9C));
	// vmulfp128 v12,v57,v58
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v58.f32)));
	// vnmsubfp v11,v13,v0,v12
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v11,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// fmadds f11,f0,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f10,f13,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fsqrts f9,f10
	ctx.f9.f64 = double(float(sqrt(ctx.f10.f64)));
	// stfs f9,0(r9)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// fadds f31,f9,f31
	f31.f64 = double(float(ctx.f9.f64 + f31.f64));
	// bne 0x826f9acc
	if (!cr0.eq) goto loc_826F9ACC;
loc_826F9B34:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// lfs f11,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// blt cr6,0x826f9b9c
	if (cr6.lt) goto loc_826F9B9C;
	// addi r10,r7,-4
	ctx.r10.s64 = ctx.r7.s64 + -4;
	// fdivs f0,f11,f31
	f0.f64 = double(float(ctx.f11.f64 / f31.f64));
	// addi r11,r1,100
	r11.s64 = ctx.r1.s64 + 100;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
loc_826F9B60:
	// lfs f13,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f9,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f0,f12
	ctx.f8.f64 = double(float(f0.f64 * ctx.f12.f64));
	// lfs f7,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f0,f9
	ctx.f6.f64 = double(float(f0.f64 * ctx.f9.f64));
	// fmuls f5,f7,f0
	ctx.f5.f64 = double(float(ctx.f7.f64 * f0.f64));
	// stfs f10,-4(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// stfs f8,0(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f6,4(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f5,8(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x826f9b60
	if (!cr0.eq) goto loc_826F9B60;
loc_826F9B9C:
	// cmpw cr6,r9,r7
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, xer);
	// bge cr6,0x826f9bd0
	if (!cr6.lt) goto loc_826F9BD0;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// fdivs f0,f11,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f11.f64 / f31.f64));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// subf r10,r9,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r9.s64;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
loc_826F9BB8:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x826f9bb8
	if (!cr0.eq) goto loc_826F9BB8;
loc_826F9BD0:
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
	// lis r5,23772
	ctx.r5.s64 = 1557921792;
	// addi r4,r6,2192
	ctx.r4.s64 = ctx.r6.s64 + 2192;
	// ori r11,r5,64167
	r11.u64 = ctx.r5.u64 | 64167;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lwz r30,2192(r6)
	r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + 2192);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// mulld r10,r30,r8
	ctx.r10.s64 = r30.s64 * ctx.r8.s64;
	// lfs f12,14348(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14348);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// rldicl r8,r11,32,32
	ctx.r8.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// mulld r10,r10,r5
	ctx.r10.s64 = ctx.r10.s64 * ctx.r5.s64;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// clrlwi r8,r11,9
	ctx.r8.u64 = r11.u32 & 0x7FFFFF;
	// clrlwi r5,r10,9
	ctx.r5.u64 = ctx.r10.u32 & 0x7FFFFF;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f13
	ctx.f9.f64 = double(ctx.f13.s64);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// fcfid f8,f10
	ctx.f8.f64 = double(ctx.f10.s64);
	// rldicl r10,r10,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// stw r11,2192(r6)
	PPC_STORE_U32(ctx.r6.u32 + 2192, r11.u32);
	// stw r10,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// fmuls f13,f7,f12
	ctx.f13.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// fmuls f12,f6,f12
	ctx.f12.f64 = double(float(ctx.f6.f64 * ctx.f12.f64));
	// blt cr6,0x826f9cb8
	if (cr6.lt) goto loc_826F9CB8;
	// addi r11,r1,100
	r11.s64 = ctx.r1.s64 + 100;
loc_826F9C64:
	// lfs f10,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f10.f64 = double(temp.f32);
	// fadds f0,f10,f0
	f0.f64 = double(float(ctx.f10.f64 + f0.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x826f9d04
	if (!cr6.lt) goto loc_826F9D04;
	// lfs f10,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fadds f0,f10,f0
	f0.f64 = double(float(ctx.f10.f64 + f0.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x826f9cf0
	if (!cr6.lt) goto loc_826F9CF0;
	// lfs f10,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fadds f0,f10,f0
	f0.f64 = double(float(ctx.f10.f64 + f0.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x826f9cf8
	if (!cr6.lt) goto loc_826F9CF8;
	// lfs f10,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fadds f0,f10,f0
	f0.f64 = double(float(ctx.f10.f64 + f0.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x826f9d00
	if (!cr6.lt) goto loc_826F9D00;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r10,r7,-3
	ctx.r10.s64 = ctx.r7.s64 + -3;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x826f9c64
	if (cr6.lt) goto loc_826F9C64;
loc_826F9CB8:
	// cmpw cr6,r9,r7
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, xer);
	// bge cr6,0x826f9d04
	if (!cr6.lt) goto loc_826F9D04;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
loc_826F9CCC:
	// lfs f10,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fadds f0,f10,f0
	f0.f64 = double(float(ctx.f10.f64 + f0.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x826f9d04
	if (!cr6.lt) goto loc_826F9D04;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r9,r7
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, xer);
	// blt cr6,0x826f9ccc
	if (cr6.lt) goto loc_826F9CCC;
	// b 0x826f9d04
	goto loc_826F9D04;
loc_826F9CF0:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// b 0x826f9d04
	goto loc_826F9D04;
loc_826F9CF8:
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// b 0x826f9d04
	goto loc_826F9D04;
loc_826F9D00:
	// addi r9,r9,3
	ctx.r9.s64 = ctx.r9.s64 + 3;
loc_826F9D04:
	// fsubs f0,f13,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f13.f64 - f0.f64));
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// fsqrts f13,f12
	ctx.f13.f64 = double(float(sqrt(ctx.f12.f64)));
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f12,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lfs f10,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f10.f64 = double(temp.f32);
	// addi r7,r1,132
	ctx.r7.s64 = ctx.r1.s64 + 132;
	// lfs f9,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f9.f64 = double(temp.f32);
	// addi r6,r1,136
	ctx.r6.s64 = ctx.r1.s64 + 136;
	// lfsx f8,r11,r10
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	ctx.f8.f64 = double(temp.f32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,148
	ctx.r4.s64 = ctx.r1.s64 + 148;
	// lfsx f7,r9,r8
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	ctx.f7.f64 = double(temp.f32);
	// addi r11,r1,152
	r11.s64 = ctx.r1.s64 + 152;
	// lfsx f6,r9,r7
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	ctx.f6.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfsx f5,r9,r6
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	ctx.f5.f64 = double(temp.f32);
	// lfsx f4,r9,r5
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r5.u32);
	ctx.f4.f64 = double(temp.f32);
	// lfsx f3,r9,r4
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r4.u32);
	ctx.f3.f64 = double(temp.f32);
	// lfsx f2,r9,r11
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	ctx.f2.f64 = double(temp.f32);
	// fadds f1,f0,f8
	ctx.f1.f64 = double(float(f0.f64 + ctx.f8.f64));
	// fsubs f0,f11,f13
	f0.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// fdivs f8,f1,f8
	ctx.f8.f64 = double(float(ctx.f1.f64 / ctx.f8.f64));
	// fsubs f1,f11,f8
	ctx.f1.f64 = double(float(ctx.f11.f64 - ctx.f8.f64));
	// fmuls f11,f13,f8
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f8.f64));
	// fmuls f8,f1,f13
	ctx.f8.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
	// fmuls f7,f7,f8
	ctx.f7.f64 = double(float(ctx.f7.f64 * ctx.f8.f64));
	// fmuls f6,f6,f8
	ctx.f6.f64 = double(float(ctx.f6.f64 * ctx.f8.f64));
	// fmuls f5,f5,f8
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f8.f64));
	// fmadds f4,f4,f11,f7
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f11.f64 + ctx.f7.f64));
	// fmadds f3,f3,f11,f6
	ctx.f3.f64 = double(float(ctx.f3.f64 * ctx.f11.f64 + ctx.f6.f64));
	// fmadds f2,f2,f11,f5
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f11.f64 + ctx.f5.f64));
	// fmadds f1,f12,f0,f4
	ctx.f1.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f4.f64));
	// stfs f1,0(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// fmadds f13,f10,f0,f3
	ctx.f13.f64 = double(float(ctx.f10.f64 * f0.f64 + ctx.f3.f64));
	// stfs f13,4(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// fmadds f12,f9,f0,f2
	ctx.f12.f64 = double(float(ctx.f9.f64 * f0.f64 + ctx.f2.f64));
	// stfs f12,8(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
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

__attribute__((alias("__imp__sub_826F9DC4"))) PPC_WEAK_FUNC(sub_826F9DC4);
PPC_FUNC_IMPL(__imp__sub_826F9DC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826F9DC8"))) PPC_WEAK_FUNC(sub_826F9DC8);
PPC_FUNC_IMPL(__imp__sub_826F9DC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826F9DD0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8259caa8
	ctx.lr = 0x826F9DDC;
	sub_8259CAA8(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r29,r31,676
	r29.s64 = r31.s64 + 676;
	// addi r10,r11,16660
	ctx.r10.s64 = r11.s64 + 16660;
	// li r30,5
	r30.s64 = 5;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_826F9DF0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826fb9d8
	ctx.lr = 0x826F9DF8;
	sub_826FB9D8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,24
	r29.s64 = r29.s64 + 24;
	// bge 0x826f9df0
	if (!cr0.lt) goto loc_826F9DF0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,820
	ctx.r3.s64 = r31.s64 + 820;
	// bl 0x82595360
	ctx.lr = 0x826F9E10;
	sub_82595360(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,672(r31)
	PPC_STORE_U32(r31.u32 + 672, r11.u32);
	// stw r11,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r11.u32);
	// stw r11,868(r31)
	PPC_STORE_U32(r31.u32 + 868, r11.u32);
	// stw r11,872(r31)
	PPC_STORE_U32(r31.u32 + 872, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826F9E30"))) PPC_WEAK_FUNC(sub_826F9E30);
PPC_FUNC_IMPL(__imp__sub_826F9E30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// addi r9,r11,16660
	ctx.r9.s64 = r11.s64 + 16660;
	// addi r8,r10,1828
	ctx.r8.s64 = ctx.r10.s64 + 1828;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r8,820(r3)
	PPC_STORE_U32(ctx.r3.u32 + 820, ctx.r8.u32);
	// b 0x8259bc10
	sub_8259BC10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826F9E4C"))) PPC_WEAK_FUNC(sub_826F9E4C);
PPC_FUNC_IMPL(__imp__sub_826F9E4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826F9E50"))) PPC_WEAK_FUNC(sub_826F9E50);
PPC_FUNC_IMPL(__imp__sub_826F9E50) {
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
	ctx.lr = 0x826F9E58;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,672(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 672);
	// lwz r10,448(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 448);
	// lwz r9,120(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 120);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x826f9ea0
	if (!cr6.gt) goto loc_826F9EA0;
	// addi r31,r29,676
	r31.s64 = r29.s64 + 676;
loc_826F9E7C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fba38
	ctx.lr = 0x826F9E84;
	sub_826FBA38(ctx, base);
	// lwz r11,672(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 672);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,24
	r31.s64 = r31.s64 + 24;
	// lwz r10,448(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 448);
	// lwz r9,120(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 120);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// blt cr6,0x826f9e7c
	if (cr6.lt) goto loc_826F9E7C;
loc_826F9EA0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826F9EA8"))) PPC_WEAK_FUNC(sub_826F9EA8);
PPC_FUNC_IMPL(__imp__sub_826F9EA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,864(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// ble cr6,0x826f9f90
	if (!cr6.gt) goto loc_826F9F90;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lwz r10,672(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// vspltisw128 v61,-1
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r11,2256
	ctx.r7.s64 = r11.s64 + 2256;
	// addi r6,r9,2384
	ctx.r6.s64 = ctx.r9.s64 + 2384;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,208
	ctx.r4.s64 = 208;
	// lfs f0,8884(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8884);
	f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vand128 v60,v62,v63
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvlx128 v59,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v58,v59,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// vaddfp128 v57,v60,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_add_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v58.f32)));
	// lvx128 v56,r10,r4
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v55,v60,v58
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v58.f32)));
	// vand128 v54,v56,v63
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpgefp128 v53,v57,v54
	simde_mm_store_ps(v53.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v54.f32)));
	// vcmpgefp128 v52,v54,v55
	simde_mm_store_ps(v52.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v55.f32)));
	// vand128 v51,v52,v53
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)v53.u8)));
	// vcmpequw128. v50,v51,v61
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	cr6.setFromMask(simde_mm_load_ps(v50.f32), 0xF);
	// mfocrf r3,2
	ctx.r3.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r11,r3,0,24,24
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826f9f90
	if (cr6.eq) goto loc_826F9F90;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826f9e50
	ctx.lr = 0x826F9F40;
	sub_826F9E50(ctx, base);
	// lwz r10,672(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lbz r11,500(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 500);
	// rlwinm r9,r11,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826f9f74
	if (cr6.eq) goto loc_826F9F74;
	// lwz r11,52(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826f9f74
	if (cr6.eq) goto loc_826F9F74;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826f9f74
	if (cr6.eq) goto loc_826F9F74;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// b 0x826f9f78
	goto loc_826F9F78;
loc_826F9F74:
	// addi r11,r10,112
	r11.s64 = ctx.r10.s64 + 112;
loc_826F9F78:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lhz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// lwz r3,-2288(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -2288);
	// bl 0x82588d90
	ctx.lr = 0x826F9F88;
	sub_82588D90(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,864(r31)
	PPC_STORE_U32(r31.u32 + 864, ctx.r9.u32);
loc_826F9F90:
	// lwz r11,864(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r11.u32);
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

__attribute__((alias("__imp__sub_826F9FB0"))) PPC_WEAK_FUNC(sub_826F9FB0);
PPC_FUNC_IMPL(__imp__sub_826F9FB0) {
	PPC_FUNC_PROLOGUE();
	// b 0x8259d7f0
	sub_8259D7F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826F9FB4"))) PPC_WEAK_FUNC(sub_826F9FB4);
PPC_FUNC_IMPL(__imp__sub_826F9FB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826F9FB8"))) PPC_WEAK_FUNC(sub_826F9FB8);
PPC_FUNC_IMPL(__imp__sub_826F9FB8) {
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
	ctx.lr = 0x826F9FC0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r30,r31,820
	r30.s64 = r31.s64 + 820;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r28,672(r31)
	PPC_STORE_U32(r31.u32 + 672, r28.u32);
	// bl 0x825952e0
	ctx.lr = 0x826F9FE0;
	sub_825952E0(ctx, base);
	// lbz r11,500(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 500);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fa010
	if (cr6.eq) goto loc_826FA010;
	// lwz r11,52(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fa010
	if (cr6.eq) goto loc_826FA010;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826fa010
	if (cr6.eq) goto loc_826FA010;
	// lwz r4,28(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// b 0x826fa014
	goto loc_826FA014;
loc_826FA010:
	// addi r4,r28,112
	ctx.r4.s64 = r28.s64 + 112;
loc_826FA014:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8259f2c0
	ctx.lr = 0x826FA020;
	sub_8259F2C0(ctx, base);
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// li r27,0
	r27.s64 = 0;
	// mr r30,r27
	r30.u64 = r27.u64;
	// lwz r10,448(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 448);
	// lwz r9,120(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 120);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x826fa06c
	if (!cr6.gt) goto loc_826FA06C;
	// addi r29,r31,676
	r29.s64 = r31.s64 + 676;
loc_826FA040:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826fba08
	ctx.lr = 0x826FA050;
	sub_826FBA08(ctx, base);
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,24
	r29.s64 = r29.s64 + 24;
	// lwz r10,448(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 448);
	// lwz r9,120(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 120);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// blt cr6,0x826fa040
	if (cr6.lt) goto loc_826FA040;
loc_826FA06C:
	// stw r27,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r27.u32);
	// stw r27,868(r31)
	PPC_STORE_U32(r31.u32 + 868, r27.u32);
	// stw r27,872(r31)
	PPC_STORE_U32(r31.u32 + 872, r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826FA080"))) PPC_WEAK_FUNC(sub_826FA080);
PPC_FUNC_IMPL(__imp__sub_826FA080) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,672(r3)
	PPC_STORE_U32(ctx.r3.u32 + 672, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FA08C"))) PPC_WEAK_FUNC(sub_826FA08C);
PPC_FUNC_IMPL(__imp__sub_826FA08C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FA090"))) PPC_WEAK_FUNC(sub_826FA090);
PPC_FUNC_IMPL(__imp__sub_826FA090) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32248
	ctx.r10.s64 = -2113404928;
	// addi r9,r11,16660
	ctx.r9.s64 = r11.s64 + 16660;
	// addi r8,r10,1828
	ctx.r8.s64 = ctx.r10.s64 + 1828;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r8,820(r31)
	PPC_STORE_U32(r31.u32 + 820, ctx.r8.u32);
	// bl 0x8259bc10
	ctx.lr = 0x826FA0C8;
	sub_8259BC10(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x826fa0e0
	if (cr6.eq) goto loc_826FA0E0;
	// bl 0x82130588
	ctx.lr = 0x826FA0DC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826FA0E0:
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

__attribute__((alias("__imp__sub_826FA0F8"))) PPC_WEAK_FUNC(sub_826FA0F8);
PPC_FUNC_IMPL(__imp__sub_826FA0F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	// bl 0x823d91c8
	ctx.lr = 0x826FA100;
	// stfd f30,-152(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -152, f30.u64);
	// stfd f31,-144(r1)
	PPC_STORE_U64(ctx.r1.u32 + -144, f31.u64);
	// stwu r1,-656(r1)
	ea = -656 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r16,r3
	r16.u64 = ctx.r3.u64;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lwz r11,672(r16)
	r11.u64 = PPC_LOAD_U32(r16.u32 + 672);
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r3,448(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 448);
	// beq cr6,0x826fa144
	if (cr6.eq) goto loc_826FA144;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lwz r10,22080(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 22080);
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// rlwinm r10,r9,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// b 0x826fa17c
	goto loc_826FA17C;
loc_826FA144:
	// lbz r10,500(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 500);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826fa174
	if (cr6.eq) goto loc_826FA174;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fa174
	if (cr6.eq) goto loc_826FA174;
	// lwz r10,48(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826fa174
	if (cr6.eq) goto loc_826FA174;
	// lwz r11,28(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// b 0x826fa178
	goto loc_826FA178;
loc_826FA174:
	// addi r11,r11,112
	r11.s64 = r11.s64 + 112;
loc_826FA178:
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
loc_826FA17C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r6,r1,304
	ctx.r6.s64 = ctx.r1.s64 + 304;
	// lfs f31,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x826e5540
	ctx.lr = 0x826FA190;
	sub_826E5540(ctx, base);
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// lwz r3,672(r16)
	ctx.r3.u64 = PPC_LOAD_U32(r16.u32 + 672);
	// bl 0x826e94e8
	ctx.lr = 0x826FA19C;
	sub_826E94E8(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r31,0
	r31.s64 = 0;
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// lwz r11,-12640(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12640);
	// lbz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826fa1c8
	if (cr6.eq) goto loc_826FA1C8;
	// lbz r10,10(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x826fa1cc
	if (cr6.eq) goto loc_826FA1CC;
loc_826FA1C8:
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
loc_826FA1CC:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fa1e8
	if (cr6.eq) goto loc_826FA1E8;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x826fa1ec
	if (cr6.eq) goto loc_826FA1EC;
loc_826FA1E8:
	// mr r11,r31
	r11.u64 = r31.u64;
loc_826FA1EC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r25,r31
	r25.u64 = r31.u64;
	// cmpwi cr6,r18,0
	cr6.compare<int32_t>(r18.s32, 0, xer);
	// ble cr6,0x826fa390
	if (!cr6.gt) goto loc_826FA390;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// clrlwi r20,r11,24
	r20.u64 = r11.u32 & 0xFF;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f30,-31324(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -31324);
	f30.f64 = double(temp.f32);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lfs f31,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r30,r1,304
	r30.s64 = ctx.r1.s64 + 304;
	// addi r26,r16,676
	r26.s64 = r16.s64 + 676;
	// ori r28,r6,65535
	r28.u64 = ctx.r6.u64 | 65535;
	// li r21,2048
	r21.s64 = 2048;
	// li r22,4
	r22.s64 = 4;
	// addi r19,r11,29952
	r19.s64 = r11.s64 + 29952;
	// addi r23,r10,3864
	r23.s64 = ctx.r10.s64 + 3864;
	// addi r27,r9,2256
	r27.s64 = ctx.r9.s64 + 2256;
	// addi r24,r8,11196
	r24.s64 = ctx.r8.s64 + 11196;
loc_826FA24C:
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r27
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// addi r29,r30,16
	r29.s64 = r30.s64 + 16;
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
	// stfs f31,256(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// lvx128 v61,r0,r29
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// stfs f31,260(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stw r24,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r24.u32);
	// stw r31,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r31.u32);
	// sth r28,268(r1)
	PPC_STORE_U16(ctx.r1.u32 + 268, r28.u16);
	// sth r31,270(r1)
	PPC_STORE_U16(ctx.r1.u32 + 270, r31.u16);
	// stb r31,272(r1)
	PPC_STORE_U8(ctx.r1.u32 + 272, r31.u8);
	// sth r31,274(r1)
	PPC_STORE_U16(ctx.r1.u32 + 274, r31.u16);
	// stw r31,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, r31.u32);
	// stw r21,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r21.u32);
	// stb r22,120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 120, r22.u8);
	// bl 0x827974f0
	ctx.lr = 0x826FA2CC;
	sub_827974F0(ctx, base);
	// lvx128 v58,r0,r29
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r30
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// vaddfp128 v56,v57,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v58.f32)));
	// addi r5,r1,288
	ctx.r5.s64 = ctx.r1.s64 + 288;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// lvlx128 v60,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vmulfp128 v55,v56,v59
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v59.f32)));
	// stvx128 v55,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x826fa300
	if (cr6.eq) goto loc_826FA300;
	// fmr f1,f31
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.f64 = f31.f64;
	// b 0x826fa304
	goto loc_826FA304;
loc_826FA300:
	// lfs f1,8(r19)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r19.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
loc_826FA304:
	// lfs f0,228(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// bge cr6,0x826fa350
	if (!cr6.lt) goto loc_826FA350;
	// addi r11,r1,208
	r11.s64 = ctx.r1.s64 + 208;
	// lvx128 v63,r0,r27
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// stw r31,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r31.u32);
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,256(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,260(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r28,268(r1)
	PPC_STORE_U16(ctx.r1.u32 + 268, r28.u16);
	// sth r31,270(r1)
	PPC_STORE_U16(ctx.r1.u32 + 270, r31.u16);
	// stb r31,272(r1)
	PPC_STORE_U8(ctx.r1.u32 + 272, r31.u8);
	// sth r31,274(r1)
	PPC_STORE_U16(ctx.r1.u32 + 274, r31.u16);
	// stw r31,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, r31.u32);
loc_826FA350:
	// cmpwi cr6,r25,1
	cr6.compare<int32_t>(r25.s32, 1, xer);
	// li r8,1
	ctx.r8.s64 = 1;
	// ble cr6,0x826fa360
	if (!cr6.gt) goto loc_826FA360;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
loc_826FA360:
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r7,r1,288
	ctx.r7.s64 = ctx.r1.s64 + 288;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826fba60
	ctx.lr = 0x826FA378;
	sub_826FBA60(ctx, base);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// stw r23,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r23.u32);
	// addi r30,r30,32
	r30.s64 = r30.s64 + 32;
	// addi r26,r26,24
	r26.s64 = r26.s64 + 24;
	// cmpw cr6,r25,r18
	cr6.compare<int32_t>(r25.s32, r18.s32, xer);
	// blt cr6,0x826fa24c
	if (cr6.lt) goto loc_826FA24C;
loc_826FA390:
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x8259e920
	ctx.lr = 0x826FA398;
	sub_8259E920(ctx, base);
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// lfd f30,-152(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -152);
	// lfd f31,-144(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_826FA3A8"))) PPC_WEAK_FUNC(sub_826FA3A8);
PPC_FUNC_IMPL(__imp__sub_826FA3A8) {
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
	// bl 0x82595558
	ctx.lr = 0x826FA3C0;
	sub_82595558(ctx, base);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r9,r11,2256
	ctx.r9.s64 = r11.s64 + 2256;
	// li r8,80
	ctx.r8.s64 = 80;
	// addi r7,r10,17172
	ctx.r7.s64 = ctx.r10.s64 + 17172;
	// li r6,96
	ctx.r6.s64 = 96;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r5,112
	ctx.r5.s64 = 112;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,0
	r11.s64 = 0;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r3,140(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 140);
	// clrlwi r10,r3,26
	ctx.r10.u64 = ctx.r3.u32 & 0x3F;
	// lfs f0,3796(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,132(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r10,140(r31)
	PPC_STORE_U8(r31.u32 + 140, ctx.r10.u8);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826FA434"))) PPC_WEAK_FUNC(sub_826FA434);
PPC_FUNC_IMPL(__imp__sub_826FA434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FA438"))) PPC_WEAK_FUNC(sub_826FA438);
PPC_FUNC_IMPL(__imp__sub_826FA438) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// li r11,96
	r11.s64 = 96;
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FA448"))) PPC_WEAK_FUNC(sub_826FA448);
PPC_FUNC_IMPL(__imp__sub_826FA448) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r10,r11,17172
	ctx.r10.s64 = r11.s64 + 17172;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// b 0x82595608
	sub_82595608(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826FA458"))) PPC_WEAK_FUNC(sub_826FA458);
PPC_FUNC_IMPL(__imp__sub_826FA458) {
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
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FA480;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826FA494;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_826FA4AC"))) PPC_WEAK_FUNC(sub_826FA4AC);
PPC_FUNC_IMPL(__imp__sub_826FA4AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FA4B0"))) PPC_WEAK_FUNC(sub_826FA4B0);
PPC_FUNC_IMPL(__imp__sub_826FA4B0) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,17172
	ctx.r10.s64 = r11.s64 + 17172;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82595608
	ctx.lr = 0x826FA4DC;
	sub_82595608(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826fa4f4
	if (cr6.eq) goto loc_826FA4F4;
	// bl 0x82130588
	ctx.lr = 0x826FA4F0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826FA4F4:
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

__attribute__((alias("__imp__sub_826FA50C"))) PPC_WEAK_FUNC(sub_826FA50C);
PPC_FUNC_IMPL(__imp__sub_826FA50C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FA510"))) PPC_WEAK_FUNC(sub_826FA510);
PPC_FUNC_IMPL(__imp__sub_826FA510) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f1,44(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 44, temp.u32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// blelr cr6
	if (!cr6.gt) return;
	// addi r10,r1,44
	ctx.r10.s64 = ctx.r1.s64 + 44;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// addi r11,r3,96
	r11.s64 = ctx.r3.s64 + 96;
	// addi r7,r9,-31664
	ctx.r7.s64 = ctx.r9.s64 + -31664;
	// li r8,112
	ctx.r8.s64 = 112;
	// lvlx128 v60,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrefp128 v0,v59
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v59.f32)));
	// vor128 v12,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v57,v61,v61
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// lvx128 v13,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v10,v0,v12,v13
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v9,v0,v10,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v56,v57,v9
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(ctx.v9.f32)));
	// vor128 v55,v56,v56
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// stvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v54,v55,v58
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v58.f32)));
	// stvx128 v54,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FA584"))) PPC_WEAK_FUNC(sub_826FA584);
PPC_FUNC_IMPL(__imp__sub_826FA584) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FA588"))) PPC_WEAK_FUNC(sub_826FA588);
PPC_FUNC_IMPL(__imp__sub_826FA588) {
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
	ctx.lr = 0x826FA590;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x825953b0
	ctx.lr = 0x826FA5AC;
	sub_825953B0(ctx, base);
	// lbz r10,140(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 140);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r28,48
	r28.s64 = 48;
	// rlwimi r10,r29,7,17,24
	ctx.r10.u64 = (__builtin_rotateleft32(r29.u32, 7) & 0x7F80) | (ctx.r10.u64 & 0xFFFFFFFFFFFF807F);
	// stb r10,140(r31)
	PPC_STORE_U8(r31.u32 + 140, ctx.r10.u8);
	// lbz r8,500(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 500);
	// rlwinm r7,r8,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x826fa66c
	if (!cr6.eq) goto loc_826FA66C;
	// lwz r11,448(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 448);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r10,-31280
	ctx.r5.s64 = ctx.r10.s64 + -31280;
	// lwz r4,104(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// bl 0x82595660
	ctx.lr = 0x826FA5E8;
	sub_82595660(ctx, base);
	// lis r29,-32112
	r29.s64 = -2104492032;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-2288(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -2288);
	// bl 0x8258b598
	ctx.lr = 0x826FA5F8;
	sub_8258B598(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,-2288(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -2288);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82588990
	ctx.lr = 0x826FA60C;
	sub_82588990(ctx, base);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r27,r9,-19300
	r27.s64 = ctx.r9.s64 + -19300;
	// addi r26,r8,-108
	r26.s64 = ctx.r8.s64 + -108;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,100(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 100);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826FA630;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x826FA644;
	sub_823DEDD8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826fa698
	if (cr6.eq) goto loc_826FA698;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r31,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r31.u32);
	// lwz r3,-2288(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -2288);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// bl 0x825882f0
	ctx.lr = 0x826FA668;
	sub_825882F0(ctx, base);
	// b 0x826fa698
	goto loc_826FA698;
loc_826FA66C:
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,16
	ctx.r9.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r30,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r30,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r30,r28
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826FA698:
	// vspltisw128 v59,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_set1_epi32(int(0x0)));
	// li r11,80
	r11.s64 = 80;
	// li r10,96
	ctx.r10.s64 = 96;
	// lvx128 v58,r30,r28
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,112
	ctx.r9.s64 = 112;
	// stvx128 v58,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826FA6C0"))) PPC_WEAK_FUNC(sub_826FA6C0);
PPC_FUNC_IMPL(__imp__sub_826FA6C0) {
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
	ctx.lr = 0x826FA6C8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,128(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// lbz r10,500(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 500);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826fa754
	if (!cr6.eq) goto loc_826FA754;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r31,r11,-19300
	r31.s64 = r11.s64 + -19300;
	// addi r29,r10,-108
	r29.s64 = ctx.r10.s64 + -108;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,100(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 100);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826FA708;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x826FA71C;
	sub_823DEDD8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lis r31,-32112
	r31.s64 = -2104492032;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826fa734
	if (cr6.eq) goto loc_826FA734;
	// lwz r3,-2288(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -2288);
	// bl 0x82588338
	ctx.lr = 0x826FA734;
	sub_82588338(ctx, base);
loc_826FA734:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-2288(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -2288);
	// lhz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// bl 0x8258b6c8
	ctx.lr = 0x826FA744;
	sub_8258B6C8(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82595580
	ctx.lr = 0x826FA754;
	sub_82595580(ctx, base);
loc_826FA754:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826FA75C"))) PPC_WEAK_FUNC(sub_826FA75C);
PPC_FUNC_IMPL(__imp__sub_826FA75C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FA760"))) PPC_WEAK_FUNC(sub_826FA760);
PPC_FUNC_IMPL(__imp__sub_826FA760) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
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
	// bl 0x823d91fc
	ctx.lr = 0x826FA768;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r11,64
	r11.s64 = 64;
	// li r9,80
	ctx.r9.s64 = 80;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r10,128(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// lvx128 v63,r30,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r30,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r8,500(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 500);
	// rlwinm r7,r8,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x826fa7d0
	if (cr6.eq) goto loc_826FA7D0;
	// addi r11,r30,16
	r11.s64 = r30.s64 + 16;
	// lvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,16
	ctx.r8.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r10,48
	ctx.r10.s64 = 48;
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r31,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r31,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r31,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826FA7D0:
	// lbz r11,140(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 140);
	// lis r29,-32112
	r29.s64 = -2104492032;
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fa7f0
	if (cr6.eq) goto loc_826FA7F0;
	// lwz r3,-2288(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -2288);
	// lhz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// bl 0x825880d8
	ctx.lr = 0x826FA7F0;
	sub_825880D8(ctx, base);
loc_826FA7F0:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,-2288(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -2288);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82588990
	ctx.lr = 0x826FA804;
	sub_82588990(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826FA80C"))) PPC_WEAK_FUNC(sub_826FA80C);
PPC_FUNC_IMPL(__imp__sub_826FA80C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FA810"))) PPC_WEAK_FUNC(sub_826FA810);
PPC_FUNC_IMPL(__imp__sub_826FA810) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x826FA818;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r3,128(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FA838;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,128(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826FA84C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826fa89c
	if (cr6.eq) goto loc_826FA89C;
	// li r11,96
	r11.s64 = 96;
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r30,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,164(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 164);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826FA880;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,36(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826FA894;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r5,864(r31)
	PPC_STORE_U32(r31.u32 + 864, ctx.r5.u32);
loc_826FA89C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826FA8A8"))) PPC_WEAK_FUNC(sub_826FA8A8);
PPC_FUNC_IMPL(__imp__sub_826FA8A8) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826FA8B0;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,140(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 140);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fa980
	if (cr6.eq) goto loc_826FA980;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,132(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f0,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stfs f12,132(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// fcmpu cr6,f12,f31
	cr6.compare(ctx.f12.f64, f31.f64);
	// bgt cr6,0x826fa980
	if (cr6.gt) goto loc_826FA980;
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// addi r30,r11,8516
	r30.s64 = r11.s64 + 8516;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826FA914;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826FA930;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r6,r3,272
	ctx.r6.s64 = ctx.r3.s64 + 272;
	// addi r7,r29,288
	ctx.r7.s64 = r29.s64 + 288;
	// lwz r4,128(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// addi r5,r31,16
	ctx.r5.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826f01a8
	ctx.lr = 0x826FA948;
	sub_826F01A8(ctx, base);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwz r4,136(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// addic. r11,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	r11.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lfs f0,14884(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
	// stfs f0,132(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// bgt 0x826fa980
	if (cr0.gt) goto loc_826FA980;
	// lbz r11,140(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 140);
	// li r10,0
	ctx.r10.s64 = 0;
	// stfs f31,132(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r10,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r10.u32);
	// rlwinm r9,r9,0,26,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stb r9,140(r31)
	PPC_STORE_U8(r31.u32 + 140, ctx.r9.u8);
loc_826FA980:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826FA98C"))) PPC_WEAK_FUNC(sub_826FA98C);
PPC_FUNC_IMPL(__imp__sub_826FA98C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FA990"))) PPC_WEAK_FUNC(sub_826FA990);
PPC_FUNC_IMPL(__imp__sub_826FA990) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826FA998;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x826fa760
	ctx.lr = 0x826FA9A8;
	sub_826FA760(ctx, base);
	// lis r29,-32112
	r29.s64 = -2104492032;
	// lhz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r3,-2288(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -2288);
	// bl 0x8258d8b8
	ctx.lr = 0x826FA9C0;
	sub_8258D8B8(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,-2288(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -2288);
	// li r5,0
	ctx.r5.s64 = 0;
	// lhz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// bl 0x8258d3f8
	ctx.lr = 0x826FA9D4;
	sub_8258D3F8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826FA9DC"))) PPC_WEAK_FUNC(sub_826FA9DC);
PPC_FUNC_IMPL(__imp__sub_826FA9DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FA9E0"))) PPC_WEAK_FUNC(sub_826FA9E0);
PPC_FUNC_IMPL(__imp__sub_826FA9E0) {
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
	ctx.lr = 0x826FA9E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x826fa760
	ctx.lr = 0x826FA9FC;
	sub_826FA760(ctx, base);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FAA10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r8,164(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 164);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826FAA24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826FAA38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,172(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 172);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x826FAA4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r6,0
	ctx.r6.s64 = 0;
	// lhz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-2288(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -2288);
	// bl 0x8258d3f8
	ctx.lr = 0x826FAA64;
	sub_8258D3F8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826FAA6C"))) PPC_WEAK_FUNC(sub_826FAA6C);
PPC_FUNC_IMPL(__imp__sub_826FAA6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FAA70"))) PPC_WEAK_FUNC(sub_826FAA70);
PPC_FUNC_IMPL(__imp__sub_826FAA70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	// bl 0x823d91ec
	ctx.lr = 0x826FAA78;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,6
	ctx.r10.s64 = 393216;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// ori r9,r10,16948
	ctx.r9.u64 = ctx.r10.u64 | 16948;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826fac38
	if (cr6.eq) goto loc_826FAC38;
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x822a7c08
	ctx.lr = 0x826FAAD0;
	sub_822A7C08(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826fabe0
	if (!cr6.eq) goto loc_826FABE0;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// li r26,112
	r26.s64 = 112;
	// lvx128 v127,r0,r9
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r11,24092
	r28.s64 = r11.s64 + 24092;
	// addi r27,r10,24064
	r27.s64 = ctx.r10.s64 + 24064;
loc_826FAAFC:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lbz r7,165(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 165);
	// rlwinm r6,r7,0,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x826fabbc
	if (cr6.eq) goto loc_826FABBC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a7c28
	ctx.lr = 0x826FAB24;
	sub_822A7C28(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x826FAB38;
	sub_823DEDD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826fabbc
	if (cr6.eq) goto loc_826FABBC;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x826FAB4C;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fab84
	if (cr6.eq) goto loc_826FAB84;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x826FAB60;
	sub_822A39C8(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826fab84
	if (cr6.eq) goto loc_826FAB84;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x826FAB74;
	sub_822A39C8(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// bne cr6,0x826fabbc
	if (!cr6.eq) goto loc_826FABBC;
loc_826FAB84:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwzx r11,r9,r10
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r7,160(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 160);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cmplw cr6,r8,r6
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, xer);
	// bne cr6,0x826fabb0
	if (!cr6.eq) goto loc_826FABB0;
	// lvx128 v127,r11,r26
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826fabbc
	goto loc_826FABBC;
loc_826FABB0:
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v62,r11,r26
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v127,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
loc_826FABBC:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// bl 0x822a7c08
	ctx.lr = 0x826FABD0;
	sub_822A7C08(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826faafc
	if (cr6.eq) goto loc_826FAAFC;
	// b 0x826fabe8
	goto loc_826FABE8;
loc_826FABE0:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826FABE8:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r11,2384
	ctx.r10.s64 = r11.s64 + 2384;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v60,v127,v63
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
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
	// bne cr6,0x826fac38
	if (!cr6.eq) goto loc_826FAC38;
	// lbz r11,140(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 140);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826fac24
	if (!cr6.eq) goto loc_826FAC24;
	// stfs f31,132(r25)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r25.u32 + 132, temp.u32);
loc_826FAC24:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// li r10,3
	ctx.r10.s64 = 3;
	// ori r9,r11,64
	ctx.r9.u64 = r11.u64 | 64;
	// stw r10,136(r25)
	PPC_STORE_U32(r25.u32 + 136, ctx.r10.u32);
	// stb r9,140(r25)
	PPC_STORE_U8(r25.u32 + 140, ctx.r9.u8);
loc_826FAC38:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_826FAC4C"))) PPC_WEAK_FUNC(sub_826FAC4C);
PPC_FUNC_IMPL(__imp__sub_826FAC4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FAC50"))) PPC_WEAK_FUNC(sub_826FAC50);
PPC_FUNC_IMPL(__imp__sub_826FAC50) {
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
	ctx.lr = 0x826FAC58;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,128(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 128);
	// lwz r11,448(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 448);
	// lbz r10,111(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 111);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826fac84
	if (!cr6.eq) goto loc_826FAC84;
	// lbz r11,112(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fad94
	if (cr6.eq) goto loc_826FAD94;
loc_826FAC84:
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// bl 0x822a7c08
	ctx.lr = 0x826FAC94;
	sub_822A7C08(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826fad94
	if (!cr6.eq) goto loc_826FAD94;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r30,r10,24092
	r30.s64 = ctx.r10.s64 + 24092;
	// addi r29,r11,-17052
	r29.s64 = r11.s64 + -17052;
loc_826FACB0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r10
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lbz r8,165(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 165);
	// rlwinm r7,r8,0,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x826fad74
	if (cr6.eq) goto loc_826FAD74;
	// lbz r11,164(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 164);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826fad74
	if (!cr6.eq) goto loc_826FAD74;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a7c28
	ctx.lr = 0x826FACE4;
	sub_822A7C28(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x826FACF8;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fad74
	if (cr6.eq) goto loc_826FAD74;
	// lwz r9,128(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 128);
	// lwz r10,448(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 448);
	// lbz r11,111(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 111);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fad28
	if (cr6.eq) goto loc_826FAD28;
	// lwz r11,128(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// lwz r8,448(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 448);
	// lbz r7,112(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 112);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x826fad48
	if (!cr6.eq) goto loc_826FAD48;
loc_826FAD28:
	// lbz r11,112(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fad74
	if (cr6.eq) goto loc_826FAD74;
	// lwz r11,128(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// lwz r10,448(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 448);
	// lbz r8,111(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 111);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826fad74
	if (cr6.eq) goto loc_826FAD74;
loc_826FAD48:
	// lwz r10,3604(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3604);
	// lwz r9,476(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 476);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bne cr6,0x826fad74
	if (!cr6.eq) goto loc_826FAD74;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lbz r7,165(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 165);
	// clrlwi r6,r7,25
	ctx.r6.u64 = ctx.r7.u32 & 0x7F;
	// stb r6,165(r8)
	PPC_STORE_U8(ctx.r8.u32 + 165, ctx.r6.u8);
loc_826FAD74:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// bl 0x822a7c08
	ctx.lr = 0x826FAD88;
	sub_822A7C08(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826facb0
	if (cr6.eq) goto loc_826FACB0;
loc_826FAD94:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826FAD9C"))) PPC_WEAK_FUNC(sub_826FAD9C);
PPC_FUNC_IMPL(__imp__sub_826FAD9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FADA0"))) PPC_WEAK_FUNC(sub_826FADA0);
PPC_FUNC_IMPL(__imp__sub_826FADA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fae3c
	if (cr6.eq) goto loc_826FAE3C;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826fae3c
	if (cr6.eq) goto loc_826FAE3C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FADE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826FADFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// fmadds f11,f0,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f10,f13,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fsqrts f9,f10
	ctx.f9.f64 = double(float(sqrt(ctx.f10.f64)));
	// stfs f9,8(r30)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// b 0x826fae48
	goto loc_826FAE48;
loc_826FAE3C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
loc_826FAE48:
	// li r3,1
	ctx.r3.s64 = 1;
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

__attribute__((alias("__imp__sub_826FAE64"))) PPC_WEAK_FUNC(sub_826FAE64);
PPC_FUNC_IMPL(__imp__sub_826FAE64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FAE68"))) PPC_WEAK_FUNC(sub_826FAE68);
PPC_FUNC_IMPL(__imp__sub_826FAE68) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FAE90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// bne cr6,0x826faef8
	if (!cr6.eq) goto loc_826FAEF8;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f9,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r5,128(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// lfs f12,17296(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17296);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,3732(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3732);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,12428(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 12428);
	ctx.f10.f64 = double(temp.f32);
	// lfs f8,412(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 412);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// fsel f6,f7,f7,f0
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f7.f64 : f0.f64;
	// fsel f5,f7,f7,f0
	ctx.f5.f64 = ctx.f7.f64 >= 0.0 ? ctx.f7.f64 : f0.f64;
	// fsubs f4,f6,f13
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// fsel f3,f4,f13,f5
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? ctx.f13.f64 : ctx.f5.f64;
	// fmadds f2,f3,f11,f10
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f11.f64 + ctx.f10.f64));
	// fcmpu cr6,f9,f2
	cr6.compare(ctx.f9.f64, ctx.f2.f64);
	// bgt cr6,0x826faef8
	if (cr6.gt) goto loc_826FAEF8;
	// li r3,0
	ctx.r3.s64 = 0;
loc_826FAEF8:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826FAF0C"))) PPC_WEAK_FUNC(sub_826FAF0C);
PPC_FUNC_IMPL(__imp__sub_826FAF0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FAF10"))) PPC_WEAK_FUNC(sub_826FAF10);
PPC_FUNC_IMPL(__imp__sub_826FAF10) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// bl 0x82741078
	ctx.lr = 0x826FAF54;
	sub_82741078(ctx, base);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r6,4(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r5,8(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// bl 0x826fac50
	ctx.lr = 0x826FAF80;
	sub_826FAC50(ctx, base);
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

__attribute__((alias("__imp__sub_826FAF98"))) PPC_WEAK_FUNC(sub_826FAF98);
PPC_FUNC_IMPL(__imp__sub_826FAF98) {
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
	PPCVRegister v123{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x826FAFA0;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823db9c0
	ctx.lr = 0x826FAFA8;
	// addi r12,r1,-176
	r12.s64 = ctx.r1.s64 + -176;
	// bl 0x823dd52c
	ctx.lr = 0x826FAFB0;
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,128(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 128);
	// lwz r3,472(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 472);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826fafdc
	if (cr6.eq) goto loc_826FAFDC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FAFDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826FAFDC:
	// lwz r11,128(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 128);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// addi r6,r10,-16980
	ctx.r6.s64 = ctx.r10.s64 + -16980;
	// addi r5,r9,-17020
	ctx.r5.s64 = ctx.r9.s64 + -17020;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,456(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 456);
	// bl 0x823dedd8
	ctx.lr = 0x826FB000;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fb2e4
	if (cr6.eq) goto loc_826FB2E4;
	// addi r21,r3,560
	r21.s64 = ctx.r3.s64 + 560;
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r21
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82794ee8
	ctx.lr = 0x826FB020;
	sub_82794EE8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821713c0
	ctx.lr = 0x826FB02C;
	sub_821713C0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// bl 0x822a7c08
	ctx.lr = 0x826FB03C;
	sub_822A7C08(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826fb2d8
	if (!cr6.eq) goto loc_826FB2D8;
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// lfs f22,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	f22.f64 = double(temp.f32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// lfs f23,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f23.f64 = double(temp.f32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// lfs f24,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f24.f64 = double(temp.f32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lfs f25,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f25.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lvx128 v126,r0,r11
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lvx128 v125,r0,r10
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lvx128 v124,r0,r9
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// lvx128 v123,r0,r8
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lfs f29,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f29.f64 = double(temp.f32);
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lfs f30,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f30.f64 = double(temp.f32);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lfs f27,31308(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 31308);
	f27.f64 = double(temp.f32);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lfs f28,14884(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14884);
	f28.f64 = double(temp.f32);
	// lfs f26,-12084(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -12084);
	f26.f64 = double(temp.f32);
	// li r23,112
	r23.s64 = 112;
	// li r24,196
	r24.s64 = 196;
	// lis r29,-32114
	r29.s64 = -2104623104;
	// addi r28,r11,2352
	r28.s64 = r11.s64 + 2352;
	// addi r27,r10,2384
	r27.s64 = ctx.r10.s64 + 2384;
	// addi r26,r9,24092
	r26.s64 = ctx.r9.s64 + 24092;
	// addi r25,r8,24064
	r25.s64 = ctx.r8.s64 + 24064;
loc_826FB0CC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lbz r7,165(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 165);
	// rlwinm r6,r7,0,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x826fb2b8
	if (cr6.eq) goto loc_826FB2B8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a7c28
	ctx.lr = 0x826FB0F4;
	sub_822A7C28(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplw cr6,r11,r22
	cr6.compare<uint32_t>(r11.u32, r22.u32, xer);
	// bne cr6,0x826fb2b8
	if (!cr6.eq) goto loc_826FB2B8;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826fb2b8
	if (cr6.eq) goto loc_826FB2B8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82330c18
	ctx.lr = 0x826FB114;
	sub_82330C18(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fb2b8
	if (cr6.eq) goto loc_826FB2B8;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823dedd8
	ctx.lr = 0x826FB134;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fb2b8
	if (cr6.eq) goto loc_826FB2B8;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r11,r9,r10
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r7,160(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 160);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cmplw cr6,r8,r6
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, xer);
	// bne cr6,0x826fb168
	if (!cr6.eq) goto loc_826FB168;
	// lvx128 v127,r11,r23
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826fb174
	goto loc_826FB174;
loc_826FB168:
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v61,r11,r23
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v127,v62,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
loc_826FB174:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82330c18
	ctx.lr = 0x826FB17C;
	sub_82330C18(ctx, base);
	// lvlx128 v60,r3,r24
	temp.u32 = ctx.r3.u32 + r24.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lhz r11,8(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// vmulfp128 v63,v127,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v59.f32)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x826fb1d8
	if (cr6.eq) goto loc_826FB1D8;
	// lwz r10,-23452(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -23452);
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,112(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// clrlwi r9,r10,30
	ctx.r9.u64 = ctx.r10.u32 & 0x3;
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// bne cr6,0x826fb1d8
	if (!cr6.eq) goto loc_826FB1D8;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stfs f26,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvlx128 v58,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vmulfp128 v56,v63,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826FB1D8:
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f0.f64 = double(temp.f32);
	// lfs f13,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f11,f0,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f10,f13,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fsqrts f9,f10
	ctx.f9.f64 = double(float(sqrt(ctx.f10.f64)));
	// fsqrts f8,f9
	ctx.f8.f64 = double(float(sqrt(ctx.f9.f64)));
	// fsubs f7,f8,f28
	ctx.f7.f64 = double(float(ctx.f8.f64 - f28.f64));
	// fmuls f6,f7,f27
	ctx.f6.f64 = double(float(ctx.f7.f64 * f27.f64));
	// fsel f5,f6,f6,f30
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f6.f64 : f30.f64;
	// fsubs f4,f5,f29
	ctx.f4.f64 = double(float(ctx.f5.f64 - f29.f64));
	// fsel f31,f4,f29,f5
	f31.f64 = ctx.f4.f64 >= 0.0 ? f29.f64 : ctx.f5.f64;
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// ble cr6,0x826fb2b8
	if (!cr6.gt) goto loc_826FB2B8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82330cc0
	ctx.lr = 0x826FB21C;
	sub_82330CC0(ctx, base);
	// lvx128 v63,r0,r27
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r0,r3
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v54,v123,v125
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v125.u32), simde_mm_load_si128((simde__m128i*)v123.u32)));
	// vmrghw128 v53,v124,v126
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v126.u32), simde_mm_load_si128((simde__m128i*)v124.u32)));
	// vand128 v52,v55,v63
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrglw128 v51,v124,v126
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v126.u32), simde_mm_load_si128((simde__m128i*)v124.u32)));
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v50,v123,v125
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v125.u32), simde_mm_load_si128((simde__m128i*)v123.u32)));
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// vor128 v49,v63,v52
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v52.u8)));
	// vmrglw128 v48,v54,v53
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrghw128 v47,v54,v53
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrghw128 v46,v50,v51
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmsum4fp128 v45,v49,v48
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v48.f32), 0xFF));
	// vmsum4fp128 v44,v49,v47
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v47.f32), 0xFF));
	// vmsum4fp128 v43,v49,v46
	simde_mm_store_ps(v43.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v46.f32), 0xFF));
	// vmrghw128 v42,v45,v49
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v41,v44,v43
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrghw128 v40,v41,v42
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// stvx128 v40,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// lfs f0,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	f0.f64 = double(temp.f32);
	// bgt cr6,0x826fb29c
	if (cr6.gt) goto loc_826FB29C;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bgt cr6,0x826fb290
	if (cr6.gt) goto loc_826FB290;
	// fadds f22,f22,f31
	f22.f64 = double(float(f22.f64 + f31.f64));
	// stfs f22,108(r1)
	temp.f32 = float(f22.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// b 0x826fb2b8
	goto loc_826FB2B8;
loc_826FB290:
	// fadds f23,f23,f31
	ctx.fpscr.disableFlushMode();
	f23.f64 = double(float(f23.f64 + f31.f64));
	// stfs f23,104(r1)
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// b 0x826fb2b8
	goto loc_826FB2B8;
loc_826FB29C:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f30.f64);
	// bgt cr6,0x826fb2b0
	if (cr6.gt) goto loc_826FB2B0;
	// fadds f24,f24,f31
	f24.f64 = double(float(f24.f64 + f31.f64));
	// stfs f24,100(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// b 0x826fb2b8
	goto loc_826FB2B8;
loc_826FB2B0:
	// fadds f25,f25,f31
	ctx.fpscr.disableFlushMode();
	f25.f64 = double(float(f25.f64 + f31.f64));
	// stfs f25,96(r1)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
loc_826FB2B8:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// bl 0x822a7c08
	ctx.lr = 0x826FB2CC;
	sub_822A7C08(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fb0cc
	if (cr6.eq) goto loc_826FB0CC;
loc_826FB2D8:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v39,r0,r11
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r0,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826FB2E4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r8,12(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// stw r9,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r9.u32);
	// stw r8,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r8.u32);
	// bl 0x826faa70
	ctx.lr = 0x826FB310;
	sub_826FAA70(ctx, base);
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// addi r12,r1,-176
	r12.s64 = ctx.r1.s64 + -176;
	// bl 0x823dd7c4
	ctx.lr = 0x826FB31C;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823dba0c
	ctx.lr = 0x826FB324;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_826FB328"))) PPC_WEAK_FUNC(sub_826FB328);
PPC_FUNC_IMPL(__imp__sub_826FB328) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82227f50
	ctx.lr = 0x826FB344;
	sub_82227F50(ctx, base);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// addi r10,r31,32
	ctx.r10.s64 = r31.s64 + 32;
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r31,48
	ctx.r9.s64 = r31.s64 + 48;
	// vspltisw v11,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// vspltw128 v61,v63,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// vspltw128 v8,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v59,v62,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v57,v60,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vspltw128 v10,v58,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// lvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v9,v0,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v61.f32)));
	// vspltw128 v6,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// vmulfp128 v7,v0,v59
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v59.f32)));
	// vspltw128 v4,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xAA));
	// vmulfp128 v5,v0,v57
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v57.f32)));
	// vspltw128 v2,v58,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xAA));
	// vmaddfp v3,v0,v10,v11
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// lvx128 v13,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v1,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// lvx128 v12,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v31,v62,2
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// vspltw128 v30,v60,2
	simde_mm_store_si128((simde__m128i*)v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x55));
	// vspltw128 v29,v58,2
	simde_mm_store_si128((simde__m128i*)v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x55));
	// vmaddfp v28,v13,v8,v9
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp v27,v13,v6,v7
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmaddfp v26,v13,v4,v5
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v25,v13,v2,v3
	simde_mm_store_ps(v25.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v24,v12,v1,v28
	simde_mm_store_ps(v24.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(v28.f32)));
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

__attribute__((alias("__imp__sub_826FB400"))) PPC_WEAK_FUNC(sub_826FB400);
PPC_FUNC_IMPL(__imp__sub_826FB400) {
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
	// bl 0x823d91e0
	ctx.lr = 0x826FB408;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823dd534
	ctx.lr = 0x826FB410;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lwz r11,448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 448);
	// lbz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 112);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826fb444
	if (!cr6.eq) goto loc_826FB444;
loc_826FB430:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823dd7cc
	ctx.lr = 0x826FB440;
	// b 0x823d9230
	return;
loc_826FB444:
	// lbz r10,500(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 500);
	// rlwinm r9,r10,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826fb430
	if (!cr6.eq) goto loc_826FB430;
	// lwz r10,448(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 448);
	// lwz r28,168(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 168);
	// lwz r3,168(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 168);
	// bl 0x82790a18
	ctx.lr = 0x826FB464;
	sub_82790A18(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lvx128 v127,r0,r9
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82790a18
	ctx.lr = 0x826FB474;
	sub_82790A18(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v124,r0,r8
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v124,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,17740(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 17740);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x82794ee8
	ctx.lr = 0x826FB4AC;
	sub_82794EE8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82794ee8
	ctx.lr = 0x826FB4B8;
	sub_82794EE8(ctx, base);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// li r9,48
	ctx.r9.s64 = 48;
	// lvx128 v59,r0,r3
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r11,2384
	r29.s64 = r11.s64 + 2384;
	// lvx128 v60,r0,r31
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,16
	ctx.r8.s64 = 16;
	// li r4,32
	ctx.r4.s64 = 32;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lvx128 v57,r3,r9
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r28,r10,2352
	r28.s64 = ctx.r10.s64 + 2352;
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,32
	r11.s64 = r31.s64 + 32;
	// lvx128 v56,r3,r8
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r31,48
	ctx.r10.s64 = r31.s64 + 48;
	// lvx128 v58,r3,r4
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r31,16
	ctx.r9.s64 = r31.s64 + 16;
	// vmrghw128 v55,v59,v58
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrghw128 v54,v56,v57
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vand128 v53,v127,v63
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrglw128 v52,v59,v58
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// lvx128 v62,r0,r28
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v51,v56,v57
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// lvx128 v50,r0,r11
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r0,r10
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v48,v60,v50
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// lvx128 v47,r0,r9
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v46,v62,v53
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v53.u8)));
	// lvx128 v45,r0,r7
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v42,v55,v54
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v40,v55,v54
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vand128 v43,v45,v63
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrghw128 v44,v47,v49
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// vmrghw128 v41,v52,v51
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// addi r23,r30,16
	r23.s64 = r30.s64 + 16;
	// vmrglw128 v35,v60,v50
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmsum4fp128 v37,v46,v42
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v37.f32, simde_mm_dp_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v42.f32), 0xFF));
	// vmrglw128 v33,v47,v49
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vor128 v38,v62,v43
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v43.u8)));
	// vmrglw128 v39,v48,v44
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmsum4fp128 v34,v46,v40
	simde_mm_store_ps(v34.f32, simde_mm_dp_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v40.f32), 0xFF));
	// vmsum4fp128 v36,v46,v41
	simde_mm_store_ps(v36.f32, simde_mm_dp_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v41.f32), 0xFF));
	// vmrghw128 v32,v48,v44
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// addi r27,r8,2240
	r27.s64 = ctx.r8.s64 + 2240;
	// vmrghw128 v61,v35,v33
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// vmsum4fp128 v62,v38,v39
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v39.f32), 0xFF));
	// vmsum4fp128 v59,v38,v32
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v32.f32), 0xFF));
	// vmsum4fp128 v58,v38,v61
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v61.f32), 0xFF));
	// lvx128 v0,r0,r27
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v37,v46
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vmrghw128 v56,v34,v36
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// vmrghw128 v55,v62,v38
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrghw128 v125,v56,v57
	simde_mm_store_si128((simde__m128i*)v125.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v54,v59,v58
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrghw128 v53,v54,v55
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// addi r26,r8,2528
	r26.s64 = ctx.r8.s64 + 2528;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r25,r7,-31648
	r25.s64 = ctx.r7.s64 + -31648;
	// vsubfp128 v52,v53,v125
	simde_mm_store_ps(v52.f32, simde_mm_sub_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v125.f32)));
	// addi r24,r8,-31664
	r24.s64 = ctx.r8.s64 + -31664;
	// lvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r22,r30,32
	r22.s64 = r30.s64 + 32;
	// addi r31,r30,48
	r31.s64 = r30.s64 + 48;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lvx128 v61,r0,r25
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lvx128 v12,r0,r24
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r6,-31456
	ctx.r4.s64 = ctx.r6.s64 + -31456;
	// stvx128 v60,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r9
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r0,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v50,v52,v52
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v52.f32), 0xEF));
	// lvx128 v49,r0,r11
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r0,r22
	simde_mm_store_si128((simde__m128i*)(base + ((r22.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v48,v50
	simde_mm_store_ps(v48.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v50.f32))));
	// vor128 v11,v50,v50
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v50.u8));
	// lvx128 v47,r0,r10
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128 v10,v48,v63
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v63.f32)));
	// vor128 v9,v48,v48
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v48.u8));
	// lvx128 v46,r0,r11
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v45,v46,99
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0x9C));
	// vsel v0,v9,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// lvx128 v62,r0,r28
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v44,v46,135
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0x78));
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v43,v60,v63
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmulfp128 v8,v0,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v13,v61,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v12,v11,v8,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v7,v12,v13,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v42,v52,v7
	simde_mm_store_ps(v42.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(ctx.v7.f32)));
	// vpermwi128 v41,v42,135
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), 0x78));
	// vpermwi128 v40,v42,99
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), 0x9C));
	// vmulfp128 v127,v41,v45
	simde_mm_store_ps(v127.f32, simde_mm_mul_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v45.f32)));
	// vnmsubfp128 v127,v40,v44,v127
	simde_mm_store_ps(v127.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v44.f32)), simde_mm_load_ps(v127.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v126,v127,v127
	simde_mm_store_ps(v126.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v127.f32), 0xEF));
	// stvx128 v127,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v39,v126,v63
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v38,v39,v62
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vcmpgefp128. v37,v38,v43
	simde_mm_store_ps(v37.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v43.f32)));
	cr6.setFromMask(simde_mm_load_ps(v37.f32), 0xF);
	// mfocrf r3,2
	ctx.r3.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r11,r3,0,24,24
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fb6e4
	if (cr6.eq) goto loc_826FB6E4;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f11,f0,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f10,f13,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fsqrts f1,f10
	ctx.f1.f64 = double(float(sqrt(ctx.f10.f64)));
	// bl 0x823dca68
	ctx.lr = 0x826FB68C;
	sub_823DCA68(ctx, base);
	// vrsqrtefp128 v36,v126
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v36.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v126.f32))));
	// lvx128 v62,r0,r26
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r0,r27
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v12,v126,v126
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// lvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v13,r0,r24
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// vcmpeqfp128 v10,v36,v62
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v9,v36,v36
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v36.u8));
	// vsel v0,v9,v11,v10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vmulfp128 v8,v0,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v7,v63,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v6,v12,v8,v13
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v5,v6,v7,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v35,v127,v5
	simde_mm_store_ps(v35.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(ctx.v5.f32)));
	// stvx128 v35,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f1,f1
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// bl 0x826fb328
	ctx.lr = 0x826FB6DC;
	sub_826FB328(ctx, base);
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r28
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826FB6E4:
	// vand128 v33,v124,v63
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v34,r0,r22
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v55,v63,v63
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// lvx128 v32,r0,r30
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,1
	ctx.r3.s64 = 1;
	// lvx128 v60,r0,r23
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v61,v32,v34
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// vmrghw128 v58,v60,v63
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vor128 v57,v62,v33
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v33.u8)));
	// vmrglw128 v59,v32,v34
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// vmrglw128 v56,v60,v63
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmrglw128 v54,v61,v58
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v52,v61,v58
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v53,v59,v56
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmsum4fp128 v51,v57,v54
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v54.f32), 0xFF));
	// vmsum4fp128 v49,v57,v52
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v52.f32), 0xFF));
	// vmsum4fp128 v50,v57,v53
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v53.f32), 0xFF));
	// vmrghw128 v48,v51,v57
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v47,v49,v50
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v46,v47,v48
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vsubfp128 v45,v125,v46
	simde_mm_store_ps(v45.f32, simde_mm_sub_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v46.f32)));
	// vaddfp128 v44,v55,v45
	simde_mm_store_ps(v44.f32, simde_mm_add_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v45.f32)));
	// stvx128 v44,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823dd7cc
	ctx.lr = 0x826FB750;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_826FB754"))) PPC_WEAK_FUNC(sub_826FB754);
PPC_FUNC_IMPL(__imp__sub_826FB754) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FB758"))) PPC_WEAK_FUNC(sub_826FB758);
PPC_FUNC_IMPL(__imp__sub_826FB758) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r4,3604(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3604);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bge cr6,0x826fb76c
	if (!cr6.lt) goto loc_826FB76C;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_826FB76C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// b 0x826d62e0
	sub_826D62E0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826FB778"))) PPC_WEAK_FUNC(sub_826FB778);
PPC_FUNC_IMPL(__imp__sub_826FB778) {
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
	// bl 0x823d91f0
	ctx.lr = 0x826FB780;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-544(r1)
	ea = -544 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r10,23772
	ctx.r10.s64 = 1557921792;
	// lis r8,26214
	ctx.r8.s64 = 1717960704;
	// ori r27,r10,64167
	r27.u64 = ctx.r10.u64 | 64167;
	// ori r28,r8,26215
	r28.u64 = ctx.r8.u64 | 26215;
	// lwz r9,384(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 384);
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lwz r11,388(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 388);
	// addi r31,r30,384
	r31.s64 = r30.s64 + 384;
	// mulld r10,r9,r27
	ctx.r10.s64 = ctx.r9.s64 * r27.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// clrlwi r7,r11,1
	ctx.r7.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,384(r30)
	PPC_STORE_U32(r30.u32 + 384, r11.u32);
	// rldicl r4,r11,32,32
	ctx.r4.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// mulhw r5,r7,r28
	ctx.r5.s64 = (int64_t(ctx.r7.s32) * int64_t(r28.s32)) >> 32;
	// stw r4,388(r30)
	PPC_STORE_U32(r30.u32 + 388, ctx.r4.u32);
	// lwz r3,-10012(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10012);
	// srawi r10,r5,1
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 1;
	// addi r8,r9,-16932
	ctx.r8.s64 = ctx.r9.s64 + -16932;
	// rlwinm r11,r10,1,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// subf r5,r6,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r6.s64;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r4,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// bl 0x826d5390
	ctx.lr = 0x826FB7F8;
	sub_826D5390(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826fb954
	if (cr6.eq) goto loc_826FB954;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x82687930
	ctx.lr = 0x826FB80C;
	sub_82687930(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mulld r10,r10,r27
	ctx.r10.s64 = ctx.r10.s64 * r27.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r9,r11,1
	ctx.r9.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// rldicl r6,r11,32,32
	ctx.r6.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// mulhw r7,r9,r28
	ctx.r7.s64 = (int64_t(ctx.r9.s32) * int64_t(r28.s32)) >> 32;
	// stw r6,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r6.u32);
	// lwz r5,448(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 448);
	// srawi r10,r7,3
	xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 3;
	// rlwinm r11,r10,1,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r3,r9
	r11.s64 = ctx.r9.s64 - ctx.r3.s64;
	// sth r11,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, r11.u16);
	// lwz r3,168(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 168);
	// lwz r31,168(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 168);
	// bl 0x82790a18
	ctx.lr = 0x826FB860;
	sub_82790A18(ctx, base);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82790a18
	ctx.lr = 0x826FB874;
	sub_82790A18(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82794ee8
	ctx.lr = 0x826FB88C;
	sub_82794EE8(ctx, base);
	// addi r3,r3,32
	ctx.r3.s64 = ctx.r3.s64 + 32;
	// bl 0x8278f690
	ctx.lr = 0x826FB894;
	sub_8278F690(ctx, base);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// addi r3,r6,-31600
	ctx.r3.s64 = ctx.r6.s64 + -31600;
	// bl 0x8278f690
	ctx.lr = 0x826FB8A4;
	sub_8278F690(ctx, base);
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// bl 0x8278f6f8
	ctx.lr = 0x826FB8AC;
	sub_8278F6F8(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x8216c890
	ctx.lr = 0x826FB8B8;
	sub_8216C890(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8216c890
	ctx.lr = 0x826FB8C4;
	sub_8216C890(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82794ee8
	ctx.lr = 0x826FB8CC;
	sub_82794EE8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// li r11,16
	r11.s64 = 16;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// li r9,32
	ctx.r9.s64 = 32;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v60,r5,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r5,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826e5cb8
	ctx.lr = 0x826FB904;
	sub_826E5CB8(ctx, base);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lvx128 v58,r0,r3
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lwz r7,476(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 476);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// vaddfp128 v56,v58,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v57.f32)));
	// lvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// lfs f1,7444(r5)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// vsubfp128 v54,v56,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v55.f32)));
	// stvx128 v54,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826df9b8
	ctx.lr = 0x826FB948;
	sub_826DF9B8(ctx, base);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lwz r3,-10012(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10012);
	// bl 0x826d4b70
	ctx.lr = 0x826FB954;
	sub_826D4B70(ctx, base);
loc_826FB954:
	// addi r1,r1,544
	ctx.r1.s64 = ctx.r1.s64 + 544;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826FB960"))) PPC_WEAK_FUNC(sub_826FB960);
PPC_FUNC_IMPL(__imp__sub_826FB960) {
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
	ctx.lr = 0x826FB968;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,448(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 448);
	// lbz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 112);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826fb98c
	if (!cr6.eq) goto loc_826FB98C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826FB98C:
	// lwz r4,3604(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 3604);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bge cr6,0x826fb9a4
	if (!cr6.lt) goto loc_826FB9A4;
	// li r30,0
	r30.s64 = 0;
	// b 0x826fb9b8
	goto loc_826FB9B8;
loc_826FB9A4:
	// lwz r3,-10012(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// bl 0x826d62e0
	ctx.lr = 0x826FB9AC;
	sub_826D62E0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x826fb9c8
	if (!cr6.eq) goto loc_826FB9C8;
loc_826FB9B8:
	// li r5,16
	ctx.r5.s64 = 16;
	// lwz r3,-10012(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x826d50e8
	ctx.lr = 0x826FB9C8;
	sub_826D50E8(ctx, base);
loc_826FB9C8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826FB9D4"))) PPC_WEAK_FUNC(sub_826FB9D4);
PPC_FUNC_IMPL(__imp__sub_826FB9D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FB9D8"))) PPC_WEAK_FUNC(sub_826FB9D8);
PPC_FUNC_IMPL(__imp__sub_826FB9D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r11,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, r11.u8);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stb r11,21(r3)
	PPC_STORE_U8(ctx.r3.u32 + 21, r11.u8);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FBA04"))) PPC_WEAK_FUNC(sub_826FBA04);
PPC_FUNC_IMPL(__imp__sub_826FBA04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FBA08"))) PPC_WEAK_FUNC(sub_826FBA08);
PPC_FUNC_IMPL(__imp__sub_826FBA08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// stb r11,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, r11.u8);
	// stb r11,21(r3)
	PPC_STORE_U8(ctx.r3.u32 + 21, r11.u8);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FBA34"))) PPC_WEAK_FUNC(sub_826FBA34);
PPC_FUNC_IMPL(__imp__sub_826FBA34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FBA38"))) PPC_WEAK_FUNC(sub_826FBA38);
PPC_FUNC_IMPL(__imp__sub_826FBA38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// stb r11,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, r11.u8);
	// stb r11,21(r3)
	PPC_STORE_U8(ctx.r3.u32 + 21, r11.u8);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FBA5C"))) PPC_WEAK_FUNC(sub_826FBA5C);
PPC_FUNC_IMPL(__imp__sub_826FBA5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FBA60"))) PPC_WEAK_FUNC(sub_826FBA60);
PPC_FUNC_IMPL(__imp__sub_826FBA60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x826FBA68;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823db9d0
	ctx.lr = 0x826FBA70;
	// li r12,-176
	r12.s64 = -176;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r23,r9
	r23.u64 = ctx.r9.u64;
	// fcmpu cr6,f30,f31
	cr6.compare(f30.f64, f31.f64);
	// beq cr6,0x826fbf94
	if (cr6.eq) goto loc_826FBF94;
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// li r20,0
	r20.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826fbac8
	if (!cr6.eq) goto loc_826FBAC8;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82794ee8
	ctx.lr = 0x826FBAC0;
	sub_82794EE8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// b 0x826fbacc
	goto loc_826FBACC;
loc_826FBAC8:
	// mr r28,r20
	r28.u64 = r20.u64;
loc_826FBACC:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r27,448(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 448);
	// beq cr6,0x826fbf5c
	if (cr6.eq) goto loc_826FBF5C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r25,r30,16
	r25.s64 = r30.s64 + 16;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lvx128 v1,r0,r25
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FBB04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r26,24
	ctx.r9.u64 = r26.u32 & 0xFF;
	// li r22,48
	r22.s64 = 48;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lfs f0,276(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 276);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// lfs f12,272(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 272);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,280(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 280);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f12,f12,f13
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmadds f9,f11,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f10.f64));
	// fsqrts f26,f9
	f26.f64 = double(float(sqrt(ctx.f9.f64)));
	// stfs f26,80(r1)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// beq cr6,0x826fbbcc
	if (cr6.eq) goto loc_826FBBCC;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x826ddd90
	ctx.lr = 0x826FBB44;
	sub_826DDD90(ctx, base);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,16
	ctx.r9.s64 = 16;
	// lvx128 v61,r0,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r28,r22
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v49,r0,r11
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v48,v62,v49
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v48.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v49.f32)));
	// lvx128 v59,r28,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r28,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v61,v59
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v56,v58,v60
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v55,v61,v59
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrglw128 v54,v58,v60
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vpermwi128 v53,v63,99
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// vmrghw128 v52,v57,v56
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrglw128 v51,v57,v56
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v50,v55,v54
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vpermwi128 v0,v63,135
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// vmsum3fp128 v47,v48,v50
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v50.f32), 0xEF));
	// vmsum3fp128 v46,v48,v52
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v52.f32), 0xEF));
	// vmsum3fp128 v45,v48,v51
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v51.f32), 0xEF));
	// vmrghw128 v44,v46,v47
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v43,v45,v44
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v42,v44,v43
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vpermwi128 v41,v42,135
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), 0x78));
	// vpermwi128 v13,v42,99
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), 0x9C));
	// vmulfp128 v12,v41,v53
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v53.f32)));
	// vnmsubfp v11,v13,v0,v12
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmulfp128 v40,v42,v11
	simde_mm_store_ps(v40.f32, simde_mm_mul_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(ctx.v11.f32)));
	// vsubfp128 v0,v63,v40
	simde_mm_store_ps(ctx.v0.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v40.f32)));
	// b 0x826fbbec
	goto loc_826FBBEC;
loc_826FBBCC:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,32
	ctx.r9.s64 = 32;
	// lvlx128 v39,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v0,v39,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), 0xFF));
	// lvx128 v13,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r28,r9
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v12,v0,v13
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
loc_826FBBEC:
	// addi r29,r30,32
	r29.s64 = r30.s64 + 32;
	// vpermwi128 v38,v0,99
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0x9C));
	// vpermwi128 v0,v0,135
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0x78));
	// lvx128 v37,r0,r24
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v36,r0,r25
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// vsubfp128 v35,v36,v37
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v35.f32, simde_mm_sub_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v37.f32)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f13,8(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v34,r0,r29
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// vpermwi128 v33,v34,135
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0x78));
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// vpermwi128 v13,v34,99
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0x9C));
	// addi r30,r28,16
	r30.s64 = r28.s64 + 16;
	// vpermwi128 v32,v34,135
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0x78));
	// vpermwi128 v12,v34,99
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), 0x9C));
	// vmulfp128 v11,v33,v38
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(v33.f32), simde_mm_load_ps(v38.f32)));
	// lfs f28,7444(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f28.f64 = double(temp.f32);
	// fdivs f29,f28,f30
	f29.f64 = double(float(f28.f64 / f30.f64));
	// stvx128 v35,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f10.f64 = double(temp.f32);
	// vnmsubfp v0,v13,v0,v11
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v11.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vpermwi128 v63,v0,99
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0x9C));
	// stvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v10,v0,135
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0x78));
	// vmulfp128 v9,v32,v63
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v63.f32)));
	// vnmsubfp v8,v12,v10,v9
	simde_mm_store_ps(ctx.v8.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v9.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v8,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,20(r28)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,16(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 16);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,24(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 24);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f7,f10
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f10.f64));
	// fmadds f5,f9,f12,f6
	ctx.f5.f64 = double(float(ctx.f9.f64 * ctx.f12.f64 + ctx.f6.f64));
	// fmr f27,f9
	f27.f64 = ctx.f9.f64;
	// fmadds f0,f11,f8,f5
	f0.f64 = double(float(ctx.f11.f64 * ctx.f8.f64 + ctx.f5.f64));
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// fsubs f4,f0,f13
	ctx.f4.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fmuls f13,f4,f29
	ctx.f13.f64 = double(float(ctx.f4.f64 * f29.f64));
	// bne cr6,0x826fbc9c
	if (!cr6.eq) goto loc_826FBC9C;
	// fmr f13,f31
	ctx.f13.f64 = f31.f64;
loc_826FBC9C:
	// lfs f12,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lfs f11,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// fmuls f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// lfs f7,248(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 248);
	ctx.f7.f64 = double(temp.f32);
	// lfs f9,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// lfs f8,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// lfs f3,244(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 244);
	ctx.f3.f64 = double(temp.f32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lfs f5,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f4,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// lvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f2,f9,f8,f10
	ctx.f2.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f10.f64));
	// fmadds f1,f3,f0,f6
	ctx.f1.f64 = double(float(ctx.f3.f64 * f0.f64 + ctx.f6.f64));
	// fmadds f0,f5,f4,f2
	f0.f64 = double(float(ctx.f5.f64 * ctx.f4.f64 + ctx.f2.f64));
	// fmuls f13,f0,f1
	ctx.f13.f64 = double(float(f0.f64 * ctx.f1.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v61,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v60,v61,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vmulfp128 v59,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v60.f32)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826e9658
	ctx.lr = 0x826FBD04;
	sub_826E9658(ctx, base);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f12,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// clrlwi r26,r21,24
	r26.u64 = r21.u32 & 0xFF;
	// fadds f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 + ctx.f12.f64));
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// lvx128 v127,r0,r9
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x826fbd3c
	if (cr6.eq) goto loc_826FBD3C;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FBD3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826FBD3C:
	// lvx128 v58,r0,r25
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v57,r28,r22
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// vsubfp128 v0,v58,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v57.f32)));
	// lfs f0,240(r27)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 240);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f27
	ctx.f13.f64 = double(float(f0.f64 * f27.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v13,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v56,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// vmaddfp v0,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// beq cr6,0x826fbd9c
	if (cr6.eq) goto loc_826FBD9C;
	// vpermwi128 v55,v0,99
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0x9C));
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// vpermwi128 v54,v127,135
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x78));
	// vpermwi128 v0,v0,135
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v0.u32), 0x78));
	// vpermwi128 v13,v127,99
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x9C));
	// vmulfp128 v12,v54,v55
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v55.f32)));
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// vnmsubfp v1,v13,v0,v12
	simde_mm_store_ps(ctx.v1.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FBD9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826FBD9C:
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,216(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 216);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x826fbdf0
	if (!cr6.gt) goto loc_826FBDF0;
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x826fbdf0
	if (cr6.eq) goto loc_826FBDF0;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lvx128 v53,r0,r29
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,2256
	ctx.r4.s64 = ctx.r10.s64 + 2256;
	// lvlx128 v52,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// vspltw128 v51,v52,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0xFF));
	// lwz r8,108(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 108);
	// vmulfp128 v1,v53,v51
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v51.f32)));
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826FBDF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826FBDF0:
	// lfs f0,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f10,f0,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fsqrts f8,f9
	ctx.f8.f64 = double(float(sqrt(ctx.f9.f64)));
	// fmuls f0,f8,f30
	f0.f64 = double(float(ctx.f8.f64 * f30.f64));
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// lfs f13,228(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 228);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x826fbe44
	if (!cr6.gt) goto loc_826FBE44;
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// li r11,1
	r11.s64 = 1;
	// lfs f0,204(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 204);
	f0.f64 = double(temp.f32);
	// lfs f13,228(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 228);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64));
	// stfs f11,12(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stb r11,20(r31)
	PPC_STORE_U8(r31.u32 + 20, r11.u8);
	// b 0x826fbe78
	goto loc_826FBE78;
loc_826FBE44:
	// fneg f13,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x826fbe74
	if (!cr6.lt) goto loc_826FBE74;
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// li r11,1
	r11.s64 = 1;
	// lfs f0,204(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 204);
	f0.f64 = double(temp.f32);
	// lfs f13,228(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 228);
	ctx.f13.f64 = double(temp.f32);
	// stb r11,20(r31)
	PPC_STORE_U8(r31.u32 + 20, r11.u8);
	// fmuls f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fneg f10,f11
	ctx.f10.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// stfs f10,12(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// b 0x826fbe78
	goto loc_826FBE78;
loc_826FBE74:
	// stb r20,20(r31)
	PPC_STORE_U8(r31.u32 + 20, r20.u8);
loc_826FBE78:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// fsubs f13,f0,f12
	ctx.f13.f64 = double(float(f0.f64 - ctx.f12.f64));
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lfs f12,252(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 252);
	ctx.f12.f64 = double(temp.f32);
	// addi r8,r10,2528
	ctx.r8.s64 = ctx.r10.s64 + 2528;
	// addi r7,r9,2240
	ctx.r7.s64 = ctx.r9.s64 + 2240;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// vmsum3fp128 v50,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r4,r6,-31648
	ctx.r4.s64 = ctx.r6.s64 + -31648;
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r5,-31664
	ctx.r3.s64 = ctx.r5.s64 + -31664;
	// lvx128 v0,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32244
	r11.s64 = -2113142784;
	// fmuls f11,f13,f29
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.f64 = double(float(ctx.f13.f64 * f29.f64));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,18044(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18044);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f26,f13
	cr6.compare(f26.f64, ctx.f13.f64);
	// vrsqrtefp128 v49,v50
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v49.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v50.f32))));
	// vor128 v12,v50,v50
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v50.u8));
	// vcmpeqfp128 v11,v49,v61
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v61.f32)));
	// vor128 v10,v49,v49
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v49.u8));
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
	// vmulfp128 v63,v63,v6
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v6.f32)));
	// bge cr6,0x826fbf08
	if (!cr6.lt) goto loc_826FBF08;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,12428(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12428);
	ctx.f13.f64 = double(temp.f32);
	// b 0x826fbf0c
	goto loc_826FBF0C;
loc_826FBF08:
	// fmr f13,f28
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f28.f64;
loc_826FBF0C:
	// lfs f10,256(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 256);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f13,f12
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmuls f8,f10,f11
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f11.f64));
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// fmsubs f7,f9,f0,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * f0.f64 - ctx.f8.f64));
	// fmuls f6,f7,f27
	ctx.f6.f64 = double(float(ctx.f7.f64 * f27.f64));
	// stfs f6,80(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// beq cr6,0x826fbf70
	if (cr6.eq) goto loc_826FBF70;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lvx128 v2,r0,r25
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,0
	ctx.r4.s64 = 0;
	// lvlx128 v48,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// vspltw128 v47,v48,0
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xFF));
	// lwz r9,124(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 124);
	// vmulfp128 v1,v63,v47
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v47.f32)));
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826FBF58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x826fbf70
	goto loc_826FBF70;
loc_826FBF5C:
	// lfs f0,20(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 20);
	f0.f64 = double(temp.f32);
	// stb r20,20(r31)
	PPC_STORE_U8(r31.u32 + 20, r20.u8);
	// lfs f13,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f12,f0,f30,f13
	ctx.f12.f64 = double(float(-(f0.f64 * f30.f64 - ctx.f13.f64)));
	// stfs f12,8(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
loc_826FBF70:
	// lfs f13,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,216(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 216);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x826fbf90
	if (cr6.gt) goto loc_826FBF90;
	// fneg f12,f0
	ctx.f12.u64 = f0.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bge cr6,0x826fbf94
	if (!cr6.lt) goto loc_826FBF94;
	// fneg f0,f0
	f0.u64 = f0.u64 ^ 0x8000000000000000;
loc_826FBF90:
	// stfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
loc_826FBF94:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// li r0,-176
	r0.s64 = -176;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba1c
	ctx.lr = 0x826FBFA8;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_826FBFAC"))) PPC_WEAK_FUNC(sub_826FBFAC);
PPC_FUNC_IMPL(__imp__sub_826FBFAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FBFB0"))) PPC_WEAK_FUNC(sub_826FBFB0);
PPC_FUNC_IMPL(__imp__sub_826FBFB0) {
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
	// lis r31,-32114
	r31.s64 = -2104623104;
	// lwz r3,-23636(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -23636);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fc008
	if (cr6.eq) goto loc_826FC008;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FBFE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-23636(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -23636);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fc000
	if (cr6.eq) goto loc_826FC000;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FC000;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826FC000:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-23636(r31)
	PPC_STORE_U32(r31.u32 + -23636, r11.u32);
loc_826FC008:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r31,-21116(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -21116);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826fc03c
	if (cr6.eq) goto loc_826FC03C;
	// bl 0x82760eb0
	ctx.lr = 0x826FC01C;
	sub_82760EB0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826fc03c
	if (cr6.eq) goto loc_826FC03C;
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
	ctx.lr = 0x826FC03C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826FC03C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826FC050"))) PPC_WEAK_FUNC(sub_826FC050);
PPC_FUNC_IMPL(__imp__sub_826FC050) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,36(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 36);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x8276a220
	sub_8276A220(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826FC064"))) PPC_WEAK_FUNC(sub_826FC064);
PPC_FUNC_IMPL(__imp__sub_826FC064) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FC068"))) PPC_WEAK_FUNC(sub_826FC068);
PPC_FUNC_IMPL(__imp__sub_826FC068) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,18340
	ctx.r10.s64 = r11.s64 + 18340;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82767860
	ctx.lr = 0x826FC094;
	sub_82767860(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826fc0ac
	if (cr6.eq) goto loc_826FC0AC;
	// bl 0x82130588
	ctx.lr = 0x826FC0A8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826FC0AC:
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

__attribute__((alias("__imp__sub_826FC0C4"))) PPC_WEAK_FUNC(sub_826FC0C4);
PPC_FUNC_IMPL(__imp__sub_826FC0C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FC0C8"))) PPC_WEAK_FUNC(sub_826FC0C8);
PPC_FUNC_IMPL(__imp__sub_826FC0C8) {
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
	// bl 0x8276acf8
	ctx.lr = 0x826FC0E8;
	sub_8276ACF8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fc100
	if (cr6.eq) goto loc_826FC100;
	// bl 0x82130588
	ctx.lr = 0x826FC0FC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826FC100:
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

__attribute__((alias("__imp__sub_826FC118"))) PPC_WEAK_FUNC(sub_826FC118);
PPC_FUNC_IMPL(__imp__sub_826FC118) {
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
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x826FC12C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fc148
	if (cr6.eq) goto loc_826FC148;
	// bl 0x8276ae18
	ctx.lr = 0x826FC138;
	sub_8276AE18(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826FC148:
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

__attribute__((alias("__imp__sub_826FC15C"))) PPC_WEAK_FUNC(sub_826FC15C);
PPC_FUNC_IMPL(__imp__sub_826FC15C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FC160"))) PPC_WEAK_FUNC(sub_826FC160);
PPC_FUNC_IMPL(__imp__sub_826FC160) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// b 0x8276aec0
	sub_8276AEC0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826FC170"))) PPC_WEAK_FUNC(sub_826FC170);
PPC_FUNC_IMPL(__imp__sub_826FC170) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FC174"))) PPC_WEAK_FUNC(sub_826FC174);
PPC_FUNC_IMPL(__imp__sub_826FC174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FC178"))) PPC_WEAK_FUNC(sub_826FC178);
PPC_FUNC_IMPL(__imp__sub_826FC178) {
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
	ctx.lr = 0x826FC180;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,-23636(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23636);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fc24c
	if (cr6.eq) goto loc_826FC24C;
	// lbz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 36);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826fc24c
	if (cr6.eq) goto loc_826FC24C;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fc1c0
	if (cr6.eq) goto loc_826FC1C0;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// b 0x826fc1cc
	goto loc_826FC1CC;
loc_826FC1C0:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_826FC1CC:
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FC1F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x826fc24c
	if (cr6.eq) goto loc_826FC24C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FC218;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826fc240
	if (!cr6.eq) goto loc_826FC240;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FC240;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826FC240:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_826FC24C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826FC258"))) PPC_WEAK_FUNC(sub_826FC258);
PPC_FUNC_IMPL(__imp__sub_826FC258) {
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
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
	// lwz r11,-23636(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23636);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fc2e0
	if (cr6.eq) goto loc_826FC2E0;
	// lbz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 36);
	// rlwinm r8,r9,0,0,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826fc2e0
	if (cr6.eq) goto loc_826FC2E0;
	// lwz r11,656(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fc2b8
	if (cr6.eq) goto loc_826FC2B8;
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82764568
	ctx.lr = 0x826FC2A8;
	sub_82764568(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826FC2B8:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82764568
	ctx.lr = 0x826FC2D0;
	sub_82764568(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826FC2E0:
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

__attribute__((alias("__imp__sub_826FC2F4"))) PPC_WEAK_FUNC(sub_826FC2F4);
PPC_FUNC_IMPL(__imp__sub_826FC2F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FC2F8"))) PPC_WEAK_FUNC(sub_826FC2F8);
PPC_FUNC_IMPL(__imp__sub_826FC2F8) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x826FC300;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,36
	ctx.r3.s64 = 36;
	// bl 0x82130528
	ctx.lr = 0x826FC310;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fc330
	if (cr6.eq) goto loc_826FC330;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,128
	ctx.r5.s64 = 128;
	// li r4,3072
	ctx.r4.s64 = 3072;
	// bl 0x8276b950
	ctx.lr = 0x826FC32C;
	sub_8276B950(ctx, base);
	// b 0x826fc334
	goto loc_826FC334;
loc_826FC330:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826FC334:
	// bl 0x82760ed0
	ctx.lr = 0x826FC338;
	sub_82760ED0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,14992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14992);
	f0.f64 = double(temp.f32);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lvlx128 v63,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lfs f0,31308(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31308);
	f0.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f13,27640(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// lis r3,-32127
	ctx.r3.s64 = -2105475072;
	// lfs f12,12428(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 12428);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32127
	r11.s64 = -2105475072;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lfs f11,-29232(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -29232);
	ctx.f11.f64 = double(temp.f32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lis r7,-32127
	ctx.r7.s64 = -2105475072;
	// lfs f10,11368(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 11368);
	ctx.f10.f64 = double(temp.f32);
	// addi r6,r9,-20480
	ctx.r6.s64 = ctx.r9.s64 + -20480;
	// stfs f0,4184(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4184, temp.u32);
	// stfs f13,4180(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4180, temp.u32);
	// li r3,688
	ctx.r3.s64 = 688;
	// stfs f12,-16740(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + -16740, temp.u32);
	// stfs f11,-16744(r8)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r8.u32 + -16744, temp.u32);
	// stfs f10,4024(r7)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r7.u32 + 4024, temp.u32);
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82130528
	ctx.lr = 0x826FC3B4;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826fc3e0
	if (cr6.eq) goto loc_826FC3E0;
	// bl 0x82767728
	ctx.lr = 0x826FC3C4;
	sub_82767728(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r9,r10,18340
	ctx.r9.s64 = ctx.r10.s64 + 18340;
	// lfs f0,12880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12880);
	f0.f64 = double(temp.f32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stfs f0,672(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 672, temp.u32);
	// b 0x826fc3e4
	goto loc_826FC3E4;
loc_826FC3E0:
	// mr r31,r30
	r31.u64 = r30.u64;
loc_826FC3E4:
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// li r6,16384
	ctx.r6.s64 = 16384;
	// addi r9,r10,-24440
	ctx.r9.s64 = ctx.r10.s64 + -24440;
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r31,-23636(r11)
	PPC_STORE_U32(r11.u32 + -23636, r31.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r4,r8,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// bl 0x82768708
	ctx.lr = 0x826FC410;
	sub_82768708(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r7,4096
	ctx.r7.s64 = 4096;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,540(r31)
	PPC_STORE_U32(r31.u32 + 540, ctx.r7.u32);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826FC42C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82768960
	ctx.lr = 0x826FC438;
	sub_82768960(ctx, base);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stb r30,57(r31)
	PPC_STORE_U8(r31.u32 + 57, r30.u8);
	// stb r30,56(r31)
	PPC_STORE_U8(r31.u32 + 56, r30.u8);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stw r3,532(r31)
	PPC_STORE_U32(r31.u32 + 532, ctx.r3.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stb r30,58(r31)
	PPC_STORE_U8(r31.u32 + 58, r30.u8);
	// addi r28,r11,30576
	r28.s64 = r11.s64 + 30576;
	// lfs f0,14192(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14192);
	f0.f64 = double(temp.f32);
	// addi r4,r10,19848
	ctx.r4.s64 = ctx.r10.s64 + 19848;
	// stfs f0,536(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 536, temp.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ca540
	ctx.lr = 0x826FC470;
	sub_821CA540(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r27,r9,19612
	r27.s64 = ctx.r9.s64 + 19612;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x821ca540
	ctx.lr = 0x826FC484;
	sub_821CA540(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x821ca540
	ctx.lr = 0x826FC490;
	sub_821CA540(ctx, base);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r7,r8,18440
	ctx.r7.s64 = ctx.r8.s64 + 18440;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82767b70
	ctx.lr = 0x826FC4B0;
	sub_82767B70(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826FC4B8;
	sub_821C9A90(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826FC4C0;
	sub_821C9A90(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826FC4C8;
	sub_821C9A90(ctx, base);
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fc4dc
	if (cr6.eq) goto loc_826FC4DC;
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// b 0x826fc4e4
	goto loc_826FC4E4;
loc_826FC4DC:
	// addi r11,r1,84
	r11.s64 = ctx.r1.s64 + 84;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
loc_826FC4E4:
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fc4f8
	if (cr6.eq) goto loc_826FC4F8;
	// li r4,1024
	ctx.r4.s64 = 1024;
	// bl 0x82761e78
	ctx.lr = 0x826FC4F8;
	sub_82761E78(ctx, base);
loc_826FC4F8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8276acf8
	ctx.lr = 0x826FC500;
	sub_8276ACF8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826FC50C"))) PPC_WEAK_FUNC(sub_826FC50C);
PPC_FUNC_IMPL(__imp__sub_826FC50C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FC510"))) PPC_WEAK_FUNC(sub_826FC510);
PPC_FUNC_IMPL(__imp__sub_826FC510) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r11,-16640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -16640);
	// subf r10,r4,r11
	ctx.r10.s64 = r11.s64 - ctx.r4.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r3,r9,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FC528"))) PPC_WEAK_FUNC(sub_826FC528);
PPC_FUNC_IMPL(__imp__sub_826FC528) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,18740
	ctx.r9.s64 = ctx.r10.s64 + 18740;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FC544"))) PPC_WEAK_FUNC(sub_826FC544);
PPC_FUNC_IMPL(__imp__sub_826FC544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FC548"))) PPC_WEAK_FUNC(sub_826FC548);
PPC_FUNC_IMPL(__imp__sub_826FC548) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r10,r11,18740
	ctx.r10.s64 = r11.s64 + 18740;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FC558"))) PPC_WEAK_FUNC(sub_826FC558);
PPC_FUNC_IMPL(__imp__sub_826FC558) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_826FC580"))) PPC_WEAK_FUNC(sub_826FC580);
PPC_FUNC_IMPL(__imp__sub_826FC580) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FC584"))) PPC_WEAK_FUNC(sub_826FC584);
PPC_FUNC_IMPL(__imp__sub_826FC584) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FC588"))) PPC_WEAK_FUNC(sub_826FC588);
PPC_FUNC_IMPL(__imp__sub_826FC588) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_826FC5A4"))) PPC_WEAK_FUNC(sub_826FC5A4);
PPC_FUNC_IMPL(__imp__sub_826FC5A4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FC5A8"))) PPC_WEAK_FUNC(sub_826FC5A8);
PPC_FUNC_IMPL(__imp__sub_826FC5A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,1
	r11.s64 = 1;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// lwz r10,48(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_826FC5D0"))) PPC_WEAK_FUNC(sub_826FC5D0);
PPC_FUNC_IMPL(__imp__sub_826FC5D0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FC5D4"))) PPC_WEAK_FUNC(sub_826FC5D4);
PPC_FUNC_IMPL(__imp__sub_826FC5D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FC5D8"))) PPC_WEAK_FUNC(sub_826FC5D8);
PPC_FUNC_IMPL(__imp__sub_826FC5D8) {
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
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826fc60c
	if (cr6.eq) goto loc_826FC60C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FC60C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826FC60C:
	// li r11,0
	r11.s64 = 0;
	// stb r11,8(r31)
	PPC_STORE_U8(r31.u32 + 8, r11.u8);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826FC62C"))) PPC_WEAK_FUNC(sub_826FC62C);
PPC_FUNC_IMPL(__imp__sub_826FC62C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FC630"))) PPC_WEAK_FUNC(sub_826FC630);
PPC_FUNC_IMPL(__imp__sub_826FC630) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,18740
	ctx.r9.s64 = r11.s64 + 18740;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x826fc664
	if (cr6.eq) goto loc_826FC664;
	// bl 0x82130588
	ctx.lr = 0x826FC660;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826FC664:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826FC678"))) PPC_WEAK_FUNC(sub_826FC678);
PPC_FUNC_IMPL(__imp__sub_826FC678) {
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
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822ab970
	ctx.lr = 0x826FC694;
	sub_822AB970(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,19124
	ctx.r10.s64 = r11.s64 + 19124;
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

__attribute__((alias("__imp__sub_826FC6B8"))) PPC_WEAK_FUNC(sub_826FC6B8);
PPC_FUNC_IMPL(__imp__sub_826FC6B8) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r10,r11,19124
	ctx.r10.s64 = r11.s64 + 19124;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822a8d98
	ctx.lr = 0x826FC6DC;
	sub_822A8D98(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r9,19320
	ctx.r3.s64 = ctx.r9.s64 + 19320;
	// bl 0x82130000
	ctx.lr = 0x826FC6EC;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822a7f10
	ctx.lr = 0x826FC6F8;
	sub_822A7F10(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a9268
	ctx.lr = 0x826FC700;
	sub_822A9268(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826FC714"))) PPC_WEAK_FUNC(sub_826FC714);
PPC_FUNC_IMPL(__imp__sub_826FC714) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FC718"))) PPC_WEAK_FUNC(sub_826FC718);
PPC_FUNC_IMPL(__imp__sub_826FC718) {
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
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822abd10
	ctx.lr = 0x826FC740;
	sub_822ABD10(ctx, base);
	// li r3,8176
	ctx.r3.s64 = 8176;
	// bl 0x82130528
	ctx.lr = 0x826FC748;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fc758
	if (cr6.eq) goto loc_826FC758;
	// bl 0x8238f550
	ctx.lr = 0x826FC754;
	sub_8238F550(ctx, base);
	// b 0x826fc75c
	goto loc_826FC75C;
loc_826FC758:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826FC75C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r3,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r3.u32);
	// beq cr6,0x826fc780
	if (cr6.eq) goto loc_826FC780;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82390b18
	ctx.lr = 0x826FC774;
	sub_82390B18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826fc798
	if (!cr6.eq) goto loc_826FC798;
loc_826FC780:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r11,-18844
	r30.s64 = r11.s64 + -18844;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82390b18
	ctx.lr = 0x826FC798;
	sub_82390B18(ctx, base);
loc_826FC798:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822aad78
	ctx.lr = 0x826FC7A4;
	sub_822AAD78(ctx, base);
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

__attribute__((alias("__imp__sub_826FC7C0"))) PPC_WEAK_FUNC(sub_826FC7C0);
PPC_FUNC_IMPL(__imp__sub_826FC7C0) {
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
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822abd10
	ctx.lr = 0x826FC7E8;
	sub_822ABD10(ctx, base);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826fc814
	if (!cr6.eq) goto loc_826FC814;
	// li r3,8176
	ctx.r3.s64 = 8176;
	// bl 0x82130528
	ctx.lr = 0x826FC7FC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fc80c
	if (cr6.eq) goto loc_826FC80C;
	// bl 0x8238f550
	ctx.lr = 0x826FC808;
	sub_8238F550(ctx, base);
	// b 0x826fc810
	goto loc_826FC810;
loc_826FC80C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826FC810:
	// stw r3,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r3.u32);
loc_826FC814:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x8238ee58
	ctx.lr = 0x826FC820;
	sub_8238EE58(ctx, base);
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

__attribute__((alias("__imp__sub_826FC83C"))) PPC_WEAK_FUNC(sub_826FC83C);
PPC_FUNC_IMPL(__imp__sub_826FC83C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FC840"))) PPC_WEAK_FUNC(sub_826FC840);
PPC_FUNC_IMPL(__imp__sub_826FC840) {
	PPC_FUNC_PROLOGUE();
	// b 0x822aa960
	sub_822AA960(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826FC844"))) PPC_WEAK_FUNC(sub_826FC844);
PPC_FUNC_IMPL(__imp__sub_826FC844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FC848"))) PPC_WEAK_FUNC(sub_826FC848);
PPC_FUNC_IMPL(__imp__sub_826FC848) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fc868
	if (cr6.eq) goto loc_826FC868;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fc868
	if (cr6.eq) goto loc_826FC868;
	// lfs f1,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_826FC868:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FC874"))) PPC_WEAK_FUNC(sub_826FC874);
PPC_FUNC_IMPL(__imp__sub_826FC874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FC878"))) PPC_WEAK_FUNC(sub_826FC878);
PPC_FUNC_IMPL(__imp__sub_826FC878) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fc898
	if (cr6.eq) goto loc_826FC898;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fc898
	if (cr6.eq) goto loc_826FC898;
	// lfs f1,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_826FC898:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FC8A4"))) PPC_WEAK_FUNC(sub_826FC8A4);
PPC_FUNC_IMPL(__imp__sub_826FC8A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FC8A8"))) PPC_WEAK_FUNC(sub_826FC8A8);
PPC_FUNC_IMPL(__imp__sub_826FC8A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fc8c8
	if (cr6.eq) goto loc_826FC8C8;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fc8c8
	if (cr6.eq) goto loc_826FC8C8;
	// lfs f1,152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 152);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_826FC8C8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FC8D4"))) PPC_WEAK_FUNC(sub_826FC8D4);
PPC_FUNC_IMPL(__imp__sub_826FC8D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FC8D8"))) PPC_WEAK_FUNC(sub_826FC8D8);
PPC_FUNC_IMPL(__imp__sub_826FC8D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fc8f8
	if (cr6.eq) goto loc_826FC8F8;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fc8f8
	if (cr6.eq) goto loc_826FC8F8;
	// lfs f1,24(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_826FC8F8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FC904"))) PPC_WEAK_FUNC(sub_826FC904);
PPC_FUNC_IMPL(__imp__sub_826FC904) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FC908"))) PPC_WEAK_FUNC(sub_826FC908);
PPC_FUNC_IMPL(__imp__sub_826FC908) {
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
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fc954
	if (cr6.eq) goto loc_826FC954;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826fc954
	if (cr6.eq) goto loc_826FC954;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x826fc954
	if (cr6.eq) goto loc_826FC954;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FC954;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826FC954:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a7de0
	ctx.lr = 0x826FC95C;
	sub_822A7DE0(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826FC970"))) PPC_WEAK_FUNC(sub_826FC970);
PPC_FUNC_IMPL(__imp__sub_826FC970) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,19124
	ctx.r10.s64 = r11.s64 + 19124;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822a8d98
	ctx.lr = 0x826FC99C;
	sub_822A8D98(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r9,19320
	ctx.r3.s64 = ctx.r9.s64 + 19320;
	// bl 0x82130000
	ctx.lr = 0x826FC9AC;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822a7f10
	ctx.lr = 0x826FC9B8;
	sub_822A7F10(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a9268
	ctx.lr = 0x826FC9C0;
	sub_822A9268(ctx, base);
	// clrlwi r8,r30,31
	ctx.r8.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826fc9d8
	if (cr6.eq) goto loc_826FC9D8;
	// bl 0x82130588
	ctx.lr = 0x826FC9D4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826FC9D8:
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

__attribute__((alias("__imp__sub_826FC9F0"))) PPC_WEAK_FUNC(sub_826FC9F0);
PPC_FUNC_IMPL(__imp__sub_826FC9F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lwz r4,52(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x827441b0
	ctx.lr = 0x826FCA14;
	sub_827441B0(ctx, base);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// lwz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// bl 0x82744678
	ctx.lr = 0x826FCA28;
	sub_82744678(ctx, base);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// stw r31,128(r3)
	PPC_STORE_U32(ctx.r3.u32 + 128, r31.u32);
	// li r11,1
	r11.s64 = 1;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stb r11,818(r9)
	PPC_STORE_U8(ctx.r9.u32 + 818, r11.u8);
	// lbz r8,464(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 464);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826fcaac
	if (cr6.eq) goto loc_826FCAAC;
	// addi r11,r31,288
	r11.s64 = r31.s64 + 288;
	// li r10,16
	ctx.r10.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,48
	ctx.r8.s64 = 48;
	// li r7,432
	ctx.r7.s64 = 432;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,448
	ctx.r6.s64 = 448;
	// lvx128 v62,r11,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lvx128 v59,r31,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v58,r31,r6
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826FCAAC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r30,68(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r10.u32);
	// lwz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826FCACC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r8,464(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 464);
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826fcb04
	if (cr6.eq) goto loc_826FCB04;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lfs f2,30712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30712);
	ctx.f2.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822a9930
	ctx.lr = 0x826FCB04;
	sub_822A9930(ctx, base);
loc_826FCB04:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822aebe0
	ctx.lr = 0x826FCB0C;
	sub_822AEBE0(ctx, base);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x82350570
	ctx.lr = 0x826FCB14;
	sub_82350570(ctx, base);
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

__attribute__((alias("__imp__sub_826FCB2C"))) PPC_WEAK_FUNC(sub_826FCB2C);
PPC_FUNC_IMPL(__imp__sub_826FCB2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FCB30"))) PPC_WEAK_FUNC(sub_826FCB30);
PPC_FUNC_IMPL(__imp__sub_826FCB30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r10,r11,-24420
	ctx.r10.s64 = r11.s64 + -24420;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r8,92(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// lfs f0,-15468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -15468);
	f0.f64 = double(temp.f32);
	// lfs f13,-28880(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28880);
	ctx.f13.f64 = double(temp.f32);
	// lwz r7,136(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 136);
	// lfs f12,116(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lfs f10,120(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 120);
	ctx.f10.f64 = double(temp.f32);
	// stfs f11,116(r7)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r7.u32 + 116, temp.u32);
	// fmsubs f9,f10,f0,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64 - ctx.f11.f64));
	// fmadds f8,f9,f13,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f8,120(r7)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r7.u32 + 120, temp.u32);
	// lwz r6,48(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r5,92(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 92);
	// lwz r4,140(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 140);
	// lfs f7,120(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 120);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,116(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 116);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 * f0.f64));
	// fmsubs f4,f7,f0,f5
	ctx.f4.f64 = double(float(ctx.f7.f64 * f0.f64 - ctx.f5.f64));
	// stfs f5,116(r4)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r4.u32 + 116, temp.u32);
	// fmadds f3,f4,f13,f5
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f3,120(r4)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r4.u32 + 120, temp.u32);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_826FCBC8"))) PPC_WEAK_FUNC(sub_826FCBC8);
PPC_FUNC_IMPL(__imp__sub_826FCBC8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FCBCC"))) PPC_WEAK_FUNC(sub_826FCBCC);
PPC_FUNC_IMPL(__imp__sub_826FCBCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FCBD0"))) PPC_WEAK_FUNC(sub_826FCBD0);
PPC_FUNC_IMPL(__imp__sub_826FCBD0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826FCBD8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822a9d98
	ctx.lr = 0x826FCBE4;
	sub_822A9D98(ctx, base);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fcc00
	if (cr6.eq) goto loc_826FCC00;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FCC00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826FCC00:
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x826fcd40
	if (!cr6.eq) goto loc_826FCD40;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fcc58
	if (cr6.eq) goto loc_826FCC58;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826fcc58
	if (cr6.eq) goto loc_826FCC58;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826fcc58
	if (!cr6.eq) goto loc_826FCC58;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r8,1
	ctx.r8.s64 = 1;
	// sth r8,44(r11)
	PPC_STORE_U16(r11.u32 + 44, ctx.r8.u16);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,152(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 152, temp.u32);
	// stfs f0,156(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 156, temp.u32);
	// stfs f0,160(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 160, temp.u32);
	// stfs f13,164(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 164, temp.u32);
loc_826FCC58:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-3660(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3660);
	// bl 0x8226adb0
	ctx.lr = 0x826FCC68;
	sub_8226ADB0(ctx, base);
	// lbz r10,178(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 178);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fcd40
	if (cr6.eq) goto loc_826FCD40;
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// ble cr6,0x826fcd40
	if (!cr6.gt) goto loc_826FCD40;
	// bl 0x823bbf80
	ctx.lr = 0x826FCC84;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826fcd40
	if (!cr6.eq) goto loc_826FCD40;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x8238f998
	ctx.lr = 0x826FCC98;
	sub_8238F998(ctx, base);
	// bl 0x823964a8
	ctx.lr = 0x826FCC9C;
	sub_823964A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826fcd40
	if (!cr6.eq) goto loc_826FCD40;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,17268(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a8108
	ctx.lr = 0x826FCCB8;
	sub_822A8108(ctx, base);
	// addi r29,r3,48
	r29.s64 = ctx.r3.s64 + 48;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a39c8
	ctx.lr = 0x826FCCC4;
	sub_822A39C8(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x826FCCC8;
	sub_822A8108(ctx, base);
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// lfs f0,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	f0.f64 = double(temp.f32);
	// lis r9,-32248
	ctx.r9.s64 = -2113404928;
	// lfs f13,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f9,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f7,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// lfs f0,-11364(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -11364);
	f0.f64 = double(temp.f32);
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fcmpu cr6,f3,f0
	cr6.compare(ctx.f3.f64, f0.f64);
	// ble cr6,0x826fcd40
	if (!cr6.gt) goto loc_826FCD40;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r10,178(r31)
	PPC_STORE_U8(r31.u32 + 178, ctx.r10.u8);
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826FCD28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r8,19344
	ctx.r3.s64 = ctx.r8.s64 + 19344;
	// bl 0x82130000
	ctx.lr = 0x826FCD38;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822abd38
	ctx.lr = 0x826FCD40;
	sub_822ABD38(ctx, base);
loc_826FCD40:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826FCD48"))) PPC_WEAK_FUNC(sub_826FCD48);
PPC_FUNC_IMPL(__imp__sub_826FCD48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r11,-16628(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -16628);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x826fcd60
	if (!cr6.eq) goto loc_826FCD60;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_826FCD60:
	// b 0x826fc510
	sub_826FC510(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826FCD64"))) PPC_WEAK_FUNC(sub_826FCD64);
PPC_FUNC_IMPL(__imp__sub_826FCD64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FCD68"))) PPC_WEAK_FUNC(sub_826FCD68);
PPC_FUNC_IMPL(__imp__sub_826FCD68) {
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
	// addi r9,r11,-30128
	ctx.r9.s64 = r11.s64 + -30128;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x826fcd9c
	if (cr6.eq) goto loc_826FCD9C;
	// bl 0x82130588
	ctx.lr = 0x826FCD98;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826FCD9C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826FCDB0"))) PPC_WEAK_FUNC(sub_826FCDB0);
PPC_FUNC_IMPL(__imp__sub_826FCDB0) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r31,132
	ctx.r3.s64 = r31.s64 + 132;
	// addi r10,r11,19804
	ctx.r10.s64 = r11.s64 + 19804;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8254ab20
	ctx.lr = 0x826FCDD8;
	sub_8254AB20(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,-30128
	ctx.r8.s64 = ctx.r9.s64 + -30128;
	// stw r8,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r8.u32);
	// stw r8,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r8.u32);
	// bl 0x826fc548
	ctx.lr = 0x826FCDF0;
	sub_826FC548(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826FCE04"))) PPC_WEAK_FUNC(sub_826FCE04);
PPC_FUNC_IMPL(__imp__sub_826FCE04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FCE08"))) PPC_WEAK_FUNC(sub_826FCE08);
PPC_FUNC_IMPL(__imp__sub_826FCE08) {
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
	ctx.lr = 0x826FCE10;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,224
	ctx.r3.s64 = 224;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x82130528
	ctx.lr = 0x826FCE28;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fce38
	if (cr6.eq) goto loc_826FCE38;
	// bl 0x82761770
	ctx.lr = 0x826FCE34;
	sub_82761770(ctx, base);
	// b 0x826fce3c
	goto loc_826FCE3C;
loc_826FCE38:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826FCE3C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,140(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 140, temp.u32);
	// bl 0x826fc558
	ctx.lr = 0x826FCE5C;
	sub_826FC558(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826FCE64"))) PPC_WEAK_FUNC(sub_826FCE64);
PPC_FUNC_IMPL(__imp__sub_826FCE64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FCE68"))) PPC_WEAK_FUNC(sub_826FCE68);
PPC_FUNC_IMPL(__imp__sub_826FCE68) {
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
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826fceb8
	if (cr6.eq) goto loc_826FCEB8;
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fceb8
	if (cr6.eq) goto loc_826FCEB8;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r3,-23636(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -23636);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fceb8
	if (cr6.eq) goto loc_826FCEB8;
	// lbz r11,36(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 36);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fceb8
	if (cr6.eq) goto loc_826FCEB8;
	// bl 0x8254dfc0
	ctx.lr = 0x826FCEB8;
	sub_8254DFC0(ctx, base);
loc_826FCEB8:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r11,0
	r11.s64 = 0;
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fcefc
	if (cr6.eq) goto loc_826FCEFC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FCEDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826fcefc
	if (cr6.eq) goto loc_826FCEFC;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FCEFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826FCEFC:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826FCF10"))) PPC_WEAK_FUNC(sub_826FCF10);
PPC_FUNC_IMPL(__imp__sub_826FCF10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addi r3,r11,152
	ctx.r3.s64 = r11.s64 + 152;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FCF1C"))) PPC_WEAK_FUNC(sub_826FCF1C);
PPC_FUNC_IMPL(__imp__sub_826FCF1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FCF20"))) PPC_WEAK_FUNC(sub_826FCF20);
PPC_FUNC_IMPL(__imp__sub_826FCF20) {
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
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r11,-23636(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23636);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fcf88
	if (cr6.eq) goto loc_826FCF88;
	// lbz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 36);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826fcf88
	if (cr6.eq) goto loc_826FCF88;
	// lwz r4,48(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fcf70
	if (cr6.eq) goto loc_826FCF70;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8254dfd8
	ctx.lr = 0x826FCF64;
	sub_8254DFD8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fcf88
	if (cr6.eq) goto loc_826FCF88;
loc_826FCF70:
	// li r11,1
	r11.s64 = 1;
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
loc_826FCF88:
	// li r11,0
	r11.s64 = 0;
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

__attribute__((alias("__imp__sub_826FCFA0"))) PPC_WEAK_FUNC(sub_826FCFA0);
PPC_FUNC_IMPL(__imp__sub_826FCFA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FCFC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826fcfe8
	if (cr6.eq) goto loc_826FCFE8;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FCFE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826FCFE8:
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// bl 0x82761878
	ctx.lr = 0x826FCFF4;
	sub_82761878(ctx, base);
	// addi r4,r31,32
	ctx.r4.s64 = r31.s64 + 32;
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// bl 0x82761878
	ctx.lr = 0x826FD000;
	sub_82761878(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r7,r31,132
	ctx.r7.s64 = r31.s64 + 132;
	// addi r5,r31,96
	ctx.r5.s64 = r31.s64 + 96;
	// addi r4,r31,64
	ctx.r4.s64 = r31.s64 + 64;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82760fb8
	ctx.lr = 0x826FD020;
	sub_82760FB8(ctx, base);
	// lwz r8,48(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r9,208(r8)
	PPC_STORE_U8(ctx.r8.u32 + 208, ctx.r9.u8);
	// lwz r3,-23636(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -23636);
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826FD048;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// stw r5,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r5.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826FD064"))) PPC_WEAK_FUNC(sub_826FD064);
PPC_FUNC_IMPL(__imp__sub_826FD064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FD068"))) PPC_WEAK_FUNC(sub_826FD068);
PPC_FUNC_IMPL(__imp__sub_826FD068) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,164(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 164);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// lfs f2,31016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,14988(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14988);
	ctx.f1.f64 = double(temp.f32);
	// b 0x826fc258
	sub_826FC258(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826FD088"))) PPC_WEAK_FUNC(sub_826FD088);
PPC_FUNC_IMPL(__imp__sub_826FD088) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// addi r4,r9,-16624
	ctx.r4.s64 = ctx.r9.s64 + -16624;
	// lfs f2,31016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	ctx.f1.f64 = double(temp.f32);
	// b 0x826fc258
	sub_826FC258(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826FD0A4"))) PPC_WEAK_FUNC(sub_826FD0A4);
PPC_FUNC_IMPL(__imp__sub_826FD0A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FD0A8"))) PPC_WEAK_FUNC(sub_826FD0A8);
PPC_FUNC_IMPL(__imp__sub_826FD0A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// addi r4,r9,-16616
	ctx.r4.s64 = ctx.r9.s64 + -16616;
	// lfs f2,31016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	ctx.f1.f64 = double(temp.f32);
	// b 0x826fc258
	sub_826FC258(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826FD0C4"))) PPC_WEAK_FUNC(sub_826FD0C4);
PPC_FUNC_IMPL(__imp__sub_826FD0C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FD0C8"))) PPC_WEAK_FUNC(sub_826FD0C8);
PPC_FUNC_IMPL(__imp__sub_826FD0C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// addi r4,r9,-16608
	ctx.r4.s64 = ctx.r9.s64 + -16608;
	// lfs f2,31016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	ctx.f1.f64 = double(temp.f32);
	// b 0x826fc258
	sub_826FC258(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826FD0E4"))) PPC_WEAK_FUNC(sub_826FD0E4);
PPC_FUNC_IMPL(__imp__sub_826FD0E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FD0E8"))) PPC_WEAK_FUNC(sub_826FD0E8);
PPC_FUNC_IMPL(__imp__sub_826FD0E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// addi r4,r9,-16600
	ctx.r4.s64 = ctx.r9.s64 + -16600;
	// lfs f2,31016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,14988(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	ctx.f1.f64 = double(temp.f32);
	// b 0x826fc258
	sub_826FC258(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826FD104"))) PPC_WEAK_FUNC(sub_826FD104);
PPC_FUNC_IMPL(__imp__sub_826FD104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FD108"))) PPC_WEAK_FUNC(sub_826FD108);
PPC_FUNC_IMPL(__imp__sub_826FD108) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826fd124
	if (cr6.eq) goto loc_826FD124;
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826fd128
	if (!cr6.eq) goto loc_826FD128;
loc_826FD124:
	// li r11,0
	r11.s64 = 0;
loc_826FD128:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FD130"))) PPC_WEAK_FUNC(sub_826FD130);
PPC_FUNC_IMPL(__imp__sub_826FD130) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826fd14c
	if (cr6.eq) goto loc_826FD14C;
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826fd150
	if (!cr6.eq) goto loc_826FD150;
loc_826FD14C:
	// li r11,0
	r11.s64 = 0;
loc_826FD150:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FD158"))) PPC_WEAK_FUNC(sub_826FD158);
PPC_FUNC_IMPL(__imp__sub_826FD158) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x826FD160;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826fc528
	ctx.lr = 0x826FD16C;
	sub_826FC528(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r9,r11,19804
	ctx.r9.s64 = r11.s64 + 19804;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r10,12064
	r29.s64 = ctx.r10.s64 + 12064;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// addi r11,r31,64
	r11.s64 = r31.s64 + 64;
	// stw r29,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r29.u32);
	// stw r30,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r30.u32);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82761858
	ctx.lr = 0x826FD19C;
	sub_82761858(ctx, base);
	// stw r29,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r29.u32);
	// stw r30,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r30.u32);
	// addi r11,r31,96
	r11.s64 = r31.s64 + 96;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x82761858
	ctx.lr = 0x826FD1B0;
	sub_82761858(ctx, base);
	// stw r30,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r30.u32);
	// addi r3,r31,132
	ctx.r3.s64 = r31.s64 + 132;
	// bl 0x8254ab98
	ctx.lr = 0x826FD1BC;
	sub_8254AB98(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r8,16
	ctx.r8.s64 = 16;
	// li r7,32
	ctx.r7.s64 = 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826FD1DC"))) PPC_WEAK_FUNC(sub_826FD1DC);
PPC_FUNC_IMPL(__imp__sub_826FD1DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FD1E0"))) PPC_WEAK_FUNC(sub_826FD1E0);
PPC_FUNC_IMPL(__imp__sub_826FD1E0) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r31,132
	ctx.r3.s64 = r31.s64 + 132;
	// addi r10,r11,19804
	ctx.r10.s64 = r11.s64 + 19804;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8254ab20
	ctx.lr = 0x826FD210;
	sub_8254AB20(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,-30128
	ctx.r8.s64 = ctx.r9.s64 + -30128;
	// stw r8,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r8.u32);
	// stw r8,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r8.u32);
	// bl 0x826fc548
	ctx.lr = 0x826FD228;
	sub_826FC548(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x826fd240
	if (cr6.eq) goto loc_826FD240;
	// bl 0x82130588
	ctx.lr = 0x826FD23C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826FD240:
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

__attribute__((alias("__imp__sub_826FD258"))) PPC_WEAK_FUNC(sub_826FD258);
PPC_FUNC_IMPL(__imp__sub_826FD258) {
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
	// bl 0x826fce68
	ctx.lr = 0x826FD270;
	sub_826FCE68(ctx, base);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fd290
	if (cr6.eq) goto loc_826FD290;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FD290;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826FD290:
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// bl 0x826fc588
	ctx.lr = 0x826FD2A0;
	sub_826FC588(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826FD2B4"))) PPC_WEAK_FUNC(sub_826FD2B4);
PPC_FUNC_IMPL(__imp__sub_826FD2B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FD2B8"))) PPC_WEAK_FUNC(sub_826FD2B8);
PPC_FUNC_IMPL(__imp__sub_826FD2B8) {
	PPC_FUNC_PROLOGUE();
	// b 0x826fce68
	sub_826FCE68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826FD2BC"))) PPC_WEAK_FUNC(sub_826FD2BC);
PPC_FUNC_IMPL(__imp__sub_826FD2BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FD2C0"))) PPC_WEAK_FUNC(sub_826FD2C0);
PPC_FUNC_IMPL(__imp__sub_826FD2C0) {
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
	// bl 0x826fc5d8
	ctx.lr = 0x826FD2D8;
	sub_826FC5D8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fce68
	ctx.lr = 0x826FD2E0;
	sub_826FCE68(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826FD2F4"))) PPC_WEAK_FUNC(sub_826FD2F4);
PPC_FUNC_IMPL(__imp__sub_826FD2F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FD2F8"))) PPC_WEAK_FUNC(sub_826FD2F8);
PPC_FUNC_IMPL(__imp__sub_826FD2F8) {
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
	// bl 0x82130000
	ctx.lr = 0x826FD310;
	sub_82130000(ctx, base);
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826fd3f8
	if (cr6.eq) goto loc_826FD3F8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fcf20
	ctx.lr = 0x826FD324;
	sub_826FCF20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fd3f8
	if (cr6.eq) goto loc_826FD3F8;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x826fd358
	if (!cr6.eq) goto loc_826FD358;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fcfa0
	ctx.lr = 0x826FD344;
	sub_826FCFA0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_826FD358:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x826fd3d4
	if (!cr6.eq) goto loc_826FD3D4;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lbz r11,25(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 25);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// beq cr6,0x826fd380
	if (cr6.eq) goto loc_826FD380;
	// lbz r11,25(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 25);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x826fd384
	if (!cr6.eq) goto loc_826FD384;
loc_826FD380:
	// li r11,1
	r11.s64 = 1;
loc_826FD384:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826fd3b8
	if (!cr6.eq) goto loc_826FD3B8;
	// lwz r11,172(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 172);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826fd3b8
	if (cr6.eq) goto loc_826FD3B8;
	// li r11,4
	r11.s64 = 4;
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_826FD3B8:
	// li r11,3
	r11.s64 = 3;
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_826FD3D4:
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// bne cr6,0x826fd3f8
	if (!cr6.eq) goto loc_826FD3F8;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FD3F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r9.u32);
loc_826FD3F8:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826FD40C"))) PPC_WEAK_FUNC(sub_826FD40C);
PPC_FUNC_IMPL(__imp__sub_826FD40C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FD410"))) PPC_WEAK_FUNC(sub_826FD410);
PPC_FUNC_IMPL(__imp__sub_826FD410) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,16
	r11.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// stvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826fcf20
	ctx.lr = 0x826FD440;
	sub_826FCF20(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826fd468
	if (cr6.eq) goto loc_826FD468;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fcfa0
	ctx.lr = 0x826FD454;
	sub_826FCFA0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_826FD468:
	// li r11,1
	r11.s64 = 1;
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826FD484"))) PPC_WEAK_FUNC(sub_826FD484);
PPC_FUNC_IMPL(__imp__sub_826FD484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FD488"))) PPC_WEAK_FUNC(sub_826FD488);
PPC_FUNC_IMPL(__imp__sub_826FD488) {
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
	// bl 0x826fcf20
	ctx.lr = 0x826FD4A0;
	sub_826FCF20(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fd4e8
	if (cr6.eq) goto loc_826FD4E8;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FD4C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826fd4e0
	if (cr6.eq) goto loc_826FD4E0;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FD4E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826FD4E0:
	// li r11,0
	r11.s64 = 0;
	// b 0x826fd4ec
	goto loc_826FD4EC;
loc_826FD4E8:
	// li r11,5
	r11.s64 = 5;
loc_826FD4EC:
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826FD504"))) PPC_WEAK_FUNC(sub_826FD504);
PPC_FUNC_IMPL(__imp__sub_826FD504) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FD508"))) PPC_WEAK_FUNC(sub_826FD508);
PPC_FUNC_IMPL(__imp__sub_826FD508) {
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
	ctx.lr = 0x826FD510;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,-23636(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23636);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fd5b4
	if (cr6.eq) goto loc_826FD5B4;
	// lbz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 36);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826fd5b4
	if (cr6.eq) goto loc_826FD5B4;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fd554
	if (cr6.eq) goto loc_826FD554;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// b 0x826fd560
	goto loc_826FD560;
loc_826FD554:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_826FD560:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8254e2e0
	ctx.lr = 0x826FD56C;
	sub_8254E2E0(ctx, base);
	// addi r4,r30,132
	ctx.r4.s64 = r30.s64 + 132;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8254ad08
	ctx.lr = 0x826FD578;
	sub_8254AD08(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r5,164(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 164);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,56(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// lfs f1,14988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	ctx.f1.f64 = double(temp.f32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826FD5A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// bne cr6,0x826fd5c0
	if (!cr6.eq) goto loc_826FD5C0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8254e338
	ctx.lr = 0x826FD5B4;
	sub_8254E338(ctx, base);
loc_826FD5B4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
loc_826FD5C0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FD5DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826fd604
	if (!cr6.eq) goto loc_826FD604;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FD604;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826FD604:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8254e338
	ctx.lr = 0x826FD60C;
	sub_8254E338(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826FD618"))) PPC_WEAK_FUNC(sub_826FD618);
PPC_FUNC_IMPL(__imp__sub_826FD618) {
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
	ctx.lr = 0x826FD620;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,-23636(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23636);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fd6c8
	if (cr6.eq) goto loc_826FD6C8;
	// lbz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 36);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826fd6c8
	if (cr6.eq) goto loc_826FD6C8;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fd664
	if (cr6.eq) goto loc_826FD664;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// b 0x826fd670
	goto loc_826FD670;
loc_826FD664:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_826FD670:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8254e2e0
	ctx.lr = 0x826FD67C;
	sub_8254E2E0(ctx, base);
	// addi r4,r30,132
	ctx.r4.s64 = r30.s64 + 132;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8254ad08
	ctx.lr = 0x826FD688;
	sub_8254AD08(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r10,-16616
	ctx.r5.s64 = ctx.r10.s64 + -16616;
	// lwz r8,56(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lfs f1,14988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826FD6B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// bne cr6,0x826fd6d4
	if (!cr6.eq) goto loc_826FD6D4;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8254e338
	ctx.lr = 0x826FD6C8;
	sub_8254E338(ctx, base);
loc_826FD6C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
loc_826FD6D4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FD6F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826fd718
	if (!cr6.eq) goto loc_826FD718;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FD718;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826FD718:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8254e338
	ctx.lr = 0x826FD720;
	sub_8254E338(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826FD72C"))) PPC_WEAK_FUNC(sub_826FD72C);
PPC_FUNC_IMPL(__imp__sub_826FD72C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FD730"))) PPC_WEAK_FUNC(sub_826FD730);
PPC_FUNC_IMPL(__imp__sub_826FD730) {
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
	ctx.lr = 0x826FD738;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32114
	r11.s64 = -2104623104;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,-23636(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -23636);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fd808
	if (cr6.eq) goto loc_826FD808;
	// lbz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 36);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826fd808
	if (cr6.eq) goto loc_826FD808;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fd778
	if (cr6.eq) goto loc_826FD778;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// b 0x826fd784
	goto loc_826FD784;
loc_826FD778:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_826FD784:
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f1,14988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	ctx.f1.f64 = double(temp.f32);
	// lwz r9,56(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826FD7B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x826fd808
	if (cr6.eq) goto loc_826FD808;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FD7D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826fd808
	if (cr6.eq) goto loc_826FD808;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FD7FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_826FD808:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826FD814"))) PPC_WEAK_FUNC(sub_826FD814);
PPC_FUNC_IMPL(__imp__sub_826FD814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FD818"))) PPC_WEAK_FUNC(sub_826FD818);
PPC_FUNC_IMPL(__imp__sub_826FD818) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x826fd488
	ctx.lr = 0x826FD830;
	sub_826FD488(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r11,16
	r11.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82130000
	ctx.lr = 0x826FD84C;
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

__attribute__((alias("__imp__sub_826FD860"))) PPC_WEAK_FUNC(sub_826FD860);
PPC_FUNC_IMPL(__imp__sub_826FD860) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x826fd878
	if (!cr6.gt) goto loc_826FD878;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_826FD878:
	// subfc r11,r10,r11
	xer.ca = r11.u32 >= ctx.r10.u32;
	r11.s64 = r11.s64 - ctx.r10.s64;
	// subfe r3,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r3.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FD884"))) PPC_WEAK_FUNC(sub_826FD884);
PPC_FUNC_IMPL(__imp__sub_826FD884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FD888"))) PPC_WEAK_FUNC(sub_826FD888);
PPC_FUNC_IMPL(__imp__sub_826FD888) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// lwz r3,224(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 224);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x8213c218
	sub_8213C218(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826FD89C"))) PPC_WEAK_FUNC(sub_826FD89C);
PPC_FUNC_IMPL(__imp__sub_826FD89C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FD8A0"))) PPC_WEAK_FUNC(sub_826FD8A0);
PPC_FUNC_IMPL(__imp__sub_826FD8A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,40(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// rlwinm r11,r4,29,3,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r9,r4,27
	ctx.r9.u64 = ctx.r4.u32 & 0x1F;
	// li r8,1
	ctx.r8.s64 = 1;
	// slw r7,r8,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// lwzx r6,r10,r11
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// andc r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 & ~ctx.r7.u64;
	// stwx r5,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r5.u32);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// or r3,r4,r7
	ctx.r3.u64 = ctx.r4.u64 | ctx.r7.u64;
	// stwx r3,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FD8D4"))) PPC_WEAK_FUNC(sub_826FD8D4);
PPC_FUNC_IMPL(__imp__sub_826FD8D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FD8D8"))) PPC_WEAK_FUNC(sub_826FD8D8);
PPC_FUNC_IMPL(__imp__sub_826FD8D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// rlwinm r10,r4,29,3,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r9,r4,27
	ctx.r9.u64 = ctx.r4.u32 & 0x1F;
	// li r8,1
	ctx.r8.s64 = 1;
	// slw r7,r8,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// lwzx r6,r10,r11
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// and r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 & ctx.r7.u64;
	// cntlzw r4,r5
	ctx.r4.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r3,r4,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// xori r3,r3,1
	ctx.r3.u64 = ctx.r3.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FD904"))) PPC_WEAK_FUNC(sub_826FD904);
PPC_FUNC_IMPL(__imp__sub_826FD904) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FD908"))) PPC_WEAK_FUNC(sub_826FD908);
PPC_FUNC_IMPL(__imp__sub_826FD908) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FD92C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826FD940;
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

__attribute__((alias("__imp__sub_826FD954"))) PPC_WEAK_FUNC(sub_826FD954);
PPC_FUNC_IMPL(__imp__sub_826FD954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FD958"))) PPC_WEAK_FUNC(sub_826FD958);
PPC_FUNC_IMPL(__imp__sub_826FD958) {
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
	ctx.lr = 0x826FD960;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lis r31,-32111
	r31.s64 = -2104426496;
	// lwz r11,-24352(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24352);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826fd9a4
	if (!cr6.eq) goto loc_826FD9A4;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// stw r11,-24352(r10)
	PPC_STORE_U32(ctx.r10.u32 + -24352, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r9,20228
	ctx.r3.s64 = ctx.r9.s64 + 20228;
	// bl 0x821c9790
	ctx.lr = 0x826FD9A0;
	sub_821C9790(ctx, base);
	// stw r3,-24356(r31)
	PPC_STORE_U32(r31.u32 + -24356, ctx.r3.u32);
loc_826FD9A4:
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stb r11,268(r29)
	PPC_STORE_U8(r29.u32 + 268, r11.u8);
	// beq cr6,0x826fd9fc
	if (cr6.eq) goto loc_826FD9FC;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826fd9f0
	if (cr6.eq) goto loc_826FD9F0;
	// lwz r11,-12012(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12012);
	// lwz r11,2256(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2256);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826fd9f0
	if (cr6.eq) goto loc_826FD9F0;
	// lwz r11,408(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 408);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x821c7d28
	ctx.lr = 0x826FD9E4;
	sub_821C7D28(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826fda18
	if (!cr6.eq) goto loc_826FDA18;
loc_826FD9F0:
	// lwz r4,-24356(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -24356);
	// lwz r3,-12012(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12012);
	// bl 0x821f0fc8
	ctx.lr = 0x826FD9FC;
	sub_821F0FC8(ctx, base);
loc_826FD9FC:
	// lwz r3,228(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 228);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fda10
	if (cr6.eq) goto loc_826FDA10;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x826FDA10;
	sub_8213C218(ctx, base);
loc_826FDA10:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826FDA18:
	// li r11,1
	r11.s64 = 1;
	// stb r11,268(r29)
	PPC_STORE_U8(r29.u32 + 268, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826FDA28"))) PPC_WEAK_FUNC(sub_826FDA28);
PPC_FUNC_IMPL(__imp__sub_826FDA28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-24400(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -24400);
	// lwz r3,228(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 228);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8213c218
	sub_8213C218(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826FDA44"))) PPC_WEAK_FUNC(sub_826FDA44);
PPC_FUNC_IMPL(__imp__sub_826FDA44) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FDA48"))) PPC_WEAK_FUNC(sub_826FDA48);
PPC_FUNC_IMPL(__imp__sub_826FDA48) {
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
	ctx.lr = 0x826FDA50;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,-12012(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -12012);
	// lwz r10,2256(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2256);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fda80
	if (cr6.eq) goto loc_826FDA80;
	// lwz r11,2260(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x826fda84
	if (!cr6.eq) goto loc_826FDA84;
loc_826FDA80:
	// li r11,0
	r11.s64 = 0;
loc_826FDA84:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fda9c
	if (cr6.eq) goto loc_826FDA9C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d924c
	return;
loc_826FDA9C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8270c2d8
	ctx.lr = 0x826FDAA4;
	sub_8270C2D8(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r11,20268
	ctx.r5.s64 = r11.s64 + 20268;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x826FDABC;
	sub_82137A08(ctx, base);
	// lwz r11,-12012(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -12012);
	// lwz r9,48(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// addi r5,r29,224
	ctx.r5.s64 = r29.s64 + 224;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,2232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2232);
	// lwz r3,16(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lwz r6,2220(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2220);
	// bl 0x8234a2c8
	ctx.lr = 0x826FDAE4;
	sub_8234A2C8(ctx, base);
	// lwz r11,-12012(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -12012);
	// lwz r10,2232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2232);
	// addi r7,r10,277
	ctx.r7.s64 = ctx.r10.s64 + 277;
	// rlwinm r6,r7,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r5,r6,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	// cntlzw r4,r5
	ctx.r4.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r3,r4,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// xori r3,r3,1
	ctx.r3.u64 = ctx.r3.u64 ^ 1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826FDB0C"))) PPC_WEAK_FUNC(sub_826FDB0C);
PPC_FUNC_IMPL(__imp__sub_826FDB0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FDB10"))) PPC_WEAK_FUNC(sub_826FDB10);
PPC_FUNC_IMPL(__imp__sub_826FDB10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826FDB18;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r31,1
	r31.s64 = 1;
	// addi r9,r8,40
	ctx.r9.s64 = ctx.r8.s64 + 40;
	// lwz r7,56(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// lwz r10,40(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	// rlwinm r11,r7,29,3,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r6,r7,27
	ctx.r6.u64 = ctx.r7.u32 & 0x1F;
	// slw r5,r31,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x20 ? 0 : (r31.u32 << (ctx.r6.u8 & 0x3F));
	// lwzx r4,r11,r10
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// or r3,r5,r4
	ctx.r3.u64 = ctx.r5.u64 | ctx.r4.u64;
	// stwx r3,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r3.u32);
	// lwz r10,232(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 232);
	// lwz r11,56(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lhz r5,12(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 12);
	// addi r7,r5,-1
	ctx.r7.s64 = ctx.r5.s64 + -1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x826fdb6c
	if (!cr6.eq) goto loc_826FDB6C;
	// li r11,0
	r11.s64 = 0;
	// b 0x826fdba8
	goto loc_826FDBA8;
loc_826FDB6C:
	// blt cr6,0x826fdba8
	if (cr6.lt) goto loc_826FDBA8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// addi r6,r7,1
	ctx.r6.s64 = ctx.r7.s64 + 1;
	// blt cr6,0x826fdb80
	if (cr6.lt) goto loc_826FDB80;
	// li r6,0
	ctx.r6.s64 = 0;
loc_826FDB80:
	// addi r4,r7,1
	ctx.r4.s64 = ctx.r7.s64 + 1;
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// divw r30,r11,r4
	r30.s32 = r11.s32 / ctx.r4.s32;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mullw r30,r30,r4
	r30.s64 = int64_t(r30.s32) * int64_t(ctx.r4.s32);
	// twllei r4,0
	// andc r4,r4,r10
	ctx.r4.u64 = ctx.r4.u64 & ~ctx.r10.u64;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// twlgei r4,-1
	// add r11,r11,r6
	r11.u64 = r11.u64 + ctx.r6.u64;
loc_826FDBA8:
	// stw r11,56(r8)
	PPC_STORE_U32(ctx.r8.u32 + 56, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x826fdc3c
	if (!cr6.gt) goto loc_826FDC3C;
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
loc_826FDBBC:
	// lwz r11,56(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// rlwinm r10,r11,29,3,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r9,r11,27
	ctx.r9.u64 = r11.u32 & 0x1F;
	// slw r9,r31,r9
	ctx.r9.u64 = ctx.r9.u8 & 0x20 ? 0 : (r31.u32 << (ctx.r9.u8 & 0x3F));
	// lwzx r10,r10,r4
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	// and r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 & ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826fdc3c
	if (cr6.eq) goto loc_826FDC3C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x826fdbf0
	if (!cr6.eq) goto loc_826FDBF0;
	// li r11,0
	r11.s64 = 0;
	// b 0x826fdc2c
	goto loc_826FDC2C;
loc_826FDBF0:
	// blt cr6,0x826fdc2c
	if (cr6.lt) goto loc_826FDC2C;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// addi r9,r7,1
	ctx.r9.s64 = ctx.r7.s64 + 1;
	// blt cr6,0x826fdc04
	if (cr6.lt) goto loc_826FDC04;
	// li r9,0
	ctx.r9.s64 = 0;
loc_826FDC04:
	// addi r30,r7,1
	r30.s64 = ctx.r7.s64 + 1;
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// divw r29,r11,r30
	r29.s32 = r11.s32 / r30.s32;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mullw r29,r29,r30
	r29.s64 = int64_t(r29.s32) * int64_t(r30.s32);
	// andc r10,r30,r10
	ctx.r10.u64 = r30.u64 & ~ctx.r10.u64;
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// twllei r30,0
	// twlgei r10,-1
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
loc_826FDC2C:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// stw r11,56(r8)
	PPC_STORE_U32(ctx.r8.u32 + 56, r11.u32);
	// cmpw cr6,r6,r5
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r5.s32, xer);
	// blt cr6,0x826fdbbc
	if (cr6.lt) goto loc_826FDBBC;
loc_826FDC3C:
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826FDC40"))) PPC_WEAK_FUNC(sub_826FDC40);
PPC_FUNC_IMPL(__imp__sub_826FDC40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,232(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 232);
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r4,r11
	ctx.r9.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r8,r9,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r7,8(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwzx r3,r7,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FDC5C"))) PPC_WEAK_FUNC(sub_826FDC5C);
PPC_FUNC_IMPL(__imp__sub_826FDC5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FDC60"))) PPC_WEAK_FUNC(sub_826FDC60);
PPC_FUNC_IMPL(__imp__sub_826FDC60) {
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// lwz r10,252(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 252);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r10,r10,96
	ctx.r10.s64 = ctx.r10.s64 + 96;
	// bne cr6,0x826fdc8c
	if (!cr6.eq) goto loc_826FDC8C;
	// addi r10,r11,208
	ctx.r10.s64 = r11.s64 + 208;
loc_826FDC8C:
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lfs f13,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r9,-31600
	ctx.r7.s64 = ctx.r9.s64 + -31600;
	// lfs f9,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// li r4,128
	ctx.r4.s64 = 128;
	// lfs f12,-31600(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31600);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,32232(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 32232);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmuls f8,f13,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f13,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f7,f10,f13,f8
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f8.f64));
	// fmadds f6,f9,f12,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f12.f64 + ctx.f7.f64));
	// fabs f5,f6
	ctx.f5.u64 = ctx.f6.u64 & ~0x8000000000000000;
	// fcmpu cr6,f5,f11
	cr6.compare(ctx.f5.f64, ctx.f11.f64);
	// lfs f11,216(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 216);
	ctx.f11.f64 = double(temp.f32);
	// ble cr6,0x826fdd10
	if (!cr6.gt) goto loc_826FDD10;
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfs f9,212(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 212);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,208(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 208);
	ctx.f8.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fmadds f7,f9,f13,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f6,f8,f12,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f0
	cr6.compare(ctx.f6.f64, f0.f64);
	// bge cr6,0x826fdd04
	if (!cr6.lt) goto loc_826FDD04;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r5,r11,20316
	ctx.r5.s64 = r11.s64 + 20316;
	// b 0x826fdd5c
	goto loc_826FDD5C;
loc_826FDD04:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r5,r11,20304
	ctx.r5.s64 = r11.s64 + 20304;
	// b 0x826fdd5c
	goto loc_826FDD5C;
loc_826FDD10:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f10,212(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 212);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,208(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 208);
	ctx.f9.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r10,-31632
	ctx.r8.s64 = ctx.r10.s64 + -31632;
	// lfs f13,-31632(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31632);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmuls f8,f11,f0
	ctx.f8.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfs f0,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	f0.f64 = double(temp.f32);
	// fmadds f7,f10,f0,f8
	ctx.f7.f64 = double(float(ctx.f10.f64 * f0.f64 + ctx.f8.f64));
	// fmadds f6,f13,f9,f7
	ctx.f6.f64 = double(float(ctx.f13.f64 * ctx.f9.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f12
	cr6.compare(ctx.f6.f64, ctx.f12.f64);
	// bge cr6,0x826fdd54
	if (!cr6.lt) goto loc_826FDD54;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r5,r11,20296
	ctx.r5.s64 = r11.s64 + 20296;
	// b 0x826fdd5c
	goto loc_826FDD5C;
loc_826FDD54:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r5,r11,20288
	ctx.r5.s64 = r11.s64 + 20288;
loc_826FDD5C:
	// bl 0x82137a08
	ctx.lr = 0x826FDD60;
	sub_82137A08(ctx, base);
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

__attribute__((alias("__imp__sub_826FDD74"))) PPC_WEAK_FUNC(sub_826FDD74);
PPC_FUNC_IMPL(__imp__sub_826FDD74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FDD78"))) PPC_WEAK_FUNC(sub_826FDD78);
PPC_FUNC_IMPL(__imp__sub_826FDD78) {
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r7,r11,124
	ctx.r7.s64 = r11.s64 + 124;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// lbz r11,124(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 124);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826fddb4
	if (!cr6.eq) goto loc_826FDDB4;
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
loc_826FDDB4:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r11,-26992
	ctx.r5.s64 = r11.s64 + -26992;
	// bl 0x82137a08
	ctx.lr = 0x826FDDC4;
	sub_82137A08(ctx, base);
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

__attribute__((alias("__imp__sub_826FDDD8"))) PPC_WEAK_FUNC(sub_826FDDD8);
PPC_FUNC_IMPL(__imp__sub_826FDDD8) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r6,r30,60
	ctx.r6.s64 = r30.s64 + 60;
	// lbz r11,60(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fded4
	if (cr6.eq) goto loc_826FDED4;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,20224
	ctx.r10.s64 = ctx.r10.s64 + 20224;
	// addi r8,r6,2
	ctx.r8.s64 = ctx.r6.s64 + 2;
loc_826FDE14:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x826fde34
	if (!cr0.eq) goto loc_826FDE34;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bne cr6,0x826fde14
	if (!cr6.eq) goto loc_826FDE14;
loc_826FDE34:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826fde78
	if (cr6.eq) goto loc_826FDE78;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,20220
	ctx.r10.s64 = ctx.r10.s64 + 20220;
	// addi r8,r6,2
	ctx.r8.s64 = ctx.r6.s64 + 2;
loc_826FDE4C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x826fde6c
	if (!cr0.eq) goto loc_826FDE6C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bne cr6,0x826fde4c
	if (!cr6.eq) goto loc_826FDE4C;
loc_826FDE6C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x826fde7c
	if (!cr6.eq) goto loc_826FDE7C;
loc_826FDE78:
	// li r11,1
	r11.s64 = 1;
loc_826FDE7C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// li r4,128
	ctx.r4.s64 = 128;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,20396
	ctx.r5.s64 = r11.s64 + 20396;
	// bne cr6,0x826fde9c
	if (!cr6.eq) goto loc_826FDE9C;
	// addi r6,r6,6
	ctx.r6.s64 = ctx.r6.s64 + 6;
loc_826FDE9C:
	// bl 0x82137a08
	ctx.lr = 0x826FDEA0;
	sub_82137A08(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9790
	ctx.lr = 0x826FDEAC;
	sub_821C9790(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r30,196
	ctx.r3.s64 = r30.s64 + 196;
	// bl 0x82180570
	ctx.lr = 0x826FDEBC;
	sub_82180570(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x826fdedc
	if (cr6.eq) goto loc_826FDEDC;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,20328
	ctx.r3.s64 = r11.s64 + 20328;
	// bl 0x82130000
	ctx.lr = 0x826FDED4;
	sub_82130000(ctx, base);
loc_826FDED4:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x826fdee0
	goto loc_826FDEE0;
loc_826FDEDC:
	// li r3,1
	ctx.r3.s64 = 1;
loc_826FDEE0:
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

__attribute__((alias("__imp__sub_826FDEF8"))) PPC_WEAK_FUNC(sub_826FDEF8);
PPC_FUNC_IMPL(__imp__sub_826FDEF8) {
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r11,188
	ctx.r6.s64 = r11.s64 + 188;
	// lbz r11,188(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826fdf30
	if (!cr6.eq) goto loc_826FDF30;
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
loc_826FDF30:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r11,20412
	ctx.r5.s64 = r11.s64 + 20412;
	// bl 0x82137a08
	ctx.lr = 0x826FDF40;
	sub_82137A08(ctx, base);
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

__attribute__((alias("__imp__sub_826FDF54"))) PPC_WEAK_FUNC(sub_826FDF54);
PPC_FUNC_IMPL(__imp__sub_826FDF54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FDF58"))) PPC_WEAK_FUNC(sub_826FDF58);
PPC_FUNC_IMPL(__imp__sub_826FDF58) {
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r6,r11,188
	ctx.r6.s64 = r11.s64 + 188;
	// lbz r11,188(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826fdf90
	if (!cr6.eq) goto loc_826FDF90;
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
loc_826FDF90:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r11,20436
	ctx.r5.s64 = r11.s64 + 20436;
	// bl 0x82137a08
	ctx.lr = 0x826FDFA0;
	sub_82137A08(ctx, base);
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

__attribute__((alias("__imp__sub_826FDFB4"))) PPC_WEAK_FUNC(sub_826FDFB4);
PPC_FUNC_IMPL(__imp__sub_826FDFB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FDFB8"))) PPC_WEAK_FUNC(sub_826FDFB8);
PPC_FUNC_IMPL(__imp__sub_826FDFB8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r3,-10016(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fe0dc
	if (cr6.eq) goto loc_826FE0DC;
	// bl 0x82700880
	ctx.lr = 0x826FDFE0;
	sub_82700880(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fe0dc
	if (cr6.eq) goto loc_826FE0DC;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826fe0dc
	if (cr6.eq) goto loc_826FE0DC;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826fe0dc
	if (cr6.eq) goto loc_826FE0DC;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f12,224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,26214
	ctx.r8.s64 = 1717960704;
	// ori r7,r8,26215
	ctx.r7.u64 = ctx.r8.u64 | 26215;
	// lfs f0,-13028(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13028);
	f0.f64 = double(temp.f32);
	// lfs f13,-1684(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -1684);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f11,f12,f0,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f13.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// mulhw r5,r6,r7
	ctx.r5.s64 = (int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32)) >> 32;
	// srawi r10,r5,1
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 1;
	// rlwinm r9,r10,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r3,r4,r6
	ctx.r3.s64 = ctx.r6.s64 - ctx.r4.s64;
	// subf r6,r3,r11
	ctx.r6.s64 = r11.s64 - ctx.r3.s64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmpwi cr6,r6,105
	cr6.compare<int32_t>(ctx.r6.s32, 105, xer);
	// blt cr6,0x826fe084
	if (cr6.lt) goto loc_826FE084;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r5,31
	ctx.r5.s64 = 31;
	// addi r4,r11,20508
	ctx.r4.s64 = r11.s64 + 20508;
	// bl 0x823da950
	ctx.lr = 0x826FE06C;
	sub_823DA950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
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
loc_826FE084:
	// cmpwi cr6,r6,50
	cr6.compare<int32_t>(ctx.r6.s32, 50, xer);
	// bgt cr6,0x826fe0b4
	if (cr6.gt) goto loc_826FE0B4;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r5,21
	ctx.r5.s64 = 21;
	// addi r4,r11,20484
	ctx.r4.s64 = r11.s64 + 20484;
	// bl 0x823da950
	ctx.lr = 0x826FE09C;
	sub_823DA950(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
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
loc_826FE0B4:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r11,20460
	ctx.r5.s64 = r11.s64 + 20460;
	// bl 0x82137a08
	ctx.lr = 0x826FE0C4;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
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
loc_826FE0DC:
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

__attribute__((alias("__imp__sub_826FE0F4"))) PPC_WEAK_FUNC(sub_826FE0F4);
PPC_FUNC_IMPL(__imp__sub_826FE0F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FE0F8"))) PPC_WEAK_FUNC(sub_826FE0F8);
PPC_FUNC_IMPL(__imp__sub_826FE0F8) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r3,-10016(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x826fe12c
	if (!cr6.eq) goto loc_826FE12C;
loc_826FE124:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x826fe15c
	goto loc_826FE15C;
loc_826FE12C:
	// bl 0x82700880
	ctx.lr = 0x826FE130;
	sub_82700880(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fe124
	if (cr6.eq) goto loc_826FE124;
	// bl 0x822a8dc8
	ctx.lr = 0x826FE13C;
	sub_822A8DC8(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r5,r11,-26992
	ctx.r5.s64 = r11.s64 + -26992;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82137a08
	ctx.lr = 0x826FE158;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
loc_826FE15C:
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

__attribute__((alias("__imp__sub_826FE174"))) PPC_WEAK_FUNC(sub_826FE174);
PPC_FUNC_IMPL(__imp__sub_826FE174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FE178"))) PPC_WEAK_FUNC(sub_826FE178);
PPC_FUNC_IMPL(__imp__sub_826FE178) {
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
	PPCRegister f0{};
	PPCRegister f31{};
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
	ctx.lr = 0x826FE180;
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r3,-10016(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fe4b0
	if (cr6.eq) goto loc_826FE4B0;
	// bl 0x82700880
	ctx.lr = 0x826FE1A0;
	sub_82700880(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826fe4b0
	if (cr6.eq) goto loc_826FE4B0;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826fe4b0
	if (cr6.eq) goto loc_826FE4B0;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826fe4b0
	if (cr6.eq) goto loc_826FE4B0;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-10016(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// bl 0x827004b8
	ctx.lr = 0x826FE1D0;
	sub_827004B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826fe4b0
	if (!cr6.eq) goto loc_826FE4B0;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r31,8(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x822a8108
	ctx.lr = 0x826FE1EC;
	sub_822A8108(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,224(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r11,r11,3796
	r11.s64 = r11.s64 + 3796;
	// addi r28,r27,208
	r28.s64 = r27.s64 + 208;
	// lfs f0,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	f0.f64 = double(temp.f32);
	// lfs f31,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x826fe224
	if (cr6.lt) goto loc_826FE224;
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r9,272
	ctx.r9.s64 = 272;
	// lvx128 v63,r10,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x826fe238
	goto loc_826FE238;
loc_826FE224:
	// li r10,32
	ctx.r10.s64 = 32;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v61,r3,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v60,v62,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v60,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_826FE238:
	// stfs f31,212(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r27.u32 + 212, temp.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lvx128 v59,r0,r28
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v58,v59,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v59.f32), 0xEF));
	// vrsqrtefp128 v57,v58
	simde_mm_store_ps(v57.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v58.f32))));
	// lis r24,-32121
	r24.s64 = -2105081856;
	// lfs f0,30712(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30712);
	f0.f64 = double(temp.f32);
	// lis r10,6
	ctx.r10.s64 = 393216;
	// addi r23,r3,48
	r23.s64 = ctx.r3.s64 + 48;
	// ori r25,r10,16704
	r25.u64 = ctx.r10.u64 | 16704;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// vmulfp128 v56,v59,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v56,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-10012(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -10012);
	// lfs f13,56(r3)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,48(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// add r3,r11,r25
	ctx.r3.u64 = r11.u64 + r25.u64;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// bl 0x8224a2b8
	ctx.lr = 0x826FE290;
	sub_8224A2B8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x826fe47c
	if (cr6.eq) goto loc_826FE47C;
	// stw r26,252(r27)
	PPC_STORE_U32(r27.u32 + 252, r26.u32);
	// lwz r5,144(r26)
	ctx.r5.u64 = PPC_LOAD_U32(r26.u32 + 144);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826fe3b8
	if (cr6.eq) goto loc_826FE3B8;
	// lbz r11,0(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fe3b8
	if (cr6.eq) goto loc_826FE3B8;
	// addi r29,r27,60
	r29.s64 = r27.s64 + 60;
	// li r4,64
	ctx.r4.s64 = 64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x826FE2C8;
	sub_82137A08(ctx, base);
	// mr r31,r29
	r31.u64 = r29.u64;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_826FE2D0:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826fe2d0
	if (!cr6.eq) goto loc_826FE2D0;
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// add r30,r11,r31
	r30.u64 = r11.u64 + r31.u64;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// bge cr6,0x826fe324
	if (!cr6.lt) goto loc_826FE324;
loc_826FE2F8:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,46
	cr6.compare<uint32_t>(r11.u32, 46, xer);
	// bne cr6,0x826fe318
	if (!cr6.eq) goto loc_826FE318;
	// subf r5,r31,r30
	ctx.r5.s64 = r30.s64 - r31.s64;
	// addi r4,r31,1
	ctx.r4.s64 = r31.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823da950
	ctx.lr = 0x826FE314;
	sub_823DA950(ctx, base);
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
loc_826FE318:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// blt cr6,0x826fe2f8
	if (cr6.lt) goto loc_826FE2F8;
loc_826FE324:
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// mr r11,r29
	r11.u64 = r29.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fe358
	if (cr6.eq) goto loc_826FE358;
	// li r10,95
	ctx.r10.s64 = 95;
loc_826FE338:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,32
	cr6.compare<uint32_t>(ctx.r9.u32, 32, xer);
	// bne cr6,0x826fe348
	if (!cr6.eq) goto loc_826FE348;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
loc_826FE348:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826fe338
	if (!cr6.eq) goto loc_826FE338;
loc_826FE358:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823de4d8
	ctx.lr = 0x826FE360;
	sub_823DE4D8(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,6
	ctx.r4.s64 = 6;
	// addi r3,r27,188
	ctx.r3.s64 = r27.s64 + 188;
	// bl 0x82137a08
	ctx.lr = 0x826FE370;
	sub_82137A08(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r11,r29
	r11.u64 = r29.u64;
	// addi r10,r10,20220
	ctx.r10.s64 = ctx.r10.s64 + 20220;
	// addi r8,r29,2
	ctx.r8.s64 = r29.s64 + 2;
loc_826FE380:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x826fe3a0
	if (!cr0.eq) goto loc_826FE3A0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bne cr6,0x826fe380
	if (!cr6.eq) goto loc_826FE380;
loc_826FE3A0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826fe3b8
	if (!cr6.eq) goto loc_826FE3B8;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r27,124
	ctx.r3.s64 = r27.s64 + 124;
	// bl 0x82137a08
	ctx.lr = 0x826FE3B8;
	sub_82137A08(ctx, base);
loc_826FE3B8:
	// lwz r11,-10012(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -10012);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// add r6,r11,r25
	ctx.r6.u64 = r11.u64 + r25.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82244840
	ctx.lr = 0x826FE3D0;
	sub_82244840(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x826fe3ec
	if (!cr6.eq) goto loc_826FE3EC;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,256(r27)
	PPC_STORE_U32(r27.u32 + 256, r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_826FE3EC:
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x826fe468
	if (!cr6.eq) goto loc_826FE468;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r9,80
	ctx.r9.s64 = 80;
	// lvx128 v55,r0,r23
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f0,8(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	f0.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lfs f13,4(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r11,r9
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v53,r0,r8
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v52,v54,v53
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v52.f32, simde_mm_sub_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v53.f32)));
	// stvx128 v52,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f0,f9
	ctx.f8.f64 = double(float(f0.f64 * ctx.f9.f64));
	// fmadds f7,f13,f11,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fmadds f6,f12,f10,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f10.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f31
	cr6.compare(ctx.f6.f64, f31.f64);
	// bge cr6,0x826fe454
	if (!cr6.lt) goto loc_826FE454;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_826FE454:
	// stw r11,260(r27)
	PPC_STORE_U32(r27.u32 + 260, r11.u32);
	// stw r11,256(r27)
	PPC_STORE_U32(r27.u32 + 256, r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_826FE468:
	// li r11,0
	r11.s64 = 0;
	// stw r11,256(r27)
	PPC_STORE_U32(r27.u32 + 256, r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_826FE47C:
	// lwz r11,-10012(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -10012);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r11,8536
	ctx.r3.s64 = r11.s64 + 8536;
	// bl 0x826dba38
	ctx.lr = 0x826FE48C;
	sub_826DBA38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fe49c
	if (cr6.eq) goto loc_826FE49C;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x826fe4a4
	goto loc_826FE4A4;
loc_826FE49C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r5,r11,3998
	ctx.r5.s64 = r11.s64 + 3998;
loc_826FE4A4:
	// li r4,6
	ctx.r4.s64 = 6;
	// addi r3,r27,188
	ctx.r3.s64 = r27.s64 + 188;
	// bl 0x82137a08
	ctx.lr = 0x826FE4B0;
	sub_82137A08(ctx, base);
loc_826FE4B0:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_826FE4BC"))) PPC_WEAK_FUNC(sub_826FE4BC);
PPC_FUNC_IMPL(__imp__sub_826FE4BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FE4C0"))) PPC_WEAK_FUNC(sub_826FE4C0);
PPC_FUNC_IMPL(__imp__sub_826FE4C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
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
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r3,-10016(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x826fe4f4
	if (!cr6.eq) goto loc_826FE4F4;
loc_826FE4EC:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x826fe574
	goto loc_826FE574;
loc_826FE4F4:
	// bl 0x82700880
	ctx.lr = 0x826FE4F8;
	sub_82700880(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fe4ec
	if (cr6.eq) goto loc_826FE4EC;
	// bl 0x822a8108
	ctx.lr = 0x826FE504;
	sub_822A8108(ctx, base);
	// li r11,48
	r11.s64 = 48;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f13,216(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 216);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f12,212(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 212);
	ctx.f12.f64 = double(temp.f32);
	// li r8,80
	ctx.r8.s64 = 80;
	// lfs f11,208(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 208);
	ctx.f11.f64 = double(temp.f32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lvx128 v62,r30,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v60,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f13,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f8.f64));
	// fmadds f6,f12,f10,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f10.f64 + ctx.f7.f64));
	// fmadds f5,f11,f9,f6
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f9.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f0
	cr6.compare(ctx.f5.f64, f0.f64);
	// bge cr6,0x826fe570
	if (!cr6.lt) goto loc_826FE570;
	// li r11,0
	r11.s64 = 0;
loc_826FE570:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
loc_826FE574:
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

__attribute__((alias("__imp__sub_826FE58C"))) PPC_WEAK_FUNC(sub_826FE58C);
PPC_FUNC_IMPL(__imp__sub_826FE58C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FE590"))) PPC_WEAK_FUNC(sub_826FE590);
PPC_FUNC_IMPL(__imp__sub_826FE590) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r7,236(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 236);
	// li r10,0
	ctx.r10.s64 = 0;
	// lhz r9,12(r7)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r7.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x826fe5f0
	if (!cr6.gt) goto loc_826FE5F0;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r8,-12012(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12012);
	// lfs f12,2248(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 2248);
	ctx.f12.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f11,29504(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 29504);
	ctx.f11.f64 = double(temp.f32);
loc_826FE5BC:
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f0.f64 = double(temp.f32);
	// lfs f13,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x826fe5d0
	if (!cr6.gt) goto loc_826FE5D0;
	// fsubs f0,f0,f11
	f0.f64 = double(float(f0.f64 - ctx.f11.f64));
loc_826FE5D0:
	// fcmpu cr6,f12,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, f0.f64);
	// blt cr6,0x826fe5e0
	if (cr6.lt) goto loc_826FE5E0;
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// blt cr6,0x826fe5f4
	if (cr6.lt) goto loc_826FE5F4;
loc_826FE5E0:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x826fe5bc
	if (cr6.lt) goto loc_826FE5BC;
loc_826FE5F0:
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
loc_826FE5F4:
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826FE5FC"))) PPC_WEAK_FUNC(sub_826FE5FC);
PPC_FUNC_IMPL(__imp__sub_826FE5FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FE600"))) PPC_WEAK_FUNC(sub_826FE600);
PPC_FUNC_IMPL(__imp__sub_826FE600) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32111
	r31.s64 = -2104426496;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r5,-24400(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + -24400);
	// lwz r3,228(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 228);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fe638
	if (cr6.eq) goto loc_826FE638;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x826FE634;
	sub_8213C218(ctx, base);
	// lwz r5,-24400(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + -24400);
loc_826FE638:
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r31,1
	r31.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// lwz r3,-12012(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12012);
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f1,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r11,127(r1)
	PPC_STORE_U8(ctx.r1.u32 + 127, r11.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// addi r5,r5,228
	ctx.r5.s64 = ctx.r5.s64 + 228;
	// stb r31,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r31.u8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x825495a8
	ctx.lr = 0x826FE688;
	sub_825495A8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
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

__attribute__((alias("__imp__sub_826FE6A0"))) PPC_WEAK_FUNC(sub_826FE6A0);
PPC_FUNC_IMPL(__imp__sub_826FE6A0) {
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
	// lis r31,-32115
	r31.s64 = -2104688640;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,-12640(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fe6dc
	if (cr6.eq) goto loc_826FE6DC;
	// lbz r10,10(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x826fe6e0
	if (cr6.eq) goto loc_826FE6E0;
loc_826FE6DC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_826FE6E0:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826fe784
	if (!cr6.eq) goto loc_826FE784;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r10,2256(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2256);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fe710
	if (cr6.eq) goto loc_826FE710;
	// lwz r11,2260(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x826fe714
	if (!cr6.eq) goto loc_826FE714;
loc_826FE710:
	// li r11,0
	r11.s64 = 0;
loc_826FE714:
	// stb r11,269(r30)
	PPC_STORE_U8(r30.u32 + 269, r11.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826fe178
	ctx.lr = 0x826FE720;
	sub_826FE178(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r11,-12348(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12348);
	// lbz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r9,r10,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826fe768
	if (cr6.eq) goto loc_826FE768;
	// lbz r10,269(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 269);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fe754
	if (cr6.eq) goto loc_826FE754;
	// lbz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 52);
	// ori r9,r10,2
	ctx.r9.u64 = ctx.r10.u64 | 2;
	// stb r9,52(r11)
	PPC_STORE_U8(r11.u32 + 52, ctx.r9.u8);
	// b 0x826fe780
	goto loc_826FE780;
loc_826FE754:
	// lbz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 52);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm r9,r9,0,31,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stb r9,52(r11)
	PPC_STORE_U8(r11.u32 + 52, ctx.r9.u8);
	// b 0x826fe780
	goto loc_826FE780;
loc_826FE768:
	// rlwinm r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fe780
	if (cr6.eq) goto loc_826FE780;
	// lbz r11,52(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 52);
	// rlwinm r10,r11,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// stb r10,269(r30)
	PPC_STORE_U8(r30.u32 + 269, ctx.r10.u8);
loc_826FE780:
	// lwz r11,-12640(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -12640);
loc_826FE784:
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fe7a0
	if (cr6.eq) goto loc_826FE7A0;
	// lbz r10,10(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x826fe7a4
	if (cr6.eq) goto loc_826FE7A4;
loc_826FE7A0:
	// li r10,0
	ctx.r10.s64 = 0;
loc_826FE7A4:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fe834
	if (cr6.eq) goto loc_826FE834;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826fe834
	if (!cr6.eq) goto loc_826FE834;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r31,-32111
	r31.s64 = -2104426496;
	// lwz r11,-24344(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24344);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826fe7fc
	if (!cr6.eq) goto loc_826FE7FC;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// stw r11,-24344(r10)
	PPC_STORE_U32(ctx.r10.u32 + -24344, r11.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r4,r9,20540
	ctx.r4.s64 = ctx.r9.s64 + 20540;
	// addi r3,r8,19856
	ctx.r3.s64 = ctx.r8.s64 + 19856;
	// bl 0x82144a20
	ctx.lr = 0x826FE7F0;
	sub_82144A20(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stw r4,-24348(r31)
	PPC_STORE_U32(r31.u32 + -24348, ctx.r4.u32);
	// b 0x826fe800
	goto loc_826FE800;
loc_826FE7FC:
	// lwz r4,-24348(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -24348);
loc_826FE800:
	// lwz r11,224(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 224);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fe834
	if (cr6.eq) goto loc_826FE834;
	// lwz r11,264(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 264);
	// addi r5,r30,264
	ctx.r5.s64 = r30.s64 + 264;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826fe848
	if (!cr6.eq) goto loc_826FE848;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lfs f1,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821ee370
	ctx.lr = 0x826FE830;
	sub_821EE370(ctx, base);
	// b 0x826fe848
	goto loc_826FE848;
loc_826FE834:
	// lwz r3,264(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 264);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826fe848
	if (cr6.eq) goto loc_826FE848;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ec060
	ctx.lr = 0x826FE848;
	sub_821EC060(ctx, base);
loc_826FE848:
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

__attribute__((alias("__imp__sub_826FE860"))) PPC_WEAK_FUNC(sub_826FE860);
PPC_FUNC_IMPL(__imp__sub_826FE860) {
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
	ctx.lr = 0x826FE868;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r10,r11,-24376
	ctx.r10.s64 = r11.s64 + -24376;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826fe968
	if (!cr6.eq) goto loc_826FE968;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,-12012(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r9,2256(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2256);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826fe8b8
	if (cr6.eq) goto loc_826FE8B8;
	// lwz r11,2260(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x826fe8bc
	if (!cr6.eq) goto loc_826FE8BC;
loc_826FE8B8:
	// li r11,0
	r11.s64 = 0;
loc_826FE8BC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fe8e0
	if (cr6.eq) goto loc_826FE8E0;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r10,2252(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2252);
	// lwz r11,-27288(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x826fe8e4
	if (cr6.eq) goto loc_826FE8E4;
loc_826FE8E0:
	// li r11,0
	r11.s64 = 0;
loc_826FE8E4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826fe968
	if (!cr6.eq) goto loc_826FE968;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r31,r11,20572
	r31.s64 = r11.s64 + 20572;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821c7d28
	ctx.lr = 0x826FE908;
	sub_821C7D28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fe920
	if (cr6.eq) goto loc_826FE920;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826fe590
	ctx.lr = 0x826FE91C;
	sub_826FE590(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_826FE920:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c7d28
	ctx.lr = 0x826FE930;
	sub_821C7D28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826fe948
	if (cr6.eq) goto loc_826FE948;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826fe590
	ctx.lr = 0x826FE944;
	sub_826FE590(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_826FE948:
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821f3390
	ctx.lr = 0x826FE968;
	sub_821F3390(ctx, base);
loc_826FE968:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_826FE974"))) PPC_WEAK_FUNC(sub_826FE974);
PPC_FUNC_IMPL(__imp__sub_826FE974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FE978"))) PPC_WEAK_FUNC(sub_826FE978);
PPC_FUNC_IMPL(__imp__sub_826FE978) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91cc
	ctx.lr = 0x826FE980;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// mr r17,r4
	r17.u64 = ctx.r4.u64;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// lwz r7,256(r18)
	ctx.r7.u64 = PPC_LOAD_U32(r18.u32 + 256);
	// addis r6,r11,6
	ctx.r6.s64 = r11.s64 + 393216;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// addi r6,r6,16704
	ctx.r6.s64 = ctx.r6.s64 + 16704;
	// bne cr6,0x826fe9c0
	if (!cr6.eq) goto loc_826FE9C0;
	// lwz r7,252(r18)
	ctx.r7.u64 = PPC_LOAD_U32(r18.u32 + 252);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x826fe9c0
	if (!cr6.eq) goto loc_826FE9C0;
	// lwz r7,260(r18)
	ctx.r7.u64 = PPC_LOAD_U32(r18.u32 + 260);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x826fec80
	if (cr6.eq) goto loc_826FEC80;
loc_826FE9C0:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r21,r18,60
	r21.s64 = r18.s64 + 60;
	// addi r19,r11,20224
	r19.s64 = r11.s64 + 20224;
	// mr r11,r21
	r11.u64 = r21.u64;
	// mr r10,r19
	ctx.r10.u64 = r19.u64;
	// addi r8,r21,2
	ctx.r8.s64 = r21.s64 + 2;
loc_826FE9D8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r5,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r5.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x826fe9f8
	if (!cr0.eq) goto loc_826FE9F8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bne cr6,0x826fe9d8
	if (!cr6.eq) goto loc_826FE9D8;
loc_826FE9F8:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r22,r11,20220
	r22.s64 = r11.s64 + 20220;
	// beq cr6,0x826fea40
	if (cr6.eq) goto loc_826FEA40;
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
	// mr r11,r21
	r11.u64 = r21.u64;
	// addi r8,r21,2
	ctx.r8.s64 = r21.s64 + 2;
loc_826FEA14:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r5,0(r10)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r5,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r5.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x826fea34
	if (!cr0.eq) goto loc_826FEA34;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bne cr6,0x826fea14
	if (!cr6.eq) goto loc_826FEA14;
loc_826FEA34:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x826fea44
	if (!cr6.eq) goto loc_826FEA44;
loc_826FEA40:
	// li r11,1
	r11.s64 = 1;
loc_826FEA44:
	// lwz r10,8(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// clrlwi r23,r11,24
	r23.u64 = r11.u32 & 0xFF;
	// lwz r9,32(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 32);
	// li r27,0
	r27.s64 = 0;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r10,60(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// add r25,r10,r11
	r25.u64 = ctx.r10.u64 + r11.u64;
	// lhz r24,4(r25)
	r24.u64 = PPC_LOAD_U16(r25.u32 + 4);
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// ble cr6,0x826fec80
	if (!cr6.gt) goto loc_826FEC80;
	// li r26,0
	r26.s64 = 0;
	// li r20,95
	r20.s64 = 95;
loc_826FEA74:
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwzx r29,r11,r26
	r29.u64 = PPC_LOAD_U32(r11.u32 + r26.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826FEA90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x826fec70
	if (!cr6.eq) goto loc_826FEC70;
	// lwz r28,144(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 144);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826fec70
	if (cr6.eq) goto loc_826FEC70;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r11,r28
	r11.u64 = r28.u64;
	// subf r10,r28,r10
	ctx.r10.s64 = ctx.r10.s64 - r28.s64;
loc_826FEAB0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x826feab0
	if (!cr6.eq) goto loc_826FEAB0;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r30,r1,96
	r30.s64 = ctx.r1.s64 + 96;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_826FEAD0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826fead0
	if (!cr6.eq) goto loc_826FEAD0;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// cmplw cr6,r9,r31
	cr6.compare<uint32_t>(ctx.r9.u32, r31.u32, xer);
	// bge cr6,0x826feb2c
	if (!cr6.lt) goto loc_826FEB2C;
loc_826FEB00:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,46
	cr6.compare<uint32_t>(r11.u32, 46, xer);
	// bne cr6,0x826feb20
	if (!cr6.eq) goto loc_826FEB20;
	// subf r5,r30,r31
	ctx.r5.s64 = r31.s64 - r30.s64;
	// addi r4,r30,1
	ctx.r4.s64 = r30.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x826FEB1C;
	sub_823DA950(ctx, base);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_826FEB20:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// blt cr6,0x826feb00
	if (cr6.lt) goto loc_826FEB00;
loc_826FEB2C:
	// lbz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 96);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826feb5c
	if (cr6.eq) goto loc_826FEB5C;
loc_826FEB3C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,32
	cr6.compare<uint32_t>(ctx.r10.u32, 32, xer);
	// bne cr6,0x826feb4c
	if (!cr6.eq) goto loc_826FEB4C;
	// stb r20,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r20.u8);
loc_826FEB4C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826feb3c
	if (!cr6.eq) goto loc_826FEB3C;
loc_826FEB5C:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823de4d8
	ctx.lr = 0x826FEB64;
	sub_823DE4D8(ctx, base);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// mr r10,r19
	ctx.r10.u64 = r19.u64;
	// addi r8,r11,2
	ctx.r8.s64 = r11.s64 + 2;
loc_826FEB70:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x826feb90
	if (!cr0.eq) goto loc_826FEB90;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bne cr6,0x826feb70
	if (!cr6.eq) goto loc_826FEB70;
loc_826FEB90:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826febd0
	if (cr6.eq) goto loc_826FEBD0;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
	// addi r8,r11,2
	ctx.r8.s64 = r11.s64 + 2;
loc_826FEBA4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x826febc4
	if (!cr0.eq) goto loc_826FEBC4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bne cr6,0x826feba4
	if (!cr6.eq) goto loc_826FEBA4;
loc_826FEBC4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x826febd4
	if (!cr6.eq) goto loc_826FEBD4;
loc_826FEBD0:
	// li r11,1
	r11.s64 = 1;
loc_826FEBD4:
	// clrlwi r10,r23,24
	ctx.r10.u64 = r23.u32 & 0xFF;
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826fec24
	if (!cr6.eq) goto loc_826FEC24;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826fec24
	if (!cr6.eq) goto loc_826FEC24;
	// addi r10,r18,66
	ctx.r10.s64 = r18.s64 + 66;
	// addi r11,r1,102
	r11.s64 = ctx.r1.s64 + 102;
loc_826FEBF8:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826fec1c
	if (cr6.eq) goto loc_826FEC1C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826febf8
	if (cr6.eq) goto loc_826FEBF8;
loc_826FEC1C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// b 0x826fec6c
	goto loc_826FEC6C;
loc_826FEC24:
	// mr r10,r21
	ctx.r10.u64 = r21.u64;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
loc_826FEC2C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826fec50
	if (cr6.eq) goto loc_826FEC50;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826fec2c
	if (cr6.eq) goto loc_826FEC2C;
loc_826FEC50:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826fec70
	if (cr6.eq) goto loc_826FEC70;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x826fe4c0
	ctx.lr = 0x826FEC64;
	sub_826FE4C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
loc_826FEC6C:
	// bne cr6,0x826fec8c
	if (!cr6.eq) goto loc_826FEC8C;
loc_826FEC70:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// cmpw cr6,r27,r24
	cr6.compare<int32_t>(r27.s32, r24.s32, xer);
	// blt cr6,0x826fea74
	if (cr6.lt) goto loc_826FEA74;
loc_826FEC80:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d921c
	return;
loc_826FEC8C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// li r4,128
	ctx.r4.s64 = 128;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// addi r5,r11,20584
	ctx.r5.s64 = r11.s64 + 20584;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// bne cr6,0x826fecb0
	if (!cr6.eq) goto loc_826FECB0;
	// addi r6,r28,6
	ctx.r6.s64 = r28.s64 + 6;
loc_826FECB0:
	// bl 0x82137a08
	ctx.lr = 0x826FECB4;
	sub_82137A08(ctx, base);
	// mr r30,r17
	r30.u64 = r17.u64;
	// mr r11,r17
	r11.u64 = r17.u64;
loc_826FECBC:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826fecbc
	if (!cr6.eq) goto loc_826FECBC;
	// subf r11,r17,r11
	r11.s64 = r11.s64 - r17.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// add r31,r11,r17
	r31.u64 = r11.u64 + r17.u64;
	// cmplw cr6,r17,r31
	cr6.compare<uint32_t>(r17.u32, r31.u32, xer);
	// bge cr6,0x826fed10
	if (!cr6.lt) goto loc_826FED10;
loc_826FECE4:
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,46
	cr6.compare<uint32_t>(r11.u32, 46, xer);
	// bne cr6,0x826fed04
	if (!cr6.eq) goto loc_826FED04;
	// subf r5,r30,r31
	ctx.r5.s64 = r31.s64 - r30.s64;
	// addi r4,r30,1
	ctx.r4.s64 = r30.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x826FED00;
	sub_823DA950(ctx, base);
	// addi r31,r31,-1
	r31.s64 = r31.s64 + -1;
loc_826FED04:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplw cr6,r30,r31
	cr6.compare<uint32_t>(r30.u32, r31.u32, xer);
	// blt cr6,0x826fece4
	if (cr6.lt) goto loc_826FECE4;
loc_826FED10:
	// lbz r10,0(r17)
	ctx.r10.u64 = PPC_LOAD_U8(r17.u32 + 0);
	// mr r11,r17
	r11.u64 = r17.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826fed40
	if (cr6.eq) goto loc_826FED40;
loc_826FED20:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,32
	cr6.compare<uint32_t>(ctx.r10.u32, 32, xer);
	// bne cr6,0x826fed30
	if (!cr6.eq) goto loc_826FED30;
	// stb r20,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r20.u8);
loc_826FED30:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826fed20
	if (!cr6.eq) goto loc_826FED20;
loc_826FED40:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x821c9790
	ctx.lr = 0x826FED4C;
	sub_821C9790(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r18,196
	ctx.r3.s64 = r18.s64 + 196;
	// bl 0x82180570
	ctx.lr = 0x826FED5C;
	sub_82180570(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x826fed80
	if (cr6.eq) goto loc_826FED80;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// addi r3,r11,20328
	ctx.r3.s64 = r11.s64 + 20328;
	// bl 0x82130000
	ctx.lr = 0x826FED74;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d921c
	return;
loc_826FED80:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_826FED8C"))) PPC_WEAK_FUNC(sub_826FED8C);
PPC_FUNC_IMPL(__imp__sub_826FED8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826FED90"))) PPC_WEAK_FUNC(sub_826FED90);
PPC_FUNC_IMPL(__imp__sub_826FED90) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x821f3938
	ctx.lr = 0x826FEDAC;
	sub_821F3938(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,20604
	ctx.r10.s64 = r11.s64 + 20604;
	// li r9,32
	ctx.r9.s64 = 32;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// li r3,128
	ctx.r3.s64 = 128;
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// addi r11,r31,40
	r11.s64 = r31.s64 + 40;
	// sth r30,44(r31)
	PPC_STORE_U16(r31.u32 + 44, r30.u16);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// sth r30,52(r31)
	PPC_STORE_U16(r31.u32 + 52, r30.u16);
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
	// sth r30,200(r31)
	PPC_STORE_U16(r31.u32 + 200, r30.u16);
	// sth r9,202(r31)
	PPC_STORE_U16(r31.u32 + 202, ctx.r9.u16);
	// bl 0x82130528
	ctx.lr = 0x826FEDE8;
	sub_82130528(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r3,196(r31)
	PPC_STORE_U32(r31.u32 + 196, ctx.r3.u32);
	// stb r30,188(r31)
	PPC_STORE_U8(r31.u32 + 188, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,124(r31)
	PPC_STORE_U8(r31.u32 + 124, r30.u8);
	// stb r30,60(r31)
	PPC_STORE_U8(r31.u32 + 60, r30.u8);
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,208(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// stfs f0,212(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 212, temp.u32);
	// stfs f13,216(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 216, temp.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r30,224(r31)
	PPC_STORE_U32(r31.u32 + 224, r30.u32);
	// stw r30,228(r31)
	PPC_STORE_U32(r31.u32 + 228, r30.u32);
	// stw r30,232(r31)
	PPC_STORE_U32(r31.u32 + 232, r30.u32);
	// stw r30,236(r31)
	PPC_STORE_U32(r31.u32 + 236, r30.u32);
	// stw r30,240(r31)
	PPC_STORE_U32(r31.u32 + 240, r30.u32);
	// stw r30,244(r31)
	PPC_STORE_U32(r31.u32 + 244, r30.u32);
	// stw r30,248(r31)
	PPC_STORE_U32(r31.u32 + 248, r30.u32);
	// stw r30,252(r31)
	PPC_STORE_U32(r31.u32 + 252, r30.u32);
	// stw r30,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r30.u32);
	// stw r30,260(r31)
	PPC_STORE_U32(r31.u32 + 260, r30.u32);
	// stw r30,264(r31)
	PPC_STORE_U32(r31.u32 + 264, r30.u32);
	// stb r30,268(r31)
	PPC_STORE_U8(r31.u32 + 268, r30.u8);
	// stb r30,269(r31)
	PPC_STORE_U8(r31.u32 + 269, r30.u8);
	// lwz r5,24(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826FEE5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,36(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x826FEE70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

