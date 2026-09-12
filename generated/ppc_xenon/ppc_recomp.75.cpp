#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8240D0A0"))) PPC_WEAK_FUNC(sub_8240D0A0);
PPC_FUNC_IMPL(__imp__sub_8240D0A0) {
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
	ctx.lr = 0x8240D0A8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lbz r30,13(r3)
	r30.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// lwz r8,28(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r31,4(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mullw r7,r30,r10
	ctx.r7.s64 = int64_t(r30.s32) * int64_t(ctx.r10.s32);
	// lwz r29,24(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,20(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r10,r31
	ctx.r10.s64 = r31.s64 - ctx.r10.s64;
	// rlwinm r9,r8,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r6,r8,r29
	ctx.r6.s64 = r29.s64 - ctx.r8.s64;
	// add r11,r11,r5
	r11.u64 = r11.u64 + ctx.r5.u64;
	// add r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 + ctx.r4.u64;
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// blt cr6,0x8240d0f4
	if (cr6.lt) goto loc_8240D0F4;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
loc_8240D0F4:
	// clrlwi r10,r7,29
	ctx.r10.u64 = ctx.r7.u32 & 0x7;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// or r10,r8,r11
	ctx.r10.u64 = ctx.r8.u64 | r11.u64;
	// clrlwi r8,r10,28
	ctx.r8.u64 = ctx.r10.u32 & 0xF;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x8240d118
	if (cr6.eq) goto loc_8240D118;
	// bl 0x82407a60
	ctx.lr = 0x8240D110;
	sub_82407A60(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
loc_8240D118:
	// rlwinm r8,r7,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r8,r8,127
	ctx.r8.s64 = ctx.r8.s64 + 127;
	// rlwinm r8,r8,25,7,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8240d144
	if (cr6.eq) goto loc_8240D144;
loc_8240D130:
	// rlwinm r28,r10,7,0,24
	r28.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// dcbt r28,r11
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// blt cr6,0x8240d130
	if (cr6.lt) goto loc_8240D130;
loc_8240D144:
	// extsw r10,r6
	ctx.r10.s64 = ctx.r6.s32;
	// lfs f0,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	f0.f64 = double(temp.f32);
	// rlwinm r8,r7,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f13,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f9,88(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// lfs f12,12428(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12428);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r10,r10,-3840
	ctx.r10.s64 = ctx.r10.s64 + -3840;
	// lvlx128 v63,r0,r28
	temp.u32 = r28.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// fcfid f7,f9
	ctx.f7.f64 = double(ctx.f9.s64);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fdivs f13,f10,f6
	ctx.f13.f64 = double(float(ctx.f10.f64 / ctx.f6.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx128 v62,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fmadds f3,f5,f13,f0
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + f0.f64));
	// stfs f3,36(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lvx128 v0,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f4,f13,f12
	ctx.f4.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// stfs f4,88(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx128 v61,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v61,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vspltw128 v12,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vaddfp128 v62,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v62.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32)));
	// vmaddfp v0,v12,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// ble cr6,0x8240d220
	if (!cr6.gt) goto loc_8240D220;
	// addi r10,r7,-1
	ctx.r10.s64 = ctx.r7.s64 + -1;
	// li r8,16
	ctx.r8.s64 = 16;
	// rlwinm r10,r10,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_8240D1F0:
	// vaddfp128 v60,v0,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v63.f32)));
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r11,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v57,v59,v0
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(ctx.v0.f32)));
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// vaddfp128 v0,v0,v62
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v62.f32)));
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// vmulfp128 v56,v58,v60
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v60.f32)));
	// stvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r9,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r9,32
	ctx.r9.s64 = ctx.r9.s64 + 32;
	// bne 0x8240d1f0
	if (!cr0.eq) goto loc_8240D1F0;
loc_8240D220:
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r5,r11
	r11.s64 = r11.s64 - ctx.r5.s64;
	// twllei r10,0
	// divwu r11,r11,r10
	r11.u32 = r11.u32 / ctx.r10.u32;
	// cmplw cr6,r11,r31
	cr6.compare<uint32_t>(r11.u32, r31.u32, xer);
	// blt cr6,0x8240d23c
	if (cr6.lt) goto loc_8240D23C;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8240D23C:
	// subf r10,r4,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r4.s64;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// rlwinm r11,r10,30,2,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// blt cr6,0x8240d254
	if (cr6.lt) goto loc_8240D254;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8240D254:
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8240D260"))) PPC_WEAK_FUNC(sub_8240D260);
PPC_FUNC_IMPL(__imp__sub_8240D260) {
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
	ctx.lr = 0x8240D268;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lbz r28,13(r3)
	r28.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// lwz r29,4(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r8,28(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mullw r7,r28,r10
	ctx.r7.s64 = int64_t(r28.s32) * int64_t(ctx.r10.s32);
	// lwz r27,24(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r31,0(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r30,20(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// subf r9,r10,r29
	ctx.r9.s64 = r29.s64 - ctx.r10.s64;
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r6,r8,r27
	ctx.r6.s64 = r27.s64 - ctx.r8.s64;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// cmpw cr6,r9,r6
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r6.s32, xer);
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// blt cr6,0x8240d2b4
	if (cr6.lt) goto loc_8240D2B4;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
loc_8240D2B4:
	// clrlwi r9,r7,29
	ctx.r9.u64 = ctx.r7.u32 & 0x7;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// or r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 | r11.u64;
	// clrlwi r4,r5,28
	ctx.r4.u64 = ctx.r5.u32 & 0xF;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8240d2d8
	if (cr6.eq) goto loc_8240D2D8;
	// bl 0x82407b80
	ctx.lr = 0x8240D2D0;
	sub_82407B80(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8240D2D8:
	// rlwinm r8,r7,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r8,127
	ctx.r8.s64 = ctx.r8.s64 + 127;
	// rlwinm r8,r8,25,7,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8240d304
	if (cr6.eq) goto loc_8240D304;
loc_8240D2F0:
	// rlwinm r5,r9,7,0,24
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// dcbt r5,r11
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// blt cr6,0x8240d2f0
	if (cr6.lt) goto loc_8240D2F0;
loc_8240D304:
	// extsw r9,r6
	ctx.r9.s64 = ctx.r6.s32;
	// lfs f0,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	f0.f64 = double(temp.f32);
	// rlwinm r8,r7,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f13,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f9,88(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lfs f12,12428(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12428);
	ctx.f12.f64 = double(temp.f32);
	// addi r5,r6,-3840
	ctx.r5.s64 = ctx.r6.s64 + -3840;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lvlx128 v63,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// fcfid f7,f9
	ctx.f7.f64 = double(ctx.f9.s64);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fdivs f13,f10,f6
	ctx.f13.f64 = double(float(ctx.f10.f64 / ctx.f6.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx128 v62,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fmadds f3,f5,f13,f0
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + f0.f64));
	// stfs f3,36(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lvx128 v0,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f4,f13,f12
	ctx.f4.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// stfs f4,88(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx128 v61,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v61,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vspltw128 v12,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vaddfp128 v58,v59,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v59.f32)));
	// vmaddfp v0,v12,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// ble cr6,0x8240d430
	if (!cr6.gt) goto loc_8240D430;
	// addi r9,r7,-1
	ctx.r9.s64 = ctx.r7.s64 + -1;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// addi r6,r8,6368
	ctx.r6.s64 = ctx.r8.s64 + 6368;
	// addi r7,r7,6384
	ctx.r7.s64 = ctx.r7.s64 + 6384;
	// rlwinm r9,r9,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFF;
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lvx128 v6,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,32
	ctx.r4.s64 = 32;
	// lvx128 v7,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,48
	ctx.r5.s64 = 48;
	// li r6,1024
	ctx.r6.s64 = 1024;
	// li r7,1040
	ctx.r7.s64 = 1040;
loc_8240D3D8:
	// vaddfp128 v57,v0,v59
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v59.f32)));
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lvx128 v61,r11,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v56,v63,v62,v7
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v60,r11,r5
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v55,v63,v62,v6
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vperm128 v54,v61,v60,v7
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// vperm128 v53,v61,v60,v6
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vmulfp128 v52,v56,v0
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v51,v55,v0
	simde_mm_store_ps(v51.f32, simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vaddfp128 v0,v0,v58
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v58.f32)));
	// vmulfp128 v50,v54,v57
	simde_mm_store_ps(v50.f32, simde_mm_mul_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v57.f32)));
	// vmulfp128 v49,v53,v57
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v52,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// bne 0x8240d3d8
	if (!cr0.eq) goto loc_8240D3D8;
loc_8240D430:
	// rlwinm r9,r28,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// twllei r9,0
	// divwu r11,r11,r9
	r11.u32 = r11.u32 / ctx.r9.u32;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// blt cr6,0x8240d44c
	if (cr6.lt) goto loc_8240D44C;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8240D44C:
	// subf r10,r30,r10
	ctx.r10.s64 = ctx.r10.s64 - r30.s64;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// rlwinm r11,r10,30,2,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// blt cr6,0x8240d464
	if (cr6.lt) goto loc_8240D464;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_8240D464:
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8240D470"))) PPC_WEAK_FUNC(sub_8240D470);
PPC_FUNC_IMPL(__imp__sub_8240D470) {
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
	// bl 0x823d91cc
	ctx.lr = 0x8240D478;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r6,8(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lbz r9,13(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r7,24(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mullw r9,r9,r6
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r6.s32);
	// lwz r4,28(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// stw r3,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, ctx.r3.u32);
	// subf r8,r6,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r6.s64;
	// subf r5,r4,r7
	ctx.r5.s64 = ctx.r7.s64 - ctx.r4.s64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r4,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// add r7,r6,r10
	ctx.r7.u64 = ctx.r6.u64 + ctx.r10.u64;
	// cmpw cr6,r8,r5
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r5.s32, xer);
	// blt cr6,0x8240d4c4
	if (cr6.lt) goto loc_8240D4C4;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
loc_8240D4C4:
	// clrlwi r11,r8,29
	r11.u64 = ctx.r8.u32 & 0x7;
	// or r10,r11,r7
	ctx.r10.u64 = r11.u64 | ctx.r7.u64;
	// or r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 | ctx.r9.u64;
	// clrlwi r4,r6,28
	ctx.r4.u64 = ctx.r6.u32 & 0xF;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8240d4e8
	if (cr6.eq) goto loc_8240D4E8;
	// bl 0x82407de8
	ctx.lr = 0x8240D4E0;
	sub_82407DE8(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d921c
	return;
loc_8240D4E8:
	// rlwinm r10,r8,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// li r11,0
	r11.s64 = 0;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r6,r10,127
	ctx.r6.s64 = ctx.r10.s64 + 127;
	// rlwinm r10,r6,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8240d51c
	if (cr6.eq) goto loc_8240D51C;
loc_8240D508:
	// rlwinm r6,r11,7,0,24
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// dcbt r6,r9
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8240d508
	if (cr6.lt) goto loc_8240D508;
loc_8240D51C:
	// extsw r11,r5
	r11.s64 = ctx.r5.s32;
	// lfs f0,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	f0.f64 = double(temp.f32);
	// rlwinm r10,r8,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f13,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// extsw r6,r10
	ctx.r6.s64 = ctx.r10.s32;
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f9,88(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r11,r1,88
	r11.s64 = ctx.r1.s64 + 88;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lfs f12,12428(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12428);
	ctx.f12.f64 = double(temp.f32);
	// addi r5,r6,-3840
	ctx.r5.s64 = ctx.r6.s64 + -3840;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// lvlx128 v63,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// fcfid f7,f9
	ctx.f7.f64 = double(ctx.f9.s64);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fdivs f13,f10,f6
	ctx.f13.f64 = double(float(ctx.f10.f64 / ctx.f6.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx128 v62,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fmadds f3,f5,f13,f0
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + f0.f64));
	// stfs f3,36(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lvx128 v0,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f4,f13,f12
	ctx.f4.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// stfs f4,88(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx128 v61,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v49,v61,0
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vspltw128 v12,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vaddfp128 v48,v49,v49
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v48.f32, simde_mm_add_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v49.f32)));
	// vmaddfp v0,v12,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// ble cr6,0x8240d75c
	if (!cr6.gt) goto loc_8240D75C;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// lis r4,-32250
	ctx.r4.s64 = -2113536000;
	// lis r3,-32250
	ctx.r3.s64 = -2113536000;
	// addi r6,r6,6400
	ctx.r6.s64 = ctx.r6.s64 + 6400;
	// addi r5,r5,6368
	ctx.r5.s64 = ctx.r5.s64 + 6368;
	// addi r4,r4,6384
	ctx.r4.s64 = ctx.r4.s64 + 6384;
	// addi r3,r3,6416
	ctx.r3.s64 = ctx.r3.s64 + 6416;
	// addi r11,r8,-1
	r11.s64 = ctx.r8.s64 + -1;
	// lvx128 v4,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r7,2064
	ctx.r10.s64 = ctx.r7.s64 + 2064;
	// rlwinm r8,r11,29,3,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFF;
	// lvx128 v5,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v6,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r9,128
	r11.s64 = ctx.r9.s64 + 128;
	// lvx128 v7,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// li r17,-96
	r17.s64 = -96;
	// li r18,-80
	r18.s64 = -80;
	// li r19,-64
	r19.s64 = -64;
	// li r20,-48
	r20.s64 = -48;
	// li r21,-32
	r21.s64 = -32;
	// li r6,-16
	ctx.r6.s64 = -16;
	// li r22,16
	r22.s64 = 16;
	// li r23,32
	r23.s64 = 32;
	// li r24,48
	r24.s64 = 48;
	// li r25,-1040
	r25.s64 = -1040;
	// li r26,1008
	r26.s64 = 1008;
	// li r27,2032
	r27.s64 = 2032;
	// li r28,3056
	r28.s64 = 3056;
	// li r29,-2048
	r29.s64 = -2048;
	// li r30,-1024
	r30.s64 = -1024;
	// li r31,1024
	r31.s64 = 1024;
	// li r4,2048
	ctx.r4.s64 = 2048;
	// li r5,3072
	ctx.r5.s64 = 3072;
	// li r3,-112
	ctx.r3.s64 = -112;
loc_8240D648:
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v47,v0,v49
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v47.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v49.f32)));
	// lvx128 v61,r11,r3
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// lvx128 v60,r11,r17
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v53,v63,v61,v7
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v59,r11,r18
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v51,v63,v60,v4
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// lvx128 v58,r11,r19
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v61,v61,v60,v7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v57,r11,r20
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v52,v59,v58,v7
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v55,r11,r6
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v60,v58,v57,v7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v56,r11,r21
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v50,v59,v57,v4
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v58,v56,v55,v7
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v54,r11,r22
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v56,v56,v62,v4
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// lvx128 v63,r11,r23
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v62,v55,v62,v7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v59,r11,r24
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v57,v54,v63,v7
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vperm128 v54,v54,v59,v4
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// addi r9,r9,192
	ctx.r9.s64 = ctx.r9.s64 + 192;
	// vperm128 v63,v63,v59,v7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// addi r11,r11,192
	r11.s64 = r11.s64 + 192;
	// vperm128 v42,v61,v60,v6
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vperm128 v38,v58,v57,v6
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vperm128 v46,v53,v52,v6
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vperm128 v45,v53,v52,v5
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vperm128 v40,v61,v60,v5
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vmulfp128 v33,v42,v0
	simde_mm_store_ps(v33.f32, simde_mm_mul_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vperm128 v36,v58,v57,v5
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vmulfp128 v59,v38,v47
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v47.f32)));
	// vperm128 v44,v51,v50,v6
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vmulfp128 v41,v46,v0
	simde_mm_store_ps(v41.f32, simde_mm_mul_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vperm128 v43,v51,v50,v5
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vmulfp128 v39,v45,v0
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vperm128 v32,v56,v54,v5
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vmulfp128 v61,v40,v0
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vperm128 v34,v56,v54,v6
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vmulfp128 v57,v36,v47
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v47.f32)));
	// vperm128 v60,v62,v63,v6
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vmulfp128 v37,v44,v0
	simde_mm_store_ps(v37.f32, simde_mm_mul_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vperm128 v58,v62,v63,v5
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vmulfp128 v35,v43,v0
	simde_mm_store_ps(v35.f32, simde_mm_mul_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v55,v32,v47
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v47.f32)));
	// vmulfp128 v56,v34,v47
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v47.f32)));
	// vmulfp128 v54,v60,v47
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v47.f32)));
	// vmulfp128 v53,v58,v47
	simde_mm_store_ps(v53.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v47.f32)));
	// stvx128 v33,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v0,v0,v48
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v48.f32)));
	// stvx128 v41,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r7,32
	ctx.r7.s64 = ctx.r7.s64 + 32;
	// stvx128 v39,r10,r25
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r10,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r10,r26
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r10,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r10,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r10,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r10,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r10,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// bne 0x8240d648
	if (!cr0.eq) goto loc_8240D648;
	// lwz r3,244(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 244);
loc_8240D75C:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// subf r10,r11,r9
	ctx.r10.s64 = ctx.r9.s64 - r11.s64;
	// lbz r11,13(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// divwu r10,r10,r9
	ctx.r10.u32 = ctx.r10.u32 / ctx.r9.u32;
	// twllei r9,0
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x8240d784
	if (!cr6.lt) goto loc_8240D784;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8240D784:
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// subf r11,r9,r7
	r11.s64 = ctx.r7.s64 - ctx.r9.s64;
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// rlwinm r11,r11,30,2,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8240d7a4
	if (cr6.lt) goto loc_8240D7A4;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8240D7A4:
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_8240D7B0"))) PPC_WEAK_FUNC(sub_8240D7B0);
PPC_FUNC_IMPL(__imp__sub_8240D7B0) {
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
	// bl 0x823d91f0
	ctx.lr = 0x8240D7B8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lbz r29,13(r3)
	r29.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// lwz r7,28(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mullw r6,r29,r10
	ctx.r6.s64 = int64_t(r29.s32) * int64_t(ctx.r10.s32);
	// lwz r30,4(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r28,24(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r31,20(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r11,r6,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r7,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r9,r10,r30
	ctx.r9.s64 = r30.s64 - ctx.r10.s64;
	// subf r7,r7,r28
	ctx.r7.s64 = r28.s64 - ctx.r7.s64;
	// add r10,r11,r4
	ctx.r10.u64 = r11.u64 + ctx.r4.u64;
	// add r11,r8,r31
	r11.u64 = ctx.r8.u64 + r31.u64;
	// cmpw cr6,r9,r7
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, xer);
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// blt cr6,0x8240d804
	if (cr6.lt) goto loc_8240D804;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
loc_8240D804:
	// or r9,r6,r11
	ctx.r9.u64 = ctx.r6.u64 | r11.u64;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// clrlwi r5,r8,28
	ctx.r5.u64 = ctx.r8.u32 & 0xF;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8240d824
	if (cr6.eq) goto loc_8240D824;
	// bl 0x82408080
	ctx.lr = 0x8240D81C;
	sub_82408080(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8240D824:
	// rlwinm r5,r6,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r5,127
	ctx.r8.s64 = ctx.r5.s64 + 127;
	// rlwinm r8,r8,25,7,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8240d850
	if (cr6.eq) goto loc_8240D850;
loc_8240D83C:
	// rlwinm r27,r9,7,0,24
	r27.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// dcbt r27,r10
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// blt cr6,0x8240d83c
	if (cr6.lt) goto loc_8240D83C;
loc_8240D850:
	// extsw r9,r7
	ctx.r9.s64 = ctx.r7.s32;
	// lfs f0,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	f0.f64 = double(temp.f32);
	// extsw r8,r5
	ctx.r8.s64 = ctx.r5.s32;
	// lfs f13,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f10,88(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fsubs f9,f13,f0
	ctx.f9.f64 = double(float(ctx.f13.f64 - f0.f64));
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// addi r8,r5,6560
	ctx.r8.s64 = ctx.r5.s64 + 6560;
	// lvlx128 v63,r0,r27
	temp.u32 = r27.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r5,r9,-3840
	ctx.r5.s64 = ctx.r9.s64 + -3840;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// vspltw128 v13,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// addi r26,r1,88
	r26.s64 = ctx.r1.s64 + 88;
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// lfs f12,-17876(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -17876);
	ctx.f12.f64 = double(temp.f32);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fdivs f13,f9,f6
	ctx.f13.f64 = double(float(ctx.f9.f64 / ctx.f6.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v62,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fmadds f4,f5,f13,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + f0.f64));
	// stfs f4,36(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f3,f13,f12
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lvx128 v11,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f3,88(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx128 v61,r0,r26
	temp.u32 = r26.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v61,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vspltw128 v12,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vaddfp128 v62,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v62.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32)));
	// vmaddfp v0,v12,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v13,v12,v11,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// ble cr6,0x8240d978
	if (!cr6.gt) goto loc_8240D978;
	// addi r9,r6,-1
	ctx.r9.s64 = ctx.r6.s64 + -1;
	// li r8,16
	ctx.r8.s64 = 16;
	// rlwinm r9,r9,28,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0xFFFFFFF;
	// li r6,32
	ctx.r6.s64 = 32;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// li r7,48
	ctx.r7.s64 = 48;
loc_8240D910:
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v59,v13,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v63.f32)));
	// lvx128 v58,r10,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vupkhsb128 v57,v60,v96
	simde_mm_store_si128((simde__m128i*)v57.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v60.s16), simde_mm_load_si128((simde__m128i*)v60.s16))));
	// vupklsb128 v56,v60,v96
	simde_mm_store_si128((simde__m128i*)v56.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)v60.s16)));
	// vaddfp128 v55,v0,v63
	simde_mm_store_ps(v55.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v63.f32)));
	// vupkhsb128 v54,v58,v96
	simde_mm_store_si128((simde__m128i*)v54.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v58.s16), simde_mm_load_si128((simde__m128i*)v58.s16))));
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// vupklsb128 v53,v58,v96
	simde_mm_store_si128((simde__m128i*)v53.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)v58.s16)));
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// vcsxwfp128 v52,v57,15
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v57.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vcsxwfp128 v51,v56,15
	simde_mm_store_ps(v51.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v56.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vcsxwfp128 v50,v54,15
	simde_mm_store_ps(v50.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v54.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vcsxwfp128 v49,v53,15
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v53.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vmulfp128 v48,v52,v13
	simde_mm_store_ps(v48.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v47,v51,v0
	simde_mm_store_ps(v47.f32, simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v46,v50,v59
	simde_mm_store_ps(v46.f32, simde_mm_mul_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v59.f32)));
	// vmulfp128 v45,v49,v55
	simde_mm_store_ps(v45.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v55.f32)));
	// vaddfp128 v0,v0,v62
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v62.f32)));
	// vaddfp128 v13,v13,v62
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// bne 0x8240d910
	if (!cr0.eq) goto loc_8240D910;
loc_8240D978:
	// rlwinm r9,r29,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r10,r4,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r4.s64;
	// twllei r9,0
	// divwu r10,r10,r9
	ctx.r10.u32 = ctx.r10.u32 / ctx.r9.u32;
	// cmplw cr6,r10,r30
	cr6.compare<uint32_t>(ctx.r10.u32, r30.u32, xer);
	// blt cr6,0x8240d994
	if (cr6.lt) goto loc_8240D994;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
loc_8240D994:
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// rlwinm r11,r11,30,2,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r11,r28
	cr6.compare<uint32_t>(r11.u32, r28.u32, xer);
	// blt cr6,0x8240d9ac
	if (cr6.lt) goto loc_8240D9AC;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_8240D9AC:
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8240D9B8"))) PPC_WEAK_FUNC(sub_8240D9B8);
PPC_FUNC_IMPL(__imp__sub_8240D9B8) {
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
	ctx.lr = 0x8240D9C0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lbz r30,13(r3)
	r30.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// lwz r7,28(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mullw r6,r30,r10
	ctx.r6.s64 = int64_t(r30.s32) * int64_t(ctx.r10.s32);
	// lwz r31,4(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r29,24(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,20(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r11,r6,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r9,r10,r31
	ctx.r9.s64 = r31.s64 - ctx.r10.s64;
	// rlwinm r8,r7,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r6,r7,r29
	ctx.r6.s64 = r29.s64 - ctx.r7.s64;
	// add r10,r11,r5
	ctx.r10.u64 = r11.u64 + ctx.r5.u64;
	// add r11,r8,r4
	r11.u64 = ctx.r8.u64 + ctx.r4.u64;
	// cmpw cr6,r9,r6
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r6.s32, xer);
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// blt cr6,0x8240da0c
	if (cr6.lt) goto loc_8240DA0C;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
loc_8240DA0C:
	// clrlwi r9,r7,29
	ctx.r9.u64 = ctx.r7.u32 & 0x7;
	// or r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 | r11.u64;
	// or r9,r8,r10
	ctx.r9.u64 = ctx.r8.u64 | ctx.r10.u64;
	// clrlwi r8,r9,28
	ctx.r8.u64 = ctx.r9.u32 & 0xF;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x8240da30
	if (cr6.eq) goto loc_8240DA30;
	// bl 0x824081c0
	ctx.lr = 0x8240DA28;
	sub_824081C0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8240DA30:
	// rlwinm r8,r7,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r8,127
	ctx.r8.s64 = ctx.r8.s64 + 127;
	// rlwinm r8,r8,25,7,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8240da5c
	if (cr6.eq) goto loc_8240DA5C;
loc_8240DA48:
	// rlwinm r28,r9,7,0,24
	r28.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// dcbt r28,r10
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// blt cr6,0x8240da48
	if (cr6.lt) goto loc_8240DA48;
loc_8240DA5C:
	// extsw r9,r6
	ctx.r9.s64 = ctx.r6.s32;
	// lfs f0,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	f0.f64 = double(temp.f32);
	// rlwinm r8,r7,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f13,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f9,88(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r8,-32250
	ctx.r8.s64 = -2113536000;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lvlx128 v63,r0,r28
	temp.u32 = r28.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r8,r8,-3840
	ctx.r8.s64 = ctx.r8.s64 + -3840;
	// addi r27,r1,88
	r27.s64 = ctx.r1.s64 + 88;
	// vspltw128 v0,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// lfs f12,12428(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 12428);
	ctx.f12.f64 = double(temp.f32);
	// fcfid f7,f9
	ctx.f7.f64 = double(ctx.f9.s64);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fdivs f13,f10,f6
	ctx.f13.f64 = double(float(ctx.f10.f64 / ctx.f6.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v61,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fmadds f4,f5,f13,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + f0.f64));
	// stfs f4,36(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lvx128 v12,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f3,f13,f12
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// stfs f3,88(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx128 v60,r0,r27
	temp.u32 = r27.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v62,v60,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vspltw128 v13,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vaddfp128 v61,v62,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v62.f32)));
	// vmaddfp v0,v13,v12,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// ble cr6,0x8240db84
	if (!cr6.gt) goto loc_8240DB84;
	// addi r9,r7,-1
	ctx.r9.s64 = ctx.r7.s64 + -1;
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// rlwinm r9,r9,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r28,r7,6432
	r28.s64 = ctx.r7.s64 + 6432;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r6,1024
	ctx.r6.s64 = 1024;
	// li r7,1040
	ctx.r7.s64 = 1040;
	// lvx128 v7,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8240DB1C:
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v59,v0,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v62.f32)));
	// vperm128 v58,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v63,r10,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v57,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// vupkhsb128 v56,v58,v96
	simde_mm_store_si128((simde__m128i*)v56.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v58.s16), simde_mm_load_si128((simde__m128i*)v58.s16))));
	// vupklsb128 v55,v58,v96
	simde_mm_store_si128((simde__m128i*)v55.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)v58.s16)));
	// vupkhsb128 v54,v57,v96
	simde_mm_store_si128((simde__m128i*)v54.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v57.s16), simde_mm_load_si128((simde__m128i*)v57.s16))));
	// vupklsb128 v53,v57,v96
	simde_mm_store_si128((simde__m128i*)v53.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)v57.s16)));
	// vcsxwfp128 v52,v56,15
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v56.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vcsxwfp128 v51,v55,15
	simde_mm_store_ps(v51.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v55.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vcsxwfp128 v50,v54,15
	simde_mm_store_ps(v50.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v54.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vcsxwfp128 v49,v53,15
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v53.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vmulfp128 v48,v52,v0
	simde_mm_store_ps(v48.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v47,v51,v0
	simde_mm_store_ps(v47.f32, simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v46,v50,v59
	simde_mm_store_ps(v46.f32, simde_mm_mul_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v59.f32)));
	// vmulfp128 v45,v49,v59
	simde_mm_store_ps(v45.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v59.f32)));
	// vaddfp128 v0,v0,v61
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// bne 0x8240db1c
	if (!cr0.eq) goto loc_8240DB1C;
loc_8240DB84:
	// rlwinm r9,r30,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r10,r5,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r5.s64;
	// twllei r9,0
	// divwu r10,r10,r9
	ctx.r10.u32 = ctx.r10.u32 / ctx.r9.u32;
	// cmplw cr6,r10,r31
	cr6.compare<uint32_t>(ctx.r10.u32, r31.u32, xer);
	// blt cr6,0x8240dba0
	if (cr6.lt) goto loc_8240DBA0;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
loc_8240DBA0:
	// subf r11,r4,r11
	r11.s64 = r11.s64 - ctx.r4.s64;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// rlwinm r11,r11,30,2,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// blt cr6,0x8240dbb8
	if (cr6.lt) goto loc_8240DBB8;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8240DBB8:
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8240DBC4"))) PPC_WEAK_FUNC(sub_8240DBC4);
PPC_FUNC_IMPL(__imp__sub_8240DBC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8240DBC8"))) PPC_WEAK_FUNC(sub_8240DBC8);
PPC_FUNC_IMPL(__imp__sub_8240DBC8) {
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
	// bl 0x823d91d8
	ctx.lr = 0x8240DBD0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lbz r11,13(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r7,24(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r5,28(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r21,0(r3)
	r21.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r20,20(r3)
	r20.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// subf r11,r10,r9
	r11.s64 = ctx.r9.s64 - ctx.r10.s64;
	// rlwinm r10,r8,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r6,r5,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r5.s64;
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r21
	ctx.r9.u64 = ctx.r10.u64 + r21.u64;
	// add r7,r8,r20
	ctx.r7.u64 = ctx.r8.u64 + r20.u64;
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// blt cr6,0x8240dc1c
	if (cr6.lt) goto loc_8240DC1C;
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
loc_8240DC1C:
	// clrlwi r11,r10,29
	r11.u64 = ctx.r10.u32 & 0x7;
	// or r8,r11,r7
	ctx.r8.u64 = r11.u64 | ctx.r7.u64;
	// or r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 | ctx.r9.u64;
	// clrlwi r4,r5,28
	ctx.r4.u64 = ctx.r5.u32 & 0xF;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8240dc40
	if (cr6.eq) goto loc_8240DC40;
	// bl 0x824084c8
	ctx.lr = 0x8240DC38;
	sub_824084C8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9228
	return;
loc_8240DC40:
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// li r11,0
	r11.s64 = 0;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r8,127
	ctx.r5.s64 = ctx.r8.s64 + 127;
	// rlwinm r8,r5,25,7,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8240dc74
	if (cr6.eq) goto loc_8240DC74;
loc_8240DC60:
	// rlwinm r5,r11,7,0,24
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// dcbt r5,r9
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// blt cr6,0x8240dc60
	if (cr6.lt) goto loc_8240DC60;
loc_8240DC74:
	// extsw r11,r6
	r11.s64 = ctx.r6.s32;
	// lfs f0,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	f0.f64 = double(temp.f32);
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f13,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// extsw r6,r8
	ctx.r6.s64 = ctx.r8.s32;
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lis r4,-32250
	ctx.r4.s64 = -2113536000;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f9,88(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r8,r4,-3840
	ctx.r8.s64 = ctx.r4.s64 + -3840;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfs f12,12428(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12428);
	ctx.f12.f64 = double(temp.f32);
	// lvlx128 v63,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v0,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// fcfid f7,f9
	ctx.f7.f64 = double(ctx.f9.s64);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fdivs f13,f10,f6
	ctx.f13.f64 = double(float(ctx.f10.f64 / ctx.f6.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v62,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// fmadds f4,f5,f13,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + f0.f64));
	// stfs f4,36(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lvx128 v12,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f3,f13,f12
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// stfs f3,88(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx128 v61,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v58,v61,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vaddfp128 v57,v58,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_add_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v58.f32)));
	// vmaddfp v0,v13,v12,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// ble cr6,0x8240dec8
	if (!cr6.gt) goto loc_8240DEC8;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// lis r4,-32250
	ctx.r4.s64 = -2113536000;
	// lis r31,-32250
	r31.s64 = -2113536000;
	// lis r30,-32250
	r30.s64 = -2113536000;
	// lis r29,-32250
	r29.s64 = -2113536000;
	// addi r6,r6,6448
	ctx.r6.s64 = ctx.r6.s64 + 6448;
	// addi r5,r5,6496
	ctx.r5.s64 = ctx.r5.s64 + 6496;
	// addi r4,r4,6464
	ctx.r4.s64 = ctx.r4.s64 + 6464;
	// addi r31,r31,6512
	r31.s64 = r31.s64 + 6512;
	// addi r30,r30,6480
	r30.s64 = r30.s64 + 6480;
	// addi r29,r29,6528
	r29.s64 = r29.s64 + 6528;
	// lvx128 v2,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// lvx128 v3,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r7,2064
	r11.s64 = ctx.r7.s64 + 2064;
	// rlwinm r8,r10,29,3,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// lvx128 v5,r0,r31
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v6,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r9,80
	ctx.r10.s64 = ctx.r9.s64 + 80;
	// lvx128 v7,r0,r29
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// li r22,-64
	r22.s64 = -64;
	// li r23,-32
	r23.s64 = -32;
	// li r6,-16
	ctx.r6.s64 = -16;
	// li r24,-48
	r24.s64 = -48;
	// li r25,-1040
	r25.s64 = -1040;
	// li r26,1008
	r26.s64 = 1008;
	// li r27,2032
	r27.s64 = 2032;
	// li r28,3056
	r28.s64 = 3056;
	// li r29,-2048
	r29.s64 = -2048;
	// li r30,-1024
	r30.s64 = -1024;
	// li r31,1024
	r31.s64 = 1024;
	// li r4,2048
	ctx.r4.s64 = 2048;
	// li r5,3072
	ctx.r5.s64 = 3072;
loc_8240DDA0:
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v56,v0,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v58.f32)));
	// lvx128 v61,r10,r22
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// lvx128 v60,r10,r23
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v55,v63,v61,v7
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v59,r10,r6
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v54,v63,v61,v5
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vperm128 v53,v63,v61,v3
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)));
	// lvx128 v63,r10,r24
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v52,v60,v59,v7
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v51,v60,v59,v5
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// addi r9,r9,96
	ctx.r9.s64 = ctx.r9.s64 + 96;
	// vperm128 v50,v60,v59,v3
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)));
	// addi r10,r10,96
	ctx.r10.s64 = ctx.r10.s64 + 96;
	// vperm128 v49,v55,v63,v6
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vperm128 v48,v54,v63,v4
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// vperm128 v47,v53,v63,v2
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// vperm128 v46,v52,v62,v6
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vperm128 v45,v51,v62,v4
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// vperm128 v44,v50,v62,v2
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// vupkhsb128 v43,v49,v96
	simde_mm_store_si128((simde__m128i*)v43.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v49.s16), simde_mm_load_si128((simde__m128i*)v49.s16))));
	// vupklsb128 v42,v49,v96
	simde_mm_store_si128((simde__m128i*)v42.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)v49.s16)));
	// vupkhsb128 v41,v48,v96
	simde_mm_store_si128((simde__m128i*)v41.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v48.s16), simde_mm_load_si128((simde__m128i*)v48.s16))));
	// vupklsb128 v40,v48,v96
	simde_mm_store_si128((simde__m128i*)v40.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)v48.s16)));
	// vupkhsb128 v39,v47,v96
	simde_mm_store_si128((simde__m128i*)v39.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v47.s16), simde_mm_load_si128((simde__m128i*)v47.s16))));
	// vcsxwfp128 v38,v43,15
	simde_mm_store_ps(v38.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v43.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vupklsb128 v37,v47,v96
	simde_mm_store_si128((simde__m128i*)v37.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)v47.s16)));
	// vcsxwfp128 v36,v42,15
	simde_mm_store_ps(v36.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v42.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vupkhsb128 v35,v46,v96
	simde_mm_store_si128((simde__m128i*)v35.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v46.s16), simde_mm_load_si128((simde__m128i*)v46.s16))));
	// vcsxwfp128 v34,v41,15
	simde_mm_store_ps(v34.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v41.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vupklsb128 v33,v46,v96
	simde_mm_store_si128((simde__m128i*)v33.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)v46.s16)));
	// vcsxwfp128 v32,v40,15
	simde_mm_store_ps(v32.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v40.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vupkhsb128 v63,v45,v96
	simde_mm_store_si128((simde__m128i*)v63.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v45.s16), simde_mm_load_si128((simde__m128i*)v45.s16))));
	// vcsxwfp128 v62,v39,15
	simde_mm_store_ps(v62.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v39.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vupklsb128 v61,v45,v96
	simde_mm_store_si128((simde__m128i*)v61.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)v45.s16)));
	// vcsxwfp128 v60,v37,15
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v37.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vupkhsb128 v59,v44,v96
	simde_mm_store_si128((simde__m128i*)v59.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v44.s16), simde_mm_load_si128((simde__m128i*)v44.s16))));
	// vcsxwfp128 v55,v35,15
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v35.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vupklsb128 v54,v44,v96
	simde_mm_store_si128((simde__m128i*)v54.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)v44.s16)));
	// vcsxwfp128 v53,v33,15
	simde_mm_store_ps(v53.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v33.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vcsxwfp128 v52,v63,15
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v63.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vcsxwfp128 v51,v61,15
	simde_mm_store_ps(v51.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v61.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vcsxwfp128 v50,v59,15
	simde_mm_store_ps(v50.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v59.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vcsxwfp128 v49,v54,15
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v54.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vmulfp128 v48,v38,v0
	simde_mm_store_ps(v48.f32, simde_mm_mul_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v47,v36,v0
	simde_mm_store_ps(v47.f32, simde_mm_mul_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v46,v34,v0
	simde_mm_store_ps(v46.f32, simde_mm_mul_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v45,v32,v0
	simde_mm_store_ps(v45.f32, simde_mm_mul_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v44,v62,v0
	simde_mm_store_ps(v44.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v43,v60,v0
	simde_mm_store_ps(v43.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v42,v55,v56
	simde_mm_store_ps(v42.f32, simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v56.f32)));
	// vmulfp128 v41,v53,v56
	simde_mm_store_ps(v41.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v56.f32)));
	// vmulfp128 v40,v52,v56
	simde_mm_store_ps(v40.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v56.f32)));
	// vmulfp128 v39,v51,v56
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v56.f32)));
	// vmulfp128 v38,v50,v56
	simde_mm_store_ps(v38.f32, simde_mm_mul_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v56.f32)));
	// vmulfp128 v37,v49,v56
	simde_mm_store_ps(v37.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v56.f32)));
	// stvx128 v48,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v0,v0,v57
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v47,r11,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r7,32
	ctx.r7.s64 = ctx.r7.s64 + 32;
	// stvx128 v46,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v40,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r11,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r11,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// bne 0x8240dda0
	if (!cr0.eq) goto loc_8240DDA0;
loc_8240DEC8:
	// lbz r11,13(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// subf r9,r21,r9
	ctx.r9.s64 = ctx.r9.s64 - r21.s64;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rotlwi r8,r11,1
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 1);
	// divwu r11,r9,r8
	r11.u32 = ctx.r9.u32 / ctx.r8.u32;
	// twllei r8,0
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8240deec
	if (cr6.lt) goto loc_8240DEEC;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8240DEEC:
	// subf r9,r20,r7
	ctx.r9.s64 = ctx.r7.s64 - r20.s64;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// rlwinm r11,r9,30,2,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8240df08
	if (cr6.lt) goto loc_8240DF08;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8240DF08:
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8240DF14"))) PPC_WEAK_FUNC(sub_8240DF14);
PPC_FUNC_IMPL(__imp__sub_8240DF14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8240DF18"))) PPC_WEAK_FUNC(sub_8240DF18);
PPC_FUNC_IMPL(__imp__sub_8240DF18) {
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
	// bl 0x823d91e8
	ctx.lr = 0x8240DF20;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r8,28(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lbz r26,13(r3)
	r26.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// rlwinm r9,r8,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r27,4(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r25,24(r3)
	r25.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mullw r10,r26,r11
	ctx.r10.s64 = int64_t(r26.s32) * int64_t(r11.s32);
	// lwz r28,20(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r29,0(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// subf r11,r11,r27
	r11.s64 = r27.s64 - r11.s64;
	// subf r7,r8,r25
	ctx.r7.s64 = r25.s64 - ctx.r8.s64;
	// add r8,r9,r28
	ctx.r8.u64 = ctx.r9.u64 + r28.u64;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// blt cr6,0x8240df68
	if (cr6.lt) goto loc_8240DF68;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
loc_8240DF68:
	// or r11,r8,r10
	r11.u64 = ctx.r8.u64 | ctx.r10.u64;
	// clrlwi r6,r11,28
	ctx.r6.u64 = r11.u32 & 0xF;
	// or r5,r6,r9
	ctx.r5.u64 = ctx.r6.u64 | ctx.r9.u64;
	// clrlwi r4,r5,27
	ctx.r4.u64 = ctx.r5.u32 & 0x1F;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8240df8c
	if (cr6.eq) goto loc_8240DF8C;
	// bl 0x824087f0
	ctx.lr = 0x8240DF84;
	sub_824087F0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_8240DF8C:
	// addi r6,r9,127
	ctx.r6.s64 = ctx.r9.s64 + 127;
	// li r11,0
	r11.s64 = 0;
	// rlwinm r6,r6,25,7,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8240dfb4
	if (cr6.eq) goto loc_8240DFB4;
loc_8240DFA0:
	// rlwinm r5,r11,7,0,24
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 7) & 0xFFFFFF80;
	// dcbt r5,r10
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplw cr6,r11,r6
	cr6.compare<uint32_t>(r11.u32, ctx.r6.u32, xer);
	// blt cr6,0x8240dfa0
	if (cr6.lt) goto loc_8240DFA0;
loc_8240DFB4:
	// extsw r11,r7
	r11.s64 = ctx.r7.s32;
	// lfs f0,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	f0.f64 = double(temp.f32);
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f13,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f9,88(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lis r4,-32250
	ctx.r4.s64 = -2113536000;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// lvlx128 v63,r0,r30
	temp.u32 = r30.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// vspltw128 v0,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// addi r4,r4,6608
	ctx.r4.s64 = ctx.r4.s64 + 6608;
	// fcfid f7,f9
	ctx.f7.f64 = double(ctx.f9.s64);
	// addi r11,r11,6592
	r11.s64 = r11.s64 + 6592;
	// addi r7,r7,6560
	ctx.r7.s64 = ctx.r7.s64 + 6560;
	// addi r6,r6,-3840
	ctx.r6.s64 = ctx.r6.s64 + -3840;
	// lis r31,-32254
	r31.s64 = -2113798144;
	// addi r24,r1,88
	r24.s64 = ctx.r1.s64 + 88;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lfs f12,15000(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 15000);
	ctx.f12.f64 = double(temp.f32);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fdivs f13,f10,f6
	ctx.f13.f64 = double(float(ctx.f10.f64 / ctx.f6.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v62,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fmadds f4,f5,f13,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + f0.f64));
	// stfs f4,36(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lvx128 v13,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f3,f13,f12
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lvx128 v12,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v9,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f3,88(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx128 v61,r0,r24
	temp.u32 = r24.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v61,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vspltw128 v10,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vaddfp128 v62,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v62.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32)));
	// vmaddfp v13,v10,v13,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v12,v10,v12,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v11,v10,v11,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v0,v10,v9,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// ble cr6,0x8240e184
	if (!cr6.gt) goto loc_8240E184;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// vspltisb v10,7
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_set1_epi8(char(0x7)));
	// addi r11,r8,96
	r11.s64 = ctx.r8.s64 + 96;
	// rlwinm r9,r9,27,5,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFF;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// vslb v10,v10,v10
	ctx.v10.u8[0] = ctx.v10.u8[0] << (ctx.v10.u8[0] & 0x7);
	ctx.v10.u8[1] = ctx.v10.u8[1] << (ctx.v10.u8[1] & 0x7);
	ctx.v10.u8[2] = ctx.v10.u8[2] << (ctx.v10.u8[2] & 0x7);
	ctx.v10.u8[3] = ctx.v10.u8[3] << (ctx.v10.u8[3] & 0x7);
	ctx.v10.u8[4] = ctx.v10.u8[4] << (ctx.v10.u8[4] & 0x7);
	ctx.v10.u8[5] = ctx.v10.u8[5] << (ctx.v10.u8[5] & 0x7);
	ctx.v10.u8[6] = ctx.v10.u8[6] << (ctx.v10.u8[6] & 0x7);
	ctx.v10.u8[7] = ctx.v10.u8[7] << (ctx.v10.u8[7] & 0x7);
	ctx.v10.u8[8] = ctx.v10.u8[8] << (ctx.v10.u8[8] & 0x7);
	ctx.v10.u8[9] = ctx.v10.u8[9] << (ctx.v10.u8[9] & 0x7);
	ctx.v10.u8[10] = ctx.v10.u8[10] << (ctx.v10.u8[10] & 0x7);
	ctx.v10.u8[11] = ctx.v10.u8[11] << (ctx.v10.u8[11] & 0x7);
	ctx.v10.u8[12] = ctx.v10.u8[12] << (ctx.v10.u8[12] & 0x7);
	ctx.v10.u8[13] = ctx.v10.u8[13] << (ctx.v10.u8[13] & 0x7);
	ctx.v10.u8[14] = ctx.v10.u8[14] << (ctx.v10.u8[14] & 0x7);
	ctx.v10.u8[15] = ctx.v10.u8[15] << (ctx.v10.u8[15] & 0x7);
	// li r30,-80
	r30.s64 = -80;
	// li r31,-64
	r31.s64 = -64;
	// li r4,-48
	ctx.r4.s64 = -48;
	// li r5,-32
	ctx.r5.s64 = -32;
	// li r6,-16
	ctx.r6.s64 = -16;
loc_8240E0B0:
	// lvx128 v9,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v60,v0,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v63.f32)));
	// lvx128 v8,r10,r7
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddubm v7,v9,v10
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)));
	// vaddubm v6,v8,v10
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)));
	// vaddfp128 v59,v11,v63
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(v63.f32)));
	// vaddfp128 v58,v12,v63
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v63.f32)));
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// vaddfp128 v57,v13,v63
	simde_mm_store_ps(v57.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v63.f32)));
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// vupkhsb128 v56,v7,v0
	simde_mm_store_si128((simde__m128i*)v56.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v7.s8), simde_mm_load_si128((simde__m128i*)ctx.v7.s8))));
	// vupklsb128 v55,v7,v0
	simde_mm_store_si128((simde__m128i*)v55.s32, simde_mm_cvtepi8_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vupkhsb128 v54,v6,v0
	simde_mm_store_si128((simde__m128i*)v54.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v6.s8), simde_mm_load_si128((simde__m128i*)ctx.v6.s8))));
	// vupklsb128 v53,v6,v0
	simde_mm_store_si128((simde__m128i*)v53.s32, simde_mm_cvtepi8_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vupkhsb128 v52,v56,v96
	simde_mm_store_si128((simde__m128i*)v52.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v56.s16), simde_mm_load_si128((simde__m128i*)v56.s16))));
	// vupklsb128 v51,v56,v96
	simde_mm_store_si128((simde__m128i*)v51.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)v56.s16)));
	// vupkhsb128 v50,v55,v96
	simde_mm_store_si128((simde__m128i*)v50.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v55.s16), simde_mm_load_si128((simde__m128i*)v55.s16))));
	// vupklsb128 v49,v55,v96
	simde_mm_store_si128((simde__m128i*)v49.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)v55.s16)));
	// vupkhsb128 v48,v54,v96
	simde_mm_store_si128((simde__m128i*)v48.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v54.s16), simde_mm_load_si128((simde__m128i*)v54.s16))));
	// vcsxwfp128 v47,v52,7
	simde_mm_store_ps(v47.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v52.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vupklsb128 v46,v54,v96
	simde_mm_store_si128((simde__m128i*)v46.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)v54.s16)));
	// vcsxwfp128 v45,v51,7
	simde_mm_store_ps(v45.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v51.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vupkhsb128 v44,v53,v96
	simde_mm_store_si128((simde__m128i*)v44.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v53.s16), simde_mm_load_si128((simde__m128i*)v53.s16))));
	// vcsxwfp128 v43,v50,7
	simde_mm_store_ps(v43.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v50.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vupklsb128 v42,v53,v96
	simde_mm_store_si128((simde__m128i*)v42.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)v53.s16)));
	// vcsxwfp128 v41,v49,7
	simde_mm_store_ps(v41.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v49.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vcsxwfp128 v40,v48,7
	simde_mm_store_ps(v40.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v48.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vcsxwfp128 v39,v46,7
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v46.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vcsxwfp128 v38,v44,7
	simde_mm_store_ps(v38.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v44.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vcsxwfp128 v37,v42,7
	simde_mm_store_ps(v37.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v42.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vmulfp128 v36,v47,v0
	simde_mm_store_ps(v36.f32, simde_mm_mul_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v35,v45,v11
	simde_mm_store_ps(v35.f32, simde_mm_mul_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(ctx.v11.f32)));
	// vmulfp128 v34,v43,v12
	simde_mm_store_ps(v34.f32, simde_mm_mul_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v33,v41,v13
	simde_mm_store_ps(v33.f32, simde_mm_mul_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v32,v40,v60
	simde_mm_store_ps(v32.f32, simde_mm_mul_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v60.f32)));
	// vmulfp128 v61,v39,v59
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v59.f32)));
	// vmulfp128 v60,v38,v58
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v58.f32)));
	// vmulfp128 v59,v37,v57
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v57.f32)));
	// vaddfp128 v0,v0,v62
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v62.f32)));
	// vaddfp128 v13,v13,v62
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v62.f32)));
	// vaddfp128 v12,v12,v62
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v62.f32)));
	// vaddfp128 v11,v11,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v36,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r8,128
	ctx.r8.s64 = ctx.r8.s64 + 128;
	// stvx128 v35,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r11,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v33,r11,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v32,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// bne 0x8240e0b0
	if (!cr0.eq) goto loc_8240E0B0;
loc_8240E184:
	// subf r11,r29,r10
	r11.s64 = ctx.r10.s64 - r29.s64;
	// twllei r26,0
	// divwu r11,r11,r26
	r11.u32 = r11.u32 / r26.u32;
	// cmplw cr6,r11,r27
	cr6.compare<uint32_t>(r11.u32, r27.u32, xer);
	// blt cr6,0x8240e19c
	if (cr6.lt) goto loc_8240E19C;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_8240E19C:
	// subf r10,r28,r8
	ctx.r10.s64 = ctx.r8.s64 - r28.s64;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// rlwinm r11,r10,30,2,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r11,r25
	cr6.compare<uint32_t>(r11.u32, r25.u32, xer);
	// blt cr6,0x8240e1b4
	if (cr6.lt) goto loc_8240E1B4;
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8240E1B4:
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8240E1C0"))) PPC_WEAK_FUNC(sub_8240E1C0);
PPC_FUNC_IMPL(__imp__sub_8240E1C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
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
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r8,13(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// subf r5,r11,r10
	ctx.r5.s64 = ctx.r10.s64 - r11.s64;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mullw r10,r8,r9
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,20(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// srawi r31,r5,1
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	r31.s64 = ctx.r5.s32 >> 1;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r9,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r9.s64;
	// addze r9,r31
	temp.s64 = r31.s64 + xer.ca;
	xer.ca = temp.u32 < r31.u32;
	ctx.r9.s64 = temp.s64;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// add r8,r6,r7
	ctx.r8.u64 = ctx.r6.u64 + ctx.r7.u64;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x8240e220
	if (!cr6.lt) goto loc_8240E220;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_8240E220:
	// clrlwi r10,r9,30
	ctx.r10.u64 = ctx.r9.u32 & 0x3;
	// or r7,r10,r8
	ctx.r7.u64 = ctx.r10.u64 | ctx.r8.u64;
	// or r6,r7,r11
	ctx.r6.u64 = ctx.r7.u64 | r11.u64;
	// clrlwi r4,r6,28
	ctx.r4.u64 = ctx.r6.u32 & 0xF;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8240e240
	if (cr6.eq) goto loc_8240E240;
	// bl 0x82409798
	ctx.lr = 0x8240E23C;
	sub_82409798(ctx, base);
	// b 0x8240e3e0
	goto loc_8240E3E0;
loc_8240E240:
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r7,r7,127
	ctx.r7.s64 = ctx.r7.s64 + 127;
	// rlwinm r7,r7,25,7,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8240e26c
	if (cr6.eq) goto loc_8240E26C;
loc_8240E258:
	// rlwinm r6,r10,7,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 7) & 0xFFFFFF80;
	// dcbt r6,r11
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r10,r7
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, xer);
	// blt cr6,0x8240e258
	if (cr6.lt) goto loc_8240E258;
loc_8240E26C:
	// extsw r10,r5
	ctx.r10.s64 = ctx.r5.s32;
	// lfs f0,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	f0.f64 = double(temp.f32);
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f13,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// std r10,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lis r4,-32250
	ctx.r4.s64 = -2113536000;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f10,96(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// addi r7,r4,6560
	ctx.r7.s64 = ctx.r4.s64 + 6560;
	// lfs f9,52(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f9.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// lis r31,-32253
	r31.s64 = -2113732608;
	// addi r6,r10,-3840
	ctx.r6.s64 = ctx.r10.s64 + -3840;
	// lvlx128 v63,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// fcfid f8,f12
	ctx.f8.f64 = double(ctx.f12.s64);
	// addi r10,r10,6624
	ctx.r10.s64 = ctx.r10.s64 + 6624;
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// addi r30,r1,96
	r30.s64 = ctx.r1.s64 + 96;
	// lfs f12,-17876(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -17876);
	ctx.f12.f64 = double(temp.f32);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stfs f9,108(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v60.f32)));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f6,f8
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fdivs f13,f11,f6
	ctx.f13.f64 = double(float(ctx.f11.f64 / ctx.f6.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v59,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fmadds f4,f5,f13,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + f0.f64));
	// stfs f4,36(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lvx128 v0,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f3,f13,f12
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lvx128 v11,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f3,96(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v58,r0,r30
	temp.u32 = r30.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vspltw128 v56,v59,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// vmulfp128 v61,v57,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v60.f32)));
	// vmulfp128 v12,v56,v60
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v60.f32)));
	// vmaddfp v0,v12,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v13,v12,v11,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// ble cr6,0x8240e38c
	if (!cr6.gt) goto loc_8240E38C;
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// li r9,16
	ctx.r9.s64 = 16;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_8240E34C:
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// vsldoi128 v55,v62,v63,12
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8), 4));
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// vaddfp128 v54,v55,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v54.f32, simde_mm_add_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v63.f32)));
	// vmrghw128 v53,v54,v63
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrglw128 v52,v54,v63
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmulfp128 v51,v53,v13
	simde_mm_store_ps(v51.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v50,v52,v0
	simde_mm_store_ps(v50.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vaddfp128 v0,v0,v61
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v61.f32)));
	// vaddfp128 v13,v13,v61
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v51,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r8,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r8,32
	ctx.r8.s64 = ctx.r8.s64 + 32;
	// bne 0x8240e34c
	if (!cr0.eq) goto loc_8240E34C;
loc_8240E38C:
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	f0.f64 = double(temp.f32);
	// stfs f0,52(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// subf r6,r10,r11
	ctx.r6.s64 = r11.s64 - ctx.r10.s64;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lbz r9,13(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// rotlwi r7,r9,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// divwu r10,r6,r7
	ctx.r10.u32 = ctx.r6.u32 / ctx.r7.u32;
	// twllei r7,0
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x8240e3bc
	if (cr6.lt) goto loc_8240E3BC;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8240E3BC:
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// subf r10,r11,r8
	ctx.r10.s64 = ctx.r8.s64 - r11.s64;
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x8240e3dc
	if (!cr6.lt) goto loc_8240E3DC;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8240E3DC:
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
loc_8240E3E0:
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

__attribute__((alias("__imp__sub_8240E3F8"))) PPC_WEAK_FUNC(sub_8240E3F8);
PPC_FUNC_IMPL(__imp__sub_8240E3F8) {
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
	// bl 0x823d91fc
	ctx.lr = 0x8240E400;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r8,13(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// subf r5,r11,r10
	ctx.r5.s64 = ctx.r10.s64 - r11.s64;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mullw r10,r8,r9
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,20(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// srawi r8,r5,1
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 1;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r9,r9,r4
	ctx.r9.s64 = ctx.r4.s64 - ctx.r9.s64;
	// addze r8,r8
	temp.s64 = ctx.r8.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r8.s64 = temp.s64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// add r11,r6,r7
	r11.u64 = ctx.r6.u64 + ctx.r7.u64;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bge cr6,0x8240e450
	if (!cr6.lt) goto loc_8240E450;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
loc_8240E450:
	// clrlwi r9,r8,29
	ctx.r9.u64 = ctx.r8.u32 & 0x7;
	// or r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 | r11.u64;
	// or r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 | ctx.r10.u64;
	// clrlwi r4,r6,28
	ctx.r4.u64 = ctx.r6.u32 & 0xF;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8240e474
	if (cr6.eq) goto loc_8240E474;
	// bl 0x8240a098
	ctx.lr = 0x8240E46C;
	sub_8240A098(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
loc_8240E474:
	// rlwinm r6,r8,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r7,r6,127
	ctx.r7.s64 = ctx.r6.s64 + 127;
	// rlwinm r7,r7,25,7,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8240e4a0
	if (cr6.eq) goto loc_8240E4A0;
loc_8240E48C:
	// rlwinm r4,r9,7,0,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// dcbt r4,r10
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r9,r7
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, xer);
	// blt cr6,0x8240e48c
	if (cr6.lt) goto loc_8240E48C;
loc_8240E4A0:
	// extsw r9,r5
	ctx.r9.s64 = ctx.r5.s32;
	// lfs f0,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	f0.f64 = double(temp.f32);
	// extsw r7,r6
	ctx.r7.s64 = ctx.r6.s32;
	// lfs f13,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// std r7,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r7.u64);
	// lfd f10,88(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fsubs f9,f13,f0
	ctx.f9.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lhz r9,52(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 52);
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r4,-32250
	ctx.r4.s64 = -2113536000;
	// lis r30,-32250
	r30.s64 = -2113536000;
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// sth r9,110(r1)
	PPC_STORE_U16(ctx.r1.u32 + 110, ctx.r9.u16);
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// addi r5,r5,6592
	ctx.r5.s64 = ctx.r5.s64 + 6592;
	// addi r4,r4,6560
	ctx.r4.s64 = ctx.r4.s64 + 6560;
	// addi r30,r30,6608
	r30.s64 = r30.s64 + 6608;
	// addi r7,r7,-3840
	ctx.r7.s64 = ctx.r7.s64 + -3840;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// addi r29,r1,96
	r29.s64 = ctx.r1.s64 + 96;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// lfs f12,15000(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 15000);
	ctx.f12.f64 = double(temp.f32);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// lvlx128 v63,r0,r31
	temp.u32 = r31.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v0,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// lvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fdivs f13,f9,f6
	ctx.f13.f64 = double(float(ctx.f9.f64 / ctx.f6.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx128 v61,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fmadds f4,f5,f13,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + f0.f64));
	// stfs f4,36(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lvx128 v12,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f3,f13,f12
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lvx128 v11,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v9,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f3,88(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx128 v60,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v60,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vspltw128 v10,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vmaddfp v13,v10,v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v12,v10,v12,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v11,v10,v11,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v10,v10,v9,v0
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// ble cr6,0x8240e604
	if (!cr6.gt) goto loc_8240E604;
	// addi r9,r8,-1
	ctx.r9.s64 = ctx.r8.s64 + -1;
	// li r6,16
	ctx.r6.s64 = 16;
	// rlwinm r9,r9,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFF;
	// li r7,32
	ctx.r7.s64 = 32;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// li r8,48
	ctx.r8.s64 = 48;
loc_8240E58C:
	// lvx128 v0,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// vsldoi128 v9,v62,v0,14
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), 2));
	// vor128 v62,v0,v0
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// vavgsh v9,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_avg_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)));
	// vmrghh v8,v9,v0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_load_si128((simde__m128i*)ctx.v9.u16)));
	// vmrglh v7,v9,v0
	simde_mm_store_si128((simde__m128i*)ctx.v7.u16, simde_mm_unpacklo_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_load_si128((simde__m128i*)ctx.v9.u16)));
	// vupkhsb128 v59,v8,v96
	simde_mm_store_si128((simde__m128i*)v59.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16))));
	// vupklsb128 v58,v8,v96
	simde_mm_store_si128((simde__m128i*)v58.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vupkhsb128 v57,v7,v96
	simde_mm_store_si128((simde__m128i*)v57.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16))));
	// vupklsb128 v56,v7,v96
	simde_mm_store_si128((simde__m128i*)v56.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vcsxwfp128 v55,v59,15
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v59.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vcsxwfp128 v54,v58,15
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v58.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vcsxwfp128 v53,v57,15
	simde_mm_store_ps(v53.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v57.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vcsxwfp128 v52,v56,15
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v56.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x38000000)))));
	// vmulfp128 v51,v55,v10
	simde_mm_store_ps(v51.f32, simde_mm_mul_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(ctx.v10.f32)));
	// vmulfp128 v50,v54,v11
	simde_mm_store_ps(v50.f32, simde_mm_mul_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(ctx.v11.f32)));
	// vmulfp128 v49,v53,v12
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v48,v52,v13
	simde_mm_store_ps(v48.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vaddfp128 v13,v13,v63
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v63.f32)));
	// vaddfp128 v12,v12,v63
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v63.f32)));
	// vaddfp128 v11,v11,v63
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(v63.f32)));
	// vaddfp128 v10,v10,v63
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v51,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// bne 0x8240e58c
	if (!cr0.eq) goto loc_8240E58C;
loc_8240E604:
	// lhz r9,-2(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + -2);
	// sth r9,52(r3)
	PPC_STORE_U16(ctx.r3.u32 + 52, ctx.r9.u16);
	// lbz r8,13(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// rotlwi r5,r8,1
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// divwu r9,r6,r5
	ctx.r9.u32 = ctx.r6.u32 / ctx.r5.u32;
	// twllei r5,0
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// blt cr6,0x8240e634
	if (cr6.lt) goto loc_8240E634;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_8240E634:
	// lwz r8,20(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// subf r7,r8,r11
	ctx.r7.s64 = r11.s64 - ctx.r8.s64;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// rlwinm r11,r7,30,2,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8240e654
	if (cr6.lt) goto loc_8240E654;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8240E654:
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8240E660"))) PPC_WEAK_FUNC(sub_8240E660);
PPC_FUNC_IMPL(__imp__sub_8240E660) {
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
	// bl 0x823d91f0
	ctx.lr = 0x8240E668;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r5,r11,r10
	ctx.r5.s64 = ctx.r10.s64 - r11.s64;
	// lbz r8,13(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// srawi r31,r5,1
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	r31.s64 = ctx.r5.s32 >> 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mullw r10,r8,r9
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r7,20(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// subf r9,r9,r4
	ctx.r9.s64 = ctx.r4.s64 - ctx.r9.s64;
	// addze r8,r31
	temp.s64 = r31.s64 + xer.ca;
	xer.ca = temp.u32 < r31.u32;
	ctx.r8.s64 = temp.s64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// add r11,r6,r7
	r11.u64 = ctx.r6.u64 + ctx.r7.u64;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// bge cr6,0x8240e6b4
	if (!cr6.lt) goto loc_8240E6B4;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
loc_8240E6B4:
	// or r9,r8,r11
	ctx.r9.u64 = ctx.r8.u64 | r11.u64;
	// or r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 | ctx.r10.u64;
	// clrlwi r6,r7,28
	ctx.r6.u64 = ctx.r7.u32 & 0xF;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x8240e6d4
	if (cr6.eq) goto loc_8240E6D4;
	// bl 0x8240ac88
	ctx.lr = 0x8240E6CC;
	sub_8240AC88(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8240E6D4:
	// addi r7,r8,127
	ctx.r7.s64 = ctx.r8.s64 + 127;
	// li r9,0
	ctx.r9.s64 = 0;
	// rlwinm r7,r7,25,7,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8240e6fc
	if (cr6.eq) goto loc_8240E6FC;
loc_8240E6E8:
	// rlwinm r6,r9,7,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 7) & 0xFFFFFF80;
	// dcbt r6,r10
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r9,r7
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, xer);
	// blt cr6,0x8240e6e8
	if (cr6.lt) goto loc_8240E6E8;
loc_8240E6FC:
	// extsw r9,r5
	ctx.r9.s64 = ctx.r5.s32;
	// lfs f0,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	f0.f64 = double(temp.f32);
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f13,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lbz r4,52(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 52);
	// addi r28,r1,96
	r28.s64 = ctx.r1.s64 + 96;
	// std r6,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r6.u64);
	// lfd f9,88(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// vspltisb v0,7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0x7)));
	// lis r29,-32250
	r29.s64 = -2113536000;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r7,-32250
	ctx.r7.s64 = -2113536000;
	// stb r4,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, ctx.r4.u8);
	// lvx128 v13,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// vslb v3,v0,v0
	ctx.v3.u8[0] = ctx.v0.u8[0] << (ctx.v0.u8[0] & 0x7);
	ctx.v3.u8[1] = ctx.v0.u8[1] << (ctx.v0.u8[1] & 0x7);
	ctx.v3.u8[2] = ctx.v0.u8[2] << (ctx.v0.u8[2] & 0x7);
	ctx.v3.u8[3] = ctx.v0.u8[3] << (ctx.v0.u8[3] & 0x7);
	ctx.v3.u8[4] = ctx.v0.u8[4] << (ctx.v0.u8[4] & 0x7);
	ctx.v3.u8[5] = ctx.v0.u8[5] << (ctx.v0.u8[5] & 0x7);
	ctx.v3.u8[6] = ctx.v0.u8[6] << (ctx.v0.u8[6] & 0x7);
	ctx.v3.u8[7] = ctx.v0.u8[7] << (ctx.v0.u8[7] & 0x7);
	ctx.v3.u8[8] = ctx.v0.u8[8] << (ctx.v0.u8[8] & 0x7);
	ctx.v3.u8[9] = ctx.v0.u8[9] << (ctx.v0.u8[9] & 0x7);
	ctx.v3.u8[10] = ctx.v0.u8[10] << (ctx.v0.u8[10] & 0x7);
	ctx.v3.u8[11] = ctx.v0.u8[11] << (ctx.v0.u8[11] & 0x7);
	ctx.v3.u8[12] = ctx.v0.u8[12] << (ctx.v0.u8[12] & 0x7);
	ctx.v3.u8[13] = ctx.v0.u8[13] << (ctx.v0.u8[13] & 0x7);
	ctx.v3.u8[14] = ctx.v0.u8[14] << (ctx.v0.u8[14] & 0x7);
	ctx.v3.u8[15] = ctx.v0.u8[15] << (ctx.v0.u8[15] & 0x7);
	// lfs f12,-10992(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -10992);
	ctx.f12.f64 = double(temp.f32);
	// lis r31,-32250
	r31.s64 = -2113536000;
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// lis r30,-32250
	r30.s64 = -2113536000;
	// lis r28,-32250
	r28.s64 = -2113536000;
	// addi r27,r1,88
	r27.s64 = ctx.r1.s64 + 88;
	// addi r4,r29,-3840
	ctx.r4.s64 = r29.s64 + -3840;
	// addi r7,r7,6688
	ctx.r7.s64 = ctx.r7.s64 + 6688;
	// addi r6,r6,6672
	ctx.r6.s64 = ctx.r6.s64 + 6672;
	// addi r31,r31,6608
	r31.s64 = r31.s64 + 6608;
	// addi r5,r5,6592
	ctx.r5.s64 = ctx.r5.s64 + 6592;
	// addi r30,r30,6560
	r30.s64 = r30.s64 + 6560;
	// addi r28,r28,6656
	r28.s64 = r28.s64 + 6656;
	// addi r29,r1,88
	r29.s64 = ctx.r1.s64 + 88;
	// addi r26,r1,80
	r26.s64 = ctx.r1.s64 + 80;
	// lis r9,-32250
	ctx.r9.s64 = -2113536000;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r9,r9,6640
	ctx.r9.s64 = ctx.r9.s64 + 6640;
	// lvlx128 v63,r0,r26
	temp.u32 = r26.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v0,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// vaddubm v4,v13,v3
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)));
	// fcfid f7,f9
	ctx.f7.f64 = double(ctx.f9.s64);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fdivs f13,f10,f6
	ctx.f13.f64 = double(float(ctx.f10.f64 / ctx.f6.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx128 v62,r0,r27
	temp.u32 = r27.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// fmadds f4,f5,f13,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + f0.f64));
	// stfs f4,36(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// fmuls f3,f13,f12
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lvx128 v10,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v9,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v8,r0,r31
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v7,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v6,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f3,88(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v5,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v61,r0,r29
	temp.u32 = r29.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvx128 v11,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v13,v11,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v12,v13,v12,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vspltw128 v63,v61,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vmaddfp v10,v13,v10,v0
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v9,v13,v9,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v8,v13,v8,v0
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v7,v13,v7,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v6,v13,v6,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v13,v13,v5,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// ble cr6,0x8240e924
	if (!cr6.gt) goto loc_8240E924;
	// addi r9,r8,-1
	ctx.r9.s64 = ctx.r8.s64 + -1;
	// li r30,16
	r30.s64 = 16;
	// rlwinm r9,r9,28,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0xFFFFFFF;
	// li r31,32
	r31.s64 = 32;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// li r4,48
	ctx.r4.s64 = 48;
	// li r5,64
	ctx.r5.s64 = 64;
	// li r6,80
	ctx.r6.s64 = 80;
	// li r7,96
	ctx.r7.s64 = 96;
	// li r8,112
	ctx.r8.s64 = 112;
loc_8240E848:
	// lvx128 v0,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// vaddubm v0,v0,v3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_add_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// vsldoi v5,v4,v0,15
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), 1));
	// vor v4,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vavgsb v5,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_avg_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vmrghb v2,v5,v0
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vmrglb v1,v5,v0
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_unpacklo_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vupkhsb128 v60,v2,v0
	simde_mm_store_si128((simde__m128i*)v60.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v2.s8), simde_mm_load_si128((simde__m128i*)ctx.v2.s8))));
	// vupklsb128 v59,v2,v0
	simde_mm_store_si128((simde__m128i*)v59.s32, simde_mm_cvtepi8_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vupkhsb128 v58,v1,v0
	simde_mm_store_si128((simde__m128i*)v58.s16, simde_mm_cvtepi8_epi16(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)ctx.v1.s8), simde_mm_load_si128((simde__m128i*)ctx.v1.s8))));
	// vupklsb128 v57,v1,v0
	simde_mm_store_si128((simde__m128i*)v57.s32, simde_mm_cvtepi8_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16)));
	// vupkhsb128 v56,v60,v96
	simde_mm_store_si128((simde__m128i*)v56.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v60.s16), simde_mm_load_si128((simde__m128i*)v60.s16))));
	// vupklsb128 v55,v60,v96
	simde_mm_store_si128((simde__m128i*)v55.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)v60.s16)));
	// vupkhsb128 v54,v59,v96
	simde_mm_store_si128((simde__m128i*)v54.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v59.s16), simde_mm_load_si128((simde__m128i*)v59.s16))));
	// vupklsb128 v53,v59,v96
	simde_mm_store_si128((simde__m128i*)v53.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)v59.s16)));
	// vupkhsb128 v52,v58,v96
	simde_mm_store_si128((simde__m128i*)v52.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v58.s16), simde_mm_load_si128((simde__m128i*)v58.s16))));
	// vcsxwfp128 v51,v56,7
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v51.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v56.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vupklsb128 v50,v58,v96
	simde_mm_store_si128((simde__m128i*)v50.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)v58.s16)));
	// vcsxwfp128 v49,v55,7
	simde_mm_store_ps(v49.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v55.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vupkhsb128 v48,v57,v96
	simde_mm_store_si128((simde__m128i*)v48.s32, simde_mm_cvtepi16_epi32(simde_mm_unpackhi_epi64(simde_mm_load_si128((simde__m128i*)v57.s16), simde_mm_load_si128((simde__m128i*)v57.s16))));
	// vcsxwfp128 v47,v54,7
	simde_mm_store_ps(v47.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v54.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vupklsb128 v46,v57,v96
	simde_mm_store_si128((simde__m128i*)v46.s32, simde_mm_cvtepi16_epi32(simde_mm_load_si128((simde__m128i*)v57.s16)));
	// vcsxwfp128 v45,v53,7
	simde_mm_store_ps(v45.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v53.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vcsxwfp128 v44,v52,7
	simde_mm_store_ps(v44.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v52.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vcsxwfp128 v43,v50,7
	simde_mm_store_ps(v43.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v50.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vcsxwfp128 v42,v48,7
	simde_mm_store_ps(v42.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v48.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vcsxwfp128 v41,v46,7
	simde_mm_store_ps(v41.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)v46.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vmulfp128 v40,v51,v13
	simde_mm_store_ps(v40.f32, simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v39,v49,v6
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vmulfp128 v38,v47,v7
	simde_mm_store_ps(v38.f32, simde_mm_mul_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(ctx.v7.f32)));
	// vmulfp128 v37,v45,v8
	simde_mm_store_ps(v37.f32, simde_mm_mul_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(ctx.v8.f32)));
	// vmulfp128 v36,v44,v9
	simde_mm_store_ps(v36.f32, simde_mm_mul_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(ctx.v9.f32)));
	// vmulfp128 v35,v43,v10
	simde_mm_store_ps(v35.f32, simde_mm_mul_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(ctx.v10.f32)));
	// vmulfp128 v34,v42,v11
	simde_mm_store_ps(v34.f32, simde_mm_mul_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(ctx.v11.f32)));
	// vmulfp128 v33,v41,v12
	simde_mm_store_ps(v33.f32, simde_mm_mul_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vaddfp128 v12,v12,v63
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(v63.f32)));
	// vaddfp128 v11,v11,v63
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(v63.f32)));
	// vaddfp128 v10,v10,v63
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(v63.f32)));
	// vaddfp128 v9,v9,v63
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v40,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v8,v8,v63
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v39,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v7,v7,v63
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v38,r11,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v6,v6,v63
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v37,r11,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v13,v13,v63
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v36,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v33,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,128
	r11.s64 = r11.s64 + 128;
	// bne 0x8240e848
	if (!cr0.eq) goto loc_8240E848;
loc_8240E924:
	// lbz r9,-1(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + -1);
	// stb r9,52(r3)
	PPC_STORE_U8(ctx.r3.u32 + 52, ctx.r9.u8);
	// lbz r8,13(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// divwu r9,r6,r8
	ctx.r9.u32 = ctx.r6.u32 / ctx.r8.u32;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// twllei r8,0
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// blt cr6,0x8240e950
	if (cr6.lt) goto loc_8240E950;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_8240E950:
	// lwz r8,20(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// subf r7,r8,r11
	ctx.r7.s64 = r11.s64 - ctx.r8.s64;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// rlwinm r11,r7,30,2,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8240e970
	if (cr6.lt) goto loc_8240E970;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8240E970:
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8240E97C"))) PPC_WEAK_FUNC(sub_8240E97C);
PPC_FUNC_IMPL(__imp__sub_8240E97C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8240E980"))) PPC_WEAK_FUNC(sub_8240E980);
PPC_FUNC_IMPL(__imp__sub_8240E980) {
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
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,116
	ctx.r6.s64 = ctx.r1.s64 + 116;
	// li r3,250
	ctx.r3.s64 = 250;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x827bd0b4
	ctx.lr = 0x8240E9A8;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8240e9d0
	if (cr0.lt) goto loc_8240E9D0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8240e9c0
	if (!cr6.eq) goto loc_8240E9C0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82450030
	ctx.lr = 0x8240E9C0;
	sub_82450030(ctx, base);
loc_8240E9C0:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8240e9d0
	if (cr6.lt) goto loc_8240E9D0;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8240e9e8
	goto loc_8240E9E8;
loc_8240E9D0:
	// rlwinm r11,r3,0,3,15
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1FFF0000;
	// lis r10,7
	ctx.r10.s64 = 458752;
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x8240e9e8
	if (cr6.eq) goto loc_8240E9E8;
	// li r3,1627
	ctx.r3.s64 = 1627;
loc_8240E9E8:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8240E9FC"))) PPC_WEAK_FUNC(sub_8240E9FC);
PPC_FUNC_IMPL(__imp__sub_8240E9FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8240EA00"))) PPC_WEAK_FUNC(sub_8240EA00);
PPC_FUNC_IMPL(__imp__sub_8240EA00) {
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
	// stwu r1,-928(r1)
	ea = -928 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r5,824
	ctx.r5.s64 = 824;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823d9890
	ctx.lr = 0x8240EA2C;
	sub_823D9890(ctx, base);
	// li r11,2
	r11.s64 = 2;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// li r5,820
	ctx.r5.s64 = 820;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x8240EA44;
	sub_823DA950(ctx, base);
	// lis r4,7
	ctx.r4.s64 = 458752;
	// li r7,824
	ctx.r7.s64 = 824;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// ori r4,r4,59
	ctx.r4.u64 = ctx.r4.u64 | 59;
	// li r3,250
	ctx.r3.s64 = 250;
	// bl 0x827bd0b4
	ctx.lr = 0x8240EA60;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8240ea88
	if (cr0.lt) goto loc_8240EA88;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8240ea78
	if (!cr6.eq) goto loc_8240EA78;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82450030
	ctx.lr = 0x8240EA78;
	sub_82450030(ctx, base);
loc_8240EA78:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8240ea88
	if (cr6.lt) goto loc_8240EA88;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8240eaa0
	goto loc_8240EAA0;
loc_8240EA88:
	// rlwinm r11,r3,0,3,15
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1FFF0000;
	// lis r10,7
	ctx.r10.s64 = 458752;
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x8240eaa0
	if (cr6.eq) goto loc_8240EAA0;
	// li r3,1627
	ctx.r3.s64 = 1627;
loc_8240EAA0:
	// addi r1,r1,928
	ctx.r1.s64 = ctx.r1.s64 + 928;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8240EAB8"))) PPC_WEAK_FUNC(sub_8240EAB8);
PPC_FUNC_IMPL(__imp__sub_8240EAB8) {
	PPC_FUNC_PROLOGUE();
	// lis r4,7
	ctx.r4.s64 = 458752;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// ori r4,r4,3
	ctx.r4.u64 = ctx.r4.u64 | 3;
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x8240e980
	sub_8240E980(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8240EACC"))) PPC_WEAK_FUNC(sub_8240EACC);
PPC_FUNC_IMPL(__imp__sub_8240EACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8240EAD0"))) PPC_WEAK_FUNC(sub_8240EAD0);
PPC_FUNC_IMPL(__imp__sub_8240EAD0) {
	PPC_FUNC_PROLOGUE();
	// lis r4,7
	ctx.r4.s64 = 458752;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// ori r4,r4,5
	ctx.r4.u64 = ctx.r4.u64 | 5;
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x8240e980
	sub_8240E980(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8240EAE4"))) PPC_WEAK_FUNC(sub_8240EAE4);
PPC_FUNC_IMPL(__imp__sub_8240EAE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8240EAE8"))) PPC_WEAK_FUNC(sub_8240EAE8);
PPC_FUNC_IMPL(__imp__sub_8240EAE8) {
	PPC_FUNC_PROLOGUE();
	// lis r4,7
	ctx.r4.s64 = 458752;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// ori r4,r4,6
	ctx.r4.u64 = ctx.r4.u64 | 6;
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x8240e980
	sub_8240E980(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8240EAFC"))) PPC_WEAK_FUNC(sub_8240EAFC);
PPC_FUNC_IMPL(__imp__sub_8240EAFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8240EB00"))) PPC_WEAK_FUNC(sub_8240EB00);
PPC_FUNC_IMPL(__imp__sub_8240EB00) {
	PPC_FUNC_PROLOGUE();
	// lis r4,7
	ctx.r4.s64 = 458752;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// ori r4,r4,7
	ctx.r4.u64 = ctx.r4.u64 | 7;
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x8240e980
	sub_8240E980(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8240EB14"))) PPC_WEAK_FUNC(sub_8240EB14);
PPC_FUNC_IMPL(__imp__sub_8240EB14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8240EB18"))) PPC_WEAK_FUNC(sub_8240EB18);
PPC_FUNC_IMPL(__imp__sub_8240EB18) {
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
	ctx.lr = 0x8240EB20;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// clrlwi. r11,r28,31
	r11.u64 = r28.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8240eb48
	if (cr0.eq) goto loc_8240EB48;
	// lis r9,8192
	ctx.r9.s64 = 536870912;
	// ori r9,r9,1
	ctx.r9.u64 = ctx.r9.u64 | 1;
	// b 0x8240eb4c
	goto loc_8240EB4C;
loc_8240EB48:
	// li r9,0
	ctx.r9.s64 = 0;
loc_8240EB4C:
	// lis r6,7
	ctx.r6.s64 = 458752;
	// lis r5,7
	ctx.r5.s64 = 458752;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// li r7,5544
	ctx.r7.s64 = 5544;
	// ori r6,r6,39
	ctx.r6.u64 = ctx.r6.u64 | 39;
	// ori r5,r5,38
	ctx.r5.u64 = ctx.r5.u64 | 38;
	// li r4,250
	ctx.r4.s64 = 250;
	// li r3,-1
	ctx.r3.s64 = -1;
	// bl 0x827bd094
	ctx.lr = 0x8240EB74;
	__imp__XamCreateEnumeratorHandle(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt 0x8240eb84
	if (cr0.gt) goto loc_8240EB84;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8240eb8c
	goto loc_8240EB8C;
loc_8240EB84:
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r31,r11,32775
	r31.u64 = r11.u64 | 2147942400;
loc_8240EB8C:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8240ec04
	if (cr6.lt) goto loc_8240EC04;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x827bd0e4
	ctx.lr = 0x8240EBA0;
	__imp__XamGetPrivateEnumStructureFromHandle(ctx, base);
	// li r11,2
	r11.s64 = 2;
	// li r5,5544
	ctx.r5.s64 = 5544;
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r3,r11,24
	ctx.r3.s64 = r11.s64 + 24;
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// bl 0x823d9890
	ctx.lr = 0x8240EBC4;
	sub_823D9890(ctx, base);
	// mulli r11,r29,820
	r11.s64 = r29.s64 * 820;
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// lis r4,7
	ctx.r4.s64 = 458752;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// ori r4,r4,37
	ctx.r4.u64 = ctx.r4.u64 | 37;
	// li r3,250
	ctx.r3.s64 = 250;
	// bl 0x827bd0d4
	ctx.lr = 0x8240EBE4;
	__imp__XMsgInProcessCall(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x8240ebf4
	if (!cr0.lt) goto loc_8240EBF4;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8244eee0
	ctx.lr = 0x8240EBF4;
	sub_8244EEE0(ctx, base);
loc_8240EBF4:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x827bce64
	ctx.lr = 0x8240EBFC;
	__imp__ObDereferenceObject(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bge cr6,0x8240ec14
	if (!cr6.lt) goto loc_8240EC14;
loc_8240EC04:
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// blt cr6,0x8240ec1c
	if (cr6.lt) goto loc_8240EC1C;
loc_8240EC14:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8240ec34
	goto loc_8240EC34;
loc_8240EC1C:
	// rlwinm r11,r31,0,3,15
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 0) & 0x1FFF0000;
	// lis r10,7
	ctx.r10.s64 = 458752;
	// clrlwi r3,r31,16
	ctx.r3.u64 = r31.u32 & 0xFFFF;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x8240ec34
	if (cr6.eq) goto loc_8240EC34;
	// li r3,1627
	ctx.r3.s64 = 1627;
loc_8240EC34:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8240EC3C"))) PPC_WEAK_FUNC(sub_8240EC3C);
PPC_FUNC_IMPL(__imp__sub_8240EC3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8240EC40"))) PPC_WEAK_FUNC(sub_8240EC40);
PPC_FUNC_IMPL(__imp__sub_8240EC40) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r4,7
	ctx.r4.s64 = 458752;
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// li r7,12
	ctx.r7.s64 = 12;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// ori r4,r4,14
	ctx.r4.u64 = ctx.r4.u64 | 14;
	// li r3,250
	ctx.r3.s64 = 250;
	// bl 0x827bd0b4
	ctx.lr = 0x8240EC7C;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8240eca4
	if (cr0.lt) goto loc_8240ECA4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8240ec94
	if (!cr6.eq) goto loc_8240EC94;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82450030
	ctx.lr = 0x8240EC94;
	sub_82450030(ctx, base);
loc_8240EC94:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8240eca4
	if (cr6.lt) goto loc_8240ECA4;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8240ecbc
	goto loc_8240ECBC;
loc_8240ECA4:
	// rlwinm r11,r3,0,3,15
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1FFF0000;
	// lis r10,7
	ctx.r10.s64 = 458752;
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x8240ecbc
	if (cr6.eq) goto loc_8240ECBC;
	// li r3,1627
	ctx.r3.s64 = 1627;
loc_8240ECBC:
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

__attribute__((alias("__imp__sub_8240ECD0"))) PPC_WEAK_FUNC(sub_8240ECD0);
PPC_FUNC_IMPL(__imp__sub_8240ECD0) {
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
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r4,7
	ctx.r4.s64 = 458752;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// li r3,250
	ctx.r3.s64 = 250;
	// bl 0x827bd0d4
	ctx.lr = 0x8240ECFC;
	__imp__XMsgInProcessCall(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8240ed0c
	if (cr0.lt) goto loc_8240ED0C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8240ed24
	goto loc_8240ED24;
loc_8240ED0C:
	// rlwinm r11,r3,0,3,15
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1FFF0000;
	// lis r10,7
	ctx.r10.s64 = 458752;
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x8240ed24
	if (cr6.eq) goto loc_8240ED24;
	// li r3,1627
	ctx.r3.s64 = 1627;
loc_8240ED24:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8240ED34"))) PPC_WEAK_FUNC(sub_8240ED34);
PPC_FUNC_IMPL(__imp__sub_8240ED34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8240ED38"))) PPC_WEAK_FUNC(sub_8240ED38);
PPC_FUNC_IMPL(__imp__sub_8240ED38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// stfs f1,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r4,7
	ctx.r4.s64 = 458752;
	// li r7,8
	ctx.r7.s64 = 8;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// ori r4,r4,12
	ctx.r4.u64 = ctx.r4.u64 | 12;
	// li r3,250
	ctx.r3.s64 = 250;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x827bd0b4
	ctx.lr = 0x8240ED6C;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8240ed94
	if (cr0.lt) goto loc_8240ED94;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8240ed84
	if (!cr6.eq) goto loc_8240ED84;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82450030
	ctx.lr = 0x8240ED84;
	sub_82450030(ctx, base);
loc_8240ED84:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8240ed94
	if (cr6.lt) goto loc_8240ED94;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8240edac
	goto loc_8240EDAC;
loc_8240ED94:
	// rlwinm r11,r3,0,3,15
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1FFF0000;
	// lis r10,7
	ctx.r10.s64 = 458752;
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x8240edac
	if (cr6.eq) goto loc_8240EDAC;
	// li r3,1627
	ctx.r3.s64 = 1627;
loc_8240EDAC:
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

__attribute__((alias("__imp__sub_8240EDC0"))) PPC_WEAK_FUNC(sub_8240EDC0);
PPC_FUNC_IMPL(__imp__sub_8240EDC0) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stw r4,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r4.u32);
	// stw r5,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// bne cr6,0x8240ee00
	if (!cr6.eq) goto loc_8240EE00;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lis r10,8
	ctx.r10.s64 = 524288;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// std r9,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r9.u64);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// b 0x8240ee04
	goto loc_8240EE04;
loc_8240EE00:
	// li r8,0
	ctx.r8.s64 = 0;
loc_8240EE04:
	// lis r4,7
	ctx.r4.s64 = 458752;
	// li r7,12
	ctx.r7.s64 = 12;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,26
	ctx.r4.u64 = ctx.r4.u64 | 26;
	// li r3,250
	ctx.r3.s64 = 250;
	// bl 0x827bd0a4
	ctx.lr = 0x8240EE20;
	__imp__XMsgStartIORequestEx(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8240ee40
	if (cr0.lt) goto loc_8240EE40;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82450030
	ctx.lr = 0x8240EE30;
	sub_82450030(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8240ee40
	if (cr0.lt) goto loc_8240EE40;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8240ee58
	goto loc_8240EE58;
loc_8240EE40:
	// rlwinm r11,r3,0,3,15
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1FFF0000;
	// lis r10,7
	ctx.r10.s64 = 458752;
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x8240ee58
	if (cr6.eq) goto loc_8240EE58;
	// li r3,1627
	ctx.r3.s64 = 1627;
loc_8240EE58:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8240EE68"))) PPC_WEAK_FUNC(sub_8240EE68);
PPC_FUNC_IMPL(__imp__sub_8240EE68) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r4,7
	ctx.r4.s64 = 458752;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// ori r4,r4,27
	ctx.r4.u64 = ctx.r4.u64 | 27;
	// li r3,250
	ctx.r3.s64 = 250;
	// bl 0x827bd0d4
	ctx.lr = 0x8240EE98;
	__imp__XMsgInProcessCall(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8240eea8
	if (cr0.lt) goto loc_8240EEA8;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8240eec0
	goto loc_8240EEC0;
loc_8240EEA8:
	// rlwinm r11,r3,0,3,15
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1FFF0000;
	// lis r10,7
	ctx.r10.s64 = 458752;
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x8240eec0
	if (cr6.eq) goto loc_8240EEC0;
	// li r3,1627
	ctx.r3.s64 = 1627;
loc_8240EEC0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8240EED0"))) PPC_WEAK_FUNC(sub_8240EED0);
PPC_FUNC_IMPL(__imp__sub_8240EED0) {
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
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r30,0
	r30.s64 = 0;
	// lis r4,7
	ctx.r4.s64 = 458752;
	// li r7,8
	ctx.r7.s64 = 8;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// std r30,0(r11)
	PPC_STORE_U64(r11.u32 + 0, r30.u64);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// ori r4,r4,4
	ctx.r4.u64 = ctx.r4.u64 | 4;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// li r3,250
	ctx.r3.s64 = 250;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x827bd0b4
	ctx.lr = 0x8240EF14;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt 0x8240ef3c
	if (cr0.lt) goto loc_8240EF3C;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8240ef2c
	if (!cr6.eq) goto loc_8240EF2C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82450030
	ctx.lr = 0x8240EF2C;
	sub_82450030(ctx, base);
loc_8240EF2C:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8240ef3c
	if (cr6.lt) goto loc_8240EF3C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// b 0x8240ef54
	goto loc_8240EF54;
loc_8240EF3C:
	// rlwinm r11,r3,0,3,15
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1FFF0000;
	// lis r10,7
	ctx.r10.s64 = 458752;
	// clrlwi r3,r3,16
	ctx.r3.u64 = ctx.r3.u32 & 0xFFFF;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// beq cr6,0x8240ef54
	if (cr6.eq) goto loc_8240EF54;
	// li r3,1627
	ctx.r3.s64 = 1627;
loc_8240EF54:
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

__attribute__((alias("__imp__sub_8240EF6C"))) PPC_WEAK_FUNC(sub_8240EF6C);
PPC_FUNC_IMPL(__imp__sub_8240EF6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8240EF70"))) PPC_WEAK_FUNC(sub_8240EF70);
PPC_FUNC_IMPL(__imp__sub_8240EF70) {
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
	// lis r11,-32250
	r11.s64 = -2113536000;
	// clrlwi. r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,6704
	r11.s64 = r11.s64 + 6704;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// beq 0x8240ef9c
	if (cr0.eq) goto loc_8240EF9C;
	// bl 0x82130588
	ctx.lr = 0x8240EF9C;
	sub_82130588(ctx, base);
loc_8240EF9C:
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

__attribute__((alias("__imp__sub_8240EFB4"))) PPC_WEAK_FUNC(sub_8240EFB4);
PPC_FUNC_IMPL(__imp__sub_8240EFB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8240EFB8"))) PPC_WEAK_FUNC(sub_8240EFB8);
PPC_FUNC_IMPL(__imp__sub_8240EFB8) {
	PPC_FUNC_PROLOGUE();
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x8240ec40
	sub_8240EC40(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8240EFCC"))) PPC_WEAK_FUNC(sub_8240EFCC);
PPC_FUNC_IMPL(__imp__sub_8240EFCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8240EFD0"))) PPC_WEAK_FUNC(sub_8240EFD0);
PPC_FUNC_IMPL(__imp__sub_8240EFD0) {
	PPC_FUNC_PROLOGUE();
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x8240eed0
	sub_8240EED0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8240EFE0"))) PPC_WEAK_FUNC(sub_8240EFE0);
PPC_FUNC_IMPL(__imp__sub_8240EFE0) {
	PPC_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x8240ecd0
	sub_8240ECD0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8240EFEC"))) PPC_WEAK_FUNC(sub_8240EFEC);
PPC_FUNC_IMPL(__imp__sub_8240EFEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8240EFF0"))) PPC_WEAK_FUNC(sub_8240EFF0);
PPC_FUNC_IMPL(__imp__sub_8240EFF0) {
	PPC_FUNC_PROLOGUE();
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// b 0x8240ed38
	sub_8240ED38(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8240EFFC"))) PPC_WEAK_FUNC(sub_8240EFFC);
PPC_FUNC_IMPL(__imp__sub_8240EFFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8240F000"))) PPC_WEAK_FUNC(sub_8240F000);
PPC_FUNC_IMPL(__imp__sub_8240F000) {
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
	ctx.lr = 0x8240F008;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x827bd0c4
	ctx.lr = 0x8240F010;
	__imp__XamGetSystemVersion(ctx, base);
	// lis r11,8
	r11.s64 = 524288;
	// rlwinm r10,r3,0,8,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFF00;
	// ori r11,r11,41216
	r11.u64 = r11.u64 | 41216;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x8240f0b8
	if (!cr6.lt) goto loc_8240F0B8;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r28,r11,-15548
	r28.s64 = r11.s64 + -15548;
	// addi r3,r28,4
	ctx.r3.s64 = r28.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x8240F034;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r29,-32115
	r29.s64 = -2104688640;
	// lwz r11,-9728(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -9728);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8240f04c
	if (!cr6.eq) goto loc_8240F04C;
	// li r30,1627
	r30.s64 = 1627;
	// b 0x8240f0ac
	goto loc_8240F0AC;
loc_8240F04C:
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8240ee68
	ctx.lr = 0x8240F05C;
	sub_8240EE68(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// lis r31,-32115
	r31.s64 = -2104688640;
	// bne 0x8240f09c
	if (!cr0.eq) goto loc_8240F09C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r11,r11,0
	r11.s64 = r11.s64 + 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// stw r11,-9724(r31)
	PPC_STORE_U32(r31.u32 + -9724, r11.u32);
	// bl 0x8240edc0
	ctx.lr = 0x8240F08C;
	sub_8240EDC0(ctx, base);
	// mr. r30,r3
	r30.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x8240f09c
	if (!cr0.eq) goto loc_8240F09C;
	// li r11,1
	r11.s64 = 1;
	// b 0x8240f0a8
	goto loc_8240F0A8;
loc_8240F09C:
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,0
	r11.s64 = 0;
	// stw r10,-9724(r31)
	PPC_STORE_U32(r31.u32 + -9724, ctx.r10.u32);
loc_8240F0A8:
	// stw r11,-9728(r29)
	PPC_STORE_U32(r29.u32 + -9728, r11.u32);
loc_8240F0AC:
	// addi r3,r28,4
	ctx.r3.s64 = r28.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x8240F0B4;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// b 0x8240f0cc
	goto loc_8240F0CC;
loc_8240F0B8:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8240edc0
	ctx.lr = 0x8240F0C8;
	sub_8240EDC0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8240F0CC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8240F0D8"))) PPC_WEAK_FUNC(sub_8240F0D8);
PPC_FUNC_IMPL(__imp__sub_8240F0D8) {
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
	ctx.lr = 0x8240F0E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x827bd0c4
	ctx.lr = 0x8240F0E8;
	__imp__XamGetSystemVersion(ctx, base);
	// lis r11,8
	r11.s64 = 524288;
	// rlwinm r10,r3,0,8,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFF00;
	// ori r11,r11,41216
	r11.u64 = r11.u64 | 41216;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bge cr6,0x8240f168
	if (!cr6.lt) goto loc_8240F168;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r28,r11,-15548
	r28.s64 = r11.s64 + -15548;
	// addi r3,r28,4
	ctx.r3.s64 = r28.s64 + 4;
	// bl 0x827bcf64
	ctx.lr = 0x8240F10C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r31,-32115
	r31.s64 = -2104688640;
	// lwz r11,-9728(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -9728);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8240f124
	if (!cr6.eq) goto loc_8240F124;
	// li r29,1627
	r29.s64 = 1627;
	// b 0x8240f15c
	goto loc_8240F15C;
loc_8240F124:
	// lis r30,-32115
	r30.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-9724(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -9724);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8240f144
	if (cr6.eq) goto loc_8240F144;
	// li r4,4
	ctx.r4.s64 = 4;
loc_8240F144:
	// bl 0x8240edc0
	ctx.lr = 0x8240F148;
	sub_8240EDC0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stw r11,-9724(r30)
	PPC_STORE_U32(r30.u32 + -9724, r11.u32);
	// stw r10,-9728(r31)
	PPC_STORE_U32(r31.u32 + -9728, ctx.r10.u32);
loc_8240F15C:
	// addi r3,r28,4
	ctx.r3.s64 = r28.s64 + 4;
	// bl 0x827bcf54
	ctx.lr = 0x8240F164;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// b 0x8240f17c
	goto loc_8240F17C;
loc_8240F168:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8240edc0
	ctx.lr = 0x8240F178;
	sub_8240EDC0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_8240F17C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8240F188"))) PPC_WEAK_FUNC(sub_8240F188);
PPC_FUNC_IMPL(__imp__sub_8240F188) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,40(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// rlwinm r11,r11,2,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x2;
	// rlwinm. r10,r10,23,30,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0x3;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne 0x8240f1bc
	if (!cr0.eq) goto loc_8240F1BC;
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r9,1
	ctx.r9.s64 = 1;
	// clrlwi r10,r10,8
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFFFF;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// stw r9,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// b 0x8240f218
	goto loc_8240F218;
loc_8240F1BC:
	// cmplwi cr6,r10,2
	cr6.compare<uint32_t>(ctx.r10.u32, 2, xer);
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// bne cr6,0x8240f1f8
	if (!cr6.eq) goto loc_8240F1F8;
	// clrlwi r10,r10,21
	ctx.r10.u64 = ctx.r10.u32 & 0x7FF;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r10,r10,21,21,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 21) & 0x7FF;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r10,r10,10,22,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 10) & 0x3FF;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r11.u32);
	// blr 
	return;
loc_8240F1F8:
	// clrlwi r10,r10,19
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFF;
	// li r9,1
	ctx.r9.s64 = 1;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r10,r10,19,19,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 19) & 0x1FFF;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
loc_8240F218:
	// stw r9,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8240F220"))) PPC_WEAK_FUNC(sub_8240F220);
PPC_FUNC_IMPL(__imp__sub_8240F220) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// rlwinm r5,r11,0,0,19
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	// rlwinm r4,r10,0,0,19
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFF000;
	// b 0x82421f38
	sub_82421F38(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8240F234"))) PPC_WEAK_FUNC(sub_8240F234);
PPC_FUNC_IMPL(__imp__sub_8240F234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8240F238"))) PPC_WEAK_FUNC(sub_8240F238);
PPC_FUNC_IMPL(__imp__sub_8240F238) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r9,r5,26
	ctx.r9.u64 = ctx.r5.u32 & 0x3F;
	// li r8,4
	ctx.r8.s64 = 4;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// cmpwi cr6,r6,1
	cr6.compare<int32_t>(ctx.r6.s32, 1, xer);
	// blt cr6,0x8240f254
	if (cr6.lt) goto loc_8240F254;
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
loc_8240F254:
	// cmpwi cr6,r6,2
	cr6.compare<int32_t>(ctx.r6.s32, 2, xer);
	// bne cr6,0x8240f260
	if (!cr6.eq) goto loc_8240F260;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
loc_8240F260:
	// addi r11,r11,79
	r11.s64 = r11.s64 + 79;
	// li r7,80
	ctx.r7.s64 = 80;
	// addi r10,r10,15
	ctx.r10.s64 = ctx.r10.s64 + 15;
	// divwu r7,r11,r7
	ctx.r7.u32 = r11.u32 / ctx.r7.u32;
	// rlwinm r11,r10,0,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// mulli r10,r7,80
	ctx.r10.s64 = ctx.r7.s64 * 80;
	// cmpwi cr6,r9,21
	cr6.compare<int32_t>(ctx.r9.s32, 21, xer);
	// beq cr6,0x8240f290
	if (cr6.eq) goto loc_8240F290;
	// cmpwi cr6,r9,32
	cr6.compare<int32_t>(ctx.r9.s32, 32, xer);
	// beq cr6,0x8240f290
	if (cr6.eq) goto loc_8240F290;
	// cmpwi cr6,r9,37
	cr6.compare<int32_t>(ctx.r9.s32, 37, xer);
	// bne cr6,0x8240f294
	if (!cr6.eq) goto loc_8240F294;
loc_8240F290:
	// li r8,8
	ctx.r8.s64 = 8;
loc_8240F294:
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// li r10,5120
	ctx.r10.s64 = 5120;
	// divwu r3,r11,r10
	ctx.r3.u32 = r11.u32 / ctx.r10.u32;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8240F2A8"))) PPC_WEAK_FUNC(sub_8240F2A8);
PPC_FUNC_IMPL(__imp__sub_8240F2A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,44
	cr6.compare<uint32_t>(ctx.r3.u32, 44, xer);
	// bgt cr6,0x8240f300
	if (cr6.gt) goto loc_8240F300;
	// beq cr6,0x8240f2f8
	if (cr6.eq) goto loc_8240F2F8;
	// cmplwi cr6,r3,11
	cr6.compare<uint32_t>(ctx.r3.u32, 11, xer);
	// blt cr6,0x8240f328
	if (cr6.lt) goto loc_8240F328;
	// cmplwi cr6,r3,12
	cr6.compare<uint32_t>(ctx.r3.u32, 12, xer);
	// ble cr6,0x8240f2e4
	if (!cr6.gt) goto loc_8240F2E4;
	// cmplwi cr6,r3,17
	cr6.compare<uint32_t>(ctx.r3.u32, 17, xer);
	// ble cr6,0x8240f328
	if (!cr6.gt) goto loc_8240F328;
	// cmplwi cr6,r3,20
	cr6.compare<uint32_t>(ctx.r3.u32, 20, xer);
	// ble cr6,0x8240f330
	if (!cr6.gt) goto loc_8240F330;
	// cmplwi cr6,r3,39
	cr6.compare<uint32_t>(ctx.r3.u32, 39, xer);
	// beq cr6,0x8240f2f8
	if (cr6.eq) goto loc_8240F2F8;
	// cmplwi cr6,r3,40
	cr6.compare<uint32_t>(ctx.r3.u32, 40, xer);
	// bne cr6,0x8240f328
	if (!cr6.eq) goto loc_8240F328;
loc_8240F2E4:
	// li r11,2
	r11.s64 = 2;
loc_8240F2E8:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// stw r10,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r10.u32);
	// blr 
	return;
loc_8240F2F8:
	// li r11,4
	r11.s64 = 4;
	// b 0x8240f2e8
	goto loc_8240F2E8;
loc_8240F300:
	// cmplwi cr6,r3,49
	cr6.compare<uint32_t>(ctx.r3.u32, 49, xer);
	// beq cr6,0x8240f330
	if (cr6.eq) goto loc_8240F330;
	// cmplwi cr6,r3,50
	cr6.compare<uint32_t>(ctx.r3.u32, 50, xer);
	// ble cr6,0x8240f328
	if (!cr6.gt) goto loc_8240F328;
	// cmplwi cr6,r3,53
	cr6.compare<uint32_t>(ctx.r3.u32, 53, xer);
	// ble cr6,0x8240f330
	if (!cr6.gt) goto loc_8240F330;
	// cmplwi cr6,r3,57
	cr6.compare<uint32_t>(ctx.r3.u32, 57, xer);
	// ble cr6,0x8240f328
	if (!cr6.gt) goto loc_8240F328;
	// cmplwi cr6,r3,61
	cr6.compare<uint32_t>(ctx.r3.u32, 61, xer);
	// ble cr6,0x8240f330
	if (!cr6.gt) goto loc_8240F330;
loc_8240F328:
	// li r11,1
	r11.s64 = 1;
	// b 0x8240f334
	goto loc_8240F334;
loc_8240F330:
	// li r11,4
	r11.s64 = 4;
loc_8240F334:
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8240F340"))) PPC_WEAK_FUNC(sub_8240F340);
PPC_FUNC_IMPL(__imp__sub_8240F340) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// rlwinm r9,r6,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r8,r9,r5
	ctx.r8.s64 = ctx.r5.s64 - ctx.r9.s64;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// bgt cr6,0x8240f358
	if (cr6.gt) goto loc_8240F358;
	// li r11,1
	r11.s64 = 1;
loc_8240F358:
	// subf r7,r9,r4
	ctx.r7.s64 = ctx.r4.s64 - ctx.r9.s64;
	// cmplw cr6,r7,r11
	cr6.compare<uint32_t>(ctx.r7.u32, r11.u32, xer);
	// ble cr6,0x8240f36c
	if (!cr6.gt) goto loc_8240F36C;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// b 0x8240f37c
	goto loc_8240F37C;
loc_8240F36C:
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// bgt cr6,0x8240f37c
	if (cr6.gt) goto loc_8240F37C;
	// li r10,1
	ctx.r10.s64 = 1;
loc_8240F37C:
	// subf r11,r9,r3
	r11.s64 = ctx.r3.s64 - ctx.r9.s64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bgt cr6,0x8240f3b8
	if (cr6.gt) goto loc_8240F3B8;
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// bgt cr6,0x8240f398
	if (cr6.gt) goto loc_8240F398;
	// li r11,1
	r11.s64 = 1;
loc_8240F398:
	// cmplw cr6,r7,r11
	cr6.compare<uint32_t>(ctx.r7.u32, r11.u32, xer);
	// ble cr6,0x8240f3a8
	if (!cr6.gt) goto loc_8240F3A8;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// b 0x8240f3b8
	goto loc_8240F3B8;
loc_8240F3A8:
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// bgt cr6,0x8240f3b8
	if (cr6.gt) goto loc_8240F3B8;
	// li r11,1
	r11.s64 = 1;
loc_8240F3B8:
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// subfic r3,r11,32
	xer.ca = r11.u32 <= 32;
	ctx.r3.s64 = 32 - r11.s64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8240F3C4"))) PPC_WEAK_FUNC(sub_8240F3C4);
PPC_FUNC_IMPL(__imp__sub_8240F3C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8240F3C8"))) PPC_WEAK_FUNC(sub_8240F3C8);
PPC_FUNC_IMPL(__imp__sub_8240F3C8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x8240F3D0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r8
	r28.u64 = ctx.r8.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// subfic r11,r28,0
	xer.ca = r28.u32 <= 0;
	r11.s64 = 0 - r28.s64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// clrlwi r11,r11,27
	r11.u64 = r11.u32 & 0x1F;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r23,r9
	r23.u64 = ctx.r9.u64;
	// li r25,32
	r25.s64 = 32;
	// cmplwi cr6,r28,2
	cr6.compare<uint32_t>(r28.u32, 2, xer);
	// addi r24,r11,1
	r24.s64 = r11.s64 + 1;
	// li r27,4
	r27.s64 = 4;
	// beq cr6,0x8240f410
	if (cr6.eq) goto loc_8240F410;
	// li r27,1
	r27.s64 = 1;
loc_8240F410:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x8240f2a8
	ctx.lr = 0x8240F420;
	sub_8240F2A8(ctx, base);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// bne cr6,0x8240f458
	if (!cr6.eq) goto loc_8240F458;
	// mullw r10,r11,r9
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// mullw r10,r10,r26
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r26.s32);
	// rlwinm. r10,r10,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x8240f458
	if (cr0.eq) goto loc_8240F458;
	// li r8,256
	ctx.r8.s64 = 256;
	// twllei r10,0
	// divwu r10,r8,r10
	ctx.r10.u32 = ctx.r8.u32 / ctx.r10.u32;
	// cmplwi cr6,r10,32
	cr6.compare<uint32_t>(ctx.r10.u32, 32, xer);
	// blt cr6,0x8240f458
	if (cr6.lt) goto loc_8240F458;
	// mr r25,r10
	r25.u64 = ctx.r10.u64;
loc_8240F458:
	// mullw r11,r11,r25
	r11.s64 = int64_t(r11.s32) * int64_t(r25.s32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// addi r8,r11,-1
	ctx.r8.s64 = r11.s64 + -1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mullw r11,r9,r24
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r24.s32);
	// andc r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 & ~ctx.r8.u64;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r8,r27,-1
	ctx.r8.s64 = r27.s64 + -1;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmplwi cr6,r28,2
	cr6.compare<uint32_t>(r28.u32, 2, xer);
	// andc r11,r11,r9
	r11.u64 = r11.u64 & ~ctx.r9.u64;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// andc r11,r11,r8
	r11.u64 = r11.u64 & ~ctx.r8.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mullw r9,r9,r26
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(r26.s32);
	// rlwinm r9,r9,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFF;
	// mullw r10,r9,r10
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// beq cr6,0x8240f4d4
	if (cr6.eq) goto loc_8240F4D4;
	// addi r10,r10,4095
	ctx.r10.s64 = ctx.r10.s64 + 4095;
	// rlwinm r10,r10,0,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFF000;
	// mullw r3,r10,r11
	ctx.r3.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// b 0x8240f4e0
	goto loc_8240F4E0;
loc_8240F4D4:
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// addi r11,r11,4095
	r11.s64 = r11.s64 + 4095;
	// rlwinm r3,r11,0,0,19
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
loc_8240F4E0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8240F4E8"))) PPC_WEAK_FUNC(sub_8240F4E8);
PPC_FUNC_IMPL(__imp__sub_8240F4E8) {
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
	ctx.lr = 0x8240F4F0;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r8
	r22.u64 = ctx.r8.u64;
	// stw r5,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, ctx.r5.u32);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r15,r6
	r15.u64 = ctx.r6.u64;
	// stw r8,332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 332, ctx.r8.u32);
	// mr r20,r7
	r20.u64 = ctx.r7.u64;
	// mr r16,r9
	r16.u64 = ctx.r9.u64;
	// li r19,1
	r19.s64 = 1;
	// li r17,0
	r17.s64 = 0;
	// cmplwi cr6,r22,1
	cr6.compare<uint32_t>(r22.u32, 1, xer);
	// bne cr6,0x8240f534
	if (!cr6.eq) goto loc_8240F534;
	// cmplwi cr6,r5,1
	cr6.compare<uint32_t>(ctx.r5.u32, 1, xer);
	// ble cr6,0x8240f534
	if (!cr6.gt) goto loc_8240F534;
	// stw r19,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r19.u32);
	// b 0x8240f544
	goto loc_8240F544;
loc_8240F534:
	// stw r17,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r17.u32);
	// cmplwi cr6,r22,3
	cr6.compare<uint32_t>(r22.u32, 3, xer);
	// mr r14,r17
	r14.u64 = r17.u64;
	// bne cr6,0x8240f548
	if (!cr6.eq) goto loc_8240F548;
loc_8240F544:
	// mr r14,r19
	r14.u64 = r19.u64;
loc_8240F548:
	// cmpwi cr6,r14,0
	cr6.compare<int32_t>(r14.s32, 0, xer);
	// mr r28,r19
	r28.u64 = r19.u64;
	// bne cr6,0x8240f558
	if (!cr6.eq) goto loc_8240F558;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
loc_8240F558:
	// lwz r31,340(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// rlwinm r7,r20,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r10,6712
	ctx.r10.s64 = ctx.r10.s64 + 6712;
	// subf r23,r11,r3
	r23.s64 = ctx.r3.s64 - r11.s64;
	// subf r26,r11,r25
	r26.s64 = r25.s64 - r11.s64;
	// addi r9,r23,-1
	ctx.r9.s64 = r23.s64 + -1;
	// addi r6,r26,-1
	ctx.r6.s64 = r26.s64 + -1;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// cntlzw r10,r9
	ctx.r10.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// cntlzw r9,r6
	ctx.r9.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// subf r10,r10,r31
	ctx.r10.s64 = r31.s64 - ctx.r10.s64;
	// subf r9,r9,r31
	ctx.r9.s64 = r31.s64 - ctx.r9.s64;
	// lbzx r21,r7,r5
	r21.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r5.u32);
	// addi r29,r10,32
	r29.s64 = ctx.r10.s64 + 32;
	// addi r30,r9,32
	r30.s64 = ctx.r9.s64 + 32;
	// cmplwi cr6,r22,2
	cr6.compare<uint32_t>(r22.u32, 2, xer);
	// bne cr6,0x8240f5bc
	if (!cr6.eq) goto loc_8240F5BC;
	// subf r24,r11,r28
	r24.s64 = r28.s64 - r11.s64;
	// addi r11,r24,-1
	r11.s64 = r24.s64 + -1;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// subf r11,r11,r31
	r11.s64 = r31.s64 - r11.s64;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// b 0x8240f5c4
	goto loc_8240F5C4;
loc_8240F5BC:
	// mr r24,r19
	r24.u64 = r19.u64;
	// mr r11,r17
	r11.u64 = r17.u64;
loc_8240F5C4:
	// slw r11,r19,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (r19.u32 << (r11.u8 & 0x3F));
	// lwz r27,356(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 356);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// slw r10,r19,r29
	ctx.r10.u64 = r29.u8 & 0x20 ? 0 : (r19.u32 << (r29.u8 & 0x3F));
	// slw r11,r19,r30
	r11.u64 = r30.u8 & 0x20 ? 0 : (r19.u32 << (r30.u8 & 0x3F));
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// cmplwi cr6,r10,16
	cr6.compare<uint32_t>(ctx.r10.u32, 16, xer);
	// ble cr6,0x8240f5f0
	if (!cr6.gt) goto loc_8240F5F0;
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// bgt cr6,0x8240f5f8
	if (cr6.gt) goto loc_8240F5F8;
loc_8240F5F0:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x8240f620
	if (!cr6.eq) goto loc_8240F620;
loc_8240F5F8:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x8240f608
	if (!cr6.eq) goto loc_8240F608;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// b 0x8240f618
	goto loc_8240F618;
loc_8240F608:
	// rlwinm r11,r27,3,0,28
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 3) & 0xFFFFFFF8;
	// twllei r21,0
	// divwu r11,r11,r21
	r11.u32 = r11.u32 / r21.u32;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
loc_8240F618:
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r25.u32);
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
loc_8240F620:
	// mr r9,r16
	ctx.r9.u64 = r16.u64;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// mr r6,r21
	ctx.r6.u64 = r21.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8240f3c8
	ctx.lr = 0x8240F640;
	sub_8240F3C8(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// lwz r18,88(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bne cr6,0x8240f654
	if (!cr6.eq) goto loc_8240F654;
	// mullw r11,r18,r21
	r11.s64 = int64_t(r18.s32) * int64_t(r21.s32);
	// rlwinm r27,r11,29,3,31
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFF;
loc_8240F654:
	// cmpwi cr6,r16,0
	cr6.compare<int32_t>(r16.s32, 0, xer);
	// bne cr6,0x8240f6d0
	if (!cr6.eq) goto loc_8240F6D0;
	// cmpwi cr6,r14,0
	cr6.compare<int32_t>(r14.s32, 0, xer);
	// bne cr6,0x8240f6d0
	if (!cr6.eq) goto loc_8240F6D0;
	// cmplwi cr6,r22,2
	cr6.compare<uint32_t>(r22.u32, 2, xer);
	// beq cr6,0x8240f6f4
	if (cr6.eq) goto loc_8240F6F4;
	// cmplwi cr6,r22,1
	cr6.compare<uint32_t>(r22.u32, 1, xer);
	// bne cr6,0x8240f6bc
	if (!cr6.eq) goto loc_8240F6BC;
	// cmplwi cr6,r15,1
	cr6.compare<uint32_t>(r15.u32, 1, xer);
	// bne cr6,0x8240f6bc
	if (!cr6.eq) goto loc_8240F6BC;
	// lwz r11,332(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8240f6bc
	if (!cr6.eq) goto loc_8240F6BC;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8240f6bc
	if (!cr6.eq) goto loc_8240F6BC;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x8240f2a8
	ctx.lr = 0x8240F6A0;
	sub_8240F2A8(ctx, base);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// add r10,r11,r25
	ctx.r10.u64 = r11.u64 + r25.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// andc r11,r10,r11
	r11.u64 = ctx.r10.u64 & ~r11.u64;
	// mullw r25,r11,r27
	r25.s64 = int64_t(r11.s32) * int64_t(r27.s32);
	// b 0x8240f834
	goto loc_8240F834;
loc_8240F6BC:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mullw r11,r27,r11
	r11.s64 = int64_t(r27.s32) * int64_t(r11.s32);
	// mullw r25,r11,r10
	r25.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// b 0x8240f71c
	goto loc_8240F71C;
loc_8240F6D0:
	// cmplwi cr6,r22,2
	cr6.compare<uint32_t>(r22.u32, 2, xer);
	// beq cr6,0x8240f6f4
	if (cr6.eq) goto loc_8240F6F4;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mullw r11,r27,r11
	r11.s64 = int64_t(r27.s32) * int64_t(r11.s32);
	// addi r11,r11,4095
	r11.s64 = r11.s64 + 4095;
	// rlwinm r11,r11,0,0,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	// mullw r25,r11,r10
	r25.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// b 0x8240f70c
	goto loc_8240F70C;
loc_8240F6F4:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mullw r11,r27,r11
	r11.s64 = int64_t(r27.s32) * int64_t(r11.s32);
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// addi r11,r11,4095
	r11.s64 = r11.s64 + 4095;
	// rlwinm r25,r11,0,0,19
	r25.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
loc_8240F70C:
	// cmpwi cr6,r14,0
	cr6.compare<int32_t>(r14.s32, 0, xer);
	// beq cr6,0x8240f71c
	if (cr6.eq) goto loc_8240F71C;
	// lwz r11,292(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// mullw r25,r25,r11
	r25.s64 = int64_t(r25.s32) * int64_t(r11.s32);
loc_8240F71C:
	// cmplwi cr6,r15,1
	cr6.compare<uint32_t>(r15.u32, 1, xer);
	// bgt cr6,0x8240f72c
	if (cr6.gt) goto loc_8240F72C;
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// bne cr6,0x8240f834
	if (!cr6.eq) goto loc_8240F834;
loc_8240F72C:
	// cmplw cr6,r26,r24
	cr6.compare<uint32_t>(r26.u32, r24.u32, xer);
	// mr r11,r26
	r11.u64 = r26.u64;
	// bgt cr6,0x8240f73c
	if (cr6.gt) goto loc_8240F73C;
	// mr r11,r24
	r11.u64 = r24.u64;
loc_8240F73C:
	// cmplw cr6,r23,r11
	cr6.compare<uint32_t>(r23.u32, r11.u32, xer);
	// ble cr6,0x8240f74c
	if (!cr6.gt) goto loc_8240F74C;
	// mr r11,r23
	r11.u64 = r23.u64;
	// b 0x8240f75c
	goto loc_8240F75C;
loc_8240F74C:
	// cmplw cr6,r26,r24
	cr6.compare<uint32_t>(r26.u32, r24.u32, xer);
	// mr r11,r26
	r11.u64 = r26.u64;
	// bgt cr6,0x8240f75c
	if (cr6.gt) goto loc_8240F75C;
	// mr r11,r24
	r11.u64 = r24.u64;
loc_8240F75C:
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// bne cr6,0x8240f76c
	if (!cr6.eq) goto loc_8240F76C;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// subfic r15,r11,32
	xer.ca = r11.u32 <= 32;
	r15.s64 = 32 - r11.s64;
loc_8240F76C:
	// li r11,15
	r11.s64 = 15;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// subfic r27,r11,32
	xer.ca = r11.u32 <= 32;
	r27.s64 = 32 - r11.s64;
	// addic. r31,r15,-1
	xer.ca = r15.u32 > 0;
	r31.s64 = r15.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x8240f800
	if (cr0.eq) goto loc_8240F800;
loc_8240F780:
	// lwz r11,332(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8240f79c
	if (cr6.eq) goto loc_8240F79C;
	// cmplw cr6,r29,r27
	cr6.compare<uint32_t>(r29.u32, r27.u32, xer);
	// ble cr6,0x8240f800
	if (!cr6.gt) goto loc_8240F800;
	// cmplw cr6,r30,r27
	cr6.compare<uint32_t>(r30.u32, r27.u32, xer);
	// ble cr6,0x8240f800
	if (!cr6.gt) goto loc_8240F800;
loc_8240F79C:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8240f7a8
	if (cr6.eq) goto loc_8240F7A8;
	// addi r29,r29,-1
	r29.s64 = r29.s64 + -1;
loc_8240F7A8:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8240f7b4
	if (cr6.eq) goto loc_8240F7B4;
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
loc_8240F7B4:
	// cmplwi cr6,r28,1
	cr6.compare<uint32_t>(r28.u32, 1, xer);
	// ble cr6,0x8240f7c0
	if (!cr6.gt) goto loc_8240F7C0;
	// rlwinm r28,r28,31,1,31
	r28.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 31) & 0x7FFFFFFF;
loc_8240F7C0:
	// slw r11,r19,r29
	r11.u64 = r29.u8 & 0x20 ? 0 : (r19.u32 << (r29.u8 & 0x3F));
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// slw r10,r19,r30
	ctx.r10.u64 = r30.u8 & 0x20 ? 0 : (r19.u32 << (r30.u8 & 0x3F));
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// mr r9,r16
	ctx.r9.u64 = r16.u64;
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// mr r6,r21
	ctx.r6.u64 = r21.u64;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8240f3c8
	ctx.lr = 0x8240F7F4;
	sub_8240F3C8(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// add r17,r3,r17
	r17.u64 = ctx.r3.u64 + r17.u64;
	// bne 0x8240f780
	if (!cr0.eq) goto loc_8240F780;
loc_8240F800:
	// cmpwi cr6,r14,0
	cr6.compare<int32_t>(r14.s32, 0, xer);
	// beq cr6,0x8240f834
	if (cr6.eq) goto loc_8240F834;
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r10,292(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	// subfic r11,r11,0
	xer.ca = r11.u32 <= 0;
	r11.s64 = 0 - r11.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// andc r11,r10,r11
	r11.u64 = ctx.r10.u64 & ~r11.u64;
	// mullw r17,r11,r17
	r17.s64 = int64_t(r11.s32) * int64_t(r17.s32);
loc_8240F834:
	// lwz r11,364(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 364);
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// lwz r10,372(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// lwz r9,380(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 380);
	// stw r18,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r18.u32);
	// stw r25,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r25.u32);
	// stw r17,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r17.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8240F858"))) PPC_WEAK_FUNC(sub_8240F858);
PPC_FUNC_IMPL(__imp__sub_8240F858) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x8240F860;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r25,r10
	r25.u64 = ctx.r10.u64;
	// addi r10,r11,6712
	ctx.r10.s64 = r11.s64 + 6712;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// addi r8,r1,100
	ctx.r8.s64 = ctx.r1.s64 + 100;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// li r11,0
	r11.s64 = 0;
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lbzx r24,r7,r10
	r24.u64 = PPC_LOAD_U8(ctx.r7.u32 + ctx.r10.u32);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x8240f2a8
	ctx.lr = 0x8240F8B8;
	sub_8240F2A8(ctx, base);
	// addi r11,r30,-1
	r11.s64 = r30.s64 + -1;
	// addi r10,r29,-1
	ctx.r10.s64 = r29.s64 + -1;
	// addi r9,r28,-1
	ctx.r9.s64 = r28.s64 + -1;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cntlzw r9,r9
	ctx.r9.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// subfic r11,r11,32
	xer.ca = r11.u32 <= 32;
	r11.s64 = 32 - r11.s64;
	// subfic r10,r10,32
	xer.ca = ctx.r10.u32 <= 32;
	ctx.r10.s64 = 32 - ctx.r10.s64;
	// subfic r8,r9,32
	xer.ca = ctx.r9.u32 <= 32;
	ctx.r8.s64 = 32 - ctx.r9.s64;
	// li r9,1
	ctx.r9.s64 = 1;
	// subfc r7,r11,r10
	xer.ca = ctx.r10.u32 >= r11.u32;
	ctx.r7.s64 = ctx.r10.s64 - r11.s64;
	// slw r11,r9,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (ctx.r9.u32 << (r11.u8 & 0x3F));
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// slw r11,r9,r10
	r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r10.u8 & 0x3F));
	// subfe r7,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r7.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// cmplwi cr6,r31,3
	cr6.compare<uint32_t>(r31.u32, 3, xer);
	// clrlwi r11,r7,31
	r11.u64 = ctx.r7.u32 & 0x1;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bge cr6,0x8240f974
	if (!cr6.lt) goto loc_8240F974;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// sraw r10,r10,r31
	temp.u32 = r31.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r10.s64 = ctx.r10.s32 >> temp.u32;
	// stwx r10,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, ctx.r10.u32);
loc_8240F918:
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
loc_8240F91C:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mullw r7,r10,r24
	ctx.r7.s64 = int64_t(ctx.r10.s32) * int64_t(r24.s32);
	// lwz r8,100(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r4,276(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// lwz r3,284(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 284);
	// mullw r7,r7,r9
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// twllei r10,0
	// divwu r10,r9,r10
	ctx.r10.u32 = ctx.r9.u32 / ctx.r10.u32;
	// rlwinm r6,r7,29,3,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 29) & 0x1FFFFFFF;
	// mullw r7,r8,r27
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(r27.s32);
	// stw r10,0(r25)
	PPC_STORE_U32(r25.u32 + 0, ctx.r10.u32);
	// divwu r8,r8,r5
	ctx.r8.u32 = ctx.r8.u32 / ctx.r5.u32;
	// add r9,r6,r7
	ctx.r9.u64 = ctx.r6.u64 + ctx.r7.u64;
	// mullw r10,r11,r26
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(r26.s32);
	// stw r8,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r8.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// twllei r5,0
	// add r3,r9,r10
	ctx.r3.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9238
	return;
loc_8240F974:
	// xori r11,r11,4
	r11.u64 = r11.u64 ^ 4;
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// addi r7,r31,-2
	ctx.r7.s64 = r31.s64 + -2;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// srw r10,r10,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r7.u8 & 0x3F));
	// stwx r10,r11,r6
	PPC_STORE_U32(r11.u32 + ctx.r6.u32, ctx.r10.u32);
	// cmplwi cr6,r10,4
	cr6.compare<uint32_t>(ctx.r10.u32, 4, xer);
	// bge cr6,0x8240f918
	if (!cr6.lt) goto loc_8240F918;
	// subf r11,r31,r8
	r11.s64 = ctx.r8.s64 - r31.s64;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bgt cr6,0x8240f9a8
	if (cr6.gt) goto loc_8240F9A8;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8240F9A8:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// b 0x8240f91c
	goto loc_8240F91C;
}

__attribute__((alias("__imp__sub_8240F9B0"))) PPC_WEAK_FUNC(sub_8240F9B0);
PPC_FUNC_IMPL(__imp__sub_8240F9B0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c4
	ctx.lr = 0x8240F9B8;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// addi r11,r11,6712
	r11.s64 = r11.s64 + 6712;
	// mr r20,r5
	r20.u64 = ctx.r5.u64;
	// lwz r10,32(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// mr r19,r6
	r19.u64 = ctx.r6.u64;
	// clrlwi r22,r10,26
	r22.u64 = ctx.r10.u32 & 0x3F;
	// mr r18,r7
	r18.u64 = ctx.r7.u64;
	// rlwinm r10,r22,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r17,r8
	r17.u64 = ctx.r8.u64;
	// mr r16,r9
	r16.u64 = ctx.r9.u64;
	// lbzx r21,r10,r11
	r21.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// bl 0x82421a18
	ctx.lr = 0x8240F9F8;
	sub_82421A18(ctx, base);
	// mr r15,r3
	r15.u64 = ctx.r3.u64;
	// addi r6,r1,100
	ctx.r6.s64 = ctx.r1.s64 + 100;
	// cmpwi cr6,r15,4
	cr6.compare<int32_t>(r15.s32, 4, xer);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,92
	ctx.r4.s64 = ctx.r1.s64 + 92;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bne cr6,0x8240fa68
	if (!cr6.eq) goto loc_8240FA68;
	// bl 0x8240f188
	ctx.lr = 0x8240FA18;
	sub_8240F188(ctx, base);
	// lwz r11,28(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// lwz r10,48(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// rlwinm r9,r11,10,23,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 10) & 0x1FF;
	// mr r6,r21
	ctx.r6.u64 = r21.u64;
	// mullw r31,r9,r21
	r31.s64 = int64_t(ctx.r9.s32) * int64_t(r21.s32);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// rlwinm r8,r10,23,30,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 23) & 0x3;
	// rlwinm r31,r31,2,3,29
	r31.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0x1FFFFFFC;
	// lwz r25,92(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r27,96(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r24,100(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// stw r25,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r25.u32);
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// stw r24,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r24.u32);
	// bl 0x8240f3c8
	ctx.lr = 0x8240FA64;
	sub_8240F3C8(ctx, base);
	// b 0x8240fd10
	goto loc_8240FD10;
loc_8240FA68:
	// lwz r11,40(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// rlwinm r31,r11,1,31,31
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// rlwinm r8,r31,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x8240f188
	ctx.lr = 0x8240FA78;
	sub_8240F188(ctx, base);
	// lwz r28,48(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// li r5,1
	ctx.r5.s64 = 1;
	// rlwinm r26,r28,23,30,31
	r26.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 23) & 0x3;
	// cmplwi cr6,r26,2
	cr6.compare<uint32_t>(r26.u32, 2, xer);
	// lwz r25,92(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r27,96(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// subf r9,r8,r25
	ctx.r9.s64 = r25.s64 - ctx.r8.s64;
	// lwz r24,100(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// subf r7,r8,r27
	ctx.r7.s64 = r27.s64 - ctx.r8.s64;
	// addi r11,r9,-1
	r11.s64 = ctx.r9.s64 + -1;
	// addi r10,r7,-1
	ctx.r10.s64 = ctx.r7.s64 + -1;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// subf r11,r11,r31
	r11.s64 = r31.s64 - r11.s64;
	// subf r10,r10,r31
	ctx.r10.s64 = r31.s64 - ctx.r10.s64;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// slw r4,r5,r11
	ctx.r4.u64 = r11.u8 & 0x20 ? 0 : (ctx.r5.u32 << (r11.u8 & 0x3F));
	// slw r3,r5,r10
	ctx.r3.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r10.u8 & 0x3F));
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// bne cr6,0x8240faec
	if (!cr6.eq) goto loc_8240FAEC;
	// subf r11,r8,r24
	r11.s64 = r24.s64 - ctx.r8.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// subf r11,r11,r31
	r11.s64 = r31.s64 - r11.s64;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// slw r30,r5,r11
	r30.u64 = r11.u8 & 0x20 ? 0 : (ctx.r5.u32 << (r11.u8 & 0x3F));
	// b 0x8240faf0
	goto loc_8240FAF0;
loc_8240FAEC:
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
loc_8240FAF0:
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// bne cr6,0x8240fbb8
	if (!cr6.eq) goto loc_8240FBB8;
	// cmplwi cr6,r4,16
	cr6.compare<uint32_t>(ctx.r4.u32, 16, xer);
	// ble cr6,0x8240fb0c
	if (!cr6.gt) goto loc_8240FB0C;
	// cmplwi cr6,r3,16
	cr6.compare<uint32_t>(ctx.r3.u32, 16, xer);
	// bgt cr6,0x8240fb14
	if (cr6.gt) goto loc_8240FB14;
loc_8240FB0C:
	// rlwinm. r11,r28,0,20,20
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x800;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8240fb20
	if (!cr0.eq) goto loc_8240FB20;
loc_8240FB14:
	// stw r25,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r25.u32);
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// stw r24,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r24.u32);
loc_8240FB20:
	// lwz r30,28(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// rlwinm r22,r30,1,31,31
	r22.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0x1;
	// mr r6,r21
	ctx.r6.u64 = r21.u64;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// bl 0x8240f3c8
	ctx.lr = 0x8240FB48;
	sub_8240F3C8(ctx, base);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// bne cr6,0x8240fba8
	if (!cr6.eq) goto loc_8240FBA8;
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// rlwinm. r10,r11,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x400;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8240fba8
	if (!cr0.eq) goto loc_8240FBA8;
	// rlwinm. r10,r28,0,20,20
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x800;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8240fba8
	if (!cr0.eq) goto loc_8240FBA8;
	// cmplwi cr6,r26,1
	cr6.compare<uint32_t>(r26.u32, 1, xer);
	// bne cr6,0x8240fba8
	if (!cr6.eq) goto loc_8240FBA8;
	// lwz r10,44(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// rlwinm. r10,r10,0,22,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x3C0;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8240fba8
	if (!cr0.eq) goto loc_8240FBA8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8240fba8
	if (!cr6.eq) goto loc_8240FBA8;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// clrlwi r3,r11,26
	ctx.r3.u64 = r11.u32 & 0x3F;
	// bl 0x8240f2a8
	ctx.lr = 0x8240FB90;
	sub_8240F2A8(ctx, base);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// add r10,r11,r27
	ctx.r10.u64 = r11.u64 + r27.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// andc r11,r10,r11
	r11.u64 = ctx.r10.u64 & ~r11.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
loc_8240FBA8:
	// rlwinm r11,r30,10,23,31
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 10) & 0x1FF;
	// mullw r11,r11,r21
	r11.s64 = int64_t(r11.s32) * int64_t(r21.s32);
	// rlwinm r31,r11,2,3,29
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x1FFFFFFC;
	// b 0x8240fd10
	goto loc_8240FD10;
loc_8240FBB8:
	// srw r11,r9,r23
	r11.u64 = r23.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (r23.u8 & 0x3F));
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bgt cr6,0x8240fbd0
	if (cr6.gt) goto loc_8240FBD0;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
loc_8240FBD0:
	// srw r10,r7,r23
	ctx.r10.u64 = r23.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (r23.u8 & 0x3F));
	// add r25,r11,r8
	r25.u64 = r11.u64 + ctx.r8.u64;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bgt cr6,0x8240fbe4
	if (cr6.gt) goto loc_8240FBE4;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
loc_8240FBE4:
	// add r27,r10,r8
	r27.u64 = ctx.r10.u64 + ctx.r8.u64;
	// cmplwi cr6,r26,2
	cr6.compare<uint32_t>(r26.u32, 2, xer);
	// bne cr6,0x8240fc0c
	if (!cr6.eq) goto loc_8240FC0C;
	// subf r11,r8,r24
	r11.s64 = r24.s64 - ctx.r8.s64;
	// srw r11,r11,r23
	r11.u64 = r23.u8 & 0x20 ? 0 : (r11.u32 >> (r23.u8 & 0x3F));
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bgt cr6,0x8240fc04
	if (cr6.gt) goto loc_8240FC04;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
loc_8240FC04:
	// add r24,r11,r8
	r24.u64 = r11.u64 + ctx.r8.u64;
	// b 0x8240fc10
	goto loc_8240FC10;
loc_8240FC0C:
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
loc_8240FC10:
	// rlwinm. r11,r28,0,20,20
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x800;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8240fca4
	if (cr0.eq) goto loc_8240FCA4;
	// subf r10,r8,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r8.s64;
	// subf r11,r8,r6
	r11.s64 = ctx.r6.s64 - ctx.r8.s64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cntlzw r7,r11
	ctx.r7.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// subf r11,r10,r31
	r11.s64 = r31.s64 - ctx.r10.s64;
	// subf r10,r7,r31
	ctx.r10.s64 = r31.s64 - ctx.r7.s64;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8240fc4c
	if (cr6.lt) goto loc_8240FC4C;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8240FC4C:
	// addic. r11,r11,-4
	xer.ca = r11.u32 > 3;
	r11.s64 = r11.s64 + -4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bgt 0x8240fc58
	if (cr0.gt) goto loc_8240FC58;
	// li r11,0
	r11.s64 = 0;
loc_8240FC58:
	// cmplw cr6,r23,r11
	cr6.compare<uint32_t>(r23.u32, r11.u32, xer);
	// blt cr6,0x8240fca4
	if (cr6.lt) goto loc_8240FCA4;
	// subf r10,r8,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r8.s64;
	// subf r11,r8,r6
	r11.s64 = ctx.r6.s64 - ctx.r8.s64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// subf r11,r10,r31
	r11.s64 = r31.s64 - ctx.r10.s64;
	// subf r10,r9,r31
	ctx.r10.s64 = r31.s64 - ctx.r9.s64;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x8240fc94
	if (cr6.lt) goto loc_8240FC94;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8240FC94:
	// addic. r11,r11,-4
	xer.ca = r11.u32 > 3;
	r11.s64 = r11.s64 + -4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// mr r23,r11
	r23.u64 = r11.u64;
	// bgt 0x8240fca4
	if (cr0.gt) goto loc_8240FCA4;
	// li r23,0
	r23.s64 = 0;
loc_8240FCA4:
	// srw r11,r4,r23
	r11.u64 = r23.u8 & 0x20 ? 0 : (ctx.r4.u32 >> (r23.u8 & 0x3F));
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// bgt cr6,0x8240fcb8
	if (cr6.gt) goto loc_8240FCB8;
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
loc_8240FCB8:
	// srw r11,r3,r23
	r11.u64 = r23.u8 & 0x20 ? 0 : (ctx.r3.u32 >> (r23.u8 & 0x3F));
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bgt cr6,0x8240fccc
	if (cr6.gt) goto loc_8240FCCC;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
loc_8240FCCC:
	// srw r11,r30,r23
	r11.u64 = r23.u8 & 0x20 ? 0 : (r30.u32 >> (r23.u8 & 0x3F));
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bgt cr6,0x8240fce0
	if (cr6.gt) goto loc_8240FCE0;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
loc_8240FCE0:
	// lwz r11,28(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// mr r6,r21
	ctx.r6.u64 = r21.u64;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// bl 0x8240f3c8
	ctx.lr = 0x8240FD04;
	sub_8240F3C8(ctx, base);
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mullw r11,r11,r21
	r11.s64 = int64_t(r11.s32) * int64_t(r21.s32);
	// rlwinm r31,r11,29,3,31
	r31.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFF;
loc_8240FD10:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// stw r25,0(r20)
	PPC_STORE_U32(r20.u32 + 0, r25.u32);
	// stw r27,0(r19)
	PPC_STORE_U32(r19.u32 + 0, r27.u32);
	// mullw r11,r31,r11
	r11.s64 = int64_t(r31.s32) * int64_t(r11.s32);
	// stw r24,0(r18)
	PPC_STORE_U32(r18.u32 + 0, r24.u32);
	// stw r31,0(r17)
	PPC_STORE_U32(r17.u32 + 0, r31.u32);
	// stw r11,0(r16)
	PPC_STORE_U32(r16.u32 + 0, r11.u32);
	// lwz r10,28(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// rlwinm. r10,r10,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x8240fd50
	if (!cr0.eq) goto loc_8240FD50;
	// cmplwi cr6,r23,1
	cr6.compare<uint32_t>(r23.u32, 1, xer);
	// bgt cr6,0x8240fd50
	if (cr6.gt) goto loc_8240FD50;
	// cmpwi cr6,r15,3
	cr6.compare<int32_t>(r15.s32, 3, xer);
	// beq cr6,0x8240fd6c
	if (cr6.eq) goto loc_8240FD6C;
	// cmpwi cr6,r15,20
	cr6.compare<int32_t>(r15.s32, 20, xer);
	// beq cr6,0x8240fd6c
	if (cr6.eq) goto loc_8240FD6C;
loc_8240FD50:
	// lwz r10,48(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// rlwinm r10,r10,0,21,22
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x600;
	// cmplwi cr6,r10,1024
	cr6.compare<uint32_t>(ctx.r10.u32, 1024, xer);
	// beq cr6,0x8240fd6c
	if (cr6.eq) goto loc_8240FD6C;
	// addi r11,r11,4095
	r11.s64 = r11.s64 + 4095;
	// rlwinm r11,r11,0,0,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	// stw r11,0(r16)
	PPC_STORE_U32(r16.u32 + 0, r11.u32);
loc_8240FD6C:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9214
	return;
}

__attribute__((alias("__imp__sub_8240FD74"))) PPC_WEAK_FUNC(sub_8240FD74);
PPC_FUNC_IMPL(__imp__sub_8240FD74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8240FD78"))) PPC_WEAK_FUNC(sub_8240FD78);
PPC_FUNC_IMPL(__imp__sub_8240FD78) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r9,r1,88
	ctx.r9.s64 = ctx.r1.s64 + 88;
	// addi r8,r1,92
	ctx.r8.s64 = ctx.r1.s64 + 92;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8240f9b0
	ctx.lr = 0x8240FDAC;
	sub_8240F9B0(ctx, base);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r7,r11,25,29,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x7;
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// rlwinm r9,r11,25,26,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x38;
	// rlwinm r6,r11,28,29,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0x7;
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// rlwinm r7,r11,31,29,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r5,r10,26,30,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0x3;
	// or r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 | ctx.r6.u64;
	// rlwinm r6,r10,24,30,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0x3;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// rlwinm r7,r10,28,30,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x3;
	// rlwimi r11,r9,1,0,30
	r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 1) & 0xFFFFFFFE) | (r11.u64 & 0xFFFFFFFF00000001);
	// rlwinm r9,r10,30,30,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r10,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// or r11,r11,r6
	r11.u64 = r11.u64 | ctx.r6.u64;
	// rlwinm r6,r8,26,30,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 26) & 0x3;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// or r11,r11,r5
	r11.u64 = r11.u64 | ctx.r5.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// or r11,r11,r7
	r11.u64 = r11.u64 | ctx.r7.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// or r11,r11,r9
	r11.u64 = r11.u64 | ctx.r9.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// or r11,r11,r6
	r11.u64 = r11.u64 | ctx.r6.u64;
	// rlwimi r8,r11,6,0,25
	ctx.r8.u64 = (__builtin_rotateleft32(r11.u32, 6) & 0xFFFFFFC0) | (ctx.r8.u64 & 0xFFFFFFFF0000003F);
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
	// bl 0x82421a18
	ctx.lr = 0x8240FE38;
	sub_82421A18(ctx, base);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r11,0
	r11.s64 = 0;
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
	// stw r10,24(r30)
	PPC_STORE_U32(r30.u32 + 24, ctx.r10.u32);
	// stw r9,28(r30)
	PPC_STORE_U32(r30.u32 + 28, ctx.r9.u32);
	// stw r11,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r11.u32);
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

__attribute__((alias("__imp__sub_8240FE78"))) PPC_WEAK_FUNC(sub_8240FE78);
PPC_FUNC_IMPL(__imp__sub_8240FE78) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r9,r1,92
	ctx.r9.s64 = ctx.r1.s64 + 92;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8240f9b0
	ctx.lr = 0x8240FEAC;
	sub_8240F9B0(ctx, base);
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r7,r11,25,29,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x7;
	// lwz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// rlwinm r9,r11,25,26,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x38;
	// rlwinm r6,r11,28,29,31
	ctx.r6.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0x7;
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// rlwinm r7,r11,31,29,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r5,r10,26,30,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0x3;
	// or r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 | ctx.r6.u64;
	// rlwinm r6,r10,24,30,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0x3;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// rlwinm r7,r10,28,30,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x3;
	// rlwimi r11,r9,1,0,30
	r11.u64 = (__builtin_rotateleft32(ctx.r9.u32, 1) & 0xFFFFFFFE) | (r11.u64 & 0xFFFFFFFF00000001);
	// rlwinm r9,r10,30,30,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r10,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// or r11,r11,r6
	r11.u64 = r11.u64 | ctx.r6.u64;
	// rlwinm r6,r8,26,30,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 26) & 0x3;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// or r11,r11,r5
	r11.u64 = r11.u64 | ctx.r5.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// or r11,r11,r7
	r11.u64 = r11.u64 | ctx.r7.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// or r11,r11,r9
	r11.u64 = r11.u64 | ctx.r9.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// or r11,r11,r6
	r11.u64 = r11.u64 | ctx.r6.u64;
	// rlwimi r8,r11,6,0,25
	ctx.r8.u64 = (__builtin_rotateleft32(r11.u32, 6) & 0xFFFFFFC0) | (ctx.r8.u64 & 0xFFFFFFFF0000003F);
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
	// bl 0x82421a18
	ctx.lr = 0x8240FF38;
	sub_82421A18(ctx, base);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r11,0
	r11.s64 = 0;
	// lwz r8,88(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// stw r10,16(r30)
	PPC_STORE_U32(r30.u32 + 16, ctx.r10.u32);
	// stw r9,20(r30)
	PPC_STORE_U32(r30.u32 + 20, ctx.r9.u32);
	// stw r8,24(r30)
	PPC_STORE_U32(r30.u32 + 24, ctx.r8.u32);
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

__attribute__((alias("__imp__sub_8240FF78"))) PPC_WEAK_FUNC(sub_8240FF78);
PPC_FUNC_IMPL(__imp__sub_8240FF78) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x8240FF80;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r10,364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 364, ctx.r10.u32);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// stw r9,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, ctx.r9.u32);
	// stw r6,332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 332, ctx.r6.u32);
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// addi r11,r11,6712
	r11.s64 = r11.s64 + 6712;
	// stw r7,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, ctx.r7.u32);
	// stw r8,348(r1)
	PPC_STORE_U32(ctx.r1.u32 + 348, ctx.r8.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r10,1,25,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x7E;
	// lwz r7,28(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r6,48(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// rlwinm r30,r9,1,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// stw r4,316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 316, ctx.r4.u32);
	// rlwinm r27,r7,1,31,31
	r27.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0x1;
	// stw r8,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// rlwinm r25,r6,23,30,31
	r25.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 23) & 0x3;
	// rlwinm r29,r30,1,0,30
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lbzx r16,r10,r11
	r16.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// bl 0x82421a18
	ctx.lr = 0x8240FFE4;
	sub_82421A18(ctx, base);
	// addi r6,r1,104
	ctx.r6.s64 = ctx.r1.s64 + 104;
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8240f188
	ctx.lr = 0x8240FFF8;
	sub_8240F188(ctx, base);
	// li r28,1
	r28.s64 = 1;
	// cmplwi cr6,r25,2
	cr6.compare<uint32_t>(r25.u32, 2, xer);
	// lwz r14,108(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r7,112(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// subf r8,r29,r14
	ctx.r8.s64 = r14.s64 - r29.s64;
	// subf r9,r29,r7
	ctx.r9.s64 = ctx.r7.s64 - r29.s64;
	// addi r11,r8,-1
	r11.s64 = ctx.r8.s64 + -1;
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r6,r10
	ctx.r6.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// subf r10,r11,r30
	ctx.r10.s64 = r30.s64 - r11.s64;
	// subf r11,r6,r30
	r11.s64 = r30.s64 - ctx.r6.s64;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// slw r20,r28,r10
	r20.u64 = ctx.r10.u8 & 0x20 ? 0 : (r28.u32 << (ctx.r10.u8 & 0x3F));
	// slw r26,r28,r11
	r26.u64 = r11.u8 & 0x20 ? 0 : (r28.u32 << (r11.u8 & 0x3F));
	// bne cr6,0x8241005c
	if (!cr6.eq) goto loc_8241005C;
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// subf r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// slw r17,r28,r11
	r17.u64 = r11.u8 & 0x20 ? 0 : (r28.u32 << (r11.u8 & 0x3F));
	// b 0x82410060
	goto loc_82410060;
loc_8241005C:
	// mr r17,r28
	r17.u64 = r28.u64;
loc_82410060:
	// cmplwi cr6,r26,16
	cr6.compare<uint32_t>(r26.u32, 16, xer);
	// ble cr6,0x82410070
	if (!cr6.gt) goto loc_82410070;
	// cmplwi cr6,r20,16
	cr6.compare<uint32_t>(r20.u32, 16, xer);
	// bgt cr6,0x82410080
	if (cr6.gt) goto loc_82410080;
loc_82410070:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mr r30,r28
	r30.u64 = r28.u64;
	// rlwinm. r11,r11,0,20,20
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x800;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82410084
	if (!cr0.eq) goto loc_82410084;
loc_82410080:
	// li r30,0
	r30.s64 = 0;
loc_82410084:
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x8241009c
	if (cr6.eq) goto loc_8241009C;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x8241009c
	if (!cr6.eq) goto loc_8241009C;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// b 0x824100a0
	goto loc_824100A0;
loc_8241009C:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
loc_824100A0:
	// rlwinm r15,r11,0,0,19
	r15.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// bne cr6,0x82410188
	if (!cr6.eq) goto loc_82410188;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x82410188
	if (!cr6.eq) goto loc_82410188;
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// mr r6,r16
	ctx.r6.u64 = r16.u64;
	// stw r14,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r14.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r29,48(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r3,r1,108
	ctx.r3.s64 = ctx.r1.s64 + 108;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// rlwinm r27,r29,23,30,31
	r27.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 23) & 0x3;
	// clrlwi r28,r30,26
	r28.u64 = r30.u32 & 0x3F;
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// bl 0x8240f3c8
	ctx.lr = 0x824100F4;
	sub_8240F3C8(ctx, base);
	// lwz r26,28(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// rlwinm. r11,r26,0,0,0
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82410158
	if (!cr0.eq) goto loc_82410158;
	// rlwinm. r11,r30,0,21,21
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x400;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82410158
	if (!cr0.eq) goto loc_82410158;
	// rlwinm. r11,r29,0,20,20
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x800;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82410158
	if (!cr0.eq) goto loc_82410158;
	// cmplwi cr6,r27,1
	cr6.compare<uint32_t>(r27.u32, 1, xer);
	// bne cr6,0x82410158
	if (!cr6.eq) goto loc_82410158;
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// rlwinm. r11,r11,0,22,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x3C0;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82410158
	if (!cr0.eq) goto loc_82410158;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm. r11,r11,0,0,0
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82410158
	if (!cr0.eq) goto loc_82410158;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8240f2a8
	ctx.lr = 0x82410140;
	sub_8240F2A8(ctx, base);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// add r10,r11,r14
	ctx.r10.u64 = r11.u64 + r14.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// andc r20,r10,r11
	r20.u64 = ctx.r10.u64 & ~r11.u64;
	// b 0x8241015c
	goto loc_8241015C;
loc_82410158:
	// lwz r20,100(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
loc_8241015C:
	// lwz r17,96(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x82410178
	if (!cr6.eq) goto loc_82410178;
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// mullw r11,r11,r16
	r11.s64 = int64_t(r11.s32) * int64_t(r16.s32);
	// rlwinm r30,r11,29,3,31
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFF;
	// b 0x82410398
	goto loc_82410398;
loc_82410178:
	// rlwinm r11,r26,10,23,31
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 10) & 0x1FF;
	// mullw r11,r11,r16
	r11.s64 = int64_t(r11.s32) * int64_t(r16.s32);
	// rlwinm r30,r11,2,3,29
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x1FFFFFFC;
	// b 0x82410398
	goto loc_82410398;
loc_82410188:
	// srw r10,r9,r24
	ctx.r10.u64 = r24.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (r24.u8 & 0x3F));
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bgt cr6,0x82410198
	if (cr6.gt) goto loc_82410198;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
loc_82410198:
	// srw r11,r8,r24
	r11.u64 = r24.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (r24.u8 & 0x3F));
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + r29.u64;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// bgt cr6,0x824101b0
	if (cr6.gt) goto loc_824101B0;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824101B0:
	// add r14,r11,r29
	r14.u64 = r11.u64 + r29.u64;
	// cmplwi cr6,r25,2
	cr6.compare<uint32_t>(r25.u32, 2, xer);
	// bne cr6,0x824101e0
	if (!cr6.eq) goto loc_824101E0;
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// srw r11,r11,r24
	r11.u64 = r24.u8 & 0x20 ? 0 : (r11.u32 >> (r24.u8 & 0x3F));
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bgt cr6,0x824101d4
	if (cr6.gt) goto loc_824101D4;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_824101D4:
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// b 0x824101e4
	goto loc_824101E4;
loc_824101E0:
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r28.u32);
loc_824101E4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82421a18
	ctx.lr = 0x824101EC;
	sub_82421A18(ctx, base);
	// cmpwi cr6,r3,18
	cr6.compare<int32_t>(ctx.r3.s32, 18, xer);
	// beq cr6,0x82410204
	if (cr6.eq) goto loc_82410204;
	// cmpwi cr6,r3,19
	cr6.compare<int32_t>(ctx.r3.s32, 19, xer);
	// beq cr6,0x82410204
	if (cr6.eq) goto loc_82410204;
	// mr r18,r28
	r18.u64 = r28.u64;
	// b 0x82410224
	goto loc_82410224;
loc_82410204:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// rlwinm r11,r11,23,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 23) & 0x2;
	// rlwinm r10,r10,6,26,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0x3F;
	// slw r11,r28,r11
	r11.u64 = r11.u8 & 0x20 ? 0 : (r28.u32 << (r11.u8 & 0x3F));
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// andc r18,r10,r11
	r18.u64 = ctx.r10.u64 & ~r11.u64;
loc_82410224:
	// cntlzw r11,r26
	r11.u64 = r26.u32 == 0 ? 32 : __builtin_clz(r26.u32);
	// cntlzw r10,r20
	ctx.r10.u64 = r20.u32 == 0 ? 32 : __builtin_clz(r20.u32);
	// cntlzw r9,r17
	ctx.r9.u64 = r17.u32 == 0 ? 32 : __builtin_clz(r17.u32);
	// subfic r25,r11,31
	xer.ca = r11.u32 <= 31;
	r25.s64 = 31 - r11.s64;
	// subfic r26,r10,31
	xer.ca = ctx.r10.u32 <= 31;
	r26.s64 = 31 - ctx.r10.s64;
	// subfic r27,r9,31
	xer.ca = ctx.r9.u32 <= 31;
	r27.s64 = 31 - ctx.r9.s64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x82410258
	if (cr6.eq) goto loc_82410258;
	// mr r21,r24
	r21.u64 = r24.u64;
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// b 0x8241025c
	goto loc_8241025C;
loc_82410258:
	// addi r21,r24,-1
	r21.s64 = r24.s64 + -1;
loc_8241025C:
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// blt cr6,0x82410394
	if (cr6.lt) goto loc_82410394;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r19,48(r31)
	r19.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// rlwinm r22,r11,1,31,31
	r22.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// clrlwi r24,r10,26
	r24.u64 = ctx.r10.u32 & 0x3F;
	// rlwinm r23,r19,23,30,31
	r23.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 23) & 0x3;
loc_8241027C:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82410288
	if (cr6.eq) goto loc_82410288;
	// addi r25,r25,-1
	r25.s64 = r25.s64 + -1;
loc_82410288:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82410294
	if (cr6.eq) goto loc_82410294;
	// addi r26,r26,-1
	r26.s64 = r26.s64 + -1;
loc_82410294:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824102a0
	if (cr6.eq) goto loc_824102A0;
	// addi r27,r27,-1
	r27.s64 = r27.s64 + -1;
loc_824102A0:
	// slw r11,r28,r27
	r11.u64 = r27.u8 & 0x20 ? 0 : (r28.u32 << (r27.u8 & 0x3F));
	// slw r30,r28,r25
	r30.u64 = r25.u8 & 0x20 ? 0 : (r28.u32 << (r25.u8 & 0x3F));
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// slw r29,r28,r26
	r29.u64 = r26.u8 & 0x20 ? 0 : (r28.u32 << (r26.u8 & 0x3F));
	// stw r30,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r30.u32);
	// stw r29,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r29.u32);
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// mr r8,r23
	ctx.r8.u64 = r23.u64;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r6,r16
	ctx.r6.u64 = r16.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// addi r3,r1,108
	ctx.r3.s64 = ctx.r1.s64 + 108;
	// bl 0x8240f3c8
	ctx.lr = 0x824102D8;
	sub_8240F3C8(ctx, base);
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// cmplwi cr6,r30,16
	cr6.compare<uint32_t>(r30.u32, 16, xer);
	// mullw r11,r11,r16
	r11.s64 = int64_t(r11.s32) * int64_t(r16.s32);
	// rlwinm r30,r11,29,3,31
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFF;
	// ble cr6,0x824102f4
	if (!cr6.gt) goto loc_824102F4;
	// cmplwi cr6,r29,16
	cr6.compare<uint32_t>(r29.u32, 16, xer);
	// bgt cr6,0x824102fc
	if (cr6.gt) goto loc_824102FC;
loc_824102F4:
	// rlwinm. r11,r19,0,20,20
	r11.u64 = __builtin_rotateleft64(r19.u32 | (r19.u64 << 32), 0) & 0x800;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241034c
	if (!cr0.eq) goto loc_8241034C;
loc_824102FC:
	// lwz r20,100(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// lwz r17,96(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// ble cr6,0x82410340
	if (!cr6.gt) goto loc_82410340;
	// cmplwi cr6,r23,2
	cr6.compare<uint32_t>(r23.u32, 2, xer);
	// beq cr6,0x82410328
	if (cr6.eq) goto loc_82410328;
	// mullw r11,r30,r20
	r11.s64 = int64_t(r30.s32) * int64_t(r20.s32);
	// addi r11,r11,4095
	r11.s64 = r11.s64 + 4095;
	// rlwinm r11,r11,0,0,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	// mullw r11,r11,r17
	r11.s64 = int64_t(r11.s32) * int64_t(r17.s32);
	// b 0x82410338
	goto loc_82410338;
loc_82410328:
	// mullw r11,r30,r17
	r11.s64 = int64_t(r30.s32) * int64_t(r17.s32);
	// mullw r11,r11,r20
	r11.s64 = int64_t(r11.s32) * int64_t(r20.s32);
	// addi r11,r11,4095
	r11.s64 = r11.s64 + 4095;
	// rlwinm r11,r11,0,0,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
loc_82410338:
	// mullw r11,r11,r18
	r11.s64 = int64_t(r11.s32) * int64_t(r18.s32);
	// add r15,r11,r15
	r15.u64 = r11.u64 + r15.u64;
loc_82410340:
	// addic. r21,r21,-1
	xer.ca = r21.u32 > 0;
	r21.s64 = r21.s64 + -1;
	cr0.compare<int32_t>(r21.s32, 0, xer);
	// bge 0x8241027c
	if (!cr0.lt) goto loc_8241027C;
	// b 0x82410398
	goto loc_82410398;
loc_8241034C:
	// addi r11,r1,120
	r11.s64 = ctx.r1.s64 + 120;
	// lwz r20,100(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r9,r1,116
	ctx.r9.s64 = ctx.r1.s64 + 116;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// addi r10,r1,108
	ctx.r10.s64 = ctx.r1.s64 + 108;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// mullw r8,r30,r20
	ctx.r8.s64 = int64_t(r30.s32) * int64_t(r20.s32);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// slw r6,r28,r27
	ctx.r6.u64 = r27.u8 & 0x20 ? 0 : (r28.u32 << (r27.u8 & 0x3F));
	// slw r5,r28,r26
	ctx.r5.u64 = r26.u8 & 0x20 ? 0 : (r28.u32 << (r26.u8 & 0x3F));
	// slw r4,r28,r25
	ctx.r4.u64 = r25.u8 & 0x20 ? 0 : (r28.u32 << (r25.u8 & 0x3F));
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8240f858
	ctx.lr = 0x82410384;
	sub_8240F858(ctx, base);
	// lwz r17,96(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// add r15,r15,r3
	r15.u64 = r15.u64 + ctx.r3.u64;
	// b 0x82410398
	goto loc_82410398;
loc_82410394:
	// lwz r30,120(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
loc_82410398:
	// mullw r11,r30,r20
	r11.s64 = int64_t(r30.s32) * int64_t(r20.s32);
	// lwz r9,316(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 316);
	// lwz r8,388(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// lwz r7,332(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
	// addi r10,r11,4095
	ctx.r10.s64 = r11.s64 + 4095;
	// rlwinm r6,r10,0,0,19
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFF000;
	// mullw r9,r6,r9
	ctx.r9.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r9.s32);
	// add r9,r9,r15
	ctx.r9.u64 = ctx.r9.u64 + r15.u64;
	// stw r9,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r9.u32);
	// stw r30,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r30.u32);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// rlwinm r9,r9,0,21,22
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x600;
	// cmplwi cr6,r9,1024
	cr6.compare<uint32_t>(ctx.r9.u32, 1024, xer);
	// beq cr6,0x824103ec
	if (cr6.eq) goto loc_824103EC;
	// lwz r11,340(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	// rlwinm r10,r10,0,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFF000;
	// lwz r9,348(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 348);
	// mullw r8,r10,r17
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r17.s32);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// b 0x82410408
	goto loc_82410408;
loc_824103EC:
	// lwz r9,340(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 340);
	// mullw r10,r11,r17
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(r17.s32);
	// lwz r8,348(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 348);
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// addi r11,r10,4095
	r11.s64 = ctx.r10.s64 + 4095;
	// rlwinm r11,r11,0,0,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
loc_82410408:
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r10,364(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 364);
	// lwz r9,372(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// lwz r8,380(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 380);
	// lwz r7,104(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r6,116(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r5,356(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 356);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// stw r14,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r14.u32);
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// stw r6,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r6.u32);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8241043C"))) PPC_WEAK_FUNC(sub_8241043C);
PPC_FUNC_IMPL(__imp__sub_8241043C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82410440"))) PPC_WEAK_FUNC(sub_82410440);
PPC_FUNC_IMPL(__imp__sub_82410440) {
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
	ctx.lr = 0x82410448;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lwz r31,276(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// addi r10,r1,120
	ctx.r10.s64 = ctx.r1.s64 + 120;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r11,r1,116
	r11.s64 = ctx.r1.s64 + 116;
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r10,r1,124
	ctx.r10.s64 = ctx.r1.s64 + 124;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x8240ff78
	ctx.lr = 0x8241049C;
	sub_8240FF78(ctx, base);
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// addi r5,r1,116
	ctx.r5.s64 = ctx.r1.s64 + 116;
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// clrlwi r3,r11,26
	ctx.r3.u64 = r11.u32 & 0x3F;
	// bl 0x8240f2a8
	ctx.lr = 0x824104B0;
	sub_8240F2A8(ctx, base);
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// lwz r9,116(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lis r10,512
	ctx.r10.s64 = 33554432;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// stw r27,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r27.u32);
	// stw r11,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r11.u32);
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lwz r8,48(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// subf r9,r3,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r3.s64;
	// li r5,14
	ctx.r5.s64 = 14;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// rlwinm r8,r8,0,0,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFF000;
	// rlwinm r7,r11,0,0,19
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82421ca0
	ctx.lr = 0x82410500;
	sub_82421CA0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82410514"))) PPC_WEAK_FUNC(sub_82410514);
PPC_FUNC_IMPL(__imp__sub_82410514) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82410518"))) PPC_WEAK_FUNC(sub_82410518);
PPC_FUNC_IMPL(__imp__sub_82410518) {
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
	ctx.lr = 0x82410520;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// addi r11,r1,104
	r11.s64 = ctx.r1.s64 + 104;
	// addi r10,r1,108
	ctx.r10.s64 = ctx.r1.s64 + 108;
	// addi r9,r1,100
	ctx.r9.s64 = ctx.r1.s64 + 100;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82410440
	ctx.lr = 0x8241054C;
	sub_82410440(ctx, base);
	// lwz r9,100(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82410594
	if (cr6.eq) goto loc_82410594;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,6712
	r11.s64 = r11.s64 + 6712;
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r10,r10,1,25,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x7E;
	// lwz r6,96(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// mullw r11,r7,r9
	r11.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// lbzx r10,r10,r5
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r5.u32);
	// mullw r10,r10,r8
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r8.s32);
	// rlwinm r10,r10,29,3,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// add r11,r11,r6
	r11.u64 = r11.u64 + ctx.r6.u64;
	// b 0x82410598
	goto loc_82410598;
loc_82410594:
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
loc_82410598:
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824105A8"))) PPC_WEAK_FUNC(sub_824105A8);
PPC_FUNC_IMPL(__imp__sub_824105A8) {
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
	ctx.lr = 0x824105B0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// addi r11,r1,108
	r11.s64 = ctx.r1.s64 + 108;
	// addi r10,r1,100
	ctx.r10.s64 = ctx.r1.s64 + 100;
	// addi r9,r1,104
	ctx.r9.s64 = ctx.r1.s64 + 104;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82410440
	ctx.lr = 0x824105E4;
	sub_82410440(ctx, base);
	// lwz r8,100(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r7,104(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8241063c
	if (cr6.eq) goto loc_8241063C;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,6712
	r11.s64 = r11.s64 + 6712;
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r10,r10,1,25,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x7E;
	// lwz r5,16(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mullw r11,r6,r7
	r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r7.s32);
	// lbzx r10,r10,r4
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// rlwinm r9,r10,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// mullw r10,r5,r8
	ctx.r10.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r8.s32);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// b 0x82410640
	goto loc_82410640;
loc_8241063C:
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
loc_82410640:
	// stw r7,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r7.u32);
	// stw r8,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r8.u32);
	// stw r11,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82410654"))) PPC_WEAK_FUNC(sub_82410654);
PPC_FUNC_IMPL(__imp__sub_82410654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82410658"))) PPC_WEAK_FUNC(sub_82410658);
PPC_FUNC_IMPL(__imp__sub_82410658) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c8
	ctx.lr = 0x82410660;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r20,372(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// rlwinm r11,r20,1,0,30
	r11.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r22,r7
	r22.u64 = ctx.r7.u64;
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// mr r31,r9
	r31.u64 = ctx.r9.u64;
	// mr r26,r10
	r26.u64 = ctx.r10.u64;
	// cmpwi cr6,r19,3
	cr6.compare<int32_t>(r19.s32, 3, xer);
	// addi r25,r11,1
	r25.s64 = r11.s64 + 1;
	// beq cr6,0x82410708
	if (cr6.eq) goto loc_82410708;
	// cmpwi cr6,r19,17
	cr6.compare<int32_t>(r19.s32, 17, xer);
	// beq cr6,0x824106cc
	if (cr6.eq) goto loc_824106CC;
	// cmpwi cr6,r19,18
	cr6.compare<int32_t>(r19.s32, 18, xer);
	// beq cr6,0x824106c4
	if (cr6.eq) goto loc_824106C4;
	// cmpwi cr6,r19,19
	cr6.compare<int32_t>(r19.s32, 19, xer);
	// beq cr6,0x82410708
	if (cr6.eq) goto loc_82410708;
	// cmpwi cr6,r19,20
	cr6.compare<int32_t>(r19.s32, 20, xer);
	// bne cr6,0x82410710
	if (!cr6.eq) goto loc_82410710;
	// li r30,0
	r30.s64 = 0;
	// li r26,0
	r26.s64 = 0;
	// b 0x8241071c
	goto loc_8241071C;
loc_824106C4:
	// li r30,3
	r30.s64 = 3;
	// b 0x8241071c
	goto loc_8241071C;
loc_824106CC:
	// li r30,2
	r30.s64 = 2;
loc_824106D0:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
loc_824106D4:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// bne cr6,0x824106f0
	if (!cr6.eq) goto loc_824106F0;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8240f340
	ctx.lr = 0x824106EC;
	sub_8240F340(ctx, base);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
loc_824106F0:
	// cmpwi cr6,r26,2
	cr6.compare<int32_t>(r26.s32, 2, xer);
	// bne cr6,0x82410724
	if (!cr6.eq) goto loc_82410724;
	// subfic r11,r22,1
	xer.ca = r22.u32 <= 1;
	r11.s64 = 1 - r22.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r23,r11,31
	r23.u64 = r11.u32 & 0x1;
	// b 0x82410728
	goto loc_82410728;
loc_82410708:
	// li r30,1
	r30.s64 = 1;
	// b 0x82410714
	goto loc_82410714;
loc_82410710:
	// lwz r30,136(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
loc_82410714:
	// cmpwi cr6,r19,17
	cr6.compare<int32_t>(r19.s32, 17, xer);
	// beq cr6,0x824106d0
	if (cr6.eq) goto loc_824106D0;
loc_8241071C:
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x824106d4
	goto loc_824106D4;
loc_82410724:
	// mr r23,r26
	r23.u64 = r26.u64;
loc_82410728:
	// lwz r11,388(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// addi r10,r1,136
	ctx.r10.s64 = ctx.r1.s64 + 136;
	// lwz r21,380(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 380);
	// addi r9,r1,132
	ctx.r9.s64 = ctx.r1.s64 + 132;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stw r10,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
	// clrlwi r26,r31,26
	r26.u64 = r31.u32 & 0x3F;
	// stw r9,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// mr r10,r23
	ctx.r10.u64 = r23.u64;
	// rlwinm r9,r31,24,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 24) & 0x1;
	// stw r20,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r20.u32);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// stw r21,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r21.u32);
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8240f4e8
	ctx.lr = 0x8241077C;
	sub_8240F4E8(ctx, base);
	// lis r9,16
	ctx.r9.s64 = 1048576;
	// rlwinm. r11,r24,0,29,29
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ori r9,r9,3
	ctx.r9.u64 = ctx.r9.u64 | 3;
	// beq 0x82410794
	if (cr0.eq) goto loc_82410794;
	// lis r9,48
	ctx.r9.s64 = 3145728;
	// ori r9,r9,3
	ctx.r9.u64 = ctx.r9.u64 | 3;
loc_82410794:
	// rlwinm. r11,r24,0,22,22
	r11.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 0) & 0x200;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x824107a0
	if (cr0.eq) goto loc_824107A0;
	// oris r9,r9,64
	ctx.r9.u64 = ctx.r9.u64 | 4194304;
loc_824107A0:
	// lwz r11,396(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
	// lis r10,-1
	ctx.r10.s64 = -65536;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmplwi cr6,r30,1
	cr6.compare<uint32_t>(r30.u32, 1, xer);
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// rlwimi r10,r30,9,21,22
	ctx.r10.u64 = (__builtin_rotateleft32(r30.u32, 9) & 0x600) | (ctx.r10.u64 & 0xFFFFFFFFFFFFF9FF);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// stw r7,24(r11)
	PPC_STORE_U32(r11.u32 + 24, ctx.r7.u32);
	// stw r6,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r6.u32);
	// stw r10,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r10.u32);
	// blt cr6,0x8241086c
	if (cr6.lt) goto loc_8241086C;
	// beq cr6,0x82410834
	if (cr6.eq) goto loc_82410834;
	// cmplwi cr6,r30,3
	cr6.compare<uint32_t>(r30.u32, 3, xer);
	// blt cr6,0x82410804
	if (cr6.lt) goto loc_82410804;
	// bne cr6,0x8241087c
	if (!cr6.eq) goto loc_8241087C;
	// subf r9,r25,r28
	ctx.r9.s64 = r28.s64 - r25.s64;
	// subf r8,r25,r29
	ctx.r8.s64 = r29.s64 - r25.s64;
	// addi r7,r27,-1
	ctx.r7.s64 = r27.s64 + -1;
	// rlwimi r8,r9,13,6,18
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 13) & 0x3FFE000) | (ctx.r8.u64 & 0xFFFFFFFFFC001FFF);
	// rlwimi r8,r7,26,0,5
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 26) & 0xFC000000) | (ctx.r8.u64 & 0xFFFFFFFF03FFFFFF);
	// b 0x82410878
	goto loc_82410878;
loc_82410804:
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// subf r8,r25,r29
	ctx.r8.s64 = r29.s64 - r25.s64;
	// subf r7,r25,r28
	ctx.r7.s64 = r28.s64 - r25.s64;
	// rlwimi r8,r9,0,0,20
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0xFFFFF800) | (ctx.r8.u64 & 0xFFFFFFFF000007FF);
	// subf r6,r25,r27
	ctx.r6.s64 = r27.s64 - r25.s64;
	// rlwinm r9,r7,11,10,20
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 11) & 0x3FF800;
	// stw r8,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r8.u32);
	// rlwinm r7,r6,22,0,9
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 22) & 0xFFC00000;
	// rotlwi r8,r8,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// or r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 | ctx.r7.u64;
	// clrlwi r8,r8,21
	ctx.r8.u64 = ctx.r8.u32 & 0x7FF;
	// b 0x82410860
	goto loc_82410860;
loc_82410834:
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// subf r8,r25,r29
	ctx.r8.s64 = r29.s64 - r25.s64;
	// subf r7,r25,r28
	ctx.r7.s64 = r28.s64 - r25.s64;
	// rlwimi r8,r9,0,0,18
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0xFFFFE000) | (ctx.r8.u64 & 0xFFFFFFFF00001FFF);
	// addi r9,r27,-1
	ctx.r9.s64 = r27.s64 + -1;
	// stw r8,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r8.u32);
	// rlwinm r8,r7,13,6,18
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 13) & 0x3FFE000;
	// rlwinm r9,r9,26,0,5
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 26) & 0xFC000000;
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// clrlwi r8,r8,19
	ctx.r8.u64 = ctx.r8.u32 & 0x1FFF;
loc_82410860:
	// or r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r9,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r9.u32);
	// b 0x8241087c
	goto loc_8241087C;
loc_8241086C:
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// subf r8,r25,r29
	ctx.r8.s64 = r29.s64 - r25.s64;
	// rlwimi r8,r9,0,0,7
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r9.u32, 0) & 0xFF000000) | (ctx.r8.u64 & 0xFFFFFFFF00FFFFFF);
loc_82410878:
	// stw r8,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r8.u32);
loc_8241087C:
	// srawi r9,r31,15
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x7FFF) != 0);
	ctx.r9.s64 = r31.s32 >> 15;
	// lwz r8,128(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// srawi r7,r31,13
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x1FFF) != 0);
	ctx.r7.s64 = r31.s32 >> 13;
	// lwz r6,28(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// srawi r5,r31,11
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x7FF) != 0);
	ctx.r5.s64 = r31.s32 >> 11;
	// lwz r4,32(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// srawi r3,r31,9
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x1FF) != 0);
	ctx.r3.s64 = r31.s32 >> 9;
	// lwz r30,40(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// srawi r29,r31,8
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0xFF) != 0);
	r29.s64 = r31.s32 >> 8;
	// lwz r28,44(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// srawi r27,r31,6
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x3F) != 0);
	r27.s64 = r31.s32 >> 6;
	// lwz r25,404(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 404);
	// srawi r24,r31,27
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x7FFFFFF) != 0);
	r24.s64 = r31.s32 >> 27;
	// lwz r18,132(r1)
	r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// rlwinm r20,r20,21,0,10
	r20.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 21) & 0xFFE00000;
	// lwz r17,412(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 412);
	// clrlwi r24,r24,29
	r24.u64 = r24.u32 & 0x7;
	// lwz r16,136(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// rlwimi r7,r9,2,28,29
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r9.u32, 2) & 0xC) | (ctx.r7.u64 & 0xFFFFFFFFFFFFFFF3);
	// or r24,r24,r20
	r24.u64 = r24.u64 | r20.u64;
	// addi r9,r19,-19
	ctx.r9.s64 = r19.s64 + -19;
	// rlwimi r8,r29,14,0,17
	ctx.r8.u64 = (__builtin_rotateleft32(r29.u32, 14) & 0xFFFFC000) | (ctx.r8.u64 & 0xFFFFFFFF00003FFF);
	// clrlwi r7,r7,28
	ctx.r7.u64 = ctx.r7.u32 & 0xF;
	// cntlzw r9,r9
	ctx.r9.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// srawi r20,r31,24
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0xFFFFFF) != 0);
	r20.s64 = r31.s32 >> 24;
	// rlwimi r24,r21,3,23,28
	r24.u64 = (__builtin_rotateleft32(r21.u32, 3) & 0x1F8) | (r24.u64 & 0xFFFFFFFFFFFFFE07);
	// rlwimi r5,r7,2,0,29
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r7.u32, 2) & 0xFFFFFFFC) | (ctx.r5.u64 & 0xFFFFFFFF00000003);
	// rlwimi r6,r8,17,0,9
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r8.u32, 17) & 0xFFC00000) | (ctx.r6.u64 & 0xFFFFFFFF003FFFFF);
	// rlwinm r9,r9,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// srawi r29,r31,21
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x1FFFFF) != 0);
	r29.s64 = r31.s32 >> 21;
	// rlwimi r20,r24,3,0,28
	r20.u64 = (__builtin_rotateleft32(r24.u32, 3) & 0xFFFFFFF8) | (r20.u64 & 0xFFFFFFFF00000007);
	// rlwimi r27,r9,4,27,27
	r27.u64 = (__builtin_rotateleft32(ctx.r9.u32, 4) & 0x10) | (r27.u64 & 0xFFFFFFFFFFFFFFEF);
	// rlwimi r3,r5,2,0,29
	ctx.r3.u64 = (__builtin_rotateleft32(ctx.r5.u32, 2) & 0xFFFFFFFC) | (ctx.r3.u64 & 0xFFFFFFFF00000003);
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// srawi r8,r31,18
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x3FFFF) != 0);
	ctx.r8.s64 = r31.s32 >> 18;
	// rlwimi r29,r20,3,0,28
	r29.u64 = (__builtin_rotateleft32(r20.u32, 3) & 0xFFFFFFF8) | (r29.u64 & 0xFFFFFFFF00000007);
	// rlwinm r9,r4,0,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFC0;
	// rlwimi r8,r29,3,0,28
	ctx.r8.u64 = (__builtin_rotateleft32(r29.u32, 3) & 0xFFFFFFF8) | (ctx.r8.u64 & 0xFFFFFFFF00000007);
	// rlwinm r6,r3,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r7,0,0,21
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFC00;
	// srawi r5,r31,17
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x1FFFF) != 0);
	ctx.r5.s64 = r31.s32 >> 17;
	// or r9,r9,r26
	ctx.r9.u64 = ctx.r9.u64 | r26.u64;
	// or r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 | ctx.r7.u64;
	// rlwimi r5,r8,1,0,30
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r8.u32, 1) & 0xFFFFFFFE) | (ctx.r5.u64 & 0xFFFFFFFF00000001);
	// addi r6,r22,-1
	ctx.r6.s64 = r22.s64 + -1;
	// rlwimi r9,r27,6,24,25
	ctx.r9.u64 = (__builtin_rotateleft32(r27.u32, 6) & 0xC0) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFF3F);
	// rlwinm r8,r30,0,1,12
	ctx.r8.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x7FF80000;
	// ori r7,r7,2
	ctx.r7.u64 = ctx.r7.u64 | 2;
	// rlwimi r28,r6,6,22,25
	r28.u64 = (__builtin_rotateleft32(ctx.r6.u32, 6) & 0x3C0) | (r28.u64 & 0xFFFFFFFFFFFFFC3F);
	// rlwimi r9,r27,6,21,21
	ctx.r9.u64 = (__builtin_rotateleft32(r27.u32, 6) & 0x400) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFBFF);
	// stw r7,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r7.u32);
	// rlwimi r10,r23,11,20,20
	ctx.r10.u64 = (__builtin_rotateleft32(r23.u32, 11) & 0x800) | (ctx.r10.u64 & 0xFFFFFFFFFFFFF7FF);
	// stw r28,44(r11)
	PPC_STORE_U32(r11.u32 + 44, r28.u32);
	// or r8,r5,r8
	ctx.r8.u64 = ctx.r5.u64 | ctx.r8.u64;
	// stw r9,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r9.u32);
	// stw r10,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r10.u32);
	// stw r8,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r8.u32);
	// stw r18,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r18.u32);
	// stw r16,0(r17)
	PPC_STORE_U32(r17.u32 + 0, r16.u32);
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_82410970"))) PPC_WEAK_FUNC(sub_82410970);
PPC_FUNC_IMPL(__imp__sub_82410970) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82410978;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// clrlwi r25,r28,26
	r25.u64 = r28.u32 & 0x3F;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// mr r21,r9
	r21.u64 = ctx.r9.u64;
	// mr r20,r10
	r20.u64 = ctx.r10.u64;
	// li r22,1
	r22.s64 = 1;
	// cmplwi cr6,r25,22
	cr6.compare<uint32_t>(r25.u32, 22, xer);
	// beq cr6,0x824109b8
	if (cr6.eq) goto loc_824109B8;
	// cmplwi cr6,r25,23
	cr6.compare<uint32_t>(r25.u32, 23, xer);
	// li r26,0
	r26.s64 = 0;
	// bne cr6,0x824109bc
	if (!cr6.eq) goto loc_824109BC;
loc_824109B8:
	// mr r26,r22
	r26.u64 = r22.u64;
loc_824109BC:
	// cmplwi cr6,r25,54
	cr6.compare<uint32_t>(r25.u32, 54, xer);
	// bne cr6,0x824109c8
	if (!cr6.eq) goto loc_824109C8;
	// li r25,7
	r25.s64 = 7;
loc_824109C8:
	// li r11,4
	r11.s64 = 4;
	// stw r22,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r22.u32);
	// lis r10,-1
	ctx.r10.s64 = -65536;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r24,-1
	r24.s64 = -1;
	// bl 0x8240f238
	ctx.lr = 0x824109F4;
	sub_8240F238(ctx, base);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// beq cr6,0x82410a38
	if (cr6.eq) goto loc_82410A38;
	// mr r11,r30
	r11.u64 = r30.u64;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// blt cr6,0x82410a10
	if (cr6.lt) goto loc_82410A10;
	// rlwinm r10,r27,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 1) & 0xFFFFFFFE;
loc_82410A10:
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// bne cr6,0x82410a1c
	if (!cr6.eq) goto loc_82410A1C;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
loc_82410A1C:
	// addi r11,r11,31
	r11.s64 = r11.s64 + 31;
	// addi r10,r10,15
	ctx.r10.s64 = ctx.r10.s64 + 15;
	// rlwinm r11,r11,27,5,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7FFFFFF;
	// rlwinm r10,r10,28,4,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// clrlwi r7,r11,9
	ctx.r7.u64 = r11.u32 & 0x7FFFFF;
	// b 0x82410a3c
	goto loc_82410A3C;
loc_82410A38:
	// li r7,0
	ctx.r7.s64 = 0;
loc_82410A3C:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x82410a54
	if (cr6.eq) goto loc_82410A54;
	// lwz r9,0(r23)
	ctx.r9.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// lwz r24,4(r23)
	r24.u64 = PPC_LOAD_U32(r23.u32 + 4);
	// lwz r8,8(r23)
	ctx.r8.u64 = PPC_LOAD_U32(r23.u32 + 8);
	// b 0x82410a78
	goto loc_82410A78;
loc_82410A54:
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// beq cr6,0x82410a78
	if (cr6.eq) goto loc_82410A78;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-9720(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9720);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82410a78
	if (!cr6.eq) goto loc_82410A78;
	// li r24,0
	r24.s64 = 0;
loc_82410A78:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x82410a88
	if (cr6.eq) goto loc_82410A88;
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// bne cr6,0x82410aa4
	if (!cr6.eq) goto loc_82410AA4;
loc_82410A88:
	// li r10,80
	ctx.r10.s64 = 80;
	// addi r11,r30,79
	r11.s64 = r30.s64 + 79;
	// divwu r11,r11,r10
	r11.u32 = r11.u32 / ctx.r10.u32;
	// mulli r10,r11,80
	ctx.r10.s64 = r11.s64 * 80;
	// addi r11,r30,31
	r11.s64 = r30.s64 + 31;
	// rlwinm r11,r11,0,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFE0;
	// b 0x82410abc
	goto loc_82410ABC;
loc_82410AA4:
	// li r10,40
	ctx.r10.s64 = 40;
	// addi r11,r30,39
	r11.s64 = r30.s64 + 39;
	// divwu r11,r11,r10
	r11.u32 = r11.u32 / ctx.r10.u32;
	// mulli r10,r11,40
	ctx.r10.s64 = r11.s64 * 40;
	// addi r11,r30,15
	r11.s64 = r30.s64 + 15;
	// rlwinm r11,r11,0,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF0;
loc_82410ABC:
	// lwz r6,36(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r5,r30,-1
	ctx.r5.s64 = r30.s64 + -1;
	// rlwimi r29,r11,2,0,29
	r29.u64 = (__builtin_rotateleft32(r11.u32, 2) & 0xFFFFFFFC) | (r29.u64 & 0xFFFFFFFF00000003);
	// stw r28,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r28.u32);
	// rlwinm r11,r5,18,0,13
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 18) & 0xFFFC0000;
	// clrlwi r6,r6,29
	ctx.r6.u64 = ctx.r6.u32 & 0x7;
	// lis r5,-32250
	ctx.r5.s64 = -2113536000;
	// or r11,r11,r6
	r11.u64 = r11.u64 | ctx.r6.u64;
	// addi r6,r27,-1
	ctx.r6.s64 = r27.s64 + -1;
	// rlwinm r4,r29,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 16) & 0xFFFF0000;
	// clrlwi r10,r10,18
	ctx.r10.u64 = ctx.r10.u32 & 0x3FFF;
	// addi r5,r5,6712
	ctx.r5.s64 = ctx.r5.s64 + 6712;
	// rlwinm r30,r25,1,0,30
	r30.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwimi r11,r6,3,14,28
	r11.u64 = (__builtin_rotateleft32(ctx.r6.u32, 3) & 0x3FFF8) | (r11.u64 & 0xFFFFFFFFFFFC0007);
	// or r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 | ctx.r10.u64;
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// lhzx r11,r30,r5
	r11.u64 = PPC_LOAD_U16(r30.u32 + ctx.r5.u32);
	// rlwinm r11,r11,24,28,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xF;
	// beq cr6,0x82410b78
	if (cr6.eq) goto loc_82410B78;
	// rlwinm r11,r11,16,15,15
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x10000;
	// clrlwi r10,r9,20
	ctx.r10.u64 = ctx.r9.u32 & 0xFFF;
	// cmpwi cr6,r24,-1
	cr6.compare<int32_t>(r24.s32, -1, xer);
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// beq cr6,0x82410b6c
	if (cr6.eq) goto loc_82410B6C;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x82410b44
	if (cr6.eq) goto loc_82410B44;
	// lwz r11,12(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82410b44
	if (cr6.eq) goto loc_82410B44;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// b 0x82410b54
	goto loc_82410B54;
loc_82410B44:
	// addi r11,r25,-22
	r11.s64 = r25.s64 + -22;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	r11.u64 = r11.u64 ^ 1;
loc_82410B54:
	// clrlwi r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	// rlwinm r10,r24,13,0,18
	ctx.r10.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 13) & 0xFFFFE000;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// rlwimi r22,r11,4,0,27
	r22.u64 = (__builtin_rotateleft32(r11.u32, 4) & 0xFFFFFFF0) | (r22.u64 & 0xFFFFFFFF0000000F);
	// stw r22,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r22.u32);
	// b 0x82410bcc
	goto loc_82410BCC;
loc_82410B6C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// b 0x82410bcc
	goto loc_82410BCC;
loc_82410B78:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82410bb8
	if (!cr6.eq) goto loc_82410BB8;
	// rlwinm. r10,r28,0,14,14
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x20000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x82410bb8
	if (!cr0.eq) goto loc_82410BB8;
	// rlwinm r10,r28,0,21,22
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x600;
	// cmpwi cr6,r10,1536
	cr6.compare<int32_t>(ctx.r10.s32, 1536, xer);
	// bne cr6,0x82410bb8
	if (!cr6.eq) goto loc_82410BB8;
	// rlwinm r10,r28,0,19,20
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x1800;
	// cmpwi cr6,r10,6144
	cr6.compare<int32_t>(ctx.r10.s32, 6144, xer);
	// bne cr6,0x82410bb8
	if (!cr6.eq) goto loc_82410BB8;
	// rlwinm r10,r28,0,17,18
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x6000;
	// cmpwi cr6,r10,24576
	cr6.compare<int32_t>(ctx.r10.s32, 24576, xer);
	// bne cr6,0x82410bb8
	if (!cr6.eq) goto loc_82410BB8;
	// rlwinm. r10,r28,0,15,16
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0x18000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne 0x82410bb8
	if (!cr0.eq) goto loc_82410BB8;
	// mr r11,r22
	r11.u64 = r22.u64;
loc_82410BB8:
	// rlwimi r11,r8,4,22,27
	r11.u64 = (__builtin_rotateleft32(ctx.r8.u32, 4) & 0x3F0) | (r11.u64 & 0xFFFFFFFFFFFFFC0F);
	// clrlwi r10,r9,20
	ctx.r10.u64 = ctx.r9.u32 & 0xFFF;
	// rlwinm r11,r11,16,6,15
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF0000;
	// or r11,r11,r10
	r11.u64 = r11.u64 | ctx.r10.u64;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
loc_82410BCC:
	// mulli r11,r3,5120
	r11.s64 = ctx.r3.s64 * 5120;
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// stw r3,0(r21)
	PPC_STORE_U32(r21.u32 + 0, ctx.r3.u32);
	// stw r7,0(r20)
	PPC_STORE_U32(r20.u32 + 0, ctx.r7.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82410BE4"))) PPC_WEAK_FUNC(sub_82410BE4);
PPC_FUNC_IMPL(__imp__sub_82410BE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82410BE8"))) PPC_WEAK_FUNC(sub_82410BE8);
PPC_FUNC_IMPL(__imp__sub_82410BE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,44(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// rlwinm r11,r11,26,28,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0xF;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82410BF8"))) PPC_WEAK_FUNC(sub_82410BF8);
PPC_FUNC_IMPL(__imp__sub_82410BF8) {
	PPC_FUNC_PROLOGUE();
	// b 0x8240fd78
	sub_8240FD78(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82410BFC"))) PPC_WEAK_FUNC(sub_82410BFC);
PPC_FUNC_IMPL(__imp__sub_82410BFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82410C00"))) PPC_WEAK_FUNC(sub_82410C00);
PPC_FUNC_IMPL(__imp__sub_82410C00) {
	PPC_FUNC_PROLOGUE();
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82410518
	sub_82410518(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82410C1C"))) PPC_WEAK_FUNC(sub_82410C1C);
PPC_FUNC_IMPL(__imp__sub_82410C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82410C20"))) PPC_WEAK_FUNC(sub_82410C20);
PPC_FUNC_IMPL(__imp__sub_82410C20) {
	PPC_FUNC_PROLOGUE();
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82410518
	sub_82410518(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82410C3C"))) PPC_WEAK_FUNC(sub_82410C3C);
PPC_FUNC_IMPL(__imp__sub_82410C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82410C40"))) PPC_WEAK_FUNC(sub_82410C40);
PPC_FUNC_IMPL(__imp__sub_82410C40) {
	PPC_FUNC_PROLOGUE();
	// b 0x8240fe78
	sub_8240FE78(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82410C44"))) PPC_WEAK_FUNC(sub_82410C44);
PPC_FUNC_IMPL(__imp__sub_82410C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82410C48"))) PPC_WEAK_FUNC(sub_82410C48);
PPC_FUNC_IMPL(__imp__sub_82410C48) {
	PPC_FUNC_PROLOGUE();
	// b 0x824105a8
	sub_824105A8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82410C4C"))) PPC_WEAK_FUNC(sub_82410C4C);
PPC_FUNC_IMPL(__imp__sub_82410C4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82410C50"))) PPC_WEAK_FUNC(sub_82410C50);
PPC_FUNC_IMPL(__imp__sub_82410C50) {
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
	ctx.lr = 0x82410C58;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// lis r4,25728
	ctx.r4.s64 = 1686110208;
	// li r3,52
	ctx.r3.s64 = 52;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// mr r23,r10
	r23.u64 = ctx.r10.u64;
	// mr r22,r30
	r22.u64 = r30.u64;
	// bl 0x82130b50
	ctx.lr = 0x82410C8C;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x82410c9c
	if (!cr0.eq) goto loc_82410C9C;
loc_82410C94:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82410d68
	goto loc_82410D68;
loc_82410C9C:
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
	// addi r11,r1,132
	r11.s64 = ctx.r1.s64 + 132;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// stw r8,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82410658
	ctx.lr = 0x82410CE0;
	sub_82410658(ctx, base);
	// not r11,r29
	r11.u64 = ~r29.u64;
	// lwz r3,128(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// rlwinm r11,r11,30,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1;
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// rlwinm r11,r11,28,0,3
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0xF0000000;
	// oris r30,r11,35968
	r30.u64 = r11.u64 | 2357198848;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82130b50
	ctx.lr = 0x82410D00;
	sub_82130B50(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bne 0x82410d18
	if (!cr0.eq) goto loc_82410D18;
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82410D10:
	// bl 0x821310f8
	ctx.lr = 0x82410D14;
	sub_821310F8(ctx, base);
	// b 0x82410c94
	goto loc_82410C94;
loc_82410D18:
	// lwz r3,132(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82410d4c
	if (cr6.eq) goto loc_82410D4C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82130b50
	ctx.lr = 0x82410D2C;
	sub_82130B50(ctx, base);
	// mr. r22,r3
	r22.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// bne 0x82410d4c
	if (!cr0.eq) goto loc_82410D4C;
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821310f8
	ctx.lr = 0x82410D40;
	sub_821310F8(ctx, base);
	// lis r4,-20096
	ctx.r4.s64 = -1317011456;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// b 0x82410d10
	goto loc_82410D10;
loc_82410D4C:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// rlwimi r11,r29,0,0,19
	r11.u64 = (__builtin_rotateleft32(r29.u32, 0) & 0xFFFFF000) | (r11.u64 & 0xFFFFFFFF00000FFF);
	// rlwimi r22,r10,0,20,31
	r22.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFFF) | (r22.u64 & 0xFFFFFFFFFFFFF000);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// stw r22,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r22.u32);
loc_82410D68:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82410D70"))) PPC_WEAK_FUNC(sub_82410D70);
PPC_FUNC_IMPL(__imp__sub_82410D70) {
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
	ctx.lr = 0x82410D78;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lis r4,25728
	ctx.r4.s64 = 1686110208;
	// li r3,48
	ctx.r3.s64 = 48;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// bl 0x82130b50
	ctx.lr = 0x82410D9C;
	sub_82130B50(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x82410dac
	if (!cr0.eq) goto loc_82410DAC;
loc_82410DA4:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82410ea0
	goto loc_82410EA0;
loc_82410DAC:
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82410970
	ctx.lr = 0x82410DD0;
	sub_82410970(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// oris r11,r11,16
	r11.u64 = r11.u64 | 1048576;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bne cr6,0x82410e9c
	if (!cr6.eq) goto loc_82410E9C;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// clrlwi r11,r11,26
	r11.u64 = r11.u32 & 0x3F;
	// cmplwi cr6,r11,22
	cr6.compare<uint32_t>(r11.u32, 22, xer);
	// beq cr6,0x82410e00
	if (cr6.eq) goto loc_82410E00;
	// cmplwi cr6,r11,23
	cr6.compare<uint32_t>(r11.u32, 23, xer);
	// li r29,0
	r29.s64 = 0;
	// bne cr6,0x82410e04
	if (!cr6.eq) goto loc_82410E04;
loc_82410E00:
	// li r29,1
	r29.s64 = 1;
loc_82410E04:
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824252a8
	ctx.lr = 0x82410E14;
	sub_824252A8(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x82410e2c
	if (!cr0.eq) goto loc_82410E2C;
loc_82410E1C:
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821310f8
	ctx.lr = 0x82410E28;
	sub_821310F8(ctx, base);
	// b 0x82410da4
	goto loc_82410DA4;
loc_82410E2C:
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplwi cr6,r11,2048
	cr6.compare<uint32_t>(r11.u32, 2048, xer);
	// ble cr6,0x82410e48
	if (!cr6.gt) goto loc_82410E48;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82425258
	ctx.lr = 0x82410E44;
	sub_82425258(ctx, base);
	// b 0x82410e1c
	goto loc_82410E1C;
loc_82410E48:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// oris r11,r11,32768
	r11.u64 = r11.u64 | 2147483648;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// beq cr6,0x82410e90
	if (cr6.eq) goto loc_82410E90;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// rlwimi r3,r10,0,0,19
	ctx.r3.u64 = (__builtin_rotateleft32(ctx.r10.u32, 0) & 0xFFFFF000) | (ctx.r3.u64 & 0xFFFFFFFF00000FFF);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// lwz r10,-9720(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -9720);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82410e9c
	if (!cr6.eq) goto loc_82410E9C;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,-9720(r11)
	PPC_STORE_U32(r11.u32 + -9720, ctx.r10.u32);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// clrlwi r11,r11,15
	r11.u64 = r11.u32 & 0x1FFFF;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// b 0x82410e9c
	goto loc_82410E9C;
loc_82410E90:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// rlwimi r3,r11,0,0,19
	ctx.r3.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0xFFFFF000) | (ctx.r3.u64 & 0xFFFFFFFF00000FFF);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
loc_82410E9C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82410EA0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82410EA8"))) PPC_WEAK_FUNC(sub_82410EA8);
PPC_FUNC_IMPL(__imp__sub_82410EA8) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm. r11,r11,0,1,1
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82410ee0
	if (cr0.eq) goto loc_82410EE0;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// rlwinm r4,r11,4,28,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xF;
	// bl 0x8240fd78
	ctx.lr = 0x82410EDC;
	sub_8240FD78(ctx, base);
	// b 0x82410f24
	goto loc_82410F24;
loc_82410EE0:
	// lwz r10,40(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// li r11,0
	r11.s64 = 0;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r11,r11,14,18,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 14) & 0x3FFF;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// lwz r11,36(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r11,r11,29,17,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x7FFF;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// lhz r11,24(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 24);
	// clrlwi r11,r11,30
	r11.u64 = r11.u32 & 0x3;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82410F24:
	// li r11,4
	r11.s64 = 4;
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

__attribute__((alias("__imp__sub_82410F40"))) PPC_WEAK_FUNC(sub_82410F40);
PPC_FUNC_IMPL(__imp__sub_82410F40) {
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
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// rlwinm r4,r11,4,28,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xF;
	// bl 0x8240fe78
	ctx.lr = 0x82410F68;
	sub_8240FE78(ctx, base);
	// li r11,16
	r11.s64 = 16;
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

__attribute__((alias("__imp__sub_82410F84"))) PPC_WEAK_FUNC(sub_82410F84);
PPC_FUNC_IMPL(__imp__sub_82410F84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82410F88"))) PPC_WEAK_FUNC(sub_82410F88);
PPC_FUNC_IMPL(__imp__sub_82410F88) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82410F90;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r4,3136
	r11.s64 = ctx.r4.s64 + 3136;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// lwzx r28,r29,r31
	r28.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// beq cr6,0x8241108c
	if (cr6.eq) goto loc_8241108C;
	// lwz r27,48(r5)
	r27.u64 = PPC_LOAD_U32(ctx.r5.u32 + 48);
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// lwz r7,32(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 32);
	// rlwinm r9,r27,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 12) & 0xFFF;
	// lwz r26,44(r5)
	r26.u64 = PPC_LOAD_U32(ctx.r5.u32 + 44);
	// mulli r11,r11,24
	r11.s64 = r11.s64 * 24;
	// lwz r25,28(r5)
	r25.u64 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	// lwz r24,36(r5)
	r24.u64 = PPC_LOAD_U32(ctx.r5.u32 + 36);
	// lwz r23,40(r5)
	r23.u64 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	// rlwinm r10,r7,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 12) & 0xFFF;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// clrlwi r30,r7,3
	r30.u64 = ctx.r7.u32 & 0x1FFFFFFF;
	// rlwinm r8,r9,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// rlwinm r3,r10,0,19,19
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// lwz r22,0(r11)
	r22.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r9,r31,r4
	ctx.r9.u64 = r31.u64 + ctx.r4.u64;
	// lwz r4,16(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rlwinm r7,r27,0,3,22
	ctx.r7.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x1FFFFE00;
	// lwz r27,4(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// lwz r21,12(r11)
	r21.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwz r20,20(r11)
	r20.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// add r7,r8,r7
	ctx.r7.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r3,r3,r30
	ctx.r3.u64 = ctx.r3.u64 + r30.u64;
	// stw r24,8(r11)
	PPC_STORE_U32(r11.u32 + 8, r24.u32);
	// rlwimi r10,r4,0,30,21
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r4.u32, 0) & 0xFFFFFFFFFFFFFC03) | (ctx.r10.u64 & 0x3FC);
	// lbz r8,11950(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 11950);
	// rlwimi r25,r22,0,10,21
	r25.u64 = (__builtin_rotateleft32(r22.u32, 0) & 0x3FFC00) | (r25.u64 & 0xFFFFFFFFFFC003FF);
	// rlwimi r3,r27,0,20,20
	ctx.r3.u64 = (__builtin_rotateleft32(r27.u32, 0) & 0x800) | (ctx.r3.u64 & 0xFFFFFFFFFFFFF7FF);
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// rlwimi r23,r21,0,1,12
	r23.u64 = (__builtin_rotateleft32(r21.u32, 0) & 0x7FF80000) | (r23.u64 & 0xFFFFFFFF8007FFFF);
	// stw r25,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r25.u32);
	// rlwimi r7,r20,0,23,31
	ctx.r7.u64 = (__builtin_rotateleft32(r20.u32, 0) & 0x1FF) | (ctx.r7.u64 & 0xFFFFFFFFFFFFFE00);
	// stw r3,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r3.u32);
	// rlwinm r4,r26,30,28,31
	ctx.r4.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 30) & 0xF;
	// stw r23,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r23.u32);
	// stw r7,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r7.u32);
	// cmplw cr6,r4,r8
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r8.u32, xer);
	// ble cr6,0x82411058
	if (!cr6.gt) goto loc_82411058;
	// rotlwi r8,r26,0
	ctx.r8.u64 = __builtin_rotateleft32(r26.u32, 0);
	// rlwinm r8,r8,30,28,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0xF;
loc_82411058:
	// lwz r7,44(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 44);
	// rlwimi r10,r8,2,26,29
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r8.u32, 2) & 0x3C) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFC3);
	// lbz r9,11976(r9)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r9.u32 + 11976);
	// rlwinm r8,r7,26,28,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 26) & 0xF;
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// bge cr6,0x82411078
	if (!cr6.lt) goto loc_82411078;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
loc_82411078:
	// ld r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U64(r31.u32 + 24);
	// rlwimi r10,r9,6,22,25
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 6) & 0x3C0) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFC3F);
	// or r9,r8,r6
	ctx.r9.u64 = ctx.r8.u64 | ctx.r6.u64;
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// std r9,24(r31)
	PPC_STORE_U64(r31.u32 + 24, ctx.r9.u64);
loc_8241108C:
	// stwx r5,r29,r31
	PPC_STORE_U32(r29.u32 + r31.u32, ctx.r5.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824110fc
	if (cr6.eq) goto loc_824110FC;
	// lwz r11,10908(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10908);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824110ac
	if (cr6.eq) goto loc_824110AC;
	// stw r11,8(r28)
	PPC_STORE_U32(r28.u32 + 8, r11.u32);
	// b 0x824110fc
	goto loc_824110FC;
loc_824110AC:
	// lwz r11,10912(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10912);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// and. r11,r11,r10
	r11.u64 = r11.u64 & ctx.r10.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x824110fc
	if (cr0.eq) goto loc_824110FC;
	// lwz r11,13528(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13528);
	// lwz r3,13524(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 13524);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x824110d4
	if (cr6.lt) goto loc_824110D4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8241a630
	ctx.lr = 0x824110D4;
	sub_8241A630(ctx, base);
loc_824110D4:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r3,8
	ctx.r9.s64 = ctx.r3.s64 + 8;
	// rlwimi r11,r28,30,2,31
	r11.u64 = (__builtin_rotateleft32(r28.u32, 30) & 0x3FFFFFFF) | (r11.u64 & 0xFFFFFFFFC0000000);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// rlwinm r11,r11,0,2,0
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFBFFFFFFF;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, r11.u64);
	// stw r9,13524(r31)
	PPC_STORE_U32(r31.u32 + 13524, ctx.r9.u32);
loc_824110FC:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82411104"))) PPC_WEAK_FUNC(sub_82411104);
PPC_FUNC_IMPL(__imp__sub_82411104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82411108"))) PPC_WEAK_FUNC(sub_82411108);
PPC_FUNC_IMPL(__imp__sub_82411108) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,52(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r9,14928(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14928);
	// lwz r8,14924(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14924);
	// lwz r7,14916(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14916);
	// lwz r6,14920(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14920);
	// stw r11,13408(r3)
	PPC_STORE_U32(ctx.r3.u32 + 13408, r11.u32);
	// stw r10,13412(r3)
	PPC_STORE_U32(ctx.r3.u32 + 13412, ctx.r10.u32);
	// stw r9,13416(r3)
	PPC_STORE_U32(ctx.r3.u32 + 13416, ctx.r9.u32);
	// stw r8,13420(r3)
	PPC_STORE_U32(ctx.r3.u32 + 13420, ctx.r8.u32);
	// stw r7,13424(r3)
	PPC_STORE_U32(ctx.r3.u32 + 13424, ctx.r7.u32);
	// stw r6,13428(r3)
	PPC_STORE_U32(ctx.r3.u32 + 13428, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241113C"))) PPC_WEAK_FUNC(sub_8241113C);
PPC_FUNC_IMPL(__imp__sub_8241113C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82411140"))) PPC_WEAK_FUNC(sub_82411140);
PPC_FUNC_IMPL(__imp__sub_82411140) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,13412(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13412);
	// lwz r10,13408(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13408);
	// lwz r9,13416(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13416);
	// addi r8,r11,-160
	ctx.r8.s64 = r11.s64 + -160;
	// lwz r7,13420(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13420);
	// lwz r6,13424(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13424);
	// lwz r5,13428(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13428);
	// stw r10,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r10.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// stw r9,14928(r3)
	PPC_STORE_U32(ctx.r3.u32 + 14928, ctx.r9.u32);
	// stw r7,14924(r3)
	PPC_STORE_U32(ctx.r3.u32 + 14924, ctx.r7.u32);
	// stw r6,14916(r3)
	PPC_STORE_U32(ctx.r3.u32 + 14916, ctx.r6.u32);
	// stw r5,14920(r3)
	PPC_STORE_U32(ctx.r3.u32 + 14920, ctx.r5.u32);
	// stw r8,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241117C"))) PPC_WEAK_FUNC(sub_8241117C);
PPC_FUNC_IMPL(__imp__sub_8241117C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82411180"))) PPC_WEAK_FUNC(sub_82411180);
PPC_FUNC_IMPL(__imp__sub_82411180) {
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
	ctx.lr = 0x82411188;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,10896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r10,r11,r30
	ctx.r10.s64 = r30.s64 - r11.s64;
	// clrlwi. r10,r10,30
	ctx.r10.u64 = ctx.r10.u32 & 0x3;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82411210
	if (cr0.eq) goto loc_82411210;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x824111c0
	if (!cr6.eq) goto loc_824111C0;
	// rlwinm r11,r11,0,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// ble cr6,0x82411210
	if (!cr6.gt) goto loc_82411210;
loc_824111C0:
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82412ea0
	ctx.lr = 0x824111D0;
	sub_82412EA0(ctx, base);
loc_824111D0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82412f98
	ctx.lr = 0x824111D8;
	sub_82412F98(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x82411208
	if (cr0.eq) goto loc_82411208;
	// lwz r11,10896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// subf r10,r11,r30
	ctx.r10.s64 = r30.s64 - r11.s64;
	// clrlwi. r10,r10,30
	ctx.r10.u64 = ctx.r10.u32 & 0x3;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82411208
	if (cr0.eq) goto loc_82411208;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// bne cr6,0x824111d0
	if (!cr6.eq) goto loc_824111D0;
	// rlwinm r11,r11,0,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bgt cr6,0x824111d0
	if (cr6.gt) goto loc_824111D0;
loc_82411208:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82412ed0
	ctx.lr = 0x82411210;
	sub_82412ED0(ctx, base);
loc_82411210:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82411218"))) PPC_WEAK_FUNC(sub_82411218);
PPC_FUNC_IMPL(__imp__sub_82411218) {
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
	ctx.lr = 0x82411220;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// add r10,r31,r5
	ctx.r10.u64 = r31.u64 + ctx.r5.u64;
	// lwz r11,14900(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 14900);
	// lwz r9,10896(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 10896);
	// and r30,r10,r11
	r30.u64 = ctx.r10.u64 & r11.u64;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// lwz r11,60(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// bge cr6,0x8241125c
	if (!cr6.lt) goto loc_8241125C;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bge cr6,0x824112b8
	if (!cr6.lt) goto loc_824112B8;
loc_82411250:
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// ble cr6,0x82411264
	if (!cr6.gt) goto loc_82411264;
	// b 0x824112b8
	goto loc_824112B8;
loc_8241125C:
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bge cr6,0x82411250
	if (!cr6.lt) goto loc_82411250;
loc_82411264:
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82412ea0
	ctx.lr = 0x82411274;
	sub_82412EA0(ctx, base);
loc_82411274:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82412f98
	ctx.lr = 0x8241127C;
	sub_82412F98(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x824112b0
	if (cr0.eq) goto loc_824112B0;
	// lwz r11,10896(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 10896);
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// bge cr6,0x824112a0
	if (!cr6.lt) goto loc_824112A0;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bge cr6,0x824112b0
	if (!cr6.lt) goto loc_824112B0;
	// b 0x824112a8
	goto loc_824112A8;
loc_824112A0:
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// blt cr6,0x82411274
	if (cr6.lt) goto loc_82411274;
loc_824112A8:
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// ble cr6,0x82411274
	if (!cr6.gt) goto loc_82411274;
loc_824112B0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82412ed0
	ctx.lr = 0x824112B8;
	sub_82412ED0(ctx, base);
loc_824112B8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824112C4"))) PPC_WEAK_FUNC(sub_824112C4);
PPC_FUNC_IMPL(__imp__sub_824112C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824112C8"))) PPC_WEAK_FUNC(sub_824112C8);
PPC_FUNC_IMPL(__imp__sub_824112C8) {
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
	ctx.lr = 0x824112D0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r3,21532(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 21532);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82411300
	if (cr6.eq) goto loc_82411300;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82411300;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82411300:
	// lwz r11,23308(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 23308);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82411324
	if (cr6.eq) goto loc_82411324;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82411324;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82411324:
	// lwz r31,10952(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 10952);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r27,14900(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 14900);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r26,14896(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 14896);
	// bl 0x82411218
	ctx.lr = 0x82411340;
	sub_82411218(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8241136c
	if (cr6.eq) goto loc_8241136C;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_8241134C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r9,r31,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r31,1
	ctx.r8.s64 = r31.s64 + 1;
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// and r31,r8,r27
	r31.u64 = ctx.r8.u64 & r27.u64;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stwx r10,r9,r26
	PPC_STORE_U32(ctx.r9.u32 + r26.u32, ctx.r10.u32);
	// bne 0x8241134c
	if (!cr0.eq) goto loc_8241134C;
loc_8241136C:
	// lwz r3,21532(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 21532);
	// stw r31,10952(r30)
	PPC_STORE_U32(r30.u32 + 10952, r31.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8241138c
	if (cr6.eq) goto loc_8241138C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8241138C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8241138C:
	// lwz r11,23308(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 23308);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824113b0
	if (cr6.eq) goto loc_824113B0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824113B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824113B0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_824113B8"))) PPC_WEAK_FUNC(sub_824113B8);
PPC_FUNC_IMPL(__imp__sub_824113B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister reserved{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
loc_824113B8:
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// bge cr6,0x824113cc
	if (!cr6.lt) goto loc_824113CC;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
loc_824113CC:
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// cmplw cr6,r5,r9
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r9.u32, xer);
	// ble cr6,0x824113dc
	if (!cr6.gt) goto loc_824113DC;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
loc_824113DC:
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// rldimi r10,r9,32,0
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r10.u64 & 0xFFFFFFFF);
loc_824113E4:
	// mfmsr r7
	ctx.r7.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// ldarx r8,0,r3
	reserved.u64 = *(uint64_t*)(base + ctx.r3.u32);
	ctx.r8.u64 = __builtin_bswap64(reserved.u64);
	// cmpd cr6,r8,r11
	cr6.compare<int64_t>(ctx.r8.s64, r11.s64, xer);
	// bne cr6,0x82411408
	if (!cr6.eq) goto loc_82411408;
	// stdcx. r10,0,r3
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(base + ctx.r3.u32), reserved.s64, __builtin_bswap64(ctx.r10.s64));
	cr0.so = xer.so;
	// mtmsrd r7,1
	ctx.msr = (ctx.r7.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x824113e4
	if (!cr0.eq) goto loc_824113E4;
	// b 0x82411410
	goto loc_82411410;
loc_82411408:
	// stdcx. r8,0,r3
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(base + ctx.r3.u32), reserved.s64, __builtin_bswap64(ctx.r8.s64));
	cr0.so = xer.so;
	// mtmsrd r7,1
	ctx.msr = (ctx.r7.u32 & 0x8020) | (ctx.msr & ~0x8020);
loc_82411410:
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// cmpld cr6,r10,r11
	cr6.compare<uint64_t>(ctx.r10.u64, r11.u64, xer);
	// bne cr6,0x824113b8
	if (!cr6.eq) goto loc_824113B8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82411420"))) PPC_WEAK_FUNC(sub_82411420);
PPC_FUNC_IMPL(__imp__sub_82411420) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister reserved{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
loc_82411420:
	// li r10,-1
	ctx.r10.s64 = -1;
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
loc_8241142C:
	// mfmsr r8
	ctx.r8.u64 = ctx.msr;
	// mtmsrd r13,1
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// ldarx r9,0,r3
	reserved.u64 = *(uint64_t*)(base + ctx.r3.u32);
	ctx.r9.u64 = __builtin_bswap64(reserved.u64);
	// cmpd cr6,r9,r11
	cr6.compare<int64_t>(ctx.r9.s64, r11.s64, xer);
	// bne cr6,0x82411450
	if (!cr6.eq) goto loc_82411450;
	// stdcx. r10,0,r3
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(base + ctx.r3.u32), reserved.s64, __builtin_bswap64(ctx.r10.s64));
	cr0.so = xer.so;
	// mtmsrd r8,1
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	// bne 0x8241142c
	if (!cr0.eq) goto loc_8241142C;
	// b 0x82411458
	goto loc_82411458;
loc_82411450:
	// stdcx. r9,0,r3
	cr0.lt = 0;
	cr0.gt = 0;
	cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint64_t*>(base + ctx.r3.u32), reserved.s64, __builtin_bswap64(ctx.r9.s64));
	cr0.so = xer.so;
	// mtmsrd r8,1
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
loc_82411458:
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// cmpld cr6,r10,r11
	cr6.compare<uint64_t>(ctx.r10.u64, r11.u64, xer);
	// bne cr6,0x82411420
	if (!cr6.eq) goto loc_82411420;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82411478"))) PPC_WEAK_FUNC(sub_82411478);
PPC_FUNC_IMPL(__imp__sub_82411478) {
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
	ctx.lr = 0x82411480;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// bne cr6,0x82411508
	if (!cr6.eq) goto loc_82411508;
	// lwz r11,10900(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10900);
	// lis r10,2989
	ctx.r10.s64 = 195887104;
	// ori r10,r10,61453
	ctx.r10.u64 = ctx.r10.u64 | 61453;
	// lwz r30,16(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// bne cr6,0x824114b8
	if (!cr6.eq) goto loc_824114B8;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// addi r3,r11,6840
	ctx.r3.s64 = r11.s64 + 6840;
	// bl 0x82425420
	ctx.lr = 0x824114B4;
	sub_82425420(ctx, base);
	// twi 31,r0,22
loc_824114B8:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824114d0
	if (cr6.eq) goto loc_824114D0;
	// lwz r11,10900(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10900);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r30
	ctr.u64 = r30.u64;
	// bctrl 
	ctx.lr = 0x824114D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824114D0:
	// addi r30,r31,10904
	r30.s64 = r31.s64 + 10904;
	// lbz r11,268(r13)
	r11.u64 = PPC_LOAD_U8(ctx.r13.u32 + 268);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r31,10900(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 10900);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// slw r29,r10,r11
	r29.u64 = r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (r11.u8 & 0x3F));
	// bl 0x827bd504
	ctx.lr = 0x824114EC;
	__imp__KeAcquireSpinLockAtRaisedIrql(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// andc r11,r11,r29
	r11.u64 = r11.u64 & ~r29.u64;
	// clrlwi r11,r11,26
	r11.u64 = r11.u32 & 0x3F;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bl 0x827bd544
	ctx.lr = 0x82411504;
	__imp__KeReleaseSpinLockFromRaisedIrql(ctx, base);
	// b 0x82411528
	goto loc_82411528;
loc_82411508:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82411528
	if (!cr6.eq) goto loc_82411528;
	// lis r11,32712
	r11.s64 = 2143813632;
	// lwz r11,25924(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 25924);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82411528
	if (cr0.eq) goto loc_82411528;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82419718
	ctx.lr = 0x82411528;
	sub_82419718(ctx, base);
loc_82411528:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82411530"))) PPC_WEAK_FUNC(sub_82411530);
PPC_FUNC_IMPL(__imp__sub_82411530) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82411568
	if (cr6.eq) goto loc_82411568;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r8,-16384
	ctx.r8.s64 = -1073741824;
	// rlwinm r11,r10,12,20,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addis r11,r11,-16384
	r11.s64 = r11.s64 + -1073741824;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
loc_82411568:
	// li r11,0
	r11.s64 = 0;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82411574"))) PPC_WEAK_FUNC(sub_82411574);
PPC_FUNC_IMPL(__imp__sub_82411574) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82411578"))) PPC_WEAK_FUNC(sub_82411578);
PPC_FUNC_IMPL(__imp__sub_82411578) {
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
	ctx.lr = 0x82411580;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r10,r5,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 12) & 0xFFF;
	// lwz r30,8(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r9,r4,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 12) & 0xFFF;
	// addi r11,r10,512
	r11.s64 = ctx.r10.s64 + 512;
	// rlwinm r10,r30,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 12) & 0xFFF;
	// rlwinm r7,r11,0,19,19
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// clrlwi r8,r5,3
	ctx.r8.u64 = ctx.r5.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// add r6,r7,r8
	ctx.r6.u64 = ctx.r7.u64 + ctx.r8.u64;
	// rlwinm r7,r9,0,19,19
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// lis r11,16384
	r11.s64 = 1073741824;
	// clrlwi r9,r30,3
	ctx.r9.u64 = r30.u32 & 0x1FFFFFFF;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// clrlwi r8,r4,3
	ctx.r8.u64 = ctx.r4.u32 & 0x1FFFFFFF;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r6,r11,r6
	ctx.r6.s64 = ctx.r6.s64 - r11.s64;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// addi r9,r5,-4
	ctx.r9.s64 = ctx.r5.s64 + -4;
	// stw r6,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// subf r29,r11,r8
	r29.s64 = ctx.r8.s64 - r11.s64;
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// subf r31,r11,r10
	r31.s64 = ctx.r10.s64 - r11.s64;
	// eieio 
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82425cd8
	ctx.lr = 0x824115F8;
	sub_82425CD8(ctx, base);
	// stw r29,0(r30)
	PPC_MM_STORE_U32(r30.u32 + 0, r29.u32);
	// eieio 
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82425cd8
	ctx.lr = 0x82411610;
	sub_82425CD8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82411618"))) PPC_WEAK_FUNC(sub_82411618);
PPC_FUNC_IMPL(__imp__sub_82411618) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,16728(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16728);
	// lbz r9,10941(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10941);
	// addi r11,r10,4800
	r11.s64 = ctx.r10.s64 + 4800;
	// ori r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 | 32;
	// addi r8,r11,-160
	ctx.r8.s64 = r11.s64 + -160;
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// stw r10,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r10.u32);
	// stw r8,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r8.u32);
	// stb r9,10941(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10941, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82411640"))) PPC_WEAK_FUNC(sub_82411640);
PPC_FUNC_IMPL(__imp__sub_82411640) {
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
	ctx.lr = 0x82411648;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// clrlwi. r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r7,r11,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// lwz r11,14916(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14916);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq 0x82411740
	if (cr0.eq) goto loc_82411740;
	// bne cr6,0x82411674
	if (!cr6.eq) goto loc_82411674;
	// lwz r11,52(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// addi r11,r11,60
	r11.s64 = r11.s64 + 60;
loc_82411674:
	// add r10,r11,r6
	ctx.r10.u64 = r11.u64 + ctx.r6.u64;
	// lwz r9,14908(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14908);
	// addi r11,r6,-1
	r11.s64 = ctx.r6.s64 + -1;
	// lwz r5,14920(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14920);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// not r11,r11
	r11.u64 = ~r11.u64;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// and r31,r8,r11
	r31.u64 = ctx.r8.u64 & r11.u64;
	// add r4,r10,r31
	ctx.r4.u64 = ctx.r10.u64 + r31.u64;
	// cmplw cr6,r4,r9
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, xer);
	// bgt cr6,0x824116dc
	if (cr6.gt) goto loc_824116DC;
	// lwz r10,13232(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13232);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824116d4
	if (cr6.eq) goto loc_824116D4;
	// lwz r11,13236(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13236);
	// subf r11,r5,r11
	r11.s64 = r11.s64 - ctx.r5.s64;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x824116cc
	if (cr6.eq) goto loc_824116CC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824116d4
	if (!cr6.eq) goto loc_824116D4;
	// cmplw cr6,r10,r4
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r4.u32, xer);
	// bge cr6,0x824116d4
	if (!cr6.lt) goto loc_824116D4;
loc_824116CC:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82411838
	goto loc_82411838;
loc_824116D4:
	// stw r4,14916(r3)
	PPC_STORE_U32(ctx.r3.u32 + 14916, ctx.r4.u32);
	// b 0x82411734
	goto loc_82411734;
loc_824116DC:
	// lwz r9,14924(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14924);
	// lwz r8,13232(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13232);
	// add r9,r9,r6
	ctx.r9.u64 = ctx.r9.u64 + ctx.r6.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// and r31,r9,r11
	r31.u64 = ctx.r9.u64 & r11.u64;
	// add r4,r10,r31
	ctx.r4.u64 = ctx.r10.u64 + r31.u64;
	// beq cr6,0x82411720
	if (cr6.eq) goto loc_82411720;
	// lwz r11,13236(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13236);
	// subf r11,r5,r11
	r11.s64 = r11.s64 - ctx.r5.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x824116cc
	if (cr6.eq) goto loc_824116CC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82411720
	if (!cr6.eq) goto loc_82411720;
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// blt cr6,0x824116cc
	if (cr6.lt) goto loc_824116CC;
loc_82411720:
	// lwz r11,14928(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14928);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bgt cr6,0x824116cc
	if (cr6.gt) goto loc_824116CC;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// stw r4,14924(r3)
	PPC_STORE_U32(ctx.r3.u32 + 14924, ctx.r4.u32);
loc_82411734:
	// bl 0x82411180
	ctx.lr = 0x82411738;
	sub_82411180(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x82411838
	goto loc_82411838;
loc_82411740:
	// bne cr6,0x8241174c
	if (!cr6.eq) goto loc_8241174C;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
loc_8241174C:
	// addi r11,r11,31
	r11.s64 = r11.s64 + 31;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// rlwinm r30,r11,0,0,26
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFE0;
	// bne cr6,0x82411760
	if (!cr6.eq) goto loc_82411760;
	// li r7,54
	ctx.r7.s64 = 54;
loc_82411760:
	// lwz r11,14912(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14912);
	// rlwinm r11,r11,30,2,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// cmplw cr6,r7,r11
	cr6.compare<uint32_t>(ctx.r7.u32, r11.u32, xer);
	// ble cr6,0x82411774
	if (!cr6.gt) goto loc_82411774;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
loc_82411774:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,14908(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14908);
	// add r31,r10,r30
	r31.u64 = ctx.r10.u64 + r30.u64;
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// ble cr6,0x8241178c
	if (!cr6.gt) goto loc_8241178C;
	// mr r31,r11
	r31.u64 = r11.u64;
loc_8241178C:
	// subf r11,r30,r31
	r11.s64 = r31.s64 - r30.s64;
	// srawi r11,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r11.s64 = r11.s32 >> 2;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// bge cr6,0x824117cc
	if (!cr6.lt) goto loc_824117CC;
	// lwz r11,14920(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14920);
	// lbz r9,10942(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10942);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r11,14924(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14924);
	// lwz r6,14904(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14904);
	// ori r9,r9,4
	ctx.r9.u64 = ctx.r9.u64 | 4;
	// addi r11,r11,31
	r11.s64 = r11.s64 + 31;
	// stw r8,14920(r3)
	PPC_STORE_U32(ctx.r3.u32 + 14920, ctx.r8.u32);
	// stb r9,10942(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10942, ctx.r9.u8);
	// rlwinm r30,r11,0,0,26
	r30.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFE0;
	// stw r6,14924(r3)
	PPC_STORE_U32(ctx.r3.u32 + 14924, ctx.r6.u32);
	// add r31,r10,r30
	r31.u64 = ctx.r10.u64 + r30.u64;
loc_824117CC:
	// lwz r8,13232(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13232);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82411818
	if (cr6.eq) goto loc_82411818;
	// lwz r11,13236(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13236);
	// lwz r10,14920(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14920);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// beq cr6,0x824117fc
	if (cr6.eq) goto loc_824117FC;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82411818
	if (!cr6.eq) goto loc_82411818;
	// cmplw cr6,r8,r31
	cr6.compare<uint32_t>(ctx.r8.u32, r31.u32, xer);
	// bge cr6,0x82411818
	if (!cr6.lt) goto loc_82411818;
loc_824117FC:
	// mr r31,r8
	r31.u64 = ctx.r8.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x824116cc
	if (!cr6.eq) goto loc_824116CC;
	// subf r11,r30,r31
	r11.s64 = r31.s64 - r30.s64;
	// srawi r11,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r11.s64 = r11.s32 >> 2;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x824116cc
	if (cr6.lt) goto loc_824116CC;
loc_82411818:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r5,14920(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14920);
	// bl 0x82411180
	ctx.lr = 0x82411824;
	sub_82411180(ctx, base);
	// subf r11,r30,r31
	r11.s64 = r31.s64 - r30.s64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// srawi r11,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r11.s64 = r11.s32 >> 2;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_82411838:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82411840"))) PPC_WEAK_FUNC(sub_82411840);
PPC_FUNC_IMPL(__imp__sub_82411840) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// lbz r11,10941(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8241186c
	if (cr0.eq) goto loc_8241186C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82411914
	goto loc_82411914;
loc_8241186C:
	// lwz r3,13516(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 13516);
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// bne cr6,0x82411894
	if (!cr6.eq) goto loc_82411894;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82411640
	ctx.lr = 0x82411890;
	sub_82411640(ctx, base);
	// b 0x824118b0
	goto loc_824118B0;
loc_82411894:
	// lwz r11,152(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824118ac
	if (cr6.eq) goto loc_824118AC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8241a478
	ctx.lr = 0x824118A8;
	sub_8241A478(ctx, base);
	// b 0x824118b0
	goto loc_824118B0;
loc_824118AC:
	// bl 0x8241a790
	ctx.lr = 0x824118B0;
	sub_8241A790(ctx, base);
loc_824118B0:
	// lwz r11,14932(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 14932);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,14936(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 14936);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,14932(r31)
	PPC_STORE_U32(r31.u32 + 14932, r11.u32);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// ble cr6,0x82411900
	if (!cr6.gt) goto loc_82411900;
	// lwz r11,13232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13232);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82411900
	if (!cr6.eq) goto loc_82411900;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r10,14924(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 14924);
	// lwz r9,14904(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 14904);
	// addi r8,r11,160
	ctx.r8.s64 = r11.s64 + 160;
	// stw r8,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r8.u32);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// beq cr6,0x82411900
	if (cr6.eq) goto loc_82411900;
	// lwz r11,14908(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 14908);
	// stw r11,14916(r31)
	PPC_STORE_U32(r31.u32 + 14916, r11.u32);
loc_82411900:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82411914
	if (!cr6.eq) goto loc_82411914;
	// lbz r11,10941(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// ori r11,r11,32
	r11.u64 = r11.u64 | 32;
	// stb r11,10941(r31)
	PPC_STORE_U8(r31.u32 + 10941, r11.u8);
loc_82411914:
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

__attribute__((alias("__imp__sub_82411928"))) PPC_WEAK_FUNC(sub_82411928);
PPC_FUNC_IMPL(__imp__sub_82411928) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82411930;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lbz r11,10941(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 10941);
	// lwz r25,14900(r26)
	r25.u64 = PPC_LOAD_U32(r26.u32 + 14900);
	// lwz r24,14896(r26)
	r24.u64 = PPC_LOAD_U32(r26.u32 + 14896);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x824119cc
	if (cr0.eq) goto loc_824119CC;
	// lwz r11,21532(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 21532);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82411b04
	if (cr6.eq) goto loc_82411B04;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82411b04
	if (cr6.eq) goto loc_82411B04;
	// lis r21,8192
	r21.s64 = 536870912;
	// lis r22,16384
	r22.s64 = 1073741824;
	// lis r23,16640
	r23.s64 = 1090519040;
loc_82411974:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplw cr6,r11,r21
	cr6.compare<uint32_t>(r11.u32, r21.u32, xer);
	// clrlwi r5,r10,8
	ctx.r5.u64 = ctx.r10.u32 & 0xFFFFFF;
	// subf r4,r22,r11
	ctx.r4.s64 = r11.s64 - r22.s64;
	// blt cr6,0x82411990
	if (cr6.lt) goto loc_82411990;
	// subf r4,r23,r11
	ctx.r4.s64 = r11.s64 - r23.s64;
loc_82411990:
	// lwz r3,21532(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 21532);
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824119A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,21532(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 21532);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824119BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bne 0x82411974
	if (!cr0.eq) goto loc_82411974;
	// b 0x82411b04
	goto loc_82411B04;
loc_824119CC:
	// lwz r29,10952(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + 10952);
	// mulli r5,r31,3
	ctx.r5.s64 = r31.s64 * 3;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82411218
	ctx.lr = 0x824119E0;
	sub_82411218(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82411aac
	if (cr6.eq) goto loc_82411AAC;
	// mr r27,r31
	r27.u64 = r31.u64;
	// lis r21,8192
	r21.s64 = 536870912;
	// lis r22,16384
	r22.s64 = 1073741824;
	// lis r23,16640
	r23.s64 = 1090519040;
loc_824119F8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,21532(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 21532);
	// lwz r31,4(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// clrlwi r28,r11,8
	r28.u64 = r11.u32 & 0xFFFFFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82411a38
	if (cr6.eq) goto loc_82411A38;
	// cmplw cr6,r31,r21
	cr6.compare<uint32_t>(r31.u32, r21.u32, xer);
	// subf r4,r22,r31
	ctx.r4.s64 = r31.s64 - r22.s64;
	// blt cr6,0x82411a20
	if (cr6.lt) goto loc_82411A20;
	// subf r4,r23,r31
	ctx.r4.s64 = r31.s64 - r23.s64;
loc_82411A20:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82411A38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82411A38:
	// lwz r11,23308(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 23308);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82411a68
	if (cr6.eq) goto loc_82411A68;
	// cmplw cr6,r31,r21
	cr6.compare<uint32_t>(r31.u32, r21.u32, xer);
	// subf r4,r22,r31
	ctx.r4.s64 = r31.s64 - r22.s64;
	// blt cr6,0x82411a54
	if (cr6.lt) goto loc_82411A54;
	// subf r4,r23,r31
	ctx.r4.s64 = r31.s64 - r23.s64;
loc_82411A54:
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82411A68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82411A68:
	// addi r11,r29,1
	r11.s64 = r29.s64 + 1;
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// and r11,r11,r25
	r11.u64 = r11.u64 & r25.u64;
	// lis r9,-16383
	ctx.r9.s64 = -1073676288;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// and r11,r8,r25
	r11.u64 = ctx.r8.u64 & r25.u64;
	// ori r9,r9,16128
	ctx.r9.u64 = ctx.r9.u64 | 16128;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r9,r10,r24
	PPC_STORE_U32(ctx.r10.u32 + r24.u32, ctx.r9.u32);
	// stwx r31,r7,r24
	PPC_STORE_U32(ctx.r7.u32 + r24.u32, r31.u32);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// and r29,r11,r25
	r29.u64 = r11.u64 & r25.u64;
	// stwx r28,r8,r24
	PPC_STORE_U32(ctx.r8.u32 + r24.u32, r28.u32);
	// bne 0x824119f8
	if (!cr0.eq) goto loc_824119F8;
loc_82411AAC:
	// stw r29,10952(r26)
	PPC_STORE_U32(r26.u32 + 10952, r29.u32);
	// sync 
	// lis r11,32712
	r11.s64 = 2143813632;
	// stw r29,1812(r11)
	PPC_MM_STORE_U32(r11.u32 + 1812, r29.u32);
	// eieio 
	// sync 
	// lwz r3,21532(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 21532);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82411ae0
	if (cr6.eq) goto loc_82411AE0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82411AE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82411AE0:
	// lwz r11,23308(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 23308);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82411b04
	if (cr6.eq) goto loc_82411B04;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82411B04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82411B04:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82411B0C"))) PPC_WEAK_FUNC(sub_82411B0C);
PPC_FUNC_IMPL(__imp__sub_82411B0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82411B10"))) PPC_WEAK_FUNC(sub_82411B10);
PPC_FUNC_IMPL(__imp__sub_82411B10) {
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
	ctx.lr = 0x82411B18;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,-1
	r11.s64 = -1;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// clrldi r11,r11,32
	r11.u64 = r11.u64 & 0xFFFFFFFF;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// ld r10,11824(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 11824);
	// addi r28,r31,11824
	r28.s64 = r31.s64 + 11824;
	// li r26,0
	r26.s64 = 0;
	// cmpld cr6,r10,r11
	cr6.compare<uint64_t>(ctx.r10.u64, r11.u64, xer);
	// li r30,1
	r30.s64 = 1;
	// bne cr6,0x82411b4c
	if (!cr6.eq) goto loc_82411B4C;
	// mr r30,r26
	r30.u64 = r26.u64;
loc_82411B4C:
	// lbz r11,10942(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10942);
	// rlwinm r27,r11,30,31,31
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1;
	// add r11,r27,r30
	r11.u64 = r27.u64 + r30.u64;
	// mulli r25,r11,11
	r25.s64 = r11.s64 * 11;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x82411b6c
	if (!cr6.eq) goto loc_82411B6C;
loc_82411B64:
	// stw r26,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r26.u32);
	// b 0x82411cc8
	goto loc_82411CC8;
loc_82411B6C:
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82411840
	ctx.lr = 0x82411B7C;
	sub_82411840(ctx, base);
	// mr. r29,r3
	r29.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// beq 0x82411b64
	if (cr0.eq) goto loc_82411B64;
	// addi r7,r29,-4
	ctx.r7.s64 = r29.s64 + -4;
	// lis r6,-32768
	ctx.r6.s64 = -2147483648;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x82411c14
	if (cr6.eq) goto loc_82411C14;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82411420
	ctx.lr = 0x82411BA4;
	sub_82411420(ctx, base);
	// li r11,2609
	r11.s64 = 2609;
	// lis r10,768
	ctx.r10.s64 = 50331648;
	// stwu r11,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r7.u32 = ea;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// lis r8,-16380
	ctx.r8.s64 = -1073479680;
	// ori r11,r9,2607
	r11.u64 = ctx.r9.u64 | 2607;
	// ori r9,r8,15360
	ctx.r9.u64 = ctx.r8.u64 | 15360;
	// li r8,3
	ctx.r8.s64 = 3;
	// stwu r10,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r7.u32 = ea;
	// li r5,2609
	ctx.r5.s64 = 2609;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// stwu r11,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r7.u32 = ea;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r11,r11,4095
	r11.s64 = r11.s64 + 4095;
	// rlwinm r30,r30,0,0,19
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFF000;
	// rlwinm r11,r11,0,0,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	// subf r11,r30,r11
	r11.s64 = r11.s64 - r30.s64;
	// stwu r11,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r7.u32 = ea;
	// stwu r30,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, r30.u32);
	ctx.r7.u32 = ea;
	// stwu r9,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r7.u32 = ea;
	// stwu r8,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r7.u32 = ea;
	// stwu r5,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r7.u32 = ea;
	// stwu r4,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r7.u32 = ea;
	// stwu r3,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r7.u32 = ea;
	// stwu r10,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r7.u32 = ea;
loc_82411C14:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x82411cac
	if (cr6.eq) goto loc_82411CAC;
	// li r11,2609
	r11.s64 = 2609;
	// lwz r9,14908(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 14908);
	// lwz r5,14904(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 14904);
	// lis r8,256
	ctx.r8.s64 = 16777216;
	// stwu r11,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r7.u32 = ea;
	// rlwinm r11,r9,12,20,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFF;
	// rlwinm r10,r5,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 12) & 0xFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// addi r4,r10,512
	ctx.r4.s64 = ctx.r10.s64 + 512;
	// rlwinm r10,r11,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// clrlwi r11,r9,3
	r11.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// stwu r8,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r7.u32 = ea;
	// clrlwi r9,r5,3
	ctx.r9.u64 = ctx.r5.u32 & 0x1FFFFFFF;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rlwinm r8,r4,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x1000;
	// lis r3,1
	ctx.r3.s64 = 65536;
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r11,r11,4095
	r11.s64 = r11.s64 + 4095;
	// ori r5,r3,2607
	ctx.r5.u64 = ctx.r3.u64 | 2607;
	// rlwinm r10,r10,0,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFF000;
	// stwu r5,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r7.u32 = ea;
	// rlwinm r11,r11,0,0,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFF000;
	// lis r9,-16380
	ctx.r9.s64 = -1073479680;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// ori r9,r9,15360
	ctx.r9.u64 = ctx.r9.u64 | 15360;
	// li r8,2609
	ctx.r8.s64 = 2609;
	// stwu r11,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r7.u32 = ea;
	// li r11,3
	r11.s64 = 3;
	// li r5,8
	ctx.r5.s64 = 8;
	// stwu r10,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r7.u32 = ea;
	// stwu r9,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r7.u32 = ea;
	// stwu r11,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r7.u32 = ea;
	// stwu r8,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r7.u32 = ea;
	// stwu r26,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, r26.u32);
	ctx.r7.u32 = ea;
	// stwu r6,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r7.u32 = ea;
	// stwu r5,4(r7)
	ea = 4 + ctx.r7.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r7.u32 = ea;
loc_82411CAC:
	// rlwinm r11,r29,12,20,31
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r29,3
	ctx.r10.u64 = r29.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,0(r23)
	PPC_STORE_U32(r23.u32 + 0, r11.u32);
	// stw r25,0(r24)
	PPC_STORE_U32(r24.u32 + 0, r25.u32);
loc_82411CC8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82411CD0"))) PPC_WEAK_FUNC(sub_82411CD0);
PPC_FUNC_IMPL(__imp__sub_82411CD0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r9,-16384
	ctx.r9.s64 = -1073741824;
	// li r3,32767
	ctx.r3.s64 = 32767;
	// ori r6,r9,15104
	ctx.r6.u64 = ctx.r9.u64 | 15104;
	// lis r31,-16382
	r31.s64 = -1073610752;
	// lwz r5,48(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// li r30,3
	r30.s64 = 3;
	// lwz r7,14920(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 14920);
	// ori r31,r31,22528
	r31.u64 = r31.u64 | 22528;
	// lwz r10,10896(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 10896);
	// lwz r8,10908(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 10908);
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// stw r5,13240(r11)
	PPC_STORE_U32(r11.u32 + 13240, ctx.r5.u32);
	// stw r7,13244(r11)
	PPC_STORE_U32(r11.u32 + 13244, ctx.r7.u32);
	// clrlwi r7,r7,30
	ctx.r7.u64 = ctx.r7.u32 & 0x3;
	// stwu r6,4(r4)
	ea = 4 + ctx.r4.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r4.u32 = ea;
	// rlwinm r6,r9,12,20,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFF;
	// clrlwi r9,r9,3
	ctx.r9.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// addi r6,r6,512
	ctx.r6.s64 = ctx.r6.s64 + 512;
	// or r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 | ctx.r5.u64;
	// rlwinm r6,r6,0,19,19
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x1000;
	// stwu r3,4(r4)
	ea = 4 + ctx.r4.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r4.u32 = ea;
	// lis r5,-16382
	ctx.r5.s64 = -1073610752;
	// add r9,r6,r9
	ctx.r9.u64 = ctx.r6.u64 + ctx.r9.u64;
	// ori r5,r5,22528
	ctx.r5.u64 = ctx.r5.u64 | 22528;
	// ori r6,r9,2
	ctx.r6.u64 = ctx.r9.u64 | 2;
	// rlwinm r9,r10,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// stwu r31,4(r4)
	ea = 4 + ctx.r4.u32;
	PPC_STORE_U32(ea, r31.u32);
	ctx.r4.u32 = ea;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// li r3,3
	ctx.r3.s64 = 3;
	// rlwinm r9,r9,0,19,19
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// stwu r30,4(r4)
	ea = 4 + ctx.r4.u32;
	PPC_STORE_U32(ea, r30.u32);
	ctx.r4.u32 = ea;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// ori r10,r10,2
	ctx.r10.u64 = ctx.r10.u64 | 2;
	// stwu r6,4(r4)
	ea = 4 + ctx.r4.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r4.u32 = ea;
	// stwu r7,4(r4)
	ea = 4 + ctx.r4.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r4.u32 = ea;
	// stwu r5,4(r4)
	ea = 4 + ctx.r4.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r4.u32 = ea;
	// stwu r3,4(r4)
	ea = 4 + ctx.r4.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r4.u32 = ea;
	// stwu r10,4(r4)
	ea = 4 + ctx.r4.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r4.u32 = ea;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// lwz r10,21532(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 21532);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82411da8
	if (!cr6.eq) goto loc_82411DA8;
	// lbz r10,10941(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10941);
	// rlwinm. r10,r10,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82411da8
	if (cr0.eq) goto loc_82411DA8;
	// lwz r10,10896(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 10896);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// lwz r10,10896(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 10896);
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
loc_82411DA8:
	// addi r10,r8,2
	ctx.r10.s64 = ctx.r8.s64 + 2;
	// stw r10,10908(r11)
	PPC_STORE_U32(r11.u32 + 10908, ctx.r10.u32);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82411DBC"))) PPC_WEAK_FUNC(sub_82411DBC);
PPC_FUNC_IMPL(__imp__sub_82411DBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82411DC0"))) PPC_WEAK_FUNC(sub_82411DC0);
PPC_FUNC_IMPL(__imp__sub_82411DC0) {
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
	ctx.lr = 0x82411DC8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// lwz r11,11008(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 11008);
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82411e5c
	if (cr6.eq) goto loc_82411E5C;
	// addi r24,r30,11012
	r24.s64 = r30.s64 + 11012;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x827bd684
	ctx.lr = 0x82411E00;
	__imp__KfAcquireSpinLock(ctx, base);
	// lwz r11,11008(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 11008);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82411e48
	if (cr6.eq) goto loc_82411E48;
	// oris r11,r27,33024
	r11.u64 = r27.u64 | 2164260864;
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82411578
	ctx.lr = 0x82411E38;
	sub_82411578(ctx, base);
	// lwz r11,11008(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 11008);
	// li r29,1
	r29.s64 = 1;
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
	// stw r11,11008(r30)
	PPC_STORE_U32(r30.u32 + 11008, r11.u32);
loc_82411E48:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x827bd674
	ctx.lr = 0x82411E54;
	__imp__KfReleaseSpinLock(ctx, base);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x82411e88
	if (!cr6.eq) goto loc_82411E88;
loc_82411E5C:
	// lwz r11,11008(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 11008);
	// clrlwi r10,r27,8
	ctx.r10.u64 = r27.u32 & 0xFFFFFF;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
	// oris r10,r10,33024
	ctx.r10.u64 = ctx.r10.u64 | 2164260864;
	// stw r11,11008(r30)
	PPC_STORE_U32(r30.u32 + 11008, r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82411928
	ctx.lr = 0x82411E88;
	sub_82411928(ctx, base);
loc_82411E88:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82411E94"))) PPC_WEAK_FUNC(sub_82411E94);
PPC_FUNC_IMPL(__imp__sub_82411E94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82411E98"))) PPC_WEAK_FUNC(sub_82411E98);
PPC_FUNC_IMPL(__imp__sub_82411E98) {
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
	ctx.lr = 0x82411EA0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82411f5c
	if (cr6.eq) goto loc_82411F5C;
	// lwz r11,10896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// lwz r10,10908(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10908);
	// subf r9,r30,r10
	ctx.r9.s64 = ctx.r10.s64 - r30.s64;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bge cr6,0x82411f5c
	if (!cr6.lt) goto loc_82411F5C;
	// clrlwi. r11,r7,24
	r11.u64 = ctx.r7.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82411ef8
	if (!cr0.eq) goto loc_82411EF8;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x82411ef8
	if (!cr6.eq) goto loc_82411EF8;
	// lwz r11,13232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13232);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82411f5c
	if (!cr6.eq) goto loc_82411F5C;
	// bl 0x82412710
	ctx.lr = 0x82411EF8;
	sub_82412710(ctx, base);
loc_82411EF8:
	// lwz r11,10896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// lwz r10,10908(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10908);
	// subf r9,r30,r10
	ctx.r9.s64 = ctx.r10.s64 - r30.s64;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bge cr6,0x82411f5c
	if (!cr6.lt) goto loc_82411F5C;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82412ea0
	ctx.lr = 0x82411F24;
	sub_82412EA0(ctx, base);
	// b 0x82411f38
	goto loc_82411F38;
loc_82411F28:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82412f98
	ctx.lr = 0x82411F30;
	sub_82412F98(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x82411f54
	if (cr0.eq) goto loc_82411F54;
loc_82411F38:
	// lwz r11,10896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// lwz r10,10908(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10908);
	// subf r9,r30,r10
	ctx.r9.s64 = ctx.r10.s64 - r30.s64;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// blt cr6,0x82411f28
	if (cr6.lt) goto loc_82411F28;
loc_82411F54:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82412ed0
	ctx.lr = 0x82411F5C;
	sub_82412ED0(ctx, base);
loc_82411F5C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82411F64"))) PPC_WEAK_FUNC(sub_82411F64);
PPC_FUNC_IMPL(__imp__sub_82411F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82411F68"))) PPC_WEAK_FUNC(sub_82411F68);
PPC_FUNC_IMPL(__imp__sub_82411F68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82411F70;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// rlwinm. r10,r5,0,29,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x6;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r11,2148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2148);
	// rlwinm r9,r5,8,26,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 8) & 0x3F;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,10900(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 10900);
	// bne 0x82411f98
	if (!cr0.eq) goto loc_82411F98;
	// ori r5,r5,6
	ctx.r5.u64 = ctx.r5.u64 | 6;
loc_82411F98:
	// lis r11,-16380
	r11.s64 = -1073479680;
	// rlwinm. r30,r5,0,30,30
	r30.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// li r31,-1
	r31.s64 = -1;
	// ori r11,r11,15360
	r11.u64 = r11.u64 | 15360;
	// beq 0x824120f4
	if (cr0.eq) goto loc_824120F4;
	// clrlwi. r30,r5,31
	r30.u64 = ctx.r5.u32 & 0x1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x82411fc8
	if (!cr0.eq) goto loc_82411FC8;
	// li r3,1480
	ctx.r3.s64 = 1480;
	// lis r30,2
	r30.s64 = 131072;
	// stwu r3,4(r4)
	ea = 4 + ctx.r4.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	ctx.r4.u32 = ea;
	// stwu r30,4(r4)
	ea = 4 + ctx.r4.u32;
	PPC_STORE_U32(ea, r30.u32);
	ctx.r4.u32 = ea;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
loc_82411FC8:
	// lis r4,1
	ctx.r4.s64 = 65536;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// ori r4,r4,1404
	ctx.r4.u64 = ctx.r4.u64 | 1404;
	// stwu r4,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r3.u32 = ea;
	// stwu r6,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r3.u32 = ea;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// stwu r7,4(r4)
	ea = 4 + ctx.r4.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r4.u32 = ea;
	// bne cr6,0x82411fec
	if (!cr6.eq) goto loc_82411FEC;
	// li r9,4
	ctx.r9.s64 = 4;
loc_82411FEC:
	// li r30,1400
	r30.s64 = 1400;
	// rlwinm r3,r10,12,20,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// stwu r30,4(r4)
	ea = 4 + ctx.r4.u32;
	PPC_STORE_U32(ea, r30.u32);
	ctx.r4.u32 = ea;
	// li r30,19
	r30.s64 = 19;
	// addi r29,r3,512
	r29.s64 = ctx.r3.s64 + 512;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// rlwinm r4,r29,0,19,19
	ctx.r4.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 0) & 0x1000;
	// clrlwi r3,r10,3
	ctx.r3.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// mr r29,r31
	r29.u64 = r31.u64;
	// add r4,r4,r3
	ctx.r4.u64 = ctx.r4.u64 + ctx.r3.u64;
	// stwu r9,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r28.u32 = ea;
	// li r27,256
	r27.s64 = 256;
	// lwz r3,12716(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12716);
	// ori r26,r4,2
	r26.u64 = ctx.r4.u64 | 2;
	// addi r4,r10,20
	ctx.r4.s64 = ctx.r10.s64 + 20;
	// or r25,r3,r11
	r25.u64 = ctx.r3.u64 | r11.u64;
	// rlwinm r3,r4,12,20,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 12) & 0xFFF;
	// stwu r25,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, r25.u32);
	r28.u32 = ea;
	// clrlwi r4,r4,3
	ctx.r4.u64 = ctx.r4.u32 & 0x1FFFFFFF;
	// addi r3,r3,512
	ctx.r3.s64 = ctx.r3.s64 + 512;
	// li r24,19
	r24.s64 = 19;
	// rlwinm r3,r3,0,19,19
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1000;
	// mr r25,r31
	r25.u64 = r31.u64;
	// stwu r30,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, r30.u32);
	r28.u32 = ea;
	// add r4,r3,r4
	ctx.r4.u64 = ctx.r3.u64 + ctx.r4.u64;
	// li r23,256
	r23.s64 = 256;
	// ori r30,r4,2
	r30.u64 = ctx.r4.u64 | 2;
	// addi r4,r10,16
	ctx.r4.s64 = ctx.r10.s64 + 16;
	// li r22,19
	r22.s64 = 19;
	// stwu r26,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, r26.u32);
	r28.u32 = ea;
	// rlwinm r3,r4,12,20,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 12) & 0xFFF;
	// clrlwi r4,r4,3
	ctx.r4.u64 = ctx.r4.u32 & 0x1FFFFFFF;
	// addi r3,r3,512
	ctx.r3.s64 = ctx.r3.s64 + 512;
	// mr r26,r31
	r26.u64 = r31.u64;
	// rlwinm r3,r3,0,19,19
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x1000;
	// stwu r9,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r28.u32 = ea;
	// li r21,1118
	r21.s64 = 1118;
	// add r4,r3,r4
	ctx.r4.u64 = ctx.r3.u64 + ctx.r4.u64;
	// li r3,256
	ctx.r3.s64 = 256;
	// ori r4,r4,2
	ctx.r4.u64 = ctx.r4.u64 | 2;
	// stwu r29,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, r29.u32);
	r28.u32 = ea;
	// stwu r27,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, r27.u32);
	r28.u32 = ea;
	// lwz r29,12716(r8)
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12716);
	// or r29,r29,r11
	r29.u64 = r29.u64 | r11.u64;
	// stwu r29,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, r29.u32);
	r28.u32 = ea;
	// stwu r24,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, r24.u32);
	r28.u32 = ea;
	// stwu r30,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, r30.u32);
	r28.u32 = ea;
	// stwu r7,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r28.u32 = ea;
	// stwu r25,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, r25.u32);
	r28.u32 = ea;
	// stwu r23,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, r23.u32);
	r28.u32 = ea;
	// lwz r7,12716(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12716);
	// or r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 | r11.u64;
	// stwu r7,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r28.u32 = ea;
	// stwu r22,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, r22.u32);
	r28.u32 = ea;
	// stwu r4,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	r28.u32 = ea;
	// stwu r6,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	r28.u32 = ea;
	// stwu r26,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, r26.u32);
	r28.u32 = ea;
	// stwu r3,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	r28.u32 = ea;
	// lwz r7,12716(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12716);
	// oris r7,r7,49152
	ctx.r7.u64 = ctx.r7.u64 | 3221225472;
	// ori r7,r7,21504
	ctx.r7.u64 = ctx.r7.u64 | 21504;
	// stwu r7,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r28.u32 = ea;
	// stwu r9,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r28.u32 = ea;
	// stwu r21,4(r28)
	ea = 4 + r28.u32;
	PPC_STORE_U32(ea, r21.u32);
	r28.u32 = ea;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
loc_824120F4:
	// rlwinm. r9,r5,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x4;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x82412154
	if (cr0.eq) goto loc_82412154;
	// lwz r9,12716(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12716);
	// li r8,19
	ctx.r8.s64 = 19;
	// or r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 | r11.u64;
	// rlwinm r11,r10,12,20,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// li r9,256
	ctx.r9.s64 = 256;
	// addi r7,r11,512
	ctx.r7.s64 = r11.s64 + 512;
	// clrlwi r11,r10,3
	r11.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// rlwinm r10,r7,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x1000;
	// lis r7,2989
	ctx.r7.s64 = 195887104;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// li r8,1404
	ctx.r8.s64 = 1404;
	// ori r7,r7,61453
	ctx.r7.u64 = ctx.r7.u64 | 61453;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// stwu r31,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r31.u32);
	ctx.r3.u32 = ea;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// stwu r8,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r3.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
loc_82412154:
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82412158"))) PPC_WEAK_FUNC(sub_82412158);
PPC_FUNC_IMPL(__imp__sub_82412158) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,6
	ctx.r5.s64 = 6;
	// lwz r11,2148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2148);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82411e98
	sub_82411E98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82412178"))) PPC_WEAK_FUNC(sub_82412178);
PPC_FUNC_IMPL(__imp__sub_82412178) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r4,8(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,5
	ctx.r5.s64 = 5;
	// lwz r11,2148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2148);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82411e98
	sub_82411E98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82412198"))) PPC_WEAK_FUNC(sub_82412198);
PPC_FUNC_IMPL(__imp__sub_82412198) {
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
	ctx.lr = 0x824121A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r29,16384
	r29.s64 = 1073741824;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824121d8
	if (cr6.eq) goto loc_824121D8;
	// lwz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// rlwinm r10,r9,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFF;
	// clrlwi r9,r9,3
	ctx.r9.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r10,r29,r10
	ctx.r10.s64 = ctx.r10.s64 - r29.s64;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_824121D8:
	// li r5,128
	ctx.r5.s64 = 128;
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// li r4,4224
	ctx.r4.s64 = 4224;
	// bl 0x82411840
	ctx.lr = 0x824121E8;
	sub_82411840(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x82412204
	if (!cr0.eq) goto loc_82412204;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r31,16728(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 16728);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// b 0x82412278
	goto loc_82412278;
loc_82412204:
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// rlwinm r9,r11,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r11,3
	ctx.r10.u64 = r11.u32 & 0x1FFFFFFF;
	// addi r11,r9,512
	r11.s64 = ctx.r9.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82412250
	if (cr6.eq) goto loc_82412250;
	// rlwinm r10,r31,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 12) & 0xFFF;
	// clrlwi r9,r31,3
	ctx.r9.u64 = r31.u32 & 0x1FFFFFFF;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subf r10,r29,r10
	ctx.r10.s64 = ctx.r10.s64 - r29.s64;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// b 0x82412254
	goto loc_82412254;
loc_82412250:
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
loc_82412254:
	// rlwinm r11,r31,12,20,31
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r31,3
	ctx.r10.u64 = r31.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// subf r3,r29,r11
	ctx.r3.s64 = r11.s64 - r29.s64;
	// addi r4,r3,4224
	ctx.r4.s64 = ctx.r3.s64 + 4224;
	// bl 0x82425cd8
	ctx.lr = 0x82412278;
	sub_82425CD8(ctx, base);
loc_82412278:
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r31,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r31.u32);
	// addi r11,r31,4220
	r11.s64 = r31.s64 + 4220;
	// stw r3,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r3.u32);
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82412294"))) PPC_WEAK_FUNC(sub_82412294);
PPC_FUNC_IMPL(__imp__sub_82412294) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82412298"))) PPC_WEAK_FUNC(sub_82412298);
PPC_FUNC_IMPL(__imp__sub_82412298) {
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
	ctx.lr = 0x824122A0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r6,-1
	r11.s64 = ctx.r6.s64 + -1;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mullw r31,r5,r6
	r31.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// not r26,r11
	r26.u64 = ~r11.u64;
loc_824122B8:
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// subf r11,r3,r11
	r11.s64 = r11.s64 - ctx.r3.s64;
	// srawi r11,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r11.s64 = r11.s32 >> 2;
	// and r28,r11,r26
	r28.u64 = r11.u64 & r26.u64;
	// cmplw cr6,r28,r31
	cr6.compare<uint32_t>(r28.u32, r31.u32, xer);
	// ble cr6,0x824122d8
	if (!cr6.gt) goto loc_824122D8;
	// mr r28,r31
	r28.u64 = r31.u64;
loc_824122D8:
	// rlwinm r29,r28,2,0,29
	r29.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823da950
	ctx.lr = 0x824122E8;
	sub_823DA950(ctx, base);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// subf. r31,r28,r31
	r31.s64 = r31.s64 - r28.s64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// add r27,r29,r27
	r27.u64 = r29.u64 + r27.u64;
	// stw r11,8(r30)
	PPC_STORE_U32(r30.u32 + 8, r11.u32);
	// beq 0x8241230c
	if (cr0.eq) goto loc_8241230C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82412198
	ctx.lr = 0x82412308;
	sub_82412198(ctx, base);
	// b 0x824122b8
	goto loc_824122B8;
loc_8241230C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82412314"))) PPC_WEAK_FUNC(sub_82412314);
PPC_FUNC_IMPL(__imp__sub_82412314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82412318"))) PPC_WEAK_FUNC(sub_82412318);
PPC_FUNC_IMPL(__imp__sub_82412318) {
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
	ctx.lr = 0x82412320;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,10941(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// rlwinm. r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82412360
	if (cr0.eq) goto loc_82412360;
	// lwz r10,16728(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16728);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r11,r10,4800
	r11.s64 = ctx.r10.s64 + 4800;
	// ori r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 | 32;
	// addi r8,r11,-160
	ctx.r8.s64 = r11.s64 + -160;
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// stw r10,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r10.u32);
	// stw r8,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r8.u32);
	// stb r9,10941(r31)
	PPC_STORE_U8(r31.u32 + 10941, ctx.r9.u8);
	// b 0x8241247c
	goto loc_8241247C;
loc_82412360:
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x82412374
	if (!cr6.eq) goto loc_82412374;
	// mr r11,r29
	r11.u64 = r29.u64;
	// b 0x8241237c
	goto loc_8241237C;
loc_82412374:
	// addi r11,r4,14
	r11.s64 = ctx.r4.s64 + 14;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
loc_8241237C:
	// lwz r3,13516(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 13516);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824123a4
	if (cr6.eq) goto loc_824123A4;
	// lwz r10,172(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 172);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824123a4
	if (cr6.eq) goto loc_824123A4;
	// lwz r10,14912(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 14912);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bgt cr6,0x824123a4
	if (cr6.gt) goto loc_824123A4;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_824123A4:
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r6,32
	ctx.r6.s64 = 32;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,2
	ctx.r4.s64 = 2;
	// bne 0x824123c8
	if (!cr0.eq) goto loc_824123C8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82411640
	ctx.lr = 0x824123C4;
	sub_82411640(ctx, base);
	// b 0x824123e4
	goto loc_824123E4;
loc_824123C8:
	// lwz r11,152(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824123e0
	if (cr6.eq) goto loc_824123E0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8241a478
	ctx.lr = 0x824123DC;
	sub_8241A478(ctx, base);
	// b 0x824123e4
	goto loc_824123E4;
loc_824123E0:
	// bl 0x8241a790
	ctx.lr = 0x824123E4;
	sub_8241A790(ctx, base);
loc_824123E4:
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82412414
	if (!cr6.eq) goto loc_82412414;
	// lwz r10,16728(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16728);
	// lbz r9,10941(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// addi r11,r10,4800
	r11.s64 = ctx.r10.s64 + 4800;
	// ori r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 | 32;
	// addi r8,r11,-160
	ctx.r8.s64 = r11.s64 + -160;
	// stw r10,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r10.u32);
	// stw r8,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r8.u32);
	// stb r9,10941(r31)
	PPC_STORE_U8(r31.u32 + 10941, ctx.r9.u8);
	// b 0x82412444
	goto loc_82412444;
loc_82412414:
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r11,r30,-4
	r11.s64 = r30.s64 + -4;
	// stw r30,14928(r31)
	PPC_STORE_U32(r31.u32 + 14928, r30.u32);
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// stw r29,14916(r31)
	PPC_STORE_U32(r31.u32 + 14916, r29.u32);
	// addi r10,r10,-14
	ctx.r10.s64 = ctx.r10.s64 + -14;
	// stw r29,14932(r31)
	PPC_STORE_U32(r31.u32 + 14932, r29.u32);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r11,-160
	ctx.r10.s64 = r11.s64 + -160;
	// stw r10,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r10.u32);
loc_82412444:
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// lwz r11,23932(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23932);
	// clrlwi. r11,r11,31
	r11.u64 = r11.u32 & 0x1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82412478
	if (!cr0.eq) goto loc_82412478;
	// lwz r4,14940(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 14940);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82412478
	if (cr6.eq) goto loc_82412478;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82411e98
	ctx.lr = 0x82412474;
	sub_82411E98(ctx, base);
	// stw r29,14940(r31)
	PPC_STORE_U32(r31.u32 + 14940, r29.u32);
loc_82412478:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8241247C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82412484"))) PPC_WEAK_FUNC(sub_82412484);
PPC_FUNC_IMPL(__imp__sub_82412484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82412488"))) PPC_WEAK_FUNC(sub_82412488);
PPC_FUNC_IMPL(__imp__sub_82412488) {
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
	ctx.lr = 0x82412490;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r11,13232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13232);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824124bc
	if (cr6.eq) goto loc_824124BC;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r3,r31,13368
	ctx.r3.s64 = r31.s64 + 13368;
	// bl 0x82412298
	ctx.lr = 0x824124B8;
	sub_82412298(ctx, base);
	// b 0x8241255c
	goto loc_8241255C;
loc_824124BC:
	// lwz r11,11008(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11008);
	// li r24,0
	r24.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8241254c
	if (cr6.eq) goto loc_8241254C;
	// rlwinm r11,r28,1,0,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0xFFFFFFFE;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r11,2
	ctx.r4.s64 = r11.s64 + 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82411840
	ctx.lr = 0x824124E0;
	sub_82411840(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// rlwinm r29,r28,3,0,28
	r29.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x823da950
	ctx.lr = 0x824124F8;
	sub_823DA950(ctx, base);
	// add r11,r29,r30
	r11.u64 = r29.u64 + r30.u64;
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// addi r27,r31,11012
	r27.s64 = r31.s64 + 11012;
	// addi r29,r11,4
	r29.s64 = r11.s64 + 4;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bl 0x827bd684
	ctx.lr = 0x82412514;
	__imp__KfAcquireSpinLock(ctx, base);
	// lwz r11,11008(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11008);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82412538
	if (cr6.eq) goto loc_82412538;
	// addi r5,r29,4
	ctx.r5.s64 = r29.s64 + 4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,13368
	ctx.r3.s64 = r31.s64 + 13368;
	// bl 0x82411578
	ctx.lr = 0x82412534;
	sub_82411578(ctx, base);
	// li r24,1
	r24.s64 = 1;
loc_82412538:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x827bd674
	ctx.lr = 0x82412544;
	__imp__KfReleaseSpinLock(ctx, base);
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// bne cr6,0x8241255c
	if (!cr6.eq) goto loc_8241255C;
loc_8241254C:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82411928
	ctx.lr = 0x8241255C;
	sub_82411928(ctx, base);
loc_8241255C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82412564"))) PPC_WEAK_FUNC(sub_82412564);
PPC_FUNC_IMPL(__imp__sub_82412564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82412568"))) PPC_WEAK_FUNC(sub_82412568);
PPC_FUNC_IMPL(__imp__sub_82412568) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// b 0x82412198
	sub_82412198(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82412584"))) PPC_WEAK_FUNC(sub_82412584);
PPC_FUNC_IMPL(__imp__sub_82412584) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82412588"))) PPC_WEAK_FUNC(sub_82412588);
PPC_FUNC_IMPL(__imp__sub_82412588) {
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
	ctx.lr = 0x82412590;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r10,10941(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r30,14928(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 14928);
	// rlwinm. r10,r10,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r28,r11,4
	r28.s64 = r11.s64 + 4;
	// bne 0x824126c8
	if (!cr0.eq) goto loc_824126C8;
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rlwinm. r11,r11,0,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82412624
	if (cr0.eq) goto loc_82412624;
	// lwz r11,13516(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13516);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824126c8
	if (cr6.eq) goto loc_824126C8;
	// lwz r11,152(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824126c8
	if (!cr6.eq) goto loc_824126C8;
	// subf r11,r30,r28
	r11.s64 = r28.s64 - r30.s64;
	// srawi. r29,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r29.s64 = r11.s32 >> 2;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// beq 0x824126c8
	if (cr0.eq) goto loc_824126C8;
	// lwz r11,13540(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13540);
	// lwz r3,13536(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 13536);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// blt cr6,0x824125f8
	if (cr6.lt) goto loc_824125F8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8241a6e0
	ctx.lr = 0x824125F8;
	sub_8241A6E0(ctx, base);
loc_824125F8:
	// rlwinm r11,r30,12,20,31
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r30,3
	ctx.r10.u64 = r30.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// oris r9,r29,33024
	ctx.r9.u64 = r29.u64 | 2164260864;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// addi r8,r3,8
	ctx.r8.s64 = ctx.r3.s64 + 8;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r8,13536(r31)
	PPC_STORE_U32(r31.u32 + 13536, ctx.r8.u32);
	// b 0x824126c8
	goto loc_824126C8;
loc_82412624:
	// lwz r11,13232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13232);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82412688
	if (cr6.eq) goto loc_82412688;
	// rlwinm r11,r30,12,20,31
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r30,3
	ctx.r10.u64 = r30.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// subf r9,r30,r28
	ctx.r9.s64 = r28.s64 - r30.s64;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// srawi. r30,r9,2
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	r30.s64 = ctx.r9.s32 >> 2;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// add r29,r11,r10
	r29.u64 = r11.u64 + ctx.r10.u64;
	// beq 0x824126c8
	if (cr0.eq) goto loc_824126C8;
	// lwz r11,13376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13376);
	// addi r3,r31,13368
	ctx.r3.s64 = r31.s64 + 13368;
	// lwz r10,13380(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 13380);
	// addi r9,r11,8
	ctx.r9.s64 = r11.s64 + 8;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// ble cr6,0x82412670
	if (!cr6.gt) goto loc_82412670;
	// bl 0x82412198
	ctx.lr = 0x8241266C;
	sub_82412198(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_82412670:
	// oris r10,r30,33024
	ctx.r10.u64 = r30.u64 | 2164260864;
	// stw r29,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r29.u32);
	// addi r9,r11,8
	ctx.r9.s64 = r11.s64 + 8;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stw r9,13376(r31)
	PPC_STORE_U32(r31.u32 + 13376, ctx.r9.u32);
	// b 0x824126c8
	goto loc_824126C8;
loc_82412688:
	// addi r4,r28,-4
	ctx.r4.s64 = r28.s64 + -4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82411cd0
	ctx.lr = 0x82412694;
	sub_82411CD0(ctx, base);
	// rlwinm r11,r30,12,20,31
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 12) & 0xFFF;
	// addi r4,r3,4
	ctx.r4.s64 = ctx.r3.s64 + 4;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// subf r9,r30,r4
	ctx.r9.s64 = ctx.r4.s64 - r30.s64;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// clrlwi r10,r30,3
	ctx.r10.u64 = r30.u32 & 0x1FFFFFFF;
	// addi r8,r31,13368
	ctx.r8.s64 = r31.s64 + 13368;
	// li r7,0
	ctx.r7.s64 = 0;
	// srawi r6,r9,2
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 2;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82411dc0
	ctx.lr = 0x824126C4;
	sub_82411DC0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_824126C8:
	// addi r11,r28,31
	r11.s64 = r28.s64 + 31;
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// rlwinm r9,r11,0,0,26
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFE0;
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// ble cr6,0x824126f4
	if (!cr6.gt) goto loc_824126F4;
	// addi r11,r28,-4
	r11.s64 = r28.s64 + -4;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412318
	ctx.lr = 0x824126F0;
	sub_82412318(ctx, base);
	// b 0x82412704
	goto loc_82412704;
loc_824126F4:
	// rlwinm r11,r11,0,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFE0;
	// addi r10,r11,-4
	ctx.r10.s64 = r11.s64 + -4;
	// stw r11,14928(r31)
	PPC_STORE_U32(r31.u32 + 14928, r11.u32);
	// stw r10,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r10.u32);
loc_82412704:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8241270C"))) PPC_WEAK_FUNC(sub_8241270C);
PPC_FUNC_IMPL(__imp__sub_8241270C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82412710"))) PPC_WEAK_FUNC(sub_82412710);
PPC_FUNC_IMPL(__imp__sub_82412710) {
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
	// lwz r11,10896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82412738
	if (cr6.eq) goto loc_82412738;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_82412738:
	// lwz r11,13232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 13232);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241279c
	if (!cr6.eq) goto loc_8241279C;
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rlwinm. r11,r11,0,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241279c
	if (!cr0.eq) goto loc_8241279C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82411b10
	ctx.lr = 0x82412760;
	sub_82411B10(ctx, base);
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8241279c
	if (cr6.eq) goto loc_8241279C;
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82411840
	ctx.lr = 0x8241277C;
	sub_82411840(ctx, base);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq 0x8241279c
	if (cr0.eq) goto loc_8241279C;
	// addi r8,r31,13368
	ctx.r8.s64 = r31.s64 + 13368;
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82411dc0
	ctx.lr = 0x8241279C;
	sub_82411DC0(ctx, base);
loc_8241279C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412588
	ctx.lr = 0x824127A4;
	sub_82412588(ctx, base);
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rlwinm. r11,r11,0,0,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x824127f4
	if (!cr0.eq) goto loc_824127F4;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-9716(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -9716);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x824127f4
	if (cr6.eq) goto loc_824127F4;
	// lbz r11,10941(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x824127f4
	if (!cr0.eq) goto loc_824127F4;
	// lwz r11,10908(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10908);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-2
	ctx.r4.s64 = r11.s64 + -2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82411e98
	ctx.lr = 0x824127E8;
	sub_82411E98(ctx, base);
	// lbz r11,10941(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// stb r11,10941(r31)
	PPC_STORE_U8(r31.u32 + 10941, r11.u8);
loc_824127F4:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
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

__attribute__((alias("__imp__sub_82412810"))) PPC_WEAK_FUNC(sub_82412810);
PPC_FUNC_IMPL(__imp__sub_82412810) {
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
	// lwz r31,10908(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10908);
	// stw r31,10928(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10928, r31.u32);
	// bl 0x82412710
	ctx.lr = 0x8241282C;
	sub_82412710(ctx, base);
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

__attribute__((alias("__imp__sub_82412844"))) PPC_WEAK_FUNC(sub_82412844);
PPC_FUNC_IMPL(__imp__sub_82412844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82412848"))) PPC_WEAK_FUNC(sub_82412848);
PPC_FUNC_IMPL(__imp__sub_82412848) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824128a8
	if (cr6.eq) goto loc_824128A8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r11,2148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2148);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,10908(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10908);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x82412888
	if (!cr6.eq) goto loc_82412888;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82412888;
	sub_82412710(ctx, base);
loc_82412888:
	// lwz r11,10896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// lwz r10,10908(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10908);
	// subf r9,r30,r10
	ctx.r9.s64 = ctx.r10.s64 - r30.s64;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// subfc r11,r11,r9
	xer.ca = ctx.r9.u32 >= r11.u32;
	r11.s64 = ctx.r9.s64 - r11.s64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r11,31
	ctx.r3.u64 = r11.u32 & 0x1;
loc_824128A8:
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

__attribute__((alias("__imp__sub_824128C0"))) PPC_WEAK_FUNC(sub_824128C0);
PPC_FUNC_IMPL(__imp__sub_824128C0) {
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
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x824128ec
	if (!cr6.gt) goto loc_824128EC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x824128EC;
	sub_82412710(ctx, base);
loc_824128EC:
	// li r11,1480
	r11.s64 = 1480;
	// lis r10,2
	ctx.r10.s64 = 131072;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// li r11,3332
	r11.s64 = 3332;
	// li r9,0
	ctx.r9.s64 = 0;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r9,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r3.u32 = ea;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82412924"))) PPC_WEAK_FUNC(sub_82412924);
PPC_FUNC_IMPL(__imp__sub_82412924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82412928"))) PPC_WEAK_FUNC(sub_82412928);
PPC_FUNC_IMPL(__imp__sub_82412928) {
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
	ctx.lr = 0x82412930;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// rlwinm r30,r29,2,0,29
	r30.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x82412984
	if (!cr6.gt) goto loc_82412984;
	// bl 0x82412710
	ctx.lr = 0x82412958;
	sub_82412710(ctx, base);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x82412984
	if (!cr6.gt) goto loc_82412984;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412318
	ctx.lr = 0x82412978;
	sub_82412318(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// beq 0x82412988
	if (cr0.eq) goto loc_82412988;
loc_82412984:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
loc_82412988:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82412990"))) PPC_WEAK_FUNC(sub_82412990);
PPC_FUNC_IMPL(__imp__sub_82412990) {
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
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x824129bc
	if (!cr6.gt) goto loc_824129BC;
	// bl 0x82412710
	ctx.lr = 0x824129B8;
	sub_82412710(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_824129BC:
	// li r10,1480
	ctx.r10.s64 = 1480;
	// lis r9,2
	ctx.r9.s64 = 131072;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// lwz r4,10908(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 10908);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// bl 0x82411e98
	ctx.lr = 0x824129E8;
	sub_82411E98(ctx, base);
loc_824129E8:
	// lwz r11,11008(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 11008);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824129e8
	if (!cr6.eq) goto loc_824129E8;
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82412A08"))) PPC_WEAK_FUNC(sub_82412A08);
PPC_FUNC_IMPL(__imp__sub_82412A08) {
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
	ctx.lr = 0x82412A10;
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
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// ble cr6,0x82412a3c
	if (!cr6.gt) goto loc_82412A3C;
	// bl 0x82412710
	ctx.lr = 0x82412A38;
	sub_82412710(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
loc_82412A3C:
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82411f68
	ctx.lr = 0x82412A50;
	sub_82411F68(ctx, base);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82412A5C"))) PPC_WEAK_FUNC(sub_82412A5C);
PPC_FUNC_IMPL(__imp__sub_82412A5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82412A60"))) PPC_WEAK_FUNC(sub_82412A60);
PPC_FUNC_IMPL(__imp__sub_82412A60) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82412A68;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lwz r11,10908(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10908);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82412aac
	if (cr6.eq) goto loc_82412AAC;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82412aac
	if (cr6.eq) goto loc_82412AAC;
	// bl 0x82412990
	ctx.lr = 0x82412A90;
	sub_82412990(ctx, base);
	// b 0x82412a9c
	goto loc_82412A9C;
loc_82412A94:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8244fec0
	ctx.lr = 0x82412A9C;
	sub_8244FEC0(ctx, base);
loc_82412A9C:
	// lwz r10,10984(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10984);
	// lwz r11,10988(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10988);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82412a94
	if (!cr6.eq) goto loc_82412A94;
loc_82412AAC:
	// lwz r11,14904(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 14904);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82412af8
	if (cr6.eq) goto loc_82412AF8;
	// lwz r8,14908(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 14908);
	// rlwinm r10,r11,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r9,r11,3
	ctx.r9.u64 = r11.u32 & 0x1FFFFFFF;
	// rlwinm r11,r8,12,20,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 12) & 0xFFF;
	// addi r7,r10,512
	ctx.r7.s64 = ctx.r10.s64 + 512;
	// addi r10,r11,512
	ctx.r10.s64 = r11.s64 + 512;
	// clrlwi r11,r8,3
	r11.u64 = ctx.r8.u32 & 0x1FFFFFFF;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// rlwinm r8,r7,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x1000;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lis r7,16384
	ctx.r7.s64 = 1073741824;
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// subf r4,r7,r11
	ctx.r4.s64 = r11.s64 - ctx.r7.s64;
	// subf r3,r7,r10
	ctx.r3.s64 = ctx.r10.s64 - ctx.r7.s64;
	// bl 0x82425cd8
	ctx.lr = 0x82412AF8;
	sub_82425CD8(ctx, base);
loc_82412AF8:
	// lis r30,-20096
	r30.s64 = -1317011456;
	// lwz r3,14836(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 14836);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821310f8
	ctx.lr = 0x82412B08;
	sub_821310F8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,14840(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 14840);
	// bl 0x821310f8
	ctx.lr = 0x82412B14;
	sub_821310F8(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r29,14836(r31)
	PPC_STORE_U32(r31.u32 + 14836, r29.u32);
	// stw r29,14840(r31)
	PPC_STORE_U32(r31.u32 + 14840, r29.u32);
	// stw r29,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r29.u32);
	// stw r29,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r29.u32);
	// bl 0x827bd6c4
	ctx.lr = 0x82412B30;
	__imp__VdSetSystemCommandBufferGpuIdentifierAddress(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,10900(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10900);
	// bl 0x821310f8
	ctx.lr = 0x82412B3C;
	sub_821310F8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,10896(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// bl 0x821310f8
	ctx.lr = 0x82412B48;
	sub_821310F8(ctx, base);
	// stw r29,10900(r31)
	PPC_STORE_U32(r31.u32 + 10900, r29.u32);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// stw r29,10896(r31)
	PPC_STORE_U32(r31.u32 + 10896, r29.u32);
	// bne cr6,0x82412b60
	if (!cr6.eq) goto loc_82412B60;
loc_82412B58:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82412e94
	goto loc_82412E94;
loc_82412B60:
	// lwz r25,4(r26)
	r25.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// lwz r27,8(r26)
	r27.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// lwz r28,12(r26)
	r28.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// lwz r30,16(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// lwz r11,20(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 20);
	// bne cr6,0x82412b84
	if (!cr6.eq) goto loc_82412B84;
	// lis r25,0
	r25.s64 = 0;
	// ori r25,r25,32768
	r25.u64 = r25.u64 | 32768;
loc_82412B84:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x82412b90
	if (!cr6.eq) goto loc_82412B90;
	// lis r28,32
	r28.s64 = 2097152;
loc_82412B90:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82412b9c
	if (!cr6.eq) goto loc_82412B9C;
	// li r11,32
	r11.s64 = 32;
loc_82412B9C:
	// divwu r26,r28,r11
	r26.u32 = r28.u32 / r11.u32;
	// twllei r11,0
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x82412bc0
	if (!cr6.eq) goto loc_82412BC0;
	// lis r4,-19072
	ctx.r4.s64 = -1249902592;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82130b50
	ctx.lr = 0x82412BB8;
	sub_82130B50(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stw r27,14836(r31)
	PPC_STORE_U32(r31.u32 + 14836, r27.u32);
loc_82412BC0:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82412bec
	if (!cr6.eq) goto loc_82412BEC;
	// lis r11,8
	r11.s64 = 524288;
	// lis r4,-30848
	ctx.r4.s64 = -2021654528;
	// subfc r11,r11,r28
	xer.ca = r28.u32 >= r11.u32;
	r11.s64 = r28.s64 - r11.s64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// subfe r11,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	r11.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwimi r4,r11,28,2,3
	ctx.r4.u64 = (__builtin_rotateleft32(r11.u32, 28) & 0x30000000) | (ctx.r4.u64 & 0xFFFFFFFFCFFFFFFF);
	// bl 0x82130b50
	ctx.lr = 0x82412BE4;
	sub_82130B50(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r30,14840(r31)
	PPC_STORE_U32(r31.u32 + 14840, r30.u32);
loc_82412BEC:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82412e8c
	if (cr6.eq) goto loc_82412E8C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82412e8c
	if (cr6.eq) goto loc_82412E8C;
	// lis r4,-23168
	ctx.r4.s64 = -1518338048;
	// li r3,96
	ctx.r3.s64 = 96;
	// bl 0x82130b50
	ctx.lr = 0x82412C08;
	sub_82130B50(ctx, base);
	// stw r3,10896(r31)
	PPC_STORE_U32(r31.u32 + 10896, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82412e8c
	if (cr0.eq) goto loc_82412E8C;
	// lis r4,-27264
	ctx.r4.s64 = -1786773504;
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130b50
	ctx.lr = 0x82412C20;
	sub_82130B50(ctx, base);
	// stw r3,10900(r31)
	PPC_STORE_U32(r31.u32 + 10900, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82412e8c
	if (cr0.eq) goto loc_82412E8C;
	// li r5,96
	ctx.r5.s64 = 96;
	// lwz r3,10896(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823d9890
	ctx.lr = 0x82412C3C;
	sub_823D9890(ctx, base);
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,10900(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10900);
	// bl 0x823d9890
	ctx.lr = 0x82412C4C;
	sub_823D9890(ctx, base);
	// cntlzw r11,r25
	r11.u64 = r25.u32 == 0 ? 32 : __builtin_clz(r25.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// subfic r24,r11,28
	xer.ca = r11.u32 <= 28;
	r24.s64 = 28 - r11.s64;
	// bl 0x827bd5f4
	ctx.lr = 0x82412C5C;
	__imp__MmGetPhysicalAddress(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x827bd6b4
	ctx.lr = 0x82412C64;
	__imp__VdInitializeRingBuffer(ctx, base);
	// rlwinm r11,r25,23,9,31
	r11.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 23) & 0x7FFFFF;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// subfic r4,r11,31
	xer.ca = r11.u32 <= 31;
	ctx.r4.s64 = 31 - r11.s64;
	// cmplwi cr6,r4,19
	cr6.compare<uint32_t>(ctx.r4.u32, 19, xer);
	// ble cr6,0x82412c7c
	if (!cr6.gt) goto loc_82412C7C;
	// li r4,19
	ctx.r4.s64 = 19;
loc_82412C7C:
	// lwz r11,10896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// addi r11,r11,60
	r11.s64 = r11.s64 + 60;
	// rlwinm r10,r11,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 12) & 0xFFF;
	// clrlwi r11,r11,3
	r11.u64 = r11.u32 & 0x1FFFFFFF;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x827bd6a4
	ctx.lr = 0x82412C9C;
	__imp__VdEnableRingBufferRPtrWriteBack(ctx, base);
	// rlwinm r11,r28,0,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 0) & 0xFFFFFFFC;
	// lis r9,2989
	ctx.r9.s64 = 195887104;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// ori r7,r9,61453
	ctx.r7.u64 = ctx.r9.u64 | 61453;
	// rlwinm r8,r25,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r10,r26,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 0) & 0xFFFFFFFC;
	// addi r9,r11,-4
	ctx.r9.s64 = r11.s64 + -4;
	// stw r7,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r7.u32);
	// rlwinm r11,r28,30,2,31
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 30) & 0x3FFFFFFF;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// stw r9,14908(r31)
	PPC_STORE_U32(r31.u32 + 14908, ctx.r9.u32);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// stw r11,14936(r31)
	PPC_STORE_U32(r31.u32 + 14936, r11.u32);
	// stw r27,14896(r31)
	PPC_STORE_U32(r31.u32 + 14896, r27.u32);
	// addi r9,r30,-4
	ctx.r9.s64 = r30.s64 + -4;
	// stw r30,14904(r31)
	PPC_STORE_U32(r31.u32 + 14904, r30.u32);
	// addi r7,r10,-160
	ctx.r7.s64 = ctx.r10.s64 + -160;
	// stw r30,14924(r31)
	PPC_STORE_U32(r31.u32 + 14924, r30.u32);
	// stw r30,14928(r31)
	PPC_STORE_U32(r31.u32 + 14928, r30.u32);
	// stw r26,14912(r31)
	PPC_STORE_U32(r31.u32 + 14912, r26.u32);
	// stw r8,14900(r31)
	PPC_STORE_U32(r31.u32 + 14900, ctx.r8.u32);
	// lwz r11,10896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// stw r29,60(r11)
	PPC_STORE_U32(r11.u32 + 60, r29.u32);
	// lwz r11,10908(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10908);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r29,10952(r31)
	PPC_STORE_U32(r31.u32 + 10952, r29.u32);
	// stw r9,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r9.u32);
	// stw r10,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r10.u32);
	// stw r7,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r7.u32);
	// stw r29,14916(r31)
	PPC_STORE_U32(r31.u32 + 14916, r29.u32);
	// bne cr6,0x82412d20
	if (!cr6.eq) goto loc_82412D20;
	// li r11,3
	r11.s64 = 3;
	// stw r11,10908(r31)
	PPC_STORE_U32(r31.u32 + 10908, r11.u32);
loc_82412D20:
	// lwz r11,10908(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10908);
	// lwz r10,10896(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r10,10896(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// lwz r9,14920(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 14920);
	// clrlwi r9,r9,30
	ctx.r9.u64 = ctx.r9.u32 & 0x3;
	// or r11,r9,r11
	r11.u64 = ctx.r9.u64 | r11.u64;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// lwz r11,10896(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10896);
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x827bd6c4
	ctx.lr = 0x82412D54;
	__imp__VdSetSystemCommandBufferGpuIdentifierAddress(ctx, base);
	// lis r10,-16367
	ctx.r10.s64 = -1072627712;
	// lis r11,-32250
	r11.s64 = -2113536000;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
	// ori r9,r10,18432
	ctx.r9.u64 = ctx.r10.u64 | 18432;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// li r8,1023
	ctx.r8.s64 = 1023;
	// addi r10,r11,6916
	ctx.r10.s64 = r11.s64 + 6916;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// li r11,8
	r11.s64 = 8;
	// mtctr r11
	ctr.u64 = r11.u64;
loc_82412D84:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x82412d84
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82412D84;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r29,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r29.u32);
	// li r11,2048
	r11.s64 = 2048;
	// stw r29,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r29.u32);
	// li r9,7
	ctx.r9.s64 = 7;
	// sth r10,10924(r31)
	PPC_STORE_U16(r31.u32 + 10924, ctx.r10.u16);
	// sth r11,10926(r31)
	PPC_STORE_U16(r31.u32 + 10926, r11.u16);
	// li r4,19
	ctx.r4.s64 = 19;
	// sth r11,130(r1)
	PPC_STORE_U16(ctx.r1.u32 + 130, r11.u16);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// sth r10,128(r1)
	PPC_STORE_U16(ctx.r1.u32 + 128, ctx.r10.u16);
	// stw r9,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r9.u32);
	// stw r29,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r29.u32);
	// stw r29,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r29.u32);
	// stw r29,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r29.u32);
	// bl 0x827bd694
	ctx.lr = 0x82412DD8;
	__imp__KiApcNormalRoutineNop(ctx, base);
	// li r5,19
	ctx.r5.s64 = 19;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824112c8
	ctx.lr = 0x82412DE8;
	sub_824112C8(ctx, base);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x82412e00
	if (!cr6.gt) goto loc_82412E00;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82412E00;
	sub_82412710(ctx, base);
loc_82412E00:
	// li r11,3330
	r11.s64 = 3330;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// lis r11,3
	r11.s64 = 196608;
	// ori r10,r10,2048
	ctx.r10.u64 = ctx.r10.u64 | 2048;
	// ori r11,r11,2562
	r11.u64 = r11.u64 | 2562;
	// lis r9,-16368
	ctx.r9.s64 = -1072693248;
	// lis r8,2032
	ctx.r8.s64 = 133169152;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lis r7,-16384
	ctx.r7.s64 = -1073741824;
	// lis r10,16
	ctx.r10.s64 = 1048576;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r6,477
	ctx.r6.s64 = 477;
	// li r4,476
	ctx.r4.s64 = 476;
	// lis r30,2
	r30.s64 = 131072;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stwu r11,4(r5)
	ea = 4 + ctx.r5.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r5.u32 = ea;
	// ori r30,r30,55
	r30.u64 = r30.u64 | 55;
	// stwu r9,4(r5)
	ea = 4 + ctx.r5.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r5.u32 = ea;
	// stwu r8,4(r5)
	ea = 4 + ctx.r5.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r5.u32 = ea;
	// stwu r7,4(r5)
	ea = 4 + ctx.r5.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r5.u32 = ea;
	// stwu r10,4(r5)
	ea = 4 + ctx.r5.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r5.u32 = ea;
	// stwu r6,4(r5)
	ea = 4 + ctx.r5.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r5.u32 = ea;
	// lwz r10,10900(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10900);
	// rlwinm r11,r10,12,20,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r10,3
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stwu r11,4(r5)
	ea = 4 + ctx.r5.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r5.u32 = ea;
	// stwu r4,4(r5)
	ea = 4 + ctx.r5.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	ctx.r5.u32 = ea;
	// stwu r30,4(r5)
	ea = 4 + ctx.r5.u32;
	PPC_STORE_U32(ea, r30.u32);
	ctx.r5.u32 = ea;
	// stw r5,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r5.u32);
	// bl 0x824128c0
	ctx.lr = 0x82412E88;
	sub_824128C0(ctx, base);
	// b 0x82412b58
	goto loc_82412B58;
loc_82412E8C:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
loc_82412E94:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82412E9C"))) PPC_WEAK_FUNC(sub_82412E9C);
PPC_FUNC_IMPL(__imp__sub_82412E9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82412EA0"))) PPC_WEAK_FUNC(sub_82412EA0);
PPC_FUNC_IMPL(__imp__sub_82412EA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// lwz r11,256(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 256);
	// lwz r10,10896(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 10896);
	// lwz r11,88(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// mftb r11
	r11.u64 = __rdtsc();
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82412ED0"))) PPC_WEAK_FUNC(sub_82412ED0);
PPC_FUNC_IMPL(__imp__sub_82412ED0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82412f84
	if (cr6.eq) goto loc_82412F84;
	// mftb r11
	r11.u64 = __rdtsc();
	// lwz r10,256(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 256);
	// lwz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lwz r10,88(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	// cmpwi cr6,r7,3
	cr6.compare<int32_t>(ctx.r7.s32, 3, xer);
	// subf r6,r8,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r8.s64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bne cr6,0x82412f2c
	if (!cr6.eq) goto loc_82412F2C;
	// ld r9,21608(r10)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r10.u32 + 21608);
	// clrldi r8,r11,32
	ctx.r8.u64 = r11.u64 & 0xFFFFFFFF;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// std r9,21608(r10)
	PPC_STORE_U64(ctx.r10.u32 + 21608, ctx.r9.u64);
	// b 0x82412f3c
	goto loc_82412F3C;
loc_82412F2C:
	// ld r8,21600(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + 21600);
	// clrldi r9,r11,32
	ctx.r9.u64 = r11.u64 & 0xFFFFFFFF;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// std r9,21600(r10)
	PPC_STORE_U64(ctx.r10.u32 + 21600, ctx.r9.u64);
loc_82412F3C:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,13436(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 13436);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82412f84
	if (cr6.eq) goto loc_82412F84;
	// clrldi r11,r11,32
	r11.u64 = r11.u64 & 0xFFFFFFFF;
	// lfs f13,21592(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 21592);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// li r3,0
	ctx.r3.s64 = 0;
	// frsp f12,f0
	ctx.f12.f64 = double(float(f0.f64));
	// lfs f0,11364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11364);
	f0.f64 = double(temp.f32);
	// fmuls f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82412F84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82412F84:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82412F94"))) PPC_WEAK_FUNC(sub_82412F94);
PPC_FUNC_IMPL(__imp__sub_82412F94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82412F98"))) PPC_WEAK_FUNC(sub_82412F98);
PPC_FUNC_IMPL(__imp__sub_82412F98) {
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
	ctx.lr = 0x82412FA0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,4
	r11.s64 = 4;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
loc_82412FB0:
	// db16cyc 
	// db16cyc 
	// db16cyc 
	// db16cyc 
	// db16cyc 
	// db16cyc 
	// db16cyc 
	// db16cyc 
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82412fb0
	if (!cr0.eq) goto loc_82412FB0;
	// lbz r11,10941(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 10941);
	// rlwinm. r11,r11,0,30,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x8241305c
	if (!cr0.eq) goto loc_8241305C;
	// lwz r11,10896(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 10896);
	// lwz r10,256(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 256);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r30,88(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// beq cr6,0x8241300c
	if (cr6.eq) goto loc_8241300C;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
loc_8241300C:
	// bl 0x8244fec8
	ctx.lr = 0x82413010;
	sub_8244FEC8(ctx, base);
	// lwz r11,10888(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 10888);
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// bne cr6,0x8241302c
	if (!cr6.eq) goto loc_8241302C;
	// lwz r11,11004(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 11004);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8241302c
	if (cr6.eq) goto loc_8241302C;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
loc_8241302C:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// subf r11,r11,r30
	r11.s64 = r30.s64 - r11.s64;
	// cmplwi cr6,r11,5000
	cr6.compare<uint32_t>(r11.u32, 5000, xer);
	// bge cr6,0x82413044
	if (!cr6.lt) goto loc_82413044;
loc_8241303C:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82413060
	goto loc_82413060;
loc_82413044:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82425c18
	ctx.lr = 0x8241304C;
	sub_82425C18(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x8241305c
	if (!cr0.eq) goto loc_8241305C;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// b 0x8241303c
	goto loc_8241303C;
loc_8241305C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82413060:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82413068"))) PPC_WEAK_FUNC(sub_82413068);
PPC_FUNC_IMPL(__imp__sub_82413068) {
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
	// lis r4,-19072
	ctx.r4.s64 = -1249902592;
	// li r3,4096
	ctx.r3.s64 = 4096;
	// bl 0x82130b50
	ctx.lr = 0x8241308C;
	sub_82130B50(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,23936(r31)
	PPC_STORE_U32(r31.u32 + 23936, ctx.r3.u32);
	// bne 0x824130a0
	if (!cr0.eq) goto loc_824130A0;
loc_82413098:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x824131ac
	goto loc_824131AC;
loc_824130A0:
	// lis r4,25728
	ctx.r4.s64 = 1686110208;
	// li r3,512
	ctx.r3.s64 = 512;
	// bl 0x82130b50
	ctx.lr = 0x824130AC;
	sub_82130B50(ctx, base);
	// stw r3,23944(r31)
	PPC_STORE_U32(r31.u32 + 23944, ctx.r3.u32);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82413098
	if (cr0.eq) goto loc_82413098;
	// lwz r11,23936(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23936);
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// li r9,768
	ctx.r9.s64 = 768;
	// addi r11,r11,156
	r11.s64 = r11.s64 + 156;
	// ori r10,r10,15104
	ctx.r10.u64 = ctx.r10.u64 | 15104;
	// lis r8,-16359
	ctx.r8.s64 = -1072103424;
	// li r7,0
	ctx.r7.s64 = 0;
	// ori r8,r8,11008
	ctx.r8.u64 = ctx.r8.u64 | 11008;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// li r10,24
	ctx.r10.s64 = 24;
	// lis r6,-32250
	ctx.r6.s64 = -2113536000;
	// li r5,96
	ctx.r5.s64 = 96;
	// addi r4,r6,6952
	ctx.r4.s64 = ctx.r6.s64 + 6952;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// stwu r8,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r11.u32 = ea;
	// stwu r7,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r11.u32 = ea;
	// mr r30,r11
	r30.u64 = r11.u64;
	// stwu r10,4(r30)
	ea = 4 + r30.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r30.u32 = ea;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x823da950
	ctx.lr = 0x82413108;
	sub_823DA950(ctx, base);
	// addi r11,r30,96
	r11.s64 = r30.s64 + 96;
	// li r10,8709
	ctx.r10.s64 = 8709;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// li r8,1
	ctx.r8.s64 = 1;
	// ori r9,r9,8576
	ctx.r9.u64 = ctx.r9.u64 | 8576;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,10568(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 10568);
	// li r10,15
	ctx.r10.s64 = 15;
	// rlwinm r6,r6,0,29,20
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFF807;
	// stwu r6,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	r11.u32 = ea;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// stwu r8,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r11.u32 = ea;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// stwu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// lwz r9,23936(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 23936);
	// rlwinm r11,r9,12,20,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFF;
	// clrlwi r9,r9,3
	ctx.r9.u64 = ctx.r9.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	r11.s64 = r11.s64 + 512;
	// rlwinm r11,r11,0,19,19
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
loc_8241315C:
	// lis r9,-16381
	ctx.r9.s64 = -1073545216;
	// li r7,0
	ctx.r7.s64 = 0;
	// ori r9,r9,8705
	ctx.r9.u64 = ctx.r9.u64 | 8705;
	// lis r6,3
	ctx.r6.s64 = 196608;
	// stwu r9,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r8.u32 = ea;
	// lis r9,16384
	ctx.r9.s64 = 1073741824;
	// ori r6,r6,4
	ctx.r6.u64 = ctx.r6.u64 | 4;
	// ori r9,r9,3
	ctx.r9.u64 = ctx.r9.u64 | 3;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stwu r7,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r8.u32 = ea;
	// stwu r6,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	ctx.r8.u32 = ea;
	// stwu r11,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r8.u32 = ea;
	// stwu r9,4(r8)
	ea = 4 + ctx.r8.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	ctx.r8.u32 = ea;
	// bne 0x8241315c
	if (!cr0.eq) goto loc_8241315C;
	// lwz r11,23936(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 23936);
	// li r3,1
	ctx.r3.s64 = 1;
	// subf r11,r11,r8
	r11.s64 = ctx.r8.s64 - r11.s64;
	// addi r11,r11,-156
	r11.s64 = r11.s64 + -156;
	// srawi r11,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r11.s64 = r11.s32 >> 2;
	// stw r11,23940(r31)
	PPC_STORE_U32(r31.u32 + 23940, r11.u32);
loc_824131AC:
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

__attribute__((alias("__imp__sub_824131C4"))) PPC_WEAK_FUNC(sub_824131C4);
PPC_FUNC_IMPL(__imp__sub_824131C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824131C8"))) PPC_WEAK_FUNC(sub_824131C8);
PPC_FUNC_IMPL(__imp__sub_824131C8) {
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
	// lis r4,-20096
	ctx.r4.s64 = -1317011456;
	// lwz r3,23936(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 23936);
	// bl 0x821310f8
	ctx.lr = 0x824131E8;
	sub_821310F8(ctx, base);
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// lwz r3,23944(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 23944);
	// bl 0x821310f8
	ctx.lr = 0x824131F4;
	sub_821310F8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,23936(r31)
	PPC_STORE_U32(r31.u32 + 23936, r11.u32);
	// stw r11,23944(r31)
	PPC_STORE_U32(r31.u32 + 23944, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82413214"))) PPC_WEAK_FUNC(sub_82413214);
PPC_FUNC_IMPL(__imp__sub_82413214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413218"))) PPC_WEAK_FUNC(sub_82413218);
PPC_FUNC_IMPL(__imp__sub_82413218) {
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
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82413250
	if (!cr6.eq) goto loc_82413250;
	// bl 0x82426840
	ctx.lr = 0x8241323C;
	sub_82426840(ctx, base);
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// lwz r3,-4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// bl 0x821310f8
	ctx.lr = 0x82413248;
	sub_821310F8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82413258
	goto loc_82413258;
loc_82413250:
	// addi r3,r11,-1
	ctx.r3.s64 = r11.s64 + -1;
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
loc_82413258:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8241326C"))) PPC_WEAK_FUNC(sub_8241326C);
PPC_FUNC_IMPL(__imp__sub_8241326C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413270"))) PPC_WEAK_FUNC(sub_82413270);
PPC_FUNC_IMPL(__imp__sub_82413270) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r30,72
	ctx.r4.s64 = r30.s64 + 72;
	// bl 0x82412a60
	ctx.lr = 0x82413294;
	sub_82412A60(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x824132d8
	if (!cr0.eq) goto loc_824132D8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412990
	ctx.lr = 0x824132A4;
	sub_82412990(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82426268
	ctx.lr = 0x824132AC;
	sub_82426268(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82426028
	ctx.lr = 0x824132B8;
	sub_82426028(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x824132d4
	if (!cr0.eq) goto loc_824132D4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82426268
	ctx.lr = 0x824132C8;
	sub_82426268(ctx, base);
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x824132d8
	goto loc_824132D8;
loc_824132D4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824132D8:
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

__attribute__((alias("__imp__sub_824132F0"))) PPC_WEAK_FUNC(sub_824132F0);
PPC_FUNC_IMPL(__imp__sub_824132F0) {
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
	// lwz r11,10888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10888);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82413314
	if (cr6.eq) goto loc_82413314;
	// bl 0x8244fec8
	ctx.lr = 0x82413314;
	sub_8244FEC8(ctx, base);
loc_82413314:
	// bl 0x8244fec8
	ctx.lr = 0x82413318;
	sub_8244FEC8(ctx, base);
	// stw r3,10888(r31)
	PPC_STORE_U32(r31.u32 + 10888, ctx.r3.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82413330"))) PPC_WEAK_FUNC(sub_82413330);
PPC_FUNC_IMPL(__imp__sub_82413330) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// eieio 
	// li r11,0
	r11.s64 = 0;
	// stw r11,10888(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10888, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413340"))) PPC_WEAK_FUNC(sub_82413340);
PPC_FUNC_IMPL(__imp__sub_82413340) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x82413374
	if (!cr6.gt) goto loc_82413374;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82413374;
	sub_82412710(ctx, base);
loc_82413374:
	// lis r11,-16384
	r11.s64 = -1073741824;
	// li r10,15
	ctx.r10.s64 = 15;
	// ori r11,r11,17920
	r11.u64 = r11.u64 | 17920;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// bne cr6,0x824133a4
	if (!cr6.eq) goto loc_824133A4;
	// li r10,1480
	ctx.r10.s64 = 1480;
	// lis r9,2
	ctx.r9.s64 = 131072;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
loc_824133A4:
	// lbz r10,10941(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10941);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// andi. r11,r10,251
	r11.u64 = ctx.r10.u64 & 251;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stb r11,10941(r31)
	PPC_STORE_U8(r31.u32 + 10941, r11.u8);
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

__attribute__((alias("__imp__sub_824133CC"))) PPC_WEAK_FUNC(sub_824133CC);
PPC_FUNC_IMPL(__imp__sub_824133CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824133D0"))) PPC_WEAK_FUNC(sub_824133D0);
PPC_FUNC_IMPL(__imp__sub_824133D0) {
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
	ctx.lr = 0x824133D8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,12440
	r29.s64 = r31.s64 + 12440;
loc_824133E8:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,14832(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 14832);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x82413408
	if (cr6.eq) goto loc_82413408;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82416670
	ctx.lr = 0x82413408;
	sub_82416670(ctx, base);
loc_82413408:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmplwi cr6,r30,4
	cr6.compare<uint32_t>(r30.u32, 4, xer);
	// blt cr6,0x824133e8
	if (cr6.lt) goto loc_824133E8;
	// lwz r11,12456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12456);
	// lwz r10,14824(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 14824);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x82413434
	if (cr6.eq) goto loc_82413434;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824169d0
	ctx.lr = 0x82413434;
	sub_824169D0(ctx, base);
loc_82413434:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82417c70
	ctx.lr = 0x82413440;
	sub_82417C70(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824179b8
	ctx.lr = 0x8241344C;
	sub_824179B8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82417e88
	ctx.lr = 0x82413458;
	sub_82417E88(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82415ee8
	ctx.lr = 0x82413464;
	sub_82415EE8(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// li r30,0
	r30.s64 = 0;
	// rldicr r29,r11,63,63
	r29.u64 = __builtin_rotateleft64(r11.u64, 63) & 0xFFFFFFFFFFFFFFFF;
loc_82413470:
	// subfic r11,r30,95
	xer.ca = r30.u32 <= 95;
	r11.s64 = 95 - r30.s64;
	// li r7,4
	ctx.r7.s64 = 4;
	// mulli r11,r11,21846
	r11.s64 = r11.s64 * 21846;
	// rlwinm r11,r11,16,16,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFFFF;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// clrldi r11,r11,32
	r11.u64 = r11.u64 & 0xFFFFFFFF;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// srd r8,r29,r11
	ctx.r8.u64 = r11.u8 & 0x40 ? 0 : (r29.u64 >> (r11.u8 & 0x7F));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82415dc8
	ctx.lr = 0x824134A0;
	sub_82415DC8(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplwi cr6,r30,16
	cr6.compare<uint32_t>(r30.u32, 16, xer);
	// blt cr6,0x82413470
	if (cr6.lt) goto loc_82413470;
	// li r30,0
	r30.s64 = 0;
loc_824134B0:
	// addi r11,r30,32
	r11.s64 = r30.s64 + 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// clrldi r11,r11,32
	r11.u64 = r11.u64 & 0xFFFFFFFF;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// srd r6,r29,r11
	ctx.r6.u64 = r11.u8 & 0x40 ? 0 : (r29.u64 >> (r11.u8 & 0x7F));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82410f88
	ctx.lr = 0x824134CC;
	sub_82410F88(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplwi cr6,r30,26
	cr6.compare<uint32_t>(r30.u32, 26, xer);
	// blt cr6,0x824134b0
	if (cr6.lt) goto loc_824134B0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_824134E0"))) PPC_WEAK_FUNC(sub_824134E0);
PPC_FUNC_IMPL(__imp__sub_824134E0) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + r31.u64;
	// bl 0x82130b50
	ctx.lr = 0x82413500;
	sub_82130B50(ctx, base);
	// cmplwi r3,0
	cr0.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq 0x82413520
	if (cr0.eq) goto loc_82413520;
	// add r11,r3,r31
	r11.u64 = ctx.r3.u64 + r31.u64;
	// addi r10,r31,-1
	ctx.r10.s64 = r31.s64 + -1;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// andc r11,r11,r10
	r11.u64 = r11.u64 & ~ctx.r10.u64;
	// stw r3,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r3.u32);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
loc_82413520:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82413534"))) PPC_WEAK_FUNC(sub_82413534);
PPC_FUNC_IMPL(__imp__sub_82413534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413538"))) PPC_WEAK_FUNC(sub_82413538);
PPC_FUNC_IMPL(__imp__sub_82413538) {
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
	// bl 0x824134e0
	ctx.lr = 0x82413554;
	sub_824134E0(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x8241356c
	if (cr0.eq) goto loc_8241356C;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823d9890
	ctx.lr = 0x8241356C;
	sub_823D9890(ctx, base);
loc_8241356C:
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

__attribute__((alias("__imp__sub_82413588"))) PPC_WEAK_FUNC(sub_82413588);
PPC_FUNC_IMPL(__imp__sub_82413588) {
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
	ctx.lr = 0x82413590;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// li r3,24064
	ctx.r3.s64 = 24064;
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// bl 0x82413538
	ctx.lr = 0x824135B8;
	sub_82413538(ctx, base);
	// mr. r31,r3
	r31.u64 = ctx.r3.u64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x824135cc
	if (!cr0.eq) goto loc_824135CC;
loc_824135C0:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x82413654
	goto loc_82413654;
loc_824135CC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824264f0
	ctx.lr = 0x824135D4;
	sub_824264F0(ctx, base);
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x824135ec
	if (!cr0.eq) goto loc_824135EC;
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// lwz r3,-4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// bl 0x821310f8
	ctx.lr = 0x824135E8;
	sub_821310F8(ctx, base);
	// b 0x824135c0
	goto loc_824135C0;
loc_824135EC:
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// bne cr6,0x82413624
	if (!cr6.eq) goto loc_82413624;
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r11,r11,128
	r11.u64 = r11.u64 | 128;
	// stb r11,10940(r31)
	PPC_STORE_U8(r31.u32 + 10940, r11.u8);
	// bl 0x82411618
	ctx.lr = 0x82413608;
	sub_82411618(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82426770
	ctx.lr = 0x82413610;
	sub_82426770(ctx, base);
loc_82413610:
	// cmpwi r3,0
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne 0x8241364c
	if (!cr0.eq) goto loc_8241364C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82413218
	ctx.lr = 0x82413620;
	sub_82413218(ctx, base);
	// b 0x824135c0
	goto loc_824135C0;
loc_82413624:
	// rlwinm. r11,r30,0,23,23
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x100;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82413638
	if (!cr0.eq) goto loc_82413638;
	// rlwinm. r11,r30,0,2,7
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x3F000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bne 0x82413638
	if (!cr0.eq) goto loc_82413638;
	// oris r30,r30,3072
	r30.u64 = r30.u64 | 201326592;
loc_82413638:
	// stw r30,23932(r31)
	PPC_STORE_U32(r31.u32 + 23932, r30.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82426558
	ctx.lr = 0x82413648;
	sub_82426558(ctx, base);
	// b 0x82413610
	goto loc_82413610;
loc_8241364C:
	// stw r31,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r31.u32);
	// li r3,0
	ctx.r3.s64 = 0;
loc_82413654:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8241365C"))) PPC_WEAK_FUNC(sub_8241365C);
PPC_FUNC_IMPL(__imp__sub_8241365C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413660"))) PPC_WEAK_FUNC(sub_82413660);
PPC_FUNC_IMPL(__imp__sub_82413660) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82413668;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r22,r7
	r22.u64 = ctx.r7.u64;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// ble cr6,0x82413698
	if (!cr6.gt) goto loc_82413698;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x82413698;
	sub_82412710(ctx, base);
loc_82413698:
	// lbz r11,10940(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rlwinm. r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x824136ac
	if (cr0.eq) goto loc_824136AC;
	// li r11,1
	r11.s64 = 1;
	// b 0x8241373c
	goto loc_8241373C;
loc_824136AC:
	// rlwinm. r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82413734
	if (cr0.eq) goto loc_82413734;
	// lwz r11,12440(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12440);
	// lwz r10,12728(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12728);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x824136cc
	if (cr6.eq) goto loc_824136CC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82413734
	if (!cr6.eq) goto loc_82413734;
loc_824136CC:
	// lwz r11,12444(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12444);
	// lwz r10,12732(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12732);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x824136e4
	if (cr6.eq) goto loc_824136E4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82413734
	if (!cr6.eq) goto loc_82413734;
loc_824136E4:
	// lwz r11,12448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12448);
	// lwz r10,12736(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12736);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x824136fc
	if (cr6.eq) goto loc_824136FC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82413734
	if (!cr6.eq) goto loc_82413734;
loc_824136FC:
	// lwz r11,12452(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12452);
	// lwz r10,12740(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12740);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82413714
	if (cr6.eq) goto loc_82413714;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82413734
	if (!cr6.eq) goto loc_82413734;
loc_82413714:
	// lwz r11,12456(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12456);
	// lwz r10,12744(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12744);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8241372c
	if (cr6.eq) goto loc_8241372C;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82413734
	if (!cr6.eq) goto loc_82413734;
loc_8241372C:
	// li r11,1
	r11.s64 = 1;
	// b 0x82413738
	goto loc_82413738;
loc_82413734:
	// li r11,0
	r11.s64 = 0;
loc_82413738:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
loc_8241373C:
	// clrlwi. r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r10,0
	ctx.r10.s64 = 0;
	// bne 0x82413780
	if (!cr0.eq) goto loc_82413780;
	// lis r11,2
	r11.s64 = 131072;
	// rlwinm r9,r24,16,2,15
	ctx.r9.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 16) & 0x3FFF0000;
	// ori r11,r11,8320
	r11.u64 = r11.u64 | 8320;
	// rlwinm r8,r22,16,2,15
	ctx.r8.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 16) & 0x3FFF0000;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// clrlwi r11,r25,18
	r11.u64 = r25.u32 & 0x3FFF;
	// or r11,r9,r11
	r11.u64 = ctx.r9.u64 | r11.u64;
	// clrlwi r9,r23,18
	ctx.r9.u64 = r23.u32 & 0x3FFF;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// b 0x82413944
	goto loc_82413944;
loc_82413780:
	// lis r11,-16384
	r11.s64 = -1073741824;
	// lis r9,-16384
	ctx.r9.s64 = -1073741824;
	// ori r11,r11,24832
	r11.u64 = r11.u64 | 24832;
	// li r27,0
	r27.s64 = 0;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, r11.u32);
	ctx.r3.u32 = ea;
	// ori r26,r9,24576
	r26.u64 = ctx.r9.u64 | 24576;
	// stwu r10,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	ctx.r3.u32 = ea;
	// lwz r10,12748(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12748);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// ble cr6,0x824138c4
	if (!cr6.gt) goto loc_824138C4;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r31,12756
	r30.s64 = r31.s64 + 12756;
	// addi r28,r31,12996
	r28.s64 = r31.s64 + 12996;
loc_824137B8:
	// lwz r10,-4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -4);
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// lwz r6,-4(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + -4);
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpw cr6,r25,r10
	cr6.compare<int32_t>(r25.s32, ctx.r10.s32, xer);
	// bgt cr6,0x824137d4
	if (cr6.gt) goto loc_824137D4;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
loc_824137D4:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// cmpw cr6,r24,r10
	cr6.compare<int32_t>(r24.s32, ctx.r10.s32, xer);
	// bgt cr6,0x824137e8
	if (cr6.gt) goto loc_824137E8;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
loc_824137E8:
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpw cr6,r23,r9
	cr6.compare<int32_t>(r23.s32, ctx.r9.s32, xer);
	// bge cr6,0x824137f8
	if (!cr6.lt) goto loc_824137F8;
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
loc_824137F8:
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpw cr6,r22,r10
	cr6.compare<int32_t>(r22.s32, ctx.r10.s32, xer);
	// bge cr6,0x82413808
	if (!cr6.lt) goto loc_82413808;
	// mr r10,r22
	ctx.r10.u64 = r22.u64;
loc_82413808:
	// cmpw cr6,r7,r9
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, xer);
	// bge cr6,0x82413818
	if (!cr6.lt) goto loc_82413818;
	// cmpw cr6,r8,r10
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r10.s32, xer);
	// blt cr6,0x82413828
	if (cr6.lt) goto loc_82413828;
loc_82413818:
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
loc_82413828:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r3,3
	ctx.r3.s64 = 3;
	// stwu r4,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	r11.u32 = ea;
	// lis r4,-16381
	ctx.r4.s64 = -1073545216;
	// slw r3,r3,r29
	ctx.r3.u64 = r29.u8 & 0x20 ? 0 : (ctx.r3.u32 << (r29.u8 & 0x3F));
	// stwu r3,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r3.u32);
	r11.u32 = ea;
	// ori r4,r4,11521
	ctx.r4.u64 = ctx.r4.u64 | 11521;
	// lis r21,4
	r21.s64 = 262144;
	// neg r6,r6
	ctx.r6.s64 = -ctx.r6.s64;
	// neg r5,r5
	ctx.r5.s64 = -ctx.r5.s64;
	// ori r21,r21,128
	r21.u64 = r21.u64 | 128;
	// stwu r4,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r4.u32);
	r11.u32 = ea;
	// rlwinm r5,r5,16,1,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0x7FFF0000;
	// clrlwi r6,r6,17
	ctx.r6.u64 = ctx.r6.u32 & 0x7FFF;
	// rlwinm r8,r8,16,2,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0x3FFF0000;
	// or r6,r5,r6
	ctx.r6.u64 = ctx.r5.u64 | ctx.r6.u64;
	// clrlwi r7,r7,18
	ctx.r7.u64 = ctx.r7.u32 & 0x3FFF;
	// stwu r21,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r21.u32);
	r11.u32 = ea;
	// rlwinm r10,r10,16,2,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0x3FFF0000;
	// or r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	// clrlwi r9,r9,18
	ctx.r9.u64 = ctx.r9.u32 & 0x3FFF;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// stwu r6,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r6.u32);
	r11.u32 = ea;
	// stwu r8,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r11.u32 = ea;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// ble cr6,0x824138a8
	if (!cr6.gt) goto loc_824138A8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82412710
	ctx.lr = 0x824138A4;
	sub_82412710(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_824138A8:
	// lwz r10,12748(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12748);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// addi r29,r29,2
	r29.s64 = r29.s64 + 2;
	// cmplw cr6,r27,r10
	cr6.compare<uint32_t>(r27.u32, ctx.r10.u32, xer);
	// blt cr6,0x824137b8
	if (cr6.lt) goto loc_824137B8;
loc_824138C4:
	// lbz r10,10943(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10943);
	// rlwinm. r10,r10,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82413924
	if (cr0.eq) goto loc_82413924;
	// lbz r10,10940(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 10940);
	// rlwinm. r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x82413924
	if (cr0.eq) goto loc_82413924;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// lis r8,-16382
	ctx.r8.s64 = -1073610752;
	// lis r7,4
	ctx.r7.s64 = 262144;
	// ori r10,r8,11521
	ctx.r10.u64 = ctx.r8.u64 | 11521;
	// ori r8,r7,129
	ctx.r8.u64 = ctx.r7.u64 | 129;
	// rlwinm r7,r24,16,2,15
	ctx.r7.u64 = __builtin_rotateleft64(r24.u32 | (r24.u64 << 32), 16) & 0x3FFF0000;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// clrlwi r6,r25,18
	ctx.r6.u64 = r25.u32 & 0x3FFF;
	// rlwinm r5,r22,16,2,15
	ctx.r5.u64 = __builtin_rotateleft64(r22.u32 | (r22.u64 << 32), 16) & 0x3FFF0000;
	// or r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 | ctx.r6.u64;
	// clrlwi r9,r23,18
	ctx.r9.u64 = r23.u32 & 0x3FFF;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// or r9,r5,r9
	ctx.r9.u64 = ctx.r5.u64 | ctx.r9.u64;
	// stwu r8,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	r11.u32 = ea;
	// stwu r7,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	r11.u32 = ea;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
loc_82413924:
	// stwu r26,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, r26.u32);
	r11.u32 = ea;
	// lis r10,-16384
	ctx.r10.s64 = -1073741824;
	// lwz r9,12708(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12708);
	// ori r10,r10,24832
	ctx.r10.u64 = ctx.r10.u64 | 24832;
	// stwu r9,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r9.u32);
	r11.u32 = ea;
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
	// lwz r10,12712(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12712);
	// stwu r10,4(r11)
	ea = 4 + r11.u32;
	PPC_STORE_U32(ea, ctx.r10.u32);
	r11.u32 = ea;
loc_82413944:
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82413950"))) PPC_WEAK_FUNC(sub_82413950);
PPC_FUNC_IMPL(__imp__sub_82413950) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10568(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10568);
	// rlwimi r4,r11,0,0,28
	ctx.r4.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0xFFFFFFF8) | (ctx.r4.u64 & 0xFFFFFFFF00000007);
	// stw r4,10568(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10568, ctx.r4.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,64
	r11.u64 = r11.u64 | 64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241396C"))) PPC_WEAK_FUNC(sub_8241396C);
PPC_FUNC_IMPL(__imp__sub_8241396C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413970"))) PPC_WEAK_FUNC(sub_82413970);
PPC_FUNC_IMPL(__imp__sub_82413970) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10568(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10568);
	// clrlwi r3,r11,29
	ctx.r3.u64 = r11.u32 & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241397C"))) PPC_WEAK_FUNC(sub_8241397C);
PPC_FUNC_IMPL(__imp__sub_8241397C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413980"))) PPC_WEAK_FUNC(sub_82413980);
PPC_FUNC_IMPL(__imp__sub_82413980) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10568(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10568);
	// rlwimi r11,r4,3,21,28
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 3) & 0x7F8) | (r11.u64 & 0xFFFFFFFFFFFFF807);
	// stw r11,10568(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10568, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,64
	r11.u64 = r11.u64 | 64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241399C"))) PPC_WEAK_FUNC(sub_8241399C);
PPC_FUNC_IMPL(__imp__sub_8241399C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824139A0"))) PPC_WEAK_FUNC(sub_824139A0);
PPC_FUNC_IMPL(__imp__sub_824139A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10568(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10568);
	// rlwinm r3,r11,29,24,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824139AC"))) PPC_WEAK_FUNC(sub_824139AC);
PPC_FUNC_IMPL(__imp__sub_824139AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824139B0"))) PPC_WEAK_FUNC(sub_824139B0);
PPC_FUNC_IMPL(__imp__sub_824139B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10556(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10556);
	// rlwimi r11,r4,3,28,28
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 3) & 0x8) | (r11.u64 & 0xFFFFFFFFFFFFFFF7);
	// stw r11,10556(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10556, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,512
	r11.u64 = r11.u64 | 512;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// oris r11,r11,4
	r11.u64 = r11.u64 | 262144;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824139D4"))) PPC_WEAK_FUNC(sub_824139D4);
PPC_FUNC_IMPL(__imp__sub_824139D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824139D8"))) PPC_WEAK_FUNC(sub_824139D8);
PPC_FUNC_IMPL(__imp__sub_824139D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10556(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10556);
	// rlwinm r3,r11,29,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824139E4"))) PPC_WEAK_FUNC(sub_824139E4);
PPC_FUNC_IMPL(__imp__sub_824139E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824139E8"))) PPC_WEAK_FUNC(sub_824139E8);
PPC_FUNC_IMPL(__imp__sub_824139E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,11852(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11852);
	// rlwimi r11,r4,31,0,0
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 31) & 0x80000000) | (r11.u64 & 0xFFFFFFFF7FFFFFFF);
	// stw r11,11852(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11852, r11.u32);
	// rlwinm. r10,r11,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r11,11848(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11848);
	// bne 0x82413a20
	if (!cr0.eq) goto loc_82413A20;
	// andi. r10,r11,4112
	ctx.r10.u64 = r11.u64 & 4112;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFF0;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwinm r10,r10,12,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFF0000;
	// rlwinm r10,r10,0,12,10
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFEFFFFF;
	// rlwinm r10,r10,0,4,2
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
loc_82413A20:
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne cr6,0x82413a30
	if (!cr6.eq) goto loc_82413A30;
	// lis r11,1
	r11.s64 = 65536;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
loc_82413A30:
	// stw r11,10588(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10588, r11.u32);
	// stw r11,10552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10552, r11.u32);
	// stw r11,10584(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10584, r11.u32);
	// stw r11,10592(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10592, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,1024
	r11.u64 = r11.u64 | 1024;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,4
	r11.u64 = r11.u64 | 4;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413A68"))) PPC_WEAK_FUNC(sub_82413A68);
PPC_FUNC_IMPL(__imp__sub_82413A68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,11852(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11852);
	// rlwinm r3,r11,1,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413A74"))) PPC_WEAK_FUNC(sub_82413A74);
PPC_FUNC_IMPL(__imp__sub_82413A74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413A78"))) PPC_WEAK_FUNC(sub_82413A78);
PPC_FUNC_IMPL(__imp__sub_82413A78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lwz r10,11848(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11848);
	// lwz r11,11852(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11852);
	// rlwimi r10,r4,5,24,26
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r4.u32, 5) & 0xE0) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFF1F);
	// rlwinm. r9,r11,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r10,11848(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11848, ctx.r10.u32);
	// beqlr 
	if (cr0.eq) return;
	// rlwinm. r10,r11,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r11,11848(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11848);
	// bne 0x82413abc
	if (!cr0.eq) goto loc_82413ABC;
	// andi. r10,r11,4112
	ctx.r10.u64 = r11.u64 & 4112;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFF0;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwinm r10,r10,12,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFF0000;
	// rlwinm r10,r10,0,12,10
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFEFFFFF;
	// rlwinm r10,r10,0,4,2
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
loc_82413ABC:
	// stw r11,10552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10552, r11.u32);
	// stw r11,10584(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10584, r11.u32);
	// stw r11,10588(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10588, r11.u32);
	// stw r11,10592(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10592, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,1024
	r11.u64 = r11.u64 | 1024;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,4
	r11.u64 = r11.u64 | 4;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413AF4"))) PPC_WEAK_FUNC(sub_82413AF4);
PPC_FUNC_IMPL(__imp__sub_82413AF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413AF8"))) PPC_WEAK_FUNC(sub_82413AF8);
PPC_FUNC_IMPL(__imp__sub_82413AF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,11848(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11848);
	// rlwinm r3,r11,27,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413B04"))) PPC_WEAK_FUNC(sub_82413B04);
PPC_FUNC_IMPL(__imp__sub_82413B04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413B08"))) PPC_WEAK_FUNC(sub_82413B08);
PPC_FUNC_IMPL(__imp__sub_82413B08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lwz r10,11848(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11848);
	// lwz r11,11852(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11852);
	// rlwimi r10,r4,0,27,31
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r4.u32, 0) & 0x1F) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFE0);
	// rlwinm. r9,r11,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r10,11848(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11848, ctx.r10.u32);
	// beqlr 
	if (cr0.eq) return;
	// rlwinm. r10,r11,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r11,11848(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11848);
	// bne 0x82413b4c
	if (!cr0.eq) goto loc_82413B4C;
	// andi. r10,r11,4112
	ctx.r10.u64 = r11.u64 & 4112;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFF0;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwinm r10,r10,12,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFF0000;
	// rlwinm r10,r10,0,12,10
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFEFFFFF;
	// rlwinm r10,r10,0,4,2
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
loc_82413B4C:
	// stw r11,10552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10552, r11.u32);
	// stw r11,10584(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10584, r11.u32);
	// stw r11,10588(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10588, r11.u32);
	// stw r11,10592(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10592, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,1024
	r11.u64 = r11.u64 | 1024;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,4
	r11.u64 = r11.u64 | 4;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413B84"))) PPC_WEAK_FUNC(sub_82413B84);
PPC_FUNC_IMPL(__imp__sub_82413B84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413B88"))) PPC_WEAK_FUNC(sub_82413B88);
PPC_FUNC_IMPL(__imp__sub_82413B88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,11848(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11848);
	// clrlwi r3,r11,27
	ctx.r3.u64 = r11.u32 & 0x1F;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413B94"))) PPC_WEAK_FUNC(sub_82413B94);
PPC_FUNC_IMPL(__imp__sub_82413B94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413B98"))) PPC_WEAK_FUNC(sub_82413B98);
PPC_FUNC_IMPL(__imp__sub_82413B98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lwz r10,11848(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11848);
	// lwz r11,11852(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11852);
	// rlwimi r10,r4,8,19,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0x1F00) | (ctx.r10.u64 & 0xFFFFFFFFFFFFE0FF);
	// rlwinm. r9,r11,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r10,11848(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11848, ctx.r10.u32);
	// beqlr 
	if (cr0.eq) return;
	// rlwinm. r10,r11,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r11,11848(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11848);
	// bne 0x82413bdc
	if (!cr0.eq) goto loc_82413BDC;
	// andi. r10,r11,4112
	ctx.r10.u64 = r11.u64 & 4112;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFF0;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// rlwinm r10,r10,12,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0xFFFF0000;
	// rlwinm r10,r10,0,12,10
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFEFFFFF;
	// rlwinm r10,r10,0,4,2
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// or r11,r10,r11
	r11.u64 = ctx.r10.u64 | r11.u64;
loc_82413BDC:
	// stw r11,10552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10552, r11.u32);
	// stw r11,10584(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10584, r11.u32);
	// stw r11,10588(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10588, r11.u32);
	// stw r11,10592(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10592, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,1024
	r11.u64 = r11.u64 | 1024;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,4
	r11.u64 = r11.u64 | 4;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413C14"))) PPC_WEAK_FUNC(sub_82413C14);
PPC_FUNC_IMPL(__imp__sub_82413C14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413C18"))) PPC_WEAK_FUNC(sub_82413C18);
PPC_FUNC_IMPL(__imp__sub_82413C18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,11848(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11848);
	// rlwinm r3,r11,24,27,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0x1F;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413C24"))) PPC_WEAK_FUNC(sub_82413C24);
PPC_FUNC_IMPL(__imp__sub_82413C24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413C28"))) PPC_WEAK_FUNC(sub_82413C28);
PPC_FUNC_IMPL(__imp__sub_82413C28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lwz r10,11848(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11848);
	// lwz r11,11852(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11852);
	// rlwimi r10,r4,21,8,10
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r4.u32, 21) & 0xE00000) | (ctx.r10.u64 & 0xFFFFFFFFFF1FFFFF);
	// rlwinm. r9,r11,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r10,11848(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11848, ctx.r10.u32);
	// beqlr 
	if (cr0.eq) return;
	// rlwinm. r11,r11,0,1,1
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beqlr 
	if (cr0.eq) return;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r11,10552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10552, r11.u32);
	// stw r11,10584(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10584, r11.u32);
	// stw r11,10588(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10588, r11.u32);
	// stw r11,10592(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10592, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,1024
	r11.u64 = r11.u64 | 1024;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,4
	r11.u64 = r11.u64 | 4;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413C84"))) PPC_WEAK_FUNC(sub_82413C84);
PPC_FUNC_IMPL(__imp__sub_82413C84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413C88"))) PPC_WEAK_FUNC(sub_82413C88);
PPC_FUNC_IMPL(__imp__sub_82413C88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,11848(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11848);
	// rlwinm r3,r11,11,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 11) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413C94"))) PPC_WEAK_FUNC(sub_82413C94);
PPC_FUNC_IMPL(__imp__sub_82413C94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413C98"))) PPC_WEAK_FUNC(sub_82413C98);
PPC_FUNC_IMPL(__imp__sub_82413C98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lwz r10,11848(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11848);
	// lwz r11,11852(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11852);
	// rlwimi r10,r4,16,11,15
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r4.u32, 16) & 0x1F0000) | (ctx.r10.u64 & 0xFFFFFFFFFFE0FFFF);
	// rlwinm. r9,r11,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r10,11848(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11848, ctx.r10.u32);
	// beqlr 
	if (cr0.eq) return;
	// rlwinm. r11,r11,0,1,1
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beqlr 
	if (cr0.eq) return;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r11,10552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10552, r11.u32);
	// stw r11,10584(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10584, r11.u32);
	// stw r11,10588(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10588, r11.u32);
	// stw r11,10592(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10592, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,1024
	r11.u64 = r11.u64 | 1024;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,4
	r11.u64 = r11.u64 | 4;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413CF4"))) PPC_WEAK_FUNC(sub_82413CF4);
PPC_FUNC_IMPL(__imp__sub_82413CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413CF8"))) PPC_WEAK_FUNC(sub_82413CF8);
PPC_FUNC_IMPL(__imp__sub_82413CF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lhz r11,11848(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 11848);
	// clrlwi r3,r11,27
	ctx.r3.u64 = r11.u32 & 0x1F;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413D04"))) PPC_WEAK_FUNC(sub_82413D04);
PPC_FUNC_IMPL(__imp__sub_82413D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413D08"))) PPC_WEAK_FUNC(sub_82413D08);
PPC_FUNC_IMPL(__imp__sub_82413D08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lwz r10,11848(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11848);
	// lwz r11,11852(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11852);
	// rlwimi r10,r4,24,3,7
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r4.u32, 24) & 0x1F000000) | (ctx.r10.u64 & 0xFFFFFFFFE0FFFFFF);
	// rlwinm. r9,r11,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80000000;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stw r10,11848(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11848, ctx.r10.u32);
	// beqlr 
	if (cr0.eq) return;
	// rlwinm. r11,r11,0,1,1
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40000000;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beqlr 
	if (cr0.eq) return;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// stw r11,10552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10552, r11.u32);
	// stw r11,10584(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10584, r11.u32);
	// stw r11,10588(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10588, r11.u32);
	// stw r11,10592(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10592, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,1024
	r11.u64 = r11.u64 | 1024;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,4
	r11.u64 = r11.u64 | 4;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413D64"))) PPC_WEAK_FUNC(sub_82413D64);
PPC_FUNC_IMPL(__imp__sub_82413D64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413D68"))) PPC_WEAK_FUNC(sub_82413D68);
PPC_FUNC_IMPL(__imp__sub_82413D68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,11848(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 11848);
	// clrlwi r3,r11,27
	ctx.r3.u64 = r11.u32 & 0x1F;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413D74"))) PPC_WEAK_FUNC(sub_82413D74);
PPC_FUNC_IMPL(__imp__sub_82413D74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413D78"))) PPC_WEAK_FUNC(sub_82413D78);
PPC_FUNC_IMPL(__imp__sub_82413D78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,11852(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11852);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// rlwimi r11,r4,30,1,1
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 30) & 0x40000000) | (r11.u64 & 0xFFFFFFFFBFFFFFFF);
	// stw r11,11852(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11852, r11.u32);
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// lwz r11,11848(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11848);
	// bne cr6,0x82413db4
	if (!cr6.eq) goto loc_82413DB4;
	// andi. r9,r11,4112
	ctx.r9.u64 = r11.u64 & 4112;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// rlwinm r8,r11,4,12,27
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFF0;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// or r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 | ctx.r8.u64;
	// rlwinm r9,r9,12,0,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 12) & 0xFFFF0000;
	// rlwinm r9,r9,0,12,10
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFEFFFFF;
	// rlwinm r9,r9,0,4,2
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// or r11,r9,r11
	r11.u64 = ctx.r9.u64 | r11.u64;
loc_82413DB4:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82413dc4
	if (!cr6.eq) goto loc_82413DC4;
	// lis r11,1
	r11.s64 = 65536;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
loc_82413DC4:
	// stw r11,10552(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10552, r11.u32);
	// stw r11,10584(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10584, r11.u32);
	// stw r11,10588(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10588, r11.u32);
	// stw r11,10592(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10592, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,1024
	r11.u64 = r11.u64 | 1024;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,4
	r11.u64 = r11.u64 | 4;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413DFC"))) PPC_WEAK_FUNC(sub_82413DFC);
PPC_FUNC_IMPL(__imp__sub_82413DFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413E00"))) PPC_WEAK_FUNC(sub_82413E00);
PPC_FUNC_IMPL(__imp__sub_82413E00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,11852(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11852);
	// rlwinm r3,r11,2,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413E0C"))) PPC_WEAK_FUNC(sub_82413E0C);
PPC_FUNC_IMPL(__imp__sub_82413E0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413E10"))) PPC_WEAK_FUNC(sub_82413E10);
PPC_FUNC_IMPL(__imp__sub_82413E10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// clrldi r11,r4,32
	r11.u64 = ctx.r4.u64 & 0xFFFFFFFF;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f0,f0
	f0.f64 = double(f0.s64);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// frsp f13,f0
	ctx.f13.f64 = double(float(f0.f64));
	// lfs f0,15364(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15364);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f0,10500(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10500, temp.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// oris r11,r11,2048
	r11.u64 = r11.u64 | 134217728;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413E44"))) PPC_WEAK_FUNC(sub_82413E44);
PPC_FUNC_IMPL(__imp__sub_82413E44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413E48"))) PPC_WEAK_FUNC(sub_82413E48);
PPC_FUNC_IMPL(__imp__sub_82413E48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,10500(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10500);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,15360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15360);
	f0.f64 = double(temp.f32);
	// lfs f13,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f12,f0,f13
	f0.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f13.f64));
	// fctidz f0,f0
	f0.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f0.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413E70"))) PPC_WEAK_FUNC(sub_82413E70);
PPC_FUNC_IMPL(__imp__sub_82413E70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10556(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10556);
	// rlwimi r4,r11,0,0,28
	ctx.r4.u64 = (__builtin_rotateleft32(r11.u32, 0) & 0xFFFFFFF8) | (ctx.r4.u64 & 0xFFFFFFFF00000007);
	// stw r4,10556(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10556, ctx.r4.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,512
	r11.u64 = r11.u64 | 512;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413E8C"))) PPC_WEAK_FUNC(sub_82413E8C);
PPC_FUNC_IMPL(__imp__sub_82413E8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413E90"))) PPC_WEAK_FUNC(sub_82413E90);
PPC_FUNC_IMPL(__imp__sub_82413E90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10556(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10556);
	// clrlwi r3,r11,29
	ctx.r3.u64 = r11.u32 & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413E9C"))) PPC_WEAK_FUNC(sub_82413E9C);
PPC_FUNC_IMPL(__imp__sub_82413E9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413EA0"))) PPC_WEAK_FUNC(sub_82413EA0);
PPC_FUNC_IMPL(__imp__sub_82413EA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister temp{};
	// rlwinm r11,r4,8,24,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFF;
	// rlwinm r9,r4,24,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 24) & 0xFF;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f13,-16(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f0,-16(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// rlwinm r10,r4,16,24,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 16) & 0xFF;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// std r10,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r10.u64);
	// lfd f12,-8(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// std r11,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r11.u64);
	// lfd f11,-8(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fcfid f10,f0
	ctx.f10.f64 = double(f0.s64);
	// lfs f0,15364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15364);
	f0.f64 = double(temp.f32);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// li r12,15
	r12.s64 = 15;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// rldicr r12,r12,33,30
	r12.u64 = __builtin_rotateleft64(r12.u64, 33) & 0xFFFFFFFE00000000;
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f11,10472(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10472, temp.u32);
	// fmuls f11,f10,f0
	ctx.f11.f64 = double(float(ctx.f10.f64 * f0.f64));
	// stfs f11,10468(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10468, temp.u32);
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f12,10464(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10464, temp.u32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f0,10476(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 10476, temp.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413F30"))) PPC_WEAK_FUNC(sub_82413F30);
PPC_FUNC_IMPL(__imp__sub_82413F30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,10468(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10468);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f11,10472(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10472);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,10464(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10464);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,10476(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 10476);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,15360(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15360);
	f0.f64 = double(temp.f32);
	// lfs f13,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f13.f64));
	// fmadds f11,f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f13.f64));
	// fmadds f10,f10,f0,f13
	ctx.f10.f64 = double(float(ctx.f10.f64 * f0.f64 + ctx.f13.f64));
	// fmadds f0,f9,f0,f13
	f0.f64 = double(float(ctx.f9.f64 * f0.f64 + ctx.f13.f64));
	// fctidz f13,f12
	ctx.f13.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f13,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// lwz r11,-12(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// fctidz f13,f11
	ctx.f13.s64 = (ctx.f11.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f13,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// lwz r3,-12(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// fctidz f13,f10
	ctx.f13.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f13,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// fctidz f0,f0
	f0.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f0,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, f0.u64);
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// lwz r9,-4(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	// rlwimi r10,r9,8,0,23
	ctx.r10.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFFFFFF00) | (ctx.r10.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r11,r10,8,0,23
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFFFFFF00) | (r11.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r3,r11,8,0,23
	ctx.r3.u64 = (__builtin_rotateleft32(r11.u32, 8) & 0xFFFFFF00) | (ctx.r3.u64 & 0xFFFFFFFF000000FF);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413FA0"))) PPC_WEAK_FUNC(sub_82413FA0);
PPC_FUNC_IMPL(__imp__sub_82413FA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r11,10680(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10680);
	// li r12,1
	r12.s64 = 1;
	// rlwimi r11,r4,10,21,21
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 10) & 0x400) | (r11.u64 & 0xFFFFFFFFFFFFFBFF);
	// rldicr r12,r12,37,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 37) & 0xFFFFFFFFFFFFFFFF;
	// stw r11,10680(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10680, r11.u32);
	// ld r11,32(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 32);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413FC4"))) PPC_WEAK_FUNC(sub_82413FC4);
PPC_FUNC_IMPL(__imp__sub_82413FC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413FC8"))) PPC_WEAK_FUNC(sub_82413FC8);
PPC_FUNC_IMPL(__imp__sub_82413FC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10680(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10680);
	// rlwinm r3,r11,22,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82413FD4"))) PPC_WEAK_FUNC(sub_82413FD4);
PPC_FUNC_IMPL(__imp__sub_82413FD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82413FD8"))) PPC_WEAK_FUNC(sub_82413FD8);
PPC_FUNC_IMPL(__imp__sub_82413FD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r4,28(r1)
	PPC_STORE_U32(ctx.r1.u32 + 28, ctx.r4.u32);
	// lfs f13,28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// li r12,1
	r12.s64 = 1;
	// rldicr r12,r12,52,63
	r12.u64 = __builtin_rotateleft64(r12.u64, 52) & 0xFFFFFFFFFFFFFFFF;
	// lfs f0,-17876(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17876);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctidz f0,f0
	f0.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, f0.u64);
	// lwz r11,-12(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// sth r11,10606(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10606, r11.u16);
	// ld r11,24(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r12
	r11.u64 = r11.u64 | r12.u64;
	// std r11,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414014"))) PPC_WEAK_FUNC(sub_82414014);
PPC_FUNC_IMPL(__imp__sub_82414014) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414018"))) PPC_WEAK_FUNC(sub_82414018);
PPC_FUNC_IMPL(__imp__sub_82414018) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lhz r11,10606(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 10606);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,12424(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12424);
	f0.f64 = double(temp.f32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lwz r3,-16(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414048"))) PPC_WEAK_FUNC(sub_82414048);
PPC_FUNC_IMPL(__imp__sub_82414048) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,23932(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23932);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8241405c
	if (cr6.eq) goto loc_8241405C;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// b 0x82414060
	goto loc_82414060;
loc_8241405C:
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
loc_82414060:
	// stw r11,23932(r3)
	PPC_STORE_U32(ctx.r3.u32 + 23932, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414068"))) PPC_WEAK_FUNC(sub_82414068);
PPC_FUNC_IMPL(__imp__sub_82414068) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,23932(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 23932);
	// clrlwi r3,r11,31
	ctx.r3.u64 = r11.u32 & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414074"))) PPC_WEAK_FUNC(sub_82414074);
PPC_FUNC_IMPL(__imp__sub_82414074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414078"))) PPC_WEAK_FUNC(sub_82414078);
PPC_FUNC_IMPL(__imp__sub_82414078) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,12456(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12456);
	// stw r4,11876(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11876, ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8241408c
	if (!cr6.eq) goto loc_8241408C;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8241408C:
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,1,30,30
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 1) & 0x2) | (r11.u64 & 0xFFFFFFFFFFFFFFFD);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// oris r11,r11,2
	r11.u64 = r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824140B0"))) PPC_WEAK_FUNC(sub_824140B0);
PPC_FUNC_IMPL(__imp__sub_824140B0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,11876(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11876);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824140B8"))) PPC_WEAK_FUNC(sub_824140B8);
PPC_FUNC_IMPL(__imp__sub_824140B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,2,29,29
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 2) & 0x4) | (r11.u64 & 0xFFFFFFFFFFFFFFFB);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824140D4"))) PPC_WEAK_FUNC(sub_824140D4);
PPC_FUNC_IMPL(__imp__sub_824140D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824140D8"))) PPC_WEAK_FUNC(sub_824140D8);
PPC_FUNC_IMPL(__imp__sub_824140D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,30,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824140E4"))) PPC_WEAK_FUNC(sub_824140E4);
PPC_FUNC_IMPL(__imp__sub_824140E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824140E8"))) PPC_WEAK_FUNC(sub_824140E8);
PPC_FUNC_IMPL(__imp__sub_824140E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,4,25,27
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 4) & 0x70) | (r11.u64 & 0xFFFFFFFFFFFFFF8F);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// oris r11,r11,2
	r11.u64 = r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241410C"))) PPC_WEAK_FUNC(sub_8241410C);
PPC_FUNC_IMPL(__imp__sub_8241410C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414110"))) PPC_WEAK_FUNC(sub_82414110);
PPC_FUNC_IMPL(__imp__sub_82414110) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,28,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 28) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8241411C"))) PPC_WEAK_FUNC(sub_8241411C);
PPC_FUNC_IMPL(__imp__sub_8241411C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414120"))) PPC_WEAK_FUNC(sub_82414120);
PPC_FUNC_IMPL(__imp__sub_82414120) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,12456(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12456);
	// stw r4,11880(r3)
	PPC_STORE_U32(ctx.r3.u32 + 11880, ctx.r4.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82414134
	if (!cr6.eq) goto loc_82414134;
	// li r4,0
	ctx.r4.s64 = 0;
loc_82414134:
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,0,31,31
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 0) & 0x1) | (r11.u64 & 0xFFFFFFFFFFFFFFFE);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// oris r11,r11,2
	r11.u64 = r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414158"))) PPC_WEAK_FUNC(sub_82414158);
PPC_FUNC_IMPL(__imp__sub_82414158) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,11880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 11880);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414160"))) PPC_WEAK_FUNC(sub_82414160);
PPC_FUNC_IMPL(__imp__sub_82414160) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,7,24,24
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 7) & 0x80) | (r11.u64 & 0xFFFFFFFFFFFFFF7F);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// oris r11,r11,2
	r11.u64 = r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414184"))) PPC_WEAK_FUNC(sub_82414184);
PPC_FUNC_IMPL(__imp__sub_82414184) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414188"))) PPC_WEAK_FUNC(sub_82414188);
PPC_FUNC_IMPL(__imp__sub_82414188) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414194"))) PPC_WEAK_FUNC(sub_82414194);
PPC_FUNC_IMPL(__imp__sub_82414194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414198"))) PPC_WEAK_FUNC(sub_82414198);
PPC_FUNC_IMPL(__imp__sub_82414198) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,8,21,23
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 8) & 0x700) | (r11.u64 & 0xFFFFFFFFFFFFF8FF);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824141B4"))) PPC_WEAK_FUNC(sub_824141B4);
PPC_FUNC_IMPL(__imp__sub_824141B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824141B8"))) PPC_WEAK_FUNC(sub_824141B8);
PPC_FUNC_IMPL(__imp__sub_824141B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,24,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824141C4"))) PPC_WEAK_FUNC(sub_824141C4);
PPC_FUNC_IMPL(__imp__sub_824141C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824141C8"))) PPC_WEAK_FUNC(sub_824141C8);
PPC_FUNC_IMPL(__imp__sub_824141C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,11,18,20
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 11) & 0x3800) | (r11.u64 & 0xFFFFFFFFFFFFC7FF);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// oris r11,r11,2
	r11.u64 = r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824141EC"))) PPC_WEAK_FUNC(sub_824141EC);
PPC_FUNC_IMPL(__imp__sub_824141EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_824141F0"))) PPC_WEAK_FUNC(sub_824141F0);
PPC_FUNC_IMPL(__imp__sub_824141F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,21,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 21) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_824141FC"))) PPC_WEAK_FUNC(sub_824141FC);
PPC_FUNC_IMPL(__imp__sub_824141FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414200"))) PPC_WEAK_FUNC(sub_82414200);
PPC_FUNC_IMPL(__imp__sub_82414200) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,17,12,14
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 17) & 0xE0000) | (r11.u64 & 0xFFFFFFFFFFF1FFFF);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// oris r11,r11,2
	r11.u64 = r11.u64 | 131072;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414224"))) PPC_WEAK_FUNC(sub_82414224);
PPC_FUNC_IMPL(__imp__sub_82414224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414228"))) PPC_WEAK_FUNC(sub_82414228);
PPC_FUNC_IMPL(__imp__sub_82414228) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,15,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414234"))) PPC_WEAK_FUNC(sub_82414234);
PPC_FUNC_IMPL(__imp__sub_82414234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414238"))) PPC_WEAK_FUNC(sub_82414238);
PPC_FUNC_IMPL(__imp__sub_82414238) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwimi r11,r4,14,15,17
	r11.u64 = (__builtin_rotateleft32(ctx.r4.u32, 14) & 0x1C000) | (r11.u64 & 0xFFFFFFFFFFFE3FFF);
	// stw r11,10548(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10548, r11.u32);
	// ld r11,16(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,2048
	r11.u64 = r11.u64 | 2048;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414254"))) PPC_WEAK_FUNC(sub_82414254);
PPC_FUNC_IMPL(__imp__sub_82414254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82414258"))) PPC_WEAK_FUNC(sub_82414258);
PPC_FUNC_IMPL(__imp__sub_82414258) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,10548(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 10548);
	// rlwinm r3,r11,18,29,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 18) & 0x7;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82414264"))) PPC_WEAK_FUNC(sub_82414264);
PPC_FUNC_IMPL(__imp__sub_82414264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

